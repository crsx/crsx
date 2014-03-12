/* Copyright © 2008, 2013 IBM Corporation. */

package net.sf.crsx.generic;

import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StringReader;
import java.lang.reflect.Method;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.TreeSet;

import net.sf.crsx.Builder;
import net.sf.crsx.CRS;
import net.sf.crsx.CRSException;
import net.sf.crsx.Constructor;
import net.sf.crsx.Contractum;
import net.sf.crsx.Copyable;
import net.sf.crsx.Factory;
import net.sf.crsx.Kind;
import net.sf.crsx.Match;
import net.sf.crsx.MetaAnalyzer;
import net.sf.crsx.Pattern;
import net.sf.crsx.Primitive;
import net.sf.crsx.PropertiesHolder;
import net.sf.crsx.Reifier;
import net.sf.crsx.Sink;
import net.sf.crsx.Stub;
import net.sf.crsx.Substitute;
import net.sf.crsx.Term;
import net.sf.crsx.Unification;
import net.sf.crsx.Valuation;
import net.sf.crsx.Variable;
import net.sf.crsx.Visitor;
import net.sf.crsx.analysis.Unifier;
import net.sf.crsx.util.Buffer;
import net.sf.crsx.util.ExtensibleMap;
import net.sf.crsx.util.ExtensibleSet;
import net.sf.crsx.util.LinkedExtensibleMap;
import net.sf.crsx.util.LinkedExtensibleSet;
import net.sf.crsx.util.SequenceIterator;
import net.sf.crsx.util.StackedMap;
import net.sf.crsx.util.Util;
import net.sf.crsx.util.WriterAppender;

/**
 * Special construction with custom rules for matching and copying/contraction.
 * 
 * This evaluator uses the string representation of nullary constructors as arguments and returns
 * a nullary constructor with a string representation of the result.
 * <p>
 * Supported forms (a "constant" is a nullary constructor with the right representation) are listed in the
 * {@link Primitive} helper class.
 * <p>
 * Each form is active in three situations:
 * <ol>
 * <li>When <em>copying</em>, special forms are quietly replaced with their result when possible.
 * <li>When <em>matching</em>, special forms in patterns generally should match the same as their result 
 * 		(<b>note:</b> not fully implemented and not even fully possible...).
 *		Special forms in the matched term never match.
 * <li>When <em>contracting</em>, special forms <em>must</em> be replaceable by their result or it is an error!
 * </ol>
 * These rules ensure that evaluators used in rules do not accidentally creep into the rewritten term.
 * <p>
 * 
 * @author <a href="http://www.research.ibm.com/people/k/krisrose">Kristoffer Rose</a>.
 * @version $Id: GenericEvaluator.java,v 3.46 2014/02/05 22:28:34 krisrose Exp $
 */
class GenericEvaluator extends FixedGenericConstruction
{
	// Constants.
	
	/** Regular expression for integers. */
	final static java.util.regex.Pattern INTEGER_REGEX = java.util.regex.Pattern.compile("[-+]*[0-9]+");

    /** The string without outermost quotes. */
	public static String unquote(String s)
	{
		if (s.length() > 0)
		{
			switch (s.charAt(0))
			{
				case '"' : s = s.substring(1, s.length()-1).replace("\\\"", "\""); break;
				case '\'' : s = s.substring(1, s.length()-1).replace("''", "'"); break;
			}
			// TODO: escape sequences?
		}
		return s;
	}

    /**
     * The string with quotes.
     * @param s string to quote
     * @param quote 
     */
	public static String quoteWith(String s, String quote)
	{
		StringBuilder b = new StringBuilder();
		Util.quotedJavaChars(quote, b);
		return quote + s.replace(quote, b.toString()) + quote;
	}
	
	/**
	 * Return the computed version of the term.
     * @see Contractum
	 * @param term to evaluate (must be a GeneroicEvaluator)
	 * @param globals variables free in context
	 * @return computed result or null if it cannot be computed
	 */
	static GenericTerm compute(GenericTerm term, Set<Variable> globals)
	{
		GenericTerm next = (term instanceof GenericEvaluator ? ((GenericEvaluator) term).compute(globals) : null);
		return next != null ? next : term;
	}
	
	// Fields.
	
	/** Valuation for not yet contraction.. */
	final GenericValuation valuation;

	/** Valuation for contraction. */
	final ExtensibleMap<Variable,Variable> renamings;
	
///	/** Bitset indicating whether each parameter has been contracted. */
///	final boolean[] needsContraction;
	
	/** Options (used by reifier and computed by {@link #analyzeMetaUseContractum(Map, Map)} */
	List<Object>[] options;
	
	// Constructor.

	/**
	 * Create evaluator instance (no contraction needed).
	 * @param factory to use
	 * @param constructor to use (usually $).
	 * @param binds bindings for subterms
	 * @param sub subterms
	 */
	public GenericEvaluator(GenericFactory factory, Constructor constructor, Variable[][] binds, GenericTerm[] sub)
	{
		super(factory, constructor, binds, sub);
		valuation = null;
		renamings = LinkedExtensibleMap.EMPTY_RENAMING;
///		needsContraction = new boolean[sub.length];
///		for (int i = 0; i < needsContraction.length; ++i) needsContraction[i] = false;
	}

	/**
	 * Create evaluator instance with uncontracted subterms.
	 * @param factory to use
	 * @param constructor to use (usually $).
	 * @param binds bindings for subterms
	 * @param sub subterms
	 * @param valuation to use for un-contracted subterms.
	 * @param renamings to use for uncontracted subterms.
	 */
	public GenericEvaluator(GenericFactory factory, Constructor constructor, Variable[][] binds, GenericTerm[] sub, GenericValuation valuation, ExtensibleMap<Variable,Variable> renamings)
	{
		super(factory, constructor, binds, sub);
		this.valuation = valuation;
		this.renamings = renamings;
///		needsContraction = new boolean[sub.length];
///		for (int i = 0; i < needsContraction.length; ++i) needsContraction[i] = true;
	}
	
	// Methods.
	
	/** Evaluate all arguments. */
	void computeArguments()
	{
        for (int i = 0; i < arity(); ++i) computeArgument(i);
	}

	/** Evaluate one argument. */
	void computeArgument(int i)
	{
		if (0 <= i && i < arity())
		{
///			contractArgument(i);
			GenericTerm t = sub(i);
			GenericTerm t2 = compute(t, null);
			replaceSub(i, binders(i), t2 != null ? t2 : t);
		}
	}

///	/** Contract (but do not evaluate) one argument. */
///	void contractArgument(int i)
///	{
///		if (0 <= i && i < arity() && needsContraction[i])
///		{
///			needsContraction[i] = false;
///			replaceSub(i, binders(i), (GenericTerm) Buffer.contraction(sub(i), valuation, renamings));
///		}
///	}

	/** Evaluate all arguments. */
	void normalizeArguments()
	{
		if (valuation != null)
			for (int i = 0; i < arity(); ++i) normalizeArgument(i);
	}

	/** Evaluate one argument. */
	void normalizeArgument(int i)
	{
		computeArgument(i);
		if (0 <= i && i < arity() && valuation != null)
		{
	        try
	        {
	        	GenericTerm t = valuation.rule.crs.normalize(sub(i));
	        	if (t != null)
	        	{
	        		replaceSub(i, binders(i), t);
	        		computeArgument(i);
	        	}
	        }
	        catch (CRSException e)
	        {}
		}
	}

	/** Recalculate what evaluator with specific arguments. Only observes sub(0) and arity(). */
	public Primitive primitive()
	{
		if (arity() > 0 && sub(0).kind() == Kind.CONSTRUCTION)
		{
			computeArgument(0);
			String s = Util.symbol(sub(0)); s = new String(s.toCharArray());
			Primitive w = Primitive.which(s);
			if (w != null)
			{
				int arity = arity() - 1;
				if (arity < w.minArgCount || arity > w.maxArgCount)
					throw new UnsupportedOperationException("Illformed evaluator pattern $["+this+"]");
				return w;
			}
		}
		return Primitive.IGNORE;
	}
	
