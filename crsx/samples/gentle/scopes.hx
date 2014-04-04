module "net.sf.crsx.samples.gentle.Scopes" {
space [ \t\n] ;

token IDENTIFIER | [a-z] [A-Za-z_0-9]* ;

sort Id    | symbol ⟦⟨IDENTIFIER⟩⟧ ;

sort Type  | ⟦ A ⟧ | ⟦ B ⟧ ;

sort Stat  | ⟦ def ⟨Type⟩ ⟨Id⟩; ⟨Stat⟩ ⟧
	   | ⟦ use ⟨Type⟩ ⟨Id⟩; ⟨Stat⟩ ⟧
           | ⟦ ⟧ ;

// MAIN: Check that every 'use' uses same type as nearest in-scope 'def'.

sort Stat  | scheme Check(Stat) ;

Check(#s) → Check2(#s) ;

// 1. SYNTHESIZE ATTRIBUTE WITH ALL TOP LEVEL DEFINITIONS IN A PLAIN LIST.

attribute  ↑ds(Defs) ;
sort Defs  | ⟦ ⟨Type⟩ ⟨Id⟩ ; ⟨Defs⟩ ⟧ | ⟦⟧ ;

sort Stat  | ↑ds ;
⟦ def ⟨Type#t⟩ id; ⟨Stat#s↑ds(#ds)⟩ ⟧ ↑ds(⟦ ⟨Type#t⟩ id; ⟨Defs#ds⟩ ⟧) ;
⟦ use ⟨Type#t⟩ id; ⟨Stat#s↑ds(#ds)⟩ ⟧ ↑ds(#ds) ;
⟦⟧ ↑ds(⟦⟧) ;

// 2. CONVERT DEFINITIONS RECURSIVELY TO ENVIRONMENT.

attribute  ↓e{Id:Type} ;

sort Stat  | scheme Check2(Stat)
     	   | scheme Check2_(Defs, Stat) ↓e ;

Check2(#s↑ds(#ds)) → Check2_(#ds, #s) ;

Check2_(⟦ ⟨Type#t⟩ id; ⟨Defs#ds⟩ ⟧, #s) → Check2_(#ds, #s) ↓e{id : #t} ;

Check2_(⟦⟧, #s) → Check3(#s) ;

// 3. CHECK USING ENVIRONMENT.

sort Stat  | scheme Check3(Stat) ↓e ;

Check3(⟦ use ⟨Type#t⟩ id; ⟨Stat#s⟩ ⟧)
  ↓e{id:#t}
  // - we found a mapping from id to same type \#t
  → ⟦ use ⟨Type#t⟩ id; ⟨Stat Check3(#s)⟩ ⟧ ;

Check3(⟦ use ⟨Type#t⟩ id; ⟨Stat#s⟩ ⟧)
  ↓e{¬id}
  // - we did not find a mapping from id
  → error⟦ Undefined ⟨id⟩ ⟧ ;

default Check3(⟦ use ⟨Type#t⟩ id; ⟨Stat#s⟩ ⟧)
  ↓e{id:#t2}
  // - we found a mapping from id to some type \#t so it has the wrong type
  → error⟦ Bad type for ⟨id⟩ ⟧ ;

Check3(⟦ def ⟨Type#t⟩ id; ⟨Stat#s⟩ ⟧) → ⟦ def ⟨Type#t⟩ id; ⟨Stat Check3(#s)⟩ ⟧ ;

Check3(⟦⟧) → ⟦⟧ ;

}
