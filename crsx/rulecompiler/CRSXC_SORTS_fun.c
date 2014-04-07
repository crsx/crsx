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
    Hashset namedFV__V8 = LINK_VARIABLESET(sink__V1->context, asConstruction(term__V2)->properties->namedFreeVars);
    Hashset varFV__V9 = LINK_VARIABLESET(sink__V1->context, asConstruction(term__V2)->properties->variableFreeVars);
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
                      COPY(sink__V1, LINK(sink__V1->context, sub__V5));{ Variable x__V10 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V1->context,"x__V10");
                        Variable binds__V11[1] = {x__V10}; BINDS(sink__V1, 1, binds__V11);
                        { START(sink__V1, _M_S_Data_Form_s1);
                          USE(sink__V1, x__V10); COPY(sink__V1, LINK(sink__V1->context, sub__V3));END(sink__V1, _M_S_Data_Form_s1); }
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
                              { Variable x__V12 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V1->context,"x__V12");
                                Variable x__V13 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V1->context,"x__V13");
                                Variable binds__V14[2] = {x__V12,x__V13}; BINDS(sink__V1, 2, binds__V14);
                                { START(sink__V1, _M__sTextCons);
                                  { START(sink__V1, _M__sTextChars);
                                    LITERAL(sink__V1,  "&" ); END(sink__V1, _M__sTextChars); }
                                  { START(sink__V1, _M__sTextCons);
                                    { START(sink__V1, _M__sTextEmbed);
                                      { START(sink__V1, _M_AsText);
                                        { START(sink__V1, _M_DDescriptor);
                                          USE(sink__V1, x__V12); USE(sink__V1, x__V13); END(sink__V1, _M_DDescriptor); }
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
                                          { Variable x__V15 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V1->context,"x__V15");
                                            Variable x__V16 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V1->context,"x__V16");
                                            Variable binds__V17[2] = {x__V15,x__V16}; BINDS(sink__V1, 2, binds__V17);
                                            { START(sink__V1, _M__sTextCons);
                                              { START(sink__V1, _M__sTextEmbed);
                                                { START(sink__V1, _M_AsText);
                                                  { START(sink__V1, _M_DSTRING);
                                                    USE(sink__V1, x__V15);
                                                    USE(sink__V1, x__V16);
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
                                                      { Variable x__V18 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V1->context,"x__V18");
                                                        Variable x__V19 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V1->context,"x__V19");
                                                        Variable binds__V20[2] = {x__V18,x__V19}; BINDS(sink__V1, 2, binds__V20);
                                                        { START(sink__V1, _M__sTextCons);
                                                          { START(sink__V1, _M__sTextChars);
                                                            LITERAL(sink__V1,  "\"" );
                                                            END(sink__V1, _M__sTextChars); }
                                                          { START(sink__V1, _M__sTextCons);
                                                            { START(sink__V1, _M__sTextEmbed);
                                                              { START(sink__V1, _M_AsText);
                                                                { START(sink__V1, _M_DMANGLE);
                                                                  USE(sink__V1, x__V18);
                                                                  USE(sink__V1, x__V19);
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
    UNLINK_VARIABLESET(sink__V1->context, namedFV__V8); UNLINK_VARIABLESET(sink__V1->context, varFV__V9);
    UNLINK_NamedPropertyLink(sink__V1->context, namedP__V6); UNLINK_VariablePropertyLink(sink__V1->context, varP__V7);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION S-Data$2. */
int conBindOffs_M_S_Data_s2[] = {0 , 0 , 0 , 0 , 0};
char *nameFun_M_S_Data_s2(Term term) { return  "S-Data$2" ; }
struct _ConstructionDescriptor descriptor_M_S_Data_s2 = {&sort_M_Reified_xVariable, 0, 4, sizeof(STRUCT_Con_M_S_Data_s2), conBindOffs_M_S_Data_s2, &nameFun_M_S_Data_s2, &step_M_S_Data_s2};

int step_M_S_Data_s2(Sink sink__V21, Term term__V22)
{
  int term__V22_count = LINK_COUNT(term__V22); permitUnusedInt(term__V22_count);
  do {
    /* Contraction rule SORTS-S-Data-2. */
    ASSERT(sink__V21->context, !strcmp(SYMBOL(term__V22),  "S-Data$2" ));
    Term sub__V23 = SUB(term__V22, 0); permitUnusedTerm(sub__V23); int sub__V23_count = term__V22_count*LINK_COUNT(sub__V23); permitUnusedInt(sub__V23_count);
    CRSX_CHECK_SORT(sink__V21->context, sub__V23, &sort_M_Reified_xSort); /* sub__V23 = &#11 */
    Term sub__V24 = SUB(term__V22, 1); permitUnusedTerm(sub__V24); int sub__V24_count = term__V22_count*LINK_COUNT(sub__V24); permitUnusedInt(sub__V24_count);
    CRSX_CHECK_SORT(sink__V21->context, sub__V24, &sort_M_Reified_xSort); /* sub__V24 = &#12 */
    Term sub__V25 = LINK(sink__V21->context, SUB(term__V22, 2)); int sub__V25_count = term__V22_count*LINK_COUNT(sub__V25); permitUnusedInt(sub__V25_count);
    CRSX_CHECK_SORT(sink__V21->context, sub__V25, &sort_M_Reified_xSort); /* sub__V25 = &#13 */
    Term sub__V26 = LINK(sink__V21->context, SUB(term__V22, 3)); int sub__V26_count = term__V22_count*LINK_COUNT(sub__V26); permitUnusedInt(sub__V26_count);
    /* sub__V26 = &#2 */
    
    NamedPropertyLink namedP__V27 = LINK_NamedPropertyLink(sink__V21->context, NAMED_PROPERTIES(term__V22));
    VariablePropertyLink varP__V28 = LINK_VariablePropertyLink(sink__V21->context, VARIABLE_PROPERTIES(term__V22));
    Hashset namedFV__V29 = LINK_VARIABLESET(sink__V21->context, asConstruction(term__V22)->properties->namedFreeVars);
    Hashset varFV__V30 = LINK_VARIABLESET(sink__V21->context, asConstruction(term__V22)->properties->variableFreeVars);
    UNLINK(sink__V21->context, term__V22);
    { START(sink__V21, _M_S_Data);
      COPY(sink__V21, sub__V25);COPY(sink__V21, sub__V26);END(sink__V21, _M_S_Data); }
    UNLINK_VARIABLESET(sink__V21->context, namedFV__V29); UNLINK_VARIABLESET(sink__V21->context, varFV__V30);
    UNLINK_NamedPropertyLink(sink__V21->context, namedP__V27); UNLINK_VariablePropertyLink(sink__V21->context, varP__V28);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION ComputeSorts$1. */
int conBindOffs_M_ComputeSorts_s1[] = {0 , 0 , 0};
char *nameFun_M_ComputeSorts_s1(Term term) { return  "ComputeSorts$1" ; }
struct _ConstructionDescriptor descriptor_M_ComputeSorts_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_ComputeSorts_s1), conBindOffs_M_ComputeSorts_s1, &nameFun_M_ComputeSorts_s1, &step_M_ComputeSorts_s1};

int step_M_ComputeSorts_s1(Sink sink__V31, Term term__V32)
{
  int term__V32_count = LINK_COUNT(term__V32); permitUnusedInt(term__V32_count);
  do {
    /* Contraction rule SORTS-Crsx. */
    ASSERT(sink__V31->context, !strcmp(SYMBOL(term__V32),  "ComputeSorts$1" ));
    Term sub__V33 = LINK(sink__V31->context, SUB(term__V32, 0)); int sub__V33_count = term__V32_count*LINK_COUNT(sub__V33); permitUnusedInt(sub__V33_count);
    UNLINK_SUB(sink__V31->context, term__V32,  0); NORMALIZE(sink__V31->context, sub__V33); SUB(term__V32,  0) = LINK(sink__V31->context, sub__V33);
    /* sub__V33 = &#11 */
    Term sub__V34 = LINK(sink__V31->context, SUB(term__V32, 1)); int sub__V34_count = term__V32_count*LINK_COUNT(sub__V34); permitUnusedInt(sub__V34_count);
    /* sub__V34 = &#12 */
    
    NamedPropertyLink namedP__V35 = LINK_NamedPropertyLink(sink__V31->context, NAMED_PROPERTIES(term__V32));
    VariablePropertyLink varP__V36 = LINK_VariablePropertyLink(sink__V31->context, VARIABLE_PROPERTIES(term__V32));
    Hashset namedFV__V37 = LINK_VARIABLESET(sink__V31->context, asConstruction(term__V32)->properties->namedFreeVars);
    Hashset varFV__V38 = LINK_VARIABLESET(sink__V31->context, asConstruction(term__V32)->properties->variableFreeVars);
    UNLINK(sink__V31->context, term__V32);
    { START(sink__V31, _M__sTextCons);
      { START(sink__V31, _M__sTextChars);
        LITERAL(sink__V31,  "/* C SORT DESCRIPTORS FOR CRSX " ); END(sink__V31, _M__sTextChars); }
      { START(sink__V31, _M__sTextCons);
        { START(sink__V31, _M__sTextEmbed);
          { START(sink__V31, _M_AsText);
            { START(sink__V31, _M_TOKEN);
              COPY(sink__V31, LINK(sink__V31->context, sub__V33));END(sink__V31, _M_TOKEN); }
            END(sink__V31, _M_AsText); }
          END(sink__V31, _M__sTextEmbed); }
        { START(sink__V31, _M__sTextCons);
          { START(sink__V31, _M__sTextChars);
            LITERAL(sink__V31,  ". */" ); END(sink__V31, _M__sTextChars); }
          { START(sink__V31, _M__sTextCons);
            { START(sink__V31, _M__sTextBreak);
              LITERAL(sink__V31,  "\n" ); END(sink__V31, _M__sTextBreak); }
            { START(sink__V31, _M__sTextCons);
              { START(sink__V31, _M__sTextEmbed);
                { START(sink__V31, _M_AsText);
                  { START(sink__V31, _M_DelayMapText_s1);
                    {char* str__V39;{ Term term__V40;
                        { char *value__V41 = getenv( "HEADERS" );
                          if (value__V41) term__V40 = makeStringLiteral(sink__V31->context, value__V41);
                          else {term__V40 = makeStringLiteral(sink__V31->context,  "" );
                            }
                        }
                        str__V39 = SYMBOL(term__V40); UNLINK(sink__V31->context, term__V40); }
                      
                      char* regex__V42;
                      regex__V42 =  ";" ; SEND_SPLIT(str__V39, regex__V42, sink__V31);
                    }
                    { Variable x__V43 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V31->context,"x__V43");
                      Variable x__V44 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V31->context,"x__V44");
                      Variable binds__V45[2] = {x__V43,x__V44}; BINDS(sink__V31, 2, binds__V45);
                      { START(sink__V31, _M__sTextCons);
                        { START(sink__V31, _M__sTextChars);
                          LITERAL(sink__V31,  "#include \"" ); END(sink__V31, _M__sTextChars); }
                        { START(sink__V31, _M__sTextCons);
                          { START(sink__V31, _M__sTextEmbed);
                            { START(sink__V31, _M_AsText);
                              { START(sink__V31, _M_DTOKEN);
                                USE(sink__V31, x__V43); USE(sink__V31, x__V44); END(sink__V31, _M_DTOKEN); }
                              END(sink__V31, _M_AsText); }
                            END(sink__V31, _M__sTextEmbed); }
                          { START(sink__V31, _M__sTextCons);
                            { START(sink__V31, _M__sTextChars);
                              LITERAL(sink__V31,  "\"" ); END(sink__V31, _M__sTextChars); }
                            { START(sink__V31, _M__sTextCons);
                              { START(sink__V31, _M__sTextBreak);
                                LITERAL(sink__V31,  "\n" ); END(sink__V31, _M__sTextBreak); }
                              { START(sink__V31, _M__sTextNil);
                                END(sink__V31, _M__sTextNil); }
                              END(sink__V31, _M__sTextCons); }
                            END(sink__V31, _M__sTextCons); }
                          END(sink__V31, _M__sTextCons); }
                        END(sink__V31, _M__sTextCons); }
                       }
                    END(sink__V31, _M_DelayMapText_s1); }
                  END(sink__V31, _M_AsText); }
                END(sink__V31, _M__sTextEmbed); }
              { START(sink__V31, _M__sTextCons);
                { START(sink__V31, _M__sTextBreak);
                  LITERAL(sink__V31,  "\n" ); END(sink__V31, _M__sTextBreak); }
                { START(sink__V31, _M__sTextCons);
                  { START(sink__V31, _M__sTextChars);
                    LITERAL(sink__V31,  "#ifdef __cplusplus" ); END(sink__V31, _M__sTextChars); }
                  { START(sink__V31, _M__sTextCons);
                    { START(sink__V31, _M__sTextBreak);
                      LITERAL(sink__V31,  "\n" ); END(sink__V31, _M__sTextBreak); }
                    { START(sink__V31, _M__sTextCons);
                      { START(sink__V31, _M__sTextChars);
                        LITERAL(sink__V31,  "extern \"C\" {" ); END(sink__V31, _M__sTextChars); }
                      { START(sink__V31, _M__sTextCons);
                        { START(sink__V31, _M__sTextBreak);
                          LITERAL(sink__V31,  "\n" ); END(sink__V31, _M__sTextBreak); }
                        { START(sink__V31, _M__sTextCons);
                          { START(sink__V31, _M__sTextChars);
                            LITERAL(sink__V31,  "#endif" ); END(sink__V31, _M__sTextChars); }
                          { START(sink__V31, _M__sTextCons);
                            { START(sink__V31, _M__sTextBreak);
                              LITERAL(sink__V31,  "\n" ); END(sink__V31, _M__sTextBreak); }
                            { START(sink__V31, _M__sTextCons);
                              { START(sink__V31, _M__sTextEmbed);
                                { START(sink__V31, _M_AsText);
                                  { START(sink__V31, _M_MapText_s1);
                                    COPY(sink__V31, sub__V34);{ Variable x__V46 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V31->context,"x__V46");
                                      Variable binds__V47[1] = {x__V46}; BINDS(sink__V31, 1, binds__V47);
                                      { START(sink__V31, _M_S_Declaration);
                                        USE(sink__V31, x__V46); END(sink__V31, _M_S_Declaration); }
                                       }
                                    END(sink__V31, _M_MapText_s1); }
                                  END(sink__V31, _M_AsText); }
                                END(sink__V31, _M__sTextEmbed); }
                              { START(sink__V31, _M__sTextCons);
                                { START(sink__V31, _M__sTextBreak);
                                  LITERAL(sink__V31,  "\n" ); END(sink__V31, _M__sTextBreak); }
                                { START(sink__V31, _M__sTextCons);
                                  { START(sink__V31, _M__sTextChars);
                                    LITERAL(sink__V31,  "#ifdef __cplusplus" );
                                    END(sink__V31, _M__sTextChars); }
                                  { START(sink__V31, _M__sTextCons);
                                    { START(sink__V31, _M__sTextBreak);
                                      LITERAL(sink__V31,  "\n" ); END(sink__V31, _M__sTextBreak); }
                                    { START(sink__V31, _M__sTextCons);
                                      { START(sink__V31, _M__sTextChars);
                                        LITERAL(sink__V31,  "}" ); END(sink__V31, _M__sTextChars); }
                                      { START(sink__V31, _M__sTextCons);
                                        { START(sink__V31, _M__sTextBreak);
                                          LITERAL(sink__V31,  "\n" ); END(sink__V31, _M__sTextBreak); }
                                        { START(sink__V31, _M__sTextCons);
                                          { START(sink__V31, _M__sTextChars);
                                            LITERAL(sink__V31,  "#endif" );
                                            END(sink__V31, _M__sTextChars); }
                                          { START(sink__V31, _M__sTextCons);
                                            { START(sink__V31, _M__sTextBreak);
                                              LITERAL(sink__V31,  "\n" );
                                              END(sink__V31, _M__sTextBreak); }
                                            { START(sink__V31, _M__sTextCons);
                                              { START(sink__V31, _M__sTextChars);
                                                LITERAL(sink__V31,  "/* END OF C SORT DESCRIPTORS FOR CRSX " );
                                                END(sink__V31, _M__sTextChars); }
                                              { START(sink__V31, _M__sTextCons);
                                                { START(sink__V31, _M__sTextEmbed);
                                                  { START(sink__V31, _M_AsText);
                                                    { START(sink__V31, _M_TOKEN);
                                                      COPY(sink__V31, sub__V33);END(sink__V31, _M_TOKEN); }
                                                    END(sink__V31, _M_AsText); }
                                                  END(sink__V31, _M__sTextEmbed); }
                                                { START(sink__V31, _M__sTextCons);
                                                  { START(sink__V31, _M__sTextChars);
                                                    LITERAL(sink__V31,  ". */" );
                                                    END(sink__V31, _M__sTextChars); }
                                                  { START(sink__V31, _M__sTextCons);
                                                    { START(sink__V31, _M__sTextBreak);
                                                      LITERAL(sink__V31,  "\n" );
                                                      END(sink__V31, _M__sTextBreak); }
                                                    { START(sink__V31, _M__sTextNil);
                                                      END(sink__V31, _M__sTextNil); }
                                                    END(sink__V31, _M__sTextCons); }
                                                  END(sink__V31, _M__sTextCons); }
                                                END(sink__V31, _M__sTextCons); }
                                              END(sink__V31, _M__sTextCons); }
                                            END(sink__V31, _M__sTextCons); }
                                          END(sink__V31, _M__sTextCons); }
                                        END(sink__V31, _M__sTextCons); }
                                      END(sink__V31, _M__sTextCons); }
                                    END(sink__V31, _M__sTextCons); }
                                  END(sink__V31, _M__sTextCons); }
                                END(sink__V31, _M__sTextCons); }
                              END(sink__V31, _M__sTextCons); }
                            END(sink__V31, _M__sTextCons); }
                          END(sink__V31, _M__sTextCons); }
                        END(sink__V31, _M__sTextCons); }
                      END(sink__V31, _M__sTextCons); }
                    END(sink__V31, _M__sTextCons); }
                  END(sink__V31, _M__sTextCons); }
                END(sink__V31, _M__sTextCons); }
              END(sink__V31, _M__sTextCons); }
            END(sink__V31, _M__sTextCons); }
          END(sink__V31, _M__sTextCons); }
        END(sink__V31, _M__sTextCons); }
      END(sink__V31, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V31->context, namedFV__V37); UNLINK_VARIABLESET(sink__V31->context, varFV__V38);
    UNLINK_NamedPropertyLink(sink__V31->context, namedP__V35); UNLINK_VariablePropertyLink(sink__V31->context, varP__V36);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION S-Declaration. */
int conBindOffs_M_S_Declaration[] = {0 , 0};
char *nameFun_M_S_Declaration(Term term) { return  "S-Declaration" ; }
struct _ConstructionDescriptor descriptor_M_S_Declaration = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_S_Declaration), conBindOffs_M_S_Declaration, &nameFun_M_S_Declaration, &step_M_S_Declaration};

int step_M_S_Declaration(Sink sink__V48, Term term__V49)
{
  int term__V49_count = LINK_COUNT(term__V49); permitUnusedInt(term__V49_count);
  Term sub__V50 = FORCE(sink__V48->context, SUB(term__V49, 0));
  EnumOf_M_Reified_xDeclaration choice__V51 = (IS_VARIABLE_USE(sub__V50) ? VarOf_M_Reified_xDeclaration : (EnumOf_M_Reified_xDeclaration) TAG(sub__V50));
  switch (choice__V51)
  {
    case Data_M_DATA: { /* Function SORTS-Data$S-Declaration$DATA case DATA */
      ASSERT(sink__V48->context, !strcmp(SYMBOL(term__V49),  "S-Declaration" ));
      Term sub__V52 = SUB(term__V49, 0); permitUnusedTerm(sub__V52); int sub__V52_count = term__V49_count*LINK_COUNT(sub__V52); permitUnusedInt(sub__V52_count);
      CRSX_CHECK_SORT(sink__V48->context, sub__V52, &sort_M_Reified_xDeclaration); ASSERT(sink__V48->context, !strcmp(SYMBOL(sub__V52),  "DATA" ));
      Term sub__V53 = LINK(sink__V48->context, SUB(sub__V52, 0)); int sub__V53_count = sub__V52_count*LINK_COUNT(sub__V53); permitUnusedInt(sub__V53_count);
      CRSX_CHECK_SORT(sink__V48->context, sub__V53, &sort_M_Reified_xSort); /* sub__V53 = &#0-0 */
      Term sub__V54 = LINK(sink__V48->context, SUB(sub__V52, 1)); int sub__V54_count = sub__V52_count*LINK_COUNT(sub__V54); permitUnusedInt(sub__V54_count);
      /* sub__V54 = &#0-1 */
      
      NamedPropertyLink namedP__V55 = LINK_NamedPropertyLink(sink__V48->context, NAMED_PROPERTIES(term__V49));
      VariablePropertyLink varP__V56 = LINK_VariablePropertyLink(sink__V48->context, VARIABLE_PROPERTIES(term__V49));
      Hashset namedFV__V57 = LINK_VARIABLESET(sink__V48->context, asConstruction(term__V49)->properties->namedFreeVars);
      Hashset varFV__V58 = LINK_VARIABLESET(sink__V48->context, asConstruction(term__V49)->properties->variableFreeVars);
      UNLINK(sink__V48->context, term__V49);
      ADD_PROPERTIES(sink__V48, LINK_VARIABLESET(sink__V48->context, namedFV__V57), LINK_VARIABLESET(sink__V48->context, varFV__V58), LINK_NamedPropertyLink(sink__V48->context, namedP__V55), LINK_VariablePropertyLink(sink__V48->context, varP__V56));
      { START(sink__V48, _M_S_Declaration_s1);
        COPY(sink__V48, sub__V53);COPY(sink__V48, sub__V54);END(sink__V48, _M_S_Declaration_s1); }
      UNLINK_VARIABLESET(sink__V48->context, namedFV__V57); UNLINK_VARIABLESET(sink__V48->context, varFV__V58);
      UNLINK_NamedPropertyLink(sink__V48->context, namedP__V55); UNLINK_VariablePropertyLink(sink__V48->context, varP__V56);
      
      return 1;
    break; } case Data_M_FUNCTION: { /* Function SORTS-Function$S-Declaration$FUNCTION case FUNCTION */
      ASSERT(sink__V48->context, !strcmp(SYMBOL(term__V49),  "S-Declaration" ));
      Term sub__V59 = SUB(term__V49, 0); permitUnusedTerm(sub__V59); int sub__V59_count = term__V49_count*LINK_COUNT(sub__V59); permitUnusedInt(sub__V59_count);
      CRSX_CHECK_SORT(sink__V48->context, sub__V59, &sort_M_Reified_xDeclaration); ASSERT(sink__V48->context, !strcmp(SYMBOL(sub__V59),  "FUNCTION" ));
      Term sub__V60 = LINK(sink__V48->context, SUB(sub__V59, 0)); int sub__V60_count = sub__V59_count*LINK_COUNT(sub__V60); permitUnusedInt(sub__V60_count);
      /* sub__V60 = &#0-0 */
      Term sub__V61 = LINK(sink__V48->context, SUB(sub__V59, 1)); int sub__V61_count = sub__V59_count*LINK_COUNT(sub__V61); permitUnusedInt(sub__V61_count);
      /* sub__V61 = &#0-1 */
      Term sub__V62 = LINK(sink__V48->context, SUB(sub__V59, 2)); int sub__V62_count = sub__V59_count*LINK_COUNT(sub__V62); permitUnusedInt(sub__V62_count);
      /* sub__V62 = &#0-2 */
      Term sub__V63 = LINK(sink__V48->context, SUB(sub__V59, 3)); int sub__V63_count = sub__V59_count*LINK_COUNT(sub__V63); permitUnusedInt(sub__V63_count);
      /* sub__V63 = &#0-3 */
      Term sub__V64 = LINK(sink__V48->context, SUB(sub__V59, 4)); int sub__V64_count = sub__V59_count*LINK_COUNT(sub__V64); permitUnusedInt(sub__V64_count);
      /* sub__V64 = &#0-4 */
      Term sub__V65 = LINK(sink__V48->context, SUB(sub__V59, 5)); int sub__V65_count = sub__V59_count*LINK_COUNT(sub__V65); permitUnusedInt(sub__V65_count);
      CRSX_CHECK_SORT(sink__V48->context, sub__V65, &sort_M_Reified_xSort); /* sub__V65 = &#0-5 */
      Term sub__V66 = LINK(sink__V48->context, SUB(sub__V59, 6)); int sub__V66_count = sub__V59_count*LINK_COUNT(sub__V66); permitUnusedInt(sub__V66_count);
      /* sub__V66 = &#0-6 */
      
      NamedPropertyLink namedP__V67 = LINK_NamedPropertyLink(sink__V48->context, NAMED_PROPERTIES(term__V49));
      VariablePropertyLink varP__V68 = LINK_VariablePropertyLink(sink__V48->context, VARIABLE_PROPERTIES(term__V49));
      Hashset namedFV__V69 = LINK_VARIABLESET(sink__V48->context, asConstruction(term__V49)->properties->namedFreeVars);
      Hashset varFV__V70 = LINK_VARIABLESET(sink__V48->context, asConstruction(term__V49)->properties->variableFreeVars);
      UNLINK(sink__V48->context, term__V49);
      ADD_PROPERTIES(sink__V48, LINK_VARIABLESET(sink__V48->context, namedFV__V69), LINK_VARIABLESET(sink__V48->context, varFV__V70), LINK_NamedPropertyLink(sink__V48->context, namedP__V67), LINK_VariablePropertyLink(sink__V48->context, varP__V68));
      { START(sink__V48, _M_S_Declaration_s2);
        COPY(sink__V48, sub__V60);COPY(sink__V48, sub__V61);COPY(sink__V48, sub__V62);COPY(sink__V48, sub__V63);COPY(sink__V48, sub__V64);COPY(sink__V48, sub__V65);COPY(sink__V48, sub__V66);END(sink__V48, _M_S_Declaration_s2); }
      UNLINK_VARIABLESET(sink__V48->context, namedFV__V69); UNLINK_VARIABLESET(sink__V48->context, varFV__V70);
      UNLINK_NamedPropertyLink(sink__V48->context, namedP__V67); UNLINK_VariablePropertyLink(sink__V48->context, varP__V68);
      
      return 1;
    break; } case Data_M_POLYMORPHIC: { /* Function SORTS-Polymorphic$S-Declaration$POLYMORPHIC case POLYMORPHIC */
      ASSERT(sink__V48->context, !strcmp(SYMBOL(term__V49),  "S-Declaration" ));
      Term sub__V71 = SUB(term__V49, 0); permitUnusedTerm(sub__V71); int sub__V71_count = term__V49_count*LINK_COUNT(sub__V71); permitUnusedInt(sub__V71_count);
      CRSX_CHECK_SORT(sink__V48->context, sub__V71, &sort_M_Reified_xDeclaration); ASSERT(sink__V48->context, !strcmp(SYMBOL(sub__V71),  "POLYMORPHIC" ));
      Variable y__V72 = BINDER(sub__V71,0,0); if (sub__V71_count <= 1) UNBIND(y__V72);
      Term sub__V73 = LINK(sink__V48->context, SUB(sub__V71, 0)); int sub__V73_count = sub__V71_count*LINK_COUNT(sub__V73); permitUnusedInt(sub__V73_count);
      CRSX_CHECK_SORT(sink__V48->context, sub__V73, &sort_M_Reified_xDeclaration); /* sub__V73 = &#0-0 */
      
      NamedPropertyLink namedP__V74 = LINK_NamedPropertyLink(sink__V48->context, NAMED_PROPERTIES(term__V49));
      VariablePropertyLink varP__V75 = LINK_VariablePropertyLink(sink__V48->context, VARIABLE_PROPERTIES(term__V49));
      Hashset namedFV__V76 = LINK_VARIABLESET(sink__V48->context, asConstruction(term__V49)->properties->namedFreeVars);
      Hashset varFV__V77 = LINK_VARIABLESET(sink__V48->context, asConstruction(term__V49)->properties->variableFreeVars);
      UNLINK(sink__V48->context, term__V49);
      ADD_PROPERTIES(sink__V48, LINK_VARIABLESET(sink__V48->context, namedFV__V76), LINK_VARIABLESET(sink__V48->context, varFV__V77), LINK_NamedPropertyLink(sink__V48->context, namedP__V74), LINK_VariablePropertyLink(sink__V48->context, varP__V75));
      { START(sink__V48, _M_S_Declaration_s3);
        { if (!IS_BOUND(y__V72)) { REBIND(y__V72);
            Variable binds__V78[1] = {y__V72}; BINDS(sink__V48, 1, binds__V78);
            COPY(sink__V48, sub__V73); /* REUSED SUBSTITUTION */  }
          else { Variable b__V79 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V48->context,"b__V79");
            Variable binds__V80[1] = {b__V79}; BINDS(sink__V48, 1, binds__V80);
            {
              Term arg__V81;
              { Sink buf__V82 = ALLOCA_BUFFER(sink__V48->context);
                USE(buf__V82, b__V79); arg__V81 = BUFFER_TERM(buf__V82); FREE_BUFFER(buf__V82); }
              Variable vars__V83[1] = {y__V72};
              Term args__V84[1] = {arg__V81};
              struct _SubstitutionFrame substitution__V85 = {NULL, 0, 1, vars__V83, args__V84, NULL};
              SUBSTITUTE(sink__V48, sub__V73, &substitution__V85); }
                }
           }
        END(sink__V48, _M_S_Declaration_s3); }
      UNLINK_VARIABLESET(sink__V48->context, namedFV__V76); UNLINK_VARIABLESET(sink__V48->context, varFV__V77);
      UNLINK_NamedPropertyLink(sink__V48->context, namedP__V74); UNLINK_VariablePropertyLink(sink__V48->context, varP__V75);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION S-Declaration$3. */
int conBindOffs_M_S_Declaration_s3[] = {0 , 1};
char *nameFun_M_S_Declaration_s3(Term term) { return  "S-Declaration$3" ; }
struct _ConstructionDescriptor descriptor_M_S_Declaration_s3 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_S_Declaration_s3), conBindOffs_M_S_Declaration_s3, &nameFun_M_S_Declaration_s3, &step_M_S_Declaration_s3};

int step_M_S_Declaration_s3(Sink sink__V86, Term term__V87)
{
  int term__V87_count = LINK_COUNT(term__V87); permitUnusedInt(term__V87_count);
  do {
    /* Contraction rule SORTS-Polymorphic. */
    ASSERT(sink__V86->context, !strcmp(SYMBOL(term__V87),  "S-Declaration$3" ));
    Variable x__V88 = BINDER(term__V87,0,0); if (term__V87_count <= 1) UNBIND(x__V88);
    Term sub__V89 = LINK(sink__V86->context, SUB(term__V87, 0)); int sub__V89_count = term__V87_count*LINK_COUNT(sub__V89); permitUnusedInt(sub__V89_count);
    CRSX_CHECK_SORT(sink__V86->context, sub__V89, &sort_M_Reified_xDeclaration); /* sub__V89 = &#11 */
    Variable y__V90 = x__V88; permitUnusedVariable(y__V90);
    
    NamedPropertyLink namedP__V91 = LINK_NamedPropertyLink(sink__V86->context, NAMED_PROPERTIES(term__V87));
    VariablePropertyLink varP__V92 = LINK_VariablePropertyLink(sink__V86->context, VARIABLE_PROPERTIES(term__V87));
    Hashset namedFV__V93 = LINK_VARIABLESET(sink__V86->context, asConstruction(term__V87)->properties->namedFreeVars);
    Hashset varFV__V94 = LINK_VARIABLESET(sink__V86->context, asConstruction(term__V87)->properties->variableFreeVars);
    UNLINK(sink__V86->context, term__V87);
    { START(sink__V86, _M_S_Declaration);
      COPY(sink__V86, sub__V89); /* REUSED SUBSTITUTION */ END(sink__V86, _M_S_Declaration); }
    UNLINK_VARIABLESET(sink__V86->context, namedFV__V93); UNLINK_VARIABLESET(sink__V86->context, varFV__V94);
    UNLINK_NamedPropertyLink(sink__V86->context, namedP__V91); UNLINK_VariablePropertyLink(sink__V86->context, varP__V92);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION S-Declaration$2. */
int conBindOffs_M_S_Declaration_s2[] = {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0};
char *nameFun_M_S_Declaration_s2(Term term) { return  "S-Declaration$2" ; }
struct _ConstructionDescriptor descriptor_M_S_Declaration_s2 = {&sort_M_Reified_xVariable, 0, 7, sizeof(STRUCT_Con_M_S_Declaration_s2), conBindOffs_M_S_Declaration_s2, &nameFun_M_S_Declaration_s2, &step_M_S_Declaration_s2};

int step_M_S_Declaration_s2(Sink sink__V95, Term term__V96)
{
  int term__V96_count = LINK_COUNT(term__V96); permitUnusedInt(term__V96_count);
  do {
    /* Contraction rule SORTS-Function. */
    ASSERT(sink__V95->context, !strcmp(SYMBOL(term__V96),  "S-Declaration$2" ));
    Term sub__V97 = SUB(term__V96, 0); permitUnusedTerm(sub__V97); int sub__V97_count = term__V96_count*LINK_COUNT(sub__V97); permitUnusedInt(sub__V97_count);
    /* sub__V97 = &#11 */
    Term sub__V98 = SUB(term__V96, 1); permitUnusedTerm(sub__V98); int sub__V98_count = term__V96_count*LINK_COUNT(sub__V98); permitUnusedInt(sub__V98_count);
    /* sub__V98 = &#12 */
    Term sub__V99 = SUB(term__V96, 2); permitUnusedTerm(sub__V99); int sub__V99_count = term__V96_count*LINK_COUNT(sub__V99); permitUnusedInt(sub__V99_count);
    /* sub__V99 = &#13 */
    Term sub__V100 = SUB(term__V96, 3); permitUnusedTerm(sub__V100); int sub__V100_count = term__V96_count*LINK_COUNT(sub__V100); permitUnusedInt(sub__V100_count);
    /* sub__V100 = &#14 */
    Term sub__V101 = SUB(term__V96, 4); permitUnusedTerm(sub__V101); int sub__V101_count = term__V96_count*LINK_COUNT(sub__V101); permitUnusedInt(sub__V101_count);
    /* sub__V101 = &#15 */
    Term sub__V102 = SUB(term__V96, 5); permitUnusedTerm(sub__V102); int sub__V102_count = term__V96_count*LINK_COUNT(sub__V102); permitUnusedInt(sub__V102_count);
    CRSX_CHECK_SORT(sink__V95->context, sub__V102, &sort_M_Reified_xSort); /* sub__V102 = &#16 */
    Term sub__V103 = SUB(term__V96, 6); permitUnusedTerm(sub__V103); int sub__V103_count = term__V96_count*LINK_COUNT(sub__V103); permitUnusedInt(sub__V103_count);
    /* sub__V103 = &#17 */
    
    NamedPropertyLink namedP__V104 = LINK_NamedPropertyLink(sink__V95->context, NAMED_PROPERTIES(term__V96));
    VariablePropertyLink varP__V105 = LINK_VariablePropertyLink(sink__V95->context, VARIABLE_PROPERTIES(term__V96));
    Hashset namedFV__V106 = LINK_VARIABLESET(sink__V95->context, asConstruction(term__V96)->properties->namedFreeVars);
    Hashset varFV__V107 = LINK_VARIABLESET(sink__V95->context, asConstruction(term__V96)->properties->variableFreeVars);
    UNLINK(sink__V95->context, term__V96);
    { START(sink__V95, _M__sTextNil); END(sink__V95, _M__sTextNil); } UNLINK_VARIABLESET(sink__V95->context, namedFV__V106); UNLINK_VARIABLESET(sink__V95->context, varFV__V107);
    UNLINK_NamedPropertyLink(sink__V95->context, namedP__V104); UNLINK_VariablePropertyLink(sink__V95->context, varP__V105);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION S-Declaration$1. */
int conBindOffs_M_S_Declaration_s1[] = {0 , 0 , 0};
char *nameFun_M_S_Declaration_s1(Term term) { return  "S-Declaration$1" ; }
struct _ConstructionDescriptor descriptor_M_S_Declaration_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_S_Declaration_s1), conBindOffs_M_S_Declaration_s1, &nameFun_M_S_Declaration_s1, &step_M_S_Declaration_s1};

int step_M_S_Declaration_s1(Sink sink__V108, Term term__V109)
{
  int term__V109_count = LINK_COUNT(term__V109); permitUnusedInt(term__V109_count);
  do {
    /* Contraction rule SORTS-Data. */
    ASSERT(sink__V108->context, !strcmp(SYMBOL(term__V109),  "S-Declaration$1" ));
    Term sub__V110 = LINK(sink__V108->context, SUB(term__V109, 0)); int sub__V110_count = term__V109_count*LINK_COUNT(sub__V110); permitUnusedInt(sub__V110_count);
    CRSX_CHECK_SORT(sink__V108->context, sub__V110, &sort_M_Reified_xSort); /* sub__V110 = &#11 */
    Term sub__V111 = LINK(sink__V108->context, SUB(term__V109, 1)); int sub__V111_count = term__V109_count*LINK_COUNT(sub__V111); permitUnusedInt(sub__V111_count);
    /* sub__V111 = &#12 */
    
    NamedPropertyLink namedP__V112 = LINK_NamedPropertyLink(sink__V108->context, NAMED_PROPERTIES(term__V109));
    VariablePropertyLink varP__V113 = LINK_VariablePropertyLink(sink__V108->context, VARIABLE_PROPERTIES(term__V109));
    Hashset namedFV__V114 = LINK_VARIABLESET(sink__V108->context, asConstruction(term__V109)->properties->namedFreeVars);
    Hashset varFV__V115 = LINK_VARIABLESET(sink__V108->context, asConstruction(term__V109)->properties->variableFreeVars);
    UNLINK(sink__V108->context, term__V109);
    { START(sink__V108, _M_S_Data);
      COPY(sink__V108, sub__V110);COPY(sink__V108, sub__V111);END(sink__V108, _M_S_Data); }
    UNLINK_VARIABLESET(sink__V108->context, namedFV__V114); UNLINK_VARIABLESET(sink__V108->context, varFV__V115);
    UNLINK_NamedPropertyLink(sink__V108->context, namedP__V112); UNLINK_VariablePropertyLink(sink__V108->context, varP__V113);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION S-Data-Form$7. */
int conBindOffs_M_S_Data_Form_s7[] = {0 , 0 , 0 , 0 , 0};
char *nameFun_M_S_Data_Form_s7(Term term) { return  "S-Data-Form$7" ; }
struct _ConstructionDescriptor descriptor_M_S_Data_Form_s7 = {&sort_M_Reified_xVariable, 0, 4, sizeof(STRUCT_Con_M_S_Data_Form_s7), conBindOffs_M_S_Data_Form_s7, &nameFun_M_S_Data_Form_s7, &step_M_S_Data_Form_s7};

int step_M_S_Data_Form_s7(Sink sink__V116, Term term__V117)
{
  int term__V117_count = LINK_COUNT(term__V117); permitUnusedInt(term__V117_count);
  do {
    /* Contraction rule SORTS-S-Data-Form-1. */
    ASSERT(sink__V116->context, !strcmp(SYMBOL(term__V117),  "S-Data-Form$7" ));
    Term sub__V118 = SUB(term__V117, 0); permitUnusedTerm(sub__V118); int sub__V118_count = term__V117_count*LINK_COUNT(sub__V118); permitUnusedInt(sub__V118_count);
    CRSX_CHECK_SORT(sink__V116->context, sub__V118, &sort_M_Reified_xSort); /* sub__V118 = &#21 */
    Term sub__V119 = SUB(term__V117, 1); permitUnusedTerm(sub__V119); int sub__V119_count = term__V117_count*LINK_COUNT(sub__V119); permitUnusedInt(sub__V119_count);
    CRSX_CHECK_SORT(sink__V116->context, sub__V119, &sort_M_Reified_xSort); /* sub__V119 = &#22 */
    Term sub__V120 = LINK(sink__V116->context, SUB(term__V117, 2)); int sub__V120_count = term__V117_count*LINK_COUNT(sub__V120); permitUnusedInt(sub__V120_count);
    CRSX_CHECK_SORT(sink__V116->context, sub__V120, &sort_M_Reified_xForm); /* sub__V120 = &#23 */
    Term sub__V121 = LINK(sink__V116->context, SUB(term__V117, 3)); int sub__V121_count = term__V117_count*LINK_COUNT(sub__V121); permitUnusedInt(sub__V121_count);
    /* sub__V121 = &#1 */
    
    NamedPropertyLink namedP__V122 = LINK_NamedPropertyLink(sink__V116->context, NAMED_PROPERTIES(term__V117));
    VariablePropertyLink varP__V123 = LINK_VariablePropertyLink(sink__V116->context, VARIABLE_PROPERTIES(term__V117));
    Hashset namedFV__V124 = LINK_VARIABLESET(sink__V116->context, asConstruction(term__V117)->properties->namedFreeVars);
    Hashset varFV__V125 = LINK_VARIABLESET(sink__V116->context, asConstruction(term__V117)->properties->variableFreeVars);
    UNLINK(sink__V116->context, term__V117);
    { START(sink__V116, _M_S_Data_Form_s1);
      COPY(sink__V116, sub__V120);COPY(sink__V116, sub__V121);END(sink__V116, _M_S_Data_Form_s1); }
    UNLINK_VARIABLESET(sink__V116->context, namedFV__V124); UNLINK_VARIABLESET(sink__V116->context, varFV__V125);
    UNLINK_NamedPropertyLink(sink__V116->context, namedP__V122); UNLINK_VariablePropertyLink(sink__V116->context, varP__V123);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION S-Data-Form$5. */
int conBindOffs_M_S_Data_Form_s5[] = {0 , 0 , 0};
char *nameFun_M_S_Data_Form_s5(Term term) { return  "S-Data-Form$5" ; }
struct _ConstructionDescriptor descriptor_M_S_Data_Form_s5 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_S_Data_Form_s5), conBindOffs_M_S_Data_Form_s5, &nameFun_M_S_Data_Form_s5, &step_M_S_Data_Form_s5};

int step_M_S_Data_Form_s5(Sink sink__V126, Term term__V127)
{
  int term__V127_count = LINK_COUNT(term__V127); permitUnusedInt(term__V127_count);
  do {
    /* Contraction rule SORTS-S-Data-Form-3. */
    ASSERT(sink__V126->context, !strcmp(SYMBOL(term__V127),  "S-Data-Form$5" ));
    Term sub__V128 = LINK(sink__V126->context, SUB(term__V127, 0)); int sub__V128_count = term__V127_count*LINK_COUNT(sub__V128); permitUnusedInt(sub__V128_count);
    UNLINK_SUB(sink__V126->context, term__V127,  0); NORMALIZE(sink__V126->context, sub__V128); SUB(term__V127,  0) = LINK(sink__V126->context, sub__V128);
    /* sub__V128 = &#21 */
    Term sub__V129 = LINK(sink__V126->context, SUB(term__V127, 1)); int sub__V129_count = term__V127_count*LINK_COUNT(sub__V129); permitUnusedInt(sub__V129_count);
    /* sub__V129 = &#1 */
    
    NamedPropertyLink namedP__V130 = LINK_NamedPropertyLink(sink__V126->context, NAMED_PROPERTIES(term__V127));
    VariablePropertyLink varP__V131 = LINK_VariablePropertyLink(sink__V126->context, VARIABLE_PROPERTIES(term__V127));
    Hashset namedFV__V132 = LINK_VARIABLESET(sink__V126->context, asConstruction(term__V127)->properties->namedFreeVars);
    Hashset varFV__V133 = LINK_VARIABLESET(sink__V126->context, asConstruction(term__V127)->properties->variableFreeVars);
    UNLINK(sink__V126->context, term__V127);
    { START(sink__V126, _M__sTextCons);
      { START(sink__V126, _M__sTextChars);
        LITERAL(sink__V126,  "char *" ); END(sink__V126, _M__sTextChars); }
      { START(sink__V126, _M__sTextCons);
        { START(sink__V126, _M__sTextEmbed);
          { START(sink__V126, _M_AsText);
            { START(sink__V126, _M_Name);
              COPY(sink__V126, LINK(sink__V126->context, sub__V128));END(sink__V126, _M_Name); }
            END(sink__V126, _M_AsText); }
          END(sink__V126, _M__sTextEmbed); }
        { START(sink__V126, _M__sTextCons);
          { START(sink__V126, _M__sTextChars);
            LITERAL(sink__V126,  " = " ); END(sink__V126, _M__sTextChars); }
          { START(sink__V126, _M__sTextCons);
            { START(sink__V126, _M__sTextEmbed);
              { START(sink__V126, _M_AsText);
                { START(sink__V126, _M_STRING);
                  COPY(sink__V126, LINK(sink__V126->context, sub__V128));END(sink__V126, _M_STRING); }
                END(sink__V126, _M_AsText); }
              END(sink__V126, _M__sTextEmbed); }
            { START(sink__V126, _M__sTextCons);
              { START(sink__V126, _M__sTextChars);
                LITERAL(sink__V126,  ";" ); END(sink__V126, _M__sTextChars); }
              { START(sink__V126, _M__sTextCons);
                { START(sink__V126, _M__sTextBreak);
                  LITERAL(sink__V126,  "\n" ); END(sink__V126, _M__sTextBreak); }
                { START(sink__V126, _M__sTextCons);
                  { START(sink__V126, _M__sTextChars);
                    LITERAL(sink__V126,  "char *" ); END(sink__V126, _M__sTextChars); }
                  { START(sink__V126, _M__sTextCons);
                    { START(sink__V126, _M__sTextEmbed);
                      { START(sink__V126, _M_AsText);
                        { START(sink__V126, _M_NameFun);
                          COPY(sink__V126, LINK(sink__V126->context, sub__V128));END(sink__V126, _M_NameFun); }
                        END(sink__V126, _M_AsText); }
                      END(sink__V126, _M__sTextEmbed); }
                    { START(sink__V126, _M__sTextCons);
                      { START(sink__V126, _M__sTextChars);
                        LITERAL(sink__V126,  "(Term term) { return " );
                        END(sink__V126, _M__sTextChars); }
                      { START(sink__V126, _M__sTextCons);
                        { START(sink__V126, _M__sTextEmbed);
                          { START(sink__V126, _M_AsText);
                            { START(sink__V126, _M_Name);
                              COPY(sink__V126, LINK(sink__V126->context, sub__V128));END(sink__V126, _M_Name); }
                            END(sink__V126, _M_AsText); }
                          END(sink__V126, _M__sTextEmbed); }
                        { START(sink__V126, _M__sTextCons);
                          { START(sink__V126, _M__sTextChars);
                            LITERAL(sink__V126,  "; }" ); END(sink__V126, _M__sTextChars); }
                          { START(sink__V126, _M__sTextCons);
                            { START(sink__V126, _M__sTextBreak);
                              LITERAL(sink__V126,  "\n" ); END(sink__V126, _M__sTextBreak); }
                            { START(sink__V126, _M__sTextCons);
                              { START(sink__V126, _M__sTextChars);
                                LITERAL(sink__V126,  "struct _ConstructionDescriptor " );
                                END(sink__V126, _M__sTextChars); }
                              { START(sink__V126, _M__sTextCons);
                                { START(sink__V126, _M__sTextEmbed);
                                  { START(sink__V126, _M_AsText);
                                    { START(sink__V126, _M_Descriptor);
                                      COPY(sink__V126, LINK(sink__V126->context, sub__V128));END(sink__V126, _M_Descriptor); }
                                    END(sink__V126, _M_AsText); }
                                  END(sink__V126, _M__sTextEmbed); }
                                { START(sink__V126, _M__sTextCons);
                                  { START(sink__V126, _M__sTextChars);
                                    LITERAL(sink__V126,  " = {&" ); END(sink__V126, _M__sTextChars); }
                                  { START(sink__V126, _M__sTextCons);
                                    { START(sink__V126, _M__sTextEmbed);
                                      { START(sink__V126, _M_AsText);
                                        { START(sink__V126, _M_Sort);
                                          COPY(sink__V126, sub__V129);END(sink__V126, _M_Sort); }
                                        END(sink__V126, _M_AsText); }
                                      END(sink__V126, _M__sTextEmbed); }
                                    { START(sink__V126, _M__sTextCons);
                                      { START(sink__V126, _M__sTextChars);
                                        LITERAL(sink__V126,  ", " ); END(sink__V126, _M__sTextChars); }
                                      { START(sink__V126, _M__sTextCons);
                                        { START(sink__V126, _M__sTextEmbed);
                                          { START(sink__V126, _M_AsText);
                                            { START(sink__V126, _M_EnumTag);
                                              COPY(sink__V126, LINK(sink__V126->context, sub__V128));END(sink__V126, _M_EnumTag); }
                                            END(sink__V126, _M_AsText); }
                                          END(sink__V126, _M__sTextEmbed); }
                                        { START(sink__V126, _M__sTextCons);
                                          { START(sink__V126, _M__sTextChars);
                                            LITERAL(sink__V126,  ", 0, sizeof(STRUCT" );
                                            END(sink__V126, _M__sTextChars); }
                                          { START(sink__V126, _M__sTextCons);
                                            { START(sink__V126, _M__sTextEmbed);
                                              { START(sink__V126, _M_AsText);
                                                { START(sink__V126, _M_Struct);
                                                  COPY(sink__V126, LINK(sink__V126->context, sub__V128));END(sink__V126, _M_Struct); }
                                                END(sink__V126, _M_AsText); }
                                              END(sink__V126, _M__sTextEmbed); }
                                            { START(sink__V126, _M__sTextCons);
                                              { START(sink__V126, _M__sTextChars);
                                                LITERAL(sink__V126,  "), noBinderOffsets, &" );
                                                END(sink__V126, _M__sTextChars); }
                                              { START(sink__V126, _M__sTextCons);
                                                { START(sink__V126, _M__sTextEmbed);
                                                  { START(sink__V126, _M_AsText);
                                                    { START(sink__V126, _M_NameFun);
                                                      COPY(sink__V126, sub__V128);END(sink__V126, _M_NameFun); }
                                                    END(sink__V126, _M_AsText); }
                                                  END(sink__V126, _M__sTextEmbed); }
                                                { START(sink__V126, _M__sTextCons);
                                                  { START(sink__V126, _M__sTextChars);
                                                    LITERAL(sink__V126,  ", &dataStep};" );
                                                    END(sink__V126, _M__sTextChars); }
                                                  { START(sink__V126, _M__sTextCons);
                                                    { START(sink__V126, _M__sTextBreak);
                                                      LITERAL(sink__V126,  "\n" );
                                                      END(sink__V126, _M__sTextBreak); }
                                                    { START(sink__V126, _M__sTextNil);
                                                      END(sink__V126, _M__sTextNil); }
                                                    END(sink__V126, _M__sTextCons); }
                                                  END(sink__V126, _M__sTextCons); }
                                                END(sink__V126, _M__sTextCons); }
                                              END(sink__V126, _M__sTextCons); }
                                            END(sink__V126, _M__sTextCons); }
                                          END(sink__V126, _M__sTextCons); }
                                        END(sink__V126, _M__sTextCons); }
                                      END(sink__V126, _M__sTextCons); }
                                    END(sink__V126, _M__sTextCons); }
                                  END(sink__V126, _M__sTextCons); }
                                END(sink__V126, _M__sTextCons); }
                              END(sink__V126, _M__sTextCons); }
                            END(sink__V126, _M__sTextCons); }
                          END(sink__V126, _M__sTextCons); }
                        END(sink__V126, _M__sTextCons); }
                      END(sink__V126, _M__sTextCons); }
                    END(sink__V126, _M__sTextCons); }
                  END(sink__V126, _M__sTextCons); }
                END(sink__V126, _M__sTextCons); }
              END(sink__V126, _M__sTextCons); }
            END(sink__V126, _M__sTextCons); }
          END(sink__V126, _M__sTextCons); }
        END(sink__V126, _M__sTextCons); }
      END(sink__V126, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V126->context, namedFV__V132); UNLINK_VARIABLESET(sink__V126->context, varFV__V133);
    UNLINK_NamedPropertyLink(sink__V126->context, namedP__V130); UNLINK_VariablePropertyLink(sink__V126->context, varP__V131);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION S-Data-Form$6. */
int conBindOffs_M_S_Data_Form_s6[] = {0 , 0};
char *nameFun_M_S_Data_Form_s6(Term term) { return  "S-Data-Form$6" ; }
struct _ConstructionDescriptor descriptor_M_S_Data_Form_s6 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_S_Data_Form_s6), conBindOffs_M_S_Data_Form_s6, &nameFun_M_S_Data_Form_s6, &step_M_S_Data_Form_s6};

int step_M_S_Data_Form_s6(Sink sink__V134, Term term__V135)
{
  int term__V135_count = LINK_COUNT(term__V135); permitUnusedInt(term__V135_count);
  do {
    /* Contraction rule SORTS-S-Data-Form-2. */
    ASSERT(sink__V134->context, !strcmp(SYMBOL(term__V135),  "S-Data-Form$6" ));
    Term sub__V136 = SUB(term__V135, 0); permitUnusedTerm(sub__V136); int sub__V136_count = term__V135_count*LINK_COUNT(sub__V136); permitUnusedInt(sub__V136_count);
    /* sub__V136 = &#1 */
    
    NamedPropertyLink namedP__V137 = LINK_NamedPropertyLink(sink__V134->context, NAMED_PROPERTIES(term__V135));
    VariablePropertyLink varP__V138 = LINK_VariablePropertyLink(sink__V134->context, VARIABLE_PROPERTIES(term__V135));
    Hashset namedFV__V139 = LINK_VARIABLESET(sink__V134->context, asConstruction(term__V135)->properties->namedFreeVars);
    Hashset varFV__V140 = LINK_VARIABLESET(sink__V134->context, asConstruction(term__V135)->properties->variableFreeVars);
    UNLINK(sink__V134->context, term__V135);
    { START(sink__V134, _M__sTextNil); END(sink__V134, _M__sTextNil); }
    UNLINK_VARIABLESET(sink__V134->context, namedFV__V139); UNLINK_VARIABLESET(sink__V134->context, varFV__V140);
    UNLINK_NamedPropertyLink(sink__V134->context, namedP__V137); UNLINK_VariablePropertyLink(sink__V134->context, varP__V138);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION S-Data-Form$3. */
int conBindOffs_M_S_Data_Form_s3[] = {0 , 0 , 0 , 0};
char *nameFun_M_S_Data_Form_s3(Term term) { return  "S-Data-Form$3" ; }
struct _ConstructionDescriptor descriptor_M_S_Data_Form_s3 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_S_Data_Form_s3), conBindOffs_M_S_Data_Form_s3, &nameFun_M_S_Data_Form_s3, &step_M_S_Data_Form_s3};

int step_M_S_Data_Form_s3(Sink sink__V141, Term term__V142)
{
  int term__V142_count = LINK_COUNT(term__V142); permitUnusedInt(term__V142_count);
  Term sub__V143 = FORCE(sink__V141->context, SUB(term__V142, 0));
  EnumOf_M__sList choice__V144 = (IS_VARIABLE_USE(sub__V143) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V143));
  switch (choice__V144)
  {
    case Data_M__sNil: { /* Function SORTS-S-Data-Form-3$S-Data-Form$3$$Nil case $Nil */
      ASSERT(sink__V141->context, !strcmp(SYMBOL(term__V142),  "S-Data-Form$3" ));
      Term sub__V145 = SUB(term__V142, 0); permitUnusedTerm(sub__V145); int sub__V145_count = term__V142_count*LINK_COUNT(sub__V145); permitUnusedInt(sub__V145_count);
      ASSERT(sink__V141->context, !strcmp(SYMBOL(sub__V145),  "$Nil" ));
      Term sub__V146 = LINK(sink__V141->context, SUB(term__V142, 1)); int sub__V146_count = term__V142_count*LINK_COUNT(sub__V146); permitUnusedInt(sub__V146_count);
      /* sub__V146 = &#0 */
      Term sub__V147 = LINK(sink__V141->context, SUB(term__V142, 2)); int sub__V147_count = term__V142_count*LINK_COUNT(sub__V147); permitUnusedInt(sub__V147_count);
      /* sub__V147 = &#1 */
      
      NamedPropertyLink namedP__V148 = LINK_NamedPropertyLink(sink__V141->context, NAMED_PROPERTIES(term__V142));
      VariablePropertyLink varP__V149 = LINK_VariablePropertyLink(sink__V141->context, VARIABLE_PROPERTIES(term__V142));
      Hashset namedFV__V150 = LINK_VARIABLESET(sink__V141->context, asConstruction(term__V142)->properties->namedFreeVars);
      Hashset varFV__V151 = LINK_VARIABLESET(sink__V141->context, asConstruction(term__V142)->properties->variableFreeVars);
      UNLINK(sink__V141->context, term__V142);
      ADD_PROPERTIES(sink__V141, LINK_VARIABLESET(sink__V141->context, namedFV__V150), LINK_VARIABLESET(sink__V141->context, varFV__V151), LINK_NamedPropertyLink(sink__V141->context, namedP__V148), LINK_VariablePropertyLink(sink__V141->context, varP__V149));
      { START(sink__V141, _M_S_Data_Form_s5);
        COPY(sink__V141, sub__V146);COPY(sink__V141, sub__V147);END(sink__V141, _M_S_Data_Form_s5); }
      UNLINK_VARIABLESET(sink__V141->context, namedFV__V150); UNLINK_VARIABLESET(sink__V141->context, varFV__V151);
      UNLINK_NamedPropertyLink(sink__V141->context, namedP__V148); UNLINK_VariablePropertyLink(sink__V141->context, varP__V149);
      
      return 1;
    break; } case Data_M__sCons: { /* Function SORTS-S-Data-Form-4$S-Data-Form$3$$Cons case $Cons */
      ASSERT(sink__V141->context, !strcmp(SYMBOL(term__V142),  "S-Data-Form$3" ));
      Term sub__V152 = SUB(term__V142, 0); permitUnusedTerm(sub__V152); int sub__V152_count = term__V142_count*LINK_COUNT(sub__V152); permitUnusedInt(sub__V152_count);
      ASSERT(sink__V141->context, !strcmp(SYMBOL(sub__V152),  "$Cons" ));
      Term sub__V153 = LINK(sink__V141->context, SUB(sub__V152, 0)); int sub__V153_count = sub__V152_count*LINK_COUNT(sub__V153); permitUnusedInt(sub__V153_count);
      /* sub__V153 = &#0-0 */
      Term sub__V154 = LINK(sink__V141->context, SUB(sub__V152, 1)); int sub__V154_count = sub__V152_count*LINK_COUNT(sub__V154); permitUnusedInt(sub__V154_count);
      /* sub__V154 = &#0-1 */
      Term sub__V155 = LINK(sink__V141->context, SUB(term__V142, 1)); int sub__V155_count = term__V142_count*LINK_COUNT(sub__V155); permitUnusedInt(sub__V155_count);
      /* sub__V155 = &#2 */
      Term sub__V156 = LINK(sink__V141->context, SUB(term__V142, 2)); int sub__V156_count = term__V142_count*LINK_COUNT(sub__V156); permitUnusedInt(sub__V156_count);
      /* sub__V156 = &#3 */
      
      NamedPropertyLink namedP__V157 = LINK_NamedPropertyLink(sink__V141->context, NAMED_PROPERTIES(term__V142));
      VariablePropertyLink varP__V158 = LINK_VariablePropertyLink(sink__V141->context, VARIABLE_PROPERTIES(term__V142));
      Hashset namedFV__V159 = LINK_VARIABLESET(sink__V141->context, asConstruction(term__V142)->properties->namedFreeVars);
      Hashset varFV__V160 = LINK_VARIABLESET(sink__V141->context, asConstruction(term__V142)->properties->variableFreeVars);
      UNLINK(sink__V141->context, term__V142);
      ADD_PROPERTIES(sink__V141, LINK_VARIABLESET(sink__V141->context, namedFV__V159), LINK_VARIABLESET(sink__V141->context, varFV__V160), LINK_NamedPropertyLink(sink__V141->context, namedP__V157), LINK_VariablePropertyLink(sink__V141->context, varP__V158));
      { START(sink__V141, _M_S_Data_Form_s4);
        COPY(sink__V141, sub__V153);COPY(sink__V141, sub__V154);COPY(sink__V141, sub__V155);COPY(sink__V141, sub__V156);END(sink__V141, _M_S_Data_Form_s4); }
      UNLINK_VARIABLESET(sink__V141->context, namedFV__V159); UNLINK_VARIABLESET(sink__V141->context, varFV__V160);
      UNLINK_NamedPropertyLink(sink__V141->context, namedP__V157); UNLINK_VariablePropertyLink(sink__V141->context, varP__V158);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION S-Data-Form$4. */
int conBindOffs_M_S_Data_Form_s4[] = {0 , 0 , 0 , 0 , 0};
char *nameFun_M_S_Data_Form_s4(Term term) { return  "S-Data-Form$4" ; }
struct _ConstructionDescriptor descriptor_M_S_Data_Form_s4 = {&sort_M_Reified_xVariable, 0, 4, sizeof(STRUCT_Con_M_S_Data_Form_s4), conBindOffs_M_S_Data_Form_s4, &nameFun_M_S_Data_Form_s4, &step_M_S_Data_Form_s4};

int step_M_S_Data_Form_s4(Sink sink__V161, Term term__V162)
{
  int term__V162_count = LINK_COUNT(term__V162); permitUnusedInt(term__V162_count);
  do {
    /* Contraction rule SORTS-S-Data-Form-4. */
    ASSERT(sink__V161->context, !strcmp(SYMBOL(term__V162),  "S-Data-Form$4" ));
    Term sub__V163 = LINK(sink__V161->context, SUB(term__V162, 0)); int sub__V163_count = term__V162_count*LINK_COUNT(sub__V163); permitUnusedInt(sub__V163_count);
    UNLINK_SUB(sink__V161->context, term__V162,  0); NORMALIZE(sink__V161->context, sub__V163); SUB(term__V162,  0) = LINK(sink__V161->context, sub__V163);
    /* sub__V163 = &#221 */
    Term sub__V164 = LINK(sink__V161->context, SUB(term__V162, 1)); int sub__V164_count = term__V162_count*LINK_COUNT(sub__V164); permitUnusedInt(sub__V164_count);
    UNLINK_SUB(sink__V161->context, term__V162,  1); NORMALIZE(sink__V161->context, sub__V164); SUB(term__V162,  1) = LINK(sink__V161->context, sub__V164);
    /* sub__V164 = &#222 */
    Term sub__V165 = LINK(sink__V161->context, SUB(term__V162, 2)); int sub__V165_count = term__V162_count*LINK_COUNT(sub__V165); permitUnusedInt(sub__V165_count);
    UNLINK_SUB(sink__V161->context, term__V162,  2); NORMALIZE(sink__V161->context, sub__V165); SUB(term__V162,  2) = LINK(sink__V161->context, sub__V165);
    /* sub__V165 = &#21 */
    Term sub__V166 = LINK(sink__V161->context, SUB(term__V162, 3)); int sub__V166_count = term__V162_count*LINK_COUNT(sub__V166); permitUnusedInt(sub__V166_count);
    /* sub__V166 = &#1 */
    
    NamedPropertyLink namedP__V167 = LINK_NamedPropertyLink(sink__V161->context, NAMED_PROPERTIES(term__V162));
    VariablePropertyLink varP__V168 = LINK_VariablePropertyLink(sink__V161->context, VARIABLE_PROPERTIES(term__V162));
    Hashset namedFV__V169 = LINK_VARIABLESET(sink__V161->context, asConstruction(term__V162)->properties->namedFreeVars);
    Hashset varFV__V170 = LINK_VARIABLESET(sink__V161->context, asConstruction(term__V162)->properties->variableFreeVars);
    UNLINK(sink__V161->context, term__V162);
    { START(sink__V161, _M__sTextCons);
      { START(sink__V161, _M__sTextChars);
        LITERAL(sink__V161,  "int " ); END(sink__V161, _M__sTextChars); }
      { START(sink__V161, _M__sTextCons);
        { START(sink__V161, _M__sTextEmbed);
          { START(sink__V161, _M_AsText);
            { START(sink__V161, _M_BinderOffsets);
              COPY(sink__V161, LINK(sink__V161->context, sub__V165));END(sink__V161, _M_BinderOffsets); }
            END(sink__V161, _M_AsText); }
          END(sink__V161, _M__sTextEmbed); }
        { START(sink__V161, _M__sTextCons);
          { START(sink__V161, _M__sTextChars);
            LITERAL(sink__V161,  "[] = {0" ); END(sink__V161, _M__sTextChars); }
          { START(sink__V161, _M__sTextCons);
            { START(sink__V161, _M__sTextEmbed);
              { START(sink__V161, _M_AsText);
                { START(sink__V161, _M_DelayMapText_s1);
                  { START(sink__V161, _M_FormArguments__binder__offsets);
                    { START(sink__V161, _M__sCons);
                      COPY(sink__V161, sub__V163);COPY(sink__V161, LINK(sink__V161->context, sub__V164));END(sink__V161, _M__sCons); }
                    LITERAL(sink__V161,  "0" ); END(sink__V161, _M_FormArguments__binder__offsets); }
                  { Variable x__V171 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V161->context,"x__V171");
                    Variable x__V172 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V161->context,"x__V172");
                    Variable binds__V173[2] = {x__V171,x__V172}; BINDS(sink__V161, 2, binds__V173);
                    { START(sink__V161, _M__sTextCons);
                      { START(sink__V161, _M__sTextChars);
                        LITERAL(sink__V161,  " , " ); END(sink__V161, _M__sTextChars); }
                      { START(sink__V161, _M__sTextCons);
                        { START(sink__V161, _M__sTextEmbed);
                          { START(sink__V161, _M_AsText);
                            { START(sink__V161, _M_DINTEGER);
                              USE(sink__V161, x__V171); USE(sink__V161, x__V172); END(sink__V161, _M_DINTEGER); }
                            END(sink__V161, _M_AsText); }
                          END(sink__V161, _M__sTextEmbed); }
                        { START(sink__V161, _M__sTextNil);
                          END(sink__V161, _M__sTextNil); }
                        END(sink__V161, _M__sTextCons); }
                      END(sink__V161, _M__sTextCons); }
                     }
                  END(sink__V161, _M_DelayMapText_s1); }
                END(sink__V161, _M_AsText); }
              END(sink__V161, _M__sTextEmbed); }
            { START(sink__V161, _M__sTextCons);
              { START(sink__V161, _M__sTextChars);
                LITERAL(sink__V161,  "};" ); END(sink__V161, _M__sTextChars); }
              { START(sink__V161, _M__sTextCons);
                { START(sink__V161, _M__sTextBreak);
                  LITERAL(sink__V161,  "\n" ); END(sink__V161, _M__sTextBreak); }
                { START(sink__V161, _M__sTextCons);
                  { START(sink__V161, _M__sTextChars);
                    LITERAL(sink__V161,  "char *" ); END(sink__V161, _M__sTextChars); }
                  { START(sink__V161, _M__sTextCons);
                    { START(sink__V161, _M__sTextEmbed);
                      { START(sink__V161, _M_AsText);
                        { START(sink__V161, _M_Name);
                          COPY(sink__V161, LINK(sink__V161->context, sub__V165));END(sink__V161, _M_Name); }
                        END(sink__V161, _M_AsText); }
                      END(sink__V161, _M__sTextEmbed); }
                    { START(sink__V161, _M__sTextCons);
                      { START(sink__V161, _M__sTextChars);
                        LITERAL(sink__V161,  " = " ); END(sink__V161, _M__sTextChars); }
                      { START(sink__V161, _M__sTextCons);
                        { START(sink__V161, _M__sTextEmbed);
                          { START(sink__V161, _M_AsText);
                            { START(sink__V161, _M_STRING);
                              COPY(sink__V161, LINK(sink__V161->context, sub__V165));END(sink__V161, _M_STRING); }
                            END(sink__V161, _M_AsText); }
                          END(sink__V161, _M__sTextEmbed); }
                        { START(sink__V161, _M__sTextCons);
                          { START(sink__V161, _M__sTextChars);
                            LITERAL(sink__V161,  ";" ); END(sink__V161, _M__sTextChars); }
                          { START(sink__V161, _M__sTextCons);
                            { START(sink__V161, _M__sTextBreak);
                              LITERAL(sink__V161,  "\n" ); END(sink__V161, _M__sTextBreak); }
                            { START(sink__V161, _M__sTextCons);
                              { START(sink__V161, _M__sTextChars);
                                LITERAL(sink__V161,  "char *" ); END(sink__V161, _M__sTextChars); }
                              { START(sink__V161, _M__sTextCons);
                                { START(sink__V161, _M__sTextEmbed);
                                  { START(sink__V161, _M_AsText);
                                    { START(sink__V161, _M_NameFun);
                                      COPY(sink__V161, LINK(sink__V161->context, sub__V165));END(sink__V161, _M_NameFun); }
                                    END(sink__V161, _M_AsText); }
                                  END(sink__V161, _M__sTextEmbed); }
                                { START(sink__V161, _M__sTextCons);
                                  { START(sink__V161, _M__sTextChars);
                                    LITERAL(sink__V161,  "(Term term) { return " );
                                    END(sink__V161, _M__sTextChars); }
                                  { START(sink__V161, _M__sTextCons);
                                    { START(sink__V161, _M__sTextEmbed);
                                      { START(sink__V161, _M_AsText);
                                        { START(sink__V161, _M_Name);
                                          COPY(sink__V161, LINK(sink__V161->context, sub__V165));END(sink__V161, _M_Name); }
                                        END(sink__V161, _M_AsText); }
                                      END(sink__V161, _M__sTextEmbed); }
                                    { START(sink__V161, _M__sTextCons);
                                      { START(sink__V161, _M__sTextChars);
                                        LITERAL(sink__V161,  "; }" ); END(sink__V161, _M__sTextChars); }
                                      { START(sink__V161, _M__sTextCons);
                                        { START(sink__V161, _M__sTextBreak);
                                          LITERAL(sink__V161,  "\n" ); END(sink__V161, _M__sTextBreak); }
                                        { START(sink__V161, _M__sTextCons);
                                          { START(sink__V161, _M__sTextChars);
                                            LITERAL(sink__V161,  "struct _ConstructionDescriptor " );
                                            END(sink__V161, _M__sTextChars); }
                                          { START(sink__V161, _M__sTextCons);
                                            { START(sink__V161, _M__sTextEmbed);
                                              { START(sink__V161, _M_AsText);
                                                { START(sink__V161, _M_Descriptor);
                                                  COPY(sink__V161, LINK(sink__V161->context, sub__V165));END(sink__V161, _M_Descriptor); }
                                                END(sink__V161, _M_AsText); }
                                              END(sink__V161, _M__sTextEmbed); }
                                            { START(sink__V161, _M__sTextCons);
                                              { START(sink__V161, _M__sTextChars);
                                                LITERAL(sink__V161,  " = {&" );
                                                END(sink__V161, _M__sTextChars); }
                                              { START(sink__V161, _M__sTextCons);
                                                { START(sink__V161, _M__sTextEmbed);
                                                  { START(sink__V161, _M_AsText);
                                                    { START(sink__V161, _M_Sort);
                                                      COPY(sink__V161, sub__V166);END(sink__V161, _M_Sort); }
                                                    END(sink__V161, _M_AsText); }
                                                  END(sink__V161, _M__sTextEmbed); }
                                                { START(sink__V161, _M__sTextCons);
                                                  { START(sink__V161, _M__sTextChars);
                                                    LITERAL(sink__V161,  ", " );
                                                    END(sink__V161, _M__sTextChars); }
                                                  { START(sink__V161, _M__sTextCons);
                                                    { START(sink__V161, _M__sTextEmbed);
                                                      { START(sink__V161, _M_AsText);
                                                        { START(sink__V161, _M_EnumTag);
                                                          COPY(sink__V161, LINK(sink__V161->context, sub__V165));END(sink__V161, _M_EnumTag); }
                                                        END(sink__V161, _M_AsText); }
                                                      END(sink__V161, _M__sTextEmbed); }
                                                    { START(sink__V161, _M__sTextCons);
                                                      { START(sink__V161, _M__sTextChars);
                                                        LITERAL(sink__V161,  ", " );
                                                        END(sink__V161, _M__sTextChars); }
                                                      { START(sink__V161, _M__sTextCons);
                                                        { START(sink__V161, _M__sTextEmbed);
                                                          { START(sink__V161, _M_AsText);
                                                            { START(sink__V161, _M_INTEGER);
                                                              { START(sink__V161, _M_Length);
                                                                COPY(sink__V161, sub__V164);LITERAL(sink__V161,  "1" );
                                                                END(sink__V161, _M_Length); }
                                                              END(sink__V161, _M_INTEGER); }
                                                            END(sink__V161, _M_AsText); }
                                                          END(sink__V161, _M__sTextEmbed); }
                                                        { START(sink__V161, _M__sTextCons);
                                                          { START(sink__V161, _M__sTextChars);
                                                            LITERAL(sink__V161,  ", sizeof(STRUCT" );
                                                            END(sink__V161, _M__sTextChars); }
                                                          { START(sink__V161, _M__sTextCons);
                                                            { START(sink__V161, _M__sTextEmbed);
                                                              { START(sink__V161, _M_AsText);
                                                                { START(sink__V161, _M_Struct);
                                                                  COPY(sink__V161, LINK(sink__V161->context, sub__V165));END(sink__V161, _M_Struct); }
                                                                END(sink__V161, _M_AsText); }
                                                              END(sink__V161, _M__sTextEmbed); }
                                                            { START(sink__V161, _M__sTextCons);
                                                              { START(sink__V161, _M__sTextChars);
                                                                LITERAL(sink__V161,  "), " );
                                                                END(sink__V161, _M__sTextChars); }
                                                              { START(sink__V161, _M__sTextCons);
                                                                { START(sink__V161, _M__sTextEmbed);
                                                                  { START(sink__V161, _M_AsText);
                                                                    { START(sink__V161, _M_BinderOffsets);
                                                                      COPY(sink__V161, LINK(sink__V161->context, sub__V165));END(sink__V161, _M_BinderOffsets); }
                                                                    END(sink__V161, _M_AsText); }
                                                                  END(sink__V161, _M__sTextEmbed); }
                                                                { START(sink__V161, _M__sTextCons);
                                                                  { START(sink__V161, _M__sTextChars);
                                                                    LITERAL(sink__V161,  ", &" );
                                                                    END(sink__V161, _M__sTextChars); }
                                                                  { START(sink__V161, _M__sTextCons);
                                                                    { START(sink__V161, _M__sTextEmbed);
                                                                      { START(sink__V161, _M_AsText);
                                                                        { START(sink__V161, _M_NameFun);
                                                                          COPY(sink__V161, sub__V165);END(sink__V161, _M_NameFun); }
                                                                        END(sink__V161, _M_AsText); }
                                                                      END(sink__V161, _M__sTextEmbed); }
                                                                    { START(sink__V161, _M__sTextCons);
                                                                      { START(sink__V161, _M__sTextChars);
                                                                        LITERAL(sink__V161,  ", &dataStep};" );
                                                                        END(sink__V161, _M__sTextChars); }
                                                                      { START(sink__V161, _M__sTextCons);
                                                                        { START(sink__V161, _M__sTextBreak);
                                                                          LITERAL(sink__V161,  "\n" );
                                                                          END(sink__V161, _M__sTextBreak); }
                                                                        { START(sink__V161, _M__sTextNil);
                                                                          END(sink__V161, _M__sTextNil); }
                                                                        END(sink__V161, _M__sTextCons); }
                                                                      END(sink__V161, _M__sTextCons); }
                                                                    END(sink__V161, _M__sTextCons); }
                                                                  END(sink__V161, _M__sTextCons); }
                                                                END(sink__V161, _M__sTextCons); }
                                                              END(sink__V161, _M__sTextCons); }
                                                            END(sink__V161, _M__sTextCons); }
                                                          END(sink__V161, _M__sTextCons); }
                                                        END(sink__V161, _M__sTextCons); }
                                                      END(sink__V161, _M__sTextCons); }
                                                    END(sink__V161, _M__sTextCons); }
                                                  END(sink__V161, _M__sTextCons); }
                                                END(sink__V161, _M__sTextCons); }
                                              END(sink__V161, _M__sTextCons); }
                                            END(sink__V161, _M__sTextCons); }
                                          END(sink__V161, _M__sTextCons); }
                                        END(sink__V161, _M__sTextCons); }
                                      END(sink__V161, _M__sTextCons); }
                                    END(sink__V161, _M__sTextCons); }
                                  END(sink__V161, _M__sTextCons); }
                                END(sink__V161, _M__sTextCons); }
                              END(sink__V161, _M__sTextCons); }
                            END(sink__V161, _M__sTextCons); }
                          END(sink__V161, _M__sTextCons); }
                        END(sink__V161, _M__sTextCons); }
                      END(sink__V161, _M__sTextCons); }
                    END(sink__V161, _M__sTextCons); }
                  END(sink__V161, _M__sTextCons); }
                END(sink__V161, _M__sTextCons); }
              END(sink__V161, _M__sTextCons); }
            END(sink__V161, _M__sTextCons); }
          END(sink__V161, _M__sTextCons); }
        END(sink__V161, _M__sTextCons); }
      END(sink__V161, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V161->context, namedFV__V169); UNLINK_VARIABLESET(sink__V161->context, varFV__V170);
    UNLINK_NamedPropertyLink(sink__V161->context, namedP__V167); UNLINK_VariablePropertyLink(sink__V161->context, varP__V168);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION S-Data-Form$1. */
int conBindOffs_M_S_Data_Form_s1[] = {0 , 0 , 0};
char *nameFun_M_S_Data_Form_s1(Term term) { return  "S-Data-Form$1" ; }
struct _ConstructionDescriptor descriptor_M_S_Data_Form_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_S_Data_Form_s1), conBindOffs_M_S_Data_Form_s1, &nameFun_M_S_Data_Form_s1, &step_M_S_Data_Form_s1};

int step_M_S_Data_Form_s1(Sink sink__V174, Term term__V175)
{
  int term__V175_count = LINK_COUNT(term__V175); permitUnusedInt(term__V175_count);
  Term sub__V176 = FORCE(sink__V174->context, SUB(term__V175, 0));
  EnumOf_M_Reified_xForm choice__V177 = (IS_VARIABLE_USE(sub__V176) ? VarOf_M_Reified_xForm : (EnumOf_M_Reified_xForm) TAG(sub__V176));
  switch (choice__V177)
  {
    case Data_M_SORT_SET: { /* Function SORTS-S-Data-Form-1$S-Data-Form$1$SORT-SET case SORT-SET */
      ASSERT(sink__V174->context, !strcmp(SYMBOL(term__V175),  "S-Data-Form$1" ));
      Term sub__V178 = SUB(term__V175, 0); permitUnusedTerm(sub__V178); int sub__V178_count = term__V175_count*LINK_COUNT(sub__V178); permitUnusedInt(sub__V178_count);
      CRSX_CHECK_SORT(sink__V174->context, sub__V178, &sort_M_Reified_xForm); ASSERT(sink__V174->context, !strcmp(SYMBOL(sub__V178),  "SORT-SET" ));
      Term sub__V179 = LINK(sink__V174->context, SUB(sub__V178, 0)); int sub__V179_count = sub__V178_count*LINK_COUNT(sub__V179); permitUnusedInt(sub__V179_count);
      CRSX_CHECK_SORT(sink__V174->context, sub__V179, &sort_M_Reified_xSort); /* sub__V179 = &#0-0 */
      Term sub__V180 = LINK(sink__V174->context, SUB(sub__V178, 1)); int sub__V180_count = sub__V178_count*LINK_COUNT(sub__V180); permitUnusedInt(sub__V180_count);
      CRSX_CHECK_SORT(sink__V174->context, sub__V180, &sort_M_Reified_xSort); /* sub__V180 = &#0-1 */
      Term sub__V181 = LINK(sink__V174->context, SUB(sub__V178, 2)); int sub__V181_count = sub__V178_count*LINK_COUNT(sub__V181); permitUnusedInt(sub__V181_count);
      CRSX_CHECK_SORT(sink__V174->context, sub__V181, &sort_M_Reified_xForm); /* sub__V181 = &#0-2 */
      Term sub__V182 = LINK(sink__V174->context, SUB(term__V175, 1)); int sub__V182_count = term__V175_count*LINK_COUNT(sub__V182); permitUnusedInt(sub__V182_count);
      /* sub__V182 = &#3 */
      
      NamedPropertyLink namedP__V183 = LINK_NamedPropertyLink(sink__V174->context, NAMED_PROPERTIES(term__V175));
      VariablePropertyLink varP__V184 = LINK_VariablePropertyLink(sink__V174->context, VARIABLE_PROPERTIES(term__V175));
      Hashset namedFV__V185 = LINK_VARIABLESET(sink__V174->context, asConstruction(term__V175)->properties->namedFreeVars);
      Hashset varFV__V186 = LINK_VARIABLESET(sink__V174->context, asConstruction(term__V175)->properties->variableFreeVars);
      UNLINK(sink__V174->context, term__V175);
      ADD_PROPERTIES(sink__V174, LINK_VARIABLESET(sink__V174->context, namedFV__V185), LINK_VARIABLESET(sink__V174->context, varFV__V186), LINK_NamedPropertyLink(sink__V174->context, namedP__V183), LINK_VariablePropertyLink(sink__V174->context, varP__V184));
      { START(sink__V174, _M_S_Data_Form_s7);
        COPY(sink__V174, sub__V179);COPY(sink__V174, sub__V180);COPY(sink__V174, sub__V181);COPY(sink__V174, sub__V182);END(sink__V174, _M_S_Data_Form_s7); }
      UNLINK_VARIABLESET(sink__V174->context, namedFV__V185); UNLINK_VARIABLESET(sink__V174->context, varFV__V186);
      UNLINK_NamedPropertyLink(sink__V174->context, namedP__V183); UNLINK_VariablePropertyLink(sink__V174->context, varP__V184);
      
      return 1;
    break; } case Data_M_SORT_ALLOWS_VARIABLES: { /* Function SORTS-S-Data-Form-2$S-Data-Form$1$SORT-ALLOWS-VARIABLES case SORT-ALLOWS-VARIABLES */
      ASSERT(sink__V174->context, !strcmp(SYMBOL(term__V175),  "S-Data-Form$1" ));
      Term sub__V187 = SUB(term__V175, 0); permitUnusedTerm(sub__V187); int sub__V187_count = term__V175_count*LINK_COUNT(sub__V187); permitUnusedInt(sub__V187_count);
      CRSX_CHECK_SORT(sink__V174->context, sub__V187, &sort_M_Reified_xForm); ASSERT(sink__V174->context, !strcmp(SYMBOL(sub__V187),  "SORT-ALLOWS-VARIABLES" ));
      Term sub__V188 = LINK(sink__V174->context, SUB(term__V175, 1)); int sub__V188_count = term__V175_count*LINK_COUNT(sub__V188); permitUnusedInt(sub__V188_count);
      /* sub__V188 = &#0 */
      
      NamedPropertyLink namedP__V189 = LINK_NamedPropertyLink(sink__V174->context, NAMED_PROPERTIES(term__V175));
      VariablePropertyLink varP__V190 = LINK_VariablePropertyLink(sink__V174->context, VARIABLE_PROPERTIES(term__V175));
      Hashset namedFV__V191 = LINK_VARIABLESET(sink__V174->context, asConstruction(term__V175)->properties->namedFreeVars);
      Hashset varFV__V192 = LINK_VARIABLESET(sink__V174->context, asConstruction(term__V175)->properties->variableFreeVars);
      UNLINK(sink__V174->context, term__V175);
      ADD_PROPERTIES(sink__V174, LINK_VARIABLESET(sink__V174->context, namedFV__V191), LINK_VARIABLESET(sink__V174->context, varFV__V192), LINK_NamedPropertyLink(sink__V174->context, namedP__V189), LINK_VariablePropertyLink(sink__V174->context, varP__V190));
      { START(sink__V174, _M_S_Data_Form_s6);
        COPY(sink__V174, sub__V188);END(sink__V174, _M_S_Data_Form_s6); }
      UNLINK_VARIABLESET(sink__V174->context, namedFV__V191); UNLINK_VARIABLESET(sink__V174->context, varFV__V192);
      UNLINK_NamedPropertyLink(sink__V174->context, namedP__V189); UNLINK_VariablePropertyLink(sink__V174->context, varP__V190);
      
      return 1;
    break; } case Data_M_FORM: { /* Function SORTS-S-Data-Form-3$S-Data-Form$1$FORM case FORM */
      ASSERT(sink__V174->context, !strcmp(SYMBOL(term__V175),  "S-Data-Form$1" ));
      Term sub__V193 = SUB(term__V175, 0); permitUnusedTerm(sub__V193); int sub__V193_count = term__V175_count*LINK_COUNT(sub__V193); permitUnusedInt(sub__V193_count);
      CRSX_CHECK_SORT(sink__V174->context, sub__V193, &sort_M_Reified_xForm); ASSERT(sink__V174->context, !strcmp(SYMBOL(sub__V193),  "FORM" ));
      Term sub__V194 = LINK(sink__V174->context, SUB(sub__V193, 0)); int sub__V194_count = sub__V193_count*LINK_COUNT(sub__V194); permitUnusedInt(sub__V194_count);
      /* sub__V194 = &#0-0 */
      Term sub__V195 = LINK(sink__V174->context, SUB(sub__V193, 1)); int sub__V195_count = sub__V193_count*LINK_COUNT(sub__V195); permitUnusedInt(sub__V195_count);
      /* sub__V195 = &#0-1 */
      Term sub__V196 = LINK(sink__V174->context, SUB(term__V175, 1)); int sub__V196_count = term__V175_count*LINK_COUNT(sub__V196); permitUnusedInt(sub__V196_count);
      /* sub__V196 = &#2 */
      
      NamedPropertyLink namedP__V197 = LINK_NamedPropertyLink(sink__V174->context, NAMED_PROPERTIES(term__V175));
      VariablePropertyLink varP__V198 = LINK_VariablePropertyLink(sink__V174->context, VARIABLE_PROPERTIES(term__V175));
      Hashset namedFV__V199 = LINK_VARIABLESET(sink__V174->context, asConstruction(term__V175)->properties->namedFreeVars);
      Hashset varFV__V200 = LINK_VARIABLESET(sink__V174->context, asConstruction(term__V175)->properties->variableFreeVars);
      UNLINK(sink__V174->context, term__V175);
      ADD_PROPERTIES(sink__V174, LINK_VARIABLESET(sink__V174->context, namedFV__V199), LINK_VARIABLESET(sink__V174->context, varFV__V200), LINK_NamedPropertyLink(sink__V174->context, namedP__V197), LINK_VariablePropertyLink(sink__V174->context, varP__V198));
      { START(sink__V174, _M_S_Data_Form_s3);
        COPY(sink__V174, sub__V195);COPY(sink__V174, sub__V194);COPY(sink__V174, sub__V196);END(sink__V174, _M_S_Data_Form_s3); }
      UNLINK_VARIABLESET(sink__V174->context, namedFV__V199); UNLINK_VARIABLESET(sink__V174->context, varFV__V200);
      UNLINK_NamedPropertyLink(sink__V174->context, namedP__V197); UNLINK_VariablePropertyLink(sink__V174->context, varP__V198);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION ComputeSorts. */
int conBindOffs_M_ComputeSorts[] = {0 , 0};
char *nameFun_M_ComputeSorts(Term term) { return  "ComputeSorts" ; }
struct _ConstructionDescriptor descriptor_M_ComputeSorts = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_ComputeSorts), conBindOffs_M_ComputeSorts, &nameFun_M_ComputeSorts, &step_M_ComputeSorts};

int step_M_ComputeSorts(Sink sink__V201, Term term__V202)
{
  int term__V202_count = LINK_COUNT(term__V202); permitUnusedInt(term__V202_count);
  Term sub__V203 = FORCE(sink__V201->context, SUB(term__V202, 0));
  EnumOf_M_Reify_xCRSX choice__V204 = (IS_VARIABLE_USE(sub__V203) ? VarOf_M_Reify_xCRSX : (EnumOf_M_Reify_xCRSX) TAG(sub__V203));
  switch (choice__V204)
  {
    case Data_M_CRSX: { /* Function SORTS-Crsx$ComputeSorts$CRSX case CRSX */
      ASSERT(sink__V201->context, !strcmp(SYMBOL(term__V202),  "ComputeSorts" ));
      Term sub__V205 = SUB(term__V202, 0); permitUnusedTerm(sub__V205); int sub__V205_count = term__V202_count*LINK_COUNT(sub__V205); permitUnusedInt(sub__V205_count);
      CRSX_CHECK_SORT(sink__V201->context, sub__V205, &sort_M_Reify_xCRSX); ASSERT(sink__V201->context, !strcmp(SYMBOL(sub__V205),  "CRSX" ));
      Term sub__V206 = LINK(sink__V201->context, SUB(sub__V205, 0)); int sub__V206_count = sub__V205_count*LINK_COUNT(sub__V206); permitUnusedInt(sub__V206_count);
      /* sub__V206 = &#0-0 */
      Term sub__V207 = LINK(sink__V201->context, SUB(sub__V205, 1)); int sub__V207_count = sub__V205_count*LINK_COUNT(sub__V207); permitUnusedInt(sub__V207_count);
      /* sub__V207 = &#0-1 */
      
      NamedPropertyLink namedP__V208 = LINK_NamedPropertyLink(sink__V201->context, NAMED_PROPERTIES(term__V202));
      VariablePropertyLink varP__V209 = LINK_VariablePropertyLink(sink__V201->context, VARIABLE_PROPERTIES(term__V202));
      Hashset namedFV__V210 = LINK_VARIABLESET(sink__V201->context, asConstruction(term__V202)->properties->namedFreeVars);
      Hashset varFV__V211 = LINK_VARIABLESET(sink__V201->context, asConstruction(term__V202)->properties->variableFreeVars);
      UNLINK(sink__V201->context, term__V202);
      ADD_PROPERTIES(sink__V201, LINK_VARIABLESET(sink__V201->context, namedFV__V210), LINK_VARIABLESET(sink__V201->context, varFV__V211), LINK_NamedPropertyLink(sink__V201->context, namedP__V208), LINK_VariablePropertyLink(sink__V201->context, varP__V209));
      { START(sink__V201, _M_ComputeSorts_s1);
        COPY(sink__V201, sub__V206);COPY(sink__V201, sub__V207);END(sink__V201, _M_ComputeSorts_s1); }
      UNLINK_VARIABLESET(sink__V201->context, namedFV__V210); UNLINK_VARIABLESET(sink__V201->context, varFV__V211);
      UNLINK_NamedPropertyLink(sink__V201->context, namedP__V208); UNLINK_VariablePropertyLink(sink__V201->context, varP__V209);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION S-Data. */
int conBindOffs_M_S_Data[] = {0 , 0 , 0};
char *nameFun_M_S_Data(Term term) { return  "S-Data" ; }
struct _ConstructionDescriptor descriptor_M_S_Data = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_S_Data), conBindOffs_M_S_Data, &nameFun_M_S_Data, &step_M_S_Data};

int step_M_S_Data(Sink sink__V212, Term term__V213)
{
  int term__V213_count = LINK_COUNT(term__V213); permitUnusedInt(term__V213_count);
  Term sub__V214 = FORCE(sink__V212->context, SUB(term__V213, 0));
  EnumOf_M_Reified_xSort choice__V215 = (IS_VARIABLE_USE(sub__V214) ? VarOf_M_Reified_xSort : (EnumOf_M_Reified_xSort) TAG(sub__V214));
  switch (choice__V215)
  {
    case Data_M_SORT: { /* Function SORTS-S-Data-1$S-Data$SORT case SORT */
      ASSERT(sink__V212->context, !strcmp(SYMBOL(term__V213),  "S-Data" ));
      Term sub__V216 = SUB(term__V213, 0); permitUnusedTerm(sub__V216); int sub__V216_count = term__V213_count*LINK_COUNT(sub__V216); permitUnusedInt(sub__V216_count);
      CRSX_CHECK_SORT(sink__V212->context, sub__V216, &sort_M_Reified_xSort); ASSERT(sink__V212->context, !strcmp(SYMBOL(sub__V216),  "SORT" ));
      Term sub__V217 = LINK(sink__V212->context, SUB(sub__V216, 0)); int sub__V217_count = sub__V216_count*LINK_COUNT(sub__V217); permitUnusedInt(sub__V217_count);
      /* sub__V217 = &#0-0 */
      Term sub__V218 = LINK(sink__V212->context, SUB(sub__V216, 1)); int sub__V218_count = sub__V216_count*LINK_COUNT(sub__V218); permitUnusedInt(sub__V218_count);
      /* sub__V218 = &#0-1 */
      Term sub__V219 = LINK(sink__V212->context, SUB(term__V213, 1)); int sub__V219_count = term__V213_count*LINK_COUNT(sub__V219); permitUnusedInt(sub__V219_count);
      /* sub__V219 = &#2 */
      
      NamedPropertyLink namedP__V220 = LINK_NamedPropertyLink(sink__V212->context, NAMED_PROPERTIES(term__V213));
      VariablePropertyLink varP__V221 = LINK_VariablePropertyLink(sink__V212->context, VARIABLE_PROPERTIES(term__V213));
      Hashset namedFV__V222 = LINK_VARIABLESET(sink__V212->context, asConstruction(term__V213)->properties->namedFreeVars);
      Hashset varFV__V223 = LINK_VARIABLESET(sink__V212->context, asConstruction(term__V213)->properties->variableFreeVars);
      UNLINK(sink__V212->context, term__V213);
      ADD_PROPERTIES(sink__V212, LINK_VARIABLESET(sink__V212->context, namedFV__V222), LINK_VARIABLESET(sink__V212->context, varFV__V223), LINK_NamedPropertyLink(sink__V212->context, namedP__V220), LINK_VariablePropertyLink(sink__V212->context, varP__V221));
      { START(sink__V212, _M_S_Data_s1);
        COPY(sink__V212, sub__V217);COPY(sink__V212, sub__V218);COPY(sink__V212, sub__V219);END(sink__V212, _M_S_Data_s1); }
      UNLINK_VARIABLESET(sink__V212->context, namedFV__V222); UNLINK_VARIABLESET(sink__V212->context, varFV__V223);
      UNLINK_NamedPropertyLink(sink__V212->context, namedP__V220); UNLINK_VariablePropertyLink(sink__V212->context, varP__V221);
      
      return 1;
    break; } case Data_M_SORT_PROPERTY: { /* Function SORTS-S-Data-2$S-Data$SORT-PROPERTY case SORT-PROPERTY */
      ASSERT(sink__V212->context, !strcmp(SYMBOL(term__V213),  "S-Data" ));
      Term sub__V224 = SUB(term__V213, 0); permitUnusedTerm(sub__V224); int sub__V224_count = term__V213_count*LINK_COUNT(sub__V224); permitUnusedInt(sub__V224_count);
      CRSX_CHECK_SORT(sink__V212->context, sub__V224, &sort_M_Reified_xSort); ASSERT(sink__V212->context, !strcmp(SYMBOL(sub__V224),  "SORT-PROPERTY" ));
      Term sub__V225 = LINK(sink__V212->context, SUB(sub__V224, 0)); int sub__V225_count = sub__V224_count*LINK_COUNT(sub__V225); permitUnusedInt(sub__V225_count);
      CRSX_CHECK_SORT(sink__V212->context, sub__V225, &sort_M_Reified_xSort); /* sub__V225 = &#0-0 */
      Term sub__V226 = LINK(sink__V212->context, SUB(sub__V224, 1)); int sub__V226_count = sub__V224_count*LINK_COUNT(sub__V226); permitUnusedInt(sub__V226_count);
      CRSX_CHECK_SORT(sink__V212->context, sub__V226, &sort_M_Reified_xSort); /* sub__V226 = &#0-1 */
      Term sub__V227 = LINK(sink__V212->context, SUB(sub__V224, 2)); int sub__V227_count = sub__V224_count*LINK_COUNT(sub__V227); permitUnusedInt(sub__V227_count);
      CRSX_CHECK_SORT(sink__V212->context, sub__V227, &sort_M_Reified_xSort); /* sub__V227 = &#0-2 */
      Term sub__V228 = LINK(sink__V212->context, SUB(term__V213, 1)); int sub__V228_count = term__V213_count*LINK_COUNT(sub__V228); permitUnusedInt(sub__V228_count);
      /* sub__V228 = &#3 */
      
      NamedPropertyLink namedP__V229 = LINK_NamedPropertyLink(sink__V212->context, NAMED_PROPERTIES(term__V213));
      VariablePropertyLink varP__V230 = LINK_VariablePropertyLink(sink__V212->context, VARIABLE_PROPERTIES(term__V213));
      Hashset namedFV__V231 = LINK_VARIABLESET(sink__V212->context, asConstruction(term__V213)->properties->namedFreeVars);
      Hashset varFV__V232 = LINK_VARIABLESET(sink__V212->context, asConstruction(term__V213)->properties->variableFreeVars);
      UNLINK(sink__V212->context, term__V213);
      ADD_PROPERTIES(sink__V212, LINK_VARIABLESET(sink__V212->context, namedFV__V231), LINK_VARIABLESET(sink__V212->context, varFV__V232), LINK_NamedPropertyLink(sink__V212->context, namedP__V229), LINK_VariablePropertyLink(sink__V212->context, varP__V230));
      { START(sink__V212, _M_S_Data_s2);
        COPY(sink__V212, sub__V225);COPY(sink__V212, sub__V226);COPY(sink__V212, sub__V227);COPY(sink__V212, sub__V228);END(sink__V212, _M_S_Data_s2); }
      UNLINK_VARIABLESET(sink__V212->context, namedFV__V231); UNLINK_VARIABLESET(sink__V212->context, varFV__V232);
      UNLINK_NamedPropertyLink(sink__V212->context, namedP__V229); UNLINK_VariablePropertyLink(sink__V212->context, varP__V230);
      
      return 1;
    } default: break;
  }
  return 0;
}

#ifdef __cplusplus
}
#endif
/* END OF C RULES FOR CRSX CRSXC MODULE SORTS. */
