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
      UNLINK(sink__V1->context, term__V2);
      ADD_PROPERTIES(sink__V1, LINK_NamedPropertyLink(sink__V1->context, namedP__V7), LINK_VariablePropertyLink(sink__V1->context, varP__V8));
      { START(sink__V1, _M_DSTRING_s1);
        COPY(sink__V1, sub__V6);END(sink__V1, _M_DSTRING_s1); }
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

int step_M_MetaVar2(Sink sink__V9, Term term__V10)
{
  int term__V10_count = LINK_COUNT(term__V10); permitUnusedInt(term__V10_count);
  Term sub__V11 = FORCE(sink__V9->context, SUB(term__V10, 0));
  EnumOf_M_STRING_xENTRY choice__V12 = (IS_VARIABLE_USE(sub__V11) ? VarOf_M_STRING_xENTRY : (EnumOf_M_STRING_xENTRY) TAG(sub__V11));
  switch (choice__V12)
  {
    case Data_M_VARIABLE: { /* Function DEFS-MetaVar2-1$MetaVar2$VARIABLE case VARIABLE */
      ASSERT(sink__V9->context, !strcmp(SYMBOL(term__V10),  "MetaVar2" ));
      Term sub__V13 = SUB(term__V10, 0); permitUnusedTerm(sub__V13); int sub__V13_count = term__V10_count*LINK_COUNT(sub__V13); permitUnusedInt(sub__V13_count);
      CRSX_CHECK_SORT(sink__V9->context, sub__V13, &sort_M_STRING_xENTRY); ASSERT(sink__V9->context, !strcmp(SYMBOL(sub__V13),  "VARIABLE" ));
      Term sub__V14 = LINK(sink__V9->context, SUB(sub__V13, 0)); int sub__V14_count = sub__V13_count*LINK_COUNT(sub__V14); permitUnusedInt(sub__V14_count);
      CRSX_CHECK_SORT(sink__V9->context, sub__V14, &sort_M_Reified_xVariable); /* sub__V14 = &#0-0 */
      NamedPropertyLink namedP__V15 = LINK_NamedPropertyLink(sink__V9->context, NAMED_PROPERTIES(term__V10));
      VariablePropertyLink varP__V16 = LINK_VariablePropertyLink(sink__V9->context, VARIABLE_PROPERTIES(term__V10));
      UNLINK(sink__V9->context, term__V10);
      ADD_PROPERTIES(sink__V9, LINK_NamedPropertyLink(sink__V9->context, namedP__V15), LINK_VariablePropertyLink(sink__V9->context, varP__V16));
      { START(sink__V9, _M_MetaVar2_s2);
        COPY(sink__V9, sub__V14);END(sink__V9, _M_MetaVar2_s2); }
      UNLINK_NamedPropertyLink(sink__V9->context, namedP__V15); UNLINK_VariablePropertyLink(sink__V9->context, varP__V16);
      
      return 1;
    break; } case Data_M_STRING_xVALUE: { /* Function DEFS-MetaVar2-2$MetaVar2$STRING_VALUE case STRING_VALUE */
      ASSERT(sink__V9->context, !strcmp(SYMBOL(term__V10),  "MetaVar2" ));
      Term sub__V17 = SUB(term__V10, 0); permitUnusedTerm(sub__V17); int sub__V17_count = term__V10_count*LINK_COUNT(sub__V17); permitUnusedInt(sub__V17_count);
      CRSX_CHECK_SORT(sink__V9->context, sub__V17, &sort_M_STRING_xENTRY); ASSERT(sink__V9->context, !strcmp(SYMBOL(sub__V17),  "STRING_VALUE" ));
      Term sub__V18 = LINK(sink__V9->context, SUB(sub__V17, 0)); int sub__V18_count = sub__V17_count*LINK_COUNT(sub__V18); permitUnusedInt(sub__V18_count);
      /* sub__V18 = &#0-0 */
      NamedPropertyLink namedP__V19 = LINK_NamedPropertyLink(sink__V9->context, NAMED_PROPERTIES(term__V10));
      VariablePropertyLink varP__V20 = LINK_VariablePropertyLink(sink__V9->context, VARIABLE_PROPERTIES(term__V10));
      UNLINK(sink__V9->context, term__V10);
      ADD_PROPERTIES(sink__V9, LINK_NamedPropertyLink(sink__V9->context, namedP__V19), LINK_VariablePropertyLink(sink__V9->context, varP__V20));
      { START(sink__V9, _M_MetaVar2_s1);
        COPY(sink__V9, sub__V18);END(sink__V9, _M_MetaVar2_s1); }
      UNLINK_NamedPropertyLink(sink__V9->context, namedP__V19); UNLINK_VariablePropertyLink(sink__V9->context, varP__V20);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION TOKEN. */
int conBindOffs_M_TOKEN[] = {0 , 0};
char *nameFun_M_TOKEN(Term term) { return  "TOKEN" ; }
struct _ConstructionDescriptor descriptor_M_TOKEN = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_TOKEN), conBindOffs_M_TOKEN, &nameFun_M_TOKEN, &step_M_TOKEN};

int step_M_TOKEN(Sink sink__V21, Term term__V22)
{
  int term__V22_count = LINK_COUNT(term__V22); permitUnusedInt(term__V22_count);
  do {
    /* Contraction rule DEFS-TOKEN-1. */
    ASSERT(sink__V21->context, !strcmp(SYMBOL(term__V22),  "TOKEN" ));
    Term sub__V23 = LINK(sink__V21->context, SUB(term__V22, 0)); int sub__V23_count = term__V22_count*LINK_COUNT(sub__V23); permitUnusedInt(sub__V23_count);
    UNLINK_SUB(sink__V21->context, term__V22,  0); NORMALIZE(sink__V21->context, sub__V23); SUB(term__V22,  0) = LINK(sink__V21->context, sub__V23);
    /* sub__V23 = &#1 */
    NamedPropertyLink namedP__V24 = LINK_NamedPropertyLink(sink__V21->context, NAMED_PROPERTIES(term__V22));
    VariablePropertyLink varP__V25 = LINK_VariablePropertyLink(sink__V21->context, VARIABLE_PROPERTIES(term__V22));
    UNLINK(sink__V21->context, term__V22);
    { START(sink__V21, _M__sTextCons);
      { START(sink__V21, _M__sTextChars);
        COPY(sink__V21, sub__V23);END(sink__V21, _M__sTextChars); }
      { START(sink__V21, _M__sTextNil); END(sink__V21, _M__sTextNil); }
      END(sink__V21, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V21->context, namedP__V24); UNLINK_VariablePropertyLink(sink__V21->context, varP__V25);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Length$1. */
int conBindOffs_M_Length_s1[] = {0 , 0 , 0 , 0};
char *nameFun_M_Length_s1(Term term) { return  "Length$1" ; }
struct _ConstructionDescriptor descriptor_M_Length_s1 = {NULL, 0, 3, sizeof(STRUCT_Con_M_Length_s1), conBindOffs_M_Length_s1, &nameFun_M_Length_s1, &step_M_Length_s1};

int step_M_Length_s1(Sink sink__V26, Term term__V27)
{
  int term__V27_count = LINK_COUNT(term__V27); permitUnusedInt(term__V27_count);
  do {
    /* Contraction rule DEFS-Length-2. */
    ASSERT(sink__V26->context, !strcmp(SYMBOL(term__V27),  "Length$1" ));
    Term sub__V28 = SUB(term__V27, 0); permitUnusedTerm(sub__V28); int sub__V28_count = term__V27_count*LINK_COUNT(sub__V28); permitUnusedInt(sub__V28_count);
    /* sub__V28 = &#11 */
    Term sub__V29 = LINK(sink__V26->context, SUB(term__V27, 1)); int sub__V29_count = term__V27_count*LINK_COUNT(sub__V29); permitUnusedInt(sub__V29_count);
    /* sub__V29 = &#12 */
    Term sub__V30 = LINK(sink__V26->context, SUB(term__V27, 2)); int sub__V30_count = term__V27_count*LINK_COUNT(sub__V30); permitUnusedInt(sub__V30_count);
    /* sub__V30 = &#2 */
    UNLINK(sink__V26->context, term__V27);
    { START(sink__V26, _M_Length);
      COPY(sink__V26, sub__V29);{ double num__V31;
        num__V31 = (double) 1; { double tmp__V32;
          tmp__V32 = DOUBLE(sub__V30); num__V31 += tmp__V32; }
        LITERALNF(sink__V26, (size_t) 31, "%G", num__V31); }
      END(sink__V26, _M_Length); }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Length$2. */
int conBindOffs_M_Length_s2[] = {0 , 0};
char *nameFun_M_Length_s2(Term term) { return  "Length$2" ; }
struct _ConstructionDescriptor descriptor_M_Length_s2 = {NULL, 0, 1, sizeof(STRUCT_Con_M_Length_s2), conBindOffs_M_Length_s2, &nameFun_M_Length_s2, &step_M_Length_s2};

int step_M_Length_s2(Sink sink__V33, Term term__V34)
{
  int term__V34_count = LINK_COUNT(term__V34); permitUnusedInt(term__V34_count);
  do {
    /* Contraction rule DEFS-Length-1. */
    ASSERT(sink__V33->context, !strcmp(SYMBOL(term__V34),  "Length$2" ));
    Term sub__V35 = LINK(sink__V33->context, SUB(term__V34, 0)); int sub__V35_count = term__V34_count*LINK_COUNT(sub__V35); permitUnusedInt(sub__V35_count);
    /* sub__V35 = &#2 */
    UNLINK(sink__V33->context, term__V34); COPY(sink__V33, sub__V35); return 1;
  } while (0);
  return 0;
}

/* FUNCTION DCOMMENT_TOKEN. */
int conBindOffs_M_DCOMMENT_xTOKEN[] = {0 , 0 , 0};
char *nameFun_M_DCOMMENT_xTOKEN(Term term) { return  "DCOMMENT_TOKEN" ; }
struct _ConstructionDescriptor descriptor_M_DCOMMENT_xTOKEN = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_DCOMMENT_xTOKEN), conBindOffs_M_DCOMMENT_xTOKEN, &nameFun_M_DCOMMENT_xTOKEN, &step_M_DCOMMENT_xTOKEN};

int step_M_DCOMMENT_xTOKEN(Sink sink__V36, Term term__V37)
{
  int term__V37_count = LINK_COUNT(term__V37); permitUnusedInt(term__V37_count);
  Term sub__V38 = FORCE(sink__V36->context, SUB(term__V37, 0));
  EnumOf_M_OK_xSORT choice__V39 = (IS_VARIABLE_USE(sub__V38) ? VarOf_M_OK_xSORT : (EnumOf_M_OK_xSORT) TAG(sub__V38));
  switch (choice__V39)
  {
    case Data_M_OK: { /* Function DEFS-DCOMMENT_TOKEN-1$DCOMMENT_TOKEN$OK case OK */
      ASSERT(sink__V36->context, !strcmp(SYMBOL(term__V37),  "DCOMMENT_TOKEN" ));
      Term sub__V40 = SUB(term__V37, 0); permitUnusedTerm(sub__V40); int sub__V40_count = term__V37_count*LINK_COUNT(sub__V40); permitUnusedInt(sub__V40_count);
      CRSX_CHECK_SORT(sink__V36->context, sub__V40, &sort_M_OK_xSORT); ASSERT(sink__V36->context, !strcmp(SYMBOL(sub__V40),  "OK" ));
      Term sub__V41 = LINK(sink__V36->context, SUB(term__V37, 1)); int sub__V41_count = term__V37_count*LINK_COUNT(sub__V41); permitUnusedInt(sub__V41_count);
      /* sub__V41 = &#0 */
      NamedPropertyLink namedP__V42 = LINK_NamedPropertyLink(sink__V36->context, NAMED_PROPERTIES(term__V37));
      VariablePropertyLink varP__V43 = LINK_VariablePropertyLink(sink__V36->context, VARIABLE_PROPERTIES(term__V37));
      UNLINK(sink__V36->context, term__V37);
      ADD_PROPERTIES(sink__V36, LINK_NamedPropertyLink(sink__V36->context, namedP__V42), LINK_VariablePropertyLink(sink__V36->context, varP__V43));
      { START(sink__V36, _M_DCOMMENT_xTOKEN_s1);
        COPY(sink__V36, sub__V41);END(sink__V36, _M_DCOMMENT_xTOKEN_s1); }
      UNLINK_NamedPropertyLink(sink__V36->context, namedP__V42); UNLINK_VariablePropertyLink(sink__V36->context, varP__V43);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION MissingPrimitive. */
int conBindOffs_M_MissingPrimitive[] = {0 , 0};
char *nameFun_M_MissingPrimitive(Term term) { return  "MissingPrimitive" ; }
struct _ConstructionDescriptor descriptor_M_MissingPrimitive = {&sort_M_SPrimitive, 0, 1, sizeof(STRUCT_Con_M_MissingPrimitive), conBindOffs_M_MissingPrimitive, &nameFun_M_MissingPrimitive, &step_M_MissingPrimitive};

int step_M_MissingPrimitive(Sink sink__V44, Term term__V45)
{
  int term__V45_count = LINK_COUNT(term__V45); permitUnusedInt(term__V45_count);
  do {
    /* Contraction rule DEFS-MissingPrimitive-1. */
    ASSERT(sink__V44->context, !strcmp(SYMBOL(term__V45),  "MissingPrimitive" ));
    Term sub__V46 = LINK(sink__V44->context, SUB(term__V45, 0)); int sub__V46_count = term__V45_count*LINK_COUNT(sub__V46); permitUnusedInt(sub__V46_count);
    /* sub__V46 = &#1 */
    UNLINK(sink__V44->context, term__V45);
    char *sub__V47[3]; size_t sublength__V48[3]; size_t length__V49 = 0;
    length__V49 += (sublength__V48[0] = strlen(sub__V47[0] =  "$[" ));
    FORCE(sink__V44->context, sub__V46);
    length__V49 += (sublength__V48[1] = strlen(sub__V47[1] = SYMBOL(sub__V46)));
    UNLINK(sink__V44->context, sub__V46);length__V49 += (sublength__V48[2] = strlen(sub__V47[2] =  "] not supported" ));
    { char *str__V50 = ALLOCA(sink__V44->context, length__V49+1), *p__V51 = str__V50;
      int i; for (i = 0; i < 3; ++i) { memcpy(p__V51, sub__V47[i], sublength__V48[i]); p__V51 += sublength__V48[i]; }
      *p__V51 = '\0';
      ASSERT(sink__V44->context, strlen(str__V50) == length__V49);
      ERRORF(sink__V44->context, Default, "%s\n", str__V50); }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION If$1. */
int conBindOffs_M_If_s1[] = {0 , 0 , 0};
char *nameFun_M_If_s1(Term term) { return  "If$1" ; }
struct _ConstructionDescriptor descriptor_M_If_s1 = {NULL, 0, 2, sizeof(STRUCT_Con_M_If_s1), conBindOffs_M_If_s1, &nameFun_M_If_s1, &step_M_If_s1};

int step_M_If_s1(Sink sink__V52, Term term__V53)
{
  int term__V53_count = LINK_COUNT(term__V53); permitUnusedInt(term__V53_count);
  do {
    /* Contraction rule DEFS-If-2. */
    ASSERT(sink__V52->context, !strcmp(SYMBOL(term__V53),  "If$1" ));
    Term sub__V54 = SUB(term__V53, 0); permitUnusedTerm(sub__V54); int sub__V54_count = term__V53_count*LINK_COUNT(sub__V54); permitUnusedInt(sub__V54_count);
    /* sub__V54 = &#2 */
    Term sub__V55 = LINK(sink__V52->context, SUB(term__V53, 1)); int sub__V55_count = term__V53_count*LINK_COUNT(sub__V55); permitUnusedInt(sub__V55_count);
    /* sub__V55 = &#3 */
    UNLINK(sink__V52->context, term__V53); COPY(sink__V52, sub__V55); return 1;
  } while (0);
  return 0;
}

/* FUNCTION If$2. */
int conBindOffs_M_If_s2[] = {0 , 0 , 0};
char *nameFun_M_If_s2(Term term) { return  "If$2" ; }
struct _ConstructionDescriptor descriptor_M_If_s2 = {NULL, 0, 2, sizeof(STRUCT_Con_M_If_s2), conBindOffs_M_If_s2, &nameFun_M_If_s2, &step_M_If_s2};

int step_M_If_s2(Sink sink__V56, Term term__V57)
{
  int term__V57_count = LINK_COUNT(term__V57); permitUnusedInt(term__V57_count);
  do {
    /* Contraction rule DEFS-If-1. */
    ASSERT(sink__V56->context, !strcmp(SYMBOL(term__V57),  "If$2" ));
    Term sub__V58 = LINK(sink__V56->context, SUB(term__V57, 0)); int sub__V58_count = term__V57_count*LINK_COUNT(sub__V58); permitUnusedInt(sub__V58_count);
    /* sub__V58 = &#2 */
    Term sub__V59 = SUB(term__V57, 1); permitUnusedTerm(sub__V59); int sub__V59_count = term__V57_count*LINK_COUNT(sub__V59); permitUnusedInt(sub__V59_count);
    /* sub__V59 = &#3 */
    UNLINK(sink__V56->context, term__V57); COPY(sink__V56, sub__V58); return 1;
  } while (0);
  return 0;
}

/* FUNCTION NameFun. */
int conBindOffs_M_NameFun[] = {0 , 0};
char *nameFun_M_NameFun(Term term) { return  "NameFun" ; }
struct _ConstructionDescriptor descriptor_M_NameFun = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_NameFun), conBindOffs_M_NameFun, &nameFun_M_NameFun, &step_M_NameFun};

int step_M_NameFun(Sink sink__V60, Term term__V61)
{
  int term__V61_count = LINK_COUNT(term__V61); permitUnusedInt(term__V61_count);
  do {
    /* Contraction rule DEFS-NameFun-1. */
    ASSERT(sink__V60->context, !strcmp(SYMBOL(term__V61),  "NameFun" ));
    Term sub__V62 = LINK(sink__V60->context, SUB(term__V61, 0)); int sub__V62_count = term__V61_count*LINK_COUNT(sub__V62); permitUnusedInt(sub__V62_count);
    /* sub__V62 = &#1 */
    NamedPropertyLink namedP__V63 = LINK_NamedPropertyLink(sink__V60->context, NAMED_PROPERTIES(term__V61));
    VariablePropertyLink varP__V64 = LINK_VariablePropertyLink(sink__V60->context, VARIABLE_PROPERTIES(term__V61));
    UNLINK(sink__V60->context, term__V61);
    { START(sink__V60, _M__sTextCons);
      { START(sink__V60, _M__sTextChars);
        LITERAL(sink__V60,  "nameFun" ); END(sink__V60, _M__sTextChars); }
      { START(sink__V60, _M__sTextCons);
        { START(sink__V60, _M__sTextEmbed);
          { START(sink__V60, _M_AsText);
            { START(sink__V60, _M_MANGLE);
              COPY(sink__V60, sub__V62);END(sink__V60, _M_MANGLE); }
            END(sink__V60, _M_AsText); }
          END(sink__V60, _M__sTextEmbed); }
        { START(sink__V60, _M__sTextNil);
          END(sink__V60, _M__sTextNil); }
        END(sink__V60, _M__sTextCons); }
      END(sink__V60, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V60->context, namedP__V63); UNLINK_VariablePropertyLink(sink__V60->context, varP__V64);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION FormArguments-binder-count$1. */
int conBindOffs_M_FormArguments__binder__count_s1[] = {0 , 0 , 0 , 0};
char *nameFun_M_FormArguments__binder__count_s1(Term term) { return  "FormArguments-binder-count$1" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__count_s1 = {NULL, 0, 3, sizeof(STRUCT_Con_M_FormArguments__binder__count_s1), conBindOffs_M_FormArguments__binder__count_s1, &nameFun_M_FormArguments__binder__count_s1, &step_M_FormArguments__binder__count_s1};

int step_M_FormArguments__binder__count_s1(Sink sink__V65, Term term__V66)
{
  int term__V66_count = LINK_COUNT(term__V66); permitUnusedInt(term__V66_count);
  do {
    /* Contraction rule DEFS-FormArguments-binder-count-1$FormArguments-binder-count$1$FORM-BINDER. */
    ASSERT(sink__V65->context, !strcmp(SYMBOL(term__V66),  "FormArguments-binder-count$1" ));
    Term sub__V67 = SUB(term__V66, 0); permitUnusedTerm(sub__V67); int sub__V67_count = term__V66_count*LINK_COUNT(sub__V67); permitUnusedInt(sub__V67_count);
    FORCE(sink__V65->context, sub__V67); SUB(term__V66, 0) = sub__V67;
    if (strcmp(SYMBOL(sub__V67),  "FORM-BINDER" )) break;
    Term sub__V68 = LINK(sink__V65->context, SUB(sub__V67, 0)); int sub__V68_count = sub__V67_count*LINK_COUNT(sub__V68); permitUnusedInt(sub__V68_count);
    CRSX_CHECK_SORT(sink__V65->context, sub__V68, &sort_M_Reified_xSort); /* sub__V68 = &#0-0 */
    Variable y__V69 = BINDER(sub__V67,1,0); if (sub__V67_count <= 1) UNBIND(y__V69);
    Term sub__V70 = LINK(sink__V65->context, SUB(sub__V67, 1)); int sub__V70_count = sub__V67_count*LINK_COUNT(sub__V70); permitUnusedInt(sub__V70_count);
    CRSX_CHECK_SORT(sink__V65->context, sub__V70, &sort_M_Reified_xFormArgument); /* sub__V70 = &#0-1 */
    Term sub__V71 = LINK(sink__V65->context, SUB(term__V66, 1)); int sub__V71_count = term__V66_count*LINK_COUNT(sub__V71); permitUnusedInt(sub__V71_count);
    /* sub__V71 = &#2 */
    Term sub__V72 = LINK(sink__V65->context, SUB(term__V66, 2)); int sub__V72_count = term__V66_count*LINK_COUNT(sub__V72); permitUnusedInt(sub__V72_count);
    /* sub__V72 = &#3 */
    NamedPropertyLink namedP__V73 = LINK_NamedPropertyLink(sink__V65->context, NAMED_PROPERTIES(term__V66));
    VariablePropertyLink varP__V74 = LINK_VariablePropertyLink(sink__V65->context, VARIABLE_PROPERTIES(term__V66));
    UNLINK(sink__V65->context, term__V66);
    ADD_PROPERTIES(sink__V65, LINK_NamedPropertyLink(sink__V65->context, namedP__V73), LINK_VariablePropertyLink(sink__V65->context, varP__V74));
    { START(sink__V65, _M_FormArguments__binder__count_s3);
      COPY(sink__V65, sub__V68);{ if (!IS_BOUND(y__V69)) { REBIND(y__V69);
          Variable binds__V75[1] = {y__V69}; BINDS(sink__V65, 1, binds__V75);
          COPY(sink__V65, sub__V70); /* REUSED SUBSTITUTION */  }
        else { Variable b__V76 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V65->context,"b__V76");
          Variable binds__V77[1] = {b__V76}; BINDS(sink__V65, 1, binds__V77);
          {
            Term arg__V78;
            { Sink buf__V79 = ALLOCA_BUFFER(sink__V65->context);
              USE(buf__V79, b__V76); arg__V78 = BUFFER_TERM(buf__V79); FREE_BUFFER(buf__V79); }
            Variable vars__V80[1] = {y__V69};
            Term args__V81[1] = {arg__V78};
            struct _SubstitutionFrame substitution__V82 = {NULL, 0, 1, vars__V80, args__V81, NULL};
            SUBSTITUTE(sink__V65, sub__V70, &substitution__V82); }
              }
         }
      COPY(sink__V65, sub__V71);COPY(sink__V65, sub__V72);END(sink__V65, _M_FormArguments__binder__count_s3); }
    UNLINK_NamedPropertyLink(sink__V65->context, namedP__V73); UNLINK_VariablePropertyLink(sink__V65->context, varP__V74);
    
    return 1;
  } while (0);
  do {
    /* Contraction rule DEFS-FormArguments-binder-count-2$FormArguments-binder-count$1$FORM-ARGUMENT. */
    ASSERT(sink__V65->context, !strcmp(SYMBOL(term__V66),  "FormArguments-binder-count$1" ));
    Term sub__V83 = SUB(term__V66, 0); permitUnusedTerm(sub__V83); int sub__V83_count = term__V66_count*LINK_COUNT(sub__V83); permitUnusedInt(sub__V83_count);
    FORCE(sink__V65->context, sub__V83); SUB(term__V66, 0) = sub__V83;
    if (strcmp(SYMBOL(sub__V83),  "FORM-ARGUMENT" )) break;
    Term sub__V84 = LINK(sink__V65->context, SUB(sub__V83, 0)); int sub__V84_count = sub__V83_count*LINK_COUNT(sub__V84); permitUnusedInt(sub__V84_count);
    CRSX_CHECK_SORT(sink__V65->context, sub__V84, &sort_M_Reified_xSort); /* sub__V84 = &#0-0 */
    Term sub__V85 = LINK(sink__V65->context, SUB(term__V66, 1)); int sub__V85_count = term__V66_count*LINK_COUNT(sub__V85); permitUnusedInt(sub__V85_count);
    /* sub__V85 = &#1 */
    Term sub__V86 = LINK(sink__V65->context, SUB(term__V66, 2)); int sub__V86_count = term__V66_count*LINK_COUNT(sub__V86); permitUnusedInt(sub__V86_count);
    /* sub__V86 = &#2 */
    NamedPropertyLink namedP__V87 = LINK_NamedPropertyLink(sink__V65->context, NAMED_PROPERTIES(term__V66));
    VariablePropertyLink varP__V88 = LINK_VariablePropertyLink(sink__V65->context, VARIABLE_PROPERTIES(term__V66));
    UNLINK(sink__V65->context, term__V66);
    ADD_PROPERTIES(sink__V65, LINK_NamedPropertyLink(sink__V65->context, namedP__V87), LINK_VariablePropertyLink(sink__V65->context, varP__V88));
    { START(sink__V65, _M_FormArguments__binder__count_s2);
      COPY(sink__V65, sub__V84);COPY(sink__V65, sub__V85);COPY(sink__V65, sub__V86);END(sink__V65, _M_FormArguments__binder__count_s2); }
    UNLINK_NamedPropertyLink(sink__V65->context, namedP__V87); UNLINK_VariablePropertyLink(sink__V65->context, varP__V88);
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION FormArguments-binder-count$2. */
int conBindOffs_M_FormArguments__binder__count_s2[] = {0 , 0 , 0 , 0};
char *nameFun_M_FormArguments__binder__count_s2(Term term) { return  "FormArguments-binder-count$2" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__count_s2 = {NULL, 0, 3, sizeof(STRUCT_Con_M_FormArguments__binder__count_s2), conBindOffs_M_FormArguments__binder__count_s2, &nameFun_M_FormArguments__binder__count_s2, &step_M_FormArguments__binder__count_s2};

int step_M_FormArguments__binder__count_s2(Sink sink__V89, Term term__V90)
{
  int term__V90_count = LINK_COUNT(term__V90); permitUnusedInt(term__V90_count);
  do {
    /* Contraction rule DEFS-FormArguments-binder-count-2. */
    ASSERT(sink__V89->context, !strcmp(SYMBOL(term__V90),  "FormArguments-binder-count$2" ));
    Term sub__V91 = SUB(term__V90, 0); permitUnusedTerm(sub__V91); int sub__V91_count = term__V90_count*LINK_COUNT(sub__V91); permitUnusedInt(sub__V91_count);
    CRSX_CHECK_SORT(sink__V89->context, sub__V91, &sort_M_Reified_xSort); /* sub__V91 = &#111 */
    Term sub__V92 = LINK(sink__V89->context, SUB(term__V90, 1)); int sub__V92_count = term__V90_count*LINK_COUNT(sub__V92); permitUnusedInt(sub__V92_count);
    /* sub__V92 = &#12 */
    Term sub__V93 = LINK(sink__V89->context, SUB(term__V90, 2)); int sub__V93_count = term__V90_count*LINK_COUNT(sub__V93); permitUnusedInt(sub__V93_count);
    /* sub__V93 = &#2 */
    UNLINK(sink__V89->context, term__V90);
    { START(sink__V89, _M_FormArguments__binder__count);
      COPY(sink__V89, sub__V92);COPY(sink__V89, sub__V93);END(sink__V89, _M_FormArguments__binder__count); }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION FormArguments-binder-count$3. */
int conBindOffs_M_FormArguments__binder__count_s3[] = {0 , 0 , 1 , 1 , 1};
char *nameFun_M_FormArguments__binder__count_s3(Term term) { return  "FormArguments-binder-count$3" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__count_s3 = {NULL, 0, 4, sizeof(STRUCT_Con_M_FormArguments__binder__count_s3), conBindOffs_M_FormArguments__binder__count_s3, &nameFun_M_FormArguments__binder__count_s3, &step_M_FormArguments__binder__count_s3};

int step_M_FormArguments__binder__count_s3(Sink sink__V94, Term term__V95)
{
  int term__V95_count = LINK_COUNT(term__V95); permitUnusedInt(term__V95_count);
  do {
    /* Contraction rule DEFS-FormArguments-binder-count-1. */
    ASSERT(sink__V94->context, !strcmp(SYMBOL(term__V95),  "FormArguments-binder-count$3" ));
    Term sub__V96 = SUB(term__V95, 0); permitUnusedTerm(sub__V96); int sub__V96_count = term__V95_count*LINK_COUNT(sub__V96); permitUnusedInt(sub__V96_count);
    CRSX_CHECK_SORT(sink__V94->context, sub__V96, &sort_M_Reified_xSort); /* sub__V96 = &#111 */
    Variable x__V97 = BINDER(term__V95,1,0); if (term__V95_count <= 1) UNBIND(x__V97);
    Term sub__V98 = LINK(sink__V94->context, SUB(term__V95, 1)); int sub__V98_count = term__V95_count*LINK_COUNT(sub__V98); permitUnusedInt(sub__V98_count);
    CRSX_CHECK_SORT(sink__V94->context, sub__V98, &sort_M_Reified_xFormArgument); /* sub__V98 = &#112 */
    Variable y__V99 = x__V97; permitUnusedVariable(y__V99);
    Term sub__V100 = LINK(sink__V94->context, SUB(term__V95, 2)); int sub__V100_count = term__V95_count*LINK_COUNT(sub__V100); permitUnusedInt(sub__V100_count);
    /* sub__V100 = &#12 */
    Term sub__V101 = LINK(sink__V94->context, SUB(term__V95, 3)); int sub__V101_count = term__V95_count*LINK_COUNT(sub__V101); permitUnusedInt(sub__V101_count);
    /* sub__V101 = &#2 */
    UNLINK(sink__V94->context, term__V95);
    { START(sink__V94, _M_FormArguments__binder__count);
      { START(sink__V94, _M__sCons);
        COPY(sink__V94, sub__V98); /* REUSED SUBSTITUTION */ COPY(sink__V94, sub__V100);END(sink__V94, _M__sCons); }
      { double num__V102;
        num__V102 = (double) 1; { double tmp__V103;
          tmp__V103 = DOUBLE(sub__V101); num__V102 += tmp__V103; }
        LITERALNF(sink__V94, (size_t) 31, "%G", num__V102); }
      END(sink__V94, _M_FormArguments__binder__count); }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION FormArguments-binder-count$4. */
int conBindOffs_M_FormArguments__binder__count_s4[] = {0 , 0};
char *nameFun_M_FormArguments__binder__count_s4(Term term) { return  "FormArguments-binder-count$4" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__count_s4 = {NULL, 0, 1, sizeof(STRUCT_Con_M_FormArguments__binder__count_s4), conBindOffs_M_FormArguments__binder__count_s4, &nameFun_M_FormArguments__binder__count_s4, &step_M_FormArguments__binder__count_s4};

int step_M_FormArguments__binder__count_s4(Sink sink__V104, Term term__V105)
{
  int term__V105_count = LINK_COUNT(term__V105); permitUnusedInt(term__V105_count);
  do {
    /* Contraction rule DEFS-FormArguments-binder-count-3. */
    ASSERT(sink__V104->context, !strcmp(SYMBOL(term__V105),  "FormArguments-binder-count$4" ));
    Term sub__V106 = LINK(sink__V104->context, SUB(term__V105, 0)); int sub__V106_count = term__V105_count*LINK_COUNT(sub__V106); permitUnusedInt(sub__V106_count);
    /* sub__V106 = &#2 */
    UNLINK(sink__V104->context, term__V105);
    COPY(sink__V104, sub__V106);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION FormArguments-binder-offsets. */
int conBindOffs_M_FormArguments__binder__offsets[] = {0 , 0 , 0};
char *nameFun_M_FormArguments__binder__offsets(Term term) { return  "FormArguments-binder-offsets" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__offsets = {NULL, 0, 2, sizeof(STRUCT_Con_M_FormArguments__binder__offsets), conBindOffs_M_FormArguments__binder__offsets, &nameFun_M_FormArguments__binder__offsets, &step_M_FormArguments__binder__offsets};

int step_M_FormArguments__binder__offsets(Sink sink__V107, Term term__V108)
{
  int term__V108_count = LINK_COUNT(term__V108); permitUnusedInt(term__V108_count);
  Term sub__V109 = FORCE(sink__V107->context, SUB(term__V108, 0));
  EnumOf_M__sList choice__V110 = (IS_VARIABLE_USE(sub__V109) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V109));
  switch (choice__V110)
  {
    case Data_M__sCons: { /* Function DEFS-FormArguments-binder-offsets-2$FormArguments-binder-offsets$$Cons case $Cons */
      ASSERT(sink__V107->context, !strcmp(SYMBOL(term__V108),  "FormArguments-binder-offsets" ));
      Term sub__V111 = SUB(term__V108, 0); permitUnusedTerm(sub__V111); int sub__V111_count = term__V108_count*LINK_COUNT(sub__V111); permitUnusedInt(sub__V111_count);
      ASSERT(sink__V107->context, !strcmp(SYMBOL(sub__V111),  "$Cons" ));
      Term sub__V112 = LINK(sink__V107->context, SUB(sub__V111, 0)); int sub__V112_count = sub__V111_count*LINK_COUNT(sub__V112); permitUnusedInt(sub__V112_count);
      /* sub__V112 = &#0-0 */
      Term sub__V113 = LINK(sink__V107->context, SUB(sub__V111, 1)); int sub__V113_count = sub__V111_count*LINK_COUNT(sub__V113); permitUnusedInt(sub__V113_count);
      /* sub__V113 = &#0-1 */
      Term sub__V114 = LINK(sink__V107->context, SUB(term__V108, 1)); int sub__V114_count = term__V108_count*LINK_COUNT(sub__V114); permitUnusedInt(sub__V114_count);
      /* sub__V114 = &#2 */
      NamedPropertyLink namedP__V115 = LINK_NamedPropertyLink(sink__V107->context, NAMED_PROPERTIES(term__V108));
      VariablePropertyLink varP__V116 = LINK_VariablePropertyLink(sink__V107->context, VARIABLE_PROPERTIES(term__V108));
      UNLINK(sink__V107->context, term__V108);
      ADD_PROPERTIES(sink__V107, LINK_NamedPropertyLink(sink__V107->context, namedP__V115), LINK_VariablePropertyLink(sink__V107->context, varP__V116));
      { START(sink__V107, _M_FormArguments__binder__offsets_s1);
        COPY(sink__V107, sub__V112);COPY(sink__V107, sub__V113);COPY(sink__V107, sub__V114);END(sink__V107, _M_FormArguments__binder__offsets_s1); }
      UNLINK_NamedPropertyLink(sink__V107->context, namedP__V115); UNLINK_VariablePropertyLink(sink__V107->context, varP__V116);
      
      return 1;
    break; } case Data_M__sNil: { /* Function DEFS-FormArguments-binder-offsets-3$FormArguments-binder-offsets$$Nil case $Nil */
      ASSERT(sink__V107->context, !strcmp(SYMBOL(term__V108),  "FormArguments-binder-offsets" ));
      Term sub__V117 = SUB(term__V108, 0); permitUnusedTerm(sub__V117); int sub__V117_count = term__V108_count*LINK_COUNT(sub__V117); permitUnusedInt(sub__V117_count);
      ASSERT(sink__V107->context, !strcmp(SYMBOL(sub__V117),  "$Nil" ));
      Term sub__V118 = LINK(sink__V107->context, SUB(term__V108, 1)); int sub__V118_count = term__V108_count*LINK_COUNT(sub__V118); permitUnusedInt(sub__V118_count);
      /* sub__V118 = &#0 */
      NamedPropertyLink namedP__V119 = LINK_NamedPropertyLink(sink__V107->context, NAMED_PROPERTIES(term__V108));
      VariablePropertyLink varP__V120 = LINK_VariablePropertyLink(sink__V107->context, VARIABLE_PROPERTIES(term__V108));
      UNLINK(sink__V107->context, term__V108);
      ADD_PROPERTIES(sink__V107, LINK_NamedPropertyLink(sink__V107->context, namedP__V119), LINK_VariablePropertyLink(sink__V107->context, varP__V120));
      { START(sink__V107, _M_FormArguments__binder__offsets_s4);
        COPY(sink__V107, sub__V118);END(sink__V107, _M_FormArguments__binder__offsets_s4); }
      UNLINK_NamedPropertyLink(sink__V107->context, namedP__V119); UNLINK_VariablePropertyLink(sink__V107->context, varP__V120);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION COMMENT_TOKEN. */
int conBindOffs_M_COMMENT_xTOKEN[] = {0 , 0};
char *nameFun_M_COMMENT_xTOKEN(Term term) { return  "COMMENT_TOKEN" ; }
struct _ConstructionDescriptor descriptor_M_COMMENT_xTOKEN = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_COMMENT_xTOKEN), conBindOffs_M_COMMENT_xTOKEN, &nameFun_M_COMMENT_xTOKEN, &step_M_COMMENT_xTOKEN};

int step_M_COMMENT_xTOKEN(Sink sink__V121, Term term__V122)
{
  int term__V122_count = LINK_COUNT(term__V122); permitUnusedInt(term__V122_count);
  do {
    /* Contraction rule DEFS-COMMENT_TOKEN-1. */
    ASSERT(sink__V121->context, !strcmp(SYMBOL(term__V122),  "COMMENT_TOKEN" ));
    Term sub__V123 = LINK(sink__V121->context, SUB(term__V122, 0)); int sub__V123_count = term__V122_count*LINK_COUNT(sub__V123); permitUnusedInt(sub__V123_count);
    UNLINK_SUB(sink__V121->context, term__V122,  0); NORMALIZE(sink__V121->context, sub__V123); SUB(term__V122,  0) = LINK(sink__V121->context, sub__V123);
    /* sub__V123 = &#1 */
    NamedPropertyLink namedP__V124 = LINK_NamedPropertyLink(sink__V121->context, NAMED_PROPERTIES(term__V122));
    VariablePropertyLink varP__V125 = LINK_VariablePropertyLink(sink__V121->context, VARIABLE_PROPERTIES(term__V122));
    UNLINK(sink__V121->context, term__V122);
    { START(sink__V121, _M__sTextCons);
      { START(sink__V121, _M__sTextChars);
        { char *str__V126;
          FORCE(sink__V121->context, sub__V123);
          { char *replaced__V127;
            const size_t z = strlen(SYMBOL(sub__V123));
            if (* "*/" ) {
              const size_t oldz = strlen( "*/" ), newz = strlen( "*_/" );
              size_t limitz;
              if (oldz==newz) { limitz = z; }
              else { limitz = z; size_t growz = (oldz < newz ? newz - oldz : 0);
                if (growz > 0) { char *p = SYMBOL(sub__V123); while ((p = strstr(p,  "*/" ))) { limitz += growz; p += oldz; } } }
              replaced__V127 = ALLOCA(sink__V121->context, limitz+1);
              if (oldz==newz) { memcpy(replaced__V127, SYMBOL(sub__V123), z+1);
                char *r = replaced__V127; while ((r = strstr(r,  "*/" ))) { memcpy(r,  "*_/" , newz); r += oldz; } }
              else { char *s = SYMBOL(sub__V123), *ends = s+z, *r = replaced__V127, *next;
                while ((next = strstr(s,  "*/" ))) { size_t prez = next-s;
                  if (prez) { memcpy(r, s, prez); r += prez; } 
                  if (newz) { memcpy(r,  "*_/" , newz); r += newz; }
                  s = next+oldz;}
                if (s < ends) { memcpy(r, s, ends-s); r += ends-s; }
                *r = '\0';}
              }
            else { replaced__V127 = memcpy(ALLOCA(sink__V121->context, z+1), SYMBOL(sub__V123), z+1); }
             UNLINK(sink__V121->context, sub__V123);{ size_t z__V128 = strlen(replaced__V127) + 1; memcpy(str__V126 = ALLOCATE(sink__V121->context, z__V128), replaced__V127, z__V128); }
            
          }LITERALU(sink__V121, str__V126); }
        END(sink__V121, _M__sTextChars); }
      { START(sink__V121, _M__sTextNil);
        END(sink__V121, _M__sTextNil); }
      END(sink__V121, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V121->context, namedP__V124); UNLINK_VariablePropertyLink(sink__V121->context, varP__V125);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION STRING. */
int conBindOffs_M_STRING[] = {0 , 0};
char *nameFun_M_STRING(Term term) { return  "STRING" ; }
struct _ConstructionDescriptor descriptor_M_STRING = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_STRING), conBindOffs_M_STRING, &nameFun_M_STRING, &step_M_STRING};

int step_M_STRING(Sink sink__V129, Term term__V130)
{
  int term__V130_count = LINK_COUNT(term__V130); permitUnusedInt(term__V130_count);
  do {
    /* Contraction rule DEFS-STRING-1. */
    ASSERT(sink__V129->context, !strcmp(SYMBOL(term__V130),  "STRING" ));
    Term sub__V131 = LINK(sink__V129->context, SUB(term__V130, 0)); int sub__V131_count = term__V130_count*LINK_COUNT(sub__V131); permitUnusedInt(sub__V131_count);
    UNLINK_SUB(sink__V129->context, term__V130,  0); NORMALIZE(sink__V129->context, sub__V131); SUB(term__V130,  0) = LINK(sink__V129->context, sub__V131);
    /* sub__V131 = &#1 */
    NamedPropertyLink namedP__V132 = LINK_NamedPropertyLink(sink__V129->context, NAMED_PROPERTIES(term__V130));
    VariablePropertyLink varP__V133 = LINK_VariablePropertyLink(sink__V129->context, VARIABLE_PROPERTIES(term__V130));
    UNLINK(sink__V129->context, term__V130);
    { START(sink__V129, _M__sTextCons);
      { START(sink__V129, _M__sTextChars);
        LITERAL(sink__V129,  " " ); END(sink__V129, _M__sTextChars); }
      { START(sink__V129, _M__sTextCons);
        { START(sink__V129, _M__sTextString);
          { START(sink__V129, _M__sTextCons);
            { START(sink__V129, _M__sTextChars);
              { char *str__V134;
                FORCE(sink__V129->context, sub__V131);
                {str__V134 = makeEscaped(sink__V129->context, SYMBOL(sub__V131));
                  UNLINK(sink__V129->context, sub__V131);}
                LITERALU(sink__V129, str__V134); }
              END(sink__V129, _M__sTextChars); }
            { START(sink__V129, _M__sTextNil);
              END(sink__V129, _M__sTextNil); }
            END(sink__V129, _M__sTextCons); }
          END(sink__V129, _M__sTextString); }
        { START(sink__V129, _M__sTextCons);
          { START(sink__V129, _M__sTextChars);
            LITERAL(sink__V129,  " " ); END(sink__V129, _M__sTextChars); }
          { START(sink__V129, _M__sTextNil);
            END(sink__V129, _M__sTextNil); }
          END(sink__V129, _M__sTextCons); }
        END(sink__V129, _M__sTextCons); }
      END(sink__V129, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V129->context, namedP__V132); UNLINK_VariablePropertyLink(sink__V129->context, varP__V133);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION SortNames. */
int conBindOffs_M_SortNames[] = {0 , 0};
char *nameFun_M_SortNames(Term term) { return  "SortNames" ; }
struct _ConstructionDescriptor descriptor_M_SortNames = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_SortNames), conBindOffs_M_SortNames, &nameFun_M_SortNames, &step_M_SortNames};

int step_M_SortNames(Sink sink__V135, Term term__V136)
{
  int term__V136_count = LINK_COUNT(term__V136); permitUnusedInt(term__V136_count);
  do {
    /* Contraction rule DEFS-SortNames-1. */
    ASSERT(sink__V135->context, !strcmp(SYMBOL(term__V136),  "SortNames" ));
    Term sub__V137 = LINK(sink__V135->context, SUB(term__V136, 0)); int sub__V137_count = term__V136_count*LINK_COUNT(sub__V137); permitUnusedInt(sub__V137_count);
    /* sub__V137 = &#1 */
    NamedPropertyLink namedP__V138 = LINK_NamedPropertyLink(sink__V135->context, NAMED_PROPERTIES(term__V136));
    VariablePropertyLink varP__V139 = LINK_VariablePropertyLink(sink__V135->context, VARIABLE_PROPERTIES(term__V136));
    UNLINK(sink__V135->context, term__V136);
    { START(sink__V135, _M__sTextCons);
      { START(sink__V135, _M__sTextChars);
        LITERAL(sink__V135,  "sortNam" ); END(sink__V135, _M__sTextChars); }
      { START(sink__V135, _M__sTextCons);
        { START(sink__V135, _M__sTextEmbed);
          { START(sink__V135, _M_AsText);
            { START(sink__V135, _M_MANGLE);
              COPY(sink__V135, sub__V137);END(sink__V135, _M_MANGLE); }
            END(sink__V135, _M_AsText); }
          END(sink__V135, _M__sTextEmbed); }
        { START(sink__V135, _M__sTextNil);
          END(sink__V135, _M__sTextNil); }
        END(sink__V135, _M__sTextCons); }
      END(sink__V135, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V135->context, namedP__V138); UNLINK_VariablePropertyLink(sink__V135->context, varP__V139);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION FormArguments-binder-count. */
int conBindOffs_M_FormArguments__binder__count[] = {0 , 0 , 0};
char *nameFun_M_FormArguments__binder__count(Term term) { return  "FormArguments-binder-count" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__count = {NULL, 0, 2, sizeof(STRUCT_Con_M_FormArguments__binder__count), conBindOffs_M_FormArguments__binder__count, &nameFun_M_FormArguments__binder__count, &step_M_FormArguments__binder__count};

int step_M_FormArguments__binder__count(Sink sink__V140, Term term__V141)
{
  int term__V141_count = LINK_COUNT(term__V141); permitUnusedInt(term__V141_count);
  Term sub__V142 = FORCE(sink__V140->context, SUB(term__V141, 0));
  EnumOf_M__sList choice__V143 = (IS_VARIABLE_USE(sub__V142) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V142));
  switch (choice__V143)
  {
    case Data_M__sCons: { /* Function DEFS-FormArguments-binder-count-2$FormArguments-binder-count$$Cons case $Cons */
      ASSERT(sink__V140->context, !strcmp(SYMBOL(term__V141),  "FormArguments-binder-count" ));
      Term sub__V144 = SUB(term__V141, 0); permitUnusedTerm(sub__V144); int sub__V144_count = term__V141_count*LINK_COUNT(sub__V144); permitUnusedInt(sub__V144_count);
      ASSERT(sink__V140->context, !strcmp(SYMBOL(sub__V144),  "$Cons" ));
      Term sub__V145 = LINK(sink__V140->context, SUB(sub__V144, 0)); int sub__V145_count = sub__V144_count*LINK_COUNT(sub__V145); permitUnusedInt(sub__V145_count);
      /* sub__V145 = &#0-0 */
      Term sub__V146 = LINK(sink__V140->context, SUB(sub__V144, 1)); int sub__V146_count = sub__V144_count*LINK_COUNT(sub__V146); permitUnusedInt(sub__V146_count);
      /* sub__V146 = &#0-1 */
      Term sub__V147 = LINK(sink__V140->context, SUB(term__V141, 1)); int sub__V147_count = term__V141_count*LINK_COUNT(sub__V147); permitUnusedInt(sub__V147_count);
      /* sub__V147 = &#2 */
      NamedPropertyLink namedP__V148 = LINK_NamedPropertyLink(sink__V140->context, NAMED_PROPERTIES(term__V141));
      VariablePropertyLink varP__V149 = LINK_VariablePropertyLink(sink__V140->context, VARIABLE_PROPERTIES(term__V141));
      UNLINK(sink__V140->context, term__V141);
      ADD_PROPERTIES(sink__V140, LINK_NamedPropertyLink(sink__V140->context, namedP__V148), LINK_VariablePropertyLink(sink__V140->context, varP__V149));
      { START(sink__V140, _M_FormArguments__binder__count_s1);
        COPY(sink__V140, sub__V145);COPY(sink__V140, sub__V146);COPY(sink__V140, sub__V147);END(sink__V140, _M_FormArguments__binder__count_s1); }
      UNLINK_NamedPropertyLink(sink__V140->context, namedP__V148); UNLINK_VariablePropertyLink(sink__V140->context, varP__V149);
      
      return 1;
    break; } case Data_M__sNil: { /* Function DEFS-FormArguments-binder-count-3$FormArguments-binder-count$$Nil case $Nil */
      ASSERT(sink__V140->context, !strcmp(SYMBOL(term__V141),  "FormArguments-binder-count" ));
      Term sub__V150 = SUB(term__V141, 0); permitUnusedTerm(sub__V150); int sub__V150_count = term__V141_count*LINK_COUNT(sub__V150); permitUnusedInt(sub__V150_count);
      ASSERT(sink__V140->context, !strcmp(SYMBOL(sub__V150),  "$Nil" ));
      Term sub__V151 = LINK(sink__V140->context, SUB(term__V141, 1)); int sub__V151_count = term__V141_count*LINK_COUNT(sub__V151); permitUnusedInt(sub__V151_count);
      /* sub__V151 = &#0 */
      NamedPropertyLink namedP__V152 = LINK_NamedPropertyLink(sink__V140->context, NAMED_PROPERTIES(term__V141));
      VariablePropertyLink varP__V153 = LINK_VariablePropertyLink(sink__V140->context, VARIABLE_PROPERTIES(term__V141));
      UNLINK(sink__V140->context, term__V141);
      ADD_PROPERTIES(sink__V140, LINK_NamedPropertyLink(sink__V140->context, namedP__V152), LINK_VariablePropertyLink(sink__V140->context, varP__V153));
      { START(sink__V140, _M_FormArguments__binder__count_s4);
        COPY(sink__V140, sub__V151);END(sink__V140, _M_FormArguments__binder__count_s4); }
      UNLINK_NamedPropertyLink(sink__V140->context, namedP__V152); UNLINK_VariablePropertyLink(sink__V140->context, varP__V153);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION DSTRING$1. */
int conBindOffs_M_DSTRING_s1[] = {0 , 0};
char *nameFun_M_DSTRING_s1(Term term) { return  "DSTRING$1" ; }
struct _ConstructionDescriptor descriptor_M_DSTRING_s1 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_DSTRING_s1), conBindOffs_M_DSTRING_s1, &nameFun_M_DSTRING_s1, &step_M_DSTRING_s1};

int step_M_DSTRING_s1(Sink sink__V154, Term term__V155)
{
  int term__V155_count = LINK_COUNT(term__V155); permitUnusedInt(term__V155_count);
  do {
    /* Contraction rule DEFS-DSTRING-1. */
    ASSERT(sink__V154->context, !strcmp(SYMBOL(term__V155),  "DSTRING$1" ));
    Term sub__V156 = LINK(sink__V154->context, SUB(term__V155, 0)); int sub__V156_count = term__V155_count*LINK_COUNT(sub__V156); permitUnusedInt(sub__V156_count);
    UNLINK_SUB(sink__V154->context, term__V155,  0); NORMALIZE(sink__V154->context, sub__V156); SUB(term__V155,  0) = LINK(sink__V154->context, sub__V156);
    /* sub__V156 = &#2 */
    NamedPropertyLink namedP__V157 = LINK_NamedPropertyLink(sink__V154->context, NAMED_PROPERTIES(term__V155));
    VariablePropertyLink varP__V158 = LINK_VariablePropertyLink(sink__V154->context, VARIABLE_PROPERTIES(term__V155));
    UNLINK(sink__V154->context, term__V155);
    { START(sink__V154, _M__sTextCons);
      { START(sink__V154, _M__sTextChars);
        LITERAL(sink__V154,  " " ); END(sink__V154, _M__sTextChars); }
      { START(sink__V154, _M__sTextCons);
        { START(sink__V154, _M__sTextString);
          { START(sink__V154, _M__sTextCons);
            { START(sink__V154, _M__sTextChars);
              { char *str__V159;
                FORCE(sink__V154->context, sub__V156);
                {str__V159 = makeEscaped(sink__V154->context, SYMBOL(sub__V156));
                  UNLINK(sink__V154->context, sub__V156);}
                LITERALU(sink__V154, str__V159); }
              END(sink__V154, _M__sTextChars); }
            { START(sink__V154, _M__sTextNil);
              END(sink__V154, _M__sTextNil); }
            END(sink__V154, _M__sTextCons); }
          END(sink__V154, _M__sTextString); }
        { START(sink__V154, _M__sTextCons);
          { START(sink__V154, _M__sTextChars);
            LITERAL(sink__V154,  " " ); END(sink__V154, _M__sTextChars); }
          { START(sink__V154, _M__sTextNil);
            END(sink__V154, _M__sTextNil); }
          END(sink__V154, _M__sTextCons); }
        END(sink__V154, _M__sTextCons); }
      END(sink__V154, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V154->context, namedP__V157); UNLINK_VariablePropertyLink(sink__V154->context, varP__V158);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DelayMapText$1. */
int conBindOffs_M_DelayMapText_s1[] = {0 , 0 , 2};
char *nameFun_M_DelayMapText_s1(Term term) { return  "DelayMapText$1" ; }
struct _ConstructionDescriptor descriptor_M_DelayMapText_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_DelayMapText_s1), conBindOffs_M_DelayMapText_s1, &nameFun_M_DelayMapText_s1, &step_M_DelayMapText_s1};

int step_M_DelayMapText_s1(Sink sink__V160, Term term__V161)
{
  int term__V161_count = LINK_COUNT(term__V161); permitUnusedInt(term__V161_count);
  Term sub__V162 = FORCE(sink__V160->context, SUB(term__V161, 0));
  EnumOf_M__sList choice__V163 = (IS_VARIABLE_USE(sub__V162) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V162));
  switch (choice__V163)
  {
    case Data_M__sCons: { /* Function DEFS-DelayMapText-1$DelayMapText$1$$Cons case $Cons */
      ASSERT(sink__V160->context, !strcmp(SYMBOL(term__V161),  "DelayMapText$1" ));
      Term sub__V164 = SUB(term__V161, 0); permitUnusedTerm(sub__V164); int sub__V164_count = term__V161_count*LINK_COUNT(sub__V164); permitUnusedInt(sub__V164_count);
      ASSERT(sink__V160->context, !strcmp(SYMBOL(sub__V164),  "$Cons" ));
      Term sub__V165 = LINK(sink__V160->context, SUB(sub__V164, 0)); int sub__V165_count = sub__V164_count*LINK_COUNT(sub__V165); permitUnusedInt(sub__V165_count);
      /* sub__V165 = &#0-0 */
      Term sub__V166 = LINK(sink__V160->context, SUB(sub__V164, 1)); int sub__V166_count = sub__V164_count*LINK_COUNT(sub__V166); permitUnusedInt(sub__V166_count);
      /* sub__V166 = &#0-1 */
      Variable x__V167 = BINDER(term__V161,1,0); if (term__V161_count <= 1) UNBIND(x__V167);
      Variable x__V168 = BINDER(term__V161,1,1); if (term__V161_count <= 1) UNBIND(x__V168);
      Term sub__V169 = LINK(sink__V160->context, SUB(term__V161, 1)); int sub__V169_count = term__V161_count*LINK_COUNT(sub__V169); permitUnusedInt(sub__V169_count);
      CRSX_CHECK_SORT(sink__V160->context, sub__V169, &sort_M_Reified_xVariable); /* sub__V169 = &#2 */
      NamedPropertyLink namedP__V170 = LINK_NamedPropertyLink(sink__V160->context, NAMED_PROPERTIES(term__V161));
      VariablePropertyLink varP__V171 = LINK_VariablePropertyLink(sink__V160->context, VARIABLE_PROPERTIES(term__V161));
      UNLINK(sink__V160->context, term__V161);
      ADD_PROPERTIES(sink__V160, LINK_NamedPropertyLink(sink__V160->context, namedP__V170), LINK_VariablePropertyLink(sink__V160->context, varP__V171));
      { START(sink__V160, _M_DelayMapText_s2);
        COPY(sink__V160, sub__V165);COPY(sink__V160, sub__V166);{ if (!IS_BOUND(x__V167)) { REBIND(x__V167);
            REBIND(x__V168);
            Variable binds__V172[2] = {x__V167,x__V168}; BINDS(sink__V160, 2, binds__V172);
            COPY(sink__V160, sub__V169); /* REUSED SUBSTITUTION */  }
          else { Variable b__V173 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V160->context,"b__V173");
            Variable b__V174 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V160->context,"b__V174");
            Variable binds__V175[2] = {b__V173,b__V174}; BINDS(sink__V160, 2, binds__V175);
            {
              Term arg__V176;
              { Sink buf__V177 = ALLOCA_BUFFER(sink__V160->context);
                USE(buf__V177, b__V173); arg__V176 = BUFFER_TERM(buf__V177); FREE_BUFFER(buf__V177); }
              Term arg__V178;
              { Sink buf__V179 = ALLOCA_BUFFER(sink__V160->context);
                USE(buf__V179, b__V174); arg__V178 = BUFFER_TERM(buf__V179); FREE_BUFFER(buf__V179); }
              Variable vars__V180[2] = {x__V167,x__V168};
              Term args__V181[2] = {arg__V176,arg__V178};
              struct _SubstitutionFrame substitution__V182 = {NULL, 0, 2, vars__V180, args__V181, NULL};
              SUBSTITUTE(sink__V160, sub__V169, &substitution__V182); }
                }
           }
        END(sink__V160, _M_DelayMapText_s2); }
      UNLINK_NamedPropertyLink(sink__V160->context, namedP__V170); UNLINK_VariablePropertyLink(sink__V160->context, varP__V171);
      
      return 1;
    break; } case Data_M__sNil: { /* Function DEFS-DelayMapText-2$DelayMapText$1$$Nil case $Nil */
      ASSERT(sink__V160->context, !strcmp(SYMBOL(term__V161),  "DelayMapText$1" ));
      Term sub__V183 = SUB(term__V161, 0); permitUnusedTerm(sub__V183); int sub__V183_count = term__V161_count*LINK_COUNT(sub__V183); permitUnusedInt(sub__V183_count);
      ASSERT(sink__V160->context, !strcmp(SYMBOL(sub__V183),  "$Nil" ));
      Variable x__V184 = BINDER(term__V161,1,0); if (term__V161_count <= 1) UNBIND(x__V184);
      Variable x__V185 = BINDER(term__V161,1,1); if (term__V161_count <= 1) UNBIND(x__V185);
      Term sub__V186 = LINK(sink__V160->context, SUB(term__V161, 1)); int sub__V186_count = term__V161_count*LINK_COUNT(sub__V186); permitUnusedInt(sub__V186_count);
      CRSX_CHECK_SORT(sink__V160->context, sub__V186, &sort_M_Reified_xVariable); /* sub__V186 = &#0 */
      NamedPropertyLink namedP__V187 = LINK_NamedPropertyLink(sink__V160->context, NAMED_PROPERTIES(term__V161));
      VariablePropertyLink varP__V188 = LINK_VariablePropertyLink(sink__V160->context, VARIABLE_PROPERTIES(term__V161));
      UNLINK(sink__V160->context, term__V161);
      ADD_PROPERTIES(sink__V160, LINK_NamedPropertyLink(sink__V160->context, namedP__V187), LINK_VariablePropertyLink(sink__V160->context, varP__V188));
      { START(sink__V160, _M_DelayMapText_s3);
        { if (!IS_BOUND(x__V184)) { REBIND(x__V184);
            REBIND(x__V185);
            Variable binds__V189[2] = {x__V184,x__V185}; BINDS(sink__V160, 2, binds__V189);
            COPY(sink__V160, sub__V186); /* REUSED SUBSTITUTION */  }
          else { Variable b__V190 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V160->context,"b__V190");
            Variable b__V191 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V160->context,"b__V191");
            Variable binds__V192[2] = {b__V190,b__V191}; BINDS(sink__V160, 2, binds__V192);
            {
              Term arg__V193;
              { Sink buf__V194 = ALLOCA_BUFFER(sink__V160->context);
                USE(buf__V194, b__V190); arg__V193 = BUFFER_TERM(buf__V194); FREE_BUFFER(buf__V194); }
              Term arg__V195;
              { Sink buf__V196 = ALLOCA_BUFFER(sink__V160->context);
                USE(buf__V196, b__V191); arg__V195 = BUFFER_TERM(buf__V196); FREE_BUFFER(buf__V196); }
              Variable vars__V197[2] = {x__V184,x__V185};
              Term args__V198[2] = {arg__V193,arg__V195};
              struct _SubstitutionFrame substitution__V199 = {NULL, 0, 2, vars__V197, args__V198, NULL};
              SUBSTITUTE(sink__V160, sub__V186, &substitution__V199); }
                }
           }
        END(sink__V160, _M_DelayMapText_s3); }
      UNLINK_NamedPropertyLink(sink__V160->context, namedP__V187); UNLINK_VariablePropertyLink(sink__V160->context, varP__V188);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION DelayMapText$2. */
int conBindOffs_M_DelayMapText_s2[] = {0 , 0 , 0 , 2};
char *nameFun_M_DelayMapText_s2(Term term) { return  "DelayMapText$2" ; }
struct _ConstructionDescriptor descriptor_M_DelayMapText_s2 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_DelayMapText_s2), conBindOffs_M_DelayMapText_s2, &nameFun_M_DelayMapText_s2, &step_M_DelayMapText_s2};

int step_M_DelayMapText_s2(Sink sink__V200, Term term__V201)
{
  int term__V201_count = LINK_COUNT(term__V201); permitUnusedInt(term__V201_count);
  do {
    /* Contraction rule DEFS-DelayMapText-1. */
    ASSERT(sink__V200->context, !strcmp(SYMBOL(term__V201),  "DelayMapText$2" ));
    Term sub__V202 = LINK(sink__V200->context, SUB(term__V201, 0)); int sub__V202_count = term__V201_count*LINK_COUNT(sub__V202); permitUnusedInt(sub__V202_count);
    /* sub__V202 = &#21 */
    Term sub__V203 = LINK(sink__V200->context, SUB(term__V201, 1)); int sub__V203_count = term__V201_count*LINK_COUNT(sub__V203); permitUnusedInt(sub__V203_count);
    /* sub__V203 = &#22 */
    Variable x__V204 = BINDER(term__V201,2,0); if (term__V201_count <= 1) UNBIND(x__V204);
    Variable x__V205 = BINDER(term__V201,2,1); if (term__V201_count <= 1) UNBIND(x__V205);
    Term sub__V206 = LINK(sink__V200->context, SUB(term__V201, 2)); int sub__V206_count = term__V201_count*LINK_COUNT(sub__V206); permitUnusedInt(sub__V206_count);
    CRSX_CHECK_SORT(sink__V200->context, sub__V206, &sort_M_Reified_xVariable); UNLINK_SUB(sink__V200->context, term__V201,  2); NORMALIZE(sink__V200->context, sub__V206); SUB(term__V201,  2) = LINK(sink__V200->context, sub__V206);
    /* sub__V206 = &#1 */
    NamedPropertyLink namedP__V207 = LINK_NamedPropertyLink(sink__V200->context, NAMED_PROPERTIES(term__V201));
    VariablePropertyLink varP__V208 = LINK_VariablePropertyLink(sink__V200->context, VARIABLE_PROPERTIES(term__V201));
    UNLINK(sink__V200->context, term__V201);
    { START(sink__V200, _M__sTextCons);
      { START(sink__V200, _M__sTextEmbed);
        { START(sink__V200, _M_AsText);
          {
            Term arg__V209;
            { Sink buf__V210 = ALLOCA_BUFFER(sink__V200->context);
              { START(buf__V210, _M_OK); END(buf__V210, _M_OK); } arg__V209 = BUFFER_TERM(buf__V210); FREE_BUFFER(buf__V210); }
            Term arg__V211;
            { Sink buf__V212 = ALLOCA_BUFFER(sink__V200->context);
              COPY(buf__V212, sub__V202);arg__V211 = BUFFER_TERM(buf__V212); FREE_BUFFER(buf__V212); }
            Variable vars__V213[2] = {x__V204,x__V205};
            Term args__V214[2] = {arg__V209,arg__V211};
            struct _SubstitutionFrame substitution__V215 = {NULL, 0, 2, vars__V213, args__V214, NULL};
            SUBSTITUTE(sink__V200, LINK(sink__V200->context,sub__V206), &substitution__V215); }
          END(sink__V200, _M_AsText); }
        END(sink__V200, _M__sTextEmbed); }
      { START(sink__V200, _M__sTextCons);
        { START(sink__V200, _M__sTextEmbed);
          { START(sink__V200, _M_AsText);
            { START(sink__V200, _M_DelayMapText_s1);
              COPY(sink__V200, sub__V203);{ Variable x__V216 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V200->context,"x__V216");
                Variable x__V217 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V200->context,"x__V217");
                Variable binds__V218[2] = {x__V216,x__V217}; BINDS(sink__V200, 2, binds__V218);
                {
                  Term arg__V219;
                  { Sink buf__V220 = ALLOCA_BUFFER(sink__V200->context);
                    USE(buf__V220, x__V216); arg__V219 = BUFFER_TERM(buf__V220); FREE_BUFFER(buf__V220); }
                  Term arg__V221;
                  { Sink buf__V222 = ALLOCA_BUFFER(sink__V200->context);
                    USE(buf__V222, x__V217); arg__V221 = BUFFER_TERM(buf__V222); FREE_BUFFER(buf__V222); }
                  Variable vars__V223[2] = {x__V204,x__V205};
                  Term args__V224[2] = {arg__V219,arg__V221};
                  struct _SubstitutionFrame substitution__V225 = {NULL, 0, 2, vars__V223, args__V224, NULL};
                  SUBSTITUTE(sink__V200, sub__V206, &substitution__V225); }
                 }
              END(sink__V200, _M_DelayMapText_s1); }
            END(sink__V200, _M_AsText); }
          END(sink__V200, _M__sTextEmbed); }
        { START(sink__V200, _M__sTextNil);
          END(sink__V200, _M__sTextNil); }
        END(sink__V200, _M__sTextCons); }
      END(sink__V200, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V200->context, namedP__V207); UNLINK_VariablePropertyLink(sink__V200->context, varP__V208);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DelayMapText$3. */
int conBindOffs_M_DelayMapText_s3[] = {0 , 2};
char *nameFun_M_DelayMapText_s3(Term term) { return  "DelayMapText$3" ; }
struct _ConstructionDescriptor descriptor_M_DelayMapText_s3 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_DelayMapText_s3), conBindOffs_M_DelayMapText_s3, &nameFun_M_DelayMapText_s3, &step_M_DelayMapText_s3};

int step_M_DelayMapText_s3(Sink sink__V226, Term term__V227)
{
  int term__V227_count = LINK_COUNT(term__V227); permitUnusedInt(term__V227_count);
  do {
    /* Contraction rule DEFS-DelayMapText-2. */
    ASSERT(sink__V226->context, !strcmp(SYMBOL(term__V227),  "DelayMapText$3" ));
    Variable x__V228 = BINDER(term__V227,0,0); if (term__V227_count <= 1) UNBIND(x__V228);
    Variable x__V229 = BINDER(term__V227,0,1); if (term__V227_count <= 1) UNBIND(x__V229);
    Term sub__V230 = SUB(term__V227, 0); permitUnusedTerm(sub__V230); int sub__V230_count = term__V227_count*LINK_COUNT(sub__V230); permitUnusedInt(sub__V230_count);
    CRSX_CHECK_SORT(sink__V226->context, sub__V230, &sort_M_Reified_xVariable); /* sub__V230 = &#1 */
    NamedPropertyLink namedP__V231 = LINK_NamedPropertyLink(sink__V226->context, NAMED_PROPERTIES(term__V227));
    VariablePropertyLink varP__V232 = LINK_VariablePropertyLink(sink__V226->context, VARIABLE_PROPERTIES(term__V227));
    UNLINK(sink__V226->context, term__V227);
    { START(sink__V226, _M__sTextNil); END(sink__V226, _M__sTextNil); }
    UNLINK_NamedPropertyLink(sink__V226->context, namedP__V231); UNLINK_VariablePropertyLink(sink__V226->context, varP__V232);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Forms-Constructors. */
int conBindOffs_M_Forms_Constructors[] = {0 , 0};
char *nameFun_M_Forms_Constructors(Term term) { return  "Forms-Constructors" ; }
struct _ConstructionDescriptor descriptor_M_Forms_Constructors = {NULL, 0, 1, sizeof(STRUCT_Con_M_Forms_Constructors), conBindOffs_M_Forms_Constructors, &nameFun_M_Forms_Constructors, &step_M_Forms_Constructors};

int step_M_Forms_Constructors(Sink sink__V233, Term term__V234)
{
  int term__V234_count = LINK_COUNT(term__V234); permitUnusedInt(term__V234_count);
  Term sub__V235 = FORCE(sink__V233->context, SUB(term__V234, 0));
  EnumOf_M__sList choice__V236 = (IS_VARIABLE_USE(sub__V235) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V235));
  switch (choice__V236)
  {
    case Data_M__sCons: { /* Function DEFS-Forms-Constructors-3$Forms-Constructors$$Cons case $Cons */
      ASSERT(sink__V233->context, !strcmp(SYMBOL(term__V234),  "Forms-Constructors" ));
      Term sub__V237 = SUB(term__V234, 0); permitUnusedTerm(sub__V237); int sub__V237_count = term__V234_count*LINK_COUNT(sub__V237); permitUnusedInt(sub__V237_count);
      ASSERT(sink__V233->context, !strcmp(SYMBOL(sub__V237),  "$Cons" ));
      Term sub__V238 = LINK(sink__V233->context, SUB(sub__V237, 0)); int sub__V238_count = sub__V237_count*LINK_COUNT(sub__V238); permitUnusedInt(sub__V238_count);
      /* sub__V238 = &#0-0 */
      Term sub__V239 = LINK(sink__V233->context, SUB(sub__V237, 1)); int sub__V239_count = sub__V237_count*LINK_COUNT(sub__V239); permitUnusedInt(sub__V239_count);
      /* sub__V239 = &#0-1 */
      NamedPropertyLink namedP__V240 = LINK_NamedPropertyLink(sink__V233->context, NAMED_PROPERTIES(term__V234));
      VariablePropertyLink varP__V241 = LINK_VariablePropertyLink(sink__V233->context, VARIABLE_PROPERTIES(term__V234));
      UNLINK(sink__V233->context, term__V234);
      ADD_PROPERTIES(sink__V233, LINK_NamedPropertyLink(sink__V233->context, namedP__V240), LINK_VariablePropertyLink(sink__V233->context, varP__V241));
      { START(sink__V233, _M_Forms_Constructors_s1);
        COPY(sink__V233, sub__V238);COPY(sink__V233, sub__V239);END(sink__V233, _M_Forms_Constructors_s1); }
      UNLINK_NamedPropertyLink(sink__V233->context, namedP__V240); UNLINK_VariablePropertyLink(sink__V233->context, varP__V241);
      
      return 1;
    break; } case Data_M__sNil: { /* Function DEFS-Forms-Constructors-4$Forms-Constructors$$Nil case $Nil */
      ASSERT(sink__V233->context, !strcmp(SYMBOL(term__V234),  "Forms-Constructors" ));
      Term sub__V242 = SUB(term__V234, 0); permitUnusedTerm(sub__V242); int sub__V242_count = term__V234_count*LINK_COUNT(sub__V242); permitUnusedInt(sub__V242_count);
      ASSERT(sink__V233->context, !strcmp(SYMBOL(sub__V242),  "$Nil" ));
      NamedPropertyLink namedP__V243 = LINK_NamedPropertyLink(sink__V233->context, NAMED_PROPERTIES(term__V234));
      VariablePropertyLink varP__V244 = LINK_VariablePropertyLink(sink__V233->context, VARIABLE_PROPERTIES(term__V234));
      UNLINK(sink__V233->context, term__V234);
      ADD_PROPERTIES(sink__V233, LINK_NamedPropertyLink(sink__V233->context, namedP__V243), LINK_VariablePropertyLink(sink__V233->context, varP__V244));
      { START(sink__V233, _M_Forms_Constructors_s5);
        END(sink__V233, _M_Forms_Constructors_s5); }
      UNLINK_NamedPropertyLink(sink__V233->context, namedP__V243); UNLINK_VariablePropertyLink(sink__V233->context, varP__V244);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION DEnumTag$1. */
int conBindOffs_M_DEnumTag_s1[] = {0 , 0};
char *nameFun_M_DEnumTag_s1(Term term) { return  "DEnumTag$1" ; }
struct _ConstructionDescriptor descriptor_M_DEnumTag_s1 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_DEnumTag_s1), conBindOffs_M_DEnumTag_s1, &nameFun_M_DEnumTag_s1, &step_M_DEnumTag_s1};

int step_M_DEnumTag_s1(Sink sink__V245, Term term__V246)
{
  int term__V246_count = LINK_COUNT(term__V246); permitUnusedInt(term__V246_count);
  do {
    /* Contraction rule DEFS-DEnumTag-1. */
    ASSERT(sink__V245->context, !strcmp(SYMBOL(term__V246),  "DEnumTag$1" ));
    Term sub__V247 = LINK(sink__V245->context, SUB(term__V246, 0)); int sub__V247_count = term__V246_count*LINK_COUNT(sub__V247); permitUnusedInt(sub__V247_count);
    /* sub__V247 = &#2 */
    NamedPropertyLink namedP__V248 = LINK_NamedPropertyLink(sink__V245->context, NAMED_PROPERTIES(term__V246));
    VariablePropertyLink varP__V249 = LINK_VariablePropertyLink(sink__V245->context, VARIABLE_PROPERTIES(term__V246));
    UNLINK(sink__V245->context, term__V246);
    { START(sink__V245, _M__sTextCons);
      { START(sink__V245, _M__sTextChars);
        LITERAL(sink__V245,  "Data" ); END(sink__V245, _M__sTextChars); }
      { START(sink__V245, _M__sTextCons);
        { START(sink__V245, _M__sTextEmbed);
          { START(sink__V245, _M_AsText);
            { START(sink__V245, _M_MANGLE);
              COPY(sink__V245, sub__V247);END(sink__V245, _M_MANGLE); }
            END(sink__V245, _M_AsText); }
          END(sink__V245, _M__sTextEmbed); }
        { START(sink__V245, _M__sTextNil);
          END(sink__V245, _M__sTextNil); }
        END(sink__V245, _M__sTextCons); }
      END(sink__V245, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V245->context, namedP__V248); UNLINK_VariablePropertyLink(sink__V245->context, varP__V249);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DCOMMENT_TOKEN$1. */
int conBindOffs_M_DCOMMENT_xTOKEN_s1[] = {0 , 0};
char *nameFun_M_DCOMMENT_xTOKEN_s1(Term term) { return  "DCOMMENT_TOKEN$1" ; }
struct _ConstructionDescriptor descriptor_M_DCOMMENT_xTOKEN_s1 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_DCOMMENT_xTOKEN_s1), conBindOffs_M_DCOMMENT_xTOKEN_s1, &nameFun_M_DCOMMENT_xTOKEN_s1, &step_M_DCOMMENT_xTOKEN_s1};

int step_M_DCOMMENT_xTOKEN_s1(Sink sink__V250, Term term__V251)
{
  int term__V251_count = LINK_COUNT(term__V251); permitUnusedInt(term__V251_count);
  do {
    /* Contraction rule DEFS-DCOMMENT_TOKEN-1. */
    ASSERT(sink__V250->context, !strcmp(SYMBOL(term__V251),  "DCOMMENT_TOKEN$1" ));
    Term sub__V252 = LINK(sink__V250->context, SUB(term__V251, 0)); int sub__V252_count = term__V251_count*LINK_COUNT(sub__V252); permitUnusedInt(sub__V252_count);
    UNLINK_SUB(sink__V250->context, term__V251,  0); NORMALIZE(sink__V250->context, sub__V252); SUB(term__V251,  0) = LINK(sink__V250->context, sub__V252);
    /* sub__V252 = &#2 */
    NamedPropertyLink namedP__V253 = LINK_NamedPropertyLink(sink__V250->context, NAMED_PROPERTIES(term__V251));
    VariablePropertyLink varP__V254 = LINK_VariablePropertyLink(sink__V250->context, VARIABLE_PROPERTIES(term__V251));
    UNLINK(sink__V250->context, term__V251);
    { START(sink__V250, _M__sTextCons);
      { START(sink__V250, _M__sTextChars);
        { char *str__V255;
          FORCE(sink__V250->context, sub__V252);
          { char *replaced__V256;
            const size_t z = strlen(SYMBOL(sub__V252));
            if (* "*/" ) {
              const size_t oldz = strlen( "*/" ), newz = strlen( "*_/" );
              size_t limitz;
              if (oldz==newz) { limitz = z; }
              else { limitz = z; size_t growz = (oldz < newz ? newz - oldz : 0);
                if (growz > 0) { char *p = SYMBOL(sub__V252); while ((p = strstr(p,  "*/" ))) { limitz += growz; p += oldz; } } }
              replaced__V256 = ALLOCA(sink__V250->context, limitz+1);
              if (oldz==newz) { memcpy(replaced__V256, SYMBOL(sub__V252), z+1);
                char *r = replaced__V256; while ((r = strstr(r,  "*/" ))) { memcpy(r,  "*_/" , newz); r += oldz; } }
              else { char *s = SYMBOL(sub__V252), *ends = s+z, *r = replaced__V256, *next;
                while ((next = strstr(s,  "*/" ))) { size_t prez = next-s;
                  if (prez) { memcpy(r, s, prez); r += prez; } 
                  if (newz) { memcpy(r,  "*_/" , newz); r += newz; }
                  s = next+oldz;}
                if (s < ends) { memcpy(r, s, ends-s); r += ends-s; }
                *r = '\0';}
              }
            else { replaced__V256 = memcpy(ALLOCA(sink__V250->context, z+1), SYMBOL(sub__V252), z+1); }
             UNLINK(sink__V250->context, sub__V252);{ size_t z__V257 = strlen(replaced__V256) + 1; memcpy(str__V255 = ALLOCATE(sink__V250->context, z__V257), replaced__V256, z__V257); }
            
          }LITERALU(sink__V250, str__V255); }
        END(sink__V250, _M__sTextChars); }
      { START(sink__V250, _M__sTextNil);
        END(sink__V250, _M__sTextNil); }
      END(sink__V250, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V250->context, namedP__V253); UNLINK_VariablePropertyLink(sink__V250->context, varP__V254);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION IfZero. */
int conBindOffs_M_IfZero[] = {0 , 0 , 0 , 0};
char *nameFun_M_IfZero(Term term) { return  "IfZero" ; }
struct _ConstructionDescriptor descriptor_M_IfZero = {NULL, 0, 3, sizeof(STRUCT_Con_M_IfZero), conBindOffs_M_IfZero, &nameFun_M_IfZero, &step_M_IfZero};

int step_M_IfZero(Sink sink__V258, Term term__V259)
{
  int term__V259_count = LINK_COUNT(term__V259); permitUnusedInt(term__V259_count);
  do {
    /* Contraction rule DEFS-IfZero-1. */
    ASSERT(sink__V258->context, !strcmp(SYMBOL(term__V259),  "IfZero" ));
    Term sub__V260 = LINK(sink__V258->context, SUB(term__V259, 0)); int sub__V260_count = term__V259_count*LINK_COUNT(sub__V260); permitUnusedInt(sub__V260_count);
    UNLINK_SUB(sink__V258->context, term__V259,  0); NORMALIZE(sink__V258->context, sub__V260); SUB(term__V259,  0) = LINK(sink__V258->context, sub__V260);
    /* sub__V260 = &#1 */
    Term sub__V261 = LINK(sink__V258->context, SUB(term__V259, 1)); int sub__V261_count = term__V259_count*LINK_COUNT(sub__V261); permitUnusedInt(sub__V261_count);
    /* sub__V261 = &#2 */
    Term sub__V262 = LINK(sink__V258->context, SUB(term__V259, 2)); int sub__V262_count = term__V259_count*LINK_COUNT(sub__V262); permitUnusedInt(sub__V262_count);
    /* sub__V262 = &#3 */
    UNLINK(sink__V258->context, term__V259);
    { long long intt__V263;
      intt__V263 = LONGLONG(sub__V260); if (intt__V263 == 0ll) {  UNLINK(sink__V258->context, sub__V262); COPY(sink__V258, sub__V261); }
      else { COPY(sink__V258, sub__V262); }
    }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DMANGLE. */
int conBindOffs_M_DMANGLE[] = {0 , 0 , 0};
char *nameFun_M_DMANGLE(Term term) { return  "DMANGLE" ; }
struct _ConstructionDescriptor descriptor_M_DMANGLE = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_DMANGLE), conBindOffs_M_DMANGLE, &nameFun_M_DMANGLE, &step_M_DMANGLE};

int step_M_DMANGLE(Sink sink__V264, Term term__V265)
{
  int term__V265_count = LINK_COUNT(term__V265); permitUnusedInt(term__V265_count);
  Term sub__V266 = FORCE(sink__V264->context, SUB(term__V265, 0));
  EnumOf_M_OK_xSORT choice__V267 = (IS_VARIABLE_USE(sub__V266) ? VarOf_M_OK_xSORT : (EnumOf_M_OK_xSORT) TAG(sub__V266));
  switch (choice__V267)
  {
    case Data_M_OK: { /* Function DEFS-DMANGLE-1$DMANGLE$OK case OK */
      ASSERT(sink__V264->context, !strcmp(SYMBOL(term__V265),  "DMANGLE" ));
      Term sub__V268 = SUB(term__V265, 0); permitUnusedTerm(sub__V268); int sub__V268_count = term__V265_count*LINK_COUNT(sub__V268); permitUnusedInt(sub__V268_count);
      CRSX_CHECK_SORT(sink__V264->context, sub__V268, &sort_M_OK_xSORT); ASSERT(sink__V264->context, !strcmp(SYMBOL(sub__V268),  "OK" ));
      Term sub__V269 = LINK(sink__V264->context, SUB(term__V265, 1)); int sub__V269_count = term__V265_count*LINK_COUNT(sub__V269); permitUnusedInt(sub__V269_count);
      /* sub__V269 = &#0 */
      NamedPropertyLink namedP__V270 = LINK_NamedPropertyLink(sink__V264->context, NAMED_PROPERTIES(term__V265));
      VariablePropertyLink varP__V271 = LINK_VariablePropertyLink(sink__V264->context, VARIABLE_PROPERTIES(term__V265));
      UNLINK(sink__V264->context, term__V265);
      ADD_PROPERTIES(sink__V264, LINK_NamedPropertyLink(sink__V264->context, namedP__V270), LINK_VariablePropertyLink(sink__V264->context, varP__V271));
      { START(sink__V264, _M_DMANGLE_s1);
        COPY(sink__V264, sub__V269);END(sink__V264, _M_DMANGLE_s1); }
      UNLINK_NamedPropertyLink(sink__V264->context, namedP__V270); UNLINK_VariablePropertyLink(sink__V264->context, varP__V271);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION EnumVar. */
int conBindOffs_M_EnumVar[] = {0 , 0};
char *nameFun_M_EnumVar(Term term) { return  "EnumVar" ; }
struct _ConstructionDescriptor descriptor_M_EnumVar = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_EnumVar), conBindOffs_M_EnumVar, &nameFun_M_EnumVar, &step_M_EnumVar};

int step_M_EnumVar(Sink sink__V272, Term term__V273)
{
  int term__V273_count = LINK_COUNT(term__V273); permitUnusedInt(term__V273_count);
  do {
    /* Contraction rule DEFS-EnumVar-1. */
    ASSERT(sink__V272->context, !strcmp(SYMBOL(term__V273),  "EnumVar" ));
    Term sub__V274 = LINK(sink__V272->context, SUB(term__V273, 0)); int sub__V274_count = term__V273_count*LINK_COUNT(sub__V274); permitUnusedInt(sub__V274_count);
    /* sub__V274 = &#1 */
    NamedPropertyLink namedP__V275 = LINK_NamedPropertyLink(sink__V272->context, NAMED_PROPERTIES(term__V273));
    VariablePropertyLink varP__V276 = LINK_VariablePropertyLink(sink__V272->context, VARIABLE_PROPERTIES(term__V273));
    UNLINK(sink__V272->context, term__V273);
    { START(sink__V272, _M__sTextCons);
      { START(sink__V272, _M__sTextChars);
        LITERAL(sink__V272,  "VarOf" ); END(sink__V272, _M__sTextChars); }
      { START(sink__V272, _M__sTextCons);
        { START(sink__V272, _M__sTextEmbed);
          { START(sink__V272, _M_AsText);
            { START(sink__V272, _M_MANGLE);
              COPY(sink__V272, sub__V274);END(sink__V272, _M_MANGLE); }
            END(sink__V272, _M_AsText); }
          END(sink__V272, _M__sTextEmbed); }
        { START(sink__V272, _M__sTextNil);
          END(sink__V272, _M__sTextNil); }
        END(sink__V272, _M__sTextCons); }
      END(sink__V272, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V272->context, namedP__V275); UNLINK_VariablePropertyLink(sink__V272->context, varP__V276);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DDescriptor$1. */
int conBindOffs_M_DDescriptor_s1[] = {0 , 0};
char *nameFun_M_DDescriptor_s1(Term term) { return  "DDescriptor$1" ; }
struct _ConstructionDescriptor descriptor_M_DDescriptor_s1 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_DDescriptor_s1), conBindOffs_M_DDescriptor_s1, &nameFun_M_DDescriptor_s1, &step_M_DDescriptor_s1};

int step_M_DDescriptor_s1(Sink sink__V277, Term term__V278)
{
  int term__V278_count = LINK_COUNT(term__V278); permitUnusedInt(term__V278_count);
  do {
    /* Contraction rule DEFS-DDescriptor-1. */
    ASSERT(sink__V277->context, !strcmp(SYMBOL(term__V278),  "DDescriptor$1" ));
    Term sub__V279 = LINK(sink__V277->context, SUB(term__V278, 0)); int sub__V279_count = term__V278_count*LINK_COUNT(sub__V279); permitUnusedInt(sub__V279_count);
    /* sub__V279 = &#2 */
    NamedPropertyLink namedP__V280 = LINK_NamedPropertyLink(sink__V277->context, NAMED_PROPERTIES(term__V278));
    VariablePropertyLink varP__V281 = LINK_VariablePropertyLink(sink__V277->context, VARIABLE_PROPERTIES(term__V278));
    UNLINK(sink__V277->context, term__V278);
    { START(sink__V277, _M__sTextCons);
      { START(sink__V277, _M__sTextChars);
        LITERAL(sink__V277,  "descriptor" ); END(sink__V277, _M__sTextChars); }
      { START(sink__V277, _M__sTextCons);
        { START(sink__V277, _M__sTextEmbed);
          { START(sink__V277, _M_AsText);
            { START(sink__V277, _M_MANGLE);
              COPY(sink__V277, sub__V279);END(sink__V277, _M_MANGLE); }
            END(sink__V277, _M_AsText); }
          END(sink__V277, _M__sTextEmbed); }
        { START(sink__V277, _M__sTextNil);
          END(sink__V277, _M__sTextNil); }
        END(sink__V277, _M__sTextCons); }
      END(sink__V277, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V277->context, namedP__V280); UNLINK_VariablePropertyLink(sink__V277->context, varP__V281);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION MetaVar. */
int conBindOffs_M_MetaVar[] = {0 , 0};
char *nameFun_M_MetaVar(Term term) { return  "MetaVar" ; }
struct _ConstructionDescriptor descriptor_M_MetaVar = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_MetaVar), conBindOffs_M_MetaVar, &nameFun_M_MetaVar, &step_M_MetaVar};

int step_M_MetaVar(Sink sink__V282, Term term__V283)
{
  int term__V283_count = LINK_COUNT(term__V283); permitUnusedInt(term__V283_count);
  do {
    /* Contraction rule DEFS-MetaVar-1. */
    ASSERT(sink__V282->context, !strcmp(SYMBOL(term__V283),  "MetaVar" ));
    Term sub__V284 = LINK(sink__V282->context, SUB(term__V283, 0)); int sub__V284_count = term__V283_count*LINK_COUNT(sub__V284); permitUnusedInt(sub__V284_count);
    UNLINK_SUB(sink__V282->context, term__V283,  0); NORMALIZE(sink__V282->context, sub__V284); SUB(term__V283,  0) = LINK(sink__V282->context, sub__V284);
    /* sub__V284 = &#1 */
    NamedPropertyLink namedP__V285 = LINK_NamedPropertyLink(sink__V282->context, NAMED_PROPERTIES(term__V283));
    VariablePropertyLink varP__V286 = LINK_VariablePropertyLink(sink__V282->context, VARIABLE_PROPERTIES(term__V283));
    UNLINK(sink__V282->context, term__V283);
    ADD_PROPERTIES(sink__V282, LINK_NamedPropertyLink(sink__V282->context, namedP__V285), LINK_VariablePropertyLink(sink__V282->context, varP__V286));
    { START(sink__V282, _M_MetaVar2);
      { Term term__V287;
        { Term key__V288;
          char *sub__V289[2]; size_t sublength__V290[2]; size_t length__V291 = 0;
          length__V291 += (sublength__V290[0] = strlen(sub__V289[0] =  "MetaVar$" ));
          FORCE(sink__V282->context, sub__V284);
          length__V291 += (sublength__V290[1] = strlen(sub__V289[1] = SYMBOL(sub__V284)));
          { char *str__V292 = ALLOCA(sink__V282->context, length__V291+1), *p__V293 = str__V292;
            int i; for (i = 0; i < 2; ++i) { memcpy(p__V293, sub__V289[i], sublength__V290[i]); p__V293 += sublength__V290[i]; }
            *p__V293 = '\0';
            ASSERT(sink__V282->context, strlen(str__V292) == length__V291);
            key__V288 = makeStringLiteral(sink__V282->context, str__V292);
            }
          Term *pp__V294 = DPROPERTY(namedP__V285, varP__V286, key__V288);UNLINK(sink__V282->context, key__V288); 
          if (pp__V294) term__V287 = LINK(sink__V282->context, *pp__V294);
          else {{ Sink buf__V295 = ALLOCA_BUFFER(sink__V282->context);
              { START(buf__V295, _M_STRING_xVALUE);
                { char *str__V296;
                  { char *sub__V297[2]; size_t sublength__V298[2]; size_t length__V299 = 0;
                    length__V299 += (sublength__V298[0] = strlen(sub__V297[0] =  "m" ));
                    FORCE(buf__V295->context, sub__V284);
                    { char *s__V300 = makeMangled(buf__V295->context, SYMBOL(sub__V284));
                      length__V299 += (sublength__V298[1] = strlen(sub__V297[1] = s__V300));
                      UNLINK(buf__V295->context, sub__V284);{ char *str__V301 = ALLOCATE(buf__V295->context, length__V299+1), *p__V302 = str__V301;
                        int i; for (i = 0; i < 2; ++i) { memcpy(p__V302, sub__V297[i], sublength__V298[i]); p__V302 += sublength__V298[i]; }
                        *p__V302 = '\0';
                        ASSERT(buf__V295->context, strlen(str__V301) == length__V299);
                        str__V296 = str__V301; }
                      }
                     }
                  LITERALU(buf__V295, str__V296); }
                END(buf__V295, _M_STRING_xVALUE); }
              term__V287 = BUFFER_TERM(buf__V295); FREE_BUFFER(buf__V295); }
            }
        }
        COPY(sink__V282, term__V287); /*CONSERVATIVE*/ }
      END(sink__V282, _M_MetaVar2); }
    UNLINK_NamedPropertyLink(sink__V282->context, namedP__V285); UNLINK_VariablePropertyLink(sink__V282->context, varP__V286);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Length. */
int conBindOffs_M_Length[] = {0 , 0 , 0};
char *nameFun_M_Length(Term term) { return  "Length" ; }
struct _ConstructionDescriptor descriptor_M_Length = {NULL, 0, 2, sizeof(STRUCT_Con_M_Length), conBindOffs_M_Length, &nameFun_M_Length, &step_M_Length};

int step_M_Length(Sink sink__V303, Term term__V304)
{
  int term__V304_count = LINK_COUNT(term__V304); permitUnusedInt(term__V304_count);
  Term sub__V305 = FORCE(sink__V303->context, SUB(term__V304, 0));
  EnumOf_M__sList choice__V306 = (IS_VARIABLE_USE(sub__V305) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V305));
  switch (choice__V306)
  {
    case Data_M__sNil: { /* Function DEFS-Length-1$Length$$Nil case $Nil */
      ASSERT(sink__V303->context, !strcmp(SYMBOL(term__V304),  "Length" ));
      Term sub__V307 = SUB(term__V304, 0); permitUnusedTerm(sub__V307); int sub__V307_count = term__V304_count*LINK_COUNT(sub__V307); permitUnusedInt(sub__V307_count);
      ASSERT(sink__V303->context, !strcmp(SYMBOL(sub__V307),  "$Nil" ));
      Term sub__V308 = LINK(sink__V303->context, SUB(term__V304, 1)); int sub__V308_count = term__V304_count*LINK_COUNT(sub__V308); permitUnusedInt(sub__V308_count);
      /* sub__V308 = &#0 */
      NamedPropertyLink namedP__V309 = LINK_NamedPropertyLink(sink__V303->context, NAMED_PROPERTIES(term__V304));
      VariablePropertyLink varP__V310 = LINK_VariablePropertyLink(sink__V303->context, VARIABLE_PROPERTIES(term__V304));
      UNLINK(sink__V303->context, term__V304);
      ADD_PROPERTIES(sink__V303, LINK_NamedPropertyLink(sink__V303->context, namedP__V309), LINK_VariablePropertyLink(sink__V303->context, varP__V310));
      { START(sink__V303, _M_Length_s2);
        COPY(sink__V303, sub__V308);END(sink__V303, _M_Length_s2); }
      UNLINK_NamedPropertyLink(sink__V303->context, namedP__V309); UNLINK_VariablePropertyLink(sink__V303->context, varP__V310);
      
      return 1;
    break; } case Data_M__sCons: { /* Function DEFS-Length-2$Length$$Cons case $Cons */
      ASSERT(sink__V303->context, !strcmp(SYMBOL(term__V304),  "Length" ));
      Term sub__V311 = SUB(term__V304, 0); permitUnusedTerm(sub__V311); int sub__V311_count = term__V304_count*LINK_COUNT(sub__V311); permitUnusedInt(sub__V311_count);
      ASSERT(sink__V303->context, !strcmp(SYMBOL(sub__V311),  "$Cons" ));
      Term sub__V312 = LINK(sink__V303->context, SUB(sub__V311, 0)); int sub__V312_count = sub__V311_count*LINK_COUNT(sub__V312); permitUnusedInt(sub__V312_count);
      /* sub__V312 = &#0-0 */
      Term sub__V313 = LINK(sink__V303->context, SUB(sub__V311, 1)); int sub__V313_count = sub__V311_count*LINK_COUNT(sub__V313); permitUnusedInt(sub__V313_count);
      /* sub__V313 = &#0-1 */
      Term sub__V314 = LINK(sink__V303->context, SUB(term__V304, 1)); int sub__V314_count = term__V304_count*LINK_COUNT(sub__V314); permitUnusedInt(sub__V314_count);
      /* sub__V314 = &#2 */
      NamedPropertyLink namedP__V315 = LINK_NamedPropertyLink(sink__V303->context, NAMED_PROPERTIES(term__V304));
      VariablePropertyLink varP__V316 = LINK_VariablePropertyLink(sink__V303->context, VARIABLE_PROPERTIES(term__V304));
      UNLINK(sink__V303->context, term__V304);
      ADD_PROPERTIES(sink__V303, LINK_NamedPropertyLink(sink__V303->context, namedP__V315), LINK_VariablePropertyLink(sink__V303->context, varP__V316));
      { START(sink__V303, _M_Length_s1);
        COPY(sink__V303, sub__V312);COPY(sink__V303, sub__V313);COPY(sink__V303, sub__V314);END(sink__V303, _M_Length_s1); }
      UNLINK_NamedPropertyLink(sink__V303->context, namedP__V315); UNLINK_VariablePropertyLink(sink__V303->context, varP__V316);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION Sort-name$1. */
int conBindOffs_M_Sort__name_s1[] = {0 , 0 , 0};
char *nameFun_M_Sort__name_s1(Term term) { return  "Sort-name$1" ; }
struct _ConstructionDescriptor descriptor_M_Sort__name_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_Sort__name_s1), conBindOffs_M_Sort__name_s1, &nameFun_M_Sort__name_s1, &step_M_Sort__name_s1};

int step_M_Sort__name_s1(Sink sink__V317, Term term__V318)
{
  int term__V318_count = LINK_COUNT(term__V318); permitUnusedInt(term__V318_count);
  do {
    /* Contraction rule DEFS-Sort-name-1. */
    ASSERT(sink__V317->context, !strcmp(SYMBOL(term__V318),  "Sort-name$1" ));
    Term sub__V319 = LINK(sink__V317->context, SUB(term__V318, 0)); int sub__V319_count = term__V318_count*LINK_COUNT(sub__V319); permitUnusedInt(sub__V319_count);
    /* sub__V319 = &#11 */
    Term sub__V320 = SUB(term__V318, 1); permitUnusedTerm(sub__V320); int sub__V320_count = term__V318_count*LINK_COUNT(sub__V320); permitUnusedInt(sub__V320_count);
    /* sub__V320 = &#12 */
    NamedPropertyLink namedP__V321 = LINK_NamedPropertyLink(sink__V317->context, NAMED_PROPERTIES(term__V318));
    VariablePropertyLink varP__V322 = LINK_VariablePropertyLink(sink__V317->context, VARIABLE_PROPERTIES(term__V318));
    UNLINK(sink__V317->context, term__V318);
    { START(sink__V317, _M_TOKEN);
      COPY(sink__V317, sub__V319);END(sink__V317, _M_TOKEN); }
    UNLINK_NamedPropertyLink(sink__V317->context, namedP__V321); UNLINK_VariablePropertyLink(sink__V317->context, varP__V322);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Struct. */
int conBindOffs_M_Struct[] = {0 , 0};
char *nameFun_M_Struct(Term term) { return  "Struct" ; }
struct _ConstructionDescriptor descriptor_M_Struct = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_Struct), conBindOffs_M_Struct, &nameFun_M_Struct, &step_M_Struct};

int step_M_Struct(Sink sink__V323, Term term__V324)
{
  int term__V324_count = LINK_COUNT(term__V324); permitUnusedInt(term__V324_count);
  do {
    /* Contraction rule DEFS-Struct-1. */
    ASSERT(sink__V323->context, !strcmp(SYMBOL(term__V324),  "Struct" ));
    Term sub__V325 = LINK(sink__V323->context, SUB(term__V324, 0)); int sub__V325_count = term__V324_count*LINK_COUNT(sub__V325); permitUnusedInt(sub__V325_count);
    /* sub__V325 = &#1 */
    NamedPropertyLink namedP__V326 = LINK_NamedPropertyLink(sink__V323->context, NAMED_PROPERTIES(term__V324));
    VariablePropertyLink varP__V327 = LINK_VariablePropertyLink(sink__V323->context, VARIABLE_PROPERTIES(term__V324));
    UNLINK(sink__V323->context, term__V324);
    { START(sink__V323, _M__sTextCons);
      { START(sink__V323, _M__sTextChars);
        LITERAL(sink__V323,  "_Con" ); END(sink__V323, _M__sTextChars); }
      { START(sink__V323, _M__sTextCons);
        { START(sink__V323, _M__sTextEmbed);
          { START(sink__V323, _M_AsText);
            { START(sink__V323, _M_MANGLE);
              COPY(sink__V323, sub__V325);END(sink__V323, _M_MANGLE); }
            END(sink__V323, _M_AsText); }
          END(sink__V323, _M__sTextEmbed); }
        { START(sink__V323, _M__sTextNil);
          END(sink__V323, _M__sTextNil); }
        END(sink__V323, _M__sTextCons); }
      END(sink__V323, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V323->context, namedP__V326); UNLINK_VariablePropertyLink(sink__V323->context, varP__V327);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION UnString. */
int conBindOffs_M_UnString[] = {0 , 0};
char *nameFun_M_UnString(Term term) { return  "UnString" ; }
struct _ConstructionDescriptor descriptor_M_UnString = {NULL, 0, 1, sizeof(STRUCT_Con_M_UnString), conBindOffs_M_UnString, &nameFun_M_UnString, &step_M_UnString};

int step_M_UnString(Sink sink__V328, Term term__V329)
{
  int term__V329_count = LINK_COUNT(term__V329); permitUnusedInt(term__V329_count);
  Term sub__V330 = FORCE(sink__V328->context, SUB(term__V329, 0));
  EnumOf_M_STRING_xENTRY choice__V331 = (IS_VARIABLE_USE(sub__V330) ? VarOf_M_STRING_xENTRY : (EnumOf_M_STRING_xENTRY) TAG(sub__V330));
  switch (choice__V331)
  {
    case Data_M_STRING_xVALUE: { /* Function DEFS-UnString-1$UnString$STRING_VALUE case STRING_VALUE */
      ASSERT(sink__V328->context, !strcmp(SYMBOL(term__V329),  "UnString" ));
      Term sub__V332 = SUB(term__V329, 0); permitUnusedTerm(sub__V332); int sub__V332_count = term__V329_count*LINK_COUNT(sub__V332); permitUnusedInt(sub__V332_count);
      CRSX_CHECK_SORT(sink__V328->context, sub__V332, &sort_M_STRING_xENTRY); ASSERT(sink__V328->context, !strcmp(SYMBOL(sub__V332),  "STRING_VALUE" ));
      Term sub__V333 = LINK(sink__V328->context, SUB(sub__V332, 0)); int sub__V333_count = sub__V332_count*LINK_COUNT(sub__V333); permitUnusedInt(sub__V333_count);
      /* sub__V333 = &#0-0 */
      NamedPropertyLink namedP__V334 = LINK_NamedPropertyLink(sink__V328->context, NAMED_PROPERTIES(term__V329));
      VariablePropertyLink varP__V335 = LINK_VariablePropertyLink(sink__V328->context, VARIABLE_PROPERTIES(term__V329));
      UNLINK(sink__V328->context, term__V329);
      ADD_PROPERTIES(sink__V328, LINK_NamedPropertyLink(sink__V328->context, namedP__V334), LINK_VariablePropertyLink(sink__V328->context, varP__V335));
      { START(sink__V328, _M_UnString_s1);
        COPY(sink__V328, sub__V333);END(sink__V328, _M_UnString_s1); }
      UNLINK_NamedPropertyLink(sink__V328->context, namedP__V334); UNLINK_VariablePropertyLink(sink__V328->context, varP__V335);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION UnVariable. */
int conBindOffs_M_UnVariable[] = {0 , 0};
char *nameFun_M_UnVariable(Term term) { return  "UnVariable" ; }
struct _ConstructionDescriptor descriptor_M_UnVariable = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_UnVariable), conBindOffs_M_UnVariable, &nameFun_M_UnVariable, &step_M_UnVariable};

int step_M_UnVariable(Sink sink__V336, Term term__V337)
{
  int term__V337_count = LINK_COUNT(term__V337); permitUnusedInt(term__V337_count);
  Term sub__V338 = FORCE(sink__V336->context, SUB(term__V337, 0));
  EnumOf_M_STRING_xENTRY choice__V339 = (IS_VARIABLE_USE(sub__V338) ? VarOf_M_STRING_xENTRY : (EnumOf_M_STRING_xENTRY) TAG(sub__V338));
  switch (choice__V339)
  {
    case Data_M_VARIABLE: { /* Function DEFS-UnVariable-1$UnVariable$VARIABLE case VARIABLE */
      ASSERT(sink__V336->context, !strcmp(SYMBOL(term__V337),  "UnVariable" ));
      Term sub__V340 = SUB(term__V337, 0); permitUnusedTerm(sub__V340); int sub__V340_count = term__V337_count*LINK_COUNT(sub__V340); permitUnusedInt(sub__V340_count);
      CRSX_CHECK_SORT(sink__V336->context, sub__V340, &sort_M_STRING_xENTRY); ASSERT(sink__V336->context, !strcmp(SYMBOL(sub__V340),  "VARIABLE" ));
      Term sub__V341 = LINK(sink__V336->context, SUB(sub__V340, 0)); int sub__V341_count = sub__V340_count*LINK_COUNT(sub__V341); permitUnusedInt(sub__V341_count);
      CRSX_CHECK_SORT(sink__V336->context, sub__V341, &sort_M_Reified_xVariable); /* sub__V341 = &#0-0 */
      NamedPropertyLink namedP__V342 = LINK_NamedPropertyLink(sink__V336->context, NAMED_PROPERTIES(term__V337));
      VariablePropertyLink varP__V343 = LINK_VariablePropertyLink(sink__V336->context, VARIABLE_PROPERTIES(term__V337));
      UNLINK(sink__V336->context, term__V337);
      ADD_PROPERTIES(sink__V336, LINK_NamedPropertyLink(sink__V336->context, namedP__V342), LINK_VariablePropertyLink(sink__V336->context, varP__V343));
      { START(sink__V336, _M_UnVariable_s1);
        COPY(sink__V336, sub__V341);END(sink__V336, _M_UnVariable_s1); }
      UNLINK_NamedPropertyLink(sink__V336->context, namedP__V342); UNLINK_VariablePropertyLink(sink__V336->context, varP__V343);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION DINTEGER. */
int conBindOffs_M_DINTEGER[] = {0 , 0 , 0};
char *nameFun_M_DINTEGER(Term term) { return  "DINTEGER" ; }
struct _ConstructionDescriptor descriptor_M_DINTEGER = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_DINTEGER), conBindOffs_M_DINTEGER, &nameFun_M_DINTEGER, &step_M_DINTEGER};

int step_M_DINTEGER(Sink sink__V344, Term term__V345)
{
  int term__V345_count = LINK_COUNT(term__V345); permitUnusedInt(term__V345_count);
  Term sub__V346 = FORCE(sink__V344->context, SUB(term__V345, 0));
  EnumOf_M_OK_xSORT choice__V347 = (IS_VARIABLE_USE(sub__V346) ? VarOf_M_OK_xSORT : (EnumOf_M_OK_xSORT) TAG(sub__V346));
  switch (choice__V347)
  {
    case Data_M_OK: { /* Function DEFS-DINTEGER-1$DINTEGER$OK case OK */
      ASSERT(sink__V344->context, !strcmp(SYMBOL(term__V345),  "DINTEGER" ));
      Term sub__V348 = SUB(term__V345, 0); permitUnusedTerm(sub__V348); int sub__V348_count = term__V345_count*LINK_COUNT(sub__V348); permitUnusedInt(sub__V348_count);
      CRSX_CHECK_SORT(sink__V344->context, sub__V348, &sort_M_OK_xSORT); ASSERT(sink__V344->context, !strcmp(SYMBOL(sub__V348),  "OK" ));
      Term sub__V349 = LINK(sink__V344->context, SUB(term__V345, 1)); int sub__V349_count = term__V345_count*LINK_COUNT(sub__V349); permitUnusedInt(sub__V349_count);
      /* sub__V349 = &#0 */
      NamedPropertyLink namedP__V350 = LINK_NamedPropertyLink(sink__V344->context, NAMED_PROPERTIES(term__V345));
      VariablePropertyLink varP__V351 = LINK_VariablePropertyLink(sink__V344->context, VARIABLE_PROPERTIES(term__V345));
      UNLINK(sink__V344->context, term__V345);
      ADD_PROPERTIES(sink__V344, LINK_NamedPropertyLink(sink__V344->context, namedP__V350), LINK_VariablePropertyLink(sink__V344->context, varP__V351));
      { START(sink__V344, _M_DINTEGER_s1);
        COPY(sink__V344, sub__V349);END(sink__V344, _M_DINTEGER_s1); }
      UNLINK_NamedPropertyLink(sink__V344->context, namedP__V350); UNLINK_VariablePropertyLink(sink__V344->context, varP__V351);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION MANGLE. */
int conBindOffs_M_MANGLE[] = {0 , 0};
char *nameFun_M_MANGLE(Term term) { return  "MANGLE" ; }
struct _ConstructionDescriptor descriptor_M_MANGLE = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_MANGLE), conBindOffs_M_MANGLE, &nameFun_M_MANGLE, &step_M_MANGLE};

int step_M_MANGLE(Sink sink__V352, Term term__V353)
{
  int term__V353_count = LINK_COUNT(term__V353); permitUnusedInt(term__V353_count);
  do {
    /* Contraction rule DEFS-MANGLE-1. */
    ASSERT(sink__V352->context, !strcmp(SYMBOL(term__V353),  "MANGLE" ));
    Term sub__V354 = LINK(sink__V352->context, SUB(term__V353, 0)); int sub__V354_count = term__V353_count*LINK_COUNT(sub__V354); permitUnusedInt(sub__V354_count);
    UNLINK_SUB(sink__V352->context, term__V353,  0); NORMALIZE(sink__V352->context, sub__V354); SUB(term__V353,  0) = LINK(sink__V352->context, sub__V354);
    /* sub__V354 = &#1 */
    NamedPropertyLink namedP__V355 = LINK_NamedPropertyLink(sink__V352->context, NAMED_PROPERTIES(term__V353));
    VariablePropertyLink varP__V356 = LINK_VariablePropertyLink(sink__V352->context, VARIABLE_PROPERTIES(term__V353));
    UNLINK(sink__V352->context, term__V353);
    { START(sink__V352, _M__sTextCons);
      { START(sink__V352, _M__sTextChars);
        { char *str__V357;
          FORCE(sink__V352->context, sub__V354);
          { char *s__V358 = makeMangled(sink__V352->context, SYMBOL(sub__V354));
            { size_t z__V359 = strlen(s__V358) + 1; memcpy(str__V357 = ALLOCATE(sink__V352->context, z__V359), s__V358, z__V359);  UNLINK(sink__V352->context, sub__V354);}
            }
          LITERALU(sink__V352, str__V357); }
        END(sink__V352, _M__sTextChars); }
      { START(sink__V352, _M__sTextNil);
        END(sink__V352, _M__sTextNil); }
      END(sink__V352, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V352->context, namedP__V355); UNLINK_VariablePropertyLink(sink__V352->context, varP__V356);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Enum. */
int conBindOffs_M_Enum[] = {0 , 0};
char *nameFun_M_Enum(Term term) { return  "Enum" ; }
struct _ConstructionDescriptor descriptor_M_Enum = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_Enum), conBindOffs_M_Enum, &nameFun_M_Enum, &step_M_Enum};

int step_M_Enum(Sink sink__V360, Term term__V361)
{
  int term__V361_count = LINK_COUNT(term__V361); permitUnusedInt(term__V361_count);
  do {
    /* Contraction rule DEFS-Enum-1. */
    ASSERT(sink__V360->context, !strcmp(SYMBOL(term__V361),  "Enum" ));
    Term sub__V362 = LINK(sink__V360->context, SUB(term__V361, 0)); int sub__V362_count = term__V361_count*LINK_COUNT(sub__V362); permitUnusedInt(sub__V362_count);
    /* sub__V362 = &#1 */
    NamedPropertyLink namedP__V363 = LINK_NamedPropertyLink(sink__V360->context, NAMED_PROPERTIES(term__V361));
    VariablePropertyLink varP__V364 = LINK_VariablePropertyLink(sink__V360->context, VARIABLE_PROPERTIES(term__V361));
    UNLINK(sink__V360->context, term__V361);
    { START(sink__V360, _M__sTextCons);
      { START(sink__V360, _M__sTextChars);
        LITERAL(sink__V360,  "EnumOf" ); END(sink__V360, _M__sTextChars); }
      { START(sink__V360, _M__sTextCons);
        { START(sink__V360, _M__sTextEmbed);
          { START(sink__V360, _M_AsText);
            { START(sink__V360, _M_MANGLE);
              COPY(sink__V360, sub__V362);END(sink__V360, _M_MANGLE); }
            END(sink__V360, _M_AsText); }
          END(sink__V360, _M__sTextEmbed); }
        { START(sink__V360, _M__sTextNil);
          END(sink__V360, _M__sTextNil); }
        END(sink__V360, _M__sTextCons); }
      END(sink__V360, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V360->context, namedP__V363); UNLINK_VariablePropertyLink(sink__V360->context, varP__V364);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Sort-name. */
int conBindOffs_M_Sort__name[] = {0 , 0};
char *nameFun_M_Sort__name(Term term) { return  "Sort-name" ; }
struct _ConstructionDescriptor descriptor_M_Sort__name = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_Sort__name), conBindOffs_M_Sort__name, &nameFun_M_Sort__name, &step_M_Sort__name};

int step_M_Sort__name(Sink sink__V365, Term term__V366)
{
  int term__V366_count = LINK_COUNT(term__V366); permitUnusedInt(term__V366_count);
  Term sub__V367 = FORCE(sink__V365->context, SUB(term__V366, 0));
  EnumOf_M_Reified_xSort choice__V368 = (IS_VARIABLE_USE(sub__V367) ? VarOf_M_Reified_xSort : (EnumOf_M_Reified_xSort) TAG(sub__V367));
  switch (choice__V368)
  {
    case Data_M_SORT: { /* Function DEFS-Sort-name-1$Sort-name$SORT case SORT */
      ASSERT(sink__V365->context, !strcmp(SYMBOL(term__V366),  "Sort-name" ));
      Term sub__V369 = SUB(term__V366, 0); permitUnusedTerm(sub__V369); int sub__V369_count = term__V366_count*LINK_COUNT(sub__V369); permitUnusedInt(sub__V369_count);
      CRSX_CHECK_SORT(sink__V365->context, sub__V369, &sort_M_Reified_xSort); ASSERT(sink__V365->context, !strcmp(SYMBOL(sub__V369),  "SORT" ));
      Term sub__V370 = LINK(sink__V365->context, SUB(sub__V369, 0)); int sub__V370_count = sub__V369_count*LINK_COUNT(sub__V370); permitUnusedInt(sub__V370_count);
      /* sub__V370 = &#0-0 */
      Term sub__V371 = LINK(sink__V365->context, SUB(sub__V369, 1)); int sub__V371_count = sub__V369_count*LINK_COUNT(sub__V371); permitUnusedInt(sub__V371_count);
      /* sub__V371 = &#0-1 */
      NamedPropertyLink namedP__V372 = LINK_NamedPropertyLink(sink__V365->context, NAMED_PROPERTIES(term__V366));
      VariablePropertyLink varP__V373 = LINK_VariablePropertyLink(sink__V365->context, VARIABLE_PROPERTIES(term__V366));
      UNLINK(sink__V365->context, term__V366);
      ADD_PROPERTIES(sink__V365, LINK_NamedPropertyLink(sink__V365->context, namedP__V372), LINK_VariablePropertyLink(sink__V365->context, varP__V373));
      { START(sink__V365, _M_Sort__name_s1);
        COPY(sink__V365, sub__V370);COPY(sink__V365, sub__V371);END(sink__V365, _M_Sort__name_s1); }
      UNLINK_NamedPropertyLink(sink__V365->context, namedP__V372); UNLINK_VariablePropertyLink(sink__V365->context, varP__V373);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION If. */
int conBindOffs_M_If[] = {0 , 0 , 0 , 0};
char *nameFun_M_If(Term term) { return  "If" ; }
struct _ConstructionDescriptor descriptor_M_If = {NULL, 0, 3, sizeof(STRUCT_Con_M_If), conBindOffs_M_If, &nameFun_M_If, &step_M_If};

int step_M_If(Sink sink__V374, Term term__V375)
{
  int term__V375_count = LINK_COUNT(term__V375); permitUnusedInt(term__V375_count);
  Term sub__V376 = FORCE(sink__V374->context, SUB(term__V375, 0));
  EnumOf_M__sBoolean choice__V377 = (IS_VARIABLE_USE(sub__V376) ? VarOf_M__sBoolean : (EnumOf_M__sBoolean) TAG(sub__V376));
  switch (choice__V377)
  {
    case Data_M__sTrue: { /* Function DEFS-If-1$If$$True case $True */
      ASSERT(sink__V374->context, !strcmp(SYMBOL(term__V375),  "If" ));
      Term sub__V378 = SUB(term__V375, 0); permitUnusedTerm(sub__V378); int sub__V378_count = term__V375_count*LINK_COUNT(sub__V378); permitUnusedInt(sub__V378_count);
      ASSERT(sink__V374->context, !strcmp(SYMBOL(sub__V378),  "$True" ));
      Term sub__V379 = LINK(sink__V374->context, SUB(term__V375, 1)); int sub__V379_count = term__V375_count*LINK_COUNT(sub__V379); permitUnusedInt(sub__V379_count);
      /* sub__V379 = &#0 */
      Term sub__V380 = LINK(sink__V374->context, SUB(term__V375, 2)); int sub__V380_count = term__V375_count*LINK_COUNT(sub__V380); permitUnusedInt(sub__V380_count);
      /* sub__V380 = &#1 */
      NamedPropertyLink namedP__V381 = LINK_NamedPropertyLink(sink__V374->context, NAMED_PROPERTIES(term__V375));
      VariablePropertyLink varP__V382 = LINK_VariablePropertyLink(sink__V374->context, VARIABLE_PROPERTIES(term__V375));
      UNLINK(sink__V374->context, term__V375);
      ADD_PROPERTIES(sink__V374, LINK_NamedPropertyLink(sink__V374->context, namedP__V381), LINK_VariablePropertyLink(sink__V374->context, varP__V382));
      { START(sink__V374, _M_If_s2);
        COPY(sink__V374, sub__V379);COPY(sink__V374, sub__V380);END(sink__V374, _M_If_s2); }
      UNLINK_NamedPropertyLink(sink__V374->context, namedP__V381); UNLINK_VariablePropertyLink(sink__V374->context, varP__V382);
      
      return 1;
    break; } case Data_M__sFalse: { /* Function DEFS-If-2$If$$False case $False */
      ASSERT(sink__V374->context, !strcmp(SYMBOL(term__V375),  "If" ));
      Term sub__V383 = SUB(term__V375, 0); permitUnusedTerm(sub__V383); int sub__V383_count = term__V375_count*LINK_COUNT(sub__V383); permitUnusedInt(sub__V383_count);
      ASSERT(sink__V374->context, !strcmp(SYMBOL(sub__V383),  "$False" ));
      Term sub__V384 = LINK(sink__V374->context, SUB(term__V375, 1)); int sub__V384_count = term__V375_count*LINK_COUNT(sub__V384); permitUnusedInt(sub__V384_count);
      /* sub__V384 = &#0 */
      Term sub__V385 = LINK(sink__V374->context, SUB(term__V375, 2)); int sub__V385_count = term__V375_count*LINK_COUNT(sub__V385); permitUnusedInt(sub__V385_count);
      /* sub__V385 = &#1 */
      NamedPropertyLink namedP__V386 = LINK_NamedPropertyLink(sink__V374->context, NAMED_PROPERTIES(term__V375));
      VariablePropertyLink varP__V387 = LINK_VariablePropertyLink(sink__V374->context, VARIABLE_PROPERTIES(term__V375));
      UNLINK(sink__V374->context, term__V375);
      ADD_PROPERTIES(sink__V374, LINK_NamedPropertyLink(sink__V374->context, namedP__V386), LINK_VariablePropertyLink(sink__V374->context, varP__V387));
      { START(sink__V374, _M_If_s1);
        COPY(sink__V374, sub__V384);COPY(sink__V374, sub__V385);END(sink__V374, _M_If_s1); }
      UNLINK_NamedPropertyLink(sink__V374->context, namedP__V386); UNLINK_VariablePropertyLink(sink__V374->context, varP__V387);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION Sort. */
int conBindOffs_M_Sort[] = {0 , 0};
char *nameFun_M_Sort(Term term) { return  "Sort" ; }
struct _ConstructionDescriptor descriptor_M_Sort = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_Sort), conBindOffs_M_Sort, &nameFun_M_Sort, &step_M_Sort};

int step_M_Sort(Sink sink__V388, Term term__V389)
{
  int term__V389_count = LINK_COUNT(term__V389); permitUnusedInt(term__V389_count);
  do {
    /* Contraction rule DEFS-Sort-1. */
    ASSERT(sink__V388->context, !strcmp(SYMBOL(term__V389),  "Sort" ));
    Term sub__V390 = LINK(sink__V388->context, SUB(term__V389, 0)); int sub__V390_count = term__V389_count*LINK_COUNT(sub__V390); permitUnusedInt(sub__V390_count);
    /* sub__V390 = &#1 */
    NamedPropertyLink namedP__V391 = LINK_NamedPropertyLink(sink__V388->context, NAMED_PROPERTIES(term__V389));
    VariablePropertyLink varP__V392 = LINK_VariablePropertyLink(sink__V388->context, VARIABLE_PROPERTIES(term__V389));
    UNLINK(sink__V388->context, term__V389);
    { START(sink__V388, _M__sTextCons);
      { START(sink__V388, _M__sTextChars);
        LITERAL(sink__V388,  "sort" ); END(sink__V388, _M__sTextChars); }
      { START(sink__V388, _M__sTextCons);
        { START(sink__V388, _M__sTextEmbed);
          { START(sink__V388, _M_AsText);
            { START(sink__V388, _M_MANGLE);
              COPY(sink__V388, sub__V390);END(sink__V388, _M_MANGLE); }
            END(sink__V388, _M_AsText); }
          END(sink__V388, _M__sTextEmbed); }
        { START(sink__V388, _M__sTextNil);
          END(sink__V388, _M__sTextNil); }
        END(sink__V388, _M__sTextCons); }
      END(sink__V388, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V388->context, namedP__V391); UNLINK_VariablePropertyLink(sink__V388->context, varP__V392);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DEnumTag. */
int conBindOffs_M_DEnumTag[] = {0 , 0 , 0};
char *nameFun_M_DEnumTag(Term term) { return  "DEnumTag" ; }
struct _ConstructionDescriptor descriptor_M_DEnumTag = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_DEnumTag), conBindOffs_M_DEnumTag, &nameFun_M_DEnumTag, &step_M_DEnumTag};

int step_M_DEnumTag(Sink sink__V393, Term term__V394)
{
  int term__V394_count = LINK_COUNT(term__V394); permitUnusedInt(term__V394_count);
  Term sub__V395 = FORCE(sink__V393->context, SUB(term__V394, 0));
  EnumOf_M_OK_xSORT choice__V396 = (IS_VARIABLE_USE(sub__V395) ? VarOf_M_OK_xSORT : (EnumOf_M_OK_xSORT) TAG(sub__V395));
  switch (choice__V396)
  {
    case Data_M_OK: { /* Function DEFS-DEnumTag-1$DEnumTag$OK case OK */
      ASSERT(sink__V393->context, !strcmp(SYMBOL(term__V394),  "DEnumTag" ));
      Term sub__V397 = SUB(term__V394, 0); permitUnusedTerm(sub__V397); int sub__V397_count = term__V394_count*LINK_COUNT(sub__V397); permitUnusedInt(sub__V397_count);
      CRSX_CHECK_SORT(sink__V393->context, sub__V397, &sort_M_OK_xSORT); ASSERT(sink__V393->context, !strcmp(SYMBOL(sub__V397),  "OK" ));
      Term sub__V398 = LINK(sink__V393->context, SUB(term__V394, 1)); int sub__V398_count = term__V394_count*LINK_COUNT(sub__V398); permitUnusedInt(sub__V398_count);
      /* sub__V398 = &#0 */
      NamedPropertyLink namedP__V399 = LINK_NamedPropertyLink(sink__V393->context, NAMED_PROPERTIES(term__V394));
      VariablePropertyLink varP__V400 = LINK_VariablePropertyLink(sink__V393->context, VARIABLE_PROPERTIES(term__V394));
      UNLINK(sink__V393->context, term__V394);
      ADD_PROPERTIES(sink__V393, LINK_NamedPropertyLink(sink__V393->context, namedP__V399), LINK_VariablePropertyLink(sink__V393->context, varP__V400));
      { START(sink__V393, _M_DEnumTag_s1);
        COPY(sink__V393, sub__V398);END(sink__V393, _M_DEnumTag_s1); }
      UNLINK_NamedPropertyLink(sink__V393->context, namedP__V399); UNLINK_VariablePropertyLink(sink__V393->context, varP__V400);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION FormArguments-binder-offsets$1. */
int conBindOffs_M_FormArguments__binder__offsets_s1[] = {0 , 0 , 0 , 0};
char *nameFun_M_FormArguments__binder__offsets_s1(Term term) { return  "FormArguments-binder-offsets$1" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__offsets_s1 = {NULL, 0, 3, sizeof(STRUCT_Con_M_FormArguments__binder__offsets_s1), conBindOffs_M_FormArguments__binder__offsets_s1, &nameFun_M_FormArguments__binder__offsets_s1, &step_M_FormArguments__binder__offsets_s1};

int step_M_FormArguments__binder__offsets_s1(Sink sink__V401, Term term__V402)
{
  int term__V402_count = LINK_COUNT(term__V402); permitUnusedInt(term__V402_count);
  do {
    /* Contraction rule DEFS-FormArguments-binder-offsets-1$FormArguments-binder-offsets$1$FORM-BINDER. */
    ASSERT(sink__V401->context, !strcmp(SYMBOL(term__V402),  "FormArguments-binder-offsets$1" ));
    Term sub__V403 = SUB(term__V402, 0); permitUnusedTerm(sub__V403); int sub__V403_count = term__V402_count*LINK_COUNT(sub__V403); permitUnusedInt(sub__V403_count);
    FORCE(sink__V401->context, sub__V403); SUB(term__V402, 0) = sub__V403;
    if (strcmp(SYMBOL(sub__V403),  "FORM-BINDER" )) break;
    Term sub__V404 = LINK(sink__V401->context, SUB(sub__V403, 0)); int sub__V404_count = sub__V403_count*LINK_COUNT(sub__V404); permitUnusedInt(sub__V404_count);
    CRSX_CHECK_SORT(sink__V401->context, sub__V404, &sort_M_Reified_xSort); /* sub__V404 = &#0-0 */
    Variable y__V405 = BINDER(sub__V403,1,0); if (sub__V403_count <= 1) UNBIND(y__V405);
    Term sub__V406 = LINK(sink__V401->context, SUB(sub__V403, 1)); int sub__V406_count = sub__V403_count*LINK_COUNT(sub__V406); permitUnusedInt(sub__V406_count);
    CRSX_CHECK_SORT(sink__V401->context, sub__V406, &sort_M_Reified_xFormArgument); /* sub__V406 = &#0-1 */
    Term sub__V407 = LINK(sink__V401->context, SUB(term__V402, 1)); int sub__V407_count = term__V402_count*LINK_COUNT(sub__V407); permitUnusedInt(sub__V407_count);
    /* sub__V407 = &#2 */
    Term sub__V408 = LINK(sink__V401->context, SUB(term__V402, 2)); int sub__V408_count = term__V402_count*LINK_COUNT(sub__V408); permitUnusedInt(sub__V408_count);
    /* sub__V408 = &#3 */
    NamedPropertyLink namedP__V409 = LINK_NamedPropertyLink(sink__V401->context, NAMED_PROPERTIES(term__V402));
    VariablePropertyLink varP__V410 = LINK_VariablePropertyLink(sink__V401->context, VARIABLE_PROPERTIES(term__V402));
    UNLINK(sink__V401->context, term__V402);
    ADD_PROPERTIES(sink__V401, LINK_NamedPropertyLink(sink__V401->context, namedP__V409), LINK_VariablePropertyLink(sink__V401->context, varP__V410));
    { START(sink__V401, _M_FormArguments__binder__offsets_s3);
      COPY(sink__V401, sub__V404);{ if (!IS_BOUND(y__V405)) { REBIND(y__V405);
          Variable binds__V411[1] = {y__V405}; BINDS(sink__V401, 1, binds__V411);
          COPY(sink__V401, sub__V406); /* REUSED SUBSTITUTION */  }
        else { Variable b__V412 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V401->context,"b__V412");
          Variable binds__V413[1] = {b__V412}; BINDS(sink__V401, 1, binds__V413);
          {
            Term arg__V414;
            { Sink buf__V415 = ALLOCA_BUFFER(sink__V401->context);
              USE(buf__V415, b__V412); arg__V414 = BUFFER_TERM(buf__V415); FREE_BUFFER(buf__V415); }
            Variable vars__V416[1] = {y__V405};
            Term args__V417[1] = {arg__V414};
            struct _SubstitutionFrame substitution__V418 = {NULL, 0, 1, vars__V416, args__V417, NULL};
            SUBSTITUTE(sink__V401, sub__V406, &substitution__V418); }
              }
         }
      COPY(sink__V401, sub__V407);COPY(sink__V401, sub__V408);END(sink__V401, _M_FormArguments__binder__offsets_s3); }
    UNLINK_NamedPropertyLink(sink__V401->context, namedP__V409); UNLINK_VariablePropertyLink(sink__V401->context, varP__V410);
    
    return 1;
  } while (0);
  do {
    /* Contraction rule DEFS-FormArguments-binder-offsets-2$FormArguments-binder-offsets$1$FORM-ARGUMENT. */
    ASSERT(sink__V401->context, !strcmp(SYMBOL(term__V402),  "FormArguments-binder-offsets$1" ));
    Term sub__V419 = SUB(term__V402, 0); permitUnusedTerm(sub__V419); int sub__V419_count = term__V402_count*LINK_COUNT(sub__V419); permitUnusedInt(sub__V419_count);
    FORCE(sink__V401->context, sub__V419); SUB(term__V402, 0) = sub__V419;
    if (strcmp(SYMBOL(sub__V419),  "FORM-ARGUMENT" )) break;
    Term sub__V420 = LINK(sink__V401->context, SUB(sub__V419, 0)); int sub__V420_count = sub__V419_count*LINK_COUNT(sub__V420); permitUnusedInt(sub__V420_count);
    CRSX_CHECK_SORT(sink__V401->context, sub__V420, &sort_M_Reified_xSort); /* sub__V420 = &#0-0 */
    Term sub__V421 = LINK(sink__V401->context, SUB(term__V402, 1)); int sub__V421_count = term__V402_count*LINK_COUNT(sub__V421); permitUnusedInt(sub__V421_count);
    /* sub__V421 = &#1 */
    Term sub__V422 = LINK(sink__V401->context, SUB(term__V402, 2)); int sub__V422_count = term__V402_count*LINK_COUNT(sub__V422); permitUnusedInt(sub__V422_count);
    /* sub__V422 = &#2 */
    NamedPropertyLink namedP__V423 = LINK_NamedPropertyLink(sink__V401->context, NAMED_PROPERTIES(term__V402));
    VariablePropertyLink varP__V424 = LINK_VariablePropertyLink(sink__V401->context, VARIABLE_PROPERTIES(term__V402));
    UNLINK(sink__V401->context, term__V402);
    ADD_PROPERTIES(sink__V401, LINK_NamedPropertyLink(sink__V401->context, namedP__V423), LINK_VariablePropertyLink(sink__V401->context, varP__V424));
    { START(sink__V401, _M_FormArguments__binder__offsets_s2);
      COPY(sink__V401, sub__V420);COPY(sink__V401, sub__V421);COPY(sink__V401, sub__V422);END(sink__V401, _M_FormArguments__binder__offsets_s2); }
    UNLINK_NamedPropertyLink(sink__V401->context, namedP__V423); UNLINK_VariablePropertyLink(sink__V401->context, varP__V424);
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION FormArguments-binder-offsets$2. */
int conBindOffs_M_FormArguments__binder__offsets_s2[] = {0 , 0 , 0 , 0};
char *nameFun_M_FormArguments__binder__offsets_s2(Term term) { return  "FormArguments-binder-offsets$2" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__offsets_s2 = {NULL, 0, 3, sizeof(STRUCT_Con_M_FormArguments__binder__offsets_s2), conBindOffs_M_FormArguments__binder__offsets_s2, &nameFun_M_FormArguments__binder__offsets_s2, &step_M_FormArguments__binder__offsets_s2};

int step_M_FormArguments__binder__offsets_s2(Sink sink__V425, Term term__V426)
{
  int term__V426_count = LINK_COUNT(term__V426); permitUnusedInt(term__V426_count);
  do {
    /* Contraction rule DEFS-FormArguments-binder-offsets-2. */
    ASSERT(sink__V425->context, !strcmp(SYMBOL(term__V426),  "FormArguments-binder-offsets$2" ));
    Term sub__V427 = SUB(term__V426, 0); permitUnusedTerm(sub__V427); int sub__V427_count = term__V426_count*LINK_COUNT(sub__V427); permitUnusedInt(sub__V427_count);
    CRSX_CHECK_SORT(sink__V425->context, sub__V427, &sort_M_Reified_xSort); /* sub__V427 = &#111 */
    Term sub__V428 = LINK(sink__V425->context, SUB(term__V426, 1)); int sub__V428_count = term__V426_count*LINK_COUNT(sub__V428); permitUnusedInt(sub__V428_count);
    /* sub__V428 = &#12 */
    Term sub__V429 = LINK(sink__V425->context, SUB(term__V426, 2)); int sub__V429_count = term__V426_count*LINK_COUNT(sub__V429); permitUnusedInt(sub__V429_count);
    /* sub__V429 = &#2 */
    UNLINK(sink__V425->context, term__V426);
    { START(sink__V425, _M__sCons);
      COPY(sink__V425, LINK(sink__V425->context, sub__V429));{ START(sink__V425, _M_FormArguments__binder__offsets);
        COPY(sink__V425, sub__V428);COPY(sink__V425, sub__V429);END(sink__V425, _M_FormArguments__binder__offsets); }
      END(sink__V425, _M__sCons); }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION FormArguments-binder-offsets$3. */
int conBindOffs_M_FormArguments__binder__offsets_s3[] = {0 , 0 , 1 , 1 , 1};
char *nameFun_M_FormArguments__binder__offsets_s3(Term term) { return  "FormArguments-binder-offsets$3" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__offsets_s3 = {NULL, 0, 4, sizeof(STRUCT_Con_M_FormArguments__binder__offsets_s3), conBindOffs_M_FormArguments__binder__offsets_s3, &nameFun_M_FormArguments__binder__offsets_s3, &step_M_FormArguments__binder__offsets_s3};

int step_M_FormArguments__binder__offsets_s3(Sink sink__V430, Term term__V431)
{
  int term__V431_count = LINK_COUNT(term__V431); permitUnusedInt(term__V431_count);
  do {
    /* Contraction rule DEFS-FormArguments-binder-offsets-1. */
    ASSERT(sink__V430->context, !strcmp(SYMBOL(term__V431),  "FormArguments-binder-offsets$3" ));
    Term sub__V432 = SUB(term__V431, 0); permitUnusedTerm(sub__V432); int sub__V432_count = term__V431_count*LINK_COUNT(sub__V432); permitUnusedInt(sub__V432_count);
    CRSX_CHECK_SORT(sink__V430->context, sub__V432, &sort_M_Reified_xSort); /* sub__V432 = &#111 */
    Variable x__V433 = BINDER(term__V431,1,0); if (term__V431_count <= 1) UNBIND(x__V433);
    Term sub__V434 = LINK(sink__V430->context, SUB(term__V431, 1)); int sub__V434_count = term__V431_count*LINK_COUNT(sub__V434); permitUnusedInt(sub__V434_count);
    CRSX_CHECK_SORT(sink__V430->context, sub__V434, &sort_M_Reified_xFormArgument); /* sub__V434 = &#112 */
    Variable y__V99 = x__V433; permitUnusedVariable(y__V99);
    Term sub__V435 = LINK(sink__V430->context, SUB(term__V431, 2)); int sub__V435_count = term__V431_count*LINK_COUNT(sub__V435); permitUnusedInt(sub__V435_count);
    /* sub__V435 = &#12 */
    Term sub__V436 = LINK(sink__V430->context, SUB(term__V431, 3)); int sub__V436_count = term__V431_count*LINK_COUNT(sub__V436); permitUnusedInt(sub__V436_count);
    /* sub__V436 = &#2 */
    UNLINK(sink__V430->context, term__V431);
    { START(sink__V430, _M_FormArguments__binder__offsets);
      { START(sink__V430, _M__sCons);
        COPY(sink__V430, sub__V434); /* REUSED SUBSTITUTION */ COPY(sink__V430, sub__V435);END(sink__V430, _M__sCons); }
      { double num__V437;
        num__V437 = (double) 1; { double tmp__V438;
          tmp__V438 = DOUBLE(sub__V436); num__V437 += tmp__V438; }
        LITERALNF(sink__V430, (size_t) 31, "%G", num__V437); }
      END(sink__V430, _M_FormArguments__binder__offsets); }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION FormArguments-binder-offsets$4. */
int conBindOffs_M_FormArguments__binder__offsets_s4[] = {0 , 0};
char *nameFun_M_FormArguments__binder__offsets_s4(Term term) { return  "FormArguments-binder-offsets$4" ; }
struct _ConstructionDescriptor descriptor_M_FormArguments__binder__offsets_s4 = {NULL, 0, 1, sizeof(STRUCT_Con_M_FormArguments__binder__offsets_s4), conBindOffs_M_FormArguments__binder__offsets_s4, &nameFun_M_FormArguments__binder__offsets_s4, &step_M_FormArguments__binder__offsets_s4};

int step_M_FormArguments__binder__offsets_s4(Sink sink__V439, Term term__V440)
{
  int term__V440_count = LINK_COUNT(term__V440); permitUnusedInt(term__V440_count);
  do {
    /* Contraction rule DEFS-FormArguments-binder-offsets-3. */
    ASSERT(sink__V439->context, !strcmp(SYMBOL(term__V440),  "FormArguments-binder-offsets$4" ));
    Term sub__V441 = SUB(term__V440, 0); permitUnusedTerm(sub__V441); int sub__V441_count = term__V440_count*LINK_COUNT(sub__V441); permitUnusedInt(sub__V441_count);
    /* sub__V441 = &#2 */
    UNLINK(sink__V439->context, term__V440);
    { START(sink__V439, _M__sNil); END(sink__V439, _M__sNil); } 
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION UnString$1. */
int conBindOffs_M_UnString_s1[] = {0 , 0};
char *nameFun_M_UnString_s1(Term term) { return  "UnString$1" ; }
struct _ConstructionDescriptor descriptor_M_UnString_s1 = {NULL, 0, 1, sizeof(STRUCT_Con_M_UnString_s1), conBindOffs_M_UnString_s1, &nameFun_M_UnString_s1, &step_M_UnString_s1};

int step_M_UnString_s1(Sink sink__V442, Term term__V443)
{
  int term__V443_count = LINK_COUNT(term__V443); permitUnusedInt(term__V443_count);
  do {
    /* Contraction rule DEFS-UnString-1. */
    ASSERT(sink__V442->context, !strcmp(SYMBOL(term__V443),  "UnString$1" ));
    Term sub__V444 = LINK(sink__V442->context, SUB(term__V443, 0)); int sub__V444_count = term__V443_count*LINK_COUNT(sub__V444); permitUnusedInt(sub__V444_count);
    /* sub__V444 = &#11 */
    UNLINK(sink__V442->context, term__V443);
    COPY(sink__V442, sub__V444);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION MetaVar2$1. */
int conBindOffs_M_MetaVar2_s1[] = {0 , 0};
char *nameFun_M_MetaVar2_s1(Term term) { return  "MetaVar2$1" ; }
struct _ConstructionDescriptor descriptor_M_MetaVar2_s1 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_MetaVar2_s1), conBindOffs_M_MetaVar2_s1, &nameFun_M_MetaVar2_s1, &step_M_MetaVar2_s1};

int step_M_MetaVar2_s1(Sink sink__V445, Term term__V446)
{
  int term__V446_count = LINK_COUNT(term__V446); permitUnusedInt(term__V446_count);
  do {
    /* Contraction rule DEFS-MetaVar2-2. */
    ASSERT(sink__V445->context, !strcmp(SYMBOL(term__V446),  "MetaVar2$1" ));
    Term sub__V447 = LINK(sink__V445->context, SUB(term__V446, 0)); int sub__V447_count = term__V446_count*LINK_COUNT(sub__V447); permitUnusedInt(sub__V447_count);
    /* sub__V447 = &#11 */
    NamedPropertyLink namedP__V448 = LINK_NamedPropertyLink(sink__V445->context, NAMED_PROPERTIES(term__V446));
    VariablePropertyLink varP__V449 = LINK_VariablePropertyLink(sink__V445->context, VARIABLE_PROPERTIES(term__V446));
    UNLINK(sink__V445->context, term__V446);
    { START(sink__V445, _M_TOKEN);
      COPY(sink__V445, sub__V447);END(sink__V445, _M_TOKEN); }
    UNLINK_NamedPropertyLink(sink__V445->context, namedP__V448); UNLINK_VariablePropertyLink(sink__V445->context, varP__V449);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION MetaVar2$2. */
int conBindOffs_M_MetaVar2_s2[] = {0 , 0};
char *nameFun_M_MetaVar2_s2(Term term) { return  "MetaVar2$2" ; }
struct _ConstructionDescriptor descriptor_M_MetaVar2_s2 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_MetaVar2_s2), conBindOffs_M_MetaVar2_s2, &nameFun_M_MetaVar2_s2, &step_M_MetaVar2_s2};

int step_M_MetaVar2_s2(Sink sink__V450, Term term__V451)
{
  int term__V451_count = LINK_COUNT(term__V451); permitUnusedInt(term__V451_count);
  Term sub__V452 = FORCE(sink__V450->context, SUB(term__V451, 0));
  EnumOf_M_Reified_xVariable choice__V453 = (IS_VARIABLE_USE(sub__V452) ? VarOf_M_Reified_xVariable : (EnumOf_M_Reified_xVariable) TAG(sub__V452));
  switch (choice__V453)
  {
    case VarOf_M_Reified_xVariable: {
      do {
        ASSERT(sink__V450->context, !strcmp(SYMBOL(term__V451),  "MetaVar2$2" ));
        Term sub__V454 = SUB(term__V451, 0); permitUnusedTerm(sub__V454); int sub__V454_count = term__V451_count*LINK_COUNT(sub__V454); permitUnusedInt(sub__V454_count);
        CRSX_CHECK_SORT(sink__V450->context, sub__V454, &sort_M_Reified_xVariable); /* Function DEFS-MetaVar2-1$vFree fall-back case for free variable */
        Variable z__V455 = VARIABLE(sub__V454); permitUnusedVariable(z__V455);
        NamedPropertyLink namedP__V456 = LINK_NamedPropertyLink(sink__V450->context, NAMED_PROPERTIES(term__V451));
        VariablePropertyLink varP__V457 = LINK_VariablePropertyLink(sink__V450->context, VARIABLE_PROPERTIES(term__V451));
        UNLINK(sink__V450->context, term__V451);
        ADD_PROPERTIES(sink__V450, LINK_NamedPropertyLink(sink__V450->context, namedP__V456), LINK_VariablePropertyLink(sink__V450->context, varP__V457));
        { START(sink__V450, _M_MetaVar2_s3);
          USE(sink__V450, z__V455); END(sink__V450, _M_MetaVar2_s3); }
        UNLINK_NamedPropertyLink(sink__V450->context, namedP__V456); UNLINK_VariablePropertyLink(sink__V450->context, varP__V457);
        
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

int step_M_MetaVar2_s3(Sink sink__V458, Term term__V459)
{
  int term__V459_count = LINK_COUNT(term__V459); permitUnusedInt(term__V459_count);
  do {
    /* Contraction rule DEFS-MetaVar2-1. */
    ASSERT(sink__V458->context, !strcmp(SYMBOL(term__V459),  "MetaVar2$3" ));
    Term sub__V460 = LINK(sink__V458->context, SUB(term__V459, 0)); int sub__V460_count = term__V459_count*LINK_COUNT(sub__V460); permitUnusedInt(sub__V460_count);
    CRSX_CHECK_SORT(sink__V458->context, sub__V460, &sort_M_Reified_xVariable); UNLINK_SUB(sink__V458->context, term__V459,  0); NORMALIZE(sink__V458->context, sub__V460); SUB(term__V459,  0) = LINK(sink__V458->context, sub__V460);
    /* sub__V460 = &#11 */
    NamedPropertyLink namedP__V461 = LINK_NamedPropertyLink(sink__V458->context, NAMED_PROPERTIES(term__V459));
    VariablePropertyLink varP__V462 = LINK_VariablePropertyLink(sink__V458->context, VARIABLE_PROPERTIES(term__V459));
    UNLINK(sink__V458->context, term__V459);
    { START(sink__V458, _M__sTextCons);
      { START(sink__V458, _M__sTextEmbed);
        { START(sink__V458, _M_AsText);
          COPY(sink__V458, sub__V460);END(sink__V458, _M_AsText); }
        END(sink__V458, _M__sTextEmbed); }
      { START(sink__V458, _M__sTextNil);
        END(sink__V458, _M__sTextNil); }
      END(sink__V458, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V458->context, namedP__V461); UNLINK_VariablePropertyLink(sink__V458->context, varP__V462);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DDescriptor. */
int conBindOffs_M_DDescriptor[] = {0 , 0 , 0};
char *nameFun_M_DDescriptor(Term term) { return  "DDescriptor" ; }
struct _ConstructionDescriptor descriptor_M_DDescriptor = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_DDescriptor), conBindOffs_M_DDescriptor, &nameFun_M_DDescriptor, &step_M_DDescriptor};

int step_M_DDescriptor(Sink sink__V463, Term term__V464)
{
  int term__V464_count = LINK_COUNT(term__V464); permitUnusedInt(term__V464_count);
  Term sub__V465 = FORCE(sink__V463->context, SUB(term__V464, 0));
  EnumOf_M_OK_xSORT choice__V466 = (IS_VARIABLE_USE(sub__V465) ? VarOf_M_OK_xSORT : (EnumOf_M_OK_xSORT) TAG(sub__V465));
  switch (choice__V466)
  {
    case Data_M_OK: { /* Function DEFS-DDescriptor-1$DDescriptor$OK case OK */
      ASSERT(sink__V463->context, !strcmp(SYMBOL(term__V464),  "DDescriptor" ));
      Term sub__V467 = SUB(term__V464, 0); permitUnusedTerm(sub__V467); int sub__V467_count = term__V464_count*LINK_COUNT(sub__V467); permitUnusedInt(sub__V467_count);
      CRSX_CHECK_SORT(sink__V463->context, sub__V467, &sort_M_OK_xSORT); ASSERT(sink__V463->context, !strcmp(SYMBOL(sub__V467),  "OK" ));
      Term sub__V468 = LINK(sink__V463->context, SUB(term__V464, 1)); int sub__V468_count = term__V464_count*LINK_COUNT(sub__V468); permitUnusedInt(sub__V468_count);
      /* sub__V468 = &#0 */
      NamedPropertyLink namedP__V469 = LINK_NamedPropertyLink(sink__V463->context, NAMED_PROPERTIES(term__V464));
      VariablePropertyLink varP__V470 = LINK_VariablePropertyLink(sink__V463->context, VARIABLE_PROPERTIES(term__V464));
      UNLINK(sink__V463->context, term__V464);
      ADD_PROPERTIES(sink__V463, LINK_NamedPropertyLink(sink__V463->context, namedP__V469), LINK_VariablePropertyLink(sink__V463->context, varP__V470));
      { START(sink__V463, _M_DDescriptor_s1);
        COPY(sink__V463, sub__V468);END(sink__V463, _M_DDescriptor_s1); }
      UNLINK_NamedPropertyLink(sink__V463->context, namedP__V469); UNLINK_VariablePropertyLink(sink__V463->context, varP__V470);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION Step. */
int conBindOffs_M_Step[] = {0 , 0};
char *nameFun_M_Step(Term term) { return  "Step" ; }
struct _ConstructionDescriptor descriptor_M_Step = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_Step), conBindOffs_M_Step, &nameFun_M_Step, &step_M_Step};

int step_M_Step(Sink sink__V471, Term term__V472)
{
  int term__V472_count = LINK_COUNT(term__V472); permitUnusedInt(term__V472_count);
  do {
    /* Contraction rule DEFS-Step-1. */
    ASSERT(sink__V471->context, !strcmp(SYMBOL(term__V472),  "Step" ));
    Term sub__V473 = LINK(sink__V471->context, SUB(term__V472, 0)); int sub__V473_count = term__V472_count*LINK_COUNT(sub__V473); permitUnusedInt(sub__V473_count);
    /* sub__V473 = &#1 */
    NamedPropertyLink namedP__V474 = LINK_NamedPropertyLink(sink__V471->context, NAMED_PROPERTIES(term__V472));
    VariablePropertyLink varP__V475 = LINK_VariablePropertyLink(sink__V471->context, VARIABLE_PROPERTIES(term__V472));
    UNLINK(sink__V471->context, term__V472);
    { START(sink__V471, _M__sTextCons);
      { START(sink__V471, _M__sTextChars);
        LITERAL(sink__V471,  "step" ); END(sink__V471, _M__sTextChars); }
      { START(sink__V471, _M__sTextCons);
        { START(sink__V471, _M__sTextEmbed);
          { START(sink__V471, _M_AsText);
            { START(sink__V471, _M_MANGLE);
              COPY(sink__V471, sub__V473);END(sink__V471, _M_MANGLE); }
            END(sink__V471, _M_AsText); }
          END(sink__V471, _M__sTextEmbed); }
        { START(sink__V471, _M__sTextNil);
          END(sink__V471, _M__sTextNil); }
        END(sink__V471, _M__sTextCons); }
      END(sink__V471, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V471->context, namedP__V474); UNLINK_VariablePropertyLink(sink__V471->context, varP__V475);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION PromiscuityString$1. */
int conBindOffs_M_PromiscuityString_s1[] = {0};
char *nameFun_M_PromiscuityString_s1(Term term) { return  "PromiscuityString$1" ; }
struct _ConstructionDescriptor descriptor_M_PromiscuityString_s1 = {NULL, 0, 0, sizeof(STRUCT_Con_M_PromiscuityString_s1), conBindOffs_M_PromiscuityString_s1, &nameFun_M_PromiscuityString_s1, &step_M_PromiscuityString_s1};

int step_M_PromiscuityString_s1(Sink sink__V476, Term term__V477)
{
  int term__V477_count = LINK_COUNT(term__V477); permitUnusedInt(term__V477_count);
  do {
    /* Contraction rule DEFS-PromiscuityString-1. */
    ASSERT(sink__V476->context, !strcmp(SYMBOL(term__V477),  "PromiscuityString$1" ));
    UNLINK(sink__V476->context, term__V477);
    LITERAL(sink__V476,  "LINEAR" ); 
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION PromiscuityString$2. */
int conBindOffs_M_PromiscuityString_s2[] = {0};
char *nameFun_M_PromiscuityString_s2(Term term) { return  "PromiscuityString$2" ; }
struct _ConstructionDescriptor descriptor_M_PromiscuityString_s2 = {NULL, 0, 0, sizeof(STRUCT_Con_M_PromiscuityString_s2), conBindOffs_M_PromiscuityString_s2, &nameFun_M_PromiscuityString_s2, &step_M_PromiscuityString_s2};

int step_M_PromiscuityString_s2(Sink sink__V478, Term term__V479)
{
  int term__V479_count = LINK_COUNT(term__V479); permitUnusedInt(term__V479_count);
  do {
    /* Contraction rule DEFS-PromiscuityString-2. */
    ASSERT(sink__V478->context, !strcmp(SYMBOL(term__V479),  "PromiscuityString$2" ));
    UNLINK(sink__V478->context, term__V479);
    LITERAL(sink__V478,  "PROMISCUOUS" ); 
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION PromiscuityString. */
int conBindOffs_M_PromiscuityString[] = {0 , 0};
char *nameFun_M_PromiscuityString(Term term) { return  "PromiscuityString" ; }
struct _ConstructionDescriptor descriptor_M_PromiscuityString = {NULL, 0, 1, sizeof(STRUCT_Con_M_PromiscuityString), conBindOffs_M_PromiscuityString, &nameFun_M_PromiscuityString, &step_M_PromiscuityString};

int step_M_PromiscuityString(Sink sink__V480, Term term__V481)
{
  int term__V481_count = LINK_COUNT(term__V481); permitUnusedInt(term__V481_count);
  Term sub__V482 = FORCE(sink__V480->context, SUB(term__V481, 0));
  EnumOf_M_Reified_xPromiscuity choice__V483 = (IS_VARIABLE_USE(sub__V482) ? VarOf_M_Reified_xPromiscuity : (EnumOf_M_Reified_xPromiscuity) TAG(sub__V482));
  switch (choice__V483)
  {
    case Data_M_LINEAR: { /* Function DEFS-PromiscuityString-1$PromiscuityString$LINEAR case LINEAR */
      ASSERT(sink__V480->context, !strcmp(SYMBOL(term__V481),  "PromiscuityString" ));
      Term sub__V484 = SUB(term__V481, 0); permitUnusedTerm(sub__V484); int sub__V484_count = term__V481_count*LINK_COUNT(sub__V484); permitUnusedInt(sub__V484_count);
      CRSX_CHECK_SORT(sink__V480->context, sub__V484, &sort_M_Reified_xPromiscuity); ASSERT(sink__V480->context, !strcmp(SYMBOL(sub__V484),  "LINEAR" ));
      NamedPropertyLink namedP__V485 = LINK_NamedPropertyLink(sink__V480->context, NAMED_PROPERTIES(term__V481));
      VariablePropertyLink varP__V486 = LINK_VariablePropertyLink(sink__V480->context, VARIABLE_PROPERTIES(term__V481));
      UNLINK(sink__V480->context, term__V481);
      ADD_PROPERTIES(sink__V480, LINK_NamedPropertyLink(sink__V480->context, namedP__V485), LINK_VariablePropertyLink(sink__V480->context, varP__V486));
      { START(sink__V480, _M_PromiscuityString_s1);
        END(sink__V480, _M_PromiscuityString_s1); }
      UNLINK_NamedPropertyLink(sink__V480->context, namedP__V485); UNLINK_VariablePropertyLink(sink__V480->context, varP__V486);
      
      return 1;
    break; } case Data_M_PROMISCUOUS: { /* Function DEFS-PromiscuityString-2$PromiscuityString$PROMISCUOUS case PROMISCUOUS */
      ASSERT(sink__V480->context, !strcmp(SYMBOL(term__V481),  "PromiscuityString" ));
      Term sub__V487 = SUB(term__V481, 0); permitUnusedTerm(sub__V487); int sub__V487_count = term__V481_count*LINK_COUNT(sub__V487); permitUnusedInt(sub__V487_count);
      CRSX_CHECK_SORT(sink__V480->context, sub__V487, &sort_M_Reified_xPromiscuity); ASSERT(sink__V480->context, !strcmp(SYMBOL(sub__V487),  "PROMISCUOUS" ));
      NamedPropertyLink namedP__V488 = LINK_NamedPropertyLink(sink__V480->context, NAMED_PROPERTIES(term__V481));
      VariablePropertyLink varP__V489 = LINK_VariablePropertyLink(sink__V480->context, VARIABLE_PROPERTIES(term__V481));
      UNLINK(sink__V480->context, term__V481);
      ADD_PROPERTIES(sink__V480, LINK_NamedPropertyLink(sink__V480->context, namedP__V488), LINK_VariablePropertyLink(sink__V480->context, varP__V489));
      { START(sink__V480, _M_PromiscuityString_s2);
        END(sink__V480, _M_PromiscuityString_s2); }
      UNLINK_NamedPropertyLink(sink__V480->context, namedP__V488); UNLINK_VariablePropertyLink(sink__V480->context, varP__V489);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION MapText1$1. */
int conBindOffs_M_MapText1_s1[] = {0 , 0 , 1 , 2};
char *nameFun_M_MapText1_s1(Term term) { return  "MapText1$1" ; }
struct _ConstructionDescriptor descriptor_M_MapText1_s1 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_MapText1_s1), conBindOffs_M_MapText1_s1, &nameFun_M_MapText1_s1, &step_M_MapText1_s1};

int step_M_MapText1_s1(Sink sink__V490, Term term__V491)
{
  int term__V491_count = LINK_COUNT(term__V491); permitUnusedInt(term__V491_count);
  Term sub__V492 = FORCE(sink__V490->context, SUB(term__V491, 0));
  EnumOf_M__sList choice__V493 = (IS_VARIABLE_USE(sub__V492) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V492));
  switch (choice__V493)
  {
    case Data_M__sCons: { /* Function DEFS-MapText1-1$MapText1$1$$Cons case $Cons */
      ASSERT(sink__V490->context, !strcmp(SYMBOL(term__V491),  "MapText1$1" ));
      Term sub__V494 = SUB(term__V491, 0); permitUnusedTerm(sub__V494); int sub__V494_count = term__V491_count*LINK_COUNT(sub__V494); permitUnusedInt(sub__V494_count);
      ASSERT(sink__V490->context, !strcmp(SYMBOL(sub__V494),  "$Cons" ));
      Term sub__V495 = LINK(sink__V490->context, SUB(sub__V494, 0)); int sub__V495_count = sub__V494_count*LINK_COUNT(sub__V495); permitUnusedInt(sub__V495_count);
      /* sub__V495 = &#0-0 */
      Term sub__V496 = LINK(sink__V490->context, SUB(sub__V494, 1)); int sub__V496_count = sub__V494_count*LINK_COUNT(sub__V496); permitUnusedInt(sub__V496_count);
      /* sub__V496 = &#0-1 */
      Variable x__V497 = BINDER(term__V491,1,0); if (term__V491_count <= 1) UNBIND(x__V497);
      Term sub__V498 = LINK(sink__V490->context, SUB(term__V491, 1)); int sub__V498_count = term__V491_count*LINK_COUNT(sub__V498); permitUnusedInt(sub__V498_count);
      CRSX_CHECK_SORT(sink__V490->context, sub__V498, &sort_M_Reified_xVariable); /* sub__V498 = &#2 */
      Variable x__V499 = BINDER(term__V491,2,0); if (term__V491_count <= 1) UNBIND(x__V499);
      Term sub__V500 = LINK(sink__V490->context, SUB(term__V491, 2)); int sub__V500_count = term__V491_count*LINK_COUNT(sub__V500); permitUnusedInt(sub__V500_count);
      CRSX_CHECK_SORT(sink__V490->context, sub__V500, &sort_M_Reified_xVariable); /* sub__V500 = &#3 */
      NamedPropertyLink namedP__V501 = LINK_NamedPropertyLink(sink__V490->context, NAMED_PROPERTIES(term__V491));
      VariablePropertyLink varP__V502 = LINK_VariablePropertyLink(sink__V490->context, VARIABLE_PROPERTIES(term__V491));
      UNLINK(sink__V490->context, term__V491);
      ADD_PROPERTIES(sink__V490, LINK_NamedPropertyLink(sink__V490->context, namedP__V501), LINK_VariablePropertyLink(sink__V490->context, varP__V502));
      { START(sink__V490, _M_MapText1_s2);
        COPY(sink__V490, sub__V495);COPY(sink__V490, sub__V496);{ if (!IS_BOUND(x__V497)) { REBIND(x__V497);
            Variable binds__V503[1] = {x__V497}; BINDS(sink__V490, 1, binds__V503);
            COPY(sink__V490, sub__V498); /* REUSED SUBSTITUTION */  }
          else { Variable b__V504 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V490->context,"b__V504");
            Variable binds__V505[1] = {b__V504}; BINDS(sink__V490, 1, binds__V505);
            {
              Term arg__V506;
              { Sink buf__V507 = ALLOCA_BUFFER(sink__V490->context);
                USE(buf__V507, b__V504); arg__V506 = BUFFER_TERM(buf__V507); FREE_BUFFER(buf__V507); }
              Variable vars__V508[1] = {x__V497};
              Term args__V509[1] = {arg__V506};
              struct _SubstitutionFrame substitution__V510 = {NULL, 0, 1, vars__V508, args__V509, NULL};
              SUBSTITUTE(sink__V490, sub__V498, &substitution__V510); }
                }
           }
        { if (!IS_BOUND(x__V499)) { REBIND(x__V499);
            Variable binds__V511[1] = {x__V499}; BINDS(sink__V490, 1, binds__V511);
            COPY(sink__V490, sub__V500); /* REUSED SUBSTITUTION */  }
          else { Variable b__V512 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V490->context,"b__V512");
            Variable binds__V513[1] = {b__V512}; BINDS(sink__V490, 1, binds__V513);
            {
              Term arg__V514;
              { Sink buf__V515 = ALLOCA_BUFFER(sink__V490->context);
                USE(buf__V515, b__V512); arg__V514 = BUFFER_TERM(buf__V515); FREE_BUFFER(buf__V515); }
              Variable vars__V516[1] = {x__V499};
              Term args__V517[1] = {arg__V514};
              struct _SubstitutionFrame substitution__V518 = {NULL, 0, 1, vars__V516, args__V517, NULL};
              SUBSTITUTE(sink__V490, sub__V500, &substitution__V518); }
                }
           }
        END(sink__V490, _M_MapText1_s2); }
      UNLINK_NamedPropertyLink(sink__V490->context, namedP__V501); UNLINK_VariablePropertyLink(sink__V490->context, varP__V502);
      
      return 1;
    break; } case Data_M__sNil: { /* Function DEFS-MapText1-2$MapText1$1$$Nil case $Nil */
      ASSERT(sink__V490->context, !strcmp(SYMBOL(term__V491),  "MapText1$1" ));
      Term sub__V519 = SUB(term__V491, 0); permitUnusedTerm(sub__V519); int sub__V519_count = term__V491_count*LINK_COUNT(sub__V519); permitUnusedInt(sub__V519_count);
      ASSERT(sink__V490->context, !strcmp(SYMBOL(sub__V519),  "$Nil" ));
      Variable x__V520 = BINDER(term__V491,1,0); if (term__V491_count <= 1) UNBIND(x__V520);
      Term sub__V521 = LINK(sink__V490->context, SUB(term__V491, 1)); int sub__V521_count = term__V491_count*LINK_COUNT(sub__V521); permitUnusedInt(sub__V521_count);
      CRSX_CHECK_SORT(sink__V490->context, sub__V521, &sort_M_Reified_xVariable); /* sub__V521 = &#0 */
      Variable x__V522 = BINDER(term__V491,2,0); if (term__V491_count <= 1) UNBIND(x__V522);
      Term sub__V523 = LINK(sink__V490->context, SUB(term__V491, 2)); int sub__V523_count = term__V491_count*LINK_COUNT(sub__V523); permitUnusedInt(sub__V523_count);
      CRSX_CHECK_SORT(sink__V490->context, sub__V523, &sort_M_Reified_xVariable); /* sub__V523 = &#1 */
      NamedPropertyLink namedP__V524 = LINK_NamedPropertyLink(sink__V490->context, NAMED_PROPERTIES(term__V491));
      VariablePropertyLink varP__V525 = LINK_VariablePropertyLink(sink__V490->context, VARIABLE_PROPERTIES(term__V491));
      UNLINK(sink__V490->context, term__V491);
      ADD_PROPERTIES(sink__V490, LINK_NamedPropertyLink(sink__V490->context, namedP__V524), LINK_VariablePropertyLink(sink__V490->context, varP__V525));
      { START(sink__V490, _M_MapText1_s3);
        { if (!IS_BOUND(x__V520)) { REBIND(x__V520);
            Variable binds__V526[1] = {x__V520}; BINDS(sink__V490, 1, binds__V526);
            COPY(sink__V490, sub__V521); /* REUSED SUBSTITUTION */  }
          else { Variable b__V527 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V490->context,"b__V527");
            Variable binds__V528[1] = {b__V527}; BINDS(sink__V490, 1, binds__V528);
            {
              Term arg__V529;
              { Sink buf__V530 = ALLOCA_BUFFER(sink__V490->context);
                USE(buf__V530, b__V527); arg__V529 = BUFFER_TERM(buf__V530); FREE_BUFFER(buf__V530); }
              Variable vars__V531[1] = {x__V520};
              Term args__V532[1] = {arg__V529};
              struct _SubstitutionFrame substitution__V533 = {NULL, 0, 1, vars__V531, args__V532, NULL};
              SUBSTITUTE(sink__V490, sub__V521, &substitution__V533); }
                }
           }
        { if (!IS_BOUND(x__V522)) { REBIND(x__V522);
            Variable binds__V534[1] = {x__V522}; BINDS(sink__V490, 1, binds__V534);
            COPY(sink__V490, sub__V523); /* REUSED SUBSTITUTION */  }
          else { Variable b__V535 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V490->context,"b__V535");
            Variable binds__V536[1] = {b__V535}; BINDS(sink__V490, 1, binds__V536);
            {
              Term arg__V537;
              { Sink buf__V538 = ALLOCA_BUFFER(sink__V490->context);
                USE(buf__V538, b__V535); arg__V537 = BUFFER_TERM(buf__V538); FREE_BUFFER(buf__V538); }
              Variable vars__V539[1] = {x__V522};
              Term args__V540[1] = {arg__V537};
              struct _SubstitutionFrame substitution__V541 = {NULL, 0, 1, vars__V539, args__V540, NULL};
              SUBSTITUTE(sink__V490, sub__V523, &substitution__V541); }
                }
           }
        END(sink__V490, _M_MapText1_s3); }
      UNLINK_NamedPropertyLink(sink__V490->context, namedP__V524); UNLINK_VariablePropertyLink(sink__V490->context, varP__V525);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION MapText1$2. */
int conBindOffs_M_MapText1_s2[] = {0 , 0 , 0 , 1 , 2};
char *nameFun_M_MapText1_s2(Term term) { return  "MapText1$2" ; }
struct _ConstructionDescriptor descriptor_M_MapText1_s2 = {&sort_M_Reified_xVariable, 0, 4, sizeof(STRUCT_Con_M_MapText1_s2), conBindOffs_M_MapText1_s2, &nameFun_M_MapText1_s2, &step_M_MapText1_s2};

int step_M_MapText1_s2(Sink sink__V542, Term term__V543)
{
  int term__V543_count = LINK_COUNT(term__V543); permitUnusedInt(term__V543_count);
  do {
    /* Contraction rule DEFS-MapText1-1. */
    ASSERT(sink__V542->context, !strcmp(SYMBOL(term__V543),  "MapText1$2" ));
    Term sub__V544 = LINK(sink__V542->context, SUB(term__V543, 0)); int sub__V544_count = term__V543_count*LINK_COUNT(sub__V544); permitUnusedInt(sub__V544_count);
    /* sub__V544 = &#31 */
    Term sub__V545 = LINK(sink__V542->context, SUB(term__V543, 1)); int sub__V545_count = term__V543_count*LINK_COUNT(sub__V545); permitUnusedInt(sub__V545_count);
    /* sub__V545 = &#32 */
    Variable x__V546 = BINDER(term__V543,2,0); if (term__V543_count <= 1) UNBIND(x__V546);
    Term sub__V547 = LINK(sink__V542->context, SUB(term__V543, 2)); int sub__V547_count = term__V543_count*LINK_COUNT(sub__V547); permitUnusedInt(sub__V547_count);
    CRSX_CHECK_SORT(sink__V542->context, sub__V547, &sort_M_Reified_xVariable); /* sub__V547 = &#2 */
    Variable x__V548 = BINDER(term__V543,3,0); if (term__V543_count <= 1) UNBIND(x__V548);
    Term sub__V549 = LINK(sink__V542->context, SUB(term__V543, 3)); int sub__V549_count = term__V543_count*LINK_COUNT(sub__V549); permitUnusedInt(sub__V549_count);
    CRSX_CHECK_SORT(sink__V542->context, sub__V549, &sort_M_Reified_xVariable); /* sub__V549 = &#1 */
    NamedPropertyLink namedP__V550 = LINK_NamedPropertyLink(sink__V542->context, NAMED_PROPERTIES(term__V543));
    VariablePropertyLink varP__V551 = LINK_VariablePropertyLink(sink__V542->context, VARIABLE_PROPERTIES(term__V543));
    UNLINK(sink__V542->context, term__V543);
    { START(sink__V542, _M__sTextCons);
      { START(sink__V542, _M__sTextEmbed);
        { START(sink__V542, _M_AsText);
          {
            Term arg__V552;
            { Sink buf__V553 = ALLOCA_BUFFER(sink__V542->context);
              COPY(buf__V553, sub__V544);arg__V552 = BUFFER_TERM(buf__V553); FREE_BUFFER(buf__V553); }
            Variable vars__V554[1] = {x__V548};
            Term args__V555[1] = {arg__V552};
            struct _SubstitutionFrame substitution__V556 = {NULL, 0, 1, vars__V554, args__V555, NULL};
            SUBSTITUTE(sink__V542, sub__V549, &substitution__V556); }
          END(sink__V542, _M_AsText); }
        END(sink__V542, _M__sTextEmbed); }
      { START(sink__V542, _M__sTextCons);
        { START(sink__V542, _M__sTextEmbed);
          { START(sink__V542, _M_AsText);
            { START(sink__V542, _M_MapText_s1);
              COPY(sink__V542, sub__V545);{ if (!IS_BOUND(x__V546)) { REBIND(x__V546);
                  Variable binds__V557[1] = {x__V546}; BINDS(sink__V542, 1, binds__V557);
                  COPY(sink__V542, sub__V547); /* REUSED SUBSTITUTION */  }
                else { Variable b__V558 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V542->context,"b__V558");
                  Variable binds__V559[1] = {b__V558}; BINDS(sink__V542, 1, binds__V559);
                  {
                    Term arg__V560;
                    { Sink buf__V561 = ALLOCA_BUFFER(sink__V542->context);
                      USE(buf__V561, b__V558); arg__V560 = BUFFER_TERM(buf__V561); FREE_BUFFER(buf__V561); }
                    Variable vars__V562[1] = {x__V546};
                    Term args__V563[1] = {arg__V560};
                    struct _SubstitutionFrame substitution__V564 = {NULL, 0, 1, vars__V562, args__V563, NULL};
                    SUBSTITUTE(sink__V542, sub__V547, &substitution__V564); }
                      }
                 }
              END(sink__V542, _M_MapText_s1); }
            END(sink__V542, _M_AsText); }
          END(sink__V542, _M__sTextEmbed); }
        { START(sink__V542, _M__sTextNil);
          END(sink__V542, _M__sTextNil); }
        END(sink__V542, _M__sTextCons); }
      END(sink__V542, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V542->context, namedP__V550); UNLINK_VariablePropertyLink(sink__V542->context, varP__V551);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION MapText1$3. */
int conBindOffs_M_MapText1_s3[] = {0 , 1 , 2};
char *nameFun_M_MapText1_s3(Term term) { return  "MapText1$3" ; }
struct _ConstructionDescriptor descriptor_M_MapText1_s3 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_MapText1_s3), conBindOffs_M_MapText1_s3, &nameFun_M_MapText1_s3, &step_M_MapText1_s3};

int step_M_MapText1_s3(Sink sink__V565, Term term__V566)
{
  int term__V566_count = LINK_COUNT(term__V566); permitUnusedInt(term__V566_count);
  do {
    /* Contraction rule DEFS-MapText1-2. */
    ASSERT(sink__V565->context, !strcmp(SYMBOL(term__V566),  "MapText1$3" ));
    Variable x__V567 = BINDER(term__V566,0,0); if (term__V566_count <= 1) UNBIND(x__V567);
    Term sub__V568 = SUB(term__V566, 0); permitUnusedTerm(sub__V568); int sub__V568_count = term__V566_count*LINK_COUNT(sub__V568); permitUnusedInt(sub__V568_count);
    CRSX_CHECK_SORT(sink__V565->context, sub__V568, &sort_M_Reified_xVariable); /* sub__V568 = &#2 */
    Variable x__V569 = BINDER(term__V566,1,0); if (term__V566_count <= 1) UNBIND(x__V569);
    Term sub__V570 = SUB(term__V566, 1); permitUnusedTerm(sub__V570); int sub__V570_count = term__V566_count*LINK_COUNT(sub__V570); permitUnusedInt(sub__V570_count);
    CRSX_CHECK_SORT(sink__V565->context, sub__V570, &sort_M_Reified_xVariable); /* sub__V570 = &#1 */
    NamedPropertyLink namedP__V571 = LINK_NamedPropertyLink(sink__V565->context, NAMED_PROPERTIES(term__V566));
    VariablePropertyLink varP__V572 = LINK_VariablePropertyLink(sink__V565->context, VARIABLE_PROPERTIES(term__V566));
    UNLINK(sink__V565->context, term__V566);
    { START(sink__V565, _M__sTextNil); END(sink__V565, _M__sTextNil); }
    UNLINK_NamedPropertyLink(sink__V565->context, namedP__V571); UNLINK_VariablePropertyLink(sink__V565->context, varP__V572);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION UnVariable$1. */
int conBindOffs_M_UnVariable_s1[] = {0 , 0};
char *nameFun_M_UnVariable_s1(Term term) { return  "UnVariable$1" ; }
struct _ConstructionDescriptor descriptor_M_UnVariable_s1 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_UnVariable_s1), conBindOffs_M_UnVariable_s1, &nameFun_M_UnVariable_s1, &step_M_UnVariable_s1};

int step_M_UnVariable_s1(Sink sink__V573, Term term__V574)
{
  int term__V574_count = LINK_COUNT(term__V574); permitUnusedInt(term__V574_count);
  do {
    /* Contraction rule DEFS-UnVariable-1. */
    ASSERT(sink__V573->context, !strcmp(SYMBOL(term__V574),  "UnVariable$1" ));
    Term sub__V575 = LINK(sink__V573->context, SUB(term__V574, 0)); int sub__V575_count = term__V574_count*LINK_COUNT(sub__V575); permitUnusedInt(sub__V575_count);
    CRSX_CHECK_SORT(sink__V573->context, sub__V575, &sort_M_Reified_xVariable); /* sub__V575 = &#11 */
    NamedPropertyLink namedP__V576 = LINK_NamedPropertyLink(sink__V573->context, NAMED_PROPERTIES(term__V574));
    VariablePropertyLink varP__V577 = LINK_VariablePropertyLink(sink__V573->context, VARIABLE_PROPERTIES(term__V574));
    UNLINK(sink__V573->context, term__V574);
    COPY(sink__V573, sub__V575);UNLINK_NamedPropertyLink(sink__V573->context, namedP__V576); UNLINK_VariablePropertyLink(sink__V573->context, varP__V577);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DTOKEN. */
int conBindOffs_M_DTOKEN[] = {0 , 0 , 0};
char *nameFun_M_DTOKEN(Term term) { return  "DTOKEN" ; }
struct _ConstructionDescriptor descriptor_M_DTOKEN = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_DTOKEN), conBindOffs_M_DTOKEN, &nameFun_M_DTOKEN, &step_M_DTOKEN};

int step_M_DTOKEN(Sink sink__V578, Term term__V579)
{
  int term__V579_count = LINK_COUNT(term__V579); permitUnusedInt(term__V579_count);
  Term sub__V580 = FORCE(sink__V578->context, SUB(term__V579, 0));
  EnumOf_M_OK_xSORT choice__V581 = (IS_VARIABLE_USE(sub__V580) ? VarOf_M_OK_xSORT : (EnumOf_M_OK_xSORT) TAG(sub__V580));
  switch (choice__V581)
  {
    case Data_M_OK: { /* Function DEFS-DTOKEN-1$DTOKEN$OK case OK */
      ASSERT(sink__V578->context, !strcmp(SYMBOL(term__V579),  "DTOKEN" ));
      Term sub__V582 = SUB(term__V579, 0); permitUnusedTerm(sub__V582); int sub__V582_count = term__V579_count*LINK_COUNT(sub__V582); permitUnusedInt(sub__V582_count);
      CRSX_CHECK_SORT(sink__V578->context, sub__V582, &sort_M_OK_xSORT); ASSERT(sink__V578->context, !strcmp(SYMBOL(sub__V582),  "OK" ));
      Term sub__V583 = LINK(sink__V578->context, SUB(term__V579, 1)); int sub__V583_count = term__V579_count*LINK_COUNT(sub__V583); permitUnusedInt(sub__V583_count);
      /* sub__V583 = &#0 */
      NamedPropertyLink namedP__V584 = LINK_NamedPropertyLink(sink__V578->context, NAMED_PROPERTIES(term__V579));
      VariablePropertyLink varP__V585 = LINK_VariablePropertyLink(sink__V578->context, VARIABLE_PROPERTIES(term__V579));
      UNLINK(sink__V578->context, term__V579);
      ADD_PROPERTIES(sink__V578, LINK_NamedPropertyLink(sink__V578->context, namedP__V584), LINK_VariablePropertyLink(sink__V578->context, varP__V585));
      { START(sink__V578, _M_DTOKEN_s1);
        COPY(sink__V578, sub__V583);END(sink__V578, _M_DTOKEN_s1); }
      UNLINK_NamedPropertyLink(sink__V578->context, namedP__V584); UNLINK_VariablePropertyLink(sink__V578->context, varP__V585);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION EnumFun. */
int conBindOffs_M_EnumFun[] = {0 , 0};
char *nameFun_M_EnumFun(Term term) { return  "EnumFun" ; }
struct _ConstructionDescriptor descriptor_M_EnumFun = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_EnumFun), conBindOffs_M_EnumFun, &nameFun_M_EnumFun, &step_M_EnumFun};

int step_M_EnumFun(Sink sink__V586, Term term__V587)
{
  int term__V587_count = LINK_COUNT(term__V587); permitUnusedInt(term__V587_count);
  do {
    /* Contraction rule DEFS-EnumFun-1. */
    ASSERT(sink__V586->context, !strcmp(SYMBOL(term__V587),  "EnumFun" ));
    Term sub__V588 = LINK(sink__V586->context, SUB(term__V587, 0)); int sub__V588_count = term__V587_count*LINK_COUNT(sub__V588); permitUnusedInt(sub__V588_count);
    /* sub__V588 = &#1 */
    NamedPropertyLink namedP__V589 = LINK_NamedPropertyLink(sink__V586->context, NAMED_PROPERTIES(term__V587));
    VariablePropertyLink varP__V590 = LINK_VariablePropertyLink(sink__V586->context, VARIABLE_PROPERTIES(term__V587));
    UNLINK(sink__V586->context, term__V587);
    { START(sink__V586, _M__sTextCons);
      { START(sink__V586, _M__sTextChars);
        LITERAL(sink__V586,  "FunOf" ); END(sink__V586, _M__sTextChars); }
      { START(sink__V586, _M__sTextCons);
        { START(sink__V586, _M__sTextEmbed);
          { START(sink__V586, _M_AsText);
            { START(sink__V586, _M_MANGLE);
              COPY(sink__V586, sub__V588);END(sink__V586, _M_MANGLE); }
            END(sink__V586, _M_AsText); }
          END(sink__V586, _M__sTextEmbed); }
        { START(sink__V586, _M__sTextNil);
          END(sink__V586, _M__sTextNil); }
        END(sink__V586, _M__sTextCons); }
      END(sink__V586, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V586->context, namedP__V589); UNLINK_VariablePropertyLink(sink__V586->context, varP__V590);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Primitive. */
int conBindOffs_M_Primitive[] = {0 , 0};
char *nameFun_M_Primitive(Term term) { return  "Primitive" ; }
struct _ConstructionDescriptor descriptor_M_Primitive = {&sort_M_SPrimitive, 0, 1, sizeof(STRUCT_Con_M_Primitive), conBindOffs_M_Primitive, &nameFun_M_Primitive, &step_M_Primitive};

int step_M_Primitive(Sink sink__V591, Term term__V592)
{
  int term__V592_count = LINK_COUNT(term__V592); permitUnusedInt(term__V592_count);
  do {
    /* Contraction rule DEFS-Primitive-1. */
    ASSERT(sink__V591->context, !strcmp(SYMBOL(term__V592),  "Primitive" ));
    Term sub__V593 = LINK(sink__V591->context, SUB(term__V592, 0)); int sub__V593_count = term__V592_count*LINK_COUNT(sub__V593); permitUnusedInt(sub__V593_count);
    /* sub__V593 = &#1 */
    UNLINK(sink__V591->context, term__V592);
    { int test__V594;
      FORCE(sink__V591->context, sub__V593);
      test__V594 = (int) !strcmp(SYMBOL(sub__V593), "C" ); if (test__V594) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xC); END(sink__V591, _M_E_xC); }  }
      else { { int test__V595;
          FORCE(sink__V591->context, sub__V593);
          test__V595 = (int) !strcmp(SYMBOL(sub__V593), "NumericEqual" );
          if (test__V595) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xNumericEqual);
              END(sink__V591, _M_E_xNumericEqual); }
             }
          else { { int test__V596;
              FORCE(sink__V591->context, sub__V593);
              test__V596 = (int) !strcmp(SYMBOL(sub__V593), "StringLessThan" );
              if (test__V596) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xStringLessThan);
                  END(sink__V591, _M_E_xStringLessThan); }
                 }
              else { { int test__V597;
                  FORCE(sink__V591->context, sub__V593);
                  test__V597 = (int) !strcmp(SYMBOL(sub__V593), "LessThan" );
                  if (test__V597) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xLessThan);
                      END(sink__V591, _M_E_xLessThan); }
                     }
                  else { { int test__V598;
                      FORCE(sink__V591->context, sub__V593);
                      test__V598 = (int) !strcmp(SYMBOL(sub__V593), "GreaterThan" );
                      if (test__V598) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xGreaterThan);
                          END(sink__V591, _M_E_xGreaterThan); }
                         }
                      else { { int test__V599;
                          FORCE(sink__V591->context, sub__V593);
                          test__V599 = (int) !strcmp(SYMBOL(sub__V593), "LessThanOrEqual" );
                          if (test__V599) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xLessThanOrEqual);
                              END(sink__V591, _M_E_xLessThanOrEqual); }
                             }
                          else { { int test__V600;
                              FORCE(sink__V591->context, sub__V593);
                              test__V600 = (int) !strcmp(SYMBOL(sub__V593), "GreaterThanOrEqual" );
                              if (test__V600) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xGreaterThanOrEqual);
                                  END(sink__V591, _M_E_xGreaterThanOrEqual); }
                                 }
                              else { { int test__V601;
                                  FORCE(sink__V591->context, sub__V593);
                                  test__V601 = (int) !strcmp(SYMBOL(sub__V593), "NotEqual" );
                                  if (test__V601) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xNotEqual);
                                      END(sink__V591, _M_E_xNotEqual); }
                                     }
                                  else { { int test__V602;
                                      FORCE(sink__V591->context, sub__V593);
                                      test__V602 = (int) !strcmp(SYMBOL(sub__V593), ":" );
                                      if (test__V602) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xConcat);
                                          END(sink__V591, _M_E_xConcat); }
                                         }
                                      else { { int test__V603;
                                          FORCE(sink__V591->context, sub__V593);
                                          test__V603 = (int) !strcmp(SYMBOL(sub__V593), "SameVariable" );
                                          if (test__V603) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xSameVariable);
                                              END(sink__V591, _M_E_xSameVariable); }
                                             }
                                          else { { int test__V604;
                                              FORCE(sink__V591->context, sub__V593);
                                              test__V604 = (int) !strcmp(SYMBOL(sub__V593), "LesserVariable" );
                                              if (test__V604) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xLesserVariable);
                                                  END(sink__V591, _M_E_xLesserVariable); }
                                                 }
                                              else { { int test__V605;
                                                  FORCE(sink__V591->context, sub__V593);
                                                  test__V605 = (int) !strcmp(SYMBOL(sub__V593), "Equal" );
                                                  if (test__V605) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xEqual);
                                                      END(sink__V591, _M_E_xEqual); }
                                                     }
                                                  else { { int test__V606;
                                                      FORCE(sink__V591->context, sub__V593);
                                                      test__V606 = (int) !strcmp(SYMBOL(sub__V593), "Contains" );
                                                      if (test__V606) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xContains);
                                                          END(sink__V591, _M_E_xContains); }
                                                         }
                                                      else { { int test__V607;
                                                          FORCE(sink__V591->context, sub__V593);
                                                          test__V607 = (int) !strcmp(SYMBOL(sub__V593), "StartsWith" );
                                                          if (test__V607) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xStartsWith);
                                                              END(sink__V591, _M_E_xStartsWith); }
                                                             }
                                                          else { { int test__V608;
                                                              FORCE(sink__V591->context, sub__V593);
                                                              test__V608 = (int) !strcmp(SYMBOL(sub__V593), "EndsWith" );
                                                              if (test__V608) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xEndsWith);
                                                                  END(sink__V591, _M_E_xEndsWith); }
                                                                 }
                                                              else { { int test__V609;
                                                                  FORCE(sink__V591->context, sub__V593);
                                                                  test__V609 = (int) !strcmp(SYMBOL(sub__V593), "Split" );
                                                                  if (test__V609) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xSplit);
                                                                      END(sink__V591, _M_E_xSplit); }
                                                                     }
                                                                  else { { int test__V610;
                                                                      FORCE(sink__V591->context, sub__V593);
                                                                      test__V610 = (int) !strcmp(SYMBOL(sub__V593), "MatchRegex" );
                                                                      if (test__V610) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xMatchRegex);
                                                                          END(sink__V591, _M_E_xMatchRegex); }
                                                                         }
                                                                      else { { int test__V611;
                                                                          FORCE(sink__V591->context, sub__V593);
                                                                          test__V611 = (int) !strcmp(SYMBOL(sub__V593), "Length" );
                                                                          if (test__V611) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xLength);
                                                                              END(sink__V591, _M_E_xLength); }
                                                                             }
                                                                          else { { int test__V612;
                                                                              FORCE(sink__V591->context, sub__V593);
                                                                              test__V612 = (int) !strcmp(SYMBOL(sub__V593), "Substring" );
                                                                              if (test__V612) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xSubstring);
                                                                                  END(sink__V591, _M_E_xSubstring); }
                                                                                 }
                                                                              else { { int test__V613;
                                                                                  FORCE(sink__V591->context, sub__V593);
                                                                                  test__V613 = (int) !strcmp(SYMBOL(sub__V593), "Escape" );
                                                                                  if (test__V613) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xEscape);
                                                                                      END(sink__V591, _M_E_xEscape); }
                                                                                     }
                                                                                  else { { int test__V614;
                                                                                      FORCE(sink__V591->context, sub__V593);
                                                                                      test__V614 = (int) !strcmp(SYMBOL(sub__V593), "Mangle" );
                                                                                      if (test__V614) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xMangle);
                                                                                          END(sink__V591, _M_E_xMangle); }
                                                                                         }
                                                                                      else { { int test__V615;
                                                                                          FORCE(sink__V591->context, sub__V593);
                                                                                          test__V615 = (int) !strcmp(SYMBOL(sub__V593), "BeforeFirst" );
                                                                                          if (test__V615) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xBeforeFirst);
                                                                                              END(sink__V591, _M_E_xBeforeFirst); }
                                                                                             }
                                                                                          else { { int test__V616;
                                                                                              FORCE(sink__V591->context, sub__V593);
                                                                                              test__V616 = (int) !strcmp(SYMBOL(sub__V593), "AfterFirst" );
                                                                                              if (test__V616) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xAfterFirst);
                                                                                                  END(sink__V591, _M_E_xAfterFirst); }
                                                                                                 }
                                                                                              else { { int test__V617;
                                                                                                  FORCE(sink__V591->context, sub__V593);
                                                                                                  test__V617 = (int) !strcmp(SYMBOL(sub__V593), "FromFirst" );
                                                                                                  if (test__V617) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xFromFirst);
                                                                                                      END(sink__V591, _M_E_xFromFirst); }
                                                                                                     }
                                                                                                  else { { int test__V618;
                                                                                                      FORCE(sink__V591->context, sub__V593);
                                                                                                      test__V618 = (int) !strcmp(SYMBOL(sub__V593), "ToFirst" );
                                                                                                      if (test__V618) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xToFirst);
                                                                                                          END(sink__V591, _M_E_xToFirst); }
                                                                                                         }
                                                                                                      else { { int test__V619;
                                                                                                          FORCE(sink__V591->context, sub__V593);
                                                                                                          test__V619 = (int) !strcmp(SYMBOL(sub__V593), "FormatNumber" );
                                                                                                          if (test__V619) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xFormatNumber);
                                                                                                              END(sink__V591, _M_E_xFormatNumber); }
                                                                                                             }
                                                                                                          else { { int test__V620;
                                                                                                              FORCE(sink__V591->context, sub__V593);
                                                                                                              test__V620 = (int) !strcmp(SYMBOL(sub__V593), "Format" );
                                                                                                              if (test__V620) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xFormat);
                                                                                                                  END(sink__V591, _M_E_xFormat); }
                                                                                                                 }
                                                                                                              else { { int test__V621;
                                                                                                                  FORCE(sink__V591->context, sub__V593);
                                                                                                                  test__V621 = (int) !strcmp(SYMBOL(sub__V593), "Show" );
                                                                                                                  if (test__V621) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xShow);
                                                                                                                      END(sink__V591, _M_E_xShow); }
                                                                                                                     }
                                                                                                                  else { { int test__V622;
                                                                                                                      FORCE(sink__V591->context, sub__V593);
                                                                                                                      test__V622 = (int) !strcmp(SYMBOL(sub__V593), "PassLocationProperties" );
                                                                                                                      if (test__V622) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xPassLocationProperties);
                                                                                                                          END(sink__V591, _M_E_xPassLocationProperties); }
                                                                                                                         }
                                                                                                                      else { { int test__V623;
                                                                                                                          FORCE(sink__V591->context, sub__V593);
                                                                                                                          test__V623 = (int) !strcmp(SYMBOL(sub__V593), "Plus" );
                                                                                                                          if (test__V623) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xPlus);
                                                                                                                              END(sink__V591, _M_E_xPlus); }
                                                                                                                             }
                                                                                                                          else { { int test__V624;
                                                                                                                              FORCE(sink__V591->context, sub__V593);
                                                                                                                              test__V624 = (int) !strcmp(SYMBOL(sub__V593), "Minus" );
                                                                                                                              if (test__V624) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xMinus);
                                                                                                                                  END(sink__V591, _M_E_xMinus); }
                                                                                                                                 }
                                                                                                                              else { { int test__V625;
                                                                                                                                  FORCE(sink__V591->context, sub__V593);
                                                                                                                                  test__V625 = (int) !strcmp(SYMBOL(sub__V593), "Times" );
                                                                                                                                  if (test__V625) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xTimes);
                                                                                                                                      END(sink__V591, _M_E_xTimes); }
                                                                                                                                     }
                                                                                                                                  else { { int test__V626;
                                                                                                                                      FORCE(sink__V591->context, sub__V593);
                                                                                                                                      test__V626 = (int) !strcmp(SYMBOL(sub__V593), "Divide" );
                                                                                                                                      if (test__V626) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xDiv);
                                                                                                                                          END(sink__V591, _M_E_xDiv); }
                                                                                                                                         }
                                                                                                                                      else { { int test__V627;
                                                                                                                                          FORCE(sink__V591->context, sub__V593);
                                                                                                                                          test__V627 = (int) !strcmp(SYMBOL(sub__V593), "Modulo" );
                                                                                                                                          if (test__V627) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xMod);
                                                                                                                                              END(sink__V591, _M_E_xMod); }
                                                                                                                                             }
                                                                                                                                          else { { int test__V628;
                                                                                                                                              FORCE(sink__V591->context, sub__V593);
                                                                                                                                              test__V628 = (int) !strcmp(SYMBOL(sub__V593), "Absolute" );
                                                                                                                                              if (test__V628) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xAbsolute);
                                                                                                                                                  END(sink__V591, _M_E_xAbsolute); }
                                                                                                                                                 }
                                                                                                                                              else { { int test__V629;
                                                                                                                                                  FORCE(sink__V591->context, sub__V593);
                                                                                                                                                  test__V629 = (int) !strcmp(SYMBOL(sub__V593), "Decimal" );
                                                                                                                                                  if (test__V629) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xDecimal);
                                                                                                                                                      END(sink__V591, _M_E_xDecimal); }
                                                                                                                                                     }
                                                                                                                                                  else { { int test__V630;
                                                                                                                                                      FORCE(sink__V591->context, sub__V593);
                                                                                                                                                      test__V630 = (int) !strcmp(SYMBOL(sub__V593), "Hex" );
                                                                                                                                                      if (test__V630) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xHex);
                                                                                                                                                          END(sink__V591, _M_E_xHex); }
                                                                                                                                                         }
                                                                                                                                                      else { { int test__V631;
                                                                                                                                                          FORCE(sink__V591->context, sub__V593);
                                                                                                                                                          test__V631 = (int) !strcmp(SYMBOL(sub__V593), "BitAnd" );
                                                                                                                                                          if (test__V631) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xBitAnd);
                                                                                                                                                              END(sink__V591, _M_E_xBitAnd); }
                                                                                                                                                             }
                                                                                                                                                          else { { int test__V632;
                                                                                                                                                              FORCE(sink__V591->context, sub__V593);
                                                                                                                                                              test__V632 = (int) !strcmp(SYMBOL(sub__V593), "BitOr" );
                                                                                                                                                              if (test__V632) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xBitOr);
                                                                                                                                                                  END(sink__V591, _M_E_xBitOr); }
                                                                                                                                                                 }
                                                                                                                                                              else { { int test__V633;
                                                                                                                                                                  FORCE(sink__V591->context, sub__V593);
                                                                                                                                                                  test__V633 = (int) !strcmp(SYMBOL(sub__V593), "BitXor" );
                                                                                                                                                                  if (test__V633) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xBitXOr);
                                                                                                                                                                      END(sink__V591, _M_E_xBitXOr); }
                                                                                                                                                                     }
                                                                                                                                                                  else { { int test__V634;
                                                                                                                                                                      FORCE(sink__V591->context, sub__V593);
                                                                                                                                                                      test__V634 = (int) !strcmp(SYMBOL(sub__V593), "BitNot" );
                                                                                                                                                                      if (test__V634) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xBitNot);
                                                                                                                                                                          END(sink__V591, _M_E_xBitNot); }
                                                                                                                                                                         }
                                                                                                                                                                      else { { int test__V635;
                                                                                                                                                                          FORCE(sink__V591->context, sub__V593);
                                                                                                                                                                          test__V635 = (int) !strcmp(SYMBOL(sub__V593), "BitMinus" );
                                                                                                                                                                          if (test__V635) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xBitMinus);
                                                                                                                                                                              END(sink__V591, _M_E_xBitMinus); }
                                                                                                                                                                             }
                                                                                                                                                                          else { { int test__V636;
                                                                                                                                                                              FORCE(sink__V591->context, sub__V593);
                                                                                                                                                                              test__V636 = (int) !strcmp(SYMBOL(sub__V593), "BitSubSetEq" );
                                                                                                                                                                              if (test__V636) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xBitSubSetEq);
                                                                                                                                                                                  END(sink__V591, _M_E_xBitSubSetEq); }
                                                                                                                                                                                 }
                                                                                                                                                                              else { { int test__V637;
                                                                                                                                                                                  FORCE(sink__V591->context, sub__V593);
                                                                                                                                                                                  test__V637 = (int) !strcmp(SYMBOL(sub__V593), "Get" );
                                                                                                                                                                                  if (test__V637) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xGet);
                                                                                                                                                                                      END(sink__V591, _M_E_xGet); }
                                                                                                                                                                                     }
                                                                                                                                                                                  else { { int test__V638;
                                                                                                                                                                                      FORCE(sink__V591->context, sub__V593);
                                                                                                                                                                                      test__V638 = (int) !strcmp(SYMBOL(sub__V593), "GetRef" );
                                                                                                                                                                                      if (test__V638) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xGetRef);
                                                                                                                                                                                          END(sink__V591, _M_E_xGetRef); }
                                                                                                                                                                                         }
                                                                                                                                                                                      else { { int test__V639;
                                                                                                                                                                                          FORCE(sink__V591->context, sub__V593);
                                                                                                                                                                                          test__V639 = (int) !strcmp(SYMBOL(sub__V593), "IfDef" );
                                                                                                                                                                                          if (test__V639) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xIfDef);
                                                                                                                                                                                              END(sink__V591, _M_E_xIfDef); }
                                                                                                                                                                                             }
                                                                                                                                                                                          else { { int test__V640;
                                                                                                                                                                                              FORCE(sink__V591->context, sub__V593);
                                                                                                                                                                                              test__V640 = (int) !strcmp(SYMBOL(sub__V593), "Error" );
                                                                                                                                                                                              if (test__V640) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xError);
                                                                                                                                                                                                  END(sink__V591, _M_E_xError); }
                                                                                                                                                                                                 }
                                                                                                                                                                                              else { { int test__V641;
                                                                                                                                                                                                  FORCE(sink__V591->context, sub__V593);
                                                                                                                                                                                                  test__V641 = (int) !strcmp(SYMBOL(sub__V593), "ForgivableError" );
                                                                                                                                                                                                  if (test__V641) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xForgivableError);
                                                                                                                                                                                                      END(sink__V591, _M_E_xForgivableError); }
                                                                                                                                                                                                     }
                                                                                                                                                                                                  else { { int test__V642;
                                                                                                                                                                                                      FORCE(sink__V591->context, sub__V593);
                                                                                                                                                                                                      test__V642 = (int) !strcmp(SYMBOL(sub__V593), "Trace" );
                                                                                                                                                                                                      if (test__V642) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xTrace);
                                                                                                                                                                                                          END(sink__V591, _M_E_xTrace); }
                                                                                                                                                                                                         }
                                                                                                                                                                                                      else { { int test__V643;
                                                                                                                                                                                                          FORCE(sink__V591->context, sub__V593);
                                                                                                                                                                                                          test__V643 = (int) !strcmp(SYMBOL(sub__V593), "LoadTerm" );
                                                                                                                                                                                                          if (test__V643) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xLoadTerm);
                                                                                                                                                                                                              END(sink__V591, _M_E_xLoadTerm); }
                                                                                                                                                                                                             }
                                                                                                                                                                                                          else { { int test__V644;
                                                                                                                                                                                                              FORCE(sink__V591->context, sub__V593);
                                                                                                                                                                                                              test__V644 = (int) !strcmp(SYMBOL(sub__V593), "SaveTerm" );
                                                                                                                                                                                                              if (test__V644) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xSaveTerm);
                                                                                                                                                                                                                  END(sink__V591, _M_E_xSaveTerm); }
                                                                                                                                                                                                                 }
                                                                                                                                                                                                              else { { int test__V645;
                                                                                                                                                                                                                  FORCE(sink__V591->context, sub__V593);
                                                                                                                                                                                                                  test__V645 = (int) !strcmp(SYMBOL(sub__V593), "If" );
                                                                                                                                                                                                                  if (test__V645) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xIf);
                                                                                                                                                                                                                      END(sink__V591, _M_E_xIf); }
                                                                                                                                                                                                                     }
                                                                                                                                                                                                                  else { { int test__V646;
                                                                                                                                                                                                                      FORCE(sink__V591->context, sub__V593);
                                                                                                                                                                                                                      test__V646 = (int) !strcmp(SYMBOL(sub__V593), "IfZero" );
                                                                                                                                                                                                                      if (test__V646) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xIfZero);
                                                                                                                                                                                                                          END(sink__V591, _M_E_xIfZero); }
                                                                                                                                                                                                                         }
                                                                                                                                                                                                                      else { { int test__V647;
                                                                                                                                                                                                                          FORCE(sink__V591->context, sub__V593);
                                                                                                                                                                                                                          test__V647 = (int) !strcmp(SYMBOL(sub__V593), "IfEmpty" );
                                                                                                                                                                                                                          if (test__V647) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xIfEmpty);
                                                                                                                                                                                                                              END(sink__V591, _M_E_xIfEmpty); }
                                                                                                                                                                                                                             }
                                                                                                                                                                                                                          else { { int test__V648;
                                                                                                                                                                                                                              FORCE(sink__V591->context, sub__V593);
                                                                                                                                                                                                                              test__V648 = (int) !strcmp(SYMBOL(sub__V593), "FreeVariables" );
                                                                                                                                                                                                                              if (test__V648) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xFreeVariables);
                                                                                                                                                                                                                                  END(sink__V591, _M_E_xFreeVariables); }
                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                              else { { int test__V649;
                                                                                                                                                                                                                                  FORCE(sink__V591->context, sub__V593);
                                                                                                                                                                                                                                  test__V649 = (int) !strcmp(SYMBOL(sub__V593), "IntersectVariables" );
                                                                                                                                                                                                                                  if (test__V649) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xIntersectVariables);
                                                                                                                                                                                                                                      END(sink__V591, _M_E_xIntersectVariables); }
                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                  else { { int test__V650;
                                                                                                                                                                                                                                      FORCE(sink__V591->context, sub__V593);
                                                                                                                                                                                                                                      test__V650 = (int) !strcmp(SYMBOL(sub__V593), "UnionVariables" );
                                                                                                                                                                                                                                      if (test__V650) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xUnionVariables);
                                                                                                                                                                                                                                          END(sink__V591, _M_E_xUnionVariables); }
                                                                                                                                                                                                                                         }
                                                                                                                                                                                                                                      else { { int test__V651;
                                                                                                                                                                                                                                          FORCE(sink__V591->context, sub__V593);
                                                                                                                                                                                                                                          test__V651 = (int) !strcmp(SYMBOL(sub__V593), "ExceptVariables" );
                                                                                                                                                                                                                                          if (test__V651) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xExceptVariables);
                                                                                                                                                                                                                                              END(sink__V591, _M_E_xExceptVariables); }
                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                          else { { int test__V652;
                                                                                                                                                                                                                                              FORCE(sink__V591->context, sub__V593);
                                                                                                                                                                                                                                              test__V652 = (int) !strcmp(SYMBOL(sub__V593), "VariableNameIs" );
                                                                                                                                                                                                                                              if (test__V652) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xVariableNameIs);
                                                                                                                                                                                                                                                  END(sink__V591, _M_E_xVariableNameIs); }
                                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                                              else { { int test__V653;
                                                                                                                                                                                                                                                  FORCE(sink__V591->context, sub__V593);
                                                                                                                                                                                                                                                  test__V653 = (int) !strcmp(SYMBOL(sub__V593), "Match" );
                                                                                                                                                                                                                                                  if (test__V653) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xMatch);
                                                                                                                                                                                                                                                      END(sink__V591, _M_E_xMatch); }
                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                  else { { int test__V654;
                                                                                                                                                                                                                                                      FORCE(sink__V591->context, sub__V593);
                                                                                                                                                                                                                                                      test__V654 = (int) !strcmp(SYMBOL(sub__V593), "TryCall" );
                                                                                                                                                                                                                                                      if (test__V654) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xTryCall);
                                                                                                                                                                                                                                                          END(sink__V591, _M_E_xTryCall); }
                                                                                                                                                                                                                                                         }
                                                                                                                                                                                                                                                      else { { int test__V655;
                                                                                                                                                                                                                                                          FORCE(sink__V591->context, sub__V593);
                                                                                                                                                                                                                                                          test__V655 = (int) !strcmp(SYMBOL(sub__V593), "Call" );
                                                                                                                                                                                                                                                          if (test__V655) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xCall);
                                                                                                                                                                                                                                                              END(sink__V591, _M_E_xCall); }
                                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                                          else { { int test__V656;
                                                                                                                                                                                                                                                              FORCE(sink__V591->context, sub__V593);
                                                                                                                                                                                                                                                              test__V656 = (int) !strcmp(SYMBOL(sub__V593), "Cast" );
                                                                                                                                                                                                                                                              if (test__V656) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xCast);
                                                                                                                                                                                                                                                                  END(sink__V591, _M_E_xCast); }
                                                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                                                              else { { int test__V657;
                                                                                                                                                                                                                                                                  FORCE(sink__V591->context, sub__V593);
                                                                                                                                                                                                                                                                  test__V657 = (int) !strcmp(SYMBOL(sub__V593), "Null" );
                                                                                                                                                                                                                                                                  if (test__V657) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xNull);
                                                                                                                                                                                                                                                                      END(sink__V591, _M_E_xNull); }
                                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                                  else { { int test__V658;
                                                                                                                                                                                                                                                                      FORCE(sink__V591->context, sub__V593);
                                                                                                                                                                                                                                                                      test__V658 = (int) !strcmp(SYMBOL(sub__V593), "Nil" );
                                                                                                                                                                                                                                                                      if (test__V658) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xNil);
                                                                                                                                                                                                                                                                          END(sink__V591, _M_E_xNil); }
                                                                                                                                                                                                                                                                         }
                                                                                                                                                                                                                                                                      else { { int test__V659;
                                                                                                                                                                                                                                                                          FORCE(sink__V591->context, sub__V593);
                                                                                                                                                                                                                                                                          test__V659 = (int) !strcmp(SYMBOL(sub__V593), "UpCase" );
                                                                                                                                                                                                                                                                          if (test__V659) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xUpCase);
                                                                                                                                                                                                                                                                              END(sink__V591, _M_E_xUpCase); }
                                                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                                                          else { { int test__V660;
                                                                                                                                                                                                                                                                              FORCE(sink__V591->context, sub__V593);
                                                                                                                                                                                                                                                                              test__V660 = (int) !strcmp(SYMBOL(sub__V593), "DownCase" );
                                                                                                                                                                                                                                                                              if (test__V660) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xDownCase);
                                                                                                                                                                                                                                                                                  END(sink__V591, _M_E_xDownCase); }
                                                                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                                                                              else { { int test__V661;
                                                                                                                                                                                                                                                                                  FORCE(sink__V591->context, sub__V593);
                                                                                                                                                                                                                                                                                  test__V661 = (int) !strcmp(SYMBOL(sub__V593), "Replace" );
                                                                                                                                                                                                                                                                                  if (test__V661) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xReplace);
                                                                                                                                                                                                                                                                                      END(sink__V591, _M_E_xReplace); }
                                                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                                                  else { { int test__V662;
                                                                                                                                                                                                                                                                                      FORCE(sink__V591->context, sub__V593);
                                                                                                                                                                                                                                                                                      test__V662 = (int) !strcmp(SYMBOL(sub__V593), "Trim" );
                                                                                                                                                                                                                                                                                      if (test__V662) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xTrim);
                                                                                                                                                                                                                                                                                          END(sink__V591, _M_E_xTrim); }
                                                                                                                                                                                                                                                                                         }
                                                                                                                                                                                                                                                                                      else { { int test__V663;
                                                                                                                                                                                                                                                                                          FORCE(sink__V591->context, sub__V593);
                                                                                                                                                                                                                                                                                          test__V663 = (int) !strcmp(SYMBOL(sub__V593), "Split" );
                                                                                                                                                                                                                                                                                          if (test__V663) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xSplit);
                                                                                                                                                                                                                                                                                              END(sink__V591, _M_E_xSplit); }
                                                                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                                                                          else { { int test__V664;
                                                                                                                                                                                                                                                                                              FORCE(sink__V591->context, sub__V593);
                                                                                                                                                                                                                                                                                              test__V664 = (int) !strcmp(SYMBOL(sub__V593), "Rescape" );
                                                                                                                                                                                                                                                                                              if (test__V664) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xRescape);
                                                                                                                                                                                                                                                                                                  END(sink__V591, _M_E_xRescape); }
                                                                                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                                                                                              else { { int test__V665;
                                                                                                                                                                                                                                                                                                  FORCE(sink__V591->context, sub__V593);
                                                                                                                                                                                                                                                                                                  test__V665 = (int) !strcmp(SYMBOL(sub__V593), "Keys" );
                                                                                                                                                                                                                                                                                                  if (test__V665) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xKeys);
                                                                                                                                                                                                                                                                                                      END(sink__V591, _M_E_xKeys); }
                                                                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                                                                  else { { int test__V666;
                                                                                                                                                                                                                                                                                                      FORCE(sink__V591->context, sub__V593);
                                                                                                                                                                                                                                                                                                      test__V666 = (int) !strcmp(SYMBOL(sub__V593), "ParseURL" );
                                                                                                                                                                                                                                                                                                      if (test__V666) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xParseURL);
                                                                                                                                                                                                                                                                                                          END(sink__V591, _M_E_xParseURL); }
                                                                                                                                                                                                                                                                                                         }
                                                                                                                                                                                                                                                                                                      else { { int test__V667;
                                                                                                                                                                                                                                                                                                          FORCE(sink__V591->context, sub__V593);
                                                                                                                                                                                                                                                                                                          test__V667 = (int) !strcmp(SYMBOL(sub__V593), "Echo" );
                                                                                                                                                                                                                                                                                                          if (test__V667) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xEcho);
                                                                                                                                                                                                                                                                                                              END(sink__V591, _M_E_xEcho); }
                                                                                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                                                                                          else { { int test__V668;
                                                                                                                                                                                                                                                                                                              FORCE(sink__V591->context, sub__V593);
                                                                                                                                                                                                                                                                                                              test__V668 = (int) !strcmp(SYMBOL(sub__V593), "DeepEqual" );
                                                                                                                                                                                                                                                                                                              if (test__V668) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xDeepEqual);
                                                                                                                                                                                                                                                                                                                  END(sink__V591, _M_E_xDeepEqual); }
                                                                                                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                                                                                                              else { { int test__V669;
                                                                                                                                                                                                                                                                                                                  FORCE(sink__V591->context, sub__V593);
                                                                                                                                                                                                                                                                                                                  test__V669 = (int) !strcmp(SYMBOL(sub__V593), "HashCode" );
                                                                                                                                                                                                                                                                                                                  if (test__V669) {  UNLINK(sink__V591->context, sub__V593); { START(sink__V591, _M_E_xHashCode);
                                                                                                                                                                                                                                                                                                                      END(sink__V591, _M_E_xHashCode); }
                                                                                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                                                                                  else { { START(sink__V591, _M_MissingPrimitive);
                                                                                                                                                                                                                                                                                                                      COPY(sink__V591, sub__V593);END(sink__V591, _M_MissingPrimitive); }
                                                                                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                                                         }
                                                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                                         }
                                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                         }
                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                         }
                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                         }
                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                 }
                                                                                                                                                                                                                            }
                                                                                                                                                                                                                             }
                                                                                                                                                                                                                        }
                                                                                                                                                                                                                         }
                                                                                                                                                                                                                    }
                                                                                                                                                                                                                     }
                                                                                                                                                                                                                }
                                                                                                                                                                                                                 }
                                                                                                                                                                                                            }
                                                                                                                                                                                                             }
                                                                                                                                                                                                        }
                                                                                                                                                                                                         }
                                                                                                                                                                                                    }
                                                                                                                                                                                                     }
                                                                                                                                                                                                }
                                                                                                                                                                                                 }
                                                                                                                                                                                            }
                                                                                                                                                                                             }
                                                                                                                                                                                        }
                                                                                                                                                                                         }
                                                                                                                                                                                    }
                                                                                                                                                                                     }
                                                                                                                                                                                }
                                                                                                                                                                                 }
                                                                                                                                                                            }
                                                                                                                                                                             }
                                                                                                                                                                        }
                                                                                                                                                                         }
                                                                                                                                                                    }
                                                                                                                                                                     }
                                                                                                                                                                }
                                                                                                                                                                 }
                                                                                                                                                            }
                                                                                                                                                             }
                                                                                                                                                        }
                                                                                                                                                         }
                                                                                                                                                    }
                                                                                                                                                     }
                                                                                                                                                }
                                                                                                                                                 }
                                                                                                                                            }
                                                                                                                                             }
                                                                                                                                        }
                                                                                                                                         }
                                                                                                                                    }
                                                                                                                                     }
                                                                                                                                }
                                                                                                                                 }
                                                                                                                            }
                                                                                                                             }
                                                                                                                        }
                                                                                                                         }
                                                                                                                    }
                                                                                                                     }
                                                                                                                }
                                                                                                                 }
                                                                                                            }
                                                                                                             }
                                                                                                        }
                                                                                                         }
                                                                                                    }
                                                                                                     }
                                                                                                }
                                                                                                 }
                                                                                            }
                                                                                             }
                                                                                        }
                                                                                         }
                                                                                    }
                                                                                     }
                                                                                }
                                                                                 }
                                                                            }
                                                                             }
                                                                        }
                                                                         }
                                                                    }
                                                                     }
                                                                }
                                                                 }
                                                            }
                                                             }
                                                        }
                                                         }
                                                    }
                                                     }
                                                }
                                                 }
                                            }
                                             }
                                        }
                                         }
                                    }
                                     }
                                }
                                 }
                            }
                             }
                        }
                         }
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

int step_M_BinderOffsets(Sink sink__V670, Term term__V671)
{
  int term__V671_count = LINK_COUNT(term__V671); permitUnusedInt(term__V671_count);
  do {
    /* Contraction rule DEFS-BinderOffsets-1. */
    ASSERT(sink__V670->context, !strcmp(SYMBOL(term__V671),  "BinderOffsets" ));
    Term sub__V672 = LINK(sink__V670->context, SUB(term__V671, 0)); int sub__V672_count = term__V671_count*LINK_COUNT(sub__V672); permitUnusedInt(sub__V672_count);
    /* sub__V672 = &#1 */
    NamedPropertyLink namedP__V673 = LINK_NamedPropertyLink(sink__V670->context, NAMED_PROPERTIES(term__V671));
    VariablePropertyLink varP__V674 = LINK_VariablePropertyLink(sink__V670->context, VARIABLE_PROPERTIES(term__V671));
    UNLINK(sink__V670->context, term__V671);
    { START(sink__V670, _M__sTextCons);
      { START(sink__V670, _M__sTextChars);
        LITERAL(sink__V670,  "conBindOffs" ); END(sink__V670, _M__sTextChars); }
      { START(sink__V670, _M__sTextCons);
        { START(sink__V670, _M__sTextEmbed);
          { START(sink__V670, _M_AsText);
            { START(sink__V670, _M_MANGLE);
              COPY(sink__V670, sub__V672);END(sink__V670, _M_MANGLE); }
            END(sink__V670, _M_AsText); }
          END(sink__V670, _M__sTextEmbed); }
        { START(sink__V670, _M__sTextNil);
          END(sink__V670, _M__sTextNil); }
        END(sink__V670, _M__sTextCons); }
      END(sink__V670, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V670->context, namedP__V673); UNLINK_VariablePropertyLink(sink__V670->context, varP__V674);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION SplitMapText$1. */
int conBindOffs_M_SplitMapText_s1[] = {0 , 0 , 1 , 1 , 1 , 1 , 2 , 3};
char *nameFun_M_SplitMapText_s1(Term term) { return  "SplitMapText$1" ; }
struct _ConstructionDescriptor descriptor_M_SplitMapText_s1 = {&sort_M_Reified_xVariable, 0, 7, sizeof(STRUCT_Con_M_SplitMapText_s1), conBindOffs_M_SplitMapText_s1, &nameFun_M_SplitMapText_s1, &step_M_SplitMapText_s1};

int step_M_SplitMapText_s1(Sink sink__V675, Term term__V676)
{
  int term__V676_count = LINK_COUNT(term__V676); permitUnusedInt(term__V676_count);
  Term sub__V677 = FORCE(sink__V675->context, SUB(term__V676, 0));
  EnumOf_M__sList choice__V678 = (IS_VARIABLE_USE(sub__V677) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V677));
  switch (choice__V678)
  {
    case Data_M__sCons: { /* Function DEFS-SplitMapText-1$SplitMapText$1$$Cons case $Cons */
      ASSERT(sink__V675->context, !strcmp(SYMBOL(term__V676),  "SplitMapText$1" ));
      Term sub__V679 = SUB(term__V676, 0); permitUnusedTerm(sub__V679); int sub__V679_count = term__V676_count*LINK_COUNT(sub__V679); permitUnusedInt(sub__V679_count);
      ASSERT(sink__V675->context, !strcmp(SYMBOL(sub__V679),  "$Cons" ));
      Term sub__V680 = LINK(sink__V675->context, SUB(sub__V679, 0)); int sub__V680_count = sub__V679_count*LINK_COUNT(sub__V680); permitUnusedInt(sub__V680_count);
      /* sub__V680 = &#0-0 */
      Term sub__V681 = LINK(sink__V675->context, SUB(sub__V679, 1)); int sub__V681_count = sub__V679_count*LINK_COUNT(sub__V681); permitUnusedInt(sub__V681_count);
      /* sub__V681 = &#0-1 */
      Variable x__V682 = BINDER(term__V676,1,0); if (term__V676_count <= 1) UNBIND(x__V682);
      Term sub__V683 = LINK(sink__V675->context, SUB(term__V676, 1)); int sub__V683_count = term__V676_count*LINK_COUNT(sub__V683); permitUnusedInt(sub__V683_count);
      CRSX_CHECK_SORT(sink__V675->context, sub__V683, &sort_M_Reified_xVariable); /* sub__V683 = &#2 */
      Term sub__V684 = LINK(sink__V675->context, SUB(term__V676, 2)); int sub__V684_count = term__V676_count*LINK_COUNT(sub__V684); permitUnusedInt(sub__V684_count);
      /* sub__V684 = &#3 */
      Term sub__V685 = LINK(sink__V675->context, SUB(term__V676, 3)); int sub__V685_count = term__V676_count*LINK_COUNT(sub__V685); permitUnusedInt(sub__V685_count);
      /* sub__V685 = &#4 */
      Term sub__V686 = LINK(sink__V675->context, SUB(term__V676, 4)); int sub__V686_count = term__V676_count*LINK_COUNT(sub__V686); permitUnusedInt(sub__V686_count);
      /* sub__V686 = &#5 */
      Variable x__V687 = BINDER(term__V676,5,0); if (term__V676_count <= 1) UNBIND(x__V687);
      Term sub__V688 = LINK(sink__V675->context, SUB(term__V676, 5)); int sub__V688_count = term__V676_count*LINK_COUNT(sub__V688); permitUnusedInt(sub__V688_count);
      CRSX_CHECK_SORT(sink__V675->context, sub__V688, &sort_M_Reified_xVariable); /* sub__V688 = &#6 */
      Variable x__V689 = BINDER(term__V676,6,0); if (term__V676_count <= 1) UNBIND(x__V689);
      Term sub__V690 = LINK(sink__V675->context, SUB(term__V676, 6)); int sub__V690_count = term__V676_count*LINK_COUNT(sub__V690); permitUnusedInt(sub__V690_count);
      CRSX_CHECK_SORT(sink__V675->context, sub__V690, &sort_M_Reified_xVariable); /* sub__V690 = &#7 */
      NamedPropertyLink namedP__V691 = LINK_NamedPropertyLink(sink__V675->context, NAMED_PROPERTIES(term__V676));
      VariablePropertyLink varP__V692 = LINK_VariablePropertyLink(sink__V675->context, VARIABLE_PROPERTIES(term__V676));
      UNLINK(sink__V675->context, term__V676);
      ADD_PROPERTIES(sink__V675, LINK_NamedPropertyLink(sink__V675->context, namedP__V691), LINK_VariablePropertyLink(sink__V675->context, varP__V692));
      { START(sink__V675, _M_SplitMapText_s2);
        COPY(sink__V675, sub__V680);COPY(sink__V675, sub__V681);{ if (!IS_BOUND(x__V682)) { REBIND(x__V682);
            Variable binds__V693[1] = {x__V682}; BINDS(sink__V675, 1, binds__V693);
            COPY(sink__V675, sub__V683); /* REUSED SUBSTITUTION */  }
          else { Variable b__V694 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V675->context,"b__V694");
            Variable binds__V695[1] = {b__V694}; BINDS(sink__V675, 1, binds__V695);
            {
              Term arg__V696;
              { Sink buf__V697 = ALLOCA_BUFFER(sink__V675->context);
                USE(buf__V697, b__V694); arg__V696 = BUFFER_TERM(buf__V697); FREE_BUFFER(buf__V697); }
              Variable vars__V698[1] = {x__V682};
              Term args__V699[1] = {arg__V696};
              struct _SubstitutionFrame substitution__V700 = {NULL, 0, 1, vars__V698, args__V699, NULL};
              SUBSTITUTE(sink__V675, sub__V683, &substitution__V700); }
                }
           }
        COPY(sink__V675, sub__V684);COPY(sink__V675, sub__V685);COPY(sink__V675, sub__V686);{ if (!IS_BOUND(x__V687)) { REBIND(x__V687);
            Variable binds__V701[1] = {x__V687}; BINDS(sink__V675, 1, binds__V701);
            COPY(sink__V675, sub__V688); /* REUSED SUBSTITUTION */  }
          else { Variable b__V702 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V675->context,"b__V702");
            Variable binds__V703[1] = {b__V702}; BINDS(sink__V675, 1, binds__V703);
            {
              Term arg__V704;
              { Sink buf__V705 = ALLOCA_BUFFER(sink__V675->context);
                USE(buf__V705, b__V702); arg__V704 = BUFFER_TERM(buf__V705); FREE_BUFFER(buf__V705); }
              Variable vars__V706[1] = {x__V687};
              Term args__V707[1] = {arg__V704};
              struct _SubstitutionFrame substitution__V708 = {NULL, 0, 1, vars__V706, args__V707, NULL};
              SUBSTITUTE(sink__V675, sub__V688, &substitution__V708); }
                }
           }
        { if (!IS_BOUND(x__V689)) { REBIND(x__V689);
            Variable binds__V709[1] = {x__V689}; BINDS(sink__V675, 1, binds__V709);
            COPY(sink__V675, sub__V690); /* REUSED SUBSTITUTION */  }
          else { Variable b__V710 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V675->context,"b__V710");
            Variable binds__V711[1] = {b__V710}; BINDS(sink__V675, 1, binds__V711);
            {
              Term arg__V712;
              { Sink buf__V713 = ALLOCA_BUFFER(sink__V675->context);
                USE(buf__V713, b__V710); arg__V712 = BUFFER_TERM(buf__V713); FREE_BUFFER(buf__V713); }
              Variable vars__V714[1] = {x__V689};
              Term args__V715[1] = {arg__V712};
              struct _SubstitutionFrame substitution__V716 = {NULL, 0, 1, vars__V714, args__V715, NULL};
              SUBSTITUTE(sink__V675, sub__V690, &substitution__V716); }
                }
           }
        END(sink__V675, _M_SplitMapText_s2); }
      UNLINK_NamedPropertyLink(sink__V675->context, namedP__V691); UNLINK_VariablePropertyLink(sink__V675->context, varP__V692);
      
      return 1;
    break; } case Data_M__sNil: { /* Function DEFS-SplitMapText-2$SplitMapText$1$$Nil case $Nil */
      ASSERT(sink__V675->context, !strcmp(SYMBOL(term__V676),  "SplitMapText$1" ));
      Term sub__V717 = SUB(term__V676, 0); permitUnusedTerm(sub__V717); int sub__V717_count = term__V676_count*LINK_COUNT(sub__V717); permitUnusedInt(sub__V717_count);
      ASSERT(sink__V675->context, !strcmp(SYMBOL(sub__V717),  "$Nil" ));
      Variable x__V718 = BINDER(term__V676,1,0); if (term__V676_count <= 1) UNBIND(x__V718);
      Term sub__V719 = LINK(sink__V675->context, SUB(term__V676, 1)); int sub__V719_count = term__V676_count*LINK_COUNT(sub__V719); permitUnusedInt(sub__V719_count);
      CRSX_CHECK_SORT(sink__V675->context, sub__V719, &sort_M_Reified_xVariable); /* sub__V719 = &#0 */
      Term sub__V720 = LINK(sink__V675->context, SUB(term__V676, 2)); int sub__V720_count = term__V676_count*LINK_COUNT(sub__V720); permitUnusedInt(sub__V720_count);
      /* sub__V720 = &#1 */
      Term sub__V721 = LINK(sink__V675->context, SUB(term__V676, 3)); int sub__V721_count = term__V676_count*LINK_COUNT(sub__V721); permitUnusedInt(sub__V721_count);
      /* sub__V721 = &#2 */
      Term sub__V722 = LINK(sink__V675->context, SUB(term__V676, 4)); int sub__V722_count = term__V676_count*LINK_COUNT(sub__V722); permitUnusedInt(sub__V722_count);
      /* sub__V722 = &#3 */
      Variable x__V723 = BINDER(term__V676,5,0); if (term__V676_count <= 1) UNBIND(x__V723);
      Term sub__V724 = LINK(sink__V675->context, SUB(term__V676, 5)); int sub__V724_count = term__V676_count*LINK_COUNT(sub__V724); permitUnusedInt(sub__V724_count);
      CRSX_CHECK_SORT(sink__V675->context, sub__V724, &sort_M_Reified_xVariable); /* sub__V724 = &#4 */
      Variable x__V725 = BINDER(term__V676,6,0); if (term__V676_count <= 1) UNBIND(x__V725);
      Term sub__V726 = LINK(sink__V675->context, SUB(term__V676, 6)); int sub__V726_count = term__V676_count*LINK_COUNT(sub__V726); permitUnusedInt(sub__V726_count);
      CRSX_CHECK_SORT(sink__V675->context, sub__V726, &sort_M_Reified_xVariable); /* sub__V726 = &#5 */
      NamedPropertyLink namedP__V727 = LINK_NamedPropertyLink(sink__V675->context, NAMED_PROPERTIES(term__V676));
      VariablePropertyLink varP__V728 = LINK_VariablePropertyLink(sink__V675->context, VARIABLE_PROPERTIES(term__V676));
      UNLINK(sink__V675->context, term__V676);
      ADD_PROPERTIES(sink__V675, LINK_NamedPropertyLink(sink__V675->context, namedP__V727), LINK_VariablePropertyLink(sink__V675->context, varP__V728));
      { START(sink__V675, _M_SplitMapText_s3);
        { if (!IS_BOUND(x__V718)) { REBIND(x__V718);
            Variable binds__V729[1] = {x__V718}; BINDS(sink__V675, 1, binds__V729);
            COPY(sink__V675, sub__V719); /* REUSED SUBSTITUTION */  }
          else { Variable b__V730 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V675->context,"b__V730");
            Variable binds__V731[1] = {b__V730}; BINDS(sink__V675, 1, binds__V731);
            {
              Term arg__V732;
              { Sink buf__V733 = ALLOCA_BUFFER(sink__V675->context);
                USE(buf__V733, b__V730); arg__V732 = BUFFER_TERM(buf__V733); FREE_BUFFER(buf__V733); }
              Variable vars__V734[1] = {x__V718};
              Term args__V735[1] = {arg__V732};
              struct _SubstitutionFrame substitution__V736 = {NULL, 0, 1, vars__V734, args__V735, NULL};
              SUBSTITUTE(sink__V675, sub__V719, &substitution__V736); }
                }
           }
        COPY(sink__V675, sub__V720);COPY(sink__V675, sub__V721);COPY(sink__V675, sub__V722);{ if (!IS_BOUND(x__V723)) { REBIND(x__V723);
            Variable binds__V737[1] = {x__V723}; BINDS(sink__V675, 1, binds__V737);
            COPY(sink__V675, sub__V724); /* REUSED SUBSTITUTION */  }
          else { Variable b__V738 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V675->context,"b__V738");
            Variable binds__V739[1] = {b__V738}; BINDS(sink__V675, 1, binds__V739);
            {
              Term arg__V740;
              { Sink buf__V741 = ALLOCA_BUFFER(sink__V675->context);
                USE(buf__V741, b__V738); arg__V740 = BUFFER_TERM(buf__V741); FREE_BUFFER(buf__V741); }
              Variable vars__V742[1] = {x__V723};
              Term args__V743[1] = {arg__V740};
              struct _SubstitutionFrame substitution__V744 = {NULL, 0, 1, vars__V742, args__V743, NULL};
              SUBSTITUTE(sink__V675, sub__V724, &substitution__V744); }
                }
           }
        { if (!IS_BOUND(x__V725)) { REBIND(x__V725);
            Variable binds__V745[1] = {x__V725}; BINDS(sink__V675, 1, binds__V745);
            COPY(sink__V675, sub__V726); /* REUSED SUBSTITUTION */  }
          else { Variable b__V746 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V675->context,"b__V746");
            Variable binds__V747[1] = {b__V746}; BINDS(sink__V675, 1, binds__V747);
            {
              Term arg__V748;
              { Sink buf__V749 = ALLOCA_BUFFER(sink__V675->context);
                USE(buf__V749, b__V746); arg__V748 = BUFFER_TERM(buf__V749); FREE_BUFFER(buf__V749); }
              Variable vars__V750[1] = {x__V725};
              Term args__V751[1] = {arg__V748};
              struct _SubstitutionFrame substitution__V752 = {NULL, 0, 1, vars__V750, args__V751, NULL};
              SUBSTITUTE(sink__V675, sub__V726, &substitution__V752); }
                }
           }
        END(sink__V675, _M_SplitMapText_s3); }
      UNLINK_NamedPropertyLink(sink__V675->context, namedP__V727); UNLINK_VariablePropertyLink(sink__V675->context, varP__V728);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION SplitMapText$2. */
int conBindOffs_M_SplitMapText_s2[] = {0 , 0 , 0 , 1 , 1 , 1 , 1 , 2 , 3};
char *nameFun_M_SplitMapText_s2(Term term) { return  "SplitMapText$2" ; }
struct _ConstructionDescriptor descriptor_M_SplitMapText_s2 = {&sort_M_Reified_xVariable, 0, 8, sizeof(STRUCT_Con_M_SplitMapText_s2), conBindOffs_M_SplitMapText_s2, &nameFun_M_SplitMapText_s2, &step_M_SplitMapText_s2};

int step_M_SplitMapText_s2(Sink sink__V753, Term term__V754)
{
  int term__V754_count = LINK_COUNT(term__V754); permitUnusedInt(term__V754_count);
  do {
    /* Contraction rule DEFS-SplitMapText-1. */
    ASSERT(sink__V753->context, !strcmp(SYMBOL(term__V754),  "SplitMapText$2" ));
    Term sub__V755 = LINK(sink__V753->context, SUB(term__V754, 0)); int sub__V755_count = term__V754_count*LINK_COUNT(sub__V755); permitUnusedInt(sub__V755_count);
    /* sub__V755 = &#21 */
    Term sub__V756 = LINK(sink__V753->context, SUB(term__V754, 1)); int sub__V756_count = term__V754_count*LINK_COUNT(sub__V756); permitUnusedInt(sub__V756_count);
    /* sub__V756 = &#22 */
    Variable x__V757 = BINDER(term__V754,2,0); if (term__V754_count <= 1) UNBIND(x__V757);
    Term sub__V758 = LINK(sink__V753->context, SUB(term__V754, 2)); int sub__V758_count = term__V754_count*LINK_COUNT(sub__V758); permitUnusedInt(sub__V758_count);
    CRSX_CHECK_SORT(sink__V753->context, sub__V758, &sort_M_Reified_xVariable); UNLINK_SUB(sink__V753->context, term__V754,  2); NORMALIZE(sink__V753->context, sub__V758); SUB(term__V754,  2) = LINK(sink__V753->context, sub__V758);
    /* sub__V758 = &#1 */
    Term sub__V759 = LINK(sink__V753->context, SUB(term__V754, 3)); int sub__V759_count = term__V754_count*LINK_COUNT(sub__V759); permitUnusedInt(sub__V759_count);
    UNLINK_SUB(sink__V753->context, term__V754,  3); NORMALIZE(sink__V753->context, sub__V759); SUB(term__V754,  3) = LINK(sink__V753->context, sub__V759);
    /* sub__V759 = &#3 */
    Term sub__V760 = LINK(sink__V753->context, SUB(term__V754, 4)); int sub__V760_count = term__V754_count*LINK_COUNT(sub__V760); permitUnusedInt(sub__V760_count);
    UNLINK_SUB(sink__V753->context, term__V754,  4); NORMALIZE(sink__V753->context, sub__V760); SUB(term__V754,  4) = LINK(sink__V753->context, sub__V760);
    /* sub__V760 = &#4 */
    Term sub__V761 = LINK(sink__V753->context, SUB(term__V754, 5)); int sub__V761_count = term__V754_count*LINK_COUNT(sub__V761); permitUnusedInt(sub__V761_count);
    UNLINK_SUB(sink__V753->context, term__V754,  5); NORMALIZE(sink__V753->context, sub__V761); SUB(term__V754,  5) = LINK(sink__V753->context, sub__V761);
    /* sub__V761 = &#5 */
    Variable x__V762 = BINDER(term__V754,6,0); if (term__V754_count <= 1) UNBIND(x__V762);
    Term sub__V763 = LINK(sink__V753->context, SUB(term__V754, 6)); int sub__V763_count = term__V754_count*LINK_COUNT(sub__V763); permitUnusedInt(sub__V763_count);
    CRSX_CHECK_SORT(sink__V753->context, sub__V763, &sort_M_Reified_xVariable); UNLINK_SUB(sink__V753->context, term__V754,  6); NORMALIZE(sink__V753->context, sub__V763); SUB(term__V754,  6) = LINK(sink__V753->context, sub__V763);
    /* sub__V763 = &#6 */
    Variable x__V764 = BINDER(term__V754,7,0); if (term__V754_count <= 1) UNBIND(x__V764);
    Term sub__V765 = LINK(sink__V753->context, SUB(term__V754, 7)); int sub__V765_count = term__V754_count*LINK_COUNT(sub__V765); permitUnusedInt(sub__V765_count);
    CRSX_CHECK_SORT(sink__V753->context, sub__V765, &sort_M_Reified_xVariable); UNLINK_SUB(sink__V753->context, term__V754,  7); NORMALIZE(sink__V753->context, sub__V765); SUB(term__V754,  7) = LINK(sink__V753->context, sub__V765);
    /* sub__V765 = &#7 */
    NamedPropertyLink namedP__V766 = LINK_NamedPropertyLink(sink__V753->context, NAMED_PROPERTIES(term__V754));
    VariablePropertyLink varP__V767 = LINK_VariablePropertyLink(sink__V753->context, VARIABLE_PROPERTIES(term__V754));
    UNLINK(sink__V753->context, term__V754);
    { int test__V768;
      FORCE(sink__V753->context, sub__V759);
      test__V768 = (int) !strcmp(SYMBOL(sub__V759), "0" ); if (test__V768) {  UNLINK(sink__V753->context, sub__V759); { START(sink__V753, _M__sTextCons);
          { START(sink__V753, _M__sTextEmbed);
            { START(sink__V753, _M_AsText);
              {
                Term arg__V769;
                { Sink buf__V770 = ALLOCA_BUFFER(sink__V753->context);
                  COPY(buf__V770, LINK(buf__V770->context, sub__V760));arg__V769 = BUFFER_TERM(buf__V770); FREE_BUFFER(buf__V770); }
                Variable vars__V771[1] = {x__V762};
                Term args__V772[1] = {arg__V769};
                struct _SubstitutionFrame substitution__V773 = {NULL, 0, 1, vars__V771, args__V772, NULL};
                SUBSTITUTE(sink__V753, LINK(sink__V753->context,sub__V763), &substitution__V773); }
              END(sink__V753, _M_AsText); }
            END(sink__V753, _M__sTextEmbed); }
          { START(sink__V753, _M__sTextCons);
            { START(sink__V753, _M__sTextEmbed);
              { START(sink__V753, _M_AsText);
                {
                  Term arg__V774;
                  { Sink buf__V775 = ALLOCA_BUFFER(sink__V753->context);
                    COPY(buf__V775, sub__V755);arg__V774 = BUFFER_TERM(buf__V775); FREE_BUFFER(buf__V775); }
                  Variable vars__V776[1] = {x__V757};
                  Term args__V777[1] = {arg__V774};
                  struct _SubstitutionFrame substitution__V778 = {NULL, 0, 1, vars__V776, args__V777, NULL};
                  SUBSTITUTE(sink__V753, LINK(sink__V753->context,sub__V758), &substitution__V778); }
                END(sink__V753, _M_AsText); }
              END(sink__V753, _M__sTextEmbed); }
            { START(sink__V753, _M__sTextCons);
              { START(sink__V753, _M__sTextEmbed);
                { START(sink__V753, _M_AsText);
                  { START(sink__V753, _M_SplitMapText_s1);
                    COPY(sink__V753, sub__V756);{ Variable x__V779 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V753->context,"x__V779");
                      Variable binds__V780[1] = {x__V779}; BINDS(sink__V753, 1, binds__V780);
                      {
                        Term arg__V781;
                        { Sink buf__V782 = ALLOCA_BUFFER(sink__V753->context);
                          USE(buf__V782, x__V779); arg__V781 = BUFFER_TERM(buf__V782); FREE_BUFFER(buf__V782); }
                        Variable vars__V783[1] = {x__V757};
                        Term args__V784[1] = {arg__V781};
                        struct _SubstitutionFrame substitution__V785 = {NULL, 0, 1, vars__V783, args__V784, NULL};
                        SUBSTITUTE(sink__V753, sub__V758, &substitution__V785); }
                       }
                    LITERAL(sink__V753,  "1" ); COPY(sink__V753, sub__V760);COPY(sink__V753, sub__V761);{ Variable x__V786 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V753->context,"x__V786");
                      Variable binds__V787[1] = {x__V786}; BINDS(sink__V753, 1, binds__V787);
                      {
                        Term arg__V788;
                        { Sink buf__V789 = ALLOCA_BUFFER(sink__V753->context);
                          USE(buf__V789, x__V786); arg__V788 = BUFFER_TERM(buf__V789); FREE_BUFFER(buf__V789); }
                        Variable vars__V790[1] = {x__V762};
                        Term args__V791[1] = {arg__V788};
                        struct _SubstitutionFrame substitution__V792 = {NULL, 0, 1, vars__V790, args__V791, NULL};
                        SUBSTITUTE(sink__V753, sub__V763, &substitution__V792); }
                       }
                    { Variable x__V793 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V753->context,"x__V793");
                      Variable binds__V794[1] = {x__V793}; BINDS(sink__V753, 1, binds__V794);
                      {
                        Term arg__V795;
                        { Sink buf__V796 = ALLOCA_BUFFER(sink__V753->context);
                          USE(buf__V796, x__V793); arg__V795 = BUFFER_TERM(buf__V796); FREE_BUFFER(buf__V796); }
                        Variable vars__V797[1] = {x__V764};
                        Term args__V798[1] = {arg__V795};
                        struct _SubstitutionFrame substitution__V799 = {NULL, 0, 1, vars__V797, args__V798, NULL};
                        SUBSTITUTE(sink__V753, sub__V765, &substitution__V799); }
                       }
                    END(sink__V753, _M_SplitMapText_s1); }
                  END(sink__V753, _M_AsText); }
                END(sink__V753, _M__sTextEmbed); }
              { START(sink__V753, _M__sTextNil);
                END(sink__V753, _M__sTextNil); }
              END(sink__V753, _M__sTextCons); }
            END(sink__V753, _M__sTextCons); }
          END(sink__V753, _M__sTextCons); }
         }
      else { { int test__V800;
          FORCE(sink__V753->context, sub__V759);
          FORCE(sink__V753->context, sub__V761);
          test__V800 = (int) !strcmp(SYMBOL(sub__V759),SYMBOL(sub__V761));
          if (test__V800) {  UNLINK(sink__V753->context, sub__V759); { START(sink__V753, _M__sTextCons);
              { START(sink__V753, _M__sTextEmbed);
                { START(sink__V753, _M_AsText);
                  {
                    Term arg__V801;
                    { Sink buf__V802 = ALLOCA_BUFFER(sink__V753->context);
                      COPY(buf__V802, LINK(buf__V802->context, sub__V760));arg__V801 = BUFFER_TERM(buf__V802); FREE_BUFFER(buf__V802); }
                    Variable vars__V803[1] = {x__V764};
                    Term args__V804[1] = {arg__V801};
                    struct _SubstitutionFrame substitution__V805 = {NULL, 0, 1, vars__V803, args__V804, NULL};
                    SUBSTITUTE(sink__V753, LINK(sink__V753->context,sub__V765), &substitution__V805); }
                  END(sink__V753, _M_AsText); }
                END(sink__V753, _M__sTextEmbed); }
              { START(sink__V753, _M__sTextCons);
                { START(sink__V753, _M__sTextEmbed);
                  { START(sink__V753, _M_AsText);
                    { START(sink__V753, _M_SplitMapText_s1);
                      { START(sink__V753, _M__sCons);
                        COPY(sink__V753, sub__V755);COPY(sink__V753, sub__V756);END(sink__V753, _M__sCons); }
                      { Variable x__V806 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V753->context,"x__V806");
                        Variable binds__V807[1] = {x__V806}; BINDS(sink__V753, 1, binds__V807);
                        {
                          Term arg__V808;
                          { Sink buf__V809 = ALLOCA_BUFFER(sink__V753->context);
                            USE(buf__V809, x__V806); arg__V808 = BUFFER_TERM(buf__V809); FREE_BUFFER(buf__V809); }
                          Variable vars__V810[1] = {x__V757};
                          Term args__V811[1] = {arg__V808};
                          struct _SubstitutionFrame substitution__V812 = {NULL, 0, 1, vars__V810, args__V811, NULL};
                          SUBSTITUTE(sink__V753, sub__V758, &substitution__V812); }
                         }
                      LITERAL(sink__V753,  "0" ); { double num__V813;
                        num__V813 = DOUBLE(sub__V760); { double tmp__V814;
                          tmp__V814 = (double) 1; num__V813 += tmp__V814; }
                        LITERALNF(sink__V753, (size_t) 31, "%G", num__V813); }
                      COPY(sink__V753, sub__V761);{ Variable x__V815 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V753->context,"x__V815");
                        Variable binds__V816[1] = {x__V815}; BINDS(sink__V753, 1, binds__V816);
                        {
                          Term arg__V817;
                          { Sink buf__V818 = ALLOCA_BUFFER(sink__V753->context);
                            USE(buf__V818, x__V815); arg__V817 = BUFFER_TERM(buf__V818); FREE_BUFFER(buf__V818); }
                          Variable vars__V819[1] = {x__V762};
                          Term args__V820[1] = {arg__V817};
                          struct _SubstitutionFrame substitution__V821 = {NULL, 0, 1, vars__V819, args__V820, NULL};
                          SUBSTITUTE(sink__V753, sub__V763, &substitution__V821); }
                         }
                      { Variable x__V822 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V753->context,"x__V822");
                        Variable binds__V823[1] = {x__V822}; BINDS(sink__V753, 1, binds__V823);
                        {
                          Term arg__V824;
                          { Sink buf__V825 = ALLOCA_BUFFER(sink__V753->context);
                            USE(buf__V825, x__V822); arg__V824 = BUFFER_TERM(buf__V825); FREE_BUFFER(buf__V825); }
                          Variable vars__V826[1] = {x__V764};
                          Term args__V827[1] = {arg__V824};
                          struct _SubstitutionFrame substitution__V828 = {NULL, 0, 1, vars__V826, args__V827, NULL};
                          SUBSTITUTE(sink__V753, sub__V765, &substitution__V828); }
                         }
                      END(sink__V753, _M_SplitMapText_s1); }
                    END(sink__V753, _M_AsText); }
                  END(sink__V753, _M__sTextEmbed); }
                { START(sink__V753, _M__sTextNil);
                  END(sink__V753, _M__sTextNil); }
                END(sink__V753, _M__sTextCons); }
              END(sink__V753, _M__sTextCons); }
             }
          else { { START(sink__V753, _M__sTextCons);
              { START(sink__V753, _M__sTextEmbed);
                { START(sink__V753, _M_AsText);
                  {
                    Term arg__V829;
                    { Sink buf__V830 = ALLOCA_BUFFER(sink__V753->context);
                      COPY(buf__V830, sub__V755);arg__V829 = BUFFER_TERM(buf__V830); FREE_BUFFER(buf__V830); }
                    Variable vars__V831[1] = {x__V757};
                    Term args__V832[1] = {arg__V829};
                    struct _SubstitutionFrame substitution__V833 = {NULL, 0, 1, vars__V831, args__V832, NULL};
                    SUBSTITUTE(sink__V753, LINK(sink__V753->context,sub__V758), &substitution__V833); }
                  END(sink__V753, _M_AsText); }
                END(sink__V753, _M__sTextEmbed); }
              { START(sink__V753, _M__sTextCons);
                { START(sink__V753, _M__sTextEmbed);
                  { START(sink__V753, _M_AsText);
                    { START(sink__V753, _M_SplitMapText_s1);
                      COPY(sink__V753, sub__V756);{ Variable x__V834 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V753->context,"x__V834");
                        Variable binds__V835[1] = {x__V834}; BINDS(sink__V753, 1, binds__V835);
                        {
                          Term arg__V836;
                          { Sink buf__V837 = ALLOCA_BUFFER(sink__V753->context);
                            USE(buf__V837, x__V834); arg__V836 = BUFFER_TERM(buf__V837); FREE_BUFFER(buf__V837); }
                          Variable vars__V838[1] = {x__V757};
                          Term args__V839[1] = {arg__V836};
                          struct _SubstitutionFrame substitution__V840 = {NULL, 0, 1, vars__V838, args__V839, NULL};
                          SUBSTITUTE(sink__V753, sub__V758, &substitution__V840); }
                         }
                      { double num__V841;
                        num__V841 = DOUBLE(sub__V759); { double tmp__V842;
                          tmp__V842 = (double) 1; num__V841 += tmp__V842; }
                        LITERALNF(sink__V753, (size_t) 31, "%G", num__V841); }
                      COPY(sink__V753, sub__V760);COPY(sink__V753, sub__V761);{ Variable x__V843 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V753->context,"x__V843");
                        Variable binds__V844[1] = {x__V843}; BINDS(sink__V753, 1, binds__V844);
                        {
                          Term arg__V845;
                          { Sink buf__V846 = ALLOCA_BUFFER(sink__V753->context);
                            USE(buf__V846, x__V843); arg__V845 = BUFFER_TERM(buf__V846); FREE_BUFFER(buf__V846); }
                          Variable vars__V847[1] = {x__V762};
                          Term args__V848[1] = {arg__V845};
                          struct _SubstitutionFrame substitution__V849 = {NULL, 0, 1, vars__V847, args__V848, NULL};
                          SUBSTITUTE(sink__V753, sub__V763, &substitution__V849); }
                         }
                      { Variable x__V850 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V753->context,"x__V850");
                        Variable binds__V851[1] = {x__V850}; BINDS(sink__V753, 1, binds__V851);
                        {
                          Term arg__V852;
                          { Sink buf__V853 = ALLOCA_BUFFER(sink__V753->context);
                            USE(buf__V853, x__V850); arg__V852 = BUFFER_TERM(buf__V853); FREE_BUFFER(buf__V853); }
                          Variable vars__V854[1] = {x__V764};
                          Term args__V855[1] = {arg__V852};
                          struct _SubstitutionFrame substitution__V856 = {NULL, 0, 1, vars__V854, args__V855, NULL};
                          SUBSTITUTE(sink__V753, sub__V765, &substitution__V856); }
                         }
                      END(sink__V753, _M_SplitMapText_s1); }
                    END(sink__V753, _M_AsText); }
                  END(sink__V753, _M__sTextEmbed); }
                { START(sink__V753, _M__sTextNil);
                  END(sink__V753, _M__sTextNil); }
                END(sink__V753, _M__sTextCons); }
              END(sink__V753, _M__sTextCons); }
             }
        }
         }
    }
    UNLINK_NamedPropertyLink(sink__V753->context, namedP__V766); UNLINK_VariablePropertyLink(sink__V753->context, varP__V767);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION SplitMapText$3. */
int conBindOffs_M_SplitMapText_s3[] = {0 , 1 , 1 , 1 , 1 , 2 , 3};
char *nameFun_M_SplitMapText_s3(Term term) { return  "SplitMapText$3" ; }
struct _ConstructionDescriptor descriptor_M_SplitMapText_s3 = {&sort_M_Reified_xVariable, 0, 6, sizeof(STRUCT_Con_M_SplitMapText_s3), conBindOffs_M_SplitMapText_s3, &nameFun_M_SplitMapText_s3, &step_M_SplitMapText_s3};

int step_M_SplitMapText_s3(Sink sink__V857, Term term__V858)
{
  int term__V858_count = LINK_COUNT(term__V858); permitUnusedInt(term__V858_count);
  do {
    /* Contraction rule DEFS-SplitMapText-2. */
    ASSERT(sink__V857->context, !strcmp(SYMBOL(term__V858),  "SplitMapText$3" ));
    Variable x__V859 = BINDER(term__V858,0,0); if (term__V858_count <= 1) UNBIND(x__V859);
    Term sub__V860 = SUB(term__V858, 0); permitUnusedTerm(sub__V860); int sub__V860_count = term__V858_count*LINK_COUNT(sub__V860); permitUnusedInt(sub__V860_count);
    CRSX_CHECK_SORT(sink__V857->context, sub__V860, &sort_M_Reified_xVariable); /* sub__V860 = &#1 */
    Term sub__V861 = SUB(term__V858, 1); permitUnusedTerm(sub__V861); int sub__V861_count = term__V858_count*LINK_COUNT(sub__V861); permitUnusedInt(sub__V861_count);
    /* sub__V861 = &#3 */
    Term sub__V862 = LINK(sink__V857->context, SUB(term__V858, 2)); int sub__V862_count = term__V858_count*LINK_COUNT(sub__V862); permitUnusedInt(sub__V862_count);
    UNLINK_SUB(sink__V857->context, term__V858,  2); NORMALIZE(sink__V857->context, sub__V862); SUB(term__V858,  2) = LINK(sink__V857->context, sub__V862);
    /* sub__V862 = &#4 */
    Term sub__V863 = SUB(term__V858, 3); permitUnusedTerm(sub__V863); int sub__V863_count = term__V858_count*LINK_COUNT(sub__V863); permitUnusedInt(sub__V863_count);
    /* sub__V863 = &#5 */
    Variable x__V864 = BINDER(term__V858,4,0); if (term__V858_count <= 1) UNBIND(x__V864);
    Term sub__V865 = SUB(term__V858, 4); permitUnusedTerm(sub__V865); int sub__V865_count = term__V858_count*LINK_COUNT(sub__V865); permitUnusedInt(sub__V865_count);
    CRSX_CHECK_SORT(sink__V857->context, sub__V865, &sort_M_Reified_xVariable); /* sub__V865 = &#6 */
    Variable x__V866 = BINDER(term__V858,5,0); if (term__V858_count <= 1) UNBIND(x__V866);
    Term sub__V867 = LINK(sink__V857->context, SUB(term__V858, 5)); int sub__V867_count = term__V858_count*LINK_COUNT(sub__V867); permitUnusedInt(sub__V867_count);
    CRSX_CHECK_SORT(sink__V857->context, sub__V867, &sort_M_Reified_xVariable); /* sub__V867 = &#7 */
    NamedPropertyLink namedP__V868 = LINK_NamedPropertyLink(sink__V857->context, NAMED_PROPERTIES(term__V858));
    VariablePropertyLink varP__V869 = LINK_VariablePropertyLink(sink__V857->context, VARIABLE_PROPERTIES(term__V858));
    UNLINK(sink__V857->context, term__V858);
    {
      Term arg__V870;
      { Sink buf__V871 = ALLOCA_BUFFER(sink__V857->context);
        COPY(buf__V871, sub__V862);arg__V870 = BUFFER_TERM(buf__V871); FREE_BUFFER(buf__V871); }
      Variable vars__V872[1] = {x__V866};
      Term args__V873[1] = {arg__V870};
      struct _SubstitutionFrame substitution__V874 = {NULL, 0, 1, vars__V872, args__V873, NULL};
      SUBSTITUTE(sink__V857, sub__V867, &substitution__V874); }
    UNLINK_NamedPropertyLink(sink__V857->context, namedP__V868); UNLINK_VariablePropertyLink(sink__V857->context, varP__V869);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION INTEGER. */
int conBindOffs_M_INTEGER[] = {0 , 0};
char *nameFun_M_INTEGER(Term term) { return  "INTEGER" ; }
struct _ConstructionDescriptor descriptor_M_INTEGER = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_INTEGER), conBindOffs_M_INTEGER, &nameFun_M_INTEGER, &step_M_INTEGER};

int step_M_INTEGER(Sink sink__V875, Term term__V876)
{
  int term__V876_count = LINK_COUNT(term__V876); permitUnusedInt(term__V876_count);
  do {
    /* Contraction rule DEFS-INTEGER-1. */
    ASSERT(sink__V875->context, !strcmp(SYMBOL(term__V876),  "INTEGER" ));
    Term sub__V877 = LINK(sink__V875->context, SUB(term__V876, 0)); int sub__V877_count = term__V876_count*LINK_COUNT(sub__V877); permitUnusedInt(sub__V877_count);
    UNLINK_SUB(sink__V875->context, term__V876,  0); NORMALIZE(sink__V875->context, sub__V877); SUB(term__V876,  0) = LINK(sink__V875->context, sub__V877);
    /* sub__V877 = &#1 */
    NamedPropertyLink namedP__V878 = LINK_NamedPropertyLink(sink__V875->context, NAMED_PROPERTIES(term__V876));
    VariablePropertyLink varP__V879 = LINK_VariablePropertyLink(sink__V875->context, VARIABLE_PROPERTIES(term__V876));
    UNLINK(sink__V875->context, term__V876);
    { START(sink__V875, _M__sTextCons);
      { START(sink__V875, _M__sTextChars);
        { char *str__V880;
          {double num__V881; char *str__V882;
            num__V881 = DOUBLE(sub__V877); snprintf(str__V882 = ALLOCA(sink__V875->context, (size_t) 32), (size_t) 31, "%G", num__V881);
            { size_t z__V883 = strlen(str__V882) + 1; memcpy(str__V880 = ALLOCATE(sink__V875->context, z__V883), str__V882, z__V883); }
             }
          LITERALU(sink__V875, str__V880); }
        END(sink__V875, _M__sTextChars); }
      { START(sink__V875, _M__sTextNil);
        END(sink__V875, _M__sTextNil); }
      END(sink__V875, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V875->context, namedP__V878); UNLINK_VariablePropertyLink(sink__V875->context, varP__V879);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION EventConstructor. */
int conBindOffs_M_EventConstructor[] = {0 , 0};
char *nameFun_M_EventConstructor(Term term) { return  "EventConstructor" ; }
struct _ConstructionDescriptor descriptor_M_EventConstructor = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_EventConstructor), conBindOffs_M_EventConstructor, &nameFun_M_EventConstructor, &step_M_EventConstructor};

int step_M_EventConstructor(Sink sink__V884, Term term__V885)
{
  int term__V885_count = LINK_COUNT(term__V885); permitUnusedInt(term__V885_count);
  do {
    /* Contraction rule DEFS-EventConstructor-1. */
    ASSERT(sink__V884->context, !strcmp(SYMBOL(term__V885),  "EventConstructor" ));
    Term sub__V886 = LINK(sink__V884->context, SUB(term__V885, 0)); int sub__V886_count = term__V885_count*LINK_COUNT(sub__V886); permitUnusedInt(sub__V886_count);
    /* sub__V886 = &#1 */
    NamedPropertyLink namedP__V887 = LINK_NamedPropertyLink(sink__V884->context, NAMED_PROPERTIES(term__V885));
    VariablePropertyLink varP__V888 = LINK_VariablePropertyLink(sink__V884->context, VARIABLE_PROPERTIES(term__V885));
    UNLINK(sink__V884->context, term__V885);
    { START(sink__V884, _M_MANGLE);
      COPY(sink__V884, sub__V886);END(sink__V884, _M_MANGLE); }
    UNLINK_NamedPropertyLink(sink__V884->context, namedP__V887); UNLINK_VariablePropertyLink(sink__V884->context, varP__V888);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION SortInternals. */
int conBindOffs_M_SortInternals[] = {0 , 0};
char *nameFun_M_SortInternals(Term term) { return  "SortInternals" ; }
struct _ConstructionDescriptor descriptor_M_SortInternals = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_SortInternals), conBindOffs_M_SortInternals, &nameFun_M_SortInternals, &step_M_SortInternals};

int step_M_SortInternals(Sink sink__V889, Term term__V890)
{
  int term__V890_count = LINK_COUNT(term__V890); permitUnusedInt(term__V890_count);
  do {
    /* Contraction rule DEFS-SortInternals-1. */
    ASSERT(sink__V889->context, !strcmp(SYMBOL(term__V890),  "SortInternals" ));
    Term sub__V891 = LINK(sink__V889->context, SUB(term__V890, 0)); int sub__V891_count = term__V890_count*LINK_COUNT(sub__V891); permitUnusedInt(sub__V891_count);
    /* sub__V891 = &#1 */
    NamedPropertyLink namedP__V892 = LINK_NamedPropertyLink(sink__V889->context, NAMED_PROPERTIES(term__V890));
    VariablePropertyLink varP__V893 = LINK_VariablePropertyLink(sink__V889->context, VARIABLE_PROPERTIES(term__V890));
    UNLINK(sink__V889->context, term__V890);
    { START(sink__V889, _M__sTextCons);
      { START(sink__V889, _M__sTextChars);
        LITERAL(sink__V889,  "sortInt" ); END(sink__V889, _M__sTextChars); }
      { START(sink__V889, _M__sTextCons);
        { START(sink__V889, _M__sTextEmbed);
          { START(sink__V889, _M_AsText);
            { START(sink__V889, _M_MANGLE);
              COPY(sink__V889, sub__V891);END(sink__V889, _M_MANGLE); }
            END(sink__V889, _M_AsText); }
          END(sink__V889, _M__sTextEmbed); }
        { START(sink__V889, _M__sTextNil);
          END(sink__V889, _M__sTextNil); }
        END(sink__V889, _M__sTextCons); }
      END(sink__V889, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V889->context, namedP__V892); UNLINK_VariablePropertyLink(sink__V889->context, varP__V893);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION SortCons. */
int conBindOffs_M_SortCons[] = {0 , 0};
char *nameFun_M_SortCons(Term term) { return  "SortCons" ; }
struct _ConstructionDescriptor descriptor_M_SortCons = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_SortCons), conBindOffs_M_SortCons, &nameFun_M_SortCons, &step_M_SortCons};

int step_M_SortCons(Sink sink__V894, Term term__V895)
{
  int term__V895_count = LINK_COUNT(term__V895); permitUnusedInt(term__V895_count);
  do {
    /* Contraction rule DEFS-SortCons-1. */
    ASSERT(sink__V894->context, !strcmp(SYMBOL(term__V895),  "SortCons" ));
    Term sub__V896 = LINK(sink__V894->context, SUB(term__V895, 0)); int sub__V896_count = term__V895_count*LINK_COUNT(sub__V896); permitUnusedInt(sub__V896_count);
    /* sub__V896 = &#1 */
    NamedPropertyLink namedP__V897 = LINK_NamedPropertyLink(sink__V894->context, NAMED_PROPERTIES(term__V895));
    VariablePropertyLink varP__V898 = LINK_VariablePropertyLink(sink__V894->context, VARIABLE_PROPERTIES(term__V895));
    UNLINK(sink__V894->context, term__V895);
    { START(sink__V894, _M__sTextCons);
      { START(sink__V894, _M__sTextChars);
        LITERAL(sink__V894,  "sortCon" ); END(sink__V894, _M__sTextChars); }
      { START(sink__V894, _M__sTextCons);
        { START(sink__V894, _M__sTextEmbed);
          { START(sink__V894, _M_AsText);
            { START(sink__V894, _M_MANGLE);
              COPY(sink__V894, sub__V896);END(sink__V894, _M_MANGLE); }
            END(sink__V894, _M_AsText); }
          END(sink__V894, _M__sTextEmbed); }
        { START(sink__V894, _M__sTextNil);
          END(sink__V894, _M__sTextNil); }
        END(sink__V894, _M__sTextCons); }
      END(sink__V894, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V894->context, namedP__V897); UNLINK_VariablePropertyLink(sink__V894->context, varP__V898);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DINTEGER$1. */
int conBindOffs_M_DINTEGER_s1[] = {0 , 0};
char *nameFun_M_DINTEGER_s1(Term term) { return  "DINTEGER$1" ; }
struct _ConstructionDescriptor descriptor_M_DINTEGER_s1 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_DINTEGER_s1), conBindOffs_M_DINTEGER_s1, &nameFun_M_DINTEGER_s1, &step_M_DINTEGER_s1};

int step_M_DINTEGER_s1(Sink sink__V899, Term term__V900)
{
  int term__V900_count = LINK_COUNT(term__V900); permitUnusedInt(term__V900_count);
  do {
    /* Contraction rule DEFS-DINTEGER-1. */
    ASSERT(sink__V899->context, !strcmp(SYMBOL(term__V900),  "DINTEGER$1" ));
    Term sub__V901 = LINK(sink__V899->context, SUB(term__V900, 0)); int sub__V901_count = term__V900_count*LINK_COUNT(sub__V901); permitUnusedInt(sub__V901_count);
    UNLINK_SUB(sink__V899->context, term__V900,  0); NORMALIZE(sink__V899->context, sub__V901); SUB(term__V900,  0) = LINK(sink__V899->context, sub__V901);
    /* sub__V901 = &#2 */
    NamedPropertyLink namedP__V902 = LINK_NamedPropertyLink(sink__V899->context, NAMED_PROPERTIES(term__V900));
    VariablePropertyLink varP__V903 = LINK_VariablePropertyLink(sink__V899->context, VARIABLE_PROPERTIES(term__V900));
    UNLINK(sink__V899->context, term__V900);
    { START(sink__V899, _M__sTextCons);
      { START(sink__V899, _M__sTextChars);
        { char *str__V904;
          {double num__V905; char *str__V906;
            num__V905 = DOUBLE(sub__V901); snprintf(str__V906 = ALLOCA(sink__V899->context, (size_t) 32), (size_t) 31, "%G", num__V905);
            { size_t z__V907 = strlen(str__V906) + 1; memcpy(str__V904 = ALLOCATE(sink__V899->context, z__V907), str__V906, z__V907); }
             }
          LITERALU(sink__V899, str__V904); }
        END(sink__V899, _M__sTextChars); }
      { START(sink__V899, _M__sTextNil);
        END(sink__V899, _M__sTextNil); }
      END(sink__V899, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V899->context, namedP__V902); UNLINK_VariablePropertyLink(sink__V899->context, varP__V903);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Name. */
int conBindOffs_M_Name[] = {0 , 0};
char *nameFun_M_Name(Term term) { return  "Name" ; }
struct _ConstructionDescriptor descriptor_M_Name = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_Name), conBindOffs_M_Name, &nameFun_M_Name, &step_M_Name};

int step_M_Name(Sink sink__V908, Term term__V909)
{
  int term__V909_count = LINK_COUNT(term__V909); permitUnusedInt(term__V909_count);
  do {
    /* Contraction rule DEFS-Name-1. */
    ASSERT(sink__V908->context, !strcmp(SYMBOL(term__V909),  "Name" ));
    Term sub__V910 = LINK(sink__V908->context, SUB(term__V909, 0)); int sub__V910_count = term__V909_count*LINK_COUNT(sub__V910); permitUnusedInt(sub__V910_count);
    /* sub__V910 = &#1 */
    NamedPropertyLink namedP__V911 = LINK_NamedPropertyLink(sink__V908->context, NAMED_PROPERTIES(term__V909));
    VariablePropertyLink varP__V912 = LINK_VariablePropertyLink(sink__V908->context, VARIABLE_PROPERTIES(term__V909));
    UNLINK(sink__V908->context, term__V909);
    { START(sink__V908, _M__sTextCons);
      { START(sink__V908, _M__sTextChars);
        LITERAL(sink__V908,  "name" ); END(sink__V908, _M__sTextChars); }
      { START(sink__V908, _M__sTextCons);
        { START(sink__V908, _M__sTextEmbed);
          { START(sink__V908, _M_AsText);
            { START(sink__V908, _M_MANGLE);
              COPY(sink__V908, sub__V910);END(sink__V908, _M_MANGLE); }
            END(sink__V908, _M_AsText); }
          END(sink__V908, _M__sTextEmbed); }
        { START(sink__V908, _M__sTextNil);
          END(sink__V908, _M__sTextNil); }
        END(sink__V908, _M__sTextCons); }
      END(sink__V908, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V908->context, namedP__V911); UNLINK_VariablePropertyLink(sink__V908->context, varP__V912);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION EnumTag. */
int conBindOffs_M_EnumTag[] = {0 , 0};
char *nameFun_M_EnumTag(Term term) { return  "EnumTag" ; }
struct _ConstructionDescriptor descriptor_M_EnumTag = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_EnumTag), conBindOffs_M_EnumTag, &nameFun_M_EnumTag, &step_M_EnumTag};

int step_M_EnumTag(Sink sink__V913, Term term__V914)
{
  int term__V914_count = LINK_COUNT(term__V914); permitUnusedInt(term__V914_count);
  do {
    /* Contraction rule DEFS-EnumTag-1. */
    ASSERT(sink__V913->context, !strcmp(SYMBOL(term__V914),  "EnumTag" ));
    Term sub__V915 = LINK(sink__V913->context, SUB(term__V914, 0)); int sub__V915_count = term__V914_count*LINK_COUNT(sub__V915); permitUnusedInt(sub__V915_count);
    /* sub__V915 = &#1 */
    NamedPropertyLink namedP__V916 = LINK_NamedPropertyLink(sink__V913->context, NAMED_PROPERTIES(term__V914));
    VariablePropertyLink varP__V917 = LINK_VariablePropertyLink(sink__V913->context, VARIABLE_PROPERTIES(term__V914));
    UNLINK(sink__V913->context, term__V914);
    { START(sink__V913, _M__sTextCons);
      { START(sink__V913, _M__sTextChars);
        LITERAL(sink__V913,  "Data" ); END(sink__V913, _M__sTextChars); }
      { START(sink__V913, _M__sTextCons);
        { START(sink__V913, _M__sTextEmbed);
          { START(sink__V913, _M_AsText);
            { START(sink__V913, _M_MANGLE);
              COPY(sink__V913, sub__V915);END(sink__V913, _M_MANGLE); }
            END(sink__V913, _M_AsText); }
          END(sink__V913, _M__sTextEmbed); }
        { START(sink__V913, _M__sTextNil);
          END(sink__V913, _M__sTextNil); }
        END(sink__V913, _M__sTextCons); }
      END(sink__V913, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V913->context, namedP__V916); UNLINK_VariablePropertyLink(sink__V913->context, varP__V917);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION MapText$1. */
int conBindOffs_M_MapText_s1[] = {0 , 0 , 1};
char *nameFun_M_MapText_s1(Term term) { return  "MapText$1" ; }
struct _ConstructionDescriptor descriptor_M_MapText_s1 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_MapText_s1), conBindOffs_M_MapText_s1, &nameFun_M_MapText_s1, &step_M_MapText_s1};

int step_M_MapText_s1(Sink sink__V918, Term term__V919)
{
  int term__V919_count = LINK_COUNT(term__V919); permitUnusedInt(term__V919_count);
  Term sub__V920 = FORCE(sink__V918->context, SUB(term__V919, 0));
  EnumOf_M__sList choice__V921 = (IS_VARIABLE_USE(sub__V920) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V920));
  switch (choice__V921)
  {
    case Data_M__sCons: { /* Function DEFS-MapText-1$MapText$1$$Cons case $Cons */
      ASSERT(sink__V918->context, !strcmp(SYMBOL(term__V919),  "MapText$1" ));
      Term sub__V922 = SUB(term__V919, 0); permitUnusedTerm(sub__V922); int sub__V922_count = term__V919_count*LINK_COUNT(sub__V922); permitUnusedInt(sub__V922_count);
      ASSERT(sink__V918->context, !strcmp(SYMBOL(sub__V922),  "$Cons" ));
      Term sub__V923 = LINK(sink__V918->context, SUB(sub__V922, 0)); int sub__V923_count = sub__V922_count*LINK_COUNT(sub__V923); permitUnusedInt(sub__V923_count);
      /* sub__V923 = &#0-0 */
      Term sub__V924 = LINK(sink__V918->context, SUB(sub__V922, 1)); int sub__V924_count = sub__V922_count*LINK_COUNT(sub__V924); permitUnusedInt(sub__V924_count);
      /* sub__V924 = &#0-1 */
      Variable x__V925 = BINDER(term__V919,1,0); if (term__V919_count <= 1) UNBIND(x__V925);
      Term sub__V926 = LINK(sink__V918->context, SUB(term__V919, 1)); int sub__V926_count = term__V919_count*LINK_COUNT(sub__V926); permitUnusedInt(sub__V926_count);
      CRSX_CHECK_SORT(sink__V918->context, sub__V926, &sort_M_Reified_xVariable); /* sub__V926 = &#2 */
      NamedPropertyLink namedP__V927 = LINK_NamedPropertyLink(sink__V918->context, NAMED_PROPERTIES(term__V919));
      VariablePropertyLink varP__V928 = LINK_VariablePropertyLink(sink__V918->context, VARIABLE_PROPERTIES(term__V919));
      UNLINK(sink__V918->context, term__V919);
      ADD_PROPERTIES(sink__V918, LINK_NamedPropertyLink(sink__V918->context, namedP__V927), LINK_VariablePropertyLink(sink__V918->context, varP__V928));
      { START(sink__V918, _M_MapText_s2);
        COPY(sink__V918, sub__V923);COPY(sink__V918, sub__V924);{ if (!IS_BOUND(x__V925)) { REBIND(x__V925);
            Variable binds__V929[1] = {x__V925}; BINDS(sink__V918, 1, binds__V929);
            COPY(sink__V918, sub__V926); /* REUSED SUBSTITUTION */  }
          else { Variable b__V930 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V918->context,"b__V930");
            Variable binds__V931[1] = {b__V930}; BINDS(sink__V918, 1, binds__V931);
            {
              Term arg__V932;
              { Sink buf__V933 = ALLOCA_BUFFER(sink__V918->context);
                USE(buf__V933, b__V930); arg__V932 = BUFFER_TERM(buf__V933); FREE_BUFFER(buf__V933); }
              Variable vars__V934[1] = {x__V925};
              Term args__V935[1] = {arg__V932};
              struct _SubstitutionFrame substitution__V936 = {NULL, 0, 1, vars__V934, args__V935, NULL};
              SUBSTITUTE(sink__V918, sub__V926, &substitution__V936); }
                }
           }
        END(sink__V918, _M_MapText_s2); }
      UNLINK_NamedPropertyLink(sink__V918->context, namedP__V927); UNLINK_VariablePropertyLink(sink__V918->context, varP__V928);
      
      return 1;
    break; } case Data_M__sNil: { /* Function DEFS-MapText-2$MapText$1$$Nil case $Nil */
      ASSERT(sink__V918->context, !strcmp(SYMBOL(term__V919),  "MapText$1" ));
      Term sub__V937 = SUB(term__V919, 0); permitUnusedTerm(sub__V937); int sub__V937_count = term__V919_count*LINK_COUNT(sub__V937); permitUnusedInt(sub__V937_count);
      ASSERT(sink__V918->context, !strcmp(SYMBOL(sub__V937),  "$Nil" ));
      Variable x__V938 = BINDER(term__V919,1,0); if (term__V919_count <= 1) UNBIND(x__V938);
      Term sub__V939 = LINK(sink__V918->context, SUB(term__V919, 1)); int sub__V939_count = term__V919_count*LINK_COUNT(sub__V939); permitUnusedInt(sub__V939_count);
      CRSX_CHECK_SORT(sink__V918->context, sub__V939, &sort_M_Reified_xVariable); /* sub__V939 = &#0 */
      NamedPropertyLink namedP__V940 = LINK_NamedPropertyLink(sink__V918->context, NAMED_PROPERTIES(term__V919));
      VariablePropertyLink varP__V941 = LINK_VariablePropertyLink(sink__V918->context, VARIABLE_PROPERTIES(term__V919));
      UNLINK(sink__V918->context, term__V919);
      ADD_PROPERTIES(sink__V918, LINK_NamedPropertyLink(sink__V918->context, namedP__V940), LINK_VariablePropertyLink(sink__V918->context, varP__V941));
      { START(sink__V918, _M_MapText_s3);
        { if (!IS_BOUND(x__V938)) { REBIND(x__V938);
            Variable binds__V942[1] = {x__V938}; BINDS(sink__V918, 1, binds__V942);
            COPY(sink__V918, sub__V939); /* REUSED SUBSTITUTION */  }
          else { Variable b__V943 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V918->context,"b__V943");
            Variable binds__V944[1] = {b__V943}; BINDS(sink__V918, 1, binds__V944);
            {
              Term arg__V945;
              { Sink buf__V946 = ALLOCA_BUFFER(sink__V918->context);
                USE(buf__V946, b__V943); arg__V945 = BUFFER_TERM(buf__V946); FREE_BUFFER(buf__V946); }
              Variable vars__V947[1] = {x__V938};
              Term args__V948[1] = {arg__V945};
              struct _SubstitutionFrame substitution__V949 = {NULL, 0, 1, vars__V947, args__V948, NULL};
              SUBSTITUTE(sink__V918, sub__V939, &substitution__V949); }
                }
           }
        END(sink__V918, _M_MapText_s3); }
      UNLINK_NamedPropertyLink(sink__V918->context, namedP__V940); UNLINK_VariablePropertyLink(sink__V918->context, varP__V941);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION MapText$2. */
int conBindOffs_M_MapText_s2[] = {0 , 0 , 0 , 1};
char *nameFun_M_MapText_s2(Term term) { return  "MapText$2" ; }
struct _ConstructionDescriptor descriptor_M_MapText_s2 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_MapText_s2), conBindOffs_M_MapText_s2, &nameFun_M_MapText_s2, &step_M_MapText_s2};

int step_M_MapText_s2(Sink sink__V950, Term term__V951)
{
  int term__V951_count = LINK_COUNT(term__V951); permitUnusedInt(term__V951_count);
  do {
    /* Contraction rule DEFS-MapText-1. */
    ASSERT(sink__V950->context, !strcmp(SYMBOL(term__V951),  "MapText$2" ));
    Term sub__V952 = LINK(sink__V950->context, SUB(term__V951, 0)); int sub__V952_count = term__V951_count*LINK_COUNT(sub__V952); permitUnusedInt(sub__V952_count);
    /* sub__V952 = &#21 */
    Term sub__V953 = LINK(sink__V950->context, SUB(term__V951, 1)); int sub__V953_count = term__V951_count*LINK_COUNT(sub__V953); permitUnusedInt(sub__V953_count);
    /* sub__V953 = &#22 */
    Variable x__V954 = BINDER(term__V951,2,0); if (term__V951_count <= 1) UNBIND(x__V954);
    Term sub__V955 = LINK(sink__V950->context, SUB(term__V951, 2)); int sub__V955_count = term__V951_count*LINK_COUNT(sub__V955); permitUnusedInt(sub__V955_count);
    CRSX_CHECK_SORT(sink__V950->context, sub__V955, &sort_M_Reified_xVariable); UNLINK_SUB(sink__V950->context, term__V951,  2); NORMALIZE(sink__V950->context, sub__V955); SUB(term__V951,  2) = LINK(sink__V950->context, sub__V955);
    /* sub__V955 = &#1 */
    NamedPropertyLink namedP__V956 = LINK_NamedPropertyLink(sink__V950->context, NAMED_PROPERTIES(term__V951));
    VariablePropertyLink varP__V957 = LINK_VariablePropertyLink(sink__V950->context, VARIABLE_PROPERTIES(term__V951));
    UNLINK(sink__V950->context, term__V951);
    { START(sink__V950, _M__sTextCons);
      { START(sink__V950, _M__sTextEmbed);
        { START(sink__V950, _M_AsText);
          {
            Term arg__V958;
            { Sink buf__V959 = ALLOCA_BUFFER(sink__V950->context);
              COPY(buf__V959, sub__V952);arg__V958 = BUFFER_TERM(buf__V959); FREE_BUFFER(buf__V959); }
            Variable vars__V960[1] = {x__V954};
            Term args__V961[1] = {arg__V958};
            struct _SubstitutionFrame substitution__V962 = {NULL, 0, 1, vars__V960, args__V961, NULL};
            SUBSTITUTE(sink__V950, LINK(sink__V950->context,sub__V955), &substitution__V962); }
          END(sink__V950, _M_AsText); }
        END(sink__V950, _M__sTextEmbed); }
      { START(sink__V950, _M__sTextCons);
        { START(sink__V950, _M__sTextEmbed);
          { START(sink__V950, _M_AsText);
            { START(sink__V950, _M_MapText_s1);
              COPY(sink__V950, sub__V953);{ Variable x__V963 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V950->context,"x__V963");
                Variable binds__V964[1] = {x__V963}; BINDS(sink__V950, 1, binds__V964);
                {
                  Term arg__V965;
                  { Sink buf__V966 = ALLOCA_BUFFER(sink__V950->context);
                    USE(buf__V966, x__V963); arg__V965 = BUFFER_TERM(buf__V966); FREE_BUFFER(buf__V966); }
                  Variable vars__V967[1] = {x__V954};
                  Term args__V968[1] = {arg__V965};
                  struct _SubstitutionFrame substitution__V969 = {NULL, 0, 1, vars__V967, args__V968, NULL};
                  SUBSTITUTE(sink__V950, sub__V955, &substitution__V969); }
                 }
              END(sink__V950, _M_MapText_s1); }
            END(sink__V950, _M_AsText); }
          END(sink__V950, _M__sTextEmbed); }
        { START(sink__V950, _M__sTextNil);
          END(sink__V950, _M__sTextNil); }
        END(sink__V950, _M__sTextCons); }
      END(sink__V950, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V950->context, namedP__V956); UNLINK_VariablePropertyLink(sink__V950->context, varP__V957);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION MapText$3. */
int conBindOffs_M_MapText_s3[] = {0 , 1};
char *nameFun_M_MapText_s3(Term term) { return  "MapText$3" ; }
struct _ConstructionDescriptor descriptor_M_MapText_s3 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_MapText_s3), conBindOffs_M_MapText_s3, &nameFun_M_MapText_s3, &step_M_MapText_s3};

int step_M_MapText_s3(Sink sink__V970, Term term__V971)
{
  int term__V971_count = LINK_COUNT(term__V971); permitUnusedInt(term__V971_count);
  do {
    /* Contraction rule DEFS-MapText-2. */
    ASSERT(sink__V970->context, !strcmp(SYMBOL(term__V971),  "MapText$3" ));
    Variable x__V972 = BINDER(term__V971,0,0); if (term__V971_count <= 1) UNBIND(x__V972);
    Term sub__V973 = SUB(term__V971, 0); permitUnusedTerm(sub__V973); int sub__V973_count = term__V971_count*LINK_COUNT(sub__V973); permitUnusedInt(sub__V973_count);
    CRSX_CHECK_SORT(sink__V970->context, sub__V973, &sort_M_Reified_xVariable); /* sub__V973 = &#1 */
    NamedPropertyLink namedP__V974 = LINK_NamedPropertyLink(sink__V970->context, NAMED_PROPERTIES(term__V971));
    VariablePropertyLink varP__V975 = LINK_VariablePropertyLink(sink__V970->context, VARIABLE_PROPERTIES(term__V971));
    UNLINK(sink__V970->context, term__V971);
    { START(sink__V970, _M__sTextNil); END(sink__V970, _M__sTextNil); }
    UNLINK_NamedPropertyLink(sink__V970->context, namedP__V974); UNLINK_VariablePropertyLink(sink__V970->context, varP__V975);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Var. */
int conBindOffs_M_Var[] = {0 , 0};
char *nameFun_M_Var(Term term) { return  "Var" ; }
struct _ConstructionDescriptor descriptor_M_Var = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_Var), conBindOffs_M_Var, &nameFun_M_Var, &step_M_Var};

int step_M_Var(Sink sink__V976, Term term__V977)
{
  int term__V977_count = LINK_COUNT(term__V977); permitUnusedInt(term__V977_count);
  do {
    /* Contraction rule DEFS-Var-1. */
    ASSERT(sink__V976->context, !strcmp(SYMBOL(term__V977),  "Var" ));
    Term sub__V978 = LINK(sink__V976->context, SUB(term__V977, 0)); int sub__V978_count = term__V977_count*LINK_COUNT(sub__V978); permitUnusedInt(sub__V978_count);
    /* sub__V978 = &#1 */
    NamedPropertyLink namedP__V979 = LINK_NamedPropertyLink(sink__V976->context, NAMED_PROPERTIES(term__V977));
    VariablePropertyLink varP__V980 = LINK_VariablePropertyLink(sink__V976->context, VARIABLE_PROPERTIES(term__V977));
    UNLINK(sink__V976->context, term__V977);
    { START(sink__V976, _M__sTextCons);
      { START(sink__V976, _M__sTextChars);
        LITERAL(sink__V976,  "v" ); END(sink__V976, _M__sTextChars); }
      { START(sink__V976, _M__sTextCons);
        { START(sink__V976, _M__sTextEmbed);
          { START(sink__V976, _M_AsText);
            { START(sink__V976, _M_MANGLE);
              COPY(sink__V976, sub__V978);END(sink__V976, _M_MANGLE); }
            END(sink__V976, _M_AsText); }
          END(sink__V976, _M__sTextEmbed); }
        { START(sink__V976, _M__sTextNil);
          END(sink__V976, _M__sTextNil); }
        END(sink__V976, _M__sTextCons); }
      END(sink__V976, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V976->context, namedP__V979); UNLINK_VariablePropertyLink(sink__V976->context, varP__V980);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION MapIndexText$1. */
int conBindOffs_M_MapIndexText_s1[] = {0 , 0 , 2 , 2};
char *nameFun_M_MapIndexText_s1(Term term) { return  "MapIndexText$1" ; }
struct _ConstructionDescriptor descriptor_M_MapIndexText_s1 = {&sort_M_Reified_xVariable, 0, 3, sizeof(STRUCT_Con_M_MapIndexText_s1), conBindOffs_M_MapIndexText_s1, &nameFun_M_MapIndexText_s1, &step_M_MapIndexText_s1};

int step_M_MapIndexText_s1(Sink sink__V981, Term term__V982)
{
  int term__V982_count = LINK_COUNT(term__V982); permitUnusedInt(term__V982_count);
  Term sub__V983 = FORCE(sink__V981->context, SUB(term__V982, 0));
  EnumOf_M__sList choice__V984 = (IS_VARIABLE_USE(sub__V983) ? VarOf_M__sList : (EnumOf_M__sList) TAG(sub__V983));
  switch (choice__V984)
  {
    case Data_M__sCons: { /* Function DEFS-MapIndexText-1$MapIndexText$1$$Cons case $Cons */
      ASSERT(sink__V981->context, !strcmp(SYMBOL(term__V982),  "MapIndexText$1" ));
      Term sub__V985 = SUB(term__V982, 0); permitUnusedTerm(sub__V985); int sub__V985_count = term__V982_count*LINK_COUNT(sub__V985); permitUnusedInt(sub__V985_count);
      ASSERT(sink__V981->context, !strcmp(SYMBOL(sub__V985),  "$Cons" ));
      Term sub__V986 = LINK(sink__V981->context, SUB(sub__V985, 0)); int sub__V986_count = sub__V985_count*LINK_COUNT(sub__V986); permitUnusedInt(sub__V986_count);
      /* sub__V986 = &#0-0 */
      Term sub__V987 = LINK(sink__V981->context, SUB(sub__V985, 1)); int sub__V987_count = sub__V985_count*LINK_COUNT(sub__V987); permitUnusedInt(sub__V987_count);
      /* sub__V987 = &#0-1 */
      Variable x__V988 = BINDER(term__V982,1,0); if (term__V982_count <= 1) UNBIND(x__V988);
      Variable x__V989 = BINDER(term__V982,1,1); if (term__V982_count <= 1) UNBIND(x__V989);
      Term sub__V990 = LINK(sink__V981->context, SUB(term__V982, 1)); int sub__V990_count = term__V982_count*LINK_COUNT(sub__V990); permitUnusedInt(sub__V990_count);
      CRSX_CHECK_SORT(sink__V981->context, sub__V990, &sort_M_Reified_xVariable); /* sub__V990 = &#2 */
      Term sub__V991 = LINK(sink__V981->context, SUB(term__V982, 2)); int sub__V991_count = term__V982_count*LINK_COUNT(sub__V991); permitUnusedInt(sub__V991_count);
      /* sub__V991 = &#3 */
      NamedPropertyLink namedP__V992 = LINK_NamedPropertyLink(sink__V981->context, NAMED_PROPERTIES(term__V982));
      VariablePropertyLink varP__V993 = LINK_VariablePropertyLink(sink__V981->context, VARIABLE_PROPERTIES(term__V982));
      UNLINK(sink__V981->context, term__V982);
      ADD_PROPERTIES(sink__V981, LINK_NamedPropertyLink(sink__V981->context, namedP__V992), LINK_VariablePropertyLink(sink__V981->context, varP__V993));
      { START(sink__V981, _M_MapIndexText_s2);
        COPY(sink__V981, sub__V986);COPY(sink__V981, sub__V987);{ if (!IS_BOUND(x__V988)) { REBIND(x__V988);
            REBIND(x__V989);
            Variable binds__V994[2] = {x__V988,x__V989}; BINDS(sink__V981, 2, binds__V994);
            COPY(sink__V981, sub__V990); /* REUSED SUBSTITUTION */  }
          else { Variable b__V995 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V981->context,"b__V995");
            Variable b__V996 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V981->context,"b__V996");
            Variable binds__V997[2] = {b__V995,b__V996}; BINDS(sink__V981, 2, binds__V997);
            {
              Term arg__V998;
              { Sink buf__V999 = ALLOCA_BUFFER(sink__V981->context);
                USE(buf__V999, b__V995); arg__V998 = BUFFER_TERM(buf__V999); FREE_BUFFER(buf__V999); }
              Term arg__V1000;
              { Sink buf__V1001 = ALLOCA_BUFFER(sink__V981->context);
                USE(buf__V1001, b__V996); arg__V1000 = BUFFER_TERM(buf__V1001); FREE_BUFFER(buf__V1001); }
              Variable vars__V1002[2] = {x__V988,x__V989};
              Term args__V1003[2] = {arg__V998,arg__V1000};
              struct _SubstitutionFrame substitution__V1004 = {NULL, 0, 2, vars__V1002, args__V1003, NULL};
              SUBSTITUTE(sink__V981, sub__V990, &substitution__V1004); }
                }
           }
        COPY(sink__V981, sub__V991);END(sink__V981, _M_MapIndexText_s2); }
      UNLINK_NamedPropertyLink(sink__V981->context, namedP__V992); UNLINK_VariablePropertyLink(sink__V981->context, varP__V993);
      
      return 1;
    break; } case Data_M__sNil: { /* Function DEFS-MapIndexText-2$MapIndexText$1$$Nil case $Nil */
      ASSERT(sink__V981->context, !strcmp(SYMBOL(term__V982),  "MapIndexText$1" ));
      Term sub__V1005 = SUB(term__V982, 0); permitUnusedTerm(sub__V1005); int sub__V1005_count = term__V982_count*LINK_COUNT(sub__V1005); permitUnusedInt(sub__V1005_count);
      ASSERT(sink__V981->context, !strcmp(SYMBOL(sub__V1005),  "$Nil" ));
      Variable x__V1006 = BINDER(term__V982,1,0); if (term__V982_count <= 1) UNBIND(x__V1006);
      Variable x__V1007 = BINDER(term__V982,1,1); if (term__V982_count <= 1) UNBIND(x__V1007);
      Term sub__V1008 = LINK(sink__V981->context, SUB(term__V982, 1)); int sub__V1008_count = term__V982_count*LINK_COUNT(sub__V1008); permitUnusedInt(sub__V1008_count);
      CRSX_CHECK_SORT(sink__V981->context, sub__V1008, &sort_M_Reified_xVariable); /* sub__V1008 = &#0 */
      Term sub__V1009 = LINK(sink__V981->context, SUB(term__V982, 2)); int sub__V1009_count = term__V982_count*LINK_COUNT(sub__V1009); permitUnusedInt(sub__V1009_count);
      /* sub__V1009 = &#1 */
      NamedPropertyLink namedP__V1010 = LINK_NamedPropertyLink(sink__V981->context, NAMED_PROPERTIES(term__V982));
      VariablePropertyLink varP__V1011 = LINK_VariablePropertyLink(sink__V981->context, VARIABLE_PROPERTIES(term__V982));
      UNLINK(sink__V981->context, term__V982);
      ADD_PROPERTIES(sink__V981, LINK_NamedPropertyLink(sink__V981->context, namedP__V1010), LINK_VariablePropertyLink(sink__V981->context, varP__V1011));
      { START(sink__V981, _M_MapIndexText_s3);
        { if (!IS_BOUND(x__V1006)) { REBIND(x__V1006);
            REBIND(x__V1007);
            Variable binds__V1012[2] = {x__V1006,x__V1007}; BINDS(sink__V981, 2, binds__V1012);
            COPY(sink__V981, sub__V1008); /* REUSED SUBSTITUTION */  }
          else { Variable b__V1013 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V981->context,"b__V1013");
            Variable b__V1014 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V981->context,"b__V1014");
            Variable binds__V1015[2] = {b__V1013,b__V1014}; BINDS(sink__V981, 2, binds__V1015);
            {
              Term arg__V1016;
              { Sink buf__V1017 = ALLOCA_BUFFER(sink__V981->context);
                USE(buf__V1017, b__V1013); arg__V1016 = BUFFER_TERM(buf__V1017); FREE_BUFFER(buf__V1017); }
              Term arg__V1018;
              { Sink buf__V1019 = ALLOCA_BUFFER(sink__V981->context);
                USE(buf__V1019, b__V1014); arg__V1018 = BUFFER_TERM(buf__V1019); FREE_BUFFER(buf__V1019); }
              Variable vars__V1020[2] = {x__V1006,x__V1007};
              Term args__V1021[2] = {arg__V1016,arg__V1018};
              struct _SubstitutionFrame substitution__V1022 = {NULL, 0, 2, vars__V1020, args__V1021, NULL};
              SUBSTITUTE(sink__V981, sub__V1008, &substitution__V1022); }
                }
           }
        COPY(sink__V981, sub__V1009);END(sink__V981, _M_MapIndexText_s3); }
      UNLINK_NamedPropertyLink(sink__V981->context, namedP__V1010); UNLINK_VariablePropertyLink(sink__V981->context, varP__V1011);
      
      return 1;
    } default: break;
  }
  return 0;
}

/* FUNCTION MapIndexText$2. */
int conBindOffs_M_MapIndexText_s2[] = {0 , 0 , 0 , 2 , 2};
char *nameFun_M_MapIndexText_s2(Term term) { return  "MapIndexText$2" ; }
struct _ConstructionDescriptor descriptor_M_MapIndexText_s2 = {&sort_M_Reified_xVariable, 0, 4, sizeof(STRUCT_Con_M_MapIndexText_s2), conBindOffs_M_MapIndexText_s2, &nameFun_M_MapIndexText_s2, &step_M_MapIndexText_s2};

int step_M_MapIndexText_s2(Sink sink__V1023, Term term__V1024)
{
  int term__V1024_count = LINK_COUNT(term__V1024); permitUnusedInt(term__V1024_count);
  do {
    /* Contraction rule DEFS-MapIndexText-1. */
    ASSERT(sink__V1023->context, !strcmp(SYMBOL(term__V1024),  "MapIndexText$2" ));
    Term sub__V1025 = LINK(sink__V1023->context, SUB(term__V1024, 0)); int sub__V1025_count = term__V1024_count*LINK_COUNT(sub__V1025); permitUnusedInt(sub__V1025_count);
    /* sub__V1025 = &#21 */
    Term sub__V1026 = LINK(sink__V1023->context, SUB(term__V1024, 1)); int sub__V1026_count = term__V1024_count*LINK_COUNT(sub__V1026); permitUnusedInt(sub__V1026_count);
    /* sub__V1026 = &#22 */
    Variable x__V1027 = BINDER(term__V1024,2,0); if (term__V1024_count <= 1) UNBIND(x__V1027);
    Variable x__V1028 = BINDER(term__V1024,2,1); if (term__V1024_count <= 1) UNBIND(x__V1028);
    Term sub__V1029 = LINK(sink__V1023->context, SUB(term__V1024, 2)); int sub__V1029_count = term__V1024_count*LINK_COUNT(sub__V1029); permitUnusedInt(sub__V1029_count);
    CRSX_CHECK_SORT(sink__V1023->context, sub__V1029, &sort_M_Reified_xVariable); UNLINK_SUB(sink__V1023->context, term__V1024,  2); NORMALIZE(sink__V1023->context, sub__V1029); SUB(term__V1024,  2) = LINK(sink__V1023->context, sub__V1029);
    /* sub__V1029 = &#1 */
    Term sub__V1030 = LINK(sink__V1023->context, SUB(term__V1024, 3)); int sub__V1030_count = term__V1024_count*LINK_COUNT(sub__V1030); permitUnusedInt(sub__V1030_count);
    UNLINK_SUB(sink__V1023->context, term__V1024,  3); NORMALIZE(sink__V1023->context, sub__V1030); SUB(term__V1024,  3) = LINK(sink__V1023->context, sub__V1030);
    /* sub__V1030 = &#3 */
    NamedPropertyLink namedP__V1031 = LINK_NamedPropertyLink(sink__V1023->context, NAMED_PROPERTIES(term__V1024));
    VariablePropertyLink varP__V1032 = LINK_VariablePropertyLink(sink__V1023->context, VARIABLE_PROPERTIES(term__V1024));
    UNLINK(sink__V1023->context, term__V1024);
    { START(sink__V1023, _M__sTextCons);
      { START(sink__V1023, _M__sTextEmbed);
        { START(sink__V1023, _M_AsText);
          {
            Term arg__V1033;
            { Sink buf__V1034 = ALLOCA_BUFFER(sink__V1023->context);
              COPY(buf__V1034, sub__V1025);arg__V1033 = BUFFER_TERM(buf__V1034); FREE_BUFFER(buf__V1034); }
            Term arg__V1035;
            { Sink buf__V1036 = ALLOCA_BUFFER(sink__V1023->context);
              COPY(buf__V1036, LINK(buf__V1036->context, sub__V1030));arg__V1035 = BUFFER_TERM(buf__V1036); FREE_BUFFER(buf__V1036); }
            Variable vars__V1037[2] = {x__V1027,x__V1028};
            Term args__V1038[2] = {arg__V1033,arg__V1035};
            struct _SubstitutionFrame substitution__V1039 = {NULL, 0, 2, vars__V1037, args__V1038, NULL};
            SUBSTITUTE(sink__V1023, LINK(sink__V1023->context,sub__V1029), &substitution__V1039); }
          END(sink__V1023, _M_AsText); }
        END(sink__V1023, _M__sTextEmbed); }
      { START(sink__V1023, _M__sTextCons);
        { START(sink__V1023, _M__sTextEmbed);
          { START(sink__V1023, _M_AsText);
            { START(sink__V1023, _M_MapIndexText_s1);
              COPY(sink__V1023, sub__V1026);{ Variable x__V1040 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V1023->context,"x__V1040");
                Variable x__V1041 = MAKE_BOUND_PROMISCUOUS_VARIABLE(sink__V1023->context,"x__V1041");
                Variable binds__V1042[2] = {x__V1040,x__V1041}; BINDS(sink__V1023, 2, binds__V1042);
                {
                  Term arg__V1043;
                  { Sink buf__V1044 = ALLOCA_BUFFER(sink__V1023->context);
                    USE(buf__V1044, x__V1040); arg__V1043 = BUFFER_TERM(buf__V1044); FREE_BUFFER(buf__V1044); }
                  Term arg__V1045;
                  { Sink buf__V1046 = ALLOCA_BUFFER(sink__V1023->context);
                    USE(buf__V1046, x__V1041); arg__V1045 = BUFFER_TERM(buf__V1046); FREE_BUFFER(buf__V1046); }
                  Variable vars__V1047[2] = {x__V1027,x__V1028};
                  Term args__V1048[2] = {arg__V1043,arg__V1045};
                  struct _SubstitutionFrame substitution__V1049 = {NULL, 0, 2, vars__V1047, args__V1048, NULL};
                  SUBSTITUTE(sink__V1023, sub__V1029, &substitution__V1049); }
                 }
              { double num__V1050;
                num__V1050 = (double) 1; { double tmp__V1051;
                  tmp__V1051 = DOUBLE(sub__V1030); num__V1050 += tmp__V1051; }
                LITERALNF(sink__V1023, (size_t) 31, "%G", num__V1050); }
              END(sink__V1023, _M_MapIndexText_s1); }
            END(sink__V1023, _M_AsText); }
          END(sink__V1023, _M__sTextEmbed); }
        { START(sink__V1023, _M__sTextNil);
          END(sink__V1023, _M__sTextNil); }
        END(sink__V1023, _M__sTextCons); }
      END(sink__V1023, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V1023->context, namedP__V1031); UNLINK_VariablePropertyLink(sink__V1023->context, varP__V1032);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION MapIndexText$3. */
int conBindOffs_M_MapIndexText_s3[] = {0 , 2 , 2};
char *nameFun_M_MapIndexText_s3(Term term) { return  "MapIndexText$3" ; }
struct _ConstructionDescriptor descriptor_M_MapIndexText_s3 = {&sort_M_Reified_xVariable, 0, 2, sizeof(STRUCT_Con_M_MapIndexText_s3), conBindOffs_M_MapIndexText_s3, &nameFun_M_MapIndexText_s3, &step_M_MapIndexText_s3};

int step_M_MapIndexText_s3(Sink sink__V1052, Term term__V1053)
{
  int term__V1053_count = LINK_COUNT(term__V1053); permitUnusedInt(term__V1053_count);
  do {
    /* Contraction rule DEFS-MapIndexText-2. */
    ASSERT(sink__V1052->context, !strcmp(SYMBOL(term__V1053),  "MapIndexText$3" ));
    Variable x__V1054 = BINDER(term__V1053,0,0); if (term__V1053_count <= 1) UNBIND(x__V1054);
    Variable x__V1055 = BINDER(term__V1053,0,1); if (term__V1053_count <= 1) UNBIND(x__V1055);
    Term sub__V1056 = SUB(term__V1053, 0); permitUnusedTerm(sub__V1056); int sub__V1056_count = term__V1053_count*LINK_COUNT(sub__V1056); permitUnusedInt(sub__V1056_count);
    CRSX_CHECK_SORT(sink__V1052->context, sub__V1056, &sort_M_Reified_xVariable); /* sub__V1056 = &#1 */
    Term sub__V1057 = SUB(term__V1053, 1); permitUnusedTerm(sub__V1057); int sub__V1057_count = term__V1053_count*LINK_COUNT(sub__V1057); permitUnusedInt(sub__V1057_count);
    /* sub__V1057 = &#3 */
    NamedPropertyLink namedP__V1058 = LINK_NamedPropertyLink(sink__V1052->context, NAMED_PROPERTIES(term__V1053));
    VariablePropertyLink varP__V1059 = LINK_VariablePropertyLink(sink__V1052->context, VARIABLE_PROPERTIES(term__V1053));
    UNLINK(sink__V1052->context, term__V1053);
    { START(sink__V1052, _M__sTextNil);
      END(sink__V1052, _M__sTextNil); }
    UNLINK_NamedPropertyLink(sink__V1052->context, namedP__V1058); UNLINK_VariablePropertyLink(sink__V1052->context, varP__V1059);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DTOKEN$1. */
int conBindOffs_M_DTOKEN_s1[] = {0 , 0};
char *nameFun_M_DTOKEN_s1(Term term) { return  "DTOKEN$1" ; }
struct _ConstructionDescriptor descriptor_M_DTOKEN_s1 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_DTOKEN_s1), conBindOffs_M_DTOKEN_s1, &nameFun_M_DTOKEN_s1, &step_M_DTOKEN_s1};

int step_M_DTOKEN_s1(Sink sink__V1060, Term term__V1061)
{
  int term__V1061_count = LINK_COUNT(term__V1061); permitUnusedInt(term__V1061_count);
  do {
    /* Contraction rule DEFS-DTOKEN-1. */
    ASSERT(sink__V1060->context, !strcmp(SYMBOL(term__V1061),  "DTOKEN$1" ));
    Term sub__V1062 = LINK(sink__V1060->context, SUB(term__V1061, 0)); int sub__V1062_count = term__V1061_count*LINK_COUNT(sub__V1062); permitUnusedInt(sub__V1062_count);
    UNLINK_SUB(sink__V1060->context, term__V1061,  0); NORMALIZE(sink__V1060->context, sub__V1062); SUB(term__V1061,  0) = LINK(sink__V1060->context, sub__V1062);
    /* sub__V1062 = &#2 */
    NamedPropertyLink namedP__V1063 = LINK_NamedPropertyLink(sink__V1060->context, NAMED_PROPERTIES(term__V1061));
    VariablePropertyLink varP__V1064 = LINK_VariablePropertyLink(sink__V1060->context, VARIABLE_PROPERTIES(term__V1061));
    UNLINK(sink__V1060->context, term__V1061);
    { START(sink__V1060, _M__sTextCons);
      { START(sink__V1060, _M__sTextChars);
        COPY(sink__V1060, sub__V1062);END(sink__V1060, _M__sTextChars); }
      { START(sink__V1060, _M__sTextNil);
        END(sink__V1060, _M__sTextNil); }
      END(sink__V1060, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V1060->context, namedP__V1063); UNLINK_VariablePropertyLink(sink__V1060->context, varP__V1064);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Descriptor. */
int conBindOffs_M_Descriptor[] = {0 , 0};
char *nameFun_M_Descriptor(Term term) { return  "Descriptor" ; }
struct _ConstructionDescriptor descriptor_M_Descriptor = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_Descriptor), conBindOffs_M_Descriptor, &nameFun_M_Descriptor, &step_M_Descriptor};

int step_M_Descriptor(Sink sink__V1065, Term term__V1066)
{
  int term__V1066_count = LINK_COUNT(term__V1066); permitUnusedInt(term__V1066_count);
  do {
    /* Contraction rule DEFS-Descriptor-1. */
    ASSERT(sink__V1065->context, !strcmp(SYMBOL(term__V1066),  "Descriptor" ));
    Term sub__V1067 = LINK(sink__V1065->context, SUB(term__V1066, 0)); int sub__V1067_count = term__V1066_count*LINK_COUNT(sub__V1067); permitUnusedInt(sub__V1067_count);
    /* sub__V1067 = &#1 */
    NamedPropertyLink namedP__V1068 = LINK_NamedPropertyLink(sink__V1065->context, NAMED_PROPERTIES(term__V1066));
    VariablePropertyLink varP__V1069 = LINK_VariablePropertyLink(sink__V1065->context, VARIABLE_PROPERTIES(term__V1066));
    UNLINK(sink__V1065->context, term__V1066);
    { START(sink__V1065, _M__sTextCons);
      { START(sink__V1065, _M__sTextChars);
        LITERAL(sink__V1065,  "descriptor" ); END(sink__V1065, _M__sTextChars); }
      { START(sink__V1065, _M__sTextCons);
        { START(sink__V1065, _M__sTextEmbed);
          { START(sink__V1065, _M_AsText);
            { START(sink__V1065, _M_MANGLE);
              COPY(sink__V1065, sub__V1067);END(sink__V1065, _M_MANGLE); }
            END(sink__V1065, _M_AsText); }
          END(sink__V1065, _M__sTextEmbed); }
        { START(sink__V1065, _M__sTextNil);
          END(sink__V1065, _M__sTextNil); }
        END(sink__V1065, _M__sTextCons); }
      END(sink__V1065, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V1065->context, namedP__V1068); UNLINK_VariablePropertyLink(sink__V1065->context, varP__V1069);
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Forms-Constructors$1. */
int conBindOffs_M_Forms_Constructors_s1[] = {0 , 0 , 0};
char *nameFun_M_Forms_Constructors_s1(Term term) { return  "Forms-Constructors$1" ; }
struct _ConstructionDescriptor descriptor_M_Forms_Constructors_s1 = {NULL, 0, 2, sizeof(STRUCT_Con_M_Forms_Constructors_s1), conBindOffs_M_Forms_Constructors_s1, &nameFun_M_Forms_Constructors_s1, &step_M_Forms_Constructors_s1};

int step_M_Forms_Constructors_s1(Sink sink__V1070, Term term__V1071)
{
  int term__V1071_count = LINK_COUNT(term__V1071); permitUnusedInt(term__V1071_count);
  do {
    /* Contraction rule DEFS-Forms-Constructors-1$Forms-Constructors$1$SORT-ALLOWS-VARIABLES. */
    ASSERT(sink__V1070->context, !strcmp(SYMBOL(term__V1071),  "Forms-Constructors$1" ));
    Term sub__V1072 = SUB(term__V1071, 0); permitUnusedTerm(sub__V1072); int sub__V1072_count = term__V1071_count*LINK_COUNT(sub__V1072); permitUnusedInt(sub__V1072_count);
    FORCE(sink__V1070->context, sub__V1072); SUB(term__V1071, 0) = sub__V1072;
    if (strcmp(SYMBOL(sub__V1072),  "SORT-ALLOWS-VARIABLES" )) break;
    Term sub__V1073 = LINK(sink__V1070->context, SUB(term__V1071, 1)); int sub__V1073_count = term__V1071_count*LINK_COUNT(sub__V1073); permitUnusedInt(sub__V1073_count);
    /* sub__V1073 = &#0 */
    NamedPropertyLink namedP__V1074 = LINK_NamedPropertyLink(sink__V1070->context, NAMED_PROPERTIES(term__V1071));
    VariablePropertyLink varP__V1075 = LINK_VariablePropertyLink(sink__V1070->context, VARIABLE_PROPERTIES(term__V1071));
    UNLINK(sink__V1070->context, term__V1071);
    ADD_PROPERTIES(sink__V1070, LINK_NamedPropertyLink(sink__V1070->context, namedP__V1074), LINK_VariablePropertyLink(sink__V1070->context, varP__V1075));
    { START(sink__V1070, _M_Forms_Constructors_s3);
      COPY(sink__V1070, sub__V1073);END(sink__V1070, _M_Forms_Constructors_s3); }
    UNLINK_NamedPropertyLink(sink__V1070->context, namedP__V1074); UNLINK_VariablePropertyLink(sink__V1070->context, varP__V1075);
    
    return 1;
  } while (0);
  do {
    /* Contraction rule DEFS-Forms-Constructors-2$Forms-Constructors$1$SORT-SET. */
    ASSERT(sink__V1070->context, !strcmp(SYMBOL(term__V1071),  "Forms-Constructors$1" ));
    Term sub__V1076 = SUB(term__V1071, 0); permitUnusedTerm(sub__V1076); int sub__V1076_count = term__V1071_count*LINK_COUNT(sub__V1076); permitUnusedInt(sub__V1076_count);
    FORCE(sink__V1070->context, sub__V1076); SUB(term__V1071, 0) = sub__V1076;
    if (strcmp(SYMBOL(sub__V1076),  "SORT-SET" )) break;
    Term sub__V1077 = LINK(sink__V1070->context, SUB(sub__V1076, 0)); int sub__V1077_count = sub__V1076_count*LINK_COUNT(sub__V1077); permitUnusedInt(sub__V1077_count);
    CRSX_CHECK_SORT(sink__V1070->context, sub__V1077, &sort_M_Reified_xSort); /* sub__V1077 = &#0-0 */
    Term sub__V1078 = LINK(sink__V1070->context, SUB(sub__V1076, 1)); int sub__V1078_count = sub__V1076_count*LINK_COUNT(sub__V1078); permitUnusedInt(sub__V1078_count);
    CRSX_CHECK_SORT(sink__V1070->context, sub__V1078, &sort_M_Reified_xSort); /* sub__V1078 = &#0-1 */
    Term sub__V1079 = LINK(sink__V1070->context, SUB(sub__V1076, 2)); int sub__V1079_count = sub__V1076_count*LINK_COUNT(sub__V1079); permitUnusedInt(sub__V1079_count);
    CRSX_CHECK_SORT(sink__V1070->context, sub__V1079, &sort_M_Reified_xForm); /* sub__V1079 = &#0-2 */
    Term sub__V1080 = LINK(sink__V1070->context, SUB(term__V1071, 1)); int sub__V1080_count = term__V1071_count*LINK_COUNT(sub__V1080); permitUnusedInt(sub__V1080_count);
    /* sub__V1080 = &#3 */
    NamedPropertyLink namedP__V1081 = LINK_NamedPropertyLink(sink__V1070->context, NAMED_PROPERTIES(term__V1071));
    VariablePropertyLink varP__V1082 = LINK_VariablePropertyLink(sink__V1070->context, VARIABLE_PROPERTIES(term__V1071));
    UNLINK(sink__V1070->context, term__V1071);
    ADD_PROPERTIES(sink__V1070, LINK_NamedPropertyLink(sink__V1070->context, namedP__V1081), LINK_VariablePropertyLink(sink__V1070->context, varP__V1082));
    { START(sink__V1070, _M_Forms_Constructors_s4);
      COPY(sink__V1070, sub__V1077);COPY(sink__V1070, sub__V1078);COPY(sink__V1070, sub__V1079);COPY(sink__V1070, sub__V1080);END(sink__V1070, _M_Forms_Constructors_s4); }
    UNLINK_NamedPropertyLink(sink__V1070->context, namedP__V1081); UNLINK_VariablePropertyLink(sink__V1070->context, varP__V1082);
    
    return 1;
  } while (0);
  do {
    /* Contraction rule DEFS-Forms-Constructors-3$Forms-Constructors$1$FORM. */
    ASSERT(sink__V1070->context, !strcmp(SYMBOL(term__V1071),  "Forms-Constructors$1" ));
    Term sub__V1083 = SUB(term__V1071, 0); permitUnusedTerm(sub__V1083); int sub__V1083_count = term__V1071_count*LINK_COUNT(sub__V1083); permitUnusedInt(sub__V1083_count);
    FORCE(sink__V1070->context, sub__V1083); SUB(term__V1071, 0) = sub__V1083;
    if (strcmp(SYMBOL(sub__V1083),  "FORM" )) break;
    Term sub__V1084 = LINK(sink__V1070->context, SUB(sub__V1083, 0)); int sub__V1084_count = sub__V1083_count*LINK_COUNT(sub__V1084); permitUnusedInt(sub__V1084_count);
    /* sub__V1084 = &#0-0 */
    Term sub__V1085 = LINK(sink__V1070->context, SUB(sub__V1083, 1)); int sub__V1085_count = sub__V1083_count*LINK_COUNT(sub__V1085); permitUnusedInt(sub__V1085_count);
    /* sub__V1085 = &#0-1 */
    Term sub__V1086 = LINK(sink__V1070->context, SUB(term__V1071, 1)); int sub__V1086_count = term__V1071_count*LINK_COUNT(sub__V1086); permitUnusedInt(sub__V1086_count);
    /* sub__V1086 = &#2 */
    NamedPropertyLink namedP__V1087 = LINK_NamedPropertyLink(sink__V1070->context, NAMED_PROPERTIES(term__V1071));
    VariablePropertyLink varP__V1088 = LINK_VariablePropertyLink(sink__V1070->context, VARIABLE_PROPERTIES(term__V1071));
    UNLINK(sink__V1070->context, term__V1071);
    ADD_PROPERTIES(sink__V1070, LINK_NamedPropertyLink(sink__V1070->context, namedP__V1087), LINK_VariablePropertyLink(sink__V1070->context, varP__V1088));
    { START(sink__V1070, _M_Forms_Constructors_s2);
      COPY(sink__V1070, sub__V1084);COPY(sink__V1070, sub__V1085);COPY(sink__V1070, sub__V1086);END(sink__V1070, _M_Forms_Constructors_s2); }
    UNLINK_NamedPropertyLink(sink__V1070->context, namedP__V1087); UNLINK_VariablePropertyLink(sink__V1070->context, varP__V1088);
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Forms-Constructors$2. */
int conBindOffs_M_Forms_Constructors_s2[] = {0 , 0 , 0 , 0};
char *nameFun_M_Forms_Constructors_s2(Term term) { return  "Forms-Constructors$2" ; }
struct _ConstructionDescriptor descriptor_M_Forms_Constructors_s2 = {NULL, 0, 3, sizeof(STRUCT_Con_M_Forms_Constructors_s2), conBindOffs_M_Forms_Constructors_s2, &nameFun_M_Forms_Constructors_s2, &step_M_Forms_Constructors_s2};

int step_M_Forms_Constructors_s2(Sink sink__V1089, Term term__V1090)
{
  int term__V1090_count = LINK_COUNT(term__V1090); permitUnusedInt(term__V1090_count);
  do {
    /* Contraction rule DEFS-Forms-Constructors-3. */
    ASSERT(sink__V1089->context, !strcmp(SYMBOL(term__V1090),  "Forms-Constructors$2" ));
    Term sub__V1091 = LINK(sink__V1089->context, SUB(term__V1090, 0)); int sub__V1091_count = term__V1090_count*LINK_COUNT(sub__V1091); permitUnusedInt(sub__V1091_count);
    /* sub__V1091 = &#111 */
    Term sub__V1092 = SUB(term__V1090, 1); permitUnusedTerm(sub__V1092); int sub__V1092_count = term__V1090_count*LINK_COUNT(sub__V1092); permitUnusedInt(sub__V1092_count);
    /* sub__V1092 = &#112 */
    Term sub__V1093 = LINK(sink__V1089->context, SUB(term__V1090, 2)); int sub__V1093_count = term__V1090_count*LINK_COUNT(sub__V1093); permitUnusedInt(sub__V1093_count);
    /* sub__V1093 = &#12 */
    UNLINK(sink__V1089->context, term__V1090);
    { START(sink__V1089, _M__sCons);
      COPY(sink__V1089, sub__V1091);{ START(sink__V1089, _M_Forms_Constructors);
        COPY(sink__V1089, sub__V1093);END(sink__V1089, _M_Forms_Constructors); }
      END(sink__V1089, _M__sCons); }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Forms-Constructors$3. */
int conBindOffs_M_Forms_Constructors_s3[] = {0 , 0};
char *nameFun_M_Forms_Constructors_s3(Term term) { return  "Forms-Constructors$3" ; }
struct _ConstructionDescriptor descriptor_M_Forms_Constructors_s3 = {NULL, 0, 1, sizeof(STRUCT_Con_M_Forms_Constructors_s3), conBindOffs_M_Forms_Constructors_s3, &nameFun_M_Forms_Constructors_s3, &step_M_Forms_Constructors_s3};

int step_M_Forms_Constructors_s3(Sink sink__V1094, Term term__V1095)
{
  int term__V1095_count = LINK_COUNT(term__V1095); permitUnusedInt(term__V1095_count);
  do {
    /* Contraction rule DEFS-Forms-Constructors-1. */
    ASSERT(sink__V1094->context, !strcmp(SYMBOL(term__V1095),  "Forms-Constructors$3" ));
    Term sub__V1096 = LINK(sink__V1094->context, SUB(term__V1095, 0)); int sub__V1096_count = term__V1095_count*LINK_COUNT(sub__V1096); permitUnusedInt(sub__V1096_count);
    /* sub__V1096 = &#12 */
    UNLINK(sink__V1094->context, term__V1095);
    { START(sink__V1094, _M_Forms_Constructors);
      COPY(sink__V1094, sub__V1096);END(sink__V1094, _M_Forms_Constructors); }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Forms-Constructors$4. */
int conBindOffs_M_Forms_Constructors_s4[] = {0 , 0 , 0 , 0 , 0};
char *nameFun_M_Forms_Constructors_s4(Term term) { return  "Forms-Constructors$4" ; }
struct _ConstructionDescriptor descriptor_M_Forms_Constructors_s4 = {NULL, 0, 4, sizeof(STRUCT_Con_M_Forms_Constructors_s4), conBindOffs_M_Forms_Constructors_s4, &nameFun_M_Forms_Constructors_s4, &step_M_Forms_Constructors_s4};

int step_M_Forms_Constructors_s4(Sink sink__V1097, Term term__V1098)
{
  int term__V1098_count = LINK_COUNT(term__V1098); permitUnusedInt(term__V1098_count);
  do {
    /* Contraction rule DEFS-Forms-Constructors-2. */
    ASSERT(sink__V1097->context, !strcmp(SYMBOL(term__V1098),  "Forms-Constructors$4" ));
    Term sub__V1099 = SUB(term__V1098, 0); permitUnusedTerm(sub__V1099); int sub__V1099_count = term__V1098_count*LINK_COUNT(sub__V1099); permitUnusedInt(sub__V1099_count);
    CRSX_CHECK_SORT(sink__V1097->context, sub__V1099, &sort_M_Reified_xSort); /* sub__V1099 = &#111 */
    Term sub__V1100 = SUB(term__V1098, 1); permitUnusedTerm(sub__V1100); int sub__V1100_count = term__V1098_count*LINK_COUNT(sub__V1100); permitUnusedInt(sub__V1100_count);
    CRSX_CHECK_SORT(sink__V1097->context, sub__V1100, &sort_M_Reified_xSort); /* sub__V1100 = &#112 */
    Term sub__V1101 = LINK(sink__V1097->context, SUB(term__V1098, 2)); int sub__V1101_count = term__V1098_count*LINK_COUNT(sub__V1101); permitUnusedInt(sub__V1101_count);
    CRSX_CHECK_SORT(sink__V1097->context, sub__V1101, &sort_M_Reified_xForm); /* sub__V1101 = &#113 */
    Term sub__V1102 = LINK(sink__V1097->context, SUB(term__V1098, 3)); int sub__V1102_count = term__V1098_count*LINK_COUNT(sub__V1102); permitUnusedInt(sub__V1102_count);
    /* sub__V1102 = &#12 */
    UNLINK(sink__V1097->context, term__V1098);
    { START(sink__V1097, _M_Forms_Constructors);
      { START(sink__V1097, _M__sCons);
        COPY(sink__V1097, sub__V1101);COPY(sink__V1097, sub__V1102);END(sink__V1097, _M__sCons); }
      END(sink__V1097, _M_Forms_Constructors); }
    
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION Forms-Constructors$5. */
int conBindOffs_M_Forms_Constructors_s5[] = {0};
char *nameFun_M_Forms_Constructors_s5(Term term) { return  "Forms-Constructors$5" ; }
struct _ConstructionDescriptor descriptor_M_Forms_Constructors_s5 = {NULL, 0, 0, sizeof(STRUCT_Con_M_Forms_Constructors_s5), conBindOffs_M_Forms_Constructors_s5, &nameFun_M_Forms_Constructors_s5, &step_M_Forms_Constructors_s5};

int step_M_Forms_Constructors_s5(Sink sink__V1103, Term term__V1104)
{
  int term__V1104_count = LINK_COUNT(term__V1104); permitUnusedInt(term__V1104_count);
  do {
    /* Contraction rule DEFS-Forms-Constructors-4. */
    ASSERT(sink__V1103->context, !strcmp(SYMBOL(term__V1104),  "Forms-Constructors$5" ));
    UNLINK(sink__V1103->context, term__V1104);
    { START(sink__V1103, _M__sNil); END(sink__V1103, _M__sNil); } 
    return 1;
  } while (0);
  return 0;
}

/* FUNCTION DMANGLE$1. */
int conBindOffs_M_DMANGLE_s1[] = {0 , 0};
char *nameFun_M_DMANGLE_s1(Term term) { return  "DMANGLE$1" ; }
struct _ConstructionDescriptor descriptor_M_DMANGLE_s1 = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_DMANGLE_s1), conBindOffs_M_DMANGLE_s1, &nameFun_M_DMANGLE_s1, &step_M_DMANGLE_s1};

int step_M_DMANGLE_s1(Sink sink__V1105, Term term__V1106)
{
  int term__V1106_count = LINK_COUNT(term__V1106); permitUnusedInt(term__V1106_count);
  do {
    /* Contraction rule DEFS-DMANGLE-1. */
    ASSERT(sink__V1105->context, !strcmp(SYMBOL(term__V1106),  "DMANGLE$1" ));
    Term sub__V1107 = LINK(sink__V1105->context, SUB(term__V1106, 0)); int sub__V1107_count = term__V1106_count*LINK_COUNT(sub__V1107); permitUnusedInt(sub__V1107_count);
    UNLINK_SUB(sink__V1105->context, term__V1106,  0); NORMALIZE(sink__V1105->context, sub__V1107); SUB(term__V1106,  0) = LINK(sink__V1105->context, sub__V1107);
    /* sub__V1107 = &#2 */
    NamedPropertyLink namedP__V1108 = LINK_NamedPropertyLink(sink__V1105->context, NAMED_PROPERTIES(term__V1106));
    VariablePropertyLink varP__V1109 = LINK_VariablePropertyLink(sink__V1105->context, VARIABLE_PROPERTIES(term__V1106));
    UNLINK(sink__V1105->context, term__V1106);
    { START(sink__V1105, _M__sTextCons);
      { START(sink__V1105, _M__sTextChars);
        { char *str__V1110;
          FORCE(sink__V1105->context, sub__V1107);
          { char *s__V1111 = makeMangled(sink__V1105->context, SYMBOL(sub__V1107));
            { size_t z__V1112 = strlen(s__V1111) + 1; memcpy(str__V1110 = ALLOCATE(sink__V1105->context, z__V1112), s__V1111, z__V1112);  UNLINK(sink__V1105->context, sub__V1107);}
            }
          LITERALU(sink__V1105, str__V1110); }
        END(sink__V1105, _M__sTextChars); }
      { START(sink__V1105, _M__sTextNil);
        END(sink__V1105, _M__sTextNil); }
      END(sink__V1105, _M__sTextCons); }
    UNLINK_NamedPropertyLink(sink__V1105->context, namedP__V1108); UNLINK_VariablePropertyLink(sink__V1105->context, varP__V1109);
    return 1;
  } while (0);
  return 0;
}

#ifdef __cplusplus
}
#endif
/* END OF C RULES FOR CRSX CRSXC MODULE D. */
