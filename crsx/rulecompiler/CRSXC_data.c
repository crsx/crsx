/* C SORT DESCRIPTORS FOR CRSX CRSXC. */
#include "CRSXC.h" 
#ifdef __cplusplus
extern "C" {
#endif

/* SORT $Boolean CONSTANTS. */
char *name_M__sTrue =  "$True" ;
char *nameFun_M__sTrue(Term term) { return name_M__sTrue; }
struct _ConstructionDescriptor descriptor_M__sTrue = {&sort_M__sBoolean, Data_M__sTrue, 0, sizeof(STRUCT_Con_M__sTrue), noBinderOffsets, &nameFun_M__sTrue, &dataStep};
char *name_M__sFalse =  "$False" ;
char *nameFun_M__sFalse(Term term) { return name_M__sFalse; }
struct _ConstructionDescriptor descriptor_M__sFalse = {&sort_M__sBoolean, Data_M__sFalse, 0, sizeof(STRUCT_Con_M__sFalse), noBinderOffsets, &nameFun_M__sFalse, &dataStep};
ConstructionDescriptor sortCon_M__sBoolean[] = {NULL, NULL, &descriptor_M__sTrue, &descriptor_M__sFalse,  NULL};
char *sortNam_M__sBoolean[] = {NULL, NULL,  "$True" ,  "$False" ,  NULL};
char *sortInt_M__sBoolean[] = {NULL, NULL, "_M__sTrue", "_M__sFalse",  NULL};
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

/* SORT Binder-State CONSTANTS. */
char *name_M_OUTER =  "OUTER" ;
char *nameFun_M_OUTER(Term term) { return name_M_OUTER; }
struct _ConstructionDescriptor descriptor_M_OUTER = {&sort_M_Binder_State, Data_M_OUTER, 0, sizeof(STRUCT_Con_M_OUTER), noBinderOffsets, &nameFun_M_OUTER, &dataStep};
char *name_M_REUSING =  "REUSING" ;
char *nameFun_M_REUSING(Term term) { return name_M_REUSING; }
struct _ConstructionDescriptor descriptor_M_REUSING = {&sort_M_Binder_State, Data_M_REUSING, 0, sizeof(STRUCT_Con_M_REUSING), noBinderOffsets, &nameFun_M_REUSING, &dataStep};
char *name_M_COPYING =  "COPYING" ;
char *nameFun_M_COPYING(Term term) { return name_M_COPYING; }
struct _ConstructionDescriptor descriptor_M_COPYING = {&sort_M_Binder_State, Data_M_COPYING, 0, sizeof(STRUCT_Con_M_COPYING), noBinderOffsets, &nameFun_M_COPYING, &dataStep};
char *name_M_NO_xREUSE =  "NO_REUSE" ;
char *nameFun_M_NO_xREUSE(Term term) { return name_M_NO_xREUSE; }
struct _ConstructionDescriptor descriptor_M_NO_xREUSE = {&sort_M_Binder_State, Data_M_NO_xREUSE, 0, sizeof(STRUCT_Con_M_NO_xREUSE), noBinderOffsets, &nameFun_M_NO_xREUSE, &dataStep};
ConstructionDescriptor sortCon_M_Binder_State[] = {NULL, NULL, &descriptor_M_OUTER, &descriptor_M_REUSING, &descriptor_M_COPYING, &descriptor_M_NO_xREUSE,  NULL};
char *sortNam_M_Binder_State[] = {NULL, NULL,  "OUTER" ,  "REUSING" ,  "COPYING" ,  "NO_REUSE" ,  NULL};
char *sortInt_M_Binder_State[] = {NULL, NULL, "_M_OUTER", "_M_REUSING", "_M_COPYING", "_M_NO_xREUSE",  NULL};
struct _SortDescriptor sort_M_Binder_State = { "Binder-State" , sortCon_M_Binder_State, sortNam_M_Binder_State, sortInt_M_Binder_State, NULL};

/* SORT Meta-Occurrence CONSTANTS. */
char *name_M_NOTHING =  "NOTHING" ;
char *nameFun_M_NOTHING(Term term) { return name_M_NOTHING; }
struct _ConstructionDescriptor descriptor_M_NOTHING = {&sort_M_Meta_Occurrence, Data_M_NOTHING, 0, sizeof(STRUCT_Con_M_NOTHING), noBinderOffsets, &nameFun_M_NOTHING, &dataStep};
int conBindOffs_M_UNIQUE[] = {0 , 0};
char *name_M_UNIQUE =  "UNIQUE" ;
char *nameFun_M_UNIQUE(Term term) { return name_M_UNIQUE; }
struct _ConstructionDescriptor descriptor_M_UNIQUE = {&sort_M_Meta_Occurrence, Data_M_UNIQUE, 1, sizeof(STRUCT_Con_M_UNIQUE), conBindOffs_M_UNIQUE, &nameFun_M_UNIQUE, &dataStep};
ConstructionDescriptor sortCon_M_Meta_Occurrence[] = {NULL, NULL, &descriptor_M_NOTHING, &descriptor_M_UNIQUE,  NULL};
char *sortNam_M_Meta_Occurrence[] = {NULL, NULL,  "NOTHING" ,  "UNIQUE" ,  NULL};
char *sortInt_M_Meta_Occurrence[] = {NULL, NULL, "_M_NOTHING", "_M_UNIQUE",  NULL};
struct _SortDescriptor sort_M_Meta_Occurrence = { "Meta-Occurrence" , sortCon_M_Meta_Occurrence, sortNam_M_Meta_Occurrence, sortInt_M_Meta_Occurrence, NULL};

/* SORT OK_SORT CONSTANTS. */
char *name_M_OK =  "OK" ;
char *nameFun_M_OK(Term term) { return name_M_OK; }
struct _ConstructionDescriptor descriptor_M_OK = {&sort_M_OK_xSORT, Data_M_OK, 0, sizeof(STRUCT_Con_M_OK), noBinderOffsets, &nameFun_M_OK, &dataStep};
ConstructionDescriptor sortCon_M_OK_xSORT[] = {NULL, NULL, &descriptor_M_OK,  NULL};
char *sortNam_M_OK_xSORT[] = {NULL, NULL,  "OK" ,  NULL};
char *sortInt_M_OK_xSORT[] = {NULL, NULL, "_M_OK",  NULL};
struct _SortDescriptor sort_M_OK_xSORT = { "OK_SORT" , sortCon_M_OK_xSORT, sortNam_M_OK_xSORT, sortInt_M_OK_xSORT, NULL};

/* SORT PASS CONSTANTS. */
char *name_M_FIRST =  "FIRST" ;
char *nameFun_M_FIRST(Term term) { return name_M_FIRST; }
struct _ConstructionDescriptor descriptor_M_FIRST = {&sort_M_PASS, Data_M_FIRST, 0, sizeof(STRUCT_Con_M_FIRST), noBinderOffsets, &nameFun_M_FIRST, &dataStep};
char *name_M_SECOND =  "SECOND" ;
char *nameFun_M_SECOND(Term term) { return name_M_SECOND; }
struct _ConstructionDescriptor descriptor_M_SECOND = {&sort_M_PASS, Data_M_SECOND, 0, sizeof(STRUCT_Con_M_SECOND), noBinderOffsets, &nameFun_M_SECOND, &dataStep};
ConstructionDescriptor sortCon_M_PASS[] = {NULL, NULL, &descriptor_M_FIRST, &descriptor_M_SECOND,  NULL};
char *sortNam_M_PASS[] = {NULL, NULL,  "FIRST" ,  "SECOND" ,  NULL};
char *sortInt_M_PASS[] = {NULL, NULL, "_M_FIRST", "_M_SECOND",  NULL};
struct _SortDescriptor sort_M_PASS = { "PASS" , sortCon_M_PASS, sortNam_M_PASS, sortInt_M_PASS, NULL};

/* SORT Pattern-Stage CONSTANTS. */
char *name_M_SUBMATCH =  "SUBMATCH" ;
char *nameFun_M_SUBMATCH(Term term) { return name_M_SUBMATCH; }
struct _ConstructionDescriptor descriptor_M_SUBMATCH = {&sort_M_Pattern_Stage, Data_M_SUBMATCH, 0, sizeof(STRUCT_Con_M_SUBMATCH), noBinderOffsets, &nameFun_M_SUBMATCH, &dataStep};
int conBindOffs_M_DISPATCH[] = {0 , 0 , 0 , 0};
char *name_M_DISPATCH =  "DISPATCH" ;
char *nameFun_M_DISPATCH(Term term) { return name_M_DISPATCH; }
struct _ConstructionDescriptor descriptor_M_DISPATCH = {&sort_M_Pattern_Stage, Data_M_DISPATCH, 3, sizeof(STRUCT_Con_M_DISPATCH), conBindOffs_M_DISPATCH, &nameFun_M_DISPATCH, &dataStep};
char *name_M_MATCH =  "MATCH" ;
char *nameFun_M_MATCH(Term term) { return name_M_MATCH; }
struct _ConstructionDescriptor descriptor_M_MATCH = {&sort_M_Pattern_Stage, Data_M_MATCH, 0, sizeof(STRUCT_Con_M_MATCH), noBinderOffsets, &nameFun_M_MATCH, &dataStep};
int conBindOffs_M_CASE[] = {0 , 0 , 0 , 0};
char *name_M_CASE =  "CASE" ;
char *nameFun_M_CASE(Term term) { return name_M_CASE; }
struct _ConstructionDescriptor descriptor_M_CASE = {&sort_M_Pattern_Stage, Data_M_CASE, 3, sizeof(STRUCT_Con_M_CASE), conBindOffs_M_CASE, &nameFun_M_CASE, &dataStep};
ConstructionDescriptor sortCon_M_Pattern_Stage[] = {NULL, NULL, &descriptor_M_SUBMATCH, &descriptor_M_DISPATCH, &descriptor_M_MATCH, &descriptor_M_CASE,  NULL};
char *sortNam_M_Pattern_Stage[] = {NULL, NULL,  "SUBMATCH" ,  "DISPATCH" ,  "MATCH" ,  "CASE" ,  NULL};
char *sortInt_M_Pattern_Stage[] = {NULL, NULL, "_M_SUBMATCH", "_M_DISPATCH", "_M_MATCH", "_M_CASE",  NULL};
struct _SortDescriptor sort_M_Pattern_Stage = { "Pattern-Stage" , sortCon_M_Pattern_Stage, sortNam_M_Pattern_Stage, sortInt_M_Pattern_Stage, NULL};

/* SORT PropsOf$$TextCons_SORT CONSTANTS. */
char *name_M_PropsOf_s_sTextCons =  "PropsOf$$TextCons" ;
char *nameFun_M_PropsOf_s_sTextCons(Term term) { return name_M_PropsOf_s_sTextCons; }
struct _ConstructionDescriptor descriptor_M_PropsOf_s_sTextCons = {&sort_M_PropsOf_s_sTextCons_xSORT, Data_M_PropsOf_s_sTextCons, 0, sizeof(STRUCT_Con_M_PropsOf_s_sTextCons), noBinderOffsets, &nameFun_M_PropsOf_s_sTextCons, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_s_sTextCons_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_s_sTextCons,  NULL};
char *sortNam_M_PropsOf_s_sTextCons_xSORT[] = {NULL, NULL,  "PropsOf$$TextCons" ,  NULL};
char *sortInt_M_PropsOf_s_sTextCons_xSORT[] = {NULL, NULL, "_M_PropsOf_s_sTextCons",  NULL};
struct _SortDescriptor sort_M_PropsOf_s_sTextCons_xSORT = { "PropsOf$$TextCons_SORT" , sortCon_M_PropsOf_s_sTextCons_xSORT, sortNam_M_PropsOf_s_sTextCons_xSORT, sortInt_M_PropsOf_s_sTextCons_xSORT, NULL};

/* SORT PropsOf$$TextNil_SORT CONSTANTS. */
char *name_M_PropsOf_s_sTextNil =  "PropsOf$$TextNil" ;
char *nameFun_M_PropsOf_s_sTextNil(Term term) { return name_M_PropsOf_s_sTextNil; }
struct _ConstructionDescriptor descriptor_M_PropsOf_s_sTextNil = {&sort_M_PropsOf_s_sTextNil_xSORT, Data_M_PropsOf_s_sTextNil, 0, sizeof(STRUCT_Con_M_PropsOf_s_sTextNil), noBinderOffsets, &nameFun_M_PropsOf_s_sTextNil, &dataStep};
ConstructionDescriptor sortCon_M_PropsOf_s_sTextNil_xSORT[] = {NULL, NULL, &descriptor_M_PropsOf_s_sTextNil,  NULL};
char *sortNam_M_PropsOf_s_sTextNil_xSORT[] = {NULL, NULL,  "PropsOf$$TextNil" ,  NULL};
char *sortInt_M_PropsOf_s_sTextNil_xSORT[] = {NULL, NULL, "_M_PropsOf_s_sTextNil",  NULL};
struct _SortDescriptor sort_M_PropsOf_s_sTextNil_xSORT = { "PropsOf$$TextNil_SORT" , sortCon_M_PropsOf_s_sTextNil_xSORT, sortNam_M_PropsOf_s_sTextNil_xSORT, sortInt_M_PropsOf_s_sTextNil_xSORT, NULL};

/* SORT Reified_Binder CONSTANTS. */
int conBindOffs_M_BINDER[] = {0 , 0 , 0 , 0 , 1};
char *name_M_BINDER =  "BINDER" ;
char *nameFun_M_BINDER(Term term) { return name_M_BINDER; }
struct _ConstructionDescriptor descriptor_M_BINDER = {&sort_M_Reified_xBinder, Data_M_BINDER, 4, sizeof(STRUCT_Con_M_BINDER), conBindOffs_M_BINDER, &nameFun_M_BINDER, &dataStep};
int conBindOffs_M_ARGUMENT[] = {0 , 0 , 0};
char *name_M_ARGUMENT =  "ARGUMENT" ;
char *nameFun_M_ARGUMENT(Term term) { return name_M_ARGUMENT; }
struct _ConstructionDescriptor descriptor_M_ARGUMENT = {&sort_M_Reified_xBinder, Data_M_ARGUMENT, 2, sizeof(STRUCT_Con_M_ARGUMENT), conBindOffs_M_ARGUMENT, &nameFun_M_ARGUMENT, &dataStep};
int conBindOffs_M_META_REQUIRED_VARIABLE[] = {0 , 0};
char *name_M_META_REQUIRED_VARIABLE =  "META-REQUIRED-VARIABLE" ;
char *nameFun_M_META_REQUIRED_VARIABLE(Term term) { return name_M_META_REQUIRED_VARIABLE; }
struct _ConstructionDescriptor descriptor_M_META_REQUIRED_VARIABLE = {&sort_M_Reified_xBinder, Data_M_META_REQUIRED_VARIABLE, 1, sizeof(STRUCT_Con_M_META_REQUIRED_VARIABLE), conBindOffs_M_META_REQUIRED_VARIABLE, &nameFun_M_META_REQUIRED_VARIABLE, &dataStep};
ConstructionDescriptor sortCon_M_Reified_xBinder[] = {NULL, NULL, &descriptor_M_BINDER, &descriptor_M_ARGUMENT, &descriptor_M_META_REQUIRED_VARIABLE,  NULL};
char *sortNam_M_Reified_xBinder[] = {NULL, NULL,  "BINDER" ,  "ARGUMENT" ,  "META-REQUIRED-VARIABLE" ,  NULL};
char *sortInt_M_Reified_xBinder[] = {NULL, NULL, "_M_BINDER", "_M_ARGUMENT", "_M_META_REQUIRED_VARIABLE",  NULL};
struct _SortDescriptor sort_M_Reified_xBinder = { "Reified_Binder" , sortCon_M_Reified_xBinder, sortNam_M_Reified_xBinder, sortInt_M_Reified_xBinder, NULL};

/* SORT Reified_Declaration CONSTANTS. */
int conBindOffs_M_FUNCTION[] = {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0};
char *name_M_FUNCTION =  "FUNCTION" ;
char *nameFun_M_FUNCTION(Term term) { return name_M_FUNCTION; }
struct _ConstructionDescriptor descriptor_M_FUNCTION = {&sort_M_Reified_xDeclaration, Data_M_FUNCTION, 7, sizeof(STRUCT_Con_M_FUNCTION), conBindOffs_M_FUNCTION, &nameFun_M_FUNCTION, &dataStep};
int conBindOffs_M_POLYMORPHIC[] = {0 , 1};
char *name_M_POLYMORPHIC =  "POLYMORPHIC" ;
char *nameFun_M_POLYMORPHIC(Term term) { return name_M_POLYMORPHIC; }
struct _ConstructionDescriptor descriptor_M_POLYMORPHIC = {&sort_M_Reified_xDeclaration, Data_M_POLYMORPHIC, 1, sizeof(STRUCT_Con_M_POLYMORPHIC), conBindOffs_M_POLYMORPHIC, &nameFun_M_POLYMORPHIC, &dataStep};
int conBindOffs_M_DATA[] = {0 , 0 , 0};
char *name_M_DATA =  "DATA" ;
char *nameFun_M_DATA(Term term) { return name_M_DATA; }
struct _ConstructionDescriptor descriptor_M_DATA = {&sort_M_Reified_xDeclaration, Data_M_DATA, 2, sizeof(STRUCT_Con_M_DATA), conBindOffs_M_DATA, &nameFun_M_DATA, &dataStep};
ConstructionDescriptor sortCon_M_Reified_xDeclaration[] = {NULL, NULL, &descriptor_M_FUNCTION, &descriptor_M_POLYMORPHIC, &descriptor_M_DATA,  NULL};
char *sortNam_M_Reified_xDeclaration[] = {NULL, NULL,  "FUNCTION" ,  "POLYMORPHIC" ,  "DATA" ,  NULL};
char *sortInt_M_Reified_xDeclaration[] = {NULL, NULL, "_M_FUNCTION", "_M_POLYMORPHIC", "_M_DATA",  NULL};
struct _SortDescriptor sort_M_Reified_xDeclaration = { "Reified_Declaration" , sortCon_M_Reified_xDeclaration, sortNam_M_Reified_xDeclaration, sortInt_M_Reified_xDeclaration, NULL};

/* SORT Reified_Form CONSTANTS. */
int conBindOffs_M_SORT_SET[] = {0 , 0 , 0 , 0};
char *name_M_SORT_SET =  "SORT-SET" ;
char *nameFun_M_SORT_SET(Term term) { return name_M_SORT_SET; }
struct _ConstructionDescriptor descriptor_M_SORT_SET = {&sort_M_Reified_xForm, Data_M_SORT_SET, 3, sizeof(STRUCT_Con_M_SORT_SET), conBindOffs_M_SORT_SET, &nameFun_M_SORT_SET, &dataStep};
char *name_M_SORT_ALLOWS_VARIABLES =  "SORT-ALLOWS-VARIABLES" ;
char *nameFun_M_SORT_ALLOWS_VARIABLES(Term term) { return name_M_SORT_ALLOWS_VARIABLES; }
struct _ConstructionDescriptor descriptor_M_SORT_ALLOWS_VARIABLES = {&sort_M_Reified_xForm, Data_M_SORT_ALLOWS_VARIABLES, 0, sizeof(STRUCT_Con_M_SORT_ALLOWS_VARIABLES), noBinderOffsets, &nameFun_M_SORT_ALLOWS_VARIABLES, &dataStep};
int conBindOffs_M_FORM[] = {0 , 0 , 0};
char *name_M_FORM =  "FORM" ;
char *nameFun_M_FORM(Term term) { return name_M_FORM; }
struct _ConstructionDescriptor descriptor_M_FORM = {&sort_M_Reified_xForm, Data_M_FORM, 2, sizeof(STRUCT_Con_M_FORM), conBindOffs_M_FORM, &nameFun_M_FORM, &dataStep};
ConstructionDescriptor sortCon_M_Reified_xForm[] = {NULL, NULL, &descriptor_M_SORT_SET, &descriptor_M_SORT_ALLOWS_VARIABLES, &descriptor_M_FORM,  NULL};
char *sortNam_M_Reified_xForm[] = {NULL, NULL,  "SORT-SET" ,  "SORT-ALLOWS-VARIABLES" ,  "FORM" ,  NULL};
char *sortInt_M_Reified_xForm[] = {NULL, NULL, "_M_SORT_SET", "_M_SORT_ALLOWS_VARIABLES", "_M_FORM",  NULL};
struct _SortDescriptor sort_M_Reified_xForm = { "Reified_Form" , sortCon_M_Reified_xForm, sortNam_M_Reified_xForm, sortInt_M_Reified_xForm, NULL};

/* SORT Reified_FormArgument CONSTANTS. */
int conBindOffs_M_FORM_BINDER[] = {0 , 0 , 1};
char *name_M_FORM_BINDER =  "FORM-BINDER" ;
char *nameFun_M_FORM_BINDER(Term term) { return name_M_FORM_BINDER; }
struct _ConstructionDescriptor descriptor_M_FORM_BINDER = {&sort_M_Reified_xFormArgument, Data_M_FORM_BINDER, 2, sizeof(STRUCT_Con_M_FORM_BINDER), conBindOffs_M_FORM_BINDER, &nameFun_M_FORM_BINDER, &dataStep};
int conBindOffs_M_FORM_ARGUMENT[] = {0 , 0};
char *name_M_FORM_ARGUMENT =  "FORM-ARGUMENT" ;
char *nameFun_M_FORM_ARGUMENT(Term term) { return name_M_FORM_ARGUMENT; }
struct _ConstructionDescriptor descriptor_M_FORM_ARGUMENT = {&sort_M_Reified_xFormArgument, Data_M_FORM_ARGUMENT, 1, sizeof(STRUCT_Con_M_FORM_ARGUMENT), conBindOffs_M_FORM_ARGUMENT, &nameFun_M_FORM_ARGUMENT, &dataStep};
ConstructionDescriptor sortCon_M_Reified_xFormArgument[] = {NULL, NULL, &descriptor_M_FORM_BINDER, &descriptor_M_FORM_ARGUMENT,  NULL};
char *sortNam_M_Reified_xFormArgument[] = {NULL, NULL,  "FORM-BINDER" ,  "FORM-ARGUMENT" ,  NULL};
char *sortInt_M_Reified_xFormArgument[] = {NULL, NULL, "_M_FORM_BINDER", "_M_FORM_ARGUMENT",  NULL};
struct _SortDescriptor sort_M_Reified_xFormArgument = { "Reified_FormArgument" , sortCon_M_Reified_xFormArgument, sortNam_M_Reified_xFormArgument, sortInt_M_Reified_xFormArgument, NULL};

/* SORT Reified_Occurrence CONSTANTS. */
int conBindOffs_M_META_USE[] = {0 , 0 , 0};
char *name_M_META_USE =  "META-USE" ;
char *nameFun_M_META_USE(Term term) { return name_M_META_USE; }
struct _ConstructionDescriptor descriptor_M_META_USE = {&sort_M_Reified_xOccurrence, Data_M_META_USE, 2, sizeof(STRUCT_Con_M_META_USE), conBindOffs_M_META_USE, &nameFun_M_META_USE, &dataStep};
char *name_M_OTHER =  "OTHER" ;
char *nameFun_M_OTHER(Term term) { return name_M_OTHER; }
struct _ConstructionDescriptor descriptor_M_OTHER = {&sort_M_Reified_xOccurrence, Data_M_OTHER, 0, sizeof(STRUCT_Con_M_OTHER), noBinderOffsets, &nameFun_M_OTHER, &dataStep};
ConstructionDescriptor sortCon_M_Reified_xOccurrence[] = {NULL, NULL, &descriptor_M_META_USE, &descriptor_M_OTHER,  NULL};
char *sortNam_M_Reified_xOccurrence[] = {NULL, NULL,  "META-USE" ,  "OTHER" ,  NULL};
char *sortInt_M_Reified_xOccurrence[] = {NULL, NULL, "_M_META_USE", "_M_OTHER",  NULL};
struct _SortDescriptor sort_M_Reified_xOccurrence = { "Reified_Occurrence" , sortCon_M_Reified_xOccurrence, sortNam_M_Reified_xOccurrence, sortInt_M_Reified_xOccurrence, NULL};

/* SORT Reified_Option CONSTANTS. */
int conBindOffs_M_OPTION[] = {0 , 0 , 0};
char *name_M_OPTION =  "OPTION" ;
char *nameFun_M_OPTION(Term term) { return name_M_OPTION; }
struct _ConstructionDescriptor descriptor_M_OPTION = {&sort_M_Reified_xOption, Data_M_OPTION, 2, sizeof(STRUCT_Con_M_OPTION), conBindOffs_M_OPTION, &nameFun_M_OPTION, &dataStep};
ConstructionDescriptor sortCon_M_Reified_xOption[] = {NULL, NULL, &descriptor_M_OPTION,  NULL};
char *sortNam_M_Reified_xOption[] = {NULL, NULL,  "OPTION" ,  NULL};
char *sortInt_M_Reified_xOption[] = {NULL, NULL, "_M_OPTION",  NULL};
struct _SortDescriptor sort_M_Reified_xOption = { "Reified_Option" , sortCon_M_Reified_xOption, sortNam_M_Reified_xOption, sortInt_M_Reified_xOption, NULL};

/* SORT Reified_Promiscuity CONSTANTS. */
char *name_M_LINEAR =  "LINEAR" ;
char *nameFun_M_LINEAR(Term term) { return name_M_LINEAR; }
struct _ConstructionDescriptor descriptor_M_LINEAR = {&sort_M_Reified_xPromiscuity, Data_M_LINEAR, 0, sizeof(STRUCT_Con_M_LINEAR), noBinderOffsets, &nameFun_M_LINEAR, &dataStep};
char *name_M_PROMISCUOUS =  "PROMISCUOUS" ;
char *nameFun_M_PROMISCUOUS(Term term) { return name_M_PROMISCUOUS; }
struct _ConstructionDescriptor descriptor_M_PROMISCUOUS = {&sort_M_Reified_xPromiscuity, Data_M_PROMISCUOUS, 0, sizeof(STRUCT_Con_M_PROMISCUOUS), noBinderOffsets, &nameFun_M_PROMISCUOUS, &dataStep};
ConstructionDescriptor sortCon_M_Reified_xPromiscuity[] = {NULL, NULL, &descriptor_M_LINEAR, &descriptor_M_PROMISCUOUS,  NULL};
char *sortNam_M_Reified_xPromiscuity[] = {NULL, NULL,  "LINEAR" ,  "PROMISCUOUS" ,  NULL};
char *sortInt_M_Reified_xPromiscuity[] = {NULL, NULL, "_M_LINEAR", "_M_PROMISCUOUS",  NULL};
struct _SortDescriptor sort_M_Reified_xPromiscuity = { "Reified_Promiscuity" , sortCon_M_Reified_xPromiscuity, sortNam_M_Reified_xPromiscuity, sortInt_M_Reified_xPromiscuity, NULL};

/* SORT Reified_Rule CONSTANTS. */
int conBindOffs_M_RULE[] = {0 , 0 , 0 , 0 , 0};
char *name_M_RULE =  "RULE" ;
char *nameFun_M_RULE(Term term) { return name_M_RULE; }
struct _ConstructionDescriptor descriptor_M_RULE = {&sort_M_Reified_xRule, Data_M_RULE, 4, sizeof(STRUCT_Con_M_RULE), conBindOffs_M_RULE, &nameFun_M_RULE, &dataStep};
ConstructionDescriptor sortCon_M_Reified_xRule[] = {NULL, NULL, &descriptor_M_RULE,  NULL};
char *sortNam_M_Reified_xRule[] = {NULL, NULL,  "RULE" ,  NULL};
char *sortInt_M_Reified_xRule[] = {NULL, NULL, "_M_RULE",  NULL};
struct _SortDescriptor sort_M_Reified_xRule = { "Reified_Rule" , sortCon_M_Reified_xRule, sortNam_M_Reified_xRule, sortInt_M_Reified_xRule, NULL};

/* SORT Reified_Sort CONSTANTS. */
int conBindOffs_M_SORT[] = {0 , 0 , 0};
char *name_M_SORT =  "SORT" ;
char *nameFun_M_SORT(Term term) { return name_M_SORT; }
struct _ConstructionDescriptor descriptor_M_SORT = {&sort_M_Reified_xSort, Data_M_SORT, 2, sizeof(STRUCT_Con_M_SORT), conBindOffs_M_SORT, &nameFun_M_SORT, &dataStep};
int conBindOffs_M_SORT_VARIABLE[] = {0 , 0};
char *name_M_SORT_VARIABLE =  "SORT-VARIABLE" ;
char *nameFun_M_SORT_VARIABLE(Term term) { return name_M_SORT_VARIABLE; }
struct _ConstructionDescriptor descriptor_M_SORT_VARIABLE = {&sort_M_Reified_xSort, Data_M_SORT_VARIABLE, 1, sizeof(STRUCT_Con_M_SORT_VARIABLE), conBindOffs_M_SORT_VARIABLE, &nameFun_M_SORT_VARIABLE, &dataStep};
int conBindOffs_M_SORT_PROPERTY[] = {0 , 0 , 0 , 0};
char *name_M_SORT_PROPERTY =  "SORT-PROPERTY" ;
char *nameFun_M_SORT_PROPERTY(Term term) { return name_M_SORT_PROPERTY; }
struct _ConstructionDescriptor descriptor_M_SORT_PROPERTY = {&sort_M_Reified_xSort, Data_M_SORT_PROPERTY, 3, sizeof(STRUCT_Con_M_SORT_PROPERTY), conBindOffs_M_SORT_PROPERTY, &nameFun_M_SORT_PROPERTY, &dataStep};
ConstructionDescriptor sortCon_M_Reified_xSort[] = {NULL, NULL, &descriptor_M_SORT, &descriptor_M_SORT_VARIABLE, &descriptor_M_SORT_PROPERTY,  NULL};
char *sortNam_M_Reified_xSort[] = {NULL, NULL,  "SORT" ,  "SORT-VARIABLE" ,  "SORT-PROPERTY" ,  NULL};
char *sortInt_M_Reified_xSort[] = {NULL, NULL, "_M_SORT", "_M_SORT_VARIABLE", "_M_SORT_PROPERTY",  NULL};
struct _SortDescriptor sort_M_Reified_xSort = { "Reified_Sort" , sortCon_M_Reified_xSort, sortNam_M_Reified_xSort, sortInt_M_Reified_xSort, NULL};

/* SORT Reified_Term CONSTANTS. */
int conBindOffs_M_META_APPLICATION[] = {0 , 0 , 0 , 0};
char *name_M_META_APPLICATION =  "META-APPLICATION" ;
char *nameFun_M_META_APPLICATION(Term term) { return name_M_META_APPLICATION; }
struct _ConstructionDescriptor descriptor_M_META_APPLICATION = {&sort_M_Reified_xTerm, Data_M_META_APPLICATION, 3, sizeof(STRUCT_Con_M_META_APPLICATION), conBindOffs_M_META_APPLICATION, &nameFun_M_META_APPLICATION, &dataStep};
int conBindOffs_M_EVALUATOR[] = {0 , 0 , 0 , 0};
char *name_M_EVALUATOR =  "EVALUATOR" ;
char *nameFun_M_EVALUATOR(Term term) { return name_M_EVALUATOR; }
struct _ConstructionDescriptor descriptor_M_EVALUATOR = {&sort_M_Reified_xTerm, Data_M_EVALUATOR, 3, sizeof(STRUCT_Con_M_EVALUATOR), conBindOffs_M_EVALUATOR, &nameFun_M_EVALUATOR, &dataStep};
int conBindOffs_M_FreshReuseOrigin[] = {0 , 0 , 0 , 0};
char *name_M_FreshReuseOrigin =  "FreshReuseOrigin" ;
char *nameFun_M_FreshReuseOrigin(Term term) { return name_M_FreshReuseOrigin; }
struct _ConstructionDescriptor descriptor_M_FreshReuseOrigin = {&sort_M_Reified_xTerm, Data_M_FreshReuseOrigin, 3, sizeof(STRUCT_Con_M_FreshReuseOrigin), conBindOffs_M_FreshReuseOrigin, &nameFun_M_FreshReuseOrigin, &dataStep};
int conBindOffs_M_PROPERTY_REF[] = {0 , 0 , 0};
char *name_M_PROPERTY_REF =  "PROPERTY-REF" ;
char *nameFun_M_PROPERTY_REF(Term term) { return name_M_PROPERTY_REF; }
struct _ConstructionDescriptor descriptor_M_PROPERTY_REF = {&sort_M_Reified_xTerm, Data_M_PROPERTY_REF, 2, sizeof(STRUCT_Con_M_PROPERTY_REF), conBindOffs_M_PROPERTY_REF, &nameFun_M_PROPERTY_REF, &dataStep};
int conBindOffs_M_PROPERTY[] = {0 , 0 , 0 , 0};
char *name_M_PROPERTY =  "PROPERTY" ;
char *nameFun_M_PROPERTY(Term term) { return name_M_PROPERTY; }
struct _ConstructionDescriptor descriptor_M_PROPERTY = {&sort_M_Reified_xTerm, Data_M_PROPERTY, 3, sizeof(STRUCT_Con_M_PROPERTY), conBindOffs_M_PROPERTY, &nameFun_M_PROPERTY, &dataStep};
int conBindOffs_M_PROPERTY_NOT[] = {0 , 0 , 0};
char *name_M_PROPERTY_NOT =  "PROPERTY-NOT" ;
char *nameFun_M_PROPERTY_NOT(Term term) { return name_M_PROPERTY_NOT; }
struct _ConstructionDescriptor descriptor_M_PROPERTY_NOT = {&sort_M_Reified_xTerm, Data_M_PROPERTY_NOT, 2, sizeof(STRUCT_Con_M_PROPERTY_NOT), conBindOffs_M_PROPERTY_NOT, &nameFun_M_PROPERTY_NOT, &dataStep};
int conBindOffs_M_CONSTRUCTION[] = {0 , 0 , 0};
char *name_M_CONSTRUCTION =  "CONSTRUCTION" ;
char *nameFun_M_CONSTRUCTION(Term term) { return name_M_CONSTRUCTION; }
struct _ConstructionDescriptor descriptor_M_CONSTRUCTION = {&sort_M_Reified_xTerm, Data_M_CONSTRUCTION, 2, sizeof(STRUCT_Con_M_CONSTRUCTION), conBindOffs_M_CONSTRUCTION, &nameFun_M_CONSTRUCTION, &dataStep};
int conBindOffs_M_LITERAL[] = {0 , 0 , 0};
char *name_M_LITERAL =  "LITERAL" ;
char *nameFun_M_LITERAL(Term term) { return name_M_LITERAL; }
struct _ConstructionDescriptor descriptor_M_LITERAL = {&sort_M_Reified_xTerm, Data_M_LITERAL, 2, sizeof(STRUCT_Con_M_LITERAL), conBindOffs_M_LITERAL, &nameFun_M_LITERAL, &dataStep};
int conBindOffs_M_VARIABLE_USE[] = {0 , 0};
char *name_M_VARIABLE_USE =  "VARIABLE-USE" ;
char *nameFun_M_VARIABLE_USE(Term term) { return name_M_VARIABLE_USE; }
struct _ConstructionDescriptor descriptor_M_VARIABLE_USE = {&sort_M_Reified_xTerm, Data_M_VARIABLE_USE, 1, sizeof(STRUCT_Con_M_VARIABLE_USE), conBindOffs_M_VARIABLE_USE, &nameFun_M_VARIABLE_USE, &dataStep};
ConstructionDescriptor sortCon_M_Reified_xTerm[] = {NULL, NULL, &descriptor_M_META_APPLICATION, &descriptor_M_EVALUATOR, &descriptor_M_FreshReuseOrigin, &descriptor_M_PROPERTY_REF, &descriptor_M_PROPERTY, &descriptor_M_PROPERTY_NOT, &descriptor_M_CONSTRUCTION, &descriptor_M_LITERAL, &descriptor_M_VARIABLE_USE,  NULL};
char *sortNam_M_Reified_xTerm[] = {NULL, NULL,  "META-APPLICATION" ,  "EVALUATOR" ,  "FreshReuseOrigin" ,  "PROPERTY-REF" ,  "PROPERTY" ,  "PROPERTY-NOT" ,  "CONSTRUCTION" ,  "LITERAL" ,  "VARIABLE-USE" ,  NULL};
char *sortInt_M_Reified_xTerm[] = {NULL, NULL, "_M_META_APPLICATION", "_M_EVALUATOR", "_M_FreshReuseOrigin", "_M_PROPERTY_REF", "_M_PROPERTY", "_M_PROPERTY_NOT", "_M_CONSTRUCTION", "_M_LITERAL", "_M_VARIABLE_USE",  NULL};
struct _SortDescriptor sort_M_Reified_xTerm = { "Reified_Term" , sortCon_M_Reified_xTerm, sortNam_M_Reified_xTerm, sortInt_M_Reified_xTerm, NULL};

/* SORT Reified_Use CONSTANTS. */
char *name_M_DISCARD =  "DISCARD" ;
char *nameFun_M_DISCARD(Term term) { return name_M_DISCARD; }
struct _ConstructionDescriptor descriptor_M_DISCARD = {&sort_M_Reified_xUse, Data_M_DISCARD, 0, sizeof(STRUCT_Con_M_DISCARD), noBinderOffsets, &nameFun_M_DISCARD, &dataStep};
int conBindOffs_M_USE[] = {0 , 0};
char *name_M_USE =  "USE" ;
char *nameFun_M_USE(Term term) { return name_M_USE; }
struct _ConstructionDescriptor descriptor_M_USE = {&sort_M_Reified_xUse, Data_M_USE, 1, sizeof(STRUCT_Con_M_USE), conBindOffs_M_USE, &nameFun_M_USE, &dataStep};
char *name_M_NA =  "NA" ;
char *nameFun_M_NA(Term term) { return name_M_NA; }
struct _ConstructionDescriptor descriptor_M_NA = {&sort_M_Reified_xUse, Data_M_NA, 0, sizeof(STRUCT_Con_M_NA), noBinderOffsets, &nameFun_M_NA, &dataStep};
char *name_M_LINK =  "LINK" ;
char *nameFun_M_LINK(Term term) { return name_M_LINK; }
struct _ConstructionDescriptor descriptor_M_LINK = {&sort_M_Reified_xUse, Data_M_LINK, 0, sizeof(STRUCT_Con_M_LINK), noBinderOffsets, &nameFun_M_LINK, &dataStep};
char *name_M_NOLINK =  "NOLINK" ;
char *nameFun_M_NOLINK(Term term) { return name_M_NOLINK; }
struct _ConstructionDescriptor descriptor_M_NOLINK = {&sort_M_Reified_xUse, Data_M_NOLINK, 0, sizeof(STRUCT_Con_M_NOLINK), noBinderOffsets, &nameFun_M_NOLINK, &dataStep};
ConstructionDescriptor sortCon_M_Reified_xUse[] = {NULL, NULL, &descriptor_M_DISCARD, &descriptor_M_USE, &descriptor_M_NA, &descriptor_M_LINK, &descriptor_M_NOLINK,  NULL};
char *sortNam_M_Reified_xUse[] = {NULL, NULL,  "DISCARD" ,  "USE" ,  "NA" ,  "LINK" ,  "NOLINK" ,  NULL};
char *sortInt_M_Reified_xUse[] = {NULL, NULL, "_M_DISCARD", "_M_USE", "_M_NA", "_M_LINK", "_M_NOLINK",  NULL};
struct _SortDescriptor sort_M_Reified_xUse = { "Reified_Use" , sortCon_M_Reified_xUse, sortNam_M_Reified_xUse, sortInt_M_Reified_xUse, NULL};

/* SORT Reified_Variable CONSTANTS. */
char *name_M__sTextNil =  "$TextNil" ;
char *nameFun_M__sTextNil(Term term) { return name_M__sTextNil; }
struct _ConstructionDescriptor descriptor_M__sTextNil = {&sort_M_Reified_xVariable, Data_M__sTextNil, 0, sizeof(STRUCT_Con_M__sTextNil), noBinderOffsets, &nameFun_M__sTextNil, &dataStep};
int conBindOffs_M__sTextCons[] = {0 , 0 , 0};
char *name_M__sTextCons =  "$TextCons" ;
char *nameFun_M__sTextCons(Term term) { return name_M__sTextCons; }
struct _ConstructionDescriptor descriptor_M__sTextCons = {&sort_M_Reified_xVariable, Data_M__sTextCons, 2, sizeof(STRUCT_Con_M__sTextCons), conBindOffs_M__sTextCons, &nameFun_M__sTextCons, &dataStep};
ConstructionDescriptor sortCon_M_Reified_xVariable[] = {NULL, NULL, &descriptor_M__sTextNil, &descriptor_M__sTextCons,  NULL};
char *sortNam_M_Reified_xVariable[] = {NULL, NULL,  "$TextNil" ,  "$TextCons" ,  NULL};
char *sortInt_M_Reified_xVariable[] = {NULL, NULL, "_M__sTextNil", "_M__sTextCons",  NULL};
struct _SortDescriptor sort_M_Reified_xVariable = { "Reified_Variable" , sortCon_M_Reified_xVariable, sortNam_M_Reified_xVariable, sortInt_M_Reified_xVariable, NULL};

/* SORT Reify_CRSX CONSTANTS. */
int conBindOffs_M_CRSX[] = {0 , 0 , 0};
char *name_M_CRSX =  "CRSX" ;
char *nameFun_M_CRSX(Term term) { return name_M_CRSX; }
struct _ConstructionDescriptor descriptor_M_CRSX = {&sort_M_Reify_xCRSX, Data_M_CRSX, 2, sizeof(STRUCT_Con_M_CRSX), conBindOffs_M_CRSX, &nameFun_M_CRSX, &dataStep};
ConstructionDescriptor sortCon_M_Reify_xCRSX[] = {NULL, NULL, &descriptor_M_CRSX,  NULL};
char *sortNam_M_Reify_xCRSX[] = {NULL, NULL,  "CRSX" ,  NULL};
char *sortInt_M_Reify_xCRSX[] = {NULL, NULL, "_M_CRSX",  NULL};
struct _SortDescriptor sort_M_Reify_xCRSX = { "Reify_CRSX" , sortCon_M_Reify_xCRSX, sortNam_M_Reify_xCRSX, sortInt_M_Reify_xCRSX, NULL};

/* SORT SPrimitive CONSTANTS. */
char *name_M_E_xNull =  "E_Null" ;
char *nameFun_M_E_xNull(Term term) { return name_M_E_xNull; }
struct _ConstructionDescriptor descriptor_M_E_xNull = {&sort_M_SPrimitive, Data_M_E_xNull, 0, sizeof(STRUCT_Con_M_E_xNull), noBinderOffsets, &nameFun_M_E_xNull, &dataStep};
char *name_M_E_xNil =  "E_Nil" ;
char *nameFun_M_E_xNil(Term term) { return name_M_E_xNil; }
struct _ConstructionDescriptor descriptor_M_E_xNil = {&sort_M_SPrimitive, Data_M_E_xNil, 0, sizeof(STRUCT_Con_M_E_xNil), noBinderOffsets, &nameFun_M_E_xNil, &dataStep};
char *name_M_E_xForgivableError =  "E_ForgivableError" ;
char *nameFun_M_E_xForgivableError(Term term) { return name_M_E_xForgivableError; }
struct _ConstructionDescriptor descriptor_M_E_xForgivableError = {&sort_M_SPrimitive, Data_M_E_xForgivableError, 0, sizeof(STRUCT_Con_M_E_xForgivableError), noBinderOffsets, &nameFun_M_E_xForgivableError, &dataStep};
char *name_M_E_xStringLessThan =  "E_StringLessThan" ;
char *nameFun_M_E_xStringLessThan(Term term) { return name_M_E_xStringLessThan; }
struct _ConstructionDescriptor descriptor_M_E_xStringLessThan = {&sort_M_SPrimitive, Data_M_E_xStringLessThan, 0, sizeof(STRUCT_Con_M_E_xStringLessThan), noBinderOffsets, &nameFun_M_E_xStringLessThan, &dataStep};
char *name_M_E_xFromFirst =  "E_FromFirst" ;
char *nameFun_M_E_xFromFirst(Term term) { return name_M_E_xFromFirst; }
struct _ConstructionDescriptor descriptor_M_E_xFromFirst = {&sort_M_SPrimitive, Data_M_E_xFromFirst, 0, sizeof(STRUCT_Con_M_E_xFromFirst), noBinderOffsets, &nameFun_M_E_xFromFirst, &dataStep};
char *name_M_E_xToFirst =  "E_ToFirst" ;
char *nameFun_M_E_xToFirst(Term term) { return name_M_E_xToFirst; }
struct _ConstructionDescriptor descriptor_M_E_xToFirst = {&sort_M_SPrimitive, Data_M_E_xToFirst, 0, sizeof(STRUCT_Con_M_E_xToFirst), noBinderOffsets, &nameFun_M_E_xToFirst, &dataStep};
char *name_M_E_xVariableNameIs =  "E_VariableNameIs" ;
char *nameFun_M_E_xVariableNameIs(Term term) { return name_M_E_xVariableNameIs; }
struct _ConstructionDescriptor descriptor_M_E_xVariableNameIs = {&sort_M_SPrimitive, Data_M_E_xVariableNameIs, 0, sizeof(STRUCT_Con_M_E_xVariableNameIs), noBinderOffsets, &nameFun_M_E_xVariableNameIs, &dataStep};
char *name_M_E_xSplit =  "E_Split" ;
char *nameFun_M_E_xSplit(Term term) { return name_M_E_xSplit; }
struct _ConstructionDescriptor descriptor_M_E_xSplit = {&sort_M_SPrimitive, Data_M_E_xSplit, 0, sizeof(STRUCT_Con_M_E_xSplit), noBinderOffsets, &nameFun_M_E_xSplit, &dataStep};
char *name_M_E_xRescape =  "E_Rescape" ;
char *nameFun_M_E_xRescape(Term term) { return name_M_E_xRescape; }
struct _ConstructionDescriptor descriptor_M_E_xRescape = {&sort_M_SPrimitive, Data_M_E_xRescape, 0, sizeof(STRUCT_Con_M_E_xRescape), noBinderOffsets, &nameFun_M_E_xRescape, &dataStep};
char *name_M_E_xUpCase =  "E_UpCase" ;
char *nameFun_M_E_xUpCase(Term term) { return name_M_E_xUpCase; }
struct _ConstructionDescriptor descriptor_M_E_xUpCase = {&sort_M_SPrimitive, Data_M_E_xUpCase, 0, sizeof(STRUCT_Con_M_E_xUpCase), noBinderOffsets, &nameFun_M_E_xUpCase, &dataStep};
char *name_M_E_xDownCase =  "E_DownCase" ;
char *nameFun_M_E_xDownCase(Term term) { return name_M_E_xDownCase; }
struct _ConstructionDescriptor descriptor_M_E_xDownCase = {&sort_M_SPrimitive, Data_M_E_xDownCase, 0, sizeof(STRUCT_Con_M_E_xDownCase), noBinderOffsets, &nameFun_M_E_xDownCase, &dataStep};
char *name_M_E_xReplace =  "E_Replace" ;
char *nameFun_M_E_xReplace(Term term) { return name_M_E_xReplace; }
struct _ConstructionDescriptor descriptor_M_E_xReplace = {&sort_M_SPrimitive, Data_M_E_xReplace, 0, sizeof(STRUCT_Con_M_E_xReplace), noBinderOffsets, &nameFun_M_E_xReplace, &dataStep};
char *name_M_E_xTrim =  "E_Trim" ;
char *nameFun_M_E_xTrim(Term term) { return name_M_E_xTrim; }
struct _ConstructionDescriptor descriptor_M_E_xTrim = {&sort_M_SPrimitive, Data_M_E_xTrim, 0, sizeof(STRUCT_Con_M_E_xTrim), noBinderOffsets, &nameFun_M_E_xTrim, &dataStep};
char *name_M_E_xKeys =  "E_Keys" ;
char *nameFun_M_E_xKeys(Term term) { return name_M_E_xKeys; }
struct _ConstructionDescriptor descriptor_M_E_xKeys = {&sort_M_SPrimitive, Data_M_E_xKeys, 0, sizeof(STRUCT_Con_M_E_xKeys), noBinderOffsets, &nameFun_M_E_xKeys, &dataStep};
char *name_M_E_xParseURL =  "E_ParseURL" ;
char *nameFun_M_E_xParseURL(Term term) { return name_M_E_xParseURL; }
struct _ConstructionDescriptor descriptor_M_E_xParseURL = {&sort_M_SPrimitive, Data_M_E_xParseURL, 0, sizeof(STRUCT_Con_M_E_xParseURL), noBinderOffsets, &nameFun_M_E_xParseURL, &dataStep};
char *name_M_E_xEcho =  "E_Echo" ;
char *nameFun_M_E_xEcho(Term term) { return name_M_E_xEcho; }
struct _ConstructionDescriptor descriptor_M_E_xEcho = {&sort_M_SPrimitive, Data_M_E_xEcho, 0, sizeof(STRUCT_Con_M_E_xEcho), noBinderOffsets, &nameFun_M_E_xEcho, &dataStep};
char *name_M_E_xDeepEqual =  "E_DeepEqual" ;
char *nameFun_M_E_xDeepEqual(Term term) { return name_M_E_xDeepEqual; }
struct _ConstructionDescriptor descriptor_M_E_xDeepEqual = {&sort_M_SPrimitive, Data_M_E_xDeepEqual, 0, sizeof(STRUCT_Con_M_E_xDeepEqual), noBinderOffsets, &nameFun_M_E_xDeepEqual, &dataStep};
char *name_M_E_xHashCode =  "E_HashCode" ;
char *nameFun_M_E_xHashCode(Term term) { return name_M_E_xHashCode; }
struct _ConstructionDescriptor descriptor_M_E_xHashCode = {&sort_M_SPrimitive, Data_M_E_xHashCode, 0, sizeof(STRUCT_Con_M_E_xHashCode), noBinderOffsets, &nameFun_M_E_xHashCode, &dataStep};
char *name_M_E_xConcat =  "E_Concat" ;
char *nameFun_M_E_xConcat(Term term) { return name_M_E_xConcat; }
struct _ConstructionDescriptor descriptor_M_E_xConcat = {&sort_M_SPrimitive, Data_M_E_xConcat, 0, sizeof(STRUCT_Con_M_E_xConcat), noBinderOffsets, &nameFun_M_E_xConcat, &dataStep};
char *name_M_E_xC =  "E_C" ;
char *nameFun_M_E_xC(Term term) { return name_M_E_xC; }
struct _ConstructionDescriptor descriptor_M_E_xC = {&sort_M_SPrimitive, Data_M_E_xC, 0, sizeof(STRUCT_Con_M_E_xC), noBinderOffsets, &nameFun_M_E_xC, &dataStep};
char *name_M_E_xEqual =  "E_Equal" ;
char *nameFun_M_E_xEqual(Term term) { return name_M_E_xEqual; }
struct _ConstructionDescriptor descriptor_M_E_xEqual = {&sort_M_SPrimitive, Data_M_E_xEqual, 0, sizeof(STRUCT_Con_M_E_xEqual), noBinderOffsets, &nameFun_M_E_xEqual, &dataStep};
char *name_M_E_xNotEqual =  "E_NotEqual" ;
char *nameFun_M_E_xNotEqual(Term term) { return name_M_E_xNotEqual; }
struct _ConstructionDescriptor descriptor_M_E_xNotEqual = {&sort_M_SPrimitive, Data_M_E_xNotEqual, 0, sizeof(STRUCT_Con_M_E_xNotEqual), noBinderOffsets, &nameFun_M_E_xNotEqual, &dataStep};
char *name_M_E_xLessThan =  "E_LessThan" ;
char *nameFun_M_E_xLessThan(Term term) { return name_M_E_xLessThan; }
struct _ConstructionDescriptor descriptor_M_E_xLessThan = {&sort_M_SPrimitive, Data_M_E_xLessThan, 0, sizeof(STRUCT_Con_M_E_xLessThan), noBinderOffsets, &nameFun_M_E_xLessThan, &dataStep};
char *name_M_E_xGreaterThan =  "E_GreaterThan" ;
char *nameFun_M_E_xGreaterThan(Term term) { return name_M_E_xGreaterThan; }
struct _ConstructionDescriptor descriptor_M_E_xGreaterThan = {&sort_M_SPrimitive, Data_M_E_xGreaterThan, 0, sizeof(STRUCT_Con_M_E_xGreaterThan), noBinderOffsets, &nameFun_M_E_xGreaterThan, &dataStep};
char *name_M_E_xLessThanOrEqual =  "E_LessThanOrEqual" ;
char *nameFun_M_E_xLessThanOrEqual(Term term) { return name_M_E_xLessThanOrEqual; }
struct _ConstructionDescriptor descriptor_M_E_xLessThanOrEqual = {&sort_M_SPrimitive, Data_M_E_xLessThanOrEqual, 0, sizeof(STRUCT_Con_M_E_xLessThanOrEqual), noBinderOffsets, &nameFun_M_E_xLessThanOrEqual, &dataStep};
char *name_M_E_xSameVariable =  "E_SameVariable" ;
char *nameFun_M_E_xSameVariable(Term term) { return name_M_E_xSameVariable; }
struct _ConstructionDescriptor descriptor_M_E_xSameVariable = {&sort_M_SPrimitive, Data_M_E_xSameVariable, 0, sizeof(STRUCT_Con_M_E_xSameVariable), noBinderOffsets, &nameFun_M_E_xSameVariable, &dataStep};
char *name_M_E_xLesserVariable =  "E_LesserVariable" ;
char *nameFun_M_E_xLesserVariable(Term term) { return name_M_E_xLesserVariable; }
struct _ConstructionDescriptor descriptor_M_E_xLesserVariable = {&sort_M_SPrimitive, Data_M_E_xLesserVariable, 0, sizeof(STRUCT_Con_M_E_xLesserVariable), noBinderOffsets, &nameFun_M_E_xLesserVariable, &dataStep};
char *name_M_E_xGreaterThanOrEqual =  "E_GreaterThanOrEqual" ;
char *nameFun_M_E_xGreaterThanOrEqual(Term term) { return name_M_E_xGreaterThanOrEqual; }
struct _ConstructionDescriptor descriptor_M_E_xGreaterThanOrEqual = {&sort_M_SPrimitive, Data_M_E_xGreaterThanOrEqual, 0, sizeof(STRUCT_Con_M_E_xGreaterThanOrEqual), noBinderOffsets, &nameFun_M_E_xGreaterThanOrEqual, &dataStep};
char *name_M_E_xIf =  "E_If" ;
char *nameFun_M_E_xIf(Term term) { return name_M_E_xIf; }
struct _ConstructionDescriptor descriptor_M_E_xIf = {&sort_M_SPrimitive, Data_M_E_xIf, 0, sizeof(STRUCT_Con_M_E_xIf), noBinderOffsets, &nameFun_M_E_xIf, &dataStep};
char *name_M_E_xIfZero =  "E_IfZero" ;
char *nameFun_M_E_xIfZero(Term term) { return name_M_E_xIfZero; }
struct _ConstructionDescriptor descriptor_M_E_xIfZero = {&sort_M_SPrimitive, Data_M_E_xIfZero, 0, sizeof(STRUCT_Con_M_E_xIfZero), noBinderOffsets, &nameFun_M_E_xIfZero, &dataStep};
char *name_M_E_xIfEmpty =  "E_IfEmpty" ;
char *nameFun_M_E_xIfEmpty(Term term) { return name_M_E_xIfEmpty; }
struct _ConstructionDescriptor descriptor_M_E_xIfEmpty = {&sort_M_SPrimitive, Data_M_E_xIfEmpty, 0, sizeof(STRUCT_Con_M_E_xIfEmpty), noBinderOffsets, &nameFun_M_E_xIfEmpty, &dataStep};
char *name_M_E_xSquash =  "E_Squash" ;
char *nameFun_M_E_xSquash(Term term) { return name_M_E_xSquash; }
struct _ConstructionDescriptor descriptor_M_E_xSquash = {&sort_M_SPrimitive, Data_M_E_xSquash, 0, sizeof(STRUCT_Con_M_E_xSquash), noBinderOffsets, &nameFun_M_E_xSquash, &dataStep};
char *name_M_E_xContains =  "E_Contains" ;
char *nameFun_M_E_xContains(Term term) { return name_M_E_xContains; }
struct _ConstructionDescriptor descriptor_M_E_xContains = {&sort_M_SPrimitive, Data_M_E_xContains, 0, sizeof(STRUCT_Con_M_E_xContains), noBinderOffsets, &nameFun_M_E_xContains, &dataStep};
char *name_M_E_xStartsWith =  "E_StartsWith" ;
char *nameFun_M_E_xStartsWith(Term term) { return name_M_E_xStartsWith; }
struct _ConstructionDescriptor descriptor_M_E_xStartsWith = {&sort_M_SPrimitive, Data_M_E_xStartsWith, 0, sizeof(STRUCT_Con_M_E_xStartsWith), noBinderOffsets, &nameFun_M_E_xStartsWith, &dataStep};
char *name_M_E_xEndsWith =  "E_EndsWith" ;
char *nameFun_M_E_xEndsWith(Term term) { return name_M_E_xEndsWith; }
struct _ConstructionDescriptor descriptor_M_E_xEndsWith = {&sort_M_SPrimitive, Data_M_E_xEndsWith, 0, sizeof(STRUCT_Con_M_E_xEndsWith), noBinderOffsets, &nameFun_M_E_xEndsWith, &dataStep};
char *name_M_E_xMatchRegex =  "E_MatchRegex" ;
char *nameFun_M_E_xMatchRegex(Term term) { return name_M_E_xMatchRegex; }
struct _ConstructionDescriptor descriptor_M_E_xMatchRegex = {&sort_M_SPrimitive, Data_M_E_xMatchRegex, 0, sizeof(STRUCT_Con_M_E_xMatchRegex), noBinderOffsets, &nameFun_M_E_xMatchRegex, &dataStep};
char *name_M_E_xLength =  "E_Length" ;
char *nameFun_M_E_xLength(Term term) { return name_M_E_xLength; }
struct _ConstructionDescriptor descriptor_M_E_xLength = {&sort_M_SPrimitive, Data_M_E_xLength, 0, sizeof(STRUCT_Con_M_E_xLength), noBinderOffsets, &nameFun_M_E_xLength, &dataStep};
char *name_M_E_xSubstring =  "E_Substring" ;
char *nameFun_M_E_xSubstring(Term term) { return name_M_E_xSubstring; }
struct _ConstructionDescriptor descriptor_M_E_xSubstring = {&sort_M_SPrimitive, Data_M_E_xSubstring, 0, sizeof(STRUCT_Con_M_E_xSubstring), noBinderOffsets, &nameFun_M_E_xSubstring, &dataStep};
char *name_M_E_xEscape =  "E_Escape" ;
char *nameFun_M_E_xEscape(Term term) { return name_M_E_xEscape; }
struct _ConstructionDescriptor descriptor_M_E_xEscape = {&sort_M_SPrimitive, Data_M_E_xEscape, 0, sizeof(STRUCT_Con_M_E_xEscape), noBinderOffsets, &nameFun_M_E_xEscape, &dataStep};
char *name_M_E_xMangle =  "E_Mangle" ;
char *nameFun_M_E_xMangle(Term term) { return name_M_E_xMangle; }
struct _ConstructionDescriptor descriptor_M_E_xMangle = {&sort_M_SPrimitive, Data_M_E_xMangle, 0, sizeof(STRUCT_Con_M_E_xMangle), noBinderOffsets, &nameFun_M_E_xMangle, &dataStep};
char *name_M_E_xBeforeFirst =  "E_BeforeFirst" ;
char *nameFun_M_E_xBeforeFirst(Term term) { return name_M_E_xBeforeFirst; }
struct _ConstructionDescriptor descriptor_M_E_xBeforeFirst = {&sort_M_SPrimitive, Data_M_E_xBeforeFirst, 0, sizeof(STRUCT_Con_M_E_xBeforeFirst), noBinderOffsets, &nameFun_M_E_xBeforeFirst, &dataStep};
char *name_M_E_xAfterFirst =  "E_AfterFirst" ;
char *nameFun_M_E_xAfterFirst(Term term) { return name_M_E_xAfterFirst; }
struct _ConstructionDescriptor descriptor_M_E_xAfterFirst = {&sort_M_SPrimitive, Data_M_E_xAfterFirst, 0, sizeof(STRUCT_Con_M_E_xAfterFirst), noBinderOffsets, &nameFun_M_E_xAfterFirst, &dataStep};
char *name_M_E_xPlus =  "E_Plus" ;
char *nameFun_M_E_xPlus(Term term) { return name_M_E_xPlus; }
struct _ConstructionDescriptor descriptor_M_E_xPlus = {&sort_M_SPrimitive, Data_M_E_xPlus, 0, sizeof(STRUCT_Con_M_E_xPlus), noBinderOffsets, &nameFun_M_E_xPlus, &dataStep};
char *name_M_E_xMinus =  "E_Minus" ;
char *nameFun_M_E_xMinus(Term term) { return name_M_E_xMinus; }
struct _ConstructionDescriptor descriptor_M_E_xMinus = {&sort_M_SPrimitive, Data_M_E_xMinus, 0, sizeof(STRUCT_Con_M_E_xMinus), noBinderOffsets, &nameFun_M_E_xMinus, &dataStep};
char *name_M_E_xTimes =  "E_Times" ;
char *nameFun_M_E_xTimes(Term term) { return name_M_E_xTimes; }
struct _ConstructionDescriptor descriptor_M_E_xTimes = {&sort_M_SPrimitive, Data_M_E_xTimes, 0, sizeof(STRUCT_Con_M_E_xTimes), noBinderOffsets, &nameFun_M_E_xTimes, &dataStep};
char *name_M_E_xAbsolute =  "E_Absolute" ;
char *nameFun_M_E_xAbsolute(Term term) { return name_M_E_xAbsolute; }
struct _ConstructionDescriptor descriptor_M_E_xAbsolute = {&sort_M_SPrimitive, Data_M_E_xAbsolute, 0, sizeof(STRUCT_Con_M_E_xAbsolute), noBinderOffsets, &nameFun_M_E_xAbsolute, &dataStep};
char *name_M_E_xDecimal =  "E_Decimal" ;
char *nameFun_M_E_xDecimal(Term term) { return name_M_E_xDecimal; }
struct _ConstructionDescriptor descriptor_M_E_xDecimal = {&sort_M_SPrimitive, Data_M_E_xDecimal, 0, sizeof(STRUCT_Con_M_E_xDecimal), noBinderOffsets, &nameFun_M_E_xDecimal, &dataStep};
char *name_M_E_xDiv =  "E_Div" ;
char *nameFun_M_E_xDiv(Term term) { return name_M_E_xDiv; }
struct _ConstructionDescriptor descriptor_M_E_xDiv = {&sort_M_SPrimitive, Data_M_E_xDiv, 0, sizeof(STRUCT_Con_M_E_xDiv), noBinderOffsets, &nameFun_M_E_xDiv, &dataStep};
char *name_M_E_xMod =  "E_Mod" ;
char *nameFun_M_E_xMod(Term term) { return name_M_E_xMod; }
struct _ConstructionDescriptor descriptor_M_E_xMod = {&sort_M_SPrimitive, Data_M_E_xMod, 0, sizeof(STRUCT_Con_M_E_xMod), noBinderOffsets, &nameFun_M_E_xMod, &dataStep};
char *name_M_E_xHex =  "E_Hex" ;
char *nameFun_M_E_xHex(Term term) { return name_M_E_xHex; }
struct _ConstructionDescriptor descriptor_M_E_xHex = {&sort_M_SPrimitive, Data_M_E_xHex, 0, sizeof(STRUCT_Con_M_E_xHex), noBinderOffsets, &nameFun_M_E_xHex, &dataStep};
char *name_M_E_xBitAnd =  "E_BitAnd" ;
char *nameFun_M_E_xBitAnd(Term term) { return name_M_E_xBitAnd; }
struct _ConstructionDescriptor descriptor_M_E_xBitAnd = {&sort_M_SPrimitive, Data_M_E_xBitAnd, 0, sizeof(STRUCT_Con_M_E_xBitAnd), noBinderOffsets, &nameFun_M_E_xBitAnd, &dataStep};
char *name_M_E_xBitOr =  "E_BitOr" ;
char *nameFun_M_E_xBitOr(Term term) { return name_M_E_xBitOr; }
struct _ConstructionDescriptor descriptor_M_E_xBitOr = {&sort_M_SPrimitive, Data_M_E_xBitOr, 0, sizeof(STRUCT_Con_M_E_xBitOr), noBinderOffsets, &nameFun_M_E_xBitOr, &dataStep};
char *name_M_E_xBitXOr =  "E_BitXOr" ;
char *nameFun_M_E_xBitXOr(Term term) { return name_M_E_xBitXOr; }
struct _ConstructionDescriptor descriptor_M_E_xBitXOr = {&sort_M_SPrimitive, Data_M_E_xBitXOr, 0, sizeof(STRUCT_Con_M_E_xBitXOr), noBinderOffsets, &nameFun_M_E_xBitXOr, &dataStep};
char *name_M_E_xBitNot =  "E_BitNot" ;
char *nameFun_M_E_xBitNot(Term term) { return name_M_E_xBitNot; }
struct _ConstructionDescriptor descriptor_M_E_xBitNot = {&sort_M_SPrimitive, Data_M_E_xBitNot, 0, sizeof(STRUCT_Con_M_E_xBitNot), noBinderOffsets, &nameFun_M_E_xBitNot, &dataStep};
char *name_M_E_xBitMinus =  "E_BitMinus" ;
char *nameFun_M_E_xBitMinus(Term term) { return name_M_E_xBitMinus; }
struct _ConstructionDescriptor descriptor_M_E_xBitMinus = {&sort_M_SPrimitive, Data_M_E_xBitMinus, 0, sizeof(STRUCT_Con_M_E_xBitMinus), noBinderOffsets, &nameFun_M_E_xBitMinus, &dataStep};
char *name_M_E_xBitSubSetEq =  "E_BitSubSetEq" ;
char *nameFun_M_E_xBitSubSetEq(Term term) { return name_M_E_xBitSubSetEq; }
struct _ConstructionDescriptor descriptor_M_E_xBitSubSetEq = {&sort_M_SPrimitive, Data_M_E_xBitSubSetEq, 0, sizeof(STRUCT_Con_M_E_xBitSubSetEq), noBinderOffsets, &nameFun_M_E_xBitSubSetEq, &dataStep};
char *name_M_E_xLoadTerm =  "E_LoadTerm" ;
char *nameFun_M_E_xLoadTerm(Term term) { return name_M_E_xLoadTerm; }
struct _ConstructionDescriptor descriptor_M_E_xLoadTerm = {&sort_M_SPrimitive, Data_M_E_xLoadTerm, 0, sizeof(STRUCT_Con_M_E_xLoadTerm), noBinderOffsets, &nameFun_M_E_xLoadTerm, &dataStep};
char *name_M_E_xSaveTerm =  "E_SaveTerm" ;
char *nameFun_M_E_xSaveTerm(Term term) { return name_M_E_xSaveTerm; }
struct _ConstructionDescriptor descriptor_M_E_xSaveTerm = {&sort_M_SPrimitive, Data_M_E_xSaveTerm, 0, sizeof(STRUCT_Con_M_E_xSaveTerm), noBinderOffsets, &nameFun_M_E_xSaveTerm, &dataStep};
char *name_M_E_xIsZero =  "E_IsZero" ;
char *nameFun_M_E_xIsZero(Term term) { return name_M_E_xIsZero; }
struct _ConstructionDescriptor descriptor_M_E_xIsZero = {&sort_M_SPrimitive, Data_M_E_xIsZero, 0, sizeof(STRUCT_Con_M_E_xIsZero), noBinderOffsets, &nameFun_M_E_xIsZero, &dataStep};
char *name_M_E_xIsEmpty =  "E_IsEmpty" ;
char *nameFun_M_E_xIsEmpty(Term term) { return name_M_E_xIsEmpty; }
struct _ConstructionDescriptor descriptor_M_E_xIsEmpty = {&sort_M_SPrimitive, Data_M_E_xIsEmpty, 0, sizeof(STRUCT_Con_M_E_xIsEmpty), noBinderOffsets, &nameFun_M_E_xIsEmpty, &dataStep};
char *name_M_E_xNumericEqual =  "E_NumericEqual" ;
char *nameFun_M_E_xNumericEqual(Term term) { return name_M_E_xNumericEqual; }
struct _ConstructionDescriptor descriptor_M_E_xNumericEqual = {&sort_M_SPrimitive, Data_M_E_xNumericEqual, 0, sizeof(STRUCT_Con_M_E_xNumericEqual), noBinderOffsets, &nameFun_M_E_xNumericEqual, &dataStep};
char *name_M_E_xError =  "E_Error" ;
char *nameFun_M_E_xError(Term term) { return name_M_E_xError; }
struct _ConstructionDescriptor descriptor_M_E_xError = {&sort_M_SPrimitive, Data_M_E_xError, 0, sizeof(STRUCT_Con_M_E_xError), noBinderOffsets, &nameFun_M_E_xError, &dataStep};
char *name_M_E_xTrace =  "E_Trace" ;
char *nameFun_M_E_xTrace(Term term) { return name_M_E_xTrace; }
struct _ConstructionDescriptor descriptor_M_E_xTrace = {&sort_M_SPrimitive, Data_M_E_xTrace, 0, sizeof(STRUCT_Con_M_E_xTrace), noBinderOffsets, &nameFun_M_E_xTrace, &dataStep};
char *name_M_E_xFormatNumber =  "E_FormatNumber" ;
char *nameFun_M_E_xFormatNumber(Term term) { return name_M_E_xFormatNumber; }
struct _ConstructionDescriptor descriptor_M_E_xFormatNumber = {&sort_M_SPrimitive, Data_M_E_xFormatNumber, 0, sizeof(STRUCT_Con_M_E_xFormatNumber), noBinderOffsets, &nameFun_M_E_xFormatNumber, &dataStep};
char *name_M_E_xPassLocationProperties =  "E_PassLocationProperties" ;
char *nameFun_M_E_xPassLocationProperties(Term term) { return name_M_E_xPassLocationProperties; }
struct _ConstructionDescriptor descriptor_M_E_xPassLocationProperties = {&sort_M_SPrimitive, Data_M_E_xPassLocationProperties, 0, sizeof(STRUCT_Con_M_E_xPassLocationProperties), noBinderOffsets, &nameFun_M_E_xPassLocationProperties, &dataStep};
char *name_M_E_xGet =  "E_Get" ;
char *nameFun_M_E_xGet(Term term) { return name_M_E_xGet; }
struct _ConstructionDescriptor descriptor_M_E_xGet = {&sort_M_SPrimitive, Data_M_E_xGet, 0, sizeof(STRUCT_Con_M_E_xGet), noBinderOffsets, &nameFun_M_E_xGet, &dataStep};
char *name_M_E_xGetRef =  "E_GetRef" ;
char *nameFun_M_E_xGetRef(Term term) { return name_M_E_xGetRef; }
struct _ConstructionDescriptor descriptor_M_E_xGetRef = {&sort_M_SPrimitive, Data_M_E_xGetRef, 0, sizeof(STRUCT_Con_M_E_xGetRef), noBinderOffsets, &nameFun_M_E_xGetRef, &dataStep};
char *name_M_E_xIfDef =  "E_IfDef" ;
char *nameFun_M_E_xIfDef(Term term) { return name_M_E_xIfDef; }
struct _ConstructionDescriptor descriptor_M_E_xIfDef = {&sort_M_SPrimitive, Data_M_E_xIfDef, 0, sizeof(STRUCT_Con_M_E_xIfDef), noBinderOffsets, &nameFun_M_E_xIfDef, &dataStep};
char *name_M_E_xShow =  "E_Show" ;
char *nameFun_M_E_xShow(Term term) { return name_M_E_xShow; }
struct _ConstructionDescriptor descriptor_M_E_xShow = {&sort_M_SPrimitive, Data_M_E_xShow, 0, sizeof(STRUCT_Con_M_E_xShow), noBinderOffsets, &nameFun_M_E_xShow, &dataStep};
char *name_M_E_xFormat =  "E_Format" ;
char *nameFun_M_E_xFormat(Term term) { return name_M_E_xFormat; }
struct _ConstructionDescriptor descriptor_M_E_xFormat = {&sort_M_SPrimitive, Data_M_E_xFormat, 0, sizeof(STRUCT_Con_M_E_xFormat), noBinderOffsets, &nameFun_M_E_xFormat, &dataStep};
char *name_M_E_xFreeVariables =  "E_FreeVariables" ;
char *nameFun_M_E_xFreeVariables(Term term) { return name_M_E_xFreeVariables; }
struct _ConstructionDescriptor descriptor_M_E_xFreeVariables = {&sort_M_SPrimitive, Data_M_E_xFreeVariables, 0, sizeof(STRUCT_Con_M_E_xFreeVariables), noBinderOffsets, &nameFun_M_E_xFreeVariables, &dataStep};
char *name_M_E_xIntersectVariables =  "E_IntersectVariables" ;
char *nameFun_M_E_xIntersectVariables(Term term) { return name_M_E_xIntersectVariables; }
struct _ConstructionDescriptor descriptor_M_E_xIntersectVariables = {&sort_M_SPrimitive, Data_M_E_xIntersectVariables, 0, sizeof(STRUCT_Con_M_E_xIntersectVariables), noBinderOffsets, &nameFun_M_E_xIntersectVariables, &dataStep};
char *name_M_E_xUnionVariables =  "E_UnionVariables" ;
char *nameFun_M_E_xUnionVariables(Term term) { return name_M_E_xUnionVariables; }
struct _ConstructionDescriptor descriptor_M_E_xUnionVariables = {&sort_M_SPrimitive, Data_M_E_xUnionVariables, 0, sizeof(STRUCT_Con_M_E_xUnionVariables), noBinderOffsets, &nameFun_M_E_xUnionVariables, &dataStep};
char *name_M_E_xExceptVariables =  "E_ExceptVariables" ;
char *nameFun_M_E_xExceptVariables(Term term) { return name_M_E_xExceptVariables; }
struct _ConstructionDescriptor descriptor_M_E_xExceptVariables = {&sort_M_SPrimitive, Data_M_E_xExceptVariables, 0, sizeof(STRUCT_Con_M_E_xExceptVariables), noBinderOffsets, &nameFun_M_E_xExceptVariables, &dataStep};
char *name_M_E_xMatch =  "E_Match" ;
char *nameFun_M_E_xMatch(Term term) { return name_M_E_xMatch; }
struct _ConstructionDescriptor descriptor_M_E_xMatch = {&sort_M_SPrimitive, Data_M_E_xMatch, 0, sizeof(STRUCT_Con_M_E_xMatch), noBinderOffsets, &nameFun_M_E_xMatch, &dataStep};
char *name_M_E_xCall =  "E_Call" ;
char *nameFun_M_E_xCall(Term term) { return name_M_E_xCall; }
struct _ConstructionDescriptor descriptor_M_E_xCall = {&sort_M_SPrimitive, Data_M_E_xCall, 0, sizeof(STRUCT_Con_M_E_xCall), noBinderOffsets, &nameFun_M_E_xCall, &dataStep};
char *name_M_E_xTryCall =  "E_TryCall" ;
char *nameFun_M_E_xTryCall(Term term) { return name_M_E_xTryCall; }
struct _ConstructionDescriptor descriptor_M_E_xTryCall = {&sort_M_SPrimitive, Data_M_E_xTryCall, 0, sizeof(STRUCT_Con_M_E_xTryCall), noBinderOffsets, &nameFun_M_E_xTryCall, &dataStep};
char *name_M_E_xCast =  "E_Cast" ;
char *nameFun_M_E_xCast(Term term) { return name_M_E_xCast; }
struct _ConstructionDescriptor descriptor_M_E_xCast = {&sort_M_SPrimitive, Data_M_E_xCast, 0, sizeof(STRUCT_Con_M_E_xCast), noBinderOffsets, &nameFun_M_E_xCast, &dataStep};
ConstructionDescriptor sortCon_M_SPrimitive[] = {NULL, NULL, &descriptor_M_E_xNull, &descriptor_M_E_xNil, &descriptor_M_E_xForgivableError, &descriptor_M_E_xStringLessThan, &descriptor_M_E_xFromFirst, &descriptor_M_E_xToFirst, &descriptor_M_E_xVariableNameIs, &descriptor_M_E_xSplit, &descriptor_M_E_xRescape, &descriptor_M_E_xUpCase, &descriptor_M_E_xDownCase, &descriptor_M_E_xReplace, &descriptor_M_E_xTrim, &descriptor_M_E_xKeys, &descriptor_M_E_xParseURL, &descriptor_M_E_xEcho, &descriptor_M_E_xDeepEqual, &descriptor_M_E_xHashCode, &descriptor_M_E_xConcat, &descriptor_M_E_xC, &descriptor_M_E_xEqual, &descriptor_M_E_xNotEqual, &descriptor_M_E_xLessThan, &descriptor_M_E_xGreaterThan, &descriptor_M_E_xLessThanOrEqual, &descriptor_M_E_xSameVariable, &descriptor_M_E_xLesserVariable, &descriptor_M_E_xGreaterThanOrEqual, &descriptor_M_E_xIf, &descriptor_M_E_xIfZero, &descriptor_M_E_xIfEmpty, &descriptor_M_E_xSquash, &descriptor_M_E_xContains, &descriptor_M_E_xStartsWith, &descriptor_M_E_xEndsWith, &descriptor_M_E_xMatchRegex, &descriptor_M_E_xLength, &descriptor_M_E_xSubstring, &descriptor_M_E_xEscape, &descriptor_M_E_xMangle, &descriptor_M_E_xBeforeFirst, &descriptor_M_E_xAfterFirst, &descriptor_M_E_xPlus, &descriptor_M_E_xMinus, &descriptor_M_E_xTimes, &descriptor_M_E_xAbsolute, &descriptor_M_E_xDecimal, &descriptor_M_E_xDiv, &descriptor_M_E_xMod, &descriptor_M_E_xHex, &descriptor_M_E_xBitAnd, &descriptor_M_E_xBitOr, &descriptor_M_E_xBitXOr, &descriptor_M_E_xBitNot, &descriptor_M_E_xBitMinus, &descriptor_M_E_xBitSubSetEq, &descriptor_M_E_xLoadTerm, &descriptor_M_E_xSaveTerm, &descriptor_M_E_xIsZero, &descriptor_M_E_xIsEmpty, &descriptor_M_E_xNumericEqual, &descriptor_M_E_xError, &descriptor_M_E_xTrace, &descriptor_M_E_xFormatNumber, &descriptor_M_E_xPassLocationProperties, &descriptor_M_E_xGet, &descriptor_M_E_xGetRef, &descriptor_M_E_xIfDef, &descriptor_M_E_xShow, &descriptor_M_E_xFormat, &descriptor_M_E_xFreeVariables, &descriptor_M_E_xIntersectVariables, &descriptor_M_E_xUnionVariables, &descriptor_M_E_xExceptVariables, &descriptor_M_E_xMatch, &descriptor_M_E_xCall, &descriptor_M_E_xTryCall, &descriptor_M_E_xCast,  NULL};
char *sortNam_M_SPrimitive[] = {NULL, NULL,  "E_Null" ,  "E_Nil" ,  "E_ForgivableError" ,  "E_StringLessThan" ,  "E_FromFirst" ,  "E_ToFirst" ,  "E_VariableNameIs" ,  "E_Split" ,  "E_Rescape" ,  "E_UpCase" ,  "E_DownCase" ,  "E_Replace" ,  "E_Trim" ,  "E_Keys" ,  "E_ParseURL" ,  "E_Echo" ,  "E_DeepEqual" ,  "E_HashCode" ,  "E_Concat" ,  "E_C" ,  "E_Equal" ,  "E_NotEqual" ,  "E_LessThan" ,  "E_GreaterThan" ,  "E_LessThanOrEqual" ,  "E_SameVariable" ,  "E_LesserVariable" ,  "E_GreaterThanOrEqual" ,  "E_If" ,  "E_IfZero" ,  "E_IfEmpty" ,  "E_Squash" ,  "E_Contains" ,  "E_StartsWith" ,  "E_EndsWith" ,  "E_MatchRegex" ,  "E_Length" ,  "E_Substring" ,  "E_Escape" ,  "E_Mangle" ,  "E_BeforeFirst" ,  "E_AfterFirst" ,  "E_Plus" ,  "E_Minus" ,  "E_Times" ,  "E_Absolute" ,  "E_Decimal" ,  "E_Div" ,  "E_Mod" ,  "E_Hex" ,  "E_BitAnd" ,  "E_BitOr" ,  "E_BitXOr" ,  "E_BitNot" ,  "E_BitMinus" ,  "E_BitSubSetEq" ,  "E_LoadTerm" ,  "E_SaveTerm" ,  "E_IsZero" ,  "E_IsEmpty" ,  "E_NumericEqual" ,  "E_Error" ,  "E_Trace" ,  "E_FormatNumber" ,  "E_PassLocationProperties" ,  "E_Get" ,  "E_GetRef" ,  "E_IfDef" ,  "E_Show" ,  "E_Format" ,  "E_FreeVariables" ,  "E_IntersectVariables" ,  "E_UnionVariables" ,  "E_ExceptVariables" ,  "E_Match" ,  "E_Call" ,  "E_TryCall" ,  "E_Cast" ,  NULL};
char *sortInt_M_SPrimitive[] = {NULL, NULL, "_M_E_xNull", "_M_E_xNil", "_M_E_xForgivableError", "_M_E_xStringLessThan", "_M_E_xFromFirst", "_M_E_xToFirst", "_M_E_xVariableNameIs", "_M_E_xSplit", "_M_E_xRescape", "_M_E_xUpCase", "_M_E_xDownCase", "_M_E_xReplace", "_M_E_xTrim", "_M_E_xKeys", "_M_E_xParseURL", "_M_E_xEcho", "_M_E_xDeepEqual", "_M_E_xHashCode", "_M_E_xConcat", "_M_E_xC", "_M_E_xEqual", "_M_E_xNotEqual", "_M_E_xLessThan", "_M_E_xGreaterThan", "_M_E_xLessThanOrEqual", "_M_E_xSameVariable", "_M_E_xLesserVariable", "_M_E_xGreaterThanOrEqual", "_M_E_xIf", "_M_E_xIfZero", "_M_E_xIfEmpty", "_M_E_xSquash", "_M_E_xContains", "_M_E_xStartsWith", "_M_E_xEndsWith", "_M_E_xMatchRegex", "_M_E_xLength", "_M_E_xSubstring", "_M_E_xEscape", "_M_E_xMangle", "_M_E_xBeforeFirst", "_M_E_xAfterFirst", "_M_E_xPlus", "_M_E_xMinus", "_M_E_xTimes", "_M_E_xAbsolute", "_M_E_xDecimal", "_M_E_xDiv", "_M_E_xMod", "_M_E_xHex", "_M_E_xBitAnd", "_M_E_xBitOr", "_M_E_xBitXOr", "_M_E_xBitNot", "_M_E_xBitMinus", "_M_E_xBitSubSetEq", "_M_E_xLoadTerm", "_M_E_xSaveTerm", "_M_E_xIsZero", "_M_E_xIsEmpty", "_M_E_xNumericEqual", "_M_E_xError", "_M_E_xTrace", "_M_E_xFormatNumber", "_M_E_xPassLocationProperties", "_M_E_xGet", "_M_E_xGetRef", "_M_E_xIfDef", "_M_E_xShow", "_M_E_xFormat", "_M_E_xFreeVariables", "_M_E_xIntersectVariables", "_M_E_xUnionVariables", "_M_E_xExceptVariables", "_M_E_xMatch", "_M_E_xCall", "_M_E_xTryCall", "_M_E_xCast",  NULL};
struct _SortDescriptor sort_M_SPrimitive = { "SPrimitive" , sortCon_M_SPrimitive, sortNam_M_SPrimitive, sortInt_M_SPrimitive, NULL};

/* SORT STRING_ENTRY CONSTANTS. */
int conBindOffs_M_STRING_xVALUE[] = {0 , 0};
char *name_M_STRING_xVALUE =  "STRING_VALUE" ;
char *nameFun_M_STRING_xVALUE(Term term) { return name_M_STRING_xVALUE; }
struct _ConstructionDescriptor descriptor_M_STRING_xVALUE = {&sort_M_STRING_xENTRY, Data_M_STRING_xVALUE, 1, sizeof(STRUCT_Con_M_STRING_xVALUE), conBindOffs_M_STRING_xVALUE, &nameFun_M_STRING_xVALUE, &dataStep};
int conBindOffs_M_LIST_xSTRING[] = {0 , 0};
char *name_M_LIST_xSTRING =  "LIST_STRING" ;
char *nameFun_M_LIST_xSTRING(Term term) { return name_M_LIST_xSTRING; }
struct _ConstructionDescriptor descriptor_M_LIST_xSTRING = {&sort_M_STRING_xENTRY, Data_M_LIST_xSTRING, 1, sizeof(STRUCT_Con_M_LIST_xSTRING), conBindOffs_M_LIST_xSTRING, &nameFun_M_LIST_xSTRING, &dataStep};
int conBindOffs_M_NUM_xVALUE[] = {0 , 0};
char *name_M_NUM_xVALUE =  "NUM_VALUE" ;
char *nameFun_M_NUM_xVALUE(Term term) { return name_M_NUM_xVALUE; }
struct _ConstructionDescriptor descriptor_M_NUM_xVALUE = {&sort_M_STRING_xENTRY, Data_M_NUM_xVALUE, 1, sizeof(STRUCT_Con_M_NUM_xVALUE), conBindOffs_M_NUM_xVALUE, &nameFun_M_NUM_xVALUE, &dataStep};
int conBindOffs_M_VARIABLE[] = {0 , 0};
char *name_M_VARIABLE =  "VARIABLE" ;
char *nameFun_M_VARIABLE(Term term) { return name_M_VARIABLE; }
struct _ConstructionDescriptor descriptor_M_VARIABLE = {&sort_M_STRING_xENTRY, Data_M_VARIABLE, 1, sizeof(STRUCT_Con_M_VARIABLE), conBindOffs_M_VARIABLE, &nameFun_M_VARIABLE, &dataStep};
int conBindOffs_M_LIST_xVARIABLE[] = {0 , 0};
char *name_M_LIST_xVARIABLE =  "LIST_VARIABLE" ;
char *nameFun_M_LIST_xVARIABLE(Term term) { return name_M_LIST_xVARIABLE; }
struct _ConstructionDescriptor descriptor_M_LIST_xVARIABLE = {&sort_M_STRING_xENTRY, Data_M_LIST_xVARIABLE, 1, sizeof(STRUCT_Con_M_LIST_xVARIABLE), conBindOffs_M_LIST_xVARIABLE, &nameFun_M_LIST_xVARIABLE, &dataStep};
int conBindOffs_M_PROPERTY_xVARIABLE[] = {0 , 0 , 0 , 0};
char *name_M_PROPERTY_xVARIABLE =  "PROPERTY_VARIABLE" ;
char *nameFun_M_PROPERTY_xVARIABLE(Term term) { return name_M_PROPERTY_xVARIABLE; }
struct _ConstructionDescriptor descriptor_M_PROPERTY_xVARIABLE = {&sort_M_STRING_xENTRY, Data_M_PROPERTY_xVARIABLE, 3, sizeof(STRUCT_Con_M_PROPERTY_xVARIABLE), conBindOffs_M_PROPERTY_xVARIABLE, &nameFun_M_PROPERTY_xVARIABLE, &dataStep};
char *name_M_NO =  "NO" ;
char *nameFun_M_NO(Term term) { return name_M_NO; }
struct _ConstructionDescriptor descriptor_M_NO = {&sort_M_STRING_xENTRY, Data_M_NO, 0, sizeof(STRUCT_Con_M_NO), noBinderOffsets, &nameFun_M_NO, &dataStep};
ConstructionDescriptor sortCon_M_STRING_xENTRY[] = {NULL, NULL, &descriptor_M_STRING_xVALUE, &descriptor_M_LIST_xSTRING, &descriptor_M_NUM_xVALUE, &descriptor_M_VARIABLE, &descriptor_M_LIST_xVARIABLE, &descriptor_M_PROPERTY_xVARIABLE, &descriptor_M_NO,  NULL};
char *sortNam_M_STRING_xENTRY[] = {NULL, NULL,  "STRING_VALUE" ,  "LIST_STRING" ,  "NUM_VALUE" ,  "VARIABLE" ,  "LIST_VARIABLE" ,  "PROPERTY_VARIABLE" ,  "NO" ,  NULL};
char *sortInt_M_STRING_xENTRY[] = {NULL, NULL, "_M_STRING_xVALUE", "_M_LIST_xSTRING", "_M_NUM_xVALUE", "_M_VARIABLE", "_M_LIST_xVARIABLE", "_M_PROPERTY_xVARIABLE", "_M_NO",  NULL};
struct _SortDescriptor sort_M_STRING_xENTRY = { "STRING_ENTRY" , sortCon_M_STRING_xENTRY, sortNam_M_STRING_xENTRY, sortInt_M_STRING_xENTRY, NULL};

/* SORT T_REUSE_SORT CONSTANTS. */
char *name_M_T_xNO_xREUSE =  "T_NO_REUSE" ;
char *nameFun_M_T_xNO_xREUSE(Term term) { return name_M_T_xNO_xREUSE; }
struct _ConstructionDescriptor descriptor_M_T_xNO_xREUSE = {&sort_M_T_xREUSE_xSORT, Data_M_T_xNO_xREUSE, 0, sizeof(STRUCT_Con_M_T_xNO_xREUSE), noBinderOffsets, &nameFun_M_T_xNO_xREUSE, &dataStep};
char *name_M_T_xREUSE =  "T_REUSE" ;
char *nameFun_M_T_xREUSE(Term term) { return name_M_T_xREUSE; }
struct _ConstructionDescriptor descriptor_M_T_xREUSE = {&sort_M_T_xREUSE_xSORT, Data_M_T_xREUSE, 0, sizeof(STRUCT_Con_M_T_xREUSE), noBinderOffsets, &nameFun_M_T_xREUSE, &dataStep};
ConstructionDescriptor sortCon_M_T_xREUSE_xSORT[] = {NULL, NULL, &descriptor_M_T_xNO_xREUSE, &descriptor_M_T_xREUSE,  NULL};
char *sortNam_M_T_xREUSE_xSORT[] = {NULL, NULL,  "T_NO_REUSE" ,  "T_REUSE" ,  NULL};
char *sortInt_M_T_xREUSE_xSORT[] = {NULL, NULL, "_M_T_xNO_xREUSE", "_M_T_xREUSE",  NULL};
struct _SortDescriptor sort_M_T_xREUSE_xSORT = { "T_REUSE_SORT" , sortCon_M_T_xREUSE_xSORT, sortNam_M_T_xREUSE_xSORT, sortInt_M_T_xREUSE_xSORT, NULL};

/* SORT Text-Part CONSTANTS. */
int conBindOffs_M__sTextEmbed[] = {0 , 0};
char *name_M__sTextEmbed =  "$TextEmbed" ;
char *nameFun_M__sTextEmbed(Term term) { return name_M__sTextEmbed; }
struct _ConstructionDescriptor descriptor_M__sTextEmbed = {&sort_M_Text_Part, Data_M__sTextEmbed, 1, sizeof(STRUCT_Con_M__sTextEmbed), conBindOffs_M__sTextEmbed, &nameFun_M__sTextEmbed, &dataStep};
int conBindOffs_M__sTextBreak[] = {0 , 0};
char *name_M__sTextBreak =  "$TextBreak" ;
char *nameFun_M__sTextBreak(Term term) { return name_M__sTextBreak; }
struct _ConstructionDescriptor descriptor_M__sTextBreak = {&sort_M_Text_Part, Data_M__sTextBreak, 1, sizeof(STRUCT_Con_M__sTextBreak), conBindOffs_M__sTextBreak, &nameFun_M__sTextBreak, &dataStep};
char *name_M__sTextSeparator =  "$TextSeparator" ;
char *nameFun_M__sTextSeparator(Term term) { return name_M__sTextSeparator; }
struct _ConstructionDescriptor descriptor_M__sTextSeparator = {&sort_M_Text_Part, Data_M__sTextSeparator, 0, sizeof(STRUCT_Con_M__sTextSeparator), noBinderOffsets, &nameFun_M__sTextSeparator, &dataStep};
int conBindOffs_M__sTextGroup[] = {0 , 0};
char *name_M__sTextGroup =  "$TextGroup" ;
char *nameFun_M__sTextGroup(Term term) { return name_M__sTextGroup; }
struct _ConstructionDescriptor descriptor_M__sTextGroup = {&sort_M_Text_Part, Data_M__sTextGroup, 1, sizeof(STRUCT_Con_M__sTextGroup), conBindOffs_M__sTextGroup, &nameFun_M__sTextGroup, &dataStep};
int conBindOffs_M__sTextIndent[] = {0 , 0};
char *name_M__sTextIndent =  "$TextIndent" ;
char *nameFun_M__sTextIndent(Term term) { return name_M__sTextIndent; }
struct _ConstructionDescriptor descriptor_M__sTextIndent = {&sort_M_Text_Part, Data_M__sTextIndent, 1, sizeof(STRUCT_Con_M__sTextIndent), conBindOffs_M__sTextIndent, &nameFun_M__sTextIndent, &dataStep};
int conBindOffs_M__sTextString[] = {0 , 0};
char *name_M__sTextString =  "$TextString" ;
char *nameFun_M__sTextString(Term term) { return name_M__sTextString; }
struct _ConstructionDescriptor descriptor_M__sTextString = {&sort_M_Text_Part, Data_M__sTextString, 1, sizeof(STRUCT_Con_M__sTextString), conBindOffs_M__sTextString, &nameFun_M__sTextString, &dataStep};
int conBindOffs_M__sTextChars[] = {0 , 0};
char *name_M__sTextChars =  "$TextChars" ;
char *nameFun_M__sTextChars(Term term) { return name_M__sTextChars; }
struct _ConstructionDescriptor descriptor_M__sTextChars = {&sort_M_Text_Part, Data_M__sTextChars, 1, sizeof(STRUCT_Con_M__sTextChars), conBindOffs_M__sTextChars, &nameFun_M__sTextChars, &dataStep};
ConstructionDescriptor sortCon_M_Text_Part[] = {NULL, NULL, &descriptor_M__sTextEmbed, &descriptor_M__sTextBreak, &descriptor_M__sTextSeparator, &descriptor_M__sTextGroup, &descriptor_M__sTextIndent, &descriptor_M__sTextString, &descriptor_M__sTextChars,  NULL};
char *sortNam_M_Text_Part[] = {NULL, NULL,  "$TextEmbed" ,  "$TextBreak" ,  "$TextSeparator" ,  "$TextGroup" ,  "$TextIndent" ,  "$TextString" ,  "$TextChars" ,  NULL};
char *sortInt_M_Text_Part[] = {NULL, NULL, "_M__sTextEmbed", "_M__sTextBreak", "_M__sTextSeparator", "_M__sTextGroup", "_M__sTextIndent", "_M__sTextString", "_M__sTextChars",  NULL};
struct _SortDescriptor sort_M_Text_Part = { "Text-Part" , sortCon_M_Text_Part, sortNam_M_Text_Part, sortInt_M_Text_Part, NULL};

/* SORT VARIABLE_ENTRY CONSTANTS. */
char *name_M_FREE =  "FREE" ;
char *nameFun_M_FREE(Term term) { return name_M_FREE; }
struct _ConstructionDescriptor descriptor_M_FREE = {&sort_M_VARIABLE_xENTRY, Data_M_FREE, 0, sizeof(STRUCT_Con_M_FREE), noBinderOffsets, &nameFun_M_FREE, &dataStep};
char *name_M_BOUNDREUSE =  "BOUNDREUSE" ;
char *nameFun_M_BOUNDREUSE(Term term) { return name_M_BOUNDREUSE; }
struct _ConstructionDescriptor descriptor_M_BOUNDREUSE = {&sort_M_VARIABLE_xENTRY, Data_M_BOUNDREUSE, 0, sizeof(STRUCT_Con_M_BOUNDREUSE), noBinderOffsets, &nameFun_M_BOUNDREUSE, &dataStep};
char *name_M_FRESH =  "FRESH" ;
char *nameFun_M_FRESH(Term term) { return name_M_FRESH; }
struct _ConstructionDescriptor descriptor_M_FRESH = {&sort_M_VARIABLE_xENTRY, Data_M_FRESH, 0, sizeof(STRUCT_Con_M_FRESH), noBinderOffsets, &nameFun_M_FRESH, &dataStep};
char *name_M_FRESHREUSE =  "FRESHREUSE" ;
char *nameFun_M_FRESHREUSE(Term term) { return name_M_FRESHREUSE; }
struct _ConstructionDescriptor descriptor_M_FRESHREUSE = {&sort_M_VARIABLE_xENTRY, Data_M_FRESHREUSE, 0, sizeof(STRUCT_Con_M_FRESHREUSE), noBinderOffsets, &nameFun_M_FRESHREUSE, &dataStep};
int conBindOffs_M_SUB[] = {0 , 0 , 0 , 0};
char *name_M_SUB =  "SUB" ;
char *nameFun_M_SUB(Term term) { return name_M_SUB; }
struct _ConstructionDescriptor descriptor_M_SUB = {&sort_M_VARIABLE_xENTRY, Data_M_SUB, 3, sizeof(STRUCT_Con_M_SUB), conBindOffs_M_SUB, &nameFun_M_SUB, &dataStep};
char *name_M_BOUND =  "BOUND" ;
char *nameFun_M_BOUND(Term term) { return name_M_BOUND; }
struct _ConstructionDescriptor descriptor_M_BOUND = {&sort_M_VARIABLE_xENTRY, Data_M_BOUND, 0, sizeof(STRUCT_Con_M_BOUND), noBinderOffsets, &nameFun_M_BOUND, &dataStep};
ConstructionDescriptor sortCon_M_VARIABLE_xENTRY[] = {NULL, NULL, &descriptor_M_FREE, &descriptor_M_BOUNDREUSE, &descriptor_M_FRESH, &descriptor_M_FRESHREUSE, &descriptor_M_SUB, &descriptor_M_BOUND,  NULL};
char *sortNam_M_VARIABLE_xENTRY[] = {NULL, NULL,  "FREE" ,  "BOUNDREUSE" ,  "FRESH" ,  "FRESHREUSE" ,  "SUB" ,  "BOUND" ,  NULL};
char *sortInt_M_VARIABLE_xENTRY[] = {NULL, NULL, "_M_FREE", "_M_BOUNDREUSE", "_M_FRESH", "_M_FRESHREUSE", "_M_SUB", "_M_BOUND",  NULL};
struct _SortDescriptor sort_M_VARIABLE_xENTRY = { "VARIABLE_ENTRY" , sortCon_M_VARIABLE_xENTRY, sortNam_M_VARIABLE_xENTRY, sortInt_M_VARIABLE_xENTRY, NULL};

#ifdef __cplusplus
}
#endif
/* END OF C SORT DESCRIPTORS FOR CRSX CRSXC. */
