/* C RULES FOR CRSX CRSXC MODULE HEADER. */
#include "CRSXC.h" 
#ifdef __cplusplus
extern "C" {
#endif

/* FUNCTION H-Data$2. */
int conBindOffs_M_H_Data_s2[] = {0 , 0 , 0 , 0 , 0};
char *nameFun_M_H_Data_s2(Term term) { return  "H-Data$2" ; }
struct _ConstructionDescriptor descriptor_M_H_Data_s2 = {&sort_M_Reified_xVariable, 0, 4, sizeof(STRUCT_Con_M_H_Data_s2), conBindOffs_M_H_Data_s2, &nameFun_M_H_Data_s2, &step_M_H_Data_s2};

int step_M_H_Data_s2(Sink sink__V1, Term term__V2)
{
  int term__V2_count = LINK_COUNT(term__V2); permitUnusedInt(term__V2_count);
  do {
    /* Contraction rule HEADER-H-Data-2. */
    ASSERT(sink__V1->context, !strcmp(SYMBOL(term__V2),  "H-Data$2" ));
    Term sub__V3 = SUB(term__V2, 0); permitUnusedTerm(sub__V3); int sub__V3_count = term__V2_count*LINK_COUNT(sub__V3); permitUnusedInt(sub__V3_count);
    CRSX_CHECK_SORT(sink__V1->context, sub__V3, &sort_M_Reified_xSort); /* sub__V3 = &#11 */
    Term sub__V4 = SUB(term__V2, 1); permitUnusedTerm(sub__V4); int sub__V4_count = term__V2_count*LINK_COUNT(sub__V4); permitUnusedInt(sub__V4_count);
    CRSX_CHECK_SORT(sink__V1->context, sub__V4, &sort_M_Reified_xSort); /* sub__V4 = &#12 */
    Term sub__V5 = LINK(sink__V1->context, SUB(term__V2, 2)); int sub__V5_count = term__V2_count*LINK_COUNT(sub__V5); permitUnusedInt(sub__V5_count);
    CRSX_CHECK_SORT(sink__V1->context, sub__V5, &sort_M_Reified_xSort); /* sub__V5 = &#13 */
    Term sub__V6 = LINK(sink__V1->context, SUB(term__V2, 3)); int sub__V6_count = term__V2_count*LINK_COUNT(sub__V6); permitUnusedInt(sub__V6_count);
    /* sub__V6 = &#2 */
    NamedPropertyLink namedP__V7 = LINK_NamedPropertyLink(sink__V1->context, NAMED_PROPERTIES(term__V2));
    VariablePropertyLink varP__V8 = LINK_VariablePropertyLink(sink__V1->context, VARIABLE_PROPERTIES(term__V2));
    UNLINK(sink__V1->context, term__V2);
    { START(sink__V1, _M_H_Data);
      COPY(sink__V1, sub__V5);COPY(sink__V1, sub__V6);END(sink__V1, _M_H_Data); }
    UNLINK_NamedPropertyLink(sink__V1->context, namedP__V7); UNLINK_VariablePropertyLink(sink__V1->context, varP__V8);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Data$1. */
int conBindOffs_M_H_Data_s1[] = {0 , 0 , 0 , 0};
char *nameFun_M_H_Data_s1(Term term) { return  "H-Data$1" ; }
struct _ConstructionDescriptor descriptor_M_H_Data_s1 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_H_Data_s1), conBindOffs_M_H_Data_s1, &nameFun_M_H_Data_s1, &step_M_H_Data_s1};

int step_M_H_Data_s1(Sink sink__V9, Term term__V10)
{
  int term__V10_count = LINK_COUNT(term__V10); permitUnusedInt(term__V10_count);
  do {
    /* Contraction rule HEADER-H-Data-1. */
    ASSERT(sink__V9->context, !strcmp(SYMBOL(term__V10),  "H-Data$1" ));
    Term sub__V11 = LINK(sink__V9->context, SUB(term__V10, 0)); int sub__V11_count = term__V10_count*LINK_COUNT(sub__V11); permitUnusedInt(sub__V11_count);
    /* sub__V11 = &#11 */
    Term sub__V12 = SUB(term__V10, 1); permitUnusedTerm(sub__V12); int sub__V12_count = term__V10_count*LINK_COUNT(sub__V12); permitUnusedInt(sub__V12_count);
    /* sub__V12 = &#12 */
    Term sub__V13 = LINK(sink__V9->context, SUB(term__V10, 2)); int sub__V13_count = term__V10_count*LINK_COUNT(sub__V13); permitUnusedInt(sub__V13_count);
    /* sub__V13 = &#2 */
    NamedPropertyLink namedP__V14 = LINK_NamedPropertyLink(sink__V9->context, NAMED_PROPERTIES(term__V10));
    VariablePropertyLink varP__V15 = LINK_VariablePropertyLink(sink__V9->context, VARIABLE_PROPERTIES(term__V10));
    UNLINK(sink__V9->context, term__V10);
    { START(sink__V9, _M__sTextCons);
      { START(sink__V9, _M__sTextBreak);
        LITERAL(sink__V9,  "\n" ); END(sink__V9, _M__sTextBreak); }
      { START(sink__V9, _M__sTextCons);
        { START(sink__V9, _M__sTextChars);
          LITERAL(sink__V9,  "/* DATA SORT " ); END(sink__V9, _M__sTextChars); }
        { START(sink__V9, _M__sTextCons);
          { START(sink__V9, _M__sTextEmbed);
            { START(sink__V9, _M_AsText);
              { START(sink__V9, _M_COMMENT_xTOKEN);
                COPY(sink__V9, LINK(sink__V9->context, sub__V11));END(sink__V9, _M_COMMENT_xTOKEN); }
              END(sink__V9, _M_AsText); }
            END(sink__V9, _M__sTextEmbed); }
          { START(sink__V9, _M__sTextCons);
            { START(sink__V9, _M__sTextChars);
              LITERAL(sink__V9,  " HEADER DECLARATIONS. */" ); END(sink__V9, _M__sTextChars); }
            { START(sink__V9, _M__sTextCons);
              { START(sink__V9, _M__sTextBreak);
                LITERAL(sink__V9,  "\n" ); END(sink__V9, _M__sTextBreak); }
              { START(sink__V9, _M__sTextCons);
                { START(sink__V9, _M__sTextChars);
                  LITERAL(sink__V9,  "typedef enum {" ); END(sink__V9, _M__sTextChars); }
                { START(sink__V9, _M__sTextCons);
                  { START(sink__V9, _M__sTextEmbed);
                    { START(sink__V9, _M_AsText);
                      { START(sink__V9, _M_EnumFun);
                        COPY(sink__V9, LINK(sink__V9->context, sub__V11));END(sink__V9, _M_EnumFun); }
                      END(sink__V9, _M_AsText); }
                    END(sink__V9, _M__sTextEmbed); }
                  { START(sink__V9, _M__sTextCons);
                    { START(sink__V9, _M__sTextChars);
                      LITERAL(sink__V9,  " = 0, " ); END(sink__V9, _M__sTextChars); }
                    { START(sink__V9, _M__sTextCons);
                      { START(sink__V9, _M__sTextEmbed);
                        { START(sink__V9, _M_AsText);
                          { START(sink__V9, _M_EnumVar);
                            COPY(sink__V9, LINK(sink__V9->context, sub__V11));END(sink__V9, _M_EnumVar); }
                          END(sink__V9, _M_AsText); }
                        END(sink__V9, _M__sTextEmbed); }
                      { START(sink__V9, _M__sTextCons);
                        { START(sink__V9, _M__sTextChars);
                          LITERAL(sink__V9,  " = 1" ); END(sink__V9, _M__sTextChars); }
                        { START(sink__V9, _M__sTextCons);
                          { START(sink__V9, _M__sTextEmbed);
                            { START(sink__V9, _M_AsText);
                              { START(sink__V9, _M_DelayMapText_s1);
                                { START(sink__V9, _M_Forms_Constructors);
                                  COPY(sink__V9, LINK(sink__V9->context, sub__V13));END(sink__V9, _M_Forms_Constructors); }
                                { Variable x__V16 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V9->context,"x__V16");
                                  Variable x__V17 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V9->context,"x__V17");
                                  Variable binds__V18[2] = {x__V16,x__V17}; BINDS(sink__V9, 2, binds__V18);
                                  { START(sink__V9, _M__sTextCons);
                                    { START(sink__V9, _M__sTextChars);
                                      LITERAL(sink__V9,  ", " ); END(sink__V9, _M__sTextChars); }
                                    { START(sink__V9, _M__sTextCons);
                                      { START(sink__V9, _M__sTextEmbed);
                                        { START(sink__V9, _M_AsText);
                                          { START(sink__V9, _M_DEnumTag);
                                            USE(sink__V9, x__V16); USE(sink__V9, x__V17); END(sink__V9, _M_DEnumTag); }
                                          END(sink__V9, _M_AsText); }
                                        END(sink__V9, _M__sTextEmbed); }
                                      { START(sink__V9, _M__sTextNil);
                                        END(sink__V9, _M__sTextNil); }
                                      END(sink__V9, _M__sTextCons); }
                                    END(sink__V9, _M__sTextCons); }
                                   }
                                END(sink__V9, _M_DelayMapText_s1); }
                              END(sink__V9, _M_AsText); }
                            END(sink__V9, _M__sTextEmbed); }
                          { START(sink__V9, _M__sTextCons);
                            { START(sink__V9, _M__sTextChars);
                              LITERAL(sink__V9,  "} " ); END(sink__V9, _M__sTextChars); }
                            { START(sink__V9, _M__sTextCons);
                              { START(sink__V9, _M__sTextEmbed);
                                { START(sink__V9, _M_AsText);
                                  { START(sink__V9, _M_Enum);
                                    COPY(sink__V9, LINK(sink__V9->context, sub__V11));END(sink__V9, _M_Enum); }
                                  END(sink__V9, _M_AsText); }
                                END(sink__V9, _M__sTextEmbed); }
                              { START(sink__V9, _M__sTextCons);
                                { START(sink__V9, _M__sTextChars);
                                  LITERAL(sink__V9,  ";" ); END(sink__V9, _M__sTextChars); }
                                { START(sink__V9, _M__sTextCons);
                                  { START(sink__V9, _M__sTextBreak);
                                    LITERAL(sink__V9,  "\n" ); END(sink__V9, _M__sTextBreak); }
                                  { START(sink__V9, _M__sTextCons);
                                    { START(sink__V9, _M__sTextEmbed);
                                      { START(sink__V9, _M_AsText);
                                        { START(sink__V9, _M_MapText_s1);
                                          COPY(sink__V9, sub__V13);{ Variable x__V19 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V9->context,"x__V19");
                                            Variable binds__V20[1] = {x__V19}; BINDS(sink__V9, 1, binds__V20);
                                            { START(sink__V9, _M_H_Form);
                                              USE(sink__V9, x__V19); END(sink__V9, _M_H_Form); }
                                             }
                                          END(sink__V9, _M_MapText_s1); }
                                        END(sink__V9, _M_AsText); }
                                      END(sink__V9, _M__sTextEmbed); }
                                    { START(sink__V9, _M__sTextCons);
                                      { START(sink__V9, _M__sTextChars);
                                        LITERAL(sink__V9,  "extern struct _SortDescriptor " );
                                        END(sink__V9, _M__sTextChars); }
                                      { START(sink__V9, _M__sTextCons);
                                        { START(sink__V9, _M__sTextEmbed);
                                          { START(sink__V9, _M_AsText);
                                            { START(sink__V9, _M_Sort);
                                              COPY(sink__V9, sub__V11);END(sink__V9, _M_Sort); }
                                            END(sink__V9, _M_AsText); }
                                          END(sink__V9, _M__sTextEmbed); }
                                        { START(sink__V9, _M__sTextCons);
                                          { START(sink__V9, _M__sTextChars);
                                            LITERAL(sink__V9,  ";" ); END(sink__V9, _M__sTextChars); }
                                          { START(sink__V9, _M__sTextCons);
                                            { START(sink__V9, _M__sTextBreak);
                                              LITERAL(sink__V9,  "\n" );
                                              END(sink__V9, _M__sTextBreak); }
                                            { START(sink__V9, _M__sTextNil);
                                              END(sink__V9, _M__sTextNil); }
                                            END(sink__V9, _M__sTextCons); }
                                          END(sink__V9, _M__sTextCons); }
                                        END(sink__V9, _M__sTextCons); }
                                      END(sink__V9, _M__sTextCons); }
                                    END(sink__V9, _M__sTextCons); }
                                  END(sink__V9, _M__sTextCons); }
                                END(sink__V9, _M__sTextCons); }
                              END(sink__V9, _M__sTextCons); }
                            END(sink__V9, _M__sTextCons); }
                          END(sink__V9, _M__sTextCons); }
                        END(sink__V9, _M__sTextCons); }
                      END(sink__V9, _M__sTextCons); }
                    END(sink__V9, _M__sTextCons); }
                  END(sink__V9, _M__sTextCons); }
                END(sink__V9, _M__sTextCons); }
              END(sink__V9, _M__sTextCons); }
            END(sink__V9, _M__sTextCons); }
          END(sink__V9, _M__sTextCons); }
        END(sink__V9, _M__sTextCons); }
      END(sink__V9, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V9->context, namedP__V14); UNLINK_VariablePropertyLink(sink__V9->context, varP__V15);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Form$2. */
int conBindOffs_M_H_Form_s2[] = {0 , 0 , 0};
char *nameFun_M_H_Form_s2(Term term) { return  "H-Form$2" ; }
struct _ConstructionDescriptor descriptor_M_H_Form_s2 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_H_Form_s2), conBindOffs_M_H_Form_s2, &nameFun_M_H_Form_s2, &step_M_H_Form_s2};

