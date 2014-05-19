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
    Hashset namedFV__V9 = LINK_VARIABLESET(sink__V1->context, asConstruction(term__V2)->properties->namedFreeVars);
    Hashset varFV__V10 = LINK_VARIABLESET(sink__V1->context, asConstruction(term__V2)->properties->variableFreeVars);
    UNLINK(sink__V1->context, term__V2);
    { START(sink__V1, _M_H_Data);
      COPY(sink__V1, sub__V5);COPY(sink__V1, sub__V6);END(sink__V1, _M_H_Data); }
    UNLINK_VARIABLESET(sink__V1->context, namedFV__V9); UNLINK_VARIABLESET(sink__V1->context, varFV__V10);
    UNLINK_NamedPropertyLink(sink__V1->context, namedP__V7); UNLINK_VariablePropertyLink(sink__V1->context, varP__V8);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Data$1. */
int conBindOffs_M_H_Data_s1[] = {0 , 0 , 0 , 0};
char *nameFun_M_H_Data_s1(Term term) { return  "H-Data$1" ; }
struct _ConstructionDescriptor descriptor_M_H_Data_s1 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_H_Data_s1), conBindOffs_M_H_Data_s1, &nameFun_M_H_Data_s1, &step_M_H_Data_s1};

int step_M_H_Data_s1(Sink sink__V11, Term term__V12)
{
  int term__V12_count = LINK_COUNT(term__V12); permitUnusedInt(term__V12_count);
  do {
    /* Contraction rule HEADER-H-Data-1. */
    ASSERT(sink__V11->context, !strcmp(SYMBOL(term__V12),  "H-Data$1" ));
    Term sub__V13 = LINK(sink__V11->context, SUB(term__V12, 0)); int sub__V13_count = term__V12_count*LINK_COUNT(sub__V13); permitUnusedInt(sub__V13_count);
    /* sub__V13 = &#11 */
    Term sub__V14 = SUB(term__V12, 1); permitUnusedTerm(sub__V14); int sub__V14_count = term__V12_count*LINK_COUNT(sub__V14); permitUnusedInt(sub__V14_count);
    /* sub__V14 = &#12 */
    Term sub__V15 = LINK(sink__V11->context, SUB(term__V12, 2)); int sub__V15_count = term__V12_count*LINK_COUNT(sub__V15); permitUnusedInt(sub__V15_count);
    /* sub__V15 = &#2 */
    
    NamedPropertyLink namedP__V16 = LINK_NamedPropertyLink(sink__V11->context, NAMED_PROPERTIES(term__V12));
    VariablePropertyLink varP__V17 = LINK_VariablePropertyLink(sink__V11->context, VARIABLE_PROPERTIES(term__V12));
    Hashset namedFV__V18 = LINK_VARIABLESET(sink__V11->context, asConstruction(term__V12)->properties->namedFreeVars);
    Hashset varFV__V19 = LINK_VARIABLESET(sink__V11->context, asConstruction(term__V12)->properties->variableFreeVars);
    UNLINK(sink__V11->context, term__V12);
    { START(sink__V11, _M__sTextCons);
      { START(sink__V11, _M__sTextBreak);
        LITERAL(sink__V11,  "\n" ); END(sink__V11, _M__sTextBreak); }
      { START(sink__V11, _M__sTextCons);
        { START(sink__V11, _M__sTextChars);
          LITERAL(sink__V11,  "/* DATA SORT " ); END(sink__V11, _M__sTextChars); }
        { START(sink__V11, _M__sTextCons);
          { START(sink__V11, _M__sTextEmbed);
            { START(sink__V11, _M_AsText);
              { START(sink__V11, _M_COMMENT_xTOKEN);
                COPY(sink__V11, LINK(sink__V11->context, sub__V13));END(sink__V11, _M_COMMENT_xTOKEN); }
              END(sink__V11, _M_AsText); }
            END(sink__V11, _M__sTextEmbed); }
          { START(sink__V11, _M__sTextCons);
            { START(sink__V11, _M__sTextChars);
              LITERAL(sink__V11,  " HEADER DECLARATIONS. */" ); END(sink__V11, _M__sTextChars); }
            { START(sink__V11, _M__sTextCons);
              { START(sink__V11, _M__sTextBreak);
                LITERAL(sink__V11,  "\n" ); END(sink__V11, _M__sTextBreak); }
              { START(sink__V11, _M__sTextCons);
                { START(sink__V11, _M__sTextChars);
                  LITERAL(sink__V11,  "typedef enum {" ); END(sink__V11, _M__sTextChars); }
                { START(sink__V11, _M__sTextCons);
                  { START(sink__V11, _M__sTextEmbed);
                    { START(sink__V11, _M_AsText);
                      { START(sink__V11, _M_EnumFun);
                        COPY(sink__V11, LINK(sink__V11->context, sub__V13));END(sink__V11, _M_EnumFun); }
                      END(sink__V11, _M_AsText); }
                    END(sink__V11, _M__sTextEmbed); }
                  { START(sink__V11, _M__sTextCons);
                    { START(sink__V11, _M__sTextChars);
                      LITERAL(sink__V11,  " = 0, " ); END(sink__V11, _M__sTextChars); }
                    { START(sink__V11, _M__sTextCons);
                      { START(sink__V11, _M__sTextEmbed);
                        { START(sink__V11, _M_AsText);
                          { START(sink__V11, _M_EnumVar);
                            COPY(sink__V11, LINK(sink__V11->context, sub__V13));END(sink__V11, _M_EnumVar); }
                          END(sink__V11, _M_AsText); }
                        END(sink__V11, _M__sTextEmbed); }
                      { START(sink__V11, _M__sTextCons);
                        { START(sink__V11, _M__sTextChars);
                          LITERAL(sink__V11,  " = 1" ); END(sink__V11, _M__sTextChars); }
                        { START(sink__V11, _M__sTextCons);
                          { START(sink__V11, _M__sTextEmbed);
                            { START(sink__V11, _M_AsText);
                              { START(sink__V11, _M_DelayMapText_s1);
                                { START(sink__V11, _M_Forms_Constructors);
                                  COPY(sink__V11, LINK(sink__V11->context, sub__V15));END(sink__V11, _M_Forms_Constructors); }
                                { Variable x__V20 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V11->context,"x__V20");
                                  Variable x__V21 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V11->context,"x__V21");
                                  Variable binds__V22[2] = {x__V20,x__V21}; BINDS(sink__V11, 2, binds__V22);
                                  { START(sink__V11, _M__sTextCons);
                                    { START(sink__V11, _M__sTextChars);
                                      LITERAL(sink__V11,  ", " ); END(sink__V11, _M__sTextChars); }
                                    { START(sink__V11, _M__sTextCons);
                                      { START(sink__V11, _M__sTextEmbed);
                                        { START(sink__V11, _M_AsText);
                                          { START(sink__V11, _M_DEnumTag);
                                            USE(sink__V11, x__V20); USE(sink__V11, x__V21); END(sink__V11, _M_DEnumTag); }
                                          END(sink__V11, _M_AsText); }
                                        END(sink__V11, _M__sTextEmbed); }
                                      { START(sink__V11, _M__sTextNil);
                                        END(sink__V11, _M__sTextNil); }
                                      END(sink__V11, _M__sTextCons); }
                                    END(sink__V11, _M__sTextCons); }
                                   }
                                END(sink__V11, _M_DelayMapText_s1); }
                              END(sink__V11, _M_AsText); }
                            END(sink__V11, _M__sTextEmbed); }
                          { START(sink__V11, _M__sTextCons);
                            { START(sink__V11, _M__sTextChars);
                              LITERAL(sink__V11,  "} " ); END(sink__V11, _M__sTextChars); }
                            { START(sink__V11, _M__sTextCons);
                              { START(sink__V11, _M__sTextEmbed);
                                { START(sink__V11, _M_AsText);
                                  { START(sink__V11, _M_Enum);
                                    COPY(sink__V11, LINK(sink__V11->context, sub__V13));END(sink__V11, _M_Enum); }
                                  END(sink__V11, _M_AsText); }
                                END(sink__V11, _M__sTextEmbed); }
                              { START(sink__V11, _M__sTextCons);
                                { START(sink__V11, _M__sTextChars);
                                  LITERAL(sink__V11,  ";" ); END(sink__V11, _M__sTextChars); }
                                { START(sink__V11, _M__sTextCons);
                                  { START(sink__V11, _M__sTextBreak);
                                    LITERAL(sink__V11,  "\n" ); END(sink__V11, _M__sTextBreak); }
                                  { START(sink__V11, _M__sTextCons);
                                    { START(sink__V11, _M__sTextEmbed);
                                      { START(sink__V11, _M_AsText);
                                        { START(sink__V11, _M_MapText_s1);
                                          COPY(sink__V11, sub__V15);{ Variable x__V23 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V11->context,"x__V23");
                                            Variable binds__V24[1] = {x__V23}; BINDS(sink__V11, 1, binds__V24);
                                            { START(sink__V11, _M_H_Form);
                                              USE(sink__V11, x__V23); END(sink__V11, _M_H_Form); }
                                             }
                                          END(sink__V11, _M_MapText_s1); }
                                        END(sink__V11, _M_AsText); }
                                      END(sink__V11, _M__sTextEmbed); }
                                    { START(sink__V11, _M__sTextCons);
                                      { START(sink__V11, _M__sTextChars);
                                        LITERAL(sink__V11,  "extern struct _SortDescriptor " );
                                        END(sink__V11, _M__sTextChars); }
                                      { START(sink__V11, _M__sTextCons);
                                        { START(sink__V11, _M__sTextEmbed);
                                          { START(sink__V11, _M_AsText);
                                            { START(sink__V11, _M_Sort);
                                              COPY(sink__V11, sub__V13);END(sink__V11, _M_Sort); }
                                            END(sink__V11, _M_AsText); }
                                          END(sink__V11, _M__sTextEmbed); }
                                        { START(sink__V11, _M__sTextCons);
                                          { START(sink__V11, _M__sTextChars);
                                            LITERAL(sink__V11,  ";" ); END(sink__V11, _M__sTextChars); }
                                          { START(sink__V11, _M__sTextCons);
                                            { START(sink__V11, _M__sTextBreak);
                                              LITERAL(sink__V11,  "\n" );
                                              END(sink__V11, _M__sTextBreak); }
                                            { START(sink__V11, _M__sTextNil);
                                              END(sink__V11, _M__sTextNil); }
                                            END(sink__V11, _M__sTextCons); }
                                          END(sink__V11, _M__sTextCons); }
                                        END(sink__V11, _M__sTextCons); }
                                      END(sink__V11, _M__sTextCons); }
                                    END(sink__V11, _M__sTextCons); }
                                  END(sink__V11, _M__sTextCons); }
                                END(sink__V11, _M__sTextCons); }
                              END(sink__V11, _M__sTextCons); }
                            END(sink__V11, _M__sTextCons); }
                          END(sink__V11, _M__sTextCons); }
                        END(sink__V11, _M__sTextCons); }
                      END(sink__V11, _M__sTextCons); }
                    END(sink__V11, _M__sTextCons); }
                  END(sink__V11, _M__sTextCons); }
                END(sink__V11, _M__sTextCons); }
              END(sink__V11, _M__sTextCons); }
            END(sink__V11, _M__sTextCons); }
          END(sink__V11, _M__sTextCons); }
        END(sink__V11, _M__sTextCons); }
      END(sink__V11, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V11->context, namedFV__V18); UNLINK_VARIABLESET(sink__V11->context, varFV__V19);
    UNLINK_NamedPropertyLink(sink__V11->context, namedP__V16); UNLINK_VariablePropertyLink(sink__V11->context, varP__V17);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Form$2. */
int conBindOffs_M_H_Form_s2[] = {0 , 0 , 0};
char *nameFun_M_H_Form_s2(Term term) { return  "H-Form$2" ; }
struct _ConstructionDescriptor descriptor_M_H_Form_s2 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_H_Form_s2), conBindOffs_M_H_Form_s2, &nameFun_M_H_Form_s2, &step_M_H_Form_s2};

