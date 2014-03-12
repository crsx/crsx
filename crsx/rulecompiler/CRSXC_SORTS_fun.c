/* C RULES FOR CRSX CRSXC MODULE SORTS. */
#include "CRSXC.h" 
#ifdef __cplusplus
extern "C" {
#endif

/* FUNCTION S-Data$1. */
int conBindOffs_M_S_Data_s1[] = {0 , 0 , 0 , 0};
char *nameFun_M_S_Data_s1(Term term) { return  "S-Data$1" ; }
struct _ConstructionDescriptor descriptor_M_S_Data_s1 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_S_Data_s1), conBindOffs_M_S_Data_s1, &nameFun_M_S_Data_s1, &step_M_S_Data_s1};

int step_M_S_Data_s1(Sink sink__V1, Term term__V2)
{
  int term__V2_count = LINK_COUNT(term__V2); permitUnusedInt(term__V2_count);
  do {
    /* Contraction rule SORTS-S-Data-1. */
    ASSERT(sink__V1->context, !strcmp(SYMBOL(term__V2),  "S-Data$1" ));
    Term sub__V3 = LINK(sink__V1->context, SUB(term__V2, 0)); int sub__V3_count = term__V2_count*LINK_COUNT(sub__V3); permitUnusedInt(sub__V3_count);
    UNLINK_SUB(sink__V1->context, term__V2,  0); NORMALIZE(sink__V1->context, sub__V3); SUB(term__V2,  0) = LINK(sink__V1->context, sub__V3);
    /* sub__V3 = &#11 */
    Term sub__V4 = SUB(term__V2, 1); permitUnusedTerm(sub__V4); int sub__V4_count = term__V2_count*LINK_COUNT(sub__V4); permitUnusedInt(sub__V4_count);
    /* sub__V4 = &#12 */
    Term sub__V5 = LINK(sink__V1->context, SUB(term__V2, 2)); int sub__V5_count = term__V2_count*LINK_COUNT(sub__V5); permitUnusedInt(sub__V5_count);
    UNLINK_SUB(sink__V1->context, term__V2,  2); NORMALIZE(sink__V1->context, sub__V5); SUB(term__V2,  2) = LINK(sink__V1->context, sub__V5);
    /* sub__V5 = &#2 */
    NamedPropertyLink namedP__V6 = LINK_NamedPropertyLink(sink__V1->context, NAMED_PROPERTIES(term__V2));
    VariablePropertyLink varP__V7 = LINK_VariablePropertyLink(sink__V1->context, VARIABLE_PROPERTIES(term__V2));
    UNLINK(sink__V1->context, term__V2);
    { START(sink__V1, _M__sTextCons);
      { START(sink__V1, _M__sTextBreak);
        LITERAL(sink__V1,  "\n" ); END(sink__V1, _M__sTextBreak); }
      { START(sink__V1, _M__sTextCons);
        { START(sink__V1, _M__sTextChars);
          LITERAL(sink__V1,  "/* SORT " ); END(sink__V1, _M__sTextChars); }
        { START(sink__V1, _M__sTextCons);
          { START(sink__V1, _M__sTextEmbed);
            { START(sink__V1, _M_AsText);
              { START(sink__V1, _M_TOKEN);
                COPY(sink__V1, LINK(sink__V1->context, sub__V3));END(sink__V1, _M_TOKEN); }
              END(sink__V1, _M_AsText); }
            END(sink__V1, _M__sTextEmbed); }
          { START(sink__V1, _M__sTextCons);
            { START(sink__V1, _M__sTextChars);
              LITERAL(sink__V1,  " CONSTANTS. */" ); END(sink__V1, _M__sTextChars); }
            { START(sink__V1, _M__sTextCons);
              { START(sink__V1, _M__sTextBreak);
                LITERAL(sink__V1,  "\n" ); END(sink__V1, _M__sTextBreak); }
              { START(sink__V1, _M__sTextCons);
                { START(sink__V1, _M__sTextEmbed);
                  { START(sink__V1, _M_AsText);
                    { START(sink__V1, _M_MapText_s1);
                      COPY(sink__V1, LINK(sink__V1->context, sub__V5));{ Variable x__V8 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V1->context,"x__V8");
                        Variable binds__V9[1] = {x__V8}; BINDS(sink__V1, 1, binds__V9);
                        { START(sink__V1, _M_S_Data_Form_s1);
                          USE(sink__V1, x__V8); COPY(sink__V1, LINK(sink__V1->context, sub__V3));END(sink__V1, _M_S_Data_Form_s1); }
                         }
                      END(sink__V1, _M_MapText_s1); }
                    END(sink__V1, _M_AsText); }
                  END(sink__V1, _M__sTextEmbed); }
                { START(sink__V1, _M__sTextCons);
                  { START(sink__V1, _M__sTextChars);
                    LITERAL(sink__V1,  "ConstructionDescriptor " ); END(sink__V1, _M__sTextChars); }
                  { START(sink__V1, _M__sTextCons);
                    { START(sink__V1, _M__sTextEmbed);
                      { START(sink__V1, _M_AsText);
                        { START(sink__V1, _M_SortCons);
                          COPY(sink__V1, LINK(sink__V1->context, sub__V3));END(sink__V1, _M_SortCons); }
                        END(sink__V1, _M_AsText); }
                      END(sink__V1, _M__sTextEmbed); }
                    { START(sink__V1, _M__sTextCons);
                      { START(sink__V1, _M__sTextChars);
                        LITERAL(sink__V1,  "[] = {NULL, NULL, " ); END(sink__V1, _M__sTextChars); }
                      { START(sink__V1, _M__sTextCons);
                        { START(sink__V1, _M__sTextEmbed);
                          { START(sink__V1, _M_AsText);
                            { START(sink__V1, _M_DelayMapText_s1);
                              { START(sink__V1, _M_Forms_Constructors);
                                COPY(sink__V1, LINK(sink__V1->context, sub__V5));END(sink__V1, _M_Forms_Constructors); }
                              { Variable x__V10 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V1->context,"x__V10");
                                Variable x__V11 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V1->context,"x__V11");
                                Variable binds__V12[2] = {x__V10,x__V11}; BINDS(sink__V1, 2, binds__V12);
                                { START(sink__V1, _M__sTextCons);
                                  { START(sink__V1, _M__sTextChars);
                                    LITERAL(sink__V1,  "&" ); END(sink__V1, _M__sTextChars); }
                                  { START(sink__V1, _M__sTextCons);
                                    { START(sink__V1, _M__sTextEmbed);
                                      { START(sink__V1, _M_AsText);
                                        { START(sink__V1, _M_DDescriptor);
                                          USE(sink__V1, x__V10); USE(sink__V1, x__V11); END(sink__V1, _M_DDescriptor); }
                                        END(sink__V1, _M_AsText); }
                                      END(sink__V1, _M__sTextEmbed); }
                                    { START(sink__V1, _M__sTextCons);
                                      { START(sink__V1, _M__sTextChars);
                                        LITERAL(sink__V1,  ", " ); END(sink__V1, _M__sTextChars); }
                                      { START(sink__V1, _M__sTextNil);
                                        END(sink__V1, _M__sTextNil); }
                                      END(sink__V1, _M__sTextCons); }
                                    END(sink__V1, _M__sTextCons); }
                                  END(sink__V1, _M__sTextCons); }
                                 }
                              END(sink__V1, _M_DelayMapText_s1); }
                            END(sink__V1, _M_AsText); }
                          END(sink__V1, _M__sTextEmbed); }
                        { START(sink__V1, _M__sTextCons);
                          { START(sink__V1, _M__sTextChars);
                            LITERAL(sink__V1,  " NULL};" ); END(sink__V1, _M__sTextChars); }
                          { START(sink__V1, _M__sTextCons);
                            { START(sink__V1, _M__sTextBreak);
                              LITERAL(sink__V1,  "\n" ); END(sink__V1, _M__sTextBreak); }
                            { START(sink__V1, _M__sTextCons);
                              { START(sink__V1, _M__sTextChars);
                                LITERAL(sink__V1,  "char *" ); END(sink__V1, _M__sTextChars); }
                              { START(sink__V1, _M__sTextCons);
                                { START(sink__V1, _M__sTextEmbed);
                                  { START(sink__V1, _M_AsText);
                                    { START(sink__V1, _M_SortNames);
                                      COPY(sink__V1, LINK(sink__V1->context, sub__V3));END(sink__V1, _M_SortNames); }
                                    END(sink__V1, _M_AsText); }
                                  END(sink__V1, _M__sTextEmbed); }
                                { START(sink__V1, _M__sTextCons);
                                  { START(sink__V1, _M__sTextChars);
                                    LITERAL(sink__V1,  "[] = {NULL, NULL, " );
                                    END(sink__V1, _M__sTextChars); }
                                  { START(sink__V1, _M__sTextCons);
                                    { START(sink__V1, _M__sTextEmbed);
                                      { START(sink__V1, _M_AsText);
                                        { START(sink__V1, _M_DelayMapText_s1);
                                          { START(sink__V1, _M_Forms_Constructors);
                                            COPY(sink__V1, LINK(sink__V1->context, sub__V5));END(sink__V1, _M_Forms_Constructors); }
                                          { Variable x__V13 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V1->context,"x__V13");
                                            Variable x__V14 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V1->context,"x__V14");
                                            Variable binds__V15[2] = {x__V13,x__V14}; BINDS(sink__V1, 2, binds__V15);
                                            { START(sink__V1, _M__sTextCons);
                                              { START(sink__V1, _M__sTextEmbed);
                                                { START(sink__V1, _M_AsText);
                                                  { START(sink__V1, _M_DSTRING);
                                                    USE(sink__V1, x__V13);
                                                    USE(sink__V1, x__V14);
                                                    END(sink__V1, _M_DSTRING); }
                                                  END(sink__V1, _M_AsText); }
                                                END(sink__V1, _M__sTextEmbed); }
                                              { START(sink__V1, _M__sTextCons);
                                                { START(sink__V1, _M__sTextChars);
                                                  LITERAL(sink__V1,  ", " );
                                                  END(sink__V1, _M__sTextChars); }
                                                { START(sink__V1, _M__sTextNil);
                                                  END(sink__V1, _M__sTextNil); }
                                                END(sink__V1, _M__sTextCons); }
                                              END(sink__V1, _M__sTextCons); }
                                             }
                                          END(sink__V1, _M_DelayMapText_s1); }
                                        END(sink__V1, _M_AsText); }
                                      END(sink__V1, _M__sTextEmbed); }
                                    { START(sink__V1, _M__sTextCons);
                                      { START(sink__V1, _M__sTextChars);
                                        LITERAL(sink__V1,  " NULL};" );
                                        END(sink__V1, _M__sTextChars); }
                                      { START(sink__V1, _M__sTextCons);
                                        { START(sink__V1, _M__sTextBreak);
                                          LITERAL(sink__V1,  "\n" ); END(sink__V1, _M__sTextBreak); }
                                        { START(sink__V1, _M__sTextCons);
                                          { START(sink__V1, _M__sTextChars);
                                            LITERAL(sink__V1,  "char *" );
                                            END(sink__V1, _M__sTextChars); }
                                          { START(sink__V1, _M__sTextCons);
                                            { START(sink__V1, _M__sTextEmbed);
                                              { START(sink__V1, _M_AsText);
                                                { START(sink__V1, _M_SortInternals);
                                                  COPY(sink__V1, LINK(sink__V1->context, sub__V3));END(sink__V1, _M_SortInternals); }
                                                END(sink__V1, _M_AsText); }
                                              END(sink__V1, _M__sTextEmbed); }
                                            { START(sink__V1, _M__sTextCons);
                                              { START(sink__V1, _M__sTextChars);
                                                LITERAL(sink__V1,  "[] = {NULL, NULL, " );
                                                END(sink__V1, _M__sTextChars); }
                                              { START(sink__V1, _M__sTextCons);
                                                { START(sink__V1, _M__sTextEmbed);
                                                  { START(sink__V1, _M_AsText);
                                                    { START(sink__V1, _M_DelayMapText_s1);
                                                      { START(sink__V1, _M_Forms_Constructors);
                                                        COPY(sink__V1, sub__V5);END(sink__V1, _M_Forms_Constructors); }
                                                      { Variable x__V16 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V1->context,"x__V16");
                                                        Variable x__V17 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V1->context,"x__V17");
                                                        Variable binds__V18[2] = {x__V16,x__V17}; BINDS(sink__V1, 2, binds__V18);
                                                        { START(sink__V1, _M__sTextCons);
                                                          { START(sink__V1, _M__sTextChars);
                                                            LITERAL(sink__V1,  "\"" );
                                                            END(sink__V1, _M__sTextChars); }
                                                          { START(sink__V1, _M__sTextCons);
                                                            { START(sink__V1, _M__sTextEmbed);
                                                              { START(sink__V1, _M_AsText);
                                                                { START(sink__V1, _M_DMANGLE);
                                                                  USE(sink__V1, x__V16);
                                                                  USE(sink__V1, x__V17);
                                                                  END(sink__V1, _M_DMANGLE); }
                                                                END(sink__V1, _M_AsText); }
                                                              END(sink__V1, _M__sTextEmbed); }
                                                            { START(sink__V1, _M__sTextCons);
                                                              { START(sink__V1, _M__sTextChars);
                                                                LITERAL(sink__V1,  "\", " );
                                                                END(sink__V1, _M__sTextChars); }
                                                              { START(sink__V1, _M__sTextNil);
                                                                END(sink__V1, _M__sTextNil); }
                                                              END(sink__V1, _M__sTextCons); }
                                                            END(sink__V1, _M__sTextCons); }
                                                          END(sink__V1, _M__sTextCons); }
                                                         }
                                                      END(sink__V1, _M_DelayMapText_s1); }
                                                    END(sink__V1, _M_AsText); }
                                                  END(sink__V1, _M__sTextEmbed); }
                                                { START(sink__V1, _M__sTextCons);
                                                  { START(sink__V1, _M__sTextChars);
                                                    LITERAL(sink__V1,  " NULL};" );
                                                    END(sink__V1, _M__sTextChars); }
                                                  { START(sink__V1, _M__sTextCons);
                                                    { START(sink__V1, _M__sTextBreak);
                                                      LITERAL(sink__V1,  "\n" );
                                                      END(sink__V1, _M__sTextBreak); }
                                                    { START(sink__V1, _M__sTextCons);
                                                      { START(sink__V1, _M__sTextChars);
                                                        LITERAL(sink__V1,  "struct _SortDescriptor " );
                                                        END(sink__V1, _M__sTextChars); }
                                                      { START(sink__V1, _M__sTextCons);
                                                        { START(sink__V1, _M__sTextEmbed);
                                                          { START(sink__V1, _M_AsText);
                                                            { START(sink__V1, _M_Sort);
                                                              COPY(sink__V1, LINK(sink__V1->context, sub__V3));END(sink__V1, _M_Sort); }
                                                            END(sink__V1, _M_AsText); }
                                                          END(sink__V1, _M__sTextEmbed); }
                                                        { START(sink__V1, _M__sTextCons);
                                                          { START(sink__V1, _M__sTextChars);
                                                            LITERAL(sink__V1,  " = {" );
                                                            END(sink__V1, _M__sTextChars); }
                                                          { START(sink__V1, _M__sTextCons);
                                                            { START(sink__V1, _M__sTextEmbed);
                                                              { START(sink__V1, _M_AsText);
                                                                { START(sink__V1, _M_STRING);
                                                                  COPY(sink__V1, LINK(sink__V1->context, sub__V3));END(sink__V1, _M_STRING); }
                                                                END(sink__V1, _M_AsText); }
                                                              END(sink__V1, _M__sTextEmbed); }
                                                            { START(sink__V1, _M__sTextCons);
                                                              { START(sink__V1, _M__sTextChars);
                                                                LITERAL(sink__V1,  ", " );
                                                                END(sink__V1, _M__sTextChars); }
                                                              { START(sink__V1, _M__sTextCons);
                                                                { START(sink__V1, _M__sTextEmbed);
                                                                  { START(sink__V1, _M_AsText);
                                                                    { START(sink__V1, _M_SortCons);
                                                                      COPY(sink__V1, LINK(sink__V1->context, sub__V3));END(sink__V1, _M_SortCons); }
                                                                    END(sink__V1, _M_AsText); }
                                                                  END(sink__V1, _M__sTextEmbed); }
                                                                { START(sink__V1, _M__sTextCons);
                                                                  { START(sink__V1, _M__sTextChars);
                                                                    LITERAL(sink__V1,  ", " );
                                                                    END(sink__V1, _M__sTextChars); }
                                                                  { START(sink__V1, _M__sTextCons);
                                                                    { START(sink__V1, _M__sTextEmbed);
                                                                      { START(sink__V1, _M_AsText);
                                                                        { START(sink__V1, _M_SortNames);
                                                                          COPY(sink__V1, LINK(sink__V1->context, sub__V3));END(sink__V1, _M_SortNames); }
                                                                        END(sink__V1, _M_AsText); }
                                                                      END(sink__V1, _M__sTextEmbed); }
                                                                    { START(sink__V1, _M__sTextCons);
                                                                      { START(sink__V1, _M__sTextChars);
                                                                        LITERAL(sink__V1,  ", " );
                                                                        END(sink__V1, _M__sTextChars); }
                                                                      { START(sink__V1, _M__sTextCons);
                                                                        { START(sink__V1, _M__sTextEmbed);
                                                                          { START(sink__V1, _M_AsText);
                                                                            { START(sink__V1, _M_SortInternals);
                                                                              COPY(sink__V1, sub__V3);END(sink__V1, _M_SortInternals); }
                                                                            END(sink__V1, _M_AsText); }
                                                                          END(sink__V1, _M__sTextEmbed); }
                                                                        { START(sink__V1, _M__sTextCons);
                                                                          { START(sink__V1, _M__sTextChars);
                                                                            LITERAL(sink__V1,  ", NULL};" );
                                                                            END(sink__V1, _M__sTextChars); }
                                                                          { START(sink__V1, _M__sTextCons);
                                                                            { START(sink__V1, _M__sTextBreak);
                                                                              LITERAL(sink__V1,  "\n" );
                                                                              END(sink__V1, _M__sTextBreak); }
                                                                            { START(sink__V1, _M__sTextNil);
                                                                              END(sink__V1, _M__sTextNil); }
                                                                            END(sink__V1, _M__sTextCons); }
                                                                          END(sink__V1, _M__sTextCons); }
                                                                        END(sink__V1, _M__sTextCons); }
                                                                      END(sink__V1, _M__sTextCons); }
                                                                    END(sink__V1, _M__sTextCons); }
                                                                  END(sink__V1, _M__sTextCons); }
                                                                END(sink__V1, _M__sTextCons); }
                                                              END(sink__V1, _M__sTextCons); }
                                                            END(sink__V1, _M__sTextCons); }
                                                          END(sink__V1, _M__sTextCons); }
                                                        END(sink__V1, _M__sTextCons); }
                                                      END(sink__V1, _M__sTextCons); }
                                                    END(sink__V1, _M__sTextCons); }
                                                  END(sink__V1, _M__sTextCons); }
                                                END(sink__V1, _M__sTextCons); }
                                              END(sink__V1, _M__sTextCons); }
                                            END(sink__V1, _M__sTextCons); }
                                          END(sink__V1, _M__sTextCons); }
                                        END(sink__V1, _M__sTextCons); }
                                      END(sink__V1, _M__sTextCons); }
                                    END(sink__V1, _M__sTextCons); }
                                  END(sink__V1, _M__sTextCons); }
                                END(sink__V1, _M__sTextCons); }
                              END(sink__V1, _M__sTextCons); }
                            END(sink__V1, _M__sTextCons); }
                          END(sink__V1, _M__sTextCons); }
                        END(sink__V1, _M__sTextCons); }
                      END(sink__V1, _M__sTextCons); }
                    END(sink__V1, _M__sTextCons); }
                  END(sink__V1, _M__sTextCons); }
                END(sink__V1, _M__sTextCons); }
              END(sink__V1, _M__sTextCons); }
            END(sink__V1, _M__sTextCons); }
          END(sink__V1, _M__sTextCons); }
        END(sink__V1, _M__sTextCons); }
      END(sink__V1, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V1->context, namedP__V6); UNLINK_VariablePropertyLink(sink__V1->context, varP__V7);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION S-Data$2. */