	/**
	 * Perform the computation implied by the term (internal version).
     * Used by implementations of {@link Contractum#Sink, Valuation, ExtensibleMap)}.
	 * @param globals variables free in context
	 * @return computed result or null if it cannot be computed
	 */
	private GenericTerm compute(Set<Variable> globals)
	{
		Primitive what = primitive();
		What: switch (what)
		{
			case PLUS :
				// $[Plus, n1, n2, ...]
				computeArguments();
				try
				{
					long longSum = 0l;
					double doubleSum = 0.0;
					for (int i = 1; i <arity(); ++i)
					{
						Term a = sub(i);
						if (!Util.isConstant(a)) return null; // "Sum requires constant arguments?"
						Object o = a.constructor().object();
						if (o instanceof Long)
							longSum += (Long) o;
						else if (o instanceof Double)
							doubleSum += (Double) o;
						else
							doubleSum += Double.parseDouble(Util.symbol(a));
					}
					if (doubleSum == 0.0)
						return rewrapWithProperties(factory.literal(longSum));
					else
						return rewrapWithProperties(factory.literal(doubleSum + (double) longSum));
				}
				catch (NumberFormatException e)
				{}
				break;

			case MINUS :
				// $[Minus, n1, n2]
				computeArguments();
				try
				{
					if (!Util.isConstant(sub(1)) || !Util.isConstant(sub(2))) return null; // "Can only subtract two constant values!"
					Object o1 = sub(1).constructor().object();
					Object o2 = sub(2).constructor().object();
					if (o1 instanceof Long && o2 instanceof Long)
						return rewrapWithProperties(factory.literal(((Long) o1) - ((Long) o2)));
					else if (o1 instanceof Double && o2 instanceof Double)
						return rewrapWithProperties(factory.literal(((Double) o1) - ((Double) o2)));
					else
					{
						double left = Double.parseDouble(Util.symbol(sub(1)));
						double right = Double.parseDouble(Util.symbol(sub(2)));
						return rewrapWithProperties(factory.literal(left - right));
					}
				}
				catch (NumberFormatException e)
				{}
				break;
			
			case TIMES :
				// $[Times, n1, n2, ...]
				computeArguments();
				try
				{
					double doubleProduct = 1;
					for (int i = 1; i <arity(); ++i)
					{
						Term a = sub(i);
						if (!Util.isConstant(a)) return null; // "Product requires constant arguments?"
						doubleProduct *= Double.parseDouble(a.toString());
					}
					return rewrapWithProperties(factory.literal(doubleProduct));
				}
				catch (NumberFormatException e)
				{}
				break;
			
			case DIVIDE :
				// $[Div, n1, n2]
				computeArguments();
				if (!Util.isConstant(sub(1)) || !Util.isConstant(sub(2))) break; // "Can only divide two constant values!"
				try
				{
					double left = Double.parseDouble(Util.symbol(sub(1)));
					double right = Double.parseDouble(Util.symbol(sub(2)));
					return rewrapWithProperties(factory.literal(left / right));
				}
				catch (NumberFormatException e)
				{}
				break;
			
			case MODULO :
				// $[Mod, n1, n2]
				computeArguments();
				if (!Util.isConstant(sub(1)) || !Util.isConstant(sub(2))) break; // "Can only modulo two constant values!"
				try
				{
					Object o1 = sub(1).constructor().object();
					Object o2 = sub(2).constructor().object();
					if (o1 instanceof Long && o2 instanceof Long)
						return rewrapWithProperties(factory.literal(((Long) o1) % ((Long) o2)));
					else if (o1 instanceof Double && o2 instanceof Double)
						return rewrapWithProperties(factory.literal(((Double) o1) % ((Double) o2)));
					else
					{
						double left = Double.parseDouble(Util.symbol(sub(1)));
						double right = Double.parseDouble(Util.symbol(sub(2)));
						return rewrapWithProperties(factory.literal(left % right));
					}
				}
				catch (NumberFormatException e)
				{}
				break;

			case ABSOLUTE:
				// $[Absolute, n]
				computeArguments();
				if (!Util.isConstant(sub(1))) break;
				try
				{
					long n = Long.parseLong(Util.symbol(sub(1)), 10);
					return rewrapWithProperties(factory.literal(n < 0l ? -n : n));
				}
				catch (NumberFormatException e)
				{}
				break;

			case DECIMAL:
				// $[Decimal, n]
				computeArguments();
				if (!Util.isConstant(sub(1))) break; // "Can only parse constant values!"
				try
				{
					return rewrapWithProperties(factory.literal(Long.parseLong(Util.symbol(sub(1)), 10)));
				}
				catch (NumberFormatException e)
				{}
				break;

			case HEX :
				// $[Hex, n1]
				computeArguments();
				if (!Util.isConstant(sub(1))) break; // "Can only hex constant values!"
				try
				{
					return rewrapWithProperties(factory.literal(Long.parseLong(Util.symbol(sub(1)), 16)));
				}
				catch (NumberFormatException e)
				{}
				break;

			case BIT_AND :
				// $[BitAnd, n1, n2]
				computeArguments();
				if (!Util.isConstant(sub(1)) || !Util.isConstant(sub(2))) break;
				try
				{
					long left = Long.decode(Util.symbol(sub(1)));
					long right = Long.decode(Util.symbol(sub(2)));
					return rewrapWithProperties(factory.literal(left & right));
				}
				catch (NumberFormatException e)
				{}
				break;

			case BIT_OR :
				// $[BitOr, n1, n2]
				computeArguments();
				if (!Util.isConstant(sub(1)) || !Util.isConstant(sub(2))) break;
				try
				{
					long left = Long.decode(Util.symbol(sub(1)));
					long right = Long.decode(Util.symbol(sub(2)));
					return rewrapWithProperties(factory.literal(left | right));
				}
				catch (NumberFormatException e)
				{}
				break;

			case BIT_XOR :
				// $[BitXor, n1, n2]
				computeArguments();
				if (!Util.isConstant(sub(1)) || !Util.isConstant(sub(2))) break;
				try
				{
					long left = Long.decode(Util.symbol(sub(1)));
					long right = Long.decode(Util.symbol(sub(2)));
					return rewrapWithProperties(factory.literal(left ^ right));
				}
				catch (NumberFormatException e)
				{}
				break;

			case BIT_NOT :
				// $[BitNot, n]
				computeArguments();
				if (!Util.isConstant(sub(1))) break;
				try
				{
					long bits = Long.decode(Util.symbol(sub(1)));
					return rewrapWithProperties(factory.literal(~ bits));
				}
				catch (NumberFormatException e)
				{}
				break;

			case BIT_MINUS :
				// $[BitMinus, n1, n2]
				computeArguments();
				if (!Util.isConstant(sub(1)) || !Util.isConstant(sub(2))) break;
				try
				{
					long left = Long.decode(Util.symbol(sub(1)));
					long right = Long.decode(Util.symbol(sub(2)));
					return rewrapWithProperties(factory.literal(left & ~right));
				}
				catch (NumberFormatException e)
				{}
				break;

			case BIT_SUB_SET_EQ : {
				// $[BitSubSetEq, small, large]
				computeArguments();
                if (!Util.isConstant(sub(1)) || !Util.isConstant(sub(2))) break;
				try
				{
					long left = Long.decode(Util.symbol(sub(1)));
					long right = Long.decode(Util.symbol(sub(2)));
	                return rewrapWithProperties(factory.literal((left & (~right)) == 0));
				}
				catch (NumberFormatException e)
				{}
                break;
			}
			
            case EQ : {
            	// $[Equal, t1, t2]
                computeArguments();
				if (Util.isMetaApplication(sub(1)) || Util.isMetaApplication(sub(2))) break;
                return rewrapWithProperties(factory.literal(sub(1).equals(sub(2))));
            }
            case NE : {
            	// $[NotEqual, t1, t2]
                computeArguments();
				if (Util.isMetaApplication(sub(1)) || Util.isMetaApplication(sub(2))) break;
                return rewrapWithProperties(factory.literal(!sub(1).equals(sub(2))));
            }
            case LE : {
            	// $[LessThanOrEqual, t1, t2]
                computeArguments();
                if (!Util.isConstant(sub(1)) || !Util.isConstant(sub(2))) break; // "Can only compare two constant values!"
                double left = Double.parseDouble(Util.symbol(sub(1)));
                double right = Double.parseDouble(Util.symbol(sub(2)));
                return rewrapWithProperties(factory.literal(left <= right));
            }
            case GE : {
            	// $[GreaterEqual, t1, t2]
                computeArguments();
                if (!Util.isConstant(sub(1)) || !Util.isConstant(sub(2))) break; // "Can only compare two constant values!"
                double left = Double.parseDouble(Util.symbol(sub(1)));
                double right = Double.parseDouble(Util.symbol(sub(2)));
                return rewrapWithProperties(factory.literal(left >= right));
            }
            case LT : {
            	// $[LessThan, t1, t2]
                computeArguments();
                if (!Util.isConstant(sub(1)) || !Util.isConstant(sub(2))) break; // "Can only compare two constant values!"
                double left = Double.parseDouble(Util.symbol(sub(1)));
                double right = Double.parseDouble(Util.symbol(sub(2)));
                return rewrapWithProperties(factory.literal(left < right));
            }
            case GT : {
            	// $[GreaterThan, t1, t2]
                computeArguments();
                if (!Util.isConstant(sub(1)) || !Util.isConstant(sub(2))) break; // "Can only compare two constant values!"
                double left = Double.parseDouble(Util.symbol(sub(1)));
                double right = Double.parseDouble(Util.symbol(sub(2)));
                return rewrapWithProperties(factory.literal(left > right));
            }
            
            case NUMEQ : {
            	// $[NumericEqual, t1, t2]
                computeArguments();
                if (!Util.isConstant(sub(1)) || !Util.isConstant(sub(2))) break; // "Can only compare two constant values!"
                double left = Double.parseDouble(Util.symbol(sub(1)));
                double right = Double.parseDouble(Util.symbol(sub(2)));
                return rewrapWithProperties(factory.literal(left == right));
            }
            case STRING_LT : {
            	// $[StringLessThan, t1, t2]
                computeArguments();
                if (!Util.isConstant(sub(1)) || !Util.isConstant(sub(2))) break; // "Can only compare two constant values!"
                return rewrapWithProperties(factory.literal(Util.symbol(sub(1)).compareTo(Util.symbol(sub(2))) < 0));
            }
            case DEEP_EQ : {
            	// $[DeepEqual, t1, t2[, bool]]
            	// TODO: bool
            	
            	return rewrapWithProperties(factory.literal(sub(1).equals(sub(2))));
            }
            
            case VARIABLE_NAME_IS : {
            	// $[VariableNameIs, v, #name, #result]
                computeArgument(1);
                computeArgument(2);
                if (sub(1).kind() != Kind.VARIABLE_USE || !Util.isConstant(sub(2))) break; // "Can only name variable with constant"
                Variable v = sub(1).variable();
                String n = Util.symbol(sub(2));
                v.setName(n.replaceFirst("[a-z][a-zA-Z0-9]*", n));
                return rewrapWithProperties(sub(3));
            }
            
            case SAME_VARIABLE : {
            	// $[SameVariable x y]
                computeArguments();
                if (sub(1).kind() != Kind.VARIABLE_USE || sub(2).kind() != Kind.VARIABLE_USE) break; // "Can only compare two variables!"
                Variable left = sub(1).variable();
                Variable right = sub(2).variable();
                return rewrapWithProperties(factory.literal(left == right));
            }
            case LESSER_VARIABLE : {
            	// $[LesserVariable x y]
            	normalizeArguments();
                if (sub(1).kind() != Kind.VARIABLE_USE || sub(2).kind() != Kind.VARIABLE_USE) break; // "Can only compare two variables!"
                Variable left = sub(1).variable();
                Variable right = sub(2).variable();
                return rewrapWithProperties(factory.literal(left != right && left.hashCode() <= right.hashCode()));
            }

            case AND : {
            	// $[And, b1, b2]
            	normalizeArguments();
                if (!Util.isConstant(sub(1)) || !Util.isConstant(sub(2))) break; // "Can only connect two constant values!"
                return rewrapWithProperties(factory.literal(Util.isTrue(sub(1)) && Util.isTrue(sub(2))));
            }
            case OR : {
            	// $[Or, b1, b2]
            	normalizeArguments();
                if (!Util.isConstant(sub(1)) || !Util.isConstant(sub(2))) break; // "Can only connect two constant values!"
                return rewrapWithProperties(factory.literal(Util.isTrue(sub(1)) || Util.isTrue(sub(2))));
            }
            case NOT : {
            	// $[Not, b]
            	normalizeArguments();
                if (!Util.isConstant(sub(1))) break; // "Can only negate constant values!"
                return rewrapWithProperties(factory.literal(! Util.isTrue(sub(1))));
            }
            
			case CONCATENATION : {
            	// $[:, t1, t2, ...]
				normalizeArguments();
				StringBuilder b = new StringBuilder(); // be optimistic...
				for (int i = 1; i <arity(); ++i)
				{
					Term a = sub(i);
					if (!Util.isConstant(a))
						return null;
					String text;
	                switch (a.kind())
	                {
	                    case CONSTRUCTION : text = Util.symbol(a); break;
	                    case META_APPLICATION : text = a.metaVariable(); break;
	                    case VARIABLE_USE : text = a.variable().name(); break;
	                    default : break What;
	                }
					b.append(text);
				}
				return rewrapWithProperties(factory.literal(b.toString()));
			}
			
			case INDEX : {
				// $[Index, piece, text]
				normalizeArguments();
                if (!Util.isConstant(sub(1)) || !Util.isConstant(sub(2))) break;
                int index = Util.symbol(sub(1)).indexOf(Util.symbol(sub(2)));
                return rewrapWithProperties(factory.literal(index));
			}
			
			case CONTAINS : {
				// $[Contains, string, sub]
				normalizeArguments();
                if (!Util.isConstant(sub(1)) || !Util.isConstant(sub(2))) break;
                boolean contains = Util.symbol(sub(1)).contains(Util.symbol(sub(2)));
                return rewrapWithProperties(factory.literal(contains));
			}
			
			case STARTS_WITH : {
				// $[StartsWith, string, sub]
				normalizeArguments();
                if (!Util.isConstant(sub(1)) || !Util.isConstant(sub(2))) break;
                boolean startsWith = Util.symbol(sub(1)).startsWith(Util.symbol(sub(2)));
                return rewrapWithProperties(factory.literal(startsWith));
			}
			
			case ENDS_WITH : {
				// $[EndsWith, string, sub]
				normalizeArguments();
                if (!Util.isConstant(sub(1)) || !Util.isConstant(sub(2))) break;
                boolean endsWith = Util.symbol(sub(1)).endsWith(Util.symbol(sub(2)));
                return rewrapWithProperties(factory.literal(endsWith));
			}

			case MATCH_REGEX : {
				// $[MatchRegex, regexp, string]
				computeArguments();
                if (!Util.isConstant(sub(1)) || !Util.isConstant(sub(2))) break;
				String r = unquote(Util.symbol(sub(1)));
				java.util.regex.Pattern regex = java.util.regex.Pattern.compile(r);
				return rewrapWithProperties(factory.literal(regex.matcher(Util.symbol(sub(2))).matches()));
			}
			
			case LENGTH : {
				// $[Length, string]
				computeArguments();
                if (!Util.isConstant(sub(1))) break;
                int length = Util.symbol(sub(1)).length();
                return rewrapWithProperties(factory.literal(length));
			}
			
			case REPLACE : {
				// $[Replace, string, match, replace]
                computeArguments();
                if (!Util.isConstant(sub(1)) || !Util.isConstant(sub(2)) || !Util.isConstant(sub(3))) break;
                String symbol = Util.symbol(sub(1)).replace(Util.symbol(sub(2)), Util.symbol(sub(3)));
                return rewrapWithProperties(factory.literal(symbol));
			}
			
			case SQUASH : {
				// $[Squash, string]
                computeArguments();
                if (!Util.isConstant(sub(1))) break;
                String symbol = Util.symbol(sub(1)).replaceAll("[\\n\\t ]+", " ").trim();
                return rewrapWithProperties(factory.literal(symbol));
			}
			
			case SUBSTRING : {
                computeArguments();
                if (!Util.isConstant(sub(1)) || !Util.isConstant(sub(2)) || (arity() == 4 && !Util.isConstant(sub(3)))) break;
				// $[Substring, string, first] - 0-based indices
				// $[Substring, string, first, after-last] - 0-based indices
                String pre = Util.symbol(sub(1));
                int start = Integer.parseInt(Util.symbol(sub(2)));
                int end = arity() == 4 ?  Integer.parseInt(Util.symbol(sub(3))) : pre.length();
                return rewrapWithProperties(factory.literal(start < end ? pre.substring(start, end) : ""));
			}

			case UP_CASE : {
                computeArguments();
                if (!Util.isConstant(sub(1))) break;
				// $[UpCase, string]
                String string = Util.symbol(sub(1)).toUpperCase();
                return rewrapWithProperties(factory.literal(string));
			}

			case DOWN_CASE : {
                computeArguments();
                if (!Util.isConstant(sub(1))) break;
				// $[DownCase, string]
                String string = Util.symbol(sub(1)).toLowerCase();
                return rewrapWithProperties(factory.literal(string));
			}
			
			case DECODE_POINT : {
				computeArguments();
                if (!Util.isConstant(sub(1))) break;
				// $[DecodePoint, #string]
                return rewrapWithProperties(factory.literal(Character.codePointAt(Util.symbol(sub(1)), 0)));
			}

			case ENCODE_POINT : {
				computeArguments();
                if (!Util.isConstant(sub(1))) break;
				// $[EncodePoint, #int]
                int cp = Integer.parseInt(Util.symbol(sub(1)));
                return rewrapWithProperties(factory.literal((char) cp));
			}

			case TRIM : {
                computeArguments();
                if (!Util.isConstant(sub(1))) break;
				// $[UpCase, string]
                String string = Util.symbol(sub(1)).trim();
                return rewrapWithProperties(factory.literal(string));
			}

			case ESCAPE : {
                computeArguments();
                if (!Util.isConstant(sub(1))) break;
				// $[Escape, string]
                String string = sub(0).arity() == 0 ? Util.quoteJava(Util.symbol(sub(1))) : quoteWith(Util.symbol(sub(1)), Util.symbol(sub(0).sub(0)));
                return rewrapWithProperties(factory.literal(string));
			}

			case RESCAPE : {
                computeArguments();
                if (!Util.isConstant(sub(1))) break;
				// $[Rescape, string]
                String string = Util.unquoteJava(Util.symbol(sub(1)));
                return rewrapWithProperties(factory.literal(string));
			}
			case MANGLE  : {
                computeArguments();
                if (!Util.isConstant(sub(1))) break;
				// $[Mangle, constant]
                String string = Util.quoteJavaIdentifierPart(Util.symbol(sub(1)));
                return rewrapWithProperties(factory.literal(string));
			}
			
			case SPLIT : {
                computeArguments();
                if (!Util.isConstant(sub(1)) || !Util.isConstant(sub(2)) || arity() != 3) break;
				// $[Split, string, sep-regex]
                String string = Util.symbol(sub(1));
                GenericTerm sequence = (GenericTerm) factory.nil();
                if (!string.isEmpty())
                {
                	String regex = Util.symbol(sub(2));
                	String[] split = string.split(regex);
                	final Variable[] nobinds = {};
                	for (int i = split.length-1; i >= 0; --i)
                		sequence = factory.cons(nobinds, (GenericTerm) factory.literal(split[i]), nobinds, sequence);
                }
                return rewrapWithProperties(sequence);
			}
			
			case TO_FIRST : {
                computeArguments();
                if (!Util.isConstant(sub(1)) || !Util.isConstant(sub(2)) || (arity() > 3 && !Util.isConstant(sub(3)))) break;
                // $[UptoFirst, string, sep]
                String string = Util.symbol(sub(1));
                String first = Util.symbol(sub(2));
                int index = string.indexOf(first);
                return rewrapWithProperties(index < 0 ? (arity() > 3 ? sub(3) : sub(1)) : factory.literal(string.substring(0, index+first.length())));
			}

			case FROM_FIRST : {
                computeArguments();
                if (!Util.isConstant(sub(1)) || !Util.isConstant(sub(2)) || (arity() > 3 && !Util.isConstant(sub(3)))) break;
                // $[UptoFirst, string, sep]
                String string = Util.symbol(sub(1));
                String first = Util.symbol(sub(2));
                int index = string.indexOf(first);
                return rewrapWithProperties(index < 0 ? (arity() > 3 ? sub(3) : sub(1)) : factory.literal(string.substring(index)));
			}

			case BEFORE_FIRST : {
                computeArguments();
                if (!Util.isConstant(sub(1)) || !Util.isConstant(sub(2)) || (arity() > 3 && !Util.isConstant(sub(3)))) break;
                // $[BeforeFirst, string, sep]
                String string = Util.symbol(sub(1));
                String first = Util.symbol(sub(2));
                int index = string.indexOf(first);
                return rewrapWithProperties(index < 0 ? (arity() > 3 ? sub(3) : sub(1)) : factory.literal(string.substring(0, index)));
			}
			
			case AFTER_FIRST : {
                computeArguments();
                if (!Util.isConstant(sub(1)) || !Util.isConstant(sub(2)) || (arity() > 3 && !Util.isConstant(sub(3))))  break;
                // $[AfterFirst, string, sep]
                String string = Util.symbol(sub(1));
                String first = Util.symbol(sub(2));
                int index = string.indexOf(first);
                return rewrapWithProperties(index < 0 ? (arity() > 3 ? sub(3) : factory.literal("")) : factory.literal(string.substring(index+first.length())));
			}
			
			case EMPTY_SEQUENCE : {
				// $[EmptySequence, sequence]
                computeArguments();
                if (sub(1).kind() == Kind.CONSTRUCTION)
                {
                    return rewrapWithProperties(factory.literal(Util.isNull(sub(1))));
                }
                break;
			}
			
			case CONSTRUCTION : {
                // $[C[sort?], constructor, (argument1; ...; argumentN;)]
                computeArguments();
                if (arity() == 1 || !Util.isConstant(sub(1))) break; // can only generate constant constants [sic]
				return rewrapWithProperties(unquoteConstructionAndArguments(factory, sub(1).constructor().symbol(), (sub(0).arity() == 0 ? null : Util.symbol(sub(0).sub(0))), (arity() <= 2 ? factory.nil() : sub(2)), renamings));
			}
			
			case VARIABLE : {
				// $[V, t]
				// $[{...}V, Var] will retrieve instance from ... with same name TODO!
                computeArguments();
				if (arity() == 1 || !Util.isConstant(sub(1))) break; // "Can only build free variable with name from constant constructor argument!"
				return rewrapWithProperties(factory.newVariableUse(factory.makeVariable(Util.symbol(sub(1)), true)));
			}
			
			case META_APPLICATION : {
				// $[M, t, [#list]] ]
                computeArguments();
				if (arity() == 1 || !Util.isConstant(sub(1)) || arity() == 2 || !SequenceIterator.isSequencing(sub(2))) break; // "Can only build meta-application with name from first argument constant constructor!"
				return rewrapWithProperties(factory.newMetaApplication(Util.symbol(sub(1)), (arity() <= 2 ? NO_TERMS : Util.unconsArray(sub(2), false, renamings))));
			}
			
            case PROPERTY_NAMED : {
                computeArguments();
                if (!Util.isConstant(sub(1))) break; // no go unless name well defined
                String name = Util.symbol(sub(1));
                Term value = sub(2);
                Term owner = sub(3);
                return rewrapWithProperties(((GenericTerm) owner).wrapWithProperty(name, value, false));
            }

            case PROPERTY_NAMED_NOT : {
                computeArguments();
                if (!Util.isConstant(sub(1))) break; // no go unless name well defined
                String name = Util.symbol(sub(1));
                Term owner = sub(2);
                return rewrapWithProperties(GenericTerm.wrapWithNotProperty(name, (GenericTerm) owner, false));
            }

            case PROPERTY_VARIABLE : {
                computeArguments();
                Variable property;
                if (sub(1).kind() == Kind.VARIABLE_USE)
                    property = sub(1).variable();
                else if (Util.isConstant(sub(1)))
                    property = factory.makeVariable(Util.symbol(sub(1)), true);
                else
                    break; // no go unless variable well defined
                Term value = sub(2);
                Term owner = sub(3);
                return rewrapWithProperties(((GenericTerm)owner).wrapWithProperty(property, value, false));
            }

            case PROPERTY_VARIABLE_NOT : {
                computeArguments();
                Variable property;
                if (sub(1).kind() == Kind.VARIABLE_USE)
                    property = sub(1).variable();
                else if (Util.isConstant(sub(1)))
                    property = factory.makeVariable(Util.symbol(sub(1)), true);
                else
                    break; // no go unless variable well defined
                Term owner = sub(2);
                try
				{
					return rewrapWithProperties(((GenericTerm) ((GenericTerm) owner)).wrapWithNotProperty(property, false));
				}
				catch (CRSException e)
				{
					break;
				}
            }

			case PROPERTY_COLLECT : {
                computeArguments();
                String metavar;
                if (sub(1).kind() == Kind.META_APPLICATION && sub(1).arity() == 0)
                    metavar = sub(1).metaVariable();
                else if (Util.isConstant(sub(1)))
                    metavar = Util.symbol(sub(1));
                else
                    break; // no go unless meta-variable well defined
				Term owner = sub(2);
				return rewrapWithProperties(((GenericTerm) owner).wrapWithPropertiesRef(metavar, false));
			}

            case PROPERTIES : {
				// $[P, PROPERTIES_LIST, TERM]
                computeArguments();
            	return rewrapWithProperties(unquoteProperties(factory, sub(1), sub(2)));
			}
            
            case PASS_LOCATION_PROPERTIES : {
            	// $[{#loc}PassLocationProperties, {#env}#]
                computeArguments();
                PropertiesHolder ph0 = Util.propertiesHolder(sub(0));
            	String[] keys = { "$FileLocation", "$LineLocation", "$ColumnLocation" };
            	GenericTerm term = sub(1);
            	for (String key : keys)
            	{
                    PropertiesHolder ph = Util.propertiesHolder(term);
                    Term value = ph0.getProperty(key);
            		if (value != null && !Util.symbol(value).equals(ph.getProperty(key)))
            			term = Util.wrapWithProperty(term, key, value);
            	}
            	return term;
            }
            
            case FREE_VARIABLES : {
            	// $[FreeVariables, TERM]
            	// $[{#Env}FreeVariables, TERM]
            	// $[FreeVariables[SORTNAME], TERM]
            	// $[{#Env}FreeVariables[SORTNAME], TERM]
            	computeArguments();
            	Set <Variable> base = null;
            	if (Util.hasProperties(sub(0)))
            	{
            		base = new HashSet<Variable>();
            		for (Variable v : Util.propertiesHolder(sub(0)).propertyVariables())
            			base.add(v);
            	}
            	Set<Variable> vs = new TreeSet<Variable>();
            	sub(1).addFree(vs, LinkedExtensibleSet.EMPTY_VARIABLE_SET, true, base);
            	return rewrapWithProperties(Util.listifyVariableSet(factory, vs));
            }
            case INTERSECT_VARIABLES :{
            	// $[IntersectVariables[S?], vs1, vs2]
                computeArguments();
            	Set<Variable> vs = Util.extractVariableSet(sub(1));
            	vs.retainAll(Util.extractVariableSet(sub(2)));
            	return rewrapWithProperties(Util.listifyVariableSet(factory, vs));
            }
            case UNION_VARIABLES : {
            	// $[UnionVariables[S?], vs1, vs2]
                computeArguments();
            	Set<Variable> vs = Util.extractVariableSet(sub(1));
            	vs.addAll(Util.extractVariableSet(sub(2)));
            	return rewrapWithProperties(Util.listifyVariableSet(factory, vs));
            }
            case EXCEPT_VARIABLES : {
            	// $[ExceptVariables[S?], vs1, vs2]
                computeArguments();
            	Set<Variable> vs = Util.extractVariableSet(sub(1));
            	vs.removeAll(Util.extractVariableSet(sub(2)));
            	return rewrapWithProperties(Util.listifyVariableSet(factory, vs));
            }
			
			case MATCH :
				// $[Match,...] does not evaluate at all!
				break;

            case HAS_URL : {
                computeArguments();
                try
                {
                    for (int i = 1; i < arity(); ++i)
                        if (!Util.isConstant(sub(i)))
                            break What; // parsing not supported until all arguments constant.

                    URL base = new URL("file:."); // be paranoid
                    Term parseContextURL = Util.materialize(factory.get(Factory.BASE_URL), false);
                    if (parseContextURL != null)
                    	base = new URL(base, parseContextURL.toString());
                    URL url = new URL(base, Util.symbol(sub(1)));
                    new InputStreamReader(url.openStream());
                    if (Util.getInteger(factory, Factory.VERBOSE_OPTION, 0) > 0)
                    	if (Util.getInteger(factory, GenericFactory.VERBOSE_OPTION, 0) >= 0)
                    		factory.message(toString());
                    return rewrapWithProperties(factory.truth());
                }
                catch (IOException e)
                {
                    return rewrapWithProperties(factory.lie());
                }
            }
            
            case PARSE :
            case PARSE_URL :
            case PARSE_TEXT :
            case PARSE_RESOURCE :
            case LOAD :
            case LOAD_TERM : {
                computeArguments();
                try
                {
                    for (int i = 1; i < arity(); ++i)
                        if (!Util.isConstant(sub(i)))
                            break What; // parsing not supported until all arguments constant.

                    String category;
                    String resource;
                    Reader reader;
                    switch (what)
                    {
                    	case PARSE :
                        case PARSE_URL : {
    						URL base = new URL("file:."); // be paranoid
    						Term parseContextURL = Util.materialize(factory.get(Factory.BASE_URL), false);
    						if (parseContextURL != null)
    							base = new URL(base, parseContextURL.toString());
                    		if (arity() == 2)
                    		{
                    			// $[Parse, url]
                    			category = null;
                    			URL url = new URL(base, Util.symbol(sub(1)));
                    			resource = url.toExternalForm();
                    			reader = new InputStreamReader(url.openStream());
                    		}
                    		else
                    		{
                    			// $[ParseURL, category, url]
                    			category = Util.isNull(sub(1)) ? null : Util.symbol(sub(1));
                    			URL url = new URL(base, Util.symbol(sub(2)));
                    			resource = url.toExternalForm();
                    			reader = new InputStreamReader(url.openStream());
                    		}
                			break;
                        }
                        case PARSE_TEXT : {
                        	// $[ParseText[Sort], category, text]
                        	category = Util.symbol(sub(1));
                        	resource = null;
                            reader = new StringReader(Util.symbol(sub(2)));
                            break;
                        }
                        case PARSE_RESOURCE : {
                        	// $[ParseResource, category, resource-name]
                			category = Util.symbol(sub(1));
                        	resource = Util.symbol(sub(2));
                            reader = Util.resourceReader(factory, resource);
                            break;
                        }
                        case LOAD : {
                        	// $[Load, resource-name-or-url]
                        	// $[Load, resource-name-or-url, category]
                        	resource = Util.symbol(sub(1));
                        	reader = Util.resourceReader(factory, resource);
                			category = (arity() <= 2 || !Util.isTrue(sub(2)) ? null : Util.symbol(sub(2)));
                            break;
                        }
                        case LOAD_TERM : {
                        	// $[LoadTerm, resource-name-or-url]
                        	resource = Util.quoteJavaIdentifierPart(Util.symbol(sub(1)));
                        	reader = Util.resourceReader(factory, resource);
                			category = null;
                            break;
                        }
                        default :
                        	break What; // "Unknown $[Parse...] command?!?"
                    }
					if (Util.getInteger(factory, Factory.VERBOSE_OPTION, 0) > 0)
	                    if (Util.getInteger(factory, GenericFactory.VERBOSE_OPTION, 0) >= 0)
                        	factory.message(toString());
                    Buffer buffer = new Buffer(factory);
                    Sink bufferSink = buffer.sink();
					Map<String,Variable> free = null;
					if (globals != null)
					{
						free = new HashMap<String, Variable>();
						for (Variable v : globals)
							free.put(v.name(), v);
					}
                    factory.parser(factory).parse(bufferSink, category, reader, resource, 1, 1, null);
                    Term result = buffer.term(true);
                    assert result != null : "Parser did not build complete term.";
                    return rewrapWithProperties(result);
                }
                catch (CRSException e)
                {
                	throw new RuntimeException(e);
                }
                catch (IOException e)
                {
                	throw new RuntimeException(e);
                }
            }
            
            case SAVE_TERM :
            	// $[SaveTerm, #uri, #term, #result]
            	computeArgument(1);
///            	contractArgument(2);
            	computeArgument(3);
            	if (Util.isConstant(sub(1)))
            	{
            		String resource = Util.quoteJavaIdentifierPart(Util.symbol(sub(1)));
            		try
            		{
            			Appendable w = new WriterAppender(new FileWriter(resource));
            			sub(2).appendTo(w, new HashMap<Variable, String>(), Integer.MAX_VALUE, factory.defined(Factory.SIMPLE_TERMS), true, true, null);
            		}
            		catch (IOException e)
            		{
            			throw new RuntimeException(toString()+" failed", e);
            		}
            		return sub(3);
            	}
            	break;
            	
			case SCRIPT :
				// $[Script, script]
				// $[Script, script, name]
///				contractArgument(1);
				computeArgument(2);
				if (arity() == 2 || Util.isConstant(sub(2)))
				{
					try
					{
						SequenceBuffer result = new SequenceBuffer(factory);
						Builder builder = factory.builder();
						builder.load(result.sink(), sub(1));
						if (arity() > 2)
						{
							factory.set(Util.symbol(sub(2)), (GenericCRS) builder.toCRS(true));
						}
						return rewrapWithProperties(result.term(true));
					}
					catch (CRSException e)
					{
	                	throw new RuntimeException(toString()+" failed", e);
					}
				}
				break;
				
			case NORMALIZE :
				// $[Normalize, term, name]
				computeArguments();
				if (Util.isConstant(sub(2)))
				{
					Constructor c = factory.get(Util.symbol(sub(2))).constructor(); // CRS hidden in constructor
					if (c != null && c instanceof CRS)
					{
						try
						{
							return rewrapWithProperties(((CRS) c).normalize(sub(1)));
						}
						catch (CRSException e)
						{}
					}
				}
				break;
				
			case URL :
                computeArguments();
                // $[URL, url]
                // $[URL, url, base]
                computeArguments();
				if (Util.isConstant(sub(1)) && (arity() == 2 || Util.isConstant(sub(2))))
				{
					String name = Util.symbol(sub(1));
					try
					{
						URL base = new URL("file:."); // be paranoid
						Term parseContextURL = Util.materialize(((GenericFactory) factory).get(Factory.BASE_URL), false);
						if (parseContextURL != null)
							base = new URL(base, parseContextURL.toString());
						if (arity() > 2)
							base = new URL(base, Util.symbol(sub(2)));
						URL url = new URL(base, name);
						return rewrapWithProperties(factory.newConstruction(factory.makeConstructor(url), GenericTerm.NO_BINDS, GenericTerm.NO_TERMS));
					}
					catch (MalformedURLException e)
					{} // Entire construct is ignored if it can't do anything...
				}
				break;

			case IF : {
				// $[If, truth-value, true-result[, false-result]]
				normalizeArgument(1);
                if (Util.isConstant(sub(1)))
                {
                	if (Util.isTrue(sub(1)))
                	{
        				computeArgument(2);
                		return rewrapWithProperties(sub(2));
                	}
                	else
                	{
                		if (arity() == 3)
							return rewrapWithProperties(factory.nil());
						else
                		{
	        				computeArgument(3);
	                		return rewrapWithProperties(sub(3));
                		}
                	}
                }
///                System.out.println("//*** Unevaluated $[If, "+sub(1)+", ...] with "+needsContraction[1]+" AND "+valuation);
                break;
			}
			
			case PICK : {
				// $[Pick, index, list]
				computeArgument(1);
///				contractArgument(2);
                if (Util.isConstant(sub(1)))
                {
                	try
                	{
                		int index = Integer.decode(Util.symbol(sub(1)));
                		Term list = sub(2);
                		if (index < 0) break What;
                		while (index-- > 0)
                		{
                			if (!Util.isCons(list.constructor())) break What;
                			list = list.sub(1);
                		}
            			if (!Util.isCons(list.constructor())) break What;
            			return rewrapWithProperties(list.sub(0));
                	}
                	catch (NumberFormatException e)
                	{}
                }
				break;
			}
			
			case IF_ZERO : {
				// $[IfZero, maybe-zero-number, true-result, false-result]
				computeArgument(1);
                if (Util.isConstant(sub(1)))
                {
                    Constructor c = sub(1).constructor();
                	if ("0".equals(c.symbol()))
                	{
        				computeArgument(2);
                		return rewrapWithProperties(sub(2));
                	}
                	else
                	{
                		if (arity() == 3)
							return rewrapWithProperties(factory.nil());
						else
                		{
	        				computeArgument(3);
	                		return rewrapWithProperties(sub(3));
                		}
                	}
                }
                break;
			}

			case IF_EMPTY : {
				// $[IfEmpty, maybe-empty-string-or-sequence, true-result, false-result]
				computeArgument(1);
                if (Util.isConstant(sub(1)))
                {
                    Constructor c = sub(1).constructor();
                	if ("".equals(c.symbol()) || Util.isNull(c))
                	{
        				computeArgument(2);
                		return rewrapWithProperties(sub(2));
                	}
                	else
                	{
                		if (arity() == 3)
							return rewrapWithProperties(factory.nil());
						else
                		{
	        				computeArgument(3);
	                		return rewrapWithProperties(sub(3));
                		}
                	}
                }
                break;
			}

            case KEYS : {
            	PropertiesHolder properties = Util.propertiesHolder(sub(0));
            	if (properties.isMeta())
            		break; // If the environment is a meta-environment then give up!
            	GenericTerm tail = factory.nil();
            	// Now get all the usual properties.
            	for (String key : properties.propertyNames())
            		tail = factory.cons(GenericTerm.NO_BIND, factory.literal(key), GenericTerm.NO_BIND, tail);
            	for (Variable key : properties.propertyVariables())
            		tail = factory.cons(GenericTerm.NO_BIND, factory.newVariableUse(key), GenericTerm.NO_BIND, tail);
            	return rewrapWithProperties(tail);
            }
            
			case IF_DEF : {
				// $[{...}IfDef, maybe-defined-name, true-result, false-result]
				computeArgument(1);
                boolean defined = false;
                if (sub(0) instanceof PropertiesConstraintsWrapper)
                {
                	// $[{...}IfDef,...] used for meta-rewriting...tongue in cheek:
                	PropertiesConstraintsWrapper propertiesWrapper = (PropertiesConstraintsWrapper) sub(0);
                	WhichKey : switch (sub(1).kind())
                	{
                		case CONSTRUCTION : 
                			{
                            	// Constructor property - if explicitly included or constrained then evaluate.
                        		String symbol = Util.symbol(sub(1));
                        		Map<String, Term> properties = propertiesWrapper.getLocalProperties();
                        		if (properties.containsKey(symbol))
                        		{
                        			// Constructor property *is* mentioned - C:t succeeds, &not;C fails.
                        			defined = properties.get(symbol) != null;
                        		}
                        		else
                        		{
                        			// Constructor property is *not* mentioned...if it may be hiding in meta-variable stuff then break out, otherwise just fail.
                        			if (propertiesWrapper.hasUnknownKeys())
                        				break What;
                        		}
                    			break;
                        	}
                		case VARIABLE_USE :
                        	{
                            	// Variable property - if explicitly included or constrained then evaluate.
                        		Variable variable = sub(1).variable();
                        		Map<Variable, Term> properties = propertiesWrapper.getLocalVariableProperties();
                        		if (properties.containsKey(variable))
                        		{
                        			// Variable property *is* mentioned - v:t succeeds, &not;v fails.
                        			defined = properties.get(variable) != null;
                        		}
                        		else
                        		{
                        			// Variable property is *not* mentioned...if it may be hiding in meta-variable stuff then break out, otherwise just fail.
                        			if (propertiesWrapper.hasUnknownKeys())
                        				break What;
                        		}
                        		break;
                        	}
                		case META_APPLICATION :
                			{
                				// Property key only known as meta-variable - if explicitly included or constrained then evaluate.
                				String metaVariable = sub(1).metaVariable();
                				for (Map.Entry<String,Term> e : propertiesWrapper.getLocalMetaProperties().entrySet())
                				{
                					if (metaVariable.equals(e.getKey()))
                					{
                						// Found the meta-variable...#:t succeeds, &not;# fails.
                						defined = e.getValue() != null;
                						break WhichKey;
                					}
                				}
                			}
                		default :
                			break What;
                	}
                }
                if (!defined)
                {
                	// Look locally.
                	PropertiesHolder properties = (PropertiesHolder) sub(0).constructor();
                	switch (sub(1).kind())
                	{
                		case CONSTRUCTION :
                    		defined = properties.getProperty(Util.symbol(sub(1))) != null;
                    		break;
                		case VARIABLE_USE :
                    		defined = properties.getProperty(sub(1).variable()) != null;
                    		break;
                    	default :
                    		break What;
                	}
                }
                if (!defined && Util.isConstant(sub(1)))
                {
					defined = ((GenericFactory) factory).defined(Util.symbol(sub(1)));
                }
                if (defined)
                {
                	computeArgument(2);
                	return rewrapWithProperties(sub(2));
                }
                else
                {
                	if (arity() == 3)
                		return rewrapWithProperties(factory.nil());
                	else
                	{
                		computeArgument(3);
                		return rewrapWithProperties(sub(3));
                	}
                }
			}

			case IF_LINEAR : {
				// $[IfLinear, v, #true, #false]
				computeArgument(1);
                if (sub(1).kind() == Kind.VARIABLE_USE)
                {
                	if (!sub(1).variable().promiscuous())
                	{
        				computeArgument(2);
                		return rewrapWithProperties(sub(2));
                	}
                	else
                	{
                		if (arity() == 3)
							return rewrapWithProperties(factory.nil());
						else
                		{
	        				computeArgument(3);
	                		return rewrapWithProperties(sub(3));
                		}
                	}
                }
                break;
			}
			
			case GET :
			case GET_REF : {
				// $[{...}Get, key]
				// $[{...}Get, key, fail]
				computeArgument(1);
				if (!Util.propertiesHolder(sub(0)).isMeta())
				{
					Term value = null;
					if (sub(1).kind() == Kind.VARIABLE_USE)
					{
						// Variable key with actual environment. 
						value = Util.propertiesHolder(sub(0)).getProperty(sub(1).variable());
					}
					else if (Util.isConstant(sub(1)))
					{
						String key = Util.symbol(sub(1));
						if (Util.hasProperties(sub(0)))
						{
							// Constant key with actual environment.
							value = Util.propertiesHolder(sub(0)).getProperty(key);
						}
						else
						{
							// No environment passed -- delegate to factory.
							Stub lookup = factory.get(key);
							if (lookup != null) value = lookup.copy(false, renamings);
						}
					}
					if (value != null)
						return rewrapWithProperties(value);
					if (arity() > 2)
					{
						computeArgument(2);
						return rewrapWithProperties(sub(2));
					}
				}
				break;
			}

			case INHERIT : {
				// $[{...}Inherit, term]
				computeArgument(1);
				String ref = Util.propertyRef(sub(0));
				if (ref != null)
				{
					GenericTerm t = Util.inherit(factory, sub(1).copy(false, LinkedExtensibleMap.EMPTY_RENAMING), ref);
					return rewrapWithProperties(t);
				}
				break;
			}

			case SYNTHESIZE : {
				// $[{...}Synthesize, term]
				computeArgument(1);
				String ref = Util.propertyRef(sub(0));
				if (ref != null)
				{
					GenericTerm t = Util.synthesize(factory, sub(1).copy(false, LinkedExtensibleMap.EMPTY_RENAMING), ref);
					return rewrapWithProperties(t);
				}
				break;
			}

			case CAST :
            	// $[Cast[sort], value]
            	computeArguments();
            	return rewrapWithProperties(sub(1));
            
			case SORT_OF : {
				// $[SortOf, term]
///				contractArgument(1);
				Term term = sub(1);
				if (term.kind() == Kind.CONSTRUCTION)
				{
					Term sort = factory.sortOf(Util.symbol(term));
					GenericTerm t = factory.nil();
					if (sort != null)
						t = factory.cons(NO_BIND, (GenericTerm) sort, NO_BIND, t);
					return t;
				}
				return factory.nil();
			}
			
			case CHECK_SORT_OF : {
				// $[CheckSortOf, sort, term]
                computeArguments();
				Term sort = sub(1);
				Term term = sub(2);
				try
				{
					factory.checkSortOf(sort, term, LinkedExtensibleMap.EMPTY_VARIABLE_PROPERTIES, new HashMap<Variable, Term>(), new HashMap<String, Term>());
					return rewrapWithProperties(factory.truth());
				}
				catch (CRSException e)
				{
					return rewrapWithProperties(factory.lie());
				}
			}
            case PRINT :
            	// $[Print, term]
            	// $[Print, term, result]
                computeArguments();
                try
                {
                    sub(1).appendTo(System.out, new HashMap<Variable, String>(), Integer.MAX_VALUE, factory.defined(Factory.SIMPLE_TERMS), true, true, null); // TODO: allow depth?
                    System.out.println();
                    System.out.flush();
                    return rewrapWithProperties(arity() == 2 ? factory.nil() : sub(2));
                }
                catch (IOException e)
                {}
                break;

            case FORMAT_NUMBER : {
            	// $[FormatNumber, number]
            	// $[FormatNumber, number, format]
                computeArguments();
            	if (!Util.isConstant(sub(1)))// || !CRS.NUMERIC_SORT.equals( sub(1).constructor().literalSort()))
            		break;
            	if (arity() == 2)
            		return rewrapWithProperties(factory.literal(Util.symbol(sub(1))));
            	break; // TODO: implement format argument.
            }
            
            case FORMAT : {
            	// $[Format, format, args...]
                computeArguments();
            	if (!Util.isConstant(sub(1)))
            		break;
                String s = format();
                if (s == null)
                	break;
        		return rewrapWithProperties(factory.literal(s));
            }
            
            case SHOW :
            	// $[Show, term]
///            	contractArgument(1);
                return rewrapWithProperties(factory.literal(sub(1).toString()));

            case COMPUTE :
            	// $[Compute, term]
            	computeArguments();
                return rewrapWithProperties(sub(1));

            case ECHO :
            	// $[Echo, message]
            	// $[Echo, message, result]
                computeArguments();
                System.out.print(Util.symbol(sub(1)));
                System.out.flush();
                return rewrapWithProperties(arity() == 2 ? factory.nil() : sub(2));

            case HASH_CODE :
            	// $[HashCode, #term] is hex string of a hash code.
            	return rewrapWithProperties(factory.literal((long) sub(1).hashCode()));
                
            case DUMP :
                try
                {
                	Map<Variable, String> used = new HashMap<Variable, String>();
                    boolean full = factory.defined(Factory.SIMPLE_TERMS);
                    sub(1).appendTo(System.out, used, Integer.MAX_VALUE, full, true, true, null);
                    System.out.print(" ");
                    sub(2).appendTo(System.out, used, Integer.MAX_VALUE, full, true, true, null);
                    System.out.println();
                    System.out.flush();
                    return rewrapWithProperties(sub(2));
                }
                catch (IOException e)
                {}
                break;

            case TRACE :
            	// $[Trace, message]
            	// $[Trace, message, result]
            	computeArguments();
                try
                {
                    sub(1).appendTo(System.err, new HashMap<Variable, String>(), Integer.MAX_VALUE, factory.defined(Factory.SIMPLE_TERMS), true, true, null);
                    System.err.println();
                    System.err.flush();
                    return rewrapWithProperties(arity() == 2 ? sub(1) : sub(2));
                }
                catch (IOException e)
                {}
                break;
            
            case UNIFY :
            	// $[Unify, sort1, sort2]
                computeArguments();
                try
                {
                	GenericTerm sort = Unifier.unify(sub(1), sub(2), factory);
	            	return sort == null ? factory.nil() : sort;
                }
                catch (CRSException e)
                {
                }
                break;

            case CALL:
            case TRYCALL:
            	// $[Call, "name", args...]
            	// $[TryCall, "name", args...]
            	
            	// First part is the same
            	computeArguments();
            	String qname = Util.symbol(sub(1));
            	int index = qname.lastIndexOf(".");
            	if (index != -1)
            	{
            		String classname = qname.substring(0, index);
            		String methodname = qname.substring(index + 1);
            		try
            		{
            			Class<?> c = Class.forName(classname);
            			
            			// Compute argument types and value.
            			Class<?>[] paramTypes = null;
            			Object[] values = null;
            			if (arity() > 2)
            			{
            				paramTypes = new Class<?>[arity() - 2];
            				values = new Object[arity() - 2];
            				for (int i = 2; i < arity(); i ++)
            				{
            					String sort = sub(i).constructor().literalSort();
            					if (sort == null)
            					{
            						paramTypes[i - 2] = Term.class;
            						values[i - 2] = sub(i);
            					}
            					else if (sort.equals(CRS.STRING_SORT))
            					{
            						paramTypes[i - 2] = String.class;
            						values[i - 2] = Util.symbol(sub(i));
            					}
            					else if (sort.equals(CRS.NUMERIC_SORT))
            					{
            						paramTypes[i - 2] = Double.class;
            						values[i - 2] = Double.parseDouble(Util.symbol(sub(i)));
            					}
            					else if (sort.equals(CRS.BOOLEAN_SORT))
            					{
            						paramTypes[i - 2] = Boolean.class;
            						values[i - 2] = Util.symbol(sub(i)).equals("$True") ? Boolean.TRUE : Boolean.FALSE;
            					}
            				}
            			}
            			Method m = c.getMethod(methodname, paramTypes);
            			Object result = m.invoke(null,  values);
            			GenericTerm termResult = rewrapWithProperties(factory.literal(result.toString()));
            			if (what == Primitive.CALL)
            				return termResult;
            			else
            			{
            				// Return $TrySuccess[result]
            				GenericTerm[] subterms = new GenericTerm[1];
            				subterms[0] = termResult;
            				return factory.newConstruction(factory.makeConstructor(CRS.TRYSUCCESS_SYMBOL), GenericTerm.NO_BINDS, subterms);
            			}
            		} catch (Exception e)
            		{	
            			if (what == Primitive.TRYCALL)
            			{
            				// Return $TryFailure[msg]
            				GenericTerm[] subterms = new GenericTerm[1];
            				subterms[0] = factory.literal(e.getLocalizedMessage());
            				return factory.newConstruction(factory.makeConstructor(CRS.TRYFAILURE_SYMBOL), GenericTerm.NO_BINDS, subterms);
            			}
            			else
            			{
            				throw new RuntimeException ("Exception raised when evaluating $[Call primitive: " + e.getMessage());
            			}
            		}
            	}	
            	break;
            	
            	
            case ERROR :
            case FORGIVABLEERROR :
            	// $[Error, ...]
            	normalizeArguments();
                error();
                break;

            case IGNORE :
            	computeArguments();
                break;
		}
		return null;
	}
	
