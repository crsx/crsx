/* C RULES FOR CRSX CRSXC MODULE SORTS. */
#include "CRSXC.h" 
#ifdef __cplusplus
extern "C" {
#endif

/* FUNCTION S-Data. */
int conBindOffs_M_S_Data[] = {0 , 0 , 0};
char *nameFun_M_S_Data(Term term) { return  "S-Data" ; }
struct _ConstructionDescriptor descriptor_M_S_Data = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_S_Data), conBindOffs_M_S_Data, &nameFun_M_S_Data, &step_M_S_Data};

int step_M_S_Data(Sink sink__V1, Term term__V2)
{
  int term__V2_count = LINK_COUNT(term__V2); permitUnusedInt(term__V2_count);
  Term sub__V3 = FORCE(sink__V1->context, SUB(term__V2, 0));
  EnumOf_M_Reified_xSort choice__V4 = (IS_VARIABLE_USE(sub__V3) ? VarOf_M_Reified_xSort : (EnumOf_M_Reified_xSort) TAG(sub__V3));
  switch (choice__V4)
  {
    case Data_M_SORT: { /* Function SORTS-S-Data-1$S-Data$SORT case SORT */
      ASSERT(sink__V1->context, !strcmp(SYMBOL(term__V2),  "S-Data" ));
      Term sub__V5 = SUB(term__V2, 0); permitUnusedTerm(sub__V5); int sub__V5_count = term__V2_count*LINK_COUNT(sub__V5); permitUnusedInt(sub__V5_count);
      CRSX_CHECK_SORT(sink__V1->context, sub__V5, &sort_M_Reified_xSort); ASSERT(sink__V1->context, !strcmp(SYMBOL(sub__V5),  "SORT" ));
      Term sub__V6 = LINK(sink__V1->context, SUB(sub__V5, 0)); int sub__V6_count = sub__V5_count*LINK_COUNT(sub__V6); permitUnusedInt(sub__V6_count);
      /* sub__V6 = &#0-0 */
      Term sub__V7 = LINK(sink__V1->context, SUB(sub__V5, 1)); int sub__V7_count = sub__V5_count*LINK_COUNT(sub__V7); permitUnusedInt(sub__V7_count);
      /* sub__V7 = &#0-1 */
      Term sub__V8 = LINK(sink__V1->context, SUB(term__V2, 1)); int sub__V8_count = term__V2_count*LINK_COUNT(sub__V8); permitUnusedInt(sub__V8_count);
      /* sub__V8 = &#2 */
      
      NamedPropertyLink namedP__V9 = LINK_NamedPropertyLink(sink__V1->context, NAMED_PROPERTIES(term__V2));
      VariablePropertyLink varP__V10 = LINK_VariablePropertyLink(sink__V1->context, VARIABLE_PROPERTIES(term__V2));
      Hashset namedFV__V11 = LINK_VARIABLESET(sink__V1->context, asConstruction(term__V2)->nfvs);
      Hashset varFV__V12 = LINK_VARIABLESET(sink__V1->context, variablePropertyFreeVars(varP__V10));
      UNLINK(sink__V1->context, term__V2);
      ADD_PROPERTIES(sink__V1, LINK_VARIABLESET(sink__V1->context, namedFV__V11), LINK_VARIABLESET(sink__V1->context, varFV__V12), LINK_NamedPropertyLink(sink__V1->context, namedP__V9), LINK_VariablePropertyLink(sink__V1->context, varP__V10));
      { START(sink__V1, _M_S_Data_s1);
        COPY(sink__V1, sub__V6);COPY(sink__V1, sub__V7);COPY(sink__V1, sub__V8);END(sink__V1, _M_S_Data_s1); }
      UNLINK_VARIABLESET(sink__V1->context, namedFV__V11); UNLINK_VARIABLESET(sink__V1->context, varFV__V12);
      UNLINK_NamedPropertyLink(sink__V1->context, namedP__V9); UNLINK_VariablePropertyLink(sink__V1->context, varP__V10);
      
      return 1;
    break; } case Data_M_SORT_PROPERTY: { /* Function SORTS-S-Data-2$S-Data$SORT-PROPERTY case SORT-PROPERTY */
      ASSERT(sink__V1->context, !strcmp(SYMBOL(term__V2),  "S-Data" ));
      Term sub__V13 = SUB(term__V2, 0); permitUnusedTerm(sub__V13); int sub__V13_count = term__V2_count*LINK_COUNT(sub__V13); permitUnusedInt(sub__V13_count);
      CRSX_CHECK_SORT(sink__V1->context, sub__V13, &sort_M_Reified_xSort); ASSERT(sink__V1->context, !strcmp(SYMBOL(sub__V13),  "SORT-PROPERTY" ));
      Term sub__V14 = LINK(sink__V1->context, SUB(sub__V13, 0)); int sub__V14_count = sub__V13_count*LINK_COUNT(sub__V14); permitUnusedInt(sub__V14_count);
      CRSX_CHECK_SORT(sink__V1->context, sub__V14, &sort_M_Reified_xSort); /* sub__V14 = &#0-0 */
      Term sub__V15 = LINK(sink__V1->context, SUB(sub__V13, 1)); int sub__V15_count = sub__V13_count*LINK_COUNT(sub__V15); permitUnusedInt(sub__V15_count);
      CRSX_CHECK_SORT(sink__V1->context, sub__V15, &sort_M_Reified_xSort); /* sub__V15 = &#0-1 */
      Term sub__V16 = LINK(sink__V1->context, SUB(sub__V13, 2)); int sub__V16_count = sub__V13_count*LINK_COUNT(sub__V16); permitUnusedInt(sub__V16_count);
      CRSX_CHECK_SORT(sink__V1->context, sub__V16, &sort_M_Reified_xSort); /* sub__V16 = &#0-2 */
      Term sub__V17 = LINK(sink__V1->context, SUB(term__V2, 1)); int sub__V17_count = term__V2_count*LINK_COUNT(sub__V17); permitUnusedInt(sub__V17_count);
      /* sub__V17 = &#3 */
      
      NamedPropertyLink namedP__V18 = LINK_NamedPropertyLink(sink__V1->context, NAMED_PROPERTIES(term__V2));
      VariablePropertyLink varP__V19 = LINK_VariablePropertyLink(sink__V1->context, VARIABLE_PROPERTIES(term__V2));
      Hashset namedFV__V20 = LINK_VARIABLESET(sink__V1->context, asConstruction(term__V2)->nfvs);
      Hashset varFV__V21 = LINK_VARIABLESET(sink__V1->context, variablePropertyFreeVars(varP__V19));
      UNLINK(sink__V1->context, term__V2);
      ADD_PROPERTIES(sink__V1, LINK_VARIABLESET(sink__V1->context, namedFV__V20), LINK_VARIABLESET(sink__V1->context, varFV__V21), LINK_NamedPropertyLink(sink__V1->context, namedP__V18), LINK_VariablePropertyLink(sink__V1->context, varP__V19));
      { START(sink__V1, _M_S_Data_s2);
        COPY(sink__V1, sub__V14);COPY(sink__V1, sub__V15);COPY(sink__V1, sub__V16);COPY(sink__V1, sub__V17);END(sink__V1, _M_S_Data_s2); }
      UNLINK_VARIABLESET(sink__V1->context, namedFV__V20); UNLINK_VARIABLESET(sink__V1->context, varFV__V21);
      UNLINK_NamedPropertyLink(sink__V1->context, namedP__V18); UNLINK_VariablePropertyLink(sink__V1->context, varP__V19);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION ComputeSorts$1. */
int conBindOffs_M_ComputeSorts_s1[] = {0 , 0 , 0};
char *nameFun_M_ComputeSorts_s1(Term term) { return  "ComputeSorts$1" ; }
struct _ConstructionDescriptor descriptor_M_ComputeSorts_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_ComputeSorts_s1), conBindOffs_M_ComputeSorts_s1, &nameFun_M_ComputeSorts_s1, &step_M_ComputeSorts_s1};

int step_M_ComputeSorts_s1(Sink sink__V22, Term term__V23)
{
  int term__V23_count = LINK_COUNT(term__V23); permitUnusedInt(term__V23_count);
  do {
    /* Contraction rule SORTS-Crsx. */
    ASSERT(sink__V22->context, !strcmp(SYMBOL(term__V23),  "ComputeSorts$1" ));
    Term sub__V24 = LINK(sink__V22->context, SUB(term__V23, 0)); int sub__V24_count = term__V23_count*LINK_COUNT(sub__V24); permitUnusedInt(sub__V24_count);
    UNLINK_SUB(sink__V22->context, term__V23,  0); NORMALIZE(sink__V22->context, sub__V24); SUB(term__V23,  0) = LINK(sink__V22->context, sub__V24);
    /* sub__V24 = &#11 */
    Term sub__V25 = LINK(sink__V22->context, SUB(term__V23, 1)); int sub__V25_count = term__V23_count*LINK_COUNT(sub__V25); permitUnusedInt(sub__V25_count);
    /* sub__V25 = &#12 */
    
    NamedPropertyLink namedP__V26 = LINK_NamedPropertyLink(sink__V22->context, NAMED_PROPERTIES(term__V23));
    VariablePropertyLink varP__V27 = LINK_VariablePropertyLink(sink__V22->context, VARIABLE_PROPERTIES(term__V23));
    Hashset namedFV__V28 = LINK_VARIABLESET(sink__V22->context, asConstruction(term__V23)->nfvs);
    Hashset varFV__V29 = LINK_VARIABLESET(sink__V22->context, variablePropertyFreeVars(varP__V27));
    UNLINK(sink__V22->context, term__V23);
    { START(sink__V22, _M__sTextCons);
      { START(sink__V22, _M__sTextChars);
        LITERAL(sink__V22,  "/* C SORT DESCRIPTORS FOR CRSX " ); END(sink__V22, _M__sTextChars); }
      { START(sink__V22, _M__sTextCons);
        { START(sink__V22, _M__sTextEmbed);
          { START(sink__V22, _M_AsText);
            { START(sink__V22, _M_TOKEN);
              COPY(sink__V22, LINK(sink__V22->context, sub__V24));END(sink__V22, _M_TOKEN); }
            END(sink__V22, _M_AsText); }
          END(sink__V22, _M__sTextEmbed); }
        { START(sink__V22, _M__sTextCons);
          { START(sink__V22, _M__sTextChars);
            LITERAL(sink__V22,  ". */" ); END(sink__V22, _M__sTextChars); }
          { START(sink__V22, _M__sTextCons);
            { START(sink__V22, _M__sTextBreak);
              LITERAL(sink__V22,  "\n" ); END(sink__V22, _M__sTextBreak); }
            { START(sink__V22, _M__sTextCons);
              { START(sink__V22, _M__sTextEmbed);
                { START(sink__V22, _M_AsText);
                  { START(sink__V22, _M_DelayMapText_s1);
                    {char* str__V30;{ Term term__V31;
                        { char *value__V32 = getenv( "HEADERS" );
                          if (value__V32) term__V31 = makeStringLiteral(sink__V22->context, value__V32);
                          else {term__V31 = makeStringLiteral(sink__V22->context,  "" );
                            }
                        }
                        str__V30 = SYMBOL(term__V31); UNLINK(sink__V22->context, term__V31); }
                      
                      char* regex__V33;
                      regex__V33 =  ";" ; SEND_SPLIT(str__V30, regex__V33, sink__V22);
                    }
                    { Variable x__V34 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V22->context,"x__V34");
                      Variable x__V35 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V22->context,"x__V35");
                      Variable binds__V36[2] = {x__V34,x__V35}; BINDS(sink__V22, 2, binds__V36);
                      { START(sink__V22, _M__sTextCons);
                        { START(sink__V22, _M__sTextChars);
                          LITERAL(sink__V22,  "#include \"" ); END(sink__V22, _M__sTextChars); }
                        { START(sink__V22, _M__sTextCons);
                          { START(sink__V22, _M__sTextEmbed);
                            { START(sink__V22, _M_AsText);
                              { START(sink__V22, _M_DTOKEN);
                                USE(sink__V22, x__V34); USE(sink__V22, x__V35); END(sink__V22, _M_DTOKEN); }
                              END(sink__V22, _M_AsText); }
                            END(sink__V22, _M__sTextEmbed); }
                          { START(sink__V22, _M__sTextCons);
                            { START(sink__V22, _M__sTextChars);
                              LITERAL(sink__V22,  "\"" ); END(sink__V22, _M__sTextChars); }
                            { START(sink__V22, _M__sTextCons);
                              { START(sink__V22, _M__sTextBreak);
                                LITERAL(sink__V22,  "\n" ); END(sink__V22, _M__sTextBreak); }
                              { START(sink__V22, _M__sTextNil);
                                END(sink__V22, _M__sTextNil); }
                              END(sink__V22, _M__sTextCons); }
                            END(sink__V22, _M__sTextCons); }
                          END(sink__V22, _M__sTextCons); }
                        END(sink__V22, _M__sTextCons); }
                       }
                    END(sink__V22, _M_DelayMapText_s1); }
                  END(sink__V22, _M_AsText); }
                END(sink__V22, _M__sTextEmbed); }
              { START(sink__V22, _M__sTextCons);
                { START(sink__V22, _M__sTextBreak);
                  LITERAL(sink__V22,  "\n" ); END(sink__V22, _M__sTextBreak); }
                { START(sink__V22, _M__sTextCons);
                  { START(sink__V22, _M__sTextChars);
                    LITERAL(sink__V22,  "#ifdef __cplusplus" ); END(sink__V22, _M__sTextChars); }
                  { START(sink__V22, _M__sTextCons);
                    { START(sink__V22, _M__sTextBreak);
                      LITERAL(sink__V22,  "\n" ); END(sink__V22, _M__sTextBreak); }
                    { START(sink__V22, _M__sTextCons);
                      { START(sink__V22, _M__sTextChars);
                        LITERAL(sink__V22,  "extern \"C\" {" ); END(sink__V22, _M__sTextChars); }
                      { START(sink__V22, _M__sTextCons);
                        { START(sink__V22, _M__sTextBreak);
                          LITERAL(sink__V22,  "\n" ); END(sink__V22, _M__sTextBreak); }
                        { START(sink__V22, _M__sTextCons);
                          { START(sink__V22, _M__sTextChars);
                            LITERAL(sink__V22,  "#endif" ); END(sink__V22, _M__sTextChars); }
                          { START(sink__V22, _M__sTextCons);
                            { START(sink__V22, _M__sTextBreak);
                              LITERAL(sink__V22,  "\n" ); END(sink__V22, _M__sTextBreak); }
                            { START(sink__V22, _M__sTextCons);
                              { START(sink__V22, _M__sTextEmbed);
                                { START(sink__V22, _M_AsText);
                                  { START(sink__V22, _M_MapText_s1);
                                    COPY(sink__V22, sub__V25);{ Variable x__V37 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V22->context,"x__V37");
                                      Variable binds__V38[1] = {x__V37}; BINDS(sink__V22, 1, binds__V38);
                                      { START(sink__V22, _M_S_Declaration);
                                        USE(sink__V22, x__V37); END(sink__V22, _M_S_Declaration); }
                                       }
                                    END(sink__V22, _M_MapText_s1); }
                                  END(sink__V22, _M_AsText); }
                                END(sink__V22, _M__sTextEmbed); }
                              { START(sink__V22, _M__sTextCons);
                                { START(sink__V22, _M__sTextBreak);
                                  LITERAL(sink__V22,  "\n" ); END(sink__V22, _M__sTextBreak); }
                                { START(sink__V22, _M__sTextCons);
                                  { START(sink__V22, _M__sTextChars);
                                    LITERAL(sink__V22,  "#ifdef __cplusplus" );
                                    END(sink__V22, _M__sTextChars); }
                                  { START(sink__V22, _M__sTextCons);
                                    { START(sink__V22, _M__sTextBreak);
                                      LITERAL(sink__V22,  "\n" ); END(sink__V22, _M__sTextBreak); }
                                    { START(sink__V22, _M__sTextCons);
                                      { START(sink__V22, _M__sTextChars);
                                        LITERAL(sink__V22,  "}" ); END(sink__V22, _M__sTextChars); }
                                      { START(sink__V22, _M__sTextCons);
                                        { START(sink__V22, _M__sTextBreak);
                                          LITERAL(sink__V22,  "\n" ); END(sink__V22, _M__sTextBreak); }
                                        { START(sink__V22, _M__sTextCons);
                                          { START(sink__V22, _M__sTextChars);
                                            LITERAL(sink__V22,  "#endif" );
                                            END(sink__V22, _M__sTextChars); }
                                          { START(sink__V22, _M__sTextCons);
                                            { START(sink__V22, _M__sTextBreak);
                                              LITERAL(sink__V22,  "\n" );
                                              END(sink__V22, _M__sTextBreak); }
                                            { START(sink__V22, _M__sTextCons);
                                              { START(sink__V22, _M__sTextChars);
                                                LITERAL(sink__V22,  "/* END OF C SORT DESCRIPTORS FOR CRSX " );
                                                END(sink__V22, _M__sTextChars); }
                                              { START(sink__V22, _M__sTextCons);
                                                { START(sink__V22, _M__sTextEmbed);
                                                  { START(sink__V22, _M_AsText);
                                                    { START(sink__V22, _M_TOKEN);
                                                      COPY(sink__V22, sub__V24);END(sink__V22, _M_TOKEN); }
                                                    END(sink__V22, _M_AsText); }
                                                  END(sink__V22, _M__sTextEmbed); }
                                                { START(sink__V22, _M__sTextCons);
                                                  { START(sink__V22, _M__sTextChars);
                                                    LITERAL(sink__V22,  ". */" );
                                                    END(sink__V22, _M__sTextChars); }
                                                  { START(sink__V22, _M__sTextCons);
                                                    { START(sink__V22, _M__sTextBreak);
                                                      LITERAL(sink__V22,  "\n" );
                                                      END(sink__V22, _M__sTextBreak); }
                                                    { START(sink__V22, _M__sTextNil);
                                                      END(sink__V22, _M__sTextNil); }
                                                    END(sink__V22, _M__sTextCons); }
                                                  END(sink__V22, _M__sTextCons); }
                                                END(sink__V22, _M__sTextCons); }
                                              END(sink__V22, _M__sTextCons); }
                                            END(sink__V22, _M__sTextCons); }
                                          END(sink__V22, _M__sTextCons); }
                                        END(sink__V22, _M__sTextCons); }
                                      END(sink__V22, _M__sTextCons); }
                                    END(sink__V22, _M__sTextCons); }
                                  END(sink__V22, _M__sTextCons); }
                                END(sink__V22, _M__sTextCons); }
                              END(sink__V22, _M__sTextCons); }
                            END(sink__V22, _M__sTextCons); }
                          END(sink__V22, _M__sTextCons); }
                        END(sink__V22, _M__sTextCons); }
                      END(sink__V22, _M__sTextCons); }
                    END(sink__V22, _M__sTextCons); }
                  END(sink__V22, _M__sTextCons); }
                END(sink__V22, _M__sTextCons); }
              END(sink__V22, _M__sTextCons); }
            END(sink__V22, _M__sTextCons); }
          END(sink__V22, _M__sTextCons); }
        END(sink__V22, _M__sTextCons); }
      END(sink__V22, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V22->context, namedFV__V28); UNLINK_VARIABLESET(sink__V22->context, varFV__V29);
    UNLINK_NamedPropertyLink(sink__V22->context, namedP__V26); UNLINK_VariablePropertyLink(sink__V22->context, varP__V27);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION S-Data$1. */
int conBindOffs_M_S_Data_s1[] = {0 , 0 , 0 , 0};
char *nameFun_M_S_Data_s1(Term term) { return  "S-Data$1" ; }
struct _ConstructionDescriptor descriptor_M_S_Data_s1 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_S_Data_s1), conBindOffs_M_S_Data_s1, &nameFun_M_S_Data_s1, &step_M_S_Data_s1};

