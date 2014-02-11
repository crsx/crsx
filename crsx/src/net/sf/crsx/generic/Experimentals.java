/* Copyright (c) 2009 IBM Corporation. */

package net.sf.crsx.generic;

import java.util.Arrays;
import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

import net.sf.crsx.Builder;
import net.sf.crsx.CRS;
import net.sf.crsx.CRSException;
import net.sf.crsx.Constructor;
import net.sf.crsx.Pattern;
import net.sf.crsx.Primitive;
import net.sf.crsx.PropertiesHolder;
import net.sf.crsx.Sink;
import net.sf.crsx.Term;
import net.sf.crsx.Variable;
import net.sf.crsx.util.LinkedExtensibleMap;
import net.sf.crsx.util.SmallMapWithDefault;

/**
 * Various experimental code for the generic CRS and terms.
 * @author krisrose
 */
class Experimentals
{
	/**
	 * Walks through the provided rules and generates term with dispatch rules for potential dispatch arguments.
	 *
	 * @param sink to send dispatch rule sequence
	 * @param rulesByFunction the rules to find dispatch cases in
	 * @return sink that has received the dispatch rules
	 * @throws CRSException
	 */
	public static Sink dispatchRules(Sink sink, Map<Constructor, Collection<GenericRule>> rulesByFunction) throws CRSException
	{
		int conses = 0; // count the number of emitted $Cons[... starters.

		FunctionLoop :
		for (Map.Entry<Constructor, Collection<GenericRule>> rulesEntry : rulesByFunction.entrySet())
		{
			Constructor function = rulesEntry.getKey();
			Collection<GenericRule> functionRules = rulesEntry.getValue();
			assert !functionRules.isEmpty() : "Seems to have lost the rules for "+function+"?";
			if (functionRules.size() == 1) continue; // no dispatch for singleton rules...
			
			int arity = functionRules.iterator().next().getPattern().arity();
			if (arity == 0) continue; // no dispatch needed when there are no arguments...

			// State for each parameter: 1 means constructors seen, 2 that one variable case was seen,
			// 4 that more variable cases were seen, and 8 that metavariable cases were seen.
			int parameterState[] = new int[arity]; Arrays.fill(parameterState, 0, arity, 0);
			// State for each property (variables, constants, and meta-variables): 1 for seen, 2 for seen more than once, 4 for negation;
			// furthermore for variables and meta-variables the argument holding the variable is stored <<3
			Map<String, Integer> namedPropertyState = new SmallMapWithDefault<String, Integer>(0);
			Map<Variable, Integer> variablePropertyState = new SmallMapWithDefault<Variable, Integer>(0);
			Map<String, Integer> metaPropertyState = new SmallMapWithDefault<String, Integer>(0);
			//
			for (GenericRule rule : functionRules)
			{
				Pattern pattern = rule.getPattern();
				if (pattern.arity() != arity)
					throw new CRSException("Inconsistent arity for rule "+rule.name()+"'s pattern "+pattern);
				// Update parameter state.
				for (int i = 0; i < arity; ++i)
				{
					switch (pattern.sub(i).kind())
					{
						case CONSTRUCTION :
							parameterState[i] |= 1;
							break;
						case VARIABLE_USE :
							parameterState[i] |= ((parameterState[i]&2)==0 ? 2 : 4);
							break;
						case META_APPLICATION :
							parameterState[i] |= 8;
							break;
					}
				}
				// Update property state, if appropriate...
				Map<String, Term> namedPropertyConstraints;
				Map<Variable, Term> variablePropertyConstraints;
				Map<String, Term> metaPropertyConstraints;
				if (pattern instanceof PropertiesConstraintsWrapper) // that's a hack!
				{
					PropertiesConstraintsWrapper properties = (PropertiesConstraintsWrapper) pattern;
					namedPropertyConstraints = properties.namedPropertyConstraints;
					variablePropertyConstraints = properties.variablePropertyConstraints;
					metaPropertyConstraints = properties.metaPropertyConstraints;
				}
				else if (pattern.constructor() instanceof PropertiesHolder)
				{
					PropertiesHolder properties = (PropertiesHolder) pattern.constructor();
					namedPropertyConstraints = new HashMap<String, Term>();
					for (String name : properties.propertyNames()) namedPropertyConstraints.put(name, properties.getProperty(name));
					variablePropertyConstraints = new HashMap<Variable, Term>();
					for (Variable variable : properties.propertyVariables()) variablePropertyConstraints.put(variable, properties.getProperty(variable));
					metaPropertyConstraints = new HashMap<String, Term>(); // ain't none
				}
				else
				{
					namedPropertyConstraints = LinkedExtensibleMap.EMPTY_NAMED_PROPERTIES;
					variablePropertyConstraints = LinkedExtensibleMap.EMPTY_VARIABLE_PROPERTIES;
					metaPropertyConstraints = new HashMap<String, Term>();
				}
				for (Map.Entry<String, Term> entry : namedPropertyConstraints.entrySet())
				{
					String name = entry.getKey();
					Term value = entry.getValue();
					int oldState = namedPropertyState.get(name);
					if (value == null)
						namedPropertyState.put(name, oldState | 4); // ¬name
					else if ((oldState & 1) == 0)
						namedPropertyState.put(name, oldState | 1); // name, first time
					else
						namedPropertyState.put(name, oldState | 2); // name, second time (so value must be matched)
				}
				for (Map.Entry<Variable, Term> entry : variablePropertyConstraints.entrySet())
				{
					Variable variable = entry.getKey();
					Term value = entry.getValue();
					int oldState = variablePropertyState.get(variable);
					int newState;
					if (value == null)
						newState = oldState | 4; // ¬variable
					else if ((oldState & 1) == 0)
						newState = oldState | 1; // variable, first time
					else
						newState = oldState | 2; // variable, second time (so value must be matched)
					for (int i = 0; i < arity; ++i)
						if (variable.equals(pattern.sub(i).variable()))
							newState = newState | (i<<3);
					variablePropertyState.put(variable, newState);
				}
				for (Map.Entry<String, Term> p : metaPropertyConstraints.entrySet())
				{
					String metaVariable = p.getKey();
					Term value = p.getValue();
					int oldState = metaPropertyState.get(metaVariable);
					int newState;
					if (value == null)
						newState = oldState | 4; // ¬#metaVariable
					else if ((oldState & 1) == 0)
						newState = oldState | 1; // #metaVariable, first time
					else
						newState = oldState | 2; // #metaVariable, second time (so value must be matched...TODO)
					for (int i = 0; i < arity; ++i)
						if (metaVariable.equals(pattern.sub(i).metaVariable()))
							newState = newState | (i<<3);
					metaPropertyState.put(metaVariable, newState);
				}
			}
			
			// Generate any parameter dispatch rule.
			for (int i = 0; i < arity; ++i)
			{
				switch (parameterState[i])
				{
					case 1 : // only constructors - OK
					case 3 : // constructors and a single variable case - OK
					case 7 : // constructors and multiple variable cases - OK
						// Generate dispatch rule term.
						// $Cons[
						sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL)); 
						++conses;
						//  $Rule[
						sink = sink.start(sink.makeConstructor(Builder.RULE_SYMBOL));
						//   function,
						sink = sink.start(sink.makeConstructor(function.symbol())).end();
						//   {#props}function[ #1,...,#j-1, $[C,#c,#as], #j+1,...,#arity ],
						sink = PropertiesWrapperConstructor.start(sink, "#env", null, null, null) // {#props}
								.start(function); // function[
						for (int j = 0; j < arity; ++j)
						{
							sink = (j != i
									? sink.startMetaApplication("#"+(j+1)).endMetaApplication() // either #j or...
									: sink.start(sink.makeConstructor(CRS.EVAL_SYMBOL)) // $[
										.start(sink.makeConstructor(Primitive.CONSTRUCTION)).end() // C,
										.startMetaApplication("#c").endMetaApplication() // #c,
										.startMetaApplication("#as").endMetaApplication() // #as
										.end()) ; // ]
						}
						sink = sink.end(); // ]
						sink = sink.end(); // for {props} wrapper
						//   {#props}$[C, $[:,'function-',#c], $Cons[#1, ..., $Cons[#j-1, $Cons[#j+1, ..., $Cons[#arity, #as]...]]...]]
						sink = PropertiesWrapperConstructor.start(sink, "#env", null, null, null) // {props}
								.start(sink.makeConstructor(CRS.EVAL_SYMBOL)).start(sink.makeConstructor(Primitive.CONSTRUCTION)).end() // $[C,
								.start(sink.makeConstructor(CRS.EVAL_SYMBOL)).start(sink.makeConstructor(Primitive.CONCATENATION)).end() // $[:,
								.start(sink.makeConstructor(function.symbol()+"-")).end().startMetaApplication("#c").endMetaApplication().end(); // #c,"-function"],
						for (int j = 0; j < arity; ++j)
							if (i != j)
								sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL)).startMetaApplication("#"+(j+1)).endMetaApplication(); // $Cons[#j,   (except for i=j)
						sink = sink.startMetaApplication("#as").endMetaApplication(); // #as
						for (int j = 0; j < arity; ++j)
							if (i != j) 
								sink = sink.end(); // ]  (of $Cons for j)
						sink = sink.end() // ]  (of $)
								.end(); // for {props} wrapper
						//  ] (of $Rule)
						sink = sink.end();
						continue  FunctionLoop; // only one dispatch rule per function
				}
			}

			// Named property dispatch rules.
			for (Map.Entry<String, Integer> e : namedPropertyState.entrySet())
			{
				String name = e.getKey();
				int state = e.getValue();
				switch (state & 7)
				{
					case 5 : // ¬name and name 
						// Generate rule:
						// $Cons[
						sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL)); 
						++conses;
						//  $Rule[
						sink = sink.start(sink.makeConstructor(Builder.RULE_SYMBOL));
						//  function-named-property-name
						sink = sink.start(sink.makeConstructor(function+"-named-property-"+name)).end();
						//    {#env}function[#1,...,#j]
						sink = PropertiesWrapperConstructor.start(sink, "#env", null, null, null) // {#env}
								.start(function); // function[
						for (int j = 0; j < arity; ++j)
							sink = sink.startMetaApplication("#"+(j+1)); // #j
						sink = sink.end() // ]
								.end(); // end of {#env}
						//    {#env}$[C,$[:,'function-',{#env}$[IfDef,name,'-','-no-'],name], (#1;...#j;)]
						sink = PropertiesWrapperConstructor.start(sink, "#env", null, null, null) // {#env}
								.start(sink.makeConstructor(CRS.EVAL_SYMBOL)).start(sink.makeConstructor(Primitive.CONSTRUCTION)).end() // $[C,
								.start(sink.makeConstructor(CRS.EVAL_SYMBOL)).start(sink.makeConstructor(Primitive.CONCATENATION)).end() // $[:,
								.start(sink.makeConstructor(function.symbol()+"-")).end(); // 'function-'
						sink = PropertiesWrapperConstructor.start(sink, "#env", null, null, null) // {#env}
								.start(sink.makeConstructor(CRS.EVAL_SYMBOL)).start(sink.makeConstructor(Primitive.IF_DEF)).end() // $[IfDef,
								.start(sink.makeConstructor(name)).end().start(sink.makeConstructor("-")).end().start(sink.makeConstructor("-no-")).end().end().end() // name,'-','-no-'], end{#env}
								.start(sink.makeConstructor(name)).end().end(); // name]  end of {#env} ,
						for (int j = 0; j < arity; ++j)
							sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL)).startMetaApplication("#"+j).endMetaApplication(); // $Cons[#j,
						sink = sink.start(sink.makeConstructor(CRS.NIL_SYMBOL)).end(); // $Nil
						for (int j = 0; j < arity; ++j)
							sink = sink.end(); // ]  (of $Cons for j)
						sink = sink.end() // ]  (of $)
								.end(); // end of {#env}
						//  ] (of $Rule)
						sink = sink.end();
						continue  FunctionLoop; // only one dispatch rule per function
						
					case 3 : // multiple name
					case 7 : // ¬name and multiple name
						assert false : "Cannot yet handle multiple values for same property...";
				}
			}

			// Variable property dispatch rules.
			for (Map.Entry<Variable, Integer> e : variablePropertyState.entrySet())
			{
				Variable variable = e.getKey();
				int state = e.getValue();
				switch (state & 7)
				{
					case 5 : // ¬variable and variable
						// Generate rule:
						// $Cons[
						sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL)); 
						++conses;
						//  $Rule[
						sink = sink.start(sink.makeConstructor(Builder.RULE_SYMBOL));
						//  function-variable-property-variable
						sink = sink.start(sink.makeConstructor(function+"-variable-property-"+variable.name())).start(sink.makeConstructor(Builder.FREE_OPTION_SYMBOL)).use(variable).end().end();
						//    {#env}function[#1,...,variable,...,#j]
						sink = PropertiesWrapperConstructor.start(sink, "#env", null, null, null) // {#env}
								.start(function); // function[
						for (int j = 0; j < arity; ++j)
							sink = (j == state>>3 ? sink.use(variable) : sink.startMetaApplication("#"+(j+1))); // variable or #j
						sink = sink.end() // ]
								.end(); // end of {#env}
						//    {#env}$[C,$[:,'function-',{#env}IfDef[variable,'-','-no-'],variable], (#1;...#j;)]
						sink = PropertiesWrapperConstructor.start(sink, "#env", null, null, null) // {#env}
								.start(sink.makeConstructor(CRS.EVAL_SYMBOL)).start(sink.makeConstructor(Primitive.CONSTRUCTION)).end() // $[C,
								.start(sink.makeConstructor(CRS.EVAL_SYMBOL)).start(sink.makeConstructor(Primitive.CONCATENATION)).end() // $[:,
								.start(sink.makeConstructor(function.symbol()+"-")).end(); // 'function-'
						sink = PropertiesWrapperConstructor.start(sink, "#env", null, null, null) // {#env}
								.start(sink.makeConstructor(CRS.EVAL_SYMBOL)).start(sink.makeConstructor(Primitive.IF_DEF)).end() // $[IfDef,
								.use(variable).start(sink.makeConstructor("-")).end().start(sink.makeConstructor("-no-")).end().end().end()// variable,'-','-no-'], end{#env}
								.use(variable).end(); // variable] ,
						for (int j = 0; j < arity; ++j)
						{
							sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL)); // $Cons[
							sink = (j == state>>3 ? sink.use(variable) : sink.startMetaApplication("#"+j).endMetaApplication()); // variable or #j,
						}
						sink = sink.start(sink.makeConstructor(CRS.NIL_SYMBOL)).end(); // $Nil
						for (int j = 0; j < arity; ++j)
							sink = sink.end(); // ]  (of $Cons for j)
						sink = sink.end() // ]  (of $)
								.end(); // end of {#env}
						//  ] (of $Rule)
						sink = sink.end();
						continue  FunctionLoop; // only one dispatch rule per function
						
					case 3 : // multiple variable
					case 7 : // ¬variable and multiple variable
						assert false : "Cannot yet handle multiple values for same property...";
				}
			}

			// Meta-variable property dispatch rules.
			for (Map.Entry<String, Integer> e : metaPropertyState.entrySet())
			{
				String metaVariable = e.getKey();
				int state = e.getValue();
				
				switch (state & 7)
				{
					case 5 : // ¬#meta and #meta
						// Generate rule:
						// $Cons[
						sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL)); 
						++conses;
						//  $Rule[
						sink = sink.start(sink.makeConstructor(Builder.RULE_SYMBOL));
						//  function-meta-property-meta
						sink = sink.start(sink.makeConstructor(function+"-meta-property-"+metaVariable)).end();
						//    {#env}function[#1,...,#meta,...,#j]
						sink = PropertiesWrapperConstructor.start(sink, "#env", null, null, null) // {#env}
								.start(function); // function[
						for (int j = 0; j < arity; ++j)
							sink = sink.startMetaApplication(j == state>>3 ? metaVariable : "#"+(j+1)).endMetaApplication(); // metaVariable or #j
						sink = sink.end() // ]
								.end(); // end of {#env}
						//    {#env}$[C,$[:,'function-',{#env}IfDef[metaVariable,'-','-no-'],metaVariable], (#1;...#j;)]
						sink = PropertiesWrapperConstructor.start(sink, "#env", null, null, null) // {#env}
								.start(sink.makeConstructor(CRS.EVAL_SYMBOL)).start(sink.makeConstructor(Primitive.CONSTRUCTION)).end() // $[C,
								.start(sink.makeConstructor(CRS.EVAL_SYMBOL)).start(sink.makeConstructor(Primitive.CONCATENATION)).end() // $[:,
								.start(sink.makeConstructor(function.symbol()+"-")).end(); // 'function-'
						sink = PropertiesWrapperConstructor.start(sink, "#env", null, null, null) // {#env}
								.start(sink.makeConstructor(CRS.EVAL_SYMBOL)).start(sink.makeConstructor(Primitive.IF_DEF)).end() // $[IfDef,
								.startMetaApplication(metaVariable).endMetaApplication().start(sink.makeConstructor("-")).end().start(sink.makeConstructor("-no-")).end().end().end()// #metaVariable,'-','-no-'], end{#env}
								.startMetaApplication(metaVariable).endMetaApplication().end(); // metaVariable] ,
						for (int j = 0; j < arity; ++j)
						{
							sink = sink.start(sink.makeConstructor(CRS.CONS_SYMBOL)); // $Cons[
							sink = sink.startMetaApplication(j == state>>3 ? metaVariable : "#"+j).endMetaApplication(); // metaVariable or #j,
						}
						sink = sink.start(sink.makeConstructor(CRS.NIL_SYMBOL)).end(); // $Nil
						for (int j = 0; j < arity; ++j)
							sink = sink.end(); // ]  (of $Cons for j)
						sink = sink.end() // ]  (of $)
								.end(); // end of {#env}
						//  ] (of $Rule)
						sink = sink.end();
						continue  FunctionLoop; // only one dispatch rule per function
						
					case 3 : // multiple metaVariable
					case 7 : // ¬metaVariable and multiple metaVariable
						assert false : "Cannot yet handle multiple values for same property...";
				}
			}
		} // end FunctionLoop
		
		sink = sink.start(sink.makeConstructor(CRS.NIL_SYMBOL)).end(); // $Nil  (for innermost $Cons)
		for (int i = 0; i < conses; ++i)
			sink = sink.end(); // ]  (for i'th rule $Cons)

		return sink;
	}

}