	/**
	 * Add properties on this term to a generated term.
	 * @param term to add the properties to
	 * @return term with added properties
	 */
	GenericTerm rewrapWithProperties(Term term)
	{
		try
		{
			return ((GenericTerm) term).wrapWithPropertiesOf(this);
		}
		catch (CRSException e)
		{
			return null;
		}
	}

//	/** Helper to collect property lists. */
//	static String collectPropertyLists(GenericFactory factory, Term propertyPattern, Map<String, Term> namedProperties, Map<Variable, Term> variableProperties, List<Pair<String, Term>> metaProperties)
//	{
//		FlattenedSequence propertyList = new FlattenedSequence(propertyPattern);
//		String ref = null;
//		for (int i = 0; i < propertyList.arity(); ++i)
//		{
//			assert propertyList.binders[i].length == 0 : "$[Properties] property list cannot have binders!";
//			Term property = propertyList.terms[i]; // should end up as property key
//			Term value;
//			if (property.kind() == Kind.CONSTRUCTION && Util.isApply(property.constructor()))
//			{
//				Term first = property.sub(0);
//				Term second = property.sub(1);
//				if (first.kind() == Kind.CONSTRUCTION && Util.symbol(first).equals("&not;")) // TODO: constant...
//				{
//					// (&not; key)
//					property = second;
//					value = null;
//				}
//				else
//				{
//					// (key value)
//					property = first;
//					value = second;
//				}
//			}
//			else
//			{
//				// key
//				value = factory.nil();
//			}
//			switch (property.kind())
//			{
//				case CONSTRUCTION :
//					// C or (&not; C) or (C value)
//					namedProperties.put(Util.symbol(property), value);
//					break;
//				case VARIABLE_USE :
//					// v or (&not; v) or (v value)
//					variableProperties.put(property.variable(), value);
//					break;
//				case META_APPLICATION :
//					if (value != null && value.kind() == Kind.CONSTRUCTION && Util.isNull(value.constructor()))
//					{
//						// # is special notation for collection reference.
//						assert ref == null : "$[Properties] can only have one collection meta-variable";
//						ref = property.metaVariable();
//					}
//					else
//					{
//						// (&not; #) or (# value)
//						metaProperties.add(new Pair<String, Term>(property.metaVariable(), value));
//					}
//					break;
//			}
//		}
//		return ref;
//	}

//	/** Helper to extract properties as a single list. */
//	private Term propertiesAsList(Term term)
//	{
//		Term termProperties = factory.nil();
//		PropertiesHolder ph = (term instanceof PropertiesHolder ? (PropertiesHolder) term : term.constructor());
//		for (String name : ph.propertyNames())
//		{
//			Term value = ph.getProperty(name);
//			if (term == null) // negated constraint
//				termProperties = factory.cons(NO_BIND, factory.app(NO_BIND, factory.constant("¬"), NO_BIND, value), NO_BIND, factory.constant(name));
//			else
//				termProperties = factory.cons(NO_BIND, factory.app(NO_BIND, factory.constant(name), NO_BIND, value), NO_BIND, termProperties);
//		}
//		for (Variable variable : ph.propertyVariables())
//		{
//			Term value = ph.getProperty(variable);
//			if (term == null)
//				termProperties = factory.cons(NO_BIND, factory.app(NO_BIND, factory.constant("¬"), NO_BIND, value), NO_BIND, factory.newVariableUse(variable));
//			else
//				termProperties = factory.cons(NO_BIND, factory.app(NO_BIND, factory.newVariableUse(variable), NO_BIND, value), NO_BIND, termProperties);
//		}
//		// TODO: meta-properties...
//		return termProperties;
//	}
	
//	/**
//	 * Interpret quoted term.
//	 * @param factory for creating terms
//	 * @param contextBinders with context-defined variable names
//	 * @param quoted term to interpret
//	 * @see Primitive#QUOTE
//	 */
//	public static Term quote(GenericFactory factory, ExtensibleMap<String,Variable> contextBinders, Term quoted)
//	{
//		assert quoted.kind() == Kind.CONSTRUCTION : "Quoting $[Q,...] only accepts constructors!";
//		String tag = Util.symbol(quoted);
//		if ("C".equals(tag))
//		{
//			switch (quoted.arity())
//			{
//				case 1 : {
//					// C[c]
//					assert quoted.binders(0).length == 0 : "$[Q] bad C[ constructor ]";
//					Constructor c = q_constructor(factory, contextBinders, quoted.sub(0));
//					return factory.newConstruction(c, GenericTerm.NO_BINDS, GenericTerm.NO_TERMS);
//				}
//				case 2 : {
//					// C[ c, as ]
//					assert quoted.binders(0).length == 0 && quoted.binders(1).length == 0 : "$[Q] bad C[ constructor, arguments ]";
//					Constructor c = q_constructor(factory, contextBinders, quoted.sub(0));
//					QuotedArguments qas = new QuotedArguments(factory, contextBinders, quoted.sub(1));
//					return factory.newConstruction(c, qas.binders, qas.terms);
//				}
//			}
//			assert false : "$[Q] bad C[]";
//			return null;
//		}
//		else if ("V".equals(tag))
//		{
//			assert quoted.arity() == 1 && quoted.binders(0).length == 0 : "$[Q] variable subterms have form V[ name ]";
//			Variable variable;
//			switch (quoted.sub(0).kind())
//			{
//				case CONSTRUCTION : {
//					// V[name]
//					String name = q_string(quoted.sub(0));
//					variable = (contextBinders.containsKey(name) ? contextBinders.get(name) : factory.makeVariable(name, true));
//					break;
//				}
//				case VARIABLE_USE :
//					// V[variable]
//					variable = quoted.sub(0).variable();
//					break;
//				default :
//					assert false : "$[Q] bad V[]";
//					return null;
//			}
//			return factory.newVariableUse(variable);
//		}
//		else if ("M".equals(tag))
//		{
//			// M[ name, as ]
//			assert quoted.arity() == 2 && quoted.binders(0).length == 0 && quoted.binders(1).length == 0 : "$[Q] construction subterms have form C[ constructor, arguments ]";
//			String metaVariable = q_string(quoted.sub(0));
//			QuotedArguments qas = new QuotedArguments(factory, contextBinders, quoted.sub(1));
//			return factory.newMetaApplication(metaVariable, qas.terms);
//		}
//		else if ("T".equals(tag))
//		{
//			// T[ term ]
//			assert quoted.arity() == 1 && quoted.binders(0).length == 0 : "$[Q] bad T[ term ]";
//			return quoted.sub(0);
//		}
//		else 
//		{
//			assert false : "Impossible $[Q] subterm.";
//			return null;
//		}
//	}
//	private static String q_string(Term name)
//	{
//		assert Util.isConstant(name) : "$[Q] name must be constant.";
//		return Util.symbol(name);
//	}
//	private static Constructor q_constructor(GenericFactory factory, ExtensibleMap<String,Variable> binders, Term constructor)
//	{
//		String ref = null;
//		Map<String,Term> namedProps = new HashMap<String, Term>();
//		Map<Variable,Term> variableProps = new HashMap<Variable, Term>();
//		List<Pair<String, Term>> metaProps = new ArrayList<Pair<String,Term>>();
//		boolean meta = false;
//		while (constructor.kind() == Kind.CONSTRUCTION && "P".equals(Util.symbol(constructor)))
//		{
//			assert constructor.arity() == 3 : "$[Q] property needs key value constructor";
//			Term key = quote(factory, binders, constructor.sub(0));
//			Term value = quote(factory, binders, constructor.sub(1));
//			switch (key.kind())
//			{
//				case CONSTRUCTION :
//					namedProps.put(Util.symbol(key), value);
//					break;
//				case VARIABLE_USE :
//					variableProps.put(key.variable(), value);
//					break;
//				case META_APPLICATION :
//					metaProps.add(new Pair<String, Term>(key.metaVariable(), value));
//					break;
//				default :
//					assert false : "unknown kind?!?";
//					break;
//			}
//			constructor = constructor.sub(2);
//		}
//		assert constructor.kind() == Kind.CONSTRUCTION && "A".equals(Util.symbol(constructor)) : "$[Q] constructor must ultimately be A[name]";
//		Constructor c = factory.makeConstructor(constructor.sub(0).constructor().symbol());
//		if (meta)
//			return new PropertiesWrapperConstructor(ref, namedProps, variableProps, metaProps);
//		if (variableProps.isEmpty() && namedProps.isEmpty())
//			return c; // no properties at all
//		return new PropertiesConstructor(factory, c, namedProps, variableProps); // got properties
//	}
//	private static class QuotedArguments
//	{
//	    /** The argument binders. */
//	    final Variable[][] binders;
//	    /** The argument subterms. */
//	    final Term[] terms;
//	    /** Construct flat sequence. */
//	    QuotedArguments(GenericFactory factory, ExtensibleMap<String,Variable> contextBinders, Term sequence)
//	    {
//	        List<Variable[]> bs = new ArrayList<Variable[]>();
//	        List<Term> ts = new ArrayList<Term>();
//	        if (sequence != null)
//	        {
//	    	    while (true)
//	    	    {
//	    	        if (Util.isCons(sequence.constructor()))
//	    	        {
//	    	            // Add the head of the sequence and repeat for tail.
//	    	        	q_argument(factory, contextBinders, bs, ts, sequence.sub(0));
//	    	            assert sequence.binders(1).length == 0 : "Tail of sequence cannot have binders!";
//	    	            sequence = sequence.sub(1);
//	    	        }
//	    	        else
//	    	        {
//	    	            assert Util.isNull(sequence.constructor()) : "List to be flattened is terminated by non-$Nil?!?";
//	    	            break;
//	    	        }
//	            }
//	        }
//	        binders = bs.toArray(new Variable[bs.size()][]);
//	        terms = ts.toArray(new Term[bs.size()]);
//	    }
//	}
//	private static void q_argument(GenericFactory factory, ExtensibleMap<String,Variable> contextBinders, List<Variable[]> binderlists, List<Term> terms, Term argument)
//	{
//		assert argument.kind() == Kind.CONSTRUCTION : "Quoting $[Q,...] only accepts constructors!";
//		List<Variable> vs = new ArrayList<Variable>();
//		while (argument.kind() == Kind.CONSTRUCTION && "B".equals(Util.symbol(argument)))
//		{
//			switch (argument.arity())
//			{
//				case 1 :
//					// B[variable . argument]
//					assert argument.binders(0).length == 1 : "$[Q] argument variable binders take form B[v.TERM]";
//					vs.add(argument.binders(0)[0]);
//					argument = argument.sub(0);
//					break;
//				case 2 : {
//					// B[name, argument]
//					assert argument.binders(0).length == 0 && argument.binders(1).length == 0 : "$[Q] argument named binders take form B['v', TERM]";
//					String name = q_string(argument.sub(0));
//					Variable variable = factory.makeVariable(name, true);
//					contextBinders = contextBinders.extend(name, variable);
//					vs.add(variable);
//					argument = argument.sub(1);
//					break;
//				}
//				default :
//					assert false : "$[Q] has bad B[]";
//					return;
//			}
//		}
//		binderlists.add(vs.toArray(new Variable[vs.size()]));
//		terms.add(quote(factory, contextBinders, argument));
//	}