int conBindOffs_M_S_Data_s2[] = {0 , 0 , 0 , 0 , 0};
char *nameFun_M_S_Data_s2(Term term) { return  "S-Data$2" ; }
struct _ConstructionDescriptor descriptor_M_S_Data_s2 = {&sort_M_Reified_xVariable, 0, 4, sizeof(STRUCT_Con_M_S_Data_s2), conBindOffs_M_S_Data_s2, &nameFun_M_S_Data_s2, &step_M_S_Data_s2};

int step_M_S_Data_s2(Sink sink__V19, Term term__V20)
{
  int term__V20_count = LINK_COUNT(term__V20); permitUnusedInt(term__V20_count);
  do {
    /* Contraction rule SORTS-S-Data-2. */
    ASSERT(sink__V19->context, !strcmp(SYMBOL(term__V20),  "S-Data$2" ));
    Term sub__V21 = SUB(term__V20, 0); permitUnusedTerm(sub__V21); int sub__V21_count = term__V20_count*LINK_COUNT(sub__V21); permitUnusedInt(sub__V21_count);
    CRSX_CHECK_SORT(sink__V19->context, sub__V21, &sort_M_Reified_xSort); /* sub__V21 = &#11 */
    Term sub__V22 = SUB(term__V20, 1); permitUnusedTerm(sub__V22); int sub__V22_count = term__V20_count*LINK_COUNT(sub__V22); permitUnusedInt(sub__V22_count);
    CRSX_CHECK_SORT(sink__V19->context, sub__V22, &sort_M_Reified_xSort); /* sub__V22 = &#12 */
    Term sub__V23 = LINK(sink__V19->context, SUB(term__V20, 2)); int sub__V23_count = term__V20_count*LINK_COUNT(sub__V23); permitUnusedInt(sub__V23_count);
    CRSX_CHECK_SORT(sink__V19->context, sub__V23, &sort_M_Reified_xSort); /* sub__V23 = &#13 */
    Term sub__V24 = LINK(sink__V19->context, SUB(term__V20, 3)); int sub__V24_count = term__V20_count*LINK_COUNT(sub__V24); permitUnusedInt(sub__V24_count);
    /* sub__V24 = &#2 */
    NamedPropertyLink namedP__V25 = LINK_NamedPropertyLink(sink__V19->context, NAMED_PROPERTIES(term__V20));
    VariablePropertyLink varP__V26 = LINK_VariablePropertyLink(sink__V19->context, VARIABLE_PROPERTIES(term__V20));
    UNLINK(sink__V19->context, term__V20);
    { START(sink__V19, _M_S_Data);
      COPY(sink__V19, sub__V23);COPY(sink__V19, sub__V24);END(sink__V19, _M_S_Data); }
    UNLINK_NamedPropertyLink(sink__V19->context, namedP__V25); UNLINK_VariablePropertyLink(sink__V19->context, varP__V26);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION ComputeSorts$1. */
int conBindOffs_M_ComputeSorts_s1[] = {0 , 0 , 0};
char *nameFun_M_ComputeSorts_s1(Term term) { return  "ComputeSorts$1" ; }
struct _ConstructionDescriptor descriptor_M_ComputeSorts_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_ComputeSorts_s1), conBindOffs_M_ComputeSorts_s1, &nameFun_M_ComputeSorts_s1, &step_M_ComputeSorts_s1};