int step_M_S_Data_s1(Sink sink__V39, Term term__V40)
{
  int term__V40_count = LINK_COUNT(term__V40); permitUnusedInt(term__V40_count);
  do {
    /* Contraction rule SORTS-S-Data-1. */
    ASSERT(sink__V39->context, !strcmp(SYMBOL(term__V40),  "S-Data$1" ));
    Term sub__V41 = LINK(sink__V39->context, SUB(term__V40, 0)); int sub__V41_count = term__V40_count*LINK_COUNT(sub__V41); permitUnusedInt(sub__V41_count);
    UNLINK_SUB(sink__V39->context, term__V40,  0); NORMALIZE(sink__V39->context, sub__V41); SUB(term__V40,  0) = LINK(sink__V39->context, sub__V41);
    /* sub__V41 = &#11 */
    Term sub__V42 = SUB(term__V40, 1); permitUnusedTerm(sub__V42); int sub__V42_count = term__V40_count*LINK_COUNT(sub__V42); permitUnusedInt(sub__V42_count);
    /* sub__V42 = &#12 */
    Term sub__V43 = LINK(sink__V39->context, SUB(term__V40, 2)); int sub__V43_count = term__V40_count*LINK_COUNT(sub__V43); permitUnusedInt(sub__V43_count);
    UNLINK_SUB(sink__V39->context, term__V40,  2); NORMALIZE(sink__V39->context, sub__V43); SUB(term__V40,  2) = LINK(sink__V39->context, sub__V43);
    /* sub__V43 = &#2 */
    
    NamedPropertyLink namedP__V44 = LINK_NamedPropertyLink(sink__V39->context, NAMED_PROPERTIES(term__V40));
    VariablePropertyLink varP__V45 = LINK_VariablePropertyLink(sink__V39->context, VARIABLE_PROPERTIES(term__V40));
    Hashset namedFV__V46 = LINK_VARIABLESET(sink__V39->context, asConstruction(term__V40)->nfvs);
    Hashset varFV__V47 = LINK_VARIABLESET(sink__V39->context, variablePropertyFreeVars(varP__V45));
    UNLINK(sink__V39->context, term__V40);
    { START(sink__V39, _M__sTextCons);
      { START(sink__V39, _M__sTextBreak);
        LITERAL(sink__V39,  "\n" ); END(sink__V39, _M__sTextBreak); }
      { START(sink__V39, _M__sTextCons);
        { START(sink__V39, _M__sTextChars);
          LITERAL(sink__V39,  "/* SORT " ); END(sink__V39, _M__sTextChars); }
        { START(sink__V39, _M__sTextCons);
          { START(sink__V39, _M__sTextEmbed);
            { START(sink__V39, _M_AsText);
              { START(sink__V39, _M_TOKEN);
                COPY(sink__V39, LINK(sink__V39->context, sub__V41));END(sink__V39, _M_TOKEN); }
              END(sink__V39, _M_AsText); }
            END(sink__V39, _M__sTextEmbed); }
          { START(sink__V39, _M__sTextCons);
            { START(sink__V39, _M__sTextChars);
              LITERAL(sink__V39,  " CONSTANTS. */" ); END(sink__V39, _M__sTextChars); }
            { START(sink__V39, _M__sTextCons);
              { START(sink__V39, _M__sTextBreak);
                LITERAL(sink__V39,  "\n" ); END(sink__V39, _M__sTextBreak); }
              { START(sink__V39, _M__sTextCons);
                { START(sink__V39, _M__sTextEmbed);
                  { START(sink__V39, _M_AsText);
                    { START(sink__V39, _M_MapText_s1);
                      COPY(sink__V39, LINK(sink__V39->context, sub__V43));{ Variable x__V48 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V39->context,"x__V48");
                        Variable binds__V49[1] = {x__V48}; BINDS(sink__V39, 1, binds__V49);
                        { START(sink__V39, _M_S_Data_Form_s1);
                          USE(sink__V39, x__V48); COPY(sink__V39, LINK(sink__V39->context, sub__V41));END(sink__V39, _M_S_Data_Form_s1); }
                         }
                      END(sink__V39, _M_MapText_s1); }
                    END(sink__V39, _M_AsText); }
                  END(sink__V39, _M__sTextEmbed); }
                { START(sink__V39, _M__sTextCons);
                  { START(sink__V39, _M__sTextChars);
                    LITERAL(sink__V39,  "ConstructionDescriptor " ); END(sink__V39, _M__sTextChars); }
                  { START(sink__V39, _M__sTextCons);
                    { START(sink__V39, _M__sTextEmbed);
                      { START(sink__V39, _M_AsText);
                        { START(sink__V39, _M_SortCons);
                          COPY(sink__V39, LINK(sink__V39->context, sub__V41));END(sink__V39, _M_SortCons); }
                        END(sink__V39, _M_AsText); }
                      END(sink__V39, _M__sTextEmbed); }
                    { START(sink__V39, _M__sTextCons);
                      { START(sink__V39, _M__sTextChars);
                        LITERAL(sink__V39,  "[] = {NULL, NULL, " ); END(sink__V39, _M__sTextChars); }
                      { START(sink__V39, _M__sTextCons);
                        { START(sink__V39, _M__sTextEmbed);
                          { START(sink__V39, _M_AsText);
                            { START(sink__V39, _M_DelayMapText_s1);
                              { START(sink__V39, _M_Forms_Constructors);
                                COPY(sink__V39, LINK(sink__V39->context, sub__V43));END(sink__V39, _M_Forms_Constructors); }
                              { Variable x__V50 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V39->context,"x__V50");
                                Variable x__V51 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V39->context,"x__V51");
                                Variable binds__V52[2] = {x__V50,x__V51}; BINDS(sink__V39, 2, binds__V52);
                                { START(sink__V39, _M__sTextCons);
                                  { START(sink__V39, _M__sTextChars);
                                    LITERAL(sink__V39,  "&" ); END(sink__V39, _M__sTextChars); }
                                  { START(sink__V39, _M__sTextCons);
                                    { START(sink__V39, _M__sTextEmbed);
                                      { START(sink__V39, _M_AsText);
                                        { START(sink__V39, _M_DDescriptor);
                                          USE(sink__V39, x__V50); USE(sink__V39, x__V51); END(sink__V39, _M_DDescriptor); }
                                        END(sink__V39, _M_AsText); }
                                      END(sink__V39, _M__sTextEmbed); }
                                    { START(sink__V39, _M__sTextCons);
                                      { START(sink__V39, _M__sTextChars);
                                        LITERAL(sink__V39,  ", " ); END(sink__V39, _M__sTextChars); }
                                      { START(sink__V39, _M__sTextNil);
                                        END(sink__V39, _M__sTextNil); }
                                      END(sink__V39, _M__sTextCons); }
                                    END(sink__V39, _M__sTextCons); }
                                  END(sink__V39, _M__sTextCons); }
                                 }
                              END(sink__V39, _M_DelayMapText_s1); }
                            END(sink__V39, _M_AsText); }
                          END(sink__V39, _M__sTextEmbed); }
                        { START(sink__V39, _M__sTextCons);
                          { START(sink__V39, _M__sTextChars);
                            LITERAL(sink__V39,  " NULL};" ); END(sink__V39, _M__sTextChars); }
                          { START(sink__V39, _M__sTextCons);
                            { START(sink__V39, _M__sTextBreak);
                              LITERAL(sink__V39,  "\n" ); END(sink__V39, _M__sTextBreak); }
                            { START(sink__V39, _M__sTextCons);
                              { START(sink__V39, _M__sTextChars);
                                LITERAL(sink__V39,  "char *" ); END(sink__V39, _M__sTextChars); }
                              { START(sink__V39, _M__sTextCons);
                                { START(sink__V39, _M__sTextEmbed);
                                  { START(sink__V39, _M_AsText);
                                    { START(sink__V39, _M_SortNames);
                                      COPY(sink__V39, LINK(sink__V39->context, sub__V41));END(sink__V39, _M_SortNames); }
                                    END(sink__V39, _M_AsText); }
                                  END(sink__V39, _M__sTextEmbed); }
                                { START(sink__V39, _M__sTextCons);
                                  { START(sink__V39, _M__sTextChars);
                                    LITERAL(sink__V39,  "[] = {NULL, NULL, " );
                                    END(sink__V39, _M__sTextChars); }
                                  { START(sink__V39, _M__sTextCons);
                                    { START(sink__V39, _M__sTextEmbed);
                                      { START(sink__V39, _M_AsText);
                                        { START(sink__V39, _M_DelayMapText_s1);
                                          { START(sink__V39, _M_Forms_Constructors);
                                            COPY(sink__V39, LINK(sink__V39->context, sub__V43));END(sink__V39, _M_Forms_Constructors); }
                                          { Variable x__V53 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V39->context,"x__V53");
                                            Variable x__V54 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V39->context,"x__V54");
                                            Variable binds__V55[2] = {x__V53,x__V54}; BINDS(sink__V39, 2, binds__V55);
                                            { START(sink__V39, _M__sTextCons);
                                              { START(sink__V39, _M__sTextEmbed);
                                                { START(sink__V39, _M_AsText);
                                                  { START(sink__V39, _M_DSTRING);
                                                    USE(sink__V39, x__V53);
                                                    USE(sink__V39, x__V54);
                                                    END(sink__V39, _M_DSTRING); }
                                                  END(sink__V39, _M_AsText); }
                                                END(sink__V39, _M__sTextEmbed); }
                                              { START(sink__V39, _M__sTextCons);
                                                { START(sink__V39, _M__sTextChars);
                                                  LITERAL(sink__V39,  ", " );
                                                  END(sink__V39, _M__sTextChars); }
                                                { START(sink__V39, _M__sTextNil);
                                                  END(sink__V39, _M__sTextNil); }
                                                END(sink__V39, _M__sTextCons); }
                                              END(sink__V39, _M__sTextCons); }
                                             }
                                          END(sink__V39, _M_DelayMapText_s1); }
                                        END(sink__V39, _M_AsText); }
                                      END(sink__V39, _M__sTextEmbed); }
                                    { START(sink__V39, _M__sTextCons);
                                      { START(sink__V39, _M__sTextChars);
                                        LITERAL(sink__V39,  " NULL};" );
                                        END(sink__V39, _M__sTextChars); }
                                      { START(sink__V39, _M__sTextCons);
                                        { START(sink__V39, _M__sTextBreak);
                                          LITERAL(sink__V39,  "\n" ); END(sink__V39, _M__sTextBreak); }
                                        { START(sink__V39, _M__sTextCons);
                                          { START(sink__V39, _M__sTextChars);
                                            LITERAL(sink__V39,  "char *" );
                                            END(sink__V39, _M__sTextChars); }
                                          { START(sink__V39, _M__sTextCons);
                                            { START(sink__V39, _M__sTextEmbed);
                                              { START(sink__V39, _M_AsText);
                                                { START(sink__V39, _M_SortInternals);
                                                  COPY(sink__V39, LINK(sink__V39->context, sub__V41));END(sink__V39, _M_SortInternals); }
                                                END(sink__V39, _M_AsText); }
                                              END(sink__V39, _M__sTextEmbed); }
                                            { START(sink__V39, _M__sTextCons);
                                              { START(sink__V39, _M__sTextChars);
                                                LITERAL(sink__V39,  "[] = {NULL, NULL, " );
                                                END(sink__V39, _M__sTextChars); }
                                              { START(sink__V39, _M__sTextCons);
                                                { START(sink__V39, _M__sTextEmbed);
                                                  { START(sink__V39, _M_AsText);
                                                    { START(sink__V39, _M_DelayMapText_s1);
                                                      { START(sink__V39, _M_Forms_Constructors);
                                                        COPY(sink__V39, sub__V43);END(sink__V39, _M_Forms_Constructors); }
                                                      { Variable x__V56 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V39->context,"x__V56");
                                                        Variable x__V57 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V39->context,"x__V57");
                                                        Variable binds__V58[2] = {x__V56,x__V57}; BINDS(sink__V39, 2, binds__V58);
                                                        { START(sink__V39, _M__sTextCons);
                                                          { START(sink__V39, _M__sTextChars);
                                                            LITERAL(sink__V39,  "\"" );
                                                            END(sink__V39, _M__sTextChars); }
                                                          { START(sink__V39, _M__sTextCons);
                                                            { START(sink__V39, _M__sTextEmbed);
                                                              { START(sink__V39, _M_AsText);
                                                                { START(sink__V39, _M_DMANGLE);
                                                                  USE(sink__V39, x__V56);
                                                                  USE(sink__V39, x__V57);
                                                                  END(sink__V39, _M_DMANGLE); }
                                                                END(sink__V39, _M_AsText); }
                                                              END(sink__V39, _M__sTextEmbed); }
                                                            { START(sink__V39, _M__sTextCons);
                                                              { START(sink__V39, _M__sTextChars);
                                                                LITERAL(sink__V39,  "\", " );
                                                                END(sink__V39, _M__sTextChars); }
                                                              { START(sink__V39, _M__sTextNil);
                                                                END(sink__V39, _M__sTextNil); }
                                                              END(sink__V39, _M__sTextCons); }
                                                            END(sink__V39, _M__sTextCons); }
                                                          END(sink__V39, _M__sTextCons); }
                                                         }
                                                      END(sink__V39, _M_DelayMapText_s1); }
                                                    END(sink__V39, _M_AsText); }
                                                  END(sink__V39, _M__sTextEmbed); }
                                                { START(sink__V39, _M__sTextCons);
                                                  { START(sink__V39, _M__sTextChars);
                                                    LITERAL(sink__V39,  " NULL};" );
                                                    END(sink__V39, _M__sTextChars); }
                                                  { START(sink__V39, _M__sTextCons);
                                                    { START(sink__V39, _M__sTextBreak);
                                                      LITERAL(sink__V39,  "\n" );
                                                      END(sink__V39, _M__sTextBreak); }
                                                    { START(sink__V39, _M__sTextCons);
                                                      { START(sink__V39, _M__sTextChars);
                                                        LITERAL(sink__V39,  "struct _SortDescriptor " );
                                                        END(sink__V39, _M__sTextChars); }
                                                      { START(sink__V39, _M__sTextCons);
                                                        { START(sink__V39, _M__sTextEmbed);
                                                          { START(sink__V39, _M_AsText);
                                                            { START(sink__V39, _M_Sort);
                                                              COPY(sink__V39, LINK(sink__V39->context, sub__V41));END(sink__V39, _M_Sort); }
                                                            END(sink__V39, _M_AsText); }
                                                          END(sink__V39, _M__sTextEmbed); }
                                                        { START(sink__V39, _M__sTextCons);
                                                          { START(sink__V39, _M__sTextChars);
                                                            LITERAL(sink__V39,  " = {" );
                                                            END(sink__V39, _M__sTextChars); }
                                                          { START(sink__V39, _M__sTextCons);
                                                            { START(sink__V39, _M__sTextEmbed);
                                                              { START(sink__V39, _M_AsText);
                                                                { START(sink__V39, _M_STRING);
                                                                  COPY(sink__V39, LINK(sink__V39->context, sub__V41));END(sink__V39, _M_STRING); }
                                                                END(sink__V39, _M_AsText); }
                                                              END(sink__V39, _M__sTextEmbed); }
                                                            { START(sink__V39, _M__sTextCons);
                                                              { START(sink__V39, _M__sTextChars);
                                                                LITERAL(sink__V39,  ", " );
                                                                END(sink__V39, _M__sTextChars); }
                                                              { START(sink__V39, _M__sTextCons);
                                                                { START(sink__V39, _M__sTextEmbed);
                                                                  { START(sink__V39, _M_AsText);
                                                                    { START(sink__V39, _M_SortCons);
                                                                      COPY(sink__V39, LINK(sink__V39->context, sub__V41));END(sink__V39, _M_SortCons); }
                                                                    END(sink__V39, _M_AsText); }
                                                                  END(sink__V39, _M__sTextEmbed); }
                                                                { START(sink__V39, _M__sTextCons);
                                                                  { START(sink__V39, _M__sTextChars);
                                                                    LITERAL(sink__V39,  ", " );
                                                                    END(sink__V39, _M__sTextChars); }
                                                                  { START(sink__V39, _M__sTextCons);
                                                                    { START(sink__V39, _M__sTextEmbed);
                                                                      { START(sink__V39, _M_AsText);
                                                                        { START(sink__V39, _M_SortNames);
                                                                          COPY(sink__V39, LINK(sink__V39->context, sub__V41));END(sink__V39, _M_SortNames); }
                                                                        END(sink__V39, _M_AsText); }
                                                                      END(sink__V39, _M__sTextEmbed); }
                                                                    { START(sink__V39, _M__sTextCons);
                                                                      { START(sink__V39, _M__sTextChars);
                                                                        LITERAL(sink__V39,  ", " );
                                                                        END(sink__V39, _M__sTextChars); }
                                                                      { START(sink__V39, _M__sTextCons);
                                                                        { START(sink__V39, _M__sTextEmbed);
                                                                          { START(sink__V39, _M_AsText);
                                                                            { START(sink__V39, _M_SortInternals);
                                                                              COPY(sink__V39, sub__V41);END(sink__V39, _M_SortInternals); }
                                                                            END(sink__V39, _M_AsText); }
                                                                          END(sink__V39, _M__sTextEmbed); }
                                                                        { START(sink__V39, _M__sTextCons);
                                                                          { START(sink__V39, _M__sTextChars);
                                                                            LITERAL(sink__V39,  ", NULL};" );
                                                                            END(sink__V39, _M__sTextChars); }
                                                                          { START(sink__V39, _M__sTextCons);
                                                                            { START(sink__V39, _M__sTextBreak);
                                                                              LITERAL(sink__V39,  "\n" );
                                                                              END(sink__V39, _M__sTextBreak); }
                                                                            { START(sink__V39, _M__sTextNil);
                                                                              END(sink__V39, _M__sTextNil); }
                                                                            END(sink__V39, _M__sTextCons); }
                                                                          END(sink__V39, _M__sTextCons); }
                                                                        END(sink__V39, _M__sTextCons); }
                                                                      END(sink__V39, _M__sTextCons); }
                                                                    END(sink__V39, _M__sTextCons); }
                                                                  END(sink__V39, _M__sTextCons); }
                                                                END(sink__V39, _M__sTextCons); }
                                                              END(sink__V39, _M__sTextCons); }
                                                            END(sink__V39, _M__sTextCons); }
                                                          END(sink__V39, _M__sTextCons); }
                                                        END(sink__V39, _M__sTextCons); }
                                                      END(sink__V39, _M__sTextCons); }
                                                    END(sink__V39, _M__sTextCons); }
                                                  END(sink__V39, _M__sTextCons); }
                                                END(sink__V39, _M__sTextCons); }
                                              END(sink__V39, _M__sTextCons); }
                                            END(sink__V39, _M__sTextCons); }
                                          END(sink__V39, _M__sTextCons); }
                                        END(sink__V39, _M__sTextCons); }
                                      END(sink__V39, _M__sTextCons); }
                                    END(sink__V39, _M__sTextCons); }
                                  END(sink__V39, _M__sTextCons); }
                                END(sink__V39, _M__sTextCons); }
                              END(sink__V39, _M__sTextCons); }
                            END(sink__V39, _M__sTextCons); }
                          END(sink__V39, _M__sTextCons); }
                        END(sink__V39, _M__sTextCons); }
                      END(sink__V39, _M__sTextCons); }
                    END(sink__V39, _M__sTextCons); }
                  END(sink__V39, _M__sTextCons); }
                END(sink__V39, _M__sTextCons); }
              END(sink__V39, _M__sTextCons); }
            END(sink__V39, _M__sTextCons); }
          END(sink__V39, _M__sTextCons); }
        END(sink__V39, _M__sTextCons); }
      END(sink__V39, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V39->context, namedFV__V46); UNLINK_VARIABLESET(sink__V39->context, varFV__V47);
    UNLINK_NamedPropertyLink(sink__V39->context, namedP__V44); UNLINK_VariablePropertyLink(sink__V39->context, varP__V45);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION S-Data$2. */
