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
    UNLINK(sink__V1->context, term__V2);
    { START(sink__V1, _M_ComputeSymbols2);
      COPY(sink__V1, sub__V3);COPY(sink__V1, sub__V4);{ Term term__V7;
        { char *value__V8 = getenv( "MODULE" );
          if (value__V8) term__V7 = makeStringLiteral(sink__V1->context, value__V8);
          else {term__V7 = makeStringLiteral(sink__V1->context,  "" ); }
        }
        COPY(sink__V1, term__V7); /*CONSERVATIVE*/ }
      END(sink__V1, _M_ComputeSymbols2); }
    UNLINK_NamedPropertyLink(sink__V1->context, namedP__V5); UNLINK_VariablePropertyLink(sink__V1->context, varP__V6);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Data. */
int conBindOffs_M_X_Data[] = {0 , 0 , 0};
char *nameFun_M_X_Data(Term term) { return  "X-Data" ; }
struct _ConstructionDescriptor descriptor_M_X_Data = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_X_Data), conBindOffs_M_X_Data, &nameFun_M_X_Data, &step_M_X_Data};

int step_M_X_Data(Sink sink__V9, Term term__V10)
{
  int term__V10_count = LINK_COUNT(term__V10); permitUnusedInt(term__V10_count);
  Term sub__V11 = FORCE(sink__V9->context, SUB(term__V10, 0));
  EnumOf_M_Reified_xSort choice__V12 = (IS_VARIABLE_USE(sub__V11) ? VarOf_M_Reified_xSort : (EnumOf_M_Reified_xSort) TAG(sub__V11));
  switch (choice__V12)
  {
    case Data_M_SORT: { /* Function SYMBOLS-X-Data-1$X-Data$SORT case SORT */
      ASSERT(sink__V9->context, !strcmp(SYMBOL(term__V10),  "X-Data" ));
      Term sub__V13 = SUB(term__V10, 0); permitUnusedTerm(sub__V13); int sub__V13_count = term__V10_count*LINK_COUNT(sub__V13); permitUnusedInt(sub__V13_count);
      CRSX_CHECK_SORT(sink__V9->context, sub__V13, &sort_M_Reified_xSort); ASSERT(sink__V9->context, !strcmp(SYMBOL(sub__V13),  "SORT" ));
      Term sub__V14 = LINK(sink__V9->context, SUB(sub__V13, 0)); int sub__V14_count = sub__V13_count*LINK_COUNT(sub__V14); permitUnusedInt(sub__V14_count);
      /* sub__V14 = &#0-0 */
      Term sub__V15 = LINK(sink__V9->context, SUB(sub__V13, 1)); int sub__V15_count = sub__V13_count*LINK_COUNT(sub__V15); permitUnusedInt(sub__V15_count);
      /* sub__V15 = &#0-1 */
      Term sub__V16 = LINK(sink__V9->context, SUB(term__V10, 1)); int sub__V16_count = term__V10_count*LINK_COUNT(sub__V16); permitUnusedInt(sub__V16_count);
      /* sub__V16 = &#2 */
      NamedPropertyLink namedP__V17 = LINK_NamedPropertyLink(sink__V9->context, NAMED_PROPERTIES(term__V10));
      VariablePropertyLink varP__V18 = LINK_VariablePropertyLink(sink__V9->context, VARIABLE_PROPERTIES(term__V10));
      UNLINK(sink__V9->context, term__V10);
      ADD_PROPERTIES(sink__V9, LINK_NamedPropertyLink(sink__V9->context, namedP__V17), LINK_VariablePropertyLink(sink__V9->context, varP__V18));
      { START(sink__V9, _M_X_Data_s1);
        COPY(sink__V9, sub__V14);COPY(sink__V9, sub__V15);COPY(sink__V9, sub__V16);END(sink__V9, _M_X_Data_s1); }
      UNLINK_NamedPropertyLink(sink__V9->context, namedP__V17); UNLINK_VariablePropertyLink(sink__V9->context, varP__V18);
      
      return 1;
    break; } case Data_M_SORT_PROPERTY: { /* Function SYMBOLS-X-Data-2$X-Data$SORT-PROPERTY case SORT-PROPERTY */
      ASSERT(sink__V9->context, !strcmp(SYMBOL(term__V10),  "X-Data" ));
      Term sub__V19 = SUB(term__V10, 0); permitUnusedTerm(sub__V19); int sub__V19_count = term__V10_count*LINK_COUNT(sub__V19); permitUnusedInt(sub__V19_count);
      CRSX_CHECK_SORT(sink__V9->context, sub__V19, &sort_M_Reified_xSort); ASSERT(sink__V9->context, !strcmp(SYMBOL(sub__V19),  "SORT-PROPERTY" ));
      Term sub__V20 = LINK(sink__V9->context, SUB(sub__V19, 0)); int sub__V20_count = sub__V19_count*LINK_COUNT(sub__V20); permitUnusedInt(sub__V20_count);
      CRSX_CHECK_SORT(sink__V9->context, sub__V20, &sort_M_Reified_xSort); /* sub__V20 = &#0-0 */
      Term sub__V21 = LINK(sink__V9->context, SUB(sub__V19, 1)); int sub__V21_count = sub__V19_count*LINK_COUNT(sub__V21); permitUnusedInt(sub__V21_count);
      CRSX_CHECK_SORT(sink__V9->context, sub__V21, &sort_M_Reified_xSort); /* sub__V21 = &#0-1 */
      Term sub__V22 = LINK(sink__V9->context, SUB(sub__V19, 2)); int sub__V22_count = sub__V19_count*LINK_COUNT(sub__V22); permitUnusedInt(sub__V22_count);
      CRSX_CHECK_SORT(sink__V9->context, sub__V22, &sort_M_Reified_xSort); /* sub__V22 = &#0-2 */
      Term sub__V23 = LINK(sink__V9->context, SUB(term__V10, 1)); int sub__V23_count = term__V10_count*LINK_COUNT(sub__V23); permitUnusedInt(sub__V23_count);
      /* sub__V23 = &#3 */
      NamedPropertyLink namedP__V24 = LINK_NamedPropertyLink(sink__V9->context, NAMED_PROPERTIES(term__V10));
      VariablePropertyLink varP__V25 = LINK_VariablePropertyLink(sink__V9->context, VARIABLE_PROPERTIES(term__V10));
      UNLINK(sink__V9->context, term__V10);
      ADD_PROPERTIES(sink__V9, LINK_NamedPropertyLink(sink__V9->context, namedP__V24), LINK_VariablePropertyLink(sink__V9->context, varP__V25));
      { START(sink__V9, _M_X_Data_s2);
        COPY(sink__V9, sub__V20);COPY(sink__V9, sub__V21);COPY(sink__V9, sub__V22);COPY(sink__V9, sub__V23);END(sink__V9, _M_X_Data_s2); }
      UNLINK_NamedPropertyLink(sink__V9->context, namedP__V24); UNLINK_VariablePropertyLink(sink__V9->context, varP__V25);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION X-Declaration. */
int conBindOffs_M_X_Declaration[] = {0 , 0};
char *nameFun_M_X_Declaration(Term term) { return  "X-Declaration" ; }
struct _ConstructionDescriptor descriptor_M_X_Declaration = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_X_Declaration), conBindOffs_M_X_Declaration, &nameFun_M_X_Declaration, &step_M_X_Declaration};

int step_M_X_Declaration(Sink sink__V26, Term term__V27)
{
  int term__V27_count = LINK_COUNT(term__V27); permitUnusedInt(term__V27_count);
  Term sub__V28 = FORCE(sink__V26->context, SUB(term__V27, 0));
  EnumOf_M_Reified_xDeclaration choice__V29 = (IS_VARIABLE_USE(sub__V28) ? VarOf_M_Reified_xDeclaration : (EnumOf_M_Reified_xDeclaration) TAG(sub__V28));
  switch (choice__V29)
  {
    case Data_M_DATA: { /* Function SYMBOLS-Data$X-Declaration$DATA case DATA */
      ASSERT(sink__V26->context, !strcmp(SYMBOL(term__V27),  "X-Declaration" ));
      Term sub__V30 = SUB(term__V27, 0); permitUnusedTerm(sub__V30); int sub__V30_count = term__V27_count*LINK_COUNT(sub__V30); permitUnusedInt(sub__V30_count);
      CRSX_CHECK_SORT(sink__V26->context, sub__V30, &sort_M_Reified_xDeclaration); ASSERT(sink__V26->context, !strcmp(SYMBOL(sub__V30),  "DATA" ));
      Term sub__V31 = LINK(sink__V26->context, SUB(sub__V30, 0)); int sub__V31_count = sub__V30_count*LINK_COUNT(sub__V31); permitUnusedInt(sub__V31_count);
      CRSX_CHECK_SORT(sink__V26->context, sub__V31, &sort_M_Reified_xSort); /* sub__V31 = &#0-0 */
      Term sub__V32 = LINK(sink__V26->context, SUB(sub__V30, 1)); int sub__V32_count = sub__V30_count*LINK_COUNT(sub__V32); permitUnusedInt(sub__V32_count);
      /* sub__V32 = &#0-1 */
      NamedPropertyLink namedP__V33 = LINK_NamedPropertyLink(sink__V26->context, NAMED_PROPERTIES(term__V27));
      VariablePropertyLink varP__V34 = LINK_VariablePropertyLink(sink__V26->context, VARIABLE_PROPERTIES(term__V27));
      UNLINK(sink__V26->context, term__V27);
      ADD_PROPERTIES(sink__V26, LINK_NamedPropertyLink(sink__V26->context, namedP__V33), LINK_VariablePropertyLink(sink__V26->context, varP__V34));
      { START(sink__V26, _M_X_Declaration_s1);
        COPY(sink__V26, sub__V31);COPY(sink__V26, sub__V32);END(sink__V26, _M_X_Declaration_s1); }
      UNLINK_NamedPropertyLink(sink__V26->context, namedP__V33); UNLINK_VariablePropertyLink(sink__V26->context, varP__V34);
      
      return 1;
    break; } case Data_M_FUNCTION: { /* Function SYMBOLS-Function$X-Declaration$FUNCTION case FUNCTION */
      ASSERT(sink__V26->context, !strcmp(SYMBOL(term__V27),  "X-Declaration" ));
      Term sub__V35 = SUB(term__V27, 0); permitUnusedTerm(sub__V35); int sub__V35_count = term__V27_count*LINK_COUNT(sub__V35); permitUnusedInt(sub__V35_count);
      CRSX_CHECK_SORT(sink__V26->context, sub__V35, &sort_M_Reified_xDeclaration); ASSERT(sink__V26->context, !strcmp(SYMBOL(sub__V35),  "FUNCTION" ));
      Term sub__V36 = LINK(sink__V26->context, SUB(sub__V35, 0)); int sub__V36_count = sub__V35_count*LINK_COUNT(sub__V36); permitUnusedInt(sub__V36_count);
      /* sub__V36 = &#0-0 */
      Term sub__V37 = LINK(sink__V26->context, SUB(sub__V35, 1)); int sub__V37_count = sub__V35_count*LINK_COUNT(sub__V37); permitUnusedInt(sub__V37_count);
      /* sub__V37 = &#0-1 */
      Term sub__V38 = LINK(sink__V26->context, SUB(sub__V35, 2)); int sub__V38_count = sub__V35_count*LINK_COUNT(sub__V38); permitUnusedInt(sub__V38_count);
      /* sub__V38 = &#0-2 */
      Term sub__V39 = LINK(sink__V26->context, SUB(sub__V35, 3)); int sub__V39_count = sub__V35_count*LINK_COUNT(sub__V39); permitUnusedInt(sub__V39_count);
      /* sub__V39 = &#0-3 */
      Term sub__V40 = LINK(sink__V26->context, SUB(sub__V35, 4)); int sub__V40_count = sub__V35_count*LINK_COUNT(sub__V40); permitUnusedInt(sub__V40_count);
      /* sub__V40 = &#0-4 */
      Term sub__V41 = LINK(sink__V26->context, SUB(sub__V35, 5)); int sub__V41_count = sub__V35_count*LINK_COUNT(sub__V41); permitUnusedInt(sub__V41_count);
      CRSX_CHECK_SORT(sink__V26->context, sub__V41, &sort_M_Reified_xSort); /* sub__V41 = &#0-5 */
      Term sub__V42 = LINK(sink__V26->context, SUB(sub__V35, 6)); int sub__V42_count = sub__V35_count*LINK_COUNT(sub__V42); permitUnusedInt(sub__V42_count);
      /* sub__V42 = &#0-6 */
      NamedPropertyLink namedP__V43 = LINK_NamedPropertyLink(sink__V26->context, NAMED_PROPERTIES(term__V27));
      VariablePropertyLink varP__V44 = LINK_VariablePropertyLink(sink__V26->context, VARIABLE_PROPERTIES(term__V27));
      UNLINK(sink__V26->context, term__V27);
      ADD_PROPERTIES(sink__V26, LINK_NamedPropertyLink(sink__V26->context, namedP__V43), LINK_VariablePropertyLink(sink__V26->context, varP__V44));
      { START(sink__V26, _M_X_Declaration_s2);
        COPY(sink__V26, sub__V36);COPY(sink__V26, sub__V37);COPY(sink__V26, sub__V38);COPY(sink__V26, sub__V39);COPY(sink__V26, sub__V40);COPY(sink__V26, sub__V41);COPY(sink__V26, sub__V42);END(sink__V26, _M_X_Declaration_s2); }
      UNLINK_NamedPropertyLink(sink__V26->context, namedP__V43); UNLINK_VariablePropertyLink(sink__V26->context, varP__V44);
      
      return 1;
    break; } case Data_M_POLYMORPHIC: { /* Function SYMBOLS-Polymorphic$X-Declaration$POLYMORPHIC case POLYMORPHIC */
      ASSERT(sink__V26->context, !strcmp(SYMBOL(term__V27),  "X-Declaration" ));
      Term sub__V45 = SUB(term__V27, 0); permitUnusedTerm(sub__V45); int sub__V45_count = term__V27_count*LINK_COUNT(sub__V45); permitUnusedInt(sub__V45_count);
      CRSX_CHECK_SORT(sink__V26->context, sub__V45, &sort_M_Reified_xDeclaration); ASSERT(sink__V26->context, !strcmp(SYMBOL(sub__V45),  "POLYMORPHIC" ));
      Variable y__V46 = BINDER(sub__V45,0,0); if (sub__V45_count <= 1) UNBIND(y__V46);
      Term sub__V47 = LINK(sink__V26->context, SUB(sub__V45, 0)); int sub__V47_count = sub__V45_count*LINK_COUNT(sub__V47); permitUnusedInt(sub__V47_count);
      CRSX_CHECK_SORT(sink__V26->context, sub__V47, &sort_M_Reified_xDeclaration); /* sub__V47 = &#0-0 */
      NamedPropertyLink namedP__V48 = LINK_NamedPropertyLink(sink__V26->context, NAMED_PROPERTIES(term__V27));
      VariablePropertyLink varP__V49 = LINK_VariablePropertyLink(sink__V26->context, VARIABLE_PROPERTIES(term__V27));
      UNLINK(sink__V26->context, term__V27);
      ADD_PROPERTIES(sink__V26, LINK_NamedPropertyLink(sink__V26->context, namedP__V48), LINK_VariablePropertyLink(sink__V26->context, varP__V49));
      { START(sink__V26, _M_X_Declaration_s3);
        { if (!IS_BOUND(y__V46)) { REBIND(y__V46);
            Variable binds__V50[1] = {y__V46}; BINDS(sink__V26, 1, binds__V50);
            COPY(sink__V26, sub__V47); /* REUSED SUBSTITUTION */  }
          else { Variable b__V51 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V26->context,"b__V51");
            Variable binds__V52[1] = {b__V51}; BINDS(sink__V26, 1, binds__V52);
            {
              Term arg__V53;
              { Sink buf__V54 = ALLOCA_BUFFER(sink__V26->context);
                USE(buf__V54, b__V51); arg__V53 = BUFFER_TERM(buf__V54); FREE_BUFFER(buf__V54); }
              Variable vars__V55[1] = {y__V46};
              Term args__V56[1] = {arg__V53};
              struct _SubstitutionFrame substitution__V57 = {NULL, 0, 1, vars__V55, args__V56, NULL};
              SUBSTITUTE(sink__V26, sub__V47, &substitution__V57); }
                }
           }
        END(sink__V26, _M_X_Declaration_s3); }
      UNLINK_NamedPropertyLink(sink__V26->context, namedP__V48); UNLINK_VariablePropertyLink(sink__V26->context, varP__V49);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION X-Function. */
int conBindOffs_M_X_Function[] = {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0};
char *nameFun_M_X_Function(Term term) { return  "X-Function" ; }
struct _ConstructionDescriptor descriptor_M_X_Function = {&sort_M_Reified_xVariable, 0, 7, sizeof(STRUCT_Con_M_X_Function), conBindOffs_M_X_Function, &nameFun_M_X_Function, &step_M_X_Function};

int step_M_X_Function(Sink sink__V58, Term term__V59)
{
  int term__V59_count = LINK_COUNT(term__V59); permitUnusedInt(term__V59_count);
  do {
    /* Contraction rule SYMBOLS-X-Function-1. */
    ASSERT(sink__V58->context, !strcmp(SYMBOL(term__V59),  "X-Function" ));
    Term sub__V60 = SUB(term__V59, 0); permitUnusedTerm(sub__V60); int sub__V60_count = term__V59_count*LINK_COUNT(sub__V60); permitUnusedInt(sub__V60_count);
    /* sub__V60 = &#1 */
    Term sub__V61 = SUB(term__V59, 1); permitUnusedTerm(sub__V61); int sub__V61_count = term__V59_count*LINK_COUNT(sub__V61); permitUnusedInt(sub__V61_count);
    /* sub__V61 = &#2 */
    Term sub__V62 = SUB(term__V59, 2); permitUnusedTerm(sub__V62); int sub__V62_count = term__V59_count*LINK_COUNT(sub__V62); permitUnusedInt(sub__V62_count);
    /* sub__V62 = &#3 */
    Term sub__V63 = SUB(term__V59, 3); permitUnusedTerm(sub__V63); int sub__V63_count = term__V59_count*LINK_COUNT(sub__V63); permitUnusedInt(sub__V63_count);
    /* sub__V63 = &#4 */
    Term sub__V64 = LINK(sink__V58->context, SUB(term__V59, 4)); int sub__V64_count = term__V59_count*LINK_COUNT(sub__V64); permitUnusedInt(sub__V64_count);
    UNLINK_SUB(sink__V58->context, term__V59,  4); NORMALIZE(sink__V58->context, sub__V64); SUB(term__V59,  4) = LINK(sink__V58->context, sub__V64);
    /* sub__V64 = &#5 */
    Term sub__V65 = SUB(term__V59, 5); permitUnusedTerm(sub__V65); int sub__V65_count = term__V59_count*LINK_COUNT(sub__V65); permitUnusedInt(sub__V65_count);
    CRSX_CHECK_SORT(sink__V58->context, sub__V65, &sort_M_Reified_xSort); /* sub__V65 = &#6 */
    Term sub__V66 = SUB(term__V59, 6); permitUnusedTerm(sub__V66); int sub__V66_count = term__V59_count*LINK_COUNT(sub__V66); permitUnusedInt(sub__V66_count);
    /* sub__V66 = &#7 */
    NamedPropertyLink namedP__V67 = LINK_NamedPropertyLink(sink__V58->context, NAMED_PROPERTIES(term__V59));
    VariablePropertyLink varP__V68 = LINK_VariablePropertyLink(sink__V58->context, VARIABLE_PROPERTIES(term__V59));
    UNLINK(sink__V58->context, term__V59);
    { START(sink__V58, _M__sTextCons);
      { START(sink__V58, _M__sTextEmbed);
        { START(sink__V58, _M_AsText);
          { START(sink__V58, _M_MapText_s1);
            COPY(sink__V58, sub__V64);{ Variable x__V69 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V58->context,"x__V69");
              Variable binds__V70[1] = {x__V69}; BINDS(sink__V58, 1, binds__V70);
              { START(sink__V58, _M_X_Form);
                USE(sink__V58, x__V69); END(sink__V58, _M_X_Form); }
               }
            END(sink__V58, _M_MapText_s1); }
          END(sink__V58, _M_AsText); }
        END(sink__V58, _M__sTextEmbed); }
      { START(sink__V58, _M__sTextNil); END(sink__V58, _M__sTextNil); }
      END(sink__V58, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V58->context, namedP__V67); UNLINK_VariablePropertyLink(sink__V58->context, varP__V68);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Declarations. */
int conBindOffs_M_X_Declarations[] = {0 , 0};
char *nameFun_M_X_Declarations(Term term) { return  "X-Declarations" ; }
struct _ConstructionDescriptor descriptor_M_X_Declarations = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_X_Declarations), conBindOffs_M_X_Declarations, &nameFun_M_X_Declarations, &step_M_X_Declarations};

int step_M_X_Declarations(Sink sink__V71, Term term__V72)
{
  int term__V72_count = LINK_COUNT(term__V72); permitUnusedInt(term__V72_count);
  Term sub__V73 = FORCE(sink__V71->context, SUB(term__V72, 0));
  EnumOf_M__sList choice__V74 = (IS_VARIABLE_USE(sub__V73) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V73));
  switch (choice__V74)
  {
    case Data_M__sCons: { /* Function SYMBOLS-X-Declarations-1$X-Declarations$$Cons case $Cons */
      ASSERT(sink__V71->context, !strcmp(SYMBOL(term__V72),  "X-Declarations" ));
      Term sub__V75 = SUB(term__V72, 0); permitUnusedTerm(sub__V75); int sub__V75_count = term__V72_count*LINK_COUNT(sub__V75); permitUnusedInt(sub__V75_count);
      ASSERT(sink__V71->context, !strcmp(SYMBOL(sub__V75),  "$Cons" ));
      Term sub__V76 = LINK(sink__V71->context, SUB(sub__V75, 0)); int sub__V76_count = sub__V75_count*LINK_COUNT(sub__V76); permitUnusedInt(sub__V76_count);
      /* sub__V76 = &#0-0 */
      Term sub__V77 = LINK(sink__V71->context, SUB(sub__V75, 1)); int sub__V77_count = sub__V75_count*LINK_COUNT(sub__V77); permitUnusedInt(sub__V77_count);
      /* sub__V77 = &#0-1 */
      NamedPropertyLink namedP__V78 = LINK_NamedPropertyLink(sink__V71->context, NAMED_PROPERTIES(term__V72));
      VariablePropertyLink varP__V79 = LINK_VariablePropertyLink(sink__V71->context, VARIABLE_PROPERTIES(term__V72));
      UNLINK(sink__V71->context, term__V72);
      ADD_PROPERTIES(sink__V71, LINK_NamedPropertyLink(sink__V71->context, namedP__V78), LINK_VariablePropertyLink(sink__V71->context, varP__V79));
      { START(sink__V71, _M_X_Declarations_s1);
        COPY(sink__V71, sub__V76);COPY(sink__V71, sub__V77);END(sink__V71, _M_X_Declarations_s1); }
      UNLINK_NamedPropertyLink(sink__V71->context, namedP__V78); UNLINK_VariablePropertyLink(sink__V71->context, varP__V79);
      
      return 1;
    break; } case Data_M__sNil: { /* Function SYMBOLS-X-Declarations-2$X-Declarations$$Nil case $Nil */
      ASSERT(sink__V71->context, !strcmp(SYMBOL(term__V72),  "X-Declarations" ));
      Term sub__V80 = SUB(term__V72, 0); permitUnusedTerm(sub__V80); int sub__V80_count = term__V72_count*LINK_COUNT(sub__V80); permitUnusedInt(sub__V80_count);
      ASSERT(sink__V71->context, !strcmp(SYMBOL(sub__V80),  "$Nil" ));
      NamedPropertyLink namedP__V81 = LINK_NamedPropertyLink(sink__V71->context, NAMED_PROPERTIES(term__V72));
      VariablePropertyLink varP__V82 = LINK_VariablePropertyLink(sink__V71->context, VARIABLE_PROPERTIES(term__V72));
      UNLINK(sink__V71->context, term__V72);
      ADD_PROPERTIES(sink__V71, LINK_NamedPropertyLink(sink__V71->context, namedP__V81), LINK_VariablePropertyLink(sink__V71->context, varP__V82));
      { START(sink__V71, _M_X_Declarations_s2);
        END(sink__V71, _M_X_Declarations_s2); }
      UNLINK_NamedPropertyLink(sink__V71->context, namedP__V81); UNLINK_VariablePropertyLink(sink__V71->context, varP__V82);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION ComputeSymbols. */
int conBindOffs_M_ComputeSymbols[] = {0 , 0};
char *nameFun_M_ComputeSymbols(Term term) { return  "ComputeSymbols" ; }
struct _ConstructionDescriptor descriptor_M_ComputeSymbols = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_ComputeSymbols), conBindOffs_M_ComputeSymbols, &nameFun_M_ComputeSymbols, &step_M_ComputeSymbols};

int step_M_ComputeSymbols(Sink sink__V83, Term term__V84)
{
  int term__V84_count = LINK_COUNT(term__V84); permitUnusedInt(term__V84_count);
  Term sub__V85 = FORCE(sink__V83->context, SUB(term__V84, 0));
  EnumOf_M_Reify_xCRSX choice__V86 = (IS_VARIABLE_USE(sub__V85) ? VarOf_M_Reify_xCRSX : (EnumOf_M_Reify_xCRSX) TAG(sub__V85));
  switch (choice__V86)
  {
    case Data_M_CRSX: { /* Function SYMBOLS-ComputeSymbols-1$ComputeSymbols$CRSX case CRSX */
      ASSERT(sink__V83->context, !strcmp(SYMBOL(term__V84),  "ComputeSymbols" ));
      Term sub__V87 = SUB(term__V84, 0); permitUnusedTerm(sub__V87); int sub__V87_count = term__V84_count*LINK_COUNT(sub__V87); permitUnusedInt(sub__V87_count);
      CRSX_CHECK_SORT(sink__V83->context, sub__V87, &sort_M_Reify_xCRSX); ASSERT(sink__V83->context, !strcmp(SYMBOL(sub__V87),  "CRSX" ));
      Term sub__V88 = LINK(sink__V83->context, SUB(sub__V87, 0)); int sub__V88_count = sub__V87_count*LINK_COUNT(sub__V88); permitUnusedInt(sub__V88_count);
      /* sub__V88 = &#0-0 */
      Term sub__V89 = LINK(sink__V83->context, SUB(sub__V87, 1)); int sub__V89_count = sub__V87_count*LINK_COUNT(sub__V89); permitUnusedInt(sub__V89_count);
      /* sub__V89 = &#0-1 */
      NamedPropertyLink namedP__V90 = LINK_NamedPropertyLink(sink__V83->context, NAMED_PROPERTIES(term__V84));
      VariablePropertyLink varP__V91 = LINK_VariablePropertyLink(sink__V83->context, VARIABLE_PROPERTIES(term__V84));
      UNLINK(sink__V83->context, term__V84);
      ADD_PROPERTIES(sink__V83, LINK_NamedPropertyLink(sink__V83->context, namedP__V90), LINK_VariablePropertyLink(sink__V83->context, varP__V91));
      { START(sink__V83, _M_ComputeSymbols_s1);
        COPY(sink__V83, sub__V88);COPY(sink__V83, sub__V89);END(sink__V83, _M_ComputeSymbols_s1); }
      UNLINK_NamedPropertyLink(sink__V83->context, namedP__V90); UNLINK_VariablePropertyLink(sink__V83->context, varP__V91);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION X-Form. */
int conBindOffs_M_X_Form[] = {0 , 0};
char *nameFun_M_X_Form(Term term) { return  "X-Form" ; }
struct _ConstructionDescriptor descriptor_M_X_Form = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_X_Form), conBindOffs_M_X_Form, &nameFun_M_X_Form, &step_M_X_Form};

int step_M_X_Form(Sink sink__V92, Term term__V93)
{
  int term__V93_count = LINK_COUNT(term__V93); permitUnusedInt(term__V93_count);
  Term sub__V94 = FORCE(sink__V92->context, SUB(term__V93, 0));
  EnumOf_M_Reified_xForm choice__V95 = (IS_VARIABLE_USE(sub__V94) ? VarOf_M_Reified_xForm : (EnumOf_M_Reified_xForm) TAG(sub__V94));
  switch (choice__V95)
  {
    case Data_M_SORT_SET: { /* Function SYMBOLS-X-Form-1$X-Form$SORT-SET case SORT-SET */
      ASSERT(sink__V92->context, !strcmp(SYMBOL(term__V93),  "X-Form" ));
      Term sub__V96 = SUB(term__V93, 0); permitUnusedTerm(sub__V96); int sub__V96_count = term__V93_count*LINK_COUNT(sub__V96); permitUnusedInt(sub__V96_count);
      CRSX_CHECK_SORT(sink__V92->context, sub__V96, &sort_M_Reified_xForm); ASSERT(sink__V92->context, !strcmp(SYMBOL(sub__V96),  "SORT-SET" ));
      Term sub__V97 = LINK(sink__V92->context, SUB(sub__V96, 0)); int sub__V97_count = sub__V96_count*LINK_COUNT(sub__V97); permitUnusedInt(sub__V97_count);
      CRSX_CHECK_SORT(sink__V92->context, sub__V97, &sort_M_Reified_xSort); /* sub__V97 = &#0-0 */
      Term sub__V98 = LINK(sink__V92->context, SUB(sub__V96, 1)); int sub__V98_count = sub__V96_count*LINK_COUNT(sub__V98); permitUnusedInt(sub__V98_count);
      CRSX_CHECK_SORT(sink__V92->context, sub__V98, &sort_M_Reified_xSort); /* sub__V98 = &#0-1 */
      Term sub__V99 = LINK(sink__V92->context, SUB(sub__V96, 2)); int sub__V99_count = sub__V96_count*LINK_COUNT(sub__V99); permitUnusedInt(sub__V99_count);
      CRSX_CHECK_SORT(sink__V92->context, sub__V99, &sort_M_Reified_xForm); /* sub__V99 = &#0-2 */
      NamedPropertyLink namedP__V100 = LINK_NamedPropertyLink(sink__V92->context, NAMED_PROPERTIES(term__V93));
      VariablePropertyLink varP__V101 = LINK_VariablePropertyLink(sink__V92->context, VARIABLE_PROPERTIES(term__V93));
      UNLINK(sink__V92->context, term__V93);
      ADD_PROPERTIES(sink__V92, LINK_NamedPropertyLink(sink__V92->context, namedP__V100), LINK_VariablePropertyLink(sink__V92->context, varP__V101));
      { START(sink__V92, _M_X_Form_s6);
        COPY(sink__V92, sub__V97);COPY(sink__V92, sub__V98);COPY(sink__V92, sub__V99);END(sink__V92, _M_X_Form_s6); }
      UNLINK_NamedPropertyLink(sink__V92->context, namedP__V100); UNLINK_VariablePropertyLink(sink__V92->context, varP__V101);
      
      return 1;
    break; } case Data_M_SORT_ALLOWS_VARIABLES: { /* Function SYMBOLS-X-Form-2$X-Form$SORT-ALLOWS-VARIABLES case SORT-ALLOWS-VARIABLES */
      ASSERT(sink__V92->context, !strcmp(SYMBOL(term__V93),  "X-Form" ));
      Term sub__V102 = SUB(term__V93, 0); permitUnusedTerm(sub__V102); int sub__V102_count = term__V93_count*LINK_COUNT(sub__V102); permitUnusedInt(sub__V102_count);
      CRSX_CHECK_SORT(sink__V92->context, sub__V102, &sort_M_Reified_xForm); ASSERT(sink__V92->context, !strcmp(SYMBOL(sub__V102),  "SORT-ALLOWS-VARIABLES" ));
      NamedPropertyLink namedP__V103 = LINK_NamedPropertyLink(sink__V92->context, NAMED_PROPERTIES(term__V93));
      VariablePropertyLink varP__V104 = LINK_VariablePropertyLink(sink__V92->context, VARIABLE_PROPERTIES(term__V93));
      UNLINK(sink__V92->context, term__V93);
      ADD_PROPERTIES(sink__V92, LINK_NamedPropertyLink(sink__V92->context, namedP__V103), LINK_VariablePropertyLink(sink__V92->context, varP__V104));
      { START(sink__V92, _M_X_Form_s5); END(sink__V92, _M_X_Form_s5); }
      UNLINK_NamedPropertyLink(sink__V92->context, namedP__V103); UNLINK_VariablePropertyLink(sink__V92->context, varP__V104);
      
      return 1;
    break; } case Data_M_FORM: { /* Function SYMBOLS-X-Form-3$X-Form$FORM case FORM */
      ASSERT(sink__V92->context, !strcmp(SYMBOL(term__V93),  "X-Form" ));
      Term sub__V105 = SUB(term__V93, 0); permitUnusedTerm(sub__V105); int sub__V105_count = term__V93_count*LINK_COUNT(sub__V105); permitUnusedInt(sub__V105_count);
      CRSX_CHECK_SORT(sink__V92->context, sub__V105, &sort_M_Reified_xForm); ASSERT(sink__V92->context, !strcmp(SYMBOL(sub__V105),  "FORM" ));
      Term sub__V106 = LINK(sink__V92->context, SUB(sub__V105, 0)); int sub__V106_count = sub__V105_count*LINK_COUNT(sub__V106); permitUnusedInt(sub__V106_count);
      /* sub__V106 = &#0-0 */
      Term sub__V107 = LINK(sink__V92->context, SUB(sub__V105, 1)); int sub__V107_count = sub__V105_count*LINK_COUNT(sub__V107); permitUnusedInt(sub__V107_count);
      /* sub__V107 = &#0-1 */
      NamedPropertyLink namedP__V108 = LINK_NamedPropertyLink(sink__V92->context, NAMED_PROPERTIES(term__V93));
      VariablePropertyLink varP__V109 = LINK_VariablePropertyLink(sink__V92->context, VARIABLE_PROPERTIES(term__V93));
      UNLINK(sink__V92->context, term__V93);
      ADD_PROPERTIES(sink__V92, LINK_NamedPropertyLink(sink__V92->context, namedP__V108), LINK_VariablePropertyLink(sink__V92->context, varP__V109));
      { START(sink__V92, _M_X_Form_s2);
        COPY(sink__V92, sub__V107);COPY(sink__V92, sub__V106);END(sink__V92, _M_X_Form_s2); }
      UNLINK_NamedPropertyLink(sink__V92->context, namedP__V108); UNLINK_VariablePropertyLink(sink__V92->context, varP__V109);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION X-Data$2. */
int conBindOffs_M_X_Data_s2[] = {0 , 0 , 0 , 0 , 0};
char *nameFun_M_X_Data_s2(Term term) { return  "X-Data$2" ; }
struct _ConstructionDescriptor descriptor_M_X_Data_s2 = {&sort_M_Reified_xVariable, 0, 4, sizeof(STRUCT_Con_M_X_Data_s2), conBindOffs_M_X_Data_s2, &nameFun_M_X_Data_s2, &step_M_X_Data_s2};

int step_M_X_Data_s2(Sink sink__V110, Term term__V111)
{
  int term__V111_count = LINK_COUNT(term__V111); permitUnusedInt(term__V111_count);
  do {
    /* Contraction rule SYMBOLS-X-Data-2. */
    ASSERT(sink__V110->context, !strcmp(SYMBOL(term__V111),  "X-Data$2" ));
    Term sub__V112 = SUB(term__V111, 0); permitUnusedTerm(sub__V112); int sub__V112_count = term__V111_count*LINK_COUNT(sub__V112); permitUnusedInt(sub__V112_count);
    CRSX_CHECK_SORT(sink__V110->context, sub__V112, &sort_M_Reified_xSort); /* sub__V112 = &#11 */
    Term sub__V113 = SUB(term__V111, 1); permitUnusedTerm(sub__V113); int sub__V113_count = term__V111_count*LINK_COUNT(sub__V113); permitUnusedInt(sub__V113_count);
    CRSX_CHECK_SORT(sink__V110->context, sub__V113, &sort_M_Reified_xSort); /* sub__V113 = &#12 */
    Term sub__V114 = LINK(sink__V110->context, SUB(term__V111, 2)); int sub__V114_count = term__V111_count*LINK_COUNT(sub__V114); permitUnusedInt(sub__V114_count);
    CRSX_CHECK_SORT(sink__V110->context, sub__V114, &sort_M_Reified_xSort); /* sub__V114 = &#13 */
    Term sub__V115 = LINK(sink__V110->context, SUB(term__V111, 3)); int sub__V115_count = term__V111_count*LINK_COUNT(sub__V115); permitUnusedInt(sub__V115_count);
    /* sub__V115 = &#2 */
    NamedPropertyLink namedP__V116 = LINK_NamedPropertyLink(sink__V110->context, NAMED_PROPERTIES(term__V111));
    VariablePropertyLink varP__V117 = LINK_VariablePropertyLink(sink__V110->context, VARIABLE_PROPERTIES(term__V111));
    UNLINK(sink__V110->context, term__V111);
    { START(sink__V110, _M_X_Data);
      COPY(sink__V110, sub__V114);COPY(sink__V110, sub__V115);END(sink__V110, _M_X_Data); }
    UNLINK_NamedPropertyLink(sink__V110->context, namedP__V116); UNLINK_VariablePropertyLink(sink__V110->context, varP__V117);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Data$1. */
int conBindOffs_M_X_Data_s1[] = {0 , 0 , 0 , 0};
char *nameFun_M_X_Data_s1(Term term) { return  "X-Data$1" ; }
struct _ConstructionDescriptor descriptor_M_X_Data_s1 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_X_Data_s1), conBindOffs_M_X_Data_s1, &nameFun_M_X_Data_s1, &step_M_X_Data_s1};

int step_M_X_Data_s1(Sink sink__V118, Term term__V119)
{
  int term__V119_count = LINK_COUNT(term__V119); permitUnusedInt(term__V119_count);
  do {
    /* Contraction rule SYMBOLS-X-Data-1. */
    ASSERT(sink__V118->context, !strcmp(SYMBOL(term__V119),  "X-Data$1" ));
    Term sub__V120 = SUB(term__V119, 0); permitUnusedTerm(sub__V120); int sub__V120_count = term__V119_count*LINK_COUNT(sub__V120); permitUnusedInt(sub__V120_count);
    /* sub__V120 = &#11 */
    Term sub__V121 = SUB(term__V119, 1); permitUnusedTerm(sub__V121); int sub__V121_count = term__V119_count*LINK_COUNT(sub__V121); permitUnusedInt(sub__V121_count);
    /* sub__V121 = &#12 */
    Term sub__V122 = LINK(sink__V118->context, SUB(term__V119, 2)); int sub__V122_count = term__V119_count*LINK_COUNT(sub__V122); permitUnusedInt(sub__V122_count);
    /* sub__V122 = &#2 */
    NamedPropertyLink namedP__V123 = LINK_NamedPropertyLink(sink__V118->context, NAMED_PROPERTIES(term__V119));
    VariablePropertyLink varP__V124 = LINK_VariablePropertyLink(sink__V118->context, VARIABLE_PROPERTIES(term__V119));
    UNLINK(sink__V118->context, term__V119);
    { START(sink__V118, _M__sTextCons);
      { START(sink__V118, _M__sTextEmbed);
        { START(sink__V118, _M_AsText);
          { START(sink__V118, _M_MapText_s1);
            COPY(sink__V118, sub__V122);{ Variable x__V125 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V118->context,"x__V125");
              Variable binds__V126[1] = {x__V125}; BINDS(sink__V118, 1, binds__V126);
              { START(sink__V118, _M_X_Form);
                USE(sink__V118, x__V125); END(sink__V118, _M_X_Form); }
               }
            END(sink__V118, _M_MapText_s1); }
          END(sink__V118, _M_AsText); }
        END(sink__V118, _M__sTextEmbed); }
      { START(sink__V118, _M__sTextNil);
        END(sink__V118, _M__sTextNil); }
      END(sink__V118, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V118->context, namedP__V123); UNLINK_VariablePropertyLink(sink__V118->context, varP__V124);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Form$5. */
int conBindOffs_M_X_Form_s5[] = {0};
char *nameFun_M_X_Form_s5(Term term) { return  "X-Form$5" ; }
struct _ConstructionDescriptor descriptor_M_X_Form_s5 = {&sort_M_Reified_xVariable, 0, 0, sizeof(STRUCT_Con_M_X_Form_s5), conBindOffs_M_X_Form_s5, &nameFun_M_X_Form_s5, &step_M_X_Form_s5};

int step_M_X_Form_s5(Sink sink__V127, Term term__V128)
{
  int term__V128_count = LINK_COUNT(term__V128); permitUnusedInt(term__V128_count);
  do {
    /* Contraction rule SYMBOLS-X-Form-2. */
    ASSERT(sink__V127->context, !strcmp(SYMBOL(term__V128),  "X-Form$5" ));
    NamedPropertyLink namedP__V129 = LINK_NamedPropertyLink(sink__V127->context, NAMED_PROPERTIES(term__V128));
    VariablePropertyLink varP__V130 = LINK_VariablePropertyLink(sink__V127->context, VARIABLE_PROPERTIES(term__V128));
    UNLINK(sink__V127->context, term__V128);
    { START(sink__V127, _M__sTextNil); END(sink__V127, _M__sTextNil); }
    UNLINK_NamedPropertyLink(sink__V127->context, namedP__V129); UNLINK_VariablePropertyLink(sink__V127->context, varP__V130);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Form$6. */
int conBindOffs_M_X_Form_s6[] = {0 , 0 , 0 , 0};
char *nameFun_M_X_Form_s6(Term term) { return  "X-Form$6" ; }
struct _ConstructionDescriptor descriptor_M_X_Form_s6 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_X_Form_s6), conBindOffs_M_X_Form_s6, &nameFun_M_X_Form_s6, &step_M_X_Form_s6};

int step_M_X_Form_s6(Sink sink__V131, Term term__V132)
{
  int term__V132_count = LINK_COUNT(term__V132); permitUnusedInt(term__V132_count);
  do {
    /* Contraction rule SYMBOLS-X-Form-1. */
    ASSERT(sink__V131->context, !strcmp(SYMBOL(term__V132),  "X-Form$6" ));
    Term sub__V133 = SUB(term__V132, 0); permitUnusedTerm(sub__V133); int sub__V133_count = term__V132_count*LINK_COUNT(sub__V133); permitUnusedInt(sub__V133_count);
    CRSX_CHECK_SORT(sink__V131->context, sub__V133, &sort_M_Reified_xSort); /* sub__V133 = &#11 */
    Term sub__V134 = SUB(term__V132, 1); permitUnusedTerm(sub__V134); int sub__V134_count = term__V132_count*LINK_COUNT(sub__V134); permitUnusedInt(sub__V134_count);
    CRSX_CHECK_SORT(sink__V131->context, sub__V134, &sort_M_Reified_xSort); /* sub__V134 = &#12 */
    Term sub__V135 = LINK(sink__V131->context, SUB(term__V132, 2)); int sub__V135_count = term__V132_count*LINK_COUNT(sub__V135); permitUnusedInt(sub__V135_count);
    CRSX_CHECK_SORT(sink__V131->context, sub__V135, &sort_M_Reified_xForm); /* sub__V135 = &#13 */
    NamedPropertyLink namedP__V136 = LINK_NamedPropertyLink(sink__V131->context, NAMED_PROPERTIES(term__V132));
    VariablePropertyLink varP__V137 = LINK_VariablePropertyLink(sink__V131->context, VARIABLE_PROPERTIES(term__V132));
    UNLINK(sink__V131->context, term__V132);
    { START(sink__V131, _M_X_Form);
      COPY(sink__V131, sub__V135);END(sink__V131, _M_X_Form); }
    UNLINK_NamedPropertyLink(sink__V131->context, namedP__V136); UNLINK_VariablePropertyLink(sink__V131->context, varP__V137);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Form$3. */
int conBindOffs_M_X_Form_s3[] = {0 , 0 , 0 , 0};
char *nameFun_M_X_Form_s3(Term term) { return  "X-Form$3" ; }
struct _ConstructionDescriptor descriptor_M_X_Form_s3 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_X_Form_s3), conBindOffs_M_X_Form_s3, &nameFun_M_X_Form_s3, &step_M_X_Form_s3};

int step_M_X_Form_s3(Sink sink__V138, Term term__V139)
{
  int term__V139_count = LINK_COUNT(term__V139); permitUnusedInt(term__V139_count);
  do {
    /* Contraction rule SYMBOLS-X-Form-4. */
    ASSERT(sink__V138->context, !strcmp(SYMBOL(term__V139),  "X-Form$3" ));
    Term sub__V140 = SUB(term__V139, 0); permitUnusedTerm(sub__V140); int sub__V140_count = term__V139_count*LINK_COUNT(sub__V140); permitUnusedInt(sub__V140_count);
    /* sub__V140 = &#121 */
    Term sub__V141 = SUB(term__V139, 1); permitUnusedTerm(sub__V141); int sub__V141_count = term__V139_count*LINK_COUNT(sub__V141); permitUnusedInt(sub__V141_count);
    /* sub__V141 = &#122 */
    Term sub__V142 = LINK(sink__V138->context, SUB(term__V139, 2)); int sub__V142_count = term__V139_count*LINK_COUNT(sub__V142); permitUnusedInt(sub__V142_count);
    UNLINK_SUB(sink__V138->context, term__V139,  2); NORMALIZE(sink__V138->context, sub__V142); SUB(term__V139,  2) = LINK(sink__V138->context, sub__V142);
    /* sub__V142 = &#11 */
    NamedPropertyLink namedP__V143 = LINK_NamedPropertyLink(sink__V138->context, NAMED_PROPERTIES(term__V139));
    VariablePropertyLink varP__V144 = LINK_VariablePropertyLink(sink__V138->context, VARIABLE_PROPERTIES(term__V139));
    UNLINK(sink__V138->context, term__V139);
    { START(sink__V138, _M__sTextCons);
      { START(sink__V138, _M__sTextBreak);
        LITERAL(sink__V138,  "\n" ); END(sink__V138, _M__sTextBreak); }
      { START(sink__V138, _M__sTextCons);
        { START(sink__V138, _M__sTextChars);
          LITERAL(sink__V138,  "{" ); END(sink__V138, _M__sTextChars); }
        { START(sink__V138, _M__sTextCons);
          { START(sink__V138, _M__sTextEmbed);
            { START(sink__V138, _M_AsText);
              { START(sink__V138, _M_STRING);
                COPY(sink__V138, LINK(sink__V138->context, sub__V142));END(sink__V138, _M_STRING); }
              END(sink__V138, _M_AsText); }
            END(sink__V138, _M__sTextEmbed); }
          { START(sink__V138, _M__sTextCons);
            { START(sink__V138, _M__sTextChars);
              LITERAL(sink__V138,  ", &" ); END(sink__V138, _M__sTextChars); }
            { START(sink__V138, _M__sTextCons);
              { START(sink__V138, _M__sTextEmbed);
                { START(sink__V138, _M_AsText);
                  { START(sink__V138, _M_Descriptor);
                    COPY(sink__V138, sub__V142);END(sink__V138, _M_Descriptor); }
                  END(sink__V138, _M_AsText); }
                END(sink__V138, _M__sTextEmbed); }
              { START(sink__V138, _M__sTextCons);
                { START(sink__V138, _M__sTextChars);
                  LITERAL(sink__V138,  "}," ); END(sink__V138, _M__sTextChars); }
                { START(sink__V138, _M__sTextNil);
                  END(sink__V138, _M__sTextNil); }
                END(sink__V138, _M__sTextCons); }
              END(sink__V138, _M__sTextCons); }
            END(sink__V138, _M__sTextCons); }
          END(sink__V138, _M__sTextCons); }
        END(sink__V138, _M__sTextCons); }
      END(sink__V138, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V138->context, namedP__V143); UNLINK_VariablePropertyLink(sink__V138->context, varP__V144);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Form$4. */
int conBindOffs_M_X_Form_s4[] = {0 , 0};
char *nameFun_M_X_Form_s4(Term term) { return  "X-Form$4" ; }
struct _ConstructionDescriptor descriptor_M_X_Form_s4 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_X_Form_s4), conBindOffs_M_X_Form_s4, &nameFun_M_X_Form_s4, &step_M_X_Form_s4};

int step_M_X_Form_s4(Sink sink__V145, Term term__V146)
{
  int term__V146_count = LINK_COUNT(term__V146); permitUnusedInt(term__V146_count);
  do {
    /* Contraction rule SYMBOLS-X-Form-3. */
    ASSERT(sink__V145->context, !strcmp(SYMBOL(term__V146),  "X-Form$4" ));
    Term sub__V147 = LINK(sink__V145->context, SUB(term__V146, 0)); int sub__V147_count = term__V146_count*LINK_COUNT(sub__V147); permitUnusedInt(sub__V147_count);
    UNLINK_SUB(sink__V145->context, term__V146,  0); NORMALIZE(sink__V145->context, sub__V147); SUB(term__V146,  0) = LINK(sink__V145->context, sub__V147);
    /* sub__V147 = &#11 */
    NamedPropertyLink namedP__V148 = LINK_NamedPropertyLink(sink__V145->context, NAMED_PROPERTIES(term__V146));
    VariablePropertyLink varP__V149 = LINK_VariablePropertyLink(sink__V145->context, VARIABLE_PROPERTIES(term__V146));
    UNLINK(sink__V145->context, term__V146);
    { START(sink__V145, _M__sTextCons);
      { START(sink__V145, _M__sTextBreak);
        LITERAL(sink__V145,  "\n" ); END(sink__V145, _M__sTextBreak); }
      { START(sink__V145, _M__sTextCons);
        { START(sink__V145, _M__sTextChars);
          LITERAL(sink__V145,  "{" ); END(sink__V145, _M__sTextChars); }
        { START(sink__V145, _M__sTextCons);
          { START(sink__V145, _M__sTextEmbed);
            { START(sink__V145, _M_AsText);
              { START(sink__V145, _M_STRING);
                COPY(sink__V145, LINK(sink__V145->context, sub__V147));END(sink__V145, _M_STRING); }
              END(sink__V145, _M_AsText); }
            END(sink__V145, _M__sTextEmbed); }
          { START(sink__V145, _M__sTextCons);
            { START(sink__V145, _M__sTextChars);
              LITERAL(sink__V145,  ", &" ); END(sink__V145, _M__sTextChars); }
            { START(sink__V145, _M__sTextCons);
              { START(sink__V145, _M__sTextEmbed);
                { START(sink__V145, _M_AsText);
                  { START(sink__V145, _M_Descriptor);
                    COPY(sink__V145, sub__V147);END(sink__V145, _M_Descriptor); }
                  END(sink__V145, _M_AsText); }
                END(sink__V145, _M__sTextEmbed); }
              { START(sink__V145, _M__sTextCons);
                { START(sink__V145, _M__sTextChars);
                  LITERAL(sink__V145,  "}," ); END(sink__V145, _M__sTextChars); }
                { START(sink__V145, _M__sTextNil);
                  END(sink__V145, _M__sTextNil); }
                END(sink__V145, _M__sTextCons); }
              END(sink__V145, _M__sTextCons); }
            END(sink__V145, _M__sTextCons); }
          END(sink__V145, _M__sTextCons); }
        END(sink__V145, _M__sTextCons); }
      END(sink__V145, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V145->context, namedP__V148); UNLINK_VariablePropertyLink(sink__V145->context, varP__V149);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Form$2. */
int conBindOffs_M_X_Form_s2[] = {0 , 0 , 0};
char *nameFun_M_X_Form_s2(Term term) { return  "X-Form$2" ; }
struct _ConstructionDescriptor descriptor_M_X_Form_s2 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_X_Form_s2), conBindOffs_M_X_Form_s2, &nameFun_M_X_Form_s2, &step_M_X_Form_s2};

int step_M_X_Form_s2(Sink sink__V150, Term term__V151)
{
  int term__V151_count = LINK_COUNT(term__V151); permitUnusedInt(term__V151_count);
  Term sub__V152 = FORCE(sink__V150->context, SUB(term__V151, 0));
  EnumOf_M__sList choice__V153 = (IS_VARIABLE_USE(sub__V152) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V152));
  switch (choice__V153)
  {
    case Data_M__sNil: { /* Function SYMBOLS-X-Form-3$X-Form$2$$Nil case $Nil */
      ASSERT(sink__V150->context, !strcmp(SYMBOL(term__V151),  "X-Form$2" ));
      Term sub__V154 = SUB(term__V151, 0); permitUnusedTerm(sub__V154); int sub__V154_count = term__V151_count*LINK_COUNT(sub__V154); permitUnusedInt(sub__V154_count);
      ASSERT(sink__V150->context, !strcmp(SYMBOL(sub__V154),  "$Nil" ));
      Term sub__V155 = LINK(sink__V150->context, SUB(term__V151, 1)); int sub__V155_count = term__V151_count*LINK_COUNT(sub__V155); permitUnusedInt(sub__V155_count);
      /* sub__V155 = &#0 */
      NamedPropertyLink namedP__V156 = LINK_NamedPropertyLink(sink__V150->context, NAMED_PROPERTIES(term__V151));
      VariablePropertyLink varP__V157 = LINK_VariablePropertyLink(sink__V150->context, VARIABLE_PROPERTIES(term__V151));
      UNLINK(sink__V150->context, term__V151);
      ADD_PROPERTIES(sink__V150, LINK_NamedPropertyLink(sink__V150->context, namedP__V156), LINK_VariablePropertyLink(sink__V150->context, varP__V157));
      { START(sink__V150, _M_X_Form_s4);
        COPY(sink__V150, sub__V155);END(sink__V150, _M_X_Form_s4); }
      UNLINK_NamedPropertyLink(sink__V150->context, namedP__V156); UNLINK_VariablePropertyLink(sink__V150->context, varP__V157);
      
      return 1;
    break; } case Data_M__sCons: { /* Function SYMBOLS-X-Form-4$X-Form$2$$Cons case $Cons */
      ASSERT(sink__V150->context, !strcmp(SYMBOL(term__V151),  "X-Form$2" ));
      Term sub__V158 = SUB(term__V151, 0); permitUnusedTerm(sub__V158); int sub__V158_count = term__V151_count*LINK_COUNT(sub__V158); permitUnusedInt(sub__V158_count);
      ASSERT(sink__V150->context, !strcmp(SYMBOL(sub__V158),  "$Cons" ));
      Term sub__V159 = LINK(sink__V150->context, SUB(sub__V158, 0)); int sub__V159_count = sub__V158_count*LINK_COUNT(sub__V159); permitUnusedInt(sub__V159_count);
      /* sub__V159 = &#0-0 */
      Term sub__V160 = LINK(sink__V150->context, SUB(sub__V158, 1)); int sub__V160_count = sub__V158_count*LINK_COUNT(sub__V160); permitUnusedInt(sub__V160_count);
      /* sub__V160 = &#0-1 */
      Term sub__V161 = LINK(sink__V150->context, SUB(term__V151, 1)); int sub__V161_count = term__V151_count*LINK_COUNT(sub__V161); permitUnusedInt(sub__V161_count);
      /* sub__V161 = &#2 */
      NamedPropertyLink namedP__V162 = LINK_NamedPropertyLink(sink__V150->context, NAMED_PROPERTIES(term__V151));
      VariablePropertyLink varP__V163 = LINK_VariablePropertyLink(sink__V150->context, VARIABLE_PROPERTIES(term__V151));
      UNLINK(sink__V150->context, term__V151);
      ADD_PROPERTIES(sink__V150, LINK_NamedPropertyLink(sink__V150->context, namedP__V162), LINK_VariablePropertyLink(sink__V150->context, varP__V163));
      { START(sink__V150, _M_X_Form_s3);
        COPY(sink__V150, sub__V159);COPY(sink__V150, sub__V160);COPY(sink__V150, sub__V161);END(sink__V150, _M_X_Form_s3); }
      UNLINK_NamedPropertyLink(sink__V150->context, namedP__V162); UNLINK_VariablePropertyLink(sink__V150->context, varP__V163);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION X-Declaration$3. */
int conBindOffs_M_X_Declaration_s3[] = {0 , 1};
char *nameFun_M_X_Declaration_s3(Term term) { return  "X-Declaration$3" ; }
struct _ConstructionDescriptor descriptor_M_X_Declaration_s3 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_X_Declaration_s3), conBindOffs_M_X_Declaration_s3, &nameFun_M_X_Declaration_s3, &step_M_X_Declaration_s3};

int step_M_X_Declaration_s3(Sink sink__V164, Term term__V165)
{
  int term__V165_count = LINK_COUNT(term__V165); permitUnusedInt(term__V165_count);
  do {
    /* Contraction rule SYMBOLS-Polymorphic. */
    ASSERT(sink__V164->context, !strcmp(SYMBOL(term__V165),  "X-Declaration$3" ));
    Variable x__V166 = BINDER(term__V165,0,0); if (term__V165_count <= 1) UNBIND(x__V166);
    Term sub__V167 = LINK(sink__V164->context, SUB(term__V165, 0)); int sub__V167_count = term__V165_count*LINK_COUNT(sub__V167); permitUnusedInt(sub__V167_count);
    CRSX_CHECK_SORT(sink__V164->context, sub__V167, &sort_M_Reified_xDeclaration); /* sub__V167 = &#11 */
    Variable y__V168 = x__V166; permitUnusedVariable(y__V168);
    NamedPropertyLink namedP__V169 = LINK_NamedPropertyLink(sink__V164->context, NAMED_PROPERTIES(term__V165));
    VariablePropertyLink varP__V170 = LINK_VariablePropertyLink(sink__V164->context, VARIABLE_PROPERTIES(term__V165));
    UNLINK(sink__V164->context, term__V165);
    { START(sink__V164, _M_X_Declaration);
      COPY(sink__V164, sub__V167); /* REUSED SUBSTITUTION */ END(sink__V164, _M_X_Declaration); }
    UNLINK_NamedPropertyLink(sink__V164->context, namedP__V169); UNLINK_VariablePropertyLink(sink__V164->context, varP__V170);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Declaration$1. */
int conBindOffs_M_X_Declaration_s1[] = {0 , 0 , 0};
char *nameFun_M_X_Declaration_s1(Term term) { return  "X-Declaration$1" ; }
struct _ConstructionDescriptor descriptor_M_X_Declaration_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_X_Declaration_s1), conBindOffs_M_X_Declaration_s1, &nameFun_M_X_Declaration_s1, &step_M_X_Declaration_s1};

int step_M_X_Declaration_s1(Sink sink__V171, Term term__V172)
{
  int term__V172_count = LINK_COUNT(term__V172); permitUnusedInt(term__V172_count);
  do {
    /* Contraction rule SYMBOLS-Data. */
    ASSERT(sink__V171->context, !strcmp(SYMBOL(term__V172),  "X-Declaration$1" ));
    Term sub__V173 = LINK(sink__V171->context, SUB(term__V172, 0)); int sub__V173_count = term__V172_count*LINK_COUNT(sub__V173); permitUnusedInt(sub__V173_count);
    CRSX_CHECK_SORT(sink__V171->context, sub__V173, &sort_M_Reified_xSort); /* sub__V173 = &#11 */
    Term sub__V174 = LINK(sink__V171->context, SUB(term__V172, 1)); int sub__V174_count = term__V172_count*LINK_COUNT(sub__V174); permitUnusedInt(sub__V174_count);
    /* sub__V174 = &#12 */
    NamedPropertyLink namedP__V175 = LINK_NamedPropertyLink(sink__V171->context, NAMED_PROPERTIES(term__V172));
    VariablePropertyLink varP__V176 = LINK_VariablePropertyLink(sink__V171->context, VARIABLE_PROPERTIES(term__V172));
    UNLINK(sink__V171->context, term__V172);
    { START(sink__V171, _M_X_Data);
      COPY(sink__V171, sub__V173);COPY(sink__V171, sub__V174);END(sink__V171, _M_X_Data); }
    UNLINK_NamedPropertyLink(sink__V171->context, namedP__V175); UNLINK_VariablePropertyLink(sink__V171->context, varP__V176);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Declaration$2. */
int conBindOffs_M_X_Declaration_s2[] = {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0};
char *nameFun_M_X_Declaration_s2(Term term) { return  "X-Declaration$2" ; }
struct _ConstructionDescriptor descriptor_M_X_Declaration_s2 = {&sort_M_Reified_xVariable, 0, 7, sizeof(STRUCT_Con_M_X_Declaration_s2), conBindOffs_M_X_Declaration_s2, &nameFun_M_X_Declaration_s2, &step_M_X_Declaration_s2};

int step_M_X_Declaration_s2(Sink sink__V177, Term term__V178)
{
  int term__V178_count = LINK_COUNT(term__V178); permitUnusedInt(term__V178_count);
  do {
    /* Contraction rule SYMBOLS-Function. */
    ASSERT(sink__V177->context, !strcmp(SYMBOL(term__V178),  "X-Declaration$2" ));
    Term sub__V179 = LINK(sink__V177->context, SUB(term__V178, 0)); int sub__V179_count = term__V178_count*LINK_COUNT(sub__V179); permitUnusedInt(sub__V179_count);
    /* sub__V179 = &#11 */
    Term sub__V180 = LINK(sink__V177->context, SUB(term__V178, 1)); int sub__V180_count = term__V178_count*LINK_COUNT(sub__V180); permitUnusedInt(sub__V180_count);
    /* sub__V180 = &#12 */
    Term sub__V181 = LINK(sink__V177->context, SUB(term__V178, 2)); int sub__V181_count = term__V178_count*LINK_COUNT(sub__V181); permitUnusedInt(sub__V181_count);
    /* sub__V181 = &#13 */
    Term sub__V182 = LINK(sink__V177->context, SUB(term__V178, 3)); int sub__V182_count = term__V178_count*LINK_COUNT(sub__V182); permitUnusedInt(sub__V182_count);
    /* sub__V182 = &#14 */
    Term sub__V183 = LINK(sink__V177->context, SUB(term__V178, 4)); int sub__V183_count = term__V178_count*LINK_COUNT(sub__V183); permitUnusedInt(sub__V183_count);
    /* sub__V183 = &#15 */
    Term sub__V184 = LINK(sink__V177->context, SUB(term__V178, 5)); int sub__V184_count = term__V178_count*LINK_COUNT(sub__V184); permitUnusedInt(sub__V184_count);
    CRSX_CHECK_SORT(sink__V177->context, sub__V184, &sort_M_Reified_xSort); /* sub__V184 = &#16 */
    Term sub__V185 = LINK(sink__V177->context, SUB(term__V178, 6)); int sub__V185_count = term__V178_count*LINK_COUNT(sub__V185); permitUnusedInt(sub__V185_count);
    /* sub__V185 = &#17 */
    NamedPropertyLink namedP__V186 = LINK_NamedPropertyLink(sink__V177->context, NAMED_PROPERTIES(term__V178));
    VariablePropertyLink varP__V187 = LINK_VariablePropertyLink(sink__V177->context, VARIABLE_PROPERTIES(term__V178));
    UNLINK(sink__V177->context, term__V178);
    { START(sink__V177, _M_X_Function);
      COPY(sink__V177, sub__V179);COPY(sink__V177, sub__V180);COPY(sink__V177, sub__V181);COPY(sink__V177, sub__V182);COPY(sink__V177, sub__V183);COPY(sink__V177, sub__V184);COPY(sink__V177, sub__V185);END(sink__V177, _M_X_Function); }
    UNLINK_NamedPropertyLink(sink__V177->context, namedP__V186); UNLINK_VariablePropertyLink(sink__V177->context, varP__V187);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION ComputeSymbols2. */
int conBindOffs_M_ComputeSymbols2[] = {0 , 0 , 0 , 0};
char *nameFun_M_ComputeSymbols2(Term term) { return  "ComputeSymbols2" ; }
struct _ConstructionDescriptor descriptor_M_ComputeSymbols2 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_ComputeSymbols2), conBindOffs_M_ComputeSymbols2, &nameFun_M_ComputeSymbols2, &step_M_ComputeSymbols2};

int step_M_ComputeSymbols2(Sink sink__V188, Term term__V189)
{
  int term__V189_count = LINK_COUNT(term__V189); permitUnusedInt(term__V189_count);
  do {
    /* Contraction rule SYMBOLS-ComputeSymbols2-1. */
    ASSERT(sink__V188->context, !strcmp(SYMBOL(term__V189),  "ComputeSymbols2" ));
    Term sub__V190 = SUB(term__V189, 0); permitUnusedTerm(sub__V190); int sub__V190_count = term__V189_count*LINK_COUNT(sub__V190); permitUnusedInt(sub__V190_count);
    /* sub__V190 = &#1 */
    Term sub__V191 = LINK(sink__V188->context, SUB(term__V189, 1)); int sub__V191_count = term__V189_count*LINK_COUNT(sub__V191); permitUnusedInt(sub__V191_count);
    /* sub__V191 = &#2 */
    Term sub__V192 = SUB(term__V189, 2); permitUnusedTerm(sub__V192); int sub__V192_count = term__V189_count*LINK_COUNT(sub__V192); permitUnusedInt(sub__V192_count);
    /* sub__V192 = &#3 */
    NamedPropertyLink namedP__V193 = LINK_NamedPropertyLink(sink__V188->context, NAMED_PROPERTIES(term__V189));
    VariablePropertyLink varP__V194 = LINK_VariablePropertyLink(sink__V188->context, VARIABLE_PROPERTIES(term__V189));
    UNLINK(sink__V188->context, term__V189);
    { START(sink__V188, _M__sTextCons);
      { START(sink__V188, _M__sTextEmbed);
        { START(sink__V188, _M_AsText);
          { START(sink__V188, _M_X_Declarations);
            COPY(sink__V188, sub__V191);END(sink__V188, _M_X_Declarations); }
          END(sink__V188, _M_AsText); }
        END(sink__V188, _M__sTextEmbed); }
      { START(sink__V188, _M__sTextCons);
        { START(sink__V188, _M__sTextBreak);
          LITERAL(sink__V188,  "\n" ); END(sink__V188, _M__sTextBreak); }
        { START(sink__V188, _M__sTextNil);
          END(sink__V188, _M__sTextNil); }
        END(sink__V188, _M__sTextCons); }
      END(sink__V188, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V188->context, namedP__V193); UNLINK_VariablePropertyLink(sink__V188->context, varP__V194);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Declarations$1. */
int conBindOffs_M_X_Declarations_s1[] = {0 , 0 , 0};
char *nameFun_M_X_Declarations_s1(Term term) { return  "X-Declarations$1" ; }
struct _ConstructionDescriptor descriptor_M_X_Declarations_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_X_Declarations_s1), conBindOffs_M_X_Declarations_s1, &nameFun_M_X_Declarations_s1, &step_M_X_Declarations_s1};

int step_M_X_Declarations_s1(Sink sink__V195, Term term__V196)
{
  int term__V196_count = LINK_COUNT(term__V196); permitUnusedInt(term__V196_count);
  do {
    /* Contraction rule SYMBOLS-X-Declarations-1. */
    ASSERT(sink__V195->context, !strcmp(SYMBOL(term__V196),  "X-Declarations$1" ));
    Term sub__V197 = LINK(sink__V195->context, SUB(term__V196, 0)); int sub__V197_count = term__V196_count*LINK_COUNT(sub__V197); permitUnusedInt(sub__V197_count);
    /* sub__V197 = &#11 */
    Term sub__V198 = LINK(sink__V195->context, SUB(term__V196, 1)); int sub__V198_count = term__V196_count*LINK_COUNT(sub__V198); permitUnusedInt(sub__V198_count);
    /* sub__V198 = &#12 */
    NamedPropertyLink namedP__V199 = LINK_NamedPropertyLink(sink__V195->context, NAMED_PROPERTIES(term__V196));
    VariablePropertyLink varP__V200 = LINK_VariablePropertyLink(sink__V195->context, VARIABLE_PROPERTIES(term__V196));
    UNLINK(sink__V195->context, term__V196);
    { START(sink__V195, _M__sTextCons);
      { START(sink__V195, _M__sTextEmbed);
        { START(sink__V195, _M_AsText);
          { START(sink__V195, _M_X_Declaration);
            COPY(sink__V195, sub__V197);END(sink__V195, _M_X_Declaration); }
          END(sink__V195, _M_AsText); }
        END(sink__V195, _M__sTextEmbed); }
      { START(sink__V195, _M__sTextCons);
        { START(sink__V195, _M__sTextEmbed);
          { START(sink__V195, _M_AsText);
            { START(sink__V195, _M_X_Declarations);
              COPY(sink__V195, sub__V198);END(sink__V195, _M_X_Declarations); }
            END(sink__V195, _M_AsText); }
          END(sink__V195, _M__sTextEmbed); }
        { START(sink__V195, _M__sTextNil);
          END(sink__V195, _M__sTextNil); }
        END(sink__V195, _M__sTextCons); }
      END(sink__V195, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V195->context, namedP__V199); UNLINK_VariablePropertyLink(sink__V195->context, varP__V200);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Declarations$2. */
int conBindOffs_M_X_Declarations_s2[] = {0};
char *nameFun_M_X_Declarations_s2(Term term) { return  "X-Declarations$2" ; }
struct _ConstructionDescriptor descriptor_M_X_Declarations_s2 = {&sort_M_Reified_xVariable, 0, 0, sizeof(STRUCT_Con_M_X_Declarations_s2), conBindOffs_M_X_Declarations_s2, &nameFun_M_X_Declarations_s2, &step_M_X_Declarations_s2};

int step_M_X_Declarations_s2(Sink sink__V201, Term term__V202)
{
  int term__V202_count = LINK_COUNT(term__V202); permitUnusedInt(term__V202_count);
  do {
    /* Contraction rule SYMBOLS-X-Declarations-2. */
    ASSERT(sink__V201->context, !strcmp(SYMBOL(term__V202),  "X-Declarations$2" ));
    NamedPropertyLink namedP__V203 = LINK_NamedPropertyLink(sink__V201->context, NAMED_PROPERTIES(term__V202));
    VariablePropertyLink varP__V204 = LINK_VariablePropertyLink(sink__V201->context, VARIABLE_PROPERTIES(term__V202));
    UNLINK(sink__V201->context, term__V202);
    { START(sink__V201, _M__sTextNil); END(sink__V201, _M__sTextNil); }
    UNLINK_NamedPropertyLink(sink__V201->context, namedP__V203); UNLINK_VariablePropertyLink(sink__V201->context, varP__V204);
    return 1;
  } while (0);
  return 0;
}

#ifdef __cplusplus
}
#endif
/* END OF C RULES FOR CRSX CRSXC MODULE SYMBOLS. */
