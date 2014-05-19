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
    Hashset namedFV__V7 = LINK_VARIABLESET(sink__V1->context, asConstruction(term__V2)->properties->namedFreeVars);
    Hashset varFV__V8 = LINK_VARIABLESET(sink__V1->context, asConstruction(term__V2)->properties->variableFreeVars);
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

/* FUNCTION X-Data. */
int conBindOffs_M_X_Data[] = {0 , 0 , 0};
char *nameFun_M_X_Data(Term term) { return  "X-Data" ; }
struct _ConstructionDescriptor descriptor_M_X_Data = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_X_Data), conBindOffs_M_X_Data, &nameFun_M_X_Data, &step_M_X_Data};

int step_M_X_Data(Sink sink__V11, Term term__V12)
{
  int term__V12_count = LINK_COUNT(term__V12); permitUnusedInt(term__V12_count);
  Term sub__V13 = FORCE(sink__V11->context, SUB(term__V12, 0));
  EnumOf_M_Reified_xSort choice__V14 = (IS_VARIABLE_USE(sub__V13) ? VarOf_M_Reified_xSort : (EnumOf_M_Reified_xSort) TAG(sub__V13));
  switch (choice__V14)
  {
    case Data_M_SORT: { /* Function SYMBOLS-X-Data-1$X-Data$SORT case SORT */
      ASSERT(sink__V11->context, !strcmp(SYMBOL(term__V12),  "X-Data" ));
      Term sub__V15 = SUB(term__V12, 0); permitUnusedTerm(sub__V15); int sub__V15_count = term__V12_count*LINK_COUNT(sub__V15); permitUnusedInt(sub__V15_count);
      CRSX_CHECK_SORT(sink__V11->context, sub__V15, &sort_M_Reified_xSort); ASSERT(sink__V11->context, !strcmp(SYMBOL(sub__V15),  "SORT" ));
      Term sub__V16 = LINK(sink__V11->context, SUB(sub__V15, 0)); int sub__V16_count = sub__V15_count*LINK_COUNT(sub__V16); permitUnusedInt(sub__V16_count);
      /* sub__V16 = &#0-0 */
      Term sub__V17 = LINK(sink__V11->context, SUB(sub__V15, 1)); int sub__V17_count = sub__V15_count*LINK_COUNT(sub__V17); permitUnusedInt(sub__V17_count);
      /* sub__V17 = &#0-1 */
      Term sub__V18 = LINK(sink__V11->context, SUB(term__V12, 1)); int sub__V18_count = term__V12_count*LINK_COUNT(sub__V18); permitUnusedInt(sub__V18_count);
      /* sub__V18 = &#2 */
      
      NamedPropertyLink namedP__V19 = LINK_NamedPropertyLink(sink__V11->context, NAMED_PROPERTIES(term__V12));
      VariablePropertyLink varP__V20 = LINK_VariablePropertyLink(sink__V11->context, VARIABLE_PROPERTIES(term__V12));
      Hashset namedFV__V21 = LINK_VARIABLESET(sink__V11->context, asConstruction(term__V12)->properties->namedFreeVars);
      Hashset varFV__V22 = LINK_VARIABLESET(sink__V11->context, asConstruction(term__V12)->properties->variableFreeVars);
      UNLINK(sink__V11->context, term__V12);
      ADD_PROPERTIES(sink__V11, LINK_VARIABLESET(sink__V11->context, namedFV__V21), LINK_VARIABLESET(sink__V11->context, varFV__V22), LINK_NamedPropertyLink(sink__V11->context, namedP__V19), LINK_VariablePropertyLink(sink__V11->context, varP__V20));
      { START(sink__V11, _M_X_Data_s1);
        COPY(sink__V11, sub__V16);COPY(sink__V11, sub__V17);COPY(sink__V11, sub__V18);END(sink__V11, _M_X_Data_s1); }
      UNLINK_VARIABLESET(sink__V11->context, namedFV__V21); UNLINK_VARIABLESET(sink__V11->context, varFV__V22);
      UNLINK_NamedPropertyLink(sink__V11->context, namedP__V19); UNLINK_VariablePropertyLink(sink__V11->context, varP__V20);
      
      return 1;
    break; } case Data_M_SORT_PROPERTY: { /* Function SYMBOLS-X-Data-2$X-Data$SORT-PROPERTY case SORT-PROPERTY */
      ASSERT(sink__V11->context, !strcmp(SYMBOL(term__V12),  "X-Data" ));
      Term sub__V23 = SUB(term__V12, 0); permitUnusedTerm(sub__V23); int sub__V23_count = term__V12_count*LINK_COUNT(sub__V23); permitUnusedInt(sub__V23_count);
      CRSX_CHECK_SORT(sink__V11->context, sub__V23, &sort_M_Reified_xSort); ASSERT(sink__V11->context, !strcmp(SYMBOL(sub__V23),  "SORT-PROPERTY" ));
      Term sub__V24 = LINK(sink__V11->context, SUB(sub__V23, 0)); int sub__V24_count = sub__V23_count*LINK_COUNT(sub__V24); permitUnusedInt(sub__V24_count);
      CRSX_CHECK_SORT(sink__V11->context, sub__V24, &sort_M_Reified_xSort); /* sub__V24 = &#0-0 */
      Term sub__V25 = LINK(sink__V11->context, SUB(sub__V23, 1)); int sub__V25_count = sub__V23_count*LINK_COUNT(sub__V25); permitUnusedInt(sub__V25_count);
      CRSX_CHECK_SORT(sink__V11->context, sub__V25, &sort_M_Reified_xSort); /* sub__V25 = &#0-1 */
      Term sub__V26 = LINK(sink__V11->context, SUB(sub__V23, 2)); int sub__V26_count = sub__V23_count*LINK_COUNT(sub__V26); permitUnusedInt(sub__V26_count);
      CRSX_CHECK_SORT(sink__V11->context, sub__V26, &sort_M_Reified_xSort); /* sub__V26 = &#0-2 */
      Term sub__V27 = LINK(sink__V11->context, SUB(term__V12, 1)); int sub__V27_count = term__V12_count*LINK_COUNT(sub__V27); permitUnusedInt(sub__V27_count);
      /* sub__V27 = &#3 */
      
      NamedPropertyLink namedP__V28 = LINK_NamedPropertyLink(sink__V11->context, NAMED_PROPERTIES(term__V12));
      VariablePropertyLink varP__V29 = LINK_VariablePropertyLink(sink__V11->context, VARIABLE_PROPERTIES(term__V12));
      Hashset namedFV__V30 = LINK_VARIABLESET(sink__V11->context, asConstruction(term__V12)->properties->namedFreeVars);
      Hashset varFV__V31 = LINK_VARIABLESET(sink__V11->context, asConstruction(term__V12)->properties->variableFreeVars);
      UNLINK(sink__V11->context, term__V12);
      ADD_PROPERTIES(sink__V11, LINK_VARIABLESET(sink__V11->context, namedFV__V30), LINK_VARIABLESET(sink__V11->context, varFV__V31), LINK_NamedPropertyLink(sink__V11->context, namedP__V28), LINK_VariablePropertyLink(sink__V11->context, varP__V29));
      { START(sink__V11, _M_X_Data_s2);
        COPY(sink__V11, sub__V24);COPY(sink__V11, sub__V25);COPY(sink__V11, sub__V26);COPY(sink__V11, sub__V27);END(sink__V11, _M_X_Data_s2); }
      UNLINK_VARIABLESET(sink__V11->context, namedFV__V30); UNLINK_VARIABLESET(sink__V11->context, varFV__V31);
      UNLINK_NamedPropertyLink(sink__V11->context, namedP__V28); UNLINK_VariablePropertyLink(sink__V11->context, varP__V29);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION X-Declaration. */
int conBindOffs_M_X_Declaration[] = {0 , 0};
char *nameFun_M_X_Declaration(Term term) { return  "X-Declaration" ; }
struct _ConstructionDescriptor descriptor_M_X_Declaration = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_X_Declaration), conBindOffs_M_X_Declaration, &nameFun_M_X_Declaration, &step_M_X_Declaration};

int step_M_X_Declaration(Sink sink__V32, Term term__V33)
{
  int term__V33_count = LINK_COUNT(term__V33); permitUnusedInt(term__V33_count);
  Term sub__V34 = FORCE(sink__V32->context, SUB(term__V33, 0));
  EnumOf_M_Reified_xDeclaration choice__V35 = (IS_VARIABLE_USE(sub__V34) ? VarOf_M_Reified_xDeclaration : (EnumOf_M_Reified_xDeclaration) TAG(sub__V34));
  switch (choice__V35)
  {
    case Data_M_DATA: { /* Function SYMBOLS-Data$X-Declaration$DATA case DATA */
      ASSERT(sink__V32->context, !strcmp(SYMBOL(term__V33),  "X-Declaration" ));
      Term sub__V36 = SUB(term__V33, 0); permitUnusedTerm(sub__V36); int sub__V36_count = term__V33_count*LINK_COUNT(sub__V36); permitUnusedInt(sub__V36_count);
      CRSX_CHECK_SORT(sink__V32->context, sub__V36, &sort_M_Reified_xDeclaration); ASSERT(sink__V32->context, !strcmp(SYMBOL(sub__V36),  "DATA" ));
      Term sub__V37 = LINK(sink__V32->context, SUB(sub__V36, 0)); int sub__V37_count = sub__V36_count*LINK_COUNT(sub__V37); permitUnusedInt(sub__V37_count);
      CRSX_CHECK_SORT(sink__V32->context, sub__V37, &sort_M_Reified_xSort); /* sub__V37 = &#0-0 */
      Term sub__V38 = LINK(sink__V32->context, SUB(sub__V36, 1)); int sub__V38_count = sub__V36_count*LINK_COUNT(sub__V38); permitUnusedInt(sub__V38_count);
      /* sub__V38 = &#0-1 */
      
      NamedPropertyLink namedP__V39 = LINK_NamedPropertyLink(sink__V32->context, NAMED_PROPERTIES(term__V33));
      VariablePropertyLink varP__V40 = LINK_VariablePropertyLink(sink__V32->context, VARIABLE_PROPERTIES(term__V33));
      Hashset namedFV__V41 = LINK_VARIABLESET(sink__V32->context, asConstruction(term__V33)->properties->namedFreeVars);
      Hashset varFV__V42 = LINK_VARIABLESET(sink__V32->context, asConstruction(term__V33)->properties->variableFreeVars);
      UNLINK(sink__V32->context, term__V33);
      ADD_PROPERTIES(sink__V32, LINK_VARIABLESET(sink__V32->context, namedFV__V41), LINK_VARIABLESET(sink__V32->context, varFV__V42), LINK_NamedPropertyLink(sink__V32->context, namedP__V39), LINK_VariablePropertyLink(sink__V32->context, varP__V40));
      { START(sink__V32, _M_X_Declaration_s1);
        COPY(sink__V32, sub__V37);COPY(sink__V32, sub__V38);END(sink__V32, _M_X_Declaration_s1); }
      UNLINK_VARIABLESET(sink__V32->context, namedFV__V41); UNLINK_VARIABLESET(sink__V32->context, varFV__V42);
      UNLINK_NamedPropertyLink(sink__V32->context, namedP__V39); UNLINK_VariablePropertyLink(sink__V32->context, varP__V40);
      
      return 1;
    break; } case Data_M_FUNCTION: { /* Function SYMBOLS-Function$X-Declaration$FUNCTION case FUNCTION */
      ASSERT(sink__V32->context, !strcmp(SYMBOL(term__V33),  "X-Declaration" ));
      Term sub__V43 = SUB(term__V33, 0); permitUnusedTerm(sub__V43); int sub__V43_count = term__V33_count*LINK_COUNT(sub__V43); permitUnusedInt(sub__V43_count);
      CRSX_CHECK_SORT(sink__V32->context, sub__V43, &sort_M_Reified_xDeclaration); ASSERT(sink__V32->context, !strcmp(SYMBOL(sub__V43),  "FUNCTION" ));
      Term sub__V44 = LINK(sink__V32->context, SUB(sub__V43, 0)); int sub__V44_count = sub__V43_count*LINK_COUNT(sub__V44); permitUnusedInt(sub__V44_count);
      /* sub__V44 = &#0-0 */
      Term sub__V45 = LINK(sink__V32->context, SUB(sub__V43, 1)); int sub__V45_count = sub__V43_count*LINK_COUNT(sub__V45); permitUnusedInt(sub__V45_count);
      /* sub__V45 = &#0-1 */
      Term sub__V46 = LINK(sink__V32->context, SUB(sub__V43, 2)); int sub__V46_count = sub__V43_count*LINK_COUNT(sub__V46); permitUnusedInt(sub__V46_count);
      /* sub__V46 = &#0-2 */
      Term sub__V47 = LINK(sink__V32->context, SUB(sub__V43, 3)); int sub__V47_count = sub__V43_count*LINK_COUNT(sub__V47); permitUnusedInt(sub__V47_count);
      /* sub__V47 = &#0-3 */
      Term sub__V48 = LINK(sink__V32->context, SUB(sub__V43, 4)); int sub__V48_count = sub__V43_count*LINK_COUNT(sub__V48); permitUnusedInt(sub__V48_count);
      /* sub__V48 = &#0-4 */
      Term sub__V49 = LINK(sink__V32->context, SUB(sub__V43, 5)); int sub__V49_count = sub__V43_count*LINK_COUNT(sub__V49); permitUnusedInt(sub__V49_count);
      CRSX_CHECK_SORT(sink__V32->context, sub__V49, &sort_M_Reified_xSort); /* sub__V49 = &#0-5 */
      Term sub__V50 = LINK(sink__V32->context, SUB(sub__V43, 6)); int sub__V50_count = sub__V43_count*LINK_COUNT(sub__V50); permitUnusedInt(sub__V50_count);
      /* sub__V50 = &#0-6 */
      
      NamedPropertyLink namedP__V51 = LINK_NamedPropertyLink(sink__V32->context, NAMED_PROPERTIES(term__V33));
      VariablePropertyLink varP__V52 = LINK_VariablePropertyLink(sink__V32->context, VARIABLE_PROPERTIES(term__V33));
      Hashset namedFV__V53 = LINK_VARIABLESET(sink__V32->context, asConstruction(term__V33)->properties->namedFreeVars);
      Hashset varFV__V54 = LINK_VARIABLESET(sink__V32->context, asConstruction(term__V33)->properties->variableFreeVars);
      UNLINK(sink__V32->context, term__V33);
      ADD_PROPERTIES(sink__V32, LINK_VARIABLESET(sink__V32->context, namedFV__V53), LINK_VARIABLESET(sink__V32->context, varFV__V54), LINK_NamedPropertyLink(sink__V32->context, namedP__V51), LINK_VariablePropertyLink(sink__V32->context, varP__V52));
      { START(sink__V32, _M_X_Declaration_s2);
        COPY(sink__V32, sub__V44);COPY(sink__V32, sub__V45);COPY(sink__V32, sub__V46);COPY(sink__V32, sub__V47);COPY(sink__V32, sub__V48);COPY(sink__V32, sub__V49);COPY(sink__V32, sub__V50);END(sink__V32, _M_X_Declaration_s2); }
      UNLINK_VARIABLESET(sink__V32->context, namedFV__V53); UNLINK_VARIABLESET(sink__V32->context, varFV__V54);
      UNLINK_NamedPropertyLink(sink__V32->context, namedP__V51); UNLINK_VariablePropertyLink(sink__V32->context, varP__V52);
      
      return 1;
    break; } case Data_M_POLYMORPHIC: { /* Function SYMBOLS-Polymorphic$X-Declaration$POLYMORPHIC case POLYMORPHIC */
      ASSERT(sink__V32->context, !strcmp(SYMBOL(term__V33),  "X-Declaration" ));
      Term sub__V55 = SUB(term__V33, 0); permitUnusedTerm(sub__V55); int sub__V55_count = term__V33_count*LINK_COUNT(sub__V55); permitUnusedInt(sub__V55_count);
      CRSX_CHECK_SORT(sink__V32->context, sub__V55, &sort_M_Reified_xDeclaration); ASSERT(sink__V32->context, !strcmp(SYMBOL(sub__V55),  "POLYMORPHIC" ));
      Variable y__V56 = BINDER(sub__V55,0,0); if (sub__V55_count <= 1) UNBIND(y__V56);
      Term sub__V57 = LINK(sink__V32->context, SUB(sub__V55, 0)); int sub__V57_count = sub__V55_count*LINK_COUNT(sub__V57); permitUnusedInt(sub__V57_count);
      CRSX_CHECK_SORT(sink__V32->context, sub__V57, &sort_M_Reified_xDeclaration); /* sub__V57 = &#0-0 */
      
      NamedPropertyLink namedP__V58 = LINK_NamedPropertyLink(sink__V32->context, NAMED_PROPERTIES(term__V33));
      VariablePropertyLink varP__V59 = LINK_VariablePropertyLink(sink__V32->context, VARIABLE_PROPERTIES(term__V33));
      Hashset namedFV__V60 = LINK_VARIABLESET(sink__V32->context, asConstruction(term__V33)->properties->namedFreeVars);
      Hashset varFV__V61 = LINK_VARIABLESET(sink__V32->context, asConstruction(term__V33)->properties->variableFreeVars);
      UNLINK(sink__V32->context, term__V33);
      ADD_PROPERTIES(sink__V32, LINK_VARIABLESET(sink__V32->context, namedFV__V60), LINK_VARIABLESET(sink__V32->context, varFV__V61), LINK_NamedPropertyLink(sink__V32->context, namedP__V58), LINK_VariablePropertyLink(sink__V32->context, varP__V59));
      { START(sink__V32, _M_X_Declaration_s3);
        { if (!IS_BOUND(y__V56)) { REBIND(y__V56);
            Variable binds__V62[1] = {y__V56}; BINDS(sink__V32, 1, binds__V62);
            COPY(sink__V32, sub__V57); /* REUSED SUBSTITUTION */  }
          else { Variable b__V63 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V32->context,"b__V63");
            Variable binds__V64[1] = {b__V63}; BINDS(sink__V32, 1, binds__V64);
            {
              Term arg__V65;
              { Sink buf__V66 = ALLOCA_BUFFER(sink__V32->context);
                USE(buf__V66, b__V63); arg__V65 = BUFFER_TERM(buf__V66); FREE_BUFFER(buf__V66); }
              Variable vars__V67[1] = {y__V56};
              Term args__V68[1] = {arg__V65};
              struct _SubstitutionFrame substitution__V69 = {NULL, 0, 1, vars__V67, args__V68, NULL};
              SUBSTITUTE(sink__V32, sub__V57, &substitution__V69); }
                }
           }
        END(sink__V32, _M_X_Declaration_s3); }
      UNLINK_VARIABLESET(sink__V32->context, namedFV__V60); UNLINK_VARIABLESET(sink__V32->context, varFV__V61);
      UNLINK_NamedPropertyLink(sink__V32->context, namedP__V58); UNLINK_VariablePropertyLink(sink__V32->context, varP__V59);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION X-Function. */
int conBindOffs_M_X_Function[] = {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0};
char *nameFun_M_X_Function(Term term) { return  "X-Function" ; }
struct _ConstructionDescriptor descriptor_M_X_Function = {&sort_M_Reified_xVariable, 0, 7, sizeof(STRUCT_Con_M_X_Function), conBindOffs_M_X_Function, &nameFun_M_X_Function, &step_M_X_Function};

int step_M_X_Function(Sink sink__V70, Term term__V71)
{
  int term__V71_count = LINK_COUNT(term__V71); permitUnusedInt(term__V71_count);
  do {
    /* Contraction rule SYMBOLS-X-Function-1. */
    ASSERT(sink__V70->context, !strcmp(SYMBOL(term__V71),  "X-Function" ));
    Term sub__V72 = SUB(term__V71, 0); permitUnusedTerm(sub__V72); int sub__V72_count = term__V71_count*LINK_COUNT(sub__V72); permitUnusedInt(sub__V72_count);
    /* sub__V72 = &#1 */
    Term sub__V73 = SUB(term__V71, 1); permitUnusedTerm(sub__V73); int sub__V73_count = term__V71_count*LINK_COUNT(sub__V73); permitUnusedInt(sub__V73_count);
    /* sub__V73 = &#2 */
    Term sub__V74 = SUB(term__V71, 2); permitUnusedTerm(sub__V74); int sub__V74_count = term__V71_count*LINK_COUNT(sub__V74); permitUnusedInt(sub__V74_count);
    /* sub__V74 = &#3 */
    Term sub__V75 = SUB(term__V71, 3); permitUnusedTerm(sub__V75); int sub__V75_count = term__V71_count*LINK_COUNT(sub__V75); permitUnusedInt(sub__V75_count);
    /* sub__V75 = &#4 */
    Term sub__V76 = LINK(sink__V70->context, SUB(term__V71, 4)); int sub__V76_count = term__V71_count*LINK_COUNT(sub__V76); permitUnusedInt(sub__V76_count);
    UNLINK_SUB(sink__V70->context, term__V71,  4); NORMALIZE(sink__V70->context, sub__V76); SUB(term__V71,  4) = LINK(sink__V70->context, sub__V76);
    /* sub__V76 = &#5 */
    Term sub__V77 = SUB(term__V71, 5); permitUnusedTerm(sub__V77); int sub__V77_count = term__V71_count*LINK_COUNT(sub__V77); permitUnusedInt(sub__V77_count);
    CRSX_CHECK_SORT(sink__V70->context, sub__V77, &sort_M_Reified_xSort); /* sub__V77 = &#6 */
    Term sub__V78 = SUB(term__V71, 6); permitUnusedTerm(sub__V78); int sub__V78_count = term__V71_count*LINK_COUNT(sub__V78); permitUnusedInt(sub__V78_count);
    /* sub__V78 = &#7 */
    
    NamedPropertyLink namedP__V79 = LINK_NamedPropertyLink(sink__V70->context, NAMED_PROPERTIES(term__V71));
    VariablePropertyLink varP__V80 = LINK_VariablePropertyLink(sink__V70->context, VARIABLE_PROPERTIES(term__V71));
    Hashset namedFV__V81 = LINK_VARIABLESET(sink__V70->context, asConstruction(term__V71)->properties->namedFreeVars);
    Hashset varFV__V82 = LINK_VARIABLESET(sink__V70->context, asConstruction(term__V71)->properties->variableFreeVars);
    UNLINK(sink__V70->context, term__V71);
    { START(sink__V70, _M__sTextCons);
      { START(sink__V70, _M__sTextEmbed);
        { START(sink__V70, _M_AsText);
          { START(sink__V70, _M_MapText_s1);
            COPY(sink__V70, sub__V76);{ Variable x__V83 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V70->context,"x__V83");
              Variable binds__V84[1] = {x__V83}; BINDS(sink__V70, 1, binds__V84);
              { START(sink__V70, _M_X_Form);
                USE(sink__V70, x__V83); END(sink__V70, _M_X_Form); }
               }
            END(sink__V70, _M_MapText_s1); }
          END(sink__V70, _M_AsText); }
        END(sink__V70, _M__sTextEmbed); }
      { START(sink__V70, _M__sTextNil); END(sink__V70, _M__sTextNil); }
      END(sink__V70, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V70->context, namedFV__V81); UNLINK_VARIABLESET(sink__V70->context, varFV__V82);
    UNLINK_NamedPropertyLink(sink__V70->context, namedP__V79); UNLINK_VariablePropertyLink(sink__V70->context, varP__V80);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Declarations. */
int conBindOffs_M_X_Declarations[] = {0 , 0};
char *nameFun_M_X_Declarations(Term term) { return  "X-Declarations" ; }
struct _ConstructionDescriptor descriptor_M_X_Declarations = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_X_Declarations), conBindOffs_M_X_Declarations, &nameFun_M_X_Declarations, &step_M_X_Declarations};

int step_M_X_Declarations(Sink sink__V85, Term term__V86)
{
  int term__V86_count = LINK_COUNT(term__V86); permitUnusedInt(term__V86_count);
  Term sub__V87 = FORCE(sink__V85->context, SUB(term__V86, 0));
  EnumOf_M__sList choice__V88 = (IS_VARIABLE_USE(sub__V87) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V87));
  switch (choice__V88)
  {
    case Data_M__sCons: { /* Function SYMBOLS-X-Declarations-1$X-Declarations$$Cons case $Cons */
      ASSERT(sink__V85->context, !strcmp(SYMBOL(term__V86),  "X-Declarations" ));
      Term sub__V89 = SUB(term__V86, 0); permitUnusedTerm(sub__V89); int sub__V89_count = term__V86_count*LINK_COUNT(sub__V89); permitUnusedInt(sub__V89_count);
      ASSERT(sink__V85->context, !strcmp(SYMBOL(sub__V89),  "$Cons" ));
      Term sub__V90 = LINK(sink__V85->context, SUB(sub__V89, 0)); int sub__V90_count = sub__V89_count*LINK_COUNT(sub__V90); permitUnusedInt(sub__V90_count);
      /* sub__V90 = &#0-0 */
      Term sub__V91 = LINK(sink__V85->context, SUB(sub__V89, 1)); int sub__V91_count = sub__V89_count*LINK_COUNT(sub__V91); permitUnusedInt(sub__V91_count);
      /* sub__V91 = &#0-1 */
      
      NamedPropertyLink namedP__V92 = LINK_NamedPropertyLink(sink__V85->context, NAMED_PROPERTIES(term__V86));
      VariablePropertyLink varP__V93 = LINK_VariablePropertyLink(sink__V85->context, VARIABLE_PROPERTIES(term__V86));
      Hashset namedFV__V94 = LINK_VARIABLESET(sink__V85->context, asConstruction(term__V86)->properties->namedFreeVars);
      Hashset varFV__V95 = LINK_VARIABLESET(sink__V85->context, asConstruction(term__V86)->properties->variableFreeVars);
      UNLINK(sink__V85->context, term__V86);
      ADD_PROPERTIES(sink__V85, LINK_VARIABLESET(sink__V85->context, namedFV__V94), LINK_VARIABLESET(sink__V85->context, varFV__V95), LINK_NamedPropertyLink(sink__V85->context, namedP__V92), LINK_VariablePropertyLink(sink__V85->context, varP__V93));
      { START(sink__V85, _M_X_Declarations_s1);
        COPY(sink__V85, sub__V90);COPY(sink__V85, sub__V91);END(sink__V85, _M_X_Declarations_s1); }
      UNLINK_VARIABLESET(sink__V85->context, namedFV__V94); UNLINK_VARIABLESET(sink__V85->context, varFV__V95);
      UNLINK_NamedPropertyLink(sink__V85->context, namedP__V92); UNLINK_VariablePropertyLink(sink__V85->context, varP__V93);
      
      return 1;
    break; } case Data_M__sNil: { /* Function SYMBOLS-X-Declarations-2$X-Declarations$$Nil case $Nil */
      ASSERT(sink__V85->context, !strcmp(SYMBOL(term__V86),  "X-Declarations" ));
      Term sub__V96 = SUB(term__V86, 0); permitUnusedTerm(sub__V96); int sub__V96_count = term__V86_count*LINK_COUNT(sub__V96); permitUnusedInt(sub__V96_count);
      ASSERT(sink__V85->context, !strcmp(SYMBOL(sub__V96),  "$Nil" ));
      
      NamedPropertyLink namedP__V97 = LINK_NamedPropertyLink(sink__V85->context, NAMED_PROPERTIES(term__V86));
      VariablePropertyLink varP__V98 = LINK_VariablePropertyLink(sink__V85->context, VARIABLE_PROPERTIES(term__V86));
      Hashset namedFV__V99 = LINK_VARIABLESET(sink__V85->context, asConstruction(term__V86)->properties->namedFreeVars);
      Hashset varFV__V100 = LINK_VARIABLESET(sink__V85->context, asConstruction(term__V86)->properties->variableFreeVars);
      UNLINK(sink__V85->context, term__V86);
      ADD_PROPERTIES(sink__V85, LINK_VARIABLESET(sink__V85->context, namedFV__V99), LINK_VARIABLESET(sink__V85->context, varFV__V100), LINK_NamedPropertyLink(sink__V85->context, namedP__V97), LINK_VariablePropertyLink(sink__V85->context, varP__V98));
      { START(sink__V85, _M_X_Declarations_s2);
        END(sink__V85, _M_X_Declarations_s2); }
      UNLINK_VARIABLESET(sink__V85->context, namedFV__V99); UNLINK_VARIABLESET(sink__V85->context, varFV__V100);
      UNLINK_NamedPropertyLink(sink__V85->context, namedP__V97); UNLINK_VariablePropertyLink(sink__V85->context, varP__V98);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION ComputeSymbols. */
int conBindOffs_M_ComputeSymbols[] = {0 , 0};
char *nameFun_M_ComputeSymbols(Term term) { return  "ComputeSymbols" ; }
struct _ConstructionDescriptor descriptor_M_ComputeSymbols = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_ComputeSymbols), conBindOffs_M_ComputeSymbols, &nameFun_M_ComputeSymbols, &step_M_ComputeSymbols};

int step_M_ComputeSymbols(Sink sink__V101, Term term__V102)
{
  int term__V102_count = LINK_COUNT(term__V102); permitUnusedInt(term__V102_count);
  Term sub__V103 = FORCE(sink__V101->context, SUB(term__V102, 0));
  EnumOf_M_Reify_xCRSX choice__V104 = (IS_VARIABLE_USE(sub__V103) ? VarOf_M_Reify_xCRSX : (EnumOf_M_Reify_xCRSX) TAG(sub__V103));
  switch (choice__V104)
  {
    case Data_M_CRSX: { /* Function SYMBOLS-ComputeSymbols-1$ComputeSymbols$CRSX case CRSX */
      ASSERT(sink__V101->context, !strcmp(SYMBOL(term__V102),  "ComputeSymbols" ));
      Term sub__V105 = SUB(term__V102, 0); permitUnusedTerm(sub__V105); int sub__V105_count = term__V102_count*LINK_COUNT(sub__V105); permitUnusedInt(sub__V105_count);
      CRSX_CHECK_SORT(sink__V101->context, sub__V105, &sort_M_Reify_xCRSX); ASSERT(sink__V101->context, !strcmp(SYMBOL(sub__V105),  "CRSX" ));
      Term sub__V106 = LINK(sink__V101->context, SUB(sub__V105, 0)); int sub__V106_count = sub__V105_count*LINK_COUNT(sub__V106); permitUnusedInt(sub__V106_count);
      /* sub__V106 = &#0-0 */
      Term sub__V107 = LINK(sink__V101->context, SUB(sub__V105, 1)); int sub__V107_count = sub__V105_count*LINK_COUNT(sub__V107); permitUnusedInt(sub__V107_count);
      /* sub__V107 = &#0-1 */
      
      NamedPropertyLink namedP__V108 = LINK_NamedPropertyLink(sink__V101->context, NAMED_PROPERTIES(term__V102));
      VariablePropertyLink varP__V109 = LINK_VariablePropertyLink(sink__V101->context, VARIABLE_PROPERTIES(term__V102));
      Hashset namedFV__V110 = LINK_VARIABLESET(sink__V101->context, asConstruction(term__V102)->properties->namedFreeVars);
      Hashset varFV__V111 = LINK_VARIABLESET(sink__V101->context, asConstruction(term__V102)->properties->variableFreeVars);
      UNLINK(sink__V101->context, term__V102);
      ADD_PROPERTIES(sink__V101, LINK_VARIABLESET(sink__V101->context, namedFV__V110), LINK_VARIABLESET(sink__V101->context, varFV__V111), LINK_NamedPropertyLink(sink__V101->context, namedP__V108), LINK_VariablePropertyLink(sink__V101->context, varP__V109));
      { START(sink__V101, _M_ComputeSymbols_s1);
        COPY(sink__V101, sub__V106);COPY(sink__V101, sub__V107);END(sink__V101, _M_ComputeSymbols_s1); }
      UNLINK_VARIABLESET(sink__V101->context, namedFV__V110); UNLINK_VARIABLESET(sink__V101->context, varFV__V111);
      UNLINK_NamedPropertyLink(sink__V101->context, namedP__V108); UNLINK_VariablePropertyLink(sink__V101->context, varP__V109);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION X-Form. */
int conBindOffs_M_X_Form[] = {0 , 0};
char *nameFun_M_X_Form(Term term) { return  "X-Form" ; }
struct _ConstructionDescriptor descriptor_M_X_Form = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_X_Form), conBindOffs_M_X_Form, &nameFun_M_X_Form, &step_M_X_Form};

int step_M_X_Form(Sink sink__V112, Term term__V113)
{
  int term__V113_count = LINK_COUNT(term__V113); permitUnusedInt(term__V113_count);
  Term sub__V114 = FORCE(sink__V112->context, SUB(term__V113, 0));
  EnumOf_M_Reified_xForm choice__V115 = (IS_VARIABLE_USE(sub__V114) ? VarOf_M_Reified_xForm : (EnumOf_M_Reified_xForm) TAG(sub__V114));
  switch (choice__V115)
  {
    case Data_M_SORT_SET: { /* Function SYMBOLS-X-Form-1$X-Form$SORT-SET case SORT-SET */
      ASSERT(sink__V112->context, !strcmp(SYMBOL(term__V113),  "X-Form" ));
      Term sub__V116 = SUB(term__V113, 0); permitUnusedTerm(sub__V116); int sub__V116_count = term__V113_count*LINK_COUNT(sub__V116); permitUnusedInt(sub__V116_count);
      CRSX_CHECK_SORT(sink__V112->context, sub__V116, &sort_M_Reified_xForm); ASSERT(sink__V112->context, !strcmp(SYMBOL(sub__V116),  "SORT-SET" ));
      Term sub__V117 = LINK(sink__V112->context, SUB(sub__V116, 0)); int sub__V117_count = sub__V116_count*LINK_COUNT(sub__V117); permitUnusedInt(sub__V117_count);
      CRSX_CHECK_SORT(sink__V112->context, sub__V117, &sort_M_Reified_xSort); /* sub__V117 = &#0-0 */
      Term sub__V118 = LINK(sink__V112->context, SUB(sub__V116, 1)); int sub__V118_count = sub__V116_count*LINK_COUNT(sub__V118); permitUnusedInt(sub__V118_count);
      CRSX_CHECK_SORT(sink__V112->context, sub__V118, &sort_M_Reified_xSort); /* sub__V118 = &#0-1 */
      Term sub__V119 = LINK(sink__V112->context, SUB(sub__V116, 2)); int sub__V119_count = sub__V116_count*LINK_COUNT(sub__V119); permitUnusedInt(sub__V119_count);
      CRSX_CHECK_SORT(sink__V112->context, sub__V119, &sort_M_Reified_xForm); /* sub__V119 = &#0-2 */
      
      NamedPropertyLink namedP__V120 = LINK_NamedPropertyLink(sink__V112->context, NAMED_PROPERTIES(term__V113));
      VariablePropertyLink varP__V121 = LINK_VariablePropertyLink(sink__V112->context, VARIABLE_PROPERTIES(term__V113));
      Hashset namedFV__V122 = LINK_VARIABLESET(sink__V112->context, asConstruction(term__V113)->properties->namedFreeVars);
      Hashset varFV__V123 = LINK_VARIABLESET(sink__V112->context, asConstruction(term__V113)->properties->variableFreeVars);
      UNLINK(sink__V112->context, term__V113);
      ADD_PROPERTIES(sink__V112, LINK_VARIABLESET(sink__V112->context, namedFV__V122), LINK_VARIABLESET(sink__V112->context, varFV__V123), LINK_NamedPropertyLink(sink__V112->context, namedP__V120), LINK_VariablePropertyLink(sink__V112->context, varP__V121));
      { START(sink__V112, _M_X_Form_s6);
        COPY(sink__V112, sub__V117);COPY(sink__V112, sub__V118);COPY(sink__V112, sub__V119);END(sink__V112, _M_X_Form_s6); }
      UNLINK_VARIABLESET(sink__V112->context, namedFV__V122); UNLINK_VARIABLESET(sink__V112->context, varFV__V123);
      UNLINK_NamedPropertyLink(sink__V112->context, namedP__V120); UNLINK_VariablePropertyLink(sink__V112->context, varP__V121);
      
      return 1;
    break; } case Data_M_SORT_ALLOWS_VARIABLES: { /* Function SYMBOLS-X-Form-2$X-Form$SORT-ALLOWS-VARIABLES case SORT-ALLOWS-VARIABLES */
      ASSERT(sink__V112->context, !strcmp(SYMBOL(term__V113),  "X-Form" ));
      Term sub__V124 = SUB(term__V113, 0); permitUnusedTerm(sub__V124); int sub__V124_count = term__V113_count*LINK_COUNT(sub__V124); permitUnusedInt(sub__V124_count);
      CRSX_CHECK_SORT(sink__V112->context, sub__V124, &sort_M_Reified_xForm); ASSERT(sink__V112->context, !strcmp(SYMBOL(sub__V124),  "SORT-ALLOWS-VARIABLES" ));
      
      NamedPropertyLink namedP__V125 = LINK_NamedPropertyLink(sink__V112->context, NAMED_PROPERTIES(term__V113));
      VariablePropertyLink varP__V126 = LINK_VariablePropertyLink(sink__V112->context, VARIABLE_PROPERTIES(term__V113));
      Hashset namedFV__V127 = LINK_VARIABLESET(sink__V112->context, asConstruction(term__V113)->properties->namedFreeVars);
      Hashset varFV__V128 = LINK_VARIABLESET(sink__V112->context, asConstruction(term__V113)->properties->variableFreeVars);
      UNLINK(sink__V112->context, term__V113);
      ADD_PROPERTIES(sink__V112, LINK_VARIABLESET(sink__V112->context, namedFV__V127), LINK_VARIABLESET(sink__V112->context, varFV__V128), LINK_NamedPropertyLink(sink__V112->context, namedP__V125), LINK_VariablePropertyLink(sink__V112->context, varP__V126));
      { START(sink__V112, _M_X_Form_s5);
        END(sink__V112, _M_X_Form_s5); }
      UNLINK_VARIABLESET(sink__V112->context, namedFV__V127); UNLINK_VARIABLESET(sink__V112->context, varFV__V128);
      UNLINK_NamedPropertyLink(sink__V112->context, namedP__V125); UNLINK_VariablePropertyLink(sink__V112->context, varP__V126);
      
      return 1;
    break; } case Data_M_FORM: { /* Function SYMBOLS-X-Form-3$X-Form$FORM case FORM */
      ASSERT(sink__V112->context, !strcmp(SYMBOL(term__V113),  "X-Form" ));
      Term sub__V129 = SUB(term__V113, 0); permitUnusedTerm(sub__V129); int sub__V129_count = term__V113_count*LINK_COUNT(sub__V129); permitUnusedInt(sub__V129_count);
      CRSX_CHECK_SORT(sink__V112->context, sub__V129, &sort_M_Reified_xForm); ASSERT(sink__V112->context, !strcmp(SYMBOL(sub__V129),  "FORM" ));
      Term sub__V130 = LINK(sink__V112->context, SUB(sub__V129, 0)); int sub__V130_count = sub__V129_count*LINK_COUNT(sub__V130); permitUnusedInt(sub__V130_count);
      /* sub__V130 = &#0-0 */
      Term sub__V131 = LINK(sink__V112->context, SUB(sub__V129, 1)); int sub__V131_count = sub__V129_count*LINK_COUNT(sub__V131); permitUnusedInt(sub__V131_count);
      /* sub__V131 = &#0-1 */
      
      NamedPropertyLink namedP__V132 = LINK_NamedPropertyLink(sink__V112->context, NAMED_PROPERTIES(term__V113));
      VariablePropertyLink varP__V133 = LINK_VariablePropertyLink(sink__V112->context, VARIABLE_PROPERTIES(term__V113));
      Hashset namedFV__V134 = LINK_VARIABLESET(sink__V112->context, asConstruction(term__V113)->properties->namedFreeVars);
      Hashset varFV__V135 = LINK_VARIABLESET(sink__V112->context, asConstruction(term__V113)->properties->variableFreeVars);
      UNLINK(sink__V112->context, term__V113);
      ADD_PROPERTIES(sink__V112, LINK_VARIABLESET(sink__V112->context, namedFV__V134), LINK_VARIABLESET(sink__V112->context, varFV__V135), LINK_NamedPropertyLink(sink__V112->context, namedP__V132), LINK_VariablePropertyLink(sink__V112->context, varP__V133));
      { START(sink__V112, _M_X_Form_s2);
        COPY(sink__V112, sub__V131);COPY(sink__V112, sub__V130);END(sink__V112, _M_X_Form_s2); }
      UNLINK_VARIABLESET(sink__V112->context, namedFV__V134); UNLINK_VARIABLESET(sink__V112->context, varFV__V135);
      UNLINK_NamedPropertyLink(sink__V112->context, namedP__V132); UNLINK_VariablePropertyLink(sink__V112->context, varP__V133);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION X-Data$2. */
int conBindOffs_M_X_Data_s2[] = {0 , 0 , 0 , 0 , 0};
char *nameFun_M_X_Data_s2(Term term) { return  "X-Data$2" ; }
struct _ConstructionDescriptor descriptor_M_X_Data_s2 = {&sort_M_Reified_xVariable, 0, 4, sizeof(STRUCT_Con_M_X_Data_s2), conBindOffs_M_X_Data_s2, &nameFun_M_X_Data_s2, &step_M_X_Data_s2};

int step_M_X_Data_s2(Sink sink__V136, Term term__V137)
{
  int term__V137_count = LINK_COUNT(term__V137); permitUnusedInt(term__V137_count);
  do {
    /* Contraction rule SYMBOLS-X-Data-2. */
    ASSERT(sink__V136->context, !strcmp(SYMBOL(term__V137),  "X-Data$2" ));
    Term sub__V138 = SUB(term__V137, 0); permitUnusedTerm(sub__V138); int sub__V138_count = term__V137_count*LINK_COUNT(sub__V138); permitUnusedInt(sub__V138_count);
    CRSX_CHECK_SORT(sink__V136->context, sub__V138, &sort_M_Reified_xSort); /* sub__V138 = &#11 */
    Term sub__V139 = SUB(term__V137, 1); permitUnusedTerm(sub__V139); int sub__V139_count = term__V137_count*LINK_COUNT(sub__V139); permitUnusedInt(sub__V139_count);
    CRSX_CHECK_SORT(sink__V136->context, sub__V139, &sort_M_Reified_xSort); /* sub__V139 = &#12 */
    Term sub__V140 = LINK(sink__V136->context, SUB(term__V137, 2)); int sub__V140_count = term__V137_count*LINK_COUNT(sub__V140); permitUnusedInt(sub__V140_count);
    CRSX_CHECK_SORT(sink__V136->context, sub__V140, &sort_M_Reified_xSort); /* sub__V140 = &#13 */
    Term sub__V141 = LINK(sink__V136->context, SUB(term__V137, 3)); int sub__V141_count = term__V137_count*LINK_COUNT(sub__V141); permitUnusedInt(sub__V141_count);
    /* sub__V141 = &#2 */
    
    NamedPropertyLink namedP__V142 = LINK_NamedPropertyLink(sink__V136->context, NAMED_PROPERTIES(term__V137));
    VariablePropertyLink varP__V143 = LINK_VariablePropertyLink(sink__V136->context, VARIABLE_PROPERTIES(term__V137));
    Hashset namedFV__V144 = LINK_VARIABLESET(sink__V136->context, asConstruction(term__V137)->properties->namedFreeVars);
    Hashset varFV__V145 = LINK_VARIABLESET(sink__V136->context, asConstruction(term__V137)->properties->variableFreeVars);
    UNLINK(sink__V136->context, term__V137);
    { START(sink__V136, _M_X_Data);
      COPY(sink__V136, sub__V140);COPY(sink__V136, sub__V141);END(sink__V136, _M_X_Data); }
    UNLINK_VARIABLESET(sink__V136->context, namedFV__V144); UNLINK_VARIABLESET(sink__V136->context, varFV__V145);
    UNLINK_NamedPropertyLink(sink__V136->context, namedP__V142); UNLINK_VariablePropertyLink(sink__V136->context, varP__V143);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Data$1. */
int conBindOffs_M_X_Data_s1[] = {0 , 0 , 0 , 0};
char *nameFun_M_X_Data_s1(Term term) { return  "X-Data$1" ; }
struct _ConstructionDescriptor descriptor_M_X_Data_s1 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_X_Data_s1), conBindOffs_M_X_Data_s1, &nameFun_M_X_Data_s1, &step_M_X_Data_s1};

int step_M_X_Data_s1(Sink sink__V146, Term term__V147)
{
  int term__V147_count = LINK_COUNT(term__V147); permitUnusedInt(term__V147_count);
  do {
    /* Contraction rule SYMBOLS-X-Data-1. */
    ASSERT(sink__V146->context, !strcmp(SYMBOL(term__V147),  "X-Data$1" ));
    Term sub__V148 = SUB(term__V147, 0); permitUnusedTerm(sub__V148); int sub__V148_count = term__V147_count*LINK_COUNT(sub__V148); permitUnusedInt(sub__V148_count);
    /* sub__V148 = &#11 */
    Term sub__V149 = SUB(term__V147, 1); permitUnusedTerm(sub__V149); int sub__V149_count = term__V147_count*LINK_COUNT(sub__V149); permitUnusedInt(sub__V149_count);
    /* sub__V149 = &#12 */
    Term sub__V150 = LINK(sink__V146->context, SUB(term__V147, 2)); int sub__V150_count = term__V147_count*LINK_COUNT(sub__V150); permitUnusedInt(sub__V150_count);
    /* sub__V150 = &#2 */
    
    NamedPropertyLink namedP__V151 = LINK_NamedPropertyLink(sink__V146->context, NAMED_PROPERTIES(term__V147));
    VariablePropertyLink varP__V152 = LINK_VariablePropertyLink(sink__V146->context, VARIABLE_PROPERTIES(term__V147));
    Hashset namedFV__V153 = LINK_VARIABLESET(sink__V146->context, asConstruction(term__V147)->properties->namedFreeVars);
    Hashset varFV__V154 = LINK_VARIABLESET(sink__V146->context, asConstruction(term__V147)->properties->variableFreeVars);
    UNLINK(sink__V146->context, term__V147);
    { START(sink__V146, _M__sTextCons);
      { START(sink__V146, _M__sTextEmbed);
        { START(sink__V146, _M_AsText);
          { START(sink__V146, _M_MapText_s1);
            COPY(sink__V146, sub__V150);{ Variable x__V155 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V146->context,"x__V155");
              Variable binds__V156[1] = {x__V155}; BINDS(sink__V146, 1, binds__V156);
              { START(sink__V146, _M_X_Form);
                USE(sink__V146, x__V155); END(sink__V146, _M_X_Form); }
               }
            END(sink__V146, _M_MapText_s1); }
          END(sink__V146, _M_AsText); }
        END(sink__V146, _M__sTextEmbed); }
      { START(sink__V146, _M__sTextNil);
        END(sink__V146, _M__sTextNil); }
      END(sink__V146, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V146->context, namedFV__V153); UNLINK_VARIABLESET(sink__V146->context, varFV__V154);
    UNLINK_NamedPropertyLink(sink__V146->context, namedP__V151); UNLINK_VariablePropertyLink(sink__V146->context, varP__V152);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Form$5. */
int conBindOffs_M_X_Form_s5[] = {0};
char *nameFun_M_X_Form_s5(Term term) { return  "X-Form$5" ; }
struct _ConstructionDescriptor descriptor_M_X_Form_s5 = {&sort_M_Reified_xVariable, 0, 0, sizeof(STRUCT_Con_M_X_Form_s5), conBindOffs_M_X_Form_s5, &nameFun_M_X_Form_s5, &step_M_X_Form_s5};

int step_M_X_Form_s5(Sink sink__V157, Term term__V158)
{
  int term__V158_count = LINK_COUNT(term__V158); permitUnusedInt(term__V158_count);
  do {
    /* Contraction rule SYMBOLS-X-Form-2. */
    ASSERT(sink__V157->context, !strcmp(SYMBOL(term__V158),  "X-Form$5" ));
    
    NamedPropertyLink namedP__V159 = LINK_NamedPropertyLink(sink__V157->context, NAMED_PROPERTIES(term__V158));
    VariablePropertyLink varP__V160 = LINK_VariablePropertyLink(sink__V157->context, VARIABLE_PROPERTIES(term__V158));
    Hashset namedFV__V161 = LINK_VARIABLESET(sink__V157->context, asConstruction(term__V158)->properties->namedFreeVars);
    Hashset varFV__V162 = LINK_VARIABLESET(sink__V157->context, asConstruction(term__V158)->properties->variableFreeVars);
    UNLINK(sink__V157->context, term__V158);
    { START(sink__V157, _M__sTextNil); END(sink__V157, _M__sTextNil); }
    UNLINK_VARIABLESET(sink__V157->context, namedFV__V161); UNLINK_VARIABLESET(sink__V157->context, varFV__V162);
    UNLINK_NamedPropertyLink(sink__V157->context, namedP__V159); UNLINK_VariablePropertyLink(sink__V157->context, varP__V160);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Form$6. */
int conBindOffs_M_X_Form_s6[] = {0 , 0 , 0 , 0};
char *nameFun_M_X_Form_s6(Term term) { return  "X-Form$6" ; }
struct _ConstructionDescriptor descriptor_M_X_Form_s6 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_X_Form_s6), conBindOffs_M_X_Form_s6, &nameFun_M_X_Form_s6, &step_M_X_Form_s6};

int step_M_X_Form_s6(Sink sink__V163, Term term__V164)
{
  int term__V164_count = LINK_COUNT(term__V164); permitUnusedInt(term__V164_count);
  do {
    /* Contraction rule SYMBOLS-X-Form-1. */
    ASSERT(sink__V163->context, !strcmp(SYMBOL(term__V164),  "X-Form$6" ));
    Term sub__V165 = SUB(term__V164, 0); permitUnusedTerm(sub__V165); int sub__V165_count = term__V164_count*LINK_COUNT(sub__V165); permitUnusedInt(sub__V165_count);
    CRSX_CHECK_SORT(sink__V163->context, sub__V165, &sort_M_Reified_xSort); /* sub__V165 = &#11 */
    Term sub__V166 = SUB(term__V164, 1); permitUnusedTerm(sub__V166); int sub__V166_count = term__V164_count*LINK_COUNT(sub__V166); permitUnusedInt(sub__V166_count);
    CRSX_CHECK_SORT(sink__V163->context, sub__V166, &sort_M_Reified_xSort); /* sub__V166 = &#12 */
    Term sub__V167 = LINK(sink__V163->context, SUB(term__V164, 2)); int sub__V167_count = term__V164_count*LINK_COUNT(sub__V167); permitUnusedInt(sub__V167_count);
    CRSX_CHECK_SORT(sink__V163->context, sub__V167, &sort_M_Reified_xForm); /* sub__V167 = &#13 */
    
    NamedPropertyLink namedP__V168 = LINK_NamedPropertyLink(sink__V163->context, NAMED_PROPERTIES(term__V164));
    VariablePropertyLink varP__V169 = LINK_VariablePropertyLink(sink__V163->context, VARIABLE_PROPERTIES(term__V164));
    Hashset namedFV__V170 = LINK_VARIABLESET(sink__V163->context, asConstruction(term__V164)->properties->namedFreeVars);
    Hashset varFV__V171 = LINK_VARIABLESET(sink__V163->context, asConstruction(term__V164)->properties->variableFreeVars);
    UNLINK(sink__V163->context, term__V164);
    { START(sink__V163, _M_X_Form);
      COPY(sink__V163, sub__V167);END(sink__V163, _M_X_Form); }
    UNLINK_VARIABLESET(sink__V163->context, namedFV__V170); UNLINK_VARIABLESET(sink__V163->context, varFV__V171);
    UNLINK_NamedPropertyLink(sink__V163->context, namedP__V168); UNLINK_VariablePropertyLink(sink__V163->context, varP__V169);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Form$3. */
int conBindOffs_M_X_Form_s3[] = {0 , 0 , 0 , 0};
char *nameFun_M_X_Form_s3(Term term) { return  "X-Form$3" ; }
struct _ConstructionDescriptor descriptor_M_X_Form_s3 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_X_Form_s3), conBindOffs_M_X_Form_s3, &nameFun_M_X_Form_s3, &step_M_X_Form_s3};

int step_M_X_Form_s3(Sink sink__V172, Term term__V173)
{
  int term__V173_count = LINK_COUNT(term__V173); permitUnusedInt(term__V173_count);
  do {
    /* Contraction rule SYMBOLS-X-Form-4. */
    ASSERT(sink__V172->context, !strcmp(SYMBOL(term__V173),  "X-Form$3" ));
    Term sub__V174 = SUB(term__V173, 0); permitUnusedTerm(sub__V174); int sub__V174_count = term__V173_count*LINK_COUNT(sub__V174); permitUnusedInt(sub__V174_count);
    /* sub__V174 = &#121 */
    Term sub__V175 = SUB(term__V173, 1); permitUnusedTerm(sub__V175); int sub__V175_count = term__V173_count*LINK_COUNT(sub__V175); permitUnusedInt(sub__V175_count);
    /* sub__V175 = &#122 */
    Term sub__V176 = LINK(sink__V172->context, SUB(term__V173, 2)); int sub__V176_count = term__V173_count*LINK_COUNT(sub__V176); permitUnusedInt(sub__V176_count);
    UNLINK_SUB(sink__V172->context, term__V173,  2); NORMALIZE(sink__V172->context, sub__V176); SUB(term__V173,  2) = LINK(sink__V172->context, sub__V176);
    /* sub__V176 = &#11 */
    
    NamedPropertyLink namedP__V177 = LINK_NamedPropertyLink(sink__V172->context, NAMED_PROPERTIES(term__V173));
    VariablePropertyLink varP__V178 = LINK_VariablePropertyLink(sink__V172->context, VARIABLE_PROPERTIES(term__V173));
    Hashset namedFV__V179 = LINK_VARIABLESET(sink__V172->context, asConstruction(term__V173)->properties->namedFreeVars);
    Hashset varFV__V180 = LINK_VARIABLESET(sink__V172->context, asConstruction(term__V173)->properties->variableFreeVars);
    UNLINK(sink__V172->context, term__V173);
    { START(sink__V172, _M__sTextCons);
      { START(sink__V172, _M__sTextBreak);
        LITERAL(sink__V172,  "\n" ); END(sink__V172, _M__sTextBreak); }
      { START(sink__V172, _M__sTextCons);
        { START(sink__V172, _M__sTextChars);
          LITERAL(sink__V172,  "{" ); END(sink__V172, _M__sTextChars); }
        { START(sink__V172, _M__sTextCons);
          { START(sink__V172, _M__sTextEmbed);
            { START(sink__V172, _M_AsText);
              { START(sink__V172, _M_STRING);
                COPY(sink__V172, LINK(sink__V172->context, sub__V176));END(sink__V172, _M_STRING); }
              END(sink__V172, _M_AsText); }
            END(sink__V172, _M__sTextEmbed); }
          { START(sink__V172, _M__sTextCons);
            { START(sink__V172, _M__sTextChars);
              LITERAL(sink__V172,  ", &" ); END(sink__V172, _M__sTextChars); }
            { START(sink__V172, _M__sTextCons);
              { START(sink__V172, _M__sTextEmbed);
                { START(sink__V172, _M_AsText);
                  { START(sink__V172, _M_Descriptor);
                    COPY(sink__V172, sub__V176);END(sink__V172, _M_Descriptor); }
                  END(sink__V172, _M_AsText); }
                END(sink__V172, _M__sTextEmbed); }
              { START(sink__V172, _M__sTextCons);
                { START(sink__V172, _M__sTextChars);
                  LITERAL(sink__V172,  "}," ); END(sink__V172, _M__sTextChars); }
                { START(sink__V172, _M__sTextNil);
                  END(sink__V172, _M__sTextNil); }
                END(sink__V172, _M__sTextCons); }
              END(sink__V172, _M__sTextCons); }
            END(sink__V172, _M__sTextCons); }
          END(sink__V172, _M__sTextCons); }
        END(sink__V172, _M__sTextCons); }
      END(sink__V172, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V172->context, namedFV__V179); UNLINK_VARIABLESET(sink__V172->context, varFV__V180);
    UNLINK_NamedPropertyLink(sink__V172->context, namedP__V177); UNLINK_VariablePropertyLink(sink__V172->context, varP__V178);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Form$4. */
int conBindOffs_M_X_Form_s4[] = {0 , 0};
char *nameFun_M_X_Form_s4(Term term) { return  "X-Form$4" ; }
struct _ConstructionDescriptor descriptor_M_X_Form_s4 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_X_Form_s4), conBindOffs_M_X_Form_s4, &nameFun_M_X_Form_s4, &step_M_X_Form_s4};

int step_M_X_Form_s4(Sink sink__V181, Term term__V182)
{
  int term__V182_count = LINK_COUNT(term__V182); permitUnusedInt(term__V182_count);
  do {
    /* Contraction rule SYMBOLS-X-Form-3. */
    ASSERT(sink__V181->context, !strcmp(SYMBOL(term__V182),  "X-Form$4" ));
    Term sub__V183 = LINK(sink__V181->context, SUB(term__V182, 0)); int sub__V183_count = term__V182_count*LINK_COUNT(sub__V183); permitUnusedInt(sub__V183_count);
    UNLINK_SUB(sink__V181->context, term__V182,  0); NORMALIZE(sink__V181->context, sub__V183); SUB(term__V182,  0) = LINK(sink__V181->context, sub__V183);
    /* sub__V183 = &#11 */
    
    NamedPropertyLink namedP__V184 = LINK_NamedPropertyLink(sink__V181->context, NAMED_PROPERTIES(term__V182));
    VariablePropertyLink varP__V185 = LINK_VariablePropertyLink(sink__V181->context, VARIABLE_PROPERTIES(term__V182));
    Hashset namedFV__V186 = LINK_VARIABLESET(sink__V181->context, asConstruction(term__V182)->properties->namedFreeVars);
    Hashset varFV__V187 = LINK_VARIABLESET(sink__V181->context, asConstruction(term__V182)->properties->variableFreeVars);
    UNLINK(sink__V181->context, term__V182);
    { START(sink__V181, _M__sTextCons);
      { START(sink__V181, _M__sTextBreak);
        LITERAL(sink__V181,  "\n" ); END(sink__V181, _M__sTextBreak); }
      { START(sink__V181, _M__sTextCons);
        { START(sink__V181, _M__sTextChars);
          LITERAL(sink__V181,  "{" ); END(sink__V181, _M__sTextChars); }
        { START(sink__V181, _M__sTextCons);
          { START(sink__V181, _M__sTextEmbed);
            { START(sink__V181, _M_AsText);
              { START(sink__V181, _M_STRING);
                COPY(sink__V181, LINK(sink__V181->context, sub__V183));END(sink__V181, _M_STRING); }
              END(sink__V181, _M_AsText); }
            END(sink__V181, _M__sTextEmbed); }
          { START(sink__V181, _M__sTextCons);
            { START(sink__V181, _M__sTextChars);
              LITERAL(sink__V181,  ", &" ); END(sink__V181, _M__sTextChars); }
            { START(sink__V181, _M__sTextCons);
              { START(sink__V181, _M__sTextEmbed);
                { START(sink__V181, _M_AsText);
                  { START(sink__V181, _M_Descriptor);
                    COPY(sink__V181, sub__V183);END(sink__V181, _M_Descriptor); }
                  END(sink__V181, _M_AsText); }
                END(sink__V181, _M__sTextEmbed); }
              { START(sink__V181, _M__sTextCons);
                { START(sink__V181, _M__sTextChars);
                  LITERAL(sink__V181,  "}," ); END(sink__V181, _M__sTextChars); }
                { START(sink__V181, _M__sTextNil);
                  END(sink__V181, _M__sTextNil); }
                END(sink__V181, _M__sTextCons); }
              END(sink__V181, _M__sTextCons); }
            END(sink__V181, _M__sTextCons); }
          END(sink__V181, _M__sTextCons); }
        END(sink__V181, _M__sTextCons); }
      END(sink__V181, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V181->context, namedFV__V186); UNLINK_VARIABLESET(sink__V181->context, varFV__V187);
    UNLINK_NamedPropertyLink(sink__V181->context, namedP__V184); UNLINK_VariablePropertyLink(sink__V181->context, varP__V185);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Form$2. */
int conBindOffs_M_X_Form_s2[] = {0 , 0 , 0};
char *nameFun_M_X_Form_s2(Term term) { return  "X-Form$2" ; }
struct _ConstructionDescriptor descriptor_M_X_Form_s2 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_X_Form_s2), conBindOffs_M_X_Form_s2, &nameFun_M_X_Form_s2, &step_M_X_Form_s2};

int step_M_X_Form_s2(Sink sink__V188, Term term__V189)
{
  int term__V189_count = LINK_COUNT(term__V189); permitUnusedInt(term__V189_count);
  Term sub__V190 = FORCE(sink__V188->context, SUB(term__V189, 0));
  EnumOf_M__sList choice__V191 = (IS_VARIABLE_USE(sub__V190) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V190));
  switch (choice__V191)
  {
    case Data_M__sNil: { /* Function SYMBOLS-X-Form-3$X-Form$2$$Nil case $Nil */
      ASSERT(sink__V188->context, !strcmp(SYMBOL(term__V189),  "X-Form$2" ));
      Term sub__V192 = SUB(term__V189, 0); permitUnusedTerm(sub__V192); int sub__V192_count = term__V189_count*LINK_COUNT(sub__V192); permitUnusedInt(sub__V192_count);
      ASSERT(sink__V188->context, !strcmp(SYMBOL(sub__V192),  "$Nil" ));
      Term sub__V193 = LINK(sink__V188->context, SUB(term__V189, 1)); int sub__V193_count = term__V189_count*LINK_COUNT(sub__V193); permitUnusedInt(sub__V193_count);
      /* sub__V193 = &#0 */
      
      NamedPropertyLink namedP__V194 = LINK_NamedPropertyLink(sink__V188->context, NAMED_PROPERTIES(term__V189));
      VariablePropertyLink varP__V195 = LINK_VariablePropertyLink(sink__V188->context, VARIABLE_PROPERTIES(term__V189));
      Hashset namedFV__V196 = LINK_VARIABLESET(sink__V188->context, asConstruction(term__V189)->properties->namedFreeVars);
      Hashset varFV__V197 = LINK_VARIABLESET(sink__V188->context, asConstruction(term__V189)->properties->variableFreeVars);
      UNLINK(sink__V188->context, term__V189);
      ADD_PROPERTIES(sink__V188, LINK_VARIABLESET(sink__V188->context, namedFV__V196), LINK_VARIABLESET(sink__V188->context, varFV__V197), LINK_NamedPropertyLink(sink__V188->context, namedP__V194), LINK_VariablePropertyLink(sink__V188->context, varP__V195));
      { START(sink__V188, _M_X_Form_s4);
        COPY(sink__V188, sub__V193);END(sink__V188, _M_X_Form_s4); }
      UNLINK_VARIABLESET(sink__V188->context, namedFV__V196); UNLINK_VARIABLESET(sink__V188->context, varFV__V197);
      UNLINK_NamedPropertyLink(sink__V188->context, namedP__V194); UNLINK_VariablePropertyLink(sink__V188->context, varP__V195);
      
      return 1;
    break; } case Data_M__sCons: { /* Function SYMBOLS-X-Form-4$X-Form$2$$Cons case $Cons */
      ASSERT(sink__V188->context, !strcmp(SYMBOL(term__V189),  "X-Form$2" ));
      Term sub__V198 = SUB(term__V189, 0); permitUnusedTerm(sub__V198); int sub__V198_count = term__V189_count*LINK_COUNT(sub__V198); permitUnusedInt(sub__V198_count);
      ASSERT(sink__V188->context, !strcmp(SYMBOL(sub__V198),  "$Cons" ));
      Term sub__V199 = LINK(sink__V188->context, SUB(sub__V198, 0)); int sub__V199_count = sub__V198_count*LINK_COUNT(sub__V199); permitUnusedInt(sub__V199_count);
      /* sub__V199 = &#0-0 */
      Term sub__V200 = LINK(sink__V188->context, SUB(sub__V198, 1)); int sub__V200_count = sub__V198_count*LINK_COUNT(sub__V200); permitUnusedInt(sub__V200_count);
      /* sub__V200 = &#0-1 */
      Term sub__V201 = LINK(sink__V188->context, SUB(term__V189, 1)); int sub__V201_count = term__V189_count*LINK_COUNT(sub__V201); permitUnusedInt(sub__V201_count);
      /* sub__V201 = &#2 */
      
      NamedPropertyLink namedP__V202 = LINK_NamedPropertyLink(sink__V188->context, NAMED_PROPERTIES(term__V189));
      VariablePropertyLink varP__V203 = LINK_VariablePropertyLink(sink__V188->context, VARIABLE_PROPERTIES(term__V189));
      Hashset namedFV__V204 = LINK_VARIABLESET(sink__V188->context, asConstruction(term__V189)->properties->namedFreeVars);
      Hashset varFV__V205 = LINK_VARIABLESET(sink__V188->context, asConstruction(term__V189)->properties->variableFreeVars);
      UNLINK(sink__V188->context, term__V189);
      ADD_PROPERTIES(sink__V188, LINK_VARIABLESET(sink__V188->context, namedFV__V204), LINK_VARIABLESET(sink__V188->context, varFV__V205), LINK_NamedPropertyLink(sink__V188->context, namedP__V202), LINK_VariablePropertyLink(sink__V188->context, varP__V203));
      { START(sink__V188, _M_X_Form_s3);
        COPY(sink__V188, sub__V199);COPY(sink__V188, sub__V200);COPY(sink__V188, sub__V201);END(sink__V188, _M_X_Form_s3); }
      UNLINK_VARIABLESET(sink__V188->context, namedFV__V204); UNLINK_VARIABLESET(sink__V188->context, varFV__V205);
      UNLINK_NamedPropertyLink(sink__V188->context, namedP__V202); UNLINK_VariablePropertyLink(sink__V188->context, varP__V203);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION X-Declaration$3. */
int conBindOffs_M_X_Declaration_s3[] = {0 , 1};
char *nameFun_M_X_Declaration_s3(Term term) { return  "X-Declaration$3" ; }
struct _ConstructionDescriptor descriptor_M_X_Declaration_s3 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_X_Declaration_s3), conBindOffs_M_X_Declaration_s3, &nameFun_M_X_Declaration_s3, &step_M_X_Declaration_s3};

int step_M_X_Declaration_s3(Sink sink__V206, Term term__V207)
{
  int term__V207_count = LINK_COUNT(term__V207); permitUnusedInt(term__V207_count);
  do {
    /* Contraction rule SYMBOLS-Polymorphic. */
    ASSERT(sink__V206->context, !strcmp(SYMBOL(term__V207),  "X-Declaration$3" ));
    Variable x__V208 = BINDER(term__V207,0,0); if (term__V207_count <= 1) UNBIND(x__V208);
    Term sub__V209 = LINK(sink__V206->context, SUB(term__V207, 0)); int sub__V209_count = term__V207_count*LINK_COUNT(sub__V209); permitUnusedInt(sub__V209_count);
    CRSX_CHECK_SORT(sink__V206->context, sub__V209, &sort_M_Reified_xDeclaration); /* sub__V209 = &#11 */
    Variable y__V210 = x__V208; permitUnusedVariable(y__V210);
    
    NamedPropertyLink namedP__V211 = LINK_NamedPropertyLink(sink__V206->context, NAMED_PROPERTIES(term__V207));
    VariablePropertyLink varP__V212 = LINK_VariablePropertyLink(sink__V206->context, VARIABLE_PROPERTIES(term__V207));
    Hashset namedFV__V213 = LINK_VARIABLESET(sink__V206->context, asConstruction(term__V207)->properties->namedFreeVars);
    Hashset varFV__V214 = LINK_VARIABLESET(sink__V206->context, asConstruction(term__V207)->properties->variableFreeVars);
    UNLINK(sink__V206->context, term__V207);
    { START(sink__V206, _M_X_Declaration);
      COPY(sink__V206, sub__V209); /* REUSED SUBSTITUTION */ END(sink__V206, _M_X_Declaration); }
    UNLINK_VARIABLESET(sink__V206->context, namedFV__V213); UNLINK_VARIABLESET(sink__V206->context, varFV__V214);
    UNLINK_NamedPropertyLink(sink__V206->context, namedP__V211); UNLINK_VariablePropertyLink(sink__V206->context, varP__V212);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Declaration$1. */
int conBindOffs_M_X_Declaration_s1[] = {0 , 0 , 0};
char *nameFun_M_X_Declaration_s1(Term term) { return  "X-Declaration$1" ; }
struct _ConstructionDescriptor descriptor_M_X_Declaration_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_X_Declaration_s1), conBindOffs_M_X_Declaration_s1, &nameFun_M_X_Declaration_s1, &step_M_X_Declaration_s1};

int step_M_X_Declaration_s1(Sink sink__V215, Term term__V216)
{
  int term__V216_count = LINK_COUNT(term__V216); permitUnusedInt(term__V216_count);
  do {
    /* Contraction rule SYMBOLS-Data. */
    ASSERT(sink__V215->context, !strcmp(SYMBOL(term__V216),  "X-Declaration$1" ));
    Term sub__V217 = LINK(sink__V215->context, SUB(term__V216, 0)); int sub__V217_count = term__V216_count*LINK_COUNT(sub__V217); permitUnusedInt(sub__V217_count);
    CRSX_CHECK_SORT(sink__V215->context, sub__V217, &sort_M_Reified_xSort); /* sub__V217 = &#11 */
    Term sub__V218 = LINK(sink__V215->context, SUB(term__V216, 1)); int sub__V218_count = term__V216_count*LINK_COUNT(sub__V218); permitUnusedInt(sub__V218_count);
    /* sub__V218 = &#12 */
    
    NamedPropertyLink namedP__V219 = LINK_NamedPropertyLink(sink__V215->context, NAMED_PROPERTIES(term__V216));
    VariablePropertyLink varP__V220 = LINK_VariablePropertyLink(sink__V215->context, VARIABLE_PROPERTIES(term__V216));
    Hashset namedFV__V221 = LINK_VARIABLESET(sink__V215->context, asConstruction(term__V216)->properties->namedFreeVars);
    Hashset varFV__V222 = LINK_VARIABLESET(sink__V215->context, asConstruction(term__V216)->properties->variableFreeVars);
    UNLINK(sink__V215->context, term__V216);
    { START(sink__V215, _M_X_Data);
      COPY(sink__V215, sub__V217);COPY(sink__V215, sub__V218);END(sink__V215, _M_X_Data); }
    UNLINK_VARIABLESET(sink__V215->context, namedFV__V221); UNLINK_VARIABLESET(sink__V215->context, varFV__V222);
    UNLINK_NamedPropertyLink(sink__V215->context, namedP__V219); UNLINK_VariablePropertyLink(sink__V215->context, varP__V220);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Declaration$2. */
int conBindOffs_M_X_Declaration_s2[] = {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0};
char *nameFun_M_X_Declaration_s2(Term term) { return  "X-Declaration$2" ; }
struct _ConstructionDescriptor descriptor_M_X_Declaration_s2 = {&sort_M_Reified_xVariable, 0, 7, sizeof(STRUCT_Con_M_X_Declaration_s2), conBindOffs_M_X_Declaration_s2, &nameFun_M_X_Declaration_s2, &step_M_X_Declaration_s2};

int step_M_X_Declaration_s2(Sink sink__V223, Term term__V224)
{
  int term__V224_count = LINK_COUNT(term__V224); permitUnusedInt(term__V224_count);
  do {
    /* Contraction rule SYMBOLS-Function. */
    ASSERT(sink__V223->context, !strcmp(SYMBOL(term__V224),  "X-Declaration$2" ));
    Term sub__V225 = LINK(sink__V223->context, SUB(term__V224, 0)); int sub__V225_count = term__V224_count*LINK_COUNT(sub__V225); permitUnusedInt(sub__V225_count);
    /* sub__V225 = &#11 */
    Term sub__V226 = LINK(sink__V223->context, SUB(term__V224, 1)); int sub__V226_count = term__V224_count*LINK_COUNT(sub__V226); permitUnusedInt(sub__V226_count);
    /* sub__V226 = &#12 */
    Term sub__V227 = LINK(sink__V223->context, SUB(term__V224, 2)); int sub__V227_count = term__V224_count*LINK_COUNT(sub__V227); permitUnusedInt(sub__V227_count);
    /* sub__V227 = &#13 */
    Term sub__V228 = LINK(sink__V223->context, SUB(term__V224, 3)); int sub__V228_count = term__V224_count*LINK_COUNT(sub__V228); permitUnusedInt(sub__V228_count);
    /* sub__V228 = &#14 */
    Term sub__V229 = LINK(sink__V223->context, SUB(term__V224, 4)); int sub__V229_count = term__V224_count*LINK_COUNT(sub__V229); permitUnusedInt(sub__V229_count);
    /* sub__V229 = &#15 */
    Term sub__V230 = LINK(sink__V223->context, SUB(term__V224, 5)); int sub__V230_count = term__V224_count*LINK_COUNT(sub__V230); permitUnusedInt(sub__V230_count);
    CRSX_CHECK_SORT(sink__V223->context, sub__V230, &sort_M_Reified_xSort); /* sub__V230 = &#16 */
    Term sub__V231 = LINK(sink__V223->context, SUB(term__V224, 6)); int sub__V231_count = term__V224_count*LINK_COUNT(sub__V231); permitUnusedInt(sub__V231_count);
    /* sub__V231 = &#17 */
    
    NamedPropertyLink namedP__V232 = LINK_NamedPropertyLink(sink__V223->context, NAMED_PROPERTIES(term__V224));
    VariablePropertyLink varP__V233 = LINK_VariablePropertyLink(sink__V223->context, VARIABLE_PROPERTIES(term__V224));
    Hashset namedFV__V234 = LINK_VARIABLESET(sink__V223->context, asConstruction(term__V224)->properties->namedFreeVars);
    Hashset varFV__V235 = LINK_VARIABLESET(sink__V223->context, asConstruction(term__V224)->properties->variableFreeVars);
    UNLINK(sink__V223->context, term__V224);
    { START(sink__V223, _M_X_Function);
      COPY(sink__V223, sub__V225);COPY(sink__V223, sub__V226);COPY(sink__V223, sub__V227);COPY(sink__V223, sub__V228);COPY(sink__V223, sub__V229);COPY(sink__V223, sub__V230);COPY(sink__V223, sub__V231);END(sink__V223, _M_X_Function); }
    UNLINK_VARIABLESET(sink__V223->context, namedFV__V234); UNLINK_VARIABLESET(sink__V223->context, varFV__V235);
    UNLINK_NamedPropertyLink(sink__V223->context, namedP__V232); UNLINK_VariablePropertyLink(sink__V223->context, varP__V233);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION ComputeSymbols2. */
int conBindOffs_M_ComputeSymbols2[] = {0 , 0 , 0 , 0};
char *nameFun_M_ComputeSymbols2(Term term) { return  "ComputeSymbols2" ; }
struct _ConstructionDescriptor descriptor_M_ComputeSymbols2 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_ComputeSymbols2), conBindOffs_M_ComputeSymbols2, &nameFun_M_ComputeSymbols2, &step_M_ComputeSymbols2};

int step_M_ComputeSymbols2(Sink sink__V236, Term term__V237)
{
  int term__V237_count = LINK_COUNT(term__V237); permitUnusedInt(term__V237_count);
  do {
    /* Contraction rule SYMBOLS-ComputeSymbols2-1. */
    ASSERT(sink__V236->context, !strcmp(SYMBOL(term__V237),  "ComputeSymbols2" ));
    Term sub__V238 = SUB(term__V237, 0); permitUnusedTerm(sub__V238); int sub__V238_count = term__V237_count*LINK_COUNT(sub__V238); permitUnusedInt(sub__V238_count);
    /* sub__V238 = &#1 */
    Term sub__V239 = LINK(sink__V236->context, SUB(term__V237, 1)); int sub__V239_count = term__V237_count*LINK_COUNT(sub__V239); permitUnusedInt(sub__V239_count);
    /* sub__V239 = &#2 */
    Term sub__V240 = SUB(term__V237, 2); permitUnusedTerm(sub__V240); int sub__V240_count = term__V237_count*LINK_COUNT(sub__V240); permitUnusedInt(sub__V240_count);
    /* sub__V240 = &#3 */
    
    NamedPropertyLink namedP__V241 = LINK_NamedPropertyLink(sink__V236->context, NAMED_PROPERTIES(term__V237));
    VariablePropertyLink varP__V242 = LINK_VariablePropertyLink(sink__V236->context, VARIABLE_PROPERTIES(term__V237));
    Hashset namedFV__V243 = LINK_VARIABLESET(sink__V236->context, asConstruction(term__V237)->properties->namedFreeVars);
    Hashset varFV__V244 = LINK_VARIABLESET(sink__V236->context, asConstruction(term__V237)->properties->variableFreeVars);
    UNLINK(sink__V236->context, term__V237);
    { START(sink__V236, _M__sTextCons);
      { START(sink__V236, _M__sTextEmbed);
        { START(sink__V236, _M_AsText);
          { START(sink__V236, _M_X_Declarations);
            COPY(sink__V236, sub__V239);END(sink__V236, _M_X_Declarations); }
          END(sink__V236, _M_AsText); }
        END(sink__V236, _M__sTextEmbed); }
      { START(sink__V236, _M__sTextCons);
        { START(sink__V236, _M__sTextBreak);
          LITERAL(sink__V236,  "\n" ); END(sink__V236, _M__sTextBreak); }
        { START(sink__V236, _M__sTextNil);
          END(sink__V236, _M__sTextNil); }
        END(sink__V236, _M__sTextCons); }
      END(sink__V236, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V236->context, namedFV__V243); UNLINK_VARIABLESET(sink__V236->context, varFV__V244);
    UNLINK_NamedPropertyLink(sink__V236->context, namedP__V241); UNLINK_VariablePropertyLink(sink__V236->context, varP__V242);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Declarations$1. */
int conBindOffs_M_X_Declarations_s1[] = {0 , 0 , 0};
char *nameFun_M_X_Declarations_s1(Term term) { return  "X-Declarations$1" ; }
struct _ConstructionDescriptor descriptor_M_X_Declarations_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_X_Declarations_s1), conBindOffs_M_X_Declarations_s1, &nameFun_M_X_Declarations_s1, &step_M_X_Declarations_s1};

int step_M_X_Declarations_s1(Sink sink__V245, Term term__V246)
{
  int term__V246_count = LINK_COUNT(term__V246); permitUnusedInt(term__V246_count);
  do {
    /* Contraction rule SYMBOLS-X-Declarations-1. */
    ASSERT(sink__V245->context, !strcmp(SYMBOL(term__V246),  "X-Declarations$1" ));
    Term sub__V247 = LINK(sink__V245->context, SUB(term__V246, 0)); int sub__V247_count = term__V246_count*LINK_COUNT(sub__V247); permitUnusedInt(sub__V247_count);
    /* sub__V247 = &#11 */
    Term sub__V248 = LINK(sink__V245->context, SUB(term__V246, 1)); int sub__V248_count = term__V246_count*LINK_COUNT(sub__V248); permitUnusedInt(sub__V248_count);
    /* sub__V248 = &#12 */
    
    NamedPropertyLink namedP__V249 = LINK_NamedPropertyLink(sink__V245->context, NAMED_PROPERTIES(term__V246));
    VariablePropertyLink varP__V250 = LINK_VariablePropertyLink(sink__V245->context, VARIABLE_PROPERTIES(term__V246));
    Hashset namedFV__V251 = LINK_VARIABLESET(sink__V245->context, asConstruction(term__V246)->properties->namedFreeVars);
    Hashset varFV__V252 = LINK_VARIABLESET(sink__V245->context, asConstruction(term__V246)->properties->variableFreeVars);
    UNLINK(sink__V245->context, term__V246);
    { START(sink__V245, _M__sTextCons);
      { START(sink__V245, _M__sTextEmbed);
        { START(sink__V245, _M_AsText);
          { START(sink__V245, _M_X_Declaration);
            COPY(sink__V245, sub__V247);END(sink__V245, _M_X_Declaration); }
          END(sink__V245, _M_AsText); }
        END(sink__V245, _M__sTextEmbed); }
      { START(sink__V245, _M__sTextCons);
        { START(sink__V245, _M__sTextEmbed);
          { START(sink__V245, _M_AsText);
            { START(sink__V245, _M_X_Declarations);
              COPY(sink__V245, sub__V248);END(sink__V245, _M_X_Declarations); }
            END(sink__V245, _M_AsText); }
          END(sink__V245, _M__sTextEmbed); }
        { START(sink__V245, _M__sTextNil);
          END(sink__V245, _M__sTextNil); }
        END(sink__V245, _M__sTextCons); }
      END(sink__V245, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V245->context, namedFV__V251); UNLINK_VARIABLESET(sink__V245->context, varFV__V252);
    UNLINK_NamedPropertyLink(sink__V245->context, namedP__V249); UNLINK_VariablePropertyLink(sink__V245->context, varP__V250);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Declarations$2. */
int conBindOffs_M_X_Declarations_s2[] = {0};
char *nameFun_M_X_Declarations_s2(Term term) { return  "X-Declarations$2" ; }
struct _ConstructionDescriptor descriptor_M_X_Declarations_s2 = {&sort_M_Reified_xVariable, 0, 0, sizeof(STRUCT_Con_M_X_Declarations_s2), conBindOffs_M_X_Declarations_s2, &nameFun_M_X_Declarations_s2, &step_M_X_Declarations_s2};

int step_M_X_Declarations_s2(Sink sink__V253, Term term__V254)
{
  int term__V254_count = LINK_COUNT(term__V254); permitUnusedInt(term__V254_count);
  do {
    /* Contraction rule SYMBOLS-X-Declarations-2. */
    ASSERT(sink__V253->context, !strcmp(SYMBOL(term__V254),  "X-Declarations$2" ));
    
    NamedPropertyLink namedP__V255 = LINK_NamedPropertyLink(sink__V253->context, NAMED_PROPERTIES(term__V254));
    VariablePropertyLink varP__V256 = LINK_VariablePropertyLink(sink__V253->context, VARIABLE_PROPERTIES(term__V254));
    Hashset namedFV__V257 = LINK_VARIABLESET(sink__V253->context, asConstruction(term__V254)->properties->namedFreeVars);
    Hashset varFV__V258 = LINK_VARIABLESET(sink__V253->context, asConstruction(term__V254)->properties->variableFreeVars);
    UNLINK(sink__V253->context, term__V254);
    { START(sink__V253, _M__sTextNil); END(sink__V253, _M__sTextNil); }
    UNLINK_VARIABLESET(sink__V253->context, namedFV__V257); UNLINK_VARIABLESET(sink__V253->context, varFV__V258);
    UNLINK_NamedPropertyLink(sink__V253->context, namedP__V255); UNLINK_VariablePropertyLink(sink__V253->context, varP__V256);
    return 1;
  } while (0);
  return 0;
}

#ifdef __cplusplus
}
#endif
/* END OF C RULES FOR CRSX CRSXC MODULE SYMBOLS. */
