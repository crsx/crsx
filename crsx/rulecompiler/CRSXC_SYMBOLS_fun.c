/* C RULES FOR CRSX CRSXC MODULE SYMBOLS. */
#include "CRSXC.h" 
#ifdef __cplusplus
extern "C" {
#endif

/* FUNCTION ComputeSymbols$1. */
int conBindOffs_M_ComputeSymbols_s1[] = {0 , 0 , 0};
char *nameFun_M_ComputeSymbols_s1(Term term) { return  "ComputeSymbols$1" ; }
struct _ConstructionDescriptor descriptor_M_ComputeSymbols_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_ComputeSymbols_s1), conBindOffs_M_ComputeSymbols_s1, &nameFun_M_ComputeSymbols_s1, &step_M_ComputeSymbols_s1};

int step_M_ComputeSymbols_s1(Sink sink__V1, Term term__V2)
{
  int term__V2_count = LINK_COUNT(term__V2); permitUnusedInt(term__V2_count);
  do {
    /* Contraction rule SYMBOLS-ComputeSymbols-1. */
    ASSERT(sink__V1->context, !strcmp(SYMBOL(term__V2),  "ComputeSymbols$1" ));
    Term sub__V3 = LINK(sink__V1->context, SUB(term__V2, 0)); int sub__V3_count = term__V2_count*LINK_COUNT(sub__V3); permitUnusedInt(sub__V3_count);
    /* sub__V3 = &#11 */
    Term sub__V4 = LINK(sink__V1->context, SUB(term__V2, 1)); int sub__V4_count = term__V2_count*LINK_COUNT(sub__V4); permitUnusedInt(sub__V4_count);
    /* sub__V4 = &#12 */
    NamedPropertyLink namedP__V5 = LINK_NamedPropertyLink(sink__V1->context, NAMED_PROPERTIES(term__V2));
    VariablePropertyLink varP__V6 = LINK_VariablePropertyLink(sink__V1->context, VARIABLE_PROPERTIES(term__V2));
    UNLINK(sink__V1->context, term__V2);
    { START(sink__V1, _M_ComputeSymbols2);
      COPY(sink__V1, sub__V3);COPY(sink__V1, sub__V4);{ Term term__V7;
        { char *value__V8 = getenv( "MODULE" );
          if (value__V8) term__V7 = makeStringLiteral(sink__V1->context, value__V8);
          else {term__V7 = makeStringLiteral(sink__V1->context,  "" ); }
        }
        COPY(sink__V1, term__V7); /*CONSERVATIVE*/ }
      END(sink__V1, _M_ComputeSymbols2); }
    UNLINK_NamedPropertyLink(sink__V1->context, namedP__V5); UNLINK_VariablePropertyLink(sink__V1->context, varP__V6);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Declarations. */
int conBindOffs_M_X_Declarations[] = {0 , 0};
char *nameFun_M_X_Declarations(Term term) { return  "X-Declarations" ; }
struct _ConstructionDescriptor descriptor_M_X_Declarations = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_X_Declarations), conBindOffs_M_X_Declarations, &nameFun_M_X_Declarations, &step_M_X_Declarations};

int step_M_X_Declarations(Sink sink__V9, Term term__V10)
{
  int term__V10_count = LINK_COUNT(term__V10); permitUnusedInt(term__V10_count);
  Term sub__V11 = FORCE(sink__V9->context, SUB(term__V10, 0));
  EnumOf_M__sList choice__V12 = (IS_VARIABLE_USE(sub__V11) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V11));
  switch (choice__V12)
  {
    case Data_M__sCons: { /* Function SYMBOLS-X-Declarations-1$X-Declarations$$Cons case $Cons */
      ASSERT(sink__V9->context, !strcmp(SYMBOL(term__V10),  "X-Declarations" ));
      Term sub__V13 = SUB(term__V10, 0); permitUnusedTerm(sub__V13); int sub__V13_count = term__V10_count*LINK_COUNT(sub__V13); permitUnusedInt(sub__V13_count);
      ASSERT(sink__V9->context, !strcmp(SYMBOL(sub__V13),  "$Cons" ));
      Term sub__V14 = LINK(sink__V9->context, SUB(sub__V13, 0)); int sub__V14_count = sub__V13_count*LINK_COUNT(sub__V14); permitUnusedInt(sub__V14_count);
      /* sub__V14 = &#0-0 */
      Term sub__V15 = LINK(sink__V9->context, SUB(sub__V13, 1)); int sub__V15_count = sub__V13_count*LINK_COUNT(sub__V15); permitUnusedInt(sub__V15_count);
      /* sub__V15 = &#0-1 */
      NamedPropertyLink namedP__V16 = LINK_NamedPropertyLink(sink__V9->context, NAMED_PROPERTIES(term__V10));
      VariablePropertyLink varP__V17 = LINK_VariablePropertyLink(sink__V9->context, VARIABLE_PROPERTIES(term__V10));
      UNLINK(sink__V9->context, term__V10);
      ADD_PROPERTIES(sink__V9, LINK_NamedPropertyLink(sink__V9->context, namedP__V16), LINK_VariablePropertyLink(sink__V9->context, varP__V17));
      { START(sink__V9, _M_X_Declarations_s1);
        COPY(sink__V9, sub__V14);COPY(sink__V9, sub__V15);END(sink__V9, _M_X_Declarations_s1); }
      UNLINK_NamedPropertyLink(sink__V9->context, namedP__V16); UNLINK_VariablePropertyLink(sink__V9->context, varP__V17);
      
      return 1;
    break; } case Data_M__sNil: { /* Function SYMBOLS-X-Declarations-2$X-Declarations$$Nil case $Nil */
      ASSERT(sink__V9->context, !strcmp(SYMBOL(term__V10),  "X-Declarations" ));
      Term sub__V18 = SUB(term__V10, 0); permitUnusedTerm(sub__V18); int sub__V18_count = term__V10_count*LINK_COUNT(sub__V18); permitUnusedInt(sub__V18_count);
      ASSERT(sink__V9->context, !strcmp(SYMBOL(sub__V18),  "$Nil" ));
      NamedPropertyLink namedP__V19 = LINK_NamedPropertyLink(sink__V9->context, NAMED_PROPERTIES(term__V10));
      VariablePropertyLink varP__V20 = LINK_VariablePropertyLink(sink__V9->context, VARIABLE_PROPERTIES(term__V10));
      UNLINK(sink__V9->context, term__V10);
      ADD_PROPERTIES(sink__V9, LINK_NamedPropertyLink(sink__V9->context, namedP__V19), LINK_VariablePropertyLink(sink__V9->context, varP__V20));
      { START(sink__V9, _M_X_Declarations_s2);
        END(sink__V9, _M_X_Declarations_s2); }
      UNLINK_NamedPropertyLink(sink__V9->context, namedP__V19); UNLINK_VariablePropertyLink(sink__V9->context, varP__V20);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION X-Declarations$1. */
int conBindOffs_M_X_Declarations_s1[] = {0 , 0 , 0};
char *nameFun_M_X_Declarations_s1(Term term) { return  "X-Declarations$1" ; }
struct _ConstructionDescriptor descriptor_M_X_Declarations_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_X_Declarations_s1), conBindOffs_M_X_Declarations_s1, &nameFun_M_X_Declarations_s1, &step_M_X_Declarations_s1};