	/** Helper to trigger runtime error using {@link RuntimeException} to support $[Error,..] (invokes {@link #format()} for arguments). */
	void error()
	{
	    switch (arity())
	    {
	        case 1 :
	            throw new RuntimeException();
	        case 2 :
	        	if (!Util.isConstant(sub(1)))
	        		break;
	            throw new RuntimeException(Util.symbol(sub(1)));
	        default : {
	        	if (!Util.isConstant(sub(1)))
	        		break;
	        	String mess = format();
	        	if (mess == null)
	        		break;
	        	throw new RuntimeException(mess);
	        }
	    }
	}
	
	/** Helper to build string from $[PRIM, format, args,...] with flattening of args; returns null if any non-constant arguments. */
	String format()
	{
    	String format = Util.symbol(sub(1));
    	List<String> list = new ArrayList<String>();
    	for (int i = 2; i < arity(); ++i)
    	{
    		Term t = sub(i);
    		if (Util.isSequence(t))
    			while (Util.isCons(t.constructor()))
    			{
    				Term s = t.sub(0);
    				if (Util.isConstant(t))
    					list.add(Util.symbol(s));
    				else
    					return null;
    			}
    		else
    		{
				if (Util.isConstant(t))
					list.add(Util.symbol(t));
				else
					return null;
    		}
    	}
    	return String.format(format, list.toArray());
	}
	
//
//	/** Helper class to extract sequence arguments from $[C,...] construct. */
//	static class FlattenedSequence
//	{
//	    /** The subterm binders. */
//	    final Variable[][] binders;
//	    /** The subterms. */
//	    final Term[] terms;
//	    /** Construct flat sequence. */
//	    FlattenedSequence(Term sequence)
//	    {
//	        List<Variable[]> bss = new ArrayList<Variable[]>();
//	        List<Term> ts = new ArrayList<Term>();
//	        if (sequence != null)
//	        {
//	    	    while (true)
//	    	    {
//	    	    	if (Util.isCons(sequence.constructor()))
//	    	        {
//	    	            // Add the head of the sequence and repeat for tail.
//	    	    		List<Variable> subBinders = new ArrayList<Variable>(Arrays.asList(sequence.binders(0)));
//	    	        	Term head = sequence.sub(0);
//	    	        	while (head.kind() == Kind.CONSTRUCTION && head.arity() == 1 && GenericTerm.BIND.equals(Util.symbol(head)))
//	    	        	{
//	    	        		// Consume B x.sub wrappers.
//	    	        		subBinders.addAll(Arrays.asList(head.binders(0)));
//	    	        		head = head.sub(0);
//	    	        	}
//	    	            bss.add(subBinders.toArray(new Variable[subBinders.size()]));
//	    	            ts.add(head);
//	    	            assert sequence.binders(1).length == 0 : "Tail of sequence cannot have binders!";
//	    	            sequence = sequence.sub(1);
//	    	        }
//	    	        else
//	    	        {
//	    	            assert Util.isNull(sequence.constructor()) : "List to be flattened is terminated by non-$Nil?!?";
//	    	            break;
//	    	        }
//	            }
//	        }
//	        binders = bss.toArray(new Variable[bss.size()][]);
//	        terms = ts.toArray(new Term[bss.size()]);
//	    }
//	    /** Arity of sequence. */
//	    int arity()
//	    {
//	    	return terms.length;
//	    }
//	}

