/* C RULES FOR CRSX CRSXC MODULE HEADER. */
#include "CRSXC.h" 
#ifdef __cplusplus
extern "C" {
#endif

/* FUNCTION ComputeHeader. */
int conBindOffs_M_ComputeHeader[] = {0 , 0};
char *nameFun_M_ComputeHeader(Term term) { return  "ComputeHeader" ; }
struct _ConstructionDescriptor descriptor_M_ComputeHeader = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_ComputeHeader), conBindOffs_M_ComputeHeader, &nameFun_M_ComputeHeader, &step_M_ComputeHeader};

int step_M_ComputeHeader(Sink sink__V1, Term term__V2)
{
  int term__V2_count = LINK_COUNT(term__V2); permitUnusedInt(term__V2_count);
  Term sub__V3 = FORCE(sink__V1->context, SUB(term__V2, 0));
  EnumOf_M_Reify_xCRSX choice__V4 = (IS_VARIABLE_USE(sub__V3) ? VarOf_M_Reify_xCRSX : (EnumOf_M_Reify_xCRSX) TAG(sub__V3));
  switch (choice__V4)
  {
    case Data_M_CRSX: { /* Function HEADER-ComputeHeader-1$ComputeHeader$CRSX case CRSX */
      ASSERT(sink__V1->context, !strcmp(SYMBOL(term__V2),  "ComputeHeader" ));
      Term sub__V5 = SUB(term__V2, 0); permitUnusedTerm(sub__V5); int sub__V5_count = term__V2_count*LINK_COUNT(sub__V5); permitUnusedInt(sub__V5_count);
      CRSX_CHECK_SORT(sink__V1->context, sub__V5, &sort_M_Reify_xCRSX); ASSERT(sink__V1->context, !strcmp(SYMBOL(sub__V5),  "CRSX" ));
      Term sub__V6 = LINK(sink__V1->context, SUB(sub__V5, 0)); int sub__V6_count = sub__V5_count*LINK_COUNT(sub__V6); permitUnusedInt(sub__V6_count);
      /* sub__V6 = &#0-0 */
      Term sub__V7 = LINK(sink__V1->context, SUB(sub__V5, 1)); int sub__V7_count = sub__V5_count*LINK_COUNT(sub__V7); permitUnusedInt(sub__V7_count);
      /* sub__V7 = &#0-1 */
      
      NamedPropertyLink namedP__V8 = LINK_NamedPropertyLink(sink__V1->context, NAMED_PROPERTIES(term__V2));
      VariablePropertyLink varP__V9 = LINK_VariablePropertyLink(sink__V1->context, VARIABLE_PROPERTIES(term__V2));
      Hashset namedFV__V10 = LINK_VARIABLESET(sink__V1->context, asConstruction(term__V2)->properties->namedFreeVars);
      Hashset varFV__V11 = LINK_VARIABLESET(sink__V1->context, asConstruction(term__V2)->properties->variableFreeVars);
      UNLINK(sink__V1->context, term__V2);
      ADD_PROPERTIES(sink__V1, LINK_VARIABLESET(sink__V1->context, namedFV__V10), LINK_VARIABLESET(sink__V1->context, varFV__V11), LINK_NamedPropertyLink(sink__V1->context, namedP__V8), LINK_VariablePropertyLink(sink__V1->context, varP__V9));
      { START(sink__V1, _M_ComputeHeader_s1);
        COPY(sink__V1, sub__V6);COPY(sink__V1, sub__V7);END(sink__V1, _M_ComputeHeader_s1); }
      UNLINK_VARIABLESET(sink__V1->context, namedFV__V10); UNLINK_VARIABLESET(sink__V1->context, varFV__V11);
      UNLINK_NamedPropertyLink(sink__V1->context, namedP__V8); UNLINK_VariablePropertyLink(sink__V1->context, varP__V9);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION H-Data. */
int conBindOffs_M_H_Data[] = {0 , 0 , 0};
char *nameFun_M_H_Data(Term term) { return  "H-Data" ; }
struct _ConstructionDescriptor descriptor_M_H_Data = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_H_Data), conBindOffs_M_H_Data, &nameFun_M_H_Data, &step_M_H_Data};

int step_M_H_Data(Sink sink__V12, Term term__V13)
{
  int term__V13_count = LINK_COUNT(term__V13); permitUnusedInt(term__V13_count);
  Term sub__V14 = FORCE(sink__V12->context, SUB(term__V13, 0));
  EnumOf_M_Reified_xSort choice__V15 = (IS_VARIABLE_USE(sub__V14) ? VarOf_M_Reified_xSort : (EnumOf_M_Reified_xSort) TAG(sub__V14));
  switch (choice__V15)
  {
    case Data_M_SORT: { /* Function HEADER-H-Data-1$H-Data$SORT case SORT */
      ASSERT(sink__V12->context, !strcmp(SYMBOL(term__V13),  "H-Data" ));
      Term sub__V16 = SUB(term__V13, 0); permitUnusedTerm(sub__V16); int sub__V16_count = term__V13_count*LINK_COUNT(sub__V16); permitUnusedInt(sub__V16_count);
      CRSX_CHECK_SORT(sink__V12->context, sub__V16, &sort_M_Reified_xSort); ASSERT(sink__V12->context, !strcmp(SYMBOL(sub__V16),  "SORT" ));
      Term sub__V17 = LINK(sink__V12->context, SUB(sub__V16, 0)); int sub__V17_count = sub__V16_count*LINK_COUNT(sub__V17); permitUnusedInt(sub__V17_count);
      /* sub__V17 = &#0-0 */
      Term sub__V18 = LINK(sink__V12->context, SUB(sub__V16, 1)); int sub__V18_count = sub__V16_count*LINK_COUNT(sub__V18); permitUnusedInt(sub__V18_count);
      /* sub__V18 = &#0-1 */
      Term sub__V19 = LINK(sink__V12->context, SUB(term__V13, 1)); int sub__V19_count = term__V13_count*LINK_COUNT(sub__V19); permitUnusedInt(sub__V19_count);
      /* sub__V19 = &#2 */
      
      NamedPropertyLink namedP__V20 = LINK_NamedPropertyLink(sink__V12->context, NAMED_PROPERTIES(term__V13));
      VariablePropertyLink varP__V21 = LINK_VariablePropertyLink(sink__V12->context, VARIABLE_PROPERTIES(term__V13));
      Hashset namedFV__V22 = LINK_VARIABLESET(sink__V12->context, asConstruction(term__V13)->properties->namedFreeVars);
      Hashset varFV__V23 = LINK_VARIABLESET(sink__V12->context, asConstruction(term__V13)->properties->variableFreeVars);
      UNLINK(sink__V12->context, term__V13);
      ADD_PROPERTIES(sink__V12, LINK_VARIABLESET(sink__V12->context, namedFV__V22), LINK_VARIABLESET(sink__V12->context, varFV__V23), LINK_NamedPropertyLink(sink__V12->context, namedP__V20), LINK_VariablePropertyLink(sink__V12->context, varP__V21));
      { START(sink__V12, _M_H_Data_s1);
        COPY(sink__V12, sub__V17);COPY(sink__V12, sub__V18);COPY(sink__V12, sub__V19);END(sink__V12, _M_H_Data_s1); }
      UNLINK_VARIABLESET(sink__V12->context, namedFV__V22); UNLINK_VARIABLESET(sink__V12->context, varFV__V23);
      UNLINK_NamedPropertyLink(sink__V12->context, namedP__V20); UNLINK_VariablePropertyLink(sink__V12->context, varP__V21);
      
      return 1;
    break; } case Data_M_SORT_PROPERTY: { /* Function HEADER-H-Data-2$H-Data$SORT-PROPERTY case SORT-PROPERTY */
      ASSERT(sink__V12->context, !strcmp(SYMBOL(term__V13),  "H-Data" ));
      Term sub__V24 = SUB(term__V13, 0); permitUnusedTerm(sub__V24); int sub__V24_count = term__V13_count*LINK_COUNT(sub__V24); permitUnusedInt(sub__V24_count);
      CRSX_CHECK_SORT(sink__V12->context, sub__V24, &sort_M_Reified_xSort); ASSERT(sink__V12->context, !strcmp(SYMBOL(sub__V24),  "SORT-PROPERTY" ));
      Term sub__V25 = LINK(sink__V12->context, SUB(sub__V24, 0)); int sub__V25_count = sub__V24_count*LINK_COUNT(sub__V25); permitUnusedInt(sub__V25_count);
      CRSX_CHECK_SORT(sink__V12->context, sub__V25, &sort_M_Reified_xSort); /* sub__V25 = &#0-0 */
      Term sub__V26 = LINK(sink__V12->context, SUB(sub__V24, 1)); int sub__V26_count = sub__V24_count*LINK_COUNT(sub__V26); permitUnusedInt(sub__V26_count);
      CRSX_CHECK_SORT(sink__V12->context, sub__V26, &sort_M_Reified_xSort); /* sub__V26 = &#0-1 */
      Term sub__V27 = LINK(sink__V12->context, SUB(sub__V24, 2)); int sub__V27_count = sub__V24_count*LINK_COUNT(sub__V27); permitUnusedInt(sub__V27_count);
      CRSX_CHECK_SORT(sink__V12->context, sub__V27, &sort_M_Reified_xSort); /* sub__V27 = &#0-2 */
      Term sub__V28 = LINK(sink__V12->context, SUB(term__V13, 1)); int sub__V28_count = term__V13_count*LINK_COUNT(sub__V28); permitUnusedInt(sub__V28_count);
      /* sub__V28 = &#3 */
      
      NamedPropertyLink namedP__V29 = LINK_NamedPropertyLink(sink__V12->context, NAMED_PROPERTIES(term__V13));
      VariablePropertyLink varP__V30 = LINK_VariablePropertyLink(sink__V12->context, VARIABLE_PROPERTIES(term__V13));
      Hashset namedFV__V31 = LINK_VARIABLESET(sink__V12->context, asConstruction(term__V13)->properties->namedFreeVars);
      Hashset varFV__V32 = LINK_VARIABLESET(sink__V12->context, asConstruction(term__V13)->properties->variableFreeVars);
      UNLINK(sink__V12->context, term__V13);
      ADD_PROPERTIES(sink__V12, LINK_VARIABLESET(sink__V12->context, namedFV__V31), LINK_VARIABLESET(sink__V12->context, varFV__V32), LINK_NamedPropertyLink(sink__V12->context, namedP__V29), LINK_VariablePropertyLink(sink__V12->context, varP__V30));
      { START(sink__V12, _M_H_Data_s2);
        COPY(sink__V12, sub__V25);COPY(sink__V12, sub__V26);COPY(sink__V12, sub__V27);COPY(sink__V12, sub__V28);END(sink__V12, _M_H_Data_s2); }
      UNLINK_VARIABLESET(sink__V12->context, namedFV__V31); UNLINK_VARIABLESET(sink__V12->context, varFV__V32);
      UNLINK_NamedPropertyLink(sink__V12->context, namedP__V29); UNLINK_VariablePropertyLink(sink__V12->context, varP__V30);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION H-Declaration. */
int conBindOffs_M_H_Declaration[] = {0 , 0};
char *nameFun_M_H_Declaration(Term term) { return  "H-Declaration" ; }
struct _ConstructionDescriptor descriptor_M_H_Declaration = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_H_Declaration), conBindOffs_M_H_Declaration, &nameFun_M_H_Declaration, &step_M_H_Declaration};

int step_M_H_Declaration(Sink sink__V33, Term term__V34)
{
  int term__V34_count = LINK_COUNT(term__V34); permitUnusedInt(term__V34_count);
  Term sub__V35 = FORCE(sink__V33->context, SUB(term__V34, 0));
  EnumOf_M_Reified_xDeclaration choice__V36 = (IS_VARIABLE_USE(sub__V35) ? VarOf_M_Reified_xDeclaration : (EnumOf_M_Reified_xDeclaration) TAG(sub__V35));
  switch (choice__V36)
  {
    case Data_M_DATA: { /* Function HEADER-Data$H-Declaration$DATA case DATA */
      ASSERT(sink__V33->context, !strcmp(SYMBOL(term__V34),  "H-Declaration" ));
      Term sub__V37 = SUB(term__V34, 0); permitUnusedTerm(sub__V37); int sub__V37_count = term__V34_count*LINK_COUNT(sub__V37); permitUnusedInt(sub__V37_count);
      CRSX_CHECK_SORT(sink__V33->context, sub__V37, &sort_M_Reified_xDeclaration); ASSERT(sink__V33->context, !strcmp(SYMBOL(sub__V37),  "DATA" ));
      Term sub__V38 = LINK(sink__V33->context, SUB(sub__V37, 0)); int sub__V38_count = sub__V37_count*LINK_COUNT(sub__V38); permitUnusedInt(sub__V38_count);
      CRSX_CHECK_SORT(sink__V33->context, sub__V38, &sort_M_Reified_xSort); /* sub__V38 = &#0-0 */
      Term sub__V39 = LINK(sink__V33->context, SUB(sub__V37, 1)); int sub__V39_count = sub__V37_count*LINK_COUNT(sub__V39); permitUnusedInt(sub__V39_count);
      /* sub__V39 = &#0-1 */
      
      NamedPropertyLink namedP__V40 = LINK_NamedPropertyLink(sink__V33->context, NAMED_PROPERTIES(term__V34));
      VariablePropertyLink varP__V41 = LINK_VariablePropertyLink(sink__V33->context, VARIABLE_PROPERTIES(term__V34));
      Hashset namedFV__V42 = LINK_VARIABLESET(sink__V33->context, asConstruction(term__V34)->properties->namedFreeVars);
      Hashset varFV__V43 = LINK_VARIABLESET(sink__V33->context, asConstruction(term__V34)->properties->variableFreeVars);
      UNLINK(sink__V33->context, term__V34);
      ADD_PROPERTIES(sink__V33, LINK_VARIABLESET(sink__V33->context, namedFV__V42), LINK_VARIABLESET(sink__V33->context, varFV__V43), LINK_NamedPropertyLink(sink__V33->context, namedP__V40), LINK_VariablePropertyLink(sink__V33->context, varP__V41));
      { START(sink__V33, _M_H_Declaration_s1);
        COPY(sink__V33, sub__V38);COPY(sink__V33, sub__V39);END(sink__V33, _M_H_Declaration_s1); }
      UNLINK_VARIABLESET(sink__V33->context, namedFV__V42); UNLINK_VARIABLESET(sink__V33->context, varFV__V43);
      UNLINK_NamedPropertyLink(sink__V33->context, namedP__V40); UNLINK_VariablePropertyLink(sink__V33->context, varP__V41);
      
      return 1;
    break; } case Data_M_FUNCTION: { /* Function HEADER-Function$H-Declaration$FUNCTION case FUNCTION */
      ASSERT(sink__V33->context, !strcmp(SYMBOL(term__V34),  "H-Declaration" ));
      Term sub__V44 = SUB(term__V34, 0); permitUnusedTerm(sub__V44); int sub__V44_count = term__V34_count*LINK_COUNT(sub__V44); permitUnusedInt(sub__V44_count);
      CRSX_CHECK_SORT(sink__V33->context, sub__V44, &sort_M_Reified_xDeclaration); ASSERT(sink__V33->context, !strcmp(SYMBOL(sub__V44),  "FUNCTION" ));
      Term sub__V45 = LINK(sink__V33->context, SUB(sub__V44, 0)); int sub__V45_count = sub__V44_count*LINK_COUNT(sub__V45); permitUnusedInt(sub__V45_count);
      /* sub__V45 = &#0-0 */
      Term sub__V46 = LINK(sink__V33->context, SUB(sub__V44, 1)); int sub__V46_count = sub__V44_count*LINK_COUNT(sub__V46); permitUnusedInt(sub__V46_count);
      /* sub__V46 = &#0-1 */
      Term sub__V47 = LINK(sink__V33->context, SUB(sub__V44, 2)); int sub__V47_count = sub__V44_count*LINK_COUNT(sub__V47); permitUnusedInt(sub__V47_count);
      /* sub__V47 = &#0-2 */
      Term sub__V48 = LINK(sink__V33->context, SUB(sub__V44, 3)); int sub__V48_count = sub__V44_count*LINK_COUNT(sub__V48); permitUnusedInt(sub__V48_count);
      /* sub__V48 = &#0-3 */
      Term sub__V49 = LINK(sink__V33->context, SUB(sub__V44, 4)); int sub__V49_count = sub__V44_count*LINK_COUNT(sub__V49); permitUnusedInt(sub__V49_count);
      /* sub__V49 = &#0-4 */
      Term sub__V50 = LINK(sink__V33->context, SUB(sub__V44, 5)); int sub__V50_count = sub__V44_count*LINK_COUNT(sub__V50); permitUnusedInt(sub__V50_count);
      CRSX_CHECK_SORT(sink__V33->context, sub__V50, &sort_M_Reified_xSort); /* sub__V50 = &#0-5 */
      Term sub__V51 = LINK(sink__V33->context, SUB(sub__V44, 6)); int sub__V51_count = sub__V44_count*LINK_COUNT(sub__V51); permitUnusedInt(sub__V51_count);
      /* sub__V51 = &#0-6 */
      
      NamedPropertyLink namedP__V52 = LINK_NamedPropertyLink(sink__V33->context, NAMED_PROPERTIES(term__V34));
      VariablePropertyLink varP__V53 = LINK_VariablePropertyLink(sink__V33->context, VARIABLE_PROPERTIES(term__V34));
      Hashset namedFV__V54 = LINK_VARIABLESET(sink__V33->context, asConstruction(term__V34)->properties->namedFreeVars);
      Hashset varFV__V55 = LINK_VARIABLESET(sink__V33->context, asConstruction(term__V34)->properties->variableFreeVars);
      UNLINK(sink__V33->context, term__V34);
      ADD_PROPERTIES(sink__V33, LINK_VARIABLESET(sink__V33->context, namedFV__V54), LINK_VARIABLESET(sink__V33->context, varFV__V55), LINK_NamedPropertyLink(sink__V33->context, namedP__V52), LINK_VariablePropertyLink(sink__V33->context, varP__V53));
      { START(sink__V33, _M_H_Declaration_s2);
        COPY(sink__V33, sub__V45);COPY(sink__V33, sub__V46);COPY(sink__V33, sub__V47);COPY(sink__V33, sub__V48);COPY(sink__V33, sub__V49);COPY(sink__V33, sub__V50);COPY(sink__V33, sub__V51);END(sink__V33, _M_H_Declaration_s2); }
      UNLINK_VARIABLESET(sink__V33->context, namedFV__V54); UNLINK_VARIABLESET(sink__V33->context, varFV__V55);
      UNLINK_NamedPropertyLink(sink__V33->context, namedP__V52); UNLINK_VariablePropertyLink(sink__V33->context, varP__V53);
      
      return 1;
    break; } case Data_M_POLYMORPHIC: { /* Function HEADER-Polymorphic$H-Declaration$POLYMORPHIC case POLYMORPHIC */
      ASSERT(sink__V33->context, !strcmp(SYMBOL(term__V34),  "H-Declaration" ));
      Term sub__V56 = SUB(term__V34, 0); permitUnusedTerm(sub__V56); int sub__V56_count = term__V34_count*LINK_COUNT(sub__V56); permitUnusedInt(sub__V56_count);
      CRSX_CHECK_SORT(sink__V33->context, sub__V56, &sort_M_Reified_xDeclaration); ASSERT(sink__V33->context, !strcmp(SYMBOL(sub__V56),  "POLYMORPHIC" ));
      Variable y__V57 = BINDER(sub__V56,0,0); if (sub__V56_count <= 1) UNBIND(y__V57);
      Term sub__V58 = LINK(sink__V33->context, SUB(sub__V56, 0)); int sub__V58_count = sub__V56_count*LINK_COUNT(sub__V58); permitUnusedInt(sub__V58_count);
      CRSX_CHECK_SORT(sink__V33->context, sub__V58, &sort_M_Reified_xDeclaration); /* sub__V58 = &#0-0 */
      
      NamedPropertyLink namedP__V59 = LINK_NamedPropertyLink(sink__V33->context, NAMED_PROPERTIES(term__V34));
      VariablePropertyLink varP__V60 = LINK_VariablePropertyLink(sink__V33->context, VARIABLE_PROPERTIES(term__V34));
      Hashset namedFV__V61 = LINK_VARIABLESET(sink__V33->context, asConstruction(term__V34)->properties->namedFreeVars);
      Hashset varFV__V62 = LINK_VARIABLESET(sink__V33->context, asConstruction(term__V34)->properties->variableFreeVars);
      UNLINK(sink__V33->context, term__V34);
      ADD_PROPERTIES(sink__V33, LINK_VARIABLESET(sink__V33->context, namedFV__V61), LINK_VARIABLESET(sink__V33->context, varFV__V62), LINK_NamedPropertyLink(sink__V33->context, namedP__V59), LINK_VariablePropertyLink(sink__V33->context, varP__V60));
      { START(sink__V33, _M_H_Declaration_s3);
        { if (!IS_BOUND(y__V57)) { REBIND(y__V57);
            Variable binds__V63[1] = {y__V57}; BINDS(sink__V33, 1, binds__V63);
            COPY(sink__V33, sub__V58); /* REUSED SUBSTITUTION */  }
          else { Variable b__V64 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V33->context,"b__V64");
            Variable binds__V65[1] = {b__V64}; BINDS(sink__V33, 1, binds__V65);
            {
              Term arg__V66;
              { Sink buf__V67 = ALLOCA_BUFFER(sink__V33->context);
                USE(buf__V67, b__V64); arg__V66 = BUFFER_TERM(buf__V67); FREE_BUFFER(buf__V67); }
              Variable vars__V68[1] = {y__V57};
              Term args__V69[1] = {arg__V66};
              struct _SubstitutionFrame substitution__V70 = {NULL, 0, 1, vars__V68, args__V69, NULL};
              SUBSTITUTE(sink__V33, sub__V58, &substitution__V70); }
                }
           }
        END(sink__V33, _M_H_Declaration_s3); }
      UNLINK_VARIABLESET(sink__V33->context, namedFV__V61); UNLINK_VARIABLESET(sink__V33->context, varFV__V62);
      UNLINK_NamedPropertyLink(sink__V33->context, namedP__V59); UNLINK_VariablePropertyLink(sink__V33->context, varP__V60);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION H-Declarations$1. */
int conBindOffs_M_H_Declarations_s1[] = {0 , 0 , 0};
char *nameFun_M_H_Declarations_s1(Term term) { return  "H-Declarations$1" ; }
struct _ConstructionDescriptor descriptor_M_H_Declarations_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_H_Declarations_s1), conBindOffs_M_H_Declarations_s1, &nameFun_M_H_Declarations_s1, &step_M_H_Declarations_s1};

int step_M_H_Declarations_s1(Sink sink__V71, Term term__V72)
{
  int term__V72_count = LINK_COUNT(term__V72); permitUnusedInt(term__V72_count);
  do {
    /* Contraction rule HEADER-H-Declarations-1. */
    ASSERT(sink__V71->context, !strcmp(SYMBOL(term__V72),  "H-Declarations$1" ));
    Term sub__V73 = LINK(sink__V71->context, SUB(term__V72, 0)); int sub__V73_count = term__V72_count*LINK_COUNT(sub__V73); permitUnusedInt(sub__V73_count);
    /* sub__V73 = &#11 */
    Term sub__V74 = LINK(sink__V71->context, SUB(term__V72, 1)); int sub__V74_count = term__V72_count*LINK_COUNT(sub__V74); permitUnusedInt(sub__V74_count);
    /* sub__V74 = &#12 */
    
    NamedPropertyLink namedP__V75 = LINK_NamedPropertyLink(sink__V71->context, NAMED_PROPERTIES(term__V72));
    VariablePropertyLink varP__V76 = LINK_VariablePropertyLink(sink__V71->context, VARIABLE_PROPERTIES(term__V72));
    Hashset namedFV__V77 = LINK_VARIABLESET(sink__V71->context, asConstruction(term__V72)->properties->namedFreeVars);
    Hashset varFV__V78 = LINK_VARIABLESET(sink__V71->context, asConstruction(term__V72)->properties->variableFreeVars);
    UNLINK(sink__V71->context, term__V72);
    { START(sink__V71, _M__sTextCons);
      { START(sink__V71, _M__sTextEmbed);
        { START(sink__V71, _M_AsText);
          { START(sink__V71, _M_H_Declaration);
            COPY(sink__V71, sub__V73);END(sink__V71, _M_H_Declaration); }
          END(sink__V71, _M_AsText); }
        END(sink__V71, _M__sTextEmbed); }
      { START(sink__V71, _M__sTextCons);
        { START(sink__V71, _M__sTextEmbed);
          { START(sink__V71, _M_AsText);
            { START(sink__V71, _M_H_Declarations);
              COPY(sink__V71, sub__V74);END(sink__V71, _M_H_Declarations); }
            END(sink__V71, _M_AsText); }
          END(sink__V71, _M__sTextEmbed); }
        { START(sink__V71, _M__sTextNil);
          END(sink__V71, _M__sTextNil); }
        END(sink__V71, _M__sTextCons); }
      END(sink__V71, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V71->context, namedFV__V77); UNLINK_VARIABLESET(sink__V71->context, varFV__V78);
    UNLINK_NamedPropertyLink(sink__V71->context, namedP__V75); UNLINK_VariablePropertyLink(sink__V71->context, varP__V76);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Declarations$2. */
int conBindOffs_M_H_Declarations_s2[] = {0};
char *nameFun_M_H_Declarations_s2(Term term) { return  "H-Declarations$2" ; }
struct _ConstructionDescriptor descriptor_M_H_Declarations_s2 = {&sort_M_Reified_xVariable, 0, 0, sizeof(STRUCT_Con_M_H_Declarations_s2), conBindOffs_M_H_Declarations_s2, &nameFun_M_H_Declarations_s2, &step_M_H_Declarations_s2};

int step_M_H_Declarations_s2(Sink sink__V79, Term term__V80)
{
  int term__V80_count = LINK_COUNT(term__V80); permitUnusedInt(term__V80_count);
  do {
    /* Contraction rule HEADER-H-Declarations-2. */
    ASSERT(sink__V79->context, !strcmp(SYMBOL(term__V80),  "H-Declarations$2" ));
    
    NamedPropertyLink namedP__V81 = LINK_NamedPropertyLink(sink__V79->context, NAMED_PROPERTIES(term__V80));
    VariablePropertyLink varP__V82 = LINK_VariablePropertyLink(sink__V79->context, VARIABLE_PROPERTIES(term__V80));
    Hashset namedFV__V83 = LINK_VARIABLESET(sink__V79->context, asConstruction(term__V80)->properties->namedFreeVars);
    Hashset varFV__V84 = LINK_VARIABLESET(sink__V79->context, asConstruction(term__V80)->properties->variableFreeVars);
    UNLINK(sink__V79->context, term__V80);
    { START(sink__V79, _M__sTextNil); END(sink__V79, _M__sTextNil); } UNLINK_VARIABLESET(sink__V79->context, namedFV__V83); UNLINK_VARIABLESET(sink__V79->context, varFV__V84);
    UNLINK_NamedPropertyLink(sink__V79->context, namedP__V81); UNLINK_VariablePropertyLink(sink__V79->context, varP__V82);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION ComputeHeader$1. */
int conBindOffs_M_ComputeHeader_s1[] = {0 , 0 , 0};
char *nameFun_M_ComputeHeader_s1(Term term) { return  "ComputeHeader$1" ; }
struct _ConstructionDescriptor descriptor_M_ComputeHeader_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_ComputeHeader_s1), conBindOffs_M_ComputeHeader_s1, &nameFun_M_ComputeHeader_s1, &step_M_ComputeHeader_s1};

int step_M_ComputeHeader_s1(Sink sink__V85, Term term__V86)
{
  int term__V86_count = LINK_COUNT(term__V86); permitUnusedInt(term__V86_count);
  do {
    /* Contraction rule HEADER-ComputeHeader-1. */
    ASSERT(sink__V85->context, !strcmp(SYMBOL(term__V86),  "ComputeHeader$1" ));
    Term sub__V87 = LINK(sink__V85->context, SUB(term__V86, 0)); int sub__V87_count = term__V86_count*LINK_COUNT(sub__V87); permitUnusedInt(sub__V87_count);
    /* sub__V87 = &#11 */
    Term sub__V88 = LINK(sink__V85->context, SUB(term__V86, 1)); int sub__V88_count = term__V86_count*LINK_COUNT(sub__V88); permitUnusedInt(sub__V88_count);
    /* sub__V88 = &#12 */
    
    NamedPropertyLink namedP__V89 = LINK_NamedPropertyLink(sink__V85->context, NAMED_PROPERTIES(term__V86));
    VariablePropertyLink varP__V90 = LINK_VariablePropertyLink(sink__V85->context, VARIABLE_PROPERTIES(term__V86));
    Hashset namedFV__V91 = LINK_VARIABLESET(sink__V85->context, asConstruction(term__V86)->properties->namedFreeVars);
    Hashset varFV__V92 = LINK_VARIABLESET(sink__V85->context, asConstruction(term__V86)->properties->variableFreeVars);
    UNLINK(sink__V85->context, term__V86);
    { START(sink__V85, _M_ComputeHeader2);
      COPY(sink__V85, sub__V87);COPY(sink__V85, sub__V88);{ Term term__V93;
        { char *value__V94 = getenv( "MODULE" );
          if (value__V94) term__V93 = makeStringLiteral(sink__V85->context, value__V94);
          else {term__V93 = makeStringLiteral(sink__V85->context,  "" ); }
        }
        COPY(sink__V85, term__V93); /*CONSERVATIVE*/ }
      END(sink__V85, _M_ComputeHeader2); }
    UNLINK_VARIABLESET(sink__V85->context, namedFV__V91); UNLINK_VARIABLESET(sink__V85->context, varFV__V92);
    UNLINK_NamedPropertyLink(sink__V85->context, namedP__V89); UNLINK_VariablePropertyLink(sink__V85->context, varP__V90);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Form$2. */
int conBindOffs_M_H_Form_s2[] = {0 , 0 , 0};
char *nameFun_M_H_Form_s2(Term term) { return  "H-Form$2" ; }
struct _ConstructionDescriptor descriptor_M_H_Form_s2 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_H_Form_s2), conBindOffs_M_H_Form_s2, &nameFun_M_H_Form_s2, &step_M_H_Form_s2};

int step_M_H_Form_s2(Sink sink__V95, Term term__V96)
{
  int term__V96_count = LINK_COUNT(term__V96); permitUnusedInt(term__V96_count);
  Term sub__V97 = FORCE(sink__V95->context, SUB(term__V96, 0));
  EnumOf_M__sList choice__V98 = (IS_VARIABLE_USE(sub__V97) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V97));
  switch (choice__V98)
  {
    case Data_M__sNil: { /* Function HEADER-H-Form-3$H-Form$2$$Nil case $Nil */
      ASSERT(sink__V95->context, !strcmp(SYMBOL(term__V96),  "H-Form$2" ));
      Term sub__V99 = SUB(term__V96, 0); permitUnusedTerm(sub__V99); int sub__V99_count = term__V96_count*LINK_COUNT(sub__V99); permitUnusedInt(sub__V99_count);
      ASSERT(sink__V95->context, !strcmp(SYMBOL(sub__V99),  "$Nil" ));
      Term sub__V100 = LINK(sink__V95->context, SUB(term__V96, 1)); int sub__V100_count = term__V96_count*LINK_COUNT(sub__V100); permitUnusedInt(sub__V100_count);
      /* sub__V100 = &#0 */
      
      NamedPropertyLink namedP__V101 = LINK_NamedPropertyLink(sink__V95->context, NAMED_PROPERTIES(term__V96));
      VariablePropertyLink varP__V102 = LINK_VariablePropertyLink(sink__V95->context, VARIABLE_PROPERTIES(term__V96));
      Hashset namedFV__V103 = LINK_VARIABLESET(sink__V95->context, asConstruction(term__V96)->properties->namedFreeVars);
      Hashset varFV__V104 = LINK_VARIABLESET(sink__V95->context, asConstruction(term__V96)->properties->variableFreeVars);
      UNLINK(sink__V95->context, term__V96);
      ADD_PROPERTIES(sink__V95, LINK_VARIABLESET(sink__V95->context, namedFV__V103), LINK_VARIABLESET(sink__V95->context, varFV__V104), LINK_NamedPropertyLink(sink__V95->context, namedP__V101), LINK_VariablePropertyLink(sink__V95->context, varP__V102));
      { START(sink__V95, _M_H_Form_s4);
        COPY(sink__V95, sub__V100);END(sink__V95, _M_H_Form_s4); }
      UNLINK_VARIABLESET(sink__V95->context, namedFV__V103); UNLINK_VARIABLESET(sink__V95->context, varFV__V104);
      UNLINK_NamedPropertyLink(sink__V95->context, namedP__V101); UNLINK_VariablePropertyLink(sink__V95->context, varP__V102);
      
      return 1;
    break; } case Data_M__sCons: { /* Function HEADER-H-Form-4$H-Form$2$$Cons case $Cons */
      ASSERT(sink__V95->context, !strcmp(SYMBOL(term__V96),  "H-Form$2" ));
      Term sub__V105 = SUB(term__V96, 0); permitUnusedTerm(sub__V105); int sub__V105_count = term__V96_count*LINK_COUNT(sub__V105); permitUnusedInt(sub__V105_count);
      ASSERT(sink__V95->context, !strcmp(SYMBOL(sub__V105),  "$Cons" ));
      Term sub__V106 = LINK(sink__V95->context, SUB(sub__V105, 0)); int sub__V106_count = sub__V105_count*LINK_COUNT(sub__V106); permitUnusedInt(sub__V106_count);
      /* sub__V106 = &#0-0 */
      Term sub__V107 = LINK(sink__V95->context, SUB(sub__V105, 1)); int sub__V107_count = sub__V105_count*LINK_COUNT(sub__V107); permitUnusedInt(sub__V107_count);
      /* sub__V107 = &#0-1 */
      Term sub__V108 = LINK(sink__V95->context, SUB(term__V96, 1)); int sub__V108_count = term__V96_count*LINK_COUNT(sub__V108); permitUnusedInt(sub__V108_count);
      /* sub__V108 = &#2 */
      
      NamedPropertyLink namedP__V109 = LINK_NamedPropertyLink(sink__V95->context, NAMED_PROPERTIES(term__V96));
      VariablePropertyLink varP__V110 = LINK_VariablePropertyLink(sink__V95->context, VARIABLE_PROPERTIES(term__V96));
      Hashset namedFV__V111 = LINK_VARIABLESET(sink__V95->context, asConstruction(term__V96)->properties->namedFreeVars);
      Hashset varFV__V112 = LINK_VARIABLESET(sink__V95->context, asConstruction(term__V96)->properties->variableFreeVars);
      UNLINK(sink__V95->context, term__V96);
      ADD_PROPERTIES(sink__V95, LINK_VARIABLESET(sink__V95->context, namedFV__V111), LINK_VARIABLESET(sink__V95->context, varFV__V112), LINK_NamedPropertyLink(sink__V95->context, namedP__V109), LINK_VariablePropertyLink(sink__V95->context, varP__V110));
      { START(sink__V95, _M_H_Form_s3);
        COPY(sink__V95, sub__V106);COPY(sink__V95, sub__V107);COPY(sink__V95, sub__V108);END(sink__V95, _M_H_Form_s3); }
      UNLINK_VARIABLESET(sink__V95->context, namedFV__V111); UNLINK_VARIABLESET(sink__V95->context, varFV__V112);
      UNLINK_NamedPropertyLink(sink__V95->context, namedP__V109); UNLINK_VariablePropertyLink(sink__V95->context, varP__V110);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION H-Form$3. */
int conBindOffs_M_H_Form_s3[] = {0 , 0 , 0 , 0};
char *nameFun_M_H_Form_s3(Term term) { return  "H-Form$3" ; }
struct _ConstructionDescriptor descriptor_M_H_Form_s3 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_H_Form_s3), conBindOffs_M_H_Form_s3, &nameFun_M_H_Form_s3, &step_M_H_Form_s3};

int step_M_H_Form_s3(Sink sink__V113, Term term__V114)
{
  int term__V114_count = LINK_COUNT(term__V114); permitUnusedInt(term__V114_count);
  do {
    /* Contraction rule HEADER-H-Form-4. */
    ASSERT(sink__V113->context, !strcmp(SYMBOL(term__V114),  "H-Form$3" ));
    Term sub__V115 = LINK(sink__V113->context, SUB(term__V114, 0)); int sub__V115_count = term__V114_count*LINK_COUNT(sub__V115); permitUnusedInt(sub__V115_count);
    /* sub__V115 = &#121 */
    Term sub__V116 = LINK(sink__V113->context, SUB(term__V114, 1)); int sub__V116_count = term__V114_count*LINK_COUNT(sub__V116); permitUnusedInt(sub__V116_count);
    /* sub__V116 = &#122 */
    Term sub__V117 = LINK(sink__V113->context, SUB(term__V114, 2)); int sub__V117_count = term__V114_count*LINK_COUNT(sub__V117); permitUnusedInt(sub__V117_count);
    /* sub__V117 = &#11 */
    
    NamedPropertyLink namedP__V118 = LINK_NamedPropertyLink(sink__V113->context, NAMED_PROPERTIES(term__V114));
    VariablePropertyLink varP__V119 = LINK_VariablePropertyLink(sink__V113->context, VARIABLE_PROPERTIES(term__V114));
    Hashset namedFV__V120 = LINK_VARIABLESET(sink__V113->context, asConstruction(term__V114)->properties->namedFreeVars);
    Hashset varFV__V121 = LINK_VARIABLESET(sink__V113->context, asConstruction(term__V114)->properties->variableFreeVars);
    UNLINK(sink__V113->context, term__V114);
    { START(sink__V113, _M__sTextCons);
      { START(sink__V113, _M__sTextChars);
        LITERAL(sink__V113,  "#define STRUCT" ); END(sink__V113, _M__sTextChars); }
      { START(sink__V113, _M__sTextCons);
        { START(sink__V113, _M__sTextEmbed);
          { START(sink__V113, _M_AsText);
            { START(sink__V113, _M_Struct);
              COPY(sink__V113, LINK(sink__V113->context, sub__V117));END(sink__V113, _M_Struct); }
            END(sink__V113, _M_AsText); }
          END(sink__V113, _M__sTextEmbed); }
        { START(sink__V113, _M__sTextCons);
          { START(sink__V113, _M__sTextChars);
            LITERAL(sink__V113,  " struct " ); END(sink__V113, _M__sTextChars); }
          { START(sink__V113, _M__sTextCons);
            { START(sink__V113, _M__sTextEmbed);
              { START(sink__V113, _M_AsText);
                { START(sink__V113, _M_Struct);
                  COPY(sink__V113, LINK(sink__V113->context, sub__V117));END(sink__V113, _M_Struct); }
                END(sink__V113, _M_AsText); }
              END(sink__V113, _M__sTextEmbed); }
            { START(sink__V113, _M__sTextCons);
              { START(sink__V113, _M__sTextBreak);
                LITERAL(sink__V113,  "\n" ); END(sink__V113, _M__sTextBreak); }
              { START(sink__V113, _M__sTextCons);
                { START(sink__V113, _M__sTextChars);
                  LITERAL(sink__V113,  "struct " ); END(sink__V113, _M__sTextChars); }
                { START(sink__V113, _M__sTextCons);
                  { START(sink__V113, _M__sTextEmbed);
                    { START(sink__V113, _M_AsText);
                      { START(sink__V113, _M_Struct);
                        COPY(sink__V113, LINK(sink__V113->context, sub__V117));END(sink__V113, _M_Struct); }
                      END(sink__V113, _M_AsText); }
                    END(sink__V113, _M__sTextEmbed); }
                  { START(sink__V113, _M__sTextCons);
                    { START(sink__V113, _M__sTextChars);
                      LITERAL(sink__V113,  " {struct _Construction construction; Term sub[" );
                      END(sink__V113, _M__sTextChars); }
                    { START(sink__V113, _M__sTextCons);
                      { START(sink__V113, _M__sTextEmbed);
                        { START(sink__V113, _M_AsText);
                          { START(sink__V113, _M_INTEGER);
                            { START(sink__V113, _M_Length);
                              COPY(sink__V113, LINK(sink__V113->context, sub__V116));LITERAL(sink__V113,  "1" ); END(sink__V113, _M_Length); }
                            END(sink__V113, _M_INTEGER); }
                          END(sink__V113, _M_AsText); }
                        END(sink__V113, _M__sTextEmbed); }
                      { START(sink__V113, _M__sTextCons);
                        { START(sink__V113, _M__sTextChars);
                          LITERAL(sink__V113,  "]; Variable binder[" );
                          END(sink__V113, _M__sTextChars); }
                        { START(sink__V113, _M__sTextCons);
                          { START(sink__V113, _M__sTextEmbed);
                            { START(sink__V113, _M_AsText);
                              { START(sink__V113, _M_INTEGER);
                                { START(sink__V113, _M_FormArguments__binder__count);
                                  { START(sink__V113, _M__sCons);
                                    COPY(sink__V113, sub__V115);COPY(sink__V113, sub__V116);END(sink__V113, _M__sCons); }
                                  LITERAL(sink__V113,  "0" ); END(sink__V113, _M_FormArguments__binder__count); }
                                END(sink__V113, _M_INTEGER); }
                              END(sink__V113, _M_AsText); }
                            END(sink__V113, _M__sTextEmbed); }
                          { START(sink__V113, _M__sTextCons);
                            { START(sink__V113, _M__sTextChars);
                              LITERAL(sink__V113,  "];};" ); END(sink__V113, _M__sTextChars); }
                            { START(sink__V113, _M__sTextCons);
                              { START(sink__V113, _M__sTextBreak);
                                LITERAL(sink__V113,  "\n" ); END(sink__V113, _M__sTextBreak); }
                              { START(sink__V113, _M__sTextCons);
                                { START(sink__V113, _M__sTextChars);
                                  LITERAL(sink__V113,  "extern struct _ConstructionDescriptor " );
                                  END(sink__V113, _M__sTextChars); }
                                { START(sink__V113, _M__sTextCons);
                                  { START(sink__V113, _M__sTextEmbed);
                                    { START(sink__V113, _M_AsText);
                                      { START(sink__V113, _M_Descriptor);
                                        COPY(sink__V113, sub__V117);END(sink__V113, _M_Descriptor); }
                                      END(sink__V113, _M_AsText); }
                                    END(sink__V113, _M__sTextEmbed); }
                                  { START(sink__V113, _M__sTextCons);
                                    { START(sink__V113, _M__sTextChars);
                                      LITERAL(sink__V113,  ";" ); END(sink__V113, _M__sTextChars); }
                                    { START(sink__V113, _M__sTextCons);
                                      { START(sink__V113, _M__sTextBreak);
                                        LITERAL(sink__V113,  "\n" ); END(sink__V113, _M__sTextBreak); }
                                      { START(sink__V113, _M__sTextNil);
                                        END(sink__V113, _M__sTextNil); }
                                      END(sink__V113, _M__sTextCons); }
                                    END(sink__V113, _M__sTextCons); }
                                  END(sink__V113, _M__sTextCons); }
                                END(sink__V113, _M__sTextCons); }
                              END(sink__V113, _M__sTextCons); }
                            END(sink__V113, _M__sTextCons); }
                          END(sink__V113, _M__sTextCons); }
                        END(sink__V113, _M__sTextCons); }
                      END(sink__V113, _M__sTextCons); }
                    END(sink__V113, _M__sTextCons); }
                  END(sink__V113, _M__sTextCons); }
                END(sink__V113, _M__sTextCons); }
              END(sink__V113, _M__sTextCons); }
            END(sink__V113, _M__sTextCons); }
          END(sink__V113, _M__sTextCons); }
        END(sink__V113, _M__sTextCons); }
      END(sink__V113, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V113->context, namedFV__V120); UNLINK_VARIABLESET(sink__V113->context, varFV__V121);
    UNLINK_NamedPropertyLink(sink__V113->context, namedP__V118); UNLINK_VariablePropertyLink(sink__V113->context, varP__V119);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Form$4. */
int conBindOffs_M_H_Form_s4[] = {0 , 0};
char *nameFun_M_H_Form_s4(Term term) { return  "H-Form$4" ; }
struct _ConstructionDescriptor descriptor_M_H_Form_s4 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_H_Form_s4), conBindOffs_M_H_Form_s4, &nameFun_M_H_Form_s4, &step_M_H_Form_s4};

int step_M_H_Form_s4(Sink sink__V122, Term term__V123)
{
  int term__V123_count = LINK_COUNT(term__V123); permitUnusedInt(term__V123_count);
  do {
    /* Contraction rule HEADER-H-Form-3. */
    ASSERT(sink__V122->context, !strcmp(SYMBOL(term__V123),  "H-Form$4" ));
    Term sub__V124 = LINK(sink__V122->context, SUB(term__V123, 0)); int sub__V124_count = term__V123_count*LINK_COUNT(sub__V124); permitUnusedInt(sub__V124_count);
    /* sub__V124 = &#11 */
    
    NamedPropertyLink namedP__V125 = LINK_NamedPropertyLink(sink__V122->context, NAMED_PROPERTIES(term__V123));
    VariablePropertyLink varP__V126 = LINK_VariablePropertyLink(sink__V122->context, VARIABLE_PROPERTIES(term__V123));
    Hashset namedFV__V127 = LINK_VARIABLESET(sink__V122->context, asConstruction(term__V123)->properties->namedFreeVars);
    Hashset varFV__V128 = LINK_VARIABLESET(sink__V122->context, asConstruction(term__V123)->properties->variableFreeVars);
    UNLINK(sink__V122->context, term__V123);
    { START(sink__V122, _M__sTextCons);
      { START(sink__V122, _M__sTextChars);
        LITERAL(sink__V122,  "#define STRUCT" ); END(sink__V122, _M__sTextChars); }
      { START(sink__V122, _M__sTextCons);
        { START(sink__V122, _M__sTextEmbed);
          { START(sink__V122, _M_AsText);
            { START(sink__V122, _M_Struct);
              COPY(sink__V122, LINK(sink__V122->context, sub__V124));END(sink__V122, _M_Struct); }
            END(sink__V122, _M_AsText); }
          END(sink__V122, _M__sTextEmbed); }
        { START(sink__V122, _M__sTextCons);
          { START(sink__V122, _M__sTextChars);
            LITERAL(sink__V122,  " struct _ConstantConstruction" ); END(sink__V122, _M__sTextChars); }
          { START(sink__V122, _M__sTextCons);
            { START(sink__V122, _M__sTextBreak);
              LITERAL(sink__V122,  "\n" ); END(sink__V122, _M__sTextBreak); }
            { START(sink__V122, _M__sTextCons);
              { START(sink__V122, _M__sTextChars);
                LITERAL(sink__V122,  "extern struct _ConstructionDescriptor " );
                END(sink__V122, _M__sTextChars); }
              { START(sink__V122, _M__sTextCons);
                { START(sink__V122, _M__sTextEmbed);
                  { START(sink__V122, _M_AsText);
                    { START(sink__V122, _M_Descriptor);
                      COPY(sink__V122, sub__V124);END(sink__V122, _M_Descriptor); }
                    END(sink__V122, _M_AsText); }
                  END(sink__V122, _M__sTextEmbed); }
                { START(sink__V122, _M__sTextCons);
                  { START(sink__V122, _M__sTextChars);
                    LITERAL(sink__V122,  ";" ); END(sink__V122, _M__sTextChars); }
                  { START(sink__V122, _M__sTextCons);
                    { START(sink__V122, _M__sTextBreak);
                      LITERAL(sink__V122,  "\n" ); END(sink__V122, _M__sTextBreak); }
                    { START(sink__V122, _M__sTextNil);
                      END(sink__V122, _M__sTextNil); }
                    END(sink__V122, _M__sTextCons); }
                  END(sink__V122, _M__sTextCons); }
                END(sink__V122, _M__sTextCons); }
              END(sink__V122, _M__sTextCons); }
            END(sink__V122, _M__sTextCons); }
          END(sink__V122, _M__sTextCons); }
        END(sink__V122, _M__sTextCons); }
      END(sink__V122, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V122->context, namedFV__V127); UNLINK_VARIABLESET(sink__V122->context, varFV__V128);
    UNLINK_NamedPropertyLink(sink__V122->context, namedP__V125); UNLINK_VariablePropertyLink(sink__V122->context, varP__V126);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Form$5. */
int conBindOffs_M_H_Form_s5[] = {0};
char *nameFun_M_H_Form_s5(Term term) { return  "H-Form$5" ; }
struct _ConstructionDescriptor descriptor_M_H_Form_s5 = {&sort_M_Reified_xVariable, 0, 0, sizeof(STRUCT_Con_M_H_Form_s5), conBindOffs_M_H_Form_s5, &nameFun_M_H_Form_s5, &step_M_H_Form_s5};

int step_M_H_Form_s5(Sink sink__V129, Term term__V130)
{
  int term__V130_count = LINK_COUNT(term__V130); permitUnusedInt(term__V130_count);
  do {
    /* Contraction rule HEADER-H-Form-2. */
    ASSERT(sink__V129->context, !strcmp(SYMBOL(term__V130),  "H-Form$5" ));
    
    NamedPropertyLink namedP__V131 = LINK_NamedPropertyLink(sink__V129->context, NAMED_PROPERTIES(term__V130));
    VariablePropertyLink varP__V132 = LINK_VariablePropertyLink(sink__V129->context, VARIABLE_PROPERTIES(term__V130));
    Hashset namedFV__V133 = LINK_VARIABLESET(sink__V129->context, asConstruction(term__V130)->properties->namedFreeVars);
    Hashset varFV__V134 = LINK_VARIABLESET(sink__V129->context, asConstruction(term__V130)->properties->variableFreeVars);
    UNLINK(sink__V129->context, term__V130);
    { START(sink__V129, _M__sTextNil); END(sink__V129, _M__sTextNil); }
    UNLINK_VARIABLESET(sink__V129->context, namedFV__V133); UNLINK_VARIABLESET(sink__V129->context, varFV__V134);
    UNLINK_NamedPropertyLink(sink__V129->context, namedP__V131); UNLINK_VariablePropertyLink(sink__V129->context, varP__V132);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Form$6. */
int conBindOffs_M_H_Form_s6[] = {0 , 0 , 0 , 0};
char *nameFun_M_H_Form_s6(Term term) { return  "H-Form$6" ; }
struct _ConstructionDescriptor descriptor_M_H_Form_s6 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_H_Form_s6), conBindOffs_M_H_Form_s6, &nameFun_M_H_Form_s6, &step_M_H_Form_s6};

int step_M_H_Form_s6(Sink sink__V135, Term term__V136)
{
  int term__V136_count = LINK_COUNT(term__V136); permitUnusedInt(term__V136_count);
  do {
    /* Contraction rule HEADER-H-Form-1. */
    ASSERT(sink__V135->context, !strcmp(SYMBOL(term__V136),  "H-Form$6" ));
    Term sub__V137 = SUB(term__V136, 0); permitUnusedTerm(sub__V137); int sub__V137_count = term__V136_count*LINK_COUNT(sub__V137); permitUnusedInt(sub__V137_count);
    CRSX_CHECK_SORT(sink__V135->context, sub__V137, &sort_M_Reified_xSort); /* sub__V137 = &#11 */
    Term sub__V138 = SUB(term__V136, 1); permitUnusedTerm(sub__V138); int sub__V138_count = term__V136_count*LINK_COUNT(sub__V138); permitUnusedInt(sub__V138_count);
    CRSX_CHECK_SORT(sink__V135->context, sub__V138, &sort_M_Reified_xSort); /* sub__V138 = &#12 */
    Term sub__V139 = LINK(sink__V135->context, SUB(term__V136, 2)); int sub__V139_count = term__V136_count*LINK_COUNT(sub__V139); permitUnusedInt(sub__V139_count);
    CRSX_CHECK_SORT(sink__V135->context, sub__V139, &sort_M_Reified_xForm); /* sub__V139 = &#13 */
    
    NamedPropertyLink namedP__V140 = LINK_NamedPropertyLink(sink__V135->context, NAMED_PROPERTIES(term__V136));
    VariablePropertyLink varP__V141 = LINK_VariablePropertyLink(sink__V135->context, VARIABLE_PROPERTIES(term__V136));
    Hashset namedFV__V142 = LINK_VARIABLESET(sink__V135->context, asConstruction(term__V136)->properties->namedFreeVars);
    Hashset varFV__V143 = LINK_VARIABLESET(sink__V135->context, asConstruction(term__V136)->properties->variableFreeVars);
    UNLINK(sink__V135->context, term__V136);
    { START(sink__V135, _M_H_Form);
      COPY(sink__V135, sub__V139);END(sink__V135, _M_H_Form); }
    UNLINK_VARIABLESET(sink__V135->context, namedFV__V142); UNLINK_VARIABLESET(sink__V135->context, varFV__V143);
    UNLINK_NamedPropertyLink(sink__V135->context, namedP__V140); UNLINK_VariablePropertyLink(sink__V135->context, varP__V141);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Declaration$1. */
int conBindOffs_M_H_Declaration_s1[] = {0 , 0 , 0};
char *nameFun_M_H_Declaration_s1(Term term) { return  "H-Declaration$1" ; }
struct _ConstructionDescriptor descriptor_M_H_Declaration_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_H_Declaration_s1), conBindOffs_M_H_Declaration_s1, &nameFun_M_H_Declaration_s1, &step_M_H_Declaration_s1};

int step_M_H_Declaration_s1(Sink sink__V144, Term term__V145)
{
  int term__V145_count = LINK_COUNT(term__V145); permitUnusedInt(term__V145_count);
  do {
    /* Contraction rule HEADER-Data. */
    ASSERT(sink__V144->context, !strcmp(SYMBOL(term__V145),  "H-Declaration$1" ));
    Term sub__V146 = LINK(sink__V144->context, SUB(term__V145, 0)); int sub__V146_count = term__V145_count*LINK_COUNT(sub__V146); permitUnusedInt(sub__V146_count);
    CRSX_CHECK_SORT(sink__V144->context, sub__V146, &sort_M_Reified_xSort); /* sub__V146 = &#11 */
    Term sub__V147 = LINK(sink__V144->context, SUB(term__V145, 1)); int sub__V147_count = term__V145_count*LINK_COUNT(sub__V147); permitUnusedInt(sub__V147_count);
    /* sub__V147 = &#12 */
    
    NamedPropertyLink namedP__V148 = LINK_NamedPropertyLink(sink__V144->context, NAMED_PROPERTIES(term__V145));
    VariablePropertyLink varP__V149 = LINK_VariablePropertyLink(sink__V144->context, VARIABLE_PROPERTIES(term__V145));
    Hashset namedFV__V150 = LINK_VARIABLESET(sink__V144->context, asConstruction(term__V145)->properties->namedFreeVars);
    Hashset varFV__V151 = LINK_VARIABLESET(sink__V144->context, asConstruction(term__V145)->properties->variableFreeVars);
    UNLINK(sink__V144->context, term__V145);
    { START(sink__V144, _M_H_Data);
      COPY(sink__V144, sub__V146);COPY(sink__V144, sub__V147);END(sink__V144, _M_H_Data); }
    UNLINK_VARIABLESET(sink__V144->context, namedFV__V150); UNLINK_VARIABLESET(sink__V144->context, varFV__V151);
    UNLINK_NamedPropertyLink(sink__V144->context, namedP__V148); UNLINK_VariablePropertyLink(sink__V144->context, varP__V149);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Declaration$2. */
int conBindOffs_M_H_Declaration_s2[] = {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0};
char *nameFun_M_H_Declaration_s2(Term term) { return  "H-Declaration$2" ; }
struct _ConstructionDescriptor descriptor_M_H_Declaration_s2 = {&sort_M_Reified_xVariable, 0, 7, sizeof(STRUCT_Con_M_H_Declaration_s2), conBindOffs_M_H_Declaration_s2, &nameFun_M_H_Declaration_s2, &step_M_H_Declaration_s2};

int step_M_H_Declaration_s2(Sink sink__V152, Term term__V153)
{
  int term__V153_count = LINK_COUNT(term__V153); permitUnusedInt(term__V153_count);
  do {
    /* Contraction rule HEADER-Function. */
    ASSERT(sink__V152->context, !strcmp(SYMBOL(term__V153),  "H-Declaration$2" ));
    Term sub__V154 = LINK(sink__V152->context, SUB(term__V153, 0)); int sub__V154_count = term__V153_count*LINK_COUNT(sub__V154); permitUnusedInt(sub__V154_count);
    /* sub__V154 = &#11 */
    Term sub__V155 = LINK(sink__V152->context, SUB(term__V153, 1)); int sub__V155_count = term__V153_count*LINK_COUNT(sub__V155); permitUnusedInt(sub__V155_count);
    /* sub__V155 = &#12 */
    Term sub__V156 = LINK(sink__V152->context, SUB(term__V153, 2)); int sub__V156_count = term__V153_count*LINK_COUNT(sub__V156); permitUnusedInt(sub__V156_count);
    /* sub__V156 = &#13 */
    Term sub__V157 = LINK(sink__V152->context, SUB(term__V153, 3)); int sub__V157_count = term__V153_count*LINK_COUNT(sub__V157); permitUnusedInt(sub__V157_count);
    /* sub__V157 = &#14 */
    Term sub__V158 = LINK(sink__V152->context, SUB(term__V153, 4)); int sub__V158_count = term__V153_count*LINK_COUNT(sub__V158); permitUnusedInt(sub__V158_count);
    /* sub__V158 = &#15 */
    Term sub__V159 = LINK(sink__V152->context, SUB(term__V153, 5)); int sub__V159_count = term__V153_count*LINK_COUNT(sub__V159); permitUnusedInt(sub__V159_count);
    CRSX_CHECK_SORT(sink__V152->context, sub__V159, &sort_M_Reified_xSort); /* sub__V159 = &#16 */
    Term sub__V160 = LINK(sink__V152->context, SUB(term__V153, 6)); int sub__V160_count = term__V153_count*LINK_COUNT(sub__V160); permitUnusedInt(sub__V160_count);
    /* sub__V160 = &#17 */
    
    NamedPropertyLink namedP__V161 = LINK_NamedPropertyLink(sink__V152->context, NAMED_PROPERTIES(term__V153));
    VariablePropertyLink varP__V162 = LINK_VariablePropertyLink(sink__V152->context, VARIABLE_PROPERTIES(term__V153));
    Hashset namedFV__V163 = LINK_VARIABLESET(sink__V152->context, asConstruction(term__V153)->properties->namedFreeVars);
    Hashset varFV__V164 = LINK_VARIABLESET(sink__V152->context, asConstruction(term__V153)->properties->variableFreeVars);
    UNLINK(sink__V152->context, term__V153);
    { START(sink__V152, _M_H_Function);
      COPY(sink__V152, sub__V154);COPY(sink__V152, sub__V155);COPY(sink__V152, sub__V156);COPY(sink__V152, sub__V157);COPY(sink__V152, sub__V158);COPY(sink__V152, sub__V159);COPY(sink__V152, sub__V160);END(sink__V152, _M_H_Function); }
    UNLINK_VARIABLESET(sink__V152->context, namedFV__V163); UNLINK_VARIABLESET(sink__V152->context, varFV__V164);
    UNLINK_NamedPropertyLink(sink__V152->context, namedP__V161); UNLINK_VariablePropertyLink(sink__V152->context, varP__V162);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Declaration$3. */
int conBindOffs_M_H_Declaration_s3[] = {0 , 1};
char *nameFun_M_H_Declaration_s3(Term term) { return  "H-Declaration$3" ; }
struct _ConstructionDescriptor descriptor_M_H_Declaration_s3 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_H_Declaration_s3), conBindOffs_M_H_Declaration_s3, &nameFun_M_H_Declaration_s3, &step_M_H_Declaration_s3};

int step_M_H_Declaration_s3(Sink sink__V165, Term term__V166)
{
  int term__V166_count = LINK_COUNT(term__V166); permitUnusedInt(term__V166_count);
  do {
    /* Contraction rule HEADER-Polymorphic. */
    ASSERT(sink__V165->context, !strcmp(SYMBOL(term__V166),  "H-Declaration$3" ));
    Variable x__V167 = BINDER(term__V166,0,0); if (term__V166_count <= 1) UNBIND(x__V167);
    Term sub__V168 = LINK(sink__V165->context, SUB(term__V166, 0)); int sub__V168_count = term__V166_count*LINK_COUNT(sub__V168); permitUnusedInt(sub__V168_count);
    CRSX_CHECK_SORT(sink__V165->context, sub__V168, &sort_M_Reified_xDeclaration); /* sub__V168 = &#11 */
    Variable y__V169 = x__V167; permitUnusedVariable(y__V169);
    
    NamedPropertyLink namedP__V170 = LINK_NamedPropertyLink(sink__V165->context, NAMED_PROPERTIES(term__V166));
    VariablePropertyLink varP__V171 = LINK_VariablePropertyLink(sink__V165->context, VARIABLE_PROPERTIES(term__V166));
    Hashset namedFV__V172 = LINK_VARIABLESET(sink__V165->context, asConstruction(term__V166)->properties->namedFreeVars);
    Hashset varFV__V173 = LINK_VARIABLESET(sink__V165->context, asConstruction(term__V166)->properties->variableFreeVars);
    UNLINK(sink__V165->context, term__V166);
    { START(sink__V165, _M_H_Declaration);
      COPY(sink__V165, sub__V168); /* REUSED SUBSTITUTION */ END(sink__V165, _M_H_Declaration); }
    UNLINK_VARIABLESET(sink__V165->context, namedFV__V172); UNLINK_VARIABLESET(sink__V165->context, varFV__V173);
    UNLINK_NamedPropertyLink(sink__V165->context, namedP__V170); UNLINK_VariablePropertyLink(sink__V165->context, varP__V171);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Data$1. */
int conBindOffs_M_H_Data_s1[] = {0 , 0 , 0 , 0};
char *nameFun_M_H_Data_s1(Term term) { return  "H-Data$1" ; }
struct _ConstructionDescriptor descriptor_M_H_Data_s1 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_H_Data_s1), conBindOffs_M_H_Data_s1, &nameFun_M_H_Data_s1, &step_M_H_Data_s1};

int step_M_H_Data_s1(Sink sink__V174, Term term__V175)
{
  int term__V175_count = LINK_COUNT(term__V175); permitUnusedInt(term__V175_count);
  do {
    /* Contraction rule HEADER-H-Data-1. */
    ASSERT(sink__V174->context, !strcmp(SYMBOL(term__V175),  "H-Data$1" ));
    Term sub__V176 = LINK(sink__V174->context, SUB(term__V175, 0)); int sub__V176_count = term__V175_count*LINK_COUNT(sub__V176); permitUnusedInt(sub__V176_count);
    /* sub__V176 = &#11 */
    Term sub__V177 = SUB(term__V175, 1); permitUnusedTerm(sub__V177); int sub__V177_count = term__V175_count*LINK_COUNT(sub__V177); permitUnusedInt(sub__V177_count);
    /* sub__V177 = &#12 */
    Term sub__V178 = LINK(sink__V174->context, SUB(term__V175, 2)); int sub__V178_count = term__V175_count*LINK_COUNT(sub__V178); permitUnusedInt(sub__V178_count);
    /* sub__V178 = &#2 */
    
    NamedPropertyLink namedP__V179 = LINK_NamedPropertyLink(sink__V174->context, NAMED_PROPERTIES(term__V175));
    VariablePropertyLink varP__V180 = LINK_VariablePropertyLink(sink__V174->context, VARIABLE_PROPERTIES(term__V175));
    Hashset namedFV__V181 = LINK_VARIABLESET(sink__V174->context, asConstruction(term__V175)->properties->namedFreeVars);
    Hashset varFV__V182 = LINK_VARIABLESET(sink__V174->context, asConstruction(term__V175)->properties->variableFreeVars);
    UNLINK(sink__V174->context, term__V175);
    { START(sink__V174, _M__sTextCons);
      { START(sink__V174, _M__sTextBreak);
        LITERAL(sink__V174,  "\n" ); END(sink__V174, _M__sTextBreak); }
      { START(sink__V174, _M__sTextCons);
        { START(sink__V174, _M__sTextChars);
          LITERAL(sink__V174,  "/* DATA SORT " ); END(sink__V174, _M__sTextChars); }
        { START(sink__V174, _M__sTextCons);
          { START(sink__V174, _M__sTextEmbed);
            { START(sink__V174, _M_AsText);
              { START(sink__V174, _M_COMMENT_xTOKEN);
                COPY(sink__V174, LINK(sink__V174->context, sub__V176));END(sink__V174, _M_COMMENT_xTOKEN); }
              END(sink__V174, _M_AsText); }
            END(sink__V174, _M__sTextEmbed); }
          { START(sink__V174, _M__sTextCons);
            { START(sink__V174, _M__sTextChars);
              LITERAL(sink__V174,  " HEADER DECLARATIONS. */" ); END(sink__V174, _M__sTextChars); }
            { START(sink__V174, _M__sTextCons);
              { START(sink__V174, _M__sTextBreak);
                LITERAL(sink__V174,  "\n" ); END(sink__V174, _M__sTextBreak); }
              { START(sink__V174, _M__sTextCons);
                { START(sink__V174, _M__sTextChars);
                  LITERAL(sink__V174,  "typedef enum {" ); END(sink__V174, _M__sTextChars); }
                { START(sink__V174, _M__sTextCons);
                  { START(sink__V174, _M__sTextEmbed);
                    { START(sink__V174, _M_AsText);
                      { START(sink__V174, _M_EnumFun);
                        COPY(sink__V174, LINK(sink__V174->context, sub__V176));END(sink__V174, _M_EnumFun); }
                      END(sink__V174, _M_AsText); }
                    END(sink__V174, _M__sTextEmbed); }
                  { START(sink__V174, _M__sTextCons);
                    { START(sink__V174, _M__sTextChars);
                      LITERAL(sink__V174,  " = 0, " ); END(sink__V174, _M__sTextChars); }
                    { START(sink__V174, _M__sTextCons);
                      { START(sink__V174, _M__sTextEmbed);
                        { START(sink__V174, _M_AsText);
                          { START(sink__V174, _M_EnumVar);
                            COPY(sink__V174, LINK(sink__V174->context, sub__V176));END(sink__V174, _M_EnumVar); }
                          END(sink__V174, _M_AsText); }
                        END(sink__V174, _M__sTextEmbed); }
                      { START(sink__V174, _M__sTextCons);
                        { START(sink__V174, _M__sTextChars);
                          LITERAL(sink__V174,  " = 1" ); END(sink__V174, _M__sTextChars); }
                        { START(sink__V174, _M__sTextCons);
                          { START(sink__V174, _M__sTextEmbed);
                            { START(sink__V174, _M_AsText);
                              { START(sink__V174, _M_DelayMapText_s1);
                                { START(sink__V174, _M_Forms_Constructors);
                                  COPY(sink__V174, LINK(sink__V174->context, sub__V178));END(sink__V174, _M_Forms_Constructors); }
                                { Variable x__V183 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V174->context,"x__V183");
                                  Variable x__V184 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V174->context,"x__V184");
                                  Variable binds__V185[2] = {x__V183,x__V184}; BINDS(sink__V174, 2, binds__V185);
                                  { START(sink__V174, _M__sTextCons);
                                    { START(sink__V174, _M__sTextChars);
                                      LITERAL(sink__V174,  ", " ); END(sink__V174, _M__sTextChars); }
                                    { START(sink__V174, _M__sTextCons);
                                      { START(sink__V174, _M__sTextEmbed);
                                        { START(sink__V174, _M_AsText);
                                          { START(sink__V174, _M_DEnumTag);
                                            USE(sink__V174, x__V183); USE(sink__V174, x__V184); END(sink__V174, _M_DEnumTag); }
                                          END(sink__V174, _M_AsText); }
                                        END(sink__V174, _M__sTextEmbed); }
                                      { START(sink__V174, _M__sTextNil);
                                        END(sink__V174, _M__sTextNil); }
                                      END(sink__V174, _M__sTextCons); }
                                    END(sink__V174, _M__sTextCons); }
                                   }
                                END(sink__V174, _M_DelayMapText_s1); }
                              END(sink__V174, _M_AsText); }
                            END(sink__V174, _M__sTextEmbed); }
                          { START(sink__V174, _M__sTextCons);
                            { START(sink__V174, _M__sTextChars);
                              LITERAL(sink__V174,  "} " ); END(sink__V174, _M__sTextChars); }
                            { START(sink__V174, _M__sTextCons);
                              { START(sink__V174, _M__sTextEmbed);
                                { START(sink__V174, _M_AsText);
                                  { START(sink__V174, _M_Enum);
                                    COPY(sink__V174, LINK(sink__V174->context, sub__V176));END(sink__V174, _M_Enum); }
                                  END(sink__V174, _M_AsText); }
                                END(sink__V174, _M__sTextEmbed); }
                              { START(sink__V174, _M__sTextCons);
                                { START(sink__V174, _M__sTextChars);
                                  LITERAL(sink__V174,  ";" ); END(sink__V174, _M__sTextChars); }
                                { START(sink__V174, _M__sTextCons);
                                  { START(sink__V174, _M__sTextBreak);
                                    LITERAL(sink__V174,  "\n" ); END(sink__V174, _M__sTextBreak); }
                                  { START(sink__V174, _M__sTextCons);
                                    { START(sink__V174, _M__sTextEmbed);
                                      { START(sink__V174, _M_AsText);
                                        { START(sink__V174, _M_MapText_s1);
                                          COPY(sink__V174, sub__V178);{ Variable x__V186 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V174->context,"x__V186");
                                            Variable binds__V187[1] = {x__V186}; BINDS(sink__V174, 1, binds__V187);
                                            { START(sink__V174, _M_H_Form);
                                              USE(sink__V174, x__V186);
                                              END(sink__V174, _M_H_Form); }
                                             }
                                          END(sink__V174, _M_MapText_s1); }
                                        END(sink__V174, _M_AsText); }
                                      END(sink__V174, _M__sTextEmbed); }
                                    { START(sink__V174, _M__sTextCons);
                                      { START(sink__V174, _M__sTextChars);
                                        LITERAL(sink__V174,  "extern struct _SortDescriptor " );
                                        END(sink__V174, _M__sTextChars); }
                                      { START(sink__V174, _M__sTextCons);
                                        { START(sink__V174, _M__sTextEmbed);
                                          { START(sink__V174, _M_AsText);
                                            { START(sink__V174, _M_Sort);
                                              COPY(sink__V174, sub__V176);END(sink__V174, _M_Sort); }
                                            END(sink__V174, _M_AsText); }
                                          END(sink__V174, _M__sTextEmbed); }
                                        { START(sink__V174, _M__sTextCons);
                                          { START(sink__V174, _M__sTextChars);
                                            LITERAL(sink__V174,  ";" );
                                            END(sink__V174, _M__sTextChars); }
                                          { START(sink__V174, _M__sTextCons);
                                            { START(sink__V174, _M__sTextBreak);
                                              LITERAL(sink__V174,  "\n" );
                                              END(sink__V174, _M__sTextBreak); }
                                            { START(sink__V174, _M__sTextNil);
                                              END(sink__V174, _M__sTextNil); }
                                            END(sink__V174, _M__sTextCons); }
                                          END(sink__V174, _M__sTextCons); }
                                        END(sink__V174, _M__sTextCons); }
                                      END(sink__V174, _M__sTextCons); }
                                    END(sink__V174, _M__sTextCons); }
                                  END(sink__V174, _M__sTextCons); }
                                END(sink__V174, _M__sTextCons); }
                              END(sink__V174, _M__sTextCons); }
                            END(sink__V174, _M__sTextCons); }
                          END(sink__V174, _M__sTextCons); }
                        END(sink__V174, _M__sTextCons); }
                      END(sink__V174, _M__sTextCons); }
                    END(sink__V174, _M__sTextCons); }
                  END(sink__V174, _M__sTextCons); }
                END(sink__V174, _M__sTextCons); }
              END(sink__V174, _M__sTextCons); }
            END(sink__V174, _M__sTextCons); }
          END(sink__V174, _M__sTextCons); }
        END(sink__V174, _M__sTextCons); }
      END(sink__V174, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V174->context, namedFV__V181); UNLINK_VARIABLESET(sink__V174->context, varFV__V182);
    UNLINK_NamedPropertyLink(sink__V174->context, namedP__V179); UNLINK_VariablePropertyLink(sink__V174->context, varP__V180);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Data$2. */
int conBindOffs_M_H_Data_s2[] = {0 , 0 , 0 , 0 , 0};
char *nameFun_M_H_Data_s2(Term term) { return  "H-Data$2" ; }
struct _ConstructionDescriptor descriptor_M_H_Data_s2 = {&sort_M_Reified_xVariable, 0, 4, sizeof(STRUCT_Con_M_H_Data_s2), conBindOffs_M_H_Data_s2, &nameFun_M_H_Data_s2, &step_M_H_Data_s2};

int step_M_H_Data_s2(Sink sink__V188, Term term__V189)
{
  int term__V189_count = LINK_COUNT(term__V189); permitUnusedInt(term__V189_count);
  do {
    /* Contraction rule HEADER-H-Data-2. */
    ASSERT(sink__V188->context, !strcmp(SYMBOL(term__V189),  "H-Data$2" ));
    Term sub__V190 = SUB(term__V189, 0); permitUnusedTerm(sub__V190); int sub__V190_count = term__V189_count*LINK_COUNT(sub__V190); permitUnusedInt(sub__V190_count);
    CRSX_CHECK_SORT(sink__V188->context, sub__V190, &sort_M_Reified_xSort); /* sub__V190 = &#11 */
    Term sub__V191 = SUB(term__V189, 1); permitUnusedTerm(sub__V191); int sub__V191_count = term__V189_count*LINK_COUNT(sub__V191); permitUnusedInt(sub__V191_count);
    CRSX_CHECK_SORT(sink__V188->context, sub__V191, &sort_M_Reified_xSort); /* sub__V191 = &#12 */
    Term sub__V192 = LINK(sink__V188->context, SUB(term__V189, 2)); int sub__V192_count = term__V189_count*LINK_COUNT(sub__V192); permitUnusedInt(sub__V192_count);
    CRSX_CHECK_SORT(sink__V188->context, sub__V192, &sort_M_Reified_xSort); /* sub__V192 = &#13 */
    Term sub__V193 = LINK(sink__V188->context, SUB(term__V189, 3)); int sub__V193_count = term__V189_count*LINK_COUNT(sub__V193); permitUnusedInt(sub__V193_count);
    /* sub__V193 = &#2 */
    
    NamedPropertyLink namedP__V194 = LINK_NamedPropertyLink(sink__V188->context, NAMED_PROPERTIES(term__V189));
    VariablePropertyLink varP__V195 = LINK_VariablePropertyLink(sink__V188->context, VARIABLE_PROPERTIES(term__V189));
    Hashset namedFV__V196 = LINK_VARIABLESET(sink__V188->context, asConstruction(term__V189)->properties->namedFreeVars);
    Hashset varFV__V197 = LINK_VARIABLESET(sink__V188->context, asConstruction(term__V189)->properties->variableFreeVars);
    UNLINK(sink__V188->context, term__V189);
    { START(sink__V188, _M_H_Data);
      COPY(sink__V188, sub__V192);COPY(sink__V188, sub__V193);END(sink__V188, _M_H_Data); }
    UNLINK_VARIABLESET(sink__V188->context, namedFV__V196); UNLINK_VARIABLESET(sink__V188->context, varFV__V197);
    UNLINK_NamedPropertyLink(sink__V188->context, namedP__V194); UNLINK_VariablePropertyLink(sink__V188->context, varP__V195);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Declarations. */
int conBindOffs_M_H_Declarations[] = {0 , 0};
char *nameFun_M_H_Declarations(Term term) { return  "H-Declarations" ; }
struct _ConstructionDescriptor descriptor_M_H_Declarations = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_H_Declarations), conBindOffs_M_H_Declarations, &nameFun_M_H_Declarations, &step_M_H_Declarations};

int step_M_H_Declarations(Sink sink__V198, Term term__V199)
{
  int term__V199_count = LINK_COUNT(term__V199); permitUnusedInt(term__V199_count);
  Term sub__V200 = FORCE(sink__V198->context, SUB(term__V199, 0));
  EnumOf_M__sList choice__V201 = (IS_VARIABLE_USE(sub__V200) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V200));
  switch (choice__V201)
  {
    case Data_M__sCons: { /* Function HEADER-H-Declarations-1$H-Declarations$$Cons case $Cons */
      ASSERT(sink__V198->context, !strcmp(SYMBOL(term__V199),  "H-Declarations" ));
      Term sub__V202 = SUB(term__V199, 0); permitUnusedTerm(sub__V202); int sub__V202_count = term__V199_count*LINK_COUNT(sub__V202); permitUnusedInt(sub__V202_count);
      ASSERT(sink__V198->context, !strcmp(SYMBOL(sub__V202),  "$Cons" ));
      Term sub__V203 = LINK(sink__V198->context, SUB(sub__V202, 0)); int sub__V203_count = sub__V202_count*LINK_COUNT(sub__V203); permitUnusedInt(sub__V203_count);
      /* sub__V203 = &#0-0 */
      Term sub__V204 = LINK(sink__V198->context, SUB(sub__V202, 1)); int sub__V204_count = sub__V202_count*LINK_COUNT(sub__V204); permitUnusedInt(sub__V204_count);
      /* sub__V204 = &#0-1 */
      
      NamedPropertyLink namedP__V205 = LINK_NamedPropertyLink(sink__V198->context, NAMED_PROPERTIES(term__V199));
      VariablePropertyLink varP__V206 = LINK_VariablePropertyLink(sink__V198->context, VARIABLE_PROPERTIES(term__V199));
      Hashset namedFV__V207 = LINK_VARIABLESET(sink__V198->context, asConstruction(term__V199)->properties->namedFreeVars);
      Hashset varFV__V208 = LINK_VARIABLESET(sink__V198->context, asConstruction(term__V199)->properties->variableFreeVars);
      UNLINK(sink__V198->context, term__V199);
      ADD_PROPERTIES(sink__V198, LINK_VARIABLESET(sink__V198->context, namedFV__V207), LINK_VARIABLESET(sink__V198->context, varFV__V208), LINK_NamedPropertyLink(sink__V198->context, namedP__V205), LINK_VariablePropertyLink(sink__V198->context, varP__V206));
      { START(sink__V198, _M_H_Declarations_s1);
        COPY(sink__V198, sub__V203);COPY(sink__V198, sub__V204);END(sink__V198, _M_H_Declarations_s1); }
      UNLINK_VARIABLESET(sink__V198->context, namedFV__V207); UNLINK_VARIABLESET(sink__V198->context, varFV__V208);
      UNLINK_NamedPropertyLink(sink__V198->context, namedP__V205); UNLINK_VariablePropertyLink(sink__V198->context, varP__V206);
      
      return 1;
    break; } case Data_M__sNil: { /* Function HEADER-H-Declarations-2$H-Declarations$$Nil case $Nil */
      ASSERT(sink__V198->context, !strcmp(SYMBOL(term__V199),  "H-Declarations" ));
      Term sub__V209 = SUB(term__V199, 0); permitUnusedTerm(sub__V209); int sub__V209_count = term__V199_count*LINK_COUNT(sub__V209); permitUnusedInt(sub__V209_count);
      ASSERT(sink__V198->context, !strcmp(SYMBOL(sub__V209),  "$Nil" ));
      
      NamedPropertyLink namedP__V210 = LINK_NamedPropertyLink(sink__V198->context, NAMED_PROPERTIES(term__V199));
      VariablePropertyLink varP__V211 = LINK_VariablePropertyLink(sink__V198->context, VARIABLE_PROPERTIES(term__V199));
      Hashset namedFV__V212 = LINK_VARIABLESET(sink__V198->context, asConstruction(term__V199)->properties->namedFreeVars);
      Hashset varFV__V213 = LINK_VARIABLESET(sink__V198->context, asConstruction(term__V199)->properties->variableFreeVars);
      UNLINK(sink__V198->context, term__V199);
      ADD_PROPERTIES(sink__V198, LINK_VARIABLESET(sink__V198->context, namedFV__V212), LINK_VARIABLESET(sink__V198->context, varFV__V213), LINK_NamedPropertyLink(sink__V198->context, namedP__V210), LINK_VariablePropertyLink(sink__V198->context, varP__V211));
      { START(sink__V198, _M_H_Declarations_s2);
        END(sink__V198, _M_H_Declarations_s2); }
      UNLINK_VARIABLESET(sink__V198->context, namedFV__V212); UNLINK_VARIABLESET(sink__V198->context, varFV__V213);
      UNLINK_NamedPropertyLink(sink__V198->context, namedP__V210); UNLINK_VariablePropertyLink(sink__V198->context, varP__V211);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION H-Function. */
int conBindOffs_M_H_Function[] = {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0};
char *nameFun_M_H_Function(Term term) { return  "H-Function" ; }
struct _ConstructionDescriptor descriptor_M_H_Function = {&sort_M_Reified_xVariable, 0, 7, sizeof(STRUCT_Con_M_H_Function), conBindOffs_M_H_Function, &nameFun_M_H_Function, &step_M_H_Function};

int step_M_H_Function(Sink sink__V214, Term term__V215)
{
  int term__V215_count = LINK_COUNT(term__V215); permitUnusedInt(term__V215_count);
  do {
    /* Contraction rule HEADER-H-Function-1. */
    ASSERT(sink__V214->context, !strcmp(SYMBOL(term__V215),  "H-Function" ));
    Term sub__V216 = LINK(sink__V214->context, SUB(term__V215, 0)); int sub__V216_count = term__V215_count*LINK_COUNT(sub__V216); permitUnusedInt(sub__V216_count);
    /* sub__V216 = &#1 */
    Term sub__V217 = SUB(term__V215, 1); permitUnusedTerm(sub__V217); int sub__V217_count = term__V215_count*LINK_COUNT(sub__V217); permitUnusedInt(sub__V217_count);
    /* sub__V217 = &#2 */
    Term sub__V218 = SUB(term__V215, 2); permitUnusedTerm(sub__V218); int sub__V218_count = term__V215_count*LINK_COUNT(sub__V218); permitUnusedInt(sub__V218_count);
    /* sub__V218 = &#3 */
    Term sub__V219 = LINK(sink__V214->context, SUB(term__V215, 3)); int sub__V219_count = term__V215_count*LINK_COUNT(sub__V219); permitUnusedInt(sub__V219_count);
    /* sub__V219 = &#4 */
    Term sub__V220 = LINK(sink__V214->context, SUB(term__V215, 4)); int sub__V220_count = term__V215_count*LINK_COUNT(sub__V220); permitUnusedInt(sub__V220_count);
    /* sub__V220 = &#5 */
    Term sub__V221 = SUB(term__V215, 5); permitUnusedTerm(sub__V221); int sub__V221_count = term__V215_count*LINK_COUNT(sub__V221); permitUnusedInt(sub__V221_count);
    CRSX_CHECK_SORT(sink__V214->context, sub__V221, &sort_M_Reified_xSort); /* sub__V221 = &#6 */
    Term sub__V222 = SUB(term__V215, 6); permitUnusedTerm(sub__V222); int sub__V222_count = term__V215_count*LINK_COUNT(sub__V222); permitUnusedInt(sub__V222_count);
    /* sub__V222 = &#7 */
    
    NamedPropertyLink namedP__V223 = LINK_NamedPropertyLink(sink__V214->context, NAMED_PROPERTIES(term__V215));
    VariablePropertyLink varP__V224 = LINK_VariablePropertyLink(sink__V214->context, VARIABLE_PROPERTIES(term__V215));
    Hashset namedFV__V225 = LINK_VARIABLESET(sink__V214->context, asConstruction(term__V215)->properties->namedFreeVars);
    Hashset varFV__V226 = LINK_VARIABLESET(sink__V214->context, asConstruction(term__V215)->properties->variableFreeVars);
    UNLINK(sink__V214->context, term__V215);
    { START(sink__V214, _M__sTextCons);
      { START(sink__V214, _M__sTextBreak);
        LITERAL(sink__V214,  "\n" ); END(sink__V214, _M__sTextBreak); }
      { START(sink__V214, _M__sTextCons);
        { START(sink__V214, _M__sTextChars);
          LITERAL(sink__V214,  "/* FUNCTION " ); END(sink__V214, _M__sTextChars); }
        { START(sink__V214, _M__sTextCons);
          { START(sink__V214, _M__sTextEmbed);
            { START(sink__V214, _M_AsText);
              { START(sink__V214, _M_COMMENT_xTOKEN);
                COPY(sink__V214, sub__V216);END(sink__V214, _M_COMMENT_xTOKEN); }
              END(sink__V214, _M_AsText); }
            END(sink__V214, _M__sTextEmbed); }
          { START(sink__V214, _M__sTextCons);
            { START(sink__V214, _M__sTextChars);
              LITERAL(sink__V214,  " HEADER DECLARATIONS. */" ); END(sink__V214, _M__sTextChars); }
            { START(sink__V214, _M__sTextCons);
              { START(sink__V214, _M__sTextBreak);
                LITERAL(sink__V214,  "\n" ); END(sink__V214, _M__sTextBreak); }
              { START(sink__V214, _M__sTextCons);
                { START(sink__V214, _M__sTextEmbed);
                  { START(sink__V214, _M_AsText);
                    { START(sink__V214, _M_MapText_s1);
                      COPY(sink__V214, sub__V220);{ Variable x__V227 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V214->context,"x__V227");
                        Variable binds__V228[1] = {x__V227}; BINDS(sink__V214, 1, binds__V228);
                        { START(sink__V214, _M_H_Form);
                          USE(sink__V214, x__V227); END(sink__V214, _M_H_Form); }
                         }
                      END(sink__V214, _M_MapText_s1); }
                    END(sink__V214, _M_AsText); }
                  END(sink__V214, _M__sTextEmbed); }
                { START(sink__V214, _M__sTextCons);
                  { START(sink__V214, _M__sTextChars);
                    LITERAL(sink__V214,  "extern int " ); END(sink__V214, _M__sTextChars); }
                  { START(sink__V214, _M__sTextCons);
                    { START(sink__V214, _M__sTextEmbed);
                      { START(sink__V214, _M_AsText);
                        { START(sink__V214, _M_Step);
                          COPY(sink__V214, sub__V219);END(sink__V214, _M_Step); }
                        END(sink__V214, _M_AsText); }
                      END(sink__V214, _M__sTextEmbed); }
                    { START(sink__V214, _M__sTextCons);
                      { START(sink__V214, _M__sTextChars);
                        LITERAL(sink__V214,  "(Sink,Term);" ); END(sink__V214, _M__sTextChars); }
                      { START(sink__V214, _M__sTextCons);
                        { START(sink__V214, _M__sTextBreak);
                          LITERAL(sink__V214,  "\n" ); END(sink__V214, _M__sTextBreak); }
                        { START(sink__V214, _M__sTextNil);
                          END(sink__V214, _M__sTextNil); }
                        END(sink__V214, _M__sTextCons); }
                      END(sink__V214, _M__sTextCons); }
                    END(sink__V214, _M__sTextCons); }
                  END(sink__V214, _M__sTextCons); }
                END(sink__V214, _M__sTextCons); }
              END(sink__V214, _M__sTextCons); }
            END(sink__V214, _M__sTextCons); }
          END(sink__V214, _M__sTextCons); }
        END(sink__V214, _M__sTextCons); }
      END(sink__V214, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V214->context, namedFV__V225); UNLINK_VARIABLESET(sink__V214->context, varFV__V226);
    UNLINK_NamedPropertyLink(sink__V214->context, namedP__V223); UNLINK_VariablePropertyLink(sink__V214->context, varP__V224);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION ComputeHeader2. */
int conBindOffs_M_ComputeHeader2[] = {0 , 0 , 0 , 0};
char *nameFun_M_ComputeHeader2(Term term) { return  "ComputeHeader2" ; }
struct _ConstructionDescriptor descriptor_M_ComputeHeader2 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_ComputeHeader2), conBindOffs_M_ComputeHeader2, &nameFun_M_ComputeHeader2, &step_M_ComputeHeader2};

int step_M_ComputeHeader2(Sink sink__V229, Term term__V230)
{
  int term__V230_count = LINK_COUNT(term__V230); permitUnusedInt(term__V230_count);
  do {
    /* Contraction rule HEADER-ComputeHeader2-1. */
    ASSERT(sink__V229->context, !strcmp(SYMBOL(term__V230),  "ComputeHeader2" ));
    Term sub__V231 = LINK(sink__V229->context, SUB(term__V230, 0)); int sub__V231_count = term__V230_count*LINK_COUNT(sub__V231); permitUnusedInt(sub__V231_count);
    /* sub__V231 = &#1 */
    Term sub__V232 = LINK(sink__V229->context, SUB(term__V230, 1)); int sub__V232_count = term__V230_count*LINK_COUNT(sub__V232); permitUnusedInt(sub__V232_count);
    /* sub__V232 = &#2 */
    Term sub__V233 = LINK(sink__V229->context, SUB(term__V230, 2)); int sub__V233_count = term__V230_count*LINK_COUNT(sub__V233); permitUnusedInt(sub__V233_count);
    UNLINK_SUB(sink__V229->context, term__V230,  2); NORMALIZE(sink__V229->context, sub__V233); SUB(term__V230,  2) = LINK(sink__V229->context, sub__V233);
    /* sub__V233 = &#3 */
    
    NamedPropertyLink namedP__V234 = LINK_NamedPropertyLink(sink__V229->context, NAMED_PROPERTIES(term__V230));
    VariablePropertyLink varP__V235 = LINK_VariablePropertyLink(sink__V229->context, VARIABLE_PROPERTIES(term__V230));
    Hashset namedFV__V236 = LINK_VARIABLESET(sink__V229->context, asConstruction(term__V230)->properties->namedFreeVars);
    Hashset varFV__V237 = LINK_VARIABLESET(sink__V229->context, asConstruction(term__V230)->properties->variableFreeVars);
    UNLINK(sink__V229->context, term__V230);
    { START(sink__V229, _M__sTextCons);
      { START(sink__V229, _M__sTextChars);
        LITERAL(sink__V229,  "/* C HEADER FOR CRSX " ); END(sink__V229, _M__sTextChars); }
      { START(sink__V229, _M__sTextCons);
        { START(sink__V229, _M__sTextEmbed);
          { START(sink__V229, _M_AsText);
            { START(sink__V229, _M_COMMENT_xTOKEN);
              COPY(sink__V229, LINK(sink__V229->context, sub__V231));END(sink__V229, _M_COMMENT_xTOKEN); }
            END(sink__V229, _M_AsText); }
          END(sink__V229, _M__sTextEmbed); }
        { START(sink__V229, _M__sTextCons);
          { START(sink__V229, _M__sTextChars);
            LITERAL(sink__V229,  " MODULE " ); END(sink__V229, _M__sTextChars); }
          { START(sink__V229, _M__sTextCons);
            { START(sink__V229, _M__sTextEmbed);
              { START(sink__V229, _M_AsText);
                { START(sink__V229, _M_COMMENT_xTOKEN);
                  COPY(sink__V229, LINK(sink__V229->context, sub__V233));END(sink__V229, _M_COMMENT_xTOKEN); }
                END(sink__V229, _M_AsText); }
              END(sink__V229, _M__sTextEmbed); }
            { START(sink__V229, _M__sTextCons);
              { START(sink__V229, _M__sTextChars);
                LITERAL(sink__V229,  ". */" ); END(sink__V229, _M__sTextChars); }
              { START(sink__V229, _M__sTextCons);
                { START(sink__V229, _M__sTextBreak);
                  LITERAL(sink__V229,  "\n" ); END(sink__V229, _M__sTextBreak); }
                { START(sink__V229, _M__sTextCons);
                  { START(sink__V229, _M__sTextChars);
                    LITERAL(sink__V229,  "#ifndef CRSX_" ); END(sink__V229, _M__sTextChars); }
                  { START(sink__V229, _M__sTextCons);
                    { START(sink__V229, _M__sTextEmbed);
                      { START(sink__V229, _M_AsText);
                        { START(sink__V229, _M_MANGLE);
                          COPY(sink__V229, LINK(sink__V229->context, sub__V231));END(sink__V229, _M_MANGLE); }
                        END(sink__V229, _M_AsText); }
                      END(sink__V229, _M__sTextEmbed); }
                    { START(sink__V229, _M__sTextCons);
                      { START(sink__V229, _M__sTextEmbed);
                        { START(sink__V229, _M_AsText);
                          { START(sink__V229, _M_MANGLE);
                            COPY(sink__V229, LINK(sink__V229->context, sub__V233));END(sink__V229, _M_MANGLE); }
                          END(sink__V229, _M_AsText); }
                        END(sink__V229, _M__sTextEmbed); }
                      { START(sink__V229, _M__sTextCons);
                        { START(sink__V229, _M__sTextChars);
                          LITERAL(sink__V229,  "_H" ); END(sink__V229, _M__sTextChars); }
                        { START(sink__V229, _M__sTextCons);
                          { START(sink__V229, _M__sTextBreak);
                            LITERAL(sink__V229,  "\n" ); END(sink__V229, _M__sTextBreak); }
                          { START(sink__V229, _M__sTextCons);
                            { START(sink__V229, _M__sTextChars);
                              LITERAL(sink__V229,  "#define CRSX_" ); END(sink__V229, _M__sTextChars); }
                            { START(sink__V229, _M__sTextCons);
                              { START(sink__V229, _M__sTextEmbed);
                                { START(sink__V229, _M_AsText);
                                  { START(sink__V229, _M_MANGLE);
                                    COPY(sink__V229, LINK(sink__V229->context, sub__V231));END(sink__V229, _M_MANGLE); }
                                  END(sink__V229, _M_AsText); }
                                END(sink__V229, _M__sTextEmbed); }
                              { START(sink__V229, _M__sTextCons);
                                { START(sink__V229, _M__sTextEmbed);
                                  { START(sink__V229, _M_AsText);
                                    { START(sink__V229, _M_MANGLE);
                                      COPY(sink__V229, LINK(sink__V229->context, sub__V233));END(sink__V229, _M_MANGLE); }
                                    END(sink__V229, _M_AsText); }
                                  END(sink__V229, _M__sTextEmbed); }
                                { START(sink__V229, _M__sTextCons);
                                  { START(sink__V229, _M__sTextChars);
                                    LITERAL(sink__V229,  "_H" ); END(sink__V229, _M__sTextChars); }
                                  { START(sink__V229, _M__sTextCons);
                                    { START(sink__V229, _M__sTextBreak);
                                      LITERAL(sink__V229,  "\n" ); END(sink__V229, _M__sTextBreak); }
                                    { START(sink__V229, _M__sTextCons);
                                      { START(sink__V229, _M__sTextEmbed);
                                        { START(sink__V229, _M_AsText);
                                          { START(sink__V229, _M_DelayMapText_s1);
                                            {char* str__V238;{ Term term__V239;
                                                { char *value__V240 = getenv( "HEADERS" );
                                                  if (value__V240) term__V239 = makeStringLiteral(sink__V229->context, value__V240);
                                                  else {term__V239 = makeStringLiteral(sink__V229->context,  "" );
                                                    }
                                                }
                                                str__V238 = SYMBOL(term__V239);
                                                UNLINK(sink__V229->context, term__V239);
                                                }
                                              
                                              char* regex__V241;
                                              regex__V241 =  ";" ; SEND_SPLIT(str__V238, regex__V241, sink__V229);
                                            }
                                            { Variable x__V242 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V229->context,"x__V242");
                                              Variable x__V243 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V229->context,"x__V243");
                                              Variable binds__V244[2] = {x__V242,x__V243}; BINDS(sink__V229, 2, binds__V244);
                                              { START(sink__V229, _M__sTextCons);
                                                { START(sink__V229, _M__sTextChars);
                                                  LITERAL(sink__V229,  "#include \"" );
                                                  END(sink__V229, _M__sTextChars); }
                                                { START(sink__V229, _M__sTextCons);
                                                  { START(sink__V229, _M__sTextEmbed);
                                                    { START(sink__V229, _M_AsText);
                                                      { START(sink__V229, _M_DTOKEN);
                                                        USE(sink__V229, x__V242);
                                                        USE(sink__V229, x__V243);
                                                        END(sink__V229, _M_DTOKEN); }
                                                      END(sink__V229, _M_AsText); }
                                                    END(sink__V229, _M__sTextEmbed); }
                                                  { START(sink__V229, _M__sTextCons);
                                                    { START(sink__V229, _M__sTextChars);
                                                      LITERAL(sink__V229,  "\"" );
                                                      END(sink__V229, _M__sTextChars); }
                                                    { START(sink__V229, _M__sTextCons);
                                                      { START(sink__V229, _M__sTextBreak);
                                                        LITERAL(sink__V229,  "\n" );
                                                        END(sink__V229, _M__sTextBreak); }
                                                      { START(sink__V229, _M__sTextNil);
                                                        END(sink__V229, _M__sTextNil); }
                                                      END(sink__V229, _M__sTextCons); }
                                                    END(sink__V229, _M__sTextCons); }
                                                  END(sink__V229, _M__sTextCons); }
                                                END(sink__V229, _M__sTextCons); }
                                               }
                                            END(sink__V229, _M_DelayMapText_s1); }
                                          END(sink__V229, _M_AsText); }
                                        END(sink__V229, _M__sTextEmbed); }
                                      { START(sink__V229, _M__sTextCons);
                                        { START(sink__V229, _M__sTextBreak);
                                          LITERAL(sink__V229,  "\n" ); END(sink__V229, _M__sTextBreak); }
                                        { START(sink__V229, _M__sTextCons);
                                          { START(sink__V229, _M__sTextChars);
                                            LITERAL(sink__V229,  "#ifdef __cplusplus" );
                                            END(sink__V229, _M__sTextChars); }
                                          { START(sink__V229, _M__sTextCons);
                                            { START(sink__V229, _M__sTextBreak);
                                              LITERAL(sink__V229,  "\n" );
                                              END(sink__V229, _M__sTextBreak); }
                                            { START(sink__V229, _M__sTextCons);
                                              { START(sink__V229, _M__sTextChars);
                                                LITERAL(sink__V229,  "extern \"C\" {" );
                                                END(sink__V229, _M__sTextChars); }
                                              { START(sink__V229, _M__sTextCons);
                                                { START(sink__V229, _M__sTextBreak);
                                                  LITERAL(sink__V229,  "\n" );
                                                  END(sink__V229, _M__sTextBreak); }
                                                { START(sink__V229, _M__sTextCons);
                                                  { START(sink__V229, _M__sTextChars);
                                                    LITERAL(sink__V229,  "#endif" );
                                                    END(sink__V229, _M__sTextChars); }
                                                  { START(sink__V229, _M__sTextCons);
                                                    { START(sink__V229, _M__sTextBreak);
                                                      LITERAL(sink__V229,  "\n" );
                                                      END(sink__V229, _M__sTextBreak); }
                                                    { START(sink__V229, _M__sTextCons);
                                                      { START(sink__V229, _M__sTextEmbed);
                                                        { START(sink__V229, _M_AsText);
                                                          { START(sink__V229, _M_H_Declarations);
                                                            COPY(sink__V229, sub__V232);END(sink__V229, _M_H_Declarations); }
                                                          END(sink__V229, _M_AsText); }
                                                        END(sink__V229, _M__sTextEmbed); }
                                                      { START(sink__V229, _M__sTextCons);
                                                        { START(sink__V229, _M__sTextBreak);
                                                          LITERAL(sink__V229,  "\n" );
                                                          END(sink__V229, _M__sTextBreak); }
                                                        { START(sink__V229, _M__sTextCons);
                                                          { START(sink__V229, _M__sTextChars);
                                                            LITERAL(sink__V229,  "#ifdef __cplusplus" );
                                                            END(sink__V229, _M__sTextChars); }
                                                          { START(sink__V229, _M__sTextCons);
                                                            { START(sink__V229, _M__sTextBreak);
                                                              LITERAL(sink__V229,  "\n" );
                                                              END(sink__V229, _M__sTextBreak); }
                                                            { START(sink__V229, _M__sTextCons);
                                                              { START(sink__V229, _M__sTextChars);
                                                                LITERAL(sink__V229,  "}" );
                                                                END(sink__V229, _M__sTextChars); }
                                                              { START(sink__V229, _M__sTextCons);
                                                                { START(sink__V229, _M__sTextBreak);
                                                                  LITERAL(sink__V229,  "\n" );
                                                                  END(sink__V229, _M__sTextBreak); }
                                                                { START(sink__V229, _M__sTextCons);
                                                                  { START(sink__V229, _M__sTextChars);
                                                                    LITERAL(sink__V229,  "#endif" );
                                                                    END(sink__V229, _M__sTextChars); }
                                                                  { START(sink__V229, _M__sTextCons);
                                                                    { START(sink__V229, _M__sTextBreak);
                                                                      LITERAL(sink__V229,  "\n" );
                                                                      END(sink__V229, _M__sTextBreak); }
                                                                    { START(sink__V229, _M__sTextCons);
                                                                      { START(sink__V229, _M__sTextChars);
                                                                        LITERAL(sink__V229,  "/* END OF C HEADER FOR CRSX " );
                                                                        END(sink__V229, _M__sTextChars); }
                                                                      { START(sink__V229, _M__sTextCons);
                                                                        { START(sink__V229, _M__sTextEmbed);
                                                                          { START(sink__V229, _M_AsText);
                                                                            { START(sink__V229, _M_COMMENT_xTOKEN);
                                                                              COPY(sink__V229, sub__V231);END(sink__V229, _M_COMMENT_xTOKEN); }
                                                                            END(sink__V229, _M_AsText); }
                                                                          END(sink__V229, _M__sTextEmbed); }
                                                                        { START(sink__V229, _M__sTextCons);
                                                                          { START(sink__V229, _M__sTextChars);
                                                                            LITERAL(sink__V229,  " MODULE " );
                                                                            END(sink__V229, _M__sTextChars); }
                                                                          { START(sink__V229, _M__sTextCons);
                                                                            { START(sink__V229, _M__sTextEmbed);
                                                                              { START(sink__V229, _M_AsText);
                                                                                { START(sink__V229, _M_COMMENT_xTOKEN);
                                                                                  COPY(sink__V229, sub__V233);END(sink__V229, _M_COMMENT_xTOKEN); }
                                                                                END(sink__V229, _M_AsText); }
                                                                              END(sink__V229, _M__sTextEmbed); }
                                                                            { START(sink__V229, _M__sTextCons);
                                                                              { START(sink__V229, _M__sTextChars);
                                                                                LITERAL(sink__V229,  ". */" );
                                                                                END(sink__V229, _M__sTextChars); }
                                                                              { START(sink__V229, _M__sTextCons);
                                                                                { START(sink__V229, _M__sTextBreak);
                                                                                  LITERAL(sink__V229,  "\n" );
                                                                                  END(sink__V229, _M__sTextBreak); }
                                                                                { START(sink__V229, _M__sTextCons);
                                                                                  { START(sink__V229, _M__sTextChars);
                                                                                    LITERAL(sink__V229,  "#endif" );
                                                                                    END(sink__V229, _M__sTextChars); }
                                                                                  { START(sink__V229, _M__sTextCons);
                                                                                    { START(sink__V229, _M__sTextBreak);
                                                                                      LITERAL(sink__V229,  "\n" );
                                                                                      END(sink__V229, _M__sTextBreak); }
                                                                                    { START(sink__V229, _M__sTextNil);
                                                                                      END(sink__V229, _M__sTextNil); }
                                                                                    END(sink__V229, _M__sTextCons); }
                                                                                  END(sink__V229, _M__sTextCons); }
                                                                                END(sink__V229, _M__sTextCons); }
                                                                              END(sink__V229, _M__sTextCons); }
                                                                            END(sink__V229, _M__sTextCons); }
                                                                          END(sink__V229, _M__sTextCons); }
                                                                        END(sink__V229, _M__sTextCons); }
                                                                      END(sink__V229, _M__sTextCons); }
                                                                    END(sink__V229, _M__sTextCons); }
                                                                  END(sink__V229, _M__sTextCons); }
                                                                END(sink__V229, _M__sTextCons); }
                                                              END(sink__V229, _M__sTextCons); }
                                                            END(sink__V229, _M__sTextCons); }
                                                          END(sink__V229, _M__sTextCons); }
                                                        END(sink__V229, _M__sTextCons); }
                                                      END(sink__V229, _M__sTextCons); }
                                                    END(sink__V229, _M__sTextCons); }
                                                  END(sink__V229, _M__sTextCons); }
                                                END(sink__V229, _M__sTextCons); }
                                              END(sink__V229, _M__sTextCons); }
                                            END(sink__V229, _M__sTextCons); }
                                          END(sink__V229, _M__sTextCons); }
                                        END(sink__V229, _M__sTextCons); }
                                      END(sink__V229, _M__sTextCons); }
                                    END(sink__V229, _M__sTextCons); }
                                  END(sink__V229, _M__sTextCons); }
                                END(sink__V229, _M__sTextCons); }
                              END(sink__V229, _M__sTextCons); }
                            END(sink__V229, _M__sTextCons); }
                          END(sink__V229, _M__sTextCons); }
                        END(sink__V229, _M__sTextCons); }
                      END(sink__V229, _M__sTextCons); }
                    END(sink__V229, _M__sTextCons); }
                  END(sink__V229, _M__sTextCons); }
                END(sink__V229, _M__sTextCons); }
              END(sink__V229, _M__sTextCons); }
            END(sink__V229, _M__sTextCons); }
          END(sink__V229, _M__sTextCons); }
        END(sink__V229, _M__sTextCons); }
      END(sink__V229, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V229->context, namedFV__V236); UNLINK_VARIABLESET(sink__V229->context, varFV__V237);
    UNLINK_NamedPropertyLink(sink__V229->context, namedP__V234); UNLINK_VariablePropertyLink(sink__V229->context, varP__V235);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Form. */
int conBindOffs_M_H_Form[] = {0 , 0};
char *nameFun_M_H_Form(Term term) { return  "H-Form" ; }
struct _ConstructionDescriptor descriptor_M_H_Form = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_H_Form), conBindOffs_M_H_Form, &nameFun_M_H_Form, &step_M_H_Form};

int step_M_H_Form(Sink sink__V245, Term term__V246)
{
  int term__V246_count = LINK_COUNT(term__V246); permitUnusedInt(term__V246_count);
  Term sub__V247 = FORCE(sink__V245->context, SUB(term__V246, 0));
  EnumOf_M_Reified_xForm choice__V248 = (IS_VARIABLE_USE(sub__V247) ? VarOf_M_Reified_xForm : (EnumOf_M_Reified_xForm) TAG(sub__V247));
  switch (choice__V248)
  {
    case Data_M_SORT_SET: { /* Function HEADER-H-Form-1$H-Form$SORT-SET case SORT-SET */
      ASSERT(sink__V245->context, !strcmp(SYMBOL(term__V246),  "H-Form" ));
      Term sub__V249 = SUB(term__V246, 0); permitUnusedTerm(sub__V249); int sub__V249_count = term__V246_count*LINK_COUNT(sub__V249); permitUnusedInt(sub__V249_count);
      CRSX_CHECK_SORT(sink__V245->context, sub__V249, &sort_M_Reified_xForm); ASSERT(sink__V245->context, !strcmp(SYMBOL(sub__V249),  "SORT-SET" ));
      Term sub__V250 = LINK(sink__V245->context, SUB(sub__V249, 0)); int sub__V250_count = sub__V249_count*LINK_COUNT(sub__V250); permitUnusedInt(sub__V250_count);
      CRSX_CHECK_SORT(sink__V245->context, sub__V250, &sort_M_Reified_xSort); /* sub__V250 = &#0-0 */
      Term sub__V251 = LINK(sink__V245->context, SUB(sub__V249, 1)); int sub__V251_count = sub__V249_count*LINK_COUNT(sub__V251); permitUnusedInt(sub__V251_count);
      CRSX_CHECK_SORT(sink__V245->context, sub__V251, &sort_M_Reified_xSort); /* sub__V251 = &#0-1 */
      Term sub__V252 = LINK(sink__V245->context, SUB(sub__V249, 2)); int sub__V252_count = sub__V249_count*LINK_COUNT(sub__V252); permitUnusedInt(sub__V252_count);
      CRSX_CHECK_SORT(sink__V245->context, sub__V252, &sort_M_Reified_xForm); /* sub__V252 = &#0-2 */
      
      NamedPropertyLink namedP__V253 = LINK_NamedPropertyLink(sink__V245->context, NAMED_PROPERTIES(term__V246));
      VariablePropertyLink varP__V254 = LINK_VariablePropertyLink(sink__V245->context, VARIABLE_PROPERTIES(term__V246));
      Hashset namedFV__V255 = LINK_VARIABLESET(sink__V245->context, asConstruction(term__V246)->properties->namedFreeVars);
      Hashset varFV__V256 = LINK_VARIABLESET(sink__V245->context, asConstruction(term__V246)->properties->variableFreeVars);
      UNLINK(sink__V245->context, term__V246);
      ADD_PROPERTIES(sink__V245, LINK_VARIABLESET(sink__V245->context, namedFV__V255), LINK_VARIABLESET(sink__V245->context, varFV__V256), LINK_NamedPropertyLink(sink__V245->context, namedP__V253), LINK_VariablePropertyLink(sink__V245->context, varP__V254));
      { START(sink__V245, _M_H_Form_s6);
        COPY(sink__V245, sub__V250);COPY(sink__V245, sub__V251);COPY(sink__V245, sub__V252);END(sink__V245, _M_H_Form_s6); }
      UNLINK_VARIABLESET(sink__V245->context, namedFV__V255); UNLINK_VARIABLESET(sink__V245->context, varFV__V256);
      UNLINK_NamedPropertyLink(sink__V245->context, namedP__V253); UNLINK_VariablePropertyLink(sink__V245->context, varP__V254);
      
      return 1;
    break; } case Data_M_SORT_ALLOWS_VARIABLES: { /* Function HEADER-H-Form-2$H-Form$SORT-ALLOWS-VARIABLES case SORT-ALLOWS-VARIABLES */
      ASSERT(sink__V245->context, !strcmp(SYMBOL(term__V246),  "H-Form" ));
      Term sub__V257 = SUB(term__V246, 0); permitUnusedTerm(sub__V257); int sub__V257_count = term__V246_count*LINK_COUNT(sub__V257); permitUnusedInt(sub__V257_count);
      CRSX_CHECK_SORT(sink__V245->context, sub__V257, &sort_M_Reified_xForm); ASSERT(sink__V245->context, !strcmp(SYMBOL(sub__V257),  "SORT-ALLOWS-VARIABLES" ));
      
      NamedPropertyLink namedP__V258 = LINK_NamedPropertyLink(sink__V245->context, NAMED_PROPERTIES(term__V246));
      VariablePropertyLink varP__V259 = LINK_VariablePropertyLink(sink__V245->context, VARIABLE_PROPERTIES(term__V246));
      Hashset namedFV__V260 = LINK_VARIABLESET(sink__V245->context, asConstruction(term__V246)->properties->namedFreeVars);
      Hashset varFV__V261 = LINK_VARIABLESET(sink__V245->context, asConstruction(term__V246)->properties->variableFreeVars);
      UNLINK(sink__V245->context, term__V246);
      ADD_PROPERTIES(sink__V245, LINK_VARIABLESET(sink__V245->context, namedFV__V260), LINK_VARIABLESET(sink__V245->context, varFV__V261), LINK_NamedPropertyLink(sink__V245->context, namedP__V258), LINK_VariablePropertyLink(sink__V245->context, varP__V259));
      { START(sink__V245, _M_H_Form_s5);
        END(sink__V245, _M_H_Form_s5); }
      UNLINK_VARIABLESET(sink__V245->context, namedFV__V260); UNLINK_VARIABLESET(sink__V245->context, varFV__V261);
      UNLINK_NamedPropertyLink(sink__V245->context, namedP__V258); UNLINK_VariablePropertyLink(sink__V245->context, varP__V259);
      
      return 1;
    break; } case Data_M_FORM: { /* Function HEADER-H-Form-3$H-Form$FORM case FORM */
      ASSERT(sink__V245->context, !strcmp(SYMBOL(term__V246),  "H-Form" ));
      Term sub__V262 = SUB(term__V246, 0); permitUnusedTerm(sub__V262); int sub__V262_count = term__V246_count*LINK_COUNT(sub__V262); permitUnusedInt(sub__V262_count);
      CRSX_CHECK_SORT(sink__V245->context, sub__V262, &sort_M_Reified_xForm); ASSERT(sink__V245->context, !strcmp(SYMBOL(sub__V262),  "FORM" ));
      Term sub__V263 = LINK(sink__V245->context, SUB(sub__V262, 0)); int sub__V263_count = sub__V262_count*LINK_COUNT(sub__V263); permitUnusedInt(sub__V263_count);
      /* sub__V263 = &#0-0 */
      Term sub__V264 = LINK(sink__V245->context, SUB(sub__V262, 1)); int sub__V264_count = sub__V262_count*LINK_COUNT(sub__V264); permitUnusedInt(sub__V264_count);
      /* sub__V264 = &#0-1 */
      
      NamedPropertyLink namedP__V265 = LINK_NamedPropertyLink(sink__V245->context, NAMED_PROPERTIES(term__V246));
      VariablePropertyLink varP__V266 = LINK_VariablePropertyLink(sink__V245->context, VARIABLE_PROPERTIES(term__V246));
      Hashset namedFV__V267 = LINK_VARIABLESET(sink__V245->context, asConstruction(term__V246)->properties->namedFreeVars);
      Hashset varFV__V268 = LINK_VARIABLESET(sink__V245->context, asConstruction(term__V246)->properties->variableFreeVars);
      UNLINK(sink__V245->context, term__V246);
      ADD_PROPERTIES(sink__V245, LINK_VARIABLESET(sink__V245->context, namedFV__V267), LINK_VARIABLESET(sink__V245->context, varFV__V268), LINK_NamedPropertyLink(sink__V245->context, namedP__V265), LINK_VariablePropertyLink(sink__V245->context, varP__V266));
      { START(sink__V245, _M_H_Form_s2);
        COPY(sink__V245, sub__V264);COPY(sink__V245, sub__V263);END(sink__V245, _M_H_Form_s2); }
      UNLINK_VARIABLESET(sink__V245->context, namedFV__V267); UNLINK_VARIABLESET(sink__V245->context, varFV__V268);
      UNLINK_NamedPropertyLink(sink__V245->context, namedP__V265); UNLINK_VariablePropertyLink(sink__V245->context, varP__V266);
      
      return 1;
    } default: break;
  }
  return 0;
}

#ifdef __cplusplus
}
#endif
/* END OF C RULES FOR CRSX CRSXC MODULE HEADER. */
