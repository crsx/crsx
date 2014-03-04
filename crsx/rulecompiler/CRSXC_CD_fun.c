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
      UNLINK(sink__V1->context, term__V2);
      ADD_PROPERTIES(sink__V1, LINK_NamedPropertyLink(sink__V1->context, namedP__V11), LINK_VariablePropertyLink(sink__V1->context, varP__V12));
      { START(sink__V1, _M_D__check__sort_s3);
        COPY(sink__V1, sub__V6);COPY(sink__V1, sub__V7);COPY(sink__V1, sub__V8);COPY(sink__V1, sub__V9);COPY(sink__V1, sub__V10);END(sink__V1, _M_D__check__sort_s3); }
      UNLINK_NamedPropertyLink(sink__V1->context, namedP__V11); UNLINK_VariablePropertyLink(sink__V1->context, varP__V12);
      
      return 1;
    break; } case Data_M_SORT_VARIABLE: { /* Function CDEFS-D-check-sort-2$D-check-sort$1$SORT-VARIABLE case SORT-VARIABLE */
      ASSERT(sink__V1->context, !strcmp(SYMBOL(term__V2),  "D-check-sort$1" ));
      Term sub__V13 = SUB(term__V2, 0); permitUnusedTerm(sub__V13); int sub__V13_count = term__V2_count*LINK_COUNT(sub__V13); permitUnusedInt(sub__V13_count);
      CRSX_CHECK_SORT(sink__V1->context, sub__V13, &sort_M_Reified_xSort); ASSERT(sink__V1->context, !strcmp(SYMBOL(sub__V13),  "SORT-VARIABLE" ));
      Term sub__V14 = LINK(sink__V1->context, SUB(sub__V13, 0)); int sub__V14_count = sub__V13_count*LINK_COUNT(sub__V14); permitUnusedInt(sub__V14_count);
      CRSX_CHECK_SORT(sink__V1->context, sub__V14, &sort_M_Reified_xVariable); /* sub__V14 = &#0-0 */
      Term sub__V15 = LINK(sink__V1->context, SUB(term__V2, 1)); int sub__V15_count = term__V2_count*LINK_COUNT(sub__V15); permitUnusedInt(sub__V15_count);
      CRSX_CHECK_SORT(sink__V1->context, sub__V15, &sort_M_Reified_xVariable); /* sub__V15 = &#1 */
      Term sub__V16 = LINK(sink__V1->context, SUB(term__V2, 2)); int sub__V16_count = term__V2_count*LINK_COUNT(sub__V16); permitUnusedInt(sub__V16_count);
      CRSX_CHECK_SORT(sink__V1->context, sub__V16, &sort_M_Reified_xVariable); /* sub__V16 = &#2 */
      NamedPropertyLink namedP__V17 = LINK_NamedPropertyLink(sink__V1->context, NAMED_PROPERTIES(term__V2));
      VariablePropertyLink varP__V18 = LINK_VariablePropertyLink(sink__V1->context, VARIABLE_PROPERTIES(term__V2));
      UNLINK(sink__V1->context, term__V2);
      ADD_PROPERTIES(sink__V1, LINK_NamedPropertyLink(sink__V1->context, namedP__V17), LINK_VariablePropertyLink(sink__V1->context, varP__V18));
      { START(sink__V1, _M_D__check__sort_s4);
        COPY(sink__V1, sub__V14);COPY(sink__V1, sub__V15);COPY(sink__V1, sub__V16);END(sink__V1, _M_D__check__sort_s4); }
      UNLINK_NamedPropertyLink(sink__V1->context, namedP__V17); UNLINK_VariablePropertyLink(sink__V1->context, varP__V18);
      
      return 1;
    break; } case Data_M_SORT: { /* Function CDEFS-D-check-sort-3$D-check-sort$1$SORT case SORT */
      ASSERT(sink__V1->context, !strcmp(SYMBOL(term__V2),  "D-check-sort$1" ));
      Term sub__V19 = SUB(term__V2, 0); permitUnusedTerm(sub__V19); int sub__V19_count = term__V2_count*LINK_COUNT(sub__V19); permitUnusedInt(sub__V19_count);
      CRSX_CHECK_SORT(sink__V1->context, sub__V19, &sort_M_Reified_xSort); ASSERT(sink__V1->context, !strcmp(SYMBOL(sub__V19),  "SORT" ));
      Term sub__V20 = LINK(sink__V1->context, SUB(sub__V19, 0)); int sub__V20_count = sub__V19_count*LINK_COUNT(sub__V20); permitUnusedInt(sub__V20_count);
      /* sub__V20 = &#0-0 */
      Term sub__V21 = LINK(sink__V1->context, SUB(sub__V19, 1)); int sub__V21_count = sub__V19_count*LINK_COUNT(sub__V21); permitUnusedInt(sub__V21_count);
      /* sub__V21 = &#0-1 */
      Term sub__V22 = LINK(sink__V1->context, SUB(term__V2, 1)); int sub__V22_count = term__V2_count*LINK_COUNT(sub__V22); permitUnusedInt(sub__V22_count);
      CRSX_CHECK_SORT(sink__V1->context, sub__V22, &sort_M_Reified_xVariable); /* sub__V22 = &#2 */
      Term sub__V23 = LINK(sink__V1->context, SUB(term__V2, 2)); int sub__V23_count = term__V2_count*LINK_COUNT(sub__V23); permitUnusedInt(sub__V23_count);
      CRSX_CHECK_SORT(sink__V1->context, sub__V23, &sort_M_Reified_xVariable); /* sub__V23 = &#3 */
      NamedPropertyLink namedP__V24 = LINK_NamedPropertyLink(sink__V1->context, NAMED_PROPERTIES(term__V2));
      VariablePropertyLink varP__V25 = LINK_VariablePropertyLink(sink__V1->context, VARIABLE_PROPERTIES(term__V2));
      UNLINK(sink__V1->context, term__V2);
      ADD_PROPERTIES(sink__V1, LINK_NamedPropertyLink(sink__V1->context, namedP__V24), LINK_VariablePropertyLink(sink__V1->context, varP__V25));
      { START(sink__V1, _M_D__check__sort_s2);
        COPY(sink__V1, sub__V20);COPY(sink__V1, sub__V21);COPY(sink__V1, sub__V22);COPY(sink__V1, sub__V23);END(sink__V1, _M_D__check__sort_s2); }
      UNLINK_NamedPropertyLink(sink__V1->context, namedP__V24); UNLINK_VariablePropertyLink(sink__V1->context, varP__V25);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION D-check-sort$2. */
int conBindOffs_M_D__check__sort_s2[] = {0 , 0 , 0 , 0 , 0};
char *nameFun_M_D__check__sort_s2(Term term) { return  "D-check-sort$2" ; }
struct _ConstructionDescriptor descriptor_M_D__check__sort_s2 = {&sort_M_Reified_xVariable, 0, 4, sizeof(STRUCT_Con_M_D__check__sort_s2), conBindOffs_M_D__check__sort_s2, &nameFun_M_D__check__sort_s2, &step_M_D__check__sort_s2};

int step_M_D__check__sort_s2(Sink sink__V26, Term term__V27)
{
  int term__V27_count = LINK_COUNT(term__V27); permitUnusedInt(term__V27_count);
  do {
    /* Contraction rule CDEFS-D-check-sort-3. */
    ASSERT(sink__V26->context, !strcmp(SYMBOL(term__V27),  "D-check-sort$2" ));
    Term sub__V28 = LINK(sink__V26->context, SUB(term__V27, 0)); int sub__V28_count = term__V27_count*LINK_COUNT(sub__V28); permitUnusedInt(sub__V28_count);
    /* sub__V28 = &#31 */
    Term sub__V29 = SUB(term__V27, 1); permitUnusedTerm(sub__V29); int sub__V29_count = term__V27_count*LINK_COUNT(sub__V29); permitUnusedInt(sub__V29_count);
    /* sub__V29 = &#32 */
    Term sub__V30 = LINK(sink__V26->context, SUB(term__V27, 2)); int sub__V30_count = term__V27_count*LINK_COUNT(sub__V30); permitUnusedInt(sub__V30_count);
    CRSX_CHECK_SORT(sink__V26->context, sub__V30, &sort_M_Reified_xVariable); /* sub__V30 = &#2 */
    Term sub__V31 = LINK(sink__V26->context, SUB(term__V27, 3)); int sub__V31_count = term__V27_count*LINK_COUNT(sub__V31); permitUnusedInt(sub__V31_count);
    CRSX_CHECK_SORT(sink__V26->context, sub__V31, &sort_M_Reified_xVariable); /* sub__V31 = &#1 */
    NamedPropertyLink namedP__V32 = LINK_NamedPropertyLink(sink__V26->context, NAMED_PROPERTIES(term__V27));
    VariablePropertyLink varP__V33 = LINK_VariablePropertyLink(sink__V26->context, VARIABLE_PROPERTIES(term__V27));
    UNLINK(sink__V26->context, term__V27);
    { int test__V34;
      FORCE(sink__V26->context, sub__V28);
      test__V34 = (int) (strstr(SYMBOL(sub__V28), "$" ) != NULL); if (test__V34) {  UNLINK(sink__V26->context, sub__V30);  UNLINK(sink__V26->context, sub__V31);  UNLINK(sink__V26->context, sub__V28); { START(sink__V26, _M__sTextNil);
          END(sink__V26, _M__sTextNil); }
         }
      else { { START(sink__V26, _M__sTextCons);
          { START(sink__V26, _M__sTextChars);
            LITERAL(sink__V26,  "CRSX_CHECK_SORT(" ); END(sink__V26, _M__sTextChars); }
          { START(sink__V26, _M__sTextCons);
            { START(sink__V26, _M__sTextEmbed);
              { START(sink__V26, _M_AsText);
                COPY(sink__V26, sub__V31);END(sink__V26, _M_AsText); }
              END(sink__V26, _M__sTextEmbed); }
            { START(sink__V26, _M__sTextCons);
              { START(sink__V26, _M__sTextChars);
                LITERAL(sink__V26,  "->context, " ); END(sink__V26, _M__sTextChars); }
              { START(sink__V26, _M__sTextCons);
                { START(sink__V26, _M__sTextEmbed);
                  { START(sink__V26, _M_AsText);
                    COPY(sink__V26, sub__V30);END(sink__V26, _M_AsText); }
                  END(sink__V26, _M__sTextEmbed); }
                { START(sink__V26, _M__sTextCons);
                  { START(sink__V26, _M__sTextChars);
                    LITERAL(sink__V26,  ", &" ); END(sink__V26, _M__sTextChars); }
                  { START(sink__V26, _M__sTextCons);
                    { START(sink__V26, _M__sTextEmbed);
                      { START(sink__V26, _M_AsText);
                        { START(sink__V26, _M_Sort);
                          COPY(sink__V26, sub__V28);END(sink__V26, _M_Sort); }
                        END(sink__V26, _M_AsText); }
                      END(sink__V26, _M__sTextEmbed); }
                    { START(sink__V26, _M__sTextCons);
                      { START(sink__V26, _M__sTextChars);
                        LITERAL(sink__V26,  "); " ); END(sink__V26, _M__sTextChars); }
                      { START(sink__V26, _M__sTextNil);
                        END(sink__V26, _M__sTextNil); }
                      END(sink__V26, _M__sTextCons); }
                    END(sink__V26, _M__sTextCons); }
                  END(sink__V26, _M__sTextCons); }
                END(sink__V26, _M__sTextCons); }
              END(sink__V26, _M__sTextCons); }
            END(sink__V26, _M__sTextCons); }
          END(sink__V26, _M__sTextCons); }
         }
    }
    UNLINK_NamedPropertyLink(sink__V26->context, namedP__V32); UNLINK_VariablePropertyLink(sink__V26->context, varP__V33);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION D-check-sort$3. */
int conBindOffs_M_D__check__sort_s3[] = {0 , 0 , 0 , 0 , 0 , 0};
char *nameFun_M_D__check__sort_s3(Term term) { return  "D-check-sort$3" ; }
struct _ConstructionDescriptor descriptor_M_D__check__sort_s3 = {&sort_M_Reified_xVariable, 0, 5, sizeof(STRUCT_Con_M_D__check__sort_s3), conBindOffs_M_D__check__sort_s3, &nameFun_M_D__check__sort_s3, &step_M_D__check__sort_s3};

int step_M_D__check__sort_s3(Sink sink__V35, Term term__V36)
{
  int term__V36_count = LINK_COUNT(term__V36); permitUnusedInt(term__V36_count);
  do {
    /* Contraction rule CDEFS-D-check-sort-1. */
    ASSERT(sink__V35->context, !strcmp(SYMBOL(term__V36),  "D-check-sort$3" ));
    Term sub__V37 = SUB(term__V36, 0); permitUnusedTerm(sub__V37); int sub__V37_count = term__V36_count*LINK_COUNT(sub__V37); permitUnusedInt(sub__V37_count);
    CRSX_CHECK_SORT(sink__V35->context, sub__V37, &sort_M_Reified_xSort); /* sub__V37 = &#31 */
    Term sub__V38 = SUB(term__V36, 1); permitUnusedTerm(sub__V38); int sub__V38_count = term__V36_count*LINK_COUNT(sub__V38); permitUnusedInt(sub__V38_count);
    CRSX_CHECK_SORT(sink__V35->context, sub__V38, &sort_M_Reified_xSort); /* sub__V38 = &#32 */
    Term sub__V39 = LINK(sink__V35->context, SUB(term__V36, 2)); int sub__V39_count = term__V36_count*LINK_COUNT(sub__V39); permitUnusedInt(sub__V39_count);
    CRSX_CHECK_SORT(sink__V35->context, sub__V39, &sort_M_Reified_xSort); /* sub__V39 = &#33 */
    Term sub__V40 = LINK(sink__V35->context, SUB(term__V36, 3)); int sub__V40_count = term__V36_count*LINK_COUNT(sub__V40); permitUnusedInt(sub__V40_count);
    CRSX_CHECK_SORT(sink__V35->context, sub__V40, &sort_M_Reified_xVariable); /* sub__V40 = &#2 */
    Term sub__V41 = LINK(sink__V35->context, SUB(term__V36, 4)); int sub__V41_count = term__V36_count*LINK_COUNT(sub__V41); permitUnusedInt(sub__V41_count);
    CRSX_CHECK_SORT(sink__V35->context, sub__V41, &sort_M_Reified_xVariable); /* sub__V41 = &#1 */
    NamedPropertyLink namedP__V42 = LINK_NamedPropertyLink(sink__V35->context, NAMED_PROPERTIES(term__V36));
    VariablePropertyLink varP__V43 = LINK_VariablePropertyLink(sink__V35->context, VARIABLE_PROPERTIES(term__V36));
    UNLINK(sink__V35->context, term__V36);
    { START(sink__V35, _M_D__check__sort_s1);
      COPY(sink__V35, sub__V39);COPY(sink__V35, sub__V40);COPY(sink__V35, sub__V41);END(sink__V35, _M_D__check__sort_s1); }
    UNLINK_NamedPropertyLink(sink__V35->context, namedP__V42); UNLINK_VariablePropertyLink(sink__V35->context, varP__V43);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION D-check-sort$4. */
int conBindOffs_M_D__check__sort_s4[] = {0 , 0 , 0 , 0};
char *nameFun_M_D__check__sort_s4(Term term) { return  "D-check-sort$4" ; }
struct _ConstructionDescriptor descriptor_M_D__check__sort_s4 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_D__check__sort_s4), conBindOffs_M_D__check__sort_s4, &nameFun_M_D__check__sort_s4, &step_M_D__check__sort_s4};

int step_M_D__check__sort_s4(Sink sink__V44, Term term__V45)
{
  int term__V45_count = LINK_COUNT(term__V45); permitUnusedInt(term__V45_count);
  do {
    /* Contraction rule CDEFS-D-check-sort-2. */
    ASSERT(sink__V44->context, !strcmp(SYMBOL(term__V45),  "D-check-sort$4" ));
    Term sub__V46 = SUB(term__V45, 0); permitUnusedTerm(sub__V46); int sub__V46_count = term__V45_count*LINK_COUNT(sub__V46); permitUnusedInt(sub__V46_count);
    CRSX_CHECK_SORT(sink__V44->context, sub__V46, &sort_M_Reified_xVariable); /* sub__V46 = &#31 */
    Term sub__V47 = SUB(term__V45, 1); permitUnusedTerm(sub__V47); int sub__V47_count = term__V45_count*LINK_COUNT(sub__V47); permitUnusedInt(sub__V47_count);
    CRSX_CHECK_SORT(sink__V44->context, sub__V47, &sort_M_Reified_xVariable); /* sub__V47 = &#2 */
    Term sub__V48 = SUB(term__V45, 2); permitUnusedTerm(sub__V48); int sub__V48_count = term__V45_count*LINK_COUNT(sub__V48); permitUnusedInt(sub__V48_count);
    CRSX_CHECK_SORT(sink__V44->context, sub__V48, &sort_M_Reified_xVariable); /* sub__V48 = &#1 */
    NamedPropertyLink namedP__V49 = LINK_NamedPropertyLink(sink__V44->context, NAMED_PROPERTIES(term__V45));
    VariablePropertyLink varP__V50 = LINK_VariablePropertyLink(sink__V44->context, VARIABLE_PROPERTIES(term__V45));
    UNLINK(sink__V44->context, term__V45);
    { START(sink__V44, _M__sTextNil); END(sink__V44, _M__sTextNil); } UNLINK_NamedPropertyLink(sink__V44->context, namedP__V49); UNLINK_VariablePropertyLink(sink__V44->context, varP__V50);
    return 1;
  } while (0);
  return 0;
}

#ifdef __cplusplus
}
#endif
/* END OF C RULES FOR CRSX CRSXC MODULE CD. */
