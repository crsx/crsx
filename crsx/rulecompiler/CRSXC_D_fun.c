/* C RULES FOR CRSX CRSXC MODULE D. */
#include "CRSXC.h" 
#ifdef __cplusplus
extern "C" {
#endif

/* FUNCTION DSTRING. */
int conBindOffs_M_DSTRING[] = {0 , 0 , 0};
char *nameFun_M_DSTRING(Term term) { return  "DSTRING" ; }
struct _ConstructionDescriptor descriptor_M_DSTRING = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_DSTRING), conBindOffs_M_DSTRING, &nameFun_M_DSTRING, &step_M_DSTRING};

int step_M_DSTRING(Sink sink__V1, Term term__V2)
{
  int term__V2_count = LINK_COUNT(term__V2); permitUnusedInt(term__V2_count);
  Term sub__V3 = FORCE(sink__V1->context, SUB(term__V2, 0));
  EnumOf_M_OK_xSORT choice__V4 = (IS_VARIABLE_USE(sub__V3) ? VarOf_M_OK_xSORT : (EnumOf_M_OK_xSORT) TAG(sub__V3));
  switch (choice__V4)
  {
    case Data_M_OK: { /* Function DEFS-DSTRING-1$DSTRING$OK case OK */
      ASSERT(sink__V1->context, !strcmp(SYMBOL(term__V2),  "DSTRING" ));
      Term sub__V5 = SUB(term__V2, 0); permitUnusedTerm(sub__V5); int sub__V5_count = term__V2_count*LINK_COUNT(sub__V5); permitUnusedInt(sub__V5_count);
      CRSX_CHECK_SORT(sink__V1->context, sub__V5, &sort_M_OK_xSORT); ASSERT(sink__V1->context, !strcmp(SYMBOL(sub__V5),  "OK" ));
      Term sub__V6 = LINK(sink__V1->context, SUB(term__V2, 1)); int sub__V6_count = term__V2_count*LINK_COUNT(sub__V6); permitUnusedInt(sub__V6_count);
      /* sub__V6 = &#0 */
      
      NamedPropertyLink namedP__V7 = LINK_NamedPropertyLink(sink__V1->context, NAMED_PROPERTIES(term__V2));
      VariablePropertyLink varP__V8 = LINK_VariablePropertyLink(sink__V1->context, VARIABLE_PROPERTIES(term__V2));
      Hashset namedFV__V9 = LINK_VARIABLESET(sink__V1->context, namedPropertyFreeVars(namedP__V7));
      Hashset varFV__V10 = LINK_VARIABLESET(sink__V1->context, variablePropertyFreeVars(varP__V8));
      UNLINK(sink__V1->context, term__V2);
      ADD_PROPERTIES(sink__V1, LINK_VARIABLESET(sink__V1->context, namedFV__V9), LINK_VARIABLESET(sink__V1->context, varFV__V10), LINK_NamedPropertyLink(sink__V1->context, namedP__V7), LINK_VariablePropertyLink(sink__V1->context, varP__V8));
      { START(sink__V1, _M_DSTRING_s1);
        COPY(sink__V1, sub__V6);END(sink__V1, _M_DSTRING_s1); }
      UNLINK_VARIABLESET(sink__V1->context, namedFV__V9); UNLINK_VARIABLESET(sink__V1->context, varFV__V10);
      UNLINK_NamedPropertyLink(sink__V1->context, namedP__V7); UNLINK_VariablePropertyLink(sink__V1->context, varP__V8);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION MetaVar2. */
int conBindOffs_M_MetaVar2[] = {0 , 0};
char *nameFun_M_MetaVar2(Term term) { return  "MetaVar2" ; }
struct _ConstructionDescriptor descriptor_M_MetaVar2 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_MetaVar2), conBindOffs_M_MetaVar2, &nameFun_M_MetaVar2, &step_M_MetaVar2};

int step_M_MetaVar2(Sink sink__V11, Term term__V12)
{
  int term__V12_count = LINK_COUNT(term__V12); permitUnusedInt(term__V12_count);
  Term sub__V13 = FORCE(sink__V11->context, SUB(term__V12, 0));
  EnumOf_M_STRING_xENTRY choice__V14 = (IS_VARIABLE_USE(sub__V13) ? VarOf_M_STRING_xENTRY : (EnumOf_M_STRING_xENTRY) TAG(sub__V13));
  switch (choice__V14)
  {
    case Data_M_VARIABLE: { /* Function DEFS-MetaVar2-1$MetaVar2$VARIABLE case VARIABLE */
      ASSERT(sink__V11->context, !strcmp(SYMBOL(term__V12),  "MetaVar2" ));
      Term sub__V15 = SUB(term__V12, 0); permitUnusedTerm(sub__V15); int sub__V15_count = term__V12_count*LINK_COUNT(sub__V15); permitUnusedInt(sub__V15_count);
      CRSX_CHECK_SORT(sink__V11->context, sub__V15, &sort_M_STRING_xENTRY); ASSERT(sink__V11->context, !strcmp(SYMBOL(sub__V15),  "VARIABLE" ));
      Term sub__V16 = LINK(sink__V11->context, SUB(sub__V15, 0)); int sub__V16_count = sub__V15_count*LINK_COUNT(sub__V16); permitUnusedInt(sub__V16_count);
      CRSX_CHECK_SORT(sink__V11->context, sub__V16, &sort_M_Reified_xVariable); /* sub__V16 = &#0-0 */
      
      NamedPropertyLink namedP__V17 = LINK_NamedPropertyLink(sink__V11->context, NAMED_PROPERTIES(term__V12));
      VariablePropertyLink varP__V18 = LINK_VariablePropertyLink(sink__V11->context, VARIABLE_PROPERTIES(term__V12));
      Hashset namedFV__V19 = LINK_VARIABLESET(sink__V11->context, namedPropertyFreeVars(namedP__V17));
      Hashset varFV__V20 = LINK_VARIABLESET(sink__V11->context, variablePropertyFreeVars(varP__V18));
      UNLINK(sink__V11->context, term__V12);
      ADD_PROPERTIES(sink__V11, LINK_VARIABLESET(sink__V11->context, namedFV__V19), LINK_VARIABLESET(sink__V11->context, varFV__V20), LINK_NamedPropertyLink(sink__V11->context, namedP__V17), LINK_VariablePropertyLink(sink__V11->context, varP__V18));
      { START(sink__V11, _M_MetaVar2_s2);
        COPY(sink__V11, sub__V16);END(sink__V11, _M_MetaVar2_s2); }
      UNLINK_VARIABLESET(sink__V11->context, namedFV__V19); UNLINK_VARIABLESET(sink__V11->context, varFV__V20);
      UNLINK_NamedPropertyLink(sink__V11->context, namedP__V17); UNLINK_VariablePropertyLink(sink__V11->context, varP__V18);
      
      return 1;
    break; } case Data_M_STRING_xVALUE: { /* Function DEFS-MetaVar2-2$MetaVar2$STRING_VALUE case STRING_VALUE */
      ASSERT(sink__V11->context, !strcmp(SYMBOL(term__V12),  "MetaVar2" ));
      Term sub__V21 = SUB(term__V12, 0); permitUnusedTerm(sub__V21); int sub__V21_count = term__V12_count*LINK_COUNT(sub__V21); permitUnusedInt(sub__V21_count);
      CRSX_CHECK_SORT(sink__V11->context, sub__V21, &sort_M_STRING_xENTRY); ASSERT(sink__V11->context, !strcmp(SYMBOL(sub__V21),  "STRING_VALUE" ));
      Term sub__V22 = LINK(sink__V11->context, SUB(sub__V21, 0)); int sub__V22_count = sub__V21_count*LINK_COUNT(sub__V22); permitUnusedInt(sub__V22_count);
      /* sub__V22 = &#0-0 */
      
      NamedPropertyLink namedP__V23 = LINK_NamedPropertyLink(sink__V11->context, NAMED_PROPERTIES(term__V12));
      VariablePropertyLink varP__V24 = LINK_VariablePropertyLink(sink__V11->context, VARIABLE_PROPERTIES(term__V12));
      Hashset namedFV__V25 = LINK_VARIABLESET(sink__V11->context, namedPropertyFreeVars(namedP__V23));
      Hashset varFV__V26 = LINK_VARIABLESET(sink__V11->context, variablePropertyFreeVars(varP__V24));
      UNLINK(sink__V11->context, term__V12);
      ADD_PROPERTIES(sink__V11, LINK_VARIABLESET(sink__V11->context, namedFV__V25), LINK_VARIABLESET(sink__V11->context, varFV__V26), LINK_NamedPropertyLink(sink__V11->context, namedP__V23), LINK_VariablePropertyLink(sink__V11->context, varP__V24));
      { START(sink__V11, _M_MetaVar2_s1);
        COPY(sink__V11, sub__V22);END(sink__V11, _M_MetaVar2_s1); }
      UNLINK_VARIABLESET(sink__V11->context, namedFV__V25); UNLINK_VARIABLESET(sink__V11->context, varFV__V26);
      UNLINK_NamedPropertyLink(sink__V11->context, namedP__V23); UNLINK_VariablePropertyLink(sink__V11->context, varP__V24);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION TOKEN. */
int conBindOffs_M_TOKEN[] = {0 , 0};
char *nameFun_M_TOKEN(Term term) { return  "TOKEN" ; }
struct _ConstructionDescriptor descriptor_M_TOKEN = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_TOKEN), conBindOffs_M_TOKEN, &nameFun_M_TOKEN, &step_M_TOKEN};

int step_M_TOKEN(Sink sink__V27, Term term__V28)
{
  int term__V28_count = LINK_COUNT(term__V28); permitUnusedInt(term__V28_count);
  do {
    /* Contraction rule DEFS-TOKEN-1. */
    ASSERT(sink__V27->context, !strcmp(SYMBOL(term__V28),  "TOKEN" ));
    Term sub__V29 = LINK(sink__V27->context, SUB(term__V28, 0)); int sub__V29_count = term__V28_count*LINK_COUNT(sub__V29); permitUnusedInt(sub__V29_count);
    UNLINK_SUB(sink__V27->context, term__V28,  0); NORMALIZE(sink__V27->context, sub__V29); SUB(term__V28,  0) = LINK(sink__V27->context, sub__V29);
    /* sub__V29 = &#1 */
    
    NamedPropertyLink namedP__V30 = LINK_NamedPropertyLink(sink__V27->context, NAMED_PROPERTIES(term__V28));
    VariablePropertyLink varP__V31 = LINK_VariablePropertyLink(sink__V27->context, VARIABLE_PROPERTIES(term__V28));
    Hashset namedFV__V32 = LINK_VARIABLESET(sink__V27->context, namedPropertyFreeVars(namedP__V30));
    Hashset varFV__V33 = LINK_VARIABLESET(sink__V27->context, variablePropertyFreeVars(varP__V31));
    UNLINK(sink__V27->context, term__V28);
    { START(sink__V27, _M__sTextCons);
      { START(sink__V27, _M__sTextChars);
        COPY(sink__V27, sub__V29);END(sink__V27, _M__sTextChars); }
      { START(sink__V27, _M__sTextNil); END(sink__V27, _M__sTextNil); }
      END(sink__V27, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V27->context, namedFV__V32); UNLINK_VARIABLESET(sink__V27->context, varFV__V33);
    UNLINK_NamedPropertyLink(sink__V27->context, namedP__V30); UNLINK_VariablePropertyLink(sink__V27->context, varP__V31);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Length$1. */
int conBindOffs_M_Length_s1[] = {0 , 0 , 0 , 0};
char *nameFun_M_Length_s1(Term term) { return  "Length$1" ; }
struct _ConstructionDescriptor descriptor_M_Length_s1 = {NULL, 0, 3, sizeof(STRUCT_Con_M_Length_s1), conBindOffs_M_Length_s1, &nameFun_M_Length_s1, &step_M_Length_s1};

int step_M_Length_s1(Sink sink__V34, Term term__V35)
{
  int term__V35_count = LINK_COUNT(term__V35); permitUnusedInt(term__V35_count);
  do {
    /* Contraction rule DEFS-Length-2. */
    ASSERT(sink__V34->context, !strcmp(SYMBOL(term__V35),  "Length$1" ));
    Term sub__V36 = SUB(term__V35, 0); permitUnusedTerm(sub__V36); int sub__V36_count = term__V35_count*LINK_COUNT(sub__V36); permitUnusedInt(sub__V36_count);
    /* sub__V36 = &#11 */
    Term sub__V37 = LINK(sink__V34->context, SUB(term__V35, 1)); int sub__V37_count = term__V35_count*LINK_COUNT(sub__V37); permitUnusedInt(sub__V37_count);
    /* sub__V37 = &#12 */
    Term sub__V38 = LINK(sink__V34->context, SUB(term__V35, 2)); int sub__V38_count = term__V35_count*LINK_COUNT(sub__V38); permitUnusedInt(sub__V38_count);
    /* sub__V38 = &#2 */
    UNLINK(sink__V34->context, term__V35);
    { START(sink__V34, _M_Length);
      COPY(sink__V34, sub__V37);{ double num__V39;
        num__V39 = (double) 1; { double tmp__V40;
          tmp__V40 = DOUBLE(sub__V38); num__V39 += tmp__V40; }
        LITERALNF(sink__V34, (size_t) 31, "%G", num__V39); }
      END(sink__V34, _M_Length); }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Length$2. */
int conBindOffs_M_Length_s2[] = {0 , 0};
char *nameFun_M_Length_s2(Term term) { return  "Length$2" ; }
struct _ConstructionDescriptor descriptor_M_Length_s2 = {NULL, 0, 1, sizeof(STRUCT_Con_M_Length_s2), conBindOffs_M_Length_s2, &nameFun_M_Length_s2, &step_M_Length_s2};

int step_M_Length_s2(Sink sink__V41, Term term__V42)
{
  int term__V42_count = LINK_COUNT(term__V42); permitUnusedInt(term__V42_count);
  do {
    /* Contraction rule DEFS-Length-1. */
    ASSERT(sink__V41->context, !strcmp(SYMBOL(term__V42),  "Length$2" ));
    Term sub__V43 = LINK(sink__V41->context, SUB(term__V42, 0)); int sub__V43_count = term__V42_count*LINK_COUNT(sub__V43); permitUnusedInt(sub__V43_count);
    /* sub__V43 = &#2 */
    UNLINK(sink__V41->context, term__V42); COPY(sink__V41, sub__V43); return 1;
  } while (0);
  return 0;
}

/* FUNCTION DCOMMENT_TOKEN. */
int conBindOffs_M_DCOMMENT_xTOKEN[] = {0 , 0 , 0};
char *nameFun_M_DCOMMENT_xTOKEN(Term term) { return  "DCOMMENT_TOKEN" ; }
struct _ConstructionDescriptor descriptor_M_DCOMMENT_xTOKEN = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_DCOMMENT_xTOKEN), conBindOffs_M_DCOMMENT_xTOKEN, &nameFun_M_DCOMMENT_xTOKEN, &step_M_DCOMMENT_xTOKEN};

int step_M_DCOMMENT_xTOKEN(Sink sink__V44, Term term__V45)
{
  int term__V45_count = LINK_COUNT(term__V45); permitUnusedInt(term__V45_count);
  Term sub__V46 = FORCE(sink__V44->context, SUB(term__V45, 0));
  EnumOf_M_OK_xSORT choice__V47 = (IS_VARIABLE_USE(sub__V46) ? VarOf_M_OK_xSORT : (EnumOf_M_OK_xSORT) TAG(sub__V46));
  switch (choice__V47)
  {
    case Data_M_OK: { /* Function DEFS-DCOMMENT_TOKEN-1$DCOMMENT_TOKEN$OK case OK */
      ASSERT(sink__V44->context, !strcmp(SYMBOL(term__V45),  "DCOMMENT_TOKEN" ));
      Term sub__V48 = SUB(term__V45, 0); permitUnusedTerm(sub__V48); int sub__V48_count = term__V45_count*LINK_COUNT(sub__V48); permitUnusedInt(sub__V48_count);
      CRSX_CHECK_SORT(sink__V44->context, sub__V48, &sort_M_OK_xSORT); ASSERT(sink__V44->context, !strcmp(SYMBOL(sub__V48),  "OK" ));
      Term sub__V49 = LINK(sink__V44->context, SUB(term__V45, 1)); int sub__V49_count = term__V45_count*LINK_COUNT(sub__V49); permitUnusedInt(sub__V49_count);
      /* sub__V49 = &#0 */
      
      NamedPropertyLink namedP__V50 = LINK_NamedPropertyLink(sink__V44->context, NAMED_PROPERTIES(term__V45));
      VariablePropertyLink varP__V51 = LINK_VariablePropertyLink(sink__V44->context, VARIABLE_PROPERTIES(term__V45));
      Hashset namedFV__V52 = LINK_VARIABLESET(sink__V44->context, namedPropertyFreeVars(namedP__V50));
      Hashset varFV__V53 = LINK_VARIABLESET(sink__V44->context, variablePropertyFreeVars(varP__V51));
      UNLINK(sink__V44->context, term__V45);
      ADD_PROPERTIES(sink__V44, LINK_VARIABLESET(sink__V44->context, namedFV__V52), LINK_VARIABLESET(sink__V44->context, varFV__V53), LINK_NamedPropertyLink(sink__V44->context, namedP__V50), LINK_VariablePropertyLink(sink__V44->context, varP__V51));
      { START(sink__V44, _M_DCOMMENT_xTOKEN_s1);
        COPY(sink__V44, sub__V49);END(sink__V44, _M_DCOMMENT_xTOKEN_s1); }
      UNLINK_VARIABLESET(sink__V44->context, namedFV__V52); UNLINK_VARIABLESET(sink__V44->context, varFV__V53);
      UNLINK_NamedPropertyLink(sink__V44->context, namedP__V50); UNLINK_VariablePropertyLink(sink__V44->context, varP__V51);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION MissingPrimitive. */
int conBindOffs_M_MissingPrimitive[] = {0 , 0};
char *nameFun_M_MissingPrimitive(Term term) { return  "MissingPrimitive" ; }
struct _ConstructionDescriptor descriptor_M_MissingPrimitive = {&sort_M_SPrimitive, 0, 1, sizeof(STRUCT_Con_M_MissingPrimitive), conBindOffs_M_MissingPrimitive, &nameFun_M_MissingPrimitive, &step_M_MissingPrimitive};

int step_M_MissingPrimitive(Sink sink__V54, Term term__V55)
{
  int term__V55_count = LINK_COUNT(term__V55); permitUnusedInt(term__V55_count);
  do {
    /* Contraction rule DEFS-MissingPrimitive-1. */
    ASSERT(sink__V54->context, !strcmp(SYMBOL(term__V55),  "MissingPrimitive" ));
    Term sub__V56 = LINK(sink__V54->context, SUB(term__V55, 0)); int sub__V56_count = term__V55_count*LINK_COUNT(sub__V56); permitUnusedInt(sub__V56_count);
    /* sub__V56 = &#1 */
    UNLINK(sink__V54->context, term__V55);
    char *sub__V57[3]; size_t sublength__V58[3]; size_t length__V59 = 0;
    length__V59 += (sublength__V58[0] = strlen(sub__V57[0] =  "$[" ));
    FORCE(sink__V54->context, sub__V56);
    length__V59 += (sublength__V58[1] = strlen(sub__V57[1] = SYMBOL(sub__V56)));
    UNLINK(sink__V54->context, sub__V56);length__V59 += (sublength__V58[2] = strlen(sub__V57[2] =  "] not supported" ));
    { char *str__V60 = ALLOCA(sink__V54->context, length__V59+1), *p__V61 = str__V60;
      int i; for (i = 0; i < 3; ++i) { memcpy(p__V61, sub__V57[i], sublength__V58[i]); p__V61 += sublength__V58[i]; }
      *p__V61 = '\0';
      ASSERT(sink__V54->context, strlen(str__V60) == length__V59);
      ERRORF(sink__V54->context, Default, "%s\n", str__V60); }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION If$1. */
int conBindOffs_M_If_s1[] = {0 , 0 , 0};
char *nameFun_M_If_s1(Term term) { return  "If$1" ; }
struct _ConstructionDescriptor descriptor_M_If_s1 = {NULL, 0, 2, sizeof(STRUCT_Con_M_If_s1), conBindOffs_M_If_s1, &nameFun_M_If_s1, &step_M_If_s1};

int step_M_If_s1(Sink sink__V62, Term term__V63)
{
  int term__V63_count = LINK_COUNT(term__V63); permitUnusedInt(term__V63_count);
  do {
    /* Contraction rule DEFS-If-2. */
    ASSERT(sink__V62->context, !strcmp(SYMBOL(term__V63),  "If$1" ));
    Term sub__V64 = SUB(term__V63, 0); permitUnusedTerm(sub__V64); int sub__V64_count = term__V63_count*LINK_COUNT(sub__V64); permitUnusedInt(sub__V64_count);
    /* sub__V64 = &#2 */
    Term sub__V65 = LINK(sink__V62->context, SUB(term__V63, 1)); int sub__V65_count = term__V63_count*LINK_COUNT(sub__V65); permitUnusedInt(sub__V65_count);
    /* sub__V65 = &#3 */
    UNLINK(sink__V62->context, term__V63); COPY(sink__V62, sub__V65); return 1;
  } while (0);
  return 0;
}

/* FUNCTION If$2. */
int conBindOffs_M_If_s2[] = {0 , 0 , 0};
char *nameFun_M_If_s2(Term term) { return  "If$2" ; }
struct _ConstructionDescriptor descriptor_M_If_s2 = {NULL, 0, 2, sizeof(STRUCT_Con_M_If_s2), conBindOffs_M_If_s2, &nameFun_M_If_s2, &step_M_If_s2};

int step_M_If_s2(Sink sink__V66, Term term__V67)
{
  int term__V67_count = LINK_COUNT(term__V67); permitUnusedInt(term__V67_count);
  do {
    /* Contraction rule DEFS-If-1. */
    ASSERT(sink__V66->context, !strcmp(SYMBOL(term__V67),  "If$2" ));
    Term sub__V68 = LINK(sink__V66->context, SUB(term__V67, 0)); int sub__V68_count = term__V67_count*LINK_COUNT(sub__V68); permitUnusedInt(sub__V68_count);
    /* sub__V68 = &#2 */
    Term sub__V69 = SUB(term__V67, 1); permitUnusedTerm(sub__V69); int sub__V69_count = term__V67_count*LINK_COUNT(sub__V69); permitUnusedInt(sub__V69_count);
    /* sub__V69 = &#3 */
    UNLINK(sink__V66->context, term__V67); COPY(sink__V66, sub__V68); return 1;
  } while (0);
  return 0;
}

/* FUNCTION NameFun. */
int conBindOffs_M_NameFun[] = {0 , 0};
char *nameFun_M_NameFun(Term term) { return  "NameFun" ; }
struct _ConstructionDescriptor descriptor_M_NameFun = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_NameFun), conBindOffs_M_NameFun, &nameFun_M_NameFun, &step_M_NameFun};

int step_M_NameFun(Sink sink__V70, Term term__V71)
{
  int term__V71_count = LINK_COUNT(term__V71); permitUnusedInt(term__V71_count);
  do {
    /* Contraction rule DEFS-NameFun-1. */
    ASSERT(sink__V70->context, !strcmp(SYMBOL(term__V71),  "NameFun" ));
    Term sub__V72 = LINK(sink__V70->context, SUB(term__V71, 0)); int sub__V72_count = term__V71_count*LINK_COUNT(sub__V72); permitUnusedInt(sub__V72_count);
    /* sub__V72 = &#1 */
    
    NamedPropertyLink namedP__V73 = LINK_NamedPropertyLink(sink__V70->context, NAMED_PROPERTIES(term__V71));
    VariablePropertyLink varP__V74 = LINK_VariablePropertyLink(sink__V70->context, VARIABLE_PROPERTIES(term__V71));
    Hashset namedFV__V75 = LINK_VARIABLESET(sink__V70->context, namedPropertyFreeVars(namedP__V73));
    Hashset varFV__V76 = LINK_VARIABLESET(sink__V70->context, variablePropertyFreeVars(varP__V74));
    UNLINK(sink__V70->context, term__V71);
    { START(sink__V70, _M__sTextCons);
      { START(sink__V70, _M__sTextChars);
        LITERAL(sink__V70,  "nameFun" ); END(sink__V70, _M__sTextChars); }
      { START(sink__V70, _M__sTextCons);
        { START(sink__V70, _M__sTextEmbed);
          { START(sink__V70, _M_AsText);
            { START(sink__V70, _M_MANGLE);
              COPY(sink__V70, sub__V72);END(sink__V70, _M_MANGLE); }
            END(sink__V70, _M_AsText); }
          END(sink__V70, _M__sTextEmbed); }
        { START(sink__V70, _M__sTextNil);
          END(sink__V70, _M__sTextNil); }
        END(sink__V70, _M__sTextCons); }
      END(sink__V70, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V70->context, namedFV__V75); UNLINK_VARIABLESET(sink__V70->context, varFV__V76);
    UNLINK_NamedPropertyLink(sink__V70->context, namedP__V73); UNLINK_VariablePropertyLink(sink__V70->context, varP__V74);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION FormArguments-binder-count$1. */
int conBindOffs_M_FormArguments__binder__count_s1[] = {0 , 0 , 0 , 0};
char *nameFun_M_FormArguments__binder__count_s1(Term term) { return  "FormArguments-binder-count$1" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__count_s1 = {NULL, 0, 3, sizeof(STRUCT_Con_M_FormArguments__binder__count_s1), conBindOffs_M_FormArguments__binder__count_s1, &nameFun_M_FormArguments__binder__count_s1, &step_M_FormArguments__binder__count_s1};

int step_M_FormArguments__binder__count_s1(Sink sink__V77, Term term__V78)
{
  int term__V78_count = LINK_COUNT(term__V78); permitUnusedInt(term__V78_count);
  do {
    /* Contraction rule DEFS-FormArguments-binder-count-1$FormArguments-binder-count$1$FORM-BINDER. */
    ASSERT(sink__V77->context, !strcmp(SYMBOL(term__V78),  "FormArguments-binder-count$1" ));
    Term sub__V79 = SUB(term__V78, 0); permitUnusedTerm(sub__V79); int sub__V79_count = term__V78_count*LINK_COUNT(sub__V79); permitUnusedInt(sub__V79_count);
    FORCE(sink__V77->context, sub__V79); SUB(term__V78, 0) = sub__V79;
    if (strcmp(SYMBOL(sub__V79),  "FORM-BINDER" )) break;
    Term sub__V80 = LINK(sink__V77->context, SUB(sub__V79, 0)); int sub__V80_count = sub__V79_count*LINK_COUNT(sub__V80); permitUnusedInt(sub__V80_count);
    CRSX_CHECK_SORT(sink__V77->context, sub__V80, &sort_M_Reified_xSort); /* sub__V80 = &#0-0 */
    Variable y__V81 = BINDER(sub__V79,1,0); if (sub__V79_count <= 1) UNBIND(y__V81);
    Term sub__V82 = LINK(sink__V77->context, SUB(sub__V79, 1)); int sub__V82_count = sub__V79_count*LINK_COUNT(sub__V82); permitUnusedInt(sub__V82_count);
    CRSX_CHECK_SORT(sink__V77->context, sub__V82, &sort_M_Reified_xFormArgument); /* sub__V82 = &#0-1 */
    Term sub__V83 = LINK(sink__V77->context, SUB(term__V78, 1)); int sub__V83_count = term__V78_count*LINK_COUNT(sub__V83); permitUnusedInt(sub__V83_count);
    /* sub__V83 = &#2 */
    Term sub__V84 = LINK(sink__V77->context, SUB(term__V78, 2)); int sub__V84_count = term__V78_count*LINK_COUNT(sub__V84); permitUnusedInt(sub__V84_count);
    /* sub__V84 = &#3 */
    
    NamedPropertyLink namedP__V85 = LINK_NamedPropertyLink(sink__V77->context, NAMED_PROPERTIES(term__V78));
    VariablePropertyLink varP__V86 = LINK_VariablePropertyLink(sink__V77->context, VARIABLE_PROPERTIES(term__V78));
    Hashset namedFV__V87 = LINK_VARIABLESET(sink__V77->context, namedPropertyFreeVars(namedP__V85));
    Hashset varFV__V88 = LINK_VARIABLESET(sink__V77->context, variablePropertyFreeVars(varP__V86));
    UNLINK(sink__V77->context, term__V78);
    ADD_PROPERTIES(sink__V77, LINK_VARIABLESET(sink__V77->context, namedFV__V87), LINK_VARIABLESET(sink__V77->context, varFV__V88), LINK_NamedPropertyLink(sink__V77->context, namedP__V85), LINK_VariablePropertyLink(sink__V77->context, varP__V86));
    { START(sink__V77, _M_FormArguments__binder__count_s3);
      COPY(sink__V77, sub__V80);{ if (!IS_BOUND(y__V81)) { REBIND(y__V81);
          Variable binds__V89[1] = {y__V81}; BINDS(sink__V77, 1, binds__V89);
          COPY(sink__V77, sub__V82); /* REUSED SUBSTITUTION */  }
        else { Variable b__V90 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V77->context,"b__V90");
          Variable binds__V91[1] = {b__V90}; BINDS(sink__V77, 1, binds__V91);
          {
            Term arg__V92;
            { Sink buf__V93 = ALLOCA_BUFFER(sink__V77->context);
              USE(buf__V93, b__V90); arg__V92 = BUFFER_TERM(buf__V93); FREE_BUFFER(buf__V93); }
            Variable vars__V94[1] = {y__V81};
            Term args__V95[1] = {arg__V92};
            struct _SubstitutionFrame substitution__V96 = {NULL, 0, 1, vars__V94, args__V95, NULL};
            SUBSTITUTE(sink__V77, sub__V82, &substitution__V96); }
              }
         }
      COPY(sink__V77, sub__V83);COPY(sink__V77, sub__V84);END(sink__V77, _M_FormArguments__binder__count_s3); }
    UNLINK_VARIABLESET(sink__V77->context, namedFV__V87); UNLINK_VARIABLESET(sink__V77->context, varFV__V88);
    UNLINK_NamedPropertyLink(sink__V77->context, namedP__V85); UNLINK_VariablePropertyLink(sink__V77->context, varP__V86);
    
    return 1;
  } while (0);
  do {
    /* Contraction rule DEFS-FormArguments-binder-count-2$FormArguments-binder-count$1$FORM-ARGUMENT. */
    ASSERT(sink__V77->context, !strcmp(SYMBOL(term__V78),  "FormArguments-binder-count$1" ));
    Term sub__V97 = SUB(term__V78, 0); permitUnusedTerm(sub__V97); int sub__V97_count = term__V78_count*LINK_COUNT(sub__V97); permitUnusedInt(sub__V97_count);
    FORCE(sink__V77->context, sub__V97); SUB(term__V78, 0) = sub__V97;
    if (strcmp(SYMBOL(sub__V97),  "FORM-ARGUMENT" )) break;
    Term sub__V98 = LINK(sink__V77->context, SUB(sub__V97, 0)); int sub__V98_count = sub__V97_count*LINK_COUNT(sub__V98); permitUnusedInt(sub__V98_count);
    CRSX_CHECK_SORT(sink__V77->context, sub__V98, &sort_M_Reified_xSort); /* sub__V98 = &#0-0 */
    Term sub__V99 = LINK(sink__V77->context, SUB(term__V78, 1)); int sub__V99_count = term__V78_count*LINK_COUNT(sub__V99); permitUnusedInt(sub__V99_count);
    /* sub__V99 = &#1 */
    Term sub__V100 = LINK(sink__V77->context, SUB(term__V78, 2)); int sub__V100_count = term__V78_count*LINK_COUNT(sub__V100); permitUnusedInt(sub__V100_count);
    /* sub__V100 = &#2 */
    
    NamedPropertyLink namedP__V101 = LINK_NamedPropertyLink(sink__V77->context, NAMED_PROPERTIES(term__V78));
    VariablePropertyLink varP__V102 = LINK_VariablePropertyLink(sink__V77->context, VARIABLE_PROPERTIES(term__V78));
    Hashset namedFV__V103 = LINK_VARIABLESET(sink__V77->context, namedPropertyFreeVars(namedP__V101));
    Hashset varFV__V104 = LINK_VARIABLESET(sink__V77->context, variablePropertyFreeVars(varP__V102));
    UNLINK(sink__V77->context, term__V78);
    ADD_PROPERTIES(sink__V77, LINK_VARIABLESET(sink__V77->context, namedFV__V103), LINK_VARIABLESET(sink__V77->context, varFV__V104), LINK_NamedPropertyLink(sink__V77->context, namedP__V101), LINK_VariablePropertyLink(sink__V77->context, varP__V102));
    { START(sink__V77, _M_FormArguments__binder__count_s2);
      COPY(sink__V77, sub__V98);COPY(sink__V77, sub__V99);COPY(sink__V77, sub__V100);END(sink__V77, _M_FormArguments__binder__count_s2); }
    UNLINK_VARIABLESET(sink__V77->context, namedFV__V103); UNLINK_VARIABLESET(sink__V77->context, varFV__V104);
    UNLINK_NamedPropertyLink(sink__V77->context, namedP__V101); UNLINK_VariablePropertyLink(sink__V77->context, varP__V102);
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION FormArguments-binder-count$2. */
int conBindOffs_M_FormArguments__binder__count_s2[] = {0 , 0 , 0 , 0};
char *nameFun_M_FormArguments__binder__count_s2(Term term) { return  "FormArguments-binder-count$2" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__count_s2 = {NULL, 0, 3, sizeof(STRUCT_Con_M_FormArguments__binder__count_s2), conBindOffs_M_FormArguments__binder__count_s2, &nameFun_M_FormArguments__binder__count_s2, &step_M_FormArguments__binder__count_s2};

int step_M_FormArguments__binder__count_s2(Sink sink__V105, Term term__V106)
{
  int term__V106_count = LINK_COUNT(term__V106); permitUnusedInt(term__V106_count);
  do {
    /* Contraction rule DEFS-FormArguments-binder-count-2. */
    ASSERT(sink__V105->context, !strcmp(SYMBOL(term__V106),  "FormArguments-binder-count$2" ));
    Term sub__V107 = SUB(term__V106, 0); permitUnusedTerm(sub__V107); int sub__V107_count = term__V106_count*LINK_COUNT(sub__V107); permitUnusedInt(sub__V107_count);
    CRSX_CHECK_SORT(sink__V105->context, sub__V107, &sort_M_Reified_xSort); /* sub__V107 = &#111 */
    Term sub__V108 = LINK(sink__V105->context, SUB(term__V106, 1)); int sub__V108_count = term__V106_count*LINK_COUNT(sub__V108); permitUnusedInt(sub__V108_count);
    /* sub__V108 = &#12 */
    Term sub__V109 = LINK(sink__V105->context, SUB(term__V106, 2)); int sub__V109_count = term__V106_count*LINK_COUNT(sub__V109); permitUnusedInt(sub__V109_count);
    /* sub__V109 = &#2 */
    UNLINK(sink__V105->context, term__V106);
    { START(sink__V105, _M_FormArguments__binder__count);
      COPY(sink__V105, sub__V108);COPY(sink__V105, sub__V109);END(sink__V105, _M_FormArguments__binder__count); }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION FormArguments-binder-count$3. */
int conBindOffs_M_FormArguments__binder__count_s3[] = {0 , 0 , 1 , 1 , 1};
char *nameFun_M_FormArguments__binder__count_s3(Term term) { return  "FormArguments-binder-count$3" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__count_s3 = {NULL, 0, 4, sizeof(STRUCT_Con_M_FormArguments__binder__count_s3), conBindOffs_M_FormArguments__binder__count_s3, &nameFun_M_FormArguments__binder__count_s3, &step_M_FormArguments__binder__count_s3};

int step_M_FormArguments__binder__count_s3(Sink sink__V110, Term term__V111)
{
  int term__V111_count = LINK_COUNT(term__V111); permitUnusedInt(term__V111_count);
  do {
    /* Contraction rule DEFS-FormArguments-binder-count-1. */
    ASSERT(sink__V110->context, !strcmp(SYMBOL(term__V111),  "FormArguments-binder-count$3" ));
    Term sub__V112 = SUB(term__V111, 0); permitUnusedTerm(sub__V112); int sub__V112_count = term__V111_count*LINK_COUNT(sub__V112); permitUnusedInt(sub__V112_count);
    CRSX_CHECK_SORT(sink__V110->context, sub__V112, &sort_M_Reified_xSort); /* sub__V112 = &#111 */
    Variable x__V113 = BINDER(term__V111,1,0); if (term__V111_count <= 1) UNBIND(x__V113);
    Term sub__V114 = LINK(sink__V110->context, SUB(term__V111, 1)); int sub__V114_count = term__V111_count*LINK_COUNT(sub__V114); permitUnusedInt(sub__V114_count);
    CRSX_CHECK_SORT(sink__V110->context, sub__V114, &sort_M_Reified_xFormArgument); /* sub__V114 = &#112 */
    Variable y__V115 = x__V113; permitUnusedVariable(y__V115);
    Term sub__V116 = LINK(sink__V110->context, SUB(term__V111, 2)); int sub__V116_count = term__V111_count*LINK_COUNT(sub__V116); permitUnusedInt(sub__V116_count);
    /* sub__V116 = &#12 */
    Term sub__V117 = LINK(sink__V110->context, SUB(term__V111, 3)); int sub__V117_count = term__V111_count*LINK_COUNT(sub__V117); permitUnusedInt(sub__V117_count);
    /* sub__V117 = &#2 */
    UNLINK(sink__V110->context, term__V111);
    { START(sink__V110, _M_FormArguments__binder__count);
      { START(sink__V110, _M__sCons);
        COPY(sink__V110, sub__V114); /* REUSED SUBSTITUTION */ COPY(sink__V110, sub__V116);END(sink__V110, _M__sCons); }
      { double num__V118;
        num__V118 = (double) 1; { double tmp__V119;
          tmp__V119 = DOUBLE(sub__V117); num__V118 += tmp__V119; }
        LITERALNF(sink__V110, (size_t) 31, "%G", num__V118); }
      END(sink__V110, _M_FormArguments__binder__count); }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION FormArguments-binder-count$4. */
int conBindOffs_M_FormArguments__binder__count_s4[] = {0 , 0};
char *nameFun_M_FormArguments__binder__count_s4(Term term) { return  "FormArguments-binder-count$4" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__count_s4 = {NULL, 0, 1, sizeof(STRUCT_Con_M_FormArguments__binder__count_s4), conBindOffs_M_FormArguments__binder__count_s4, &nameFun_M_FormArguments__binder__count_s4, &step_M_FormArguments__binder__count_s4};

int step_M_FormArguments__binder__count_s4(Sink sink__V120, Term term__V121)
{
  int term__V121_count = LINK_COUNT(term__V121); permitUnusedInt(term__V121_count);
  do {
    /* Contraction rule DEFS-FormArguments-binder-count-3. */
    ASSERT(sink__V120->context, !strcmp(SYMBOL(term__V121),  "FormArguments-binder-count$4" ));
    Term sub__V122 = LINK(sink__V120->context, SUB(term__V121, 0)); int sub__V122_count = term__V121_count*LINK_COUNT(sub__V122); permitUnusedInt(sub__V122_count);
    /* sub__V122 = &#2 */
    UNLINK(sink__V120->context, term__V121);
    COPY(sink__V120, sub__V122);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION FormArguments-binder-offsets. */
int conBindOffs_M_FormArguments__binder__offsets[] = {0 , 0 , 0};
char *nameFun_M_FormArguments__binder__offsets(Term term) { return  "FormArguments-binder-offsets" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__offsets = {NULL, 0, 2, sizeof(STRUCT_Con_M_FormArguments__binder__offsets), conBindOffs_M_FormArguments__binder__offsets, &nameFun_M_FormArguments__binder__offsets, &step_M_FormArguments__binder__offsets};

int step_M_FormArguments__binder__offsets(Sink sink__V123, Term term__V124)
{
  int term__V124_count = LINK_COUNT(term__V124); permitUnusedInt(term__V124_count);
  Term sub__V125 = FORCE(sink__V123->context, SUB(term__V124, 0));
  EnumOf_M__sList choice__V126 = (IS_VARIABLE_USE(sub__V125) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V125));
  switch (choice__V126)
  {
    case Data_M__sCons: { /* Function DEFS-FormArguments-binder-offsets-2$FormArguments-binder-offsets$$Cons case $Cons */
      ASSERT(sink__V123->context, !strcmp(SYMBOL(term__V124),  "FormArguments-binder-offsets" ));
      Term sub__V127 = SUB(term__V124, 0); permitUnusedTerm(sub__V127); int sub__V127_count = term__V124_count*LINK_COUNT(sub__V127); permitUnusedInt(sub__V127_count);
      ASSERT(sink__V123->context, !strcmp(SYMBOL(sub__V127),  "$Cons" ));
      Term sub__V128 = LINK(sink__V123->context, SUB(sub__V127, 0)); int sub__V128_count = sub__V127_count*LINK_COUNT(sub__V128); permitUnusedInt(sub__V128_count);
      /* sub__V128 = &#0-0 */
      Term sub__V129 = LINK(sink__V123->context, SUB(sub__V127, 1)); int sub__V129_count = sub__V127_count*LINK_COUNT(sub__V129); permitUnusedInt(sub__V129_count);
      /* sub__V129 = &#0-1 */
      Term sub__V130 = LINK(sink__V123->context, SUB(term__V124, 1)); int sub__V130_count = term__V124_count*LINK_COUNT(sub__V130); permitUnusedInt(sub__V130_count);
      /* sub__V130 = &#2 */
      
      NamedPropertyLink namedP__V131 = LINK_NamedPropertyLink(sink__V123->context, NAMED_PROPERTIES(term__V124));
      VariablePropertyLink varP__V132 = LINK_VariablePropertyLink(sink__V123->context, VARIABLE_PROPERTIES(term__V124));
      Hashset namedFV__V133 = LINK_VARIABLESET(sink__V123->context, namedPropertyFreeVars(namedP__V131));
      Hashset varFV__V134 = LINK_VARIABLESET(sink__V123->context, variablePropertyFreeVars(varP__V132));
      UNLINK(sink__V123->context, term__V124);
      ADD_PROPERTIES(sink__V123, LINK_VARIABLESET(sink__V123->context, namedFV__V133), LINK_VARIABLESET(sink__V123->context, varFV__V134), LINK_NamedPropertyLink(sink__V123->context, namedP__V131), LINK_VariablePropertyLink(sink__V123->context, varP__V132));
      { START(sink__V123, _M_FormArguments__binder__offsets_s1);
        COPY(sink__V123, sub__V128);COPY(sink__V123, sub__V129);COPY(sink__V123, sub__V130);END(sink__V123, _M_FormArguments__binder__offsets_s1); }
      UNLINK_VARIABLESET(sink__V123->context, namedFV__V133); UNLINK_VARIABLESET(sink__V123->context, varFV__V134);
      UNLINK_NamedPropertyLink(sink__V123->context, namedP__V131); UNLINK_VariablePropertyLink(sink__V123->context, varP__V132);
      
      return 1;
    break; } case Data_M__sNil: { /* Function DEFS-FormArguments-binder-offsets-3$FormArguments-binder-offsets$$Nil case $Nil */
      ASSERT(sink__V123->context, !strcmp(SYMBOL(term__V124),  "FormArguments-binder-offsets" ));
      Term sub__V135 = SUB(term__V124, 0); permitUnusedTerm(sub__V135); int sub__V135_count = term__V124_count*LINK_COUNT(sub__V135); permitUnusedInt(sub__V135_count);
      ASSERT(sink__V123->context, !strcmp(SYMBOL(sub__V135),  "$Nil" ));
      Term sub__V136 = LINK(sink__V123->context, SUB(term__V124, 1)); int sub__V136_count = term__V124_count*LINK_COUNT(sub__V136); permitUnusedInt(sub__V136_count);
      /* sub__V136 = &#0 */
      
      NamedPropertyLink namedP__V137 = LINK_NamedPropertyLink(sink__V123->context, NAMED_PROPERTIES(term__V124));
      VariablePropertyLink varP__V138 = LINK_VariablePropertyLink(sink__V123->context, VARIABLE_PROPERTIES(term__V124));
      Hashset namedFV__V139 = LINK_VARIABLESET(sink__V123->context, namedPropertyFreeVars(namedP__V137));
      Hashset varFV__V140 = LINK_VARIABLESET(sink__V123->context, variablePropertyFreeVars(varP__V138));
      UNLINK(sink__V123->context, term__V124);
      ADD_PROPERTIES(sink__V123, LINK_VARIABLESET(sink__V123->context, namedFV__V139), LINK_VARIABLESET(sink__V123->context, varFV__V140), LINK_NamedPropertyLink(sink__V123->context, namedP__V137), LINK_VariablePropertyLink(sink__V123->context, varP__V138));
      { START(sink__V123, _M_FormArguments__binder__offsets_s4);
        COPY(sink__V123, sub__V136);END(sink__V123, _M_FormArguments__binder__offsets_s4); }
      UNLINK_VARIABLESET(sink__V123->context, namedFV__V139); UNLINK_VARIABLESET(sink__V123->context, varFV__V140);
      UNLINK_NamedPropertyLink(sink__V123->context, namedP__V137); UNLINK_VariablePropertyLink(sink__V123->context, varP__V138);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION COMMENT_TOKEN. */
int conBindOffs_M_COMMENT_xTOKEN[] = {0 , 0};
char *nameFun_M_COMMENT_xTOKEN(Term term) { return  "COMMENT_TOKEN" ; }
struct _ConstructionDescriptor descriptor_M_COMMENT_xTOKEN = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_COMMENT_xTOKEN), conBindOffs_M_COMMENT_xTOKEN, &nameFun_M_COMMENT_xTOKEN, &step_M_COMMENT_xTOKEN};

int step_M_COMMENT_xTOKEN(Sink sink__V141, Term term__V142)
{
  int term__V142_count = LINK_COUNT(term__V142); permitUnusedInt(term__V142_count);
  do {
    /* Contraction rule DEFS-COMMENT_TOKEN-1. */
    ASSERT(sink__V141->context, !strcmp(SYMBOL(term__V142),  "COMMENT_TOKEN" ));
    Term sub__V143 = LINK(sink__V141->context, SUB(term__V142, 0)); int sub__V143_count = term__V142_count*LINK_COUNT(sub__V143); permitUnusedInt(sub__V143_count);
    UNLINK_SUB(sink__V141->context, term__V142,  0); NORMALIZE(sink__V141->context, sub__V143); SUB(term__V142,  0) = LINK(sink__V141->context, sub__V143);
    /* sub__V143 = &#1 */
    
    NamedPropertyLink namedP__V144 = LINK_NamedPropertyLink(sink__V141->context, NAMED_PROPERTIES(term__V142));
    VariablePropertyLink varP__V145 = LINK_VariablePropertyLink(sink__V141->context, VARIABLE_PROPERTIES(term__V142));
    Hashset namedFV__V146 = LINK_VARIABLESET(sink__V141->context, namedPropertyFreeVars(namedP__V144));
    Hashset varFV__V147 = LINK_VARIABLESET(sink__V141->context, variablePropertyFreeVars(varP__V145));
    UNLINK(sink__V141->context, term__V142);
    { START(sink__V141, _M__sTextCons);
      { START(sink__V141, _M__sTextChars);
        { char *str__V148;
          FORCE(sink__V141->context, sub__V143);
          { char *replaced__V149;
            const size_t z = strlen(SYMBOL(sub__V143));
            if (* "*/" ) {
              const size_t oldz = strlen( "*/" ), newz = strlen( "*_/" );
              size_t limitz;
              if (oldz==newz) { limitz = z; }
              else { limitz = z; size_t growz = (oldz < newz ? newz - oldz : 0);
                if (growz > 0) { char *p = SYMBOL(sub__V143); while ((p = strstr(p,  "*/" ))) { limitz += growz; p += oldz; } } }
              replaced__V149 = ALLOCA(sink__V141->context, limitz+1);
              if (oldz==newz) { memcpy(replaced__V149, SYMBOL(sub__V143), z+1);
                char *r = replaced__V149; while ((r = strstr(r,  "*/" ))) { memcpy(r,  "*_/" , newz); r += oldz; } }
              else { char *s = SYMBOL(sub__V143), *ends = s+z, *r = replaced__V149, *next;
                while ((next = strstr(s,  "*/" ))) { size_t prez = next-s;
                  if (prez) { memcpy(r, s, prez); r += prez; } 
                  if (newz) { memcpy(r,  "*_/" , newz); r += newz; }
                  s = next+oldz;}
                if (s < ends) { memcpy(r, s, ends-s); r += ends-s; }
                *r = '\0';}
              }
            else { replaced__V149 = memcpy(ALLOCA(sink__V141->context, z+1), SYMBOL(sub__V143), z+1); }
             UNLINK(sink__V141->context, sub__V143);{ size_t z__V150 = strlen(replaced__V149) + 1; memcpy(str__V148 = ALLOCATE(sink__V141->context, z__V150), replaced__V149, z__V150); }
            
          }LITERALU(sink__V141, str__V148); }
        END(sink__V141, _M__sTextChars); }
      { START(sink__V141, _M__sTextNil);
        END(sink__V141, _M__sTextNil); }
      END(sink__V141, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V141->context, namedFV__V146); UNLINK_VARIABLESET(sink__V141->context, varFV__V147);
    UNLINK_NamedPropertyLink(sink__V141->context, namedP__V144); UNLINK_VariablePropertyLink(sink__V141->context, varP__V145);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION STRING. */
int conBindOffs_M_STRING[] = {0 , 0};
char *nameFun_M_STRING(Term term) { return  "STRING" ; }
struct _ConstructionDescriptor descriptor_M_STRING = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_STRING), conBindOffs_M_STRING, &nameFun_M_STRING, &step_M_STRING};

int step_M_STRING(Sink sink__V151, Term term__V152)
{
  int term__V152_count = LINK_COUNT(term__V152); permitUnusedInt(term__V152_count);
  do {
    /* Contraction rule DEFS-STRING-1. */
    ASSERT(sink__V151->context, !strcmp(SYMBOL(term__V152),  "STRING" ));
    Term sub__V153 = LINK(sink__V151->context, SUB(term__V152, 0)); int sub__V153_count = term__V152_count*LINK_COUNT(sub__V153); permitUnusedInt(sub__V153_count);
    UNLINK_SUB(sink__V151->context, term__V152,  0); NORMALIZE(sink__V151->context, sub__V153); SUB(term__V152,  0) = LINK(sink__V151->context, sub__V153);
    /* sub__V153 = &#1 */
    
    NamedPropertyLink namedP__V154 = LINK_NamedPropertyLink(sink__V151->context, NAMED_PROPERTIES(term__V152));
    VariablePropertyLink varP__V155 = LINK_VariablePropertyLink(sink__V151->context, VARIABLE_PROPERTIES(term__V152));
    Hashset namedFV__V156 = LINK_VARIABLESET(sink__V151->context, namedPropertyFreeVars(namedP__V154));
    Hashset varFV__V157 = LINK_VARIABLESET(sink__V151->context, variablePropertyFreeVars(varP__V155));
    UNLINK(sink__V151->context, term__V152);
    { START(sink__V151, _M__sTextCons);
      { START(sink__V151, _M__sTextChars);
        LITERAL(sink__V151,  " " ); END(sink__V151, _M__sTextChars); }
      { START(sink__V151, _M__sTextCons);
        { START(sink__V151, _M__sTextString);
          { START(sink__V151, _M__sTextCons);
            { START(sink__V151, _M__sTextChars);
              { char *str__V158;
                FORCE(sink__V151->context, sub__V153);
                {str__V158 = makeEscaped(sink__V151->context, SYMBOL(sub__V153));
                  UNLINK(sink__V151->context, sub__V153);}
                LITERALU(sink__V151, str__V158); }
              END(sink__V151, _M__sTextChars); }
            { START(sink__V151, _M__sTextNil);
              END(sink__V151, _M__sTextNil); }
            END(sink__V151, _M__sTextCons); }
          END(sink__V151, _M__sTextString); }
        { START(sink__V151, _M__sTextCons);
          { START(sink__V151, _M__sTextChars);
            LITERAL(sink__V151,  " " ); END(sink__V151, _M__sTextChars); }
          { START(sink__V151, _M__sTextNil);
            END(sink__V151, _M__sTextNil); }
          END(sink__V151, _M__sTextCons); }
        END(sink__V151, _M__sTextCons); }
      END(sink__V151, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V151->context, namedFV__V156); UNLINK_VARIABLESET(sink__V151->context, varFV__V157);
    UNLINK_NamedPropertyLink(sink__V151->context, namedP__V154); UNLINK_VariablePropertyLink(sink__V151->context, varP__V155);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION SortNames. */
int conBindOffs_M_SortNames[] = {0 , 0};
char *nameFun_M_SortNames(Term term) { return  "SortNames" ; }
struct _ConstructionDescriptor descriptor_M_SortNames = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_SortNames), conBindOffs_M_SortNames, &nameFun_M_SortNames, &step_M_SortNames};

int step_M_SortNames(Sink sink__V159, Term term__V160)
{
  int term__V160_count = LINK_COUNT(term__V160); permitUnusedInt(term__V160_count);
  do {
    /* Contraction rule DEFS-SortNames-1. */
    ASSERT(sink__V159->context, !strcmp(SYMBOL(term__V160),  "SortNames" ));
    Term sub__V161 = LINK(sink__V159->context, SUB(term__V160, 0)); int sub__V161_count = term__V160_count*LINK_COUNT(sub__V161); permitUnusedInt(sub__V161_count);
    /* sub__V161 = &#1 */
    
    NamedPropertyLink namedP__V162 = LINK_NamedPropertyLink(sink__V159->context, NAMED_PROPERTIES(term__V160));
    VariablePropertyLink varP__V163 = LINK_VariablePropertyLink(sink__V159->context, VARIABLE_PROPERTIES(term__V160));
    Hashset namedFV__V164 = LINK_VARIABLESET(sink__V159->context, namedPropertyFreeVars(namedP__V162));
    Hashset varFV__V165 = LINK_VARIABLESET(sink__V159->context, variablePropertyFreeVars(varP__V163));
    UNLINK(sink__V159->context, term__V160);
    { START(sink__V159, _M__sTextCons);
      { START(sink__V159, _M__sTextChars);
        LITERAL(sink__V159,  "sortNam" ); END(sink__V159, _M__sTextChars); }
      { START(sink__V159, _M__sTextCons);
        { START(sink__V159, _M__sTextEmbed);
          { START(sink__V159, _M_AsText);
            { START(sink__V159, _M_MANGLE);
              COPY(sink__V159, sub__V161);END(sink__V159, _M_MANGLE); }
            END(sink__V159, _M_AsText); }
          END(sink__V159, _M__sTextEmbed); }
        { START(sink__V159, _M__sTextNil);
          END(sink__V159, _M__sTextNil); }
        END(sink__V159, _M__sTextCons); }
      END(sink__V159, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V159->context, namedFV__V164); UNLINK_VARIABLESET(sink__V159->context, varFV__V165);
    UNLINK_NamedPropertyLink(sink__V159->context, namedP__V162); UNLINK_VariablePropertyLink(sink__V159->context, varP__V163);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION FormArguments-binder-count. */
int conBindOffs_M_FormArguments__binder__count[] = {0 , 0 , 0};
char *nameFun_M_FormArguments__binder__count(Term term) { return  "FormArguments-binder-count" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__count = {NULL, 0, 2, sizeof(STRUCT_Con_M_FormArguments__binder__count), conBindOffs_M_FormArguments__binder__count, &nameFun_M_FormArguments__binder__count, &step_M_FormArguments__binder__count};

int step_M_FormArguments__binder__count(Sink sink__V166, Term term__V167)
{
  int term__V167_count = LINK_COUNT(term__V167); permitUnusedInt(term__V167_count);
  Term sub__V168 = FORCE(sink__V166->context, SUB(term__V167, 0));
  EnumOf_M__sList choice__V169 = (IS_VARIABLE_USE(sub__V168) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V168));
  switch (choice__V169)
  {
    case Data_M__sCons: { /* Function DEFS-FormArguments-binder-count-2$FormArguments-binder-count$$Cons case $Cons */
      ASSERT(sink__V166->context, !strcmp(SYMBOL(term__V167),  "FormArguments-binder-count" ));
      Term sub__V170 = SUB(term__V167, 0); permitUnusedTerm(sub__V170); int sub__V170_count = term__V167_count*LINK_COUNT(sub__V170); permitUnusedInt(sub__V170_count);
      ASSERT(sink__V166->context, !strcmp(SYMBOL(sub__V170),  "$Cons" ));
      Term sub__V171 = LINK(sink__V166->context, SUB(sub__V170, 0)); int sub__V171_count = sub__V170_count*LINK_COUNT(sub__V171); permitUnusedInt(sub__V171_count);
      /* sub__V171 = &#0-0 */
      Term sub__V172 = LINK(sink__V166->context, SUB(sub__V170, 1)); int sub__V172_count = sub__V170_count*LINK_COUNT(sub__V172); permitUnusedInt(sub__V172_count);
      /* sub__V172 = &#0-1 */
      Term sub__V173 = LINK(sink__V166->context, SUB(term__V167, 1)); int sub__V173_count = term__V167_count*LINK_COUNT(sub__V173); permitUnusedInt(sub__V173_count);
      /* sub__V173 = &#2 */
      
      NamedPropertyLink namedP__V174 = LINK_NamedPropertyLink(sink__V166->context, NAMED_PROPERTIES(term__V167));
      VariablePropertyLink varP__V175 = LINK_VariablePropertyLink(sink__V166->context, VARIABLE_PROPERTIES(term__V167));
      Hashset namedFV__V176 = LINK_VARIABLESET(sink__V166->context, namedPropertyFreeVars(namedP__V174));
      Hashset varFV__V177 = LINK_VARIABLESET(sink__V166->context, variablePropertyFreeVars(varP__V175));
      UNLINK(sink__V166->context, term__V167);
      ADD_PROPERTIES(sink__V166, LINK_VARIABLESET(sink__V166->context, namedFV__V176), LINK_VARIABLESET(sink__V166->context, varFV__V177), LINK_NamedPropertyLink(sink__V166->context, namedP__V174), LINK_VariablePropertyLink(sink__V166->context, varP__V175));
      { START(sink__V166, _M_FormArguments__binder__count_s1);
        COPY(sink__V166, sub__V171);COPY(sink__V166, sub__V172);COPY(sink__V166, sub__V173);END(sink__V166, _M_FormArguments__binder__count_s1); }
      UNLINK_VARIABLESET(sink__V166->context, namedFV__V176); UNLINK_VARIABLESET(sink__V166->context, varFV__V177);
      UNLINK_NamedPropertyLink(sink__V166->context, namedP__V174); UNLINK_VariablePropertyLink(sink__V166->context, varP__V175);
      
      return 1;
    break; } case Data_M__sNil: { /* Function DEFS-FormArguments-binder-count-3$FormArguments-binder-count$$Nil case $Nil */
      ASSERT(sink__V166->context, !strcmp(SYMBOL(term__V167),  "FormArguments-binder-count" ));
      Term sub__V178 = SUB(term__V167, 0); permitUnusedTerm(sub__V178); int sub__V178_count = term__V167_count*LINK_COUNT(sub__V178); permitUnusedInt(sub__V178_count);
      ASSERT(sink__V166->context, !strcmp(SYMBOL(sub__V178),  "$Nil" ));
      Term sub__V179 = LINK(sink__V166->context, SUB(term__V167, 1)); int sub__V179_count = term__V167_count*LINK_COUNT(sub__V179); permitUnusedInt(sub__V179_count);
      /* sub__V179 = &#0 */
      
      NamedPropertyLink namedP__V180 = LINK_NamedPropertyLink(sink__V166->context, NAMED_PROPERTIES(term__V167));
      VariablePropertyLink varP__V181 = LINK_VariablePropertyLink(sink__V166->context, VARIABLE_PROPERTIES(term__V167));
      Hashset namedFV__V182 = LINK_VARIABLESET(sink__V166->context, namedPropertyFreeVars(namedP__V180));
      Hashset varFV__V183 = LINK_VARIABLESET(sink__V166->context, variablePropertyFreeVars(varP__V181));
      UNLINK(sink__V166->context, term__V167);
      ADD_PROPERTIES(sink__V166, LINK_VARIABLESET(sink__V166->context, namedFV__V182), LINK_VARIABLESET(sink__V166->context, varFV__V183), LINK_NamedPropertyLink(sink__V166->context, namedP__V180), LINK_VariablePropertyLink(sink__V166->context, varP__V181));
      { START(sink__V166, _M_FormArguments__binder__count_s4);
        COPY(sink__V166, sub__V179);END(sink__V166, _M_FormArguments__binder__count_s4); }
      UNLINK_VARIABLESET(sink__V166->context, namedFV__V182); UNLINK_VARIABLESET(sink__V166->context, varFV__V183);
      UNLINK_NamedPropertyLink(sink__V166->context, namedP__V180); UNLINK_VariablePropertyLink(sink__V166->context, varP__V181);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION DSTRING$1. */
int conBindOffs_M_DSTRING_s1[] = {0 , 0};
char *nameFun_M_DSTRING_s1(Term term) { return  "DSTRING$1" ; }
struct _ConstructionDescriptor descriptor_M_DSTRING_s1 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_DSTRING_s1), conBindOffs_M_DSTRING_s1, &nameFun_M_DSTRING_s1, &step_M_DSTRING_s1};

int step_M_DSTRING_s1(Sink sink__V184, Term term__V185)
{
  int term__V185_count = LINK_COUNT(term__V185); permitUnusedInt(term__V185_count);
  do {
    /* Contraction rule DEFS-DSTRING-1. */
    ASSERT(sink__V184->context, !strcmp(SYMBOL(term__V185),  "DSTRING$1" ));
    Term sub__V186 = LINK(sink__V184->context, SUB(term__V185, 0)); int sub__V186_count = term__V185_count*LINK_COUNT(sub__V186); permitUnusedInt(sub__V186_count);
    UNLINK_SUB(sink__V184->context, term__V185,  0); NORMALIZE(sink__V184->context, sub__V186); SUB(term__V185,  0) = LINK(sink__V184->context, sub__V186);
    /* sub__V186 = &#2 */
    
    NamedPropertyLink namedP__V187 = LINK_NamedPropertyLink(sink__V184->context, NAMED_PROPERTIES(term__V185));
    VariablePropertyLink varP__V188 = LINK_VariablePropertyLink(sink__V184->context, VARIABLE_PROPERTIES(term__V185));
    Hashset namedFV__V189 = LINK_VARIABLESET(sink__V184->context, namedPropertyFreeVars(namedP__V187));
    Hashset varFV__V190 = LINK_VARIABLESET(sink__V184->context, variablePropertyFreeVars(varP__V188));
    UNLINK(sink__V184->context, term__V185);
    { START(sink__V184, _M__sTextCons);
      { START(sink__V184, _M__sTextChars);
        LITERAL(sink__V184,  " " ); END(sink__V184, _M__sTextChars); }
      { START(sink__V184, _M__sTextCons);
        { START(sink__V184, _M__sTextString);
          { START(sink__V184, _M__sTextCons);
            { START(sink__V184, _M__sTextChars);
              { char *str__V191;
                FORCE(sink__V184->context, sub__V186);
                {str__V191 = makeEscaped(sink__V184->context, SYMBOL(sub__V186));
                  UNLINK(sink__V184->context, sub__V186);}
                LITERALU(sink__V184, str__V191); }
              END(sink__V184, _M__sTextChars); }
            { START(sink__V184, _M__sTextNil);
              END(sink__V184, _M__sTextNil); }
            END(sink__V184, _M__sTextCons); }
          END(sink__V184, _M__sTextString); }
        { START(sink__V184, _M__sTextCons);
          { START(sink__V184, _M__sTextChars);
            LITERAL(sink__V184,  " " ); END(sink__V184, _M__sTextChars); }
          { START(sink__V184, _M__sTextNil);
            END(sink__V184, _M__sTextNil); }
          END(sink__V184, _M__sTextCons); }
        END(sink__V184, _M__sTextCons); }
      END(sink__V184, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V184->context, namedFV__V189); UNLINK_VARIABLESET(sink__V184->context, varFV__V190);
    UNLINK_NamedPropertyLink(sink__V184->context, namedP__V187); UNLINK_VariablePropertyLink(sink__V184->context, varP__V188);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DelayMapText$1. */
int conBindOffs_M_DelayMapText_s1[] = {0 , 0 , 2};
char *nameFun_M_DelayMapText_s1(Term term) { return  "DelayMapText$1" ; }
struct _ConstructionDescriptor descriptor_M_DelayMapText_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_DelayMapText_s1), conBindOffs_M_DelayMapText_s1, &nameFun_M_DelayMapText_s1, &step_M_DelayMapText_s1};

int step_M_DelayMapText_s1(Sink sink__V192, Term term__V193)
{
  int term__V193_count = LINK_COUNT(term__V193); permitUnusedInt(term__V193_count);
  Term sub__V194 = FORCE(sink__V192->context, SUB(term__V193, 0));
  EnumOf_M__sList choice__V195 = (IS_VARIABLE_USE(sub__V194) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V194));
  switch (choice__V195)
  {
    case Data_M__sCons: { /* Function DEFS-DelayMapText-1$DelayMapText$1$$Cons case $Cons */
      ASSERT(sink__V192->context, !strcmp(SYMBOL(term__V193),  "DelayMapText$1" ));
      Term sub__V196 = SUB(term__V193, 0); permitUnusedTerm(sub__V196); int sub__V196_count = term__V193_count*LINK_COUNT(sub__V196); permitUnusedInt(sub__V196_count);
      ASSERT(sink__V192->context, !strcmp(SYMBOL(sub__V196),  "$Cons" ));
      Term sub__V197 = LINK(sink__V192->context, SUB(sub__V196, 0)); int sub__V197_count = sub__V196_count*LINK_COUNT(sub__V197); permitUnusedInt(sub__V197_count);
      /* sub__V197 = &#0-0 */
      Term sub__V198 = LINK(sink__V192->context, SUB(sub__V196, 1)); int sub__V198_count = sub__V196_count*LINK_COUNT(sub__V198); permitUnusedInt(sub__V198_count);
      /* sub__V198 = &#0-1 */
      Variable x__V199 = BINDER(term__V193,1,0); if (term__V193_count <= 1) UNBIND(x__V199);
      Variable x__V200 = BINDER(term__V193,1,1); if (term__V193_count <= 1) UNBIND(x__V200);
      Term sub__V201 = LINK(sink__V192->context, SUB(term__V193, 1)); int sub__V201_count = term__V193_count*LINK_COUNT(sub__V201); permitUnusedInt(sub__V201_count);
      CRSX_CHECK_SORT(sink__V192->context, sub__V201, &sort_M_Reified_xVariable); /* sub__V201 = &#2 */
      
      NamedPropertyLink namedP__V202 = LINK_NamedPropertyLink(sink__V192->context, NAMED_PROPERTIES(term__V193));
      VariablePropertyLink varP__V203 = LINK_VariablePropertyLink(sink__V192->context, VARIABLE_PROPERTIES(term__V193));
      Hashset namedFV__V204 = LINK_VARIABLESET(sink__V192->context, namedPropertyFreeVars(namedP__V202));
      Hashset varFV__V205 = LINK_VARIABLESET(sink__V192->context, variablePropertyFreeVars(varP__V203));
      UNLINK(sink__V192->context, term__V193);
      ADD_PROPERTIES(sink__V192, LINK_VARIABLESET(sink__V192->context, namedFV__V204), LINK_VARIABLESET(sink__V192->context, varFV__V205), LINK_NamedPropertyLink(sink__V192->context, namedP__V202), LINK_VariablePropertyLink(sink__V192->context, varP__V203));
      { START(sink__V192, _M_DelayMapText_s2);
        COPY(sink__V192, sub__V197);COPY(sink__V192, sub__V198);{ if (!IS_BOUND(x__V199)) { REBIND(x__V199);
            REBIND(x__V200);
            Variable binds__V206[2] = {x__V199,x__V200}; BINDS(sink__V192, 2, binds__V206);
            COPY(sink__V192, sub__V201); /* REUSED SUBSTITUTION */  }
          else { Variable b__V207 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V192->context,"b__V207");
            Variable b__V208 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V192->context,"b__V208");
            Variable binds__V209[2] = {b__V207,b__V208}; BINDS(sink__V192, 2, binds__V209);
            {
              Term arg__V210;
              { Sink buf__V211 = ALLOCA_BUFFER(sink__V192->context);
                USE(buf__V211, b__V207); arg__V210 = BUFFER_TERM(buf__V211); FREE_BUFFER(buf__V211); }
              Term arg__V212;
              { Sink buf__V213 = ALLOCA_BUFFER(sink__V192->context);
                USE(buf__V213, b__V208); arg__V212 = BUFFER_TERM(buf__V213); FREE_BUFFER(buf__V213); }
              Variable vars__V214[2] = {x__V199,x__V200};
              Term args__V215[2] = {arg__V210,arg__V212};
              struct _SubstitutionFrame substitution__V216 = {NULL, 0, 2, vars__V214, args__V215, NULL};
              SUBSTITUTE(sink__V192, sub__V201, &substitution__V216); }
                }
           }
        END(sink__V192, _M_DelayMapText_s2); }
      UNLINK_VARIABLESET(sink__V192->context, namedFV__V204); UNLINK_VARIABLESET(sink__V192->context, varFV__V205);
      UNLINK_NamedPropertyLink(sink__V192->context, namedP__V202); UNLINK_VariablePropertyLink(sink__V192->context, varP__V203);
      
      return 1;
    break; } case Data_M__sNil: { /* Function DEFS-DelayMapText-2$DelayMapText$1$$Nil case $Nil */
      ASSERT(sink__V192->context, !strcmp(SYMBOL(term__V193),  "DelayMapText$1" ));
      Term sub__V217 = SUB(term__V193, 0); permitUnusedTerm(sub__V217); int sub__V217_count = term__V193_count*LINK_COUNT(sub__V217); permitUnusedInt(sub__V217_count);
      ASSERT(sink__V192->context, !strcmp(SYMBOL(sub__V217),  "$Nil" ));
      Variable x__V218 = BINDER(term__V193,1,0); if (term__V193_count <= 1) UNBIND(x__V218);
      Variable x__V219 = BINDER(term__V193,1,1); if (term__V193_count <= 1) UNBIND(x__V219);
      Term sub__V220 = LINK(sink__V192->context, SUB(term__V193, 1)); int sub__V220_count = term__V193_count*LINK_COUNT(sub__V220); permitUnusedInt(sub__V220_count);
      CRSX_CHECK_SORT(sink__V192->context, sub__V220, &sort_M_Reified_xVariable); /* sub__V220 = &#0 */
      
      NamedPropertyLink namedP__V221 = LINK_NamedPropertyLink(sink__V192->context, NAMED_PROPERTIES(term__V193));
      VariablePropertyLink varP__V222 = LINK_VariablePropertyLink(sink__V192->context, VARIABLE_PROPERTIES(term__V193));
      Hashset namedFV__V223 = LINK_VARIABLESET(sink__V192->context, namedPropertyFreeVars(namedP__V221));
      Hashset varFV__V224 = LINK_VARIABLESET(sink__V192->context, variablePropertyFreeVars(varP__V222));
      UNLINK(sink__V192->context, term__V193);
      ADD_PROPERTIES(sink__V192, LINK_VARIABLESET(sink__V192->context, namedFV__V223), LINK_VARIABLESET(sink__V192->context, varFV__V224), LINK_NamedPropertyLink(sink__V192->context, namedP__V221), LINK_VariablePropertyLink(sink__V192->context, varP__V222));
      { START(sink__V192, _M_DelayMapText_s3);
        { if (!IS_BOUND(x__V218)) { REBIND(x__V218);
            REBIND(x__V219);
            Variable binds__V225[2] = {x__V218,x__V219}; BINDS(sink__V192, 2, binds__V225);
            COPY(sink__V192, sub__V220); /* REUSED SUBSTITUTION */  }
          else { Variable b__V226 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V192->context,"b__V226");
            Variable b__V227 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V192->context,"b__V227");
            Variable binds__V228[2] = {b__V226,b__V227}; BINDS(sink__V192, 2, binds__V228);
            {
              Term arg__V229;
              { Sink buf__V230 = ALLOCA_BUFFER(sink__V192->context);
                USE(buf__V230, b__V226); arg__V229 = BUFFER_TERM(buf__V230); FREE_BUFFER(buf__V230); }
              Term arg__V231;
              { Sink buf__V232 = ALLOCA_BUFFER(sink__V192->context);
                USE(buf__V232, b__V227); arg__V231 = BUFFER_TERM(buf__V232); FREE_BUFFER(buf__V232); }
              Variable vars__V233[2] = {x__V218,x__V219};
              Term args__V234[2] = {arg__V229,arg__V231};
              struct _SubstitutionFrame substitution__V235 = {NULL, 0, 2, vars__V233, args__V234, NULL};
              SUBSTITUTE(sink__V192, sub__V220, &substitution__V235); }
                }
           }
        END(sink__V192, _M_DelayMapText_s3); }
      UNLINK_VARIABLESET(sink__V192->context, namedFV__V223); UNLINK_VARIABLESET(sink__V192->context, varFV__V224);
      UNLINK_NamedPropertyLink(sink__V192->context, namedP__V221); UNLINK_VariablePropertyLink(sink__V192->context, varP__V222);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION DelayMapText$2. */
int conBindOffs_M_DelayMapText_s2[] = {0 , 0 , 0 , 2};
char *nameFun_M_DelayMapText_s2(Term term) { return  "DelayMapText$2" ; }
struct _ConstructionDescriptor descriptor_M_DelayMapText_s2 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_DelayMapText_s2), conBindOffs_M_DelayMapText_s2, &nameFun_M_DelayMapText_s2, &step_M_DelayMapText_s2};

int step_M_DelayMapText_s2(Sink sink__V236, Term term__V237)
{
  int term__V237_count = LINK_COUNT(term__V237); permitUnusedInt(term__V237_count);
  do {
    /* Contraction rule DEFS-DelayMapText-1. */
    ASSERT(sink__V236->context, !strcmp(SYMBOL(term__V237),  "DelayMapText$2" ));
    Term sub__V238 = LINK(sink__V236->context, SUB(term__V237, 0)); int sub__V238_count = term__V237_count*LINK_COUNT(sub__V238); permitUnusedInt(sub__V238_count);
    /* sub__V238 = &#21 */
    Term sub__V239 = LINK(sink__V236->context, SUB(term__V237, 1)); int sub__V239_count = term__V237_count*LINK_COUNT(sub__V239); permitUnusedInt(sub__V239_count);
    /* sub__V239 = &#22 */
    Variable x__V240 = BINDER(term__V237,2,0); if (term__V237_count <= 1) UNBIND(x__V240);
    Variable x__V241 = BINDER(term__V237,2,1); if (term__V237_count <= 1) UNBIND(x__V241);
    Term sub__V242 = LINK(sink__V236->context, SUB(term__V237, 2)); int sub__V242_count = term__V237_count*LINK_COUNT(sub__V242); permitUnusedInt(sub__V242_count);
    CRSX_CHECK_SORT(sink__V236->context, sub__V242, &sort_M_Reified_xVariable); UNLINK_SUB(sink__V236->context, term__V237,  2); NORMALIZE(sink__V236->context, sub__V242); SUB(term__V237,  2) = LINK(sink__V236->context, sub__V242);
    /* sub__V242 = &#1 */
    
    NamedPropertyLink namedP__V243 = LINK_NamedPropertyLink(sink__V236->context, NAMED_PROPERTIES(term__V237));
    VariablePropertyLink varP__V244 = LINK_VariablePropertyLink(sink__V236->context, VARIABLE_PROPERTIES(term__V237));
    Hashset namedFV__V245 = LINK_VARIABLESET(sink__V236->context, namedPropertyFreeVars(namedP__V243));
    Hashset varFV__V246 = LINK_VARIABLESET(sink__V236->context, variablePropertyFreeVars(varP__V244));
    UNLINK(sink__V236->context, term__V237);
    { START(sink__V236, _M__sTextCons);
      { START(sink__V236, _M__sTextEmbed);
        { START(sink__V236, _M_AsText);
          {
            Term arg__V247;
            { Sink buf__V248 = ALLOCA_BUFFER(sink__V236->context);
              { START(buf__V248, _M_OK); END(buf__V248, _M_OK); } arg__V247 = BUFFER_TERM(buf__V248); FREE_BUFFER(buf__V248); }
            Term arg__V249;
            { Sink buf__V250 = ALLOCA_BUFFER(sink__V236->context);
              COPY(buf__V250, sub__V238);arg__V249 = BUFFER_TERM(buf__V250); FREE_BUFFER(buf__V250); }
            Variable vars__V251[2] = {x__V240,x__V241};
            Term args__V252[2] = {arg__V247,arg__V249};
            struct _SubstitutionFrame substitution__V253 = {NULL, 0, 2, vars__V251, args__V252, NULL};
            SUBSTITUTE(sink__V236, LINK(sink__V236->context,sub__V242), &substitution__V253); }
          END(sink__V236, _M_AsText); }
        END(sink__V236, _M__sTextEmbed); }
      { START(sink__V236, _M__sTextCons);
        { START(sink__V236, _M__sTextEmbed);
          { START(sink__V236, _M_AsText);
            { START(sink__V236, _M_DelayMapText_s1);
              COPY(sink__V236, sub__V239);{ Variable x__V254 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V236->context,"x__V254");
                Variable x__V255 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V236->context,"x__V255");
                Variable binds__V256[2] = {x__V254,x__V255}; BINDS(sink__V236, 2, binds__V256);
                {
                  Term arg__V257;
                  { Sink buf__V258 = ALLOCA_BUFFER(sink__V236->context);
                    USE(buf__V258, x__V254); arg__V257 = BUFFER_TERM(buf__V258); FREE_BUFFER(buf__V258); }
                  Term arg__V259;
                  { Sink buf__V260 = ALLOCA_BUFFER(sink__V236->context);
                    USE(buf__V260, x__V255); arg__V259 = BUFFER_TERM(buf__V260); FREE_BUFFER(buf__V260); }
                  Variable vars__V261[2] = {x__V240,x__V241};
                  Term args__V262[2] = {arg__V257,arg__V259};
                  struct _SubstitutionFrame substitution__V263 = {NULL, 0, 2, vars__V261, args__V262, NULL};
                  SUBSTITUTE(sink__V236, sub__V242, &substitution__V263); }
                 }
              END(sink__V236, _M_DelayMapText_s1); }
            END(sink__V236, _M_AsText); }
          END(sink__V236, _M__sTextEmbed); }
        { START(sink__V236, _M__sTextNil);
          END(sink__V236, _M__sTextNil); }
        END(sink__V236, _M__sTextCons); }
      END(sink__V236, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V236->context, namedFV__V245); UNLINK_VARIABLESET(sink__V236->context, varFV__V246);
    UNLINK_NamedPropertyLink(sink__V236->context, namedP__V243); UNLINK_VariablePropertyLink(sink__V236->context, varP__V244);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DelayMapText$3. */
int conBindOffs_M_DelayMapText_s3[] = {0 , 2};
char *nameFun_M_DelayMapText_s3(Term term) { return  "DelayMapText$3" ; }
struct _ConstructionDescriptor descriptor_M_DelayMapText_s3 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_DelayMapText_s3), conBindOffs_M_DelayMapText_s3, &nameFun_M_DelayMapText_s3, &step_M_DelayMapText_s3};

int step_M_DelayMapText_s3(Sink sink__V264, Term term__V265)
{
  int term__V265_count = LINK_COUNT(term__V265); permitUnusedInt(term__V265_count);
  do {
    /* Contraction rule DEFS-DelayMapText-2. */
    ASSERT(sink__V264->context, !strcmp(SYMBOL(term__V265),  "DelayMapText$3" ));
    Variable x__V266 = BINDER(term__V265,0,0); if (term__V265_count <= 1) UNBIND(x__V266);
    Variable x__V267 = BINDER(term__V265,0,1); if (term__V265_count <= 1) UNBIND(x__V267);
    Term sub__V268 = SUB(term__V265, 0); permitUnusedTerm(sub__V268); int sub__V268_count = term__V265_count*LINK_COUNT(sub__V268); permitUnusedInt(sub__V268_count);
    CRSX_CHECK_SORT(sink__V264->context, sub__V268, &sort_M_Reified_xVariable); /* sub__V268 = &#1 */
    
    NamedPropertyLink namedP__V269 = LINK_NamedPropertyLink(sink__V264->context, NAMED_PROPERTIES(term__V265));
    VariablePropertyLink varP__V270 = LINK_VariablePropertyLink(sink__V264->context, VARIABLE_PROPERTIES(term__V265));
    Hashset namedFV__V271 = LINK_VARIABLESET(sink__V264->context, namedPropertyFreeVars(namedP__V269));
    Hashset varFV__V272 = LINK_VARIABLESET(sink__V264->context, variablePropertyFreeVars(varP__V270));
    UNLINK(sink__V264->context, term__V265);
    { START(sink__V264, _M__sTextNil); END(sink__V264, _M__sTextNil); }
    UNLINK_VARIABLESET(sink__V264->context, namedFV__V271); UNLINK_VARIABLESET(sink__V264->context, varFV__V272);
    UNLINK_NamedPropertyLink(sink__V264->context, namedP__V269); UNLINK_VariablePropertyLink(sink__V264->context, varP__V270);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Forms-Constructors. */
int conBindOffs_M_Forms_Constructors[] = {0 , 0};
char *nameFun_M_Forms_Constructors(Term term) { return  "Forms-Constructors" ; }
struct _ConstructionDescriptor descriptor_M_Forms_Constructors = {NULL, 0, 1, sizeof(STRUCT_Con_M_Forms_Constructors), conBindOffs_M_Forms_Constructors, &nameFun_M_Forms_Constructors, &step_M_Forms_Constructors};

int step_M_Forms_Constructors(Sink sink__V273, Term term__V274)
{
  int term__V274_count = LINK_COUNT(term__V274); permitUnusedInt(term__V274_count);
  Term sub__V275 = FORCE(sink__V273->context, SUB(term__V274, 0));
  EnumOf_M__sList choice__V276 = (IS_VARIABLE_USE(sub__V275) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V275));
  switch (choice__V276)
  {
    case Data_M__sCons: { /* Function DEFS-Forms-Constructors-3$Forms-Constructors$$Cons case $Cons */
      ASSERT(sink__V273->context, !strcmp(SYMBOL(term__V274),  "Forms-Constructors" ));
      Term sub__V277 = SUB(term__V274, 0); permitUnusedTerm(sub__V277); int sub__V277_count = term__V274_count*LINK_COUNT(sub__V277); permitUnusedInt(sub__V277_count);
      ASSERT(sink__V273->context, !strcmp(SYMBOL(sub__V277),  "$Cons" ));
      Term sub__V278 = LINK(sink__V273->context, SUB(sub__V277, 0)); int sub__V278_count = sub__V277_count*LINK_COUNT(sub__V278); permitUnusedInt(sub__V278_count);
      /* sub__V278 = &#0-0 */
      Term sub__V279 = LINK(sink__V273->context, SUB(sub__V277, 1)); int sub__V279_count = sub__V277_count*LINK_COUNT(sub__V279); permitUnusedInt(sub__V279_count);
      /* sub__V279 = &#0-1 */
      
      NamedPropertyLink namedP__V280 = LINK_NamedPropertyLink(sink__V273->context, NAMED_PROPERTIES(term__V274));
      VariablePropertyLink varP__V281 = LINK_VariablePropertyLink(sink__V273->context, VARIABLE_PROPERTIES(term__V274));
      Hashset namedFV__V282 = LINK_VARIABLESET(sink__V273->context, namedPropertyFreeVars(namedP__V280));
      Hashset varFV__V283 = LINK_VARIABLESET(sink__V273->context, variablePropertyFreeVars(varP__V281));
      UNLINK(sink__V273->context, term__V274);
      ADD_PROPERTIES(sink__V273, LINK_VARIABLESET(sink__V273->context, namedFV__V282), LINK_VARIABLESET(sink__V273->context, varFV__V283), LINK_NamedPropertyLink(sink__V273->context, namedP__V280), LINK_VariablePropertyLink(sink__V273->context, varP__V281));
      { START(sink__V273, _M_Forms_Constructors_s1);
        COPY(sink__V273, sub__V278);COPY(sink__V273, sub__V279);END(sink__V273, _M_Forms_Constructors_s1); }
      UNLINK_VARIABLESET(sink__V273->context, namedFV__V282); UNLINK_VARIABLESET(sink__V273->context, varFV__V283);
      UNLINK_NamedPropertyLink(sink__V273->context, namedP__V280); UNLINK_VariablePropertyLink(sink__V273->context, varP__V281);
      
      return 1;
    break; } case Data_M__sNil: { /* Function DEFS-Forms-Constructors-4$Forms-Constructors$$Nil case $Nil */
      ASSERT(sink__V273->context, !strcmp(SYMBOL(term__V274),  "Forms-Constructors" ));
      Term sub__V284 = SUB(term__V274, 0); permitUnusedTerm(sub__V284); int sub__V284_count = term__V274_count*LINK_COUNT(sub__V284); permitUnusedInt(sub__V284_count);
      ASSERT(sink__V273->context, !strcmp(SYMBOL(sub__V284),  "$Nil" ));
      
      NamedPropertyLink namedP__V285 = LINK_NamedPropertyLink(sink__V273->context, NAMED_PROPERTIES(term__V274));
      VariablePropertyLink varP__V286 = LINK_VariablePropertyLink(sink__V273->context, VARIABLE_PROPERTIES(term__V274));
      Hashset namedFV__V287 = LINK_VARIABLESET(sink__V273->context, namedPropertyFreeVars(namedP__V285));
      Hashset varFV__V288 = LINK_VARIABLESET(sink__V273->context, variablePropertyFreeVars(varP__V286));
      UNLINK(sink__V273->context, term__V274);
      ADD_PROPERTIES(sink__V273, LINK_VARIABLESET(sink__V273->context, namedFV__V287), LINK_VARIABLESET(sink__V273->context, varFV__V288), LINK_NamedPropertyLink(sink__V273->context, namedP__V285), LINK_VariablePropertyLink(sink__V273->context, varP__V286));
      { START(sink__V273, _M_Forms_Constructors_s5);
        END(sink__V273, _M_Forms_Constructors_s5); }
      UNLINK_VARIABLESET(sink__V273->context, namedFV__V287); UNLINK_VARIABLESET(sink__V273->context, varFV__V288);
      UNLINK_NamedPropertyLink(sink__V273->context, namedP__V285); UNLINK_VariablePropertyLink(sink__V273->context, varP__V286);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION DEnumTag$1. */
int conBindOffs_M_DEnumTag_s1[] = {0 , 0};
char *nameFun_M_DEnumTag_s1(Term term) { return  "DEnumTag$1" ; }
struct _ConstructionDescriptor descriptor_M_DEnumTag_s1 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_DEnumTag_s1), conBindOffs_M_DEnumTag_s1, &nameFun_M_DEnumTag_s1, &step_M_DEnumTag_s1};

int step_M_DEnumTag_s1(Sink sink__V289, Term term__V290)
{
  int term__V290_count = LINK_COUNT(term__V290); permitUnusedInt(term__V290_count);
  do {
    /* Contraction rule DEFS-DEnumTag-1. */
    ASSERT(sink__V289->context, !strcmp(SYMBOL(term__V290),  "DEnumTag$1" ));
    Term sub__V291 = LINK(sink__V289->context, SUB(term__V290, 0)); int sub__V291_count = term__V290_count*LINK_COUNT(sub__V291); permitUnusedInt(sub__V291_count);
    /* sub__V291 = &#2 */
    
    NamedPropertyLink namedP__V292 = LINK_NamedPropertyLink(sink__V289->context, NAMED_PROPERTIES(term__V290));
    VariablePropertyLink varP__V293 = LINK_VariablePropertyLink(sink__V289->context, VARIABLE_PROPERTIES(term__V290));
    Hashset namedFV__V294 = LINK_VARIABLESET(sink__V289->context, namedPropertyFreeVars(namedP__V292));
    Hashset varFV__V295 = LINK_VARIABLESET(sink__V289->context, variablePropertyFreeVars(varP__V293));
    UNLINK(sink__V289->context, term__V290);
    { START(sink__V289, _M__sTextCons);
      { START(sink__V289, _M__sTextChars);
        LITERAL(sink__V289,  "Data" ); END(sink__V289, _M__sTextChars); }
      { START(sink__V289, _M__sTextCons);
        { START(sink__V289, _M__sTextEmbed);
          { START(sink__V289, _M_AsText);
            { START(sink__V289, _M_MANGLE);
              COPY(sink__V289, sub__V291);END(sink__V289, _M_MANGLE); }
            END(sink__V289, _M_AsText); }
          END(sink__V289, _M__sTextEmbed); }
        { START(sink__V289, _M__sTextNil);
          END(sink__V289, _M__sTextNil); }
        END(sink__V289, _M__sTextCons); }
      END(sink__V289, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V289->context, namedFV__V294); UNLINK_VARIABLESET(sink__V289->context, varFV__V295);
    UNLINK_NamedPropertyLink(sink__V289->context, namedP__V292); UNLINK_VariablePropertyLink(sink__V289->context, varP__V293);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DCOMMENT_TOKEN$1. */
int conBindOffs_M_DCOMMENT_xTOKEN_s1[] = {0 , 0};
char *nameFun_M_DCOMMENT_xTOKEN_s1(Term term) { return  "DCOMMENT_TOKEN$1" ; }
struct _ConstructionDescriptor descriptor_M_DCOMMENT_xTOKEN_s1 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_DCOMMENT_xTOKEN_s1), conBindOffs_M_DCOMMENT_xTOKEN_s1, &nameFun_M_DCOMMENT_xTOKEN_s1, &step_M_DCOMMENT_xTOKEN_s1};

int step_M_DCOMMENT_xTOKEN_s1(Sink sink__V296, Term term__V297)
{
  int term__V297_count = LINK_COUNT(term__V297); permitUnusedInt(term__V297_count);
  do {
    /* Contraction rule DEFS-DCOMMENT_TOKEN-1. */
    ASSERT(sink__V296->context, !strcmp(SYMBOL(term__V297),  "DCOMMENT_TOKEN$1" ));
    Term sub__V298 = LINK(sink__V296->context, SUB(term__V297, 0)); int sub__V298_count = term__V297_count*LINK_COUNT(sub__V298); permitUnusedInt(sub__V298_count);
    UNLINK_SUB(sink__V296->context, term__V297,  0); NORMALIZE(sink__V296->context, sub__V298); SUB(term__V297,  0) = LINK(sink__V296->context, sub__V298);
    /* sub__V298 = &#2 */
    
    NamedPropertyLink namedP__V299 = LINK_NamedPropertyLink(sink__V296->context, NAMED_PROPERTIES(term__V297));
    VariablePropertyLink varP__V300 = LINK_VariablePropertyLink(sink__V296->context, VARIABLE_PROPERTIES(term__V297));
    Hashset namedFV__V301 = LINK_VARIABLESET(sink__V296->context, namedPropertyFreeVars(namedP__V299));
    Hashset varFV__V302 = LINK_VARIABLESET(sink__V296->context, variablePropertyFreeVars(varP__V300));
    UNLINK(sink__V296->context, term__V297);
    { START(sink__V296, _M__sTextCons);
      { START(sink__V296, _M__sTextChars);
        { char *str__V303;
          FORCE(sink__V296->context, sub__V298);
          { char *replaced__V304;
            const size_t z = strlen(SYMBOL(sub__V298));
            if (* "*/" ) {
              const size_t oldz = strlen( "*/" ), newz = strlen( "*_/" );
              size_t limitz;
              if (oldz==newz) { limitz = z; }
              else { limitz = z; size_t growz = (oldz < newz ? newz - oldz : 0);
                if (growz > 0) { char *p = SYMBOL(sub__V298); while ((p = strstr(p,  "*/" ))) { limitz += growz; p += oldz; } } }
              replaced__V304 = ALLOCA(sink__V296->context, limitz+1);
              if (oldz==newz) { memcpy(replaced__V304, SYMBOL(sub__V298), z+1);
                char *r = replaced__V304; while ((r = strstr(r,  "*/" ))) { memcpy(r,  "*_/" , newz); r += oldz; } }
              else { char *s = SYMBOL(sub__V298), *ends = s+z, *r = replaced__V304, *next;
                while ((next = strstr(s,  "*/" ))) { size_t prez = next-s;
                  if (prez) { memcpy(r, s, prez); r += prez; } 
                  if (newz) { memcpy(r,  "*_/" , newz); r += newz; }
                  s = next+oldz;}
                if (s < ends) { memcpy(r, s, ends-s); r += ends-s; }
                *r = '\0';}
              }
            else { replaced__V304 = memcpy(ALLOCA(sink__V296->context, z+1), SYMBOL(sub__V298), z+1); }
             UNLINK(sink__V296->context, sub__V298);{ size_t z__V305 = strlen(replaced__V304) + 1; memcpy(str__V303 = ALLOCATE(sink__V296->context, z__V305), replaced__V304, z__V305); }
            
          }LITERALU(sink__V296, str__V303); }
        END(sink__V296, _M__sTextChars); }
      { START(sink__V296, _M__sTextNil);
        END(sink__V296, _M__sTextNil); }
      END(sink__V296, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V296->context, namedFV__V301); UNLINK_VARIABLESET(sink__V296->context, varFV__V302);
    UNLINK_NamedPropertyLink(sink__V296->context, namedP__V299); UNLINK_VariablePropertyLink(sink__V296->context, varP__V300);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION IfZero. */
int conBindOffs_M_IfZero[] = {0 , 0 , 0 , 0};
char *nameFun_M_IfZero(Term term) { return  "IfZero" ; }
struct _ConstructionDescriptor descriptor_M_IfZero = {NULL, 0, 3, sizeof(STRUCT_Con_M_IfZero), conBindOffs_M_IfZero, &nameFun_M_IfZero, &step_M_IfZero};

int step_M_IfZero(Sink sink__V306, Term term__V307)
{
  int term__V307_count = LINK_COUNT(term__V307); permitUnusedInt(term__V307_count);
  do {
    /* Contraction rule DEFS-IfZero-1. */
    ASSERT(sink__V306->context, !strcmp(SYMBOL(term__V307),  "IfZero" ));
    Term sub__V308 = LINK(sink__V306->context, SUB(term__V307, 0)); int sub__V308_count = term__V307_count*LINK_COUNT(sub__V308); permitUnusedInt(sub__V308_count);
    UNLINK_SUB(sink__V306->context, term__V307,  0); NORMALIZE(sink__V306->context, sub__V308); SUB(term__V307,  0) = LINK(sink__V306->context, sub__V308);
    /* sub__V308 = &#1 */
    Term sub__V309 = LINK(sink__V306->context, SUB(term__V307, 1)); int sub__V309_count = term__V307_count*LINK_COUNT(sub__V309); permitUnusedInt(sub__V309_count);
    /* sub__V309 = &#2 */
    Term sub__V310 = LINK(sink__V306->context, SUB(term__V307, 2)); int sub__V310_count = term__V307_count*LINK_COUNT(sub__V310); permitUnusedInt(sub__V310_count);
    /* sub__V310 = &#3 */
    UNLINK(sink__V306->context, term__V307);
    { long long intt__V311;
      intt__V311 = LONGLONG(sub__V308); if (intt__V311 == 0ll) {  UNLINK(sink__V306->context, sub__V310); COPY(sink__V306, sub__V309); }
      else { COPY(sink__V306, sub__V310); }
    }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DMANGLE. */
int conBindOffs_M_DMANGLE[] = {0 , 0 , 0};
char *nameFun_M_DMANGLE(Term term) { return  "DMANGLE" ; }
struct _ConstructionDescriptor descriptor_M_DMANGLE = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_DMANGLE), conBindOffs_M_DMANGLE, &nameFun_M_DMANGLE, &step_M_DMANGLE};

int step_M_DMANGLE(Sink sink__V312, Term term__V313)
{
  int term__V313_count = LINK_COUNT(term__V313); permitUnusedInt(term__V313_count);
  Term sub__V314 = FORCE(sink__V312->context, SUB(term__V313, 0));
  EnumOf_M_OK_xSORT choice__V315 = (IS_VARIABLE_USE(sub__V314) ? VarOf_M_OK_xSORT : (EnumOf_M_OK_xSORT) TAG(sub__V314));
  switch (choice__V315)
  {
    case Data_M_OK: { /* Function DEFS-DMANGLE-1$DMANGLE$OK case OK */
      ASSERT(sink__V312->context, !strcmp(SYMBOL(term__V313),  "DMANGLE" ));
      Term sub__V316 = SUB(term__V313, 0); permitUnusedTerm(sub__V316); int sub__V316_count = term__V313_count*LINK_COUNT(sub__V316); permitUnusedInt(sub__V316_count);
      CRSX_CHECK_SORT(sink__V312->context, sub__V316, &sort_M_OK_xSORT); ASSERT(sink__V312->context, !strcmp(SYMBOL(sub__V316),  "OK" ));
      Term sub__V317 = LINK(sink__V312->context, SUB(term__V313, 1)); int sub__V317_count = term__V313_count*LINK_COUNT(sub__V317); permitUnusedInt(sub__V317_count);
      /* sub__V317 = &#0 */
      
      NamedPropertyLink namedP__V318 = LINK_NamedPropertyLink(sink__V312->context, NAMED_PROPERTIES(term__V313));
      VariablePropertyLink varP__V319 = LINK_VariablePropertyLink(sink__V312->context, VARIABLE_PROPERTIES(term__V313));
      Hashset namedFV__V320 = LINK_VARIABLESET(sink__V312->context, namedPropertyFreeVars(namedP__V318));
      Hashset varFV__V321 = LINK_VARIABLESET(sink__V312->context, variablePropertyFreeVars(varP__V319));
      UNLINK(sink__V312->context, term__V313);
      ADD_PROPERTIES(sink__V312, LINK_VARIABLESET(sink__V312->context, namedFV__V320), LINK_VARIABLESET(sink__V312->context, varFV__V321), LINK_NamedPropertyLink(sink__V312->context, namedP__V318), LINK_VariablePropertyLink(sink__V312->context, varP__V319));
      { START(sink__V312, _M_DMANGLE_s1);
        COPY(sink__V312, sub__V317);END(sink__V312, _M_DMANGLE_s1); }
      UNLINK_VARIABLESET(sink__V312->context, namedFV__V320); UNLINK_VARIABLESET(sink__V312->context, varFV__V321);
      UNLINK_NamedPropertyLink(sink__V312->context, namedP__V318); UNLINK_VariablePropertyLink(sink__V312->context, varP__V319);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION EnumVar. */
int conBindOffs_M_EnumVar[] = {0 , 0};
char *nameFun_M_EnumVar(Term term) { return  "EnumVar" ; }
struct _ConstructionDescriptor descriptor_M_EnumVar = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_EnumVar), conBindOffs_M_EnumVar, &nameFun_M_EnumVar, &step_M_EnumVar};

int step_M_EnumVar(Sink sink__V322, Term term__V323)
{
  int term__V323_count = LINK_COUNT(term__V323); permitUnusedInt(term__V323_count);
  do {
    /* Contraction rule DEFS-EnumVar-1. */
    ASSERT(sink__V322->context, !strcmp(SYMBOL(term__V323),  "EnumVar" ));
    Term sub__V324 = LINK(sink__V322->context, SUB(term__V323, 0)); int sub__V324_count = term__V323_count*LINK_COUNT(sub__V324); permitUnusedInt(sub__V324_count);
    /* sub__V324 = &#1 */
    
    NamedPropertyLink namedP__V325 = LINK_NamedPropertyLink(sink__V322->context, NAMED_PROPERTIES(term__V323));
    VariablePropertyLink varP__V326 = LINK_VariablePropertyLink(sink__V322->context, VARIABLE_PROPERTIES(term__V323));
    Hashset namedFV__V327 = LINK_VARIABLESET(sink__V322->context, namedPropertyFreeVars(namedP__V325));
    Hashset varFV__V328 = LINK_VARIABLESET(sink__V322->context, variablePropertyFreeVars(varP__V326));
    UNLINK(sink__V322->context, term__V323);
    { START(sink__V322, _M__sTextCons);
      { START(sink__V322, _M__sTextChars);
        LITERAL(sink__V322,  "VarOf" ); END(sink__V322, _M__sTextChars); }
      { START(sink__V322, _M__sTextCons);
        { START(sink__V322, _M__sTextEmbed);
          { START(sink__V322, _M_AsText);
            { START(sink__V322, _M_MANGLE);
              COPY(sink__V322, sub__V324);END(sink__V322, _M_MANGLE); }
            END(sink__V322, _M_AsText); }
          END(sink__V322, _M__sTextEmbed); }
        { START(sink__V322, _M__sTextNil);
          END(sink__V322, _M__sTextNil); }
        END(sink__V322, _M__sTextCons); }
      END(sink__V322, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V322->context, namedFV__V327); UNLINK_VARIABLESET(sink__V322->context, varFV__V328);
    UNLINK_NamedPropertyLink(sink__V322->context, namedP__V325); UNLINK_VariablePropertyLink(sink__V322->context, varP__V326);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DDescriptor$1. */
int conBindOffs_M_DDescriptor_s1[] = {0 , 0};
char *nameFun_M_DDescriptor_s1(Term term) { return  "DDescriptor$1" ; }
struct _ConstructionDescriptor descriptor_M_DDescriptor_s1 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_DDescriptor_s1), conBindOffs_M_DDescriptor_s1, &nameFun_M_DDescriptor_s1, &step_M_DDescriptor_s1};

int step_M_DDescriptor_s1(Sink sink__V329, Term term__V330)
{
  int term__V330_count = LINK_COUNT(term__V330); permitUnusedInt(term__V330_count);
  do {
    /* Contraction rule DEFS-DDescriptor-1. */
    ASSERT(sink__V329->context, !strcmp(SYMBOL(term__V330),  "DDescriptor$1" ));
    Term sub__V331 = LINK(sink__V329->context, SUB(term__V330, 0)); int sub__V331_count = term__V330_count*LINK_COUNT(sub__V331); permitUnusedInt(sub__V331_count);
    /* sub__V331 = &#2 */
    
    NamedPropertyLink namedP__V332 = LINK_NamedPropertyLink(sink__V329->context, NAMED_PROPERTIES(term__V330));
    VariablePropertyLink varP__V333 = LINK_VariablePropertyLink(sink__V329->context, VARIABLE_PROPERTIES(term__V330));
    Hashset namedFV__V334 = LINK_VARIABLESET(sink__V329->context, namedPropertyFreeVars(namedP__V332));
    Hashset varFV__V335 = LINK_VARIABLESET(sink__V329->context, variablePropertyFreeVars(varP__V333));
    UNLINK(sink__V329->context, term__V330);
    { START(sink__V329, _M__sTextCons);
      { START(sink__V329, _M__sTextChars);
        LITERAL(sink__V329,  "descriptor" ); END(sink__V329, _M__sTextChars); }
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
    UNLINK_VARIABLESET(sink__V329->context, namedFV__V334); UNLINK_VARIABLESET(sink__V329->context, varFV__V335);
    UNLINK_NamedPropertyLink(sink__V329->context, namedP__V332); UNLINK_VariablePropertyLink(sink__V329->context, varP__V333);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION MetaVar. */
int conBindOffs_M_MetaVar[] = {0 , 0};
char *nameFun_M_MetaVar(Term term) { return  "MetaVar" ; }
struct _ConstructionDescriptor descriptor_M_MetaVar = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_MetaVar), conBindOffs_M_MetaVar, &nameFun_M_MetaVar, &step_M_MetaVar};

int step_M_MetaVar(Sink sink__V336, Term term__V337)
{
  int term__V337_count = LINK_COUNT(term__V337); permitUnusedInt(term__V337_count);
  do {
    /* Contraction rule DEFS-MetaVar-1. */
    ASSERT(sink__V336->context, !strcmp(SYMBOL(term__V337),  "MetaVar" ));
    Term sub__V338 = LINK(sink__V336->context, SUB(term__V337, 0)); int sub__V338_count = term__V337_count*LINK_COUNT(sub__V338); permitUnusedInt(sub__V338_count);
    UNLINK_SUB(sink__V336->context, term__V337,  0); NORMALIZE(sink__V336->context, sub__V338); SUB(term__V337,  0) = LINK(sink__V336->context, sub__V338);
    /* sub__V338 = &#1 */
    
    NamedPropertyLink namedP__V339 = LINK_NamedPropertyLink(sink__V336->context, NAMED_PROPERTIES(term__V337));
    VariablePropertyLink varP__V340 = LINK_VariablePropertyLink(sink__V336->context, VARIABLE_PROPERTIES(term__V337));
    Hashset namedFV__V341 = LINK_VARIABLESET(sink__V336->context, namedPropertyFreeVars(namedP__V339));
    Hashset varFV__V342 = LINK_VARIABLESET(sink__V336->context, variablePropertyFreeVars(varP__V340));
    UNLINK(sink__V336->context, term__V337);
    ADD_PROPERTIES(sink__V336, LINK_VARIABLESET(sink__V336->context, namedFV__V341), LINK_VARIABLESET(sink__V336->context, varFV__V342), LINK_NamedPropertyLink(sink__V336->context, namedP__V339), LINK_VariablePropertyLink(sink__V336->context, varP__V340));
    { START(sink__V336, _M_MetaVar2);
      { Term term__V343;
        { Term key__V344;
          char *sub__V345[2]; size_t sublength__V346[2]; size_t length__V347 = 0;
          length__V347 += (sublength__V346[0] = strlen(sub__V345[0] =  "MetaVar$" ));
          FORCE(sink__V336->context, sub__V338);
          length__V347 += (sublength__V346[1] = strlen(sub__V345[1] = SYMBOL(sub__V338)));
          { char *str__V348 = ALLOCA(sink__V336->context, length__V347+1), *p__V349 = str__V348;
            int i; for (i = 0; i < 2; ++i) { memcpy(p__V349, sub__V345[i], sublength__V346[i]); p__V349 += sublength__V346[i]; }
            *p__V349 = '\0';
            ASSERT(sink__V336->context, strlen(str__V348) == length__V347);
            key__V344 = makeStringLiteral(sink__V336->context, str__V348);
            }
          Term *pp__V350 = DPROPERTY(sink__V336->context, namedP__V339, varP__V340, key__V344);UNLINK(sink__V336->context, key__V344); 
          if (pp__V350) term__V343 = LINK(sink__V336->context, *pp__V350);
          else {{ Sink buf__V351 = ALLOCA_BUFFER(sink__V336->context);
              { START(buf__V351, _M_STRING_xVALUE);
                { char *str__V352;
                  { char *sub__V353[2]; size_t sublength__V354[2]; size_t length__V355 = 0;
                    length__V355 += (sublength__V354[0] = strlen(sub__V353[0] =  "m" ));
                    FORCE(buf__V351->context, sub__V338);
                    { char *s__V356 = makeMangled(buf__V351->context, SYMBOL(sub__V338));
                      length__V355 += (sublength__V354[1] = strlen(sub__V353[1] = s__V356));
                      UNLINK(buf__V351->context, sub__V338);{ char *str__V357 = ALLOCATE(buf__V351->context, length__V355+1), *p__V358 = str__V357;
                        int i; for (i = 0; i < 2; ++i) { memcpy(p__V358, sub__V353[i], sublength__V354[i]); p__V358 += sublength__V354[i]; }
                        *p__V358 = '\0';
                        ASSERT(buf__V351->context, strlen(str__V357) == length__V355);
                        str__V352 = str__V357; }
                      }
                     }
                  LITERALU(buf__V351, str__V352); }
                END(buf__V351, _M_STRING_xVALUE); }
              term__V343 = BUFFER_TERM(buf__V351); FREE_BUFFER(buf__V351); }
            }
        }
        COPY(sink__V336, term__V343); /*CONSERVATIVE*/ }
      END(sink__V336, _M_MetaVar2); }
    UNLINK_VARIABLESET(sink__V336->context, namedFV__V341); UNLINK_VARIABLESET(sink__V336->context, varFV__V342);
    UNLINK_NamedPropertyLink(sink__V336->context, namedP__V339); UNLINK_VariablePropertyLink(sink__V336->context, varP__V340);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Length. */
int conBindOffs_M_Length[] = {0 , 0 , 0};
char *nameFun_M_Length(Term term) { return  "Length" ; }
struct _ConstructionDescriptor descriptor_M_Length = {NULL, 0, 2, sizeof(STRUCT_Con_M_Length), conBindOffs_M_Length, &nameFun_M_Length, &step_M_Length};

int step_M_Length(Sink sink__V359, Term term__V360)
{
  int term__V360_count = LINK_COUNT(term__V360); permitUnusedInt(term__V360_count);
  Term sub__V361 = FORCE(sink__V359->context, SUB(term__V360, 0));
  EnumOf_M__sList choice__V362 = (IS_VARIABLE_USE(sub__V361) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V361));
  switch (choice__V362)
  {
    case Data_M__sNil: { /* Function DEFS-Length-1$Length$$Nil case $Nil */
      ASSERT(sink__V359->context, !strcmp(SYMBOL(term__V360),  "Length" ));
      Term sub__V363 = SUB(term__V360, 0); permitUnusedTerm(sub__V363); int sub__V363_count = term__V360_count*LINK_COUNT(sub__V363); permitUnusedInt(sub__V363_count);
      ASSERT(sink__V359->context, !strcmp(SYMBOL(sub__V363),  "$Nil" ));
      Term sub__V364 = LINK(sink__V359->context, SUB(term__V360, 1)); int sub__V364_count = term__V360_count*LINK_COUNT(sub__V364); permitUnusedInt(sub__V364_count);
      /* sub__V364 = &#0 */
      
      NamedPropertyLink namedP__V365 = LINK_NamedPropertyLink(sink__V359->context, NAMED_PROPERTIES(term__V360));
      VariablePropertyLink varP__V366 = LINK_VariablePropertyLink(sink__V359->context, VARIABLE_PROPERTIES(term__V360));
      Hashset namedFV__V367 = LINK_VARIABLESET(sink__V359->context, namedPropertyFreeVars(namedP__V365));
      Hashset varFV__V368 = LINK_VARIABLESET(sink__V359->context, variablePropertyFreeVars(varP__V366));
      UNLINK(sink__V359->context, term__V360);
      ADD_PROPERTIES(sink__V359, LINK_VARIABLESET(sink__V359->context, namedFV__V367), LINK_VARIABLESET(sink__V359->context, varFV__V368), LINK_NamedPropertyLink(sink__V359->context, namedP__V365), LINK_VariablePropertyLink(sink__V359->context, varP__V366));
      { START(sink__V359, _M_Length_s2);
        COPY(sink__V359, sub__V364);END(sink__V359, _M_Length_s2); }
      UNLINK_VARIABLESET(sink__V359->context, namedFV__V367); UNLINK_VARIABLESET(sink__V359->context, varFV__V368);
      UNLINK_NamedPropertyLink(sink__V359->context, namedP__V365); UNLINK_VariablePropertyLink(sink__V359->context, varP__V366);
      
      return 1;
    break; } case Data_M__sCons: { /* Function DEFS-Length-2$Length$$Cons case $Cons */
      ASSERT(sink__V359->context, !strcmp(SYMBOL(term__V360),  "Length" ));
      Term sub__V369 = SUB(term__V360, 0); permitUnusedTerm(sub__V369); int sub__V369_count = term__V360_count*LINK_COUNT(sub__V369); permitUnusedInt(sub__V369_count);
      ASSERT(sink__V359->context, !strcmp(SYMBOL(sub__V369),  "$Cons" ));
      Term sub__V370 = LINK(sink__V359->context, SUB(sub__V369, 0)); int sub__V370_count = sub__V369_count*LINK_COUNT(sub__V370); permitUnusedInt(sub__V370_count);
      /* sub__V370 = &#0-0 */
      Term sub__V371 = LINK(sink__V359->context, SUB(sub__V369, 1)); int sub__V371_count = sub__V369_count*LINK_COUNT(sub__V371); permitUnusedInt(sub__V371_count);
      /* sub__V371 = &#0-1 */
      Term sub__V372 = LINK(sink__V359->context, SUB(term__V360, 1)); int sub__V372_count = term__V360_count*LINK_COUNT(sub__V372); permitUnusedInt(sub__V372_count);
      /* sub__V372 = &#2 */
      
      NamedPropertyLink namedP__V373 = LINK_NamedPropertyLink(sink__V359->context, NAMED_PROPERTIES(term__V360));
      VariablePropertyLink varP__V374 = LINK_VariablePropertyLink(sink__V359->context, VARIABLE_PROPERTIES(term__V360));
      Hashset namedFV__V375 = LINK_VARIABLESET(sink__V359->context, namedPropertyFreeVars(namedP__V373));
      Hashset varFV__V376 = LINK_VARIABLESET(sink__V359->context, variablePropertyFreeVars(varP__V374));
      UNLINK(sink__V359->context, term__V360);
      ADD_PROPERTIES(sink__V359, LINK_VARIABLESET(sink__V359->context, namedFV__V375), LINK_VARIABLESET(sink__V359->context, varFV__V376), LINK_NamedPropertyLink(sink__V359->context, namedP__V373), LINK_VariablePropertyLink(sink__V359->context, varP__V374));
      { START(sink__V359, _M_Length_s1);
        COPY(sink__V359, sub__V370);COPY(sink__V359, sub__V371);COPY(sink__V359, sub__V372);END(sink__V359, _M_Length_s1); }
      UNLINK_VARIABLESET(sink__V359->context, namedFV__V375); UNLINK_VARIABLESET(sink__V359->context, varFV__V376);
      UNLINK_NamedPropertyLink(sink__V359->context, namedP__V373); UNLINK_VariablePropertyLink(sink__V359->context, varP__V374);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION Sort-name$1. */
int conBindOffs_M_Sort__name_s1[] = {0 , 0 , 0};
char *nameFun_M_Sort__name_s1(Term term) { return  "Sort-name$1" ; }
struct _ConstructionDescriptor descriptor_M_Sort__name_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_Sort__name_s1), conBindOffs_M_Sort__name_s1, &nameFun_M_Sort__name_s1, &step_M_Sort__name_s1};

int step_M_Sort__name_s1(Sink sink__V377, Term term__V378)
{
  int term__V378_count = LINK_COUNT(term__V378); permitUnusedInt(term__V378_count);
  do {
    /* Contraction rule DEFS-Sort-name-1. */
    ASSERT(sink__V377->context, !strcmp(SYMBOL(term__V378),  "Sort-name$1" ));
    Term sub__V379 = LINK(sink__V377->context, SUB(term__V378, 0)); int sub__V379_count = term__V378_count*LINK_COUNT(sub__V379); permitUnusedInt(sub__V379_count);
    /* sub__V379 = &#11 */
    Term sub__V380 = SUB(term__V378, 1); permitUnusedTerm(sub__V380); int sub__V380_count = term__V378_count*LINK_COUNT(sub__V380); permitUnusedInt(sub__V380_count);
    /* sub__V380 = &#12 */
    
    NamedPropertyLink namedP__V381 = LINK_NamedPropertyLink(sink__V377->context, NAMED_PROPERTIES(term__V378));
    VariablePropertyLink varP__V382 = LINK_VariablePropertyLink(sink__V377->context, VARIABLE_PROPERTIES(term__V378));
    Hashset namedFV__V383 = LINK_VARIABLESET(sink__V377->context, namedPropertyFreeVars(namedP__V381));
    Hashset varFV__V384 = LINK_VARIABLESET(sink__V377->context, variablePropertyFreeVars(varP__V382));
    UNLINK(sink__V377->context, term__V378);
    { START(sink__V377, _M_TOKEN);
      COPY(sink__V377, sub__V379);END(sink__V377, _M_TOKEN); }
    UNLINK_VARIABLESET(sink__V377->context, namedFV__V383); UNLINK_VARIABLESET(sink__V377->context, varFV__V384);
    UNLINK_NamedPropertyLink(sink__V377->context, namedP__V381); UNLINK_VariablePropertyLink(sink__V377->context, varP__V382);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Struct. */
int conBindOffs_M_Struct[] = {0 , 0};
char *nameFun_M_Struct(Term term) { return  "Struct" ; }
struct _ConstructionDescriptor descriptor_M_Struct = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_Struct), conBindOffs_M_Struct, &nameFun_M_Struct, &step_M_Struct};

int step_M_Struct(Sink sink__V385, Term term__V386)
{
  int term__V386_count = LINK_COUNT(term__V386); permitUnusedInt(term__V386_count);
  do {
    /* Contraction rule DEFS-Struct-1. */
    ASSERT(sink__V385->context, !strcmp(SYMBOL(term__V386),  "Struct" ));
    Term sub__V387 = LINK(sink__V385->context, SUB(term__V386, 0)); int sub__V387_count = term__V386_count*LINK_COUNT(sub__V387); permitUnusedInt(sub__V387_count);
    /* sub__V387 = &#1 */
    
    NamedPropertyLink namedP__V388 = LINK_NamedPropertyLink(sink__V385->context, NAMED_PROPERTIES(term__V386));
    VariablePropertyLink varP__V389 = LINK_VariablePropertyLink(sink__V385->context, VARIABLE_PROPERTIES(term__V386));
    Hashset namedFV__V390 = LINK_VARIABLESET(sink__V385->context, namedPropertyFreeVars(namedP__V388));
    Hashset varFV__V391 = LINK_VARIABLESET(sink__V385->context, variablePropertyFreeVars(varP__V389));
    UNLINK(sink__V385->context, term__V386);
    { START(sink__V385, _M__sTextCons);
      { START(sink__V385, _M__sTextChars);
        LITERAL(sink__V385,  "_Con" ); END(sink__V385, _M__sTextChars); }
      { START(sink__V385, _M__sTextCons);
        { START(sink__V385, _M__sTextEmbed);
          { START(sink__V385, _M_AsText);
            { START(sink__V385, _M_MANGLE);
              COPY(sink__V385, sub__V387);END(sink__V385, _M_MANGLE); }
            END(sink__V385, _M_AsText); }
          END(sink__V385, _M__sTextEmbed); }
        { START(sink__V385, _M__sTextNil);
          END(sink__V385, _M__sTextNil); }
        END(sink__V385, _M__sTextCons); }
      END(sink__V385, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V385->context, namedFV__V390); UNLINK_VARIABLESET(sink__V385->context, varFV__V391);
    UNLINK_NamedPropertyLink(sink__V385->context, namedP__V388); UNLINK_VariablePropertyLink(sink__V385->context, varP__V389);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION UnString. */
int conBindOffs_M_UnString[] = {0 , 0};
char *nameFun_M_UnString(Term term) { return  "UnString" ; }
struct _ConstructionDescriptor descriptor_M_UnString = {NULL, 0, 1, sizeof(STRUCT_Con_M_UnString), conBindOffs_M_UnString, &nameFun_M_UnString, &step_M_UnString};

int step_M_UnString(Sink sink__V392, Term term__V393)
{
  int term__V393_count = LINK_COUNT(term__V393); permitUnusedInt(term__V393_count);
  Term sub__V394 = FORCE(sink__V392->context, SUB(term__V393, 0));
  EnumOf_M_STRING_xENTRY choice__V395 = (IS_VARIABLE_USE(sub__V394) ? VarOf_M_STRING_xENTRY : (EnumOf_M_STRING_xENTRY) TAG(sub__V394));
  switch (choice__V395)
  {
    case Data_M_STRING_xVALUE: { /* Function DEFS-UnString-1$UnString$STRING_VALUE case STRING_VALUE */
      ASSERT(sink__V392->context, !strcmp(SYMBOL(term__V393),  "UnString" ));
      Term sub__V396 = SUB(term__V393, 0); permitUnusedTerm(sub__V396); int sub__V396_count = term__V393_count*LINK_COUNT(sub__V396); permitUnusedInt(sub__V396_count);
      CRSX_CHECK_SORT(sink__V392->context, sub__V396, &sort_M_STRING_xENTRY); ASSERT(sink__V392->context, !strcmp(SYMBOL(sub__V396),  "STRING_VALUE" ));
      Term sub__V397 = LINK(sink__V392->context, SUB(sub__V396, 0)); int sub__V397_count = sub__V396_count*LINK_COUNT(sub__V397); permitUnusedInt(sub__V397_count);
      /* sub__V397 = &#0-0 */
      
      NamedPropertyLink namedP__V398 = LINK_NamedPropertyLink(sink__V392->context, NAMED_PROPERTIES(term__V393));
      VariablePropertyLink varP__V399 = LINK_VariablePropertyLink(sink__V392->context, VARIABLE_PROPERTIES(term__V393));
      Hashset namedFV__V400 = LINK_VARIABLESET(sink__V392->context, namedPropertyFreeVars(namedP__V398));
      Hashset varFV__V401 = LINK_VARIABLESET(sink__V392->context, variablePropertyFreeVars(varP__V399));
      UNLINK(sink__V392->context, term__V393);
      ADD_PROPERTIES(sink__V392, LINK_VARIABLESET(sink__V392->context, namedFV__V400), LINK_VARIABLESET(sink__V392->context, varFV__V401), LINK_NamedPropertyLink(sink__V392->context, namedP__V398), LINK_VariablePropertyLink(sink__V392->context, varP__V399));
      { START(sink__V392, _M_UnString_s1);
        COPY(sink__V392, sub__V397);END(sink__V392, _M_UnString_s1); }
      UNLINK_VARIABLESET(sink__V392->context, namedFV__V400); UNLINK_VARIABLESET(sink__V392->context, varFV__V401);
      UNLINK_NamedPropertyLink(sink__V392->context, namedP__V398); UNLINK_VariablePropertyLink(sink__V392->context, varP__V399);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION UnVariable. */
int conBindOffs_M_UnVariable[] = {0 , 0};
char *nameFun_M_UnVariable(Term term) { return  "UnVariable" ; }
struct _ConstructionDescriptor descriptor_M_UnVariable = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_UnVariable), conBindOffs_M_UnVariable, &nameFun_M_UnVariable, &step_M_UnVariable};

int step_M_UnVariable(Sink sink__V402, Term term__V403)
{
  int term__V403_count = LINK_COUNT(term__V403); permitUnusedInt(term__V403_count);
  Term sub__V404 = FORCE(sink__V402->context, SUB(term__V403, 0));
  EnumOf_M_STRING_xENTRY choice__V405 = (IS_VARIABLE_USE(sub__V404) ? VarOf_M_STRING_xENTRY : (EnumOf_M_STRING_xENTRY) TAG(sub__V404));
  switch (choice__V405)
  {
    case Data_M_VARIABLE: { /* Function DEFS-UnVariable-1$UnVariable$VARIABLE case VARIABLE */
      ASSERT(sink__V402->context, !strcmp(SYMBOL(term__V403),  "UnVariable" ));
      Term sub__V406 = SUB(term__V403, 0); permitUnusedTerm(sub__V406); int sub__V406_count = term__V403_count*LINK_COUNT(sub__V406); permitUnusedInt(sub__V406_count);
      CRSX_CHECK_SORT(sink__V402->context, sub__V406, &sort_M_STRING_xENTRY); ASSERT(sink__V402->context, !strcmp(SYMBOL(sub__V406),  "VARIABLE" ));
      Term sub__V407 = LINK(sink__V402->context, SUB(sub__V406, 0)); int sub__V407_count = sub__V406_count*LINK_COUNT(sub__V407); permitUnusedInt(sub__V407_count);
      CRSX_CHECK_SORT(sink__V402->context, sub__V407, &sort_M_Reified_xVariable); /* sub__V407 = &#0-0 */
      
      NamedPropertyLink namedP__V408 = LINK_NamedPropertyLink(sink__V402->context, NAMED_PROPERTIES(term__V403));
      VariablePropertyLink varP__V409 = LINK_VariablePropertyLink(sink__V402->context, VARIABLE_PROPERTIES(term__V403));
      Hashset namedFV__V410 = LINK_VARIABLESET(sink__V402->context, namedPropertyFreeVars(namedP__V408));
      Hashset varFV__V411 = LINK_VARIABLESET(sink__V402->context, variablePropertyFreeVars(varP__V409));
      UNLINK(sink__V402->context, term__V403);
      ADD_PROPERTIES(sink__V402, LINK_VARIABLESET(sink__V402->context, namedFV__V410), LINK_VARIABLESET(sink__V402->context, varFV__V411), LINK_NamedPropertyLink(sink__V402->context, namedP__V408), LINK_VariablePropertyLink(sink__V402->context, varP__V409));
      { START(sink__V402, _M_UnVariable_s1);
        COPY(sink__V402, sub__V407);END(sink__V402, _M_UnVariable_s1); }
      UNLINK_VARIABLESET(sink__V402->context, namedFV__V410); UNLINK_VARIABLESET(sink__V402->context, varFV__V411);
      UNLINK_NamedPropertyLink(sink__V402->context, namedP__V408); UNLINK_VariablePropertyLink(sink__V402->context, varP__V409);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION DINTEGER. */
int conBindOffs_M_DINTEGER[] = {0 , 0 , 0};
char *nameFun_M_DINTEGER(Term term) { return  "DINTEGER" ; }
struct _ConstructionDescriptor descriptor_M_DINTEGER = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_DINTEGER), conBindOffs_M_DINTEGER, &nameFun_M_DINTEGER, &step_M_DINTEGER};

int step_M_DINTEGER(Sink sink__V412, Term term__V413)
{
  int term__V413_count = LINK_COUNT(term__V413); permitUnusedInt(term__V413_count);
  Term sub__V414 = FORCE(sink__V412->context, SUB(term__V413, 0));
  EnumOf_M_OK_xSORT choice__V415 = (IS_VARIABLE_USE(sub__V414) ? VarOf_M_OK_xSORT : (EnumOf_M_OK_xSORT) TAG(sub__V414));
  switch (choice__V415)
  {
    case Data_M_OK: { /* Function DEFS-DINTEGER-1$DINTEGER$OK case OK */
      ASSERT(sink__V412->context, !strcmp(SYMBOL(term__V413),  "DINTEGER" ));
      Term sub__V416 = SUB(term__V413, 0); permitUnusedTerm(sub__V416); int sub__V416_count = term__V413_count*LINK_COUNT(sub__V416); permitUnusedInt(sub__V416_count);
      CRSX_CHECK_SORT(sink__V412->context, sub__V416, &sort_M_OK_xSORT); ASSERT(sink__V412->context, !strcmp(SYMBOL(sub__V416),  "OK" ));
      Term sub__V417 = LINK(sink__V412->context, SUB(term__V413, 1)); int sub__V417_count = term__V413_count*LINK_COUNT(sub__V417); permitUnusedInt(sub__V417_count);
      /* sub__V417 = &#0 */
      
      NamedPropertyLink namedP__V418 = LINK_NamedPropertyLink(sink__V412->context, NAMED_PROPERTIES(term__V413));
      VariablePropertyLink varP__V419 = LINK_VariablePropertyLink(sink__V412->context, VARIABLE_PROPERTIES(term__V413));
      Hashset namedFV__V420 = LINK_VARIABLESET(sink__V412->context, namedPropertyFreeVars(namedP__V418));
      Hashset varFV__V421 = LINK_VARIABLESET(sink__V412->context, variablePropertyFreeVars(varP__V419));
      UNLINK(sink__V412->context, term__V413);
      ADD_PROPERTIES(sink__V412, LINK_VARIABLESET(sink__V412->context, namedFV__V420), LINK_VARIABLESET(sink__V412->context, varFV__V421), LINK_NamedPropertyLink(sink__V412->context, namedP__V418), LINK_VariablePropertyLink(sink__V412->context, varP__V419));
      { START(sink__V412, _M_DINTEGER_s1);
        COPY(sink__V412, sub__V417);END(sink__V412, _M_DINTEGER_s1); }
      UNLINK_VARIABLESET(sink__V412->context, namedFV__V420); UNLINK_VARIABLESET(sink__V412->context, varFV__V421);
      UNLINK_NamedPropertyLink(sink__V412->context, namedP__V418); UNLINK_VariablePropertyLink(sink__V412->context, varP__V419);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION MANGLE. */
int conBindOffs_M_MANGLE[] = {0 , 0};
char *nameFun_M_MANGLE(Term term) { return  "MANGLE" ; }
struct _ConstructionDescriptor descriptor_M_MANGLE = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_MANGLE), conBindOffs_M_MANGLE, &nameFun_M_MANGLE, &step_M_MANGLE};

int step_M_MANGLE(Sink sink__V422, Term term__V423)
{
  int term__V423_count = LINK_COUNT(term__V423); permitUnusedInt(term__V423_count);
  do {
    /* Contraction rule DEFS-MANGLE-1. */
    ASSERT(sink__V422->context, !strcmp(SYMBOL(term__V423),  "MANGLE" ));
    Term sub__V424 = LINK(sink__V422->context, SUB(term__V423, 0)); int sub__V424_count = term__V423_count*LINK_COUNT(sub__V424); permitUnusedInt(sub__V424_count);
    UNLINK_SUB(sink__V422->context, term__V423,  0); NORMALIZE(sink__V422->context, sub__V424); SUB(term__V423,  0) = LINK(sink__V422->context, sub__V424);
    /* sub__V424 = &#1 */
    
    NamedPropertyLink namedP__V425 = LINK_NamedPropertyLink(sink__V422->context, NAMED_PROPERTIES(term__V423));
    VariablePropertyLink varP__V426 = LINK_VariablePropertyLink(sink__V422->context, VARIABLE_PROPERTIES(term__V423));
    Hashset namedFV__V427 = LINK_VARIABLESET(sink__V422->context, namedPropertyFreeVars(namedP__V425));
    Hashset varFV__V428 = LINK_VARIABLESET(sink__V422->context, variablePropertyFreeVars(varP__V426));
    UNLINK(sink__V422->context, term__V423);
    { START(sink__V422, _M__sTextCons);
      { START(sink__V422, _M__sTextChars);
        { char *str__V429;
          FORCE(sink__V422->context, sub__V424);
          { char *s__V430 = makeMangled(sink__V422->context, SYMBOL(sub__V424));
            { size_t z__V431 = strlen(s__V430) + 1; memcpy(str__V429 = ALLOCATE(sink__V422->context, z__V431), s__V430, z__V431);  UNLINK(sink__V422->context, sub__V424);}
            }
          LITERALU(sink__V422, str__V429); }
        END(sink__V422, _M__sTextChars); }
      { START(sink__V422, _M__sTextNil);
        END(sink__V422, _M__sTextNil); }
      END(sink__V422, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V422->context, namedFV__V427); UNLINK_VARIABLESET(sink__V422->context, varFV__V428);
    UNLINK_NamedPropertyLink(sink__V422->context, namedP__V425); UNLINK_VariablePropertyLink(sink__V422->context, varP__V426);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Enum. */
int conBindOffs_M_Enum[] = {0 , 0};
char *nameFun_M_Enum(Term term) { return  "Enum" ; }
struct _ConstructionDescriptor descriptor_M_Enum = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_Enum), conBindOffs_M_Enum, &nameFun_M_Enum, &step_M_Enum};

int step_M_Enum(Sink sink__V432, Term term__V433)
{
  int term__V433_count = LINK_COUNT(term__V433); permitUnusedInt(term__V433_count);
  do {
    /* Contraction rule DEFS-Enum-1. */
    ASSERT(sink__V432->context, !strcmp(SYMBOL(term__V433),  "Enum" ));
    Term sub__V434 = LINK(sink__V432->context, SUB(term__V433, 0)); int sub__V434_count = term__V433_count*LINK_COUNT(sub__V434); permitUnusedInt(sub__V434_count);
    /* sub__V434 = &#1 */
    
    NamedPropertyLink namedP__V435 = LINK_NamedPropertyLink(sink__V432->context, NAMED_PROPERTIES(term__V433));
    VariablePropertyLink varP__V436 = LINK_VariablePropertyLink(sink__V432->context, VARIABLE_PROPERTIES(term__V433));
    Hashset namedFV__V437 = LINK_VARIABLESET(sink__V432->context, namedPropertyFreeVars(namedP__V435));
    Hashset varFV__V438 = LINK_VARIABLESET(sink__V432->context, variablePropertyFreeVars(varP__V436));
    UNLINK(sink__V432->context, term__V433);
    { START(sink__V432, _M__sTextCons);
      { START(sink__V432, _M__sTextChars);
        LITERAL(sink__V432,  "EnumOf" ); END(sink__V432, _M__sTextChars); }
      { START(sink__V432, _M__sTextCons);
        { START(sink__V432, _M__sTextEmbed);
          { START(sink__V432, _M_AsText);
            { START(sink__V432, _M_MANGLE);
              COPY(sink__V432, sub__V434);END(sink__V432, _M_MANGLE); }
            END(sink__V432, _M_AsText); }
          END(sink__V432, _M__sTextEmbed); }
        { START(sink__V432, _M__sTextNil);
          END(sink__V432, _M__sTextNil); }
        END(sink__V432, _M__sTextCons); }
      END(sink__V432, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V432->context, namedFV__V437); UNLINK_VARIABLESET(sink__V432->context, varFV__V438);
    UNLINK_NamedPropertyLink(sink__V432->context, namedP__V435); UNLINK_VariablePropertyLink(sink__V432->context, varP__V436);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Sort-name. */
int conBindOffs_M_Sort__name[] = {0 , 0};
char *nameFun_M_Sort__name(Term term) { return  "Sort-name" ; }
struct _ConstructionDescriptor descriptor_M_Sort__name = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_Sort__name), conBindOffs_M_Sort__name, &nameFun_M_Sort__name, &step_M_Sort__name};

int step_M_Sort__name(Sink sink__V439, Term term__V440)
{
  int term__V440_count = LINK_COUNT(term__V440); permitUnusedInt(term__V440_count);
  Term sub__V441 = FORCE(sink__V439->context, SUB(term__V440, 0));
  EnumOf_M_Reified_xSort choice__V442 = (IS_VARIABLE_USE(sub__V441) ? VarOf_M_Reified_xSort : (EnumOf_M_Reified_xSort) TAG(sub__V441));
  switch (choice__V442)
  {
    case Data_M_SORT: { /* Function DEFS-Sort-name-1$Sort-name$SORT case SORT */
      ASSERT(sink__V439->context, !strcmp(SYMBOL(term__V440),  "Sort-name" ));
      Term sub__V443 = SUB(term__V440, 0); permitUnusedTerm(sub__V443); int sub__V443_count = term__V440_count*LINK_COUNT(sub__V443); permitUnusedInt(sub__V443_count);
      CRSX_CHECK_SORT(sink__V439->context, sub__V443, &sort_M_Reified_xSort); ASSERT(sink__V439->context, !strcmp(SYMBOL(sub__V443),  "SORT" ));
      Term sub__V444 = LINK(sink__V439->context, SUB(sub__V443, 0)); int sub__V444_count = sub__V443_count*LINK_COUNT(sub__V444); permitUnusedInt(sub__V444_count);
      /* sub__V444 = &#0-0 */
      Term sub__V445 = LINK(sink__V439->context, SUB(sub__V443, 1)); int sub__V445_count = sub__V443_count*LINK_COUNT(sub__V445); permitUnusedInt(sub__V445_count);
      /* sub__V445 = &#0-1 */
      
      NamedPropertyLink namedP__V446 = LINK_NamedPropertyLink(sink__V439->context, NAMED_PROPERTIES(term__V440));
      VariablePropertyLink varP__V447 = LINK_VariablePropertyLink(sink__V439->context, VARIABLE_PROPERTIES(term__V440));
      Hashset namedFV__V448 = LINK_VARIABLESET(sink__V439->context, namedPropertyFreeVars(namedP__V446));
      Hashset varFV__V449 = LINK_VARIABLESET(sink__V439->context, variablePropertyFreeVars(varP__V447));
      UNLINK(sink__V439->context, term__V440);
      ADD_PROPERTIES(sink__V439, LINK_VARIABLESET(sink__V439->context, namedFV__V448), LINK_VARIABLESET(sink__V439->context, varFV__V449), LINK_NamedPropertyLink(sink__V439->context, namedP__V446), LINK_VariablePropertyLink(sink__V439->context, varP__V447));
      { START(sink__V439, _M_Sort__name_s1);
        COPY(sink__V439, sub__V444);COPY(sink__V439, sub__V445);END(sink__V439, _M_Sort__name_s1); }
      UNLINK_VARIABLESET(sink__V439->context, namedFV__V448); UNLINK_VARIABLESET(sink__V439->context, varFV__V449);
      UNLINK_NamedPropertyLink(sink__V439->context, namedP__V446); UNLINK_VariablePropertyLink(sink__V439->context, varP__V447);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION If. */
int conBindOffs_M_If[] = {0 , 0 , 0 , 0};
char *nameFun_M_If(Term term) { return  "If" ; }
struct _ConstructionDescriptor descriptor_M_If = {NULL, 0, 3, sizeof(STRUCT_Con_M_If), conBindOffs_M_If, &nameFun_M_If, &step_M_If};

int step_M_If(Sink sink__V450, Term term__V451)
{
  int term__V451_count = LINK_COUNT(term__V451); permitUnusedInt(term__V451_count);
  Term sub__V452 = FORCE(sink__V450->context, SUB(term__V451, 0));
  EnumOf_M__sBoolean choice__V453 = (IS_VARIABLE_USE(sub__V452) ? VarOf_M__sBoolean : (EnumOf_M__sBoolean) TAG(sub__V452));
  switch (choice__V453)
  {
    case Data_M__sTrue: { /* Function DEFS-If-1$If$$True case $True */
      ASSERT(sink__V450->context, !strcmp(SYMBOL(term__V451),  "If" ));
      Term sub__V454 = SUB(term__V451, 0); permitUnusedTerm(sub__V454); int sub__V454_count = term__V451_count*LINK_COUNT(sub__V454); permitUnusedInt(sub__V454_count);
      ASSERT(sink__V450->context, !strcmp(SYMBOL(sub__V454),  "$True" ));
      Term sub__V455 = LINK(sink__V450->context, SUB(term__V451, 1)); int sub__V455_count = term__V451_count*LINK_COUNT(sub__V455); permitUnusedInt(sub__V455_count);
      /* sub__V455 = &#0 */
      Term sub__V456 = LINK(sink__V450->context, SUB(term__V451, 2)); int sub__V456_count = term__V451_count*LINK_COUNT(sub__V456); permitUnusedInt(sub__V456_count);
      /* sub__V456 = &#1 */
      
      NamedPropertyLink namedP__V457 = LINK_NamedPropertyLink(sink__V450->context, NAMED_PROPERTIES(term__V451));
      VariablePropertyLink varP__V458 = LINK_VariablePropertyLink(sink__V450->context, VARIABLE_PROPERTIES(term__V451));
      Hashset namedFV__V459 = LINK_VARIABLESET(sink__V450->context, namedPropertyFreeVars(namedP__V457));
      Hashset varFV__V460 = LINK_VARIABLESET(sink__V450->context, variablePropertyFreeVars(varP__V458));
      UNLINK(sink__V450->context, term__V451);
      ADD_PROPERTIES(sink__V450, LINK_VARIABLESET(sink__V450->context, namedFV__V459), LINK_VARIABLESET(sink__V450->context, varFV__V460), LINK_NamedPropertyLink(sink__V450->context, namedP__V457), LINK_VariablePropertyLink(sink__V450->context, varP__V458));
      { START(sink__V450, _M_If_s2);
        COPY(sink__V450, sub__V455);COPY(sink__V450, sub__V456);END(sink__V450, _M_If_s2); }
      UNLINK_VARIABLESET(sink__V450->context, namedFV__V459); UNLINK_VARIABLESET(sink__V450->context, varFV__V460);
      UNLINK_NamedPropertyLink(sink__V450->context, namedP__V457); UNLINK_VariablePropertyLink(sink__V450->context, varP__V458);
      
      return 1;
    break; } case Data_M__sFalse: { /* Function DEFS-If-2$If$$False case $False */
      ASSERT(sink__V450->context, !strcmp(SYMBOL(term__V451),  "If" ));
      Term sub__V461 = SUB(term__V451, 0); permitUnusedTerm(sub__V461); int sub__V461_count = term__V451_count*LINK_COUNT(sub__V461); permitUnusedInt(sub__V461_count);
      ASSERT(sink__V450->context, !strcmp(SYMBOL(sub__V461),  "$False" ));
      Term sub__V462 = LINK(sink__V450->context, SUB(term__V451, 1)); int sub__V462_count = term__V451_count*LINK_COUNT(sub__V462); permitUnusedInt(sub__V462_count);
      /* sub__V462 = &#0 */
      Term sub__V463 = LINK(sink__V450->context, SUB(term__V451, 2)); int sub__V463_count = term__V451_count*LINK_COUNT(sub__V463); permitUnusedInt(sub__V463_count);
      /* sub__V463 = &#1 */
      
      NamedPropertyLink namedP__V464 = LINK_NamedPropertyLink(sink__V450->context, NAMED_PROPERTIES(term__V451));
      VariablePropertyLink varP__V465 = LINK_VariablePropertyLink(sink__V450->context, VARIABLE_PROPERTIES(term__V451));
      Hashset namedFV__V466 = LINK_VARIABLESET(sink__V450->context, namedPropertyFreeVars(namedP__V464));
      Hashset varFV__V467 = LINK_VARIABLESET(sink__V450->context, variablePropertyFreeVars(varP__V465));
      UNLINK(sink__V450->context, term__V451);
      ADD_PROPERTIES(sink__V450, LINK_VARIABLESET(sink__V450->context, namedFV__V466), LINK_VARIABLESET(sink__V450->context, varFV__V467), LINK_NamedPropertyLink(sink__V450->context, namedP__V464), LINK_VariablePropertyLink(sink__V450->context, varP__V465));
      { START(sink__V450, _M_If_s1);
        COPY(sink__V450, sub__V462);COPY(sink__V450, sub__V463);END(sink__V450, _M_If_s1); }
      UNLINK_VARIABLESET(sink__V450->context, namedFV__V466); UNLINK_VARIABLESET(sink__V450->context, varFV__V467);
      UNLINK_NamedPropertyLink(sink__V450->context, namedP__V464); UNLINK_VariablePropertyLink(sink__V450->context, varP__V465);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION Sort. */
int conBindOffs_M_Sort[] = {0 , 0};
char *nameFun_M_Sort(Term term) { return  "Sort" ; }
struct _ConstructionDescriptor descriptor_M_Sort = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_Sort), conBindOffs_M_Sort, &nameFun_M_Sort, &step_M_Sort};

int step_M_Sort(Sink sink__V468, Term term__V469)
{
  int term__V469_count = LINK_COUNT(term__V469); permitUnusedInt(term__V469_count);
  do {
    /* Contraction rule DEFS-Sort-1. */
    ASSERT(sink__V468->context, !strcmp(SYMBOL(term__V469),  "Sort" ));
    Term sub__V470 = LINK(sink__V468->context, SUB(term__V469, 0)); int sub__V470_count = term__V469_count*LINK_COUNT(sub__V470); permitUnusedInt(sub__V470_count);
    /* sub__V470 = &#1 */
    
    NamedPropertyLink namedP__V471 = LINK_NamedPropertyLink(sink__V468->context, NAMED_PROPERTIES(term__V469));
    VariablePropertyLink varP__V472 = LINK_VariablePropertyLink(sink__V468->context, VARIABLE_PROPERTIES(term__V469));
    Hashset namedFV__V473 = LINK_VARIABLESET(sink__V468->context, namedPropertyFreeVars(namedP__V471));
    Hashset varFV__V474 = LINK_VARIABLESET(sink__V468->context, variablePropertyFreeVars(varP__V472));
    UNLINK(sink__V468->context, term__V469);
    { START(sink__V468, _M__sTextCons);
      { START(sink__V468, _M__sTextChars);
        LITERAL(sink__V468,  "sort" ); END(sink__V468, _M__sTextChars); }
      { START(sink__V468, _M__sTextCons);
        { START(sink__V468, _M__sTextEmbed);
          { START(sink__V468, _M_AsText);
            { START(sink__V468, _M_MANGLE);
              COPY(sink__V468, sub__V470);END(sink__V468, _M_MANGLE); }
            END(sink__V468, _M_AsText); }
          END(sink__V468, _M__sTextEmbed); }
        { START(sink__V468, _M__sTextNil);
          END(sink__V468, _M__sTextNil); }
        END(sink__V468, _M__sTextCons); }
      END(sink__V468, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V468->context, namedFV__V473); UNLINK_VARIABLESET(sink__V468->context, varFV__V474);
    UNLINK_NamedPropertyLink(sink__V468->context, namedP__V471); UNLINK_VariablePropertyLink(sink__V468->context, varP__V472);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DEnumTag. */
int conBindOffs_M_DEnumTag[] = {0 , 0 , 0};
char *nameFun_M_DEnumTag(Term term) { return  "DEnumTag" ; }
struct _ConstructionDescriptor descriptor_M_DEnumTag = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_DEnumTag), conBindOffs_M_DEnumTag, &nameFun_M_DEnumTag, &step_M_DEnumTag};

int step_M_DEnumTag(Sink sink__V475, Term term__V476)
{
  int term__V476_count = LINK_COUNT(term__V476); permitUnusedInt(term__V476_count);
  Term sub__V477 = FORCE(sink__V475->context, SUB(term__V476, 0));
  EnumOf_M_OK_xSORT choice__V478 = (IS_VARIABLE_USE(sub__V477) ? VarOf_M_OK_xSORT : (EnumOf_M_OK_xSORT) TAG(sub__V477));
  switch (choice__V478)
  {
    case Data_M_OK: { /* Function DEFS-DEnumTag-1$DEnumTag$OK case OK */
      ASSERT(sink__V475->context, !strcmp(SYMBOL(term__V476),  "DEnumTag" ));
      Term sub__V479 = SUB(term__V476, 0); permitUnusedTerm(sub__V479); int sub__V479_count = term__V476_count*LINK_COUNT(sub__V479); permitUnusedInt(sub__V479_count);
      CRSX_CHECK_SORT(sink__V475->context, sub__V479, &sort_M_OK_xSORT); ASSERT(sink__V475->context, !strcmp(SYMBOL(sub__V479),  "OK" ));
      Term sub__V480 = LINK(sink__V475->context, SUB(term__V476, 1)); int sub__V480_count = term__V476_count*LINK_COUNT(sub__V480); permitUnusedInt(sub__V480_count);
      /* sub__V480 = &#0 */
      
      NamedPropertyLink namedP__V481 = LINK_NamedPropertyLink(sink__V475->context, NAMED_PROPERTIES(term__V476));
      VariablePropertyLink varP__V482 = LINK_VariablePropertyLink(sink__V475->context, VARIABLE_PROPERTIES(term__V476));
      Hashset namedFV__V483 = LINK_VARIABLESET(sink__V475->context, namedPropertyFreeVars(namedP__V481));
      Hashset varFV__V484 = LINK_VARIABLESET(sink__V475->context, variablePropertyFreeVars(varP__V482));
      UNLINK(sink__V475->context, term__V476);
      ADD_PROPERTIES(sink__V475, LINK_VARIABLESET(sink__V475->context, namedFV__V483), LINK_VARIABLESET(sink__V475->context, varFV__V484), LINK_NamedPropertyLink(sink__V475->context, namedP__V481), LINK_VariablePropertyLink(sink__V475->context, varP__V482));
      { START(sink__V475, _M_DEnumTag_s1);
        COPY(sink__V475, sub__V480);END(sink__V475, _M_DEnumTag_s1); }
      UNLINK_VARIABLESET(sink__V475->context, namedFV__V483); UNLINK_VARIABLESET(sink__V475->context, varFV__V484);
      UNLINK_NamedPropertyLink(sink__V475->context, namedP__V481); UNLINK_VariablePropertyLink(sink__V475->context, varP__V482);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION FormArguments-binder-offsets$1. */
int conBindOffs_M_FormArguments__binder__offsets_s1[] = {0 , 0 , 0 , 0};
char *nameFun_M_FormArguments__binder__offsets_s1(Term term) { return  "FormArguments-binder-offsets$1" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__offsets_s1 = {NULL, 0, 3, sizeof(STRUCT_Con_M_FormArguments__binder__offsets_s1), conBindOffs_M_FormArguments__binder__offsets_s1, &nameFun_M_FormArguments__binder__offsets_s1, &step_M_FormArguments__binder__offsets_s1};

int step_M_FormArguments__binder__offsets_s1(Sink sink__V485, Term term__V486)
{
  int term__V486_count = LINK_COUNT(term__V486); permitUnusedInt(term__V486_count);
  do {
    /* Contraction rule DEFS-FormArguments-binder-offsets-1$FormArguments-binder-offsets$1$FORM-BINDER. */
    ASSERT(sink__V485->context, !strcmp(SYMBOL(term__V486),  "FormArguments-binder-offsets$1" ));
    Term sub__V487 = SUB(term__V486, 0); permitUnusedTerm(sub__V487); int sub__V487_count = term__V486_count*LINK_COUNT(sub__V487); permitUnusedInt(sub__V487_count);
    FORCE(sink__V485->context, sub__V487); SUB(term__V486, 0) = sub__V487;
    if (strcmp(SYMBOL(sub__V487),  "FORM-BINDER" )) break;
    Term sub__V488 = LINK(sink__V485->context, SUB(sub__V487, 0)); int sub__V488_count = sub__V487_count*LINK_COUNT(sub__V488); permitUnusedInt(sub__V488_count);
    CRSX_CHECK_SORT(sink__V485->context, sub__V488, &sort_M_Reified_xSort); /* sub__V488 = &#0-0 */
    Variable y__V489 = BINDER(sub__V487,1,0); if (sub__V487_count <= 1) UNBIND(y__V489);
    Term sub__V490 = LINK(sink__V485->context, SUB(sub__V487, 1)); int sub__V490_count = sub__V487_count*LINK_COUNT(sub__V490); permitUnusedInt(sub__V490_count);
    CRSX_CHECK_SORT(sink__V485->context, sub__V490, &sort_M_Reified_xFormArgument); /* sub__V490 = &#0-1 */
    Term sub__V491 = LINK(sink__V485->context, SUB(term__V486, 1)); int sub__V491_count = term__V486_count*LINK_COUNT(sub__V491); permitUnusedInt(sub__V491_count);
    /* sub__V491 = &#2 */
    Term sub__V492 = LINK(sink__V485->context, SUB(term__V486, 2)); int sub__V492_count = term__V486_count*LINK_COUNT(sub__V492); permitUnusedInt(sub__V492_count);
    /* sub__V492 = &#3 */
    
    NamedPropertyLink namedP__V493 = LINK_NamedPropertyLink(sink__V485->context, NAMED_PROPERTIES(term__V486));
    VariablePropertyLink varP__V494 = LINK_VariablePropertyLink(sink__V485->context, VARIABLE_PROPERTIES(term__V486));
    Hashset namedFV__V495 = LINK_VARIABLESET(sink__V485->context, namedPropertyFreeVars(namedP__V493));
    Hashset varFV__V496 = LINK_VARIABLESET(sink__V485->context, variablePropertyFreeVars(varP__V494));
    UNLINK(sink__V485->context, term__V486);
    ADD_PROPERTIES(sink__V485, LINK_VARIABLESET(sink__V485->context, namedFV__V495), LINK_VARIABLESET(sink__V485->context, varFV__V496), LINK_NamedPropertyLink(sink__V485->context, namedP__V493), LINK_VariablePropertyLink(sink__V485->context, varP__V494));
    { START(sink__V485, _M_FormArguments__binder__offsets_s3);
      COPY(sink__V485, sub__V488);{ if (!IS_BOUND(y__V489)) { REBIND(y__V489);
          Variable binds__V497[1] = {y__V489}; BINDS(sink__V485, 1, binds__V497);
          COPY(sink__V485, sub__V490); /* REUSED SUBSTITUTION */  }
        else { Variable b__V498 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V485->context,"b__V498");
          Variable binds__V499[1] = {b__V498}; BINDS(sink__V485, 1, binds__V499);
          {
            Term arg__V500;
            { Sink buf__V501 = ALLOCA_BUFFER(sink__V485->context);
              USE(buf__V501, b__V498); arg__V500 = BUFFER_TERM(buf__V501); FREE_BUFFER(buf__V501); }
            Variable vars__V502[1] = {y__V489};
            Term args__V503[1] = {arg__V500};
            struct _SubstitutionFrame substitution__V504 = {NULL, 0, 1, vars__V502, args__V503, NULL};
            SUBSTITUTE(sink__V485, sub__V490, &substitution__V504); }
              }
         }
      COPY(sink__V485, sub__V491);COPY(sink__V485, sub__V492);END(sink__V485, _M_FormArguments__binder__offsets_s3); }
    UNLINK_VARIABLESET(sink__V485->context, namedFV__V495); UNLINK_VARIABLESET(sink__V485->context, varFV__V496);
    UNLINK_NamedPropertyLink(sink__V485->context, namedP__V493); UNLINK_VariablePropertyLink(sink__V485->context, varP__V494);
    
    return 1;
  } while (0);
  do {
    /* Contraction rule DEFS-FormArguments-binder-offsets-2$FormArguments-binder-offsets$1$FORM-ARGUMENT. */
    ASSERT(sink__V485->context, !strcmp(SYMBOL(term__V486),  "FormArguments-binder-offsets$1" ));
    Term sub__V505 = SUB(term__V486, 0); permitUnusedTerm(sub__V505); int sub__V505_count = term__V486_count*LINK_COUNT(sub__V505); permitUnusedInt(sub__V505_count);
    FORCE(sink__V485->context, sub__V505); SUB(term__V486, 0) = sub__V505;
    if (strcmp(SYMBOL(sub__V505),  "FORM-ARGUMENT" )) break;
    Term sub__V506 = LINK(sink__V485->context, SUB(sub__V505, 0)); int sub__V506_count = sub__V505_count*LINK_COUNT(sub__V506); permitUnusedInt(sub__V506_count);
    CRSX_CHECK_SORT(sink__V485->context, sub__V506, &sort_M_Reified_xSort); /* sub__V506 = &#0-0 */
    Term sub__V507 = LINK(sink__V485->context, SUB(term__V486, 1)); int sub__V507_count = term__V486_count*LINK_COUNT(sub__V507); permitUnusedInt(sub__V507_count);
    /* sub__V507 = &#1 */
    Term sub__V508 = LINK(sink__V485->context, SUB(term__V486, 2)); int sub__V508_count = term__V486_count*LINK_COUNT(sub__V508); permitUnusedInt(sub__V508_count);
    /* sub__V508 = &#2 */
    
    NamedPropertyLink namedP__V509 = LINK_NamedPropertyLink(sink__V485->context, NAMED_PROPERTIES(term__V486));
    VariablePropertyLink varP__V510 = LINK_VariablePropertyLink(sink__V485->context, VARIABLE_PROPERTIES(term__V486));
    Hashset namedFV__V511 = LINK_VARIABLESET(sink__V485->context, namedPropertyFreeVars(namedP__V509));
    Hashset varFV__V512 = LINK_VARIABLESET(sink__V485->context, variablePropertyFreeVars(varP__V510));
    UNLINK(sink__V485->context, term__V486);
    ADD_PROPERTIES(sink__V485, LINK_VARIABLESET(sink__V485->context, namedFV__V511), LINK_VARIABLESET(sink__V485->context, varFV__V512), LINK_NamedPropertyLink(sink__V485->context, namedP__V509), LINK_VariablePropertyLink(sink__V485->context, varP__V510));
    { START(sink__V485, _M_FormArguments__binder__offsets_s2);
      COPY(sink__V485, sub__V506);COPY(sink__V485, sub__V507);COPY(sink__V485, sub__V508);END(sink__V485, _M_FormArguments__binder__offsets_s2); }
    UNLINK_VARIABLESET(sink__V485->context, namedFV__V511); UNLINK_VARIABLESET(sink__V485->context, varFV__V512);
    UNLINK_NamedPropertyLink(sink__V485->context, namedP__V509); UNLINK_VariablePropertyLink(sink__V485->context, varP__V510);
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION FormArguments-binder-offsets$2. */
int conBindOffs_M_FormArguments__binder__offsets_s2[] = {0 , 0 , 0 , 0};
char *nameFun_M_FormArguments__binder__offsets_s2(Term term) { return  "FormArguments-binder-offsets$2" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__offsets_s2 = {NULL, 0, 3, sizeof(STRUCT_Con_M_FormArguments__binder__offsets_s2), conBindOffs_M_FormArguments__binder__offsets_s2, &nameFun_M_FormArguments__binder__offsets_s2, &step_M_FormArguments__binder__offsets_s2};

int step_M_FormArguments__binder__offsets_s2(Sink sink__V513, Term term__V514)
{
  int term__V514_count = LINK_COUNT(term__V514); permitUnusedInt(term__V514_count);
  do {
    /* Contraction rule DEFS-FormArguments-binder-offsets-2. */
    ASSERT(sink__V513->context, !strcmp(SYMBOL(term__V514),  "FormArguments-binder-offsets$2" ));
    Term sub__V515 = SUB(term__V514, 0); permitUnusedTerm(sub__V515); int sub__V515_count = term__V514_count*LINK_COUNT(sub__V515); permitUnusedInt(sub__V515_count);
    CRSX_CHECK_SORT(sink__V513->context, sub__V515, &sort_M_Reified_xSort); /* sub__V515 = &#111 */
    Term sub__V516 = LINK(sink__V513->context, SUB(term__V514, 1)); int sub__V516_count = term__V514_count*LINK_COUNT(sub__V516); permitUnusedInt(sub__V516_count);
    /* sub__V516 = &#12 */
    Term sub__V517 = LINK(sink__V513->context, SUB(term__V514, 2)); int sub__V517_count = term__V514_count*LINK_COUNT(sub__V517); permitUnusedInt(sub__V517_count);
    /* sub__V517 = &#2 */
    UNLINK(sink__V513->context, term__V514);
    { START(sink__V513, _M__sCons);
      COPY(sink__V513, LINK(sink__V513->context, sub__V517));{ START(sink__V513, _M_FormArguments__binder__offsets);
        COPY(sink__V513, sub__V516);COPY(sink__V513, sub__V517);END(sink__V513, _M_FormArguments__binder__offsets); }
      END(sink__V513, _M__sCons); }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION FormArguments-binder-offsets$3. */
int conBindOffs_M_FormArguments__binder__offsets_s3[] = {0 , 0 , 1 , 1 , 1};
char *nameFun_M_FormArguments__binder__offsets_s3(Term term) { return  "FormArguments-binder-offsets$3" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__offsets_s3 = {NULL, 0, 4, sizeof(STRUCT_Con_M_FormArguments__binder__offsets_s3), conBindOffs_M_FormArguments__binder__offsets_s3, &nameFun_M_FormArguments__binder__offsets_s3, &step_M_FormArguments__binder__offsets_s3};

int step_M_FormArguments__binder__offsets_s3(Sink sink__V518, Term term__V519)
{
  int term__V519_count = LINK_COUNT(term__V519); permitUnusedInt(term__V519_count);
  do {
    /* Contraction rule DEFS-FormArguments-binder-offsets-1. */
    ASSERT(sink__V518->context, !strcmp(SYMBOL(term__V519),  "FormArguments-binder-offsets$3" ));
    Term sub__V520 = SUB(term__V519, 0); permitUnusedTerm(sub__V520); int sub__V520_count = term__V519_count*LINK_COUNT(sub__V520); permitUnusedInt(sub__V520_count);
    CRSX_CHECK_SORT(sink__V518->context, sub__V520, &sort_M_Reified_xSort); /* sub__V520 = &#111 */
    Variable x__V521 = BINDER(term__V519,1,0); if (term__V519_count <= 1) UNBIND(x__V521);
    Term sub__V522 = LINK(sink__V518->context, SUB(term__V519, 1)); int sub__V522_count = term__V519_count*LINK_COUNT(sub__V522); permitUnusedInt(sub__V522_count);
    CRSX_CHECK_SORT(sink__V518->context, sub__V522, &sort_M_Reified_xFormArgument); /* sub__V522 = &#112 */
    Variable y__V115 = x__V521; permitUnusedVariable(y__V115);
    Term sub__V523 = LINK(sink__V518->context, SUB(term__V519, 2)); int sub__V523_count = term__V519_count*LINK_COUNT(sub__V523); permitUnusedInt(sub__V523_count);
    /* sub__V523 = &#12 */
    Term sub__V524 = LINK(sink__V518->context, SUB(term__V519, 3)); int sub__V524_count = term__V519_count*LINK_COUNT(sub__V524); permitUnusedInt(sub__V524_count);
    /* sub__V524 = &#2 */
    UNLINK(sink__V518->context, term__V519);
    { START(sink__V518, _M_FormArguments__binder__offsets);
      { START(sink__V518, _M__sCons);
        COPY(sink__V518, sub__V522); /* REUSED SUBSTITUTION */ COPY(sink__V518, sub__V523);END(sink__V518, _M__sCons); }
      { double num__V525;
        num__V525 = (double) 1; { double tmp__V526;
          tmp__V526 = DOUBLE(sub__V524); num__V525 += tmp__V526; }
        LITERALNF(sink__V518, (size_t) 31, "%G", num__V525); }
      END(sink__V518, _M_FormArguments__binder__offsets); }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION FormArguments-binder-offsets$4. */
int conBindOffs_M_FormArguments__binder__offsets_s4[] = {0 , 0};
char *nameFun_M_FormArguments__binder__offsets_s4(Term term) { return  "FormArguments-binder-offsets$4" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__offsets_s4 = {NULL, 0, 1, sizeof(STRUCT_Con_M_FormArguments__binder__offsets_s4), conBindOffs_M_FormArguments__binder__offsets_s4, &nameFun_M_FormArguments__binder__offsets_s4, &step_M_FormArguments__binder__offsets_s4};

int step_M_FormArguments__binder__offsets_s4(Sink sink__V527, Term term__V528)
{
  int term__V528_count = LINK_COUNT(term__V528); permitUnusedInt(term__V528_count);
  do {
    /* Contraction rule DEFS-FormArguments-binder-offsets-3. */
    ASSERT(sink__V527->context, !strcmp(SYMBOL(term__V528),  "FormArguments-binder-offsets$4" ));
    Term sub__V529 = SUB(term__V528, 0); permitUnusedTerm(sub__V529); int sub__V529_count = term__V528_count*LINK_COUNT(sub__V529); permitUnusedInt(sub__V529_count);
    /* sub__V529 = &#2 */
    UNLINK(sink__V527->context, term__V528);
    { START(sink__V527, _M__sNil); END(sink__V527, _M__sNil); } 
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION UnString$1. */
int conBindOffs_M_UnString_s1[] = {0 , 0};
char *nameFun_M_UnString_s1(Term term) { return  "UnString$1" ; }
struct _ConstructionDescriptor descriptor_M_UnString_s1 = {NULL, 0, 1, sizeof(STRUCT_Con_M_UnString_s1), conBindOffs_M_UnString_s1, &nameFun_M_UnString_s1, &step_M_UnString_s1};

int step_M_UnString_s1(Sink sink__V530, Term term__V531)
{
  int term__V531_count = LINK_COUNT(term__V531); permitUnusedInt(term__V531_count);
  do {
    /* Contraction rule DEFS-UnString-1. */
    ASSERT(sink__V530->context, !strcmp(SYMBOL(term__V531),  "UnString$1" ));
    Term sub__V532 = LINK(sink__V530->context, SUB(term__V531, 0)); int sub__V532_count = term__V531_count*LINK_COUNT(sub__V532); permitUnusedInt(sub__V532_count);
    /* sub__V532 = &#11 */
    UNLINK(sink__V530->context, term__V531);
    COPY(sink__V530, sub__V532);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION MetaVar2$1. */
int conBindOffs_M_MetaVar2_s1[] = {0 , 0};
char *nameFun_M_MetaVar2_s1(Term term) { return  "MetaVar2$1" ; }
struct _ConstructionDescriptor descriptor_M_MetaVar2_s1 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_MetaVar2_s1), conBindOffs_M_MetaVar2_s1, &nameFun_M_MetaVar2_s1, &step_M_MetaVar2_s1};

int step_M_MetaVar2_s1(Sink sink__V533, Term term__V534)
{
  int term__V534_count = LINK_COUNT(term__V534); permitUnusedInt(term__V534_count);
  do {
    /* Contraction rule DEFS-MetaVar2-2. */
    ASSERT(sink__V533->context, !strcmp(SYMBOL(term__V534),  "MetaVar2$1" ));
    Term sub__V535 = LINK(sink__V533->context, SUB(term__V534, 0)); int sub__V535_count = term__V534_count*LINK_COUNT(sub__V535); permitUnusedInt(sub__V535_count);
    /* sub__V535 = &#11 */
    
    NamedPropertyLink namedP__V536 = LINK_NamedPropertyLink(sink__V533->context, NAMED_PROPERTIES(term__V534));
    VariablePropertyLink varP__V537 = LINK_VariablePropertyLink(sink__V533->context, VARIABLE_PROPERTIES(term__V534));
    Hashset namedFV__V538 = LINK_VARIABLESET(sink__V533->context, namedPropertyFreeVars(namedP__V536));
    Hashset varFV__V539 = LINK_VARIABLESET(sink__V533->context, variablePropertyFreeVars(varP__V537));
    UNLINK(sink__V533->context, term__V534);
    { START(sink__V533, _M_TOKEN);
      COPY(sink__V533, sub__V535);END(sink__V533, _M_TOKEN); }
    UNLINK_VARIABLESET(sink__V533->context, namedFV__V538); UNLINK_VARIABLESET(sink__V533->context, varFV__V539);
    UNLINK_NamedPropertyLink(sink__V533->context, namedP__V536); UNLINK_VariablePropertyLink(sink__V533->context, varP__V537);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION MetaVar2$2. */
int conBindOffs_M_MetaVar2_s2[] = {0 , 0};
char *nameFun_M_MetaVar2_s2(Term term) { return  "MetaVar2$2" ; }
struct _ConstructionDescriptor descriptor_M_MetaVar2_s2 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_MetaVar2_s2), conBindOffs_M_MetaVar2_s2, &nameFun_M_MetaVar2_s2, &step_M_MetaVar2_s2};

int step_M_MetaVar2_s2(Sink sink__V540, Term term__V541)
{
  int term__V541_count = LINK_COUNT(term__V541); permitUnusedInt(term__V541_count);
  Term sub__V542 = FORCE(sink__V540->context, SUB(term__V541, 0));
  EnumOf_M_Reified_xVariable choice__V543 = (IS_VARIABLE_USE(sub__V542) ? VarOf_M_Reified_xVariable : (EnumOf_M_Reified_xVariable) TAG(sub__V542));
  switch (choice__V543)
  {
    case VarOf_M_Reified_xVariable: {
      do {
        ASSERT(sink__V540->context, !strcmp(SYMBOL(term__V541),  "MetaVar2$2" ));
        Term sub__V544 = SUB(term__V541, 0); permitUnusedTerm(sub__V544); int sub__V544_count = term__V541_count*LINK_COUNT(sub__V544); permitUnusedInt(sub__V544_count);
        CRSX_CHECK_SORT(sink__V540->context, sub__V544, &sort_M_Reified_xVariable); /* Function DEFS-MetaVar2-1$vFree fall-back case for free variable */
        Variable z__V545 = VARIABLE(sub__V544); permitUnusedVariable(z__V545);
        
        NamedPropertyLink namedP__V546 = LINK_NamedPropertyLink(sink__V540->context, NAMED_PROPERTIES(term__V541));
        VariablePropertyLink varP__V547 = LINK_VariablePropertyLink(sink__V540->context, VARIABLE_PROPERTIES(term__V541));
        Hashset namedFV__V548 = LINK_VARIABLESET(sink__V540->context, namedPropertyFreeVars(namedP__V546));
        Hashset varFV__V549 = LINK_VARIABLESET(sink__V540->context, variablePropertyFreeVars(varP__V547));
        UNLINK(sink__V540->context, term__V541);
        ADD_PROPERTIES(sink__V540, LINK_VARIABLESET(sink__V540->context, namedFV__V548), LINK_VARIABLESET(sink__V540->context, varFV__V549), LINK_NamedPropertyLink(sink__V540->context, namedP__V546), LINK_VariablePropertyLink(sink__V540->context, varP__V547));
        { START(sink__V540, _M_MetaVar2_s3);
          USE(sink__V540, z__V545); END(sink__V540, _M_MetaVar2_s3); }
        UNLINK_VARIABLESET(sink__V540->context, namedFV__V548); UNLINK_VARIABLESET(sink__V540->context, varFV__V549);
        UNLINK_NamedPropertyLink(sink__V540->context, namedP__V546); UNLINK_VariablePropertyLink(sink__V540->context, varP__V547);
        
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

int step_M_MetaVar2_s3(Sink sink__V550, Term term__V551)
{
  int term__V551_count = LINK_COUNT(term__V551); permitUnusedInt(term__V551_count);
  do {
    /* Contraction rule DEFS-MetaVar2-1. */
    ASSERT(sink__V550->context, !strcmp(SYMBOL(term__V551),  "MetaVar2$3" ));
    Term sub__V552 = LINK(sink__V550->context, SUB(term__V551, 0)); int sub__V552_count = term__V551_count*LINK_COUNT(sub__V552); permitUnusedInt(sub__V552_count);
    CRSX_CHECK_SORT(sink__V550->context, sub__V552, &sort_M_Reified_xVariable); UNLINK_SUB(sink__V550->context, term__V551,  0); NORMALIZE(sink__V550->context, sub__V552); SUB(term__V551,  0) = LINK(sink__V550->context, sub__V552);
    /* sub__V552 = &#11 */
    
    NamedPropertyLink namedP__V553 = LINK_NamedPropertyLink(sink__V550->context, NAMED_PROPERTIES(term__V551));
    VariablePropertyLink varP__V554 = LINK_VariablePropertyLink(sink__V550->context, VARIABLE_PROPERTIES(term__V551));
    Hashset namedFV__V555 = LINK_VARIABLESET(sink__V550->context, namedPropertyFreeVars(namedP__V553));
    Hashset varFV__V556 = LINK_VARIABLESET(sink__V550->context, variablePropertyFreeVars(varP__V554));
    UNLINK(sink__V550->context, term__V551);
    { START(sink__V550, _M__sTextCons);
      { START(sink__V550, _M__sTextEmbed);
        { START(sink__V550, _M_AsText);
          COPY(sink__V550, sub__V552);END(sink__V550, _M_AsText); }
        END(sink__V550, _M__sTextEmbed); }
      { START(sink__V550, _M__sTextNil);
        END(sink__V550, _M__sTextNil); }
      END(sink__V550, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V550->context, namedFV__V555); UNLINK_VARIABLESET(sink__V550->context, varFV__V556);
    UNLINK_NamedPropertyLink(sink__V550->context, namedP__V553); UNLINK_VariablePropertyLink(sink__V550->context, varP__V554);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DDescriptor. */
int conBindOffs_M_DDescriptor[] = {0 , 0 , 0};
char *nameFun_M_DDescriptor(Term term) { return  "DDescriptor" ; }
struct _ConstructionDescriptor descriptor_M_DDescriptor = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_DDescriptor), conBindOffs_M_DDescriptor, &nameFun_M_DDescriptor, &step_M_DDescriptor};

int step_M_DDescriptor(Sink sink__V557, Term term__V558)
{
  int term__V558_count = LINK_COUNT(term__V558); permitUnusedInt(term__V558_count);
  Term sub__V559 = FORCE(sink__V557->context, SUB(term__V558, 0));
  EnumOf_M_OK_xSORT choice__V560 = (IS_VARIABLE_USE(sub__V559) ? VarOf_M_OK_xSORT : (EnumOf_M_OK_xSORT) TAG(sub__V559));
  switch (choice__V560)
  {
    case Data_M_OK: { /* Function DEFS-DDescriptor-1$DDescriptor$OK case OK */
      ASSERT(sink__V557->context, !strcmp(SYMBOL(term__V558),  "DDescriptor" ));
      Term sub__V561 = SUB(term__V558, 0); permitUnusedTerm(sub__V561); int sub__V561_count = term__V558_count*LINK_COUNT(sub__V561); permitUnusedInt(sub__V561_count);
      CRSX_CHECK_SORT(sink__V557->context, sub__V561, &sort_M_OK_xSORT); ASSERT(sink__V557->context, !strcmp(SYMBOL(sub__V561),  "OK" ));
      Term sub__V562 = LINK(sink__V557->context, SUB(term__V558, 1)); int sub__V562_count = term__V558_count*LINK_COUNT(sub__V562); permitUnusedInt(sub__V562_count);
      /* sub__V562 = &#0 */
      
      NamedPropertyLink namedP__V563 = LINK_NamedPropertyLink(sink__V557->context, NAMED_PROPERTIES(term__V558));
      VariablePropertyLink varP__V564 = LINK_VariablePropertyLink(sink__V557->context, VARIABLE_PROPERTIES(term__V558));
      Hashset namedFV__V565 = LINK_VARIABLESET(sink__V557->context, namedPropertyFreeVars(namedP__V563));
      Hashset varFV__V566 = LINK_VARIABLESET(sink__V557->context, variablePropertyFreeVars(varP__V564));
      UNLINK(sink__V557->context, term__V558);
      ADD_PROPERTIES(sink__V557, LINK_VARIABLESET(sink__V557->context, namedFV__V565), LINK_VARIABLESET(sink__V557->context, varFV__V566), LINK_NamedPropertyLink(sink__V557->context, namedP__V563), LINK_VariablePropertyLink(sink__V557->context, varP__V564));
      { START(sink__V557, _M_DDescriptor_s1);
        COPY(sink__V557, sub__V562);END(sink__V557, _M_DDescriptor_s1); }
      UNLINK_VARIABLESET(sink__V557->context, namedFV__V565); UNLINK_VARIABLESET(sink__V557->context, varFV__V566);
      UNLINK_NamedPropertyLink(sink__V557->context, namedP__V563); UNLINK_VariablePropertyLink(sink__V557->context, varP__V564);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION Step. */
int conBindOffs_M_Step[] = {0 , 0};
char *nameFun_M_Step(Term term) { return  "Step" ; }
struct _ConstructionDescriptor descriptor_M_Step = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_Step), conBindOffs_M_Step, &nameFun_M_Step, &step_M_Step};

int step_M_Step(Sink sink__V567, Term term__V568)
{
  int term__V568_count = LINK_COUNT(term__V568); permitUnusedInt(term__V568_count);
  do {
    /* Contraction rule DEFS-Step-1. */
    ASSERT(sink__V567->context, !strcmp(SYMBOL(term__V568),  "Step" ));
    Term sub__V569 = LINK(sink__V567->context, SUB(term__V568, 0)); int sub__V569_count = term__V568_count*LINK_COUNT(sub__V569); permitUnusedInt(sub__V569_count);
    /* sub__V569 = &#1 */
    
    NamedPropertyLink namedP__V570 = LINK_NamedPropertyLink(sink__V567->context, NAMED_PROPERTIES(term__V568));
    VariablePropertyLink varP__V571 = LINK_VariablePropertyLink(sink__V567->context, VARIABLE_PROPERTIES(term__V568));
    Hashset namedFV__V572 = LINK_VARIABLESET(sink__V567->context, namedPropertyFreeVars(namedP__V570));
    Hashset varFV__V573 = LINK_VARIABLESET(sink__V567->context, variablePropertyFreeVars(varP__V571));
    UNLINK(sink__V567->context, term__V568);
    { START(sink__V567, _M__sTextCons);
      { START(sink__V567, _M__sTextChars);
        LITERAL(sink__V567,  "step" ); END(sink__V567, _M__sTextChars); }
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

/* FUNCTION PromiscuityString$1. */
int conBindOffs_M_PromiscuityString_s1[] = {0};
char *nameFun_M_PromiscuityString_s1(Term term) { return  "PromiscuityString$1" ; }
struct _ConstructionDescriptor descriptor_M_PromiscuityString_s1 = {NULL, 0, 0, sizeof(STRUCT_Con_M_PromiscuityString_s1), conBindOffs_M_PromiscuityString_s1, &nameFun_M_PromiscuityString_s1, &step_M_PromiscuityString_s1};

int step_M_PromiscuityString_s1(Sink sink__V574, Term term__V575)
{
  int term__V575_count = LINK_COUNT(term__V575); permitUnusedInt(term__V575_count);
  do {
    /* Contraction rule DEFS-PromiscuityString-1. */
    ASSERT(sink__V574->context, !strcmp(SYMBOL(term__V575),  "PromiscuityString$1" ));
    UNLINK(sink__V574->context, term__V575);
    LITERAL(sink__V574,  "LINEAR" ); 
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION PromiscuityString$2. */
int conBindOffs_M_PromiscuityString_s2[] = {0};
char *nameFun_M_PromiscuityString_s2(Term term) { return  "PromiscuityString$2" ; }
struct _ConstructionDescriptor descriptor_M_PromiscuityString_s2 = {NULL, 0, 0, sizeof(STRUCT_Con_M_PromiscuityString_s2), conBindOffs_M_PromiscuityString_s2, &nameFun_M_PromiscuityString_s2, &step_M_PromiscuityString_s2};

int step_M_PromiscuityString_s2(Sink sink__V576, Term term__V577)
{
  int term__V577_count = LINK_COUNT(term__V577); permitUnusedInt(term__V577_count);
  do {
    /* Contraction rule DEFS-PromiscuityString-2. */
    ASSERT(sink__V576->context, !strcmp(SYMBOL(term__V577),  "PromiscuityString$2" ));
    UNLINK(sink__V576->context, term__V577);
    LITERAL(sink__V576,  "PROMISCUOUS" ); 
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION PromiscuityString. */
int conBindOffs_M_PromiscuityString[] = {0 , 0};
char *nameFun_M_PromiscuityString(Term term) { return  "PromiscuityString" ; }
struct _ConstructionDescriptor descriptor_M_PromiscuityString = {NULL, 0, 1, sizeof(STRUCT_Con_M_PromiscuityString), conBindOffs_M_PromiscuityString, &nameFun_M_PromiscuityString, &step_M_PromiscuityString};

int step_M_PromiscuityString(Sink sink__V578, Term term__V579)
{
  int term__V579_count = LINK_COUNT(term__V579); permitUnusedInt(term__V579_count);
  Term sub__V580 = FORCE(sink__V578->context, SUB(term__V579, 0));
  EnumOf_M_Reified_xPromiscuity choice__V581 = (IS_VARIABLE_USE(sub__V580) ? VarOf_M_Reified_xPromiscuity : (EnumOf_M_Reified_xPromiscuity) TAG(sub__V580));
  switch (choice__V581)
  {
    case Data_M_LINEAR: { /* Function DEFS-PromiscuityString-1$PromiscuityString$LINEAR case LINEAR */
      ASSERT(sink__V578->context, !strcmp(SYMBOL(term__V579),  "PromiscuityString" ));
      Term sub__V582 = SUB(term__V579, 0); permitUnusedTerm(sub__V582); int sub__V582_count = term__V579_count*LINK_COUNT(sub__V582); permitUnusedInt(sub__V582_count);
      CRSX_CHECK_SORT(sink__V578->context, sub__V582, &sort_M_Reified_xPromiscuity); ASSERT(sink__V578->context, !strcmp(SYMBOL(sub__V582),  "LINEAR" ));
      
      NamedPropertyLink namedP__V583 = LINK_NamedPropertyLink(sink__V578->context, NAMED_PROPERTIES(term__V579));
      VariablePropertyLink varP__V584 = LINK_VariablePropertyLink(sink__V578->context, VARIABLE_PROPERTIES(term__V579));
      Hashset namedFV__V585 = LINK_VARIABLESET(sink__V578->context, namedPropertyFreeVars(namedP__V583));
      Hashset varFV__V586 = LINK_VARIABLESET(sink__V578->context, variablePropertyFreeVars(varP__V584));
      UNLINK(sink__V578->context, term__V579);
      ADD_PROPERTIES(sink__V578, LINK_VARIABLESET(sink__V578->context, namedFV__V585), LINK_VARIABLESET(sink__V578->context, varFV__V586), LINK_NamedPropertyLink(sink__V578->context, namedP__V583), LINK_VariablePropertyLink(sink__V578->context, varP__V584));
      { START(sink__V578, _M_PromiscuityString_s1);
        END(sink__V578, _M_PromiscuityString_s1); }
      UNLINK_VARIABLESET(sink__V578->context, namedFV__V585); UNLINK_VARIABLESET(sink__V578->context, varFV__V586);
      UNLINK_NamedPropertyLink(sink__V578->context, namedP__V583); UNLINK_VariablePropertyLink(sink__V578->context, varP__V584);
      
      return 1;
    break; } case Data_M_PROMISCUOUS: { /* Function DEFS-PromiscuityString-2$PromiscuityString$PROMISCUOUS case PROMISCUOUS */
      ASSERT(sink__V578->context, !strcmp(SYMBOL(term__V579),  "PromiscuityString" ));
      Term sub__V587 = SUB(term__V579, 0); permitUnusedTerm(sub__V587); int sub__V587_count = term__V579_count*LINK_COUNT(sub__V587); permitUnusedInt(sub__V587_count);
      CRSX_CHECK_SORT(sink__V578->context, sub__V587, &sort_M_Reified_xPromiscuity); ASSERT(sink__V578->context, !strcmp(SYMBOL(sub__V587),  "PROMISCUOUS" ));
      
      NamedPropertyLink namedP__V588 = LINK_NamedPropertyLink(sink__V578->context, NAMED_PROPERTIES(term__V579));
      VariablePropertyLink varP__V589 = LINK_VariablePropertyLink(sink__V578->context, VARIABLE_PROPERTIES(term__V579));
      Hashset namedFV__V590 = LINK_VARIABLESET(sink__V578->context, namedPropertyFreeVars(namedP__V588));
      Hashset varFV__V591 = LINK_VARIABLESET(sink__V578->context, variablePropertyFreeVars(varP__V589));
      UNLINK(sink__V578->context, term__V579);
      ADD_PROPERTIES(sink__V578, LINK_VARIABLESET(sink__V578->context, namedFV__V590), LINK_VARIABLESET(sink__V578->context, varFV__V591), LINK_NamedPropertyLink(sink__V578->context, namedP__V588), LINK_VariablePropertyLink(sink__V578->context, varP__V589));
      { START(sink__V578, _M_PromiscuityString_s2);
        END(sink__V578, _M_PromiscuityString_s2); }
      UNLINK_VARIABLESET(sink__V578->context, namedFV__V590); UNLINK_VARIABLESET(sink__V578->context, varFV__V591);
      UNLINK_NamedPropertyLink(sink__V578->context, namedP__V588); UNLINK_VariablePropertyLink(sink__V578->context, varP__V589);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION MapText1$1. */
int conBindOffs_M_MapText1_s1[] = {0 , 0 , 1 , 2};
char *nameFun_M_MapText1_s1(Term term) { return  "MapText1$1" ; }
struct _ConstructionDescriptor descriptor_M_MapText1_s1 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_MapText1_s1), conBindOffs_M_MapText1_s1, &nameFun_M_MapText1_s1, &step_M_MapText1_s1};

int step_M_MapText1_s1(Sink sink__V592, Term term__V593)
{
  int term__V593_count = LINK_COUNT(term__V593); permitUnusedInt(term__V593_count);
  Term sub__V594 = FORCE(sink__V592->context, SUB(term__V593, 0));
  EnumOf_M__sList choice__V595 = (IS_VARIABLE_USE(sub__V594) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V594));
  switch (choice__V595)
  {
    case Data_M__sCons: { /* Function DEFS-MapText1-1$MapText1$1$$Cons case $Cons */
      ASSERT(sink__V592->context, !strcmp(SYMBOL(term__V593),  "MapText1$1" ));
      Term sub__V596 = SUB(term__V593, 0); permitUnusedTerm(sub__V596); int sub__V596_count = term__V593_count*LINK_COUNT(sub__V596); permitUnusedInt(sub__V596_count);
      ASSERT(sink__V592->context, !strcmp(SYMBOL(sub__V596),  "$Cons" ));
      Term sub__V597 = LINK(sink__V592->context, SUB(sub__V596, 0)); int sub__V597_count = sub__V596_count*LINK_COUNT(sub__V597); permitUnusedInt(sub__V597_count);
      /* sub__V597 = &#0-0 */
      Term sub__V598 = LINK(sink__V592->context, SUB(sub__V596, 1)); int sub__V598_count = sub__V596_count*LINK_COUNT(sub__V598); permitUnusedInt(sub__V598_count);
      /* sub__V598 = &#0-1 */
      Variable x__V599 = BINDER(term__V593,1,0); if (term__V593_count <= 1) UNBIND(x__V599);
      Term sub__V600 = LINK(sink__V592->context, SUB(term__V593, 1)); int sub__V600_count = term__V593_count*LINK_COUNT(sub__V600); permitUnusedInt(sub__V600_count);
      CRSX_CHECK_SORT(sink__V592->context, sub__V600, &sort_M_Reified_xVariable); /* sub__V600 = &#2 */
      Variable x__V601 = BINDER(term__V593,2,0); if (term__V593_count <= 1) UNBIND(x__V601);
      Term sub__V602 = LINK(sink__V592->context, SUB(term__V593, 2)); int sub__V602_count = term__V593_count*LINK_COUNT(sub__V602); permitUnusedInt(sub__V602_count);
      CRSX_CHECK_SORT(sink__V592->context, sub__V602, &sort_M_Reified_xVariable); /* sub__V602 = &#3 */
      
      NamedPropertyLink namedP__V603 = LINK_NamedPropertyLink(sink__V592->context, NAMED_PROPERTIES(term__V593));
      VariablePropertyLink varP__V604 = LINK_VariablePropertyLink(sink__V592->context, VARIABLE_PROPERTIES(term__V593));
      Hashset namedFV__V605 = LINK_VARIABLESET(sink__V592->context, namedPropertyFreeVars(namedP__V603));
      Hashset varFV__V606 = LINK_VARIABLESET(sink__V592->context, variablePropertyFreeVars(varP__V604));
      UNLINK(sink__V592->context, term__V593);
      ADD_PROPERTIES(sink__V592, LINK_VARIABLESET(sink__V592->context, namedFV__V605), LINK_VARIABLESET(sink__V592->context, varFV__V606), LINK_NamedPropertyLink(sink__V592->context, namedP__V603), LINK_VariablePropertyLink(sink__V592->context, varP__V604));
      { START(sink__V592, _M_MapText1_s2);
        COPY(sink__V592, sub__V597);COPY(sink__V592, sub__V598);{ if (!IS_BOUND(x__V599)) { REBIND(x__V599);
            Variable binds__V607[1] = {x__V599}; BINDS(sink__V592, 1, binds__V607);
            COPY(sink__V592, sub__V600); /* REUSED SUBSTITUTION */  }
          else { Variable b__V608 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V592->context,"b__V608");
            Variable binds__V609[1] = {b__V608}; BINDS(sink__V592, 1, binds__V609);
            {
              Term arg__V610;
              { Sink buf__V611 = ALLOCA_BUFFER(sink__V592->context);
                USE(buf__V611, b__V608); arg__V610 = BUFFER_TERM(buf__V611); FREE_BUFFER(buf__V611); }
              Variable vars__V612[1] = {x__V599};
              Term args__V613[1] = {arg__V610};
              struct _SubstitutionFrame substitution__V614 = {NULL, 0, 1, vars__V612, args__V613, NULL};
              SUBSTITUTE(sink__V592, sub__V600, &substitution__V614); }
                }
           }
        { if (!IS_BOUND(x__V601)) { REBIND(x__V601);
            Variable binds__V615[1] = {x__V601}; BINDS(sink__V592, 1, binds__V615);
            COPY(sink__V592, sub__V602); /* REUSED SUBSTITUTION */  }
          else { Variable b__V616 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V592->context,"b__V616");
            Variable binds__V617[1] = {b__V616}; BINDS(sink__V592, 1, binds__V617);
            {
              Term arg__V618;
              { Sink buf__V619 = ALLOCA_BUFFER(sink__V592->context);
                USE(buf__V619, b__V616); arg__V618 = BUFFER_TERM(buf__V619); FREE_BUFFER(buf__V619); }
              Variable vars__V620[1] = {x__V601};
              Term args__V621[1] = {arg__V618};
              struct _SubstitutionFrame substitution__V622 = {NULL, 0, 1, vars__V620, args__V621, NULL};
              SUBSTITUTE(sink__V592, sub__V602, &substitution__V622); }
                }
           }
        END(sink__V592, _M_MapText1_s2); }
      UNLINK_VARIABLESET(sink__V592->context, namedFV__V605); UNLINK_VARIABLESET(sink__V592->context, varFV__V606);
      UNLINK_NamedPropertyLink(sink__V592->context, namedP__V603); UNLINK_VariablePropertyLink(sink__V592->context, varP__V604);
      
      return 1;
    break; } case Data_M__sNil: { /* Function DEFS-MapText1-2$MapText1$1$$Nil case $Nil */
      ASSERT(sink__V592->context, !strcmp(SYMBOL(term__V593),  "MapText1$1" ));
      Term sub__V623 = SUB(term__V593, 0); permitUnusedTerm(sub__V623); int sub__V623_count = term__V593_count*LINK_COUNT(sub__V623); permitUnusedInt(sub__V623_count);
      ASSERT(sink__V592->context, !strcmp(SYMBOL(sub__V623),  "$Nil" ));
      Variable x__V624 = BINDER(term__V593,1,0); if (term__V593_count <= 1) UNBIND(x__V624);
      Term sub__V625 = LINK(sink__V592->context, SUB(term__V593, 1)); int sub__V625_count = term__V593_count*LINK_COUNT(sub__V625); permitUnusedInt(sub__V625_count);
      CRSX_CHECK_SORT(sink__V592->context, sub__V625, &sort_M_Reified_xVariable); /* sub__V625 = &#0 */
      Variable x__V626 = BINDER(term__V593,2,0); if (term__V593_count <= 1) UNBIND(x__V626);
      Term sub__V627 = LINK(sink__V592->context, SUB(term__V593, 2)); int sub__V627_count = term__V593_count*LINK_COUNT(sub__V627); permitUnusedInt(sub__V627_count);
      CRSX_CHECK_SORT(sink__V592->context, sub__V627, &sort_M_Reified_xVariable); /* sub__V627 = &#1 */
      
      NamedPropertyLink namedP__V628 = LINK_NamedPropertyLink(sink__V592->context, NAMED_PROPERTIES(term__V593));
      VariablePropertyLink varP__V629 = LINK_VariablePropertyLink(sink__V592->context, VARIABLE_PROPERTIES(term__V593));
      Hashset namedFV__V630 = LINK_VARIABLESET(sink__V592->context, namedPropertyFreeVars(namedP__V628));
      Hashset varFV__V631 = LINK_VARIABLESET(sink__V592->context, variablePropertyFreeVars(varP__V629));
      UNLINK(sink__V592->context, term__V593);
      ADD_PROPERTIES(sink__V592, LINK_VARIABLESET(sink__V592->context, namedFV__V630), LINK_VARIABLESET(sink__V592->context, varFV__V631), LINK_NamedPropertyLink(sink__V592->context, namedP__V628), LINK_VariablePropertyLink(sink__V592->context, varP__V629));
      { START(sink__V592, _M_MapText1_s3);
        { if (!IS_BOUND(x__V624)) { REBIND(x__V624);
            Variable binds__V632[1] = {x__V624}; BINDS(sink__V592, 1, binds__V632);
            COPY(sink__V592, sub__V625); /* REUSED SUBSTITUTION */  }
          else { Variable b__V633 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V592->context,"b__V633");
            Variable binds__V634[1] = {b__V633}; BINDS(sink__V592, 1, binds__V634);
            {
              Term arg__V635;
              { Sink buf__V636 = ALLOCA_BUFFER(sink__V592->context);
                USE(buf__V636, b__V633); arg__V635 = BUFFER_TERM(buf__V636); FREE_BUFFER(buf__V636); }
              Variable vars__V637[1] = {x__V624};
              Term args__V638[1] = {arg__V635};
              struct _SubstitutionFrame substitution__V639 = {NULL, 0, 1, vars__V637, args__V638, NULL};
              SUBSTITUTE(sink__V592, sub__V625, &substitution__V639); }
                }
           }
        { if (!IS_BOUND(x__V626)) { REBIND(x__V626);
            Variable binds__V640[1] = {x__V626}; BINDS(sink__V592, 1, binds__V640);
            COPY(sink__V592, sub__V627); /* REUSED SUBSTITUTION */  }
          else { Variable b__V641 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V592->context,"b__V641");
            Variable binds__V642[1] = {b__V641}; BINDS(sink__V592, 1, binds__V642);
            {
              Term arg__V643;
              { Sink buf__V644 = ALLOCA_BUFFER(sink__V592->context);
                USE(buf__V644, b__V641); arg__V643 = BUFFER_TERM(buf__V644); FREE_BUFFER(buf__V644); }
              Variable vars__V645[1] = {x__V626};
              Term args__V646[1] = {arg__V643};
              struct _SubstitutionFrame substitution__V647 = {NULL, 0, 1, vars__V645, args__V646, NULL};
              SUBSTITUTE(sink__V592, sub__V627, &substitution__V647); }
                }
           }
        END(sink__V592, _M_MapText1_s3); }
      UNLINK_VARIABLESET(sink__V592->context, namedFV__V630); UNLINK_VARIABLESET(sink__V592->context, varFV__V631);
      UNLINK_NamedPropertyLink(sink__V592->context, namedP__V628); UNLINK_VariablePropertyLink(sink__V592->context, varP__V629);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION MapText1$2. */
int conBindOffs_M_MapText1_s2[] = {0 , 0 , 0 , 1 , 2};
char *nameFun_M_MapText1_s2(Term term) { return  "MapText1$2" ; }
struct _ConstructionDescriptor descriptor_M_MapText1_s2 = {&sort_M_Reified_xVariable, 0, 4, sizeof(STRUCT_Con_M_MapText1_s2), conBindOffs_M_MapText1_s2, &nameFun_M_MapText1_s2, &step_M_MapText1_s2};

int step_M_MapText1_s2(Sink sink__V648, Term term__V649)
{
  int term__V649_count = LINK_COUNT(term__V649); permitUnusedInt(term__V649_count);
  do {
    /* Contraction rule DEFS-MapText1-1. */
    ASSERT(sink__V648->context, !strcmp(SYMBOL(term__V649),  "MapText1$2" ));
    Term sub__V650 = LINK(sink__V648->context, SUB(term__V649, 0)); int sub__V650_count = term__V649_count*LINK_COUNT(sub__V650); permitUnusedInt(sub__V650_count);
    /* sub__V650 = &#31 */
    Term sub__V651 = LINK(sink__V648->context, SUB(term__V649, 1)); int sub__V651_count = term__V649_count*LINK_COUNT(sub__V651); permitUnusedInt(sub__V651_count);
    /* sub__V651 = &#32 */
    Variable x__V652 = BINDER(term__V649,2,0); if (term__V649_count <= 1) UNBIND(x__V652);
    Term sub__V653 = LINK(sink__V648->context, SUB(term__V649, 2)); int sub__V653_count = term__V649_count*LINK_COUNT(sub__V653); permitUnusedInt(sub__V653_count);
    CRSX_CHECK_SORT(sink__V648->context, sub__V653, &sort_M_Reified_xVariable); /* sub__V653 = &#2 */
    Variable x__V654 = BINDER(term__V649,3,0); if (term__V649_count <= 1) UNBIND(x__V654);
    Term sub__V655 = LINK(sink__V648->context, SUB(term__V649, 3)); int sub__V655_count = term__V649_count*LINK_COUNT(sub__V655); permitUnusedInt(sub__V655_count);
    CRSX_CHECK_SORT(sink__V648->context, sub__V655, &sort_M_Reified_xVariable); /* sub__V655 = &#1 */
    
    NamedPropertyLink namedP__V656 = LINK_NamedPropertyLink(sink__V648->context, NAMED_PROPERTIES(term__V649));
    VariablePropertyLink varP__V657 = LINK_VariablePropertyLink(sink__V648->context, VARIABLE_PROPERTIES(term__V649));
    Hashset namedFV__V658 = LINK_VARIABLESET(sink__V648->context, namedPropertyFreeVars(namedP__V656));
    Hashset varFV__V659 = LINK_VARIABLESET(sink__V648->context, variablePropertyFreeVars(varP__V657));
    UNLINK(sink__V648->context, term__V649);
    { START(sink__V648, _M__sTextCons);
      { START(sink__V648, _M__sTextEmbed);
        { START(sink__V648, _M_AsText);
          {
            Term arg__V660;
            { Sink buf__V661 = ALLOCA_BUFFER(sink__V648->context);
              COPY(buf__V661, sub__V650);arg__V660 = BUFFER_TERM(buf__V661); FREE_BUFFER(buf__V661); }
            Variable vars__V662[1] = {x__V654};
            Term args__V663[1] = {arg__V660};
            struct _SubstitutionFrame substitution__V664 = {NULL, 0, 1, vars__V662, args__V663, NULL};
            SUBSTITUTE(sink__V648, sub__V655, &substitution__V664); }
          END(sink__V648, _M_AsText); }
        END(sink__V648, _M__sTextEmbed); }
      { START(sink__V648, _M__sTextCons);
        { START(sink__V648, _M__sTextEmbed);
          { START(sink__V648, _M_AsText);
            { START(sink__V648, _M_MapText_s1);
              COPY(sink__V648, sub__V651);{ if (!IS_BOUND(x__V652)) { REBIND(x__V652);
                  Variable binds__V665[1] = {x__V652}; BINDS(sink__V648, 1, binds__V665);
                  COPY(sink__V648, sub__V653); /* REUSED SUBSTITUTION */  }
                else { Variable b__V666 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V648->context,"b__V666");
                  Variable binds__V667[1] = {b__V666}; BINDS(sink__V648, 1, binds__V667);
                  {
                    Term arg__V668;
                    { Sink buf__V669 = ALLOCA_BUFFER(sink__V648->context);
                      USE(buf__V669, b__V666); arg__V668 = BUFFER_TERM(buf__V669); FREE_BUFFER(buf__V669); }
                    Variable vars__V670[1] = {x__V652};
                    Term args__V671[1] = {arg__V668};
                    struct _SubstitutionFrame substitution__V672 = {NULL, 0, 1, vars__V670, args__V671, NULL};
                    SUBSTITUTE(sink__V648, sub__V653, &substitution__V672); }
                      }
                 }
              END(sink__V648, _M_MapText_s1); }
            END(sink__V648, _M_AsText); }
          END(sink__V648, _M__sTextEmbed); }
        { START(sink__V648, _M__sTextNil);
          END(sink__V648, _M__sTextNil); }
        END(sink__V648, _M__sTextCons); }
      END(sink__V648, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V648->context, namedFV__V658); UNLINK_VARIABLESET(sink__V648->context, varFV__V659);
    UNLINK_NamedPropertyLink(sink__V648->context, namedP__V656); UNLINK_VariablePropertyLink(sink__V648->context, varP__V657);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION MapText1$3. */
int conBindOffs_M_MapText1_s3[] = {0 , 1 , 2};
char *nameFun_M_MapText1_s3(Term term) { return  "MapText1$3" ; }
struct _ConstructionDescriptor descriptor_M_MapText1_s3 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_MapText1_s3), conBindOffs_M_MapText1_s3, &nameFun_M_MapText1_s3, &step_M_MapText1_s3};

int step_M_MapText1_s3(Sink sink__V673, Term term__V674)
{
  int term__V674_count = LINK_COUNT(term__V674); permitUnusedInt(term__V674_count);
  do {
    /* Contraction rule DEFS-MapText1-2. */
    ASSERT(sink__V673->context, !strcmp(SYMBOL(term__V674),  "MapText1$3" ));
    Variable x__V675 = BINDER(term__V674,0,0); if (term__V674_count <= 1) UNBIND(x__V675);
    Term sub__V676 = SUB(term__V674, 0); permitUnusedTerm(sub__V676); int sub__V676_count = term__V674_count*LINK_COUNT(sub__V676); permitUnusedInt(sub__V676_count);
    CRSX_CHECK_SORT(sink__V673->context, sub__V676, &sort_M_Reified_xVariable); /* sub__V676 = &#2 */
    Variable x__V677 = BINDER(term__V674,1,0); if (term__V674_count <= 1) UNBIND(x__V677);
    Term sub__V678 = SUB(term__V674, 1); permitUnusedTerm(sub__V678); int sub__V678_count = term__V674_count*LINK_COUNT(sub__V678); permitUnusedInt(sub__V678_count);
    CRSX_CHECK_SORT(sink__V673->context, sub__V678, &sort_M_Reified_xVariable); /* sub__V678 = &#1 */
    
    NamedPropertyLink namedP__V679 = LINK_NamedPropertyLink(sink__V673->context, NAMED_PROPERTIES(term__V674));
    VariablePropertyLink varP__V680 = LINK_VariablePropertyLink(sink__V673->context, VARIABLE_PROPERTIES(term__V674));
    Hashset namedFV__V681 = LINK_VARIABLESET(sink__V673->context, namedPropertyFreeVars(namedP__V679));
    Hashset varFV__V682 = LINK_VARIABLESET(sink__V673->context, variablePropertyFreeVars(varP__V680));
    UNLINK(sink__V673->context, term__V674);
    { START(sink__V673, _M__sTextNil); END(sink__V673, _M__sTextNil); }
    UNLINK_VARIABLESET(sink__V673->context, namedFV__V681); UNLINK_VARIABLESET(sink__V673->context, varFV__V682);
    UNLINK_NamedPropertyLink(sink__V673->context, namedP__V679); UNLINK_VariablePropertyLink(sink__V673->context, varP__V680);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION UnVariable$1. */
int conBindOffs_M_UnVariable_s1[] = {0 , 0};
char *nameFun_M_UnVariable_s1(Term term) { return  "UnVariable$1" ; }
struct _ConstructionDescriptor descriptor_M_UnVariable_s1 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_UnVariable_s1), conBindOffs_M_UnVariable_s1, &nameFun_M_UnVariable_s1, &step_M_UnVariable_s1};

int step_M_UnVariable_s1(Sink sink__V683, Term term__V684)
{
  int term__V684_count = LINK_COUNT(term__V684); permitUnusedInt(term__V684_count);
  do {
    /* Contraction rule DEFS-UnVariable-1. */
    ASSERT(sink__V683->context, !strcmp(SYMBOL(term__V684),  "UnVariable$1" ));
    Term sub__V685 = LINK(sink__V683->context, SUB(term__V684, 0)); int sub__V685_count = term__V684_count*LINK_COUNT(sub__V685); permitUnusedInt(sub__V685_count);
    CRSX_CHECK_SORT(sink__V683->context, sub__V685, &sort_M_Reified_xVariable); /* sub__V685 = &#11 */
    
    NamedPropertyLink namedP__V686 = LINK_NamedPropertyLink(sink__V683->context, NAMED_PROPERTIES(term__V684));
    VariablePropertyLink varP__V687 = LINK_VariablePropertyLink(sink__V683->context, VARIABLE_PROPERTIES(term__V684));
    Hashset namedFV__V688 = LINK_VARIABLESET(sink__V683->context, namedPropertyFreeVars(namedP__V686));
    Hashset varFV__V689 = LINK_VARIABLESET(sink__V683->context, variablePropertyFreeVars(varP__V687));
    UNLINK(sink__V683->context, term__V684);
    COPY(sink__V683, sub__V685);UNLINK_VARIABLESET(sink__V683->context, namedFV__V688); UNLINK_VARIABLESET(sink__V683->context, varFV__V689);
    UNLINK_NamedPropertyLink(sink__V683->context, namedP__V686); UNLINK_VariablePropertyLink(sink__V683->context, varP__V687);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DTOKEN. */
int conBindOffs_M_DTOKEN[] = {0 , 0 , 0};
char *nameFun_M_DTOKEN(Term term) { return  "DTOKEN" ; }
struct _ConstructionDescriptor descriptor_M_DTOKEN = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_DTOKEN), conBindOffs_M_DTOKEN, &nameFun_M_DTOKEN, &step_M_DTOKEN};

int step_M_DTOKEN(Sink sink__V690, Term term__V691)
{
  int term__V691_count = LINK_COUNT(term__V691); permitUnusedInt(term__V691_count);
  Term sub__V692 = FORCE(sink__V690->context, SUB(term__V691, 0));
  EnumOf_M_OK_xSORT choice__V693 = (IS_VARIABLE_USE(sub__V692) ? VarOf_M_OK_xSORT : (EnumOf_M_OK_xSORT) TAG(sub__V692));
  switch (choice__V693)
  {
    case Data_M_OK: { /* Function DEFS-DTOKEN-1$DTOKEN$OK case OK */
      ASSERT(sink__V690->context, !strcmp(SYMBOL(term__V691),  "DTOKEN" ));
      Term sub__V694 = SUB(term__V691, 0); permitUnusedTerm(sub__V694); int sub__V694_count = term__V691_count*LINK_COUNT(sub__V694); permitUnusedInt(sub__V694_count);
      CRSX_CHECK_SORT(sink__V690->context, sub__V694, &sort_M_OK_xSORT); ASSERT(sink__V690->context, !strcmp(SYMBOL(sub__V694),  "OK" ));
      Term sub__V695 = LINK(sink__V690->context, SUB(term__V691, 1)); int sub__V695_count = term__V691_count*LINK_COUNT(sub__V695); permitUnusedInt(sub__V695_count);
      /* sub__V695 = &#0 */
      
      NamedPropertyLink namedP__V696 = LINK_NamedPropertyLink(sink__V690->context, NAMED_PROPERTIES(term__V691));
      VariablePropertyLink varP__V697 = LINK_VariablePropertyLink(sink__V690->context, VARIABLE_PROPERTIES(term__V691));
      Hashset namedFV__V698 = LINK_VARIABLESET(sink__V690->context, namedPropertyFreeVars(namedP__V696));
      Hashset varFV__V699 = LINK_VARIABLESET(sink__V690->context, variablePropertyFreeVars(varP__V697));
      UNLINK(sink__V690->context, term__V691);
      ADD_PROPERTIES(sink__V690, LINK_VARIABLESET(sink__V690->context, namedFV__V698), LINK_VARIABLESET(sink__V690->context, varFV__V699), LINK_NamedPropertyLink(sink__V690->context, namedP__V696), LINK_VariablePropertyLink(sink__V690->context, varP__V697));
      { START(sink__V690, _M_DTOKEN_s1);
        COPY(sink__V690, sub__V695);END(sink__V690, _M_DTOKEN_s1); }
      UNLINK_VARIABLESET(sink__V690->context, namedFV__V698); UNLINK_VARIABLESET(sink__V690->context, varFV__V699);
      UNLINK_NamedPropertyLink(sink__V690->context, namedP__V696); UNLINK_VariablePropertyLink(sink__V690->context, varP__V697);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION EnumFun. */
int conBindOffs_M_EnumFun[] = {0 , 0};
char *nameFun_M_EnumFun(Term term) { return  "EnumFun" ; }
struct _ConstructionDescriptor descriptor_M_EnumFun = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_EnumFun), conBindOffs_M_EnumFun, &nameFun_M_EnumFun, &step_M_EnumFun};

int step_M_EnumFun(Sink sink__V700, Term term__V701)
{
  int term__V701_count = LINK_COUNT(term__V701); permitUnusedInt(term__V701_count);
  do {
    /* Contraction rule DEFS-EnumFun-1. */
    ASSERT(sink__V700->context, !strcmp(SYMBOL(term__V701),  "EnumFun" ));
    Term sub__V702 = LINK(sink__V700->context, SUB(term__V701, 0)); int sub__V702_count = term__V701_count*LINK_COUNT(sub__V702); permitUnusedInt(sub__V702_count);
    /* sub__V702 = &#1 */
    
    NamedPropertyLink namedP__V703 = LINK_NamedPropertyLink(sink__V700->context, NAMED_PROPERTIES(term__V701));
    VariablePropertyLink varP__V704 = LINK_VariablePropertyLink(sink__V700->context, VARIABLE_PROPERTIES(term__V701));
    Hashset namedFV__V705 = LINK_VARIABLESET(sink__V700->context, namedPropertyFreeVars(namedP__V703));
    Hashset varFV__V706 = LINK_VARIABLESET(sink__V700->context, variablePropertyFreeVars(varP__V704));
    UNLINK(sink__V700->context, term__V701);
    { START(sink__V700, _M__sTextCons);
      { START(sink__V700, _M__sTextChars);
        LITERAL(sink__V700,  "FunOf" ); END(sink__V700, _M__sTextChars); }
      { START(sink__V700, _M__sTextCons);
        { START(sink__V700, _M__sTextEmbed);
          { START(sink__V700, _M_AsText);
            { START(sink__V700, _M_MANGLE);
              COPY(sink__V700, sub__V702);END(sink__V700, _M_MANGLE); }
            END(sink__V700, _M_AsText); }
          END(sink__V700, _M__sTextEmbed); }
        { START(sink__V700, _M__sTextNil);
          END(sink__V700, _M__sTextNil); }
        END(sink__V700, _M__sTextCons); }
      END(sink__V700, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V700->context, namedFV__V705); UNLINK_VARIABLESET(sink__V700->context, varFV__V706);
    UNLINK_NamedPropertyLink(sink__V700->context, namedP__V703); UNLINK_VariablePropertyLink(sink__V700->context, varP__V704);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Primitive. */
int conBindOffs_M_Primitive[] = {0 , 0};
char *nameFun_M_Primitive(Term term) { return  "Primitive" ; }
struct _ConstructionDescriptor descriptor_M_Primitive = {&sort_M_SPrimitive, 0, 1, sizeof(STRUCT_Con_M_Primitive), conBindOffs_M_Primitive, &nameFun_M_Primitive, &step_M_Primitive};

int step_M_Primitive(Sink sink__V707, Term term__V708)
{
  int term__V708_count = LINK_COUNT(term__V708); permitUnusedInt(term__V708_count);
  do {
    /* Contraction rule DEFS-Primitive-1. */
    ASSERT(sink__V707->context, !strcmp(SYMBOL(term__V708),  "Primitive" ));
    Term sub__V709 = LINK(sink__V707->context, SUB(term__V708, 0)); int sub__V709_count = term__V708_count*LINK_COUNT(sub__V709); permitUnusedInt(sub__V709_count);
    /* sub__V709 = &#1 */
    UNLINK(sink__V707->context, term__V708);
    { int test__V710;
      FORCE(sink__V707->context, sub__V709);
      test__V710 = (int) !strcmp(SYMBOL(sub__V709), "C" ); if (test__V710) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xC); END(sink__V707, _M_E_xC); }  }
      else { { int test__V711;
          FORCE(sink__V707->context, sub__V709);
          test__V711 = (int) !strcmp(SYMBOL(sub__V709), "NumericEqual" );
          if (test__V711) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xNumericEqual);
              END(sink__V707, _M_E_xNumericEqual); }
             }
          else { { int test__V712;
              FORCE(sink__V707->context, sub__V709);
              test__V712 = (int) !strcmp(SYMBOL(sub__V709), "StringLessThan" );
              if (test__V712) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xStringLessThan);
                  END(sink__V707, _M_E_xStringLessThan); }
                 }
              else { { int test__V713;
                  FORCE(sink__V707->context, sub__V709);
                  test__V713 = (int) !strcmp(SYMBOL(sub__V709), "LessThan" );
                  if (test__V713) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xLessThan);
                      END(sink__V707, _M_E_xLessThan); }
                     }
                  else { { int test__V714;
                      FORCE(sink__V707->context, sub__V709);
                      test__V714 = (int) !strcmp(SYMBOL(sub__V709), "GreaterThan" );
                      if (test__V714) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xGreaterThan);
                          END(sink__V707, _M_E_xGreaterThan); }
                         }
                      else { { int test__V715;
                          FORCE(sink__V707->context, sub__V709);
                          test__V715 = (int) !strcmp(SYMBOL(sub__V709), "LessThanOrEqual" );
                          if (test__V715) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xLessThanOrEqual);
                              END(sink__V707, _M_E_xLessThanOrEqual); }
                             }
                          else { { int test__V716;
                              FORCE(sink__V707->context, sub__V709);
                              test__V716 = (int) !strcmp(SYMBOL(sub__V709), "GreaterThanOrEqual" );
                              if (test__V716) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xGreaterThanOrEqual);
                                  END(sink__V707, _M_E_xGreaterThanOrEqual); }
                                 }
                              else { { int test__V717;
                                  FORCE(sink__V707->context, sub__V709);
                                  test__V717 = (int) !strcmp(SYMBOL(sub__V709), "NotEqual" );
                                  if (test__V717) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xNotEqual);
                                      END(sink__V707, _M_E_xNotEqual); }
                                     }
                                  else { { int test__V718;
                                      FORCE(sink__V707->context, sub__V709);
                                      test__V718 = (int) !strcmp(SYMBOL(sub__V709), ":" );
                                      if (test__V718) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xConcat);
                                          END(sink__V707, _M_E_xConcat); }
                                         }
                                      else { { int test__V719;
                                          FORCE(sink__V707->context, sub__V709);
                                          test__V719 = (int) !strcmp(SYMBOL(sub__V709), "SameVariable" );
                                          if (test__V719) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xSameVariable);
                                              END(sink__V707, _M_E_xSameVariable); }
                                             }
                                          else { { int test__V720;
                                              FORCE(sink__V707->context, sub__V709);
                                              test__V720 = (int) !strcmp(SYMBOL(sub__V709), "LesserVariable" );
                                              if (test__V720) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xLesserVariable);
                                                  END(sink__V707, _M_E_xLesserVariable); }
                                                 }
                                              else { { int test__V721;
                                                  FORCE(sink__V707->context, sub__V709);
                                                  test__V721 = (int) !strcmp(SYMBOL(sub__V709), "Equal" );
                                                  if (test__V721) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xEqual);
                                                      END(sink__V707, _M_E_xEqual); }
                                                     }
                                                  else { { int test__V722;
                                                      FORCE(sink__V707->context, sub__V709);
                                                      test__V722 = (int) !strcmp(SYMBOL(sub__V709), "Contains" );
                                                      if (test__V722) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xContains);
                                                          END(sink__V707, _M_E_xContains); }
                                                         }
                                                      else { { int test__V723;
                                                          FORCE(sink__V707->context, sub__V709);
                                                          test__V723 = (int) !strcmp(SYMBOL(sub__V709), "StartsWith" );
                                                          if (test__V723) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xStartsWith);
                                                              END(sink__V707, _M_E_xStartsWith); }
                                                             }
                                                          else { { int test__V724;
                                                              FORCE(sink__V707->context, sub__V709);
                                                              test__V724 = (int) !strcmp(SYMBOL(sub__V709), "EndsWith" );
                                                              if (test__V724) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xEndsWith);
                                                                  END(sink__V707, _M_E_xEndsWith); }
                                                                 }
                                                              else { { int test__V725;
                                                                  FORCE(sink__V707->context, sub__V709);
                                                                  test__V725 = (int) !strcmp(SYMBOL(sub__V709), "Split" );
                                                                  if (test__V725) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xSplit);
                                                                      END(sink__V707, _M_E_xSplit); }
                                                                     }
                                                                  else { { int test__V726;
                                                                      FORCE(sink__V707->context, sub__V709);
                                                                      test__V726 = (int) !strcmp(SYMBOL(sub__V709), "MatchRegex" );
                                                                      if (test__V726) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xMatchRegex);
                                                                          END(sink__V707, _M_E_xMatchRegex); }
                                                                         }
                                                                      else { { int test__V727;
                                                                          FORCE(sink__V707->context, sub__V709);
                                                                          test__V727 = (int) !strcmp(SYMBOL(sub__V709), "Length" );
                                                                          if (test__V727) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xLength);
                                                                              END(sink__V707, _M_E_xLength); }
                                                                             }
                                                                          else { { int test__V728;
                                                                              FORCE(sink__V707->context, sub__V709);
                                                                              test__V728 = (int) !strcmp(SYMBOL(sub__V709), "Substring" );
                                                                              if (test__V728) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xSubstring);
                                                                                  END(sink__V707, _M_E_xSubstring); }
                                                                                 }
                                                                              else { { int test__V729;
                                                                                  FORCE(sink__V707->context, sub__V709);
                                                                                  test__V729 = (int) !strcmp(SYMBOL(sub__V709), "Escape" );
                                                                                  if (test__V729) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xEscape);
                                                                                      END(sink__V707, _M_E_xEscape); }
                                                                                     }
                                                                                  else { { int test__V730;
                                                                                      FORCE(sink__V707->context, sub__V709);
                                                                                      test__V730 = (int) !strcmp(SYMBOL(sub__V709), "Mangle" );
                                                                                      if (test__V730) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xMangle);
                                                                                          END(sink__V707, _M_E_xMangle); }
                                                                                         }
                                                                                      else { { int test__V731;
                                                                                          FORCE(sink__V707->context, sub__V709);
                                                                                          test__V731 = (int) !strcmp(SYMBOL(sub__V709), "BeforeFirst" );
                                                                                          if (test__V731) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xBeforeFirst);
                                                                                              END(sink__V707, _M_E_xBeforeFirst); }
                                                                                             }
                                                                                          else { { int test__V732;
                                                                                              FORCE(sink__V707->context, sub__V709);
                                                                                              test__V732 = (int) !strcmp(SYMBOL(sub__V709), "AfterFirst" );
                                                                                              if (test__V732) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xAfterFirst);
                                                                                                  END(sink__V707, _M_E_xAfterFirst); }
                                                                                                 }
                                                                                              else { { int test__V733;
                                                                                                  FORCE(sink__V707->context, sub__V709);
                                                                                                  test__V733 = (int) !strcmp(SYMBOL(sub__V709), "FromFirst" );
                                                                                                  if (test__V733) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xFromFirst);
                                                                                                      END(sink__V707, _M_E_xFromFirst); }
                                                                                                     }
                                                                                                  else { { int test__V734;
                                                                                                      FORCE(sink__V707->context, sub__V709);
                                                                                                      test__V734 = (int) !strcmp(SYMBOL(sub__V709), "ToFirst" );
                                                                                                      if (test__V734) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xToFirst);
                                                                                                          END(sink__V707, _M_E_xToFirst); }
                                                                                                         }
                                                                                                      else { { int test__V735;
                                                                                                          FORCE(sink__V707->context, sub__V709);
                                                                                                          test__V735 = (int) !strcmp(SYMBOL(sub__V709), "FormatNumber" );
                                                                                                          if (test__V735) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xFormatNumber);
                                                                                                              END(sink__V707, _M_E_xFormatNumber); }
                                                                                                             }
                                                                                                          else { { int test__V736;
                                                                                                              FORCE(sink__V707->context, sub__V709);
                                                                                                              test__V736 = (int) !strcmp(SYMBOL(sub__V709), "Format" );
                                                                                                              if (test__V736) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xFormat);
                                                                                                                  END(sink__V707, _M_E_xFormat); }
                                                                                                                 }
                                                                                                              else { { int test__V737;
                                                                                                                  FORCE(sink__V707->context, sub__V709);
                                                                                                                  test__V737 = (int) !strcmp(SYMBOL(sub__V709), "Show" );
                                                                                                                  if (test__V737) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xShow);
                                                                                                                      END(sink__V707, _M_E_xShow); }
                                                                                                                     }
                                                                                                                  else { { int test__V738;
                                                                                                                      FORCE(sink__V707->context, sub__V709);
                                                                                                                      test__V738 = (int) !strcmp(SYMBOL(sub__V709), "PassLocationProperties" );
                                                                                                                      if (test__V738) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xPassLocationProperties);
                                                                                                                          END(sink__V707, _M_E_xPassLocationProperties); }
                                                                                                                         }
                                                                                                                      else { { int test__V739;
                                                                                                                          FORCE(sink__V707->context, sub__V709);
                                                                                                                          test__V739 = (int) !strcmp(SYMBOL(sub__V709), "Plus" );
                                                                                                                          if (test__V739) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xPlus);
                                                                                                                              END(sink__V707, _M_E_xPlus); }
                                                                                                                             }
                                                                                                                          else { { int test__V740;
                                                                                                                              FORCE(sink__V707->context, sub__V709);
                                                                                                                              test__V740 = (int) !strcmp(SYMBOL(sub__V709), "Minus" );
                                                                                                                              if (test__V740) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xMinus);
                                                                                                                                  END(sink__V707, _M_E_xMinus); }
                                                                                                                                 }
                                                                                                                              else { { int test__V741;
                                                                                                                                  FORCE(sink__V707->context, sub__V709);
                                                                                                                                  test__V741 = (int) !strcmp(SYMBOL(sub__V709), "Times" );
                                                                                                                                  if (test__V741) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xTimes);
                                                                                                                                      END(sink__V707, _M_E_xTimes); }
                                                                                                                                     }
                                                                                                                                  else { { int test__V742;
                                                                                                                                      FORCE(sink__V707->context, sub__V709);
                                                                                                                                      test__V742 = (int) !strcmp(SYMBOL(sub__V709), "Divide" );
                                                                                                                                      if (test__V742) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xDiv);
                                                                                                                                          END(sink__V707, _M_E_xDiv); }
                                                                                                                                         }
                                                                                                                                      else { { int test__V743;
                                                                                                                                          FORCE(sink__V707->context, sub__V709);
                                                                                                                                          test__V743 = (int) !strcmp(SYMBOL(sub__V709), "Modulo" );
                                                                                                                                          if (test__V743) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xMod);
                                                                                                                                              END(sink__V707, _M_E_xMod); }
                                                                                                                                             }
                                                                                                                                          else { { int test__V744;
                                                                                                                                              FORCE(sink__V707->context, sub__V709);
                                                                                                                                              test__V744 = (int) !strcmp(SYMBOL(sub__V709), "Absolute" );
                                                                                                                                              if (test__V744) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xAbsolute);
                                                                                                                                                  END(sink__V707, _M_E_xAbsolute); }
                                                                                                                                                 }
                                                                                                                                              else { { int test__V745;
                                                                                                                                                  FORCE(sink__V707->context, sub__V709);
                                                                                                                                                  test__V745 = (int) !strcmp(SYMBOL(sub__V709), "Decimal" );
                                                                                                                                                  if (test__V745) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xDecimal);
                                                                                                                                                      END(sink__V707, _M_E_xDecimal); }
                                                                                                                                                     }
                                                                                                                                                  else { { int test__V746;
                                                                                                                                                      FORCE(sink__V707->context, sub__V709);
                                                                                                                                                      test__V746 = (int) !strcmp(SYMBOL(sub__V709), "Hex" );
                                                                                                                                                      if (test__V746) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xHex);
                                                                                                                                                          END(sink__V707, _M_E_xHex); }
                                                                                                                                                         }
                                                                                                                                                      else { { int test__V747;
                                                                                                                                                          FORCE(sink__V707->context, sub__V709);
                                                                                                                                                          test__V747 = (int) !strcmp(SYMBOL(sub__V709), "BitAnd" );
                                                                                                                                                          if (test__V747) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xBitAnd);
                                                                                                                                                              END(sink__V707, _M_E_xBitAnd); }
                                                                                                                                                             }
                                                                                                                                                          else { { int test__V748;
                                                                                                                                                              FORCE(sink__V707->context, sub__V709);
                                                                                                                                                              test__V748 = (int) !strcmp(SYMBOL(sub__V709), "BitOr" );
                                                                                                                                                              if (test__V748) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xBitOr);
                                                                                                                                                                  END(sink__V707, _M_E_xBitOr); }
                                                                                                                                                                 }
                                                                                                                                                              else { { int test__V749;
                                                                                                                                                                  FORCE(sink__V707->context, sub__V709);
                                                                                                                                                                  test__V749 = (int) !strcmp(SYMBOL(sub__V709), "BitXor" );
                                                                                                                                                                  if (test__V749) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xBitXOr);
                                                                                                                                                                      END(sink__V707, _M_E_xBitXOr); }
                                                                                                                                                                     }
                                                                                                                                                                  else { { int test__V750;
                                                                                                                                                                      FORCE(sink__V707->context, sub__V709);
                                                                                                                                                                      test__V750 = (int) !strcmp(SYMBOL(sub__V709), "BitNot" );
                                                                                                                                                                      if (test__V750) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xBitNot);
                                                                                                                                                                          END(sink__V707, _M_E_xBitNot); }
                                                                                                                                                                         }
                                                                                                                                                                      else { { int test__V751;
                                                                                                                                                                          FORCE(sink__V707->context, sub__V709);
                                                                                                                                                                          test__V751 = (int) !strcmp(SYMBOL(sub__V709), "BitMinus" );
                                                                                                                                                                          if (test__V751) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xBitMinus);
                                                                                                                                                                              END(sink__V707, _M_E_xBitMinus); }
                                                                                                                                                                             }
                                                                                                                                                                          else { { int test__V752;
                                                                                                                                                                              FORCE(sink__V707->context, sub__V709);
                                                                                                                                                                              test__V752 = (int) !strcmp(SYMBOL(sub__V709), "BitSubSetEq" );
                                                                                                                                                                              if (test__V752) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xBitSubSetEq);
                                                                                                                                                                                  END(sink__V707, _M_E_xBitSubSetEq); }
                                                                                                                                                                                 }
                                                                                                                                                                              else { { int test__V753;
                                                                                                                                                                                  FORCE(sink__V707->context, sub__V709);
                                                                                                                                                                                  test__V753 = (int) !strcmp(SYMBOL(sub__V709), "Get" );
                                                                                                                                                                                  if (test__V753) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xGet);
                                                                                                                                                                                      END(sink__V707, _M_E_xGet); }
                                                                                                                                                                                     }
                                                                                                                                                                                  else { { int test__V754;
                                                                                                                                                                                      FORCE(sink__V707->context, sub__V709);
                                                                                                                                                                                      test__V754 = (int) !strcmp(SYMBOL(sub__V709), "GetRef" );
                                                                                                                                                                                      if (test__V754) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xGetRef);
                                                                                                                                                                                          END(sink__V707, _M_E_xGetRef); }
                                                                                                                                                                                         }
                                                                                                                                                                                      else { { int test__V755;
                                                                                                                                                                                          FORCE(sink__V707->context, sub__V709);
                                                                                                                                                                                          test__V755 = (int) !strcmp(SYMBOL(sub__V709), "IfDef" );
                                                                                                                                                                                          if (test__V755) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xIfDef);
                                                                                                                                                                                              END(sink__V707, _M_E_xIfDef); }
                                                                                                                                                                                             }
                                                                                                                                                                                          else { { int test__V756;
                                                                                                                                                                                              FORCE(sink__V707->context, sub__V709);
                                                                                                                                                                                              test__V756 = (int) !strcmp(SYMBOL(sub__V709), "Error" );
                                                                                                                                                                                              if (test__V756) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xError);
                                                                                                                                                                                                  END(sink__V707, _M_E_xError); }
                                                                                                                                                                                                 }
                                                                                                                                                                                              else { { int test__V757;
                                                                                                                                                                                                  FORCE(sink__V707->context, sub__V709);
                                                                                                                                                                                                  test__V757 = (int) !strcmp(SYMBOL(sub__V709), "ForgivableError" );
                                                                                                                                                                                                  if (test__V757) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xForgivableError);
                                                                                                                                                                                                      END(sink__V707, _M_E_xForgivableError); }
                                                                                                                                                                                                     }
                                                                                                                                                                                                  else { { int test__V758;
                                                                                                                                                                                                      FORCE(sink__V707->context, sub__V709);
                                                                                                                                                                                                      test__V758 = (int) !strcmp(SYMBOL(sub__V709), "Trace" );
                                                                                                                                                                                                      if (test__V758) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xTrace);
                                                                                                                                                                                                          END(sink__V707, _M_E_xTrace); }
                                                                                                                                                                                                         }
                                                                                                                                                                                                      else { { int test__V759;
                                                                                                                                                                                                          FORCE(sink__V707->context, sub__V709);
                                                                                                                                                                                                          test__V759 = (int) !strcmp(SYMBOL(sub__V709), "LoadTerm" );
                                                                                                                                                                                                          if (test__V759) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xLoadTerm);
                                                                                                                                                                                                              END(sink__V707, _M_E_xLoadTerm); }
                                                                                                                                                                                                             }
                                                                                                                                                                                                          else { { int test__V760;
                                                                                                                                                                                                              FORCE(sink__V707->context, sub__V709);
                                                                                                                                                                                                              test__V760 = (int) !strcmp(SYMBOL(sub__V709), "SaveTerm" );
                                                                                                                                                                                                              if (test__V760) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xSaveTerm);
                                                                                                                                                                                                                  END(sink__V707, _M_E_xSaveTerm); }
                                                                                                                                                                                                                 }
                                                                                                                                                                                                              else { { int test__V761;
                                                                                                                                                                                                                  FORCE(sink__V707->context, sub__V709);
                                                                                                                                                                                                                  test__V761 = (int) !strcmp(SYMBOL(sub__V709), "If" );
                                                                                                                                                                                                                  if (test__V761) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xIf);
                                                                                                                                                                                                                      END(sink__V707, _M_E_xIf); }
                                                                                                                                                                                                                     }
                                                                                                                                                                                                                  else { { int test__V762;
                                                                                                                                                                                                                      FORCE(sink__V707->context, sub__V709);
                                                                                                                                                                                                                      test__V762 = (int) !strcmp(SYMBOL(sub__V709), "IfZero" );
                                                                                                                                                                                                                      if (test__V762) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xIfZero);
                                                                                                                                                                                                                          END(sink__V707, _M_E_xIfZero); }
                                                                                                                                                                                                                         }
                                                                                                                                                                                                                      else { { int test__V763;
                                                                                                                                                                                                                          FORCE(sink__V707->context, sub__V709);
                                                                                                                                                                                                                          test__V763 = (int) !strcmp(SYMBOL(sub__V709), "IfEmpty" );
                                                                                                                                                                                                                          if (test__V763) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xIfEmpty);
                                                                                                                                                                                                                              END(sink__V707, _M_E_xIfEmpty); }
                                                                                                                                                                                                                             }
                                                                                                                                                                                                                          else { { int test__V764;
                                                                                                                                                                                                                              FORCE(sink__V707->context, sub__V709);
                                                                                                                                                                                                                              test__V764 = (int) !strcmp(SYMBOL(sub__V709), "FreeVariables" );
                                                                                                                                                                                                                              if (test__V764) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xFreeVariables);
                                                                                                                                                                                                                                  END(sink__V707, _M_E_xFreeVariables); }
                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                              else { { int test__V765;
                                                                                                                                                                                                                                  FORCE(sink__V707->context, sub__V709);
                                                                                                                                                                                                                                  test__V765 = (int) !strcmp(SYMBOL(sub__V709), "IntersectVariables" );
                                                                                                                                                                                                                                  if (test__V765) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xIntersectVariables);
                                                                                                                                                                                                                                      END(sink__V707, _M_E_xIntersectVariables); }
                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                  else { { int test__V766;
                                                                                                                                                                                                                                      FORCE(sink__V707->context, sub__V709);
                                                                                                                                                                                                                                      test__V766 = (int) !strcmp(SYMBOL(sub__V709), "UnionVariables" );
                                                                                                                                                                                                                                      if (test__V766) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xUnionVariables);
                                                                                                                                                                                                                                          END(sink__V707, _M_E_xUnionVariables); }
                                                                                                                                                                                                                                         }
                                                                                                                                                                                                                                      else { { int test__V767;
                                                                                                                                                                                                                                          FORCE(sink__V707->context, sub__V709);
                                                                                                                                                                                                                                          test__V767 = (int) !strcmp(SYMBOL(sub__V709), "ExceptVariables" );
                                                                                                                                                                                                                                          if (test__V767) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xExceptVariables);
                                                                                                                                                                                                                                              END(sink__V707, _M_E_xExceptVariables); }
                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                          else { { int test__V768;
                                                                                                                                                                                                                                              FORCE(sink__V707->context, sub__V709);
                                                                                                                                                                                                                                              test__V768 = (int) !strcmp(SYMBOL(sub__V709), "VariableNameIs" );
                                                                                                                                                                                                                                              if (test__V768) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xVariableNameIs);
                                                                                                                                                                                                                                                  END(sink__V707, _M_E_xVariableNameIs); }
                                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                                              else { { int test__V769;
                                                                                                                                                                                                                                                  FORCE(sink__V707->context, sub__V709);
                                                                                                                                                                                                                                                  test__V769 = (int) !strcmp(SYMBOL(sub__V709), "Match" );
                                                                                                                                                                                                                                                  if (test__V769) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xMatch);
                                                                                                                                                                                                                                                      END(sink__V707, _M_E_xMatch); }
                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                  else { { int test__V770;
                                                                                                                                                                                                                                                      FORCE(sink__V707->context, sub__V709);
                                                                                                                                                                                                                                                      test__V770 = (int) !strcmp(SYMBOL(sub__V709), "TryCall" );
                                                                                                                                                                                                                                                      if (test__V770) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xTryCall);
                                                                                                                                                                                                                                                          END(sink__V707, _M_E_xTryCall); }
                                                                                                                                                                                                                                                         }
                                                                                                                                                                                                                                                      else { { int test__V771;
                                                                                                                                                                                                                                                          FORCE(sink__V707->context, sub__V709);
                                                                                                                                                                                                                                                          test__V771 = (int) !strcmp(SYMBOL(sub__V709), "Call" );
                                                                                                                                                                                                                                                          if (test__V771) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xCall);
                                                                                                                                                                                                                                                              END(sink__V707, _M_E_xCall); }
                                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                                          else { { int test__V772;
                                                                                                                                                                                                                                                              FORCE(sink__V707->context, sub__V709);
                                                                                                                                                                                                                                                              test__V772 = (int) !strcmp(SYMBOL(sub__V709), "Cast" );
                                                                                                                                                                                                                                                              if (test__V772) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xCast);
                                                                                                                                                                                                                                                                  END(sink__V707, _M_E_xCast); }
                                                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                                                              else { { int test__V773;
                                                                                                                                                                                                                                                                  FORCE(sink__V707->context, sub__V709);
                                                                                                                                                                                                                                                                  test__V773 = (int) !strcmp(SYMBOL(sub__V709), "Null" );
                                                                                                                                                                                                                                                                  if (test__V773) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xNull);
                                                                                                                                                                                                                                                                      END(sink__V707, _M_E_xNull); }
                                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                                  else { { int test__V774;
                                                                                                                                                                                                                                                                      FORCE(sink__V707->context, sub__V709);
                                                                                                                                                                                                                                                                      test__V774 = (int) !strcmp(SYMBOL(sub__V709), "Nil" );
                                                                                                                                                                                                                                                                      if (test__V774) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xNil);
                                                                                                                                                                                                                                                                          END(sink__V707, _M_E_xNil); }
                                                                                                                                                                                                                                                                         }
                                                                                                                                                                                                                                                                      else { { int test__V775;
                                                                                                                                                                                                                                                                          FORCE(sink__V707->context, sub__V709);
                                                                                                                                                                                                                                                                          test__V775 = (int) !strcmp(SYMBOL(sub__V709), "UpCase" );
                                                                                                                                                                                                                                                                          if (test__V775) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xUpCase);
                                                                                                                                                                                                                                                                              END(sink__V707, _M_E_xUpCase); }
                                                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                                                          else { { int test__V776;
                                                                                                                                                                                                                                                                              FORCE(sink__V707->context, sub__V709);
                                                                                                                                                                                                                                                                              test__V776 = (int) !strcmp(SYMBOL(sub__V709), "DownCase" );
                                                                                                                                                                                                                                                                              if (test__V776) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xDownCase);
                                                                                                                                                                                                                                                                                  END(sink__V707, _M_E_xDownCase); }
                                                                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                                                                              else { { int test__V777;
                                                                                                                                                                                                                                                                                  FORCE(sink__V707->context, sub__V709);
                                                                                                                                                                                                                                                                                  test__V777 = (int) !strcmp(SYMBOL(sub__V709), "Replace" );
                                                                                                                                                                                                                                                                                  if (test__V777) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xReplace);
                                                                                                                                                                                                                                                                                      END(sink__V707, _M_E_xReplace); }
                                                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                                                  else { { int test__V778;
                                                                                                                                                                                                                                                                                      FORCE(sink__V707->context, sub__V709);
                                                                                                                                                                                                                                                                                      test__V778 = (int) !strcmp(SYMBOL(sub__V709), "Trim" );
                                                                                                                                                                                                                                                                                      if (test__V778) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xTrim);
                                                                                                                                                                                                                                                                                          END(sink__V707, _M_E_xTrim); }
                                                                                                                                                                                                                                                                                         }
                                                                                                                                                                                                                                                                                      else { { int test__V779;
                                                                                                                                                                                                                                                                                          FORCE(sink__V707->context, sub__V709);
                                                                                                                                                                                                                                                                                          test__V779 = (int) !strcmp(SYMBOL(sub__V709), "Split" );
                                                                                                                                                                                                                                                                                          if (test__V779) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xSplit);
                                                                                                                                                                                                                                                                                              END(sink__V707, _M_E_xSplit); }
                                                                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                                                                          else { { int test__V780;
                                                                                                                                                                                                                                                                                              FORCE(sink__V707->context, sub__V709);
                                                                                                                                                                                                                                                                                              test__V780 = (int) !strcmp(SYMBOL(sub__V709), "Rescape" );
                                                                                                                                                                                                                                                                                              if (test__V780) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xRescape);
                                                                                                                                                                                                                                                                                                  END(sink__V707, _M_E_xRescape); }
                                                                                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                                                                                              else { { int test__V781;
                                                                                                                                                                                                                                                                                                  FORCE(sink__V707->context, sub__V709);
                                                                                                                                                                                                                                                                                                  test__V781 = (int) !strcmp(SYMBOL(sub__V709), "Keys" );
                                                                                                                                                                                                                                                                                                  if (test__V781) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xKeys);
                                                                                                                                                                                                                                                                                                      END(sink__V707, _M_E_xKeys); }
                                                                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                                                                  else { { int test__V782;
                                                                                                                                                                                                                                                                                                      FORCE(sink__V707->context, sub__V709);
                                                                                                                                                                                                                                                                                                      test__V782 = (int) !strcmp(SYMBOL(sub__V709), "ParseURL" );
                                                                                                                                                                                                                                                                                                      if (test__V782) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xParseURL);
                                                                                                                                                                                                                                                                                                          END(sink__V707, _M_E_xParseURL); }
                                                                                                                                                                                                                                                                                                         }
                                                                                                                                                                                                                                                                                                      else { { int test__V783;
                                                                                                                                                                                                                                                                                                          FORCE(sink__V707->context, sub__V709);
                                                                                                                                                                                                                                                                                                          test__V783 = (int) !strcmp(SYMBOL(sub__V709), "Echo" );
                                                                                                                                                                                                                                                                                                          if (test__V783) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xEcho);
                                                                                                                                                                                                                                                                                                              END(sink__V707, _M_E_xEcho); }
                                                                                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                                                                                          else { { int test__V784;
                                                                                                                                                                                                                                                                                                              FORCE(sink__V707->context, sub__V709);
                                                                                                                                                                                                                                                                                                              test__V784 = (int) !strcmp(SYMBOL(sub__V709), "DeepEqual" );
                                                                                                                                                                                                                                                                                                              if (test__V784) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xDeepEqual);
                                                                                                                                                                                                                                                                                                                  END(sink__V707, _M_E_xDeepEqual); }
                                                                                                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                                                                                                              else { { int test__V785;
                                                                                                                                                                                                                                                                                                                  FORCE(sink__V707->context, sub__V709);
                                                                                                                                                                                                                                                                                                                  test__V785 = (int) !strcmp(SYMBOL(sub__V709), "HashCode" );
                                                                                                                                                                                                                                                                                                                  if (test__V785) {  UNLINK(sink__V707->context, sub__V709); { START(sink__V707, _M_E_xHashCode);
                                                                                                                                                                                                                                                                                                                      END(sink__V707, _M_E_xHashCode); }
                                                                                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                                                                                  else { { START(sink__V707, _M_MissingPrimitive);
                                                                                                                                                                                                                                                                                                                      COPY(sink__V707, sub__V709);END(sink__V707, _M_MissingPrimitive); }
                                                                                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                                                         }
                                                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                                         }
                                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                         }
                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                         }
                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                         }
                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                            }
                                                                                                                                                                                                                             }
                                                                                                                                                                                                                        }
                                                                                                                                                                                                                         }
                                                                                                                                                                                                                    }
                                                                                                                                                                                                                     }
                                                                                                                                                                                                                }
                                                                                                                                                                                                                 }
                                                                                                                                                                                                            }
                                                                                                                                                                                                             }
                                                                                                                                                                                                        }
                                                                                                                                                                                                         }
                                                                                                                                                                                                    }
                                                                                                                                                                                                     }
                                                                                                                                                                                                }
                                                                                                                                                                                                 }
                                                                                                                                                                                            }
                                                                                                                                                                                             }
                                                                                                                                                                                        }
                                                                                                                                                                                         }
                                                                                                                                                                                    }
                                                                                                                                                                                     }
                                                                                                                                                                                }
                                                                                                                                                                                 }
                                                                                                                                                                            }
                                                                                                                                                                             }
                                                                                                                                                                        }
                                                                                                                                                                         }
                                                                                                                                                                    }
                                                                                                                                                                     }
                                                                                                                                                                }
                                                                                                                                                                 }
                                                                                                                                                            }
                                                                                                                                                             }
                                                                                                                                                        }
                                                                                                                                                         }
                                                                                                                                                    }
                                                                                                                                                     }
                                                                                                                                                }
                                                                                                                                                 }
                                                                                                                                            }
                                                                                                                                             }
                                                                                                                                        }
                                                                                                                                         }
                                                                                                                                    }
                                                                                                                                     }
                                                                                                                                }
                                                                                                                                 }
                                                                                                                            }
                                                                                                                             }
                                                                                                                        }
                                                                                                                         }
                                                                                                                    }
                                                                                                                     }
                                                                                                                }
                                                                                                                 }
                                                                                                            }
                                                                                                             }
                                                                                                        }
                                                                                                         }
                                                                                                    }
                                                                                                     }
                                                                                                }
                                                                                                 }
                                                                                            }
                                                                                             }
                                                                                        }
                                                                                         }
                                                                                    }
                                                                                     }
                                                                                }
                                                                                 }
                                                                            }
                                                                             }
                                                                        }
                                                                         }
                                                                    }
                                                                     }
                                                                }
                                                                 }
                                                            }
                                                             }
                                                        }
                                                         }
                                                    }
                                                     }
                                                }
                                                 }
                                            }
                                             }
                                        }
                                         }
                                    }
                                     }
                                }
                                 }
                            }
                             }
                        }
                         }
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

/* FUNCTION BinderOffsets. */
int conBindOffs_M_BinderOffsets[] = {0 , 0};
char *nameFun_M_BinderOffsets(Term term) { return  "BinderOffsets" ; }
struct _ConstructionDescriptor descriptor_M_BinderOffsets = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_BinderOffsets), conBindOffs_M_BinderOffsets, &nameFun_M_BinderOffsets, &step_M_BinderOffsets};

int step_M_BinderOffsets(Sink sink__V786, Term term__V787)
{
  int term__V787_count = LINK_COUNT(term__V787); permitUnusedInt(term__V787_count);
  do {
    /* Contraction rule DEFS-BinderOffsets-1. */
    ASSERT(sink__V786->context, !strcmp(SYMBOL(term__V787),  "BinderOffsets" ));
    Term sub__V788 = LINK(sink__V786->context, SUB(term__V787, 0)); int sub__V788_count = term__V787_count*LINK_COUNT(sub__V788); permitUnusedInt(sub__V788_count);
    /* sub__V788 = &#1 */
    
    NamedPropertyLink namedP__V789 = LINK_NamedPropertyLink(sink__V786->context, NAMED_PROPERTIES(term__V787));
    VariablePropertyLink varP__V790 = LINK_VariablePropertyLink(sink__V786->context, VARIABLE_PROPERTIES(term__V787));
    Hashset namedFV__V791 = LINK_VARIABLESET(sink__V786->context, namedPropertyFreeVars(namedP__V789));
    Hashset varFV__V792 = LINK_VARIABLESET(sink__V786->context, variablePropertyFreeVars(varP__V790));
    UNLINK(sink__V786->context, term__V787);
    { START(sink__V786, _M__sTextCons);
      { START(sink__V786, _M__sTextChars);
        LITERAL(sink__V786,  "conBindOffs" ); END(sink__V786, _M__sTextChars); }
      { START(sink__V786, _M__sTextCons);
        { START(sink__V786, _M__sTextEmbed);
          { START(sink__V786, _M_AsText);
            { START(sink__V786, _M_MANGLE);
              COPY(sink__V786, sub__V788);END(sink__V786, _M_MANGLE); }
            END(sink__V786, _M_AsText); }
          END(sink__V786, _M__sTextEmbed); }
        { START(sink__V786, _M__sTextNil);
          END(sink__V786, _M__sTextNil); }
        END(sink__V786, _M__sTextCons); }
      END(sink__V786, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V786->context, namedFV__V791); UNLINK_VARIABLESET(sink__V786->context, varFV__V792);
    UNLINK_NamedPropertyLink(sink__V786->context, namedP__V789); UNLINK_VariablePropertyLink(sink__V786->context, varP__V790);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION SplitMapText$1. */
int conBindOffs_M_SplitMapText_s1[] = {0 , 0 , 1 , 1 , 1 , 1 , 2 , 3};
char *nameFun_M_SplitMapText_s1(Term term) { return  "SplitMapText$1" ; }
struct _ConstructionDescriptor descriptor_M_SplitMapText_s1 = {&sort_M_Reified_xVariable, 0, 7, sizeof(STRUCT_Con_M_SplitMapText_s1), conBindOffs_M_SplitMapText_s1, &nameFun_M_SplitMapText_s1, &step_M_SplitMapText_s1};

int step_M_SplitMapText_s1(Sink sink__V793, Term term__V794)
{
  int term__V794_count = LINK_COUNT(term__V794); permitUnusedInt(term__V794_count);
  Term sub__V795 = FORCE(sink__V793->context, SUB(term__V794, 0));
  EnumOf_M__sList choice__V796 = (IS_VARIABLE_USE(sub__V795) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V795));
  switch (choice__V796)
  {
    case Data_M__sCons: { /* Function DEFS-SplitMapText-1$SplitMapText$1$$Cons case $Cons */
      ASSERT(sink__V793->context, !strcmp(SYMBOL(term__V794),  "SplitMapText$1" ));
      Term sub__V797 = SUB(term__V794, 0); permitUnusedTerm(sub__V797); int sub__V797_count = term__V794_count*LINK_COUNT(sub__V797); permitUnusedInt(sub__V797_count);
      ASSERT(sink__V793->context, !strcmp(SYMBOL(sub__V797),  "$Cons" ));
      Term sub__V798 = LINK(sink__V793->context, SUB(sub__V797, 0)); int sub__V798_count = sub__V797_count*LINK_COUNT(sub__V798); permitUnusedInt(sub__V798_count);
      /* sub__V798 = &#0-0 */
      Term sub__V799 = LINK(sink__V793->context, SUB(sub__V797, 1)); int sub__V799_count = sub__V797_count*LINK_COUNT(sub__V799); permitUnusedInt(sub__V799_count);
      /* sub__V799 = &#0-1 */
      Variable x__V800 = BINDER(term__V794,1,0); if (term__V794_count <= 1) UNBIND(x__V800);
      Term sub__V801 = LINK(sink__V793->context, SUB(term__V794, 1)); int sub__V801_count = term__V794_count*LINK_COUNT(sub__V801); permitUnusedInt(sub__V801_count);
      CRSX_CHECK_SORT(sink__V793->context, sub__V801, &sort_M_Reified_xVariable); /* sub__V801 = &#2 */
      Term sub__V802 = LINK(sink__V793->context, SUB(term__V794, 2)); int sub__V802_count = term__V794_count*LINK_COUNT(sub__V802); permitUnusedInt(sub__V802_count);
      /* sub__V802 = &#3 */
      Term sub__V803 = LINK(sink__V793->context, SUB(term__V794, 3)); int sub__V803_count = term__V794_count*LINK_COUNT(sub__V803); permitUnusedInt(sub__V803_count);
      /* sub__V803 = &#4 */
      Term sub__V804 = LINK(sink__V793->context, SUB(term__V794, 4)); int sub__V804_count = term__V794_count*LINK_COUNT(sub__V804); permitUnusedInt(sub__V804_count);
      /* sub__V804 = &#5 */
      Variable x__V805 = BINDER(term__V794,5,0); if (term__V794_count <= 1) UNBIND(x__V805);
      Term sub__V806 = LINK(sink__V793->context, SUB(term__V794, 5)); int sub__V806_count = term__V794_count*LINK_COUNT(sub__V806); permitUnusedInt(sub__V806_count);
      CRSX_CHECK_SORT(sink__V793->context, sub__V806, &sort_M_Reified_xVariable); /* sub__V806 = &#6 */
      Variable x__V807 = BINDER(term__V794,6,0); if (term__V794_count <= 1) UNBIND(x__V807);
      Term sub__V808 = LINK(sink__V793->context, SUB(term__V794, 6)); int sub__V808_count = term__V794_count*LINK_COUNT(sub__V808); permitUnusedInt(sub__V808_count);
      CRSX_CHECK_SORT(sink__V793->context, sub__V808, &sort_M_Reified_xVariable); /* sub__V808 = &#7 */
      
      NamedPropertyLink namedP__V809 = LINK_NamedPropertyLink(sink__V793->context, NAMED_PROPERTIES(term__V794));
      VariablePropertyLink varP__V810 = LINK_VariablePropertyLink(sink__V793->context, VARIABLE_PROPERTIES(term__V794));
      Hashset namedFV__V811 = LINK_VARIABLESET(sink__V793->context, namedPropertyFreeVars(namedP__V809));
      Hashset varFV__V812 = LINK_VARIABLESET(sink__V793->context, variablePropertyFreeVars(varP__V810));
      UNLINK(sink__V793->context, term__V794);
      ADD_PROPERTIES(sink__V793, LINK_VARIABLESET(sink__V793->context, namedFV__V811), LINK_VARIABLESET(sink__V793->context, varFV__V812), LINK_NamedPropertyLink(sink__V793->context, namedP__V809), LINK_VariablePropertyLink(sink__V793->context, varP__V810));
      { START(sink__V793, _M_SplitMapText_s2);
        COPY(sink__V793, sub__V798);COPY(sink__V793, sub__V799);{ if (!IS_BOUND(x__V800)) { REBIND(x__V800);
            Variable binds__V813[1] = {x__V800}; BINDS(sink__V793, 1, binds__V813);
            COPY(sink__V793, sub__V801); /* REUSED SUBSTITUTION */  }
          else { Variable b__V814 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V793->context,"b__V814");
            Variable binds__V815[1] = {b__V814}; BINDS(sink__V793, 1, binds__V815);
            {
              Term arg__V816;
              { Sink buf__V817 = ALLOCA_BUFFER(sink__V793->context);
                USE(buf__V817, b__V814); arg__V816 = BUFFER_TERM(buf__V817); FREE_BUFFER(buf__V817); }
              Variable vars__V818[1] = {x__V800};
              Term args__V819[1] = {arg__V816};
              struct _SubstitutionFrame substitution__V820 = {NULL, 0, 1, vars__V818, args__V819, NULL};
              SUBSTITUTE(sink__V793, sub__V801, &substitution__V820); }
                }
           }
        COPY(sink__V793, sub__V802);COPY(sink__V793, sub__V803);COPY(sink__V793, sub__V804);{ if (!IS_BOUND(x__V805)) { REBIND(x__V805);
            Variable binds__V821[1] = {x__V805}; BINDS(sink__V793, 1, binds__V821);
            COPY(sink__V793, sub__V806); /* REUSED SUBSTITUTION */  }
          else { Variable b__V822 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V793->context,"b__V822");
            Variable binds__V823[1] = {b__V822}; BINDS(sink__V793, 1, binds__V823);
            {
              Term arg__V824;
              { Sink buf__V825 = ALLOCA_BUFFER(sink__V793->context);
                USE(buf__V825, b__V822); arg__V824 = BUFFER_TERM(buf__V825); FREE_BUFFER(buf__V825); }
              Variable vars__V826[1] = {x__V805};
              Term args__V827[1] = {arg__V824};
              struct _SubstitutionFrame substitution__V828 = {NULL, 0, 1, vars__V826, args__V827, NULL};
              SUBSTITUTE(sink__V793, sub__V806, &substitution__V828); }
                }
           }
        { if (!IS_BOUND(x__V807)) { REBIND(x__V807);
            Variable binds__V829[1] = {x__V807}; BINDS(sink__V793, 1, binds__V829);
            COPY(sink__V793, sub__V808); /* REUSED SUBSTITUTION */  }
          else { Variable b__V830 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V793->context,"b__V830");
            Variable binds__V831[1] = {b__V830}; BINDS(sink__V793, 1, binds__V831);
            {
              Term arg__V832;
              { Sink buf__V833 = ALLOCA_BUFFER(sink__V793->context);
                USE(buf__V833, b__V830); arg__V832 = BUFFER_TERM(buf__V833); FREE_BUFFER(buf__V833); }
              Variable vars__V834[1] = {x__V807};
              Term args__V835[1] = {arg__V832};
              struct _SubstitutionFrame substitution__V836 = {NULL, 0, 1, vars__V834, args__V835, NULL};
              SUBSTITUTE(sink__V793, sub__V808, &substitution__V836); }
                }
           }
        END(sink__V793, _M_SplitMapText_s2); }
      UNLINK_VARIABLESET(sink__V793->context, namedFV__V811); UNLINK_VARIABLESET(sink__V793->context, varFV__V812);
      UNLINK_NamedPropertyLink(sink__V793->context, namedP__V809); UNLINK_VariablePropertyLink(sink__V793->context, varP__V810);
      
      return 1;
    break; } case Data_M__sNil: { /* Function DEFS-SplitMapText-2$SplitMapText$1$$Nil case $Nil */
      ASSERT(sink__V793->context, !strcmp(SYMBOL(term__V794),  "SplitMapText$1" ));
      Term sub__V837 = SUB(term__V794, 0); permitUnusedTerm(sub__V837); int sub__V837_count = term__V794_count*LINK_COUNT(sub__V837); permitUnusedInt(sub__V837_count);
      ASSERT(sink__V793->context, !strcmp(SYMBOL(sub__V837),  "$Nil" ));
      Variable x__V838 = BINDER(term__V794,1,0); if (term__V794_count <= 1) UNBIND(x__V838);
      Term sub__V839 = LINK(sink__V793->context, SUB(term__V794, 1)); int sub__V839_count = term__V794_count*LINK_COUNT(sub__V839); permitUnusedInt(sub__V839_count);
      CRSX_CHECK_SORT(sink__V793->context, sub__V839, &sort_M_Reified_xVariable); /* sub__V839 = &#0 */
      Term sub__V840 = LINK(sink__V793->context, SUB(term__V794, 2)); int sub__V840_count = term__V794_count*LINK_COUNT(sub__V840); permitUnusedInt(sub__V840_count);
      /* sub__V840 = &#1 */
      Term sub__V841 = LINK(sink__V793->context, SUB(term__V794, 3)); int sub__V841_count = term__V794_count*LINK_COUNT(sub__V841); permitUnusedInt(sub__V841_count);
      /* sub__V841 = &#2 */
      Term sub__V842 = LINK(sink__V793->context, SUB(term__V794, 4)); int sub__V842_count = term__V794_count*LINK_COUNT(sub__V842); permitUnusedInt(sub__V842_count);
      /* sub__V842 = &#3 */
      Variable x__V843 = BINDER(term__V794,5,0); if (term__V794_count <= 1) UNBIND(x__V843);
      Term sub__V844 = LINK(sink__V793->context, SUB(term__V794, 5)); int sub__V844_count = term__V794_count*LINK_COUNT(sub__V844); permitUnusedInt(sub__V844_count);
      CRSX_CHECK_SORT(sink__V793->context, sub__V844, &sort_M_Reified_xVariable); /* sub__V844 = &#4 */
      Variable x__V845 = BINDER(term__V794,6,0); if (term__V794_count <= 1) UNBIND(x__V845);
      Term sub__V846 = LINK(sink__V793->context, SUB(term__V794, 6)); int sub__V846_count = term__V794_count*LINK_COUNT(sub__V846); permitUnusedInt(sub__V846_count);
      CRSX_CHECK_SORT(sink__V793->context, sub__V846, &sort_M_Reified_xVariable); /* sub__V846 = &#5 */
      
      NamedPropertyLink namedP__V847 = LINK_NamedPropertyLink(sink__V793->context, NAMED_PROPERTIES(term__V794));
      VariablePropertyLink varP__V848 = LINK_VariablePropertyLink(sink__V793->context, VARIABLE_PROPERTIES(term__V794));
      Hashset namedFV__V849 = LINK_VARIABLESET(sink__V793->context, namedPropertyFreeVars(namedP__V847));
      Hashset varFV__V850 = LINK_VARIABLESET(sink__V793->context, variablePropertyFreeVars(varP__V848));
      UNLINK(sink__V793->context, term__V794);
      ADD_PROPERTIES(sink__V793, LINK_VARIABLESET(sink__V793->context, namedFV__V849), LINK_VARIABLESET(sink__V793->context, varFV__V850), LINK_NamedPropertyLink(sink__V793->context, namedP__V847), LINK_VariablePropertyLink(sink__V793->context, varP__V848));
      { START(sink__V793, _M_SplitMapText_s3);
        { if (!IS_BOUND(x__V838)) { REBIND(x__V838);
            Variable binds__V851[1] = {x__V838}; BINDS(sink__V793, 1, binds__V851);
            COPY(sink__V793, sub__V839); /* REUSED SUBSTITUTION */  }
          else { Variable b__V852 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V793->context,"b__V852");
            Variable binds__V853[1] = {b__V852}; BINDS(sink__V793, 1, binds__V853);
            {
              Term arg__V854;
              { Sink buf__V855 = ALLOCA_BUFFER(sink__V793->context);
                USE(buf__V855, b__V852); arg__V854 = BUFFER_TERM(buf__V855); FREE_BUFFER(buf__V855); }
              Variable vars__V856[1] = {x__V838};
              Term args__V857[1] = {arg__V854};
              struct _SubstitutionFrame substitution__V858 = {NULL, 0, 1, vars__V856, args__V857, NULL};
              SUBSTITUTE(sink__V793, sub__V839, &substitution__V858); }
                }
           }
        COPY(sink__V793, sub__V840);COPY(sink__V793, sub__V841);COPY(sink__V793, sub__V842);{ if (!IS_BOUND(x__V843)) { REBIND(x__V843);
            Variable binds__V859[1] = {x__V843}; BINDS(sink__V793, 1, binds__V859);
            COPY(sink__V793, sub__V844); /* REUSED SUBSTITUTION */  }
          else { Variable b__V860 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V793->context,"b__V860");
            Variable binds__V861[1] = {b__V860}; BINDS(sink__V793, 1, binds__V861);
            {
              Term arg__V862;
              { Sink buf__V863 = ALLOCA_BUFFER(sink__V793->context);
                USE(buf__V863, b__V860); arg__V862 = BUFFER_TERM(buf__V863); FREE_BUFFER(buf__V863); }
              Variable vars__V864[1] = {x__V843};
              Term args__V865[1] = {arg__V862};
              struct _SubstitutionFrame substitution__V866 = {NULL, 0, 1, vars__V864, args__V865, NULL};
              SUBSTITUTE(sink__V793, sub__V844, &substitution__V866); }
                }
           }
        { if (!IS_BOUND(x__V845)) { REBIND(x__V845);
            Variable binds__V867[1] = {x__V845}; BINDS(sink__V793, 1, binds__V867);
            COPY(sink__V793, sub__V846); /* REUSED SUBSTITUTION */  }
          else { Variable b__V868 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V793->context,"b__V868");
            Variable binds__V869[1] = {b__V868}; BINDS(sink__V793, 1, binds__V869);
            {
              Term arg__V870;
              { Sink buf__V871 = ALLOCA_BUFFER(sink__V793->context);
                USE(buf__V871, b__V868); arg__V870 = BUFFER_TERM(buf__V871); FREE_BUFFER(buf__V871); }
              Variable vars__V872[1] = {x__V845};
              Term args__V873[1] = {arg__V870};
              struct _SubstitutionFrame substitution__V874 = {NULL, 0, 1, vars__V872, args__V873, NULL};
              SUBSTITUTE(sink__V793, sub__V846, &substitution__V874); }
                }
           }
        END(sink__V793, _M_SplitMapText_s3); }
      UNLINK_VARIABLESET(sink__V793->context, namedFV__V849); UNLINK_VARIABLESET(sink__V793->context, varFV__V850);
      UNLINK_NamedPropertyLink(sink__V793->context, namedP__V847); UNLINK_VariablePropertyLink(sink__V793->context, varP__V848);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION SplitMapText$2. */
int conBindOffs_M_SplitMapText_s2[] = {0 , 0 , 0 , 1 , 1 , 1 , 1 , 2 , 3};
char *nameFun_M_SplitMapText_s2(Term term) { return  "SplitMapText$2" ; }
struct _ConstructionDescriptor descriptor_M_SplitMapText_s2 = {&sort_M_Reified_xVariable, 0, 8, sizeof(STRUCT_Con_M_SplitMapText_s2), conBindOffs_M_SplitMapText_s2, &nameFun_M_SplitMapText_s2, &step_M_SplitMapText_s2};

int step_M_SplitMapText_s2(Sink sink__V875, Term term__V876)
{
  int term__V876_count = LINK_COUNT(term__V876); permitUnusedInt(term__V876_count);
  do {
    /* Contraction rule DEFS-SplitMapText-1. */
    ASSERT(sink__V875->context, !strcmp(SYMBOL(term__V876),  "SplitMapText$2" ));
    Term sub__V877 = LINK(sink__V875->context, SUB(term__V876, 0)); int sub__V877_count = term__V876_count*LINK_COUNT(sub__V877); permitUnusedInt(sub__V877_count);
    /* sub__V877 = &#21 */
    Term sub__V878 = LINK(sink__V875->context, SUB(term__V876, 1)); int sub__V878_count = term__V876_count*LINK_COUNT(sub__V878); permitUnusedInt(sub__V878_count);
    /* sub__V878 = &#22 */
    Variable x__V879 = BINDER(term__V876,2,0); if (term__V876_count <= 1) UNBIND(x__V879);
    Term sub__V880 = LINK(sink__V875->context, SUB(term__V876, 2)); int sub__V880_count = term__V876_count*LINK_COUNT(sub__V880); permitUnusedInt(sub__V880_count);
    CRSX_CHECK_SORT(sink__V875->context, sub__V880, &sort_M_Reified_xVariable); UNLINK_SUB(sink__V875->context, term__V876,  2); NORMALIZE(sink__V875->context, sub__V880); SUB(term__V876,  2) = LINK(sink__V875->context, sub__V880);
    /* sub__V880 = &#1 */
    Term sub__V881 = LINK(sink__V875->context, SUB(term__V876, 3)); int sub__V881_count = term__V876_count*LINK_COUNT(sub__V881); permitUnusedInt(sub__V881_count);
    UNLINK_SUB(sink__V875->context, term__V876,  3); NORMALIZE(sink__V875->context, sub__V881); SUB(term__V876,  3) = LINK(sink__V875->context, sub__V881);
    /* sub__V881 = &#3 */
    Term sub__V882 = LINK(sink__V875->context, SUB(term__V876, 4)); int sub__V882_count = term__V876_count*LINK_COUNT(sub__V882); permitUnusedInt(sub__V882_count);
    UNLINK_SUB(sink__V875->context, term__V876,  4); NORMALIZE(sink__V875->context, sub__V882); SUB(term__V876,  4) = LINK(sink__V875->context, sub__V882);
    /* sub__V882 = &#4 */
    Term sub__V883 = LINK(sink__V875->context, SUB(term__V876, 5)); int sub__V883_count = term__V876_count*LINK_COUNT(sub__V883); permitUnusedInt(sub__V883_count);
    UNLINK_SUB(sink__V875->context, term__V876,  5); NORMALIZE(sink__V875->context, sub__V883); SUB(term__V876,  5) = LINK(sink__V875->context, sub__V883);
    /* sub__V883 = &#5 */
    Variable x__V884 = BINDER(term__V876,6,0); if (term__V876_count <= 1) UNBIND(x__V884);
    Term sub__V885 = LINK(sink__V875->context, SUB(term__V876, 6)); int sub__V885_count = term__V876_count*LINK_COUNT(sub__V885); permitUnusedInt(sub__V885_count);
    CRSX_CHECK_SORT(sink__V875->context, sub__V885, &sort_M_Reified_xVariable); UNLINK_SUB(sink__V875->context, term__V876,  6); NORMALIZE(sink__V875->context, sub__V885); SUB(term__V876,  6) = LINK(sink__V875->context, sub__V885);
    /* sub__V885 = &#6 */
    Variable x__V886 = BINDER(term__V876,7,0); if (term__V876_count <= 1) UNBIND(x__V886);
    Term sub__V887 = LINK(sink__V875->context, SUB(term__V876, 7)); int sub__V887_count = term__V876_count*LINK_COUNT(sub__V887); permitUnusedInt(sub__V887_count);
    CRSX_CHECK_SORT(sink__V875->context, sub__V887, &sort_M_Reified_xVariable); UNLINK_SUB(sink__V875->context, term__V876,  7); NORMALIZE(sink__V875->context, sub__V887); SUB(term__V876,  7) = LINK(sink__V875->context, sub__V887);
    /* sub__V887 = &#7 */
    
    NamedPropertyLink namedP__V888 = LINK_NamedPropertyLink(sink__V875->context, NAMED_PROPERTIES(term__V876));
    VariablePropertyLink varP__V889 = LINK_VariablePropertyLink(sink__V875->context, VARIABLE_PROPERTIES(term__V876));
    Hashset namedFV__V890 = LINK_VARIABLESET(sink__V875->context, namedPropertyFreeVars(namedP__V888));
    Hashset varFV__V891 = LINK_VARIABLESET(sink__V875->context, variablePropertyFreeVars(varP__V889));
    UNLINK(sink__V875->context, term__V876);
    { int test__V892;
      FORCE(sink__V875->context, sub__V881);
      test__V892 = (int) !strcmp(SYMBOL(sub__V881), "0" ); if (test__V892) {  UNLINK(sink__V875->context, sub__V881); { START(sink__V875, _M__sTextCons);
          { START(sink__V875, _M__sTextEmbed);
            { START(sink__V875, _M_AsText);
              {
                Term arg__V893;
                { Sink buf__V894 = ALLOCA_BUFFER(sink__V875->context);
                  COPY(buf__V894, LINK(buf__V894->context, sub__V882));arg__V893 = BUFFER_TERM(buf__V894); FREE_BUFFER(buf__V894); }
                Variable vars__V895[1] = {x__V884};
                Term args__V896[1] = {arg__V893};
                struct _SubstitutionFrame substitution__V897 = {NULL, 0, 1, vars__V895, args__V896, NULL};
                SUBSTITUTE(sink__V875, LINK(sink__V875->context,sub__V885), &substitution__V897); }
              END(sink__V875, _M_AsText); }
            END(sink__V875, _M__sTextEmbed); }
          { START(sink__V875, _M__sTextCons);
            { START(sink__V875, _M__sTextEmbed);
              { START(sink__V875, _M_AsText);
                {
                  Term arg__V898;
                  { Sink buf__V899 = ALLOCA_BUFFER(sink__V875->context);
                    COPY(buf__V899, sub__V877);arg__V898 = BUFFER_TERM(buf__V899); FREE_BUFFER(buf__V899); }
                  Variable vars__V900[1] = {x__V879};
                  Term args__V901[1] = {arg__V898};
                  struct _SubstitutionFrame substitution__V902 = {NULL, 0, 1, vars__V900, args__V901, NULL};
                  SUBSTITUTE(sink__V875, LINK(sink__V875->context,sub__V880), &substitution__V902); }
                END(sink__V875, _M_AsText); }
              END(sink__V875, _M__sTextEmbed); }
            { START(sink__V875, _M__sTextCons);
              { START(sink__V875, _M__sTextEmbed);
                { START(sink__V875, _M_AsText);
                  { START(sink__V875, _M_SplitMapText_s1);
                    COPY(sink__V875, sub__V878);{ Variable x__V903 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V875->context,"x__V903");
                      Variable binds__V904[1] = {x__V903}; BINDS(sink__V875, 1, binds__V904);
                      {
                        Term arg__V905;
                        { Sink buf__V906 = ALLOCA_BUFFER(sink__V875->context);
                          USE(buf__V906, x__V903); arg__V905 = BUFFER_TERM(buf__V906); FREE_BUFFER(buf__V906); }
                        Variable vars__V907[1] = {x__V879};
                        Term args__V908[1] = {arg__V905};
                        struct _SubstitutionFrame substitution__V909 = {NULL, 0, 1, vars__V907, args__V908, NULL};
                        SUBSTITUTE(sink__V875, sub__V880, &substitution__V909); }
                       }
                    LITERAL(sink__V875,  "1" ); COPY(sink__V875, sub__V882);COPY(sink__V875, sub__V883);{ Variable x__V910 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V875->context,"x__V910");
                      Variable binds__V911[1] = {x__V910}; BINDS(sink__V875, 1, binds__V911);
                      {
                        Term arg__V912;
                        { Sink buf__V913 = ALLOCA_BUFFER(sink__V875->context);
                          USE(buf__V913, x__V910); arg__V912 = BUFFER_TERM(buf__V913); FREE_BUFFER(buf__V913); }
                        Variable vars__V914[1] = {x__V884};
                        Term args__V915[1] = {arg__V912};
                        struct _SubstitutionFrame substitution__V916 = {NULL, 0, 1, vars__V914, args__V915, NULL};
                        SUBSTITUTE(sink__V875, sub__V885, &substitution__V916); }
                       }
                    { Variable x__V917 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V875->context,"x__V917");
                      Variable binds__V918[1] = {x__V917}; BINDS(sink__V875, 1, binds__V918);
                      {
                        Term arg__V919;
                        { Sink buf__V920 = ALLOCA_BUFFER(sink__V875->context);
                          USE(buf__V920, x__V917); arg__V919 = BUFFER_TERM(buf__V920); FREE_BUFFER(buf__V920); }
                        Variable vars__V921[1] = {x__V886};
                        Term args__V922[1] = {arg__V919};
                        struct _SubstitutionFrame substitution__V923 = {NULL, 0, 1, vars__V921, args__V922, NULL};
                        SUBSTITUTE(sink__V875, sub__V887, &substitution__V923); }
                       }
                    END(sink__V875, _M_SplitMapText_s1); }
                  END(sink__V875, _M_AsText); }
                END(sink__V875, _M__sTextEmbed); }
              { START(sink__V875, _M__sTextNil);
                END(sink__V875, _M__sTextNil); }
              END(sink__V875, _M__sTextCons); }
            END(sink__V875, _M__sTextCons); }
          END(sink__V875, _M__sTextCons); }
         }
      else { { int test__V924;
          FORCE(sink__V875->context, sub__V881);
          FORCE(sink__V875->context, sub__V883);
          test__V924 = (int) !strcmp(SYMBOL(sub__V881),SYMBOL(sub__V883));
          if (test__V924) {  UNLINK(sink__V875->context, sub__V881); { START(sink__V875, _M__sTextCons);
              { START(sink__V875, _M__sTextEmbed);
                { START(sink__V875, _M_AsText);
                  {
                    Term arg__V925;
                    { Sink buf__V926 = ALLOCA_BUFFER(sink__V875->context);
                      COPY(buf__V926, LINK(buf__V926->context, sub__V882));arg__V925 = BUFFER_TERM(buf__V926); FREE_BUFFER(buf__V926); }
                    Variable vars__V927[1] = {x__V886};
                    Term args__V928[1] = {arg__V925};
                    struct _SubstitutionFrame substitution__V929 = {NULL, 0, 1, vars__V927, args__V928, NULL};
                    SUBSTITUTE(sink__V875, LINK(sink__V875->context,sub__V887), &substitution__V929); }
                  END(sink__V875, _M_AsText); }
                END(sink__V875, _M__sTextEmbed); }
              { START(sink__V875, _M__sTextCons);
                { START(sink__V875, _M__sTextEmbed);
                  { START(sink__V875, _M_AsText);
                    { START(sink__V875, _M_SplitMapText_s1);
                      { START(sink__V875, _M__sCons);
                        COPY(sink__V875, sub__V877);COPY(sink__V875, sub__V878);END(sink__V875, _M__sCons); }
                      { Variable x__V930 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V875->context,"x__V930");
                        Variable binds__V931[1] = {x__V930}; BINDS(sink__V875, 1, binds__V931);
                        {
                          Term arg__V932;
                          { Sink buf__V933 = ALLOCA_BUFFER(sink__V875->context);
                            USE(buf__V933, x__V930); arg__V932 = BUFFER_TERM(buf__V933); FREE_BUFFER(buf__V933); }
                          Variable vars__V934[1] = {x__V879};
                          Term args__V935[1] = {arg__V932};
                          struct _SubstitutionFrame substitution__V936 = {NULL, 0, 1, vars__V934, args__V935, NULL};
                          SUBSTITUTE(sink__V875, sub__V880, &substitution__V936); }
                         }
                      LITERAL(sink__V875,  "0" ); { double num__V937;
                        num__V937 = DOUBLE(sub__V882); { double tmp__V938;
                          tmp__V938 = (double) 1; num__V937 += tmp__V938; }
                        LITERALNF(sink__V875, (size_t) 31, "%G", num__V937); }
                      COPY(sink__V875, sub__V883);{ Variable x__V939 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V875->context,"x__V939");
                        Variable binds__V940[1] = {x__V939}; BINDS(sink__V875, 1, binds__V940);
                        {
                          Term arg__V941;
                          { Sink buf__V942 = ALLOCA_BUFFER(sink__V875->context);
                            USE(buf__V942, x__V939); arg__V941 = BUFFER_TERM(buf__V942); FREE_BUFFER(buf__V942); }
                          Variable vars__V943[1] = {x__V884};
                          Term args__V944[1] = {arg__V941};
                          struct _SubstitutionFrame substitution__V945 = {NULL, 0, 1, vars__V943, args__V944, NULL};
                          SUBSTITUTE(sink__V875, sub__V885, &substitution__V945); }
                         }
                      { Variable x__V946 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V875->context,"x__V946");
                        Variable binds__V947[1] = {x__V946}; BINDS(sink__V875, 1, binds__V947);
                        {
                          Term arg__V948;
                          { Sink buf__V949 = ALLOCA_BUFFER(sink__V875->context);
                            USE(buf__V949, x__V946); arg__V948 = BUFFER_TERM(buf__V949); FREE_BUFFER(buf__V949); }
                          Variable vars__V950[1] = {x__V886};
                          Term args__V951[1] = {arg__V948};
                          struct _SubstitutionFrame substitution__V952 = {NULL, 0, 1, vars__V950, args__V951, NULL};
                          SUBSTITUTE(sink__V875, sub__V887, &substitution__V952); }
                         }
                      END(sink__V875, _M_SplitMapText_s1); }
                    END(sink__V875, _M_AsText); }
                  END(sink__V875, _M__sTextEmbed); }
                { START(sink__V875, _M__sTextNil);
                  END(sink__V875, _M__sTextNil); }
                END(sink__V875, _M__sTextCons); }
              END(sink__V875, _M__sTextCons); }
             }
          else { { START(sink__V875, _M__sTextCons);
              { START(sink__V875, _M__sTextEmbed);
                { START(sink__V875, _M_AsText);
                  {
                    Term arg__V953;
                    { Sink buf__V954 = ALLOCA_BUFFER(sink__V875->context);
                      COPY(buf__V954, sub__V877);arg__V953 = BUFFER_TERM(buf__V954); FREE_BUFFER(buf__V954); }
                    Variable vars__V955[1] = {x__V879};
                    Term args__V956[1] = {arg__V953};
                    struct _SubstitutionFrame substitution__V957 = {NULL, 0, 1, vars__V955, args__V956, NULL};
                    SUBSTITUTE(sink__V875, LINK(sink__V875->context,sub__V880), &substitution__V957); }
                  END(sink__V875, _M_AsText); }
                END(sink__V875, _M__sTextEmbed); }
              { START(sink__V875, _M__sTextCons);
                { START(sink__V875, _M__sTextEmbed);
                  { START(sink__V875, _M_AsText);
                    { START(sink__V875, _M_SplitMapText_s1);
                      COPY(sink__V875, sub__V878);{ Variable x__V958 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V875->context,"x__V958");
                        Variable binds__V959[1] = {x__V958}; BINDS(sink__V875, 1, binds__V959);
                        {
                          Term arg__V960;
                          { Sink buf__V961 = ALLOCA_BUFFER(sink__V875->context);
                            USE(buf__V961, x__V958); arg__V960 = BUFFER_TERM(buf__V961); FREE_BUFFER(buf__V961); }
                          Variable vars__V962[1] = {x__V879};
                          Term args__V963[1] = {arg__V960};
                          struct _SubstitutionFrame substitution__V964 = {NULL, 0, 1, vars__V962, args__V963, NULL};
                          SUBSTITUTE(sink__V875, sub__V880, &substitution__V964); }
                         }
                      { double num__V965;
                        num__V965 = DOUBLE(sub__V881); { double tmp__V966;
                          tmp__V966 = (double) 1; num__V965 += tmp__V966; }
                        LITERALNF(sink__V875, (size_t) 31, "%G", num__V965); }
                      COPY(sink__V875, sub__V882);COPY(sink__V875, sub__V883);{ Variable x__V967 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V875->context,"x__V967");
                        Variable binds__V968[1] = {x__V967}; BINDS(sink__V875, 1, binds__V968);
                        {
                          Term arg__V969;
                          { Sink buf__V970 = ALLOCA_BUFFER(sink__V875->context);
                            USE(buf__V970, x__V967); arg__V969 = BUFFER_TERM(buf__V970); FREE_BUFFER(buf__V970); }
                          Variable vars__V971[1] = {x__V884};
                          Term args__V972[1] = {arg__V969};
                          struct _SubstitutionFrame substitution__V973 = {NULL, 0, 1, vars__V971, args__V972, NULL};
                          SUBSTITUTE(sink__V875, sub__V885, &substitution__V973); }
                         }
                      { Variable x__V974 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V875->context,"x__V974");
                        Variable binds__V975[1] = {x__V974}; BINDS(sink__V875, 1, binds__V975);
                        {
                          Term arg__V976;
                          { Sink buf__V977 = ALLOCA_BUFFER(sink__V875->context);
                            USE(buf__V977, x__V974); arg__V976 = BUFFER_TERM(buf__V977); FREE_BUFFER(buf__V977); }
                          Variable vars__V978[1] = {x__V886};
                          Term args__V979[1] = {arg__V976};
                          struct _SubstitutionFrame substitution__V980 = {NULL, 0, 1, vars__V978, args__V979, NULL};
                          SUBSTITUTE(sink__V875, sub__V887, &substitution__V980); }
                         }
                      END(sink__V875, _M_SplitMapText_s1); }
                    END(sink__V875, _M_AsText); }
                  END(sink__V875, _M__sTextEmbed); }
                { START(sink__V875, _M__sTextNil);
                  END(sink__V875, _M__sTextNil); }
                END(sink__V875, _M__sTextCons); }
              END(sink__V875, _M__sTextCons); }
             }
        }
         }
    }
    UNLINK_VARIABLESET(sink__V875->context, namedFV__V890); UNLINK_VARIABLESET(sink__V875->context, varFV__V891);
    UNLINK_NamedPropertyLink(sink__V875->context, namedP__V888); UNLINK_VariablePropertyLink(sink__V875->context, varP__V889);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION SplitMapText$3. */
int conBindOffs_M_SplitMapText_s3[] = {0 , 1 , 1 , 1 , 1 , 2 , 3};
char *nameFun_M_SplitMapText_s3(Term term) { return  "SplitMapText$3" ; }
struct _ConstructionDescriptor descriptor_M_SplitMapText_s3 = {&sort_M_Reified_xVariable, 0, 6, sizeof(STRUCT_Con_M_SplitMapText_s3), conBindOffs_M_SplitMapText_s3, &nameFun_M_SplitMapText_s3, &step_M_SplitMapText_s3};

int step_M_SplitMapText_s3(Sink sink__V981, Term term__V982)
{
  int term__V982_count = LINK_COUNT(term__V982); permitUnusedInt(term__V982_count);
  do {
    /* Contraction rule DEFS-SplitMapText-2. */
    ASSERT(sink__V981->context, !strcmp(SYMBOL(term__V982),  "SplitMapText$3" ));
    Variable x__V983 = BINDER(term__V982,0,0); if (term__V982_count <= 1) UNBIND(x__V983);
    Term sub__V984 = SUB(term__V982, 0); permitUnusedTerm(sub__V984); int sub__V984_count = term__V982_count*LINK_COUNT(sub__V984); permitUnusedInt(sub__V984_count);
    CRSX_CHECK_SORT(sink__V981->context, sub__V984, &sort_M_Reified_xVariable); /* sub__V984 = &#1 */
    Term sub__V985 = SUB(term__V982, 1); permitUnusedTerm(sub__V985); int sub__V985_count = term__V982_count*LINK_COUNT(sub__V985); permitUnusedInt(sub__V985_count);
    /* sub__V985 = &#3 */
    Term sub__V986 = LINK(sink__V981->context, SUB(term__V982, 2)); int sub__V986_count = term__V982_count*LINK_COUNT(sub__V986); permitUnusedInt(sub__V986_count);
    UNLINK_SUB(sink__V981->context, term__V982,  2); NORMALIZE(sink__V981->context, sub__V986); SUB(term__V982,  2) = LINK(sink__V981->context, sub__V986);
    /* sub__V986 = &#4 */
    Term sub__V987 = SUB(term__V982, 3); permitUnusedTerm(sub__V987); int sub__V987_count = term__V982_count*LINK_COUNT(sub__V987); permitUnusedInt(sub__V987_count);
    /* sub__V987 = &#5 */
    Variable x__V988 = BINDER(term__V982,4,0); if (term__V982_count <= 1) UNBIND(x__V988);
    Term sub__V989 = SUB(term__V982, 4); permitUnusedTerm(sub__V989); int sub__V989_count = term__V982_count*LINK_COUNT(sub__V989); permitUnusedInt(sub__V989_count);
    CRSX_CHECK_SORT(sink__V981->context, sub__V989, &sort_M_Reified_xVariable); /* sub__V989 = &#6 */
    Variable x__V990 = BINDER(term__V982,5,0); if (term__V982_count <= 1) UNBIND(x__V990);
    Term sub__V991 = LINK(sink__V981->context, SUB(term__V982, 5)); int sub__V991_count = term__V982_count*LINK_COUNT(sub__V991); permitUnusedInt(sub__V991_count);
    CRSX_CHECK_SORT(sink__V981->context, sub__V991, &sort_M_Reified_xVariable); /* sub__V991 = &#7 */
    
    NamedPropertyLink namedP__V992 = LINK_NamedPropertyLink(sink__V981->context, NAMED_PROPERTIES(term__V982));
    VariablePropertyLink varP__V993 = LINK_VariablePropertyLink(sink__V981->context, VARIABLE_PROPERTIES(term__V982));
    Hashset namedFV__V994 = LINK_VARIABLESET(sink__V981->context, namedPropertyFreeVars(namedP__V992));
    Hashset varFV__V995 = LINK_VARIABLESET(sink__V981->context, variablePropertyFreeVars(varP__V993));
    UNLINK(sink__V981->context, term__V982);
    {
      Term arg__V996;
      { Sink buf__V997 = ALLOCA_BUFFER(sink__V981->context);
        COPY(buf__V997, sub__V986);arg__V996 = BUFFER_TERM(buf__V997); FREE_BUFFER(buf__V997); }
      Variable vars__V998[1] = {x__V990};
      Term args__V999[1] = {arg__V996};
      struct _SubstitutionFrame substitution__V1000 = {NULL, 0, 1, vars__V998, args__V999, NULL};
      SUBSTITUTE(sink__V981, sub__V991, &substitution__V1000); }
    UNLINK_VARIABLESET(sink__V981->context, namedFV__V994); UNLINK_VARIABLESET(sink__V981->context, varFV__V995);
    UNLINK_NamedPropertyLink(sink__V981->context, namedP__V992); UNLINK_VariablePropertyLink(sink__V981->context, varP__V993);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION INTEGER. */
int conBindOffs_M_INTEGER[] = {0 , 0};
char *nameFun_M_INTEGER(Term term) { return  "INTEGER" ; }
struct _ConstructionDescriptor descriptor_M_INTEGER = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_INTEGER), conBindOffs_M_INTEGER, &nameFun_M_INTEGER, &step_M_INTEGER};

int step_M_INTEGER(Sink sink__V1001, Term term__V1002)
{
  int term__V1002_count = LINK_COUNT(term__V1002); permitUnusedInt(term__V1002_count);
  do {
    /* Contraction rule DEFS-INTEGER-1. */
    ASSERT(sink__V1001->context, !strcmp(SYMBOL(term__V1002),  "INTEGER" ));
    Term sub__V1003 = LINK(sink__V1001->context, SUB(term__V1002, 0)); int sub__V1003_count = term__V1002_count*LINK_COUNT(sub__V1003); permitUnusedInt(sub__V1003_count);
    UNLINK_SUB(sink__V1001->context, term__V1002,  0); NORMALIZE(sink__V1001->context, sub__V1003); SUB(term__V1002,  0) = LINK(sink__V1001->context, sub__V1003);
    /* sub__V1003 = &#1 */
    
    NamedPropertyLink namedP__V1004 = LINK_NamedPropertyLink(sink__V1001->context, NAMED_PROPERTIES(term__V1002));
    VariablePropertyLink varP__V1005 = LINK_VariablePropertyLink(sink__V1001->context, VARIABLE_PROPERTIES(term__V1002));
    Hashset namedFV__V1006 = LINK_VARIABLESET(sink__V1001->context, namedPropertyFreeVars(namedP__V1004));
    Hashset varFV__V1007 = LINK_VARIABLESET(sink__V1001->context, variablePropertyFreeVars(varP__V1005));
    UNLINK(sink__V1001->context, term__V1002);
    { START(sink__V1001, _M__sTextCons);
      { START(sink__V1001, _M__sTextChars);
        { char *str__V1008;
          {double num__V1009; char *str__V1010;
            num__V1009 = DOUBLE(sub__V1003); snprintf(str__V1010 = ALLOCA(sink__V1001->context, (size_t) 32), (size_t) 31, "%G", num__V1009);
            { size_t z__V1011 = strlen(str__V1010) + 1; memcpy(str__V1008 = ALLOCATE(sink__V1001->context, z__V1011), str__V1010, z__V1011); }
             }
          LITERALU(sink__V1001, str__V1008); }
        END(sink__V1001, _M__sTextChars); }
      { START(sink__V1001, _M__sTextNil);
        END(sink__V1001, _M__sTextNil); }
      END(sink__V1001, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V1001->context, namedFV__V1006); UNLINK_VARIABLESET(sink__V1001->context, varFV__V1007);
    UNLINK_NamedPropertyLink(sink__V1001->context, namedP__V1004); UNLINK_VariablePropertyLink(sink__V1001->context, varP__V1005);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION EventConstructor. */
int conBindOffs_M_EventConstructor[] = {0 , 0};
char *nameFun_M_EventConstructor(Term term) { return  "EventConstructor" ; }
struct _ConstructionDescriptor descriptor_M_EventConstructor = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_EventConstructor), conBindOffs_M_EventConstructor, &nameFun_M_EventConstructor, &step_M_EventConstructor};

int step_M_EventConstructor(Sink sink__V1012, Term term__V1013)
{
  int term__V1013_count = LINK_COUNT(term__V1013); permitUnusedInt(term__V1013_count);
  do {
    /* Contraction rule DEFS-EventConstructor-1. */
    ASSERT(sink__V1012->context, !strcmp(SYMBOL(term__V1013),  "EventConstructor" ));
    Term sub__V1014 = LINK(sink__V1012->context, SUB(term__V1013, 0)); int sub__V1014_count = term__V1013_count*LINK_COUNT(sub__V1014); permitUnusedInt(sub__V1014_count);
    /* sub__V1014 = &#1 */
    
    NamedPropertyLink namedP__V1015 = LINK_NamedPropertyLink(sink__V1012->context, NAMED_PROPERTIES(term__V1013));
    VariablePropertyLink varP__V1016 = LINK_VariablePropertyLink(sink__V1012->context, VARIABLE_PROPERTIES(term__V1013));
    Hashset namedFV__V1017 = LINK_VARIABLESET(sink__V1012->context, namedPropertyFreeVars(namedP__V1015));
    Hashset varFV__V1018 = LINK_VARIABLESET(sink__V1012->context, variablePropertyFreeVars(varP__V1016));
    UNLINK(sink__V1012->context, term__V1013);
    { START(sink__V1012, _M_MANGLE);
      COPY(sink__V1012, sub__V1014);END(sink__V1012, _M_MANGLE); }
    UNLINK_VARIABLESET(sink__V1012->context, namedFV__V1017); UNLINK_VARIABLESET(sink__V1012->context, varFV__V1018);
    UNLINK_NamedPropertyLink(sink__V1012->context, namedP__V1015); UNLINK_VariablePropertyLink(sink__V1012->context, varP__V1016);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION SortInternals. */
int conBindOffs_M_SortInternals[] = {0 , 0};
char *nameFun_M_SortInternals(Term term) { return  "SortInternals" ; }
struct _ConstructionDescriptor descriptor_M_SortInternals = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_SortInternals), conBindOffs_M_SortInternals, &nameFun_M_SortInternals, &step_M_SortInternals};

int step_M_SortInternals(Sink sink__V1019, Term term__V1020)
{
  int term__V1020_count = LINK_COUNT(term__V1020); permitUnusedInt(term__V1020_count);
  do {
    /* Contraction rule DEFS-SortInternals-1. */
    ASSERT(sink__V1019->context, !strcmp(SYMBOL(term__V1020),  "SortInternals" ));
    Term sub__V1021 = LINK(sink__V1019->context, SUB(term__V1020, 0)); int sub__V1021_count = term__V1020_count*LINK_COUNT(sub__V1021); permitUnusedInt(sub__V1021_count);
    /* sub__V1021 = &#1 */
    
    NamedPropertyLink namedP__V1022 = LINK_NamedPropertyLink(sink__V1019->context, NAMED_PROPERTIES(term__V1020));
    VariablePropertyLink varP__V1023 = LINK_VariablePropertyLink(sink__V1019->context, VARIABLE_PROPERTIES(term__V1020));
    Hashset namedFV__V1024 = LINK_VARIABLESET(sink__V1019->context, namedPropertyFreeVars(namedP__V1022));
    Hashset varFV__V1025 = LINK_VARIABLESET(sink__V1019->context, variablePropertyFreeVars(varP__V1023));
    UNLINK(sink__V1019->context, term__V1020);
    { START(sink__V1019, _M__sTextCons);
      { START(sink__V1019, _M__sTextChars);
        LITERAL(sink__V1019,  "sortInt" ); END(sink__V1019, _M__sTextChars); }
      { START(sink__V1019, _M__sTextCons);
        { START(sink__V1019, _M__sTextEmbed);
          { START(sink__V1019, _M_AsText);
            { START(sink__V1019, _M_MANGLE);
              COPY(sink__V1019, sub__V1021);END(sink__V1019, _M_MANGLE); }
            END(sink__V1019, _M_AsText); }
          END(sink__V1019, _M__sTextEmbed); }
        { START(sink__V1019, _M__sTextNil);
          END(sink__V1019, _M__sTextNil); }
        END(sink__V1019, _M__sTextCons); }
      END(sink__V1019, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V1019->context, namedFV__V1024); UNLINK_VARIABLESET(sink__V1019->context, varFV__V1025);
    UNLINK_NamedPropertyLink(sink__V1019->context, namedP__V1022); UNLINK_VariablePropertyLink(sink__V1019->context, varP__V1023);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION SortCons. */
int conBindOffs_M_SortCons[] = {0 , 0};
char *nameFun_M_SortCons(Term term) { return  "SortCons" ; }
struct _ConstructionDescriptor descriptor_M_SortCons = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_SortCons), conBindOffs_M_SortCons, &nameFun_M_SortCons, &step_M_SortCons};

int step_M_SortCons(Sink sink__V1026, Term term__V1027)
{
  int term__V1027_count = LINK_COUNT(term__V1027); permitUnusedInt(term__V1027_count);
  do {
    /* Contraction rule DEFS-SortCons-1. */
    ASSERT(sink__V1026->context, !strcmp(SYMBOL(term__V1027),  "SortCons" ));
    Term sub__V1028 = LINK(sink__V1026->context, SUB(term__V1027, 0)); int sub__V1028_count = term__V1027_count*LINK_COUNT(sub__V1028); permitUnusedInt(sub__V1028_count);
    /* sub__V1028 = &#1 */
    
    NamedPropertyLink namedP__V1029 = LINK_NamedPropertyLink(sink__V1026->context, NAMED_PROPERTIES(term__V1027));
    VariablePropertyLink varP__V1030 = LINK_VariablePropertyLink(sink__V1026->context, VARIABLE_PROPERTIES(term__V1027));
    Hashset namedFV__V1031 = LINK_VARIABLESET(sink__V1026->context, namedPropertyFreeVars(namedP__V1029));
    Hashset varFV__V1032 = LINK_VARIABLESET(sink__V1026->context, variablePropertyFreeVars(varP__V1030));
    UNLINK(sink__V1026->context, term__V1027);
    { START(sink__V1026, _M__sTextCons);
      { START(sink__V1026, _M__sTextChars);
        LITERAL(sink__V1026,  "sortCon" ); END(sink__V1026, _M__sTextChars); }
      { START(sink__V1026, _M__sTextCons);
        { START(sink__V1026, _M__sTextEmbed);
          { START(sink__V1026, _M_AsText);
            { START(sink__V1026, _M_MANGLE);
              COPY(sink__V1026, sub__V1028);END(sink__V1026, _M_MANGLE); }
            END(sink__V1026, _M_AsText); }
          END(sink__V1026, _M__sTextEmbed); }
        { START(sink__V1026, _M__sTextNil);
          END(sink__V1026, _M__sTextNil); }
        END(sink__V1026, _M__sTextCons); }
      END(sink__V1026, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V1026->context, namedFV__V1031); UNLINK_VARIABLESET(sink__V1026->context, varFV__V1032);
    UNLINK_NamedPropertyLink(sink__V1026->context, namedP__V1029); UNLINK_VariablePropertyLink(sink__V1026->context, varP__V1030);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DINTEGER$1. */
int conBindOffs_M_DINTEGER_s1[] = {0 , 0};
char *nameFun_M_DINTEGER_s1(Term term) { return  "DINTEGER$1" ; }
struct _ConstructionDescriptor descriptor_M_DINTEGER_s1 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_DINTEGER_s1), conBindOffs_M_DINTEGER_s1, &nameFun_M_DINTEGER_s1, &step_M_DINTEGER_s1};

int step_M_DINTEGER_s1(Sink sink__V1033, Term term__V1034)
{
  int term__V1034_count = LINK_COUNT(term__V1034); permitUnusedInt(term__V1034_count);
  do {
    /* Contraction rule DEFS-DINTEGER-1. */
    ASSERT(sink__V1033->context, !strcmp(SYMBOL(term__V1034),  "DINTEGER$1" ));
    Term sub__V1035 = LINK(sink__V1033->context, SUB(term__V1034, 0)); int sub__V1035_count = term__V1034_count*LINK_COUNT(sub__V1035); permitUnusedInt(sub__V1035_count);
    UNLINK_SUB(sink__V1033->context, term__V1034,  0); NORMALIZE(sink__V1033->context, sub__V1035); SUB(term__V1034,  0) = LINK(sink__V1033->context, sub__V1035);
    /* sub__V1035 = &#2 */
    
    NamedPropertyLink namedP__V1036 = LINK_NamedPropertyLink(sink__V1033->context, NAMED_PROPERTIES(term__V1034));
    VariablePropertyLink varP__V1037 = LINK_VariablePropertyLink(sink__V1033->context, VARIABLE_PROPERTIES(term__V1034));
    Hashset namedFV__V1038 = LINK_VARIABLESET(sink__V1033->context, namedPropertyFreeVars(namedP__V1036));
    Hashset varFV__V1039 = LINK_VARIABLESET(sink__V1033->context, variablePropertyFreeVars(varP__V1037));
    UNLINK(sink__V1033->context, term__V1034);
    { START(sink__V1033, _M__sTextCons);
      { START(sink__V1033, _M__sTextChars);
        { char *str__V1040;
          {double num__V1041; char *str__V1042;
            num__V1041 = DOUBLE(sub__V1035); snprintf(str__V1042 = ALLOCA(sink__V1033->context, (size_t) 32), (size_t) 31, "%G", num__V1041);
            { size_t z__V1043 = strlen(str__V1042) + 1; memcpy(str__V1040 = ALLOCATE(sink__V1033->context, z__V1043), str__V1042, z__V1043); }
             }
          LITERALU(sink__V1033, str__V1040); }
        END(sink__V1033, _M__sTextChars); }
      { START(sink__V1033, _M__sTextNil);
        END(sink__V1033, _M__sTextNil); }
      END(sink__V1033, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V1033->context, namedFV__V1038); UNLINK_VARIABLESET(sink__V1033->context, varFV__V1039);
    UNLINK_NamedPropertyLink(sink__V1033->context, namedP__V1036); UNLINK_VariablePropertyLink(sink__V1033->context, varP__V1037);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Name. */
int conBindOffs_M_Name[] = {0 , 0};
char *nameFun_M_Name(Term term) { return  "Name" ; }
struct _ConstructionDescriptor descriptor_M_Name = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_Name), conBindOffs_M_Name, &nameFun_M_Name, &step_M_Name};

int step_M_Name(Sink sink__V1044, Term term__V1045)
{
  int term__V1045_count = LINK_COUNT(term__V1045); permitUnusedInt(term__V1045_count);
  do {
    /* Contraction rule DEFS-Name-1. */
    ASSERT(sink__V1044->context, !strcmp(SYMBOL(term__V1045),  "Name" ));
    Term sub__V1046 = LINK(sink__V1044->context, SUB(term__V1045, 0)); int sub__V1046_count = term__V1045_count*LINK_COUNT(sub__V1046); permitUnusedInt(sub__V1046_count);
    /* sub__V1046 = &#1 */
    
    NamedPropertyLink namedP__V1047 = LINK_NamedPropertyLink(sink__V1044->context, NAMED_PROPERTIES(term__V1045));
    VariablePropertyLink varP__V1048 = LINK_VariablePropertyLink(sink__V1044->context, VARIABLE_PROPERTIES(term__V1045));
    Hashset namedFV__V1049 = LINK_VARIABLESET(sink__V1044->context, namedPropertyFreeVars(namedP__V1047));
    Hashset varFV__V1050 = LINK_VARIABLESET(sink__V1044->context, variablePropertyFreeVars(varP__V1048));
    UNLINK(sink__V1044->context, term__V1045);
    { START(sink__V1044, _M__sTextCons);
      { START(sink__V1044, _M__sTextChars);
        LITERAL(sink__V1044,  "name" ); END(sink__V1044, _M__sTextChars); }
      { START(sink__V1044, _M__sTextCons);
        { START(sink__V1044, _M__sTextEmbed);
          { START(sink__V1044, _M_AsText);
            { START(sink__V1044, _M_MANGLE);
              COPY(sink__V1044, sub__V1046);END(sink__V1044, _M_MANGLE); }
            END(sink__V1044, _M_AsText); }
          END(sink__V1044, _M__sTextEmbed); }
        { START(sink__V1044, _M__sTextNil);
          END(sink__V1044, _M__sTextNil); }
        END(sink__V1044, _M__sTextCons); }
      END(sink__V1044, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V1044->context, namedFV__V1049); UNLINK_VARIABLESET(sink__V1044->context, varFV__V1050);
    UNLINK_NamedPropertyLink(sink__V1044->context, namedP__V1047); UNLINK_VariablePropertyLink(sink__V1044->context, varP__V1048);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION EnumTag. */
int conBindOffs_M_EnumTag[] = {0 , 0};
char *nameFun_M_EnumTag(Term term) { return  "EnumTag" ; }
struct _ConstructionDescriptor descriptor_M_EnumTag = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_EnumTag), conBindOffs_M_EnumTag, &nameFun_M_EnumTag, &step_M_EnumTag};

int step_M_EnumTag(Sink sink__V1051, Term term__V1052)
{
  int term__V1052_count = LINK_COUNT(term__V1052); permitUnusedInt(term__V1052_count);
  do {
    /* Contraction rule DEFS-EnumTag-1. */
    ASSERT(sink__V1051->context, !strcmp(SYMBOL(term__V1052),  "EnumTag" ));
    Term sub__V1053 = LINK(sink__V1051->context, SUB(term__V1052, 0)); int sub__V1053_count = term__V1052_count*LINK_COUNT(sub__V1053); permitUnusedInt(sub__V1053_count);
    /* sub__V1053 = &#1 */
    
    NamedPropertyLink namedP__V1054 = LINK_NamedPropertyLink(sink__V1051->context, NAMED_PROPERTIES(term__V1052));
    VariablePropertyLink varP__V1055 = LINK_VariablePropertyLink(sink__V1051->context, VARIABLE_PROPERTIES(term__V1052));
    Hashset namedFV__V1056 = LINK_VARIABLESET(sink__V1051->context, namedPropertyFreeVars(namedP__V1054));
    Hashset varFV__V1057 = LINK_VARIABLESET(sink__V1051->context, variablePropertyFreeVars(varP__V1055));
    UNLINK(sink__V1051->context, term__V1052);
    { START(sink__V1051, _M__sTextCons);
      { START(sink__V1051, _M__sTextChars);
        LITERAL(sink__V1051,  "Data" ); END(sink__V1051, _M__sTextChars); }
      { START(sink__V1051, _M__sTextCons);
        { START(sink__V1051, _M__sTextEmbed);
          { START(sink__V1051, _M_AsText);
            { START(sink__V1051, _M_MANGLE);
              COPY(sink__V1051, sub__V1053);END(sink__V1051, _M_MANGLE); }
            END(sink__V1051, _M_AsText); }
          END(sink__V1051, _M__sTextEmbed); }
        { START(sink__V1051, _M__sTextNil);
          END(sink__V1051, _M__sTextNil); }
        END(sink__V1051, _M__sTextCons); }
      END(sink__V1051, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V1051->context, namedFV__V1056); UNLINK_VARIABLESET(sink__V1051->context, varFV__V1057);
    UNLINK_NamedPropertyLink(sink__V1051->context, namedP__V1054); UNLINK_VariablePropertyLink(sink__V1051->context, varP__V1055);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION MapText$1. */
int conBindOffs_M_MapText_s1[] = {0 , 0 , 1};
char *nameFun_M_MapText_s1(Term term) { return  "MapText$1" ; }
struct _ConstructionDescriptor descriptor_M_MapText_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_MapText_s1), conBindOffs_M_MapText_s1, &nameFun_M_MapText_s1, &step_M_MapText_s1};

int step_M_MapText_s1(Sink sink__V1058, Term term__V1059)
{
  int term__V1059_count = LINK_COUNT(term__V1059); permitUnusedInt(term__V1059_count);
  Term sub__V1060 = FORCE(sink__V1058->context, SUB(term__V1059, 0));
  EnumOf_M__sList choice__V1061 = (IS_VARIABLE_USE(sub__V1060) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V1060));
  switch (choice__V1061)
  {
    case Data_M__sCons: { /* Function DEFS-MapText-1$MapText$1$$Cons case $Cons */
      ASSERT(sink__V1058->context, !strcmp(SYMBOL(term__V1059),  "MapText$1" ));
      Term sub__V1062 = SUB(term__V1059, 0); permitUnusedTerm(sub__V1062); int sub__V1062_count = term__V1059_count*LINK_COUNT(sub__V1062); permitUnusedInt(sub__V1062_count);
      ASSERT(sink__V1058->context, !strcmp(SYMBOL(sub__V1062),  "$Cons" ));
      Term sub__V1063 = LINK(sink__V1058->context, SUB(sub__V1062, 0)); int sub__V1063_count = sub__V1062_count*LINK_COUNT(sub__V1063); permitUnusedInt(sub__V1063_count);
      /* sub__V1063 = &#0-0 */
      Term sub__V1064 = LINK(sink__V1058->context, SUB(sub__V1062, 1)); int sub__V1064_count = sub__V1062_count*LINK_COUNT(sub__V1064); permitUnusedInt(sub__V1064_count);
      /* sub__V1064 = &#0-1 */
      Variable x__V1065 = BINDER(term__V1059,1,0); if (term__V1059_count <= 1) UNBIND(x__V1065);
      Term sub__V1066 = LINK(sink__V1058->context, SUB(term__V1059, 1)); int sub__V1066_count = term__V1059_count*LINK_COUNT(sub__V1066); permitUnusedInt(sub__V1066_count);
      CRSX_CHECK_SORT(sink__V1058->context, sub__V1066, &sort_M_Reified_xVariable); /* sub__V1066 = &#2 */
      
      NamedPropertyLink namedP__V1067 = LINK_NamedPropertyLink(sink__V1058->context, NAMED_PROPERTIES(term__V1059));
      VariablePropertyLink varP__V1068 = LINK_VariablePropertyLink(sink__V1058->context, VARIABLE_PROPERTIES(term__V1059));
      Hashset namedFV__V1069 = LINK_VARIABLESET(sink__V1058->context, namedPropertyFreeVars(namedP__V1067));
      Hashset varFV__V1070 = LINK_VARIABLESET(sink__V1058->context, variablePropertyFreeVars(varP__V1068));
      UNLINK(sink__V1058->context, term__V1059);
      ADD_PROPERTIES(sink__V1058, LINK_VARIABLESET(sink__V1058->context, namedFV__V1069), LINK_VARIABLESET(sink__V1058->context, varFV__V1070), LINK_NamedPropertyLink(sink__V1058->context, namedP__V1067), LINK_VariablePropertyLink(sink__V1058->context, varP__V1068));
      { START(sink__V1058, _M_MapText_s2);
        COPY(sink__V1058, sub__V1063);COPY(sink__V1058, sub__V1064);{ if (!IS_BOUND(x__V1065)) { REBIND(x__V1065);
            Variable binds__V1071[1] = {x__V1065}; BINDS(sink__V1058, 1, binds__V1071);
            COPY(sink__V1058, sub__V1066); /* REUSED SUBSTITUTION */  }
          else { Variable b__V1072 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V1058->context,"b__V1072");
            Variable binds__V1073[1] = {b__V1072}; BINDS(sink__V1058, 1, binds__V1073);
            {
              Term arg__V1074;
              { Sink buf__V1075 = ALLOCA_BUFFER(sink__V1058->context);
                USE(buf__V1075, b__V1072); arg__V1074 = BUFFER_TERM(buf__V1075); FREE_BUFFER(buf__V1075); }
              Variable vars__V1076[1] = {x__V1065};
              Term args__V1077[1] = {arg__V1074};
              struct _SubstitutionFrame substitution__V1078 = {NULL, 0, 1, vars__V1076, args__V1077, NULL};
              SUBSTITUTE(sink__V1058, sub__V1066, &substitution__V1078); }
                }
           }
        END(sink__V1058, _M_MapText_s2); }
      UNLINK_VARIABLESET(sink__V1058->context, namedFV__V1069); UNLINK_VARIABLESET(sink__V1058->context, varFV__V1070);
      UNLINK_NamedPropertyLink(sink__V1058->context, namedP__V1067); UNLINK_VariablePropertyLink(sink__V1058->context, varP__V1068);
      
      return 1;
    break; } case Data_M__sNil: { /* Function DEFS-MapText-2$MapText$1$$Nil case $Nil */
      ASSERT(sink__V1058->context, !strcmp(SYMBOL(term__V1059),  "MapText$1" ));
      Term sub__V1079 = SUB(term__V1059, 0); permitUnusedTerm(sub__V1079); int sub__V1079_count = term__V1059_count*LINK_COUNT(sub__V1079); permitUnusedInt(sub__V1079_count);
      ASSERT(sink__V1058->context, !strcmp(SYMBOL(sub__V1079),  "$Nil" ));
      Variable x__V1080 = BINDER(term__V1059,1,0); if (term__V1059_count <= 1) UNBIND(x__V1080);
      Term sub__V1081 = LINK(sink__V1058->context, SUB(term__V1059, 1)); int sub__V1081_count = term__V1059_count*LINK_COUNT(sub__V1081); permitUnusedInt(sub__V1081_count);
      CRSX_CHECK_SORT(sink__V1058->context, sub__V1081, &sort_M_Reified_xVariable); /* sub__V1081 = &#0 */
      
      NamedPropertyLink namedP__V1082 = LINK_NamedPropertyLink(sink__V1058->context, NAMED_PROPERTIES(term__V1059));
      VariablePropertyLink varP__V1083 = LINK_VariablePropertyLink(sink__V1058->context, VARIABLE_PROPERTIES(term__V1059));
      Hashset namedFV__V1084 = LINK_VARIABLESET(sink__V1058->context, namedPropertyFreeVars(namedP__V1082));
      Hashset varFV__V1085 = LINK_VARIABLESET(sink__V1058->context, variablePropertyFreeVars(varP__V1083));
      UNLINK(sink__V1058->context, term__V1059);
      ADD_PROPERTIES(sink__V1058, LINK_VARIABLESET(sink__V1058->context, namedFV__V1084), LINK_VARIABLESET(sink__V1058->context, varFV__V1085), LINK_NamedPropertyLink(sink__V1058->context, namedP__V1082), LINK_VariablePropertyLink(sink__V1058->context, varP__V1083));
      { START(sink__V1058, _M_MapText_s3);
        { if (!IS_BOUND(x__V1080)) { REBIND(x__V1080);
            Variable binds__V1086[1] = {x__V1080}; BINDS(sink__V1058, 1, binds__V1086);
            COPY(sink__V1058, sub__V1081); /* REUSED SUBSTITUTION */  }
          else { Variable b__V1087 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V1058->context,"b__V1087");
            Variable binds__V1088[1] = {b__V1087}; BINDS(sink__V1058, 1, binds__V1088);
            {
              Term arg__V1089;
              { Sink buf__V1090 = ALLOCA_BUFFER(sink__V1058->context);
                USE(buf__V1090, b__V1087); arg__V1089 = BUFFER_TERM(buf__V1090); FREE_BUFFER(buf__V1090); }
              Variable vars__V1091[1] = {x__V1080};
              Term args__V1092[1] = {arg__V1089};
              struct _SubstitutionFrame substitution__V1093 = {NULL, 0, 1, vars__V1091, args__V1092, NULL};
              SUBSTITUTE(sink__V1058, sub__V1081, &substitution__V1093); }
                }
           }
        END(sink__V1058, _M_MapText_s3); }
      UNLINK_VARIABLESET(sink__V1058->context, namedFV__V1084); UNLINK_VARIABLESET(sink__V1058->context, varFV__V1085);
      UNLINK_NamedPropertyLink(sink__V1058->context, namedP__V1082); UNLINK_VariablePropertyLink(sink__V1058->context, varP__V1083);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION MapText$2. */
int conBindOffs_M_MapText_s2[] = {0 , 0 , 0 , 1};
char *nameFun_M_MapText_s2(Term term) { return  "MapText$2" ; }
struct _ConstructionDescriptor descriptor_M_MapText_s2 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_MapText_s2), conBindOffs_M_MapText_s2, &nameFun_M_MapText_s2, &step_M_MapText_s2};

int step_M_MapText_s2(Sink sink__V1094, Term term__V1095)
{
  int term__V1095_count = LINK_COUNT(term__V1095); permitUnusedInt(term__V1095_count);
  do {
    /* Contraction rule DEFS-MapText-1. */
    ASSERT(sink__V1094->context, !strcmp(SYMBOL(term__V1095),  "MapText$2" ));
    Term sub__V1096 = LINK(sink__V1094->context, SUB(term__V1095, 0)); int sub__V1096_count = term__V1095_count*LINK_COUNT(sub__V1096); permitUnusedInt(sub__V1096_count);
    /* sub__V1096 = &#21 */
    Term sub__V1097 = LINK(sink__V1094->context, SUB(term__V1095, 1)); int sub__V1097_count = term__V1095_count*LINK_COUNT(sub__V1097); permitUnusedInt(sub__V1097_count);
    /* sub__V1097 = &#22 */
    Variable x__V1098 = BINDER(term__V1095,2,0); if (term__V1095_count <= 1) UNBIND(x__V1098);
    Term sub__V1099 = LINK(sink__V1094->context, SUB(term__V1095, 2)); int sub__V1099_count = term__V1095_count*LINK_COUNT(sub__V1099); permitUnusedInt(sub__V1099_count);
    CRSX_CHECK_SORT(sink__V1094->context, sub__V1099, &sort_M_Reified_xVariable); UNLINK_SUB(sink__V1094->context, term__V1095,  2); NORMALIZE(sink__V1094->context, sub__V1099); SUB(term__V1095,  2) = LINK(sink__V1094->context, sub__V1099);
    /* sub__V1099 = &#1 */
    
    NamedPropertyLink namedP__V1100 = LINK_NamedPropertyLink(sink__V1094->context, NAMED_PROPERTIES(term__V1095));
    VariablePropertyLink varP__V1101 = LINK_VariablePropertyLink(sink__V1094->context, VARIABLE_PROPERTIES(term__V1095));
    Hashset namedFV__V1102 = LINK_VARIABLESET(sink__V1094->context, namedPropertyFreeVars(namedP__V1100));
    Hashset varFV__V1103 = LINK_VARIABLESET(sink__V1094->context, variablePropertyFreeVars(varP__V1101));
    UNLINK(sink__V1094->context, term__V1095);
    { START(sink__V1094, _M__sTextCons);
      { START(sink__V1094, _M__sTextEmbed);
        { START(sink__V1094, _M_AsText);
          {
            Term arg__V1104;
            { Sink buf__V1105 = ALLOCA_BUFFER(sink__V1094->context);
              COPY(buf__V1105, sub__V1096);arg__V1104 = BUFFER_TERM(buf__V1105); FREE_BUFFER(buf__V1105); }
            Variable vars__V1106[1] = {x__V1098};
            Term args__V1107[1] = {arg__V1104};
            struct _SubstitutionFrame substitution__V1108 = {NULL, 0, 1, vars__V1106, args__V1107, NULL};
            SUBSTITUTE(sink__V1094, LINK(sink__V1094->context,sub__V1099), &substitution__V1108); }
          END(sink__V1094, _M_AsText); }
        END(sink__V1094, _M__sTextEmbed); }
      { START(sink__V1094, _M__sTextCons);
        { START(sink__V1094, _M__sTextEmbed);
          { START(sink__V1094, _M_AsText);
            { START(sink__V1094, _M_MapText_s1);
              COPY(sink__V1094, sub__V1097);{ Variable x__V1109 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V1094->context,"x__V1109");
                Variable binds__V1110[1] = {x__V1109}; BINDS(sink__V1094, 1, binds__V1110);
                {
                  Term arg__V1111;
                  { Sink buf__V1112 = ALLOCA_BUFFER(sink__V1094->context);
                    USE(buf__V1112, x__V1109); arg__V1111 = BUFFER_TERM(buf__V1112); FREE_BUFFER(buf__V1112); }
                  Variable vars__V1113[1] = {x__V1098};
                  Term args__V1114[1] = {arg__V1111};
                  struct _SubstitutionFrame substitution__V1115 = {NULL, 0, 1, vars__V1113, args__V1114, NULL};
                  SUBSTITUTE(sink__V1094, sub__V1099, &substitution__V1115); }
                 }
              END(sink__V1094, _M_MapText_s1); }
            END(sink__V1094, _M_AsText); }
          END(sink__V1094, _M__sTextEmbed); }
        { START(sink__V1094, _M__sTextNil);
          END(sink__V1094, _M__sTextNil); }
        END(sink__V1094, _M__sTextCons); }
      END(sink__V1094, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V1094->context, namedFV__V1102); UNLINK_VARIABLESET(sink__V1094->context, varFV__V1103);
    UNLINK_NamedPropertyLink(sink__V1094->context, namedP__V1100); UNLINK_VariablePropertyLink(sink__V1094->context, varP__V1101);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION MapText$3. */
int conBindOffs_M_MapText_s3[] = {0 , 1};
char *nameFun_M_MapText_s3(Term term) { return  "MapText$3" ; }
struct _ConstructionDescriptor descriptor_M_MapText_s3 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_MapText_s3), conBindOffs_M_MapText_s3, &nameFun_M_MapText_s3, &step_M_MapText_s3};

int step_M_MapText_s3(Sink sink__V1116, Term term__V1117)
{
  int term__V1117_count = LINK_COUNT(term__V1117); permitUnusedInt(term__V1117_count);
  do {
    /* Contraction rule DEFS-MapText-2. */
    ASSERT(sink__V1116->context, !strcmp(SYMBOL(term__V1117),  "MapText$3" ));
    Variable x__V1118 = BINDER(term__V1117,0,0); if (term__V1117_count <= 1) UNBIND(x__V1118);
    Term sub__V1119 = SUB(term__V1117, 0); permitUnusedTerm(sub__V1119); int sub__V1119_count = term__V1117_count*LINK_COUNT(sub__V1119); permitUnusedInt(sub__V1119_count);
    CRSX_CHECK_SORT(sink__V1116->context, sub__V1119, &sort_M_Reified_xVariable); /* sub__V1119 = &#1 */
    
    NamedPropertyLink namedP__V1120 = LINK_NamedPropertyLink(sink__V1116->context, NAMED_PROPERTIES(term__V1117));
    VariablePropertyLink varP__V1121 = LINK_VariablePropertyLink(sink__V1116->context, VARIABLE_PROPERTIES(term__V1117));
    Hashset namedFV__V1122 = LINK_VARIABLESET(sink__V1116->context, namedPropertyFreeVars(namedP__V1120));
    Hashset varFV__V1123 = LINK_VARIABLESET(sink__V1116->context, variablePropertyFreeVars(varP__V1121));
    UNLINK(sink__V1116->context, term__V1117);
    { START(sink__V1116, _M__sTextNil);
      END(sink__V1116, _M__sTextNil); }
    UNLINK_VARIABLESET(sink__V1116->context, namedFV__V1122); UNLINK_VARIABLESET(sink__V1116->context, varFV__V1123);
    UNLINK_NamedPropertyLink(sink__V1116->context, namedP__V1120); UNLINK_VariablePropertyLink(sink__V1116->context, varP__V1121);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Var. */
int conBindOffs_M_Var[] = {0 , 0};
char *nameFun_M_Var(Term term) { return  "Var" ; }
struct _ConstructionDescriptor descriptor_M_Var = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_Var), conBindOffs_M_Var, &nameFun_M_Var, &step_M_Var};

int step_M_Var(Sink sink__V1124, Term term__V1125)
{
  int term__V1125_count = LINK_COUNT(term__V1125); permitUnusedInt(term__V1125_count);
  do {
    /* Contraction rule DEFS-Var-1. */
    ASSERT(sink__V1124->context, !strcmp(SYMBOL(term__V1125),  "Var" ));
    Term sub__V1126 = LINK(sink__V1124->context, SUB(term__V1125, 0)); int sub__V1126_count = term__V1125_count*LINK_COUNT(sub__V1126); permitUnusedInt(sub__V1126_count);
    /* sub__V1126 = &#1 */
    
    NamedPropertyLink namedP__V1127 = LINK_NamedPropertyLink(sink__V1124->context, NAMED_PROPERTIES(term__V1125));
    VariablePropertyLink varP__V1128 = LINK_VariablePropertyLink(sink__V1124->context, VARIABLE_PROPERTIES(term__V1125));
    Hashset namedFV__V1129 = LINK_VARIABLESET(sink__V1124->context, namedPropertyFreeVars(namedP__V1127));
    Hashset varFV__V1130 = LINK_VARIABLESET(sink__V1124->context, variablePropertyFreeVars(varP__V1128));
    UNLINK(sink__V1124->context, term__V1125);
    { START(sink__V1124, _M__sTextCons);
      { START(sink__V1124, _M__sTextChars);
        LITERAL(sink__V1124,  "v" ); END(sink__V1124, _M__sTextChars); }
      { START(sink__V1124, _M__sTextCons);
        { START(sink__V1124, _M__sTextEmbed);
          { START(sink__V1124, _M_AsText);
            { START(sink__V1124, _M_MANGLE);
              COPY(sink__V1124, sub__V1126);END(sink__V1124, _M_MANGLE); }
            END(sink__V1124, _M_AsText); }
          END(sink__V1124, _M__sTextEmbed); }
        { START(sink__V1124, _M__sTextNil);
          END(sink__V1124, _M__sTextNil); }
        END(sink__V1124, _M__sTextCons); }
      END(sink__V1124, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V1124->context, namedFV__V1129); UNLINK_VARIABLESET(sink__V1124->context, varFV__V1130);
    UNLINK_NamedPropertyLink(sink__V1124->context, namedP__V1127); UNLINK_VariablePropertyLink(sink__V1124->context, varP__V1128);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION MapIndexText$1. */
int conBindOffs_M_MapIndexText_s1[] = {0 , 0 , 2 , 2};
char *nameFun_M_MapIndexText_s1(Term term) { return  "MapIndexText$1" ; }
struct _ConstructionDescriptor descriptor_M_MapIndexText_s1 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_MapIndexText_s1), conBindOffs_M_MapIndexText_s1, &nameFun_M_MapIndexText_s1, &step_M_MapIndexText_s1};

int step_M_MapIndexText_s1(Sink sink__V1131, Term term__V1132)
{
  int term__V1132_count = LINK_COUNT(term__V1132); permitUnusedInt(term__V1132_count);
  Term sub__V1133 = FORCE(sink__V1131->context, SUB(term__V1132, 0));
  EnumOf_M__sList choice__V1134 = (IS_VARIABLE_USE(sub__V1133) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V1133));
  switch (choice__V1134)
  {
    case Data_M__sCons: { /* Function DEFS-MapIndexText-1$MapIndexText$1$$Cons case $Cons */
      ASSERT(sink__V1131->context, !strcmp(SYMBOL(term__V1132),  "MapIndexText$1" ));
      Term sub__V1135 = SUB(term__V1132, 0); permitUnusedTerm(sub__V1135); int sub__V1135_count = term__V1132_count*LINK_COUNT(sub__V1135); permitUnusedInt(sub__V1135_count);
      ASSERT(sink__V1131->context, !strcmp(SYMBOL(sub__V1135),  "$Cons" ));
      Term sub__V1136 = LINK(sink__V1131->context, SUB(sub__V1135, 0)); int sub__V1136_count = sub__V1135_count*LINK_COUNT(sub__V1136); permitUnusedInt(sub__V1136_count);
      /* sub__V1136 = &#0-0 */
      Term sub__V1137 = LINK(sink__V1131->context, SUB(sub__V1135, 1)); int sub__V1137_count = sub__V1135_count*LINK_COUNT(sub__V1137); permitUnusedInt(sub__V1137_count);
      /* sub__V1137 = &#0-1 */
      Variable x__V1138 = BINDER(term__V1132,1,0); if (term__V1132_count <= 1) UNBIND(x__V1138);
      Variable x__V1139 = BINDER(term__V1132,1,1); if (term__V1132_count <= 1) UNBIND(x__V1139);
      Term sub__V1140 = LINK(sink__V1131->context, SUB(term__V1132, 1)); int sub__V1140_count = term__V1132_count*LINK_COUNT(sub__V1140); permitUnusedInt(sub__V1140_count);
      CRSX_CHECK_SORT(sink__V1131->context, sub__V1140, &sort_M_Reified_xVariable); /* sub__V1140 = &#2 */
      Term sub__V1141 = LINK(sink__V1131->context, SUB(term__V1132, 2)); int sub__V1141_count = term__V1132_count*LINK_COUNT(sub__V1141); permitUnusedInt(sub__V1141_count);
      /* sub__V1141 = &#3 */
      
      NamedPropertyLink namedP__V1142 = LINK_NamedPropertyLink(sink__V1131->context, NAMED_PROPERTIES(term__V1132));
      VariablePropertyLink varP__V1143 = LINK_VariablePropertyLink(sink__V1131->context, VARIABLE_PROPERTIES(term__V1132));
      Hashset namedFV__V1144 = LINK_VARIABLESET(sink__V1131->context, namedPropertyFreeVars(namedP__V1142));
      Hashset varFV__V1145 = LINK_VARIABLESET(sink__V1131->context, variablePropertyFreeVars(varP__V1143));
      UNLINK(sink__V1131->context, term__V1132);
      ADD_PROPERTIES(sink__V1131, LINK_VARIABLESET(sink__V1131->context, namedFV__V1144), LINK_VARIABLESET(sink__V1131->context, varFV__V1145), LINK_NamedPropertyLink(sink__V1131->context, namedP__V1142), LINK_VariablePropertyLink(sink__V1131->context, varP__V1143));
      { START(sink__V1131, _M_MapIndexText_s2);
        COPY(sink__V1131, sub__V1136);COPY(sink__V1131, sub__V1137);{ if (!IS_BOUND(x__V1138)) { REBIND(x__V1138);
            REBIND(x__V1139);
            Variable binds__V1146[2] = {x__V1138,x__V1139}; BINDS(sink__V1131, 2, binds__V1146);
            COPY(sink__V1131, sub__V1140); /* REUSED SUBSTITUTION */  }
          else { Variable b__V1147 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V1131->context,"b__V1147");
            Variable b__V1148 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V1131->context,"b__V1148");
            Variable binds__V1149[2] = {b__V1147,b__V1148}; BINDS(sink__V1131, 2, binds__V1149);
            {
              Term arg__V1150;
              { Sink buf__V1151 = ALLOCA_BUFFER(sink__V1131->context);
                USE(buf__V1151, b__V1147); arg__V1150 = BUFFER_TERM(buf__V1151); FREE_BUFFER(buf__V1151); }
              Term arg__V1152;
              { Sink buf__V1153 = ALLOCA_BUFFER(sink__V1131->context);
                USE(buf__V1153, b__V1148); arg__V1152 = BUFFER_TERM(buf__V1153); FREE_BUFFER(buf__V1153); }
              Variable vars__V1154[2] = {x__V1138,x__V1139};
              Term args__V1155[2] = {arg__V1150,arg__V1152};
              struct _SubstitutionFrame substitution__V1156 = {NULL, 0, 2, vars__V1154, args__V1155, NULL};
              SUBSTITUTE(sink__V1131, sub__V1140, &substitution__V1156); }
                }
           }
        COPY(sink__V1131, sub__V1141);END(sink__V1131, _M_MapIndexText_s2); }
      UNLINK_VARIABLESET(sink__V1131->context, namedFV__V1144); UNLINK_VARIABLESET(sink__V1131->context, varFV__V1145);
      UNLINK_NamedPropertyLink(sink__V1131->context, namedP__V1142); UNLINK_VariablePropertyLink(sink__V1131->context, varP__V1143);
      
      return 1;
    break; } case Data_M__sNil: { /* Function DEFS-MapIndexText-2$MapIndexText$1$$Nil case $Nil */
      ASSERT(sink__V1131->context, !strcmp(SYMBOL(term__V1132),  "MapIndexText$1" ));
      Term sub__V1157 = SUB(term__V1132, 0); permitUnusedTerm(sub__V1157); int sub__V1157_count = term__V1132_count*LINK_COUNT(sub__V1157); permitUnusedInt(sub__V1157_count);
      ASSERT(sink__V1131->context, !strcmp(SYMBOL(sub__V1157),  "$Nil" ));
      Variable x__V1158 = BINDER(term__V1132,1,0); if (term__V1132_count <= 1) UNBIND(x__V1158);
      Variable x__V1159 = BINDER(term__V1132,1,1); if (term__V1132_count <= 1) UNBIND(x__V1159);
      Term sub__V1160 = LINK(sink__V1131->context, SUB(term__V1132, 1)); int sub__V1160_count = term__V1132_count*LINK_COUNT(sub__V1160); permitUnusedInt(sub__V1160_count);
      CRSX_CHECK_SORT(sink__V1131->context, sub__V1160, &sort_M_Reified_xVariable); /* sub__V1160 = &#0 */
      Term sub__V1161 = LINK(sink__V1131->context, SUB(term__V1132, 2)); int sub__V1161_count = term__V1132_count*LINK_COUNT(sub__V1161); permitUnusedInt(sub__V1161_count);
      /* sub__V1161 = &#1 */
      
      NamedPropertyLink namedP__V1162 = LINK_NamedPropertyLink(sink__V1131->context, NAMED_PROPERTIES(term__V1132));
      VariablePropertyLink varP__V1163 = LINK_VariablePropertyLink(sink__V1131->context, VARIABLE_PROPERTIES(term__V1132));
      Hashset namedFV__V1164 = LINK_VARIABLESET(sink__V1131->context, namedPropertyFreeVars(namedP__V1162));
      Hashset varFV__V1165 = LINK_VARIABLESET(sink__V1131->context, variablePropertyFreeVars(varP__V1163));
      UNLINK(sink__V1131->context, term__V1132);
      ADD_PROPERTIES(sink__V1131, LINK_VARIABLESET(sink__V1131->context, namedFV__V1164), LINK_VARIABLESET(sink__V1131->context, varFV__V1165), LINK_NamedPropertyLink(sink__V1131->context, namedP__V1162), LINK_VariablePropertyLink(sink__V1131->context, varP__V1163));
      { START(sink__V1131, _M_MapIndexText_s3);
        { if (!IS_BOUND(x__V1158)) { REBIND(x__V1158);
            REBIND(x__V1159);
            Variable binds__V1166[2] = {x__V1158,x__V1159}; BINDS(sink__V1131, 2, binds__V1166);
            COPY(sink__V1131, sub__V1160); /* REUSED SUBSTITUTION */  }
          else { Variable b__V1167 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V1131->context,"b__V1167");
            Variable b__V1168 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V1131->context,"b__V1168");
            Variable binds__V1169[2] = {b__V1167,b__V1168}; BINDS(sink__V1131, 2, binds__V1169);
            {
              Term arg__V1170;
              { Sink buf__V1171 = ALLOCA_BUFFER(sink__V1131->context);
                USE(buf__V1171, b__V1167); arg__V1170 = BUFFER_TERM(buf__V1171); FREE_BUFFER(buf__V1171); }
              Term arg__V1172;
              { Sink buf__V1173 = ALLOCA_BUFFER(sink__V1131->context);
                USE(buf__V1173, b__V1168); arg__V1172 = BUFFER_TERM(buf__V1173); FREE_BUFFER(buf__V1173); }
              Variable vars__V1174[2] = {x__V1158,x__V1159};
              Term args__V1175[2] = {arg__V1170,arg__V1172};
              struct _SubstitutionFrame substitution__V1176 = {NULL, 0, 2, vars__V1174, args__V1175, NULL};
              SUBSTITUTE(sink__V1131, sub__V1160, &substitution__V1176); }
                }
           }
        COPY(sink__V1131, sub__V1161);END(sink__V1131, _M_MapIndexText_s3); }
      UNLINK_VARIABLESET(sink__V1131->context, namedFV__V1164); UNLINK_VARIABLESET(sink__V1131->context, varFV__V1165);
      UNLINK_NamedPropertyLink(sink__V1131->context, namedP__V1162); UNLINK_VariablePropertyLink(sink__V1131->context, varP__V1163);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION MapIndexText$2. */
int conBindOffs_M_MapIndexText_s2[] = {0 , 0 , 0 , 2 , 2};
char *nameFun_M_MapIndexText_s2(Term term) { return  "MapIndexText$2" ; }
struct _ConstructionDescriptor descriptor_M_MapIndexText_s2 = {&sort_M_Reified_xVariable, 0, 4, sizeof(STRUCT_Con_M_MapIndexText_s2), conBindOffs_M_MapIndexText_s2, &nameFun_M_MapIndexText_s2, &step_M_MapIndexText_s2};

int step_M_MapIndexText_s2(Sink sink__V1177, Term term__V1178)
{
  int term__V1178_count = LINK_COUNT(term__V1178); permitUnusedInt(term__V1178_count);
  do {
    /* Contraction rule DEFS-MapIndexText-1. */
    ASSERT(sink__V1177->context, !strcmp(SYMBOL(term__V1178),  "MapIndexText$2" ));
    Term sub__V1179 = LINK(sink__V1177->context, SUB(term__V1178, 0)); int sub__V1179_count = term__V1178_count*LINK_COUNT(sub__V1179); permitUnusedInt(sub__V1179_count);
    /* sub__V1179 = &#21 */
    Term sub__V1180 = LINK(sink__V1177->context, SUB(term__V1178, 1)); int sub__V1180_count = term__V1178_count*LINK_COUNT(sub__V1180); permitUnusedInt(sub__V1180_count);
    /* sub__V1180 = &#22 */
    Variable x__V1181 = BINDER(term__V1178,2,0); if (term__V1178_count <= 1) UNBIND(x__V1181);
    Variable x__V1182 = BINDER(term__V1178,2,1); if (term__V1178_count <= 1) UNBIND(x__V1182);
    Term sub__V1183 = LINK(sink__V1177->context, SUB(term__V1178, 2)); int sub__V1183_count = term__V1178_count*LINK_COUNT(sub__V1183); permitUnusedInt(sub__V1183_count);
    CRSX_CHECK_SORT(sink__V1177->context, sub__V1183, &sort_M_Reified_xVariable); UNLINK_SUB(sink__V1177->context, term__V1178,  2); NORMALIZE(sink__V1177->context, sub__V1183); SUB(term__V1178,  2) = LINK(sink__V1177->context, sub__V1183);
    /* sub__V1183 = &#1 */
    Term sub__V1184 = LINK(sink__V1177->context, SUB(term__V1178, 3)); int sub__V1184_count = term__V1178_count*LINK_COUNT(sub__V1184); permitUnusedInt(sub__V1184_count);
    UNLINK_SUB(sink__V1177->context, term__V1178,  3); NORMALIZE(sink__V1177->context, sub__V1184); SUB(term__V1178,  3) = LINK(sink__V1177->context, sub__V1184);
    /* sub__V1184 = &#3 */
    
    NamedPropertyLink namedP__V1185 = LINK_NamedPropertyLink(sink__V1177->context, NAMED_PROPERTIES(term__V1178));
    VariablePropertyLink varP__V1186 = LINK_VariablePropertyLink(sink__V1177->context, VARIABLE_PROPERTIES(term__V1178));
    Hashset namedFV__V1187 = LINK_VARIABLESET(sink__V1177->context, namedPropertyFreeVars(namedP__V1185));
    Hashset varFV__V1188 = LINK_VARIABLESET(sink__V1177->context, variablePropertyFreeVars(varP__V1186));
    UNLINK(sink__V1177->context, term__V1178);
    { START(sink__V1177, _M__sTextCons);
      { START(sink__V1177, _M__sTextEmbed);
        { START(sink__V1177, _M_AsText);
          {
            Term arg__V1189;
            { Sink buf__V1190 = ALLOCA_BUFFER(sink__V1177->context);
              COPY(buf__V1190, sub__V1179);arg__V1189 = BUFFER_TERM(buf__V1190); FREE_BUFFER(buf__V1190); }
            Term arg__V1191;
            { Sink buf__V1192 = ALLOCA_BUFFER(sink__V1177->context);
              COPY(buf__V1192, LINK(buf__V1192->context, sub__V1184));arg__V1191 = BUFFER_TERM(buf__V1192); FREE_BUFFER(buf__V1192); }
            Variable vars__V1193[2] = {x__V1181,x__V1182};
            Term args__V1194[2] = {arg__V1189,arg__V1191};
            struct _SubstitutionFrame substitution__V1195 = {NULL, 0, 2, vars__V1193, args__V1194, NULL};
            SUBSTITUTE(sink__V1177, LINK(sink__V1177->context,sub__V1183), &substitution__V1195); }
          END(sink__V1177, _M_AsText); }
        END(sink__V1177, _M__sTextEmbed); }
      { START(sink__V1177, _M__sTextCons);
        { START(sink__V1177, _M__sTextEmbed);
          { START(sink__V1177, _M_AsText);
            { START(sink__V1177, _M_MapIndexText_s1);
              COPY(sink__V1177, sub__V1180);{ Variable x__V1196 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V1177->context,"x__V1196");
                Variable x__V1197 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V1177->context,"x__V1197");
                Variable binds__V1198[2] = {x__V1196,x__V1197}; BINDS(sink__V1177, 2, binds__V1198);
                {
                  Term arg__V1199;
                  { Sink buf__V1200 = ALLOCA_BUFFER(sink__V1177->context);
                    USE(buf__V1200, x__V1196); arg__V1199 = BUFFER_TERM(buf__V1200); FREE_BUFFER(buf__V1200); }
                  Term arg__V1201;
                  { Sink buf__V1202 = ALLOCA_BUFFER(sink__V1177->context);
                    USE(buf__V1202, x__V1197); arg__V1201 = BUFFER_TERM(buf__V1202); FREE_BUFFER(buf__V1202); }
                  Variable vars__V1203[2] = {x__V1181,x__V1182};
                  Term args__V1204[2] = {arg__V1199,arg__V1201};
                  struct _SubstitutionFrame substitution__V1205 = {NULL, 0, 2, vars__V1203, args__V1204, NULL};
                  SUBSTITUTE(sink__V1177, sub__V1183, &substitution__V1205); }
                 }
              { double num__V1206;
                num__V1206 = (double) 1; { double tmp__V1207;
                  tmp__V1207 = DOUBLE(sub__V1184); num__V1206 += tmp__V1207; }
                LITERALNF(sink__V1177, (size_t) 31, "%G", num__V1206); }
              END(sink__V1177, _M_MapIndexText_s1); }
            END(sink__V1177, _M_AsText); }
          END(sink__V1177, _M__sTextEmbed); }
        { START(sink__V1177, _M__sTextNil);
          END(sink__V1177, _M__sTextNil); }
        END(sink__V1177, _M__sTextCons); }
      END(sink__V1177, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V1177->context, namedFV__V1187); UNLINK_VARIABLESET(sink__V1177->context, varFV__V1188);
    UNLINK_NamedPropertyLink(sink__V1177->context, namedP__V1185); UNLINK_VariablePropertyLink(sink__V1177->context, varP__V1186);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION MapIndexText$3. */
int conBindOffs_M_MapIndexText_s3[] = {0 , 2 , 2};
char *nameFun_M_MapIndexText_s3(Term term) { return  "MapIndexText$3" ; }
struct _ConstructionDescriptor descriptor_M_MapIndexText_s3 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_MapIndexText_s3), conBindOffs_M_MapIndexText_s3, &nameFun_M_MapIndexText_s3, &step_M_MapIndexText_s3};

int step_M_MapIndexText_s3(Sink sink__V1208, Term term__V1209)
{
  int term__V1209_count = LINK_COUNT(term__V1209); permitUnusedInt(term__V1209_count);
  do {
    /* Contraction rule DEFS-MapIndexText-2. */
    ASSERT(sink__V1208->context, !strcmp(SYMBOL(term__V1209),  "MapIndexText$3" ));
    Variable x__V1210 = BINDER(term__V1209,0,0); if (term__V1209_count <= 1) UNBIND(x__V1210);
    Variable x__V1211 = BINDER(term__V1209,0,1); if (term__V1209_count <= 1) UNBIND(x__V1211);
    Term sub__V1212 = SUB(term__V1209, 0); permitUnusedTerm(sub__V1212); int sub__V1212_count = term__V1209_count*LINK_COUNT(sub__V1212); permitUnusedInt(sub__V1212_count);
    CRSX_CHECK_SORT(sink__V1208->context, sub__V1212, &sort_M_Reified_xVariable); /* sub__V1212 = &#1 */
    Term sub__V1213 = SUB(term__V1209, 1); permitUnusedTerm(sub__V1213); int sub__V1213_count = term__V1209_count*LINK_COUNT(sub__V1213); permitUnusedInt(sub__V1213_count);
    /* sub__V1213 = &#3 */
    
    NamedPropertyLink namedP__V1214 = LINK_NamedPropertyLink(sink__V1208->context, NAMED_PROPERTIES(term__V1209));
    VariablePropertyLink varP__V1215 = LINK_VariablePropertyLink(sink__V1208->context, VARIABLE_PROPERTIES(term__V1209));
    Hashset namedFV__V1216 = LINK_VARIABLESET(sink__V1208->context, namedPropertyFreeVars(namedP__V1214));
    Hashset varFV__V1217 = LINK_VARIABLESET(sink__V1208->context, variablePropertyFreeVars(varP__V1215));
    UNLINK(sink__V1208->context, term__V1209);
    { START(sink__V1208, _M__sTextNil);
      END(sink__V1208, _M__sTextNil); }
    UNLINK_VARIABLESET(sink__V1208->context, namedFV__V1216); UNLINK_VARIABLESET(sink__V1208->context, varFV__V1217);
    UNLINK_NamedPropertyLink(sink__V1208->context, namedP__V1214); UNLINK_VariablePropertyLink(sink__V1208->context, varP__V1215);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DTOKEN$1. */
int conBindOffs_M_DTOKEN_s1[] = {0 , 0};
char *nameFun_M_DTOKEN_s1(Term term) { return  "DTOKEN$1" ; }
struct _ConstructionDescriptor descriptor_M_DTOKEN_s1 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_DTOKEN_s1), conBindOffs_M_DTOKEN_s1, &nameFun_M_DTOKEN_s1, &step_M_DTOKEN_s1};

int step_M_DTOKEN_s1(Sink sink__V1218, Term term__V1219)
{
  int term__V1219_count = LINK_COUNT(term__V1219); permitUnusedInt(term__V1219_count);
  do {
    /* Contraction rule DEFS-DTOKEN-1. */
    ASSERT(sink__V1218->context, !strcmp(SYMBOL(term__V1219),  "DTOKEN$1" ));
    Term sub__V1220 = LINK(sink__V1218->context, SUB(term__V1219, 0)); int sub__V1220_count = term__V1219_count*LINK_COUNT(sub__V1220); permitUnusedInt(sub__V1220_count);
    UNLINK_SUB(sink__V1218->context, term__V1219,  0); NORMALIZE(sink__V1218->context, sub__V1220); SUB(term__V1219,  0) = LINK(sink__V1218->context, sub__V1220);
    /* sub__V1220 = &#2 */
    
    NamedPropertyLink namedP__V1221 = LINK_NamedPropertyLink(sink__V1218->context, NAMED_PROPERTIES(term__V1219));
    VariablePropertyLink varP__V1222 = LINK_VariablePropertyLink(sink__V1218->context, VARIABLE_PROPERTIES(term__V1219));
    Hashset namedFV__V1223 = LINK_VARIABLESET(sink__V1218->context, namedPropertyFreeVars(namedP__V1221));
    Hashset varFV__V1224 = LINK_VARIABLESET(sink__V1218->context, variablePropertyFreeVars(varP__V1222));
    UNLINK(sink__V1218->context, term__V1219);
    { START(sink__V1218, _M__sTextCons);
      { START(sink__V1218, _M__sTextChars);
        COPY(sink__V1218, sub__V1220);END(sink__V1218, _M__sTextChars); }
      { START(sink__V1218, _M__sTextNil);
        END(sink__V1218, _M__sTextNil); }
      END(sink__V1218, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V1218->context, namedFV__V1223); UNLINK_VARIABLESET(sink__V1218->context, varFV__V1224);
    UNLINK_NamedPropertyLink(sink__V1218->context, namedP__V1221); UNLINK_VariablePropertyLink(sink__V1218->context, varP__V1222);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Descriptor. */
int conBindOffs_M_Descriptor[] = {0 , 0};
char *nameFun_M_Descriptor(Term term) { return  "Descriptor" ; }
struct _ConstructionDescriptor descriptor_M_Descriptor = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_Descriptor), conBindOffs_M_Descriptor, &nameFun_M_Descriptor, &step_M_Descriptor};

int step_M_Descriptor(Sink sink__V1225, Term term__V1226)
{
  int term__V1226_count = LINK_COUNT(term__V1226); permitUnusedInt(term__V1226_count);
  do {
    /* Contraction rule DEFS-Descriptor-1. */
    ASSERT(sink__V1225->context, !strcmp(SYMBOL(term__V1226),  "Descriptor" ));
    Term sub__V1227 = LINK(sink__V1225->context, SUB(term__V1226, 0)); int sub__V1227_count = term__V1226_count*LINK_COUNT(sub__V1227); permitUnusedInt(sub__V1227_count);
    /* sub__V1227 = &#1 */
    
    NamedPropertyLink namedP__V1228 = LINK_NamedPropertyLink(sink__V1225->context, NAMED_PROPERTIES(term__V1226));
    VariablePropertyLink varP__V1229 = LINK_VariablePropertyLink(sink__V1225->context, VARIABLE_PROPERTIES(term__V1226));
    Hashset namedFV__V1230 = LINK_VARIABLESET(sink__V1225->context, namedPropertyFreeVars(namedP__V1228));
    Hashset varFV__V1231 = LINK_VARIABLESET(sink__V1225->context, variablePropertyFreeVars(varP__V1229));
    UNLINK(sink__V1225->context, term__V1226);
    { START(sink__V1225, _M__sTextCons);
      { START(sink__V1225, _M__sTextChars);
        LITERAL(sink__V1225,  "descriptor" ); END(sink__V1225, _M__sTextChars); }
      { START(sink__V1225, _M__sTextCons);
        { START(sink__V1225, _M__sTextEmbed);
          { START(sink__V1225, _M_AsText);
            { START(sink__V1225, _M_MANGLE);
              COPY(sink__V1225, sub__V1227);END(sink__V1225, _M_MANGLE); }
            END(sink__V1225, _M_AsText); }
          END(sink__V1225, _M__sTextEmbed); }
        { START(sink__V1225, _M__sTextNil);
          END(sink__V1225, _M__sTextNil); }
        END(sink__V1225, _M__sTextCons); }
      END(sink__V1225, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V1225->context, namedFV__V1230); UNLINK_VARIABLESET(sink__V1225->context, varFV__V1231);
    UNLINK_NamedPropertyLink(sink__V1225->context, namedP__V1228); UNLINK_VariablePropertyLink(sink__V1225->context, varP__V1229);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Forms-Constructors$1. */
int conBindOffs_M_Forms_Constructors_s1[] = {0 , 0 , 0};
char *nameFun_M_Forms_Constructors_s1(Term term) { return  "Forms-Constructors$1" ; }
struct _ConstructionDescriptor descriptor_M_Forms_Constructors_s1 = {NULL, 0, 2, sizeof(STRUCT_Con_M_Forms_Constructors_s1), conBindOffs_M_Forms_Constructors_s1, &nameFun_M_Forms_Constructors_s1, &step_M_Forms_Constructors_s1};

int step_M_Forms_Constructors_s1(Sink sink__V1232, Term term__V1233)
{
  int term__V1233_count = LINK_COUNT(term__V1233); permitUnusedInt(term__V1233_count);
  do {
    /* Contraction rule DEFS-Forms-Constructors-1$Forms-Constructors$1$SORT-ALLOWS-VARIABLES. */
    ASSERT(sink__V1232->context, !strcmp(SYMBOL(term__V1233),  "Forms-Constructors$1" ));
    Term sub__V1234 = SUB(term__V1233, 0); permitUnusedTerm(sub__V1234); int sub__V1234_count = term__V1233_count*LINK_COUNT(sub__V1234); permitUnusedInt(sub__V1234_count);
    FORCE(sink__V1232->context, sub__V1234); SUB(term__V1233, 0) = sub__V1234;
    if (strcmp(SYMBOL(sub__V1234),  "SORT-ALLOWS-VARIABLES" )) break;
    Term sub__V1235 = LINK(sink__V1232->context, SUB(term__V1233, 1)); int sub__V1235_count = term__V1233_count*LINK_COUNT(sub__V1235); permitUnusedInt(sub__V1235_count);
    /* sub__V1235 = &#0 */
    
    NamedPropertyLink namedP__V1236 = LINK_NamedPropertyLink(sink__V1232->context, NAMED_PROPERTIES(term__V1233));
    VariablePropertyLink varP__V1237 = LINK_VariablePropertyLink(sink__V1232->context, VARIABLE_PROPERTIES(term__V1233));
    Hashset namedFV__V1238 = LINK_VARIABLESET(sink__V1232->context, namedPropertyFreeVars(namedP__V1236));
    Hashset varFV__V1239 = LINK_VARIABLESET(sink__V1232->context, variablePropertyFreeVars(varP__V1237));
    UNLINK(sink__V1232->context, term__V1233);
    ADD_PROPERTIES(sink__V1232, LINK_VARIABLESET(sink__V1232->context, namedFV__V1238), LINK_VARIABLESET(sink__V1232->context, varFV__V1239), LINK_NamedPropertyLink(sink__V1232->context, namedP__V1236), LINK_VariablePropertyLink(sink__V1232->context, varP__V1237));
    { START(sink__V1232, _M_Forms_Constructors_s3);
      COPY(sink__V1232, sub__V1235);END(sink__V1232, _M_Forms_Constructors_s3); }
    UNLINK_VARIABLESET(sink__V1232->context, namedFV__V1238); UNLINK_VARIABLESET(sink__V1232->context, varFV__V1239);
    UNLINK_NamedPropertyLink(sink__V1232->context, namedP__V1236); UNLINK_VariablePropertyLink(sink__V1232->context, varP__V1237);
    
    return 1;
  } while (0);
  do {
    /* Contraction rule DEFS-Forms-Constructors-2$Forms-Constructors$1$SORT-SET. */
    ASSERT(sink__V1232->context, !strcmp(SYMBOL(term__V1233),  "Forms-Constructors$1" ));
    Term sub__V1240 = SUB(term__V1233, 0); permitUnusedTerm(sub__V1240); int sub__V1240_count = term__V1233_count*LINK_COUNT(sub__V1240); permitUnusedInt(sub__V1240_count);
    FORCE(sink__V1232->context, sub__V1240); SUB(term__V1233, 0) = sub__V1240;
    if (strcmp(SYMBOL(sub__V1240),  "SORT-SET" )) break;
    Term sub__V1241 = LINK(sink__V1232->context, SUB(sub__V1240, 0)); int sub__V1241_count = sub__V1240_count*LINK_COUNT(sub__V1241); permitUnusedInt(sub__V1241_count);
    CRSX_CHECK_SORT(sink__V1232->context, sub__V1241, &sort_M_Reified_xSort); /* sub__V1241 = &#0-0 */
    Term sub__V1242 = LINK(sink__V1232->context, SUB(sub__V1240, 1)); int sub__V1242_count = sub__V1240_count*LINK_COUNT(sub__V1242); permitUnusedInt(sub__V1242_count);
    CRSX_CHECK_SORT(sink__V1232->context, sub__V1242, &sort_M_Reified_xSort); /* sub__V1242 = &#0-1 */
    Term sub__V1243 = LINK(sink__V1232->context, SUB(sub__V1240, 2)); int sub__V1243_count = sub__V1240_count*LINK_COUNT(sub__V1243); permitUnusedInt(sub__V1243_count);
    CRSX_CHECK_SORT(sink__V1232->context, sub__V1243, &sort_M_Reified_xForm); /* sub__V1243 = &#0-2 */
    Term sub__V1244 = LINK(sink__V1232->context, SUB(term__V1233, 1)); int sub__V1244_count = term__V1233_count*LINK_COUNT(sub__V1244); permitUnusedInt(sub__V1244_count);
    /* sub__V1244 = &#3 */
    
    NamedPropertyLink namedP__V1245 = LINK_NamedPropertyLink(sink__V1232->context, NAMED_PROPERTIES(term__V1233));
    VariablePropertyLink varP__V1246 = LINK_VariablePropertyLink(sink__V1232->context, VARIABLE_PROPERTIES(term__V1233));
    Hashset namedFV__V1247 = LINK_VARIABLESET(sink__V1232->context, namedPropertyFreeVars(namedP__V1245));
    Hashset varFV__V1248 = LINK_VARIABLESET(sink__V1232->context, variablePropertyFreeVars(varP__V1246));
    UNLINK(sink__V1232->context, term__V1233);
    ADD_PROPERTIES(sink__V1232, LINK_VARIABLESET(sink__V1232->context, namedFV__V1247), LINK_VARIABLESET(sink__V1232->context, varFV__V1248), LINK_NamedPropertyLink(sink__V1232->context, namedP__V1245), LINK_VariablePropertyLink(sink__V1232->context, varP__V1246));
    { START(sink__V1232, _M_Forms_Constructors_s4);
      COPY(sink__V1232, sub__V1241);COPY(sink__V1232, sub__V1242);COPY(sink__V1232, sub__V1243);COPY(sink__V1232, sub__V1244);END(sink__V1232, _M_Forms_Constructors_s4); }
    UNLINK_VARIABLESET(sink__V1232->context, namedFV__V1247); UNLINK_VARIABLESET(sink__V1232->context, varFV__V1248);
    UNLINK_NamedPropertyLink(sink__V1232->context, namedP__V1245); UNLINK_VariablePropertyLink(sink__V1232->context, varP__V1246);
    
    return 1;
  } while (0);
  do {
    /* Contraction rule DEFS-Forms-Constructors-3$Forms-Constructors$1$FORM. */
    ASSERT(sink__V1232->context, !strcmp(SYMBOL(term__V1233),  "Forms-Constructors$1" ));
    Term sub__V1249 = SUB(term__V1233, 0); permitUnusedTerm(sub__V1249); int sub__V1249_count = term__V1233_count*LINK_COUNT(sub__V1249); permitUnusedInt(sub__V1249_count);
    FORCE(sink__V1232->context, sub__V1249); SUB(term__V1233, 0) = sub__V1249;
    if (strcmp(SYMBOL(sub__V1249),  "FORM" )) break;
    Term sub__V1250 = LINK(sink__V1232->context, SUB(sub__V1249, 0)); int sub__V1250_count = sub__V1249_count*LINK_COUNT(sub__V1250); permitUnusedInt(sub__V1250_count);
    /* sub__V1250 = &#0-0 */
    Term sub__V1251 = LINK(sink__V1232->context, SUB(sub__V1249, 1)); int sub__V1251_count = sub__V1249_count*LINK_COUNT(sub__V1251); permitUnusedInt(sub__V1251_count);
    /* sub__V1251 = &#0-1 */
    Term sub__V1252 = LINK(sink__V1232->context, SUB(term__V1233, 1)); int sub__V1252_count = term__V1233_count*LINK_COUNT(sub__V1252); permitUnusedInt(sub__V1252_count);
    /* sub__V1252 = &#2 */
    
    NamedPropertyLink namedP__V1253 = LINK_NamedPropertyLink(sink__V1232->context, NAMED_PROPERTIES(term__V1233));
    VariablePropertyLink varP__V1254 = LINK_VariablePropertyLink(sink__V1232->context, VARIABLE_PROPERTIES(term__V1233));
    Hashset namedFV__V1255 = LINK_VARIABLESET(sink__V1232->context, namedPropertyFreeVars(namedP__V1253));
    Hashset varFV__V1256 = LINK_VARIABLESET(sink__V1232->context, variablePropertyFreeVars(varP__V1254));
    UNLINK(sink__V1232->context, term__V1233);
    ADD_PROPERTIES(sink__V1232, LINK_VARIABLESET(sink__V1232->context, namedFV__V1255), LINK_VARIABLESET(sink__V1232->context, varFV__V1256), LINK_NamedPropertyLink(sink__V1232->context, namedP__V1253), LINK_VariablePropertyLink(sink__V1232->context, varP__V1254));
    { START(sink__V1232, _M_Forms_Constructors_s2);
      COPY(sink__V1232, sub__V1250);COPY(sink__V1232, sub__V1251);COPY(sink__V1232, sub__V1252);END(sink__V1232, _M_Forms_Constructors_s2); }
    UNLINK_VARIABLESET(sink__V1232->context, namedFV__V1255); UNLINK_VARIABLESET(sink__V1232->context, varFV__V1256);
    UNLINK_NamedPropertyLink(sink__V1232->context, namedP__V1253); UNLINK_VariablePropertyLink(sink__V1232->context, varP__V1254);
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Forms-Constructors$2. */
int conBindOffs_M_Forms_Constructors_s2[] = {0 , 0 , 0 , 0};
char *nameFun_M_Forms_Constructors_s2(Term term) { return  "Forms-Constructors$2" ; }
struct _ConstructionDescriptor descriptor_M_Forms_Constructors_s2 = {NULL, 0, 3, sizeof(STRUCT_Con_M_Forms_Constructors_s2), conBindOffs_M_Forms_Constructors_s2, &nameFun_M_Forms_Constructors_s2, &step_M_Forms_Constructors_s2};

int step_M_Forms_Constructors_s2(Sink sink__V1257, Term term__V1258)
{
  int term__V1258_count = LINK_COUNT(term__V1258); permitUnusedInt(term__V1258_count);
  do {
    /* Contraction rule DEFS-Forms-Constructors-3. */
    ASSERT(sink__V1257->context, !strcmp(SYMBOL(term__V1258),  "Forms-Constructors$2" ));
    Term sub__V1259 = LINK(sink__V1257->context, SUB(term__V1258, 0)); int sub__V1259_count = term__V1258_count*LINK_COUNT(sub__V1259); permitUnusedInt(sub__V1259_count);
    /* sub__V1259 = &#111 */
    Term sub__V1260 = SUB(term__V1258, 1); permitUnusedTerm(sub__V1260); int sub__V1260_count = term__V1258_count*LINK_COUNT(sub__V1260); permitUnusedInt(sub__V1260_count);
    /* sub__V1260 = &#112 */
    Term sub__V1261 = LINK(sink__V1257->context, SUB(term__V1258, 2)); int sub__V1261_count = term__V1258_count*LINK_COUNT(sub__V1261); permitUnusedInt(sub__V1261_count);
    /* sub__V1261 = &#12 */
    UNLINK(sink__V1257->context, term__V1258);
    { START(sink__V1257, _M__sCons);
      COPY(sink__V1257, sub__V1259);{ START(sink__V1257, _M_Forms_Constructors);
        COPY(sink__V1257, sub__V1261);END(sink__V1257, _M_Forms_Constructors); }
      END(sink__V1257, _M__sCons); }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Forms-Constructors$3. */
int conBindOffs_M_Forms_Constructors_s3[] = {0 , 0};
char *nameFun_M_Forms_Constructors_s3(Term term) { return  "Forms-Constructors$3" ; }
struct _ConstructionDescriptor descriptor_M_Forms_Constructors_s3 = {NULL, 0, 1, sizeof(STRUCT_Con_M_Forms_Constructors_s3), conBindOffs_M_Forms_Constructors_s3, &nameFun_M_Forms_Constructors_s3, &step_M_Forms_Constructors_s3};

int step_M_Forms_Constructors_s3(Sink sink__V1262, Term term__V1263)
{
  int term__V1263_count = LINK_COUNT(term__V1263); permitUnusedInt(term__V1263_count);
  do {
    /* Contraction rule DEFS-Forms-Constructors-1. */
    ASSERT(sink__V1262->context, !strcmp(SYMBOL(term__V1263),  "Forms-Constructors$3" ));
    Term sub__V1264 = LINK(sink__V1262->context, SUB(term__V1263, 0)); int sub__V1264_count = term__V1263_count*LINK_COUNT(sub__V1264); permitUnusedInt(sub__V1264_count);
    /* sub__V1264 = &#12 */
    UNLINK(sink__V1262->context, term__V1263);
    { START(sink__V1262, _M_Forms_Constructors);
      COPY(sink__V1262, sub__V1264);END(sink__V1262, _M_Forms_Constructors); }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Forms-Constructors$4. */
int conBindOffs_M_Forms_Constructors_s4[] = {0 , 0 , 0 , 0 , 0};
char *nameFun_M_Forms_Constructors_s4(Term term) { return  "Forms-Constructors$4" ; }
struct _ConstructionDescriptor descriptor_M_Forms_Constructors_s4 = {NULL, 0, 4, sizeof(STRUCT_Con_M_Forms_Constructors_s4), conBindOffs_M_Forms_Constructors_s4, &nameFun_M_Forms_Constructors_s4, &step_M_Forms_Constructors_s4};

int step_M_Forms_Constructors_s4(Sink sink__V1265, Term term__V1266)
{
  int term__V1266_count = LINK_COUNT(term__V1266); permitUnusedInt(term__V1266_count);
  do {
    /* Contraction rule DEFS-Forms-Constructors-2. */
    ASSERT(sink__V1265->context, !strcmp(SYMBOL(term__V1266),  "Forms-Constructors$4" ));
    Term sub__V1267 = SUB(term__V1266, 0); permitUnusedTerm(sub__V1267); int sub__V1267_count = term__V1266_count*LINK_COUNT(sub__V1267); permitUnusedInt(sub__V1267_count);
    CRSX_CHECK_SORT(sink__V1265->context, sub__V1267, &sort_M_Reified_xSort); /* sub__V1267 = &#111 */
    Term sub__V1268 = SUB(term__V1266, 1); permitUnusedTerm(sub__V1268); int sub__V1268_count = term__V1266_count*LINK_COUNT(sub__V1268); permitUnusedInt(sub__V1268_count);
    CRSX_CHECK_SORT(sink__V1265->context, sub__V1268, &sort_M_Reified_xSort); /* sub__V1268 = &#112 */
    Term sub__V1269 = LINK(sink__V1265->context, SUB(term__V1266, 2)); int sub__V1269_count = term__V1266_count*LINK_COUNT(sub__V1269); permitUnusedInt(sub__V1269_count);
    CRSX_CHECK_SORT(sink__V1265->context, sub__V1269, &sort_M_Reified_xForm); /* sub__V1269 = &#113 */
    Term sub__V1270 = LINK(sink__V1265->context, SUB(term__V1266, 3)); int sub__V1270_count = term__V1266_count*LINK_COUNT(sub__V1270); permitUnusedInt(sub__V1270_count);
    /* sub__V1270 = &#12 */
    UNLINK(sink__V1265->context, term__V1266);
    { START(sink__V1265, _M_Forms_Constructors);
      { START(sink__V1265, _M__sCons);
        COPY(sink__V1265, sub__V1269);COPY(sink__V1265, sub__V1270);END(sink__V1265, _M__sCons); }
      END(sink__V1265, _M_Forms_Constructors); }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Forms-Constructors$5. */
int conBindOffs_M_Forms_Constructors_s5[] = {0};
char *nameFun_M_Forms_Constructors_s5(Term term) { return  "Forms-Constructors$5" ; }
struct _ConstructionDescriptor descriptor_M_Forms_Constructors_s5 = {NULL, 0, 0, sizeof(STRUCT_Con_M_Forms_Constructors_s5), conBindOffs_M_Forms_Constructors_s5, &nameFun_M_Forms_Constructors_s5, &step_M_Forms_Constructors_s5};

int step_M_Forms_Constructors_s5(Sink sink__V1271, Term term__V1272)
{
  int term__V1272_count = LINK_COUNT(term__V1272); permitUnusedInt(term__V1272_count);
  do {
    /* Contraction rule DEFS-Forms-Constructors-4. */
    ASSERT(sink__V1271->context, !strcmp(SYMBOL(term__V1272),  "Forms-Constructors$5" ));
    UNLINK(sink__V1271->context, term__V1272);
    { START(sink__V1271, _M__sNil); END(sink__V1271, _M__sNil); } 
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DMANGLE$1. */
int conBindOffs_M_DMANGLE_s1[] = {0 , 0};
char *nameFun_M_DMANGLE_s1(Term term) { return  "DMANGLE$1" ; }
struct _ConstructionDescriptor descriptor_M_DMANGLE_s1 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_DMANGLE_s1), conBindOffs_M_DMANGLE_s1, &nameFun_M_DMANGLE_s1, &step_M_DMANGLE_s1};

int step_M_DMANGLE_s1(Sink sink__V1273, Term term__V1274)
{
  int term__V1274_count = LINK_COUNT(term__V1274); permitUnusedInt(term__V1274_count);
  do {
    /* Contraction rule DEFS-DMANGLE-1. */
    ASSERT(sink__V1273->context, !strcmp(SYMBOL(term__V1274),  "DMANGLE$1" ));
    Term sub__V1275 = LINK(sink__V1273->context, SUB(term__V1274, 0)); int sub__V1275_count = term__V1274_count*LINK_COUNT(sub__V1275); permitUnusedInt(sub__V1275_count);
    UNLINK_SUB(sink__V1273->context, term__V1274,  0); NORMALIZE(sink__V1273->context, sub__V1275); SUB(term__V1274,  0) = LINK(sink__V1273->context, sub__V1275);
    /* sub__V1275 = &#2 */
    
    NamedPropertyLink namedP__V1276 = LINK_NamedPropertyLink(sink__V1273->context, NAMED_PROPERTIES(term__V1274));
    VariablePropertyLink varP__V1277 = LINK_VariablePropertyLink(sink__V1273->context, VARIABLE_PROPERTIES(term__V1274));
    Hashset namedFV__V1278 = LINK_VARIABLESET(sink__V1273->context, namedPropertyFreeVars(namedP__V1276));
    Hashset varFV__V1279 = LINK_VARIABLESET(sink__V1273->context, variablePropertyFreeVars(varP__V1277));
    UNLINK(sink__V1273->context, term__V1274);
    { START(sink__V1273, _M__sTextCons);
      { START(sink__V1273, _M__sTextChars);
        { char *str__V1280;
          FORCE(sink__V1273->context, sub__V1275);
          { char *s__V1281 = makeMangled(sink__V1273->context, SYMBOL(sub__V1275));
            { size_t z__V1282 = strlen(s__V1281) + 1; memcpy(str__V1280 = ALLOCATE(sink__V1273->context, z__V1282), s__V1281, z__V1282);  UNLINK(sink__V1273->context, sub__V1275);}
            }
          LITERALU(sink__V1273, str__V1280); }
        END(sink__V1273, _M__sTextChars); }
      { START(sink__V1273, _M__sTextNil);
        END(sink__V1273, _M__sTextNil); }
      END(sink__V1273, _M__sTextCons); }
    UNLINK_VARIABLESET(sink__V1273->context, namedFV__V1278); UNLINK_VARIABLESET(sink__V1273->context, varFV__V1279);
    UNLINK_NamedPropertyLink(sink__V1273->context, namedP__V1276); UNLINK_VariablePropertyLink(sink__V1273->context, varP__V1277);
    return 1;
  } while (0);
  return 0;
}

#ifdef __cplusplus
}
#endif
/* END OF C RULES FOR CRSX CRSXC MODULE D. */
