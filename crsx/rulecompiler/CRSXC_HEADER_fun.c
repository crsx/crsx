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
      UNLINK(sink__V1->context, term__V2);
      ADD_PROPERTIES(sink__V1, LINK_NamedPropertyLink(sink__V1->context, namedP__V8), LINK_VariablePropertyLink(sink__V1->context, varP__V9));
      { START(sink__V1, _M_ComputeHeader_s1);
        COPY(sink__V1, sub__V6);COPY(sink__V1, sub__V7);END(sink__V1, _M_ComputeHeader_s1); }
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

int step_M_H_Data(Sink sink__V10, Term term__V11)
{
  int term__V11_count = LINK_COUNT(term__V11); permitUnusedInt(term__V11_count);
  Term sub__V12 = FORCE(sink__V10->context, SUB(term__V11, 0));
  EnumOf_M_Reified_xSort choice__V13 = (IS_VARIABLE_USE(sub__V12) ? VarOf_M_Reified_xSort : (EnumOf_M_Reified_xSort) TAG(sub__V12));
  switch (choice__V13)
  {
    case Data_M_SORT: { /* Function HEADER-H-Data-1$H-Data$SORT case SORT */
      ASSERT(sink__V10->context, !strcmp(SYMBOL(term__V11),  "H-Data" ));
      Term sub__V14 = SUB(term__V11, 0); permitUnusedTerm(sub__V14); int sub__V14_count = term__V11_count*LINK_COUNT(sub__V14); permitUnusedInt(sub__V14_count);
      CRSX_CHECK_SORT(sink__V10->context, sub__V14, &sort_M_Reified_xSort); ASSERT(sink__V10->context, !strcmp(SYMBOL(sub__V14),  "SORT" ));
      Term sub__V15 = LINK(sink__V10->context, SUB(sub__V14, 0)); int sub__V15_count = sub__V14_count*LINK_COUNT(sub__V15); permitUnusedInt(sub__V15_count);
      /* sub__V15 = &#0-0 */
      Term sub__V16 = LINK(sink__V10->context, SUB(sub__V14, 1)); int sub__V16_count = sub__V14_count*LINK_COUNT(sub__V16); permitUnusedInt(sub__V16_count);
      /* sub__V16 = &#0-1 */
      Term sub__V17 = LINK(sink__V10->context, SUB(term__V11, 1)); int sub__V17_count = term__V11_count*LINK_COUNT(sub__V17); permitUnusedInt(sub__V17_count);
      /* sub__V17 = &#2 */
      NamedPropertyLink namedP__V18 = LINK_NamedPropertyLink(sink__V10->context, NAMED_PROPERTIES(term__V11));
      VariablePropertyLink varP__V19 = LINK_VariablePropertyLink(sink__V10->context, VARIABLE_PROPERTIES(term__V11));
      UNLINK(sink__V10->context, term__V11);
      ADD_PROPERTIES(sink__V10, LINK_NamedPropertyLink(sink__V10->context, namedP__V18), LINK_VariablePropertyLink(sink__V10->context, varP__V19));
      { START(sink__V10, _M_H_Data_s1);
        COPY(sink__V10, sub__V15);COPY(sink__V10, sub__V16);COPY(sink__V10, sub__V17);END(sink__V10, _M_H_Data_s1); }
      UNLINK_NamedPropertyLink(sink__V10->context, namedP__V18); UNLINK_VariablePropertyLink(sink__V10->context, varP__V19);
      
      return 1;
    break; } case Data_M_SORT_PROPERTY: { /* Function HEADER-H-Data-2$H-Data$SORT-PROPERTY case SORT-PROPERTY */
      ASSERT(sink__V10->context, !strcmp(SYMBOL(term__V11),  "H-Data" ));
      Term sub__V20 = SUB(term__V11, 0); permitUnusedTerm(sub__V20); int sub__V20_count = term__V11_count*LINK_COUNT(sub__V20); permitUnusedInt(sub__V20_count);
      CRSX_CHECK_SORT(sink__V10->context, sub__V20, &sort_M_Reified_xSort); ASSERT(sink__V10->context, !strcmp(SYMBOL(sub__V20),  "SORT-PROPERTY" ));
      Term sub__V21 = LINK(sink__V10->context, SUB(sub__V20, 0)); int sub__V21_count = sub__V20_count*LINK_COUNT(sub__V21); permitUnusedInt(sub__V21_count);
      CRSX_CHECK_SORT(sink__V10->context, sub__V21, &sort_M_Reified_xSort); /* sub__V21 = &#0-0 */
      Term sub__V22 = LINK(sink__V10->context, SUB(sub__V20, 1)); int sub__V22_count = sub__V20_count*LINK_COUNT(sub__V22); permitUnusedInt(sub__V22_count);
      CRSX_CHECK_SORT(sink__V10->context, sub__V22, &sort_M_Reified_xSort); /* sub__V22 = &#0-1 */
      Term sub__V23 = LINK(sink__V10->context, SUB(sub__V20, 2)); int sub__V23_count = sub__V20_count*LINK_COUNT(sub__V23); permitUnusedInt(sub__V23_count);
      CRSX_CHECK_SORT(sink__V10->context, sub__V23, &sort_M_Reified_xSort); /* sub__V23 = &#0-2 */
      Term sub__V24 = LINK(sink__V10->context, SUB(term__V11, 1)); int sub__V24_count = term__V11_count*LINK_COUNT(sub__V24); permitUnusedInt(sub__V24_count);
      /* sub__V24 = &#3 */
      NamedPropertyLink namedP__V25 = LINK_NamedPropertyLink(sink__V10->context, NAMED_PROPERTIES(term__V11));
      VariablePropertyLink varP__V26 = LINK_VariablePropertyLink(sink__V10->context, VARIABLE_PROPERTIES(term__V11));
      UNLINK(sink__V10->context, term__V11);
      ADD_PROPERTIES(sink__V10, LINK_NamedPropertyLink(sink__V10->context, namedP__V25), LINK_VariablePropertyLink(sink__V10->context, varP__V26));
      { START(sink__V10, _M_H_Data_s2);
        COPY(sink__V10, sub__V21);COPY(sink__V10, sub__V22);COPY(sink__V10, sub__V23);COPY(sink__V10, sub__V24);END(sink__V10, _M_H_Data_s2); }
      UNLINK_NamedPropertyLink(sink__V10->context, namedP__V25); UNLINK_VariablePropertyLink(sink__V10->context, varP__V26);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION H-Declaration. */
int conBindOffs_M_H_Declaration[] = {0 , 0};
char *nameFun_M_H_Declaration(Term term) { return  "H-Declaration" ; }
struct _ConstructionDescriptor descriptor_M_H_Declaration = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_H_Declaration), conBindOffs_M_H_Declaration, &nameFun_M_H_Declaration, &step_M_H_Declaration};

int step_M_H_Declaration(Sink sink__V27, Term term__V28)
{
  int term__V28_count = LINK_COUNT(term__V28); permitUnusedInt(term__V28_count);
  Term sub__V29 = FORCE(sink__V27->context, SUB(term__V28, 0));
  EnumOf_M_Reified_xDeclaration choice__V30 = (IS_VARIABLE_USE(sub__V29) ? VarOf_M_Reified_xDeclaration : (EnumOf_M_Reified_xDeclaration) TAG(sub__V29));
  switch (choice__V30)
  {
    case Data_M_DATA: { /* Function HEADER-Data$H-Declaration$DATA case DATA */
      ASSERT(sink__V27->context, !strcmp(SYMBOL(term__V28),  "H-Declaration" ));
      Term sub__V31 = SUB(term__V28, 0); permitUnusedTerm(sub__V31); int sub__V31_count = term__V28_count*LINK_COUNT(sub__V31); permitUnusedInt(sub__V31_count);
      CRSX_CHECK_SORT(sink__V27->context, sub__V31, &sort_M_Reified_xDeclaration); ASSERT(sink__V27->context, !strcmp(SYMBOL(sub__V31),  "DATA" ));
      Term sub__V32 = LINK(sink__V27->context, SUB(sub__V31, 0)); int sub__V32_count = sub__V31_count*LINK_COUNT(sub__V32); permitUnusedInt(sub__V32_count);
      CRSX_CHECK_SORT(sink__V27->context, sub__V32, &sort_M_Reified_xSort); /* sub__V32 = &#0-0 */
      Term sub__V33 = LINK(sink__V27->context, SUB(sub__V31, 1)); int sub__V33_count = sub__V31_count*LINK_COUNT(sub__V33); permitUnusedInt(sub__V33_count);
      /* sub__V33 = &#0-1 */
      NamedPropertyLink namedP__V34 = LINK_NamedPropertyLink(sink__V27->context, NAMED_PROPERTIES(term__V28));
      VariablePropertyLink varP__V35 = LINK_VariablePropertyLink(sink__V27->context, VARIABLE_PROPERTIES(term__V28));
      UNLINK(sink__V27->context, term__V28);
      ADD_PROPERTIES(sink__V27, LINK_NamedPropertyLink(sink__V27->context, namedP__V34), LINK_VariablePropertyLink(sink__V27->context, varP__V35));
      { START(sink__V27, _M_H_Declaration_s1);
        COPY(sink__V27, sub__V32);COPY(sink__V27, sub__V33);END(sink__V27, _M_H_Declaration_s1); }
      UNLINK_NamedPropertyLink(sink__V27->context, namedP__V34); UNLINK_VariablePropertyLink(sink__V27->context, varP__V35);
      
      return 1;
    break; } case Data_M_FUNCTION: { /* Function HEADER-Function$H-Declaration$FUNCTION case FUNCTION */
      ASSERT(sink__V27->context, !strcmp(SYMBOL(term__V28),  "H-Declaration" ));
      Term sub__V36 = SUB(term__V28, 0); permitUnusedTerm(sub__V36); int sub__V36_count = term__V28_count*LINK_COUNT(sub__V36); permitUnusedInt(sub__V36_count);
      CRSX_CHECK_SORT(sink__V27->context, sub__V36, &sort_M_Reified_xDeclaration); ASSERT(sink__V27->context, !strcmp(SYMBOL(sub__V36),  "FUNCTION" ));
      Term sub__V37 = LINK(sink__V27->context, SUB(sub__V36, 0)); int sub__V37_count = sub__V36_count*LINK_COUNT(sub__V37); permitUnusedInt(sub__V37_count);
      /* sub__V37 = &#0-0 */
      Term sub__V38 = LINK(sink__V27->context, SUB(sub__V36, 1)); int sub__V38_count = sub__V36_count*LINK_COUNT(sub__V38); permitUnusedInt(sub__V38_count);
      /* sub__V38 = &#0-1 */
      Term sub__V39 = LINK(sink__V27->context, SUB(sub__V36, 2)); int sub__V39_count = sub__V36_count*LINK_COUNT(sub__V39); permitUnusedInt(sub__V39_count);
      /* sub__V39 = &#0-2 */
      Term sub__V40 = LINK(sink__V27->context, SUB(sub__V36, 3)); int sub__V40_count = sub__V36_count*LINK_COUNT(sub__V40); permitUnusedInt(sub__V40_count);
      /* sub__V40 = &#0-3 */
      Term sub__V41 = LINK(sink__V27->context, SUB(sub__V36, 4)); int sub__V41_count = sub__V36_count*LINK_COUNT(sub__V41); permitUnusedInt(sub__V41_count);
      /* sub__V41 = &#0-4 */
      Term sub__V42 = LINK(sink__V27->context, SUB(sub__V36, 5)); int sub__V42_count = sub__V36_count*LINK_COUNT(sub__V42); permitUnusedInt(sub__V42_count);
      CRSX_CHECK_SORT(sink__V27->context, sub__V42, &sort_M_Reified_xSort); /* sub__V42 = &#0-5 */
      Term sub__V43 = LINK(sink__V27->context, SUB(sub__V36, 6)); int sub__V43_count = sub__V36_count*LINK_COUNT(sub__V43); permitUnusedInt(sub__V43_count);
      /* sub__V43 = &#0-6 */
      NamedPropertyLink namedP__V44 = LINK_NamedPropertyLink(sink__V27->context, NAMED_PROPERTIES(term__V28));
      VariablePropertyLink varP__V45 = LINK_VariablePropertyLink(sink__V27->context, VARIABLE_PROPERTIES(term__V28));
      UNLINK(sink__V27->context, term__V28);
      ADD_PROPERTIES(sink__V27, LINK_NamedPropertyLink(sink__V27->context, namedP__V44), LINK_VariablePropertyLink(sink__V27->context, varP__V45));
      { START(sink__V27, _M_H_Declaration_s2);
        COPY(sink__V27, sub__V37);COPY(sink__V27, sub__V38);COPY(sink__V27, sub__V39);COPY(sink__V27, sub__V40);COPY(sink__V27, sub__V41);COPY(sink__V27, sub__V42);COPY(sink__V27, sub__V43);END(sink__V27, _M_H_Declaration_s2); }
      UNLINK_NamedPropertyLink(sink__V27->context, namedP__V44); UNLINK_VariablePropertyLink(sink__V27->context, varP__V45);
      
      return 1;
    break; } case Data_M_POLYMORPHIC: { /* Function HEADER-Polymorphic$H-Declaration$POLYMORPHIC case POLYMORPHIC */
      ASSERT(sink__V27->context, !strcmp(SYMBOL(term__V28),  "H-Declaration" ));
      Term sub__V46 = SUB(term__V28, 0); permitUnusedTerm(sub__V46); int sub__V46_count = term__V28_count*LINK_COUNT(sub__V46); permitUnusedInt(sub__V46_count);
      CRSX_CHECK_SORT(sink__V27->context, sub__V46, &sort_M_Reified_xDeclaration); ASSERT(sink__V27->context, !strcmp(SYMBOL(sub__V46),  "POLYMORPHIC" ));
      Variable y__V47 = BINDER(sub__V46,0,0); if (sub__V46_count <= 1) UNBIND(y__V47);
      Term sub__V48 = LINK(sink__V27->context, SUB(sub__V46, 0)); int sub__V48_count = sub__V46_count*LINK_COUNT(sub__V48); permitUnusedInt(sub__V48_count);
      CRSX_CHECK_SORT(sink__V27->context, sub__V48, &sort_M_Reified_xDeclaration); /* sub__V48 = &#0-0 */
      NamedPropertyLink namedP__V49 = LINK_NamedPropertyLink(sink__V27->context, NAMED_PROPERTIES(term__V28));
      VariablePropertyLink varP__V50 = LINK_VariablePropertyLink(sink__V27->context, VARIABLE_PROPERTIES(term__V28));
      UNLINK(sink__V27->context, term__V28);
      ADD_PROPERTIES(sink__V27, LINK_NamedPropertyLink(sink__V27->context, namedP__V49), LINK_VariablePropertyLink(sink__V27->context, varP__V50));
      { START(sink__V27, _M_H_Declaration_s3);
        { if (!IS_BOUND(y__V47)) { REBIND(y__V47);
            Variable binds__V51[1] = {y__V47}; BINDS(sink__V27, 1, binds__V51);
            COPY(sink__V27, sub__V48); /* REUSED SUBSTITUTION */  }
          else { Variable b__V52 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V27->context,"b__V52");
            Variable binds__V53[1] = {b__V52}; BINDS(sink__V27, 1, binds__V53);
            {
              Term arg__V54;
              { Sink buf__V55 = ALLOCA_BUFFER(sink__V27->context);
                USE(buf__V55, b__V52); arg__V54 = BUFFER_TERM(buf__V55); FREE_BUFFER(buf__V55); }
              Variable vars__V56[1] = {y__V47};
              Term args__V57[1] = {arg__V54};
              struct _SubstitutionFrame substitution__V58 = {NULL, 0, 1, vars__V56, args__V57, NULL};
              SUBSTITUTE(sink__V27, sub__V48, &substitution__V58); }
                }
           }
        END(sink__V27, _M_H_Declaration_s3); }
      UNLINK_NamedPropertyLink(sink__V27->context, namedP__V49); UNLINK_VariablePropertyLink(sink__V27->context, varP__V50);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION H-Declarations$1. */
int conBindOffs_M_H_Declarations_s1[] = {0 , 0 , 0};
char *nameFun_M_H_Declarations_s1(Term term) { return  "H-Declarations$1" ; }
struct _ConstructionDescriptor descriptor_M_H_Declarations_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_H_Declarations_s1), conBindOffs_M_H_Declarations_s1, &nameFun_M_H_Declarations_s1, &step_M_H_Declarations_s1};

int step_M_H_Declarations_s1(Sink sink__V59, Term term__V60)
{
  int term__V60_count = LINK_COUNT(term__V60); permitUnusedInt(term__V60_count);
  do {
    /* Contraction rule HEADER-H-Declarations-1. */
    ASSERT(sink__V59->context, !strcmp(SYMBOL(term__V60),  "H-Declarations$1" ));
    Term sub__V61 = LINK(sink__V59->context, SUB(term__V60, 0)); int sub__V61_count = term__V60_count*LINK_COUNT(sub__V61); permitUnusedInt(sub__V61_count);
    /* sub__V61 = &#11 */
    Term sub__V62 = LINK(sink__V59->context, SUB(term__V60, 1)); int sub__V62_count = term__V60_count*LINK_COUNT(sub__V62); permitUnusedInt(sub__V62_count);
    /* sub__V62 = &#12 */
    NamedPropertyLink namedP__V63 = LINK_NamedPropertyLink(sink__V59->context, NAMED_PROPERTIES(term__V60));
    VariablePropertyLink varP__V64 = LINK_VariablePropertyLink(sink__V59->context, VARIABLE_PROPERTIES(term__V60));
    UNLINK(sink__V59->context, term__V60);
    { START(sink__V59, _M__sTextCons);
      { START(sink__V59, _M__sTextEmbed);
        { START(sink__V59, _M_AsText);
          { START(sink__V59, _M_H_Declaration);
            COPY(sink__V59, sub__V61);END(sink__V59, _M_H_Declaration); }
          END(sink__V59, _M_AsText); }
        END(sink__V59, _M__sTextEmbed); }
      { START(sink__V59, _M__sTextCons);
        { START(sink__V59, _M__sTextEmbed);
          { START(sink__V59, _M_AsText);
            { START(sink__V59, _M_H_Declarations);
              COPY(sink__V59, sub__V62);END(sink__V59, _M_H_Declarations); }
            END(sink__V59, _M_AsText); }
          END(sink__V59, _M__sTextEmbed); }
        { START(sink__V59, _M__sTextNil);
          END(sink__V59, _M__sTextNil); }
        END(sink__V59, _M__sTextCons); }
      END(sink__V59, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V59->context, namedP__V63); UNLINK_VariablePropertyLink(sink__V59->context, varP__V64);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Declarations$2. */
int conBindOffs_M_H_Declarations_s2[] = {0};
char *nameFun_M_H_Declarations_s2(Term term) { return  "H-Declarations$2" ; }
struct _ConstructionDescriptor descriptor_M_H_Declarations_s2 = {&sort_M_Reified_xVariable, 0, 0, sizeof(STRUCT_Con_M_H_Declarations_s2), conBindOffs_M_H_Declarations_s2, &nameFun_M_H_Declarations_s2, &step_M_H_Declarations_s2};

int step_M_H_Declarations_s2(Sink sink__V65, Term term__V66)
{
  int term__V66_count = LINK_COUNT(term__V66); permitUnusedInt(term__V66_count);
  do {
    /* Contraction rule HEADER-H-Declarations-2. */
    ASSERT(sink__V65->context, !strcmp(SYMBOL(term__V66),  "H-Declarations$2" ));
    NamedPropertyLink namedP__V67 = LINK_NamedPropertyLink(sink__V65->context, NAMED_PROPERTIES(term__V66));
    VariablePropertyLink varP__V68 = LINK_VariablePropertyLink(sink__V65->context, VARIABLE_PROPERTIES(term__V66));
    UNLINK(sink__V65->context, term__V66);
    { START(sink__V65, _M__sTextNil); END(sink__V65, _M__sTextNil); } UNLINK_NamedPropertyLink(sink__V65->context, namedP__V67); UNLINK_VariablePropertyLink(sink__V65->context, varP__V68);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION ComputeHeader$1. */
int conBindOffs_M_ComputeHeader_s1[] = {0 , 0 , 0};
char *nameFun_M_ComputeHeader_s1(Term term) { return  "ComputeHeader$1" ; }
struct _ConstructionDescriptor descriptor_M_ComputeHeader_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_ComputeHeader_s1), conBindOffs_M_ComputeHeader_s1, &nameFun_M_ComputeHeader_s1, &step_M_ComputeHeader_s1};

int step_M_ComputeHeader_s1(Sink sink__V69, Term term__V70)
{
  int term__V70_count = LINK_COUNT(term__V70); permitUnusedInt(term__V70_count);
  do {
    /* Contraction rule HEADER-ComputeHeader-1. */
    ASSERT(sink__V69->context, !strcmp(SYMBOL(term__V70),  "ComputeHeader$1" ));
    Term sub__V71 = LINK(sink__V69->context, SUB(term__V70, 0)); int sub__V71_count = term__V70_count*LINK_COUNT(sub__V71); permitUnusedInt(sub__V71_count);
    /* sub__V71 = &#11 */
    Term sub__V72 = LINK(sink__V69->context, SUB(term__V70, 1)); int sub__V72_count = term__V70_count*LINK_COUNT(sub__V72); permitUnusedInt(sub__V72_count);
    /* sub__V72 = &#12 */
    NamedPropertyLink namedP__V73 = LINK_NamedPropertyLink(sink__V69->context, NAMED_PROPERTIES(term__V70));
    VariablePropertyLink varP__V74 = LINK_VariablePropertyLink(sink__V69->context, VARIABLE_PROPERTIES(term__V70));
    UNLINK(sink__V69->context, term__V70);
    { START(sink__V69, _M_ComputeHeader2);
      COPY(sink__V69, sub__V71);COPY(sink__V69, sub__V72);{ Term term__V75;
        { char *value__V76 = getenv( "MODULE" );
          if (value__V76) term__V75 = makeStringLiteral(sink__V69->context, value__V76);
          else {term__V75 = makeStringLiteral(sink__V69->context,  "" ); }
        }
        COPY(sink__V69, term__V75); /*CONSERVATIVE*/ }
      END(sink__V69, _M_ComputeHeader2); }
    UNLINK_NamedPropertyLink(sink__V69->context, namedP__V73); UNLINK_VariablePropertyLink(sink__V69->context, varP__V74);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Form$2. */
int conBindOffs_M_H_Form_s2[] = {0 , 0 , 0};
char *nameFun_M_H_Form_s2(Term term) { return  "H-Form$2" ; }
struct _ConstructionDescriptor descriptor_M_H_Form_s2 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_H_Form_s2), conBindOffs_M_H_Form_s2, &nameFun_M_H_Form_s2, &step_M_H_Form_s2};

int step_M_H_Form_s2(Sink sink__V77, Term term__V78)
{
  int term__V78_count = LINK_COUNT(term__V78); permitUnusedInt(term__V78_count);
  Term sub__V79 = FORCE(sink__V77->context, SUB(term__V78, 0));
  EnumOf_M__sList choice__V80 = (IS_VARIABLE_USE(sub__V79) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V79));
  switch (choice__V80)
  {
    case Data_M__sNil: { /* Function HEADER-H-Form-3$H-Form$2$$Nil case $Nil */
      ASSERT(sink__V77->context, !strcmp(SYMBOL(term__V78),  "H-Form$2" ));
      Term sub__V81 = SUB(term__V78, 0); permitUnusedTerm(sub__V81); int sub__V81_count = term__V78_count*LINK_COUNT(sub__V81); permitUnusedInt(sub__V81_count);
      ASSERT(sink__V77->context, !strcmp(SYMBOL(sub__V81),  "$Nil" ));
      Term sub__V82 = LINK(sink__V77->context, SUB(term__V78, 1)); int sub__V82_count = term__V78_count*LINK_COUNT(sub__V82); permitUnusedInt(sub__V82_count);
      /* sub__V82 = &#0 */
      NamedPropertyLink namedP__V83 = LINK_NamedPropertyLink(sink__V77->context, NAMED_PROPERTIES(term__V78));
      VariablePropertyLink varP__V84 = LINK_VariablePropertyLink(sink__V77->context, VARIABLE_PROPERTIES(term__V78));
      UNLINK(sink__V77->context, term__V78);
      ADD_PROPERTIES(sink__V77, LINK_NamedPropertyLink(sink__V77->context, namedP__V83), LINK_VariablePropertyLink(sink__V77->context, varP__V84));
      { START(sink__V77, _M_H_Form_s4);
        COPY(sink__V77, sub__V82);END(sink__V77, _M_H_Form_s4); }
      UNLINK_NamedPropertyLink(sink__V77->context, namedP__V83); UNLINK_VariablePropertyLink(sink__V77->context, varP__V84);
      
      return 1;
    break; } case Data_M__sCons: { /* Function HEADER-H-Form-4$H-Form$2$$Cons case $Cons */
      ASSERT(sink__V77->context, !strcmp(SYMBOL(term__V78),  "H-Form$2" ));
      Term sub__V85 = SUB(term__V78, 0); permitUnusedTerm(sub__V85); int sub__V85_count = term__V78_count*LINK_COUNT(sub__V85); permitUnusedInt(sub__V85_count);
      ASSERT(sink__V77->context, !strcmp(SYMBOL(sub__V85),  "$Cons" ));
      Term sub__V86 = LINK(sink__V77->context, SUB(sub__V85, 0)); int sub__V86_count = sub__V85_count*LINK_COUNT(sub__V86); permitUnusedInt(sub__V86_count);
      /* sub__V86 = &#0-0 */
      Term sub__V87 = LINK(sink__V77->context, SUB(sub__V85, 1)); int sub__V87_count = sub__V85_count*LINK_COUNT(sub__V87); permitUnusedInt(sub__V87_count);
      /* sub__V87 = &#0-1 */
      Term sub__V88 = LINK(sink__V77->context, SUB(term__V78, 1)); int sub__V88_count = term__V78_count*LINK_COUNT(sub__V88); permitUnusedInt(sub__V88_count);
      /* sub__V88 = &#2 */
      NamedPropertyLink namedP__V89 = LINK_NamedPropertyLink(sink__V77->context, NAMED_PROPERTIES(term__V78));
      VariablePropertyLink varP__V90 = LINK_VariablePropertyLink(sink__V77->context, VARIABLE_PROPERTIES(term__V78));
      UNLINK(sink__V77->context, term__V78);
      ADD_PROPERTIES(sink__V77, LINK_NamedPropertyLink(sink__V77->context, namedP__V89), LINK_VariablePropertyLink(sink__V77->context, varP__V90));
      { START(sink__V77, _M_H_Form_s3);
        COPY(sink__V77, sub__V86);COPY(sink__V77, sub__V87);COPY(sink__V77, sub__V88);END(sink__V77, _M_H_Form_s3); }
      UNLINK_NamedPropertyLink(sink__V77->context, namedP__V89); UNLINK_VariablePropertyLink(sink__V77->context, varP__V90);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION H-Form$3. */
int conBindOffs_M_H_Form_s3[] = {0 , 0 , 0 , 0};
char *nameFun_M_H_Form_s3(Term term) { return  "H-Form$3" ; }
struct _ConstructionDescriptor descriptor_M_H_Form_s3 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_H_Form_s3), conBindOffs_M_H_Form_s3, &nameFun_M_H_Form_s3, &step_M_H_Form_s3};

int step_M_H_Form_s3(Sink sink__V91, Term term__V92)
{
  int term__V92_count = LINK_COUNT(term__V92); permitUnusedInt(term__V92_count);
  do {
    /* Contraction rule HEADER-H-Form-4. */
    ASSERT(sink__V91->context, !strcmp(SYMBOL(term__V92),  "H-Form$3" ));
    Term sub__V93 = LINK(sink__V91->context, SUB(term__V92, 0)); int sub__V93_count = term__V92_count*LINK_COUNT(sub__V93); permitUnusedInt(sub__V93_count);
    /* sub__V93 = &#121 */
    Term sub__V94 = LINK(sink__V91->context, SUB(term__V92, 1)); int sub__V94_count = term__V92_count*LINK_COUNT(sub__V94); permitUnusedInt(sub__V94_count);
    /* sub__V94 = &#122 */
    Term sub__V95 = LINK(sink__V91->context, SUB(term__V92, 2)); int sub__V95_count = term__V92_count*LINK_COUNT(sub__V95); permitUnusedInt(sub__V95_count);
    /* sub__V95 = &#11 */
    NamedPropertyLink namedP__V96 = LINK_NamedPropertyLink(sink__V91->context, NAMED_PROPERTIES(term__V92));
    VariablePropertyLink varP__V97 = LINK_VariablePropertyLink(sink__V91->context, VARIABLE_PROPERTIES(term__V92));
    UNLINK(sink__V91->context, term__V92);
    { START(sink__V91, _M__sTextCons);
      { START(sink__V91, _M__sTextChars);
        LITERAL(sink__V91,  "#define STRUCT" ); END(sink__V91, _M__sTextChars); }
      { START(sink__V91, _M__sTextCons);
        { START(sink__V91, _M__sTextEmbed);
          { START(sink__V91, _M_AsText);
            { START(sink__V91, _M_Struct);
              COPY(sink__V91, LINK(sink__V91->context, sub__V95));END(sink__V91, _M_Struct); }
            END(sink__V91, _M_AsText); }
          END(sink__V91, _M__sTextEmbed); }
        { START(sink__V91, _M__sTextCons);
          { START(sink__V91, _M__sTextChars);
            LITERAL(sink__V91,  " struct " ); END(sink__V91, _M__sTextChars); }
          { START(sink__V91, _M__sTextCons);
            { START(sink__V91, _M__sTextEmbed);
              { START(sink__V91, _M_AsText);
                { START(sink__V91, _M_Struct);
                  COPY(sink__V91, LINK(sink__V91->context, sub__V95));END(sink__V91, _M_Struct); }
                END(sink__V91, _M_AsText); }
              END(sink__V91, _M__sTextEmbed); }
            { START(sink__V91, _M__sTextCons);
              { START(sink__V91, _M__sTextBreak);
                LITERAL(sink__V91,  "\n" ); END(sink__V91, _M__sTextBreak); }
              { START(sink__V91, _M__sTextCons);
                { START(sink__V91, _M__sTextChars);
                  LITERAL(sink__V91,  "struct " ); END(sink__V91, _M__sTextChars); }
                { START(sink__V91, _M__sTextCons);
                  { START(sink__V91, _M__sTextEmbed);
                    { START(sink__V91, _M_AsText);
                      { START(sink__V91, _M_Struct);
                        COPY(sink__V91, LINK(sink__V91->context, sub__V95));END(sink__V91, _M_Struct); }
                      END(sink__V91, _M_AsText); }
                    END(sink__V91, _M__sTextEmbed); }
                  { START(sink__V91, _M__sTextCons);
                    { START(sink__V91, _M__sTextChars);
                      LITERAL(sink__V91,  " {struct _Construction construction; Term sub[" );
                      END(sink__V91, _M__sTextChars); }
                    { START(sink__V91, _M__sTextCons);
                      { START(sink__V91, _M__sTextEmbed);
                        { START(sink__V91, _M_AsText);
                          { START(sink__V91, _M_INTEGER);
                            { START(sink__V91, _M_Length);
                              COPY(sink__V91, LINK(sink__V91->context, sub__V94));LITERAL(sink__V91,  "1" ); END(sink__V91, _M_Length); }
                            END(sink__V91, _M_INTEGER); }
                          END(sink__V91, _M_AsText); }
                        END(sink__V91, _M__sTextEmbed); }
                      { START(sink__V91, _M__sTextCons);
                        { START(sink__V91, _M__sTextChars);
                          LITERAL(sink__V91,  "]; Variable binder[" ); END(sink__V91, _M__sTextChars); }
                        { START(sink__V91, _M__sTextCons);
                          { START(sink__V91, _M__sTextEmbed);
                            { START(sink__V91, _M_AsText);
                              { START(sink__V91, _M_INTEGER);
                                { START(sink__V91, _M_FormArguments__binder__count);
                                  { START(sink__V91, _M__sCons);
                                    COPY(sink__V91, sub__V93);COPY(sink__V91, sub__V94);END(sink__V91, _M__sCons); }
                                  LITERAL(sink__V91,  "0" ); END(sink__V91, _M_FormArguments__binder__count); }
                                END(sink__V91, _M_INTEGER); }
                              END(sink__V91, _M_AsText); }
                            END(sink__V91, _M__sTextEmbed); }
                          { START(sink__V91, _M__sTextCons);
                            { START(sink__V91, _M__sTextChars);
                              LITERAL(sink__V91,  "];};" ); END(sink__V91, _M__sTextChars); }
                            { START(sink__V91, _M__sTextCons);
                              { START(sink__V91, _M__sTextBreak);
                                LITERAL(sink__V91,  "\n" ); END(sink__V91, _M__sTextBreak); }
                              { START(sink__V91, _M__sTextCons);
                                { START(sink__V91, _M__sTextChars);
                                  LITERAL(sink__V91,  "extern struct _ConstructionDescriptor " );
                                  END(sink__V91, _M__sTextChars); }
                                { START(sink__V91, _M__sTextCons);
                                  { START(sink__V91, _M__sTextEmbed);
                                    { START(sink__V91, _M_AsText);
                                      { START(sink__V91, _M_Descriptor);
                                        COPY(sink__V91, sub__V95);END(sink__V91, _M_Descriptor); }
                                      END(sink__V91, _M_AsText); }
                                    END(sink__V91, _M__sTextEmbed); }
                                  { START(sink__V91, _M__sTextCons);
                                    { START(sink__V91, _M__sTextChars);
                                      LITERAL(sink__V91,  ";" ); END(sink__V91, _M__sTextChars); }
                                    { START(sink__V91, _M__sTextCons);
                                      { START(sink__V91, _M__sTextBreak);
                                        LITERAL(sink__V91,  "\n" ); END(sink__V91, _M__sTextBreak); }
                                      { START(sink__V91, _M__sTextNil);
                                        END(sink__V91, _M__sTextNil); }
                                      END(sink__V91, _M__sTextCons); }
                                    END(sink__V91, _M__sTextCons); }
                                  END(sink__V91, _M__sTextCons); }
                                END(sink__V91, _M__sTextCons); }
                              END(sink__V91, _M__sTextCons); }
                            END(sink__V91, _M__sTextCons); }
                          END(sink__V91, _M__sTextCons); }
                        END(sink__V91, _M__sTextCons); }
                      END(sink__V91, _M__sTextCons); }
                    END(sink__V91, _M__sTextCons); }
                  END(sink__V91, _M__sTextCons); }
                END(sink__V91, _M__sTextCons); }
              END(sink__V91, _M__sTextCons); }
            END(sink__V91, _M__sTextCons); }
          END(sink__V91, _M__sTextCons); }
        END(sink__V91, _M__sTextCons); }
      END(sink__V91, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V91->context, namedP__V96); UNLINK_VariablePropertyLink(sink__V91->context, varP__V97);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Form$4. */
int conBindOffs_M_H_Form_s4[] = {0 , 0};
char *nameFun_M_H_Form_s4(Term term) { return  "H-Form$4" ; }
struct _ConstructionDescriptor descriptor_M_H_Form_s4 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_H_Form_s4), conBindOffs_M_H_Form_s4, &nameFun_M_H_Form_s4, &step_M_H_Form_s4};

int step_M_H_Form_s4(Sink sink__V98, Term term__V99)
{
  int term__V99_count = LINK_COUNT(term__V99); permitUnusedInt(term__V99_count);
  do {
    /* Contraction rule HEADER-H-Form-3. */
    ASSERT(sink__V98->context, !strcmp(SYMBOL(term__V99),  "H-Form$4" ));
    Term sub__V100 = LINK(sink__V98->context, SUB(term__V99, 0)); int sub__V100_count = term__V99_count*LINK_COUNT(sub__V100); permitUnusedInt(sub__V100_count);
    /* sub__V100 = &#11 */
    NamedPropertyLink namedP__V101 = LINK_NamedPropertyLink(sink__V98->context, NAMED_PROPERTIES(term__V99));
    VariablePropertyLink varP__V102 = LINK_VariablePropertyLink(sink__V98->context, VARIABLE_PROPERTIES(term__V99));
    UNLINK(sink__V98->context, term__V99);
    { START(sink__V98, _M__sTextCons);
      { START(sink__V98, _M__sTextChars);
        LITERAL(sink__V98,  "#define STRUCT" ); END(sink__V98, _M__sTextChars); }
      { START(sink__V98, _M__sTextCons);
        { START(sink__V98, _M__sTextEmbed);
          { START(sink__V98, _M_AsText);
            { START(sink__V98, _M_Struct);
              COPY(sink__V98, LINK(sink__V98->context, sub__V100));END(sink__V98, _M_Struct); }
            END(sink__V98, _M_AsText); }
          END(sink__V98, _M__sTextEmbed); }
        { START(sink__V98, _M__sTextCons);
          { START(sink__V98, _M__sTextChars);
            LITERAL(sink__V98,  " struct _ConstantConstruction" ); END(sink__V98, _M__sTextChars); }
          { START(sink__V98, _M__sTextCons);
            { START(sink__V98, _M__sTextBreak);
              LITERAL(sink__V98,  "\n" ); END(sink__V98, _M__sTextBreak); }
            { START(sink__V98, _M__sTextCons);
              { START(sink__V98, _M__sTextChars);
                LITERAL(sink__V98,  "extern struct _ConstructionDescriptor " );
                END(sink__V98, _M__sTextChars); }
              { START(sink__V98, _M__sTextCons);
                { START(sink__V98, _M__sTextEmbed);
                  { START(sink__V98, _M_AsText);
                    { START(sink__V98, _M_Descriptor);
                      COPY(sink__V98, sub__V100);END(sink__V98, _M_Descriptor); }
                    END(sink__V98, _M_AsText); }
                  END(sink__V98, _M__sTextEmbed); }
                { START(sink__V98, _M__sTextCons);
                  { START(sink__V98, _M__sTextChars);
                    LITERAL(sink__V98,  ";" ); END(sink__V98, _M__sTextChars); }
                  { START(sink__V98, _M__sTextCons);
                    { START(sink__V98, _M__sTextBreak);
                      LITERAL(sink__V98,  "\n" ); END(sink__V98, _M__sTextBreak); }
                    { START(sink__V98, _M__sTextNil);
                      END(sink__V98, _M__sTextNil); }
                    END(sink__V98, _M__sTextCons); }
                  END(sink__V98, _M__sTextCons); }
                END(sink__V98, _M__sTextCons); }
              END(sink__V98, _M__sTextCons); }
            END(sink__V98, _M__sTextCons); }
          END(sink__V98, _M__sTextCons); }
        END(sink__V98, _M__sTextCons); }
      END(sink__V98, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V98->context, namedP__V101); UNLINK_VariablePropertyLink(sink__V98->context, varP__V102);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Form$5. */
int conBindOffs_M_H_Form_s5[] = {0};
char *nameFun_M_H_Form_s5(Term term) { return  "H-Form$5" ; }
struct _ConstructionDescriptor descriptor_M_H_Form_s5 = {&sort_M_Reified_xVariable, 0, 0, sizeof(STRUCT_Con_M_H_Form_s5), conBindOffs_M_H_Form_s5, &nameFun_M_H_Form_s5, &step_M_H_Form_s5};

int step_M_H_Form_s5(Sink sink__V103, Term term__V104)
{
  int term__V104_count = LINK_COUNT(term__V104); permitUnusedInt(term__V104_count);
  do {
    /* Contraction rule HEADER-H-Form-2. */
    ASSERT(sink__V103->context, !strcmp(SYMBOL(term__V104),  "H-Form$5" ));
    NamedPropertyLink namedP__V105 = LINK_NamedPropertyLink(sink__V103->context, NAMED_PROPERTIES(term__V104));
    VariablePropertyLink varP__V106 = LINK_VariablePropertyLink(sink__V103->context, VARIABLE_PROPERTIES(term__V104));
    UNLINK(sink__V103->context, term__V104);
    { START(sink__V103, _M__sTextNil); END(sink__V103, _M__sTextNil); }
    UNLINK_NamedPropertyLink(sink__V103->context, namedP__V105); UNLINK_VariablePropertyLink(sink__V103->context, varP__V106);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Form$6. */
int conBindOffs_M_H_Form_s6[] = {0 , 0 , 0 , 0};
char *nameFun_M_H_Form_s6(Term term) { return  "H-Form$6" ; }
struct _ConstructionDescriptor descriptor_M_H_Form_s6 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_H_Form_s6), conBindOffs_M_H_Form_s6, &nameFun_M_H_Form_s6, &step_M_H_Form_s6};

int step_M_H_Form_s6(Sink sink__V107, Term term__V108)
{
  int term__V108_count = LINK_COUNT(term__V108); permitUnusedInt(term__V108_count);
  do {
    /* Contraction rule HEADER-H-Form-1. */
    ASSERT(sink__V107->context, !strcmp(SYMBOL(term__V108),  "H-Form$6" ));
    Term sub__V109 = SUB(term__V108, 0); permitUnusedTerm(sub__V109); int sub__V109_count = term__V108_count*LINK_COUNT(sub__V109); permitUnusedInt(sub__V109_count);
    CRSX_CHECK_SORT(sink__V107->context, sub__V109, &sort_M_Reified_xSort); /* sub__V109 = &#11 */
    Term sub__V110 = SUB(term__V108, 1); permitUnusedTerm(sub__V110); int sub__V110_count = term__V108_count*LINK_COUNT(sub__V110); permitUnusedInt(sub__V110_count);
    CRSX_CHECK_SORT(sink__V107->context, sub__V110, &sort_M_Reified_xSort); /* sub__V110 = &#12 */
    Term sub__V111 = LINK(sink__V107->context, SUB(term__V108, 2)); int sub__V111_count = term__V108_count*LINK_COUNT(sub__V111); permitUnusedInt(sub__V111_count);
    CRSX_CHECK_SORT(sink__V107->context, sub__V111, &sort_M_Reified_xForm); /* sub__V111 = &#13 */
    NamedPropertyLink namedP__V112 = LINK_NamedPropertyLink(sink__V107->context, NAMED_PROPERTIES(term__V108));
    VariablePropertyLink varP__V113 = LINK_VariablePropertyLink(sink__V107->context, VARIABLE_PROPERTIES(term__V108));
    UNLINK(sink__V107->context, term__V108);
    { START(sink__V107, _M_H_Form);
      COPY(sink__V107, sub__V111);END(sink__V107, _M_H_Form); }
    UNLINK_NamedPropertyLink(sink__V107->context, namedP__V112); UNLINK_VariablePropertyLink(sink__V107->context, varP__V113);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Declaration$1. */
int conBindOffs_M_H_Declaration_s1[] = {0 , 0 , 0};
char *nameFun_M_H_Declaration_s1(Term term) { return  "H-Declaration$1" ; }
struct _ConstructionDescriptor descriptor_M_H_Declaration_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_H_Declaration_s1), conBindOffs_M_H_Declaration_s1, &nameFun_M_H_Declaration_s1, &step_M_H_Declaration_s1};

int step_M_H_Declaration_s1(Sink sink__V114, Term term__V115)
{
  int term__V115_count = LINK_COUNT(term__V115); permitUnusedInt(term__V115_count);
  do {
    /* Contraction rule HEADER-Data. */
    ASSERT(sink__V114->context, !strcmp(SYMBOL(term__V115),  "H-Declaration$1" ));
    Term sub__V116 = LINK(sink__V114->context, SUB(term__V115, 0)); int sub__V116_count = term__V115_count*LINK_COUNT(sub__V116); permitUnusedInt(sub__V116_count);
    CRSX_CHECK_SORT(sink__V114->context, sub__V116, &sort_M_Reified_xSort); /* sub__V116 = &#11 */
    Term sub__V117 = LINK(sink__V114->context, SUB(term__V115, 1)); int sub__V117_count = term__V115_count*LINK_COUNT(sub__V117); permitUnusedInt(sub__V117_count);
    /* sub__V117 = &#12 */
    NamedPropertyLink namedP__V118 = LINK_NamedPropertyLink(sink__V114->context, NAMED_PROPERTIES(term__V115));
    VariablePropertyLink varP__V119 = LINK_VariablePropertyLink(sink__V114->context, VARIABLE_PROPERTIES(term__V115));
    UNLINK(sink__V114->context, term__V115);
    { START(sink__V114, _M_H_Data);
      COPY(sink__V114, sub__V116);COPY(sink__V114, sub__V117);END(sink__V114, _M_H_Data); }
    UNLINK_NamedPropertyLink(sink__V114->context, namedP__V118); UNLINK_VariablePropertyLink(sink__V114->context, varP__V119);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Declaration$2. */
int conBindOffs_M_H_Declaration_s2[] = {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0};
char *nameFun_M_H_Declaration_s2(Term term) { return  "H-Declaration$2" ; }
struct _ConstructionDescriptor descriptor_M_H_Declaration_s2 = {&sort_M_Reified_xVariable, 0, 7, sizeof(STRUCT_Con_M_H_Declaration_s2), conBindOffs_M_H_Declaration_s2, &nameFun_M_H_Declaration_s2, &step_M_H_Declaration_s2};

int step_M_H_Declaration_s2(Sink sink__V120, Term term__V121)
{
  int term__V121_count = LINK_COUNT(term__V121); permitUnusedInt(term__V121_count);
  do {
    /* Contraction rule HEADER-Function. */
    ASSERT(sink__V120->context, !strcmp(SYMBOL(term__V121),  "H-Declaration$2" ));
    Term sub__V122 = LINK(sink__V120->context, SUB(term__V121, 0)); int sub__V122_count = term__V121_count*LINK_COUNT(sub__V122); permitUnusedInt(sub__V122_count);
    /* sub__V122 = &#11 */
    Term sub__V123 = LINK(sink__V120->context, SUB(term__V121, 1)); int sub__V123_count = term__V121_count*LINK_COUNT(sub__V123); permitUnusedInt(sub__V123_count);
    /* sub__V123 = &#12 */
    Term sub__V124 = LINK(sink__V120->context, SUB(term__V121, 2)); int sub__V124_count = term__V121_count*LINK_COUNT(sub__V124); permitUnusedInt(sub__V124_count);
    /* sub__V124 = &#13 */
    Term sub__V125 = LINK(sink__V120->context, SUB(term__V121, 3)); int sub__V125_count = term__V121_count*LINK_COUNT(sub__V125); permitUnusedInt(sub__V125_count);
    /* sub__V125 = &#14 */
    Term sub__V126 = LINK(sink__V120->context, SUB(term__V121, 4)); int sub__V126_count = term__V121_count*LINK_COUNT(sub__V126); permitUnusedInt(sub__V126_count);
    /* sub__V126 = &#15 */
    Term sub__V127 = LINK(sink__V120->context, SUB(term__V121, 5)); int sub__V127_count = term__V121_count*LINK_COUNT(sub__V127); permitUnusedInt(sub__V127_count);
    CRSX_CHECK_SORT(sink__V120->context, sub__V127, &sort_M_Reified_xSort); /* sub__V127 = &#16 */
    Term sub__V128 = LINK(sink__V120->context, SUB(term__V121, 6)); int sub__V128_count = term__V121_count*LINK_COUNT(sub__V128); permitUnusedInt(sub__V128_count);
    /* sub__V128 = &#17 */
    NamedPropertyLink namedP__V129 = LINK_NamedPropertyLink(sink__V120->context, NAMED_PROPERTIES(term__V121));
    VariablePropertyLink varP__V130 = LINK_VariablePropertyLink(sink__V120->context, VARIABLE_PROPERTIES(term__V121));
    UNLINK(sink__V120->context, term__V121);
    { START(sink__V120, _M_H_Function);
      COPY(sink__V120, sub__V122);COPY(sink__V120, sub__V123);COPY(sink__V120, sub__V124);COPY(sink__V120, sub__V125);COPY(sink__V120, sub__V126);COPY(sink__V120, sub__V127);COPY(sink__V120, sub__V128);END(sink__V120, _M_H_Function); }
    UNLINK_NamedPropertyLink(sink__V120->context, namedP__V129); UNLINK_VariablePropertyLink(sink__V120->context, varP__V130);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Declaration$3. */
int conBindOffs_M_H_Declaration_s3[] = {0 , 1};
char *nameFun_M_H_Declaration_s3(Term term) { return  "H-Declaration$3" ; }
struct _ConstructionDescriptor descriptor_M_H_Declaration_s3 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_H_Declaration_s3), conBindOffs_M_H_Declaration_s3, &nameFun_M_H_Declaration_s3, &step_M_H_Declaration_s3};

int step_M_H_Declaration_s3(Sink sink__V131, Term term__V132)
{
  int term__V132_count = LINK_COUNT(term__V132); permitUnusedInt(term__V132_count);
  do {
    /* Contraction rule HEADER-Polymorphic. */
    ASSERT(sink__V131->context, !strcmp(SYMBOL(term__V132),  "H-Declaration$3" ));
    Variable x__V133 = BINDER(term__V132,0,0); if (term__V132_count <= 1) UNBIND(x__V133);
    Term sub__V134 = LINK(sink__V131->context, SUB(term__V132, 0)); int sub__V134_count = term__V132_count*LINK_COUNT(sub__V134); permitUnusedInt(sub__V134_count);
    CRSX_CHECK_SORT(sink__V131->context, sub__V134, &sort_M_Reified_xDeclaration); /* sub__V134 = &#11 */
    Variable y__V135 = x__V133; permitUnusedVariable(y__V135);
    NamedPropertyLink namedP__V136 = LINK_NamedPropertyLink(sink__V131->context, NAMED_PROPERTIES(term__V132));
    VariablePropertyLink varP__V137 = LINK_VariablePropertyLink(sink__V131->context, VARIABLE_PROPERTIES(term__V132));
    UNLINK(sink__V131->context, term__V132);
    { START(sink__V131, _M_H_Declaration);
      COPY(sink__V131, sub__V134); /* REUSED SUBSTITUTION */ END(sink__V131, _M_H_Declaration); }
    UNLINK_NamedPropertyLink(sink__V131->context, namedP__V136); UNLINK_VariablePropertyLink(sink__V131->context, varP__V137);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Data$1. */
int conBindOffs_M_H_Data_s1[] = {0 , 0 , 0 , 0};
char *nameFun_M_H_Data_s1(Term term) { return  "H-Data$1" ; }
struct _ConstructionDescriptor descriptor_M_H_Data_s1 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_H_Data_s1), conBindOffs_M_H_Data_s1, &nameFun_M_H_Data_s1, &step_M_H_Data_s1};

int step_M_H_Data_s1(Sink sink__V138, Term term__V139)
{
  int term__V139_count = LINK_COUNT(term__V139); permitUnusedInt(term__V139_count);
  do {
    /* Contraction rule HEADER-H-Data-1. */
    ASSERT(sink__V138->context, !strcmp(SYMBOL(term__V139),  "H-Data$1" ));
    Term sub__V140 = LINK(sink__V138->context, SUB(term__V139, 0)); int sub__V140_count = term__V139_count*LINK_COUNT(sub__V140); permitUnusedInt(sub__V140_count);
    /* sub__V140 = &#11 */
    Term sub__V141 = SUB(term__V139, 1); permitUnusedTerm(sub__V141); int sub__V141_count = term__V139_count*LINK_COUNT(sub__V141); permitUnusedInt(sub__V141_count);
    /* sub__V141 = &#12 */
    Term sub__V142 = LINK(sink__V138->context, SUB(term__V139, 2)); int sub__V142_count = term__V139_count*LINK_COUNT(sub__V142); permitUnusedInt(sub__V142_count);
    /* sub__V142 = &#2 */
    NamedPropertyLink namedP__V143 = LINK_NamedPropertyLink(sink__V138->context, NAMED_PROPERTIES(term__V139));
    VariablePropertyLink varP__V144 = LINK_VariablePropertyLink(sink__V138->context, VARIABLE_PROPERTIES(term__V139));
    UNLINK(sink__V138->context, term__V139);
    { START(sink__V138, _M__sTextCons);
      { START(sink__V138, _M__sTextBreak);
        LITERAL(sink__V138,  "\n" ); END(sink__V138, _M__sTextBreak); }
      { START(sink__V138, _M__sTextCons);
        { START(sink__V138, _M__sTextChars);
          LITERAL(sink__V138,  "/* DATA SORT " ); END(sink__V138, _M__sTextChars); }
        { START(sink__V138, _M__sTextCons);
          { START(sink__V138, _M__sTextEmbed);
            { START(sink__V138, _M_AsText);
              { START(sink__V138, _M_COMMENT_xTOKEN);
                COPY(sink__V138, LINK(sink__V138->context, sub__V140));END(sink__V138, _M_COMMENT_xTOKEN); }
              END(sink__V138, _M_AsText); }
            END(sink__V138, _M__sTextEmbed); }
          { START(sink__V138, _M__sTextCons);
            { START(sink__V138, _M__sTextChars);
              LITERAL(sink__V138,  " HEADER DECLARATIONS. */" ); END(sink__V138, _M__sTextChars); }
            { START(sink__V138, _M__sTextCons);
              { START(sink__V138, _M__sTextBreak);
                LITERAL(sink__V138,  "\n" ); END(sink__V138, _M__sTextBreak); }
              { START(sink__V138, _M__sTextCons);
                { START(sink__V138, _M__sTextChars);
                  LITERAL(sink__V138,  "typedef enum {" ); END(sink__V138, _M__sTextChars); }
                { START(sink__V138, _M__sTextCons);
                  { START(sink__V138, _M__sTextEmbed);
                    { START(sink__V138, _M_AsText);
                      { START(sink__V138, _M_EnumFun);
                        COPY(sink__V138, LINK(sink__V138->context, sub__V140));END(sink__V138, _M_EnumFun); }
                      END(sink__V138, _M_AsText); }
                    END(sink__V138, _M__sTextEmbed); }
                  { START(sink__V138, _M__sTextCons);
                    { START(sink__V138, _M__sTextChars);
                      LITERAL(sink__V138,  " = 0, " ); END(sink__V138, _M__sTextChars); }
                    { START(sink__V138, _M__sTextCons);
                      { START(sink__V138, _M__sTextEmbed);
                        { START(sink__V138, _M_AsText);
                          { START(sink__V138, _M_EnumVar);
                            COPY(sink__V138, LINK(sink__V138->context, sub__V140));END(sink__V138, _M_EnumVar); }
                          END(sink__V138, _M_AsText); }
                        END(sink__V138, _M__sTextEmbed); }
                      { START(sink__V138, _M__sTextCons);
                        { START(sink__V138, _M__sTextChars);
                          LITERAL(sink__V138,  " = 1" ); END(sink__V138, _M__sTextChars); }
                        { START(sink__V138, _M__sTextCons);
                          { START(sink__V138, _M__sTextEmbed);
                            { START(sink__V138, _M_AsText);
                              { START(sink__V138, _M_DelayMapText_s1);
                                { START(sink__V138, _M_Forms_Constructors);
                                  COPY(sink__V138, LINK(sink__V138->context, sub__V142));END(sink__V138, _M_Forms_Constructors); }
                                { Variable x__V145 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V138->context,"x__V145");
                                  Variable x__V146 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V138->context,"x__V146");
                                  Variable binds__V147[2] = {x__V145,x__V146}; BINDS(sink__V138, 2, binds__V147);
                                  { START(sink__V138, _M__sTextCons);
                                    { START(sink__V138, _M__sTextChars);
                                      LITERAL(sink__V138,  ", " ); END(sink__V138, _M__sTextChars); }
                                    { START(sink__V138, _M__sTextCons);
                                      { START(sink__V138, _M__sTextEmbed);
                                        { START(sink__V138, _M_AsText);
                                          { START(sink__V138, _M_DEnumTag);
                                            USE(sink__V138, x__V145); USE(sink__V138, x__V146); END(sink__V138, _M_DEnumTag); }
                                          END(sink__V138, _M_AsText); }
                                        END(sink__V138, _M__sTextEmbed); }
                                      { START(sink__V138, _M__sTextNil);
                                        END(sink__V138, _M__sTextNil); }
                                      END(sink__V138, _M__sTextCons); }
                                    END(sink__V138, _M__sTextCons); }
                                   }
                                END(sink__V138, _M_DelayMapText_s1); }
                              END(sink__V138, _M_AsText); }
                            END(sink__V138, _M__sTextEmbed); }
                          { START(sink__V138, _M__sTextCons);
                            { START(sink__V138, _M__sTextChars);
                              LITERAL(sink__V138,  "} " ); END(sink__V138, _M__sTextChars); }
                            { START(sink__V138, _M__sTextCons);
                              { START(sink__V138, _M__sTextEmbed);
                                { START(sink__V138, _M_AsText);
                                  { START(sink__V138, _M_Enum);
                                    COPY(sink__V138, LINK(sink__V138->context, sub__V140));END(sink__V138, _M_Enum); }
                                  END(sink__V138, _M_AsText); }
                                END(sink__V138, _M__sTextEmbed); }
                              { START(sink__V138, _M__sTextCons);
                                { START(sink__V138, _M__sTextChars);
                                  LITERAL(sink__V138,  ";" ); END(sink__V138, _M__sTextChars); }
                                { START(sink__V138, _M__sTextCons);
                                  { START(sink__V138, _M__sTextBreak);
                                    LITERAL(sink__V138,  "\n" ); END(sink__V138, _M__sTextBreak); }
                                  { START(sink__V138, _M__sTextCons);
                                    { START(sink__V138, _M__sTextEmbed);
                                      { START(sink__V138, _M_AsText);
                                        { START(sink__V138, _M_MapText_s1);
                                          COPY(sink__V138, sub__V142);{ Variable x__V148 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V138->context,"x__V148");
                                            Variable binds__V149[1] = {x__V148}; BINDS(sink__V138, 1, binds__V149);
                                            { START(sink__V138, _M_H_Form);
                                              USE(sink__V138, x__V148);
                                              END(sink__V138, _M_H_Form); }
                                             }
                                          END(sink__V138, _M_MapText_s1); }
                                        END(sink__V138, _M_AsText); }
                                      END(sink__V138, _M__sTextEmbed); }
                                    { START(sink__V138, _M__sTextCons);
                                      { START(sink__V138, _M__sTextChars);
                                        LITERAL(sink__V138,  "extern struct _SortDescriptor " );
                                        END(sink__V138, _M__sTextChars); }
                                      { START(sink__V138, _M__sTextCons);
                                        { START(sink__V138, _M__sTextEmbed);
                                          { START(sink__V138, _M_AsText);
                                            { START(sink__V138, _M_Sort);
                                              COPY(sink__V138, sub__V140);END(sink__V138, _M_Sort); }
                                            END(sink__V138, _M_AsText); }
                                          END(sink__V138, _M__sTextEmbed); }
                                        { START(sink__V138, _M__sTextCons);
                                          { START(sink__V138, _M__sTextChars);
                                            LITERAL(sink__V138,  ";" );
                                            END(sink__V138, _M__sTextChars); }
                                          { START(sink__V138, _M__sTextCons);
                                            { START(sink__V138, _M__sTextBreak);
                                              LITERAL(sink__V138,  "\n" );
                                              END(sink__V138, _M__sTextBreak); }
                                            { START(sink__V138, _M__sTextNil);
                                              END(sink__V138, _M__sTextNil); }
                                            END(sink__V138, _M__sTextCons); }
                                          END(sink__V138, _M__sTextCons); }
                                        END(sink__V138, _M__sTextCons); }
                                      END(sink__V138, _M__sTextCons); }
                                    END(sink__V138, _M__sTextCons); }
                                  END(sink__V138, _M__sTextCons); }
                                END(sink__V138, _M__sTextCons); }
                              END(sink__V138, _M__sTextCons); }
                            END(sink__V138, _M__sTextCons); }
                          END(sink__V138, _M__sTextCons); }
                        END(sink__V138, _M__sTextCons); }
                      END(sink__V138, _M__sTextCons); }
                    END(sink__V138, _M__sTextCons); }
                  END(sink__V138, _M__sTextCons); }
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

/* FUNCTION H-Data$2. */
int conBindOffs_M_H_Data_s2[] = {0 , 0 , 0 , 0 , 0};
char *nameFun_M_H_Data_s2(Term term) { return  "H-Data$2" ; }
struct _ConstructionDescriptor descriptor_M_H_Data_s2 = {&sort_M_Reified_xVariable, 0, 4, sizeof(STRUCT_Con_M_H_Data_s2), conBindOffs_M_H_Data_s2, &nameFun_M_H_Data_s2, &step_M_H_Data_s2};

int step_M_H_Data_s2(Sink sink__V150, Term term__V151)
{
  int term__V151_count = LINK_COUNT(term__V151); permitUnusedInt(term__V151_count);
  do {
    /* Contraction rule HEADER-H-Data-2. */
    ASSERT(sink__V150->context, !strcmp(SYMBOL(term__V151),  "H-Data$2" ));
    Term sub__V152 = SUB(term__V151, 0); permitUnusedTerm(sub__V152); int sub__V152_count = term__V151_count*LINK_COUNT(sub__V152); permitUnusedInt(sub__V152_count);
    CRSX_CHECK_SORT(sink__V150->context, sub__V152, &sort_M_Reified_xSort); /* sub__V152 = &#11 */
    Term sub__V153 = SUB(term__V151, 1); permitUnusedTerm(sub__V153); int sub__V153_count = term__V151_count*LINK_COUNT(sub__V153); permitUnusedInt(sub__V153_count);
    CRSX_CHECK_SORT(sink__V150->context, sub__V153, &sort_M_Reified_xSort); /* sub__V153 = &#12 */
    Term sub__V154 = LINK(sink__V150->context, SUB(term__V151, 2)); int sub__V154_count = term__V151_count*LINK_COUNT(sub__V154); permitUnusedInt(sub__V154_count);
    CRSX_CHECK_SORT(sink__V150->context, sub__V154, &sort_M_Reified_xSort); /* sub__V154 = &#13 */
    Term sub__V155 = LINK(sink__V150->context, SUB(term__V151, 3)); int sub__V155_count = term__V151_count*LINK_COUNT(sub__V155); permitUnusedInt(sub__V155_count);
    /* sub__V155 = &#2 */
    NamedPropertyLink namedP__V156 = LINK_NamedPropertyLink(sink__V150->context, NAMED_PROPERTIES(term__V151));
    VariablePropertyLink varP__V157 = LINK_VariablePropertyLink(sink__V150->context, VARIABLE_PROPERTIES(term__V151));
    UNLINK(sink__V150->context, term__V151);
    { START(sink__V150, _M_H_Data);
      COPY(sink__V150, sub__V154);COPY(sink__V150, sub__V155);END(sink__V150, _M_H_Data); }
    UNLINK_NamedPropertyLink(sink__V150->context, namedP__V156); UNLINK_VariablePropertyLink(sink__V150->context, varP__V157);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Declarations. */
int conBindOffs_M_H_Declarations[] = {0 , 0};
char *nameFun_M_H_Declarations(Term term) { return  "H-Declarations" ; }
struct _ConstructionDescriptor descriptor_M_H_Declarations = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_H_Declarations), conBindOffs_M_H_Declarations, &nameFun_M_H_Declarations, &step_M_H_Declarations};

int step_M_H_Declarations(Sink sink__V158, Term term__V159)
{
  int term__V159_count = LINK_COUNT(term__V159); permitUnusedInt(term__V159_count);
  Term sub__V160 = FORCE(sink__V158->context, SUB(term__V159, 0));
  EnumOf_M__sList choice__V161 = (IS_VARIABLE_USE(sub__V160) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V160));
  switch (choice__V161)
  {
    case Data_M__sCons: { /* Function HEADER-H-Declarations-1$H-Declarations$$Cons case $Cons */
      ASSERT(sink__V158->context, !strcmp(SYMBOL(term__V159),  "H-Declarations" ));
      Term sub__V162 = SUB(term__V159, 0); permitUnusedTerm(sub__V162); int sub__V162_count = term__V159_count*LINK_COUNT(sub__V162); permitUnusedInt(sub__V162_count);
      ASSERT(sink__V158->context, !strcmp(SYMBOL(sub__V162),  "$Cons" ));
      Term sub__V163 = LINK(sink__V158->context, SUB(sub__V162, 0)); int sub__V163_count = sub__V162_count*LINK_COUNT(sub__V163); permitUnusedInt(sub__V163_count);
      /* sub__V163 = &#0-0 */
      Term sub__V164 = LINK(sink__V158->context, SUB(sub__V162, 1)); int sub__V164_count = sub__V162_count*LINK_COUNT(sub__V164); permitUnusedInt(sub__V164_count);
      /* sub__V164 = &#0-1 */
      NamedPropertyLink namedP__V165 = LINK_NamedPropertyLink(sink__V158->context, NAMED_PROPERTIES(term__V159));
      VariablePropertyLink varP__V166 = LINK_VariablePropertyLink(sink__V158->context, VARIABLE_PROPERTIES(term__V159));
      UNLINK(sink__V158->context, term__V159);
      ADD_PROPERTIES(sink__V158, LINK_NamedPropertyLink(sink__V158->context, namedP__V165), LINK_VariablePropertyLink(sink__V158->context, varP__V166));
      { START(sink__V158, _M_H_Declarations_s1);
        COPY(sink__V158, sub__V163);COPY(sink__V158, sub__V164);END(sink__V158, _M_H_Declarations_s1); }
      UNLINK_NamedPropertyLink(sink__V158->context, namedP__V165); UNLINK_VariablePropertyLink(sink__V158->context, varP__V166);
      
      return 1;
    break; } case Data_M__sNil: { /* Function HEADER-H-Declarations-2$H-Declarations$$Nil case $Nil */
      ASSERT(sink__V158->context, !strcmp(SYMBOL(term__V159),  "H-Declarations" ));
      Term sub__V167 = SUB(term__V159, 0); permitUnusedTerm(sub__V167); int sub__V167_count = term__V159_count*LINK_COUNT(sub__V167); permitUnusedInt(sub__V167_count);
      ASSERT(sink__V158->context, !strcmp(SYMBOL(sub__V167),  "$Nil" ));
      NamedPropertyLink namedP__V168 = LINK_NamedPropertyLink(sink__V158->context, NAMED_PROPERTIES(term__V159));
      VariablePropertyLink varP__V169 = LINK_VariablePropertyLink(sink__V158->context, VARIABLE_PROPERTIES(term__V159));
      UNLINK(sink__V158->context, term__V159);
      ADD_PROPERTIES(sink__V158, LINK_NamedPropertyLink(sink__V158->context, namedP__V168), LINK_VariablePropertyLink(sink__V158->context, varP__V169));
      { START(sink__V158, _M_H_Declarations_s2);
        END(sink__V158, _M_H_Declarations_s2); }
      UNLINK_NamedPropertyLink(sink__V158->context, namedP__V168); UNLINK_VariablePropertyLink(sink__V158->context, varP__V169);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION H-Function. */
int conBindOffs_M_H_Function[] = {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0};
char *nameFun_M_H_Function(Term term) { return  "H-Function" ; }
struct _ConstructionDescriptor descriptor_M_H_Function = {&sort_M_Reified_xVariable, 0, 7, sizeof(STRUCT_Con_M_H_Function), conBindOffs_M_H_Function, &nameFun_M_H_Function, &step_M_H_Function};

int step_M_H_Function(Sink sink__V170, Term term__V171)
{
  int term__V171_count = LINK_COUNT(term__V171); permitUnusedInt(term__V171_count);
  do {
    /* Contraction rule HEADER-H-Function-1. */
    ASSERT(sink__V170->context, !strcmp(SYMBOL(term__V171),  "H-Function" ));
    Term sub__V172 = LINK(sink__V170->context, SUB(term__V171, 0)); int sub__V172_count = term__V171_count*LINK_COUNT(sub__V172); permitUnusedInt(sub__V172_count);
    /* sub__V172 = &#1 */
    Term sub__V173 = SUB(term__V171, 1); permitUnusedTerm(sub__V173); int sub__V173_count = term__V171_count*LINK_COUNT(sub__V173); permitUnusedInt(sub__V173_count);
    /* sub__V173 = &#2 */
    Term sub__V174 = SUB(term__V171, 2); permitUnusedTerm(sub__V174); int sub__V174_count = term__V171_count*LINK_COUNT(sub__V174); permitUnusedInt(sub__V174_count);
    /* sub__V174 = &#3 */
    Term sub__V175 = LINK(sink__V170->context, SUB(term__V171, 3)); int sub__V175_count = term__V171_count*LINK_COUNT(sub__V175); permitUnusedInt(sub__V175_count);
    /* sub__V175 = &#4 */
    Term sub__V176 = LINK(sink__V170->context, SUB(term__V171, 4)); int sub__V176_count = term__V171_count*LINK_COUNT(sub__V176); permitUnusedInt(sub__V176_count);
    /* sub__V176 = &#5 */
    Term sub__V177 = SUB(term__V171, 5); permitUnusedTerm(sub__V177); int sub__V177_count = term__V171_count*LINK_COUNT(sub__V177); permitUnusedInt(sub__V177_count);
    CRSX_CHECK_SORT(sink__V170->context, sub__V177, &sort_M_Reified_xSort); /* sub__V177 = &#6 */
    Term sub__V178 = SUB(term__V171, 6); permitUnusedTerm(sub__V178); int sub__V178_count = term__V171_count*LINK_COUNT(sub__V178); permitUnusedInt(sub__V178_count);
    /* sub__V178 = &#7 */
    NamedPropertyLink namedP__V179 = LINK_NamedPropertyLink(sink__V170->context, NAMED_PROPERTIES(term__V171));
    VariablePropertyLink varP__V180 = LINK_VariablePropertyLink(sink__V170->context, VARIABLE_PROPERTIES(term__V171));
    UNLINK(sink__V170->context, term__V171);
    { START(sink__V170, _M__sTextCons);
      { START(sink__V170, _M__sTextBreak);
        LITERAL(sink__V170,  "\n" ); END(sink__V170, _M__sTextBreak); }
      { START(sink__V170, _M__sTextCons);
        { START(sink__V170, _M__sTextChars);
          LITERAL(sink__V170,  "/* FUNCTION " ); END(sink__V170, _M__sTextChars); }
        { START(sink__V170, _M__sTextCons);
          { START(sink__V170, _M__sTextEmbed);
            { START(sink__V170, _M_AsText);
              { START(sink__V170, _M_COMMENT_xTOKEN);
                COPY(sink__V170, sub__V172);END(sink__V170, _M_COMMENT_xTOKEN); }
              END(sink__V170, _M_AsText); }
            END(sink__V170, _M__sTextEmbed); }
          { START(sink__V170, _M__sTextCons);
            { START(sink__V170, _M__sTextChars);
              LITERAL(sink__V170,  " HEADER DECLARATIONS. */" ); END(sink__V170, _M__sTextChars); }
            { START(sink__V170, _M__sTextCons);
              { START(sink__V170, _M__sTextBreak);
                LITERAL(sink__V170,  "\n" ); END(sink__V170, _M__sTextBreak); }
              { START(sink__V170, _M__sTextCons);
                { START(sink__V170, _M__sTextEmbed);
                  { START(sink__V170, _M_AsText);
                    { START(sink__V170, _M_MapText_s1);
                      COPY(sink__V170, sub__V176);{ Variable x__V181 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V170->context,"x__V181");
                        Variable binds__V182[1] = {x__V181}; BINDS(sink__V170, 1, binds__V182);
                        { START(sink__V170, _M_H_Form);
                          USE(sink__V170, x__V181); END(sink__V170, _M_H_Form); }
                         }
                      END(sink__V170, _M_MapText_s1); }
                    END(sink__V170, _M_AsText); }
                  END(sink__V170, _M__sTextEmbed); }
                { START(sink__V170, _M__sTextCons);
                  { START(sink__V170, _M__sTextChars);
                    LITERAL(sink__V170,  "extern int " ); END(sink__V170, _M__sTextChars); }
                  { START(sink__V170, _M__sTextCons);
                    { START(sink__V170, _M__sTextEmbed);
                      { START(sink__V170, _M_AsText);
                        { START(sink__V170, _M_Step);
                          COPY(sink__V170, sub__V175);END(sink__V170, _M_Step); }
                        END(sink__V170, _M_AsText); }
                      END(sink__V170, _M__sTextEmbed); }
                    { START(sink__V170, _M__sTextCons);
                      { START(sink__V170, _M__sTextChars);
                        LITERAL(sink__V170,  "(Sink,Term);" ); END(sink__V170, _M__sTextChars); }
                      { START(sink__V170, _M__sTextCons);
                        { START(sink__V170, _M__sTextBreak);
                          LITERAL(sink__V170,  "\n" ); END(sink__V170, _M__sTextBreak); }
                        { START(sink__V170, _M__sTextNil);
                          END(sink__V170, _M__sTextNil); }
                        END(sink__V170, _M__sTextCons); }
                      END(sink__V170, _M__sTextCons); }
                    END(sink__V170, _M__sTextCons); }
                  END(sink__V170, _M__sTextCons); }
                END(sink__V170, _M__sTextCons); }
              END(sink__V170, _M__sTextCons); }
            END(sink__V170, _M__sTextCons); }
          END(sink__V170, _M__sTextCons); }
        END(sink__V170, _M__sTextCons); }
      END(sink__V170, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V170->context, namedP__V179); UNLINK_VariablePropertyLink(sink__V170->context, varP__V180);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION ComputeHeader2. */
int conBindOffs_M_ComputeHeader2[] = {0 , 0 , 0 , 0};
char *nameFun_M_ComputeHeader2(Term term) { return  "ComputeHeader2" ; }
struct _ConstructionDescriptor descriptor_M_ComputeHeader2 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_ComputeHeader2), conBindOffs_M_ComputeHeader2, &nameFun_M_ComputeHeader2, &step_M_ComputeHeader2};

int step_M_ComputeHeader2(Sink sink__V183, Term term__V184)
{
  int term__V184_count = LINK_COUNT(term__V184); permitUnusedInt(term__V184_count);
  do {
    /* Contraction rule HEADER-ComputeHeader2-1. */
    ASSERT(sink__V183->context, !strcmp(SYMBOL(term__V184),  "ComputeHeader2" ));
    Term sub__V185 = LINK(sink__V183->context, SUB(term__V184, 0)); int sub__V185_count = term__V184_count*LINK_COUNT(sub__V185); permitUnusedInt(sub__V185_count);
    /* sub__V185 = &#1 */
    Term sub__V186 = LINK(sink__V183->context, SUB(term__V184, 1)); int sub__V186_count = term__V184_count*LINK_COUNT(sub__V186); permitUnusedInt(sub__V186_count);
    /* sub__V186 = &#2 */
    Term sub__V187 = LINK(sink__V183->context, SUB(term__V184, 2)); int sub__V187_count = term__V184_count*LINK_COUNT(sub__V187); permitUnusedInt(sub__V187_count);
    UNLINK_SUB(sink__V183->context, term__V184,  2); NORMALIZE(sink__V183->context, sub__V187); SUB(term__V184,  2) = LINK(sink__V183->context, sub__V187);
    /* sub__V187 = &#3 */
    NamedPropertyLink namedP__V188 = LINK_NamedPropertyLink(sink__V183->context, NAMED_PROPERTIES(term__V184));
    VariablePropertyLink varP__V189 = LINK_VariablePropertyLink(sink__V183->context, VARIABLE_PROPERTIES(term__V184));
    UNLINK(sink__V183->context, term__V184);
    { START(sink__V183, _M__sTextCons);
      { START(sink__V183, _M__sTextChars);
        LITERAL(sink__V183,  "/* C HEADER FOR CRSX " ); END(sink__V183, _M__sTextChars); }
      { START(sink__V183, _M__sTextCons);
        { START(sink__V183, _M__sTextEmbed);
          { START(sink__V183, _M_AsText);
            { START(sink__V183, _M_COMMENT_xTOKEN);
              COPY(sink__V183, LINK(sink__V183->context, sub__V185));END(sink__V183, _M_COMMENT_xTOKEN); }
            END(sink__V183, _M_AsText); }
          END(sink__V183, _M__sTextEmbed); }
        { START(sink__V183, _M__sTextCons);
          { START(sink__V183, _M__sTextChars);
            LITERAL(sink__V183,  " MODULE " ); END(sink__V183, _M__sTextChars); }
          { START(sink__V183, _M__sTextCons);
            { START(sink__V183, _M__sTextEmbed);
              { START(sink__V183, _M_AsText);
                { START(sink__V183, _M_COMMENT_xTOKEN);
                  COPY(sink__V183, LINK(sink__V183->context, sub__V187));END(sink__V183, _M_COMMENT_xTOKEN); }
                END(sink__V183, _M_AsText); }
              END(sink__V183, _M__sTextEmbed); }
            { START(sink__V183, _M__sTextCons);
              { START(sink__V183, _M__sTextChars);
                LITERAL(sink__V183,  ". */" ); END(sink__V183, _M__sTextChars); }
              { START(sink__V183, _M__sTextCons);
                { START(sink__V183, _M__sTextBreak);
                  LITERAL(sink__V183,  "\n" ); END(sink__V183, _M__sTextBreak); }
                { START(sink__V183, _M__sTextCons);
                  { START(sink__V183, _M__sTextChars);
                    LITERAL(sink__V183,  "#ifndef CRSX_" ); END(sink__V183, _M__sTextChars); }
                  { START(sink__V183, _M__sTextCons);
                    { START(sink__V183, _M__sTextEmbed);
                      { START(sink__V183, _M_AsText);
                        { START(sink__V183, _M_MANGLE);
                          COPY(sink__V183, LINK(sink__V183->context, sub__V185));END(sink__V183, _M_MANGLE); }
                        END(sink__V183, _M_AsText); }
                      END(sink__V183, _M__sTextEmbed); }
                    { START(sink__V183, _M__sTextCons);
                      { START(sink__V183, _M__sTextEmbed);
                        { START(sink__V183, _M_AsText);
                          { START(sink__V183, _M_MANGLE);
                            COPY(sink__V183, LINK(sink__V183->context, sub__V187));END(sink__V183, _M_MANGLE); }
                          END(sink__V183, _M_AsText); }
                        END(sink__V183, _M__sTextEmbed); }
                      { START(sink__V183, _M__sTextCons);
                        { START(sink__V183, _M__sTextChars);
                          LITERAL(sink__V183,  "_H" ); END(sink__V183, _M__sTextChars); }
                        { START(sink__V183, _M__sTextCons);
                          { START(sink__V183, _M__sTextBreak);
                            LITERAL(sink__V183,  "\n" ); END(sink__V183, _M__sTextBreak); }
                          { START(sink__V183, _M__sTextCons);
                            { START(sink__V183, _M__sTextChars);
                              LITERAL(sink__V183,  "#define CRSX_" ); END(sink__V183, _M__sTextChars); }
                            { START(sink__V183, _M__sTextCons);
                              { START(sink__V183, _M__sTextEmbed);
                                { START(sink__V183, _M_AsText);
                                  { START(sink__V183, _M_MANGLE);
                                    COPY(sink__V183, LINK(sink__V183->context, sub__V185));END(sink__V183, _M_MANGLE); }
                                  END(sink__V183, _M_AsText); }
                                END(sink__V183, _M__sTextEmbed); }
                              { START(sink__V183, _M__sTextCons);
                                { START(sink__V183, _M__sTextEmbed);
                                  { START(sink__V183, _M_AsText);
                                    { START(sink__V183, _M_MANGLE);
                                      COPY(sink__V183, LINK(sink__V183->context, sub__V187));END(sink__V183, _M_MANGLE); }
                                    END(sink__V183, _M_AsText); }
                                  END(sink__V183, _M__sTextEmbed); }
                                { START(sink__V183, _M__sTextCons);
                                  { START(sink__V183, _M__sTextChars);
                                    LITERAL(sink__V183,  "_H" ); END(sink__V183, _M__sTextChars); }
                                  { START(sink__V183, _M__sTextCons);
                                    { START(sink__V183, _M__sTextBreak);
                                      LITERAL(sink__V183,  "\n" ); END(sink__V183, _M__sTextBreak); }
                                    { START(sink__V183, _M__sTextCons);
                                      { START(sink__V183, _M__sTextEmbed);
                                        { START(sink__V183, _M_AsText);
                                          { START(sink__V183, _M_DelayMapText_s1);
                                            {char* str__V190;{ Term term__V191;
                                                { char *value__V192 = getenv( "HEADERS" );
                                                  if (value__V192) term__V191 = makeStringLiteral(sink__V183->context, value__V192);
                                                  else {term__V191 = makeStringLiteral(sink__V183->context,  "" );
                                                    }
                                                }
                                                str__V190 = SYMBOL(term__V191);
                                                UNLINK(sink__V183->context, term__V191);
                                                }
                                              
                                              char* regex__V193;
                                              regex__V193 =  ";" ; SEND_SPLIT(str__V190, regex__V193, sink__V183);
                                            }
                                            { Variable x__V194 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V183->context,"x__V194");
                                              Variable x__V195 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V183->context,"x__V195");
                                              Variable binds__V196[2] = {x__V194,x__V195}; BINDS(sink__V183, 2, binds__V196);
                                              { START(sink__V183, _M__sTextCons);
                                                { START(sink__V183, _M__sTextChars);
                                                  LITERAL(sink__V183,  "#include \"" );
                                                  END(sink__V183, _M__sTextChars); }
                                                { START(sink__V183, _M__sTextCons);
                                                  { START(sink__V183, _M__sTextEmbed);
                                                    { START(sink__V183, _M_AsText);
                                                      { START(sink__V183, _M_DTOKEN);
                                                        USE(sink__V183, x__V194);
                                                        USE(sink__V183, x__V195);
                                                        END(sink__V183, _M_DTOKEN); }
                                                      END(sink__V183, _M_AsText); }
                                                    END(sink__V183, _M__sTextEmbed); }
                                                  { START(sink__V183, _M__sTextCons);
                                                    { START(sink__V183, _M__sTextChars);
                                                      LITERAL(sink__V183,  "\"" );
                                                      END(sink__V183, _M__sTextChars); }
                                                    { START(sink__V183, _M__sTextCons);
                                                      { START(sink__V183, _M__sTextBreak);
                                                        LITERAL(sink__V183,  "\n" );
                                                        END(sink__V183, _M__sTextBreak); }
                                                      { START(sink__V183, _M__sTextNil);
                                                        END(sink__V183, _M__sTextNil); }
                                                      END(sink__V183, _M__sTextCons); }
                                                    END(sink__V183, _M__sTextCons); }
                                                  END(sink__V183, _M__sTextCons); }
                                                END(sink__V183, _M__sTextCons); }
                                               }
                                            END(sink__V183, _M_DelayMapText_s1); }
                                          END(sink__V183, _M_AsText); }
                                        END(sink__V183, _M__sTextEmbed); }
                                      { START(sink__V183, _M__sTextCons);
                                        { START(sink__V183, _M__sTextBreak);
                                          LITERAL(sink__V183,  "\n" ); END(sink__V183, _M__sTextBreak); }
                                        { START(sink__V183, _M__sTextCons);
                                          { START(sink__V183, _M__sTextChars);
                                            LITERAL(sink__V183,  "#ifdef __cplusplus" );
                                            END(sink__V183, _M__sTextChars); }
                                          { START(sink__V183, _M__sTextCons);
                                            { START(sink__V183, _M__sTextBreak);
                                              LITERAL(sink__V183,  "\n" );
                                              END(sink__V183, _M__sTextBreak); }
                                            { START(sink__V183, _M__sTextCons);
                                              { START(sink__V183, _M__sTextChars);
                                                LITERAL(sink__V183,  "extern \"C\" {" );
                                                END(sink__V183, _M__sTextChars); }
                                              { START(sink__V183, _M__sTextCons);
                                                { START(sink__V183, _M__sTextBreak);
                                                  LITERAL(sink__V183,  "\n" );
                                                  END(sink__V183, _M__sTextBreak); }
                                                { START(sink__V183, _M__sTextCons);
                                                  { START(sink__V183, _M__sTextChars);
                                                    LITERAL(sink__V183,  "#endif" );
                                                    END(sink__V183, _M__sTextChars); }
                                                  { START(sink__V183, _M__sTextCons);
                                                    { START(sink__V183, _M__sTextBreak);
                                                      LITERAL(sink__V183,  "\n" );
                                                      END(sink__V183, _M__sTextBreak); }
                                                    { START(sink__V183, _M__sTextCons);
                                                      { START(sink__V183, _M__sTextEmbed);
                                                        { START(sink__V183, _M_AsText);
                                                          { START(sink__V183, _M_H_Declarations);
                                                            COPY(sink__V183, sub__V186);END(sink__V183, _M_H_Declarations); }
                                                          END(sink__V183, _M_AsText); }
                                                        END(sink__V183, _M__sTextEmbed); }
                                                      { START(sink__V183, _M__sTextCons);
                                                        { START(sink__V183, _M__sTextBreak);
                                                          LITERAL(sink__V183,  "\n" );
                                                          END(sink__V183, _M__sTextBreak); }
                                                        { START(sink__V183, _M__sTextCons);
                                                          { START(sink__V183, _M__sTextChars);
                                                            LITERAL(sink__V183,  "#ifdef __cplusplus" );
                                                            END(sink__V183, _M__sTextChars); }
                                                          { START(sink__V183, _M__sTextCons);
                                                            { START(sink__V183, _M__sTextBreak);
                                                              LITERAL(sink__V183,  "\n" );
                                                              END(sink__V183, _M__sTextBreak); }
                                                            { START(sink__V183, _M__sTextCons);
                                                              { START(sink__V183, _M__sTextChars);
                                                                LITERAL(sink__V183,  "}" );
                                                                END(sink__V183, _M__sTextChars); }
                                                              { START(sink__V183, _M__sTextCons);
                                                                { START(sink__V183, _M__sTextBreak);
                                                                  LITERAL(sink__V183,  "\n" );
                                                                  END(sink__V183, _M__sTextBreak); }
                                                                { START(sink__V183, _M__sTextCons);
                                                                  { START(sink__V183, _M__sTextChars);
                                                                    LITERAL(sink__V183,  "#endif" );
                                                                    END(sink__V183, _M__sTextChars); }
                                                                  { START(sink__V183, _M__sTextCons);
                                                                    { START(sink__V183, _M__sTextBreak);
                                                                      LITERAL(sink__V183,  "\n" );
                                                                      END(sink__V183, _M__sTextBreak); }
                                                                    { START(sink__V183, _M__sTextCons);
                                                                      { START(sink__V183, _M__sTextChars);
                                                                        LITERAL(sink__V183,  "/* END OF C HEADER FOR CRSX " );
                                                                        END(sink__V183, _M__sTextChars); }
                                                                      { START(sink__V183, _M__sTextCons);
                                                                        { START(sink__V183, _M__sTextEmbed);
                                                                          { START(sink__V183, _M_AsText);
                                                                            { START(sink__V183, _M_COMMENT_xTOKEN);
                                                                              COPY(sink__V183, sub__V185);END(sink__V183, _M_COMMENT_xTOKEN); }
                                                                            END(sink__V183, _M_AsText); }
                                                                          END(sink__V183, _M__sTextEmbed); }
                                                                        { START(sink__V183, _M__sTextCons);
                                                                          { START(sink__V183, _M__sTextChars);
                                                                            LITERAL(sink__V183,  " MODULE " );
                                                                            END(sink__V183, _M__sTextChars); }
                                                                          { START(sink__V183, _M__sTextCons);
                                                                            { START(sink__V183, _M__sTextEmbed);
                                                                              { START(sink__V183, _M_AsText);
                                                                                { START(sink__V183, _M_COMMENT_xTOKEN);
                                                                                  COPY(sink__V183, sub__V187);END(sink__V183, _M_COMMENT_xTOKEN); }
                                                                                END(sink__V183, _M_AsText); }
                                                                              END(sink__V183, _M__sTextEmbed); }
                                                                            { START(sink__V183, _M__sTextCons);
                                                                              { START(sink__V183, _M__sTextChars);
                                                                                LITERAL(sink__V183,  ". */" );
                                                                                END(sink__V183, _M__sTextChars); }
                                                                              { START(sink__V183, _M__sTextCons);
                                                                                { START(sink__V183, _M__sTextBreak);
                                                                                  LITERAL(sink__V183,  "\n" );
                                                                                  END(sink__V183, _M__sTextBreak); }
                                                                                { START(sink__V183, _M__sTextCons);
                                                                                  { START(sink__V183, _M__sTextChars);
                                                                                    LITERAL(sink__V183,  "#endif" );
                                                                                    END(sink__V183, _M__sTextChars); }
                                                                                  { START(sink__V183, _M__sTextCons);
                                                                                    { START(sink__V183, _M__sTextBreak);
                                                                                      LITERAL(sink__V183,  "\n" );
                                                                                      END(sink__V183, _M__sTextBreak); }
                                                                                    { START(sink__V183, _M__sTextNil);
                                                                                      END(sink__V183, _M__sTextNil); }
                                                                                    END(sink__V183, _M__sTextCons); }
                                                                                  END(sink__V183, _M__sTextCons); }
                                                                                END(sink__V183, _M__sTextCons); }
                                                                              END(sink__V183, _M__sTextCons); }
                                                                            END(sink__V183, _M__sTextCons); }
                                                                          END(sink__V183, _M__sTextCons); }
                                                                        END(sink__V183, _M__sTextCons); }
                                                                      END(sink__V183, _M__sTextCons); }
                                                                    END(sink__V183, _M__sTextCons); }
                                                                  END(sink__V183, _M__sTextCons); }
                                                                END(sink__V183, _M__sTextCons); }
                                                              END(sink__V183, _M__sTextCons); }
                                                            END(sink__V183, _M__sTextCons); }
                                                          END(sink__V183, _M__sTextCons); }
                                                        END(sink__V183, _M__sTextCons); }
                                                      END(sink__V183, _M__sTextCons); }
                                                    END(sink__V183, _M__sTextCons); }
                                                  END(sink__V183, _M__sTextCons); }
                                                END(sink__V183, _M__sTextCons); }
                                              END(sink__V183, _M__sTextCons); }
                                            END(sink__V183, _M__sTextCons); }
                                          END(sink__V183, _M__sTextCons); }
                                        END(sink__V183, _M__sTextCons); }
                                      END(sink__V183, _M__sTextCons); }
                                    END(sink__V183, _M__sTextCons); }
                                  END(sink__V183, _M__sTextCons); }
                                END(sink__V183, _M__sTextCons); }
                              END(sink__V183, _M__sTextCons); }
                            END(sink__V183, _M__sTextCons); }
                          END(sink__V183, _M__sTextCons); }
                        END(sink__V183, _M__sTextCons); }
                      END(sink__V183, _M__sTextCons); }
                    END(sink__V183, _M__sTextCons); }
                  END(sink__V183, _M__sTextCons); }
                END(sink__V183, _M__sTextCons); }
              END(sink__V183, _M__sTextCons); }
            END(sink__V183, _M__sTextCons); }
          END(sink__V183, _M__sTextCons); }
        END(sink__V183, _M__sTextCons); }
      END(sink__V183, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V183->context, namedP__V188); UNLINK_VariablePropertyLink(sink__V183->context, varP__V189);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Form. */
int conBindOffs_M_H_Form[] = {0 , 0};
char *nameFun_M_H_Form(Term term) { return  "H-Form" ; }
struct _ConstructionDescriptor descriptor_M_H_Form = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_H_Form), conBindOffs_M_H_Form, &nameFun_M_H_Form, &step_M_H_Form};

int step_M_H_Form(Sink sink__V197, Term term__V198)
{
  int term__V198_count = LINK_COUNT(term__V198); permitUnusedInt(term__V198_count);
  Term sub__V199 = FORCE(sink__V197->context, SUB(term__V198, 0));
  EnumOf_M_Reified_xForm choice__V200 = (IS_VARIABLE_USE(sub__V199) ? VarOf_M_Reified_xForm : (EnumOf_M_Reified_xForm) TAG(sub__V199));
  switch (choice__V200)
  {
    case Data_M_SORT_SET: { /* Function HEADER-H-Form-1$H-Form$SORT-SET case SORT-SET */
      ASSERT(sink__V197->context, !strcmp(SYMBOL(term__V198),  "H-Form" ));
      Term sub__V201 = SUB(term__V198, 0); permitUnusedTerm(sub__V201); int sub__V201_count = term__V198_count*LINK_COUNT(sub__V201); permitUnusedInt(sub__V201_count);
      CRSX_CHECK_SORT(sink__V197->context, sub__V201, &sort_M_Reified_xForm); ASSERT(sink__V197->context, !strcmp(SYMBOL(sub__V201),  "SORT-SET" ));
      Term sub__V202 = LINK(sink__V197->context, SUB(sub__V201, 0)); int sub__V202_count = sub__V201_count*LINK_COUNT(sub__V202); permitUnusedInt(sub__V202_count);
      CRSX_CHECK_SORT(sink__V197->context, sub__V202, &sort_M_Reified_xSort); /* sub__V202 = &#0-0 */
      Term sub__V203 = LINK(sink__V197->context, SUB(sub__V201, 1)); int sub__V203_count = sub__V201_count*LINK_COUNT(sub__V203); permitUnusedInt(sub__V203_count);
      CRSX_CHECK_SORT(sink__V197->context, sub__V203, &sort_M_Reified_xSort); /* sub__V203 = &#0-1 */
      Term sub__V204 = LINK(sink__V197->context, SUB(sub__V201, 2)); int sub__V204_count = sub__V201_count*LINK_COUNT(sub__V204); permitUnusedInt(sub__V204_count);
      CRSX_CHECK_SORT(sink__V197->context, sub__V204, &sort_M_Reified_xForm); /* sub__V204 = &#0-2 */
      NamedPropertyLink namedP__V205 = LINK_NamedPropertyLink(sink__V197->context, NAMED_PROPERTIES(term__V198));
      VariablePropertyLink varP__V206 = LINK_VariablePropertyLink(sink__V197->context, VARIABLE_PROPERTIES(term__V198));
      UNLINK(sink__V197->context, term__V198);
      ADD_PROPERTIES(sink__V197, LINK_NamedPropertyLink(sink__V197->context, namedP__V205), LINK_VariablePropertyLink(sink__V197->context, varP__V206));
      { START(sink__V197, _M_H_Form_s6);
        COPY(sink__V197, sub__V202);COPY(sink__V197, sub__V203);COPY(sink__V197, sub__V204);END(sink__V197, _M_H_Form_s6); }
      UNLINK_NamedPropertyLink(sink__V197->context, namedP__V205); UNLINK_VariablePropertyLink(sink__V197->context, varP__V206);
      
      return 1;
    break; } case Data_M_SORT_ALLOWS_VARIABLES: { /* Function HEADER-H-Form-2$H-Form$SORT-ALLOWS-VARIABLES case SORT-ALLOWS-VARIABLES */
      ASSERT(sink__V197->context, !strcmp(SYMBOL(term__V198),  "H-Form" ));
      Term sub__V207 = SUB(term__V198, 0); permitUnusedTerm(sub__V207); int sub__V207_count = term__V198_count*LINK_COUNT(sub__V207); permitUnusedInt(sub__V207_count);
      CRSX_CHECK_SORT(sink__V197->context, sub__V207, &sort_M_Reified_xForm); ASSERT(sink__V197->context, !strcmp(SYMBOL(sub__V207),  "SORT-ALLOWS-VARIABLES" ));
      NamedPropertyLink namedP__V208 = LINK_NamedPropertyLink(sink__V197->context, NAMED_PROPERTIES(term__V198));
      VariablePropertyLink varP__V209 = LINK_VariablePropertyLink(sink__V197->context, VARIABLE_PROPERTIES(term__V198));
      UNLINK(sink__V197->context, term__V198);
      ADD_PROPERTIES(sink__V197, LINK_NamedPropertyLink(sink__V197->context, namedP__V208), LINK_VariablePropertyLink(sink__V197->context, varP__V209));
      { START(sink__V197, _M_H_Form_s5);
        END(sink__V197, _M_H_Form_s5); }
      UNLINK_NamedPropertyLink(sink__V197->context, namedP__V208); UNLINK_VariablePropertyLink(sink__V197->context, varP__V209);
      
      return 1;
    break; } case Data_M_FORM: { /* Function HEADER-H-Form-3$H-Form$FORM case FORM */
      ASSERT(sink__V197->context, !strcmp(SYMBOL(term__V198),  "H-Form" ));
      Term sub__V210 = SUB(term__V198, 0); permitUnusedTerm(sub__V210); int sub__V210_count = term__V198_count*LINK_COUNT(sub__V210); permitUnusedInt(sub__V210_count);
      CRSX_CHECK_SORT(sink__V197->context, sub__V210, &sort_M_Reified_xForm); ASSERT(sink__V197->context, !strcmp(SYMBOL(sub__V210),  "FORM" ));
      Term sub__V211 = LINK(sink__V197->context, SUB(sub__V210, 0)); int sub__V211_count = sub__V210_count*LINK_COUNT(sub__V211); permitUnusedInt(sub__V211_count);
      /* sub__V211 = &#0-0 */
      Term sub__V212 = LINK(sink__V197->context, SUB(sub__V210, 1)); int sub__V212_count = sub__V210_count*LINK_COUNT(sub__V212); permitUnusedInt(sub__V212_count);
      /* sub__V212 = &#0-1 */
      NamedPropertyLink namedP__V213 = LINK_NamedPropertyLink(sink__V197->context, NAMED_PROPERTIES(term__V198));
      VariablePropertyLink varP__V214 = LINK_VariablePropertyLink(sink__V197->context, VARIABLE_PROPERTIES(term__V198));
      UNLINK(sink__V197->context, term__V198);
      ADD_PROPERTIES(sink__V197, LINK_NamedPropertyLink(sink__V197->context, namedP__V213), LINK_VariablePropertyLink(sink__V197->context, varP__V214));
      { START(sink__V197, _M_H_Form_s2);
        COPY(sink__V197, sub__V212);COPY(sink__V197, sub__V211);END(sink__V197, _M_H_Form_s2); }
      UNLINK_NamedPropertyLink(sink__V197->context, namedP__V213); UNLINK_VariablePropertyLink(sink__V197->context, varP__V214);
      
      return 1;
    } default: break;
  }
  return 0;
}

#ifdef __cplusplus
}
#endif
/* END OF C RULES FOR CRSX CRSXC MODULE HEADER. */