int step_M_H_Form_s2(Sink sink__V21, Term term__V22)
{
  int term__V22_count = LINK_COUNT(term__V22); permitUnusedInt(term__V22_count);
  Term sub__V23 = FORCE(sink__V21->context, SUB(term__V22, 0));
  EnumOf_M__sList choice__V24 = (IS_VARIABLE_USE(sub__V23) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V23));
  switch (choice__V24)
  {
    case Data_M__sNil: { /* Function HEADER-H-Form-3$H-Form$2$$Nil case $Nil */
      ASSERT(sink__V21->context, !strcmp(SYMBOL(term__V22),  "H-Form$2" ));
      Term sub__V25 = SUB(term__V22, 0); permitUnusedTerm(sub__V25); int sub__V25_count = term__V22_count*LINK_COUNT(sub__V25); permitUnusedInt(sub__V25_count);
      ASSERT(sink__V21->context, !strcmp(SYMBOL(sub__V25),  "$Nil" ));
      Term sub__V26 = LINK(sink__V21->context, SUB(term__V22, 1)); int sub__V26_count = term__V22_count*LINK_COUNT(sub__V26); permitUnusedInt(sub__V26_count);
      /* sub__V26 = &#0 */
      NamedPropertyLink namedP__V27 = LINK_NamedPropertyLink(sink__V21->context, NAMED_PROPERTIES(term__V22));
      VariablePropertyLink varP__V28 = LINK_VariablePropertyLink(sink__V21->context, VARIABLE_PROPERTIES(term__V22));
      UNLINK(sink__V21->context, term__V22);
      ADD_PROPERTIES(sink__V21, LINK_NamedPropertyLink(sink__V21->context, namedP__V27), LINK_VariablePropertyLink(sink__V21->context, varP__V28));
      { START(sink__V21, _M_H_Form_s4);
        COPY(sink__V21, sub__V26);END(sink__V21, _M_H_Form_s4); }
      UNLINK_NamedPropertyLink(sink__V21->context, namedP__V27); UNLINK_VariablePropertyLink(sink__V21->context, varP__V28);
      
      return 1;
    break; } case Data_M__sCons: { /* Function HEADER-H-Form-4$H-Form$2$$Cons case $Cons */
      ASSERT(sink__V21->context, !strcmp(SYMBOL(term__V22),  "H-Form$2" ));
      Term sub__V29 = SUB(term__V22, 0); permitUnusedTerm(sub__V29); int sub__V29_count = term__V22_count*LINK_COUNT(sub__V29); permitUnusedInt(sub__V29_count);
      ASSERT(sink__V21->context, !strcmp(SYMBOL(sub__V29),  "$Cons" ));
      Term sub__V30 = LINK(sink__V21->context, SUB(sub__V29, 0)); int sub__V30_count = sub__V29_count*LINK_COUNT(sub__V30); permitUnusedInt(sub__V30_count);
      /* sub__V30 = &#0-0 */
      Term sub__V31 = LINK(sink__V21->context, SUB(sub__V29, 1)); int sub__V31_count = sub__V29_count*LINK_COUNT(sub__V31); permitUnusedInt(sub__V31_count);
      /* sub__V31 = &#0-1 */
      Term sub__V32 = LINK(sink__V21->context, SUB(term__V22, 1)); int sub__V32_count = term__V22_count*LINK_COUNT(sub__V32); permitUnusedInt(sub__V32_count);
      /* sub__V32 = &#2 */
      NamedPropertyLink namedP__V33 = LINK_NamedPropertyLink(sink__V21->context, NAMED_PROPERTIES(term__V22));
      VariablePropertyLink varP__V34 = LINK_VariablePropertyLink(sink__V21->context, VARIABLE_PROPERTIES(term__V22));
      UNLINK(sink__V21->context, term__V22);
      ADD_PROPERTIES(sink__V21, LINK_NamedPropertyLink(sink__V21->context, namedP__V33), LINK_VariablePropertyLink(sink__V21->context, varP__V34));
      { START(sink__V21, _M_H_Form_s3);
        COPY(sink__V21, sub__V30);COPY(sink__V21, sub__V31);COPY(sink__V21, sub__V32);END(sink__V21, _M_H_Form_s3); }
      UNLINK_NamedPropertyLink(sink__V21->context, namedP__V33); UNLINK_VariablePropertyLink(sink__V21->context, varP__V34);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION ComputeHeader$1. */
int conBindOffs_M_ComputeHeader_s1[] = {0 , 0 , 0};
char *nameFun_M_ComputeHeader_s1(Term term) { return  "ComputeHeader$1" ; }
struct _ConstructionDescriptor descriptor_M_ComputeHeader_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_ComputeHeader_s1), conBindOffs_M_ComputeHeader_s1, &nameFun_M_ComputeHeader_s1, &step_M_ComputeHeader_s1};

int step_M_ComputeHeader_s1(Sink sink__V35, Term term__V36)
{
  int term__V36_count = LINK_COUNT(term__V36); permitUnusedInt(term__V36_count);
  do {
    /* Contraction rule HEADER-ComputeHeader-1. */
    ASSERT(sink__V35->context, !strcmp(SYMBOL(term__V36),  "ComputeHeader$1" ));
    Term sub__V37 = LINK(sink__V35->context, SUB(term__V36, 0)); int sub__V37_count = term__V36_count*LINK_COUNT(sub__V37); permitUnusedInt(sub__V37_count);
    /* sub__V37 = &#11 */
    Term sub__V38 = LINK(sink__V35->context, SUB(term__V36, 1)); int sub__V38_count = term__V36_count*LINK_COUNT(sub__V38); permitUnusedInt(sub__V38_count);
    /* sub__V38 = &#12 */
    NamedPropertyLink namedP__V39 = LINK_NamedPropertyLink(sink__V35->context, NAMED_PROPERTIES(term__V36));
    VariablePropertyLink varP__V40 = LINK_VariablePropertyLink(sink__V35->context, VARIABLE_PROPERTIES(term__V36));
    UNLINK(sink__V35->context, term__V36);
    { START(sink__V35, _M_ComputeHeader2);
      COPY(sink__V35, sub__V37);COPY(sink__V35, sub__V38);{ Term term__V41;
        { char *value__V42 = getenv( "MODULE" );
          if (value__V42) term__V41 = makeStringLiteral(sink__V35->context, value__V42);
          else {term__V41 = makeStringLiteral(sink__V35->context,  "" ); }
        }
        COPY(sink__V35, term__V41); /*CONSERVATIVE*/ }
      END(sink__V35, _M_ComputeHeader2); }
    UNLINK_NamedPropertyLink(sink__V35->context, namedP__V39); UNLINK_VariablePropertyLink(sink__V35->context, varP__V40);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Form$6. */
int conBindOffs_M_H_Form_s6[] = {0 , 0 , 0 , 0};
char *nameFun_M_H_Form_s6(Term term) { return  "H-Form$6" ; }
struct _ConstructionDescriptor descriptor_M_H_Form_s6 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_H_Form_s6), conBindOffs_M_H_Form_s6, &nameFun_M_H_Form_s6, &step_M_H_Form_s6};

