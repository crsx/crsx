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
      UNLINK(sink__V1->context, term__V2);
      ADD_PROPERTIES(sink__V1, LINK_NamedPropertyLink(sink__V1->context, namedP__V9), LINK_VariablePropertyLink(sink__V1->context, varP__V10));
      { START(sink__V1, _M_S_Data_s1);
        COPY(sink__V1, sub__V6);COPY(sink__V1, sub__V7);COPY(sink__V1, sub__V8);END(sink__V1, _M_S_Data_s1); }
      UNLINK_NamedPropertyLink(sink__V1->context, namedP__V9); UNLINK_VariablePropertyLink(sink__V1->context, varP__V10);
      
      return 1;
    break; } case Data_M_SORT_PROPERTY: { /* Function SORTS-S-Data-2$S-Data$SORT-PROPERTY case SORT-PROPERTY */
      ASSERT(sink__V1->context, !strcmp(SYMBOL(term__V2),  "S-Data" ));
      Term sub__V11 = SUB(term__V2, 0); permitUnusedTerm(sub__V11); int sub__V11_count = term__V2_count*LINK_COUNT(sub__V11); permitUnusedInt(sub__V11_count);
      CRSX_CHECK_SORT(sink__V1->context, sub__V11, &sort_M_Reified_xSort); ASSERT(sink__V1->context, !strcmp(SYMBOL(sub__V11),  "SORT-PROPERTY" ));
      Term sub__V12 = LINK(sink__V1->context, SUB(sub__V11, 0)); int sub__V12_count = sub__V11_count*LINK_COUNT(sub__V12); permitUnusedInt(sub__V12_count);
      CRSX_CHECK_SORT(sink__V1->context, sub__V12, &sort_M_Reified_xSort); /* sub__V12 = &#0-0 */
      Term sub__V13 = LINK(sink__V1->context, SUB(sub__V11, 1)); int sub__V13_count = sub__V11_count*LINK_COUNT(sub__V13); permitUnusedInt(sub__V13_count);
      CRSX_CHECK_SORT(sink__V1->context, sub__V13, &sort_M_Reified_xSort); /* sub__V13 = &#0-1 */
      Term sub__V14 = LINK(sink__V1->context, SUB(sub__V11, 2)); int sub__V14_count = sub__V11_count*LINK_COUNT(sub__V14); permitUnusedInt(sub__V14_count);
      CRSX_CHECK_SORT(sink__V1->context, sub__V14, &sort_M_Reified_xSort); /* sub__V14 = &#0-2 */
      Term sub__V15 = LINK(sink__V1->context, SUB(term__V2, 1)); int sub__V15_count = term__V2_count*LINK_COUNT(sub__V15); permitUnusedInt(sub__V15_count);
      /* sub__V15 = &#3 */
      NamedPropertyLink namedP__V16 = LINK_NamedPropertyLink(sink__V1->context, NAMED_PROPERTIES(term__V2));
      VariablePropertyLink varP__V17 = LINK_VariablePropertyLink(sink__V1->context, VARIABLE_PROPERTIES(term__V2));
      UNLINK(sink__V1->context, term__V2);
      ADD_PROPERTIES(sink__V1, LINK_NamedPropertyLink(sink__V1->context, namedP__V16), LINK_VariablePropertyLink(sink__V1->context, varP__V17));
      { START(sink__V1, _M_S_Data_s2);
        COPY(sink__V1, sub__V12);COPY(sink__V1, sub__V13);COPY(sink__V1, sub__V14);COPY(sink__V1, sub__V15);END(sink__V1, _M_S_Data_s2); }
      UNLINK_NamedPropertyLink(sink__V1->context, namedP__V16); UNLINK_VariablePropertyLink(sink__V1->context, varP__V17);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION ComputeSorts$1. */
int conBindOffs_M_ComputeSorts_s1[] = {0 , 0 , 0};
char *nameFun_M_ComputeSorts_s1(Term term) { return  "ComputeSorts$1" ; }
struct _ConstructionDescriptor descriptor_M_ComputeSorts_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_ComputeSorts_s1), conBindOffs_M_ComputeSorts_s1, &nameFun_M_ComputeSorts_s1, &step_M_ComputeSorts_s1};

int step_M_ComputeSorts_s1(Sink sink__V18, Term term__V19)
{
  int term__V19_count = LINK_COUNT(term__V19); permitUnusedInt(term__V19_count);
  do {
    /* Contraction rule SORTS-Crsx. */
    ASSERT(sink__V18->context, !strcmp(SYMBOL(term__V19),  "ComputeSorts$1" ));
    Term sub__V20 = LINK(sink__V18->context, SUB(term__V19, 0)); int sub__V20_count = term__V19_count*LINK_COUNT(sub__V20); permitUnusedInt(sub__V20_count);
    UNLINK_SUB(sink__V18->context, term__V19,  0); NORMALIZE(sink__V18->context, sub__V20); SUB(term__V19,  0) = LINK(sink__V18->context, sub__V20);
    /* sub__V20 = &#11 */
    Term sub__V21 = LINK(sink__V18->context, SUB(term__V19, 1)); int sub__V21_count = term__V19_count*LINK_COUNT(sub__V21); permitUnusedInt(sub__V21_count);
    /* sub__V21 = &#12 */
    NamedPropertyLink namedP__V22 = LINK_NamedPropertyLink(sink__V18->context, NAMED_PROPERTIES(term__V19));
    VariablePropertyLink varP__V23 = LINK_VariablePropertyLink(sink__V18->context, VARIABLE_PROPERTIES(term__V19));
    UNLINK(sink__V18->context, term__V19);
    { START(sink__V18, _M__sTextCons);
      { START(sink__V18, _M__sTextChars);
        LITERAL(sink__V18,  "/* C SORT DESCRIPTORS FOR CRSX " ); END(sink__V18, _M__sTextChars); }
      { START(sink__V18, _M__sTextCons);
        { START(sink__V18, _M__sTextEmbed);
          { START(sink__V18, _M_AsText);
            { START(sink__V18, _M_TOKEN);
              COPY(sink__V18, LINK(sink__V18->context, sub__V20));END(sink__V18, _M_TOKEN); }
            END(sink__V18, _M_AsText); }
          END(sink__V18, _M__sTextEmbed); }
        { START(sink__V18, _M__sTextCons);
          { START(sink__V18, _M__sTextChars);
            LITERAL(sink__V18,  ". */" ); END(sink__V18, _M__sTextChars); }
          { START(sink__V18, _M__sTextCons);
            { START(sink__V18, _M__sTextBreak);
              LITERAL(sink__V18,  "\n" ); END(sink__V18, _M__sTextBreak); }
            { START(sink__V18, _M__sTextCons);
              { START(sink__V18, _M__sTextEmbed);
                { START(sink__V18, _M_AsText);
                  { START(sink__V18, _M_DelayMapText_s1);
                    {char* str__V24;{ Term term__V25;
                        { char *value__V26 = getenv( "HEADERS" );
                          if (value__V26) term__V25 = makeStringLiteral(sink__V18->context, value__V26);
                          else {term__V25 = makeStringLiteral(sink__V18->context,  "" );
                            }
                        }
                        str__V24 = SYMBOL(term__V25); UNLINK(sink__V18->context, term__V25); }
                      
                      char* regex__V27;
                      regex__V27 =  ";" ; SEND_SPLIT(str__V24, regex__V27, sink__V18);
                    }
                    { Variable x__V28 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V18->context,"x__V28");
                      Variable x__V29 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V18->context,"x__V29");
                      Variable binds__V30[2] = {x__V28,x__V29}; BINDS(sink__V18, 2, binds__V30);
                      { START(sink__V18, _M__sTextCons);
                        { START(sink__V18, _M__sTextChars);
                          LITERAL(sink__V18,  "#include \"" ); END(sink__V18, _M__sTextChars); }
                        { START(sink__V18, _M__sTextCons);
                          { START(sink__V18, _M__sTextEmbed);
                            { START(sink__V18, _M_AsText);
                              { START(sink__V18, _M_DTOKEN);
                                USE(sink__V18, x__V28); USE(sink__V18, x__V29); END(sink__V18, _M_DTOKEN); }
                              END(sink__V18, _M_AsText); }
                            END(sink__V18, _M__sTextEmbed); }
                          { START(sink__V18, _M__sTextCons);
                            { START(sink__V18, _M__sTextChars);
                              LITERAL(sink__V18,  "\"" ); END(sink__V18, _M__sTextChars); }
                            { START(sink__V18, _M__sTextCons);
                              { START(sink__V18, _M__sTextBreak);
                                LITERAL(sink__V18,  "\n" ); END(sink__V18, _M__sTextBreak); }
                              { START(sink__V18, _M__sTextNil);
                                END(sink__V18, _M__sTextNil); }
                              END(sink__V18, _M__sTextCons); }
                            END(sink__V18, _M__sTextCons); }
                          END(sink__V18, _M__sTextCons); }
                        END(sink__V18, _M__sTextCons); }
                       }
                    END(sink__V18, _M_DelayMapText_s1); }
                  END(sink__V18, _M_AsText); }
                END(sink__V18, _M__sTextEmbed); }
              { START(sink__V18, _M__sTextCons);
                { START(sink__V18, _M__sTextBreak);
                  LITERAL(sink__V18,  "\n" ); END(sink__V18, _M__sTextBreak); }
                { START(sink__V18, _M__sTextCons);
                  { START(sink__V18, _M__sTextChars);
                    LITERAL(sink__V18,  "#ifdef __cplusplus" ); END(sink__V18, _M__sTextChars); }
                  { START(sink__V18, _M__sTextCons);
                    { START(sink__V18, _M__sTextBreak);
                      LITERAL(sink__V18,  "\n" ); END(sink__V18, _M__sTextBreak); }
                    { START(sink__V18, _M__sTextCons);
                      { START(sink__V18, _M__sTextChars);
                        LITERAL(sink__V18,  "extern \"C\" {" ); END(sink__V18, _M__sTextChars); }
                      { START(sink__V18, _M__sTextCons);
                        { START(sink__V18, _M__sTextBreak);
                          LITERAL(sink__V18,  "\n" ); END(sink__V18, _M__sTextBreak); }
                        { START(sink__V18, _M__sTextCons);
                          { START(sink__V18, _M__sTextChars);
                            LITERAL(sink__V18,  "#endif" ); END(sink__V18, _M__sTextChars); }
                          { START(sink__V18, _M__sTextCons);
                            { START(sink__V18, _M__sTextBreak);
                              LITERAL(sink__V18,  "\n" ); END(sink__V18, _M__sTextBreak); }
                            { START(sink__V18, _M__sTextCons);
                              { START(sink__V18, _M__sTextEmbed);
                                { START(sink__V18, _M_AsText);
                                  { START(sink__V18, _M_MapText_s1);
                                    COPY(sink__V18, sub__V21);{ Variable x__V31 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V18->context,"x__V31");
                                      Variable binds__V32[1] = {x__V31}; BINDS(sink__V18, 1, binds__V32);
                                      { START(sink__V18, _M_S_Declaration);
                                        USE(sink__V18, x__V31); END(sink__V18, _M_S_Declaration); }
                                       }
                                    END(sink__V18, _M_MapText_s1); }
                                  END(sink__V18, _M_AsText); }
                                END(sink__V18, _M__sTextEmbed); }
                              { START(sink__V18, _M__sTextCons);
                                { START(sink__V18, _M__sTextBreak);
                                  LITERAL(sink__V18,  "\n" ); END(sink__V18, _M__sTextBreak); }
                                { START(sink__V18, _M__sTextCons);
                                  { START(sink__V18, _M__sTextChars);
                                    LITERAL(sink__V18,  "#ifdef __cplusplus" );
                                    END(sink__V18, _M__sTextChars); }
                                  { START(sink__V18, _M__sTextCons);
                                    { START(sink__V18, _M__sTextBreak);
                                      LITERAL(sink__V18,  "\n" ); END(sink__V18, _M__sTextBreak); }
                                    { START(sink__V18, _M__sTextCons);
                                      { START(sink__V18, _M__sTextChars);
                                        LITERAL(sink__V18,  "}" ); END(sink__V18, _M__sTextChars); }
                                      { START(sink__V18, _M__sTextCons);
                                        { START(sink__V18, _M__sTextBreak);
                                          LITERAL(sink__V18,  "\n" ); END(sink__V18, _M__sTextBreak); }
                                        { START(sink__V18, _M__sTextCons);
                                          { START(sink__V18, _M__sTextChars);
                                            LITERAL(sink__V18,  "#endif" );
                                            END(sink__V18, _M__sTextChars); }
                                          { START(sink__V18, _M__sTextCons);
                                            { START(sink__V18, _M__sTextBreak);
                                              LITERAL(sink__V18,  "\n" );
                                              END(sink__V18, _M__sTextBreak); }
                                            { START(sink__V18, _M__sTextCons);
                                              { START(sink__V18, _M__sTextChars);
                                                LITERAL(sink__V18,  "/* END OF C SORT DESCRIPTORS FOR CRSX " );
                                                END(sink__V18, _M__sTextChars); }
                                              { START(sink__V18, _M__sTextCons);
                                                { START(sink__V18, _M__sTextEmbed);
                                                  { START(sink__V18, _M_AsText);
                                                    { START(sink__V18, _M_TOKEN);
                                                      COPY(sink__V18, sub__V20);END(sink__V18, _M_TOKEN); }
                                                    END(sink__V18, _M_AsText); }
                                                  END(sink__V18, _M__sTextEmbed); }
                                                { START(sink__V18, _M__sTextCons);
                                                  { START(sink__V18, _M__sTextChars);
                                                    LITERAL(sink__V18,  ". */" );
                                                    END(sink__V18, _M__sTextChars); }
                                                  { START(sink__V18, _M__sTextCons);
                                                    { START(sink__V18, _M__sTextBreak);
                                                      LITERAL(sink__V18,  "\n" );
                                                      END(sink__V18, _M__sTextBreak); }
                                                    { START(sink__V18, _M__sTextNil);
                                                      END(sink__V18, _M__sTextNil); }
                                                    END(sink__V18, _M__sTextCons); }
                                                  END(sink__V18, _M__sTextCons); }
                                                END(sink__V18, _M__sTextCons); }
                                              END(sink__V18, _M__sTextCons); }
                                            END(sink__V18, _M__sTextCons); }
                                          END(sink__V18, _M__sTextCons); }
                                        END(sink__V18, _M__sTextCons); }
                                      END(sink__V18, _M__sTextCons); }
                                    END(sink__V18, _M__sTextCons); }
                                  END(sink__V18, _M__sTextCons); }
                                END(sink__V18, _M__sTextCons); }
                              END(sink__V18, _M__sTextCons); }
                            END(sink__V18, _M__sTextCons); }
                          END(sink__V18, _M__sTextCons); }
                        END(sink__V18, _M__sTextCons); }
                      END(sink__V18, _M__sTextCons); }
                    END(sink__V18, _M__sTextCons); }
                  END(sink__V18, _M__sTextCons); }
                END(sink__V18, _M__sTextCons); }
              END(sink__V18, _M__sTextCons); }
            END(sink__V18, _M__sTextCons); }
          END(sink__V18, _M__sTextCons); }
        END(sink__V18, _M__sTextCons); }
      END(sink__V18, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V18->context, namedP__V22); UNLINK_VariablePropertyLink(sink__V18->context, varP__V23);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION S-Data$1. */