	// Term...

    public void visit(Visitor visitor, ExtensibleSet<Variable> bound) throws CRSException
    {
    	Primitive what = primitive();
    	visitor.visitPrimitive(what, true);
    	switch (what)
    	{
    		case CONSTRUCTION :
    		case META_APPLICATION :
    		case VARIABLE :
    			// Match primitives have all special arguments...currently none are classified as "normal"...
    			// TODO: actually parse special arguments, identifying "normal" components.
    			super.visit(visitor, bound);
    			break;
    			
    		case PROPERTY_COLLECT :
    		case PROPERTY_NAMED :
    		case PROPERTY_NAMED_NOT :
    		case PROPERTY_VARIABLE :
    		case PROPERTY_VARIABLE_NOT :
    			// These have two special arguments before normal ones.
    	        visitor.visitConstruction(this, true, bound);
    	        visitor.visitConstructor(constructor(), true, bound);
    	        constructor().visit(visitor, bound);
    	        visitor.visitConstructor(constructor(), false, bound);
    	        // First argument is evaluation directive...
	            visitor.visitConstructionSub(this, 0, true, bound);
	            sub(0).visit(visitor, bound.extend(binders(0)));
	            visitor.visitConstructionSub(this, 0, false, bound);
    	        // Second argument is also special...
	            visitor.visitConstructionSub(this, 1, true, bound);
	            sub(1).visit(visitor, bound.extend(binders(1)));
	            visitor.visitConstructionSub(this, 1, false, bound);
    	        // Rest of arguments are normal.
	            visitor.visitPrimitiveNormal(what, true);
    	        for (int i = 2; i < arity(); ++i)
    	        {
    	            visitor.visitConstructionSub(this, i, true, bound);
    	            sub(i).visit(visitor, bound.extend(binders(i)));
    	            visitor.visitConstructionSub(this, i, false, bound);
    	        }
    	        visitor.visitConstruction(this, false, bound);
	            visitor.visitPrimitiveNormal(what, false);
	            break;
    			
    		default :
    			// Default is process first argument as primitive, rest normally.
    	        visitor.visitConstruction(this, true, bound);
    	        visitor.visitConstructor(constructor(), true, bound);
    	        constructor().visit(visitor, bound);
    	        visitor.visitConstructor(constructor(), false, bound);
    	        // First argument is evaluation directive...
    	        if (arity() > 0)
    	        {
    	        	visitor.visitConstructionSub(this, 0, true, bound);
    	        	sub(0).visit(visitor, bound.extend(binders(0)));
    	        	visitor.visitConstructionSub(this, 0, false, bound);
    	        	// Rest of arguments are normal.
    	        	visitor.visitPrimitiveNormal(what, true);
    	        	for (int i = 1; i < arity(); ++i)
    	        	{
    	        		visitor.visitConstructionSub(this, i, true, bound);
    	        		sub(i).visit(visitor, bound.extend(binders(i)));
    	        		visitor.visitConstructionSub(this, i, false, bound);
    	        	}
    	        }
    	        visitor.visitConstruction(this, false, bound);
	            visitor.visitPrimitiveNormal(what, false);
	            break;
    	}
    	visitor.visitPrimitive(what, false);
    }
	
