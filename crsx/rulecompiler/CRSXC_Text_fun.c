/* C RULES FOR CRSX CRSXC MODULE Text. */
#include "CRSXC.h" 
#ifdef __cplusplus
extern "C" {
#endif

/* FUNCTION AsText. */
int conBindOffs_M_AsText[] = {0 , 0};
char *nameFun_M_AsText(Term term) { return  "AsText" ; }
struct _ConstructionDescriptor descriptor_M_AsText = {&sort_M_Reified_xVariable, 0, 1, sizeof(STRUCT_Con_M_AsText), conBindOffs_M_AsText, &nameFun_M_AsText, &step_M_AsText};

int step_M_AsText(Sink sink__V1, Term term__V2)
{
  int term__V2_count = LINK_COUNT(term__V2); permitUnusedInt(term__V2_count);
  do {
    /* Contraction rule Text-AsText-1. */
    ASSERT(sink__V1->context, !strcmp(SYMBOL(term__V2),  "AsText" ));
    Term sub__V3 = LINK(sink__V1->context, SUB(term__V2, 0)); int sub__V3_count = term__V2_count*LINK_COUNT(sub__V3); permitUnusedInt(sub__V3_count);
    /* sub__V3 = &#1 */
    
    NamedPropertyLink namedP__V4 = LINK_NamedPropertyLink(sink__V1->context, NAMED_PROPERTIES(term__V2));
    VariablePropertyLink varP__V5 = LINK_VariablePropertyLink(sink__V1->context, VARIABLE_PROPERTIES(term__V2));
    Hashset namedFV__V6 = LINK_VARIABLESET(sink__V1->context, namedPropertyFreeVars(namedP__V4));
    Hashset varFV__V7 = LINK_VARIABLESET(sink__V1->context, variablePropertyFreeVars(varP__V5));
    UNLINK(sink__V1->context, term__V2);
    COPY(sink__V1, sub__V3);UNLINK_VARIABLESET(sink__V1->context, namedFV__V6); UNLINK_VARIABLESET(sink__V1->context, varFV__V7);
    UNLINK_NamedPropertyLink(sink__V1->context, namedP__V4); UNLINK_VariablePropertyLink(sink__V1->context, varP__V5);
    return 1;
  } while (0);
  return 0;
}

#ifdef __cplusplus
}
#endif
/* END OF C RULES FOR CRSX CRSXC MODULE Text. */