int conBindOffs_M_S_Data_s1[] = {0 , 0 , 0 , 0};
char *nameFun_M_S_Data_s1(Term term) { return  "S-Data$1" ; }
struct _ConstructionDescriptor descriptor_M_S_Data_s1 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_S_Data_s1), conBindOffs_M_S_Data_s1, &nameFun_M_S_Data_s1, &step_M_S_Data_s1};

int step_M_S_Data_s1(Sink sink__V33, Term term__V34)
{
  int term__V34_count = LINK_COUNT(term__V34); permitUnusedInt(term__V34_count);
  do {
    /* Contraction rule SORTS-S-Data-1. */
    ASSERT(sink__V33->context, !strcmp(SYMBOL(term__V34),  "S-Data$1" ));
    Term sub__V35 = LINK(sink__V33->context, SUB(term__V34, 0)); int sub__V35_count = term__V34_count*LINK_COUNT(sub__V35); permitUnusedInt(sub__V35_count);
    UNLINK_SUB(sink__V33->context, term__V34,  0); NORMALIZE(sink__V33->context, sub__V35); SUB(term__V34,  0) = LINK(sink__V33->context, sub__V35);
    /* sub__V35 = &#11 */
    Term sub__V36 = SUB(term__V34, 1); permitUnusedTerm(sub__V36); int sub__V36_count = term__V34_count*LINK_COUNT(sub__V36); permitUnusedInt(sub__V36_count);
    /* sub__V36 = &#12 */
    Term sub__V37 = LINK(sink__V33->context, SUB(term__V34, 2)); int sub__V37_count = term__V34_count*LINK_COUNT(sub__V37); permitUnusedInt(sub__V37_count);
    UNLINK_SUB(sink__V33->context, term__V34,  2); NORMALIZE(sink__V33->context, sub__V37); SUB(term__V34,  2) = LINK(sink__V33->context, sub__V37);
    /* sub__V37 = &#2 */
    NamedPropertyLink namedP__V38 = LINK_NamedPropertyLink(sink__V33->context, NAMED_PROPERTIES(term__V34));
    VariablePropertyLink varP__V39 = LINK_VariablePropertyLink(sink__V33->context, VARIABLE_PROPERTIES(term__V34));
    UNLINK(sink__V33->context, term__V34);
    { START(sink__V33, _M__sTextCons);
      { START(sink__V33, _M__sTextBreak);
        LITERAL(sink__V33,  "\n" ); END(sink__V33, _M__sTextBreak); }
      { START(sink__V33, _M__sTextCons);
        { START(sink__V33, _M__sTextChars);
          LITERAL(sink__V33,  "/* SORT " ); END(sink__V33, _M__sTextChars); }
        { START(sink__V33, _M__sTextCons);
          { START(sink__V33, _M__sTextEmbed);
            { START(sink__V33, _M_AsText);
              { START(sink__V33, _M_TOKEN);
                COPY(sink__V33, LINK(sink__V33->context, sub__V35));END(sink__V33, _M_TOKEN); }
              END(sink__V33, _M_AsText); }
            END(sink__V33, _M__sTextEmbed); }
          { START(sink__V33, _M__sTextCons);
            { START(sink__V33, _M__sTextChars);
              LITERAL(sink__V33,  " CONSTANTS. */" ); END(sink__V33, _M__sTextChars); }
            { START(sink__V33, _M__sTextCons);
              { START(sink__V33, _M__sTextBreak);
                LITERAL(sink__V33,  "\n" ); END(sink__V33, _M__sTextBreak); }
              { START(sink__V33, _M__sTextCons);
                { START(sink__V33, _M__sTextEmbed);
                  { START(sink__V33, _M_AsText);
                    { START(sink__V33, _M_MapText_s1);
                      COPY(sink__V33, LINK(sink__V33->context, sub__V37));{ Variable x__V40 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V33->context,"x__V40");
                        Variable binds__V41[1] = {x__V40}; BINDS(sink__V33, 1, binds__V41);
                        { START(sink__V33, _M_S_Data_Form_s1);
                          USE(sink__V33, x__V40); WEAKEN(sink__V33, x__V40);
                          COPY(sink__V33, LINK(sink__V33->context, sub__V35));END(sink__V33, _M_S_Data_Form_s1); }
                         }
                      END(sink__V33, _M_MapText_s1); }
                    END(sink__V33, _M_AsText); }
                  END(sink__V33, _M__sTextEmbed); }
                { START(sink__V33, _M__sTextCons);
                  { START(sink__V33, _M__sTextChars);
                    LITERAL(sink__V33,  "ConstructionDescriptor " ); END(sink__V33, _M__sTextChars); }
                  { START(sink__V33, _M__sTextCons);
                    { START(sink__V33, _M__sTextEmbed);
                      { START(sink__V33, _M_AsText);
                        { START(sink__V33, _M_SortCons);
                          COPY(sink__V33, LINK(sink__V33->context, sub__V35));END(sink__V33, _M_SortCons); }
                        END(sink__V33, _M_AsText); }
                      END(sink__V33, _M__sTextEmbed); }
                    { START(sink__V33, _M__sTextCons);
                      { START(sink__V33, _M__sTextChars);
                        LITERAL(sink__V33,  "[] = {NULL, NULL, " ); END(sink__V33, _M__sTextChars); }
                      { START(sink__V33, _M__sTextCons);
                        { START(sink__V33, _M__sTextEmbed);
                          { START(sink__V33, _M_AsText);
                            { START(sink__V33, _M_DelayMapText_s1);
                              { START(sink__V33, _M_Forms_Constructors);
                                COPY(sink__V33, LINK(sink__V33->context, sub__V37));END(sink__V33, _M_Forms_Constructors); }
                              { Variable x__V42 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V33->context,"x__V42");
                                Variable x__V43 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V33->context,"x__V43");
                                Variable binds__V44[2] = {x__V42,x__V43}; BINDS(sink__V33, 2, binds__V44);
                                { START(sink__V33, _M__sTextCons);
                                  { START(sink__V33, _M__sTextChars);
                                    LITERAL(sink__V33,  "&" ); END(sink__V33, _M__sTextChars); }
                                  { START(sink__V33, _M__sTextCons);
                                    { START(sink__V33, _M__sTextEmbed);
                                      { START(sink__V33, _M_AsText);
                                        { START(sink__V33, _M_DDescriptor);
                                          USE(sink__V33, x__V42); USE(sink__V33, x__V43); END(sink__V33, _M_DDescriptor); }
                                        END(sink__V33, _M_AsText); }
                                      END(sink__V33, _M__sTextEmbed); }
                                    { START(sink__V33, _M__sTextCons);
                                      { START(sink__V33, _M__sTextChars);
                                        LITERAL(sink__V33,  ", " ); END(sink__V33, _M__sTextChars); }
                                      { START(sink__V33, _M__sTextNil);
                                        END(sink__V33, _M__sTextNil); }
                                      END(sink__V33, _M__sTextCons); }
                                    END(sink__V33, _M__sTextCons); }
                                  END(sink__V33, _M__sTextCons); }
                                 }
                              END(sink__V33, _M_DelayMapText_s1); }
                            END(sink__V33, _M_AsText); }
                          END(sink__V33, _M__sTextEmbed); }
                        { START(sink__V33, _M__sTextCons);
                          { START(sink__V33, _M__sTextChars);
                            LITERAL(sink__V33,  " NULL};" ); END(sink__V33, _M__sTextChars); }
                          { START(sink__V33, _M__sTextCons);
                            { START(sink__V33, _M__sTextBreak);
                              LITERAL(sink__V33,  "\n" ); END(sink__V33, _M__sTextBreak); }
                            { START(sink__V33, _M__sTextCons);
                              { START(sink__V33, _M__sTextChars);
                                LITERAL(sink__V33,  "char *" ); END(sink__V33, _M__sTextChars); }
                              { START(sink__V33, _M__sTextCons);
                                { START(sink__V33, _M__sTextEmbed);
                                  { START(sink__V33, _M_AsText);
                                    { START(sink__V33, _M_SortNames);
                                      COPY(sink__V33, LINK(sink__V33->context, sub__V35));END(sink__V33, _M_SortNames); }
                                    END(sink__V33, _M_AsText); }
                                  END(sink__V33, _M__sTextEmbed); }
                                { START(sink__V33, _M__sTextCons);
                                  { START(sink__V33, _M__sTextChars);
                                    LITERAL(sink__V33,  "[] = {NULL, NULL, " );
                                    END(sink__V33, _M__sTextChars); }
                                  { START(sink__V33, _M__sTextCons);
                                    { START(sink__V33, _M__sTextEmbed);
                                      { START(sink__V33, _M_AsText);
                                        { START(sink__V33, _M_DelayMapText_s1);
                                          { START(sink__V33, _M_Forms_Constructors);
                                            COPY(sink__V33, LINK(sink__V33->context, sub__V37));END(sink__V33, _M_Forms_Constructors); }
                                          { Variable x__V45 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V33->context,"x__V45");
                                            Variable x__V46 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V33->context,"x__V46");
                                            Variable binds__V47[2] = {x__V45,x__V46}; BINDS(sink__V33, 2, binds__V47);
                                            { START(sink__V33, _M__sTextCons);
                                              { START(sink__V33, _M__sTextEmbed);
                                                { START(sink__V33, _M_AsText);
                                                  { START(sink__V33, _M_DSTRING);
                                                    USE(sink__V33, x__V45);
                                                    USE(sink__V33, x__V46);
                                                    END(sink__V33, _M_DSTRING); }
                                                  END(sink__V33, _M_AsText); }
                                                END(sink__V33, _M__sTextEmbed); }
                                              { START(sink__V33, _M__sTextCons);
                                                { START(sink__V33, _M__sTextChars);
                                                  LITERAL(sink__V33,  ", " );
                                                  END(sink__V33, _M__sTextChars); }
                                                { START(sink__V33, _M__sTextNil);
                                                  END(sink__V33, _M__sTextNil); }
                                                END(sink__V33, _M__sTextCons); }
                                              END(sink__V33, _M__sTextCons); }
                                             }
                                          END(sink__V33, _M_DelayMapText_s1); }
                                        END(sink__V33, _M_AsText); }
                                      END(sink__V33, _M__sTextEmbed); }
                                    { START(sink__V33, _M__sTextCons);
                                      { START(sink__V33, _M__sTextChars);
                                        LITERAL(sink__V33,  " NULL};" );
                                        END(sink__V33, _M__sTextChars); }
                                      { START(sink__V33, _M__sTextCons);
                                        { START(sink__V33, _M__sTextBreak);
                                          LITERAL(sink__V33,  "\n" ); END(sink__V33, _M__sTextBreak); }
                                        { START(sink__V33, _M__sTextCons);
                                          { START(sink__V33, _M__sTextChars);
                                            LITERAL(sink__V33,  "char *" );
                                            END(sink__V33, _M__sTextChars); }
                                          { START(sink__V33, _M__sTextCons);
                                            { START(sink__V33, _M__sTextEmbed);
                                              { START(sink__V33, _M_AsText);
                                                { START(sink__V33, _M_SortInternals);
                                                  COPY(sink__V33, LINK(sink__V33->context, sub__V35));END(sink__V33, _M_SortInternals); }
                                                END(sink__V33, _M_AsText); }
                                              END(sink__V33, _M__sTextEmbed); }
                                            { START(sink__V33, _M__sTextCons);
                                              { START(sink__V33, _M__sTextChars);
                                                LITERAL(sink__V33,  "[] = {NULL, NULL, " );
                                                END(sink__V33, _M__sTextChars); }
                                              { START(sink__V33, _M__sTextCons);
                                                { START(sink__V33, _M__sTextEmbed);
                                                  { START(sink__V33, _M_AsText);
                                                    { START(sink__V33, _M_DelayMapText_s1);
                                                      { START(sink__V33, _M_Forms_Constructors);
                                                        COPY(sink__V33, sub__V37);END(sink__V33, _M_Forms_Constructors); }
                                                      { Variable x__V48 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V33->context,"x__V48");
                                                        Variable x__V49 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V33->context,"x__V49");
                                                        Variable binds__V50[2] = {x__V48,x__V49}; BINDS(sink__V33, 2, binds__V50);
                                                        { START(sink__V33, _M__sTextCons);
                                                          { START(sink__V33, _M__sTextChars);
                                                            LITERAL(sink__V33,  "\"" );
                                                            END(sink__V33, _M__sTextChars); }
                                                          { START(sink__V33, _M__sTextCons);
                                                            { START(sink__V33, _M__sTextEmbed);
                                                              { START(sink__V33, _M_AsText);
                                                                { START(sink__V33, _M_DMANGLE);
                                                                  USE(sink__V33, x__V48);
                                                                  USE(sink__V33, x__V49);
                                                                  END(sink__V33, _M_DMANGLE); }
                                                                END(sink__V33, _M_AsText); }
                                                              END(sink__V33, _M__sTextEmbed); }
                                                            { START(sink__V33, _M__sTextCons);
                                                              { START(sink__V33, _M__sTextChars);
                                                                LITERAL(sink__V33,  "\", " );
                                                                END(sink__V33, _M__sTextChars); }
                                                              { START(sink__V33, _M__sTextNil);
                                                                END(sink__V33, _M__sTextNil); }
                                                              END(sink__V33, _M__sTextCons); }
                                                            END(sink__V33, _M__sTextCons); }
                                                          END(sink__V33, _M__sTextCons); }
                                                         }
                                                      END(sink__V33, _M_DelayMapText_s1); }
                                                    END(sink__V33, _M_AsText); }
                                                  END(sink__V33, _M__sTextEmbed); }
                                                { START(sink__V33, _M__sTextCons);
                                                  { START(sink__V33, _M__sTextChars);
                                                    LITERAL(sink__V33,  " NULL};" );
                                                    END(sink__V33, _M__sTextChars); }
                                                  { START(sink__V33, _M__sTextCons);
                                                    { START(sink__V33, _M__sTextBreak);
                                                      LITERAL(sink__V33,  "\n" );
                                                      END(sink__V33, _M__sTextBreak); }
                                                    { START(sink__V33, _M__sTextCons);
                                                      { START(sink__V33, _M__sTextChars);
                                                        LITERAL(sink__V33,  "struct _SortDescriptor " );
                                                        END(sink__V33, _M__sTextChars); }
                                                      { START(sink__V33, _M__sTextCons);
                                                        { START(sink__V33, _M__sTextEmbed);
                                                          { START(sink__V33, _M_AsText);
                                                            { START(sink__V33, _M_Sort);
                                                              COPY(sink__V33, LINK(sink__V33->context, sub__V35));END(sink__V33, _M_Sort); }
                                                            END(sink__V33, _M_AsText); }
                                                          END(sink__V33, _M__sTextEmbed); }
                                                        { START(sink__V33, _M__sTextCons);
                                                          { START(sink__V33, _M__sTextChars);
                                                            LITERAL(sink__V33,  " = {" );
                                                            END(sink__V33, _M__sTextChars); }
                                                          { START(sink__V33, _M__sTextCons);
                                                            { START(sink__V33, _M__sTextEmbed);
                                                              { START(sink__V33, _M_AsText);
                                                                { START(sink__V33, _M_STRING);
                                                                  COPY(sink__V33, LINK(sink__V33->context, sub__V35));END(sink__V33, _M_STRING); }
                                                                END(sink__V33, _M_AsText); }
                                                              END(sink__V33, _M__sTextEmbed); }
                                                            { START(sink__V33, _M__sTextCons);
                                                              { START(sink__V33, _M__sTextChars);
                                                                LITERAL(sink__V33,  ", " );
                                                                END(sink__V33, _M__sTextChars); }
                                                              { START(sink__V33, _M__sTextCons);
                                                                { START(sink__V33, _M__sTextEmbed);
                                                                  { START(sink__V33, _M_AsText);
                                                                    { START(sink__V33, _M_SortCons);
                                                                      COPY(sink__V33, LINK(sink__V33->context, sub__V35));END(sink__V33, _M_SortCons); }
                                                                    END(sink__V33, _M_AsText); }
                                                                  END(sink__V33, _M__sTextEmbed); }
                                                                { START(sink__V33, _M__sTextCons);
                                                                  { START(sink__V33, _M__sTextChars);
                                                                    LITERAL(sink__V33,  ", " );
                                                                    END(sink__V33, _M__sTextChars); }
                                                                  { START(sink__V33, _M__sTextCons);
                                                                    { START(sink__V33, _M__sTextEmbed);
                                                                      { START(sink__V33, _M_AsText);
                                                                        { START(sink__V33, _M_SortNames);
                                                                          COPY(sink__V33, LINK(sink__V33->context, sub__V35));END(sink__V33, _M_SortNames); }
                                                                        END(sink__V33, _M_AsText); }
                                                                      END(sink__V33, _M__sTextEmbed); }
                                                                    { START(sink__V33, _M__sTextCons);
                                                                      { START(sink__V33, _M__sTextChars);
                                                                        LITERAL(sink__V33,  ", " );
                                                                        END(sink__V33, _M__sTextChars); }
                                                                      { START(sink__V33, _M__sTextCons);
                                                                        { START(sink__V33, _M__sTextEmbed);
                                                                          { START(sink__V33, _M_AsText);
                                                                            { START(sink__V33, _M_SortInternals);
                                                                              COPY(sink__V33, sub__V35);END(sink__V33, _M_SortInternals); }
                                                                            END(sink__V33, _M_AsText); }
                                                                          END(sink__V33, _M__sTextEmbed); }
                                                                        { START(sink__V33, _M__sTextCons);
                                                                          { START(sink__V33, _M__sTextChars);
                                                                            LITERAL(sink__V33,  ", NULL};" );
                                                                            END(sink__V33, _M__sTextChars); }
                                                                          { START(sink__V33, _M__sTextCons);
                                                                            { START(sink__V33, _M__sTextBreak);
                                                                              LITERAL(sink__V33,  "\n" );
                                                                              END(sink__V33, _M__sTextBreak); }
                                                                            { START(sink__V33, _M__sTextNil);
                                                                              END(sink__V33, _M__sTextNil); }
                                                                            END(sink__V33, _M__sTextCons); }
                                                                          END(sink__V33, _M__sTextCons); }
                                                                        END(sink__V33, _M__sTextCons); }
                                                                      END(sink__V33, _M__sTextCons); }
                                                                    END(sink__V33, _M__sTextCons); }
                                                                  END(sink__V33, _M__sTextCons); }
                                                                END(sink__V33, _M__sTextCons); }
                                                              END(sink__V33, _M__sTextCons); }
                                                            END(sink__V33, _M__sTextCons); }
                                                          END(sink__V33, _M__sTextCons); }
                                                        END(sink__V33, _M__sTextCons); }
                                                      END(sink__V33, _M__sTextCons); }
                                                    END(sink__V33, _M__sTextCons); }
                                                  END(sink__V33, _M__sTextCons); }
                                                END(sink__V33, _M__sTextCons); }
                                              END(sink__V33, _M__sTextCons); }
                                            END(sink__V33, _M__sTextCons); }
                                          END(sink__V33, _M__sTextCons); }
                                        END(sink__V33, _M__sTextCons); }
                                      END(sink__V33, _M__sTextCons); }
                                    END(sink__V33, _M__sTextCons); }
                                  END(sink__V33, _M__sTextCons); }
                                END(sink__V33, _M__sTextCons); }
                              END(sink__V33, _M__sTextCons); }
                            END(sink__V33, _M__sTextCons); }
                          END(sink__V33, _M__sTextCons); }
                        END(sink__V33, _M__sTextCons); }
                      END(sink__V33, _M__sTextCons); }
                    END(sink__V33, _M__sTextCons); }
                  END(sink__V33, _M__sTextCons); }
                END(sink__V33, _M__sTextCons); }
              END(sink__V33, _M__sTextCons); }
            END(sink__V33, _M__sTextCons); }
          END(sink__V33, _M__sTextCons); }
        END(sink__V33, _M__sTextCons); }
      END(sink__V33, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V33->context, namedP__V38); UNLINK_VariablePropertyLink(sink__V33->context, varP__V39);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION S-Data$2. */