int conBindOffs_M_S_Data_s2[] = {0 , 0 , 0 , 0 , 0};
char *nameFun_M_S_Data_s2(Term term) { return  "S-Data$2" ; }
struct _ConstructionDescriptor descriptor_M_S_Data_s2 = {&sort_M_Reified_xVariable, 0, 4, sizeof(STRUCT_Con_M_S_Data_s2), conBindOffs_M_S_Data_s2, &nameFun_M_S_Data_s2, &step_M_S_Data_s2};

int step_M_S_Data_s2(Sink sink__V59, Term term__V60)
{
  int term__V60_count = LINK_COUNT(term__V60); permitUnusedInt(term__V60_count);
  do {
    /* Contraction rule SORTS-S-Data-2. */
    ASSERT(sink__V59->context, !strcmp(SYMBOL(term__V60),  "S-Data$2" ));
    Term sub__V61 = SUB(term__V60, 0); permitUnusedTerm(sub__V61); int sub__V61_count = term__V60_count*LINK_COUNT(sub__V61); permitUnusedInt(sub__V61_count);
    CRSX_CHECK_SORT(sink__V59->context, sub__V61, &sort_M_Reified_xSort); /* sub__V61 = &#11 */
    Term sub__V62 = SUB(term__V60, 1); permitUnusedTerm(sub__V62); int sub__V62_count = term__V60_count*LINK_COUNT(sub__V62); permitUnusedInt(sub__V62_count);
    CRSX_CHECK_SORT(sink__V59->context, sub__V62, &sort_M_Reified_xSort); /* sub__V62 = &#12 */
    Term sub__V63 = LINK(sink__V59->context, SUB(term__V60, 2)); int sub__V63_count = term__V60_count*LINK_COUNT(sub__V63); permitUnusedInt(sub__V63_count);
    CRSX_CHECK_SORT(sink__V59->context, sub__V63, &sort_M_Reified_xSort); /* sub__V63 = &#13 */
    Term sub__V64 = LINK(sink__V59->context, SUB(term__V60, 3)); int sub__V64_count = term__V60_count*LINK_COUNT(sub__V64); permitUnusedInt(sub__V64_count);
    /* sub__V64 = &#2 */
    
    NamedPropertyLink namedP__V65 = LINK_NamedPropertyLink(sink__V59->context, NAMED_PROPERTIES(term__V60));
    VariablePropertyLink varP__V66 = LINK_VariablePropertyLink(sink__V59->context, VARIABLE_PROPERTIES(term__V60));
    Hashset namedFV__V67 = LINK_VARIABLESET(sink__V59->context, asConstruction(term__V60)->nfvs);
    Hashset varFV__V68 = LINK_VARIABLESET(sink__V59->context, variablePropertyFreeVars(varP__V66));
    UNLINK(sink__V59->context, term__V60);
    { START(sink__V59, _M_S_Data);
      COPY(sink__V59, sub__V63);COPY(sink__V59, sub__V64);END(sink__V59, _M_S_Data); }
    UNLINK_VARIABLESET(sink__V59->context, namedFV__V67); UNLINK_VARIABLESET(sink__V59->context, varFV__V68);
    UNLINK_NamedPropertyLink(sink__V59->context, namedP__V65); UNLINK_VariablePropertyLink(sink__V59->context, varP__V66);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION ComputeSorts. */
int conBindOffs_M_ComputeSorts[] = {0 , 0};
char *nameFun_M_ComputeSorts(Term term) { return  "ComputeSorts" ; }
struct _ConstructionDescriptor descriptor_M_ComputeSorts = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_ComputeSorts), conBindOffs_M_ComputeSorts, &nameFun_M_ComputeSorts, &step_M_ComputeSorts};