	// Pattern...

	@Override
	public boolean match(Match match, Term term, ExtensibleSet<Variable> bound, Map<String, Integer> contractionCount, boolean promiscuous, Collection<Variable> once, Collection<Variable> onceSeen)
	{
		Primitive what = primitive();
		switch (what)
		{
			case CONSTRUCTION : {
				// $[C]
				// $[C, #name]
				// $[C[#sort], #name]
				// $[C, #name, #list]
				// $[C, #name, #list]
			    if (term.kind() != Kind.CONSTRUCTION)
                    return false; // wrong kind
			    Constructor c = term.constructor();
			    if (GenericTerm.BIND.equals(c.symbol()) || GenericTerm.BIND_LINEAR.equals(c.symbol()))
			    	return false; // special exception for $B  and $BL to avoid overlaps with binder rules...
			    if (sub(0).arity() == 1)
			    {
			    	// $[C[#sort],...] variants: got a data sort constraint to verify
			    	if (!factory.isData(c.symbol()) && c.literalSort() == null)
			    		return false; // not a data constructor so does not match sort
			    	Pattern sortPattern = (Pattern) sub(0).sub(0);
			    	Term sort = factory.sortOf(c.symbol());
			    	if (sort == null)
			    		sort = factory.constant(factory.makeConstructor(c.literalSort()));
			    	// TODO - what is happening here?!?
			    	if (!sortPattern.match(match, sort, bound, contractionCount, promiscuous, once, onceSeen))
			    		return false;
			    }
			    if (arity() == 1)
			    	return true; // no name and argument constraints
			    if (!matchConstructor(factory, match, (Pattern) sub(1), c, bound, contractionCount, promiscuous, once, onceSeen))
			    	return false;
                
				// Match provided argument patterns...
				if (arity() == 2)
				    return true;
				else
				{
					Term quotedArguments = quoteArguments(factory, term);
					return ((Pattern) sub(2)).match(match, quotedArguments, bound, contractionCount, promiscuous, once, onceSeen);
				}
			}
			
			case VARIABLE : {
                // $[V, #name]
                if (term.kind() != Kind.VARIABLE_USE)
                    return false; // wrong kind
			    if (arity() == 1)
			    	return true; // no name constraint

                // Match the variable name.
                Buffer buffer = new Buffer(factory);
                buffer.sink().start(factory.makeLiteral(term.variable().name(), CRS.STRING_SORT)).end(); // new term with just the variable name
                return ((Pattern) sub(1)).match(match, buffer.term(true), bound, contractionCount, promiscuous, once, onceSeen);
			}

            case META_APPLICATION : {
                // $[M, #name, #list]
                if (term.kind() != Kind.META_APPLICATION)
                    return false; // wrong kind
			    if (arity() == 1)
			    	return true; // no name and argument constraints

			    if (!((Pattern) sub(1)).match(match, factory.literal(term.metaVariable()), bound, contractionCount, promiscuous, once, onceSeen))
			    	return false;
			    
                // Match provided argument patterns...
				if (arity() == 2)
				    return true;
				else
				{
					Term quotedArguments = quoteArguments(factory, term);
					return ((Pattern) sub(2)).match(match, quotedArguments, bound, contractionCount, promiscuous, once, onceSeen);
				}
            }

            case PROPERTIES : {
				// $[P, PROPERTIES_LIST_PATTERN, PATTERN]
				if (!((Pattern) sub(2)).match(match, term, bound, contractionCount, promiscuous, once, onceSeen))
					return false; // contained term does not match
				// PROPERTIES_LIST_PATTERN should match generated list of all actual properties!
				Term termProperties = quoteProperties(term);
				return ((Pattern) sub(1)).match(match, termProperties, bound, contractionCount, promiscuous, once, onceSeen);
			}
			
            case PROPERTY_NAMED :
            case PROPERTY_NAMED_NOT : { 
            	// $[NamedProperty, #name, #value, #rest]
            	// $[NotNamedProperty, #name, #rest]
            	// Get property name to check.
        		Term nameTerm = sub(1);
        		if (nameTerm.kind() == Kind.META_APPLICATION)
        		{
        			Substitute s = match.getSubstitute(nameTerm.metaVariable());
        			if (s == null || s.getBindings().length > 0)
        				throw new RuntimeException("Match error: NamedProperty with non-constant pattern.");
        			nameTerm = s.getBody();
        		}
				if (!Util.isConstant(nameTerm))
        			throw new RuntimeException("Match error: NamedProperty with non-constant name.");
				String name = Util.symbol(nameTerm);
				// Check property constraint.
				PropertiesHolder properties = (term instanceof PropertiesHolder ? (PropertiesHolder) term : term.constructor());
				Pattern restPattern;
				if (what == Primitive.PROPERTY_NAMED)
				{
	            	// $[NamedProperty, #name, #value, #rest]
					if (properties == null)
						return false; // no properties!
					Term value = properties.getProperty(name);
					if (value == null || !((Pattern) sub(2)).match(match, value, bound, contractionCount, promiscuous, once, onceSeen))
						return false; // property value missing or did not match
					restPattern = (Pattern) sub(3); // #term
				}
				else
				{
	                // $[NotNamedProperty, #name, #term]
					if (properties != null)
					{
						Term value = properties.getProperty(name);
						if (value != null)
							return false; // property exists so match fails
					}
					restPattern = (Pattern) sub(2); // #term
	            }
				// Match rest (against same term as prtoperty matching is non-destructive).
				return restPattern.match(match, term, bound, contractionCount, promiscuous, once, onceSeen);
            }

            case PROPERTY_VARIABLE :
            case PROPERTY_VARIABLE_NOT : {
                // $[VariableProperty, variable, #value, #rest]
                // $[NotVariableProperty, #name, #term]
            	// Get variable property to check.
                Term variableTerm = sub(1);
                if (variableTerm.kind() == Kind.META_APPLICATION)
                {
                    Substitute s = match.getSubstitute(variableTerm.metaVariable());
                    if (s == null || s.getBindings().length > 0)
                        throw new RuntimeException("Match error: VariableProperty with non-variable pattern.");
                    variableTerm = s.getBody();
                }
                if (variableTerm.kind() == Kind.VARIABLE_USE)
                	throw new RuntimeException("Match error: VariableProperty with non-variable pattern.");
				Variable variable = variableTerm.variable();
				if (match.renamings().containsKey(variable))
					variable = match.renamings().get(variable);
				// Check property constraint.
				PropertiesHolder properties = (term instanceof PropertiesHolder ? (PropertiesHolder) term : term.constructor());
				Pattern restPattern;
				if (what == Primitive.PROPERTY_VARIABLE)
				{
	                // $[VariableProperty, variable, #value, #rest]
					if (properties == null)
						return false; // no properties!
					Term value = properties.getProperty(variable);
					if (value == null || !((Pattern) sub(2)).match(match, value, bound, contractionCount, promiscuous, once, onceSeen))
						return false; // property value missing or did not match
					restPattern = (Pattern) sub(3); // #term
				}
				else
				{
	                // $[NotVariableProperty, #name, #term]
					if (properties != null)
					{
						Term value = properties.getProperty(variable);
						if (value != null)
							return false; // property exists so match fails
					}
					restPattern = (Pattern) sub(2); // #term
				}
				// Match rest (against same term as prtoperty matching is non-destructive).
				return restPattern.match(match, term, bound, contractionCount, promiscuous, once, onceSeen);
            }
            
            case PROPERTY_COLLECT : {
                // $[CollectsProperties, #metaname, #term]
                if (!Util.isConstant(sub(1))) return false; // "Not constant meta-variable property name?"
                String metavar = Util.symbol(sub(1));
                Term owner = sub(2);
                return ((Pattern) ((GenericTerm) owner).wrapWithPropertiesRef(metavar, false)).match(match, term, bound, contractionCount, promiscuous, once, onceSeen);
            }

			case MATCH : {
			    // $[Match, #p1, #p2]
                assert arity() == 3 : "Match pattern needs two patterns?";
                return ((Pattern) sub(1)).match(match, term, bound, contractionCount, promiscuous, once, onceSeen)
                    && ((Pattern) sub(2)).match(match, term, bound, contractionCount, promiscuous, once, onceSeen); 
			}

            case NOT_MATCH : {
                // $[NotMatch, #not]
                // $[NotMatch, #not, #p]
                if (((Pattern) sub(1)).match(match.clone(), term, bound, contractionCount, promiscuous, once, onceSeen))
                    return false; // #not matched so fail!
                return arity() == 2 || ((Pattern) sub(2)).match(match, term, bound, contractionCount, promiscuous, once, onceSeen); 
            }
            
			case MATCH_REGEX : {
				// $[MatchRegex, Regex, #alias]
				String r = unquote(Util.symbol(sub(1)));
				java.util.regex.Pattern regex = java.util.regex.Pattern.compile(r);
				return Util.isConstant(term)
					&& regex.matcher(Util.symbol(term)).matches()
					&& (arity() == 2 || ((Pattern) sub(2)).match(match, term, bound, contractionCount, promiscuous, once, onceSeen));
			}
			
			case IS_INTEGER : {
				// $[IsInteger, #alias]
				return Util.isConstant(term)
					&& INTEGER_REGEX.matcher(Util.symbol(term)).matches()
					&& (arity() == 1 || ((Pattern) sub(1)).match(match, term, bound, contractionCount, promiscuous, once, onceSeen));
			}

			case VARIABLE_NAME_IS : {
                // $[VariableNameIs, v, #name, #pattern]
                assert arity() == 4 : "VariableNameIs needs v name pattern?";
                
                // The variable in the pattern that we want the name of.
                if (sub(1).kind() != Kind.VARIABLE_USE) return false; // fail when there is no variable in the pattern.
                Variable patternVariable = sub(1).variable();
                
                // The variable in the term that it must already correspond to.
                Variable termVariable = match.getVariable(patternVariable);
                
                // Temporary term with just the real variable name.
                Buffer buffer = new Buffer(factory);
                buffer.sink().start(factory.makeLiteral(termVariable.name(), CRS.STRING_SORT)).end();
                
                // Match the term variable's name against the name pattern and continue with the final pattern as usual.
                return ((Pattern) sub(2)).match(match, buffer.term(true), bound, contractionCount, promiscuous, once, onceSeen)
                        && ((Pattern) sub(3)).match(match, term, bound, contractionCount, promiscuous, once, onceSeen); 
			}

			case PLUS : {
				// $[Plus,#arg,n]
				// $[Plus,n,#arg]
				if (!Util.isConstant(sub(1)) && !Util.isConstant(sub(2))) return false;
				int constantArg = (Util.isConstant(sub(1)) ? 1 : 2);
				if (!INTEGER_REGEX.matcher(Util.symbol(sub(constantArg))).matches()) return false;
				final int n = Integer.parseInt(Util.symbol(sub(constantArg)));
				int metaArg = 3 - constantArg;
				if (!Util.isMetaApplication(sub(metaArg))) return false;
				// Match the redex subterm against #arg.
				if (!((Pattern) sub(metaArg)).match(match, term, bound, contractionCount, promiscuous, once, onceSeen)) return false;
				// Construct wraper substitute that subtracts the number.
				String arg = sub(metaArg).metaVariable();
				final Substitute argSubstitute = match.getSubstitute(arg);
				if (!Util.isConstant(argSubstitute.getBody())) return false; // submatch must be constant
				Substitute minusSubstitute = new Substitute()
				{
					public boolean rematch(Match match, Variable[] binders, Term term)
					{
						return argSubstitute.rematch(match, binders, term); // rematch must use original (to check equality)
					}
					public Copyable substitute(Valuation valuation, Term[] replacement)
					{
						return argSubstitute.substitute(valuation, replacement);
					}
					public Variable[] getBindings()
					{
						return argSubstitute.getBindings();
					}
					public Term getBody()
					{
						int arg = Integer.parseInt(Util.symbol(argSubstitute.getBody()));
						return factory.literal(arg-n); 
					}
                    public void replaceBody(Term replacement)
                    {
                    	throw new RuntimeException("PANIC: bad replacement of $[Plus...].");
                    }
				};
				match.putSubstitute(arg, minusSubstitute);
				return true;
			}

            case IF :
                if (Util.isConstant(sub(1)))
                {
                	if (Util.isTrue(sub(1)))
                		return ((Pattern) sub(2)).match(match, term, bound, contractionCount, promiscuous, once, onceSeen);
                	else if (arity() == 3)
                		return false;
                	else
                		return ((Pattern) sub(3)).match(match, term, bound, contractionCount, promiscuous, once, onceSeen);
                }
                break;
                
            case GET :
            case GET_REF :
                if (Util.isConstant(sub(1)))
                {
                    Term value = Util.materialize(((GenericFactory) factory).get(Util.symbol(sub(1))), false);
                    return ((Pattern) (value != null || arity() == 2 ? value : sub(2))).match(match, term, bound, contractionCount, promiscuous, once, onceSeen);
                }
                return false;

            case CAST :
            	return ((Pattern) sub(1)).match(match, term, bound, contractionCount, promiscuous, once, onceSeen);
            
            case PRINT :
                try
                {
                    sub(1).appendTo(System.out, new HashMap<Variable, String>(), Integer.MAX_VALUE, factory.defined(Factory.SIMPLE_TERMS), true, true, null);
                    System.out.println();
                    System.out.flush();
                }
                catch (IOException e)
                {
                    throw new UnsupportedOperationException(e);
                }
                return (arity() == 2 ? false : ((Pattern) sub(2)).match(match, term, bound, contractionCount, promiscuous, once, onceSeen));

            case DUMP :
                try
                {
                    if (sub(2).kind() != Kind.META_APPLICATION || binders(2).length != 0)
                        throw new UnsupportedOperationException(toString());
                    boolean full = factory.defined(Factory.SIMPLE_TERMS);
                    Map<Variable, String> used = new HashMap<Variable, String>();
                    sub(1).appendTo(System.out, used, Integer.MAX_VALUE, full, true, true, null);
                    System.out.print(" ");
                    if (((Pattern) sub(2)).match(match, term, bound, contractionCount, promiscuous, once, onceSeen))
                    {
                        match.getSubstitute(sub(2).metaVariable()).getBody().appendTo(System.out, used, Integer.MAX_VALUE, full, true, true, null);
                        sub(2).appendTo(System.out, used, Integer.MAX_VALUE, full, true, true, null);
                        System.out.println();
                        System.out.flush();
                        return true;
                    }
                    else
                    {
                        System.out.println("#FAIL");
                        System.out.flush();
                        return false;
                    }
                }
                catch (IOException e)
                {
                    throw new UnsupportedOperationException(e);
                }
                
            case TRACE :
                try
                {
                    sub(1).appendTo(System.err, new HashMap<Variable, String>(), Integer.MAX_VALUE, factory.defined(Factory.SIMPLE_TERMS), true, true, null);
                    System.err.println();
                    System.err.flush();
                }
                catch (IOException e)
                {
                    throw new UnsupportedOperationException(e);
                }
                return (arity() == 2 ? false : ((Pattern) sub(2)).match(match, term, bound, contractionCount, promiscuous, once, onceSeen));

			case ERROR :
				error();
				break;
		}
		// Fall back to plain literate matching.
		return super.match(match, term, bound, contractionCount, promiscuous, once, onceSeen);
	}
	