int conBindOffs_M_S_Data_s2[] = {0 , 0 , 0 , 0 , 0};
char *nameFun_M_S_Data_s2(Term term) { return  "S-Data$2" ; }
struct _ConstructionDescriptor descriptor_M_S_Data_s2 = {&sort_M_Reified_xVariable, 0, 4, sizeof(STRUCT_Con_M_S_Data_s2), conBindOffs_M_S_Data_s2, &nameFun_M_S_Data_s2, &step_M_S_Data_s2};

int step_M_S_Data_s2(Sink sink__V51, Term term__V52)
{
  int term__V52_count = LINK_COUNT(term__V52); permitUnusedInt(term__V52_count);
  do {
    /* Contraction rule SORTS-S-Data-2. */
    ASSERT(sink__V51->context, !strcmp(SYMBOL(term__V52),  "S-Data$2" ));
    Term sub__V53 = SUB(term__V52, 0); permitUnusedTerm(sub__V53); int sub__V53_count = term__V52_count*LINK_COUNT(sub__V53); permitUnusedInt(sub__V53_count);
    CRSX_CHECK_SORT(sink__V51->context, sub__V53, &sort_M_Reified_xSort); /* sub__V53 = &#11 */
    Term sub__V54 = SUB(term__V52, 1); permitUnusedTerm(sub__V54); int sub__V54_count = term__V52_count*LINK_COUNT(sub__V54); permitUnusedInt(sub__V54_count);
    CRSX_CHECK_SORT(sink__V51->context, sub__V54, &sort_M_Reified_xSort); /* sub__V54 = &#12 */
    Term sub__V55 = LINK(sink__V51->context, SUB(term__V52, 2)); int sub__V55_count = term__V52_count*LINK_COUNT(sub__V55); permitUnusedInt(sub__V55_count);
    CRSX_CHECK_SORT(sink__V51->context, sub__V55, &sort_M_Reified_xSort); /* sub__V55 = &#13 */
    Term sub__V56 = LINK(sink__V51->context, SUB(term__V52, 3)); int sub__V56_count = term__V52_count*LINK_COUNT(sub__V56); permitUnusedInt(sub__V56_count);
    /* sub__V56 = &#2 */
    NamedPropertyLink namedP__V57 = LINK_NamedPropertyLink(sink__V51->context, NAMED_PROPERTIES(term__V52));
    VariablePropertyLink varP__V58 = LINK_VariablePropertyLink(sink__V51->context, VARIABLE_PROPERTIES(term__V52));
    UNLINK(sink__V51->context, term__V52);
    { START(sink__V51, _M_S_Data);
      COPY(sink__V51, sub__V55);COPY(sink__V51, sub__V56);END(sink__V51, _M_S_Data); }
    UNLINK_NamedPropertyLink(sink__V51->context, namedP__V57); UNLINK_VariablePropertyLink(sink__V51->context, varP__V58);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION ComputeSorts. */
int conBindOffs_M_ComputeSorts[] = {0 , 0};
char *nameFun_M_ComputeSorts(Term term) { return  "ComputeSorts" ; }
struct _ConstructionDescriptor descriptor_M_ComputeSorts = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_ComputeSorts), conBindOffs_M_ComputeSorts, &nameFun_M_ComputeSorts, &step_M_ComputeSorts};

