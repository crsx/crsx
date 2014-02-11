// HACS example: "Functions Using Plus Zero"
module FUP {
 sort E | ⟦0⟧ | ⟦ ( ⟨E⟩ + ⟨E⟩ ) ⟧ | ⟦ ⟨F⟩ ⟨E⟩ ⟧ ;
 sort F | ⟦ [ ⟨[V]⟩ ↦ ⟨E[V]⟩ ] ⟧ ; //abstraction
 token V | [a-z]+[0-9]* ;

 sort E | scheme ⟦run ⟨E⟩⟧;
 ⟦run 0⟧ → ⟦0⟧;
 ⟦run (⟨E#⟩+0)⟧ → ⟦run ⟨E#⟩⟧;
 ⟦run ([x↦⟨E#[x]⟩] ⟨E#2⟩⟧ → ⟦run ⟨E#[E#2]⟩⟧;
}
