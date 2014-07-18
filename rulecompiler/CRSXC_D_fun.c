/* C RULES FOR CRSX CRSXC MODULE D. */
#include "CRSXC.h" 
#ifdef __cplusplus
extern "C" {
#endif

/* FUNCTION DCOMMENT_TOKEN. */
int conBindOffs_M_DCOMMENT_xTOKEN[] = {0 , 0 , 0};
char *nameFun_M_DCOMMENT_xTOKEN(Term term) { return  "DCOMMENT_TOKEN" ; }
struct _ConstructionDescriptor descriptor_M_DCOMMENT_xTOKEN = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_DCOMMENT_xTOKEN), conBindOffs_M_DCOMMENT_xTOKEN, &nameFun_M_DCOMMENT_xTOKEN, &step_M_DCOMMENT_xTOKEN};

int step_M_DCOMMENT_xTOKEN(Sink sink__V1, Term term__V2)
{
  int term__V2_count = LINK_COUNT(term__V2); permitUnusedInt(term__V2_count);
  Term sub__V3 = FORCE(sink__V1->context, SUB(term__V2, 0));
  EnumOf_M_OK_xSORT choice__V4 = (IS_VARIABLE_USE(sub__V3) ? VarOf_M_OK_xSORT : (EnumOf_M_OK_xSORT) TAG(sub__V3));
  switch (choice__V4)
  {
    case Data_M_OK: { /* Function DEFS-DCOMMENT_TOKEN-1$DCOMMENT_TOKEN$OK case OK */
      ASSERT(sink__V1->context, !strcmp(SYMBOL(term__V2),  "DCOMMENT_TOKEN" ));
      Term sub__V5 = SUB(term__V2, 0); permitUnusedTerm(sub__V5); int sub__V5_count = term__V2_count*LINK_COUNT(sub__V5); permitUnusedInt(sub__V5_count);
      CRSX_CHECK_SORT(sink__V1->context, sub__V5, &sort_M_OK_xSORT); ASSERT(sink__V1->context, !strcmp(SYMBOL(sub__V5),  "OK" ));
      Term sub__V6 = LINK(sink__V1->context, SUB(term__V2, 1)); int sub__V6_count = term__V2_count*LINK_COUNT(sub__V6); permitUnusedInt(sub__V6_count);
      /* sub__V6 = &#0 */
      
      NamedPropertyLink namedP__V7 = LINK_NamedPropertyLink(sink__V1->context, NAMED_PROPERTIES(term__V2));
      VariablePropertyLink varP__V8 = LINK_VariablePropertyLink(sink__V1->context, VARIABLE_PROPERTIES(term__V2));
      Hashset namedFV__V9 = LINK_VARIABLESET(sink__V1->context, asConstruction(term__V2)->properties->namedFreeVars);
      Hashset varFV__V10 = LINK_VARIABLESET(sink__V1->context, asConstruction(term__V2)->properties->variableFreeVars);
      UNLINK(sink__V1->context, term__V2);
      ADD_PROPERTIES(sink__V1, LINK_VARIABLESET(sink__V1->context, namedFV__V9), LINK_VARIABLESET(sink__V1->context, varFV__V10), LINK_NamedPropertyLink(sink__V1->context, namedP__V7), LINK_VariablePropertyLink(sink__V1->context, varP__V8));
      { START(sink__V1, _M_DCOMMENT_xTOKEN_s1);
        COPY(sink__V1, sub__V6);END(sink__V1, _M_DCOMMENT_xTOKEN_s1); }
      UNLINK_VARIABLESET(sink__V1->context, namedFV__V9); UNLINK_VARIABLESET(sink__V1->context, varFV__V10);
      UNLINK_NamedPropertyLink(sink__V1->context, namedP__V7); UNLINK_VariablePropertyLink(sink__V1->context, varP__V8);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION IfZero. */
int conBindOffs_M_IfZero[] = {0 , 0 , 0 , 0};
char *nameFun_M_IfZero(Term term) { return  "IfZero" ; }
struct _ConstructionDescriptor descriptor_M_IfZero = {NULL, 0, 3, sizeof(STRUCT_Con_M_IfZero), conBindOffs_M_IfZero, &nameFun_M_IfZero, &step_M_IfZero};

int step_M_IfZero(Sink sink__V11, Term term__V12)
{
  int term__V12_count = LINK_COUNT(term__V12); permitUnusedInt(term__V12_count);
  do {
    /* Contraction rule DEFS-IfZero-1. */
    ASSERT(sink__V11->context, !strcmp(SYMBOL(term__V12),  "IfZero" ));
    Term sub__V13 = LINK(sink__V11->context, SUB(term__V12, 0)); int sub__V13_count = term__V12_count*LINK_COUNT(sub__V13); permitUnusedInt(sub__V13_count);
    UNLINK_SUB(sink__V11->context, term__V12,  0); NORMALIZE(sink__V11->context, sub__V13); SUB(term__V12,  0) = LINK(sink__V11->context, sub__V13);
    /* sub__V13 = &#1 */
    Term sub__V14 = LINK(sink__V11->context, SUB(term__V12, 1)); int sub__V14_count = term__V12_count*LINK_COUNT(sub__V14); permitUnusedInt(sub__V14_count);
    /* sub__V14 = &#2 */
    Term sub__V15 = LINK(sink__V11->context, SUB(term__V12, 2)); int sub__V15_count = term__V12_count*LINK_COUNT(sub__V15); permitUnusedInt(sub__V15_count);
    /* sub__V15 = &#3 */
    UNLINK(sink__V11->context, term__V12);
    { long long intt__V16;
      intt__V16 = LONGLONG(sub__V13); if (intt__V16 == 0ll) {  UNLINK(sink__V11->context, sub__V15); COPY(sink__V11, sub__V14); }
      else { COPY(sink__V11, sub__V15); }
    }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION MetaVar2. */
int conBindOffs_M_MetaVar2[] = {0 , 0};
char *nameFun_M_MetaVar2(Term term) { return  "MetaVar2" ; }
struct _ConstructionDescriptor descriptor_M_MetaVar2 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_MetaVar2), conBindOffs_M_MetaVar2, &nameFun_M_MetaVar2, &step_M_MetaVar2};

int step_M_MetaVar2(Sink sink__V17, Term term__V18)
{
  int term__V18_count = LINK_COUNT(term__V18); permitUnusedInt(term__V18_count);
  Term sub__V19 = FORCE(sink__V17->context, SUB(term__V18, 0));
  EnumOf_M_STRING_xENTRY choice__V20 = (IS_VARIABLE_USE(sub__V19) ? VarOf_M_STRING_xENTRY : (EnumOf_M_STRING_xENTRY) TAG(sub__V19));
  switch (choice__V20)
  {
    case Data_M_VARIABLE: { /* Function DEFS-MetaVar2-1$MetaVar2$VARIABLE case VARIABLE */
      ASSERT(sink__V17->context, !strcmp(SYMBOL(term__V18),  "MetaVar2" ));
      Term sub__V21 = SUB(term__V18, 0); permitUnusedTerm(sub__V21); int sub__V21_count = term__V18_count*LINK_COUNT(sub__V21); permitUnusedInt(sub__V21_count);
      CRSX_CHECK_SORT(sink__V17->context, sub__V21, &sort_M_STRING_xENTRY); ASSERT(sink__V17->context, !strcmp(SYMBOL(sub__V21),  "VARIABLE" ));
      Term sub__V22 = LINK(sink__V17->context, SUB(sub__V21, 0)); int sub__V22_count = sub__V21_count*LINK_COUNT(sub__V22); permitUnusedInt(sub__V22_count);
      CRSX_CHECK_SORT(sink__V17->context, sub__V22, &sort_M_Reified_xVariable); /* sub__V22 = &#0-0 */
      
      NamedPropertyLink namedP__V23 = LINK_NamedPropertyLink(sink__V17->context, NAMED_PROPERTIES(term__V18));
      VariablePropertyLink varP__V24 = LINK_VariablePropertyLink(sink__V17->context, VARIABLE_PROPERTIES(term__V18));
      Hashset namedFV__V25 = LINK_VARIABLESET(sink__V17->context, asConstruction(term__V18)->properties->namedFreeVars);
      Hashset varFV__V26 = LINK_VARIABLESET(sink__V17->context, asConstruction(term__V18)->properties->variableFreeVars);
      UNLINK(sink__V17->context, term__V18);
      ADD_PROPERTIES(sink__V17, LINK_VARIABLESET(sink__V17->context, namedFV__V25), LINK_VARIABLESET(sink__V17->context, varFV__V26), LINK_NamedPropertyLink(sink__V17->context, namedP__V23), LINK_VariablePropertyLink(sink__V17->context, varP__V24));
      { START(sink__V17, _M_MetaVar2_s2);
        COPY(sink__V17, sub__V22);END(sink__V17, _M_MetaVar2_s2); }
      UNLINK_VARIABLESET(sink__V17->context, namedFV__V25); UNLINK_VARIABLESET(sink__V17->context, varFV__V26);
      UNLINK_NamedPropertyLink(sink__V17->context, namedP__V23); UNLINK_VariablePropertyLink(sink__V17->context, varP__V24);
      
      return 1;
    break; } case Data_M_STRING_xVALUE: { /* Function DEFS-MetaVar2-2$MetaVar2$STRING_VALUE case STRING_VALUE */
      ASSERT(sink__V17->context, !strcmp(SYMBOL(term__V18),  "MetaVar2" ));
      Term sub__V27 = SUB(term__V18, 0); permitUnusedTerm(sub__V27); int sub__V27_count = term__V18_count*LINK_COUNT(sub__V27); permitUnusedInt(sub__V27_count);
      CRSX_CHECK_SORT(sink__V17->context, sub__V27, &sort_M_STRING_xENTRY); ASSERT(sink__V17->context, !strcmp(SYMBOL(sub__V27),  "STRING_VALUE" ));
      Term sub__V28 = LINK(sink__V17->context, SUB(sub__V27, 0)); int sub__V28_count = sub__V27_count*LINK_COUNT(sub__V28); permitUnusedInt(sub__V28_count);
      /* sub__V28 = &#0-0 */
      
      NamedPropertyLink namedP__V29 = LINK_NamedPropertyLink(sink__V17->context, NAMED_PROPERTIES(term__V18));
      VariablePropertyLink varP__V30 = LINK_VariablePropertyLink(sink__V17->context, VARIABLE_PROPERTIES(term__V18));
      Hashset namedFV__V31 = LINK_VARIABLESET(sink__V17->context, asConstruction(term__V18)->properties->namedFreeVars);
      Hashset varFV__V32 = LINK_VARIABLESET(sink__V17->context, asConstruction(term__V18)->properties->variableFreeVars);
      UNLINK(sink__V17->context, term__V18);
      ADD_PROPERTIES(sink__V17, LINK_VARIABLESET(sink__V17->context, namedFV__V31), LINK_VARIABLESET(sink__V17->context, varFV__V32), LINK_NamedPropertyLink(sink__V17->context, namedP__V29), LINK_VariablePropertyLink(sink__V17->context, varP__V30));
      { START(sink__V17, _M_MetaVar2_s1);
        COPY(sink__V17, sub__V28);END(sink__V17, _M_MetaVar2_s1); }
      UNLINK_VARIABLESET(sink__V17->context, namedFV__V31); UNLINK_VARIABLESET(sink__V17->context, varFV__V32);
      UNLINK_NamedPropertyLink(sink__V17->context, namedP__V29); UNLINK_VariablePropertyLink(sink__V17->context, varP__V30);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION COMMENT_TOKEN. */
int conBindOffs_M_COMMENT_xTOKEN[] = {0 , 0};
char *nameFun_M_COMMENT_xTOKEN(Term term) { return  "COMMENT_TOKEN" ; }
struct _ConstructionDescriptor descriptor_M_COMMENT_xTOKEN = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_COMMENT_xTOKEN), conBindOffs_M_COMMENT_xTOKEN, &nameFun_M_COMMENT_xTOKEN, &step_M_COMMENT_xTOKEN};

int step_M_COMMENT_xTOKEN(Sink sink__V33, Term term__V34)
{
  int term__V34_count = LINK_COUNT(term__V34); permitUnusedInt(term__V34_count);
  do {
    /* Contraction rule DEFS-COMMENT_TOKEN-1. */
    ASSERT(sink__V33->context, !strcmp(SYMBOL(term__V34),  "COMMENT_TOKEN" ));
    Term sub__V35 = LINK(sink__V33->context, SUB(term__V34, 0)); int sub__V35_count = term__V34_count*LINK_COUNT(sub__V35); permitUnusedInt(sub__V35_count);
    UNLINK_SUB(sink__V33->context, term__V34,  0); NORMALIZE(sink__V33->context, sub__V35); SUB(term__V34,  0) = LINK(sink__V33->context, sub__V35);
    /* sub__V35 = &#1 */
    
    NamedPropertyLink namedP__V36 = LINK_NamedPropertyLink(sink__V33->context, NAMED_PROPERTIES(term__V34));
    VariablePropertyLink varP__V37 = LINK_VariablePropertyLink(sink__V33->context, VARIABLE_PROPERTIES(term__V34));
    Hashset namedFV__V38 = LINK_VARIABLESET(sink__V33->context, asConstruction(term__V34)->properties->namedFreeVars);
    Hashset varFV__V39 = LINK_VARIABLESET(sink__V33->context, asConstruction(term__V34)->properties->variableFreeVars);
    UNLINK(sink__V33->context, term__V34);
    { START(sink__V33, _M__sTextCons);
      { START(sink__V33, _M__sTextChars);
        { char *str__V40;
          FORCE(sink__V33->context, sub__V35); LINK(sink__V33->context, sub__V35);
          { char *replaced__V41;
            const size_t z = strlen(SYMBOL(sub__V35));
            if (* "*/" ) {
              const size_t oldz = strlen( "*/" ), newz = strlen( "*_/" );
              size_t limitz;
              if (oldz==newz) { limitz = z; }
              else { limitz = z; size_t growz = (oldz < newz ? newz - oldz : 0);
                if (growz > 0) { char *p = SYMBOL(sub__V35); while ((p = strstr(p,  "*/" ))) { limitz += growz; p += oldz; } } }
              replaced__V41 = ALLOCA(sink__V33->context, limitz+1);
              if (oldz==newz) { memcpy(replaced__V41, SYMBOL(sub__V35), z+1);
                char *r = replaced__V41; while ((r = strstr(r,  "*/" ))) { memcpy(r,  "*_/" , newz); r += oldz; } }
              else { char *s = SYMBOL(sub__V35), *ends = s+z, *r = replaced__V41, *next;
                while ((next = strstr(s,  "*/" ))) { size_t prez = next-s;
                  if (prez) { memcpy(r, s, prez); r += prez; } 
                  if (newz) { memcpy(r,  "*_/" , newz); r += newz; }
                  s = next+oldz;}
                if (s < ends) { memcpy(r, s, ends-s); r += ends-s; }
                *r = '\0';}
              }
            else { replaced__V41 = memcpy(ALLOCA(sink__V33->context, z+1), SYMBOL(sub__V35), z+1); }
             UNLINK(sink__V33->context, sub__V35);  UNLINK(sink__V33->context, sub__V35); { size_t z__V42 = strlen(replaced__V41) + 1; memcpy(str__V40 = ALLOCATE(sink__V33->context, z__V42), replaced__V41, z__V42); }
            
          }LITERALU(sink__V33, str__V40); }
        END(sink__V33, _M__sTextChars); }
      { START(sink__V33, _M__sTextNil); END(sink__V33, _M__sTextNil); }
      END(sink__V33, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V33->context, namedFV__V38); UNLINK_VARIABLESET(sink__V33->context, varFV__V39);
    UNLINK_NamedPropertyLink(sink__V33->context, namedP__V36); UNLINK_VariablePropertyLink(sink__V33->context, varP__V37);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DTOKEN$1. */
int conBindOffs_M_DTOKEN_s1[] = {0 , 0};
char *nameFun_M_DTOKEN_s1(Term term) { return  "DTOKEN$1" ; }
struct _ConstructionDescriptor descriptor_M_DTOKEN_s1 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_DTOKEN_s1), conBindOffs_M_DTOKEN_s1, &nameFun_M_DTOKEN_s1, &step_M_DTOKEN_s1};

int step_M_DTOKEN_s1(Sink sink__V43, Term term__V44)
{
  int term__V44_count = LINK_COUNT(term__V44); permitUnusedInt(term__V44_count);
  do {
    /* Contraction rule DEFS-DTOKEN-1. */
    ASSERT(sink__V43->context, !strcmp(SYMBOL(term__V44),  "DTOKEN$1" ));
    Term sub__V45 = LINK(sink__V43->context, SUB(term__V44, 0)); int sub__V45_count = term__V44_count*LINK_COUNT(sub__V45); permitUnusedInt(sub__V45_count);
    UNLINK_SUB(sink__V43->context, term__V44,  0); NORMALIZE(sink__V43->context, sub__V45); SUB(term__V44,  0) = LINK(sink__V43->context, sub__V45);
    /* sub__V45 = &#2 */
    
    NamedPropertyLink namedP__V46 = LINK_NamedPropertyLink(sink__V43->context, NAMED_PROPERTIES(term__V44));
    VariablePropertyLink varP__V47 = LINK_VariablePropertyLink(sink__V43->context, VARIABLE_PROPERTIES(term__V44));
    Hashset namedFV__V48 = LINK_VARIABLESET(sink__V43->context, asConstruction(term__V44)->properties->namedFreeVars);
    Hashset varFV__V49 = LINK_VARIABLESET(sink__V43->context, asConstruction(term__V44)->properties->variableFreeVars);
    UNLINK(sink__V43->context, term__V44);
    { START(sink__V43, _M__sTextCons);
      { START(sink__V43, _M__sTextChars);
        COPY(sink__V43, sub__V45);END(sink__V43, _M__sTextChars); }
      { START(sink__V43, _M__sTextNil); END(sink__V43, _M__sTextNil); }
      END(sink__V43, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V43->context, namedFV__V48); UNLINK_VARIABLESET(sink__V43->context, varFV__V49);
    UNLINK_NamedPropertyLink(sink__V43->context, namedP__V46); UNLINK_VariablePropertyLink(sink__V43->context, varP__V47);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DSTRING$1. */
int conBindOffs_M_DSTRING_s1[] = {0 , 0};
char *nameFun_M_DSTRING_s1(Term term) { return  "DSTRING$1" ; }
struct _ConstructionDescriptor descriptor_M_DSTRING_s1 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_DSTRING_s1), conBindOffs_M_DSTRING_s1, &nameFun_M_DSTRING_s1, &step_M_DSTRING_s1};

int step_M_DSTRING_s1(Sink sink__V50, Term term__V51)
{
  int term__V51_count = LINK_COUNT(term__V51); permitUnusedInt(term__V51_count);
  do {
    /* Contraction rule DEFS-DSTRING-1. */
    ASSERT(sink__V50->context, !strcmp(SYMBOL(term__V51),  "DSTRING$1" ));
    Term sub__V52 = LINK(sink__V50->context, SUB(term__V51, 0)); int sub__V52_count = term__V51_count*LINK_COUNT(sub__V52); permitUnusedInt(sub__V52_count);
    UNLINK_SUB(sink__V50->context, term__V51,  0); NORMALIZE(sink__V50->context, sub__V52); SUB(term__V51,  0) = LINK(sink__V50->context, sub__V52);
    /* sub__V52 = &#2 */
    
    NamedPropertyLink namedP__V53 = LINK_NamedPropertyLink(sink__V50->context, NAMED_PROPERTIES(term__V51));
    VariablePropertyLink varP__V54 = LINK_VariablePropertyLink(sink__V50->context, VARIABLE_PROPERTIES(term__V51));
    Hashset namedFV__V55 = LINK_VARIABLESET(sink__V50->context, asConstruction(term__V51)->properties->namedFreeVars);
    Hashset varFV__V56 = LINK_VARIABLESET(sink__V50->context, asConstruction(term__V51)->properties->variableFreeVars);
    UNLINK(sink__V50->context, term__V51);
    { START(sink__V50, _M__sTextCons);
      { START(sink__V50, _M__sTextChars);
        LITERAL(sink__V50,  " " ); END(sink__V50, _M__sTextChars); }
      { START(sink__V50, _M__sTextCons);
        { START(sink__V50, _M__sTextString);
          { START(sink__V50, _M__sTextCons);
            { START(sink__V50, _M__sTextChars);
              { char *str__V57;
                FORCE(sink__V50->context, sub__V52); LINK(sink__V50->context, sub__V52);
                {str__V57 = makeEscaped(sink__V50->context, SYMBOL(sub__V52));
                   UNLINK(sink__V50->context, sub__V52);  UNLINK(sink__V50->context, sub__V52); }
                LITERALU(sink__V50, str__V57); }
              END(sink__V50, _M__sTextChars); }
            { START(sink__V50, _M__sTextNil);
              END(sink__V50, _M__sTextNil); }
            END(sink__V50, _M__sTextCons); }
          END(sink__V50, _M__sTextString); }
        { START(sink__V50, _M__sTextCons);
          { START(sink__V50, _M__sTextChars);
            LITERAL(sink__V50,  " " ); END(sink__V50, _M__sTextChars); }
          { START(sink__V50, _M__sTextNil);
            END(sink__V50, _M__sTextNil); }
          END(sink__V50, _M__sTextCons); }
        END(sink__V50, _M__sTextCons); }
      END(sink__V50, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V50->context, namedFV__V55); UNLINK_VARIABLESET(sink__V50->context, varFV__V56);
    UNLINK_NamedPropertyLink(sink__V50->context, namedP__V53); UNLINK_VariablePropertyLink(sink__V50->context, varP__V54);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION SplitMapText$1. */
int conBindOffs_M_SplitMapText_s1[] = {0 , 0 , 1 , 1 , 1 , 1 , 2 , 3};
char *nameFun_M_SplitMapText_s1(Term term) { return  "SplitMapText$1" ; }
struct _ConstructionDescriptor descriptor_M_SplitMapText_s1 = {&sort_M_Reified_xVariable, 0, 7, sizeof(STRUCT_Con_M_SplitMapText_s1), conBindOffs_M_SplitMapText_s1, &nameFun_M_SplitMapText_s1, &step_M_SplitMapText_s1};

int step_M_SplitMapText_s1(Sink sink__V58, Term term__V59)
{
  int term__V59_count = LINK_COUNT(term__V59); permitUnusedInt(term__V59_count);
  Term sub__V60 = FORCE(sink__V58->context, SUB(term__V59, 0));
  EnumOf_M__sList choice__V61 = (IS_VARIABLE_USE(sub__V60) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V60));
  switch (choice__V61)
  {
    case Data_M__sCons: { /* Function DEFS-SplitMapText-1$SplitMapText$1$$Cons case $Cons */
      ASSERT(sink__V58->context, !strcmp(SYMBOL(term__V59),  "SplitMapText$1" ));
      Term sub__V62 = SUB(term__V59, 0); permitUnusedTerm(sub__V62); int sub__V62_count = term__V59_count*LINK_COUNT(sub__V62); permitUnusedInt(sub__V62_count);
      ASSERT(sink__V58->context, !strcmp(SYMBOL(sub__V62),  "$Cons" ));
      Term sub__V63 = LINK(sink__V58->context, SUB(sub__V62, 0)); int sub__V63_count = sub__V62_count*LINK_COUNT(sub__V63); permitUnusedInt(sub__V63_count);
      /* sub__V63 = &#0-0 */
      Term sub__V64 = LINK(sink__V58->context, SUB(sub__V62, 1)); int sub__V64_count = sub__V62_count*LINK_COUNT(sub__V64); permitUnusedInt(sub__V64_count);
      /* sub__V64 = &#0-1 */
      Variable x__V65 = BINDER(term__V59,1,0); if (term__V59_count <= 1) UNBIND(x__V65);
      Term sub__V66 = LINK(sink__V58->context, SUB(term__V59, 1)); int sub__V66_count = term__V59_count*LINK_COUNT(sub__V66); permitUnusedInt(sub__V66_count);
      CRSX_CHECK_SORT(sink__V58->context, sub__V66, &sort_M_Reified_xVariable); /* sub__V66 = &#2 */
      Term sub__V67 = LINK(sink__V58->context, SUB(term__V59, 2)); int sub__V67_count = term__V59_count*LINK_COUNT(sub__V67); permitUnusedInt(sub__V67_count);
      /* sub__V67 = &#3 */
      Term sub__V68 = LINK(sink__V58->context, SUB(term__V59, 3)); int sub__V68_count = term__V59_count*LINK_COUNT(sub__V68); permitUnusedInt(sub__V68_count);
      /* sub__V68 = &#4 */
      Term sub__V69 = LINK(sink__V58->context, SUB(term__V59, 4)); int sub__V69_count = term__V59_count*LINK_COUNT(sub__V69); permitUnusedInt(sub__V69_count);
      /* sub__V69 = &#5 */
      Variable x__V70 = BINDER(term__V59,5,0); if (term__V59_count <= 1) UNBIND(x__V70);
      Term sub__V71 = LINK(sink__V58->context, SUB(term__V59, 5)); int sub__V71_count = term__V59_count*LINK_COUNT(sub__V71); permitUnusedInt(sub__V71_count);
      CRSX_CHECK_SORT(sink__V58->context, sub__V71, &sort_M_Reified_xVariable); /* sub__V71 = &#6 */
      Variable x__V72 = BINDER(term__V59,6,0); if (term__V59_count <= 1) UNBIND(x__V72);
      Term sub__V73 = LINK(sink__V58->context, SUB(term__V59, 6)); int sub__V73_count = term__V59_count*LINK_COUNT(sub__V73); permitUnusedInt(sub__V73_count);
      CRSX_CHECK_SORT(sink__V58->context, sub__V73, &sort_M_Reified_xVariable); /* sub__V73 = &#7 */
      
      NamedPropertyLink namedP__V74 = LINK_NamedPropertyLink(sink__V58->context, NAMED_PROPERTIES(term__V59));
      VariablePropertyLink varP__V75 = LINK_VariablePropertyLink(sink__V58->context, VARIABLE_PROPERTIES(term__V59));
      Hashset namedFV__V76 = LINK_VARIABLESET(sink__V58->context, asConstruction(term__V59)->properties->namedFreeVars);
      Hashset varFV__V77 = LINK_VARIABLESET(sink__V58->context, asConstruction(term__V59)->properties->variableFreeVars);
      UNLINK(sink__V58->context, term__V59);
      ADD_PROPERTIES(sink__V58, LINK_VARIABLESET(sink__V58->context, namedFV__V76), LINK_VARIABLESET(sink__V58->context, varFV__V77), LINK_NamedPropertyLink(sink__V58->context, namedP__V74), LINK_VariablePropertyLink(sink__V58->context, varP__V75));
      { START(sink__V58, _M_SplitMapText_s2);
        COPY(sink__V58, sub__V63);COPY(sink__V58, sub__V64);{ if (!IS_BOUND(x__V65)) { REBIND(x__V65);
            Variable binds__V78[1] = {x__V65}; BINDS(sink__V58, 1, binds__V78);
            COPY(sink__V58, sub__V66); /* REUSED SUBSTITUTION */  }
          else { Variable b__V79 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V58->context,"b__V79");
            Variable binds__V80[1] = {b__V79}; BINDS(sink__V58, 1, binds__V80);
            {
              Term arg__V81;
              { Sink buf__V82 = ALLOCA_BUFFER(sink__V58->context);
                USE(buf__V82, b__V79); arg__V81 = BUFFER_TERM(buf__V82); FREE_BUFFER(buf__V82); }
              Variable vars__V83[1] = {x__V65};
              Term args__V84[1] = {arg__V81};
              struct _SubstitutionFrame substitution__V85 = {NULL, 0, 1, vars__V83, args__V84, NULL};
              SUBSTITUTE(sink__V58, sub__V66, &substitution__V85); }
                }
           }
        COPY(sink__V58, sub__V67);COPY(sink__V58, sub__V68);COPY(sink__V58, sub__V69);{ if (!IS_BOUND(x__V70)) { REBIND(x__V70);
            Variable binds__V86[1] = {x__V70}; BINDS(sink__V58, 1, binds__V86);
            COPY(sink__V58, sub__V71); /* REUSED SUBSTITUTION */  }
          else { Variable b__V87 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V58->context,"b__V87");
            Variable binds__V88[1] = {b__V87}; BINDS(sink__V58, 1, binds__V88);
            {
              Term arg__V89;
              { Sink buf__V90 = ALLOCA_BUFFER(sink__V58->context);
                USE(buf__V90, b__V87); arg__V89 = BUFFER_TERM(buf__V90); FREE_BUFFER(buf__V90); }
              Variable vars__V91[1] = {x__V70};
              Term args__V92[1] = {arg__V89};
              struct _SubstitutionFrame substitution__V93 = {NULL, 0, 1, vars__V91, args__V92, NULL};
              SUBSTITUTE(sink__V58, sub__V71, &substitution__V93); }
                }
           }
        { if (!IS_BOUND(x__V72)) { REBIND(x__V72);
            Variable binds__V94[1] = {x__V72}; BINDS(sink__V58, 1, binds__V94);
            COPY(sink__V58, sub__V73); /* REUSED SUBSTITUTION */  }
          else { Variable b__V95 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V58->context,"b__V95");
            Variable binds__V96[1] = {b__V95}; BINDS(sink__V58, 1, binds__V96);
            {
              Term arg__V97;
              { Sink buf__V98 = ALLOCA_BUFFER(sink__V58->context);
                USE(buf__V98, b__V95); arg__V97 = BUFFER_TERM(buf__V98); FREE_BUFFER(buf__V98); }
              Variable vars__V99[1] = {x__V72};
              Term args__V100[1] = {arg__V97};
              struct _SubstitutionFrame substitution__V101 = {NULL, 0, 1, vars__V99, args__V100, NULL};
              SUBSTITUTE(sink__V58, sub__V73, &substitution__V101); }
                }
           }
        END(sink__V58, _M_SplitMapText_s2); }
      UNLINK_VARIABLESET(sink__V58->context, namedFV__V76); UNLINK_VARIABLESET(sink__V58->context, varFV__V77);
      UNLINK_NamedPropertyLink(sink__V58->context, namedP__V74); UNLINK_VariablePropertyLink(sink__V58->context, varP__V75);
      
      return 1;
    break; } case Data_M__sNil: { /* Function DEFS-SplitMapText-2$SplitMapText$1$$Nil case $Nil */
      ASSERT(sink__V58->context, !strcmp(SYMBOL(term__V59),  "SplitMapText$1" ));
      Term sub__V102 = SUB(term__V59, 0); permitUnusedTerm(sub__V102); int sub__V102_count = term__V59_count*LINK_COUNT(sub__V102); permitUnusedInt(sub__V102_count);
      ASSERT(sink__V58->context, !strcmp(SYMBOL(sub__V102),  "$Nil" ));
      Variable x__V103 = BINDER(term__V59,1,0); if (term__V59_count <= 1) UNBIND(x__V103);
      Term sub__V104 = LINK(sink__V58->context, SUB(term__V59, 1)); int sub__V104_count = term__V59_count*LINK_COUNT(sub__V104); permitUnusedInt(sub__V104_count);
      CRSX_CHECK_SORT(sink__V58->context, sub__V104, &sort_M_Reified_xVariable); /* sub__V104 = &#0 */
      Term sub__V105 = LINK(sink__V58->context, SUB(term__V59, 2)); int sub__V105_count = term__V59_count*LINK_COUNT(sub__V105); permitUnusedInt(sub__V105_count);
      /* sub__V105 = &#1 */
      Term sub__V106 = LINK(sink__V58->context, SUB(term__V59, 3)); int sub__V106_count = term__V59_count*LINK_COUNT(sub__V106); permitUnusedInt(sub__V106_count);
      /* sub__V106 = &#2 */
      Term sub__V107 = LINK(sink__V58->context, SUB(term__V59, 4)); int sub__V107_count = term__V59_count*LINK_COUNT(sub__V107); permitUnusedInt(sub__V107_count);
      /* sub__V107 = &#3 */
      Variable x__V108 = BINDER(term__V59,5,0); if (term__V59_count <= 1) UNBIND(x__V108);
      Term sub__V109 = LINK(sink__V58->context, SUB(term__V59, 5)); int sub__V109_count = term__V59_count*LINK_COUNT(sub__V109); permitUnusedInt(sub__V109_count);
      CRSX_CHECK_SORT(sink__V58->context, sub__V109, &sort_M_Reified_xVariable); /* sub__V109 = &#4 */
      Variable x__V110 = BINDER(term__V59,6,0); if (term__V59_count <= 1) UNBIND(x__V110);
      Term sub__V111 = LINK(sink__V58->context, SUB(term__V59, 6)); int sub__V111_count = term__V59_count*LINK_COUNT(sub__V111); permitUnusedInt(sub__V111_count);
      CRSX_CHECK_SORT(sink__V58->context, sub__V111, &sort_M_Reified_xVariable); /* sub__V111 = &#5 */
      
      NamedPropertyLink namedP__V112 = LINK_NamedPropertyLink(sink__V58->context, NAMED_PROPERTIES(term__V59));
      VariablePropertyLink varP__V113 = LINK_VariablePropertyLink(sink__V58->context, VARIABLE_PROPERTIES(term__V59));
      Hashset namedFV__V114 = LINK_VARIABLESET(sink__V58->context, asConstruction(term__V59)->properties->namedFreeVars);
      Hashset varFV__V115 = LINK_VARIABLESET(sink__V58->context, asConstruction(term__V59)->properties->variableFreeVars);
      UNLINK(sink__V58->context, term__V59);
      ADD_PROPERTIES(sink__V58, LINK_VARIABLESET(sink__V58->context, namedFV__V114), LINK_VARIABLESET(sink__V58->context, varFV__V115), LINK_NamedPropertyLink(sink__V58->context, namedP__V112), LINK_VariablePropertyLink(sink__V58->context, varP__V113));
      { START(sink__V58, _M_SplitMapText_s3);
        { if (!IS_BOUND(x__V103)) { REBIND(x__V103);
            Variable binds__V116[1] = {x__V103}; BINDS(sink__V58, 1, binds__V116);
            COPY(sink__V58, sub__V104); /* REUSED SUBSTITUTION */  }
          else { Variable b__V117 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V58->context,"b__V117");
            Variable binds__V118[1] = {b__V117}; BINDS(sink__V58, 1, binds__V118);
            {
              Term arg__V119;
              { Sink buf__V120 = ALLOCA_BUFFER(sink__V58->context);
                USE(buf__V120, b__V117); arg__V119 = BUFFER_TERM(buf__V120); FREE_BUFFER(buf__V120); }
              Variable vars__V121[1] = {x__V103};
              Term args__V122[1] = {arg__V119};
              struct _SubstitutionFrame substitution__V123 = {NULL, 0, 1, vars__V121, args__V122, NULL};
              SUBSTITUTE(sink__V58, sub__V104, &substitution__V123); }
                }
           }
        COPY(sink__V58, sub__V105);COPY(sink__V58, sub__V106);COPY(sink__V58, sub__V107);{ if (!IS_BOUND(x__V108)) { REBIND(x__V108);
            Variable binds__V124[1] = {x__V108}; BINDS(sink__V58, 1, binds__V124);
            COPY(sink__V58, sub__V109); /* REUSED SUBSTITUTION */  }
          else { Variable b__V125 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V58->context,"b__V125");
            Variable binds__V126[1] = {b__V125}; BINDS(sink__V58, 1, binds__V126);
            {
              Term arg__V127;
              { Sink buf__V128 = ALLOCA_BUFFER(sink__V58->context);
                USE(buf__V128, b__V125); arg__V127 = BUFFER_TERM(buf__V128); FREE_BUFFER(buf__V128); }
              Variable vars__V129[1] = {x__V108};
              Term args__V130[1] = {arg__V127};
              struct _SubstitutionFrame substitution__V131 = {NULL, 0, 1, vars__V129, args__V130, NULL};
              SUBSTITUTE(sink__V58, sub__V109, &substitution__V131); }
                }
           }
        { if (!IS_BOUND(x__V110)) { REBIND(x__V110);
            Variable binds__V132[1] = {x__V110}; BINDS(sink__V58, 1, binds__V132);
            COPY(sink__V58, sub__V111); /* REUSED SUBSTITUTION */  }
          else { Variable b__V133 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V58->context,"b__V133");
            Variable binds__V134[1] = {b__V133}; BINDS(sink__V58, 1, binds__V134);
            {
              Term arg__V135;
              { Sink buf__V136 = ALLOCA_BUFFER(sink__V58->context);
                USE(buf__V136, b__V133); arg__V135 = BUFFER_TERM(buf__V136); FREE_BUFFER(buf__V136); }
              Variable vars__V137[1] = {x__V110};
              Term args__V138[1] = {arg__V135};
              struct _SubstitutionFrame substitution__V139 = {NULL, 0, 1, vars__V137, args__V138, NULL};
              SUBSTITUTE(sink__V58, sub__V111, &substitution__V139); }
                }
           }
        END(sink__V58, _M_SplitMapText_s3); }
      UNLINK_VARIABLESET(sink__V58->context, namedFV__V114); UNLINK_VARIABLESET(sink__V58->context, varFV__V115);
      UNLINK_NamedPropertyLink(sink__V58->context, namedP__V112); UNLINK_VariablePropertyLink(sink__V58->context, varP__V113);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION SplitMapText$2. */
int conBindOffs_M_SplitMapText_s2[] = {0 , 0 , 0 , 1 , 1 , 1 , 1 , 2 , 3};
char *nameFun_M_SplitMapText_s2(Term term) { return  "SplitMapText$2" ; }
struct _ConstructionDescriptor descriptor_M_SplitMapText_s2 = {&sort_M_Reified_xVariable, 0, 8, sizeof(STRUCT_Con_M_SplitMapText_s2), conBindOffs_M_SplitMapText_s2, &nameFun_M_SplitMapText_s2, &step_M_SplitMapText_s2};

int step_M_SplitMapText_s2(Sink sink__V140, Term term__V141)
{
  int term__V141_count = LINK_COUNT(term__V141); permitUnusedInt(term__V141_count);
  do {
    /* Contraction rule DEFS-SplitMapText-1. */
    ASSERT(sink__V140->context, !strcmp(SYMBOL(term__V141),  "SplitMapText$2" ));
    Term sub__V142 = LINK(sink__V140->context, SUB(term__V141, 0)); int sub__V142_count = term__V141_count*LINK_COUNT(sub__V142); permitUnusedInt(sub__V142_count);
    /* sub__V142 = &#21 */
    Term sub__V143 = LINK(sink__V140->context, SUB(term__V141, 1)); int sub__V143_count = term__V141_count*LINK_COUNT(sub__V143); permitUnusedInt(sub__V143_count);
    /* sub__V143 = &#22 */
    Variable x__V144 = BINDER(term__V141,2,0); if (term__V141_count <= 1) UNBIND(x__V144);
    Term sub__V145 = LINK(sink__V140->context, SUB(term__V141, 2)); int sub__V145_count = term__V141_count*LINK_COUNT(sub__V145); permitUnusedInt(sub__V145_count);
    CRSX_CHECK_SORT(sink__V140->context, sub__V145, &sort_M_Reified_xVariable); UNLINK_SUB(sink__V140->context, term__V141,  2); NORMALIZE(sink__V140->context, sub__V145); SUB(term__V141,  2) = LINK(sink__V140->context, sub__V145);
    /* sub__V145 = &#1 */
    Term sub__V146 = LINK(sink__V140->context, SUB(term__V141, 3)); int sub__V146_count = term__V141_count*LINK_COUNT(sub__V146); permitUnusedInt(sub__V146_count);
    UNLINK_SUB(sink__V140->context, term__V141,  3); NORMALIZE(sink__V140->context, sub__V146); SUB(term__V141,  3) = LINK(sink__V140->context, sub__V146);
    /* sub__V146 = &#3 */
    Term sub__V147 = LINK(sink__V140->context, SUB(term__V141, 4)); int sub__V147_count = term__V141_count*LINK_COUNT(sub__V147); permitUnusedInt(sub__V147_count);
    UNLINK_SUB(sink__V140->context, term__V141,  4); NORMALIZE(sink__V140->context, sub__V147); SUB(term__V141,  4) = LINK(sink__V140->context, sub__V147);
    /* sub__V147 = &#4 */
    Term sub__V148 = LINK(sink__V140->context, SUB(term__V141, 5)); int sub__V148_count = term__V141_count*LINK_COUNT(sub__V148); permitUnusedInt(sub__V148_count);
    UNLINK_SUB(sink__V140->context, term__V141,  5); NORMALIZE(sink__V140->context, sub__V148); SUB(term__V141,  5) = LINK(sink__V140->context, sub__V148);
    /* sub__V148 = &#5 */
    Variable x__V149 = BINDER(term__V141,6,0); if (term__V141_count <= 1) UNBIND(x__V149);
    Term sub__V150 = LINK(sink__V140->context, SUB(term__V141, 6)); int sub__V150_count = term__V141_count*LINK_COUNT(sub__V150); permitUnusedInt(sub__V150_count);
    CRSX_CHECK_SORT(sink__V140->context, sub__V150, &sort_M_Reified_xVariable); UNLINK_SUB(sink__V140->context, term__V141,  6); NORMALIZE(sink__V140->context, sub__V150); SUB(term__V141,  6) = LINK(sink__V140->context, sub__V150);
    /* sub__V150 = &#6 */
    Variable x__V151 = BINDER(term__V141,7,0); if (term__V141_count <= 1) UNBIND(x__V151);
    Term sub__V152 = LINK(sink__V140->context, SUB(term__V141, 7)); int sub__V152_count = term__V141_count*LINK_COUNT(sub__V152); permitUnusedInt(sub__V152_count);
    CRSX_CHECK_SORT(sink__V140->context, sub__V152, &sort_M_Reified_xVariable); UNLINK_SUB(sink__V140->context, term__V141,  7); NORMALIZE(sink__V140->context, sub__V152); SUB(term__V141,  7) = LINK(sink__V140->context, sub__V152);
    /* sub__V152 = &#7 */
    
    NamedPropertyLink namedP__V153 = LINK_NamedPropertyLink(sink__V140->context, NAMED_PROPERTIES(term__V141));
    VariablePropertyLink varP__V154 = LINK_VariablePropertyLink(sink__V140->context, VARIABLE_PROPERTIES(term__V141));
    Hashset namedFV__V155 = LINK_VARIABLESET(sink__V140->context, asConstruction(term__V141)->properties->namedFreeVars);
    Hashset varFV__V156 = LINK_VARIABLESET(sink__V140->context, asConstruction(term__V141)->properties->variableFreeVars);
    UNLINK(sink__V140->context, term__V141);
    { int test__V157;
      FORCE(sink__V140->context, sub__V146); LINK(sink__V140->context, sub__V146);
      test__V157 = (int) !strcmp(SYMBOL(sub__V146), "0" );
      UNLINK(sink__V140->context, sub__V146);  if (test__V157) {  UNLINK(sink__V140->context, sub__V146); { START(sink__V140, _M__sTextCons);
          { START(sink__V140, _M__sTextEmbed);
            { START(sink__V140, _M_AsText);
              {
                Term arg__V158;
                { Sink buf__V159 = ALLOCA_BUFFER(sink__V140->context);
                  COPY(buf__V159, LINK(buf__V159->context, sub__V147));arg__V158 = BUFFER_TERM(buf__V159); FREE_BUFFER(buf__V159); }
                Variable vars__V160[1] = {x__V149};
                Term args__V161[1] = {arg__V158};
                struct _SubstitutionFrame substitution__V162 = {NULL, 0, 1, vars__V160, args__V161, NULL};
                SUBSTITUTE(sink__V140, LINK(sink__V140->context,sub__V150), &substitution__V162); }
              END(sink__V140, _M_AsText); }
            END(sink__V140, _M__sTextEmbed); }
          { START(sink__V140, _M__sTextCons);
            { START(sink__V140, _M__sTextEmbed);
              { START(sink__V140, _M_AsText);
                {
                  Term arg__V163;
                  { Sink buf__V164 = ALLOCA_BUFFER(sink__V140->context);
                    COPY(buf__V164, sub__V142);arg__V163 = BUFFER_TERM(buf__V164); FREE_BUFFER(buf__V164); }
                  Variable vars__V165[1] = {x__V144};
                  Term args__V166[1] = {arg__V163};
                  struct _SubstitutionFrame substitution__V167 = {NULL, 0, 1, vars__V165, args__V166, NULL};
                  SUBSTITUTE(sink__V140, LINK(sink__V140->context,sub__V145), &substitution__V167); }
                END(sink__V140, _M_AsText); }
              END(sink__V140, _M__sTextEmbed); }
            { START(sink__V140, _M__sTextCons);
              { START(sink__V140, _M__sTextEmbed);
                { START(sink__V140, _M_AsText);
                  { START(sink__V140, _M_SplitMapText_s1);
                    COPY(sink__V140, sub__V143);{ Variable x__V168 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V140->context,"x__V168");
                      Variable binds__V169[1] = {x__V168}; BINDS(sink__V140, 1, binds__V169);
                      {
                        Term arg__V170;
                        { Sink buf__V171 = ALLOCA_BUFFER(sink__V140->context);
                          USE(buf__V171, x__V168); arg__V170 = BUFFER_TERM(buf__V171); FREE_BUFFER(buf__V171); }
                        Variable vars__V172[1] = {x__V144};
                        Term args__V173[1] = {arg__V170};
                        struct _SubstitutionFrame substitution__V174 = {NULL, 0, 1, vars__V172, args__V173, NULL};
                        SUBSTITUTE(sink__V140, sub__V145, &substitution__V174); }
                       }
                    LITERAL(sink__V140,  "1" ); COPY(sink__V140, sub__V147);COPY(sink__V140, sub__V148);{ Variable x__V175 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V140->context,"x__V175");
                      Variable binds__V176[1] = {x__V175}; BINDS(sink__V140, 1, binds__V176);
                      {
                        Term arg__V177;
                        { Sink buf__V178 = ALLOCA_BUFFER(sink__V140->context);
                          USE(buf__V178, x__V175); arg__V177 = BUFFER_TERM(buf__V178); FREE_BUFFER(buf__V178); }
                        Variable vars__V179[1] = {x__V149};
                        Term args__V180[1] = {arg__V177};
                        struct _SubstitutionFrame substitution__V181 = {NULL, 0, 1, vars__V179, args__V180, NULL};
                        SUBSTITUTE(sink__V140, sub__V150, &substitution__V181); }
                       }
                    { Variable x__V182 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V140->context,"x__V182");
                      Variable binds__V183[1] = {x__V182}; BINDS(sink__V140, 1, binds__V183);
                      {
                        Term arg__V184;
                        { Sink buf__V185 = ALLOCA_BUFFER(sink__V140->context);
                          USE(buf__V185, x__V182); arg__V184 = BUFFER_TERM(buf__V185); FREE_BUFFER(buf__V185); }
                        Variable vars__V186[1] = {x__V151};
                        Term args__V187[1] = {arg__V184};
                        struct _SubstitutionFrame substitution__V188 = {NULL, 0, 1, vars__V186, args__V187, NULL};
                        SUBSTITUTE(sink__V140, sub__V152, &substitution__V188); }
                       }
                    END(sink__V140, _M_SplitMapText_s1); }
                  END(sink__V140, _M_AsText); }
                END(sink__V140, _M__sTextEmbed); }
              { START(sink__V140, _M__sTextNil);
                END(sink__V140, _M__sTextNil); }
              END(sink__V140, _M__sTextCons); }
            END(sink__V140, _M__sTextCons); }
          END(sink__V140, _M__sTextCons); }
         }
      else { { int test__V189;
          FORCE(sink__V140->context, sub__V146); LINK(sink__V140->context, sub__V146);
          FORCE(sink__V140->context, sub__V148); LINK(sink__V140->context, sub__V148);
          test__V189 = (int) !strcmp(SYMBOL(sub__V146),SYMBOL(sub__V148));
          UNLINK(sink__V140->context, sub__V146);   UNLINK(sink__V140->context, sub__V148);  if (test__V189) {  UNLINK(sink__V140->context, sub__V146); { START(sink__V140, _M__sTextCons);
              { START(sink__V140, _M__sTextEmbed);
                { START(sink__V140, _M_AsText);
                  {
                    Term arg__V190;
                    { Sink buf__V191 = ALLOCA_BUFFER(sink__V140->context);
                      COPY(buf__V191, LINK(buf__V191->context, sub__V147));arg__V190 = BUFFER_TERM(buf__V191); FREE_BUFFER(buf__V191); }
                    Variable vars__V192[1] = {x__V151};
                    Term args__V193[1] = {arg__V190};
                    struct _SubstitutionFrame substitution__V194 = {NULL, 0, 1, vars__V192, args__V193, NULL};
                    SUBSTITUTE(sink__V140, LINK(sink__V140->context,sub__V152), &substitution__V194); }
                  END(sink__V140, _M_AsText); }
                END(sink__V140, _M__sTextEmbed); }
              { START(sink__V140, _M__sTextCons);
                { START(sink__V140, _M__sTextEmbed);
                  { START(sink__V140, _M_AsText);
                    { START(sink__V140, _M_SplitMapText_s1);
                      { START(sink__V140, _M__sCons);
                        COPY(sink__V140, sub__V142);COPY(sink__V140, sub__V143);END(sink__V140, _M__sCons); }
                      { Variable x__V195 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V140->context,"x__V195");
                        Variable binds__V196[1] = {x__V195}; BINDS(sink__V140, 1, binds__V196);
                        {
                          Term arg__V197;
                          { Sink buf__V198 = ALLOCA_BUFFER(sink__V140->context);
                            USE(buf__V198, x__V195); arg__V197 = BUFFER_TERM(buf__V198); FREE_BUFFER(buf__V198); }
                          Variable vars__V199[1] = {x__V144};
                          Term args__V200[1] = {arg__V197};
                          struct _SubstitutionFrame substitution__V201 = {NULL, 0, 1, vars__V199, args__V200, NULL};
                          SUBSTITUTE(sink__V140, sub__V145, &substitution__V201); }
                         }
                      LITERAL(sink__V140,  "0" ); { double num__V202;
                        num__V202 = DOUBLE(sub__V147); { double tmp__V203;
                          tmp__V203 = (double) 1; num__V202 += tmp__V203; }
                        LITERALNF(sink__V140, (size_t) 31, "%G", num__V202); }
                      COPY(sink__V140, sub__V148);{ Variable x__V204 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V140->context,"x__V204");
                        Variable binds__V205[1] = {x__V204}; BINDS(sink__V140, 1, binds__V205);
                        {
                          Term arg__V206;
                          { Sink buf__V207 = ALLOCA_BUFFER(sink__V140->context);
                            USE(buf__V207, x__V204); arg__V206 = BUFFER_TERM(buf__V207); FREE_BUFFER(buf__V207); }
                          Variable vars__V208[1] = {x__V149};
                          Term args__V209[1] = {arg__V206};
                          struct _SubstitutionFrame substitution__V210 = {NULL, 0, 1, vars__V208, args__V209, NULL};
                          SUBSTITUTE(sink__V140, sub__V150, &substitution__V210); }
                         }
                      { Variable x__V211 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V140->context,"x__V211");
                        Variable binds__V212[1] = {x__V211}; BINDS(sink__V140, 1, binds__V212);
                        {
                          Term arg__V213;
                          { Sink buf__V214 = ALLOCA_BUFFER(sink__V140->context);
                            USE(buf__V214, x__V211); arg__V213 = BUFFER_TERM(buf__V214); FREE_BUFFER(buf__V214); }
                          Variable vars__V215[1] = {x__V151};
                          Term args__V216[1] = {arg__V213};
                          struct _SubstitutionFrame substitution__V217 = {NULL, 0, 1, vars__V215, args__V216, NULL};
                          SUBSTITUTE(sink__V140, sub__V152, &substitution__V217); }
                         }
                      END(sink__V140, _M_SplitMapText_s1); }
                    END(sink__V140, _M_AsText); }
                  END(sink__V140, _M__sTextEmbed); }
                { START(sink__V140, _M__sTextNil);
                  END(sink__V140, _M__sTextNil); }
                END(sink__V140, _M__sTextCons); }
              END(sink__V140, _M__sTextCons); }
             }
          else { { START(sink__V140, _M__sTextCons);
              { START(sink__V140, _M__sTextEmbed);
                { START(sink__V140, _M_AsText);
                  {
                    Term arg__V218;
                    { Sink buf__V219 = ALLOCA_BUFFER(sink__V140->context);
                      COPY(buf__V219, sub__V142);arg__V218 = BUFFER_TERM(buf__V219); FREE_BUFFER(buf__V219); }
                    Variable vars__V220[1] = {x__V144};
                    Term args__V221[1] = {arg__V218};
                    struct _SubstitutionFrame substitution__V222 = {NULL, 0, 1, vars__V220, args__V221, NULL};
                    SUBSTITUTE(sink__V140, LINK(sink__V140->context,sub__V145), &substitution__V222); }
                  END(sink__V140, _M_AsText); }
                END(sink__V140, _M__sTextEmbed); }
              { START(sink__V140, _M__sTextCons);
                { START(sink__V140, _M__sTextEmbed);
                  { START(sink__V140, _M_AsText);
                    { START(sink__V140, _M_SplitMapText_s1);
                      COPY(sink__V140, sub__V143);{ Variable x__V223 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V140->context,"x__V223");
                        Variable binds__V224[1] = {x__V223}; BINDS(sink__V140, 1, binds__V224);
                        {
                          Term arg__V225;
                          { Sink buf__V226 = ALLOCA_BUFFER(sink__V140->context);
                            USE(buf__V226, x__V223); arg__V225 = BUFFER_TERM(buf__V226); FREE_BUFFER(buf__V226); }
                          Variable vars__V227[1] = {x__V144};
                          Term args__V228[1] = {arg__V225};
                          struct _SubstitutionFrame substitution__V229 = {NULL, 0, 1, vars__V227, args__V228, NULL};
                          SUBSTITUTE(sink__V140, sub__V145, &substitution__V229); }
                         }
                      { double num__V230;
                        num__V230 = DOUBLE(sub__V146); { double tmp__V231;
                          tmp__V231 = (double) 1; num__V230 += tmp__V231; }
                        LITERALNF(sink__V140, (size_t) 31, "%G", num__V230); }
                      COPY(sink__V140, sub__V147);COPY(sink__V140, sub__V148);{ Variable x__V232 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V140->context,"x__V232");
                        Variable binds__V233[1] = {x__V232}; BINDS(sink__V140, 1, binds__V233);
                        {
                          Term arg__V234;
                          { Sink buf__V235 = ALLOCA_BUFFER(sink__V140->context);
                            USE(buf__V235, x__V232); arg__V234 = BUFFER_TERM(buf__V235); FREE_BUFFER(buf__V235); }
                          Variable vars__V236[1] = {x__V149};
                          Term args__V237[1] = {arg__V234};
                          struct _SubstitutionFrame substitution__V238 = {NULL, 0, 1, vars__V236, args__V237, NULL};
                          SUBSTITUTE(sink__V140, sub__V150, &substitution__V238); }
                         }
                      { Variable x__V239 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V140->context,"x__V239");
                        Variable binds__V240[1] = {x__V239}; BINDS(sink__V140, 1, binds__V240);
                        {
                          Term arg__V241;
                          { Sink buf__V242 = ALLOCA_BUFFER(sink__V140->context);
                            USE(buf__V242, x__V239); arg__V241 = BUFFER_TERM(buf__V242); FREE_BUFFER(buf__V242); }
                          Variable vars__V243[1] = {x__V151};
                          Term args__V244[1] = {arg__V241};
                          struct _SubstitutionFrame substitution__V245 = {NULL, 0, 1, vars__V243, args__V244, NULL};
                          SUBSTITUTE(sink__V140, sub__V152, &substitution__V245); }
                         }
                      END(sink__V140, _M_SplitMapText_s1); }
                    END(sink__V140, _M_AsText); }
                  END(sink__V140, _M__sTextEmbed); }
                { START(sink__V140, _M__sTextNil);
                  END(sink__V140, _M__sTextNil); }
                END(sink__V140, _M__sTextCons); }
              END(sink__V140, _M__sTextCons); }
             }
        }
         }
    }
    UNLINK_VARIABLESET(sink__V140->context, namedFV__V155); UNLINK_VARIABLESET(sink__V140->context, varFV__V156);
    UNLINK_NamedPropertyLink(sink__V140->context, namedP__V153); UNLINK_VariablePropertyLink(sink__V140->context, varP__V154);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION SplitMapText$3. */
int conBindOffs_M_SplitMapText_s3[] = {0 , 1 , 1 , 1 , 1 , 2 , 3};
char *nameFun_M_SplitMapText_s3(Term term) { return  "SplitMapText$3" ; }
struct _ConstructionDescriptor descriptor_M_SplitMapText_s3 = {&sort_M_Reified_xVariable, 0, 6, sizeof(STRUCT_Con_M_SplitMapText_s3), conBindOffs_M_SplitMapText_s3, &nameFun_M_SplitMapText_s3, &step_M_SplitMapText_s3};

int step_M_SplitMapText_s3(Sink sink__V246, Term term__V247)
{
  int term__V247_count = LINK_COUNT(term__V247); permitUnusedInt(term__V247_count);
  do {
    /* Contraction rule DEFS-SplitMapText-2. */
    ASSERT(sink__V246->context, !strcmp(SYMBOL(term__V247),  "SplitMapText$3" ));
    Variable x__V248 = BINDER(term__V247,0,0); if (term__V247_count <= 1) UNBIND(x__V248);
    Term sub__V249 = SUB(term__V247, 0); permitUnusedTerm(sub__V249); int sub__V249_count = term__V247_count*LINK_COUNT(sub__V249); permitUnusedInt(sub__V249_count);
    CRSX_CHECK_SORT(sink__V246->context, sub__V249, &sort_M_Reified_xVariable); /* sub__V249 = &#1 */
    Term sub__V250 = SUB(term__V247, 1); permitUnusedTerm(sub__V250); int sub__V250_count = term__V247_count*LINK_COUNT(sub__V250); permitUnusedInt(sub__V250_count);
    /* sub__V250 = &#3 */
    Term sub__V251 = LINK(sink__V246->context, SUB(term__V247, 2)); int sub__V251_count = term__V247_count*LINK_COUNT(sub__V251); permitUnusedInt(sub__V251_count);
    UNLINK_SUB(sink__V246->context, term__V247,  2); NORMALIZE(sink__V246->context, sub__V251); SUB(term__V247,  2) = LINK(sink__V246->context, sub__V251);
    /* sub__V251 = &#4 */
    Term sub__V252 = SUB(term__V247, 3); permitUnusedTerm(sub__V252); int sub__V252_count = term__V247_count*LINK_COUNT(sub__V252); permitUnusedInt(sub__V252_count);
    /* sub__V252 = &#5 */
    Variable x__V253 = BINDER(term__V247,4,0); if (term__V247_count <= 1) UNBIND(x__V253);
    Term sub__V254 = SUB(term__V247, 4); permitUnusedTerm(sub__V254); int sub__V254_count = term__V247_count*LINK_COUNT(sub__V254); permitUnusedInt(sub__V254_count);
    CRSX_CHECK_SORT(sink__V246->context, sub__V254, &sort_M_Reified_xVariable); /* sub__V254 = &#6 */
    Variable x__V255 = BINDER(term__V247,5,0); if (term__V247_count <= 1) UNBIND(x__V255);
    Term sub__V256 = LINK(sink__V246->context, SUB(term__V247, 5)); int sub__V256_count = term__V247_count*LINK_COUNT(sub__V256); permitUnusedInt(sub__V256_count);
    CRSX_CHECK_SORT(sink__V246->context, sub__V256, &sort_M_Reified_xVariable); /* sub__V256 = &#7 */
    
    NamedPropertyLink namedP__V257 = LINK_NamedPropertyLink(sink__V246->context, NAMED_PROPERTIES(term__V247));
    VariablePropertyLink varP__V258 = LINK_VariablePropertyLink(sink__V246->context, VARIABLE_PROPERTIES(term__V247));
    Hashset namedFV__V259 = LINK_VARIABLESET(sink__V246->context, asConstruction(term__V247)->properties->namedFreeVars);
    Hashset varFV__V260 = LINK_VARIABLESET(sink__V246->context, asConstruction(term__V247)->properties->variableFreeVars);
    UNLINK(sink__V246->context, term__V247);
    {
      Term arg__V261;
      { Sink buf__V262 = ALLOCA_BUFFER(sink__V246->context);
        COPY(buf__V262, sub__V251);arg__V261 = BUFFER_TERM(buf__V262); FREE_BUFFER(buf__V262); }
      Variable vars__V263[1] = {x__V255};
      Term args__V264[1] = {arg__V261};
      struct _SubstitutionFrame substitution__V265 = {NULL, 0, 1, vars__V263, args__V264, NULL};
      SUBSTITUTE(sink__V246, sub__V256, &substitution__V265); }
    UNLINK_VARIABLESET(sink__V246->context, namedFV__V259); UNLINK_VARIABLESET(sink__V246->context, varFV__V260);
    UNLINK_NamedPropertyLink(sink__V246->context, namedP__V257); UNLINK_VariablePropertyLink(sink__V246->context, varP__V258);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DINTEGER. */
int conBindOffs_M_DINTEGER[] = {0 , 0 , 0};
char *nameFun_M_DINTEGER(Term term) { return  "DINTEGER" ; }
struct _ConstructionDescriptor descriptor_M_DINTEGER = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_DINTEGER), conBindOffs_M_DINTEGER, &nameFun_M_DINTEGER, &step_M_DINTEGER};

int step_M_DINTEGER(Sink sink__V266, Term term__V267)
{
  int term__V267_count = LINK_COUNT(term__V267); permitUnusedInt(term__V267_count);
  Term sub__V268 = FORCE(sink__V266->context, SUB(term__V267, 0));
  EnumOf_M_OK_xSORT choice__V269 = (IS_VARIABLE_USE(sub__V268) ? VarOf_M_OK_xSORT : (EnumOf_M_OK_xSORT) TAG(sub__V268));
  switch (choice__V269)
  {
    case Data_M_OK: { /* Function DEFS-DINTEGER-1$DINTEGER$OK case OK */
      ASSERT(sink__V266->context, !strcmp(SYMBOL(term__V267),  "DINTEGER" ));
      Term sub__V270 = SUB(term__V267, 0); permitUnusedTerm(sub__V270); int sub__V270_count = term__V267_count*LINK_COUNT(sub__V270); permitUnusedInt(sub__V270_count);
      CRSX_CHECK_SORT(sink__V266->context, sub__V270, &sort_M_OK_xSORT); ASSERT(sink__V266->context, !strcmp(SYMBOL(sub__V270),  "OK" ));
      Term sub__V271 = LINK(sink__V266->context, SUB(term__V267, 1)); int sub__V271_count = term__V267_count*LINK_COUNT(sub__V271); permitUnusedInt(sub__V271_count);
      /* sub__V271 = &#0 */
      
      NamedPropertyLink namedP__V272 = LINK_NamedPropertyLink(sink__V266->context, NAMED_PROPERTIES(term__V267));
      VariablePropertyLink varP__V273 = LINK_VariablePropertyLink(sink__V266->context, VARIABLE_PROPERTIES(term__V267));
      Hashset namedFV__V274 = LINK_VARIABLESET(sink__V266->context, asConstruction(term__V267)->properties->namedFreeVars);
      Hashset varFV__V275 = LINK_VARIABLESET(sink__V266->context, asConstruction(term__V267)->properties->variableFreeVars);
      UNLINK(sink__V266->context, term__V267);
      ADD_PROPERTIES(sink__V266, LINK_VARIABLESET(sink__V266->context, namedFV__V274), LINK_VARIABLESET(sink__V266->context, varFV__V275), LINK_NamedPropertyLink(sink__V266->context, namedP__V272), LINK_VariablePropertyLink(sink__V266->context, varP__V273));
      { START(sink__V266, _M_DINTEGER_s1);
        COPY(sink__V266, sub__V271);END(sink__V266, _M_DINTEGER_s1); }
      UNLINK_VARIABLESET(sink__V266->context, namedFV__V274); UNLINK_VARIABLESET(sink__V266->context, varFV__V275);
      UNLINK_NamedPropertyLink(sink__V266->context, namedP__V272); UNLINK_VariablePropertyLink(sink__V266->context, varP__V273);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION Step. */
int conBindOffs_M_Step[] = {0 , 0};
char *nameFun_M_Step(Term term) { return  "Step" ; }
struct _ConstructionDescriptor descriptor_M_Step = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_Step), conBindOffs_M_Step, &nameFun_M_Step, &step_M_Step};

int step_M_Step(Sink sink__V276, Term term__V277)
{
  int term__V277_count = LINK_COUNT(term__V277); permitUnusedInt(term__V277_count);
  do {
    /* Contraction rule DEFS-Step-1. */
    ASSERT(sink__V276->context, !strcmp(SYMBOL(term__V277),  "Step" ));
    Term sub__V278 = LINK(sink__V276->context, SUB(term__V277, 0)); int sub__V278_count = term__V277_count*LINK_COUNT(sub__V278); permitUnusedInt(sub__V278_count);
    /* sub__V278 = &#1 */
    
    NamedPropertyLink namedP__V279 = LINK_NamedPropertyLink(sink__V276->context, NAMED_PROPERTIES(term__V277));
    VariablePropertyLink varP__V280 = LINK_VariablePropertyLink(sink__V276->context, VARIABLE_PROPERTIES(term__V277));
    Hashset namedFV__V281 = LINK_VARIABLESET(sink__V276->context, asConstruction(term__V277)->properties->namedFreeVars);
    Hashset varFV__V282 = LINK_VARIABLESET(sink__V276->context, asConstruction(term__V277)->properties->variableFreeVars);
    UNLINK(sink__V276->context, term__V277);
    { START(sink__V276, _M__sTextCons);
      { START(sink__V276, _M__sTextChars);
        LITERAL(sink__V276,  "step" ); END(sink__V276, _M__sTextChars); }
      { START(sink__V276, _M__sTextCons);
        { START(sink__V276, _M__sTextEmbed);
          { START(sink__V276, _M_AsText);
            { START(sink__V276, _M_MANGLE);
              COPY(sink__V276, sub__V278);END(sink__V276, _M_MANGLE); }
            END(sink__V276, _M_AsText); }
          END(sink__V276, _M__sTextEmbed); }
        { START(sink__V276, _M__sTextNil);
          END(sink__V276, _M__sTextNil); }
        END(sink__V276, _M__sTextCons); }
      END(sink__V276, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V276->context, namedFV__V281); UNLINK_VARIABLESET(sink__V276->context, varFV__V282);
    UNLINK_NamedPropertyLink(sink__V276->context, namedP__V279); UNLINK_VariablePropertyLink(sink__V276->context, varP__V280);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DMANGLE. */
int conBindOffs_M_DMANGLE[] = {0 , 0 , 0};
char *nameFun_M_DMANGLE(Term term) { return  "DMANGLE" ; }
struct _ConstructionDescriptor descriptor_M_DMANGLE = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_DMANGLE), conBindOffs_M_DMANGLE, &nameFun_M_DMANGLE, &step_M_DMANGLE};

int step_M_DMANGLE(Sink sink__V283, Term term__V284)
{
  int term__V284_count = LINK_COUNT(term__V284); permitUnusedInt(term__V284_count);
  Term sub__V285 = FORCE(sink__V283->context, SUB(term__V284, 0));
  EnumOf_M_OK_xSORT choice__V286 = (IS_VARIABLE_USE(sub__V285) ? VarOf_M_OK_xSORT : (EnumOf_M_OK_xSORT) TAG(sub__V285));
  switch (choice__V286)
  {
    case Data_M_OK: { /* Function DEFS-DMANGLE-1$DMANGLE$OK case OK */
      ASSERT(sink__V283->context, !strcmp(SYMBOL(term__V284),  "DMANGLE" ));
      Term sub__V287 = SUB(term__V284, 0); permitUnusedTerm(sub__V287); int sub__V287_count = term__V284_count*LINK_COUNT(sub__V287); permitUnusedInt(sub__V287_count);
      CRSX_CHECK_SORT(sink__V283->context, sub__V287, &sort_M_OK_xSORT); ASSERT(sink__V283->context, !strcmp(SYMBOL(sub__V287),  "OK" ));
      Term sub__V288 = LINK(sink__V283->context, SUB(term__V284, 1)); int sub__V288_count = term__V284_count*LINK_COUNT(sub__V288); permitUnusedInt(sub__V288_count);
      /* sub__V288 = &#0 */
      
      NamedPropertyLink namedP__V289 = LINK_NamedPropertyLink(sink__V283->context, NAMED_PROPERTIES(term__V284));
      VariablePropertyLink varP__V290 = LINK_VariablePropertyLink(sink__V283->context, VARIABLE_PROPERTIES(term__V284));
      Hashset namedFV__V291 = LINK_VARIABLESET(sink__V283->context, asConstruction(term__V284)->properties->namedFreeVars);
      Hashset varFV__V292 = LINK_VARIABLESET(sink__V283->context, asConstruction(term__V284)->properties->variableFreeVars);
      UNLINK(sink__V283->context, term__V284);
      ADD_PROPERTIES(sink__V283, LINK_VARIABLESET(sink__V283->context, namedFV__V291), LINK_VARIABLESET(sink__V283->context, varFV__V292), LINK_NamedPropertyLink(sink__V283->context, namedP__V289), LINK_VariablePropertyLink(sink__V283->context, varP__V290));
      { START(sink__V283, _M_DMANGLE_s1);
        COPY(sink__V283, sub__V288);END(sink__V283, _M_DMANGLE_s1); }
      UNLINK_VARIABLESET(sink__V283->context, namedFV__V291); UNLINK_VARIABLESET(sink__V283->context, varFV__V292);
      UNLINK_NamedPropertyLink(sink__V283->context, namedP__V289); UNLINK_VariablePropertyLink(sink__V283->context, varP__V290);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION UnString. */
int conBindOffs_M_UnString[] = {0 , 0};
char *nameFun_M_UnString(Term term) { return  "UnString" ; }
struct _ConstructionDescriptor descriptor_M_UnString = {NULL, 0, 1, sizeof(STRUCT_Con_M_UnString), conBindOffs_M_UnString, &nameFun_M_UnString, &step_M_UnString};

int step_M_UnString(Sink sink__V293, Term term__V294)
{
  int term__V294_count = LINK_COUNT(term__V294); permitUnusedInt(term__V294_count);
  Term sub__V295 = FORCE(sink__V293->context, SUB(term__V294, 0));
  EnumOf_M_STRING_xENTRY choice__V296 = (IS_VARIABLE_USE(sub__V295) ? VarOf_M_STRING_xENTRY : (EnumOf_M_STRING_xENTRY) TAG(sub__V295));
  switch (choice__V296)
  {
    case Data_M_STRING_xVALUE: { /* Function DEFS-UnString-1$UnString$STRING_VALUE case STRING_VALUE */
      ASSERT(sink__V293->context, !strcmp(SYMBOL(term__V294),  "UnString" ));
      Term sub__V297 = SUB(term__V294, 0); permitUnusedTerm(sub__V297); int sub__V297_count = term__V294_count*LINK_COUNT(sub__V297); permitUnusedInt(sub__V297_count);
      CRSX_CHECK_SORT(sink__V293->context, sub__V297, &sort_M_STRING_xENTRY); ASSERT(sink__V293->context, !strcmp(SYMBOL(sub__V297),  "STRING_VALUE" ));
      Term sub__V298 = LINK(sink__V293->context, SUB(sub__V297, 0)); int sub__V298_count = sub__V297_count*LINK_COUNT(sub__V298); permitUnusedInt(sub__V298_count);
      /* sub__V298 = &#0-0 */
      
      NamedPropertyLink namedP__V299 = LINK_NamedPropertyLink(sink__V293->context, NAMED_PROPERTIES(term__V294));
      VariablePropertyLink varP__V300 = LINK_VariablePropertyLink(sink__V293->context, VARIABLE_PROPERTIES(term__V294));
      Hashset namedFV__V301 = LINK_VARIABLESET(sink__V293->context, asConstruction(term__V294)->properties->namedFreeVars);
      Hashset varFV__V302 = LINK_VARIABLESET(sink__V293->context, asConstruction(term__V294)->properties->variableFreeVars);
      UNLINK(sink__V293->context, term__V294);
      ADD_PROPERTIES(sink__V293, LINK_VARIABLESET(sink__V293->context, namedFV__V301), LINK_VARIABLESET(sink__V293->context, varFV__V302), LINK_NamedPropertyLink(sink__V293->context, namedP__V299), LINK_VariablePropertyLink(sink__V293->context, varP__V300));
      { START(sink__V293, _M_UnString_s1);
        COPY(sink__V293, sub__V298);END(sink__V293, _M_UnString_s1); }
      UNLINK_VARIABLESET(sink__V293->context, namedFV__V301); UNLINK_VARIABLESET(sink__V293->context, varFV__V302);
      UNLINK_NamedPropertyLink(sink__V293->context, namedP__V299); UNLINK_VariablePropertyLink(sink__V293->context, varP__V300);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION FormArguments-binder-count. */
int conBindOffs_M_FormArguments__binder__count[] = {0 , 0 , 0};
char *nameFun_M_FormArguments__binder__count(Term term) { return  "FormArguments-binder-count" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__count = {NULL, 0, 2, sizeof(STRUCT_Con_M_FormArguments__binder__count), conBindOffs_M_FormArguments__binder__count, &nameFun_M_FormArguments__binder__count, &step_M_FormArguments__binder__count};

int step_M_FormArguments__binder__count(Sink sink__V303, Term term__V304)
{
  int term__V304_count = LINK_COUNT(term__V304); permitUnusedInt(term__V304_count);
  Term sub__V305 = FORCE(sink__V303->context, SUB(term__V304, 0));
  EnumOf_M__sList choice__V306 = (IS_VARIABLE_USE(sub__V305) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V305));
  switch (choice__V306)
  {
    case Data_M__sCons: { /* Function DEFS-FormArguments-binder-count-2$FormArguments-binder-count$$Cons case $Cons */
      ASSERT(sink__V303->context, !strcmp(SYMBOL(term__V304),  "FormArguments-binder-count" ));
      Term sub__V307 = SUB(term__V304, 0); permitUnusedTerm(sub__V307); int sub__V307_count = term__V304_count*LINK_COUNT(sub__V307); permitUnusedInt(sub__V307_count);
      ASSERT(sink__V303->context, !strcmp(SYMBOL(sub__V307),  "$Cons" ));
      Term sub__V308 = LINK(sink__V303->context, SUB(sub__V307, 0)); int sub__V308_count = sub__V307_count*LINK_COUNT(sub__V308); permitUnusedInt(sub__V308_count);
      /* sub__V308 = &#0-0 */
      Term sub__V309 = LINK(sink__V303->context, SUB(sub__V307, 1)); int sub__V309_count = sub__V307_count*LINK_COUNT(sub__V309); permitUnusedInt(sub__V309_count);
      /* sub__V309 = &#0-1 */
      Term sub__V310 = LINK(sink__V303->context, SUB(term__V304, 1)); int sub__V310_count = term__V304_count*LINK_COUNT(sub__V310); permitUnusedInt(sub__V310_count);
      /* sub__V310 = &#2 */
      
      NamedPropertyLink namedP__V311 = LINK_NamedPropertyLink(sink__V303->context, NAMED_PROPERTIES(term__V304));
      VariablePropertyLink varP__V312 = LINK_VariablePropertyLink(sink__V303->context, VARIABLE_PROPERTIES(term__V304));
      Hashset namedFV__V313 = LINK_VARIABLESET(sink__V303->context, asConstruction(term__V304)->properties->namedFreeVars);
      Hashset varFV__V314 = LINK_VARIABLESET(sink__V303->context, asConstruction(term__V304)->properties->variableFreeVars);
      UNLINK(sink__V303->context, term__V304);
      ADD_PROPERTIES(sink__V303, LINK_VARIABLESET(sink__V303->context, namedFV__V313), LINK_VARIABLESET(sink__V303->context, varFV__V314), LINK_NamedPropertyLink(sink__V303->context, namedP__V311), LINK_VariablePropertyLink(sink__V303->context, varP__V312));
      { START(sink__V303, _M_FormArguments__binder__count_s1);
        COPY(sink__V303, sub__V308);COPY(sink__V303, sub__V309);COPY(sink__V303, sub__V310);END(sink__V303, _M_FormArguments__binder__count_s1); }
      UNLINK_VARIABLESET(sink__V303->context, namedFV__V313); UNLINK_VARIABLESET(sink__V303->context, varFV__V314);
      UNLINK_NamedPropertyLink(sink__V303->context, namedP__V311); UNLINK_VariablePropertyLink(sink__V303->context, varP__V312);
      
      return 1;
    break; } case Data_M__sNil: { /* Function DEFS-FormArguments-binder-count-3$FormArguments-binder-count$$Nil case $Nil */
      ASSERT(sink__V303->context, !strcmp(SYMBOL(term__V304),  "FormArguments-binder-count" ));
      Term sub__V315 = SUB(term__V304, 0); permitUnusedTerm(sub__V315); int sub__V315_count = term__V304_count*LINK_COUNT(sub__V315); permitUnusedInt(sub__V315_count);
      ASSERT(sink__V303->context, !strcmp(SYMBOL(sub__V315),  "$Nil" ));
      Term sub__V316 = LINK(sink__V303->context, SUB(term__V304, 1)); int sub__V316_count = term__V304_count*LINK_COUNT(sub__V316); permitUnusedInt(sub__V316_count);
      /* sub__V316 = &#0 */
      
      NamedPropertyLink namedP__V317 = LINK_NamedPropertyLink(sink__V303->context, NAMED_PROPERTIES(term__V304));
      VariablePropertyLink varP__V318 = LINK_VariablePropertyLink(sink__V303->context, VARIABLE_PROPERTIES(term__V304));
      Hashset namedFV__V319 = LINK_VARIABLESET(sink__V303->context, asConstruction(term__V304)->properties->namedFreeVars);
      Hashset varFV__V320 = LINK_VARIABLESET(sink__V303->context, asConstruction(term__V304)->properties->variableFreeVars);
      UNLINK(sink__V303->context, term__V304);
      ADD_PROPERTIES(sink__V303, LINK_VARIABLESET(sink__V303->context, namedFV__V319), LINK_VARIABLESET(sink__V303->context, varFV__V320), LINK_NamedPropertyLink(sink__V303->context, namedP__V317), LINK_VariablePropertyLink(sink__V303->context, varP__V318));
      { START(sink__V303, _M_FormArguments__binder__count_s4);
        COPY(sink__V303, sub__V316);END(sink__V303, _M_FormArguments__binder__count_s4); }
      UNLINK_VARIABLESET(sink__V303->context, namedFV__V319); UNLINK_VARIABLESET(sink__V303->context, varFV__V320);
      UNLINK_NamedPropertyLink(sink__V303->context, namedP__V317); UNLINK_VariablePropertyLink(sink__V303->context, varP__V318);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION DMANGLE$1. */
int conBindOffs_M_DMANGLE_s1[] = {0 , 0};
char *nameFun_M_DMANGLE_s1(Term term) { return  "DMANGLE$1" ; }
struct _ConstructionDescriptor descriptor_M_DMANGLE_s1 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_DMANGLE_s1), conBindOffs_M_DMANGLE_s1, &nameFun_M_DMANGLE_s1, &step_M_DMANGLE_s1};

int step_M_DMANGLE_s1(Sink sink__V321, Term term__V322)
{
  int term__V322_count = LINK_COUNT(term__V322); permitUnusedInt(term__V322_count);
  do {
    /* Contraction rule DEFS-DMANGLE-1. */
    ASSERT(sink__V321->context, !strcmp(SYMBOL(term__V322),  "DMANGLE$1" ));
    Term sub__V323 = LINK(sink__V321->context, SUB(term__V322, 0)); int sub__V323_count = term__V322_count*LINK_COUNT(sub__V323); permitUnusedInt(sub__V323_count);
    UNLINK_SUB(sink__V321->context, term__V322,  0); NORMALIZE(sink__V321->context, sub__V323); SUB(term__V322,  0) = LINK(sink__V321->context, sub__V323);
    /* sub__V323 = &#2 */
    
    NamedPropertyLink namedP__V324 = LINK_NamedPropertyLink(sink__V321->context, NAMED_PROPERTIES(term__V322));
    VariablePropertyLink varP__V325 = LINK_VariablePropertyLink(sink__V321->context, VARIABLE_PROPERTIES(term__V322));
    Hashset namedFV__V326 = LINK_VARIABLESET(sink__V321->context, asConstruction(term__V322)->properties->namedFreeVars);
    Hashset varFV__V327 = LINK_VARIABLESET(sink__V321->context, asConstruction(term__V322)->properties->variableFreeVars);
    UNLINK(sink__V321->context, term__V322);
    { START(sink__V321, _M__sTextCons);
      { START(sink__V321, _M__sTextChars);
        { char *str__V328;
          FORCE(sink__V321->context, sub__V323); LINK(sink__V321->context, sub__V323);
          { char *s__V329 = makeMangled(sink__V321->context, SYMBOL(sub__V323));
            { size_t z__V330 = strlen(s__V329) + 1; memcpy(str__V328 = ALLOCATE(sink__V321->context, z__V330), s__V329, z__V330);  UNLINK(sink__V321->context, sub__V323);  UNLINK(sink__V321->context, sub__V323); }
            }
          LITERALU(sink__V321, str__V328); }
        END(sink__V321, _M__sTextChars); }
      { START(sink__V321, _M__sTextNil);
        END(sink__V321, _M__sTextNil); }
      END(sink__V321, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V321->context, namedFV__V326); UNLINK_VARIABLESET(sink__V321->context, varFV__V327);
    UNLINK_NamedPropertyLink(sink__V321->context, namedP__V324); UNLINK_VariablePropertyLink(sink__V321->context, varP__V325);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION INTEGER. */
int conBindOffs_M_INTEGER[] = {0 , 0};
char *nameFun_M_INTEGER(Term term) { return  "INTEGER" ; }
struct _ConstructionDescriptor descriptor_M_INTEGER = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_INTEGER), conBindOffs_M_INTEGER, &nameFun_M_INTEGER, &step_M_INTEGER};

int step_M_INTEGER(Sink sink__V331, Term term__V332)
{
  int term__V332_count = LINK_COUNT(term__V332); permitUnusedInt(term__V332_count);
  do {
    /* Contraction rule DEFS-INTEGER-1. */
    ASSERT(sink__V331->context, !strcmp(SYMBOL(term__V332),  "INTEGER" ));
    Term sub__V333 = LINK(sink__V331->context, SUB(term__V332, 0)); int sub__V333_count = term__V332_count*LINK_COUNT(sub__V333); permitUnusedInt(sub__V333_count);
    UNLINK_SUB(sink__V331->context, term__V332,  0); NORMALIZE(sink__V331->context, sub__V333); SUB(term__V332,  0) = LINK(sink__V331->context, sub__V333);
    /* sub__V333 = &#1 */
    
    NamedPropertyLink namedP__V334 = LINK_NamedPropertyLink(sink__V331->context, NAMED_PROPERTIES(term__V332));
    VariablePropertyLink varP__V335 = LINK_VariablePropertyLink(sink__V331->context, VARIABLE_PROPERTIES(term__V332));
    Hashset namedFV__V336 = LINK_VARIABLESET(sink__V331->context, asConstruction(term__V332)->properties->namedFreeVars);
    Hashset varFV__V337 = LINK_VARIABLESET(sink__V331->context, asConstruction(term__V332)->properties->variableFreeVars);
    UNLINK(sink__V331->context, term__V332);
    { START(sink__V331, _M__sTextCons);
      { START(sink__V331, _M__sTextChars);
        { char *str__V338;
          {double num__V339; char *str__V340;
            num__V339 = DOUBLE(sub__V333); snprintf(str__V340 = ALLOCA(sink__V331->context, (size_t) 32), (size_t) 31, "%G", num__V339);
            { size_t z__V341 = strlen(str__V340) + 1; memcpy(str__V338 = ALLOCATE(sink__V331->context, z__V341), str__V340, z__V341); }
             }
          LITERALU(sink__V331, str__V338); }
        END(sink__V331, _M__sTextChars); }
      { START(sink__V331, _M__sTextNil);
        END(sink__V331, _M__sTextNil); }
      END(sink__V331, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V331->context, namedFV__V336); UNLINK_VARIABLESET(sink__V331->context, varFV__V337);
    UNLINK_NamedPropertyLink(sink__V331->context, namedP__V334); UNLINK_VariablePropertyLink(sink__V331->context, varP__V335);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION MetaVar2$1. */
int conBindOffs_M_MetaVar2_s1[] = {0 , 0};
char *nameFun_M_MetaVar2_s1(Term term) { return  "MetaVar2$1" ; }
struct _ConstructionDescriptor descriptor_M_MetaVar2_s1 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_MetaVar2_s1), conBindOffs_M_MetaVar2_s1, &nameFun_M_MetaVar2_s1, &step_M_MetaVar2_s1};

int step_M_MetaVar2_s1(Sink sink__V342, Term term__V343)
{
  int term__V343_count = LINK_COUNT(term__V343); permitUnusedInt(term__V343_count);
  do {
    /* Contraction rule DEFS-MetaVar2-2. */
    ASSERT(sink__V342->context, !strcmp(SYMBOL(term__V343),  "MetaVar2$1" ));
    Term sub__V344 = LINK(sink__V342->context, SUB(term__V343, 0)); int sub__V344_count = term__V343_count*LINK_COUNT(sub__V344); permitUnusedInt(sub__V344_count);
    /* sub__V344 = &#11 */
    
    NamedPropertyLink namedP__V345 = LINK_NamedPropertyLink(sink__V342->context, NAMED_PROPERTIES(term__V343));
    VariablePropertyLink varP__V346 = LINK_VariablePropertyLink(sink__V342->context, VARIABLE_PROPERTIES(term__V343));
    Hashset namedFV__V347 = LINK_VARIABLESET(sink__V342->context, asConstruction(term__V343)->properties->namedFreeVars);
    Hashset varFV__V348 = LINK_VARIABLESET(sink__V342->context, asConstruction(term__V343)->properties->variableFreeVars);
    UNLINK(sink__V342->context, term__V343);
    { START(sink__V342, _M_TOKEN);
      COPY(sink__V342, sub__V344);END(sink__V342, _M_TOKEN); }
    UNLINK_VARIABLESET(sink__V342->context, namedFV__V347); UNLINK_VARIABLESET(sink__V342->context, varFV__V348);
    UNLINK_NamedPropertyLink(sink__V342->context, namedP__V345); UNLINK_VariablePropertyLink(sink__V342->context, varP__V346);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION MetaVar2$2. */
int conBindOffs_M_MetaVar2_s2[] = {0 , 0};
char *nameFun_M_MetaVar2_s2(Term term) { return  "MetaVar2$2" ; }
struct _ConstructionDescriptor descriptor_M_MetaVar2_s2 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_MetaVar2_s2), conBindOffs_M_MetaVar2_s2, &nameFun_M_MetaVar2_s2, &step_M_MetaVar2_s2};

int step_M_MetaVar2_s2(Sink sink__V349, Term term__V350)
{
  int term__V350_count = LINK_COUNT(term__V350); permitUnusedInt(term__V350_count);
  Term sub__V351 = FORCE(sink__V349->context, SUB(term__V350, 0));
  EnumOf_M_Reified_xVariable choice__V352 = (IS_VARIABLE_USE(sub__V351) ? VarOf_M_Reified_xVariable : (EnumOf_M_Reified_xVariable) TAG(sub__V351));
  switch (choice__V352)
  {
    case VarOf_M_Reified_xVariable: {
      do {
        ASSERT(sink__V349->context, !strcmp(SYMBOL(term__V350),  "MetaVar2$2" ));
        Term sub__V353 = SUB(term__V350, 0); permitUnusedTerm(sub__V353); int sub__V353_count = term__V350_count*LINK_COUNT(sub__V353); permitUnusedInt(sub__V353_count);
        CRSX_CHECK_SORT(sink__V349->context, sub__V353, &sort_M_Reified_xVariable); /* Function DEFS-MetaVar2-1$vFree fall-back case for free variable */
        Variable z__V354 = VARIABLE(sub__V353); permitUnusedVariable(z__V354);
        
        NamedPropertyLink namedP__V355 = LINK_NamedPropertyLink(sink__V349->context, NAMED_PROPERTIES(term__V350));
        VariablePropertyLink varP__V356 = LINK_VariablePropertyLink(sink__V349->context, VARIABLE_PROPERTIES(term__V350));
        Hashset namedFV__V357 = LINK_VARIABLESET(sink__V349->context, asConstruction(term__V350)->properties->namedFreeVars);
        Hashset varFV__V358 = LINK_VARIABLESET(sink__V349->context, asConstruction(term__V350)->properties->variableFreeVars);
        UNLINK(sink__V349->context, term__V350);
        ADD_PROPERTIES(sink__V349, LINK_VARIABLESET(sink__V349->context, namedFV__V357), LINK_VARIABLESET(sink__V349->context, varFV__V358), LINK_NamedPropertyLink(sink__V349->context, namedP__V355), LINK_VariablePropertyLink(sink__V349->context, varP__V356));
        { START(sink__V349, _M_MetaVar2_s3);
          USE(sink__V349, z__V354); END(sink__V349, _M_MetaVar2_s3); }
        UNLINK_VARIABLESET(sink__V349->context, namedFV__V357); UNLINK_VARIABLESET(sink__V349->context, varFV__V358);
        UNLINK_NamedPropertyLink(sink__V349->context, namedP__V355); UNLINK_VariablePropertyLink(sink__V349->context, varP__V356);
        
        return 1;
      } while(0);
      } default: break;
  }
  return 0;
}

/* FUNCTION MetaVar2$3. */
int conBindOffs_M_MetaVar2_s3[] = {0 , 0};
char *nameFun_M_MetaVar2_s3(Term term) { return  "MetaVar2$3" ; }
struct _ConstructionDescriptor descriptor_M_MetaVar2_s3 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_MetaVar2_s3), conBindOffs_M_MetaVar2_s3, &nameFun_M_MetaVar2_s3, &step_M_MetaVar2_s3};

int step_M_MetaVar2_s3(Sink sink__V359, Term term__V360)
{
  int term__V360_count = LINK_COUNT(term__V360); permitUnusedInt(term__V360_count);
  do {
    /* Contraction rule DEFS-MetaVar2-1. */
    ASSERT(sink__V359->context, !strcmp(SYMBOL(term__V360),  "MetaVar2$3" ));
    Term sub__V361 = LINK(sink__V359->context, SUB(term__V360, 0)); int sub__V361_count = term__V360_count*LINK_COUNT(sub__V361); permitUnusedInt(sub__V361_count);
    CRSX_CHECK_SORT(sink__V359->context, sub__V361, &sort_M_Reified_xVariable); UNLINK_SUB(sink__V359->context, term__V360,  0); NORMALIZE(sink__V359->context, sub__V361); SUB(term__V360,  0) = LINK(sink__V359->context, sub__V361);
    /* sub__V361 = &#11 */
    
    NamedPropertyLink namedP__V362 = LINK_NamedPropertyLink(sink__V359->context, NAMED_PROPERTIES(term__V360));
    VariablePropertyLink varP__V363 = LINK_VariablePropertyLink(sink__V359->context, VARIABLE_PROPERTIES(term__V360));
    Hashset namedFV__V364 = LINK_VARIABLESET(sink__V359->context, asConstruction(term__V360)->properties->namedFreeVars);
    Hashset varFV__V365 = LINK_VARIABLESET(sink__V359->context, asConstruction(term__V360)->properties->variableFreeVars);
    UNLINK(sink__V359->context, term__V360);
    { START(sink__V359, _M__sTextCons);
      { START(sink__V359, _M__sTextEmbed);
        { START(sink__V359, _M_AsText);
          COPY(sink__V359, sub__V361);END(sink__V359, _M_AsText); }
        END(sink__V359, _M__sTextEmbed); }
      { START(sink__V359, _M__sTextNil);
        END(sink__V359, _M__sTextNil); }
      END(sink__V359, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V359->context, namedFV__V364); UNLINK_VARIABLESET(sink__V359->context, varFV__V365);
    UNLINK_NamedPropertyLink(sink__V359->context, namedP__V362); UNLINK_VariablePropertyLink(sink__V359->context, varP__V363);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Sort. */
int conBindOffs_M_Sort[] = {0 , 0};
char *nameFun_M_Sort(Term term) { return  "Sort" ; }
struct _ConstructionDescriptor descriptor_M_Sort = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_Sort), conBindOffs_M_Sort, &nameFun_M_Sort, &step_M_Sort};

int step_M_Sort(Sink sink__V366, Term term__V367)
{
  int term__V367_count = LINK_COUNT(term__V367); permitUnusedInt(term__V367_count);
  do {
    /* Contraction rule DEFS-Sort-1. */
    ASSERT(sink__V366->context, !strcmp(SYMBOL(term__V367),  "Sort" ));
    Term sub__V368 = LINK(sink__V366->context, SUB(term__V367, 0)); int sub__V368_count = term__V367_count*LINK_COUNT(sub__V368); permitUnusedInt(sub__V368_count);
    /* sub__V368 = &#1 */
    
    NamedPropertyLink namedP__V369 = LINK_NamedPropertyLink(sink__V366->context, NAMED_PROPERTIES(term__V367));
    VariablePropertyLink varP__V370 = LINK_VariablePropertyLink(sink__V366->context, VARIABLE_PROPERTIES(term__V367));
    Hashset namedFV__V371 = LINK_VARIABLESET(sink__V366->context, asConstruction(term__V367)->properties->namedFreeVars);
    Hashset varFV__V372 = LINK_VARIABLESET(sink__V366->context, asConstruction(term__V367)->properties->variableFreeVars);
    UNLINK(sink__V366->context, term__V367);
    { START(sink__V366, _M__sTextCons);
      { START(sink__V366, _M__sTextChars);
        LITERAL(sink__V366,  "sort" ); END(sink__V366, _M__sTextChars); }
      { START(sink__V366, _M__sTextCons);
        { START(sink__V366, _M__sTextEmbed);
          { START(sink__V366, _M_AsText);
            { START(sink__V366, _M_MANGLE);
              COPY(sink__V366, sub__V368);END(sink__V366, _M_MANGLE); }
            END(sink__V366, _M_AsText); }
          END(sink__V366, _M__sTextEmbed); }
        { START(sink__V366, _M__sTextNil);
          END(sink__V366, _M__sTextNil); }
        END(sink__V366, _M__sTextCons); }
      END(sink__V366, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V366->context, namedFV__V371); UNLINK_VARIABLESET(sink__V366->context, varFV__V372);
    UNLINK_NamedPropertyLink(sink__V366->context, namedP__V369); UNLINK_VariablePropertyLink(sink__V366->context, varP__V370);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION EnumVar. */
int conBindOffs_M_EnumVar[] = {0 , 0};
char *nameFun_M_EnumVar(Term term) { return  "EnumVar" ; }
struct _ConstructionDescriptor descriptor_M_EnumVar = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_EnumVar), conBindOffs_M_EnumVar, &nameFun_M_EnumVar, &step_M_EnumVar};

int step_M_EnumVar(Sink sink__V373, Term term__V374)
{
  int term__V374_count = LINK_COUNT(term__V374); permitUnusedInt(term__V374_count);
  do {
    /* Contraction rule DEFS-EnumVar-1. */
    ASSERT(sink__V373->context, !strcmp(SYMBOL(term__V374),  "EnumVar" ));
    Term sub__V375 = LINK(sink__V373->context, SUB(term__V374, 0)); int sub__V375_count = term__V374_count*LINK_COUNT(sub__V375); permitUnusedInt(sub__V375_count);
    /* sub__V375 = &#1 */
    
    NamedPropertyLink namedP__V376 = LINK_NamedPropertyLink(sink__V373->context, NAMED_PROPERTIES(term__V374));
    VariablePropertyLink varP__V377 = LINK_VariablePropertyLink(sink__V373->context, VARIABLE_PROPERTIES(term__V374));
    Hashset namedFV__V378 = LINK_VARIABLESET(sink__V373->context, asConstruction(term__V374)->properties->namedFreeVars);
    Hashset varFV__V379 = LINK_VARIABLESET(sink__V373->context, asConstruction(term__V374)->properties->variableFreeVars);
    UNLINK(sink__V373->context, term__V374);
    { START(sink__V373, _M__sTextCons);
      { START(sink__V373, _M__sTextChars);
        LITERAL(sink__V373,  "VarOf" ); END(sink__V373, _M__sTextChars); }
      { START(sink__V373, _M__sTextCons);
        { START(sink__V373, _M__sTextEmbed);
          { START(sink__V373, _M_AsText);
            { START(sink__V373, _M_MANGLE);
              COPY(sink__V373, sub__V375);END(sink__V373, _M_MANGLE); }
            END(sink__V373, _M_AsText); }
          END(sink__V373, _M__sTextEmbed); }
        { START(sink__V373, _M__sTextNil);
          END(sink__V373, _M__sTextNil); }
        END(sink__V373, _M__sTextCons); }
      END(sink__V373, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V373->context, namedFV__V378); UNLINK_VARIABLESET(sink__V373->context, varFV__V379);
    UNLINK_NamedPropertyLink(sink__V373->context, namedP__V376); UNLINK_VariablePropertyLink(sink__V373->context, varP__V377);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DEnumTag$1. */
int conBindOffs_M_DEnumTag_s1[] = {0 , 0};
char *nameFun_M_DEnumTag_s1(Term term) { return  "DEnumTag$1" ; }
struct _ConstructionDescriptor descriptor_M_DEnumTag_s1 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_DEnumTag_s1), conBindOffs_M_DEnumTag_s1, &nameFun_M_DEnumTag_s1, &step_M_DEnumTag_s1};

int step_M_DEnumTag_s1(Sink sink__V380, Term term__V381)
{
  int term__V381_count = LINK_COUNT(term__V381); permitUnusedInt(term__V381_count);
  do {
    /* Contraction rule DEFS-DEnumTag-1. */
    ASSERT(sink__V380->context, !strcmp(SYMBOL(term__V381),  "DEnumTag$1" ));
    Term sub__V382 = LINK(sink__V380->context, SUB(term__V381, 0)); int sub__V382_count = term__V381_count*LINK_COUNT(sub__V382); permitUnusedInt(sub__V382_count);
    /* sub__V382 = &#2 */
    
    NamedPropertyLink namedP__V383 = LINK_NamedPropertyLink(sink__V380->context, NAMED_PROPERTIES(term__V381));
    VariablePropertyLink varP__V384 = LINK_VariablePropertyLink(sink__V380->context, VARIABLE_PROPERTIES(term__V381));
    Hashset namedFV__V385 = LINK_VARIABLESET(sink__V380->context, asConstruction(term__V381)->properties->namedFreeVars);
    Hashset varFV__V386 = LINK_VARIABLESET(sink__V380->context, asConstruction(term__V381)->properties->variableFreeVars);
    UNLINK(sink__V380->context, term__V381);
    { START(sink__V380, _M__sTextCons);
      { START(sink__V380, _M__sTextChars);
        LITERAL(sink__V380,  "Data" ); END(sink__V380, _M__sTextChars); }
      { START(sink__V380, _M__sTextCons);
        { START(sink__V380, _M__sTextEmbed);
          { START(sink__V380, _M_AsText);
            { START(sink__V380, _M_MANGLE);
              COPY(sink__V380, sub__V382);END(sink__V380, _M_MANGLE); }
            END(sink__V380, _M_AsText); }
          END(sink__V380, _M__sTextEmbed); }
        { START(sink__V380, _M__sTextNil);
          END(sink__V380, _M__sTextNil); }
        END(sink__V380, _M__sTextCons); }
      END(sink__V380, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V380->context, namedFV__V385); UNLINK_VARIABLESET(sink__V380->context, varFV__V386);
    UNLINK_NamedPropertyLink(sink__V380->context, namedP__V383); UNLINK_VariablePropertyLink(sink__V380->context, varP__V384);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION EnumFun. */
int conBindOffs_M_EnumFun[] = {0 , 0};
char *nameFun_M_EnumFun(Term term) { return  "EnumFun" ; }
struct _ConstructionDescriptor descriptor_M_EnumFun = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_EnumFun), conBindOffs_M_EnumFun, &nameFun_M_EnumFun, &step_M_EnumFun};

int step_M_EnumFun(Sink sink__V387, Term term__V388)
{
  int term__V388_count = LINK_COUNT(term__V388); permitUnusedInt(term__V388_count);
  do {
    /* Contraction rule DEFS-EnumFun-1. */
    ASSERT(sink__V387->context, !strcmp(SYMBOL(term__V388),  "EnumFun" ));
    Term sub__V389 = LINK(sink__V387->context, SUB(term__V388, 0)); int sub__V389_count = term__V388_count*LINK_COUNT(sub__V389); permitUnusedInt(sub__V389_count);
    /* sub__V389 = &#1 */
    
    NamedPropertyLink namedP__V390 = LINK_NamedPropertyLink(sink__V387->context, NAMED_PROPERTIES(term__V388));
    VariablePropertyLink varP__V391 = LINK_VariablePropertyLink(sink__V387->context, VARIABLE_PROPERTIES(term__V388));
    Hashset namedFV__V392 = LINK_VARIABLESET(sink__V387->context, asConstruction(term__V388)->properties->namedFreeVars);
    Hashset varFV__V393 = LINK_VARIABLESET(sink__V387->context, asConstruction(term__V388)->properties->variableFreeVars);
    UNLINK(sink__V387->context, term__V388);
    { START(sink__V387, _M__sTextCons);
      { START(sink__V387, _M__sTextChars);
        LITERAL(sink__V387,  "FunOf" ); END(sink__V387, _M__sTextChars); }
      { START(sink__V387, _M__sTextCons);
        { START(sink__V387, _M__sTextEmbed);
          { START(sink__V387, _M_AsText);
            { START(sink__V387, _M_MANGLE);
              COPY(sink__V387, sub__V389);END(sink__V387, _M_MANGLE); }
            END(sink__V387, _M_AsText); }
          END(sink__V387, _M__sTextEmbed); }
        { START(sink__V387, _M__sTextNil);
          END(sink__V387, _M__sTextNil); }
        END(sink__V387, _M__sTextCons); }
      END(sink__V387, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V387->context, namedFV__V392); UNLINK_VARIABLESET(sink__V387->context, varFV__V393);
    UNLINK_NamedPropertyLink(sink__V387->context, namedP__V390); UNLINK_VariablePropertyLink(sink__V387->context, varP__V391);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Sort-name. */
int conBindOffs_M_Sort__name[] = {0 , 0};
char *nameFun_M_Sort__name(Term term) { return  "Sort-name" ; }
struct _ConstructionDescriptor descriptor_M_Sort__name = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_Sort__name), conBindOffs_M_Sort__name, &nameFun_M_Sort__name, &step_M_Sort__name};

int step_M_Sort__name(Sink sink__V394, Term term__V395)
{
  int term__V395_count = LINK_COUNT(term__V395); permitUnusedInt(term__V395_count);
  Term sub__V396 = FORCE(sink__V394->context, SUB(term__V395, 0));
  EnumOf_M_Reified_xSort choice__V397 = (IS_VARIABLE_USE(sub__V396) ? VarOf_M_Reified_xSort : (EnumOf_M_Reified_xSort) TAG(sub__V396));
  switch (choice__V397)
  {
    case Data_M_SORT: { /* Function DEFS-Sort-name-1$Sort-name$SORT case SORT */
      ASSERT(sink__V394->context, !strcmp(SYMBOL(term__V395),  "Sort-name" ));
      Term sub__V398 = SUB(term__V395, 0); permitUnusedTerm(sub__V398); int sub__V398_count = term__V395_count*LINK_COUNT(sub__V398); permitUnusedInt(sub__V398_count);
      CRSX_CHECK_SORT(sink__V394->context, sub__V398, &sort_M_Reified_xSort); ASSERT(sink__V394->context, !strcmp(SYMBOL(sub__V398),  "SORT" ));
      Term sub__V399 = LINK(sink__V394->context, SUB(sub__V398, 0)); int sub__V399_count = sub__V398_count*LINK_COUNT(sub__V399); permitUnusedInt(sub__V399_count);
      /* sub__V399 = &#0-0 */
      Term sub__V400 = LINK(sink__V394->context, SUB(sub__V398, 1)); int sub__V400_count = sub__V398_count*LINK_COUNT(sub__V400); permitUnusedInt(sub__V400_count);
      /* sub__V400 = &#0-1 */
      
      NamedPropertyLink namedP__V401 = LINK_NamedPropertyLink(sink__V394->context, NAMED_PROPERTIES(term__V395));
      VariablePropertyLink varP__V402 = LINK_VariablePropertyLink(sink__V394->context, VARIABLE_PROPERTIES(term__V395));
      Hashset namedFV__V403 = LINK_VARIABLESET(sink__V394->context, asConstruction(term__V395)->properties->namedFreeVars);
      Hashset varFV__V404 = LINK_VARIABLESET(sink__V394->context, asConstruction(term__V395)->properties->variableFreeVars);
      UNLINK(sink__V394->context, term__V395);
      ADD_PROPERTIES(sink__V394, LINK_VARIABLESET(sink__V394->context, namedFV__V403), LINK_VARIABLESET(sink__V394->context, varFV__V404), LINK_NamedPropertyLink(sink__V394->context, namedP__V401), LINK_VariablePropertyLink(sink__V394->context, varP__V402));
      { START(sink__V394, _M_Sort__name_s1);
        COPY(sink__V394, sub__V399);COPY(sink__V394, sub__V400);END(sink__V394, _M_Sort__name_s1); }
      UNLINK_VARIABLESET(sink__V394->context, namedFV__V403); UNLINK_VARIABLESET(sink__V394->context, varFV__V404);
      UNLINK_NamedPropertyLink(sink__V394->context, namedP__V401); UNLINK_VariablePropertyLink(sink__V394->context, varP__V402);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION MapText$1. */
int conBindOffs_M_MapText_s1[] = {0 , 0 , 1};
char *nameFun_M_MapText_s1(Term term) { return  "MapText$1" ; }
struct _ConstructionDescriptor descriptor_M_MapText_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_MapText_s1), conBindOffs_M_MapText_s1, &nameFun_M_MapText_s1, &step_M_MapText_s1};

int step_M_MapText_s1(Sink sink__V405, Term term__V406)
{
  int term__V406_count = LINK_COUNT(term__V406); permitUnusedInt(term__V406_count);
  Term sub__V407 = FORCE(sink__V405->context, SUB(term__V406, 0));
  EnumOf_M__sList choice__V408 = (IS_VARIABLE_USE(sub__V407) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V407));
  switch (choice__V408)
  {
    case Data_M__sCons: { /* Function DEFS-MapText-1$MapText$1$$Cons case $Cons */
      ASSERT(sink__V405->context, !strcmp(SYMBOL(term__V406),  "MapText$1" ));
      Term sub__V409 = SUB(term__V406, 0); permitUnusedTerm(sub__V409); int sub__V409_count = term__V406_count*LINK_COUNT(sub__V409); permitUnusedInt(sub__V409_count);
      ASSERT(sink__V405->context, !strcmp(SYMBOL(sub__V409),  "$Cons" ));
      Term sub__V410 = LINK(sink__V405->context, SUB(sub__V409, 0)); int sub__V410_count = sub__V409_count*LINK_COUNT(sub__V410); permitUnusedInt(sub__V410_count);
      /* sub__V410 = &#0-0 */
      Term sub__V411 = LINK(sink__V405->context, SUB(sub__V409, 1)); int sub__V411_count = sub__V409_count*LINK_COUNT(sub__V411); permitUnusedInt(sub__V411_count);
      /* sub__V411 = &#0-1 */
      Variable x__V412 = BINDER(term__V406,1,0); if (term__V406_count <= 1) UNBIND(x__V412);
      Term sub__V413 = LINK(sink__V405->context, SUB(term__V406, 1)); int sub__V413_count = term__V406_count*LINK_COUNT(sub__V413); permitUnusedInt(sub__V413_count);
      CRSX_CHECK_SORT(sink__V405->context, sub__V413, &sort_M_Reified_xVariable); /* sub__V413 = &#2 */
      
      NamedPropertyLink namedP__V414 = LINK_NamedPropertyLink(sink__V405->context, NAMED_PROPERTIES(term__V406));
      VariablePropertyLink varP__V415 = LINK_VariablePropertyLink(sink__V405->context, VARIABLE_PROPERTIES(term__V406));
      Hashset namedFV__V416 = LINK_VARIABLESET(sink__V405->context, asConstruction(term__V406)->properties->namedFreeVars);
      Hashset varFV__V417 = LINK_VARIABLESET(sink__V405->context, asConstruction(term__V406)->properties->variableFreeVars);
      UNLINK(sink__V405->context, term__V406);
      ADD_PROPERTIES(sink__V405, LINK_VARIABLESET(sink__V405->context, namedFV__V416), LINK_VARIABLESET(sink__V405->context, varFV__V417), LINK_NamedPropertyLink(sink__V405->context, namedP__V414), LINK_VariablePropertyLink(sink__V405->context, varP__V415));
      { START(sink__V405, _M_MapText_s2);
        COPY(sink__V405, sub__V410);COPY(sink__V405, sub__V411);{ if (!IS_BOUND(x__V412)) { REBIND(x__V412);
            Variable binds__V418[1] = {x__V412}; BINDS(sink__V405, 1, binds__V418);
            COPY(sink__V405, sub__V413); /* REUSED SUBSTITUTION */  }
          else { Variable b__V419 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V405->context,"b__V419");
            Variable binds__V420[1] = {b__V419}; BINDS(sink__V405, 1, binds__V420);
            {
              Term arg__V421;
              { Sink buf__V422 = ALLOCA_BUFFER(sink__V405->context);
                USE(buf__V422, b__V419); arg__V421 = BUFFER_TERM(buf__V422); FREE_BUFFER(buf__V422); }
              Variable vars__V423[1] = {x__V412};
              Term args__V424[1] = {arg__V421};
              struct _SubstitutionFrame substitution__V425 = {NULL, 0, 1, vars__V423, args__V424, NULL};
              SUBSTITUTE(sink__V405, sub__V413, &substitution__V425); }
                }
           }
        END(sink__V405, _M_MapText_s2); }
      UNLINK_VARIABLESET(sink__V405->context, namedFV__V416); UNLINK_VARIABLESET(sink__V405->context, varFV__V417);
      UNLINK_NamedPropertyLink(sink__V405->context, namedP__V414); UNLINK_VariablePropertyLink(sink__V405->context, varP__V415);
      
      return 1;
    break; } case Data_M__sNil: { /* Function DEFS-MapText-2$MapText$1$$Nil case $Nil */
      ASSERT(sink__V405->context, !strcmp(SYMBOL(term__V406),  "MapText$1" ));
      Term sub__V426 = SUB(term__V406, 0); permitUnusedTerm(sub__V426); int sub__V426_count = term__V406_count*LINK_COUNT(sub__V426); permitUnusedInt(sub__V426_count);
      ASSERT(sink__V405->context, !strcmp(SYMBOL(sub__V426),  "$Nil" ));
      Variable x__V427 = BINDER(term__V406,1,0); if (term__V406_count <= 1) UNBIND(x__V427);
      Term sub__V428 = LINK(sink__V405->context, SUB(term__V406, 1)); int sub__V428_count = term__V406_count*LINK_COUNT(sub__V428); permitUnusedInt(sub__V428_count);
      CRSX_CHECK_SORT(sink__V405->context, sub__V428, &sort_M_Reified_xVariable); /* sub__V428 = &#0 */
      
      NamedPropertyLink namedP__V429 = LINK_NamedPropertyLink(sink__V405->context, NAMED_PROPERTIES(term__V406));
      VariablePropertyLink varP__V430 = LINK_VariablePropertyLink(sink__V405->context, VARIABLE_PROPERTIES(term__V406));
      Hashset namedFV__V431 = LINK_VARIABLESET(sink__V405->context, asConstruction(term__V406)->properties->namedFreeVars);
      Hashset varFV__V432 = LINK_VARIABLESET(sink__V405->context, asConstruction(term__V406)->properties->variableFreeVars);
      UNLINK(sink__V405->context, term__V406);
      ADD_PROPERTIES(sink__V405, LINK_VARIABLESET(sink__V405->context, namedFV__V431), LINK_VARIABLESET(sink__V405->context, varFV__V432), LINK_NamedPropertyLink(sink__V405->context, namedP__V429), LINK_VariablePropertyLink(sink__V405->context, varP__V430));
      { START(sink__V405, _M_MapText_s3);
        { if (!IS_BOUND(x__V427)) { REBIND(x__V427);
            Variable binds__V433[1] = {x__V427}; BINDS(sink__V405, 1, binds__V433);
            COPY(sink__V405, sub__V428); /* REUSED SUBSTITUTION */  }
          else { Variable b__V434 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V405->context,"b__V434");
            Variable binds__V435[1] = {b__V434}; BINDS(sink__V405, 1, binds__V435);
            {
              Term arg__V436;
              { Sink buf__V437 = ALLOCA_BUFFER(sink__V405->context);
                USE(buf__V437, b__V434); arg__V436 = BUFFER_TERM(buf__V437); FREE_BUFFER(buf__V437); }
              Variable vars__V438[1] = {x__V427};
              Term args__V439[1] = {arg__V436};
              struct _SubstitutionFrame substitution__V440 = {NULL, 0, 1, vars__V438, args__V439, NULL};
              SUBSTITUTE(sink__V405, sub__V428, &substitution__V440); }
                }
           }
        END(sink__V405, _M_MapText_s3); }
      UNLINK_VARIABLESET(sink__V405->context, namedFV__V431); UNLINK_VARIABLESET(sink__V405->context, varFV__V432);
      UNLINK_NamedPropertyLink(sink__V405->context, namedP__V429); UNLINK_VariablePropertyLink(sink__V405->context, varP__V430);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION MapText$2. */
int conBindOffs_M_MapText_s2[] = {0 , 0 , 0 , 1};
char *nameFun_M_MapText_s2(Term term) { return  "MapText$2" ; }
struct _ConstructionDescriptor descriptor_M_MapText_s2 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_MapText_s2), conBindOffs_M_MapText_s2, &nameFun_M_MapText_s2, &step_M_MapText_s2};

int step_M_MapText_s2(Sink sink__V441, Term term__V442)
{
  int term__V442_count = LINK_COUNT(term__V442); permitUnusedInt(term__V442_count);
  do {
    /* Contraction rule DEFS-MapText-1. */
    ASSERT(sink__V441->context, !strcmp(SYMBOL(term__V442),  "MapText$2" ));
    Term sub__V443 = LINK(sink__V441->context, SUB(term__V442, 0)); int sub__V443_count = term__V442_count*LINK_COUNT(sub__V443); permitUnusedInt(sub__V443_count);
    /* sub__V443 = &#21 */
    Term sub__V444 = LINK(sink__V441->context, SUB(term__V442, 1)); int sub__V444_count = term__V442_count*LINK_COUNT(sub__V444); permitUnusedInt(sub__V444_count);
    /* sub__V444 = &#22 */
    Variable x__V445 = BINDER(term__V442,2,0); if (term__V442_count <= 1) UNBIND(x__V445);
    Term sub__V446 = LINK(sink__V441->context, SUB(term__V442, 2)); int sub__V446_count = term__V442_count*LINK_COUNT(sub__V446); permitUnusedInt(sub__V446_count);
    CRSX_CHECK_SORT(sink__V441->context, sub__V446, &sort_M_Reified_xVariable); UNLINK_SUB(sink__V441->context, term__V442,  2); NORMALIZE(sink__V441->context, sub__V446); SUB(term__V442,  2) = LINK(sink__V441->context, sub__V446);
    /* sub__V446 = &#1 */
    
    NamedPropertyLink namedP__V447 = LINK_NamedPropertyLink(sink__V441->context, NAMED_PROPERTIES(term__V442));
    VariablePropertyLink varP__V448 = LINK_VariablePropertyLink(sink__V441->context, VARIABLE_PROPERTIES(term__V442));
    Hashset namedFV__V449 = LINK_VARIABLESET(sink__V441->context, asConstruction(term__V442)->properties->namedFreeVars);
    Hashset varFV__V450 = LINK_VARIABLESET(sink__V441->context, asConstruction(term__V442)->properties->variableFreeVars);
    UNLINK(sink__V441->context, term__V442);
    { START(sink__V441, _M__sTextCons);
      { START(sink__V441, _M__sTextEmbed);
        { START(sink__V441, _M_AsText);
          {
            Term arg__V451;
            { Sink buf__V452 = ALLOCA_BUFFER(sink__V441->context);
              COPY(buf__V452, sub__V443);arg__V451 = BUFFER_TERM(buf__V452); FREE_BUFFER(buf__V452); }
            Variable vars__V453[1] = {x__V445};
            Term args__V454[1] = {arg__V451};
            struct _SubstitutionFrame substitution__V455 = {NULL, 0, 1, vars__V453, args__V454, NULL};
            SUBSTITUTE(sink__V441, LINK(sink__V441->context,sub__V446), &substitution__V455); }
          END(sink__V441, _M_AsText); }
        END(sink__V441, _M__sTextEmbed); }
      { START(sink__V441, _M__sTextCons);
        { START(sink__V441, _M__sTextEmbed);
          { START(sink__V441, _M_AsText);
            { START(sink__V441, _M_MapText_s1);
              COPY(sink__V441, sub__V444);{ Variable x__V456 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V441->context,"x__V456");
                Variable binds__V457[1] = {x__V456}; BINDS(sink__V441, 1, binds__V457);
                {
                  Term arg__V458;
                  { Sink buf__V459 = ALLOCA_BUFFER(sink__V441->context);
                    USE(buf__V459, x__V456); arg__V458 = BUFFER_TERM(buf__V459); FREE_BUFFER(buf__V459); }
                  Variable vars__V460[1] = {x__V445};
                  Term args__V461[1] = {arg__V458};
                  struct _SubstitutionFrame substitution__V462 = {NULL, 0, 1, vars__V460, args__V461, NULL};
                  SUBSTITUTE(sink__V441, sub__V446, &substitution__V462); }
                 }
              END(sink__V441, _M_MapText_s1); }
            END(sink__V441, _M_AsText); }
          END(sink__V441, _M__sTextEmbed); }
        { START(sink__V441, _M__sTextNil);
          END(sink__V441, _M__sTextNil); }
        END(sink__V441, _M__sTextCons); }
      END(sink__V441, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V441->context, namedFV__V449); UNLINK_VARIABLESET(sink__V441->context, varFV__V450);
    UNLINK_NamedPropertyLink(sink__V441->context, namedP__V447); UNLINK_VariablePropertyLink(sink__V441->context, varP__V448);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION MapText$3. */
int conBindOffs_M_MapText_s3[] = {0 , 1};
char *nameFun_M_MapText_s3(Term term) { return  "MapText$3" ; }
struct _ConstructionDescriptor descriptor_M_MapText_s3 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_MapText_s3), conBindOffs_M_MapText_s3, &nameFun_M_MapText_s3, &step_M_MapText_s3};

int step_M_MapText_s3(Sink sink__V463, Term term__V464)
{
  int term__V464_count = LINK_COUNT(term__V464); permitUnusedInt(term__V464_count);
  do {
    /* Contraction rule DEFS-MapText-2. */
    ASSERT(sink__V463->context, !strcmp(SYMBOL(term__V464),  "MapText$3" ));
    Variable x__V465 = BINDER(term__V464,0,0); if (term__V464_count <= 1) UNBIND(x__V465);
    Term sub__V466 = SUB(term__V464, 0); permitUnusedTerm(sub__V466); int sub__V466_count = term__V464_count*LINK_COUNT(sub__V466); permitUnusedInt(sub__V466_count);
    CRSX_CHECK_SORT(sink__V463->context, sub__V466, &sort_M_Reified_xVariable); /* sub__V466 = &#1 */
    
    NamedPropertyLink namedP__V467 = LINK_NamedPropertyLink(sink__V463->context, NAMED_PROPERTIES(term__V464));
    VariablePropertyLink varP__V468 = LINK_VariablePropertyLink(sink__V463->context, VARIABLE_PROPERTIES(term__V464));
    Hashset namedFV__V469 = LINK_VARIABLESET(sink__V463->context, asConstruction(term__V464)->properties->namedFreeVars);
    Hashset varFV__V470 = LINK_VARIABLESET(sink__V463->context, asConstruction(term__V464)->properties->variableFreeVars);
    UNLINK(sink__V463->context, term__V464);
    { START(sink__V463, _M__sTextNil); END(sink__V463, _M__sTextNil); }
    UNLINK_VARIABLESET(sink__V463->context, namedFV__V469); UNLINK_VARIABLESET(sink__V463->context, varFV__V470);
    UNLINK_NamedPropertyLink(sink__V463->context, namedP__V467); UNLINK_VariablePropertyLink(sink__V463->context, varP__V468);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION EventConstructor. */
int conBindOffs_M_EventConstructor[] = {0 , 0};
char *nameFun_M_EventConstructor(Term term) { return  "EventConstructor" ; }
struct _ConstructionDescriptor descriptor_M_EventConstructor = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_EventConstructor), conBindOffs_M_EventConstructor, &nameFun_M_EventConstructor, &step_M_EventConstructor};

int step_M_EventConstructor(Sink sink__V471, Term term__V472)
{
  int term__V472_count = LINK_COUNT(term__V472); permitUnusedInt(term__V472_count);
  do {
    /* Contraction rule DEFS-EventConstructor-1. */
    ASSERT(sink__V471->context, !strcmp(SYMBOL(term__V472),  "EventConstructor" ));
    Term sub__V473 = LINK(sink__V471->context, SUB(term__V472, 0)); int sub__V473_count = term__V472_count*LINK_COUNT(sub__V473); permitUnusedInt(sub__V473_count);
    /* sub__V473 = &#1 */
    
    NamedPropertyLink namedP__V474 = LINK_NamedPropertyLink(sink__V471->context, NAMED_PROPERTIES(term__V472));
    VariablePropertyLink varP__V475 = LINK_VariablePropertyLink(sink__V471->context, VARIABLE_PROPERTIES(term__V472));
    Hashset namedFV__V476 = LINK_VARIABLESET(sink__V471->context, asConstruction(term__V472)->properties->namedFreeVars);
    Hashset varFV__V477 = LINK_VARIABLESET(sink__V471->context, asConstruction(term__V472)->properties->variableFreeVars);
    UNLINK(sink__V471->context, term__V472);
    { START(sink__V471, _M_MANGLE);
      COPY(sink__V471, sub__V473);END(sink__V471, _M_MANGLE); }
    UNLINK_VARIABLESET(sink__V471->context, namedFV__V476); UNLINK_VARIABLESET(sink__V471->context, varFV__V477);
    UNLINK_NamedPropertyLink(sink__V471->context, namedP__V474); UNLINK_VariablePropertyLink(sink__V471->context, varP__V475);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION MetaVar. */
int conBindOffs_M_MetaVar[] = {0 , 0};
char *nameFun_M_MetaVar(Term term) { return  "MetaVar" ; }
struct _ConstructionDescriptor descriptor_M_MetaVar = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_MetaVar), conBindOffs_M_MetaVar, &nameFun_M_MetaVar, &step_M_MetaVar};

int step_M_MetaVar(Sink sink__V478, Term term__V479)
{
  int term__V479_count = LINK_COUNT(term__V479); permitUnusedInt(term__V479_count);
  do {
    /* Contraction rule DEFS-MetaVar-1. */
    ASSERT(sink__V478->context, !strcmp(SYMBOL(term__V479),  "MetaVar" ));
    Term sub__V480 = LINK(sink__V478->context, SUB(term__V479, 0)); int sub__V480_count = term__V479_count*LINK_COUNT(sub__V480); permitUnusedInt(sub__V480_count);
    UNLINK_SUB(sink__V478->context, term__V479,  0); NORMALIZE(sink__V478->context, sub__V480); SUB(term__V479,  0) = LINK(sink__V478->context, sub__V480);
    /* sub__V480 = &#1 */
    
    NamedPropertyLink namedP__V481 = LINK_NamedPropertyLink(sink__V478->context, NAMED_PROPERTIES(term__V479));
    VariablePropertyLink varP__V482 = LINK_VariablePropertyLink(sink__V478->context, VARIABLE_PROPERTIES(term__V479));
    Hashset namedFV__V483 = LINK_VARIABLESET(sink__V478->context, asConstruction(term__V479)->properties->namedFreeVars);
    Hashset varFV__V484 = LINK_VARIABLESET(sink__V478->context, asConstruction(term__V479)->properties->variableFreeVars);
    UNLINK(sink__V478->context, term__V479);
    ADD_PROPERTIES(sink__V478, LINK_VARIABLESET(sink__V478->context, namedFV__V483), LINK_VARIABLESET(sink__V478->context, varFV__V484), LINK_NamedPropertyLink(sink__V478->context, namedP__V481), LINK_VariablePropertyLink(sink__V478->context, varP__V482));
    { START(sink__V478, _M_MetaVar2);
      { Term term__V485;
        { Term key__V486;
          char *sub__V487[2]; size_t sublength__V488[2]; size_t length__V489 = 0;
          length__V489 += (sublength__V488[0] = strlen(sub__V487[0] =  "MetaVar$" ));
          FORCE(sink__V478->context, sub__V480); LINK(sink__V478->context, sub__V480);
          length__V489 += (sublength__V488[1] = strlen(sub__V487[1] = SYMBOL(sub__V480)));
          UNLINK(sink__V478->context, sub__V480);  { char *str__V490 = ALLOCA(sink__V478->context, length__V489+1), *p__V491 = str__V490;
            int i; for (i = 0; i < 2; ++i) { memcpy(p__V491, sub__V487[i], sublength__V488[i]); p__V491 += sublength__V488[i]; }
            *p__V491 = '\0';
            ASSERT(sink__V478->context, strlen(str__V490) == length__V489);
            key__V486 = makeStringLiteral(sink__V478->context, str__V490);
            }
          Term pp__V492 = DPROPERTY(sink__V478->context, namedP__V481, varP__V482, key__V486);UNLINK(sink__V478->context, key__V486); 
          if (pp__V492) term__V485 = LINK(sink__V478->context, pp__V492);
          else {{ Sink buf__V493 = ALLOCA_BUFFER(sink__V478->context);
              { START(buf__V493, _M_STRING_xVALUE);
                { char *str__V494;
                  { char *sub__V495[2]; size_t sublength__V496[2]; size_t length__V497 = 0;
                    length__V497 += (sublength__V496[0] = strlen(sub__V495[0] =  "m" ));
                    FORCE(buf__V493->context, sub__V480); LINK(buf__V493->context, sub__V480);
                    { char *s__V498 = makeMangled(buf__V493->context, SYMBOL(sub__V480));
                      length__V497 += (sublength__V496[1] = strlen(sub__V495[1] = s__V498));
                       UNLINK(buf__V493->context, sub__V480);  UNLINK(buf__V493->context, sub__V480); { char *str__V499 = ALLOCATE(buf__V493->context, length__V497+1), *p__V500 = str__V499;
                        int i; for (i = 0; i < 2; ++i) { memcpy(p__V500, sub__V495[i], sublength__V496[i]); p__V500 += sublength__V496[i]; }
                        *p__V500 = '\0';
                        ASSERT(buf__V493->context, strlen(str__V499) == length__V497);
                        str__V494 = str__V499; }
                      }
                     }
                  LITERALU(buf__V493, str__V494); }
                END(buf__V493, _M_STRING_xVALUE); }
              term__V485 = BUFFER_TERM(buf__V493); FREE_BUFFER(buf__V493); }
            }
        }
        COPY(sink__V478, term__V485); /*CONSERVATIVE*/ }
      END(sink__V478, _M_MetaVar2); }
    UNLINK_VARIABLESET(sink__V478->context, namedFV__V483); UNLINK_VARIABLESET(sink__V478->context, varFV__V484);
    UNLINK_NamedPropertyLink(sink__V478->context, namedP__V481); UNLINK_VariablePropertyLink(sink__V478->context, varP__V482);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DINTEGER$1. */
int conBindOffs_M_DINTEGER_s1[] = {0 , 0};
char *nameFun_M_DINTEGER_s1(Term term) { return  "DINTEGER$1" ; }
struct _ConstructionDescriptor descriptor_M_DINTEGER_s1 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_DINTEGER_s1), conBindOffs_M_DINTEGER_s1, &nameFun_M_DINTEGER_s1, &step_M_DINTEGER_s1};

int step_M_DINTEGER_s1(Sink sink__V501, Term term__V502)
{
  int term__V502_count = LINK_COUNT(term__V502); permitUnusedInt(term__V502_count);
  do {
    /* Contraction rule DEFS-DINTEGER-1. */
    ASSERT(sink__V501->context, !strcmp(SYMBOL(term__V502),  "DINTEGER$1" ));
    Term sub__V503 = LINK(sink__V501->context, SUB(term__V502, 0)); int sub__V503_count = term__V502_count*LINK_COUNT(sub__V503); permitUnusedInt(sub__V503_count);
    UNLINK_SUB(sink__V501->context, term__V502,  0); NORMALIZE(sink__V501->context, sub__V503); SUB(term__V502,  0) = LINK(sink__V501->context, sub__V503);
    /* sub__V503 = &#2 */
    
    NamedPropertyLink namedP__V504 = LINK_NamedPropertyLink(sink__V501->context, NAMED_PROPERTIES(term__V502));
    VariablePropertyLink varP__V505 = LINK_VariablePropertyLink(sink__V501->context, VARIABLE_PROPERTIES(term__V502));
    Hashset namedFV__V506 = LINK_VARIABLESET(sink__V501->context, asConstruction(term__V502)->properties->namedFreeVars);
    Hashset varFV__V507 = LINK_VARIABLESET(sink__V501->context, asConstruction(term__V502)->properties->variableFreeVars);
    UNLINK(sink__V501->context, term__V502);
    { START(sink__V501, _M__sTextCons);
      { START(sink__V501, _M__sTextChars);
        { char *str__V508;
          {double num__V509; char *str__V510;
            num__V509 = DOUBLE(sub__V503); snprintf(str__V510 = ALLOCA(sink__V501->context, (size_t) 32), (size_t) 31, "%G", num__V509);
            { size_t z__V511 = strlen(str__V510) + 1; memcpy(str__V508 = ALLOCATE(sink__V501->context, z__V511), str__V510, z__V511); }
             }
          LITERALU(sink__V501, str__V508); }
        END(sink__V501, _M__sTextChars); }
      { START(sink__V501, _M__sTextNil);
        END(sink__V501, _M__sTextNil); }
      END(sink__V501, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V501->context, namedFV__V506); UNLINK_VARIABLESET(sink__V501->context, varFV__V507);
    UNLINK_NamedPropertyLink(sink__V501->context, namedP__V504); UNLINK_VariablePropertyLink(sink__V501->context, varP__V505);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DDescriptor$1. */
int conBindOffs_M_DDescriptor_s1[] = {0 , 0};
char *nameFun_M_DDescriptor_s1(Term term) { return  "DDescriptor$1" ; }
struct _ConstructionDescriptor descriptor_M_DDescriptor_s1 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_DDescriptor_s1), conBindOffs_M_DDescriptor_s1, &nameFun_M_DDescriptor_s1, &step_M_DDescriptor_s1};

int step_M_DDescriptor_s1(Sink sink__V512, Term term__V513)
{
  int term__V513_count = LINK_COUNT(term__V513); permitUnusedInt(term__V513_count);
  do {
    /* Contraction rule DEFS-DDescriptor-1. */
    ASSERT(sink__V512->context, !strcmp(SYMBOL(term__V513),  "DDescriptor$1" ));
    Term sub__V514 = LINK(sink__V512->context, SUB(term__V513, 0)); int sub__V514_count = term__V513_count*LINK_COUNT(sub__V514); permitUnusedInt(sub__V514_count);
    /* sub__V514 = &#2 */
    
    NamedPropertyLink namedP__V515 = LINK_NamedPropertyLink(sink__V512->context, NAMED_PROPERTIES(term__V513));
    VariablePropertyLink varP__V516 = LINK_VariablePropertyLink(sink__V512->context, VARIABLE_PROPERTIES(term__V513));
    Hashset namedFV__V517 = LINK_VARIABLESET(sink__V512->context, asConstruction(term__V513)->properties->namedFreeVars);
    Hashset varFV__V518 = LINK_VARIABLESET(sink__V512->context, asConstruction(term__V513)->properties->variableFreeVars);
    UNLINK(sink__V512->context, term__V513);
    { START(sink__V512, _M__sTextCons);
      { START(sink__V512, _M__sTextChars);
        LITERAL(sink__V512,  "descriptor" ); END(sink__V512, _M__sTextChars); }
      { START(sink__V512, _M__sTextCons);
        { START(sink__V512, _M__sTextEmbed);
          { START(sink__V512, _M_AsText);
            { START(sink__V512, _M_MANGLE);
              COPY(sink__V512, sub__V514);END(sink__V512, _M_MANGLE); }
            END(sink__V512, _M_AsText); }
          END(sink__V512, _M__sTextEmbed); }
        { START(sink__V512, _M__sTextNil);
          END(sink__V512, _M__sTextNil); }
        END(sink__V512, _M__sTextCons); }
      END(sink__V512, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V512->context, namedFV__V517); UNLINK_VARIABLESET(sink__V512->context, varFV__V518);
    UNLINK_NamedPropertyLink(sink__V512->context, namedP__V515); UNLINK_VariablePropertyLink(sink__V512->context, varP__V516);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION PromiscuityString. */
int conBindOffs_M_PromiscuityString[] = {0 , 0};
char *nameFun_M_PromiscuityString(Term term) { return  "PromiscuityString" ; }
struct _ConstructionDescriptor descriptor_M_PromiscuityString = {NULL, 0, 1, sizeof(STRUCT_Con_M_PromiscuityString), conBindOffs_M_PromiscuityString, &nameFun_M_PromiscuityString, &step_M_PromiscuityString};

int step_M_PromiscuityString(Sink sink__V519, Term term__V520)
{
  int term__V520_count = LINK_COUNT(term__V520); permitUnusedInt(term__V520_count);
  Term sub__V521 = FORCE(sink__V519->context, SUB(term__V520, 0));
  EnumOf_M_Reified_xPromiscuity choice__V522 = (IS_VARIABLE_USE(sub__V521) ? VarOf_M_Reified_xPromiscuity : (EnumOf_M_Reified_xPromiscuity) TAG(sub__V521));
  switch (choice__V522)
  {
    case Data_M_LINEAR: { /* Function DEFS-PromiscuityString-1$PromiscuityString$LINEAR case LINEAR */
      ASSERT(sink__V519->context, !strcmp(SYMBOL(term__V520),  "PromiscuityString" ));
      Term sub__V523 = SUB(term__V520, 0); permitUnusedTerm(sub__V523); int sub__V523_count = term__V520_count*LINK_COUNT(sub__V523); permitUnusedInt(sub__V523_count);
      CRSX_CHECK_SORT(sink__V519->context, sub__V523, &sort_M_Reified_xPromiscuity); ASSERT(sink__V519->context, !strcmp(SYMBOL(sub__V523),  "LINEAR" ));
      
      NamedPropertyLink namedP__V524 = LINK_NamedPropertyLink(sink__V519->context, NAMED_PROPERTIES(term__V520));
      VariablePropertyLink varP__V525 = LINK_VariablePropertyLink(sink__V519->context, VARIABLE_PROPERTIES(term__V520));
      Hashset namedFV__V526 = LINK_VARIABLESET(sink__V519->context, asConstruction(term__V520)->properties->namedFreeVars);
      Hashset varFV__V527 = LINK_VARIABLESET(sink__V519->context, asConstruction(term__V520)->properties->variableFreeVars);
      UNLINK(sink__V519->context, term__V520);
      ADD_PROPERTIES(sink__V519, LINK_VARIABLESET(sink__V519->context, namedFV__V526), LINK_VARIABLESET(sink__V519->context, varFV__V527), LINK_NamedPropertyLink(sink__V519->context, namedP__V524), LINK_VariablePropertyLink(sink__V519->context, varP__V525));
      { START(sink__V519, _M_PromiscuityString_s1);
        END(sink__V519, _M_PromiscuityString_s1); }
      UNLINK_VARIABLESET(sink__V519->context, namedFV__V526); UNLINK_VARIABLESET(sink__V519->context, varFV__V527);
      UNLINK_NamedPropertyLink(sink__V519->context, namedP__V524); UNLINK_VariablePropertyLink(sink__V519->context, varP__V525);
      
      return 1;
    break; } case Data_M_PROMISCUOUS: { /* Function DEFS-PromiscuityString-2$PromiscuityString$PROMISCUOUS case PROMISCUOUS */
      ASSERT(sink__V519->context, !strcmp(SYMBOL(term__V520),  "PromiscuityString" ));
      Term sub__V528 = SUB(term__V520, 0); permitUnusedTerm(sub__V528); int sub__V528_count = term__V520_count*LINK_COUNT(sub__V528); permitUnusedInt(sub__V528_count);
      CRSX_CHECK_SORT(sink__V519->context, sub__V528, &sort_M_Reified_xPromiscuity); ASSERT(sink__V519->context, !strcmp(SYMBOL(sub__V528),  "PROMISCUOUS" ));
      
      NamedPropertyLink namedP__V529 = LINK_NamedPropertyLink(sink__V519->context, NAMED_PROPERTIES(term__V520));
      VariablePropertyLink varP__V530 = LINK_VariablePropertyLink(sink__V519->context, VARIABLE_PROPERTIES(term__V520));
      Hashset namedFV__V531 = LINK_VARIABLESET(sink__V519->context, asConstruction(term__V520)->properties->namedFreeVars);
      Hashset varFV__V532 = LINK_VARIABLESET(sink__V519->context, asConstruction(term__V520)->properties->variableFreeVars);
      UNLINK(sink__V519->context, term__V520);
      ADD_PROPERTIES(sink__V519, LINK_VARIABLESET(sink__V519->context, namedFV__V531), LINK_VARIABLESET(sink__V519->context, varFV__V532), LINK_NamedPropertyLink(sink__V519->context, namedP__V529), LINK_VariablePropertyLink(sink__V519->context, varP__V530));
      { START(sink__V519, _M_PromiscuityString_s2);
        END(sink__V519, _M_PromiscuityString_s2); }
      UNLINK_VARIABLESET(sink__V519->context, namedFV__V531); UNLINK_VARIABLESET(sink__V519->context, varFV__V532);
      UNLINK_NamedPropertyLink(sink__V519->context, namedP__V529); UNLINK_VariablePropertyLink(sink__V519->context, varP__V530);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION MANGLE. */
int conBindOffs_M_MANGLE[] = {0 , 0};
char *nameFun_M_MANGLE(Term term) { return  "MANGLE" ; }
struct _ConstructionDescriptor descriptor_M_MANGLE = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_MANGLE), conBindOffs_M_MANGLE, &nameFun_M_MANGLE, &step_M_MANGLE};

int step_M_MANGLE(Sink sink__V533, Term term__V534)
{
  int term__V534_count = LINK_COUNT(term__V534); permitUnusedInt(term__V534_count);
  do {
    /* Contraction rule DEFS-MANGLE-1. */
    ASSERT(sink__V533->context, !strcmp(SYMBOL(term__V534),  "MANGLE" ));
    Term sub__V535 = LINK(sink__V533->context, SUB(term__V534, 0)); int sub__V535_count = term__V534_count*LINK_COUNT(sub__V535); permitUnusedInt(sub__V535_count);
    UNLINK_SUB(sink__V533->context, term__V534,  0); NORMALIZE(sink__V533->context, sub__V535); SUB(term__V534,  0) = LINK(sink__V533->context, sub__V535);
    /* sub__V535 = &#1 */
    
    NamedPropertyLink namedP__V536 = LINK_NamedPropertyLink(sink__V533->context, NAMED_PROPERTIES(term__V534));
    VariablePropertyLink varP__V537 = LINK_VariablePropertyLink(sink__V533->context, VARIABLE_PROPERTIES(term__V534));
    Hashset namedFV__V538 = LINK_VARIABLESET(sink__V533->context, asConstruction(term__V534)->properties->namedFreeVars);
    Hashset varFV__V539 = LINK_VARIABLESET(sink__V533->context, asConstruction(term__V534)->properties->variableFreeVars);
    UNLINK(sink__V533->context, term__V534);
    { START(sink__V533, _M__sTextCons);
      { START(sink__V533, _M__sTextChars);
        { char *str__V540;
          FORCE(sink__V533->context, sub__V535); LINK(sink__V533->context, sub__V535);
          { char *s__V541 = makeMangled(sink__V533->context, SYMBOL(sub__V535));
            { size_t z__V542 = strlen(s__V541) + 1; memcpy(str__V540 = ALLOCATE(sink__V533->context, z__V542), s__V541, z__V542);  UNLINK(sink__V533->context, sub__V535);  UNLINK(sink__V533->context, sub__V535); }
            }
          LITERALU(sink__V533, str__V540); }
        END(sink__V533, _M__sTextChars); }
      { START(sink__V533, _M__sTextNil);
        END(sink__V533, _M__sTextNil); }
      END(sink__V533, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V533->context, namedFV__V538); UNLINK_VARIABLESET(sink__V533->context, varFV__V539);
    UNLINK_NamedPropertyLink(sink__V533->context, namedP__V536); UNLINK_VariablePropertyLink(sink__V533->context, varP__V537);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION NameFun. */
int conBindOffs_M_NameFun[] = {0 , 0};
char *nameFun_M_NameFun(Term term) { return  "NameFun" ; }
struct _ConstructionDescriptor descriptor_M_NameFun = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_NameFun), conBindOffs_M_NameFun, &nameFun_M_NameFun, &step_M_NameFun};

int step_M_NameFun(Sink sink__V543, Term term__V544)
{
  int term__V544_count = LINK_COUNT(term__V544); permitUnusedInt(term__V544_count);
  do {
    /* Contraction rule DEFS-NameFun-1. */
    ASSERT(sink__V543->context, !strcmp(SYMBOL(term__V544),  "NameFun" ));
    Term sub__V545 = LINK(sink__V543->context, SUB(term__V544, 0)); int sub__V545_count = term__V544_count*LINK_COUNT(sub__V545); permitUnusedInt(sub__V545_count);
    /* sub__V545 = &#1 */
    
    NamedPropertyLink namedP__V546 = LINK_NamedPropertyLink(sink__V543->context, NAMED_PROPERTIES(term__V544));
    VariablePropertyLink varP__V547 = LINK_VariablePropertyLink(sink__V543->context, VARIABLE_PROPERTIES(term__V544));
    Hashset namedFV__V548 = LINK_VARIABLESET(sink__V543->context, asConstruction(term__V544)->properties->namedFreeVars);
    Hashset varFV__V549 = LINK_VARIABLESET(sink__V543->context, asConstruction(term__V544)->properties->variableFreeVars);
    UNLINK(sink__V543->context, term__V544);
    { START(sink__V543, _M__sTextCons);
      { START(sink__V543, _M__sTextChars);
        LITERAL(sink__V543,  "nameFun" ); END(sink__V543, _M__sTextChars); }
      { START(sink__V543, _M__sTextCons);
        { START(sink__V543, _M__sTextEmbed);
          { START(sink__V543, _M_AsText);
            { START(sink__V543, _M_MANGLE);
              COPY(sink__V543, sub__V545);END(sink__V543, _M_MANGLE); }
            END(sink__V543, _M_AsText); }
          END(sink__V543, _M__sTextEmbed); }
        { START(sink__V543, _M__sTextNil);
          END(sink__V543, _M__sTextNil); }
        END(sink__V543, _M__sTextCons); }
      END(sink__V543, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V543->context, namedFV__V548); UNLINK_VARIABLESET(sink__V543->context, varFV__V549);
    UNLINK_NamedPropertyLink(sink__V543->context, namedP__V546); UNLINK_VariablePropertyLink(sink__V543->context, varP__V547);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DTOKEN. */
int conBindOffs_M_DTOKEN[] = {0 , 0 , 0};
char *nameFun_M_DTOKEN(Term term) { return  "DTOKEN" ; }
struct _ConstructionDescriptor descriptor_M_DTOKEN = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_DTOKEN), conBindOffs_M_DTOKEN, &nameFun_M_DTOKEN, &step_M_DTOKEN};

int step_M_DTOKEN(Sink sink__V550, Term term__V551)
{
  int term__V551_count = LINK_COUNT(term__V551); permitUnusedInt(term__V551_count);
  Term sub__V552 = FORCE(sink__V550->context, SUB(term__V551, 0));
  EnumOf_M_OK_xSORT choice__V553 = (IS_VARIABLE_USE(sub__V552) ? VarOf_M_OK_xSORT : (EnumOf_M_OK_xSORT) TAG(sub__V552));
  switch (choice__V553)
  {
    case Data_M_OK: { /* Function DEFS-DTOKEN-1$DTOKEN$OK case OK */
      ASSERT(sink__V550->context, !strcmp(SYMBOL(term__V551),  "DTOKEN" ));
      Term sub__V554 = SUB(term__V551, 0); permitUnusedTerm(sub__V554); int sub__V554_count = term__V551_count*LINK_COUNT(sub__V554); permitUnusedInt(sub__V554_count);
      CRSX_CHECK_SORT(sink__V550->context, sub__V554, &sort_M_OK_xSORT); ASSERT(sink__V550->context, !strcmp(SYMBOL(sub__V554),  "OK" ));
      Term sub__V555 = LINK(sink__V550->context, SUB(term__V551, 1)); int sub__V555_count = term__V551_count*LINK_COUNT(sub__V555); permitUnusedInt(sub__V555_count);
      /* sub__V555 = &#0 */
      
      NamedPropertyLink namedP__V556 = LINK_NamedPropertyLink(sink__V550->context, NAMED_PROPERTIES(term__V551));
      VariablePropertyLink varP__V557 = LINK_VariablePropertyLink(sink__V550->context, VARIABLE_PROPERTIES(term__V551));
      Hashset namedFV__V558 = LINK_VARIABLESET(sink__V550->context, asConstruction(term__V551)->properties->namedFreeVars);
      Hashset varFV__V559 = LINK_VARIABLESET(sink__V550->context, asConstruction(term__V551)->properties->variableFreeVars);
      UNLINK(sink__V550->context, term__V551);
      ADD_PROPERTIES(sink__V550, LINK_VARIABLESET(sink__V550->context, namedFV__V558), LINK_VARIABLESET(sink__V550->context, varFV__V559), LINK_NamedPropertyLink(sink__V550->context, namedP__V556), LINK_VariablePropertyLink(sink__V550->context, varP__V557));
      { START(sink__V550, _M_DTOKEN_s1);
        COPY(sink__V550, sub__V555);END(sink__V550, _M_DTOKEN_s1); }
      UNLINK_VARIABLESET(sink__V550->context, namedFV__V558); UNLINK_VARIABLESET(sink__V550->context, varFV__V559);
      UNLINK_NamedPropertyLink(sink__V550->context, namedP__V556); UNLINK_VariablePropertyLink(sink__V550->context, varP__V557);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION EnumTag. */
int conBindOffs_M_EnumTag[] = {0 , 0};
char *nameFun_M_EnumTag(Term term) { return  "EnumTag" ; }
struct _ConstructionDescriptor descriptor_M_EnumTag = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_EnumTag), conBindOffs_M_EnumTag, &nameFun_M_EnumTag, &step_M_EnumTag};

int step_M_EnumTag(Sink sink__V560, Term term__V561)
{
  int term__V561_count = LINK_COUNT(term__V561); permitUnusedInt(term__V561_count);
  do {
    /* Contraction rule DEFS-EnumTag-1. */
    ASSERT(sink__V560->context, !strcmp(SYMBOL(term__V561),  "EnumTag" ));
    Term sub__V562 = LINK(sink__V560->context, SUB(term__V561, 0)); int sub__V562_count = term__V561_count*LINK_COUNT(sub__V562); permitUnusedInt(sub__V562_count);
    /* sub__V562 = &#1 */
    
    NamedPropertyLink namedP__V563 = LINK_NamedPropertyLink(sink__V560->context, NAMED_PROPERTIES(term__V561));
    VariablePropertyLink varP__V564 = LINK_VariablePropertyLink(sink__V560->context, VARIABLE_PROPERTIES(term__V561));
    Hashset namedFV__V565 = LINK_VARIABLESET(sink__V560->context, asConstruction(term__V561)->properties->namedFreeVars);
    Hashset varFV__V566 = LINK_VARIABLESET(sink__V560->context, asConstruction(term__V561)->properties->variableFreeVars);
    UNLINK(sink__V560->context, term__V561);
    { START(sink__V560, _M__sTextCons);
      { START(sink__V560, _M__sTextChars);
        LITERAL(sink__V560,  "Data" ); END(sink__V560, _M__sTextChars); }
      { START(sink__V560, _M__sTextCons);
        { START(sink__V560, _M__sTextEmbed);
          { START(sink__V560, _M_AsText);
            { START(sink__V560, _M_MANGLE);
              COPY(sink__V560, sub__V562);END(sink__V560, _M_MANGLE); }
            END(sink__V560, _M_AsText); }
          END(sink__V560, _M__sTextEmbed); }
        { START(sink__V560, _M__sTextNil);
          END(sink__V560, _M__sTextNil); }
        END(sink__V560, _M__sTextCons); }
      END(sink__V560, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V560->context, namedFV__V565); UNLINK_VARIABLESET(sink__V560->context, varFV__V566);
    UNLINK_NamedPropertyLink(sink__V560->context, namedP__V563); UNLINK_VariablePropertyLink(sink__V560->context, varP__V564);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Struct. */
int conBindOffs_M_Struct[] = {0 , 0};
char *nameFun_M_Struct(Term term) { return  "Struct" ; }
struct _ConstructionDescriptor descriptor_M_Struct = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_Struct), conBindOffs_M_Struct, &nameFun_M_Struct, &step_M_Struct};

int step_M_Struct(Sink sink__V567, Term term__V568)
{
  int term__V568_count = LINK_COUNT(term__V568); permitUnusedInt(term__V568_count);
  do {
    /* Contraction rule DEFS-Struct-1. */
    ASSERT(sink__V567->context, !strcmp(SYMBOL(term__V568),  "Struct" ));
    Term sub__V569 = LINK(sink__V567->context, SUB(term__V568, 0)); int sub__V569_count = term__V568_count*LINK_COUNT(sub__V569); permitUnusedInt(sub__V569_count);
    /* sub__V569 = &#1 */
    
    NamedPropertyLink namedP__V570 = LINK_NamedPropertyLink(sink__V567->context, NAMED_PROPERTIES(term__V568));
    VariablePropertyLink varP__V571 = LINK_VariablePropertyLink(sink__V567->context, VARIABLE_PROPERTIES(term__V568));
    Hashset namedFV__V572 = LINK_VARIABLESET(sink__V567->context, asConstruction(term__V568)->properties->namedFreeVars);
    Hashset varFV__V573 = LINK_VARIABLESET(sink__V567->context, asConstruction(term__V568)->properties->variableFreeVars);
    UNLINK(sink__V567->context, term__V568);
    { START(sink__V567, _M__sTextCons);
      { START(sink__V567, _M__sTextChars);
        LITERAL(sink__V567,  "_Con" ); END(sink__V567, _M__sTextChars); }
      { START(sink__V567, _M__sTextCons);
        { START(sink__V567, _M__sTextEmbed);
          { START(sink__V567, _M_AsText);
            { START(sink__V567, _M_MANGLE);
              COPY(sink__V567, sub__V569);END(sink__V567, _M_MANGLE); }
            END(sink__V567, _M_AsText); }
          END(sink__V567, _M__sTextEmbed); }
        { START(sink__V567, _M__sTextNil);
          END(sink__V567, _M__sTextNil); }
        END(sink__V567, _M__sTextCons); }
      END(sink__V567, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V567->context, namedFV__V572); UNLINK_VARIABLESET(sink__V567->context, varFV__V573);
    UNLINK_NamedPropertyLink(sink__V567->context, namedP__V570); UNLINK_VariablePropertyLink(sink__V567->context, varP__V571);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION BinderOffsets. */
int conBindOffs_M_BinderOffsets[] = {0 , 0};
char *nameFun_M_BinderOffsets(Term term) { return  "BinderOffsets" ; }
struct _ConstructionDescriptor descriptor_M_BinderOffsets = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_BinderOffsets), conBindOffs_M_BinderOffsets, &nameFun_M_BinderOffsets, &step_M_BinderOffsets};

int step_M_BinderOffsets(Sink sink__V574, Term term__V575)
{
  int term__V575_count = LINK_COUNT(term__V575); permitUnusedInt(term__V575_count);
  do {
    /* Contraction rule DEFS-BinderOffsets-1. */
    ASSERT(sink__V574->context, !strcmp(SYMBOL(term__V575),  "BinderOffsets" ));
    Term sub__V576 = LINK(sink__V574->context, SUB(term__V575, 0)); int sub__V576_count = term__V575_count*LINK_COUNT(sub__V576); permitUnusedInt(sub__V576_count);
    /* sub__V576 = &#1 */
    
    NamedPropertyLink namedP__V577 = LINK_NamedPropertyLink(sink__V574->context, NAMED_PROPERTIES(term__V575));
    VariablePropertyLink varP__V578 = LINK_VariablePropertyLink(sink__V574->context, VARIABLE_PROPERTIES(term__V575));
    Hashset namedFV__V579 = LINK_VARIABLESET(sink__V574->context, asConstruction(term__V575)->properties->namedFreeVars);
    Hashset varFV__V580 = LINK_VARIABLESET(sink__V574->context, asConstruction(term__V575)->properties->variableFreeVars);
    UNLINK(sink__V574->context, term__V575);
    { START(sink__V574, _M__sTextCons);
      { START(sink__V574, _M__sTextChars);
        LITERAL(sink__V574,  "conBindOffs" ); END(sink__V574, _M__sTextChars); }
      { START(sink__V574, _M__sTextCons);
        { START(sink__V574, _M__sTextEmbed);
          { START(sink__V574, _M_AsText);
            { START(sink__V574, _M_MANGLE);
              COPY(sink__V574, sub__V576);END(sink__V574, _M_MANGLE); }
            END(sink__V574, _M_AsText); }
          END(sink__V574, _M__sTextEmbed); }
        { START(sink__V574, _M__sTextNil);
          END(sink__V574, _M__sTextNil); }
        END(sink__V574, _M__sTextCons); }
      END(sink__V574, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V574->context, namedFV__V579); UNLINK_VARIABLESET(sink__V574->context, varFV__V580);
    UNLINK_NamedPropertyLink(sink__V574->context, namedP__V577); UNLINK_VariablePropertyLink(sink__V574->context, varP__V578);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION FormArguments-binder-offsets$4. */
int conBindOffs_M_FormArguments__binder__offsets_s4[] = {0 , 0};
char *nameFun_M_FormArguments__binder__offsets_s4(Term term) { return  "FormArguments-binder-offsets$4" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__offsets_s4 = {NULL, 0, 1, sizeof(STRUCT_Con_M_FormArguments__binder__offsets_s4), conBindOffs_M_FormArguments__binder__offsets_s4, &nameFun_M_FormArguments__binder__offsets_s4, &step_M_FormArguments__binder__offsets_s4};

int step_M_FormArguments__binder__offsets_s4(Sink sink__V581, Term term__V582)
{
  int term__V582_count = LINK_COUNT(term__V582); permitUnusedInt(term__V582_count);
  do {
    /* Contraction rule DEFS-FormArguments-binder-offsets-3. */
    ASSERT(sink__V581->context, !strcmp(SYMBOL(term__V582),  "FormArguments-binder-offsets$4" ));
    Term sub__V583 = SUB(term__V582, 0); permitUnusedTerm(sub__V583); int sub__V583_count = term__V582_count*LINK_COUNT(sub__V583); permitUnusedInt(sub__V583_count);
    /* sub__V583 = &#2 */
    UNLINK(sink__V581->context, term__V582);
    { START(sink__V581, _M__sNil); END(sink__V581, _M__sNil); } 
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION FormArguments-binder-offsets$1. */
int conBindOffs_M_FormArguments__binder__offsets_s1[] = {0 , 0 , 0 , 0};
char *nameFun_M_FormArguments__binder__offsets_s1(Term term) { return  "FormArguments-binder-offsets$1" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__offsets_s1 = {NULL, 0, 3, sizeof(STRUCT_Con_M_FormArguments__binder__offsets_s1), conBindOffs_M_FormArguments__binder__offsets_s1, &nameFun_M_FormArguments__binder__offsets_s1, &step_M_FormArguments__binder__offsets_s1};

int step_M_FormArguments__binder__offsets_s1(Sink sink__V584, Term term__V585)
{
  int term__V585_count = LINK_COUNT(term__V585); permitUnusedInt(term__V585_count);
  do {
    /* Contraction rule DEFS-FormArguments-binder-offsets-1$FormArguments-binder-offsets$1$FORM-BINDER. */
    ASSERT(sink__V584->context, !strcmp(SYMBOL(term__V585),  "FormArguments-binder-offsets$1" ));
    Term sub__V586 = SUB(term__V585, 0); permitUnusedTerm(sub__V586); int sub__V586_count = term__V585_count*LINK_COUNT(sub__V586); permitUnusedInt(sub__V586_count);
    FORCE(sink__V584->context, sub__V586); SUB(term__V585, 0) = sub__V586;
    if (strcmp(SYMBOL(sub__V586),  "FORM-BINDER" )) break;
    Term sub__V587 = LINK(sink__V584->context, SUB(sub__V586, 0)); int sub__V587_count = sub__V586_count*LINK_COUNT(sub__V587); permitUnusedInt(sub__V587_count);
    CRSX_CHECK_SORT(sink__V584->context, sub__V587, &sort_M_Reified_xSort); /* sub__V587 = &#0-0 */
    Variable y__V588 = BINDER(sub__V586,1,0); if (sub__V586_count <= 1) UNBIND(y__V588);
    Term sub__V589 = LINK(sink__V584->context, SUB(sub__V586, 1)); int sub__V589_count = sub__V586_count*LINK_COUNT(sub__V589); permitUnusedInt(sub__V589_count);
    CRSX_CHECK_SORT(sink__V584->context, sub__V589, &sort_M_Reified_xFormArgument); /* sub__V589 = &#0-1 */
    Term sub__V590 = LINK(sink__V584->context, SUB(term__V585, 1)); int sub__V590_count = term__V585_count*LINK_COUNT(sub__V590); permitUnusedInt(sub__V590_count);
    /* sub__V590 = &#2 */
    Term sub__V591 = LINK(sink__V584->context, SUB(term__V585, 2)); int sub__V591_count = term__V585_count*LINK_COUNT(sub__V591); permitUnusedInt(sub__V591_count);
    /* sub__V591 = &#3 */
    
    NamedPropertyLink namedP__V592 = LINK_NamedPropertyLink(sink__V584->context, NAMED_PROPERTIES(term__V585));
    VariablePropertyLink varP__V593 = LINK_VariablePropertyLink(sink__V584->context, VARIABLE_PROPERTIES(term__V585));
    Hashset namedFV__V594 = LINK_VARIABLESET(sink__V584->context, asConstruction(term__V585)->properties->namedFreeVars);
    Hashset varFV__V595 = LINK_VARIABLESET(sink__V584->context, asConstruction(term__V585)->properties->variableFreeVars);
    UNLINK(sink__V584->context, term__V585);
    ADD_PROPERTIES(sink__V584, LINK_VARIABLESET(sink__V584->context, namedFV__V594), LINK_VARIABLESET(sink__V584->context, varFV__V595), LINK_NamedPropertyLink(sink__V584->context, namedP__V592), LINK_VariablePropertyLink(sink__V584->context, varP__V593));
    { START(sink__V584, _M_FormArguments__binder__offsets_s3);
      COPY(sink__V584, sub__V587);{ if (!IS_BOUND(y__V588)) { REBIND(y__V588);
          Variable binds__V596[1] = {y__V588}; BINDS(sink__V584, 1, binds__V596);
          COPY(sink__V584, sub__V589); /* REUSED SUBSTITUTION */  }
        else { Variable b__V597 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V584->context,"b__V597");
          Variable binds__V598[1] = {b__V597}; BINDS(sink__V584, 1, binds__V598);
          {
            Term arg__V599;
            { Sink buf__V600 = ALLOCA_BUFFER(sink__V584->context);
              USE(buf__V600, b__V597); arg__V599 = BUFFER_TERM(buf__V600); FREE_BUFFER(buf__V600); }
            Variable vars__V601[1] = {y__V588};
            Term args__V602[1] = {arg__V599};
            struct _SubstitutionFrame substitution__V603 = {NULL, 0, 1, vars__V601, args__V602, NULL};
            SUBSTITUTE(sink__V584, sub__V589, &substitution__V603); }
              }
         }
      COPY(sink__V584, sub__V590);COPY(sink__V584, sub__V591);END(sink__V584, _M_FormArguments__binder__offsets_s3); }
    UNLINK_VARIABLESET(sink__V584->context, namedFV__V594); UNLINK_VARIABLESET(sink__V584->context, varFV__V595);
    UNLINK_NamedPropertyLink(sink__V584->context, namedP__V592); UNLINK_VariablePropertyLink(sink__V584->context, varP__V593);
    
    return 1;
  } while (0);
  do {
    /* Contraction rule DEFS-FormArguments-binder-offsets-2$FormArguments-binder-offsets$1$FORM-ARGUMENT. */
    ASSERT(sink__V584->context, !strcmp(SYMBOL(term__V585),  "FormArguments-binder-offsets$1" ));
    Term sub__V604 = SUB(term__V585, 0); permitUnusedTerm(sub__V604); int sub__V604_count = term__V585_count*LINK_COUNT(sub__V604); permitUnusedInt(sub__V604_count);
    FORCE(sink__V584->context, sub__V604); SUB(term__V585, 0) = sub__V604;
    if (strcmp(SYMBOL(sub__V604),  "FORM-ARGUMENT" )) break;
    Term sub__V605 = LINK(sink__V584->context, SUB(sub__V604, 0)); int sub__V605_count = sub__V604_count*LINK_COUNT(sub__V605); permitUnusedInt(sub__V605_count);
    CRSX_CHECK_SORT(sink__V584->context, sub__V605, &sort_M_Reified_xSort); /* sub__V605 = &#0-0 */
    Term sub__V606 = LINK(sink__V584->context, SUB(term__V585, 1)); int sub__V606_count = term__V585_count*LINK_COUNT(sub__V606); permitUnusedInt(sub__V606_count);
    /* sub__V606 = &#1 */
    Term sub__V607 = LINK(sink__V584->context, SUB(term__V585, 2)); int sub__V607_count = term__V585_count*LINK_COUNT(sub__V607); permitUnusedInt(sub__V607_count);
    /* sub__V607 = &#2 */
    
    NamedPropertyLink namedP__V608 = LINK_NamedPropertyLink(sink__V584->context, NAMED_PROPERTIES(term__V585));
    VariablePropertyLink varP__V609 = LINK_VariablePropertyLink(sink__V584->context, VARIABLE_PROPERTIES(term__V585));
    Hashset namedFV__V610 = LINK_VARIABLESET(sink__V584->context, asConstruction(term__V585)->properties->namedFreeVars);
    Hashset varFV__V611 = LINK_VARIABLESET(sink__V584->context, asConstruction(term__V585)->properties->variableFreeVars);
    UNLINK(sink__V584->context, term__V585);
    ADD_PROPERTIES(sink__V584, LINK_VARIABLESET(sink__V584->context, namedFV__V610), LINK_VARIABLESET(sink__V584->context, varFV__V611), LINK_NamedPropertyLink(sink__V584->context, namedP__V608), LINK_VariablePropertyLink(sink__V584->context, varP__V609));
    { START(sink__V584, _M_FormArguments__binder__offsets_s2);
      COPY(sink__V584, sub__V605);COPY(sink__V584, sub__V606);COPY(sink__V584, sub__V607);END(sink__V584, _M_FormArguments__binder__offsets_s2); }
    UNLINK_VARIABLESET(sink__V584->context, namedFV__V610); UNLINK_VARIABLESET(sink__V584->context, varFV__V611);
    UNLINK_NamedPropertyLink(sink__V584->context, namedP__V608); UNLINK_VariablePropertyLink(sink__V584->context, varP__V609);
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION FormArguments-binder-offsets$3. */
int conBindOffs_M_FormArguments__binder__offsets_s3[] = {0 , 0 , 1 , 1 , 1};
char *nameFun_M_FormArguments__binder__offsets_s3(Term term) { return  "FormArguments-binder-offsets$3" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__offsets_s3 = {NULL, 0, 4, sizeof(STRUCT_Con_M_FormArguments__binder__offsets_s3), conBindOffs_M_FormArguments__binder__offsets_s3, &nameFun_M_FormArguments__binder__offsets_s3, &step_M_FormArguments__binder__offsets_s3};

int step_M_FormArguments__binder__offsets_s3(Sink sink__V612, Term term__V613)
{
  int term__V613_count = LINK_COUNT(term__V613); permitUnusedInt(term__V613_count);
  do {
    /* Contraction rule DEFS-FormArguments-binder-offsets-1. */
    ASSERT(sink__V612->context, !strcmp(SYMBOL(term__V613),  "FormArguments-binder-offsets$3" ));
    Term sub__V614 = SUB(term__V613, 0); permitUnusedTerm(sub__V614); int sub__V614_count = term__V613_count*LINK_COUNT(sub__V614); permitUnusedInt(sub__V614_count);
    CRSX_CHECK_SORT(sink__V612->context, sub__V614, &sort_M_Reified_xSort); /* sub__V614 = &#111 */
    Variable x__V615 = BINDER(term__V613,1,0); if (term__V613_count <= 1) UNBIND(x__V615);
    Term sub__V616 = LINK(sink__V612->context, SUB(term__V613, 1)); int sub__V616_count = term__V613_count*LINK_COUNT(sub__V616); permitUnusedInt(sub__V616_count);
    CRSX_CHECK_SORT(sink__V612->context, sub__V616, &sort_M_Reified_xFormArgument); /* sub__V616 = &#112 */
    Variable y__V617 = x__V615; permitUnusedVariable(y__V617);
    Term sub__V618 = LINK(sink__V612->context, SUB(term__V613, 2)); int sub__V618_count = term__V613_count*LINK_COUNT(sub__V618); permitUnusedInt(sub__V618_count);
    /* sub__V618 = &#12 */
    Term sub__V619 = LINK(sink__V612->context, SUB(term__V613, 3)); int sub__V619_count = term__V613_count*LINK_COUNT(sub__V619); permitUnusedInt(sub__V619_count);
    /* sub__V619 = &#2 */
    UNLINK(sink__V612->context, term__V613);
    { START(sink__V612, _M_FormArguments__binder__offsets);
      { START(sink__V612, _M__sCons);
        COPY(sink__V612, sub__V616); /* REUSED SUBSTITUTION */ COPY(sink__V612, sub__V618);END(sink__V612, _M__sCons); }
      { double num__V620;
        num__V620 = (double) 1; { double tmp__V621;
          tmp__V621 = DOUBLE(sub__V619); num__V620 += tmp__V621; }
        LITERALNF(sink__V612, (size_t) 31, "%G", num__V620); }
      END(sink__V612, _M_FormArguments__binder__offsets); }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION FormArguments-binder-offsets$2. */
int conBindOffs_M_FormArguments__binder__offsets_s2[] = {0 , 0 , 0 , 0};
char *nameFun_M_FormArguments__binder__offsets_s2(Term term) { return  "FormArguments-binder-offsets$2" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__offsets_s2 = {NULL, 0, 3, sizeof(STRUCT_Con_M_FormArguments__binder__offsets_s2), conBindOffs_M_FormArguments__binder__offsets_s2, &nameFun_M_FormArguments__binder__offsets_s2, &step_M_FormArguments__binder__offsets_s2};

int step_M_FormArguments__binder__offsets_s2(Sink sink__V622, Term term__V623)
{
  int term__V623_count = LINK_COUNT(term__V623); permitUnusedInt(term__V623_count);
  do {
    /* Contraction rule DEFS-FormArguments-binder-offsets-2. */
    ASSERT(sink__V622->context, !strcmp(SYMBOL(term__V623),  "FormArguments-binder-offsets$2" ));
    Term sub__V624 = SUB(term__V623, 0); permitUnusedTerm(sub__V624); int sub__V624_count = term__V623_count*LINK_COUNT(sub__V624); permitUnusedInt(sub__V624_count);
    CRSX_CHECK_SORT(sink__V622->context, sub__V624, &sort_M_Reified_xSort); /* sub__V624 = &#111 */
    Term sub__V625 = LINK(sink__V622->context, SUB(term__V623, 1)); int sub__V625_count = term__V623_count*LINK_COUNT(sub__V625); permitUnusedInt(sub__V625_count);
    /* sub__V625 = &#12 */
    Term sub__V626 = LINK(sink__V622->context, SUB(term__V623, 2)); int sub__V626_count = term__V623_count*LINK_COUNT(sub__V626); permitUnusedInt(sub__V626_count);
    /* sub__V626 = &#2 */
    UNLINK(sink__V622->context, term__V623);
    { START(sink__V622, _M__sCons);
      COPY(sink__V622, LINK(sink__V622->context, sub__V626));{ START(sink__V622, _M_FormArguments__binder__offsets);
        COPY(sink__V622, sub__V625);COPY(sink__V622, sub__V626);END(sink__V622, _M_FormArguments__binder__offsets); }
      END(sink__V622, _M__sCons); }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Var. */
int conBindOffs_M_Var[] = {0 , 0};
char *nameFun_M_Var(Term term) { return  "Var" ; }
struct _ConstructionDescriptor descriptor_M_Var = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_Var), conBindOffs_M_Var, &nameFun_M_Var, &step_M_Var};

int step_M_Var(Sink sink__V627, Term term__V628)
{
  int term__V628_count = LINK_COUNT(term__V628); permitUnusedInt(term__V628_count);
  do {
    /* Contraction rule DEFS-Var-1. */
    ASSERT(sink__V627->context, !strcmp(SYMBOL(term__V628),  "Var" ));
    Term sub__V629 = LINK(sink__V627->context, SUB(term__V628, 0)); int sub__V629_count = term__V628_count*LINK_COUNT(sub__V629); permitUnusedInt(sub__V629_count);
    /* sub__V629 = &#1 */
    
    NamedPropertyLink namedP__V630 = LINK_NamedPropertyLink(sink__V627->context, NAMED_PROPERTIES(term__V628));
    VariablePropertyLink varP__V631 = LINK_VariablePropertyLink(sink__V627->context, VARIABLE_PROPERTIES(term__V628));
    Hashset namedFV__V632 = LINK_VARIABLESET(sink__V627->context, asConstruction(term__V628)->properties->namedFreeVars);
    Hashset varFV__V633 = LINK_VARIABLESET(sink__V627->context, asConstruction(term__V628)->properties->variableFreeVars);
    UNLINK(sink__V627->context, term__V628);
    { START(sink__V627, _M__sTextCons);
      { START(sink__V627, _M__sTextChars);
        LITERAL(sink__V627,  "v" ); END(sink__V627, _M__sTextChars); }
      { START(sink__V627, _M__sTextCons);
        { START(sink__V627, _M__sTextEmbed);
          { START(sink__V627, _M_AsText);
            { START(sink__V627, _M_MANGLE);
              COPY(sink__V627, sub__V629);END(sink__V627, _M_MANGLE); }
            END(sink__V627, _M_AsText); }
          END(sink__V627, _M__sTextEmbed); }
        { START(sink__V627, _M__sTextNil);
          END(sink__V627, _M__sTextNil); }
        END(sink__V627, _M__sTextCons); }
      END(sink__V627, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V627->context, namedFV__V632); UNLINK_VARIABLESET(sink__V627->context, varFV__V633);
    UNLINK_NamedPropertyLink(sink__V627->context, namedP__V630); UNLINK_VariablePropertyLink(sink__V627->context, varP__V631);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Enum. */
int conBindOffs_M_Enum[] = {0 , 0};
char *nameFun_M_Enum(Term term) { return  "Enum" ; }
struct _ConstructionDescriptor descriptor_M_Enum = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_Enum), conBindOffs_M_Enum, &nameFun_M_Enum, &step_M_Enum};

int step_M_Enum(Sink sink__V634, Term term__V635)
{
  int term__V635_count = LINK_COUNT(term__V635); permitUnusedInt(term__V635_count);
  do {
    /* Contraction rule DEFS-Enum-1. */
    ASSERT(sink__V634->context, !strcmp(SYMBOL(term__V635),  "Enum" ));
    Term sub__V636 = LINK(sink__V634->context, SUB(term__V635, 0)); int sub__V636_count = term__V635_count*LINK_COUNT(sub__V636); permitUnusedInt(sub__V636_count);
    /* sub__V636 = &#1 */
    
    NamedPropertyLink namedP__V637 = LINK_NamedPropertyLink(sink__V634->context, NAMED_PROPERTIES(term__V635));
    VariablePropertyLink varP__V638 = LINK_VariablePropertyLink(sink__V634->context, VARIABLE_PROPERTIES(term__V635));
    Hashset namedFV__V639 = LINK_VARIABLESET(sink__V634->context, asConstruction(term__V635)->properties->namedFreeVars);
    Hashset varFV__V640 = LINK_VARIABLESET(sink__V634->context, asConstruction(term__V635)->properties->variableFreeVars);
    UNLINK(sink__V634->context, term__V635);
    { START(sink__V634, _M__sTextCons);
      { START(sink__V634, _M__sTextChars);
        LITERAL(sink__V634,  "EnumOf" ); END(sink__V634, _M__sTextChars); }
      { START(sink__V634, _M__sTextCons);
        { START(sink__V634, _M__sTextEmbed);
          { START(sink__V634, _M_AsText);
            { START(sink__V634, _M_MANGLE);
              COPY(sink__V634, sub__V636);END(sink__V634, _M_MANGLE); }
            END(sink__V634, _M_AsText); }
          END(sink__V634, _M__sTextEmbed); }
        { START(sink__V634, _M__sTextNil);
          END(sink__V634, _M__sTextNil); }
        END(sink__V634, _M__sTextCons); }
      END(sink__V634, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V634->context, namedFV__V639); UNLINK_VARIABLESET(sink__V634->context, varFV__V640);
    UNLINK_NamedPropertyLink(sink__V634->context, namedP__V637); UNLINK_VariablePropertyLink(sink__V634->context, varP__V638);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION If. */
int conBindOffs_M_If[] = {0 , 0 , 0 , 0};
char *nameFun_M_If(Term term) { return  "If" ; }
struct _ConstructionDescriptor descriptor_M_If = {NULL, 0, 3, sizeof(STRUCT_Con_M_If), conBindOffs_M_If, &nameFun_M_If, &step_M_If};

int step_M_If(Sink sink__V641, Term term__V642)
{
  int term__V642_count = LINK_COUNT(term__V642); permitUnusedInt(term__V642_count);
  Term sub__V643 = FORCE(sink__V641->context, SUB(term__V642, 0));
  EnumOf_M__sBoolean choice__V644 = (IS_VARIABLE_USE(sub__V643) ? VarOf_M__sBoolean : (EnumOf_M__sBoolean) TAG(sub__V643));
  switch (choice__V644)
  {
    case Data_M__sTrue: { /* Function DEFS-If-1$If$$True case $True */
      ASSERT(sink__V641->context, !strcmp(SYMBOL(term__V642),  "If" ));
      Term sub__V645 = SUB(term__V642, 0); permitUnusedTerm(sub__V645); int sub__V645_count = term__V642_count*LINK_COUNT(sub__V645); permitUnusedInt(sub__V645_count);
      ASSERT(sink__V641->context, !strcmp(SYMBOL(sub__V645),  "$True" ));
      Term sub__V646 = LINK(sink__V641->context, SUB(term__V642, 1)); int sub__V646_count = term__V642_count*LINK_COUNT(sub__V646); permitUnusedInt(sub__V646_count);
      /* sub__V646 = &#0 */
      Term sub__V647 = LINK(sink__V641->context, SUB(term__V642, 2)); int sub__V647_count = term__V642_count*LINK_COUNT(sub__V647); permitUnusedInt(sub__V647_count);
      /* sub__V647 = &#1 */
      
      NamedPropertyLink namedP__V648 = LINK_NamedPropertyLink(sink__V641->context, NAMED_PROPERTIES(term__V642));
      VariablePropertyLink varP__V649 = LINK_VariablePropertyLink(sink__V641->context, VARIABLE_PROPERTIES(term__V642));
      Hashset namedFV__V650 = LINK_VARIABLESET(sink__V641->context, asConstruction(term__V642)->properties->namedFreeVars);
      Hashset varFV__V651 = LINK_VARIABLESET(sink__V641->context, asConstruction(term__V642)->properties->variableFreeVars);
      UNLINK(sink__V641->context, term__V642);
      ADD_PROPERTIES(sink__V641, LINK_VARIABLESET(sink__V641->context, namedFV__V650), LINK_VARIABLESET(sink__V641->context, varFV__V651), LINK_NamedPropertyLink(sink__V641->context, namedP__V648), LINK_VariablePropertyLink(sink__V641->context, varP__V649));
      { START(sink__V641, _M_If_s2);
        COPY(sink__V641, sub__V646);COPY(sink__V641, sub__V647);END(sink__V641, _M_If_s2); }
      UNLINK_VARIABLESET(sink__V641->context, namedFV__V650); UNLINK_VARIABLESET(sink__V641->context, varFV__V651);
      UNLINK_NamedPropertyLink(sink__V641->context, namedP__V648); UNLINK_VariablePropertyLink(sink__V641->context, varP__V649);
      
      return 1;
    break; } case Data_M__sFalse: { /* Function DEFS-If-2$If$$False case $False */
      ASSERT(sink__V641->context, !strcmp(SYMBOL(term__V642),  "If" ));
      Term sub__V652 = SUB(term__V642, 0); permitUnusedTerm(sub__V652); int sub__V652_count = term__V642_count*LINK_COUNT(sub__V652); permitUnusedInt(sub__V652_count);
      ASSERT(sink__V641->context, !strcmp(SYMBOL(sub__V652),  "$False" ));
      Term sub__V653 = LINK(sink__V641->context, SUB(term__V642, 1)); int sub__V653_count = term__V642_count*LINK_COUNT(sub__V653); permitUnusedInt(sub__V653_count);
      /* sub__V653 = &#0 */
      Term sub__V654 = LINK(sink__V641->context, SUB(term__V642, 2)); int sub__V654_count = term__V642_count*LINK_COUNT(sub__V654); permitUnusedInt(sub__V654_count);
      /* sub__V654 = &#1 */
      
      NamedPropertyLink namedP__V655 = LINK_NamedPropertyLink(sink__V641->context, NAMED_PROPERTIES(term__V642));
      VariablePropertyLink varP__V656 = LINK_VariablePropertyLink(sink__V641->context, VARIABLE_PROPERTIES(term__V642));
      Hashset namedFV__V657 = LINK_VARIABLESET(sink__V641->context, asConstruction(term__V642)->properties->namedFreeVars);
      Hashset varFV__V658 = LINK_VARIABLESET(sink__V641->context, asConstruction(term__V642)->properties->variableFreeVars);
      UNLINK(sink__V641->context, term__V642);
      ADD_PROPERTIES(sink__V641, LINK_VARIABLESET(sink__V641->context, namedFV__V657), LINK_VARIABLESET(sink__V641->context, varFV__V658), LINK_NamedPropertyLink(sink__V641->context, namedP__V655), LINK_VariablePropertyLink(sink__V641->context, varP__V656));
      { START(sink__V641, _M_If_s1);
        COPY(sink__V641, sub__V653);COPY(sink__V641, sub__V654);END(sink__V641, _M_If_s1); }
      UNLINK_VARIABLESET(sink__V641->context, namedFV__V657); UNLINK_VARIABLESET(sink__V641->context, varFV__V658);
      UNLINK_NamedPropertyLink(sink__V641->context, namedP__V655); UNLINK_VariablePropertyLink(sink__V641->context, varP__V656);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION DEnumTag. */
int conBindOffs_M_DEnumTag[] = {0 , 0 , 0};
char *nameFun_M_DEnumTag(Term term) { return  "DEnumTag" ; }
struct _ConstructionDescriptor descriptor_M_DEnumTag = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_DEnumTag), conBindOffs_M_DEnumTag, &nameFun_M_DEnumTag, &step_M_DEnumTag};

int step_M_DEnumTag(Sink sink__V659, Term term__V660)
{
  int term__V660_count = LINK_COUNT(term__V660); permitUnusedInt(term__V660_count);
  Term sub__V661 = FORCE(sink__V659->context, SUB(term__V660, 0));
  EnumOf_M_OK_xSORT choice__V662 = (IS_VARIABLE_USE(sub__V661) ? VarOf_M_OK_xSORT : (EnumOf_M_OK_xSORT) TAG(sub__V661));
  switch (choice__V662)
  {
    case Data_M_OK: { /* Function DEFS-DEnumTag-1$DEnumTag$OK case OK */
      ASSERT(sink__V659->context, !strcmp(SYMBOL(term__V660),  "DEnumTag" ));
      Term sub__V663 = SUB(term__V660, 0); permitUnusedTerm(sub__V663); int sub__V663_count = term__V660_count*LINK_COUNT(sub__V663); permitUnusedInt(sub__V663_count);
      CRSX_CHECK_SORT(sink__V659->context, sub__V663, &sort_M_OK_xSORT); ASSERT(sink__V659->context, !strcmp(SYMBOL(sub__V663),  "OK" ));
      Term sub__V664 = LINK(sink__V659->context, SUB(term__V660, 1)); int sub__V664_count = term__V660_count*LINK_COUNT(sub__V664); permitUnusedInt(sub__V664_count);
      /* sub__V664 = &#0 */
      
      NamedPropertyLink namedP__V665 = LINK_NamedPropertyLink(sink__V659->context, NAMED_PROPERTIES(term__V660));
      VariablePropertyLink varP__V666 = LINK_VariablePropertyLink(sink__V659->context, VARIABLE_PROPERTIES(term__V660));
      Hashset namedFV__V667 = LINK_VARIABLESET(sink__V659->context, asConstruction(term__V660)->properties->namedFreeVars);
      Hashset varFV__V668 = LINK_VARIABLESET(sink__V659->context, asConstruction(term__V660)->properties->variableFreeVars);
      UNLINK(sink__V659->context, term__V660);
      ADD_PROPERTIES(sink__V659, LINK_VARIABLESET(sink__V659->context, namedFV__V667), LINK_VARIABLESET(sink__V659->context, varFV__V668), LINK_NamedPropertyLink(sink__V659->context, namedP__V665), LINK_VariablePropertyLink(sink__V659->context, varP__V666));
      { START(sink__V659, _M_DEnumTag_s1);
        COPY(sink__V659, sub__V664);END(sink__V659, _M_DEnumTag_s1); }
      UNLINK_VARIABLESET(sink__V659->context, namedFV__V667); UNLINK_VARIABLESET(sink__V659->context, varFV__V668);
      UNLINK_NamedPropertyLink(sink__V659->context, namedP__V665); UNLINK_VariablePropertyLink(sink__V659->context, varP__V666);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION Forms-Constructors. */
int conBindOffs_M_Forms_Constructors[] = {0 , 0};
char *nameFun_M_Forms_Constructors(Term term) { return  "Forms-Constructors" ; }
struct _ConstructionDescriptor descriptor_M_Forms_Constructors = {NULL, 0, 1, sizeof(STRUCT_Con_M_Forms_Constructors), conBindOffs_M_Forms_Constructors, &nameFun_M_Forms_Constructors, &step_M_Forms_Constructors};

int step_M_Forms_Constructors(Sink sink__V669, Term term__V670)
{
  int term__V670_count = LINK_COUNT(term__V670); permitUnusedInt(term__V670_count);
  Term sub__V671 = FORCE(sink__V669->context, SUB(term__V670, 0));
  EnumOf_M__sList choice__V672 = (IS_VARIABLE_USE(sub__V671) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V671));
  switch (choice__V672)
  {
    case Data_M__sCons: { /* Function DEFS-Forms-Constructors-3$Forms-Constructors$$Cons case $Cons */
      ASSERT(sink__V669->context, !strcmp(SYMBOL(term__V670),  "Forms-Constructors" ));
      Term sub__V673 = SUB(term__V670, 0); permitUnusedTerm(sub__V673); int sub__V673_count = term__V670_count*LINK_COUNT(sub__V673); permitUnusedInt(sub__V673_count);
      ASSERT(sink__V669->context, !strcmp(SYMBOL(sub__V673),  "$Cons" ));
      Term sub__V674 = LINK(sink__V669->context, SUB(sub__V673, 0)); int sub__V674_count = sub__V673_count*LINK_COUNT(sub__V674); permitUnusedInt(sub__V674_count);
      /* sub__V674 = &#0-0 */
      Term sub__V675 = LINK(sink__V669->context, SUB(sub__V673, 1)); int sub__V675_count = sub__V673_count*LINK_COUNT(sub__V675); permitUnusedInt(sub__V675_count);
      /* sub__V675 = &#0-1 */
      
      NamedPropertyLink namedP__V676 = LINK_NamedPropertyLink(sink__V669->context, NAMED_PROPERTIES(term__V670));
      VariablePropertyLink varP__V677 = LINK_VariablePropertyLink(sink__V669->context, VARIABLE_PROPERTIES(term__V670));
      Hashset namedFV__V678 = LINK_VARIABLESET(sink__V669->context, asConstruction(term__V670)->properties->namedFreeVars);
      Hashset varFV__V679 = LINK_VARIABLESET(sink__V669->context, asConstruction(term__V670)->properties->variableFreeVars);
      UNLINK(sink__V669->context, term__V670);
      ADD_PROPERTIES(sink__V669, LINK_VARIABLESET(sink__V669->context, namedFV__V678), LINK_VARIABLESET(sink__V669->context, varFV__V679), LINK_NamedPropertyLink(sink__V669->context, namedP__V676), LINK_VariablePropertyLink(sink__V669->context, varP__V677));
      { START(sink__V669, _M_Forms_Constructors_s1);
        COPY(sink__V669, sub__V674);COPY(sink__V669, sub__V675);END(sink__V669, _M_Forms_Constructors_s1); }
      UNLINK_VARIABLESET(sink__V669->context, namedFV__V678); UNLINK_VARIABLESET(sink__V669->context, varFV__V679);
      UNLINK_NamedPropertyLink(sink__V669->context, namedP__V676); UNLINK_VariablePropertyLink(sink__V669->context, varP__V677);
      
      return 1;
    break; } case Data_M__sNil: { /* Function DEFS-Forms-Constructors-4$Forms-Constructors$$Nil case $Nil */
      ASSERT(sink__V669->context, !strcmp(SYMBOL(term__V670),  "Forms-Constructors" ));
      Term sub__V680 = SUB(term__V670, 0); permitUnusedTerm(sub__V680); int sub__V680_count = term__V670_count*LINK_COUNT(sub__V680); permitUnusedInt(sub__V680_count);
      ASSERT(sink__V669->context, !strcmp(SYMBOL(sub__V680),  "$Nil" ));
      
      NamedPropertyLink namedP__V681 = LINK_NamedPropertyLink(sink__V669->context, NAMED_PROPERTIES(term__V670));
      VariablePropertyLink varP__V682 = LINK_VariablePropertyLink(sink__V669->context, VARIABLE_PROPERTIES(term__V670));
      Hashset namedFV__V683 = LINK_VARIABLESET(sink__V669->context, asConstruction(term__V670)->properties->namedFreeVars);
      Hashset varFV__V684 = LINK_VARIABLESET(sink__V669->context, asConstruction(term__V670)->properties->variableFreeVars);
      UNLINK(sink__V669->context, term__V670);
      ADD_PROPERTIES(sink__V669, LINK_VARIABLESET(sink__V669->context, namedFV__V683), LINK_VARIABLESET(sink__V669->context, varFV__V684), LINK_NamedPropertyLink(sink__V669->context, namedP__V681), LINK_VariablePropertyLink(sink__V669->context, varP__V682));
      { START(sink__V669, _M_Forms_Constructors_s5);
        END(sink__V669, _M_Forms_Constructors_s5); }
      UNLINK_VARIABLESET(sink__V669->context, namedFV__V683); UNLINK_VARIABLESET(sink__V669->context, varFV__V684);
      UNLINK_NamedPropertyLink(sink__V669->context, namedP__V681); UNLINK_VariablePropertyLink(sink__V669->context, varP__V682);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION DDescriptor. */
int conBindOffs_M_DDescriptor[] = {0 , 0 , 0};
char *nameFun_M_DDescriptor(Term term) { return  "DDescriptor" ; }
struct _ConstructionDescriptor descriptor_M_DDescriptor = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_DDescriptor), conBindOffs_M_DDescriptor, &nameFun_M_DDescriptor, &step_M_DDescriptor};

int step_M_DDescriptor(Sink sink__V685, Term term__V686)
{
  int term__V686_count = LINK_COUNT(term__V686); permitUnusedInt(term__V686_count);
  Term sub__V687 = FORCE(sink__V685->context, SUB(term__V686, 0));
  EnumOf_M_OK_xSORT choice__V688 = (IS_VARIABLE_USE(sub__V687) ? VarOf_M_OK_xSORT : (EnumOf_M_OK_xSORT) TAG(sub__V687));
  switch (choice__V688)
  {
    case Data_M_OK: { /* Function DEFS-DDescriptor-1$DDescriptor$OK case OK */
      ASSERT(sink__V685->context, !strcmp(SYMBOL(term__V686),  "DDescriptor" ));
      Term sub__V689 = SUB(term__V686, 0); permitUnusedTerm(sub__V689); int sub__V689_count = term__V686_count*LINK_COUNT(sub__V689); permitUnusedInt(sub__V689_count);
      CRSX_CHECK_SORT(sink__V685->context, sub__V689, &sort_M_OK_xSORT); ASSERT(sink__V685->context, !strcmp(SYMBOL(sub__V689),  "OK" ));
      Term sub__V690 = LINK(sink__V685->context, SUB(term__V686, 1)); int sub__V690_count = term__V686_count*LINK_COUNT(sub__V690); permitUnusedInt(sub__V690_count);
      /* sub__V690 = &#0 */
      
      NamedPropertyLink namedP__V691 = LINK_NamedPropertyLink(sink__V685->context, NAMED_PROPERTIES(term__V686));
      VariablePropertyLink varP__V692 = LINK_VariablePropertyLink(sink__V685->context, VARIABLE_PROPERTIES(term__V686));
      Hashset namedFV__V693 = LINK_VARIABLESET(sink__V685->context, asConstruction(term__V686)->properties->namedFreeVars);
      Hashset varFV__V694 = LINK_VARIABLESET(sink__V685->context, asConstruction(term__V686)->properties->variableFreeVars);
      UNLINK(sink__V685->context, term__V686);
      ADD_PROPERTIES(sink__V685, LINK_VARIABLESET(sink__V685->context, namedFV__V693), LINK_VARIABLESET(sink__V685->context, varFV__V694), LINK_NamedPropertyLink(sink__V685->context, namedP__V691), LINK_VariablePropertyLink(sink__V685->context, varP__V692));
      { START(sink__V685, _M_DDescriptor_s1);
        COPY(sink__V685, sub__V690);END(sink__V685, _M_DDescriptor_s1); }
      UNLINK_VARIABLESET(sink__V685->context, namedFV__V693); UNLINK_VARIABLESET(sink__V685->context, varFV__V694);
      UNLINK_NamedPropertyLink(sink__V685->context, namedP__V691); UNLINK_VariablePropertyLink(sink__V685->context, varP__V692);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION PromiscuityString$1. */
int conBindOffs_M_PromiscuityString_s1[] = {0};
char *nameFun_M_PromiscuityString_s1(Term term) { return  "PromiscuityString$1" ; }
struct _ConstructionDescriptor descriptor_M_PromiscuityString_s1 = {NULL, 0, 0, sizeof(STRUCT_Con_M_PromiscuityString_s1), conBindOffs_M_PromiscuityString_s1, &nameFun_M_PromiscuityString_s1, &step_M_PromiscuityString_s1};

int step_M_PromiscuityString_s1(Sink sink__V695, Term term__V696)
{
  int term__V696_count = LINK_COUNT(term__V696); permitUnusedInt(term__V696_count);
  do {
    /* Contraction rule DEFS-PromiscuityString-1. */
    ASSERT(sink__V695->context, !strcmp(SYMBOL(term__V696),  "PromiscuityString$1" ));
    UNLINK(sink__V695->context, term__V696);
    LITERAL(sink__V695,  "LINEAR" ); 
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION PromiscuityString$2. */
int conBindOffs_M_PromiscuityString_s2[] = {0};
char *nameFun_M_PromiscuityString_s2(Term term) { return  "PromiscuityString$2" ; }
struct _ConstructionDescriptor descriptor_M_PromiscuityString_s2 = {NULL, 0, 0, sizeof(STRUCT_Con_M_PromiscuityString_s2), conBindOffs_M_PromiscuityString_s2, &nameFun_M_PromiscuityString_s2, &step_M_PromiscuityString_s2};

int step_M_PromiscuityString_s2(Sink sink__V697, Term term__V698)
{
  int term__V698_count = LINK_COUNT(term__V698); permitUnusedInt(term__V698_count);
  do {
    /* Contraction rule DEFS-PromiscuityString-2. */
    ASSERT(sink__V697->context, !strcmp(SYMBOL(term__V698),  "PromiscuityString$2" ));
    UNLINK(sink__V697->context, term__V698);
    LITERAL(sink__V697,  "PROMISCUOUS" ); 
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION SortCons. */
int conBindOffs_M_SortCons[] = {0 , 0};
char *nameFun_M_SortCons(Term term) { return  "SortCons" ; }
struct _ConstructionDescriptor descriptor_M_SortCons = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_SortCons), conBindOffs_M_SortCons, &nameFun_M_SortCons, &step_M_SortCons};

int step_M_SortCons(Sink sink__V699, Term term__V700)
{
  int term__V700_count = LINK_COUNT(term__V700); permitUnusedInt(term__V700_count);
  do {
    /* Contraction rule DEFS-SortCons-1. */
    ASSERT(sink__V699->context, !strcmp(SYMBOL(term__V700),  "SortCons" ));
    Term sub__V701 = LINK(sink__V699->context, SUB(term__V700, 0)); int sub__V701_count = term__V700_count*LINK_COUNT(sub__V701); permitUnusedInt(sub__V701_count);
    /* sub__V701 = &#1 */
    
    NamedPropertyLink namedP__V702 = LINK_NamedPropertyLink(sink__V699->context, NAMED_PROPERTIES(term__V700));
    VariablePropertyLink varP__V703 = LINK_VariablePropertyLink(sink__V699->context, VARIABLE_PROPERTIES(term__V700));
    Hashset namedFV__V704 = LINK_VARIABLESET(sink__V699->context, asConstruction(term__V700)->properties->namedFreeVars);
    Hashset varFV__V705 = LINK_VARIABLESET(sink__V699->context, asConstruction(term__V700)->properties->variableFreeVars);
    UNLINK(sink__V699->context, term__V700);
    { START(sink__V699, _M__sTextCons);
      { START(sink__V699, _M__sTextChars);
        LITERAL(sink__V699,  "sortCon" ); END(sink__V699, _M__sTextChars); }
      { START(sink__V699, _M__sTextCons);
        { START(sink__V699, _M__sTextEmbed);
          { START(sink__V699, _M_AsText);
            { START(sink__V699, _M_MANGLE);
              COPY(sink__V699, sub__V701);END(sink__V699, _M_MANGLE); }
            END(sink__V699, _M_AsText); }
          END(sink__V699, _M__sTextEmbed); }
        { START(sink__V699, _M__sTextNil);
          END(sink__V699, _M__sTextNil); }
        END(sink__V699, _M__sTextCons); }
      END(sink__V699, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V699->context, namedFV__V704); UNLINK_VARIABLESET(sink__V699->context, varFV__V705);
    UNLINK_NamedPropertyLink(sink__V699->context, namedP__V702); UNLINK_VariablePropertyLink(sink__V699->context, varP__V703);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION FormArguments-binder-count$4. */
int conBindOffs_M_FormArguments__binder__count_s4[] = {0 , 0};
char *nameFun_M_FormArguments__binder__count_s4(Term term) { return  "FormArguments-binder-count$4" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__count_s4 = {NULL, 0, 1, sizeof(STRUCT_Con_M_FormArguments__binder__count_s4), conBindOffs_M_FormArguments__binder__count_s4, &nameFun_M_FormArguments__binder__count_s4, &step_M_FormArguments__binder__count_s4};

int step_M_FormArguments__binder__count_s4(Sink sink__V706, Term term__V707)
{
  int term__V707_count = LINK_COUNT(term__V707); permitUnusedInt(term__V707_count);
  do {
    /* Contraction rule DEFS-FormArguments-binder-count-3. */
    ASSERT(sink__V706->context, !strcmp(SYMBOL(term__V707),  "FormArguments-binder-count$4" ));
    Term sub__V708 = LINK(sink__V706->context, SUB(term__V707, 0)); int sub__V708_count = term__V707_count*LINK_COUNT(sub__V708); permitUnusedInt(sub__V708_count);
    /* sub__V708 = &#2 */
    UNLINK(sink__V706->context, term__V707);
    COPY(sink__V706, sub__V708);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION FormArguments-binder-count$3. */
int conBindOffs_M_FormArguments__binder__count_s3[] = {0 , 0 , 1 , 1 , 1};
char *nameFun_M_FormArguments__binder__count_s3(Term term) { return  "FormArguments-binder-count$3" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__count_s3 = {NULL, 0, 4, sizeof(STRUCT_Con_M_FormArguments__binder__count_s3), conBindOffs_M_FormArguments__binder__count_s3, &nameFun_M_FormArguments__binder__count_s3, &step_M_FormArguments__binder__count_s3};

int step_M_FormArguments__binder__count_s3(Sink sink__V709, Term term__V710)
{
  int term__V710_count = LINK_COUNT(term__V710); permitUnusedInt(term__V710_count);
  do {
    /* Contraction rule DEFS-FormArguments-binder-count-1. */
    ASSERT(sink__V709->context, !strcmp(SYMBOL(term__V710),  "FormArguments-binder-count$3" ));
    Term sub__V711 = SUB(term__V710, 0); permitUnusedTerm(sub__V711); int sub__V711_count = term__V710_count*LINK_COUNT(sub__V711); permitUnusedInt(sub__V711_count);
    CRSX_CHECK_SORT(sink__V709->context, sub__V711, &sort_M_Reified_xSort); /* sub__V711 = &#111 */
    Variable x__V712 = BINDER(term__V710,1,0); if (term__V710_count <= 1) UNBIND(x__V712);
    Term sub__V713 = LINK(sink__V709->context, SUB(term__V710, 1)); int sub__V713_count = term__V710_count*LINK_COUNT(sub__V713); permitUnusedInt(sub__V713_count);
    CRSX_CHECK_SORT(sink__V709->context, sub__V713, &sort_M_Reified_xFormArgument); /* sub__V713 = &#112 */
    Variable y__V617 = x__V712; permitUnusedVariable(y__V617);
    Term sub__V714 = LINK(sink__V709->context, SUB(term__V710, 2)); int sub__V714_count = term__V710_count*LINK_COUNT(sub__V714); permitUnusedInt(sub__V714_count);
    /* sub__V714 = &#12 */
    Term sub__V715 = LINK(sink__V709->context, SUB(term__V710, 3)); int sub__V715_count = term__V710_count*LINK_COUNT(sub__V715); permitUnusedInt(sub__V715_count);
    /* sub__V715 = &#2 */
    UNLINK(sink__V709->context, term__V710);
    { START(sink__V709, _M_FormArguments__binder__count);
      { START(sink__V709, _M__sCons);
        COPY(sink__V709, sub__V713); /* REUSED SUBSTITUTION */ COPY(sink__V709, sub__V714);END(sink__V709, _M__sCons); }
      { double num__V716;
        num__V716 = (double) 1; { double tmp__V717;
          tmp__V717 = DOUBLE(sub__V715); num__V716 += tmp__V717; }
        LITERALNF(sink__V709, (size_t) 31, "%G", num__V716); }
      END(sink__V709, _M_FormArguments__binder__count); }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION FormArguments-binder-count$2. */
int conBindOffs_M_FormArguments__binder__count_s2[] = {0 , 0 , 0 , 0};
char *nameFun_M_FormArguments__binder__count_s2(Term term) { return  "FormArguments-binder-count$2" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__count_s2 = {NULL, 0, 3, sizeof(STRUCT_Con_M_FormArguments__binder__count_s2), conBindOffs_M_FormArguments__binder__count_s2, &nameFun_M_FormArguments__binder__count_s2, &step_M_FormArguments__binder__count_s2};

int step_M_FormArguments__binder__count_s2(Sink sink__V718, Term term__V719)
{
  int term__V719_count = LINK_COUNT(term__V719); permitUnusedInt(term__V719_count);
  do {
    /* Contraction rule DEFS-FormArguments-binder-count-2. */
    ASSERT(sink__V718->context, !strcmp(SYMBOL(term__V719),  "FormArguments-binder-count$2" ));
    Term sub__V720 = SUB(term__V719, 0); permitUnusedTerm(sub__V720); int sub__V720_count = term__V719_count*LINK_COUNT(sub__V720); permitUnusedInt(sub__V720_count);
    CRSX_CHECK_SORT(sink__V718->context, sub__V720, &sort_M_Reified_xSort); /* sub__V720 = &#111 */
    Term sub__V721 = LINK(sink__V718->context, SUB(term__V719, 1)); int sub__V721_count = term__V719_count*LINK_COUNT(sub__V721); permitUnusedInt(sub__V721_count);
    /* sub__V721 = &#12 */
    Term sub__V722 = LINK(sink__V718->context, SUB(term__V719, 2)); int sub__V722_count = term__V719_count*LINK_COUNT(sub__V722); permitUnusedInt(sub__V722_count);
    /* sub__V722 = &#2 */
    UNLINK(sink__V718->context, term__V719);
    { START(sink__V718, _M_FormArguments__binder__count);
      COPY(sink__V718, sub__V721);COPY(sink__V718, sub__V722);END(sink__V718, _M_FormArguments__binder__count); }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION FormArguments-binder-count$1. */
int conBindOffs_M_FormArguments__binder__count_s1[] = {0 , 0 , 0 , 0};
char *nameFun_M_FormArguments__binder__count_s1(Term term) { return  "FormArguments-binder-count$1" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__count_s1 = {NULL, 0, 3, sizeof(STRUCT_Con_M_FormArguments__binder__count_s1), conBindOffs_M_FormArguments__binder__count_s1, &nameFun_M_FormArguments__binder__count_s1, &step_M_FormArguments__binder__count_s1};

int step_M_FormArguments__binder__count_s1(Sink sink__V723, Term term__V724)
{
  int term__V724_count = LINK_COUNT(term__V724); permitUnusedInt(term__V724_count);
  do {
    /* Contraction rule DEFS-FormArguments-binder-count-1$FormArguments-binder-count$1$FORM-BINDER. */
    ASSERT(sink__V723->context, !strcmp(SYMBOL(term__V724),  "FormArguments-binder-count$1" ));
    Term sub__V725 = SUB(term__V724, 0); permitUnusedTerm(sub__V725); int sub__V725_count = term__V724_count*LINK_COUNT(sub__V725); permitUnusedInt(sub__V725_count);
    FORCE(sink__V723->context, sub__V725); SUB(term__V724, 0) = sub__V725;
    if (strcmp(SYMBOL(sub__V725),  "FORM-BINDER" )) break;
    Term sub__V726 = LINK(sink__V723->context, SUB(sub__V725, 0)); int sub__V726_count = sub__V725_count*LINK_COUNT(sub__V726); permitUnusedInt(sub__V726_count);
    CRSX_CHECK_SORT(sink__V723->context, sub__V726, &sort_M_Reified_xSort); /* sub__V726 = &#0-0 */
    Variable y__V727 = BINDER(sub__V725,1,0); if (sub__V725_count <= 1) UNBIND(y__V727);
    Term sub__V728 = LINK(sink__V723->context, SUB(sub__V725, 1)); int sub__V728_count = sub__V725_count*LINK_COUNT(sub__V728); permitUnusedInt(sub__V728_count);
    CRSX_CHECK_SORT(sink__V723->context, sub__V728, &sort_M_Reified_xFormArgument); /* sub__V728 = &#0-1 */
    Term sub__V729 = LINK(sink__V723->context, SUB(term__V724, 1)); int sub__V729_count = term__V724_count*LINK_COUNT(sub__V729); permitUnusedInt(sub__V729_count);
    /* sub__V729 = &#2 */
    Term sub__V730 = LINK(sink__V723->context, SUB(term__V724, 2)); int sub__V730_count = term__V724_count*LINK_COUNT(sub__V730); permitUnusedInt(sub__V730_count);
    /* sub__V730 = &#3 */
    
    NamedPropertyLink namedP__V731 = LINK_NamedPropertyLink(sink__V723->context, NAMED_PROPERTIES(term__V724));
    VariablePropertyLink varP__V732 = LINK_VariablePropertyLink(sink__V723->context, VARIABLE_PROPERTIES(term__V724));
    Hashset namedFV__V733 = LINK_VARIABLESET(sink__V723->context, asConstruction(term__V724)->properties->namedFreeVars);
    Hashset varFV__V734 = LINK_VARIABLESET(sink__V723->context, asConstruction(term__V724)->properties->variableFreeVars);
    UNLINK(sink__V723->context, term__V724);
    ADD_PROPERTIES(sink__V723, LINK_VARIABLESET(sink__V723->context, namedFV__V733), LINK_VARIABLESET(sink__V723->context, varFV__V734), LINK_NamedPropertyLink(sink__V723->context, namedP__V731), LINK_VariablePropertyLink(sink__V723->context, varP__V732));
    { START(sink__V723, _M_FormArguments__binder__count_s3);
      COPY(sink__V723, sub__V726);{ if (!IS_BOUND(y__V727)) { REBIND(y__V727);
          Variable binds__V735[1] = {y__V727}; BINDS(sink__V723, 1, binds__V735);
          COPY(sink__V723, sub__V728); /* REUSED SUBSTITUTION */  }
        else { Variable b__V736 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V723->context,"b__V736");
          Variable binds__V737[1] = {b__V736}; BINDS(sink__V723, 1, binds__V737);
          {
            Term arg__V738;
            { Sink buf__V739 = ALLOCA_BUFFER(sink__V723->context);
              USE(buf__V739, b__V736); arg__V738 = BUFFER_TERM(buf__V739); FREE_BUFFER(buf__V739); }
            Variable vars__V740[1] = {y__V727};
            Term args__V741[1] = {arg__V738};
            struct _SubstitutionFrame substitution__V742 = {NULL, 0, 1, vars__V740, args__V741, NULL};
            SUBSTITUTE(sink__V723, sub__V728, &substitution__V742); }
              }
         }
      COPY(sink__V723, sub__V729);COPY(sink__V723, sub__V730);END(sink__V723, _M_FormArguments__binder__count_s3); }
    UNLINK_VARIABLESET(sink__V723->context, namedFV__V733); UNLINK_VARIABLESET(sink__V723->context, varFV__V734);
    UNLINK_NamedPropertyLink(sink__V723->context, namedP__V731); UNLINK_VariablePropertyLink(sink__V723->context, varP__V732);
    
    return 1;
  } while (0);
  do {
    /* Contraction rule DEFS-FormArguments-binder-count-2$FormArguments-binder-count$1$FORM-ARGUMENT. */
    ASSERT(sink__V723->context, !strcmp(SYMBOL(term__V724),  "FormArguments-binder-count$1" ));
    Term sub__V743 = SUB(term__V724, 0); permitUnusedTerm(sub__V743); int sub__V743_count = term__V724_count*LINK_COUNT(sub__V743); permitUnusedInt(sub__V743_count);
    FORCE(sink__V723->context, sub__V743); SUB(term__V724, 0) = sub__V743;
    if (strcmp(SYMBOL(sub__V743),  "FORM-ARGUMENT" )) break;
    Term sub__V744 = LINK(sink__V723->context, SUB(sub__V743, 0)); int sub__V744_count = sub__V743_count*LINK_COUNT(sub__V744); permitUnusedInt(sub__V744_count);
    CRSX_CHECK_SORT(sink__V723->context, sub__V744, &sort_M_Reified_xSort); /* sub__V744 = &#0-0 */
    Term sub__V745 = LINK(sink__V723->context, SUB(term__V724, 1)); int sub__V745_count = term__V724_count*LINK_COUNT(sub__V745); permitUnusedInt(sub__V745_count);
    /* sub__V745 = &#1 */
    Term sub__V746 = LINK(sink__V723->context, SUB(term__V724, 2)); int sub__V746_count = term__V724_count*LINK_COUNT(sub__V746); permitUnusedInt(sub__V746_count);
    /* sub__V746 = &#2 */
    
    NamedPropertyLink namedP__V747 = LINK_NamedPropertyLink(sink__V723->context, NAMED_PROPERTIES(term__V724));
    VariablePropertyLink varP__V748 = LINK_VariablePropertyLink(sink__V723->context, VARIABLE_PROPERTIES(term__V724));
    Hashset namedFV__V749 = LINK_VARIABLESET(sink__V723->context, asConstruction(term__V724)->properties->namedFreeVars);
    Hashset varFV__V750 = LINK_VARIABLESET(sink__V723->context, asConstruction(term__V724)->properties->variableFreeVars);
    UNLINK(sink__V723->context, term__V724);
    ADD_PROPERTIES(sink__V723, LINK_VARIABLESET(sink__V723->context, namedFV__V749), LINK_VARIABLESET(sink__V723->context, varFV__V750), LINK_NamedPropertyLink(sink__V723->context, namedP__V747), LINK_VariablePropertyLink(sink__V723->context, varP__V748));
    { START(sink__V723, _M_FormArguments__binder__count_s2);
      COPY(sink__V723, sub__V744);COPY(sink__V723, sub__V745);COPY(sink__V723, sub__V746);END(sink__V723, _M_FormArguments__binder__count_s2); }
    UNLINK_VARIABLESET(sink__V723->context, namedFV__V749); UNLINK_VARIABLESET(sink__V723->context, varFV__V750);
    UNLINK_NamedPropertyLink(sink__V723->context, namedP__V747); UNLINK_VariablePropertyLink(sink__V723->context, varP__V748);
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Length. */
int conBindOffs_M_Length[] = {0 , 0 , 0};
char *nameFun_M_Length(Term term) { return  "Length" ; }
struct _ConstructionDescriptor descriptor_M_Length = {NULL, 0, 2, sizeof(STRUCT_Con_M_Length), conBindOffs_M_Length, &nameFun_M_Length, &step_M_Length};

int step_M_Length(Sink sink__V751, Term term__V752)
{
  int term__V752_count = LINK_COUNT(term__V752); permitUnusedInt(term__V752_count);
  Term sub__V753 = FORCE(sink__V751->context, SUB(term__V752, 0));
  EnumOf_M__sList choice__V754 = (IS_VARIABLE_USE(sub__V753) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V753));
  switch (choice__V754)
  {
    case Data_M__sNil: { /* Function DEFS-Length-1$Length$$Nil case $Nil */
      ASSERT(sink__V751->context, !strcmp(SYMBOL(term__V752),  "Length" ));
      Term sub__V755 = SUB(term__V752, 0); permitUnusedTerm(sub__V755); int sub__V755_count = term__V752_count*LINK_COUNT(sub__V755); permitUnusedInt(sub__V755_count);
      ASSERT(sink__V751->context, !strcmp(SYMBOL(sub__V755),  "$Nil" ));
      Term sub__V756 = LINK(sink__V751->context, SUB(term__V752, 1)); int sub__V756_count = term__V752_count*LINK_COUNT(sub__V756); permitUnusedInt(sub__V756_count);
      /* sub__V756 = &#0 */
      
      NamedPropertyLink namedP__V757 = LINK_NamedPropertyLink(sink__V751->context, NAMED_PROPERTIES(term__V752));
      VariablePropertyLink varP__V758 = LINK_VariablePropertyLink(sink__V751->context, VARIABLE_PROPERTIES(term__V752));
      Hashset namedFV__V759 = LINK_VARIABLESET(sink__V751->context, asConstruction(term__V752)->properties->namedFreeVars);
      Hashset varFV__V760 = LINK_VARIABLESET(sink__V751->context, asConstruction(term__V752)->properties->variableFreeVars);
      UNLINK(sink__V751->context, term__V752);
      ADD_PROPERTIES(sink__V751, LINK_VARIABLESET(sink__V751->context, namedFV__V759), LINK_VARIABLESET(sink__V751->context, varFV__V760), LINK_NamedPropertyLink(sink__V751->context, namedP__V757), LINK_VariablePropertyLink(sink__V751->context, varP__V758));
      { START(sink__V751, _M_Length_s2);
        COPY(sink__V751, sub__V756);END(sink__V751, _M_Length_s2); }
      UNLINK_VARIABLESET(sink__V751->context, namedFV__V759); UNLINK_VARIABLESET(sink__V751->context, varFV__V760);
      UNLINK_NamedPropertyLink(sink__V751->context, namedP__V757); UNLINK_VariablePropertyLink(sink__V751->context, varP__V758);
      
      return 1;
    break; } case Data_M__sCons: { /* Function DEFS-Length-2$Length$$Cons case $Cons */
      ASSERT(sink__V751->context, !strcmp(SYMBOL(term__V752),  "Length" ));
      Term sub__V761 = SUB(term__V752, 0); permitUnusedTerm(sub__V761); int sub__V761_count = term__V752_count*LINK_COUNT(sub__V761); permitUnusedInt(sub__V761_count);
      ASSERT(sink__V751->context, !strcmp(SYMBOL(sub__V761),  "$Cons" ));
      Term sub__V762 = LINK(sink__V751->context, SUB(sub__V761, 0)); int sub__V762_count = sub__V761_count*LINK_COUNT(sub__V762); permitUnusedInt(sub__V762_count);
      /* sub__V762 = &#0-0 */
      Term sub__V763 = LINK(sink__V751->context, SUB(sub__V761, 1)); int sub__V763_count = sub__V761_count*LINK_COUNT(sub__V763); permitUnusedInt(sub__V763_count);
      /* sub__V763 = &#0-1 */
      Term sub__V764 = LINK(sink__V751->context, SUB(term__V752, 1)); int sub__V764_count = term__V752_count*LINK_COUNT(sub__V764); permitUnusedInt(sub__V764_count);
      /* sub__V764 = &#2 */
      
      NamedPropertyLink namedP__V765 = LINK_NamedPropertyLink(sink__V751->context, NAMED_PROPERTIES(term__V752));
      VariablePropertyLink varP__V766 = LINK_VariablePropertyLink(sink__V751->context, VARIABLE_PROPERTIES(term__V752));
      Hashset namedFV__V767 = LINK_VARIABLESET(sink__V751->context, asConstruction(term__V752)->properties->namedFreeVars);
      Hashset varFV__V768 = LINK_VARIABLESET(sink__V751->context, asConstruction(term__V752)->properties->variableFreeVars);
      UNLINK(sink__V751->context, term__V752);
      ADD_PROPERTIES(sink__V751, LINK_VARIABLESET(sink__V751->context, namedFV__V767), LINK_VARIABLESET(sink__V751->context, varFV__V768), LINK_NamedPropertyLink(sink__V751->context, namedP__V765), LINK_VariablePropertyLink(sink__V751->context, varP__V766));
      { START(sink__V751, _M_Length_s1);
        COPY(sink__V751, sub__V762);COPY(sink__V751, sub__V763);COPY(sink__V751, sub__V764);END(sink__V751, _M_Length_s1); }
      UNLINK_VARIABLESET(sink__V751->context, namedFV__V767); UNLINK_VARIABLESET(sink__V751->context, varFV__V768);
      UNLINK_NamedPropertyLink(sink__V751->context, namedP__V765); UNLINK_VariablePropertyLink(sink__V751->context, varP__V766);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION MapText1$1. */
int conBindOffs_M_MapText1_s1[] = {0 , 0 , 1 , 2};
char *nameFun_M_MapText1_s1(Term term) { return  "MapText1$1" ; }
struct _ConstructionDescriptor descriptor_M_MapText1_s1 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_MapText1_s1), conBindOffs_M_MapText1_s1, &nameFun_M_MapText1_s1, &step_M_MapText1_s1};

int step_M_MapText1_s1(Sink sink__V769, Term term__V770)
{
  int term__V770_count = LINK_COUNT(term__V770); permitUnusedInt(term__V770_count);
  Term sub__V771 = FORCE(sink__V769->context, SUB(term__V770, 0));
  EnumOf_M__sList choice__V772 = (IS_VARIABLE_USE(sub__V771) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V771));
  switch (choice__V772)
  {
    case Data_M__sCons: { /* Function DEFS-MapText1-1$MapText1$1$$Cons case $Cons */
      ASSERT(sink__V769->context, !strcmp(SYMBOL(term__V770),  "MapText1$1" ));
      Term sub__V773 = SUB(term__V770, 0); permitUnusedTerm(sub__V773); int sub__V773_count = term__V770_count*LINK_COUNT(sub__V773); permitUnusedInt(sub__V773_count);
      ASSERT(sink__V769->context, !strcmp(SYMBOL(sub__V773),  "$Cons" ));
      Term sub__V774 = LINK(sink__V769->context, SUB(sub__V773, 0)); int sub__V774_count = sub__V773_count*LINK_COUNT(sub__V774); permitUnusedInt(sub__V774_count);
      /* sub__V774 = &#0-0 */
      Term sub__V775 = LINK(sink__V769->context, SUB(sub__V773, 1)); int sub__V775_count = sub__V773_count*LINK_COUNT(sub__V775); permitUnusedInt(sub__V775_count);
      /* sub__V775 = &#0-1 */
      Variable x__V776 = BINDER(term__V770,1,0); if (term__V770_count <= 1) UNBIND(x__V776);
      Term sub__V777 = LINK(sink__V769->context, SUB(term__V770, 1)); int sub__V777_count = term__V770_count*LINK_COUNT(sub__V777); permitUnusedInt(sub__V777_count);
      CRSX_CHECK_SORT(sink__V769->context, sub__V777, &sort_M_Reified_xVariable); /* sub__V777 = &#2 */
      Variable x__V778 = BINDER(term__V770,2,0); if (term__V770_count <= 1) UNBIND(x__V778);
      Term sub__V779 = LINK(sink__V769->context, SUB(term__V770, 2)); int sub__V779_count = term__V770_count*LINK_COUNT(sub__V779); permitUnusedInt(sub__V779_count);
      CRSX_CHECK_SORT(sink__V769->context, sub__V779, &sort_M_Reified_xVariable); /* sub__V779 = &#3 */
      
      NamedPropertyLink namedP__V780 = LINK_NamedPropertyLink(sink__V769->context, NAMED_PROPERTIES(term__V770));
      VariablePropertyLink varP__V781 = LINK_VariablePropertyLink(sink__V769->context, VARIABLE_PROPERTIES(term__V770));
      Hashset namedFV__V782 = LINK_VARIABLESET(sink__V769->context, asConstruction(term__V770)->properties->namedFreeVars);
      Hashset varFV__V783 = LINK_VARIABLESET(sink__V769->context, asConstruction(term__V770)->properties->variableFreeVars);
      UNLINK(sink__V769->context, term__V770);
      ADD_PROPERTIES(sink__V769, LINK_VARIABLESET(sink__V769->context, namedFV__V782), LINK_VARIABLESET(sink__V769->context, varFV__V783), LINK_NamedPropertyLink(sink__V769->context, namedP__V780), LINK_VariablePropertyLink(sink__V769->context, varP__V781));
      { START(sink__V769, _M_MapText1_s2);
        COPY(sink__V769, sub__V774);COPY(sink__V769, sub__V775);{ if (!IS_BOUND(x__V776)) { REBIND(x__V776);
            Variable binds__V784[1] = {x__V776}; BINDS(sink__V769, 1, binds__V784);
            COPY(sink__V769, sub__V777); /* REUSED SUBSTITUTION */  }
          else { Variable b__V785 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V769->context,"b__V785");
            Variable binds__V786[1] = {b__V785}; BINDS(sink__V769, 1, binds__V786);
            {
              Term arg__V787;
              { Sink buf__V788 = ALLOCA_BUFFER(sink__V769->context);
                USE(buf__V788, b__V785); arg__V787 = BUFFER_TERM(buf__V788); FREE_BUFFER(buf__V788); }
              Variable vars__V789[1] = {x__V776};
              Term args__V790[1] = {arg__V787};
              struct _SubstitutionFrame substitution__V791 = {NULL, 0, 1, vars__V789, args__V790, NULL};
              SUBSTITUTE(sink__V769, sub__V777, &substitution__V791); }
                }
           }
        { if (!IS_BOUND(x__V778)) { REBIND(x__V778);
            Variable binds__V792[1] = {x__V778}; BINDS(sink__V769, 1, binds__V792);
            COPY(sink__V769, sub__V779); /* REUSED SUBSTITUTION */  }
          else { Variable b__V793 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V769->context,"b__V793");
            Variable binds__V794[1] = {b__V793}; BINDS(sink__V769, 1, binds__V794);
            {
              Term arg__V795;
              { Sink buf__V796 = ALLOCA_BUFFER(sink__V769->context);
                USE(buf__V796, b__V793); arg__V795 = BUFFER_TERM(buf__V796); FREE_BUFFER(buf__V796); }
              Variable vars__V797[1] = {x__V778};
              Term args__V798[1] = {arg__V795};
              struct _SubstitutionFrame substitution__V799 = {NULL, 0, 1, vars__V797, args__V798, NULL};
              SUBSTITUTE(sink__V769, sub__V779, &substitution__V799); }
                }
           }
        END(sink__V769, _M_MapText1_s2); }
      UNLINK_VARIABLESET(sink__V769->context, namedFV__V782); UNLINK_VARIABLESET(sink__V769->context, varFV__V783);
      UNLINK_NamedPropertyLink(sink__V769->context, namedP__V780); UNLINK_VariablePropertyLink(sink__V769->context, varP__V781);
      
      return 1;
    break; } case Data_M__sNil: { /* Function DEFS-MapText1-2$MapText1$1$$Nil case $Nil */
      ASSERT(sink__V769->context, !strcmp(SYMBOL(term__V770),  "MapText1$1" ));
      Term sub__V800 = SUB(term__V770, 0); permitUnusedTerm(sub__V800); int sub__V800_count = term__V770_count*LINK_COUNT(sub__V800); permitUnusedInt(sub__V800_count);
      ASSERT(sink__V769->context, !strcmp(SYMBOL(sub__V800),  "$Nil" ));
      Variable x__V801 = BINDER(term__V770,1,0); if (term__V770_count <= 1) UNBIND(x__V801);
      Term sub__V802 = LINK(sink__V769->context, SUB(term__V770, 1)); int sub__V802_count = term__V770_count*LINK_COUNT(sub__V802); permitUnusedInt(sub__V802_count);
      CRSX_CHECK_SORT(sink__V769->context, sub__V802, &sort_M_Reified_xVariable); /* sub__V802 = &#0 */
      Variable x__V803 = BINDER(term__V770,2,0); if (term__V770_count <= 1) UNBIND(x__V803);
      Term sub__V804 = LINK(sink__V769->context, SUB(term__V770, 2)); int sub__V804_count = term__V770_count*LINK_COUNT(sub__V804); permitUnusedInt(sub__V804_count);
      CRSX_CHECK_SORT(sink__V769->context, sub__V804, &sort_M_Reified_xVariable); /* sub__V804 = &#1 */
      
      NamedPropertyLink namedP__V805 = LINK_NamedPropertyLink(sink__V769->context, NAMED_PROPERTIES(term__V770));
      VariablePropertyLink varP__V806 = LINK_VariablePropertyLink(sink__V769->context, VARIABLE_PROPERTIES(term__V770));
      Hashset namedFV__V807 = LINK_VARIABLESET(sink__V769->context, asConstruction(term__V770)->properties->namedFreeVars);
      Hashset varFV__V808 = LINK_VARIABLESET(sink__V769->context, asConstruction(term__V770)->properties->variableFreeVars);
      UNLINK(sink__V769->context, term__V770);
      ADD_PROPERTIES(sink__V769, LINK_VARIABLESET(sink__V769->context, namedFV__V807), LINK_VARIABLESET(sink__V769->context, varFV__V808), LINK_NamedPropertyLink(sink__V769->context, namedP__V805), LINK_VariablePropertyLink(sink__V769->context, varP__V806));
      { START(sink__V769, _M_MapText1_s3);
        { if (!IS_BOUND(x__V801)) { REBIND(x__V801);
            Variable binds__V809[1] = {x__V801}; BINDS(sink__V769, 1, binds__V809);
            COPY(sink__V769, sub__V802); /* REUSED SUBSTITUTION */  }
          else { Variable b__V810 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V769->context,"b__V810");
            Variable binds__V811[1] = {b__V810}; BINDS(sink__V769, 1, binds__V811);
            {
              Term arg__V812;
              { Sink buf__V813 = ALLOCA_BUFFER(sink__V769->context);
                USE(buf__V813, b__V810); arg__V812 = BUFFER_TERM(buf__V813); FREE_BUFFER(buf__V813); }
              Variable vars__V814[1] = {x__V801};
              Term args__V815[1] = {arg__V812};
              struct _SubstitutionFrame substitution__V816 = {NULL, 0, 1, vars__V814, args__V815, NULL};
              SUBSTITUTE(sink__V769, sub__V802, &substitution__V816); }
                }
           }
        { if (!IS_BOUND(x__V803)) { REBIND(x__V803);
            Variable binds__V817[1] = {x__V803}; BINDS(sink__V769, 1, binds__V817);
            COPY(sink__V769, sub__V804); /* REUSED SUBSTITUTION */  }
          else { Variable b__V818 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V769->context,"b__V818");
            Variable binds__V819[1] = {b__V818}; BINDS(sink__V769, 1, binds__V819);
            {
              Term arg__V820;
              { Sink buf__V821 = ALLOCA_BUFFER(sink__V769->context);
                USE(buf__V821, b__V818); arg__V820 = BUFFER_TERM(buf__V821); FREE_BUFFER(buf__V821); }
              Variable vars__V822[1] = {x__V803};
              Term args__V823[1] = {arg__V820};
              struct _SubstitutionFrame substitution__V824 = {NULL, 0, 1, vars__V822, args__V823, NULL};
              SUBSTITUTE(sink__V769, sub__V804, &substitution__V824); }
                }
           }
        END(sink__V769, _M_MapText1_s3); }
      UNLINK_VARIABLESET(sink__V769->context, namedFV__V807); UNLINK_VARIABLESET(sink__V769->context, varFV__V808);
      UNLINK_NamedPropertyLink(sink__V769->context, namedP__V805); UNLINK_VariablePropertyLink(sink__V769->context, varP__V806);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION MapText1$2. */
int conBindOffs_M_MapText1_s2[] = {0 , 0 , 0 , 1 , 2};
char *nameFun_M_MapText1_s2(Term term) { return  "MapText1$2" ; }
struct _ConstructionDescriptor descriptor_M_MapText1_s2 = {&sort_M_Reified_xVariable, 0, 4, sizeof(STRUCT_Con_M_MapText1_s2), conBindOffs_M_MapText1_s2, &nameFun_M_MapText1_s2, &step_M_MapText1_s2};

int step_M_MapText1_s2(Sink sink__V825, Term term__V826)
{
  int term__V826_count = LINK_COUNT(term__V826); permitUnusedInt(term__V826_count);
  do {
    /* Contraction rule DEFS-MapText1-1. */
    ASSERT(sink__V825->context, !strcmp(SYMBOL(term__V826),  "MapText1$2" ));
    Term sub__V827 = LINK(sink__V825->context, SUB(term__V826, 0)); int sub__V827_count = term__V826_count*LINK_COUNT(sub__V827); permitUnusedInt(sub__V827_count);
    /* sub__V827 = &#31 */
    Term sub__V828 = LINK(sink__V825->context, SUB(term__V826, 1)); int sub__V828_count = term__V826_count*LINK_COUNT(sub__V828); permitUnusedInt(sub__V828_count);
    /* sub__V828 = &#32 */
    Variable x__V829 = BINDER(term__V826,2,0); if (term__V826_count <= 1) UNBIND(x__V829);
    Term sub__V830 = LINK(sink__V825->context, SUB(term__V826, 2)); int sub__V830_count = term__V826_count*LINK_COUNT(sub__V830); permitUnusedInt(sub__V830_count);
    CRSX_CHECK_SORT(sink__V825->context, sub__V830, &sort_M_Reified_xVariable); /* sub__V830 = &#2 */
    Variable x__V831 = BINDER(term__V826,3,0); if (term__V826_count <= 1) UNBIND(x__V831);
    Term sub__V832 = LINK(sink__V825->context, SUB(term__V826, 3)); int sub__V832_count = term__V826_count*LINK_COUNT(sub__V832); permitUnusedInt(sub__V832_count);
    CRSX_CHECK_SORT(sink__V825->context, sub__V832, &sort_M_Reified_xVariable); /* sub__V832 = &#1 */
    
    NamedPropertyLink namedP__V833 = LINK_NamedPropertyLink(sink__V825->context, NAMED_PROPERTIES(term__V826));
    VariablePropertyLink varP__V834 = LINK_VariablePropertyLink(sink__V825->context, VARIABLE_PROPERTIES(term__V826));
    Hashset namedFV__V835 = LINK_VARIABLESET(sink__V825->context, asConstruction(term__V826)->properties->namedFreeVars);
    Hashset varFV__V836 = LINK_VARIABLESET(sink__V825->context, asConstruction(term__V826)->properties->variableFreeVars);
    UNLINK(sink__V825->context, term__V826);
    { START(sink__V825, _M__sTextCons);
      { START(sink__V825, _M__sTextEmbed);
        { START(sink__V825, _M_AsText);
          {
            Term arg__V837;
            { Sink buf__V838 = ALLOCA_BUFFER(sink__V825->context);
              COPY(buf__V838, sub__V827);arg__V837 = BUFFER_TERM(buf__V838); FREE_BUFFER(buf__V838); }
            Variable vars__V839[1] = {x__V831};
            Term args__V840[1] = {arg__V837};
            struct _SubstitutionFrame substitution__V841 = {NULL, 0, 1, vars__V839, args__V840, NULL};
            SUBSTITUTE(sink__V825, sub__V832, &substitution__V841); }
          END(sink__V825, _M_AsText); }
        END(sink__V825, _M__sTextEmbed); }
      { START(sink__V825, _M__sTextCons);
        { START(sink__V825, _M__sTextEmbed);
          { START(sink__V825, _M_AsText);
            { START(sink__V825, _M_MapText_s1);
              COPY(sink__V825, sub__V828);{ if (!IS_BOUND(x__V829)) { REBIND(x__V829);
                  Variable binds__V842[1] = {x__V829}; BINDS(sink__V825, 1, binds__V842);
                  COPY(sink__V825, sub__V830); /* REUSED SUBSTITUTION */  }
                else { Variable b__V843 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V825->context,"b__V843");
                  Variable binds__V844[1] = {b__V843}; BINDS(sink__V825, 1, binds__V844);
                  {
                    Term arg__V845;
                    { Sink buf__V846 = ALLOCA_BUFFER(sink__V825->context);
                      USE(buf__V846, b__V843); arg__V845 = BUFFER_TERM(buf__V846); FREE_BUFFER(buf__V846); }
                    Variable vars__V847[1] = {x__V829};
                    Term args__V848[1] = {arg__V845};
                    struct _SubstitutionFrame substitution__V849 = {NULL, 0, 1, vars__V847, args__V848, NULL};
                    SUBSTITUTE(sink__V825, sub__V830, &substitution__V849); }
                      }
                 }
              END(sink__V825, _M_MapText_s1); }
            END(sink__V825, _M_AsText); }
          END(sink__V825, _M__sTextEmbed); }
        { START(sink__V825, _M__sTextNil);
          END(sink__V825, _M__sTextNil); }
        END(sink__V825, _M__sTextCons); }
      END(sink__V825, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V825->context, namedFV__V835); UNLINK_VARIABLESET(sink__V825->context, varFV__V836);
    UNLINK_NamedPropertyLink(sink__V825->context, namedP__V833); UNLINK_VariablePropertyLink(sink__V825->context, varP__V834);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION MapText1$3. */
int conBindOffs_M_MapText1_s3[] = {0 , 1 , 2};
char *nameFun_M_MapText1_s3(Term term) { return  "MapText1$3" ; }
struct _ConstructionDescriptor descriptor_M_MapText1_s3 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_MapText1_s3), conBindOffs_M_MapText1_s3, &nameFun_M_MapText1_s3, &step_M_MapText1_s3};

int step_M_MapText1_s3(Sink sink__V850, Term term__V851)
{
  int term__V851_count = LINK_COUNT(term__V851); permitUnusedInt(term__V851_count);
  do {
    /* Contraction rule DEFS-MapText1-2. */
    ASSERT(sink__V850->context, !strcmp(SYMBOL(term__V851),  "MapText1$3" ));
    Variable x__V852 = BINDER(term__V851,0,0); if (term__V851_count <= 1) UNBIND(x__V852);
    Term sub__V853 = SUB(term__V851, 0); permitUnusedTerm(sub__V853); int sub__V853_count = term__V851_count*LINK_COUNT(sub__V853); permitUnusedInt(sub__V853_count);
    CRSX_CHECK_SORT(sink__V850->context, sub__V853, &sort_M_Reified_xVariable); /* sub__V853 = &#2 */
    Variable x__V854 = BINDER(term__V851,1,0); if (term__V851_count <= 1) UNBIND(x__V854);
    Term sub__V855 = SUB(term__V851, 1); permitUnusedTerm(sub__V855); int sub__V855_count = term__V851_count*LINK_COUNT(sub__V855); permitUnusedInt(sub__V855_count);
    CRSX_CHECK_SORT(sink__V850->context, sub__V855, &sort_M_Reified_xVariable); /* sub__V855 = &#1 */
    
    NamedPropertyLink namedP__V856 = LINK_NamedPropertyLink(sink__V850->context, NAMED_PROPERTIES(term__V851));
    VariablePropertyLink varP__V857 = LINK_VariablePropertyLink(sink__V850->context, VARIABLE_PROPERTIES(term__V851));
    Hashset namedFV__V858 = LINK_VARIABLESET(sink__V850->context, asConstruction(term__V851)->properties->namedFreeVars);
    Hashset varFV__V859 = LINK_VARIABLESET(sink__V850->context, asConstruction(term__V851)->properties->variableFreeVars);
    UNLINK(sink__V850->context, term__V851);
    { START(sink__V850, _M__sTextNil); END(sink__V850, _M__sTextNil); }
    UNLINK_VARIABLESET(sink__V850->context, namedFV__V858); UNLINK_VARIABLESET(sink__V850->context, varFV__V859);
    UNLINK_NamedPropertyLink(sink__V850->context, namedP__V856); UNLINK_VariablePropertyLink(sink__V850->context, varP__V857);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DCOMMENT_TOKEN$1. */
int conBindOffs_M_DCOMMENT_xTOKEN_s1[] = {0 , 0};
char *nameFun_M_DCOMMENT_xTOKEN_s1(Term term) { return  "DCOMMENT_TOKEN$1" ; }
struct _ConstructionDescriptor descriptor_M_DCOMMENT_xTOKEN_s1 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_DCOMMENT_xTOKEN_s1), conBindOffs_M_DCOMMENT_xTOKEN_s1, &nameFun_M_DCOMMENT_xTOKEN_s1, &step_M_DCOMMENT_xTOKEN_s1};

int step_M_DCOMMENT_xTOKEN_s1(Sink sink__V860, Term term__V861)
{
  int term__V861_count = LINK_COUNT(term__V861); permitUnusedInt(term__V861_count);
  do {
    /* Contraction rule DEFS-DCOMMENT_TOKEN-1. */
    ASSERT(sink__V860->context, !strcmp(SYMBOL(term__V861),  "DCOMMENT_TOKEN$1" ));
    Term sub__V862 = LINK(sink__V860->context, SUB(term__V861, 0)); int sub__V862_count = term__V861_count*LINK_COUNT(sub__V862); permitUnusedInt(sub__V862_count);
    UNLINK_SUB(sink__V860->context, term__V861,  0); NORMALIZE(sink__V860->context, sub__V862); SUB(term__V861,  0) = LINK(sink__V860->context, sub__V862);
    /* sub__V862 = &#2 */
    
    NamedPropertyLink namedP__V863 = LINK_NamedPropertyLink(sink__V860->context, NAMED_PROPERTIES(term__V861));
    VariablePropertyLink varP__V864 = LINK_VariablePropertyLink(sink__V860->context, VARIABLE_PROPERTIES(term__V861));
    Hashset namedFV__V865 = LINK_VARIABLESET(sink__V860->context, asConstruction(term__V861)->properties->namedFreeVars);
    Hashset varFV__V866 = LINK_VARIABLESET(sink__V860->context, asConstruction(term__V861)->properties->variableFreeVars);
    UNLINK(sink__V860->context, term__V861);
    { START(sink__V860, _M__sTextCons);
      { START(sink__V860, _M__sTextChars);
        { char *str__V867;
          FORCE(sink__V860->context, sub__V862); LINK(sink__V860->context, sub__V862);
          { char *replaced__V868;
            const size_t z = strlen(SYMBOL(sub__V862));
            if (* "*/" ) {
              const size_t oldz = strlen( "*/" ), newz = strlen( "*_/" );
              size_t limitz;
              if (oldz==newz) { limitz = z; }
              else { limitz = z; size_t growz = (oldz < newz ? newz - oldz : 0);
                if (growz > 0) { char *p = SYMBOL(sub__V862); while ((p = strstr(p,  "*/" ))) { limitz += growz; p += oldz; } } }
              replaced__V868 = ALLOCA(sink__V860->context, limitz+1);
              if (oldz==newz) { memcpy(replaced__V868, SYMBOL(sub__V862), z+1);
                char *r = replaced__V868; while ((r = strstr(r,  "*/" ))) { memcpy(r,  "*_/" , newz); r += oldz; } }
              else { char *s = SYMBOL(sub__V862), *ends = s+z, *r = replaced__V868, *next;
                while ((next = strstr(s,  "*/" ))) { size_t prez = next-s;
                  if (prez) { memcpy(r, s, prez); r += prez; } 
                  if (newz) { memcpy(r,  "*_/" , newz); r += newz; }
                  s = next+oldz;}
                if (s < ends) { memcpy(r, s, ends-s); r += ends-s; }
                *r = '\0';}
              }
            else { replaced__V868 = memcpy(ALLOCA(sink__V860->context, z+1), SYMBOL(sub__V862), z+1); }
             UNLINK(sink__V860->context, sub__V862);  UNLINK(sink__V860->context, sub__V862); { size_t z__V869 = strlen(replaced__V868) + 1; memcpy(str__V867 = ALLOCATE(sink__V860->context, z__V869), replaced__V868, z__V869); }
            
          }LITERALU(sink__V860, str__V867); }
        END(sink__V860, _M__sTextChars); }
      { START(sink__V860, _M__sTextNil);
        END(sink__V860, _M__sTextNil); }
      END(sink__V860, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V860->context, namedFV__V865); UNLINK_VARIABLESET(sink__V860->context, varFV__V866);
    UNLINK_NamedPropertyLink(sink__V860->context, namedP__V863); UNLINK_VariablePropertyLink(sink__V860->context, varP__V864);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Length$2. */
int conBindOffs_M_Length_s2[] = {0 , 0};
char *nameFun_M_Length_s2(Term term) { return  "Length$2" ; }
struct _ConstructionDescriptor descriptor_M_Length_s2 = {NULL, 0, 1, sizeof(STRUCT_Con_M_Length_s2), conBindOffs_M_Length_s2, &nameFun_M_Length_s2, &step_M_Length_s2};

int step_M_Length_s2(Sink sink__V870, Term term__V871)
{
  int term__V871_count = LINK_COUNT(term__V871); permitUnusedInt(term__V871_count);
  do {
    /* Contraction rule DEFS-Length-1. */
    ASSERT(sink__V870->context, !strcmp(SYMBOL(term__V871),  "Length$2" ));
    Term sub__V872 = LINK(sink__V870->context, SUB(term__V871, 0)); int sub__V872_count = term__V871_count*LINK_COUNT(sub__V872); permitUnusedInt(sub__V872_count);
    /* sub__V872 = &#2 */
    UNLINK(sink__V870->context, term__V871);
    COPY(sink__V870, sub__V872);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Length$1. */
int conBindOffs_M_Length_s1[] = {0 , 0 , 0 , 0};
char *nameFun_M_Length_s1(Term term) { return  "Length$1" ; }
struct _ConstructionDescriptor descriptor_M_Length_s1 = {NULL, 0, 3, sizeof(STRUCT_Con_M_Length_s1), conBindOffs_M_Length_s1, &nameFun_M_Length_s1, &step_M_Length_s1};

int step_M_Length_s1(Sink sink__V873, Term term__V874)
{
  int term__V874_count = LINK_COUNT(term__V874); permitUnusedInt(term__V874_count);
  do {
    /* Contraction rule DEFS-Length-2. */
    ASSERT(sink__V873->context, !strcmp(SYMBOL(term__V874),  "Length$1" ));
    Term sub__V875 = SUB(term__V874, 0); permitUnusedTerm(sub__V875); int sub__V875_count = term__V874_count*LINK_COUNT(sub__V875); permitUnusedInt(sub__V875_count);
    /* sub__V875 = &#11 */
    Term sub__V876 = LINK(sink__V873->context, SUB(term__V874, 1)); int sub__V876_count = term__V874_count*LINK_COUNT(sub__V876); permitUnusedInt(sub__V876_count);
    /* sub__V876 = &#12 */
    Term sub__V877 = LINK(sink__V873->context, SUB(term__V874, 2)); int sub__V877_count = term__V874_count*LINK_COUNT(sub__V877); permitUnusedInt(sub__V877_count);
    /* sub__V877 = &#2 */
    UNLINK(sink__V873->context, term__V874);
    { START(sink__V873, _M_Length);
      COPY(sink__V873, sub__V876);{ double num__V878;
        num__V878 = (double) 1; { double tmp__V879;
          tmp__V879 = DOUBLE(sub__V877); num__V878 += tmp__V879; }
        LITERALNF(sink__V873, (size_t) 31, "%G", num__V878); }
      END(sink__V873, _M_Length); }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Name. */
int conBindOffs_M_Name[] = {0 , 0};
char *nameFun_M_Name(Term term) { return  "Name" ; }
struct _ConstructionDescriptor descriptor_M_Name = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_Name), conBindOffs_M_Name, &nameFun_M_Name, &step_M_Name};

int step_M_Name(Sink sink__V880, Term term__V881)
{
  int term__V881_count = LINK_COUNT(term__V881); permitUnusedInt(term__V881_count);
  do {
    /* Contraction rule DEFS-Name-1. */
    ASSERT(sink__V880->context, !strcmp(SYMBOL(term__V881),  "Name" ));
    Term sub__V882 = LINK(sink__V880->context, SUB(term__V881, 0)); int sub__V882_count = term__V881_count*LINK_COUNT(sub__V882); permitUnusedInt(sub__V882_count);
    /* sub__V882 = &#1 */
    
    NamedPropertyLink namedP__V883 = LINK_NamedPropertyLink(sink__V880->context, NAMED_PROPERTIES(term__V881));
    VariablePropertyLink varP__V884 = LINK_VariablePropertyLink(sink__V880->context, VARIABLE_PROPERTIES(term__V881));
    Hashset namedFV__V885 = LINK_VARIABLESET(sink__V880->context, asConstruction(term__V881)->properties->namedFreeVars);
    Hashset varFV__V886 = LINK_VARIABLESET(sink__V880->context, asConstruction(term__V881)->properties->variableFreeVars);
    UNLINK(sink__V880->context, term__V881);
    { START(sink__V880, _M__sTextCons);
      { START(sink__V880, _M__sTextChars);
        LITERAL(sink__V880,  "name" ); END(sink__V880, _M__sTextChars); }
      { START(sink__V880, _M__sTextCons);
        { START(sink__V880, _M__sTextEmbed);
          { START(sink__V880, _M_AsText);
            { START(sink__V880, _M_MANGLE);
              COPY(sink__V880, sub__V882);END(sink__V880, _M_MANGLE); }
            END(sink__V880, _M_AsText); }
          END(sink__V880, _M__sTextEmbed); }
        { START(sink__V880, _M__sTextNil);
          END(sink__V880, _M__sTextNil); }
        END(sink__V880, _M__sTextCons); }
      END(sink__V880, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V880->context, namedFV__V885); UNLINK_VARIABLESET(sink__V880->context, varFV__V886);
    UNLINK_NamedPropertyLink(sink__V880->context, namedP__V883); UNLINK_VariablePropertyLink(sink__V880->context, varP__V884);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION TOKEN. */
int conBindOffs_M_TOKEN[] = {0 , 0};
char *nameFun_M_TOKEN(Term term) { return  "TOKEN" ; }
struct _ConstructionDescriptor descriptor_M_TOKEN = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_TOKEN), conBindOffs_M_TOKEN, &nameFun_M_TOKEN, &step_M_TOKEN};

int step_M_TOKEN(Sink sink__V887, Term term__V888)
{
  int term__V888_count = LINK_COUNT(term__V888); permitUnusedInt(term__V888_count);
  do {
    /* Contraction rule DEFS-TOKEN-1. */
    ASSERT(sink__V887->context, !strcmp(SYMBOL(term__V888),  "TOKEN" ));
    Term sub__V889 = LINK(sink__V887->context, SUB(term__V888, 0)); int sub__V889_count = term__V888_count*LINK_COUNT(sub__V889); permitUnusedInt(sub__V889_count);
    UNLINK_SUB(sink__V887->context, term__V888,  0); NORMALIZE(sink__V887->context, sub__V889); SUB(term__V888,  0) = LINK(sink__V887->context, sub__V889);
    /* sub__V889 = &#1 */
    
    NamedPropertyLink namedP__V890 = LINK_NamedPropertyLink(sink__V887->context, NAMED_PROPERTIES(term__V888));
    VariablePropertyLink varP__V891 = LINK_VariablePropertyLink(sink__V887->context, VARIABLE_PROPERTIES(term__V888));
    Hashset namedFV__V892 = LINK_VARIABLESET(sink__V887->context, asConstruction(term__V888)->properties->namedFreeVars);
    Hashset varFV__V893 = LINK_VARIABLESET(sink__V887->context, asConstruction(term__V888)->properties->variableFreeVars);
    UNLINK(sink__V887->context, term__V888);
    { START(sink__V887, _M__sTextCons);
      { START(sink__V887, _M__sTextChars);
        COPY(sink__V887, sub__V889);END(sink__V887, _M__sTextChars); }
      { START(sink__V887, _M__sTextNil);
        END(sink__V887, _M__sTextNil); }
      END(sink__V887, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V887->context, namedFV__V892); UNLINK_VARIABLESET(sink__V887->context, varFV__V893);
    UNLINK_NamedPropertyLink(sink__V887->context, namedP__V890); UNLINK_VariablePropertyLink(sink__V887->context, varP__V891);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DSTRING. */
int conBindOffs_M_DSTRING[] = {0 , 0 , 0};
char *nameFun_M_DSTRING(Term term) { return  "DSTRING" ; }
struct _ConstructionDescriptor descriptor_M_DSTRING = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_DSTRING), conBindOffs_M_DSTRING, &nameFun_M_DSTRING, &step_M_DSTRING};

int step_M_DSTRING(Sink sink__V894, Term term__V895)
{
  int term__V895_count = LINK_COUNT(term__V895); permitUnusedInt(term__V895_count);
  Term sub__V896 = FORCE(sink__V894->context, SUB(term__V895, 0));
  EnumOf_M_OK_xSORT choice__V897 = (IS_VARIABLE_USE(sub__V896) ? VarOf_M_OK_xSORT : (EnumOf_M_OK_xSORT) TAG(sub__V896));
  switch (choice__V897)
  {
    case Data_M_OK: { /* Function DEFS-DSTRING-1$DSTRING$OK case OK */
      ASSERT(sink__V894->context, !strcmp(SYMBOL(term__V895),  "DSTRING" ));
      Term sub__V898 = SUB(term__V895, 0); permitUnusedTerm(sub__V898); int sub__V898_count = term__V895_count*LINK_COUNT(sub__V898); permitUnusedInt(sub__V898_count);
      CRSX_CHECK_SORT(sink__V894->context, sub__V898, &sort_M_OK_xSORT); ASSERT(sink__V894->context, !strcmp(SYMBOL(sub__V898),  "OK" ));
      Term sub__V899 = LINK(sink__V894->context, SUB(term__V895, 1)); int sub__V899_count = term__V895_count*LINK_COUNT(sub__V899); permitUnusedInt(sub__V899_count);
      /* sub__V899 = &#0 */
      
      NamedPropertyLink namedP__V900 = LINK_NamedPropertyLink(sink__V894->context, NAMED_PROPERTIES(term__V895));
      VariablePropertyLink varP__V901 = LINK_VariablePropertyLink(sink__V894->context, VARIABLE_PROPERTIES(term__V895));
      Hashset namedFV__V902 = LINK_VARIABLESET(sink__V894->context, asConstruction(term__V895)->properties->namedFreeVars);
      Hashset varFV__V903 = LINK_VARIABLESET(sink__V894->context, asConstruction(term__V895)->properties->variableFreeVars);
      UNLINK(sink__V894->context, term__V895);
      ADD_PROPERTIES(sink__V894, LINK_VARIABLESET(sink__V894->context, namedFV__V902), LINK_VARIABLESET(sink__V894->context, varFV__V903), LINK_NamedPropertyLink(sink__V894->context, namedP__V900), LINK_VariablePropertyLink(sink__V894->context, varP__V901));
      { START(sink__V894, _M_DSTRING_s1);
        COPY(sink__V894, sub__V899);END(sink__V894, _M_DSTRING_s1); }
      UNLINK_VARIABLESET(sink__V894->context, namedFV__V902); UNLINK_VARIABLESET(sink__V894->context, varFV__V903);
      UNLINK_NamedPropertyLink(sink__V894->context, namedP__V900); UNLINK_VariablePropertyLink(sink__V894->context, varP__V901);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION SortInternals. */
int conBindOffs_M_SortInternals[] = {0 , 0};
char *nameFun_M_SortInternals(Term term) { return  "SortInternals" ; }
struct _ConstructionDescriptor descriptor_M_SortInternals = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_SortInternals), conBindOffs_M_SortInternals, &nameFun_M_SortInternals, &step_M_SortInternals};

int step_M_SortInternals(Sink sink__V904, Term term__V905)
{
  int term__V905_count = LINK_COUNT(term__V905); permitUnusedInt(term__V905_count);
  do {
    /* Contraction rule DEFS-SortInternals-1. */
    ASSERT(sink__V904->context, !strcmp(SYMBOL(term__V905),  "SortInternals" ));
    Term sub__V906 = LINK(sink__V904->context, SUB(term__V905, 0)); int sub__V906_count = term__V905_count*LINK_COUNT(sub__V906); permitUnusedInt(sub__V906_count);
    /* sub__V906 = &#1 */
    
    NamedPropertyLink namedP__V907 = LINK_NamedPropertyLink(sink__V904->context, NAMED_PROPERTIES(term__V905));
    VariablePropertyLink varP__V908 = LINK_VariablePropertyLink(sink__V904->context, VARIABLE_PROPERTIES(term__V905));
    Hashset namedFV__V909 = LINK_VARIABLESET(sink__V904->context, asConstruction(term__V905)->properties->namedFreeVars);
    Hashset varFV__V910 = LINK_VARIABLESET(sink__V904->context, asConstruction(term__V905)->properties->variableFreeVars);
    UNLINK(sink__V904->context, term__V905);
    { START(sink__V904, _M__sTextCons);
      { START(sink__V904, _M__sTextChars);
        LITERAL(sink__V904,  "sortInt" ); END(sink__V904, _M__sTextChars); }
      { START(sink__V904, _M__sTextCons);
        { START(sink__V904, _M__sTextEmbed);
          { START(sink__V904, _M_AsText);
            { START(sink__V904, _M_MANGLE);
              COPY(sink__V904, sub__V906);END(sink__V904, _M_MANGLE); }
            END(sink__V904, _M_AsText); }
          END(sink__V904, _M__sTextEmbed); }
        { START(sink__V904, _M__sTextNil);
          END(sink__V904, _M__sTextNil); }
        END(sink__V904, _M__sTextCons); }
      END(sink__V904, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V904->context, namedFV__V909); UNLINK_VARIABLESET(sink__V904->context, varFV__V910);
    UNLINK_NamedPropertyLink(sink__V904->context, namedP__V907); UNLINK_VariablePropertyLink(sink__V904->context, varP__V908);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION UnString$1. */
int conBindOffs_M_UnString_s1[] = {0 , 0};
char *nameFun_M_UnString_s1(Term term) { return  "UnString$1" ; }
struct _ConstructionDescriptor descriptor_M_UnString_s1 = {NULL, 0, 1, sizeof(STRUCT_Con_M_UnString_s1), conBindOffs_M_UnString_s1, &nameFun_M_UnString_s1, &step_M_UnString_s1};

int step_M_UnString_s1(Sink sink__V911, Term term__V912)
{
  int term__V912_count = LINK_COUNT(term__V912); permitUnusedInt(term__V912_count);
  do {
    /* Contraction rule DEFS-UnString-1. */
    ASSERT(sink__V911->context, !strcmp(SYMBOL(term__V912),  "UnString$1" ));
    Term sub__V913 = LINK(sink__V911->context, SUB(term__V912, 0)); int sub__V913_count = term__V912_count*LINK_COUNT(sub__V913); permitUnusedInt(sub__V913_count);
    /* sub__V913 = &#11 */
    UNLINK(sink__V911->context, term__V912);
    COPY(sink__V911, sub__V913);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Descriptor. */
int conBindOffs_M_Descriptor[] = {0 , 0};
char *nameFun_M_Descriptor(Term term) { return  "Descriptor" ; }
struct _ConstructionDescriptor descriptor_M_Descriptor = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_Descriptor), conBindOffs_M_Descriptor, &nameFun_M_Descriptor, &step_M_Descriptor};

int step_M_Descriptor(Sink sink__V914, Term term__V915)
{
  int term__V915_count = LINK_COUNT(term__V915); permitUnusedInt(term__V915_count);
  do {
    /* Contraction rule DEFS-Descriptor-1. */
    ASSERT(sink__V914->context, !strcmp(SYMBOL(term__V915),  "Descriptor" ));
    Term sub__V916 = LINK(sink__V914->context, SUB(term__V915, 0)); int sub__V916_count = term__V915_count*LINK_COUNT(sub__V916); permitUnusedInt(sub__V916_count);
    /* sub__V916 = &#1 */
    
    NamedPropertyLink namedP__V917 = LINK_NamedPropertyLink(sink__V914->context, NAMED_PROPERTIES(term__V915));
    VariablePropertyLink varP__V918 = LINK_VariablePropertyLink(sink__V914->context, VARIABLE_PROPERTIES(term__V915));
    Hashset namedFV__V919 = LINK_VARIABLESET(sink__V914->context, asConstruction(term__V915)->properties->namedFreeVars);
    Hashset varFV__V920 = LINK_VARIABLESET(sink__V914->context, asConstruction(term__V915)->properties->variableFreeVars);
    UNLINK(sink__V914->context, term__V915);
    { START(sink__V914, _M__sTextCons);
      { START(sink__V914, _M__sTextChars);
        LITERAL(sink__V914,  "descriptor" ); END(sink__V914, _M__sTextChars); }
      { START(sink__V914, _M__sTextCons);
        { START(sink__V914, _M__sTextEmbed);
          { START(sink__V914, _M_AsText);
            { START(sink__V914, _M_MANGLE);
              COPY(sink__V914, sub__V916);END(sink__V914, _M_MANGLE); }
            END(sink__V914, _M_AsText); }
          END(sink__V914, _M__sTextEmbed); }
        { START(sink__V914, _M__sTextNil);
          END(sink__V914, _M__sTextNil); }
        END(sink__V914, _M__sTextCons); }
      END(sink__V914, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V914->context, namedFV__V919); UNLINK_VARIABLESET(sink__V914->context, varFV__V920);
    UNLINK_NamedPropertyLink(sink__V914->context, namedP__V917); UNLINK_VariablePropertyLink(sink__V914->context, varP__V918);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Forms-Constructors$5. */
int conBindOffs_M_Forms_Constructors_s5[] = {0};
char *nameFun_M_Forms_Constructors_s5(Term term) { return  "Forms-Constructors$5" ; }
struct _ConstructionDescriptor descriptor_M_Forms_Constructors_s5 = {NULL, 0, 0, sizeof(STRUCT_Con_M_Forms_Constructors_s5), conBindOffs_M_Forms_Constructors_s5, &nameFun_M_Forms_Constructors_s5, &step_M_Forms_Constructors_s5};

int step_M_Forms_Constructors_s5(Sink sink__V921, Term term__V922)
{
  int term__V922_count = LINK_COUNT(term__V922); permitUnusedInt(term__V922_count);
  do {
    /* Contraction rule DEFS-Forms-Constructors-4. */
    ASSERT(sink__V921->context, !strcmp(SYMBOL(term__V922),  "Forms-Constructors$5" ));
    UNLINK(sink__V921->context, term__V922);
    { START(sink__V921, _M__sNil); END(sink__V921, _M__sNil); } 
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Forms-Constructors$2. */
int conBindOffs_M_Forms_Constructors_s2[] = {0 , 0 , 0 , 0};
char *nameFun_M_Forms_Constructors_s2(Term term) { return  "Forms-Constructors$2" ; }
struct _ConstructionDescriptor descriptor_M_Forms_Constructors_s2 = {NULL, 0, 3, sizeof(STRUCT_Con_M_Forms_Constructors_s2), conBindOffs_M_Forms_Constructors_s2, &nameFun_M_Forms_Constructors_s2, &step_M_Forms_Constructors_s2};

int step_M_Forms_Constructors_s2(Sink sink__V923, Term term__V924)
{
  int term__V924_count = LINK_COUNT(term__V924); permitUnusedInt(term__V924_count);
  do {
    /* Contraction rule DEFS-Forms-Constructors-3. */
    ASSERT(sink__V923->context, !strcmp(SYMBOL(term__V924),  "Forms-Constructors$2" ));
    Term sub__V925 = LINK(sink__V923->context, SUB(term__V924, 0)); int sub__V925_count = term__V924_count*LINK_COUNT(sub__V925); permitUnusedInt(sub__V925_count);
    /* sub__V925 = &#111 */
    Term sub__V926 = SUB(term__V924, 1); permitUnusedTerm(sub__V926); int sub__V926_count = term__V924_count*LINK_COUNT(sub__V926); permitUnusedInt(sub__V926_count);
    /* sub__V926 = &#112 */
    Term sub__V927 = LINK(sink__V923->context, SUB(term__V924, 2)); int sub__V927_count = term__V924_count*LINK_COUNT(sub__V927); permitUnusedInt(sub__V927_count);
    /* sub__V927 = &#12 */
    UNLINK(sink__V923->context, term__V924);
    { START(sink__V923, _M__sCons);
      COPY(sink__V923, sub__V925);{ START(sink__V923, _M_Forms_Constructors);
        COPY(sink__V923, sub__V927);END(sink__V923, _M_Forms_Constructors); }
      END(sink__V923, _M__sCons); }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Forms-Constructors$1. */
int conBindOffs_M_Forms_Constructors_s1[] = {0 , 0 , 0};
char *nameFun_M_Forms_Constructors_s1(Term term) { return  "Forms-Constructors$1" ; }
struct _ConstructionDescriptor descriptor_M_Forms_Constructors_s1 = {NULL, 0, 2, sizeof(STRUCT_Con_M_Forms_Constructors_s1), conBindOffs_M_Forms_Constructors_s1, &nameFun_M_Forms_Constructors_s1, &step_M_Forms_Constructors_s1};

int step_M_Forms_Constructors_s1(Sink sink__V928, Term term__V929)
{
  int term__V929_count = LINK_COUNT(term__V929); permitUnusedInt(term__V929_count);
  do {
    /* Contraction rule DEFS-Forms-Constructors-1$Forms-Constructors$1$SORT-ALLOWS-VARIABLES. */
    ASSERT(sink__V928->context, !strcmp(SYMBOL(term__V929),  "Forms-Constructors$1" ));
    Term sub__V930 = SUB(term__V929, 0); permitUnusedTerm(sub__V930); int sub__V930_count = term__V929_count*LINK_COUNT(sub__V930); permitUnusedInt(sub__V930_count);
    FORCE(sink__V928->context, sub__V930); SUB(term__V929, 0) = sub__V930;
    if (strcmp(SYMBOL(sub__V930),  "SORT-ALLOWS-VARIABLES" )) break;
    Term sub__V931 = LINK(sink__V928->context, SUB(term__V929, 1)); int sub__V931_count = term__V929_count*LINK_COUNT(sub__V931); permitUnusedInt(sub__V931_count);
    /* sub__V931 = &#0 */
    
    NamedPropertyLink namedP__V932 = LINK_NamedPropertyLink(sink__V928->context, NAMED_PROPERTIES(term__V929));
    VariablePropertyLink varP__V933 = LINK_VariablePropertyLink(sink__V928->context, VARIABLE_PROPERTIES(term__V929));
    Hashset namedFV__V934 = LINK_VARIABLESET(sink__V928->context, asConstruction(term__V929)->properties->namedFreeVars);
    Hashset varFV__V935 = LINK_VARIABLESET(sink__V928->context, asConstruction(term__V929)->properties->variableFreeVars);
    UNLINK(sink__V928->context, term__V929);
    ADD_PROPERTIES(sink__V928, LINK_VARIABLESET(sink__V928->context, namedFV__V934), LINK_VARIABLESET(sink__V928->context, varFV__V935), LINK_NamedPropertyLink(sink__V928->context, namedP__V932), LINK_VariablePropertyLink(sink__V928->context, varP__V933));
    { START(sink__V928, _M_Forms_Constructors_s3);
      COPY(sink__V928, sub__V931);END(sink__V928, _M_Forms_Constructors_s3); }
    UNLINK_VARIABLESET(sink__V928->context, namedFV__V934); UNLINK_VARIABLESET(sink__V928->context, varFV__V935);
    UNLINK_NamedPropertyLink(sink__V928->context, namedP__V932); UNLINK_VariablePropertyLink(sink__V928->context, varP__V933);
    
    return 1;
  } while (0);
  do {
    /* Contraction rule DEFS-Forms-Constructors-2$Forms-Constructors$1$SORT-SET. */
    ASSERT(sink__V928->context, !strcmp(SYMBOL(term__V929),  "Forms-Constructors$1" ));
    Term sub__V936 = SUB(term__V929, 0); permitUnusedTerm(sub__V936); int sub__V936_count = term__V929_count*LINK_COUNT(sub__V936); permitUnusedInt(sub__V936_count);
    FORCE(sink__V928->context, sub__V936); SUB(term__V929, 0) = sub__V936;
    if (strcmp(SYMBOL(sub__V936),  "SORT-SET" )) break;
    Term sub__V937 = LINK(sink__V928->context, SUB(sub__V936, 0)); int sub__V937_count = sub__V936_count*LINK_COUNT(sub__V937); permitUnusedInt(sub__V937_count);
    CRSX_CHECK_SORT(sink__V928->context, sub__V937, &sort_M_Reified_xSort); /* sub__V937 = &#0-0 */
    Term sub__V938 = LINK(sink__V928->context, SUB(sub__V936, 1)); int sub__V938_count = sub__V936_count*LINK_COUNT(sub__V938); permitUnusedInt(sub__V938_count);
    CRSX_CHECK_SORT(sink__V928->context, sub__V938, &sort_M_Reified_xSort); /* sub__V938 = &#0-1 */
    Term sub__V939 = LINK(sink__V928->context, SUB(sub__V936, 2)); int sub__V939_count = sub__V936_count*LINK_COUNT(sub__V939); permitUnusedInt(sub__V939_count);
    CRSX_CHECK_SORT(sink__V928->context, sub__V939, &sort_M_Reified_xForm); /* sub__V939 = &#0-2 */
    Term sub__V940 = LINK(sink__V928->context, SUB(term__V929, 1)); int sub__V940_count = term__V929_count*LINK_COUNT(sub__V940); permitUnusedInt(sub__V940_count);
    /* sub__V940 = &#3 */
    
    NamedPropertyLink namedP__V941 = LINK_NamedPropertyLink(sink__V928->context, NAMED_PROPERTIES(term__V929));
    VariablePropertyLink varP__V942 = LINK_VariablePropertyLink(sink__V928->context, VARIABLE_PROPERTIES(term__V929));
    Hashset namedFV__V943 = LINK_VARIABLESET(sink__V928->context, asConstruction(term__V929)->properties->namedFreeVars);
    Hashset varFV__V944 = LINK_VARIABLESET(sink__V928->context, asConstruction(term__V929)->properties->variableFreeVars);
    UNLINK(sink__V928->context, term__V929);
    ADD_PROPERTIES(sink__V928, LINK_VARIABLESET(sink__V928->context, namedFV__V943), LINK_VARIABLESET(sink__V928->context, varFV__V944), LINK_NamedPropertyLink(sink__V928->context, namedP__V941), LINK_VariablePropertyLink(sink__V928->context, varP__V942));
    { START(sink__V928, _M_Forms_Constructors_s4);
      COPY(sink__V928, sub__V937);COPY(sink__V928, sub__V938);COPY(sink__V928, sub__V939);COPY(sink__V928, sub__V940);END(sink__V928, _M_Forms_Constructors_s4); }
    UNLINK_VARIABLESET(sink__V928->context, namedFV__V943); UNLINK_VARIABLESET(sink__V928->context, varFV__V944);
    UNLINK_NamedPropertyLink(sink__V928->context, namedP__V941); UNLINK_VariablePropertyLink(sink__V928->context, varP__V942);
    
    return 1;
  } while (0);
  do {
    /* Contraction rule DEFS-Forms-Constructors-3$Forms-Constructors$1$FORM. */
    ASSERT(sink__V928->context, !strcmp(SYMBOL(term__V929),  "Forms-Constructors$1" ));
    Term sub__V945 = SUB(term__V929, 0); permitUnusedTerm(sub__V945); int sub__V945_count = term__V929_count*LINK_COUNT(sub__V945); permitUnusedInt(sub__V945_count);
    FORCE(sink__V928->context, sub__V945); SUB(term__V929, 0) = sub__V945;
    if (strcmp(SYMBOL(sub__V945),  "FORM" )) break;
    Term sub__V946 = LINK(sink__V928->context, SUB(sub__V945, 0)); int sub__V946_count = sub__V945_count*LINK_COUNT(sub__V946); permitUnusedInt(sub__V946_count);
    /* sub__V946 = &#0-0 */
    Term sub__V947 = LINK(sink__V928->context, SUB(sub__V945, 1)); int sub__V947_count = sub__V945_count*LINK_COUNT(sub__V947); permitUnusedInt(sub__V947_count);
    /* sub__V947 = &#0-1 */
    Term sub__V948 = LINK(sink__V928->context, SUB(term__V929, 1)); int sub__V948_count = term__V929_count*LINK_COUNT(sub__V948); permitUnusedInt(sub__V948_count);
    /* sub__V948 = &#2 */
    
    NamedPropertyLink namedP__V949 = LINK_NamedPropertyLink(sink__V928->context, NAMED_PROPERTIES(term__V929));
    VariablePropertyLink varP__V950 = LINK_VariablePropertyLink(sink__V928->context, VARIABLE_PROPERTIES(term__V929));
    Hashset namedFV__V951 = LINK_VARIABLESET(sink__V928->context, asConstruction(term__V929)->properties->namedFreeVars);
    Hashset varFV__V952 = LINK_VARIABLESET(sink__V928->context, asConstruction(term__V929)->properties->variableFreeVars);
    UNLINK(sink__V928->context, term__V929);
    ADD_PROPERTIES(sink__V928, LINK_VARIABLESET(sink__V928->context, namedFV__V951), LINK_VARIABLESET(sink__V928->context, varFV__V952), LINK_NamedPropertyLink(sink__V928->context, namedP__V949), LINK_VariablePropertyLink(sink__V928->context, varP__V950));
    { START(sink__V928, _M_Forms_Constructors_s2);
      COPY(sink__V928, sub__V946);COPY(sink__V928, sub__V947);COPY(sink__V928, sub__V948);END(sink__V928, _M_Forms_Constructors_s2); }
    UNLINK_VARIABLESET(sink__V928->context, namedFV__V951); UNLINK_VARIABLESET(sink__V928->context, varFV__V952);
    UNLINK_NamedPropertyLink(sink__V928->context, namedP__V949); UNLINK_VariablePropertyLink(sink__V928->context, varP__V950);
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Forms-Constructors$4. */
int conBindOffs_M_Forms_Constructors_s4[] = {0 , 0 , 0 , 0 , 0};
char *nameFun_M_Forms_Constructors_s4(Term term) { return  "Forms-Constructors$4" ; }
struct _ConstructionDescriptor descriptor_M_Forms_Constructors_s4 = {NULL, 0, 4, sizeof(STRUCT_Con_M_Forms_Constructors_s4), conBindOffs_M_Forms_Constructors_s4, &nameFun_M_Forms_Constructors_s4, &step_M_Forms_Constructors_s4};

int step_M_Forms_Constructors_s4(Sink sink__V953, Term term__V954)
{
  int term__V954_count = LINK_COUNT(term__V954); permitUnusedInt(term__V954_count);
  do {
    /* Contraction rule DEFS-Forms-Constructors-2. */
    ASSERT(sink__V953->context, !strcmp(SYMBOL(term__V954),  "Forms-Constructors$4" ));
    Term sub__V955 = SUB(term__V954, 0); permitUnusedTerm(sub__V955); int sub__V955_count = term__V954_count*LINK_COUNT(sub__V955); permitUnusedInt(sub__V955_count);
    CRSX_CHECK_SORT(sink__V953->context, sub__V955, &sort_M_Reified_xSort); /* sub__V955 = &#111 */
    Term sub__V956 = SUB(term__V954, 1); permitUnusedTerm(sub__V956); int sub__V956_count = term__V954_count*LINK_COUNT(sub__V956); permitUnusedInt(sub__V956_count);
    CRSX_CHECK_SORT(sink__V953->context, sub__V956, &sort_M_Reified_xSort); /* sub__V956 = &#112 */
    Term sub__V957 = LINK(sink__V953->context, SUB(term__V954, 2)); int sub__V957_count = term__V954_count*LINK_COUNT(sub__V957); permitUnusedInt(sub__V957_count);
    CRSX_CHECK_SORT(sink__V953->context, sub__V957, &sort_M_Reified_xForm); /* sub__V957 = &#113 */
    Term sub__V958 = LINK(sink__V953->context, SUB(term__V954, 3)); int sub__V958_count = term__V954_count*LINK_COUNT(sub__V958); permitUnusedInt(sub__V958_count);
    /* sub__V958 = &#12 */
    UNLINK(sink__V953->context, term__V954);
    { START(sink__V953, _M_Forms_Constructors);
      { START(sink__V953, _M__sCons);
        COPY(sink__V953, sub__V957);COPY(sink__V953, sub__V958);END(sink__V953, _M__sCons); }
      END(sink__V953, _M_Forms_Constructors); }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Forms-Constructors$3. */
int conBindOffs_M_Forms_Constructors_s3[] = {0 , 0};
char *nameFun_M_Forms_Constructors_s3(Term term) { return  "Forms-Constructors$3" ; }
struct _ConstructionDescriptor descriptor_M_Forms_Constructors_s3 = {NULL, 0, 1, sizeof(STRUCT_Con_M_Forms_Constructors_s3), conBindOffs_M_Forms_Constructors_s3, &nameFun_M_Forms_Constructors_s3, &step_M_Forms_Constructors_s3};

int step_M_Forms_Constructors_s3(Sink sink__V959, Term term__V960)
{
  int term__V960_count = LINK_COUNT(term__V960); permitUnusedInt(term__V960_count);
  do {
    /* Contraction rule DEFS-Forms-Constructors-1. */
    ASSERT(sink__V959->context, !strcmp(SYMBOL(term__V960),  "Forms-Constructors$3" ));
    Term sub__V961 = LINK(sink__V959->context, SUB(term__V960, 0)); int sub__V961_count = term__V960_count*LINK_COUNT(sub__V961); permitUnusedInt(sub__V961_count);
    /* sub__V961 = &#12 */
    UNLINK(sink__V959->context, term__V960);
    { START(sink__V959, _M_Forms_Constructors);
      COPY(sink__V959, sub__V961);END(sink__V959, _M_Forms_Constructors); }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION SortNames. */
int conBindOffs_M_SortNames[] = {0 , 0};
char *nameFun_M_SortNames(Term term) { return  "SortNames" ; }
struct _ConstructionDescriptor descriptor_M_SortNames = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_SortNames), conBindOffs_M_SortNames, &nameFun_M_SortNames, &step_M_SortNames};

int step_M_SortNames(Sink sink__V962, Term term__V963)
{
  int term__V963_count = LINK_COUNT(term__V963); permitUnusedInt(term__V963_count);
  do {
    /* Contraction rule DEFS-SortNames-1. */
    ASSERT(sink__V962->context, !strcmp(SYMBOL(term__V963),  "SortNames" ));
    Term sub__V964 = LINK(sink__V962->context, SUB(term__V963, 0)); int sub__V964_count = term__V963_count*LINK_COUNT(sub__V964); permitUnusedInt(sub__V964_count);
    /* sub__V964 = &#1 */
    
    NamedPropertyLink namedP__V965 = LINK_NamedPropertyLink(sink__V962->context, NAMED_PROPERTIES(term__V963));
    VariablePropertyLink varP__V966 = LINK_VariablePropertyLink(sink__V962->context, VARIABLE_PROPERTIES(term__V963));
    Hashset namedFV__V967 = LINK_VARIABLESET(sink__V962->context, asConstruction(term__V963)->properties->namedFreeVars);
    Hashset varFV__V968 = LINK_VARIABLESET(sink__V962->context, asConstruction(term__V963)->properties->variableFreeVars);
    UNLINK(sink__V962->context, term__V963);
    { START(sink__V962, _M__sTextCons);
      { START(sink__V962, _M__sTextChars);
        LITERAL(sink__V962,  "sortNam" ); END(sink__V962, _M__sTextChars); }
      { START(sink__V962, _M__sTextCons);
        { START(sink__V962, _M__sTextEmbed);
          { START(sink__V962, _M_AsText);
            { START(sink__V962, _M_MANGLE);
              COPY(sink__V962, sub__V964);END(sink__V962, _M_MANGLE); }
            END(sink__V962, _M_AsText); }
          END(sink__V962, _M__sTextEmbed); }
        { START(sink__V962, _M__sTextNil);
          END(sink__V962, _M__sTextNil); }
        END(sink__V962, _M__sTextCons); }
      END(sink__V962, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V962->context, namedFV__V967); UNLINK_VARIABLESET(sink__V962->context, varFV__V968);
    UNLINK_NamedPropertyLink(sink__V962->context, namedP__V965); UNLINK_VariablePropertyLink(sink__V962->context, varP__V966);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION UnVariable. */
int conBindOffs_M_UnVariable[] = {0 , 0};
char *nameFun_M_UnVariable(Term term) { return  "UnVariable" ; }
struct _ConstructionDescriptor descriptor_M_UnVariable = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_UnVariable), conBindOffs_M_UnVariable, &nameFun_M_UnVariable, &step_M_UnVariable};

int step_M_UnVariable(Sink sink__V969, Term term__V970)
{
  int term__V970_count = LINK_COUNT(term__V970); permitUnusedInt(term__V970_count);
  Term sub__V971 = FORCE(sink__V969->context, SUB(term__V970, 0));
  EnumOf_M_STRING_xENTRY choice__V972 = (IS_VARIABLE_USE(sub__V971) ? VarOf_M_STRING_xENTRY : (EnumOf_M_STRING_xENTRY) TAG(sub__V971));
  switch (choice__V972)
  {
    case Data_M_VARIABLE: { /* Function DEFS-UnVariable-1$UnVariable$VARIABLE case VARIABLE */
      ASSERT(sink__V969->context, !strcmp(SYMBOL(term__V970),  "UnVariable" ));
      Term sub__V973 = SUB(term__V970, 0); permitUnusedTerm(sub__V973); int sub__V973_count = term__V970_count*LINK_COUNT(sub__V973); permitUnusedInt(sub__V973_count);
      CRSX_CHECK_SORT(sink__V969->context, sub__V973, &sort_M_STRING_xENTRY); ASSERT(sink__V969->context, !strcmp(SYMBOL(sub__V973),  "VARIABLE" ));
      Term sub__V974 = LINK(sink__V969->context, SUB(sub__V973, 0)); int sub__V974_count = sub__V973_count*LINK_COUNT(sub__V974); permitUnusedInt(sub__V974_count);
      CRSX_CHECK_SORT(sink__V969->context, sub__V974, &sort_M_Reified_xVariable); /* sub__V974 = &#0-0 */
      
      NamedPropertyLink namedP__V975 = LINK_NamedPropertyLink(sink__V969->context, NAMED_PROPERTIES(term__V970));
      VariablePropertyLink varP__V976 = LINK_VariablePropertyLink(sink__V969->context, VARIABLE_PROPERTIES(term__V970));
      Hashset namedFV__V977 = LINK_VARIABLESET(sink__V969->context, asConstruction(term__V970)->properties->namedFreeVars);
      Hashset varFV__V978 = LINK_VARIABLESET(sink__V969->context, asConstruction(term__V970)->properties->variableFreeVars);
      UNLINK(sink__V969->context, term__V970);
      ADD_PROPERTIES(sink__V969, LINK_VARIABLESET(sink__V969->context, namedFV__V977), LINK_VARIABLESET(sink__V969->context, varFV__V978), LINK_NamedPropertyLink(sink__V969->context, namedP__V975), LINK_VariablePropertyLink(sink__V969->context, varP__V976));
      { START(sink__V969, _M_UnVariable_s1);
        COPY(sink__V969, sub__V974);END(sink__V969, _M_UnVariable_s1); }
      UNLINK_VARIABLESET(sink__V969->context, namedFV__V977); UNLINK_VARIABLESET(sink__V969->context, varFV__V978);
      UNLINK_NamedPropertyLink(sink__V969->context, namedP__V975); UNLINK_VariablePropertyLink(sink__V969->context, varP__V976);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION DelayMapText$1. */
int conBindOffs_M_DelayMapText_s1[] = {0 , 0 , 2};
char *nameFun_M_DelayMapText_s1(Term term) { return  "DelayMapText$1" ; }
struct _ConstructionDescriptor descriptor_M_DelayMapText_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_DelayMapText_s1), conBindOffs_M_DelayMapText_s1, &nameFun_M_DelayMapText_s1, &step_M_DelayMapText_s1};

int step_M_DelayMapText_s1(Sink sink__V979, Term term__V980)
{
  int term__V980_count = LINK_COUNT(term__V980); permitUnusedInt(term__V980_count);
  Term sub__V981 = FORCE(sink__V979->context, SUB(term__V980, 0));
  EnumOf_M__sList choice__V982 = (IS_VARIABLE_USE(sub__V981) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V981));
  switch (choice__V982)
  {
    case Data_M__sCons: { /* Function DEFS-DelayMapText-1$DelayMapText$1$$Cons case $Cons */
      ASSERT(sink__V979->context, !strcmp(SYMBOL(term__V980),  "DelayMapText$1" ));
      Term sub__V983 = SUB(term__V980, 0); permitUnusedTerm(sub__V983); int sub__V983_count = term__V980_count*LINK_COUNT(sub__V983); permitUnusedInt(sub__V983_count);
      ASSERT(sink__V979->context, !strcmp(SYMBOL(sub__V983),  "$Cons" ));
      Term sub__V984 = LINK(sink__V979->context, SUB(sub__V983, 0)); int sub__V984_count = sub__V983_count*LINK_COUNT(sub__V984); permitUnusedInt(sub__V984_count);
      /* sub__V984 = &#0-0 */
      Term sub__V985 = LINK(sink__V979->context, SUB(sub__V983, 1)); int sub__V985_count = sub__V983_count*LINK_COUNT(sub__V985); permitUnusedInt(sub__V985_count);
      /* sub__V985 = &#0-1 */
      Variable x__V986 = BINDER(term__V980,1,0); if (term__V980_count <= 1) UNBIND(x__V986);
      Variable x__V987 = BINDER(term__V980,1,1); if (term__V980_count <= 1) UNBIND(x__V987);
      Term sub__V988 = LINK(sink__V979->context, SUB(term__V980, 1)); int sub__V988_count = term__V980_count*LINK_COUNT(sub__V988); permitUnusedInt(sub__V988_count);
      CRSX_CHECK_SORT(sink__V979->context, sub__V988, &sort_M_Reified_xVariable); /* sub__V988 = &#2 */
      
      NamedPropertyLink namedP__V989 = LINK_NamedPropertyLink(sink__V979->context, NAMED_PROPERTIES(term__V980));
      VariablePropertyLink varP__V990 = LINK_VariablePropertyLink(sink__V979->context, VARIABLE_PROPERTIES(term__V980));
      Hashset namedFV__V991 = LINK_VARIABLESET(sink__V979->context, asConstruction(term__V980)->properties->namedFreeVars);
      Hashset varFV__V992 = LINK_VARIABLESET(sink__V979->context, asConstruction(term__V980)->properties->variableFreeVars);
      UNLINK(sink__V979->context, term__V980);
      ADD_PROPERTIES(sink__V979, LINK_VARIABLESET(sink__V979->context, namedFV__V991), LINK_VARIABLESET(sink__V979->context, varFV__V992), LINK_NamedPropertyLink(sink__V979->context, namedP__V989), LINK_VariablePropertyLink(sink__V979->context, varP__V990));
      { START(sink__V979, _M_DelayMapText_s2);
        COPY(sink__V979, sub__V984);COPY(sink__V979, sub__V985);{ if (!IS_BOUND(x__V986)) { REBIND(x__V986);
            REBIND(x__V987);
            Variable binds__V993[2] = {x__V986,x__V987}; BINDS(sink__V979, 2, binds__V993);
            COPY(sink__V979, sub__V988); /* REUSED SUBSTITUTION */  }
          else { Variable b__V994 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V979->context,"b__V994");
            Variable b__V995 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V979->context,"b__V995");
            Variable binds__V996[2] = {b__V994,b__V995}; BINDS(sink__V979, 2, binds__V996);
            {
              Term arg__V997;
              { Sink buf__V998 = ALLOCA_BUFFER(sink__V979->context);
                USE(buf__V998, b__V994); arg__V997 = BUFFER_TERM(buf__V998); FREE_BUFFER(buf__V998); }
              Term arg__V999;
              { Sink buf__V1000 = ALLOCA_BUFFER(sink__V979->context);
                USE(buf__V1000, b__V995); arg__V999 = BUFFER_TERM(buf__V1000); FREE_BUFFER(buf__V1000); }
              Variable vars__V1001[2] = {x__V986,x__V987};
              Term args__V1002[2] = {arg__V997,arg__V999};
              struct _SubstitutionFrame substitution__V1003 = {NULL, 0, 2, vars__V1001, args__V1002, NULL};
              SUBSTITUTE(sink__V979, sub__V988, &substitution__V1003); }
                }
           }
        END(sink__V979, _M_DelayMapText_s2); }
      UNLINK_VARIABLESET(sink__V979->context, namedFV__V991); UNLINK_VARIABLESET(sink__V979->context, varFV__V992);
      UNLINK_NamedPropertyLink(sink__V979->context, namedP__V989); UNLINK_VariablePropertyLink(sink__V979->context, varP__V990);
      
      return 1;
    break; } case Data_M__sNil: { /* Function DEFS-DelayMapText-2$DelayMapText$1$$Nil case $Nil */
      ASSERT(sink__V979->context, !strcmp(SYMBOL(term__V980),  "DelayMapText$1" ));
      Term sub__V1004 = SUB(term__V980, 0); permitUnusedTerm(sub__V1004); int sub__V1004_count = term__V980_count*LINK_COUNT(sub__V1004); permitUnusedInt(sub__V1004_count);
      ASSERT(sink__V979->context, !strcmp(SYMBOL(sub__V1004),  "$Nil" ));
      Variable x__V1005 = BINDER(term__V980,1,0); if (term__V980_count <= 1) UNBIND(x__V1005);
      Variable x__V1006 = BINDER(term__V980,1,1); if (term__V980_count <= 1) UNBIND(x__V1006);
      Term sub__V1007 = LINK(sink__V979->context, SUB(term__V980, 1)); int sub__V1007_count = term__V980_count*LINK_COUNT(sub__V1007); permitUnusedInt(sub__V1007_count);
      CRSX_CHECK_SORT(sink__V979->context, sub__V1007, &sort_M_Reified_xVariable); /* sub__V1007 = &#0 */
      
      NamedPropertyLink namedP__V1008 = LINK_NamedPropertyLink(sink__V979->context, NAMED_PROPERTIES(term__V980));
      VariablePropertyLink varP__V1009 = LINK_VariablePropertyLink(sink__V979->context, VARIABLE_PROPERTIES(term__V980));
      Hashset namedFV__V1010 = LINK_VARIABLESET(sink__V979->context, asConstruction(term__V980)->properties->namedFreeVars);
      Hashset varFV__V1011 = LINK_VARIABLESET(sink__V979->context, asConstruction(term__V980)->properties->variableFreeVars);
      UNLINK(sink__V979->context, term__V980);
      ADD_PROPERTIES(sink__V979, LINK_VARIABLESET(sink__V979->context, namedFV__V1010), LINK_VARIABLESET(sink__V979->context, varFV__V1011), LINK_NamedPropertyLink(sink__V979->context, namedP__V1008), LINK_VariablePropertyLink(sink__V979->context, varP__V1009));
      { START(sink__V979, _M_DelayMapText_s3);
        { if (!IS_BOUND(x__V1005)) { REBIND(x__V1005);
            REBIND(x__V1006);
            Variable binds__V1012[2] = {x__V1005,x__V1006}; BINDS(sink__V979, 2, binds__V1012);
            COPY(sink__V979, sub__V1007); /* REUSED SUBSTITUTION */  }
          else { Variable b__V1013 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V979->context,"b__V1013");
            Variable b__V1014 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V979->context,"b__V1014");
            Variable binds__V1015[2] = {b__V1013,b__V1014}; BINDS(sink__V979, 2, binds__V1015);
            {
              Term arg__V1016;
              { Sink buf__V1017 = ALLOCA_BUFFER(sink__V979->context);
                USE(buf__V1017, b__V1013); arg__V1016 = BUFFER_TERM(buf__V1017); FREE_BUFFER(buf__V1017); }
              Term arg__V1018;
              { Sink buf__V1019 = ALLOCA_BUFFER(sink__V979->context);
                USE(buf__V1019, b__V1014); arg__V1018 = BUFFER_TERM(buf__V1019); FREE_BUFFER(buf__V1019); }
              Variable vars__V1020[2] = {x__V1005,x__V1006};
              Term args__V1021[2] = {arg__V1016,arg__V1018};
              struct _SubstitutionFrame substitution__V1022 = {NULL, 0, 2, vars__V1020, args__V1021, NULL};
              SUBSTITUTE(sink__V979, sub__V1007, &substitution__V1022); }
                }
           }
        END(sink__V979, _M_DelayMapText_s3); }
      UNLINK_VARIABLESET(sink__V979->context, namedFV__V1010); UNLINK_VARIABLESET(sink__V979->context, varFV__V1011);
      UNLINK_NamedPropertyLink(sink__V979->context, namedP__V1008); UNLINK_VariablePropertyLink(sink__V979->context, varP__V1009);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION DelayMapText$3. */
int conBindOffs_M_DelayMapText_s3[] = {0 , 2};
char *nameFun_M_DelayMapText_s3(Term term) { return  "DelayMapText$3" ; }
struct _ConstructionDescriptor descriptor_M_DelayMapText_s3 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_DelayMapText_s3), conBindOffs_M_DelayMapText_s3, &nameFun_M_DelayMapText_s3, &step_M_DelayMapText_s3};

int step_M_DelayMapText_s3(Sink sink__V1023, Term term__V1024)
{
  int term__V1024_count = LINK_COUNT(term__V1024); permitUnusedInt(term__V1024_count);
  do {
    /* Contraction rule DEFS-DelayMapText-2. */
    ASSERT(sink__V1023->context, !strcmp(SYMBOL(term__V1024),  "DelayMapText$3" ));
    Variable x__V1025 = BINDER(term__V1024,0,0); if (term__V1024_count <= 1) UNBIND(x__V1025);
    Variable x__V1026 = BINDER(term__V1024,0,1); if (term__V1024_count <= 1) UNBIND(x__V1026);
    Term sub__V1027 = SUB(term__V1024, 0); permitUnusedTerm(sub__V1027); int sub__V1027_count = term__V1024_count*LINK_COUNT(sub__V1027); permitUnusedInt(sub__V1027_count);
    CRSX_CHECK_SORT(sink__V1023->context, sub__V1027, &sort_M_Reified_xVariable); /* sub__V1027 = &#1 */
    
    NamedPropertyLink namedP__V1028 = LINK_NamedPropertyLink(sink__V1023->context, NAMED_PROPERTIES(term__V1024));
    VariablePropertyLink varP__V1029 = LINK_VariablePropertyLink(sink__V1023->context, VARIABLE_PROPERTIES(term__V1024));
    Hashset namedFV__V1030 = LINK_VARIABLESET(sink__V1023->context, asConstruction(term__V1024)->properties->namedFreeVars);
    Hashset varFV__V1031 = LINK_VARIABLESET(sink__V1023->context, asConstruction(term__V1024)->properties->variableFreeVars);
    UNLINK(sink__V1023->context, term__V1024);
    { START(sink__V1023, _M__sTextNil);
      END(sink__V1023, _M__sTextNil); }
    UNLINK_VARIABLESET(sink__V1023->context, namedFV__V1030); UNLINK_VARIABLESET(sink__V1023->context, varFV__V1031);
    UNLINK_NamedPropertyLink(sink__V1023->context, namedP__V1028); UNLINK_VariablePropertyLink(sink__V1023->context, varP__V1029);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DelayMapText$2. */
int conBindOffs_M_DelayMapText_s2[] = {0 , 0 , 0 , 2};
char *nameFun_M_DelayMapText_s2(Term term) { return  "DelayMapText$2" ; }
struct _ConstructionDescriptor descriptor_M_DelayMapText_s2 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_DelayMapText_s2), conBindOffs_M_DelayMapText_s2, &nameFun_M_DelayMapText_s2, &step_M_DelayMapText_s2};

int step_M_DelayMapText_s2(Sink sink__V1032, Term term__V1033)
{
  int term__V1033_count = LINK_COUNT(term__V1033); permitUnusedInt(term__V1033_count);
  do {
    /* Contraction rule DEFS-DelayMapText-1. */
    ASSERT(sink__V1032->context, !strcmp(SYMBOL(term__V1033),  "DelayMapText$2" ));
    Term sub__V1034 = LINK(sink__V1032->context, SUB(term__V1033, 0)); int sub__V1034_count = term__V1033_count*LINK_COUNT(sub__V1034); permitUnusedInt(sub__V1034_count);
    /* sub__V1034 = &#21 */
    Term sub__V1035 = LINK(sink__V1032->context, SUB(term__V1033, 1)); int sub__V1035_count = term__V1033_count*LINK_COUNT(sub__V1035); permitUnusedInt(sub__V1035_count);
    /* sub__V1035 = &#22 */
    Variable x__V1036 = BINDER(term__V1033,2,0); if (term__V1033_count <= 1) UNBIND(x__V1036);
    Variable x__V1037 = BINDER(term__V1033,2,1); if (term__V1033_count <= 1) UNBIND(x__V1037);
    Term sub__V1038 = LINK(sink__V1032->context, SUB(term__V1033, 2)); int sub__V1038_count = term__V1033_count*LINK_COUNT(sub__V1038); permitUnusedInt(sub__V1038_count);
    CRSX_CHECK_SORT(sink__V1032->context, sub__V1038, &sort_M_Reified_xVariable); UNLINK_SUB(sink__V1032->context, term__V1033,  2); NORMALIZE(sink__V1032->context, sub__V1038); SUB(term__V1033,  2) = LINK(sink__V1032->context, sub__V1038);
    /* sub__V1038 = &#1 */
    
    NamedPropertyLink namedP__V1039 = LINK_NamedPropertyLink(sink__V1032->context, NAMED_PROPERTIES(term__V1033));
    VariablePropertyLink varP__V1040 = LINK_VariablePropertyLink(sink__V1032->context, VARIABLE_PROPERTIES(term__V1033));
    Hashset namedFV__V1041 = LINK_VARIABLESET(sink__V1032->context, asConstruction(term__V1033)->properties->namedFreeVars);
    Hashset varFV__V1042 = LINK_VARIABLESET(sink__V1032->context, asConstruction(term__V1033)->properties->variableFreeVars);
    UNLINK(sink__V1032->context, term__V1033);
    { START(sink__V1032, _M__sTextCons);
      { START(sink__V1032, _M__sTextEmbed);
        { START(sink__V1032, _M_AsText);
          {
            Term arg__V1043;
            { Sink buf__V1044 = ALLOCA_BUFFER(sink__V1032->context);
              { START(buf__V1044, _M_OK); END(buf__V1044, _M_OK); } arg__V1043 = BUFFER_TERM(buf__V1044); FREE_BUFFER(buf__V1044); }
            Term arg__V1045;
            { Sink buf__V1046 = ALLOCA_BUFFER(sink__V1032->context);
              COPY(buf__V1046, sub__V1034);arg__V1045 = BUFFER_TERM(buf__V1046); FREE_BUFFER(buf__V1046); }
            Variable vars__V1047[2] = {x__V1036,x__V1037};
            Term args__V1048[2] = {arg__V1043,arg__V1045};
            struct _SubstitutionFrame substitution__V1049 = {NULL, 0, 2, vars__V1047, args__V1048, NULL};
            SUBSTITUTE(sink__V1032, LINK(sink__V1032->context,sub__V1038), &substitution__V1049); }
          END(sink__V1032, _M_AsText); }
        END(sink__V1032, _M__sTextEmbed); }
      { START(sink__V1032, _M__sTextCons);
        { START(sink__V1032, _M__sTextEmbed);
          { START(sink__V1032, _M_AsText);
            { START(sink__V1032, _M_DelayMapText_s1);
              COPY(sink__V1032, sub__V1035);{ Variable x__V1050 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V1032->context,"x__V1050");
                Variable x__V1051 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V1032->context,"x__V1051");
                Variable binds__V1052[2] = {x__V1050,x__V1051}; BINDS(sink__V1032, 2, binds__V1052);
                {
                  Term arg__V1053;
                  { Sink buf__V1054 = ALLOCA_BUFFER(sink__V1032->context);
                    USE(buf__V1054, x__V1050); arg__V1053 = BUFFER_TERM(buf__V1054); FREE_BUFFER(buf__V1054); }
                  Term arg__V1055;
                  { Sink buf__V1056 = ALLOCA_BUFFER(sink__V1032->context);
                    USE(buf__V1056, x__V1051); arg__V1055 = BUFFER_TERM(buf__V1056); FREE_BUFFER(buf__V1056); }
                  Variable vars__V1057[2] = {x__V1036,x__V1037};
                  Term args__V1058[2] = {arg__V1053,arg__V1055};
                  struct _SubstitutionFrame substitution__V1059 = {NULL, 0, 2, vars__V1057, args__V1058, NULL};
                  SUBSTITUTE(sink__V1032, sub__V1038, &substitution__V1059); }
                 }
              END(sink__V1032, _M_DelayMapText_s1); }
            END(sink__V1032, _M_AsText); }
          END(sink__V1032, _M__sTextEmbed); }
        { START(sink__V1032, _M__sTextNil);
          END(sink__V1032, _M__sTextNil); }
        END(sink__V1032, _M__sTextCons); }
      END(sink__V1032, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V1032->context, namedFV__V1041); UNLINK_VARIABLESET(sink__V1032->context, varFV__V1042);
    UNLINK_NamedPropertyLink(sink__V1032->context, namedP__V1039); UNLINK_VariablePropertyLink(sink__V1032->context, varP__V1040);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION FormArguments-binder-offsets. */
int conBindOffs_M_FormArguments__binder__offsets[] = {0 , 0 , 0};
char *nameFun_M_FormArguments__binder__offsets(Term term) { return  "FormArguments-binder-offsets" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__offsets = {NULL, 0, 2, sizeof(STRUCT_Con_M_FormArguments__binder__offsets), conBindOffs_M_FormArguments__binder__offsets, &nameFun_M_FormArguments__binder__offsets, &step_M_FormArguments__binder__offsets};

int step_M_FormArguments__binder__offsets(Sink sink__V1060, Term term__V1061)
{
  int term__V1061_count = LINK_COUNT(term__V1061); permitUnusedInt(term__V1061_count);
  Term sub__V1062 = FORCE(sink__V1060->context, SUB(term__V1061, 0));
  EnumOf_M__sList choice__V1063 = (IS_VARIABLE_USE(sub__V1062) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V1062));
  switch (choice__V1063)
  {
    case Data_M__sCons: { /* Function DEFS-FormArguments-binder-offsets-1$FormArguments-binder-offsets$$Cons case $Cons */
      ASSERT(sink__V1060->context, !strcmp(SYMBOL(term__V1061),  "FormArguments-binder-offsets" ));
      Term sub__V1064 = SUB(term__V1061, 0); permitUnusedTerm(sub__V1064); int sub__V1064_count = term__V1061_count*LINK_COUNT(sub__V1064); permitUnusedInt(sub__V1064_count);
      ASSERT(sink__V1060->context, !strcmp(SYMBOL(sub__V1064),  "$Cons" ));
      Term sub__V1065 = LINK(sink__V1060->context, SUB(sub__V1064, 0)); int sub__V1065_count = sub__V1064_count*LINK_COUNT(sub__V1065); permitUnusedInt(sub__V1065_count);
      /* sub__V1065 = &#0-0 */
      Term sub__V1066 = LINK(sink__V1060->context, SUB(sub__V1064, 1)); int sub__V1066_count = sub__V1064_count*LINK_COUNT(sub__V1066); permitUnusedInt(sub__V1066_count);
      /* sub__V1066 = &#0-1 */
      Term sub__V1067 = LINK(sink__V1060->context, SUB(term__V1061, 1)); int sub__V1067_count = term__V1061_count*LINK_COUNT(sub__V1067); permitUnusedInt(sub__V1067_count);
      /* sub__V1067 = &#2 */
      
      NamedPropertyLink namedP__V1068 = LINK_NamedPropertyLink(sink__V1060->context, NAMED_PROPERTIES(term__V1061));
      VariablePropertyLink varP__V1069 = LINK_VariablePropertyLink(sink__V1060->context, VARIABLE_PROPERTIES(term__V1061));
      Hashset namedFV__V1070 = LINK_VARIABLESET(sink__V1060->context, asConstruction(term__V1061)->properties->namedFreeVars);
      Hashset varFV__V1071 = LINK_VARIABLESET(sink__V1060->context, asConstruction(term__V1061)->properties->variableFreeVars);
      UNLINK(sink__V1060->context, term__V1061);
      ADD_PROPERTIES(sink__V1060, LINK_VARIABLESET(sink__V1060->context, namedFV__V1070), LINK_VARIABLESET(sink__V1060->context, varFV__V1071), LINK_NamedPropertyLink(sink__V1060->context, namedP__V1068), LINK_VariablePropertyLink(sink__V1060->context, varP__V1069));
      { START(sink__V1060, _M_FormArguments__binder__offsets_s1);
        COPY(sink__V1060, sub__V1065);COPY(sink__V1060, sub__V1066);COPY(sink__V1060, sub__V1067);END(sink__V1060, _M_FormArguments__binder__offsets_s1); }
      UNLINK_VARIABLESET(sink__V1060->context, namedFV__V1070); UNLINK_VARIABLESET(sink__V1060->context, varFV__V1071);
      UNLINK_NamedPropertyLink(sink__V1060->context, namedP__V1068); UNLINK_VariablePropertyLink(sink__V1060->context, varP__V1069);
      
      return 1;
    break; } case Data_M__sNil: { /* Function DEFS-FormArguments-binder-offsets-3$FormArguments-binder-offsets$$Nil case $Nil */
      ASSERT(sink__V1060->context, !strcmp(SYMBOL(term__V1061),  "FormArguments-binder-offsets" ));
      Term sub__V1072 = SUB(term__V1061, 0); permitUnusedTerm(sub__V1072); int sub__V1072_count = term__V1061_count*LINK_COUNT(sub__V1072); permitUnusedInt(sub__V1072_count);
      ASSERT(sink__V1060->context, !strcmp(SYMBOL(sub__V1072),  "$Nil" ));
      Term sub__V1073 = LINK(sink__V1060->context, SUB(term__V1061, 1)); int sub__V1073_count = term__V1061_count*LINK_COUNT(sub__V1073); permitUnusedInt(sub__V1073_count);
      /* sub__V1073 = &#0 */
      
      NamedPropertyLink namedP__V1074 = LINK_NamedPropertyLink(sink__V1060->context, NAMED_PROPERTIES(term__V1061));
      VariablePropertyLink varP__V1075 = LINK_VariablePropertyLink(sink__V1060->context, VARIABLE_PROPERTIES(term__V1061));
      Hashset namedFV__V1076 = LINK_VARIABLESET(sink__V1060->context, asConstruction(term__V1061)->properties->namedFreeVars);
      Hashset varFV__V1077 = LINK_VARIABLESET(sink__V1060->context, asConstruction(term__V1061)->properties->variableFreeVars);
      UNLINK(sink__V1060->context, term__V1061);
      ADD_PROPERTIES(sink__V1060, LINK_VARIABLESET(sink__V1060->context, namedFV__V1076), LINK_VARIABLESET(sink__V1060->context, varFV__V1077), LINK_NamedPropertyLink(sink__V1060->context, namedP__V1074), LINK_VariablePropertyLink(sink__V1060->context, varP__V1075));
      { START(sink__V1060, _M_FormArguments__binder__offsets_s4);
        COPY(sink__V1060, sub__V1073);END(sink__V1060, _M_FormArguments__binder__offsets_s4); }
      UNLINK_VARIABLESET(sink__V1060->context, namedFV__V1076); UNLINK_VARIABLESET(sink__V1060->context, varFV__V1077);
      UNLINK_NamedPropertyLink(sink__V1060->context, namedP__V1074); UNLINK_VariablePropertyLink(sink__V1060->context, varP__V1075);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION MapIndexText$2. */
int conBindOffs_M_MapIndexText_s2[] = {0 , 0 , 0 , 2 , 2};
char *nameFun_M_MapIndexText_s2(Term term) { return  "MapIndexText$2" ; }
struct _ConstructionDescriptor descriptor_M_MapIndexText_s2 = {&sort_M_Reified_xVariable, 0, 4, sizeof(STRUCT_Con_M_MapIndexText_s2), conBindOffs_M_MapIndexText_s2, &nameFun_M_MapIndexText_s2, &step_M_MapIndexText_s2};

int step_M_MapIndexText_s2(Sink sink__V1078, Term term__V1079)
{
  int term__V1079_count = LINK_COUNT(term__V1079); permitUnusedInt(term__V1079_count);
  do {
    /* Contraction rule DEFS-MapIndexText-1. */
    ASSERT(sink__V1078->context, !strcmp(SYMBOL(term__V1079),  "MapIndexText$2" ));
    Term sub__V1080 = LINK(sink__V1078->context, SUB(term__V1079, 0)); int sub__V1080_count = term__V1079_count*LINK_COUNT(sub__V1080); permitUnusedInt(sub__V1080_count);
    /* sub__V1080 = &#21 */
    Term sub__V1081 = LINK(sink__V1078->context, SUB(term__V1079, 1)); int sub__V1081_count = term__V1079_count*LINK_COUNT(sub__V1081); permitUnusedInt(sub__V1081_count);
    /* sub__V1081 = &#22 */
    Variable x__V1082 = BINDER(term__V1079,2,0); if (term__V1079_count <= 1) UNBIND(x__V1082);
    Variable x__V1083 = BINDER(term__V1079,2,1); if (term__V1079_count <= 1) UNBIND(x__V1083);
    Term sub__V1084 = LINK(sink__V1078->context, SUB(term__V1079, 2)); int sub__V1084_count = term__V1079_count*LINK_COUNT(sub__V1084); permitUnusedInt(sub__V1084_count);
    CRSX_CHECK_SORT(sink__V1078->context, sub__V1084, &sort_M_Reified_xVariable); UNLINK_SUB(sink__V1078->context, term__V1079,  2); NORMALIZE(sink__V1078->context, sub__V1084); SUB(term__V1079,  2) = LINK(sink__V1078->context, sub__V1084);
    /* sub__V1084 = &#1 */
    Term sub__V1085 = LINK(sink__V1078->context, SUB(term__V1079, 3)); int sub__V1085_count = term__V1079_count*LINK_COUNT(sub__V1085); permitUnusedInt(sub__V1085_count);
    UNLINK_SUB(sink__V1078->context, term__V1079,  3); NORMALIZE(sink__V1078->context, sub__V1085); SUB(term__V1079,  3) = LINK(sink__V1078->context, sub__V1085);
    /* sub__V1085 = &#3 */
    
    NamedPropertyLink namedP__V1086 = LINK_NamedPropertyLink(sink__V1078->context, NAMED_PROPERTIES(term__V1079));
    VariablePropertyLink varP__V1087 = LINK_VariablePropertyLink(sink__V1078->context, VARIABLE_PROPERTIES(term__V1079));
    Hashset namedFV__V1088 = LINK_VARIABLESET(sink__V1078->context, asConstruction(term__V1079)->properties->namedFreeVars);
    Hashset varFV__V1089 = LINK_VARIABLESET(sink__V1078->context, asConstruction(term__V1079)->properties->variableFreeVars);
    UNLINK(sink__V1078->context, term__V1079);
    { START(sink__V1078, _M__sTextCons);
      { START(sink__V1078, _M__sTextEmbed);
        { START(sink__V1078, _M_AsText);
          {
            Term arg__V1090;
            { Sink buf__V1091 = ALLOCA_BUFFER(sink__V1078->context);
              COPY(buf__V1091, sub__V1080);arg__V1090 = BUFFER_TERM(buf__V1091); FREE_BUFFER(buf__V1091); }
            Term arg__V1092;
            { Sink buf__V1093 = ALLOCA_BUFFER(sink__V1078->context);
              COPY(buf__V1093, LINK(buf__V1093->context, sub__V1085));arg__V1092 = BUFFER_TERM(buf__V1093); FREE_BUFFER(buf__V1093); }
            Variable vars__V1094[2] = {x__V1082,x__V1083};
            Term args__V1095[2] = {arg__V1090,arg__V1092};
            struct _SubstitutionFrame substitution__V1096 = {NULL, 0, 2, vars__V1094, args__V1095, NULL};
            SUBSTITUTE(sink__V1078, LINK(sink__V1078->context,sub__V1084), &substitution__V1096); }
          END(sink__V1078, _M_AsText); }
        END(sink__V1078, _M__sTextEmbed); }
      { START(sink__V1078, _M__sTextCons);
        { START(sink__V1078, _M__sTextEmbed);
          { START(sink__V1078, _M_AsText);
            { START(sink__V1078, _M_MapIndexText_s1);
              COPY(sink__V1078, sub__V1081);{ Variable x__V1097 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V1078->context,"x__V1097");
                Variable x__V1098 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V1078->context,"x__V1098");
                Variable binds__V1099[2] = {x__V1097,x__V1098}; BINDS(sink__V1078, 2, binds__V1099);
                {
                  Term arg__V1100;
                  { Sink buf__V1101 = ALLOCA_BUFFER(sink__V1078->context);
                    USE(buf__V1101, x__V1097); arg__V1100 = BUFFER_TERM(buf__V1101); FREE_BUFFER(buf__V1101); }
                  Term arg__V1102;
                  { Sink buf__V1103 = ALLOCA_BUFFER(sink__V1078->context);
                    USE(buf__V1103, x__V1098); arg__V1102 = BUFFER_TERM(buf__V1103); FREE_BUFFER(buf__V1103); }
                  Variable vars__V1104[2] = {x__V1082,x__V1083};
                  Term args__V1105[2] = {arg__V1100,arg__V1102};
                  struct _SubstitutionFrame substitution__V1106 = {NULL, 0, 2, vars__V1104, args__V1105, NULL};
                  SUBSTITUTE(sink__V1078, sub__V1084, &substitution__V1106); }
                 }
              { double num__V1107;
                num__V1107 = (double) 1; { double tmp__V1108;
                  tmp__V1108 = DOUBLE(sub__V1085); num__V1107 += tmp__V1108; }
                LITERALNF(sink__V1078, (size_t) 31, "%G", num__V1107); }
              END(sink__V1078, _M_MapIndexText_s1); }
            END(sink__V1078, _M_AsText); }
          END(sink__V1078, _M__sTextEmbed); }
        { START(sink__V1078, _M__sTextNil);
          END(sink__V1078, _M__sTextNil); }
        END(sink__V1078, _M__sTextCons); }
      END(sink__V1078, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V1078->context, namedFV__V1088); UNLINK_VARIABLESET(sink__V1078->context, varFV__V1089);
    UNLINK_NamedPropertyLink(sink__V1078->context, namedP__V1086); UNLINK_VariablePropertyLink(sink__V1078->context, varP__V1087);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION MapIndexText$1. */
int conBindOffs_M_MapIndexText_s1[] = {0 , 0 , 2 , 2};
char *nameFun_M_MapIndexText_s1(Term term) { return  "MapIndexText$1" ; }
struct _ConstructionDescriptor descriptor_M_MapIndexText_s1 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_MapIndexText_s1), conBindOffs_M_MapIndexText_s1, &nameFun_M_MapIndexText_s1, &step_M_MapIndexText_s1};

int step_M_MapIndexText_s1(Sink sink__V1109, Term term__V1110)
{
  int term__V1110_count = LINK_COUNT(term__V1110); permitUnusedInt(term__V1110_count);
  Term sub__V1111 = FORCE(sink__V1109->context, SUB(term__V1110, 0));
  EnumOf_M__sList choice__V1112 = (IS_VARIABLE_USE(sub__V1111) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V1111));
  switch (choice__V1112)
  {
    case Data_M__sCons: { /* Function DEFS-MapIndexText-1$MapIndexText$1$$Cons case $Cons */
      ASSERT(sink__V1109->context, !strcmp(SYMBOL(term__V1110),  "MapIndexText$1" ));
      Term sub__V1113 = SUB(term__V1110, 0); permitUnusedTerm(sub__V1113); int sub__V1113_count = term__V1110_count*LINK_COUNT(sub__V1113); permitUnusedInt(sub__V1113_count);
      ASSERT(sink__V1109->context, !strcmp(SYMBOL(sub__V1113),  "$Cons" ));
      Term sub__V1114 = LINK(sink__V1109->context, SUB(sub__V1113, 0)); int sub__V1114_count = sub__V1113_count*LINK_COUNT(sub__V1114); permitUnusedInt(sub__V1114_count);
      /* sub__V1114 = &#0-0 */
      Term sub__V1115 = LINK(sink__V1109->context, SUB(sub__V1113, 1)); int sub__V1115_count = sub__V1113_count*LINK_COUNT(sub__V1115); permitUnusedInt(sub__V1115_count);
      /* sub__V1115 = &#0-1 */
      Variable x__V1116 = BINDER(term__V1110,1,0); if (term__V1110_count <= 1) UNBIND(x__V1116);
      Variable x__V1117 = BINDER(term__V1110,1,1); if (term__V1110_count <= 1) UNBIND(x__V1117);
      Term sub__V1118 = LINK(sink__V1109->context, SUB(term__V1110, 1)); int sub__V1118_count = term__V1110_count*LINK_COUNT(sub__V1118); permitUnusedInt(sub__V1118_count);
      CRSX_CHECK_SORT(sink__V1109->context, sub__V1118, &sort_M_Reified_xVariable); /* sub__V1118 = &#2 */
      Term sub__V1119 = LINK(sink__V1109->context, SUB(term__V1110, 2)); int sub__V1119_count = term__V1110_count*LINK_COUNT(sub__V1119); permitUnusedInt(sub__V1119_count);
      /* sub__V1119 = &#3 */
      
      NamedPropertyLink namedP__V1120 = LINK_NamedPropertyLink(sink__V1109->context, NAMED_PROPERTIES(term__V1110));
      VariablePropertyLink varP__V1121 = LINK_VariablePropertyLink(sink__V1109->context, VARIABLE_PROPERTIES(term__V1110));
      Hashset namedFV__V1122 = LINK_VARIABLESET(sink__V1109->context, asConstruction(term__V1110)->properties->namedFreeVars);
      Hashset varFV__V1123 = LINK_VARIABLESET(sink__V1109->context, asConstruction(term__V1110)->properties->variableFreeVars);
      UNLINK(sink__V1109->context, term__V1110);
      ADD_PROPERTIES(sink__V1109, LINK_VARIABLESET(sink__V1109->context, namedFV__V1122), LINK_VARIABLESET(sink__V1109->context, varFV__V1123), LINK_NamedPropertyLink(sink__V1109->context, namedP__V1120), LINK_VariablePropertyLink(sink__V1109->context, varP__V1121));
      { START(sink__V1109, _M_MapIndexText_s2);
        COPY(sink__V1109, sub__V1114);COPY(sink__V1109, sub__V1115);{ if (!IS_BOUND(x__V1116)) { REBIND(x__V1116);
            REBIND(x__V1117);
            Variable binds__V1124[2] = {x__V1116,x__V1117}; BINDS(sink__V1109, 2, binds__V1124);
            COPY(sink__V1109, sub__V1118); /* REUSED SUBSTITUTION */  }
          else { Variable b__V1125 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V1109->context,"b__V1125");
            Variable b__V1126 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V1109->context,"b__V1126");
            Variable binds__V1127[2] = {b__V1125,b__V1126}; BINDS(sink__V1109, 2, binds__V1127);
            {
              Term arg__V1128;
              { Sink buf__V1129 = ALLOCA_BUFFER(sink__V1109->context);
                USE(buf__V1129, b__V1125); arg__V1128 = BUFFER_TERM(buf__V1129); FREE_BUFFER(buf__V1129); }
              Term arg__V1130;
              { Sink buf__V1131 = ALLOCA_BUFFER(sink__V1109->context);
                USE(buf__V1131, b__V1126); arg__V1130 = BUFFER_TERM(buf__V1131); FREE_BUFFER(buf__V1131); }
              Variable vars__V1132[2] = {x__V1116,x__V1117};
              Term args__V1133[2] = {arg__V1128,arg__V1130};
              struct _SubstitutionFrame substitution__V1134 = {NULL, 0, 2, vars__V1132, args__V1133, NULL};
              SUBSTITUTE(sink__V1109, sub__V1118, &substitution__V1134); }
                }
           }
        COPY(sink__V1109, sub__V1119);END(sink__V1109, _M_MapIndexText_s2); }
      UNLINK_VARIABLESET(sink__V1109->context, namedFV__V1122); UNLINK_VARIABLESET(sink__V1109->context, varFV__V1123);
      UNLINK_NamedPropertyLink(sink__V1109->context, namedP__V1120); UNLINK_VariablePropertyLink(sink__V1109->context, varP__V1121);
      
      return 1;
    break; } case Data_M__sNil: { /* Function DEFS-MapIndexText-2$MapIndexText$1$$Nil case $Nil */
      ASSERT(sink__V1109->context, !strcmp(SYMBOL(term__V1110),  "MapIndexText$1" ));
      Term sub__V1135 = SUB(term__V1110, 0); permitUnusedTerm(sub__V1135); int sub__V1135_count = term__V1110_count*LINK_COUNT(sub__V1135); permitUnusedInt(sub__V1135_count);
      ASSERT(sink__V1109->context, !strcmp(SYMBOL(sub__V1135),  "$Nil" ));
      Variable x__V1136 = BINDER(term__V1110,1,0); if (term__V1110_count <= 1) UNBIND(x__V1136);
      Variable x__V1137 = BINDER(term__V1110,1,1); if (term__V1110_count <= 1) UNBIND(x__V1137);
      Term sub__V1138 = LINK(sink__V1109->context, SUB(term__V1110, 1)); int sub__V1138_count = term__V1110_count*LINK_COUNT(sub__V1138); permitUnusedInt(sub__V1138_count);
      CRSX_CHECK_SORT(sink__V1109->context, sub__V1138, &sort_M_Reified_xVariable); /* sub__V1138 = &#0 */
      Term sub__V1139 = LINK(sink__V1109->context, SUB(term__V1110, 2)); int sub__V1139_count = term__V1110_count*LINK_COUNT(sub__V1139); permitUnusedInt(sub__V1139_count);
      /* sub__V1139 = &#1 */
      
      NamedPropertyLink namedP__V1140 = LINK_NamedPropertyLink(sink__V1109->context, NAMED_PROPERTIES(term__V1110));
      VariablePropertyLink varP__V1141 = LINK_VariablePropertyLink(sink__V1109->context, VARIABLE_PROPERTIES(term__V1110));
      Hashset namedFV__V1142 = LINK_VARIABLESET(sink__V1109->context, asConstruction(term__V1110)->properties->namedFreeVars);
      Hashset varFV__V1143 = LINK_VARIABLESET(sink__V1109->context, asConstruction(term__V1110)->properties->variableFreeVars);
      UNLINK(sink__V1109->context, term__V1110);
      ADD_PROPERTIES(sink__V1109, LINK_VARIABLESET(sink__V1109->context, namedFV__V1142), LINK_VARIABLESET(sink__V1109->context, varFV__V1143), LINK_NamedPropertyLink(sink__V1109->context, namedP__V1140), LINK_VariablePropertyLink(sink__V1109->context, varP__V1141));
      { START(sink__V1109, _M_MapIndexText_s3);
        { if (!IS_BOUND(x__V1136)) { REBIND(x__V1136);
            REBIND(x__V1137);
            Variable binds__V1144[2] = {x__V1136,x__V1137}; BINDS(sink__V1109, 2, binds__V1144);
            COPY(sink__V1109, sub__V1138); /* REUSED SUBSTITUTION */  }
          else { Variable b__V1145 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V1109->context,"b__V1145");
            Variable b__V1146 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V1109->context,"b__V1146");
            Variable binds__V1147[2] = {b__V1145,b__V1146}; BINDS(sink__V1109, 2, binds__V1147);
            {
              Term arg__V1148;
              { Sink buf__V1149 = ALLOCA_BUFFER(sink__V1109->context);
                USE(buf__V1149, b__V1145); arg__V1148 = BUFFER_TERM(buf__V1149); FREE_BUFFER(buf__V1149); }
              Term arg__V1150;
              { Sink buf__V1151 = ALLOCA_BUFFER(sink__V1109->context);
                USE(buf__V1151, b__V1146); arg__V1150 = BUFFER_TERM(buf__V1151); FREE_BUFFER(buf__V1151); }
              Variable vars__V1152[2] = {x__V1136,x__V1137};
              Term args__V1153[2] = {arg__V1148,arg__V1150};
              struct _SubstitutionFrame substitution__V1154 = {NULL, 0, 2, vars__V1152, args__V1153, NULL};
              SUBSTITUTE(sink__V1109, sub__V1138, &substitution__V1154); }
                }
           }
        COPY(sink__V1109, sub__V1139);END(sink__V1109, _M_MapIndexText_s3); }
      UNLINK_VARIABLESET(sink__V1109->context, namedFV__V1142); UNLINK_VARIABLESET(sink__V1109->context, varFV__V1143);
      UNLINK_NamedPropertyLink(sink__V1109->context, namedP__V1140); UNLINK_VariablePropertyLink(sink__V1109->context, varP__V1141);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION MapIndexText$3. */
int conBindOffs_M_MapIndexText_s3[] = {0 , 2 , 2};
char *nameFun_M_MapIndexText_s3(Term term) { return  "MapIndexText$3" ; }
struct _ConstructionDescriptor descriptor_M_MapIndexText_s3 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_MapIndexText_s3), conBindOffs_M_MapIndexText_s3, &nameFun_M_MapIndexText_s3, &step_M_MapIndexText_s3};

int step_M_MapIndexText_s3(Sink sink__V1155, Term term__V1156)
{
  int term__V1156_count = LINK_COUNT(term__V1156); permitUnusedInt(term__V1156_count);
  do {
    /* Contraction rule DEFS-MapIndexText-2. */
    ASSERT(sink__V1155->context, !strcmp(SYMBOL(term__V1156),  "MapIndexText$3" ));
    Variable x__V1157 = BINDER(term__V1156,0,0); if (term__V1156_count <= 1) UNBIND(x__V1157);
    Variable x__V1158 = BINDER(term__V1156,0,1); if (term__V1156_count <= 1) UNBIND(x__V1158);
    Term sub__V1159 = SUB(term__V1156, 0); permitUnusedTerm(sub__V1159); int sub__V1159_count = term__V1156_count*LINK_COUNT(sub__V1159); permitUnusedInt(sub__V1159_count);
    CRSX_CHECK_SORT(sink__V1155->context, sub__V1159, &sort_M_Reified_xVariable); /* sub__V1159 = &#1 */
    Term sub__V1160 = SUB(term__V1156, 1); permitUnusedTerm(sub__V1160); int sub__V1160_count = term__V1156_count*LINK_COUNT(sub__V1160); permitUnusedInt(sub__V1160_count);
    /* sub__V1160 = &#3 */
    
    NamedPropertyLink namedP__V1161 = LINK_NamedPropertyLink(sink__V1155->context, NAMED_PROPERTIES(term__V1156));
    VariablePropertyLink varP__V1162 = LINK_VariablePropertyLink(sink__V1155->context, VARIABLE_PROPERTIES(term__V1156));
    Hashset namedFV__V1163 = LINK_VARIABLESET(sink__V1155->context, asConstruction(term__V1156)->properties->namedFreeVars);
    Hashset varFV__V1164 = LINK_VARIABLESET(sink__V1155->context, asConstruction(term__V1156)->properties->variableFreeVars);
    UNLINK(sink__V1155->context, term__V1156);
    { START(sink__V1155, _M__sTextNil);
      END(sink__V1155, _M__sTextNil); }
    UNLINK_VARIABLESET(sink__V1155->context, namedFV__V1163); UNLINK_VARIABLESET(sink__V1155->context, varFV__V1164);
    UNLINK_NamedPropertyLink(sink__V1155->context, namedP__V1161); UNLINK_VariablePropertyLink(sink__V1155->context, varP__V1162);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION If$1. */
int conBindOffs_M_If_s1[] = {0 , 0 , 0};
char *nameFun_M_If_s1(Term term) { return  "If$1" ; }
struct _ConstructionDescriptor descriptor_M_If_s1 = {NULL, 0, 2, sizeof(STRUCT_Con_M_If_s1), conBindOffs_M_If_s1, &nameFun_M_If_s1, &step_M_If_s1};

int step_M_If_s1(Sink sink__V1165, Term term__V1166)
{
  int term__V1166_count = LINK_COUNT(term__V1166); permitUnusedInt(term__V1166_count);
  do {
    /* Contraction rule DEFS-If-2. */
    ASSERT(sink__V1165->context, !strcmp(SYMBOL(term__V1166),  "If$1" ));
    Term sub__V1167 = SUB(term__V1166, 0); permitUnusedTerm(sub__V1167); int sub__V1167_count = term__V1166_count*LINK_COUNT(sub__V1167); permitUnusedInt(sub__V1167_count);
    /* sub__V1167 = &#2 */
    Term sub__V1168 = LINK(sink__V1165->context, SUB(term__V1166, 1)); int sub__V1168_count = term__V1166_count*LINK_COUNT(sub__V1168); permitUnusedInt(sub__V1168_count);
    /* sub__V1168 = &#3 */
    UNLINK(sink__V1165->context, term__V1166);
    COPY(sink__V1165, sub__V1168);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION If$2. */
int conBindOffs_M_If_s2[] = {0 , 0 , 0};
char *nameFun_M_If_s2(Term term) { return  "If$2" ; }
struct _ConstructionDescriptor descriptor_M_If_s2 = {NULL, 0, 2, sizeof(STRUCT_Con_M_If_s2), conBindOffs_M_If_s2, &nameFun_M_If_s2, &step_M_If_s2};

int step_M_If_s2(Sink sink__V1169, Term term__V1170)
{
  int term__V1170_count = LINK_COUNT(term__V1170); permitUnusedInt(term__V1170_count);
  do {
    /* Contraction rule DEFS-If-1. */
    ASSERT(sink__V1169->context, !strcmp(SYMBOL(term__V1170),  "If$2" ));
    Term sub__V1171 = LINK(sink__V1169->context, SUB(term__V1170, 0)); int sub__V1171_count = term__V1170_count*LINK_COUNT(sub__V1171); permitUnusedInt(sub__V1171_count);
    /* sub__V1171 = &#2 */
    Term sub__V1172 = SUB(term__V1170, 1); permitUnusedTerm(sub__V1172); int sub__V1172_count = term__V1170_count*LINK_COUNT(sub__V1172); permitUnusedInt(sub__V1172_count);
    /* sub__V1172 = &#3 */
    UNLINK(sink__V1169->context, term__V1170);
    COPY(sink__V1169, sub__V1171);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION MissingPrimitive. */
int conBindOffs_M_MissingPrimitive[] = {0 , 0};
char *nameFun_M_MissingPrimitive(Term term) { return  "MissingPrimitive" ; }
struct _ConstructionDescriptor descriptor_M_MissingPrimitive = {&sort_M_SPrimitive, 0, 1, sizeof(STRUCT_Con_M_MissingPrimitive), conBindOffs_M_MissingPrimitive, &nameFun_M_MissingPrimitive, &step_M_MissingPrimitive};

int step_M_MissingPrimitive(Sink sink__V1173, Term term__V1174)
{
  int term__V1174_count = LINK_COUNT(term__V1174); permitUnusedInt(term__V1174_count);
  do {
    /* Contraction rule DEFS-MissingPrimitive-1. */
    ASSERT(sink__V1173->context, !strcmp(SYMBOL(term__V1174),  "MissingPrimitive" ));
    Term sub__V1175 = LINK(sink__V1173->context, SUB(term__V1174, 0)); int sub__V1175_count = term__V1174_count*LINK_COUNT(sub__V1175); permitUnusedInt(sub__V1175_count);
    /* sub__V1175 = &#1 */
    UNLINK(sink__V1173->context, term__V1174);
    char *sub__V1176[3]; size_t sublength__V1177[3]; size_t length__V1178 = 0;
    length__V1178 += (sublength__V1177[0] = strlen(sub__V1176[0] =  "$[" ));
    FORCE(sink__V1173->context, sub__V1175); LINK(sink__V1173->context, sub__V1175);
    length__V1178 += (sublength__V1177[1] = strlen(sub__V1176[1] = SYMBOL(sub__V1175)));
     UNLINK(sink__V1173->context, sub__V1175);  UNLINK(sink__V1173->context, sub__V1175); length__V1178 += (sublength__V1177[2] = strlen(sub__V1176[2] =  "] not supported" ));
    { char *str__V1179 = ALLOCA(sink__V1173->context, length__V1178+1), *p__V1180 = str__V1179;
      int i; for (i = 0; i < 3; ++i) { memcpy(p__V1180, sub__V1176[i], sublength__V1177[i]); p__V1180 += sublength__V1177[i]; }
      *p__V1180 = '\0';
      ASSERT(sink__V1173->context, strlen(str__V1179) == length__V1178);
      ERRORF(sink__V1173->context, Default, "%s\n", str__V1179); }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Primitive. */
int conBindOffs_M_Primitive[] = {0 , 0};
char *nameFun_M_Primitive(Term term) { return  "Primitive" ; }
struct _ConstructionDescriptor descriptor_M_Primitive = {&sort_M_SPrimitive, 0, 1, sizeof(STRUCT_Con_M_Primitive), conBindOffs_M_Primitive, &nameFun_M_Primitive, &step_M_Primitive};

int step_M_Primitive(Sink sink__V1181, Term term__V1182)
{
  int term__V1182_count = LINK_COUNT(term__V1182); permitUnusedInt(term__V1182_count);
  do {
    /* Contraction rule DEFS-Primitive-1. */
    ASSERT(sink__V1181->context, !strcmp(SYMBOL(term__V1182),  "Primitive" ));
    Term sub__V1183 = LINK(sink__V1181->context, SUB(term__V1182, 0)); int sub__V1183_count = term__V1182_count*LINK_COUNT(sub__V1183); permitUnusedInt(sub__V1183_count);
    /* sub__V1183 = &#1 */
    UNLINK(sink__V1181->context, term__V1182);
    { int test__V1184;
      FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
      test__V1184 = (int) !strcmp(SYMBOL(sub__V1183), "C" );
      UNLINK(sink__V1181->context, sub__V1183);  if (test__V1184) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xC); END(sink__V1181, _M_E_xC); }  }
      else { { int test__V1185;
          FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
          test__V1185 = (int) !strcmp(SYMBOL(sub__V1183), "NumericEqual" );
          UNLINK(sink__V1181->context, sub__V1183);  if (test__V1185) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xNumericEqual);
              END(sink__V1181, _M_E_xNumericEqual); }
             }
          else { { int test__V1186;
              FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
              test__V1186 = (int) !strcmp(SYMBOL(sub__V1183), "StringLessThan" );
              UNLINK(sink__V1181->context, sub__V1183);  if (test__V1186) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xStringLessThan);
                  END(sink__V1181, _M_E_xStringLessThan); }
                 }
              else { { int test__V1187;
                  FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                  test__V1187 = (int) !strcmp(SYMBOL(sub__V1183), "LessThan" );
                  UNLINK(sink__V1181->context, sub__V1183);  if (test__V1187) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xLessThan);
                      END(sink__V1181, _M_E_xLessThan); }
                     }
                  else { { int test__V1188;
                      FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                      test__V1188 = (int) !strcmp(SYMBOL(sub__V1183), "GreaterThan" );
                      UNLINK(sink__V1181->context, sub__V1183);  if (test__V1188) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xGreaterThan);
                          END(sink__V1181, _M_E_xGreaterThan); }
                         }
                      else { { int test__V1189;
                          FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                          test__V1189 = (int) !strcmp(SYMBOL(sub__V1183), "LessThanOrEqual" );
                          UNLINK(sink__V1181->context, sub__V1183);  if (test__V1189) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xLessThanOrEqual);
                              END(sink__V1181, _M_E_xLessThanOrEqual); }
                             }
                          else { { int test__V1190;
                              FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                              test__V1190 = (int) !strcmp(SYMBOL(sub__V1183), "GreaterThanOrEqual" );
                               UNLINK(sink__V1181->context, sub__V1183);  if (test__V1190) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xGreaterThanOrEqual);
                                  END(sink__V1181, _M_E_xGreaterThanOrEqual); }
                                 }
                              else { { int test__V1191;
                                  FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                  test__V1191 = (int) !strcmp(SYMBOL(sub__V1183), "NotEqual" );
                                   UNLINK(sink__V1181->context, sub__V1183);  if (test__V1191) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xNotEqual);
                                      END(sink__V1181, _M_E_xNotEqual); }
                                     }
                                  else { { int test__V1192;
                                      FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                      test__V1192 = (int) !strcmp(SYMBOL(sub__V1183), ":" );
                                       UNLINK(sink__V1181->context, sub__V1183);  if (test__V1192) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xConcat);
                                          END(sink__V1181, _M_E_xConcat); }
                                         }
                                      else { { int test__V1193;
                                          FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                          test__V1193 = (int) !strcmp(SYMBOL(sub__V1183), "SameVariable" );
                                           UNLINK(sink__V1181->context, sub__V1183);  if (test__V1193) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xSameVariable);
                                              END(sink__V1181, _M_E_xSameVariable); }
                                             }
                                          else { { int test__V1194;
                                              FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                              test__V1194 = (int) !strcmp(SYMBOL(sub__V1183), "LesserVariable" );
                                               UNLINK(sink__V1181->context, sub__V1183);  if (test__V1194) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xLesserVariable);
                                                  END(sink__V1181, _M_E_xLesserVariable); }
                                                 }
                                              else { { int test__V1195;
                                                  FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                  test__V1195 = (int) !strcmp(SYMBOL(sub__V1183), "Equal" );
                                                   UNLINK(sink__V1181->context, sub__V1183);  if (test__V1195) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xEqual);
                                                      END(sink__V1181, _M_E_xEqual); }
                                                     }
                                                  else { { int test__V1196;
                                                      FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                      test__V1196 = (int) !strcmp(SYMBOL(sub__V1183), "Contains" );
                                                       UNLINK(sink__V1181->context, sub__V1183);  if (test__V1196) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xContains);
                                                          END(sink__V1181, _M_E_xContains); }
                                                         }
                                                      else { { int test__V1197;
                                                          FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                          test__V1197 = (int) !strcmp(SYMBOL(sub__V1183), "StartsWith" );
                                                           UNLINK(sink__V1181->context, sub__V1183);  if (test__V1197) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xStartsWith);
                                                              END(sink__V1181, _M_E_xStartsWith); }
                                                             }
                                                          else { { int test__V1198;
                                                              FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                              test__V1198 = (int) !strcmp(SYMBOL(sub__V1183), "EndsWith" );
                                                               UNLINK(sink__V1181->context, sub__V1183);  if (test__V1198) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xEndsWith);
                                                                  END(sink__V1181, _M_E_xEndsWith); }
                                                                 }
                                                              else { { int test__V1199;
                                                                  FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                  test__V1199 = (int) !strcmp(SYMBOL(sub__V1183), "Split" );
                                                                   UNLINK(sink__V1181->context, sub__V1183);  if (test__V1199) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xSplit);
                                                                      END(sink__V1181, _M_E_xSplit); }
                                                                     }
                                                                  else { { int test__V1200;
                                                                      FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                      test__V1200 = (int) !strcmp(SYMBOL(sub__V1183), "MatchRegex" );
                                                                       UNLINK(sink__V1181->context, sub__V1183);  if (test__V1200) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xMatchRegex);
                                                                          END(sink__V1181, _M_E_xMatchRegex); }
                                                                         }
                                                                      else { { int test__V1201;
                                                                          FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                          test__V1201 = (int) !strcmp(SYMBOL(sub__V1183), "Length" );
                                                                           UNLINK(sink__V1181->context, sub__V1183);  if (test__V1201) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xLength);
                                                                              END(sink__V1181, _M_E_xLength); }
                                                                             }
                                                                          else { { int test__V1202;
                                                                              FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                              test__V1202 = (int) !strcmp(SYMBOL(sub__V1183), "Substring" );
                                                                               UNLINK(sink__V1181->context, sub__V1183);  if (test__V1202) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xSubstring);
                                                                                  END(sink__V1181, _M_E_xSubstring); }
                                                                                 }
                                                                              else { { int test__V1203;
                                                                                  FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                  test__V1203 = (int) !strcmp(SYMBOL(sub__V1183), "Escape" );
                                                                                   UNLINK(sink__V1181->context, sub__V1183);  if (test__V1203) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xEscape);
                                                                                      END(sink__V1181, _M_E_xEscape); }
                                                                                     }
                                                                                  else { { int test__V1204;
                                                                                      FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                      test__V1204 = (int) !strcmp(SYMBOL(sub__V1183), "Mangle" );
                                                                                       UNLINK(sink__V1181->context, sub__V1183);  if (test__V1204) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xMangle);
                                                                                          END(sink__V1181, _M_E_xMangle); }
                                                                                         }
                                                                                      else { { int test__V1205;
                                                                                          FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                          test__V1205 = (int) !strcmp(SYMBOL(sub__V1183), "BeforeFirst" );
                                                                                           UNLINK(sink__V1181->context, sub__V1183);  if (test__V1205) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xBeforeFirst);
                                                                                              END(sink__V1181, _M_E_xBeforeFirst); }
                                                                                             }
                                                                                          else { { int test__V1206;
                                                                                              FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                              test__V1206 = (int) !strcmp(SYMBOL(sub__V1183), "AfterFirst" );
                                                                                               UNLINK(sink__V1181->context, sub__V1183);  if (test__V1206) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xAfterFirst);
                                                                                                  END(sink__V1181, _M_E_xAfterFirst); }
                                                                                                 }
                                                                                              else { { int test__V1207;
                                                                                                  FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                  test__V1207 = (int) !strcmp(SYMBOL(sub__V1183), "FromFirst" );
                                                                                                   UNLINK(sink__V1181->context, sub__V1183);  if (test__V1207) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xFromFirst);
                                                                                                      END(sink__V1181, _M_E_xFromFirst); }
                                                                                                     }
                                                                                                  else { { int test__V1208;
                                                                                                      FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                      test__V1208 = (int) !strcmp(SYMBOL(sub__V1183), "ToFirst" );
                                                                                                       UNLINK(sink__V1181->context, sub__V1183);  if (test__V1208) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xToFirst);
                                                                                                          END(sink__V1181, _M_E_xToFirst); }
                                                                                                         }
                                                                                                      else { { int test__V1209;
                                                                                                          FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                          test__V1209 = (int) !strcmp(SYMBOL(sub__V1183), "FormatNumber" );
                                                                                                           UNLINK(sink__V1181->context, sub__V1183);  if (test__V1209) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xFormatNumber);
                                                                                                              END(sink__V1181, _M_E_xFormatNumber); }
                                                                                                             }
                                                                                                          else { { int test__V1210;
                                                                                                              FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                              test__V1210 = (int) !strcmp(SYMBOL(sub__V1183), "Format" );
                                                                                                               UNLINK(sink__V1181->context, sub__V1183);  if (test__V1210) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xFormat);
                                                                                                                  END(sink__V1181, _M_E_xFormat); }
                                                                                                                 }
                                                                                                              else { { int test__V1211;
                                                                                                                  FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                  test__V1211 = (int) !strcmp(SYMBOL(sub__V1183), "Show" );
                                                                                                                   UNLINK(sink__V1181->context, sub__V1183);  if (test__V1211) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xShow);
                                                                                                                      END(sink__V1181, _M_E_xShow); }
                                                                                                                     }
                                                                                                                  else { { int test__V1212;
                                                                                                                      FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                      test__V1212 = (int) !strcmp(SYMBOL(sub__V1183), "PassLocationProperties" );
                                                                                                                       UNLINK(sink__V1181->context, sub__V1183);  if (test__V1212) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xPassLocationProperties);
                                                                                                                          END(sink__V1181, _M_E_xPassLocationProperties); }
                                                                                                                         }
                                                                                                                      else { { int test__V1213;
                                                                                                                          FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                          test__V1213 = (int) !strcmp(SYMBOL(sub__V1183), "Plus" );
                                                                                                                           UNLINK(sink__V1181->context, sub__V1183);  if (test__V1213) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xPlus);
                                                                                                                              END(sink__V1181, _M_E_xPlus); }
                                                                                                                             }
                                                                                                                          else { { int test__V1214;
                                                                                                                              FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                              test__V1214 = (int) !strcmp(SYMBOL(sub__V1183), "Minus" );
                                                                                                                               UNLINK(sink__V1181->context, sub__V1183);  if (test__V1214) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xMinus);
                                                                                                                                  END(sink__V1181, _M_E_xMinus); }
                                                                                                                                 }
                                                                                                                              else { { int test__V1215;
                                                                                                                                  FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                  test__V1215 = (int) !strcmp(SYMBOL(sub__V1183), "Times" );
                                                                                                                                   UNLINK(sink__V1181->context, sub__V1183);  if (test__V1215) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xTimes);
                                                                                                                                      END(sink__V1181, _M_E_xTimes); }
                                                                                                                                     }
                                                                                                                                  else { { int test__V1216;
                                                                                                                                      FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                      test__V1216 = (int) !strcmp(SYMBOL(sub__V1183), "Divide" );
                                                                                                                                       UNLINK(sink__V1181->context, sub__V1183);  if (test__V1216) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xDiv);
                                                                                                                                          END(sink__V1181, _M_E_xDiv); }
                                                                                                                                         }
                                                                                                                                      else { { int test__V1217;
                                                                                                                                          FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                          test__V1217 = (int) !strcmp(SYMBOL(sub__V1183), "Modulo" );
                                                                                                                                           UNLINK(sink__V1181->context, sub__V1183);  if (test__V1217) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xMod);
                                                                                                                                              END(sink__V1181, _M_E_xMod); }
                                                                                                                                             }
                                                                                                                                          else { { int test__V1218;
                                                                                                                                              FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                              test__V1218 = (int) !strcmp(SYMBOL(sub__V1183), "Absolute" );
                                                                                                                                               UNLINK(sink__V1181->context, sub__V1183);  if (test__V1218) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xAbsolute);
                                                                                                                                                  END(sink__V1181, _M_E_xAbsolute); }
                                                                                                                                                 }
                                                                                                                                              else { { int test__V1219;
                                                                                                                                                  FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                  test__V1219 = (int) !strcmp(SYMBOL(sub__V1183), "Decimal" );
                                                                                                                                                   UNLINK(sink__V1181->context, sub__V1183);  if (test__V1219) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xDecimal);
                                                                                                                                                      END(sink__V1181, _M_E_xDecimal); }
                                                                                                                                                     }
                                                                                                                                                  else { { int test__V1220;
                                                                                                                                                      FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                      test__V1220 = (int) !strcmp(SYMBOL(sub__V1183), "Hex" );
                                                                                                                                                       UNLINK(sink__V1181->context, sub__V1183);  if (test__V1220) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xHex);
                                                                                                                                                          END(sink__V1181, _M_E_xHex); }
                                                                                                                                                         }
                                                                                                                                                      else { { int test__V1221;
                                                                                                                                                          FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                          test__V1221 = (int) !strcmp(SYMBOL(sub__V1183), "BitAnd" );
                                                                                                                                                           UNLINK(sink__V1181->context, sub__V1183);  if (test__V1221) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xBitAnd);
                                                                                                                                                              END(sink__V1181, _M_E_xBitAnd); }
                                                                                                                                                             }
                                                                                                                                                          else { { int test__V1222;
                                                                                                                                                              FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                              test__V1222 = (int) !strcmp(SYMBOL(sub__V1183), "BitOr" );
                                                                                                                                                               UNLINK(sink__V1181->context, sub__V1183);  if (test__V1222) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xBitOr);
                                                                                                                                                                  END(sink__V1181, _M_E_xBitOr); }
                                                                                                                                                                 }
                                                                                                                                                              else { { int test__V1223;
                                                                                                                                                                  FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                                  test__V1223 = (int) !strcmp(SYMBOL(sub__V1183), "BitXor" );
                                                                                                                                                                   UNLINK(sink__V1181->context, sub__V1183);  if (test__V1223) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xBitXOr);
                                                                                                                                                                      END(sink__V1181, _M_E_xBitXOr); }
                                                                                                                                                                     }
                                                                                                                                                                  else { { int test__V1224;
                                                                                                                                                                      FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                                      test__V1224 = (int) !strcmp(SYMBOL(sub__V1183), "BitNot" );
                                                                                                                                                                       UNLINK(sink__V1181->context, sub__V1183);  if (test__V1224) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xBitNot);
                                                                                                                                                                          END(sink__V1181, _M_E_xBitNot); }
                                                                                                                                                                         }
                                                                                                                                                                      else { { int test__V1225;
                                                                                                                                                                          FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                                          test__V1225 = (int) !strcmp(SYMBOL(sub__V1183), "BitMinus" );
                                                                                                                                                                           UNLINK(sink__V1181->context, sub__V1183);  if (test__V1225) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xBitMinus);
                                                                                                                                                                              END(sink__V1181, _M_E_xBitMinus); }
                                                                                                                                                                             }
                                                                                                                                                                          else { { int test__V1226;
                                                                                                                                                                              FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                                              test__V1226 = (int) !strcmp(SYMBOL(sub__V1183), "BitSubSetEq" );
                                                                                                                                                                               UNLINK(sink__V1181->context, sub__V1183);  if (test__V1226) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xBitSubSetEq);
                                                                                                                                                                                  END(sink__V1181, _M_E_xBitSubSetEq); }
                                                                                                                                                                                 }
                                                                                                                                                                              else { { int test__V1227;
                                                                                                                                                                                  FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                                                  test__V1227 = (int) !strcmp(SYMBOL(sub__V1183), "Get" );
                                                                                                                                                                                   UNLINK(sink__V1181->context, sub__V1183);  if (test__V1227) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xGet);
                                                                                                                                                                                      END(sink__V1181, _M_E_xGet); }
                                                                                                                                                                                     }
                                                                                                                                                                                  else { { int test__V1228;
                                                                                                                                                                                      FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                                                      test__V1228 = (int) !strcmp(SYMBOL(sub__V1183), "GetRef" );
                                                                                                                                                                                       UNLINK(sink__V1181->context, sub__V1183);  if (test__V1228) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xGetRef);
                                                                                                                                                                                          END(sink__V1181, _M_E_xGetRef); }
                                                                                                                                                                                         }
                                                                                                                                                                                      else { { int test__V1229;
                                                                                                                                                                                          FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                                                          test__V1229 = (int) !strcmp(SYMBOL(sub__V1183), "IfDef" );
                                                                                                                                                                                           UNLINK(sink__V1181->context, sub__V1183);  if (test__V1229) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xIfDef);
                                                                                                                                                                                              END(sink__V1181, _M_E_xIfDef); }
                                                                                                                                                                                             }
                                                                                                                                                                                          else { { int test__V1230;
                                                                                                                                                                                              FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                                                              test__V1230 = (int) !strcmp(SYMBOL(sub__V1183), "Error" );
                                                                                                                                                                                               UNLINK(sink__V1181->context, sub__V1183);  if (test__V1230) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xError);
                                                                                                                                                                                                  END(sink__V1181, _M_E_xError); }
                                                                                                                                                                                                 }
                                                                                                                                                                                              else { { int test__V1231;
                                                                                                                                                                                                  FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                                                                  test__V1231 = (int) !strcmp(SYMBOL(sub__V1183), "ForgivableError" );
                                                                                                                                                                                                   UNLINK(sink__V1181->context, sub__V1183);  if (test__V1231) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xForgivableError);
                                                                                                                                                                                                      END(sink__V1181, _M_E_xForgivableError); }
                                                                                                                                                                                                     }
                                                                                                                                                                                                  else { { int test__V1232;
                                                                                                                                                                                                      FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                                                                      test__V1232 = (int) !strcmp(SYMBOL(sub__V1183), "Trace" );
                                                                                                                                                                                                       UNLINK(sink__V1181->context, sub__V1183);  if (test__V1232) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xTrace);
                                                                                                                                                                                                          END(sink__V1181, _M_E_xTrace); }
                                                                                                                                                                                                         }
                                                                                                                                                                                                      else { { int test__V1233;
                                                                                                                                                                                                          FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                                                                          test__V1233 = (int) !strcmp(SYMBOL(sub__V1183), "LoadTerm" );
                                                                                                                                                                                                           UNLINK(sink__V1181->context, sub__V1183);  if (test__V1233) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xLoadTerm);
                                                                                                                                                                                                              END(sink__V1181, _M_E_xLoadTerm); }
                                                                                                                                                                                                             }
                                                                                                                                                                                                          else { { int test__V1234;
                                                                                                                                                                                                              FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                                                                              test__V1234 = (int) !strcmp(SYMBOL(sub__V1183), "SaveTerm" );
                                                                                                                                                                                                               UNLINK(sink__V1181->context, sub__V1183);  if (test__V1234) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xSaveTerm);
                                                                                                                                                                                                                  END(sink__V1181, _M_E_xSaveTerm); }
                                                                                                                                                                                                                 }
                                                                                                                                                                                                              else { { int test__V1235;
                                                                                                                                                                                                                  FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                                                                                  test__V1235 = (int) !strcmp(SYMBOL(sub__V1183), "If" );
                                                                                                                                                                                                                   UNLINK(sink__V1181->context, sub__V1183);  if (test__V1235) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xIf);
                                                                                                                                                                                                                      END(sink__V1181, _M_E_xIf); }
                                                                                                                                                                                                                     }
                                                                                                                                                                                                                  else { { int test__V1236;
                                                                                                                                                                                                                      FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                                                                                      test__V1236 = (int) !strcmp(SYMBOL(sub__V1183), "IfZero" );
                                                                                                                                                                                                                       UNLINK(sink__V1181->context, sub__V1183);  if (test__V1236) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xIfZero);
                                                                                                                                                                                                                          END(sink__V1181, _M_E_xIfZero); }
                                                                                                                                                                                                                         }
                                                                                                                                                                                                                      else { { int test__V1237;
                                                                                                                                                                                                                          FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                                                                                          test__V1237 = (int) !strcmp(SYMBOL(sub__V1183), "IfEmpty" );
                                                                                                                                                                                                                           UNLINK(sink__V1181->context, sub__V1183);  if (test__V1237) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xIfEmpty);
                                                                                                                                                                                                                              END(sink__V1181, _M_E_xIfEmpty); }
                                                                                                                                                                                                                             }
                                                                                                                                                                                                                          else { { int test__V1238;
                                                                                                                                                                                                                              FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                                                                                              test__V1238 = (int) !strcmp(SYMBOL(sub__V1183), "FreeVariables" );
                                                                                                                                                                                                                               UNLINK(sink__V1181->context, sub__V1183);  if (test__V1238) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xFreeVariables);
                                                                                                                                                                                                                                  END(sink__V1181, _M_E_xFreeVariables); }
                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                              else { { int test__V1239;
                                                                                                                                                                                                                                  FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                                                                                                  test__V1239 = (int) !strcmp(SYMBOL(sub__V1183), "IntersectVariables" );
                                                                                                                                                                                                                                   UNLINK(sink__V1181->context, sub__V1183);  if (test__V1239) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xIntersectVariables);
                                                                                                                                                                                                                                      END(sink__V1181, _M_E_xIntersectVariables); }
                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                  else { { int test__V1240;
                                                                                                                                                                                                                                      FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                                                                                                      test__V1240 = (int) !strcmp(SYMBOL(sub__V1183), "UnionVariables" );
                                                                                                                                                                                                                                       UNLINK(sink__V1181->context, sub__V1183);  if (test__V1240) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xUnionVariables);
                                                                                                                                                                                                                                          END(sink__V1181, _M_E_xUnionVariables); }
                                                                                                                                                                                                                                         }
                                                                                                                                                                                                                                      else { { int test__V1241;
                                                                                                                                                                                                                                          FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                                                                                                          test__V1241 = (int) !strcmp(SYMBOL(sub__V1183), "ExceptVariables" );
                                                                                                                                                                                                                                           UNLINK(sink__V1181->context, sub__V1183);  if (test__V1241) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xExceptVariables);
                                                                                                                                                                                                                                              END(sink__V1181, _M_E_xExceptVariables); }
                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                          else { { int test__V1242;
                                                                                                                                                                                                                                              FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                                                                                                              test__V1242 = (int) !strcmp(SYMBOL(sub__V1183), "VariableNameIs" );
                                                                                                                                                                                                                                               UNLINK(sink__V1181->context, sub__V1183);  if (test__V1242) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xVariableNameIs);
                                                                                                                                                                                                                                                  END(sink__V1181, _M_E_xVariableNameIs); }
                                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                                              else { { int test__V1243;
                                                                                                                                                                                                                                                  FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                                                                                                                  test__V1243 = (int) !strcmp(SYMBOL(sub__V1183), "Match" );
                                                                                                                                                                                                                                                   UNLINK(sink__V1181->context, sub__V1183);  if (test__V1243) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xMatch);
                                                                                                                                                                                                                                                      END(sink__V1181, _M_E_xMatch); }
                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                  else { { int test__V1244;
                                                                                                                                                                                                                                                      FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                                                                                                                      test__V1244 = (int) !strcmp(SYMBOL(sub__V1183), "TryCall" );
                                                                                                                                                                                                                                                       UNLINK(sink__V1181->context, sub__V1183);  if (test__V1244) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xTryCall);
                                                                                                                                                                                                                                                          END(sink__V1181, _M_E_xTryCall); }
                                                                                                                                                                                                                                                         }
                                                                                                                                                                                                                                                      else { { int test__V1245;
                                                                                                                                                                                                                                                          FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                                                                                                                          test__V1245 = (int) !strcmp(SYMBOL(sub__V1183), "Call" );
                                                                                                                                                                                                                                                           UNLINK(sink__V1181->context, sub__V1183);  if (test__V1245) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xCall);
                                                                                                                                                                                                                                                              END(sink__V1181, _M_E_xCall); }
                                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                                          else { { int test__V1246;
                                                                                                                                                                                                                                                              FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                                                                                                                              test__V1246 = (int) !strcmp(SYMBOL(sub__V1183), "Cast" );
                                                                                                                                                                                                                                                               UNLINK(sink__V1181->context, sub__V1183);  if (test__V1246) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xCast);
                                                                                                                                                                                                                                                                  END(sink__V1181, _M_E_xCast); }
                                                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                                                              else { { int test__V1247;
                                                                                                                                                                                                                                                                  FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                                                                                                                                  test__V1247 = (int) !strcmp(SYMBOL(sub__V1183), "Null" );
                                                                                                                                                                                                                                                                   UNLINK(sink__V1181->context, sub__V1183);  if (test__V1247) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xNull);
                                                                                                                                                                                                                                                                      END(sink__V1181, _M_E_xNull); }
                                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                                  else { { int test__V1248;
                                                                                                                                                                                                                                                                      FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                                                                                                                                      test__V1248 = (int) !strcmp(SYMBOL(sub__V1183), "Nil" );
                                                                                                                                                                                                                                                                       UNLINK(sink__V1181->context, sub__V1183);  if (test__V1248) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xNil);
                                                                                                                                                                                                                                                                          END(sink__V1181, _M_E_xNil); }
                                                                                                                                                                                                                                                                         }
                                                                                                                                                                                                                                                                      else { { int test__V1249;
                                                                                                                                                                                                                                                                          FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                                                                                                                                          test__V1249 = (int) !strcmp(SYMBOL(sub__V1183), "UpCase" );
                                                                                                                                                                                                                                                                           UNLINK(sink__V1181->context, sub__V1183);  if (test__V1249) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xUpCase);
                                                                                                                                                                                                                                                                              END(sink__V1181, _M_E_xUpCase); }
                                                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                                                          else { { int test__V1250;
                                                                                                                                                                                                                                                                              FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                                                                                                                                              test__V1250 = (int) !strcmp(SYMBOL(sub__V1183), "DownCase" );
                                                                                                                                                                                                                                                                               UNLINK(sink__V1181->context, sub__V1183);  if (test__V1250) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xDownCase);
                                                                                                                                                                                                                                                                                  END(sink__V1181, _M_E_xDownCase); }
                                                                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                                                                              else { { int test__V1251;
                                                                                                                                                                                                                                                                                  FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                                                                                                                                                  test__V1251 = (int) !strcmp(SYMBOL(sub__V1183), "Replace" );
                                                                                                                                                                                                                                                                                   UNLINK(sink__V1181->context, sub__V1183);  if (test__V1251) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xReplace);
                                                                                                                                                                                                                                                                                      END(sink__V1181, _M_E_xReplace); }
                                                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                                                  else { { int test__V1252;
                                                                                                                                                                                                                                                                                      FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                                                                                                                                                      test__V1252 = (int) !strcmp(SYMBOL(sub__V1183), "Trim" );
                                                                                                                                                                                                                                                                                       UNLINK(sink__V1181->context, sub__V1183);  if (test__V1252) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xTrim);
                                                                                                                                                                                                                                                                                          END(sink__V1181, _M_E_xTrim); }
                                                                                                                                                                                                                                                                                         }
                                                                                                                                                                                                                                                                                      else { { int test__V1253;
                                                                                                                                                                                                                                                                                          FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                                                                                                                                                          test__V1253 = (int) !strcmp(SYMBOL(sub__V1183), "Split" );
                                                                                                                                                                                                                                                                                           UNLINK(sink__V1181->context, sub__V1183);  if (test__V1253) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xSplit);
                                                                                                                                                                                                                                                                                              END(sink__V1181, _M_E_xSplit); }
                                                                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                                                                          else { { int test__V1254;
                                                                                                                                                                                                                                                                                              FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                                                                                                                                                              test__V1254 = (int) !strcmp(SYMBOL(sub__V1183), "Rescape" );
                                                                                                                                                                                                                                                                                               UNLINK(sink__V1181->context, sub__V1183);  if (test__V1254) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xRescape);
                                                                                                                                                                                                                                                                                                  END(sink__V1181, _M_E_xRescape); }
                                                                                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                                                                                              else { { int test__V1255;
                                                                                                                                                                                                                                                                                                  FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                                                                                                                                                                  test__V1255 = (int) !strcmp(SYMBOL(sub__V1183), "Keys" );
                                                                                                                                                                                                                                                                                                   UNLINK(sink__V1181->context, sub__V1183);  if (test__V1255) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xKeys);
                                                                                                                                                                                                                                                                                                      END(sink__V1181, _M_E_xKeys); }
                                                                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                                                                  else { { int test__V1256;
                                                                                                                                                                                                                                                                                                      FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                                                                                                                                                                      test__V1256 = (int) !strcmp(SYMBOL(sub__V1183), "ParseURL" );
                                                                                                                                                                                                                                                                                                       UNLINK(sink__V1181->context, sub__V1183);  if (test__V1256) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xParseURL);
                                                                                                                                                                                                                                                                                                          END(sink__V1181, _M_E_xParseURL); }
                                                                                                                                                                                                                                                                                                         }
                                                                                                                                                                                                                                                                                                      else { { int test__V1257;
                                                                                                                                                                                                                                                                                                          FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                                                                                                                                                                          test__V1257 = (int) !strcmp(SYMBOL(sub__V1183), "Echo" );
                                                                                                                                                                                                                                                                                                           UNLINK(sink__V1181->context, sub__V1183);  if (test__V1257) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xEcho);
                                                                                                                                                                                                                                                                                                              END(sink__V1181, _M_E_xEcho); }
                                                                                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                                                                                          else { { int test__V1258;
                                                                                                                                                                                                                                                                                                              FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                                                                                                                                                                              test__V1258 = (int) !strcmp(SYMBOL(sub__V1183), "DeepEqual" );
                                                                                                                                                                                                                                                                                                               UNLINK(sink__V1181->context, sub__V1183);  if (test__V1258) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xDeepEqual);
                                                                                                                                                                                                                                                                                                                  END(sink__V1181, _M_E_xDeepEqual); }
                                                                                                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                                                                                                              else { { int test__V1259;
                                                                                                                                                                                                                                                                                                                  FORCE(sink__V1181->context, sub__V1183); LINK(sink__V1181->context, sub__V1183);
                                                                                                                                                                                                                                                                                                                  test__V1259 = (int) !strcmp(SYMBOL(sub__V1183), "HashCode" );
                                                                                                                                                                                                                                                                                                                   UNLINK(sink__V1181->context, sub__V1183);  if (test__V1259) {  UNLINK(sink__V1181->context, sub__V1183); { START(sink__V1181, _M_E_xHashCode);
                                                                                                                                                                                                                                                                                                                      END(sink__V1181, _M_E_xHashCode); }
                                                                                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                                                                                  else { { START(sink__V1181, _M_MissingPrimitive);
                                                                                                                                                                                                                                                                                                                      COPY(sink__V1181, sub__V1183);END(sink__V1181, _M_MissingPrimitive); }
                                                                                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                                                         }
                                                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                                         }
                                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                         }
                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                         }
                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                         }
                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                            }
                                                                                                                                                                                                                             }
                                                                                                                                                                                                                        }
                                                                                                                                                                                                                         }
                                                                                                                                                                                                                    }
                                                                                                                                                                                                                     }
                                                                                                                                                                                                                }
                                                                                                                                                                                                                 }
                                                                                                                                                                                                            }
                                                                                                                                                                                                             }
                                                                                                                                                                                                        }
                                                                                                                                                                                                         }
                                                                                                                                                                                                    }
                                                                                                                                                                                                     }
                                                                                                                                                                                                }
                                                                                                                                                                                                 }
                                                                                                                                                                                            }
                                                                                                                                                                                             }
                                                                                                                                                                                        }
                                                                                                                                                                                         }
                                                                                                                                                                                    }
                                                                                                                                                                                     }
                                                                                                                                                                                }
                                                                                                                                                                                 }
                                                                                                                                                                            }
                                                                                                                                                                             }
                                                                                                                                                                        }
                                                                                                                                                                         }
                                                                                                                                                                    }
                                                                                                                                                                     }
                                                                                                                                                                }
                                                                                                                                                                 }
                                                                                                                                                            }
                                                                                                                                                             }
                                                                                                                                                        }
                                                                                                                                                         }
                                                                                                                                                    }
                                                                                                                                                     }
                                                                                                                                                }
                                                                                                                                                 }
                                                                                                                                            }
                                                                                                                                             }
                                                                                                                                        }
                                                                                                                                         }
                                                                                                                                    }
                                                                                                                                     }
                                                                                                                                }
                                                                                                                                 }
                                                                                                                            }
                                                                                                                             }
                                                                                                                        }
                                                                                                                         }
                                                                                                                    }
                                                                                                                     }
                                                                                                                }
                                                                                                                 }
                                                                                                            }
                                                                                                             }
                                                                                                        }
                                                                                                         }
                                                                                                    }
                                                                                                     }
                                                                                                }
                                                                                                 }
                                                                                            }
                                                                                             }
                                                                                        }
                                                                                         }
                                                                                    }
                                                                                     }
                                                                                }
                                                                                 }
                                                                            }
                                                                             }
                                                                        }
                                                                         }
                                                                    }
                                                                     }
                                                                }
                                                                 }
                                                            }
                                                             }
                                                        }
                                                         }
                                                    }
                                                     }
                                                }
                                                 }
                                            }
                                             }
                                        }
                                         }
                                    }
                                     }
                                }
                                 }
                            }
                             }
                        }
                         }
                    }
                     }
                }
                 }
            }
             }
        }
         }
    }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION STRING. */
int conBindOffs_M_STRING[] = {0 , 0};
char *nameFun_M_STRING(Term term) { return  "STRING" ; }
struct _ConstructionDescriptor descriptor_M_STRING = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_STRING), conBindOffs_M_STRING, &nameFun_M_STRING, &step_M_STRING};

int step_M_STRING(Sink sink__V1260, Term term__V1261)
{
  int term__V1261_count = LINK_COUNT(term__V1261); permitUnusedInt(term__V1261_count);
  do {
    /* Contraction rule DEFS-STRING-1. */
    ASSERT(sink__V1260->context, !strcmp(SYMBOL(term__V1261),  "STRING" ));
    Term sub__V1262 = LINK(sink__V1260->context, SUB(term__V1261, 0)); int sub__V1262_count = term__V1261_count*LINK_COUNT(sub__V1262); permitUnusedInt(sub__V1262_count);
    UNLINK_SUB(sink__V1260->context, term__V1261,  0); NORMALIZE(sink__V1260->context, sub__V1262); SUB(term__V1261,  0) = LINK(sink__V1260->context, sub__V1262);
    /* sub__V1262 = &#1 */
    
    NamedPropertyLink namedP__V1263 = LINK_NamedPropertyLink(sink__V1260->context, NAMED_PROPERTIES(term__V1261));
    VariablePropertyLink varP__V1264 = LINK_VariablePropertyLink(sink__V1260->context, VARIABLE_PROPERTIES(term__V1261));
    Hashset namedFV__V1265 = LINK_VARIABLESET(sink__V1260->context, asConstruction(term__V1261)->properties->namedFreeVars);
    Hashset varFV__V1266 = LINK_VARIABLESET(sink__V1260->context, asConstruction(term__V1261)->properties->variableFreeVars);
    UNLINK(sink__V1260->context, term__V1261);
    { START(sink__V1260, _M__sTextCons);
      { START(sink__V1260, _M__sTextChars);
        LITERAL(sink__V1260,  " " ); END(sink__V1260, _M__sTextChars); }
      { START(sink__V1260, _M__sTextCons);
        { START(sink__V1260, _M__sTextString);
          { START(sink__V1260, _M__sTextCons);
            { START(sink__V1260, _M__sTextChars);
              { char *str__V1267;
                FORCE(sink__V1260->context, sub__V1262); LINK(sink__V1260->context, sub__V1262);
                {str__V1267 = makeEscaped(sink__V1260->context, SYMBOL(sub__V1262));
                   UNLINK(sink__V1260->context, sub__V1262);  UNLINK(sink__V1260->context, sub__V1262); }
                LITERALU(sink__V1260, str__V1267); }
              END(sink__V1260, _M__sTextChars); }
            { START(sink__V1260, _M__sTextNil);
              END(sink__V1260, _M__sTextNil); }
            END(sink__V1260, _M__sTextCons); }
          END(sink__V1260, _M__sTextString); }
        { START(sink__V1260, _M__sTextCons);
          { START(sink__V1260, _M__sTextChars);
            LITERAL(sink__V1260,  " " ); END(sink__V1260, _M__sTextChars); }
          { START(sink__V1260, _M__sTextNil);
            END(sink__V1260, _M__sTextNil); }
          END(sink__V1260, _M__sTextCons); }
        END(sink__V1260, _M__sTextCons); }
      END(sink__V1260, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V1260->context, namedFV__V1265); UNLINK_VARIABLESET(sink__V1260->context, varFV__V1266);
    UNLINK_NamedPropertyLink(sink__V1260->context, namedP__V1263); UNLINK_VariablePropertyLink(sink__V1260->context, varP__V1264);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Sort-name$1. */
int conBindOffs_M_Sort__name_s1[] = {0 , 0 , 0};
char *nameFun_M_Sort__name_s1(Term term) { return  "Sort-name$1" ; }
struct _ConstructionDescriptor descriptor_M_Sort__name_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_Sort__name_s1), conBindOffs_M_Sort__name_s1, &nameFun_M_Sort__name_s1, &step_M_Sort__name_s1};

int step_M_Sort__name_s1(Sink sink__V1268, Term term__V1269)
{
  int term__V1269_count = LINK_COUNT(term__V1269); permitUnusedInt(term__V1269_count);
  do {
    /* Contraction rule DEFS-Sort-name-1. */
    ASSERT(sink__V1268->context, !strcmp(SYMBOL(term__V1269),  "Sort-name$1" ));
    Term sub__V1270 = LINK(sink__V1268->context, SUB(term__V1269, 0)); int sub__V1270_count = term__V1269_count*LINK_COUNT(sub__V1270); permitUnusedInt(sub__V1270_count);
    /* sub__V1270 = &#11 */
    Term sub__V1271 = SUB(term__V1269, 1); permitUnusedTerm(sub__V1271); int sub__V1271_count = term__V1269_count*LINK_COUNT(sub__V1271); permitUnusedInt(sub__V1271_count);
    /* sub__V1271 = &#12 */
    
    NamedPropertyLink namedP__V1272 = LINK_NamedPropertyLink(sink__V1268->context, NAMED_PROPERTIES(term__V1269));
    VariablePropertyLink varP__V1273 = LINK_VariablePropertyLink(sink__V1268->context, VARIABLE_PROPERTIES(term__V1269));
    Hashset namedFV__V1274 = LINK_VARIABLESET(sink__V1268->context, asConstruction(term__V1269)->properties->namedFreeVars);
    Hashset varFV__V1275 = LINK_VARIABLESET(sink__V1268->context, asConstruction(term__V1269)->properties->variableFreeVars);
    UNLINK(sink__V1268->context, term__V1269);
    { START(sink__V1268, _M_TOKEN);
      COPY(sink__V1268, sub__V1270);END(sink__V1268, _M_TOKEN); }
    UNLINK_VARIABLESET(sink__V1268->context, namedFV__V1274); UNLINK_VARIABLESET(sink__V1268->context, varFV__V1275);
    UNLINK_NamedPropertyLink(sink__V1268->context, namedP__V1272); UNLINK_VariablePropertyLink(sink__V1268->context, varP__V1273);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION UnVariable$1. */
int conBindOffs_M_UnVariable_s1[] = {0 , 0};
char *nameFun_M_UnVariable_s1(Term term) { return  "UnVariable$1" ; }
struct _ConstructionDescriptor descriptor_M_UnVariable_s1 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_UnVariable_s1), conBindOffs_M_UnVariable_s1, &nameFun_M_UnVariable_s1, &step_M_UnVariable_s1};

int step_M_UnVariable_s1(Sink sink__V1276, Term term__V1277)
{
  int term__V1277_count = LINK_COUNT(term__V1277); permitUnusedInt(term__V1277_count);
  do {
    /* Contraction rule DEFS-UnVariable-1. */
    ASSERT(sink__V1276->context, !strcmp(SYMBOL(term__V1277),  "UnVariable$1" ));
    Term sub__V1278 = LINK(sink__V1276->context, SUB(term__V1277, 0)); int sub__V1278_count = term__V1277_count*LINK_COUNT(sub__V1278); permitUnusedInt(sub__V1278_count);
    CRSX_CHECK_SORT(sink__V1276->context, sub__V1278, &sort_M_Reified_xVariable); /* sub__V1278 = &#11 */
    
    NamedPropertyLink namedP__V1279 = LINK_NamedPropertyLink(sink__V1276->context, NAMED_PROPERTIES(term__V1277));
    VariablePropertyLink varP__V1280 = LINK_VariablePropertyLink(sink__V1276->context, VARIABLE_PROPERTIES(term__V1277));
    Hashset namedFV__V1281 = LINK_VARIABLESET(sink__V1276->context, asConstruction(term__V1277)->properties->namedFreeVars);
    Hashset varFV__V1282 = LINK_VARIABLESET(sink__V1276->context, asConstruction(term__V1277)->properties->variableFreeVars);
    UNLINK(sink__V1276->context, term__V1277);
    COPY(sink__V1276, sub__V1278);UNLINK_VARIABLESET(sink__V1276->context, namedFV__V1281); UNLINK_VARIABLESET(sink__V1276->context, varFV__V1282);
    UNLINK_NamedPropertyLink(sink__V1276->context, namedP__V1279); UNLINK_VariablePropertyLink(sink__V1276->context, varP__V1280);
    return 1;
  } while (0);
  return 0;
}

#ifdef __cplusplus
}
#endif
/* END OF C RULES FOR CRSX CRSXC MODULE D. */