int step_M_H_Form_s2(Sink sink__V25, Term term__V26)
{
  int term__V26_count = LINK_COUNT(term__V26); permitUnusedInt(term__V26_count);
  Term sub__V27 = FORCE(sink__V25->context, SUB(term__V26, 0));
  EnumOf_M__sList choice__V28 = (IS_VARIABLE_USE(sub__V27) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V27));
  switch (choice__V28)
  {
    case Data_M__sNil: { /* Function HEADER-H-Form-3$H-Form$2$$Nil case $Nil */
      ASSERT(sink__V25->context, !strcmp(SYMBOL(term__V26),  "H-Form$2" ));
      Term sub__V29 = SUB(term__V26, 0); permitUnusedTerm(sub__V29); int sub__V29_count = term__V26_count*LINK_COUNT(sub__V29); permitUnusedInt(sub__V29_count);
      ASSERT(sink__V25->context, !strcmp(SYMBOL(sub__V29),  "$Nil" ));
      Term sub__V30 = LINK(sink__V25->context, SUB(term__V26, 1)); int sub__V30_count = term__V26_count*LINK_COUNT(sub__V30); permitUnusedInt(sub__V30_count);
      /* sub__V30 = &#0 */
      
      NamedPropertyLink namedP__V31 = LINK_NamedPropertyLink(sink__V25->context, NAMED_PROPERTIES(term__V26));
      VariablePropertyLink varP__V32 = LINK_VariablePropertyLink(sink__V25->context, VARIABLE_PROPERTIES(term__V26));
      Hashset namedFV__V33 = LINK_VARIABLESET(sink__V25->context, asConstruction(term__V26)->properties->namedFreeVars);
      Hashset varFV__V34 = LINK_VARIABLESET(sink__V25->context, asConstruction(term__V26)->properties->variableFreeVars);
      UNLINK(sink__V25->context, term__V26);
      ADD_PROPERTIES(sink__V25, LINK_VARIABLESET(sink__V25->context, namedFV__V33), LINK_VARIABLESET(sink__V25->context, varFV__V34), LINK_NamedPropertyLink(sink__V25->context, namedP__V31), LINK_VariablePropertyLink(sink__V25->context, varP__V32));
      { START(sink__V25, _M_H_Form_s4);
        COPY(sink__V25, sub__V30);END(sink__V25, _M_H_Form_s4); }
      UNLINK_VARIABLESET(sink__V25->context, namedFV__V33); UNLINK_VARIABLESET(sink__V25->context, varFV__V34);
      UNLINK_NamedPropertyLink(sink__V25->context, namedP__V31); UNLINK_VariablePropertyLink(sink__V25->context, varP__V32);
      
      return 1;
    break; } case Data_M__sCons: { /* Function HEADER-H-Form-4$H-Form$2$$Cons case $Cons */
      ASSERT(sink__V25->context, !strcmp(SYMBOL(term__V26),  "H-Form$2" ));
      Term sub__V35 = SUB(term__V26, 0); permitUnusedTerm(sub__V35); int sub__V35_count = term__V26_count*LINK_COUNT(sub__V35); permitUnusedInt(sub__V35_count);
      ASSERT(sink__V25->context, !strcmp(SYMBOL(sub__V35),  "$Cons" ));
      Term sub__V36 = LINK(sink__V25->context, SUB(sub__V35, 0)); int sub__V36_count = sub__V35_count*LINK_COUNT(sub__V36); permitUnusedInt(sub__V36_count);
      /* sub__V36 = &#0-0 */
      Term sub__V37 = LINK(sink__V25->context, SUB(sub__V35, 1)); int sub__V37_count = sub__V35_count*LINK_COUNT(sub__V37); permitUnusedInt(sub__V37_count);
      /* sub__V37 = &#0-1 */
      Term sub__V38 = LINK(sink__V25->context, SUB(term__V26, 1)); int sub__V38_count = term__V26_count*LINK_COUNT(sub__V38); permitUnusedInt(sub__V38_count);
      /* sub__V38 = &#2 */
      
      NamedPropertyLink namedP__V39 = LINK_NamedPropertyLink(sink__V25->context, NAMED_PROPERTIES(term__V26));
      VariablePropertyLink varP__V40 = LINK_VariablePropertyLink(sink__V25->context, VARIABLE_PROPERTIES(term__V26));
      Hashset namedFV__V41 = LINK_VARIABLESET(sink__V25->context, asConstruction(term__V26)->properties->namedFreeVars);
      Hashset varFV__V42 = LINK_VARIABLESET(sink__V25->context, asConstruction(term__V26)->properties->variableFreeVars);
      UNLINK(sink__V25->context, term__V26);
      ADD_PROPERTIES(sink__V25, LINK_VARIABLESET(sink__V25->context, namedFV__V41), LINK_VARIABLESET(sink__V25->context, varFV__V42), LINK_NamedPropertyLink(sink__V25->context, namedP__V39), LINK_VariablePropertyLink(sink__V25->context, varP__V40));
      { START(sink__V25, _M_H_Form_s3);
        COPY(sink__V25, sub__V36);COPY(sink__V25, sub__V37);COPY(sink__V25, sub__V38);END(sink__V25, _M_H_Form_s3); }
      UNLINK_VARIABLESET(sink__V25->context, namedFV__V41); UNLINK_VARIABLESET(sink__V25->context, varFV__V42);
      UNLINK_NamedPropertyLink(sink__V25->context, namedP__V39); UNLINK_VariablePropertyLink(sink__V25->context, varP__V40);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION ComputeHeader$1. */
int conBindOffs_M_ComputeHeader_s1[] = {0 , 0 , 0};
char *nameFun_M_ComputeHeader_s1(Term term) { return  "ComputeHeader$1" ; }
struct _ConstructionDescriptor descriptor_M_ComputeHeader_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_ComputeHeader_s1), conBindOffs_M_ComputeHeader_s1, &nameFun_M_ComputeHeader_s1, &step_M_ComputeHeader_s1};

int step_M_ComputeHeader_s1(Sink sink__V43, Term term__V44)
{
  int term__V44_count = LINK_COUNT(term__V44); permitUnusedInt(term__V44_count);
  do {
    /* Contraction rule HEADER-ComputeHeader-1. */
    ASSERT(sink__V43->context, !strcmp(SYMBOL(term__V44),  "ComputeHeader$1" ));
    Term sub__V45 = LINK(sink__V43->context, SUB(term__V44, 0)); int sub__V45_count = term__V44_count*LINK_COUNT(sub__V45); permitUnusedInt(sub__V45_count);
    /* sub__V45 = &#11 */
    Term sub__V46 = LINK(sink__V43->context, SUB(term__V44, 1)); int sub__V46_count = term__V44_count*LINK_COUNT(sub__V46); permitUnusedInt(sub__V46_count);
    /* sub__V46 = &#12 */
    
    NamedPropertyLink namedP__V47 = LINK_NamedPropertyLink(sink__V43->context, NAMED_PROPERTIES(term__V44));
    VariablePropertyLink varP__V48 = LINK_VariablePropertyLink(sink__V43->context, VARIABLE_PROPERTIES(term__V44));
    Hashset namedFV__V49 = LINK_VARIABLESET(sink__V43->context, asConstruction(term__V44)->properties->namedFreeVars);
    Hashset varFV__V50 = LINK_VARIABLESET(sink__V43->context, asConstruction(term__V44)->properties->variableFreeVars);
    UNLINK(sink__V43->context, term__V44);
    { START(sink__V43, _M_ComputeHeader2);
      COPY(sink__V43, sub__V45);COPY(sink__V43, sub__V46);{ Term term__V51;
        { char *value__V52 = getenv( "MODULE" );
          if (value__V52) term__V51 = makeStringLiteral(sink__V43->context, value__V52);
          else {term__V51 = makeStringLiteral(sink__V43->context,  "" ); }
        }
        COPY(sink__V43, term__V51); /*CONSERVATIVE*/ }
      END(sink__V43, _M_ComputeHeader2); }
    UNLINK_VARIABLESET(sink__V43->context, namedFV__V49); UNLINK_VARIABLESET(sink__V43->context, varFV__V50);
    UNLINK_NamedPropertyLink(sink__V43->context, namedP__V47); UNLINK_VariablePropertyLink(sink__V43->context, varP__V48);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Form$6. */
int conBindOffs_M_H_Form_s6[] = {0 , 0 , 0 , 0};
char *nameFun_M_H_Form_s6(Term term) { return  "H-Form$6" ; }
struct _ConstructionDescriptor descriptor_M_H_Form_s6 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_H_Form_s6), conBindOffs_M_H_Form_s6, &nameFun_M_H_Form_s6, &step_M_H_Form_s6};

