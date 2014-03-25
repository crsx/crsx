/* C RULES FOR CRSX CRSXC MODULE SYMBOLS. */
#include "CRSXC.h" 
#ifdef __cplusplus
extern "C" {
#endif

/* FUNCTION ComputeSymbols$1. */
int conBindOffs_M_ComputeSymbols_s1[] = {0 , 0 , 0};
char *nameFun_M_ComputeSymbols_s1(Term term) { return  "ComputeSymbols$1" ; }
struct _ConstructionDescriptor descriptor_M_ComputeSymbols_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_ComputeSymbols_s1), conBindOffs_M_ComputeSymbols_s1, &nameFun_M_ComputeSymbols_s1, &step_M_ComputeSymbols_s1};

int step_M_ComputeSymbols_s1(Sink sink__V1, Term term__V2)
{
  int term__V2_count = LINK_COUNT(term__V2); permitUnusedInt(term__V2_count);
  do {
    /* Contraction rule SYMBOLS-ComputeSymbols-1. */
    ASSERT(sink__V1->context, !strcmp(SYMBOL(term__V2),  "ComputeSymbols$1" ));
    Term sub__V3 = LINK(sink__V1->context, SUB(term__V2, 0)); int sub__V3_count = term__V2_count*LINK_COUNT(sub__V3); permitUnusedInt(sub__V3_count);
    /* sub__V3 = &#11 */
    Term sub__V4 = LINK(sink__V1->context, SUB(term__V2, 1)); int sub__V4_count = term__V2_count*LINK_COUNT(sub__V4); permitUnusedInt(sub__V4_count);
    /* sub__V4 = &#12 */
    
    NamedPropertyLink namedP__V5 = LINK_NamedPropertyLink(sink__V1->context, NAMED_PROPERTIES(term__V2));
    VariablePropertyLink varP__V6 = LINK_VariablePropertyLink(sink__V1->context, VARIABLE_PROPERTIES(term__V2));
    Hashset namedFV__V7 = LINK_VARIABLESET(sink__V1->context, namedPropertyFreeVars(namedP__V5));
    Hashset varFV__V8 = LINK_VARIABLESET(sink__V1->context, variablePropertyFreeVars(varP__V6));
    UNLINK(sink__V1->context, term__V2);
    { START(sink__V1, _M_ComputeSymbols2);
      COPY(sink__V1, sub__V3);COPY(sink__V1, sub__V4);{ Term term__V9;
        { char *value__V10 = getenv( "MODULE" );
          if (value__V10) term__V9 = makeStringLiteral(sink__V1->context, value__V10);
          else {term__V9 = makeStringLiteral(sink__V1->context,  "" ); }
        }
        COPY(sink__V1, term__V9); /*CONSERVATIVE*/ }
      END(sink__V1, _M_ComputeSymbols2); }
    UNLINK_VARIABLESET(sink__V1->context, namedFV__V7); UNLINK_VARIABLESET(sink__V1->context, varFV__V8);
    UNLINK_NamedPropertyLink(sink__V1->context, namedP__V5); UNLINK_VariablePropertyLink(sink__V1->context, varP__V6);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Declarations. */
int conBindOffs_M_X_Declarations[] = {0 , 0};
char *nameFun_M_X_Declarations(Term term) { return  "X-Declarations" ; }
struct _ConstructionDescriptor descriptor_M_X_Declarations = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_X_Declarations), conBindOffs_M_X_Declarations, &nameFun_M_X_Declarations, &step_M_X_Declarations};

int step_M_X_Declarations(Sink sink__V11, Term term__V12)
{
  int term__V12_count = LINK_COUNT(term__V12); permitUnusedInt(term__V12_count);
  Term sub__V13 = FORCE(sink__V11->context, SUB(term__V12, 0));
  EnumOf_M__sList choice__V14 = (IS_VARIABLE_USE(sub__V13) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V13));
  switch (choice__V14)
  {
    case Data_M__sCons: { /* Function SYMBOLS-X-Declarations-1$X-Declarations$$Cons case $Cons */
      ASSERT(sink__V11->context, !strcmp(SYMBOL(term__V12),  "X-Declarations" ));
      Term sub__V15 = SUB(term__V12, 0); permitUnusedTerm(sub__V15); int sub__V15_count = term__V12_count*LINK_COUNT(sub__V15); permitUnusedInt(sub__V15_count);
      ASSERT(sink__V11->context, !strcmp(SYMBOL(sub__V15),  "$Cons" ));
      Term sub__V16 = LINK(sink__V11->context, SUB(sub__V15, 0)); int sub__V16_count = sub__V15_count*LINK_COUNT(sub__V16); permitUnusedInt(sub__V16_count);
      /* sub__V16 = &#0-0 */
      Term sub__V17 = LINK(sink__V11->context, SUB(sub__V15, 1)); int sub__V17_count = sub__V15_count*LINK_COUNT(sub__V17); permitUnusedInt(sub__V17_count);
      /* sub__V17 = &#0-1 */
      
      NamedPropertyLink namedP__V18 = LINK_NamedPropertyLink(sink__V11->context, NAMED_PROPERTIES(term__V12));
      VariablePropertyLink varP__V19 = LINK_VariablePropertyLink(sink__V11->context, VARIABLE_PROPERTIES(term__V12));
      Hashset namedFV__V20 = LINK_VARIABLESET(sink__V11->context, namedPropertyFreeVars(namedP__V18));
      Hashset varFV__V21 = LINK_VARIABLESET(sink__V11->context, variablePropertyFreeVars(varP__V19));
      UNLINK(sink__V11->context, term__V12);
      ADD_PROPERTIES(sink__V11, LINK_NamedPropertyLink(sink__V11->context, namedP__V18), LINK_VariablePropertyLink(sink__V11->context, varP__V19));
      { START(sink__V11, _M_X_Declarations_s1);
        COPY(sink__V11, sub__V16);COPY(sink__V11, sub__V17);END(sink__V11, _M_X_Declarations_s1); }
      UNLINK_VARIABLESET(sink__V11->context, namedFV__V20); UNLINK_VARIABLESET(sink__V11->context, varFV__V21);
      UNLINK_NamedPropertyLink(sink__V11->context, namedP__V18); UNLINK_VariablePropertyLink(sink__V11->context, varP__V19);
      
      return 1;
    break; } case Data_M__sNil: { /* Function SYMBOLS-X-Declarations-2$X-Declarations$$Nil case $Nil */
      ASSERT(sink__V11->context, !strcmp(SYMBOL(term__V12),  "X-Declarations" ));
      Term sub__V22 = SUB(term__V12, 0); permitUnusedTerm(sub__V22); int sub__V22_count = term__V12_count*LINK_COUNT(sub__V22); permitUnusedInt(sub__V22_count);
      ASSERT(sink__V11->context, !strcmp(SYMBOL(sub__V22),  "$Nil" ));
      
      NamedPropertyLink namedP__V23 = LINK_NamedPropertyLink(sink__V11->context, NAMED_PROPERTIES(term__V12));
      VariablePropertyLink varP__V24 = LINK_VariablePropertyLink(sink__V11->context, VARIABLE_PROPERTIES(term__V12));
      Hashset namedFV__V25 = LINK_VARIABLESET(sink__V11->context, namedPropertyFreeVars(namedP__V23));
      Hashset varFV__V26 = LINK_VARIABLESET(sink__V11->context, variablePropertyFreeVars(varP__V24));
      UNLINK(sink__V11->context, term__V12);
      ADD_PROPERTIES(sink__V11, LINK_NamedPropertyLink(sink__V11->context, namedP__V23), LINK_VariablePropertyLink(sink__V11->context, varP__V24));
      { START(sink__V11, _M_X_Declarations_s2);
        END(sink__V11, _M_X_Declarations_s2); }
      UNLINK_VARIABLESET(sink__V11->context, namedFV__V25); UNLINK_VARIABLESET(sink__V11->context, varFV__V26);
      UNLINK_NamedPropertyLink(sink__V11->context, namedP__V23); UNLINK_VariablePropertyLink(sink__V11->context, varP__V24);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION X-Declarations$1. */
int conBindOffs_M_X_Declarations_s1[] = {0 , 0 , 0};
char *nameFun_M_X_Declarations_s1(Term term) { return  "X-Declarations$1" ; }
struct _ConstructionDescriptor descriptor_M_X_Declarations_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_X_Declarations_s1), conBindOffs_M_X_Declarations_s1, &nameFun_M_X_Declarations_s1, &step_M_X_Declarations_s1};

