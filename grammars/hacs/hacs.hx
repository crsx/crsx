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
    | ⟦ ⟨Module⟩ ⟨Semi⟩ ⟧ 
    | ⟦ ⟨LexicalDeclaration⟩ ⟨Semi⟩ ⟧
    | ⟦ ⟨SortDeclaration⟩ ⟨Semi⟩ ⟧
    | ⟦ ⟨RuleDeclaration⟩ ⟨Semi⟩ ⟧
    ;

// LEXICAL DECLARATIONS.

sort LexicalDeclaration
    | ⟦ ⟨Space⟩ ⟨RegExp⟩ ⟧
    | ⟦ ⟨Token⟩ ⟨SortName⟩ ⟨Bar⟩ ⟨RegExp⟩ ⟧
    | ⟦ ⟨Fragment⟩ ⟨SortName⟩ ⟨Bar⟩ ⟨RegExp⟩ ⟧
    | sugar ⟦ ⟨Token⟩ ⟨Fragment#⟩ ⟨SortName#1⟩ ⟨Bar#⟩ ⟨RegExp#2⟩ ⟧ → ⟦ ⟨Fragment#⟩ ⟨SortName#1⟩ ⟨Bar#⟩ ⟨RegExp#2⟩ ⟧
    ;

sort SortName
    | ⟦ ⟨Constructor⟩ ⟧
    ;

sort RegExp
    | ⟦ ⟨RegExp@1⟩ ⟨Bar⟩ ⟨RegExp@2⟩ ⟧@1   // Alternative
    | ⟦ ⟨RegExp@2⟩ ⟨RegExp@3⟩ ⟧@2         // Concatenation
    | ⟦ ⟨RegExp@4⟩ ⟨Repeat⟩ ⟧@3           // Repeat
    | ⟦ ⟨String⟩ ⟧@4                      // Keyword
    | ⟦ ⟨CharClass⟩ ⟧@4                   // Character Class
    | ⟦ . ⟧@4                             // Any
    | ⟦ ⟨SortName⟩ ⟧@4                    // Token/Fragment Reference NOTE: NOT COMPATIBLE WITH RAW.PG
    | ⟦ ⟨LParen⟩ ⟨RegExp⟩ ⟨RParen⟩ ⟧@4                  // Nesting
    ;

sort Repeat 
    | ⟦⟨Star⟩⟧ 
    | ⟦⟨Plus⟩⟧ 
    | ⟦⟨Quest⟩⟧
    | ⟦⟧
    ;

// SORT DECLARATION.

sort SortDeclaration
    | ⟦ sort ⟨SortName⟩ ⟨Bar⟩ ⟨SortAlternative⟩ ⟧         // Sort declarations
    ;

sort SortAlternative
    | ⟦ ⟨Data?⟩ ⟨Form⟩ ⟧        // Data sort
    | ⟦ scheme ⟨Form⟩ ⟧         // Function sort
    ;

sort Forms
    | ⟦ ⟨Form⟩ ⟨Semi⟩ ⟧
    | ⟦ ⟧
    ;

sort Form
    | ⟦ ⟨LL⟩ ⟨ParsedForm⟩ ⟨RR⟩ ⟨Precedence⟩ ⟧                  // Parsed unsorted form
    | ⟦ ⟨Constructor⟩ ⟨LSquare⟩ ⟨ScopeSorts⟩ ⟨RSquare⟩ ⟧       // Form construction
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
 
sort ScopeSorts
    | ⟦ ⟨ScopeSort⟩ ⟨CommaScopeSorts⟩ ⟧
    | ⟦ ⟧
    ;

sort CommaScopeSorts
    | ⟦ ⟨Comma⟩ ⟨ScopeSort⟩⟧
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
    | ⟦ ⟨LParen⟩ ⟨Sort⟩ ⟨RParen⟩ ⟧
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
    | ⟦ ⟨Rule?⟩ ⟨Priority⟩ ⟨Header⟩ ⟨Term⟩ ⟨RuleSuffix⟩ ⟧
    ;

