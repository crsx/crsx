module "net.sf.crsx.hacs.Hacs" {

sort Module | ⟦ module ⟨String⟩ { ⟨Declaration*⟩ } ⟧ ;

// HACS SYNTAX

sort Module
| ⟦ module ⟨ModuleName⟩ { ⟨Declaration*⟩ } ⟧
;
sort ModuleName | ⟦⟨Name⟩⟧ | ⟦⟨String⟩⟧ ;

sort Declaration
| ⟦⟨Module⟩⟧
| ⟦ import ⟨ModuleName⟩ ⟨SortNameList?⟩ ; ⟧
| ⟦⟨LexicalDeclaration⟩⟧
| ⟦⟨SyntaxDeclaration⟩⟧
| ⟦⟨RuleDeclaration⟩⟧
;

// Lexical Analysis.

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

token Repeat | [+?*]? ;

token LAng | "⟨" ;
token RAng | "⟩" ;

token CC | \[ \^? (\- | \] ⟨CCRange⟩)? ( ([^\]\\-] | ⟨Escape⟩) ⟨CCRange⟩ )* \-? \] ;

fragment CCRange | \- ([^\]\\] | ⟨Escape⟩) ;

token Char | [A-Za-z0-9] | ⟨Escape⟩ ;

token ⟨Name⟩ | ⟨Upper⟩ ⟨AlphaNum⟩* ;










}

