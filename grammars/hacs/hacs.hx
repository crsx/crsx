// HACS Grammar v0.1
//
// THIS IS NOT THE OFFICIAL HACS GRAMMAR.
// FOR THE OFFICIAL HACS GRAMMAR, LOOK FOR Raw.pg IN THE CRSX PROJECT.
// 

module "Hacs" {

// STRUCTURE.

sort Module 
	| ⟦ module ⟨String⟩ { ⟨Declaration*⟩ } ⟧ 
	;

sort ModuleName
	| ⟦ ⟨String⟩ ⟧
	;

sort Declaration 
	| ⟦ ⟨Module⟩ ; ⟧ 
	| ⟦ ⟨LexicalDeclaration⟩ ; ⟧
	| ⟦ ⟨SortDeclaration⟩ ; ⟧ 
	;

// LEXICAL DECLARATIONS.

sort LexicalDeclaration
	| ⟦ space ⟨RegExp⟩ ⟧
	| ⟦ token ⟨Name⟩ | ⟨RegExp⟩ ⟧
	| ⟦ fragment ⟨Name⟩ | ⟨RegExp⟩ ⟧
	| sugar ⟦ token fragment ⟨Name#1⟩ | ⟨RegExp#2⟩ ⟧ → ⟦ fragment ⟨Name#1⟩ | ⟨RegExp#2⟩ ⟧
	;

sort RegExp
	| ⟦ ⟨RegExp@2⟩ | ⟨RegExp@2⟩ ⟧@1   // Alternative
	| ⟦ ⟨RegExp@3⟩ ⟨RegExp@3⟩ ) ⟧@2   // Concatenation
	| ⟦ ⟨RegExp@4⟩ ⟨Repeat⟩ ⟧@3       // Repeat
	| ⟦ ⟨String⟩ ⟧@4                  // Keyword
	| ⟦ ⟨CharClass⟩ ⟧@4               // Character Class
	| ⟦ . ⟧@4                         // Any
	| ⟦ ⟨LAng⟩ ⟨Name⟩ ⟨RAng⟩ ⟧@4      // Token/Fragment Reference
	| ⟦ ( ⟨RegExp⟩ ) ⟧@4              // Nesting
	;

sort Repeat 
	| ⟦*⟧ 
	| ⟦+⟧ 
	| ⟦?⟧
	| ⟦⟧
	;

sort SortDeclaration
	| ⟦ sort ⟨Name⟩ ⟨SortAlternative*⟩ ; ⟧
	;

sort SortAlternatives
	| ⟦ | ⟨SortAlternative⟩ ⟧
	;

sort SortAlternative
	| ⟦ ⟨DataForm⟩ ⟧
	;

sort DataForm
	| data ⟦ ⟨Data?⟩ ⟨Form⟩ ⟧
	;

sort Form
	| ⟦ ⟨LL⟩  ⟨RR⟩ ⟨Precedence⟩ ⟧
	;

//sort ParsedForm
//	| ⟦ ⟨ConcreteSpace⟩ ⟨ParsedForm⟩ ⟧
//	| ⟦ ⟨ConcreteWord⟩ ⟨ParsedForm⟩ ⟧
//	| ⟦ ⟨LAng⟩  ⟨ScopeSort⟩ ⟨Precedence⟩ ⟨Repeat⟩ ⟨RLang⟩ ⟨ParsedForm⟩ ⟧
//	;

sort Precedence
	| ⟦ @ ⟨Natural⟩ ⟧
	| ⟦ ⟧
	;
 

// TOKENS.

token LL 	| '⟦' ; 
token RR 	| '⟧' ; 
token LAng  | '⟨' ; 
token RAng  | '⟩' ; 
token Data  | "data";

token CharClass 
	| \[ \^? (\- | \] ⟨CCRange⟩)? ( ([^\]\\-] | ⟨Escape⟩) ⟨CCRange⟩ )* \-? \]
	;

fragment CCRange 
	| \- ([^\]\\] | ⟨Escape⟩) 
	;

fragment Escape // TODO: octal/hex/unicode
	| "\\n"
	| "\\r"
	| "\\a"
	| "\\f"
	| "\\t"
	;

token Natural
	| [0-9]+
	;

token Name
	| ⟨AnyName⟩
	;

token String 
	| '"' [^"]* '"' 
	| "'" [^']* "'"  
	;

token ProperName  
	| ⟨UpperEtc⟩ ⟨AlphaNum⟩* 
	;

token LowerName   
	| ⟨Lower⟩ ⟨AlphaNum⟩* 
	;

token AnyName     
	| (⟨Lower⟩ | ⟨UpperEtc⟩) ⟨AlphaNum⟩* 
	;


fragment UpperEtc  | [A-Z$_] ;
fragment Lower     | [a-z] ;
fragment AlphaNum  | [A-Za-z0-9] ;

space [\n\t ]+ | "//" .* | nested "/*" "*/" ;

} 