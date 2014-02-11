 /* C SORT DESCRIPTORS FOR CRSX Cook. */
#include "Cook.h"

#ifdef __cplusplus
extern "C" {
#endif

/* SORT $Boolean CONSTANTS. */
char *name_M__sFalse =  "$False" ;
char *nameFun_M__sFalse(Term term) { return name_M__sFalse; }
struct _ConstructionDescriptor descriptor_M__sFalse = {&sort_M__sBoolean, Data_M__sFalse, 0, sizeof(STRUCT_Con_M__sFalse), noBinderOffsets, &nameFun_M__sFalse, &dataStep};
char *name_M__sTrue =  "$True" ;
char *nameFun_M__sTrue(Term term) { return name_M__sTrue; }
struct _ConstructionDescriptor descriptor_M__sTrue = {&sort_M__sBoolean, Data_M__sTrue, 0, sizeof(STRUCT_Con_M__sTrue), noBinderOffsets, &nameFun_M__sTrue, &dataStep};
ConstructionDescriptor sortCon_M__sBoolean[] = {NULL, NULL, &descriptor_M__sFalse, &descriptor_M__sTrue,  NULL};
char *sortNam_M__sBoolean[] = {NULL, NULL,  "$False" ,  "$True" ,  NULL};
char *sortInt_M__sBoolean[] = {NULL, NULL, "_M__sFalse", "_M__sTrue",  NULL};
struct _SortDescriptor sort_M__sBoolean = { "$Boolean" , sortCon_M__sBoolean, sortNam_M__sBoolean, sortInt_M__sBoolean, NULL};

/* SORT $List CONSTANTS. */
char *name_M__sNil =  "$Nil" ;
char *nameFun_M__sNil(Term term) { return name_M__sNil; }
struct _ConstructionDescriptor descriptor_M__sNil = {&sort_M__sList, Data_M__sNil, 0, sizeof(STRUCT_Con_M__sNil), noBinderOffsets, &nameFun_M__sNil, &dataStep};
int conBindOffs_M__sCons[] = {0 , 0 , 0};
char *name_M__sCons =  "$Cons" ;
char *nameFun_M__sCons(Term term) { return name_M__sCons; }
struct _ConstructionDescriptor descriptor_M__sCons = {&sort_M__sList, Data_M__sCons, 2, sizeof(STRUCT_Con_M__sCons), conBindOffs_M__sCons, &nameFun_M__sCons, &dataStep};
ConstructionDescriptor sortCon_M__sList[] = {NULL, NULL, &descriptor_M__sNil, &descriptor_M__sCons,  NULL};
char *sortNam_M__sList[] = {NULL, NULL,  "$Nil" ,  "$Cons" ,  NULL};
char *sortInt_M__sList[] = {NULL, NULL, "_M__sNil", "_M__sCons",  NULL};
struct _SortDescriptor sort_M__sList = { "$List" , sortCon_M__sList, sortNam_M__sList, sortInt_M__sList, NULL};

/* SORT $StringEntrySort CONSTANTS. */
int conBindOffs_M_STRING[] = {0 , 0};
char *name_M_STRING =  "STRING" ;
char *nameFun_M_STRING(Term term) { return name_M_STRING; }
struct _ConstructionDescriptor descriptor_M_STRING = {&sort_M__sStringEntrySort, Data_M_STRING, 1, sizeof(STRUCT_Con_M_STRING), conBindOffs_M_STRING, &nameFun_M_STRING, &dataStep};
ConstructionDescriptor sortCon_M__sStringEntrySort[] = {NULL, NULL, &descriptor_M_STRING,  NULL};
char *sortNam_M__sStringEntrySort[] = {NULL, NULL,  "STRING" ,  NULL};
char *sortInt_M__sStringEntrySort[] = {NULL, NULL, "_M_STRING",  NULL};
struct _SortDescriptor sort_M__sStringEntrySort = { "$StringEntrySort" , sortCon_M__sStringEntrySort, sortNam_M__sStringEntrySort, sortInt_M__sStringEntrySort, NULL};

/* SORT $TryResult CONSTANTS. */
int conBindOffs_M__sTrySuccess[] = {0 , 0};
char *name_M__sTrySuccess =  "$TrySuccess" ;
char *nameFun_M__sTrySuccess(Term term) { return name_M__sTrySuccess; }
struct _ConstructionDescriptor descriptor_M__sTrySuccess = {&sort_M__sTryResult, Data_M__sTrySuccess, 1, sizeof(STRUCT_Con_M__sTrySuccess), conBindOffs_M__sTrySuccess, &nameFun_M__sTrySuccess, &dataStep};
int conBindOffs_M__sTryFailure[] = {0 , 0};
char *name_M__sTryFailure =  "$TryFailure" ;
char *nameFun_M__sTryFailure(Term term) { return name_M__sTryFailure; }
struct _ConstructionDescriptor descriptor_M__sTryFailure = {&sort_M__sTryResult, Data_M__sTryFailure, 1, sizeof(STRUCT_Con_M__sTryFailure), conBindOffs_M__sTryFailure, &nameFun_M__sTryFailure, &dataStep};
ConstructionDescriptor sortCon_M__sTryResult[] = {NULL, NULL, &descriptor_M__sTrySuccess, &descriptor_M__sTryFailure,  NULL};
char *sortNam_M__sTryResult[] = {NULL, NULL,  "$TrySuccess" ,  "$TryFailure" ,  NULL};
char *sortInt_M__sTryResult[] = {NULL, NULL, "_M__sTrySuccess", "_M__sTryFailure",  NULL};
struct _SortDescriptor sort_M__sTryResult = { "$TryResult" , sortCon_M__sTryResult, sortNam_M__sTryResult, sortInt_M__sTryResult, NULL};

/* SORT ATTRIBUTE_MAP CONSTANTS. */
char *name_M_AM =  "AM" ;
char *nameFun_M_AM(Term term) { return name_M_AM; }
struct _ConstructionDescriptor descriptor_M_AM = {&sort_M_ATTRIBUTE_xMAP, Data_M_AM, 0, sizeof(STRUCT_Con_M_AM), noBinderOffsets, &nameFun_M_AM, &dataStep};
ConstructionDescriptor sortCon_M_ATTRIBUTE_xMAP[] = {NULL, NULL, &descriptor_M_AM,  NULL};
char *sortNam_M_ATTRIBUTE_xMAP[] = {NULL, NULL,  "AM" ,  NULL};
char *sortInt_M_ATTRIBUTE_xMAP[] = {NULL, NULL, "_M_AM",  NULL};
struct _SortDescriptor sort_M_ATTRIBUTE_xMAP = { "ATTRIBUTE_MAP" , sortCon_M_ATTRIBUTE_xMAP, sortNam_M_ATTRIBUTE_xMAP, sortInt_M_ATTRIBUTE_xMAP, NULL};

/* SORT Boolean CONSTANTS. */
char *name_M_B_xTRUE =  "B_TRUE" ;
char *nameFun_M_B_xTRUE(Term term) { return name_M_B_xTRUE; }
struct _ConstructionDescriptor descriptor_M_B_xTRUE = {&sort_M_Boolean, Data_M_B_xTRUE, 0, sizeof(STRUCT_Con_M_B_xTRUE), noBinderOffsets, &nameFun_M_B_xTRUE, &dataStep};
char *name_M_B_xFALSE =  "B_FALSE" ;
char *nameFun_M_B_xFALSE(Term term) { return name_M_B_xFALSE; }
struct _ConstructionDescriptor descriptor_M_B_xFALSE = {&sort_M_Boolean, Data_M_B_xFALSE, 0, sizeof(STRUCT_Con_M_B_xFALSE), noBinderOffsets, &nameFun_M_B_xFALSE, &dataStep};
ConstructionDescriptor sortCon_M_Boolean[] = {NULL, NULL, &descriptor_M_B_xTRUE, &descriptor_M_B_xFALSE,  NULL};
char *sortNam_M_Boolean[] = {NULL, NULL,  "B_TRUE" ,  "B_FALSE" ,  NULL};
char *sortInt_M_Boolean[] = {NULL, NULL, "_M_B_xTRUE", "_M_B_xFALSE",  NULL};
struct _SortDescriptor sort_M_Boolean = { "Boolean" , sortCon_M_Boolean, sortNam_M_Boolean, sortInt_M_Boolean, NULL};

/* SORT CONSUMPTION_SORT CONSTANTS. */
int conBindOffs_M_C_xBUFFER[] = {0 , 0 , 0};
char *name_M_C_xBUFFER =  "C_BUFFER" ;
char *nameFun_M_C_xBUFFER(Term term) { return name_M_C_xBUFFER; }
struct _ConstructionDescriptor descriptor_M_C_xBUFFER = {&sort_M_CONSUMPTION_xSORT, Data_M_C_xBUFFER, 2, sizeof(STRUCT_Con_M_C_xBUFFER), conBindOffs_M_C_xBUFFER, &nameFun_M_C_xBUFFER, &dataStep};
int conBindOffs_M_C_xLEFTRECURSIVE[] = {0 , 0 , 0};
char *name_M_C_xLEFTRECURSIVE =  "C_LEFTRECURSIVE" ;
char *nameFun_M_C_xLEFTRECURSIVE(Term term) { return name_M_C_xLEFTRECURSIVE; }
struct _ConstructionDescriptor descriptor_M_C_xLEFTRECURSIVE = {&sort_M_CONSUMPTION_xSORT, Data_M_C_xLEFTRECURSIVE, 2, sizeof(STRUCT_Con_M_C_xLEFTRECURSIVE), conBindOffs_M_C_xLEFTRECURSIVE, &nameFun_M_C_xLEFTRECURSIVE, &dataStep};
ConstructionDescriptor sortCon_M_CONSUMPTION_xSORT[] = {NULL, NULL, &descriptor_M_C_xBUFFER, &descriptor_M_C_xLEFTRECURSIVE,  NULL};
char *sortNam_M_CONSUMPTION_xSORT[] = {NULL, NULL,  "C_BUFFER" ,  "C_LEFTRECURSIVE" ,  NULL};
char *sortInt_M_CONSUMPTION_xSORT[] = {NULL, NULL, "_M_C_xBUFFER", "_M_C_xLEFTRECURSIVE",  NULL};
struct _SortDescriptor sort_M_CONSUMPTION_xSORT = { "CONSUMPTION_SORT" , sortCon_M_CONSUMPTION_xSORT, sortNam_M_CONSUMPTION_xSORT, sortInt_M_CONSUMPTION_xSORT, NULL};

/* SORT DERIVED_SORT CONSTANTS. */
int conBindOffs_M_DERIVED[] = {0 , 0 , 0 , 0};
char *name_M_DERIVED =  "DERIVED" ;
char *nameFun_M_DERIVED(Term term) { return name_M_DERIVED; }
struct _ConstructionDescriptor descriptor_M_DERIVED = {&sort_M_DERIVED_xSORT, Data_M_DERIVED, 3, sizeof(STRUCT_Con_M_DERIVED), conBindOffs_M_DERIVED, &nameFun_M_DERIVED, &dataStep};
ConstructionDescriptor sortCon_M_DERIVED_xSORT[] = {NULL, NULL, &descriptor_M_DERIVED,  NULL};
char *sortNam_M_DERIVED_xSORT[] = {NULL, NULL,  "DERIVED" ,  NULL};
char *sortInt_M_DERIVED_xSORT[] = {NULL, NULL, "_M_DERIVED",  NULL};
struct _SortDescriptor sort_M_DERIVED_xSORT = { "DERIVED_SORT" , sortCon_M_DERIVED_xSORT, sortNam_M_DERIVED_xSORT, sortInt_M_DERIVED_xSORT, NULL};

/* SORT Define CONSTANTS. */
int conBindOffs_M_D_xFORM[] = {0 , 0 , 0};
char *name_M_D_xFORM =  "D_FORM" ;
char *nameFun_M_D_xFORM(Term term) { return name_M_D_xFORM; }
struct _ConstructionDescriptor descriptor_M_D_xFORM = {&sort_M_Define, Data_M_D_xFORM, 2, sizeof(STRUCT_Con_M_D_xFORM), conBindOffs_M_D_xFORM, &nameFun_M_D_xFORM, &dataStep};
char *name_M_D_xNONE =  "D_NONE" ;
char *nameFun_M_D_xNONE(Term term) { return name_M_D_xNONE; }
struct _ConstructionDescriptor descriptor_M_D_xNONE = {&sort_M_Define, Data_M_D_xNONE, 0, sizeof(STRUCT_Con_M_D_xNONE), noBinderOffsets, &nameFun_M_D_xNONE, &dataStep};
int conBindOffs_M_D_xABSTRACTION[] = {0 , 1};
char *name_M_D_xABSTRACTION =  "D_ABSTRACTION" ;
char *nameFun_M_D_xABSTRACTION(Term term) { return name_M_D_xABSTRACTION; }
struct _ConstructionDescriptor descriptor_M_D_xABSTRACTION = {&sort_M_Define, Data_M_D_xABSTRACTION, 1, sizeof(STRUCT_Con_M_D_xABSTRACTION), conBindOffs_M_D_xABSTRACTION, &nameFun_M_D_xABSTRACTION, &dataStep};
int conBindOffs_M_D_xRULE[] = {0 , 0 , 0 , 0};
char *name_M_D_xRULE =  "D_RULE" ;
char *nameFun_M_D_xRULE(Term term) { return name_M_D_xRULE; }
struct _ConstructionDescriptor descriptor_M_D_xRULE = {&sort_M_Define, Data_M_D_xRULE, 3, sizeof(STRUCT_Con_M_D_xRULE), conBindOffs_M_D_xRULE, &nameFun_M_D_xRULE, &dataStep};
ConstructionDescriptor sortCon_M_Define[] = {NULL, NULL, &descriptor_M_D_xFORM, &descriptor_M_D_xNONE, &descriptor_M_D_xABSTRACTION, &descriptor_M_D_xRULE,  NULL};
char *sortNam_M_Define[] = {NULL, NULL,  "D_FORM" ,  "D_NONE" ,  "D_ABSTRACTION" ,  "D_RULE" ,  NULL};
char *sortInt_M_Define[] = {NULL, NULL, "_M_D_xFORM", "_M_D_xNONE", "_M_D_xABSTRACTION", "_M_D_xRULE",  NULL};
struct _SortDescriptor sort_M_Define = { "Define" , sortCon_M_Define, sortNam_M_Define, sortInt_M_Define, NULL};

/* SORT FormKind CONSTANTS. */
char *name_M_FK_xALIAS =  "FK_ALIAS" ;
char *nameFun_M_FK_xALIAS(Term term) { return name_M_FK_xALIAS; }
struct _ConstructionDescriptor descriptor_M_FK_xALIAS = {&sort_M_FormKind, Data_M_FK_xALIAS, 0, sizeof(STRUCT_Con_M_FK_xALIAS), noBinderOffsets, &nameFun_M_FK_xALIAS, &dataStep};
int conBindOffs_M_FK_xSYMBOL[] = {0 , 0};
char *name_M_FK_xSYMBOL =  "FK_SYMBOL" ;
char *nameFun_M_FK_xSYMBOL(Term term) { return name_M_FK_xSYMBOL; }
struct _ConstructionDescriptor descriptor_M_FK_xSYMBOL = {&sort_M_FormKind, Data_M_FK_xSYMBOL, 1, sizeof(STRUCT_Con_M_FK_xSYMBOL), conBindOffs_M_FK_xSYMBOL, &nameFun_M_FK_xSYMBOL, &dataStep};
int conBindOffs_M_FK_xSUGAR[] = {0 , 0};
char *name_M_FK_xSUGAR =  "FK_SUGAR" ;
char *nameFun_M_FK_xSUGAR(Term term) { return name_M_FK_xSUGAR; }
struct _ConstructionDescriptor descriptor_M_FK_xSUGAR = {&sort_M_FormKind, Data_M_FK_xSUGAR, 1, sizeof(STRUCT_Con_M_FK_xSUGAR), conBindOffs_M_FK_xSUGAR, &nameFun_M_FK_xSUGAR, &dataStep};
int conBindOffs_M_FK_xSCHEME[] = {0 , 0};
char *name_M_FK_xSCHEME =  "FK_SCHEME" ;
char *nameFun_M_FK_xSCHEME(Term term) { return name_M_FK_xSCHEME; }
struct _ConstructionDescriptor descriptor_M_FK_xSCHEME = {&sort_M_FormKind, Data_M_FK_xSCHEME, 1, sizeof(STRUCT_Con_M_FK_xSCHEME), conBindOffs_M_FK_xSCHEME, &nameFun_M_FK_xSCHEME, &dataStep};
int conBindOffs_M_FK_xDATA[] = {0 , 0};
char *name_M_FK_xDATA =  "FK_DATA" ;
char *nameFun_M_FK_xDATA(Term term) { return name_M_FK_xDATA; }
struct _ConstructionDescriptor descriptor_M_FK_xDATA = {&sort_M_FormKind, Data_M_FK_xDATA, 1, sizeof(STRUCT_Con_M_FK_xDATA), conBindOffs_M_FK_xDATA, &nameFun_M_FK_xDATA, &dataStep};
ConstructionDescriptor sortCon_M_FormKind[] = {NULL, NULL, &descriptor_M_FK_xALIAS, &descriptor_M_FK_xSYMBOL, &descriptor_M_FK_xSUGAR, &descriptor_M_FK_xSCHEME, &descriptor_M_FK_xDATA,  NULL};
char *sortNam_M_FormKind[] = {NULL, NULL,  "FK_ALIAS" ,  "FK_SYMBOL" ,  "FK_SUGAR" ,  "FK_SCHEME" ,  "FK_DATA" ,  NULL};
char *sortInt_M_FormKind[] = {NULL, NULL, "_M_FK_xALIAS", "_M_FK_xSYMBOL", "_M_FK_xSUGAR", "_M_FK_xSCHEME", "_M_FK_xDATA",  NULL};
struct _SortDescriptor sort_M_FormKind = { "FormKind" , sortCon_M_FormKind, sortNam_M_FormKind, sortInt_M_FormKind, NULL};

/* SORT Lifted CONSTANTS. */
char *name_M_BOTTOM =  "BOTTOM" ;
char *nameFun_M_BOTTOM(Term term) { return name_M_BOTTOM; }
struct _ConstructionDescriptor descriptor_M_BOTTOM = {&sort_M_Lifted, Data_M_BOTTOM, 0, sizeof(STRUCT_Con_M_BOTTOM), noBinderOffsets, &nameFun_M_BOTTOM, &dataStep};
int conBindOffs_M_LIFTED[] = {0 , 0};
char *name_M_LIFTED =  "LIFTED" ;
char *nameFun_M_LIFTED(Term term) { return name_M_LIFTED; }
struct _ConstructionDescriptor descriptor_M_LIFTED = {&sort_M_Lifted, Data_M_LIFTED, 1, sizeof(STRUCT_Con_M_LIFTED), conBindOffs_M_LIFTED, &nameFun_M_LIFTED, &dataStep};
ConstructionDescriptor sortCon_M_Lifted[] = {NULL, NULL, &descriptor_M_BOTTOM, &descriptor_M_LIFTED,  NULL};
char *sortNam_M_Lifted[] = {NULL, NULL,  "BOTTOM" ,  "LIFTED" ,  NULL};
char *sortInt_M_Lifted[] = {NULL, NULL, "_M_BOTTOM", "_M_LIFTED",  NULL};
struct _SortDescriptor sort_M_Lifted = { "Lifted" , sortCon_M_Lifted, sortNam_M_Lifted, sortInt_M_Lifted, NULL};

/* SORT NameSet CONSTANTS. */
int conBindOffs_M_NAME_xSET[] = {0 , 0};
char *name_M_NAME_xSET =  "NAME_SET" ;
char *nameFun_M_NAME_xSET(Term term) { return name_M_NAME_xSET; }
struct _ConstructionDescriptor descriptor_M_NAME_xSET = {&sort_M_NameSet, Data_M_NAME_xSET, 1, sizeof(STRUCT_Con_M_NAME_xSET), conBindOffs_M_NAME_xSET, &nameFun_M_NAME_xSET, &dataStep};
ConstructionDescriptor sortCon_M_NameSet[] = {NULL, NULL, &descriptor_M_NAME_xSET,  NULL};
char *sortNam_M_NameSet[] = {NULL, NULL,  "NAME_SET" ,  NULL};
char *sortInt_M_NameSet[] = {NULL, NULL, "_M_NAME_xSET",  NULL};
struct _SortDescriptor sort_M_NameSet = { "NameSet" , sortCon_M_NameSet, sortNam_M_NameSet, sortInt_M_NameSet, NULL};

/* SORT NormalizedSortMap CONSTANTS. */
int conBindOffs_M_NSM[] = {0 , 0};
char *name_M_NSM =  "NSM" ;
char *nameFun_M_NSM(Term term) { return name_M_NSM; }
struct _ConstructionDescriptor descriptor_M_NSM = {&sort_M_NormalizedSortMap, Data_M_NSM, 1, sizeof(STRUCT_Con_M_NSM), conBindOffs_M_NSM, &nameFun_M_NSM, &dataStep};
ConstructionDescriptor sortCon_M_NormalizedSortMap[] = {NULL, NULL, &descriptor_M_NSM,  NULL};
char *sortNam_M_NormalizedSortMap[] = {NULL, NULL,  "NSM" ,  NULL};
char *sortInt_M_NormalizedSortMap[] = {NULL, NULL, "_M_NSM",  NULL};
struct _SortDescriptor sort_M_NormalizedSortMap = { "NormalizedSortMap" , sortCon_M_NormalizedSortMap, sortNam_M_NormalizedSortMap, sortInt_M_NormalizedSortMap, NULL};

/* SORT Ok CONSTANTS. */
char *name_M_OK =  "OK" ;
char *nameFun_M_OK(Term term) { return name_M_OK; }
struct _ConstructionDescriptor descriptor_M_OK = {&sort_M_Ok, Data_M_OK, 0, sizeof(STRUCT_Con_M_OK), noBinderOffsets, &nameFun_M_OK, &dataStep};
ConstructionDescriptor sortCon_M_Ok[] = {NULL, NULL, &descriptor_M_OK,  NULL};
char *sortNam_M_Ok[] = {NULL, NULL,  "OK" ,  NULL};
char *sortInt_M_Ok[] = {NULL, NULL, "_M_OK",  NULL};
struct _SortDescriptor sort_M_Ok = { "Ok" , sortCon_M_Ok, sortNam_M_Ok, sortInt_M_Ok, NULL};

/* SORT PFK_SORT CONSTANTS. */
int conBindOffs_M_PFK[] = {0 , 0 , 0};
char *name_M_PFK =  "PFK" ;
char *nameFun_M_PFK(Term term) { return name_M_PFK; }
struct _ConstructionDescriptor descriptor_M_PFK = {&sort_M_PFK_xSORT, Data_M_PFK, 2, sizeof(STRUCT_Con_M_PFK), conBindOffs_M_PFK, &nameFun_M_PFK, &dataStep};
ConstructionDescriptor sortCon_M_PFK_xSORT[] = {NULL, NULL, &descriptor_M_PFK,  NULL};
char *sortNam_M_PFK_xSORT[] = {NULL, NULL,  "PFK" ,  NULL};
char *sortInt_M_PFK_xSORT[] = {NULL, NULL, "_M_PFK",  NULL};
struct _SortDescriptor sort_M_PFK_xSORT = { "PFK_SORT" , sortCon_M_PFK_xSORT, sortNam_M_PFK_xSORT, sortInt_M_PFK_xSORT, NULL};

/* SORT PropsOf$AM_SORT CONSTANTS. */
char *name_M_PropsOf_sAM =  "PropsOf$AM" ;
char *nameFun_M_PropsOf_sAM(Term term) { return name_M_PropsOf_sAM; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sAM = {&sort_M_PropsOf_sAM_xSORT, Data_M_PropsOf_sAM, 0, sizeof(STRUCT_Con_M_PropsOf_sAM), noBinderOffsets, &nameFun_M_PropsOf_sAM, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sAM_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sAM,  NULL};
char *sortNam_M_PropsOf_sAM_xSORT[] = {NULL, NULL,  "PropsOf$AM" ,  NULL};
char *sortInt_M_PropsOf_sAM_xSORT[] = {NULL, NULL, "_M_PropsOf_sAM",  NULL};
struct _SortDescriptor sort_M_PropsOf_sAM_xSORT = { "PropsOf$AM_SORT" , sortCon_M_PropsOf_sAM_xSORT, sortNam_M_PropsOf_sAM_xSORT, sortInt_M_PropsOf_sAM_xSORT, NULL};

/* SORT PropsOf$D_ABSTRACTION_SORT CONSTANTS. */
char *name_M_PropsOf_sD_xABSTRACTION =  "PropsOf$D_ABSTRACTION" ;
char *nameFun_M_PropsOf_sD_xABSTRACTION(Term term) { return name_M_PropsOf_sD_xABSTRACTION; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sD_xABSTRACTION = {&sort_M_PropsOf_sD_xABSTRACTION_xSORT, Data_M_PropsOf_sD_xABSTRACTION, 0, sizeof(STRUCT_Con_M_PropsOf_sD_xABSTRACTION), noBinderOffsets, &nameFun_M_PropsOf_sD_xABSTRACTION, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sD_xABSTRACTION_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sD_xABSTRACTION,  NULL};
char *sortNam_M_PropsOf_sD_xABSTRACTION_xSORT[] = {NULL, NULL,  "PropsOf$D_ABSTRACTION" ,  NULL};
char *sortInt_M_PropsOf_sD_xABSTRACTION_xSORT[] = {NULL, NULL, "_M_PropsOf_sD_xABSTRACTION",  NULL};
struct _SortDescriptor sort_M_PropsOf_sD_xABSTRACTION_xSORT = { "PropsOf$D_ABSTRACTION_SORT" , sortCon_M_PropsOf_sD_xABSTRACTION_xSORT, sortNam_M_PropsOf_sD_xABSTRACTION_xSORT, sortInt_M_PropsOf_sD_xABSTRACTION_xSORT, NULL};

/* SORT PropsOf$D_FORM_SORT CONSTANTS. */
char *name_M_PropsOf_sD_xFORM =  "PropsOf$D_FORM" ;
char *nameFun_M_PropsOf_sD_xFORM(Term term) { return name_M_PropsOf_sD_xFORM; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sD_xFORM = {&sort_M_PropsOf_sD_xFORM_xSORT, Data_M_PropsOf_sD_xFORM, 0, sizeof(STRUCT_Con_M_PropsOf_sD_xFORM), noBinderOffsets, &nameFun_M_PropsOf_sD_xFORM, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sD_xFORM_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sD_xFORM,  NULL};
char *sortNam_M_PropsOf_sD_xFORM_xSORT[] = {NULL, NULL,  "PropsOf$D_FORM" ,  NULL};
char *sortInt_M_PropsOf_sD_xFORM_xSORT[] = {NULL, NULL, "_M_PropsOf_sD_xFORM",  NULL};
struct _SortDescriptor sort_M_PropsOf_sD_xFORM_xSORT = { "PropsOf$D_FORM_SORT" , sortCon_M_PropsOf_sD_xFORM_xSORT, sortNam_M_PropsOf_sD_xFORM_xSORT, sortInt_M_PropsOf_sD_xFORM_xSORT, NULL};

/* SORT PropsOf$D_NONE_SORT CONSTANTS. */
char *name_M_PropsOf_sD_xNONE =  "PropsOf$D_NONE" ;
char *nameFun_M_PropsOf_sD_xNONE(Term term) { return name_M_PropsOf_sD_xNONE; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sD_xNONE = {&sort_M_PropsOf_sD_xNONE_xSORT, Data_M_PropsOf_sD_xNONE, 0, sizeof(STRUCT_Con_M_PropsOf_sD_xNONE), noBinderOffsets, &nameFun_M_PropsOf_sD_xNONE, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sD_xNONE_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sD_xNONE,  NULL};
char *sortNam_M_PropsOf_sD_xNONE_xSORT[] = {NULL, NULL,  "PropsOf$D_NONE" ,  NULL};
char *sortInt_M_PropsOf_sD_xNONE_xSORT[] = {NULL, NULL, "_M_PropsOf_sD_xNONE",  NULL};
struct _SortDescriptor sort_M_PropsOf_sD_xNONE_xSORT = { "PropsOf$D_NONE_SORT" , sortCon_M_PropsOf_sD_xNONE_xSORT, sortNam_M_PropsOf_sD_xNONE_xSORT, sortInt_M_PropsOf_sD_xNONE_xSORT, NULL};

/* SORT PropsOf$D_RULE_SORT CONSTANTS. */
char *name_M_PropsOf_sD_xRULE =  "PropsOf$D_RULE" ;
char *nameFun_M_PropsOf_sD_xRULE(Term term) { return name_M_PropsOf_sD_xRULE; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sD_xRULE = {&sort_M_PropsOf_sD_xRULE_xSORT, Data_M_PropsOf_sD_xRULE, 0, sizeof(STRUCT_Con_M_PropsOf_sD_xRULE), noBinderOffsets, &nameFun_M_PropsOf_sD_xRULE, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sD_xRULE_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sD_xRULE,  NULL};
char *sortNam_M_PropsOf_sD_xRULE_xSORT[] = {NULL, NULL,  "PropsOf$D_RULE" ,  NULL};
char *sortInt_M_PropsOf_sD_xRULE_xSORT[] = {NULL, NULL, "_M_PropsOf_sD_xRULE",  NULL};
struct _SortDescriptor sort_M_PropsOf_sD_xRULE_xSORT = { "PropsOf$D_RULE_SORT" , sortCon_M_PropsOf_sD_xRULE_xSORT, sortNam_M_PropsOf_sD_xRULE_xSORT, sortInt_M_PropsOf_sD_xRULE_xSORT, NULL};

/* SORT PropsOf$Declarations$Nil_SORT CONSTANTS. */
char *name_M_PropsOf_sDeclarations_sNil =  "PropsOf$Declarations$Nil" ;
char *nameFun_M_PropsOf_sDeclarations_sNil(Term term) { return name_M_PropsOf_sDeclarations_sNil; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sDeclarations_sNil = {&sort_M_PropsOf_sDeclarations_sNil_xSORT, Data_M_PropsOf_sDeclarations_sNil, 0, sizeof(STRUCT_Con_M_PropsOf_sDeclarations_sNil), noBinderOffsets, &nameFun_M_PropsOf_sDeclarations_sNil, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sDeclarations_sNil_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sDeclarations_sNil,  NULL};
char *sortNam_M_PropsOf_sDeclarations_sNil_xSORT[] = {NULL, NULL,  "PropsOf$Declarations$Nil" ,  NULL};
char *sortInt_M_PropsOf_sDeclarations_sNil_xSORT[] = {NULL, NULL, "_M_PropsOf_sDeclarations_sNil",  NULL};
struct _SortDescriptor sort_M_PropsOf_sDeclarations_sNil_xSORT = { "PropsOf$Declarations$Nil_SORT" , sortCon_M_PropsOf_sDeclarations_sNil_xSORT, sortNam_M_PropsOf_sDeclarations_sNil_xSORT, sortInt_M_PropsOf_sDeclarations_sNil_xSORT, NULL};

/* SORT PropsOf$NSM_SORT CONSTANTS. */
char *name_M_PropsOf_sNSM =  "PropsOf$NSM" ;
char *nameFun_M_PropsOf_sNSM(Term term) { return name_M_PropsOf_sNSM; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sNSM = {&sort_M_PropsOf_sNSM_xSORT, Data_M_PropsOf_sNSM, 0, sizeof(STRUCT_Con_M_PropsOf_sNSM), noBinderOffsets, &nameFun_M_PropsOf_sNSM, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sNSM_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sNSM,  NULL};
char *sortNam_M_PropsOf_sNSM_xSORT[] = {NULL, NULL,  "PropsOf$NSM" ,  NULL};
char *sortInt_M_PropsOf_sNSM_xSORT[] = {NULL, NULL, "_M_PropsOf_sNSM",  NULL};
struct _SortDescriptor sort_M_PropsOf_sNSM_xSORT = { "PropsOf$NSM_SORT" , sortCon_M_PropsOf_sNSM_xSORT, sortNam_M_PropsOf_sNSM_xSORT, sortInt_M_PropsOf_sNSM_xSORT, NULL};

/* SORT PropsOf$OMITTED_SORT CONSTANTS. */
char *name_M_PropsOf_sOMITTED =  "PropsOf$OMITTED" ;
char *nameFun_M_PropsOf_sOMITTED(Term term) { return name_M_PropsOf_sOMITTED; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sOMITTED = {&sort_M_PropsOf_sOMITTED_xSORT, Data_M_PropsOf_sOMITTED, 0, sizeof(STRUCT_Con_M_PropsOf_sOMITTED), noBinderOffsets, &nameFun_M_PropsOf_sOMITTED, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sOMITTED_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sOMITTED,  NULL};
char *sortNam_M_PropsOf_sOMITTED_xSORT[] = {NULL, NULL,  "PropsOf$OMITTED" ,  NULL};
char *sortInt_M_PropsOf_sOMITTED_xSORT[] = {NULL, NULL, "_M_PropsOf_sOMITTED",  NULL};
struct _SortDescriptor sort_M_PropsOf_sOMITTED_xSORT = { "PropsOf$OMITTED_SORT" , sortCon_M_PropsOf_sOMITTED_xSORT, sortNam_M_PropsOf_sOMITTED_xSORT, sortInt_M_PropsOf_sOMITTED_xSORT, NULL};

/* SORT PropsOf$RAW-AttributeFormMap_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_AttributeFormMap =  "PropsOf$RAW-AttributeFormMap" ;
char *nameFun_M_PropsOf_sRAW_AttributeFormMap(Term term) { return name_M_PropsOf_sRAW_AttributeFormMap; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_AttributeFormMap = {&sort_M_PropsOf_sRAW_AttributeFormMap_xSORT, Data_M_PropsOf_sRAW_AttributeFormMap, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_AttributeFormMap), noBinderOffsets, &nameFun_M_PropsOf_sRAW_AttributeFormMap, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_AttributeFormMap_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_AttributeFormMap,  NULL};
char *sortNam_M_PropsOf_sRAW_AttributeFormMap_xSORT[] = {NULL, NULL,  "PropsOf$RAW-AttributeFormMap" ,  NULL};
char *sortInt_M_PropsOf_sRAW_AttributeFormMap_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_AttributeFormMap",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_AttributeFormMap_xSORT = { "PropsOf$RAW-AttributeFormMap_SORT" , sortCon_M_PropsOf_sRAW_AttributeFormMap_xSORT, sortNam_M_PropsOf_sRAW_AttributeFormMap_xSORT, sortInt_M_PropsOf_sRAW_AttributeFormMap_xSORT, NULL};

/* SORT PropsOf$RAW-AttributeFormSet_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_AttributeFormSet =  "PropsOf$RAW-AttributeFormSet" ;
char *nameFun_M_PropsOf_sRAW_AttributeFormSet(Term term) { return name_M_PropsOf_sRAW_AttributeFormSet; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_AttributeFormSet = {&sort_M_PropsOf_sRAW_AttributeFormSet_xSORT, Data_M_PropsOf_sRAW_AttributeFormSet, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_AttributeFormSet), noBinderOffsets, &nameFun_M_PropsOf_sRAW_AttributeFormSet, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_AttributeFormSet_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_AttributeFormSet,  NULL};
char *sortNam_M_PropsOf_sRAW_AttributeFormSet_xSORT[] = {NULL, NULL,  "PropsOf$RAW-AttributeFormSet" ,  NULL};
char *sortInt_M_PropsOf_sRAW_AttributeFormSet_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_AttributeFormSet",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_AttributeFormSet_xSORT = { "PropsOf$RAW-AttributeFormSet_SORT" , sortCon_M_PropsOf_sRAW_AttributeFormSet_xSORT, sortNam_M_PropsOf_sRAW_AttributeFormSet_xSORT, sortInt_M_PropsOf_sRAW_AttributeFormSet_xSORT, NULL};

/* SORT PropsOf$RAW-AttributeFormSimple_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_AttributeFormSimple =  "PropsOf$RAW-AttributeFormSimple" ;
char *nameFun_M_PropsOf_sRAW_AttributeFormSimple(Term term) { return name_M_PropsOf_sRAW_AttributeFormSimple; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_AttributeFormSimple = {&sort_M_PropsOf_sRAW_AttributeFormSimple_xSORT, Data_M_PropsOf_sRAW_AttributeFormSimple, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_AttributeFormSimple), noBinderOffsets, &nameFun_M_PropsOf_sRAW_AttributeFormSimple, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_AttributeFormSimple_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_AttributeFormSimple,  NULL};
char *sortNam_M_PropsOf_sRAW_AttributeFormSimple_xSORT[] = {NULL, NULL,  "PropsOf$RAW-AttributeFormSimple" ,  NULL};
char *sortInt_M_PropsOf_sRAW_AttributeFormSimple_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_AttributeFormSimple",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_AttributeFormSimple_xSORT = { "PropsOf$RAW-AttributeFormSimple_SORT" , sortCon_M_PropsOf_sRAW_AttributeFormSimple_xSORT, sortNam_M_PropsOf_sRAW_AttributeFormSimple_xSORT, sortInt_M_PropsOf_sRAW_AttributeFormSimple_xSORT, NULL};

/* SORT PropsOf$RAW-AttributeKeyValue_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_AttributeKeyValue =  "PropsOf$RAW-AttributeKeyValue" ;
char *nameFun_M_PropsOf_sRAW_AttributeKeyValue(Term term) { return name_M_PropsOf_sRAW_AttributeKeyValue; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_AttributeKeyValue = {&sort_M_PropsOf_sRAW_AttributeKeyValue_xSORT, Data_M_PropsOf_sRAW_AttributeKeyValue, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_AttributeKeyValue), noBinderOffsets, &nameFun_M_PropsOf_sRAW_AttributeKeyValue, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_AttributeKeyValue_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_AttributeKeyValue,  NULL};
char *sortNam_M_PropsOf_sRAW_AttributeKeyValue_xSORT[] = {NULL, NULL,  "PropsOf$RAW-AttributeKeyValue" ,  NULL};
char *sortInt_M_PropsOf_sRAW_AttributeKeyValue_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_AttributeKeyValue",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_AttributeKeyValue_xSORT = { "PropsOf$RAW-AttributeKeyValue_SORT" , sortCon_M_PropsOf_sRAW_AttributeKeyValue_xSORT, sortNam_M_PropsOf_sRAW_AttributeKeyValue_xSORT, sortInt_M_PropsOf_sRAW_AttributeKeyValue_xSORT, NULL};

/* SORT PropsOf$RAW-AttributeKey_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_AttributeKey =  "PropsOf$RAW-AttributeKey" ;
char *nameFun_M_PropsOf_sRAW_AttributeKey(Term term) { return name_M_PropsOf_sRAW_AttributeKey; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_AttributeKey = {&sort_M_PropsOf_sRAW_AttributeKey_xSORT, Data_M_PropsOf_sRAW_AttributeKey, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_AttributeKey), noBinderOffsets, &nameFun_M_PropsOf_sRAW_AttributeKey, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_AttributeKey_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_AttributeKey,  NULL};
char *sortNam_M_PropsOf_sRAW_AttributeKey_xSORT[] = {NULL, NULL,  "PropsOf$RAW-AttributeKey" ,  NULL};
char *sortInt_M_PropsOf_sRAW_AttributeKey_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_AttributeKey",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_AttributeKey_xSORT = { "PropsOf$RAW-AttributeKey_SORT" , sortCon_M_PropsOf_sRAW_AttributeKey_xSORT, sortNam_M_PropsOf_sRAW_AttributeKey_xSORT, sortInt_M_PropsOf_sRAW_AttributeKey_xSORT, NULL};

/* SORT PropsOf$RAW-AttributeKindDown_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_AttributeKindDown =  "PropsOf$RAW-AttributeKindDown" ;
char *nameFun_M_PropsOf_sRAW_AttributeKindDown(Term term) { return name_M_PropsOf_sRAW_AttributeKindDown; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_AttributeKindDown = {&sort_M_PropsOf_sRAW_AttributeKindDown_xSORT, Data_M_PropsOf_sRAW_AttributeKindDown, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_AttributeKindDown), noBinderOffsets, &nameFun_M_PropsOf_sRAW_AttributeKindDown, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_AttributeKindDown_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_AttributeKindDown,  NULL};
char *sortNam_M_PropsOf_sRAW_AttributeKindDown_xSORT[] = {NULL, NULL,  "PropsOf$RAW-AttributeKindDown" ,  NULL};
char *sortInt_M_PropsOf_sRAW_AttributeKindDown_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_AttributeKindDown",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_AttributeKindDown_xSORT = { "PropsOf$RAW-AttributeKindDown_SORT" , sortCon_M_PropsOf_sRAW_AttributeKindDown_xSORT, sortNam_M_PropsOf_sRAW_AttributeKindDown_xSORT, sortInt_M_PropsOf_sRAW_AttributeKindDown_xSORT, NULL};

/* SORT PropsOf$RAW-AttributeKindUp_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_AttributeKindUp =  "PropsOf$RAW-AttributeKindUp" ;
char *nameFun_M_PropsOf_sRAW_AttributeKindUp(Term term) { return name_M_PropsOf_sRAW_AttributeKindUp; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_AttributeKindUp = {&sort_M_PropsOf_sRAW_AttributeKindUp_xSORT, Data_M_PropsOf_sRAW_AttributeKindUp, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_AttributeKindUp), noBinderOffsets, &nameFun_M_PropsOf_sRAW_AttributeKindUp, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_AttributeKindUp_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_AttributeKindUp,  NULL};
char *sortNam_M_PropsOf_sRAW_AttributeKindUp_xSORT[] = {NULL, NULL,  "PropsOf$RAW-AttributeKindUp" ,  NULL};
char *sortInt_M_PropsOf_sRAW_AttributeKindUp_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_AttributeKindUp",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_AttributeKindUp_xSORT = { "PropsOf$RAW-AttributeKindUp_SORT" , sortCon_M_PropsOf_sRAW_AttributeKindUp_xSORT, sortNam_M_PropsOf_sRAW_AttributeKindUp_xSORT, sortInt_M_PropsOf_sRAW_AttributeKindUp_xSORT, NULL};

/* SORT PropsOf$RAW-AttributeNotKey_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_AttributeNotKey =  "PropsOf$RAW-AttributeNotKey" ;
char *nameFun_M_PropsOf_sRAW_AttributeNotKey(Term term) { return name_M_PropsOf_sRAW_AttributeNotKey; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_AttributeNotKey = {&sort_M_PropsOf_sRAW_AttributeNotKey_xSORT, Data_M_PropsOf_sRAW_AttributeNotKey, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_AttributeNotKey), noBinderOffsets, &nameFun_M_PropsOf_sRAW_AttributeNotKey, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_AttributeNotKey_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_AttributeNotKey,  NULL};
char *sortNam_M_PropsOf_sRAW_AttributeNotKey_xSORT[] = {NULL, NULL,  "PropsOf$RAW-AttributeNotKey" ,  NULL};
char *sortInt_M_PropsOf_sRAW_AttributeNotKey_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_AttributeNotKey",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_AttributeNotKey_xSORT = { "PropsOf$RAW-AttributeNotKey_SORT" , sortCon_M_PropsOf_sRAW_AttributeNotKey_xSORT, sortNam_M_PropsOf_sRAW_AttributeNotKey_xSORT, sortInt_M_PropsOf_sRAW_AttributeNotKey_xSORT, NULL};

/* SORT PropsOf$RAW-AttributeOption_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_AttributeOption =  "PropsOf$RAW-AttributeOption" ;
char *nameFun_M_PropsOf_sRAW_AttributeOption(Term term) { return name_M_PropsOf_sRAW_AttributeOption; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_AttributeOption = {&sort_M_PropsOf_sRAW_AttributeOption_xSORT, Data_M_PropsOf_sRAW_AttributeOption, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_AttributeOption), noBinderOffsets, &nameFun_M_PropsOf_sRAW_AttributeOption, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_AttributeOption_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_AttributeOption,  NULL};
char *sortNam_M_PropsOf_sRAW_AttributeOption_xSORT[] = {NULL, NULL,  "PropsOf$RAW-AttributeOption" ,  NULL};
char *sortInt_M_PropsOf_sRAW_AttributeOption_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_AttributeOption",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_AttributeOption_xSORT = { "PropsOf$RAW-AttributeOption_SORT" , sortCon_M_PropsOf_sRAW_AttributeOption_xSORT, sortNam_M_PropsOf_sRAW_AttributeOption_xSORT, sortInt_M_PropsOf_sRAW_AttributeOption_xSORT, NULL};

/* SORT PropsOf$RAW-AttributeValue_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_AttributeValue =  "PropsOf$RAW-AttributeValue" ;
char *nameFun_M_PropsOf_sRAW_AttributeValue(Term term) { return name_M_PropsOf_sRAW_AttributeValue; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_AttributeValue = {&sort_M_PropsOf_sRAW_AttributeValue_xSORT, Data_M_PropsOf_sRAW_AttributeValue, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_AttributeValue), noBinderOffsets, &nameFun_M_PropsOf_sRAW_AttributeValue, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_AttributeValue_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_AttributeValue,  NULL};
char *sortNam_M_PropsOf_sRAW_AttributeValue_xSORT[] = {NULL, NULL,  "PropsOf$RAW-AttributeValue" ,  NULL};
char *sortInt_M_PropsOf_sRAW_AttributeValue_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_AttributeValue",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_AttributeValue_xSORT = { "PropsOf$RAW-AttributeValue_SORT" , sortCon_M_PropsOf_sRAW_AttributeValue_xSORT, sortNam_M_PropsOf_sRAW_AttributeValue_xSORT, sortInt_M_PropsOf_sRAW_AttributeValue_xSORT, NULL};

/* SORT PropsOf$RAW-Attribute_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_Attribute =  "PropsOf$RAW-Attribute" ;
char *nameFun_M_PropsOf_sRAW_Attribute(Term term) { return name_M_PropsOf_sRAW_Attribute; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_Attribute = {&sort_M_PropsOf_sRAW_Attribute_xSORT, Data_M_PropsOf_sRAW_Attribute, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_Attribute), noBinderOffsets, &nameFun_M_PropsOf_sRAW_Attribute, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_Attribute_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_Attribute,  NULL};
char *sortNam_M_PropsOf_sRAW_Attribute_xSORT[] = {NULL, NULL,  "PropsOf$RAW-Attribute" ,  NULL};
char *sortInt_M_PropsOf_sRAW_Attribute_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_Attribute",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_Attribute_xSORT = { "PropsOf$RAW-Attribute_SORT" , sortCon_M_PropsOf_sRAW_Attribute_xSORT, sortNam_M_PropsOf_sRAW_Attribute_xSORT, sortInt_M_PropsOf_sRAW_Attribute_xSORT, NULL};

/* SORT PropsOf$RAW-ConstructionSorted_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_ConstructionSorted =  "PropsOf$RAW-ConstructionSorted" ;
char *nameFun_M_PropsOf_sRAW_ConstructionSorted(Term term) { return name_M_PropsOf_sRAW_ConstructionSorted; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_ConstructionSorted = {&sort_M_PropsOf_sRAW_ConstructionSorted_xSORT, Data_M_PropsOf_sRAW_ConstructionSorted, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_ConstructionSorted), noBinderOffsets, &nameFun_M_PropsOf_sRAW_ConstructionSorted, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_ConstructionSorted_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_ConstructionSorted,  NULL};
char *sortNam_M_PropsOf_sRAW_ConstructionSorted_xSORT[] = {NULL, NULL,  "PropsOf$RAW-ConstructionSorted" ,  NULL};
char *sortInt_M_PropsOf_sRAW_ConstructionSorted_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_ConstructionSorted",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_ConstructionSorted_xSORT = { "PropsOf$RAW-ConstructionSorted_SORT" , sortCon_M_PropsOf_sRAW_ConstructionSorted_xSORT, sortNam_M_PropsOf_sRAW_ConstructionSorted_xSORT, sortInt_M_PropsOf_sRAW_ConstructionSorted_xSORT, NULL};

/* SORT PropsOf$RAW-Construction_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_Construction =  "PropsOf$RAW-Construction" ;
char *nameFun_M_PropsOf_sRAW_Construction(Term term) { return name_M_PropsOf_sRAW_Construction; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_Construction = {&sort_M_PropsOf_sRAW_Construction_xSORT, Data_M_PropsOf_sRAW_Construction, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_Construction), noBinderOffsets, &nameFun_M_PropsOf_sRAW_Construction, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_Construction_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_Construction,  NULL};
char *sortNam_M_PropsOf_sRAW_Construction_xSORT[] = {NULL, NULL,  "PropsOf$RAW-Construction" ,  NULL};
char *sortInt_M_PropsOf_sRAW_Construction_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_Construction",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_Construction_xSORT = { "PropsOf$RAW-Construction_SORT" , sortCon_M_PropsOf_sRAW_Construction_xSORT, sortNam_M_PropsOf_sRAW_Construction_xSORT, sortInt_M_PropsOf_sRAW_Construction_xSORT, NULL};

/* SORT PropsOf$RAW-Declarations$Cons_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_Declarations_sCons =  "PropsOf$RAW-Declarations$Cons" ;
char *nameFun_M_PropsOf_sRAW_Declarations_sCons(Term term) { return name_M_PropsOf_sRAW_Declarations_sCons; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_Declarations_sCons = {&sort_M_PropsOf_sRAW_Declarations_sCons_xSORT, Data_M_PropsOf_sRAW_Declarations_sCons, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_Declarations_sCons), noBinderOffsets, &nameFun_M_PropsOf_sRAW_Declarations_sCons, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_Declarations_sCons_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_Declarations_sCons,  NULL};
char *sortNam_M_PropsOf_sRAW_Declarations_sCons_xSORT[] = {NULL, NULL,  "PropsOf$RAW-Declarations$Cons" ,  NULL};
char *sortInt_M_PropsOf_sRAW_Declarations_sCons_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_Declarations_sCons",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_Declarations_sCons_xSORT = { "PropsOf$RAW-Declarations$Cons_SORT" , sortCon_M_PropsOf_sRAW_Declarations_sCons_xSORT, sortNam_M_PropsOf_sRAW_Declarations_sCons_xSORT, sortInt_M_PropsOf_sRAW_Declarations_sCons_xSORT, NULL};

/* SORT PropsOf$RAW-FormConstruction_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_FormConstruction =  "PropsOf$RAW-FormConstruction" ;
char *nameFun_M_PropsOf_sRAW_FormConstruction(Term term) { return name_M_PropsOf_sRAW_FormConstruction; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_FormConstruction = {&sort_M_PropsOf_sRAW_FormConstruction_xSORT, Data_M_PropsOf_sRAW_FormConstruction, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_FormConstruction), noBinderOffsets, &nameFun_M_PropsOf_sRAW_FormConstruction, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_FormConstruction_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_FormConstruction,  NULL};
char *sortNam_M_PropsOf_sRAW_FormConstruction_xSORT[] = {NULL, NULL,  "PropsOf$RAW-FormConstruction" ,  NULL};
char *sortInt_M_PropsOf_sRAW_FormConstruction_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_FormConstruction",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_FormConstruction_xSORT = { "PropsOf$RAW-FormConstruction_SORT" , sortCon_M_PropsOf_sRAW_FormConstruction_xSORT, sortNam_M_PropsOf_sRAW_FormConstruction_xSORT, sortInt_M_PropsOf_sRAW_FormConstruction_xSORT, NULL};

/* SORT PropsOf$RAW-FormParsedSorted_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_FormParsedSorted =  "PropsOf$RAW-FormParsedSorted" ;
char *nameFun_M_PropsOf_sRAW_FormParsedSorted(Term term) { return name_M_PropsOf_sRAW_FormParsedSorted; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_FormParsedSorted = {&sort_M_PropsOf_sRAW_FormParsedSorted_xSORT, Data_M_PropsOf_sRAW_FormParsedSorted, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_FormParsedSorted), noBinderOffsets, &nameFun_M_PropsOf_sRAW_FormParsedSorted, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_FormParsedSorted_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_FormParsedSorted,  NULL};
char *sortNam_M_PropsOf_sRAW_FormParsedSorted_xSORT[] = {NULL, NULL,  "PropsOf$RAW-FormParsedSorted" ,  NULL};
char *sortInt_M_PropsOf_sRAW_FormParsedSorted_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_FormParsedSorted",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_FormParsedSorted_xSORT = { "PropsOf$RAW-FormParsedSorted_SORT" , sortCon_M_PropsOf_sRAW_FormParsedSorted_xSORT, sortNam_M_PropsOf_sRAW_FormParsedSorted_xSORT, sortInt_M_PropsOf_sRAW_FormParsedSorted_xSORT, NULL};

/* SORT PropsOf$RAW-FormParsedUnsorted_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_FormParsedUnsorted =  "PropsOf$RAW-FormParsedUnsorted" ;
char *nameFun_M_PropsOf_sRAW_FormParsedUnsorted(Term term) { return name_M_PropsOf_sRAW_FormParsedUnsorted; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_FormParsedUnsorted = {&sort_M_PropsOf_sRAW_FormParsedUnsorted_xSORT, Data_M_PropsOf_sRAW_FormParsedUnsorted, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_FormParsedUnsorted), noBinderOffsets, &nameFun_M_PropsOf_sRAW_FormParsedUnsorted, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_FormParsedUnsorted_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_FormParsedUnsorted,  NULL};
char *sortNam_M_PropsOf_sRAW_FormParsedUnsorted_xSORT[] = {NULL, NULL,  "PropsOf$RAW-FormParsedUnsorted" ,  NULL};
char *sortInt_M_PropsOf_sRAW_FormParsedUnsorted_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_FormParsedUnsorted",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_FormParsedUnsorted_xSORT = { "PropsOf$RAW-FormParsedUnsorted_SORT" , sortCon_M_PropsOf_sRAW_FormParsedUnsorted_xSORT, sortNam_M_PropsOf_sRAW_FormParsedUnsorted_xSORT, sortInt_M_PropsOf_sRAW_FormParsedUnsorted_xSORT, NULL};

/* SORT PropsOf$RAW-InheritedRef_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_InheritedRef =  "PropsOf$RAW-InheritedRef" ;
char *nameFun_M_PropsOf_sRAW_InheritedRef(Term term) { return name_M_PropsOf_sRAW_InheritedRef; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_InheritedRef = {&sort_M_PropsOf_sRAW_InheritedRef_xSORT, Data_M_PropsOf_sRAW_InheritedRef, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_InheritedRef), noBinderOffsets, &nameFun_M_PropsOf_sRAW_InheritedRef, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_InheritedRef_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_InheritedRef,  NULL};
char *sortNam_M_PropsOf_sRAW_InheritedRef_xSORT[] = {NULL, NULL,  "PropsOf$RAW-InheritedRef" ,  NULL};
char *sortInt_M_PropsOf_sRAW_InheritedRef_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_InheritedRef",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_InheritedRef_xSORT = { "PropsOf$RAW-InheritedRef_SORT" , sortCon_M_PropsOf_sRAW_InheritedRef_xSORT, sortNam_M_PropsOf_sRAW_InheritedRef_xSORT, sortInt_M_PropsOf_sRAW_InheritedRef_xSORT, NULL};

/* SORT PropsOf$RAW-Literal_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_Literal =  "PropsOf$RAW-Literal" ;
char *nameFun_M_PropsOf_sRAW_Literal(Term term) { return name_M_PropsOf_sRAW_Literal; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_Literal = {&sort_M_PropsOf_sRAW_Literal_xSORT, Data_M_PropsOf_sRAW_Literal, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_Literal), noBinderOffsets, &nameFun_M_PropsOf_sRAW_Literal, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_Literal_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_Literal,  NULL};
char *sortNam_M_PropsOf_sRAW_Literal_xSORT[] = {NULL, NULL,  "PropsOf$RAW-Literal" ,  NULL};
char *sortInt_M_PropsOf_sRAW_Literal_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_Literal",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_Literal_xSORT = { "PropsOf$RAW-Literal_SORT" , sortCon_M_PropsOf_sRAW_Literal_xSORT, sortNam_M_PropsOf_sRAW_Literal_xSORT, sortInt_M_PropsOf_sRAW_Literal_xSORT, NULL};

/* SORT PropsOf$RAW-MetaApplicationSorted_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_MetaApplicationSorted =  "PropsOf$RAW-MetaApplicationSorted" ;
char *nameFun_M_PropsOf_sRAW_MetaApplicationSorted(Term term) { return name_M_PropsOf_sRAW_MetaApplicationSorted; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_MetaApplicationSorted = {&sort_M_PropsOf_sRAW_MetaApplicationSorted_xSORT, Data_M_PropsOf_sRAW_MetaApplicationSorted, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_MetaApplicationSorted), noBinderOffsets, &nameFun_M_PropsOf_sRAW_MetaApplicationSorted, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_MetaApplicationSorted_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_MetaApplicationSorted,  NULL};
char *sortNam_M_PropsOf_sRAW_MetaApplicationSorted_xSORT[] = {NULL, NULL,  "PropsOf$RAW-MetaApplicationSorted" ,  NULL};
char *sortInt_M_PropsOf_sRAW_MetaApplicationSorted_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_MetaApplicationSorted",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_MetaApplicationSorted_xSORT = { "PropsOf$RAW-MetaApplicationSorted_SORT" , sortCon_M_PropsOf_sRAW_MetaApplicationSorted_xSORT, sortNam_M_PropsOf_sRAW_MetaApplicationSorted_xSORT, sortInt_M_PropsOf_sRAW_MetaApplicationSorted_xSORT, NULL};

/* SORT PropsOf$RAW-MetaApplication_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_MetaApplication =  "PropsOf$RAW-MetaApplication" ;
char *nameFun_M_PropsOf_sRAW_MetaApplication(Term term) { return name_M_PropsOf_sRAW_MetaApplication; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_MetaApplication = {&sort_M_PropsOf_sRAW_MetaApplication_xSORT, Data_M_PropsOf_sRAW_MetaApplication, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_MetaApplication), noBinderOffsets, &nameFun_M_PropsOf_sRAW_MetaApplication, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_MetaApplication_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_MetaApplication,  NULL};
char *sortNam_M_PropsOf_sRAW_MetaApplication_xSORT[] = {NULL, NULL,  "PropsOf$RAW-MetaApplication" ,  NULL};
char *sortInt_M_PropsOf_sRAW_MetaApplication_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_MetaApplication",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_MetaApplication_xSORT = { "PropsOf$RAW-MetaApplication_SORT" , sortCon_M_PropsOf_sRAW_MetaApplication_xSORT, sortNam_M_PropsOf_sRAW_MetaApplication_xSORT, sortInt_M_PropsOf_sRAW_MetaApplication_xSORT, NULL};

/* SORT PropsOf$RAW-Normal_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_Normal =  "PropsOf$RAW-Normal" ;
char *nameFun_M_PropsOf_sRAW_Normal(Term term) { return name_M_PropsOf_sRAW_Normal; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_Normal = {&sort_M_PropsOf_sRAW_Normal_xSORT, Data_M_PropsOf_sRAW_Normal, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_Normal), noBinderOffsets, &nameFun_M_PropsOf_sRAW_Normal, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_Normal_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_Normal,  NULL};
char *sortNam_M_PropsOf_sRAW_Normal_xSORT[] = {NULL, NULL,  "PropsOf$RAW-Normal" ,  NULL};
char *sortInt_M_PropsOf_sRAW_Normal_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_Normal",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_Normal_xSORT = { "PropsOf$RAW-Normal_SORT" , sortCon_M_PropsOf_sRAW_Normal_xSORT, sortNam_M_PropsOf_sRAW_Normal_xSORT, sortInt_M_PropsOf_sRAW_Normal_xSORT, NULL};

/* SORT PropsOf$RAW-ParsedDone_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_ParsedDone =  "PropsOf$RAW-ParsedDone" ;
char *nameFun_M_PropsOf_sRAW_ParsedDone(Term term) { return name_M_PropsOf_sRAW_ParsedDone; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_ParsedDone = {&sort_M_PropsOf_sRAW_ParsedDone_xSORT, Data_M_PropsOf_sRAW_ParsedDone, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_ParsedDone), noBinderOffsets, &nameFun_M_PropsOf_sRAW_ParsedDone, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_ParsedDone_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_ParsedDone,  NULL};
char *sortNam_M_PropsOf_sRAW_ParsedDone_xSORT[] = {NULL, NULL,  "PropsOf$RAW-ParsedDone" ,  NULL};
char *sortInt_M_PropsOf_sRAW_ParsedDone_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_ParsedDone",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_ParsedDone_xSORT = { "PropsOf$RAW-ParsedDone_SORT" , sortCon_M_PropsOf_sRAW_ParsedDone_xSORT, sortNam_M_PropsOf_sRAW_ParsedDone_xSORT, sortInt_M_PropsOf_sRAW_ParsedDone_xSORT, NULL};

/* SORT PropsOf$RAW-ParsedFormDone_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_ParsedFormDone =  "PropsOf$RAW-ParsedFormDone" ;
char *nameFun_M_PropsOf_sRAW_ParsedFormDone(Term term) { return name_M_PropsOf_sRAW_ParsedFormDone; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_ParsedFormDone = {&sort_M_PropsOf_sRAW_ParsedFormDone_xSORT, Data_M_PropsOf_sRAW_ParsedFormDone, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_ParsedFormDone), noBinderOffsets, &nameFun_M_PropsOf_sRAW_ParsedFormDone, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_ParsedFormDone_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_ParsedFormDone,  NULL};
char *sortNam_M_PropsOf_sRAW_ParsedFormDone_xSORT[] = {NULL, NULL,  "PropsOf$RAW-ParsedFormDone" ,  NULL};
char *sortInt_M_PropsOf_sRAW_ParsedFormDone_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_ParsedFormDone",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_ParsedFormDone_xSORT = { "PropsOf$RAW-ParsedFormDone_SORT" , sortCon_M_PropsOf_sRAW_ParsedFormDone_xSORT, sortNam_M_PropsOf_sRAW_ParsedFormDone_xSORT, sortInt_M_PropsOf_sRAW_ParsedFormDone_xSORT, NULL};

/* SORT PropsOf$RAW-ParsedFormSpace_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_ParsedFormSpace =  "PropsOf$RAW-ParsedFormSpace" ;
char *nameFun_M_PropsOf_sRAW_ParsedFormSpace(Term term) { return name_M_PropsOf_sRAW_ParsedFormSpace; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_ParsedFormSpace = {&sort_M_PropsOf_sRAW_ParsedFormSpace_xSORT, Data_M_PropsOf_sRAW_ParsedFormSpace, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_ParsedFormSpace), noBinderOffsets, &nameFun_M_PropsOf_sRAW_ParsedFormSpace, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_ParsedFormSpace_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_ParsedFormSpace,  NULL};
char *sortNam_M_PropsOf_sRAW_ParsedFormSpace_xSORT[] = {NULL, NULL,  "PropsOf$RAW-ParsedFormSpace" ,  NULL};
char *sortInt_M_PropsOf_sRAW_ParsedFormSpace_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_ParsedFormSpace",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_ParsedFormSpace_xSORT = { "PropsOf$RAW-ParsedFormSpace_SORT" , sortCon_M_PropsOf_sRAW_ParsedFormSpace_xSORT, sortNam_M_PropsOf_sRAW_ParsedFormSpace_xSORT, sortInt_M_PropsOf_sRAW_ParsedFormSpace_xSORT, NULL};

/* SORT PropsOf$RAW-ParsedFormTerm_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_ParsedFormTerm =  "PropsOf$RAW-ParsedFormTerm" ;
char *nameFun_M_PropsOf_sRAW_ParsedFormTerm(Term term) { return name_M_PropsOf_sRAW_ParsedFormTerm; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_ParsedFormTerm = {&sort_M_PropsOf_sRAW_ParsedFormTerm_xSORT, Data_M_PropsOf_sRAW_ParsedFormTerm, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_ParsedFormTerm), noBinderOffsets, &nameFun_M_PropsOf_sRAW_ParsedFormTerm, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_ParsedFormTerm_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_ParsedFormTerm,  NULL};
char *sortNam_M_PropsOf_sRAW_ParsedFormTerm_xSORT[] = {NULL, NULL,  "PropsOf$RAW-ParsedFormTerm" ,  NULL};
char *sortInt_M_PropsOf_sRAW_ParsedFormTerm_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_ParsedFormTerm",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_ParsedFormTerm_xSORT = { "PropsOf$RAW-ParsedFormTerm_SORT" , sortCon_M_PropsOf_sRAW_ParsedFormTerm_xSORT, sortNam_M_PropsOf_sRAW_ParsedFormTerm_xSORT, sortInt_M_PropsOf_sRAW_ParsedFormTerm_xSORT, NULL};

/* SORT PropsOf$RAW-ParsedFormWord_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_ParsedFormWord =  "PropsOf$RAW-ParsedFormWord" ;
char *nameFun_M_PropsOf_sRAW_ParsedFormWord(Term term) { return name_M_PropsOf_sRAW_ParsedFormWord; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_ParsedFormWord = {&sort_M_PropsOf_sRAW_ParsedFormWord_xSORT, Data_M_PropsOf_sRAW_ParsedFormWord, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_ParsedFormWord), noBinderOffsets, &nameFun_M_PropsOf_sRAW_ParsedFormWord, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_ParsedFormWord_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_ParsedFormWord,  NULL};
char *sortNam_M_PropsOf_sRAW_ParsedFormWord_xSORT[] = {NULL, NULL,  "PropsOf$RAW-ParsedFormWord" ,  NULL};
char *sortInt_M_PropsOf_sRAW_ParsedFormWord_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_ParsedFormWord",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_ParsedFormWord_xSORT = { "PropsOf$RAW-ParsedFormWord_SORT" , sortCon_M_PropsOf_sRAW_ParsedFormWord_xSORT, sortNam_M_PropsOf_sRAW_ParsedFormWord_xSORT, sortInt_M_PropsOf_sRAW_ParsedFormWord_xSORT, NULL};

/* SORT PropsOf$RAW-ParsedSorted_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_ParsedSorted =  "PropsOf$RAW-ParsedSorted" ;
char *nameFun_M_PropsOf_sRAW_ParsedSorted(Term term) { return name_M_PropsOf_sRAW_ParsedSorted; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_ParsedSorted = {&sort_M_PropsOf_sRAW_ParsedSorted_xSORT, Data_M_PropsOf_sRAW_ParsedSorted, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_ParsedSorted), noBinderOffsets, &nameFun_M_PropsOf_sRAW_ParsedSorted, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_ParsedSorted_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_ParsedSorted,  NULL};
char *sortNam_M_PropsOf_sRAW_ParsedSorted_xSORT[] = {NULL, NULL,  "PropsOf$RAW-ParsedSorted" ,  NULL};
char *sortInt_M_PropsOf_sRAW_ParsedSorted_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_ParsedSorted",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_ParsedSorted_xSORT = { "PropsOf$RAW-ParsedSorted_SORT" , sortCon_M_PropsOf_sRAW_ParsedSorted_xSORT, sortNam_M_PropsOf_sRAW_ParsedSorted_xSORT, sortInt_M_PropsOf_sRAW_ParsedSorted_xSORT, NULL};

/* SORT PropsOf$RAW-ParsedTerm_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_ParsedTerm =  "PropsOf$RAW-ParsedTerm" ;
char *nameFun_M_PropsOf_sRAW_ParsedTerm(Term term) { return name_M_PropsOf_sRAW_ParsedTerm; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_ParsedTerm = {&sort_M_PropsOf_sRAW_ParsedTerm_xSORT, Data_M_PropsOf_sRAW_ParsedTerm, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_ParsedTerm), noBinderOffsets, &nameFun_M_PropsOf_sRAW_ParsedTerm, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_ParsedTerm_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_ParsedTerm,  NULL};
char *sortNam_M_PropsOf_sRAW_ParsedTerm_xSORT[] = {NULL, NULL,  "PropsOf$RAW-ParsedTerm" ,  NULL};
char *sortInt_M_PropsOf_sRAW_ParsedTerm_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_ParsedTerm",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_ParsedTerm_xSORT = { "PropsOf$RAW-ParsedTerm_SORT" , sortCon_M_PropsOf_sRAW_ParsedTerm_xSORT, sortNam_M_PropsOf_sRAW_ParsedTerm_xSORT, sortInt_M_PropsOf_sRAW_ParsedTerm_xSORT, NULL};

/* SORT PropsOf$RAW-ParsedWord_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_ParsedWord =  "PropsOf$RAW-ParsedWord" ;
char *nameFun_M_PropsOf_sRAW_ParsedWord(Term term) { return name_M_PropsOf_sRAW_ParsedWord; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_ParsedWord = {&sort_M_PropsOf_sRAW_ParsedWord_xSORT, Data_M_PropsOf_sRAW_ParsedWord, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_ParsedWord), noBinderOffsets, &nameFun_M_PropsOf_sRAW_ParsedWord, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_ParsedWord_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_ParsedWord,  NULL};
char *sortNam_M_PropsOf_sRAW_ParsedWord_xSORT[] = {NULL, NULL,  "PropsOf$RAW-ParsedWord" ,  NULL};
char *sortInt_M_PropsOf_sRAW_ParsedWord_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_ParsedWord",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_ParsedWord_xSORT = { "PropsOf$RAW-ParsedWord_SORT" , sortCon_M_PropsOf_sRAW_ParsedWord_xSORT, sortNam_M_PropsOf_sRAW_ParsedWord_xSORT, sortInt_M_PropsOf_sRAW_ParsedWord_xSORT, NULL};

/* SORT PropsOf$RAW-Parsed_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_Parsed =  "PropsOf$RAW-Parsed" ;
char *nameFun_M_PropsOf_sRAW_Parsed(Term term) { return name_M_PropsOf_sRAW_Parsed; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_Parsed = {&sort_M_PropsOf_sRAW_Parsed_xSORT, Data_M_PropsOf_sRAW_Parsed, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_Parsed), noBinderOffsets, &nameFun_M_PropsOf_sRAW_Parsed, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_Parsed_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_Parsed,  NULL};
char *sortNam_M_PropsOf_sRAW_Parsed_xSORT[] = {NULL, NULL,  "PropsOf$RAW-Parsed" ,  NULL};
char *sortInt_M_PropsOf_sRAW_Parsed_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_Parsed",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_Parsed_xSORT = { "PropsOf$RAW-Parsed_SORT" , sortCon_M_PropsOf_sRAW_Parsed_xSORT, sortNam_M_PropsOf_sRAW_Parsed_xSORT, sortInt_M_PropsOf_sRAW_Parsed_xSORT, NULL};

/* SORT PropsOf$RAW-RegExpAny_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_RegExpAny =  "PropsOf$RAW-RegExpAny" ;
char *nameFun_M_PropsOf_sRAW_RegExpAny(Term term) { return name_M_PropsOf_sRAW_RegExpAny; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_RegExpAny = {&sort_M_PropsOf_sRAW_RegExpAny_xSORT, Data_M_PropsOf_sRAW_RegExpAny, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_RegExpAny), noBinderOffsets, &nameFun_M_PropsOf_sRAW_RegExpAny, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_RegExpAny_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_RegExpAny,  NULL};
char *sortNam_M_PropsOf_sRAW_RegExpAny_xSORT[] = {NULL, NULL,  "PropsOf$RAW-RegExpAny" ,  NULL};
char *sortInt_M_PropsOf_sRAW_RegExpAny_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_RegExpAny",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_RegExpAny_xSORT = { "PropsOf$RAW-RegExpAny_SORT" , sortCon_M_PropsOf_sRAW_RegExpAny_xSORT, sortNam_M_PropsOf_sRAW_RegExpAny_xSORT, sortInt_M_PropsOf_sRAW_RegExpAny_xSORT, NULL};

/* SORT PropsOf$RAW-RegExpClassChar_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_RegExpClassChar =  "PropsOf$RAW-RegExpClassChar" ;
char *nameFun_M_PropsOf_sRAW_RegExpClassChar(Term term) { return name_M_PropsOf_sRAW_RegExpClassChar; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_RegExpClassChar = {&sort_M_PropsOf_sRAW_RegExpClassChar_xSORT, Data_M_PropsOf_sRAW_RegExpClassChar, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_RegExpClassChar), noBinderOffsets, &nameFun_M_PropsOf_sRAW_RegExpClassChar, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_RegExpClassChar_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_RegExpClassChar,  NULL};
char *sortNam_M_PropsOf_sRAW_RegExpClassChar_xSORT[] = {NULL, NULL,  "PropsOf$RAW-RegExpClassChar" ,  NULL};
char *sortInt_M_PropsOf_sRAW_RegExpClassChar_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_RegExpClassChar",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_RegExpClassChar_xSORT = { "PropsOf$RAW-RegExpClassChar_SORT" , sortCon_M_PropsOf_sRAW_RegExpClassChar_xSORT, sortNam_M_PropsOf_sRAW_RegExpClassChar_xSORT, sortInt_M_PropsOf_sRAW_RegExpClassChar_xSORT, NULL};

/* SORT PropsOf$RAW-RegExpClassDone_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_RegExpClassDone =  "PropsOf$RAW-RegExpClassDone" ;
char *nameFun_M_PropsOf_sRAW_RegExpClassDone(Term term) { return name_M_PropsOf_sRAW_RegExpClassDone; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_RegExpClassDone = {&sort_M_PropsOf_sRAW_RegExpClassDone_xSORT, Data_M_PropsOf_sRAW_RegExpClassDone, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_RegExpClassDone), noBinderOffsets, &nameFun_M_PropsOf_sRAW_RegExpClassDone, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_RegExpClassDone_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_RegExpClassDone,  NULL};
char *sortNam_M_PropsOf_sRAW_RegExpClassDone_xSORT[] = {NULL, NULL,  "PropsOf$RAW-RegExpClassDone" ,  NULL};
char *sortInt_M_PropsOf_sRAW_RegExpClassDone_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_RegExpClassDone",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_RegExpClassDone_xSORT = { "PropsOf$RAW-RegExpClassDone_SORT" , sortCon_M_PropsOf_sRAW_RegExpClassDone_xSORT, sortNam_M_PropsOf_sRAW_RegExpClassDone_xSORT, sortInt_M_PropsOf_sRAW_RegExpClassDone_xSORT, NULL};

/* SORT PropsOf$RAW-RegExpClassNot_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_RegExpClassNot =  "PropsOf$RAW-RegExpClassNot" ;
char *nameFun_M_PropsOf_sRAW_RegExpClassNot(Term term) { return name_M_PropsOf_sRAW_RegExpClassNot; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_RegExpClassNot = {&sort_M_PropsOf_sRAW_RegExpClassNot_xSORT, Data_M_PropsOf_sRAW_RegExpClassNot, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_RegExpClassNot), noBinderOffsets, &nameFun_M_PropsOf_sRAW_RegExpClassNot, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_RegExpClassNot_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_RegExpClassNot,  NULL};
char *sortNam_M_PropsOf_sRAW_RegExpClassNot_xSORT[] = {NULL, NULL,  "PropsOf$RAW-RegExpClassNot" ,  NULL};
char *sortInt_M_PropsOf_sRAW_RegExpClassNot_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_RegExpClassNot",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_RegExpClassNot_xSORT = { "PropsOf$RAW-RegExpClassNot_SORT" , sortCon_M_PropsOf_sRAW_RegExpClassNot_xSORT, sortNam_M_PropsOf_sRAW_RegExpClassNot_xSORT, sortInt_M_PropsOf_sRAW_RegExpClassNot_xSORT, NULL};

/* SORT PropsOf$RAW-RegExpClassRange_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_RegExpClassRange =  "PropsOf$RAW-RegExpClassRange" ;
char *nameFun_M_PropsOf_sRAW_RegExpClassRange(Term term) { return name_M_PropsOf_sRAW_RegExpClassRange; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_RegExpClassRange = {&sort_M_PropsOf_sRAW_RegExpClassRange_xSORT, Data_M_PropsOf_sRAW_RegExpClassRange, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_RegExpClassRange), noBinderOffsets, &nameFun_M_PropsOf_sRAW_RegExpClassRange, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_RegExpClassRange_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_RegExpClassRange,  NULL};
char *sortNam_M_PropsOf_sRAW_RegExpClassRange_xSORT[] = {NULL, NULL,  "PropsOf$RAW-RegExpClassRange" ,  NULL};
char *sortInt_M_PropsOf_sRAW_RegExpClassRange_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_RegExpClassRange",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_RegExpClassRange_xSORT = { "PropsOf$RAW-RegExpClassRange_SORT" , sortCon_M_PropsOf_sRAW_RegExpClassRange_xSORT, sortNam_M_PropsOf_sRAW_RegExpClassRange_xSORT, sortInt_M_PropsOf_sRAW_RegExpClassRange_xSORT, NULL};

/* SORT PropsOf$RAW-RegExpClass_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_RegExpClass =  "PropsOf$RAW-RegExpClass" ;
char *nameFun_M_PropsOf_sRAW_RegExpClass(Term term) { return name_M_PropsOf_sRAW_RegExpClass; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_RegExpClass = {&sort_M_PropsOf_sRAW_RegExpClass_xSORT, Data_M_PropsOf_sRAW_RegExpClass, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_RegExpClass), noBinderOffsets, &nameFun_M_PropsOf_sRAW_RegExpClass, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_RegExpClass_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_RegExpClass,  NULL};
char *sortNam_M_PropsOf_sRAW_RegExpClass_xSORT[] = {NULL, NULL,  "PropsOf$RAW-RegExpClass" ,  NULL};
char *sortInt_M_PropsOf_sRAW_RegExpClass_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_RegExpClass",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_RegExpClass_xSORT = { "PropsOf$RAW-RegExpClass_SORT" , sortCon_M_PropsOf_sRAW_RegExpClass_xSORT, sortNam_M_PropsOf_sRAW_RegExpClass_xSORT, sortInt_M_PropsOf_sRAW_RegExpClass_xSORT, NULL};

/* SORT PropsOf$RAW-RegExpConcat_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_RegExpConcat =  "PropsOf$RAW-RegExpConcat" ;
char *nameFun_M_PropsOf_sRAW_RegExpConcat(Term term) { return name_M_PropsOf_sRAW_RegExpConcat; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_RegExpConcat = {&sort_M_PropsOf_sRAW_RegExpConcat_xSORT, Data_M_PropsOf_sRAW_RegExpConcat, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_RegExpConcat), noBinderOffsets, &nameFun_M_PropsOf_sRAW_RegExpConcat, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_RegExpConcat_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_RegExpConcat,  NULL};
char *sortNam_M_PropsOf_sRAW_RegExpConcat_xSORT[] = {NULL, NULL,  "PropsOf$RAW-RegExpConcat" ,  NULL};
char *sortInt_M_PropsOf_sRAW_RegExpConcat_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_RegExpConcat",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_RegExpConcat_xSORT = { "PropsOf$RAW-RegExpConcat_SORT" , sortCon_M_PropsOf_sRAW_RegExpConcat_xSORT, sortNam_M_PropsOf_sRAW_RegExpConcat_xSORT, sortInt_M_PropsOf_sRAW_RegExpConcat_xSORT, NULL};

/* SORT PropsOf$RAW-RegExpNest_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_RegExpNest =  "PropsOf$RAW-RegExpNest" ;
char *nameFun_M_PropsOf_sRAW_RegExpNest(Term term) { return name_M_PropsOf_sRAW_RegExpNest; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_RegExpNest = {&sort_M_PropsOf_sRAW_RegExpNest_xSORT, Data_M_PropsOf_sRAW_RegExpNest, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_RegExpNest), noBinderOffsets, &nameFun_M_PropsOf_sRAW_RegExpNest, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_RegExpNest_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_RegExpNest,  NULL};
char *sortNam_M_PropsOf_sRAW_RegExpNest_xSORT[] = {NULL, NULL,  "PropsOf$RAW-RegExpNest" ,  NULL};
char *sortInt_M_PropsOf_sRAW_RegExpNest_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_RegExpNest",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_RegExpNest_xSORT = { "PropsOf$RAW-RegExpNest_SORT" , sortCon_M_PropsOf_sRAW_RegExpNest_xSORT, sortNam_M_PropsOf_sRAW_RegExpNest_xSORT, sortInt_M_PropsOf_sRAW_RegExpNest_xSORT, NULL};

/* SORT PropsOf$RAW-RegExpRef_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_RegExpRef =  "PropsOf$RAW-RegExpRef" ;
char *nameFun_M_PropsOf_sRAW_RegExpRef(Term term) { return name_M_PropsOf_sRAW_RegExpRef; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_RegExpRef = {&sort_M_PropsOf_sRAW_RegExpRef_xSORT, Data_M_PropsOf_sRAW_RegExpRef, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_RegExpRef), noBinderOffsets, &nameFun_M_PropsOf_sRAW_RegExpRef, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_RegExpRef_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_RegExpRef,  NULL};
char *sortNam_M_PropsOf_sRAW_RegExpRef_xSORT[] = {NULL, NULL,  "PropsOf$RAW-RegExpRef" ,  NULL};
char *sortInt_M_PropsOf_sRAW_RegExpRef_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_RegExpRef",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_RegExpRef_xSORT = { "PropsOf$RAW-RegExpRef_SORT" , sortCon_M_PropsOf_sRAW_RegExpRef_xSORT, sortNam_M_PropsOf_sRAW_RegExpRef_xSORT, sortInt_M_PropsOf_sRAW_RegExpRef_xSORT, NULL};

/* SORT PropsOf$RAW-RegExpString_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_RegExpString =  "PropsOf$RAW-RegExpString" ;
char *nameFun_M_PropsOf_sRAW_RegExpString(Term term) { return name_M_PropsOf_sRAW_RegExpString; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_RegExpString = {&sort_M_PropsOf_sRAW_RegExpString_xSORT, Data_M_PropsOf_sRAW_RegExpString, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_RegExpString), noBinderOffsets, &nameFun_M_PropsOf_sRAW_RegExpString, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_RegExpString_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_RegExpString,  NULL};
char *sortNam_M_PropsOf_sRAW_RegExpString_xSORT[] = {NULL, NULL,  "PropsOf$RAW-RegExpString" ,  NULL};
char *sortInt_M_PropsOf_sRAW_RegExpString_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_RegExpString",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_RegExpString_xSORT = { "PropsOf$RAW-RegExpString_SORT" , sortCon_M_PropsOf_sRAW_RegExpString_xSORT, sortNam_M_PropsOf_sRAW_RegExpString_xSORT, sortInt_M_PropsOf_sRAW_RegExpString_xSORT, NULL};

/* SORT PropsOf$RAW-RegExpUnit_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_RegExpUnit =  "PropsOf$RAW-RegExpUnit" ;
char *nameFun_M_PropsOf_sRAW_RegExpUnit(Term term) { return name_M_PropsOf_sRAW_RegExpUnit; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_RegExpUnit = {&sort_M_PropsOf_sRAW_RegExpUnit_xSORT, Data_M_PropsOf_sRAW_RegExpUnit, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_RegExpUnit), noBinderOffsets, &nameFun_M_PropsOf_sRAW_RegExpUnit, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_RegExpUnit_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_RegExpUnit,  NULL};
char *sortNam_M_PropsOf_sRAW_RegExpUnit_xSORT[] = {NULL, NULL,  "PropsOf$RAW-RegExpUnit" ,  NULL};
char *sortInt_M_PropsOf_sRAW_RegExpUnit_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_RegExpUnit",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_RegExpUnit_xSORT = { "PropsOf$RAW-RegExpUnit_SORT" , sortCon_M_PropsOf_sRAW_RegExpUnit_xSORT, sortNam_M_PropsOf_sRAW_RegExpUnit_xSORT, sortInt_M_PropsOf_sRAW_RegExpUnit_xSORT, NULL};

/* SORT PropsOf$RAW-RegExpWord_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_RegExpWord =  "PropsOf$RAW-RegExpWord" ;
char *nameFun_M_PropsOf_sRAW_RegExpWord(Term term) { return name_M_PropsOf_sRAW_RegExpWord; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_RegExpWord = {&sort_M_PropsOf_sRAW_RegExpWord_xSORT, Data_M_PropsOf_sRAW_RegExpWord, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_RegExpWord), noBinderOffsets, &nameFun_M_PropsOf_sRAW_RegExpWord, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_RegExpWord_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_RegExpWord,  NULL};
char *sortNam_M_PropsOf_sRAW_RegExpWord_xSORT[] = {NULL, NULL,  "PropsOf$RAW-RegExpWord" ,  NULL};
char *sortInt_M_PropsOf_sRAW_RegExpWord_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_RegExpWord",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_RegExpWord_xSORT = { "PropsOf$RAW-RegExpWord_SORT" , sortCon_M_PropsOf_sRAW_RegExpWord_xSORT, sortNam_M_PropsOf_sRAW_RegExpWord_xSORT, sortInt_M_PropsOf_sRAW_RegExpWord_xSORT, NULL};

/* SORT PropsOf$RAW-RepeatMaybeSome_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_RepeatMaybeSome =  "PropsOf$RAW-RepeatMaybeSome" ;
char *nameFun_M_PropsOf_sRAW_RepeatMaybeSome(Term term) { return name_M_PropsOf_sRAW_RepeatMaybeSome; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_RepeatMaybeSome = {&sort_M_PropsOf_sRAW_RepeatMaybeSome_xSORT, Data_M_PropsOf_sRAW_RepeatMaybeSome, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_RepeatMaybeSome), noBinderOffsets, &nameFun_M_PropsOf_sRAW_RepeatMaybeSome, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_RepeatMaybeSome_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_RepeatMaybeSome,  NULL};
char *sortNam_M_PropsOf_sRAW_RepeatMaybeSome_xSORT[] = {NULL, NULL,  "PropsOf$RAW-RepeatMaybeSome" ,  NULL};
char *sortInt_M_PropsOf_sRAW_RepeatMaybeSome_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_RepeatMaybeSome",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_RepeatMaybeSome_xSORT = { "PropsOf$RAW-RepeatMaybeSome_SORT" , sortCon_M_PropsOf_sRAW_RepeatMaybeSome_xSORT, sortNam_M_PropsOf_sRAW_RepeatMaybeSome_xSORT, sortInt_M_PropsOf_sRAW_RepeatMaybeSome_xSORT, NULL};

/* SORT PropsOf$RAW-RepeatMaybe_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_RepeatMaybe =  "PropsOf$RAW-RepeatMaybe" ;
char *nameFun_M_PropsOf_sRAW_RepeatMaybe(Term term) { return name_M_PropsOf_sRAW_RepeatMaybe; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_RepeatMaybe = {&sort_M_PropsOf_sRAW_RepeatMaybe_xSORT, Data_M_PropsOf_sRAW_RepeatMaybe, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_RepeatMaybe), noBinderOffsets, &nameFun_M_PropsOf_sRAW_RepeatMaybe, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_RepeatMaybe_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_RepeatMaybe,  NULL};
char *sortNam_M_PropsOf_sRAW_RepeatMaybe_xSORT[] = {NULL, NULL,  "PropsOf$RAW-RepeatMaybe" ,  NULL};
char *sortInt_M_PropsOf_sRAW_RepeatMaybe_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_RepeatMaybe",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_RepeatMaybe_xSORT = { "PropsOf$RAW-RepeatMaybe_SORT" , sortCon_M_PropsOf_sRAW_RepeatMaybe_xSORT, sortNam_M_PropsOf_sRAW_RepeatMaybe_xSORT, sortInt_M_PropsOf_sRAW_RepeatMaybe_xSORT, NULL};

/* SORT PropsOf$RAW-RepeatSingle_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_RepeatSingle =  "PropsOf$RAW-RepeatSingle" ;
char *nameFun_M_PropsOf_sRAW_RepeatSingle(Term term) { return name_M_PropsOf_sRAW_RepeatSingle; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_RepeatSingle = {&sort_M_PropsOf_sRAW_RepeatSingle_xSORT, Data_M_PropsOf_sRAW_RepeatSingle, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_RepeatSingle), noBinderOffsets, &nameFun_M_PropsOf_sRAW_RepeatSingle, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_RepeatSingle_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_RepeatSingle,  NULL};
char *sortNam_M_PropsOf_sRAW_RepeatSingle_xSORT[] = {NULL, NULL,  "PropsOf$RAW-RepeatSingle" ,  NULL};
char *sortInt_M_PropsOf_sRAW_RepeatSingle_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_RepeatSingle",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_RepeatSingle_xSORT = { "PropsOf$RAW-RepeatSingle_SORT" , sortCon_M_PropsOf_sRAW_RepeatSingle_xSORT, sortNam_M_PropsOf_sRAW_RepeatSingle_xSORT, sortInt_M_PropsOf_sRAW_RepeatSingle_xSORT, NULL};

/* SORT PropsOf$RAW-RepeatSomeSep_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_RepeatSomeSep =  "PropsOf$RAW-RepeatSomeSep" ;
char *nameFun_M_PropsOf_sRAW_RepeatSomeSep(Term term) { return name_M_PropsOf_sRAW_RepeatSomeSep; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_RepeatSomeSep = {&sort_M_PropsOf_sRAW_RepeatSomeSep_xSORT, Data_M_PropsOf_sRAW_RepeatSomeSep, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_RepeatSomeSep), noBinderOffsets, &nameFun_M_PropsOf_sRAW_RepeatSomeSep, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_RepeatSomeSep_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_RepeatSomeSep,  NULL};
char *sortNam_M_PropsOf_sRAW_RepeatSomeSep_xSORT[] = {NULL, NULL,  "PropsOf$RAW-RepeatSomeSep" ,  NULL};
char *sortInt_M_PropsOf_sRAW_RepeatSomeSep_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_RepeatSomeSep",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_RepeatSomeSep_xSORT = { "PropsOf$RAW-RepeatSomeSep_SORT" , sortCon_M_PropsOf_sRAW_RepeatSomeSep_xSORT, sortNam_M_PropsOf_sRAW_RepeatSomeSep_xSORT, sortInt_M_PropsOf_sRAW_RepeatSomeSep_xSORT, NULL};

/* SORT PropsOf$RAW-RepeatSome_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_RepeatSome =  "PropsOf$RAW-RepeatSome" ;
char *nameFun_M_PropsOf_sRAW_RepeatSome(Term term) { return name_M_PropsOf_sRAW_RepeatSome; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_RepeatSome = {&sort_M_PropsOf_sRAW_RepeatSome_xSORT, Data_M_PropsOf_sRAW_RepeatSome, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_RepeatSome), noBinderOffsets, &nameFun_M_PropsOf_sRAW_RepeatSome, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_RepeatSome_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_RepeatSome,  NULL};
char *sortNam_M_PropsOf_sRAW_RepeatSome_xSORT[] = {NULL, NULL,  "PropsOf$RAW-RepeatSome" ,  NULL};
char *sortInt_M_PropsOf_sRAW_RepeatSome_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_RepeatSome",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_RepeatSome_xSORT = { "PropsOf$RAW-RepeatSome_SORT" , sortCon_M_PropsOf_sRAW_RepeatSome_xSORT, sortNam_M_PropsOf_sRAW_RepeatSome_xSORT, sortInt_M_PropsOf_sRAW_RepeatSome_xSORT, NULL};

/* SORT PropsOf$RAW-Rule_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_Rule =  "PropsOf$RAW-Rule" ;
char *nameFun_M_PropsOf_sRAW_Rule(Term term) { return name_M_PropsOf_sRAW_Rule; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_Rule = {&sort_M_PropsOf_sRAW_Rule_xSORT, Data_M_PropsOf_sRAW_Rule, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_Rule), noBinderOffsets, &nameFun_M_PropsOf_sRAW_Rule, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_Rule_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_Rule,  NULL};
char *sortNam_M_PropsOf_sRAW_Rule_xSORT[] = {NULL, NULL,  "PropsOf$RAW-Rule" ,  NULL};
char *sortInt_M_PropsOf_sRAW_Rule_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_Rule",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_Rule_xSORT = { "PropsOf$RAW-Rule_SORT" , sortCon_M_PropsOf_sRAW_Rule_xSORT, sortNam_M_PropsOf_sRAW_Rule_xSORT, sortInt_M_PropsOf_sRAW_Rule_xSORT, NULL};

/* SORT PropsOf$RAW-ScopeSortBinder_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_ScopeSortBinder =  "PropsOf$RAW-ScopeSortBinder" ;
char *nameFun_M_PropsOf_sRAW_ScopeSortBinder(Term term) { return name_M_PropsOf_sRAW_ScopeSortBinder; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_ScopeSortBinder = {&sort_M_PropsOf_sRAW_ScopeSortBinder_xSORT, Data_M_PropsOf_sRAW_ScopeSortBinder, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_ScopeSortBinder), noBinderOffsets, &nameFun_M_PropsOf_sRAW_ScopeSortBinder, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_ScopeSortBinder_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_ScopeSortBinder,  NULL};
char *sortNam_M_PropsOf_sRAW_ScopeSortBinder_xSORT[] = {NULL, NULL,  "PropsOf$RAW-ScopeSortBinder" ,  NULL};
char *sortInt_M_PropsOf_sRAW_ScopeSortBinder_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_ScopeSortBinder",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_ScopeSortBinder_xSORT = { "PropsOf$RAW-ScopeSortBinder_SORT" , sortCon_M_PropsOf_sRAW_ScopeSortBinder_xSORT, sortNam_M_PropsOf_sRAW_ScopeSortBinder_xSORT, sortInt_M_PropsOf_sRAW_ScopeSortBinder_xSORT, NULL};

/* SORT PropsOf$RAW-ScopeSort_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_ScopeSort =  "PropsOf$RAW-ScopeSort" ;
char *nameFun_M_PropsOf_sRAW_ScopeSort(Term term) { return name_M_PropsOf_sRAW_ScopeSort; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_ScopeSort = {&sort_M_PropsOf_sRAW_ScopeSort_xSORT, Data_M_PropsOf_sRAW_ScopeSort, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_ScopeSort), noBinderOffsets, &nameFun_M_PropsOf_sRAW_ScopeSort, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_ScopeSort_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_ScopeSort,  NULL};
char *sortNam_M_PropsOf_sRAW_ScopeSort_xSORT[] = {NULL, NULL,  "PropsOf$RAW-ScopeSort" ,  NULL};
char *sortInt_M_PropsOf_sRAW_ScopeSort_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_ScopeSort",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_ScopeSort_xSORT = { "PropsOf$RAW-ScopeSort_SORT" , sortCon_M_PropsOf_sRAW_ScopeSort_xSORT, sortNam_M_PropsOf_sRAW_ScopeSort_xSORT, sortInt_M_PropsOf_sRAW_ScopeSort_xSORT, NULL};

/* SORT PropsOf$RAW-Scope_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_Scope =  "PropsOf$RAW-Scope" ;
char *nameFun_M_PropsOf_sRAW_Scope(Term term) { return name_M_PropsOf_sRAW_Scope; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_Scope = {&sort_M_PropsOf_sRAW_Scope_xSORT, Data_M_PropsOf_sRAW_Scope, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_Scope), noBinderOffsets, &nameFun_M_PropsOf_sRAW_Scope, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_Scope_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_Scope,  NULL};
char *sortNam_M_PropsOf_sRAW_Scope_xSORT[] = {NULL, NULL,  "PropsOf$RAW-Scope" ,  NULL};
char *sortInt_M_PropsOf_sRAW_Scope_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_Scope",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_Scope_xSORT = { "PropsOf$RAW-Scope_SORT" , sortCon_M_PropsOf_sRAW_Scope_xSORT, sortNam_M_PropsOf_sRAW_Scope_xSORT, sortInt_M_PropsOf_sRAW_Scope_xSORT, NULL};

/* SORT PropsOf$RAW-SortAbstractionBody_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_SortAbstractionBody =  "PropsOf$RAW-SortAbstractionBody" ;
char *nameFun_M_PropsOf_sRAW_SortAbstractionBody(Term term) { return name_M_PropsOf_sRAW_SortAbstractionBody; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_SortAbstractionBody = {&sort_M_PropsOf_sRAW_SortAbstractionBody_xSORT, Data_M_PropsOf_sRAW_SortAbstractionBody, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_SortAbstractionBody), noBinderOffsets, &nameFun_M_PropsOf_sRAW_SortAbstractionBody, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_SortAbstractionBody_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_SortAbstractionBody,  NULL};
char *sortNam_M_PropsOf_sRAW_SortAbstractionBody_xSORT[] = {NULL, NULL,  "PropsOf$RAW-SortAbstractionBody" ,  NULL};
char *sortInt_M_PropsOf_sRAW_SortAbstractionBody_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_SortAbstractionBody",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_SortAbstractionBody_xSORT = { "PropsOf$RAW-SortAbstractionBody_SORT" , sortCon_M_PropsOf_sRAW_SortAbstractionBody_xSORT, sortNam_M_PropsOf_sRAW_SortAbstractionBody_xSORT, sortInt_M_PropsOf_sRAW_SortAbstractionBody_xSORT, NULL};

/* SORT PropsOf$RAW-SortAbstractionParam_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_SortAbstractionParam =  "PropsOf$RAW-SortAbstractionParam" ;
char *nameFun_M_PropsOf_sRAW_SortAbstractionParam(Term term) { return name_M_PropsOf_sRAW_SortAbstractionParam; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_SortAbstractionParam = {&sort_M_PropsOf_sRAW_SortAbstractionParam_xSORT, Data_M_PropsOf_sRAW_SortAbstractionParam, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_SortAbstractionParam), noBinderOffsets, &nameFun_M_PropsOf_sRAW_SortAbstractionParam, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_SortAbstractionParam_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_SortAbstractionParam,  NULL};
char *sortNam_M_PropsOf_sRAW_SortAbstractionParam_xSORT[] = {NULL, NULL,  "PropsOf$RAW-SortAbstractionParam" ,  NULL};
char *sortInt_M_PropsOf_sRAW_SortAbstractionParam_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_SortAbstractionParam",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_SortAbstractionParam_xSORT = { "PropsOf$RAW-SortAbstractionParam_SORT" , sortCon_M_PropsOf_sRAW_SortAbstractionParam_xSORT, sortNam_M_PropsOf_sRAW_SortAbstractionParam_xSORT, sortInt_M_PropsOf_sRAW_SortAbstractionParam_xSORT, NULL};

/* SORT PropsOf$RAW-SortName_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_SortName =  "PropsOf$RAW-SortName" ;
char *nameFun_M_PropsOf_sRAW_SortName(Term term) { return name_M_PropsOf_sRAW_SortName; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_SortName = {&sort_M_PropsOf_sRAW_SortName_xSORT, Data_M_PropsOf_sRAW_SortName, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_SortName), noBinderOffsets, &nameFun_M_PropsOf_sRAW_SortName, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_SortName_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_SortName,  NULL};
char *sortNam_M_PropsOf_sRAW_SortName_xSORT[] = {NULL, NULL,  "PropsOf$RAW-SortName" ,  NULL};
char *sortInt_M_PropsOf_sRAW_SortName_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_SortName",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_SortName_xSORT = { "PropsOf$RAW-SortName_SORT" , sortCon_M_PropsOf_sRAW_SortName_xSORT, sortNam_M_PropsOf_sRAW_SortName_xSORT, sortInt_M_PropsOf_sRAW_SortName_xSORT, NULL};

/* SORT PropsOf$RAW-SortParam_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_SortParam =  "PropsOf$RAW-SortParam" ;
char *nameFun_M_PropsOf_sRAW_SortParam(Term term) { return name_M_PropsOf_sRAW_SortParam; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_SortParam = {&sort_M_PropsOf_sRAW_SortParam_xSORT, Data_M_PropsOf_sRAW_SortParam, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_SortParam), noBinderOffsets, &nameFun_M_PropsOf_sRAW_SortParam, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_SortParam_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_SortParam,  NULL};
char *sortNam_M_PropsOf_sRAW_SortParam_xSORT[] = {NULL, NULL,  "PropsOf$RAW-SortParam" ,  NULL};
char *sortInt_M_PropsOf_sRAW_SortParam_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_SortParam",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_SortParam_xSORT = { "PropsOf$RAW-SortParam_SORT" , sortCon_M_PropsOf_sRAW_SortParam_xSORT, sortNam_M_PropsOf_sRAW_SortParam_xSORT, sortInt_M_PropsOf_sRAW_SortParam_xSORT, NULL};

/* SORT PropsOf$RAW-Sort_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_Sort =  "PropsOf$RAW-Sort" ;
char *nameFun_M_PropsOf_sRAW_Sort(Term term) { return name_M_PropsOf_sRAW_Sort; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_Sort = {&sort_M_PropsOf_sRAW_Sort_xSORT, Data_M_PropsOf_sRAW_Sort, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_Sort), noBinderOffsets, &nameFun_M_PropsOf_sRAW_Sort, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_Sort_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_Sort,  NULL};
char *sortNam_M_PropsOf_sRAW_Sort_xSORT[] = {NULL, NULL,  "PropsOf$RAW-Sort" ,  NULL};
char *sortInt_M_PropsOf_sRAW_Sort_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_Sort",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_Sort_xSORT = { "PropsOf$RAW-Sort_SORT" , sortCon_M_PropsOf_sRAW_Sort_xSORT, sortNam_M_PropsOf_sRAW_Sort_xSORT, sortInt_M_PropsOf_sRAW_Sort_xSORT, NULL};

/* SORT PropsOf$RAW-Special_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_Special =  "PropsOf$RAW-Special" ;
char *nameFun_M_PropsOf_sRAW_Special(Term term) { return name_M_PropsOf_sRAW_Special; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_Special = {&sort_M_PropsOf_sRAW_Special_xSORT, Data_M_PropsOf_sRAW_Special, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_Special), noBinderOffsets, &nameFun_M_PropsOf_sRAW_Special, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_Special_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_Special,  NULL};
char *sortNam_M_PropsOf_sRAW_Special_xSORT[] = {NULL, NULL,  "PropsOf$RAW-Special" ,  NULL};
char *sortInt_M_PropsOf_sRAW_Special_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_Special",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_Special_xSORT = { "PropsOf$RAW-Special_SORT" , sortCon_M_PropsOf_sRAW_Special_xSORT, sortNam_M_PropsOf_sRAW_Special_xSORT, sortInt_M_PropsOf_sRAW_Special_xSORT, NULL};

/* SORT PropsOf$RAW-SubstituteSort_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_SubstituteSort =  "PropsOf$RAW-SubstituteSort" ;
char *nameFun_M_PropsOf_sRAW_SubstituteSort(Term term) { return name_M_PropsOf_sRAW_SubstituteSort; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_SubstituteSort = {&sort_M_PropsOf_sRAW_SubstituteSort_xSORT, Data_M_PropsOf_sRAW_SubstituteSort, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_SubstituteSort), noBinderOffsets, &nameFun_M_PropsOf_sRAW_SubstituteSort, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_SubstituteSort_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_SubstituteSort,  NULL};
char *sortNam_M_PropsOf_sRAW_SubstituteSort_xSORT[] = {NULL, NULL,  "PropsOf$RAW-SubstituteSort" ,  NULL};
char *sortInt_M_PropsOf_sRAW_SubstituteSort_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_SubstituteSort",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_SubstituteSort_xSORT = { "PropsOf$RAW-SubstituteSort_SORT" , sortCon_M_PropsOf_sRAW_SubstituteSort_xSORT, sortNam_M_PropsOf_sRAW_SubstituteSort_xSORT, sortInt_M_PropsOf_sRAW_SubstituteSort_xSORT, NULL};

/* SORT PropsOf$RAW-SynthesizedRef_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_SynthesizedRef =  "PropsOf$RAW-SynthesizedRef" ;
char *nameFun_M_PropsOf_sRAW_SynthesizedRef(Term term) { return name_M_PropsOf_sRAW_SynthesizedRef; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_SynthesizedRef = {&sort_M_PropsOf_sRAW_SynthesizedRef_xSORT, Data_M_PropsOf_sRAW_SynthesizedRef, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_SynthesizedRef), noBinderOffsets, &nameFun_M_PropsOf_sRAW_SynthesizedRef, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_SynthesizedRef_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_SynthesizedRef,  NULL};
char *sortNam_M_PropsOf_sRAW_SynthesizedRef_xSORT[] = {NULL, NULL,  "PropsOf$RAW-SynthesizedRef" ,  NULL};
char *sortInt_M_PropsOf_sRAW_SynthesizedRef_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_SynthesizedRef",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_SynthesizedRef_xSORT = { "PropsOf$RAW-SynthesizedRef_SORT" , sortCon_M_PropsOf_sRAW_SynthesizedRef_xSORT, sortNam_M_PropsOf_sRAW_SynthesizedRef_xSORT, sortInt_M_PropsOf_sRAW_SynthesizedRef_xSORT, NULL};

/* SORT PropsOf$RAW-VariableUseSorted_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_VariableUseSorted =  "PropsOf$RAW-VariableUseSorted" ;
char *nameFun_M_PropsOf_sRAW_VariableUseSorted(Term term) { return name_M_PropsOf_sRAW_VariableUseSorted; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_VariableUseSorted = {&sort_M_PropsOf_sRAW_VariableUseSorted_xSORT, Data_M_PropsOf_sRAW_VariableUseSorted, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_VariableUseSorted), noBinderOffsets, &nameFun_M_PropsOf_sRAW_VariableUseSorted, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_VariableUseSorted_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_VariableUseSorted,  NULL};
char *sortNam_M_PropsOf_sRAW_VariableUseSorted_xSORT[] = {NULL, NULL,  "PropsOf$RAW-VariableUseSorted" ,  NULL};
char *sortInt_M_PropsOf_sRAW_VariableUseSorted_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_VariableUseSorted",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_VariableUseSorted_xSORT = { "PropsOf$RAW-VariableUseSorted_SORT" , sortCon_M_PropsOf_sRAW_VariableUseSorted_xSORT, sortNam_M_PropsOf_sRAW_VariableUseSorted_xSORT, sortInt_M_PropsOf_sRAW_VariableUseSorted_xSORT, NULL};

/* SORT PropsOf$RAW-VariableUse_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW_VariableUse =  "PropsOf$RAW-VariableUse" ;
char *nameFun_M_PropsOf_sRAW_VariableUse(Term term) { return name_M_PropsOf_sRAW_VariableUse; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_VariableUse = {&sort_M_PropsOf_sRAW_VariableUse_xSORT, Data_M_PropsOf_sRAW_VariableUse, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW_VariableUse), noBinderOffsets, &nameFun_M_PropsOf_sRAW_VariableUse, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW_VariableUse_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW_VariableUse,  NULL};
char *sortNam_M_PropsOf_sRAW_VariableUse_xSORT[] = {NULL, NULL,  "PropsOf$RAW-VariableUse" ,  NULL};
char *sortInt_M_PropsOf_sRAW_VariableUse_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW_VariableUse",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW_VariableUse_xSORT = { "PropsOf$RAW-VariableUse_SORT" , sortCon_M_PropsOf_sRAW_VariableUse_xSORT, sortNam_M_PropsOf_sRAW_VariableUse_xSORT, sortInt_M_PropsOf_sRAW_VariableUse_xSORT, NULL};

/* SORT PropsOf$RAW-anonymous_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW__anonymous =  "PropsOf$RAW-anonymous" ;
char *nameFun_M_PropsOf_sRAW__anonymous(Term term) { return name_M_PropsOf_sRAW__anonymous; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__anonymous = {&sort_M_PropsOf_sRAW__anonymous_xSORT, Data_M_PropsOf_sRAW__anonymous, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW__anonymous), noBinderOffsets, &nameFun_M_PropsOf_sRAW__anonymous, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW__anonymous_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW__anonymous,  NULL};
char *sortNam_M_PropsOf_sRAW__anonymous_xSORT[] = {NULL, NULL,  "PropsOf$RAW-anonymous" ,  NULL};
char *sortInt_M_PropsOf_sRAW__anonymous_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW__anonymous",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW__anonymous_xSORT = { "PropsOf$RAW-anonymous_SORT" , sortCon_M_PropsOf_sRAW__anonymous_xSORT, sortNam_M_PropsOf_sRAW__anonymous_xSORT, sortInt_M_PropsOf_sRAW__anonymous_xSORT, NULL};

/* SORT PropsOf$RAW-attribute_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW__attribute =  "PropsOf$RAW-attribute" ;
char *nameFun_M_PropsOf_sRAW__attribute(Term term) { return name_M_PropsOf_sRAW__attribute; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__attribute = {&sort_M_PropsOf_sRAW__attribute_xSORT, Data_M_PropsOf_sRAW__attribute, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW__attribute), noBinderOffsets, &nameFun_M_PropsOf_sRAW__attribute, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW__attribute_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW__attribute,  NULL};
char *sortNam_M_PropsOf_sRAW__attribute_xSORT[] = {NULL, NULL,  "PropsOf$RAW-attribute" ,  NULL};
char *sortInt_M_PropsOf_sRAW__attribute_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW__attribute",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW__attribute_xSORT = { "PropsOf$RAW-attribute_SORT" , sortCon_M_PropsOf_sRAW__attribute_xSORT, sortNam_M_PropsOf_sRAW__attribute_xSORT, sortInt_M_PropsOf_sRAW__attribute_xSORT, NULL};

/* SORT PropsOf$RAW-data_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW__data =  "PropsOf$RAW-data" ;
char *nameFun_M_PropsOf_sRAW__data(Term term) { return name_M_PropsOf_sRAW__data; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__data = {&sort_M_PropsOf_sRAW__data_xSORT, Data_M_PropsOf_sRAW__data, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW__data), noBinderOffsets, &nameFun_M_PropsOf_sRAW__data, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW__data_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW__data,  NULL};
char *sortNam_M_PropsOf_sRAW__data_xSORT[] = {NULL, NULL,  "PropsOf$RAW-data" ,  NULL};
char *sortInt_M_PropsOf_sRAW__data_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW__data",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW__data_xSORT = { "PropsOf$RAW-data_SORT" , sortCon_M_PropsOf_sRAW__data_xSORT, sortNam_M_PropsOf_sRAW__data_xSORT, sortInt_M_PropsOf_sRAW__data_xSORT, NULL};

/* SORT PropsOf$RAW-default_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW__default =  "PropsOf$RAW-default" ;
char *nameFun_M_PropsOf_sRAW__default(Term term) { return name_M_PropsOf_sRAW__default; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__default = {&sort_M_PropsOf_sRAW__default_xSORT, Data_M_PropsOf_sRAW__default, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW__default), noBinderOffsets, &nameFun_M_PropsOf_sRAW__default, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW__default_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW__default,  NULL};
char *sortNam_M_PropsOf_sRAW__default_xSORT[] = {NULL, NULL,  "PropsOf$RAW-default" ,  NULL};
char *sortInt_M_PropsOf_sRAW__default_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW__default",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW__default_xSORT = { "PropsOf$RAW-default_SORT" , sortCon_M_PropsOf_sRAW__default_xSORT, sortNam_M_PropsOf_sRAW__default_xSORT, sortInt_M_PropsOf_sRAW__default_xSORT, NULL};

/* SORT PropsOf$RAW-embedded-module_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW__embedded__module =  "PropsOf$RAW-embedded-module" ;
char *nameFun_M_PropsOf_sRAW__embedded__module(Term term) { return name_M_PropsOf_sRAW__embedded__module; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__embedded__module = {&sort_M_PropsOf_sRAW__embedded__module_xSORT, Data_M_PropsOf_sRAW__embedded__module, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW__embedded__module), noBinderOffsets, &nameFun_M_PropsOf_sRAW__embedded__module, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW__embedded__module_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW__embedded__module,  NULL};
char *sortNam_M_PropsOf_sRAW__embedded__module_xSORT[] = {NULL, NULL,  "PropsOf$RAW-embedded-module" ,  NULL};
char *sortInt_M_PropsOf_sRAW__embedded__module_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW__embedded__module",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW__embedded__module_xSORT = { "PropsOf$RAW-embedded-module_SORT" , sortCon_M_PropsOf_sRAW__embedded__module_xSORT, sortNam_M_PropsOf_sRAW__embedded__module_xSORT, sortInt_M_PropsOf_sRAW__embedded__module_xSORT, NULL};

/* SORT PropsOf$RAW-fragment_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW__fragment =  "PropsOf$RAW-fragment" ;
char *nameFun_M_PropsOf_sRAW__fragment(Term term) { return name_M_PropsOf_sRAW__fragment; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__fragment = {&sort_M_PropsOf_sRAW__fragment_xSORT, Data_M_PropsOf_sRAW__fragment, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW__fragment), noBinderOffsets, &nameFun_M_PropsOf_sRAW__fragment, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW__fragment_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW__fragment,  NULL};
char *sortNam_M_PropsOf_sRAW__fragment_xSORT[] = {NULL, NULL,  "PropsOf$RAW-fragment" ,  NULL};
char *sortInt_M_PropsOf_sRAW__fragment_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW__fragment",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW__fragment_xSORT = { "PropsOf$RAW-fragment_SORT" , sortCon_M_PropsOf_sRAW__fragment_xSORT, sortNam_M_PropsOf_sRAW__fragment_xSORT, sortInt_M_PropsOf_sRAW__fragment_xSORT, NULL};

/* SORT PropsOf$RAW-import_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW__import =  "PropsOf$RAW-import" ;
char *nameFun_M_PropsOf_sRAW__import(Term term) { return name_M_PropsOf_sRAW__import; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__import = {&sort_M_PropsOf_sRAW__import_xSORT, Data_M_PropsOf_sRAW__import, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW__import), noBinderOffsets, &nameFun_M_PropsOf_sRAW__import, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW__import_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW__import,  NULL};
char *sortNam_M_PropsOf_sRAW__import_xSORT[] = {NULL, NULL,  "PropsOf$RAW-import" ,  NULL};
char *sortInt_M_PropsOf_sRAW__import_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW__import",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW__import_xSORT = { "PropsOf$RAW-import_SORT" , sortCon_M_PropsOf_sRAW__import_xSORT, sortNam_M_PropsOf_sRAW__import_xSORT, sortInt_M_PropsOf_sRAW__import_xSORT, NULL};

/* SORT PropsOf$RAW-module_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW__module =  "PropsOf$RAW-module" ;
char *nameFun_M_PropsOf_sRAW__module(Term term) { return name_M_PropsOf_sRAW__module; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__module = {&sort_M_PropsOf_sRAW__module_xSORT, Data_M_PropsOf_sRAW__module, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW__module), noBinderOffsets, &nameFun_M_PropsOf_sRAW__module, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW__module_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW__module,  NULL};
char *sortNam_M_PropsOf_sRAW__module_xSORT[] = {NULL, NULL,  "PropsOf$RAW-module" ,  NULL};
char *sortInt_M_PropsOf_sRAW__module_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW__module",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW__module_xSORT = { "PropsOf$RAW-module_SORT" , sortCon_M_PropsOf_sRAW__module_xSORT, sortNam_M_PropsOf_sRAW__module_xSORT, sortInt_M_PropsOf_sRAW__module_xSORT, NULL};

/* SORT PropsOf$RAW-nestedDeclarations_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW__nestedDeclarations =  "PropsOf$RAW-nestedDeclarations" ;
char *nameFun_M_PropsOf_sRAW__nestedDeclarations(Term term) { return name_M_PropsOf_sRAW__nestedDeclarations; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__nestedDeclarations = {&sort_M_PropsOf_sRAW__nestedDeclarations_xSORT, Data_M_PropsOf_sRAW__nestedDeclarations, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW__nestedDeclarations), noBinderOffsets, &nameFun_M_PropsOf_sRAW__nestedDeclarations, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW__nestedDeclarations_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW__nestedDeclarations,  NULL};
char *sortNam_M_PropsOf_sRAW__nestedDeclarations_xSORT[] = {NULL, NULL,  "PropsOf$RAW-nestedDeclarations" ,  NULL};
char *sortInt_M_PropsOf_sRAW__nestedDeclarations_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW__nestedDeclarations",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW__nestedDeclarations_xSORT = { "PropsOf$RAW-nestedDeclarations_SORT" , sortCon_M_PropsOf_sRAW__nestedDeclarations_xSORT, sortNam_M_PropsOf_sRAW__nestedDeclarations_xSORT, sortInt_M_PropsOf_sRAW__nestedDeclarations_xSORT, NULL};

/* SORT PropsOf$RAW-nested_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW__nested =  "PropsOf$RAW-nested" ;
char *nameFun_M_PropsOf_sRAW__nested(Term term) { return name_M_PropsOf_sRAW__nested; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__nested = {&sort_M_PropsOf_sRAW__nested_xSORT, Data_M_PropsOf_sRAW__nested, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW__nested), noBinderOffsets, &nameFun_M_PropsOf_sRAW__nested, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW__nested_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW__nested,  NULL};
char *sortNam_M_PropsOf_sRAW__nested_xSORT[] = {NULL, NULL,  "PropsOf$RAW-nested" ,  NULL};
char *sortInt_M_PropsOf_sRAW__nested_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW__nested",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW__nested_xSORT = { "PropsOf$RAW-nested_SORT" , sortCon_M_PropsOf_sRAW__nested_xSORT, sortNam_M_PropsOf_sRAW__nested_xSORT, sortInt_M_PropsOf_sRAW__nested_xSORT, NULL};

/* SORT PropsOf$RAW-priority_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW__priority =  "PropsOf$RAW-priority" ;
char *nameFun_M_PropsOf_sRAW__priority(Term term) { return name_M_PropsOf_sRAW__priority; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__priority = {&sort_M_PropsOf_sRAW__priority_xSORT, Data_M_PropsOf_sRAW__priority, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW__priority), noBinderOffsets, &nameFun_M_PropsOf_sRAW__priority, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW__priority_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW__priority,  NULL};
char *sortNam_M_PropsOf_sRAW__priority_xSORT[] = {NULL, NULL,  "PropsOf$RAW-priority" ,  NULL};
char *sortInt_M_PropsOf_sRAW__priority_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW__priority",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW__priority_xSORT = { "PropsOf$RAW-priority_SORT" , sortCon_M_PropsOf_sRAW__priority_xSORT, sortNam_M_PropsOf_sRAW__priority_xSORT, sortInt_M_PropsOf_sRAW__priority_xSORT, NULL};

/* SORT PropsOf$RAW-rule_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW__rule =  "PropsOf$RAW-rule" ;
char *nameFun_M_PropsOf_sRAW__rule(Term term) { return name_M_PropsOf_sRAW__rule; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__rule = {&sort_M_PropsOf_sRAW__rule_xSORT, Data_M_PropsOf_sRAW__rule, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW__rule), noBinderOffsets, &nameFun_M_PropsOf_sRAW__rule, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW__rule_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW__rule,  NULL};
char *sortNam_M_PropsOf_sRAW__rule_xSORT[] = {NULL, NULL,  "PropsOf$RAW-rule" ,  NULL};
char *sortInt_M_PropsOf_sRAW__rule_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW__rule",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW__rule_xSORT = { "PropsOf$RAW-rule_SORT" , sortCon_M_PropsOf_sRAW__rule_xSORT, sortNam_M_PropsOf_sRAW__rule_xSORT, sortInt_M_PropsOf_sRAW__rule_xSORT, NULL};

/* SORT PropsOf$RAW-scheme_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW__scheme =  "PropsOf$RAW-scheme" ;
char *nameFun_M_PropsOf_sRAW__scheme(Term term) { return name_M_PropsOf_sRAW__scheme; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__scheme = {&sort_M_PropsOf_sRAW__scheme_xSORT, Data_M_PropsOf_sRAW__scheme, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW__scheme), noBinderOffsets, &nameFun_M_PropsOf_sRAW__scheme, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW__scheme_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW__scheme,  NULL};
char *sortNam_M_PropsOf_sRAW__scheme_xSORT[] = {NULL, NULL,  "PropsOf$RAW-scheme" ,  NULL};
char *sortInt_M_PropsOf_sRAW__scheme_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW__scheme",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW__scheme_xSORT = { "PropsOf$RAW-scheme_SORT" , sortCon_M_PropsOf_sRAW__scheme_xSORT, sortNam_M_PropsOf_sRAW__scheme_xSORT, sortInt_M_PropsOf_sRAW__scheme_xSORT, NULL};

/* SORT PropsOf$RAW-sort_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW__sort =  "PropsOf$RAW-sort" ;
char *nameFun_M_PropsOf_sRAW__sort(Term term) { return name_M_PropsOf_sRAW__sort; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__sort = {&sort_M_PropsOf_sRAW__sort_xSORT, Data_M_PropsOf_sRAW__sort, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW__sort), noBinderOffsets, &nameFun_M_PropsOf_sRAW__sort, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW__sort_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW__sort,  NULL};
char *sortNam_M_PropsOf_sRAW__sort_xSORT[] = {NULL, NULL,  "PropsOf$RAW-sort" ,  NULL};
char *sortInt_M_PropsOf_sRAW__sort_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW__sort",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW__sort_xSORT = { "PropsOf$RAW-sort_SORT" , sortCon_M_PropsOf_sRAW__sort_xSORT, sortNam_M_PropsOf_sRAW__sort_xSORT, sortInt_M_PropsOf_sRAW__sort_xSORT, NULL};

/* SORT PropsOf$RAW-space_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW__space =  "PropsOf$RAW-space" ;
char *nameFun_M_PropsOf_sRAW__space(Term term) { return name_M_PropsOf_sRAW__space; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__space = {&sort_M_PropsOf_sRAW__space_xSORT, Data_M_PropsOf_sRAW__space, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW__space), noBinderOffsets, &nameFun_M_PropsOf_sRAW__space, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW__space_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW__space,  NULL};
char *sortNam_M_PropsOf_sRAW__space_xSORT[] = {NULL, NULL,  "PropsOf$RAW-space" ,  NULL};
char *sortInt_M_PropsOf_sRAW__space_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW__space",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW__space_xSORT = { "PropsOf$RAW-space_SORT" , sortCon_M_PropsOf_sRAW__space_xSORT, sortNam_M_PropsOf_sRAW__space_xSORT, sortInt_M_PropsOf_sRAW__space_xSORT, NULL};

/* SORT PropsOf$RAW-static_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW__static =  "PropsOf$RAW-static" ;
char *nameFun_M_PropsOf_sRAW__static(Term term) { return name_M_PropsOf_sRAW__static; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__static = {&sort_M_PropsOf_sRAW__static_xSORT, Data_M_PropsOf_sRAW__static, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW__static), noBinderOffsets, &nameFun_M_PropsOf_sRAW__static, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW__static_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW__static,  NULL};
char *sortNam_M_PropsOf_sRAW__static_xSORT[] = {NULL, NULL,  "PropsOf$RAW-static" ,  NULL};
char *sortInt_M_PropsOf_sRAW__static_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW__static",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW__static_xSORT = { "PropsOf$RAW-static_SORT" , sortCon_M_PropsOf_sRAW__static_xSORT, sortNam_M_PropsOf_sRAW__static_xSORT, sortInt_M_PropsOf_sRAW__static_xSORT, NULL};

/* SORT PropsOf$RAW-sugar_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW__sugar =  "PropsOf$RAW-sugar" ;
char *nameFun_M_PropsOf_sRAW__sugar(Term term) { return name_M_PropsOf_sRAW__sugar; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__sugar = {&sort_M_PropsOf_sRAW__sugar_xSORT, Data_M_PropsOf_sRAW__sugar, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW__sugar), noBinderOffsets, &nameFun_M_PropsOf_sRAW__sugar, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW__sugar_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW__sugar,  NULL};
char *sortNam_M_PropsOf_sRAW__sugar_xSORT[] = {NULL, NULL,  "PropsOf$RAW-sugar" ,  NULL};
char *sortInt_M_PropsOf_sRAW__sugar_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW__sugar",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW__sugar_xSORT = { "PropsOf$RAW-sugar_SORT" , sortCon_M_PropsOf_sRAW__sugar_xSORT, sortNam_M_PropsOf_sRAW__sugar_xSORT, sortInt_M_PropsOf_sRAW__sugar_xSORT, NULL};

/* SORT PropsOf$RAW-symbol_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW__symbol =  "PropsOf$RAW-symbol" ;
char *nameFun_M_PropsOf_sRAW__symbol(Term term) { return name_M_PropsOf_sRAW__symbol; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__symbol = {&sort_M_PropsOf_sRAW__symbol_xSORT, Data_M_PropsOf_sRAW__symbol, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW__symbol), noBinderOffsets, &nameFun_M_PropsOf_sRAW__symbol, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW__symbol_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW__symbol,  NULL};
char *sortNam_M_PropsOf_sRAW__symbol_xSORT[] = {NULL, NULL,  "PropsOf$RAW-symbol" ,  NULL};
char *sortInt_M_PropsOf_sRAW__symbol_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW__symbol",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW__symbol_xSORT = { "PropsOf$RAW-symbol_SORT" , sortCon_M_PropsOf_sRAW__symbol_xSORT, sortNam_M_PropsOf_sRAW__symbol_xSORT, sortInt_M_PropsOf_sRAW__symbol_xSORT, NULL};

/* SORT PropsOf$RAW-synthesizedrefs_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW__synthesizedrefs =  "PropsOf$RAW-synthesizedrefs" ;
char *nameFun_M_PropsOf_sRAW__synthesizedrefs(Term term) { return name_M_PropsOf_sRAW__synthesizedrefs; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__synthesizedrefs = {&sort_M_PropsOf_sRAW__synthesizedrefs_xSORT, Data_M_PropsOf_sRAW__synthesizedrefs, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW__synthesizedrefs), noBinderOffsets, &nameFun_M_PropsOf_sRAW__synthesizedrefs, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW__synthesizedrefs_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW__synthesizedrefs,  NULL};
char *sortNam_M_PropsOf_sRAW__synthesizedrefs_xSORT[] = {NULL, NULL,  "PropsOf$RAW-synthesizedrefs" ,  NULL};
char *sortInt_M_PropsOf_sRAW__synthesizedrefs_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW__synthesizedrefs",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW__synthesizedrefs_xSORT = { "PropsOf$RAW-synthesizedrefs_SORT" , sortCon_M_PropsOf_sRAW__synthesizedrefs_xSORT, sortNam_M_PropsOf_sRAW__synthesizedrefs_xSORT, sortInt_M_PropsOf_sRAW__synthesizedrefs_xSORT, NULL};

/* SORT PropsOf$RAW-token_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW__token =  "PropsOf$RAW-token" ;
char *nameFun_M_PropsOf_sRAW__token(Term term) { return name_M_PropsOf_sRAW__token; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__token = {&sort_M_PropsOf_sRAW__token_xSORT, Data_M_PropsOf_sRAW__token, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW__token), noBinderOffsets, &nameFun_M_PropsOf_sRAW__token, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW__token_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW__token,  NULL};
char *sortNam_M_PropsOf_sRAW__token_xSORT[] = {NULL, NULL,  "PropsOf$RAW-token" ,  NULL};
char *sortInt_M_PropsOf_sRAW__token_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW__token",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW__token_xSORT = { "PropsOf$RAW-token_SORT" , sortCon_M_PropsOf_sRAW__token_xSORT, sortNam_M_PropsOf_sRAW__token_xSORT, sortInt_M_PropsOf_sRAW__token_xSORT, NULL};

/* SORT PropsOf$RAW-top-module_SORT CONSTANTS. */
char *name_M_PropsOf_sRAW__top__module =  "PropsOf$RAW-top-module" ;
char *nameFun_M_PropsOf_sRAW__top__module(Term term) { return name_M_PropsOf_sRAW__top__module; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__top__module = {&sort_M_PropsOf_sRAW__top__module_xSORT, Data_M_PropsOf_sRAW__top__module, 0, sizeof(STRUCT_Con_M_PropsOf_sRAW__top__module), noBinderOffsets, &nameFun_M_PropsOf_sRAW__top__module, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRAW__top__module_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRAW__top__module,  NULL};
char *sortNam_M_PropsOf_sRAW__top__module_xSORT[] = {NULL, NULL,  "PropsOf$RAW-top-module" ,  NULL};
char *sortInt_M_PropsOf_sRAW__top__module_xSORT[] = {NULL, NULL, "_M_PropsOf_sRAW__top__module",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRAW__top__module_xSORT = { "PropsOf$RAW-top-module_SORT" , sortCon_M_PropsOf_sRAW__top__module_xSORT, sortNam_M_PropsOf_sRAW__top__module_xSORT, sortInt_M_PropsOf_sRAW__top__module_xSORT, NULL};

/* SORT PropsOf$RegExp$Cons_SORT CONSTANTS. */
char *name_M_PropsOf_sRegExp_sCons =  "PropsOf$RegExp$Cons" ;
char *nameFun_M_PropsOf_sRegExp_sCons(Term term) { return name_M_PropsOf_sRegExp_sCons; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRegExp_sCons = {&sort_M_PropsOf_sRegExp_sCons_xSORT, Data_M_PropsOf_sRegExp_sCons, 0, sizeof(STRUCT_Con_M_PropsOf_sRegExp_sCons), noBinderOffsets, &nameFun_M_PropsOf_sRegExp_sCons, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRegExp_sCons_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRegExp_sCons,  NULL};
char *sortNam_M_PropsOf_sRegExp_sCons_xSORT[] = {NULL, NULL,  "PropsOf$RegExp$Cons" ,  NULL};
char *sortInt_M_PropsOf_sRegExp_sCons_xSORT[] = {NULL, NULL, "_M_PropsOf_sRegExp_sCons",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRegExp_sCons_xSORT = { "PropsOf$RegExp$Cons_SORT" , sortCon_M_PropsOf_sRegExp_sCons_xSORT, sortNam_M_PropsOf_sRegExp_sCons_xSORT, sortInt_M_PropsOf_sRegExp_sCons_xSORT, NULL};

/* SORT PropsOf$RegExp$Nil_SORT CONSTANTS. */
char *name_M_PropsOf_sRegExp_sNil =  "PropsOf$RegExp$Nil" ;
char *nameFun_M_PropsOf_sRegExp_sNil(Term term) { return name_M_PropsOf_sRegExp_sNil; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sRegExp_sNil = {&sort_M_PropsOf_sRegExp_sNil_xSORT, Data_M_PropsOf_sRegExp_sNil, 0, sizeof(STRUCT_Con_M_PropsOf_sRegExp_sNil), noBinderOffsets, &nameFun_M_PropsOf_sRegExp_sNil, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sRegExp_sNil_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sRegExp_sNil,  NULL};
char *sortNam_M_PropsOf_sRegExp_sNil_xSORT[] = {NULL, NULL,  "PropsOf$RegExp$Nil" ,  NULL};
char *sortInt_M_PropsOf_sRegExp_sNil_xSORT[] = {NULL, NULL, "_M_PropsOf_sRegExp_sNil",  NULL};
struct _SortDescriptor sort_M_PropsOf_sRegExp_sNil_xSORT = { "PropsOf$RegExp$Nil_SORT" , sortCon_M_PropsOf_sRegExp_sNil_xSORT, sortNam_M_PropsOf_sRegExp_sNil_xSORT, sortInt_M_PropsOf_sRegExp_sNil_xSORT, NULL};

/* SORT PropsOf$TEXT_MAP_SORT CONSTANTS. */
char *name_M_PropsOf_sTEXT_xMAP =  "PropsOf$TEXT_MAP" ;
char *nameFun_M_PropsOf_sTEXT_xMAP(Term term) { return name_M_PropsOf_sTEXT_xMAP; }
struct _ConstructionDescriptor descriptor_M_PropsOf_sTEXT_xMAP = {&sort_M_PropsOf_sTEXT_xMAP_xSORT, Data_M_PropsOf_sTEXT_xMAP, 0, sizeof(STRUCT_Con_M_PropsOf_sTEXT_xMAP), noBinderOffsets, &nameFun_M_PropsOf_sTEXT_xMAP, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_sTEXT_xMAP_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_sTEXT_xMAP,  NULL};
char *sortNam_M_PropsOf_sTEXT_xMAP_xSORT[] = {NULL, NULL,  "PropsOf$TEXT_MAP" ,  NULL};
char *sortInt_M_PropsOf_sTEXT_xMAP_xSORT[] = {NULL, NULL, "_M_PropsOf_sTEXT_xMAP",  NULL};
struct _SortDescriptor sort_M_PropsOf_sTEXT_xMAP_xSORT = { "PropsOf$TEXT_MAP_SORT" , sortCon_M_PropsOf_sTEXT_xMAP_xSORT, sortNam_M_PropsOf_sTEXT_xMAP_xSORT, sortInt_M_PropsOf_sTEXT_xMAP_xSORT, NULL};

/* SORT RawAttribute CONSTANTS. */
int conBindOffs_M_RAW_Attribute[] = {0 , 0 , 0 , 0};
char *name_M_RAW_Attribute =  "RAW-Attribute" ;
char *nameFun_M_RAW_Attribute(Term term) { return name_M_RAW_Attribute; }
struct _ConstructionDescriptor descriptor_M_RAW_Attribute = {&sort_M_RawAttribute, Data_M_RAW_Attribute, 3, sizeof(STRUCT_Con_M_RAW_Attribute), conBindOffs_M_RAW_Attribute, &nameFun_M_RAW_Attribute, &dataStep};
ConstructionDescriptor sortCon_M_RawAttribute[] = {NULL, NULL, &descriptor_M_RAW_Attribute,  NULL};
char *sortNam_M_RawAttribute[] = {NULL, NULL,  "RAW-Attribute" ,  NULL};
char *sortInt_M_RawAttribute[] = {NULL, NULL, "_M_RAW_Attribute",  NULL};
struct _SortDescriptor sort_M_RawAttribute = { "RawAttribute" , sortCon_M_RawAttribute, sortNam_M_RawAttribute, sortInt_M_RawAttribute, NULL};

/* SORT RawAttributeForm CONSTANTS. */
int conBindOffs_M_RAW_AttributeFormMap[] = {0 , 0 , 0};
char *name_M_RAW_AttributeFormMap =  "RAW-AttributeFormMap" ;
char *nameFun_M_RAW_AttributeFormMap(Term term) { return name_M_RAW_AttributeFormMap; }
struct _ConstructionDescriptor descriptor_M_RAW_AttributeFormMap = {&sort_M_RawAttributeForm, Data_M_RAW_AttributeFormMap, 2, sizeof(STRUCT_Con_M_RAW_AttributeFormMap), conBindOffs_M_RAW_AttributeFormMap, &nameFun_M_RAW_AttributeFormMap, &dataStep};
int conBindOffs_M_RAW_AttributeFormSet[] = {0 , 0};
char *name_M_RAW_AttributeFormSet =  "RAW-AttributeFormSet" ;
char *nameFun_M_RAW_AttributeFormSet(Term term) { return name_M_RAW_AttributeFormSet; }
struct _ConstructionDescriptor descriptor_M_RAW_AttributeFormSet = {&sort_M_RawAttributeForm, Data_M_RAW_AttributeFormSet, 1, sizeof(STRUCT_Con_M_RAW_AttributeFormSet), conBindOffs_M_RAW_AttributeFormSet, &nameFun_M_RAW_AttributeFormSet, &dataStep};
int conBindOffs_M_RAW_AttributeFormSimple[] = {0 , 0};
char *name_M_RAW_AttributeFormSimple =  "RAW-AttributeFormSimple" ;
char *nameFun_M_RAW_AttributeFormSimple(Term term) { return name_M_RAW_AttributeFormSimple; }
struct _ConstructionDescriptor descriptor_M_RAW_AttributeFormSimple = {&sort_M_RawAttributeForm, Data_M_RAW_AttributeFormSimple, 1, sizeof(STRUCT_Con_M_RAW_AttributeFormSimple), conBindOffs_M_RAW_AttributeFormSimple, &nameFun_M_RAW_AttributeFormSimple, &dataStep};
ConstructionDescriptor sortCon_M_RawAttributeForm[] = {NULL, NULL, &descriptor_M_RAW_AttributeFormMap, &descriptor_M_RAW_AttributeFormSet, &descriptor_M_RAW_AttributeFormSimple,  NULL};
char *sortNam_M_RawAttributeForm[] = {NULL, NULL,  "RAW-AttributeFormMap" ,  "RAW-AttributeFormSet" ,  "RAW-AttributeFormSimple" ,  NULL};
char *sortInt_M_RawAttributeForm[] = {NULL, NULL, "_M_RAW_AttributeFormMap", "_M_RAW_AttributeFormSet", "_M_RAW_AttributeFormSimple",  NULL};
struct _SortDescriptor sort_M_RawAttributeForm = { "RawAttributeForm" , sortCon_M_RawAttributeForm, sortNam_M_RawAttributeForm, sortInt_M_RawAttributeForm, NULL};

/* SORT RawAttributeKind CONSTANTS. */
char *name_M_RAW_AttributeKindDown =  "RAW-AttributeKindDown" ;
char *nameFun_M_RAW_AttributeKindDown(Term term) { return name_M_RAW_AttributeKindDown; }
struct _ConstructionDescriptor descriptor_M_RAW_AttributeKindDown = {&sort_M_RawAttributeKind, Data_M_RAW_AttributeKindDown, 0, sizeof(STRUCT_Con_M_RAW_AttributeKindDown), noBinderOffsets, &nameFun_M_RAW_AttributeKindDown, &dataStep};
char *name_M_RAW_AttributeKindUp =  "RAW-AttributeKindUp" ;
char *nameFun_M_RAW_AttributeKindUp(Term term) { return name_M_RAW_AttributeKindUp; }
struct _ConstructionDescriptor descriptor_M_RAW_AttributeKindUp = {&sort_M_RawAttributeKind, Data_M_RAW_AttributeKindUp, 0, sizeof(STRUCT_Con_M_RAW_AttributeKindUp), noBinderOffsets, &nameFun_M_RAW_AttributeKindUp, &dataStep};
ConstructionDescriptor sortCon_M_RawAttributeKind[] = {NULL, NULL, &descriptor_M_RAW_AttributeKindDown, &descriptor_M_RAW_AttributeKindUp,  NULL};
char *sortNam_M_RawAttributeKind[] = {NULL, NULL,  "RAW-AttributeKindDown" ,  "RAW-AttributeKindUp" ,  NULL};
char *sortInt_M_RawAttributeKind[] = {NULL, NULL, "_M_RAW_AttributeKindDown", "_M_RAW_AttributeKindUp",  NULL};
struct _SortDescriptor sort_M_RawAttributeKind = { "RawAttributeKind" , sortCon_M_RawAttributeKind, sortNam_M_RawAttributeKind, sortInt_M_RawAttributeKind, NULL};

/* SORT RawAttributeOption CONSTANTS. */
int conBindOffs_M_RAW_AttributeOption[] = {0 , 0 , 0};
char *name_M_RAW_AttributeOption =  "RAW-AttributeOption" ;
char *nameFun_M_RAW_AttributeOption(Term term) { return name_M_RAW_AttributeOption; }
struct _ConstructionDescriptor descriptor_M_RAW_AttributeOption = {&sort_M_RawAttributeOption, Data_M_RAW_AttributeOption, 2, sizeof(STRUCT_Con_M_RAW_AttributeOption), conBindOffs_M_RAW_AttributeOption, &nameFun_M_RAW_AttributeOption, &dataStep};
ConstructionDescriptor sortCon_M_RawAttributeOption[] = {NULL, NULL, &descriptor_M_RAW_AttributeOption,  NULL};
char *sortNam_M_RawAttributeOption[] = {NULL, NULL,  "RAW-AttributeOption" ,  NULL};
char *sortInt_M_RawAttributeOption[] = {NULL, NULL, "_M_RAW_AttributeOption",  NULL};
struct _SortDescriptor sort_M_RawAttributeOption = { "RawAttributeOption" , sortCon_M_RawAttributeOption, sortNam_M_RawAttributeOption, sortInt_M_RawAttributeOption, NULL};

/* SORT RawAttributeValue CONSTANTS. */
int conBindOffs_M_RAW_AttributeValue[] = {0 , 0};
char *name_M_RAW_AttributeValue =  "RAW-AttributeValue" ;
char *nameFun_M_RAW_AttributeValue(Term term) { return name_M_RAW_AttributeValue; }
struct _ConstructionDescriptor descriptor_M_RAW_AttributeValue = {&sort_M_RawAttributeValue, Data_M_RAW_AttributeValue, 1, sizeof(STRUCT_Con_M_RAW_AttributeValue), conBindOffs_M_RAW_AttributeValue, &nameFun_M_RAW_AttributeValue, &dataStep};
int conBindOffs_M_RAW_AttributeKey[] = {0 , 0};
char *name_M_RAW_AttributeKey =  "RAW-AttributeKey" ;
char *nameFun_M_RAW_AttributeKey(Term term) { return name_M_RAW_AttributeKey; }
struct _ConstructionDescriptor descriptor_M_RAW_AttributeKey = {&sort_M_RawAttributeValue, Data_M_RAW_AttributeKey, 1, sizeof(STRUCT_Con_M_RAW_AttributeKey), conBindOffs_M_RAW_AttributeKey, &nameFun_M_RAW_AttributeKey, &dataStep};
int conBindOffs_M_RAW_AttributeKeyValue[] = {0 , 0 , 0};
char *name_M_RAW_AttributeKeyValue =  "RAW-AttributeKeyValue" ;
char *nameFun_M_RAW_AttributeKeyValue(Term term) { return name_M_RAW_AttributeKeyValue; }
struct _ConstructionDescriptor descriptor_M_RAW_AttributeKeyValue = {&sort_M_RawAttributeValue, Data_M_RAW_AttributeKeyValue, 2, sizeof(STRUCT_Con_M_RAW_AttributeKeyValue), conBindOffs_M_RAW_AttributeKeyValue, &nameFun_M_RAW_AttributeKeyValue, &dataStep};
int conBindOffs_M_RAW_AttributeNotKey[] = {0 , 0};
char *name_M_RAW_AttributeNotKey =  "RAW-AttributeNotKey" ;
char *nameFun_M_RAW_AttributeNotKey(Term term) { return name_M_RAW_AttributeNotKey; }
struct _ConstructionDescriptor descriptor_M_RAW_AttributeNotKey = {&sort_M_RawAttributeValue, Data_M_RAW_AttributeNotKey, 1, sizeof(STRUCT_Con_M_RAW_AttributeNotKey), conBindOffs_M_RAW_AttributeNotKey, &nameFun_M_RAW_AttributeNotKey, &dataStep};
ConstructionDescriptor sortCon_M_RawAttributeValue[] = {NULL, NULL, &descriptor_M_RAW_AttributeValue, &descriptor_M_RAW_AttributeKey, &descriptor_M_RAW_AttributeKeyValue, &descriptor_M_RAW_AttributeNotKey,  NULL};
char *sortNam_M_RawAttributeValue[] = {NULL, NULL,  "RAW-AttributeValue" ,  "RAW-AttributeKey" ,  "RAW-AttributeKeyValue" ,  "RAW-AttributeNotKey" ,  NULL};
char *sortInt_M_RawAttributeValue[] = {NULL, NULL, "_M_RAW_AttributeValue", "_M_RAW_AttributeKey", "_M_RAW_AttributeKeyValue", "_M_RAW_AttributeNotKey",  NULL};
struct _SortDescriptor sort_M_RawAttributeValue = { "RawAttributeValue" , sortCon_M_RawAttributeValue, sortNam_M_RawAttributeValue, sortInt_M_RawAttributeValue, NULL};

/* SORT RawDeclaration CONSTANTS. */
int conBindOffs_M_RAW__nestedDeclarations[] = {0 , 0};
char *name_M_RAW__nestedDeclarations =  "RAW-nestedDeclarations" ;
char *nameFun_M_RAW__nestedDeclarations(Term term) { return name_M_RAW__nestedDeclarations; }
struct _ConstructionDescriptor descriptor_M_RAW__nestedDeclarations = {&sort_M_RawDeclaration, Data_M_RAW__nestedDeclarations, 1, sizeof(STRUCT_Con_M_RAW__nestedDeclarations), conBindOffs_M_RAW__nestedDeclarations, &nameFun_M_RAW__nestedDeclarations, &dataStep};
int conBindOffs_M_RAW__space[] = {0 , 0};
char *name_M_RAW__space =  "RAW-space" ;
char *nameFun_M_RAW__space(Term term) { return name_M_RAW__space; }
struct _ConstructionDescriptor descriptor_M_RAW__space = {&sort_M_RawDeclaration, Data_M_RAW__space, 1, sizeof(STRUCT_Con_M_RAW__space), conBindOffs_M_RAW__space, &nameFun_M_RAW__space, &dataStep};
int conBindOffs_M_RAW__import[] = {0 , 0 , 0};
char *name_M_RAW__import =  "RAW-import" ;
char *nameFun_M_RAW__import(Term term) { return name_M_RAW__import; }
struct _ConstructionDescriptor descriptor_M_RAW__import = {&sort_M_RawDeclaration, Data_M_RAW__import, 2, sizeof(STRUCT_Con_M_RAW__import), conBindOffs_M_RAW__import, &nameFun_M_RAW__import, &dataStep};
int conBindOffs_M_RAW__embedded__module[] = {0 , 0};
char *name_M_RAW__embedded__module =  "RAW-embedded-module" ;
char *nameFun_M_RAW__embedded__module(Term term) { return name_M_RAW__embedded__module; }
struct _ConstructionDescriptor descriptor_M_RAW__embedded__module = {&sort_M_RawDeclaration, Data_M_RAW__embedded__module, 1, sizeof(STRUCT_Con_M_RAW__embedded__module), conBindOffs_M_RAW__embedded__module, &nameFun_M_RAW__embedded__module, &dataStep};
int conBindOffs_M_RAW__rule[] = {0 , 0};
char *name_M_RAW__rule =  "RAW-rule" ;
char *nameFun_M_RAW__rule(Term term) { return name_M_RAW__rule; }
struct _ConstructionDescriptor descriptor_M_RAW__rule = {&sort_M_RawDeclaration, Data_M_RAW__rule, 1, sizeof(STRUCT_Con_M_RAW__rule), conBindOffs_M_RAW__rule, &nameFun_M_RAW__rule, &dataStep};
int conBindOffs_M_RAW__attribute[] = {0 , 0 , 0 , 0 , 0};
char *name_M_RAW__attribute =  "RAW-attribute" ;
char *nameFun_M_RAW__attribute(Term term) { return name_M_RAW__attribute; }
struct _ConstructionDescriptor descriptor_M_RAW__attribute = {&sort_M_RawDeclaration, Data_M_RAW__attribute, 4, sizeof(STRUCT_Con_M_RAW__attribute), conBindOffs_M_RAW__attribute, &nameFun_M_RAW__attribute, &dataStep};
int conBindOffs_M_RAW__fragment[] = {0 , 0 , 0};
char *name_M_RAW__fragment =  "RAW-fragment" ;
char *nameFun_M_RAW__fragment(Term term) { return name_M_RAW__fragment; }
struct _ConstructionDescriptor descriptor_M_RAW__fragment = {&sort_M_RawDeclaration, Data_M_RAW__fragment, 2, sizeof(STRUCT_Con_M_RAW__fragment), conBindOffs_M_RAW__fragment, &nameFun_M_RAW__fragment, &dataStep};
int conBindOffs_M_RAW__synthesizedrefs[] = {0 , 0};
char *name_M_RAW__synthesizedrefs =  "RAW-synthesizedrefs" ;
char *nameFun_M_RAW__synthesizedrefs(Term term) { return name_M_RAW__synthesizedrefs; }
struct _ConstructionDescriptor descriptor_M_RAW__synthesizedrefs = {&sort_M_RawDeclaration, Data_M_RAW__synthesizedrefs, 1, sizeof(STRUCT_Con_M_RAW__synthesizedrefs), conBindOffs_M_RAW__synthesizedrefs, &nameFun_M_RAW__synthesizedrefs, &dataStep};
int conBindOffs_M_RAW__token[] = {0 , 0 , 0};
char *name_M_RAW__token =  "RAW-token" ;
char *nameFun_M_RAW__token(Term term) { return name_M_RAW__token; }
struct _ConstructionDescriptor descriptor_M_RAW__token = {&sort_M_RawDeclaration, Data_M_RAW__token, 2, sizeof(STRUCT_Con_M_RAW__token), conBindOffs_M_RAW__token, &nameFun_M_RAW__token, &dataStep};
int conBindOffs_M_RAW__sort[] = {0 , 0 , 0 , 0};
char *name_M_RAW__sort =  "RAW-sort" ;
char *nameFun_M_RAW__sort(Term term) { return name_M_RAW__sort; }
struct _ConstructionDescriptor descriptor_M_RAW__sort = {&sort_M_RawDeclaration, Data_M_RAW__sort, 3, sizeof(STRUCT_Con_M_RAW__sort), conBindOffs_M_RAW__sort, &nameFun_M_RAW__sort, &dataStep};
int conBindOffs_M_RAW__anonymous[] = {0 , 0};
char *name_M_RAW__anonymous =  "RAW-anonymous" ;
char *nameFun_M_RAW__anonymous(Term term) { return name_M_RAW__anonymous; }
struct _ConstructionDescriptor descriptor_M_RAW__anonymous = {&sort_M_RawDeclaration, Data_M_RAW__anonymous, 1, sizeof(STRUCT_Con_M_RAW__anonymous), conBindOffs_M_RAW__anonymous, &nameFun_M_RAW__anonymous, &dataStep};
ConstructionDescriptor sortCon_M_RawDeclaration[] = {NULL, NULL, &descriptor_M_RAW__nestedDeclarations, &descriptor_M_RAW__space, &descriptor_M_RAW__import, &descriptor_M_RAW__embedded__module, &descriptor_M_RAW__rule, &descriptor_M_RAW__attribute, &descriptor_M_RAW__fragment, &descriptor_M_RAW__synthesizedrefs, &descriptor_M_RAW__token, &descriptor_M_RAW__sort, &descriptor_M_RAW__anonymous,  NULL};
char *sortNam_M_RawDeclaration[] = {NULL, NULL,  "RAW-nestedDeclarations" ,  "RAW-space" ,  "RAW-import" ,  "RAW-embedded-module" ,  "RAW-rule" ,  "RAW-attribute" ,  "RAW-fragment" ,  "RAW-synthesizedrefs" ,  "RAW-token" ,  "RAW-sort" ,  "RAW-anonymous" ,  NULL};
char *sortInt_M_RawDeclaration[] = {NULL, NULL, "_M_RAW__nestedDeclarations", "_M_RAW__space", "_M_RAW__import", "_M_RAW__embedded__module", "_M_RAW__rule", "_M_RAW__attribute", "_M_RAW__fragment", "_M_RAW__synthesizedrefs", "_M_RAW__token", "_M_RAW__sort", "_M_RAW__anonymous",  NULL};
struct _SortDescriptor sort_M_RawDeclaration = { "RawDeclaration" , sortCon_M_RawDeclaration, sortNam_M_RawDeclaration, sortInt_M_RawDeclaration, NULL};

/* SORT RawDeclarations CONSTANTS. */
char *name_M_Declarations_sNil =  "Declarations$Nil" ;
char *nameFun_M_Declarations_sNil(Term term) { return name_M_Declarations_sNil; }
struct _ConstructionDescriptor descriptor_M_Declarations_sNil = {&sort_M_RawDeclarations, Data_M_Declarations_sNil, 0, sizeof(STRUCT_Con_M_Declarations_sNil), noBinderOffsets, &nameFun_M_Declarations_sNil, &dataStep};
int conBindOffs_M_RAW_Declarations_sCons[] = {0 , 0 , 0};
char *name_M_RAW_Declarations_sCons =  "RAW-Declarations$Cons" ;
char *nameFun_M_RAW_Declarations_sCons(Term term) { return name_M_RAW_Declarations_sCons; }
struct _ConstructionDescriptor descriptor_M_RAW_Declarations_sCons = {&sort_M_RawDeclarations, Data_M_RAW_Declarations_sCons, 2, sizeof(STRUCT_Con_M_RAW_Declarations_sCons), conBindOffs_M_RAW_Declarations_sCons, &nameFun_M_RAW_Declarations_sCons, &dataStep};
ConstructionDescriptor sortCon_M_RawDeclarations[] = {NULL, NULL, &descriptor_M_Declarations_sNil, &descriptor_M_RAW_Declarations_sCons,  NULL};
char *sortNam_M_RawDeclarations[] = {NULL, NULL,  "Declarations$Nil" ,  "RAW-Declarations$Cons" ,  NULL};
char *sortInt_M_RawDeclarations[] = {NULL, NULL, "_M_Declarations_sNil", "_M_RAW_Declarations_sCons",  NULL};
struct _SortDescriptor sort_M_RawDeclarations = { "RawDeclarations" , sortCon_M_RawDeclarations, sortNam_M_RawDeclarations, sortInt_M_RawDeclarations, NULL};

/* SORT RawEmbeddedModule CONSTANTS. */
int conBindOffs_M_RAW__module[] = {0 , 0 , 0};
char *name_M_RAW__module =  "RAW-module" ;
char *nameFun_M_RAW__module(Term term) { return name_M_RAW__module; }
struct _ConstructionDescriptor descriptor_M_RAW__module = {&sort_M_RawEmbeddedModule, Data_M_RAW__module, 2, sizeof(STRUCT_Con_M_RAW__module), conBindOffs_M_RAW__module, &nameFun_M_RAW__module, &dataStep};
ConstructionDescriptor sortCon_M_RawEmbeddedModule[] = {NULL, NULL, &descriptor_M_RAW__module,  NULL};
char *sortNam_M_RawEmbeddedModule[] = {NULL, NULL,  "RAW-module" ,  NULL};
char *sortInt_M_RawEmbeddedModule[] = {NULL, NULL, "_M_RAW__module",  NULL};
struct _SortDescriptor sort_M_RawEmbeddedModule = { "RawEmbeddedModule" , sortCon_M_RawEmbeddedModule, sortNam_M_RawEmbeddedModule, sortInt_M_RawEmbeddedModule, NULL};

/* SORT RawForm CONSTANTS. */
int conBindOffs_M_RAW_FormParsedSorted[] = {0 , 0 , 0 , 0 , 0};
char *name_M_RAW_FormParsedSorted =  "RAW-FormParsedSorted" ;
char *nameFun_M_RAW_FormParsedSorted(Term term) { return name_M_RAW_FormParsedSorted; }
struct _ConstructionDescriptor descriptor_M_RAW_FormParsedSorted = {&sort_M_RawForm, Data_M_RAW_FormParsedSorted, 4, sizeof(STRUCT_Con_M_RAW_FormParsedSorted), conBindOffs_M_RAW_FormParsedSorted, &nameFun_M_RAW_FormParsedSorted, &dataStep};
int conBindOffs_M_RAW_FormConstruction[] = {0 , 0 , 0 , 0};
char *name_M_RAW_FormConstruction =  "RAW-FormConstruction" ;
char *nameFun_M_RAW_FormConstruction(Term term) { return name_M_RAW_FormConstruction; }
struct _ConstructionDescriptor descriptor_M_RAW_FormConstruction = {&sort_M_RawForm, Data_M_RAW_FormConstruction, 3, sizeof(STRUCT_Con_M_RAW_FormConstruction), conBindOffs_M_RAW_FormConstruction, &nameFun_M_RAW_FormConstruction, &dataStep};
int conBindOffs_M_RAW_FormParsedUnsorted[] = {0 , 0 , 0 , 0};
char *name_M_RAW_FormParsedUnsorted =  "RAW-FormParsedUnsorted" ;
char *nameFun_M_RAW_FormParsedUnsorted(Term term) { return name_M_RAW_FormParsedUnsorted; }
struct _ConstructionDescriptor descriptor_M_RAW_FormParsedUnsorted = {&sort_M_RawForm, Data_M_RAW_FormParsedUnsorted, 3, sizeof(STRUCT_Con_M_RAW_FormParsedUnsorted), conBindOffs_M_RAW_FormParsedUnsorted, &nameFun_M_RAW_FormParsedUnsorted, &dataStep};
ConstructionDescriptor sortCon_M_RawForm[] = {NULL, NULL, &descriptor_M_RAW_FormParsedSorted, &descriptor_M_RAW_FormConstruction, &descriptor_M_RAW_FormParsedUnsorted,  NULL};
char *sortNam_M_RawForm[] = {NULL, NULL,  "RAW-FormParsedSorted" ,  "RAW-FormConstruction" ,  "RAW-FormParsedUnsorted" ,  NULL};
char *sortInt_M_RawForm[] = {NULL, NULL, "_M_RAW_FormParsedSorted", "_M_RAW_FormConstruction", "_M_RAW_FormParsedUnsorted",  NULL};
struct _SortDescriptor sort_M_RawForm = { "RawForm" , sortCon_M_RawForm, sortNam_M_RawForm, sortInt_M_RawForm, NULL};

/* SORT RawInheritedRef CONSTANTS. */
int conBindOffs_M_RAW_InheritedRef[] = {0 , 0};
char *name_M_RAW_InheritedRef =  "RAW-InheritedRef" ;
char *nameFun_M_RAW_InheritedRef(Term term) { return name_M_RAW_InheritedRef; }
struct _ConstructionDescriptor descriptor_M_RAW_InheritedRef = {&sort_M_RawInheritedRef, Data_M_RAW_InheritedRef, 1, sizeof(STRUCT_Con_M_RAW_InheritedRef), conBindOffs_M_RAW_InheritedRef, &nameFun_M_RAW_InheritedRef, &dataStep};
ConstructionDescriptor sortCon_M_RawInheritedRef[] = {NULL, NULL, &descriptor_M_RAW_InheritedRef,  NULL};
char *sortNam_M_RawInheritedRef[] = {NULL, NULL,  "RAW-InheritedRef" ,  NULL};
char *sortInt_M_RawInheritedRef[] = {NULL, NULL, "_M_RAW_InheritedRef",  NULL};
struct _SortDescriptor sort_M_RawInheritedRef = { "RawInheritedRef" , sortCon_M_RawInheritedRef, sortNam_M_RawInheritedRef, sortInt_M_RawInheritedRef, NULL};

/* SORT RawModule CONSTANTS. */
int conBindOffs_M_RAW__top__module[] = {0 , 0};
char *name_M_RAW__top__module =  "RAW-top-module" ;
char *nameFun_M_RAW__top__module(Term term) { return name_M_RAW__top__module; }
struct _ConstructionDescriptor descriptor_M_RAW__top__module = {&sort_M_RawModule, Data_M_RAW__top__module, 1, sizeof(STRUCT_Con_M_RAW__top__module), conBindOffs_M_RAW__top__module, &nameFun_M_RAW__top__module, &dataStep};
ConstructionDescriptor sortCon_M_RawModule[] = {NULL, NULL, &descriptor_M_RAW__top__module,  NULL};
char *sortNam_M_RawModule[] = {NULL, NULL,  "RAW-top-module" ,  NULL};
char *sortInt_M_RawModule[] = {NULL, NULL, "_M_RAW__top__module",  NULL};
struct _SortDescriptor sort_M_RawModule = { "RawModule" , sortCon_M_RawModule, sortNam_M_RawModule, sortInt_M_RawModule, NULL};

/* SORT RawParsed CONSTANTS. */
int conBindOffs_M_RAW_ParsedTerm[] = {0 , 0 , 0};
char *name_M_RAW_ParsedTerm =  "RAW-ParsedTerm" ;
char *nameFun_M_RAW_ParsedTerm(Term term) { return name_M_RAW_ParsedTerm; }
struct _ConstructionDescriptor descriptor_M_RAW_ParsedTerm = {&sort_M_RawParsed, Data_M_RAW_ParsedTerm, 2, sizeof(STRUCT_Con_M_RAW_ParsedTerm), conBindOffs_M_RAW_ParsedTerm, &nameFun_M_RAW_ParsedTerm, &dataStep};
char *name_M_RAW_ParsedDone =  "RAW-ParsedDone" ;
char *nameFun_M_RAW_ParsedDone(Term term) { return name_M_RAW_ParsedDone; }
struct _ConstructionDescriptor descriptor_M_RAW_ParsedDone = {&sort_M_RawParsed, Data_M_RAW_ParsedDone, 0, sizeof(STRUCT_Con_M_RAW_ParsedDone), noBinderOffsets, &nameFun_M_RAW_ParsedDone, &dataStep};
int conBindOffs_M_RAW_ParsedWord[] = {0 , 0 , 0};
char *name_M_RAW_ParsedWord =  "RAW-ParsedWord" ;
char *nameFun_M_RAW_ParsedWord(Term term) { return name_M_RAW_ParsedWord; }
struct _ConstructionDescriptor descriptor_M_RAW_ParsedWord = {&sort_M_RawParsed, Data_M_RAW_ParsedWord, 2, sizeof(STRUCT_Con_M_RAW_ParsedWord), conBindOffs_M_RAW_ParsedWord, &nameFun_M_RAW_ParsedWord, &dataStep};
ConstructionDescriptor sortCon_M_RawParsed[] = {NULL, NULL, &descriptor_M_RAW_ParsedTerm, &descriptor_M_RAW_ParsedDone, &descriptor_M_RAW_ParsedWord,  NULL};
char *sortNam_M_RawParsed[] = {NULL, NULL,  "RAW-ParsedTerm" ,  "RAW-ParsedDone" ,  "RAW-ParsedWord" ,  NULL};
char *sortInt_M_RawParsed[] = {NULL, NULL, "_M_RAW_ParsedTerm", "_M_RAW_ParsedDone", "_M_RAW_ParsedWord",  NULL};
struct _SortDescriptor sort_M_RawParsed = { "RawParsed" , sortCon_M_RawParsed, sortNam_M_RawParsed, sortInt_M_RawParsed, NULL};

/* SORT RawParsedForm CONSTANTS. */
int conBindOffs_M_RAW_ParsedFormTerm[] = {0 , 0 , 0 , 0 , 0};
char *name_M_RAW_ParsedFormTerm =  "RAW-ParsedFormTerm" ;
char *nameFun_M_RAW_ParsedFormTerm(Term term) { return name_M_RAW_ParsedFormTerm; }
struct _ConstructionDescriptor descriptor_M_RAW_ParsedFormTerm = {&sort_M_RawParsedForm, Data_M_RAW_ParsedFormTerm, 4, sizeof(STRUCT_Con_M_RAW_ParsedFormTerm), conBindOffs_M_RAW_ParsedFormTerm, &nameFun_M_RAW_ParsedFormTerm, &dataStep};
int conBindOffs_M_RAW_ParsedFormWord[] = {0 , 0 , 0};
char *name_M_RAW_ParsedFormWord =  "RAW-ParsedFormWord" ;
char *nameFun_M_RAW_ParsedFormWord(Term term) { return name_M_RAW_ParsedFormWord; }
struct _ConstructionDescriptor descriptor_M_RAW_ParsedFormWord = {&sort_M_RawParsedForm, Data_M_RAW_ParsedFormWord, 2, sizeof(STRUCT_Con_M_RAW_ParsedFormWord), conBindOffs_M_RAW_ParsedFormWord, &nameFun_M_RAW_ParsedFormWord, &dataStep};
char *name_M_RAW_ParsedFormDone =  "RAW-ParsedFormDone" ;
char *nameFun_M_RAW_ParsedFormDone(Term term) { return name_M_RAW_ParsedFormDone; }
struct _ConstructionDescriptor descriptor_M_RAW_ParsedFormDone = {&sort_M_RawParsedForm, Data_M_RAW_ParsedFormDone, 0, sizeof(STRUCT_Con_M_RAW_ParsedFormDone), noBinderOffsets, &nameFun_M_RAW_ParsedFormDone, &dataStep};
int conBindOffs_M_RAW_ParsedFormSpace[] = {0 , 0 , 0};
char *name_M_RAW_ParsedFormSpace =  "RAW-ParsedFormSpace" ;
char *nameFun_M_RAW_ParsedFormSpace(Term term) { return name_M_RAW_ParsedFormSpace; }
struct _ConstructionDescriptor descriptor_M_RAW_ParsedFormSpace = {&sort_M_RawParsedForm, Data_M_RAW_ParsedFormSpace, 2, sizeof(STRUCT_Con_M_RAW_ParsedFormSpace), conBindOffs_M_RAW_ParsedFormSpace, &nameFun_M_RAW_ParsedFormSpace, &dataStep};
ConstructionDescriptor sortCon_M_RawParsedForm[] = {NULL, NULL, &descriptor_M_RAW_ParsedFormTerm, &descriptor_M_RAW_ParsedFormWord, &descriptor_M_RAW_ParsedFormDone, &descriptor_M_RAW_ParsedFormSpace,  NULL};
char *sortNam_M_RawParsedForm[] = {NULL, NULL,  "RAW-ParsedFormTerm" ,  "RAW-ParsedFormWord" ,  "RAW-ParsedFormDone" ,  "RAW-ParsedFormSpace" ,  NULL};
char *sortInt_M_RawParsedForm[] = {NULL, NULL, "_M_RAW_ParsedFormTerm", "_M_RAW_ParsedFormWord", "_M_RAW_ParsedFormDone", "_M_RAW_ParsedFormSpace",  NULL};
struct _SortDescriptor sort_M_RawParsedForm = { "RawParsedForm" , sortCon_M_RawParsedForm, sortNam_M_RawParsedForm, sortInt_M_RawParsedForm, NULL};

/* SORT RawPriority CONSTANTS. */
char *name_M_RAW__default =  "RAW-default" ;
char *nameFun_M_RAW__default(Term term) { return name_M_RAW__default; }
struct _ConstructionDescriptor descriptor_M_RAW__default = {&sort_M_RawPriority, Data_M_RAW__default, 0, sizeof(STRUCT_Con_M_RAW__default), noBinderOffsets, &nameFun_M_RAW__default, &dataStep};
char *name_M_RAW__priority =  "RAW-priority" ;
char *nameFun_M_RAW__priority(Term term) { return name_M_RAW__priority; }
struct _ConstructionDescriptor descriptor_M_RAW__priority = {&sort_M_RawPriority, Data_M_RAW__priority, 0, sizeof(STRUCT_Con_M_RAW__priority), noBinderOffsets, &nameFun_M_RAW__priority, &dataStep};
char *name_M_RAW_Normal =  "RAW-Normal" ;
char *nameFun_M_RAW_Normal(Term term) { return name_M_RAW_Normal; }
struct _ConstructionDescriptor descriptor_M_RAW_Normal = {&sort_M_RawPriority, Data_M_RAW_Normal, 0, sizeof(STRUCT_Con_M_RAW_Normal), noBinderOffsets, &nameFun_M_RAW_Normal, &dataStep};
ConstructionDescriptor sortCon_M_RawPriority[] = {NULL, NULL, &descriptor_M_RAW__default, &descriptor_M_RAW__priority, &descriptor_M_RAW_Normal,  NULL};
char *sortNam_M_RawPriority[] = {NULL, NULL,  "RAW-default" ,  "RAW-priority" ,  "RAW-Normal" ,  NULL};
char *sortInt_M_RawPriority[] = {NULL, NULL, "_M_RAW__default", "_M_RAW__priority", "_M_RAW_Normal",  NULL};
struct _SortDescriptor sort_M_RawPriority = { "RawPriority" , sortCon_M_RawPriority, sortNam_M_RawPriority, sortInt_M_RawPriority, NULL};

/* SORT RawRegExp CONSTANTS. */
int conBindOffs_M_RegExp_sCons[] = {0 , 0 , 0};
char *name_M_RegExp_sCons =  "RegExp$Cons" ;
char *nameFun_M_RegExp_sCons(Term term) { return name_M_RegExp_sCons; }
struct _ConstructionDescriptor descriptor_M_RegExp_sCons = {&sort_M_RawRegExp, Data_M_RegExp_sCons, 2, sizeof(STRUCT_Con_M_RegExp_sCons), conBindOffs_M_RegExp_sCons, &nameFun_M_RegExp_sCons, &dataStep};
char *name_M_RegExp_sNil =  "RegExp$Nil" ;
char *nameFun_M_RegExp_sNil(Term term) { return name_M_RegExp_sNil; }
struct _ConstructionDescriptor descriptor_M_RegExp_sNil = {&sort_M_RawRegExp, Data_M_RegExp_sNil, 0, sizeof(STRUCT_Con_M_RegExp_sNil), noBinderOffsets, &nameFun_M_RegExp_sNil, &dataStep};
ConstructionDescriptor sortCon_M_RawRegExp[] = {NULL, NULL, &descriptor_M_RegExp_sCons, &descriptor_M_RegExp_sNil,  NULL};
char *sortNam_M_RawRegExp[] = {NULL, NULL,  "RegExp$Cons" ,  "RegExp$Nil" ,  NULL};
char *sortInt_M_RawRegExp[] = {NULL, NULL, "_M_RegExp_sCons", "_M_RegExp_sNil",  NULL};
struct _SortDescriptor sort_M_RawRegExp = { "RawRegExp" , sortCon_M_RawRegExp, sortNam_M_RawRegExp, sortInt_M_RawRegExp, NULL};

/* SORT RawRegExpChoice CONSTANTS. */
int conBindOffs_M_RAW__nested[] = {0 , 0 , 0};
char *name_M_RAW__nested =  "RAW-nested" ;
char *nameFun_M_RAW__nested(Term term) { return name_M_RAW__nested; }
struct _ConstructionDescriptor descriptor_M_RAW__nested = {&sort_M_RawRegExpChoice, Data_M_RAW__nested, 2, sizeof(STRUCT_Con_M_RAW__nested), conBindOffs_M_RAW__nested, &nameFun_M_RAW__nested, &dataStep};
int conBindOffs_M_RAW_RegExpConcat[] = {0 , 0};
char *name_M_RAW_RegExpConcat =  "RAW-RegExpConcat" ;
char *nameFun_M_RAW_RegExpConcat(Term term) { return name_M_RAW_RegExpConcat; }
struct _ConstructionDescriptor descriptor_M_RAW_RegExpConcat = {&sort_M_RawRegExpChoice, Data_M_RAW_RegExpConcat, 1, sizeof(STRUCT_Con_M_RAW_RegExpConcat), conBindOffs_M_RAW_RegExpConcat, &nameFun_M_RAW_RegExpConcat, &dataStep};
ConstructionDescriptor sortCon_M_RawRegExpChoice[] = {NULL, NULL, &descriptor_M_RAW__nested, &descriptor_M_RAW_RegExpConcat,  NULL};
char *sortNam_M_RawRegExpChoice[] = {NULL, NULL,  "RAW-nested" ,  "RAW-RegExpConcat" ,  NULL};
char *sortInt_M_RawRegExpChoice[] = {NULL, NULL, "_M_RAW__nested", "_M_RAW_RegExpConcat",  NULL};
struct _SortDescriptor sort_M_RawRegExpChoice = { "RawRegExpChoice" , sortCon_M_RawRegExpChoice, sortNam_M_RawRegExpChoice, sortInt_M_RawRegExpChoice, NULL};

/* SORT RawRegExpClass CONSTANTS. */
char *name_M_RAW_RegExpClassDone =  "RAW-RegExpClassDone" ;
char *nameFun_M_RAW_RegExpClassDone(Term term) { return name_M_RAW_RegExpClassDone; }
struct _ConstructionDescriptor descriptor_M_RAW_RegExpClassDone = {&sort_M_RawRegExpClass, Data_M_RAW_RegExpClassDone, 0, sizeof(STRUCT_Con_M_RAW_RegExpClassDone), noBinderOffsets, &nameFun_M_RAW_RegExpClassDone, &dataStep};
int conBindOffs_M_RAW_RegExpClassNot[] = {0 , 0};
char *name_M_RAW_RegExpClassNot =  "RAW-RegExpClassNot" ;
char *nameFun_M_RAW_RegExpClassNot(Term term) { return name_M_RAW_RegExpClassNot; }
struct _ConstructionDescriptor descriptor_M_RAW_RegExpClassNot = {&sort_M_RawRegExpClass, Data_M_RAW_RegExpClassNot, 1, sizeof(STRUCT_Con_M_RAW_RegExpClassNot), conBindOffs_M_RAW_RegExpClassNot, &nameFun_M_RAW_RegExpClassNot, &dataStep};
int conBindOffs_M_RAW_RegExpClassRange[] = {0 , 0 , 0 , 0};
char *name_M_RAW_RegExpClassRange =  "RAW-RegExpClassRange" ;
char *nameFun_M_RAW_RegExpClassRange(Term term) { return name_M_RAW_RegExpClassRange; }
struct _ConstructionDescriptor descriptor_M_RAW_RegExpClassRange = {&sort_M_RawRegExpClass, Data_M_RAW_RegExpClassRange, 3, sizeof(STRUCT_Con_M_RAW_RegExpClassRange), conBindOffs_M_RAW_RegExpClassRange, &nameFun_M_RAW_RegExpClassRange, &dataStep};
int conBindOffs_M_RAW_RegExpClassChar[] = {0 , 0 , 0};
char *name_M_RAW_RegExpClassChar =  "RAW-RegExpClassChar" ;
char *nameFun_M_RAW_RegExpClassChar(Term term) { return name_M_RAW_RegExpClassChar; }
struct _ConstructionDescriptor descriptor_M_RAW_RegExpClassChar = {&sort_M_RawRegExpClass, Data_M_RAW_RegExpClassChar, 2, sizeof(STRUCT_Con_M_RAW_RegExpClassChar), conBindOffs_M_RAW_RegExpClassChar, &nameFun_M_RAW_RegExpClassChar, &dataStep};
ConstructionDescriptor sortCon_M_RawRegExpClass[] = {NULL, NULL, &descriptor_M_RAW_RegExpClassDone, &descriptor_M_RAW_RegExpClassNot, &descriptor_M_RAW_RegExpClassRange, &descriptor_M_RAW_RegExpClassChar,  NULL};
char *sortNam_M_RawRegExpClass[] = {NULL, NULL,  "RAW-RegExpClassDone" ,  "RAW-RegExpClassNot" ,  "RAW-RegExpClassRange" ,  "RAW-RegExpClassChar" ,  NULL};
char *sortInt_M_RawRegExpClass[] = {NULL, NULL, "_M_RAW_RegExpClassDone", "_M_RAW_RegExpClassNot", "_M_RAW_RegExpClassRange", "_M_RAW_RegExpClassChar",  NULL};
struct _SortDescriptor sort_M_RawRegExpClass = { "RawRegExpClass" , sortCon_M_RawRegExpClass, sortNam_M_RawRegExpClass, sortInt_M_RawRegExpClass, NULL};

/* SORT RawRegExpSimple CONSTANTS. */
int conBindOffs_M_RAW_RegExpClass[] = {0 , 0};
char *name_M_RAW_RegExpClass =  "RAW-RegExpClass" ;
char *nameFun_M_RAW_RegExpClass(Term term) { return name_M_RAW_RegExpClass; }
struct _ConstructionDescriptor descriptor_M_RAW_RegExpClass = {&sort_M_RawRegExpSimple, Data_M_RAW_RegExpClass, 1, sizeof(STRUCT_Con_M_RAW_RegExpClass), conBindOffs_M_RAW_RegExpClass, &nameFun_M_RAW_RegExpClass, &dataStep};
int conBindOffs_M_RAW_RegExpRef[] = {0 , 0};
char *name_M_RAW_RegExpRef =  "RAW-RegExpRef" ;
char *nameFun_M_RAW_RegExpRef(Term term) { return name_M_RAW_RegExpRef; }
struct _ConstructionDescriptor descriptor_M_RAW_RegExpRef = {&sort_M_RawRegExpSimple, Data_M_RAW_RegExpRef, 1, sizeof(STRUCT_Con_M_RAW_RegExpRef), conBindOffs_M_RAW_RegExpRef, &nameFun_M_RAW_RegExpRef, &dataStep};
char *name_M_RAW_RegExpAny =  "RAW-RegExpAny" ;
char *nameFun_M_RAW_RegExpAny(Term term) { return name_M_RAW_RegExpAny; }
struct _ConstructionDescriptor descriptor_M_RAW_RegExpAny = {&sort_M_RawRegExpSimple, Data_M_RAW_RegExpAny, 0, sizeof(STRUCT_Con_M_RAW_RegExpAny), noBinderOffsets, &nameFun_M_RAW_RegExpAny, &dataStep};
int conBindOffs_M_RAW_RegExpWord[] = {0 , 0};
char *name_M_RAW_RegExpWord =  "RAW-RegExpWord" ;
char *nameFun_M_RAW_RegExpWord(Term term) { return name_M_RAW_RegExpWord; }
struct _ConstructionDescriptor descriptor_M_RAW_RegExpWord = {&sort_M_RawRegExpSimple, Data_M_RAW_RegExpWord, 1, sizeof(STRUCT_Con_M_RAW_RegExpWord), conBindOffs_M_RAW_RegExpWord, &nameFun_M_RAW_RegExpWord, &dataStep};
int conBindOffs_M_RAW_RegExpString[] = {0 , 0};
char *name_M_RAW_RegExpString =  "RAW-RegExpString" ;
char *nameFun_M_RAW_RegExpString(Term term) { return name_M_RAW_RegExpString; }
struct _ConstructionDescriptor descriptor_M_RAW_RegExpString = {&sort_M_RawRegExpSimple, Data_M_RAW_RegExpString, 1, sizeof(STRUCT_Con_M_RAW_RegExpString), conBindOffs_M_RAW_RegExpString, &nameFun_M_RAW_RegExpString, &dataStep};
int conBindOffs_M_RAW_RegExpNest[] = {0 , 0};
char *name_M_RAW_RegExpNest =  "RAW-RegExpNest" ;
char *nameFun_M_RAW_RegExpNest(Term term) { return name_M_RAW_RegExpNest; }
struct _ConstructionDescriptor descriptor_M_RAW_RegExpNest = {&sort_M_RawRegExpSimple, Data_M_RAW_RegExpNest, 1, sizeof(STRUCT_Con_M_RAW_RegExpNest), conBindOffs_M_RAW_RegExpNest, &nameFun_M_RAW_RegExpNest, &dataStep};
ConstructionDescriptor sortCon_M_RawRegExpSimple[] = {NULL, NULL, &descriptor_M_RAW_RegExpClass, &descriptor_M_RAW_RegExpRef, &descriptor_M_RAW_RegExpAny, &descriptor_M_RAW_RegExpWord, &descriptor_M_RAW_RegExpString, &descriptor_M_RAW_RegExpNest,  NULL};
char *sortNam_M_RawRegExpSimple[] = {NULL, NULL,  "RAW-RegExpClass" ,  "RAW-RegExpRef" ,  "RAW-RegExpAny" ,  "RAW-RegExpWord" ,  "RAW-RegExpString" ,  "RAW-RegExpNest" ,  NULL};
char *sortInt_M_RawRegExpSimple[] = {NULL, NULL, "_M_RAW_RegExpClass", "_M_RAW_RegExpRef", "_M_RAW_RegExpAny", "_M_RAW_RegExpWord", "_M_RAW_RegExpString", "_M_RAW_RegExpNest",  NULL};
struct _SortDescriptor sort_M_RawRegExpSimple = { "RawRegExpSimple" , sortCon_M_RawRegExpSimple, sortNam_M_RawRegExpSimple, sortInt_M_RawRegExpSimple, NULL};

/* SORT RawRegExpUnit CONSTANTS. */
int conBindOffs_M_RAW_RegExpUnit[] = {0 , 0 , 0};
char *name_M_RAW_RegExpUnit =  "RAW-RegExpUnit" ;
char *nameFun_M_RAW_RegExpUnit(Term term) { return name_M_RAW_RegExpUnit; }
struct _ConstructionDescriptor descriptor_M_RAW_RegExpUnit = {&sort_M_RawRegExpUnit, Data_M_RAW_RegExpUnit, 2, sizeof(STRUCT_Con_M_RAW_RegExpUnit), conBindOffs_M_RAW_RegExpUnit, &nameFun_M_RAW_RegExpUnit, &dataStep};
ConstructionDescriptor sortCon_M_RawRegExpUnit[] = {NULL, NULL, &descriptor_M_RAW_RegExpUnit,  NULL};
char *sortNam_M_RawRegExpUnit[] = {NULL, NULL,  "RAW-RegExpUnit" ,  NULL};
char *sortInt_M_RawRegExpUnit[] = {NULL, NULL, "_M_RAW_RegExpUnit",  NULL};
struct _SortDescriptor sort_M_RawRegExpUnit = { "RawRegExpUnit" , sortCon_M_RawRegExpUnit, sortNam_M_RawRegExpUnit, sortInt_M_RawRegExpUnit, NULL};

/* SORT RawRepeat CONSTANTS. */
int conBindOffs_M_RAW_RepeatSomeSep[] = {0 , 0};
char *name_M_RAW_RepeatSomeSep =  "RAW-RepeatSomeSep" ;
char *nameFun_M_RAW_RepeatSomeSep(Term term) { return name_M_RAW_RepeatSomeSep; }
struct _ConstructionDescriptor descriptor_M_RAW_RepeatSomeSep = {&sort_M_RawRepeat, Data_M_RAW_RepeatSomeSep, 1, sizeof(STRUCT_Con_M_RAW_RepeatSomeSep), conBindOffs_M_RAW_RepeatSomeSep, &nameFun_M_RAW_RepeatSomeSep, &dataStep};
char *name_M_RAW_RepeatSome =  "RAW-RepeatSome" ;
char *nameFun_M_RAW_RepeatSome(Term term) { return name_M_RAW_RepeatSome; }
struct _ConstructionDescriptor descriptor_M_RAW_RepeatSome = {&sort_M_RawRepeat, Data_M_RAW_RepeatSome, 0, sizeof(STRUCT_Con_M_RAW_RepeatSome), noBinderOffsets, &nameFun_M_RAW_RepeatSome, &dataStep};
char *name_M_RAW_RepeatSingle =  "RAW-RepeatSingle" ;
char *nameFun_M_RAW_RepeatSingle(Term term) { return name_M_RAW_RepeatSingle; }
struct _ConstructionDescriptor descriptor_M_RAW_RepeatSingle = {&sort_M_RawRepeat, Data_M_RAW_RepeatSingle, 0, sizeof(STRUCT_Con_M_RAW_RepeatSingle), noBinderOffsets, &nameFun_M_RAW_RepeatSingle, &dataStep};
char *name_M_RAW_RepeatMaybe =  "RAW-RepeatMaybe" ;
char *nameFun_M_RAW_RepeatMaybe(Term term) { return name_M_RAW_RepeatMaybe; }
struct _ConstructionDescriptor descriptor_M_RAW_RepeatMaybe = {&sort_M_RawRepeat, Data_M_RAW_RepeatMaybe, 0, sizeof(STRUCT_Con_M_RAW_RepeatMaybe), noBinderOffsets, &nameFun_M_RAW_RepeatMaybe, &dataStep};
char *name_M_RAW_RepeatMaybeSome =  "RAW-RepeatMaybeSome" ;
char *nameFun_M_RAW_RepeatMaybeSome(Term term) { return name_M_RAW_RepeatMaybeSome; }
struct _ConstructionDescriptor descriptor_M_RAW_RepeatMaybeSome = {&sort_M_RawRepeat, Data_M_RAW_RepeatMaybeSome, 0, sizeof(STRUCT_Con_M_RAW_RepeatMaybeSome), noBinderOffsets, &nameFun_M_RAW_RepeatMaybeSome, &dataStep};
ConstructionDescriptor sortCon_M_RawRepeat[] = {NULL, NULL, &descriptor_M_RAW_RepeatSomeSep, &descriptor_M_RAW_RepeatSome, &descriptor_M_RAW_RepeatSingle, &descriptor_M_RAW_RepeatMaybe, &descriptor_M_RAW_RepeatMaybeSome,  NULL};
char *sortNam_M_RawRepeat[] = {NULL, NULL,  "RAW-RepeatSomeSep" ,  "RAW-RepeatSome" ,  "RAW-RepeatSingle" ,  "RAW-RepeatMaybe" ,  "RAW-RepeatMaybeSome" ,  NULL};
char *sortInt_M_RawRepeat[] = {NULL, NULL, "_M_RAW_RepeatSomeSep", "_M_RAW_RepeatSome", "_M_RAW_RepeatSingle", "_M_RAW_RepeatMaybe", "_M_RAW_RepeatMaybeSome",  NULL};
struct _SortDescriptor sort_M_RawRepeat = { "RawRepeat" , sortCon_M_RawRepeat, sortNam_M_RawRepeat, sortInt_M_RawRepeat, NULL};

/* SORT RawRule CONSTANTS. */
int conBindOffs_M_RAW_Rule[] = {0 , 0 , 0 , 0 , 0};
char *name_M_RAW_Rule =  "RAW-Rule" ;
char *nameFun_M_RAW_Rule(Term term) { return name_M_RAW_Rule; }
struct _ConstructionDescriptor descriptor_M_RAW_Rule = {&sort_M_RawRule, Data_M_RAW_Rule, 4, sizeof(STRUCT_Con_M_RAW_Rule), conBindOffs_M_RAW_Rule, &nameFun_M_RAW_Rule, &dataStep};
ConstructionDescriptor sortCon_M_RawRule[] = {NULL, NULL, &descriptor_M_RAW_Rule,  NULL};
char *sortNam_M_RawRule[] = {NULL, NULL,  "RAW-Rule" ,  NULL};
char *sortInt_M_RawRule[] = {NULL, NULL, "_M_RAW_Rule",  NULL};
struct _SortDescriptor sort_M_RawRule = { "RawRule" , sortCon_M_RawRule, sortNam_M_RawRule, sortInt_M_RawRule, NULL};

/* SORT RawScope CONSTANTS. */
int conBindOffs_M_RAW_Scope[] = {0 , 0 , 0};
char *name_M_RAW_Scope =  "RAW-Scope" ;
char *nameFun_M_RAW_Scope(Term term) { return name_M_RAW_Scope; }
struct _ConstructionDescriptor descriptor_M_RAW_Scope = {&sort_M_RawScope, Data_M_RAW_Scope, 2, sizeof(STRUCT_Con_M_RAW_Scope), conBindOffs_M_RAW_Scope, &nameFun_M_RAW_Scope, &dataStep};
ConstructionDescriptor sortCon_M_RawScope[] = {NULL, NULL, &descriptor_M_RAW_Scope,  NULL};
char *sortNam_M_RawScope[] = {NULL, NULL,  "RAW-Scope" ,  NULL};
char *sortInt_M_RawScope[] = {NULL, NULL, "_M_RAW_Scope",  NULL};
struct _SortDescriptor sort_M_RawScope = { "RawScope" , sortCon_M_RawScope, sortNam_M_RawScope, sortInt_M_RawScope, NULL};

/* SORT RawScopeSort CONSTANTS. */
int conBindOffs_M_RAW_ScopeSortBinder[] = {0 , 0};
char *name_M_RAW_ScopeSortBinder =  "RAW-ScopeSortBinder" ;
char *nameFun_M_RAW_ScopeSortBinder(Term term) { return name_M_RAW_ScopeSortBinder; }
struct _ConstructionDescriptor descriptor_M_RAW_ScopeSortBinder = {&sort_M_RawScopeSort, Data_M_RAW_ScopeSortBinder, 1, sizeof(STRUCT_Con_M_RAW_ScopeSortBinder), conBindOffs_M_RAW_ScopeSortBinder, &nameFun_M_RAW_ScopeSortBinder, &dataStep};
int conBindOffs_M_RAW_ScopeSort[] = {0 , 0 , 0 , 0};
char *name_M_RAW_ScopeSort =  "RAW-ScopeSort" ;
char *nameFun_M_RAW_ScopeSort(Term term) { return name_M_RAW_ScopeSort; }
struct _ConstructionDescriptor descriptor_M_RAW_ScopeSort = {&sort_M_RawScopeSort, Data_M_RAW_ScopeSort, 3, sizeof(STRUCT_Con_M_RAW_ScopeSort), conBindOffs_M_RAW_ScopeSort, &nameFun_M_RAW_ScopeSort, &dataStep};
ConstructionDescriptor sortCon_M_RawScopeSort[] = {NULL, NULL, &descriptor_M_RAW_ScopeSortBinder, &descriptor_M_RAW_ScopeSort,  NULL};
char *sortNam_M_RawScopeSort[] = {NULL, NULL,  "RAW-ScopeSortBinder" ,  "RAW-ScopeSort" ,  NULL};
char *sortInt_M_RawScopeSort[] = {NULL, NULL, "_M_RAW_ScopeSortBinder", "_M_RAW_ScopeSort",  NULL};
struct _SortDescriptor sort_M_RawScopeSort = { "RawScopeSort" , sortCon_M_RawScopeSort, sortNam_M_RawScopeSort, sortInt_M_RawScopeSort, NULL};

/* SORT RawSort CONSTANTS. */
int conBindOffs_M_RAW_SortParam[] = {0 , 0};
char *name_M_RAW_SortParam =  "RAW-SortParam" ;
char *nameFun_M_RAW_SortParam(Term term) { return name_M_RAW_SortParam; }
struct _ConstructionDescriptor descriptor_M_RAW_SortParam = {&sort_M_RawSort, Data_M_RAW_SortParam, 1, sizeof(STRUCT_Con_M_RAW_SortParam), conBindOffs_M_RAW_SortParam, &nameFun_M_RAW_SortParam, &dataStep};
int conBindOffs_M_RAW_SortName[] = {0 , 0 , 0};
char *name_M_RAW_SortName =  "RAW-SortName" ;
char *nameFun_M_RAW_SortName(Term term) { return name_M_RAW_SortName; }
struct _ConstructionDescriptor descriptor_M_RAW_SortName = {&sort_M_RawSort, Data_M_RAW_SortName, 2, sizeof(STRUCT_Con_M_RAW_SortName), conBindOffs_M_RAW_SortName, &nameFun_M_RAW_SortName, &dataStep};
int conBindOffs_M_RAW_Sort[] = {0 , 0 , 0};
char *name_M_RAW_Sort =  "RAW-Sort" ;
char *nameFun_M_RAW_Sort(Term term) { return name_M_RAW_Sort; }
struct _ConstructionDescriptor descriptor_M_RAW_Sort = {&sort_M_RawSort, Data_M_RAW_Sort, 2, sizeof(STRUCT_Con_M_RAW_Sort), conBindOffs_M_RAW_Sort, &nameFun_M_RAW_Sort, &dataStep};
ConstructionDescriptor sortCon_M_RawSort[] = {NULL, NULL, &descriptor_M_RAW_SortParam, &descriptor_M_RAW_SortName, &descriptor_M_RAW_Sort,  NULL};
char *sortNam_M_RawSort[] = {NULL, NULL,  "RAW-SortParam" ,  "RAW-SortName" ,  "RAW-Sort" ,  NULL};
char *sortInt_M_RawSort[] = {NULL, NULL, "_M_RAW_SortParam", "_M_RAW_SortName", "_M_RAW_Sort",  NULL};
struct _SortDescriptor sort_M_RawSort = { "RawSort" , sortCon_M_RawSort, sortNam_M_RawSort, sortInt_M_RawSort, NULL};

/* SORT RawSortAbstraction CONSTANTS. */
int conBindOffs_M_RAW_SortAbstractionParam[] = {0 , 1};
char *name_M_RAW_SortAbstractionParam =  "RAW-SortAbstractionParam" ;
char *nameFun_M_RAW_SortAbstractionParam(Term term) { return name_M_RAW_SortAbstractionParam; }
struct _ConstructionDescriptor descriptor_M_RAW_SortAbstractionParam = {&sort_M_RawSortAbstraction, Data_M_RAW_SortAbstractionParam, 1, sizeof(STRUCT_Con_M_RAW_SortAbstractionParam), conBindOffs_M_RAW_SortAbstractionParam, &nameFun_M_RAW_SortAbstractionParam, &dataStep};
int conBindOffs_M_RAW_SortAbstractionBody[] = {0 , 0};
char *name_M_RAW_SortAbstractionBody =  "RAW-SortAbstractionBody" ;
char *nameFun_M_RAW_SortAbstractionBody(Term term) { return name_M_RAW_SortAbstractionBody; }
struct _ConstructionDescriptor descriptor_M_RAW_SortAbstractionBody = {&sort_M_RawSortAbstraction, Data_M_RAW_SortAbstractionBody, 1, sizeof(STRUCT_Con_M_RAW_SortAbstractionBody), conBindOffs_M_RAW_SortAbstractionBody, &nameFun_M_RAW_SortAbstractionBody, &dataStep};
ConstructionDescriptor sortCon_M_RawSortAbstraction[] = {NULL, NULL, &descriptor_M_RAW_SortAbstractionParam, &descriptor_M_RAW_SortAbstractionBody,  NULL};
char *sortNam_M_RawSortAbstraction[] = {NULL, NULL,  "RAW-SortAbstractionParam" ,  "RAW-SortAbstractionBody" ,  NULL};
char *sortInt_M_RawSortAbstraction[] = {NULL, NULL, "_M_RAW_SortAbstractionParam", "_M_RAW_SortAbstractionBody",  NULL};
struct _SortDescriptor sort_M_RawSortAbstraction = { "RawSortAbstraction" , sortCon_M_RawSortAbstraction, sortNam_M_RawSortAbstraction, sortInt_M_RawSortAbstraction, NULL};

/* SORT RawSortAlternative CONSTANTS. */
int conBindOffs_M_RAW__static[] = {0 , 0};
char *name_M_RAW__static =  "RAW-static" ;
char *nameFun_M_RAW__static(Term term) { return name_M_RAW__static; }
struct _ConstructionDescriptor descriptor_M_RAW__static = {&sort_M_RawSortAlternative, Data_M_RAW__static, 1, sizeof(STRUCT_Con_M_RAW__static), conBindOffs_M_RAW__static, &nameFun_M_RAW__static, &dataStep};
int conBindOffs_M_RAW__sugar[] = {0 , 0 , 0};
char *name_M_RAW__sugar =  "RAW-sugar" ;
char *nameFun_M_RAW__sugar(Term term) { return name_M_RAW__sugar; }
struct _ConstructionDescriptor descriptor_M_RAW__sugar = {&sort_M_RawSortAlternative, Data_M_RAW__sugar, 2, sizeof(STRUCT_Con_M_RAW__sugar), conBindOffs_M_RAW__sugar, &nameFun_M_RAW__sugar, &dataStep};
int conBindOffs_M_RAW__scheme[] = {0 , 0};
char *name_M_RAW__scheme =  "RAW-scheme" ;
char *nameFun_M_RAW__scheme(Term term) { return name_M_RAW__scheme; }
struct _ConstructionDescriptor descriptor_M_RAW__scheme = {&sort_M_RawSortAlternative, Data_M_RAW__scheme, 1, sizeof(STRUCT_Con_M_RAW__scheme), conBindOffs_M_RAW__scheme, &nameFun_M_RAW__scheme, &dataStep};
int conBindOffs_M_RAW__symbol[] = {0 , 0};
char *name_M_RAW__symbol =  "RAW-symbol" ;
char *nameFun_M_RAW__symbol(Term term) { return name_M_RAW__symbol; }
struct _ConstructionDescriptor descriptor_M_RAW__symbol = {&sort_M_RawSortAlternative, Data_M_RAW__symbol, 1, sizeof(STRUCT_Con_M_RAW__symbol), conBindOffs_M_RAW__symbol, &nameFun_M_RAW__symbol, &dataStep};
int conBindOffs_M_RAW__data[] = {0 , 0 , 0};
char *name_M_RAW__data =  "RAW-data" ;
char *nameFun_M_RAW__data(Term term) { return name_M_RAW__data; }
struct _ConstructionDescriptor descriptor_M_RAW__data = {&sort_M_RawSortAlternative, Data_M_RAW__data, 2, sizeof(STRUCT_Con_M_RAW__data), conBindOffs_M_RAW__data, &nameFun_M_RAW__data, &dataStep};
ConstructionDescriptor sortCon_M_RawSortAlternative[] = {NULL, NULL, &descriptor_M_RAW__static, &descriptor_M_RAW__sugar, &descriptor_M_RAW__scheme, &descriptor_M_RAW__symbol, &descriptor_M_RAW__data,  NULL};
char *sortNam_M_RawSortAlternative[] = {NULL, NULL,  "RAW-static" ,  "RAW-sugar" ,  "RAW-scheme" ,  "RAW-symbol" ,  "RAW-data" ,  NULL};
char *sortInt_M_RawSortAlternative[] = {NULL, NULL, "_M_RAW__static", "_M_RAW__sugar", "_M_RAW__scheme", "_M_RAW__symbol", "_M_RAW__data",  NULL};
struct _SortDescriptor sort_M_RawSortAlternative = { "RawSortAlternative" , sortCon_M_RawSortAlternative, sortNam_M_RawSortAlternative, sortInt_M_RawSortAlternative, NULL};

/* SORT RawSubstituteSort CONSTANTS. */
int conBindOffs_M_RAW_SubstituteSort[] = {0 , 0 , 0};
char *name_M_RAW_SubstituteSort =  "RAW-SubstituteSort" ;
char *nameFun_M_RAW_SubstituteSort(Term term) { return name_M_RAW_SubstituteSort; }
struct _ConstructionDescriptor descriptor_M_RAW_SubstituteSort = {&sort_M_RawSubstituteSort, Data_M_RAW_SubstituteSort, 2, sizeof(STRUCT_Con_M_RAW_SubstituteSort), conBindOffs_M_RAW_SubstituteSort, &nameFun_M_RAW_SubstituteSort, &dataStep};
ConstructionDescriptor sortCon_M_RawSubstituteSort[] = {NULL, NULL, &descriptor_M_RAW_SubstituteSort,  NULL};
char *sortNam_M_RawSubstituteSort[] = {NULL, NULL,  "RAW-SubstituteSort" ,  NULL};
char *sortInt_M_RawSubstituteSort[] = {NULL, NULL, "_M_RAW_SubstituteSort",  NULL};
struct _SortDescriptor sort_M_RawSubstituteSort = { "RawSubstituteSort" , sortCon_M_RawSubstituteSort, sortNam_M_RawSubstituteSort, sortInt_M_RawSubstituteSort, NULL};

/* SORT RawSynthesizedRef CONSTANTS. */
int conBindOffs_M_RAW_SynthesizedRef[] = {0 , 0};
char *name_M_RAW_SynthesizedRef =  "RAW-SynthesizedRef" ;
char *nameFun_M_RAW_SynthesizedRef(Term term) { return name_M_RAW_SynthesizedRef; }
struct _ConstructionDescriptor descriptor_M_RAW_SynthesizedRef = {&sort_M_RawSynthesizedRef, Data_M_RAW_SynthesizedRef, 1, sizeof(STRUCT_Con_M_RAW_SynthesizedRef), conBindOffs_M_RAW_SynthesizedRef, &nameFun_M_RAW_SynthesizedRef, &dataStep};
ConstructionDescriptor sortCon_M_RawSynthesizedRef[] = {NULL, NULL, &descriptor_M_RAW_SynthesizedRef,  NULL};
char *sortNam_M_RawSynthesizedRef[] = {NULL, NULL,  "RAW-SynthesizedRef" ,  NULL};
char *sortInt_M_RawSynthesizedRef[] = {NULL, NULL, "_M_RAW_SynthesizedRef",  NULL};
struct _SortDescriptor sort_M_RawSynthesizedRef = { "RawSynthesizedRef" , sortCon_M_RawSynthesizedRef, sortNam_M_RawSynthesizedRef, sortInt_M_RawSynthesizedRef, NULL};

/* SORT RawTerm CONSTANTS. */
int conBindOffs_M_RAW_VariableUseSorted[] = {0 , 0 , 0 , 0 , 0};
char *name_M_RAW_VariableUseSorted =  "RAW-VariableUseSorted" ;
char *nameFun_M_RAW_VariableUseSorted(Term term) { return name_M_RAW_VariableUseSorted; }
struct _ConstructionDescriptor descriptor_M_RAW_VariableUseSorted = {&sort_M_RawTerm, Data_M_RAW_VariableUseSorted, 4, sizeof(STRUCT_Con_M_RAW_VariableUseSorted), conBindOffs_M_RAW_VariableUseSorted, &nameFun_M_RAW_VariableUseSorted, &dataStep};
int conBindOffs_M_RAW_Parsed[] = {0 , 0 , 0};
char *name_M_RAW_Parsed =  "RAW-Parsed" ;
char *nameFun_M_RAW_Parsed(Term term) { return name_M_RAW_Parsed; }
struct _ConstructionDescriptor descriptor_M_RAW_Parsed = {&sort_M_RawTerm, Data_M_RAW_Parsed, 2, sizeof(STRUCT_Con_M_RAW_Parsed), conBindOffs_M_RAW_Parsed, &nameFun_M_RAW_Parsed, &dataStep};
int conBindOffs_M_RAW_Literal[] = {0 , 0 , 0};
char *name_M_RAW_Literal =  "RAW-Literal" ;
char *nameFun_M_RAW_Literal(Term term) { return name_M_RAW_Literal; }
struct _ConstructionDescriptor descriptor_M_RAW_Literal = {&sort_M_RawTerm, Data_M_RAW_Literal, 2, sizeof(STRUCT_Con_M_RAW_Literal), conBindOffs_M_RAW_Literal, &nameFun_M_RAW_Literal, &dataStep};
int conBindOffs_M_RAW_ParsedSorted[] = {0 , 0 , 0 , 0 , 0};
char *name_M_RAW_ParsedSorted =  "RAW-ParsedSorted" ;
char *nameFun_M_RAW_ParsedSorted(Term term) { return name_M_RAW_ParsedSorted; }
struct _ConstructionDescriptor descriptor_M_RAW_ParsedSorted = {&sort_M_RawTerm, Data_M_RAW_ParsedSorted, 4, sizeof(STRUCT_Con_M_RAW_ParsedSorted), conBindOffs_M_RAW_ParsedSorted, &nameFun_M_RAW_ParsedSorted, &dataStep};
int conBindOffs_M_RAW_Construction[] = {0 , 0 , 0 , 0};
char *name_M_RAW_Construction =  "RAW-Construction" ;
char *nameFun_M_RAW_Construction(Term term) { return name_M_RAW_Construction; }
struct _ConstructionDescriptor descriptor_M_RAW_Construction = {&sort_M_RawTerm, Data_M_RAW_Construction, 3, sizeof(STRUCT_Con_M_RAW_Construction), conBindOffs_M_RAW_Construction, &nameFun_M_RAW_Construction, &dataStep};
int conBindOffs_M_RAW_ConstructionSorted[] = {0 , 0 , 0 , 0 , 0 , 0};
char *name_M_RAW_ConstructionSorted =  "RAW-ConstructionSorted" ;
char *nameFun_M_RAW_ConstructionSorted(Term term) { return name_M_RAW_ConstructionSorted; }
struct _ConstructionDescriptor descriptor_M_RAW_ConstructionSorted = {&sort_M_RawTerm, Data_M_RAW_ConstructionSorted, 5, sizeof(STRUCT_Con_M_RAW_ConstructionSorted), conBindOffs_M_RAW_ConstructionSorted, &nameFun_M_RAW_ConstructionSorted, &dataStep};
int conBindOffs_M_RAW_MetaApplication[] = {0 , 0 , 0 , 0};
char *name_M_RAW_MetaApplication =  "RAW-MetaApplication" ;
char *nameFun_M_RAW_MetaApplication(Term term) { return name_M_RAW_MetaApplication; }
struct _ConstructionDescriptor descriptor_M_RAW_MetaApplication = {&sort_M_RawTerm, Data_M_RAW_MetaApplication, 3, sizeof(STRUCT_Con_M_RAW_MetaApplication), conBindOffs_M_RAW_MetaApplication, &nameFun_M_RAW_MetaApplication, &dataStep};
int conBindOffs_M_RAW_MetaApplicationSorted[] = {0 , 0 , 0 , 0 , 0 , 0};
char *name_M_RAW_MetaApplicationSorted =  "RAW-MetaApplicationSorted" ;
char *nameFun_M_RAW_MetaApplicationSorted(Term term) { return name_M_RAW_MetaApplicationSorted; }
struct _ConstructionDescriptor descriptor_M_RAW_MetaApplicationSorted = {&sort_M_RawTerm, Data_M_RAW_MetaApplicationSorted, 5, sizeof(STRUCT_Con_M_RAW_MetaApplicationSorted), conBindOffs_M_RAW_MetaApplicationSorted, &nameFun_M_RAW_MetaApplicationSorted, &dataStep};
int conBindOffs_M_RAW_Special[] = {0 , 0 , 0};
char *name_M_RAW_Special =  "RAW-Special" ;
char *nameFun_M_RAW_Special(Term term) { return name_M_RAW_Special; }
struct _ConstructionDescriptor descriptor_M_RAW_Special = {&sort_M_RawTerm, Data_M_RAW_Special, 2, sizeof(STRUCT_Con_M_RAW_Special), conBindOffs_M_RAW_Special, &nameFun_M_RAW_Special, &dataStep};
char *name_M_OMITTED =  "OMITTED" ;
char *nameFun_M_OMITTED(Term term) { return name_M_OMITTED; }
struct _ConstructionDescriptor descriptor_M_OMITTED = {&sort_M_RawTerm, Data_M_OMITTED, 0, sizeof(STRUCT_Con_M_OMITTED), noBinderOffsets, &nameFun_M_OMITTED, &dataStep};
int conBindOffs_M_RAW_VariableUse[] = {0 , 0 , 0};
char *name_M_RAW_VariableUse =  "RAW-VariableUse" ;
char *nameFun_M_RAW_VariableUse(Term term) { return name_M_RAW_VariableUse; }
struct _ConstructionDescriptor descriptor_M_RAW_VariableUse = {&sort_M_RawTerm, Data_M_RAW_VariableUse, 2, sizeof(STRUCT_Con_M_RAW_VariableUse), conBindOffs_M_RAW_VariableUse, &nameFun_M_RAW_VariableUse, &dataStep};
ConstructionDescriptor sortCon_M_RawTerm[] = {NULL, NULL, &descriptor_M_RAW_VariableUseSorted, &descriptor_M_RAW_Parsed, &descriptor_M_RAW_Literal, &descriptor_M_RAW_ParsedSorted, &descriptor_M_RAW_Construction, &descriptor_M_RAW_ConstructionSorted, &descriptor_M_RAW_MetaApplication, &descriptor_M_RAW_MetaApplicationSorted, &descriptor_M_RAW_Special, &descriptor_M_OMITTED, &descriptor_M_RAW_VariableUse,  NULL};
char *sortNam_M_RawTerm[] = {NULL, NULL,  "RAW-VariableUseSorted" ,  "RAW-Parsed" ,  "RAW-Literal" ,  "RAW-ParsedSorted" ,  "RAW-Construction" ,  "RAW-ConstructionSorted" ,  "RAW-MetaApplication" ,  "RAW-MetaApplicationSorted" ,  "RAW-Special" ,  "OMITTED" ,  "RAW-VariableUse" ,  NULL};
char *sortInt_M_RawTerm[] = {NULL, NULL, "_M_RAW_VariableUseSorted", "_M_RAW_Parsed", "_M_RAW_Literal", "_M_RAW_ParsedSorted", "_M_RAW_Construction", "_M_RAW_ConstructionSorted", "_M_RAW_MetaApplication", "_M_RAW_MetaApplicationSorted", "_M_RAW_Special", "_M_OMITTED", "_M_RAW_VariableUse",  NULL};
struct _SortDescriptor sort_M_RawTerm = { "RawTerm" , sortCon_M_RawTerm, sortNam_M_RawTerm, sortInt_M_RawTerm, NULL};

/* SORT RefMode CONSTANTS. */
char *name_M_RM_xNONE =  "RM_NONE" ;
char *nameFun_M_RM_xNONE(Term term) { return name_M_RM_xNONE; }
struct _ConstructionDescriptor descriptor_M_RM_xNONE = {&sort_M_RefMode, Data_M_RM_xNONE, 0, sizeof(STRUCT_Con_M_RM_xNONE), noBinderOffsets, &nameFun_M_RM_xNONE, &dataStep};
char *name_M_RM_xALL =  "RM_ALL" ;
char *nameFun_M_RM_xALL(Term term) { return name_M_RM_xALL; }
struct _ConstructionDescriptor descriptor_M_RM_xALL = {&sort_M_RefMode, Data_M_RM_xALL, 0, sizeof(STRUCT_Con_M_RM_xALL), noBinderOffsets, &nameFun_M_RM_xALL, &dataStep};
char *name_M_RM_xONLY_xTOP =  "RM_ONLY_TOP" ;
char *nameFun_M_RM_xONLY_xTOP(Term term) { return name_M_RM_xONLY_xTOP; }
struct _ConstructionDescriptor descriptor_M_RM_xONLY_xTOP = {&sort_M_RefMode, Data_M_RM_xONLY_xTOP, 0, sizeof(STRUCT_Con_M_RM_xONLY_xTOP), noBinderOffsets, &nameFun_M_RM_xONLY_xTOP, &dataStep};
ConstructionDescriptor sortCon_M_RefMode[] = {NULL, NULL, &descriptor_M_RM_xNONE, &descriptor_M_RM_xALL, &descriptor_M_RM_xONLY_xTOP,  NULL};
char *sortNam_M_RefMode[] = {NULL, NULL,  "RM_NONE" ,  "RM_ALL" ,  "RM_ONLY_TOP" ,  NULL};
char *sortInt_M_RefMode[] = {NULL, NULL, "_M_RM_xNONE", "_M_RM_xALL", "_M_RM_xONLY_xTOP",  NULL};
struct _SortDescriptor sort_M_RefMode = { "RefMode" , sortCon_M_RefMode, sortNam_M_RefMode, sortInt_M_RefMode, NULL};

/* SORT SortEntry CONSTANTS. */
char *name_M_SE_xNONE =  "SE_NONE" ;
char *nameFun_M_SE_xNONE(Term term) { return name_M_SE_xNONE; }
struct _ConstructionDescriptor descriptor_M_SE_xNONE = {&sort_M_SortEntry, Data_M_SE_xNONE, 0, sizeof(STRUCT_Con_M_SE_xNONE), noBinderOffsets, &nameFun_M_SE_xNONE, &dataStep};
int conBindOffs_M_NAMES[] = {0 , 0};
char *name_M_NAMES =  "NAMES" ;
char *nameFun_M_NAMES(Term term) { return name_M_NAMES; }
struct _ConstructionDescriptor descriptor_M_NAMES = {&sort_M_SortEntry, Data_M_NAMES, 1, sizeof(STRUCT_Con_M_NAMES), conBindOffs_M_NAMES, &nameFun_M_NAMES, &dataStep};
int conBindOffs_M_SE_xTOKEN[] = {0 , 0 , 0};
char *name_M_SE_xTOKEN =  "SE_TOKEN" ;
char *nameFun_M_SE_xTOKEN(Term term) { return name_M_SE_xTOKEN; }
struct _ConstructionDescriptor descriptor_M_SE_xTOKEN = {&sort_M_SortEntry, Data_M_SE_xTOKEN, 2, sizeof(STRUCT_Con_M_SE_xTOKEN), conBindOffs_M_SE_xTOKEN, &nameFun_M_SE_xTOKEN, &dataStep};
int conBindOffs_M_SE_xATTRIBUTE[] = {0 , 0 , 0 , 0 , 0};
char *name_M_SE_xATTRIBUTE =  "SE_ATTRIBUTE" ;
char *nameFun_M_SE_xATTRIBUTE(Term term) { return name_M_SE_xATTRIBUTE; }
struct _ConstructionDescriptor descriptor_M_SE_xATTRIBUTE = {&sort_M_SortEntry, Data_M_SE_xATTRIBUTE, 4, sizeof(STRUCT_Con_M_SE_xATTRIBUTE), conBindOffs_M_SE_xATTRIBUTE, &nameFun_M_SE_xATTRIBUTE, &dataStep};
int conBindOffs_M_SE_xSORT[] = {0 , 0 , 0 , 0 , 0 , 0};
char *name_M_SE_xSORT =  "SE_SORT" ;
char *nameFun_M_SE_xSORT(Term term) { return name_M_SE_xSORT; }
struct _ConstructionDescriptor descriptor_M_SE_xSORT = {&sort_M_SortEntry, Data_M_SE_xSORT, 5, sizeof(STRUCT_Con_M_SE_xSORT), conBindOffs_M_SE_xSORT, &nameFun_M_SE_xSORT, &dataStep};
ConstructionDescriptor sortCon_M_SortEntry[] = {NULL, NULL, &descriptor_M_SE_xNONE, &descriptor_M_NAMES, &descriptor_M_SE_xTOKEN, &descriptor_M_SE_xATTRIBUTE, &descriptor_M_SE_xSORT,  NULL};
char *sortNam_M_SortEntry[] = {NULL, NULL,  "SE_NONE" ,  "NAMES" ,  "SE_TOKEN" ,  "SE_ATTRIBUTE" ,  "SE_SORT" ,  NULL};
char *sortInt_M_SortEntry[] = {NULL, NULL, "_M_SE_xNONE", "_M_NAMES", "_M_SE_xTOKEN", "_M_SE_xATTRIBUTE", "_M_SE_xSORT",  NULL};
struct _SortDescriptor sort_M_SortEntry = { "SortEntry" , sortCon_M_SortEntry, sortNam_M_SortEntry, sortInt_M_SortEntry, NULL};

/* SORT Text CONSTANTS. */
char *name_M__sTextNil =  "$TextNil" ;
char *nameFun_M__sTextNil(Term term) { return name_M__sTextNil; }
struct _ConstructionDescriptor descriptor_M__sTextNil = {&sort_M_Text, Data_M__sTextNil, 0, sizeof(STRUCT_Con_M__sTextNil), noBinderOffsets, &nameFun_M__sTextNil, &dataStep};
int conBindOffs_M__sTextCons[] = {0 , 0 , 0};
char *name_M__sTextCons =  "$TextCons" ;
char *nameFun_M__sTextCons(Term term) { return name_M__sTextCons; }
struct _ConstructionDescriptor descriptor_M__sTextCons = {&sort_M_Text, Data_M__sTextCons, 2, sizeof(STRUCT_Con_M__sTextCons), conBindOffs_M__sTextCons, &nameFun_M__sTextCons, &dataStep};
ConstructionDescriptor sortCon_M_Text[] = {NULL, NULL, &descriptor_M__sTextNil, &descriptor_M__sTextCons,  NULL};
char *sortNam_M_Text[] = {NULL, NULL,  "$TextNil" ,  "$TextCons" ,  NULL};
char *sortInt_M_Text[] = {NULL, NULL, "_M__sTextNil", "_M__sTextCons",  NULL};
struct _SortDescriptor sort_M_Text = { "Text" , sortCon_M_Text, sortNam_M_Text, sortInt_M_Text, NULL};

/* SORT Text-Part CONSTANTS. */
int conBindOffs_M__sTextString[] = {0 , 0};
char *name_M__sTextString =  "$TextString" ;
char *nameFun_M__sTextString(Term term) { return name_M__sTextString; }
struct _ConstructionDescriptor descriptor_M__sTextString = {&sort_M_Text_Part, Data_M__sTextString, 1, sizeof(STRUCT_Con_M__sTextString), conBindOffs_M__sTextString, &nameFun_M__sTextString, &dataStep};
int conBindOffs_M__sTextEmbed[] = {0 , 0};
char *name_M__sTextEmbed =  "$TextEmbed" ;
char *nameFun_M__sTextEmbed(Term term) { return name_M__sTextEmbed; }
struct _ConstructionDescriptor descriptor_M__sTextEmbed = {&sort_M_Text_Part, Data_M__sTextEmbed, 1, sizeof(STRUCT_Con_M__sTextEmbed), conBindOffs_M__sTextEmbed, &nameFun_M__sTextEmbed, &dataStep};
int conBindOffs_M__sTextIndent[] = {0 , 0};
char *name_M__sTextIndent =  "$TextIndent" ;
char *nameFun_M__sTextIndent(Term term) { return name_M__sTextIndent; }
struct _ConstructionDescriptor descriptor_M__sTextIndent = {&sort_M_Text_Part, Data_M__sTextIndent, 1, sizeof(STRUCT_Con_M__sTextIndent), conBindOffs_M__sTextIndent, &nameFun_M__sTextIndent, &dataStep};
int conBindOffs_M__sTextGroup[] = {0 , 0};
char *name_M__sTextGroup =  "$TextGroup" ;
char *nameFun_M__sTextGroup(Term term) { return name_M__sTextGroup; }
struct _ConstructionDescriptor descriptor_M__sTextGroup = {&sort_M_Text_Part, Data_M__sTextGroup, 1, sizeof(STRUCT_Con_M__sTextGroup), conBindOffs_M__sTextGroup, &nameFun_M__sTextGroup, &dataStep};
char *name_M__sTextSeparator =  "$TextSeparator" ;
char *nameFun_M__sTextSeparator(Term term) { return name_M__sTextSeparator; }
struct _ConstructionDescriptor descriptor_M__sTextSeparator = {&sort_M_Text_Part, Data_M__sTextSeparator, 0, sizeof(STRUCT_Con_M__sTextSeparator), noBinderOffsets, &nameFun_M__sTextSeparator, &dataStep};
int conBindOffs_M__sTextBreak[] = {0 , 0};
char *name_M__sTextBreak =  "$TextBreak" ;
char *nameFun_M__sTextBreak(Term term) { return name_M__sTextBreak; }
struct _ConstructionDescriptor descriptor_M__sTextBreak = {&sort_M_Text_Part, Data_M__sTextBreak, 1, sizeof(STRUCT_Con_M__sTextBreak), conBindOffs_M__sTextBreak, &nameFun_M__sTextBreak, &dataStep};
int conBindOffs_M__sTextChars[] = {0 , 0};
char *name_M__sTextChars =  "$TextChars" ;
char *nameFun_M__sTextChars(Term term) { return name_M__sTextChars; }
struct _ConstructionDescriptor descriptor_M__sTextChars = {&sort_M_Text_Part, Data_M__sTextChars, 1, sizeof(STRUCT_Con_M__sTextChars), conBindOffs_M__sTextChars, &nameFun_M__sTextChars, &dataStep};
ConstructionDescriptor sortCon_M_Text_Part[] = {NULL, NULL, &descriptor_M__sTextString, &descriptor_M__sTextEmbed, &descriptor_M__sTextIndent, &descriptor_M__sTextGroup, &descriptor_M__sTextSeparator, &descriptor_M__sTextBreak, &descriptor_M__sTextChars,  NULL};
char *sortNam_M_Text_Part[] = {NULL, NULL,  "$TextString" ,  "$TextEmbed" ,  "$TextIndent" ,  "$TextGroup" ,  "$TextSeparator" ,  "$TextBreak" ,  "$TextChars" ,  NULL};
char *sortInt_M_Text_Part[] = {NULL, NULL, "_M__sTextString", "_M__sTextEmbed", "_M__sTextIndent", "_M__sTextGroup", "_M__sTextSeparator", "_M__sTextBreak", "_M__sTextChars",  NULL};
struct _SortDescriptor sort_M_Text_Part = { "Text-Part" , sortCon_M_Text_Part, sortNam_M_Text_Part, sortInt_M_Text_Part, NULL};

/* SORT TextMapSort CONSTANTS. */
int conBindOffs_M_TEXT_xMAP[] = {0 , 0};
char *name_M_TEXT_xMAP =  "TEXT_MAP" ;
char *nameFun_M_TEXT_xMAP(Term term) { return name_M_TEXT_xMAP; }
struct _ConstructionDescriptor descriptor_M_TEXT_xMAP = {&sort_M_TextMapSort, Data_M_TEXT_xMAP, 1, sizeof(STRUCT_Con_M_TEXT_xMAP), conBindOffs_M_TEXT_xMAP, &nameFun_M_TEXT_xMAP, &dataStep};
ConstructionDescriptor sortCon_M_TextMapSort[] = {NULL, NULL, &descriptor_M_TEXT_xMAP,  NULL};
char *sortNam_M_TextMapSort[] = {NULL, NULL,  "TEXT_MAP" ,  NULL};
char *sortInt_M_TextMapSort[] = {NULL, NULL, "_M_TEXT_xMAP",  NULL};
struct _SortDescriptor sort_M_TextMapSort = { "TextMapSort" , sortCon_M_TextMapSort, sortNam_M_TextMapSort, sortInt_M_TextMapSort, NULL};

/* SORT Wrapper CONSTANTS. */
int conBindOffs_M_Wrapper[] = {0 , 0};
char *name_M_Wrapper =  "Wrapper" ;
char *nameFun_M_Wrapper(Term term) { return name_M_Wrapper; }
struct _ConstructionDescriptor descriptor_M_Wrapper = {&sort_M_Wrapper, Data_M_Wrapper, 1, sizeof(STRUCT_Con_M_Wrapper), conBindOffs_M_Wrapper, &nameFun_M_Wrapper, &dataStep};
char *name_M_NoWrapper =  "NoWrapper" ;
char *nameFun_M_NoWrapper(Term term) { return name_M_NoWrapper; }
struct _ConstructionDescriptor descriptor_M_NoWrapper = {&sort_M_Wrapper, Data_M_NoWrapper, 0, sizeof(STRUCT_Con_M_NoWrapper), noBinderOffsets, &nameFun_M_NoWrapper, &dataStep};
ConstructionDescriptor sortCon_M_Wrapper[] = {NULL, NULL, &descriptor_M_Wrapper, &descriptor_M_NoWrapper,  NULL};
char *sortNam_M_Wrapper[] = {NULL, NULL,  "Wrapper" ,  "NoWrapper" ,  NULL};
char *sortInt_M_Wrapper[] = {NULL, NULL, "_M_Wrapper", "_M_NoWrapper",  NULL};
struct _SortDescriptor sort_M_Wrapper = { "Wrapper" , sortCon_M_Wrapper, sortNam_M_Wrapper, sortInt_M_Wrapper, NULL};

#ifdef __cplusplus
}
#endif
/* END OF C SORT DESCRIPTORS FOR CRSX Cook. */