int step_M_ComputeSorts(Sink sink__V69, Term term__V70)
{
  int term__V70_count = LINK_COUNT(term__V70); permitUnusedInt(term__V70_count);
  Term sub__V71 = FORCE(sink__V69->context, SUB(term__V70, 0));
  EnumOf_M_Reify_xCRSX choice__V72 = (IS_VARIABLE_USE(sub__V71) ? VarOf_M_Reify_xCRSX : (EnumOf_M_Reify_xCRSX) TAG(sub__V71));
  switch (choice__V72)
  {
    case Data_M_CRSX: { /* Function SORTS-Crsx$ComputeSorts$CRSX case CRSX */
      ASSERT(sink__V69->context, !strcmp(SYMBOL(term__V70),  "ComputeSorts" ));
      Term sub__V73 = SUB(term__V70, 0); permitUnusedTerm(sub__V73); int sub__V73_count = term__V70_count*LINK_COUNT(sub__V73); permitUnusedInt(sub__V73_count);
      CRSX_CHECK_SORT(sink__V69->context, sub__V73, &sort_M_Reify_xCRSX); ASSERT(sink__V69->context, !strcmp(SYMBOL(sub__V73),  "CRSX" ));
      Term sub__V74 = LINK(sink__V69->context, SUB(sub__V73, 0)); int sub__V74_count = sub__V73_count*LINK_COUNT(sub__V74); permitUnusedInt(sub__V74_count);
      /* sub__V74 = &#0-0 */
      Term sub__V75 = LINK(sink__V69->context, SUB(sub__V73, 1)); int sub__V75_count = sub__V73_count*LINK_COUNT(sub__V75); permitUnusedInt(sub__V75_count);
      /* sub__V75 = &#0-1 */
      
      NamedPropertyLink namedP__V76 = LINK_NamedPropertyLink(sink__V69->context, NAMED_PROPERTIES(term__V70));
      VariablePropertyLink varP__V77 = LINK_VariablePropertyLink(sink__V69->context, VARIABLE_PROPERTIES(term__V70));
      Hashset namedFV__V78 = LINK_VARIABLESET(sink__V69->context, asConstruction(term__V70)->nfvs);
      Hashset varFV__V79 = LINK_VARIABLESET(sink__V69->context, variablePropertyFreeVars(varP__V77));
      UNLINK(sink__V69->context, term__V70);
      ADD_PROPERTIES(sink__V69, LINK_VARIABLESET(sink__V69->context, namedFV__V78), LINK_VARIABLESET(sink__V69->context, varFV__V79), LINK_NamedPropertyLink(sink__V69->context, namedP__V76), LINK_VariablePropertyLink(sink__V69->context, varP__V77));
      { START(sink__V69, _M_ComputeSorts_s1);
        COPY(sink__V69, sub__V74);COPY(sink__V69, sub__V75);END(sink__V69, _M_ComputeSorts_s1); }
      UNLINK_VARIABLESET(sink__V69->context, namedFV__V78); UNLINK_VARIABLESET(sink__V69->context, varFV__V79);
      UNLINK_NamedPropertyLink(sink__V69->context, namedP__V76); UNLINK_VariablePropertyLink(sink__V69->context, varP__V77);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION S-Declaration$1. */
int conBindOffs_M_S_Declaration_s1[] = {0 , 0 , 0};
char *nameFun_M_S_Declaration_s1(Term term) { return  "S-Declaration$1" ; }
struct _ConstructionDescriptor descriptor_M_S_Declaration_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_S_Declaration_s1), conBindOffs_M_S_Declaration_s1, &nameFun_M_S_Declaration_s1, &step_M_S_Declaration_s1};

int step_M_S_Declaration_s1(Sink sink__V80, Term term__V81)
{
  int term__V81_count = LINK_COUNT(term__V81); permitUnusedInt(term__V81_count);
  do {
    /* Contraction rule SORTS-Data. */
    ASSERT(sink__V80->context, !strcmp(SYMBOL(term__V81),  "S-Declaration$1" ));
    Term sub__V82 = LINK(sink__V80->context, SUB(term__V81, 0)); int sub__V82_count = term__V81_count*LINK_COUNT(sub__V82); permitUnusedInt(sub__V82_count);
    CRSX_CHECK_SORT(sink__V80->context, sub__V82, &sort_M_Reified_xSort); /* sub__V82 = &#11 */
    Term sub__V83 = LINK(sink__V80->context, SUB(term__V81, 1)); int sub__V83_count = term__V81_count*LINK_COUNT(sub__V83); permitUnusedInt(sub__V83_count);
    /* sub__V83 = &#12 */
    
    NamedPropertyLink namedP__V84 = LINK_NamedPropertyLink(sink__V80->context, NAMED_PROPERTIES(term__V81));
    VariablePropertyLink varP__V85 = LINK_VariablePropertyLink(sink__V80->context, VARIABLE_PROPERTIES(term__V81));
    Hashset namedFV__V86 = LINK_VARIABLESET(sink__V80->context, asConstruction(term__V81)->nfvs);
    Hashset varFV__V87 = LINK_VARIABLESET(sink__V80->context, variablePropertyFreeVars(varP__V85));
    UNLINK(sink__V80->context, term__V81);
    { START(sink__V80, _M_S_Data);
      COPY(sink__V80, sub__V82);COPY(sink__V80, sub__V83);END(sink__V80, _M_S_Data); }
    UNLINK_VARIABLESET(sink__V80->context, namedFV__V86); UNLINK_VARIABLESET(sink__V80->context, varFV__V87);
    UNLINK_NamedPropertyLink(sink__V80->context, namedP__V84); UNLINK_VariablePropertyLink(sink__V80->context, varP__V85);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION S-Declaration$2. */
int conBindOffs_M_S_Declaration_s2[] = {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0};
char *nameFun_M_S_Declaration_s2(Term term) { return  "S-Declaration$2" ; }
struct _ConstructionDescriptor descriptor_M_S_Declaration_s2 = {&sort_M_Reified_xVariable, 0, 7, sizeof(STRUCT_Con_M_S_Declaration_s2), conBindOffs_M_S_Declaration_s2, &nameFun_M_S_Declaration_s2, &step_M_S_Declaration_s2};

int step_M_S_Declaration_s2(Sink sink__V88, Term term__V89)
{
  int term__V89_count = LINK_COUNT(term__V89); permitUnusedInt(term__V89_count);
  do {
    /* Contraction rule SORTS-Function. */
    ASSERT(sink__V88->context, !strcmp(SYMBOL(term__V89),  "S-Declaration$2" ));
    Term sub__V90 = SUB(term__V89, 0); permitUnusedTerm(sub__V90); int sub__V90_count = term__V89_count*LINK_COUNT(sub__V90); permitUnusedInt(sub__V90_count);
    /* sub__V90 = &#11 */
    Term sub__V91 = SUB(term__V89, 1); permitUnusedTerm(sub__V91); int sub__V91_count = term__V89_count*LINK_COUNT(sub__V91); permitUnusedInt(sub__V91_count);
    /* sub__V91 = &#12 */
    Term sub__V92 = SUB(term__V89, 2); permitUnusedTerm(sub__V92); int sub__V92_count = term__V89_count*LINK_COUNT(sub__V92); permitUnusedInt(sub__V92_count);
    /* sub__V92 = &#13 */
    Term sub__V93 = SUB(term__V89, 3); permitUnusedTerm(sub__V93); int sub__V93_count = term__V89_count*LINK_COUNT(sub__V93); permitUnusedInt(sub__V93_count);
    /* sub__V93 = &#14 */
    Term sub__V94 = SUB(term__V89, 4); permitUnusedTerm(sub__V94); int sub__V94_count = term__V89_count*LINK_COUNT(sub__V94); permitUnusedInt(sub__V94_count);
    /* sub__V94 = &#15 */
    Term sub__V95 = SUB(term__V89, 5); permitUnusedTerm(sub__V95); int sub__V95_count = term__V89_count*LINK_COUNT(sub__V95); permitUnusedInt(sub__V95_count);
    CRSX_CHECK_SORT(sink__V88->context, sub__V95, &sort_M_Reified_xSort); /* sub__V95 = &#16 */
    Term sub__V96 = SUB(term__V89, 6); permitUnusedTerm(sub__V96); int sub__V96_count = term__V89_count*LINK_COUNT(sub__V96); permitUnusedInt(sub__V96_count);
    /* sub__V96 = &#17 */
    
    NamedPropertyLink namedP__V97 = LINK_NamedPropertyLink(sink__V88->context, NAMED_PROPERTIES(term__V89));
    VariablePropertyLink varP__V98 = LINK_VariablePropertyLink(sink__V88->context, VARIABLE_PROPERTIES(term__V89));
    Hashset namedFV__V99 = LINK_VARIABLESET(sink__V88->context, asConstruction(term__V89)->nfvs);
    Hashset varFV__V100 = LINK_VARIABLESET(sink__V88->context, variablePropertyFreeVars(varP__V98));
    UNLINK(sink__V88->context, term__V89);
    { START(sink__V88, _M__sTextNil); END(sink__V88, _M__sTextNil); } UNLINK_VARIABLESET(sink__V88->context, namedFV__V99); UNLINK_VARIABLESET(sink__V88->context, varFV__V100);
    UNLINK_NamedPropertyLink(sink__V88->context, namedP__V97); UNLINK_VariablePropertyLink(sink__V88->context, varP__V98);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION S-Declaration$3. */
int conBindOffs_M_S_Declaration_s3[] = {0 , 1};
char *nameFun_M_S_Declaration_s3(Term term) { return  "S-Declaration$3" ; }
struct _ConstructionDescriptor descriptor_M_S_Declaration_s3 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_S_Declaration_s3), conBindOffs_M_S_Declaration_s3, &nameFun_M_S_Declaration_s3, &step_M_S_Declaration_s3};

int step_M_S_Declaration_s3(Sink sink__V101, Term term__V102)
{
  int term__V102_count = LINK_COUNT(term__V102); permitUnusedInt(term__V102_count);
  do {
    /* Contraction rule SORTS-Polymorphic. */
    ASSERT(sink__V101->context, !strcmp(SYMBOL(term__V102),  "S-Declaration$3" ));
    Variable x__V103 = BINDER(term__V102,0,0); if (term__V102_count <= 1) UNBIND(x__V103);
    Term sub__V104 = LINK(sink__V101->context, SUB(term__V102, 0)); int sub__V104_count = term__V102_count*LINK_COUNT(sub__V104); permitUnusedInt(sub__V104_count);
    CRSX_CHECK_SORT(sink__V101->context, sub__V104, &sort_M_Reified_xDeclaration); /* sub__V104 = &#11 */
    Variable y__V105 = x__V103; permitUnusedVariable(y__V105);
    
    NamedPropertyLink namedP__V106 = LINK_NamedPropertyLink(sink__V101->context, NAMED_PROPERTIES(term__V102));
    VariablePropertyLink varP__V107 = LINK_VariablePropertyLink(sink__V101->context, VARIABLE_PROPERTIES(term__V102));
    Hashset namedFV__V108 = LINK_VARIABLESET(sink__V101->context, asConstruction(term__V102)->nfvs);
    Hashset varFV__V109 = LINK_VARIABLESET(sink__V101->context, variablePropertyFreeVars(varP__V107));
    UNLINK(sink__V101->context, term__V102);
    { START(sink__V101, _M_S_Declaration);
      COPY(sink__V101, sub__V104); /* REUSED SUBSTITUTION */ END(sink__V101, _M_S_Declaration); }
    UNLINK_VARIABLESET(sink__V101->context, namedFV__V108); UNLINK_VARIABLESET(sink__V101->context, varFV__V109);
    UNLINK_NamedPropertyLink(sink__V101->context, namedP__V106); UNLINK_VariablePropertyLink(sink__V101->context, varP__V107);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION S-Data-Form$1. */
int conBindOffs_M_S_Data_Form_s1[] = {0 , 0 , 0};
char *nameFun_M_S_Data_Form_s1(Term term) { return  "S-Data-Form$1" ; }
struct _ConstructionDescriptor descriptor_M_S_Data_Form_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_S_Data_Form_s1), conBindOffs_M_S_Data_Form_s1, &nameFun_M_S_Data_Form_s1, &step_M_S_Data_Form_s1};

int step_M_S_Data_Form_s1(Sink sink__V110, Term term__V111)
{
  int term__V111_count = LINK_COUNT(term__V111); permitUnusedInt(term__V111_count);
  Term sub__V112 = FORCE(sink__V110->context, SUB(term__V111, 0));
  EnumOf_M_Reified_xForm choice__V113 = (IS_VARIABLE_USE(sub__V112) ? VarOf_M_Reified_xForm : (EnumOf_M_Reified_xForm) TAG(sub__V112));
  switch (choice__V113)
  {
    case Data_M_SORT_SET: { /* Function SORTS-S-Data-Form-1$S-Data-Form$1$SORT-SET case SORT-SET */
      ASSERT(sink__V110->context, !strcmp(SYMBOL(term__V111),  "S-Data-Form$1" ));
      Term sub__V114 = SUB(term__V111, 0); permitUnusedTerm(sub__V114); int sub__V114_count = term__V111_count*LINK_COUNT(sub__V114); permitUnusedInt(sub__V114_count);
      CRSX_CHECK_SORT(sink__V110->context, sub__V114, &sort_M_Reified_xForm); ASSERT(sink__V110->context, !strcmp(SYMBOL(sub__V114),  "SORT-SET" ));
      Term sub__V115 = LINK(sink__V110->context, SUB(sub__V114, 0)); int sub__V115_count = sub__V114_count*LINK_COUNT(sub__V115); permitUnusedInt(sub__V115_count);
      CRSX_CHECK_SORT(sink__V110->context, sub__V115, &sort_M_Reified_xSort); /* sub__V115 = &#0-0 */
      Term sub__V116 = LINK(sink__V110->context, SUB(sub__V114, 1)); int sub__V116_count = sub__V114_count*LINK_COUNT(sub__V116); permitUnusedInt(sub__V116_count);
      CRSX_CHECK_SORT(sink__V110->context, sub__V116, &sort_M_Reified_xSort); /* sub__V116 = &#0-1 */
      Term sub__V117 = LINK(sink__V110->context, SUB(sub__V114, 2)); int sub__V117_count = sub__V114_count*LINK_COUNT(sub__V117); permitUnusedInt(sub__V117_count);
      CRSX_CHECK_SORT(sink__V110->context, sub__V117, &sort_M_Reified_xForm); /* sub__V117 = &#0-2 */
      Term sub__V118 = LINK(sink__V110->context, SUB(term__V111, 1)); int sub__V118_count = term__V111_count*LINK_COUNT(sub__V118); permitUnusedInt(sub__V118_count);
      /* sub__V118 = &#3 */
      
      NamedPropertyLink namedP__V119 = LINK_NamedPropertyLink(sink__V110->context, NAMED_PROPERTIES(term__V111));
      VariablePropertyLink varP__V120 = LINK_VariablePropertyLink(sink__V110->context, VARIABLE_PROPERTIES(term__V111));
      Hashset namedFV__V121 = LINK_VARIABLESET(sink__V110->context, asConstruction(term__V111)->nfvs);
      Hashset varFV__V122 = LINK_VARIABLESET(sink__V110->context, variablePropertyFreeVars(varP__V120));
      UNLINK(sink__V110->context, term__V111);
      ADD_PROPERTIES(sink__V110, LINK_VARIABLESET(sink__V110->context, namedFV__V121), LINK_VARIABLESET(sink__V110->context, varFV__V122), LINK_NamedPropertyLink(sink__V110->context, namedP__V119), LINK_VariablePropertyLink(sink__V110->context, varP__V120));
      { START(sink__V110, _M_S_Data_Form_s7);
        COPY(sink__V110, sub__V115);COPY(sink__V110, sub__V116);COPY(sink__V110, sub__V117);COPY(sink__V110, sub__V118);END(sink__V110, _M_S_Data_Form_s7); }
      UNLINK_VARIABLESET(sink__V110->context, namedFV__V121); UNLINK_VARIABLESET(sink__V110->context, varFV__V122);
      UNLINK_NamedPropertyLink(sink__V110->context, namedP__V119); UNLINK_VariablePropertyLink(sink__V110->context, varP__V120);
      
      return 1;
    break; } case Data_M_SORT_ALLOWS_VARIABLES: { /* Function SORTS-S-Data-Form-2$S-Data-Form$1$SORT-ALLOWS-VARIABLES case SORT-ALLOWS-VARIABLES */
      ASSERT(sink__V110->context, !strcmp(SYMBOL(term__V111),  "S-Data-Form$1" ));
      Term sub__V123 = SUB(term__V111, 0); permitUnusedTerm(sub__V123); int sub__V123_count = term__V111_count*LINK_COUNT(sub__V123); permitUnusedInt(sub__V123_count);
      CRSX_CHECK_SORT(sink__V110->context, sub__V123, &sort_M_Reified_xForm); ASSERT(sink__V110->context, !strcmp(SYMBOL(sub__V123),  "SORT-ALLOWS-VARIABLES" ));
      Term sub__V124 = LINK(sink__V110->context, SUB(term__V111, 1)); int sub__V124_count = term__V111_count*LINK_COUNT(sub__V124); permitUnusedInt(sub__V124_count);
      /* sub__V124 = &#0 */
      
      NamedPropertyLink namedP__V125 = LINK_NamedPropertyLink(sink__V110->context, NAMED_PROPERTIES(term__V111));
      VariablePropertyLink varP__V126 = LINK_VariablePropertyLink(sink__V110->context, VARIABLE_PROPERTIES(term__V111));
      Hashset namedFV__V127 = LINK_VARIABLESET(sink__V110->context, asConstruction(term__V111)->nfvs);
      Hashset varFV__V128 = LINK_VARIABLESET(sink__V110->context, variablePropertyFreeVars(varP__V126));
      UNLINK(sink__V110->context, term__V111);
      ADD_PROPERTIES(sink__V110, LINK_VARIABLESET(sink__V110->context, namedFV__V127), LINK_VARIABLESET(sink__V110->context, varFV__V128), LINK_NamedPropertyLink(sink__V110->context, namedP__V125), LINK_VariablePropertyLink(sink__V110->context, varP__V126));
      { START(sink__V110, _M_S_Data_Form_s6);
        COPY(sink__V110, sub__V124);END(sink__V110, _M_S_Data_Form_s6); }
      UNLINK_VARIABLESET(sink__V110->context, namedFV__V127); UNLINK_VARIABLESET(sink__V110->context, varFV__V128);
      UNLINK_NamedPropertyLink(sink__V110->context, namedP__V125); UNLINK_VariablePropertyLink(sink__V110->context, varP__V126);
      
      return 1;
    break; } case Data_M_FORM: { /* Function SORTS-S-Data-Form-3$S-Data-Form$1$FORM case FORM */
      ASSERT(sink__V110->context, !strcmp(SYMBOL(term__V111),  "S-Data-Form$1" ));
      Term sub__V129 = SUB(term__V111, 0); permitUnusedTerm(sub__V129); int sub__V129_count = term__V111_count*LINK_COUNT(sub__V129); permitUnusedInt(sub__V129_count);
      CRSX_CHECK_SORT(sink__V110->context, sub__V129, &sort_M_Reified_xForm); ASSERT(sink__V110->context, !strcmp(SYMBOL(sub__V129),  "FORM" ));
      Term sub__V130 = LINK(sink__V110->context, SUB(sub__V129, 0)); int sub__V130_count = sub__V129_count*LINK_COUNT(sub__V130); permitUnusedInt(sub__V130_count);
      /* sub__V130 = &#0-0 */
      Term sub__V131 = LINK(sink__V110->context, SUB(sub__V129, 1)); int sub__V131_count = sub__V129_count*LINK_COUNT(sub__V131); permitUnusedInt(sub__V131_count);
      /* sub__V131 = &#0-1 */
      Term sub__V132 = LINK(sink__V110->context, SUB(term__V111, 1)); int sub__V132_count = term__V111_count*LINK_COUNT(sub__V132); permitUnusedInt(sub__V132_count);
      /* sub__V132 = &#2 */
      
      NamedPropertyLink namedP__V133 = LINK_NamedPropertyLink(sink__V110->context, NAMED_PROPERTIES(term__V111));
      VariablePropertyLink varP__V134 = LINK_VariablePropertyLink(sink__V110->context, VARIABLE_PROPERTIES(term__V111));
      Hashset namedFV__V135 = LINK_VARIABLESET(sink__V110->context, asConstruction(term__V111)->nfvs);
      Hashset varFV__V136 = LINK_VARIABLESET(sink__V110->context, variablePropertyFreeVars(varP__V134));
      UNLINK(sink__V110->context, term__V111);
      ADD_PROPERTIES(sink__V110, LINK_VARIABLESET(sink__V110->context, namedFV__V135), LINK_VARIABLESET(sink__V110->context, varFV__V136), LINK_NamedPropertyLink(sink__V110->context, namedP__V133), LINK_VariablePropertyLink(sink__V110->context, varP__V134));
      { START(sink__V110, _M_S_Data_Form_s3);
        COPY(sink__V110, sub__V131);COPY(sink__V110, sub__V130);COPY(sink__V110, sub__V132);END(sink__V110, _M_S_Data_Form_s3); }
      UNLINK_VARIABLESET(sink__V110->context, namedFV__V135); UNLINK_VARIABLESET(sink__V110->context, varFV__V136);
      UNLINK_NamedPropertyLink(sink__V110->context, namedP__V133); UNLINK_VariablePropertyLink(sink__V110->context, varP__V134);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION S-Data-Form$3. */
int conBindOffs_M_S_Data_Form_s3[] = {0 , 0 , 0 , 0};
char *nameFun_M_S_Data_Form_s3(Term term) { return  "S-Data-Form$3" ; }
struct _ConstructionDescriptor descriptor_M_S_Data_Form_s3 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_S_Data_Form_s3), conBindOffs_M_S_Data_Form_s3, &nameFun_M_S_Data_Form_s3, &step_M_S_Data_Form_s3};

int step_M_S_Data_Form_s3(Sink sink__V137, Term term__V138)
{
  int term__V138_count = LINK_COUNT(term__V138); permitUnusedInt(term__V138_count);
  Term sub__V139 = FORCE(sink__V137->context, SUB(term__V138, 0));
  EnumOf_M__sList choice__V140 = (IS_VARIABLE_USE(sub__V139) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V139));
  switch (choice__V140)
  {
    case Data_M__sNil: { /* Function SORTS-S-Data-Form-3$S-Data-Form$3$$Nil case $Nil */
      ASSERT(sink__V137->context, !strcmp(SYMBOL(term__V138),  "S-Data-Form$3" ));
      Term sub__V141 = SUB(term__V138, 0); permitUnusedTerm(sub__V141); int sub__V141_count = term__V138_count*LINK_COUNT(sub__V141); permitUnusedInt(sub__V141_count);
      ASSERT(sink__V137->context, !strcmp(SYMBOL(sub__V141),  "$Nil" ));
      Term sub__V142 = LINK(sink__V137->context, SUB(term__V138, 1)); int sub__V142_count = term__V138_count*LINK_COUNT(sub__V142); permitUnusedInt(sub__V142_count);
      /* sub__V142 = &#0 */
      Term sub__V143 = LINK(sink__V137->context, SUB(term__V138, 2)); int sub__V143_count = term__V138_count*LINK_COUNT(sub__V143); permitUnusedInt(sub__V143_count);
      /* sub__V143 = &#1 */
      
      NamedPropertyLink namedP__V144 = LINK_NamedPropertyLink(sink__V137->context, NAMED_PROPERTIES(term__V138));
      VariablePropertyLink varP__V145 = LINK_VariablePropertyLink(sink__V137->context, VARIABLE_PROPERTIES(term__V138));
      Hashset namedFV__V146 = LINK_VARIABLESET(sink__V137->context, asConstruction(term__V138)->nfvs);
      Hashset varFV__V147 = LINK_VARIABLESET(sink__V137->context, variablePropertyFreeVars(varP__V145));
      UNLINK(sink__V137->context, term__V138);
      ADD_PROPERTIES(sink__V137, LINK_VARIABLESET(sink__V137->context, namedFV__V146), LINK_VARIABLESET(sink__V137->context, varFV__V147), LINK_NamedPropertyLink(sink__V137->context, namedP__V144), LINK_VariablePropertyLink(sink__V137->context, varP__V145));
      { START(sink__V137, _M_S_Data_Form_s5);
        COPY(sink__V137, sub__V142);COPY(sink__V137, sub__V143);END(sink__V137, _M_S_Data_Form_s5); }
      UNLINK_VARIABLESET(sink__V137->context, namedFV__V146); UNLINK_VARIABLESET(sink__V137->context, varFV__V147);
      UNLINK_NamedPropertyLink(sink__V137->context, namedP__V144); UNLINK_VariablePropertyLink(sink__V137->context, varP__V145);
      
      return 1;
    break; } case Data_M__sCons: { /* Function SORTS-S-Data-Form-4$S-Data-Form$3$$Cons case $Cons */
      ASSERT(sink__V137->context, !strcmp(SYMBOL(term__V138),  "S-Data-Form$3" ));
      Term sub__V148 = SUB(term__V138, 0); permitUnusedTerm(sub__V148); int sub__V148_count = term__V138_count*LINK_COUNT(sub__V148); permitUnusedInt(sub__V148_count);
      ASSERT(sink__V137->context, !strcmp(SYMBOL(sub__V148),  "$Cons" ));
      Term sub__V149 = LINK(sink__V137->context, SUB(sub__V148, 0)); int sub__V149_count = sub__V148_count*LINK_COUNT(sub__V149); permitUnusedInt(sub__V149_count);
      /* sub__V149 = &#0-0 */
      Term sub__V150 = LINK(sink__V137->context, SUB(sub__V148, 1)); int sub__V150_count = sub__V148_count*LINK_COUNT(sub__V150); permitUnusedInt(sub__V150_count);
      /* sub__V150 = &#0-1 */
      Term sub__V151 = LINK(sink__V137->context, SUB(term__V138, 1)); int sub__V151_count = term__V138_count*LINK_COUNT(sub__V151); permitUnusedInt(sub__V151_count);
      /* sub__V151 = &#2 */
      Term sub__V152 = LINK(sink__V137->context, SUB(term__V138, 2)); int sub__V152_count = term__V138_count*LINK_COUNT(sub__V152); permitUnusedInt(sub__V152_count);
      /* sub__V152 = &#3 */
      
      NamedPropertyLink namedP__V153 = LINK_NamedPropertyLink(sink__V137->context, NAMED_PROPERTIES(term__V138));
      VariablePropertyLink varP__V154 = LINK_VariablePropertyLink(sink__V137->context, VARIABLE_PROPERTIES(term__V138));
      Hashset namedFV__V155 = LINK_VARIABLESET(sink__V137->context, asConstruction(term__V138)->nfvs);
      Hashset varFV__V156 = LINK_VARIABLESET(sink__V137->context, variablePropertyFreeVars(varP__V154));
      UNLINK(sink__V137->context, term__V138);
      ADD_PROPERTIES(sink__V137, LINK_VARIABLESET(sink__V137->context, namedFV__V155), LINK_VARIABLESET(sink__V137->context, varFV__V156), LINK_NamedPropertyLink(sink__V137->context, namedP__V153), LINK_VariablePropertyLink(sink__V137->context, varP__V154));
      { START(sink__V137, _M_S_Data_Form_s4);
        COPY(sink__V137, sub__V149);COPY(sink__V137, sub__V150);COPY(sink__V137, sub__V151);COPY(sink__V137, sub__V152);END(sink__V137, _M_S_Data_Form_s4); }
      UNLINK_VARIABLESET(sink__V137->context, namedFV__V155); UNLINK_VARIABLESET(sink__V137->context, varFV__V156);
      UNLINK_NamedPropertyLink(sink__V137->context, namedP__V153); UNLINK_VariablePropertyLink(sink__V137->context, varP__V154);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION S-Data-Form$4. */
int conBindOffs_M_S_Data_Form_s4[] = {0 , 0 , 0 , 0 , 0};
char *nameFun_M_S_Data_Form_s4(Term term) { return  "S-Data-Form$4" ; }
struct _ConstructionDescriptor descriptor_M_S_Data_Form_s4 = {&sort_M_Reified_xVariable, 0, 4, sizeof(STRUCT_Con_M_S_Data_Form_s4), conBindOffs_M_S_Data_Form_s4, &nameFun_M_S_Data_Form_s4, &step_M_S_Data_Form_s4};

int step_M_S_Data_Form_s4(Sink sink__V157, Term term__V158)
{
  int term__V158_count = LINK_COUNT(term__V158); permitUnusedInt(term__V158_count);
  do {
    /* Contraction rule SORTS-S-Data-Form-4. */
    ASSERT(sink__V157->context, !strcmp(SYMBOL(term__V158),  "S-Data-Form$4" ));
    Term sub__V159 = LINK(sink__V157->context, SUB(term__V158, 0)); int sub__V159_count = term__V158_count*LINK_COUNT(sub__V159); permitUnusedInt(sub__V159_count);
    UNLINK_SUB(sink__V157->context, term__V158,  0); NORMALIZE(sink__V157->context, sub__V159); SUB(term__V158,  0) = LINK(sink__V157->context, sub__V159);
    /* sub__V159 = &#221 */
    Term sub__V160 = LINK(sink__V157->context, SUB(term__V158, 1)); int sub__V160_count = term__V158_count*LINK_COUNT(sub__V160); permitUnusedInt(sub__V160_count);
    UNLINK_SUB(sink__V157->context, term__V158,  1); NORMALIZE(sink__V157->context, sub__V160); SUB(term__V158,  1) = LINK(sink__V157->context, sub__V160);
    /* sub__V160 = &#222 */
    Term sub__V161 = LINK(sink__V157->context, SUB(term__V158, 2)); int sub__V161_count = term__V158_count*LINK_COUNT(sub__V161); permitUnusedInt(sub__V161_count);
    UNLINK_SUB(sink__V157->context, term__V158,  2); NORMALIZE(sink__V157->context, sub__V161); SUB(term__V158,  2) = LINK(sink__V157->context, sub__V161);
    /* sub__V161 = &#21 */
    Term sub__V162 = LINK(sink__V157->context, SUB(term__V158, 3)); int sub__V162_count = term__V158_count*LINK_COUNT(sub__V162); permitUnusedInt(sub__V162_count);
    /* sub__V162 = &#1 */
    
    NamedPropertyLink namedP__V163 = LINK_NamedPropertyLink(sink__V157->context, NAMED_PROPERTIES(term__V158));
    VariablePropertyLink varP__V164 = LINK_VariablePropertyLink(sink__V157->context, VARIABLE_PROPERTIES(term__V158));
    Hashset namedFV__V165 = LINK_VARIABLESET(sink__V157->context, asConstruction(term__V158)->nfvs);
    Hashset varFV__V166 = LINK_VARIABLESET(sink__V157->context, variablePropertyFreeVars(varP__V164));
    UNLINK(sink__V157->context, term__V158);
    { START(sink__V157, _M__sTextCons);
      { START(sink__V157, _M__sTextChars);
        LITERAL(sink__V157,  "int " ); END(sink__V157, _M__sTextChars); }
      { START(sink__V157, _M__sTextCons);
        { START(sink__V157, _M__sTextEmbed);
          { START(sink__V157, _M_AsText);
            { START(sink__V157, _M_BinderOffsets);
              COPY(sink__V157, LINK(sink__V157->context, sub__V161));END(sink__V157, _M_BinderOffsets); }
            END(sink__V157, _M_AsText); }
          END(sink__V157, _M__sTextEmbed); }
        { START(sink__V157, _M__sTextCons);
          { START(sink__V157, _M__sTextChars);
            LITERAL(sink__V157,  "[] = {0" ); END(sink__V157, _M__sTextChars); }
          { START(sink__V157, _M__sTextCons);
            { START(sink__V157, _M__sTextEmbed);
              { START(sink__V157, _M_AsText);
                { START(sink__V157, _M_DelayMapText_s1);
                  { START(sink__V157, _M_FormArguments__binder__offsets);
                    { START(sink__V157, _M__sCons);
                      COPY(sink__V157, sub__V159);COPY(sink__V157, LINK(sink__V157->context, sub__V160));END(sink__V157, _M__sCons); }
                    LITERAL(sink__V157,  "0" ); END(sink__V157, _M_FormArguments__binder__offsets); }
                  { Variable x__V167 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V157->context,"x__V167");
                    Variable x__V168 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V157->context,"x__V168");
                    Variable binds__V169[2] = {x__V167,x__V168}; BINDS(sink__V157, 2, binds__V169);
                    { START(sink__V157, _M__sTextCons);
                      { START(sink__V157, _M__sTextChars);
                        LITERAL(sink__V157,  " , " ); END(sink__V157, _M__sTextChars); }
                      { START(sink__V157, _M__sTextCons);
                        { START(sink__V157, _M__sTextEmbed);
                          { START(sink__V157, _M_AsText);
                            { START(sink__V157, _M_DINTEGER);
                              USE(sink__V157, x__V167); USE(sink__V157, x__V168); END(sink__V157, _M_DINTEGER); }
                            END(sink__V157, _M_AsText); }
                          END(sink__V157, _M__sTextEmbed); }
                        { START(sink__V157, _M__sTextNil);
                          END(sink__V157, _M__sTextNil); }
                        END(sink__V157, _M__sTextCons); }
                      END(sink__V157, _M__sTextCons); }
                     }
                  END(sink__V157, _M_DelayMapText_s1); }
                END(sink__V157, _M_AsText); }
              END(sink__V157, _M__sTextEmbed); }
            { START(sink__V157, _M__sTextCons);
              { START(sink__V157, _M__sTextChars);
                LITERAL(sink__V157,  "};" ); END(sink__V157, _M__sTextChars); }
              { START(sink__V157, _M__sTextCons);
                { START(sink__V157, _M__sTextBreak);
                  LITERAL(sink__V157,  "\n" ); END(sink__V157, _M__sTextBreak); }
                { START(sink__V157, _M__sTextCons);
                  { START(sink__V157, _M__sTextChars);
                    LITERAL(sink__V157,  "char *" ); END(sink__V157, _M__sTextChars); }
                  { START(sink__V157, _M__sTextCons);
                    { START(sink__V157, _M__sTextEmbed);
                      { START(sink__V157, _M_AsText);
                        { START(sink__V157, _M_Name);
                          COPY(sink__V157, LINK(sink__V157->context, sub__V161));END(sink__V157, _M_Name); }
                        END(sink__V157, _M_AsText); }
                      END(sink__V157, _M__sTextEmbed); }
                    { START(sink__V157, _M__sTextCons);
                      { START(sink__V157, _M__sTextChars);
                        LITERAL(sink__V157,  " = " ); END(sink__V157, _M__sTextChars); }
                      { START(sink__V157, _M__sTextCons);
                        { START(sink__V157, _M__sTextEmbed);
                          { START(sink__V157, _M_AsText);
                            { START(sink__V157, _M_STRING);
                              COPY(sink__V157, LINK(sink__V157->context, sub__V161));END(sink__V157, _M_STRING); }
                            END(sink__V157, _M_AsText); }
                          END(sink__V157, _M__sTextEmbed); }
                        { START(sink__V157, _M__sTextCons);
                          { START(sink__V157, _M__sTextChars);
                            LITERAL(sink__V157,  ";" ); END(sink__V157, _M__sTextChars); }
                          { START(sink__V157, _M__sTextCons);
                            { START(sink__V157, _M__sTextBreak);
                              LITERAL(sink__V157,  "\n" ); END(sink__V157, _M__sTextBreak); }
                            { START(sink__V157, _M__sTextCons);
                              { START(sink__V157, _M__sTextChars);
                                LITERAL(sink__V157,  "char *" ); END(sink__V157, _M__sTextChars); }
                              { START(sink__V157, _M__sTextCons);
                                { START(sink__V157, _M__sTextEmbed);
                                  { START(sink__V157, _M_AsText);
                                    { START(sink__V157, _M_NameFun);
                                      COPY(sink__V157, LINK(sink__V157->context, sub__V161));END(sink__V157, _M_NameFun); }
                                    END(sink__V157, _M_AsText); }
                                  END(sink__V157, _M__sTextEmbed); }
                                { START(sink__V157, _M__sTextCons);
                                  { START(sink__V157, _M__sTextChars);
                                    LITERAL(sink__V157,  "(Term term) { return " );
                                    END(sink__V157, _M__sTextChars); }
                                  { START(sink__V157, _M__sTextCons);
                                    { START(sink__V157, _M__sTextEmbed);
                                      { START(sink__V157, _M_AsText);
                                        { START(sink__V157, _M_Name);
                                          COPY(sink__V157, LINK(sink__V157->context, sub__V161));END(sink__V157, _M_Name); }
                                        END(sink__V157, _M_AsText); }
                                      END(sink__V157, _M__sTextEmbed); }
                                    { START(sink__V157, _M__sTextCons);
                                      { START(sink__V157, _M__sTextChars);
                                        LITERAL(sink__V157,  "; }" ); END(sink__V157, _M__sTextChars); }
                                      { START(sink__V157, _M__sTextCons);
                                        { START(sink__V157, _M__sTextBreak);
                                          LITERAL(sink__V157,  "\n" ); END(sink__V157, _M__sTextBreak); }
                                        { START(sink__V157, _M__sTextCons);
                                          { START(sink__V157, _M__sTextChars);
                                            LITERAL(sink__V157,  "struct _ConstructionDescriptor " );
                                            END(sink__V157, _M__sTextChars); }
                                          { START(sink__V157, _M__sTextCons);
                                            { START(sink__V157, _M__sTextEmbed);
                                              { START(sink__V157, _M_AsText);
                                                { START(sink__V157, _M_Descriptor);
                                                  COPY(sink__V157, LINK(sink__V157->context, sub__V161));END(sink__V157, _M_Descriptor); }
                                                END(sink__V157, _M_AsText); }
                                              END(sink__V157, _M__sTextEmbed); }
                                            { START(sink__V157, _M__sTextCons);
                                              { START(sink__V157, _M__sTextChars);
                                                LITERAL(sink__V157,  " = {&" );
                                                END(sink__V157, _M__sTextChars); }
                                              { START(sink__V157, _M__sTextCons);
                                                { START(sink__V157, _M__sTextEmbed);
                                                  { START(sink__V157, _M_AsText);
                                                    { START(sink__V157, _M_Sort);
                                                      COPY(sink__V157, sub__V162);END(sink__V157, _M_Sort); }
                                                    END(sink__V157, _M_AsText); }
                                                  END(sink__V157, _M__sTextEmbed); }
                                                { START(sink__V157, _M__sTextCons);
                                                  { START(sink__V157, _M__sTextChars);
                                                    LITERAL(sink__V157,  ", " );
                                                    END(sink__V157, _M__sTextChars); }
                                                  { START(sink__V157, _M__sTextCons);
                                                    { START(sink__V157, _M__sTextEmbed);
                                                      { START(sink__V157, _M_AsText);
                                                        { START(sink__V157, _M_EnumTag);
                                                          COPY(sink__V157, LINK(sink__V157->context, sub__V161));END(sink__V157, _M_EnumTag); }
                                                        END(sink__V157, _M_AsText); }
                                                      END(sink__V157, _M__sTextEmbed); }
                                                    { START(sink__V157, _M__sTextCons);
                                                      { START(sink__V157, _M__sTextChars);
                                                        LITERAL(sink__V157,  ", " );
                                                        END(sink__V157, _M__sTextChars); }
                                                      { START(sink__V157, _M__sTextCons);
                                                        { START(sink__V157, _M__sTextEmbed);
                                                          { START(sink__V157, _M_AsText);
                                                            { START(sink__V157, _M_INTEGER);
                                                              { START(sink__V157, _M_Length);
                                                                COPY(sink__V157, sub__V160);LITERAL(sink__V157,  "1" );
                                                                END(sink__V157, _M_Length); }
                                                              END(sink__V157, _M_INTEGER); }
                                                            END(sink__V157, _M_AsText); }
                                                          END(sink__V157, _M__sTextEmbed); }
                                                        { START(sink__V157, _M__sTextCons);
                                                          { START(sink__V157, _M__sTextChars);
                                                            LITERAL(sink__V157,  ", sizeof(STRUCT" );
                                                            END(sink__V157, _M__sTextChars); }
                                                          { START(sink__V157, _M__sTextCons);
                                                            { START(sink__V157, _M__sTextEmbed);
                                                              { START(sink__V157, _M_AsText);
                                                                { START(sink__V157, _M_Struct);
                                                                  COPY(sink__V157, LINK(sink__V157->context, sub__V161));END(sink__V157, _M_Struct); }
                                                                END(sink__V157, _M_AsText); }
                                                              END(sink__V157, _M__sTextEmbed); }
                                                            { START(sink__V157, _M__sTextCons);
                                                              { START(sink__V157, _M__sTextChars);
                                                                LITERAL(sink__V157,  "), " );
                                                                END(sink__V157, _M__sTextChars); }
                                                              { START(sink__V157, _M__sTextCons);
                                                                { START(sink__V157, _M__sTextEmbed);
                                                                  { START(sink__V157, _M_AsText);
                                                                    { START(sink__V157, _M_BinderOffsets);
                                                                      COPY(sink__V157, LINK(sink__V157->context, sub__V161));END(sink__V157, _M_BinderOffsets); }
                                                                    END(sink__V157, _M_AsText); }
                                                                  END(sink__V157, _M__sTextEmbed); }
                                                                { START(sink__V157, _M__sTextCons);
                                                                  { START(sink__V157, _M__sTextChars);
                                                                    LITERAL(sink__V157,  ", &" );
                                                                    END(sink__V157, _M__sTextChars); }
                                                                  { START(sink__V157, _M__sTextCons);
                                                                    { START(sink__V157, _M__sTextEmbed);
                                                                      { START(sink__V157, _M_AsText);
                                                                        { START(sink__V157, _M_NameFun);
                                                                          COPY(sink__V157, sub__V161);END(sink__V157, _M_NameFun); }
                                                                        END(sink__V157, _M_AsText); }
                                                                      END(sink__V157, _M__sTextEmbed); }
                                                                    { START(sink__V157, _M__sTextCons);
                                                                      { START(sink__V157, _M__sTextChars);
                                                                        LITERAL(sink__V157,  ", &dataStep};" );
                                                                        END(sink__V157, _M__sTextChars); }
                                                                      { START(sink__V157, _M__sTextCons);
                                                                        { START(sink__V157, _M__sTextBreak);
                                                                          LITERAL(sink__V157,  "\n" );
                                                                          END(sink__V157, _M__sTextBreak); }
                                                                        { START(sink__V157, _M__sTextNil);
                                                                          END(sink__V157, _M__sTextNil); }
                                                                        END(sink__V157, _M__sTextCons); }
                                                                      END(sink__V157, _M__sTextCons); }
                                                                    END(sink__V157, _M__sTextCons); }
                                                                  END(sink__V157, _M__sTextCons); }
                                                                END(sink__V157, _M__sTextCons); }
                                                              END(sink__V157, _M__sTextCons); }
                                                            END(sink__V157, _M__sTextCons); }
                                                          END(sink__V157, _M__sTextCons); }
                                                        END(sink__V157, _M__sTextCons); }
                                                      END(sink__V157, _M__sTextCons); }
                                                    END(sink__V157, _M__sTextCons); }
                                                  END(sink__V157, _M__sTextCons); }
                                                END(sink__V157, _M__sTextCons); }
                                              END(sink__V157, _M__sTextCons); }
                                            END(sink__V157, _M__sTextCons); }
                                          END(sink__V157, _M__sTextCons); }
                                        END(sink__V157, _M__sTextCons); }
                                      END(sink__V157, _M__sTextCons); }
                                    END(sink__V157, _M__sTextCons); }
                                  END(sink__V157, _M__sTextCons); }
                                END(sink__V157, _M__sTextCons); }
                              END(sink__V157, _M__sTextCons); }
                            END(sink__V157, _M__sTextCons); }
                          END(sink__V157, _M__sTextCons); }
                        END(sink__V157, _M__sTextCons); }
                      END(sink__V157, _M__sTextCons); }
                    END(sink__V157, _M__sTextCons); }
                  END(sink__V157, _M__sTextCons); }
                END(sink__V157, _M__sTextCons); }
              END(sink__V157, _M__sTextCons); }
            END(sink__V157, _M__sTextCons); }
          END(sink__V157, _M__sTextCons); }
        END(sink__V157, _M__sTextCons); }
      END(sink__V157, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V157->context, namedFV__V165); UNLINK_VARIABLESET(sink__V157->context, varFV__V166);
    UNLINK_NamedPropertyLink(sink__V157->context, namedP__V163); UNLINK_VariablePropertyLink(sink__V157->context, varP__V164);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION S-Data-Form$5. */
int conBindOffs_M_S_Data_Form_s5[] = {0 , 0 , 0};
char *nameFun_M_S_Data_Form_s5(Term term) { return  "S-Data-Form$5" ; }
struct _ConstructionDescriptor descriptor_M_S_Data_Form_s5 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_S_Data_Form_s5), conBindOffs_M_S_Data_Form_s5, &nameFun_M_S_Data_Form_s5, &step_M_S_Data_Form_s5};

int step_M_S_Data_Form_s5(Sink sink__V170, Term term__V171)
{
  int term__V171_count = LINK_COUNT(term__V171); permitUnusedInt(term__V171_count);
  do {
    /* Contraction rule SORTS-S-Data-Form-3. */
    ASSERT(sink__V170->context, !strcmp(SYMBOL(term__V171),  "S-Data-Form$5" ));
    Term sub__V172 = LINK(sink__V170->context, SUB(term__V171, 0)); int sub__V172_count = term__V171_count*LINK_COUNT(sub__V172); permitUnusedInt(sub__V172_count);
    UNLINK_SUB(sink__V170->context, term__V171,  0); NORMALIZE(sink__V170->context, sub__V172); SUB(term__V171,  0) = LINK(sink__V170->context, sub__V172);
    /* sub__V172 = &#21 */
    Term sub__V173 = LINK(sink__V170->context, SUB(term__V171, 1)); int sub__V173_count = term__V171_count*LINK_COUNT(sub__V173); permitUnusedInt(sub__V173_count);
    /* sub__V173 = &#1 */
    
    NamedPropertyLink namedP__V174 = LINK_NamedPropertyLink(sink__V170->context, NAMED_PROPERTIES(term__V171));
    VariablePropertyLink varP__V175 = LINK_VariablePropertyLink(sink__V170->context, VARIABLE_PROPERTIES(term__V171));
    Hashset namedFV__V176 = LINK_VARIABLESET(sink__V170->context, asConstruction(term__V171)->nfvs);
    Hashset varFV__V177 = LINK_VARIABLESET(sink__V170->context, variablePropertyFreeVars(varP__V175));
    UNLINK(sink__V170->context, term__V171);
    { START(sink__V170, _M__sTextCons);
      { START(sink__V170, _M__sTextChars);
        LITERAL(sink__V170,  "char *" ); END(sink__V170, _M__sTextChars); }
      { START(sink__V170, _M__sTextCons);
        { START(sink__V170, _M__sTextEmbed);
          { START(sink__V170, _M_AsText);
            { START(sink__V170, _M_Name);
              COPY(sink__V170, LINK(sink__V170->context, sub__V172));END(sink__V170, _M_Name); }
            END(sink__V170, _M_AsText); }
          END(sink__V170, _M__sTextEmbed); }
        { START(sink__V170, _M__sTextCons);
          { START(sink__V170, _M__sTextChars);
            LITERAL(sink__V170,  " = " ); END(sink__V170, _M__sTextChars); }
          { START(sink__V170, _M__sTextCons);
            { START(sink__V170, _M__sTextEmbed);
              { START(sink__V170, _M_AsText);
                { START(sink__V170, _M_STRING);
                  COPY(sink__V170, LINK(sink__V170->context, sub__V172));END(sink__V170, _M_STRING); }
                END(sink__V170, _M_AsText); }
              END(sink__V170, _M__sTextEmbed); }
            { START(sink__V170, _M__sTextCons);
              { START(sink__V170, _M__sTextChars);
                LITERAL(sink__V170,  ";" ); END(sink__V170, _M__sTextChars); }
              { START(sink__V170, _M__sTextCons);
                { START(sink__V170, _M__sTextBreak);
                  LITERAL(sink__V170,  "\n" ); END(sink__V170, _M__sTextBreak); }
                { START(sink__V170, _M__sTextCons);
                  { START(sink__V170, _M__sTextChars);
                    LITERAL(sink__V170,  "char *" ); END(sink__V170, _M__sTextChars); }
                  { START(sink__V170, _M__sTextCons);
                    { START(sink__V170, _M__sTextEmbed);
                      { START(sink__V170, _M_AsText);
                        { START(sink__V170, _M_NameFun);
                          COPY(sink__V170, LINK(sink__V170->context, sub__V172));END(sink__V170, _M_NameFun); }
                        END(sink__V170, _M_AsText); }
                      END(sink__V170, _M__sTextEmbed); }
                    { START(sink__V170, _M__sTextCons);
                      { START(sink__V170, _M__sTextChars);
                        LITERAL(sink__V170,  "(Term term) { return " );
                        END(sink__V170, _M__sTextChars); }
                      { START(sink__V170, _M__sTextCons);
                        { START(sink__V170, _M__sTextEmbed);
                          { START(sink__V170, _M_AsText);
                            { START(sink__V170, _M_Name);
                              COPY(sink__V170, LINK(sink__V170->context, sub__V172));END(sink__V170, _M_Name); }
                            END(sink__V170, _M_AsText); }
                          END(sink__V170, _M__sTextEmbed); }
                        { START(sink__V170, _M__sTextCons);
                          { START(sink__V170, _M__sTextChars);
                            LITERAL(sink__V170,  "; }" ); END(sink__V170, _M__sTextChars); }
                          { START(sink__V170, _M__sTextCons);
                            { START(sink__V170, _M__sTextBreak);
                              LITERAL(sink__V170,  "\n" ); END(sink__V170, _M__sTextBreak); }
                            { START(sink__V170, _M__sTextCons);
                              { START(sink__V170, _M__sTextChars);
                                LITERAL(sink__V170,  "struct _ConstructionDescriptor " );
                                END(sink__V170, _M__sTextChars); }
                              { START(sink__V170, _M__sTextCons);
                                { START(sink__V170, _M__sTextEmbed);
                                  { START(sink__V170, _M_AsText);
                                    { START(sink__V170, _M_Descriptor);
                                      COPY(sink__V170, LINK(sink__V170->context, sub__V172));END(sink__V170, _M_Descriptor); }
                                    END(sink__V170, _M_AsText); }
                                  END(sink__V170, _M__sTextEmbed); }
                                { START(sink__V170, _M__sTextCons);
                                  { START(sink__V170, _M__sTextChars);
                                    LITERAL(sink__V170,  " = {&" ); END(sink__V170, _M__sTextChars); }
                                  { START(sink__V170, _M__sTextCons);
                                    { START(sink__V170, _M__sTextEmbed);
                                      { START(sink__V170, _M_AsText);
                                        { START(sink__V170, _M_Sort);
                                          COPY(sink__V170, sub__V173);END(sink__V170, _M_Sort); }
                                        END(sink__V170, _M_AsText); }
                                      END(sink__V170, _M__sTextEmbed); }
                                    { START(sink__V170, _M__sTextCons);
                                      { START(sink__V170, _M__sTextChars);
                                        LITERAL(sink__V170,  ", " ); END(sink__V170, _M__sTextChars); }
                                      { START(sink__V170, _M__sTextCons);
                                        { START(sink__V170, _M__sTextEmbed);
                                          { START(sink__V170, _M_AsText);
                                            { START(sink__V170, _M_EnumTag);
                                              COPY(sink__V170, LINK(sink__V170->context, sub__V172));END(sink__V170, _M_EnumTag); }
                                            END(sink__V170, _M_AsText); }
                                          END(sink__V170, _M__sTextEmbed); }
                                        { START(sink__V170, _M__sTextCons);
                                          { START(sink__V170, _M__sTextChars);
                                            LITERAL(sink__V170,  ", 0, sizeof(STRUCT" );
                                            END(sink__V170, _M__sTextChars); }
                                          { START(sink__V170, _M__sTextCons);
                                            { START(sink__V170, _M__sTextEmbed);
                                              { START(sink__V170, _M_AsText);
                                                { START(sink__V170, _M_Struct);
                                                  COPY(sink__V170, LINK(sink__V170->context, sub__V172));END(sink__V170, _M_Struct); }
                                                END(sink__V170, _M_AsText); }
                                              END(sink__V170, _M__sTextEmbed); }
                                            { START(sink__V170, _M__sTextCons);
                                              { START(sink__V170, _M__sTextChars);
                                                LITERAL(sink__V170,  "), noBinderOffsets, &" );
                                                END(sink__V170, _M__sTextChars); }
                                              { START(sink__V170, _M__sTextCons);
                                                { START(sink__V170, _M__sTextEmbed);
                                                  { START(sink__V170, _M_AsText);
                                                    { START(sink__V170, _M_NameFun);
                                                      COPY(sink__V170, sub__V172);END(sink__V170, _M_NameFun); }
                                                    END(sink__V170, _M_AsText); }
                                                  END(sink__V170, _M__sTextEmbed); }
                                                { START(sink__V170, _M__sTextCons);
                                                  { START(sink__V170, _M__sTextChars);
                                                    LITERAL(sink__V170,  ", &dataStep};" );
                                                    END(sink__V170, _M__sTextChars); }
                                                  { START(sink__V170, _M__sTextCons);
                                                    { START(sink__V170, _M__sTextBreak);
                                                      LITERAL(sink__V170,  "\n" );
                                                      END(sink__V170, _M__sTextBreak); }
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
            END(sink__V170, _M__sTextCons); }
          END(sink__V170, _M__sTextCons); }
        END(sink__V170, _M__sTextCons); }
      END(sink__V170, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V170->context, namedFV__V176); UNLINK_VARIABLESET(sink__V170->context, varFV__V177);
    UNLINK_NamedPropertyLink(sink__V170->context, namedP__V174); UNLINK_VariablePropertyLink(sink__V170->context, varP__V175);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION S-Data-Form$6. */
int conBindOffs_M_S_Data_Form_s6[] = {0 , 0};
char *nameFun_M_S_Data_Form_s6(Term term) { return  "S-Data-Form$6" ; }
struct _ConstructionDescriptor descriptor_M_S_Data_Form_s6 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_S_Data_Form_s6), conBindOffs_M_S_Data_Form_s6, &nameFun_M_S_Data_Form_s6, &step_M_S_Data_Form_s6};

int step_M_S_Data_Form_s6(Sink sink__V178, Term term__V179)
{
  int term__V179_count = LINK_COUNT(term__V179); permitUnusedInt(term__V179_count);
  do {
    /* Contraction rule SORTS-S-Data-Form-2. */
    ASSERT(sink__V178->context, !strcmp(SYMBOL(term__V179),  "S-Data-Form$6" ));
    Term sub__V180 = SUB(term__V179, 0); permitUnusedTerm(sub__V180); int sub__V180_count = term__V179_count*LINK_COUNT(sub__V180); permitUnusedInt(sub__V180_count);
    /* sub__V180 = &#1 */
    
    NamedPropertyLink namedP__V181 = LINK_NamedPropertyLink(sink__V178->context, NAMED_PROPERTIES(term__V179));
    VariablePropertyLink varP__V182 = LINK_VariablePropertyLink(sink__V178->context, VARIABLE_PROPERTIES(term__V179));
    Hashset namedFV__V183 = LINK_VARIABLESET(sink__V178->context, asConstruction(term__V179)->nfvs);
    Hashset varFV__V184 = LINK_VARIABLESET(sink__V178->context, variablePropertyFreeVars(varP__V182));
    UNLINK(sink__V178->context, term__V179);
    { START(sink__V178, _M__sTextNil); END(sink__V178, _M__sTextNil); }
    UNLINK_VARIABLESET(sink__V178->context, namedFV__V183); UNLINK_VARIABLESET(sink__V178->context, varFV__V184);
    UNLINK_NamedPropertyLink(sink__V178->context, namedP__V181); UNLINK_VariablePropertyLink(sink__V178->context, varP__V182);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION S-Data-Form$7. */
int conBindOffs_M_S_Data_Form_s7[] = {0 , 0 , 0 , 0 , 0};
char *nameFun_M_S_Data_Form_s7(Term term) { return  "S-Data-Form$7" ; }
struct _ConstructionDescriptor descriptor_M_S_Data_Form_s7 = {&sort_M_Reified_xVariable, 0, 4, sizeof(STRUCT_Con_M_S_Data_Form_s7), conBindOffs_M_S_Data_Form_s7, &nameFun_M_S_Data_Form_s7, &step_M_S_Data_Form_s7};

int step_M_S_Data_Form_s7(Sink sink__V185, Term term__V186)
{
  int term__V186_count = LINK_COUNT(term__V186); permitUnusedInt(term__V186_count);
  do {
    /* Contraction rule SORTS-S-Data-Form-1. */
    ASSERT(sink__V185->context, !strcmp(SYMBOL(term__V186),  "S-Data-Form$7" ));
    Term sub__V187 = SUB(term__V186, 0); permitUnusedTerm(sub__V187); int sub__V187_count = term__V186_count*LINK_COUNT(sub__V187); permitUnusedInt(sub__V187_count);
    CRSX_CHECK_SORT(sink__V185->context, sub__V187, &sort_M_Reified_xSort); /* sub__V187 = &#21 */
    Term sub__V188 = SUB(term__V186, 1); permitUnusedTerm(sub__V188); int sub__V188_count = term__V186_count*LINK_COUNT(sub__V188); permitUnusedInt(sub__V188_count);
    CRSX_CHECK_SORT(sink__V185->context, sub__V188, &sort_M_Reified_xSort); /* sub__V188 = &#22 */
    Term sub__V189 = LINK(sink__V185->context, SUB(term__V186, 2)); int sub__V189_count = term__V186_count*LINK_COUNT(sub__V189); permitUnusedInt(sub__V189_count);
    CRSX_CHECK_SORT(sink__V185->context, sub__V189, &sort_M_Reified_xForm); /* sub__V189 = &#23 */
    Term sub__V190 = LINK(sink__V185->context, SUB(term__V186, 3)); int sub__V190_count = term__V186_count*LINK_COUNT(sub__V190); permitUnusedInt(sub__V190_count);
    /* sub__V190 = &#1 */
    
    NamedPropertyLink namedP__V191 = LINK_NamedPropertyLink(sink__V185->context, NAMED_PROPERTIES(term__V186));
    VariablePropertyLink varP__V192 = LINK_VariablePropertyLink(sink__V185->context, VARIABLE_PROPERTIES(term__V186));
    Hashset namedFV__V193 = LINK_VARIABLESET(sink__V185->context, asConstruction(term__V186)->nfvs);
    Hashset varFV__V194 = LINK_VARIABLESET(sink__V185->context, variablePropertyFreeVars(varP__V192));
    UNLINK(sink__V185->context, term__V186);
    { START(sink__V185, _M_S_Data_Form_s1);
      COPY(sink__V185, sub__V189);COPY(sink__V185, sub__V190);END(sink__V185, _M_S_Data_Form_s1); }
    UNLINK_VARIABLESET(sink__V185->context, namedFV__V193); UNLINK_VARIABLESET(sink__V185->context, varFV__V194);
    UNLINK_NamedPropertyLink(sink__V185->context, namedP__V191); UNLINK_VariablePropertyLink(sink__V185->context, varP__V192);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION S-Declaration. */
int conBindOffs_M_S_Declaration[] = {0 , 0};
char *nameFun_M_S_Declaration(Term term) { return  "S-Declaration" ; }
struct _ConstructionDescriptor descriptor_M_S_Declaration = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_S_Declaration), conBindOffs_M_S_Declaration, &nameFun_M_S_Declaration, &step_M_S_Declaration};

int step_M_S_Declaration(Sink sink__V195, Term term__V196)
{
  int term__V196_count = LINK_COUNT(term__V196); permitUnusedInt(term__V196_count);
  Term sub__V197 = FORCE(sink__V195->context, SUB(term__V196, 0));
  EnumOf_M_Reified_xDeclaration choice__V198 = (IS_VARIABLE_USE(sub__V197) ? VarOf_M_Reified_xDeclaration : (EnumOf_M_Reified_xDeclaration) TAG(sub__V197));
  switch (choice__V198)
  {
    case Data_M_DATA: { /* Function SORTS-Data$S-Declaration$DATA case DATA */
      ASSERT(sink__V195->context, !strcmp(SYMBOL(term__V196),  "S-Declaration" ));
      Term sub__V199 = SUB(term__V196, 0); permitUnusedTerm(sub__V199); int sub__V199_count = term__V196_count*LINK_COUNT(sub__V199); permitUnusedInt(sub__V199_count);
      CRSX_CHECK_SORT(sink__V195->context, sub__V199, &sort_M_Reified_xDeclaration); ASSERT(sink__V195->context, !strcmp(SYMBOL(sub__V199),  "DATA" ));
      Term sub__V200 = LINK(sink__V195->context, SUB(sub__V199, 0)); int sub__V200_count = sub__V199_count*LINK_COUNT(sub__V200); permitUnusedInt(sub__V200_count);
      CRSX_CHECK_SORT(sink__V195->context, sub__V200, &sort_M_Reified_xSort); /* sub__V200 = &#0-0 */
      Term sub__V201 = LINK(sink__V195->context, SUB(sub__V199, 1)); int sub__V201_count = sub__V199_count*LINK_COUNT(sub__V201); permitUnusedInt(sub__V201_count);
      /* sub__V201 = &#0-1 */
      
      NamedPropertyLink namedP__V202 = LINK_NamedPropertyLink(sink__V195->context, NAMED_PROPERTIES(term__V196));
      VariablePropertyLink varP__V203 = LINK_VariablePropertyLink(sink__V195->context, VARIABLE_PROPERTIES(term__V196));
      Hashset namedFV__V204 = LINK_VARIABLESET(sink__V195->context, asConstruction(term__V196)->nfvs);
      Hashset varFV__V205 = LINK_VARIABLESET(sink__V195->context, variablePropertyFreeVars(varP__V203));
      UNLINK(sink__V195->context, term__V196);
      ADD_PROPERTIES(sink__V195, LINK_VARIABLESET(sink__V195->context, namedFV__V204), LINK_VARIABLESET(sink__V195->context, varFV__V205), LINK_NamedPropertyLink(sink__V195->context, namedP__V202), LINK_VariablePropertyLink(sink__V195->context, varP__V203));
      { START(sink__V195, _M_S_Declaration_s1);
        COPY(sink__V195, sub__V200);COPY(sink__V195, sub__V201);END(sink__V195, _M_S_Declaration_s1); }
      UNLINK_VARIABLESET(sink__V195->context, namedFV__V204); UNLINK_VARIABLESET(sink__V195->context, varFV__V205);
      UNLINK_NamedPropertyLink(sink__V195->context, namedP__V202); UNLINK_VariablePropertyLink(sink__V195->context, varP__V203);
      
      return 1;
    break; } case Data_M_FUNCTION: { /* Function SORTS-Function$S-Declaration$FUNCTION case FUNCTION */
      ASSERT(sink__V195->context, !strcmp(SYMBOL(term__V196),  "S-Declaration" ));
      Term sub__V206 = SUB(term__V196, 0); permitUnusedTerm(sub__V206); int sub__V206_count = term__V196_count*LINK_COUNT(sub__V206); permitUnusedInt(sub__V206_count);
      CRSX_CHECK_SORT(sink__V195->context, sub__V206, &sort_M_Reified_xDeclaration); ASSERT(sink__V195->context, !strcmp(SYMBOL(sub__V206),  "FUNCTION" ));
      Term sub__V207 = LINK(sink__V195->context, SUB(sub__V206, 0)); int sub__V207_count = sub__V206_count*LINK_COUNT(sub__V207); permitUnusedInt(sub__V207_count);
      /* sub__V207 = &#0-0 */
      Term sub__V208 = LINK(sink__V195->context, SUB(sub__V206, 1)); int sub__V208_count = sub__V206_count*LINK_COUNT(sub__V208); permitUnusedInt(sub__V208_count);
      /* sub__V208 = &#0-1 */
      Term sub__V209 = LINK(sink__V195->context, SUB(sub__V206, 2)); int sub__V209_count = sub__V206_count*LINK_COUNT(sub__V209); permitUnusedInt(sub__V209_count);
      /* sub__V209 = &#0-2 */
      Term sub__V210 = LINK(sink__V195->context, SUB(sub__V206, 3)); int sub__V210_count = sub__V206_count*LINK_COUNT(sub__V210); permitUnusedInt(sub__V210_count);
      /* sub__V210 = &#0-3 */
      Term sub__V211 = LINK(sink__V195->context, SUB(sub__V206, 4)); int sub__V211_count = sub__V206_count*LINK_COUNT(sub__V211); permitUnusedInt(sub__V211_count);
      /* sub__V211 = &#0-4 */
      Term sub__V212 = LINK(sink__V195->context, SUB(sub__V206, 5)); int sub__V212_count = sub__V206_count*LINK_COUNT(sub__V212); permitUnusedInt(sub__V212_count);
      CRSX_CHECK_SORT(sink__V195->context, sub__V212, &sort_M_Reified_xSort); /* sub__V212 = &#0-5 */
      Term sub__V213 = LINK(sink__V195->context, SUB(sub__V206, 6)); int sub__V213_count = sub__V206_count*LINK_COUNT(sub__V213); permitUnusedInt(sub__V213_count);
      /* sub__V213 = &#0-6 */
      
      NamedPropertyLink namedP__V214 = LINK_NamedPropertyLink(sink__V195->context, NAMED_PROPERTIES(term__V196));
      VariablePropertyLink varP__V215 = LINK_VariablePropertyLink(sink__V195->context, VARIABLE_PROPERTIES(term__V196));
      Hashset namedFV__V216 = LINK_VARIABLESET(sink__V195->context, asConstruction(term__V196)->nfvs);
      Hashset varFV__V217 = LINK_VARIABLESET(sink__V195->context, variablePropertyFreeVars(varP__V215));
      UNLINK(sink__V195->context, term__V196);
      ADD_PROPERTIES(sink__V195, LINK_VARIABLESET(sink__V195->context, namedFV__V216), LINK_VARIABLESET(sink__V195->context, varFV__V217), LINK_NamedPropertyLink(sink__V195->context, namedP__V214), LINK_VariablePropertyLink(sink__V195->context, varP__V215));
      { START(sink__V195, _M_S_Declaration_s2);
        COPY(sink__V195, sub__V207);COPY(sink__V195, sub__V208);COPY(sink__V195, sub__V209);COPY(sink__V195, sub__V210);COPY(sink__V195, sub__V211);COPY(sink__V195, sub__V212);COPY(sink__V195, sub__V213);END(sink__V195, _M_S_Declaration_s2); }
      UNLINK_VARIABLESET(sink__V195->context, namedFV__V216); UNLINK_VARIABLESET(sink__V195->context, varFV__V217);
      UNLINK_NamedPropertyLink(sink__V195->context, namedP__V214); UNLINK_VariablePropertyLink(sink__V195->context, varP__V215);
      
      return 1;
    break; } case Data_M_POLYMORPHIC: { /* Function SORTS-Polymorphic$S-Declaration$POLYMORPHIC case POLYMORPHIC */
      ASSERT(sink__V195->context, !strcmp(SYMBOL(term__V196),  "S-Declaration" ));
      Term sub__V218 = SUB(term__V196, 0); permitUnusedTerm(sub__V218); int sub__V218_count = term__V196_count*LINK_COUNT(sub__V218); permitUnusedInt(sub__V218_count);
      CRSX_CHECK_SORT(sink__V195->context, sub__V218, &sort_M_Reified_xDeclaration); ASSERT(sink__V195->context, !strcmp(SYMBOL(sub__V218),  "POLYMORPHIC" ));
      Variable y__V219 = BINDER(sub__V218,0,0); if (sub__V218_count <= 1) UNBIND(y__V219);
      Term sub__V220 = LINK(sink__V195->context, SUB(sub__V218, 0)); int sub__V220_count = sub__V218_count*LINK_COUNT(sub__V220); permitUnusedInt(sub__V220_count);
      CRSX_CHECK_SORT(sink__V195->context, sub__V220, &sort_M_Reified_xDeclaration); /* sub__V220 = &#0-0 */
      
      NamedPropertyLink namedP__V221 = LINK_NamedPropertyLink(sink__V195->context, NAMED_PROPERTIES(term__V196));
      VariablePropertyLink varP__V222 = LINK_VariablePropertyLink(sink__V195->context, VARIABLE_PROPERTIES(term__V196));
      Hashset namedFV__V223 = LINK_VARIABLESET(sink__V195->context, asConstruction(term__V196)->nfvs);
      Hashset varFV__V224 = LINK_VARIABLESET(sink__V195->context, variablePropertyFreeVars(varP__V222));
      UNLINK(sink__V195->context, term__V196);
      ADD_PROPERTIES(sink__V195, LINK_VARIABLESET(sink__V195->context, namedFV__V223), LINK_VARIABLESET(sink__V195->context, varFV__V224), LINK_NamedPropertyLink(sink__V195->context, namedP__V221), LINK_VariablePropertyLink(sink__V195->context, varP__V222));
      { START(sink__V195, _M_S_Declaration_s3);
        { if (!IS_BOUND(y__V219)) { REBIND(y__V219);
            Variable binds__V225[1] = {y__V219}; BINDS(sink__V195, 1, binds__V225);
            COPY(sink__V195, sub__V220); /* REUSED SUBSTITUTION */  }
          else { Variable b__V226 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V195->context,"b__V226");
            Variable binds__V227[1] = {b__V226}; BINDS(sink__V195, 1, binds__V227);
            {
              Term arg__V228;
              { Sink buf__V229 = ALLOCA_BUFFER(sink__V195->context);
                USE(buf__V229, b__V226); arg__V228 = BUFFER_TERM(buf__V229); FREE_BUFFER(buf__V229); }
              Variable vars__V230[1] = {y__V219};
              Term args__V231[1] = {arg__V228};
              struct _SubstitutionFrame substitution__V232 = {NULL, 0, 1, vars__V230, args__V231, NULL};
              SUBSTITUTE(sink__V195, sub__V220, &substitution__V232); }
                }
           }
        END(sink__V195, _M_S_Declaration_s3); }
      UNLINK_VARIABLESET(sink__V195->context, namedFV__V223); UNLINK_VARIABLESET(sink__V195->context, varFV__V224);
      UNLINK_NamedPropertyLink(sink__V195->context, namedP__V221); UNLINK_VariablePropertyLink(sink__V195->context, varP__V222);
      
      return 1;
    } default: break;
  }
  return 0;
}

#ifdef __cplusplus
}
#endif
/* END OF C RULES FOR CRSX CRSXC MODULE SORTS. */