	private static boolean matchConstructor(GenericFactory factory, Match match, Pattern pattern, Constructor constructor, ExtensibleSet<Variable> bound, Map<String, Integer> contractionCount, boolean promiscuous, Collection<Variable> once, Collection<Variable> onceSeen)
	{
		// TODO: Check special "property reification pattern"
	    Buffer buffer = new Buffer(factory);
	    buffer.sink().start(constructor).end(); // new term with just the constructor
	    return pattern.match(match, buffer.term(true), bound, contractionCount, promiscuous, once, onceSeen);
	}

	/**
	 * 
	 * Interprets list of arguments in quoted form: ( $B x1 y1 z1 . sub1; ....; $BL xn . subn; ).
	 * Note that the variables and subterms are shared with the original!
	 * @param factory for term creation
	 * @param symbol of construction
	 * @param sort for construction (usually null but should be a primitive sort name for literal creation)
	 * @param quotedArguments subterms with quoted binders...the actual subterms and variables are shared between this and the returned form
	 * @param renamings to apply to subterms
	 */
	private Term unquoteConstructionAndArguments(GenericFactory factory, String symbol, String sort, Term quotedArguments, ExtensibleMap<Variable,Variable> renamings)
	{
		//assert Util.isSequence(quotedArguments);
		List<GenericTerm> subs = new ArrayList<GenericTerm>();
		List<Variable[]> binders= new ArrayList<Variable[]>();
		Term rest = quotedArguments;
		while (Util.isCons(rest.constructor()))
		{
			List<Variable> bs = new ArrayList<Variable>();
			// HACK: include existing old style binders...
			for (int j = 0; j < rest.binders(0).length; ++j)
				bs.add(rest.binders(0)[j]);
			GenericTerm a = (GenericTerm) rest.sub(0);
			while (a.kind() == Kind.CONSTRUCTION && (GenericTerm.BIND.equals(Util.symbol(a)) || GenericTerm.BIND_LINEAR.equals(Util.symbol(a))))
			{
				assert a.arity() == 1 && a.binders(0).length == 1;
				Variable b = a.binders(0)[0];
				bs.add(renamings.containsKey(b) ? renamings.get(b) : b);
				a = a.sub(0);
			}
			binders.add(bs.toArray(new Variable[0]));
			GenericTerm ac = compute(a, null);
			subs.add((GenericTerm) (ac != null ? ac : a).copy(true, renamings));
			rest = rest.sub(1);
		}
		return factory.newConstruction((Util.isLiteralSort(sort) ? factory.makeLiteral(symbol, sort) : factory.makeConstructor(symbol)), binders.toArray(new Variable[0][]), subs.toArray(new GenericTerm[0]));
	}
	
	/**
	 * Return list of the subterms of parent in quoted form: ( $B x1 y1 z1 . sub1; ....; $B xn . subn; ).
	 * Note that the variables and subterms are shared with the original!
	 * @param factory for term creation
	 * @param parent term to quote...subterms and variables are shared between this and the returned form
	 */
	private static Term quoteArguments(GenericFactory factory, Term parent)
	{
		GenericTerm quoted = factory.nil();
		for (int i = parent.arity()-1; i >= 0; --i)
		{
			GenericTerm sub = (GenericTerm) parent.sub(i);
			Variable[] binds = parent.binders(i);
			for (int j = binds.length-1; j >= 0; --j)
			{
				Variable[][] bs = new Variable[1][];
				bs[0] = new Variable[1];
				bs[0][0] = binds[j];
				GenericTerm[] ts = new GenericTerm[1];
				ts[0] = sub;
				sub = factory.newConstruction(factory.makeConstructor(binds[j].promiscuous() ? GenericTerm.BIND : GenericTerm.BIND_LINEAR), bs, ts);
			}
			quoted = factory.cons(GenericTerm.NO_BIND, sub, GenericTerm.NO_BIND, quoted);
		}
		return quoted;
	}

	/**
	 * Construct properties from list in {@link Primitive#PROPERTIES} format.
	 * @param factory for construction?
	 * @param props list of property units
	 * @param term to wrap the properties around
	 * @return
	 */
	private static Term unquoteProperties(Factory<? extends Term> factory, Term props, Term term)
	{
		assert(false);
		return null;
	}
	
	/**
	 * Explicit properties in the format used by {@link Primitive#PROPERTIES}.
	 * @param term with properties
	 * @return list of just the quoted properties
	 */
	private static Term quoteProperties(Term term)
	{
		PropertiesHolder ps = (term instanceof PropertiesHolder ? (PropertiesHolder) term : term.constructor());
		Buffer buffer = new Buffer(term.maker());
		Sink sink = buffer.sink(); 
		int conses = 0;
		//
		if (ps != null)
		{
			String ref = null;
			Map<String,Term> namedProps;
			Map<Variable,Term> variableProps;
			Map<String,Term> metaProps;
			if (ps instanceof PropertiesConstraintsWrapper)
			{
				PropertiesConstraintsWrapper pcw = (PropertiesConstraintsWrapper) ps;
				ref = pcw.propertiesRef;
				namedProps = pcw.namedPropertyConstraints;
				variableProps = pcw.variablePropertyConstraints;
				metaProps = pcw.metaPropertyConstraints;
			}
			else
			{
				namedProps = new HashMap<String, Term>();
				for (String name : ps.propertyNames())
					namedProps.put(name, ps.getProperty(name));
				variableProps = new HashMap<Variable, Term>();
				for (Variable variable : ps.propertyVariables())
					variableProps.put(variable, ps.getProperty(variable));
				metaProps = new HashMap<String,Term>();
			}
			// Now generate list.
			if (ref != null)
			{
				sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL));
				++conses;
				sink = sink.start(sink.makeConstructor("$RP")).startMetaApplication(ref).endMetaApplication().end();
			}
			for (Map.Entry<String,Term> e : namedProps.entrySet())
			{
				sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL));
				++conses;
				sink = sink.start(sink.makeConstructor("$NP")).start(sink.makeLiteral(e.getKey(), CRS.STRING_SORT)).end().copy(e.getValue(), false).end();
			}
			for (Map.Entry<Variable,Term> e : variableProps.entrySet())
			{
				sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL));
				++conses;
				sink = sink.start(sink.makeConstructor("$VP")).use(e.getKey()).copy(e.getValue(), false).end();
			}
			for (Map.Entry<String, Term> e : metaProps.entrySet())
			{
				sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL));
				++conses;
				sink = sink.start(sink.makeConstructor("$MP")).startMetaApplication(e.getKey()).endMetaApplication().copy(e.getValue(), false).end();
			}
			// List done.
		}
		sink =  sink.start(sink.makeConstructor(CRS.NIL_SYMBOL)).end();
		while (conses-- > 0) sink = sink.end();
		return buffer.term(true);	
	}