int step_M_X_Declarations_s1(Sink sink__V27, Term term__V28)
{
  int term__V28_count = LINK_COUNT(term__V28); permitUnusedInt(term__V28_count);
  do {
    /* Contraction rule SYMBOLS-X-Declarations-1. */
    ASSERT(sink__V27->context, !strcmp(SYMBOL(term__V28),  "X-Declarations$1" ));
    Term sub__V29 = LINK(sink__V27->context, SUB(term__V28, 0)); int sub__V29_count = term__V28_count*LINK_COUNT(sub__V29); permitUnusedInt(sub__V29_count);
    /* sub__V29 = &#11 */
    Term sub__V30 = LINK(sink__V27->context, SUB(term__V28, 1)); int sub__V30_count = term__V28_count*LINK_COUNT(sub__V30); permitUnusedInt(sub__V30_count);
    /* sub__V30 = &#12 */
    
    NamedPropertyLink namedP__V31 = LINK_NamedPropertyLink(sink__V27->context, NAMED_PROPERTIES(term__V28));
    VariablePropertyLink varP__V32 = LINK_VariablePropertyLink(sink__V27->context, VARIABLE_PROPERTIES(term__V28));
    Hashset namedFV__V33 = LINK_VARIABLESET(sink__V27->context, namedPropertyFreeVars(namedP__V31));
    Hashset varFV__V34 = LINK_VARIABLESET(sink__V27->context, variablePropertyFreeVars(varP__V32));
    UNLINK(sink__V27->context, term__V28);
    { START(sink__V27, _M__sTextCons);
      { START(sink__V27, _M__sTextEmbed);
        { START(sink__V27, _M_AsText);
          { START(sink__V27, _M_X_Declaration);
            COPY(sink__V27, sub__V29);END(sink__V27, _M_X_Declaration); }
          END(sink__V27, _M_AsText); }
        END(sink__V27, _M__sTextEmbed); }
      { START(sink__V27, _M__sTextCons);
        { START(sink__V27, _M__sTextEmbed);
          { START(sink__V27, _M_AsText);
            { START(sink__V27, _M_X_Declarations);
              COPY(sink__V27, sub__V30);END(sink__V27, _M_X_Declarations); }
            END(sink__V27, _M_AsText); }
          END(sink__V27, _M__sTextEmbed); }
        { START(sink__V27, _M__sTextNil);
          END(sink__V27, _M__sTextNil); }
        END(sink__V27, _M__sTextCons); }
      END(sink__V27, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V27->context, namedFV__V33); UNLINK_VARIABLESET(sink__V27->context, varFV__V34);
    UNLINK_NamedPropertyLink(sink__V27->context, namedP__V31); UNLINK_VariablePropertyLink(sink__V27->context, varP__V32);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Declarations$2. */
int conBindOffs_M_X_Declarations_s2[] = {0};
char *nameFun_M_X_Declarations_s2(Term term) { return  "X-Declarations$2" ; }
struct _ConstructionDescriptor descriptor_M_X_Declarations_s2 = {&sort_M_Reified_xVariable, 0, 0, sizeof(STRUCT_Con_M_X_Declarations_s2), conBindOffs_M_X_Declarations_s2, &nameFun_M_X_Declarations_s2, &step_M_X_Declarations_s2};

int step_M_X_Declarations_s2(Sink sink__V35, Term term__V36)
{
  int term__V36_count = LINK_COUNT(term__V36); permitUnusedInt(term__V36_count);
  do {
    /* Contraction rule SYMBOLS-X-Declarations-2. */
    ASSERT(sink__V35->context, !strcmp(SYMBOL(term__V36),  "X-Declarations$2" ));
    
    NamedPropertyLink namedP__V37 = LINK_NamedPropertyLink(sink__V35->context, NAMED_PROPERTIES(term__V36));
    VariablePropertyLink varP__V38 = LINK_VariablePropertyLink(sink__V35->context, VARIABLE_PROPERTIES(term__V36));
    Hashset namedFV__V39 = LINK_VARIABLESET(sink__V35->context, namedPropertyFreeVars(namedP__V37));
    Hashset varFV__V40 = LINK_VARIABLESET(sink__V35->context, variablePropertyFreeVars(varP__V38));
    UNLINK(sink__V35->context, term__V36);
    { START(sink__V35, _M__sTextNil); END(sink__V35, _M__sTextNil); } UNLINK_VARIABLESET(sink__V35->context, namedFV__V39); UNLINK_VARIABLESET(sink__V35->context, varFV__V40);
    UNLINK_NamedPropertyLink(sink__V35->context, namedP__V37); UNLINK_VariablePropertyLink(sink__V35->context, varP__V38);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Form$2. */
int conBindOffs_M_X_Form_s2[] = {0 , 0 , 0};
char *nameFun_M_X_Form_s2(Term term) { return  "X-Form$2" ; }
struct _ConstructionDescriptor descriptor_M_X_Form_s2 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_X_Form_s2), conBindOffs_M_X_Form_s2, &nameFun_M_X_Form_s2, &step_M_X_Form_s2};

int step_M_X_Form_s2(Sink sink__V41, Term term__V42)
{
  int term__V42_count = LINK_COUNT(term__V42); permitUnusedInt(term__V42_count);
  Term sub__V43 = FORCE(sink__V41->context, SUB(term__V42, 0));
  EnumOf_M__sList choice__V44 = (IS_VARIABLE_USE(sub__V43) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V43));
  switch (choice__V44)
  {
    case Data_M__sNil: { /* Function SYMBOLS-X-Form-3$X-Form$2$$Nil case $Nil */
      ASSERT(sink__V41->context, !strcmp(SYMBOL(term__V42),  "X-Form$2" ));
      Term sub__V45 = SUB(term__V42, 0); permitUnusedTerm(sub__V45); int sub__V45_count = term__V42_count*LINK_COUNT(sub__V45); permitUnusedInt(sub__V45_count);
      ASSERT(sink__V41->context, !strcmp(SYMBOL(sub__V45),  "$Nil" ));
      Term sub__V46 = LINK(sink__V41->context, SUB(term__V42, 1)); int sub__V46_count = term__V42_count*LINK_COUNT(sub__V46); permitUnusedInt(sub__V46_count);
      /* sub__V46 = &#0 */
      
      NamedPropertyLink namedP__V47 = LINK_NamedPropertyLink(sink__V41->context, NAMED_PROPERTIES(term__V42));
      VariablePropertyLink varP__V48 = LINK_VariablePropertyLink(sink__V41->context, VARIABLE_PROPERTIES(term__V42));
      Hashset namedFV__V49 = LINK_VARIABLESET(sink__V41->context, namedPropertyFreeVars(namedP__V47));
      Hashset varFV__V50 = LINK_VARIABLESET(sink__V41->context, variablePropertyFreeVars(varP__V48));
      UNLINK(sink__V41->context, term__V42);
      ADD_PROPERTIES(sink__V41, LINK_NamedPropertyLink(sink__V41->context, namedP__V47), LINK_VariablePropertyLink(sink__V41->context, varP__V48));
      { START(sink__V41, _M_X_Form_s4);
        COPY(sink__V41, sub__V46);END(sink__V41, _M_X_Form_s4); }
      UNLINK_VARIABLESET(sink__V41->context, namedFV__V49); UNLINK_VARIABLESET(sink__V41->context, varFV__V50);
      UNLINK_NamedPropertyLink(sink__V41->context, namedP__V47); UNLINK_VariablePropertyLink(sink__V41->context, varP__V48);
      
      return 1;
    break; } case Data_M__sCons: { /* Function SYMBOLS-X-Form-4$X-Form$2$$Cons case $Cons */
      ASSERT(sink__V41->context, !strcmp(SYMBOL(term__V42),  "X-Form$2" ));
      Term sub__V51 = SUB(term__V42, 0); permitUnusedTerm(sub__V51); int sub__V51_count = term__V42_count*LINK_COUNT(sub__V51); permitUnusedInt(sub__V51_count);
      ASSERT(sink__V41->context, !strcmp(SYMBOL(sub__V51),  "$Cons" ));
      Term sub__V52 = LINK(sink__V41->context, SUB(sub__V51, 0)); int sub__V52_count = sub__V51_count*LINK_COUNT(sub__V52); permitUnusedInt(sub__V52_count);
      /* sub__V52 = &#0-0 */
      Term sub__V53 = LINK(sink__V41->context, SUB(sub__V51, 1)); int sub__V53_count = sub__V51_count*LINK_COUNT(sub__V53); permitUnusedInt(sub__V53_count);
      /* sub__V53 = &#0-1 */
      Term sub__V54 = LINK(sink__V41->context, SUB(term__V42, 1)); int sub__V54_count = term__V42_count*LINK_COUNT(sub__V54); permitUnusedInt(sub__V54_count);
      /* sub__V54 = &#2 */
      
      NamedPropertyLink namedP__V55 = LINK_NamedPropertyLink(sink__V41->context, NAMED_PROPERTIES(term__V42));
      VariablePropertyLink varP__V56 = LINK_VariablePropertyLink(sink__V41->context, VARIABLE_PROPERTIES(term__V42));
      Hashset namedFV__V57 = LINK_VARIABLESET(sink__V41->context, namedPropertyFreeVars(namedP__V55));
      Hashset varFV__V58 = LINK_VARIABLESET(sink__V41->context, variablePropertyFreeVars(varP__V56));
      UNLINK(sink__V41->context, term__V42);
      ADD_PROPERTIES(sink__V41, LINK_NamedPropertyLink(sink__V41->context, namedP__V55), LINK_VariablePropertyLink(sink__V41->context, varP__V56));
      { START(sink__V41, _M_X_Form_s3);
        COPY(sink__V41, sub__V52);COPY(sink__V41, sub__V53);COPY(sink__V41, sub__V54);END(sink__V41, _M_X_Form_s3); }
      UNLINK_VARIABLESET(sink__V41->context, namedFV__V57); UNLINK_VARIABLESET(sink__V41->context, varFV__V58);
      UNLINK_NamedPropertyLink(sink__V41->context, namedP__V55); UNLINK_VariablePropertyLink(sink__V41->context, varP__V56);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION X-Form$3. */
int conBindOffs_M_X_Form_s3[] = {0 , 0 , 0 , 0};
char *nameFun_M_X_Form_s3(Term term) { return  "X-Form$3" ; }
struct _ConstructionDescriptor descriptor_M_X_Form_s3 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_X_Form_s3), conBindOffs_M_X_Form_s3, &nameFun_M_X_Form_s3, &step_M_X_Form_s3};

int step_M_X_Form_s3(Sink sink__V59, Term term__V60)
{
  int term__V60_count = LINK_COUNT(term__V60); permitUnusedInt(term__V60_count);
  do {
    /* Contraction rule SYMBOLS-X-Form-4. */
    ASSERT(sink__V59->context, !strcmp(SYMBOL(term__V60),  "X-Form$3" ));
    Term sub__V61 = SUB(term__V60, 0); permitUnusedTerm(sub__V61); int sub__V61_count = term__V60_count*LINK_COUNT(sub__V61); permitUnusedInt(sub__V61_count);
    /* sub__V61 = &#121 */
    Term sub__V62 = SUB(term__V60, 1); permitUnusedTerm(sub__V62); int sub__V62_count = term__V60_count*LINK_COUNT(sub__V62); permitUnusedInt(sub__V62_count);
    /* sub__V62 = &#122 */
    Term sub__V63 = LINK(sink__V59->context, SUB(term__V60, 2)); int sub__V63_count = term__V60_count*LINK_COUNT(sub__V63); permitUnusedInt(sub__V63_count);
    UNLINK_SUB(sink__V59->context, term__V60,  2); NORMALIZE(sink__V59->context, sub__V63); SUB(term__V60,  2) = LINK(sink__V59->context, sub__V63);
    /* sub__V63 = &#11 */
    
    NamedPropertyLink namedP__V64 = LINK_NamedPropertyLink(sink__V59->context, NAMED_PROPERTIES(term__V60));
    VariablePropertyLink varP__V65 = LINK_VariablePropertyLink(sink__V59->context, VARIABLE_PROPERTIES(term__V60));
    Hashset namedFV__V66 = LINK_VARIABLESET(sink__V59->context, namedPropertyFreeVars(namedP__V64));
    Hashset varFV__V67 = LINK_VARIABLESET(sink__V59->context, variablePropertyFreeVars(varP__V65));
    UNLINK(sink__V59->context, term__V60);
    { START(sink__V59, _M__sTextCons);
      { START(sink__V59, _M__sTextBreak);
        LITERAL(sink__V59,  "\n" ); END(sink__V59, _M__sTextBreak); }
      { START(sink__V59, _M__sTextCons);
        { START(sink__V59, _M__sTextChars);
          LITERAL(sink__V59,  "{" ); END(sink__V59, _M__sTextChars); }
        { START(sink__V59, _M__sTextCons);
          { START(sink__V59, _M__sTextEmbed);
            { START(sink__V59, _M_AsText);
              { START(sink__V59, _M_STRING);
                COPY(sink__V59, LINK(sink__V59->context, sub__V63));END(sink__V59, _M_STRING); }
              END(sink__V59, _M_AsText); }
            END(sink__V59, _M__sTextEmbed); }
          { START(sink__V59, _M__sTextCons);
            { START(sink__V59, _M__sTextChars);
              LITERAL(sink__V59,  ", &" ); END(sink__V59, _M__sTextChars); }
            { START(sink__V59, _M__sTextCons);
              { START(sink__V59, _M__sTextEmbed);
                { START(sink__V59, _M_AsText);
                  { START(sink__V59, _M_Descriptor);
                    COPY(sink__V59, sub__V63);END(sink__V59, _M_Descriptor); }
                  END(sink__V59, _M_AsText); }
                END(sink__V59, _M__sTextEmbed); }
              { START(sink__V59, _M__sTextCons);
                { START(sink__V59, _M__sTextChars);
                  LITERAL(sink__V59,  "}," ); END(sink__V59, _M__sTextChars); }
                { START(sink__V59, _M__sTextNil);
                  END(sink__V59, _M__sTextNil); }
                END(sink__V59, _M__sTextCons); }
              END(sink__V59, _M__sTextCons); }
            END(sink__V59, _M__sTextCons); }
          END(sink__V59, _M__sTextCons); }
        END(sink__V59, _M__sTextCons); }
      END(sink__V59, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V59->context, namedFV__V66); UNLINK_VARIABLESET(sink__V59->context, varFV__V67);
    UNLINK_NamedPropertyLink(sink__V59->context, namedP__V64); UNLINK_VariablePropertyLink(sink__V59->context, varP__V65);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Form$4. */
int conBindOffs_M_X_Form_s4[] = {0 , 0};
char *nameFun_M_X_Form_s4(Term term) { return  "X-Form$4" ; }
struct _ConstructionDescriptor descriptor_M_X_Form_s4 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_X_Form_s4), conBindOffs_M_X_Form_s4, &nameFun_M_X_Form_s4, &step_M_X_Form_s4};

int step_M_X_Form_s4(Sink sink__V68, Term term__V69)
{
  int term__V69_count = LINK_COUNT(term__V69); permitUnusedInt(term__V69_count);
  do {
    /* Contraction rule SYMBOLS-X-Form-3. */
    ASSERT(sink__V68->context, !strcmp(SYMBOL(term__V69),  "X-Form$4" ));
    Term sub__V70 = LINK(sink__V68->context, SUB(term__V69, 0)); int sub__V70_count = term__V69_count*LINK_COUNT(sub__V70); permitUnusedInt(sub__V70_count);
    UNLINK_SUB(sink__V68->context, term__V69,  0); NORMALIZE(sink__V68->context, sub__V70); SUB(term__V69,  0) = LINK(sink__V68->context, sub__V70);
    /* sub__V70 = &#11 */
    
    NamedPropertyLink namedP__V71 = LINK_NamedPropertyLink(sink__V68->context, NAMED_PROPERTIES(term__V69));
    VariablePropertyLink varP__V72 = LINK_VariablePropertyLink(sink__V68->context, VARIABLE_PROPERTIES(term__V69));
    Hashset namedFV__V73 = LINK_VARIABLESET(sink__V68->context, namedPropertyFreeVars(namedP__V71));
    Hashset varFV__V74 = LINK_VARIABLESET(sink__V68->context, variablePropertyFreeVars(varP__V72));
    UNLINK(sink__V68->context, term__V69);
    { START(sink__V68, _M__sTextCons);
      { START(sink__V68, _M__sTextBreak);
        LITERAL(sink__V68,  "\n" ); END(sink__V68, _M__sTextBreak); }
      { START(sink__V68, _M__sTextCons);
        { START(sink__V68, _M__sTextChars);
          LITERAL(sink__V68,  "{" ); END(sink__V68, _M__sTextChars); }
        { START(sink__V68, _M__sTextCons);
          { START(sink__V68, _M__sTextEmbed);
            { START(sink__V68, _M_AsText);
              { START(sink__V68, _M_STRING);
                COPY(sink__V68, LINK(sink__V68->context, sub__V70));END(sink__V68, _M_STRING); }
              END(sink__V68, _M_AsText); }
            END(sink__V68, _M__sTextEmbed); }
          { START(sink__V68, _M__sTextCons);
            { START(sink__V68, _M__sTextChars);
              LITERAL(sink__V68,  ", &" ); END(sink__V68, _M__sTextChars); }
            { START(sink__V68, _M__sTextCons);
              { START(sink__V68, _M__sTextEmbed);
                { START(sink__V68, _M_AsText);
                  { START(sink__V68, _M_Descriptor);
                    COPY(sink__V68, sub__V70);END(sink__V68, _M_Descriptor); }
                  END(sink__V68, _M_AsText); }
                END(sink__V68, _M__sTextEmbed); }
              { START(sink__V68, _M__sTextCons);
                { START(sink__V68, _M__sTextChars);
                  LITERAL(sink__V68,  "}," ); END(sink__V68, _M__sTextChars); }
                { START(sink__V68, _M__sTextNil);
                  END(sink__V68, _M__sTextNil); }
                END(sink__V68, _M__sTextCons); }
              END(sink__V68, _M__sTextCons); }
            END(sink__V68, _M__sTextCons); }
          END(sink__V68, _M__sTextCons); }
        END(sink__V68, _M__sTextCons); }
      END(sink__V68, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V68->context, namedFV__V73); UNLINK_VARIABLESET(sink__V68->context, varFV__V74);
    UNLINK_NamedPropertyLink(sink__V68->context, namedP__V71); UNLINK_VariablePropertyLink(sink__V68->context, varP__V72);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Form$5. */
int conBindOffs_M_X_Form_s5[] = {0};
char *nameFun_M_X_Form_s5(Term term) { return  "X-Form$5" ; }
struct _ConstructionDescriptor descriptor_M_X_Form_s5 = {&sort_M_Reified_xVariable, 0, 0, sizeof(STRUCT_Con_M_X_Form_s5), conBindOffs_M_X_Form_s5, &nameFun_M_X_Form_s5, &step_M_X_Form_s5};

int step_M_X_Form_s5(Sink sink__V75, Term term__V76)
{
  int term__V76_count = LINK_COUNT(term__V76); permitUnusedInt(term__V76_count);
  do {
    /* Contraction rule SYMBOLS-X-Form-2. */
    ASSERT(sink__V75->context, !strcmp(SYMBOL(term__V76),  "X-Form$5" ));
    
    NamedPropertyLink namedP__V77 = LINK_NamedPropertyLink(sink__V75->context, NAMED_PROPERTIES(term__V76));
    VariablePropertyLink varP__V78 = LINK_VariablePropertyLink(sink__V75->context, VARIABLE_PROPERTIES(term__V76));
    Hashset namedFV__V79 = LINK_VARIABLESET(sink__V75->context, namedPropertyFreeVars(namedP__V77));
    Hashset varFV__V80 = LINK_VARIABLESET(sink__V75->context, variablePropertyFreeVars(varP__V78));
    UNLINK(sink__V75->context, term__V76);
    { START(sink__V75, _M__sTextNil); END(sink__V75, _M__sTextNil); } UNLINK_VARIABLESET(sink__V75->context, namedFV__V79); UNLINK_VARIABLESET(sink__V75->context, varFV__V80);
    UNLINK_NamedPropertyLink(sink__V75->context, namedP__V77); UNLINK_VariablePropertyLink(sink__V75->context, varP__V78);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Form$6. */
int conBindOffs_M_X_Form_s6[] = {0 , 0 , 0 , 0};
char *nameFun_M_X_Form_s6(Term term) { return  "X-Form$6" ; }
struct _ConstructionDescriptor descriptor_M_X_Form_s6 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_X_Form_s6), conBindOffs_M_X_Form_s6, &nameFun_M_X_Form_s6, &step_M_X_Form_s6};

int step_M_X_Form_s6(Sink sink__V81, Term term__V82)
{
  int term__V82_count = LINK_COUNT(term__V82); permitUnusedInt(term__V82_count);
  do {
    /* Contraction rule SYMBOLS-X-Form-1. */
    ASSERT(sink__V81->context, !strcmp(SYMBOL(term__V82),  "X-Form$6" ));
    Term sub__V83 = SUB(term__V82, 0); permitUnusedTerm(sub__V83); int sub__V83_count = term__V82_count*LINK_COUNT(sub__V83); permitUnusedInt(sub__V83_count);
    CRSX_CHECK_SORT(sink__V81->context, sub__V83, &sort_M_Reified_xSort); /* sub__V83 = &#11 */
    Term sub__V84 = SUB(term__V82, 1); permitUnusedTerm(sub__V84); int sub__V84_count = term__V82_count*LINK_COUNT(sub__V84); permitUnusedInt(sub__V84_count);
    CRSX_CHECK_SORT(sink__V81->context, sub__V84, &sort_M_Reified_xSort); /* sub__V84 = &#12 */
    Term sub__V85 = LINK(sink__V81->context, SUB(term__V82, 2)); int sub__V85_count = term__V82_count*LINK_COUNT(sub__V85); permitUnusedInt(sub__V85_count);
    CRSX_CHECK_SORT(sink__V81->context, sub__V85, &sort_M_Reified_xForm); /* sub__V85 = &#13 */
    
    NamedPropertyLink namedP__V86 = LINK_NamedPropertyLink(sink__V81->context, NAMED_PROPERTIES(term__V82));
    VariablePropertyLink varP__V87 = LINK_VariablePropertyLink(sink__V81->context, VARIABLE_PROPERTIES(term__V82));
    Hashset namedFV__V88 = LINK_VARIABLESET(sink__V81->context, namedPropertyFreeVars(namedP__V86));
    Hashset varFV__V89 = LINK_VARIABLESET(sink__V81->context, variablePropertyFreeVars(varP__V87));
    UNLINK(sink__V81->context, term__V82);
    { START(sink__V81, _M_X_Form);
      COPY(sink__V81, sub__V85);END(sink__V81, _M_X_Form); }
    UNLINK_VARIABLESET(sink__V81->context, namedFV__V88); UNLINK_VARIABLESET(sink__V81->context, varFV__V89);
    UNLINK_NamedPropertyLink(sink__V81->context, namedP__V86); UNLINK_VariablePropertyLink(sink__V81->context, varP__V87);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Data$1. */
int conBindOffs_M_X_Data_s1[] = {0 , 0 , 0 , 0};
char *nameFun_M_X_Data_s1(Term term) { return  "X-Data$1" ; }
struct _ConstructionDescriptor descriptor_M_X_Data_s1 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_X_Data_s1), conBindOffs_M_X_Data_s1, &nameFun_M_X_Data_s1, &step_M_X_Data_s1};

int step_M_X_Data_s1(Sink sink__V90, Term term__V91)
{
  int term__V91_count = LINK_COUNT(term__V91); permitUnusedInt(term__V91_count);
  do {
    /* Contraction rule SYMBOLS-X-Data-1. */
    ASSERT(sink__V90->context, !strcmp(SYMBOL(term__V91),  "X-Data$1" ));
    Term sub__V92 = SUB(term__V91, 0); permitUnusedTerm(sub__V92); int sub__V92_count = term__V91_count*LINK_COUNT(sub__V92); permitUnusedInt(sub__V92_count);
    /* sub__V92 = &#11 */
    Term sub__V93 = SUB(term__V91, 1); permitUnusedTerm(sub__V93); int sub__V93_count = term__V91_count*LINK_COUNT(sub__V93); permitUnusedInt(sub__V93_count);
    /* sub__V93 = &#12 */
    Term sub__V94 = LINK(sink__V90->context, SUB(term__V91, 2)); int sub__V94_count = term__V91_count*LINK_COUNT(sub__V94); permitUnusedInt(sub__V94_count);
    /* sub__V94 = &#2 */
    
    NamedPropertyLink namedP__V95 = LINK_NamedPropertyLink(sink__V90->context, NAMED_PROPERTIES(term__V91));
    VariablePropertyLink varP__V96 = LINK_VariablePropertyLink(sink__V90->context, VARIABLE_PROPERTIES(term__V91));
    Hashset namedFV__V97 = LINK_VARIABLESET(sink__V90->context, namedPropertyFreeVars(namedP__V95));
    Hashset varFV__V98 = LINK_VARIABLESET(sink__V90->context, variablePropertyFreeVars(varP__V96));
    UNLINK(sink__V90->context, term__V91);
    { START(sink__V90, _M__sTextCons);
      { START(sink__V90, _M__sTextEmbed);
        { START(sink__V90, _M_AsText);
          { START(sink__V90, _M_MapText_s1);
            COPY(sink__V90, sub__V94);{ Variable x__V99 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V90->context,"x__V99");
              Variable binds__V100[1] = {x__V99}; BINDS(sink__V90, 1, binds__V100);
              { START(sink__V90, _M_X_Form);
                USE(sink__V90, x__V99); END(sink__V90, _M_X_Form); }
               }
            END(sink__V90, _M_MapText_s1); }
          END(sink__V90, _M_AsText); }
        END(sink__V90, _M__sTextEmbed); }
      { START(sink__V90, _M__sTextNil); END(sink__V90, _M__sTextNil); }
      END(sink__V90, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V90->context, namedFV__V97); UNLINK_VARIABLESET(sink__V90->context, varFV__V98);
    UNLINK_NamedPropertyLink(sink__V90->context, namedP__V95); UNLINK_VariablePropertyLink(sink__V90->context, varP__V96);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Data$2. */
int conBindOffs_M_X_Data_s2[] = {0 , 0 , 0 , 0 , 0};
char *nameFun_M_X_Data_s2(Term term) { return  "X-Data$2" ; }
struct _ConstructionDescriptor descriptor_M_X_Data_s2 = {&sort_M_Reified_xVariable, 0, 4, sizeof(STRUCT_Con_M_X_Data_s2), conBindOffs_M_X_Data_s2, &nameFun_M_X_Data_s2, &step_M_X_Data_s2};

int step_M_X_Data_s2(Sink sink__V101, Term term__V102)
{
  int term__V102_count = LINK_COUNT(term__V102); permitUnusedInt(term__V102_count);
  do {
    /* Contraction rule SYMBOLS-X-Data-2. */
    ASSERT(sink__V101->context, !strcmp(SYMBOL(term__V102),  "X-Data$2" ));
    Term sub__V103 = SUB(term__V102, 0); permitUnusedTerm(sub__V103); int sub__V103_count = term__V102_count*LINK_COUNT(sub__V103); permitUnusedInt(sub__V103_count);
    CRSX_CHECK_SORT(sink__V101->context, sub__V103, &sort_M_Reified_xSort); /* sub__V103 = &#11 */
    Term sub__V104 = SUB(term__V102, 1); permitUnusedTerm(sub__V104); int sub__V104_count = term__V102_count*LINK_COUNT(sub__V104); permitUnusedInt(sub__V104_count);
    CRSX_CHECK_SORT(sink__V101->context, sub__V104, &sort_M_Reified_xSort); /* sub__V104 = &#12 */
    Term sub__V105 = LINK(sink__V101->context, SUB(term__V102, 2)); int sub__V105_count = term__V102_count*LINK_COUNT(sub__V105); permitUnusedInt(sub__V105_count);
    CRSX_CHECK_SORT(sink__V101->context, sub__V105, &sort_M_Reified_xSort); /* sub__V105 = &#13 */
    Term sub__V106 = LINK(sink__V101->context, SUB(term__V102, 3)); int sub__V106_count = term__V102_count*LINK_COUNT(sub__V106); permitUnusedInt(sub__V106_count);
    /* sub__V106 = &#2 */
    
    NamedPropertyLink namedP__V107 = LINK_NamedPropertyLink(sink__V101->context, NAMED_PROPERTIES(term__V102));
    VariablePropertyLink varP__V108 = LINK_VariablePropertyLink(sink__V101->context, VARIABLE_PROPERTIES(term__V102));
    Hashset namedFV__V109 = LINK_VARIABLESET(sink__V101->context, namedPropertyFreeVars(namedP__V107));
    Hashset varFV__V110 = LINK_VARIABLESET(sink__V101->context, variablePropertyFreeVars(varP__V108));
    UNLINK(sink__V101->context, term__V102);
    { START(sink__V101, _M_X_Data);
      COPY(sink__V101, sub__V105);COPY(sink__V101, sub__V106);END(sink__V101, _M_X_Data); }
    UNLINK_VARIABLESET(sink__V101->context, namedFV__V109); UNLINK_VARIABLESET(sink__V101->context, varFV__V110);
    UNLINK_NamedPropertyLink(sink__V101->context, namedP__V107); UNLINK_VariablePropertyLink(sink__V101->context, varP__V108);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Form. */
int conBindOffs_M_X_Form[] = {0 , 0};
char *nameFun_M_X_Form(Term term) { return  "X-Form" ; }
struct _ConstructionDescriptor descriptor_M_X_Form = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_X_Form), conBindOffs_M_X_Form, &nameFun_M_X_Form, &step_M_X_Form};

int step_M_X_Form(Sink sink__V111, Term term__V112)
{
  int term__V112_count = LINK_COUNT(term__V112); permitUnusedInt(term__V112_count);
  Term sub__V113 = FORCE(sink__V111->context, SUB(term__V112, 0));
  EnumOf_M_Reified_xForm choice__V114 = (IS_VARIABLE_USE(sub__V113) ? VarOf_M_Reified_xForm : (EnumOf_M_Reified_xForm) TAG(sub__V113));
  switch (choice__V114)
  {
    case Data_M_SORT_SET: { /* Function SYMBOLS-X-Form-1$X-Form$SORT-SET case SORT-SET */
      ASSERT(sink__V111->context, !strcmp(SYMBOL(term__V112),  "X-Form" ));
      Term sub__V115 = SUB(term__V112, 0); permitUnusedTerm(sub__V115); int sub__V115_count = term__V112_count*LINK_COUNT(sub__V115); permitUnusedInt(sub__V115_count);
      CRSX_CHECK_SORT(sink__V111->context, sub__V115, &sort_M_Reified_xForm); ASSERT(sink__V111->context, !strcmp(SYMBOL(sub__V115),  "SORT-SET" ));
      Term sub__V116 = LINK(sink__V111->context, SUB(sub__V115, 0)); int sub__V116_count = sub__V115_count*LINK_COUNT(sub__V116); permitUnusedInt(sub__V116_count);
      CRSX_CHECK_SORT(sink__V111->context, sub__V116, &sort_M_Reified_xSort); /* sub__V116 = &#0-0 */
      Term sub__V117 = LINK(sink__V111->context, SUB(sub__V115, 1)); int sub__V117_count = sub__V115_count*LINK_COUNT(sub__V117); permitUnusedInt(sub__V117_count);
      CRSX_CHECK_SORT(sink__V111->context, sub__V117, &sort_M_Reified_xSort); /* sub__V117 = &#0-1 */
      Term sub__V118 = LINK(sink__V111->context, SUB(sub__V115, 2)); int sub__V118_count = sub__V115_count*LINK_COUNT(sub__V118); permitUnusedInt(sub__V118_count);
      CRSX_CHECK_SORT(sink__V111->context, sub__V118, &sort_M_Reified_xForm); /* sub__V118 = &#0-2 */
      
      NamedPropertyLink namedP__V119 = LINK_NamedPropertyLink(sink__V111->context, NAMED_PROPERTIES(term__V112));
      VariablePropertyLink varP__V120 = LINK_VariablePropertyLink(sink__V111->context, VARIABLE_PROPERTIES(term__V112));
      Hashset namedFV__V121 = LINK_VARIABLESET(sink__V111->context, namedPropertyFreeVars(namedP__V119));
      Hashset varFV__V122 = LINK_VARIABLESET(sink__V111->context, variablePropertyFreeVars(varP__V120));
      UNLINK(sink__V111->context, term__V112);
      ADD_PROPERTIES(sink__V111, LINK_NamedPropertyLink(sink__V111->context, namedP__V119), LINK_VariablePropertyLink(sink__V111->context, varP__V120));
      { START(sink__V111, _M_X_Form_s6);
        COPY(sink__V111, sub__V116);COPY(sink__V111, sub__V117);COPY(sink__V111, sub__V118);END(sink__V111, _M_X_Form_s6); }
      UNLINK_VARIABLESET(sink__V111->context, namedFV__V121); UNLINK_VARIABLESET(sink__V111->context, varFV__V122);
      UNLINK_NamedPropertyLink(sink__V111->context, namedP__V119); UNLINK_VariablePropertyLink(sink__V111->context, varP__V120);
      
      return 1;
    break; } case Data_M_SORT_ALLOWS_VARIABLES: { /* Function SYMBOLS-X-Form-2$X-Form$SORT-ALLOWS-VARIABLES case SORT-ALLOWS-VARIABLES */
      ASSERT(sink__V111->context, !strcmp(SYMBOL(term__V112),  "X-Form" ));
      Term sub__V123 = SUB(term__V112, 0); permitUnusedTerm(sub__V123); int sub__V123_count = term__V112_count*LINK_COUNT(sub__V123); permitUnusedInt(sub__V123_count);
      CRSX_CHECK_SORT(sink__V111->context, sub__V123, &sort_M_Reified_xForm); ASSERT(sink__V111->context, !strcmp(SYMBOL(sub__V123),  "SORT-ALLOWS-VARIABLES" ));
      
      NamedPropertyLink namedP__V124 = LINK_NamedPropertyLink(sink__V111->context, NAMED_PROPERTIES(term__V112));
      VariablePropertyLink varP__V125 = LINK_VariablePropertyLink(sink__V111->context, VARIABLE_PROPERTIES(term__V112));
      Hashset namedFV__V126 = LINK_VARIABLESET(sink__V111->context, namedPropertyFreeVars(namedP__V124));
      Hashset varFV__V127 = LINK_VARIABLESET(sink__V111->context, variablePropertyFreeVars(varP__V125));
      UNLINK(sink__V111->context, term__V112);
      ADD_PROPERTIES(sink__V111, LINK_NamedPropertyLink(sink__V111->context, namedP__V124), LINK_VariablePropertyLink(sink__V111->context, varP__V125));
      { START(sink__V111, _M_X_Form_s5);
        END(sink__V111, _M_X_Form_s5); }
      UNLINK_VARIABLESET(sink__V111->context, namedFV__V126); UNLINK_VARIABLESET(sink__V111->context, varFV__V127);
      UNLINK_NamedPropertyLink(sink__V111->context, namedP__V124); UNLINK_VariablePropertyLink(sink__V111->context, varP__V125);
      
      return 1;
    break; } case Data_M_FORM: { /* Function SYMBOLS-X-Form-4$X-Form$FORM case FORM */
      ASSERT(sink__V111->context, !strcmp(SYMBOL(term__V112),  "X-Form" ));
      Term sub__V128 = SUB(term__V112, 0); permitUnusedTerm(sub__V128); int sub__V128_count = term__V112_count*LINK_COUNT(sub__V128); permitUnusedInt(sub__V128_count);
      CRSX_CHECK_SORT(sink__V111->context, sub__V128, &sort_M_Reified_xForm); ASSERT(sink__V111->context, !strcmp(SYMBOL(sub__V128),  "FORM" ));
      Term sub__V129 = LINK(sink__V111->context, SUB(sub__V128, 0)); int sub__V129_count = sub__V128_count*LINK_COUNT(sub__V129); permitUnusedInt(sub__V129_count);
      /* sub__V129 = &#0-0 */
      Term sub__V130 = LINK(sink__V111->context, SUB(sub__V128, 1)); int sub__V130_count = sub__V128_count*LINK_COUNT(sub__V130); permitUnusedInt(sub__V130_count);
      /* sub__V130 = &#0-1 */
      
      NamedPropertyLink namedP__V131 = LINK_NamedPropertyLink(sink__V111->context, NAMED_PROPERTIES(term__V112));
      VariablePropertyLink varP__V132 = LINK_VariablePropertyLink(sink__V111->context, VARIABLE_PROPERTIES(term__V112));
      Hashset namedFV__V133 = LINK_VARIABLESET(sink__V111->context, namedPropertyFreeVars(namedP__V131));
      Hashset varFV__V134 = LINK_VARIABLESET(sink__V111->context, variablePropertyFreeVars(varP__V132));
      UNLINK(sink__V111->context, term__V112);
      ADD_PROPERTIES(sink__V111, LINK_NamedPropertyLink(sink__V111->context, namedP__V131), LINK_VariablePropertyLink(sink__V111->context, varP__V132));
      { START(sink__V111, _M_X_Form_s2);
        COPY(sink__V111, sub__V130);COPY(sink__V111, sub__V129);END(sink__V111, _M_X_Form_s2); }
      UNLINK_VARIABLESET(sink__V111->context, namedFV__V133); UNLINK_VARIABLESET(sink__V111->context, varFV__V134);
      UNLINK_NamedPropertyLink(sink__V111->context, namedP__V131); UNLINK_VariablePropertyLink(sink__V111->context, varP__V132);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION X-Declaration$1. */
int conBindOffs_M_X_Declaration_s1[] = {0 , 0 , 0};
char *nameFun_M_X_Declaration_s1(Term term) { return  "X-Declaration$1" ; }
struct _ConstructionDescriptor descriptor_M_X_Declaration_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_X_Declaration_s1), conBindOffs_M_X_Declaration_s1, &nameFun_M_X_Declaration_s1, &step_M_X_Declaration_s1};

int step_M_X_Declaration_s1(Sink sink__V135, Term term__V136)
{
  int term__V136_count = LINK_COUNT(term__V136); permitUnusedInt(term__V136_count);
  do {
    /* Contraction rule SYMBOLS-Data. */
    ASSERT(sink__V135->context, !strcmp(SYMBOL(term__V136),  "X-Declaration$1" ));
    Term sub__V137 = LINK(sink__V135->context, SUB(term__V136, 0)); int sub__V137_count = term__V136_count*LINK_COUNT(sub__V137); permitUnusedInt(sub__V137_count);
    CRSX_CHECK_SORT(sink__V135->context, sub__V137, &sort_M_Reified_xSort); /* sub__V137 = &#11 */
    Term sub__V138 = LINK(sink__V135->context, SUB(term__V136, 1)); int sub__V138_count = term__V136_count*LINK_COUNT(sub__V138); permitUnusedInt(sub__V138_count);
    /* sub__V138 = &#12 */
    
    NamedPropertyLink namedP__V139 = LINK_NamedPropertyLink(sink__V135->context, NAMED_PROPERTIES(term__V136));
    VariablePropertyLink varP__V140 = LINK_VariablePropertyLink(sink__V135->context, VARIABLE_PROPERTIES(term__V136));
    Hashset namedFV__V141 = LINK_VARIABLESET(sink__V135->context, namedPropertyFreeVars(namedP__V139));
    Hashset varFV__V142 = LINK_VARIABLESET(sink__V135->context, variablePropertyFreeVars(varP__V140));
    UNLINK(sink__V135->context, term__V136);
    { START(sink__V135, _M_X_Data);
      COPY(sink__V135, sub__V137);COPY(sink__V135, sub__V138);END(sink__V135, _M_X_Data); }
    UNLINK_VARIABLESET(sink__V135->context, namedFV__V141); UNLINK_VARIABLESET(sink__V135->context, varFV__V142);
    UNLINK_NamedPropertyLink(sink__V135->context, namedP__V139); UNLINK_VariablePropertyLink(sink__V135->context, varP__V140);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Declaration$2. */
int conBindOffs_M_X_Declaration_s2[] = {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0};
char *nameFun_M_X_Declaration_s2(Term term) { return  "X-Declaration$2" ; }
struct _ConstructionDescriptor descriptor_M_X_Declaration_s2 = {&sort_M_Reified_xVariable, 0, 7, sizeof(STRUCT_Con_M_X_Declaration_s2), conBindOffs_M_X_Declaration_s2, &nameFun_M_X_Declaration_s2, &step_M_X_Declaration_s2};

int step_M_X_Declaration_s2(Sink sink__V143, Term term__V144)
{
  int term__V144_count = LINK_COUNT(term__V144); permitUnusedInt(term__V144_count);
  do {
    /* Contraction rule SYMBOLS-Function. */
    ASSERT(sink__V143->context, !strcmp(SYMBOL(term__V144),  "X-Declaration$2" ));
    Term sub__V145 = LINK(sink__V143->context, SUB(term__V144, 0)); int sub__V145_count = term__V144_count*LINK_COUNT(sub__V145); permitUnusedInt(sub__V145_count);
    /* sub__V145 = &#11 */
    Term sub__V146 = LINK(sink__V143->context, SUB(term__V144, 1)); int sub__V146_count = term__V144_count*LINK_COUNT(sub__V146); permitUnusedInt(sub__V146_count);
    /* sub__V146 = &#12 */
    Term sub__V147 = LINK(sink__V143->context, SUB(term__V144, 2)); int sub__V147_count = term__V144_count*LINK_COUNT(sub__V147); permitUnusedInt(sub__V147_count);
    /* sub__V147 = &#13 */
    Term sub__V148 = LINK(sink__V143->context, SUB(term__V144, 3)); int sub__V148_count = term__V144_count*LINK_COUNT(sub__V148); permitUnusedInt(sub__V148_count);
    /* sub__V148 = &#14 */
    Term sub__V149 = LINK(sink__V143->context, SUB(term__V144, 4)); int sub__V149_count = term__V144_count*LINK_COUNT(sub__V149); permitUnusedInt(sub__V149_count);
    /* sub__V149 = &#15 */
    Term sub__V150 = LINK(sink__V143->context, SUB(term__V144, 5)); int sub__V150_count = term__V144_count*LINK_COUNT(sub__V150); permitUnusedInt(sub__V150_count);
    CRSX_CHECK_SORT(sink__V143->context, sub__V150, &sort_M_Reified_xSort); /* sub__V150 = &#16 */
    Term sub__V151 = LINK(sink__V143->context, SUB(term__V144, 6)); int sub__V151_count = term__V144_count*LINK_COUNT(sub__V151); permitUnusedInt(sub__V151_count);
    /* sub__V151 = &#17 */
    
    NamedPropertyLink namedP__V152 = LINK_NamedPropertyLink(sink__V143->context, NAMED_PROPERTIES(term__V144));
    VariablePropertyLink varP__V153 = LINK_VariablePropertyLink(sink__V143->context, VARIABLE_PROPERTIES(term__V144));
    Hashset namedFV__V154 = LINK_VARIABLESET(sink__V143->context, namedPropertyFreeVars(namedP__V152));
    Hashset varFV__V155 = LINK_VARIABLESET(sink__V143->context, variablePropertyFreeVars(varP__V153));
    UNLINK(sink__V143->context, term__V144);
    { START(sink__V143, _M_X_Function);
      COPY(sink__V143, sub__V145);COPY(sink__V143, sub__V146);COPY(sink__V143, sub__V147);COPY(sink__V143, sub__V148);COPY(sink__V143, sub__V149);COPY(sink__V143, sub__V150);COPY(sink__V143, sub__V151);END(sink__V143, _M_X_Function); }
    UNLINK_VARIABLESET(sink__V143->context, namedFV__V154); UNLINK_VARIABLESET(sink__V143->context, varFV__V155);
    UNLINK_NamedPropertyLink(sink__V143->context, namedP__V152); UNLINK_VariablePropertyLink(sink__V143->context, varP__V153);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Declaration$3. */
int conBindOffs_M_X_Declaration_s3[] = {0 , 1};
char *nameFun_M_X_Declaration_s3(Term term) { return  "X-Declaration$3" ; }
struct _ConstructionDescriptor descriptor_M_X_Declaration_s3 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_X_Declaration_s3), conBindOffs_M_X_Declaration_s3, &nameFun_M_X_Declaration_s3, &step_M_X_Declaration_s3};

int step_M_X_Declaration_s3(Sink sink__V156, Term term__V157)
{
  int term__V157_count = LINK_COUNT(term__V157); permitUnusedInt(term__V157_count);
  do {
    /* Contraction rule SYMBOLS-Polymorphic. */
    ASSERT(sink__V156->context, !strcmp(SYMBOL(term__V157),  "X-Declaration$3" ));
    Variable x__V158 = BINDER(term__V157,0,0); if (term__V157_count <= 1) UNBIND(x__V158);
    Term sub__V159 = LINK(sink__V156->context, SUB(term__V157, 0)); int sub__V159_count = term__V157_count*LINK_COUNT(sub__V159); permitUnusedInt(sub__V159_count);
    CRSX_CHECK_SORT(sink__V156->context, sub__V159, &sort_M_Reified_xDeclaration); /* sub__V159 = &#11 */
    Variable y__V160 = x__V158; permitUnusedVariable(y__V160);
    
    NamedPropertyLink namedP__V161 = LINK_NamedPropertyLink(sink__V156->context, NAMED_PROPERTIES(term__V157));
    VariablePropertyLink varP__V162 = LINK_VariablePropertyLink(sink__V156->context, VARIABLE_PROPERTIES(term__V157));
    Hashset namedFV__V163 = LINK_VARIABLESET(sink__V156->context, namedPropertyFreeVars(namedP__V161));
    Hashset varFV__V164 = LINK_VARIABLESET(sink__V156->context, variablePropertyFreeVars(varP__V162));
    UNLINK(sink__V156->context, term__V157);
    { START(sink__V156, _M_X_Declaration);
      COPY(sink__V156, sub__V159); /* REUSED SUBSTITUTION */ END(sink__V156, _M_X_Declaration); }
    UNLINK_VARIABLESET(sink__V156->context, namedFV__V163); UNLINK_VARIABLESET(sink__V156->context, varFV__V164);
    UNLINK_NamedPropertyLink(sink__V156->context, namedP__V161); UNLINK_VariablePropertyLink(sink__V156->context, varP__V162);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION ComputeSymbols2. */
int conBindOffs_M_ComputeSymbols2[] = {0 , 0 , 0 , 0};
char *nameFun_M_ComputeSymbols2(Term term) { return  "ComputeSymbols2" ; }
struct _ConstructionDescriptor descriptor_M_ComputeSymbols2 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_ComputeSymbols2), conBindOffs_M_ComputeSymbols2, &nameFun_M_ComputeSymbols2, &step_M_ComputeSymbols2};

int step_M_ComputeSymbols2(Sink sink__V165, Term term__V166)
{
  int term__V166_count = LINK_COUNT(term__V166); permitUnusedInt(term__V166_count);
  do {
    /* Contraction rule SYMBOLS-ComputeSymbols2-1. */
    ASSERT(sink__V165->context, !strcmp(SYMBOL(term__V166),  "ComputeSymbols2" ));
    Term sub__V167 = SUB(term__V166, 0); permitUnusedTerm(sub__V167); int sub__V167_count = term__V166_count*LINK_COUNT(sub__V167); permitUnusedInt(sub__V167_count);
    /* sub__V167 = &#1 */
    Term sub__V168 = LINK(sink__V165->context, SUB(term__V166, 1)); int sub__V168_count = term__V166_count*LINK_COUNT(sub__V168); permitUnusedInt(sub__V168_count);
    /* sub__V168 = &#2 */
    Term sub__V169 = SUB(term__V166, 2); permitUnusedTerm(sub__V169); int sub__V169_count = term__V166_count*LINK_COUNT(sub__V169); permitUnusedInt(sub__V169_count);
    /* sub__V169 = &#3 */
    
    NamedPropertyLink namedP__V170 = LINK_NamedPropertyLink(sink__V165->context, NAMED_PROPERTIES(term__V166));
    VariablePropertyLink varP__V171 = LINK_VariablePropertyLink(sink__V165->context, VARIABLE_PROPERTIES(term__V166));
    Hashset namedFV__V172 = LINK_VARIABLESET(sink__V165->context, namedPropertyFreeVars(namedP__V170));
    Hashset varFV__V173 = LINK_VARIABLESET(sink__V165->context, variablePropertyFreeVars(varP__V171));
    UNLINK(sink__V165->context, term__V166);
    { START(sink__V165, _M__sTextCons);
      { START(sink__V165, _M__sTextEmbed);
        { START(sink__V165, _M_AsText);
          { START(sink__V165, _M_X_Declarations);
            COPY(sink__V165, sub__V168);END(sink__V165, _M_X_Declarations); }
          END(sink__V165, _M_AsText); }
        END(sink__V165, _M__sTextEmbed); }
      { START(sink__V165, _M__sTextCons);
        { START(sink__V165, _M__sTextBreak);
          LITERAL(sink__V165,  "\n" ); END(sink__V165, _M__sTextBreak); }
        { START(sink__V165, _M__sTextNil);
          END(sink__V165, _M__sTextNil); }
        END(sink__V165, _M__sTextCons); }
      END(sink__V165, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V165->context, namedFV__V172); UNLINK_VARIABLESET(sink__V165->context, varFV__V173);
    UNLINK_NamedPropertyLink(sink__V165->context, namedP__V170); UNLINK_VariablePropertyLink(sink__V165->context, varP__V171);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Declaration. */
int conBindOffs_M_X_Declaration[] = {0 , 0};
char *nameFun_M_X_Declaration(Term term) { return  "X-Declaration" ; }
struct _ConstructionDescriptor descriptor_M_X_Declaration = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_X_Declaration), conBindOffs_M_X_Declaration, &nameFun_M_X_Declaration, &step_M_X_Declaration};

int step_M_X_Declaration(Sink sink__V174, Term term__V175)
{
  int term__V175_count = LINK_COUNT(term__V175); permitUnusedInt(term__V175_count);
  Term sub__V176 = FORCE(sink__V174->context, SUB(term__V175, 0));
  EnumOf_M_Reified_xDeclaration choice__V177 = (IS_VARIABLE_USE(sub__V176) ? VarOf_M_Reified_xDeclaration : (EnumOf_M_Reified_xDeclaration) TAG(sub__V176));
  switch (choice__V177)
  {
    case Data_M_DATA: { /* Function SYMBOLS-Data$X-Declaration$DATA case DATA */
      ASSERT(sink__V174->context, !strcmp(SYMBOL(term__V175),  "X-Declaration" ));
      Term sub__V178 = SUB(term__V175, 0); permitUnusedTerm(sub__V178); int sub__V178_count = term__V175_count*LINK_COUNT(sub__V178); permitUnusedInt(sub__V178_count);
      CRSX_CHECK_SORT(sink__V174->context, sub__V178, &sort_M_Reified_xDeclaration); ASSERT(sink__V174->context, !strcmp(SYMBOL(sub__V178),  "DATA" ));
      Term sub__V179 = LINK(sink__V174->context, SUB(sub__V178, 0)); int sub__V179_count = sub__V178_count*LINK_COUNT(sub__V179); permitUnusedInt(sub__V179_count);
      CRSX_CHECK_SORT(sink__V174->context, sub__V179, &sort_M_Reified_xSort); /* sub__V179 = &#0-0 */
      Term sub__V180 = LINK(sink__V174->context, SUB(sub__V178, 1)); int sub__V180_count = sub__V178_count*LINK_COUNT(sub__V180); permitUnusedInt(sub__V180_count);
      /* sub__V180 = &#0-1 */
      
      NamedPropertyLink namedP__V181 = LINK_NamedPropertyLink(sink__V174->context, NAMED_PROPERTIES(term__V175));
      VariablePropertyLink varP__V182 = LINK_VariablePropertyLink(sink__V174->context, VARIABLE_PROPERTIES(term__V175));
      Hashset namedFV__V183 = LINK_VARIABLESET(sink__V174->context, namedPropertyFreeVars(namedP__V181));
      Hashset varFV__V184 = LINK_VARIABLESET(sink__V174->context, variablePropertyFreeVars(varP__V182));
      UNLINK(sink__V174->context, term__V175);
      ADD_PROPERTIES(sink__V174, LINK_NamedPropertyLink(sink__V174->context, namedP__V181), LINK_VariablePropertyLink(sink__V174->context, varP__V182));
      { START(sink__V174, _M_X_Declaration_s1);
        COPY(sink__V174, sub__V179);COPY(sink__V174, sub__V180);END(sink__V174, _M_X_Declaration_s1); }
      UNLINK_VARIABLESET(sink__V174->context, namedFV__V183); UNLINK_VARIABLESET(sink__V174->context, varFV__V184);
      UNLINK_NamedPropertyLink(sink__V174->context, namedP__V181); UNLINK_VariablePropertyLink(sink__V174->context, varP__V182);
      
      return 1;
    break; } case Data_M_FUNCTION: { /* Function SYMBOLS-Function$X-Declaration$FUNCTION case FUNCTION */
      ASSERT(sink__V174->context, !strcmp(SYMBOL(term__V175),  "X-Declaration" ));
      Term sub__V185 = SUB(term__V175, 0); permitUnusedTerm(sub__V185); int sub__V185_count = term__V175_count*LINK_COUNT(sub__V185); permitUnusedInt(sub__V185_count);
      CRSX_CHECK_SORT(sink__V174->context, sub__V185, &sort_M_Reified_xDeclaration); ASSERT(sink__V174->context, !strcmp(SYMBOL(sub__V185),  "FUNCTION" ));
      Term sub__V186 = LINK(sink__V174->context, SUB(sub__V185, 0)); int sub__V186_count = sub__V185_count*LINK_COUNT(sub__V186); permitUnusedInt(sub__V186_count);
      /* sub__V186 = &#0-0 */
      Term sub__V187 = LINK(sink__V174->context, SUB(sub__V185, 1)); int sub__V187_count = sub__V185_count*LINK_COUNT(sub__V187); permitUnusedInt(sub__V187_count);
      /* sub__V187 = &#0-1 */
      Term sub__V188 = LINK(sink__V174->context, SUB(sub__V185, 2)); int sub__V188_count = sub__V185_count*LINK_COUNT(sub__V188); permitUnusedInt(sub__V188_count);
      /* sub__V188 = &#0-2 */
      Term sub__V189 = LINK(sink__V174->context, SUB(sub__V185, 3)); int sub__V189_count = sub__V185_count*LINK_COUNT(sub__V189); permitUnusedInt(sub__V189_count);
      /* sub__V189 = &#0-3 */
      Term sub__V190 = LINK(sink__V174->context, SUB(sub__V185, 4)); int sub__V190_count = sub__V185_count*LINK_COUNT(sub__V190); permitUnusedInt(sub__V190_count);
      /* sub__V190 = &#0-4 */
      Term sub__V191 = LINK(sink__V174->context, SUB(sub__V185, 5)); int sub__V191_count = sub__V185_count*LINK_COUNT(sub__V191); permitUnusedInt(sub__V191_count);
      CRSX_CHECK_SORT(sink__V174->context, sub__V191, &sort_M_Reified_xSort); /* sub__V191 = &#0-5 */
      Term sub__V192 = LINK(sink__V174->context, SUB(sub__V185, 6)); int sub__V192_count = sub__V185_count*LINK_COUNT(sub__V192); permitUnusedInt(sub__V192_count);
      /* sub__V192 = &#0-6 */
      
      NamedPropertyLink namedP__V193 = LINK_NamedPropertyLink(sink__V174->context, NAMED_PROPERTIES(term__V175));
      VariablePropertyLink varP__V194 = LINK_VariablePropertyLink(sink__V174->context, VARIABLE_PROPERTIES(term__V175));
      Hashset namedFV__V195 = LINK_VARIABLESET(sink__V174->context, namedPropertyFreeVars(namedP__V193));
      Hashset varFV__V196 = LINK_VARIABLESET(sink__V174->context, variablePropertyFreeVars(varP__V194));
      UNLINK(sink__V174->context, term__V175);
      ADD_PROPERTIES(sink__V174, LINK_NamedPropertyLink(sink__V174->context, namedP__V193), LINK_VariablePropertyLink(sink__V174->context, varP__V194));
      { START(sink__V174, _M_X_Declaration_s2);
        COPY(sink__V174, sub__V186);COPY(sink__V174, sub__V187);COPY(sink__V174, sub__V188);COPY(sink__V174, sub__V189);COPY(sink__V174, sub__V190);COPY(sink__V174, sub__V191);COPY(sink__V174, sub__V192);END(sink__V174, _M_X_Declaration_s2); }
      UNLINK_VARIABLESET(sink__V174->context, namedFV__V195); UNLINK_VARIABLESET(sink__V174->context, varFV__V196);
      UNLINK_NamedPropertyLink(sink__V174->context, namedP__V193); UNLINK_VariablePropertyLink(sink__V174->context, varP__V194);
      
      return 1;
    break; } case Data_M_POLYMORPHIC: { /* Function SYMBOLS-Polymorphic$X-Declaration$POLYMORPHIC case POLYMORPHIC */
      ASSERT(sink__V174->context, !strcmp(SYMBOL(term__V175),  "X-Declaration" ));
      Term sub__V197 = SUB(term__V175, 0); permitUnusedTerm(sub__V197); int sub__V197_count = term__V175_count*LINK_COUNT(sub__V197); permitUnusedInt(sub__V197_count);
      CRSX_CHECK_SORT(sink__V174->context, sub__V197, &sort_M_Reified_xDeclaration); ASSERT(sink__V174->context, !strcmp(SYMBOL(sub__V197),  "POLYMORPHIC" ));
      Variable y__V198 = BINDER(sub__V197,0,0); if (sub__V197_count <= 1) UNBIND(y__V198);
      Term sub__V199 = LINK(sink__V174->context, SUB(sub__V197, 0)); int sub__V199_count = sub__V197_count*LINK_COUNT(sub__V199); permitUnusedInt(sub__V199_count);
      CRSX_CHECK_SORT(sink__V174->context, sub__V199, &sort_M_Reified_xDeclaration); /* sub__V199 = &#0-0 */
      
      NamedPropertyLink namedP__V200 = LINK_NamedPropertyLink(sink__V174->context, NAMED_PROPERTIES(term__V175));
      VariablePropertyLink varP__V201 = LINK_VariablePropertyLink(sink__V174->context, VARIABLE_PROPERTIES(term__V175));
      Hashset namedFV__V202 = LINK_VARIABLESET(sink__V174->context, namedPropertyFreeVars(namedP__V200));
      Hashset varFV__V203 = LINK_VARIABLESET(sink__V174->context, variablePropertyFreeVars(varP__V201));
      UNLINK(sink__V174->context, term__V175);
      ADD_PROPERTIES(sink__V174, LINK_NamedPropertyLink(sink__V174->context, namedP__V200), LINK_VariablePropertyLink(sink__V174->context, varP__V201));
      { START(sink__V174, _M_X_Declaration_s3);
        { if (!IS_BOUND(y__V198)) { REBIND(y__V198);
            Variable binds__V204[1] = {y__V198}; BINDS(sink__V174, 1, binds__V204);
            COPY(sink__V174, sub__V199); /* REUSED SUBSTITUTION */  }
          else { Variable b__V205 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V174->context,"b__V205");
            Variable binds__V206[1] = {b__V205}; BINDS(sink__V174, 1, binds__V206);
            {
              Term arg__V207;
              { Sink buf__V208 = ALLOCA_BUFFER(sink__V174->context);
                USE(buf__V208, b__V205); arg__V207 = BUFFER_TERM(buf__V208); FREE_BUFFER(buf__V208); }
              Variable vars__V209[1] = {y__V198};
              Term args__V210[1] = {arg__V207};
              struct _SubstitutionFrame substitution__V211 = {NULL, 0, 1, vars__V209, args__V210, NULL};
              SUBSTITUTE(sink__V174, sub__V199, &substitution__V211); }
                }
           }
        END(sink__V174, _M_X_Declaration_s3); }
      UNLINK_VARIABLESET(sink__V174->context, namedFV__V202); UNLINK_VARIABLESET(sink__V174->context, varFV__V203);
      UNLINK_NamedPropertyLink(sink__V174->context, namedP__V200); UNLINK_VariablePropertyLink(sink__V174->context, varP__V201);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION X-Data. */
int conBindOffs_M_X_Data[] = {0 , 0 , 0};
char *nameFun_M_X_Data(Term term) { return  "X-Data" ; }
struct _ConstructionDescriptor descriptor_M_X_Data = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_X_Data), conBindOffs_M_X_Data, &nameFun_M_X_Data, &step_M_X_Data};

int step_M_X_Data(Sink sink__V212, Term term__V213)
{
  int term__V213_count = LINK_COUNT(term__V213); permitUnusedInt(term__V213_count);
  Term sub__V214 = FORCE(sink__V212->context, SUB(term__V213, 0));
  EnumOf_M_Reified_xSort choice__V215 = (IS_VARIABLE_USE(sub__V214) ? VarOf_M_Reified_xSort : (EnumOf_M_Reified_xSort) TAG(sub__V214));
  switch (choice__V215)
  {
    case Data_M_SORT: { /* Function SYMBOLS-X-Data-1$X-Data$SORT case SORT */
      ASSERT(sink__V212->context, !strcmp(SYMBOL(term__V213),  "X-Data" ));
      Term sub__V216 = SUB(term__V213, 0); permitUnusedTerm(sub__V216); int sub__V216_count = term__V213_count*LINK_COUNT(sub__V216); permitUnusedInt(sub__V216_count);
      CRSX_CHECK_SORT(sink__V212->context, sub__V216, &sort_M_Reified_xSort); ASSERT(sink__V212->context, !strcmp(SYMBOL(sub__V216),  "SORT" ));
      Term sub__V217 = LINK(sink__V212->context, SUB(sub__V216, 0)); int sub__V217_count = sub__V216_count*LINK_COUNT(sub__V217); permitUnusedInt(sub__V217_count);
      /* sub__V217 = &#0-0 */
      Term sub__V218 = LINK(sink__V212->context, SUB(sub__V216, 1)); int sub__V218_count = sub__V216_count*LINK_COUNT(sub__V218); permitUnusedInt(sub__V218_count);
      /* sub__V218 = &#0-1 */
      Term sub__V219 = LINK(sink__V212->context, SUB(term__V213, 1)); int sub__V219_count = term__V213_count*LINK_COUNT(sub__V219); permitUnusedInt(sub__V219_count);
      /* sub__V219 = &#2 */
      
      NamedPropertyLink namedP__V220 = LINK_NamedPropertyLink(sink__V212->context, NAMED_PROPERTIES(term__V213));
      VariablePropertyLink varP__V221 = LINK_VariablePropertyLink(sink__V212->context, VARIABLE_PROPERTIES(term__V213));
      Hashset namedFV__V222 = LINK_VARIABLESET(sink__V212->context, namedPropertyFreeVars(namedP__V220));
      Hashset varFV__V223 = LINK_VARIABLESET(sink__V212->context, variablePropertyFreeVars(varP__V221));
      UNLINK(sink__V212->context, term__V213);
      ADD_PROPERTIES(sink__V212, LINK_NamedPropertyLink(sink__V212->context, namedP__V220), LINK_VariablePropertyLink(sink__V212->context, varP__V221));
      { START(sink__V212, _M_X_Data_s1);
        COPY(sink__V212, sub__V217);COPY(sink__V212, sub__V218);COPY(sink__V212, sub__V219);END(sink__V212, _M_X_Data_s1); }
      UNLINK_VARIABLESET(sink__V212->context, namedFV__V222); UNLINK_VARIABLESET(sink__V212->context, varFV__V223);
      UNLINK_NamedPropertyLink(sink__V212->context, namedP__V220); UNLINK_VariablePropertyLink(sink__V212->context, varP__V221);
      
      return 1;
    break; } case Data_M_SORT_PROPERTY: { /* Function SYMBOLS-X-Data-2$X-Data$SORT-PROPERTY case SORT-PROPERTY */
      ASSERT(sink__V212->context, !strcmp(SYMBOL(term__V213),  "X-Data" ));
      Term sub__V224 = SUB(term__V213, 0); permitUnusedTerm(sub__V224); int sub__V224_count = term__V213_count*LINK_COUNT(sub__V224); permitUnusedInt(sub__V224_count);
      CRSX_CHECK_SORT(sink__V212->context, sub__V224, &sort_M_Reified_xSort); ASSERT(sink__V212->context, !strcmp(SYMBOL(sub__V224),  "SORT-PROPERTY" ));
      Term sub__V225 = LINK(sink__V212->context, SUB(sub__V224, 0)); int sub__V225_count = sub__V224_count*LINK_COUNT(sub__V225); permitUnusedInt(sub__V225_count);
      CRSX_CHECK_SORT(sink__V212->context, sub__V225, &sort_M_Reified_xSort); /* sub__V225 = &#0-0 */
      Term sub__V226 = LINK(sink__V212->context, SUB(sub__V224, 1)); int sub__V226_count = sub__V224_count*LINK_COUNT(sub__V226); permitUnusedInt(sub__V226_count);
      CRSX_CHECK_SORT(sink__V212->context, sub__V226, &sort_M_Reified_xSort); /* sub__V226 = &#0-1 */
      Term sub__V227 = LINK(sink__V212->context, SUB(sub__V224, 2)); int sub__V227_count = sub__V224_count*LINK_COUNT(sub__V227); permitUnusedInt(sub__V227_count);
      CRSX_CHECK_SORT(sink__V212->context, sub__V227, &sort_M_Reified_xSort); /* sub__V227 = &#0-2 */
      Term sub__V228 = LINK(sink__V212->context, SUB(term__V213, 1)); int sub__V228_count = term__V213_count*LINK_COUNT(sub__V228); permitUnusedInt(sub__V228_count);
      /* sub__V228 = &#3 */
      
      NamedPropertyLink namedP__V229 = LINK_NamedPropertyLink(sink__V212->context, NAMED_PROPERTIES(term__V213));
      VariablePropertyLink varP__V230 = LINK_VariablePropertyLink(sink__V212->context, VARIABLE_PROPERTIES(term__V213));
      Hashset namedFV__V231 = LINK_VARIABLESET(sink__V212->context, namedPropertyFreeVars(namedP__V229));
      Hashset varFV__V232 = LINK_VARIABLESET(sink__V212->context, variablePropertyFreeVars(varP__V230));
      UNLINK(sink__V212->context, term__V213);
      ADD_PROPERTIES(sink__V212, LINK_NamedPropertyLink(sink__V212->context, namedP__V229), LINK_VariablePropertyLink(sink__V212->context, varP__V230));
      { START(sink__V212, _M_X_Data_s2);
        COPY(sink__V212, sub__V225);COPY(sink__V212, sub__V226);COPY(sink__V212, sub__V227);COPY(sink__V212, sub__V228);END(sink__V212, _M_X_Data_s2); }
      UNLINK_VARIABLESET(sink__V212->context, namedFV__V231); UNLINK_VARIABLESET(sink__V212->context, varFV__V232);
      UNLINK_NamedPropertyLink(sink__V212->context, namedP__V229); UNLINK_VariablePropertyLink(sink__V212->context, varP__V230);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION ComputeSymbols. */
int conBindOffs_M_ComputeSymbols[] = {0 , 0};
char *nameFun_M_ComputeSymbols(Term term) { return  "ComputeSymbols" ; }
struct _ConstructionDescriptor descriptor_M_ComputeSymbols = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_ComputeSymbols), conBindOffs_M_ComputeSymbols, &nameFun_M_ComputeSymbols, &step_M_ComputeSymbols};

int step_M_ComputeSymbols(Sink sink__V233, Term term__V234)
{
  int term__V234_count = LINK_COUNT(term__V234); permitUnusedInt(term__V234_count);
  Term sub__V235 = FORCE(sink__V233->context, SUB(term__V234, 0));
  EnumOf_M_Reify_xCRSX choice__V236 = (IS_VARIABLE_USE(sub__V235) ? VarOf_M_Reify_xCRSX : (EnumOf_M_Reify_xCRSX) TAG(sub__V235));
  switch (choice__V236)
  {
    case Data_M_CRSX: { /* Function SYMBOLS-ComputeSymbols-1$ComputeSymbols$CRSX case CRSX */
      ASSERT(sink__V233->context, !strcmp(SYMBOL(term__V234),  "ComputeSymbols" ));
      Term sub__V237 = SUB(term__V234, 0); permitUnusedTerm(sub__V237); int sub__V237_count = term__V234_count*LINK_COUNT(sub__V237); permitUnusedInt(sub__V237_count);
      CRSX_CHECK_SORT(sink__V233->context, sub__V237, &sort_M_Reify_xCRSX); ASSERT(sink__V233->context, !strcmp(SYMBOL(sub__V237),  "CRSX" ));
      Term sub__V238 = LINK(sink__V233->context, SUB(sub__V237, 0)); int sub__V238_count = sub__V237_count*LINK_COUNT(sub__V238); permitUnusedInt(sub__V238_count);
      /* sub__V238 = &#0-0 */
      Term sub__V239 = LINK(sink__V233->context, SUB(sub__V237, 1)); int sub__V239_count = sub__V237_count*LINK_COUNT(sub__V239); permitUnusedInt(sub__V239_count);
      /* sub__V239 = &#0-1 */
      
      NamedPropertyLink namedP__V240 = LINK_NamedPropertyLink(sink__V233->context, NAMED_PROPERTIES(term__V234));
      VariablePropertyLink varP__V241 = LINK_VariablePropertyLink(sink__V233->context, VARIABLE_PROPERTIES(term__V234));
      Hashset namedFV__V242 = LINK_VARIABLESET(sink__V233->context, namedPropertyFreeVars(namedP__V240));
      Hashset varFV__V243 = LINK_VARIABLESET(sink__V233->context, variablePropertyFreeVars(varP__V241));
      UNLINK(sink__V233->context, term__V234);
      ADD_PROPERTIES(sink__V233, LINK_NamedPropertyLink(sink__V233->context, namedP__V240), LINK_VariablePropertyLink(sink__V233->context, varP__V241));
      { START(sink__V233, _M_ComputeSymbols_s1);
        COPY(sink__V233, sub__V238);COPY(sink__V233, sub__V239);END(sink__V233, _M_ComputeSymbols_s1); }
      UNLINK_VARIABLESET(sink__V233->context, namedFV__V242); UNLINK_VARIABLESET(sink__V233->context, varFV__V243);
      UNLINK_NamedPropertyLink(sink__V233->context, namedP__V240); UNLINK_VariablePropertyLink(sink__V233->context, varP__V241);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION X-Function. */
int conBindOffs_M_X_Function[] = {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0};
char *nameFun_M_X_Function(Term term) { return  "X-Function" ; }
struct _ConstructionDescriptor descriptor_M_X_Function = {&sort_M_Reified_xVariable, 0, 7, sizeof(STRUCT_Con_M_X_Function), conBindOffs_M_X_Function, &nameFun_M_X_Function, &step_M_X_Function};

int step_M_X_Function(Sink sink__V244, Term term__V245)
{
  int term__V245_count = LINK_COUNT(term__V245); permitUnusedInt(term__V245_count);
  do {
    /* Contraction rule SYMBOLS-X-Function-1. */
    ASSERT(sink__V244->context, !strcmp(SYMBOL(term__V245),  "X-Function" ));
    Term sub__V246 = SUB(term__V245, 0); permitUnusedTerm(sub__V246); int sub__V246_count = term__V245_count*LINK_COUNT(sub__V246); permitUnusedInt(sub__V246_count);
    /* sub__V246 = &#1 */
    Term sub__V247 = SUB(term__V245, 1); permitUnusedTerm(sub__V247); int sub__V247_count = term__V245_count*LINK_COUNT(sub__V247); permitUnusedInt(sub__V247_count);
    /* sub__V247 = &#2 */
    Term sub__V248 = SUB(term__V245, 2); permitUnusedTerm(sub__V248); int sub__V248_count = term__V245_count*LINK_COUNT(sub__V248); permitUnusedInt(sub__V248_count);
    /* sub__V248 = &#3 */
    Term sub__V249 = SUB(term__V245, 3); permitUnusedTerm(sub__V249); int sub__V249_count = term__V245_count*LINK_COUNT(sub__V249); permitUnusedInt(sub__V249_count);
    /* sub__V249 = &#4 */
    Term sub__V250 = LINK(sink__V244->context, SUB(term__V245, 4)); int sub__V250_count = term__V245_count*LINK_COUNT(sub__V250); permitUnusedInt(sub__V250_count);
    UNLINK_SUB(sink__V244->context, term__V245,  4); NORMALIZE(sink__V244->context, sub__V250); SUB(term__V245,  4) = LINK(sink__V244->context, sub__V250);
    /* sub__V250 = &#5 */
    Term sub__V251 = SUB(term__V245, 5); permitUnusedTerm(sub__V251); int sub__V251_count = term__V245_count*LINK_COUNT(sub__V251); permitUnusedInt(sub__V251_count);
    CRSX_CHECK_SORT(sink__V244->context, sub__V251, &sort_M_Reified_xSort); /* sub__V251 = &#6 */
    Term sub__V252 = SUB(term__V245, 6); permitUnusedTerm(sub__V252); int sub__V252_count = term__V245_count*LINK_COUNT(sub__V252); permitUnusedInt(sub__V252_count);
    /* sub__V252 = &#7 */
    
    NamedPropertyLink namedP__V253 = LINK_NamedPropertyLink(sink__V244->context, NAMED_PROPERTIES(term__V245));
    VariablePropertyLink varP__V254 = LINK_VariablePropertyLink(sink__V244->context, VARIABLE_PROPERTIES(term__V245));
    Hashset namedFV__V255 = LINK_VARIABLESET(sink__V244->context, namedPropertyFreeVars(namedP__V253));
    Hashset varFV__V256 = LINK_VARIABLESET(sink__V244->context, variablePropertyFreeVars(varP__V254));
    UNLINK(sink__V244->context, term__V245);
    { START(sink__V244, _M__sTextCons);
      { START(sink__V244, _M__sTextEmbed);
        { START(sink__V244, _M_AsText);
          { START(sink__V244, _M_MapText_s1);
            COPY(sink__V244, sub__V250);{ Variable x__V257 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V244->context,"x__V257");
              Variable binds__V258[1] = {x__V257}; BINDS(sink__V244, 1, binds__V258);
              { START(sink__V244, _M_X_Form);
                USE(sink__V244, x__V257); END(sink__V244, _M_X_Form); }
               }
            END(sink__V244, _M_MapText_s1); }
          END(sink__V244, _M_AsText); }
        END(sink__V244, _M__sTextEmbed); }
      { START(sink__V244, _M__sTextNil);
        END(sink__V244, _M__sTextNil); }
      END(sink__V244, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V244->context, namedFV__V255); UNLINK_VARIABLESET(sink__V244->context, varFV__V256);
    UNLINK_NamedPropertyLink(sink__V244->context, namedP__V253); UNLINK_VariablePropertyLink(sink__V244->context, varP__V254);
    return 1;
  } while (0);
  return 0;
}

#ifdef __cplusplus
}
#endif
/* END OF C RULES FOR CRSX CRSXC MODULE SYMBOLS. */
