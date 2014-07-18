// $Id: hoacs.hx,v 3.1 2013/08/23 07:12:32 krisrose Exp $
module hoacs {

//// STRUCTURE.

sort Module | ⟦ module ⟨Identifier⟩ { ⟨Declaration*_[;]⟩ } ⟧ ;
sort Declaration | Module | LexicalDeclaration | SortDeclaration | Rule ;

//// LEXICAL DECLARATIONS.

sort LexicalDeclaration
| ⟦ space ⟨RegExp⟩ ⟧
| ⟦ token ⟨SortName⟩ | ⟨RegExp⟩ ⟧
| ⟦ token fragment ⟨Identifier⟩ | ⟨RegExp⟩ ⟧
;
sort RegExp
| ⟦ ⟨RegExp@1*_[|]⟩ ⟧  // choice
| ⟦ ⟨RegExp@2*⟩ ⟧@1  // concatenation

| ⟦ ⟨RegExp@2⟩ ⟨Repeat?⟩ ⟧@1
| ⟦ ⟨STRING⟩ ⟧@2 | ⟦ ⟨CLASS⟩ ⟧@2 | ⟦ ⟨Identifier⟩ ⟧@2
| ⟦ ( ⟨RegExp⟩ ) ⟧@2 → RegExp
;
sort Repeat | ⟦* ⟨RepeatSep?⟩⟧ | ⟦+ ⟨RepeatSep?⟩⟧ | ⟦?⟧ ;
sort RepeatSep | "_" RegExpSimple ;

//// SORTS.

sort SortDeclaration

;

sort Sort | ⟦ ⟨SortRef⟩ ⟨SimpleSort*⟩ ⟧ ;
sort SortRef | META | VAR ;
sort SimpleSort | SortRef | ⟦ ( ⟨Sort⟩ ) ⟧ ;

sort SortAlternative
| ⟦ | ⟨Form⟩ ⟧
| ⟦ | scheme ⟨Form⟩ ⟧
| ⟦ | ⟨Form⟩ → ⟨Form⟩ ⟧
| ⟦ | ⟨AttributeForm⟩ ⟧
;

sort Form
| ⟦ ⟨CON⟩ [ ⟨ScopeSort*_[,]⟩ ] ⟧
| ⟦ ⟨CON⟩ ⟧ → ⟦ ⟨CON⟩[] ⟧
| FormUnit+
;
sort ScopeSort |  ⟦ ⟨SortName⟩ ⟧ ;
FormUnit | ⟦ ⟨SortPrec⟩ ⟨Repeat?⟩ ⟧ | ⟦ ⟦ ⟨ParsedFormUnit*⟩ ⟧ ⟨Repeat?⟩ ⟧ ;
ParsedFormUnit | ⟨PARSEDCHAR⟩ | ⟦ ⟨ ⟨ParsedScopeSort⟩ ⟩ ⟧ ;
ParsedScopeSort | ⟦ ⟨ScopePrefix*⟩ ⟨SortPrec⟩ ⟧ | ⟦ . ⟨SortPrec⟩ ⟧ | ⟦ ⟨SortPrec⟩ . ⟧ ;
ScopePrefix | ⟦ ⟨SortName⟩ . ⟧ ;
SortPrec | SortName | ⟦ ⟨SortName⟩ @ ⟨INTEGER⟩ ⟧ ;


AttributeForm | ⟦ ⟨ATTRIBUTEKIND⟩ ⟨AttributeName?⟩ : ⟨SortName?⟩ = ⟨SortName⟩ ⟧
                 | ⟦ ⟨ATTRIBUTEKIND⟩ ⟨AttributeName?⟩ : . ⟨SortName?⟩ = ⟨SortName⟩ ⟧ ;

SortName | META | ⟦⟨.VAR⟩⟧ ;

Identifier | META | VAR | CON ;
AttributeName | Identifier | Literal ;

//// RULES.
Rule | ⟦ ⟨RuleHead?⟩ ⟨Term⟩ → ⟨Term⟩ ⟧ ;
RuleHead | ⟦ ⟨CoreTerm⟩ : ⟧ ;

//// TERMS.
Term |
  ⟦ ⟨Term⟩ ⟨ATTRIBUTEKIND⟩ ⟨AttributeName⟩ { ⟨Simple⟩ : ⟨CoreTerm⟩ } ⟧
| ⟦ ⟨Term⟩ ⟨ATTRIBUTEKIND⟩ ⟨AttributeName⟩ { ⟨CoreTerm⟩ } ⟧
| ⟦ ⟨Term⟩ ⟨ATTRIBUTEKIND⟩ ⟨META⟩ ⟧
| CoreTerm
;
CoreTerm |
  ⟦ CON [ ⟨Scope*_[,]⟩ ] ⟧ | ⟨CON⟩⇒⟦⟨CON⟩[]⟧
| ⟦ ⟨META⟩ ⟨MetaArgument*⟩ ⟧
| ⟦ ⟦ ⟨ParsedUnit*⟩ ⟧ ⟧
| Simple
;
Scope | ⟦ ⟨VAR.⟩ . ⟨VAR.Scope⟩ ⟧ | Term ;
ParsedUnit | PARSEDCHAR | ⟦ ⟨ ⟨Term⟩ ⟩ ⟧ ;
Simple | ⟦ ⟨.VAR⟩ ⟧ | Literal ;
Literal | STRING | NUMBER ;






//// TOKENS.
token META | "" (UPPER|LOWER)* SUFFIX*   | "" STRING SUFFIX* ;
token VAR  | LOWER NAMECHAR* SUFFIX* | "v" STRING SUFFIX* ;
token CON  | UPPER NAMECHAR* SUFFIX* | SYMBOL* SUFFIX* | "C" STRING SUFFIX* ;
token fragment SUFFIX | "_" NAMECHAR+ | DIGIT+ ;

token STRING | ["] STRINGCHAR* ["] ;
token fragment STRINGCHAR | [¬\\"]
| [\\] [¬0-7Uu] | [\\] [0-7]? [0-7]? [0-7]
| [\\] [uU] [0-9a-fA-F]? [0-9a-fA-F]? [0-9a-fA-F]? [0-9a-fA-F]? [0-9a-fA-F]? [0-9a-fA-F]? [0-9a-fA-F]? [0-9a-fA-F]
;
token INTEGER | [-+]* DIGIT+ ;
token NUMBER | (INTEGER | [-+]* DIGIT* [.] DIGIT+) ( [Ee] [+-] DIGIT+ )? ;

token ATTRIBUTEKIND | [↑↓] ;

token fragment UPPER | [A-Z] ;
token fragment LOWER | [a-z] ;
token fragment DIGIT | [0-9] ;
token fragment NAMECHAR  | LOWER | UPPER | "-" ;
token fragment SYMBOL | [¬A-Za-z0-9\\-] ;

token CLASS | "[" "¬"? CLASSCHAR* "]" ;
token fragment CLASSCHAR | [¬\\\[\]] | [\\] (LOWER | [\\\[\]]) ;

token PARSEDCHAR | [¬⟦⟧⟨⟩ ] ;


token LL | '\u27e6' ; // ⟦
token RR | '\u27e7' ; // ⟧
token L | '\u27e8' ; // ⟨
token R | '\u27e9' ; // ⟩
space [ ]+ | "//" [¬\n\r]* | nested '/*' '*/' ;

}