int step_M_ComputeSorts(Sink sink__V59, Term term__V60)
{
  int term__V60_count = LINK_COUNT(term__V60); permitUnusedInt(term__V60_count);
  Term sub__V61 = FORCE(sink__V59->context, SUB(term__V60, 0));
  EnumOf_M_Reify_xCRSX choice__V62 = (IS_VARIABLE_USE(sub__V61) ? VarOf_M_Reify_xCRSX : (EnumOf_M_Reify_xCRSX) TAG(sub__V61));
  switch (choice__V62)
  {
    case Data_M_CRSX: { /* Function SORTS-Crsx$ComputeSorts$CRSX case CRSX */
      ASSERT(sink__V59->context, !strcmp(SYMBOL(term__V60),  "ComputeSorts" ));
      Term sub__V63 = SUB(term__V60, 0); permitUnusedTerm(sub__V63); int sub__V63_count = term__V60_count*LINK_COUNT(sub__V63); permitUnusedInt(sub__V63_count);
      CRSX_CHECK_SORT(sink__V59->context, sub__V63, &sort_M_Reify_xCRSX); ASSERT(sink__V59->context, !strcmp(SYMBOL(sub__V63),  "CRSX" ));
      Term sub__V64 = LINK(sink__V59->context, SUB(sub__V63, 0)); int sub__V64_count = sub__V63_count*LINK_COUNT(sub__V64); permitUnusedInt(sub__V64_count);
      /* sub__V64 = &#0-0 */
      Term sub__V65 = LINK(sink__V59->context, SUB(sub__V63, 1)); int sub__V65_count = sub__V63_count*LINK_COUNT(sub__V65); permitUnusedInt(sub__V65_count);
      /* sub__V65 = &#0-1 */
      NamedPropertyLink namedP__V66 = LINK_NamedPropertyLink(sink__V59->context, NAMED_PROPERTIES(term__V60));
      VariablePropertyLink varP__V67 = LINK_VariablePropertyLink(sink__V59->context, VARIABLE_PROPERTIES(term__V60));
      UNLINK(sink__V59->context, term__V60);
      ADD_PROPERTIES(sink__V59, LINK_NamedPropertyLink(sink__V59->context, namedP__V66), LINK_VariablePropertyLink(sink__V59->context, varP__V67));
      { START(sink__V59, _M_ComputeSorts_s1);
        COPY(sink__V59, sub__V64);COPY(sink__V59, sub__V65);END(sink__V59, _M_ComputeSorts_s1); }
      UNLINK_NamedPropertyLink(sink__V59->context, namedP__V66); UNLINK_VariablePropertyLink(sink__V59->context, varP__V67);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION S-Declaration$1. */
int conBindOffs_M_S_Declaration_s1[] = {0 , 0 , 0};
char *nameFun_M_S_Declaration_s1(Term term) { return  "S-Declaration$1" ; }
struct _ConstructionDescriptor descriptor_M_S_Declaration_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_S_Declaration_s1), conBindOffs_M_S_Declaration_s1, &nameFun_M_S_Declaration_s1, &step_M_S_Declaration_s1};

int step_M_S_Declaration_s1(Sink sink__V68, Term term__V69)
{
  int term__V69_count = LINK_COUNT(term__V69); permitUnusedInt(term__V69_count);
  do {
    /* Contraction rule SORTS-Data. */
    ASSERT(sink__V68->context, !strcmp(SYMBOL(term__V69),  "S-Declaration$1" ));
    Term sub__V70 = LINK(sink__V68->context, SUB(term__V69, 0)); int sub__V70_count = term__V69_count*LINK_COUNT(sub__V70); permitUnusedInt(sub__V70_count);
    CRSX_CHECK_SORT(sink__V68->context, sub__V70, &sort_M_Reified_xSort); /* sub__V70 = &#11 */
    Term sub__V71 = LINK(sink__V68->context, SUB(term__V69, 1)); int sub__V71_count = term__V69_count*LINK_COUNT(sub__V71); permitUnusedInt(sub__V71_count);
    /* sub__V71 = &#12 */
    NamedPropertyLink namedP__V72 = LINK_NamedPropertyLink(sink__V68->context, NAMED_PROPERTIES(term__V69));
    VariablePropertyLink varP__V73 = LINK_VariablePropertyLink(sink__V68->context, VARIABLE_PROPERTIES(term__V69));
    UNLINK(sink__V68->context, term__V69);
    { START(sink__V68, _M_S_Data);
      COPY(sink__V68, sub__V70);COPY(sink__V68, sub__V71);END(sink__V68, _M_S_Data); }
    UNLINK_NamedPropertyLink(sink__V68->context, namedP__V72); UNLINK_VariablePropertyLink(sink__V68->context, varP__V73);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION S-Declaration$2. */
int conBindOffs_M_S_Declaration_s2[] = {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0};
char *nameFun_M_S_Declaration_s2(Term term) { return  "S-Declaration$2" ; }
struct _ConstructionDescriptor descriptor_M_S_Declaration_s2 = {&sort_M_Reified_xVariable, 0, 7, sizeof(STRUCT_Con_M_S_Declaration_s2), conBindOffs_M_S_Declaration_s2, &nameFun_M_S_Declaration_s2, &step_M_S_Declaration_s2};

int step_M_S_Declaration_s2(Sink sink__V74, Term term__V75)
{
  int term__V75_count = LINK_COUNT(term__V75); permitUnusedInt(term__V75_count);
  do {
    /* Contraction rule SORTS-Function. */
    ASSERT(sink__V74->context, !strcmp(SYMBOL(term__V75),  "S-Declaration$2" ));
    Term sub__V76 = SUB(term__V75, 0); permitUnusedTerm(sub__V76); int sub__V76_count = term__V75_count*LINK_COUNT(sub__V76); permitUnusedInt(sub__V76_count);
    /* sub__V76 = &#11 */
    Term sub__V77 = SUB(term__V75, 1); permitUnusedTerm(sub__V77); int sub__V77_count = term__V75_count*LINK_COUNT(sub__V77); permitUnusedInt(sub__V77_count);
    /* sub__V77 = &#12 */
    Term sub__V78 = SUB(term__V75, 2); permitUnusedTerm(sub__V78); int sub__V78_count = term__V75_count*LINK_COUNT(sub__V78); permitUnusedInt(sub__V78_count);
    /* sub__V78 = &#13 */
    Term sub__V79 = SUB(term__V75, 3); permitUnusedTerm(sub__V79); int sub__V79_count = term__V75_count*LINK_COUNT(sub__V79); permitUnusedInt(sub__V79_count);
    /* sub__V79 = &#14 */
    Term sub__V80 = SUB(term__V75, 4); permitUnusedTerm(sub__V80); int sub__V80_count = term__V75_count*LINK_COUNT(sub__V80); permitUnusedInt(sub__V80_count);
    /* sub__V80 = &#15 */
    Term sub__V81 = SUB(term__V75, 5); permitUnusedTerm(sub__V81); int sub__V81_count = term__V75_count*LINK_COUNT(sub__V81); permitUnusedInt(sub__V81_count);
    CRSX_CHECK_SORT(sink__V74->context, sub__V81, &sort_M_Reified_xSort); /* sub__V81 = &#16 */
    Term sub__V82 = SUB(term__V75, 6); permitUnusedTerm(sub__V82); int sub__V82_count = term__V75_count*LINK_COUNT(sub__V82); permitUnusedInt(sub__V82_count);
    /* sub__V82 = &#17 */
    NamedPropertyLink namedP__V83 = LINK_NamedPropertyLink(sink__V74->context, NAMED_PROPERTIES(term__V75));
    VariablePropertyLink varP__V84 = LINK_VariablePropertyLink(sink__V74->context, VARIABLE_PROPERTIES(term__V75));
    UNLINK(sink__V74->context, term__V75);
    { START(sink__V74, _M__sTextNil); END(sink__V74, _M__sTextNil); } UNLINK_NamedPropertyLink(sink__V74->context, namedP__V83); UNLINK_VariablePropertyLink(sink__V74->context, varP__V84);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION S-Declaration$3. */
int conBindOffs_M_S_Declaration_s3[] = {0 , 1};
char *nameFun_M_S_Declaration_s3(Term term) { return  "S-Declaration$3" ; }
struct _ConstructionDescriptor descriptor_M_S_Declaration_s3 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_S_Declaration_s3), conBindOffs_M_S_Declaration_s3, &nameFun_M_S_Declaration_s3, &step_M_S_Declaration_s3};

int step_M_S_Declaration_s3(Sink sink__V85, Term term__V86)
{
  int term__V86_count = LINK_COUNT(term__V86); permitUnusedInt(term__V86_count);
  do {
    /* Contraction rule SORTS-Polymorphic. */
    ASSERT(sink__V85->context, !strcmp(SYMBOL(term__V86),  "S-Declaration$3" ));
    Variable x__V87 = BINDER(term__V86,0,0); if (term__V86_count <= 1) UNBIND(x__V87);
    Term sub__V88 = LINK(sink__V85->context, SUB(term__V86, 0)); int sub__V88_count = term__V86_count*LINK_COUNT(sub__V88); permitUnusedInt(sub__V88_count);
    CRSX_CHECK_SORT(sink__V85->context, sub__V88, &sort_M_Reified_xDeclaration); /* sub__V88 = &#11 */
    Variable y__V89 = x__V87; permitUnusedVariable(y__V89);
    NamedPropertyLink namedP__V90 = LINK_NamedPropertyLink(sink__V85->context, NAMED_PROPERTIES(term__V86));
    VariablePropertyLink varP__V91 = LINK_VariablePropertyLink(sink__V85->context, VARIABLE_PROPERTIES(term__V86));
    UNLINK(sink__V85->context, term__V86);
    { START(sink__V85, _M_S_Declaration);
      COPY(sink__V85, sub__V88); /* REUSED SUBSTITUTION */ END(sink__V85, _M_S_Declaration); }
    UNLINK_NamedPropertyLink(sink__V85->context, namedP__V90); UNLINK_VariablePropertyLink(sink__V85->context, varP__V91);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION S-Data-Form$1. */
int conBindOffs_M_S_Data_Form_s1[] = {0 , 0 , 0};
char *nameFun_M_S_Data_Form_s1(Term term) { return  "S-Data-Form$1" ; }
struct _ConstructionDescriptor descriptor_M_S_Data_Form_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_S_Data_Form_s1), conBindOffs_M_S_Data_Form_s1, &nameFun_M_S_Data_Form_s1, &step_M_S_Data_Form_s1};

int step_M_S_Data_Form_s1(Sink sink__V92, Term term__V93)
{
  int term__V93_count = LINK_COUNT(term__V93); permitUnusedInt(term__V93_count);
  Term sub__V94 = FORCE(sink__V92->context, SUB(term__V93, 0));
  EnumOf_M_Reified_xForm choice__V95 = (IS_VARIABLE_USE(sub__V94) ? VarOf_M_Reified_xForm : (EnumOf_M_Reified_xForm) TAG(sub__V94));
  switch (choice__V95)
  {
    case Data_M_SORT_SET: { /* Function SORTS-S-Data-Form-1$S-Data-Form$1$SORT-SET case SORT-SET */
      ASSERT(sink__V92->context, !strcmp(SYMBOL(term__V93),  "S-Data-Form$1" ));
      Term sub__V96 = SUB(term__V93, 0); permitUnusedTerm(sub__V96); int sub__V96_count = term__V93_count*LINK_COUNT(sub__V96); permitUnusedInt(sub__V96_count);
      CRSX_CHECK_SORT(sink__V92->context, sub__V96, &sort_M_Reified_xForm); ASSERT(sink__V92->context, !strcmp(SYMBOL(sub__V96),  "SORT-SET" ));
      Term sub__V97 = LINK(sink__V92->context, SUB(sub__V96, 0)); int sub__V97_count = sub__V96_count*LINK_COUNT(sub__V97); permitUnusedInt(sub__V97_count);
      CRSX_CHECK_SORT(sink__V92->context, sub__V97, &sort_M_Reified_xSort); /* sub__V97 = &#0-0 */
      Term sub__V98 = LINK(sink__V92->context, SUB(sub__V96, 1)); int sub__V98_count = sub__V96_count*LINK_COUNT(sub__V98); permitUnusedInt(sub__V98_count);
      CRSX_CHECK_SORT(sink__V92->context, sub__V98, &sort_M_Reified_xSort); /* sub__V98 = &#0-1 */
      Term sub__V99 = LINK(sink__V92->context, SUB(sub__V96, 2)); int sub__V99_count = sub__V96_count*LINK_COUNT(sub__V99); permitUnusedInt(sub__V99_count);
      CRSX_CHECK_SORT(sink__V92->context, sub__V99, &sort_M_Reified_xForm); /* sub__V99 = &#0-2 */
      Term sub__V100 = LINK(sink__V92->context, SUB(term__V93, 1)); int sub__V100_count = term__V93_count*LINK_COUNT(sub__V100); permitUnusedInt(sub__V100_count);
      /* sub__V100 = &#3 */
      NamedPropertyLink namedP__V101 = LINK_NamedPropertyLink(sink__V92->context, NAMED_PROPERTIES(term__V93));
      VariablePropertyLink varP__V102 = LINK_VariablePropertyLink(sink__V92->context, VARIABLE_PROPERTIES(term__V93));
      UNLINK(sink__V92->context, term__V93);
      ADD_PROPERTIES(sink__V92, LINK_NamedPropertyLink(sink__V92->context, namedP__V101), LINK_VariablePropertyLink(sink__V92->context, varP__V102));
      { START(sink__V92, _M_S_Data_Form_s7);
        COPY(sink__V92, sub__V97);COPY(sink__V92, sub__V98);COPY(sink__V92, sub__V99);COPY(sink__V92, sub__V100);END(sink__V92, _M_S_Data_Form_s7); }
      UNLINK_NamedPropertyLink(sink__V92->context, namedP__V101); UNLINK_VariablePropertyLink(sink__V92->context, varP__V102);
      
      return 1;
    break; } case Data_M_SORT_ALLOWS_VARIABLES: { /* Function SORTS-S-Data-Form-2$S-Data-Form$1$SORT-ALLOWS-VARIABLES case SORT-ALLOWS-VARIABLES */
      ASSERT(sink__V92->context, !strcmp(SYMBOL(term__V93),  "S-Data-Form$1" ));
      Term sub__V103 = SUB(term__V93, 0); permitUnusedTerm(sub__V103); int sub__V103_count = term__V93_count*LINK_COUNT(sub__V103); permitUnusedInt(sub__V103_count);
      CRSX_CHECK_SORT(sink__V92->context, sub__V103, &sort_M_Reified_xForm); ASSERT(sink__V92->context, !strcmp(SYMBOL(sub__V103),  "SORT-ALLOWS-VARIABLES" ));
      Term sub__V104 = LINK(sink__V92->context, SUB(term__V93, 1)); int sub__V104_count = term__V93_count*LINK_COUNT(sub__V104); permitUnusedInt(sub__V104_count);
      /* sub__V104 = &#0 */
      NamedPropertyLink namedP__V105 = LINK_NamedPropertyLink(sink__V92->context, NAMED_PROPERTIES(term__V93));
      VariablePropertyLink varP__V106 = LINK_VariablePropertyLink(sink__V92->context, VARIABLE_PROPERTIES(term__V93));
      UNLINK(sink__V92->context, term__V93);
      ADD_PROPERTIES(sink__V92, LINK_NamedPropertyLink(sink__V92->context, namedP__V105), LINK_VariablePropertyLink(sink__V92->context, varP__V106));
      { START(sink__V92, _M_S_Data_Form_s6);
        COPY(sink__V92, sub__V104);END(sink__V92, _M_S_Data_Form_s6); }
      UNLINK_NamedPropertyLink(sink__V92->context, namedP__V105); UNLINK_VariablePropertyLink(sink__V92->context, varP__V106);
      
      return 1;
    break; } case Data_M_FORM: { /* Function SORTS-S-Data-Form-3$S-Data-Form$1$FORM case FORM */
      ASSERT(sink__V92->context, !strcmp(SYMBOL(term__V93),  "S-Data-Form$1" ));
      Term sub__V107 = SUB(term__V93, 0); permitUnusedTerm(sub__V107); int sub__V107_count = term__V93_count*LINK_COUNT(sub__V107); permitUnusedInt(sub__V107_count);
      CRSX_CHECK_SORT(sink__V92->context, sub__V107, &sort_M_Reified_xForm); ASSERT(sink__V92->context, !strcmp(SYMBOL(sub__V107),  "FORM" ));
      Term sub__V108 = LINK(sink__V92->context, SUB(sub__V107, 0)); int sub__V108_count = sub__V107_count*LINK_COUNT(sub__V108); permitUnusedInt(sub__V108_count);
      /* sub__V108 = &#0-0 */
      Term sub__V109 = LINK(sink__V92->context, SUB(sub__V107, 1)); int sub__V109_count = sub__V107_count*LINK_COUNT(sub__V109); permitUnusedInt(sub__V109_count);
      /* sub__V109 = &#0-1 */
      Term sub__V110 = LINK(sink__V92->context, SUB(term__V93, 1)); int sub__V110_count = term__V93_count*LINK_COUNT(sub__V110); permitUnusedInt(sub__V110_count);
      /* sub__V110 = &#2 */
      NamedPropertyLink namedP__V111 = LINK_NamedPropertyLink(sink__V92->context, NAMED_PROPERTIES(term__V93));
      VariablePropertyLink varP__V112 = LINK_VariablePropertyLink(sink__V92->context, VARIABLE_PROPERTIES(term__V93));
      UNLINK(sink__V92->context, term__V93);
      ADD_PROPERTIES(sink__V92, LINK_NamedPropertyLink(sink__V92->context, namedP__V111), LINK_VariablePropertyLink(sink__V92->context, varP__V112));
      { START(sink__V92, _M_S_Data_Form_s3);
        COPY(sink__V92, sub__V109);COPY(sink__V92, sub__V108);COPY(sink__V92, sub__V110);END(sink__V92, _M_S_Data_Form_s3); }
      UNLINK_NamedPropertyLink(sink__V92->context, namedP__V111); UNLINK_VariablePropertyLink(sink__V92->context, varP__V112);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION S-Data-Form$3. */
int conBindOffs_M_S_Data_Form_s3[] = {0 , 0 , 0 , 0};
char *nameFun_M_S_Data_Form_s3(Term term) { return  "S-Data-Form$3" ; }
struct _ConstructionDescriptor descriptor_M_S_Data_Form_s3 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_S_Data_Form_s3), conBindOffs_M_S_Data_Form_s3, &nameFun_M_S_Data_Form_s3, &step_M_S_Data_Form_s3};

int step_M_S_Data_Form_s3(Sink sink__V113, Term term__V114)
{
  int term__V114_count = LINK_COUNT(term__V114); permitUnusedInt(term__V114_count);
  Term sub__V115 = FORCE(sink__V113->context, SUB(term__V114, 0));
  EnumOf_M__sList choice__V116 = (IS_VARIABLE_USE(sub__V115) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V115));
  switch (choice__V116)
  {
    case Data_M__sNil: { /* Function SORTS-S-Data-Form-3$S-Data-Form$3$$Nil case $Nil */
      ASSERT(sink__V113->context, !strcmp(SYMBOL(term__V114),  "S-Data-Form$3" ));
      Term sub__V117 = SUB(term__V114, 0); permitUnusedTerm(sub__V117); int sub__V117_count = term__V114_count*LINK_COUNT(sub__V117); permitUnusedInt(sub__V117_count);
      ASSERT(sink__V113->context, !strcmp(SYMBOL(sub__V117),  "$Nil" ));
      Term sub__V118 = LINK(sink__V113->context, SUB(term__V114, 1)); int sub__V118_count = term__V114_count*LINK_COUNT(sub__V118); permitUnusedInt(sub__V118_count);
      /* sub__V118 = &#0 */
      Term sub__V119 = LINK(sink__V113->context, SUB(term__V114, 2)); int sub__V119_count = term__V114_count*LINK_COUNT(sub__V119); permitUnusedInt(sub__V119_count);
      /* sub__V119 = &#1 */
      NamedPropertyLink namedP__V120 = LINK_NamedPropertyLink(sink__V113->context, NAMED_PROPERTIES(term__V114));
      VariablePropertyLink varP__V121 = LINK_VariablePropertyLink(sink__V113->context, VARIABLE_PROPERTIES(term__V114));
      UNLINK(sink__V113->context, term__V114);
      ADD_PROPERTIES(sink__V113, LINK_NamedPropertyLink(sink__V113->context, namedP__V120), LINK_VariablePropertyLink(sink__V113->context, varP__V121));
      { START(sink__V113, _M_S_Data_Form_s5);
        COPY(sink__V113, sub__V118);COPY(sink__V113, sub__V119);END(sink__V113, _M_S_Data_Form_s5); }
      UNLINK_NamedPropertyLink(sink__V113->context, namedP__V120); UNLINK_VariablePropertyLink(sink__V113->context, varP__V121);
      
      return 1;
    break; } case Data_M__sCons: { /* Function SORTS-S-Data-Form-4$S-Data-Form$3$$Cons case $Cons */
      ASSERT(sink__V113->context, !strcmp(SYMBOL(term__V114),  "S-Data-Form$3" ));
      Term sub__V122 = SUB(term__V114, 0); permitUnusedTerm(sub__V122); int sub__V122_count = term__V114_count*LINK_COUNT(sub__V122); permitUnusedInt(sub__V122_count);
      ASSERT(sink__V113->context, !strcmp(SYMBOL(sub__V122),  "$Cons" ));
      Term sub__V123 = LINK(sink__V113->context, SUB(sub__V122, 0)); int sub__V123_count = sub__V122_count*LINK_COUNT(sub__V123); permitUnusedInt(sub__V123_count);
      /* sub__V123 = &#0-0 */
      Term sub__V124 = LINK(sink__V113->context, SUB(sub__V122, 1)); int sub__V124_count = sub__V122_count*LINK_COUNT(sub__V124); permitUnusedInt(sub__V124_count);
      /* sub__V124 = &#0-1 */
      Term sub__V125 = LINK(sink__V113->context, SUB(term__V114, 1)); int sub__V125_count = term__V114_count*LINK_COUNT(sub__V125); permitUnusedInt(sub__V125_count);
      /* sub__V125 = &#2 */
      Term sub__V126 = LINK(sink__V113->context, SUB(term__V114, 2)); int sub__V126_count = term__V114_count*LINK_COUNT(sub__V126); permitUnusedInt(sub__V126_count);
      /* sub__V126 = &#3 */
      NamedPropertyLink namedP__V127 = LINK_NamedPropertyLink(sink__V113->context, NAMED_PROPERTIES(term__V114));
      VariablePropertyLink varP__V128 = LINK_VariablePropertyLink(sink__V113->context, VARIABLE_PROPERTIES(term__V114));
      UNLINK(sink__V113->context, term__V114);
      ADD_PROPERTIES(sink__V113, LINK_NamedPropertyLink(sink__V113->context, namedP__V127), LINK_VariablePropertyLink(sink__V113->context, varP__V128));
      { START(sink__V113, _M_S_Data_Form_s4);
        COPY(sink__V113, sub__V123);COPY(sink__V113, sub__V124);COPY(sink__V113, sub__V125);COPY(sink__V113, sub__V126);END(sink__V113, _M_S_Data_Form_s4); }
      UNLINK_NamedPropertyLink(sink__V113->context, namedP__V127); UNLINK_VariablePropertyLink(sink__V113->context, varP__V128);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION S-Data-Form$4. */
int conBindOffs_M_S_Data_Form_s4[] = {0 , 0 , 0 , 0 , 0};
char *nameFun_M_S_Data_Form_s4(Term term) { return  "S-Data-Form$4" ; }
struct _ConstructionDescriptor descriptor_M_S_Data_Form_s4 = {&sort_M_Reified_xVariable, 0, 4, sizeof(STRUCT_Con_M_S_Data_Form_s4), conBindOffs_M_S_Data_Form_s4, &nameFun_M_S_Data_Form_s4, &step_M_S_Data_Form_s4};

int step_M_S_Data_Form_s4(Sink sink__V129, Term term__V130)
{
  int term__V130_count = LINK_COUNT(term__V130); permitUnusedInt(term__V130_count);
  do {
    /* Contraction rule SORTS-S-Data-Form-4. */
    ASSERT(sink__V129->context, !strcmp(SYMBOL(term__V130),  "S-Data-Form$4" ));
    Term sub__V131 = LINK(sink__V129->context, SUB(term__V130, 0)); int sub__V131_count = term__V130_count*LINK_COUNT(sub__V131); permitUnusedInt(sub__V131_count);
    UNLINK_SUB(sink__V129->context, term__V130,  0); NORMALIZE(sink__V129->context, sub__V131); SUB(term__V130,  0) = LINK(sink__V129->context, sub__V131);
    /* sub__V131 = &#221 */
    Term sub__V132 = LINK(sink__V129->context, SUB(term__V130, 1)); int sub__V132_count = term__V130_count*LINK_COUNT(sub__V132); permitUnusedInt(sub__V132_count);
    UNLINK_SUB(sink__V129->context, term__V130,  1); NORMALIZE(sink__V129->context, sub__V132); SUB(term__V130,  1) = LINK(sink__V129->context, sub__V132);
    /* sub__V132 = &#222 */
    Term sub__V133 = LINK(sink__V129->context, SUB(term__V130, 2)); int sub__V133_count = term__V130_count*LINK_COUNT(sub__V133); permitUnusedInt(sub__V133_count);
    UNLINK_SUB(sink__V129->context, term__V130,  2); NORMALIZE(sink__V129->context, sub__V133); SUB(term__V130,  2) = LINK(sink__V129->context, sub__V133);
    /* sub__V133 = &#21 */
    Term sub__V134 = LINK(sink__V129->context, SUB(term__V130, 3)); int sub__V134_count = term__V130_count*LINK_COUNT(sub__V134); permitUnusedInt(sub__V134_count);
    /* sub__V134 = &#1 */
    NamedPropertyLink namedP__V135 = LINK_NamedPropertyLink(sink__V129->context, NAMED_PROPERTIES(term__V130));
    VariablePropertyLink varP__V136 = LINK_VariablePropertyLink(sink__V129->context, VARIABLE_PROPERTIES(term__V130));
    UNLINK(sink__V129->context, term__V130);
    { START(sink__V129, _M__sTextCons);
      { START(sink__V129, _M__sTextChars);
        LITERAL(sink__V129,  "int " ); END(sink__V129, _M__sTextChars); }
      { START(sink__V129, _M__sTextCons);
        { START(sink__V129, _M__sTextEmbed);
          { START(sink__V129, _M_AsText);
            { START(sink__V129, _M_BinderOffsets);
              COPY(sink__V129, LINK(sink__V129->context, sub__V133));END(sink__V129, _M_BinderOffsets); }
            END(sink__V129, _M_AsText); }
          END(sink__V129, _M__sTextEmbed); }
        { START(sink__V129, _M__sTextCons);
          { START(sink__V129, _M__sTextChars);
            LITERAL(sink__V129,  "[] = {0" ); END(sink__V129, _M__sTextChars); }
          { START(sink__V129, _M__sTextCons);
            { START(sink__V129, _M__sTextEmbed);
              { START(sink__V129, _M_AsText);
                { START(sink__V129, _M_DelayMapText_s1);
                  { START(sink__V129, _M_FormArguments__binder__offsets);
                    { START(sink__V129, _M__sCons);
                      COPY(sink__V129, sub__V131);COPY(sink__V129, LINK(sink__V129->context, sub__V132));END(sink__V129, _M__sCons); }
                    LITERAL(sink__V129,  "0" ); END(sink__V129, _M_FormArguments__binder__offsets); }
                  { Variable x__V137 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V129->context,"x__V137");
                    Variable x__V138 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V129->context,"x__V138");
                    Variable binds__V139[2] = {x__V137,x__V138}; BINDS(sink__V129, 2, binds__V139);
                    { START(sink__V129, _M__sTextCons);
                      { START(sink__V129, _M__sTextChars);
                        LITERAL(sink__V129,  " , " ); END(sink__V129, _M__sTextChars); }
                      { START(sink__V129, _M__sTextCons);
                        { START(sink__V129, _M__sTextEmbed);
                          { START(sink__V129, _M_AsText);
                            { START(sink__V129, _M_DINTEGER);
                              USE(sink__V129, x__V137); USE(sink__V129, x__V138); END(sink__V129, _M_DINTEGER); }
                            END(sink__V129, _M_AsText); }
                          END(sink__V129, _M__sTextEmbed); }
                        { START(sink__V129, _M__sTextNil);
                          END(sink__V129, _M__sTextNil); }
                        END(sink__V129, _M__sTextCons); }
                      END(sink__V129, _M__sTextCons); }
                     }
                  END(sink__V129, _M_DelayMapText_s1); }
                END(sink__V129, _M_AsText); }
              END(sink__V129, _M__sTextEmbed); }
            { START(sink__V129, _M__sTextCons);
              { START(sink__V129, _M__sTextChars);
                LITERAL(sink__V129,  "};" ); END(sink__V129, _M__sTextChars); }
              { START(sink__V129, _M__sTextCons);
                { START(sink__V129, _M__sTextBreak);
                  LITERAL(sink__V129,  "\n" ); END(sink__V129, _M__sTextBreak); }
                { START(sink__V129, _M__sTextCons);
                  { START(sink__V129, _M__sTextChars);
                    LITERAL(sink__V129,  "char *" ); END(sink__V129, _M__sTextChars); }
                  { START(sink__V129, _M__sTextCons);
                    { START(sink__V129, _M__sTextEmbed);
                      { START(sink__V129, _M_AsText);
                        { START(sink__V129, _M_Name);
                          COPY(sink__V129, LINK(sink__V129->context, sub__V133));END(sink__V129, _M_Name); }
                        END(sink__V129, _M_AsText); }
                      END(sink__V129, _M__sTextEmbed); }
                    { START(sink__V129, _M__sTextCons);
                      { START(sink__V129, _M__sTextChars);
                        LITERAL(sink__V129,  " = " ); END(sink__V129, _M__sTextChars); }
                      { START(sink__V129, _M__sTextCons);
                        { START(sink__V129, _M__sTextEmbed);
                          { START(sink__V129, _M_AsText);
                            { START(sink__V129, _M_STRING);
                              COPY(sink__V129, LINK(sink__V129->context, sub__V133));END(sink__V129, _M_STRING); }
                            END(sink__V129, _M_AsText); }
                          END(sink__V129, _M__sTextEmbed); }
                        { START(sink__V129, _M__sTextCons);
                          { START(sink__V129, _M__sTextChars);
                            LITERAL(sink__V129,  ";" ); END(sink__V129, _M__sTextChars); }
                          { START(sink__V129, _M__sTextCons);
                            { START(sink__V129, _M__sTextBreak);
                              LITERAL(sink__V129,  "\n" ); END(sink__V129, _M__sTextBreak); }
                            { START(sink__V129, _M__sTextCons);
                              { START(sink__V129, _M__sTextChars);
                                LITERAL(sink__V129,  "char *" ); END(sink__V129, _M__sTextChars); }
                              { START(sink__V129, _M__sTextCons);
                                { START(sink__V129, _M__sTextEmbed);
                                  { START(sink__V129, _M_AsText);
                                    { START(sink__V129, _M_NameFun);
                                      COPY(sink__V129, LINK(sink__V129->context, sub__V133));END(sink__V129, _M_NameFun); }
                                    END(sink__V129, _M_AsText); }
                                  END(sink__V129, _M__sTextEmbed); }
                                { START(sink__V129, _M__sTextCons);
                                  { START(sink__V129, _M__sTextChars);
                                    LITERAL(sink__V129,  "(Term term) { return " );
                                    END(sink__V129, _M__sTextChars); }
                                  { START(sink__V129, _M__sTextCons);
                                    { START(sink__V129, _M__sTextEmbed);
                                      { START(sink__V129, _M_AsText);
                                        { START(sink__V129, _M_Name);
                                          COPY(sink__V129, LINK(sink__V129->context, sub__V133));END(sink__V129, _M_Name); }
                                        END(sink__V129, _M_AsText); }
                                      END(sink__V129, _M__sTextEmbed); }
                                    { START(sink__V129, _M__sTextCons);
                                      { START(sink__V129, _M__sTextChars);
                                        LITERAL(sink__V129,  "; }" ); END(sink__V129, _M__sTextChars); }
                                      { START(sink__V129, _M__sTextCons);
                                        { START(sink__V129, _M__sTextBreak);
                                          LITERAL(sink__V129,  "\n" ); END(sink__V129, _M__sTextBreak); }
                                        { START(sink__V129, _M__sTextCons);
                                          { START(sink__V129, _M__sTextChars);
                                            LITERAL(sink__V129,  "struct _ConstructionDescriptor " );
                                            END(sink__V129, _M__sTextChars); }
                                          { START(sink__V129, _M__sTextCons);
                                            { START(sink__V129, _M__sTextEmbed);
                                              { START(sink__V129, _M_AsText);
                                                { START(sink__V129, _M_Descriptor);
                                                  COPY(sink__V129, LINK(sink__V129->context, sub__V133));END(sink__V129, _M_Descriptor); }
                                                END(sink__V129, _M_AsText); }
                                              END(sink__V129, _M__sTextEmbed); }
                                            { START(sink__V129, _M__sTextCons);
                                              { START(sink__V129, _M__sTextChars);
                                                LITERAL(sink__V129,  " = {&" );
                                                END(sink__V129, _M__sTextChars); }
                                              { START(sink__V129, _M__sTextCons);
                                                { START(sink__V129, _M__sTextEmbed);
                                                  { START(sink__V129, _M_AsText);
                                                    { START(sink__V129, _M_Sort);
                                                      COPY(sink__V129, sub__V134);END(sink__V129, _M_Sort); }
                                                    END(sink__V129, _M_AsText); }
                                                  END(sink__V129, _M__sTextEmbed); }
                                                { START(sink__V129, _M__sTextCons);
                                                  { START(sink__V129, _M__sTextChars);
                                                    LITERAL(sink__V129,  ", " );
                                                    END(sink__V129, _M__sTextChars); }
                                                  { START(sink__V129, _M__sTextCons);
                                                    { START(sink__V129, _M__sTextEmbed);
                                                      { START(sink__V129, _M_AsText);
                                                        { START(sink__V129, _M_EnumTag);
                                                          COPY(sink__V129, LINK(sink__V129->context, sub__V133));END(sink__V129, _M_EnumTag); }
                                                        END(sink__V129, _M_AsText); }
                                                      END(sink__V129, _M__sTextEmbed); }
                                                    { START(sink__V129, _M__sTextCons);
                                                      { START(sink__V129, _M__sTextChars);
                                                        LITERAL(sink__V129,  ", " );
                                                        END(sink__V129, _M__sTextChars); }
                                                      { START(sink__V129, _M__sTextCons);
                                                        { START(sink__V129, _M__sTextEmbed);
                                                          { START(sink__V129, _M_AsText);
                                                            { START(sink__V129, _M_INTEGER);
                                                              { START(sink__V129, _M_Length);
                                                                COPY(sink__V129, sub__V132);LITERAL(sink__V129,  "1" );
                                                                END(sink__V129, _M_Length); }
                                                              END(sink__V129, _M_INTEGER); }
                                                            END(sink__V129, _M_AsText); }
                                                          END(sink__V129, _M__sTextEmbed); }
                                                        { START(sink__V129, _M__sTextCons);
                                                          { START(sink__V129, _M__sTextChars);
                                                            LITERAL(sink__V129,  ", sizeof(STRUCT" );
                                                            END(sink__V129, _M__sTextChars); }
                                                          { START(sink__V129, _M__sTextCons);
                                                            { START(sink__V129, _M__sTextEmbed);
                                                              { START(sink__V129, _M_AsText);
                                                                { START(sink__V129, _M_Struct);
                                                                  COPY(sink__V129, LINK(sink__V129->context, sub__V133));END(sink__V129, _M_Struct); }
                                                                END(sink__V129, _M_AsText); }
                                                              END(sink__V129, _M__sTextEmbed); }
                                                            { START(sink__V129, _M__sTextCons);
                                                              { START(sink__V129, _M__sTextChars);
                                                                LITERAL(sink__V129,  "), " );
                                                                END(sink__V129, _M__sTextChars); }
                                                              { START(sink__V129, _M__sTextCons);
                                                                { START(sink__V129, _M__sTextEmbed);
                                                                  { START(sink__V129, _M_AsText);
                                                                    { START(sink__V129, _M_BinderOffsets);
                                                                      COPY(sink__V129, LINK(sink__V129->context, sub__V133));END(sink__V129, _M_BinderOffsets); }
                                                                    END(sink__V129, _M_AsText); }
                                                                  END(sink__V129, _M__sTextEmbed); }
                                                                { START(sink__V129, _M__sTextCons);
                                                                  { START(sink__V129, _M__sTextChars);
                                                                    LITERAL(sink__V129,  ", &" );
                                                                    END(sink__V129, _M__sTextChars); }
                                                                  { START(sink__V129, _M__sTextCons);
                                                                    { START(sink__V129, _M__sTextEmbed);
                                                                      { START(sink__V129, _M_AsText);
                                                                        { START(sink__V129, _M_NameFun);
                                                                          COPY(sink__V129, sub__V133);END(sink__V129, _M_NameFun); }
                                                                        END(sink__V129, _M_AsText); }
                                                                      END(sink__V129, _M__sTextEmbed); }
                                                                    { START(sink__V129, _M__sTextCons);
                                                                      { START(sink__V129, _M__sTextChars);
                                                                        LITERAL(sink__V129,  ", &dataStep};" );
                                                                        END(sink__V129, _M__sTextChars); }
                                                                      { START(sink__V129, _M__sTextCons);
                                                                        { START(sink__V129, _M__sTextBreak);
                                                                          LITERAL(sink__V129,  "\n" );
                                                                          END(sink__V129, _M__sTextBreak); }
                                                                        { START(sink__V129, _M__sTextNil);
                                                                          END(sink__V129, _M__sTextNil); }
                                                                        END(sink__V129, _M__sTextCons); }
                                                                      END(sink__V129, _M__sTextCons); }
                                                                    END(sink__V129, _M__sTextCons); }
                                                                  END(sink__V129, _M__sTextCons); }
                                                                END(sink__V129, _M__sTextCons); }
                                                              END(sink__V129, _M__sTextCons); }
                                                            END(sink__V129, _M__sTextCons); }
                                                          END(sink__V129, _M__sTextCons); }
                                                        END(sink__V129, _M__sTextCons); }
                                                      END(sink__V129, _M__sTextCons); }
                                                    END(sink__V129, _M__sTextCons); }
                                                  END(sink__V129, _M__sTextCons); }
                                                END(sink__V129, _M__sTextCons); }
                                              END(sink__V129, _M__sTextCons); }
                                            END(sink__V129, _M__sTextCons); }
                                          END(sink__V129, _M__sTextCons); }
                                        END(sink__V129, _M__sTextCons); }
                                      END(sink__V129, _M__sTextCons); }
                                    END(sink__V129, _M__sTextCons); }
                                  END(sink__V129, _M__sTextCons); }
                                END(sink__V129, _M__sTextCons); }
                              END(sink__V129, _M__sTextCons); }
                            END(sink__V129, _M__sTextCons); }
                          END(sink__V129, _M__sTextCons); }
                        END(sink__V129, _M__sTextCons); }
                      END(sink__V129, _M__sTextCons); }
                    END(sink__V129, _M__sTextCons); }
                  END(sink__V129, _M__sTextCons); }
                END(sink__V129, _M__sTextCons); }
              END(sink__V129, _M__sTextCons); }
            END(sink__V129, _M__sTextCons); }
          END(sink__V129, _M__sTextCons); }
        END(sink__V129, _M__sTextCons); }
      END(sink__V129, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V129->context, namedP__V135); UNLINK_VariablePropertyLink(sink__V129->context, varP__V136);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION S-Data-Form$5. */
int conBindOffs_M_S_Data_Form_s5[] = {0 , 0 , 0};
char *nameFun_M_S_Data_Form_s5(Term term) { return  "S-Data-Form$5" ; }
struct _ConstructionDescriptor descriptor_M_S_Data_Form_s5 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_S_Data_Form_s5), conBindOffs_M_S_Data_Form_s5, &nameFun_M_S_Data_Form_s5, &step_M_S_Data_Form_s5};

int step_M_S_Data_Form_s5(Sink sink__V140, Term term__V141)
{
  int term__V141_count = LINK_COUNT(term__V141); permitUnusedInt(term__V141_count);
  do {
    /* Contraction rule SORTS-S-Data-Form-3. */
    ASSERT(sink__V140->context, !strcmp(SYMBOL(term__V141),  "S-Data-Form$5" ));
    Term sub__V142 = LINK(sink__V140->context, SUB(term__V141, 0)); int sub__V142_count = term__V141_count*LINK_COUNT(sub__V142); permitUnusedInt(sub__V142_count);
    UNLINK_SUB(sink__V140->context, term__V141,  0); NORMALIZE(sink__V140->context, sub__V142); SUB(term__V141,  0) = LINK(sink__V140->context, sub__V142);
    /* sub__V142 = &#21 */
    Term sub__V143 = LINK(sink__V140->context, SUB(term__V141, 1)); int sub__V143_count = term__V141_count*LINK_COUNT(sub__V143); permitUnusedInt(sub__V143_count);
    /* sub__V143 = &#1 */
    NamedPropertyLink namedP__V144 = LINK_NamedPropertyLink(sink__V140->context, NAMED_PROPERTIES(term__V141));
    VariablePropertyLink varP__V145 = LINK_VariablePropertyLink(sink__V140->context, VARIABLE_PROPERTIES(term__V141));
    UNLINK(sink__V140->context, term__V141);
    { START(sink__V140, _M__sTextCons);
      { START(sink__V140, _M__sTextChars);
        LITERAL(sink__V140,  "char *" ); END(sink__V140, _M__sTextChars); }
      { START(sink__V140, _M__sTextCons);
        { START(sink__V140, _M__sTextEmbed);
          { START(sink__V140, _M_AsText);
            { START(sink__V140, _M_Name);
              COPY(sink__V140, LINK(sink__V140->context, sub__V142));END(sink__V140, _M_Name); }
            END(sink__V140, _M_AsText); }
          END(sink__V140, _M__sTextEmbed); }
        { START(sink__V140, _M__sTextCons);
          { START(sink__V140, _M__sTextChars);
            LITERAL(sink__V140,  " = " ); END(sink__V140, _M__sTextChars); }
          { START(sink__V140, _M__sTextCons);
            { START(sink__V140, _M__sTextEmbed);
              { START(sink__V140, _M_AsText);
                { START(sink__V140, _M_STRING);
                  COPY(sink__V140, LINK(sink__V140->context, sub__V142));END(sink__V140, _M_STRING); }
                END(sink__V140, _M_AsText); }
              END(sink__V140, _M__sTextEmbed); }
            { START(sink__V140, _M__sTextCons);
              { START(sink__V140, _M__sTextChars);
                LITERAL(sink__V140,  ";" ); END(sink__V140, _M__sTextChars); }
              { START(sink__V140, _M__sTextCons);
                { START(sink__V140, _M__sTextBreak);
                  LITERAL(sink__V140,  "\n" ); END(sink__V140, _M__sTextBreak); }
                { START(sink__V140, _M__sTextCons);
                  { START(sink__V140, _M__sTextChars);
                    LITERAL(sink__V140,  "char *" ); END(sink__V140, _M__sTextChars); }
                  { START(sink__V140, _M__sTextCons);
                    { START(sink__V140, _M__sTextEmbed);
                      { START(sink__V140, _M_AsText);
                        { START(sink__V140, _M_NameFun);
                          COPY(sink__V140, LINK(sink__V140->context, sub__V142));END(sink__V140, _M_NameFun); }
                        END(sink__V140, _M_AsText); }
                      END(sink__V140, _M__sTextEmbed); }
                    { START(sink__V140, _M__sTextCons);
                      { START(sink__V140, _M__sTextChars);
                        LITERAL(sink__V140,  "(Term term) { return " );
                        END(sink__V140, _M__sTextChars); }
                      { START(sink__V140, _M__sTextCons);
                        { START(sink__V140, _M__sTextEmbed);
                          { START(sink__V140, _M_AsText);
                            { START(sink__V140, _M_Name);
                              COPY(sink__V140, LINK(sink__V140->context, sub__V142));END(sink__V140, _M_Name); }
                            END(sink__V140, _M_AsText); }
                          END(sink__V140, _M__sTextEmbed); }
                        { START(sink__V140, _M__sTextCons);
                          { START(sink__V140, _M__sTextChars);
                            LITERAL(sink__V140,  "; }" ); END(sink__V140, _M__sTextChars); }
                          { START(sink__V140, _M__sTextCons);
                            { START(sink__V140, _M__sTextBreak);
                              LITERAL(sink__V140,  "\n" ); END(sink__V140, _M__sTextBreak); }
                            { START(sink__V140, _M__sTextCons);
                              { START(sink__V140, _M__sTextChars);
                                LITERAL(sink__V140,  "struct _ConstructionDescriptor " );
                                END(sink__V140, _M__sTextChars); }
                              { START(sink__V140, _M__sTextCons);
                                { START(sink__V140, _M__sTextEmbed);
                                  { START(sink__V140, _M_AsText);
                                    { START(sink__V140, _M_Descriptor);
                                      COPY(sink__V140, LINK(sink__V140->context, sub__V142));END(sink__V140, _M_Descriptor); }
                                    END(sink__V140, _M_AsText); }
                                  END(sink__V140, _M__sTextEmbed); }
                                { START(sink__V140, _M__sTextCons);
                                  { START(sink__V140, _M__sTextChars);
                                    LITERAL(sink__V140,  " = {&" ); END(sink__V140, _M__sTextChars); }
                                  { START(sink__V140, _M__sTextCons);
                                    { START(sink__V140, _M__sTextEmbed);
                                      { START(sink__V140, _M_AsText);
                                        { START(sink__V140, _M_Sort);
                                          COPY(sink__V140, sub__V143);END(sink__V140, _M_Sort); }
                                        END(sink__V140, _M_AsText); }
                                      END(sink__V140, _M__sTextEmbed); }
                                    { START(sink__V140, _M__sTextCons);
                                      { START(sink__V140, _M__sTextChars);
                                        LITERAL(sink__V140,  ", " ); END(sink__V140, _M__sTextChars); }
                                      { START(sink__V140, _M__sTextCons);
                                        { START(sink__V140, _M__sTextEmbed);
                                          { START(sink__V140, _M_AsText);
                                            { START(sink__V140, _M_EnumTag);
                                              COPY(sink__V140, LINK(sink__V140->context, sub__V142));END(sink__V140, _M_EnumTag); }
                                            END(sink__V140, _M_AsText); }
                                          END(sink__V140, _M__sTextEmbed); }
                                        { START(sink__V140, _M__sTextCons);
                                          { START(sink__V140, _M__sTextChars);
                                            LITERAL(sink__V140,  ", 0, sizeof(STRUCT" );
                                            END(sink__V140, _M__sTextChars); }
                                          { START(sink__V140, _M__sTextCons);
                                            { START(sink__V140, _M__sTextEmbed);
                                              { START(sink__V140, _M_AsText);
                                                { START(sink__V140, _M_Struct);
                                                  COPY(sink__V140, LINK(sink__V140->context, sub__V142));END(sink__V140, _M_Struct); }
                                                END(sink__V140, _M_AsText); }
                                              END(sink__V140, _M__sTextEmbed); }
                                            { START(sink__V140, _M__sTextCons);
                                              { START(sink__V140, _M__sTextChars);
                                                LITERAL(sink__V140,  "), noBinderOffsets, &" );
                                                END(sink__V140, _M__sTextChars); }
                                              { START(sink__V140, _M__sTextCons);
                                                { START(sink__V140, _M__sTextEmbed);
                                                  { START(sink__V140, _M_AsText);
                                                    { START(sink__V140, _M_NameFun);
                                                      COPY(sink__V140, sub__V142);END(sink__V140, _M_NameFun); }
                                                    END(sink__V140, _M_AsText); }
                                                  END(sink__V140, _M__sTextEmbed); }
                                                { START(sink__V140, _M__sTextCons);
                                                  { START(sink__V140, _M__sTextChars);
                                                    LITERAL(sink__V140,  ", &dataStep};" );
                                                    END(sink__V140, _M__sTextChars); }
                                                  { START(sink__V140, _M__sTextCons);
                                                    { START(sink__V140, _M__sTextBreak);
                                                      LITERAL(sink__V140,  "\n" );
                                                      END(sink__V140, _M__sTextBreak); }
                                                    { START(sink__V140, _M__sTextNil);
                                                      END(sink__V140, _M__sTextNil); }
                                                    END(sink__V140, _M__sTextCons); }
                                                  END(sink__V140, _M__sTextCons); }
                                                END(sink__V140, _M__sTextCons); }
                                              END(sink__V140, _M__sTextCons); }
                                            END(sink__V140, _M__sTextCons); }
                                          END(sink__V140, _M__sTextCons); }
                                        END(sink__V140, _M__sTextCons); }
                                      END(sink__V140, _M__sTextCons); }
                                    END(sink__V140, _M__sTextCons); }
                                  END(sink__V140, _M__sTextCons); }
                                END(sink__V140, _M__sTextCons); }
                              END(sink__V140, _M__sTextCons); }
                            END(sink__V140, _M__sTextCons); }
                          END(sink__V140, _M__sTextCons); }
                        END(sink__V140, _M__sTextCons); }
                      END(sink__V140, _M__sTextCons); }
                    END(sink__V140, _M__sTextCons); }
                  END(sink__V140, _M__sTextCons); }
                END(sink__V140, _M__sTextCons); }
              END(sink__V140, _M__sTextCons); }
            END(sink__V140, _M__sTextCons); }
          END(sink__V140, _M__sTextCons); }
        END(sink__V140, _M__sTextCons); }
      END(sink__V140, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V140->context, namedP__V144); UNLINK_VariablePropertyLink(sink__V140->context, varP__V145);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION S-Data-Form$6. */
int conBindOffs_M_S_Data_Form_s6[] = {0 , 0};
char *nameFun_M_S_Data_Form_s6(Term term) { return  "S-Data-Form$6" ; }
struct _ConstructionDescriptor descriptor_M_S_Data_Form_s6 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_S_Data_Form_s6), conBindOffs_M_S_Data_Form_s6, &nameFun_M_S_Data_Form_s6, &step_M_S_Data_Form_s6};

int step_M_S_Data_Form_s6(Sink sink__V146, Term term__V147)
{
  int term__V147_count = LINK_COUNT(term__V147); permitUnusedInt(term__V147_count);
  do {
    /* Contraction rule SORTS-S-Data-Form-2. */
    ASSERT(sink__V146->context, !strcmp(SYMBOL(term__V147),  "S-Data-Form$6" ));
    Term sub__V148 = SUB(term__V147, 0); permitUnusedTerm(sub__V148); int sub__V148_count = term__V147_count*LINK_COUNT(sub__V148); permitUnusedInt(sub__V148_count);
    /* sub__V148 = &#1 */
    NamedPropertyLink namedP__V149 = LINK_NamedPropertyLink(sink__V146->context, NAMED_PROPERTIES(term__V147));
    VariablePropertyLink varP__V150 = LINK_VariablePropertyLink(sink__V146->context, VARIABLE_PROPERTIES(term__V147));
    UNLINK(sink__V146->context, term__V147);
    { START(sink__V146, _M__sTextNil); END(sink__V146, _M__sTextNil); }
    UNLINK_NamedPropertyLink(sink__V146->context, namedP__V149); UNLINK_VariablePropertyLink(sink__V146->context, varP__V150);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION S-Data-Form$7. */
int conBindOffs_M_S_Data_Form_s7[] = {0 , 0 , 0 , 0 , 0};
char *nameFun_M_S_Data_Form_s7(Term term) { return  "S-Data-Form$7" ; }
struct _ConstructionDescriptor descriptor_M_S_Data_Form_s7 = {&sort_M_Reified_xVariable, 0, 4, sizeof(STRUCT_Con_M_S_Data_Form_s7), conBindOffs_M_S_Data_Form_s7, &nameFun_M_S_Data_Form_s7, &step_M_S_Data_Form_s7};

int step_M_S_Data_Form_s7(Sink sink__V151, Term term__V152)
{
  int term__V152_count = LINK_COUNT(term__V152); permitUnusedInt(term__V152_count);
  do {
    /* Contraction rule SORTS-S-Data-Form-1. */
    ASSERT(sink__V151->context, !strcmp(SYMBOL(term__V152),  "S-Data-Form$7" ));
    Term sub__V153 = SUB(term__V152, 0); permitUnusedTerm(sub__V153); int sub__V153_count = term__V152_count*LINK_COUNT(sub__V153); permitUnusedInt(sub__V153_count);
    CRSX_CHECK_SORT(sink__V151->context, sub__V153, &sort_M_Reified_xSort); /* sub__V153 = &#21 */
    Term sub__V154 = SUB(term__V152, 1); permitUnusedTerm(sub__V154); int sub__V154_count = term__V152_count*LINK_COUNT(sub__V154); permitUnusedInt(sub__V154_count);
    CRSX_CHECK_SORT(sink__V151->context, sub__V154, &sort_M_Reified_xSort); /* sub__V154 = &#22 */
    Term sub__V155 = LINK(sink__V151->context, SUB(term__V152, 2)); int sub__V155_count = term__V152_count*LINK_COUNT(sub__V155); permitUnusedInt(sub__V155_count);
    CRSX_CHECK_SORT(sink__V151->context, sub__V155, &sort_M_Reified_xForm); /* sub__V155 = &#23 */
    Term sub__V156 = LINK(sink__V151->context, SUB(term__V152, 3)); int sub__V156_count = term__V152_count*LINK_COUNT(sub__V156); permitUnusedInt(sub__V156_count);
    /* sub__V156 = &#1 */
    NamedPropertyLink namedP__V157 = LINK_NamedPropertyLink(sink__V151->context, NAMED_PROPERTIES(term__V152));
    VariablePropertyLink varP__V158 = LINK_VariablePropertyLink(sink__V151->context, VARIABLE_PROPERTIES(term__V152));
    UNLINK(sink__V151->context, term__V152);
    { START(sink__V151, _M_S_Data_Form_s1);
      COPY(sink__V151, sub__V155);COPY(sink__V151, sub__V156);END(sink__V151, _M_S_Data_Form_s1); }
    UNLINK_NamedPropertyLink(sink__V151->context, namedP__V157); UNLINK_VariablePropertyLink(sink__V151->context, varP__V158);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION S-Declaration. */
int conBindOffs_M_S_Declaration[] = {0 , 0};
char *nameFun_M_S_Declaration(Term term) { return  "S-Declaration" ; }
struct _ConstructionDescriptor descriptor_M_S_Declaration = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_S_Declaration), conBindOffs_M_S_Declaration, &nameFun_M_S_Declaration, &step_M_S_Declaration};

int step_M_S_Declaration(Sink sink__V159, Term term__V160)
{
  int term__V160_count = LINK_COUNT(term__V160); permitUnusedInt(term__V160_count);
  Term sub__V161 = FORCE(sink__V159->context, SUB(term__V160, 0));
  EnumOf_M_Reified_xDeclaration choice__V162 = (IS_VARIABLE_USE(sub__V161) ? VarOf_M_Reified_xDeclaration : (EnumOf_M_Reified_xDeclaration) TAG(sub__V161));
  switch (choice__V162)
  {
    case Data_M_DATA: { /* Function SORTS-Data$S-Declaration$DATA case DATA */
      ASSERT(sink__V159->context, !strcmp(SYMBOL(term__V160),  "S-Declaration" ));
      Term sub__V163 = SUB(term__V160, 0); permitUnusedTerm(sub__V163); int sub__V163_count = term__V160_count*LINK_COUNT(sub__V163); permitUnusedInt(sub__V163_count);
      CRSX_CHECK_SORT(sink__V159->context, sub__V163, &sort_M_Reified_xDeclaration); ASSERT(sink__V159->context, !strcmp(SYMBOL(sub__V163),  "DATA" ));
      Term sub__V164 = LINK(sink__V159->context, SUB(sub__V163, 0)); int sub__V164_count = sub__V163_count*LINK_COUNT(sub__V164); permitUnusedInt(sub__V164_count);
      CRSX_CHECK_SORT(sink__V159->context, sub__V164, &sort_M_Reified_xSort); /* sub__V164 = &#0-0 */
      Term sub__V165 = LINK(sink__V159->context, SUB(sub__V163, 1)); int sub__V165_count = sub__V163_count*LINK_COUNT(sub__V165); permitUnusedInt(sub__V165_count);
      /* sub__V165 = &#0-1 */
      NamedPropertyLink namedP__V166 = LINK_NamedPropertyLink(sink__V159->context, NAMED_PROPERTIES(term__V160));
      VariablePropertyLink varP__V167 = LINK_VariablePropertyLink(sink__V159->context, VARIABLE_PROPERTIES(term__V160));
      UNLINK(sink__V159->context, term__V160);
      ADD_PROPERTIES(sink__V159, LINK_NamedPropertyLink(sink__V159->context, namedP__V166), LINK_VariablePropertyLink(sink__V159->context, varP__V167));
      { START(sink__V159, _M_S_Declaration_s1);
        COPY(sink__V159, sub__V164);COPY(sink__V159, sub__V165);END(sink__V159, _M_S_Declaration_s1); }
      UNLINK_NamedPropertyLink(sink__V159->context, namedP__V166); UNLINK_VariablePropertyLink(sink__V159->context, varP__V167);
      
      return 1;
    break; } case Data_M_FUNCTION: { /* Function SORTS-Function$S-Declaration$FUNCTION case FUNCTION */
      ASSERT(sink__V159->context, !strcmp(SYMBOL(term__V160),  "S-Declaration" ));
      Term sub__V168 = SUB(term__V160, 0); permitUnusedTerm(sub__V168); int sub__V168_count = term__V160_count*LINK_COUNT(sub__V168); permitUnusedInt(sub__V168_count);
      CRSX_CHECK_SORT(sink__V159->context, sub__V168, &sort_M_Reified_xDeclaration); ASSERT(sink__V159->context, !strcmp(SYMBOL(sub__V168),  "FUNCTION" ));
      Term sub__V169 = LINK(sink__V159->context, SUB(sub__V168, 0)); int sub__V169_count = sub__V168_count*LINK_COUNT(sub__V169); permitUnusedInt(sub__V169_count);
      /* sub__V169 = &#0-0 */
      Term sub__V170 = LINK(sink__V159->context, SUB(sub__V168, 1)); int sub__V170_count = sub__V168_count*LINK_COUNT(sub__V170); permitUnusedInt(sub__V170_count);
      /* sub__V170 = &#0-1 */
      Term sub__V171 = LINK(sink__V159->context, SUB(sub__V168, 2)); int sub__V171_count = sub__V168_count*LINK_COUNT(sub__V171); permitUnusedInt(sub__V171_count);
      /* sub__V171 = &#0-2 */
      Term sub__V172 = LINK(sink__V159->context, SUB(sub__V168, 3)); int sub__V172_count = sub__V168_count*LINK_COUNT(sub__V172); permitUnusedInt(sub__V172_count);
      /* sub__V172 = &#0-3 */
      Term sub__V173 = LINK(sink__V159->context, SUB(sub__V168, 4)); int sub__V173_count = sub__V168_count*LINK_COUNT(sub__V173); permitUnusedInt(sub__V173_count);
      /* sub__V173 = &#0-4 */
      Term sub__V174 = LINK(sink__V159->context, SUB(sub__V168, 5)); int sub__V174_count = sub__V168_count*LINK_COUNT(sub__V174); permitUnusedInt(sub__V174_count);
      CRSX_CHECK_SORT(sink__V159->context, sub__V174, &sort_M_Reified_xSort); /* sub__V174 = &#0-5 */
      Term sub__V175 = LINK(sink__V159->context, SUB(sub__V168, 6)); int sub__V175_count = sub__V168_count*LINK_COUNT(sub__V175); permitUnusedInt(sub__V175_count);
      /* sub__V175 = &#0-6 */
      NamedPropertyLink namedP__V176 = LINK_NamedPropertyLink(sink__V159->context, NAMED_PROPERTIES(term__V160));
      VariablePropertyLink varP__V177 = LINK_VariablePropertyLink(sink__V159->context, VARIABLE_PROPERTIES(term__V160));
      UNLINK(sink__V159->context, term__V160);
      ADD_PROPERTIES(sink__V159, LINK_NamedPropertyLink(sink__V159->context, namedP__V176), LINK_VariablePropertyLink(sink__V159->context, varP__V177));
      { START(sink__V159, _M_S_Declaration_s2);
        COPY(sink__V159, sub__V169);COPY(sink__V159, sub__V170);COPY(sink__V159, sub__V171);COPY(sink__V159, sub__V172);COPY(sink__V159, sub__V173);COPY(sink__V159, sub__V174);COPY(sink__V159, sub__V175);END(sink__V159, _M_S_Declaration_s2); }
      UNLINK_NamedPropertyLink(sink__V159->context, namedP__V176); UNLINK_VariablePropertyLink(sink__V159->context, varP__V177);
      
      return 1;
    break; } case Data_M_POLYMORPHIC: { /* Function SORTS-Polymorphic$S-Declaration$POLYMORPHIC case POLYMORPHIC */
      ASSERT(sink__V159->context, !strcmp(SYMBOL(term__V160),  "S-Declaration" ));
      Term sub__V178 = SUB(term__V160, 0); permitUnusedTerm(sub__V178); int sub__V178_count = term__V160_count*LINK_COUNT(sub__V178); permitUnusedInt(sub__V178_count);
      CRSX_CHECK_SORT(sink__V159->context, sub__V178, &sort_M_Reified_xDeclaration); ASSERT(sink__V159->context, !strcmp(SYMBOL(sub__V178),  "POLYMORPHIC" ));
      Variable y__V179 = BINDER(sub__V178,0,0); if (sub__V178_count <= 1) UNBIND(y__V179);
      Term sub__V180 = LINK(sink__V159->context, SUB(sub__V178, 0)); int sub__V180_count = sub__V178_count*LINK_COUNT(sub__V180); permitUnusedInt(sub__V180_count);
      CRSX_CHECK_SORT(sink__V159->context, sub__V180, &sort_M_Reified_xDeclaration); /* sub__V180 = &#0-0 */
      NamedPropertyLink namedP__V181 = LINK_NamedPropertyLink(sink__V159->context, NAMED_PROPERTIES(term__V160));
      VariablePropertyLink varP__V182 = LINK_VariablePropertyLink(sink__V159->context, VARIABLE_PROPERTIES(term__V160));
      UNLINK(sink__V159->context, term__V160);
      ADD_PROPERTIES(sink__V159, LINK_NamedPropertyLink(sink__V159->context, namedP__V181), LINK_VariablePropertyLink(sink__V159->context, varP__V182));
      { START(sink__V159, _M_S_Declaration_s3);
        { if (!IS_BOUND(y__V179)) { REBIND(y__V179);
            Variable binds__V183[1] = {y__V179}; BINDS(sink__V159, 1, binds__V183);
            COPY(sink__V159, sub__V180); /* REUSED SUBSTITUTION */  }
          else { Variable b__V184 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V159->context,"b__V184");
            Variable binds__V185[1] = {b__V184}; BINDS(sink__V159, 1, binds__V185);
            {
              Term arg__V186;
              { Sink buf__V187 = ALLOCA_BUFFER(sink__V159->context);
                USE(buf__V187, b__V184); arg__V186 = BUFFER_TERM(buf__V187); FREE_BUFFER(buf__V187); }
              Variable vars__V188[1] = {y__V179};
              Term args__V189[1] = {arg__V186};
              struct _SubstitutionFrame substitution__V190 = {NULL, 0, 1, vars__V188, args__V189, NULL};
              SUBSTITUTE(sink__V159, sub__V180, &substitution__V190); }
                }
           }
        END(sink__V159, _M_S_Declaration_s3); }
      UNLINK_NamedPropertyLink(sink__V159->context, namedP__V181); UNLINK_VariablePropertyLink(sink__V159->context, varP__V182);
      
      return 1;
    } default: break;
  }
  return 0;
}

#ifdef __cplusplus
}
#endif
/* END OF C RULES FOR CRSX CRSXC MODULE SORTS. */
