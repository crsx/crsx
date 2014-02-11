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
      UNLINK(sink__V1->context, term__V2);
      ADD_PROPERTIES(sink__V1, LINK_NamedPropertyLink(sink__V1->context, namedP__V7), LINK_VariablePropertyLink(sink__V1->context, varP__V8));
      { START(sink__V1, _M_DCOMMENT_xTOKEN_s1);
        COPY(sink__V1, sub__V6);END(sink__V1, _M_DCOMMENT_xTOKEN_s1); }
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

int step_M_IfZero(Sink sink__V9, Term term__V10)
{
  int term__V10_count = LINK_COUNT(term__V10); permitUnusedInt(term__V10_count);
  do {
    /* Contraction rule DEFS-IfZero-1. */
    ASSERT(sink__V9->context, !strcmp(SYMBOL(term__V10),  "IfZero" ));
    Term sub__V11 = LINK(sink__V9->context, SUB(term__V10, 0)); int sub__V11_count = term__V10_count*LINK_COUNT(sub__V11); permitUnusedInt(sub__V11_count);
    UNLINK_SUB(sink__V9->context, term__V10,  0); NORMALIZE(sink__V9->context, sub__V11); SUB(term__V10,  0) = LINK(sink__V9->context, sub__V11);
    /* sub__V11 = &#1 */
    Term sub__V12 = LINK(sink__V9->context, SUB(term__V10, 1)); int sub__V12_count = term__V10_count*LINK_COUNT(sub__V12); permitUnusedInt(sub__V12_count);
    /* sub__V12 = &#2 */
    Term sub__V13 = LINK(sink__V9->context, SUB(term__V10, 2)); int sub__V13_count = term__V10_count*LINK_COUNT(sub__V13); permitUnusedInt(sub__V13_count);
    /* sub__V13 = &#3 */
    UNLINK(sink__V9->context, term__V10);
    { long long intt__V14;
      intt__V14 = LONGLONG(sub__V11); if (intt__V14 == 0ll) {  UNLINK(sink__V9->context, sub__V13); COPY(sink__V9, sub__V12); }
      else { COPY(sink__V9, sub__V13); }
    }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION MetaVar2. */
int conBindOffs_M_MetaVar2[] = {0 , 0};
char *nameFun_M_MetaVar2(Term term) { return  "MetaVar2" ; }
struct _ConstructionDescriptor descriptor_M_MetaVar2 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_MetaVar2), conBindOffs_M_MetaVar2, &nameFun_M_MetaVar2, &step_M_MetaVar2};

int step_M_MetaVar2(Sink sink__V15, Term term__V16)
{
  int term__V16_count = LINK_COUNT(term__V16); permitUnusedInt(term__V16_count);
  Term sub__V17 = FORCE(sink__V15->context, SUB(term__V16, 0));
  EnumOf_M_STRING_xENTRY choice__V18 = (IS_VARIABLE_USE(sub__V17) ? VarOf_M_STRING_xENTRY : (EnumOf_M_STRING_xENTRY) TAG(sub__V17));
  switch (choice__V18)
  {
    case Data_M_VARIABLE: { /* Function DEFS-MetaVar2-1$MetaVar2$VARIABLE case VARIABLE */
      ASSERT(sink__V15->context, !strcmp(SYMBOL(term__V16),  "MetaVar2" ));
      Term sub__V19 = SUB(term__V16, 0); permitUnusedTerm(sub__V19); int sub__V19_count = term__V16_count*LINK_COUNT(sub__V19); permitUnusedInt(sub__V19_count);
      CRSX_CHECK_SORT(sink__V15->context, sub__V19, &sort_M_STRING_xENTRY); ASSERT(sink__V15->context, !strcmp(SYMBOL(sub__V19),  "VARIABLE" ));
      Term sub__V20 = LINK(sink__V15->context, SUB(sub__V19, 0)); int sub__V20_count = sub__V19_count*LINK_COUNT(sub__V20); permitUnusedInt(sub__V20_count);
      CRSX_CHECK_SORT(sink__V15->context, sub__V20, &sort_M_Reified_xVariable); /* sub__V20 = &#0-0 */
      NamedPropertyLink namedP__V21 = LINK_NamedPropertyLink(sink__V15->context, NAMED_PROPERTIES(term__V16));
      VariablePropertyLink varP__V22 = LINK_VariablePropertyLink(sink__V15->context, VARIABLE_PROPERTIES(term__V16));
      UNLINK(sink__V15->context, term__V16);
      ADD_PROPERTIES(sink__V15, LINK_NamedPropertyLink(sink__V15->context, namedP__V21), LINK_VariablePropertyLink(sink__V15->context, varP__V22));
      { START(sink__V15, _M_MetaVar2_s2);
        COPY(sink__V15, sub__V20);END(sink__V15, _M_MetaVar2_s2); }
      UNLINK_NamedPropertyLink(sink__V15->context, namedP__V21); UNLINK_VariablePropertyLink(sink__V15->context, varP__V22);
      
      return 1;
    break; } case Data_M_STRING_xVALUE: { /* Function DEFS-MetaVar2-2$MetaVar2$STRING_VALUE case STRING_VALUE */
      ASSERT(sink__V15->context, !strcmp(SYMBOL(term__V16),  "MetaVar2" ));
      Term sub__V23 = SUB(term__V16, 0); permitUnusedTerm(sub__V23); int sub__V23_count = term__V16_count*LINK_COUNT(sub__V23); permitUnusedInt(sub__V23_count);
      CRSX_CHECK_SORT(sink__V15->context, sub__V23, &sort_M_STRING_xENTRY); ASSERT(sink__V15->context, !strcmp(SYMBOL(sub__V23),  "STRING_VALUE" ));
      Term sub__V24 = LINK(sink__V15->context, SUB(sub__V23, 0)); int sub__V24_count = sub__V23_count*LINK_COUNT(sub__V24); permitUnusedInt(sub__V24_count);
      /* sub__V24 = &#0-0 */
      NamedPropertyLink namedP__V25 = LINK_NamedPropertyLink(sink__V15->context, NAMED_PROPERTIES(term__V16));
      VariablePropertyLink varP__V26 = LINK_VariablePropertyLink(sink__V15->context, VARIABLE_PROPERTIES(term__V16));
      UNLINK(sink__V15->context, term__V16);
      ADD_PROPERTIES(sink__V15, LINK_NamedPropertyLink(sink__V15->context, namedP__V25), LINK_VariablePropertyLink(sink__V15->context, varP__V26));
      { START(sink__V15, _M_MetaVar2_s1);
        COPY(sink__V15, sub__V24);END(sink__V15, _M_MetaVar2_s1); }
      UNLINK_NamedPropertyLink(sink__V15->context, namedP__V25); UNLINK_VariablePropertyLink(sink__V15->context, varP__V26);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION COMMENT_TOKEN. */
int conBindOffs_M_COMMENT_xTOKEN[] = {0 , 0};
char *nameFun_M_COMMENT_xTOKEN(Term term) { return  "COMMENT_TOKEN" ; }
struct _ConstructionDescriptor descriptor_M_COMMENT_xTOKEN = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_COMMENT_xTOKEN), conBindOffs_M_COMMENT_xTOKEN, &nameFun_M_COMMENT_xTOKEN, &step_M_COMMENT_xTOKEN};

int step_M_COMMENT_xTOKEN(Sink sink__V27, Term term__V28)
{
  int term__V28_count = LINK_COUNT(term__V28); permitUnusedInt(term__V28_count);
  do {
    /* Contraction rule DEFS-COMMENT_TOKEN-1. */
    ASSERT(sink__V27->context, !strcmp(SYMBOL(term__V28),  "COMMENT_TOKEN" ));
    Term sub__V29 = LINK(sink__V27->context, SUB(term__V28, 0)); int sub__V29_count = term__V28_count*LINK_COUNT(sub__V29); permitUnusedInt(sub__V29_count);
    UNLINK_SUB(sink__V27->context, term__V28,  0); NORMALIZE(sink__V27->context, sub__V29); SUB(term__V28,  0) = LINK(sink__V27->context, sub__V29);
    /* sub__V29 = &#1 */
    NamedPropertyLink namedP__V30 = LINK_NamedPropertyLink(sink__V27->context, NAMED_PROPERTIES(term__V28));
    VariablePropertyLink varP__V31 = LINK_VariablePropertyLink(sink__V27->context, VARIABLE_PROPERTIES(term__V28));
    UNLINK(sink__V27->context, term__V28);
    { START(sink__V27, _M__sTextCons);
      { START(sink__V27, _M__sTextChars);
        { char *str__V32;
          FORCE(sink__V27->context, sub__V29);
          { char *replaced__V33;
            const size_t z = strlen(SYMBOL(sub__V29));
            if (* "*/" ) {
              const size_t oldz = strlen( "*/" ), newz = strlen( "*_/" );
              size_t limitz;
              if (oldz==newz) { limitz = z; }
              else { limitz = z; size_t growz = (oldz < newz ? newz - oldz : 0);
                if (growz > 0) { char *p = SYMBOL(sub__V29); while ((p = strstr(p,  "*/" ))) { limitz += growz; p += oldz; } } }
              replaced__V33 = ALLOCA(sink__V27->context, limitz+1);
              if (oldz==newz) { memcpy(replaced__V33, SYMBOL(sub__V29), z+1);
                char *r = replaced__V33; while ((r = strstr(r,  "*/" ))) { memcpy(r,  "*_/" , newz); r += oldz; } }
              else { char *s = SYMBOL(sub__V29), *ends = s+z, *r = replaced__V33, *next;
                while ((next = strstr(s,  "*/" ))) { size_t prez = next-s;
                  if (prez) { memcpy(r, s, prez); r += prez; } 
                  if (newz) { memcpy(r,  "*_/" , newz); r += newz; }
                  s = next+oldz;}
                if (s < ends) { memcpy(r, s, ends-s); r += ends-s; }
                *r = '\0';}
              }
            else { replaced__V33 = memcpy(ALLOCA(sink__V27->context, z+1), SYMBOL(sub__V29), z+1); }
             UNLINK(sink__V27->context, sub__V29);{ size_t z__V34 = strlen(replaced__V33) + 1; memcpy(str__V32 = ALLOCATE(sink__V27->context, z__V34), replaced__V33, z__V34); }
            
          }LITERALU(sink__V27, str__V32); }
        END(sink__V27, _M__sTextChars); }
      { START(sink__V27, _M__sTextNil); END(sink__V27, _M__sTextNil); }
      END(sink__V27, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V27->context, namedP__V30); UNLINK_VariablePropertyLink(sink__V27->context, varP__V31);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DTOKEN$1. */
int conBindOffs_M_DTOKEN_s1[] = {0 , 0};
char *nameFun_M_DTOKEN_s1(Term term) { return  "DTOKEN$1" ; }
struct _ConstructionDescriptor descriptor_M_DTOKEN_s1 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_DTOKEN_s1), conBindOffs_M_DTOKEN_s1, &nameFun_M_DTOKEN_s1, &step_M_DTOKEN_s1};

int step_M_DTOKEN_s1(Sink sink__V35, Term term__V36)
{
  int term__V36_count = LINK_COUNT(term__V36); permitUnusedInt(term__V36_count);
  do {
    /* Contraction rule DEFS-DTOKEN-1. */
    ASSERT(sink__V35->context, !strcmp(SYMBOL(term__V36),  "DTOKEN$1" ));
    Term sub__V37 = LINK(sink__V35->context, SUB(term__V36, 0)); int sub__V37_count = term__V36_count*LINK_COUNT(sub__V37); permitUnusedInt(sub__V37_count);
    UNLINK_SUB(sink__V35->context, term__V36,  0); NORMALIZE(sink__V35->context, sub__V37); SUB(term__V36,  0) = LINK(sink__V35->context, sub__V37);
    /* sub__V37 = &#2 */
    NamedPropertyLink namedP__V38 = LINK_NamedPropertyLink(sink__V35->context, NAMED_PROPERTIES(term__V36));
    VariablePropertyLink varP__V39 = LINK_VariablePropertyLink(sink__V35->context, VARIABLE_PROPERTIES(term__V36));
    UNLINK(sink__V35->context, term__V36);
    { START(sink__V35, _M__sTextCons);
      { START(sink__V35, _M__sTextChars);
        COPY(sink__V35, sub__V37);END(sink__V35, _M__sTextChars); }
      { START(sink__V35, _M__sTextNil); END(sink__V35, _M__sTextNil); }
      END(sink__V35, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V35->context, namedP__V38); UNLINK_VariablePropertyLink(sink__V35->context, varP__V39);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DSTRING$1. */
int conBindOffs_M_DSTRING_s1[] = {0 , 0};
char *nameFun_M_DSTRING_s1(Term term) { return  "DSTRING$1" ; }
struct _ConstructionDescriptor descriptor_M_DSTRING_s1 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_DSTRING_s1), conBindOffs_M_DSTRING_s1, &nameFun_M_DSTRING_s1, &step_M_DSTRING_s1};

int step_M_DSTRING_s1(Sink sink__V40, Term term__V41)
{
  int term__V41_count = LINK_COUNT(term__V41); permitUnusedInt(term__V41_count);
  do {
    /* Contraction rule DEFS-DSTRING-1. */
    ASSERT(sink__V40->context, !strcmp(SYMBOL(term__V41),  "DSTRING$1" ));
    Term sub__V42 = LINK(sink__V40->context, SUB(term__V41, 0)); int sub__V42_count = term__V41_count*LINK_COUNT(sub__V42); permitUnusedInt(sub__V42_count);
    UNLINK_SUB(sink__V40->context, term__V41,  0); NORMALIZE(sink__V40->context, sub__V42); SUB(term__V41,  0) = LINK(sink__V40->context, sub__V42);
    /* sub__V42 = &#2 */
    NamedPropertyLink namedP__V43 = LINK_NamedPropertyLink(sink__V40->context, NAMED_PROPERTIES(term__V41));
    VariablePropertyLink varP__V44 = LINK_VariablePropertyLink(sink__V40->context, VARIABLE_PROPERTIES(term__V41));
    UNLINK(sink__V40->context, term__V41);
    { START(sink__V40, _M__sTextCons);
      { START(sink__V40, _M__sTextChars);
        LITERAL(sink__V40,  " " ); END(sink__V40, _M__sTextChars); }
      { START(sink__V40, _M__sTextCons);
        { START(sink__V40, _M__sTextString);
          { START(sink__V40, _M__sTextCons);
            { START(sink__V40, _M__sTextChars);
              { char *str__V45;
                FORCE(sink__V40->context, sub__V42);
                {str__V45 = makeEscaped(sink__V40->context, SYMBOL(sub__V42));
                  UNLINK(sink__V40->context, sub__V42);}
                LITERALU(sink__V40, str__V45); }
              END(sink__V40, _M__sTextChars); }
            { START(sink__V40, _M__sTextNil);
              END(sink__V40, _M__sTextNil); }
            END(sink__V40, _M__sTextCons); }
          END(sink__V40, _M__sTextString); }
        { START(sink__V40, _M__sTextCons);
          { START(sink__V40, _M__sTextChars);
            LITERAL(sink__V40,  " " ); END(sink__V40, _M__sTextChars); }
          { START(sink__V40, _M__sTextNil);
            END(sink__V40, _M__sTextNil); }
          END(sink__V40, _M__sTextCons); }
        END(sink__V40, _M__sTextCons); }
      END(sink__V40, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V40->context, namedP__V43); UNLINK_VariablePropertyLink(sink__V40->context, varP__V44);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION SplitMapText$1. */
int conBindOffs_M_SplitMapText_s1[] = {0 , 0 , 1 , 1 , 1 , 1 , 2 , 3};
char *nameFun_M_SplitMapText_s1(Term term) { return  "SplitMapText$1" ; }
struct _ConstructionDescriptor descriptor_M_SplitMapText_s1 = {&sort_M_Reified_xVariable, 0, 7, sizeof(STRUCT_Con_M_SplitMapText_s1), conBindOffs_M_SplitMapText_s1, &nameFun_M_SplitMapText_s1, &step_M_SplitMapText_s1};

int step_M_SplitMapText_s1(Sink sink__V46, Term term__V47)
{
  int term__V47_count = LINK_COUNT(term__V47); permitUnusedInt(term__V47_count);
  Term sub__V48 = FORCE(sink__V46->context, SUB(term__V47, 0));
  EnumOf_M__sList choice__V49 = (IS_VARIABLE_USE(sub__V48) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V48));
  switch (choice__V49)
  {
    case Data_M__sCons: { /* Function DEFS-SplitMapText-1$SplitMapText$1$$Cons case $Cons */
      ASSERT(sink__V46->context, !strcmp(SYMBOL(term__V47),  "SplitMapText$1" ));
      Term sub__V50 = SUB(term__V47, 0); permitUnusedTerm(sub__V50); int sub__V50_count = term__V47_count*LINK_COUNT(sub__V50); permitUnusedInt(sub__V50_count);
      ASSERT(sink__V46->context, !strcmp(SYMBOL(sub__V50),  "$Cons" ));
      Term sub__V51 = LINK(sink__V46->context, SUB(sub__V50, 0)); int sub__V51_count = sub__V50_count*LINK_COUNT(sub__V51); permitUnusedInt(sub__V51_count);
      /* sub__V51 = &#0-0 */
      Term sub__V52 = LINK(sink__V46->context, SUB(sub__V50, 1)); int sub__V52_count = sub__V50_count*LINK_COUNT(sub__V52); permitUnusedInt(sub__V52_count);
      /* sub__V52 = &#0-1 */
      Variable x__V53 = BINDER(term__V47,1,0); if (term__V47_count <= 1) UNBIND(x__V53);
      Term sub__V54 = LINK(sink__V46->context, SUB(term__V47, 1)); int sub__V54_count = term__V47_count*LINK_COUNT(sub__V54); permitUnusedInt(sub__V54_count);
      CRSX_CHECK_SORT(sink__V46->context, sub__V54, &sort_M_Reified_xVariable); /* sub__V54 = &#2 */
      Term sub__V55 = LINK(sink__V46->context, SUB(term__V47, 2)); int sub__V55_count = term__V47_count*LINK_COUNT(sub__V55); permitUnusedInt(sub__V55_count);
      /* sub__V55 = &#3 */
      Term sub__V56 = LINK(sink__V46->context, SUB(term__V47, 3)); int sub__V56_count = term__V47_count*LINK_COUNT(sub__V56); permitUnusedInt(sub__V56_count);
      /* sub__V56 = &#4 */
      Term sub__V57 = LINK(sink__V46->context, SUB(term__V47, 4)); int sub__V57_count = term__V47_count*LINK_COUNT(sub__V57); permitUnusedInt(sub__V57_count);
      /* sub__V57 = &#5 */
      Variable x__V58 = BINDER(term__V47,5,0); if (term__V47_count <= 1) UNBIND(x__V58);
      Term sub__V59 = LINK(sink__V46->context, SUB(term__V47, 5)); int sub__V59_count = term__V47_count*LINK_COUNT(sub__V59); permitUnusedInt(sub__V59_count);
      CRSX_CHECK_SORT(sink__V46->context, sub__V59, &sort_M_Reified_xVariable); /* sub__V59 = &#6 */
      Variable x__V60 = BINDER(term__V47,6,0); if (term__V47_count <= 1) UNBIND(x__V60);
      Term sub__V61 = LINK(sink__V46->context, SUB(term__V47, 6)); int sub__V61_count = term__V47_count*LINK_COUNT(sub__V61); permitUnusedInt(sub__V61_count);
      CRSX_CHECK_SORT(sink__V46->context, sub__V61, &sort_M_Reified_xVariable); /* sub__V61 = &#7 */
      NamedPropertyLink namedP__V62 = LINK_NamedPropertyLink(sink__V46->context, NAMED_PROPERTIES(term__V47));
      VariablePropertyLink varP__V63 = LINK_VariablePropertyLink(sink__V46->context, VARIABLE_PROPERTIES(term__V47));
      UNLINK(sink__V46->context, term__V47);
      ADD_PROPERTIES(sink__V46, LINK_NamedPropertyLink(sink__V46->context, namedP__V62), LINK_VariablePropertyLink(sink__V46->context, varP__V63));
      { START(sink__V46, _M_SplitMapText_s2);
        COPY(sink__V46, sub__V51);COPY(sink__V46, sub__V52);{ if (!IS_BOUND(x__V53)) { REBIND(x__V53);
            Variable binds__V64[1] = {x__V53}; BINDS(sink__V46, 1, binds__V64);
            COPY(sink__V46, sub__V54); /* REUSED SUBSTITUTION */  }
          else { Variable b__V65 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V46->context,"b__V65");
            Variable binds__V66[1] = {b__V65}; BINDS(sink__V46, 1, binds__V66);
            {
              Term arg__V67;
              { Sink buf__V68 = ALLOCA_BUFFER(sink__V46->context);
                USE(buf__V68, b__V65); arg__V67 = BUFFER_TERM(buf__V68); FREE_BUFFER(buf__V68); }
              Variable vars__V69[1] = {x__V53};
              Term args__V70[1] = {arg__V67};
              struct _SubstitutionFrame substitution__V71 = {NULL, 0, 1, vars__V69, args__V70, NULL};
              SUBSTITUTE(sink__V46, sub__V54, &substitution__V71); }
                }
           }
        COPY(sink__V46, sub__V55);COPY(sink__V46, sub__V56);COPY(sink__V46, sub__V57);{ if (!IS_BOUND(x__V58)) { REBIND(x__V58);
            Variable binds__V72[1] = {x__V58}; BINDS(sink__V46, 1, binds__V72);
            COPY(sink__V46, sub__V59); /* REUSED SUBSTITUTION */  }
          else { Variable b__V73 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V46->context,"b__V73");
            Variable binds__V74[1] = {b__V73}; BINDS(sink__V46, 1, binds__V74);
            {
              Term arg__V75;
              { Sink buf__V76 = ALLOCA_BUFFER(sink__V46->context);
                USE(buf__V76, b__V73); arg__V75 = BUFFER_TERM(buf__V76); FREE_BUFFER(buf__V76); }
              Variable vars__V77[1] = {x__V58};
              Term args__V78[1] = {arg__V75};
              struct _SubstitutionFrame substitution__V79 = {NULL, 0, 1, vars__V77, args__V78, NULL};
              SUBSTITUTE(sink__V46, sub__V59, &substitution__V79); }
                }
           }
        { if (!IS_BOUND(x__V60)) { REBIND(x__V60);
            Variable binds__V80[1] = {x__V60}; BINDS(sink__V46, 1, binds__V80);
            COPY(sink__V46, sub__V61); /* REUSED SUBSTITUTION */  }
          else { Variable b__V81 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V46->context,"b__V81");
            Variable binds__V82[1] = {b__V81}; BINDS(sink__V46, 1, binds__V82);
            {
              Term arg__V83;
              { Sink buf__V84 = ALLOCA_BUFFER(sink__V46->context);
                USE(buf__V84, b__V81); arg__V83 = BUFFER_TERM(buf__V84); FREE_BUFFER(buf__V84); }
              Variable vars__V85[1] = {x__V60};
              Term args__V86[1] = {arg__V83};
              struct _SubstitutionFrame substitution__V87 = {NULL, 0, 1, vars__V85, args__V86, NULL};
              SUBSTITUTE(sink__V46, sub__V61, &substitution__V87); }
                }
           }
        END(sink__V46, _M_SplitMapText_s2); }
      UNLINK_NamedPropertyLink(sink__V46->context, namedP__V62); UNLINK_VariablePropertyLink(sink__V46->context, varP__V63);
      
      return 1;
    break; } case Data_M__sNil: { /* Function DEFS-SplitMapText-2$SplitMapText$1$$Nil case $Nil */
      ASSERT(sink__V46->context, !strcmp(SYMBOL(term__V47),  "SplitMapText$1" ));
      Term sub__V88 = SUB(term__V47, 0); permitUnusedTerm(sub__V88); int sub__V88_count = term__V47_count*LINK_COUNT(sub__V88); permitUnusedInt(sub__V88_count);
      ASSERT(sink__V46->context, !strcmp(SYMBOL(sub__V88),  "$Nil" ));
      Variable x__V89 = BINDER(term__V47,1,0); if (term__V47_count <= 1) UNBIND(x__V89);
      Term sub__V90 = LINK(sink__V46->context, SUB(term__V47, 1)); int sub__V90_count = term__V47_count*LINK_COUNT(sub__V90); permitUnusedInt(sub__V90_count);
      CRSX_CHECK_SORT(sink__V46->context, sub__V90, &sort_M_Reified_xVariable); /* sub__V90 = &#0 */
      Term sub__V91 = LINK(sink__V46->context, SUB(term__V47, 2)); int sub__V91_count = term__V47_count*LINK_COUNT(sub__V91); permitUnusedInt(sub__V91_count);
      /* sub__V91 = &#1 */
      Term sub__V92 = LINK(sink__V46->context, SUB(term__V47, 3)); int sub__V92_count = term__V47_count*LINK_COUNT(sub__V92); permitUnusedInt(sub__V92_count);
      /* sub__V92 = &#2 */
      Term sub__V93 = LINK(sink__V46->context, SUB(term__V47, 4)); int sub__V93_count = term__V47_count*LINK_COUNT(sub__V93); permitUnusedInt(sub__V93_count);
      /* sub__V93 = &#3 */
      Variable x__V94 = BINDER(term__V47,5,0); if (term__V47_count <= 1) UNBIND(x__V94);
      Term sub__V95 = LINK(sink__V46->context, SUB(term__V47, 5)); int sub__V95_count = term__V47_count*LINK_COUNT(sub__V95); permitUnusedInt(sub__V95_count);
      CRSX_CHECK_SORT(sink__V46->context, sub__V95, &sort_M_Reified_xVariable); /* sub__V95 = &#4 */
      Variable x__V96 = BINDER(term__V47,6,0); if (term__V47_count <= 1) UNBIND(x__V96);
      Term sub__V97 = LINK(sink__V46->context, SUB(term__V47, 6)); int sub__V97_count = term__V47_count*LINK_COUNT(sub__V97); permitUnusedInt(sub__V97_count);
      CRSX_CHECK_SORT(sink__V46->context, sub__V97, &sort_M_Reified_xVariable); /* sub__V97 = &#5 */
      NamedPropertyLink namedP__V98 = LINK_NamedPropertyLink(sink__V46->context, NAMED_PROPERTIES(term__V47));
      VariablePropertyLink varP__V99 = LINK_VariablePropertyLink(sink__V46->context, VARIABLE_PROPERTIES(term__V47));
      UNLINK(sink__V46->context, term__V47);
      ADD_PROPERTIES(sink__V46, LINK_NamedPropertyLink(sink__V46->context, namedP__V98), LINK_VariablePropertyLink(sink__V46->context, varP__V99));
      { START(sink__V46, _M_SplitMapText_s3);
        { if (!IS_BOUND(x__V89)) { REBIND(x__V89);
            Variable binds__V100[1] = {x__V89}; BINDS(sink__V46, 1, binds__V100);
            COPY(sink__V46, sub__V90); /* REUSED SUBSTITUTION */  }
          else { Variable b__V101 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V46->context,"b__V101");
            Variable binds__V102[1] = {b__V101}; BINDS(sink__V46, 1, binds__V102);
            {
              Term arg__V103;
              { Sink buf__V104 = ALLOCA_BUFFER(sink__V46->context);
                USE(buf__V104, b__V101); arg__V103 = BUFFER_TERM(buf__V104); FREE_BUFFER(buf__V104); }
              Variable vars__V105[1] = {x__V89};
              Term args__V106[1] = {arg__V103};
              struct _SubstitutionFrame substitution__V107 = {NULL, 0, 1, vars__V105, args__V106, NULL};
              SUBSTITUTE(sink__V46, sub__V90, &substitution__V107); }
                }
           }
        COPY(sink__V46, sub__V91);COPY(sink__V46, sub__V92);COPY(sink__V46, sub__V93);{ if (!IS_BOUND(x__V94)) { REBIND(x__V94);
            Variable binds__V108[1] = {x__V94}; BINDS(sink__V46, 1, binds__V108);
            COPY(sink__V46, sub__V95); /* REUSED SUBSTITUTION */  }
          else { Variable b__V109 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V46->context,"b__V109");
            Variable binds__V110[1] = {b__V109}; BINDS(sink__V46, 1, binds__V110);
            {
              Term arg__V111;
              { Sink buf__V112 = ALLOCA_BUFFER(sink__V46->context);
                USE(buf__V112, b__V109); arg__V111 = BUFFER_TERM(buf__V112); FREE_BUFFER(buf__V112); }
              Variable vars__V113[1] = {x__V94};
              Term args__V114[1] = {arg__V111};
              struct _SubstitutionFrame substitution__V115 = {NULL, 0, 1, vars__V113, args__V114, NULL};
              SUBSTITUTE(sink__V46, sub__V95, &substitution__V115); }
                }
           }
        { if (!IS_BOUND(x__V96)) { REBIND(x__V96);
            Variable binds__V116[1] = {x__V96}; BINDS(sink__V46, 1, binds__V116);
            COPY(sink__V46, sub__V97); /* REUSED SUBSTITUTION */  }
          else { Variable b__V117 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V46->context,"b__V117");
            Variable binds__V118[1] = {b__V117}; BINDS(sink__V46, 1, binds__V118);
            {
              Term arg__V119;
              { Sink buf__V120 = ALLOCA_BUFFER(sink__V46->context);
                USE(buf__V120, b__V117); arg__V119 = BUFFER_TERM(buf__V120); FREE_BUFFER(buf__V120); }
              Variable vars__V121[1] = {x__V96};
              Term args__V122[1] = {arg__V119};
              struct _SubstitutionFrame substitution__V123 = {NULL, 0, 1, vars__V121, args__V122, NULL};
              SUBSTITUTE(sink__V46, sub__V97, &substitution__V123); }
                }
           }
        END(sink__V46, _M_SplitMapText_s3); }
      UNLINK_NamedPropertyLink(sink__V46->context, namedP__V98); UNLINK_VariablePropertyLink(sink__V46->context, varP__V99);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION SplitMapText$2. */
int conBindOffs_M_SplitMapText_s2[] = {0 , 0 , 0 , 1 , 1 , 1 , 1 , 2 , 3};
char *nameFun_M_SplitMapText_s2(Term term) { return  "SplitMapText$2" ; }
struct _ConstructionDescriptor descriptor_M_SplitMapText_s2 = {&sort_M_Reified_xVariable, 0, 8, sizeof(STRUCT_Con_M_SplitMapText_s2), conBindOffs_M_SplitMapText_s2, &nameFun_M_SplitMapText_s2, &step_M_SplitMapText_s2};

int step_M_SplitMapText_s2(Sink sink__V124, Term term__V125)
{
  int term__V125_count = LINK_COUNT(term__V125); permitUnusedInt(term__V125_count);
  do {
    /* Contraction rule DEFS-SplitMapText-1. */
    ASSERT(sink__V124->context, !strcmp(SYMBOL(term__V125),  "SplitMapText$2" ));
    Term sub__V126 = LINK(sink__V124->context, SUB(term__V125, 0)); int sub__V126_count = term__V125_count*LINK_COUNT(sub__V126); permitUnusedInt(sub__V126_count);
    /* sub__V126 = &#21 */
    Term sub__V127 = LINK(sink__V124->context, SUB(term__V125, 1)); int sub__V127_count = term__V125_count*LINK_COUNT(sub__V127); permitUnusedInt(sub__V127_count);
    /* sub__V127 = &#22 */
    Variable x__V128 = BINDER(term__V125,2,0); if (term__V125_count <= 1) UNBIND(x__V128);
    Term sub__V129 = LINK(sink__V124->context, SUB(term__V125, 2)); int sub__V129_count = term__V125_count*LINK_COUNT(sub__V129); permitUnusedInt(sub__V129_count);
    CRSX_CHECK_SORT(sink__V124->context, sub__V129, &sort_M_Reified_xVariable); UNLINK_SUB(sink__V124->context, term__V125,  2); NORMALIZE(sink__V124->context, sub__V129); SUB(term__V125,  2) = LINK(sink__V124->context, sub__V129);
    /* sub__V129 = &#1 */
    Term sub__V130 = LINK(sink__V124->context, SUB(term__V125, 3)); int sub__V130_count = term__V125_count*LINK_COUNT(sub__V130); permitUnusedInt(sub__V130_count);
    UNLINK_SUB(sink__V124->context, term__V125,  3); NORMALIZE(sink__V124->context, sub__V130); SUB(term__V125,  3) = LINK(sink__V124->context, sub__V130);
    /* sub__V130 = &#3 */
    Term sub__V131 = LINK(sink__V124->context, SUB(term__V125, 4)); int sub__V131_count = term__V125_count*LINK_COUNT(sub__V131); permitUnusedInt(sub__V131_count);
    UNLINK_SUB(sink__V124->context, term__V125,  4); NORMALIZE(sink__V124->context, sub__V131); SUB(term__V125,  4) = LINK(sink__V124->context, sub__V131);
    /* sub__V131 = &#4 */
    Term sub__V132 = LINK(sink__V124->context, SUB(term__V125, 5)); int sub__V132_count = term__V125_count*LINK_COUNT(sub__V132); permitUnusedInt(sub__V132_count);
    UNLINK_SUB(sink__V124->context, term__V125,  5); NORMALIZE(sink__V124->context, sub__V132); SUB(term__V125,  5) = LINK(sink__V124->context, sub__V132);
    /* sub__V132 = &#5 */
    Variable x__V133 = BINDER(term__V125,6,0); if (term__V125_count <= 1) UNBIND(x__V133);
    Term sub__V134 = LINK(sink__V124->context, SUB(term__V125, 6)); int sub__V134_count = term__V125_count*LINK_COUNT(sub__V134); permitUnusedInt(sub__V134_count);
    CRSX_CHECK_SORT(sink__V124->context, sub__V134, &sort_M_Reified_xVariable); UNLINK_SUB(sink__V124->context, term__V125,  6); NORMALIZE(sink__V124->context, sub__V134); SUB(term__V125,  6) = LINK(sink__V124->context, sub__V134);
    /* sub__V134 = &#6 */
    Variable x__V135 = BINDER(term__V125,7,0); if (term__V125_count <= 1) UNBIND(x__V135);
    Term sub__V136 = LINK(sink__V124->context, SUB(term__V125, 7)); int sub__V136_count = term__V125_count*LINK_COUNT(sub__V136); permitUnusedInt(sub__V136_count);
    CRSX_CHECK_SORT(sink__V124->context, sub__V136, &sort_M_Reified_xVariable); UNLINK_SUB(sink__V124->context, term__V125,  7); NORMALIZE(sink__V124->context, sub__V136); SUB(term__V125,  7) = LINK(sink__V124->context, sub__V136);
    /* sub__V136 = &#7 */
    NamedPropertyLink namedP__V137 = LINK_NamedPropertyLink(sink__V124->context, NAMED_PROPERTIES(term__V125));
    VariablePropertyLink varP__V138 = LINK_VariablePropertyLink(sink__V124->context, VARIABLE_PROPERTIES(term__V125));
    UNLINK(sink__V124->context, term__V125);
    { int test__V139;
      FORCE(sink__V124->context, sub__V130);
      test__V139 = (int) !strcmp(SYMBOL(sub__V130), "0" ); if (test__V139) {  UNLINK(sink__V124->context, sub__V130); { START(sink__V124, _M__sTextCons);
          { START(sink__V124, _M__sTextEmbed);
            { START(sink__V124, _M_AsText);
              {
                Term arg__V140;
                { Sink buf__V141 = ALLOCA_BUFFER(sink__V124->context);
                  COPY(buf__V141, LINK(buf__V141->context, sub__V131));arg__V140 = BUFFER_TERM(buf__V141); FREE_BUFFER(buf__V141); }
                Variable vars__V142[1] = {x__V133};
                Term args__V143[1] = {arg__V140};
                struct _SubstitutionFrame substitution__V144 = {NULL, 0, 1, vars__V142, args__V143, NULL};
                SUBSTITUTE(sink__V124, LINK(sink__V124->context,sub__V134), &substitution__V144); }
              END(sink__V124, _M_AsText); }
            END(sink__V124, _M__sTextEmbed); }
          { START(sink__V124, _M__sTextCons);
            { START(sink__V124, _M__sTextEmbed);
              { START(sink__V124, _M_AsText);
                {
                  Term arg__V145;
                  { Sink buf__V146 = ALLOCA_BUFFER(sink__V124->context);
                    COPY(buf__V146, sub__V126);arg__V145 = BUFFER_TERM(buf__V146); FREE_BUFFER(buf__V146); }
                  Variable vars__V147[1] = {x__V128};
                  Term args__V148[1] = {arg__V145};
                  struct _SubstitutionFrame substitution__V149 = {NULL, 0, 1, vars__V147, args__V148, NULL};
                  SUBSTITUTE(sink__V124, LINK(sink__V124->context,sub__V129), &substitution__V149); }
                END(sink__V124, _M_AsText); }
              END(sink__V124, _M__sTextEmbed); }
            { START(sink__V124, _M__sTextCons);
              { START(sink__V124, _M__sTextEmbed);
                { START(sink__V124, _M_AsText);
                  { START(sink__V124, _M_SplitMapText_s1);
                    COPY(sink__V124, sub__V127);{ Variable x__V150 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V124->context,"x__V150");
                      Variable binds__V151[1] = {x__V150}; BINDS(sink__V124, 1, binds__V151);
                      {
                        Term arg__V152;
                        { Sink buf__V153 = ALLOCA_BUFFER(sink__V124->context);
                          USE(buf__V153, x__V150); arg__V152 = BUFFER_TERM(buf__V153); FREE_BUFFER(buf__V153); }
                        Variable vars__V154[1] = {x__V128};
                        Term args__V155[1] = {arg__V152};
                        struct _SubstitutionFrame substitution__V156 = {NULL, 0, 1, vars__V154, args__V155, NULL};
                        SUBSTITUTE(sink__V124, sub__V129, &substitution__V156); }
                       }
                    LITERAL(sink__V124,  "1" ); COPY(sink__V124, sub__V131);COPY(sink__V124, sub__V132);{ Variable x__V157 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V124->context,"x__V157");
                      Variable binds__V158[1] = {x__V157}; BINDS(sink__V124, 1, binds__V158);
                      {
                        Term arg__V159;
                        { Sink buf__V160 = ALLOCA_BUFFER(sink__V124->context);
                          USE(buf__V160, x__V157); arg__V159 = BUFFER_TERM(buf__V160); FREE_BUFFER(buf__V160); }
                        Variable vars__V161[1] = {x__V133};
                        Term args__V162[1] = {arg__V159};
                        struct _SubstitutionFrame substitution__V163 = {NULL, 0, 1, vars__V161, args__V162, NULL};
                        SUBSTITUTE(sink__V124, sub__V134, &substitution__V163); }
                       }
                    { Variable x__V164 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V124->context,"x__V164");
                      Variable binds__V165[1] = {x__V164}; BINDS(sink__V124, 1, binds__V165);
                      {
                        Term arg__V166;
                        { Sink buf__V167 = ALLOCA_BUFFER(sink__V124->context);
                          USE(buf__V167, x__V164); arg__V166 = BUFFER_TERM(buf__V167); FREE_BUFFER(buf__V167); }
                        Variable vars__V168[1] = {x__V135};
                        Term args__V169[1] = {arg__V166};
                        struct _SubstitutionFrame substitution__V170 = {NULL, 0, 1, vars__V168, args__V169, NULL};
                        SUBSTITUTE(sink__V124, sub__V136, &substitution__V170); }
                       }
                    END(sink__V124, _M_SplitMapText_s1); }
                  END(sink__V124, _M_AsText); }
                END(sink__V124, _M__sTextEmbed); }
              { START(sink__V124, _M__sTextNil);
                END(sink__V124, _M__sTextNil); }
              END(sink__V124, _M__sTextCons); }
            END(sink__V124, _M__sTextCons); }
          END(sink__V124, _M__sTextCons); }
         }
      else { { int test__V171;
          FORCE(sink__V124->context, sub__V130);
          FORCE(sink__V124->context, sub__V132);
          test__V171 = (int) !strcmp(SYMBOL(sub__V130),SYMBOL(sub__V132));
          if (test__V171) {  UNLINK(sink__V124->context, sub__V130); { START(sink__V124, _M__sTextCons);
              { START(sink__V124, _M__sTextEmbed);
                { START(sink__V124, _M_AsText);
                  {
                    Term arg__V172;
                    { Sink buf__V173 = ALLOCA_BUFFER(sink__V124->context);
                      COPY(buf__V173, LINK(buf__V173->context, sub__V131));arg__V172 = BUFFER_TERM(buf__V173); FREE_BUFFER(buf__V173); }
                    Variable vars__V174[1] = {x__V135};
                    Term args__V175[1] = {arg__V172};
                    struct _SubstitutionFrame substitution__V176 = {NULL, 0, 1, vars__V174, args__V175, NULL};
                    SUBSTITUTE(sink__V124, LINK(sink__V124->context,sub__V136), &substitution__V176); }
                  END(sink__V124, _M_AsText); }
                END(sink__V124, _M__sTextEmbed); }
              { START(sink__V124, _M__sTextCons);
                { START(sink__V124, _M__sTextEmbed);
                  { START(sink__V124, _M_AsText);
                    { START(sink__V124, _M_SplitMapText_s1);
                      { START(sink__V124, _M__sCons);
                        COPY(sink__V124, sub__V126);COPY(sink__V124, sub__V127);END(sink__V124, _M__sCons); }
                      { Variable x__V177 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V124->context,"x__V177");
                        Variable binds__V178[1] = {x__V177}; BINDS(sink__V124, 1, binds__V178);
                        {
                          Term arg__V179;
                          { Sink buf__V180 = ALLOCA_BUFFER(sink__V124->context);
                            USE(buf__V180, x__V177); arg__V179 = BUFFER_TERM(buf__V180); FREE_BUFFER(buf__V180); }
                          Variable vars__V181[1] = {x__V128};
                          Term args__V182[1] = {arg__V179};
                          struct _SubstitutionFrame substitution__V183 = {NULL, 0, 1, vars__V181, args__V182, NULL};
                          SUBSTITUTE(sink__V124, sub__V129, &substitution__V183); }
                         }
                      LITERAL(sink__V124,  "0" ); { double num__V184;
                        num__V184 = DOUBLE(sub__V131); { double tmp__V185;
                          tmp__V185 = (double) 1; num__V184 += tmp__V185; }
                        LITERALNF(sink__V124, (size_t) 31, "%G", num__V184); }
                      COPY(sink__V124, sub__V132);{ Variable x__V186 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V124->context,"x__V186");
                        Variable binds__V187[1] = {x__V186}; BINDS(sink__V124, 1, binds__V187);
                        {
                          Term arg__V188;
                          { Sink buf__V189 = ALLOCA_BUFFER(sink__V124->context);
                            USE(buf__V189, x__V186); arg__V188 = BUFFER_TERM(buf__V189); FREE_BUFFER(buf__V189); }
                          Variable vars__V190[1] = {x__V133};
                          Term args__V191[1] = {arg__V188};
                          struct _SubstitutionFrame substitution__V192 = {NULL, 0, 1, vars__V190, args__V191, NULL};
                          SUBSTITUTE(sink__V124, sub__V134, &substitution__V192); }
                         }
                      { Variable x__V193 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V124->context,"x__V193");
                        Variable binds__V194[1] = {x__V193}; BINDS(sink__V124, 1, binds__V194);
                        {
                          Term arg__V195;
                          { Sink buf__V196 = ALLOCA_BUFFER(sink__V124->context);
                            USE(buf__V196, x__V193); arg__V195 = BUFFER_TERM(buf__V196); FREE_BUFFER(buf__V196); }
                          Variable vars__V197[1] = {x__V135};
                          Term args__V198[1] = {arg__V195};
                          struct _SubstitutionFrame substitution__V199 = {NULL, 0, 1, vars__V197, args__V198, NULL};
                          SUBSTITUTE(sink__V124, sub__V136, &substitution__V199); }
                         }
                      END(sink__V124, _M_SplitMapText_s1); }
                    END(sink__V124, _M_AsText); }
                  END(sink__V124, _M__sTextEmbed); }
                { START(sink__V124, _M__sTextNil);
                  END(sink__V124, _M__sTextNil); }
                END(sink__V124, _M__sTextCons); }
              END(sink__V124, _M__sTextCons); }
             }
          else { { START(sink__V124, _M__sTextCons);
              { START(sink__V124, _M__sTextEmbed);
                { START(sink__V124, _M_AsText);
                  {
                    Term arg__V200;
                    { Sink buf__V201 = ALLOCA_BUFFER(sink__V124->context);
                      COPY(buf__V201, sub__V126);arg__V200 = BUFFER_TERM(buf__V201); FREE_BUFFER(buf__V201); }
                    Variable vars__V202[1] = {x__V128};
                    Term args__V203[1] = {arg__V200};
                    struct _SubstitutionFrame substitution__V204 = {NULL, 0, 1, vars__V202, args__V203, NULL};
                    SUBSTITUTE(sink__V124, LINK(sink__V124->context,sub__V129), &substitution__V204); }
                  END(sink__V124, _M_AsText); }
                END(sink__V124, _M__sTextEmbed); }
              { START(sink__V124, _M__sTextCons);
                { START(sink__V124, _M__sTextEmbed);
                  { START(sink__V124, _M_AsText);
                    { START(sink__V124, _M_SplitMapText_s1);
                      COPY(sink__V124, sub__V127);{ Variable x__V205 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V124->context,"x__V205");
                        Variable binds__V206[1] = {x__V205}; BINDS(sink__V124, 1, binds__V206);
                        {
                          Term arg__V207;
                          { Sink buf__V208 = ALLOCA_BUFFER(sink__V124->context);
                            USE(buf__V208, x__V205); arg__V207 = BUFFER_TERM(buf__V208); FREE_BUFFER(buf__V208); }
                          Variable vars__V209[1] = {x__V128};
                          Term args__V210[1] = {arg__V207};
                          struct _SubstitutionFrame substitution__V211 = {NULL, 0, 1, vars__V209, args__V210, NULL};
                          SUBSTITUTE(sink__V124, sub__V129, &substitution__V211); }
                         }
                      { double num__V212;
                        num__V212 = DOUBLE(sub__V130); { double tmp__V213;
                          tmp__V213 = (double) 1; num__V212 += tmp__V213; }
                        LITERALNF(sink__V124, (size_t) 31, "%G", num__V212); }
                      COPY(sink__V124, sub__V131);COPY(sink__V124, sub__V132);{ Variable x__V214 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V124->context,"x__V214");
                        Variable binds__V215[1] = {x__V214}; BINDS(sink__V124, 1, binds__V215);
                        {
                          Term arg__V216;
                          { Sink buf__V217 = ALLOCA_BUFFER(sink__V124->context);
                            USE(buf__V217, x__V214); arg__V216 = BUFFER_TERM(buf__V217); FREE_BUFFER(buf__V217); }
                          Variable vars__V218[1] = {x__V133};
                          Term args__V219[1] = {arg__V216};
                          struct _SubstitutionFrame substitution__V220 = {NULL, 0, 1, vars__V218, args__V219, NULL};
                          SUBSTITUTE(sink__V124, sub__V134, &substitution__V220); }
                         }
                      { Variable x__V221 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V124->context,"x__V221");
                        Variable binds__V222[1] = {x__V221}; BINDS(sink__V124, 1, binds__V222);
                        {
                          Term arg__V223;
                          { Sink buf__V224 = ALLOCA_BUFFER(sink__V124->context);
                            USE(buf__V224, x__V221); arg__V223 = BUFFER_TERM(buf__V224); FREE_BUFFER(buf__V224); }
                          Variable vars__V225[1] = {x__V135};
                          Term args__V226[1] = {arg__V223};
                          struct _SubstitutionFrame substitution__V227 = {NULL, 0, 1, vars__V225, args__V226, NULL};
                          SUBSTITUTE(sink__V124, sub__V136, &substitution__V227); }
                         }
                      END(sink__V124, _M_SplitMapText_s1); }
                    END(sink__V124, _M_AsText); }
                  END(sink__V124, _M__sTextEmbed); }
                { START(sink__V124, _M__sTextNil);
                  END(sink__V124, _M__sTextNil); }
                END(sink__V124, _M__sTextCons); }
              END(sink__V124, _M__sTextCons); }
             }
        }
         }
    }
    UNLINK_NamedPropertyLink(sink__V124->context, namedP__V137); UNLINK_VariablePropertyLink(sink__V124->context, varP__V138);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION SplitMapText$3. */