int step_M_H_Form_s6(Sink sink__V53, Term term__V54)
{
  int term__V54_count = LINK_COUNT(term__V54); permitUnusedInt(term__V54_count);
  do {
    /* Contraction rule HEADER-H-Form-1. */
    ASSERT(sink__V53->context, !strcmp(SYMBOL(term__V54),  "H-Form$6" ));
    Term sub__V55 = SUB(term__V54, 0); permitUnusedTerm(sub__V55); int sub__V55_count = term__V54_count*LINK_COUNT(sub__V55); permitUnusedInt(sub__V55_count);
    CRSX_CHECK_SORT(sink__V53->context, sub__V55, &sort_M_Reified_xSort); /* sub__V55 = &#11 */
    Term sub__V56 = SUB(term__V54, 1); permitUnusedTerm(sub__V56); int sub__V56_count = term__V54_count*LINK_COUNT(sub__V56); permitUnusedInt(sub__V56_count);
    CRSX_CHECK_SORT(sink__V53->context, sub__V56, &sort_M_Reified_xSort); /* sub__V56 = &#12 */
    Term sub__V57 = LINK(sink__V53->context, SUB(term__V54, 2)); int sub__V57_count = term__V54_count*LINK_COUNT(sub__V57); permitUnusedInt(sub__V57_count);
    CRSX_CHECK_SORT(sink__V53->context, sub__V57, &sort_M_Reified_xForm); /* sub__V57 = &#13 */
    
    NamedPropertyLink namedP__V58 = LINK_NamedPropertyLink(sink__V53->context, NAMED_PROPERTIES(term__V54));
    VariablePropertyLink varP__V59 = LINK_VariablePropertyLink(sink__V53->context, VARIABLE_PROPERTIES(term__V54));
    Hashset namedFV__V60 = LINK_VARIABLESET(sink__V53->context, asConstruction(term__V54)->properties->namedFreeVars);
    Hashset varFV__V61 = LINK_VARIABLESET(sink__V53->context, asConstruction(term__V54)->properties->variableFreeVars);
    UNLINK(sink__V53->context, term__V54);
    { START(sink__V53, _M_H_Form);
      COPY(sink__V53, sub__V57);END(sink__V53, _M_H_Form); }
    UNLINK_VARIABLESET(sink__V53->context, namedFV__V60); UNLINK_VARIABLESET(sink__V53->context, varFV__V61);
    UNLINK_NamedPropertyLink(sink__V53->context, namedP__V58); UNLINK_VariablePropertyLink(sink__V53->context, varP__V59);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Form$5. */
int conBindOffs_M_H_Form_s5[] = {0};
char *nameFun_M_H_Form_s5(Term term) { return  "H-Form$5" ; }
struct _ConstructionDescriptor descriptor_M_H_Form_s5 = {&sort_M_Reified_xVariable, 0, 0, sizeof(STRUCT_Con_M_H_Form_s5), conBindOffs_M_H_Form_s5, &nameFun_M_H_Form_s5, &step_M_H_Form_s5};

int step_M_H_Form_s5(Sink sink__V62, Term term__V63)
{
  int term__V63_count = LINK_COUNT(term__V63); permitUnusedInt(term__V63_count);
  do {
    /* Contraction rule HEADER-H-Form-2. */
    ASSERT(sink__V62->context, !strcmp(SYMBOL(term__V63),  "H-Form$5" ));
    
    NamedPropertyLink namedP__V64 = LINK_NamedPropertyLink(sink__V62->context, NAMED_PROPERTIES(term__V63));
    VariablePropertyLink varP__V65 = LINK_VariablePropertyLink(sink__V62->context, VARIABLE_PROPERTIES(term__V63));
    Hashset namedFV__V66 = LINK_VARIABLESET(sink__V62->context, asConstruction(term__V63)->properties->namedFreeVars);
    Hashset varFV__V67 = LINK_VARIABLESET(sink__V62->context, asConstruction(term__V63)->properties->variableFreeVars);
    UNLINK(sink__V62->context, term__V63);
    { START(sink__V62, _M__sTextNil); END(sink__V62, _M__sTextNil); } UNLINK_VARIABLESET(sink__V62->context, namedFV__V66); UNLINK_VARIABLESET(sink__V62->context, varFV__V67);
    UNLINK_NamedPropertyLink(sink__V62->context, namedP__V64); UNLINK_VariablePropertyLink(sink__V62->context, varP__V65);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Form$4. */
int conBindOffs_M_H_Form_s4[] = {0 , 0};
char *nameFun_M_H_Form_s4(Term term) { return  "H-Form$4" ; }
struct _ConstructionDescriptor descriptor_M_H_Form_s4 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_H_Form_s4), conBindOffs_M_H_Form_s4, &nameFun_M_H_Form_s4, &step_M_H_Form_s4};

int step_M_H_Form_s4(Sink sink__V68, Term term__V69)
{
  int term__V69_count = LINK_COUNT(term__V69); permitUnusedInt(term__V69_count);
  do {
    /* Contraction rule HEADER-H-Form-3. */
    ASSERT(sink__V68->context, !strcmp(SYMBOL(term__V69),  "H-Form$4" ));
    Term sub__V70 = LINK(sink__V68->context, SUB(term__V69, 0)); int sub__V70_count = term__V69_count*LINK_COUNT(sub__V70); permitUnusedInt(sub__V70_count);
    /* sub__V70 = &#11 */
    
    NamedPropertyLink namedP__V71 = LINK_NamedPropertyLink(sink__V68->context, NAMED_PROPERTIES(term__V69));
    VariablePropertyLink varP__V72 = LINK_VariablePropertyLink(sink__V68->context, VARIABLE_PROPERTIES(term__V69));
    Hashset namedFV__V73 = LINK_VARIABLESET(sink__V68->context, asConstruction(term__V69)->properties->namedFreeVars);
    Hashset varFV__V74 = LINK_VARIABLESET(sink__V68->context, asConstruction(term__V69)->properties->variableFreeVars);
    UNLINK(sink__V68->context, term__V69);
    { START(sink__V68, _M__sTextCons);
      { START(sink__V68, _M__sTextChars);
        LITERAL(sink__V68,  "#define STRUCT" ); END(sink__V68, _M__sTextChars); }
      { START(sink__V68, _M__sTextCons);
        { START(sink__V68, _M__sTextEmbed);
          { START(sink__V68, _M_AsText);
            { START(sink__V68, _M_Struct);
              COPY(sink__V68, LINK(sink__V68->context, sub__V70));END(sink__V68, _M_Struct); }
            END(sink__V68, _M_AsText); }
          END(sink__V68, _M__sTextEmbed); }
        { START(sink__V68, _M__sTextCons);
          { START(sink__V68, _M__sTextChars);
            LITERAL(sink__V68,  " struct _ConstantConstruction" ); END(sink__V68, _M__sTextChars); }
          { START(sink__V68, _M__sTextCons);
            { START(sink__V68, _M__sTextBreak);
              LITERAL(sink__V68,  "\n" ); END(sink__V68, _M__sTextBreak); }
            { START(sink__V68, _M__sTextCons);
              { START(sink__V68, _M__sTextChars);
                LITERAL(sink__V68,  "extern struct _ConstructionDescriptor " );
                END(sink__V68, _M__sTextChars); }
              { START(sink__V68, _M__sTextCons);
                { START(sink__V68, _M__sTextEmbed);
                  { START(sink__V68, _M_AsText);
                    { START(sink__V68, _M_Descriptor);
                      COPY(sink__V68, sub__V70);END(sink__V68, _M_Descriptor); }
                    END(sink__V68, _M_AsText); }
                  END(sink__V68, _M__sTextEmbed); }
                { START(sink__V68, _M__sTextCons);
                  { START(sink__V68, _M__sTextChars);
                    LITERAL(sink__V68,  ";" ); END(sink__V68, _M__sTextChars); }
                  { START(sink__V68, _M__sTextCons);
                    { START(sink__V68, _M__sTextBreak);
                      LITERAL(sink__V68,  "\n" ); END(sink__V68, _M__sTextBreak); }
                    { START(sink__V68, _M__sTextNil);
                      END(sink__V68, _M__sTextNil); }
                    END(sink__V68, _M__sTextCons); }
                  END(sink__V68, _M__sTextCons); }
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

/* FUNCTION H-Form$3. */
int conBindOffs_M_H_Form_s3[] = {0 , 0 , 0 , 0};
char *nameFun_M_H_Form_s3(Term term) { return  "H-Form$3" ; }
struct _ConstructionDescriptor descriptor_M_H_Form_s3 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_H_Form_s3), conBindOffs_M_H_Form_s3, &nameFun_M_H_Form_s3, &step_M_H_Form_s3};

int step_M_H_Form_s3(Sink sink__V75, Term term__V76)
{
  int term__V76_count = LINK_COUNT(term__V76); permitUnusedInt(term__V76_count);
  do {
    /* Contraction rule HEADER-H-Form-4. */
    ASSERT(sink__V75->context, !strcmp(SYMBOL(term__V76),  "H-Form$3" ));
    Term sub__V77 = LINK(sink__V75->context, SUB(term__V76, 0)); int sub__V77_count = term__V76_count*LINK_COUNT(sub__V77); permitUnusedInt(sub__V77_count);
    /* sub__V77 = &#121 */
    Term sub__V78 = LINK(sink__V75->context, SUB(term__V76, 1)); int sub__V78_count = term__V76_count*LINK_COUNT(sub__V78); permitUnusedInt(sub__V78_count);
    /* sub__V78 = &#122 */
    Term sub__V79 = LINK(sink__V75->context, SUB(term__V76, 2)); int sub__V79_count = term__V76_count*LINK_COUNT(sub__V79); permitUnusedInt(sub__V79_count);
    /* sub__V79 = &#11 */
    
    NamedPropertyLink namedP__V80 = LINK_NamedPropertyLink(sink__V75->context, NAMED_PROPERTIES(term__V76));
    VariablePropertyLink varP__V81 = LINK_VariablePropertyLink(sink__V75->context, VARIABLE_PROPERTIES(term__V76));
    Hashset namedFV__V82 = LINK_VARIABLESET(sink__V75->context, asConstruction(term__V76)->properties->namedFreeVars);
    Hashset varFV__V83 = LINK_VARIABLESET(sink__V75->context, asConstruction(term__V76)->properties->variableFreeVars);
    UNLINK(sink__V75->context, term__V76);
    { START(sink__V75, _M__sTextCons);
      { START(sink__V75, _M__sTextChars);
        LITERAL(sink__V75,  "#define STRUCT" ); END(sink__V75, _M__sTextChars); }
      { START(sink__V75, _M__sTextCons);
        { START(sink__V75, _M__sTextEmbed);
          { START(sink__V75, _M_AsText);
            { START(sink__V75, _M_Struct);
              COPY(sink__V75, LINK(sink__V75->context, sub__V79));END(sink__V75, _M_Struct); }
            END(sink__V75, _M_AsText); }
          END(sink__V75, _M__sTextEmbed); }
        { START(sink__V75, _M__sTextCons);
          { START(sink__V75, _M__sTextChars);
            LITERAL(sink__V75,  " struct " ); END(sink__V75, _M__sTextChars); }
          { START(sink__V75, _M__sTextCons);
            { START(sink__V75, _M__sTextEmbed);
              { START(sink__V75, _M_AsText);
                { START(sink__V75, _M_Struct);
                  COPY(sink__V75, LINK(sink__V75->context, sub__V79));END(sink__V75, _M_Struct); }
                END(sink__V75, _M_AsText); }
              END(sink__V75, _M__sTextEmbed); }
            { START(sink__V75, _M__sTextCons);
              { START(sink__V75, _M__sTextBreak);
                LITERAL(sink__V75,  "\n" ); END(sink__V75, _M__sTextBreak); }
              { START(sink__V75, _M__sTextCons);
                { START(sink__V75, _M__sTextChars);
                  LITERAL(sink__V75,  "struct " ); END(sink__V75, _M__sTextChars); }
                { START(sink__V75, _M__sTextCons);
                  { START(sink__V75, _M__sTextEmbed);
                    { START(sink__V75, _M_AsText);
                      { START(sink__V75, _M_Struct);
                        COPY(sink__V75, LINK(sink__V75->context, sub__V79));END(sink__V75, _M_Struct); }
                      END(sink__V75, _M_AsText); }
                    END(sink__V75, _M__sTextEmbed); }
                  { START(sink__V75, _M__sTextCons);
                    { START(sink__V75, _M__sTextChars);
                      LITERAL(sink__V75,  " {struct _Construction construction; Term sub[" );
                      END(sink__V75, _M__sTextChars); }
                    { START(sink__V75, _M__sTextCons);
                      { START(sink__V75, _M__sTextEmbed);
                        { START(sink__V75, _M_AsText);
                          { START(sink__V75, _M_INTEGER);
                            { START(sink__V75, _M_Length);
                              COPY(sink__V75, LINK(sink__V75->context, sub__V78));LITERAL(sink__V75,  "1" ); END(sink__V75, _M_Length); }
                            END(sink__V75, _M_INTEGER); }
                          END(sink__V75, _M_AsText); }
                        END(sink__V75, _M__sTextEmbed); }
                      { START(sink__V75, _M__sTextCons);
                        { START(sink__V75, _M__sTextChars);
                          LITERAL(sink__V75,  "]; Variable binder[" ); END(sink__V75, _M__sTextChars); }
                        { START(sink__V75, _M__sTextCons);
                          { START(sink__V75, _M__sTextEmbed);
                            { START(sink__V75, _M_AsText);
                              { START(sink__V75, _M_INTEGER);
                                { START(sink__V75, _M_FormArguments__binder__count);
                                  { START(sink__V75, _M__sCons);
                                    COPY(sink__V75, sub__V77);COPY(sink__V75, sub__V78);END(sink__V75, _M__sCons); }
                                  LITERAL(sink__V75,  "0" ); END(sink__V75, _M_FormArguments__binder__count); }
                                END(sink__V75, _M_INTEGER); }
                              END(sink__V75, _M_AsText); }
                            END(sink__V75, _M__sTextEmbed); }
                          { START(sink__V75, _M__sTextCons);
                            { START(sink__V75, _M__sTextChars);
                              LITERAL(sink__V75,  "];};" ); END(sink__V75, _M__sTextChars); }
                            { START(sink__V75, _M__sTextCons);
                              { START(sink__V75, _M__sTextBreak);
                                LITERAL(sink__V75,  "\n" ); END(sink__V75, _M__sTextBreak); }
                              { START(sink__V75, _M__sTextCons);
                                { START(sink__V75, _M__sTextChars);
                                  LITERAL(sink__V75,  "extern struct _ConstructionDescriptor " );
                                  END(sink__V75, _M__sTextChars); }
                                { START(sink__V75, _M__sTextCons);
                                  { START(sink__V75, _M__sTextEmbed);
                                    { START(sink__V75, _M_AsText);
                                      { START(sink__V75, _M_Descriptor);
                                        COPY(sink__V75, sub__V79);END(sink__V75, _M_Descriptor); }
                                      END(sink__V75, _M_AsText); }
                                    END(sink__V75, _M__sTextEmbed); }
                                  { START(sink__V75, _M__sTextCons);
                                    { START(sink__V75, _M__sTextChars);
                                      LITERAL(sink__V75,  ";" ); END(sink__V75, _M__sTextChars); }
                                    { START(sink__V75, _M__sTextCons);
                                      { START(sink__V75, _M__sTextBreak);
                                        LITERAL(sink__V75,  "\n" ); END(sink__V75, _M__sTextBreak); }
                                      { START(sink__V75, _M__sTextNil);
                                        END(sink__V75, _M__sTextNil); }
                                      END(sink__V75, _M__sTextCons); }
                                    END(sink__V75, _M__sTextCons); }
                                  END(sink__V75, _M__sTextCons); }
                                END(sink__V75, _M__sTextCons); }
                              END(sink__V75, _M__sTextCons); }
                            END(sink__V75, _M__sTextCons); }
                          END(sink__V75, _M__sTextCons); }
                        END(sink__V75, _M__sTextCons); }
                      END(sink__V75, _M__sTextCons); }
                    END(sink__V75, _M__sTextCons); }
                  END(sink__V75, _M__sTextCons); }
                END(sink__V75, _M__sTextCons); }
              END(sink__V75, _M__sTextCons); }
            END(sink__V75, _M__sTextCons); }
          END(sink__V75, _M__sTextCons); }
        END(sink__V75, _M__sTextCons); }
      END(sink__V75, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V75->context, namedFV__V82); UNLINK_VARIABLESET(sink__V75->context, varFV__V83);
    UNLINK_NamedPropertyLink(sink__V75->context, namedP__V80); UNLINK_VariablePropertyLink(sink__V75->context, varP__V81);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Form. */
int conBindOffs_M_H_Form[] = {0 , 0};
char *nameFun_M_H_Form(Term term) { return  "H-Form" ; }
struct _ConstructionDescriptor descriptor_M_H_Form = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_H_Form), conBindOffs_M_H_Form, &nameFun_M_H_Form, &step_M_H_Form};

int step_M_H_Form(Sink sink__V84, Term term__V85)
{
  int term__V85_count = LINK_COUNT(term__V85); permitUnusedInt(term__V85_count);
  Term sub__V86 = FORCE(sink__V84->context, SUB(term__V85, 0));
  EnumOf_M_Reified_xForm choice__V87 = (IS_VARIABLE_USE(sub__V86) ? VarOf_M_Reified_xForm : (EnumOf_M_Reified_xForm) TAG(sub__V86));
  switch (choice__V87)
  {
    case Data_M_SORT_SET: { /* Function HEADER-H-Form-1$H-Form$SORT-SET case SORT-SET */
      ASSERT(sink__V84->context, !strcmp(SYMBOL(term__V85),  "H-Form" ));
      Term sub__V88 = SUB(term__V85, 0); permitUnusedTerm(sub__V88); int sub__V88_count = term__V85_count*LINK_COUNT(sub__V88); permitUnusedInt(sub__V88_count);
      CRSX_CHECK_SORT(sink__V84->context, sub__V88, &sort_M_Reified_xForm); ASSERT(sink__V84->context, !strcmp(SYMBOL(sub__V88),  "SORT-SET" ));
      Term sub__V89 = LINK(sink__V84->context, SUB(sub__V88, 0)); int sub__V89_count = sub__V88_count*LINK_COUNT(sub__V89); permitUnusedInt(sub__V89_count);
      CRSX_CHECK_SORT(sink__V84->context, sub__V89, &sort_M_Reified_xSort); /* sub__V89 = &#0-0 */
      Term sub__V90 = LINK(sink__V84->context, SUB(sub__V88, 1)); int sub__V90_count = sub__V88_count*LINK_COUNT(sub__V90); permitUnusedInt(sub__V90_count);
      CRSX_CHECK_SORT(sink__V84->context, sub__V90, &sort_M_Reified_xSort); /* sub__V90 = &#0-1 */
      Term sub__V91 = LINK(sink__V84->context, SUB(sub__V88, 2)); int sub__V91_count = sub__V88_count*LINK_COUNT(sub__V91); permitUnusedInt(sub__V91_count);
      CRSX_CHECK_SORT(sink__V84->context, sub__V91, &sort_M_Reified_xForm); /* sub__V91 = &#0-2 */
      
      NamedPropertyLink namedP__V92 = LINK_NamedPropertyLink(sink__V84->context, NAMED_PROPERTIES(term__V85));
      VariablePropertyLink varP__V93 = LINK_VariablePropertyLink(sink__V84->context, VARIABLE_PROPERTIES(term__V85));
      Hashset namedFV__V94 = LINK_VARIABLESET(sink__V84->context, asConstruction(term__V85)->properties->namedFreeVars);
      Hashset varFV__V95 = LINK_VARIABLESET(sink__V84->context, asConstruction(term__V85)->properties->variableFreeVars);
      UNLINK(sink__V84->context, term__V85);
      ADD_PROPERTIES(sink__V84, LINK_VARIABLESET(sink__V84->context, namedFV__V94), LINK_VARIABLESET(sink__V84->context, varFV__V95), LINK_NamedPropertyLink(sink__V84->context, namedP__V92), LINK_VariablePropertyLink(sink__V84->context, varP__V93));
      { START(sink__V84, _M_H_Form_s6);
        COPY(sink__V84, sub__V89);COPY(sink__V84, sub__V90);COPY(sink__V84, sub__V91);END(sink__V84, _M_H_Form_s6); }
      UNLINK_VARIABLESET(sink__V84->context, namedFV__V94); UNLINK_VARIABLESET(sink__V84->context, varFV__V95);
      UNLINK_NamedPropertyLink(sink__V84->context, namedP__V92); UNLINK_VariablePropertyLink(sink__V84->context, varP__V93);
      
      return 1;
    break; } case Data_M_SORT_ALLOWS_VARIABLES: { /* Function HEADER-H-Form-2$H-Form$SORT-ALLOWS-VARIABLES case SORT-ALLOWS-VARIABLES */
      ASSERT(sink__V84->context, !strcmp(SYMBOL(term__V85),  "H-Form" ));
      Term sub__V96 = SUB(term__V85, 0); permitUnusedTerm(sub__V96); int sub__V96_count = term__V85_count*LINK_COUNT(sub__V96); permitUnusedInt(sub__V96_count);
      CRSX_CHECK_SORT(sink__V84->context, sub__V96, &sort_M_Reified_xForm); ASSERT(sink__V84->context, !strcmp(SYMBOL(sub__V96),  "SORT-ALLOWS-VARIABLES" ));
      
      NamedPropertyLink namedP__V97 = LINK_NamedPropertyLink(sink__V84->context, NAMED_PROPERTIES(term__V85));
      VariablePropertyLink varP__V98 = LINK_VariablePropertyLink(sink__V84->context, VARIABLE_PROPERTIES(term__V85));
      Hashset namedFV__V99 = LINK_VARIABLESET(sink__V84->context, asConstruction(term__V85)->properties->namedFreeVars);
      Hashset varFV__V100 = LINK_VARIABLESET(sink__V84->context, asConstruction(term__V85)->properties->variableFreeVars);
      UNLINK(sink__V84->context, term__V85);
      ADD_PROPERTIES(sink__V84, LINK_VARIABLESET(sink__V84->context, namedFV__V99), LINK_VARIABLESET(sink__V84->context, varFV__V100), LINK_NamedPropertyLink(sink__V84->context, namedP__V97), LINK_VariablePropertyLink(sink__V84->context, varP__V98));
      { START(sink__V84, _M_H_Form_s5); END(sink__V84, _M_H_Form_s5); }
      UNLINK_VARIABLESET(sink__V84->context, namedFV__V99); UNLINK_VARIABLESET(sink__V84->context, varFV__V100);
      UNLINK_NamedPropertyLink(sink__V84->context, namedP__V97); UNLINK_VariablePropertyLink(sink__V84->context, varP__V98);
      
      return 1;
    break; } case Data_M_FORM: { /* Function HEADER-H-Form-4$H-Form$FORM case FORM */
      ASSERT(sink__V84->context, !strcmp(SYMBOL(term__V85),  "H-Form" ));
      Term sub__V101 = SUB(term__V85, 0); permitUnusedTerm(sub__V101); int sub__V101_count = term__V85_count*LINK_COUNT(sub__V101); permitUnusedInt(sub__V101_count);
      CRSX_CHECK_SORT(sink__V84->context, sub__V101, &sort_M_Reified_xForm); ASSERT(sink__V84->context, !strcmp(SYMBOL(sub__V101),  "FORM" ));
      Term sub__V102 = LINK(sink__V84->context, SUB(sub__V101, 0)); int sub__V102_count = sub__V101_count*LINK_COUNT(sub__V102); permitUnusedInt(sub__V102_count);
      /* sub__V102 = &#0-0 */
      Term sub__V103 = LINK(sink__V84->context, SUB(sub__V101, 1)); int sub__V103_count = sub__V101_count*LINK_COUNT(sub__V103); permitUnusedInt(sub__V103_count);
      /* sub__V103 = &#0-1 */
      
      NamedPropertyLink namedP__V104 = LINK_NamedPropertyLink(sink__V84->context, NAMED_PROPERTIES(term__V85));
      VariablePropertyLink varP__V105 = LINK_VariablePropertyLink(sink__V84->context, VARIABLE_PROPERTIES(term__V85));
      Hashset namedFV__V106 = LINK_VARIABLESET(sink__V84->context, asConstruction(term__V85)->properties->namedFreeVars);
      Hashset varFV__V107 = LINK_VARIABLESET(sink__V84->context, asConstruction(term__V85)->properties->variableFreeVars);
      UNLINK(sink__V84->context, term__V85);
      ADD_PROPERTIES(sink__V84, LINK_VARIABLESET(sink__V84->context, namedFV__V106), LINK_VARIABLESET(sink__V84->context, varFV__V107), LINK_NamedPropertyLink(sink__V84->context, namedP__V104), LINK_VariablePropertyLink(sink__V84->context, varP__V105));
      { START(sink__V84, _M_H_Form_s2);
        COPY(sink__V84, sub__V103);COPY(sink__V84, sub__V102);END(sink__V84, _M_H_Form_s2); }
      UNLINK_VARIABLESET(sink__V84->context, namedFV__V106); UNLINK_VARIABLESET(sink__V84->context, varFV__V107);
      UNLINK_NamedPropertyLink(sink__V84->context, namedP__V104); UNLINK_VariablePropertyLink(sink__V84->context, varP__V105);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION ComputeHeader. */
int conBindOffs_M_ComputeHeader[] = {0 , 0};
char *nameFun_M_ComputeHeader(Term term) { return  "ComputeHeader" ; }
struct _ConstructionDescriptor descriptor_M_ComputeHeader = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_ComputeHeader), conBindOffs_M_ComputeHeader, &nameFun_M_ComputeHeader, &step_M_ComputeHeader};

int step_M_ComputeHeader(Sink sink__V108, Term term__V109)
{
  int term__V109_count = LINK_COUNT(term__V109); permitUnusedInt(term__V109_count);
  Term sub__V110 = FORCE(sink__V108->context, SUB(term__V109, 0));
  EnumOf_M_Reify_xCRSX choice__V111 = (IS_VARIABLE_USE(sub__V110) ? VarOf_M_Reify_xCRSX : (EnumOf_M_Reify_xCRSX) TAG(sub__V110));
  switch (choice__V111)
  {
    case Data_M_CRSX: { /* Function HEADER-ComputeHeader-1$ComputeHeader$CRSX case CRSX */
      ASSERT(sink__V108->context, !strcmp(SYMBOL(term__V109),  "ComputeHeader" ));
      Term sub__V112 = SUB(term__V109, 0); permitUnusedTerm(sub__V112); int sub__V112_count = term__V109_count*LINK_COUNT(sub__V112); permitUnusedInt(sub__V112_count);
      CRSX_CHECK_SORT(sink__V108->context, sub__V112, &sort_M_Reify_xCRSX); ASSERT(sink__V108->context, !strcmp(SYMBOL(sub__V112),  "CRSX" ));
      Term sub__V113 = LINK(sink__V108->context, SUB(sub__V112, 0)); int sub__V113_count = sub__V112_count*LINK_COUNT(sub__V113); permitUnusedInt(sub__V113_count);
      /* sub__V113 = &#0-0 */
      Term sub__V114 = LINK(sink__V108->context, SUB(sub__V112, 1)); int sub__V114_count = sub__V112_count*LINK_COUNT(sub__V114); permitUnusedInt(sub__V114_count);
      /* sub__V114 = &#0-1 */
      
      NamedPropertyLink namedP__V115 = LINK_NamedPropertyLink(sink__V108->context, NAMED_PROPERTIES(term__V109));
      VariablePropertyLink varP__V116 = LINK_VariablePropertyLink(sink__V108->context, VARIABLE_PROPERTIES(term__V109));
      Hashset namedFV__V117 = LINK_VARIABLESET(sink__V108->context, asConstruction(term__V109)->properties->namedFreeVars);
      Hashset varFV__V118 = LINK_VARIABLESET(sink__V108->context, asConstruction(term__V109)->properties->variableFreeVars);
      UNLINK(sink__V108->context, term__V109);
      ADD_PROPERTIES(sink__V108, LINK_VARIABLESET(sink__V108->context, namedFV__V117), LINK_VARIABLESET(sink__V108->context, varFV__V118), LINK_NamedPropertyLink(sink__V108->context, namedP__V115), LINK_VariablePropertyLink(sink__V108->context, varP__V116));
      { START(sink__V108, _M_ComputeHeader_s1);
        COPY(sink__V108, sub__V113);COPY(sink__V108, sub__V114);END(sink__V108, _M_ComputeHeader_s1); }
      UNLINK_VARIABLESET(sink__V108->context, namedFV__V117); UNLINK_VARIABLESET(sink__V108->context, varFV__V118);
      UNLINK_NamedPropertyLink(sink__V108->context, namedP__V115); UNLINK_VariablePropertyLink(sink__V108->context, varP__V116);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION H-Declaration. */
int conBindOffs_M_H_Declaration[] = {0 , 0};
char *nameFun_M_H_Declaration(Term term) { return  "H-Declaration" ; }
struct _ConstructionDescriptor descriptor_M_H_Declaration = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_H_Declaration), conBindOffs_M_H_Declaration, &nameFun_M_H_Declaration, &step_M_H_Declaration};

int step_M_H_Declaration(Sink sink__V119, Term term__V120)
{
  int term__V120_count = LINK_COUNT(term__V120); permitUnusedInt(term__V120_count);
  Term sub__V121 = FORCE(sink__V119->context, SUB(term__V120, 0));
  EnumOf_M_Reified_xDeclaration choice__V122 = (IS_VARIABLE_USE(sub__V121) ? VarOf_M_Reified_xDeclaration : (EnumOf_M_Reified_xDeclaration) TAG(sub__V121));
  switch (choice__V122)
  {
    case Data_M_DATA: { /* Function HEADER-Data$H-Declaration$DATA case DATA */
      ASSERT(sink__V119->context, !strcmp(SYMBOL(term__V120),  "H-Declaration" ));
      Term sub__V123 = SUB(term__V120, 0); permitUnusedTerm(sub__V123); int sub__V123_count = term__V120_count*LINK_COUNT(sub__V123); permitUnusedInt(sub__V123_count);
      CRSX_CHECK_SORT(sink__V119->context, sub__V123, &sort_M_Reified_xDeclaration); ASSERT(sink__V119->context, !strcmp(SYMBOL(sub__V123),  "DATA" ));
      Term sub__V124 = LINK(sink__V119->context, SUB(sub__V123, 0)); int sub__V124_count = sub__V123_count*LINK_COUNT(sub__V124); permitUnusedInt(sub__V124_count);
      CRSX_CHECK_SORT(sink__V119->context, sub__V124, &sort_M_Reified_xSort); /* sub__V124 = &#0-0 */
      Term sub__V125 = LINK(sink__V119->context, SUB(sub__V123, 1)); int sub__V125_count = sub__V123_count*LINK_COUNT(sub__V125); permitUnusedInt(sub__V125_count);
      /* sub__V125 = &#0-1 */
      
      NamedPropertyLink namedP__V126 = LINK_NamedPropertyLink(sink__V119->context, NAMED_PROPERTIES(term__V120));
      VariablePropertyLink varP__V127 = LINK_VariablePropertyLink(sink__V119->context, VARIABLE_PROPERTIES(term__V120));
      Hashset namedFV__V128 = LINK_VARIABLESET(sink__V119->context, asConstruction(term__V120)->properties->namedFreeVars);
      Hashset varFV__V129 = LINK_VARIABLESET(sink__V119->context, asConstruction(term__V120)->properties->variableFreeVars);
      UNLINK(sink__V119->context, term__V120);
      ADD_PROPERTIES(sink__V119, LINK_VARIABLESET(sink__V119->context, namedFV__V128), LINK_VARIABLESET(sink__V119->context, varFV__V129), LINK_NamedPropertyLink(sink__V119->context, namedP__V126), LINK_VariablePropertyLink(sink__V119->context, varP__V127));
      { START(sink__V119, _M_H_Declaration_s1);
        COPY(sink__V119, sub__V124);COPY(sink__V119, sub__V125);END(sink__V119, _M_H_Declaration_s1); }
      UNLINK_VARIABLESET(sink__V119->context, namedFV__V128); UNLINK_VARIABLESET(sink__V119->context, varFV__V129);
      UNLINK_NamedPropertyLink(sink__V119->context, namedP__V126); UNLINK_VariablePropertyLink(sink__V119->context, varP__V127);
      
      return 1;
    break; } case Data_M_FUNCTION: { /* Function HEADER-Function$H-Declaration$FUNCTION case FUNCTION */
      ASSERT(sink__V119->context, !strcmp(SYMBOL(term__V120),  "H-Declaration" ));
      Term sub__V130 = SUB(term__V120, 0); permitUnusedTerm(sub__V130); int sub__V130_count = term__V120_count*LINK_COUNT(sub__V130); permitUnusedInt(sub__V130_count);
      CRSX_CHECK_SORT(sink__V119->context, sub__V130, &sort_M_Reified_xDeclaration); ASSERT(sink__V119->context, !strcmp(SYMBOL(sub__V130),  "FUNCTION" ));
      Term sub__V131 = LINK(sink__V119->context, SUB(sub__V130, 0)); int sub__V131_count = sub__V130_count*LINK_COUNT(sub__V131); permitUnusedInt(sub__V131_count);
      /* sub__V131 = &#0-0 */
      Term sub__V132 = LINK(sink__V119->context, SUB(sub__V130, 1)); int sub__V132_count = sub__V130_count*LINK_COUNT(sub__V132); permitUnusedInt(sub__V132_count);
      /* sub__V132 = &#0-1 */
      Term sub__V133 = LINK(sink__V119->context, SUB(sub__V130, 2)); int sub__V133_count = sub__V130_count*LINK_COUNT(sub__V133); permitUnusedInt(sub__V133_count);
      /* sub__V133 = &#0-2 */
      Term sub__V134 = LINK(sink__V119->context, SUB(sub__V130, 3)); int sub__V134_count = sub__V130_count*LINK_COUNT(sub__V134); permitUnusedInt(sub__V134_count);
      /* sub__V134 = &#0-3 */
      Term sub__V135 = LINK(sink__V119->context, SUB(sub__V130, 4)); int sub__V135_count = sub__V130_count*LINK_COUNT(sub__V135); permitUnusedInt(sub__V135_count);
      /* sub__V135 = &#0-4 */
      Term sub__V136 = LINK(sink__V119->context, SUB(sub__V130, 5)); int sub__V136_count = sub__V130_count*LINK_COUNT(sub__V136); permitUnusedInt(sub__V136_count);
      CRSX_CHECK_SORT(sink__V119->context, sub__V136, &sort_M_Reified_xSort); /* sub__V136 = &#0-5 */
      Term sub__V137 = LINK(sink__V119->context, SUB(sub__V130, 6)); int sub__V137_count = sub__V130_count*LINK_COUNT(sub__V137); permitUnusedInt(sub__V137_count);
      /* sub__V137 = &#0-6 */
      
      NamedPropertyLink namedP__V138 = LINK_NamedPropertyLink(sink__V119->context, NAMED_PROPERTIES(term__V120));
      VariablePropertyLink varP__V139 = LINK_VariablePropertyLink(sink__V119->context, VARIABLE_PROPERTIES(term__V120));
      Hashset namedFV__V140 = LINK_VARIABLESET(sink__V119->context, asConstruction(term__V120)->properties->namedFreeVars);
      Hashset varFV__V141 = LINK_VARIABLESET(sink__V119->context, asConstruction(term__V120)->properties->variableFreeVars);
      UNLINK(sink__V119->context, term__V120);
      ADD_PROPERTIES(sink__V119, LINK_VARIABLESET(sink__V119->context, namedFV__V140), LINK_VARIABLESET(sink__V119->context, varFV__V141), LINK_NamedPropertyLink(sink__V119->context, namedP__V138), LINK_VariablePropertyLink(sink__V119->context, varP__V139));
      { START(sink__V119, _M_H_Declaration_s2);
        COPY(sink__V119, sub__V131);COPY(sink__V119, sub__V132);COPY(sink__V119, sub__V133);COPY(sink__V119, sub__V134);COPY(sink__V119, sub__V135);COPY(sink__V119, sub__V136);COPY(sink__V119, sub__V137);END(sink__V119, _M_H_Declaration_s2); }
      UNLINK_VARIABLESET(sink__V119->context, namedFV__V140); UNLINK_VARIABLESET(sink__V119->context, varFV__V141);
      UNLINK_NamedPropertyLink(sink__V119->context, namedP__V138); UNLINK_VariablePropertyLink(sink__V119->context, varP__V139);
      
      return 1;
    break; } case Data_M_POLYMORPHIC: { /* Function HEADER-Polymorphic$H-Declaration$POLYMORPHIC case POLYMORPHIC */
      ASSERT(sink__V119->context, !strcmp(SYMBOL(term__V120),  "H-Declaration" ));
      Term sub__V142 = SUB(term__V120, 0); permitUnusedTerm(sub__V142); int sub__V142_count = term__V120_count*LINK_COUNT(sub__V142); permitUnusedInt(sub__V142_count);
      CRSX_CHECK_SORT(sink__V119->context, sub__V142, &sort_M_Reified_xDeclaration); ASSERT(sink__V119->context, !strcmp(SYMBOL(sub__V142),  "POLYMORPHIC" ));
      Variable y__V143 = BINDER(sub__V142,0,0); if (sub__V142_count <= 1) UNBIND(y__V143);
      Term sub__V144 = LINK(sink__V119->context, SUB(sub__V142, 0)); int sub__V144_count = sub__V142_count*LINK_COUNT(sub__V144); permitUnusedInt(sub__V144_count);
      CRSX_CHECK_SORT(sink__V119->context, sub__V144, &sort_M_Reified_xDeclaration); /* sub__V144 = &#0-0 */
      
      NamedPropertyLink namedP__V145 = LINK_NamedPropertyLink(sink__V119->context, NAMED_PROPERTIES(term__V120));
      VariablePropertyLink varP__V146 = LINK_VariablePropertyLink(sink__V119->context, VARIABLE_PROPERTIES(term__V120));
      Hashset namedFV__V147 = LINK_VARIABLESET(sink__V119->context, asConstruction(term__V120)->properties->namedFreeVars);
      Hashset varFV__V148 = LINK_VARIABLESET(sink__V119->context, asConstruction(term__V120)->properties->variableFreeVars);
      UNLINK(sink__V119->context, term__V120);
      ADD_PROPERTIES(sink__V119, LINK_VARIABLESET(sink__V119->context, namedFV__V147), LINK_VARIABLESET(sink__V119->context, varFV__V148), LINK_NamedPropertyLink(sink__V119->context, namedP__V145), LINK_VariablePropertyLink(sink__V119->context, varP__V146));
      { START(sink__V119, _M_H_Declaration_s3);
        { if (!IS_BOUND(y__V143)) { REBIND(y__V143);
            Variable binds__V149[1] = {y__V143}; BINDS(sink__V119, 1, binds__V149);
            COPY(sink__V119, sub__V144); /* REUSED SUBSTITUTION */  }
          else { Variable b__V150 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V119->context,"b__V150");
            Variable binds__V151[1] = {b__V150}; BINDS(sink__V119, 1, binds__V151);
            {
              Term arg__V152;
              { Sink buf__V153 = ALLOCA_BUFFER(sink__V119->context);
                USE(buf__V153, b__V150); arg__V152 = BUFFER_TERM(buf__V153); FREE_BUFFER(buf__V153); }
              Variable vars__V154[1] = {y__V143};
              Term args__V155[1] = {arg__V152};
              struct _SubstitutionFrame substitution__V156 = {NULL, 0, 1, vars__V154, args__V155, NULL};
              SUBSTITUTE(sink__V119, sub__V144, &substitution__V156); }
                }
           }
        END(sink__V119, _M_H_Declaration_s3); }
      UNLINK_VARIABLESET(sink__V119->context, namedFV__V147); UNLINK_VARIABLESET(sink__V119->context, varFV__V148);
      UNLINK_NamedPropertyLink(sink__V119->context, namedP__V145); UNLINK_VariablePropertyLink(sink__V119->context, varP__V146);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION H-Declarations. */
int conBindOffs_M_H_Declarations[] = {0 , 0};
char *nameFun_M_H_Declarations(Term term) { return  "H-Declarations" ; }
struct _ConstructionDescriptor descriptor_M_H_Declarations = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_H_Declarations), conBindOffs_M_H_Declarations, &nameFun_M_H_Declarations, &step_M_H_Declarations};

int step_M_H_Declarations(Sink sink__V157, Term term__V158)
{
  int term__V158_count = LINK_COUNT(term__V158); permitUnusedInt(term__V158_count);
  Term sub__V159 = FORCE(sink__V157->context, SUB(term__V158, 0));
  EnumOf_M__sList choice__V160 = (IS_VARIABLE_USE(sub__V159) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V159));
  switch (choice__V160)
  {
    case Data_M__sCons: { /* Function HEADER-H-Declarations-1$H-Declarations$$Cons case $Cons */
      ASSERT(sink__V157->context, !strcmp(SYMBOL(term__V158),  "H-Declarations" ));
      Term sub__V161 = SUB(term__V158, 0); permitUnusedTerm(sub__V161); int sub__V161_count = term__V158_count*LINK_COUNT(sub__V161); permitUnusedInt(sub__V161_count);
      ASSERT(sink__V157->context, !strcmp(SYMBOL(sub__V161),  "$Cons" ));
      Term sub__V162 = LINK(sink__V157->context, SUB(sub__V161, 0)); int sub__V162_count = sub__V161_count*LINK_COUNT(sub__V162); permitUnusedInt(sub__V162_count);
      /* sub__V162 = &#0-0 */
      Term sub__V163 = LINK(sink__V157->context, SUB(sub__V161, 1)); int sub__V163_count = sub__V161_count*LINK_COUNT(sub__V163); permitUnusedInt(sub__V163_count);
      /* sub__V163 = &#0-1 */
      
      NamedPropertyLink namedP__V164 = LINK_NamedPropertyLink(sink__V157->context, NAMED_PROPERTIES(term__V158));
      VariablePropertyLink varP__V165 = LINK_VariablePropertyLink(sink__V157->context, VARIABLE_PROPERTIES(term__V158));
      Hashset namedFV__V166 = LINK_VARIABLESET(sink__V157->context, asConstruction(term__V158)->properties->namedFreeVars);
      Hashset varFV__V167 = LINK_VARIABLESET(sink__V157->context, asConstruction(term__V158)->properties->variableFreeVars);
      UNLINK(sink__V157->context, term__V158);
      ADD_PROPERTIES(sink__V157, LINK_VARIABLESET(sink__V157->context, namedFV__V166), LINK_VARIABLESET(sink__V157->context, varFV__V167), LINK_NamedPropertyLink(sink__V157->context, namedP__V164), LINK_VariablePropertyLink(sink__V157->context, varP__V165));
      { START(sink__V157, _M_H_Declarations_s1);
        COPY(sink__V157, sub__V162);COPY(sink__V157, sub__V163);END(sink__V157, _M_H_Declarations_s1); }
      UNLINK_VARIABLESET(sink__V157->context, namedFV__V166); UNLINK_VARIABLESET(sink__V157->context, varFV__V167);
      UNLINK_NamedPropertyLink(sink__V157->context, namedP__V164); UNLINK_VariablePropertyLink(sink__V157->context, varP__V165);
      
      return 1;
    break; } case Data_M__sNil: { /* Function HEADER-H-Declarations-2$H-Declarations$$Nil case $Nil */
      ASSERT(sink__V157->context, !strcmp(SYMBOL(term__V158),  "H-Declarations" ));
      Term sub__V168 = SUB(term__V158, 0); permitUnusedTerm(sub__V168); int sub__V168_count = term__V158_count*LINK_COUNT(sub__V168); permitUnusedInt(sub__V168_count);
      ASSERT(sink__V157->context, !strcmp(SYMBOL(sub__V168),  "$Nil" ));
      
      NamedPropertyLink namedP__V169 = LINK_NamedPropertyLink(sink__V157->context, NAMED_PROPERTIES(term__V158));
      VariablePropertyLink varP__V170 = LINK_VariablePropertyLink(sink__V157->context, VARIABLE_PROPERTIES(term__V158));
      Hashset namedFV__V171 = LINK_VARIABLESET(sink__V157->context, asConstruction(term__V158)->properties->namedFreeVars);
      Hashset varFV__V172 = LINK_VARIABLESET(sink__V157->context, asConstruction(term__V158)->properties->variableFreeVars);
      UNLINK(sink__V157->context, term__V158);
      ADD_PROPERTIES(sink__V157, LINK_VARIABLESET(sink__V157->context, namedFV__V171), LINK_VARIABLESET(sink__V157->context, varFV__V172), LINK_NamedPropertyLink(sink__V157->context, namedP__V169), LINK_VariablePropertyLink(sink__V157->context, varP__V170));
      { START(sink__V157, _M_H_Declarations_s2);
        END(sink__V157, _M_H_Declarations_s2); }
      UNLINK_VARIABLESET(sink__V157->context, namedFV__V171); UNLINK_VARIABLESET(sink__V157->context, varFV__V172);
      UNLINK_NamedPropertyLink(sink__V157->context, namedP__V169); UNLINK_VariablePropertyLink(sink__V157->context, varP__V170);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION H-Declarations$2. */
int conBindOffs_M_H_Declarations_s2[] = {0};
char *nameFun_M_H_Declarations_s2(Term term) { return  "H-Declarations$2" ; }
struct _ConstructionDescriptor descriptor_M_H_Declarations_s2 = {&sort_M_Reified_xVariable, 0, 0, sizeof(STRUCT_Con_M_H_Declarations_s2), conBindOffs_M_H_Declarations_s2, &nameFun_M_H_Declarations_s2, &step_M_H_Declarations_s2};

int step_M_H_Declarations_s2(Sink sink__V173, Term term__V174)
{
  int term__V174_count = LINK_COUNT(term__V174); permitUnusedInt(term__V174_count);
  do {
    /* Contraction rule HEADER-H-Declarations-2. */
    ASSERT(sink__V173->context, !strcmp(SYMBOL(term__V174),  "H-Declarations$2" ));
    
    NamedPropertyLink namedP__V175 = LINK_NamedPropertyLink(sink__V173->context, NAMED_PROPERTIES(term__V174));
    VariablePropertyLink varP__V176 = LINK_VariablePropertyLink(sink__V173->context, VARIABLE_PROPERTIES(term__V174));
    Hashset namedFV__V177 = LINK_VARIABLESET(sink__V173->context, asConstruction(term__V174)->properties->namedFreeVars);
    Hashset varFV__V178 = LINK_VARIABLESET(sink__V173->context, asConstruction(term__V174)->properties->variableFreeVars);
    UNLINK(sink__V173->context, term__V174);
    { START(sink__V173, _M__sTextNil); END(sink__V173, _M__sTextNil); }
    UNLINK_VARIABLESET(sink__V173->context, namedFV__V177); UNLINK_VARIABLESET(sink__V173->context, varFV__V178);
    UNLINK_NamedPropertyLink(sink__V173->context, namedP__V175); UNLINK_VariablePropertyLink(sink__V173->context, varP__V176);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Declarations$1. */
int conBindOffs_M_H_Declarations_s1[] = {0 , 0 , 0};
char *nameFun_M_H_Declarations_s1(Term term) { return  "H-Declarations$1" ; }
struct _ConstructionDescriptor descriptor_M_H_Declarations_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_H_Declarations_s1), conBindOffs_M_H_Declarations_s1, &nameFun_M_H_Declarations_s1, &step_M_H_Declarations_s1};

int step_M_H_Declarations_s1(Sink sink__V179, Term term__V180)
{
  int term__V180_count = LINK_COUNT(term__V180); permitUnusedInt(term__V180_count);
  do {
    /* Contraction rule HEADER-H-Declarations-1. */
    ASSERT(sink__V179->context, !strcmp(SYMBOL(term__V180),  "H-Declarations$1" ));
    Term sub__V181 = LINK(sink__V179->context, SUB(term__V180, 0)); int sub__V181_count = term__V180_count*LINK_COUNT(sub__V181); permitUnusedInt(sub__V181_count);
    /* sub__V181 = &#11 */
    Term sub__V182 = LINK(sink__V179->context, SUB(term__V180, 1)); int sub__V182_count = term__V180_count*LINK_COUNT(sub__V182); permitUnusedInt(sub__V182_count);
    /* sub__V182 = &#12 */
    
    NamedPropertyLink namedP__V183 = LINK_NamedPropertyLink(sink__V179->context, NAMED_PROPERTIES(term__V180));
    VariablePropertyLink varP__V184 = LINK_VariablePropertyLink(sink__V179->context, VARIABLE_PROPERTIES(term__V180));
    Hashset namedFV__V185 = LINK_VARIABLESET(sink__V179->context, asConstruction(term__V180)->properties->namedFreeVars);
    Hashset varFV__V186 = LINK_VARIABLESET(sink__V179->context, asConstruction(term__V180)->properties->variableFreeVars);
    UNLINK(sink__V179->context, term__V180);
    { START(sink__V179, _M__sTextCons);
      { START(sink__V179, _M__sTextEmbed);
        { START(sink__V179, _M_AsText);
          { START(sink__V179, _M_H_Declaration);
            COPY(sink__V179, sub__V181);END(sink__V179, _M_H_Declaration); }
          END(sink__V179, _M_AsText); }
        END(sink__V179, _M__sTextEmbed); }
      { START(sink__V179, _M__sTextCons);
        { START(sink__V179, _M__sTextEmbed);
          { START(sink__V179, _M_AsText);
            { START(sink__V179, _M_H_Declarations);
              COPY(sink__V179, sub__V182);END(sink__V179, _M_H_Declarations); }
            END(sink__V179, _M_AsText); }
          END(sink__V179, _M__sTextEmbed); }
        { START(sink__V179, _M__sTextNil);
          END(sink__V179, _M__sTextNil); }
        END(sink__V179, _M__sTextCons); }
      END(sink__V179, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V179->context, namedFV__V185); UNLINK_VARIABLESET(sink__V179->context, varFV__V186);
    UNLINK_NamedPropertyLink(sink__V179->context, namedP__V183); UNLINK_VariablePropertyLink(sink__V179->context, varP__V184);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Data. */
int conBindOffs_M_H_Data[] = {0 , 0 , 0};
char *nameFun_M_H_Data(Term term) { return  "H-Data" ; }
struct _ConstructionDescriptor descriptor_M_H_Data = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_H_Data), conBindOffs_M_H_Data, &nameFun_M_H_Data, &step_M_H_Data};

int step_M_H_Data(Sink sink__V187, Term term__V188)
{
  int term__V188_count = LINK_COUNT(term__V188); permitUnusedInt(term__V188_count);
  Term sub__V189 = FORCE(sink__V187->context, SUB(term__V188, 0));
  EnumOf_M_Reified_xSort choice__V190 = (IS_VARIABLE_USE(sub__V189) ? VarOf_M_Reified_xSort : (EnumOf_M_Reified_xSort) TAG(sub__V189));
  switch (choice__V190)
  {
    case Data_M_SORT: { /* Function HEADER-H-Data-1$H-Data$SORT case SORT */
      ASSERT(sink__V187->context, !strcmp(SYMBOL(term__V188),  "H-Data" ));
      Term sub__V191 = SUB(term__V188, 0); permitUnusedTerm(sub__V191); int sub__V191_count = term__V188_count*LINK_COUNT(sub__V191); permitUnusedInt(sub__V191_count);
      CRSX_CHECK_SORT(sink__V187->context, sub__V191, &sort_M_Reified_xSort); ASSERT(sink__V187->context, !strcmp(SYMBOL(sub__V191),  "SORT" ));
      Term sub__V192 = LINK(sink__V187->context, SUB(sub__V191, 0)); int sub__V192_count = sub__V191_count*LINK_COUNT(sub__V192); permitUnusedInt(sub__V192_count);
      /* sub__V192 = &#0-0 */
      Term sub__V193 = LINK(sink__V187->context, SUB(sub__V191, 1)); int sub__V193_count = sub__V191_count*LINK_COUNT(sub__V193); permitUnusedInt(sub__V193_count);
      /* sub__V193 = &#0-1 */
      Term sub__V194 = LINK(sink__V187->context, SUB(term__V188, 1)); int sub__V194_count = term__V188_count*LINK_COUNT(sub__V194); permitUnusedInt(sub__V194_count);
      /* sub__V194 = &#2 */
      
      NamedPropertyLink namedP__V195 = LINK_NamedPropertyLink(sink__V187->context, NAMED_PROPERTIES(term__V188));
      VariablePropertyLink varP__V196 = LINK_VariablePropertyLink(sink__V187->context, VARIABLE_PROPERTIES(term__V188));
      Hashset namedFV__V197 = LINK_VARIABLESET(sink__V187->context, asConstruction(term__V188)->properties->namedFreeVars);
      Hashset varFV__V198 = LINK_VARIABLESET(sink__V187->context, asConstruction(term__V188)->properties->variableFreeVars);
      UNLINK(sink__V187->context, term__V188);
      ADD_PROPERTIES(sink__V187, LINK_VARIABLESET(sink__V187->context, namedFV__V197), LINK_VARIABLESET(sink__V187->context, varFV__V198), LINK_NamedPropertyLink(sink__V187->context, namedP__V195), LINK_VariablePropertyLink(sink__V187->context, varP__V196));
      { START(sink__V187, _M_H_Data_s1);
        COPY(sink__V187, sub__V192);COPY(sink__V187, sub__V193);COPY(sink__V187, sub__V194);END(sink__V187, _M_H_Data_s1); }
      UNLINK_VARIABLESET(sink__V187->context, namedFV__V197); UNLINK_VARIABLESET(sink__V187->context, varFV__V198);
      UNLINK_NamedPropertyLink(sink__V187->context, namedP__V195); UNLINK_VariablePropertyLink(sink__V187->context, varP__V196);
      
      return 1;
    break; } case Data_M_SORT_PROPERTY: { /* Function HEADER-H-Data-2$H-Data$SORT-PROPERTY case SORT-PROPERTY */
      ASSERT(sink__V187->context, !strcmp(SYMBOL(term__V188),  "H-Data" ));
      Term sub__V199 = SUB(term__V188, 0); permitUnusedTerm(sub__V199); int sub__V199_count = term__V188_count*LINK_COUNT(sub__V199); permitUnusedInt(sub__V199_count);
      CRSX_CHECK_SORT(sink__V187->context, sub__V199, &sort_M_Reified_xSort); ASSERT(sink__V187->context, !strcmp(SYMBOL(sub__V199),  "SORT-PROPERTY" ));
      Term sub__V200 = LINK(sink__V187->context, SUB(sub__V199, 0)); int sub__V200_count = sub__V199_count*LINK_COUNT(sub__V200); permitUnusedInt(sub__V200_count);
      CRSX_CHECK_SORT(sink__V187->context, sub__V200, &sort_M_Reified_xSort); /* sub__V200 = &#0-0 */
      Term sub__V201 = LINK(sink__V187->context, SUB(sub__V199, 1)); int sub__V201_count = sub__V199_count*LINK_COUNT(sub__V201); permitUnusedInt(sub__V201_count);
      CRSX_CHECK_SORT(sink__V187->context, sub__V201, &sort_M_Reified_xSort); /* sub__V201 = &#0-1 */
      Term sub__V202 = LINK(sink__V187->context, SUB(sub__V199, 2)); int sub__V202_count = sub__V199_count*LINK_COUNT(sub__V202); permitUnusedInt(sub__V202_count);
      CRSX_CHECK_SORT(sink__V187->context, sub__V202, &sort_M_Reified_xSort); /* sub__V202 = &#0-2 */
      Term sub__V203 = LINK(sink__V187->context, SUB(term__V188, 1)); int sub__V203_count = term__V188_count*LINK_COUNT(sub__V203); permitUnusedInt(sub__V203_count);
      /* sub__V203 = &#3 */
      
      NamedPropertyLink namedP__V204 = LINK_NamedPropertyLink(sink__V187->context, NAMED_PROPERTIES(term__V188));
      VariablePropertyLink varP__V205 = LINK_VariablePropertyLink(sink__V187->context, VARIABLE_PROPERTIES(term__V188));
      Hashset namedFV__V206 = LINK_VARIABLESET(sink__V187->context, asConstruction(term__V188)->properties->namedFreeVars);
      Hashset varFV__V207 = LINK_VARIABLESET(sink__V187->context, asConstruction(term__V188)->properties->variableFreeVars);
      UNLINK(sink__V187->context, term__V188);
      ADD_PROPERTIES(sink__V187, LINK_VARIABLESET(sink__V187->context, namedFV__V206), LINK_VARIABLESET(sink__V187->context, varFV__V207), LINK_NamedPropertyLink(sink__V187->context, namedP__V204), LINK_VariablePropertyLink(sink__V187->context, varP__V205));
      { START(sink__V187, _M_H_Data_s2);
        COPY(sink__V187, sub__V200);COPY(sink__V187, sub__V201);COPY(sink__V187, sub__V202);COPY(sink__V187, sub__V203);END(sink__V187, _M_H_Data_s2); }
      UNLINK_VARIABLESET(sink__V187->context, namedFV__V206); UNLINK_VARIABLESET(sink__V187->context, varFV__V207);
      UNLINK_NamedPropertyLink(sink__V187->context, namedP__V204); UNLINK_VariablePropertyLink(sink__V187->context, varP__V205);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION H-Declaration$3. */
int conBindOffs_M_H_Declaration_s3[] = {0 , 1};
char *nameFun_M_H_Declaration_s3(Term term) { return  "H-Declaration$3" ; }
struct _ConstructionDescriptor descriptor_M_H_Declaration_s3 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_H_Declaration_s3), conBindOffs_M_H_Declaration_s3, &nameFun_M_H_Declaration_s3, &step_M_H_Declaration_s3};

int step_M_H_Declaration_s3(Sink sink__V208, Term term__V209)
{
  int term__V209_count = LINK_COUNT(term__V209); permitUnusedInt(term__V209_count);
  do {
    /* Contraction rule HEADER-Polymorphic. */
    ASSERT(sink__V208->context, !strcmp(SYMBOL(term__V209),  "H-Declaration$3" ));
    Variable x__V210 = BINDER(term__V209,0,0); if (term__V209_count <= 1) UNBIND(x__V210);
    Term sub__V211 = LINK(sink__V208->context, SUB(term__V209, 0)); int sub__V211_count = term__V209_count*LINK_COUNT(sub__V211); permitUnusedInt(sub__V211_count);
    CRSX_CHECK_SORT(sink__V208->context, sub__V211, &sort_M_Reified_xDeclaration); /* sub__V211 = &#11 */
    Variable y__V212 = x__V210; permitUnusedVariable(y__V212);
    
    NamedPropertyLink namedP__V213 = LINK_NamedPropertyLink(sink__V208->context, NAMED_PROPERTIES(term__V209));
    VariablePropertyLink varP__V214 = LINK_VariablePropertyLink(sink__V208->context, VARIABLE_PROPERTIES(term__V209));
    Hashset namedFV__V215 = LINK_VARIABLESET(sink__V208->context, asConstruction(term__V209)->properties->namedFreeVars);
    Hashset varFV__V216 = LINK_VARIABLESET(sink__V208->context, asConstruction(term__V209)->properties->variableFreeVars);
    UNLINK(sink__V208->context, term__V209);
    { START(sink__V208, _M_H_Declaration);
      COPY(sink__V208, sub__V211); /* REUSED SUBSTITUTION */ END(sink__V208, _M_H_Declaration); }
    UNLINK_VARIABLESET(sink__V208->context, namedFV__V215); UNLINK_VARIABLESET(sink__V208->context, varFV__V216);
    UNLINK_NamedPropertyLink(sink__V208->context, namedP__V213); UNLINK_VariablePropertyLink(sink__V208->context, varP__V214);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Declaration$2. */
int conBindOffs_M_H_Declaration_s2[] = {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0};
char *nameFun_M_H_Declaration_s2(Term term) { return  "H-Declaration$2" ; }
struct _ConstructionDescriptor descriptor_M_H_Declaration_s2 = {&sort_M_Reified_xVariable, 0, 7, sizeof(STRUCT_Con_M_H_Declaration_s2), conBindOffs_M_H_Declaration_s2, &nameFun_M_H_Declaration_s2, &step_M_H_Declaration_s2};

int step_M_H_Declaration_s2(Sink sink__V217, Term term__V218)
{
  int term__V218_count = LINK_COUNT(term__V218); permitUnusedInt(term__V218_count);
  do {
    /* Contraction rule HEADER-Function. */
    ASSERT(sink__V217->context, !strcmp(SYMBOL(term__V218),  "H-Declaration$2" ));
    Term sub__V219 = LINK(sink__V217->context, SUB(term__V218, 0)); int sub__V219_count = term__V218_count*LINK_COUNT(sub__V219); permitUnusedInt(sub__V219_count);
    /* sub__V219 = &#11 */
    Term sub__V220 = LINK(sink__V217->context, SUB(term__V218, 1)); int sub__V220_count = term__V218_count*LINK_COUNT(sub__V220); permitUnusedInt(sub__V220_count);
    /* sub__V220 = &#12 */
    Term sub__V221 = LINK(sink__V217->context, SUB(term__V218, 2)); int sub__V221_count = term__V218_count*LINK_COUNT(sub__V221); permitUnusedInt(sub__V221_count);
    /* sub__V221 = &#13 */
    Term sub__V222 = LINK(sink__V217->context, SUB(term__V218, 3)); int sub__V222_count = term__V218_count*LINK_COUNT(sub__V222); permitUnusedInt(sub__V222_count);
    /* sub__V222 = &#14 */
    Term sub__V223 = LINK(sink__V217->context, SUB(term__V218, 4)); int sub__V223_count = term__V218_count*LINK_COUNT(sub__V223); permitUnusedInt(sub__V223_count);
    /* sub__V223 = &#15 */
    Term sub__V224 = LINK(sink__V217->context, SUB(term__V218, 5)); int sub__V224_count = term__V218_count*LINK_COUNT(sub__V224); permitUnusedInt(sub__V224_count);
    CRSX_CHECK_SORT(sink__V217->context, sub__V224, &sort_M_Reified_xSort); /* sub__V224 = &#16 */
    Term sub__V225 = LINK(sink__V217->context, SUB(term__V218, 6)); int sub__V225_count = term__V218_count*LINK_COUNT(sub__V225); permitUnusedInt(sub__V225_count);
    /* sub__V225 = &#17 */
    
    NamedPropertyLink namedP__V226 = LINK_NamedPropertyLink(sink__V217->context, NAMED_PROPERTIES(term__V218));
    VariablePropertyLink varP__V227 = LINK_VariablePropertyLink(sink__V217->context, VARIABLE_PROPERTIES(term__V218));
    Hashset namedFV__V228 = LINK_VARIABLESET(sink__V217->context, asConstruction(term__V218)->properties->namedFreeVars);
    Hashset varFV__V229 = LINK_VARIABLESET(sink__V217->context, asConstruction(term__V218)->properties->variableFreeVars);
    UNLINK(sink__V217->context, term__V218);
    { START(sink__V217, _M_H_Function);
      COPY(sink__V217, sub__V219);COPY(sink__V217, sub__V220);COPY(sink__V217, sub__V221);COPY(sink__V217, sub__V222);COPY(sink__V217, sub__V223);COPY(sink__V217, sub__V224);COPY(sink__V217, sub__V225);END(sink__V217, _M_H_Function); }
    UNLINK_VARIABLESET(sink__V217->context, namedFV__V228); UNLINK_VARIABLESET(sink__V217->context, varFV__V229);
    UNLINK_NamedPropertyLink(sink__V217->context, namedP__V226); UNLINK_VariablePropertyLink(sink__V217->context, varP__V227);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Declaration$1. */
int conBindOffs_M_H_Declaration_s1[] = {0 , 0 , 0};
char *nameFun_M_H_Declaration_s1(Term term) { return  "H-Declaration$1" ; }
struct _ConstructionDescriptor descriptor_M_H_Declaration_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_H_Declaration_s1), conBindOffs_M_H_Declaration_s1, &nameFun_M_H_Declaration_s1, &step_M_H_Declaration_s1};

int step_M_H_Declaration_s1(Sink sink__V230, Term term__V231)
{
  int term__V231_count = LINK_COUNT(term__V231); permitUnusedInt(term__V231_count);
  do {
    /* Contraction rule HEADER-Data. */
    ASSERT(sink__V230->context, !strcmp(SYMBOL(term__V231),  "H-Declaration$1" ));
    Term sub__V232 = LINK(sink__V230->context, SUB(term__V231, 0)); int sub__V232_count = term__V231_count*LINK_COUNT(sub__V232); permitUnusedInt(sub__V232_count);
    CRSX_CHECK_SORT(sink__V230->context, sub__V232, &sort_M_Reified_xSort); /* sub__V232 = &#11 */
    Term sub__V233 = LINK(sink__V230->context, SUB(term__V231, 1)); int sub__V233_count = term__V231_count*LINK_COUNT(sub__V233); permitUnusedInt(sub__V233_count);
    /* sub__V233 = &#12 */
    
    NamedPropertyLink namedP__V234 = LINK_NamedPropertyLink(sink__V230->context, NAMED_PROPERTIES(term__V231));
    VariablePropertyLink varP__V235 = LINK_VariablePropertyLink(sink__V230->context, VARIABLE_PROPERTIES(term__V231));
    Hashset namedFV__V236 = LINK_VARIABLESET(sink__V230->context, asConstruction(term__V231)->properties->namedFreeVars);
    Hashset varFV__V237 = LINK_VARIABLESET(sink__V230->context, asConstruction(term__V231)->properties->variableFreeVars);
    UNLINK(sink__V230->context, term__V231);
    { START(sink__V230, _M_H_Data);
      COPY(sink__V230, sub__V232);COPY(sink__V230, sub__V233);END(sink__V230, _M_H_Data); }
    UNLINK_VARIABLESET(sink__V230->context, namedFV__V236); UNLINK_VARIABLESET(sink__V230->context, varFV__V237);
    UNLINK_NamedPropertyLink(sink__V230->context, namedP__V234); UNLINK_VariablePropertyLink(sink__V230->context, varP__V235);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION H-Function. */
int conBindOffs_M_H_Function[] = {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0};
char *nameFun_M_H_Function(Term term) { return  "H-Function" ; }
struct _ConstructionDescriptor descriptor_M_H_Function = {&sort_M_Reified_xVariable, 0, 7, sizeof(STRUCT_Con_M_H_Function), conBindOffs_M_H_Function, &nameFun_M_H_Function, &step_M_H_Function};

int step_M_H_Function(Sink sink__V238, Term term__V239)
{
  int term__V239_count = LINK_COUNT(term__V239); permitUnusedInt(term__V239_count);
  do {
    /* Contraction rule HEADER-H-Function-1. */
    ASSERT(sink__V238->context, !strcmp(SYMBOL(term__V239),  "H-Function" ));
    Term sub__V240 = LINK(sink__V238->context, SUB(term__V239, 0)); int sub__V240_count = term__V239_count*LINK_COUNT(sub__V240); permitUnusedInt(sub__V240_count);
    /* sub__V240 = &#1 */
    Term sub__V241 = SUB(term__V239, 1); permitUnusedTerm(sub__V241); int sub__V241_count = term__V239_count*LINK_COUNT(sub__V241); permitUnusedInt(sub__V241_count);
    /* sub__V241 = &#2 */
    Term sub__V242 = SUB(term__V239, 2); permitUnusedTerm(sub__V242); int sub__V242_count = term__V239_count*LINK_COUNT(sub__V242); permitUnusedInt(sub__V242_count);
    /* sub__V242 = &#3 */
    Term sub__V243 = LINK(sink__V238->context, SUB(term__V239, 3)); int sub__V243_count = term__V239_count*LINK_COUNT(sub__V243); permitUnusedInt(sub__V243_count);
    /* sub__V243 = &#4 */
    Term sub__V244 = LINK(sink__V238->context, SUB(term__V239, 4)); int sub__V244_count = term__V239_count*LINK_COUNT(sub__V244); permitUnusedInt(sub__V244_count);
    /* sub__V244 = &#5 */
    Term sub__V245 = SUB(term__V239, 5); permitUnusedTerm(sub__V245); int sub__V245_count = term__V239_count*LINK_COUNT(sub__V245); permitUnusedInt(sub__V245_count);
    CRSX_CHECK_SORT(sink__V238->context, sub__V245, &sort_M_Reified_xSort); /* sub__V245 = &#6 */
    Term sub__V246 = SUB(term__V239, 6); permitUnusedTerm(sub__V246); int sub__V246_count = term__V239_count*LINK_COUNT(sub__V246); permitUnusedInt(sub__V246_count);
    /* sub__V246 = &#7 */
    
    NamedPropertyLink namedP__V247 = LINK_NamedPropertyLink(sink__V238->context, NAMED_PROPERTIES(term__V239));
    VariablePropertyLink varP__V248 = LINK_VariablePropertyLink(sink__V238->context, VARIABLE_PROPERTIES(term__V239));
    Hashset namedFV__V249 = LINK_VARIABLESET(sink__V238->context, asConstruction(term__V239)->properties->namedFreeVars);
    Hashset varFV__V250 = LINK_VARIABLESET(sink__V238->context, asConstruction(term__V239)->properties->variableFreeVars);
    UNLINK(sink__V238->context, term__V239);
    { START(sink__V238, _M__sTextCons);
      { START(sink__V238, _M__sTextBreak);
        LITERAL(sink__V238,  "\n" ); END(sink__V238, _M__sTextBreak); }
      { START(sink__V238, _M__sTextCons);
        { START(sink__V238, _M__sTextChars);
          LITERAL(sink__V238,  "/* FUNCTION " ); END(sink__V238, _M__sTextChars); }
        { START(sink__V238, _M__sTextCons);
          { START(sink__V238, _M__sTextEmbed);
            { START(sink__V238, _M_AsText);
              { START(sink__V238, _M_COMMENT_xTOKEN);
                COPY(sink__V238, sub__V240);END(sink__V238, _M_COMMENT_xTOKEN); }
              END(sink__V238, _M_AsText); }
            END(sink__V238, _M__sTextEmbed); }
          { START(sink__V238, _M__sTextCons);
            { START(sink__V238, _M__sTextChars);
              LITERAL(sink__V238,  " HEADER DECLARATIONS. */" ); END(sink__V238, _M__sTextChars); }
            { START(sink__V238, _M__sTextCons);
              { START(sink__V238, _M__sTextBreak);
                LITERAL(sink__V238,  "\n" ); END(sink__V238, _M__sTextBreak); }
              { START(sink__V238, _M__sTextCons);
                { START(sink__V238, _M__sTextEmbed);
                  { START(sink__V238, _M_AsText);
                    { START(sink__V238, _M_MapText_s1);
                      COPY(sink__V238, sub__V244);{ Variable x__V251 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V238->context,"x__V251");
                        Variable binds__V252[1] = {x__V251}; BINDS(sink__V238, 1, binds__V252);
                        { START(sink__V238, _M_H_Form);
                          USE(sink__V238, x__V251); END(sink__V238, _M_H_Form); }
                         }
                      END(sink__V238, _M_MapText_s1); }
                    END(sink__V238, _M_AsText); }
                  END(sink__V238, _M__sTextEmbed); }
                { START(sink__V238, _M__sTextCons);
                  { START(sink__V238, _M__sTextChars);
                    LITERAL(sink__V238,  "extern int " ); END(sink__V238, _M__sTextChars); }
                  { START(sink__V238, _M__sTextCons);
                    { START(sink__V238, _M__sTextEmbed);
                      { START(sink__V238, _M_AsText);
                        { START(sink__V238, _M_Step);
                          COPY(sink__V238, sub__V243);END(sink__V238, _M_Step); }
                        END(sink__V238, _M_AsText); }
                      END(sink__V238, _M__sTextEmbed); }
                    { START(sink__V238, _M__sTextCons);
                      { START(sink__V238, _M__sTextChars);
                        LITERAL(sink__V238,  "(Sink,Term);" ); END(sink__V238, _M__sTextChars); }
                      { START(sink__V238, _M__sTextCons);
                        { START(sink__V238, _M__sTextBreak);
                          LITERAL(sink__V238,  "\n" ); END(sink__V238, _M__sTextBreak); }
                        { START(sink__V238, _M__sTextNil);
                          END(sink__V238, _M__sTextNil); }
                        END(sink__V238, _M__sTextCons); }
                      END(sink__V238, _M__sTextCons); }
                    END(sink__V238, _M__sTextCons); }
                  END(sink__V238, _M__sTextCons); }
                END(sink__V238, _M__sTextCons); }
              END(sink__V238, _M__sTextCons); }
            END(sink__V238, _M__sTextCons); }
          END(sink__V238, _M__sTextCons); }
        END(sink__V238, _M__sTextCons); }
      END(sink__V238, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V238->context, namedFV__V249); UNLINK_VARIABLESET(sink__V238->context, varFV__V250);
    UNLINK_NamedPropertyLink(sink__V238->context, namedP__V247); UNLINK_VariablePropertyLink(sink__V238->context, varP__V248);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION ComputeHeader2. */
int conBindOffs_M_ComputeHeader2[] = {0 , 0 , 0 , 0};
char *nameFun_M_ComputeHeader2(Term term) { return  "ComputeHeader2" ; }
struct _ConstructionDescriptor descriptor_M_ComputeHeader2 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_ComputeHeader2), conBindOffs_M_ComputeHeader2, &nameFun_M_ComputeHeader2, &step_M_ComputeHeader2};

int step_M_ComputeHeader2(Sink sink__V253, Term term__V254)
{
  int term__V254_count = LINK_COUNT(term__V254); permitUnusedInt(term__V254_count);
  do {
    /* Contraction rule HEADER-ComputeHeader2-1. */
    ASSERT(sink__V253->context, !strcmp(SYMBOL(term__V254),  "ComputeHeader2" ));
    Term sub__V255 = LINK(sink__V253->context, SUB(term__V254, 0)); int sub__V255_count = term__V254_count*LINK_COUNT(sub__V255); permitUnusedInt(sub__V255_count);
    /* sub__V255 = &#1 */
    Term sub__V256 = LINK(sink__V253->context, SUB(term__V254, 1)); int sub__V256_count = term__V254_count*LINK_COUNT(sub__V256); permitUnusedInt(sub__V256_count);
    /* sub__V256 = &#2 */
    Term sub__V257 = LINK(sink__V253->context, SUB(term__V254, 2)); int sub__V257_count = term__V254_count*LINK_COUNT(sub__V257); permitUnusedInt(sub__V257_count);
    UNLINK_SUB(sink__V253->context, term__V254,  2); NORMALIZE(sink__V253->context, sub__V257); SUB(term__V254,  2) = LINK(sink__V253->context, sub__V257);
    /* sub__V257 = &#3 */
    
    NamedPropertyLink namedP__V258 = LINK_NamedPropertyLink(sink__V253->context, NAMED_PROPERTIES(term__V254));
    VariablePropertyLink varP__V259 = LINK_VariablePropertyLink(sink__V253->context, VARIABLE_PROPERTIES(term__V254));
    Hashset namedFV__V260 = LINK_VARIABLESET(sink__V253->context, asConstruction(term__V254)->properties->namedFreeVars);
    Hashset varFV__V261 = LINK_VARIABLESET(sink__V253->context, asConstruction(term__V254)->properties->variableFreeVars);
    UNLINK(sink__V253->context, term__V254);
    { START(sink__V253, _M__sTextCons);
      { START(sink__V253, _M__sTextChars);
        LITERAL(sink__V253,  "/* C HEADER FOR CRSX " ); END(sink__V253, _M__sTextChars); }
      { START(sink__V253, _M__sTextCons);
        { START(sink__V253, _M__sTextEmbed);
          { START(sink__V253, _M_AsText);
            { START(sink__V253, _M_COMMENT_xTOKEN);
              COPY(sink__V253, LINK(sink__V253->context, sub__V255));END(sink__V253, _M_COMMENT_xTOKEN); }
            END(sink__V253, _M_AsText); }
          END(sink__V253, _M__sTextEmbed); }
        { START(sink__V253, _M__sTextCons);
          { START(sink__V253, _M__sTextChars);
            LITERAL(sink__V253,  " MODULE " ); END(sink__V253, _M__sTextChars); }
          { START(sink__V253, _M__sTextCons);
            { START(sink__V253, _M__sTextEmbed);
              { START(sink__V253, _M_AsText);
                { START(sink__V253, _M_COMMENT_xTOKEN);
                  COPY(sink__V253, LINK(sink__V253->context, sub__V257));END(sink__V253, _M_COMMENT_xTOKEN); }
                END(sink__V253, _M_AsText); }
              END(sink__V253, _M__sTextEmbed); }
            { START(sink__V253, _M__sTextCons);
              { START(sink__V253, _M__sTextChars);
                LITERAL(sink__V253,  ". */" ); END(sink__V253, _M__sTextChars); }
              { START(sink__V253, _M__sTextCons);
                { START(sink__V253, _M__sTextBreak);
                  LITERAL(sink__V253,  "\n" ); END(sink__V253, _M__sTextBreak); }
                { START(sink__V253, _M__sTextCons);
                  { START(sink__V253, _M__sTextChars);
                    LITERAL(sink__V253,  "#ifndef CRSX_" ); END(sink__V253, _M__sTextChars); }
                  { START(sink__V253, _M__sTextCons);
                    { START(sink__V253, _M__sTextEmbed);
                      { START(sink__V253, _M_AsText);
                        { START(sink__V253, _M_MANGLE);
                          COPY(sink__V253, LINK(sink__V253->context, sub__V255));END(sink__V253, _M_MANGLE); }
                        END(sink__V253, _M_AsText); }
                      END(sink__V253, _M__sTextEmbed); }
                    { START(sink__V253, _M__sTextCons);
                      { START(sink__V253, _M__sTextEmbed);
                        { START(sink__V253, _M_AsText);
                          { START(sink__V253, _M_MANGLE);
                            COPY(sink__V253, LINK(sink__V253->context, sub__V257));END(sink__V253, _M_MANGLE); }
                          END(sink__V253, _M_AsText); }
                        END(sink__V253, _M__sTextEmbed); }
                      { START(sink__V253, _M__sTextCons);
                        { START(sink__V253, _M__sTextChars);
                          LITERAL(sink__V253,  "_H" ); END(sink__V253, _M__sTextChars); }
                        { START(sink__V253, _M__sTextCons);
                          { START(sink__V253, _M__sTextBreak);
                            LITERAL(sink__V253,  "\n" ); END(sink__V253, _M__sTextBreak); }
                          { START(sink__V253, _M__sTextCons);
                            { START(sink__V253, _M__sTextChars);
                              LITERAL(sink__V253,  "#define CRSX_" ); END(sink__V253, _M__sTextChars); }
                            { START(sink__V253, _M__sTextCons);
                              { START(sink__V253, _M__sTextEmbed);
                                { START(sink__V253, _M_AsText);
                                  { START(sink__V253, _M_MANGLE);
                                    COPY(sink__V253, LINK(sink__V253->context, sub__V255));END(sink__V253, _M_MANGLE); }
                                  END(sink__V253, _M_AsText); }
                                END(sink__V253, _M__sTextEmbed); }
                              { START(sink__V253, _M__sTextCons);
                                { START(sink__V253, _M__sTextEmbed);
                                  { START(sink__V253, _M_AsText);
                                    { START(sink__V253, _M_MANGLE);
                                      COPY(sink__V253, LINK(sink__V253->context, sub__V257));END(sink__V253, _M_MANGLE); }
                                    END(sink__V253, _M_AsText); }
                                  END(sink__V253, _M__sTextEmbed); }
                                { START(sink__V253, _M__sTextCons);
                                  { START(sink__V253, _M__sTextChars);
                                    LITERAL(sink__V253,  "_H" ); END(sink__V253, _M__sTextChars); }
                                  { START(sink__V253, _M__sTextCons);
                                    { START(sink__V253, _M__sTextBreak);
                                      LITERAL(sink__V253,  "\n" ); END(sink__V253, _M__sTextBreak); }
                                    { START(sink__V253, _M__sTextCons);
                                      { START(sink__V253, _M__sTextEmbed);
                                        { START(sink__V253, _M_AsText);
                                          { START(sink__V253, _M_DelayMapText_s1);
                                            {char* str__V262;{ Term term__V263;
                                                { char *value__V264 = getenv( "HEADERS" );
                                                  if (value__V264) term__V263 = makeStringLiteral(sink__V253->context, value__V264);
                                                  else {term__V263 = makeStringLiteral(sink__V253->context,  "" );
                                                    }
                                                }
                                                str__V262 = SYMBOL(term__V263);
                                                UNLINK(sink__V253->context, term__V263);
                                                }
                                              
                                              char* regex__V265;
                                              regex__V265 =  ";" ; SEND_SPLIT(str__V262, regex__V265, sink__V253);
                                            }
                                            { Variable x__V266 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V253->context,"x__V266");
                                              Variable x__V267 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V253->context,"x__V267");
                                              Variable binds__V268[2] = {x__V266,x__V267}; BINDS(sink__V253, 2, binds__V268);
                                              { START(sink__V253, _M__sTextCons);
                                                { START(sink__V253, _M__sTextChars);
                                                  LITERAL(sink__V253,  "#include \"" );
                                                  END(sink__V253, _M__sTextChars); }
                                                { START(sink__V253, _M__sTextCons);
                                                  { START(sink__V253, _M__sTextEmbed);
                                                    { START(sink__V253, _M_AsText);
                                                      { START(sink__V253, _M_DTOKEN);
                                                        USE(sink__V253, x__V266);
                                                        USE(sink__V253, x__V267);
                                                        END(sink__V253, _M_DTOKEN); }
                                                      END(sink__V253, _M_AsText); }
                                                    END(sink__V253, _M__sTextEmbed); }
                                                  { START(sink__V253, _M__sTextCons);
                                                    { START(sink__V253, _M__sTextChars);
                                                      LITERAL(sink__V253,  "\"" );
                                                      END(sink__V253, _M__sTextChars); }
                                                    { START(sink__V253, _M__sTextCons);
                                                      { START(sink__V253, _M__sTextBreak);
                                                        LITERAL(sink__V253,  "\n" );
                                                        END(sink__V253, _M__sTextBreak); }
                                                      { START(sink__V253, _M__sTextNil);
                                                        END(sink__V253, _M__sTextNil); }
                                                      END(sink__V253, _M__sTextCons); }
                                                    END(sink__V253, _M__sTextCons); }
                                                  END(sink__V253, _M__sTextCons); }
                                                END(sink__V253, _M__sTextCons); }
                                               }
                                            END(sink__V253, _M_DelayMapText_s1); }
                                          END(sink__V253, _M_AsText); }
                                        END(sink__V253, _M__sTextEmbed); }
                                      { START(sink__V253, _M__sTextCons);
                                        { START(sink__V253, _M__sTextBreak);
                                          LITERAL(sink__V253,  "\n" ); END(sink__V253, _M__sTextBreak); }
                                        { START(sink__V253, _M__sTextCons);
                                          { START(sink__V253, _M__sTextChars);
                                            LITERAL(sink__V253,  "#ifdef __cplusplus" );
                                            END(sink__V253, _M__sTextChars); }
                                          { START(sink__V253, _M__sTextCons);
                                            { START(sink__V253, _M__sTextBreak);
                                              LITERAL(sink__V253,  "\n" );
                                              END(sink__V253, _M__sTextBreak); }
                                            { START(sink__V253, _M__sTextCons);
                                              { START(sink__V253, _M__sTextChars);
                                                LITERAL(sink__V253,  "extern \"C\" {" );
                                                END(sink__V253, _M__sTextChars); }
                                              { START(sink__V253, _M__sTextCons);
                                                { START(sink__V253, _M__sTextBreak);
                                                  LITERAL(sink__V253,  "\n" );
                                                  END(sink__V253, _M__sTextBreak); }
                                                { START(sink__V253, _M__sTextCons);
                                                  { START(sink__V253, _M__sTextChars);
                                                    LITERAL(sink__V253,  "#endif" );
                                                    END(sink__V253, _M__sTextChars); }
                                                  { START(sink__V253, _M__sTextCons);
                                                    { START(sink__V253, _M__sTextBreak);
                                                      LITERAL(sink__V253,  "\n" );
                                                      END(sink__V253, _M__sTextBreak); }
                                                    { START(sink__V253, _M__sTextCons);
                                                      { START(sink__V253, _M__sTextEmbed);
                                                        { START(sink__V253, _M_AsText);
                                                          { START(sink__V253, _M_H_Declarations);
                                                            COPY(sink__V253, sub__V256);END(sink__V253, _M_H_Declarations); }
                                                          END(sink__V253, _M_AsText); }
                                                        END(sink__V253, _M__sTextEmbed); }
                                                      { START(sink__V253, _M__sTextCons);
                                                        { START(sink__V253, _M__sTextBreak);
                                                          LITERAL(sink__V253,  "\n" );
                                                          END(sink__V253, _M__sTextBreak); }
                                                        { START(sink__V253, _M__sTextCons);
                                                          { START(sink__V253, _M__sTextChars);
                                                            LITERAL(sink__V253,  "#ifdef __cplusplus" );
                                                            END(sink__V253, _M__sTextChars); }
                                                          { START(sink__V253, _M__sTextCons);
                                                            { START(sink__V253, _M__sTextBreak);
                                                              LITERAL(sink__V253,  "\n" );
                                                              END(sink__V253, _M__sTextBreak); }
                                                            { START(sink__V253, _M__sTextCons);
                                                              { START(sink__V253, _M__sTextChars);
                                                                LITERAL(sink__V253,  "}" );
                                                                END(sink__V253, _M__sTextChars); }
                                                              { START(sink__V253, _M__sTextCons);
                                                                { START(sink__V253, _M__sTextBreak);
                                                                  LITERAL(sink__V253,  "\n" );
                                                                  END(sink__V253, _M__sTextBreak); }
                                                                { START(sink__V253, _M__sTextCons);
                                                                  { START(sink__V253, _M__sTextChars);
                                                                    LITERAL(sink__V253,  "#endif" );
                                                                    END(sink__V253, _M__sTextChars); }
                                                                  { START(sink__V253, _M__sTextCons);
                                                                    { START(sink__V253, _M__sTextBreak);
                                                                      LITERAL(sink__V253,  "\n" );
                                                                      END(sink__V253, _M__sTextBreak); }
                                                                    { START(sink__V253, _M__sTextCons);
                                                                      { START(sink__V253, _M__sTextChars);
                                                                        LITERAL(sink__V253,  "/* END OF C HEADER FOR CRSX " );
                                                                        END(sink__V253, _M__sTextChars); }
                                                                      { START(sink__V253, _M__sTextCons);
                                                                        { START(sink__V253, _M__sTextEmbed);
                                                                          { START(sink__V253, _M_AsText);
                                                                            { START(sink__V253, _M_COMMENT_xTOKEN);
                                                                              COPY(sink__V253, sub__V255);END(sink__V253, _M_COMMENT_xTOKEN); }
                                                                            END(sink__V253, _M_AsText); }
                                                                          END(sink__V253, _M__sTextEmbed); }
                                                                        { START(sink__V253, _M__sTextCons);
                                                                          { START(sink__V253, _M__sTextChars);
                                                                            LITERAL(sink__V253,  " MODULE " );
                                                                            END(sink__V253, _M__sTextChars); }
                                                                          { START(sink__V253, _M__sTextCons);
                                                                            { START(sink__V253, _M__sTextEmbed);
                                                                              { START(sink__V253, _M_AsText);
                                                                                { START(sink__V253, _M_COMMENT_xTOKEN);
                                                                                  COPY(sink__V253, sub__V257);END(sink__V253, _M_COMMENT_xTOKEN); }
                                                                                END(sink__V253, _M_AsText); }
                                                                              END(sink__V253, _M__sTextEmbed); }
                                                                            { START(sink__V253, _M__sTextCons);
                                                                              { START(sink__V253, _M__sTextChars);
                                                                                LITERAL(sink__V253,  ". */" );
                                                                                END(sink__V253, _M__sTextChars); }
                                                                              { START(sink__V253, _M__sTextCons);
                                                                                { START(sink__V253, _M__sTextBreak);
                                                                                  LITERAL(sink__V253,  "\n" );
                                                                                  END(sink__V253, _M__sTextBreak); }
                                                                                { START(sink__V253, _M__sTextCons);
                                                                                  { START(sink__V253, _M__sTextChars);
                                                                                    LITERAL(sink__V253,  "#endif" );
                                                                                    END(sink__V253, _M__sTextChars); }
                                                                                  { START(sink__V253, _M__sTextCons);
                                                                                    { START(sink__V253, _M__sTextBreak);
                                                                                      LITERAL(sink__V253,  "\n" );
                                                                                      END(sink__V253, _M__sTextBreak); }
                                                                                    { START(sink__V253, _M__sTextNil);
                                                                                      END(sink__V253, _M__sTextNil); }
                                                                                    END(sink__V253, _M__sTextCons); }
                                                                                  END(sink__V253, _M__sTextCons); }
                                                                                END(sink__V253, _M__sTextCons); }
                                                                              END(sink__V253, _M__sTextCons); }
                                                                            END(sink__V253, _M__sTextCons); }
                                                                          END(sink__V253, _M__sTextCons); }
                                                                        END(sink__V253, _M__sTextCons); }
                                                                      END(sink__V253, _M__sTextCons); }
                                                                    END(sink__V253, _M__sTextCons); }
                                                                  END(sink__V253, _M__sTextCons); }
                                                                END(sink__V253, _M__sTextCons); }
                                                              END(sink__V253, _M__sTextCons); }
                                                            END(sink__V253, _M__sTextCons); }
                                                          END(sink__V253, _M__sTextCons); }
                                                        END(sink__V253, _M__sTextCons); }
                                                      END(sink__V253, _M__sTextCons); }
                                                    END(sink__V253, _M__sTextCons); }
                                                  END(sink__V253, _M__sTextCons); }
                                                END(sink__V253, _M__sTextCons); }
                                              END(sink__V253, _M__sTextCons); }
                                            END(sink__V253, _M__sTextCons); }
                                          END(sink__V253, _M__sTextCons); }
                                        END(sink__V253, _M__sTextCons); }
                                      END(sink__V253, _M__sTextCons); }
                                    END(sink__V253, _M__sTextCons); }
                                  END(sink__V253, _M__sTextCons); }
                                END(sink__V253, _M__sTextCons); }
                              END(sink__V253, _M__sTextCons); }
                            END(sink__V253, _M__sTextCons); }
                          END(sink__V253, _M__sTextCons); }
                        END(sink__V253, _M__sTextCons); }
                      END(sink__V253, _M__sTextCons); }
                    END(sink__V253, _M__sTextCons); }
                  END(sink__V253, _M__sTextCons); }
                END(sink__V253, _M__sTextCons); }
              END(sink__V253, _M__sTextCons); }
            END(sink__V253, _M__sTextCons); }
          END(sink__V253, _M__sTextCons); }
        END(sink__V253, _M__sTextCons); }
      END(sink__V253, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V253->context, namedFV__V260); UNLINK_VARIABLESET(sink__V253->context, varFV__V261);
    UNLINK_NamedPropertyLink(sink__V253->context, namedP__V258); UNLINK_VariablePropertyLink(sink__V253->context, varP__V259);
    return 1;
  } while (0);
  return 0;
}

#ifdef __cplusplus
}
#endif
/* END OF C RULES FOR CRSX CRSXC MODULE HEADER. */
