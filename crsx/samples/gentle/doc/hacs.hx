// HACS SYNTAX
module "net.sf.crsx.hacs.Hacs" {


// MODULES.

sort Module
| ⟦ module ⟨ModuleName⟩ { ⟨Declaration*⟩ } ⟧
;
sort ModuleName | ⟦⟨ProperName⟩⟧ | ⟦⟨String⟩⟧ ;

sort Declaration
| ⟦⟨Module⟩⟧
| ⟦ import ⟨ModuleName⟩ ⟨SortNameList?⟩ ; ⟧
| ⟦⟨LexicalDeclaration⟩⟧
| ⟦⟨SyntaxDeclaration⟩⟧
| ⟦⟨RuleDeclaration⟩⟧
;


// LEXICAL ANALYSIS.

sort LexicalDeclaration
| ⟦ space ⟨RE⟩ ; ⟧
| ⟦ token ⟨Name⟩ | ⟨RE⟩ ; ⟧
| ⟦ fragment ⟨Name⟩ | ⟨RE⟩ ; ⟧
| sugar ⟦ token fragment ⟨Name#1⟩ | ⟨RE#2⟩ ; ⟧ → ⟦ fragment ⟨Name#1⟩ | ⟨RE#2⟩ ; ⟧
;

sort RE
| ⟦ ⟨RE@1⟩ ⟨Repeat⟩ ⟧@1
| ⟦ ⟨LAng⟩ ⟨Name⟩ ⟨RAng⟩ ⟧@1
| ⟦ ⟨String⟩ ⟧@1
| ⟦ ⟨CC⟩ ⟧@1
| ⟦ ⟨Char⟩ ⟧@1
| ⟦ ( ⟨RE⟩ ) ⟧@1
| ⟦ ⟨RE@1+⟩ ⟧
;

sort Repeat | ⟦+⟧ | ⟦?⟧ | ⟦*⟧ | ⟦⟧ ;

token CC | \[ \^? (\- | \] ⟨CCRange⟩)? ( ([^\]\\-] | ⟨Escape⟩) ⟨CCRange⟩ )* \-? \] ;
fragment CCRange | \- ([^\]\\] | ⟨Escape⟩) ;

token Char | [A-Za-z0-9] | ⟨Escape⟩ ;

token ProperName  | ⟨UpperEtc⟩ ⟨AlphaNum⟩* ;
token LowerName   | ⟨Lower⟩ ⟨AlphaNum⟩* ;
token AnyName     | (⟨Lower⟩ | ⟨UpperEtc⟩) ⟨AlphaNum⟩* ;
fragment UpperEtc  | [A-Z$_] ;
fragment Lower     | [a-z] ;
fragment AlphaNum  | [A-Za-z0-9] ;


// SYNTAX ANALYSIS.

sort SyntaxDeclaration
| ⟦ sort ⟨Name⟩ ⟨SortAlternatives⟩ ; ⟧
| ⟦ attribute ⟨UpDown⟩ ⟨AttributeName⟩ ⟨AttributeSort⟩ ; ⟧



sort AttributeName | ⟦⟨ProperName⟩⟧ | ⟦⟨VariableName⟩⟧ ;



// UNICODE CHARACTERS.

token Negate     | "¬" ;	// \u00AC
token Paragraph  | "¶" ;	// \u00B6
token Up      	 | "↑" ;	// \u2191
token Right   	 | "→" ;	// \u2192
token Down    	 | "↓" ;	// \u2193
token LWhite  	 | "⟦" ;	// \u27E6
token RWhite  	 | "⟧" ;	// \u27E7
token LAngle  	 | "⟨" ;	// \u27E8
token RAngle  	 | "⟩" ;	// \u27E9

}