int conBindOffs_M_SplitMapText_s3[] = {0 , 1 , 1 , 1 , 1 , 2 , 3};
char *nameFun_M_SplitMapText_s3(Term term) { return  "SplitMapText$3" ; }
struct _ConstructionDescriptor descriptor_M_SplitMapText_s3 = {&sort_M_Reified_xVariable, 0, 6, sizeof(STRUCT_Con_M_SplitMapText_s3), conBindOffs_M_SplitMapText_s3, &nameFun_M_SplitMapText_s3, &step_M_SplitMapText_s3};

int step_M_SplitMapText_s3(Sink sink__V228, Term term__V229)
{
  int term__V229_count = LINK_COUNT(term__V229); permitUnusedInt(term__V229_count);
  do {
    /* Contraction rule DEFS-SplitMapText-2. */
    ASSERT(sink__V228->context, !strcmp(SYMBOL(term__V229),  "SplitMapText$3" ));
    Variable x__V230 = BINDER(term__V229,0,0); if (term__V229_count <= 1) UNBIND(x__V230);
    Term sub__V231 = SUB(term__V229, 0); permitUnusedTerm(sub__V231); int sub__V231_count = term__V229_count*LINK_COUNT(sub__V231); permitUnusedInt(sub__V231_count);
    CRSX_CHECK_SORT(sink__V228->context, sub__V231, &sort_M_Reified_xVariable); /* sub__V231 = &#1 */
    Term sub__V232 = SUB(term__V229, 1); permitUnusedTerm(sub__V232); int sub__V232_count = term__V229_count*LINK_COUNT(sub__V232); permitUnusedInt(sub__V232_count);
    /* sub__V232 = &#3 */
    Term sub__V233 = LINK(sink__V228->context, SUB(term__V229, 2)); int sub__V233_count = term__V229_count*LINK_COUNT(sub__V233); permitUnusedInt(sub__V233_count);
    UNLINK_SUB(sink__V228->context, term__V229,  2); NORMALIZE(sink__V228->context, sub__V233); SUB(term__V229,  2) = LINK(sink__V228->context, sub__V233);
    /* sub__V233 = &#4 */
    Term sub__V234 = SUB(term__V229, 3); permitUnusedTerm(sub__V234); int sub__V234_count = term__V229_count*LINK_COUNT(sub__V234); permitUnusedInt(sub__V234_count);
    /* sub__V234 = &#5 */
    Variable x__V235 = BINDER(term__V229,4,0); if (term__V229_count <= 1) UNBIND(x__V235);
    Term sub__V236 = SUB(term__V229, 4); permitUnusedTerm(sub__V236); int sub__V236_count = term__V229_count*LINK_COUNT(sub__V236); permitUnusedInt(sub__V236_count);
    CRSX_CHECK_SORT(sink__V228->context, sub__V236, &sort_M_Reified_xVariable); /* sub__V236 = &#6 */
    Variable x__V237 = BINDER(term__V229,5,0); if (term__V229_count <= 1) UNBIND(x__V237);
    Term sub__V238 = LINK(sink__V228->context, SUB(term__V229, 5)); int sub__V238_count = term__V229_count*LINK_COUNT(sub__V238); permitUnusedInt(sub__V238_count);
    CRSX_CHECK_SORT(sink__V228->context, sub__V238, &sort_M_Reified_xVariable); /* sub__V238 = &#7 */
    NamedPropertyLink namedP__V239 = LINK_NamedPropertyLink(sink__V228->context, NAMED_PROPERTIES(term__V229));
    VariablePropertyLink varP__V240 = LINK_VariablePropertyLink(sink__V228->context, VARIABLE_PROPERTIES(term__V229));
    UNLINK(sink__V228->context, term__V229);
    {
      Term arg__V241;
      { Sink buf__V242 = ALLOCA_BUFFER(sink__V228->context);
        COPY(buf__V242, sub__V233);arg__V241 = BUFFER_TERM(buf__V242); FREE_BUFFER(buf__V242); }
      Variable vars__V243[1] = {x__V237};
      Term args__V244[1] = {arg__V241};
      struct _SubstitutionFrame substitution__V245 = {NULL, 0, 1, vars__V243, args__V244, NULL};
      SUBSTITUTE(sink__V228, sub__V238, &substitution__V245); }
    UNLINK_NamedPropertyLink(sink__V228->context, namedP__V239); UNLINK_VariablePropertyLink(sink__V228->context, varP__V240);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DINTEGER. */
int conBindOffs_M_DINTEGER[] = {0 , 0 , 0};
char *nameFun_M_DINTEGER(Term term) { return  "DINTEGER" ; }
struct _ConstructionDescriptor descriptor_M_DINTEGER = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_DINTEGER), conBindOffs_M_DINTEGER, &nameFun_M_DINTEGER, &step_M_DINTEGER};