//	private static boolean match_quoted(GenericFactory factory, ExtensibleMap<String, Variable> constantVariables, Match match, Term quoted, Term term, ExtensibleSet<Variable> bound, Map<String, Integer> contractionCount, boolean promiscuous, Collection<Variable> once, Collection<Variable> onceSeen)
//	{
//		assert quoted.kind() == Kind.CONSTRUCTION : "Quoting $[Q,...] only accepts constructors!";
//		String tag = Util.symbol(quoted);
//		if ("C".equals(tag))
//		{
//			// C[constructor] or C[constructor, arguments]
//		    assert quoted.arity() > 0 && quoted.binders(0).length == 0 : "$[Q] bad C[]";
//		    if (term.kind() != Kind.CONSTRUCTION)
//                return false; // wrong kind
//		    if (!match_q_constructor(factory, match, (Pattern) quoted.sub(0), term.constructor(), bound, contractionCount, promiscuous, once, onceSeen))
//		    	return false;
//			switch (quoted.arity())
//			{
//				case 1 :
//					return true;
//				case 2 :
//					// Match provided argument patterns...
//				    assert quoted.binders(1).length == 0 : "$[Q] bad C[constructor, arguments]";
//					return match_q_arguments(factory, match, (Pattern) quoted.sub(1), term, bound, contractionCount, promiscuous, once, onceSeen);
//				default :
//					assert false : "$[Q] bad C[]";
//					return false;
//			}
//		}
//		if ("V".equals(tag))
//		{
//			// V[variable] or V[string]
//		    assert quoted.arity() == 1 && quoted.binders(0).length == 0 : "$[Q] bad V[]";
//		    if (term.kind() != Kind.VARIABLE_USE)
//                return false; // wrong kind
//			return ((Pattern) quoted.sub(0)).match(match, term, bound, contractionCount, promiscuous, once, onceSeen);
//		}
//		if ("M".equals(tag))
//		{
//			// M[string, arguments] matches ACTUAL 
//		    assert quoted.arity() == 2 && quoted.binders(0).length == 0  && quoted.binders(1).length == 0: "$[Q] bad M[]";
//		    if (term.kind() != Kind.META_APPLICATION)
//                return false; // wrong kind
//			if (!matchMetaVariable(factory, match, (Pattern) quoted.sub(0), term.metaVariable(), bound, contractionCount, promiscuous, once, onceSeen))
//				return false;
//			return match_q_arguments(factory, match, (Pattern) quoted.sub(1), term, bound, contractionCount, promiscuous, once, onceSeen);
//		}
//		if ("T".equals(tag))
//		{
//			// T[term] matches as if term was the pattern
//			assert quoted.arity() == 1 && quoted.binders(0).length == 0 : "$[Q] bad T[term]";
//			return ((Pattern) quoted.sub(0)).match(match, term, bound, contractionCount, promiscuous, once, onceSeen);
//		}
//		assert false : "$[Q] bad form";
//		return false;
//	}
//
//	private static boolean match_q_constructor(GenericFactory factory, Match match, Pattern constructor, Constructor c, ExtensibleSet<Variable> bound, Map<String, Integer> contractionCount, boolean promiscuous, Collection<Variable> once, Collection<Variable> onceSeen)
//	{
//		return false;
//	}
//
//	private static boolean match_q_arguments(GenericFactory factory, Match match, Pattern rest, Term term, ExtensibleSet<Variable> bound, Map<String, Integer> contractionCount, boolean promiscuous, Collection<Variable> once, Collection<Variable> onceSeen)
//	{
//        // Match provided argument patterns...
//        // - (a1 ;...; an;) matches x[a1,...,an].
//        // - (a1 ;...; an; A) matches x[a1,...,an,...].
//        final int arity = term.arity();
//        int index = 0;
//        while (rest.kind() == Kind.CONSTRUCTION && rest.arity() == 2 && Util.isCons(rest.constructor()))
//        {
//            if (index >= arity)
//                return false; // too many arguments!
//            
//            if (rest.binders(0).length != term.binders(index).length)
//                return false; // binder mismatch for index'th subterm
//            
//            if (!((Pattern) rest.sub(0)).match(match, term.sub(index), bound, contractionCount, promiscuous, once, onceSeen))
//                return false; // index'th subterm does not match
//            rest = (Pattern) rest.sub(1);
//            ++index;
//        }
//        if (rest.kind() == Kind.CONSTRUCTION && rest.arity() == 0 && Util.isNull(rest.constructor()))
//        {
//            return index == arity; // succeed only when argument list was exactly right length
//        }
//        else
//        {
//            // Construct sequence of remaining actual arguments to match against...
//            Term tail = factory.constant(factory.nilConstructor);
//            final Variable[] nobind = {};
//            for (int i = arity-1; i >= index; --i)
//                tail = factory.cons(term.binders(i), term.sub(i), nobind, tail);
//            // ...and do it!
//            return ((Pattern) rest).match(match, tail, bound, contractionCount, promiscuous, once, onceSeen);
//        }
//	}

	// Contractum.
	
	@Override
	public Sink contract(Sink sink, Valuation valuation, ExtensibleMap<Variable,Variable> renamings)
	{
		//System.out.printf("=========\nCONTRACTING "+this +" WITH " +valuation+"\n");
		
		// Build copy that can be destructively updated.
		final int arity = arity();
		GenericEvaluator work;
		{
			// Recreate evaluator term. Reuse binders as we'll be contracting later anyway.
			Variable[][] cbinders = new Variable[arity][];
			GenericTerm[] csub = new GenericTerm[arity];
			cbinders[0] = binders(0);
			csub[0] = (GenericTerm) Buffer.contraction(((Contractum) sub(0)), valuation, renamings);
			for (int i = 1; i < arity; ++i)
			{
				cbinders[i] = binders(i);
				csub[i] = (GenericTerm) Buffer.contraction(sub(i), valuation, renamings);
			}
			work = new GenericEvaluator(factory, constructor(), cbinders, csub, (GenericValuation) valuation, renamings);
		}
		Term computed = work.compute(null);
		if (computed != null)
		{
			if (computed instanceof GenericEvaluator)
			{
				GenericTerm c = ((GenericEvaluator) computed).compute(null); // tail evaluation...
				if (c != null)
					computed = c;
			}
			//System.out.printf("SUCCESS "+computed+"\n=========\n");
			return computed.copy(sink, false, renamings);
		}
		// Evaluator failed. Backtrack...
		for (int i = 1; i < work.arity(); ++i)
			work.computeArguments();
		//System.out.printf("FAIL "+work+"\n=========\n");
		return work.copy(sink, true, renamings);
	}

	@Override
	public GenericTerm makeUnificationCopy(StackedMap<Variable> varrenamings, Map<String, String> mvarrenamings)
	{
		ExtensibleMap<Variable, Variable> renamings = new LinkedExtensibleMap<Variable, Variable>();

		final Constructor c = constructor().copy(renamings.extend(varrenamings));
        
        final int a = arity();
        final Variable[][] bss = new Variable[a][];
        final GenericTerm[] ss = new GenericTerm[a];
        for (int i = 0; i < a; ++i)
        {
            final Variable[] bs = new Variable[binders(i).length];
            varrenamings.pushscope();
            for (int j = 0; j < bs.length; ++j)
            {
                Variable v = binders(i)[j];
                bs[j] = v;
                varrenamings.put(v, v);
            }
            bss[i] = bs;
            ss[i] = ((GenericTerm) sub(i)).makeUnificationCopy(varrenamings, mvarrenamings);
            varrenamings.popscope();
        }
        
        return new GenericEvaluator(factory, c, bss, ss);
	}

	@Override
	protected Unification unifyThese(Unification unification, Pattern that,
			StackedMap<Variable> rho, StackedMap<Variable> rhoprime,
			Set<String> existingMVars) throws CRSException {
		Primitive what = primitive();

		switch (what){
		case CONSTRUCTION:{
			//This is a $[C, #c, #args] pattern
			assert this.arity() == 3 : "$[C...] pattern of arity != 3.";
			assert this.sub[1] instanceof GenericMetaApplication &&
			       this.sub[2] instanceof GenericMetaApplication: "$[C...] pattern with non-metavariable child";
			       
			switch(that.kind()){
			case CONSTRUCTION:{
				if (that instanceof GenericEvaluator){
					Primitive thatwhat = ((GenericEvaluator)that).primitive();
					switch (thatwhat){
					case CONSTRUCTION:{
						assert false : "$[C...] pattern being unified with $[C...] pattern - duplicate rule?";
					}
					case NOT_MATCH:{
						//This pattern matches any construction, and hence matches whatever must not be matched
						//by a NotMatch pattern. Unification fails.
						return null;
					}
					default:{
						assert false : "Unknown evaluator pattern type in unification";
					}
					}
				}

				//that pattern not an evaluator, so it must be on the form F[...]. Unification succeeds
				//Add substitutes for #c and #args, and return
				unification.putSubstitute(((GenericMetaApplication)this.sub(1)).metaVariable, 
									      new Variable[0],
									      factory.newConstruction(that.constructor(), GenericTerm.NO_BINDS, GenericTerm.NO_TERMS));

				
				// Construct sequence of actual arguments
                GenericTerm tail = factory.nil();
                final Variable[] nobind = {};
                for (int i = that.arity()-1; i >= 0; --i){
                    tail = factory.cons(that.binders(i), (GenericTerm) that.sub(i), nobind, tail);
                }
                //Add substitute to unfication, and return
                unification.putSubstitute(((GenericMetaApplication)this.sub(2)).metaVariable, 
                						  new Variable[0], 
                						  tail);
                return unification;
                
			}
			case VARIABLE_USE:
			case META_APPLICATION: {
				//Unification fails
				return null;
			}
			default: {
				assert false : "Unknown pattern type being unified with $ rule";
				return null;
			}
			}
			
		}
		case NOT_MATCH:{
			//Pattern is $[NotMatch, notp, p], where p can be anoter NotMatch pattern
			assert this.arity() == 3 : "$[NotMatch...] pattern of arity != 3.";

			if (that instanceof GenericEvaluator){
				//Evaluator pattern. Distinguish between Construction or NotMatch
				Primitive thatwhat = ((GenericEvaluator)that).primitive();
				switch (thatwhat){

				case CONSTRUCTION:{
					//that pattern automatically matches pattern such that this pattern rejects.
					//Unification fails.
					return null;
				}
				case NOT_MATCH:{
					//NotMatch against NotMatch
					//TODO: Unimplemented - not at all easy!!
					return null;
				}
				default:{
					throw new CRSException ("Attempt to unify $[NotMatch, ...] pattern against unknown $ pattern");
				}
				}
			}
			else {
				//Normal pattern

				//TODO: This should be more sophisticated
				//TODO: This is buggy. Equals has to take existing renamings into account.
				if (this.sub(1).equals(that)){
					//Patterns identical, so overall unification failed
					return null;
				}
				
				//Not equal to illegal pattern. Unify with legal pattern and return result
				return ((GenericTerm)this.sub(2)).unifyThese(unification, that, rho, rhoprime, existingMVars);
			}
		}
		default:{
			throw new CRSException("Unknown $ pattern encountered in unification: " + this);
		}
		}
	}

	@Override
	public GenericTerm applySubstitutes(Unification unification)
	{
		// TODO Auto-generated method stub
		//TODO Use this.compute.
		return super.applySubstitutes(unification);
	}

    @Override
    public Sink reify(Sink sink, Map<String, Term> metaArgSort, Map<Variable, Term> freeSort, Map<String, Reifier> subReifiers)
    {
    	sink = sink.start(sink.makeConstructor(CRS.REIFY_EVALUATOR)); // EVALUATOR[
    	sink = sink.start(sink.makeLiteral(Util.symbol(sub(0)), CRS.STRING_SORT)).end(); // symbol as literal
    	switch (primitive())
    	{
    		case FREE_VARIABLES :
    			// Update sort name to canonical sort name!
    			if (sub(0).arity() > 0)
    			{
    				String argumentSort = Util.symbol(sub(0).sub(0));
    				if (factory.sortAliases.containsKey(argumentSort))
    				{
    					String realSort = factory.sortAliases.get(argumentSort);
    					sub(0).replaceSub(0, sub(0).binders(0), factory.newConstruction(factory.makeConstructor(realSort), GenericTerm.NO_BINDS, GenericTerm.NO_TERMS));
    				}
    			}
    		default:
    	}
    	for (int i = 0; i < arity(); ++i)
    	{
			sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL)); // CONS[
			sink = sub(i).reify(sink, metaArgSort, freeSort, subReifiers);			
    	}
		sink = sink.start(sink.makeConstructor(CRS.NIL_SYMBOL)).end(); // ()
    	for (int i = 0; i < arity(); ++i)
    	{
			sink = sink.end(); // ] of CONS
    	}
    	// Options
    	for (int i = 0; i < arity(); ++i)
    	{
			sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL)); // CONS[
			
			if (options != null && options[i] != null && options[i].size() > 0)
			{
				switch (primitive())
				{
					case IF:
					case IF_DEF:
					case IF_EMPTY:
					case IF_ZERO:
						for (int j = options[i].size() - 1; j >= 0; j--)
						{
							sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL)); // CONS[
							sink = sink.start(sink.makeConstructor(CRS.REIFY_RULE_OPTION)).start(sink.makeLiteral(Builder.DISCARD_OPTION_SYMBOL, CRS.STRING_SORT)).end(); // OPTION["Discard"
							sink = sink.start(sink.makeConstructor(CRS.REIFY_META_APPLICATION)).start(sink.makeLiteral(options[i].get(j), CRS.STRING_SORT)).end(); // META-APPLICATION["Name"
							sink = sink.start(sink.makeConstructor(CRS.NIL_SYMBOL)).end().start(sink.makeConstructor(CRS.REIFY_NA)).end(); // (), NA
							sink = sink.end().end(); // ]] for META and OPTION
						}
						sink = sink.start(sink.makeConstructor(CRS.NIL_SYMBOL)).end(); // ()
						for (int j = options[i].size() - 1; j >= 0; j--)
							sink = sink.end(); // ] of CONS
						break;
					default:						
				}
		    			
			}
			else
			{
				sink = sink.start(sink.makeConstructor(CRS.NIL_SYMBOL)).end();	// Empty list
			}
    	}
    	sink = sink.start(sink.makeConstructor(CRS.NIL_SYMBOL)).end(); // ()
    	for (int i = 0; i < arity(); ++i)
    	{
			sink = sink.end(); // ] of CONS
    	}
    	sink = sink.end(); // ] of EVALUATOR
    	return sink;
    }
    
    final public void analyzeMetaUseContractum(Map<String, Integer> uses, Map<String, MetaAnalyzer> subAnalyzers)
	{
    	switch (primitive())
		{
    		case IF:
    		case IF_DEF:
    		case IF_EMPTY:
    		case IF_ZERO:
    			{
    				Map<String, Integer> falseUses = null;
    				if (arity() == 4)
    				{
    					falseUses = new HashMap<String, Integer>();
    					falseUses.putAll(uses);
    					sub(3).analyzeMetaUseContractum(falseUses, subAnalyzers);
    					
    					this.options = new ArrayList[arity()];
    					this.options[2] = new ArrayList<Object>(); // True branch
    					this.options[3] = new ArrayList<Object>(); // False branch
        				
    				}
    				Map<String, Integer> trueUses = new HashMap<String, Integer>();
    				trueUses.putAll(uses);
					sub(2).analyzeMetaUseContractum(trueUses, subAnalyzers);
					
					if (falseUses != null)
					{
						HashMap<String, Integer> newFalseUses = new HashMap<String, Integer>();
						newFalseUses.putAll(falseUses);
						removeAll(newFalseUses, uses);
						
						HashMap<String, Integer> newTrueUses = new HashMap<String, Integer>();
						newTrueUses.putAll(trueUses);
						removeAll(newFalseUses, uses);
						
						// The new entries in each branch correspond to a last use (USE[1] is somewhere in the branch)
						// Each missing entry in the other branch correspond to a discarded meta var
						for (String key: newFalseUses.keySet())
						{
							if (!newTrueUses.containsKey(key))
							{
								this.options[2].add(key);
							}
							uses.put(key, newFalseUses.get(key));
						}
						for (String key: newTrueUses.keySet())
						{
							if (!newTrueUses.containsKey(key))
							{
								this.options[3].add(key);
							}
							uses.put(key, newTrueUses.get(key)); // It's fine to override.
						}
						
						// We could aggregate existings uses but it's not stricty needed
					}
					else
					{
						uses.putAll(trueUses);
					}
					
					// Test
					sub(1).analyzeMetaUseContractum(uses, subAnalyzers);					
    				break;
    			}
    		default:
    			for (int i = arity() -1; i >= 1; --i)
    				sub(i).analyzeMetaUseContractum(uses, subAnalyzers);    				
		}			
	}
    
    final public static void removeAll(Map<String, Integer> map1, Map<String, Integer> map2)
    {
    	for (String key : map2.keySet())
    		map1.remove(key);
    }
}