int step_M_H_Form_s6(Sink sink__V43, Term term__V44)
{
  int term__V44_count = LINK_COUNT(term__V44); permitUnusedInt(term__V44_count);
  do {
    /* Contraction rule HEADER-H-Form-1. */
    ASSERT(sink__V43->context, !strcmp(SYMBOL(term__V44),  "H-Form$6" ));
    Term sub__V45 = SUB(term__V44, 0); permitUnusedTerm(sub__V45); int sub__V45_count = term__V44_count*LINK_COUNT(sub__V45); permitUnusedInt(sub__V45_count);
    CRSX_CHECK_SORT(sink__V43->context, sub__V45, &sort_M_Reified_xSort); /* sub__V45 = &#11 */
    Term sub__V46 = SUB(term__V44, 1); permitUnusedTerm(sub__V46); int sub__V46_count = term__V44_count*LINK_COUNT(sub__V46); permitUnusedInt(sub__V46_count);
    CRSX_CHECK_SORT(sink__V43->context, sub__V46, &sort_M_Reified_xSort); /* sub__V46 = &#12 */
    Term sub__V47 = LINK(sink__V43->context, SUB(term__V44, 2)); int sub__V47_count = term__V44_count*LINK_COUNT(sub__V47); permitUnusedInt(sub__V47_count);
    CRSX_CHECK_SORT(sink__V43->context, sub__V47, &sort_M_Reified_xForm); /* sub__V47 = &#13 */
    NamedPropertyLink namedP__V48 = LINK_NamedPropertyLink(sink__V43->context, NAMED_PROPERTIES(term__V44));
    VariablePropertyLink varP__V49 = LINK_VariablePropertyLink(sink__V43->context, VARIABLE_PROPERTIES(term__V44));
    UNLINK(sink__V43->context, term__V44);
    { START(sink__V43, _M_H_Form);
      COPY(sink__V43, sub__V47);END(sink__V43, _M_H_Form); }
    UNLINK_NamedPropertyLink(sink__V43->context, namedP__V48); UNLINK_VariablePropertyLink(sink__V43->context, varP__V49);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Form$5. */
int conBindOffs_M_H_Form_s5[] = {0};
char *nameFun_M_H_Form_s5(Term term) { return  "H-Form$5" ; }
struct _ConstructionDescriptor descriptor_M_H_Form_s5 = {&sort_M_Reified_xVariable, 0, 0, sizeof(STRUCT_Con_M_H_Form_s5), conBindOffs_M_H_Form_s5, &nameFun_M_H_Form_s5, &step_M_H_Form_s5};

int step_M_H_Form_s5(Sink sink__V50, Term term__V51)
{
  int term__V51_count = LINK_COUNT(term__V51); permitUnusedInt(term__V51_count);
  do {
    /* Contraction rule HEADER-H-Form-2. */
    ASSERT(sink__V50->context, !strcmp(SYMBOL(term__V51),  "H-Form$5" ));
    NamedPropertyLink namedP__V52 = LINK_NamedPropertyLink(sink__V50->context, NAMED_PROPERTIES(term__V51));
    VariablePropertyLink varP__V53 = LINK_VariablePropertyLink(sink__V50->context, VARIABLE_PROPERTIES(term__V51));
    UNLINK(sink__V50->context, term__V51);
    { START(sink__V50, _M__sTextNil); END(sink__V50, _M__sTextNil); } UNLINK_NamedPropertyLink(sink__V50->context, namedP__V52); UNLINK_VariablePropertyLink(sink__V50->context, varP__V53);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Form$4. */
int conBindOffs_M_H_Form_s4[] = {0 , 0};
char *nameFun_M_H_Form_s4(Term term) { return  "H-Form$4" ; }
struct _ConstructionDescriptor descriptor_M_H_Form_s4 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_H_Form_s4), conBindOffs_M_H_Form_s4, &nameFun_M_H_Form_s4, &step_M_H_Form_s4};

int step_M_H_Form_s4(Sink sink__V54, Term term__V55)
{
  int term__V55_count = LINK_COUNT(term__V55); permitUnusedInt(term__V55_count);
  do {
    /* Contraction rule HEADER-H-Form-3. */
    ASSERT(sink__V54->context, !strcmp(SYMBOL(term__V55),  "H-Form$4" ));
    Term sub__V56 = LINK(sink__V54->context, SUB(term__V55, 0)); int sub__V56_count = term__V55_count*LINK_COUNT(sub__V56); permitUnusedInt(sub__V56_count);
    /* sub__V56 = &#11 */
    NamedPropertyLink namedP__V57 = LINK_NamedPropertyLink(sink__V54->context, NAMED_PROPERTIES(term__V55));
    VariablePropertyLink varP__V58 = LINK_VariablePropertyLink(sink__V54->context, VARIABLE_PROPERTIES(term__V55));
    UNLINK(sink__V54->context, term__V55);
    { START(sink__V54, _M__sTextCons);
      { START(sink__V54, _M__sTextChars);
        LITERAL(sink__V54,  "#define STRUCT" ); END(sink__V54, _M__sTextChars); }
      { START(sink__V54, _M__sTextCons);
        { START(sink__V54, _M__sTextEmbed);
          { START(sink__V54, _M_AsText);
            { START(sink__V54, _M_Struct);
              COPY(sink__V54, LINK(sink__V54->context, sub__V56));END(sink__V54, _M_Struct); }
            END(sink__V54, _M_AsText); }
          END(sink__V54, _M__sTextEmbed); }
        { START(sink__V54, _M__sTextCons);
          { START(sink__V54, _M__sTextChars);
            LITERAL(sink__V54,  " struct _ConstantConstruction" ); END(sink__V54, _M__sTextChars); }
          { START(sink__V54, _M__sTextCons);
            { START(sink__V54, _M__sTextBreak);
              LITERAL(sink__V54,  "\n" ); END(sink__V54, _M__sTextBreak); }
            { START(sink__V54, _M__sTextCons);
              { START(sink__V54, _M__sTextChars);
                LITERAL(sink__V54,  "extern struct _ConstructionDescriptor " );
                END(sink__V54, _M__sTextChars); }
              { START(sink__V54, _M__sTextCons);
                { START(sink__V54, _M__sTextEmbed);
                  { START(sink__V54, _M_AsText);
                    { START(sink__V54, _M_Descriptor);
                      COPY(sink__V54, sub__V56);END(sink__V54, _M_Descriptor); }
                    END(sink__V54, _M_AsText); }
                  END(sink__V54, _M__sTextEmbed); }
                { START(sink__V54, _M__sTextCons);
                  { START(sink__V54, _M__sTextChars);
                    LITERAL(sink__V54,  ";" ); END(sink__V54, _M__sTextChars); }
                  { START(sink__V54, _M__sTextCons);
                    { START(sink__V54, _M__sTextBreak);
                      LITERAL(sink__V54,  "\n" ); END(sink__V54, _M__sTextBreak); }
                    { START(sink__V54, _M__sTextNil);
                      END(sink__V54, _M__sTextNil); }
                    END(sink__V54, _M__sTextCons); }
                  END(sink__V54, _M__sTextCons); }
                END(sink__V54, _M__sTextCons); }
              END(sink__V54, _M__sTextCons); }
            END(sink__V54, _M__sTextCons); }
          END(sink__V54, _M__sTextCons); }
        END(sink__V54, _M__sTextCons); }
      END(sink__V54, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V54->context, namedP__V57); UNLINK_VariablePropertyLink(sink__V54->context, varP__V58);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Form$3. */
int conBindOffs_M_H_Form_s3[] = {0 , 0 , 0 , 0};
char *nameFun_M_H_Form_s3(Term term) { return  "H-Form$3" ; }
struct _ConstructionDescriptor descriptor_M_H_Form_s3 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_H_Form_s3), conBindOffs_M_H_Form_s3, &nameFun_M_H_Form_s3, &step_M_H_Form_s3};

int step_M_H_Form_s3(Sink sink__V59, Term term__V60)
{
  int term__V60_count = LINK_COUNT(term__V60); permitUnusedInt(term__V60_count);
  do {
    /* Contraction rule HEADER-H-Form-4. */
    ASSERT(sink__V59->context, !strcmp(SYMBOL(term__V60),  "H-Form$3" ));
    Term sub__V61 = LINK(sink__V59->context, SUB(term__V60, 0)); int sub__V61_count = term__V60_count*LINK_COUNT(sub__V61); permitUnusedInt(sub__V61_count);
    /* sub__V61 = &#121 */
    Term sub__V62 = LINK(sink__V59->context, SUB(term__V60, 1)); int sub__V62_count = term__V60_count*LINK_COUNT(sub__V62); permitUnusedInt(sub__V62_count);
    /* sub__V62 = &#122 */
    Term sub__V63 = LINK(sink__V59->context, SUB(term__V60, 2)); int sub__V63_count = term__V60_count*LINK_COUNT(sub__V63); permitUnusedInt(sub__V63_count);
    /* sub__V63 = &#11 */
    NamedPropertyLink namedP__V64 = LINK_NamedPropertyLink(sink__V59->context, NAMED_PROPERTIES(term__V60));
    VariablePropertyLink varP__V65 = LINK_VariablePropertyLink(sink__V59->context, VARIABLE_PROPERTIES(term__V60));
    UNLINK(sink__V59->context, term__V60);
    { START(sink__V59, _M__sTextCons);
      { START(sink__V59, _M__sTextChars);
        LITERAL(sink__V59,  "#define STRUCT" ); END(sink__V59, _M__sTextChars); }
      { START(sink__V59, _M__sTextCons);
        { START(sink__V59, _M__sTextEmbed);
          { START(sink__V59, _M_AsText);
            { START(sink__V59, _M_Struct);
              COPY(sink__V59, LINK(sink__V59->context, sub__V63));END(sink__V59, _M_Struct); }
            END(sink__V59, _M_AsText); }
          END(sink__V59, _M__sTextEmbed); }
        { START(sink__V59, _M__sTextCons);
          { START(sink__V59, _M__sTextChars);
            LITERAL(sink__V59,  " struct " ); END(sink__V59, _M__sTextChars); }
          { START(sink__V59, _M__sTextCons);
            { START(sink__V59, _M__sTextEmbed);
              { START(sink__V59, _M_AsText);
                { START(sink__V59, _M_Struct);
                  COPY(sink__V59, LINK(sink__V59->context, sub__V63));END(sink__V59, _M_Struct); }
                END(sink__V59, _M_AsText); }
              END(sink__V59, _M__sTextEmbed); }
            { START(sink__V59, _M__sTextCons);
              { START(sink__V59, _M__sTextBreak);
                LITERAL(sink__V59,  "\n" ); END(sink__V59, _M__sTextBreak); }
              { START(sink__V59, _M__sTextCons);
                { START(sink__V59, _M__sTextChars);
                  LITERAL(sink__V59,  "struct " ); END(sink__V59, _M__sTextChars); }
                { START(sink__V59, _M__sTextCons);
                  { START(sink__V59, _M__sTextEmbed);
                    { START(sink__V59, _M_AsText);
                      { START(sink__V59, _M_Struct);
                        COPY(sink__V59, LINK(sink__V59->context, sub__V63));END(sink__V59, _M_Struct); }
                      END(sink__V59, _M_AsText); }
                    END(sink__V59, _M__sTextEmbed); }
                  { START(sink__V59, _M__sTextCons);
                    { START(sink__V59, _M__sTextChars);
                      LITERAL(sink__V59,  " {struct _Construction construction; Term sub[" );
                      END(sink__V59, _M__sTextChars); }
                    { START(sink__V59, _M__sTextCons);
                      { START(sink__V59, _M__sTextEmbed);
                        { START(sink__V59, _M_AsText);
                          { START(sink__V59, _M_INTEGER);
                            { START(sink__V59, _M_Length);
                              COPY(sink__V59, LINK(sink__V59->context, sub__V62));LITERAL(sink__V59,  "1" ); END(sink__V59, _M_Length); }
                            END(sink__V59, _M_INTEGER); }
                          END(sink__V59, _M_AsText); }
                        END(sink__V59, _M__sTextEmbed); }
                      { START(sink__V59, _M__sTextCons);
                        { START(sink__V59, _M__sTextChars);
                          LITERAL(sink__V59,  "]; Variable binder[" ); END(sink__V59, _M__sTextChars); }
                        { START(sink__V59, _M__sTextCons);
                          { START(sink__V59, _M__sTextEmbed);
                            { START(sink__V59, _M_AsText);
                              { START(sink__V59, _M_INTEGER);
                                { START(sink__V59, _M_FormArguments__binder__count);
                                  { START(sink__V59, _M__sCons);
                                    COPY(sink__V59, sub__V61);COPY(sink__V59, sub__V62);END(sink__V59, _M__sCons); }
                                  LITERAL(sink__V59,  "0" ); END(sink__V59, _M_FormArguments__binder__count); }
                                END(sink__V59, _M_INTEGER); }
                              END(sink__V59, _M_AsText); }
                            END(sink__V59, _M__sTextEmbed); }
                          { START(sink__V59, _M__sTextCons);
                            { START(sink__V59, _M__sTextChars);
                              LITERAL(sink__V59,  "];};" ); END(sink__V59, _M__sTextChars); }
                            { START(sink__V59, _M__sTextCons);
                              { START(sink__V59, _M__sTextBreak);
                                LITERAL(sink__V59,  "\n" ); END(sink__V59, _M__sTextBreak); }
                              { START(sink__V59, _M__sTextCons);
                                { START(sink__V59, _M__sTextChars);
                                  LITERAL(sink__V59,  "extern struct _ConstructionDescriptor " );
                                  END(sink__V59, _M__sTextChars); }
                                { START(sink__V59, _M__sTextCons);
                                  { START(sink__V59, _M__sTextEmbed);
                                    { START(sink__V59, _M_AsText);
                                      { START(sink__V59, _M_Descriptor);
                                        COPY(sink__V59, sub__V63);END(sink__V59, _M_Descriptor); }
                                      END(sink__V59, _M_AsText); }
                                    END(sink__V59, _M__sTextEmbed); }
                                  { START(sink__V59, _M__sTextCons);
                                    { START(sink__V59, _M__sTextChars);
                                      LITERAL(sink__V59,  ";" ); END(sink__V59, _M__sTextChars); }
                                    { START(sink__V59, _M__sTextCons);
                                      { START(sink__V59, _M__sTextBreak);
                                        LITERAL(sink__V59,  "\n" ); END(sink__V59, _M__sTextBreak); }
                                      { START(sink__V59, _M__sTextNil);
                                        END(sink__V59, _M__sTextNil); }
                                      END(sink__V59, _M__sTextCons); }
                                    END(sink__V59, _M__sTextCons); }
                                  END(sink__V59, _M__sTextCons); }
                                END(sink__V59, _M__sTextCons); }
                              END(sink__V59, _M__sTextCons); }
                            END(sink__V59, _M__sTextCons); }
                          END(sink__V59, _M__sTextCons); }
                        END(sink__V59, _M__sTextCons); }
                      END(sink__V59, _M__sTextCons); }
                    END(sink__V59, _M__sTextCons); }
                  END(sink__V59, _M__sTextCons); }
                END(sink__V59, _M__sTextCons); }
              END(sink__V59, _M__sTextCons); }
            END(sink__V59, _M__sTextCons); }
          END(sink__V59, _M__sTextCons); }
        END(sink__V59, _M__sTextCons); }
      END(sink__V59, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V59->context, namedP__V64); UNLINK_VariablePropertyLink(sink__V59->context, varP__V65);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Form. */
int conBindOffs_M_H_Form[] = {0 , 0};
char *nameFun_M_H_Form(Term term) { return  "H-Form" ; }
struct _ConstructionDescriptor descriptor_M_H_Form = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_H_Form), conBindOffs_M_H_Form, &nameFun_M_H_Form, &step_M_H_Form};

int step_M_H_Form(Sink sink__V66, Term term__V67)
{
  int term__V67_count = LINK_COUNT(term__V67); permitUnusedInt(term__V67_count);
  Term sub__V68 = FORCE(sink__V66->context, SUB(term__V67, 0));
  EnumOf_M_Reified_xForm choice__V69 = (IS_VARIABLE_USE(sub__V68) ? VarOf_M_Reified_xForm : (EnumOf_M_Reified_xForm) TAG(sub__V68));
  switch (choice__V69)
  {
    case Data_M_SORT_SET: { /* Function HEADER-H-Form-1$H-Form$SORT-SET case SORT-SET */
      ASSERT(sink__V66->context, !strcmp(SYMBOL(term__V67),  "H-Form" ));
      Term sub__V70 = SUB(term__V67, 0); permitUnusedTerm(sub__V70); int sub__V70_count = term__V67_count*LINK_COUNT(sub__V70); permitUnusedInt(sub__V70_count);
      CRSX_CHECK_SORT(sink__V66->context, sub__V70, &sort_M_Reified_xForm); ASSERT(sink__V66->context, !strcmp(SYMBOL(sub__V70),  "SORT-SET" ));
      Term sub__V71 = LINK(sink__V66->context, SUB(sub__V70, 0)); int sub__V71_count = sub__V70_count*LINK_COUNT(sub__V71); permitUnusedInt(sub__V71_count);
      CRSX_CHECK_SORT(sink__V66->context, sub__V71, &sort_M_Reified_xSort); /* sub__V71 = &#0-0 */
      Term sub__V72 = LINK(sink__V66->context, SUB(sub__V70, 1)); int sub__V72_count = sub__V70_count*LINK_COUNT(sub__V72); permitUnusedInt(sub__V72_count);
      CRSX_CHECK_SORT(sink__V66->context, sub__V72, &sort_M_Reified_xSort); /* sub__V72 = &#0-1 */
      Term sub__V73 = LINK(sink__V66->context, SUB(sub__V70, 2)); int sub__V73_count = sub__V70_count*LINK_COUNT(sub__V73); permitUnusedInt(sub__V73_count);
      CRSX_CHECK_SORT(sink__V66->context, sub__V73, &sort_M_Reified_xForm); /* sub__V73 = &#0-2 */
      NamedPropertyLink namedP__V74 = LINK_NamedPropertyLink(sink__V66->context, NAMED_PROPERTIES(term__V67));
      VariablePropertyLink varP__V75 = LINK_VariablePropertyLink(sink__V66->context, VARIABLE_PROPERTIES(term__V67));
      UNLINK(sink__V66->context, term__V67);
      ADD_PROPERTIES(sink__V66, LINK_NamedPropertyLink(sink__V66->context, namedP__V74), LINK_VariablePropertyLink(sink__V66->context, varP__V75));
      { START(sink__V66, _M_H_Form_s6);
        COPY(sink__V66, sub__V71);COPY(sink__V66, sub__V72);COPY(sink__V66, sub__V73);END(sink__V66, _M_H_Form_s6); }
      UNLINK_NamedPropertyLink(sink__V66->context, namedP__V74); UNLINK_VariablePropertyLink(sink__V66->context, varP__V75);
      
      return 1;
    break; } case Data_M_SORT_ALLOWS_VARIABLES: { /* Function HEADER-H-Form-2$H-Form$SORT-ALLOWS-VARIABLES case SORT-ALLOWS-VARIABLES */
      ASSERT(sink__V66->context, !strcmp(SYMBOL(term__V67),  "H-Form" ));
      Term sub__V76 = SUB(term__V67, 0); permitUnusedTerm(sub__V76); int sub__V76_count = term__V67_count*LINK_COUNT(sub__V76); permitUnusedInt(sub__V76_count);
      CRSX_CHECK_SORT(sink__V66->context, sub__V76, &sort_M_Reified_xForm); ASSERT(sink__V66->context, !strcmp(SYMBOL(sub__V76),  "SORT-ALLOWS-VARIABLES" ));
      NamedPropertyLink namedP__V77 = LINK_NamedPropertyLink(sink__V66->context, NAMED_PROPERTIES(term__V67));
      VariablePropertyLink varP__V78 = LINK_VariablePropertyLink(sink__V66->context, VARIABLE_PROPERTIES(term__V67));
      UNLINK(sink__V66->context, term__V67);
      ADD_PROPERTIES(sink__V66, LINK_NamedPropertyLink(sink__V66->context, namedP__V77), LINK_VariablePropertyLink(sink__V66->context, varP__V78));
      { START(sink__V66, _M_H_Form_s5); END(sink__V66, _M_H_Form_s5); }
      UNLINK_NamedPropertyLink(sink__V66->context, namedP__V77); UNLINK_VariablePropertyLink(sink__V66->context, varP__V78);
      
      return 1;
    break; } case Data_M_FORM: { /* Function HEADER-H-Form-4$H-Form$FORM case FORM */
      ASSERT(sink__V66->context, !strcmp(SYMBOL(term__V67),  "H-Form" ));
      Term sub__V79 = SUB(term__V67, 0); permitUnusedTerm(sub__V79); int sub__V79_count = term__V67_count*LINK_COUNT(sub__V79); permitUnusedInt(sub__V79_count);
      CRSX_CHECK_SORT(sink__V66->context, sub__V79, &sort_M_Reified_xForm); ASSERT(sink__V66->context, !strcmp(SYMBOL(sub__V79),  "FORM" ));
      Term sub__V80 = LINK(sink__V66->context, SUB(sub__V79, 0)); int sub__V80_count = sub__V79_count*LINK_COUNT(sub__V80); permitUnusedInt(sub__V80_count);
      /* sub__V80 = &#0-0 */
      Term sub__V81 = LINK(sink__V66->context, SUB(sub__V79, 1)); int sub__V81_count = sub__V79_count*LINK_COUNT(sub__V81); permitUnusedInt(sub__V81_count);
      /* sub__V81 = &#0-1 */
      NamedPropertyLink namedP__V82 = LINK_NamedPropertyLink(sink__V66->context, NAMED_PROPERTIES(term__V67));
      VariablePropertyLink varP__V83 = LINK_VariablePropertyLink(sink__V66->context, VARIABLE_PROPERTIES(term__V67));
      UNLINK(sink__V66->context, term__V67);
      ADD_PROPERTIES(sink__V66, LINK_NamedPropertyLink(sink__V66->context, namedP__V82), LINK_VariablePropertyLink(sink__V66->context, varP__V83));
      { START(sink__V66, _M_H_Form_s2);
        COPY(sink__V66, sub__V81);COPY(sink__V66, sub__V80);END(sink__V66, _M_H_Form_s2); }
      UNLINK_NamedPropertyLink(sink__V66->context, namedP__V82); UNLINK_VariablePropertyLink(sink__V66->context, varP__V83);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION ComputeHeader. */
int conBindOffs_M_ComputeHeader[] = {0 , 0};
char *nameFun_M_ComputeHeader(Term term) { return  "ComputeHeader" ; }
struct _ConstructionDescriptor descriptor_M_ComputeHeader = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_ComputeHeader), conBindOffs_M_ComputeHeader, &nameFun_M_ComputeHeader, &step_M_ComputeHeader};

int step_M_ComputeHeader(Sink sink__V84, Term term__V85)
{
  int term__V85_count = LINK_COUNT(term__V85); permitUnusedInt(term__V85_count);
  Term sub__V86 = FORCE(sink__V84->context, SUB(term__V85, 0));
  EnumOf_M_Reify_xCRSX choice__V87 = (IS_VARIABLE_USE(sub__V86) ? VarOf_M_Reify_xCRSX : (EnumOf_M_Reify_xCRSX) TAG(sub__V86));
  switch (choice__V87)
  {
    case Data_M_CRSX: { /* Function HEADER-ComputeHeader-1$ComputeHeader$CRSX case CRSX */
      ASSERT(sink__V84->context, !strcmp(SYMBOL(term__V85),  "ComputeHeader" ));
      Term sub__V88 = SUB(term__V85, 0); permitUnusedTerm(sub__V88); int sub__V88_count = term__V85_count*LINK_COUNT(sub__V88); permitUnusedInt(sub__V88_count);
      CRSX_CHECK_SORT(sink__V84->context, sub__V88, &sort_M_Reify_xCRSX); ASSERT(sink__V84->context, !strcmp(SYMBOL(sub__V88),  "CRSX" ));
      Term sub__V89 = LINK(sink__V84->context, SUB(sub__V88, 0)); int sub__V89_count = sub__V88_count*LINK_COUNT(sub__V89); permitUnusedInt(sub__V89_count);
      /* sub__V89 = &#0-0 */
      Term sub__V90 = LINK(sink__V84->context, SUB(sub__V88, 1)); int sub__V90_count = sub__V88_count*LINK_COUNT(sub__V90); permitUnusedInt(sub__V90_count);
      /* sub__V90 = &#0-1 */
      NamedPropertyLink namedP__V91 = LINK_NamedPropertyLink(sink__V84->context, NAMED_PROPERTIES(term__V85));
      VariablePropertyLink varP__V92 = LINK_VariablePropertyLink(sink__V84->context, VARIABLE_PROPERTIES(term__V85));
      UNLINK(sink__V84->context, term__V85);
      ADD_PROPERTIES(sink__V84, LINK_NamedPropertyLink(sink__V84->context, namedP__V91), LINK_VariablePropertyLink(sink__V84->context, varP__V92));
      { START(sink__V84, _M_ComputeHeader_s1);
        COPY(sink__V84, sub__V89);COPY(sink__V84, sub__V90);END(sink__V84, _M_ComputeHeader_s1); }
      UNLINK_NamedPropertyLink(sink__V84->context, namedP__V91); UNLINK_VariablePropertyLink(sink__V84->context, varP__V92);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION H-Declaration. */
int conBindOffs_M_H_Declaration[] = {0 , 0};
char *nameFun_M_H_Declaration(Term term) { return  "H-Declaration" ; }
struct _ConstructionDescriptor descriptor_M_H_Declaration = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_H_Declaration), conBindOffs_M_H_Declaration, &nameFun_M_H_Declaration, &step_M_H_Declaration};

int step_M_H_Declaration(Sink sink__V93, Term term__V94)
{
  int term__V94_count = LINK_COUNT(term__V94); permitUnusedInt(term__V94_count);
  Term sub__V95 = FORCE(sink__V93->context, SUB(term__V94, 0));
  EnumOf_M_Reified_xDeclaration choice__V96 = (IS_VARIABLE_USE(sub__V95) ? VarOf_M_Reified_xDeclaration : (EnumOf_M_Reified_xDeclaration) TAG(sub__V95));
  switch (choice__V96)
  {
    case Data_M_DATA: { /* Function HEADER-Data$H-Declaration$DATA case DATA */
      ASSERT(sink__V93->context, !strcmp(SYMBOL(term__V94),  "H-Declaration" ));
      Term sub__V97 = SUB(term__V94, 0); permitUnusedTerm(sub__V97); int sub__V97_count = term__V94_count*LINK_COUNT(sub__V97); permitUnusedInt(sub__V97_count);
      CRSX_CHECK_SORT(sink__V93->context, sub__V97, &sort_M_Reified_xDeclaration); ASSERT(sink__V93->context, !strcmp(SYMBOL(sub__V97),  "DATA" ));
      Term sub__V98 = LINK(sink__V93->context, SUB(sub__V97, 0)); int sub__V98_count = sub__V97_count*LINK_COUNT(sub__V98); permitUnusedInt(sub__V98_count);
      CRSX_CHECK_SORT(sink__V93->context, sub__V98, &sort_M_Reified_xSort); /* sub__V98 = &#0-0 */
      Term sub__V99 = LINK(sink__V93->context, SUB(sub__V97, 1)); int sub__V99_count = sub__V97_count*LINK_COUNT(sub__V99); permitUnusedInt(sub__V99_count);
      /* sub__V99 = &#0-1 */
      NamedPropertyLink namedP__V100 = LINK_NamedPropertyLink(sink__V93->context, NAMED_PROPERTIES(term__V94));
      VariablePropertyLink varP__V101 = LINK_VariablePropertyLink(sink__V93->context, VARIABLE_PROPERTIES(term__V94));
      UNLINK(sink__V93->context, term__V94);
      ADD_PROPERTIES(sink__V93, LINK_NamedPropertyLink(sink__V93->context, namedP__V100), LINK_VariablePropertyLink(sink__V93->context, varP__V101));
      { START(sink__V93, _M_H_Declaration_s1);
        COPY(sink__V93, sub__V98);COPY(sink__V93, sub__V99);END(sink__V93, _M_H_Declaration_s1); }
      UNLINK_NamedPropertyLink(sink__V93->context, namedP__V100); UNLINK_VariablePropertyLink(sink__V93->context, varP__V101);
      
      return 1;
    break; } case Data_M_FUNCTION: { /* Function HEADER-Function$H-Declaration$FUNCTION case FUNCTION */
      ASSERT(sink__V93->context, !strcmp(SYMBOL(term__V94),  "H-Declaration" ));
      Term sub__V102 = SUB(term__V94, 0); permitUnusedTerm(sub__V102); int sub__V102_count = term__V94_count*LINK_COUNT(sub__V102); permitUnusedInt(sub__V102_count);
      CRSX_CHECK_SORT(sink__V93->context, sub__V102, &sort_M_Reified_xDeclaration); ASSERT(sink__V93->context, !strcmp(SYMBOL(sub__V102),  "FUNCTION" ));
      Term sub__V103 = LINK(sink__V93->context, SUB(sub__V102, 0)); int sub__V103_count = sub__V102_count*LINK_COUNT(sub__V103); permitUnusedInt(sub__V103_count);
      /* sub__V103 = &#0-0 */
      Term sub__V104 = LINK(sink__V93->context, SUB(sub__V102, 1)); int sub__V104_count = sub__V102_count*LINK_COUNT(sub__V104); permitUnusedInt(sub__V104_count);
      /* sub__V104 = &#0-1 */
      Term sub__V105 = LINK(sink__V93->context, SUB(sub__V102, 2)); int sub__V105_count = sub__V102_count*LINK_COUNT(sub__V105); permitUnusedInt(sub__V105_count);
      /* sub__V105 = &#0-2 */
      Term sub__V106 = LINK(sink__V93->context, SUB(sub__V102, 3)); int sub__V106_count = sub__V102_count*LINK_COUNT(sub__V106); permitUnusedInt(sub__V106_count);
      /* sub__V106 = &#0-3 */
      Term sub__V107 = LINK(sink__V93->context, SUB(sub__V102, 4)); int sub__V107_count = sub__V102_count*LINK_COUNT(sub__V107); permitUnusedInt(sub__V107_count);
      /* sub__V107 = &#0-4 */
      Term sub__V108 = LINK(sink__V93->context, SUB(sub__V102, 5)); int sub__V108_count = sub__V102_count*LINK_COUNT(sub__V108); permitUnusedInt(sub__V108_count);
      CRSX_CHECK_SORT(sink__V93->context, sub__V108, &sort_M_Reified_xSort); /* sub__V108 = &#0-5 */
      Term sub__V109 = LINK(sink__V93->context, SUB(sub__V102, 6)); int sub__V109_count = sub__V102_count*LINK_COUNT(sub__V109); permitUnusedInt(sub__V109_count);
      /* sub__V109 = &#0-6 */
      NamedPropertyLink namedP__V110 = LINK_NamedPropertyLink(sink__V93->context, NAMED_PROPERTIES(term__V94));
      VariablePropertyLink varP__V111 = LINK_VariablePropertyLink(sink__V93->context, VARIABLE_PROPERTIES(term__V94));
      UNLINK(sink__V93->context, term__V94);
      ADD_PROPERTIES(sink__V93, LINK_NamedPropertyLink(sink__V93->context, namedP__V110), LINK_VariablePropertyLink(sink__V93->context, varP__V111));
      { START(sink__V93, _M_H_Declaration_s2);
        COPY(sink__V93, sub__V103);COPY(sink__V93, sub__V104);COPY(sink__V93, sub__V105);COPY(sink__V93, sub__V106);COPY(sink__V93, sub__V107);COPY(sink__V93, sub__V108);COPY(sink__V93, sub__V109);END(sink__V93, _M_H_Declaration_s2); }
      UNLINK_NamedPropertyLink(sink__V93->context, namedP__V110); UNLINK_VariablePropertyLink(sink__V93->context, varP__V111);
      
      return 1;
    break; } case Data_M_POLYMORPHIC: { /* Function HEADER-Polymorphic$H-Declaration$POLYMORPHIC case POLYMORPHIC */
      ASSERT(sink__V93->context, !strcmp(SYMBOL(term__V94),  "H-Declaration" ));
      Term sub__V112 = SUB(term__V94, 0); permitUnusedTerm(sub__V112); int sub__V112_count = term__V94_count*LINK_COUNT(sub__V112); permitUnusedInt(sub__V112_count);
      CRSX_CHECK_SORT(sink__V93->context, sub__V112, &sort_M_Reified_xDeclaration); ASSERT(sink__V93->context, !strcmp(SYMBOL(sub__V112),  "POLYMORPHIC" ));
      Variable y__V113 = BINDER(sub__V112,0,0); if (sub__V112_count <= 1) UNBIND(y__V113);
      Term sub__V114 = LINK(sink__V93->context, SUB(sub__V112, 0)); int sub__V114_count = sub__V112_count*LINK_COUNT(sub__V114); permitUnusedInt(sub__V114_count);
      CRSX_CHECK_SORT(sink__V93->context, sub__V114, &sort_M_Reified_xDeclaration); /* sub__V114 = &#0-0 */
      NamedPropertyLink namedP__V115 = LINK_NamedPropertyLink(sink__V93->context, NAMED_PROPERTIES(term__V94));
      VariablePropertyLink varP__V116 = LINK_VariablePropertyLink(sink__V93->context, VARIABLE_PROPERTIES(term__V94));
      UNLINK(sink__V93->context, term__V94);
      ADD_PROPERTIES(sink__V93, LINK_NamedPropertyLink(sink__V93->context, namedP__V115), LINK_VariablePropertyLink(sink__V93->context, varP__V116));
      { START(sink__V93, _M_H_Declaration_s3);
        { if (!IS_BOUND(y__V113)) { REBIND(y__V113);
            Variable binds__V117[1] = {y__V113}; BINDS(sink__V93, 1, binds__V117);
            COPY(sink__V93, sub__V114); /* REUSED SUBSTITUTION */  }
          else { Variable b__V118 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V93->context,"b__V118");
            Variable binds__V119[1] = {b__V118}; BINDS(sink__V93, 1, binds__V119);
            {
              Term arg__V120;
              { Sink buf__V121 = ALLOCA_BUFFER(sink__V93->context);
                USE(buf__V121, b__V118); arg__V120 = BUFFER_TERM(buf__V121); FREE_BUFFER(buf__V121); }
              Variable vars__V122[1] = {y__V113};
              Term args__V123[1] = {arg__V120};
              struct _SubstitutionFrame substitution__V124 = {NULL, 0, 1, vars__V122, args__V123, NULL};
              SUBSTITUTE(sink__V93, sub__V114, &substitution__V124); }
                }
           }
        END(sink__V93, _M_H_Declaration_s3); }
      UNLINK_NamedPropertyLink(sink__V93->context, namedP__V115); UNLINK_VariablePropertyLink(sink__V93->context, varP__V116);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION H-Declarations. */
int conBindOffs_M_H_Declarations[] = {0 , 0};
char *nameFun_M_H_Declarations(Term term) { return  "H-Declarations" ; }
struct _ConstructionDescriptor descriptor_M_H_Declarations = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_H_Declarations), conBindOffs_M_H_Declarations, &nameFun_M_H_Declarations, &step_M_H_Declarations};

int step_M_H_Declarations(Sink sink__V125, Term term__V126)
{
  int term__V126_count = LINK_COUNT(term__V126); permitUnusedInt(term__V126_count);
  Term sub__V127 = FORCE(sink__V125->context, SUB(term__V126, 0));
  EnumOf_M__sList choice__V128 = (IS_VARIABLE_USE(sub__V127) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V127));
  switch (choice__V128)
  {
    case Data_M__sCons: { /* Function HEADER-H-Declarations-1$H-Declarations$$Cons case $Cons */
      ASSERT(sink__V125->context, !strcmp(SYMBOL(term__V126),  "H-Declarations" ));
      Term sub__V129 = SUB(term__V126, 0); permitUnusedTerm(sub__V129); int sub__V129_count = term__V126_count*LINK_COUNT(sub__V129); permitUnusedInt(sub__V129_count);
      ASSERT(sink__V125->context, !strcmp(SYMBOL(sub__V129),  "$Cons" ));
      Term sub__V130 = LINK(sink__V125->context, SUB(sub__V129, 0)); int sub__V130_count = sub__V129_count*LINK_COUNT(sub__V130); permitUnusedInt(sub__V130_count);
      /* sub__V130 = &#0-0 */
      Term sub__V131 = LINK(sink__V125->context, SUB(sub__V129, 1)); int sub__V131_count = sub__V129_count*LINK_COUNT(sub__V131); permitUnusedInt(sub__V131_count);
      /* sub__V131 = &#0-1 */
      NamedPropertyLink namedP__V132 = LINK_NamedPropertyLink(sink__V125->context, NAMED_PROPERTIES(term__V126));
      VariablePropertyLink varP__V133 = LINK_VariablePropertyLink(sink__V125->context, VARIABLE_PROPERTIES(term__V126));
      UNLINK(sink__V125->context, term__V126);
      ADD_PROPERTIES(sink__V125, LINK_NamedPropertyLink(sink__V125->context, namedP__V132), LINK_VariablePropertyLink(sink__V125->context, varP__V133));
      { START(sink__V125, _M_H_Declarations_s1);
        COPY(sink__V125, sub__V130);COPY(sink__V125, sub__V131);END(sink__V125, _M_H_Declarations_s1); }
      UNLINK_NamedPropertyLink(sink__V125->context, namedP__V132); UNLINK_VariablePropertyLink(sink__V125->context, varP__V133);
      
      return 1;
    break; } case Data_M__sNil: { /* Function HEADER-H-Declarations-2$H-Declarations$$Nil case $Nil */
      ASSERT(sink__V125->context, !strcmp(SYMBOL(term__V126),  "H-Declarations" ));
      Term sub__V134 = SUB(term__V126, 0); permitUnusedTerm(sub__V134); int sub__V134_count = term__V126_count*LINK_COUNT(sub__V134); permitUnusedInt(sub__V134_count);
      ASSERT(sink__V125->context, !strcmp(SYMBOL(sub__V134),  "$Nil" ));
      NamedPropertyLink namedP__V135 = LINK_NamedPropertyLink(sink__V125->context, NAMED_PROPERTIES(term__V126));
      VariablePropertyLink varP__V136 = LINK_VariablePropertyLink(sink__V125->context, VARIABLE_PROPERTIES(term__V126));
      UNLINK(sink__V125->context, term__V126);
      ADD_PROPERTIES(sink__V125, LINK_NamedPropertyLink(sink__V125->context, namedP__V135), LINK_VariablePropertyLink(sink__V125->context, varP__V136));
      { START(sink__V125, _M_H_Declarations_s2);
        END(sink__V125, _M_H_Declarations_s2); }
      UNLINK_NamedPropertyLink(sink__V125->context, namedP__V135); UNLINK_VariablePropertyLink(sink__V125->context, varP__V136);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION H-Declarations$2. */
int conBindOffs_M_H_Declarations_s2[] = {0};
char *nameFun_M_H_Declarations_s2(Term term) { return  "H-Declarations$2" ; }
struct _ConstructionDescriptor descriptor_M_H_Declarations_s2 = {&sort_M_Reified_xVariable, 0, 0, sizeof(STRUCT_Con_M_H_Declarations_s2), conBindOffs_M_H_Declarations_s2, &nameFun_M_H_Declarations_s2, &step_M_H_Declarations_s2};

int step_M_H_Declarations_s2(Sink sink__V137, Term term__V138)
{
  int term__V138_count = LINK_COUNT(term__V138); permitUnusedInt(term__V138_count);
  do {
    /* Contraction rule HEADER-H-Declarations-2. */
    ASSERT(sink__V137->context, !strcmp(SYMBOL(term__V138),  "H-Declarations$2" ));
    NamedPropertyLink namedP__V139 = LINK_NamedPropertyLink(sink__V137->context, NAMED_PROPERTIES(term__V138));
    VariablePropertyLink varP__V140 = LINK_VariablePropertyLink(sink__V137->context, VARIABLE_PROPERTIES(term__V138));
    UNLINK(sink__V137->context, term__V138);
    { START(sink__V137, _M__sTextNil); END(sink__V137, _M__sTextNil); }
    UNLINK_NamedPropertyLink(sink__V137->context, namedP__V139); UNLINK_VariablePropertyLink(sink__V137->context, varP__V140);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Declarations$1. */
int conBindOffs_M_H_Declarations_s1[] = {0 , 0 , 0};
char *nameFun_M_H_Declarations_s1(Term term) { return  "H-Declarations$1" ; }
struct _ConstructionDescriptor descriptor_M_H_Declarations_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_H_Declarations_s1), conBindOffs_M_H_Declarations_s1, &nameFun_M_H_Declarations_s1, &step_M_H_Declarations_s1};

int step_M_H_Declarations_s1(Sink sink__V141, Term term__V142)
{
  int term__V142_count = LINK_COUNT(term__V142); permitUnusedInt(term__V142_count);
  do {
    /* Contraction rule HEADER-H-Declarations-1. */
    ASSERT(sink__V141->context, !strcmp(SYMBOL(term__V142),  "H-Declarations$1" ));
    Term sub__V143 = LINK(sink__V141->context, SUB(term__V142, 0)); int sub__V143_count = term__V142_count*LINK_COUNT(sub__V143); permitUnusedInt(sub__V143_count);
    /* sub__V143 = &#11 */
    Term sub__V144 = LINK(sink__V141->context, SUB(term__V142, 1)); int sub__V144_count = term__V142_count*LINK_COUNT(sub__V144); permitUnusedInt(sub__V144_count);
    /* sub__V144 = &#12 */
    NamedPropertyLink namedP__V145 = LINK_NamedPropertyLink(sink__V141->context, NAMED_PROPERTIES(term__V142));
    VariablePropertyLink varP__V146 = LINK_VariablePropertyLink(sink__V141->context, VARIABLE_PROPERTIES(term__V142));
    UNLINK(sink__V141->context, term__V142);
    { START(sink__V141, _M__sTextCons);
      { START(sink__V141, _M__sTextEmbed);
        { START(sink__V141, _M_AsText);
          { START(sink__V141, _M_H_Declaration);
            COPY(sink__V141, sub__V143);END(sink__V141, _M_H_Declaration); }
          END(sink__V141, _M_AsText); }
        END(sink__V141, _M__sTextEmbed); }
      { START(sink__V141, _M__sTextCons);
        { START(sink__V141, _M__sTextEmbed);
          { START(sink__V141, _M_AsText);
            { START(sink__V141, _M_H_Declarations);
              COPY(sink__V141, sub__V144);END(sink__V141, _M_H_Declarations); }
            END(sink__V141, _M_AsText); }
          END(sink__V141, _M__sTextEmbed); }
        { START(sink__V141, _M__sTextNil);
          END(sink__V141, _M__sTextNil); }
        END(sink__V141, _M__sTextCons); }
      END(sink__V141, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V141->context, namedP__V145); UNLINK_VariablePropertyLink(sink__V141->context, varP__V146);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Data. */
int conBindOffs_M_H_Data[] = {0 , 0 , 0};
char *nameFun_M_H_Data(Term term) { return  "H-Data" ; }
struct _ConstructionDescriptor descriptor_M_H_Data = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_H_Data), conBindOffs_M_H_Data, &nameFun_M_H_Data, &step_M_H_Data};

int step_M_H_Data(Sink sink__V147, Term term__V148)
{
  int term__V148_count = LINK_COUNT(term__V148); permitUnusedInt(term__V148_count);
  Term sub__V149 = FORCE(sink__V147->context, SUB(term__V148, 0));
  EnumOf_M_Reified_xSort choice__V150 = (IS_VARIABLE_USE(sub__V149) ? VarOf_M_Reified_xSort : (EnumOf_M_Reified_xSort) TAG(sub__V149));
  switch (choice__V150)
  {
    case Data_M_SORT: { /* Function HEADER-H-Data-1$H-Data$SORT case SORT */
      ASSERT(sink__V147->context, !strcmp(SYMBOL(term__V148),  "H-Data" ));
      Term sub__V151 = SUB(term__V148, 0); permitUnusedTerm(sub__V151); int sub__V151_count = term__V148_count*LINK_COUNT(sub__V151); permitUnusedInt(sub__V151_count);
      CRSX_CHECK_SORT(sink__V147->context, sub__V151, &sort_M_Reified_xSort); ASSERT(sink__V147->context, !strcmp(SYMBOL(sub__V151),  "SORT" ));
      Term sub__V152 = LINK(sink__V147->context, SUB(sub__V151, 0)); int sub__V152_count = sub__V151_count*LINK_COUNT(sub__V152); permitUnusedInt(sub__V152_count);
      /* sub__V152 = &#0-0 */
      Term sub__V153 = LINK(sink__V147->context, SUB(sub__V151, 1)); int sub__V153_count = sub__V151_count*LINK_COUNT(sub__V153); permitUnusedInt(sub__V153_count);
      /* sub__V153 = &#0-1 */
      Term sub__V154 = LINK(sink__V147->context, SUB(term__V148, 1)); int sub__V154_count = term__V148_count*LINK_COUNT(sub__V154); permitUnusedInt(sub__V154_count);
      /* sub__V154 = &#2 */
      NamedPropertyLink namedP__V155 = LINK_NamedPropertyLink(sink__V147->context, NAMED_PROPERTIES(term__V148));
      VariablePropertyLink varP__V156 = LINK_VariablePropertyLink(sink__V147->context, VARIABLE_PROPERTIES(term__V148));
      UNLINK(sink__V147->context, term__V148);
      ADD_PROPERTIES(sink__V147, LINK_NamedPropertyLink(sink__V147->context, namedP__V155), LINK_VariablePropertyLink(sink__V147->context, varP__V156));
      { START(sink__V147, _M_H_Data_s1);
        COPY(sink__V147, sub__V152);COPY(sink__V147, sub__V153);COPY(sink__V147, sub__V154);END(sink__V147, _M_H_Data_s1); }
      UNLINK_NamedPropertyLink(sink__V147->context, namedP__V155); UNLINK_VariablePropertyLink(sink__V147->context, varP__V156);
      
      return 1;
    break; } case Data_M_SORT_PROPERTY: { /* Function HEADER-H-Data-2$H-Data$SORT-PROPERTY case SORT-PROPERTY */
      ASSERT(sink__V147->context, !strcmp(SYMBOL(term__V148),  "H-Data" ));
      Term sub__V157 = SUB(term__V148, 0); permitUnusedTerm(sub__V157); int sub__V157_count = term__V148_count*LINK_COUNT(sub__V157); permitUnusedInt(sub__V157_count);
      CRSX_CHECK_SORT(sink__V147->context, sub__V157, &sort_M_Reified_xSort); ASSERT(sink__V147->context, !strcmp(SYMBOL(sub__V157),  "SORT-PROPERTY" ));
      Term sub__V158 = LINK(sink__V147->context, SUB(sub__V157, 0)); int sub__V158_count = sub__V157_count*LINK_COUNT(sub__V158); permitUnusedInt(sub__V158_count);
      CRSX_CHECK_SORT(sink__V147->context, sub__V158, &sort_M_Reified_xSort); /* sub__V158 = &#0-0 */
      Term sub__V159 = LINK(sink__V147->context, SUB(sub__V157, 1)); int sub__V159_count = sub__V157_count*LINK_COUNT(sub__V159); permitUnusedInt(sub__V159_count);
      CRSX_CHECK_SORT(sink__V147->context, sub__V159, &sort_M_Reified_xSort); /* sub__V159 = &#0-1 */
      Term sub__V160 = LINK(sink__V147->context, SUB(sub__V157, 2)); int sub__V160_count = sub__V157_count*LINK_COUNT(sub__V160); permitUnusedInt(sub__V160_count);
      CRSX_CHECK_SORT(sink__V147->context, sub__V160, &sort_M_Reified_xSort); /* sub__V160 = &#0-2 */
      Term sub__V161 = LINK(sink__V147->context, SUB(term__V148, 1)); int sub__V161_count = term__V148_count*LINK_COUNT(sub__V161); permitUnusedInt(sub__V161_count);
      /* sub__V161 = &#3 */
      NamedPropertyLink namedP__V162 = LINK_NamedPropertyLink(sink__V147->context, NAMED_PROPERTIES(term__V148));
      VariablePropertyLink varP__V163 = LINK_VariablePropertyLink(sink__V147->context, VARIABLE_PROPERTIES(term__V148));
      UNLINK(sink__V147->context, term__V148);
      ADD_PROPERTIES(sink__V147, LINK_NamedPropertyLink(sink__V147->context, namedP__V162), LINK_VariablePropertyLink(sink__V147->context, varP__V163));
      { START(sink__V147, _M_H_Data_s2);
        COPY(sink__V147, sub__V158);COPY(sink__V147, sub__V159);COPY(sink__V147, sub__V160);COPY(sink__V147, sub__V161);END(sink__V147, _M_H_Data_s2); }
      UNLINK_NamedPropertyLink(sink__V147->context, namedP__V162); UNLINK_VariablePropertyLink(sink__V147->context, varP__V163);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION H-Declaration$3. */
int conBindOffs_M_H_Declaration_s3[] = {0 , 1};
char *nameFun_M_H_Declaration_s3(Term term) { return  "H-Declaration$3" ; }
struct _ConstructionDescriptor descriptor_M_H_Declaration_s3 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_H_Declaration_s3), conBindOffs_M_H_Declaration_s3, &nameFun_M_H_Declaration_s3, &step_M_H_Declaration_s3};

int step_M_H_Declaration_s3(Sink sink__V164, Term term__V165)
{
  int term__V165_count = LINK_COUNT(term__V165); permitUnusedInt(term__V165_count);
  do {
    /* Contraction rule HEADER-Polymorphic. */
    ASSERT(sink__V164->context, !strcmp(SYMBOL(term__V165),  "H-Declaration$3" ));
    Variable x__V166 = BINDER(term__V165,0,0); if (term__V165_count <= 1) UNBIND(x__V166);
    Term sub__V167 = LINK(sink__V164->context, SUB(term__V165, 0)); int sub__V167_count = term__V165_count*LINK_COUNT(sub__V167); permitUnusedInt(sub__V167_count);
    CRSX_CHECK_SORT(sink__V164->context, sub__V167, &sort_M_Reified_xDeclaration); /* sub__V167 = &#11 */
    Variable y__V168 = x__V166; permitUnusedVariable(y__V168);
    NamedPropertyLink namedP__V169 = LINK_NamedPropertyLink(sink__V164->context, NAMED_PROPERTIES(term__V165));
    VariablePropertyLink varP__V170 = LINK_VariablePropertyLink(sink__V164->context, VARIABLE_PROPERTIES(term__V165));
    UNLINK(sink__V164->context, term__V165);
    { START(sink__V164, _M_H_Declaration);
      COPY(sink__V164, sub__V167); /* REUSED SUBSTITUTION */ END(sink__V164, _M_H_Declaration); }
    UNLINK_NamedPropertyLink(sink__V164->context, namedP__V169); UNLINK_VariablePropertyLink(sink__V164->context, varP__V170);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Declaration$2. */
int conBindOffs_M_H_Declaration_s2[] = {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0};
char *nameFun_M_H_Declaration_s2(Term term) { return  "H-Declaration$2" ; }
struct _ConstructionDescriptor descriptor_M_H_Declaration_s2 = {&sort_M_Reified_xVariable, 0, 7, sizeof(STRUCT_Con_M_H_Declaration_s2), conBindOffs_M_H_Declaration_s2, &nameFun_M_H_Declaration_s2, &step_M_H_Declaration_s2};

int step_M_H_Declaration_s2(Sink sink__V171, Term term__V172)
{
  int term__V172_count = LINK_COUNT(term__V172); permitUnusedInt(term__V172_count);
  do {
    /* Contraction rule HEADER-Function. */
    ASSERT(sink__V171->context, !strcmp(SYMBOL(term__V172),  "H-Declaration$2" ));
    Term sub__V173 = LINK(sink__V171->context, SUB(term__V172, 0)); int sub__V173_count = term__V172_count*LINK_COUNT(sub__V173); permitUnusedInt(sub__V173_count);
    /* sub__V173 = &#11 */
    Term sub__V174 = LINK(sink__V171->context, SUB(term__V172, 1)); int sub__V174_count = term__V172_count*LINK_COUNT(sub__V174); permitUnusedInt(sub__V174_count);
    /* sub__V174 = &#12 */
    Term sub__V175 = LINK(sink__V171->context, SUB(term__V172, 2)); int sub__V175_count = term__V172_count*LINK_COUNT(sub__V175); permitUnusedInt(sub__V175_count);
    /* sub__V175 = &#13 */
    Term sub__V176 = LINK(sink__V171->context, SUB(term__V172, 3)); int sub__V176_count = term__V172_count*LINK_COUNT(sub__V176); permitUnusedInt(sub__V176_count);
    /* sub__V176 = &#14 */
    Term sub__V177 = LINK(sink__V171->context, SUB(term__V172, 4)); int sub__V177_count = term__V172_count*LINK_COUNT(sub__V177); permitUnusedInt(sub__V177_count);
    /* sub__V177 = &#15 */
    Term sub__V178 = LINK(sink__V171->context, SUB(term__V172, 5)); int sub__V178_count = term__V172_count*LINK_COUNT(sub__V178); permitUnusedInt(sub__V178_count);
    CRSX_CHECK_SORT(sink__V171->context, sub__V178, &sort_M_Reified_xSort); /* sub__V178 = &#16 */
    Term sub__V179 = LINK(sink__V171->context, SUB(term__V172, 6)); int sub__V179_count = term__V172_count*LINK_COUNT(sub__V179); permitUnusedInt(sub__V179_count);
    /* sub__V179 = &#17 */
    NamedPropertyLink namedP__V180 = LINK_NamedPropertyLink(sink__V171->context, NAMED_PROPERTIES(term__V172));
    VariablePropertyLink varP__V181 = LINK_VariablePropertyLink(sink__V171->context, VARIABLE_PROPERTIES(term__V172));
    UNLINK(sink__V171->context, term__V172);
    { START(sink__V171, _M_H_Function);
      COPY(sink__V171, sub__V173);COPY(sink__V171, sub__V174);COPY(sink__V171, sub__V175);COPY(sink__V171, sub__V176);COPY(sink__V171, sub__V177);COPY(sink__V171, sub__V178);COPY(sink__V171, sub__V179);END(sink__V171, _M_H_Function); }
    UNLINK_NamedPropertyLink(sink__V171->context, namedP__V180); UNLINK_VariablePropertyLink(sink__V171->context, varP__V181);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Declaration$1. */
int conBindOffs_M_H_Declaration_s1[] = {0 , 0 , 0};
char *nameFun_M_H_Declaration_s1(Term term) { return  "H-Declaration$1" ; }
struct _ConstructionDescriptor descriptor_M_H_Declaration_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_H_Declaration_s1), conBindOffs_M_H_Declaration_s1, &nameFun_M_H_Declaration_s1, &step_M_H_Declaration_s1};

int step_M_H_Declaration_s1(Sink sink__V182, Term term__V183)
{
  int term__V183_count = LINK_COUNT(term__V183); permitUnusedInt(term__V183_count);
  do {
    /* Contraction rule HEADER-Data. */
    ASSERT(sink__V182->context, !strcmp(SYMBOL(term__V183),  "H-Declaration$1" ));
    Term sub__V184 = LINK(sink__V182->context, SUB(term__V183, 0)); int sub__V184_count = term__V183_count*LINK_COUNT(sub__V184); permitUnusedInt(sub__V184_count);
    CRSX_CHECK_SORT(sink__V182->context, sub__V184, &sort_M_Reified_xSort); /* sub__V184 = &#11 */
    Term sub__V185 = LINK(sink__V182->context, SUB(term__V183, 1)); int sub__V185_count = term__V183_count*LINK_COUNT(sub__V185); permitUnusedInt(sub__V185_count);
    /* sub__V185 = &#12 */
    NamedPropertyLink namedP__V186 = LINK_NamedPropertyLink(sink__V182->context, NAMED_PROPERTIES(term__V183));
    VariablePropertyLink varP__V187 = LINK_VariablePropertyLink(sink__V182->context, VARIABLE_PROPERTIES(term__V183));
    UNLINK(sink__V182->context, term__V183);
    { START(sink__V182, _M_H_Data);
      COPY(sink__V182, sub__V184);COPY(sink__V182, sub__V185);END(sink__V182, _M_H_Data); }
    UNLINK_NamedPropertyLink(sink__V182->context, namedP__V186); UNLINK_VariablePropertyLink(sink__V182->context, varP__V187);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Function. */
int conBindOffs_M_H_Function[] = {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0};
char *nameFun_M_H_Function(Term term) { return  "H-Function" ; }
struct _ConstructionDescriptor descriptor_M_H_Function = {&sort_M_Reified_xVariable, 0, 7, sizeof(STRUCT_Con_M_H_Function), conBindOffs_M_H_Function, &nameFun_M_H_Function, &step_M_H_Function};

int step_M_H_Function(Sink sink__V188, Term term__V189)
{
  int term__V189_count = LINK_COUNT(term__V189); permitUnusedInt(term__V189_count);
  do {
    /* Contraction rule HEADER-H-Function-1. */
    ASSERT(sink__V188->context, !strcmp(SYMBOL(term__V189),  "H-Function" ));
    Term sub__V190 = LINK(sink__V188->context, SUB(term__V189, 0)); int sub__V190_count = term__V189_count*LINK_COUNT(sub__V190); permitUnusedInt(sub__V190_count);
    /* sub__V190 = &#1 */
    Term sub__V191 = SUB(term__V189, 1); permitUnusedTerm(sub__V191); int sub__V191_count = term__V189_count*LINK_COUNT(sub__V191); permitUnusedInt(sub__V191_count);
    /* sub__V191 = &#2 */
    Term sub__V192 = SUB(term__V189, 2); permitUnusedTerm(sub__V192); int sub__V192_count = term__V189_count*LINK_COUNT(sub__V192); permitUnusedInt(sub__V192_count);
    /* sub__V192 = &#3 */
    Term sub__V193 = LINK(sink__V188->context, SUB(term__V189, 3)); int sub__V193_count = term__V189_count*LINK_COUNT(sub__V193); permitUnusedInt(sub__V193_count);
    /* sub__V193 = &#4 */
    Term sub__V194 = LINK(sink__V188->context, SUB(term__V189, 4)); int sub__V194_count = term__V189_count*LINK_COUNT(sub__V194); permitUnusedInt(sub__V194_count);
    /* sub__V194 = &#5 */
    Term sub__V195 = SUB(term__V189, 5); permitUnusedTerm(sub__V195); int sub__V195_count = term__V189_count*LINK_COUNT(sub__V195); permitUnusedInt(sub__V195_count);
    CRSX_CHECK_SORT(sink__V188->context, sub__V195, &sort_M_Reified_xSort); /* sub__V195 = &#6 */
    Term sub__V196 = SUB(term__V189, 6); permitUnusedTerm(sub__V196); int sub__V196_count = term__V189_count*LINK_COUNT(sub__V196); permitUnusedInt(sub__V196_count);
    /* sub__V196 = &#7 */
    NamedPropertyLink namedP__V197 = LINK_NamedPropertyLink(sink__V188->context, NAMED_PROPERTIES(term__V189));
    VariablePropertyLink varP__V198 = LINK_VariablePropertyLink(sink__V188->context, VARIABLE_PROPERTIES(term__V189));
    UNLINK(sink__V188->context, term__V189);
    { START(sink__V188, _M__sTextCons);
      { START(sink__V188, _M__sTextBreak);
        LITERAL(sink__V188,  "\n" ); END(sink__V188, _M__sTextBreak); }
      { START(sink__V188, _M__sTextCons);
        { START(sink__V188, _M__sTextChars);
          LITERAL(sink__V188,  "/* FUNCTION " ); END(sink__V188, _M__sTextChars); }
        { START(sink__V188, _M__sTextCons);
          { START(sink__V188, _M__sTextEmbed);
            { START(sink__V188, _M_AsText);
              { START(sink__V188, _M_COMMENT_xTOKEN);
                COPY(sink__V188, sub__V190);END(sink__V188, _M_COMMENT_xTOKEN); }
              END(sink__V188, _M_AsText); }
            END(sink__V188, _M__sTextEmbed); }
          { START(sink__V188, _M__sTextCons);
            { START(sink__V188, _M__sTextChars);
              LITERAL(sink__V188,  " HEADER DECLARATIONS. */" ); END(sink__V188, _M__sTextChars); }
            { START(sink__V188, _M__sTextCons);
              { START(sink__V188, _M__sTextBreak);
                LITERAL(sink__V188,  "\n" ); END(sink__V188, _M__sTextBreak); }
              { START(sink__V188, _M__sTextCons);
                { START(sink__V188, _M__sTextEmbed);
                  { START(sink__V188, _M_AsText);
                    { START(sink__V188, _M_MapText_s1);
                      COPY(sink__V188, sub__V194);{ Variable x__V199 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V188->context,"x__V199");
                        Variable binds__V200[1] = {x__V199}; BINDS(sink__V188, 1, binds__V200);
                        { START(sink__V188, _M_H_Form);
                          USE(sink__V188, x__V199); END(sink__V188, _M_H_Form); }
                         }
                      END(sink__V188, _M_MapText_s1); }
                    END(sink__V188, _M_AsText); }
                  END(sink__V188, _M__sTextEmbed); }
                { START(sink__V188, _M__sTextCons);
                  { START(sink__V188, _M__sTextChars);
                    LITERAL(sink__V188,  "extern int " ); END(sink__V188, _M__sTextChars); }
                  { START(sink__V188, _M__sTextCons);
                    { START(sink__V188, _M__sTextEmbed);
                      { START(sink__V188, _M_AsText);
                        { START(sink__V188, _M_Step);
                          COPY(sink__V188, sub__V193);END(sink__V188, _M_Step); }
                        END(sink__V188, _M_AsText); }
                      END(sink__V188, _M__sTextEmbed); }
                    { START(sink__V188, _M__sTextCons);
                      { START(sink__V188, _M__sTextChars);
                        LITERAL(sink__V188,  "(Sink,Term);" ); END(sink__V188, _M__sTextChars); }
                      { START(sink__V188, _M__sTextCons);
                        { START(sink__V188, _M__sTextBreak);
                          LITERAL(sink__V188,  "\n" ); END(sink__V188, _M__sTextBreak); }
                        { START(sink__V188, _M__sTextNil);
                          END(sink__V188, _M__sTextNil); }
                        END(sink__V188, _M__sTextCons); }
                      END(sink__V188, _M__sTextCons); }
                    END(sink__V188, _M__sTextCons); }
                  END(sink__V188, _M__sTextCons); }
                END(sink__V188, _M__sTextCons); }
              END(sink__V188, _M__sTextCons); }
            END(sink__V188, _M__sTextCons); }
          END(sink__V188, _M__sTextCons); }
        END(sink__V188, _M__sTextCons); }
      END(sink__V188, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V188->context, namedP__V197); UNLINK_VariablePropertyLink(sink__V188->context, varP__V198);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION ComputeHeader2. */
int conBindOffs_M_ComputeHeader2[] = {0 , 0 , 0 , 0};
char *nameFun_M_ComputeHeader2(Term term) { return  "ComputeHeader2" ; }
struct _ConstructionDescriptor descriptor_M_ComputeHeader2 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_ComputeHeader2), conBindOffs_M_ComputeHeader2, &nameFun_M_ComputeHeader2, &step_M_ComputeHeader2};

int step_M_ComputeHeader2(Sink sink__V201, Term term__V202)
{
  int term__V202_count = LINK_COUNT(term__V202); permitUnusedInt(term__V202_count);
  do {
    /* Contraction rule HEADER-ComputeHeader2-1. */
    ASSERT(sink__V201->context, !strcmp(SYMBOL(term__V202),  "ComputeHeader2" ));
    Term sub__V203 = LINK(sink__V201->context, SUB(term__V202, 0)); int sub__V203_count = term__V202_count*LINK_COUNT(sub__V203); permitUnusedInt(sub__V203_count);
    /* sub__V203 = &#1 */
    Term sub__V204 = LINK(sink__V201->context, SUB(term__V202, 1)); int sub__V204_count = term__V202_count*LINK_COUNT(sub__V204); permitUnusedInt(sub__V204_count);
    /* sub__V204 = &#2 */
    Term sub__V205 = LINK(sink__V201->context, SUB(term__V202, 2)); int sub__V205_count = term__V202_count*LINK_COUNT(sub__V205); permitUnusedInt(sub__V205_count);
    UNLINK_SUB(sink__V201->context, term__V202,  2); NORMALIZE(sink__V201->context, sub__V205); SUB(term__V202,  2) = LINK(sink__V201->context, sub__V205);
    /* sub__V205 = &#3 */
    NamedPropertyLink namedP__V206 = LINK_NamedPropertyLink(sink__V201->context, NAMED_PROPERTIES(term__V202));
    VariablePropertyLink varP__V207 = LINK_VariablePropertyLink(sink__V201->context, VARIABLE_PROPERTIES(term__V202));
    UNLINK(sink__V201->context, term__V202);
    { START(sink__V201, _M__sTextCons);
      { START(sink__V201, _M__sTextChars);
        LITERAL(sink__V201,  "/* C HEADER FOR CRSX " ); END(sink__V201, _M__sTextChars); }
      { START(sink__V201, _M__sTextCons);
        { START(sink__V201, _M__sTextEmbed);
          { START(sink__V201, _M_AsText);
            { START(sink__V201, _M_COMMENT_xTOKEN);
              COPY(sink__V201, LINK(sink__V201->context, sub__V203));END(sink__V201, _M_COMMENT_xTOKEN); }
            END(sink__V201, _M_AsText); }
          END(sink__V201, _M__sTextEmbed); }
        { START(sink__V201, _M__sTextCons);
          { START(sink__V201, _M__sTextChars);
            LITERAL(sink__V201,  " MODULE " ); END(sink__V201, _M__sTextChars); }
          { START(sink__V201, _M__sTextCons);
            { START(sink__V201, _M__sTextEmbed);
              { START(sink__V201, _M_AsText);
                { START(sink__V201, _M_COMMENT_xTOKEN);
                  COPY(sink__V201, LINK(sink__V201->context, sub__V205));END(sink__V201, _M_COMMENT_xTOKEN); }
                END(sink__V201, _M_AsText); }
              END(sink__V201, _M__sTextEmbed); }
            { START(sink__V201, _M__sTextCons);
              { START(sink__V201, _M__sTextChars);
                LITERAL(sink__V201,  ". */" ); END(sink__V201, _M__sTextChars); }
              { START(sink__V201, _M__sTextCons);
                { START(sink__V201, _M__sTextBreak);
                  LITERAL(sink__V201,  "\n" ); END(sink__V201, _M__sTextBreak); }
                { START(sink__V201, _M__sTextCons);
                  { START(sink__V201, _M__sTextChars);
                    LITERAL(sink__V201,  "#ifndef CRSX_" ); END(sink__V201, _M__sTextChars); }
                  { START(sink__V201, _M__sTextCons);
                    { START(sink__V201, _M__sTextEmbed);
                      { START(sink__V201, _M_AsText);
                        { START(sink__V201, _M_MANGLE);
                          COPY(sink__V201, LINK(sink__V201->context, sub__V203));END(sink__V201, _M_MANGLE); }
                        END(sink__V201, _M_AsText); }
                      END(sink__V201, _M__sTextEmbed); }
                    { START(sink__V201, _M__sTextCons);
                      { START(sink__V201, _M__sTextEmbed);
                        { START(sink__V201, _M_AsText);
                          { START(sink__V201, _M_MANGLE);
                            COPY(sink__V201, LINK(sink__V201->context, sub__V205));END(sink__V201, _M_MANGLE); }
                          END(sink__V201, _M_AsText); }
                        END(sink__V201, _M__sTextEmbed); }
                      { START(sink__V201, _M__sTextCons);
                        { START(sink__V201, _M__sTextChars);
                          LITERAL(sink__V201,  "_H" ); END(sink__V201, _M__sTextChars); }
                        { START(sink__V201, _M__sTextCons);
                          { START(sink__V201, _M__sTextBreak);
                            LITERAL(sink__V201,  "\n" ); END(sink__V201, _M__sTextBreak); }
                          { START(sink__V201, _M__sTextCons);
                            { START(sink__V201, _M__sTextChars);
                              LITERAL(sink__V201,  "#define CRSX_" ); END(sink__V201, _M__sTextChars); }
                            { START(sink__V201, _M__sTextCons);
                              { START(sink__V201, _M__sTextEmbed);
                                { START(sink__V201, _M_AsText);
                                  { START(sink__V201, _M_MANGLE);
                                    COPY(sink__V201, LINK(sink__V201->context, sub__V203));END(sink__V201, _M_MANGLE); }
                                  END(sink__V201, _M_AsText); }
                                END(sink__V201, _M__sTextEmbed); }
                              { START(sink__V201, _M__sTextCons);
                                { START(sink__V201, _M__sTextEmbed);
                                  { START(sink__V201, _M_AsText);
                                    { START(sink__V201, _M_MANGLE);
                                      COPY(sink__V201, LINK(sink__V201->context, sub__V205));END(sink__V201, _M_MANGLE); }
                                    END(sink__V201, _M_AsText); }
                                  END(sink__V201, _M__sTextEmbed); }
                                { START(sink__V201, _M__sTextCons);
                                  { START(sink__V201, _M__sTextChars);
                                    LITERAL(sink__V201,  "_H" ); END(sink__V201, _M__sTextChars); }
                                  { START(sink__V201, _M__sTextCons);
                                    { START(sink__V201, _M__sTextBreak);
                                      LITERAL(sink__V201,  "\n" ); END(sink__V201, _M__sTextBreak); }
                                    { START(sink__V201, _M__sTextCons);
                                      { START(sink__V201, _M__sTextEmbed);
                                        { START(sink__V201, _M_AsText);
                                          { START(sink__V201, _M_DelayMapText_s1);
                                            {char* str__V208;{ Term term__V209;
                                                { char *value__V210 = getenv( "HEADERS" );
                                                  if (value__V210) term__V209 = makeStringLiteral(sink__V201->context, value__V210);
                                                  else {term__V209 = makeStringLiteral(sink__V201->context,  "" );
                                                    }
                                                }
                                                str__V208 = SYMBOL(term__V209);
                                                UNLINK(sink__V201->context, term__V209);
                                                }
                                              
                                              char* regex__V211;
                                              regex__V211 =  ";" ; SEND_SPLIT(str__V208, regex__V211, sink__V201);
                                            }
                                            { Variable x__V212 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V201->context,"x__V212");
                                              Variable x__V213 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V201->context,"x__V213");
                                              Variable binds__V214[2] = {x__V212,x__V213}; BINDS(sink__V201, 2, binds__V214);
                                              { START(sink__V201, _M__sTextCons);
                                                { START(sink__V201, _M__sTextChars);
                                                  LITERAL(sink__V201,  "#include \"" );
                                                  END(sink__V201, _M__sTextChars); }
                                                { START(sink__V201, _M__sTextCons);
                                                  { START(sink__V201, _M__sTextEmbed);
                                                    { START(sink__V201, _M_AsText);
                                                      { START(sink__V201, _M_DTOKEN);
                                                        USE(sink__V201, x__V212);
                                                        USE(sink__V201, x__V213);
                                                        END(sink__V201, _M_DTOKEN); }
                                                      END(sink__V201, _M_AsText); }
                                                    END(sink__V201, _M__sTextEmbed); }
                                                  { START(sink__V201, _M__sTextCons);
                                                    { START(sink__V201, _M__sTextChars);
                                                      LITERAL(sink__V201,  "\"" );
                                                      END(sink__V201, _M__sTextChars); }
                                                    { START(sink__V201, _M__sTextCons);
                                                      { START(sink__V201, _M__sTextBreak);
                                                        LITERAL(sink__V201,  "\n" );
                                                        END(sink__V201, _M__sTextBreak); }
                                                      { START(sink__V201, _M__sTextNil);
                                                        END(sink__V201, _M__sTextNil); }
                                                      END(sink__V201, _M__sTextCons); }
                                                    END(sink__V201, _M__sTextCons); }
                                                  END(sink__V201, _M__sTextCons); }
                                                END(sink__V201, _M__sTextCons); }
                                               }
                                            END(sink__V201, _M_DelayMapText_s1); }
                                          END(sink__V201, _M_AsText); }
                                        END(sink__V201, _M__sTextEmbed); }
                                      { START(sink__V201, _M__sTextCons);
                                        { START(sink__V201, _M__sTextBreak);
                                          LITERAL(sink__V201,  "\n" ); END(sink__V201, _M__sTextBreak); }
                                        { START(sink__V201, _M__sTextCons);
                                          { START(sink__V201, _M__sTextChars);
                                            LITERAL(sink__V201,  "#ifdef __cplusplus" );
                                            END(sink__V201, _M__sTextChars); }
                                          { START(sink__V201, _M__sTextCons);
                                            { START(sink__V201, _M__sTextBreak);
                                              LITERAL(sink__V201,  "\n" );
                                              END(sink__V201, _M__sTextBreak); }
                                            { START(sink__V201, _M__sTextCons);
                                              { START(sink__V201, _M__sTextChars);
                                                LITERAL(sink__V201,  "extern \"C\" {" );
                                                END(sink__V201, _M__sTextChars); }
                                              { START(sink__V201, _M__sTextCons);
                                                { START(sink__V201, _M__sTextBreak);
                                                  LITERAL(sink__V201,  "\n" );
                                                  END(sink__V201, _M__sTextBreak); }
                                                { START(sink__V201, _M__sTextCons);
                                                  { START(sink__V201, _M__sTextChars);
                                                    LITERAL(sink__V201,  "#endif" );
                                                    END(sink__V201, _M__sTextChars); }
                                                  { START(sink__V201, _M__sTextCons);
                                                    { START(sink__V201, _M__sTextBreak);
                                                      LITERAL(sink__V201,  "\n" );
                                                      END(sink__V201, _M__sTextBreak); }
                                                    { START(sink__V201, _M__sTextCons);
                                                      { START(sink__V201, _M__sTextEmbed);
                                                        { START(sink__V201, _M_AsText);
                                                          { START(sink__V201, _M_H_Declarations);
                                                            COPY(sink__V201, sub__V204);END(sink__V201, _M_H_Declarations); }
                                                          END(sink__V201, _M_AsText); }
                                                        END(sink__V201, _M__sTextEmbed); }
                                                      { START(sink__V201, _M__sTextCons);
                                                        { START(sink__V201, _M__sTextBreak);
                                                          LITERAL(sink__V201,  "\n" );
                                                          END(sink__V201, _M__sTextBreak); }
                                                        { START(sink__V201, _M__sTextCons);
                                                          { START(sink__V201, _M__sTextChars);
                                                            LITERAL(sink__V201,  "#ifdef __cplusplus" );
                                                            END(sink__V201, _M__sTextChars); }
                                                          { START(sink__V201, _M__sTextCons);
                                                            { START(sink__V201, _M__sTextBreak);
                                                              LITERAL(sink__V201,  "\n" );
                                                              END(sink__V201, _M__sTextBreak); }
                                                            { START(sink__V201, _M__sTextCons);
                                                              { START(sink__V201, _M__sTextChars);
                                                                LITERAL(sink__V201,  "}" );
                                                                END(sink__V201, _M__sTextChars); }
                                                              { START(sink__V201, _M__sTextCons);
                                                                { START(sink__V201, _M__sTextBreak);
                                                                  LITERAL(sink__V201,  "\n" );
                                                                  END(sink__V201, _M__sTextBreak); }
                                                                { START(sink__V201, _M__sTextCons);
                                                                  { START(sink__V201, _M__sTextChars);
                                                                    LITERAL(sink__V201,  "#endif" );
                                                                    END(sink__V201, _M__sTextChars); }
                                                                  { START(sink__V201, _M__sTextCons);
                                                                    { START(sink__V201, _M__sTextBreak);
                                                                      LITERAL(sink__V201,  "\n" );
                                                                      END(sink__V201, _M__sTextBreak); }
                                                                    { START(sink__V201, _M__sTextCons);
                                                                      { START(sink__V201, _M__sTextChars);
                                                                        LITERAL(sink__V201,  "/* END OF C HEADER FOR CRSX " );
                                                                        END(sink__V201, _M__sTextChars); }
                                                                      { START(sink__V201, _M__sTextCons);
                                                                        { START(sink__V201, _M__sTextEmbed);
                                                                          { START(sink__V201, _M_AsText);
                                                                            { START(sink__V201, _M_COMMENT_xTOKEN);
                                                                              COPY(sink__V201, sub__V203);END(sink__V201, _M_COMMENT_xTOKEN); }
                                                                            END(sink__V201, _M_AsText); }
                                                                          END(sink__V201, _M__sTextEmbed); }
                                                                        { START(sink__V201, _M__sTextCons);
                                                                          { START(sink__V201, _M__sTextChars);
                                                                            LITERAL(sink__V201,  " MODULE " );
                                                                            END(sink__V201, _M__sTextChars); }
                                                                          { START(sink__V201, _M__sTextCons);
                                                                            { START(sink__V201, _M__sTextEmbed);
                                                                              { START(sink__V201, _M_AsText);
                                                                                { START(sink__V201, _M_COMMENT_xTOKEN);
                                                                                  COPY(sink__V201, sub__V205);END(sink__V201, _M_COMMENT_xTOKEN); }
                                                                                END(sink__V201, _M_AsText); }
                                                                              END(sink__V201, _M__sTextEmbed); }
                                                                            { START(sink__V201, _M__sTextCons);
                                                                              { START(sink__V201, _M__sTextChars);
                                                                                LITERAL(sink__V201,  ". */" );
                                                                                END(sink__V201, _M__sTextChars); }
                                                                              { START(sink__V201, _M__sTextCons);
                                                                                { START(sink__V201, _M__sTextBreak);
                                                                                  LITERAL(sink__V201,  "\n" );
                                                                                  END(sink__V201, _M__sTextBreak); }
                                                                                { START(sink__V201, _M__sTextCons);
                                                                                  { START(sink__V201, _M__sTextChars);
                                                                                    LITERAL(sink__V201,  "#endif" );
                                                                                    END(sink__V201, _M__sTextChars); }
                                                                                  { START(sink__V201, _M__sTextCons);
                                                                                    { START(sink__V201, _M__sTextBreak);
                                                                                      LITERAL(sink__V201,  "\n" );
                                                                                      END(sink__V201, _M__sTextBreak); }
                                                                                    { START(sink__V201, _M__sTextNil);
                                                                                      END(sink__V201, _M__sTextNil); }
                                                                                    END(sink__V201, _M__sTextCons); }
                                                                                  END(sink__V201, _M__sTextCons); }
                                                                                END(sink__V201, _M__sTextCons); }
                                                                              END(sink__V201, _M__sTextCons); }
                                                                            END(sink__V201, _M__sTextCons); }
                                                                          END(sink__V201, _M__sTextCons); }
                                                                        END(sink__V201, _M__sTextCons); }
                                                                      END(sink__V201, _M__sTextCons); }
                                                                    END(sink__V201, _M__sTextCons); }
                                                                  END(sink__V201, _M__sTextCons); }
                                                                END(sink__V201, _M__sTextCons); }
                                                              END(sink__V201, _M__sTextCons); }
                                                            END(sink__V201, _M__sTextCons); }
                                                          END(sink__V201, _M__sTextCons); }
                                                        END(sink__V201, _M__sTextCons); }
                                                      END(sink__V201, _M__sTextCons); }
                                                    END(sink__V201, _M__sTextCons); }
                                                  END(sink__V201, _M__sTextCons); }
                                                END(sink__V201, _M__sTextCons); }
                                              END(sink__V201, _M__sTextCons); }
                                            END(sink__V201, _M__sTextCons); }
                                          END(sink__V201, _M__sTextCons); }
                                        END(sink__V201, _M__sTextCons); }
                                      END(sink__V201, _M__sTextCons); }
                                    END(sink__V201, _M__sTextCons); }
                                  END(sink__V201, _M__sTextCons); }
                                END(sink__V201, _M__sTextCons); }
                              END(sink__V201, _M__sTextCons); }
                            END(sink__V201, _M__sTextCons); }
                          END(sink__V201, _M__sTextCons); }
                        END(sink__V201, _M__sTextCons); }
                      END(sink__V201, _M__sTextCons); }
                    END(sink__V201, _M__sTextCons); }
                  END(sink__V201, _M__sTextCons); }
                END(sink__V201, _M__sTextCons); }
              END(sink__V201, _M__sTextCons); }
            END(sink__V201, _M__sTextCons); }
          END(sink__V201, _M__sTextCons); }
        END(sink__V201, _M__sTextCons); }
      END(sink__V201, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V201->context, namedP__V206); UNLINK_VariablePropertyLink(sink__V201->context, varP__V207);
    return 1;
  } while (0);
  return 0;
}

#ifdef __cplusplus
}
#endif
/* END OF C RULES FOR CRSX CRSXC MODULE HEADER. */
