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
    UNLINK(sink__V1->context, term__V2);
    { START(sink__V1, _M__sTextNil); END(sink__V1, _M__sTextNil); } UNLINK_NamedPropertyLink(sink__V1->context, namedP__V6); UNLINK_VariablePropertyLink(sink__V1->context, varP__V7);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION D-check-sort$2. */
int conBindOffs_M_D__check__sort_s2[] = {0 , 0 , 0 , 0 , 0};
char *nameFun_M_D__check__sort_s2(Term term) { return  "D-check-sort$2" ; }
struct _ConstructionDescriptor descriptor_M_D__check__sort_s2 = {&sort_M_Reified_xVariable, 0, 4, sizeof(STRUCT_Con_M_D__check__sort_s2), conBindOffs_M_D__check__sort_s2, &nameFun_M_D__check__sort_s2, &step_M_D__check__sort_s2};

int step_M_D__check__sort_s2(Sink sink__V8, Term term__V9)
{
  int term__V9_count = LINK_COUNT(term__V9); permitUnusedInt(term__V9_count);
  do {
    /* Contraction rule CDEFS-D-check-sort-3. */
    ASSERT(sink__V8->context, !strcmp(SYMBOL(term__V9),  "D-check-sort$2" ));
    Term sub__V10 = LINK(sink__V8->context, SUB(term__V9, 0)); int sub__V10_count = term__V9_count*LINK_COUNT(sub__V10); permitUnusedInt(sub__V10_count);
    /* sub__V10 = &#31 */
    Term sub__V11 = SUB(term__V9, 1); permitUnusedTerm(sub__V11); int sub__V11_count = term__V9_count*LINK_COUNT(sub__V11); permitUnusedInt(sub__V11_count);
    /* sub__V11 = &#32 */
    Term sub__V12 = LINK(sink__V8->context, SUB(term__V9, 2)); int sub__V12_count = term__V9_count*LINK_COUNT(sub__V12); permitUnusedInt(sub__V12_count);
    CRSX_CHECK_SORT(sink__V8->context, sub__V12, &sort_M_Reified_xVariable); /* sub__V12 = &#2 */
    Term sub__V13 = LINK(sink__V8->context, SUB(term__V9, 3)); int sub__V13_count = term__V9_count*LINK_COUNT(sub__V13); permitUnusedInt(sub__V13_count);
    CRSX_CHECK_SORT(sink__V8->context, sub__V13, &sort_M_Reified_xVariable); /* sub__V13 = &#1 */
    NamedPropertyLink namedP__V14 = LINK_NamedPropertyLink(sink__V8->context, NAMED_PROPERTIES(term__V9));
    VariablePropertyLink varP__V15 = LINK_VariablePropertyLink(sink__V8->context, VARIABLE_PROPERTIES(term__V9));
    UNLINK(sink__V8->context, term__V9);
    { int test__V16;
      FORCE(sink__V8->context, sub__V10);
      test__V16 = (int) (strstr(SYMBOL(sub__V10), "$" ) != NULL); if (test__V16) {  UNLINK(sink__V8->context, sub__V10);  UNLINK(sink__V8->context, sub__V12);  UNLINK(sink__V8->context, sub__V13); { START(sink__V8, _M__sTextNil); END(sink__V8, _M__sTextNil); }
         }
      else { { START(sink__V8, _M__sTextCons);
          { START(sink__V8, _M__sTextChars);
            LITERAL(sink__V8,  "CRSX_CHECK_SORT(" ); END(sink__V8, _M__sTextChars); }
          { START(sink__V8, _M__sTextCons);
            { START(sink__V8, _M__sTextEmbed);
              { START(sink__V8, _M_AsText);
                COPY(sink__V8, sub__V13);END(sink__V8, _M_AsText); }
              END(sink__V8, _M__sTextEmbed); }
            { START(sink__V8, _M__sTextCons);
              { START(sink__V8, _M__sTextChars);
                LITERAL(sink__V8,  "->context, " ); END(sink__V8, _M__sTextChars); }
              { START(sink__V8, _M__sTextCons);
                { START(sink__V8, _M__sTextEmbed);
                  { START(sink__V8, _M_AsText);
                    COPY(sink__V8, sub__V12);END(sink__V8, _M_AsText); }
                  END(sink__V8, _M__sTextEmbed); }
                { START(sink__V8, _M__sTextCons);
                  { START(sink__V8, _M__sTextChars);
                    LITERAL(sink__V8,  ", &" ); END(sink__V8, _M__sTextChars); }
                  { START(sink__V8, _M__sTextCons);
                    { START(sink__V8, _M__sTextEmbed);
                      { START(sink__V8, _M_AsText);
                        { START(sink__V8, _M_Sort);
                          COPY(sink__V8, sub__V10);END(sink__V8, _M_Sort); }
                        END(sink__V8, _M_AsText); }
                      END(sink__V8, _M__sTextEmbed); }
                    { START(sink__V8, _M__sTextCons);
                      { START(sink__V8, _M__sTextChars);
                        LITERAL(sink__V8,  "); " ); END(sink__V8, _M__sTextChars); }
                      { START(sink__V8, _M__sTextNil);
                        END(sink__V8, _M__sTextNil); }
                      END(sink__V8, _M__sTextCons); }
                    END(sink__V8, _M__sTextCons); }
                  END(sink__V8, _M__sTextCons); }
                END(sink__V8, _M__sTextCons); }
              END(sink__V8, _M__sTextCons); }
            END(sink__V8, _M__sTextCons); }
          END(sink__V8, _M__sTextCons); }
         }
    }
    UNLINK_NamedPropertyLink(sink__V8->context, namedP__V14); UNLINK_VariablePropertyLink(sink__V8->context, varP__V15);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION D-check-sort$3. */
int conBindOffs_M_D__check__sort_s3[] = {0 , 0 , 0 , 0 , 0 , 0};
char *nameFun_M_D__check__sort_s3(Term term) { return  "D-check-sort$3" ; }
struct _ConstructionDescriptor descriptor_M_D__check__sort_s3 = {&sort_M_Reified_xVariable, 0, 5, sizeof(STRUCT_Con_M_D__check__sort_s3), conBindOffs_M_D__check__sort_s3, &nameFun_M_D__check__sort_s3, &step_M_D__check__sort_s3};

int step_M_D__check__sort_s3(Sink sink__V17, Term term__V18)
{
  int term__V18_count = LINK_COUNT(term__V18); permitUnusedInt(term__V18_count);
  do {
    /* Contraction rule CDEFS-D-check-sort-1. */
    ASSERT(sink__V17->context, !strcmp(SYMBOL(term__V18),  "D-check-sort$3" ));
    Term sub__V19 = SUB(term__V18, 0); permitUnusedTerm(sub__V19); int sub__V19_count = term__V18_count*LINK_COUNT(sub__V19); permitUnusedInt(sub__V19_count);
    CRSX_CHECK_SORT(sink__V17->context, sub__V19, &sort_M_Reified_xSort); /* sub__V19 = &#31 */
    Term sub__V20 = SUB(term__V18, 1); permitUnusedTerm(sub__V20); int sub__V20_count = term__V18_count*LINK_COUNT(sub__V20); permitUnusedInt(sub__V20_count);
    CRSX_CHECK_SORT(sink__V17->context, sub__V20, &sort_M_Reified_xSort); /* sub__V20 = &#32 */
    Term sub__V21 = LINK(sink__V17->context, SUB(term__V18, 2)); int sub__V21_count = term__V18_count*LINK_COUNT(sub__V21); permitUnusedInt(sub__V21_count);
    CRSX_CHECK_SORT(sink__V17->context, sub__V21, &sort_M_Reified_xSort); /* sub__V21 = &#33 */
    Term sub__V22 = LINK(sink__V17->context, SUB(term__V18, 3)); int sub__V22_count = term__V18_count*LINK_COUNT(sub__V22); permitUnusedInt(sub__V22_count);
    CRSX_CHECK_SORT(sink__V17->context, sub__V22, &sort_M_Reified_xVariable); /* sub__V22 = &#2 */
    Term sub__V23 = LINK(sink__V17->context, SUB(term__V18, 4)); int sub__V23_count = term__V18_count*LINK_COUNT(sub__V23); permitUnusedInt(sub__V23_count);
    CRSX_CHECK_SORT(sink__V17->context, sub__V23, &sort_M_Reified_xVariable); /* sub__V23 = &#1 */
    NamedPropertyLink namedP__V24 = LINK_NamedPropertyLink(sink__V17->context, NAMED_PROPERTIES(term__V18));
    VariablePropertyLink varP__V25 = LINK_VariablePropertyLink(sink__V17->context, VARIABLE_PROPERTIES(term__V18));
    UNLINK(sink__V17->context, term__V18);
    { START(sink__V17, _M_D__check__sort_s1);
      COPY(sink__V17, sub__V21);COPY(sink__V17, sub__V22);COPY(sink__V17, sub__V23);END(sink__V17, _M_D__check__sort_s1); }
    UNLINK_NamedPropertyLink(sink__V17->context, namedP__V24); UNLINK_VariablePropertyLink(sink__V17->context, varP__V25);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION D-check-sort$1. */
int conBindOffs_M_D__check__sort_s1[] = {0 , 0 , 0 , 0};
char *nameFun_M_D__check__sort_s1(Term term) { return  "D-check-sort$1" ; }
struct _ConstructionDescriptor descriptor_M_D__check__sort_s1 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_D__check__sort_s1), conBindOffs_M_D__check__sort_s1, &nameFun_M_D__check__sort_s1, &step_M_D__check__sort_s1};

int step_M_D__check__sort_s1(Sink sink__V26, Term term__V27)
{
  int term__V27_count = LINK_COUNT(term__V27); permitUnusedInt(term__V27_count);
  Term sub__V28 = FORCE(sink__V26->context, SUB(term__V27, 0));
  EnumOf_M_Reified_xSort choice__V29 = (IS_VARIABLE_USE(sub__V28) ? VarOf_M_Reified_xSort : (EnumOf_M_Reified_xSort) TAG(sub__V28));
  switch (choice__V29)
  {
    case Data_M_SORT_PROPERTY: { /* Function CDEFS-D-check-sort-1$D-check-sort$1$SORT-PROPERTY case SORT-PROPERTY */
      ASSERT(sink__V26->context, !strcmp(SYMBOL(term__V27),  "D-check-sort$1" ));
      Term sub__V30 = SUB(term__V27, 0); permitUnusedTerm(sub__V30); int sub__V30_count = term__V27_count*LINK_COUNT(sub__V30); permitUnusedInt(sub__V30_count);
      CRSX_CHECK_SORT(sink__V26->context, sub__V30, &sort_M_Reified_xSort); ASSERT(sink__V26->context, !strcmp(SYMBOL(sub__V30),  "SORT-PROPERTY" ));
      Term sub__V31 = LINK(sink__V26->context, SUB(sub__V30, 0)); int sub__V31_count = sub__V30_count*LINK_COUNT(sub__V31); permitUnusedInt(sub__V31_count);
      CRSX_CHECK_SORT(sink__V26->context, sub__V31, &sort_M_Reified_xSort); /* sub__V31 = &#0-0 */
      Term sub__V32 = LINK(sink__V26->context, SUB(sub__V30, 1)); int sub__V32_count = sub__V30_count*LINK_COUNT(sub__V32); permitUnusedInt(sub__V32_count);
      CRSX_CHECK_SORT(sink__V26->context, sub__V32, &sort_M_Reified_xSort); /* sub__V32 = &#0-1 */
      Term sub__V33 = LINK(sink__V26->context, SUB(sub__V30, 2)); int sub__V33_count = sub__V30_count*LINK_COUNT(sub__V33); permitUnusedInt(sub__V33_count);
      CRSX_CHECK_SORT(sink__V26->context, sub__V33, &sort_M_Reified_xSort); /* sub__V33 = &#0-2 */
      Term sub__V34 = LINK(sink__V26->context, SUB(term__V27, 1)); int sub__V34_count = term__V27_count*LINK_COUNT(sub__V34); permitUnusedInt(sub__V34_count);
      CRSX_CHECK_SORT(sink__V26->context, sub__V34, &sort_M_Reified_xVariable); /* sub__V34 = &#3 */
      Term sub__V35 = LINK(sink__V26->context, SUB(term__V27, 2)); int sub__V35_count = term__V27_count*LINK_COUNT(sub__V35); permitUnusedInt(sub__V35_count);
      CRSX_CHECK_SORT(sink__V26->context, sub__V35, &sort_M_Reified_xVariable); /* sub__V35 = &#4 */
      NamedPropertyLink namedP__V36 = LINK_NamedPropertyLink(sink__V26->context, NAMED_PROPERTIES(term__V27));
      VariablePropertyLink varP__V37 = LINK_VariablePropertyLink(sink__V26->context, VARIABLE_PROPERTIES(term__V27));
      UNLINK(sink__V26->context, term__V27);
      ADD_PROPERTIES(sink__V26, LINK_NamedPropertyLink(sink__V26->context, namedP__V36), LINK_VariablePropertyLink(sink__V26->context, varP__V37));
      { START(sink__V26, _M_D__check__sort_s3);
        COPY(sink__V26, sub__V31);COPY(sink__V26, sub__V32);COPY(sink__V26, sub__V33);COPY(sink__V26, sub__V34);COPY(sink__V26, sub__V35);END(sink__V26, _M_D__check__sort_s3); }
      UNLINK_NamedPropertyLink(sink__V26->context, namedP__V36); UNLINK_VariablePropertyLink(sink__V26->context, varP__V37);
      
      return 1;
    break; } case Data_M_SORT_VARIABLE: { /* Function CDEFS-D-check-sort-2$D-check-sort$1$SORT-VARIABLE case SORT-VARIABLE */
      ASSERT(sink__V26->context, !strcmp(SYMBOL(term__V27),  "D-check-sort$1" ));
      Term sub__V38 = SUB(term__V27, 0); permitUnusedTerm(sub__V38); int sub__V38_count = term__V27_count*LINK_COUNT(sub__V38); permitUnusedInt(sub__V38_count);
      CRSX_CHECK_SORT(sink__V26->context, sub__V38, &sort_M_Reified_xSort); ASSERT(sink__V26->context, !strcmp(SYMBOL(sub__V38),  "SORT-VARIABLE" ));
      Term sub__V39 = LINK(sink__V26->context, SUB(sub__V38, 0)); int sub__V39_count = sub__V38_count*LINK_COUNT(sub__V39); permitUnusedInt(sub__V39_count);
      CRSX_CHECK_SORT(sink__V26->context, sub__V39, &sort_M_Reified_xVariable); /* sub__V39 = &#0-0 */
      Term sub__V40 = LINK(sink__V26->context, SUB(term__V27, 1)); int sub__V40_count = term__V27_count*LINK_COUNT(sub__V40); permitUnusedInt(sub__V40_count);
      CRSX_CHECK_SORT(sink__V26->context, sub__V40, &sort_M_Reified_xVariable); /* sub__V40 = &#1 */
      Term sub__V41 = LINK(sink__V26->context, SUB(term__V27, 2)); int sub__V41_count = term__V27_count*LINK_COUNT(sub__V41); permitUnusedInt(sub__V41_count);
      CRSX_CHECK_SORT(sink__V26->context, sub__V41, &sort_M_Reified_xVariable); /* sub__V41 = &#2 */
      NamedPropertyLink namedP__V42 = LINK_NamedPropertyLink(sink__V26->context, NAMED_PROPERTIES(term__V27));
      VariablePropertyLink varP__V43 = LINK_VariablePropertyLink(sink__V26->context, VARIABLE_PROPERTIES(term__V27));
      UNLINK(sink__V26->context, term__V27);
      ADD_PROPERTIES(sink__V26, LINK_NamedPropertyLink(sink__V26->context, namedP__V42), LINK_VariablePropertyLink(sink__V26->context, varP__V43));
      { START(sink__V26, _M_D__check__sort_s4);
        COPY(sink__V26, sub__V39);COPY(sink__V26, sub__V40);COPY(sink__V26, sub__V41);END(sink__V26, _M_D__check__sort_s4); }
      UNLINK_NamedPropertyLink(sink__V26->context, namedP__V42); UNLINK_VariablePropertyLink(sink__V26->context, varP__V43);
      
      return 1;
    break; } case Data_M_SORT: { /* Function CDEFS-D-check-sort-3$D-check-sort$1$SORT case SORT */
      ASSERT(sink__V26->context, !strcmp(SYMBOL(term__V27),  "D-check-sort$1" ));
      Term sub__V44 = SUB(term__V27, 0); permitUnusedTerm(sub__V44); int sub__V44_count = term__V27_count*LINK_COUNT(sub__V44); permitUnusedInt(sub__V44_count);
      CRSX_CHECK_SORT(sink__V26->context, sub__V44, &sort_M_Reified_xSort); ASSERT(sink__V26->context, !strcmp(SYMBOL(sub__V44),  "SORT" ));
      Term sub__V45 = LINK(sink__V26->context, SUB(sub__V44, 0)); int sub__V45_count = sub__V44_count*LINK_COUNT(sub__V45); permitUnusedInt(sub__V45_count);
      /* sub__V45 = &#0-0 */
      Term sub__V46 = LINK(sink__V26->context, SUB(sub__V44, 1)); int sub__V46_count = sub__V44_count*LINK_COUNT(sub__V46); permitUnusedInt(sub__V46_count);
      /* sub__V46 = &#0-1 */
      Term sub__V47 = LINK(sink__V26->context, SUB(term__V27, 1)); int sub__V47_count = term__V27_count*LINK_COUNT(sub__V47); permitUnusedInt(sub__V47_count);
      CRSX_CHECK_SORT(sink__V26->context, sub__V47, &sort_M_Reified_xVariable); /* sub__V47 = &#2 */
      Term sub__V48 = LINK(sink__V26->context, SUB(term__V27, 2)); int sub__V48_count = term__V27_count*LINK_COUNT(sub__V48); permitUnusedInt(sub__V48_count);
      CRSX_CHECK_SORT(sink__V26->context, sub__V48, &sort_M_Reified_xVariable); /* sub__V48 = &#3 */
      NamedPropertyLink namedP__V49 = LINK_NamedPropertyLink(sink__V26->context, NAMED_PROPERTIES(term__V27));
      VariablePropertyLink varP__V50 = LINK_VariablePropertyLink(sink__V26->context, VARIABLE_PROPERTIES(term__V27));
      UNLINK(sink__V26->context, term__V27);
      ADD_PROPERTIES(sink__V26, LINK_NamedPropertyLink(sink__V26->context, namedP__V49), LINK_VariablePropertyLink(sink__V26->context, varP__V50));
      { START(sink__V26, _M_D__check__sort_s2);
        COPY(sink__V26, sub__V45);COPY(sink__V26, sub__V46);COPY(sink__V26, sub__V47);COPY(sink__V26, sub__V48);END(sink__V26, _M_D__check__sort_s2); }
      UNLINK_NamedPropertyLink(sink__V26->context, namedP__V49); UNLINK_VariablePropertyLink(sink__V26->context, varP__V50);
      
      return 1;
    } default: break;
  }
  return 0;
}

#ifdef __cplusplus
}
#endif
/* END OF C RULES FOR CRSX CRSXC MODULE CD. */