int step_M_DINTEGER(Sink sink__V246, Term term__V247)
{
  int term__V247_count = LINK_COUNT(term__V247); permitUnusedInt(term__V247_count);
  Term sub__V248 = FORCE(sink__V246->context, SUB(term__V247, 0));
  EnumOf_M_OK_xSORT choice__V249 = (IS_VARIABLE_USE(sub__V248) ? VarOf_M_OK_xSORT : (EnumOf_M_OK_xSORT) TAG(sub__V248));
  switch (choice__V249)
  {
    case Data_M_OK: { /* Function DEFS-DINTEGER-1$DINTEGER$OK case OK */
      ASSERT(sink__V246->context, !strcmp(SYMBOL(term__V247),  "DINTEGER" ));
      Term sub__V250 = SUB(term__V247, 0); permitUnusedTerm(sub__V250); int sub__V250_count = term__V247_count*LINK_COUNT(sub__V250); permitUnusedInt(sub__V250_count);
      CRSX_CHECK_SORT(sink__V246->context, sub__V250, &sort_M_OK_xSORT); ASSERT(sink__V246->context, !strcmp(SYMBOL(sub__V250),  "OK" ));
      Term sub__V251 = LINK(sink__V246->context, SUB(term__V247, 1)); int sub__V251_count = term__V247_count*LINK_COUNT(sub__V251); permitUnusedInt(sub__V251_count);
      /* sub__V251 = &#0 */
      NamedPropertyLink namedP__V252 = LINK_NamedPropertyLink(sink__V246->context, NAMED_PROPERTIES(term__V247));
      VariablePropertyLink varP__V253 = LINK_VariablePropertyLink(sink__V246->context, VARIABLE_PROPERTIES(term__V247));
      UNLINK(sink__V246->context, term__V247);
      ADD_PROPERTIES(sink__V246, LINK_NamedPropertyLink(sink__V246->context, namedP__V252), LINK_VariablePropertyLink(sink__V246->context, varP__V253));
      { START(sink__V246, _M_DINTEGER_s1);
        COPY(sink__V246, sub__V251);END(sink__V246, _M_DINTEGER_s1); }
      UNLINK_NamedPropertyLink(sink__V246->context, namedP__V252); UNLINK_VariablePropertyLink(sink__V246->context, varP__V253);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION Step. */
int conBindOffs_M_Step[] = {0 , 0};
char *nameFun_M_Step(Term term) { return  "Step" ; }
struct _ConstructionDescriptor descriptor_M_Step = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_Step), conBindOffs_M_Step, &nameFun_M_Step, &step_M_Step};

int step_M_Step(Sink sink__V254, Term term__V255)
{
  int term__V255_count = LINK_COUNT(term__V255); permitUnusedInt(term__V255_count);
  do {
    /* Contraction rule DEFS-Step-1. */
    ASSERT(sink__V254->context, !strcmp(SYMBOL(term__V255),  "Step" ));
    Term sub__V256 = LINK(sink__V254->context, SUB(term__V255, 0)); int sub__V256_count = term__V255_count*LINK_COUNT(sub__V256); permitUnusedInt(sub__V256_count);
    /* sub__V256 = &#1 */
    NamedPropertyLink namedP__V257 = LINK_NamedPropertyLink(sink__V254->context, NAMED_PROPERTIES(term__V255));
    VariablePropertyLink varP__V258 = LINK_VariablePropertyLink(sink__V254->context, VARIABLE_PROPERTIES(term__V255));
    UNLINK(sink__V254->context, term__V255);
    { START(sink__V254, _M__sTextCons);
      { START(sink__V254, _M__sTextChars);
        LITERAL(sink__V254,  "step" ); END(sink__V254, _M__sTextChars); }
      { START(sink__V254, _M__sTextCons);
        { START(sink__V254, _M__sTextEmbed);
          { START(sink__V254, _M_AsText);
            { START(sink__V254, _M_MANGLE);
              COPY(sink__V254, sub__V256);END(sink__V254, _M_MANGLE); }
            END(sink__V254, _M_AsText); }
          END(sink__V254, _M__sTextEmbed); }
        { START(sink__V254, _M__sTextNil);
          END(sink__V254, _M__sTextNil); }
        END(sink__V254, _M__sTextCons); }
      END(sink__V254, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V254->context, namedP__V257); UNLINK_VariablePropertyLink(sink__V254->context, varP__V258);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DMANGLE. */
int conBindOffs_M_DMANGLE[] = {0 , 0 , 0};
char *nameFun_M_DMANGLE(Term term) { return  "DMANGLE" ; }
struct _ConstructionDescriptor descriptor_M_DMANGLE = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_DMANGLE), conBindOffs_M_DMANGLE, &nameFun_M_DMANGLE, &step_M_DMANGLE};

int step_M_DMANGLE(Sink sink__V259, Term term__V260)
{
  int term__V260_count = LINK_COUNT(term__V260); permitUnusedInt(term__V260_count);
  Term sub__V261 = FORCE(sink__V259->context, SUB(term__V260, 0));
  EnumOf_M_OK_xSORT choice__V262 = (IS_VARIABLE_USE(sub__V261) ? VarOf_M_OK_xSORT : (EnumOf_M_OK_xSORT) TAG(sub__V261));
  switch (choice__V262)
  {
    case Data_M_OK: { /* Function DEFS-DMANGLE-1$DMANGLE$OK case OK */
      ASSERT(sink__V259->context, !strcmp(SYMBOL(term__V260),  "DMANGLE" ));
      Term sub__V263 = SUB(term__V260, 0); permitUnusedTerm(sub__V263); int sub__V263_count = term__V260_count*LINK_COUNT(sub__V263); permitUnusedInt(sub__V263_count);
      CRSX_CHECK_SORT(sink__V259->context, sub__V263, &sort_M_OK_xSORT); ASSERT(sink__V259->context, !strcmp(SYMBOL(sub__V263),  "OK" ));
      Term sub__V264 = LINK(sink__V259->context, SUB(term__V260, 1)); int sub__V264_count = term__V260_count*LINK_COUNT(sub__V264); permitUnusedInt(sub__V264_count);
      /* sub__V264 = &#0 */
      NamedPropertyLink namedP__V265 = LINK_NamedPropertyLink(sink__V259->context, NAMED_PROPERTIES(term__V260));
      VariablePropertyLink varP__V266 = LINK_VariablePropertyLink(sink__V259->context, VARIABLE_PROPERTIES(term__V260));
      UNLINK(sink__V259->context, term__V260);
      ADD_PROPERTIES(sink__V259, LINK_NamedPropertyLink(sink__V259->context, namedP__V265), LINK_VariablePropertyLink(sink__V259->context, varP__V266));
      { START(sink__V259, _M_DMANGLE_s1);
        COPY(sink__V259, sub__V264);END(sink__V259, _M_DMANGLE_s1); }
      UNLINK_NamedPropertyLink(sink__V259->context, namedP__V265); UNLINK_VariablePropertyLink(sink__V259->context, varP__V266);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION UnString. */
int conBindOffs_M_UnString[] = {0 , 0};
char *nameFun_M_UnString(Term term) { return  "UnString" ; }
struct _ConstructionDescriptor descriptor_M_UnString = {NULL, 0, 1, sizeof(STRUCT_Con_M_UnString), conBindOffs_M_UnString, &nameFun_M_UnString, &step_M_UnString};

int step_M_UnString(Sink sink__V267, Term term__V268)
{
  int term__V268_count = LINK_COUNT(term__V268); permitUnusedInt(term__V268_count);
  Term sub__V269 = FORCE(sink__V267->context, SUB(term__V268, 0));
  EnumOf_M_STRING_xENTRY choice__V270 = (IS_VARIABLE_USE(sub__V269) ? VarOf_M_STRING_xENTRY : (EnumOf_M_STRING_xENTRY) TAG(sub__V269));
  switch (choice__V270)
  {
    case Data_M_STRING_xVALUE: { /* Function DEFS-UnString-1$UnString$STRING_VALUE case STRING_VALUE */
      ASSERT(sink__V267->context, !strcmp(SYMBOL(term__V268),  "UnString" ));
      Term sub__V271 = SUB(term__V268, 0); permitUnusedTerm(sub__V271); int sub__V271_count = term__V268_count*LINK_COUNT(sub__V271); permitUnusedInt(sub__V271_count);
      CRSX_CHECK_SORT(sink__V267->context, sub__V271, &sort_M_STRING_xENTRY); ASSERT(sink__V267->context, !strcmp(SYMBOL(sub__V271),  "STRING_VALUE" ));
      Term sub__V272 = LINK(sink__V267->context, SUB(sub__V271, 0)); int sub__V272_count = sub__V271_count*LINK_COUNT(sub__V272); permitUnusedInt(sub__V272_count);
      /* sub__V272 = &#0-0 */
      NamedPropertyLink namedP__V273 = LINK_NamedPropertyLink(sink__V267->context, NAMED_PROPERTIES(term__V268));
      VariablePropertyLink varP__V274 = LINK_VariablePropertyLink(sink__V267->context, VARIABLE_PROPERTIES(term__V268));
      UNLINK(sink__V267->context, term__V268);
      ADD_PROPERTIES(sink__V267, LINK_NamedPropertyLink(sink__V267->context, namedP__V273), LINK_VariablePropertyLink(sink__V267->context, varP__V274));
      { START(sink__V267, _M_UnString_s1);
        COPY(sink__V267, sub__V272);END(sink__V267, _M_UnString_s1); }
      UNLINK_NamedPropertyLink(sink__V267->context, namedP__V273); UNLINK_VariablePropertyLink(sink__V267->context, varP__V274);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION FormArguments-binder-count. */
int conBindOffs_M_FormArguments__binder__count[] = {0 , 0 , 0};
char *nameFun_M_FormArguments__binder__count(Term term) { return  "FormArguments-binder-count" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__count = {NULL, 0, 2, sizeof(STRUCT_Con_M_FormArguments__binder__count), conBindOffs_M_FormArguments__binder__count, &nameFun_M_FormArguments__binder__count, &step_M_FormArguments__binder__count};

int step_M_FormArguments__binder__count(Sink sink__V275, Term term__V276)
{
  int term__V276_count = LINK_COUNT(term__V276); permitUnusedInt(term__V276_count);
  Term sub__V277 = FORCE(sink__V275->context, SUB(term__V276, 0));
  EnumOf_M__sList choice__V278 = (IS_VARIABLE_USE(sub__V277) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V277));
  switch (choice__V278)
  {
    case Data_M__sCons: { /* Function DEFS-FormArguments-binder-count-2$FormArguments-binder-count$$Cons case $Cons */
      ASSERT(sink__V275->context, !strcmp(SYMBOL(term__V276),  "FormArguments-binder-count" ));
      Term sub__V279 = SUB(term__V276, 0); permitUnusedTerm(sub__V279); int sub__V279_count = term__V276_count*LINK_COUNT(sub__V279); permitUnusedInt(sub__V279_count);
      ASSERT(sink__V275->context, !strcmp(SYMBOL(sub__V279),  "$Cons" ));
      Term sub__V280 = LINK(sink__V275->context, SUB(sub__V279, 0)); int sub__V280_count = sub__V279_count*LINK_COUNT(sub__V280); permitUnusedInt(sub__V280_count);
      /* sub__V280 = &#0-0 */
      Term sub__V281 = LINK(sink__V275->context, SUB(sub__V279, 1)); int sub__V281_count = sub__V279_count*LINK_COUNT(sub__V281); permitUnusedInt(sub__V281_count);
      /* sub__V281 = &#0-1 */
      Term sub__V282 = LINK(sink__V275->context, SUB(term__V276, 1)); int sub__V282_count = term__V276_count*LINK_COUNT(sub__V282); permitUnusedInt(sub__V282_count);
      /* sub__V282 = &#2 */
      NamedPropertyLink namedP__V283 = LINK_NamedPropertyLink(sink__V275->context, NAMED_PROPERTIES(term__V276));
      VariablePropertyLink varP__V284 = LINK_VariablePropertyLink(sink__V275->context, VARIABLE_PROPERTIES(term__V276));
      UNLINK(sink__V275->context, term__V276);
      ADD_PROPERTIES(sink__V275, LINK_NamedPropertyLink(sink__V275->context, namedP__V283), LINK_VariablePropertyLink(sink__V275->context, varP__V284));
      { START(sink__V275, _M_FormArguments__binder__count_s1);
        COPY(sink__V275, sub__V280);COPY(sink__V275, sub__V281);COPY(sink__V275, sub__V282);END(sink__V275, _M_FormArguments__binder__count_s1); }
      UNLINK_NamedPropertyLink(sink__V275->context, namedP__V283); UNLINK_VariablePropertyLink(sink__V275->context, varP__V284);
      
      return 1;
    break; } case Data_M__sNil: { /* Function DEFS-FormArguments-binder-count-3$FormArguments-binder-count$$Nil case $Nil */
      ASSERT(sink__V275->context, !strcmp(SYMBOL(term__V276),  "FormArguments-binder-count" ));
      Term sub__V285 = SUB(term__V276, 0); permitUnusedTerm(sub__V285); int sub__V285_count = term__V276_count*LINK_COUNT(sub__V285); permitUnusedInt(sub__V285_count);
      ASSERT(sink__V275->context, !strcmp(SYMBOL(sub__V285),  "$Nil" ));
      Term sub__V286 = LINK(sink__V275->context, SUB(term__V276, 1)); int sub__V286_count = term__V276_count*LINK_COUNT(sub__V286); permitUnusedInt(sub__V286_count);
      /* sub__V286 = &#0 */
      NamedPropertyLink namedP__V287 = LINK_NamedPropertyLink(sink__V275->context, NAMED_PROPERTIES(term__V276));
      VariablePropertyLink varP__V288 = LINK_VariablePropertyLink(sink__V275->context, VARIABLE_PROPERTIES(term__V276));
      UNLINK(sink__V275->context, term__V276);
      ADD_PROPERTIES(sink__V275, LINK_NamedPropertyLink(sink__V275->context, namedP__V287), LINK_VariablePropertyLink(sink__V275->context, varP__V288));
      { START(sink__V275, _M_FormArguments__binder__count_s4);
        COPY(sink__V275, sub__V286);END(sink__V275, _M_FormArguments__binder__count_s4); }
      UNLINK_NamedPropertyLink(sink__V275->context, namedP__V287); UNLINK_VariablePropertyLink(sink__V275->context, varP__V288);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION DMANGLE$1. */
int conBindOffs_M_DMANGLE_s1[] = {0 , 0};
char *nameFun_M_DMANGLE_s1(Term term) { return  "DMANGLE$1" ; }
struct _ConstructionDescriptor descriptor_M_DMANGLE_s1 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_DMANGLE_s1), conBindOffs_M_DMANGLE_s1, &nameFun_M_DMANGLE_s1, &step_M_DMANGLE_s1};

int step_M_DMANGLE_s1(Sink sink__V289, Term term__V290)
{
  int term__V290_count = LINK_COUNT(term__V290); permitUnusedInt(term__V290_count);
  do {
    /* Contraction rule DEFS-DMANGLE-1. */
    ASSERT(sink__V289->context, !strcmp(SYMBOL(term__V290),  "DMANGLE$1" ));
    Term sub__V291 = LINK(sink__V289->context, SUB(term__V290, 0)); int sub__V291_count = term__V290_count*LINK_COUNT(sub__V291); permitUnusedInt(sub__V291_count);
    UNLINK_SUB(sink__V289->context, term__V290,  0); NORMALIZE(sink__V289->context, sub__V291); SUB(term__V290,  0) = LINK(sink__V289->context, sub__V291);
    /* sub__V291 = &#2 */
    NamedPropertyLink namedP__V292 = LINK_NamedPropertyLink(sink__V289->context, NAMED_PROPERTIES(term__V290));
    VariablePropertyLink varP__V293 = LINK_VariablePropertyLink(sink__V289->context, VARIABLE_PROPERTIES(term__V290));
    UNLINK(sink__V289->context, term__V290);
    { START(sink__V289, _M__sTextCons);
      { START(sink__V289, _M__sTextChars);
        { char *str__V294;
          FORCE(sink__V289->context, sub__V291);
          { char *s__V295 = makeMangled(sink__V289->context, SYMBOL(sub__V291));
            { size_t z__V296 = strlen(s__V295) + 1; memcpy(str__V294 = ALLOCATE(sink__V289->context, z__V296), s__V295, z__V296);  UNLINK(sink__V289->context, sub__V291);}
            }
          LITERALU(sink__V289, str__V294); }
        END(sink__V289, _M__sTextChars); }
      { START(sink__V289, _M__sTextNil);
        END(sink__V289, _M__sTextNil); }
      END(sink__V289, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V289->context, namedP__V292); UNLINK_VariablePropertyLink(sink__V289->context, varP__V293);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION INTEGER. */
int conBindOffs_M_INTEGER[] = {0 , 0};
char *nameFun_M_INTEGER(Term term) { return  "INTEGER" ; }
struct _ConstructionDescriptor descriptor_M_INTEGER = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_INTEGER), conBindOffs_M_INTEGER, &nameFun_M_INTEGER, &step_M_INTEGER};

int step_M_INTEGER(Sink sink__V297, Term term__V298)
{
  int term__V298_count = LINK_COUNT(term__V298); permitUnusedInt(term__V298_count);
  do {
    /* Contraction rule DEFS-INTEGER-1. */
    ASSERT(sink__V297->context, !strcmp(SYMBOL(term__V298),  "INTEGER" ));
    Term sub__V299 = LINK(sink__V297->context, SUB(term__V298, 0)); int sub__V299_count = term__V298_count*LINK_COUNT(sub__V299); permitUnusedInt(sub__V299_count);
    UNLINK_SUB(sink__V297->context, term__V298,  0); NORMALIZE(sink__V297->context, sub__V299); SUB(term__V298,  0) = LINK(sink__V297->context, sub__V299);
    /* sub__V299 = &#1 */
    NamedPropertyLink namedP__V300 = LINK_NamedPropertyLink(sink__V297->context, NAMED_PROPERTIES(term__V298));
    VariablePropertyLink varP__V301 = LINK_VariablePropertyLink(sink__V297->context, VARIABLE_PROPERTIES(term__V298));
    UNLINK(sink__V297->context, term__V298);
    { START(sink__V297, _M__sTextCons);
      { START(sink__V297, _M__sTextChars);
        { char *str__V302;
          {double num__V303; char *str__V304;
            num__V303 = DOUBLE(sub__V299); snprintf(str__V304 = ALLOCA(sink__V297->context, (size_t) 32), (size_t) 31, "%G", num__V303);
            { size_t z__V305 = strlen(str__V304) + 1; memcpy(str__V302 = ALLOCATE(sink__V297->context, z__V305), str__V304, z__V305); }
             }
          LITERALU(sink__V297, str__V302); }
        END(sink__V297, _M__sTextChars); }
      { START(sink__V297, _M__sTextNil);
        END(sink__V297, _M__sTextNil); }
      END(sink__V297, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V297->context, namedP__V300); UNLINK_VariablePropertyLink(sink__V297->context, varP__V301);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION MetaVar2$1. */
int conBindOffs_M_MetaVar2_s1[] = {0 , 0};
char *nameFun_M_MetaVar2_s1(Term term) { return  "MetaVar2$1" ; }
struct _ConstructionDescriptor descriptor_M_MetaVar2_s1 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_MetaVar2_s1), conBindOffs_M_MetaVar2_s1, &nameFun_M_MetaVar2_s1, &step_M_MetaVar2_s1};

int step_M_MetaVar2_s1(Sink sink__V306, Term term__V307)
{
  int term__V307_count = LINK_COUNT(term__V307); permitUnusedInt(term__V307_count);
  do {
    /* Contraction rule DEFS-MetaVar2-2. */
    ASSERT(sink__V306->context, !strcmp(SYMBOL(term__V307),  "MetaVar2$1" ));
    Term sub__V308 = LINK(sink__V306->context, SUB(term__V307, 0)); int sub__V308_count = term__V307_count*LINK_COUNT(sub__V308); permitUnusedInt(sub__V308_count);
    /* sub__V308 = &#11 */
    NamedPropertyLink namedP__V309 = LINK_NamedPropertyLink(sink__V306->context, NAMED_PROPERTIES(term__V307));
    VariablePropertyLink varP__V310 = LINK_VariablePropertyLink(sink__V306->context, VARIABLE_PROPERTIES(term__V307));
    UNLINK(sink__V306->context, term__V307);
    { START(sink__V306, _M_TOKEN);
      COPY(sink__V306, sub__V308);END(sink__V306, _M_TOKEN); }
    UNLINK_NamedPropertyLink(sink__V306->context, namedP__V309); UNLINK_VariablePropertyLink(sink__V306->context, varP__V310);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION MetaVar2$2. */
int conBindOffs_M_MetaVar2_s2[] = {0 , 0};
char *nameFun_M_MetaVar2_s2(Term term) { return  "MetaVar2$2" ; }
struct _ConstructionDescriptor descriptor_M_MetaVar2_s2 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_MetaVar2_s2), conBindOffs_M_MetaVar2_s2, &nameFun_M_MetaVar2_s2, &step_M_MetaVar2_s2};

int step_M_MetaVar2_s2(Sink sink__V311, Term term__V312)
{
  int term__V312_count = LINK_COUNT(term__V312); permitUnusedInt(term__V312_count);
  Term sub__V313 = FORCE(sink__V311->context, SUB(term__V312, 0));
  EnumOf_M_Reified_xVariable choice__V314 = (IS_VARIABLE_USE(sub__V313) ? VarOf_M_Reified_xVariable : (EnumOf_M_Reified_xVariable) TAG(sub__V313));
  switch (choice__V314)
  {
    case VarOf_M_Reified_xVariable: {
      do {
        ASSERT(sink__V311->context, !strcmp(SYMBOL(term__V312),  "MetaVar2$2" ));
        Term sub__V315 = SUB(term__V312, 0); permitUnusedTerm(sub__V315); int sub__V315_count = term__V312_count*LINK_COUNT(sub__V315); permitUnusedInt(sub__V315_count);
        CRSX_CHECK_SORT(sink__V311->context, sub__V315, &sort_M_Reified_xVariable); /* Function DEFS-MetaVar2-1$vFree fall-back case for free variable */
        Variable z__V316 = VARIABLE(sub__V315); permitUnusedVariable(z__V316);
        NamedPropertyLink namedP__V317 = LINK_NamedPropertyLink(sink__V311->context, NAMED_PROPERTIES(term__V312));
        VariablePropertyLink varP__V318 = LINK_VariablePropertyLink(sink__V311->context, VARIABLE_PROPERTIES(term__V312));
        UNLINK(sink__V311->context, term__V312);
        ADD_PROPERTIES(sink__V311, LINK_NamedPropertyLink(sink__V311->context, namedP__V317), LINK_VariablePropertyLink(sink__V311->context, varP__V318));
        { START(sink__V311, _M_MetaVar2_s3);
          USE(sink__V311, z__V316); END(sink__V311, _M_MetaVar2_s3); }
        UNLINK_NamedPropertyLink(sink__V311->context, namedP__V317); UNLINK_VariablePropertyLink(sink__V311->context, varP__V318);
        
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

int step_M_MetaVar2_s3(Sink sink__V319, Term term__V320)
{
  int term__V320_count = LINK_COUNT(term__V320); permitUnusedInt(term__V320_count);
  do {
    /* Contraction rule DEFS-MetaVar2-1. */
    ASSERT(sink__V319->context, !strcmp(SYMBOL(term__V320),  "MetaVar2$3" ));
    Term sub__V321 = LINK(sink__V319->context, SUB(term__V320, 0)); int sub__V321_count = term__V320_count*LINK_COUNT(sub__V321); permitUnusedInt(sub__V321_count);
    CRSX_CHECK_SORT(sink__V319->context, sub__V321, &sort_M_Reified_xVariable); UNLINK_SUB(sink__V319->context, term__V320,  0); NORMALIZE(sink__V319->context, sub__V321); SUB(term__V320,  0) = LINK(sink__V319->context, sub__V321);
    /* sub__V321 = &#11 */
    NamedPropertyLink namedP__V322 = LINK_NamedPropertyLink(sink__V319->context, NAMED_PROPERTIES(term__V320));
    VariablePropertyLink varP__V323 = LINK_VariablePropertyLink(sink__V319->context, VARIABLE_PROPERTIES(term__V320));
    UNLINK(sink__V319->context, term__V320);
    { START(sink__V319, _M__sTextCons);
      { START(sink__V319, _M__sTextEmbed);
        { START(sink__V319, _M_AsText);
          COPY(sink__V319, sub__V321);END(sink__V319, _M_AsText); }
        END(sink__V319, _M__sTextEmbed); }
      { START(sink__V319, _M__sTextNil);
        END(sink__V319, _M__sTextNil); }
      END(sink__V319, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V319->context, namedP__V322); UNLINK_VariablePropertyLink(sink__V319->context, varP__V323);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Sort. */
int conBindOffs_M_Sort[] = {0 , 0};
char *nameFun_M_Sort(Term term) { return  "Sort" ; }
struct _ConstructionDescriptor descriptor_M_Sort = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_Sort), conBindOffs_M_Sort, &nameFun_M_Sort, &step_M_Sort};

int step_M_Sort(Sink sink__V324, Term term__V325)
{
  int term__V325_count = LINK_COUNT(term__V325); permitUnusedInt(term__V325_count);
  do {
    /* Contraction rule DEFS-Sort-1. */
    ASSERT(sink__V324->context, !strcmp(SYMBOL(term__V325),  "Sort" ));
    Term sub__V326 = LINK(sink__V324->context, SUB(term__V325, 0)); int sub__V326_count = term__V325_count*LINK_COUNT(sub__V326); permitUnusedInt(sub__V326_count);
    /* sub__V326 = &#1 */
    NamedPropertyLink namedP__V327 = LINK_NamedPropertyLink(sink__V324->context, NAMED_PROPERTIES(term__V325));
    VariablePropertyLink varP__V328 = LINK_VariablePropertyLink(sink__V324->context, VARIABLE_PROPERTIES(term__V325));
    UNLINK(sink__V324->context, term__V325);
    { START(sink__V324, _M__sTextCons);
      { START(sink__V324, _M__sTextChars);
        LITERAL(sink__V324,  "sort" ); END(sink__V324, _M__sTextChars); }
      { START(sink__V324, _M__sTextCons);
        { START(sink__V324, _M__sTextEmbed);
          { START(sink__V324, _M_AsText);
            { START(sink__V324, _M_MANGLE);
              COPY(sink__V324, sub__V326);END(sink__V324, _M_MANGLE); }
            END(sink__V324, _M_AsText); }
          END(sink__V324, _M__sTextEmbed); }
        { START(sink__V324, _M__sTextNil);
          END(sink__V324, _M__sTextNil); }
        END(sink__V324, _M__sTextCons); }
      END(sink__V324, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V324->context, namedP__V327); UNLINK_VariablePropertyLink(sink__V324->context, varP__V328);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION EnumVar. */
int conBindOffs_M_EnumVar[] = {0 , 0};
char *nameFun_M_EnumVar(Term term) { return  "EnumVar" ; }
struct _ConstructionDescriptor descriptor_M_EnumVar = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_EnumVar), conBindOffs_M_EnumVar, &nameFun_M_EnumVar, &step_M_EnumVar};

int step_M_EnumVar(Sink sink__V329, Term term__V330)
{
  int term__V330_count = LINK_COUNT(term__V330); permitUnusedInt(term__V330_count);
  do {
    /* Contraction rule DEFS-EnumVar-1. */
    ASSERT(sink__V329->context, !strcmp(SYMBOL(term__V330),  "EnumVar" ));
    Term sub__V331 = LINK(sink__V329->context, SUB(term__V330, 0)); int sub__V331_count = term__V330_count*LINK_COUNT(sub__V331); permitUnusedInt(sub__V331_count);
    /* sub__V331 = &#1 */
    NamedPropertyLink namedP__V332 = LINK_NamedPropertyLink(sink__V329->context, NAMED_PROPERTIES(term__V330));
    VariablePropertyLink varP__V333 = LINK_VariablePropertyLink(sink__V329->context, VARIABLE_PROPERTIES(term__V330));
    UNLINK(sink__V329->context, term__V330);
    { START(sink__V329, _M__sTextCons);
      { START(sink__V329, _M__sTextChars);
        LITERAL(sink__V329,  "VarOf" ); END(sink__V329, _M__sTextChars); }
      { START(sink__V329, _M__sTextCons);
        { START(sink__V329, _M__sTextEmbed);
          { START(sink__V329, _M_AsText);
            { START(sink__V329, _M_MANGLE);
              COPY(sink__V329, sub__V331);END(sink__V329, _M_MANGLE); }
            END(sink__V329, _M_AsText); }
          END(sink__V329, _M__sTextEmbed); }
        { START(sink__V329, _M__sTextNil);
          END(sink__V329, _M__sTextNil); }
        END(sink__V329, _M__sTextCons); }
      END(sink__V329, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V329->context, namedP__V332); UNLINK_VariablePropertyLink(sink__V329->context, varP__V333);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DEnumTag$1. */
int conBindOffs_M_DEnumTag_s1[] = {0 , 0};
char *nameFun_M_DEnumTag_s1(Term term) { return  "DEnumTag$1" ; }
struct _ConstructionDescriptor descriptor_M_DEnumTag_s1 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_DEnumTag_s1), conBindOffs_M_DEnumTag_s1, &nameFun_M_DEnumTag_s1, &step_M_DEnumTag_s1};

int step_M_DEnumTag_s1(Sink sink__V334, Term term__V335)
{
  int term__V335_count = LINK_COUNT(term__V335); permitUnusedInt(term__V335_count);
  do {
    /* Contraction rule DEFS-DEnumTag-1. */
    ASSERT(sink__V334->context, !strcmp(SYMBOL(term__V335),  "DEnumTag$1" ));
    Term sub__V336 = LINK(sink__V334->context, SUB(term__V335, 0)); int sub__V336_count = term__V335_count*LINK_COUNT(sub__V336); permitUnusedInt(sub__V336_count);
    /* sub__V336 = &#2 */
    NamedPropertyLink namedP__V337 = LINK_NamedPropertyLink(sink__V334->context, NAMED_PROPERTIES(term__V335));
    VariablePropertyLink varP__V338 = LINK_VariablePropertyLink(sink__V334->context, VARIABLE_PROPERTIES(term__V335));
    UNLINK(sink__V334->context, term__V335);
    { START(sink__V334, _M__sTextCons);
      { START(sink__V334, _M__sTextChars);
        LITERAL(sink__V334,  "Data" ); END(sink__V334, _M__sTextChars); }
      { START(sink__V334, _M__sTextCons);
        { START(sink__V334, _M__sTextEmbed);
          { START(sink__V334, _M_AsText);
            { START(sink__V334, _M_MANGLE);
              COPY(sink__V334, sub__V336);END(sink__V334, _M_MANGLE); }
            END(sink__V334, _M_AsText); }
          END(sink__V334, _M__sTextEmbed); }
        { START(sink__V334, _M__sTextNil);
          END(sink__V334, _M__sTextNil); }
        END(sink__V334, _M__sTextCons); }
      END(sink__V334, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V334->context, namedP__V337); UNLINK_VariablePropertyLink(sink__V334->context, varP__V338);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION EnumFun. */
int conBindOffs_M_EnumFun[] = {0 , 0};
char *nameFun_M_EnumFun(Term term) { return  "EnumFun" ; }
struct _ConstructionDescriptor descriptor_M_EnumFun = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_EnumFun), conBindOffs_M_EnumFun, &nameFun_M_EnumFun, &step_M_EnumFun};

int step_M_EnumFun(Sink sink__V339, Term term__V340)
{
  int term__V340_count = LINK_COUNT(term__V340); permitUnusedInt(term__V340_count);
  do {
    /* Contraction rule DEFS-EnumFun-1. */
    ASSERT(sink__V339->context, !strcmp(SYMBOL(term__V340),  "EnumFun" ));
    Term sub__V341 = LINK(sink__V339->context, SUB(term__V340, 0)); int sub__V341_count = term__V340_count*LINK_COUNT(sub__V341); permitUnusedInt(sub__V341_count);
    /* sub__V341 = &#1 */
    NamedPropertyLink namedP__V342 = LINK_NamedPropertyLink(sink__V339->context, NAMED_PROPERTIES(term__V340));
    VariablePropertyLink varP__V343 = LINK_VariablePropertyLink(sink__V339->context, VARIABLE_PROPERTIES(term__V340));
    UNLINK(sink__V339->context, term__V340);
    { START(sink__V339, _M__sTextCons);
      { START(sink__V339, _M__sTextChars);
        LITERAL(sink__V339,  "FunOf" ); END(sink__V339, _M__sTextChars); }
      { START(sink__V339, _M__sTextCons);
        { START(sink__V339, _M__sTextEmbed);
          { START(sink__V339, _M_AsText);
            { START(sink__V339, _M_MANGLE);
              COPY(sink__V339, sub__V341);END(sink__V339, _M_MANGLE); }
            END(sink__V339, _M_AsText); }
          END(sink__V339, _M__sTextEmbed); }
        { START(sink__V339, _M__sTextNil);
          END(sink__V339, _M__sTextNil); }
        END(sink__V339, _M__sTextCons); }
      END(sink__V339, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V339->context, namedP__V342); UNLINK_VariablePropertyLink(sink__V339->context, varP__V343);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Sort-name. */
int conBindOffs_M_Sort__name[] = {0 , 0};
char *nameFun_M_Sort__name(Term term) { return  "Sort-name" ; }
struct _ConstructionDescriptor descriptor_M_Sort__name = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_Sort__name), conBindOffs_M_Sort__name, &nameFun_M_Sort__name, &step_M_Sort__name};

int step_M_Sort__name(Sink sink__V344, Term term__V345)
{
  int term__V345_count = LINK_COUNT(term__V345); permitUnusedInt(term__V345_count);
  Term sub__V346 = FORCE(sink__V344->context, SUB(term__V345, 0));
  EnumOf_M_Reified_xSort choice__V347 = (IS_VARIABLE_USE(sub__V346) ? VarOf_M_Reified_xSort : (EnumOf_M_Reified_xSort) TAG(sub__V346));
  switch (choice__V347)
  {
    case Data_M_SORT: { /* Function DEFS-Sort-name-1$Sort-name$SORT case SORT */
      ASSERT(sink__V344->context, !strcmp(SYMBOL(term__V345),  "Sort-name" ));
      Term sub__V348 = SUB(term__V345, 0); permitUnusedTerm(sub__V348); int sub__V348_count = term__V345_count*LINK_COUNT(sub__V348); permitUnusedInt(sub__V348_count);
      CRSX_CHECK_SORT(sink__V344->context, sub__V348, &sort_M_Reified_xSort); ASSERT(sink__V344->context, !strcmp(SYMBOL(sub__V348),  "SORT" ));
      Term sub__V349 = LINK(sink__V344->context, SUB(sub__V348, 0)); int sub__V349_count = sub__V348_count*LINK_COUNT(sub__V349); permitUnusedInt(sub__V349_count);
      /* sub__V349 = &#0-0 */
      Term sub__V350 = LINK(sink__V344->context, SUB(sub__V348, 1)); int sub__V350_count = sub__V348_count*LINK_COUNT(sub__V350); permitUnusedInt(sub__V350_count);
      /* sub__V350 = &#0-1 */
      NamedPropertyLink namedP__V351 = LINK_NamedPropertyLink(sink__V344->context, NAMED_PROPERTIES(term__V345));
      VariablePropertyLink varP__V352 = LINK_VariablePropertyLink(sink__V344->context, VARIABLE_PROPERTIES(term__V345));
      UNLINK(sink__V344->context, term__V345);
      ADD_PROPERTIES(sink__V344, LINK_NamedPropertyLink(sink__V344->context, namedP__V351), LINK_VariablePropertyLink(sink__V344->context, varP__V352));
      { START(sink__V344, _M_Sort__name_s1);
        COPY(sink__V344, sub__V349);COPY(sink__V344, sub__V350);END(sink__V344, _M_Sort__name_s1); }
      UNLINK_NamedPropertyLink(sink__V344->context, namedP__V351); UNLINK_VariablePropertyLink(sink__V344->context, varP__V352);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION MapText$1. */
int conBindOffs_M_MapText_s1[] = {0 , 0 , 1};
char *nameFun_M_MapText_s1(Term term) { return  "MapText$1" ; }
struct _ConstructionDescriptor descriptor_M_MapText_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_MapText_s1), conBindOffs_M_MapText_s1, &nameFun_M_MapText_s1, &step_M_MapText_s1};

int step_M_MapText_s1(Sink sink__V353, Term term__V354)
{
  int term__V354_count = LINK_COUNT(term__V354); permitUnusedInt(term__V354_count);
  Term sub__V355 = FORCE(sink__V353->context, SUB(term__V354, 0));
  EnumOf_M__sList choice__V356 = (IS_VARIABLE_USE(sub__V355) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V355));
  switch (choice__V356)
  {
    case Data_M__sCons: { /* Function DEFS-MapText-1$MapText$1$$Cons case $Cons */
      ASSERT(sink__V353->context, !strcmp(SYMBOL(term__V354),  "MapText$1" ));
      Term sub__V357 = SUB(term__V354, 0); permitUnusedTerm(sub__V357); int sub__V357_count = term__V354_count*LINK_COUNT(sub__V357); permitUnusedInt(sub__V357_count);
      ASSERT(sink__V353->context, !strcmp(SYMBOL(sub__V357),  "$Cons" ));
      Term sub__V358 = LINK(sink__V353->context, SUB(sub__V357, 0)); int sub__V358_count = sub__V357_count*LINK_COUNT(sub__V358); permitUnusedInt(sub__V358_count);
      /* sub__V358 = &#0-0 */
      Term sub__V359 = LINK(sink__V353->context, SUB(sub__V357, 1)); int sub__V359_count = sub__V357_count*LINK_COUNT(sub__V359); permitUnusedInt(sub__V359_count);
      /* sub__V359 = &#0-1 */
      Variable x__V360 = BINDER(term__V354,1,0); if (term__V354_count <= 1) UNBIND(x__V360);
      Term sub__V361 = LINK(sink__V353->context, SUB(term__V354, 1)); int sub__V361_count = term__V354_count*LINK_COUNT(sub__V361); permitUnusedInt(sub__V361_count);
      CRSX_CHECK_SORT(sink__V353->context, sub__V361, &sort_M_Reified_xVariable); /* sub__V361 = &#2 */
      NamedPropertyLink namedP__V362 = LINK_NamedPropertyLink(sink__V353->context, NAMED_PROPERTIES(term__V354));
      VariablePropertyLink varP__V363 = LINK_VariablePropertyLink(sink__V353->context, VARIABLE_PROPERTIES(term__V354));
      UNLINK(sink__V353->context, term__V354);
      ADD_PROPERTIES(sink__V353, LINK_NamedPropertyLink(sink__V353->context, namedP__V362), LINK_VariablePropertyLink(sink__V353->context, varP__V363));
      { START(sink__V353, _M_MapText_s2);
        COPY(sink__V353, sub__V358);COPY(sink__V353, sub__V359);{ if (!IS_BOUND(x__V360)) { REBIND(x__V360);
            Variable binds__V364[1] = {x__V360}; BINDS(sink__V353, 1, binds__V364);
            COPY(sink__V353, sub__V361); /* REUSED SUBSTITUTION */  }
          else { Variable b__V365 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V353->context,"b__V365");
            Variable binds__V366[1] = {b__V365}; BINDS(sink__V353, 1, binds__V366);
            {
              Term arg__V367;
              { Sink buf__V368 = ALLOCA_BUFFER(sink__V353->context);
                USE(buf__V368, b__V365); arg__V367 = BUFFER_TERM(buf__V368); FREE_BUFFER(buf__V368); }
              Variable vars__V369[1] = {x__V360};
              Term args__V370[1] = {arg__V367};
              struct _SubstitutionFrame substitution__V371 = {NULL, 0, 1, vars__V369, args__V370, NULL};
              SUBSTITUTE(sink__V353, sub__V361, &substitution__V371); }
                }
           }
        END(sink__V353, _M_MapText_s2); }
      UNLINK_NamedPropertyLink(sink__V353->context, namedP__V362); UNLINK_VariablePropertyLink(sink__V353->context, varP__V363);
      
      return 1;
    break; } case Data_M__sNil: { /* Function DEFS-MapText-2$MapText$1$$Nil case $Nil */
      ASSERT(sink__V353->context, !strcmp(SYMBOL(term__V354),  "MapText$1" ));
      Term sub__V372 = SUB(term__V354, 0); permitUnusedTerm(sub__V372); int sub__V372_count = term__V354_count*LINK_COUNT(sub__V372); permitUnusedInt(sub__V372_count);
      ASSERT(sink__V353->context, !strcmp(SYMBOL(sub__V372),  "$Nil" ));
      Variable x__V373 = BINDER(term__V354,1,0); if (term__V354_count <= 1) UNBIND(x__V373);
      Term sub__V374 = LINK(sink__V353->context, SUB(term__V354, 1)); int sub__V374_count = term__V354_count*LINK_COUNT(sub__V374); permitUnusedInt(sub__V374_count);
      CRSX_CHECK_SORT(sink__V353->context, sub__V374, &sort_M_Reified_xVariable); /* sub__V374 = &#0 */
      NamedPropertyLink namedP__V375 = LINK_NamedPropertyLink(sink__V353->context, NAMED_PROPERTIES(term__V354));
      VariablePropertyLink varP__V376 = LINK_VariablePropertyLink(sink__V353->context, VARIABLE_PROPERTIES(term__V354));
      UNLINK(sink__V353->context, term__V354);
      ADD_PROPERTIES(sink__V353, LINK_NamedPropertyLink(sink__V353->context, namedP__V375), LINK_VariablePropertyLink(sink__V353->context, varP__V376));
      { START(sink__V353, _M_MapText_s3);
        { if (!IS_BOUND(x__V373)) { REBIND(x__V373);
            Variable binds__V377[1] = {x__V373}; BINDS(sink__V353, 1, binds__V377);
            COPY(sink__V353, sub__V374); /* REUSED SUBSTITUTION */  }
          else { Variable b__V378 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V353->context,"b__V378");
            Variable binds__V379[1] = {b__V378}; BINDS(sink__V353, 1, binds__V379);
            {
              Term arg__V380;
              { Sink buf__V381 = ALLOCA_BUFFER(sink__V353->context);
                USE(buf__V381, b__V378); arg__V380 = BUFFER_TERM(buf__V381); FREE_BUFFER(buf__V381); }
              Variable vars__V382[1] = {x__V373};
              Term args__V383[1] = {arg__V380};
              struct _SubstitutionFrame substitution__V384 = {NULL, 0, 1, vars__V382, args__V383, NULL};
              SUBSTITUTE(sink__V353, sub__V374, &substitution__V384); }
                }
           }
        END(sink__V353, _M_MapText_s3); }
      UNLINK_NamedPropertyLink(sink__V353->context, namedP__V375); UNLINK_VariablePropertyLink(sink__V353->context, varP__V376);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION MapText$2. */
int conBindOffs_M_MapText_s2[] = {0 , 0 , 0 , 1};
char *nameFun_M_MapText_s2(Term term) { return  "MapText$2" ; }
struct _ConstructionDescriptor descriptor_M_MapText_s2 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_MapText_s2), conBindOffs_M_MapText_s2, &nameFun_M_MapText_s2, &step_M_MapText_s2};

int step_M_MapText_s2(Sink sink__V385, Term term__V386)
{
  int term__V386_count = LINK_COUNT(term__V386); permitUnusedInt(term__V386_count);
  do {
    /* Contraction rule DEFS-MapText-1. */
    ASSERT(sink__V385->context, !strcmp(SYMBOL(term__V386),  "MapText$2" ));
    Term sub__V387 = LINK(sink__V385->context, SUB(term__V386, 0)); int sub__V387_count = term__V386_count*LINK_COUNT(sub__V387); permitUnusedInt(sub__V387_count);
    /* sub__V387 = &#21 */
    Term sub__V388 = LINK(sink__V385->context, SUB(term__V386, 1)); int sub__V388_count = term__V386_count*LINK_COUNT(sub__V388); permitUnusedInt(sub__V388_count);
    /* sub__V388 = &#22 */
    Variable x__V389 = BINDER(term__V386,2,0); if (term__V386_count <= 1) UNBIND(x__V389);
    Term sub__V390 = LINK(sink__V385->context, SUB(term__V386, 2)); int sub__V390_count = term__V386_count*LINK_COUNT(sub__V390); permitUnusedInt(sub__V390_count);
    CRSX_CHECK_SORT(sink__V385->context, sub__V390, &sort_M_Reified_xVariable); UNLINK_SUB(sink__V385->context, term__V386,  2); NORMALIZE(sink__V385->context, sub__V390); SUB(term__V386,  2) = LINK(sink__V385->context, sub__V390);
    /* sub__V390 = &#1 */
    NamedPropertyLink namedP__V391 = LINK_NamedPropertyLink(sink__V385->context, NAMED_PROPERTIES(term__V386));
    VariablePropertyLink varP__V392 = LINK_VariablePropertyLink(sink__V385->context, VARIABLE_PROPERTIES(term__V386));
    UNLINK(sink__V385->context, term__V386);
    { START(sink__V385, _M__sTextCons);
      { START(sink__V385, _M__sTextEmbed);
        { START(sink__V385, _M_AsText);
          {
            Term arg__V393;
            { Sink buf__V394 = ALLOCA_BUFFER(sink__V385->context);
              COPY(buf__V394, sub__V387);arg__V393 = BUFFER_TERM(buf__V394); FREE_BUFFER(buf__V394); }
            Variable vars__V395[1] = {x__V389};
            Term args__V396[1] = {arg__V393};
            struct _SubstitutionFrame substitution__V397 = {NULL, 0, 1, vars__V395, args__V396, NULL};
            SUBSTITUTE(sink__V385, LINK(sink__V385->context,sub__V390), &substitution__V397); }
          END(sink__V385, _M_AsText); }
        END(sink__V385, _M__sTextEmbed); }
      { START(sink__V385, _M__sTextCons);
        { START(sink__V385, _M__sTextEmbed);
          { START(sink__V385, _M_AsText);
            { START(sink__V385, _M_MapText_s1);
              COPY(sink__V385, sub__V388);{ Variable x__V398 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V385->context,"x__V398");
                Variable binds__V399[1] = {x__V398}; BINDS(sink__V385, 1, binds__V399);
                {
                  Term arg__V400;
                  { Sink buf__V401 = ALLOCA_BUFFER(sink__V385->context);
                    USE(buf__V401, x__V398); arg__V400 = BUFFER_TERM(buf__V401); FREE_BUFFER(buf__V401); }
                  Variable vars__V402[1] = {x__V389};
                  Term args__V403[1] = {arg__V400};
                  struct _SubstitutionFrame substitution__V404 = {NULL, 0, 1, vars__V402, args__V403, NULL};
                  SUBSTITUTE(sink__V385, sub__V390, &substitution__V404); }
                 }
              END(sink__V385, _M_MapText_s1); }
            END(sink__V385, _M_AsText); }
          END(sink__V385, _M__sTextEmbed); }
        { START(sink__V385, _M__sTextNil);
          END(sink__V385, _M__sTextNil); }
        END(sink__V385, _M__sTextCons); }
      END(sink__V385, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V385->context, namedP__V391); UNLINK_VariablePropertyLink(sink__V385->context, varP__V392);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION MapText$3. */
int conBindOffs_M_MapText_s3[] = {0 , 1};
char *nameFun_M_MapText_s3(Term term) { return  "MapText$3" ; }
struct _ConstructionDescriptor descriptor_M_MapText_s3 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_MapText_s3), conBindOffs_M_MapText_s3, &nameFun_M_MapText_s3, &step_M_MapText_s3};

int step_M_MapText_s3(Sink sink__V405, Term term__V406)
{
  int term__V406_count = LINK_COUNT(term__V406); permitUnusedInt(term__V406_count);
  do {
    /* Contraction rule DEFS-MapText-2. */
    ASSERT(sink__V405->context, !strcmp(SYMBOL(term__V406),  "MapText$3" ));
    Variable x__V407 = BINDER(term__V406,0,0); if (term__V406_count <= 1) UNBIND(x__V407);
    Term sub__V408 = SUB(term__V406, 0); permitUnusedTerm(sub__V408); int sub__V408_count = term__V406_count*LINK_COUNT(sub__V408); permitUnusedInt(sub__V408_count);
    CRSX_CHECK_SORT(sink__V405->context, sub__V408, &sort_M_Reified_xVariable); /* sub__V408 = &#1 */
    NamedPropertyLink namedP__V409 = LINK_NamedPropertyLink(sink__V405->context, NAMED_PROPERTIES(term__V406));
    VariablePropertyLink varP__V410 = LINK_VariablePropertyLink(sink__V405->context, VARIABLE_PROPERTIES(term__V406));
    UNLINK(sink__V405->context, term__V406);
    { START(sink__V405, _M__sTextNil); END(sink__V405, _M__sTextNil); }
    UNLINK_NamedPropertyLink(sink__V405->context, namedP__V409); UNLINK_VariablePropertyLink(sink__V405->context, varP__V410);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION EventConstructor. */
int conBindOffs_M_EventConstructor[] = {0 , 0};
char *nameFun_M_EventConstructor(Term term) { return  "EventConstructor" ; }
struct _ConstructionDescriptor descriptor_M_EventConstructor = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_EventConstructor), conBindOffs_M_EventConstructor, &nameFun_M_EventConstructor, &step_M_EventConstructor};

int step_M_EventConstructor(Sink sink__V411, Term term__V412)
{
  int term__V412_count = LINK_COUNT(term__V412); permitUnusedInt(term__V412_count);
  do {
    /* Contraction rule DEFS-EventConstructor-1. */
    ASSERT(sink__V411->context, !strcmp(SYMBOL(term__V412),  "EventConstructor" ));
    Term sub__V413 = LINK(sink__V411->context, SUB(term__V412, 0)); int sub__V413_count = term__V412_count*LINK_COUNT(sub__V413); permitUnusedInt(sub__V413_count);
    /* sub__V413 = &#1 */
    NamedPropertyLink namedP__V414 = LINK_NamedPropertyLink(sink__V411->context, NAMED_PROPERTIES(term__V412));
    VariablePropertyLink varP__V415 = LINK_VariablePropertyLink(sink__V411->context, VARIABLE_PROPERTIES(term__V412));
    UNLINK(sink__V411->context, term__V412);
    { START(sink__V411, _M_MANGLE);
      COPY(sink__V411, sub__V413);END(sink__V411, _M_MANGLE); }
    UNLINK_NamedPropertyLink(sink__V411->context, namedP__V414); UNLINK_VariablePropertyLink(sink__V411->context, varP__V415);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION MetaVar. */
int conBindOffs_M_MetaVar[] = {0 , 0};
char *nameFun_M_MetaVar(Term term) { return  "MetaVar" ; }
struct _ConstructionDescriptor descriptor_M_MetaVar = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_MetaVar), conBindOffs_M_MetaVar, &nameFun_M_MetaVar, &step_M_MetaVar};

int step_M_MetaVar(Sink sink__V416, Term term__V417)
{
  int term__V417_count = LINK_COUNT(term__V417); permitUnusedInt(term__V417_count);
  do {
    /* Contraction rule DEFS-MetaVar-1. */
    ASSERT(sink__V416->context, !strcmp(SYMBOL(term__V417),  "MetaVar" ));
    Term sub__V418 = LINK(sink__V416->context, SUB(term__V417, 0)); int sub__V418_count = term__V417_count*LINK_COUNT(sub__V418); permitUnusedInt(sub__V418_count);
    UNLINK_SUB(sink__V416->context, term__V417,  0); NORMALIZE(sink__V416->context, sub__V418); SUB(term__V417,  0) = LINK(sink__V416->context, sub__V418);
    /* sub__V418 = &#1 */
    NamedPropertyLink namedP__V419 = LINK_NamedPropertyLink(sink__V416->context, NAMED_PROPERTIES(term__V417));
    VariablePropertyLink varP__V420 = LINK_VariablePropertyLink(sink__V416->context, VARIABLE_PROPERTIES(term__V417));
    UNLINK(sink__V416->context, term__V417);
    ADD_PROPERTIES(sink__V416, LINK_NamedPropertyLink(sink__V416->context, namedP__V419), LINK_VariablePropertyLink(sink__V416->context, varP__V420));
    { START(sink__V416, _M_MetaVar2);
      { Term term__V421;
        { Term key__V422;
          char *sub__V423[2]; size_t sublength__V424[2]; size_t length__V425 = 0;
          length__V425 += (sublength__V424[0] = strlen(sub__V423[0] =  "MetaVar$" ));
          FORCE(sink__V416->context, sub__V418);
          length__V425 += (sublength__V424[1] = strlen(sub__V423[1] = SYMBOL(sub__V418)));
          { char *str__V426 = ALLOCA(sink__V416->context, length__V425+1), *p__V427 = str__V426;
            int i; for (i = 0; i < 2; ++i) { memcpy(p__V427, sub__V423[i], sublength__V424[i]); p__V427 += sublength__V424[i]; }
            *p__V427 = '\0';
            ASSERT(sink__V416->context, strlen(str__V426) == length__V425);
            key__V422 = makeStringLiteral(sink__V416->context, str__V426);
            }
          Term *pp__V428 = DPROPERTY(namedP__V419, varP__V420, key__V422);UNLINK(sink__V416->context, key__V422); 
          if (pp__V428) term__V421 = LINK(sink__V416->context, *pp__V428);
          else {{ Sink buf__V429 = ALLOCA_BUFFER(sink__V416->context);
              { START(buf__V429, _M_STRING_xVALUE);
                { char *str__V430;
                  { char *sub__V431[2]; size_t sublength__V432[2]; size_t length__V433 = 0;
                    length__V433 += (sublength__V432[0] = strlen(sub__V431[0] =  "m" ));
                    FORCE(buf__V429->context, sub__V418);
                    { char *s__V434 = makeMangled(buf__V429->context, SYMBOL(sub__V418));
                      length__V433 += (sublength__V432[1] = strlen(sub__V431[1] = s__V434));
                      UNLINK(buf__V429->context, sub__V418);{ char *str__V435 = ALLOCATE(buf__V429->context, length__V433+1), *p__V436 = str__V435;
                        int i; for (i = 0; i < 2; ++i) { memcpy(p__V436, sub__V431[i], sublength__V432[i]); p__V436 += sublength__V432[i]; }
                        *p__V436 = '\0';
                        ASSERT(buf__V429->context, strlen(str__V435) == length__V433);
                        str__V430 = str__V435; }
                      }
                     }
                  LITERALU(buf__V429, str__V430); }
                END(buf__V429, _M_STRING_xVALUE); }
              term__V421 = BUFFER_TERM(buf__V429); FREE_BUFFER(buf__V429); }
            }
        }
        COPY(sink__V416, term__V421); /*CONSERVATIVE*/ }
      END(sink__V416, _M_MetaVar2); }
    UNLINK_NamedPropertyLink(sink__V416->context, namedP__V419); UNLINK_VariablePropertyLink(sink__V416->context, varP__V420);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DINTEGER$1. */
int conBindOffs_M_DINTEGER_s1[] = {0 , 0};
char *nameFun_M_DINTEGER_s1(Term term) { return  "DINTEGER$1" ; }
struct _ConstructionDescriptor descriptor_M_DINTEGER_s1 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_DINTEGER_s1), conBindOffs_M_DINTEGER_s1, &nameFun_M_DINTEGER_s1, &step_M_DINTEGER_s1};

int step_M_DINTEGER_s1(Sink sink__V437, Term term__V438)
{
  int term__V438_count = LINK_COUNT(term__V438); permitUnusedInt(term__V438_count);
  do {
    /* Contraction rule DEFS-DINTEGER-1. */
    ASSERT(sink__V437->context, !strcmp(SYMBOL(term__V438),  "DINTEGER$1" ));
    Term sub__V439 = LINK(sink__V437->context, SUB(term__V438, 0)); int sub__V439_count = term__V438_count*LINK_COUNT(sub__V439); permitUnusedInt(sub__V439_count);
    UNLINK_SUB(sink__V437->context, term__V438,  0); NORMALIZE(sink__V437->context, sub__V439); SUB(term__V438,  0) = LINK(sink__V437->context, sub__V439);
    /* sub__V439 = &#2 */
    NamedPropertyLink namedP__V440 = LINK_NamedPropertyLink(sink__V437->context, NAMED_PROPERTIES(term__V438));
    VariablePropertyLink varP__V441 = LINK_VariablePropertyLink(sink__V437->context, VARIABLE_PROPERTIES(term__V438));
    UNLINK(sink__V437->context, term__V438);
    { START(sink__V437, _M__sTextCons);
      { START(sink__V437, _M__sTextChars);
        { char *str__V442;
          {double num__V443; char *str__V444;
            num__V443 = DOUBLE(sub__V439); snprintf(str__V444 = ALLOCA(sink__V437->context, (size_t) 32), (size_t) 31, "%G", num__V443);
            { size_t z__V445 = strlen(str__V444) + 1; memcpy(str__V442 = ALLOCATE(sink__V437->context, z__V445), str__V444, z__V445); }
             }
          LITERALU(sink__V437, str__V442); }
        END(sink__V437, _M__sTextChars); }
      { START(sink__V437, _M__sTextNil);
        END(sink__V437, _M__sTextNil); }
      END(sink__V437, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V437->context, namedP__V440); UNLINK_VariablePropertyLink(sink__V437->context, varP__V441);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DDescriptor$1. */
int conBindOffs_M_DDescriptor_s1[] = {0 , 0};
char *nameFun_M_DDescriptor_s1(Term term) { return  "DDescriptor$1" ; }
struct _ConstructionDescriptor descriptor_M_DDescriptor_s1 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_DDescriptor_s1), conBindOffs_M_DDescriptor_s1, &nameFun_M_DDescriptor_s1, &step_M_DDescriptor_s1};

int step_M_DDescriptor_s1(Sink sink__V446, Term term__V447)
{
  int term__V447_count = LINK_COUNT(term__V447); permitUnusedInt(term__V447_count);
  do {
    /* Contraction rule DEFS-DDescriptor-1. */
    ASSERT(sink__V446->context, !strcmp(SYMBOL(term__V447),  "DDescriptor$1" ));
    Term sub__V448 = LINK(sink__V446->context, SUB(term__V447, 0)); int sub__V448_count = term__V447_count*LINK_COUNT(sub__V448); permitUnusedInt(sub__V448_count);
    /* sub__V448 = &#2 */
    NamedPropertyLink namedP__V449 = LINK_NamedPropertyLink(sink__V446->context, NAMED_PROPERTIES(term__V447));
    VariablePropertyLink varP__V450 = LINK_VariablePropertyLink(sink__V446->context, VARIABLE_PROPERTIES(term__V447));
    UNLINK(sink__V446->context, term__V447);
    { START(sink__V446, _M__sTextCons);
      { START(sink__V446, _M__sTextChars);
        LITERAL(sink__V446,  "descriptor" ); END(sink__V446, _M__sTextChars); }
      { START(sink__V446, _M__sTextCons);
        { START(sink__V446, _M__sTextEmbed);
          { START(sink__V446, _M_AsText);
            { START(sink__V446, _M_MANGLE);
              COPY(sink__V446, sub__V448);END(sink__V446, _M_MANGLE); }
            END(sink__V446, _M_AsText); }
          END(sink__V446, _M__sTextEmbed); }
        { START(sink__V446, _M__sTextNil);
          END(sink__V446, _M__sTextNil); }
        END(sink__V446, _M__sTextCons); }
      END(sink__V446, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V446->context, namedP__V449); UNLINK_VariablePropertyLink(sink__V446->context, varP__V450);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION PromiscuityString. */
int conBindOffs_M_PromiscuityString[] = {0 , 0};
char *nameFun_M_PromiscuityString(Term term) { return  "PromiscuityString" ; }
struct _ConstructionDescriptor descriptor_M_PromiscuityString = {NULL, 0, 1, sizeof(STRUCT_Con_M_PromiscuityString), conBindOffs_M_PromiscuityString, &nameFun_M_PromiscuityString, &step_M_PromiscuityString};

int step_M_PromiscuityString(Sink sink__V451, Term term__V452)
{
  int term__V452_count = LINK_COUNT(term__V452); permitUnusedInt(term__V452_count);
  Term sub__V453 = FORCE(sink__V451->context, SUB(term__V452, 0));
  EnumOf_M_Reified_xPromiscuity choice__V454 = (IS_VARIABLE_USE(sub__V453) ? VarOf_M_Reified_xPromiscuity : (EnumOf_M_Reified_xPromiscuity) TAG(sub__V453));
  switch (choice__V454)
  {
    case Data_M_LINEAR: { /* Function DEFS-PromiscuityString-1$PromiscuityString$LINEAR case LINEAR */
      ASSERT(sink__V451->context, !strcmp(SYMBOL(term__V452),  "PromiscuityString" ));
      Term sub__V455 = SUB(term__V452, 0); permitUnusedTerm(sub__V455); int sub__V455_count = term__V452_count*LINK_COUNT(sub__V455); permitUnusedInt(sub__V455_count);
      CRSX_CHECK_SORT(sink__V451->context, sub__V455, &sort_M_Reified_xPromiscuity); ASSERT(sink__V451->context, !strcmp(SYMBOL(sub__V455),  "LINEAR" ));
      NamedPropertyLink namedP__V456 = LINK_NamedPropertyLink(sink__V451->context, NAMED_PROPERTIES(term__V452));
      VariablePropertyLink varP__V457 = LINK_VariablePropertyLink(sink__V451->context, VARIABLE_PROPERTIES(term__V452));
      UNLINK(sink__V451->context, term__V452);
      ADD_PROPERTIES(sink__V451, LINK_NamedPropertyLink(sink__V451->context, namedP__V456), LINK_VariablePropertyLink(sink__V451->context, varP__V457));
      { START(sink__V451, _M_PromiscuityString_s1);
        END(sink__V451, _M_PromiscuityString_s1); }
      UNLINK_NamedPropertyLink(sink__V451->context, namedP__V456); UNLINK_VariablePropertyLink(sink__V451->context, varP__V457);
      
      return 1;
    break; } case Data_M_PROMISCUOUS: { /* Function DEFS-PromiscuityString-2$PromiscuityString$PROMISCUOUS case PROMISCUOUS */
      ASSERT(sink__V451->context, !strcmp(SYMBOL(term__V452),  "PromiscuityString" ));
      Term sub__V458 = SUB(term__V452, 0); permitUnusedTerm(sub__V458); int sub__V458_count = term__V452_count*LINK_COUNT(sub__V458); permitUnusedInt(sub__V458_count);
      CRSX_CHECK_SORT(sink__V451->context, sub__V458, &sort_M_Reified_xPromiscuity); ASSERT(sink__V451->context, !strcmp(SYMBOL(sub__V458),  "PROMISCUOUS" ));
      NamedPropertyLink namedP__V459 = LINK_NamedPropertyLink(sink__V451->context, NAMED_PROPERTIES(term__V452));
      VariablePropertyLink varP__V460 = LINK_VariablePropertyLink(sink__V451->context, VARIABLE_PROPERTIES(term__V452));
      UNLINK(sink__V451->context, term__V452);
      ADD_PROPERTIES(sink__V451, LINK_NamedPropertyLink(sink__V451->context, namedP__V459), LINK_VariablePropertyLink(sink__V451->context, varP__V460));
      { START(sink__V451, _M_PromiscuityString_s2);
        END(sink__V451, _M_PromiscuityString_s2); }
      UNLINK_NamedPropertyLink(sink__V451->context, namedP__V459); UNLINK_VariablePropertyLink(sink__V451->context, varP__V460);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION MANGLE. */
int conBindOffs_M_MANGLE[] = {0 , 0};
char *nameFun_M_MANGLE(Term term) { return  "MANGLE" ; }
struct _ConstructionDescriptor descriptor_M_MANGLE = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_MANGLE), conBindOffs_M_MANGLE, &nameFun_M_MANGLE, &step_M_MANGLE};

int step_M_MANGLE(Sink sink__V461, Term term__V462)
{
  int term__V462_count = LINK_COUNT(term__V462); permitUnusedInt(term__V462_count);
  do {
    /* Contraction rule DEFS-MANGLE-1. */
    ASSERT(sink__V461->context, !strcmp(SYMBOL(term__V462),  "MANGLE" ));
    Term sub__V463 = LINK(sink__V461->context, SUB(term__V462, 0)); int sub__V463_count = term__V462_count*LINK_COUNT(sub__V463); permitUnusedInt(sub__V463_count);
    UNLINK_SUB(sink__V461->context, term__V462,  0); NORMALIZE(sink__V461->context, sub__V463); SUB(term__V462,  0) = LINK(sink__V461->context, sub__V463);
    /* sub__V463 = &#1 */
    NamedPropertyLink namedP__V464 = LINK_NamedPropertyLink(sink__V461->context, NAMED_PROPERTIES(term__V462));
    VariablePropertyLink varP__V465 = LINK_VariablePropertyLink(sink__V461->context, VARIABLE_PROPERTIES(term__V462));
    UNLINK(sink__V461->context, term__V462);
    { START(sink__V461, _M__sTextCons);
      { START(sink__V461, _M__sTextChars);
        { char *str__V466;
          FORCE(sink__V461->context, sub__V463);
          { char *s__V467 = makeMangled(sink__V461->context, SYMBOL(sub__V463));
            { size_t z__V468 = strlen(s__V467) + 1; memcpy(str__V466 = ALLOCATE(sink__V461->context, z__V468), s__V467, z__V468);  UNLINK(sink__V461->context, sub__V463);}
            }
          LITERALU(sink__V461, str__V466); }
        END(sink__V461, _M__sTextChars); }
      { START(sink__V461, _M__sTextNil);
        END(sink__V461, _M__sTextNil); }
      END(sink__V461, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V461->context, namedP__V464); UNLINK_VariablePropertyLink(sink__V461->context, varP__V465);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION NameFun. */
int conBindOffs_M_NameFun[] = {0 , 0};
char *nameFun_M_NameFun(Term term) { return  "NameFun" ; }
struct _ConstructionDescriptor descriptor_M_NameFun = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_NameFun), conBindOffs_M_NameFun, &nameFun_M_NameFun, &step_M_NameFun};

int step_M_NameFun(Sink sink__V469, Term term__V470)
{
  int term__V470_count = LINK_COUNT(term__V470); permitUnusedInt(term__V470_count);
  do {
    /* Contraction rule DEFS-NameFun-1. */
    ASSERT(sink__V469->context, !strcmp(SYMBOL(term__V470),  "NameFun" ));
    Term sub__V471 = LINK(sink__V469->context, SUB(term__V470, 0)); int sub__V471_count = term__V470_count*LINK_COUNT(sub__V471); permitUnusedInt(sub__V471_count);
    /* sub__V471 = &#1 */
    NamedPropertyLink namedP__V472 = LINK_NamedPropertyLink(sink__V469->context, NAMED_PROPERTIES(term__V470));
    VariablePropertyLink varP__V473 = LINK_VariablePropertyLink(sink__V469->context, VARIABLE_PROPERTIES(term__V470));
    UNLINK(sink__V469->context, term__V470);
    { START(sink__V469, _M__sTextCons);
      { START(sink__V469, _M__sTextChars);
        LITERAL(sink__V469,  "nameFun" ); END(sink__V469, _M__sTextChars); }
      { START(sink__V469, _M__sTextCons);
        { START(sink__V469, _M__sTextEmbed);
          { START(sink__V469, _M_AsText);
            { START(sink__V469, _M_MANGLE);
              COPY(sink__V469, sub__V471);END(sink__V469, _M_MANGLE); }
            END(sink__V469, _M_AsText); }
          END(sink__V469, _M__sTextEmbed); }
        { START(sink__V469, _M__sTextNil);
          END(sink__V469, _M__sTextNil); }
        END(sink__V469, _M__sTextCons); }
      END(sink__V469, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V469->context, namedP__V472); UNLINK_VariablePropertyLink(sink__V469->context, varP__V473);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DTOKEN. */
int conBindOffs_M_DTOKEN[] = {0 , 0 , 0};
char *nameFun_M_DTOKEN(Term term) { return  "DTOKEN" ; }
struct _ConstructionDescriptor descriptor_M_DTOKEN = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_DTOKEN), conBindOffs_M_DTOKEN, &nameFun_M_DTOKEN, &step_M_DTOKEN};

int step_M_DTOKEN(Sink sink__V474, Term term__V475)
{
  int term__V475_count = LINK_COUNT(term__V475); permitUnusedInt(term__V475_count);
  Term sub__V476 = FORCE(sink__V474->context, SUB(term__V475, 0));
  EnumOf_M_OK_xSORT choice__V477 = (IS_VARIABLE_USE(sub__V476) ? VarOf_M_OK_xSORT : (EnumOf_M_OK_xSORT) TAG(sub__V476));
  switch (choice__V477)
  {
    case Data_M_OK: { /* Function DEFS-DTOKEN-1$DTOKEN$OK case OK */
      ASSERT(sink__V474->context, !strcmp(SYMBOL(term__V475),  "DTOKEN" ));
      Term sub__V478 = SUB(term__V475, 0); permitUnusedTerm(sub__V478); int sub__V478_count = term__V475_count*LINK_COUNT(sub__V478); permitUnusedInt(sub__V478_count);
      CRSX_CHECK_SORT(sink__V474->context, sub__V478, &sort_M_OK_xSORT); ASSERT(sink__V474->context, !strcmp(SYMBOL(sub__V478),  "OK" ));
      Term sub__V479 = LINK(sink__V474->context, SUB(term__V475, 1)); int sub__V479_count = term__V475_count*LINK_COUNT(sub__V479); permitUnusedInt(sub__V479_count);
      /* sub__V479 = &#0 */
      NamedPropertyLink namedP__V480 = LINK_NamedPropertyLink(sink__V474->context, NAMED_PROPERTIES(term__V475));
      VariablePropertyLink varP__V481 = LINK_VariablePropertyLink(sink__V474->context, VARIABLE_PROPERTIES(term__V475));
      UNLINK(sink__V474->context, term__V475);
      ADD_PROPERTIES(sink__V474, LINK_NamedPropertyLink(sink__V474->context, namedP__V480), LINK_VariablePropertyLink(sink__V474->context, varP__V481));
      { START(sink__V474, _M_DTOKEN_s1);
        COPY(sink__V474, sub__V479);END(sink__V474, _M_DTOKEN_s1); }
      UNLINK_NamedPropertyLink(sink__V474->context, namedP__V480); UNLINK_VariablePropertyLink(sink__V474->context, varP__V481);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION EnumTag. */
int conBindOffs_M_EnumTag[] = {0 , 0};
char *nameFun_M_EnumTag(Term term) { return  "EnumTag" ; }
struct _ConstructionDescriptor descriptor_M_EnumTag = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_EnumTag), conBindOffs_M_EnumTag, &nameFun_M_EnumTag, &step_M_EnumTag};

int step_M_EnumTag(Sink sink__V482, Term term__V483)
{
  int term__V483_count = LINK_COUNT(term__V483); permitUnusedInt(term__V483_count);
  do {
    /* Contraction rule DEFS-EnumTag-1. */
    ASSERT(sink__V482->context, !strcmp(SYMBOL(term__V483),  "EnumTag" ));
    Term sub__V484 = LINK(sink__V482->context, SUB(term__V483, 0)); int sub__V484_count = term__V483_count*LINK_COUNT(sub__V484); permitUnusedInt(sub__V484_count);
    /* sub__V484 = &#1 */
    NamedPropertyLink namedP__V485 = LINK_NamedPropertyLink(sink__V482->context, NAMED_PROPERTIES(term__V483));
    VariablePropertyLink varP__V486 = LINK_VariablePropertyLink(sink__V482->context, VARIABLE_PROPERTIES(term__V483));
    UNLINK(sink__V482->context, term__V483);
    { START(sink__V482, _M__sTextCons);
      { START(sink__V482, _M__sTextChars);
        LITERAL(sink__V482,  "Data" ); END(sink__V482, _M__sTextChars); }
      { START(sink__V482, _M__sTextCons);
        { START(sink__V482, _M__sTextEmbed);
          { START(sink__V482, _M_AsText);
            { START(sink__V482, _M_MANGLE);
              COPY(sink__V482, sub__V484);END(sink__V482, _M_MANGLE); }
            END(sink__V482, _M_AsText); }
          END(sink__V482, _M__sTextEmbed); }
        { START(sink__V482, _M__sTextNil);
          END(sink__V482, _M__sTextNil); }
        END(sink__V482, _M__sTextCons); }
      END(sink__V482, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V482->context, namedP__V485); UNLINK_VariablePropertyLink(sink__V482->context, varP__V486);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Struct. */
int conBindOffs_M_Struct[] = {0 , 0};
char *nameFun_M_Struct(Term term) { return  "Struct" ; }
struct _ConstructionDescriptor descriptor_M_Struct = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_Struct), conBindOffs_M_Struct, &nameFun_M_Struct, &step_M_Struct};

int step_M_Struct(Sink sink__V487, Term term__V488)
{
  int term__V488_count = LINK_COUNT(term__V488); permitUnusedInt(term__V488_count);
  do {
    /* Contraction rule DEFS-Struct-1. */
    ASSERT(sink__V487->context, !strcmp(SYMBOL(term__V488),  "Struct" ));
    Term sub__V489 = LINK(sink__V487->context, SUB(term__V488, 0)); int sub__V489_count = term__V488_count*LINK_COUNT(sub__V489); permitUnusedInt(sub__V489_count);
    /* sub__V489 = &#1 */
    NamedPropertyLink namedP__V490 = LINK_NamedPropertyLink(sink__V487->context, NAMED_PROPERTIES(term__V488));
    VariablePropertyLink varP__V491 = LINK_VariablePropertyLink(sink__V487->context, VARIABLE_PROPERTIES(term__V488));
    UNLINK(sink__V487->context, term__V488);
    { START(sink__V487, _M__sTextCons);
      { START(sink__V487, _M__sTextChars);
        LITERAL(sink__V487,  "_Con" ); END(sink__V487, _M__sTextChars); }
      { START(sink__V487, _M__sTextCons);
        { START(sink__V487, _M__sTextEmbed);
          { START(sink__V487, _M_AsText);
            { START(sink__V487, _M_MANGLE);
              COPY(sink__V487, sub__V489);END(sink__V487, _M_MANGLE); }
            END(sink__V487, _M_AsText); }
          END(sink__V487, _M__sTextEmbed); }
        { START(sink__V487, _M__sTextNil);
          END(sink__V487, _M__sTextNil); }
        END(sink__V487, _M__sTextCons); }
      END(sink__V487, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V487->context, namedP__V490); UNLINK_VariablePropertyLink(sink__V487->context, varP__V491);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION BinderOffsets. */
int conBindOffs_M_BinderOffsets[] = {0 , 0};
char *nameFun_M_BinderOffsets(Term term) { return  "BinderOffsets" ; }
struct _ConstructionDescriptor descriptor_M_BinderOffsets = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_BinderOffsets), conBindOffs_M_BinderOffsets, &nameFun_M_BinderOffsets, &step_M_BinderOffsets};

int step_M_BinderOffsets(Sink sink__V492, Term term__V493)
{
  int term__V493_count = LINK_COUNT(term__V493); permitUnusedInt(term__V493_count);
  do {
    /* Contraction rule DEFS-BinderOffsets-1. */
    ASSERT(sink__V492->context, !strcmp(SYMBOL(term__V493),  "BinderOffsets" ));
    Term sub__V494 = LINK(sink__V492->context, SUB(term__V493, 0)); int sub__V494_count = term__V493_count*LINK_COUNT(sub__V494); permitUnusedInt(sub__V494_count);
    /* sub__V494 = &#1 */
    NamedPropertyLink namedP__V495 = LINK_NamedPropertyLink(sink__V492->context, NAMED_PROPERTIES(term__V493));
    VariablePropertyLink varP__V496 = LINK_VariablePropertyLink(sink__V492->context, VARIABLE_PROPERTIES(term__V493));
    UNLINK(sink__V492->context, term__V493);
    { START(sink__V492, _M__sTextCons);
      { START(sink__V492, _M__sTextChars);
        LITERAL(sink__V492,  "conBindOffs" ); END(sink__V492, _M__sTextChars); }
      { START(sink__V492, _M__sTextCons);
        { START(sink__V492, _M__sTextEmbed);
          { START(sink__V492, _M_AsText);
            { START(sink__V492, _M_MANGLE);
              COPY(sink__V492, sub__V494);END(sink__V492, _M_MANGLE); }
            END(sink__V492, _M_AsText); }
          END(sink__V492, _M__sTextEmbed); }
        { START(sink__V492, _M__sTextNil);
          END(sink__V492, _M__sTextNil); }
        END(sink__V492, _M__sTextCons); }
      END(sink__V492, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V492->context, namedP__V495); UNLINK_VariablePropertyLink(sink__V492->context, varP__V496);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION FormArguments-binder-offsets$4. */
int conBindOffs_M_FormArguments__binder__offsets_s4[] = {0 , 0};
char *nameFun_M_FormArguments__binder__offsets_s4(Term term) { return  "FormArguments-binder-offsets$4" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__offsets_s4 = {NULL, 0, 1, sizeof(STRUCT_Con_M_FormArguments__binder__offsets_s4), conBindOffs_M_FormArguments__binder__offsets_s4, &nameFun_M_FormArguments__binder__offsets_s4, &step_M_FormArguments__binder__offsets_s4};

int step_M_FormArguments__binder__offsets_s4(Sink sink__V497, Term term__V498)
{
  int term__V498_count = LINK_COUNT(term__V498); permitUnusedInt(term__V498_count);
  do {
    /* Contraction rule DEFS-FormArguments-binder-offsets-3. */
    ASSERT(sink__V497->context, !strcmp(SYMBOL(term__V498),  "FormArguments-binder-offsets$4" ));
    Term sub__V499 = SUB(term__V498, 0); permitUnusedTerm(sub__V499); int sub__V499_count = term__V498_count*LINK_COUNT(sub__V499); permitUnusedInt(sub__V499_count);
    /* sub__V499 = &#2 */
    UNLINK(sink__V497->context, term__V498);
    { START(sink__V497, _M__sNil); END(sink__V497, _M__sNil); } 
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION FormArguments-binder-offsets$1. */
int conBindOffs_M_FormArguments__binder__offsets_s1[] = {0 , 0 , 0 , 0};
char *nameFun_M_FormArguments__binder__offsets_s1(Term term) { return  "FormArguments-binder-offsets$1" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__offsets_s1 = {NULL, 0, 3, sizeof(STRUCT_Con_M_FormArguments__binder__offsets_s1), conBindOffs_M_FormArguments__binder__offsets_s1, &nameFun_M_FormArguments__binder__offsets_s1, &step_M_FormArguments__binder__offsets_s1};

int step_M_FormArguments__binder__offsets_s1(Sink sink__V500, Term term__V501)
{
  int term__V501_count = LINK_COUNT(term__V501); permitUnusedInt(term__V501_count);
  do {
    /* Contraction rule DEFS-FormArguments-binder-offsets-1$FormArguments-binder-offsets$1$FORM-BINDER. */
    ASSERT(sink__V500->context, !strcmp(SYMBOL(term__V501),  "FormArguments-binder-offsets$1" ));
    Term sub__V502 = SUB(term__V501, 0); permitUnusedTerm(sub__V502); int sub__V502_count = term__V501_count*LINK_COUNT(sub__V502); permitUnusedInt(sub__V502_count);
    FORCE(sink__V500->context, sub__V502); SUB(term__V501, 0) = sub__V502;
    if (strcmp(SYMBOL(sub__V502),  "FORM-BINDER" )) break;
    Term sub__V503 = LINK(sink__V500->context, SUB(sub__V502, 0)); int sub__V503_count = sub__V502_count*LINK_COUNT(sub__V503); permitUnusedInt(sub__V503_count);
    CRSX_CHECK_SORT(sink__V500->context, sub__V503, &sort_M_Reified_xSort); /* sub__V503 = &#0-0 */
    Variable y__V504 = BINDER(sub__V502,1,0); if (sub__V502_count <= 1) UNBIND(y__V504);
    Term sub__V505 = LINK(sink__V500->context, SUB(sub__V502, 1)); int sub__V505_count = sub__V502_count*LINK_COUNT(sub__V505); permitUnusedInt(sub__V505_count);
    CRSX_CHECK_SORT(sink__V500->context, sub__V505, &sort_M_Reified_xFormArgument); /* sub__V505 = &#0-1 */
    Term sub__V506 = LINK(sink__V500->context, SUB(term__V501, 1)); int sub__V506_count = term__V501_count*LINK_COUNT(sub__V506); permitUnusedInt(sub__V506_count);
    /* sub__V506 = &#2 */
    Term sub__V507 = LINK(sink__V500->context, SUB(term__V501, 2)); int sub__V507_count = term__V501_count*LINK_COUNT(sub__V507); permitUnusedInt(sub__V507_count);
    /* sub__V507 = &#3 */
    NamedPropertyLink namedP__V508 = LINK_NamedPropertyLink(sink__V500->context, NAMED_PROPERTIES(term__V501));
    VariablePropertyLink varP__V509 = LINK_VariablePropertyLink(sink__V500->context, VARIABLE_PROPERTIES(term__V501));
    UNLINK(sink__V500->context, term__V501);
    ADD_PROPERTIES(sink__V500, LINK_NamedPropertyLink(sink__V500->context, namedP__V508), LINK_VariablePropertyLink(sink__V500->context, varP__V509));
    { START(sink__V500, _M_FormArguments__binder__offsets_s3);
      COPY(sink__V500, sub__V503);{ if (!IS_BOUND(y__V504)) { REBIND(y__V504);
          Variable binds__V510[1] = {y__V504}; BINDS(sink__V500, 1, binds__V510);
          COPY(sink__V500, sub__V505); /* REUSED SUBSTITUTION */  }
        else { Variable b__V511 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V500->context,"b__V511");
          Variable binds__V512[1] = {b__V511}; BINDS(sink__V500, 1, binds__V512);
          {
            Term arg__V513;
            { Sink buf__V514 = ALLOCA_BUFFER(sink__V500->context);
              USE(buf__V514, b__V511); arg__V513 = BUFFER_TERM(buf__V514); FREE_BUFFER(buf__V514); }
            Variable vars__V515[1] = {y__V504};
            Term args__V516[1] = {arg__V513};
            struct _SubstitutionFrame substitution__V517 = {NULL, 0, 1, vars__V515, args__V516, NULL};
            SUBSTITUTE(sink__V500, sub__V505, &substitution__V517); }
              }
         }
      COPY(sink__V500, sub__V506);COPY(sink__V500, sub__V507);END(sink__V500, _M_FormArguments__binder__offsets_s3); }
    UNLINK_NamedPropertyLink(sink__V500->context, namedP__V508); UNLINK_VariablePropertyLink(sink__V500->context, varP__V509);
    
    return 1;
  } while (0);
  do {
    /* Contraction rule DEFS-FormArguments-binder-offsets-2$FormArguments-binder-offsets$1$FORM-ARGUMENT. */
    ASSERT(sink__V500->context, !strcmp(SYMBOL(term__V501),  "FormArguments-binder-offsets$1" ));
    Term sub__V518 = SUB(term__V501, 0); permitUnusedTerm(sub__V518); int sub__V518_count = term__V501_count*LINK_COUNT(sub__V518); permitUnusedInt(sub__V518_count);
    FORCE(sink__V500->context, sub__V518); SUB(term__V501, 0) = sub__V518;
    if (strcmp(SYMBOL(sub__V518),  "FORM-ARGUMENT" )) break;
    Term sub__V519 = LINK(sink__V500->context, SUB(sub__V518, 0)); int sub__V519_count = sub__V518_count*LINK_COUNT(sub__V519); permitUnusedInt(sub__V519_count);
    CRSX_CHECK_SORT(sink__V500->context, sub__V519, &sort_M_Reified_xSort); /* sub__V519 = &#0-0 */
    Term sub__V520 = LINK(sink__V500->context, SUB(term__V501, 1)); int sub__V520_count = term__V501_count*LINK_COUNT(sub__V520); permitUnusedInt(sub__V520_count);
    /* sub__V520 = &#1 */
    Term sub__V521 = LINK(sink__V500->context, SUB(term__V501, 2)); int sub__V521_count = term__V501_count*LINK_COUNT(sub__V521); permitUnusedInt(sub__V521_count);
    /* sub__V521 = &#2 */
    NamedPropertyLink namedP__V522 = LINK_NamedPropertyLink(sink__V500->context, NAMED_PROPERTIES(term__V501));
    VariablePropertyLink varP__V523 = LINK_VariablePropertyLink(sink__V500->context, VARIABLE_PROPERTIES(term__V501));
    UNLINK(sink__V500->context, term__V501);
    ADD_PROPERTIES(sink__V500, LINK_NamedPropertyLink(sink__V500->context, namedP__V522), LINK_VariablePropertyLink(sink__V500->context, varP__V523));
    { START(sink__V500, _M_FormArguments__binder__offsets_s2);
      COPY(sink__V500, sub__V519);COPY(sink__V500, sub__V520);COPY(sink__V500, sub__V521);END(sink__V500, _M_FormArguments__binder__offsets_s2); }
    UNLINK_NamedPropertyLink(sink__V500->context, namedP__V522); UNLINK_VariablePropertyLink(sink__V500->context, varP__V523);
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION FormArguments-binder-offsets$3. */
int conBindOffs_M_FormArguments__binder__offsets_s3[] = {0 , 0 , 1 , 1 , 1};
char *nameFun_M_FormArguments__binder__offsets_s3(Term term) { return  "FormArguments-binder-offsets$3" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__offsets_s3 = {NULL, 0, 4, sizeof(STRUCT_Con_M_FormArguments__binder__offsets_s3), conBindOffs_M_FormArguments__binder__offsets_s3, &nameFun_M_FormArguments__binder__offsets_s3, &step_M_FormArguments__binder__offsets_s3};

int step_M_FormArguments__binder__offsets_s3(Sink sink__V524, Term term__V525)
{
  int term__V525_count = LINK_COUNT(term__V525); permitUnusedInt(term__V525_count);
  do {
    /* Contraction rule DEFS-FormArguments-binder-offsets-1. */
    ASSERT(sink__V524->context, !strcmp(SYMBOL(term__V525),  "FormArguments-binder-offsets$3" ));
    Term sub__V526 = SUB(term__V525, 0); permitUnusedTerm(sub__V526); int sub__V526_count = term__V525_count*LINK_COUNT(sub__V526); permitUnusedInt(sub__V526_count);
    CRSX_CHECK_SORT(sink__V524->context, sub__V526, &sort_M_Reified_xSort); /* sub__V526 = &#111 */
    Variable x__V527 = BINDER(term__V525,1,0); if (term__V525_count <= 1) UNBIND(x__V527);
    Term sub__V528 = LINK(sink__V524->context, SUB(term__V525, 1)); int sub__V528_count = term__V525_count*LINK_COUNT(sub__V528); permitUnusedInt(sub__V528_count);
    CRSX_CHECK_SORT(sink__V524->context, sub__V528, &sort_M_Reified_xFormArgument); /* sub__V528 = &#112 */
    Variable y__V529 = x__V527; permitUnusedVariable(y__V529);
    Term sub__V530 = LINK(sink__V524->context, SUB(term__V525, 2)); int sub__V530_count = term__V525_count*LINK_COUNT(sub__V530); permitUnusedInt(sub__V530_count);
    /* sub__V530 = &#12 */
    Term sub__V531 = LINK(sink__V524->context, SUB(term__V525, 3)); int sub__V531_count = term__V525_count*LINK_COUNT(sub__V531); permitUnusedInt(sub__V531_count);
    /* sub__V531 = &#2 */
    UNLINK(sink__V524->context, term__V525);
    { START(sink__V524, _M_FormArguments__binder__offsets);
      { START(sink__V524, _M__sCons);
        COPY(sink__V524, sub__V528); /* REUSED SUBSTITUTION */ COPY(sink__V524, sub__V530);END(sink__V524, _M__sCons); }
      { double num__V532;
        num__V532 = (double) 1; { double tmp__V533;
          tmp__V533 = DOUBLE(sub__V531); num__V532 += tmp__V533; }
        LITERALNF(sink__V524, (size_t) 31, "%G", num__V532); }
      END(sink__V524, _M_FormArguments__binder__offsets); }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION FormArguments-binder-offsets$2. */
int conBindOffs_M_FormArguments__binder__offsets_s2[] = {0 , 0 , 0 , 0};
char *nameFun_M_FormArguments__binder__offsets_s2(Term term) { return  "FormArguments-binder-offsets$2" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__offsets_s2 = {NULL, 0, 3, sizeof(STRUCT_Con_M_FormArguments__binder__offsets_s2), conBindOffs_M_FormArguments__binder__offsets_s2, &nameFun_M_FormArguments__binder__offsets_s2, &step_M_FormArguments__binder__offsets_s2};

int step_M_FormArguments__binder__offsets_s2(Sink sink__V534, Term term__V535)
{
  int term__V535_count = LINK_COUNT(term__V535); permitUnusedInt(term__V535_count);
  do {
    /* Contraction rule DEFS-FormArguments-binder-offsets-2. */
    ASSERT(sink__V534->context, !strcmp(SYMBOL(term__V535),  "FormArguments-binder-offsets$2" ));
    Term sub__V536 = SUB(term__V535, 0); permitUnusedTerm(sub__V536); int sub__V536_count = term__V535_count*LINK_COUNT(sub__V536); permitUnusedInt(sub__V536_count);
    CRSX_CHECK_SORT(sink__V534->context, sub__V536, &sort_M_Reified_xSort); /* sub__V536 = &#111 */
    Term sub__V537 = LINK(sink__V534->context, SUB(term__V535, 1)); int sub__V537_count = term__V535_count*LINK_COUNT(sub__V537); permitUnusedInt(sub__V537_count);
    /* sub__V537 = &#12 */
    Term sub__V538 = LINK(sink__V534->context, SUB(term__V535, 2)); int sub__V538_count = term__V535_count*LINK_COUNT(sub__V538); permitUnusedInt(sub__V538_count);
    /* sub__V538 = &#2 */
    UNLINK(sink__V534->context, term__V535);
    { START(sink__V534, _M__sCons);
      COPY(sink__V534, LINK(sink__V534->context, sub__V538));{ START(sink__V534, _M_FormArguments__binder__offsets);
        COPY(sink__V534, sub__V537);COPY(sink__V534, sub__V538);END(sink__V534, _M_FormArguments__binder__offsets); }
      END(sink__V534, _M__sCons); }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Var. */
int conBindOffs_M_Var[] = {0 , 0};
char *nameFun_M_Var(Term term) { return  "Var" ; }
struct _ConstructionDescriptor descriptor_M_Var = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_Var), conBindOffs_M_Var, &nameFun_M_Var, &step_M_Var};

int step_M_Var(Sink sink__V539, Term term__V540)
{
  int term__V540_count = LINK_COUNT(term__V540); permitUnusedInt(term__V540_count);
  do {
    /* Contraction rule DEFS-Var-1. */
    ASSERT(sink__V539->context, !strcmp(SYMBOL(term__V540),  "Var" ));
    Term sub__V541 = LINK(sink__V539->context, SUB(term__V540, 0)); int sub__V541_count = term__V540_count*LINK_COUNT(sub__V541); permitUnusedInt(sub__V541_count);
    /* sub__V541 = &#1 */
    NamedPropertyLink namedP__V542 = LINK_NamedPropertyLink(sink__V539->context, NAMED_PROPERTIES(term__V540));
    VariablePropertyLink varP__V543 = LINK_VariablePropertyLink(sink__V539->context, VARIABLE_PROPERTIES(term__V540));
    UNLINK(sink__V539->context, term__V540);
    { START(sink__V539, _M__sTextCons);
      { START(sink__V539, _M__sTextChars);
        LITERAL(sink__V539,  "v" ); END(sink__V539, _M__sTextChars); }
      { START(sink__V539, _M__sTextCons);
        { START(sink__V539, _M__sTextEmbed);
          { START(sink__V539, _M_AsText);
            { START(sink__V539, _M_MANGLE);
              COPY(sink__V539, sub__V541);END(sink__V539, _M_MANGLE); }
            END(sink__V539, _M_AsText); }
          END(sink__V539, _M__sTextEmbed); }
        { START(sink__V539, _M__sTextNil);
          END(sink__V539, _M__sTextNil); }
        END(sink__V539, _M__sTextCons); }
      END(sink__V539, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V539->context, namedP__V542); UNLINK_VariablePropertyLink(sink__V539->context, varP__V543);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Enum. */
int conBindOffs_M_Enum[] = {0 , 0};
char *nameFun_M_Enum(Term term) { return  "Enum" ; }
struct _ConstructionDescriptor descriptor_M_Enum = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_Enum), conBindOffs_M_Enum, &nameFun_M_Enum, &step_M_Enum};

int step_M_Enum(Sink sink__V544, Term term__V545)
{
  int term__V545_count = LINK_COUNT(term__V545); permitUnusedInt(term__V545_count);
  do {
    /* Contraction rule DEFS-Enum-1. */
    ASSERT(sink__V544->context, !strcmp(SYMBOL(term__V545),  "Enum" ));
    Term sub__V546 = LINK(sink__V544->context, SUB(term__V545, 0)); int sub__V546_count = term__V545_count*LINK_COUNT(sub__V546); permitUnusedInt(sub__V546_count);
    /* sub__V546 = &#1 */
    NamedPropertyLink namedP__V547 = LINK_NamedPropertyLink(sink__V544->context, NAMED_PROPERTIES(term__V545));
    VariablePropertyLink varP__V548 = LINK_VariablePropertyLink(sink__V544->context, VARIABLE_PROPERTIES(term__V545));
    UNLINK(sink__V544->context, term__V545);
    { START(sink__V544, _M__sTextCons);
      { START(sink__V544, _M__sTextChars);
        LITERAL(sink__V544,  "EnumOf" ); END(sink__V544, _M__sTextChars); }
      { START(sink__V544, _M__sTextCons);
        { START(sink__V544, _M__sTextEmbed);
          { START(sink__V544, _M_AsText);
            { START(sink__V544, _M_MANGLE);
              COPY(sink__V544, sub__V546);END(sink__V544, _M_MANGLE); }
            END(sink__V544, _M_AsText); }
          END(sink__V544, _M__sTextEmbed); }
        { START(sink__V544, _M__sTextNil);
          END(sink__V544, _M__sTextNil); }
        END(sink__V544, _M__sTextCons); }
      END(sink__V544, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V544->context, namedP__V547); UNLINK_VariablePropertyLink(sink__V544->context, varP__V548);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION If. */
int conBindOffs_M_If[] = {0 , 0 , 0 , 0};
char *nameFun_M_If(Term term) { return  "If" ; }
struct _ConstructionDescriptor descriptor_M_If = {NULL, 0, 3, sizeof(STRUCT_Con_M_If), conBindOffs_M_If, &nameFun_M_If, &step_M_If};

int step_M_If(Sink sink__V549, Term term__V550)
{
  int term__V550_count = LINK_COUNT(term__V550); permitUnusedInt(term__V550_count);
  Term sub__V551 = FORCE(sink__V549->context, SUB(term__V550, 0));
  EnumOf_M__sBoolean choice__V552 = (IS_VARIABLE_USE(sub__V551) ? VarOf_M__sBoolean : (EnumOf_M__sBoolean) TAG(sub__V551));
  switch (choice__V552)
  {
    case Data_M__sTrue: { /* Function DEFS-If-1$If$$True case $True */
      ASSERT(sink__V549->context, !strcmp(SYMBOL(term__V550),  "If" ));
      Term sub__V553 = SUB(term__V550, 0); permitUnusedTerm(sub__V553); int sub__V553_count = term__V550_count*LINK_COUNT(sub__V553); permitUnusedInt(sub__V553_count);
      ASSERT(sink__V549->context, !strcmp(SYMBOL(sub__V553),  "$True" ));
      Term sub__V554 = LINK(sink__V549->context, SUB(term__V550, 1)); int sub__V554_count = term__V550_count*LINK_COUNT(sub__V554); permitUnusedInt(sub__V554_count);
      /* sub__V554 = &#0 */
      Term sub__V555 = LINK(sink__V549->context, SUB(term__V550, 2)); int sub__V555_count = term__V550_count*LINK_COUNT(sub__V555); permitUnusedInt(sub__V555_count);
      /* sub__V555 = &#1 */
      NamedPropertyLink namedP__V556 = LINK_NamedPropertyLink(sink__V549->context, NAMED_PROPERTIES(term__V550));
      VariablePropertyLink varP__V557 = LINK_VariablePropertyLink(sink__V549->context, VARIABLE_PROPERTIES(term__V550));
      UNLINK(sink__V549->context, term__V550);
      ADD_PROPERTIES(sink__V549, LINK_NamedPropertyLink(sink__V549->context, namedP__V556), LINK_VariablePropertyLink(sink__V549->context, varP__V557));
      { START(sink__V549, _M_If_s2);
        COPY(sink__V549, sub__V554);COPY(sink__V549, sub__V555);END(sink__V549, _M_If_s2); }
      UNLINK_NamedPropertyLink(sink__V549->context, namedP__V556); UNLINK_VariablePropertyLink(sink__V549->context, varP__V557);
      
      return 1;
    break; } case Data_M__sFalse: { /* Function DEFS-If-2$If$$False case $False */
      ASSERT(sink__V549->context, !strcmp(SYMBOL(term__V550),  "If" ));
      Term sub__V558 = SUB(term__V550, 0); permitUnusedTerm(sub__V558); int sub__V558_count = term__V550_count*LINK_COUNT(sub__V558); permitUnusedInt(sub__V558_count);
      ASSERT(sink__V549->context, !strcmp(SYMBOL(sub__V558),  "$False" ));
      Term sub__V559 = LINK(sink__V549->context, SUB(term__V550, 1)); int sub__V559_count = term__V550_count*LINK_COUNT(sub__V559); permitUnusedInt(sub__V559_count);
      /* sub__V559 = &#0 */
      Term sub__V560 = LINK(sink__V549->context, SUB(term__V550, 2)); int sub__V560_count = term__V550_count*LINK_COUNT(sub__V560); permitUnusedInt(sub__V560_count);
      /* sub__V560 = &#1 */
      NamedPropertyLink namedP__V561 = LINK_NamedPropertyLink(sink__V549->context, NAMED_PROPERTIES(term__V550));
      VariablePropertyLink varP__V562 = LINK_VariablePropertyLink(sink__V549->context, VARIABLE_PROPERTIES(term__V550));
      UNLINK(sink__V549->context, term__V550);
      ADD_PROPERTIES(sink__V549, LINK_NamedPropertyLink(sink__V549->context, namedP__V561), LINK_VariablePropertyLink(sink__V549->context, varP__V562));
      { START(sink__V549, _M_If_s1);
        COPY(sink__V549, sub__V559);COPY(sink__V549, sub__V560);END(sink__V549, _M_If_s1); }
      UNLINK_NamedPropertyLink(sink__V549->context, namedP__V561); UNLINK_VariablePropertyLink(sink__V549->context, varP__V562);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION DEnumTag. */
int conBindOffs_M_DEnumTag[] = {0 , 0 , 0};
char *nameFun_M_DEnumTag(Term term) { return  "DEnumTag" ; }
struct _ConstructionDescriptor descriptor_M_DEnumTag = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_DEnumTag), conBindOffs_M_DEnumTag, &nameFun_M_DEnumTag, &step_M_DEnumTag};

int step_M_DEnumTag(Sink sink__V563, Term term__V564)
{
  int term__V564_count = LINK_COUNT(term__V564); permitUnusedInt(term__V564_count);
  Term sub__V565 = FORCE(sink__V563->context, SUB(term__V564, 0));
  EnumOf_M_OK_xSORT choice__V566 = (IS_VARIABLE_USE(sub__V565) ? VarOf_M_OK_xSORT : (EnumOf_M_OK_xSORT) TAG(sub__V565));
  switch (choice__V566)
  {
    case Data_M_OK: { /* Function DEFS-DEnumTag-1$DEnumTag$OK case OK */
      ASSERT(sink__V563->context, !strcmp(SYMBOL(term__V564),  "DEnumTag" ));
      Term sub__V567 = SUB(term__V564, 0); permitUnusedTerm(sub__V567); int sub__V567_count = term__V564_count*LINK_COUNT(sub__V567); permitUnusedInt(sub__V567_count);
      CRSX_CHECK_SORT(sink__V563->context, sub__V567, &sort_M_OK_xSORT); ASSERT(sink__V563->context, !strcmp(SYMBOL(sub__V567),  "OK" ));
      Term sub__V568 = LINK(sink__V563->context, SUB(term__V564, 1)); int sub__V568_count = term__V564_count*LINK_COUNT(sub__V568); permitUnusedInt(sub__V568_count);
      /* sub__V568 = &#0 */
      NamedPropertyLink namedP__V569 = LINK_NamedPropertyLink(sink__V563->context, NAMED_PROPERTIES(term__V564));
      VariablePropertyLink varP__V570 = LINK_VariablePropertyLink(sink__V563->context, VARIABLE_PROPERTIES(term__V564));
      UNLINK(sink__V563->context, term__V564);
      ADD_PROPERTIES(sink__V563, LINK_NamedPropertyLink(sink__V563->context, namedP__V569), LINK_VariablePropertyLink(sink__V563->context, varP__V570));
      { START(sink__V563, _M_DEnumTag_s1);
        COPY(sink__V563, sub__V568);END(sink__V563, _M_DEnumTag_s1); }
      UNLINK_NamedPropertyLink(sink__V563->context, namedP__V569); UNLINK_VariablePropertyLink(sink__V563->context, varP__V570);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION Forms-Constructors. */
int conBindOffs_M_Forms_Constructors[] = {0 , 0};
char *nameFun_M_Forms_Constructors(Term term) { return  "Forms-Constructors" ; }
struct _ConstructionDescriptor descriptor_M_Forms_Constructors = {NULL, 0, 1, sizeof(STRUCT_Con_M_Forms_Constructors), conBindOffs_M_Forms_Constructors, &nameFun_M_Forms_Constructors, &step_M_Forms_Constructors};

int step_M_Forms_Constructors(Sink sink__V571, Term term__V572)
{
  int term__V572_count = LINK_COUNT(term__V572); permitUnusedInt(term__V572_count);
  Term sub__V573 = FORCE(sink__V571->context, SUB(term__V572, 0));
  EnumOf_M__sList choice__V574 = (IS_VARIABLE_USE(sub__V573) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V573));
  switch (choice__V574)
  {
    case Data_M__sCons: { /* Function DEFS-Forms-Constructors-3$Forms-Constructors$$Cons case $Cons */
      ASSERT(sink__V571->context, !strcmp(SYMBOL(term__V572),  "Forms-Constructors" ));
      Term sub__V575 = SUB(term__V572, 0); permitUnusedTerm(sub__V575); int sub__V575_count = term__V572_count*LINK_COUNT(sub__V575); permitUnusedInt(sub__V575_count);
      ASSERT(sink__V571->context, !strcmp(SYMBOL(sub__V575),  "$Cons" ));
      Term sub__V576 = LINK(sink__V571->context, SUB(sub__V575, 0)); int sub__V576_count = sub__V575_count*LINK_COUNT(sub__V576); permitUnusedInt(sub__V576_count);
      /* sub__V576 = &#0-0 */
      Term sub__V577 = LINK(sink__V571->context, SUB(sub__V575, 1)); int sub__V577_count = sub__V575_count*LINK_COUNT(sub__V577); permitUnusedInt(sub__V577_count);
      /* sub__V577 = &#0-1 */
      NamedPropertyLink namedP__V578 = LINK_NamedPropertyLink(sink__V571->context, NAMED_PROPERTIES(term__V572));
      VariablePropertyLink varP__V579 = LINK_VariablePropertyLink(sink__V571->context, VARIABLE_PROPERTIES(term__V572));
      UNLINK(sink__V571->context, term__V572);
      ADD_PROPERTIES(sink__V571, LINK_NamedPropertyLink(sink__V571->context, namedP__V578), LINK_VariablePropertyLink(sink__V571->context, varP__V579));
      { START(sink__V571, _M_Forms_Constructors_s1);
        COPY(sink__V571, sub__V576);COPY(sink__V571, sub__V577);END(sink__V571, _M_Forms_Constructors_s1); }
      UNLINK_NamedPropertyLink(sink__V571->context, namedP__V578); UNLINK_VariablePropertyLink(sink__V571->context, varP__V579);
      
      return 1;
    break; } case Data_M__sNil: { /* Function DEFS-Forms-Constructors-4$Forms-Constructors$$Nil case $Nil */
      ASSERT(sink__V571->context, !strcmp(SYMBOL(term__V572),  "Forms-Constructors" ));
      Term sub__V580 = SUB(term__V572, 0); permitUnusedTerm(sub__V580); int sub__V580_count = term__V572_count*LINK_COUNT(sub__V580); permitUnusedInt(sub__V580_count);
      ASSERT(sink__V571->context, !strcmp(SYMBOL(sub__V580),  "$Nil" ));
      NamedPropertyLink namedP__V581 = LINK_NamedPropertyLink(sink__V571->context, NAMED_PROPERTIES(term__V572));
      VariablePropertyLink varP__V582 = LINK_VariablePropertyLink(sink__V571->context, VARIABLE_PROPERTIES(term__V572));
      UNLINK(sink__V571->context, term__V572);
      ADD_PROPERTIES(sink__V571, LINK_NamedPropertyLink(sink__V571->context, namedP__V581), LINK_VariablePropertyLink(sink__V571->context, varP__V582));
      { START(sink__V571, _M_Forms_Constructors_s5);
        END(sink__V571, _M_Forms_Constructors_s5); }
      UNLINK_NamedPropertyLink(sink__V571->context, namedP__V581); UNLINK_VariablePropertyLink(sink__V571->context, varP__V582);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION DDescriptor. */
int conBindOffs_M_DDescriptor[] = {0 , 0 , 0};
char *nameFun_M_DDescriptor(Term term) { return  "DDescriptor" ; }
struct _ConstructionDescriptor descriptor_M_DDescriptor = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_DDescriptor), conBindOffs_M_DDescriptor, &nameFun_M_DDescriptor, &step_M_DDescriptor};

int step_M_DDescriptor(Sink sink__V583, Term term__V584)
{
  int term__V584_count = LINK_COUNT(term__V584); permitUnusedInt(term__V584_count);
  Term sub__V585 = FORCE(sink__V583->context, SUB(term__V584, 0));
  EnumOf_M_OK_xSORT choice__V586 = (IS_VARIABLE_USE(sub__V585) ? VarOf_M_OK_xSORT : (EnumOf_M_OK_xSORT) TAG(sub__V585));
  switch (choice__V586)
  {
    case Data_M_OK: { /* Function DEFS-DDescriptor-1$DDescriptor$OK case OK */
      ASSERT(sink__V583->context, !strcmp(SYMBOL(term__V584),  "DDescriptor" ));
      Term sub__V587 = SUB(term__V584, 0); permitUnusedTerm(sub__V587); int sub__V587_count = term__V584_count*LINK_COUNT(sub__V587); permitUnusedInt(sub__V587_count);
      CRSX_CHECK_SORT(sink__V583->context, sub__V587, &sort_M_OK_xSORT); ASSERT(sink__V583->context, !strcmp(SYMBOL(sub__V587),  "OK" ));
      Term sub__V588 = LINK(sink__V583->context, SUB(term__V584, 1)); int sub__V588_count = term__V584_count*LINK_COUNT(sub__V588); permitUnusedInt(sub__V588_count);
      /* sub__V588 = &#0 */
      NamedPropertyLink namedP__V589 = LINK_NamedPropertyLink(sink__V583->context, NAMED_PROPERTIES(term__V584));
      VariablePropertyLink varP__V590 = LINK_VariablePropertyLink(sink__V583->context, VARIABLE_PROPERTIES(term__V584));
      UNLINK(sink__V583->context, term__V584);
      ADD_PROPERTIES(sink__V583, LINK_NamedPropertyLink(sink__V583->context, namedP__V589), LINK_VariablePropertyLink(sink__V583->context, varP__V590));
      { START(sink__V583, _M_DDescriptor_s1);
        COPY(sink__V583, sub__V588);END(sink__V583, _M_DDescriptor_s1); }
      UNLINK_NamedPropertyLink(sink__V583->context, namedP__V589); UNLINK_VariablePropertyLink(sink__V583->context, varP__V590);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION PromiscuityString$1. */
int conBindOffs_M_PromiscuityString_s1[] = {0};
char *nameFun_M_PromiscuityString_s1(Term term) { return  "PromiscuityString$1" ; }
struct _ConstructionDescriptor descriptor_M_PromiscuityString_s1 = {NULL, 0, 0, sizeof(STRUCT_Con_M_PromiscuityString_s1), conBindOffs_M_PromiscuityString_s1, &nameFun_M_PromiscuityString_s1, &step_M_PromiscuityString_s1};

int step_M_PromiscuityString_s1(Sink sink__V591, Term term__V592)
{
  int term__V592_count = LINK_COUNT(term__V592); permitUnusedInt(term__V592_count);
  do {
    /* Contraction rule DEFS-PromiscuityString-1. */
    ASSERT(sink__V591->context, !strcmp(SYMBOL(term__V592),  "PromiscuityString$1" ));
    UNLINK(sink__V591->context, term__V592);
    LITERAL(sink__V591,  "LINEAR" ); 
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION PromiscuityString$2. */
int conBindOffs_M_PromiscuityString_s2[] = {0};
char *nameFun_M_PromiscuityString_s2(Term term) { return  "PromiscuityString$2" ; }
struct _ConstructionDescriptor descriptor_M_PromiscuityString_s2 = {NULL, 0, 0, sizeof(STRUCT_Con_M_PromiscuityString_s2), conBindOffs_M_PromiscuityString_s2, &nameFun_M_PromiscuityString_s2, &step_M_PromiscuityString_s2};

int step_M_PromiscuityString_s2(Sink sink__V593, Term term__V594)
{
  int term__V594_count = LINK_COUNT(term__V594); permitUnusedInt(term__V594_count);
  do {
    /* Contraction rule DEFS-PromiscuityString-2. */
    ASSERT(sink__V593->context, !strcmp(SYMBOL(term__V594),  "PromiscuityString$2" ));
    UNLINK(sink__V593->context, term__V594);
    LITERAL(sink__V593,  "PROMISCUOUS" ); 
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION SortCons. */
int conBindOffs_M_SortCons[] = {0 , 0};
char *nameFun_M_SortCons(Term term) { return  "SortCons" ; }
struct _ConstructionDescriptor descriptor_M_SortCons = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_SortCons), conBindOffs_M_SortCons, &nameFun_M_SortCons, &step_M_SortCons};

int step_M_SortCons(Sink sink__V595, Term term__V596)
{
  int term__V596_count = LINK_COUNT(term__V596); permitUnusedInt(term__V596_count);
  do {
    /* Contraction rule DEFS-SortCons-1. */
    ASSERT(sink__V595->context, !strcmp(SYMBOL(term__V596),  "SortCons" ));
    Term sub__V597 = LINK(sink__V595->context, SUB(term__V596, 0)); int sub__V597_count = term__V596_count*LINK_COUNT(sub__V597); permitUnusedInt(sub__V597_count);
    /* sub__V597 = &#1 */
    NamedPropertyLink namedP__V598 = LINK_NamedPropertyLink(sink__V595->context, NAMED_PROPERTIES(term__V596));
    VariablePropertyLink varP__V599 = LINK_VariablePropertyLink(sink__V595->context, VARIABLE_PROPERTIES(term__V596));
    UNLINK(sink__V595->context, term__V596);
    { START(sink__V595, _M__sTextCons);
      { START(sink__V595, _M__sTextChars);
        LITERAL(sink__V595,  "sortCon" ); END(sink__V595, _M__sTextChars); }
      { START(sink__V595, _M__sTextCons);
        { START(sink__V595, _M__sTextEmbed);
          { START(sink__V595, _M_AsText);
            { START(sink__V595, _M_MANGLE);
              COPY(sink__V595, sub__V597);END(sink__V595, _M_MANGLE); }
            END(sink__V595, _M_AsText); }
          END(sink__V595, _M__sTextEmbed); }
        { START(sink__V595, _M__sTextNil);
          END(sink__V595, _M__sTextNil); }
        END(sink__V595, _M__sTextCons); }
      END(sink__V595, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V595->context, namedP__V598); UNLINK_VariablePropertyLink(sink__V595->context, varP__V599);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION FormArguments-binder-count$4. */
int conBindOffs_M_FormArguments__binder__count_s4[] = {0 , 0};
char *nameFun_M_FormArguments__binder__count_s4(Term term) { return  "FormArguments-binder-count$4" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__count_s4 = {NULL, 0, 1, sizeof(STRUCT_Con_M_FormArguments__binder__count_s4), conBindOffs_M_FormArguments__binder__count_s4, &nameFun_M_FormArguments__binder__count_s4, &step_M_FormArguments__binder__count_s4};

int step_M_FormArguments__binder__count_s4(Sink sink__V600, Term term__V601)
{
  int term__V601_count = LINK_COUNT(term__V601); permitUnusedInt(term__V601_count);
  do {
    /* Contraction rule DEFS-FormArguments-binder-count-3. */
    ASSERT(sink__V600->context, !strcmp(SYMBOL(term__V601),  "FormArguments-binder-count$4" ));
    Term sub__V602 = LINK(sink__V600->context, SUB(term__V601, 0)); int sub__V602_count = term__V601_count*LINK_COUNT(sub__V602); permitUnusedInt(sub__V602_count);
    /* sub__V602 = &#2 */
    UNLINK(sink__V600->context, term__V601);
    COPY(sink__V600, sub__V602);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION FormArguments-binder-count$3. */
int conBindOffs_M_FormArguments__binder__count_s3[] = {0 , 0 , 1 , 1 , 1};
char *nameFun_M_FormArguments__binder__count_s3(Term term) { return  "FormArguments-binder-count$3" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__count_s3 = {NULL, 0, 4, sizeof(STRUCT_Con_M_FormArguments__binder__count_s3), conBindOffs_M_FormArguments__binder__count_s3, &nameFun_M_FormArguments__binder__count_s3, &step_M_FormArguments__binder__count_s3};

int step_M_FormArguments__binder__count_s3(Sink sink__V603, Term term__V604)
{
  int term__V604_count = LINK_COUNT(term__V604); permitUnusedInt(term__V604_count);
  do {
    /* Contraction rule DEFS-FormArguments-binder-count-1. */
    ASSERT(sink__V603->context, !strcmp(SYMBOL(term__V604),  "FormArguments-binder-count$3" ));
    Term sub__V605 = SUB(term__V604, 0); permitUnusedTerm(sub__V605); int sub__V605_count = term__V604_count*LINK_COUNT(sub__V605); permitUnusedInt(sub__V605_count);
    CRSX_CHECK_SORT(sink__V603->context, sub__V605, &sort_M_Reified_xSort); /* sub__V605 = &#111 */
    Variable x__V606 = BINDER(term__V604,1,0); if (term__V604_count <= 1) UNBIND(x__V606);
    Term sub__V607 = LINK(sink__V603->context, SUB(term__V604, 1)); int sub__V607_count = term__V604_count*LINK_COUNT(sub__V607); permitUnusedInt(sub__V607_count);
    CRSX_CHECK_SORT(sink__V603->context, sub__V607, &sort_M_Reified_xFormArgument); /* sub__V607 = &#112 */
    Variable y__V529 = x__V606; permitUnusedVariable(y__V529);
    Term sub__V608 = LINK(sink__V603->context, SUB(term__V604, 2)); int sub__V608_count = term__V604_count*LINK_COUNT(sub__V608); permitUnusedInt(sub__V608_count);
    /* sub__V608 = &#12 */
    Term sub__V609 = LINK(sink__V603->context, SUB(term__V604, 3)); int sub__V609_count = term__V604_count*LINK_COUNT(sub__V609); permitUnusedInt(sub__V609_count);
    /* sub__V609 = &#2 */
    UNLINK(sink__V603->context, term__V604);
    { START(sink__V603, _M_FormArguments__binder__count);
      { START(sink__V603, _M__sCons);
        COPY(sink__V603, sub__V607); /* REUSED SUBSTITUTION */ COPY(sink__V603, sub__V608);END(sink__V603, _M__sCons); }
      { double num__V610;
        num__V610 = (double) 1; { double tmp__V611;
          tmp__V611 = DOUBLE(sub__V609); num__V610 += tmp__V611; }
        LITERALNF(sink__V603, (size_t) 31, "%G", num__V610); }
      END(sink__V603, _M_FormArguments__binder__count); }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION FormArguments-binder-count$2. */
int conBindOffs_M_FormArguments__binder__count_s2[] = {0 , 0 , 0 , 0};
char *nameFun_M_FormArguments__binder__count_s2(Term term) { return  "FormArguments-binder-count$2" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__count_s2 = {NULL, 0, 3, sizeof(STRUCT_Con_M_FormArguments__binder__count_s2), conBindOffs_M_FormArguments__binder__count_s2, &nameFun_M_FormArguments__binder__count_s2, &step_M_FormArguments__binder__count_s2};

int step_M_FormArguments__binder__count_s2(Sink sink__V612, Term term__V613)
{
  int term__V613_count = LINK_COUNT(term__V613); permitUnusedInt(term__V613_count);
  do {
    /* Contraction rule DEFS-FormArguments-binder-count-2. */
    ASSERT(sink__V612->context, !strcmp(SYMBOL(term__V613),  "FormArguments-binder-count$2" ));
    Term sub__V614 = SUB(term__V613, 0); permitUnusedTerm(sub__V614); int sub__V614_count = term__V613_count*LINK_COUNT(sub__V614); permitUnusedInt(sub__V614_count);
    CRSX_CHECK_SORT(sink__V612->context, sub__V614, &sort_M_Reified_xSort); /* sub__V614 = &#111 */
    Term sub__V615 = LINK(sink__V612->context, SUB(term__V613, 1)); int sub__V615_count = term__V613_count*LINK_COUNT(sub__V615); permitUnusedInt(sub__V615_count);
    /* sub__V615 = &#12 */
    Term sub__V616 = LINK(sink__V612->context, SUB(term__V613, 2)); int sub__V616_count = term__V613_count*LINK_COUNT(sub__V616); permitUnusedInt(sub__V616_count);
    /* sub__V616 = &#2 */
    UNLINK(sink__V612->context, term__V613);
    { START(sink__V612, _M_FormArguments__binder__count);
      COPY(sink__V612, sub__V615);COPY(sink__V612, sub__V616);END(sink__V612, _M_FormArguments__binder__count); }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION FormArguments-binder-count$1. */
int conBindOffs_M_FormArguments__binder__count_s1[] = {0 , 0 , 0 , 0};
char *nameFun_M_FormArguments__binder__count_s1(Term term) { return  "FormArguments-binder-count$1" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__count_s1 = {NULL, 0, 3, sizeof(STRUCT_Con_M_FormArguments__binder__count_s1), conBindOffs_M_FormArguments__binder__count_s1, &nameFun_M_FormArguments__binder__count_s1, &step_M_FormArguments__binder__count_s1};

int step_M_FormArguments__binder__count_s1(Sink sink__V617, Term term__V618)
{
  int term__V618_count = LINK_COUNT(term__V618); permitUnusedInt(term__V618_count);
  do {
    /* Contraction rule DEFS-FormArguments-binder-count-1$FormArguments-binder-count$1$FORM-BINDER. */
    ASSERT(sink__V617->context, !strcmp(SYMBOL(term__V618),  "FormArguments-binder-count$1" ));
    Term sub__V619 = SUB(term__V618, 0); permitUnusedTerm(sub__V619); int sub__V619_count = term__V618_count*LINK_COUNT(sub__V619); permitUnusedInt(sub__V619_count);
    FORCE(sink__V617->context, sub__V619); SUB(term__V618, 0) = sub__V619;
    if (strcmp(SYMBOL(sub__V619),  "FORM-BINDER" )) break;
    Term sub__V620 = LINK(sink__V617->context, SUB(sub__V619, 0)); int sub__V620_count = sub__V619_count*LINK_COUNT(sub__V620); permitUnusedInt(sub__V620_count);
    CRSX_CHECK_SORT(sink__V617->context, sub__V620, &sort_M_Reified_xSort); /* sub__V620 = &#0-0 */
    Variable y__V621 = BINDER(sub__V619,1,0); if (sub__V619_count <= 1) UNBIND(y__V621);
    Term sub__V622 = LINK(sink__V617->context, SUB(sub__V619, 1)); int sub__V622_count = sub__V619_count*LINK_COUNT(sub__V622); permitUnusedInt(sub__V622_count);
    CRSX_CHECK_SORT(sink__V617->context, sub__V622, &sort_M_Reified_xFormArgument); /* sub__V622 = &#0-1 */
    Term sub__V623 = LINK(sink__V617->context, SUB(term__V618, 1)); int sub__V623_count = term__V618_count*LINK_COUNT(sub__V623); permitUnusedInt(sub__V623_count);
    /* sub__V623 = &#2 */
    Term sub__V624 = LINK(sink__V617->context, SUB(term__V618, 2)); int sub__V624_count = term__V618_count*LINK_COUNT(sub__V624); permitUnusedInt(sub__V624_count);
    /* sub__V624 = &#3 */
    NamedPropertyLink namedP__V625 = LINK_NamedPropertyLink(sink__V617->context, NAMED_PROPERTIES(term__V618));
    VariablePropertyLink varP__V626 = LINK_VariablePropertyLink(sink__V617->context, VARIABLE_PROPERTIES(term__V618));
    UNLINK(sink__V617->context, term__V618);
    ADD_PROPERTIES(sink__V617, LINK_NamedPropertyLink(sink__V617->context, namedP__V625), LINK_VariablePropertyLink(sink__V617->context, varP__V626));
    { START(sink__V617, _M_FormArguments__binder__count_s3);
      COPY(sink__V617, sub__V620);{ if (!IS_BOUND(y__V621)) { REBIND(y__V621);
          Variable binds__V627[1] = {y__V621}; BINDS(sink__V617, 1, binds__V627);
          COPY(sink__V617, sub__V622); /* REUSED SUBSTITUTION */  }
        else { Variable b__V628 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V617->context,"b__V628");
          Variable binds__V629[1] = {b__V628}; BINDS(sink__V617, 1, binds__V629);
          {
            Term arg__V630;
            { Sink buf__V631 = ALLOCA_BUFFER(sink__V617->context);
              USE(buf__V631, b__V628); arg__V630 = BUFFER_TERM(buf__V631); FREE_BUFFER(buf__V631); }
            Variable vars__V632[1] = {y__V621};
            Term args__V633[1] = {arg__V630};
            struct _SubstitutionFrame substitution__V634 = {NULL, 0, 1, vars__V632, args__V633, NULL};
            SUBSTITUTE(sink__V617, sub__V622, &substitution__V634); }
              }
         }
      COPY(sink__V617, sub__V623);COPY(sink__V617, sub__V624);END(sink__V617, _M_FormArguments__binder__count_s3); }
    UNLINK_NamedPropertyLink(sink__V617->context, namedP__V625); UNLINK_VariablePropertyLink(sink__V617->context, varP__V626);
    
    return 1;
  } while (0);
  do {
    /* Contraction rule DEFS-FormArguments-binder-count-2$FormArguments-binder-count$1$FORM-ARGUMENT. */
    ASSERT(sink__V617->context, !strcmp(SYMBOL(term__V618),  "FormArguments-binder-count$1" ));
    Term sub__V635 = SUB(term__V618, 0); permitUnusedTerm(sub__V635); int sub__V635_count = term__V618_count*LINK_COUNT(sub__V635); permitUnusedInt(sub__V635_count);
    FORCE(sink__V617->context, sub__V635); SUB(term__V618, 0) = sub__V635;
    if (strcmp(SYMBOL(sub__V635),  "FORM-ARGUMENT" )) break;
    Term sub__V636 = LINK(sink__V617->context, SUB(sub__V635, 0)); int sub__V636_count = sub__V635_count*LINK_COUNT(sub__V636); permitUnusedInt(sub__V636_count);
    CRSX_CHECK_SORT(sink__V617->context, sub__V636, &sort_M_Reified_xSort); /* sub__V636 = &#0-0 */
    Term sub__V637 = LINK(sink__V617->context, SUB(term__V618, 1)); int sub__V637_count = term__V618_count*LINK_COUNT(sub__V637); permitUnusedInt(sub__V637_count);
    /* sub__V637 = &#1 */
    Term sub__V638 = LINK(sink__V617->context, SUB(term__V618, 2)); int sub__V638_count = term__V618_count*LINK_COUNT(sub__V638); permitUnusedInt(sub__V638_count);
    /* sub__V638 = &#2 */
    NamedPropertyLink namedP__V639 = LINK_NamedPropertyLink(sink__V617->context, NAMED_PROPERTIES(term__V618));
    VariablePropertyLink varP__V640 = LINK_VariablePropertyLink(sink__V617->context, VARIABLE_PROPERTIES(term__V618));
    UNLINK(sink__V617->context, term__V618);
    ADD_PROPERTIES(sink__V617, LINK_NamedPropertyLink(sink__V617->context, namedP__V639), LINK_VariablePropertyLink(sink__V617->context, varP__V640));
    { START(sink__V617, _M_FormArguments__binder__count_s2);
      COPY(sink__V617, sub__V636);COPY(sink__V617, sub__V637);COPY(sink__V617, sub__V638);END(sink__V617, _M_FormArguments__binder__count_s2); }
    UNLINK_NamedPropertyLink(sink__V617->context, namedP__V639); UNLINK_VariablePropertyLink(sink__V617->context, varP__V640);
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Length. */
int conBindOffs_M_Length[] = {0 , 0 , 0};
char *nameFun_M_Length(Term term) { return  "Length" ; }
struct _ConstructionDescriptor descriptor_M_Length = {NULL, 0, 2, sizeof(STRUCT_Con_M_Length), conBindOffs_M_Length, &nameFun_M_Length, &step_M_Length};

int step_M_Length(Sink sink__V641, Term term__V642)
{
  int term__V642_count = LINK_COUNT(term__V642); permitUnusedInt(term__V642_count);
  Term sub__V643 = FORCE(sink__V641->context, SUB(term__V642, 0));
  EnumOf_M__sList choice__V644 = (IS_VARIABLE_USE(sub__V643) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V643));
  switch (choice__V644)
  {
    case Data_M__sNil: { /* Function DEFS-Length-1$Length$$Nil case $Nil */
      ASSERT(sink__V641->context, !strcmp(SYMBOL(term__V642),  "Length" ));
      Term sub__V645 = SUB(term__V642, 0); permitUnusedTerm(sub__V645); int sub__V645_count = term__V642_count*LINK_COUNT(sub__V645); permitUnusedInt(sub__V645_count);
      ASSERT(sink__V641->context, !strcmp(SYMBOL(sub__V645),  "$Nil" ));
      Term sub__V646 = LINK(sink__V641->context, SUB(term__V642, 1)); int sub__V646_count = term__V642_count*LINK_COUNT(sub__V646); permitUnusedInt(sub__V646_count);
      /* sub__V646 = &#0 */
      NamedPropertyLink namedP__V647 = LINK_NamedPropertyLink(sink__V641->context, NAMED_PROPERTIES(term__V642));
      VariablePropertyLink varP__V648 = LINK_VariablePropertyLink(sink__V641->context, VARIABLE_PROPERTIES(term__V642));
      UNLINK(sink__V641->context, term__V642);
      ADD_PROPERTIES(sink__V641, LINK_NamedPropertyLink(sink__V641->context, namedP__V647), LINK_VariablePropertyLink(sink__V641->context, varP__V648));
      { START(sink__V641, _M_Length_s2);
        COPY(sink__V641, sub__V646);END(sink__V641, _M_Length_s2); }
      UNLINK_NamedPropertyLink(sink__V641->context, namedP__V647); UNLINK_VariablePropertyLink(sink__V641->context, varP__V648);
      
      return 1;
    break; } case Data_M__sCons: { /* Function DEFS-Length-2$Length$$Cons case $Cons */
      ASSERT(sink__V641->context, !strcmp(SYMBOL(term__V642),  "Length" ));
      Term sub__V649 = SUB(term__V642, 0); permitUnusedTerm(sub__V649); int sub__V649_count = term__V642_count*LINK_COUNT(sub__V649); permitUnusedInt(sub__V649_count);
      ASSERT(sink__V641->context, !strcmp(SYMBOL(sub__V649),  "$Cons" ));
      Term sub__V650 = LINK(sink__V641->context, SUB(sub__V649, 0)); int sub__V650_count = sub__V649_count*LINK_COUNT(sub__V650); permitUnusedInt(sub__V650_count);
      /* sub__V650 = &#0-0 */
      Term sub__V651 = LINK(sink__V641->context, SUB(sub__V649, 1)); int sub__V651_count = sub__V649_count*LINK_COUNT(sub__V651); permitUnusedInt(sub__V651_count);
      /* sub__V651 = &#0-1 */
      Term sub__V652 = LINK(sink__V641->context, SUB(term__V642, 1)); int sub__V652_count = term__V642_count*LINK_COUNT(sub__V652); permitUnusedInt(sub__V652_count);
      /* sub__V652 = &#2 */
      NamedPropertyLink namedP__V653 = LINK_NamedPropertyLink(sink__V641->context, NAMED_PROPERTIES(term__V642));
      VariablePropertyLink varP__V654 = LINK_VariablePropertyLink(sink__V641->context, VARIABLE_PROPERTIES(term__V642));
      UNLINK(sink__V641->context, term__V642);
      ADD_PROPERTIES(sink__V641, LINK_NamedPropertyLink(sink__V641->context, namedP__V653), LINK_VariablePropertyLink(sink__V641->context, varP__V654));
      { START(sink__V641, _M_Length_s1);
        COPY(sink__V641, sub__V650);COPY(sink__V641, sub__V651);COPY(sink__V641, sub__V652);END(sink__V641, _M_Length_s1); }
      UNLINK_NamedPropertyLink(sink__V641->context, namedP__V653); UNLINK_VariablePropertyLink(sink__V641->context, varP__V654);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION MapText1$1. */
int conBindOffs_M_MapText1_s1[] = {0 , 0 , 1 , 2};
char *nameFun_M_MapText1_s1(Term term) { return  "MapText1$1" ; }
struct _ConstructionDescriptor descriptor_M_MapText1_s1 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_MapText1_s1), conBindOffs_M_MapText1_s1, &nameFun_M_MapText1_s1, &step_M_MapText1_s1};

int step_M_MapText1_s1(Sink sink__V655, Term term__V656)
{
  int term__V656_count = LINK_COUNT(term__V656); permitUnusedInt(term__V656_count);
  Term sub__V657 = FORCE(sink__V655->context, SUB(term__V656, 0));
  EnumOf_M__sList choice__V658 = (IS_VARIABLE_USE(sub__V657) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V657));
  switch (choice__V658)
  {
    case Data_M__sCons: { /* Function DEFS-MapText1-1$MapText1$1$$Cons case $Cons */
      ASSERT(sink__V655->context, !strcmp(SYMBOL(term__V656),  "MapText1$1" ));
      Term sub__V659 = SUB(term__V656, 0); permitUnusedTerm(sub__V659); int sub__V659_count = term__V656_count*LINK_COUNT(sub__V659); permitUnusedInt(sub__V659_count);
      ASSERT(sink__V655->context, !strcmp(SYMBOL(sub__V659),  "$Cons" ));
      Term sub__V660 = LINK(sink__V655->context, SUB(sub__V659, 0)); int sub__V660_count = sub__V659_count*LINK_COUNT(sub__V660); permitUnusedInt(sub__V660_count);
      /* sub__V660 = &#0-0 */
      Term sub__V661 = LINK(sink__V655->context, SUB(sub__V659, 1)); int sub__V661_count = sub__V659_count*LINK_COUNT(sub__V661); permitUnusedInt(sub__V661_count);
      /* sub__V661 = &#0-1 */
      Variable x__V662 = BINDER(term__V656,1,0); if (term__V656_count <= 1) UNBIND(x__V662);
      Term sub__V663 = LINK(sink__V655->context, SUB(term__V656, 1)); int sub__V663_count = term__V656_count*LINK_COUNT(sub__V663); permitUnusedInt(sub__V663_count);
      CRSX_CHECK_SORT(sink__V655->context, sub__V663, &sort_M_Reified_xVariable); /* sub__V663 = &#2 */
      Variable x__V664 = BINDER(term__V656,2,0); if (term__V656_count <= 1) UNBIND(x__V664);
      Term sub__V665 = LINK(sink__V655->context, SUB(term__V656, 2)); int sub__V665_count = term__V656_count*LINK_COUNT(sub__V665); permitUnusedInt(sub__V665_count);
      CRSX_CHECK_SORT(sink__V655->context, sub__V665, &sort_M_Reified_xVariable); /* sub__V665 = &#3 */
      NamedPropertyLink namedP__V666 = LINK_NamedPropertyLink(sink__V655->context, NAMED_PROPERTIES(term__V656));
      VariablePropertyLink varP__V667 = LINK_VariablePropertyLink(sink__V655->context, VARIABLE_PROPERTIES(term__V656));
      UNLINK(sink__V655->context, term__V656);
      ADD_PROPERTIES(sink__V655, LINK_NamedPropertyLink(sink__V655->context, namedP__V666), LINK_VariablePropertyLink(sink__V655->context, varP__V667));
      { START(sink__V655, _M_MapText1_s2);
        COPY(sink__V655, sub__V660);COPY(sink__V655, sub__V661);{ if (!IS_BOUND(x__V662)) { REBIND(x__V662);
            Variable binds__V668[1] = {x__V662}; BINDS(sink__V655, 1, binds__V668);
            COPY(sink__V655, sub__V663); /* REUSED SUBSTITUTION */  }
          else { Variable b__V669 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V655->context,"b__V669");
            Variable binds__V670[1] = {b__V669}; BINDS(sink__V655, 1, binds__V670);
            {
              Term arg__V671;
              { Sink buf__V672 = ALLOCA_BUFFER(sink__V655->context);
                USE(buf__V672, b__V669); arg__V671 = BUFFER_TERM(buf__V672); FREE_BUFFER(buf__V672); }
              Variable vars__V673[1] = {x__V662};
              Term args__V674[1] = {arg__V671};
              struct _SubstitutionFrame substitution__V675 = {NULL, 0, 1, vars__V673, args__V674, NULL};
              SUBSTITUTE(sink__V655, sub__V663, &substitution__V675); }
                }
           }
        { if (!IS_BOUND(x__V664)) { REBIND(x__V664);
            Variable binds__V676[1] = {x__V664}; BINDS(sink__V655, 1, binds__V676);
            COPY(sink__V655, sub__V665); /* REUSED SUBSTITUTION */  }
          else { Variable b__V677 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V655->context,"b__V677");
            Variable binds__V678[1] = {b__V677}; BINDS(sink__V655, 1, binds__V678);
            {
              Term arg__V679;
              { Sink buf__V680 = ALLOCA_BUFFER(sink__V655->context);
                USE(buf__V680, b__V677); arg__V679 = BUFFER_TERM(buf__V680); FREE_BUFFER(buf__V680); }
              Variable vars__V681[1] = {x__V664};
              Term args__V682[1] = {arg__V679};
              struct _SubstitutionFrame substitution__V683 = {NULL, 0, 1, vars__V681, args__V682, NULL};
              SUBSTITUTE(sink__V655, sub__V665, &substitution__V683); }
                }
           }
        END(sink__V655, _M_MapText1_s2); }
      UNLINK_NamedPropertyLink(sink__V655->context, namedP__V666); UNLINK_VariablePropertyLink(sink__V655->context, varP__V667);
      
      return 1;
    break; } case Data_M__sNil: { /* Function DEFS-MapText1-2$MapText1$1$$Nil case $Nil */
      ASSERT(sink__V655->context, !strcmp(SYMBOL(term__V656),  "MapText1$1" ));
      Term sub__V684 = SUB(term__V656, 0); permitUnusedTerm(sub__V684); int sub__V684_count = term__V656_count*LINK_COUNT(sub__V684); permitUnusedInt(sub__V684_count);
      ASSERT(sink__V655->context, !strcmp(SYMBOL(sub__V684),  "$Nil" ));
      Variable x__V685 = BINDER(term__V656,1,0); if (term__V656_count <= 1) UNBIND(x__V685);
      Term sub__V686 = LINK(sink__V655->context, SUB(term__V656, 1)); int sub__V686_count = term__V656_count*LINK_COUNT(sub__V686); permitUnusedInt(sub__V686_count);
      CRSX_CHECK_SORT(sink__V655->context, sub__V686, &sort_M_Reified_xVariable); /* sub__V686 = &#0 */
      Variable x__V687 = BINDER(term__V656,2,0); if (term__V656_count <= 1) UNBIND(x__V687);
      Term sub__V688 = LINK(sink__V655->context, SUB(term__V656, 2)); int sub__V688_count = term__V656_count*LINK_COUNT(sub__V688); permitUnusedInt(sub__V688_count);
      CRSX_CHECK_SORT(sink__V655->context, sub__V688, &sort_M_Reified_xVariable); /* sub__V688 = &#1 */
      NamedPropertyLink namedP__V689 = LINK_NamedPropertyLink(sink__V655->context, NAMED_PROPERTIES(term__V656));
      VariablePropertyLink varP__V690 = LINK_VariablePropertyLink(sink__V655->context, VARIABLE_PROPERTIES(term__V656));
      UNLINK(sink__V655->context, term__V656);
      ADD_PROPERTIES(sink__V655, LINK_NamedPropertyLink(sink__V655->context, namedP__V689), LINK_VariablePropertyLink(sink__V655->context, varP__V690));
      { START(sink__V655, _M_MapText1_s3);
        { if (!IS_BOUND(x__V685)) { REBIND(x__V685);
            Variable binds__V691[1] = {x__V685}; BINDS(sink__V655, 1, binds__V691);
            COPY(sink__V655, sub__V686); /* REUSED SUBSTITUTION */  }
          else { Variable b__V692 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V655->context,"b__V692");
            Variable binds__V693[1] = {b__V692}; BINDS(sink__V655, 1, binds__V693);
            {
              Term arg__V694;
              { Sink buf__V695 = ALLOCA_BUFFER(sink__V655->context);
                USE(buf__V695, b__V692); arg__V694 = BUFFER_TERM(buf__V695); FREE_BUFFER(buf__V695); }
              Variable vars__V696[1] = {x__V685};
              Term args__V697[1] = {arg__V694};
              struct _SubstitutionFrame substitution__V698 = {NULL, 0, 1, vars__V696, args__V697, NULL};
              SUBSTITUTE(sink__V655, sub__V686, &substitution__V698); }
                }
           }
        { if (!IS_BOUND(x__V687)) { REBIND(x__V687);
            Variable binds__V699[1] = {x__V687}; BINDS(sink__V655, 1, binds__V699);
            COPY(sink__V655, sub__V688); /* REUSED SUBSTITUTION */  }
          else { Variable b__V700 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V655->context,"b__V700");
            Variable binds__V701[1] = {b__V700}; BINDS(sink__V655, 1, binds__V701);
            {
              Term arg__V702;
              { Sink buf__V703 = ALLOCA_BUFFER(sink__V655->context);
                USE(buf__V703, b__V700); arg__V702 = BUFFER_TERM(buf__V703); FREE_BUFFER(buf__V703); }
              Variable vars__V704[1] = {x__V687};
              Term args__V705[1] = {arg__V702};
              struct _SubstitutionFrame substitution__V706 = {NULL, 0, 1, vars__V704, args__V705, NULL};
              SUBSTITUTE(sink__V655, sub__V688, &substitution__V706); }
                }
           }
        END(sink__V655, _M_MapText1_s3); }
      UNLINK_NamedPropertyLink(sink__V655->context, namedP__V689); UNLINK_VariablePropertyLink(sink__V655->context, varP__V690);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION MapText1$2. */
int conBindOffs_M_MapText1_s2[] = {0 , 0 , 0 , 1 , 2};
char *nameFun_M_MapText1_s2(Term term) { return  "MapText1$2" ; }
struct _ConstructionDescriptor descriptor_M_MapText1_s2 = {&sort_M_Reified_xVariable, 0, 4, sizeof(STRUCT_Con_M_MapText1_s2), conBindOffs_M_MapText1_s2, &nameFun_M_MapText1_s2, &step_M_MapText1_s2};

int step_M_MapText1_s2(Sink sink__V707, Term term__V708)
{
  int term__V708_count = LINK_COUNT(term__V708); permitUnusedInt(term__V708_count);
  do {
    /* Contraction rule DEFS-MapText1-1. */
    ASSERT(sink__V707->context, !strcmp(SYMBOL(term__V708),  "MapText1$2" ));
    Term sub__V709 = LINK(sink__V707->context, SUB(term__V708, 0)); int sub__V709_count = term__V708_count*LINK_COUNT(sub__V709); permitUnusedInt(sub__V709_count);
    /* sub__V709 = &#31 */
    Term sub__V710 = LINK(sink__V707->context, SUB(term__V708, 1)); int sub__V710_count = term__V708_count*LINK_COUNT(sub__V710); permitUnusedInt(sub__V710_count);
    /* sub__V710 = &#32 */
    Variable x__V711 = BINDER(term__V708,2,0); if (term__V708_count <= 1) UNBIND(x__V711);
    Term sub__V712 = LINK(sink__V707->context, SUB(term__V708, 2)); int sub__V712_count = term__V708_count*LINK_COUNT(sub__V712); permitUnusedInt(sub__V712_count);
    CRSX_CHECK_SORT(sink__V707->context, sub__V712, &sort_M_Reified_xVariable); /* sub__V712 = &#2 */
    Variable x__V713 = BINDER(term__V708,3,0); if (term__V708_count <= 1) UNBIND(x__V713);
    Term sub__V714 = LINK(sink__V707->context, SUB(term__V708, 3)); int sub__V714_count = term__V708_count*LINK_COUNT(sub__V714); permitUnusedInt(sub__V714_count);
    CRSX_CHECK_SORT(sink__V707->context, sub__V714, &sort_M_Reified_xVariable); /* sub__V714 = &#1 */
    NamedPropertyLink namedP__V715 = LINK_NamedPropertyLink(sink__V707->context, NAMED_PROPERTIES(term__V708));
    VariablePropertyLink varP__V716 = LINK_VariablePropertyLink(sink__V707->context, VARIABLE_PROPERTIES(term__V708));
    UNLINK(sink__V707->context, term__V708);
    { START(sink__V707, _M__sTextCons);
      { START(sink__V707, _M__sTextEmbed);
        { START(sink__V707, _M_AsText);
          {
            Term arg__V717;
            { Sink buf__V718 = ALLOCA_BUFFER(sink__V707->context);
              COPY(buf__V718, sub__V709);arg__V717 = BUFFER_TERM(buf__V718); FREE_BUFFER(buf__V718); }
            Variable vars__V719[1] = {x__V713};
            Term args__V720[1] = {arg__V717};
            struct _SubstitutionFrame substitution__V721 = {NULL, 0, 1, vars__V719, args__V720, NULL};
            SUBSTITUTE(sink__V707, sub__V714, &substitution__V721); }
          END(sink__V707, _M_AsText); }
        END(sink__V707, _M__sTextEmbed); }
      { START(sink__V707, _M__sTextCons);
        { START(sink__V707, _M__sTextEmbed);
          { START(sink__V707, _M_AsText);
            { START(sink__V707, _M_MapText_s1);
              COPY(sink__V707, sub__V710);{ if (!IS_BOUND(x__V711)) { REBIND(x__V711);
                  Variable binds__V722[1] = {x__V711}; BINDS(sink__V707, 1, binds__V722);
                  COPY(sink__V707, sub__V712); /* REUSED SUBSTITUTION */  }
                else { Variable b__V723 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V707->context,"b__V723");
                  Variable binds__V724[1] = {b__V723}; BINDS(sink__V707, 1, binds__V724);
                  {
                    Term arg__V725;
                    { Sink buf__V726 = ALLOCA_BUFFER(sink__V707->context);
                      USE(buf__V726, b__V723); arg__V725 = BUFFER_TERM(buf__V726); FREE_BUFFER(buf__V726); }
                    Variable vars__V727[1] = {x__V711};
                    Term args__V728[1] = {arg__V725};
                    struct _SubstitutionFrame substitution__V729 = {NULL, 0, 1, vars__V727, args__V728, NULL};
                    SUBSTITUTE(sink__V707, sub__V712, &substitution__V729); }
                      }
                 }
              END(sink__V707, _M_MapText_s1); }
            END(sink__V707, _M_AsText); }
          END(sink__V707, _M__sTextEmbed); }
        { START(sink__V707, _M__sTextNil);
          END(sink__V707, _M__sTextNil); }
        END(sink__V707, _M__sTextCons); }
      END(sink__V707, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V707->context, namedP__V715); UNLINK_VariablePropertyLink(sink__V707->context, varP__V716);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION MapText1$3. */
int conBindOffs_M_MapText1_s3[] = {0 , 1 , 2};
char *nameFun_M_MapText1_s3(Term term) { return  "MapText1$3" ; }
struct _ConstructionDescriptor descriptor_M_MapText1_s3 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_MapText1_s3), conBindOffs_M_MapText1_s3, &nameFun_M_MapText1_s3, &step_M_MapText1_s3};

int step_M_MapText1_s3(Sink sink__V730, Term term__V731)
{
  int term__V731_count = LINK_COUNT(term__V731); permitUnusedInt(term__V731_count);
  do {
    /* Contraction rule DEFS-MapText1-2. */
    ASSERT(sink__V730->context, !strcmp(SYMBOL(term__V731),  "MapText1$3" ));
    Variable x__V732 = BINDER(term__V731,0,0); if (term__V731_count <= 1) UNBIND(x__V732);
    Term sub__V733 = SUB(term__V731, 0); permitUnusedTerm(sub__V733); int sub__V733_count = term__V731_count*LINK_COUNT(sub__V733); permitUnusedInt(sub__V733_count);
    CRSX_CHECK_SORT(sink__V730->context, sub__V733, &sort_M_Reified_xVariable); /* sub__V733 = &#2 */
    Variable x__V734 = BINDER(term__V731,1,0); if (term__V731_count <= 1) UNBIND(x__V734);
    Term sub__V735 = SUB(term__V731, 1); permitUnusedTerm(sub__V735); int sub__V735_count = term__V731_count*LINK_COUNT(sub__V735); permitUnusedInt(sub__V735_count);
    CRSX_CHECK_SORT(sink__V730->context, sub__V735, &sort_M_Reified_xVariable); /* sub__V735 = &#1 */
    NamedPropertyLink namedP__V736 = LINK_NamedPropertyLink(sink__V730->context, NAMED_PROPERTIES(term__V731));
    VariablePropertyLink varP__V737 = LINK_VariablePropertyLink(sink__V730->context, VARIABLE_PROPERTIES(term__V731));
    UNLINK(sink__V730->context, term__V731);
    { START(sink__V730, _M__sTextNil); END(sink__V730, _M__sTextNil); }
    UNLINK_NamedPropertyLink(sink__V730->context, namedP__V736); UNLINK_VariablePropertyLink(sink__V730->context, varP__V737);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DCOMMENT_TOKEN$1. */
int conBindOffs_M_DCOMMENT_xTOKEN_s1[] = {0 , 0};
char *nameFun_M_DCOMMENT_xTOKEN_s1(Term term) { return  "DCOMMENT_TOKEN$1" ; }
struct _ConstructionDescriptor descriptor_M_DCOMMENT_xTOKEN_s1 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_DCOMMENT_xTOKEN_s1), conBindOffs_M_DCOMMENT_xTOKEN_s1, &nameFun_M_DCOMMENT_xTOKEN_s1, &step_M_DCOMMENT_xTOKEN_s1};

int step_M_DCOMMENT_xTOKEN_s1(Sink sink__V738, Term term__V739)
{
  int term__V739_count = LINK_COUNT(term__V739); permitUnusedInt(term__V739_count);
  do {
    /* Contraction rule DEFS-DCOMMENT_TOKEN-1. */
    ASSERT(sink__V738->context, !strcmp(SYMBOL(term__V739),  "DCOMMENT_TOKEN$1" ));
    Term sub__V740 = LINK(sink__V738->context, SUB(term__V739, 0)); int sub__V740_count = term__V739_count*LINK_COUNT(sub__V740); permitUnusedInt(sub__V740_count);
    UNLINK_SUB(sink__V738->context, term__V739,  0); NORMALIZE(sink__V738->context, sub__V740); SUB(term__V739,  0) = LINK(sink__V738->context, sub__V740);
    /* sub__V740 = &#2 */
    NamedPropertyLink namedP__V741 = LINK_NamedPropertyLink(sink__V738->context, NAMED_PROPERTIES(term__V739));
    VariablePropertyLink varP__V742 = LINK_VariablePropertyLink(sink__V738->context, VARIABLE_PROPERTIES(term__V739));
    UNLINK(sink__V738->context, term__V739);
    { START(sink__V738, _M__sTextCons);
      { START(sink__V738, _M__sTextChars);
        { char *str__V743;
          FORCE(sink__V738->context, sub__V740);
          { char *replaced__V744;
            const size_t z = strlen(SYMBOL(sub__V740));
            if (* "*/" ) {
              const size_t oldz = strlen( "*/" ), newz = strlen( "*_/" );
              size_t limitz;
              if (oldz==newz) { limitz = z; }
              else { limitz = z; size_t growz = (oldz < newz ? newz - oldz : 0);
                if (growz > 0) { char *p = SYMBOL(sub__V740); while ((p = strstr(p,  "*/" ))) { limitz += growz; p += oldz; } } }
              replaced__V744 = ALLOCA(sink__V738->context, limitz+1);
              if (oldz==newz) { memcpy(replaced__V744, SYMBOL(sub__V740), z+1);
                char *r = replaced__V744; while ((r = strstr(r,  "*/" ))) { memcpy(r,  "*_/" , newz); r += oldz; } }
              else { char *s = SYMBOL(sub__V740), *ends = s+z, *r = replaced__V744, *next;
                while ((next = strstr(s,  "*/" ))) { size_t prez = next-s;
                  if (prez) { memcpy(r, s, prez); r += prez; } 
                  if (newz) { memcpy(r,  "*_/" , newz); r += newz; }
                  s = next+oldz;}
                if (s < ends) { memcpy(r, s, ends-s); r += ends-s; }
                *r = '\0';}
              }
            else { replaced__V744 = memcpy(ALLOCA(sink__V738->context, z+1), SYMBOL(sub__V740), z+1); }
             UNLINK(sink__V738->context, sub__V740);{ size_t z__V745 = strlen(replaced__V744) + 1; memcpy(str__V743 = ALLOCATE(sink__V738->context, z__V745), replaced__V744, z__V745); }
            
          }LITERALU(sink__V738, str__V743); }
        END(sink__V738, _M__sTextChars); }
      { START(sink__V738, _M__sTextNil);
        END(sink__V738, _M__sTextNil); }
      END(sink__V738, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V738->context, namedP__V741); UNLINK_VariablePropertyLink(sink__V738->context, varP__V742);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Length$2. */
int conBindOffs_M_Length_s2[] = {0 , 0};
char *nameFun_M_Length_s2(Term term) { return  "Length$2" ; }
struct _ConstructionDescriptor descriptor_M_Length_s2 = {NULL, 0, 1, sizeof(STRUCT_Con_M_Length_s2), conBindOffs_M_Length_s2, &nameFun_M_Length_s2, &step_M_Length_s2};

int step_M_Length_s2(Sink sink__V746, Term term__V747)
{
  int term__V747_count = LINK_COUNT(term__V747); permitUnusedInt(term__V747_count);
  do {
    /* Contraction rule DEFS-Length-1. */
    ASSERT(sink__V746->context, !strcmp(SYMBOL(term__V747),  "Length$2" ));
    Term sub__V748 = LINK(sink__V746->context, SUB(term__V747, 0)); int sub__V748_count = term__V747_count*LINK_COUNT(sub__V748); permitUnusedInt(sub__V748_count);
    /* sub__V748 = &#2 */
    UNLINK(sink__V746->context, term__V747);
    COPY(sink__V746, sub__V748);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Length$1. */
int conBindOffs_M_Length_s1[] = {0 , 0 , 0 , 0};
char *nameFun_M_Length_s1(Term term) { return  "Length$1" ; }
struct _ConstructionDescriptor descriptor_M_Length_s1 = {NULL, 0, 3, sizeof(STRUCT_Con_M_Length_s1), conBindOffs_M_Length_s1, &nameFun_M_Length_s1, &step_M_Length_s1};

int step_M_Length_s1(Sink sink__V749, Term term__V750)
{
  int term__V750_count = LINK_COUNT(term__V750); permitUnusedInt(term__V750_count);
  do {
    /* Contraction rule DEFS-Length-2. */
    ASSERT(sink__V749->context, !strcmp(SYMBOL(term__V750),  "Length$1" ));
    Term sub__V751 = SUB(term__V750, 0); permitUnusedTerm(sub__V751); int sub__V751_count = term__V750_count*LINK_COUNT(sub__V751); permitUnusedInt(sub__V751_count);
    /* sub__V751 = &#11 */
    Term sub__V752 = LINK(sink__V749->context, SUB(term__V750, 1)); int sub__V752_count = term__V750_count*LINK_COUNT(sub__V752); permitUnusedInt(sub__V752_count);
    /* sub__V752 = &#12 */
    Term sub__V753 = LINK(sink__V749->context, SUB(term__V750, 2)); int sub__V753_count = term__V750_count*LINK_COUNT(sub__V753); permitUnusedInt(sub__V753_count);
    /* sub__V753 = &#2 */
    UNLINK(sink__V749->context, term__V750);
    { START(sink__V749, _M_Length);
      COPY(sink__V749, sub__V752);{ double num__V754;
        num__V754 = (double) 1; { double tmp__V755;
          tmp__V755 = DOUBLE(sub__V753); num__V754 += tmp__V755; }
        LITERALNF(sink__V749, (size_t) 31, "%G", num__V754); }
      END(sink__V749, _M_Length); }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Name. */
int conBindOffs_M_Name[] = {0 , 0};
char *nameFun_M_Name(Term term) { return  "Name" ; }
struct _ConstructionDescriptor descriptor_M_Name = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_Name), conBindOffs_M_Name, &nameFun_M_Name, &step_M_Name};

int step_M_Name(Sink sink__V756, Term term__V757)
{
  int term__V757_count = LINK_COUNT(term__V757); permitUnusedInt(term__V757_count);
  do {
    /* Contraction rule DEFS-Name-1. */
    ASSERT(sink__V756->context, !strcmp(SYMBOL(term__V757),  "Name" ));
    Term sub__V758 = LINK(sink__V756->context, SUB(term__V757, 0)); int sub__V758_count = term__V757_count*LINK_COUNT(sub__V758); permitUnusedInt(sub__V758_count);
    /* sub__V758 = &#1 */
    NamedPropertyLink namedP__V759 = LINK_NamedPropertyLink(sink__V756->context, NAMED_PROPERTIES(term__V757));
    VariablePropertyLink varP__V760 = LINK_VariablePropertyLink(sink__V756->context, VARIABLE_PROPERTIES(term__V757));
    UNLINK(sink__V756->context, term__V757);
    { START(sink__V756, _M__sTextCons);
      { START(sink__V756, _M__sTextChars);
        LITERAL(sink__V756,  "name" ); END(sink__V756, _M__sTextChars); }
      { START(sink__V756, _M__sTextCons);
        { START(sink__V756, _M__sTextEmbed);
          { START(sink__V756, _M_AsText);
            { START(sink__V756, _M_MANGLE);
              COPY(sink__V756, sub__V758);END(sink__V756, _M_MANGLE); }
            END(sink__V756, _M_AsText); }
          END(sink__V756, _M__sTextEmbed); }
        { START(sink__V756, _M__sTextNil);
          END(sink__V756, _M__sTextNil); }
        END(sink__V756, _M__sTextCons); }
      END(sink__V756, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V756->context, namedP__V759); UNLINK_VariablePropertyLink(sink__V756->context, varP__V760);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION TOKEN. */
int conBindOffs_M_TOKEN[] = {0 , 0};
char *nameFun_M_TOKEN(Term term) { return  "TOKEN" ; }
struct _ConstructionDescriptor descriptor_M_TOKEN = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_TOKEN), conBindOffs_M_TOKEN, &nameFun_M_TOKEN, &step_M_TOKEN};

int step_M_TOKEN(Sink sink__V761, Term term__V762)
{
  int term__V762_count = LINK_COUNT(term__V762); permitUnusedInt(term__V762_count);
  do {
    /* Contraction rule DEFS-TOKEN-1. */
    ASSERT(sink__V761->context, !strcmp(SYMBOL(term__V762),  "TOKEN" ));
    Term sub__V763 = LINK(sink__V761->context, SUB(term__V762, 0)); int sub__V763_count = term__V762_count*LINK_COUNT(sub__V763); permitUnusedInt(sub__V763_count);
    UNLINK_SUB(sink__V761->context, term__V762,  0); NORMALIZE(sink__V761->context, sub__V763); SUB(term__V762,  0) = LINK(sink__V761->context, sub__V763);
    /* sub__V763 = &#1 */
    NamedPropertyLink namedP__V764 = LINK_NamedPropertyLink(sink__V761->context, NAMED_PROPERTIES(term__V762));
    VariablePropertyLink varP__V765 = LINK_VariablePropertyLink(sink__V761->context, VARIABLE_PROPERTIES(term__V762));
    UNLINK(sink__V761->context, term__V762);
    { START(sink__V761, _M__sTextCons);
      { START(sink__V761, _M__sTextChars);
        COPY(sink__V761, sub__V763);END(sink__V761, _M__sTextChars); }
      { START(sink__V761, _M__sTextNil);
        END(sink__V761, _M__sTextNil); }
      END(sink__V761, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V761->context, namedP__V764); UNLINK_VariablePropertyLink(sink__V761->context, varP__V765);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DSTRING. */
int conBindOffs_M_DSTRING[] = {0 , 0 , 0};
char *nameFun_M_DSTRING(Term term) { return  "DSTRING" ; }
struct _ConstructionDescriptor descriptor_M_DSTRING = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_DSTRING), conBindOffs_M_DSTRING, &nameFun_M_DSTRING, &step_M_DSTRING};

int step_M_DSTRING(Sink sink__V766, Term term__V767)
{
  int term__V767_count = LINK_COUNT(term__V767); permitUnusedInt(term__V767_count);
  Term sub__V768 = FORCE(sink__V766->context, SUB(term__V767, 0));
  EnumOf_M_OK_xSORT choice__V769 = (IS_VARIABLE_USE(sub__V768) ? VarOf_M_OK_xSORT : (EnumOf_M_OK_xSORT) TAG(sub__V768));
  switch (choice__V769)
  {
    case Data_M_OK: { /* Function DEFS-DSTRING-1$DSTRING$OK case OK */
      ASSERT(sink__V766->context, !strcmp(SYMBOL(term__V767),  "DSTRING" ));
      Term sub__V770 = SUB(term__V767, 0); permitUnusedTerm(sub__V770); int sub__V770_count = term__V767_count*LINK_COUNT(sub__V770); permitUnusedInt(sub__V770_count);
      CRSX_CHECK_SORT(sink__V766->context, sub__V770, &sort_M_OK_xSORT); ASSERT(sink__V766->context, !strcmp(SYMBOL(sub__V770),  "OK" ));
      Term sub__V771 = LINK(sink__V766->context, SUB(term__V767, 1)); int sub__V771_count = term__V767_count*LINK_COUNT(sub__V771); permitUnusedInt(sub__V771_count);
      /* sub__V771 = &#0 */
      NamedPropertyLink namedP__V772 = LINK_NamedPropertyLink(sink__V766->context, NAMED_PROPERTIES(term__V767));
      VariablePropertyLink varP__V773 = LINK_VariablePropertyLink(sink__V766->context, VARIABLE_PROPERTIES(term__V767));
      UNLINK(sink__V766->context, term__V767);
      ADD_PROPERTIES(sink__V766, LINK_NamedPropertyLink(sink__V766->context, namedP__V772), LINK_VariablePropertyLink(sink__V766->context, varP__V773));
      { START(sink__V766, _M_DSTRING_s1);
        COPY(sink__V766, sub__V771);END(sink__V766, _M_DSTRING_s1); }
      UNLINK_NamedPropertyLink(sink__V766->context, namedP__V772); UNLINK_VariablePropertyLink(sink__V766->context, varP__V773);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION SortInternals. */
int conBindOffs_M_SortInternals[] = {0 , 0};
char *nameFun_M_SortInternals(Term term) { return  "SortInternals" ; }
struct _ConstructionDescriptor descriptor_M_SortInternals = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_SortInternals), conBindOffs_M_SortInternals, &nameFun_M_SortInternals, &step_M_SortInternals};

int step_M_SortInternals(Sink sink__V774, Term term__V775)
{
  int term__V775_count = LINK_COUNT(term__V775); permitUnusedInt(term__V775_count);
  do {
    /* Contraction rule DEFS-SortInternals-1. */
    ASSERT(sink__V774->context, !strcmp(SYMBOL(term__V775),  "SortInternals" ));
    Term sub__V776 = LINK(sink__V774->context, SUB(term__V775, 0)); int sub__V776_count = term__V775_count*LINK_COUNT(sub__V776); permitUnusedInt(sub__V776_count);
    /* sub__V776 = &#1 */
    NamedPropertyLink namedP__V777 = LINK_NamedPropertyLink(sink__V774->context, NAMED_PROPERTIES(term__V775));
    VariablePropertyLink varP__V778 = LINK_VariablePropertyLink(sink__V774->context, VARIABLE_PROPERTIES(term__V775));
    UNLINK(sink__V774->context, term__V775);
    { START(sink__V774, _M__sTextCons);
      { START(sink__V774, _M__sTextChars);
        LITERAL(sink__V774,  "sortInt" ); END(sink__V774, _M__sTextChars); }
      { START(sink__V774, _M__sTextCons);
        { START(sink__V774, _M__sTextEmbed);
          { START(sink__V774, _M_AsText);
            { START(sink__V774, _M_MANGLE);
              COPY(sink__V774, sub__V776);END(sink__V774, _M_MANGLE); }
            END(sink__V774, _M_AsText); }
          END(sink__V774, _M__sTextEmbed); }
        { START(sink__V774, _M__sTextNil);
          END(sink__V774, _M__sTextNil); }
        END(sink__V774, _M__sTextCons); }
      END(sink__V774, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V774->context, namedP__V777); UNLINK_VariablePropertyLink(sink__V774->context, varP__V778);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION UnString$1. */
int conBindOffs_M_UnString_s1[] = {0 , 0};
char *nameFun_M_UnString_s1(Term term) { return  "UnString$1" ; }
struct _ConstructionDescriptor descriptor_M_UnString_s1 = {NULL, 0, 1, sizeof(STRUCT_Con_M_UnString_s1), conBindOffs_M_UnString_s1, &nameFun_M_UnString_s1, &step_M_UnString_s1};

int step_M_UnString_s1(Sink sink__V779, Term term__V780)
{
  int term__V780_count = LINK_COUNT(term__V780); permitUnusedInt(term__V780_count);
  do {
    /* Contraction rule DEFS-UnString-1. */
    ASSERT(sink__V779->context, !strcmp(SYMBOL(term__V780),  "UnString$1" ));
    Term sub__V781 = LINK(sink__V779->context, SUB(term__V780, 0)); int sub__V781_count = term__V780_count*LINK_COUNT(sub__V781); permitUnusedInt(sub__V781_count);
    /* sub__V781 = &#11 */
    UNLINK(sink__V779->context, term__V780);
    COPY(sink__V779, sub__V781);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Descriptor. */
int conBindOffs_M_Descriptor[] = {0 , 0};
char *nameFun_M_Descriptor(Term term) { return  "Descriptor" ; }
struct _ConstructionDescriptor descriptor_M_Descriptor = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_Descriptor), conBindOffs_M_Descriptor, &nameFun_M_Descriptor, &step_M_Descriptor};

int step_M_Descriptor(Sink sink__V782, Term term__V783)
{
  int term__V783_count = LINK_COUNT(term__V783); permitUnusedInt(term__V783_count);
  do {
    /* Contraction rule DEFS-Descriptor-1. */
    ASSERT(sink__V782->context, !strcmp(SYMBOL(term__V783),  "Descriptor" ));
    Term sub__V784 = LINK(sink__V782->context, SUB(term__V783, 0)); int sub__V784_count = term__V783_count*LINK_COUNT(sub__V784); permitUnusedInt(sub__V784_count);
    /* sub__V784 = &#1 */
    NamedPropertyLink namedP__V785 = LINK_NamedPropertyLink(sink__V782->context, NAMED_PROPERTIES(term__V783));
    VariablePropertyLink varP__V786 = LINK_VariablePropertyLink(sink__V782->context, VARIABLE_PROPERTIES(term__V783));
    UNLINK(sink__V782->context, term__V783);
    { START(sink__V782, _M__sTextCons);
      { START(sink__V782, _M__sTextChars);
        LITERAL(sink__V782,  "descriptor" ); END(sink__V782, _M__sTextChars); }
      { START(sink__V782, _M__sTextCons);
        { START(sink__V782, _M__sTextEmbed);
          { START(sink__V782, _M_AsText);
            { START(sink__V782, _M_MANGLE);
              COPY(sink__V782, sub__V784);END(sink__V782, _M_MANGLE); }
            END(sink__V782, _M_AsText); }
          END(sink__V782, _M__sTextEmbed); }
        { START(sink__V782, _M__sTextNil);
          END(sink__V782, _M__sTextNil); }
        END(sink__V782, _M__sTextCons); }
      END(sink__V782, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V782->context, namedP__V785); UNLINK_VariablePropertyLink(sink__V782->context, varP__V786);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Forms-Constructors$5. */
int conBindOffs_M_Forms_Constructors_s5[] = {0};
char *nameFun_M_Forms_Constructors_s5(Term term) { return  "Forms-Constructors$5" ; }
struct _ConstructionDescriptor descriptor_M_Forms_Constructors_s5 = {NULL, 0, 0, sizeof(STRUCT_Con_M_Forms_Constructors_s5), conBindOffs_M_Forms_Constructors_s5, &nameFun_M_Forms_Constructors_s5, &step_M_Forms_Constructors_s5};

int step_M_Forms_Constructors_s5(Sink sink__V787, Term term__V788)
{
  int term__V788_count = LINK_COUNT(term__V788); permitUnusedInt(term__V788_count);
  do {
    /* Contraction rule DEFS-Forms-Constructors-4. */
    ASSERT(sink__V787->context, !strcmp(SYMBOL(term__V788),  "Forms-Constructors$5" ));
    UNLINK(sink__V787->context, term__V788);
    { START(sink__V787, _M__sNil); END(sink__V787, _M__sNil); } 
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Forms-Constructors$2. */
int conBindOffs_M_Forms_Constructors_s2[] = {0 , 0 , 0 , 0};
char *nameFun_M_Forms_Constructors_s2(Term term) { return  "Forms-Constructors$2" ; }
struct _ConstructionDescriptor descriptor_M_Forms_Constructors_s2 = {NULL, 0, 3, sizeof(STRUCT_Con_M_Forms_Constructors_s2), conBindOffs_M_Forms_Constructors_s2, &nameFun_M_Forms_Constructors_s2, &step_M_Forms_Constructors_s2};

int step_M_Forms_Constructors_s2(Sink sink__V789, Term term__V790)
{
  int term__V790_count = LINK_COUNT(term__V790); permitUnusedInt(term__V790_count);
  do {
    /* Contraction rule DEFS-Forms-Constructors-3. */
    ASSERT(sink__V789->context, !strcmp(SYMBOL(term__V790),  "Forms-Constructors$2" ));
    Term sub__V791 = LINK(sink__V789->context, SUB(term__V790, 0)); int sub__V791_count = term__V790_count*LINK_COUNT(sub__V791); permitUnusedInt(sub__V791_count);
    /* sub__V791 = &#111 */
    Term sub__V792 = SUB(term__V790, 1); permitUnusedTerm(sub__V792); int sub__V792_count = term__V790_count*LINK_COUNT(sub__V792); permitUnusedInt(sub__V792_count);
    /* sub__V792 = &#112 */
    Term sub__V793 = LINK(sink__V789->context, SUB(term__V790, 2)); int sub__V793_count = term__V790_count*LINK_COUNT(sub__V793); permitUnusedInt(sub__V793_count);
    /* sub__V793 = &#12 */
    UNLINK(sink__V789->context, term__V790);
    { START(sink__V789, _M__sCons);
      COPY(sink__V789, sub__V791);{ START(sink__V789, _M_Forms_Constructors);
        COPY(sink__V789, sub__V793);END(sink__V789, _M_Forms_Constructors); }
      END(sink__V789, _M__sCons); }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Forms-Constructors$1. */
int conBindOffs_M_Forms_Constructors_s1[] = {0 , 0 , 0};
char *nameFun_M_Forms_Constructors_s1(Term term) { return  "Forms-Constructors$1" ; }
struct _ConstructionDescriptor descriptor_M_Forms_Constructors_s1 = {NULL, 0, 2, sizeof(STRUCT_Con_M_Forms_Constructors_s1), conBindOffs_M_Forms_Constructors_s1, &nameFun_M_Forms_Constructors_s1, &step_M_Forms_Constructors_s1};

int step_M_Forms_Constructors_s1(Sink sink__V794, Term term__V795)
{
  int term__V795_count = LINK_COUNT(term__V795); permitUnusedInt(term__V795_count);
  do {
    /* Contraction rule DEFS-Forms-Constructors-1$Forms-Constructors$1$SORT-ALLOWS-VARIABLES. */
    ASSERT(sink__V794->context, !strcmp(SYMBOL(term__V795),  "Forms-Constructors$1" ));
    Term sub__V796 = SUB(term__V795, 0); permitUnusedTerm(sub__V796); int sub__V796_count = term__V795_count*LINK_COUNT(sub__V796); permitUnusedInt(sub__V796_count);
    FORCE(sink__V794->context, sub__V796); SUB(term__V795, 0) = sub__V796;
    if (strcmp(SYMBOL(sub__V796),  "SORT-ALLOWS-VARIABLES" )) break;
    Term sub__V797 = LINK(sink__V794->context, SUB(term__V795, 1)); int sub__V797_count = term__V795_count*LINK_COUNT(sub__V797); permitUnusedInt(sub__V797_count);
    /* sub__V797 = &#0 */
    NamedPropertyLink namedP__V798 = LINK_NamedPropertyLink(sink__V794->context, NAMED_PROPERTIES(term__V795));
    VariablePropertyLink varP__V799 = LINK_VariablePropertyLink(sink__V794->context, VARIABLE_PROPERTIES(term__V795));
    UNLINK(sink__V794->context, term__V795);
    ADD_PROPERTIES(sink__V794, LINK_NamedPropertyLink(sink__V794->context, namedP__V798), LINK_VariablePropertyLink(sink__V794->context, varP__V799));
    { START(sink__V794, _M_Forms_Constructors_s3);
      COPY(sink__V794, sub__V797);END(sink__V794, _M_Forms_Constructors_s3); }
    UNLINK_NamedPropertyLink(sink__V794->context, namedP__V798); UNLINK_VariablePropertyLink(sink__V794->context, varP__V799);
    
    return 1;
  } while (0);
  do {
    /* Contraction rule DEFS-Forms-Constructors-2$Forms-Constructors$1$SORT-SET. */
    ASSERT(sink__V794->context, !strcmp(SYMBOL(term__V795),  "Forms-Constructors$1" ));
    Term sub__V800 = SUB(term__V795, 0); permitUnusedTerm(sub__V800); int sub__V800_count = term__V795_count*LINK_COUNT(sub__V800); permitUnusedInt(sub__V800_count);
    FORCE(sink__V794->context, sub__V800); SUB(term__V795, 0) = sub__V800;
    if (strcmp(SYMBOL(sub__V800),  "SORT-SET" )) break;
    Term sub__V801 = LINK(sink__V794->context, SUB(sub__V800, 0)); int sub__V801_count = sub__V800_count*LINK_COUNT(sub__V801); permitUnusedInt(sub__V801_count);
    CRSX_CHECK_SORT(sink__V794->context, sub__V801, &sort_M_Reified_xSort); /* sub__V801 = &#0-0 */
    Term sub__V802 = LINK(sink__V794->context, SUB(sub__V800, 1)); int sub__V802_count = sub__V800_count*LINK_COUNT(sub__V802); permitUnusedInt(sub__V802_count);
    CRSX_CHECK_SORT(sink__V794->context, sub__V802, &sort_M_Reified_xSort); /* sub__V802 = &#0-1 */
    Term sub__V803 = LINK(sink__V794->context, SUB(sub__V800, 2)); int sub__V803_count = sub__V800_count*LINK_COUNT(sub__V803); permitUnusedInt(sub__V803_count);
    CRSX_CHECK_SORT(sink__V794->context, sub__V803, &sort_M_Reified_xForm); /* sub__V803 = &#0-2 */
    Term sub__V804 = LINK(sink__V794->context, SUB(term__V795, 1)); int sub__V804_count = term__V795_count*LINK_COUNT(sub__V804); permitUnusedInt(sub__V804_count);
    /* sub__V804 = &#3 */
    NamedPropertyLink namedP__V805 = LINK_NamedPropertyLink(sink__V794->context, NAMED_PROPERTIES(term__V795));
    VariablePropertyLink varP__V806 = LINK_VariablePropertyLink(sink__V794->context, VARIABLE_PROPERTIES(term__V795));
    UNLINK(sink__V794->context, term__V795);
    ADD_PROPERTIES(sink__V794, LINK_NamedPropertyLink(sink__V794->context, namedP__V805), LINK_VariablePropertyLink(sink__V794->context, varP__V806));
    { START(sink__V794, _M_Forms_Constructors_s4);
      COPY(sink__V794, sub__V801);COPY(sink__V794, sub__V802);COPY(sink__V794, sub__V803);COPY(sink__V794, sub__V804);END(sink__V794, _M_Forms_Constructors_s4); }
    UNLINK_NamedPropertyLink(sink__V794->context, namedP__V805); UNLINK_VariablePropertyLink(sink__V794->context, varP__V806);
    
    return 1;
  } while (0);
  do {
    /* Contraction rule DEFS-Forms-Constructors-3$Forms-Constructors$1$FORM. */
    ASSERT(sink__V794->context, !strcmp(SYMBOL(term__V795),  "Forms-Constructors$1" ));
    Term sub__V807 = SUB(term__V795, 0); permitUnusedTerm(sub__V807); int sub__V807_count = term__V795_count*LINK_COUNT(sub__V807); permitUnusedInt(sub__V807_count);
    FORCE(sink__V794->context, sub__V807); SUB(term__V795, 0) = sub__V807;
    if (strcmp(SYMBOL(sub__V807),  "FORM" )) break;
    Term sub__V808 = LINK(sink__V794->context, SUB(sub__V807, 0)); int sub__V808_count = sub__V807_count*LINK_COUNT(sub__V808); permitUnusedInt(sub__V808_count);
    /* sub__V808 = &#0-0 */
    Term sub__V809 = LINK(sink__V794->context, SUB(sub__V807, 1)); int sub__V809_count = sub__V807_count*LINK_COUNT(sub__V809); permitUnusedInt(sub__V809_count);
    /* sub__V809 = &#0-1 */
    Term sub__V810 = LINK(sink__V794->context, SUB(term__V795, 1)); int sub__V810_count = term__V795_count*LINK_COUNT(sub__V810); permitUnusedInt(sub__V810_count);
    /* sub__V810 = &#2 */
    NamedPropertyLink namedP__V811 = LINK_NamedPropertyLink(sink__V794->context, NAMED_PROPERTIES(term__V795));
    VariablePropertyLink varP__V812 = LINK_VariablePropertyLink(sink__V794->context, VARIABLE_PROPERTIES(term__V795));
    UNLINK(sink__V794->context, term__V795);
    ADD_PROPERTIES(sink__V794, LINK_NamedPropertyLink(sink__V794->context, namedP__V811), LINK_VariablePropertyLink(sink__V794->context, varP__V812));
    { START(sink__V794, _M_Forms_Constructors_s2);
      COPY(sink__V794, sub__V808);COPY(sink__V794, sub__V809);COPY(sink__V794, sub__V810);END(sink__V794, _M_Forms_Constructors_s2); }
    UNLINK_NamedPropertyLink(sink__V794->context, namedP__V811); UNLINK_VariablePropertyLink(sink__V794->context, varP__V812);
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Forms-Constructors$4. */
int conBindOffs_M_Forms_Constructors_s4[] = {0 , 0 , 0 , 0 , 0};
char *nameFun_M_Forms_Constructors_s4(Term term) { return  "Forms-Constructors$4" ; }
struct _ConstructionDescriptor descriptor_M_Forms_Constructors_s4 = {NULL, 0, 4, sizeof(STRUCT_Con_M_Forms_Constructors_s4), conBindOffs_M_Forms_Constructors_s4, &nameFun_M_Forms_Constructors_s4, &step_M_Forms_Constructors_s4};

int step_M_Forms_Constructors_s4(Sink sink__V813, Term term__V814)
{
  int term__V814_count = LINK_COUNT(term__V814); permitUnusedInt(term__V814_count);
  do {
    /* Contraction rule DEFS-Forms-Constructors-2. */
    ASSERT(sink__V813->context, !strcmp(SYMBOL(term__V814),  "Forms-Constructors$4" ));
    Term sub__V815 = SUB(term__V814, 0); permitUnusedTerm(sub__V815); int sub__V815_count = term__V814_count*LINK_COUNT(sub__V815); permitUnusedInt(sub__V815_count);
    CRSX_CHECK_SORT(sink__V813->context, sub__V815, &sort_M_Reified_xSort); /* sub__V815 = &#111 */
    Term sub__V816 = SUB(term__V814, 1); permitUnusedTerm(sub__V816); int sub__V816_count = term__V814_count*LINK_COUNT(sub__V816); permitUnusedInt(sub__V816_count);
    CRSX_CHECK_SORT(sink__V813->context, sub__V816, &sort_M_Reified_xSort); /* sub__V816 = &#112 */
    Term sub__V817 = LINK(sink__V813->context, SUB(term__V814, 2)); int sub__V817_count = term__V814_count*LINK_COUNT(sub__V817); permitUnusedInt(sub__V817_count);
    CRSX_CHECK_SORT(sink__V813->context, sub__V817, &sort_M_Reified_xForm); /* sub__V817 = &#113 */
    Term sub__V818 = LINK(sink__V813->context, SUB(term__V814, 3)); int sub__V818_count = term__V814_count*LINK_COUNT(sub__V818); permitUnusedInt(sub__V818_count);
    /* sub__V818 = &#12 */
    UNLINK(sink__V813->context, term__V814);
    { START(sink__V813, _M_Forms_Constructors);
      { START(sink__V813, _M__sCons);
        COPY(sink__V813, sub__V817);COPY(sink__V813, sub__V818);END(sink__V813, _M__sCons); }
      END(sink__V813, _M_Forms_Constructors); }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Forms-Constructors$3. */
int conBindOffs_M_Forms_Constructors_s3[] = {0 , 0};
char *nameFun_M_Forms_Constructors_s3(Term term) { return  "Forms-Constructors$3" ; }
struct _ConstructionDescriptor descriptor_M_Forms_Constructors_s3 = {NULL, 0, 1, sizeof(STRUCT_Con_M_Forms_Constructors_s3), conBindOffs_M_Forms_Constructors_s3, &nameFun_M_Forms_Constructors_s3, &step_M_Forms_Constructors_s3};

int step_M_Forms_Constructors_s3(Sink sink__V819, Term term__V820)
{
  int term__V820_count = LINK_COUNT(term__V820); permitUnusedInt(term__V820_count);
  do {
    /* Contraction rule DEFS-Forms-Constructors-1. */
    ASSERT(sink__V819->context, !strcmp(SYMBOL(term__V820),  "Forms-Constructors$3" ));
    Term sub__V821 = LINK(sink__V819->context, SUB(term__V820, 0)); int sub__V821_count = term__V820_count*LINK_COUNT(sub__V821); permitUnusedInt(sub__V821_count);
    /* sub__V821 = &#12 */
    UNLINK(sink__V819->context, term__V820);
    { START(sink__V819, _M_Forms_Constructors);
      COPY(sink__V819, sub__V821);END(sink__V819, _M_Forms_Constructors); }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION SortNames. */
int conBindOffs_M_SortNames[] = {0 , 0};
char *nameFun_M_SortNames(Term term) { return  "SortNames" ; }
struct _ConstructionDescriptor descriptor_M_SortNames = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_SortNames), conBindOffs_M_SortNames, &nameFun_M_SortNames, &step_M_SortNames};

int step_M_SortNames(Sink sink__V822, Term term__V823)
{
  int term__V823_count = LINK_COUNT(term__V823); permitUnusedInt(term__V823_count);
  do {
    /* Contraction rule DEFS-SortNames-1. */
    ASSERT(sink__V822->context, !strcmp(SYMBOL(term__V823),  "SortNames" ));
    Term sub__V824 = LINK(sink__V822->context, SUB(term__V823, 0)); int sub__V824_count = term__V823_count*LINK_COUNT(sub__V824); permitUnusedInt(sub__V824_count);
    /* sub__V824 = &#1 */
    NamedPropertyLink namedP__V825 = LINK_NamedPropertyLink(sink__V822->context, NAMED_PROPERTIES(term__V823));
    VariablePropertyLink varP__V826 = LINK_VariablePropertyLink(sink__V822->context, VARIABLE_PROPERTIES(term__V823));
    UNLINK(sink__V822->context, term__V823);
    { START(sink__V822, _M__sTextCons);
      { START(sink__V822, _M__sTextChars);
        LITERAL(sink__V822,  "sortNam" ); END(sink__V822, _M__sTextChars); }
      { START(sink__V822, _M__sTextCons);
        { START(sink__V822, _M__sTextEmbed);
          { START(sink__V822, _M_AsText);
            { START(sink__V822, _M_MANGLE);
              COPY(sink__V822, sub__V824);END(sink__V822, _M_MANGLE); }
            END(sink__V822, _M_AsText); }
          END(sink__V822, _M__sTextEmbed); }
        { START(sink__V822, _M__sTextNil);
          END(sink__V822, _M__sTextNil); }
        END(sink__V822, _M__sTextCons); }
      END(sink__V822, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V822->context, namedP__V825); UNLINK_VariablePropertyLink(sink__V822->context, varP__V826);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION UnVariable. */
int conBindOffs_M_UnVariable[] = {0 , 0};
char *nameFun_M_UnVariable(Term term) { return  "UnVariable" ; }
struct _ConstructionDescriptor descriptor_M_UnVariable = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_UnVariable), conBindOffs_M_UnVariable, &nameFun_M_UnVariable, &step_M_UnVariable};

int step_M_UnVariable(Sink sink__V827, Term term__V828)
{
  int term__V828_count = LINK_COUNT(term__V828); permitUnusedInt(term__V828_count);
  Term sub__V829 = FORCE(sink__V827->context, SUB(term__V828, 0));
  EnumOf_M_STRING_xENTRY choice__V830 = (IS_VARIABLE_USE(sub__V829) ? VarOf_M_STRING_xENTRY : (EnumOf_M_STRING_xENTRY) TAG(sub__V829));
  switch (choice__V830)
  {
    case Data_M_VARIABLE: { /* Function DEFS-UnVariable-1$UnVariable$VARIABLE case VARIABLE */
      ASSERT(sink__V827->context, !strcmp(SYMBOL(term__V828),  "UnVariable" ));
      Term sub__V831 = SUB(term__V828, 0); permitUnusedTerm(sub__V831); int sub__V831_count = term__V828_count*LINK_COUNT(sub__V831); permitUnusedInt(sub__V831_count);
      CRSX_CHECK_SORT(sink__V827->context, sub__V831, &sort_M_STRING_xENTRY); ASSERT(sink__V827->context, !strcmp(SYMBOL(sub__V831),  "VARIABLE" ));
      Term sub__V832 = LINK(sink__V827->context, SUB(sub__V831, 0)); int sub__V832_count = sub__V831_count*LINK_COUNT(sub__V832); permitUnusedInt(sub__V832_count);
      CRSX_CHECK_SORT(sink__V827->context, sub__V832, &sort_M_Reified_xVariable); /* sub__V832 = &#0-0 */
      NamedPropertyLink namedP__V833 = LINK_NamedPropertyLink(sink__V827->context, NAMED_PROPERTIES(term__V828));
      VariablePropertyLink varP__V834 = LINK_VariablePropertyLink(sink__V827->context, VARIABLE_PROPERTIES(term__V828));
      UNLINK(sink__V827->context, term__V828);
      ADD_PROPERTIES(sink__V827, LINK_NamedPropertyLink(sink__V827->context, namedP__V833), LINK_VariablePropertyLink(sink__V827->context, varP__V834));
      { START(sink__V827, _M_UnVariable_s1);
        COPY(sink__V827, sub__V832);END(sink__V827, _M_UnVariable_s1); }
      UNLINK_NamedPropertyLink(sink__V827->context, namedP__V833); UNLINK_VariablePropertyLink(sink__V827->context, varP__V834);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION DelayMapText$1. */
int conBindOffs_M_DelayMapText_s1[] = {0 , 0 , 2};
char *nameFun_M_DelayMapText_s1(Term term) { return  "DelayMapText$1" ; }
struct _ConstructionDescriptor descriptor_M_DelayMapText_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_DelayMapText_s1), conBindOffs_M_DelayMapText_s1, &nameFun_M_DelayMapText_s1, &step_M_DelayMapText_s1};

int step_M_DelayMapText_s1(Sink sink__V835, Term term__V836)
{
  int term__V836_count = LINK_COUNT(term__V836); permitUnusedInt(term__V836_count);
  Term sub__V837 = FORCE(sink__V835->context, SUB(term__V836, 0));
  EnumOf_M__sList choice__V838 = (IS_VARIABLE_USE(sub__V837) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V837));
  switch (choice__V838)
  {
    case Data_M__sCons: { /* Function DEFS-DelayMapText-1$DelayMapText$1$$Cons case $Cons */
      ASSERT(sink__V835->context, !strcmp(SYMBOL(term__V836),  "DelayMapText$1" ));
      Term sub__V839 = SUB(term__V836, 0); permitUnusedTerm(sub__V839); int sub__V839_count = term__V836_count*LINK_COUNT(sub__V839); permitUnusedInt(sub__V839_count);
      ASSERT(sink__V835->context, !strcmp(SYMBOL(sub__V839),  "$Cons" ));
      Term sub__V840 = LINK(sink__V835->context, SUB(sub__V839, 0)); int sub__V840_count = sub__V839_count*LINK_COUNT(sub__V840); permitUnusedInt(sub__V840_count);
      /* sub__V840 = &#0-0 */
      Term sub__V841 = LINK(sink__V835->context, SUB(sub__V839, 1)); int sub__V841_count = sub__V839_count*LINK_COUNT(sub__V841); permitUnusedInt(sub__V841_count);
      /* sub__V841 = &#0-1 */
      Variable x__V842 = BINDER(term__V836,1,0); if (term__V836_count <= 1) UNBIND(x__V842);
      Variable x__V843 = BINDER(term__V836,1,1); if (term__V836_count <= 1) UNBIND(x__V843);
      Term sub__V844 = LINK(sink__V835->context, SUB(term__V836, 1)); int sub__V844_count = term__V836_count*LINK_COUNT(sub__V844); permitUnusedInt(sub__V844_count);
      CRSX_CHECK_SORT(sink__V835->context, sub__V844, &sort_M_Reified_xVariable); /* sub__V844 = &#2 */
      NamedPropertyLink namedP__V845 = LINK_NamedPropertyLink(sink__V835->context, NAMED_PROPERTIES(term__V836));
      VariablePropertyLink varP__V846 = LINK_VariablePropertyLink(sink__V835->context, VARIABLE_PROPERTIES(term__V836));
      UNLINK(sink__V835->context, term__V836);
      ADD_PROPERTIES(sink__V835, LINK_NamedPropertyLink(sink__V835->context, namedP__V845), LINK_VariablePropertyLink(sink__V835->context, varP__V846));
      { START(sink__V835, _M_DelayMapText_s2);
        COPY(sink__V835, sub__V840);COPY(sink__V835, sub__V841);{ if (!IS_BOUND(x__V842)) { REBIND(x__V842);
            REBIND(x__V843);
            Variable binds__V847[2] = {x__V842,x__V843}; BINDS(sink__V835, 2, binds__V847);
            COPY(sink__V835, sub__V844); /* REUSED SUBSTITUTION */  }
          else { Variable b__V848 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V835->context,"b__V848");
            Variable b__V849 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V835->context,"b__V849");
            Variable binds__V850[2] = {b__V848,b__V849}; BINDS(sink__V835, 2, binds__V850);
            {
              Term arg__V851;
              { Sink buf__V852 = ALLOCA_BUFFER(sink__V835->context);
                USE(buf__V852, b__V848); arg__V851 = BUFFER_TERM(buf__V852); FREE_BUFFER(buf__V852); }
              Term arg__V853;
              { Sink buf__V854 = ALLOCA_BUFFER(sink__V835->context);
                USE(buf__V854, b__V849); arg__V853 = BUFFER_TERM(buf__V854); FREE_BUFFER(buf__V854); }
              Variable vars__V855[2] = {x__V842,x__V843};
              Term args__V856[2] = {arg__V851,arg__V853};
              struct _SubstitutionFrame substitution__V857 = {NULL, 0, 2, vars__V855, args__V856, NULL};
              SUBSTITUTE(sink__V835, sub__V844, &substitution__V857); }
                }
           }
        END(sink__V835, _M_DelayMapText_s2); }
      UNLINK_NamedPropertyLink(sink__V835->context, namedP__V845); UNLINK_VariablePropertyLink(sink__V835->context, varP__V846);
      
      return 1;
    break; } case Data_M__sNil: { /* Function DEFS-DelayMapText-2$DelayMapText$1$$Nil case $Nil */
      ASSERT(sink__V835->context, !strcmp(SYMBOL(term__V836),  "DelayMapText$1" ));
      Term sub__V858 = SUB(term__V836, 0); permitUnusedTerm(sub__V858); int sub__V858_count = term__V836_count*LINK_COUNT(sub__V858); permitUnusedInt(sub__V858_count);
      ASSERT(sink__V835->context, !strcmp(SYMBOL(sub__V858),  "$Nil" ));
      Variable x__V859 = BINDER(term__V836,1,0); if (term__V836_count <= 1) UNBIND(x__V859);
      Variable x__V860 = BINDER(term__V836,1,1); if (term__V836_count <= 1) UNBIND(x__V860);
      Term sub__V861 = LINK(sink__V835->context, SUB(term__V836, 1)); int sub__V861_count = term__V836_count*LINK_COUNT(sub__V861); permitUnusedInt(sub__V861_count);
      CRSX_CHECK_SORT(sink__V835->context, sub__V861, &sort_M_Reified_xVariable); /* sub__V861 = &#0 */
      NamedPropertyLink namedP__V862 = LINK_NamedPropertyLink(sink__V835->context, NAMED_PROPERTIES(term__V836));
      VariablePropertyLink varP__V863 = LINK_VariablePropertyLink(sink__V835->context, VARIABLE_PROPERTIES(term__V836));
      UNLINK(sink__V835->context, term__V836);
      ADD_PROPERTIES(sink__V835, LINK_NamedPropertyLink(sink__V835->context, namedP__V862), LINK_VariablePropertyLink(sink__V835->context, varP__V863));
      { START(sink__V835, _M_DelayMapText_s3);
        { if (!IS_BOUND(x__V859)) { REBIND(x__V859);
            REBIND(x__V860);
            Variable binds__V864[2] = {x__V859,x__V860}; BINDS(sink__V835, 2, binds__V864);
            COPY(sink__V835, sub__V861); /* REUSED SUBSTITUTION */  }
          else { Variable b__V865 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V835->context,"b__V865");
            Variable b__V866 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V835->context,"b__V866");
            Variable binds__V867[2] = {b__V865,b__V866}; BINDS(sink__V835, 2, binds__V867);
            {
              Term arg__V868;
              { Sink buf__V869 = ALLOCA_BUFFER(sink__V835->context);
                USE(buf__V869, b__V865); arg__V868 = BUFFER_TERM(buf__V869); FREE_BUFFER(buf__V869); }
              Term arg__V870;
              { Sink buf__V871 = ALLOCA_BUFFER(sink__V835->context);
                USE(buf__V871, b__V866); arg__V870 = BUFFER_TERM(buf__V871); FREE_BUFFER(buf__V871); }
              Variable vars__V872[2] = {x__V859,x__V860};
              Term args__V873[2] = {arg__V868,arg__V870};
              struct _SubstitutionFrame substitution__V874 = {NULL, 0, 2, vars__V872, args__V873, NULL};
              SUBSTITUTE(sink__V835, sub__V861, &substitution__V874); }
                }
           }
        END(sink__V835, _M_DelayMapText_s3); }
      UNLINK_NamedPropertyLink(sink__V835->context, namedP__V862); UNLINK_VariablePropertyLink(sink__V835->context, varP__V863);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION DelayMapText$3. */
int conBindOffs_M_DelayMapText_s3[] = {0 , 2};
char *nameFun_M_DelayMapText_s3(Term term) { return  "DelayMapText$3" ; }
struct _ConstructionDescriptor descriptor_M_DelayMapText_s3 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_DelayMapText_s3), conBindOffs_M_DelayMapText_s3, &nameFun_M_DelayMapText_s3, &step_M_DelayMapText_s3};

int step_M_DelayMapText_s3(Sink sink__V875, Term term__V876)
{
  int term__V876_count = LINK_COUNT(term__V876); permitUnusedInt(term__V876_count);
  do {
    /* Contraction rule DEFS-DelayMapText-2. */
    ASSERT(sink__V875->context, !strcmp(SYMBOL(term__V876),  "DelayMapText$3" ));
    Variable x__V877 = BINDER(term__V876,0,0); if (term__V876_count <= 1) UNBIND(x__V877);
    Variable x__V878 = BINDER(term__V876,0,1); if (term__V876_count <= 1) UNBIND(x__V878);
    Term sub__V879 = SUB(term__V876, 0); permitUnusedTerm(sub__V879); int sub__V879_count = term__V876_count*LINK_COUNT(sub__V879); permitUnusedInt(sub__V879_count);
    CRSX_CHECK_SORT(sink__V875->context, sub__V879, &sort_M_Reified_xVariable); /* sub__V879 = &#1 */
    NamedPropertyLink namedP__V880 = LINK_NamedPropertyLink(sink__V875->context, NAMED_PROPERTIES(term__V876));
    VariablePropertyLink varP__V881 = LINK_VariablePropertyLink(sink__V875->context, VARIABLE_PROPERTIES(term__V876));
    UNLINK(sink__V875->context, term__V876);
    { START(sink__V875, _M__sTextNil); END(sink__V875, _M__sTextNil); }
    UNLINK_NamedPropertyLink(sink__V875->context, namedP__V880); UNLINK_VariablePropertyLink(sink__V875->context, varP__V881);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DelayMapText$2. */
int conBindOffs_M_DelayMapText_s2[] = {0 , 0 , 0 , 2};
char *nameFun_M_DelayMapText_s2(Term term) { return  "DelayMapText$2" ; }
struct _ConstructionDescriptor descriptor_M_DelayMapText_s2 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_DelayMapText_s2), conBindOffs_M_DelayMapText_s2, &nameFun_M_DelayMapText_s2, &step_M_DelayMapText_s2};

int step_M_DelayMapText_s2(Sink sink__V882, Term term__V883)
{
  int term__V883_count = LINK_COUNT(term__V883); permitUnusedInt(term__V883_count);
  do {
    /* Contraction rule DEFS-DelayMapText-1. */
    ASSERT(sink__V882->context, !strcmp(SYMBOL(term__V883),  "DelayMapText$2" ));
    Term sub__V884 = LINK(sink__V882->context, SUB(term__V883, 0)); int sub__V884_count = term__V883_count*LINK_COUNT(sub__V884); permitUnusedInt(sub__V884_count);
    /* sub__V884 = &#21 */
    Term sub__V885 = LINK(sink__V882->context, SUB(term__V883, 1)); int sub__V885_count = term__V883_count*LINK_COUNT(sub__V885); permitUnusedInt(sub__V885_count);
    /* sub__V885 = &#22 */
    Variable x__V886 = BINDER(term__V883,2,0); if (term__V883_count <= 1) UNBIND(x__V886);
    Variable x__V887 = BINDER(term__V883,2,1); if (term__V883_count <= 1) UNBIND(x__V887);
    Term sub__V888 = LINK(sink__V882->context, SUB(term__V883, 2)); int sub__V888_count = term__V883_count*LINK_COUNT(sub__V888); permitUnusedInt(sub__V888_count);
    CRSX_CHECK_SORT(sink__V882->context, sub__V888, &sort_M_Reified_xVariable); UNLINK_SUB(sink__V882->context, term__V883,  2); NORMALIZE(sink__V882->context, sub__V888); SUB(term__V883,  2) = LINK(sink__V882->context, sub__V888);
    /* sub__V888 = &#1 */
    NamedPropertyLink namedP__V889 = LINK_NamedPropertyLink(sink__V882->context, NAMED_PROPERTIES(term__V883));
    VariablePropertyLink varP__V890 = LINK_VariablePropertyLink(sink__V882->context, VARIABLE_PROPERTIES(term__V883));
    UNLINK(sink__V882->context, term__V883);
    { START(sink__V882, _M__sTextCons);
      { START(sink__V882, _M__sTextEmbed);
        { START(sink__V882, _M_AsText);
          {
            Term arg__V891;
            { Sink buf__V892 = ALLOCA_BUFFER(sink__V882->context);
              { START(buf__V892, _M_OK); END(buf__V892, _M_OK); } arg__V891 = BUFFER_TERM(buf__V892); FREE_BUFFER(buf__V892); }
            Term arg__V893;
            { Sink buf__V894 = ALLOCA_BUFFER(sink__V882->context);
              COPY(buf__V894, sub__V884);arg__V893 = BUFFER_TERM(buf__V894); FREE_BUFFER(buf__V894); }
            Variable vars__V895[2] = {x__V886,x__V887};
            Term args__V896[2] = {arg__V891,arg__V893};
            struct _SubstitutionFrame substitution__V897 = {NULL, 0, 2, vars__V895, args__V896, NULL};
            SUBSTITUTE(sink__V882, LINK(sink__V882->context,sub__V888), &substitution__V897); }
          END(sink__V882, _M_AsText); }
        END(sink__V882, _M__sTextEmbed); }
      { START(sink__V882, _M__sTextCons);
        { START(sink__V882, _M__sTextEmbed);
          { START(sink__V882, _M_AsText);
            { START(sink__V882, _M_DelayMapText_s1);
              COPY(sink__V882, sub__V885);{ Variable x__V898 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V882->context,"x__V898");
                Variable x__V899 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V882->context,"x__V899");
                Variable binds__V900[2] = {x__V898,x__V899}; BINDS(sink__V882, 2, binds__V900);
                {
                  Term arg__V901;
                  { Sink buf__V902 = ALLOCA_BUFFER(sink__V882->context);
                    USE(buf__V902, x__V898); arg__V901 = BUFFER_TERM(buf__V902); FREE_BUFFER(buf__V902); }
                  Term arg__V903;
                  { Sink buf__V904 = ALLOCA_BUFFER(sink__V882->context);
                    USE(buf__V904, x__V899); arg__V903 = BUFFER_TERM(buf__V904); FREE_BUFFER(buf__V904); }
                  Variable vars__V905[2] = {x__V886,x__V887};
                  Term args__V906[2] = {arg__V901,arg__V903};
                  struct _SubstitutionFrame substitution__V907 = {NULL, 0, 2, vars__V905, args__V906, NULL};
                  SUBSTITUTE(sink__V882, sub__V888, &substitution__V907); }
                 }
              END(sink__V882, _M_DelayMapText_s1); }
            END(sink__V882, _M_AsText); }
          END(sink__V882, _M__sTextEmbed); }
        { START(sink__V882, _M__sTextNil);
          END(sink__V882, _M__sTextNil); }
        END(sink__V882, _M__sTextCons); }
      END(sink__V882, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V882->context, namedP__V889); UNLINK_VariablePropertyLink(sink__V882->context, varP__V890);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION FormArguments-binder-offsets. */
int conBindOffs_M_FormArguments__binder__offsets[] = {0 , 0 , 0};
char *nameFun_M_FormArguments__binder__offsets(Term term) { return  "FormArguments-binder-offsets" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__offsets = {NULL, 0, 2, sizeof(STRUCT_Con_M_FormArguments__binder__offsets), conBindOffs_M_FormArguments__binder__offsets, &nameFun_M_FormArguments__binder__offsets, &step_M_FormArguments__binder__offsets};

int step_M_FormArguments__binder__offsets(Sink sink__V908, Term term__V909)
{
  int term__V909_count = LINK_COUNT(term__V909); permitUnusedInt(term__V909_count);
  Term sub__V910 = FORCE(sink__V908->context, SUB(term__V909, 0));
  EnumOf_M__sList choice__V911 = (IS_VARIABLE_USE(sub__V910) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V910));
  switch (choice__V911)
  {
    case Data_M__sCons: { /* Function DEFS-FormArguments-binder-offsets-1$FormArguments-binder-offsets$$Cons case $Cons */
      ASSERT(sink__V908->context, !strcmp(SYMBOL(term__V909),  "FormArguments-binder-offsets" ));
      Term sub__V912 = SUB(term__V909, 0); permitUnusedTerm(sub__V912); int sub__V912_count = term__V909_count*LINK_COUNT(sub__V912); permitUnusedInt(sub__V912_count);
      ASSERT(sink__V908->context, !strcmp(SYMBOL(sub__V912),  "$Cons" ));
      Term sub__V913 = LINK(sink__V908->context, SUB(sub__V912, 0)); int sub__V913_count = sub__V912_count*LINK_COUNT(sub__V913); permitUnusedInt(sub__V913_count);
      /* sub__V913 = &#0-0 */
      Term sub__V914 = LINK(sink__V908->context, SUB(sub__V912, 1)); int sub__V914_count = sub__V912_count*LINK_COUNT(sub__V914); permitUnusedInt(sub__V914_count);
      /* sub__V914 = &#0-1 */
      Term sub__V915 = LINK(sink__V908->context, SUB(term__V909, 1)); int sub__V915_count = term__V909_count*LINK_COUNT(sub__V915); permitUnusedInt(sub__V915_count);
      /* sub__V915 = &#2 */
      NamedPropertyLink namedP__V916 = LINK_NamedPropertyLink(sink__V908->context, NAMED_PROPERTIES(term__V909));
      VariablePropertyLink varP__V917 = LINK_VariablePropertyLink(sink__V908->context, VARIABLE_PROPERTIES(term__V909));
      UNLINK(sink__V908->context, term__V909);
      ADD_PROPERTIES(sink__V908, LINK_NamedPropertyLink(sink__V908->context, namedP__V916), LINK_VariablePropertyLink(sink__V908->context, varP__V917));
      { START(sink__V908, _M_FormArguments__binder__offsets_s1);
        COPY(sink__V908, sub__V913);COPY(sink__V908, sub__V914);COPY(sink__V908, sub__V915);END(sink__V908, _M_FormArguments__binder__offsets_s1); }
      UNLINK_NamedPropertyLink(sink__V908->context, namedP__V916); UNLINK_VariablePropertyLink(sink__V908->context, varP__V917);
      
      return 1;
    break; } case Data_M__sNil: { /* Function DEFS-FormArguments-binder-offsets-3$FormArguments-binder-offsets$$Nil case $Nil */
      ASSERT(sink__V908->context, !strcmp(SYMBOL(term__V909),  "FormArguments-binder-offsets" ));
      Term sub__V918 = SUB(term__V909, 0); permitUnusedTerm(sub__V918); int sub__V918_count = term__V909_count*LINK_COUNT(sub__V918); permitUnusedInt(sub__V918_count);
      ASSERT(sink__V908->context, !strcmp(SYMBOL(sub__V918),  "$Nil" ));
      Term sub__V919 = LINK(sink__V908->context, SUB(term__V909, 1)); int sub__V919_count = term__V909_count*LINK_COUNT(sub__V919); permitUnusedInt(sub__V919_count);
      /* sub__V919 = &#0 */
      NamedPropertyLink namedP__V920 = LINK_NamedPropertyLink(sink__V908->context, NAMED_PROPERTIES(term__V909));
      VariablePropertyLink varP__V921 = LINK_VariablePropertyLink(sink__V908->context, VARIABLE_PROPERTIES(term__V909));
      UNLINK(sink__V908->context, term__V909);
      ADD_PROPERTIES(sink__V908, LINK_NamedPropertyLink(sink__V908->context, namedP__V920), LINK_VariablePropertyLink(sink__V908->context, varP__V921));
      { START(sink__V908, _M_FormArguments__binder__offsets_s4);
        COPY(sink__V908, sub__V919);END(sink__V908, _M_FormArguments__binder__offsets_s4); }
      UNLINK_NamedPropertyLink(sink__V908->context, namedP__V920); UNLINK_VariablePropertyLink(sink__V908->context, varP__V921);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION MapIndexText$2. */
int conBindOffs_M_MapIndexText_s2[] = {0 , 0 , 0 , 2 , 2};
char *nameFun_M_MapIndexText_s2(Term term) { return  "MapIndexText$2" ; }
struct _ConstructionDescriptor descriptor_M_MapIndexText_s2 = {&sort_M_Reified_xVariable, 0, 4, sizeof(STRUCT_Con_M_MapIndexText_s2), conBindOffs_M_MapIndexText_s2, &nameFun_M_MapIndexText_s2, &step_M_MapIndexText_s2};

int step_M_MapIndexText_s2(Sink sink__V922, Term term__V923)
{
  int term__V923_count = LINK_COUNT(term__V923); permitUnusedInt(term__V923_count);
  do {
    /* Contraction rule DEFS-MapIndexText-1. */
    ASSERT(sink__V922->context, !strcmp(SYMBOL(term__V923),  "MapIndexText$2" ));
    Term sub__V924 = LINK(sink__V922->context, SUB(term__V923, 0)); int sub__V924_count = term__V923_count*LINK_COUNT(sub__V924); permitUnusedInt(sub__V924_count);
    /* sub__V924 = &#21 */
    Term sub__V925 = LINK(sink__V922->context, SUB(term__V923, 1)); int sub__V925_count = term__V923_count*LINK_COUNT(sub__V925); permitUnusedInt(sub__V925_count);
    /* sub__V925 = &#22 */
    Variable x__V926 = BINDER(term__V923,2,0); if (term__V923_count <= 1) UNBIND(x__V926);
    Variable x__V927 = BINDER(term__V923,2,1); if (term__V923_count <= 1) UNBIND(x__V927);
    Term sub__V928 = LINK(sink__V922->context, SUB(term__V923, 2)); int sub__V928_count = term__V923_count*LINK_COUNT(sub__V928); permitUnusedInt(sub__V928_count);
    CRSX_CHECK_SORT(sink__V922->context, sub__V928, &sort_M_Reified_xVariable); UNLINK_SUB(sink__V922->context, term__V923,  2); NORMALIZE(sink__V922->context, sub__V928); SUB(term__V923,  2) = LINK(sink__V922->context, sub__V928);
    /* sub__V928 = &#1 */
    Term sub__V929 = LINK(sink__V922->context, SUB(term__V923, 3)); int sub__V929_count = term__V923_count*LINK_COUNT(sub__V929); permitUnusedInt(sub__V929_count);
    UNLINK_SUB(sink__V922->context, term__V923,  3); NORMALIZE(sink__V922->context, sub__V929); SUB(term__V923,  3) = LINK(sink__V922->context, sub__V929);
    /* sub__V929 = &#3 */
    NamedPropertyLink namedP__V930 = LINK_NamedPropertyLink(sink__V922->context, NAMED_PROPERTIES(term__V923));
    VariablePropertyLink varP__V931 = LINK_VariablePropertyLink(sink__V922->context, VARIABLE_PROPERTIES(term__V923));
    UNLINK(sink__V922->context, term__V923);
    { START(sink__V922, _M__sTextCons);
      { START(sink__V922, _M__sTextEmbed);
        { START(sink__V922, _M_AsText);
          {
            Term arg__V932;
            { Sink buf__V933 = ALLOCA_BUFFER(sink__V922->context);
              COPY(buf__V933, sub__V924);arg__V932 = BUFFER_TERM(buf__V933); FREE_BUFFER(buf__V933); }
            Term arg__V934;
            { Sink buf__V935 = ALLOCA_BUFFER(sink__V922->context);
              COPY(buf__V935, LINK(buf__V935->context, sub__V929));arg__V934 = BUFFER_TERM(buf__V935); FREE_BUFFER(buf__V935); }
            Variable vars__V936[2] = {x__V926,x__V927};
            Term args__V937[2] = {arg__V932,arg__V934};
            struct _SubstitutionFrame substitution__V938 = {NULL, 0, 2, vars__V936, args__V937, NULL};
            SUBSTITUTE(sink__V922, LINK(sink__V922->context,sub__V928), &substitution__V938); }
          END(sink__V922, _M_AsText); }
        END(sink__V922, _M__sTextEmbed); }
      { START(sink__V922, _M__sTextCons);
        { START(sink__V922, _M__sTextEmbed);
          { START(sink__V922, _M_AsText);
            { START(sink__V922, _M_MapIndexText_s1);
              COPY(sink__V922, sub__V925);{ Variable x__V939 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V922->context,"x__V939");
                Variable x__V940 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V922->context,"x__V940");
                Variable binds__V941[2] = {x__V939,x__V940}; BINDS(sink__V922, 2, binds__V941);
                {
                  Term arg__V942;
                  { Sink buf__V943 = ALLOCA_BUFFER(sink__V922->context);
                    USE(buf__V943, x__V939); arg__V942 = BUFFER_TERM(buf__V943); FREE_BUFFER(buf__V943); }
                  Term arg__V944;
                  { Sink buf__V945 = ALLOCA_BUFFER(sink__V922->context);
                    USE(buf__V945, x__V940); arg__V944 = BUFFER_TERM(buf__V945); FREE_BUFFER(buf__V945); }
                  Variable vars__V946[2] = {x__V926,x__V927};
                  Term args__V947[2] = {arg__V942,arg__V944};
                  struct _SubstitutionFrame substitution__V948 = {NULL, 0, 2, vars__V946, args__V947, NULL};
                  SUBSTITUTE(sink__V922, sub__V928, &substitution__V948); }
                 }
              { double num__V949;
                num__V949 = (double) 1; { double tmp__V950;
                  tmp__V950 = DOUBLE(sub__V929); num__V949 += tmp__V950; }
                LITERALNF(sink__V922, (size_t) 31, "%G", num__V949); }
              END(sink__V922, _M_MapIndexText_s1); }
            END(sink__V922, _M_AsText); }
          END(sink__V922, _M__sTextEmbed); }
        { START(sink__V922, _M__sTextNil);
          END(sink__V922, _M__sTextNil); }
        END(sink__V922, _M__sTextCons); }
      END(sink__V922, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V922->context, namedP__V930); UNLINK_VariablePropertyLink(sink__V922->context, varP__V931);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION MapIndexText$1. */
int conBindOffs_M_MapIndexText_s1[] = {0 , 0 , 2 , 2};
char *nameFun_M_MapIndexText_s1(Term term) { return  "MapIndexText$1" ; }
struct _ConstructionDescriptor descriptor_M_MapIndexText_s1 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_MapIndexText_s1), conBindOffs_M_MapIndexText_s1, &nameFun_M_MapIndexText_s1, &step_M_MapIndexText_s1};

int step_M_MapIndexText_s1(Sink sink__V951, Term term__V952)
{
  int term__V952_count = LINK_COUNT(term__V952); permitUnusedInt(term__V952_count);
  Term sub__V953 = FORCE(sink__V951->context, SUB(term__V952, 0));
  EnumOf_M__sList choice__V954 = (IS_VARIABLE_USE(sub__V953) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V953));
  switch (choice__V954)
  {
    case Data_M__sCons: { /* Function DEFS-MapIndexText-1$MapIndexText$1$$Cons case $Cons */
      ASSERT(sink__V951->context, !strcmp(SYMBOL(term__V952),  "MapIndexText$1" ));
      Term sub__V955 = SUB(term__V952, 0); permitUnusedTerm(sub__V955); int sub__V955_count = term__V952_count*LINK_COUNT(sub__V955); permitUnusedInt(sub__V955_count);
      ASSERT(sink__V951->context, !strcmp(SYMBOL(sub__V955),  "$Cons" ));
      Term sub__V956 = LINK(sink__V951->context, SUB(sub__V955, 0)); int sub__V956_count = sub__V955_count*LINK_COUNT(sub__V956); permitUnusedInt(sub__V956_count);
      /* sub__V956 = &#0-0 */
      Term sub__V957 = LINK(sink__V951->context, SUB(sub__V955, 1)); int sub__V957_count = sub__V955_count*LINK_COUNT(sub__V957); permitUnusedInt(sub__V957_count);
      /* sub__V957 = &#0-1 */
      Variable x__V958 = BINDER(term__V952,1,0); if (term__V952_count <= 1) UNBIND(x__V958);
      Variable x__V959 = BINDER(term__V952,1,1); if (term__V952_count <= 1) UNBIND(x__V959);
      Term sub__V960 = LINK(sink__V951->context, SUB(term__V952, 1)); int sub__V960_count = term__V952_count*LINK_COUNT(sub__V960); permitUnusedInt(sub__V960_count);
      CRSX_CHECK_SORT(sink__V951->context, sub__V960, &sort_M_Reified_xVariable); /* sub__V960 = &#2 */
      Term sub__V961 = LINK(sink__V951->context, SUB(term__V952, 2)); int sub__V961_count = term__V952_count*LINK_COUNT(sub__V961); permitUnusedInt(sub__V961_count);
      /* sub__V961 = &#3 */
      NamedPropertyLink namedP__V962 = LINK_NamedPropertyLink(sink__V951->context, NAMED_PROPERTIES(term__V952));
      VariablePropertyLink varP__V963 = LINK_VariablePropertyLink(sink__V951->context, VARIABLE_PROPERTIES(term__V952));
      UNLINK(sink__V951->context, term__V952);
      ADD_PROPERTIES(sink__V951, LINK_NamedPropertyLink(sink__V951->context, namedP__V962), LINK_VariablePropertyLink(sink__V951->context, varP__V963));
      { START(sink__V951, _M_MapIndexText_s2);
        COPY(sink__V951, sub__V956);COPY(sink__V951, sub__V957);{ if (!IS_BOUND(x__V958)) { REBIND(x__V958);
            REBIND(x__V959);
            Variable binds__V964[2] = {x__V958,x__V959}; BINDS(sink__V951, 2, binds__V964);
            COPY(sink__V951, sub__V960); /* REUSED SUBSTITUTION */  }
          else { Variable b__V965 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V951->context,"b__V965");
            Variable b__V966 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V951->context,"b__V966");
            Variable binds__V967[2] = {b__V965,b__V966}; BINDS(sink__V951, 2, binds__V967);
            {
              Term arg__V968;
              { Sink buf__V969 = ALLOCA_BUFFER(sink__V951->context);
                USE(buf__V969, b__V965); arg__V968 = BUFFER_TERM(buf__V969); FREE_BUFFER(buf__V969); }
              Term arg__V970;
              { Sink buf__V971 = ALLOCA_BUFFER(sink__V951->context);
                USE(buf__V971, b__V966); arg__V970 = BUFFER_TERM(buf__V971); FREE_BUFFER(buf__V971); }
              Variable vars__V972[2] = {x__V958,x__V959};
              Term args__V973[2] = {arg__V968,arg__V970};
              struct _SubstitutionFrame substitution__V974 = {NULL, 0, 2, vars__V972, args__V973, NULL};
              SUBSTITUTE(sink__V951, sub__V960, &substitution__V974); }
                }
           }
        COPY(sink__V951, sub__V961);END(sink__V951, _M_MapIndexText_s2); }
      UNLINK_NamedPropertyLink(sink__V951->context, namedP__V962); UNLINK_VariablePropertyLink(sink__V951->context, varP__V963);
      
      return 1;
    break; } case Data_M__sNil: { /* Function DEFS-MapIndexText-2$MapIndexText$1$$Nil case $Nil */
      ASSERT(sink__V951->context, !strcmp(SYMBOL(term__V952),  "MapIndexText$1" ));
      Term sub__V975 = SUB(term__V952, 0); permitUnusedTerm(sub__V975); int sub__V975_count = term__V952_count*LINK_COUNT(sub__V975); permitUnusedInt(sub__V975_count);
      ASSERT(sink__V951->context, !strcmp(SYMBOL(sub__V975),  "$Nil" ));
      Variable x__V976 = BINDER(term__V952,1,0); if (term__V952_count <= 1) UNBIND(x__V976);
      Variable x__V977 = BINDER(term__V952,1,1); if (term__V952_count <= 1) UNBIND(x__V977);
      Term sub__V978 = LINK(sink__V951->context, SUB(term__V952, 1)); int sub__V978_count = term__V952_count*LINK_COUNT(sub__V978); permitUnusedInt(sub__V978_count);
      CRSX_CHECK_SORT(sink__V951->context, sub__V978, &sort_M_Reified_xVariable); /* sub__V978 = &#0 */
      Term sub__V979 = LINK(sink__V951->context, SUB(term__V952, 2)); int sub__V979_count = term__V952_count*LINK_COUNT(sub__V979); permitUnusedInt(sub__V979_count);
      /* sub__V979 = &#1 */
      NamedPropertyLink namedP__V980 = LINK_NamedPropertyLink(sink__V951->context, NAMED_PROPERTIES(term__V952));
      VariablePropertyLink varP__V981 = LINK_VariablePropertyLink(sink__V951->context, VARIABLE_PROPERTIES(term__V952));
      UNLINK(sink__V951->context, term__V952);
      ADD_PROPERTIES(sink__V951, LINK_NamedPropertyLink(sink__V951->context, namedP__V980), LINK_VariablePropertyLink(sink__V951->context, varP__V981));
      { START(sink__V951, _M_MapIndexText_s3);
        { if (!IS_BOUND(x__V976)) { REBIND(x__V976);
            REBIND(x__V977);
            Variable binds__V982[2] = {x__V976,x__V977}; BINDS(sink__V951, 2, binds__V982);
            COPY(sink__V951, sub__V978); /* REUSED SUBSTITUTION */  }
          else { Variable b__V983 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V951->context,"b__V983");
            Variable b__V984 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V951->context,"b__V984");
            Variable binds__V985[2] = {b__V983,b__V984}; BINDS(sink__V951, 2, binds__V985);
            {
              Term arg__V986;
              { Sink buf__V987 = ALLOCA_BUFFER(sink__V951->context);
                USE(buf__V987, b__V983); arg__V986 = BUFFER_TERM(buf__V987); FREE_BUFFER(buf__V987); }
              Term arg__V988;
              { Sink buf__V989 = ALLOCA_BUFFER(sink__V951->context);
                USE(buf__V989, b__V984); arg__V988 = BUFFER_TERM(buf__V989); FREE_BUFFER(buf__V989); }
              Variable vars__V990[2] = {x__V976,x__V977};
              Term args__V991[2] = {arg__V986,arg__V988};
              struct _SubstitutionFrame substitution__V992 = {NULL, 0, 2, vars__V990, args__V991, NULL};
              SUBSTITUTE(sink__V951, sub__V978, &substitution__V992); }
                }
           }
        COPY(sink__V951, sub__V979);END(sink__V951, _M_MapIndexText_s3); }
      UNLINK_NamedPropertyLink(sink__V951->context, namedP__V980); UNLINK_VariablePropertyLink(sink__V951->context, varP__V981);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION MapIndexText$3. */
int conBindOffs_M_MapIndexText_s3[] = {0 , 2 , 2};
char *nameFun_M_MapIndexText_s3(Term term) { return  "MapIndexText$3" ; }
struct _ConstructionDescriptor descriptor_M_MapIndexText_s3 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_MapIndexText_s3), conBindOffs_M_MapIndexText_s3, &nameFun_M_MapIndexText_s3, &step_M_MapIndexText_s3};

int step_M_MapIndexText_s3(Sink sink__V993, Term term__V994)
{
  int term__V994_count = LINK_COUNT(term__V994); permitUnusedInt(term__V994_count);
  do {
    /* Contraction rule DEFS-MapIndexText-2. */
    ASSERT(sink__V993->context, !strcmp(SYMBOL(term__V994),  "MapIndexText$3" ));
    Variable x__V995 = BINDER(term__V994,0,0); if (term__V994_count <= 1) UNBIND(x__V995);
    Variable x__V996 = BINDER(term__V994,0,1); if (term__V994_count <= 1) UNBIND(x__V996);
    Term sub__V997 = SUB(term__V994, 0); permitUnusedTerm(sub__V997); int sub__V997_count = term__V994_count*LINK_COUNT(sub__V997); permitUnusedInt(sub__V997_count);
    CRSX_CHECK_SORT(sink__V993->context, sub__V997, &sort_M_Reified_xVariable); /* sub__V997 = &#1 */
    Term sub__V998 = SUB(term__V994, 1); permitUnusedTerm(sub__V998); int sub__V998_count = term__V994_count*LINK_COUNT(sub__V998); permitUnusedInt(sub__V998_count);
    /* sub__V998 = &#3 */
    NamedPropertyLink namedP__V999 = LINK_NamedPropertyLink(sink__V993->context, NAMED_PROPERTIES(term__V994));
    VariablePropertyLink varP__V1000 = LINK_VariablePropertyLink(sink__V993->context, VARIABLE_PROPERTIES(term__V994));
    UNLINK(sink__V993->context, term__V994);
    { START(sink__V993, _M__sTextNil); END(sink__V993, _M__sTextNil); }
    UNLINK_NamedPropertyLink(sink__V993->context, namedP__V999); UNLINK_VariablePropertyLink(sink__V993->context, varP__V1000);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION If$1. */
int conBindOffs_M_If_s1[] = {0 , 0 , 0};
char *nameFun_M_If_s1(Term term) { return  "If$1" ; }
struct _ConstructionDescriptor descriptor_M_If_s1 = {NULL, 0, 2, sizeof(STRUCT_Con_M_If_s1), conBindOffs_M_If_s1, &nameFun_M_If_s1, &step_M_If_s1};

int step_M_If_s1(Sink sink__V1001, Term term__V1002)
{
  int term__V1002_count = LINK_COUNT(term__V1002); permitUnusedInt(term__V1002_count);
  do {
    /* Contraction rule DEFS-If-2. */
    ASSERT(sink__V1001->context, !strcmp(SYMBOL(term__V1002),  "If$1" ));
    Term sub__V1003 = SUB(term__V1002, 0); permitUnusedTerm(sub__V1003); int sub__V1003_count = term__V1002_count*LINK_COUNT(sub__V1003); permitUnusedInt(sub__V1003_count);
    /* sub__V1003 = &#2 */
    Term sub__V1004 = LINK(sink__V1001->context, SUB(term__V1002, 1)); int sub__V1004_count = term__V1002_count*LINK_COUNT(sub__V1004); permitUnusedInt(sub__V1004_count);
    /* sub__V1004 = &#3 */
    UNLINK(sink__V1001->context, term__V1002);
    COPY(sink__V1001, sub__V1004);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION If$2. */
int conBindOffs_M_If_s2[] = {0 , 0 , 0};
char *nameFun_M_If_s2(Term term) { return  "If$2" ; }
struct _ConstructionDescriptor descriptor_M_If_s2 = {NULL, 0, 2, sizeof(STRUCT_Con_M_If_s2), conBindOffs_M_If_s2, &nameFun_M_If_s2, &step_M_If_s2};

int step_M_If_s2(Sink sink__V1005, Term term__V1006)
{
  int term__V1006_count = LINK_COUNT(term__V1006); permitUnusedInt(term__V1006_count);
  do {
    /* Contraction rule DEFS-If-1. */
    ASSERT(sink__V1005->context, !strcmp(SYMBOL(term__V1006),  "If$2" ));
    Term sub__V1007 = LINK(sink__V1005->context, SUB(term__V1006, 0)); int sub__V1007_count = term__V1006_count*LINK_COUNT(sub__V1007); permitUnusedInt(sub__V1007_count);
    /* sub__V1007 = &#2 */
    Term sub__V1008 = SUB(term__V1006, 1); permitUnusedTerm(sub__V1008); int sub__V1008_count = term__V1006_count*LINK_COUNT(sub__V1008); permitUnusedInt(sub__V1008_count);
    /* sub__V1008 = &#3 */
    UNLINK(sink__V1005->context, term__V1006);
    COPY(sink__V1005, sub__V1007);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION MissingPrimitive. */
int conBindOffs_M_MissingPrimitive[] = {0 , 0};
char *nameFun_M_MissingPrimitive(Term term) { return  "MissingPrimitive" ; }
struct _ConstructionDescriptor descriptor_M_MissingPrimitive = {&sort_M_SPrimitive, 0, 1, sizeof(STRUCT_Con_M_MissingPrimitive), conBindOffs_M_MissingPrimitive, &nameFun_M_MissingPrimitive, &step_M_MissingPrimitive};

int step_M_MissingPrimitive(Sink sink__V1009, Term term__V1010)
{
  int term__V1010_count = LINK_COUNT(term__V1010); permitUnusedInt(term__V1010_count);
  do {
    /* Contraction rule DEFS-MissingPrimitive-1. */
    ASSERT(sink__V1009->context, !strcmp(SYMBOL(term__V1010),  "MissingPrimitive" ));
    Term sub__V1011 = LINK(sink__V1009->context, SUB(term__V1010, 0)); int sub__V1011_count = term__V1010_count*LINK_COUNT(sub__V1011); permitUnusedInt(sub__V1011_count);
    /* sub__V1011 = &#1 */
    UNLINK(sink__V1009->context, term__V1010);
    char *sub__V1012[3]; size_t sublength__V1013[3]; size_t length__V1014 = 0;
    length__V1014 += (sublength__V1013[0] = strlen(sub__V1012[0] =  "$[" ));
    FORCE(sink__V1009->context, sub__V1011);
    length__V1014 += (sublength__V1013[1] = strlen(sub__V1012[1] = SYMBOL(sub__V1011)));
    UNLINK(sink__V1009->context, sub__V1011);length__V1014 += (sublength__V1013[2] = strlen(sub__V1012[2] =  "] not supported" ));
    { char *str__V1015 = ALLOCA(sink__V1009->context, length__V1014+1), *p__V1016 = str__V1015;
      int i; for (i = 0; i < 3; ++i) { memcpy(p__V1016, sub__V1012[i], sublength__V1013[i]); p__V1016 += sublength__V1013[i]; }
      *p__V1016 = '\0';
      ASSERT(sink__V1009->context, strlen(str__V1015) == length__V1014);
      ERRORF(sink__V1009->context, Default, "%s\n", str__V1015); }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Primitive. */
int conBindOffs_M_Primitive[] = {0 , 0};
char *nameFun_M_Primitive(Term term) { return  "Primitive" ; }
struct _ConstructionDescriptor descriptor_M_Primitive = {&sort_M_SPrimitive, 0, 1, sizeof(STRUCT_Con_M_Primitive), conBindOffs_M_Primitive, &nameFun_M_Primitive, &step_M_Primitive};

int step_M_Primitive(Sink sink__V1017, Term term__V1018)
{
  int term__V1018_count = LINK_COUNT(term__V1018); permitUnusedInt(term__V1018_count);
  do {
    /* Contraction rule DEFS-Primitive-1. */
    ASSERT(sink__V1017->context, !strcmp(SYMBOL(term__V1018),  "Primitive" ));
    Term sub__V1019 = LINK(sink__V1017->context, SUB(term__V1018, 0)); int sub__V1019_count = term__V1018_count*LINK_COUNT(sub__V1019); permitUnusedInt(sub__V1019_count);
    /* sub__V1019 = &#1 */
    UNLINK(sink__V1017->context, term__V1018);
    { int test__V1020;
      FORCE(sink__V1017->context, sub__V1019);
      test__V1020 = (int) !strcmp(SYMBOL(sub__V1019), "C" ); if (test__V1020) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xC); END(sink__V1017, _M_E_xC); }  }
      else { { int test__V1021;
          FORCE(sink__V1017->context, sub__V1019);
          test__V1021 = (int) !strcmp(SYMBOL(sub__V1019), "NumericEqual" );
          if (test__V1021) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xNumericEqual);
              END(sink__V1017, _M_E_xNumericEqual); }
             }
          else { { int test__V1022;
              FORCE(sink__V1017->context, sub__V1019);
              test__V1022 = (int) !strcmp(SYMBOL(sub__V1019), "StringLessThan" );
              if (test__V1022) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xStringLessThan);
                  END(sink__V1017, _M_E_xStringLessThan); }
                 }
              else { { int test__V1023;
                  FORCE(sink__V1017->context, sub__V1019);
                  test__V1023 = (int) !strcmp(SYMBOL(sub__V1019), "LessThan" );
                  if (test__V1023) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xLessThan);
                      END(sink__V1017, _M_E_xLessThan); }
                     }
                  else { { int test__V1024;
                      FORCE(sink__V1017->context, sub__V1019);
                      test__V1024 = (int) !strcmp(SYMBOL(sub__V1019), "GreaterThan" );
                      if (test__V1024) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xGreaterThan);
                          END(sink__V1017, _M_E_xGreaterThan); }
                         }
                      else { { int test__V1025;
                          FORCE(sink__V1017->context, sub__V1019);
                          test__V1025 = (int) !strcmp(SYMBOL(sub__V1019), "LessThanOrEqual" );
                          if (test__V1025) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xLessThanOrEqual);
                              END(sink__V1017, _M_E_xLessThanOrEqual); }
                             }
                          else { { int test__V1026;
                              FORCE(sink__V1017->context, sub__V1019);
                              test__V1026 = (int) !strcmp(SYMBOL(sub__V1019), "GreaterThanOrEqual" );
                              if (test__V1026) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xGreaterThanOrEqual);
                                  END(sink__V1017, _M_E_xGreaterThanOrEqual); }
                                 }
                              else { { int test__V1027;
                                  FORCE(sink__V1017->context, sub__V1019);
                                  test__V1027 = (int) !strcmp(SYMBOL(sub__V1019), "NotEqual" );
                                  if (test__V1027) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xNotEqual);
                                      END(sink__V1017, _M_E_xNotEqual); }
                                     }
                                  else { { int test__V1028;
                                      FORCE(sink__V1017->context, sub__V1019);
                                      test__V1028 = (int) !strcmp(SYMBOL(sub__V1019), ":" );
                                      if (test__V1028) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xConcat);
                                          END(sink__V1017, _M_E_xConcat); }
                                         }
                                      else { { int test__V1029;
                                          FORCE(sink__V1017->context, sub__V1019);
                                          test__V1029 = (int) !strcmp(SYMBOL(sub__V1019), "SameVariable" );
                                          if (test__V1029) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xSameVariable);
                                              END(sink__V1017, _M_E_xSameVariable); }
                                             }
                                          else { { int test__V1030;
                                              FORCE(sink__V1017->context, sub__V1019);
                                              test__V1030 = (int) !strcmp(SYMBOL(sub__V1019), "LesserVariable" );
                                              if (test__V1030) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xLesserVariable);
                                                  END(sink__V1017, _M_E_xLesserVariable); }
                                                 }
                                              else { { int test__V1031;
                                                  FORCE(sink__V1017->context, sub__V1019);
                                                  test__V1031 = (int) !strcmp(SYMBOL(sub__V1019), "Equal" );
                                                  if (test__V1031) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xEqual);
                                                      END(sink__V1017, _M_E_xEqual); }
                                                     }
                                                  else { { int test__V1032;
                                                      FORCE(sink__V1017->context, sub__V1019);
                                                      test__V1032 = (int) !strcmp(SYMBOL(sub__V1019), "Contains" );
                                                      if (test__V1032) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xContains);
                                                          END(sink__V1017, _M_E_xContains); }
                                                         }
                                                      else { { int test__V1033;
                                                          FORCE(sink__V1017->context, sub__V1019);
                                                          test__V1033 = (int) !strcmp(SYMBOL(sub__V1019), "StartsWith" );
                                                          if (test__V1033) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xStartsWith);
                                                              END(sink__V1017, _M_E_xStartsWith); }
                                                             }
                                                          else { { int test__V1034;
                                                              FORCE(sink__V1017->context, sub__V1019);
                                                              test__V1034 = (int) !strcmp(SYMBOL(sub__V1019), "EndsWith" );
                                                              if (test__V1034) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xEndsWith);
                                                                  END(sink__V1017, _M_E_xEndsWith); }
                                                                 }
                                                              else { { int test__V1035;
                                                                  FORCE(sink__V1017->context, sub__V1019);
                                                                  test__V1035 = (int) !strcmp(SYMBOL(sub__V1019), "Split" );
                                                                  if (test__V1035) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xSplit);
                                                                      END(sink__V1017, _M_E_xSplit); }
                                                                     }
                                                                  else { { int test__V1036;
                                                                      FORCE(sink__V1017->context, sub__V1019);
                                                                      test__V1036 = (int) !strcmp(SYMBOL(sub__V1019), "MatchRegex" );
                                                                      if (test__V1036) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xMatchRegex);
                                                                          END(sink__V1017, _M_E_xMatchRegex); }
                                                                         }
                                                                      else { { int test__V1037;
                                                                          FORCE(sink__V1017->context, sub__V1019);
                                                                          test__V1037 = (int) !strcmp(SYMBOL(sub__V1019), "Length" );
                                                                          if (test__V1037) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xLength);
                                                                              END(sink__V1017, _M_E_xLength); }
                                                                             }
                                                                          else { { int test__V1038;
                                                                              FORCE(sink__V1017->context, sub__V1019);
                                                                              test__V1038 = (int) !strcmp(SYMBOL(sub__V1019), "Substring" );
                                                                              if (test__V1038) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xSubstring);
                                                                                  END(sink__V1017, _M_E_xSubstring); }
                                                                                 }
                                                                              else { { int test__V1039;
                                                                                  FORCE(sink__V1017->context, sub__V1019);
                                                                                  test__V1039 = (int) !strcmp(SYMBOL(sub__V1019), "Escape" );
                                                                                  if (test__V1039) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xEscape);
                                                                                      END(sink__V1017, _M_E_xEscape); }
                                                                                     }
                                                                                  else { { int test__V1040;
                                                                                      FORCE(sink__V1017->context, sub__V1019);
                                                                                      test__V1040 = (int) !strcmp(SYMBOL(sub__V1019), "Mangle" );
                                                                                      if (test__V1040) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xMangle);
                                                                                          END(sink__V1017, _M_E_xMangle); }
                                                                                         }
                                                                                      else { { int test__V1041;
                                                                                          FORCE(sink__V1017->context, sub__V1019);
                                                                                          test__V1041 = (int) !strcmp(SYMBOL(sub__V1019), "BeforeFirst" );
                                                                                          if (test__V1041) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xBeforeFirst);
                                                                                              END(sink__V1017, _M_E_xBeforeFirst); }
                                                                                             }
                                                                                          else { { int test__V1042;
                                                                                              FORCE(sink__V1017->context, sub__V1019);
                                                                                              test__V1042 = (int) !strcmp(SYMBOL(sub__V1019), "AfterFirst" );
                                                                                              if (test__V1042) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xAfterFirst);
                                                                                                  END(sink__V1017, _M_E_xAfterFirst); }
                                                                                                 }
                                                                                              else { { int test__V1043;
                                                                                                  FORCE(sink__V1017->context, sub__V1019);
                                                                                                  test__V1043 = (int) !strcmp(SYMBOL(sub__V1019), "FromFirst" );
                                                                                                  if (test__V1043) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xFromFirst);
                                                                                                      END(sink__V1017, _M_E_xFromFirst); }
                                                                                                     }
                                                                                                  else { { int test__V1044;
                                                                                                      FORCE(sink__V1017->context, sub__V1019);
                                                                                                      test__V1044 = (int) !strcmp(SYMBOL(sub__V1019), "ToFirst" );
                                                                                                      if (test__V1044) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xToFirst);
                                                                                                          END(sink__V1017, _M_E_xToFirst); }
                                                                                                         }
                                                                                                      else { { int test__V1045;
                                                                                                          FORCE(sink__V1017->context, sub__V1019);
                                                                                                          test__V1045 = (int) !strcmp(SYMBOL(sub__V1019), "FormatNumber" );
                                                                                                          if (test__V1045) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xFormatNumber);
                                                                                                              END(sink__V1017, _M_E_xFormatNumber); }
                                                                                                             }
                                                                                                          else { { int test__V1046;
                                                                                                              FORCE(sink__V1017->context, sub__V1019);
                                                                                                              test__V1046 = (int) !strcmp(SYMBOL(sub__V1019), "Format" );
                                                                                                              if (test__V1046) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xFormat);
                                                                                                                  END(sink__V1017, _M_E_xFormat); }
                                                                                                                 }
                                                                                                              else { { int test__V1047;
                                                                                                                  FORCE(sink__V1017->context, sub__V1019);
                                                                                                                  test__V1047 = (int) !strcmp(SYMBOL(sub__V1019), "Show" );
                                                                                                                  if (test__V1047) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xShow);
                                                                                                                      END(sink__V1017, _M_E_xShow); }
                                                                                                                     }
                                                                                                                  else { { int test__V1048;
                                                                                                                      FORCE(sink__V1017->context, sub__V1019);
                                                                                                                      test__V1048 = (int) !strcmp(SYMBOL(sub__V1019), "PassLocationProperties" );
                                                                                                                      if (test__V1048) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xPassLocationProperties);
                                                                                                                          END(sink__V1017, _M_E_xPassLocationProperties); }
                                                                                                                         }
                                                                                                                      else { { int test__V1049;
                                                                                                                          FORCE(sink__V1017->context, sub__V1019);
                                                                                                                          test__V1049 = (int) !strcmp(SYMBOL(sub__V1019), "Plus" );
                                                                                                                          if (test__V1049) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xPlus);
                                                                                                                              END(sink__V1017, _M_E_xPlus); }
                                                                                                                             }
                                                                                                                          else { { int test__V1050;
                                                                                                                              FORCE(sink__V1017->context, sub__V1019);
                                                                                                                              test__V1050 = (int) !strcmp(SYMBOL(sub__V1019), "Minus" );
                                                                                                                              if (test__V1050) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xMinus);
                                                                                                                                  END(sink__V1017, _M_E_xMinus); }
                                                                                                                                 }
                                                                                                                              else { { int test__V1051;
                                                                                                                                  FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                  test__V1051 = (int) !strcmp(SYMBOL(sub__V1019), "Times" );
                                                                                                                                  if (test__V1051) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xTimes);
                                                                                                                                      END(sink__V1017, _M_E_xTimes); }
                                                                                                                                     }
                                                                                                                                  else { { int test__V1052;
                                                                                                                                      FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                      test__V1052 = (int) !strcmp(SYMBOL(sub__V1019), "Divide" );
                                                                                                                                      if (test__V1052) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xDiv);
                                                                                                                                          END(sink__V1017, _M_E_xDiv); }
                                                                                                                                         }
                                                                                                                                      else { { int test__V1053;
                                                                                                                                          FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                          test__V1053 = (int) !strcmp(SYMBOL(sub__V1019), "Modulo" );
                                                                                                                                          if (test__V1053) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xMod);
                                                                                                                                              END(sink__V1017, _M_E_xMod); }
                                                                                                                                             }
                                                                                                                                          else { { int test__V1054;
                                                                                                                                              FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                              test__V1054 = (int) !strcmp(SYMBOL(sub__V1019), "Absolute" );
                                                                                                                                              if (test__V1054) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xAbsolute);
                                                                                                                                                  END(sink__V1017, _M_E_xAbsolute); }
                                                                                                                                                 }
                                                                                                                                              else { { int test__V1055;
                                                                                                                                                  FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                  test__V1055 = (int) !strcmp(SYMBOL(sub__V1019), "Decimal" );
                                                                                                                                                  if (test__V1055) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xDecimal);
                                                                                                                                                      END(sink__V1017, _M_E_xDecimal); }
                                                                                                                                                     }
                                                                                                                                                  else { { int test__V1056;
                                                                                                                                                      FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                      test__V1056 = (int) !strcmp(SYMBOL(sub__V1019), "Hex" );
                                                                                                                                                      if (test__V1056) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xHex);
                                                                                                                                                          END(sink__V1017, _M_E_xHex); }
                                                                                                                                                         }
                                                                                                                                                      else { { int test__V1057;
                                                                                                                                                          FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                          test__V1057 = (int) !strcmp(SYMBOL(sub__V1019), "BitAnd" );
                                                                                                                                                          if (test__V1057) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xBitAnd);
                                                                                                                                                              END(sink__V1017, _M_E_xBitAnd); }
                                                                                                                                                             }
                                                                                                                                                          else { { int test__V1058;
                                                                                                                                                              FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                              test__V1058 = (int) !strcmp(SYMBOL(sub__V1019), "BitOr" );
                                                                                                                                                              if (test__V1058) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xBitOr);
                                                                                                                                                                  END(sink__V1017, _M_E_xBitOr); }
                                                                                                                                                                 }
                                                                                                                                                              else { { int test__V1059;
                                                                                                                                                                  FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                                  test__V1059 = (int) !strcmp(SYMBOL(sub__V1019), "BitXor" );
                                                                                                                                                                  if (test__V1059) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xBitXOr);
                                                                                                                                                                      END(sink__V1017, _M_E_xBitXOr); }
                                                                                                                                                                     }
                                                                                                                                                                  else { { int test__V1060;
                                                                                                                                                                      FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                                      test__V1060 = (int) !strcmp(SYMBOL(sub__V1019), "BitNot" );
                                                                                                                                                                      if (test__V1060) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xBitNot);
                                                                                                                                                                          END(sink__V1017, _M_E_xBitNot); }
                                                                                                                                                                         }
                                                                                                                                                                      else { { int test__V1061;
                                                                                                                                                                          FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                                          test__V1061 = (int) !strcmp(SYMBOL(sub__V1019), "BitMinus" );
                                                                                                                                                                          if (test__V1061) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xBitMinus);
                                                                                                                                                                              END(sink__V1017, _M_E_xBitMinus); }
                                                                                                                                                                             }
                                                                                                                                                                          else { { int test__V1062;
                                                                                                                                                                              FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                                              test__V1062 = (int) !strcmp(SYMBOL(sub__V1019), "BitSubSetEq" );
                                                                                                                                                                              if (test__V1062) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xBitSubSetEq);
                                                                                                                                                                                  END(sink__V1017, _M_E_xBitSubSetEq); }
                                                                                                                                                                                 }
                                                                                                                                                                              else { { int test__V1063;
                                                                                                                                                                                  FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                                                  test__V1063 = (int) !strcmp(SYMBOL(sub__V1019), "Get" );
                                                                                                                                                                                  if (test__V1063) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xGet);
                                                                                                                                                                                      END(sink__V1017, _M_E_xGet); }
                                                                                                                                                                                     }
                                                                                                                                                                                  else { { int test__V1064;
                                                                                                                                                                                      FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                                                      test__V1064 = (int) !strcmp(SYMBOL(sub__V1019), "GetRef" );
                                                                                                                                                                                      if (test__V1064) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xGetRef);
                                                                                                                                                                                          END(sink__V1017, _M_E_xGetRef); }
                                                                                                                                                                                         }
                                                                                                                                                                                      else { { int test__V1065;
                                                                                                                                                                                          FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                                                          test__V1065 = (int) !strcmp(SYMBOL(sub__V1019), "IfDef" );
                                                                                                                                                                                          if (test__V1065) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xIfDef);
                                                                                                                                                                                              END(sink__V1017, _M_E_xIfDef); }
                                                                                                                                                                                             }
                                                                                                                                                                                          else { { int test__V1066;
                                                                                                                                                                                              FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                                                              test__V1066 = (int) !strcmp(SYMBOL(sub__V1019), "Error" );
                                                                                                                                                                                              if (test__V1066) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xError);
                                                                                                                                                                                                  END(sink__V1017, _M_E_xError); }
                                                                                                                                                                                                 }
                                                                                                                                                                                              else { { int test__V1067;
                                                                                                                                                                                                  FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                                                                  test__V1067 = (int) !strcmp(SYMBOL(sub__V1019), "ForgivableError" );
                                                                                                                                                                                                  if (test__V1067) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xForgivableError);
                                                                                                                                                                                                      END(sink__V1017, _M_E_xForgivableError); }
                                                                                                                                                                                                     }
                                                                                                                                                                                                  else { { int test__V1068;
                                                                                                                                                                                                      FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                                                                      test__V1068 = (int) !strcmp(SYMBOL(sub__V1019), "Trace" );
                                                                                                                                                                                                      if (test__V1068) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xTrace);
                                                                                                                                                                                                          END(sink__V1017, _M_E_xTrace); }
                                                                                                                                                                                                         }
                                                                                                                                                                                                      else { { int test__V1069;
                                                                                                                                                                                                          FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                                                                          test__V1069 = (int) !strcmp(SYMBOL(sub__V1019), "LoadTerm" );
                                                                                                                                                                                                          if (test__V1069) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xLoadTerm);
                                                                                                                                                                                                              END(sink__V1017, _M_E_xLoadTerm); }
                                                                                                                                                                                                             }
                                                                                                                                                                                                          else { { int test__V1070;
                                                                                                                                                                                                              FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                                                                              test__V1070 = (int) !strcmp(SYMBOL(sub__V1019), "SaveTerm" );
                                                                                                                                                                                                              if (test__V1070) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xSaveTerm);
                                                                                                                                                                                                                  END(sink__V1017, _M_E_xSaveTerm); }
                                                                                                                                                                                                                 }
                                                                                                                                                                                                              else { { int test__V1071;
                                                                                                                                                                                                                  FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                                                                                  test__V1071 = (int) !strcmp(SYMBOL(sub__V1019), "If" );
                                                                                                                                                                                                                  if (test__V1071) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xIf);
                                                                                                                                                                                                                      END(sink__V1017, _M_E_xIf); }
                                                                                                                                                                                                                     }
                                                                                                                                                                                                                  else { { int test__V1072;
                                                                                                                                                                                                                      FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                                                                                      test__V1072 = (int) !strcmp(SYMBOL(sub__V1019), "IfZero" );
                                                                                                                                                                                                                      if (test__V1072) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xIfZero);
                                                                                                                                                                                                                          END(sink__V1017, _M_E_xIfZero); }
                                                                                                                                                                                                                         }
                                                                                                                                                                                                                      else { { int test__V1073;
                                                                                                                                                                                                                          FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                                                                                          test__V1073 = (int) !strcmp(SYMBOL(sub__V1019), "IfEmpty" );
                                                                                                                                                                                                                          if (test__V1073) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xIfEmpty);
                                                                                                                                                                                                                              END(sink__V1017, _M_E_xIfEmpty); }
                                                                                                                                                                                                                             }
                                                                                                                                                                                                                          else { { int test__V1074;
                                                                                                                                                                                                                              FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                                                                                              test__V1074 = (int) !strcmp(SYMBOL(sub__V1019), "FreeVariables" );
                                                                                                                                                                                                                              if (test__V1074) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xFreeVariables);
                                                                                                                                                                                                                                  END(sink__V1017, _M_E_xFreeVariables); }
                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                              else { { int test__V1075;
                                                                                                                                                                                                                                  FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                                                                                                  test__V1075 = (int) !strcmp(SYMBOL(sub__V1019), "IntersectVariables" );
                                                                                                                                                                                                                                  if (test__V1075) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xIntersectVariables);
                                                                                                                                                                                                                                      END(sink__V1017, _M_E_xIntersectVariables); }
                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                  else { { int test__V1076;
                                                                                                                                                                                                                                      FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                                                                                                      test__V1076 = (int) !strcmp(SYMBOL(sub__V1019), "UnionVariables" );
                                                                                                                                                                                                                                      if (test__V1076) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xUnionVariables);
                                                                                                                                                                                                                                          END(sink__V1017, _M_E_xUnionVariables); }
                                                                                                                                                                                                                                         }
                                                                                                                                                                                                                                      else { { int test__V1077;
                                                                                                                                                                                                                                          FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                                                                                                          test__V1077 = (int) !strcmp(SYMBOL(sub__V1019), "ExceptVariables" );
                                                                                                                                                                                                                                          if (test__V1077) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xExceptVariables);
                                                                                                                                                                                                                                              END(sink__V1017, _M_E_xExceptVariables); }
                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                          else { { int test__V1078;
                                                                                                                                                                                                                                              FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                                                                                                              test__V1078 = (int) !strcmp(SYMBOL(sub__V1019), "VariableNameIs" );
                                                                                                                                                                                                                                              if (test__V1078) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xVariableNameIs);
                                                                                                                                                                                                                                                  END(sink__V1017, _M_E_xVariableNameIs); }
                                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                                              else { { int test__V1079;
                                                                                                                                                                                                                                                  FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                                                                                                                  test__V1079 = (int) !strcmp(SYMBOL(sub__V1019), "Match" );
                                                                                                                                                                                                                                                  if (test__V1079) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xMatch);
                                                                                                                                                                                                                                                      END(sink__V1017, _M_E_xMatch); }
                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                  else { { int test__V1080;
                                                                                                                                                                                                                                                      FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                                                                                                                      test__V1080 = (int) !strcmp(SYMBOL(sub__V1019), "TryCall" );
                                                                                                                                                                                                                                                      if (test__V1080) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xTryCall);
                                                                                                                                                                                                                                                          END(sink__V1017, _M_E_xTryCall); }
                                                                                                                                                                                                                                                         }
                                                                                                                                                                                                                                                      else { { int test__V1081;
                                                                                                                                                                                                                                                          FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                                                                                                                          test__V1081 = (int) !strcmp(SYMBOL(sub__V1019), "Call" );
                                                                                                                                                                                                                                                          if (test__V1081) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xCall);
                                                                                                                                                                                                                                                              END(sink__V1017, _M_E_xCall); }
                                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                                          else { { int test__V1082;
                                                                                                                                                                                                                                                              FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                                                                                                                              test__V1082 = (int) !strcmp(SYMBOL(sub__V1019), "Cast" );
                                                                                                                                                                                                                                                              if (test__V1082) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xCast);
                                                                                                                                                                                                                                                                  END(sink__V1017, _M_E_xCast); }
                                                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                                                              else { { int test__V1083;
                                                                                                                                                                                                                                                                  FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                                                                                                                                  test__V1083 = (int) !strcmp(SYMBOL(sub__V1019), "Null" );
                                                                                                                                                                                                                                                                  if (test__V1083) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xNull);
                                                                                                                                                                                                                                                                      END(sink__V1017, _M_E_xNull); }
                                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                                  else { { int test__V1084;
                                                                                                                                                                                                                                                                      FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                                                                                                                                      test__V1084 = (int) !strcmp(SYMBOL(sub__V1019), "Nil" );
                                                                                                                                                                                                                                                                      if (test__V1084) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xNil);
                                                                                                                                                                                                                                                                          END(sink__V1017, _M_E_xNil); }
                                                                                                                                                                                                                                                                         }
                                                                                                                                                                                                                                                                      else { { int test__V1085;
                                                                                                                                                                                                                                                                          FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                                                                                                                                          test__V1085 = (int) !strcmp(SYMBOL(sub__V1019), "UpCase" );
                                                                                                                                                                                                                                                                          if (test__V1085) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xUpCase);
                                                                                                                                                                                                                                                                              END(sink__V1017, _M_E_xUpCase); }
                                                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                                                          else { { int test__V1086;
                                                                                                                                                                                                                                                                              FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                                                                                                                                              test__V1086 = (int) !strcmp(SYMBOL(sub__V1019), "DownCase" );
                                                                                                                                                                                                                                                                              if (test__V1086) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xDownCase);
                                                                                                                                                                                                                                                                                  END(sink__V1017, _M_E_xDownCase); }
                                                                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                                                                              else { { int test__V1087;
                                                                                                                                                                                                                                                                                  FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                                                                                                                                                  test__V1087 = (int) !strcmp(SYMBOL(sub__V1019), "Replace" );
                                                                                                                                                                                                                                                                                  if (test__V1087) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xReplace);
                                                                                                                                                                                                                                                                                      END(sink__V1017, _M_E_xReplace); }
                                                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                                                  else { { int test__V1088;
                                                                                                                                                                                                                                                                                      FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                                                                                                                                                      test__V1088 = (int) !strcmp(SYMBOL(sub__V1019), "Trim" );
                                                                                                                                                                                                                                                                                      if (test__V1088) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xTrim);
                                                                                                                                                                                                                                                                                          END(sink__V1017, _M_E_xTrim); }
                                                                                                                                                                                                                                                                                         }
                                                                                                                                                                                                                                                                                      else { { int test__V1089;
                                                                                                                                                                                                                                                                                          FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                                                                                                                                                          test__V1089 = (int) !strcmp(SYMBOL(sub__V1019), "Split" );
                                                                                                                                                                                                                                                                                          if (test__V1089) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xSplit);
                                                                                                                                                                                                                                                                                              END(sink__V1017, _M_E_xSplit); }
                                                                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                                                                          else { { int test__V1090;
                                                                                                                                                                                                                                                                                              FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                                                                                                                                                              test__V1090 = (int) !strcmp(SYMBOL(sub__V1019), "Rescape" );
                                                                                                                                                                                                                                                                                              if (test__V1090) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xRescape);
                                                                                                                                                                                                                                                                                                  END(sink__V1017, _M_E_xRescape); }
                                                                                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                                                                                              else { { int test__V1091;
                                                                                                                                                                                                                                                                                                  FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                                                                                                                                                                  test__V1091 = (int) !strcmp(SYMBOL(sub__V1019), "Keys" );
                                                                                                                                                                                                                                                                                                  if (test__V1091) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xKeys);
                                                                                                                                                                                                                                                                                                      END(sink__V1017, _M_E_xKeys); }
                                                                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                                                                  else { { int test__V1092;
                                                                                                                                                                                                                                                                                                      FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                                                                                                                                                                      test__V1092 = (int) !strcmp(SYMBOL(sub__V1019), "ParseURL" );
                                                                                                                                                                                                                                                                                                      if (test__V1092) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xParseURL);
                                                                                                                                                                                                                                                                                                          END(sink__V1017, _M_E_xParseURL); }
                                                                                                                                                                                                                                                                                                         }
                                                                                                                                                                                                                                                                                                      else { { int test__V1093;
                                                                                                                                                                                                                                                                                                          FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                                                                                                                                                                          test__V1093 = (int) !strcmp(SYMBOL(sub__V1019), "Echo" );
                                                                                                                                                                                                                                                                                                          if (test__V1093) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xEcho);
                                                                                                                                                                                                                                                                                                              END(sink__V1017, _M_E_xEcho); }
                                                                                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                                                                                          else { { int test__V1094;
                                                                                                                                                                                                                                                                                                              FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                                                                                                                                                                              test__V1094 = (int) !strcmp(SYMBOL(sub__V1019), "DeepEqual" );
                                                                                                                                                                                                                                                                                                              if (test__V1094) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xDeepEqual);
                                                                                                                                                                                                                                                                                                                  END(sink__V1017, _M_E_xDeepEqual); }
                                                                                                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                                                                                                              else { { int test__V1095;
                                                                                                                                                                                                                                                                                                                  FORCE(sink__V1017->context, sub__V1019);
                                                                                                                                                                                                                                                                                                                  test__V1095 = (int) !strcmp(SYMBOL(sub__V1019), "HashCode" );
                                                                                                                                                                                                                                                                                                                  if (test__V1095) {  UNLINK(sink__V1017->context, sub__V1019); { START(sink__V1017, _M_E_xHashCode);
                                                                                                                                                                                                                                                                                                                      END(sink__V1017, _M_E_xHashCode); }
                                                                                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                                                                                  else { { START(sink__V1017, _M_MissingPrimitive);
                                                                                                                                                                                                                                                                                                                      COPY(sink__V1017, sub__V1019);END(sink__V1017, _M_MissingPrimitive); }
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

int step_M_STRING(Sink sink__V1096, Term term__V1097)
{
  int term__V1097_count = LINK_COUNT(term__V1097); permitUnusedInt(term__V1097_count);
  do {
    /* Contraction rule DEFS-STRING-1. */
    ASSERT(sink__V1096->context, !strcmp(SYMBOL(term__V1097),  "STRING" ));
    Term sub__V1098 = LINK(sink__V1096->context, SUB(term__V1097, 0)); int sub__V1098_count = term__V1097_count*LINK_COUNT(sub__V1098); permitUnusedInt(sub__V1098_count);
    UNLINK_SUB(sink__V1096->context, term__V1097,  0); NORMALIZE(sink__V1096->context, sub__V1098); SUB(term__V1097,  0) = LINK(sink__V1096->context, sub__V1098);
    /* sub__V1098 = &#1 */
    NamedPropertyLink namedP__V1099 = LINK_NamedPropertyLink(sink__V1096->context, NAMED_PROPERTIES(term__V1097));
    VariablePropertyLink varP__V1100 = LINK_VariablePropertyLink(sink__V1096->context, VARIABLE_PROPERTIES(term__V1097));
    UNLINK(sink__V1096->context, term__V1097);
    { START(sink__V1096, _M__sTextCons);
      { START(sink__V1096, _M__sTextChars);
        LITERAL(sink__V1096,  " " ); END(sink__V1096, _M__sTextChars); }
      { START(sink__V1096, _M__sTextCons);
        { START(sink__V1096, _M__sTextString);
          { START(sink__V1096, _M__sTextCons);
            { START(sink__V1096, _M__sTextChars);
              { char *str__V1101;
                FORCE(sink__V1096->context, sub__V1098);
                {str__V1101 = makeEscaped(sink__V1096->context, SYMBOL(sub__V1098));
                  UNLINK(sink__V1096->context, sub__V1098);}
                LITERALU(sink__V1096, str__V1101); }
              END(sink__V1096, _M__sTextChars); }
            { START(sink__V1096, _M__sTextNil);
              END(sink__V1096, _M__sTextNil); }
            END(sink__V1096, _M__sTextCons); }
          END(sink__V1096, _M__sTextString); }
        { START(sink__V1096, _M__sTextCons);
          { START(sink__V1096, _M__sTextChars);
            LITERAL(sink__V1096,  " " ); END(sink__V1096, _M__sTextChars); }
          { START(sink__V1096, _M__sTextNil);
            END(sink__V1096, _M__sTextNil); }
          END(sink__V1096, _M__sTextCons); }
        END(sink__V1096, _M__sTextCons); }
      END(sink__V1096, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V1096->context, namedP__V1099); UNLINK_VariablePropertyLink(sink__V1096->context, varP__V1100);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Sort-name$1. */
int conBindOffs_M_Sort__name_s1[] = {0 , 0 , 0};
char *nameFun_M_Sort__name_s1(Term term) { return  "Sort-name$1" ; }
struct _ConstructionDescriptor descriptor_M_Sort__name_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_Sort__name_s1), conBindOffs_M_Sort__name_s1, &nameFun_M_Sort__name_s1, &step_M_Sort__name_s1};

int step_M_Sort__name_s1(Sink sink__V1102, Term term__V1103)
{
  int term__V1103_count = LINK_COUNT(term__V1103); permitUnusedInt(term__V1103_count);
  do {
    /* Contraction rule DEFS-Sort-name-1. */
    ASSERT(sink__V1102->context, !strcmp(SYMBOL(term__V1103),  "Sort-name$1" ));
    Term sub__V1104 = LINK(sink__V1102->context, SUB(term__V1103, 0)); int sub__V1104_count = term__V1103_count*LINK_COUNT(sub__V1104); permitUnusedInt(sub__V1104_count);
    /* sub__V1104 = &#11 */
    Term sub__V1105 = SUB(term__V1103, 1); permitUnusedTerm(sub__V1105); int sub__V1105_count = term__V1103_count*LINK_COUNT(sub__V1105); permitUnusedInt(sub__V1105_count);
    /* sub__V1105 = &#12 */
    NamedPropertyLink namedP__V1106 = LINK_NamedPropertyLink(sink__V1102->context, NAMED_PROPERTIES(term__V1103));
    VariablePropertyLink varP__V1107 = LINK_VariablePropertyLink(sink__V1102->context, VARIABLE_PROPERTIES(term__V1103));
    UNLINK(sink__V1102->context, term__V1103);
    { START(sink__V1102, _M_TOKEN);
      COPY(sink__V1102, sub__V1104);END(sink__V1102, _M_TOKEN); }
    UNLINK_NamedPropertyLink(sink__V1102->context, namedP__V1106); UNLINK_VariablePropertyLink(sink__V1102->context, varP__V1107);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION UnVariable$1. */
int conBindOffs_M_UnVariable_s1[] = {0 , 0};
char *nameFun_M_UnVariable_s1(Term term) { return  "UnVariable$1" ; }
struct _ConstructionDescriptor descriptor_M_UnVariable_s1 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_UnVariable_s1), conBindOffs_M_UnVariable_s1, &nameFun_M_UnVariable_s1, &step_M_UnVariable_s1};

int step_M_UnVariable_s1(Sink sink__V1108, Term term__V1109)
{
  int term__V1109_count = LINK_COUNT(term__V1109); permitUnusedInt(term__V1109_count);
  do {
    /* Contraction rule DEFS-UnVariable-1. */
    ASSERT(sink__V1108->context, !strcmp(SYMBOL(term__V1109),  "UnVariable$1" ));
    Term sub__V1110 = LINK(sink__V1108->context, SUB(term__V1109, 0)); int sub__V1110_count = term__V1109_count*LINK_COUNT(sub__V1110); permitUnusedInt(sub__V1110_count);
    CRSX_CHECK_SORT(sink__V1108->context, sub__V1110, &sort_M_Reified_xVariable); /* sub__V1110 = &#11 */
    NamedPropertyLink namedP__V1111 = LINK_NamedPropertyLink(sink__V1108->context, NAMED_PROPERTIES(term__V1109));
    VariablePropertyLink varP__V1112 = LINK_VariablePropertyLink(sink__V1108->context, VARIABLE_PROPERTIES(term__V1109));
    UNLINK(sink__V1108->context, term__V1109);
    COPY(sink__V1108, sub__V1110);UNLINK_NamedPropertyLink(sink__V1108->context, namedP__V1111); UNLINK_VariablePropertyLink(sink__V1108->context, varP__V1112);
    return 1;
  } while (0);
  return 0;
}

#ifdef __cplusplus
}
#endif
/* END OF C RULES FOR CRSX CRSXC MODULE D. */