int step_M_ComputeSorts_s1(Sink sink__V27, Term term__V28)
{
  int term__V28_count = LINK_COUNT(term__V28); permitUnusedInt(term__V28_count);
  do {
    /* Contraction rule SORTS-Crsx. */
    ASSERT(sink__V27->context, !strcmp(SYMBOL(term__V28),  "ComputeSorts$1" ));
    Term sub__V29 = LINK(sink__V27->context, SUB(term__V28, 0)); int sub__V29_count = term__V28_count*LINK_COUNT(sub__V29); permitUnusedInt(sub__V29_count);
    UNLINK_SUB(sink__V27->context, term__V28,  0); NORMALIZE(sink__V27->context, sub__V29); SUB(term__V28,  0) = LINK(sink__V27->context, sub__V29);
    /* sub__V29 = &#11 */
    Term sub__V30 = LINK(sink__V27->context, SUB(term__V28, 1)); int sub__V30_count = term__V28_count*LINK_COUNT(sub__V30); permitUnusedInt(sub__V30_count);
    /* sub__V30 = &#12 */
    NamedPropertyLink namedP__V31 = LINK_NamedPropertyLink(sink__V27->context, NAMED_PROPERTIES(term__V28));
    VariablePropertyLink varP__V32 = LINK_VariablePropertyLink(sink__V27->context, VARIABLE_PROPERTIES(term__V28));
    UNLINK(sink__V27->context, term__V28);
    { START(sink__V27, _M__sTextCons);
      { START(sink__V27, _M__sTextChars);
        LITERAL(sink__V27,  "/* C SORT DESCRIPTORS FOR CRSX " ); END(sink__V27, _M__sTextChars); }
      { START(sink__V27, _M__sTextCons);
        { START(sink__V27, _M__sTextEmbed);
          { START(sink__V27, _M_AsText);
            { START(sink__V27, _M_TOKEN);
              COPY(sink__V27, LINK(sink__V27->context, sub__V29));END(sink__V27, _M_TOKEN); }
            END(sink__V27, _M_AsText); }
          END(sink__V27, _M__sTextEmbed); }
        { START(sink__V27, _M__sTextCons);
          { START(sink__V27, _M__sTextChars);
            LITERAL(sink__V27,  ". */" ); END(sink__V27, _M__sTextChars); }
          { START(sink__V27, _M__sTextCons);
            { START(sink__V27, _M__sTextBreak);
              LITERAL(sink__V27,  "\n" ); END(sink__V27, _M__sTextBreak); }
            { START(sink__V27, _M__sTextCons);
              { START(sink__V27, _M__sTextEmbed);
                { START(sink__V27, _M_AsText);
                  { START(sink__V27, _M_DelayMapText_s1);
                    {char* str__V33;{ Term term__V34;
                        { char *value__V35 = getenv( "HEADERS" );
                          if (value__V35) term__V34 = makeStringLiteral(sink__V27->context, value__V35);
                          else {term__V34 = makeStringLiteral(sink__V27->context,  "" );
                            }
                        }
                        str__V33 = SYMBOL(term__V34); UNLINK(sink__V27->context, term__V34); }
                      
                      char* regex__V36;
                      regex__V36 =  ";" ; SEND_SPLIT(str__V33, regex__V36, sink__V27);
                    }
                    { Variable x__V37 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V27->context,"x__V37");
                      Variable x__V38 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V27->context,"x__V38");
                      Variable binds__V39[2] = {x__V37,x__V38}; BINDS(sink__V27, 2, binds__V39);
                      { START(sink__V27, _M__sTextCons);
                        { START(sink__V27, _M__sTextChars);
                          LITERAL(sink__V27,  "#include \"" ); END(sink__V27, _M__sTextChars); }
                        { START(sink__V27, _M__sTextCons);
                          { START(sink__V27, _M__sTextEmbed);
                            { START(sink__V27, _M_AsText);
                              { START(sink__V27, _M_DTOKEN);
                                USE(sink__V27, x__V37); USE(sink__V27, x__V38); END(sink__V27, _M_DTOKEN); }
                              END(sink__V27, _M_AsText); }
                            END(sink__V27, _M__sTextEmbed); }
                          { START(sink__V27, _M__sTextCons);
                            { START(sink__V27, _M__sTextChars);
                              LITERAL(sink__V27,  "\"" ); END(sink__V27, _M__sTextChars); }
                            { START(sink__V27, _M__sTextCons);
                              { START(sink__V27, _M__sTextBreak);
                                LITERAL(sink__V27,  "\n" ); END(sink__V27, _M__sTextBreak); }
                              { START(sink__V27, _M__sTextNil);
                                END(sink__V27, _M__sTextNil); }
                              END(sink__V27, _M__sTextCons); }
                            END(sink__V27, _M__sTextCons); }
                          END(sink__V27, _M__sTextCons); }
                        END(sink__V27, _M__sTextCons); }
                       }
                    END(sink__V27, _M_DelayMapText_s1); }
                  END(sink__V27, _M_AsText); }
                END(sink__V27, _M__sTextEmbed); }
              { START(sink__V27, _M__sTextCons);
                { START(sink__V27, _M__sTextBreak);
                  LITERAL(sink__V27,  "\n" ); END(sink__V27, _M__sTextBreak); }
                { START(sink__V27, _M__sTextCons);
                  { START(sink__V27, _M__sTextChars);
                    LITERAL(sink__V27,  "#ifdef __cplusplus" ); END(sink__V27, _M__sTextChars); }
                  { START(sink__V27, _M__sTextCons);
                    { START(sink__V27, _M__sTextBreak);
                      LITERAL(sink__V27,  "\n" ); END(sink__V27, _M__sTextBreak); }
                    { START(sink__V27, _M__sTextCons);
                      { START(sink__V27, _M__sTextChars);
                        LITERAL(sink__V27,  "extern \"C\" {" ); END(sink__V27, _M__sTextChars); }
                      { START(sink__V27, _M__sTextCons);
                        { START(sink__V27, _M__sTextBreak);
                          LITERAL(sink__V27,  "\n" ); END(sink__V27, _M__sTextBreak); }
                        { START(sink__V27, _M__sTextCons);
                          { START(sink__V27, _M__sTextChars);
                            LITERAL(sink__V27,  "#endif" ); END(sink__V27, _M__sTextChars); }
                          { START(sink__V27, _M__sTextCons);
                            { START(sink__V27, _M__sTextBreak);
                              LITERAL(sink__V27,  "\n" ); END(sink__V27, _M__sTextBreak); }
                            { START(sink__V27, _M__sTextCons);
                              { START(sink__V27, _M__sTextEmbed);
                                { START(sink__V27, _M_AsText);
                                  { START(sink__V27, _M_MapText_s1);
                                    COPY(sink__V27, sub__V30);{ Variable x__V40 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V27->context,"x__V40");
                                      Variable binds__V41[1] = {x__V40}; BINDS(sink__V27, 1, binds__V41);
                                      { START(sink__V27, _M_S_Declaration);
                                        USE(sink__V27, x__V40); END(sink__V27, _M_S_Declaration); }
                                       }
                                    END(sink__V27, _M_MapText_s1); }
                                  END(sink__V27, _M_AsText); }
                                END(sink__V27, _M__sTextEmbed); }
                              { START(sink__V27, _M__sTextCons);
                                { START(sink__V27, _M__sTextBreak);
                                  LITERAL(sink__V27,  "\n" ); END(sink__V27, _M__sTextBreak); }
                                { START(sink__V27, _M__sTextCons);
                                  { START(sink__V27, _M__sTextChars);
                                    LITERAL(sink__V27,  "#ifdef __cplusplus" );
                                    END(sink__V27, _M__sTextChars); }
                                  { START(sink__V27, _M__sTextCons);
                                    { START(sink__V27, _M__sTextBreak);
                                      LITERAL(sink__V27,  "\n" ); END(sink__V27, _M__sTextBreak); }
                                    { START(sink__V27, _M__sTextCons);
                                      { START(sink__V27, _M__sTextChars);
                                        LITERAL(sink__V27,  "}" ); END(sink__V27, _M__sTextChars); }
                                      { START(sink__V27, _M__sTextCons);
                                        { START(sink__V27, _M__sTextBreak);
                                          LITERAL(sink__V27,  "\n" ); END(sink__V27, _M__sTextBreak); }
                                        { START(sink__V27, _M__sTextCons);
                                          { START(sink__V27, _M__sTextChars);
                                            LITERAL(sink__V27,  "#endif" );
                                            END(sink__V27, _M__sTextChars); }
                                          { START(sink__V27, _M__sTextCons);
                                            { START(sink__V27, _M__sTextBreak);
                                              LITERAL(sink__V27,  "\n" );
                                              END(sink__V27, _M__sTextBreak); }
                                            { START(sink__V27, _M__sTextCons);
                                              { START(sink__V27, _M__sTextChars);
                                                LITERAL(sink__V27,  "/* END OF C SORT DESCRIPTORS FOR CRSX " );
                                                END(sink__V27, _M__sTextChars); }
                                              { START(sink__V27, _M__sTextCons);
                                                { START(sink__V27, _M__sTextEmbed);
                                                  { START(sink__V27, _M_AsText);
                                                    { START(sink__V27, _M_TOKEN);
                                                      COPY(sink__V27, sub__V29);END(sink__V27, _M_TOKEN); }
                                                    END(sink__V27, _M_AsText); }
                                                  END(sink__V27, _M__sTextEmbed); }
                                                { START(sink__V27, _M__sTextCons);
                                                  { START(sink__V27, _M__sTextChars);
                                                    LITERAL(sink__V27,  ". */" );
                                                    END(sink__V27, _M__sTextChars); }
                                                  { START(sink__V27, _M__sTextCons);
                                                    { START(sink__V27, _M__sTextBreak);
                                                      LITERAL(sink__V27,  "\n" );
                                                      END(sink__V27, _M__sTextBreak); }
                                                    { START(sink__V27, _M__sTextNil);
                                                      END(sink__V27, _M__sTextNil); }
                                                    END(sink__V27, _M__sTextCons); }
                                                  END(sink__V27, _M__sTextCons); }
                                                END(sink__V27, _M__sTextCons); }
                                              END(sink__V27, _M__sTextCons); }
                                            END(sink__V27, _M__sTextCons); }
                                          END(sink__V27, _M__sTextCons); }
                                        END(sink__V27, _M__sTextCons); }
                                      END(sink__V27, _M__sTextCons); }
                                    END(sink__V27, _M__sTextCons); }
                                  END(sink__V27, _M__sTextCons); }
                                END(sink__V27, _M__sTextCons); }
                              END(sink__V27, _M__sTextCons); }
                            END(sink__V27, _M__sTextCons); }
                          END(sink__V27, _M__sTextCons); }
                        END(sink__V27, _M__sTextCons); }
                      END(sink__V27, _M__sTextCons); }
                    END(sink__V27, _M__sTextCons); }
                  END(sink__V27, _M__sTextCons); }
                END(sink__V27, _M__sTextCons); }
              END(sink__V27, _M__sTextCons); }
            END(sink__V27, _M__sTextCons); }
          END(sink__V27, _M__sTextCons); }
        END(sink__V27, _M__sTextCons); }
      END(sink__V27, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V27->context, namedP__V31); UNLINK_VariablePropertyLink(sink__V27->context, varP__V32);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION S-Declaration. */
int conBindOffs_M_S_Declaration[] = {0 , 0};
char *nameFun_M_S_Declaration(Term term) { return  "S-Declaration" ; }
struct _ConstructionDescriptor descriptor_M_S_Declaration = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_S_Declaration), conBindOffs_M_S_Declaration, &nameFun_M_S_Declaration, &step_M_S_Declaration};

