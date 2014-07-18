/* C RULES FOR CRSX CRSXC MODULE CD. */
#include "CRSXC.h" 
#ifdef __cplusplus
extern "C" {
#endif

/* FUNCTION D-check-sort$4. */
int conBindOffs_M_D__check__sort_s4[] = {0 , 0 , 0 , 0};
char *nameFun_M_D__check__sort_s4(Term term) { return  "D-check-sort$4" ; }
struct _ConstructionDescriptor descriptor_M_D__check__sort_s4 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_D__check__sort_s4), conBindOffs_M_D__check__sort_s4, &nameFun_M_D__check__sort_s4, &step_M_D__check__sort_s4};

int step_M_D__check__sort_s4(Sink sink__V1, Term term__V2)
{
  int term__V2_count = LINK_COUNT(term__V2); permitUnusedInt(term__V2_count);
  do {
    /* Contraction rule CDEFS-D-check-sort-2. */
    ASSERT(sink__V1->context, !strcmp(SYMBOL(term__V2),  "D-check-sort$4" ));
    Term sub__V3 = SUB(term__V2, 0); permitUnusedTerm(sub__V3); int sub__V3_count = term__V2_count*LINK_COUNT(sub__V3); permitUnusedInt(sub__V3_count);
    CRSX_CHECK_SORT(sink__V1->context, sub__V3, &sort_M_Reified_xVariable); /* sub__V3 = &#31 */
    Term sub__V4 = SUB(term__V2, 1); permitUnusedTerm(sub__V4); int sub__V4_count = term__V2_count*LINK_COUNT(sub__V4); permitUnusedInt(sub__V4_count);
    CRSX_CHECK_SORT(sink__V1->context, sub__V4, &sort_M_Reified_xVariable); /* sub__V4 = &#2 */
    Term sub__V5 = SUB(term__V2, 2); permitUnusedTerm(sub__V5); int sub__V5_count = term__V2_count*LINK_COUNT(sub__V5); permitUnusedInt(sub__V5_count);
    CRSX_CHECK_SORT(sink__V1->context, sub__V5, &sort_M_Reified_xVariable); /* sub__V5 = &#1 */
    
    NamedPropertyLink namedP__V6 = LINK_NamedPropertyLink(sink__V1->context, NAMED_PROPERTIES(term__V2));
    VariablePropertyLink varP__V7 = LINK_VariablePropertyLink(sink__V1->context, VARIABLE_PROPERTIES(term__V2));
    Hashset namedFV__V8 = LINK_VARIABLESET(sink__V1->context, asConstruction(term__V2)->properties->namedFreeVars);
    Hashset varFV__V9 = LINK_VARIABLESET(sink__V1->context, asConstruction(term__V2)->properties->variableFreeVars);
    UNLINK(sink__V1->context, term__V2);
    { START(sink__V1, _M__sTextNil); END(sink__V1, _M__sTextNil); } UNLINK_VARIABLESET(sink__V1->context, namedFV__V8); UNLINK_VARIABLESET(sink__V1->context, varFV__V9);
    UNLINK_NamedPropertyLink(sink__V1->context, namedP__V6); UNLINK_VariablePropertyLink(sink__V1->context, varP__V7);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION D-check-sort$2. */
int conBindOffs_M_D__check__sort_s2[] = {0 , 0 , 0 , 0 , 0};
char *nameFun_M_D__check__sort_s2(Term term) { return  "D-check-sort$2" ; }
struct _ConstructionDescriptor descriptor_M_D__check__sort_s2 = {&sort_M_Reified_xVariable, 0, 4, sizeof(STRUCT_Con_M_D__check__sort_s2), conBindOffs_M_D__check__sort_s2, &nameFun_M_D__check__sort_s2, &step_M_D__check__sort_s2};

int step_M_D__check__sort_s2(Sink sink__V10, Term term__V11)
{
  int term__V11_count = LINK_COUNT(term__V11); permitUnusedInt(term__V11_count);
  do {
    /* Contraction rule CDEFS-D-check-sort-3. */
    ASSERT(sink__V10->context, !strcmp(SYMBOL(term__V11),  "D-check-sort$2" ));
    Term sub__V12 = LINK(sink__V10->context, SUB(term__V11, 0)); int sub__V12_count = term__V11_count*LINK_COUNT(sub__V12); permitUnusedInt(sub__V12_count);
    /* sub__V12 = &#31 */
    Term sub__V13 = SUB(term__V11, 1); permitUnusedTerm(sub__V13); int sub__V13_count = term__V11_count*LINK_COUNT(sub__V13); permitUnusedInt(sub__V13_count);
    /* sub__V13 = &#32 */
    Term sub__V14 = LINK(sink__V10->context, SUB(term__V11, 2)); int sub__V14_count = term__V11_count*LINK_COUNT(sub__V14); permitUnusedInt(sub__V14_count);
    CRSX_CHECK_SORT(sink__V10->context, sub__V14, &sort_M_Reified_xVariable); /* sub__V14 = &#2 */
    Term sub__V15 = LINK(sink__V10->context, SUB(term__V11, 3)); int sub__V15_count = term__V11_count*LINK_COUNT(sub__V15); permitUnusedInt(sub__V15_count);
    CRSX_CHECK_SORT(sink__V10->context, sub__V15, &sort_M_Reified_xVariable); /* sub__V15 = &#1 */
    
    NamedPropertyLink namedP__V16 = LINK_NamedPropertyLink(sink__V10->context, NAMED_PROPERTIES(term__V11));
    VariablePropertyLink varP__V17 = LINK_VariablePropertyLink(sink__V10->context, VARIABLE_PROPERTIES(term__V11));
    Hashset namedFV__V18 = LINK_VARIABLESET(sink__V10->context, asConstruction(term__V11)->properties->namedFreeVars);
    Hashset varFV__V19 = LINK_VARIABLESET(sink__V10->context, asConstruction(term__V11)->properties->variableFreeVars);
    UNLINK(sink__V10->context, term__V11);
    { int test__V20;
      FORCE(sink__V10->context, sub__V12); LINK(sink__V10->context, sub__V12);
      test__V20 = (int) (strstr(SYMBOL(sub__V12), "$" ) != NULL);
      UNLINK(sink__V10->context, sub__V12);  if (test__V20) {  UNLINK(sink__V10->context, sub__V12);  UNLINK(sink__V10->context, sub__V14);  UNLINK(sink__V10->context, sub__V15); { START(sink__V10, _M__sTextNil);
          END(sink__V10, _M__sTextNil); }
         }
      else { { START(sink__V10, _M__sTextCons);
          { START(sink__V10, _M__sTextChars);
            LITERAL(sink__V10,  "CRSX_CHECK_SORT(" ); END(sink__V10, _M__sTextChars); }
          { START(sink__V10, _M__sTextCons);
            { START(sink__V10, _M__sTextEmbed);
              { START(sink__V10, _M_AsText);
                COPY(sink__V10, sub__V15);END(sink__V10, _M_AsText); }
              END(sink__V10, _M__sTextEmbed); }
            { START(sink__V10, _M__sTextCons);
              { START(sink__V10, _M__sTextChars);
                LITERAL(sink__V10,  "->context, " ); END(sink__V10, _M__sTextChars); }
              { START(sink__V10, _M__sTextCons);
                { START(sink__V10, _M__sTextEmbed);
                  { START(sink__V10, _M_AsText);
                    COPY(sink__V10, sub__V14);END(sink__V10, _M_AsText); }
                  END(sink__V10, _M__sTextEmbed); }
                { START(sink__V10, _M__sTextCons);
                  { START(sink__V10, _M__sTextChars);
                    LITERAL(sink__V10,  ", &" ); END(sink__V10, _M__sTextChars); }
                  { START(sink__V10, _M__sTextCons);
                    { START(sink__V10, _M__sTextEmbed);
                      { START(sink__V10, _M_AsText);
                        { START(sink__V10, _M_Sort);
                          COPY(sink__V10, sub__V12);END(sink__V10, _M_Sort); }
                        END(sink__V10, _M_AsText); }
                      END(sink__V10, _M__sTextEmbed); }
                    { START(sink__V10, _M__sTextCons);
                      { START(sink__V10, _M__sTextChars);
                        LITERAL(sink__V10,  "); " ); END(sink__V10, _M__sTextChars); }
                      { START(sink__V10, _M__sTextNil);
                        END(sink__V10, _M__sTextNil); }
                      END(sink__V10, _M__sTextCons); }
                    END(sink__V10, _M__sTextCons); }
                  END(sink__V10, _M__sTextCons); }
                END(sink__V10, _M__sTextCons); }
              END(sink__V10, _M__sTextCons); }
            END(sink__V10, _M__sTextCons); }
          END(sink__V10, _M__sTextCons); }
         }
    }
    UNLINK_VARIABLESET(sink__V10->context, namedFV__V18); UNLINK_VARIABLESET(sink__V10->context, varFV__V19);
    UNLINK_NamedPropertyLink(sink__V10->context, namedP__V16); UNLINK_VariablePropertyLink(sink__V10->context, varP__V17);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION D-check-sort$3. */
int conBindOffs_M_D__check__sort_s3[] = {0 , 0 , 0 , 0 , 0 , 0};
char *nameFun_M_D__check__sort_s3(Term term) { return  "D-check-sort$3" ; }
struct _ConstructionDescriptor descriptor_M_D__check__sort_s3 = {&sort_M_Reified_xVariable, 0, 5, sizeof(STRUCT_Con_M_D__check__sort_s3), conBindOffs_M_D__check__sort_s3, &nameFun_M_D__check__sort_s3, &step_M_D__check__sort_s3};

int step_M_D__check__sort_s3(Sink sink__V21, Term term__V22)
{
  int term__V22_count = LINK_COUNT(term__V22); permitUnusedInt(term__V22_count);
  do {
    /* Contraction rule CDEFS-D-check-sort-1. */
    ASSERT(sink__V21->context, !strcmp(SYMBOL(term__V22),  "D-check-sort$3" ));
    Term sub__V23 = SUB(term__V22, 0); permitUnusedTerm(sub__V23); int sub__V23_count = term__V22_count*LINK_COUNT(sub__V23); permitUnusedInt(sub__V23_count);
    CRSX_CHECK_SORT(sink__V21->context, sub__V23, &sort_M_Reified_xSort); /* sub__V23 = &#31 */
    Term sub__V24 = SUB(term__V22, 1); permitUnusedTerm(sub__V24); int sub__V24_count = term__V22_count*LINK_COUNT(sub__V24); permitUnusedInt(sub__V24_count);
    CRSX_CHECK_SORT(sink__V21->context, sub__V24, &sort_M_Reified_xSort); /* sub__V24 = &#32 */
    Term sub__V25 = LINK(sink__V21->context, SUB(term__V22, 2)); int sub__V25_count = term__V22_count*LINK_COUNT(sub__V25); permitUnusedInt(sub__V25_count);
    CRSX_CHECK_SORT(sink__V21->context, sub__V25, &sort_M_Reified_xSort); /* sub__V25 = &#33 */
    Term sub__V26 = LINK(sink__V21->context, SUB(term__V22, 3)); int sub__V26_count = term__V22_count*LINK_COUNT(sub__V26); permitUnusedInt(sub__V26_count);
    CRSX_CHECK_SORT(sink__V21->context, sub__V26, &sort_M_Reified_xVariable); /* sub__V26 = &#2 */
    Term sub__V27 = LINK(sink__V21->context, SUB(term__V22, 4)); int sub__V27_count = term__V22_count*LINK_COUNT(sub__V27); permitUnusedInt(sub__V27_count);
    CRSX_CHECK_SORT(sink__V21->context, sub__V27, &sort_M_Reified_xVariable); /* sub__V27 = &#1 */
    
    NamedPropertyLink namedP__V28 = LINK_NamedPropertyLink(sink__V21->context, NAMED_PROPERTIES(term__V22));
    VariablePropertyLink varP__V29 = LINK_VariablePropertyLink(sink__V21->context, VARIABLE_PROPERTIES(term__V22));
    Hashset namedFV__V30 = LINK_VARIABLESET(sink__V21->context, asConstruction(term__V22)->properties->namedFreeVars);
    Hashset varFV__V31 = LINK_VARIABLESET(sink__V21->context, asConstruction(term__V22)->properties->variableFreeVars);
    UNLINK(sink__V21->context, term__V22);
    { START(sink__V21, _M_D__check__sort_s1);
      COPY(sink__V21, sub__V25);COPY(sink__V21, sub__V26);COPY(sink__V21, sub__V27);END(sink__V21, _M_D__check__sort_s1); }
    UNLINK_VARIABLESET(sink__V21->context, namedFV__V30); UNLINK_VARIABLESET(sink__V21->context, varFV__V31);
    UNLINK_NamedPropertyLink(sink__V21->context, namedP__V28); UNLINK_VariablePropertyLink(sink__V21->context, varP__V29);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION D-check-sort$1. */
int conBindOffs_M_D__check__sort_s1[] = {0 , 0 , 0 , 0};
char *nameFun_M_D__check__sort_s1(Term term) { return  "D-check-sort$1" ; }
struct _ConstructionDescriptor descriptor_M_D__check__sort_s1 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_D__check__sort_s1), conBindOffs_M_D__check__sort_s1, &nameFun_M_D__check__sort_s1, &step_M_D__check__sort_s1};

int step_M_D__check__sort_s1(Sink sink__V32, Term term__V33)
{
  int term__V33_count = LINK_COUNT(term__V33); permitUnusedInt(term__V33_count);
  Term sub__V34 = FORCE(sink__V32->context, SUB(term__V33, 0));
  EnumOf_M_Reified_xSort choice__V35 = (IS_VARIABLE_USE(sub__V34) ? VarOf_M_Reified_xSort : (EnumOf_M_Reified_xSort) TAG(sub__V34));
  switch (choice__V35)
  {
    case Data_M_SORT_PROPERTY: { /* Function CDEFS-D-check-sort-1$D-check-sort$1$SORT-PROPERTY case SORT-PROPERTY */
      ASSERT(sink__V32->context, !strcmp(SYMBOL(term__V33),  "D-check-sort$1" ));
      Term sub__V36 = SUB(term__V33, 0); permitUnusedTerm(sub__V36); int sub__V36_count = term__V33_count*LINK_COUNT(sub__V36); permitUnusedInt(sub__V36_count);
      CRSX_CHECK_SORT(sink__V32->context, sub__V36, &sort_M_Reified_xSort); ASSERT(sink__V32->context, !strcmp(SYMBOL(sub__V36),  "SORT-PROPERTY" ));
      Term sub__V37 = LINK(sink__V32->context, SUB(sub__V36, 0)); int sub__V37_count = sub__V36_count*LINK_COUNT(sub__V37); permitUnusedInt(sub__V37_count);
      CRSX_CHECK_SORT(sink__V32->context, sub__V37, &sort_M_Reified_xSort); /* sub__V37 = &#0-0 */
      Term sub__V38 = LINK(sink__V32->context, SUB(sub__V36, 1)); int sub__V38_count = sub__V36_count*LINK_COUNT(sub__V38); permitUnusedInt(sub__V38_count);
      CRSX_CHECK_SORT(sink__V32->context, sub__V38, &sort_M_Reified_xSort); /* sub__V38 = &#0-1 */
      Term sub__V39 = LINK(sink__V32->context, SUB(sub__V36, 2)); int sub__V39_count = sub__V36_count*LINK_COUNT(sub__V39); permitUnusedInt(sub__V39_count);
      CRSX_CHECK_SORT(sink__V32->context, sub__V39, &sort_M_Reified_xSort); /* sub__V39 = &#0-2 */
      Term sub__V40 = LINK(sink__V32->context, SUB(term__V33, 1)); int sub__V40_count = term__V33_count*LINK_COUNT(sub__V40); permitUnusedInt(sub__V40_count);
      CRSX_CHECK_SORT(sink__V32->context, sub__V40, &sort_M_Reified_xVariable); /* sub__V40 = &#3 */
      Term sub__V41 = LINK(sink__V32->context, SUB(term__V33, 2)); int sub__V41_count = term__V33_count*LINK_COUNT(sub__V41); permitUnusedInt(sub__V41_count);
      CRSX_CHECK_SORT(sink__V32->context, sub__V41, &sort_M_Reified_xVariable); /* sub__V41 = &#4 */
      
      NamedPropertyLink namedP__V42 = LINK_NamedPropertyLink(sink__V32->context, NAMED_PROPERTIES(term__V33));
      VariablePropertyLink varP__V43 = LINK_VariablePropertyLink(sink__V32->context, VARIABLE_PROPERTIES(term__V33));
      Hashset namedFV__V44 = LINK_VARIABLESET(sink__V32->context, asConstruction(term__V33)->properties->namedFreeVars);
      Hashset varFV__V45 = LINK_VARIABLESET(sink__V32->context, asConstruction(term__V33)->properties->variableFreeVars);
      UNLINK(sink__V32->context, term__V33);
      ADD_PROPERTIES(sink__V32, LINK_VARIABLESET(sink__V32->context, namedFV__V44), LINK_VARIABLESET(sink__V32->context, varFV__V45), LINK_NamedPropertyLink(sink__V32->context, namedP__V42), LINK_VariablePropertyLink(sink__V32->context, varP__V43));
      { START(sink__V32, _M_D__check__sort_s3);
        COPY(sink__V32, sub__V37);COPY(sink__V32, sub__V38);COPY(sink__V32, sub__V39);COPY(sink__V32, sub__V40);COPY(sink__V32, sub__V41);END(sink__V32, _M_D__check__sort_s3); }
      UNLINK_VARIABLESET(sink__V32->context, namedFV__V44); UNLINK_VARIABLESET(sink__V32->context, varFV__V45);
      UNLINK_NamedPropertyLink(sink__V32->context, namedP__V42); UNLINK_VariablePropertyLink(sink__V32->context, varP__V43);
      
      return 1;
    break; } case Data_M_SORT_VARIABLE: { /* Function CDEFS-D-check-sort-2$D-check-sort$1$SORT-VARIABLE case SORT-VARIABLE */
      ASSERT(sink__V32->context, !strcmp(SYMBOL(term__V33),  "D-check-sort$1" ));
      Term sub__V46 = SUB(term__V33, 0); permitUnusedTerm(sub__V46); int sub__V46_count = term__V33_count*LINK_COUNT(sub__V46); permitUnusedInt(sub__V46_count);
      CRSX_CHECK_SORT(sink__V32->context, sub__V46, &sort_M_Reified_xSort); ASSERT(sink__V32->context, !strcmp(SYMBOL(sub__V46),  "SORT-VARIABLE" ));
      Term sub__V47 = LINK(sink__V32->context, SUB(sub__V46, 0)); int sub__V47_count = sub__V46_count*LINK_COUNT(sub__V47); permitUnusedInt(sub__V47_count);
      CRSX_CHECK_SORT(sink__V32->context, sub__V47, &sort_M_Reified_xVariable); /* sub__V47 = &#0-0 */
      Term sub__V48 = LINK(sink__V32->context, SUB(term__V33, 1)); int sub__V48_count = term__V33_count*LINK_COUNT(sub__V48); permitUnusedInt(sub__V48_count);
      CRSX_CHECK_SORT(sink__V32->context, sub__V48, &sort_M_Reified_xVariable); /* sub__V48 = &#1 */
      Term sub__V49 = LINK(sink__V32->context, SUB(term__V33, 2)); int sub__V49_count = term__V33_count*LINK_COUNT(sub__V49); permitUnusedInt(sub__V49_count);
      CRSX_CHECK_SORT(sink__V32->context, sub__V49, &sort_M_Reified_xVariable); /* sub__V49 = &#2 */
      
      NamedPropertyLink namedP__V50 = LINK_NamedPropertyLink(sink__V32->context, NAMED_PROPERTIES(term__V33));
      VariablePropertyLink varP__V51 = LINK_VariablePropertyLink(sink__V32->context, VARIABLE_PROPERTIES(term__V33));
      Hashset namedFV__V52 = LINK_VARIABLESET(sink__V32->context, asConstruction(term__V33)->properties->namedFreeVars);
      Hashset varFV__V53 = LINK_VARIABLESET(sink__V32->context, asConstruction(term__V33)->properties->variableFreeVars);
      UNLINK(sink__V32->context, term__V33);
      ADD_PROPERTIES(sink__V32, LINK_VARIABLESET(sink__V32->context, namedFV__V52), LINK_VARIABLESET(sink__V32->context, varFV__V53), LINK_NamedPropertyLink(sink__V32->context, namedP__V50), LINK_VariablePropertyLink(sink__V32->context, varP__V51));
      { START(sink__V32, _M_D__check__sort_s4);
        COPY(sink__V32, sub__V47);COPY(sink__V32, sub__V48);COPY(sink__V32, sub__V49);END(sink__V32, _M_D__check__sort_s4); }
      UNLINK_VARIABLESET(sink__V32->context, namedFV__V52); UNLINK_VARIABLESET(sink__V32->context, varFV__V53);
      UNLINK_NamedPropertyLink(sink__V32->context, namedP__V50); UNLINK_VariablePropertyLink(sink__V32->context, varP__V51);
      
      return 1;
    break; } case Data_M_SORT: { /* Function CDEFS-D-check-sort-3$D-check-sort$1$SORT case SORT */
      ASSERT(sink__V32->context, !strcmp(SYMBOL(term__V33),  "D-check-sort$1" ));
      Term sub__V54 = SUB(term__V33, 0); permitUnusedTerm(sub__V54); int sub__V54_count = term__V33_count*LINK_COUNT(sub__V54); permitUnusedInt(sub__V54_count);
      CRSX_CHECK_SORT(sink__V32->context, sub__V54, &sort_M_Reified_xSort); ASSERT(sink__V32->context, !strcmp(SYMBOL(sub__V54),  "SORT" ));
      Term sub__V55 = LINK(sink__V32->context, SUB(sub__V54, 0)); int sub__V55_count = sub__V54_count*LINK_COUNT(sub__V55); permitUnusedInt(sub__V55_count);
      /* sub__V55 = &#0-0 */
      Term sub__V56 = LINK(sink__V32->context, SUB(sub__V54, 1)); int sub__V56_count = sub__V54_count*LINK_COUNT(sub__V56); permitUnusedInt(sub__V56_count);
      /* sub__V56 = &#0-1 */
      Term sub__V57 = LINK(sink__V32->context, SUB(term__V33, 1)); int sub__V57_count = term__V33_count*LINK_COUNT(sub__V57); permitUnusedInt(sub__V57_count);
      CRSX_CHECK_SORT(sink__V32->context, sub__V57, &sort_M_Reified_xVariable); /* sub__V57 = &#2 */
      Term sub__V58 = LINK(sink__V32->context, SUB(term__V33, 2)); int sub__V58_count = term__V33_count*LINK_COUNT(sub__V58); permitUnusedInt(sub__V58_count);
      CRSX_CHECK_SORT(sink__V32->context, sub__V58, &sort_M_Reified_xVariable); /* sub__V58 = &#3 */
      
      NamedPropertyLink namedP__V59 = LINK_NamedPropertyLink(sink__V32->context, NAMED_PROPERTIES(term__V33));
      VariablePropertyLink varP__V60 = LINK_VariablePropertyLink(sink__V32->context, VARIABLE_PROPERTIES(term__V33));
      Hashset namedFV__V61 = LINK_VARIABLESET(sink__V32->context, asConstruction(term__V33)->properties->namedFreeVars);
      Hashset varFV__V62 = LINK_VARIABLESET(sink__V32->context, asConstruction(term__V33)->properties->variableFreeVars);
      UNLINK(sink__V32->context, term__V33);
      ADD_PROPERTIES(sink__V32, LINK_VARIABLESET(sink__V32->context, namedFV__V61), LINK_VARIABLESET(sink__V32->context, varFV__V62), LINK_NamedPropertyLink(sink__V32->context, namedP__V59), LINK_VariablePropertyLink(sink__V32->context, varP__V60));
      { START(sink__V32, _M_D__check__sort_s2);
        COPY(sink__V32, sub__V55);COPY(sink__V32, sub__V56);COPY(sink__V32, sub__V57);COPY(sink__V32, sub__V58);END(sink__V32, _M_D__check__sort_s2); }
      UNLINK_VARIABLESET(sink__V32->context, namedFV__V61); UNLINK_VARIABLESET(sink__V32->context, varFV__V62);
      UNLINK_NamedPropertyLink(sink__V32->context, namedP__V59); UNLINK_VariablePropertyLink(sink__V32->context, varP__V60);
      
      return 1;
    } default: break;
  }
  return 0;
}

#ifdef __cplusplus
}
#endif
/* END OF C RULES FOR CRSX CRSXC MODULE CD. */
