// HACS Grammar v0.1
//
// THIS IS NOT THE OFFICIAL HACS GRAMMAR.
// FOR THE OFFICIAL HACS GRAMMAR, LOOK FOR Raw.pg IN THE CRSX PROJECT.
// 
// REQUIRED EXPERIMENTAL HACS FEATURES IMPLEMENTED IN GIT BRANCH NAMED hacs-dev-lexer

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
    | ⟦ ⟨RuleDeclaration⟩ ; ⟧ 
    ;

// LEXICAL DECLARATIONS.

sort LexicalDeclaration
    | ⟦ space ⟨RegExp⟩ ⟧
    | ⟦ token ⟨SortName⟩ | ⟨RegExp⟩ ⟧
    | ⟦ fragment ⟨SortName⟩ | ⟨RegExp⟩ ⟧
    | sugar ⟦ token fragment ⟨SortName#1⟩ | ⟨RegExp#2⟩ ⟧ → ⟦ fragment ⟨SortName#1⟩ | ⟨RegExp#2⟩ ⟧
    ;

sort RegExp
    | ⟦ ⟨RegExp@1⟩ | ⟨RegExp@2⟩ ⟧@1   // Alternative
    | ⟦ ⟨RegExp@2⟩ ⟨RegExp@3⟩ ⟧@2     // Concatenation
    | ⟦ ⟨RegExp@4⟩ ⟨Repeat⟩ ⟧@3       // Repeat
    | ⟦ ⟨String⟩ ⟧@4                  // Keyword
    | ⟦ ⟨CharClass⟩ ⟧@4               // Character Class
    | ⟦ . ⟧@4                         // Any
    | ⟦ ⟨SortName⟩ ⟧@4                // Token/Fragment Reference NOTE: NOT COMPATIBLE WITH RAW.PG
    | ⟦ ( ⟨RegExp⟩ ) ⟧@4              // Nesting
    ;

sort Repeat 
    | ⟦*⟧ 
    | ⟦+⟧ 
    | ⟦?⟧
    | ⟦⟧
    ;

// SORT DECLARATION.

sort SortDeclaration
    | ⟦ sort ⟨SortName⟩ ⟨SortAlternatives⟩ ⟧
    ;

sort SortAlternatives
    | ⟦ | ⟨SortAlternative⟩ ⟧
    ;

sort SortAlternative
    | ⟦ ⟨Data?⟩ ⟨Form⟩ ⟧        // Data sort
    | ⟦ scheme ⟨Form⟩ ⟧         // Function sort
    ;

sort Form
    | ⟦ ⟨LL⟩ ⟨ParsedForm⟩ ⟨RR⟩ ⟨Precedence⟩ ⟧
    ;

sort ParsedForm
    | ⟦ ⟨ConcreteSpace⟩ ⟨ParsedForm⟩ ⟧
    | ⟦ ⟨ConcreteWord⟩ ⟨ParsedForm⟩ ⟧
    | ⟦ ⟨ELAng⟩ ⟨ScopeSort⟩ ⟨Precedence⟩ ⟨Repeat⟩ ⟨ERAng⟩ ⟨ParsedForm⟩ ⟧ 
    | ⟦ ⟧ 
    ;

sort Precedence
    | ⟦ @ ⟨Natural⟩ ⟧
    | ⟦ ⟧
    ;
 
sort ScopeSort
    | ⟦ ⟨Sort⟩ ⟨Repeat⟩ ⟧
    ;

sort Sort
    | ⟦ ⟨SimpleSort⟩ ⟨SimpleSorts⟩ ⟧
    ;

sort SimpleSorts
    | ⟦ ⟨SimpleSort⟩ ⟨SimpleSorts⟩ ⟧
    | ⟦ ⟧
    ;

sort SimpleSort
    | ⟦ ⟨SortName⟩ ⟨MetaVariables⟩ ⟧
    | ⟦ ⟨SortParam⟩ ⟧
    | ⟦ ( ⟨Sort⟩ ) ⟧
    ;

sort MetaVariables
    | ⟦ ⟨MetaVariable⟩ ⟧
    | ⟦ ⟧
    ;

sort SortParam
    | ⟦ ⟨Variable⟩ ⟧
    ;


// RULE DECLARATION.

sort RuleDeclaration
    | ⟦ ⟨Rule?⟩ ⟨Priority⟩ ⟨Header⟩ ⟨Pattern⟩ ⟨Contractum⟩ ⟧
    ;

sort Priority
    | ⟦ default ⟧
    | ⟦ priority ⟧
    | ⟦ ⟧
    ;

sort Header
    | ⟦ ⟧
    ;

sort Pattern
    | ⟦ ⟨Term⟩ ⟧
    ;

sort Contractum
    | ⟦ → ⟨Term⟩ ⟧
    | ⟦ ⟧
    ;

// TERM DECLARATION.

sort Term 
    | ⟦ ⟨Variable⟩ ⟨Term⟩ ⟧
    | ⟦ ⟨NotVariableTerm⟩ ⟧
    ;