int step_M_S_Declaration(Sink sink__V42, Term term__V43)
{
  int term__V43_count = LINK_COUNT(term__V43); permitUnusedInt(term__V43_count);
  Term sub__V44 = FORCE(sink__V42->context, SUB(term__V43, 0));
  EnumOf_M_Reified_xDeclaration choice__V45 = (IS_VARIABLE_USE(sub__V44) ? VarOf_M_Reified_xDeclaration : (EnumOf_M_Reified_xDeclaration) TAG(sub__V44));
  switch (choice__V45)
  {
    case Data_M_DATA: { /* Function SORTS-Data$S-Declaration$DATA case DATA */
      ASSERT(sink__V42->context, !strcmp(SYMBOL(term__V43),  "S-Declaration" ));
      Term sub__V46 = SUB(term__V43, 0); permitUnusedTerm(sub__V46); int sub__V46_count = term__V43_count*LINK_COUNT(sub__V46); permitUnusedInt(sub__V46_count);
      CRSX_CHECK_SORT(sink__V42->context, sub__V46, &sort_M_Reified_xDeclaration); ASSERT(sink__V42->context, !strcmp(SYMBOL(sub__V46),  "DATA" ));
      Term sub__V47 = LINK(sink__V42->context, SUB(sub__V46, 0)); int sub__V47_count = sub__V46_count*LINK_COUNT(sub__V47); permitUnusedInt(sub__V47_count);
      CRSX_CHECK_SORT(sink__V42->context, sub__V47, &sort_M_Reified_xSort); /* sub__V47 = &#0-0 */
      Term sub__V48 = LINK(sink__V42->context, SUB(sub__V46, 1)); int sub__V48_count = sub__V46_count*LINK_COUNT(sub__V48); permitUnusedInt(sub__V48_count);
      /* sub__V48 = &#0-1 */
      NamedPropertyLink namedP__V49 = LINK_NamedPropertyLink(sink__V42->context, NAMED_PROPERTIES(term__V43));
      VariablePropertyLink varP__V50 = LINK_VariablePropertyLink(sink__V42->context, VARIABLE_PROPERTIES(term__V43));
      UNLINK(sink__V42->context, term__V43);
      ADD_PROPERTIES(sink__V42, LINK_NamedPropertyLink(sink__V42->context, namedP__V49), LINK_VariablePropertyLink(sink__V42->context, varP__V50));
      { START(sink__V42, _M_S_Declaration_s1);
        COPY(sink__V42, sub__V47);COPY(sink__V42, sub__V48);END(sink__V42, _M_S_Declaration_s1); }
      UNLINK_NamedPropertyLink(sink__V42->context, namedP__V49); UNLINK_VariablePropertyLink(sink__V42->context, varP__V50);
      
      return 1;
    break; } case Data_M_FUNCTION: { /* Function SORTS-Function$S-Declaration$FUNCTION case FUNCTION */
      ASSERT(sink__V42->context, !strcmp(SYMBOL(term__V43),  "S-Declaration" ));
      Term sub__V51 = SUB(term__V43, 0); permitUnusedTerm(sub__V51); int sub__V51_count = term__V43_count*LINK_COUNT(sub__V51); permitUnusedInt(sub__V51_count);
      CRSX_CHECK_SORT(sink__V42->context, sub__V51, &sort_M_Reified_xDeclaration); ASSERT(sink__V42->context, !strcmp(SYMBOL(sub__V51),  "FUNCTION" ));
      Term sub__V52 = LINK(sink__V42->context, SUB(sub__V51, 0)); int sub__V52_count = sub__V51_count*LINK_COUNT(sub__V52); permitUnusedInt(sub__V52_count);
      /* sub__V52 = &#0-0 */
      Term sub__V53 = LINK(sink__V42->context, SUB(sub__V51, 1)); int sub__V53_count = sub__V51_count*LINK_COUNT(sub__V53); permitUnusedInt(sub__V53_count);
      /* sub__V53 = &#0-1 */
      Term sub__V54 = LINK(sink__V42->context, SUB(sub__V51, 2)); int sub__V54_count = sub__V51_count*LINK_COUNT(sub__V54); permitUnusedInt(sub__V54_count);
      /* sub__V54 = &#0-2 */
      Term sub__V55 = LINK(sink__V42->context, SUB(sub__V51, 3)); int sub__V55_count = sub__V51_count*LINK_COUNT(sub__V55); permitUnusedInt(sub__V55_count);
      /* sub__V55 = &#0-3 */
      Term sub__V56 = LINK(sink__V42->context, SUB(sub__V51, 4)); int sub__V56_count = sub__V51_count*LINK_COUNT(sub__V56); permitUnusedInt(sub__V56_count);
      /* sub__V56 = &#0-4 */
      Term sub__V57 = LINK(sink__V42->context, SUB(sub__V51, 5)); int sub__V57_count = sub__V51_count*LINK_COUNT(sub__V57); permitUnusedInt(sub__V57_count);
      CRSX_CHECK_SORT(sink__V42->context, sub__V57, &sort_M_Reified_xSort); /* sub__V57 = &#0-5 */
      Term sub__V58 = LINK(sink__V42->context, SUB(sub__V51, 6)); int sub__V58_count = sub__V51_count*LINK_COUNT(sub__V58); permitUnusedInt(sub__V58_count);
      /* sub__V58 = &#0-6 */
      NamedPropertyLink namedP__V59 = LINK_NamedPropertyLink(sink__V42->context, NAMED_PROPERTIES(term__V43));
      VariablePropertyLink varP__V60 = LINK_VariablePropertyLink(sink__V42->context, VARIABLE_PROPERTIES(term__V43));
      UNLINK(sink__V42->context, term__V43);
      ADD_PROPERTIES(sink__V42, LINK_NamedPropertyLink(sink__V42->context, namedP__V59), LINK_VariablePropertyLink(sink__V42->context, varP__V60));
      { START(sink__V42, _M_S_Declaration_s2);
        COPY(sink__V42, sub__V52);COPY(sink__V42, sub__V53);COPY(sink__V42, sub__V54);COPY(sink__V42, sub__V55);COPY(sink__V42, sub__V56);COPY(sink__V42, sub__V57);COPY(sink__V42, sub__V58);END(sink__V42, _M_S_Declaration_s2); }
      UNLINK_NamedPropertyLink(sink__V42->context, namedP__V59); UNLINK_VariablePropertyLink(sink__V42->context, varP__V60);
      
      return 1;
    break; } case Data_M_POLYMORPHIC: { /* Function SORTS-Polymorphic$S-Declaration$POLYMORPHIC case POLYMORPHIC */
      ASSERT(sink__V42->context, !strcmp(SYMBOL(term__V43),  "S-Declaration" ));
      Term sub__V61 = SUB(term__V43, 0); permitUnusedTerm(sub__V61); int sub__V61_count = term__V43_count*LINK_COUNT(sub__V61); permitUnusedInt(sub__V61_count);
      CRSX_CHECK_SORT(sink__V42->context, sub__V61, &sort_M_Reified_xDeclaration); ASSERT(sink__V42->context, !strcmp(SYMBOL(sub__V61),  "POLYMORPHIC" ));
      Variable y__V62 = BINDER(sub__V61,0,0); if (sub__V61_count <= 1) UNBIND(y__V62);
      Term sub__V63 = LINK(sink__V42->context, SUB(sub__V61, 0)); int sub__V63_count = sub__V61_count*LINK_COUNT(sub__V63); permitUnusedInt(sub__V63_count);
      CRSX_CHECK_SORT(sink__V42->context, sub__V63, &sort_M_Reified_xDeclaration); /* sub__V63 = &#0-0 */
      NamedPropertyLink namedP__V64 = LINK_NamedPropertyLink(sink__V42->context, NAMED_PROPERTIES(term__V43));
      VariablePropertyLink varP__V65 = LINK_VariablePropertyLink(sink__V42->context, VARIABLE_PROPERTIES(term__V43));
      UNLINK(sink__V42->context, term__V43);
      ADD_PROPERTIES(sink__V42, LINK_NamedPropertyLink(sink__V42->context, namedP__V64), LINK_VariablePropertyLink(sink__V42->context, varP__V65));
      { START(sink__V42, _M_S_Declaration_s3);
        { if (!IS_BOUND(y__V62)) { REBIND(y__V62);
            Variable binds__V66[1] = {y__V62}; BINDS(sink__V42, 1, binds__V66);
            COPY(sink__V42, sub__V63); /* REUSED SUBSTITUTION */  }
          else { Variable b__V67 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V42->context,"b__V67");
            Variable binds__V68[1] = {b__V67}; BINDS(sink__V42, 1, binds__V68);
            {
              Term arg__V69;
              { Sink buf__V70 = ALLOCA_BUFFER(sink__V42->context);
                USE(buf__V70, b__V67); arg__V69 = BUFFER_TERM(buf__V70); FREE_BUFFER(buf__V70); }
              Variable vars__V71[1] = {y__V62};
              Term args__V72[1] = {arg__V69};
              struct _SubstitutionFrame substitution__V73 = {NULL, 0, 1, vars__V71, args__V72, NULL};
              SUBSTITUTE(sink__V42, sub__V63, &substitution__V73); }
                }
           }
        END(sink__V42, _M_S_Declaration_s3); }
      UNLINK_NamedPropertyLink(sink__V42->context, namedP__V64); UNLINK_VariablePropertyLink(sink__V42->context, varP__V65);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION S-Declaration$3. */
int conBindOffs_M_S_Declaration_s3[] = {0 , 1};
char *nameFun_M_S_Declaration_s3(Term term) { return  "S-Declaration$3" ; }
struct _ConstructionDescriptor descriptor_M_S_Declaration_s3 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_S_Declaration_s3), conBindOffs_M_S_Declaration_s3, &nameFun_M_S_Declaration_s3, &step_M_S_Declaration_s3};

