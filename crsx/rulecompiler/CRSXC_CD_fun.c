/* C RULES FOR CRSX CRSXC MODULE CD. */
#include "CRSXC.h" 
#ifdef __cplusplus
extern "C" {
#endif

/* FUNCTION D-check-sort$1. */
int conBindOffs_M_D__check__sort_s1[] = {0 , 0 , 0 , 0};
char *nameFun_M_D__check__sort_s1(Term term) { return  "D-check-sort$1" ; }
struct _ConstructionDescriptor descriptor_M_D__check__sort_s1 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_D__check__sort_s1), conBindOffs_M_D__check__sort_s1, &nameFun_M_D__check__sort_s1, &step_M_D__check__sort_s1};

int step_M_D__check__sort_s1(Sink sink__V1, Term term__V2)
{
  int term__V2_count = LINK_COUNT(term__V2); permitUnusedInt(term__V2_count);
  Term sub__V3 = FORCE(sink__V1->context, SUB(term__V2, 0));
  EnumOf_M_Reified_xSort choice__V4 = (IS_VARIABLE_USE(sub__V3) ? VarOf_M_Reified_xSort : (EnumOf_M_Reified_xSort) TAG(sub__V3));
  switch (choice__V4)
  {
    case Data_M_SORT_PROPERTY: { /* Function CDEFS-D-check-sort-1$D-check-sort$1$SORT-PROPERTY case SORT-PROPERTY */
      ASSERT(sink__V1->context, !strcmp(SYMBOL(term__V2),  "D-check-sort$1" ));
      Term sub__V5 = SUB(term__V2, 0); permitUnusedTerm(sub__V5); int sub__V5_count = term__V2_count*LINK_COUNT(sub__V5); permitUnusedInt(sub__V5_count);
      CRSX_CHECK_SORT(sink__V1->context, sub__V5, &sort_M_Reified_xSort); ASSERT(sink__V1->context, !strcmp(SYMBOL(sub__V5),  "SORT-PROPERTY" ));
      Term sub__V6 = LINK(sink__V1->context, SUB(sub__V5, 0)); int sub__V6_count = sub__V5_count*LINK_COUNT(sub__V6); permitUnusedInt(sub__V6_count);
      CRSX_CHECK_SORT(sink__V1->context, sub__V6, &sort_M_Reified_xSort); /* sub__V6 = &#0-0 */
      Term sub__V7 = LINK(sink__V1->context, SUB(sub__V5, 1)); int sub__V7_count = sub__V5_count*LINK_COUNT(sub__V7); permitUnusedInt(sub__V7_count);
      CRSX_CHECK_SORT(sink__V1->context, sub__V7, &sort_M_Reified_xSort); /* sub__V7 = &#0-1 */
      Term sub__V8 = LINK(sink__V1->context, SUB(sub__V5, 2)); int sub__V8_count = sub__V5_count*LINK_COUNT(sub__V8); permitUnusedInt(sub__V8_count);
      CRSX_CHECK_SORT(sink__V1->context, sub__V8, &sort_M_Reified_xSort); /* sub__V8 = &#0-2 */
      Term sub__V9 = LINK(sink__V1->context, SUB(term__V2, 1)); int sub__V9_count = term__V2_count*LINK_COUNT(sub__V9); permitUnusedInt(sub__V9_count);
      CRSX_CHECK_SORT(sink__V1->context, sub__V9, &sort_M_Reified_xVariable); /* sub__V9 = &#3 */
      Term sub__V10 = LINK(sink__V1->context, SUB(term__V2, 2)); int sub__V10_count = term__V2_count*LINK_COUNT(sub__V10); permitUnusedInt(sub__V10_count);
      CRSX_CHECK_SORT(sink__V1->context, sub__V10, &sort_M_Reified_xVariable); /* sub__V10 = &#4 */
      
      NamedPropertyLink namedP__V11 = LINK_NamedPropertyLink(sink__V1->context, NAMED_PROPERTIES(term__V2));
      VariablePropertyLink varP__V12 = LINK_VariablePropertyLink(sink__V1->context, VARIABLE_PROPERTIES(term__V2));
      Hashset namedFV__V13 = LINK_VARIABLESET(sink__V1->context, namedPropertyFreeVars(namedP__V11));
      Hashset varFV__V14 = LINK_VARIABLESET(sink__V1->context, variablePropertyFreeVars(varP__V12));
      UNLINK(sink__V1->context, term__V2);
      ADD_PROPERTIES(sink__V1, LINK_VARIABLESET(sink__V1->context, namedFV__V13), LINK_VARIABLESET(sink__V1->context, varFV__V14), LINK_NamedPropertyLink(sink__V1->context, namedP__V11), LINK_VariablePropertyLink(sink__V1->context, varP__V12));
      { START(sink__V1, _M_D__check__sort_s3);
        COPY(sink__V1, sub__V6);COPY(sink__V1, sub__V7);COPY(sink__V1, sub__V8);COPY(sink__V1, sub__V9);COPY(sink__V1, sub__V10);END(sink__V1, _M_D__check__sort_s3); }
      UNLINK_VARIABLESET(sink__V1->context, namedFV__V13); UNLINK_VARIABLESET(sink__V1->context, varFV__V14);
      UNLINK_NamedPropertyLink(sink__V1->context, namedP__V11); UNLINK_VariablePropertyLink(sink__V1->context, varP__V12);
      
      return 1;
    break; } case Data_M_SORT_VARIABLE: { /* Function CDEFS-D-check-sort-2$D-check-sort$1$SORT-VARIABLE case SORT-VARIABLE */
      ASSERT(sink__V1->context, !strcmp(SYMBOL(term__V2),  "D-check-sort$1" ));
      Term sub__V15 = SUB(term__V2, 0); permitUnusedTerm(sub__V15); int sub__V15_count = term__V2_count*LINK_COUNT(sub__V15); permitUnusedInt(sub__V15_count);
      CRSX_CHECK_SORT(sink__V1->context, sub__V15, &sort_M_Reified_xSort); ASSERT(sink__V1->context, !strcmp(SYMBOL(sub__V15),  "SORT-VARIABLE" ));
      Term sub__V16 = LINK(sink__V1->context, SUB(sub__V15, 0)); int sub__V16_count = sub__V15_count*LINK_COUNT(sub__V16); permitUnusedInt(sub__V16_count);
      CRSX_CHECK_SORT(sink__V1->context, sub__V16, &sort_M_Reified_xVariable); /* sub__V16 = &#0-0 */
      Term sub__V17 = LINK(sink__V1->context, SUB(term__V2, 1)); int sub__V17_count = term__V2_count*LINK_COUNT(sub__V17); permitUnusedInt(sub__V17_count);
      CRSX_CHECK_SORT(sink__V1->context, sub__V17, &sort_M_Reified_xVariable); /* sub__V17 = &#1 */
      Term sub__V18 = LINK(sink__V1->context, SUB(term__V2, 2)); int sub__V18_count = term__V2_count*LINK_COUNT(sub__V18); permitUnusedInt(sub__V18_count);
      CRSX_CHECK_SORT(sink__V1->context, sub__V18, &sort_M_Reified_xVariable); /* sub__V18 = &#2 */
      
      NamedPropertyLink namedP__V19 = LINK_NamedPropertyLink(sink__V1->context, NAMED_PROPERTIES(term__V2));
      VariablePropertyLink varP__V20 = LINK_VariablePropertyLink(sink__V1->context, VARIABLE_PROPERTIES(term__V2));
      Hashset namedFV__V21 = LINK_VARIABLESET(sink__V1->context, namedPropertyFreeVars(namedP__V19));
      Hashset varFV__V22 = LINK_VARIABLESET(sink__V1->context, variablePropertyFreeVars(varP__V20));
      UNLINK(sink__V1->context, term__V2);
      ADD_PROPERTIES(sink__V1, LINK_VARIABLESET(sink__V1->context, namedFV__V21), LINK_VARIABLESET(sink__V1->context, varFV__V22), LINK_NamedPropertyLink(sink__V1->context, namedP__V19), LINK_VariablePropertyLink(sink__V1->context, varP__V20));
      { START(sink__V1, _M_D__check__sort_s4);
        COPY(sink__V1, sub__V16);COPY(sink__V1, sub__V17);COPY(sink__V1, sub__V18);END(sink__V1, _M_D__check__sort_s4); }
      UNLINK_VARIABLESET(sink__V1->context, namedFV__V21); UNLINK_VARIABLESET(sink__V1->context, varFV__V22);
      UNLINK_NamedPropertyLink(sink__V1->context, namedP__V19); UNLINK_VariablePropertyLink(sink__V1->context, varP__V20);
      
      return 1;
    break; } case Data_M_SORT: { /* Function CDEFS-D-check-sort-3$D-check-sort$1$SORT case SORT */
      ASSERT(sink__V1->context, !strcmp(SYMBOL(term__V2),  "D-check-sort$1" ));
      Term sub__V23 = SUB(term__V2, 0); permitUnusedTerm(sub__V23); int sub__V23_count = term__V2_count*LINK_COUNT(sub__V23); permitUnusedInt(sub__V23_count);
      CRSX_CHECK_SORT(sink__V1->context, sub__V23, &sort_M_Reified_xSort); ASSERT(sink__V1->context, !strcmp(SYMBOL(sub__V23),  "SORT" ));
      Term sub__V24 = LINK(sink__V1->context, SUB(sub__V23, 0)); int sub__V24_count = sub__V23_count*LINK_COUNT(sub__V24); permitUnusedInt(sub__V24_count);
      /* sub__V24 = &#0-0 */
      Term sub__V25 = LINK(sink__V1->context, SUB(sub__V23, 1)); int sub__V25_count = sub__V23_count*LINK_COUNT(sub__V25); permitUnusedInt(sub__V25_count);
      /* sub__V25 = &#0-1 */
      Term sub__V26 = LINK(sink__V1->context, SUB(term__V2, 1)); int sub__V26_count = term__V2_count*LINK_COUNT(sub__V26); permitUnusedInt(sub__V26_count);
      CRSX_CHECK_SORT(sink__V1->context, sub__V26, &sort_M_Reified_xVariable); /* sub__V26 = &#2 */
      Term sub__V27 = LINK(sink__V1->context, SUB(term__V2, 2)); int sub__V27_count = term__V2_count*LINK_COUNT(sub__V27); permitUnusedInt(sub__V27_count);
      CRSX_CHECK_SORT(sink__V1->context, sub__V27, &sort_M_Reified_xVariable); /* sub__V27 = &#3 */
      
      NamedPropertyLink namedP__V28 = LINK_NamedPropertyLink(sink__V1->context, NAMED_PROPERTIES(term__V2));
      VariablePropertyLink varP__V29 = LINK_VariablePropertyLink(sink__V1->context, VARIABLE_PROPERTIES(term__V2));
      Hashset namedFV__V30 = LINK_VARIABLESET(sink__V1->context, namedPropertyFreeVars(namedP__V28));
      Hashset varFV__V31 = LINK_VARIABLESET(sink__V1->context, variablePropertyFreeVars(varP__V29));
      UNLINK(sink__V1->context, term__V2);
      ADD_PROPERTIES(sink__V1, LINK_VARIABLESET(sink__V1->context, namedFV__V30), LINK_VARIABLESET(sink__V1->context, varFV__V31), LINK_NamedPropertyLink(sink__V1->context, namedP__V28), LINK_VariablePropertyLink(sink__V1->context, varP__V29));
      { START(sink__V1, _M_D__check__sort_s2);
        COPY(sink__V1, sub__V24);COPY(sink__V1, sub__V25);COPY(sink__V1, sub__V26);COPY(sink__V1, sub__V27);END(sink__V1, _M_D__check__sort_s2); }
      UNLINK_VARIABLESET(sink__V1->context, namedFV__V30); UNLINK_VARIABLESET(sink__V1->context, varFV__V31);
      UNLINK_NamedPropertyLink(sink__V1->context, namedP__V28); UNLINK_VariablePropertyLink(sink__V1->context, varP__V29);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION D-check-sort$2. */
int conBindOffs_M_D__check__sort_s2[] = {0 , 0 , 0 , 0 , 0};
char *nameFun_M_D__check__sort_s2(Term term) { return  "D-check-sort$2" ; }
struct _ConstructionDescriptor descriptor_M_D__check__sort_s2 = {&sort_M_Reified_xVariable, 0, 4, sizeof(STRUCT_Con_M_D__check__sort_s2), conBindOffs_M_D__check__sort_s2, &nameFun_M_D__check__sort_s2, &step_M_D__check__sort_s2};

int step_M_D__check__sort_s2(Sink sink__V32, Term term__V33)
{
  int term__V33_count = LINK_COUNT(term__V33); permitUnusedInt(term__V33_count);
  do {
    /* Contraction rule CDEFS-D-check-sort-3. */
    ASSERT(sink__V32->context, !strcmp(SYMBOL(term__V33),  "D-check-sort$2" ));
    Term sub__V34 = LINK(sink__V32->context, SUB(term__V33, 0)); int sub__V34_count = term__V33_count*LINK_COUNT(sub__V34); permitUnusedInt(sub__V34_count);
    /* sub__V34 = &#31 */
    Term sub__V35 = SUB(term__V33, 1); permitUnusedTerm(sub__V35); int sub__V35_count = term__V33_count*LINK_COUNT(sub__V35); permitUnusedInt(sub__V35_count);
    /* sub__V35 = &#32 */
    Term sub__V36 = LINK(sink__V32->context, SUB(term__V33, 2)); int sub__V36_count = term__V33_count*LINK_COUNT(sub__V36); permitUnusedInt(sub__V36_count);
    CRSX_CHECK_SORT(sink__V32->context, sub__V36, &sort_M_Reified_xVariable); /* sub__V36 = &#2 */
    Term sub__V37 = LINK(sink__V32->context, SUB(term__V33, 3)); int sub__V37_count = term__V33_count*LINK_COUNT(sub__V37); permitUnusedInt(sub__V37_count);
    CRSX_CHECK_SORT(sink__V32->context, sub__V37, &sort_M_Reified_xVariable); /* sub__V37 = &#1 */
    
    NamedPropertyLink namedP__V38 = LINK_NamedPropertyLink(sink__V32->context, NAMED_PROPERTIES(term__V33));
    VariablePropertyLink varP__V39 = LINK_VariablePropertyLink(sink__V32->context, VARIABLE_PROPERTIES(term__V33));
    Hashset namedFV__V40 = LINK_VARIABLESET(sink__V32->context, namedPropertyFreeVars(namedP__V38));
    Hashset varFV__V41 = LINK_VARIABLESET(sink__V32->context, variablePropertyFreeVars(varP__V39));
    UNLINK(sink__V32->context, term__V33);
    { int test__V42;
      FORCE(sink__V32->context, sub__V34); LINK(sink__V32->context, sub__V34);
      test__V42 = (int) (strstr(SYMBOL(sub__V34), "$" ) != NULL);
      UNLINK(sink__V32->context, sub__V34);  if (test__V42) {  UNLINK(sink__V32->context, sub__V36);  UNLINK(sink__V32->context, sub__V37);  UNLINK(sink__V32->context, sub__V34); { START(sink__V32, _M__sTextNil);
          END(sink__V32, _M__sTextNil); }
         }
      else { { START(sink__V32, _M__sTextCons);
          { START(sink__V32, _M__sTextChars);
            LITERAL(sink__V32,  "CRSX_CHECK_SORT(" ); END(sink__V32, _M__sTextChars); }
          { START(sink__V32, _M__sTextCons);
            { START(sink__V32, _M__sTextEmbed);
              { START(sink__V32, _M_AsText);
                COPY(sink__V32, sub__V37);END(sink__V32, _M_AsText); }
              END(sink__V32, _M__sTextEmbed); }
            { START(sink__V32, _M__sTextCons);
              { START(sink__V32, _M__sTextChars);
                LITERAL(sink__V32,  "->context, " ); END(sink__V32, _M__sTextChars); }
              { START(sink__V32, _M__sTextCons);
                { START(sink__V32, _M__sTextEmbed);
                  { START(sink__V32, _M_AsText);
                    COPY(sink__V32, sub__V36);END(sink__V32, _M_AsText); }
                  END(sink__V32, _M__sTextEmbed); }
                { START(sink__V32, _M__sTextCons);
                  { START(sink__V32, _M__sTextChars);
                    LITERAL(sink__V32,  ", &" ); END(sink__V32, _M__sTextChars); }
                  { START(sink__V32, _M__sTextCons);
                    { START(sink__V32, _M__sTextEmbed);
                      { START(sink__V32, _M_AsText);
                        { START(sink__V32, _M_Sort);
                          COPY(sink__V32, sub__V34);END(sink__V32, _M_Sort); }
                        END(sink__V32, _M_AsText); }
                      END(sink__V32, _M__sTextEmbed); }
                    { START(sink__V32, _M__sTextCons);
                      { START(sink__V32, _M__sTextChars);
                        LITERAL(sink__V32,  "); " ); END(sink__V32, _M__sTextChars); }
                      { START(sink__V32, _M__sTextNil);
                        END(sink__V32, _M__sTextNil); }
                      END(sink__V32, _M__sTextCons); }
                    END(sink__V32, _M__sTextCons); }
                  END(sink__V32, _M__sTextCons); }
                END(sink__V32, _M__sTextCons); }
              END(sink__V32, _M__sTextCons); }
            END(sink__V32, _M__sTextCons); }
          END(sink__V32, _M__sTextCons); }
         }
    }
    UNLINK_VARIABLESET(sink__V32->context, namedFV__V40); UNLINK_VARIABLESET(sink__V32->context, varFV__V41);
    UNLINK_NamedPropertyLink(sink__V32->context, namedP__V38); UNLINK_VariablePropertyLink(sink__V32->context, varP__V39);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION D-check-sort$3. */
int conBindOffs_M_D__check__sort_s3[] = {0 , 0 , 0 , 0 , 0 , 0};
char *nameFun_M_D__check__sort_s3(Term term) { return  "D-check-sort$3" ; }
struct _ConstructionDescriptor descriptor_M_D__check__sort_s3 = {&sort_M_Reified_xVariable, 0, 5, sizeof(STRUCT_Con_M_D__check__sort_s3), conBindOffs_M_D__check__sort_s3, &nameFun_M_D__check__sort_s3, &step_M_D__check__sort_s3};

int step_M_D__check__sort_s3(Sink sink__V43, Term term__V44)
{
  int term__V44_count = LINK_COUNT(term__V44); permitUnusedInt(term__V44_count);
  do {
    /* Contraction rule CDEFS-D-check-sort-1. */
    ASSERT(sink__V43->context, !strcmp(SYMBOL(term__V44),  "D-check-sort$3" ));
    Term sub__V45 = SUB(term__V44, 0); permitUnusedTerm(sub__V45); int sub__V45_count = term__V44_count*LINK_COUNT(sub__V45); permitUnusedInt(sub__V45_count);
    CRSX_CHECK_SORT(sink__V43->context, sub__V45, &sort_M_Reified_xSort); /* sub__V45 = &#31 */
    Term sub__V46 = SUB(term__V44, 1); permitUnusedTerm(sub__V46); int sub__V46_count = term__V44_count*LINK_COUNT(sub__V46); permitUnusedInt(sub__V46_count);
    CRSX_CHECK_SORT(sink__V43->context, sub__V46, &sort_M_Reified_xSort); /* sub__V46 = &#32 */
    Term sub__V47 = LINK(sink__V43->context, SUB(term__V44, 2)); int sub__V47_count = term__V44_count*LINK_COUNT(sub__V47); permitUnusedInt(sub__V47_count);
    CRSX_CHECK_SORT(sink__V43->context, sub__V47, &sort_M_Reified_xSort); /* sub__V47 = &#33 */
    Term sub__V48 = LINK(sink__V43->context, SUB(term__V44, 3)); int sub__V48_count = term__V44_count*LINK_COUNT(sub__V48); permitUnusedInt(sub__V48_count);
    CRSX_CHECK_SORT(sink__V43->context, sub__V48, &sort_M_Reified_xVariable); /* sub__V48 = &#2 */
    Term sub__V49 = LINK(sink__V43->context, SUB(term__V44, 4)); int sub__V49_count = term__V44_count*LINK_COUNT(sub__V49); permitUnusedInt(sub__V49_count);
    CRSX_CHECK_SORT(sink__V43->context, sub__V49, &sort_M_Reified_xVariable); /* sub__V49 = &#1 */
    
    NamedPropertyLink namedP__V50 = LINK_NamedPropertyLink(sink__V43->context, NAMED_PROPERTIES(term__V44));
    VariablePropertyLink varP__V51 = LINK_VariablePropertyLink(sink__V43->context, VARIABLE_PROPERTIES(term__V44));
    Hashset namedFV__V52 = LINK_VARIABLESET(sink__V43->context, namedPropertyFreeVars(namedP__V50));
    Hashset varFV__V53 = LINK_VARIABLESET(sink__V43->context, variablePropertyFreeVars(varP__V51));
    UNLINK(sink__V43->context, term__V44);
    { START(sink__V43, _M_D__check__sort_s1);
      COPY(sink__V43, sub__V47);COPY(sink__V43, sub__V48);COPY(sink__V43, sub__V49);END(sink__V43, _M_D__check__sort_s1); }
    UNLINK_VARIABLESET(sink__V43->context, namedFV__V52); UNLINK_VARIABLESET(sink__V43->context, varFV__V53);
    UNLINK_NamedPropertyLink(sink__V43->context, namedP__V50); UNLINK_VariablePropertyLink(sink__V43->context, varP__V51);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION D-check-sort$4. */
int conBindOffs_M_D__check__sort_s4[] = {0 , 0 , 0 , 0};
char *nameFun_M_D__check__sort_s4(Term term) { return  "D-check-sort$4" ; }
struct _ConstructionDescriptor descriptor_M_D__check__sort_s4 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_D__check__sort_s4), conBindOffs_M_D__check__sort_s4, &nameFun_M_D__check__sort_s4, &step_M_D__check__sort_s4};

int step_M_D__check__sort_s4(Sink sink__V54, Term term__V55)
{
  int term__V55_count = LINK_COUNT(term__V55); permitUnusedInt(term__V55_count);
  do {
    /* Contraction rule CDEFS-D-check-sort-2. */
    ASSERT(sink__V54->context, !strcmp(SYMBOL(term__V55),  "D-check-sort$4" ));
    Term sub__V56 = SUB(term__V55, 0); permitUnusedTerm(sub__V56); int sub__V56_count = term__V55_count*LINK_COUNT(sub__V56); permitUnusedInt(sub__V56_count);
    CRSX_CHECK_SORT(sink__V54->context, sub__V56, &sort_M_Reified_xVariable); /* sub__V56 = &#31 */
    Term sub__V57 = SUB(term__V55, 1); permitUnusedTerm(sub__V57); int sub__V57_count = term__V55_count*LINK_COUNT(sub__V57); permitUnusedInt(sub__V57_count);
    CRSX_CHECK_SORT(sink__V54->context, sub__V57, &sort_M_Reified_xVariable); /* sub__V57 = &#2 */
    Term sub__V58 = SUB(term__V55, 2); permitUnusedTerm(sub__V58); int sub__V58_count = term__V55_count*LINK_COUNT(sub__V58); permitUnusedInt(sub__V58_count);
    CRSX_CHECK_SORT(sink__V54->context, sub__V58, &sort_M_Reified_xVariable); /* sub__V58 = &#1 */
    
    NamedPropertyLink namedP__V59 = LINK_NamedPropertyLink(sink__V54->context, NAMED_PROPERTIES(term__V55));
    VariablePropertyLink varP__V60 = LINK_VariablePropertyLink(sink__V54->context, VARIABLE_PROPERTIES(term__V55));
    Hashset namedFV__V61 = LINK_VARIABLESET(sink__V54->context, namedPropertyFreeVars(namedP__V59));
    Hashset varFV__V62 = LINK_VARIABLESET(sink__V54->context, variablePropertyFreeVars(varP__V60));
    UNLINK(sink__V54->context, term__V55);
    { START(sink__V54, _M__sTextNil); END(sink__V54, _M__sTextNil); } UNLINK_VARIABLESET(sink__V54->context, namedFV__V61); UNLINK_VARIABLESET(sink__V54->context, varFV__V62);
    UNLINK_NamedPropertyLink(sink__V54->context, namedP__V59); UNLINK_VariablePropertyLink(sink__V54->context, varP__V60);
    return 1;
  } while (0);
  return 0;
}

#ifdef __cplusplus
}
#endif
/* END OF C RULES FOR CRSX CRSXC MODULE CD. */
