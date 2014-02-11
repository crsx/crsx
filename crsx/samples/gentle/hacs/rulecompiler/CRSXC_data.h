/* C HEADER FOR CRSX CRSXC MODULE DATA. */
#ifndef CRSX__M_CRSXC_M_DATA_H
#define CRSX__M_CRSXC_M_DATA_H

#ifdef __cplusplus
extern "C" {
#endif

/* DATA SORT $Boolean HEADER DECLARATIONS. */
typedef enum {FunOf_M__sBoolean = 0, VarOf_M__sBoolean = 1, Data_M__sFalse, Data_M__sTrue} EnumOf_M__sBoolean;
#define STRUCT_Con_M__sFalse struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M__sFalse;
#define STRUCT_Con_M__sTrue struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M__sTrue;
extern struct _SortDescriptor sort_M__sBoolean;

/* DATA SORT $List HEADER DECLARATIONS. */
typedef enum {FunOf_M__sList = 0, VarOf_M__sList = 1, Data_M__sNil, Data_M__sCons} EnumOf_M__sList;
#define STRUCT_Con_M__sNil struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M__sNil;
#define STRUCT_Con_M__sCons struct _Con_M__sCons
struct _Con_M__sCons {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__sCons;
extern struct _SortDescriptor sort_M__sList;

/* DATA SORT $TryResult HEADER DECLARATIONS. */
typedef enum {FunOf_M__sTryResult = 0, VarOf_M__sTryResult = 1, Data_M__sTrySuccess, Data_M__sTryFailure} EnumOf_M__sTryResult;
#define STRUCT_Con_M__sTrySuccess struct _Con_M__sTrySuccess
struct _Con_M__sTrySuccess {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__sTrySuccess;
#define STRUCT_Con_M__sTryFailure struct _Con_M__sTryFailure
struct _Con_M__sTryFailure {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__sTryFailure;
extern struct _SortDescriptor sort_M__sTryResult;

/* DATA SORT Binder-State HEADER DECLARATIONS. */
typedef enum {FunOf_M_Binder_State = 0, VarOf_M_Binder_State = 1, Data_M_OUTER, Data_M_REUSING, Data_M_NO_xREUSE, Data_M_COPYING} EnumOf_M_Binder_State;
#define STRUCT_Con_M_OUTER struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_OUTER;
#define STRUCT_Con_M_REUSING struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_REUSING;
#define STRUCT_Con_M_NO_xREUSE struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_NO_xREUSE;
#define STRUCT_Con_M_COPYING struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_COPYING;
extern struct _SortDescriptor sort_M_Binder_State;

/* DATA SORT Meta-Occurrence HEADER DECLARATIONS. */
typedef enum {FunOf_M_Meta_Occurrence = 0, VarOf_M_Meta_Occurrence = 1, Data_M_NOTHING, Data_M_UNIQUE} EnumOf_M_Meta_Occurrence;
#define STRUCT_Con_M_NOTHING struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_NOTHING;
#define STRUCT_Con_M_UNIQUE struct _Con_M_UNIQUE
struct _Con_M_UNIQUE {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_UNIQUE;
extern struct _SortDescriptor sort_M_Meta_Occurrence;

/* DATA SORT OK_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_OK_xSORT = 0, VarOf_M_OK_xSORT = 1, Data_M_OK} EnumOf_M_OK_xSORT;
#define STRUCT_Con_M_OK struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_OK;
extern struct _SortDescriptor sort_M_OK_xSORT;

/* DATA SORT PASS HEADER DECLARATIONS. */
typedef enum {FunOf_M_PASS = 0, VarOf_M_PASS = 1, Data_M_FIRST, Data_M_SECOND} EnumOf_M_PASS;
#define STRUCT_Con_M_FIRST struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_FIRST;
#define STRUCT_Con_M_SECOND struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_SECOND;
extern struct _SortDescriptor sort_M_PASS;

/* DATA SORT Pattern-Stage HEADER DECLARATIONS. */
typedef enum {FunOf_M_Pattern_Stage = 0, VarOf_M_Pattern_Stage = 1, Data_M_MATCH, Data_M_SUBMATCH, Data_M_CASE, Data_M_DISPATCH} EnumOf_M_Pattern_Stage;
#define STRUCT_Con_M_MATCH struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_MATCH;
#define STRUCT_Con_M_SUBMATCH struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_SUBMATCH;
#define STRUCT_Con_M_CASE struct _Con_M_CASE
struct _Con_M_CASE {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CASE;
#define STRUCT_Con_M_DISPATCH struct _Con_M_DISPATCH
struct _Con_M_DISPATCH {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DISPATCH;
extern struct _SortDescriptor sort_M_Pattern_Stage;

/* DATA SORT PropsOf$$TextCons_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_s_sTextCons_xSORT = 0, VarOf_M_PropsOf_s_sTextCons_xSORT = 1, Data_M_PropsOf_s_sTextCons} EnumOf_M_PropsOf_s_sTextCons_xSORT;
#define STRUCT_Con_M_PropsOf_s_sTextCons struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_s_sTextCons;
extern struct _SortDescriptor sort_M_PropsOf_s_sTextCons_xSORT;

/* DATA SORT PropsOf$$TextNil_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_s_sTextNil_xSORT = 0, VarOf_M_PropsOf_s_sTextNil_xSORT = 1, Data_M_PropsOf_s_sTextNil} EnumOf_M_PropsOf_s_sTextNil_xSORT;
#define STRUCT_Con_M_PropsOf_s_sTextNil struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_s_sTextNil;
extern struct _SortDescriptor sort_M_PropsOf_s_sTextNil_xSORT;

/* DATA SORT Reified_Binder HEADER DECLARATIONS. */
typedef enum {FunOf_M_Reified_xBinder = 0, VarOf_M_Reified_xBinder = 1, Data_M_ARGUMENT, Data_M_BINDER, Data_M_META_REQUIRED_VARIABLE} EnumOf_M_Reified_xBinder;
#define STRUCT_Con_M_ARGUMENT struct _Con_M_ARGUMENT
struct _Con_M_ARGUMENT {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ARGUMENT;
#define STRUCT_Con_M_BINDER struct _Con_M_BINDER
struct _Con_M_BINDER {struct _Construction construction; Term sub[4]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M_BINDER;
#define STRUCT_Con_M_META_REQUIRED_VARIABLE struct _Con_M_META_REQUIRED_VARIABLE
struct _Con_M_META_REQUIRED_VARIABLE {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_META_REQUIRED_VARIABLE;
extern struct _SortDescriptor sort_M_Reified_xBinder;

/* DATA SORT Reified_Declaration HEADER DECLARATIONS. */
typedef enum {FunOf_M_Reified_xDeclaration = 0, VarOf_M_Reified_xDeclaration = 1, Data_M_FUNCTION, Data_M_DATA, Data_M_POLYMORPHIC} EnumOf_M_Reified_xDeclaration;
#define STRUCT_Con_M_FUNCTION struct _Con_M_FUNCTION
struct _Con_M_FUNCTION {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_FUNCTION;
#define STRUCT_Con_M_DATA struct _Con_M_DATA
struct _Con_M_DATA {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DATA;
#define STRUCT_Con_M_POLYMORPHIC struct _Con_M_POLYMORPHIC
struct _Con_M_POLYMORPHIC {struct _Construction construction; Term sub[1]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M_POLYMORPHIC;
extern struct _SortDescriptor sort_M_Reified_xDeclaration;

/* DATA SORT Reified_Form HEADER DECLARATIONS. */
typedef enum {FunOf_M_Reified_xForm = 0, VarOf_M_Reified_xForm = 1, Data_M_SORT_ALLOWS_VARIABLES, Data_M_SORT_SET, Data_M_FORM} EnumOf_M_Reified_xForm;
#define STRUCT_Con_M_SORT_ALLOWS_VARIABLES struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_SORT_ALLOWS_VARIABLES;
#define STRUCT_Con_M_SORT_SET struct _Con_M_SORT_SET
struct _Con_M_SORT_SET {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SORT_SET;
#define STRUCT_Con_M_FORM struct _Con_M_FORM
struct _Con_M_FORM {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_FORM;
extern struct _SortDescriptor sort_M_Reified_xForm;

/* DATA SORT Reified_FormArgument HEADER DECLARATIONS. */
typedef enum {FunOf_M_Reified_xFormArgument = 0, VarOf_M_Reified_xFormArgument = 1, Data_M_FORM_ARGUMENT, Data_M_FORM_BINDER} EnumOf_M_Reified_xFormArgument;
#define STRUCT_Con_M_FORM_ARGUMENT struct _Con_M_FORM_ARGUMENT
struct _Con_M_FORM_ARGUMENT {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_FORM_ARGUMENT;
#define STRUCT_Con_M_FORM_BINDER struct _Con_M_FORM_BINDER
struct _Con_M_FORM_BINDER {struct _Construction construction; Term sub[2]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M_FORM_BINDER;
extern struct _SortDescriptor sort_M_Reified_xFormArgument;

/* DATA SORT Reified_Occurrence HEADER DECLARATIONS. */
typedef enum {FunOf_M_Reified_xOccurrence = 0, VarOf_M_Reified_xOccurrence = 1, Data_M_OTHER, Data_M_META_USE} EnumOf_M_Reified_xOccurrence;
#define STRUCT_Con_M_OTHER struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_OTHER;
#define STRUCT_Con_M_META_USE struct _Con_M_META_USE
struct _Con_M_META_USE {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_META_USE;
extern struct _SortDescriptor sort_M_Reified_xOccurrence;

/* DATA SORT Reified_Option HEADER DECLARATIONS. */
typedef enum {FunOf_M_Reified_xOption = 0, VarOf_M_Reified_xOption = 1, Data_M_OPTION} EnumOf_M_Reified_xOption;
#define STRUCT_Con_M_OPTION struct _Con_M_OPTION
struct _Con_M_OPTION {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_OPTION;
extern struct _SortDescriptor sort_M_Reified_xOption;

/* DATA SORT Reified_Promiscuity HEADER DECLARATIONS. */
typedef enum {FunOf_M_Reified_xPromiscuity = 0, VarOf_M_Reified_xPromiscuity = 1, Data_M_PROMISCUOUS, Data_M_LINEAR} EnumOf_M_Reified_xPromiscuity;
#define STRUCT_Con_M_PROMISCUOUS struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PROMISCUOUS;
#define STRUCT_Con_M_LINEAR struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_LINEAR;
extern struct _SortDescriptor sort_M_Reified_xPromiscuity;

/* DATA SORT Reified_Rule HEADER DECLARATIONS. */
typedef enum {FunOf_M_Reified_xRule = 0, VarOf_M_Reified_xRule = 1, Data_M_RULE} EnumOf_M_Reified_xRule;
#define STRUCT_Con_M_RULE struct _Con_M_RULE
struct _Con_M_RULE {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RULE;
extern struct _SortDescriptor sort_M_Reified_xRule;

/* DATA SORT Reified_Sort HEADER DECLARATIONS. */
typedef enum {FunOf_M_Reified_xSort = 0, VarOf_M_Reified_xSort = 1, Data_M_SORT, Data_M_SORT_VARIABLE, Data_M_SORT_PROPERTY} EnumOf_M_Reified_xSort;
#define STRUCT_Con_M_SORT struct _Con_M_SORT
struct _Con_M_SORT {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SORT;
#define STRUCT_Con_M_SORT_VARIABLE struct _Con_M_SORT_VARIABLE
struct _Con_M_SORT_VARIABLE {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SORT_VARIABLE;
#define STRUCT_Con_M_SORT_PROPERTY struct _Con_M_SORT_PROPERTY
struct _Con_M_SORT_PROPERTY {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SORT_PROPERTY;
extern struct _SortDescriptor sort_M_Reified_xSort;

/* DATA SORT Reified_Term HEADER DECLARATIONS. */
typedef enum {FunOf_M_Reified_xTerm = 0, VarOf_M_Reified_xTerm = 1, Data_M_FreshReuseOrigin, Data_M_EVALUATOR, Data_M_META_APPLICATION, Data_M_LITERAL, Data_M_VARIABLE_USE, Data_M_CONSTRUCTION, Data_M_PROPERTY, Data_M_PROPERTY_NOT, Data_M_PROPERTY_REF} EnumOf_M_Reified_xTerm;
#define STRUCT_Con_M_FreshReuseOrigin struct _Con_M_FreshReuseOrigin
struct _Con_M_FreshReuseOrigin {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_FreshReuseOrigin;
#define STRUCT_Con_M_EVALUATOR struct _Con_M_EVALUATOR
struct _Con_M_EVALUATOR {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_EVALUATOR;
#define STRUCT_Con_M_META_APPLICATION struct _Con_M_META_APPLICATION
struct _Con_M_META_APPLICATION {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_META_APPLICATION;
#define STRUCT_Con_M_LITERAL struct _Con_M_LITERAL
struct _Con_M_LITERAL {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_LITERAL;
#define STRUCT_Con_M_VARIABLE_USE struct _Con_M_VARIABLE_USE
struct _Con_M_VARIABLE_USE {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_VARIABLE_USE;
#define STRUCT_Con_M_CONSTRUCTION struct _Con_M_CONSTRUCTION
struct _Con_M_CONSTRUCTION {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CONSTRUCTION;
#define STRUCT_Con_M_PROPERTY struct _Con_M_PROPERTY
struct _Con_M_PROPERTY {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PROPERTY;
#define STRUCT_Con_M_PROPERTY_NOT struct _Con_M_PROPERTY_NOT
struct _Con_M_PROPERTY_NOT {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PROPERTY_NOT;
#define STRUCT_Con_M_PROPERTY_REF struct _Con_M_PROPERTY_REF
struct _Con_M_PROPERTY_REF {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PROPERTY_REF;
extern struct _SortDescriptor sort_M_Reified_xTerm;

/* DATA SORT Reified_Use HEADER DECLARATIONS. */
typedef enum {FunOf_M_Reified_xUse = 0, VarOf_M_Reified_xUse = 1, Data_M_NOLINK, Data_M_USE, Data_M_DISCARD, Data_M_LINK, Data_M_NA} EnumOf_M_Reified_xUse;
#define STRUCT_Con_M_NOLINK struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_NOLINK;
#define STRUCT_Con_M_USE struct _Con_M_USE
struct _Con_M_USE {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_USE;
#define STRUCT_Con_M_DISCARD struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_DISCARD;
#define STRUCT_Con_M_LINK struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_LINK;
#define STRUCT_Con_M_NA struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_NA;
extern struct _SortDescriptor sort_M_Reified_xUse;

/* DATA SORT Reified_Variable HEADER DECLARATIONS. */
typedef enum {FunOf_M_Reified_xVariable = 0, VarOf_M_Reified_xVariable = 1, Data_M__sTextNil, Data_M__sTextCons} EnumOf_M_Reified_xVariable;
#define STRUCT_Con_M__sTextNil struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M__sTextNil;
#define STRUCT_Con_M__sTextCons struct _Con_M__sTextCons
struct _Con_M__sTextCons {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__sTextCons;
extern struct _SortDescriptor sort_M_Reified_xVariable;

/* DATA SORT Reify_CRSX HEADER DECLARATIONS. */
typedef enum {FunOf_M_Reify_xCRSX = 0, VarOf_M_Reify_xCRSX = 1, Data_M_CRSX} EnumOf_M_Reify_xCRSX;
#define STRUCT_Con_M_CRSX struct _Con_M_CRSX
struct _Con_M_CRSX {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRSX;
extern struct _SortDescriptor sort_M_Reify_xCRSX;

/* DATA SORT SPrimitive HEADER DECLARATIONS. */
typedef enum {FunOf_M_SPrimitive = 0, VarOf_M_SPrimitive = 1, Data_M_E_xForgivableError, Data_M_E_xStringLessThan, Data_M_E_xNull, Data_M_E_xNil, Data_M_E_xVariableNameIs, Data_M_E_xSplit, Data_M_E_xFromFirst, Data_M_E_xToFirst, Data_M_E_xDownCase, Data_M_E_xReplace, Data_M_E_xRescape, Data_M_E_xUpCase, Data_M_E_xParseURL, Data_M_E_xEcho, Data_M_E_xTrim, Data_M_E_xKeys, Data_M_E_xGreaterThanOrEqual, Data_M_E_xLesserVariable, Data_M_E_xIfZero, Data_M_E_xIf, Data_M_E_xGreaterThan, Data_M_E_xLessThan, Data_M_E_xSameVariable, Data_M_E_xLessThanOrEqual, Data_M_E_xC, Data_M_E_xConcat, Data_M_E_xNotEqual, Data_M_E_xEqual, Data_M_E_xPlus, Data_M_E_xMinus, Data_M_E_xTimes, Data_M_E_xAbsolute, Data_M_E_xEscape, Data_M_E_xMangle, Data_M_E_xBeforeFirst, Data_M_E_xAfterFirst, Data_M_E_xEndsWith, Data_M_E_xMatchRegex, Data_M_E_xLength, Data_M_E_xSubstring, Data_M_E_xIfEmpty, Data_M_E_xSquash, Data_M_E_xContains, Data_M_E_xStartsWith, Data_M_E_xError, Data_M_E_xNumericEqual, Data_M_E_xIsEmpty, Data_M_E_xIsZero, Data_M_E_xSaveTerm, Data_M_E_xLoadTerm, Data_M_E_xBitSubSetEq, Data_M_E_xBitMinus, Data_M_E_xBitNot, Data_M_E_xBitXOr, Data_M_E_xBitOr, Data_M_E_xBitAnd, Data_M_E_xHex, Data_M_E_xMod, Data_M_E_xDiv, Data_M_E_xDecimal, Data_M_E_xTryCall, Data_M_E_xCast, Data_M_E_xMatch, Data_M_E_xCall, Data_M_E_xUnionVariables, Data_M_E_xExceptVariables, Data_M_E_xFreeVariables, Data_M_E_xIntersectVariables, Data_M_E_xShow, Data_M_E_xFormat, Data_M_E_xGetRef, Data_M_E_xIfDef, Data_M_E_xPassLocationProperties, Data_M_E_xGet, Data_M_E_xTrace, Data_M_E_xFormatNumber} EnumOf_M_SPrimitive;
#define STRUCT_Con_M_E_xForgivableError struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xForgivableError;
#define STRUCT_Con_M_E_xStringLessThan struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xStringLessThan;
#define STRUCT_Con_M_E_xNull struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xNull;
#define STRUCT_Con_M_E_xNil struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xNil;
#define STRUCT_Con_M_E_xVariableNameIs struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xVariableNameIs;
#define STRUCT_Con_M_E_xSplit struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xSplit;
#define STRUCT_Con_M_E_xFromFirst struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xFromFirst;
#define STRUCT_Con_M_E_xToFirst struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xToFirst;
#define STRUCT_Con_M_E_xDownCase struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xDownCase;
#define STRUCT_Con_M_E_xReplace struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xReplace;
#define STRUCT_Con_M_E_xRescape struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xRescape;
#define STRUCT_Con_M_E_xUpCase struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xUpCase;
#define STRUCT_Con_M_E_xParseURL struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xParseURL;
#define STRUCT_Con_M_E_xEcho struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xEcho;
#define STRUCT_Con_M_E_xTrim struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xTrim;
#define STRUCT_Con_M_E_xKeys struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xKeys;
#define STRUCT_Con_M_E_xGreaterThanOrEqual struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xGreaterThanOrEqual;
#define STRUCT_Con_M_E_xLesserVariable struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xLesserVariable;
#define STRUCT_Con_M_E_xIfZero struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xIfZero;
#define STRUCT_Con_M_E_xIf struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xIf;
#define STRUCT_Con_M_E_xGreaterThan struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xGreaterThan;
#define STRUCT_Con_M_E_xLessThan struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xLessThan;
#define STRUCT_Con_M_E_xSameVariable struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xSameVariable;
#define STRUCT_Con_M_E_xLessThanOrEqual struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xLessThanOrEqual;
#define STRUCT_Con_M_E_xC struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xC;
#define STRUCT_Con_M_E_xConcat struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xConcat;
#define STRUCT_Con_M_E_xNotEqual struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xNotEqual;
#define STRUCT_Con_M_E_xEqual struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xEqual;
#define STRUCT_Con_M_E_xPlus struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xPlus;
#define STRUCT_Con_M_E_xMinus struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xMinus;
#define STRUCT_Con_M_E_xTimes struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xTimes;
#define STRUCT_Con_M_E_xAbsolute struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xAbsolute;
#define STRUCT_Con_M_E_xEscape struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xEscape;
#define STRUCT_Con_M_E_xMangle struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xMangle;
#define STRUCT_Con_M_E_xBeforeFirst struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xBeforeFirst;
#define STRUCT_Con_M_E_xAfterFirst struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xAfterFirst;
#define STRUCT_Con_M_E_xEndsWith struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xEndsWith;
#define STRUCT_Con_M_E_xMatchRegex struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xMatchRegex;
#define STRUCT_Con_M_E_xLength struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xLength;
#define STRUCT_Con_M_E_xSubstring struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xSubstring;
#define STRUCT_Con_M_E_xIfEmpty struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xIfEmpty;
#define STRUCT_Con_M_E_xSquash struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xSquash;
#define STRUCT_Con_M_E_xContains struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xContains;
#define STRUCT_Con_M_E_xStartsWith struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xStartsWith;
#define STRUCT_Con_M_E_xError struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xError;
#define STRUCT_Con_M_E_xNumericEqual struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xNumericEqual;
#define STRUCT_Con_M_E_xIsEmpty struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xIsEmpty;
#define STRUCT_Con_M_E_xIsZero struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xIsZero;
#define STRUCT_Con_M_E_xSaveTerm struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xSaveTerm;
#define STRUCT_Con_M_E_xLoadTerm struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xLoadTerm;
#define STRUCT_Con_M_E_xBitSubSetEq struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xBitSubSetEq;
#define STRUCT_Con_M_E_xBitMinus struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xBitMinus;
#define STRUCT_Con_M_E_xBitNot struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xBitNot;
#define STRUCT_Con_M_E_xBitXOr struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xBitXOr;
#define STRUCT_Con_M_E_xBitOr struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xBitOr;
#define STRUCT_Con_M_E_xBitAnd struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xBitAnd;
#define STRUCT_Con_M_E_xHex struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xHex;
#define STRUCT_Con_M_E_xMod struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xMod;
#define STRUCT_Con_M_E_xDiv struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xDiv;
#define STRUCT_Con_M_E_xDecimal struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xDecimal;
#define STRUCT_Con_M_E_xTryCall struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xTryCall;
#define STRUCT_Con_M_E_xCast struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xCast;
#define STRUCT_Con_M_E_xMatch struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xMatch;
#define STRUCT_Con_M_E_xCall struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xCall;
#define STRUCT_Con_M_E_xUnionVariables struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xUnionVariables;
#define STRUCT_Con_M_E_xExceptVariables struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xExceptVariables;
#define STRUCT_Con_M_E_xFreeVariables struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xFreeVariables;
#define STRUCT_Con_M_E_xIntersectVariables struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xIntersectVariables;
#define STRUCT_Con_M_E_xShow struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xShow;
#define STRUCT_Con_M_E_xFormat struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xFormat;
#define STRUCT_Con_M_E_xGetRef struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xGetRef;
#define STRUCT_Con_M_E_xIfDef struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xIfDef;
#define STRUCT_Con_M_E_xPassLocationProperties struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xPassLocationProperties;
#define STRUCT_Con_M_E_xGet struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xGet;
#define STRUCT_Con_M_E_xTrace struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xTrace;
#define STRUCT_Con_M_E_xFormatNumber struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_E_xFormatNumber;
extern struct _SortDescriptor sort_M_SPrimitive;

/* DATA SORT STRING_ENTRY HEADER DECLARATIONS. */
typedef enum {FunOf_M_STRING_xENTRY = 0, VarOf_M_STRING_xENTRY = 1, Data_M_PROPERTY_xVARIABLE, Data_M_NO, Data_M_STRING_xVALUE, Data_M_LIST_xSTRING, Data_M_NUM_xVALUE, Data_M_VARIABLE, Data_M_LIST_xVARIABLE} EnumOf_M_STRING_xENTRY;
#define STRUCT_Con_M_PROPERTY_xVARIABLE struct _Con_M_PROPERTY_xVARIABLE
struct _Con_M_PROPERTY_xVARIABLE {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PROPERTY_xVARIABLE;
#define STRUCT_Con_M_NO struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_NO;
#define STRUCT_Con_M_STRING_xVALUE struct _Con_M_STRING_xVALUE
struct _Con_M_STRING_xVALUE {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_STRING_xVALUE;
#define STRUCT_Con_M_LIST_xSTRING struct _Con_M_LIST_xSTRING
struct _Con_M_LIST_xSTRING {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_LIST_xSTRING;
#define STRUCT_Con_M_NUM_xVALUE struct _Con_M_NUM_xVALUE
struct _Con_M_NUM_xVALUE {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NUM_xVALUE;
#define STRUCT_Con_M_VARIABLE struct _Con_M_VARIABLE
struct _Con_M_VARIABLE {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_VARIABLE;
#define STRUCT_Con_M_LIST_xVARIABLE struct _Con_M_LIST_xVARIABLE
struct _Con_M_LIST_xVARIABLE {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_LIST_xVARIABLE;
extern struct _SortDescriptor sort_M_STRING_xENTRY;

/* DATA SORT T_REUSE_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_T_xREUSE_xSORT = 0, VarOf_M_T_xREUSE_xSORT = 1, Data_M_T_xREUSE, Data_M_T_xNO_xREUSE} EnumOf_M_T_xREUSE_xSORT;
#define STRUCT_Con_M_T_xREUSE struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_T_xREUSE;
#define STRUCT_Con_M_T_xNO_xREUSE struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_T_xNO_xREUSE;
extern struct _SortDescriptor sort_M_T_xREUSE_xSORT;

/* DATA SORT Text-Part HEADER DECLARATIONS. */
typedef enum {FunOf_M_Text_Part = 0, VarOf_M_Text_Part = 1, Data_M__sTextString, Data_M__sTextBreak, Data_M__sTextEmbed, Data_M__sTextIndent, Data_M__sTextGroup, Data_M__sTextSeparator, Data_M__sTextChars} EnumOf_M_Text_Part;
#define STRUCT_Con_M__sTextString struct _Con_M__sTextString
struct _Con_M__sTextString {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__sTextString;
#define STRUCT_Con_M__sTextBreak struct _Con_M__sTextBreak
struct _Con_M__sTextBreak {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__sTextBreak;
#define STRUCT_Con_M__sTextEmbed struct _Con_M__sTextEmbed
struct _Con_M__sTextEmbed {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__sTextEmbed;
#define STRUCT_Con_M__sTextIndent struct _Con_M__sTextIndent
struct _Con_M__sTextIndent {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__sTextIndent;
#define STRUCT_Con_M__sTextGroup struct _Con_M__sTextGroup
struct _Con_M__sTextGroup {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__sTextGroup;
#define STRUCT_Con_M__sTextSeparator struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M__sTextSeparator;
#define STRUCT_Con_M__sTextChars struct _Con_M__sTextChars
struct _Con_M__sTextChars {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__sTextChars;
extern struct _SortDescriptor sort_M_Text_Part;

/* DATA SORT VARIABLE_ENTRY HEADER DECLARATIONS. */
typedef enum {FunOf_M_VARIABLE_xENTRY = 0, VarOf_M_VARIABLE_xENTRY = 1, Data_M_SUB, Data_M_BOUND, Data_M_FRESHREUSE, Data_M_FRESH, Data_M_BOUNDREUSE, Data_M_FREE} EnumOf_M_VARIABLE_xENTRY;
#define STRUCT_Con_M_SUB struct _Con_M_SUB
struct _Con_M_SUB {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SUB;
#define STRUCT_Con_M_BOUND struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_BOUND;
#define STRUCT_Con_M_FRESHREUSE struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_FRESHREUSE;
#define STRUCT_Con_M_FRESH struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_FRESH;
#define STRUCT_Con_M_BOUNDREUSE struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_BOUNDREUSE;
#define STRUCT_Con_M_FREE struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_FREE;
extern struct _SortDescriptor sort_M_VARIABLE_xENTRY;

#ifdef __cplusplus
}
#endif
/* END OF C HEADER FOR CRSX CRSXC MODULE DATA. */
#endif