int step_M_S_Declaration_s3(Sink sink__V74, Term term__V75)
{
  int term__V75_count = LINK_COUNT(term__V75); permitUnusedInt(term__V75_count);
  do {
    /* Contraction rule SORTS-Polymorphic. */
    ASSERT(sink__V74->context, !strcmp(SYMBOL(term__V75),  "S-Declaration$3" ));
    Variable x__V76 = BINDER(term__V75,0,0); if (term__V75_count <= 1) UNBIND(x__V76);
    Term sub__V77 = LINK(sink__V74->context, SUB(term__V75, 0)); int sub__V77_count = term__V75_count*LINK_COUNT(sub__V77); permitUnusedInt(sub__V77_count);
    CRSX_CHECK_SORT(sink__V74->context, sub__V77, &sort_M_Reified_xDeclaration); /* sub__V77 = &#11 */
    Variable y__V78 = x__V76; permitUnusedVariable(y__V78);
    NamedPropertyLink namedP__V79 = LINK_NamedPropertyLink(sink__V74->context, NAMED_PROPERTIES(term__V75));
    VariablePropertyLink varP__V80 = LINK_VariablePropertyLink(sink__V74->context, VARIABLE_PROPERTIES(term__V75));
    UNLINK(sink__V74->context, term__V75);
    { START(sink__V74, _M_S_Declaration);
      COPY(sink__V74, sub__V77); /* REUSED SUBSTITUTION */ END(sink__V74, _M_S_Declaration); }
    UNLINK_NamedPropertyLink(sink__V74->context, namedP__V79); UNLINK_VariablePropertyLink(sink__V74->context, varP__V80);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION S-Declaration$2. */
int conBindOffs_M_S_Declaration_s2[] = {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0};
char *nameFun_M_S_Declaration_s2(Term term) { return  "S-Declaration$2" ; }
struct _ConstructionDescriptor descriptor_M_S_Declaration_s2 = {&sort_M_Reified_xVariable, 0, 7, sizeof(STRUCT_Con_M_S_Declaration_s2), conBindOffs_M_S_Declaration_s2, &nameFun_M_S_Declaration_s2, &step_M_S_Declaration_s2};

int step_M_S_Declaration_s2(Sink sink__V81, Term term__V82)
{
  int term__V82_count = LINK_COUNT(term__V82); permitUnusedInt(term__V82_count);
  do {
    /* Contraction rule SORTS-Function. */
    ASSERT(sink__V81->context, !strcmp(SYMBOL(term__V82),  "S-Declaration$2" ));
    Term sub__V83 = SUB(term__V82, 0); permitUnusedTerm(sub__V83); int sub__V83_count = term__V82_count*LINK_COUNT(sub__V83); permitUnusedInt(sub__V83_count);
    /* sub__V83 = &#11 */
    Term sub__V84 = SUB(term__V82, 1); permitUnusedTerm(sub__V84); int sub__V84_count = term__V82_count*LINK_COUNT(sub__V84); permitUnusedInt(sub__V84_count);
    /* sub__V84 = &#12 */
    Term sub__V85 = SUB(term__V82, 2); permitUnusedTerm(sub__V85); int sub__V85_count = term__V82_count*LINK_COUNT(sub__V85); permitUnusedInt(sub__V85_count);
    /* sub__V85 = &#13 */
    Term sub__V86 = SUB(term__V82, 3); permitUnusedTerm(sub__V86); int sub__V86_count = term__V82_count*LINK_COUNT(sub__V86); permitUnusedInt(sub__V86_count);
    /* sub__V86 = &#14 */
    Term sub__V87 = SUB(term__V82, 4); permitUnusedTerm(sub__V87); int sub__V87_count = term__V82_count*LINK_COUNT(sub__V87); permitUnusedInt(sub__V87_count);
    /* sub__V87 = &#15 */
    Term sub__V88 = SUB(term__V82, 5); permitUnusedTerm(sub__V88); int sub__V88_count = term__V82_count*LINK_COUNT(sub__V88); permitUnusedInt(sub__V88_count);
    CRSX_CHECK_SORT(sink__V81->context, sub__V88, &sort_M_Reified_xSort); /* sub__V88 = &#16 */
    Term sub__V89 = SUB(term__V82, 6); permitUnusedTerm(sub__V89); int sub__V89_count = term__V82_count*LINK_COUNT(sub__V89); permitUnusedInt(sub__V89_count);
    /* sub__V89 = &#17 */
    NamedPropertyLink namedP__V90 = LINK_NamedPropertyLink(sink__V81->context, NAMED_PROPERTIES(term__V82));
    VariablePropertyLink varP__V91 = LINK_VariablePropertyLink(sink__V81->context, VARIABLE_PROPERTIES(term__V82));
    UNLINK(sink__V81->context, term__V82);
    { START(sink__V81, _M__sTextNil); END(sink__V81, _M__sTextNil); } UNLINK_NamedPropertyLink(sink__V81->context, namedP__V90); UNLINK_VariablePropertyLink(sink__V81->context, varP__V91);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION S-Declaration$1. */
int conBindOffs_M_S_Declaration_s1[] = {0 , 0 , 0};
char *nameFun_M_S_Declaration_s1(Term term) { return  "S-Declaration$1" ; }
struct _ConstructionDescriptor descriptor_M_S_Declaration_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_S_Declaration_s1), conBindOffs_M_S_Declaration_s1, &nameFun_M_S_Declaration_s1, &step_M_S_Declaration_s1};

int step_M_S_Declaration_s1(Sink sink__V92, Term term__V93)
{
  int term__V93_count = LINK_COUNT(term__V93); permitUnusedInt(term__V93_count);
  do {
    /* Contraction rule SORTS-Data. */
    ASSERT(sink__V92->context, !strcmp(SYMBOL(term__V93),  "S-Declaration$1" ));
    Term sub__V94 = LINK(sink__V92->context, SUB(term__V93, 0)); int sub__V94_count = term__V93_count*LINK_COUNT(sub__V94); permitUnusedInt(sub__V94_count);
    CRSX_CHECK_SORT(sink__V92->context, sub__V94, &sort_M_Reified_xSort); /* sub__V94 = &#11 */
    Term sub__V95 = LINK(sink__V92->context, SUB(term__V93, 1)); int sub__V95_count = term__V93_count*LINK_COUNT(sub__V95); permitUnusedInt(sub__V95_count);
    /* sub__V95 = &#12 */
    NamedPropertyLink namedP__V96 = LINK_NamedPropertyLink(sink__V92->context, NAMED_PROPERTIES(term__V93));
    VariablePropertyLink varP__V97 = LINK_VariablePropertyLink(sink__V92->context, VARIABLE_PROPERTIES(term__V93));
    UNLINK(sink__V92->context, term__V93);
    { START(sink__V92, _M_S_Data);
      COPY(sink__V92, sub__V94);COPY(sink__V92, sub__V95);END(sink__V92, _M_S_Data); }
    UNLINK_NamedPropertyLink(sink__V92->context, namedP__V96); UNLINK_VariablePropertyLink(sink__V92->context, varP__V97);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION S-Data-Form$7. */
int conBindOffs_M_S_Data_Form_s7[] = {0 , 0 , 0 , 0 , 0};
char *nameFun_M_S_Data_Form_s7(Term term) { return  "S-Data-Form$7" ; }
struct _ConstructionDescriptor descriptor_M_S_Data_Form_s7 = {&sort_M_Reified_xVariable, 0, 4, sizeof(STRUCT_Con_M_S_Data_Form_s7), conBindOffs_M_S_Data_Form_s7, &nameFun_M_S_Data_Form_s7, &step_M_S_Data_Form_s7};

int step_M_S_Data_Form_s7(Sink sink__V98, Term term__V99)
{
  int term__V99_count = LINK_COUNT(term__V99); permitUnusedInt(term__V99_count);
  do {
    /* Contraction rule SORTS-S-Data-Form-1. */
    ASSERT(sink__V98->context, !strcmp(SYMBOL(term__V99),  "S-Data-Form$7" ));
    Term sub__V100 = SUB(term__V99, 0); permitUnusedTerm(sub__V100); int sub__V100_count = term__V99_count*LINK_COUNT(sub__V100); permitUnusedInt(sub__V100_count);
    CRSX_CHECK_SORT(sink__V98->context, sub__V100, &sort_M_Reified_xSort); /* sub__V100 = &#21 */
    Term sub__V101 = SUB(term__V99, 1); permitUnusedTerm(sub__V101); int sub__V101_count = term__V99_count*LINK_COUNT(sub__V101); permitUnusedInt(sub__V101_count);
    CRSX_CHECK_SORT(sink__V98->context, sub__V101, &sort_M_Reified_xSort); /* sub__V101 = &#22 */
    Term sub__V102 = LINK(sink__V98->context, SUB(term__V99, 2)); int sub__V102_count = term__V99_count*LINK_COUNT(sub__V102); permitUnusedInt(sub__V102_count);
    CRSX_CHECK_SORT(sink__V98->context, sub__V102, &sort_M_Reified_xForm); /* sub__V102 = &#23 */
    Term sub__V103 = LINK(sink__V98->context, SUB(term__V99, 3)); int sub__V103_count = term__V99_count*LINK_COUNT(sub__V103); permitUnusedInt(sub__V103_count);
    /* sub__V103 = &#1 */
    NamedPropertyLink namedP__V104 = LINK_NamedPropertyLink(sink__V98->context, NAMED_PROPERTIES(term__V99));
    VariablePropertyLink varP__V105 = LINK_VariablePropertyLink(sink__V98->context, VARIABLE_PROPERTIES(term__V99));
    UNLINK(sink__V98->context, term__V99);
    { START(sink__V98, _M_S_Data_Form_s1);
      COPY(sink__V98, sub__V102);COPY(sink__V98, sub__V103);END(sink__V98, _M_S_Data_Form_s1); }
    UNLINK_NamedPropertyLink(sink__V98->context, namedP__V104); UNLINK_VariablePropertyLink(sink__V98->context, varP__V105);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION S-Data-Form$5. */
int conBindOffs_M_S_Data_Form_s5[] = {0 , 0 , 0};
char *nameFun_M_S_Data_Form_s5(Term term) { return  "S-Data-Form$5" ; }
struct _ConstructionDescriptor descriptor_M_S_Data_Form_s5 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_S_Data_Form_s5), conBindOffs_M_S_Data_Form_s5, &nameFun_M_S_Data_Form_s5, &step_M_S_Data_Form_s5};

int step_M_S_Data_Form_s5(Sink sink__V106, Term term__V107)
{
  int term__V107_count = LINK_COUNT(term__V107); permitUnusedInt(term__V107_count);
  do {
    /* Contraction rule SORTS-S-Data-Form-3. */
    ASSERT(sink__V106->context, !strcmp(SYMBOL(term__V107),  "S-Data-Form$5" ));
    Term sub__V108 = LINK(sink__V106->context, SUB(term__V107, 0)); int sub__V108_count = term__V107_count*LINK_COUNT(sub__V108); permitUnusedInt(sub__V108_count);
    UNLINK_SUB(sink__V106->context, term__V107,  0); NORMALIZE(sink__V106->context, sub__V108); SUB(term__V107,  0) = LINK(sink__V106->context, sub__V108);
    /* sub__V108 = &#21 */
    Term sub__V109 = LINK(sink__V106->context, SUB(term__V107, 1)); int sub__V109_count = term__V107_count*LINK_COUNT(sub__V109); permitUnusedInt(sub__V109_count);
    /* sub__V109 = &#1 */
    NamedPropertyLink namedP__V110 = LINK_NamedPropertyLink(sink__V106->context, NAMED_PROPERTIES(term__V107));
    VariablePropertyLink varP__V111 = LINK_VariablePropertyLink(sink__V106->context, VARIABLE_PROPERTIES(term__V107));
    UNLINK(sink__V106->context, term__V107);
    { START(sink__V106, _M__sTextCons);
      { START(sink__V106, _M__sTextChars);
        LITERAL(sink__V106,  "char *" ); END(sink__V106, _M__sTextChars); }
      { START(sink__V106, _M__sTextCons);
        { START(sink__V106, _M__sTextEmbed);
          { START(sink__V106, _M_AsText);
            { START(sink__V106, _M_Name);
              COPY(sink__V106, LINK(sink__V106->context, sub__V108));END(sink__V106, _M_Name); }
            END(sink__V106, _M_AsText); }
          END(sink__V106, _M__sTextEmbed); }
        { START(sink__V106, _M__sTextCons);
          { START(sink__V106, _M__sTextChars);
            LITERAL(sink__V106,  " = " ); END(sink__V106, _M__sTextChars); }
          { START(sink__V106, _M__sTextCons);
            { START(sink__V106, _M__sTextEmbed);
              { START(sink__V106, _M_AsText);
                { START(sink__V106, _M_STRING);
                  COPY(sink__V106, LINK(sink__V106->context, sub__V108));END(sink__V106, _M_STRING); }
                END(sink__V106, _M_AsText); }
              END(sink__V106, _M__sTextEmbed); }
            { START(sink__V106, _M__sTextCons);
              { START(sink__V106, _M__sTextChars);
                LITERAL(sink__V106,  ";" ); END(sink__V106, _M__sTextChars); }
              { START(sink__V106, _M__sTextCons);
                { START(sink__V106, _M__sTextBreak);
                  LITERAL(sink__V106,  "\n" ); END(sink__V106, _M__sTextBreak); }
                { START(sink__V106, _M__sTextCons);
                  { START(sink__V106, _M__sTextChars);
                    LITERAL(sink__V106,  "char *" ); END(sink__V106, _M__sTextChars); }
                  { START(sink__V106, _M__sTextCons);
                    { START(sink__V106, _M__sTextEmbed);
                      { START(sink__V106, _M_AsText);
                        { START(sink__V106, _M_NameFun);
                          COPY(sink__V106, LINK(sink__V106->context, sub__V108));END(sink__V106, _M_NameFun); }
                        END(sink__V106, _M_AsText); }
                      END(sink__V106, _M__sTextEmbed); }
                    { START(sink__V106, _M__sTextCons);
                      { START(sink__V106, _M__sTextChars);
                        LITERAL(sink__V106,  "(Term term) { return " );
                        END(sink__V106, _M__sTextChars); }
                      { START(sink__V106, _M__sTextCons);
                        { START(sink__V106, _M__sTextEmbed);
                          { START(sink__V106, _M_AsText);
                            { START(sink__V106, _M_Name);
                              COPY(sink__V106, LINK(sink__V106->context, sub__V108));END(sink__V106, _M_Name); }
                            END(sink__V106, _M_AsText); }
                          END(sink__V106, _M__sTextEmbed); }
                        { START(sink__V106, _M__sTextCons);
                          { START(sink__V106, _M__sTextChars);
                            LITERAL(sink__V106,  "; }" ); END(sink__V106, _M__sTextChars); }
                          { START(sink__V106, _M__sTextCons);
                            { START(sink__V106, _M__sTextBreak);
                              LITERAL(sink__V106,  "\n" ); END(sink__V106, _M__sTextBreak); }
                            { START(sink__V106, _M__sTextCons);
                              { START(sink__V106, _M__sTextChars);
                                LITERAL(sink__V106,  "struct _ConstructionDescriptor " );
                                END(sink__V106, _M__sTextChars); }
                              { START(sink__V106, _M__sTextCons);
                                { START(sink__V106, _M__sTextEmbed);
                                  { START(sink__V106, _M_AsText);
                                    { START(sink__V106, _M_Descriptor);
                                      COPY(sink__V106, LINK(sink__V106->context, sub__V108));END(sink__V106, _M_Descriptor); }
                                    END(sink__V106, _M_AsText); }
                                  END(sink__V106, _M__sTextEmbed); }
                                { START(sink__V106, _M__sTextCons);
                                  { START(sink__V106, _M__sTextChars);
                                    LITERAL(sink__V106,  " = {&" ); END(sink__V106, _M__sTextChars); }
                                  { START(sink__V106, _M__sTextCons);
                                    { START(sink__V106, _M__sTextEmbed);
                                      { START(sink__V106, _M_AsText);
                                        { START(sink__V106, _M_Sort);
                                          COPY(sink__V106, sub__V109);END(sink__V106, _M_Sort); }
                                        END(sink__V106, _M_AsText); }
                                      END(sink__V106, _M__sTextEmbed); }
                                    { START(sink__V106, _M__sTextCons);
                                      { START(sink__V106, _M__sTextChars);
                                        LITERAL(sink__V106,  ", " ); END(sink__V106, _M__sTextChars); }
                                      { START(sink__V106, _M__sTextCons);
                                        { START(sink__V106, _M__sTextEmbed);
                                          { START(sink__V106, _M_AsText);
                                            { START(sink__V106, _M_EnumTag);
                                              COPY(sink__V106, LINK(sink__V106->context, sub__V108));END(sink__V106, _M_EnumTag); }
                                            END(sink__V106, _M_AsText); }
                                          END(sink__V106, _M__sTextEmbed); }
                                        { START(sink__V106, _M__sTextCons);
                                          { START(sink__V106, _M__sTextChars);
                                            LITERAL(sink__V106,  ", 0, sizeof(STRUCT" );
                                            END(sink__V106, _M__sTextChars); }
                                          { START(sink__V106, _M__sTextCons);
                                            { START(sink__V106, _M__sTextEmbed);
                                              { START(sink__V106, _M_AsText);
                                                { START(sink__V106, _M_Struct);
                                                  COPY(sink__V106, LINK(sink__V106->context, sub__V108));END(sink__V106, _M_Struct); }
                                                END(sink__V106, _M_AsText); }
                                              END(sink__V106, _M__sTextEmbed); }
                                            { START(sink__V106, _M__sTextCons);
                                              { START(sink__V106, _M__sTextChars);
                                                LITERAL(sink__V106,  "), noBinderOffsets, &" );
                                                END(sink__V106, _M__sTextChars); }
                                              { START(sink__V106, _M__sTextCons);
                                                { START(sink__V106, _M__sTextEmbed);
                                                  { START(sink__V106, _M_AsText);
                                                    { START(sink__V106, _M_NameFun);
                                                      COPY(sink__V106, sub__V108);END(sink__V106, _M_NameFun); }
                                                    END(sink__V106, _M_AsText); }
                                                  END(sink__V106, _M__sTextEmbed); }
                                                { START(sink__V106, _M__sTextCons);
                                                  { START(sink__V106, _M__sTextChars);
                                                    LITERAL(sink__V106,  ", &dataStep};" );
                                                    END(sink__V106, _M__sTextChars); }
                                                  { START(sink__V106, _M__sTextCons);
                                                    { START(sink__V106, _M__sTextBreak);
                                                      LITERAL(sink__V106,  "\n" );
                                                      END(sink__V106, _M__sTextBreak); }
                                                    { START(sink__V106, _M__sTextNil);
                                                      END(sink__V106, _M__sTextNil); }
                                                    END(sink__V106, _M__sTextCons); }
                                                  END(sink__V106, _M__sTextCons); }
                                                END(sink__V106, _M__sTextCons); }
                                              END(sink__V106, _M__sTextCons); }
                                            END(sink__V106, _M__sTextCons); }
                                          END(sink__V106, _M__sTextCons); }
                                        END(sink__V106, _M__sTextCons); }
                                      END(sink__V106, _M__sTextCons); }
                                    END(sink__V106, _M__sTextCons); }
                                  END(sink__V106, _M__sTextCons); }
                                END(sink__V106, _M__sTextCons); }
                              END(sink__V106, _M__sTextCons); }
                            END(sink__V106, _M__sTextCons); }
                          END(sink__V106, _M__sTextCons); }
                        END(sink__V106, _M__sTextCons); }
                      END(sink__V106, _M__sTextCons); }
                    END(sink__V106, _M__sTextCons); }
                  END(sink__V106, _M__sTextCons); }
                END(sink__V106, _M__sTextCons); }
              END(sink__V106, _M__sTextCons); }
            END(sink__V106, _M__sTextCons); }
          END(sink__V106, _M__sTextCons); }
        END(sink__V106, _M__sTextCons); }
      END(sink__V106, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V106->context, namedP__V110); UNLINK_VariablePropertyLink(sink__V106->context, varP__V111);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION S-Data-Form$6. */
int conBindOffs_M_S_Data_Form_s6[] = {0 , 0};
char *nameFun_M_S_Data_Form_s6(Term term) { return  "S-Data-Form$6" ; }
struct _ConstructionDescriptor descriptor_M_S_Data_Form_s6 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_S_Data_Form_s6), conBindOffs_M_S_Data_Form_s6, &nameFun_M_S_Data_Form_s6, &step_M_S_Data_Form_s6};

int step_M_S_Data_Form_s6(Sink sink__V112, Term term__V113)
{
  int term__V113_count = LINK_COUNT(term__V113); permitUnusedInt(term__V113_count);
  do {
    /* Contraction rule SORTS-S-Data-Form-2. */
    ASSERT(sink__V112->context, !strcmp(SYMBOL(term__V113),  "S-Data-Form$6" ));
    Term sub__V114 = SUB(term__V113, 0); permitUnusedTerm(sub__V114); int sub__V114_count = term__V113_count*LINK_COUNT(sub__V114); permitUnusedInt(sub__V114_count);
    /* sub__V114 = &#1 */
    NamedPropertyLink namedP__V115 = LINK_NamedPropertyLink(sink__V112->context, NAMED_PROPERTIES(term__V113));
    VariablePropertyLink varP__V116 = LINK_VariablePropertyLink(sink__V112->context, VARIABLE_PROPERTIES(term__V113));
    UNLINK(sink__V112->context, term__V113);
    { START(sink__V112, _M__sTextNil); END(sink__V112, _M__sTextNil); }
    UNLINK_NamedPropertyLink(sink__V112->context, namedP__V115); UNLINK_VariablePropertyLink(sink__V112->context, varP__V116);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION S-Data-Form$3. */
int conBindOffs_M_S_Data_Form_s3[] = {0 , 0 , 0 , 0};
char *nameFun_M_S_Data_Form_s3(Term term) { return  "S-Data-Form$3" ; }
struct _ConstructionDescriptor descriptor_M_S_Data_Form_s3 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_S_Data_Form_s3), conBindOffs_M_S_Data_Form_s3, &nameFun_M_S_Data_Form_s3, &step_M_S_Data_Form_s3};

int step_M_S_Data_Form_s3(Sink sink__V117, Term term__V118)
{
  int term__V118_count = LINK_COUNT(term__V118); permitUnusedInt(term__V118_count);
  Term sub__V119 = FORCE(sink__V117->context, SUB(term__V118, 0));
  EnumOf_M__sList choice__V120 = (IS_VARIABLE_USE(sub__V119) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V119));
  switch (choice__V120)
  {
    case Data_M__sNil: { /* Function SORTS-S-Data-Form-3$S-Data-Form$3$$Nil case $Nil */
      ASSERT(sink__V117->context, !strcmp(SYMBOL(term__V118),  "S-Data-Form$3" ));
      Term sub__V121 = SUB(term__V118, 0); permitUnusedTerm(sub__V121); int sub__V121_count = term__V118_count*LINK_COUNT(sub__V121); permitUnusedInt(sub__V121_count);
      ASSERT(sink__V117->context, !strcmp(SYMBOL(sub__V121),  "$Nil" ));
      Term sub__V122 = LINK(sink__V117->context, SUB(term__V118, 1)); int sub__V122_count = term__V118_count*LINK_COUNT(sub__V122); permitUnusedInt(sub__V122_count);
      /* sub__V122 = &#0 */
      Term sub__V123 = LINK(sink__V117->context, SUB(term__V118, 2)); int sub__V123_count = term__V118_count*LINK_COUNT(sub__V123); permitUnusedInt(sub__V123_count);
      /* sub__V123 = &#1 */
      NamedPropertyLink namedP__V124 = LINK_NamedPropertyLink(sink__V117->context, NAMED_PROPERTIES(term__V118));
      VariablePropertyLink varP__V125 = LINK_VariablePropertyLink(sink__V117->context, VARIABLE_PROPERTIES(term__V118));
      UNLINK(sink__V117->context, term__V118);
      ADD_PROPERTIES(sink__V117, LINK_NamedPropertyLink(sink__V117->context, namedP__V124), LINK_VariablePropertyLink(sink__V117->context, varP__V125));
      { START(sink__V117, _M_S_Data_Form_s5);
        COPY(sink__V117, sub__V122);COPY(sink__V117, sub__V123);END(sink__V117, _M_S_Data_Form_s5); }
      UNLINK_NamedPropertyLink(sink__V117->context, namedP__V124); UNLINK_VariablePropertyLink(sink__V117->context, varP__V125);
      
      return 1;
    break; } case Data_M__sCons: { /* Function SORTS-S-Data-Form-4$S-Data-Form$3$$Cons case $Cons */
      ASSERT(sink__V117->context, !strcmp(SYMBOL(term__V118),  "S-Data-Form$3" ));
      Term sub__V126 = SUB(term__V118, 0); permitUnusedTerm(sub__V126); int sub__V126_count = term__V118_count*LINK_COUNT(sub__V126); permitUnusedInt(sub__V126_count);
      ASSERT(sink__V117->context, !strcmp(SYMBOL(sub__V126),  "$Cons" ));
      Term sub__V127 = LINK(sink__V117->context, SUB(sub__V126, 0)); int sub__V127_count = sub__V126_count*LINK_COUNT(sub__V127); permitUnusedInt(sub__V127_count);
      /* sub__V127 = &#0-0 */
      Term sub__V128 = LINK(sink__V117->context, SUB(sub__V126, 1)); int sub__V128_count = sub__V126_count*LINK_COUNT(sub__V128); permitUnusedInt(sub__V128_count);
      /* sub__V128 = &#0-1 */
      Term sub__V129 = LINK(sink__V117->context, SUB(term__V118, 1)); int sub__V129_count = term__V118_count*LINK_COUNT(sub__V129); permitUnusedInt(sub__V129_count);
      /* sub__V129 = &#2 */
      Term sub__V130 = LINK(sink__V117->context, SUB(term__V118, 2)); int sub__V130_count = term__V118_count*LINK_COUNT(sub__V130); permitUnusedInt(sub__V130_count);
      /* sub__V130 = &#3 */
      NamedPropertyLink namedP__V131 = LINK_NamedPropertyLink(sink__V117->context, NAMED_PROPERTIES(term__V118));
      VariablePropertyLink varP__V132 = LINK_VariablePropertyLink(sink__V117->context, VARIABLE_PROPERTIES(term__V118));
      UNLINK(sink__V117->context, term__V118);
      ADD_PROPERTIES(sink__V117, LINK_NamedPropertyLink(sink__V117->context, namedP__V131), LINK_VariablePropertyLink(sink__V117->context, varP__V132));
      { START(sink__V117, _M_S_Data_Form_s4);
        COPY(sink__V117, sub__V127);COPY(sink__V117, sub__V128);COPY(sink__V117, sub__V129);COPY(sink__V117, sub__V130);END(sink__V117, _M_S_Data_Form_s4); }
      UNLINK_NamedPropertyLink(sink__V117->context, namedP__V131); UNLINK_VariablePropertyLink(sink__V117->context, varP__V132);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION S-Data-Form$4. */
int conBindOffs_M_S_Data_Form_s4[] = {0 , 0 , 0 , 0 , 0};
char *nameFun_M_S_Data_Form_s4(Term term) { return  "S-Data-Form$4" ; }
struct _ConstructionDescriptor descriptor_M_S_Data_Form_s4 = {&sort_M_Reified_xVariable, 0, 4, sizeof(STRUCT_Con_M_S_Data_Form_s4), conBindOffs_M_S_Data_Form_s4, &nameFun_M_S_Data_Form_s4, &step_M_S_Data_Form_s4};

int step_M_S_Data_Form_s4(Sink sink__V133, Term term__V134)
{
  int term__V134_count = LINK_COUNT(term__V134); permitUnusedInt(term__V134_count);
  do {
    /* Contraction rule SORTS-S-Data-Form-4. */
    ASSERT(sink__V133->context, !strcmp(SYMBOL(term__V134),  "S-Data-Form$4" ));
    Term sub__V135 = LINK(sink__V133->context, SUB(term__V134, 0)); int sub__V135_count = term__V134_count*LINK_COUNT(sub__V135); permitUnusedInt(sub__V135_count);
    UNLINK_SUB(sink__V133->context, term__V134,  0); NORMALIZE(sink__V133->context, sub__V135); SUB(term__V134,  0) = LINK(sink__V133->context, sub__V135);
    /* sub__V135 = &#221 */
    Term sub__V136 = LINK(sink__V133->context, SUB(term__V134, 1)); int sub__V136_count = term__V134_count*LINK_COUNT(sub__V136); permitUnusedInt(sub__V136_count);
    UNLINK_SUB(sink__V133->context, term__V134,  1); NORMALIZE(sink__V133->context, sub__V136); SUB(term__V134,  1) = LINK(sink__V133->context, sub__V136);
    /* sub__V136 = &#222 */
    Term sub__V137 = LINK(sink__V133->context, SUB(term__V134, 2)); int sub__V137_count = term__V134_count*LINK_COUNT(sub__V137); permitUnusedInt(sub__V137_count);
    UNLINK_SUB(sink__V133->context, term__V134,  2); NORMALIZE(sink__V133->context, sub__V137); SUB(term__V134,  2) = LINK(sink__V133->context, sub__V137);
    /* sub__V137 = &#21 */
    Term sub__V138 = LINK(sink__V133->context, SUB(term__V134, 3)); int sub__V138_count = term__V134_count*LINK_COUNT(sub__V138); permitUnusedInt(sub__V138_count);
    /* sub__V138 = &#1 */
    NamedPropertyLink namedP__V139 = LINK_NamedPropertyLink(sink__V133->context, NAMED_PROPERTIES(term__V134));
    VariablePropertyLink varP__V140 = LINK_VariablePropertyLink(sink__V133->context, VARIABLE_PROPERTIES(term__V134));
    UNLINK(sink__V133->context, term__V134);
    { START(sink__V133, _M__sTextCons);
      { START(sink__V133, _M__sTextChars);
        LITERAL(sink__V133,  "int " ); END(sink__V133, _M__sTextChars); }
      { START(sink__V133, _M__sTextCons);
        { START(sink__V133, _M__sTextEmbed);
          { START(sink__V133, _M_AsText);
            { START(sink__V133, _M_BinderOffsets);
              COPY(sink__V133, LINK(sink__V133->context, sub__V137));END(sink__V133, _M_BinderOffsets); }
            END(sink__V133, _M_AsText); }
          END(sink__V133, _M__sTextEmbed); }
        { START(sink__V133, _M__sTextCons);
          { START(sink__V133, _M__sTextChars);
            LITERAL(sink__V133,  "[] = {0" ); END(sink__V133, _M__sTextChars); }
          { START(sink__V133, _M__sTextCons);
            { START(sink__V133, _M__sTextEmbed);
              { START(sink__V133, _M_AsText);
                { START(sink__V133, _M_DelayMapText_s1);
                  { START(sink__V133, _M_FormArguments__binder__offsets);
                    { START(sink__V133, _M__sCons);
                      COPY(sink__V133, sub__V135);COPY(sink__V133, LINK(sink__V133->context, sub__V136));END(sink__V133, _M__sCons); }
                    LITERAL(sink__V133,  "0" ); END(sink__V133, _M_FormArguments__binder__offsets); }
                  { Variable x__V141 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V133->context,"x__V141");
                    Variable x__V142 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V133->context,"x__V142");
                    Variable binds__V143[2] = {x__V141,x__V142}; BINDS(sink__V133, 2, binds__V143);
                    { START(sink__V133, _M__sTextCons);
                      { START(sink__V133, _M__sTextChars);
                        LITERAL(sink__V133,  " , " ); END(sink__V133, _M__sTextChars); }
                      { START(sink__V133, _M__sTextCons);
                        { START(sink__V133, _M__sTextEmbed);
                          { START(sink__V133, _M_AsText);
                            { START(sink__V133, _M_DINTEGER);
                              USE(sink__V133, x__V141); USE(sink__V133, x__V142); END(sink__V133, _M_DINTEGER); }
                            END(sink__V133, _M_AsText); }
                          END(sink__V133, _M__sTextEmbed); }
                        { START(sink__V133, _M__sTextNil);
                          END(sink__V133, _M__sTextNil); }
                        END(sink__V133, _M__sTextCons); }
                      END(sink__V133, _M__sTextCons); }
                     }
                  END(sink__V133, _M_DelayMapText_s1); }
                END(sink__V133, _M_AsText); }
              END(sink__V133, _M__sTextEmbed); }
            { START(sink__V133, _M__sTextCons);
              { START(sink__V133, _M__sTextChars);
                LITERAL(sink__V133,  "};" ); END(sink__V133, _M__sTextChars); }
              { START(sink__V133, _M__sTextCons);
                { START(sink__V133, _M__sTextBreak);
                  LITERAL(sink__V133,  "\n" ); END(sink__V133, _M__sTextBreak); }
                { START(sink__V133, _M__sTextCons);
                  { START(sink__V133, _M__sTextChars);
                    LITERAL(sink__V133,  "char *" ); END(sink__V133, _M__sTextChars); }
                  { START(sink__V133, _M__sTextCons);
                    { START(sink__V133, _M__sTextEmbed);
                      { START(sink__V133, _M_AsText);
                        { START(sink__V133, _M_Name);
                          COPY(sink__V133, LINK(sink__V133->context, sub__V137));END(sink__V133, _M_Name); }
                        END(sink__V133, _M_AsText); }
                      END(sink__V133, _M__sTextEmbed); }
                    { START(sink__V133, _M__sTextCons);
                      { START(sink__V133, _M__sTextChars);
                        LITERAL(sink__V133,  " = " ); END(sink__V133, _M__sTextChars); }
                      { START(sink__V133, _M__sTextCons);
                        { START(sink__V133, _M__sTextEmbed);
                          { START(sink__V133, _M_AsText);
                            { START(sink__V133, _M_STRING);
                              COPY(sink__V133, LINK(sink__V133->context, sub__V137));END(sink__V133, _M_STRING); }
                            END(sink__V133, _M_AsText); }
                          END(sink__V133, _M__sTextEmbed); }
                        { START(sink__V133, _M__sTextCons);
                          { START(sink__V133, _M__sTextChars);
                            LITERAL(sink__V133,  ";" ); END(sink__V133, _M__sTextChars); }
                          { START(sink__V133, _M__sTextCons);
                            { START(sink__V133, _M__sTextBreak);
                              LITERAL(sink__V133,  "\n" ); END(sink__V133, _M__sTextBreak); }
                            { START(sink__V133, _M__sTextCons);
                              { START(sink__V133, _M__sTextChars);
                                LITERAL(sink__V133,  "char *" ); END(sink__V133, _M__sTextChars); }
                              { START(sink__V133, _M__sTextCons);
                                { START(sink__V133, _M__sTextEmbed);
                                  { START(sink__V133, _M_AsText);
                                    { START(sink__V133, _M_NameFun);
                                      COPY(sink__V133, LINK(sink__V133->context, sub__V137));END(sink__V133, _M_NameFun); }
                                    END(sink__V133, _M_AsText); }
                                  END(sink__V133, _M__sTextEmbed); }
                                { START(sink__V133, _M__sTextCons);
                                  { START(sink__V133, _M__sTextChars);
                                    LITERAL(sink__V133,  "(Term term) { return " );
                                    END(sink__V133, _M__sTextChars); }
                                  { START(sink__V133, _M__sTextCons);
                                    { START(sink__V133, _M__sTextEmbed);
                                      { START(sink__V133, _M_AsText);
                                        { START(sink__V133, _M_Name);
                                          COPY(sink__V133, LINK(sink__V133->context, sub__V137));END(sink__V133, _M_Name); }
                                        END(sink__V133, _M_AsText); }
                                      END(sink__V133, _M__sTextEmbed); }
                                    { START(sink__V133, _M__sTextCons);
                                      { START(sink__V133, _M__sTextChars);
                                        LITERAL(sink__V133,  "; }" ); END(sink__V133, _M__sTextChars); }
                                      { START(sink__V133, _M__sTextCons);
                                        { START(sink__V133, _M__sTextBreak);
                                          LITERAL(sink__V133,  "\n" ); END(sink__V133, _M__sTextBreak); }
                                        { START(sink__V133, _M__sTextCons);
                                          { START(sink__V133, _M__sTextChars);
                                            LITERAL(sink__V133,  "struct _ConstructionDescriptor " );
                                            END(sink__V133, _M__sTextChars); }
                                          { START(sink__V133, _M__sTextCons);
                                            { START(sink__V133, _M__sTextEmbed);
                                              { START(sink__V133, _M_AsText);
                                                { START(sink__V133, _M_Descriptor);
                                                  COPY(sink__V133, LINK(sink__V133->context, sub__V137));END(sink__V133, _M_Descriptor); }
                                                END(sink__V133, _M_AsText); }
                                              END(sink__V133, _M__sTextEmbed); }
                                            { START(sink__V133, _M__sTextCons);
                                              { START(sink__V133, _M__sTextChars);
                                                LITERAL(sink__V133,  " = {&" );
                                                END(sink__V133, _M__sTextChars); }
                                              { START(sink__V133, _M__sTextCons);
                                                { START(sink__V133, _M__sTextEmbed);
                                                  { START(sink__V133, _M_AsText);
                                                    { START(sink__V133, _M_Sort);
                                                      COPY(sink__V133, sub__V138);END(sink__V133, _M_Sort); }
                                                    END(sink__V133, _M_AsText); }
                                                  END(sink__V133, _M__sTextEmbed); }
                                                { START(sink__V133, _M__sTextCons);
                                                  { START(sink__V133, _M__sTextChars);
                                                    LITERAL(sink__V133,  ", " );
                                                    END(sink__V133, _M__sTextChars); }
                                                  { START(sink__V133, _M__sTextCons);
                                                    { START(sink__V133, _M__sTextEmbed);
                                                      { START(sink__V133, _M_AsText);
                                                        { START(sink__V133, _M_EnumTag);
                                                          COPY(sink__V133, LINK(sink__V133->context, sub__V137));END(sink__V133, _M_EnumTag); }
                                                        END(sink__V133, _M_AsText); }
                                                      END(sink__V133, _M__sTextEmbed); }
                                                    { START(sink__V133, _M__sTextCons);
                                                      { START(sink__V133, _M__sTextChars);
                                                        LITERAL(sink__V133,  ", " );
                                                        END(sink__V133, _M__sTextChars); }
                                                      { START(sink__V133, _M__sTextCons);
                                                        { START(sink__V133, _M__sTextEmbed);
                                                          { START(sink__V133, _M_AsText);
                                                            { START(sink__V133, _M_INTEGER);
                                                              { START(sink__V133, _M_Length);
                                                                COPY(sink__V133, sub__V136);LITERAL(sink__V133,  "1" );
                                                                END(sink__V133, _M_Length); }
                                                              END(sink__V133, _M_INTEGER); }
                                                            END(sink__V133, _M_AsText); }
                                                          END(sink__V133, _M__sTextEmbed); }
                                                        { START(sink__V133, _M__sTextCons);
                                                          { START(sink__V133, _M__sTextChars);
                                                            LITERAL(sink__V133,  ", sizeof(STRUCT" );
                                                            END(sink__V133, _M__sTextChars); }
                                                          { START(sink__V133, _M__sTextCons);
                                                            { START(sink__V133, _M__sTextEmbed);
                                                              { START(sink__V133, _M_AsText);
                                                                { START(sink__V133, _M_Struct);
                                                                  COPY(sink__V133, LINK(sink__V133->context, sub__V137));END(sink__V133, _M_Struct); }
                                                                END(sink__V133, _M_AsText); }
                                                              END(sink__V133, _M__sTextEmbed); }
                                                            { START(sink__V133, _M__sTextCons);
                                                              { START(sink__V133, _M__sTextChars);
                                                                LITERAL(sink__V133,  "), " );
                                                                END(sink__V133, _M__sTextChars); }
                                                              { START(sink__V133, _M__sTextCons);
                                                                { START(sink__V133, _M__sTextEmbed);
                                                                  { START(sink__V133, _M_AsText);
                                                                    { START(sink__V133, _M_BinderOffsets);
                                                                      COPY(sink__V133, LINK(sink__V133->context, sub__V137));END(sink__V133, _M_BinderOffsets); }
                                                                    END(sink__V133, _M_AsText); }
                                                                  END(sink__V133, _M__sTextEmbed); }
                                                                { START(sink__V133, _M__sTextCons);
                                                                  { START(sink__V133, _M__sTextChars);
                                                                    LITERAL(sink__V133,  ", &" );
                                                                    END(sink__V133, _M__sTextChars); }
                                                                  { START(sink__V133, _M__sTextCons);
                                                                    { START(sink__V133, _M__sTextEmbed);
                                                                      { START(sink__V133, _M_AsText);
                                                                        { START(sink__V133, _M_NameFun);
                                                                          COPY(sink__V133, sub__V137);END(sink__V133, _M_NameFun); }
                                                                        END(sink__V133, _M_AsText); }
                                                                      END(sink__V133, _M__sTextEmbed); }
                                                                    { START(sink__V133, _M__sTextCons);
                                                                      { START(sink__V133, _M__sTextChars);
                                                                        LITERAL(sink__V133,  ", &dataStep};" );
                                                                        END(sink__V133, _M__sTextChars); }
                                                                      { START(sink__V133, _M__sTextCons);
                                                                        { START(sink__V133, _M__sTextBreak);
                                                                          LITERAL(sink__V133,  "\n" );
                                                                          END(sink__V133, _M__sTextBreak); }
                                                                        { START(sink__V133, _M__sTextNil);
                                                                          END(sink__V133, _M__sTextNil); }
                                                                        END(sink__V133, _M__sTextCons); }
                                                                      END(sink__V133, _M__sTextCons); }
                                                                    END(sink__V133, _M__sTextCons); }
                                                                  END(sink__V133, _M__sTextCons); }
                                                                END(sink__V133, _M__sTextCons); }
                                                              END(sink__V133, _M__sTextCons); }
                                                            END(sink__V133, _M__sTextCons); }
                                                          END(sink__V133, _M__sTextCons); }
                                                        END(sink__V133, _M__sTextCons); }
                                                      END(sink__V133, _M__sTextCons); }
                                                    END(sink__V133, _M__sTextCons); }
                                                  END(sink__V133, _M__sTextCons); }
                                                END(sink__V133, _M__sTextCons); }
                                              END(sink__V133, _M__sTextCons); }
                                            END(sink__V133, _M__sTextCons); }
                                          END(sink__V133, _M__sTextCons); }
                                        END(sink__V133, _M__sTextCons); }
                                      END(sink__V133, _M__sTextCons); }
                                    END(sink__V133, _M__sTextCons); }
                                  END(sink__V133, _M__sTextCons); }
                                END(sink__V133, _M__sTextCons); }
                              END(sink__V133, _M__sTextCons); }
                            END(sink__V133, _M__sTextCons); }
                          END(sink__V133, _M__sTextCons); }
                        END(sink__V133, _M__sTextCons); }
                      END(sink__V133, _M__sTextCons); }
                    END(sink__V133, _M__sTextCons); }
                  END(sink__V133, _M__sTextCons); }
                END(sink__V133, _M__sTextCons); }
              END(sink__V133, _M__sTextCons); }
            END(sink__V133, _M__sTextCons); }
          END(sink__V133, _M__sTextCons); }
        END(sink__V133, _M__sTextCons); }
      END(sink__V133, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V133->context, namedP__V139); UNLINK_VariablePropertyLink(sink__V133->context, varP__V140);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION S-Data-Form$1. */
int conBindOffs_M_S_Data_Form_s1[] = {0 , 0 , 0};
char *nameFun_M_S_Data_Form_s1(Term term) { return  "S-Data-Form$1" ; }
struct _ConstructionDescriptor descriptor_M_S_Data_Form_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_S_Data_Form_s1), conBindOffs_M_S_Data_Form_s1, &nameFun_M_S_Data_Form_s1, &step_M_S_Data_Form_s1};

int step_M_S_Data_Form_s1(Sink sink__V144, Term term__V145)
{
  int term__V145_count = LINK_COUNT(term__V145); permitUnusedInt(term__V145_count);
  Term sub__V146 = FORCE(sink__V144->context, SUB(term__V145, 0));
  EnumOf_M_Reified_xForm choice__V147 = (IS_VARIABLE_USE(sub__V146) ? VarOf_M_Reified_xForm : (EnumOf_M_Reified_xForm) TAG(sub__V146));
  switch (choice__V147)
  {
    case Data_M_SORT_SET: { /* Function SORTS-S-Data-Form-1$S-Data-Form$1$SORT-SET case SORT-SET */
      ASSERT(sink__V144->context, !strcmp(SYMBOL(term__V145),  "S-Data-Form$1" ));
      Term sub__V148 = SUB(term__V145, 0); permitUnusedTerm(sub__V148); int sub__V148_count = term__V145_count*LINK_COUNT(sub__V148); permitUnusedInt(sub__V148_count);
      CRSX_CHECK_SORT(sink__V144->context, sub__V148, &sort_M_Reified_xForm); ASSERT(sink__V144->context, !strcmp(SYMBOL(sub__V148),  "SORT-SET" ));
      Term sub__V149 = LINK(sink__V144->context, SUB(sub__V148, 0)); int sub__V149_count = sub__V148_count*LINK_COUNT(sub__V149); permitUnusedInt(sub__V149_count);
      CRSX_CHECK_SORT(sink__V144->context, sub__V149, &sort_M_Reified_xSort); /* sub__V149 = &#0-0 */
      Term sub__V150 = LINK(sink__V144->context, SUB(sub__V148, 1)); int sub__V150_count = sub__V148_count*LINK_COUNT(sub__V150); permitUnusedInt(sub__V150_count);
      CRSX_CHECK_SORT(sink__V144->context, sub__V150, &sort_M_Reified_xSort); /* sub__V150 = &#0-1 */
      Term sub__V151 = LINK(sink__V144->context, SUB(sub__V148, 2)); int sub__V151_count = sub__V148_count*LINK_COUNT(sub__V151); permitUnusedInt(sub__V151_count);
      CRSX_CHECK_SORT(sink__V144->context, sub__V151, &sort_M_Reified_xForm); /* sub__V151 = &#0-2 */
      Term sub__V152 = LINK(sink__V144->context, SUB(term__V145, 1)); int sub__V152_count = term__V145_count*LINK_COUNT(sub__V152); permitUnusedInt(sub__V152_count);
      /* sub__V152 = &#3 */
      NamedPropertyLink namedP__V153 = LINK_NamedPropertyLink(sink__V144->context, NAMED_PROPERTIES(term__V145));
      VariablePropertyLink varP__V154 = LINK_VariablePropertyLink(sink__V144->context, VARIABLE_PROPERTIES(term__V145));
      UNLINK(sink__V144->context, term__V145);
      ADD_PROPERTIES(sink__V144, LINK_NamedPropertyLink(sink__V144->context, namedP__V153), LINK_VariablePropertyLink(sink__V144->context, varP__V154));
      { START(sink__V144, _M_S_Data_Form_s7);
        COPY(sink__V144, sub__V149);COPY(sink__V144, sub__V150);COPY(sink__V144, sub__V151);COPY(sink__V144, sub__V152);END(sink__V144, _M_S_Data_Form_s7); }
      UNLINK_NamedPropertyLink(sink__V144->context, namedP__V153); UNLINK_VariablePropertyLink(sink__V144->context, varP__V154);
      
      return 1;
    break; } case Data_M_SORT_ALLOWS_VARIABLES: { /* Function SORTS-S-Data-Form-2$S-Data-Form$1$SORT-ALLOWS-VARIABLES case SORT-ALLOWS-VARIABLES */
      ASSERT(sink__V144->context, !strcmp(SYMBOL(term__V145),  "S-Data-Form$1" ));
      Term sub__V155 = SUB(term__V145, 0); permitUnusedTerm(sub__V155); int sub__V155_count = term__V145_count*LINK_COUNT(sub__V155); permitUnusedInt(sub__V155_count);
      CRSX_CHECK_SORT(sink__V144->context, sub__V155, &sort_M_Reified_xForm); ASSERT(sink__V144->context, !strcmp(SYMBOL(sub__V155),  "SORT-ALLOWS-VARIABLES" ));
      Term sub__V156 = LINK(sink__V144->context, SUB(term__V145, 1)); int sub__V156_count = term__V145_count*LINK_COUNT(sub__V156); permitUnusedInt(sub__V156_count);
      /* sub__V156 = &#0 */
      NamedPropertyLink namedP__V157 = LINK_NamedPropertyLink(sink__V144->context, NAMED_PROPERTIES(term__V145));
      VariablePropertyLink varP__V158 = LINK_VariablePropertyLink(sink__V144->context, VARIABLE_PROPERTIES(term__V145));
      UNLINK(sink__V144->context, term__V145);
      ADD_PROPERTIES(sink__V144, LINK_NamedPropertyLink(sink__V144->context, namedP__V157), LINK_VariablePropertyLink(sink__V144->context, varP__V158));
      { START(sink__V144, _M_S_Data_Form_s6);
        COPY(sink__V144, sub__V156);END(sink__V144, _M_S_Data_Form_s6); }
      UNLINK_NamedPropertyLink(sink__V144->context, namedP__V157); UNLINK_VariablePropertyLink(sink__V144->context, varP__V158);
      
      return 1;
    break; } case Data_M_FORM: { /* Function SORTS-S-Data-Form-4$S-Data-Form$1$FORM case FORM */
      ASSERT(sink__V144->context, !strcmp(SYMBOL(term__V145),  "S-Data-Form$1" ));
      Term sub__V159 = SUB(term__V145, 0); permitUnusedTerm(sub__V159); int sub__V159_count = term__V145_count*LINK_COUNT(sub__V159); permitUnusedInt(sub__V159_count);
      CRSX_CHECK_SORT(sink__V144->context, sub__V159, &sort_M_Reified_xForm); ASSERT(sink__V144->context, !strcmp(SYMBOL(sub__V159),  "FORM" ));
      Term sub__V160 = LINK(sink__V144->context, SUB(sub__V159, 0)); int sub__V160_count = sub__V159_count*LINK_COUNT(sub__V160); permitUnusedInt(sub__V160_count);
      /* sub__V160 = &#0-0 */
      Term sub__V161 = LINK(sink__V144->context, SUB(sub__V159, 1)); int sub__V161_count = sub__V159_count*LINK_COUNT(sub__V161); permitUnusedInt(sub__V161_count);
      /* sub__V161 = &#0-1 */
      Term sub__V162 = LINK(sink__V144->context, SUB(term__V145, 1)); int sub__V162_count = term__V145_count*LINK_COUNT(sub__V162); permitUnusedInt(sub__V162_count);
      /* sub__V162 = &#2 */
      NamedPropertyLink namedP__V163 = LINK_NamedPropertyLink(sink__V144->context, NAMED_PROPERTIES(term__V145));
      VariablePropertyLink varP__V164 = LINK_VariablePropertyLink(sink__V144->context, VARIABLE_PROPERTIES(term__V145));
      UNLINK(sink__V144->context, term__V145);
      ADD_PROPERTIES(sink__V144, LINK_NamedPropertyLink(sink__V144->context, namedP__V163), LINK_VariablePropertyLink(sink__V144->context, varP__V164));
      { START(sink__V144, _M_S_Data_Form_s3);
        COPY(sink__V144, sub__V161);COPY(sink__V144, sub__V160);COPY(sink__V144, sub__V162);END(sink__V144, _M_S_Data_Form_s3); }
      UNLINK_NamedPropertyLink(sink__V144->context, namedP__V163); UNLINK_VariablePropertyLink(sink__V144->context, varP__V164);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION ComputeSorts. */
int conBindOffs_M_ComputeSorts[] = {0 , 0};
char *nameFun_M_ComputeSorts(Term term) { return  "ComputeSorts" ; }
struct _ConstructionDescriptor descriptor_M_ComputeSorts = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_ComputeSorts), conBindOffs_M_ComputeSorts, &nameFun_M_ComputeSorts, &step_M_ComputeSorts};

int step_M_ComputeSorts(Sink sink__V165, Term term__V166)
{
  int term__V166_count = LINK_COUNT(term__V166); permitUnusedInt(term__V166_count);
  Term sub__V167 = FORCE(sink__V165->context, SUB(term__V166, 0));
  EnumOf_M_Reify_xCRSX choice__V168 = (IS_VARIABLE_USE(sub__V167) ? VarOf_M_Reify_xCRSX : (EnumOf_M_Reify_xCRSX) TAG(sub__V167));
  switch (choice__V168)
  {
    case Data_M_CRSX: { /* Function SORTS-Crsx$ComputeSorts$CRSX case CRSX */
      ASSERT(sink__V165->context, !strcmp(SYMBOL(term__V166),  "ComputeSorts" ));
      Term sub__V169 = SUB(term__V166, 0); permitUnusedTerm(sub__V169); int sub__V169_count = term__V166_count*LINK_COUNT(sub__V169); permitUnusedInt(sub__V169_count);
      CRSX_CHECK_SORT(sink__V165->context, sub__V169, &sort_M_Reify_xCRSX); ASSERT(sink__V165->context, !strcmp(SYMBOL(sub__V169),  "CRSX" ));
      Term sub__V170 = LINK(sink__V165->context, SUB(sub__V169, 0)); int sub__V170_count = sub__V169_count*LINK_COUNT(sub__V170); permitUnusedInt(sub__V170_count);
      /* sub__V170 = &#0-0 */
      Term sub__V171 = LINK(sink__V165->context, SUB(sub__V169, 1)); int sub__V171_count = sub__V169_count*LINK_COUNT(sub__V171); permitUnusedInt(sub__V171_count);
      /* sub__V171 = &#0-1 */
      NamedPropertyLink namedP__V172 = LINK_NamedPropertyLink(sink__V165->context, NAMED_PROPERTIES(term__V166));
      VariablePropertyLink varP__V173 = LINK_VariablePropertyLink(sink__V165->context, VARIABLE_PROPERTIES(term__V166));
      UNLINK(sink__V165->context, term__V166);
      ADD_PROPERTIES(sink__V165, LINK_NamedPropertyLink(sink__V165->context, namedP__V172), LINK_VariablePropertyLink(sink__V165->context, varP__V173));
      { START(sink__V165, _M_ComputeSorts_s1);
        COPY(sink__V165, sub__V170);COPY(sink__V165, sub__V171);END(sink__V165, _M_ComputeSorts_s1); }
      UNLINK_NamedPropertyLink(sink__V165->context, namedP__V172); UNLINK_VariablePropertyLink(sink__V165->context, varP__V173);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION S-Data. */
int conBindOffs_M_S_Data[] = {0 , 0 , 0};
char *nameFun_M_S_Data(Term term) { return  "S-Data" ; }
struct _ConstructionDescriptor descriptor_M_S_Data = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_S_Data), conBindOffs_M_S_Data, &nameFun_M_S_Data, &step_M_S_Data};

int step_M_S_Data(Sink sink__V174, Term term__V175)
{
  int term__V175_count = LINK_COUNT(term__V175); permitUnusedInt(term__V175_count);
  Term sub__V176 = FORCE(sink__V174->context, SUB(term__V175, 0));
  EnumOf_M_Reified_xSort choice__V177 = (IS_VARIABLE_USE(sub__V176) ? VarOf_M_Reified_xSort : (EnumOf_M_Reified_xSort) TAG(sub__V176));
  switch (choice__V177)
  {
    case Data_M_SORT: { /* Function SORTS-S-Data-1$S-Data$SORT case SORT */
      ASSERT(sink__V174->context, !strcmp(SYMBOL(term__V175),  "S-Data" ));
      Term sub__V178 = SUB(term__V175, 0); permitUnusedTerm(sub__V178); int sub__V178_count = term__V175_count*LINK_COUNT(sub__V178); permitUnusedInt(sub__V178_count);
      CRSX_CHECK_SORT(sink__V174->context, sub__V178, &sort_M_Reified_xSort); ASSERT(sink__V174->context, !strcmp(SYMBOL(sub__V178),  "SORT" ));
      Term sub__V179 = LINK(sink__V174->context, SUB(sub__V178, 0)); int sub__V179_count = sub__V178_count*LINK_COUNT(sub__V179); permitUnusedInt(sub__V179_count);
      /* sub__V179 = &#0-0 */
      Term sub__V180 = LINK(sink__V174->context, SUB(sub__V178, 1)); int sub__V180_count = sub__V178_count*LINK_COUNT(sub__V180); permitUnusedInt(sub__V180_count);
      /* sub__V180 = &#0-1 */
      Term sub__V181 = LINK(sink__V174->context, SUB(term__V175, 1)); int sub__V181_count = term__V175_count*LINK_COUNT(sub__V181); permitUnusedInt(sub__V181_count);
      /* sub__V181 = &#2 */
      NamedPropertyLink namedP__V182 = LINK_NamedPropertyLink(sink__V174->context, NAMED_PROPERTIES(term__V175));
      VariablePropertyLink varP__V183 = LINK_VariablePropertyLink(sink__V174->context, VARIABLE_PROPERTIES(term__V175));
      UNLINK(sink__V174->context, term__V175);
      ADD_PROPERTIES(sink__V174, LINK_NamedPropertyLink(sink__V174->context, namedP__V182), LINK_VariablePropertyLink(sink__V174->context, varP__V183));
      { START(sink__V174, _M_S_Data_s1);
        COPY(sink__V174, sub__V179);COPY(sink__V174, sub__V180);COPY(sink__V174, sub__V181);END(sink__V174, _M_S_Data_s1); }
      UNLINK_NamedPropertyLink(sink__V174->context, namedP__V182); UNLINK_VariablePropertyLink(sink__V174->context, varP__V183);
      
      return 1;
    break; } case Data_M_SORT_PROPERTY: { /* Function SORTS-S-Data-2$S-Data$SORT-PROPERTY case SORT-PROPERTY */
      ASSERT(sink__V174->context, !strcmp(SYMBOL(term__V175),  "S-Data" ));
      Term sub__V184 = SUB(term__V175, 0); permitUnusedTerm(sub__V184); int sub__V184_count = term__V175_count*LINK_COUNT(sub__V184); permitUnusedInt(sub__V184_count);
      CRSX_CHECK_SORT(sink__V174->context, sub__V184, &sort_M_Reified_xSort); ASSERT(sink__V174->context, !strcmp(SYMBOL(sub__V184),  "SORT-PROPERTY" ));
      Term sub__V185 = LINK(sink__V174->context, SUB(sub__V184, 0)); int sub__V185_count = sub__V184_count*LINK_COUNT(sub__V185); permitUnusedInt(sub__V185_count);
      CRSX_CHECK_SORT(sink__V174->context, sub__V185, &sort_M_Reified_xSort); /* sub__V185 = &#0-0 */
      Term sub__V186 = LINK(sink__V174->context, SUB(sub__V184, 1)); int sub__V186_count = sub__V184_count*LINK_COUNT(sub__V186); permitUnusedInt(sub__V186_count);
      CRSX_CHECK_SORT(sink__V174->context, sub__V186, &sort_M_Reified_xSort); /* sub__V186 = &#0-1 */
      Term sub__V187 = LINK(sink__V174->context, SUB(sub__V184, 2)); int sub__V187_count = sub__V184_count*LINK_COUNT(sub__V187); permitUnusedInt(sub__V187_count);
      CRSX_CHECK_SORT(sink__V174->context, sub__V187, &sort_M_Reified_xSort); /* sub__V187 = &#0-2 */
      Term sub__V188 = LINK(sink__V174->context, SUB(term__V175, 1)); int sub__V188_count = term__V175_count*LINK_COUNT(sub__V188); permitUnusedInt(sub__V188_count);
      /* sub__V188 = &#3 */
      NamedPropertyLink namedP__V189 = LINK_NamedPropertyLink(sink__V174->context, NAMED_PROPERTIES(term__V175));
      VariablePropertyLink varP__V190 = LINK_VariablePropertyLink(sink__V174->context, VARIABLE_PROPERTIES(term__V175));
      UNLINK(sink__V174->context, term__V175);
      ADD_PROPERTIES(sink__V174, LINK_NamedPropertyLink(sink__V174->context, namedP__V189), LINK_VariablePropertyLink(sink__V174->context, varP__V190));
      { START(sink__V174, _M_S_Data_s2);
        COPY(sink__V174, sub__V185);COPY(sink__V174, sub__V186);COPY(sink__V174, sub__V187);COPY(sink__V174, sub__V188);END(sink__V174, _M_S_Data_s2); }
      UNLINK_NamedPropertyLink(sink__V174->context, namedP__V189); UNLINK_VariablePropertyLink(sink__V174->context, varP__V190);
      
      return 1;
    } default: break;
  }
  return 0;
}

#ifdef __cplusplus
}
#endif
/* END OF C RULES FOR CRSX CRSXC MODULE SORTS. */