sort NotVariableTerm
    | ⟦ ⟨Constructor⟩ ⟨Repeat⟩ ⟨LL⟩ ⟨Parsed⟩ ⟨RR⟩ ⟧                    // Sorted Syntax
    //| ⟦ ⟨Constructor⟩ ⟨Repeat⟩ ⟨MetaVariable⟩ [ ⟨Terms⟩ ] ⟧          // Sorted MetaApplication
    //| ⟦ ⟨Constructor⟩ ⟨Repeat⟩ ⟨Constructor⟩ [ ⟨Scopes⟩ ] ⟧          // Sorted Construction
    | ⟦ ⟨Constructor⟩ ⟨Repeat⟩ ⟨Variables⟩ ⟧                           // Sorted Variable
    //| ⟦ ⟨Constructor⟩ ⟨Repeat⟩ [ ⟨Scopes⟩ ] ⟧
    | ⟦ ⟨Literal⟩ ⟧
    | ⟦ ⟨LL⟩ ⟨Parsed⟩ ⟨RR⟩ ⟧
    //| ⟦ ⟨MetaVariable⟩ [ ⟨Terms⟩ ] ⟧
    ; 
  
sort Parsed 
    | ⟦ ⟨ConcreteSpace⟩ ⟨Parsed⟩ ⟧
    | ⟦ ⟨ConcreteWord⟩ ⟨Parsed⟩ ⟧
    | ⟦ ⟨ELAng⟩ ⟨Term⟩ ⟨ERAng⟩ ⟨Parsed⟩ ⟧
    | ⟦ ⟧
    ; 

sort Terms
    | ⟦ ⟨Term⟩ ⟨CommaTerms⟩ ⟧
    ;

sort CommaTerms
    | ⟦ ⟨Comma⟩ ⟨Terms⟩ ⟧
    | ⟦ ⟧
    ; 

sort Variables
    | ⟦ ⟨Variable⟩ ⟨Variables⟩ ⟧    // space-separated variables
    | ⟦ ⟧
    ;

sort VariableList
    | ⟦ ⟨Variable⟩ ⟨CommaVariableList⟩ ⟧    // comma-separated variables
    ;

sort CommaVariableList
    | ⟦ ⟨Comma⟩ ⟨VariableList⟩ ⟧
    | ⟦ ⟧
    ;

sort Scopes
    | ⟦ ⟨Scope⟩ ⟨CommaScopes⟩ ⟧
    ;

sort CommaScopes
    | ⟦ ⟨Comma⟩ ⟨Scopes⟩ ⟧
    | ⟦ ⟧
    ;

sort Scope
    | ⟦ ⟨NotVariableTerm⟩ ⟧
    | ⟦ ⟨Variables⟩ . ⟨Term⟩ ⟧
    //| ⟦ [ ⟨VariableList?⟩ ] ⟧
    ;  

sort Literal
    | ⟦ ⟨String⟩ ⟧
    | ⟦ ⟨Number⟩ ⟧
    ;

sort MetaVariable 
    | ⟦ ⟨Meta⟩ ⟧ 
    | ⟦ ⟨Hash⟩ ⟧
    ;

// TOKENS.

// Default lexer

token Hash  | '#'; 
token Comma | ','; 
token LL    | '⟦' → Concrete; 
token ERAng | '⟩' → Concrete; 
token Data  | "data";
token Rule  | "rule";

// Numbers.
token Number    | ⟨Natural⟩;
token Natural   | ⟨Digits⟩;


token SortName
    | ⟨Constructor⟩
    ;

token String 
    | '"' [^"]* '"' 
    | "'" [^']* "'"  
    ;

token Constructor
    | (⟨Upper⟩ | [$]) ⟨Name⟩? ⟨Suffix⟩*    // Constructor name 
    | "C" ⟨String⟩ ⟨Suffix⟩*               // Escaped constructor name
    ;

token Variable 
    | ⟨Lower⟩ ⟨Name⟩? ⟨Suffix⟩*     // Variable name
    | "v" ⟨String⟩ ⟨Suffix⟩*        // Escaped variable name
    ;

token Meta  
    | ⟨Hash⟩ (⟨Name⟩ | ⟨String⟩? ("#" ⟨Name⟩* ⟨Suffix⟩*))
    ;

fragment Upper     | [A-Z] ;
fragment UpperEtc  | [A-Z$_] ;
fragment Lower     | [a-z] ;
fragment Digit     | [0-9];
fragment Digits    | ⟨Digit⟩+;
fragment AlphaNum  | [A-Za-z0-9] ;
fragment Suffix    | "_" ⟨Name⟩? | "_"? ⟨Digits⟩;
fragment Name      | (⟨Lower⟩ | ⟨Upper⟩ | [$])+;

space [\n\t ]+ | "//" .* | nested "/*" "*/" ;

token CharClass 
    | "[" "^"? ([^]\n] | ⟨Escape⟩)* "]"
    ;

fragment Escape // TODO: octal/hex/unicode
    | "\\n"
    | "\\r"
    | "\\a"
    | "\\f"
    | "\\t"
    ;


lexer Concrete;

token RR     | '⟧' → Default; 
token ELAng  | '⟨' → Default; 

token ConcreteSpace 
    | [\n\t ]+ 
    ;

token ConcreteWord 
    | [^\n\t ⟨⟧]+ 
    ;

} 