sort RuleSuffix
    | ⟦ → ⟨NotVariableTerm⟩ ⟧
    | ⟦ ⟨ColonColon⟩ ⟨Constructor⟩ ⟧
    | ⟦ ⟨ColonColonEqual⟩ ⟨List⟩ ⟧
    | ⟦ ⟧
    ;

sort Priority
    | ⟦ default ⟧
    | ⟦ priority ⟧
    | ⟦ ⟧
    ;

sort Header
    | ⟦ ⟧
    ;

// TERM DECLARATION.

sort Term 
    | ⟦ ⟨Binders?⟩ ⟨NotVariableTerm⟩⟧
    ;

sort Binders
    | ⟦ ⟨Variables⟩ . ⟧
    ;

sort NotVariableTerm
    | ⟦ ⟨Constructor⟩ ⟨Arguments⟩ ⟧
    | ⟦ ⟨Literal⟩ ⟧
    | ⟦ ⟨LL⟩ ⟨Parsed⟩ ⟨RR⟩ ⟧
    | ⟦ ⟨MetaVariable⟩ ⟨Arguments?⟩ ⟧
    ; 
  
sort Arguments
    | ⟦ ⟨LSquare⟩ ⟨TermList⟩ ⟨RSquare⟩ ⟧
    | ⟦ ⟧
    ;

sort Parsed 
    | ⟦ ⟨ConcreteSpace⟩ ⟨Parsed⟩ ⟧
    | ⟦ ⟨ConcreteWord⟩ ⟨Parsed⟩ ⟧
    | ⟦ ⟨ELAng⟩ ⟨Term⟩ ⟨ERAng⟩ ⟨Parsed⟩ ⟧
    | ⟦ ⟧
    ; 

sort TermList
    | ⟦ ⟨Term⟩ ⟨CommaTermList⟩ ⟧
    ;

sort CommaTermList
    | ⟦ ⟨Comma⟩⟨TermList⟩ ⟧
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
    | ⟦ ⟨LSquare⟩ ⟨VariableList?⟩ ⟨RSquare⟩ ⟧
    ;  

sort Literal
    | ⟦ ⟨String⟩ ⟧
    | ⟦ ⟨Number⟩ ⟧
    ;

sort MetaVariable 
    | ⟦ ⟨Meta⟩ ⟧ 
    | ⟦ ⟨Hash⟩ ⟧
    ;

sort List 
    | ⟦ ⟨LParen⟩ ⟨SemiTermList⟩ ⟨RParen⟩ ⟧
    ;

sort SemiTermList
    | ⟦ ⟨Term⟩ ⟨Semi⟩ ⟨SemiTermList⟩ ⟧
    | ⟦ ⟧
    ;

// TOKENS.

//lexer Default;

token LSquare           | '[';
token RSquare           | ']'; 
token LL                | '⟦'      → Concrete; 

token Data              | "data";
token Rule              | "rule";
token Token             | "token"       → Regex;
token Fragment          | "fragment"    → Regex;
token Space             | "space"       → Regex;

// Numbers.
token Number            | ⟨Natural⟩;
token Natural           | ⟨Digits⟩;

lexer Default, Regex;

token LParen            | '(';
token RParen            | ')';
token Hash              | '#'; 
token Star              | '*';
token Plus              | '+';
token Quest             | '?'; 
token Comma             | ',';
token Bar               | '|';
token Semi              | ';'      → Default; 
token ERAng             | '⟩'      → Concrete; 
token ColonColonEqual   | "::=";
token ColonColon        | "::";

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

space [\n\t ]+ | "//" [^\n\r\f]* | nested "/*" "*/" ;

lexer Regex;

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

token RR     | '⟧'    → Default; 
token ELAng  | '⟨'    → Default; 

token ConcreteSpace 
    | [\n\t ]+ 
    ;

token ConcreteWord 
    | [^\n\t ⟨⟧]+ 
    ;

} 