int step_M_X_Declarations_s1(Sink sink__V21, Term term__V22)
{
  int term__V22_count = LINK_COUNT(term__V22); permitUnusedInt(term__V22_count);
  do {
    /* Contraction rule SYMBOLS-X-Declarations-1. */
    ASSERT(sink__V21->context, !strcmp(SYMBOL(term__V22),  "X-Declarations$1" ));
    Term sub__V23 = LINK(sink__V21->context, SUB(term__V22, 0)); int sub__V23_count = term__V22_count*LINK_COUNT(sub__V23); permitUnusedInt(sub__V23_count);
    /* sub__V23 = &#11 */
    Term sub__V24 = LINK(sink__V21->context, SUB(term__V22, 1)); int sub__V24_count = term__V22_count*LINK_COUNT(sub__V24); permitUnusedInt(sub__V24_count);
    /* sub__V24 = &#12 */
    NamedPropertyLink namedP__V25 = LINK_NamedPropertyLink(sink__V21->context, NAMED_PROPERTIES(term__V22));
    VariablePropertyLink varP__V26 = LINK_VariablePropertyLink(sink__V21->context, VARIABLE_PROPERTIES(term__V22));
    UNLINK(sink__V21->context, term__V22);
    { START(sink__V21, _M__sTextCons);
      { START(sink__V21, _M__sTextEmbed);
        { START(sink__V21, _M_AsText);
          { START(sink__V21, _M_X_Declaration);
            COPY(sink__V21, sub__V23);END(sink__V21, _M_X_Declaration); }
          END(sink__V21, _M_AsText); }
        END(sink__V21, _M__sTextEmbed); }
      { START(sink__V21, _M__sTextCons);
        { START(sink__V21, _M__sTextEmbed);
          { START(sink__V21, _M_AsText);
            { START(sink__V21, _M_X_Declarations);
              COPY(sink__V21, sub__V24);END(sink__V21, _M_X_Declarations); }
            END(sink__V21, _M_AsText); }
          END(sink__V21, _M__sTextEmbed); }
        { START(sink__V21, _M__sTextNil);
          END(sink__V21, _M__sTextNil); }
        END(sink__V21, _M__sTextCons); }
      END(sink__V21, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V21->context, namedP__V25); UNLINK_VariablePropertyLink(sink__V21->context, varP__V26);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Declarations$2. */
int conBindOffs_M_X_Declarations_s2[] = {0};
char *nameFun_M_X_Declarations_s2(Term term) { return  "X-Declarations$2" ; }
struct _ConstructionDescriptor descriptor_M_X_Declarations_s2 = {&sort_M_Reified_xVariable, 0, 0, sizeof(STRUCT_Con_M_X_Declarations_s2), conBindOffs_M_X_Declarations_s2, &nameFun_M_X_Declarations_s2, &step_M_X_Declarations_s2};

int step_M_X_Declarations_s2(Sink sink__V27, Term term__V28)
{
  int term__V28_count = LINK_COUNT(term__V28); permitUnusedInt(term__V28_count);
  do {
    /* Contraction rule SYMBOLS-X-Declarations-2. */
    ASSERT(sink__V27->context, !strcmp(SYMBOL(term__V28),  "X-Declarations$2" ));
    NamedPropertyLink namedP__V29 = LINK_NamedPropertyLink(sink__V27->context, NAMED_PROPERTIES(term__V28));
    VariablePropertyLink varP__V30 = LINK_VariablePropertyLink(sink__V27->context, VARIABLE_PROPERTIES(term__V28));
    UNLINK(sink__V27->context, term__V28);
    { START(sink__V27, _M__sTextNil); END(sink__V27, _M__sTextNil); } UNLINK_NamedPropertyLink(sink__V27->context, namedP__V29); UNLINK_VariablePropertyLink(sink__V27->context, varP__V30);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Form$2. */
int conBindOffs_M_X_Form_s2[] = {0 , 0 , 0};
char *nameFun_M_X_Form_s2(Term term) { return  "X-Form$2" ; }
struct _ConstructionDescriptor descriptor_M_X_Form_s2 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_X_Form_s2), conBindOffs_M_X_Form_s2, &nameFun_M_X_Form_s2, &step_M_X_Form_s2};

int step_M_X_Form_s2(Sink sink__V31, Term term__V32)
{
  int term__V32_count = LINK_COUNT(term__V32); permitUnusedInt(term__V32_count);
  Term sub__V33 = FORCE(sink__V31->context, SUB(term__V32, 0));
  EnumOf_M__sList choice__V34 = (IS_VARIABLE_USE(sub__V33) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V33));
  switch (choice__V34)
  {
    case Data_M__sNil: { /* Function SYMBOLS-X-Form-3$X-Form$2$$Nil case $Nil */
      ASSERT(sink__V31->context, !strcmp(SYMBOL(term__V32),  "X-Form$2" ));
      Term sub__V35 = SUB(term__V32, 0); permitUnusedTerm(sub__V35); int sub__V35_count = term__V32_count*LINK_COUNT(sub__V35); permitUnusedInt(sub__V35_count);
      ASSERT(sink__V31->context, !strcmp(SYMBOL(sub__V35),  "$Nil" ));
      Term sub__V36 = LINK(sink__V31->context, SUB(term__V32, 1)); int sub__V36_count = term__V32_count*LINK_COUNT(sub__V36); permitUnusedInt(sub__V36_count);
      /* sub__V36 = &#0 */
      NamedPropertyLink namedP__V37 = LINK_NamedPropertyLink(sink__V31->context, NAMED_PROPERTIES(term__V32));
      VariablePropertyLink varP__V38 = LINK_VariablePropertyLink(sink__V31->context, VARIABLE_PROPERTIES(term__V32));
      UNLINK(sink__V31->context, term__V32);
      ADD_PROPERTIES(sink__V31, LINK_NamedPropertyLink(sink__V31->context, namedP__V37), LINK_VariablePropertyLink(sink__V31->context, varP__V38));
      { START(sink__V31, _M_X_Form_s4);
        COPY(sink__V31, sub__V36);END(sink__V31, _M_X_Form_s4); }
      UNLINK_NamedPropertyLink(sink__V31->context, namedP__V37); UNLINK_VariablePropertyLink(sink__V31->context, varP__V38);
      
      return 1;
    break; } case Data_M__sCons: { /* Function SYMBOLS-X-Form-4$X-Form$2$$Cons case $Cons */
      ASSERT(sink__V31->context, !strcmp(SYMBOL(term__V32),  "X-Form$2" ));
      Term sub__V39 = SUB(term__V32, 0); permitUnusedTerm(sub__V39); int sub__V39_count = term__V32_count*LINK_COUNT(sub__V39); permitUnusedInt(sub__V39_count);
      ASSERT(sink__V31->context, !strcmp(SYMBOL(sub__V39),  "$Cons" ));
      Term sub__V40 = LINK(sink__V31->context, SUB(sub__V39, 0)); int sub__V40_count = sub__V39_count*LINK_COUNT(sub__V40); permitUnusedInt(sub__V40_count);
      /* sub__V40 = &#0-0 */
      Term sub__V41 = LINK(sink__V31->context, SUB(sub__V39, 1)); int sub__V41_count = sub__V39_count*LINK_COUNT(sub__V41); permitUnusedInt(sub__V41_count);
      /* sub__V41 = &#0-1 */
      Term sub__V42 = LINK(sink__V31->context, SUB(term__V32, 1)); int sub__V42_count = term__V32_count*LINK_COUNT(sub__V42); permitUnusedInt(sub__V42_count);
      /* sub__V42 = &#2 */
      NamedPropertyLink namedP__V43 = LINK_NamedPropertyLink(sink__V31->context, NAMED_PROPERTIES(term__V32));
      VariablePropertyLink varP__V44 = LINK_VariablePropertyLink(sink__V31->context, VARIABLE_PROPERTIES(term__V32));
      UNLINK(sink__V31->context, term__V32);
      ADD_PROPERTIES(sink__V31, LINK_NamedPropertyLink(sink__V31->context, namedP__V43), LINK_VariablePropertyLink(sink__V31->context, varP__V44));
      { START(sink__V31, _M_X_Form_s3);
        COPY(sink__V31, sub__V40);COPY(sink__V31, sub__V41);COPY(sink__V31, sub__V42);END(sink__V31, _M_X_Form_s3); }
      UNLINK_NamedPropertyLink(sink__V31->context, namedP__V43); UNLINK_VariablePropertyLink(sink__V31->context, varP__V44);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION X-Form$3. */
int conBindOffs_M_X_Form_s3[] = {0 , 0 , 0 , 0};
char *nameFun_M_X_Form_s3(Term term) { return  "X-Form$3" ; }
struct _ConstructionDescriptor descriptor_M_X_Form_s3 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_X_Form_s3), conBindOffs_M_X_Form_s3, &nameFun_M_X_Form_s3, &step_M_X_Form_s3};

int step_M_X_Form_s3(Sink sink__V45, Term term__V46)
{
  int term__V46_count = LINK_COUNT(term__V46); permitUnusedInt(term__V46_count);
  do {
    /* Contraction rule SYMBOLS-X-Form-4. */
    ASSERT(sink__V45->context, !strcmp(SYMBOL(term__V46),  "X-Form$3" ));
    Term sub__V47 = SUB(term__V46, 0); permitUnusedTerm(sub__V47); int sub__V47_count = term__V46_count*LINK_COUNT(sub__V47); permitUnusedInt(sub__V47_count);
    /* sub__V47 = &#121 */
    Term sub__V48 = SUB(term__V46, 1); permitUnusedTerm(sub__V48); int sub__V48_count = term__V46_count*LINK_COUNT(sub__V48); permitUnusedInt(sub__V48_count);
    /* sub__V48 = &#122 */
    Term sub__V49 = LINK(sink__V45->context, SUB(term__V46, 2)); int sub__V49_count = term__V46_count*LINK_COUNT(sub__V49); permitUnusedInt(sub__V49_count);
    UNLINK_SUB(sink__V45->context, term__V46,  2); NORMALIZE(sink__V45->context, sub__V49); SUB(term__V46,  2) = LINK(sink__V45->context, sub__V49);
    /* sub__V49 = &#11 */
    NamedPropertyLink namedP__V50 = LINK_NamedPropertyLink(sink__V45->context, NAMED_PROPERTIES(term__V46));
    VariablePropertyLink varP__V51 = LINK_VariablePropertyLink(sink__V45->context, VARIABLE_PROPERTIES(term__V46));
    UNLINK(sink__V45->context, term__V46);
    { START(sink__V45, _M__sTextCons);
      { START(sink__V45, _M__sTextBreak);
        LITERAL(sink__V45,  "\n" ); END(sink__V45, _M__sTextBreak); }
      { START(sink__V45, _M__sTextCons);
        { START(sink__V45, _M__sTextChars);
          LITERAL(sink__V45,  "{" ); END(sink__V45, _M__sTextChars); }
        { START(sink__V45, _M__sTextCons);
          { START(sink__V45, _M__sTextEmbed);
            { START(sink__V45, _M_AsText);
              { START(sink__V45, _M_STRING);
                COPY(sink__V45, LINK(sink__V45->context, sub__V49));END(sink__V45, _M_STRING); }
              END(sink__V45, _M_AsText); }
            END(sink__V45, _M__sTextEmbed); }
          { START(sink__V45, _M__sTextCons);
            { START(sink__V45, _M__sTextChars);
              LITERAL(sink__V45,  ", &" ); END(sink__V45, _M__sTextChars); }
            { START(sink__V45, _M__sTextCons);
              { START(sink__V45, _M__sTextEmbed);
                { START(sink__V45, _M_AsText);
                  { START(sink__V45, _M_Descriptor);
                    COPY(sink__V45, sub__V49);END(sink__V45, _M_Descriptor); }
                  END(sink__V45, _M_AsText); }
                END(sink__V45, _M__sTextEmbed); }
              { START(sink__V45, _M__sTextCons);
                { START(sink__V45, _M__sTextChars);
                  LITERAL(sink__V45,  "}," ); END(sink__V45, _M__sTextChars); }
                { START(sink__V45, _M__sTextNil);
                  END(sink__V45, _M__sTextNil); }
                END(sink__V45, _M__sTextCons); }
              END(sink__V45, _M__sTextCons); }
            END(sink__V45, _M__sTextCons); }
          END(sink__V45, _M__sTextCons); }
        END(sink__V45, _M__sTextCons); }
      END(sink__V45, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V45->context, namedP__V50); UNLINK_VariablePropertyLink(sink__V45->context, varP__V51);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Form$4. */
int conBindOffs_M_X_Form_s4[] = {0 , 0};
char *nameFun_M_X_Form_s4(Term term) { return  "X-Form$4" ; }
struct _ConstructionDescriptor descriptor_M_X_Form_s4 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_X_Form_s4), conBindOffs_M_X_Form_s4, &nameFun_M_X_Form_s4, &step_M_X_Form_s4};

int step_M_X_Form_s4(Sink sink__V52, Term term__V53)
{
  int term__V53_count = LINK_COUNT(term__V53); permitUnusedInt(term__V53_count);
  do {
    /* Contraction rule SYMBOLS-X-Form-3. */
    ASSERT(sink__V52->context, !strcmp(SYMBOL(term__V53),  "X-Form$4" ));
    Term sub__V54 = LINK(sink__V52->context, SUB(term__V53, 0)); int sub__V54_count = term__V53_count*LINK_COUNT(sub__V54); permitUnusedInt(sub__V54_count);
    UNLINK_SUB(sink__V52->context, term__V53,  0); NORMALIZE(sink__V52->context, sub__V54); SUB(term__V53,  0) = LINK(sink__V52->context, sub__V54);
    /* sub__V54 = &#11 */
    NamedPropertyLink namedP__V55 = LINK_NamedPropertyLink(sink__V52->context, NAMED_PROPERTIES(term__V53));
    VariablePropertyLink varP__V56 = LINK_VariablePropertyLink(sink__V52->context, VARIABLE_PROPERTIES(term__V53));
    UNLINK(sink__V52->context, term__V53);
    { START(sink__V52, _M__sTextCons);
      { START(sink__V52, _M__sTextBreak);
        LITERAL(sink__V52,  "\n" ); END(sink__V52, _M__sTextBreak); }
      { START(sink__V52, _M__sTextCons);
        { START(sink__V52, _M__sTextChars);
          LITERAL(sink__V52,  "{" ); END(sink__V52, _M__sTextChars); }
        { START(sink__V52, _M__sTextCons);
          { START(sink__V52, _M__sTextEmbed);
            { START(sink__V52, _M_AsText);
              { START(sink__V52, _M_STRING);
                COPY(sink__V52, LINK(sink__V52->context, sub__V54));END(sink__V52, _M_STRING); }
              END(sink__V52, _M_AsText); }
            END(sink__V52, _M__sTextEmbed); }
          { START(sink__V52, _M__sTextCons);
            { START(sink__V52, _M__sTextChars);
              LITERAL(sink__V52,  ", &" ); END(sink__V52, _M__sTextChars); }
            { START(sink__V52, _M__sTextCons);
              { START(sink__V52, _M__sTextEmbed);
                { START(sink__V52, _M_AsText);
                  { START(sink__V52, _M_Descriptor);
                    COPY(sink__V52, sub__V54);END(sink__V52, _M_Descriptor); }
                  END(sink__V52, _M_AsText); }
                END(sink__V52, _M__sTextEmbed); }
              { START(sink__V52, _M__sTextCons);
                { START(sink__V52, _M__sTextChars);
                  LITERAL(sink__V52,  "}," ); END(sink__V52, _M__sTextChars); }
                { START(sink__V52, _M__sTextNil);
                  END(sink__V52, _M__sTextNil); }
                END(sink__V52, _M__sTextCons); }
              END(sink__V52, _M__sTextCons); }
            END(sink__V52, _M__sTextCons); }
          END(sink__V52, _M__sTextCons); }
        END(sink__V52, _M__sTextCons); }
      END(sink__V52, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V52->context, namedP__V55); UNLINK_VariablePropertyLink(sink__V52->context, varP__V56);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Form$5. */
int conBindOffs_M_X_Form_s5[] = {0};
char *nameFun_M_X_Form_s5(Term term) { return  "X-Form$5" ; }
struct _ConstructionDescriptor descriptor_M_X_Form_s5 = {&sort_M_Reified_xVariable, 0, 0, sizeof(STRUCT_Con_M_X_Form_s5), conBindOffs_M_X_Form_s5, &nameFun_M_X_Form_s5, &step_M_X_Form_s5};

int step_M_X_Form_s5(Sink sink__V57, Term term__V58)
{
  int term__V58_count = LINK_COUNT(term__V58); permitUnusedInt(term__V58_count);
  do {
    /* Contraction rule SYMBOLS-X-Form-2. */
    ASSERT(sink__V57->context, !strcmp(SYMBOL(term__V58),  "X-Form$5" ));
    NamedPropertyLink namedP__V59 = LINK_NamedPropertyLink(sink__V57->context, NAMED_PROPERTIES(term__V58));
    VariablePropertyLink varP__V60 = LINK_VariablePropertyLink(sink__V57->context, VARIABLE_PROPERTIES(term__V58));
    UNLINK(sink__V57->context, term__V58);
    { START(sink__V57, _M__sTextNil); END(sink__V57, _M__sTextNil); } UNLINK_NamedPropertyLink(sink__V57->context, namedP__V59); UNLINK_VariablePropertyLink(sink__V57->context, varP__V60);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Form$6. */
int conBindOffs_M_X_Form_s6[] = {0 , 0 , 0 , 0};
char *nameFun_M_X_Form_s6(Term term) { return  "X-Form$6" ; }
struct _ConstructionDescriptor descriptor_M_X_Form_s6 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_X_Form_s6), conBindOffs_M_X_Form_s6, &nameFun_M_X_Form_s6, &step_M_X_Form_s6};

int step_M_X_Form_s6(Sink sink__V61, Term term__V62)
{
  int term__V62_count = LINK_COUNT(term__V62); permitUnusedInt(term__V62_count);
  do {
    /* Contraction rule SYMBOLS-X-Form-1. */
    ASSERT(sink__V61->context, !strcmp(SYMBOL(term__V62),  "X-Form$6" ));
    Term sub__V63 = SUB(term__V62, 0); permitUnusedTerm(sub__V63); int sub__V63_count = term__V62_count*LINK_COUNT(sub__V63); permitUnusedInt(sub__V63_count);
    CRSX_CHECK_SORT(sink__V61->context, sub__V63, &sort_M_Reified_xSort); /* sub__V63 = &#11 */
    Term sub__V64 = SUB(term__V62, 1); permitUnusedTerm(sub__V64); int sub__V64_count = term__V62_count*LINK_COUNT(sub__V64); permitUnusedInt(sub__V64_count);
    CRSX_CHECK_SORT(sink__V61->context, sub__V64, &sort_M_Reified_xSort); /* sub__V64 = &#12 */
    Term sub__V65 = LINK(sink__V61->context, SUB(term__V62, 2)); int sub__V65_count = term__V62_count*LINK_COUNT(sub__V65); permitUnusedInt(sub__V65_count);
    CRSX_CHECK_SORT(sink__V61->context, sub__V65, &sort_M_Reified_xForm); /* sub__V65 = &#13 */
    NamedPropertyLink namedP__V66 = LINK_NamedPropertyLink(sink__V61->context, NAMED_PROPERTIES(term__V62));
    VariablePropertyLink varP__V67 = LINK_VariablePropertyLink(sink__V61->context, VARIABLE_PROPERTIES(term__V62));
    UNLINK(sink__V61->context, term__V62);
    { START(sink__V61, _M_X_Form);
      COPY(sink__V61, sub__V65);END(sink__V61, _M_X_Form); }
    UNLINK_NamedPropertyLink(sink__V61->context, namedP__V66); UNLINK_VariablePropertyLink(sink__V61->context, varP__V67);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Data$1. */
int conBindOffs_M_X_Data_s1[] = {0 , 0 , 0 , 0};
char *nameFun_M_X_Data_s1(Term term) { return  "X-Data$1" ; }
struct _ConstructionDescriptor descriptor_M_X_Data_s1 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_X_Data_s1), conBindOffs_M_X_Data_s1, &nameFun_M_X_Data_s1, &step_M_X_Data_s1};

int step_M_X_Data_s1(Sink sink__V68, Term term__V69)
{
  int term__V69_count = LINK_COUNT(term__V69); permitUnusedInt(term__V69_count);
  do {
    /* Contraction rule SYMBOLS-X-Data-1. */
    ASSERT(sink__V68->context, !strcmp(SYMBOL(term__V69),  "X-Data$1" ));
    Term sub__V70 = SUB(term__V69, 0); permitUnusedTerm(sub__V70); int sub__V70_count = term__V69_count*LINK_COUNT(sub__V70); permitUnusedInt(sub__V70_count);
    /* sub__V70 = &#11 */
    Term sub__V71 = SUB(term__V69, 1); permitUnusedTerm(sub__V71); int sub__V71_count = term__V69_count*LINK_COUNT(sub__V71); permitUnusedInt(sub__V71_count);
    /* sub__V71 = &#12 */
    Term sub__V72 = LINK(sink__V68->context, SUB(term__V69, 2)); int sub__V72_count = term__V69_count*LINK_COUNT(sub__V72); permitUnusedInt(sub__V72_count);
    /* sub__V72 = &#2 */
    NamedPropertyLink namedP__V73 = LINK_NamedPropertyLink(sink__V68->context, NAMED_PROPERTIES(term__V69));
    VariablePropertyLink varP__V74 = LINK_VariablePropertyLink(sink__V68->context, VARIABLE_PROPERTIES(term__V69));
    UNLINK(sink__V68->context, term__V69);
    { START(sink__V68, _M__sTextCons);
      { START(sink__V68, _M__sTextEmbed);
        { START(sink__V68, _M_AsText);
          { START(sink__V68, _M_MapText_s1);
            COPY(sink__V68, sub__V72);{ Variable x__V75 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V68->context,"x__V75");
              Variable binds__V76[1] = {x__V75}; BINDS(sink__V68, 1, binds__V76);
              { START(sink__V68, _M_X_Form);
                USE(sink__V68, x__V75); END(sink__V68, _M_X_Form); }
               }
            END(sink__V68, _M_MapText_s1); }
          END(sink__V68, _M_AsText); }
        END(sink__V68, _M__sTextEmbed); }
      { START(sink__V68, _M__sTextNil); END(sink__V68, _M__sTextNil); }
      END(sink__V68, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V68->context, namedP__V73); UNLINK_VariablePropertyLink(sink__V68->context, varP__V74);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Data$2. */
int conBindOffs_M_X_Data_s2[] = {0 , 0 , 0 , 0 , 0};
char *nameFun_M_X_Data_s2(Term term) { return  "X-Data$2" ; }
struct _ConstructionDescriptor descriptor_M_X_Data_s2 = {&sort_M_Reified_xVariable, 0, 4, sizeof(STRUCT_Con_M_X_Data_s2), conBindOffs_M_X_Data_s2, &nameFun_M_X_Data_s2, &step_M_X_Data_s2};

int step_M_X_Data_s2(Sink sink__V77, Term term__V78)
{
  int term__V78_count = LINK_COUNT(term__V78); permitUnusedInt(term__V78_count);
  do {
    /* Contraction rule SYMBOLS-X-Data-2. */
    ASSERT(sink__V77->context, !strcmp(SYMBOL(term__V78),  "X-Data$2" ));
    Term sub__V79 = SUB(term__V78, 0); permitUnusedTerm(sub__V79); int sub__V79_count = term__V78_count*LINK_COUNT(sub__V79); permitUnusedInt(sub__V79_count);
    CRSX_CHECK_SORT(sink__V77->context, sub__V79, &sort_M_Reified_xSort); /* sub__V79 = &#11 */
    Term sub__V80 = SUB(term__V78, 1); permitUnusedTerm(sub__V80); int sub__V80_count = term__V78_count*LINK_COUNT(sub__V80); permitUnusedInt(sub__V80_count);
    CRSX_CHECK_SORT(sink__V77->context, sub__V80, &sort_M_Reified_xSort); /* sub__V80 = &#12 */
    Term sub__V81 = LINK(sink__V77->context, SUB(term__V78, 2)); int sub__V81_count = term__V78_count*LINK_COUNT(sub__V81); permitUnusedInt(sub__V81_count);
    CRSX_CHECK_SORT(sink__V77->context, sub__V81, &sort_M_Reified_xSort); /* sub__V81 = &#13 */
    Term sub__V82 = LINK(sink__V77->context, SUB(term__V78, 3)); int sub__V82_count = term__V78_count*LINK_COUNT(sub__V82); permitUnusedInt(sub__V82_count);
    /* sub__V82 = &#2 */
    NamedPropertyLink namedP__V83 = LINK_NamedPropertyLink(sink__V77->context, NAMED_PROPERTIES(term__V78));
    VariablePropertyLink varP__V84 = LINK_VariablePropertyLink(sink__V77->context, VARIABLE_PROPERTIES(term__V78));
    UNLINK(sink__V77->context, term__V78);
    { START(sink__V77, _M_X_Data);
      COPY(sink__V77, sub__V81);COPY(sink__V77, sub__V82);END(sink__V77, _M_X_Data); }
    UNLINK_NamedPropertyLink(sink__V77->context, namedP__V83); UNLINK_VariablePropertyLink(sink__V77->context, varP__V84);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Form. */
int conBindOffs_M_X_Form[] = {0 , 0};
char *nameFun_M_X_Form(Term term) { return  "X-Form" ; }
struct _ConstructionDescriptor descriptor_M_X_Form = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_X_Form), conBindOffs_M_X_Form, &nameFun_M_X_Form, &step_M_X_Form};

int step_M_X_Form(Sink sink__V85, Term term__V86)
{
  int term__V86_count = LINK_COUNT(term__V86); permitUnusedInt(term__V86_count);
  Term sub__V87 = FORCE(sink__V85->context, SUB(term__V86, 0));
  EnumOf_M_Reified_xForm choice__V88 = (IS_VARIABLE_USE(sub__V87) ? VarOf_M_Reified_xForm : (EnumOf_M_Reified_xForm) TAG(sub__V87));
  switch (choice__V88)
  {
    case Data_M_SORT_SET: { /* Function SYMBOLS-X-Form-1$X-Form$SORT-SET case SORT-SET */
      ASSERT(sink__V85->context, !strcmp(SYMBOL(term__V86),  "X-Form" ));
      Term sub__V89 = SUB(term__V86, 0); permitUnusedTerm(sub__V89); int sub__V89_count = term__V86_count*LINK_COUNT(sub__V89); permitUnusedInt(sub__V89_count);
      CRSX_CHECK_SORT(sink__V85->context, sub__V89, &sort_M_Reified_xForm); ASSERT(sink__V85->context, !strcmp(SYMBOL(sub__V89),  "SORT-SET" ));
      Term sub__V90 = LINK(sink__V85->context, SUB(sub__V89, 0)); int sub__V90_count = sub__V89_count*LINK_COUNT(sub__V90); permitUnusedInt(sub__V90_count);
      CRSX_CHECK_SORT(sink__V85->context, sub__V90, &sort_M_Reified_xSort); /* sub__V90 = &#0-0 */
      Term sub__V91 = LINK(sink__V85->context, SUB(sub__V89, 1)); int sub__V91_count = sub__V89_count*LINK_COUNT(sub__V91); permitUnusedInt(sub__V91_count);
      CRSX_CHECK_SORT(sink__V85->context, sub__V91, &sort_M_Reified_xSort); /* sub__V91 = &#0-1 */
      Term sub__V92 = LINK(sink__V85->context, SUB(sub__V89, 2)); int sub__V92_count = sub__V89_count*LINK_COUNT(sub__V92); permitUnusedInt(sub__V92_count);
      CRSX_CHECK_SORT(sink__V85->context, sub__V92, &sort_M_Reified_xForm); /* sub__V92 = &#0-2 */
      NamedPropertyLink namedP__V93 = LINK_NamedPropertyLink(sink__V85->context, NAMED_PROPERTIES(term__V86));
      VariablePropertyLink varP__V94 = LINK_VariablePropertyLink(sink__V85->context, VARIABLE_PROPERTIES(term__V86));
      UNLINK(sink__V85->context, term__V86);
      ADD_PROPERTIES(sink__V85, LINK_NamedPropertyLink(sink__V85->context, namedP__V93), LINK_VariablePropertyLink(sink__V85->context, varP__V94));
      { START(sink__V85, _M_X_Form_s6);
        COPY(sink__V85, sub__V90);COPY(sink__V85, sub__V91);COPY(sink__V85, sub__V92);END(sink__V85, _M_X_Form_s6); }
      UNLINK_NamedPropertyLink(sink__V85->context, namedP__V93); UNLINK_VariablePropertyLink(sink__V85->context, varP__V94);
      
      return 1;
    break; } case Data_M_SORT_ALLOWS_VARIABLES: { /* Function SYMBOLS-X-Form-2$X-Form$SORT-ALLOWS-VARIABLES case SORT-ALLOWS-VARIABLES */
      ASSERT(sink__V85->context, !strcmp(SYMBOL(term__V86),  "X-Form" ));
      Term sub__V95 = SUB(term__V86, 0); permitUnusedTerm(sub__V95); int sub__V95_count = term__V86_count*LINK_COUNT(sub__V95); permitUnusedInt(sub__V95_count);
      CRSX_CHECK_SORT(sink__V85->context, sub__V95, &sort_M_Reified_xForm); ASSERT(sink__V85->context, !strcmp(SYMBOL(sub__V95),  "SORT-ALLOWS-VARIABLES" ));
      NamedPropertyLink namedP__V96 = LINK_NamedPropertyLink(sink__V85->context, NAMED_PROPERTIES(term__V86));
      VariablePropertyLink varP__V97 = LINK_VariablePropertyLink(sink__V85->context, VARIABLE_PROPERTIES(term__V86));
      UNLINK(sink__V85->context, term__V86);
      ADD_PROPERTIES(sink__V85, LINK_NamedPropertyLink(sink__V85->context, namedP__V96), LINK_VariablePropertyLink(sink__V85->context, varP__V97));
      { START(sink__V85, _M_X_Form_s5); END(sink__V85, _M_X_Form_s5); }
      UNLINK_NamedPropertyLink(sink__V85->context, namedP__V96); UNLINK_VariablePropertyLink(sink__V85->context, varP__V97);
      
      return 1;
    break; } case Data_M_FORM: { /* Function SYMBOLS-X-Form-3$X-Form$FORM case FORM */
      ASSERT(sink__V85->context, !strcmp(SYMBOL(term__V86),  "X-Form" ));
      Term sub__V98 = SUB(term__V86, 0); permitUnusedTerm(sub__V98); int sub__V98_count = term__V86_count*LINK_COUNT(sub__V98); permitUnusedInt(sub__V98_count);
      CRSX_CHECK_SORT(sink__V85->context, sub__V98, &sort_M_Reified_xForm); ASSERT(sink__V85->context, !strcmp(SYMBOL(sub__V98),  "FORM" ));
      Term sub__V99 = LINK(sink__V85->context, SUB(sub__V98, 0)); int sub__V99_count = sub__V98_count*LINK_COUNT(sub__V99); permitUnusedInt(sub__V99_count);
      /* sub__V99 = &#0-0 */
      Term sub__V100 = LINK(sink__V85->context, SUB(sub__V98, 1)); int sub__V100_count = sub__V98_count*LINK_COUNT(sub__V100); permitUnusedInt(sub__V100_count);
      /* sub__V100 = &#0-1 */
      NamedPropertyLink namedP__V101 = LINK_NamedPropertyLink(sink__V85->context, NAMED_PROPERTIES(term__V86));
      VariablePropertyLink varP__V102 = LINK_VariablePropertyLink(sink__V85->context, VARIABLE_PROPERTIES(term__V86));
      UNLINK(sink__V85->context, term__V86);
      ADD_PROPERTIES(sink__V85, LINK_NamedPropertyLink(sink__V85->context, namedP__V101), LINK_VariablePropertyLink(sink__V85->context, varP__V102));
      { START(sink__V85, _M_X_Form_s2);
        COPY(sink__V85, sub__V100);COPY(sink__V85, sub__V99);END(sink__V85, _M_X_Form_s2); }
      UNLINK_NamedPropertyLink(sink__V85->context, namedP__V101); UNLINK_VariablePropertyLink(sink__V85->context, varP__V102);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION X-Declaration$1. */
int conBindOffs_M_X_Declaration_s1[] = {0 , 0 , 0};
char *nameFun_M_X_Declaration_s1(Term term) { return  "X-Declaration$1" ; }
struct _ConstructionDescriptor descriptor_M_X_Declaration_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_X_Declaration_s1), conBindOffs_M_X_Declaration_s1, &nameFun_M_X_Declaration_s1, &step_M_X_Declaration_s1};

int step_M_X_Declaration_s1(Sink sink__V103, Term term__V104)
{
  int term__V104_count = LINK_COUNT(term__V104); permitUnusedInt(term__V104_count);
  do {
    /* Contraction rule SYMBOLS-Data. */
    ASSERT(sink__V103->context, !strcmp(SYMBOL(term__V104),  "X-Declaration$1" ));
    Term sub__V105 = LINK(sink__V103->context, SUB(term__V104, 0)); int sub__V105_count = term__V104_count*LINK_COUNT(sub__V105); permitUnusedInt(sub__V105_count);
    CRSX_CHECK_SORT(sink__V103->context, sub__V105, &sort_M_Reified_xSort); /* sub__V105 = &#11 */
    Term sub__V106 = LINK(sink__V103->context, SUB(term__V104, 1)); int sub__V106_count = term__V104_count*LINK_COUNT(sub__V106); permitUnusedInt(sub__V106_count);
    /* sub__V106 = &#12 */
    NamedPropertyLink namedP__V107 = LINK_NamedPropertyLink(sink__V103->context, NAMED_PROPERTIES(term__V104));
    VariablePropertyLink varP__V108 = LINK_VariablePropertyLink(sink__V103->context, VARIABLE_PROPERTIES(term__V104));
    UNLINK(sink__V103->context, term__V104);
    { START(sink__V103, _M_X_Data);
      COPY(sink__V103, sub__V105);COPY(sink__V103, sub__V106);END(sink__V103, _M_X_Data); }
    UNLINK_NamedPropertyLink(sink__V103->context, namedP__V107); UNLINK_VariablePropertyLink(sink__V103->context, varP__V108);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Declaration$2. */
int conBindOffs_M_X_Declaration_s2[] = {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0};
char *nameFun_M_X_Declaration_s2(Term term) { return  "X-Declaration$2" ; }
struct _ConstructionDescriptor descriptor_M_X_Declaration_s2 = {&sort_M_Reified_xVariable, 0, 7, sizeof(STRUCT_Con_M_X_Declaration_s2), conBindOffs_M_X_Declaration_s2, &nameFun_M_X_Declaration_s2, &step_M_X_Declaration_s2};

int step_M_X_Declaration_s2(Sink sink__V109, Term term__V110)
{
  int term__V110_count = LINK_COUNT(term__V110); permitUnusedInt(term__V110_count);
  do {
    /* Contraction rule SYMBOLS-Function. */
    ASSERT(sink__V109->context, !strcmp(SYMBOL(term__V110),  "X-Declaration$2" ));
    Term sub__V111 = LINK(sink__V109->context, SUB(term__V110, 0)); int sub__V111_count = term__V110_count*LINK_COUNT(sub__V111); permitUnusedInt(sub__V111_count);
    /* sub__V111 = &#11 */
    Term sub__V112 = LINK(sink__V109->context, SUB(term__V110, 1)); int sub__V112_count = term__V110_count*LINK_COUNT(sub__V112); permitUnusedInt(sub__V112_count);
    /* sub__V112 = &#12 */
    Term sub__V113 = LINK(sink__V109->context, SUB(term__V110, 2)); int sub__V113_count = term__V110_count*LINK_COUNT(sub__V113); permitUnusedInt(sub__V113_count);
    /* sub__V113 = &#13 */
    Term sub__V114 = LINK(sink__V109->context, SUB(term__V110, 3)); int sub__V114_count = term__V110_count*LINK_COUNT(sub__V114); permitUnusedInt(sub__V114_count);
    /* sub__V114 = &#14 */
    Term sub__V115 = LINK(sink__V109->context, SUB(term__V110, 4)); int sub__V115_count = term__V110_count*LINK_COUNT(sub__V115); permitUnusedInt(sub__V115_count);
    /* sub__V115 = &#15 */
    Term sub__V116 = LINK(sink__V109->context, SUB(term__V110, 5)); int sub__V116_count = term__V110_count*LINK_COUNT(sub__V116); permitUnusedInt(sub__V116_count);
    CRSX_CHECK_SORT(sink__V109->context, sub__V116, &sort_M_Reified_xSort); /* sub__V116 = &#16 */
    Term sub__V117 = LINK(sink__V109->context, SUB(term__V110, 6)); int sub__V117_count = term__V110_count*LINK_COUNT(sub__V117); permitUnusedInt(sub__V117_count);
    /* sub__V117 = &#17 */
    NamedPropertyLink namedP__V118 = LINK_NamedPropertyLink(sink__V109->context, NAMED_PROPERTIES(term__V110));
    VariablePropertyLink varP__V119 = LINK_VariablePropertyLink(sink__V109->context, VARIABLE_PROPERTIES(term__V110));
    UNLINK(sink__V109->context, term__V110);
    { START(sink__V109, _M_X_Function);
      COPY(sink__V109, sub__V111);COPY(sink__V109, sub__V112);COPY(sink__V109, sub__V113);COPY(sink__V109, sub__V114);COPY(sink__V109, sub__V115);COPY(sink__V109, sub__V116);COPY(sink__V109, sub__V117);END(sink__V109, _M_X_Function); }
    UNLINK_NamedPropertyLink(sink__V109->context, namedP__V118); UNLINK_VariablePropertyLink(sink__V109->context, varP__V119);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Declaration$3. */
int conBindOffs_M_X_Declaration_s3[] = {0 , 1};
char *nameFun_M_X_Declaration_s3(Term term) { return  "X-Declaration$3" ; }
struct _ConstructionDescriptor descriptor_M_X_Declaration_s3 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_X_Declaration_s3), conBindOffs_M_X_Declaration_s3, &nameFun_M_X_Declaration_s3, &step_M_X_Declaration_s3};

int step_M_X_Declaration_s3(Sink sink__V120, Term term__V121)
{
  int term__V121_count = LINK_COUNT(term__V121); permitUnusedInt(term__V121_count);
  do {
    /* Contraction rule SYMBOLS-Polymorphic. */
    ASSERT(sink__V120->context, !strcmp(SYMBOL(term__V121),  "X-Declaration$3" ));
    Variable x__V122 = BINDER(term__V121,0,0); if (term__V121_count <= 1) UNBIND(x__V122);
    Term sub__V123 = LINK(sink__V120->context, SUB(term__V121, 0)); int sub__V123_count = term__V121_count*LINK_COUNT(sub__V123); permitUnusedInt(sub__V123_count);
    CRSX_CHECK_SORT(sink__V120->context, sub__V123, &sort_M_Reified_xDeclaration); /* sub__V123 = &#11 */
    Variable y__V124 = x__V122; permitUnusedVariable(y__V124);
    NamedPropertyLink namedP__V125 = LINK_NamedPropertyLink(sink__V120->context, NAMED_PROPERTIES(term__V121));
    VariablePropertyLink varP__V126 = LINK_VariablePropertyLink(sink__V120->context, VARIABLE_PROPERTIES(term__V121));
    UNLINK(sink__V120->context, term__V121);
    { START(sink__V120, _M_X_Declaration);
      COPY(sink__V120, sub__V123); /* REUSED SUBSTITUTION */ END(sink__V120, _M_X_Declaration); }
    UNLINK_NamedPropertyLink(sink__V120->context, namedP__V125); UNLINK_VariablePropertyLink(sink__V120->context, varP__V126);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION ComputeSymbols2. */
int conBindOffs_M_ComputeSymbols2[] = {0 , 0 , 0 , 0};
char *nameFun_M_ComputeSymbols2(Term term) { return  "ComputeSymbols2" ; }
struct _ConstructionDescriptor descriptor_M_ComputeSymbols2 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_ComputeSymbols2), conBindOffs_M_ComputeSymbols2, &nameFun_M_ComputeSymbols2, &step_M_ComputeSymbols2};

int step_M_ComputeSymbols2(Sink sink__V127, Term term__V128)
{
  int term__V128_count = LINK_COUNT(term__V128); permitUnusedInt(term__V128_count);
  do {
    /* Contraction rule SYMBOLS-ComputeSymbols2-1. */
    ASSERT(sink__V127->context, !strcmp(SYMBOL(term__V128),  "ComputeSymbols2" ));
    Term sub__V129 = SUB(term__V128, 0); permitUnusedTerm(sub__V129); int sub__V129_count = term__V128_count*LINK_COUNT(sub__V129); permitUnusedInt(sub__V129_count);
    /* sub__V129 = &#1 */
    Term sub__V130 = LINK(sink__V127->context, SUB(term__V128, 1)); int sub__V130_count = term__V128_count*LINK_COUNT(sub__V130); permitUnusedInt(sub__V130_count);
    /* sub__V130 = &#2 */
    Term sub__V131 = SUB(term__V128, 2); permitUnusedTerm(sub__V131); int sub__V131_count = term__V128_count*LINK_COUNT(sub__V131); permitUnusedInt(sub__V131_count);
    /* sub__V131 = &#3 */
    NamedPropertyLink namedP__V132 = LINK_NamedPropertyLink(sink__V127->context, NAMED_PROPERTIES(term__V128));
    VariablePropertyLink varP__V133 = LINK_VariablePropertyLink(sink__V127->context, VARIABLE_PROPERTIES(term__V128));
    UNLINK(sink__V127->context, term__V128);
    { START(sink__V127, _M__sTextCons);
      { START(sink__V127, _M__sTextEmbed);
        { START(sink__V127, _M_AsText);
          { START(sink__V127, _M_X_Declarations);
            COPY(sink__V127, sub__V130);END(sink__V127, _M_X_Declarations); }
          END(sink__V127, _M_AsText); }
        END(sink__V127, _M__sTextEmbed); }
      { START(sink__V127, _M__sTextCons);
        { START(sink__V127, _M__sTextBreak);
          LITERAL(sink__V127,  "\n" ); END(sink__V127, _M__sTextBreak); }
        { START(sink__V127, _M__sTextNil);
          END(sink__V127, _M__sTextNil); }
        END(sink__V127, _M__sTextCons); }
      END(sink__V127, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V127->context, namedP__V132); UNLINK_VariablePropertyLink(sink__V127->context, varP__V133);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION X-Declaration. */
int conBindOffs_M_X_Declaration[] = {0 , 0};
char *nameFun_M_X_Declaration(Term term) { return  "X-Declaration" ; }
struct _ConstructionDescriptor descriptor_M_X_Declaration = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_X_Declaration), conBindOffs_M_X_Declaration, &nameFun_M_X_Declaration, &step_M_X_Declaration};

int step_M_X_Declaration(Sink sink__V134, Term term__V135)
{
  int term__V135_count = LINK_COUNT(term__V135); permitUnusedInt(term__V135_count);
  Term sub__V136 = FORCE(sink__V134->context, SUB(term__V135, 0));
  EnumOf_M_Reified_xDeclaration choice__V137 = (IS_VARIABLE_USE(sub__V136) ? VarOf_M_Reified_xDeclaration : (EnumOf_M_Reified_xDeclaration) TAG(sub__V136));
  switch (choice__V137)
  {
    case Data_M_DATA: { /* Function SYMBOLS-Data$X-Declaration$DATA case DATA */
      ASSERT(sink__V134->context, !strcmp(SYMBOL(term__V135),  "X-Declaration" ));
      Term sub__V138 = SUB(term__V135, 0); permitUnusedTerm(sub__V138); int sub__V138_count = term__V135_count*LINK_COUNT(sub__V138); permitUnusedInt(sub__V138_count);
      CRSX_CHECK_SORT(sink__V134->context, sub__V138, &sort_M_Reified_xDeclaration); ASSERT(sink__V134->context, !strcmp(SYMBOL(sub__V138),  "DATA" ));
      Term sub__V139 = LINK(sink__V134->context, SUB(sub__V138, 0)); int sub__V139_count = sub__V138_count*LINK_COUNT(sub__V139); permitUnusedInt(sub__V139_count);
      CRSX_CHECK_SORT(sink__V134->context, sub__V139, &sort_M_Reified_xSort); /* sub__V139 = &#0-0 */
      Term sub__V140 = LINK(sink__V134->context, SUB(sub__V138, 1)); int sub__V140_count = sub__V138_count*LINK_COUNT(sub__V140); permitUnusedInt(sub__V140_count);
      /* sub__V140 = &#0-1 */
      NamedPropertyLink namedP__V141 = LINK_NamedPropertyLink(sink__V134->context, NAMED_PROPERTIES(term__V135));
      VariablePropertyLink varP__V142 = LINK_VariablePropertyLink(sink__V134->context, VARIABLE_PROPERTIES(term__V135));
      UNLINK(sink__V134->context, term__V135);
      ADD_PROPERTIES(sink__V134, LINK_NamedPropertyLink(sink__V134->context, namedP__V141), LINK_VariablePropertyLink(sink__V134->context, varP__V142));
      { START(sink__V134, _M_X_Declaration_s1);
        COPY(sink__V134, sub__V139);COPY(sink__V134, sub__V140);END(sink__V134, _M_X_Declaration_s1); }
      UNLINK_NamedPropertyLink(sink__V134->context, namedP__V141); UNLINK_VariablePropertyLink(sink__V134->context, varP__V142);
      
      return 1;
    break; } case Data_M_FUNCTION: { /* Function SYMBOLS-Function$X-Declaration$FUNCTION case FUNCTION */
      ASSERT(sink__V134->context, !strcmp(SYMBOL(term__V135),  "X-Declaration" ));
      Term sub__V143 = SUB(term__V135, 0); permitUnusedTerm(sub__V143); int sub__V143_count = term__V135_count*LINK_COUNT(sub__V143); permitUnusedInt(sub__V143_count);
      CRSX_CHECK_SORT(sink__V134->context, sub__V143, &sort_M_Reified_xDeclaration); ASSERT(sink__V134->context, !strcmp(SYMBOL(sub__V143),  "FUNCTION" ));
      Term sub__V144 = LINK(sink__V134->context, SUB(sub__V143, 0)); int sub__V144_count = sub__V143_count*LINK_COUNT(sub__V144); permitUnusedInt(sub__V144_count);
      /* sub__V144 = &#0-0 */
      Term sub__V145 = LINK(sink__V134->context, SUB(sub__V143, 1)); int sub__V145_count = sub__V143_count*LINK_COUNT(sub__V145); permitUnusedInt(sub__V145_count);
      /* sub__V145 = &#0-1 */
      Term sub__V146 = LINK(sink__V134->context, SUB(sub__V143, 2)); int sub__V146_count = sub__V143_count*LINK_COUNT(sub__V146); permitUnusedInt(sub__V146_count);
      /* sub__V146 = &#0-2 */
      Term sub__V147 = LINK(sink__V134->context, SUB(sub__V143, 3)); int sub__V147_count = sub__V143_count*LINK_COUNT(sub__V147); permitUnusedInt(sub__V147_count);
      /* sub__V147 = &#0-3 */
      Term sub__V148 = LINK(sink__V134->context, SUB(sub__V143, 4)); int sub__V148_count = sub__V143_count*LINK_COUNT(sub__V148); permitUnusedInt(sub__V148_count);
      /* sub__V148 = &#0-4 */
      Term sub__V149 = LINK(sink__V134->context, SUB(sub__V143, 5)); int sub__V149_count = sub__V143_count*LINK_COUNT(sub__V149); permitUnusedInt(sub__V149_count);
      CRSX_CHECK_SORT(sink__V134->context, sub__V149, &sort_M_Reified_xSort); /* sub__V149 = &#0-5 */
      Term sub__V150 = LINK(sink__V134->context, SUB(sub__V143, 6)); int sub__V150_count = sub__V143_count*LINK_COUNT(sub__V150); permitUnusedInt(sub__V150_count);
      /* sub__V150 = &#0-6 */
      NamedPropertyLink namedP__V151 = LINK_NamedPropertyLink(sink__V134->context, NAMED_PROPERTIES(term__V135));
      VariablePropertyLink varP__V152 = LINK_VariablePropertyLink(sink__V134->context, VARIABLE_PROPERTIES(term__V135));
      UNLINK(sink__V134->context, term__V135);
      ADD_PROPERTIES(sink__V134, LINK_NamedPropertyLink(sink__V134->context, namedP__V151), LINK_VariablePropertyLink(sink__V134->context, varP__V152));
      { START(sink__V134, _M_X_Declaration_s2);
        COPY(sink__V134, sub__V144);COPY(sink__V134, sub__V145);COPY(sink__V134, sub__V146);COPY(sink__V134, sub__V147);COPY(sink__V134, sub__V148);COPY(sink__V134, sub__V149);COPY(sink__V134, sub__V150);END(sink__V134, _M_X_Declaration_s2); }
      UNLINK_NamedPropertyLink(sink__V134->context, namedP__V151); UNLINK_VariablePropertyLink(sink__V134->context, varP__V152);
      
      return 1;
    break; } case Data_M_POLYMORPHIC: { /* Function SYMBOLS-Polymorphic$X-Declaration$POLYMORPHIC case POLYMORPHIC */
      ASSERT(sink__V134->context, !strcmp(SYMBOL(term__V135),  "X-Declaration" ));
      Term sub__V153 = SUB(term__V135, 0); permitUnusedTerm(sub__V153); int sub__V153_count = term__V135_count*LINK_COUNT(sub__V153); permitUnusedInt(sub__V153_count);
      CRSX_CHECK_SORT(sink__V134->context, sub__V153, &sort_M_Reified_xDeclaration); ASSERT(sink__V134->context, !strcmp(SYMBOL(sub__V153),  "POLYMORPHIC" ));
      Variable y__V154 = BINDER(sub__V153,0,0); if (sub__V153_count <= 1) UNBIND(y__V154);
      Term sub__V155 = LINK(sink__V134->context, SUB(sub__V153, 0)); int sub__V155_count = sub__V153_count*LINK_COUNT(sub__V155); permitUnusedInt(sub__V155_count);
      CRSX_CHECK_SORT(sink__V134->context, sub__V155, &sort_M_Reified_xDeclaration); /* sub__V155 = &#0-0 */
      NamedPropertyLink namedP__V156 = LINK_NamedPropertyLink(sink__V134->context, NAMED_PROPERTIES(term__V135));
      VariablePropertyLink varP__V157 = LINK_VariablePropertyLink(sink__V134->context, VARIABLE_PROPERTIES(term__V135));
      UNLINK(sink__V134->context, term__V135);
      ADD_PROPERTIES(sink__V134, LINK_NamedPropertyLink(sink__V134->context, namedP__V156), LINK_VariablePropertyLink(sink__V134->context, varP__V157));
      { START(sink__V134, _M_X_Declaration_s3);
        { if (!IS_BOUND(y__V154)) { REBIND(y__V154);
            Variable binds__V158[1] = {y__V154}; BINDS(sink__V134, 1, binds__V158);
            COPY(sink__V134, sub__V155); /* REUSED SUBSTITUTION */  }
          else { Variable b__V159 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V134->context,"b__V159");
            Variable binds__V160[1] = {b__V159}; BINDS(sink__V134, 1, binds__V160);
            {
              Term arg__V161;
              { Sink buf__V162 = ALLOCA_BUFFER(sink__V134->context);
                USE(buf__V162, b__V159); arg__V161 = BUFFER_TERM(buf__V162); FREE_BUFFER(buf__V162); }
              Variable vars__V163[1] = {y__V154};
              Term args__V164[1] = {arg__V161};
              struct _SubstitutionFrame substitution__V165 = {NULL, 0, 1, vars__V163, args__V164, NULL};
              SUBSTITUTE(sink__V134, sub__V155, &substitution__V165); }
                }
           }
        END(sink__V134, _M_X_Declaration_s3); }
      UNLINK_NamedPropertyLink(sink__V134->context, namedP__V156); UNLINK_VariablePropertyLink(sink__V134->context, varP__V157);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION X-Data. */
int conBindOffs_M_X_Data[] = {0 , 0 , 0};
char *nameFun_M_X_Data(Term term) { return  "X-Data" ; }
struct _ConstructionDescriptor descriptor_M_X_Data = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_X_Data), conBindOffs_M_X_Data, &nameFun_M_X_Data, &step_M_X_Data};

int step_M_X_Data(Sink sink__V166, Term term__V167)
{
  int term__V167_count = LINK_COUNT(term__V167); permitUnusedInt(term__V167_count);
  Term sub__V168 = FORCE(sink__V166->context, SUB(term__V167, 0));
  EnumOf_M_Reified_xSort choice__V169 = (IS_VARIABLE_USE(sub__V168) ? VarOf_M_Reified_xSort : (EnumOf_M_Reified_xSort) TAG(sub__V168));
  switch (choice__V169)
  {
    case Data_M_SORT: { /* Function SYMBOLS-X-Data-1$X-Data$SORT case SORT */
      ASSERT(sink__V166->context, !strcmp(SYMBOL(term__V167),  "X-Data" ));
      Term sub__V170 = SUB(term__V167, 0); permitUnusedTerm(sub__V170); int sub__V170_count = term__V167_count*LINK_COUNT(sub__V170); permitUnusedInt(sub__V170_count);
      CRSX_CHECK_SORT(sink__V166->context, sub__V170, &sort_M_Reified_xSort); ASSERT(sink__V166->context, !strcmp(SYMBOL(sub__V170),  "SORT" ));
      Term sub__V171 = LINK(sink__V166->context, SUB(sub__V170, 0)); int sub__V171_count = sub__V170_count*LINK_COUNT(sub__V171); permitUnusedInt(sub__V171_count);
      /* sub__V171 = &#0-0 */
      Term sub__V172 = LINK(sink__V166->context, SUB(sub__V170, 1)); int sub__V172_count = sub__V170_count*LINK_COUNT(sub__V172); permitUnusedInt(sub__V172_count);
      /* sub__V172 = &#0-1 */
      Term sub__V173 = LINK(sink__V166->context, SUB(term__V167, 1)); int sub__V173_count = term__V167_count*LINK_COUNT(sub__V173); permitUnusedInt(sub__V173_count);
      /* sub__V173 = &#2 */
      NamedPropertyLink namedP__V174 = LINK_NamedPropertyLink(sink__V166->context, NAMED_PROPERTIES(term__V167));
      VariablePropertyLink varP__V175 = LINK_VariablePropertyLink(sink__V166->context, VARIABLE_PROPERTIES(term__V167));
      UNLINK(sink__V166->context, term__V167);
      ADD_PROPERTIES(sink__V166, LINK_NamedPropertyLink(sink__V166->context, namedP__V174), LINK_VariablePropertyLink(sink__V166->context, varP__V175));
      { START(sink__V166, _M_X_Data_s1);
        COPY(sink__V166, sub__V171);COPY(sink__V166, sub__V172);COPY(sink__V166, sub__V173);END(sink__V166, _M_X_Data_s1); }
      UNLINK_NamedPropertyLink(sink__V166->context, namedP__V174); UNLINK_VariablePropertyLink(sink__V166->context, varP__V175);
      
      return 1;
    break; } case Data_M_SORT_PROPERTY: { /* Function SYMBOLS-X-Data-2$X-Data$SORT-PROPERTY case SORT-PROPERTY */
      ASSERT(sink__V166->context, !strcmp(SYMBOL(term__V167),  "X-Data" ));
      Term sub__V176 = SUB(term__V167, 0); permitUnusedTerm(sub__V176); int sub__V176_count = term__V167_count*LINK_COUNT(sub__V176); permitUnusedInt(sub__V176_count);
      CRSX_CHECK_SORT(sink__V166->context, sub__V176, &sort_M_Reified_xSort); ASSERT(sink__V166->context, !strcmp(SYMBOL(sub__V176),  "SORT-PROPERTY" ));
      Term sub__V177 = LINK(sink__V166->context, SUB(sub__V176, 0)); int sub__V177_count = sub__V176_count*LINK_COUNT(sub__V177); permitUnusedInt(sub__V177_count);
      CRSX_CHECK_SORT(sink__V166->context, sub__V177, &sort_M_Reified_xSort); /* sub__V177 = &#0-0 */
      Term sub__V178 = LINK(sink__V166->context, SUB(sub__V176, 1)); int sub__V178_count = sub__V176_count*LINK_COUNT(sub__V178); permitUnusedInt(sub__V178_count);
      CRSX_CHECK_SORT(sink__V166->context, sub__V178, &sort_M_Reified_xSort); /* sub__V178 = &#0-1 */
      Term sub__V179 = LINK(sink__V166->context, SUB(sub__V176, 2)); int sub__V179_count = sub__V176_count*LINK_COUNT(sub__V179); permitUnusedInt(sub__V179_count);
      CRSX_CHECK_SORT(sink__V166->context, sub__V179, &sort_M_Reified_xSort); /* sub__V179 = &#0-2 */
      Term sub__V180 = LINK(sink__V166->context, SUB(term__V167, 1)); int sub__V180_count = term__V167_count*LINK_COUNT(sub__V180); permitUnusedInt(sub__V180_count);
      /* sub__V180 = &#3 */
      NamedPropertyLink namedP__V181 = LINK_NamedPropertyLink(sink__V166->context, NAMED_PROPERTIES(term__V167));
      VariablePropertyLink varP__V182 = LINK_VariablePropertyLink(sink__V166->context, VARIABLE_PROPERTIES(term__V167));
      UNLINK(sink__V166->context, term__V167);
      ADD_PROPERTIES(sink__V166, LINK_NamedPropertyLink(sink__V166->context, namedP__V181), LINK_VariablePropertyLink(sink__V166->context, varP__V182));
      { START(sink__V166, _M_X_Data_s2);
        COPY(sink__V166, sub__V177);COPY(sink__V166, sub__V178);COPY(sink__V166, sub__V179);COPY(sink__V166, sub__V180);END(sink__V166, _M_X_Data_s2); }
      UNLINK_NamedPropertyLink(sink__V166->context, namedP__V181); UNLINK_VariablePropertyLink(sink__V166->context, varP__V182);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION ComputeSymbols. */
int conBindOffs_M_ComputeSymbols[] = {0 , 0};
char *nameFun_M_ComputeSymbols(Term term) { return  "ComputeSymbols" ; }
struct _ConstructionDescriptor descriptor_M_ComputeSymbols = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_ComputeSymbols), conBindOffs_M_ComputeSymbols, &nameFun_M_ComputeSymbols, &step_M_ComputeSymbols};

int step_M_ComputeSymbols(Sink sink__V183, Term term__V184)
{
  int term__V184_count = LINK_COUNT(term__V184); permitUnusedInt(term__V184_count);
  Term sub__V185 = FORCE(sink__V183->context, SUB(term__V184, 0));
  EnumOf_M_Reify_xCRSX choice__V186 = (IS_VARIABLE_USE(sub__V185) ? VarOf_M_Reify_xCRSX : (EnumOf_M_Reify_xCRSX) TAG(sub__V185));
  switch (choice__V186)
  {
    case Data_M_CRSX: { /* Function SYMBOLS-ComputeSymbols-1$ComputeSymbols$CRSX case CRSX */
      ASSERT(sink__V183->context, !strcmp(SYMBOL(term__V184),  "ComputeSymbols" ));
      Term sub__V187 = SUB(term__V184, 0); permitUnusedTerm(sub__V187); int sub__V187_count = term__V184_count*LINK_COUNT(sub__V187); permitUnusedInt(sub__V187_count);
      CRSX_CHECK_SORT(sink__V183->context, sub__V187, &sort_M_Reify_xCRSX); ASSERT(sink__V183->context, !strcmp(SYMBOL(sub__V187),  "CRSX" ));
      Term sub__V188 = LINK(sink__V183->context, SUB(sub__V187, 0)); int sub__V188_count = sub__V187_count*LINK_COUNT(sub__V188); permitUnusedInt(sub__V188_count);
      /* sub__V188 = &#0-0 */
      Term sub__V189 = LINK(sink__V183->context, SUB(sub__V187, 1)); int sub__V189_count = sub__V187_count*LINK_COUNT(sub__V189); permitUnusedInt(sub__V189_count);
      /* sub__V189 = &#0-1 */
      NamedPropertyLink namedP__V190 = LINK_NamedPropertyLink(sink__V183->context, NAMED_PROPERTIES(term__V184));
      VariablePropertyLink varP__V191 = LINK_VariablePropertyLink(sink__V183->context, VARIABLE_PROPERTIES(term__V184));
      UNLINK(sink__V183->context, term__V184);
      ADD_PROPERTIES(sink__V183, LINK_NamedPropertyLink(sink__V183->context, namedP__V190), LINK_VariablePropertyLink(sink__V183->context, varP__V191));
      { START(sink__V183, _M_ComputeSymbols_s1);
        COPY(sink__V183, sub__V188);COPY(sink__V183, sub__V189);END(sink__V183, _M_ComputeSymbols_s1); }
      UNLINK_NamedPropertyLink(sink__V183->context, namedP__V190); UNLINK_VariablePropertyLink(sink__V183->context, varP__V191);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION X-Function. */
int conBindOffs_M_X_Function[] = {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0};
char *nameFun_M_X_Function(Term term) { return  "X-Function" ; }
struct _ConstructionDescriptor descriptor_M_X_Function = {&sort_M_Reified_xVariable, 0, 7, sizeof(STRUCT_Con_M_X_Function), conBindOffs_M_X_Function, &nameFun_M_X_Function, &step_M_X_Function};

int step_M_X_Function(Sink sink__V192, Term term__V193)
{
  int term__V193_count = LINK_COUNT(term__V193); permitUnusedInt(term__V193_count);
  do {
    /* Contraction rule SYMBOLS-X-Function-1. */
    ASSERT(sink__V192->context, !strcmp(SYMBOL(term__V193),  "X-Function" ));
    Term sub__V194 = SUB(term__V193, 0); permitUnusedTerm(sub__V194); int sub__V194_count = term__V193_count*LINK_COUNT(sub__V194); permitUnusedInt(sub__V194_count);
    /* sub__V194 = &#1 */
    Term sub__V195 = SUB(term__V193, 1); permitUnusedTerm(sub__V195); int sub__V195_count = term__V193_count*LINK_COUNT(sub__V195); permitUnusedInt(sub__V195_count);
    /* sub__V195 = &#2 */
    Term sub__V196 = SUB(term__V193, 2); permitUnusedTerm(sub__V196); int sub__V196_count = term__V193_count*LINK_COUNT(sub__V196); permitUnusedInt(sub__V196_count);
    /* sub__V196 = &#3 */
    Term sub__V197 = SUB(term__V193, 3); permitUnusedTerm(sub__V197); int sub__V197_count = term__V193_count*LINK_COUNT(sub__V197); permitUnusedInt(sub__V197_count);
    /* sub__V197 = &#4 */
    Term sub__V198 = LINK(sink__V192->context, SUB(term__V193, 4)); int sub__V198_count = term__V193_count*LINK_COUNT(sub__V198); permitUnusedInt(sub__V198_count);
    UNLINK_SUB(sink__V192->context, term__V193,  4); NORMALIZE(sink__V192->context, sub__V198); SUB(term__V193,  4) = LINK(sink__V192->context, sub__V198);
    /* sub__V198 = &#5 */
    Term sub__V199 = SUB(term__V193, 5); permitUnusedTerm(sub__V199); int sub__V199_count = term__V193_count*LINK_COUNT(sub__V199); permitUnusedInt(sub__V199_count);
    CRSX_CHECK_SORT(sink__V192->context, sub__V199, &sort_M_Reified_xSort); /* sub__V199 = &#6 */
    Term sub__V200 = SUB(term__V193, 6); permitUnusedTerm(sub__V200); int sub__V200_count = term__V193_count*LINK_COUNT(sub__V200); permitUnusedInt(sub__V200_count);
    /* sub__V200 = &#7 */
    NamedPropertyLink namedP__V201 = LINK_NamedPropertyLink(sink__V192->context, NAMED_PROPERTIES(term__V193));
    VariablePropertyLink varP__V202 = LINK_VariablePropertyLink(sink__V192->context, VARIABLE_PROPERTIES(term__V193));
    UNLINK(sink__V192->context, term__V193);
    { START(sink__V192, _M__sTextCons);
      { START(sink__V192, _M__sTextEmbed);
        { START(sink__V192, _M_AsText);
          { START(sink__V192, _M_MapText_s1);
            COPY(sink__V192, sub__V198);{ Variable x__V203 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V192->context,"x__V203");
              Variable binds__V204[1] = {x__V203}; BINDS(sink__V192, 1, binds__V204);
              { START(sink__V192, _M_X_Form);
                USE(sink__V192, x__V203); END(sink__V192, _M_X_Form); }
               }
            END(sink__V192, _M_MapText_s1); }
          END(sink__V192, _M_AsText); }
        END(sink__V192, _M__sTextEmbed); }
      { START(sink__V192, _M__sTextNil);
        END(sink__V192, _M__sTextNil); }
      END(sink__V192, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V192->context, namedP__V201); UNLINK_VariablePropertyLink(sink__V192->context, varP__V202);
    return 1;
  } while (0);
  return 0;
}

#ifdef __cplusplus
}
#endif
/* END OF C RULES FOR CRSX CRSXC MODULE SYMBOLS. */
