 /* C HEADER FOR CRSX Cook MODULE . */
#ifndef CRSX__M_Cook_M__H
#define CRSX__M_Cook_M__H
#include "crsx.h"

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

/* DATA SORT $StringEntrySort HEADER DECLARATIONS. */
typedef enum {FunOf_M__sStringEntrySort = 0, VarOf_M__sStringEntrySort = 1, Data_M_STRING} EnumOf_M__sStringEntrySort;
#define STRUCT_Con_M_STRING struct _Con_M_STRING
struct _Con_M_STRING {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_STRING;
extern struct _SortDescriptor sort_M__sStringEntrySort;

/* DATA SORT $TryResult HEADER DECLARATIONS. */
typedef enum {FunOf_M__sTryResult = 0, VarOf_M__sTryResult = 1, Data_M__sTrySuccess, Data_M__sTryFailure} EnumOf_M__sTryResult;
#define STRUCT_Con_M__sTrySuccess struct _Con_M__sTrySuccess
struct _Con_M__sTrySuccess {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__sTrySuccess;
#define STRUCT_Con_M__sTryFailure struct _Con_M__sTryFailure
struct _Con_M__sTryFailure {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__sTryFailure;
extern struct _SortDescriptor sort_M__sTryResult;

/* DATA SORT ATTRIBUTE_MAP HEADER DECLARATIONS. */
typedef enum {FunOf_M_ATTRIBUTE_xMAP = 0, VarOf_M_ATTRIBUTE_xMAP = 1, Data_M_AM} EnumOf_M_ATTRIBUTE_xMAP;
#define STRUCT_Con_M_AM struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_AM;
extern struct _SortDescriptor sort_M_ATTRIBUTE_xMAP;

/* DATA SORT Boolean HEADER DECLARATIONS. */
typedef enum {FunOf_M_Boolean = 0, VarOf_M_Boolean = 1, Data_M_B_xTRUE, Data_M_B_xFALSE} EnumOf_M_Boolean;
#define STRUCT_Con_M_B_xTRUE struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_B_xTRUE;
#define STRUCT_Con_M_B_xFALSE struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_B_xFALSE;
extern struct _SortDescriptor sort_M_Boolean;

/* DATA SORT CONSUMPTION_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_CONSUMPTION_xSORT = 0, VarOf_M_CONSUMPTION_xSORT = 1, Data_M_C_xBUFFER, Data_M_C_xLEFTRECURSIVE} EnumOf_M_CONSUMPTION_xSORT;
#define STRUCT_Con_M_C_xBUFFER struct _Con_M_C_xBUFFER
struct _Con_M_C_xBUFFER {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_C_xBUFFER;
#define STRUCT_Con_M_C_xLEFTRECURSIVE struct _Con_M_C_xLEFTRECURSIVE
struct _Con_M_C_xLEFTRECURSIVE {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_C_xLEFTRECURSIVE;
extern struct _SortDescriptor sort_M_CONSUMPTION_xSORT;

/* DATA SORT DERIVED_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_DERIVED_xSORT = 0, VarOf_M_DERIVED_xSORT = 1, Data_M_DERIVED} EnumOf_M_DERIVED_xSORT;
#define STRUCT_Con_M_DERIVED struct _Con_M_DERIVED
struct _Con_M_DERIVED {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DERIVED;
extern struct _SortDescriptor sort_M_DERIVED_xSORT;

/* DATA SORT Define HEADER DECLARATIONS. */
typedef enum {FunOf_M_Define = 0, VarOf_M_Define = 1, Data_M_D_xFORM, Data_M_D_xNONE, Data_M_D_xABSTRACTION, Data_M_D_xRULE} EnumOf_M_Define;
#define STRUCT_Con_M_D_xFORM struct _Con_M_D_xFORM
struct _Con_M_D_xFORM {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_D_xFORM;
#define STRUCT_Con_M_D_xNONE struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_D_xNONE;
#define STRUCT_Con_M_D_xABSTRACTION struct _Con_M_D_xABSTRACTION
struct _Con_M_D_xABSTRACTION {struct _Construction construction; Term sub[1]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M_D_xABSTRACTION;
#define STRUCT_Con_M_D_xRULE struct _Con_M_D_xRULE
struct _Con_M_D_xRULE {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_D_xRULE;
extern struct _SortDescriptor sort_M_Define;

/* DATA SORT FormKind HEADER DECLARATIONS. */
typedef enum {FunOf_M_FormKind = 0, VarOf_M_FormKind = 1, Data_M_FK_xALIAS, Data_M_FK_xSYMBOL, Data_M_FK_xSUGAR, Data_M_FK_xSCHEME, Data_M_FK_xDATA} EnumOf_M_FormKind;
#define STRUCT_Con_M_FK_xALIAS struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_FK_xALIAS;
#define STRUCT_Con_M_FK_xSYMBOL struct _Con_M_FK_xSYMBOL
struct _Con_M_FK_xSYMBOL {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_FK_xSYMBOL;
#define STRUCT_Con_M_FK_xSUGAR struct _Con_M_FK_xSUGAR
struct _Con_M_FK_xSUGAR {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_FK_xSUGAR;
#define STRUCT_Con_M_FK_xSCHEME struct _Con_M_FK_xSCHEME
struct _Con_M_FK_xSCHEME {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_FK_xSCHEME;
#define STRUCT_Con_M_FK_xDATA struct _Con_M_FK_xDATA
struct _Con_M_FK_xDATA {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_FK_xDATA;
extern struct _SortDescriptor sort_M_FormKind;

/* DATA SORT Lifted HEADER DECLARATIONS. */
typedef enum {FunOf_M_Lifted = 0, VarOf_M_Lifted = 1, Data_M_BOTTOM, Data_M_LIFTED} EnumOf_M_Lifted;
#define STRUCT_Con_M_BOTTOM struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_BOTTOM;
#define STRUCT_Con_M_LIFTED struct _Con_M_LIFTED
struct _Con_M_LIFTED {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_LIFTED;
extern struct _SortDescriptor sort_M_Lifted;

/* DATA SORT NameSet HEADER DECLARATIONS. */
typedef enum {FunOf_M_NameSet = 0, VarOf_M_NameSet = 1, Data_M_NAME_xSET} EnumOf_M_NameSet;
#define STRUCT_Con_M_NAME_xSET struct _Con_M_NAME_xSET
struct _Con_M_NAME_xSET {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NAME_xSET;
extern struct _SortDescriptor sort_M_NameSet;

/* DATA SORT NormalizedSortMap HEADER DECLARATIONS. */
typedef enum {FunOf_M_NormalizedSortMap = 0, VarOf_M_NormalizedSortMap = 1, Data_M_NSM} EnumOf_M_NormalizedSortMap;
#define STRUCT_Con_M_NSM struct _Con_M_NSM
struct _Con_M_NSM {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NSM;
extern struct _SortDescriptor sort_M_NormalizedSortMap;

/* DATA SORT Ok HEADER DECLARATIONS. */
typedef enum {FunOf_M_Ok = 0, VarOf_M_Ok = 1, Data_M_OK} EnumOf_M_Ok;
#define STRUCT_Con_M_OK struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_OK;
extern struct _SortDescriptor sort_M_Ok;

/* DATA SORT PFK_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PFK_xSORT = 0, VarOf_M_PFK_xSORT = 1, Data_M_PFK} EnumOf_M_PFK_xSORT;
#define STRUCT_Con_M_PFK struct _Con_M_PFK
struct _Con_M_PFK {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PFK;
extern struct _SortDescriptor sort_M_PFK_xSORT;

/* DATA SORT PropsOf$AM_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sAM_xSORT = 0, VarOf_M_PropsOf_sAM_xSORT = 1, Data_M_PropsOf_sAM} EnumOf_M_PropsOf_sAM_xSORT;
#define STRUCT_Con_M_PropsOf_sAM struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sAM;
extern struct _SortDescriptor sort_M_PropsOf_sAM_xSORT;

/* DATA SORT PropsOf$D_ABSTRACTION_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sD_xABSTRACTION_xSORT = 0, VarOf_M_PropsOf_sD_xABSTRACTION_xSORT = 1, Data_M_PropsOf_sD_xABSTRACTION} EnumOf_M_PropsOf_sD_xABSTRACTION_xSORT;
#define STRUCT_Con_M_PropsOf_sD_xABSTRACTION struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sD_xABSTRACTION;
extern struct _SortDescriptor sort_M_PropsOf_sD_xABSTRACTION_xSORT;

/* DATA SORT PropsOf$D_FORM_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sD_xFORM_xSORT = 0, VarOf_M_PropsOf_sD_xFORM_xSORT = 1, Data_M_PropsOf_sD_xFORM} EnumOf_M_PropsOf_sD_xFORM_xSORT;
#define STRUCT_Con_M_PropsOf_sD_xFORM struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sD_xFORM;
extern struct _SortDescriptor sort_M_PropsOf_sD_xFORM_xSORT;

/* DATA SORT PropsOf$D_NONE_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sD_xNONE_xSORT = 0, VarOf_M_PropsOf_sD_xNONE_xSORT = 1, Data_M_PropsOf_sD_xNONE} EnumOf_M_PropsOf_sD_xNONE_xSORT;
#define STRUCT_Con_M_PropsOf_sD_xNONE struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sD_xNONE;
extern struct _SortDescriptor sort_M_PropsOf_sD_xNONE_xSORT;

/* DATA SORT PropsOf$D_RULE_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sD_xRULE_xSORT = 0, VarOf_M_PropsOf_sD_xRULE_xSORT = 1, Data_M_PropsOf_sD_xRULE} EnumOf_M_PropsOf_sD_xRULE_xSORT;
#define STRUCT_Con_M_PropsOf_sD_xRULE struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sD_xRULE;
extern struct _SortDescriptor sort_M_PropsOf_sD_xRULE_xSORT;

/* DATA SORT PropsOf$Declarations$Nil_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sDeclarations_sNil_xSORT = 0, VarOf_M_PropsOf_sDeclarations_sNil_xSORT = 1, Data_M_PropsOf_sDeclarations_sNil} EnumOf_M_PropsOf_sDeclarations_sNil_xSORT;
#define STRUCT_Con_M_PropsOf_sDeclarations_sNil struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sDeclarations_sNil;
extern struct _SortDescriptor sort_M_PropsOf_sDeclarations_sNil_xSORT;

/* DATA SORT PropsOf$NSM_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sNSM_xSORT = 0, VarOf_M_PropsOf_sNSM_xSORT = 1, Data_M_PropsOf_sNSM} EnumOf_M_PropsOf_sNSM_xSORT;
#define STRUCT_Con_M_PropsOf_sNSM struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sNSM;
extern struct _SortDescriptor sort_M_PropsOf_sNSM_xSORT;

/* DATA SORT PropsOf$OMITTED_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sOMITTED_xSORT = 0, VarOf_M_PropsOf_sOMITTED_xSORT = 1, Data_M_PropsOf_sOMITTED} EnumOf_M_PropsOf_sOMITTED_xSORT;
#define STRUCT_Con_M_PropsOf_sOMITTED struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sOMITTED;
extern struct _SortDescriptor sort_M_PropsOf_sOMITTED_xSORT;

/* DATA SORT PropsOf$RAW-AttributeFormMap_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_AttributeFormMap_xSORT = 0, VarOf_M_PropsOf_sRAW_AttributeFormMap_xSORT = 1, Data_M_PropsOf_sRAW_AttributeFormMap} EnumOf_M_PropsOf_sRAW_AttributeFormMap_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_AttributeFormMap struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_AttributeFormMap;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_AttributeFormMap_xSORT;

/* DATA SORT PropsOf$RAW-AttributeFormSet_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_AttributeFormSet_xSORT = 0, VarOf_M_PropsOf_sRAW_AttributeFormSet_xSORT = 1, Data_M_PropsOf_sRAW_AttributeFormSet} EnumOf_M_PropsOf_sRAW_AttributeFormSet_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_AttributeFormSet struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_AttributeFormSet;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_AttributeFormSet_xSORT;

/* DATA SORT PropsOf$RAW-AttributeFormSimple_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_AttributeFormSimple_xSORT = 0, VarOf_M_PropsOf_sRAW_AttributeFormSimple_xSORT = 1, Data_M_PropsOf_sRAW_AttributeFormSimple} EnumOf_M_PropsOf_sRAW_AttributeFormSimple_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_AttributeFormSimple struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_AttributeFormSimple;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_AttributeFormSimple_xSORT;

/* DATA SORT PropsOf$RAW-AttributeKeyValue_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_AttributeKeyValue_xSORT = 0, VarOf_M_PropsOf_sRAW_AttributeKeyValue_xSORT = 1, Data_M_PropsOf_sRAW_AttributeKeyValue} EnumOf_M_PropsOf_sRAW_AttributeKeyValue_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_AttributeKeyValue struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_AttributeKeyValue;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_AttributeKeyValue_xSORT;

/* DATA SORT PropsOf$RAW-AttributeKey_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_AttributeKey_xSORT = 0, VarOf_M_PropsOf_sRAW_AttributeKey_xSORT = 1, Data_M_PropsOf_sRAW_AttributeKey} EnumOf_M_PropsOf_sRAW_AttributeKey_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_AttributeKey struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_AttributeKey;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_AttributeKey_xSORT;

/* DATA SORT PropsOf$RAW-AttributeKindDown_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_AttributeKindDown_xSORT = 0, VarOf_M_PropsOf_sRAW_AttributeKindDown_xSORT = 1, Data_M_PropsOf_sRAW_AttributeKindDown} EnumOf_M_PropsOf_sRAW_AttributeKindDown_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_AttributeKindDown struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_AttributeKindDown;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_AttributeKindDown_xSORT;

/* DATA SORT PropsOf$RAW-AttributeKindUp_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_AttributeKindUp_xSORT = 0, VarOf_M_PropsOf_sRAW_AttributeKindUp_xSORT = 1, Data_M_PropsOf_sRAW_AttributeKindUp} EnumOf_M_PropsOf_sRAW_AttributeKindUp_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_AttributeKindUp struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_AttributeKindUp;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_AttributeKindUp_xSORT;

/* DATA SORT PropsOf$RAW-AttributeNotKey_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_AttributeNotKey_xSORT = 0, VarOf_M_PropsOf_sRAW_AttributeNotKey_xSORT = 1, Data_M_PropsOf_sRAW_AttributeNotKey} EnumOf_M_PropsOf_sRAW_AttributeNotKey_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_AttributeNotKey struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_AttributeNotKey;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_AttributeNotKey_xSORT;

/* DATA SORT PropsOf$RAW-AttributeOption_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_AttributeOption_xSORT = 0, VarOf_M_PropsOf_sRAW_AttributeOption_xSORT = 1, Data_M_PropsOf_sRAW_AttributeOption} EnumOf_M_PropsOf_sRAW_AttributeOption_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_AttributeOption struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_AttributeOption;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_AttributeOption_xSORT;

/* DATA SORT PropsOf$RAW-AttributeValue_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_AttributeValue_xSORT = 0, VarOf_M_PropsOf_sRAW_AttributeValue_xSORT = 1, Data_M_PropsOf_sRAW_AttributeValue} EnumOf_M_PropsOf_sRAW_AttributeValue_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_AttributeValue struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_AttributeValue;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_AttributeValue_xSORT;

/* DATA SORT PropsOf$RAW-Attribute_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_Attribute_xSORT = 0, VarOf_M_PropsOf_sRAW_Attribute_xSORT = 1, Data_M_PropsOf_sRAW_Attribute} EnumOf_M_PropsOf_sRAW_Attribute_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_Attribute struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_Attribute;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_Attribute_xSORT;

/* DATA SORT PropsOf$RAW-ConstructionSorted_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_ConstructionSorted_xSORT = 0, VarOf_M_PropsOf_sRAW_ConstructionSorted_xSORT = 1, Data_M_PropsOf_sRAW_ConstructionSorted} EnumOf_M_PropsOf_sRAW_ConstructionSorted_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_ConstructionSorted struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_ConstructionSorted;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_ConstructionSorted_xSORT;

/* DATA SORT PropsOf$RAW-Construction_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_Construction_xSORT = 0, VarOf_M_PropsOf_sRAW_Construction_xSORT = 1, Data_M_PropsOf_sRAW_Construction} EnumOf_M_PropsOf_sRAW_Construction_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_Construction struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_Construction;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_Construction_xSORT;

/* DATA SORT PropsOf$RAW-Declarations$Cons_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_Declarations_sCons_xSORT = 0, VarOf_M_PropsOf_sRAW_Declarations_sCons_xSORT = 1, Data_M_PropsOf_sRAW_Declarations_sCons} EnumOf_M_PropsOf_sRAW_Declarations_sCons_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_Declarations_sCons struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_Declarations_sCons;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_Declarations_sCons_xSORT;

/* DATA SORT PropsOf$RAW-FormConstruction_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_FormConstruction_xSORT = 0, VarOf_M_PropsOf_sRAW_FormConstruction_xSORT = 1, Data_M_PropsOf_sRAW_FormConstruction} EnumOf_M_PropsOf_sRAW_FormConstruction_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_FormConstruction struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_FormConstruction;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_FormConstruction_xSORT;

/* DATA SORT PropsOf$RAW-FormParsedSorted_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_FormParsedSorted_xSORT = 0, VarOf_M_PropsOf_sRAW_FormParsedSorted_xSORT = 1, Data_M_PropsOf_sRAW_FormParsedSorted} EnumOf_M_PropsOf_sRAW_FormParsedSorted_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_FormParsedSorted struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_FormParsedSorted;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_FormParsedSorted_xSORT;

/* DATA SORT PropsOf$RAW-FormParsedUnsorted_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_FormParsedUnsorted_xSORT = 0, VarOf_M_PropsOf_sRAW_FormParsedUnsorted_xSORT = 1, Data_M_PropsOf_sRAW_FormParsedUnsorted} EnumOf_M_PropsOf_sRAW_FormParsedUnsorted_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_FormParsedUnsorted struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_FormParsedUnsorted;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_FormParsedUnsorted_xSORT;

/* DATA SORT PropsOf$RAW-InheritedRef_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_InheritedRef_xSORT = 0, VarOf_M_PropsOf_sRAW_InheritedRef_xSORT = 1, Data_M_PropsOf_sRAW_InheritedRef} EnumOf_M_PropsOf_sRAW_InheritedRef_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_InheritedRef struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_InheritedRef;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_InheritedRef_xSORT;

/* DATA SORT PropsOf$RAW-Literal_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_Literal_xSORT = 0, VarOf_M_PropsOf_sRAW_Literal_xSORT = 1, Data_M_PropsOf_sRAW_Literal} EnumOf_M_PropsOf_sRAW_Literal_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_Literal struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_Literal;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_Literal_xSORT;

/* DATA SORT PropsOf$RAW-MetaApplicationSorted_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_MetaApplicationSorted_xSORT = 0, VarOf_M_PropsOf_sRAW_MetaApplicationSorted_xSORT = 1, Data_M_PropsOf_sRAW_MetaApplicationSorted} EnumOf_M_PropsOf_sRAW_MetaApplicationSorted_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_MetaApplicationSorted struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_MetaApplicationSorted;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_MetaApplicationSorted_xSORT;

/* DATA SORT PropsOf$RAW-MetaApplication_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_MetaApplication_xSORT = 0, VarOf_M_PropsOf_sRAW_MetaApplication_xSORT = 1, Data_M_PropsOf_sRAW_MetaApplication} EnumOf_M_PropsOf_sRAW_MetaApplication_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_MetaApplication struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_MetaApplication;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_MetaApplication_xSORT;

/* DATA SORT PropsOf$RAW-Normal_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_Normal_xSORT = 0, VarOf_M_PropsOf_sRAW_Normal_xSORT = 1, Data_M_PropsOf_sRAW_Normal} EnumOf_M_PropsOf_sRAW_Normal_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_Normal struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_Normal;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_Normal_xSORT;

/* DATA SORT PropsOf$RAW-ParsedDone_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_ParsedDone_xSORT = 0, VarOf_M_PropsOf_sRAW_ParsedDone_xSORT = 1, Data_M_PropsOf_sRAW_ParsedDone} EnumOf_M_PropsOf_sRAW_ParsedDone_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_ParsedDone struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_ParsedDone;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_ParsedDone_xSORT;

/* DATA SORT PropsOf$RAW-ParsedFormDone_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_ParsedFormDone_xSORT = 0, VarOf_M_PropsOf_sRAW_ParsedFormDone_xSORT = 1, Data_M_PropsOf_sRAW_ParsedFormDone} EnumOf_M_PropsOf_sRAW_ParsedFormDone_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_ParsedFormDone struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_ParsedFormDone;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_ParsedFormDone_xSORT;

/* DATA SORT PropsOf$RAW-ParsedFormSpace_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_ParsedFormSpace_xSORT = 0, VarOf_M_PropsOf_sRAW_ParsedFormSpace_xSORT = 1, Data_M_PropsOf_sRAW_ParsedFormSpace} EnumOf_M_PropsOf_sRAW_ParsedFormSpace_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_ParsedFormSpace struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_ParsedFormSpace;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_ParsedFormSpace_xSORT;

/* DATA SORT PropsOf$RAW-ParsedFormTerm_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_ParsedFormTerm_xSORT = 0, VarOf_M_PropsOf_sRAW_ParsedFormTerm_xSORT = 1, Data_M_PropsOf_sRAW_ParsedFormTerm} EnumOf_M_PropsOf_sRAW_ParsedFormTerm_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_ParsedFormTerm struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_ParsedFormTerm;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_ParsedFormTerm_xSORT;

/* DATA SORT PropsOf$RAW-ParsedFormWord_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_ParsedFormWord_xSORT = 0, VarOf_M_PropsOf_sRAW_ParsedFormWord_xSORT = 1, Data_M_PropsOf_sRAW_ParsedFormWord} EnumOf_M_PropsOf_sRAW_ParsedFormWord_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_ParsedFormWord struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_ParsedFormWord;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_ParsedFormWord_xSORT;

/* DATA SORT PropsOf$RAW-ParsedSorted_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_ParsedSorted_xSORT = 0, VarOf_M_PropsOf_sRAW_ParsedSorted_xSORT = 1, Data_M_PropsOf_sRAW_ParsedSorted} EnumOf_M_PropsOf_sRAW_ParsedSorted_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_ParsedSorted struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_ParsedSorted;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_ParsedSorted_xSORT;

/* DATA SORT PropsOf$RAW-ParsedTerm_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_ParsedTerm_xSORT = 0, VarOf_M_PropsOf_sRAW_ParsedTerm_xSORT = 1, Data_M_PropsOf_sRAW_ParsedTerm} EnumOf_M_PropsOf_sRAW_ParsedTerm_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_ParsedTerm struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_ParsedTerm;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_ParsedTerm_xSORT;

/* DATA SORT PropsOf$RAW-ParsedWord_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_ParsedWord_xSORT = 0, VarOf_M_PropsOf_sRAW_ParsedWord_xSORT = 1, Data_M_PropsOf_sRAW_ParsedWord} EnumOf_M_PropsOf_sRAW_ParsedWord_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_ParsedWord struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_ParsedWord;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_ParsedWord_xSORT;

/* DATA SORT PropsOf$RAW-Parsed_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_Parsed_xSORT = 0, VarOf_M_PropsOf_sRAW_Parsed_xSORT = 1, Data_M_PropsOf_sRAW_Parsed} EnumOf_M_PropsOf_sRAW_Parsed_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_Parsed struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_Parsed;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_Parsed_xSORT;

/* DATA SORT PropsOf$RAW-RegExpAny_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_RegExpAny_xSORT = 0, VarOf_M_PropsOf_sRAW_RegExpAny_xSORT = 1, Data_M_PropsOf_sRAW_RegExpAny} EnumOf_M_PropsOf_sRAW_RegExpAny_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_RegExpAny struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_RegExpAny;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_RegExpAny_xSORT;

/* DATA SORT PropsOf$RAW-RegExpClassChar_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_RegExpClassChar_xSORT = 0, VarOf_M_PropsOf_sRAW_RegExpClassChar_xSORT = 1, Data_M_PropsOf_sRAW_RegExpClassChar} EnumOf_M_PropsOf_sRAW_RegExpClassChar_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_RegExpClassChar struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_RegExpClassChar;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_RegExpClassChar_xSORT;

/* DATA SORT PropsOf$RAW-RegExpClassDone_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_RegExpClassDone_xSORT = 0, VarOf_M_PropsOf_sRAW_RegExpClassDone_xSORT = 1, Data_M_PropsOf_sRAW_RegExpClassDone} EnumOf_M_PropsOf_sRAW_RegExpClassDone_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_RegExpClassDone struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_RegExpClassDone;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_RegExpClassDone_xSORT;

/* DATA SORT PropsOf$RAW-RegExpClassNot_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_RegExpClassNot_xSORT = 0, VarOf_M_PropsOf_sRAW_RegExpClassNot_xSORT = 1, Data_M_PropsOf_sRAW_RegExpClassNot} EnumOf_M_PropsOf_sRAW_RegExpClassNot_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_RegExpClassNot struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_RegExpClassNot;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_RegExpClassNot_xSORT;

/* DATA SORT PropsOf$RAW-RegExpClassRange_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_RegExpClassRange_xSORT = 0, VarOf_M_PropsOf_sRAW_RegExpClassRange_xSORT = 1, Data_M_PropsOf_sRAW_RegExpClassRange} EnumOf_M_PropsOf_sRAW_RegExpClassRange_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_RegExpClassRange struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_RegExpClassRange;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_RegExpClassRange_xSORT;

/* DATA SORT PropsOf$RAW-RegExpClass_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_RegExpClass_xSORT = 0, VarOf_M_PropsOf_sRAW_RegExpClass_xSORT = 1, Data_M_PropsOf_sRAW_RegExpClass} EnumOf_M_PropsOf_sRAW_RegExpClass_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_RegExpClass struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_RegExpClass;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_RegExpClass_xSORT;

/* DATA SORT PropsOf$RAW-RegExpConcat_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_RegExpConcat_xSORT = 0, VarOf_M_PropsOf_sRAW_RegExpConcat_xSORT = 1, Data_M_PropsOf_sRAW_RegExpConcat} EnumOf_M_PropsOf_sRAW_RegExpConcat_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_RegExpConcat struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_RegExpConcat;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_RegExpConcat_xSORT;

/* DATA SORT PropsOf$RAW-RegExpNest_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_RegExpNest_xSORT = 0, VarOf_M_PropsOf_sRAW_RegExpNest_xSORT = 1, Data_M_PropsOf_sRAW_RegExpNest} EnumOf_M_PropsOf_sRAW_RegExpNest_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_RegExpNest struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_RegExpNest;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_RegExpNest_xSORT;

/* DATA SORT PropsOf$RAW-RegExpRef_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_RegExpRef_xSORT = 0, VarOf_M_PropsOf_sRAW_RegExpRef_xSORT = 1, Data_M_PropsOf_sRAW_RegExpRef} EnumOf_M_PropsOf_sRAW_RegExpRef_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_RegExpRef struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_RegExpRef;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_RegExpRef_xSORT;

/* DATA SORT PropsOf$RAW-RegExpString_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_RegExpString_xSORT = 0, VarOf_M_PropsOf_sRAW_RegExpString_xSORT = 1, Data_M_PropsOf_sRAW_RegExpString} EnumOf_M_PropsOf_sRAW_RegExpString_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_RegExpString struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_RegExpString;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_RegExpString_xSORT;

/* DATA SORT PropsOf$RAW-RegExpUnit_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_RegExpUnit_xSORT = 0, VarOf_M_PropsOf_sRAW_RegExpUnit_xSORT = 1, Data_M_PropsOf_sRAW_RegExpUnit} EnumOf_M_PropsOf_sRAW_RegExpUnit_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_RegExpUnit struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_RegExpUnit;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_RegExpUnit_xSORT;

/* DATA SORT PropsOf$RAW-RegExpWord_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_RegExpWord_xSORT = 0, VarOf_M_PropsOf_sRAW_RegExpWord_xSORT = 1, Data_M_PropsOf_sRAW_RegExpWord} EnumOf_M_PropsOf_sRAW_RegExpWord_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_RegExpWord struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_RegExpWord;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_RegExpWord_xSORT;

/* DATA SORT PropsOf$RAW-RepeatMaybeSome_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_RepeatMaybeSome_xSORT = 0, VarOf_M_PropsOf_sRAW_RepeatMaybeSome_xSORT = 1, Data_M_PropsOf_sRAW_RepeatMaybeSome} EnumOf_M_PropsOf_sRAW_RepeatMaybeSome_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_RepeatMaybeSome struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_RepeatMaybeSome;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_RepeatMaybeSome_xSORT;

/* DATA SORT PropsOf$RAW-RepeatMaybe_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_RepeatMaybe_xSORT = 0, VarOf_M_PropsOf_sRAW_RepeatMaybe_xSORT = 1, Data_M_PropsOf_sRAW_RepeatMaybe} EnumOf_M_PropsOf_sRAW_RepeatMaybe_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_RepeatMaybe struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_RepeatMaybe;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_RepeatMaybe_xSORT;

/* DATA SORT PropsOf$RAW-RepeatSingle_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_RepeatSingle_xSORT = 0, VarOf_M_PropsOf_sRAW_RepeatSingle_xSORT = 1, Data_M_PropsOf_sRAW_RepeatSingle} EnumOf_M_PropsOf_sRAW_RepeatSingle_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_RepeatSingle struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_RepeatSingle;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_RepeatSingle_xSORT;

/* DATA SORT PropsOf$RAW-RepeatSomeSep_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_RepeatSomeSep_xSORT = 0, VarOf_M_PropsOf_sRAW_RepeatSomeSep_xSORT = 1, Data_M_PropsOf_sRAW_RepeatSomeSep} EnumOf_M_PropsOf_sRAW_RepeatSomeSep_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_RepeatSomeSep struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_RepeatSomeSep;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_RepeatSomeSep_xSORT;

/* DATA SORT PropsOf$RAW-RepeatSome_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_RepeatSome_xSORT = 0, VarOf_M_PropsOf_sRAW_RepeatSome_xSORT = 1, Data_M_PropsOf_sRAW_RepeatSome} EnumOf_M_PropsOf_sRAW_RepeatSome_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_RepeatSome struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_RepeatSome;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_RepeatSome_xSORT;

/* DATA SORT PropsOf$RAW-Rule_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_Rule_xSORT = 0, VarOf_M_PropsOf_sRAW_Rule_xSORT = 1, Data_M_PropsOf_sRAW_Rule} EnumOf_M_PropsOf_sRAW_Rule_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_Rule struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_Rule;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_Rule_xSORT;

/* DATA SORT PropsOf$RAW-ScopeSortBinder_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_ScopeSortBinder_xSORT = 0, VarOf_M_PropsOf_sRAW_ScopeSortBinder_xSORT = 1, Data_M_PropsOf_sRAW_ScopeSortBinder} EnumOf_M_PropsOf_sRAW_ScopeSortBinder_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_ScopeSortBinder struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_ScopeSortBinder;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_ScopeSortBinder_xSORT;

/* DATA SORT PropsOf$RAW-ScopeSort_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_ScopeSort_xSORT = 0, VarOf_M_PropsOf_sRAW_ScopeSort_xSORT = 1, Data_M_PropsOf_sRAW_ScopeSort} EnumOf_M_PropsOf_sRAW_ScopeSort_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_ScopeSort struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_ScopeSort;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_ScopeSort_xSORT;

/* DATA SORT PropsOf$RAW-Scope_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_Scope_xSORT = 0, VarOf_M_PropsOf_sRAW_Scope_xSORT = 1, Data_M_PropsOf_sRAW_Scope} EnumOf_M_PropsOf_sRAW_Scope_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_Scope struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_Scope;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_Scope_xSORT;

/* DATA SORT PropsOf$RAW-SortAbstractionBody_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_SortAbstractionBody_xSORT = 0, VarOf_M_PropsOf_sRAW_SortAbstractionBody_xSORT = 1, Data_M_PropsOf_sRAW_SortAbstractionBody} EnumOf_M_PropsOf_sRAW_SortAbstractionBody_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_SortAbstractionBody struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_SortAbstractionBody;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_SortAbstractionBody_xSORT;

/* DATA SORT PropsOf$RAW-SortAbstractionParam_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_SortAbstractionParam_xSORT = 0, VarOf_M_PropsOf_sRAW_SortAbstractionParam_xSORT = 1, Data_M_PropsOf_sRAW_SortAbstractionParam} EnumOf_M_PropsOf_sRAW_SortAbstractionParam_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_SortAbstractionParam struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_SortAbstractionParam;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_SortAbstractionParam_xSORT;

/* DATA SORT PropsOf$RAW-SortName_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_SortName_xSORT = 0, VarOf_M_PropsOf_sRAW_SortName_xSORT = 1, Data_M_PropsOf_sRAW_SortName} EnumOf_M_PropsOf_sRAW_SortName_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_SortName struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_SortName;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_SortName_xSORT;

/* DATA SORT PropsOf$RAW-SortParam_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_SortParam_xSORT = 0, VarOf_M_PropsOf_sRAW_SortParam_xSORT = 1, Data_M_PropsOf_sRAW_SortParam} EnumOf_M_PropsOf_sRAW_SortParam_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_SortParam struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_SortParam;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_SortParam_xSORT;

/* DATA SORT PropsOf$RAW-Sort_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_Sort_xSORT = 0, VarOf_M_PropsOf_sRAW_Sort_xSORT = 1, Data_M_PropsOf_sRAW_Sort} EnumOf_M_PropsOf_sRAW_Sort_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_Sort struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_Sort;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_Sort_xSORT;

/* DATA SORT PropsOf$RAW-Special_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_Special_xSORT = 0, VarOf_M_PropsOf_sRAW_Special_xSORT = 1, Data_M_PropsOf_sRAW_Special} EnumOf_M_PropsOf_sRAW_Special_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_Special struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_Special;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_Special_xSORT;

/* DATA SORT PropsOf$RAW-SubstituteSort_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_SubstituteSort_xSORT = 0, VarOf_M_PropsOf_sRAW_SubstituteSort_xSORT = 1, Data_M_PropsOf_sRAW_SubstituteSort} EnumOf_M_PropsOf_sRAW_SubstituteSort_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_SubstituteSort struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_SubstituteSort;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_SubstituteSort_xSORT;

/* DATA SORT PropsOf$RAW-SynthesizedRef_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_SynthesizedRef_xSORT = 0, VarOf_M_PropsOf_sRAW_SynthesizedRef_xSORT = 1, Data_M_PropsOf_sRAW_SynthesizedRef} EnumOf_M_PropsOf_sRAW_SynthesizedRef_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_SynthesizedRef struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_SynthesizedRef;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_SynthesizedRef_xSORT;

/* DATA SORT PropsOf$RAW-VariableUseSorted_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_VariableUseSorted_xSORT = 0, VarOf_M_PropsOf_sRAW_VariableUseSorted_xSORT = 1, Data_M_PropsOf_sRAW_VariableUseSorted} EnumOf_M_PropsOf_sRAW_VariableUseSorted_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_VariableUseSorted struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_VariableUseSorted;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_VariableUseSorted_xSORT;

/* DATA SORT PropsOf$RAW-VariableUse_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW_VariableUse_xSORT = 0, VarOf_M_PropsOf_sRAW_VariableUse_xSORT = 1, Data_M_PropsOf_sRAW_VariableUse} EnumOf_M_PropsOf_sRAW_VariableUse_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW_VariableUse struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW_VariableUse;
extern struct _SortDescriptor sort_M_PropsOf_sRAW_VariableUse_xSORT;

/* DATA SORT PropsOf$RAW-anonymous_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW__anonymous_xSORT = 0, VarOf_M_PropsOf_sRAW__anonymous_xSORT = 1, Data_M_PropsOf_sRAW__anonymous} EnumOf_M_PropsOf_sRAW__anonymous_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW__anonymous struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__anonymous;
extern struct _SortDescriptor sort_M_PropsOf_sRAW__anonymous_xSORT;

/* DATA SORT PropsOf$RAW-attribute_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW__attribute_xSORT = 0, VarOf_M_PropsOf_sRAW__attribute_xSORT = 1, Data_M_PropsOf_sRAW__attribute} EnumOf_M_PropsOf_sRAW__attribute_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW__attribute struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__attribute;
extern struct _SortDescriptor sort_M_PropsOf_sRAW__attribute_xSORT;

/* DATA SORT PropsOf$RAW-data_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW__data_xSORT = 0, VarOf_M_PropsOf_sRAW__data_xSORT = 1, Data_M_PropsOf_sRAW__data} EnumOf_M_PropsOf_sRAW__data_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW__data struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__data;
extern struct _SortDescriptor sort_M_PropsOf_sRAW__data_xSORT;

/* DATA SORT PropsOf$RAW-default_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW__default_xSORT = 0, VarOf_M_PropsOf_sRAW__default_xSORT = 1, Data_M_PropsOf_sRAW__default} EnumOf_M_PropsOf_sRAW__default_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW__default struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__default;
extern struct _SortDescriptor sort_M_PropsOf_sRAW__default_xSORT;

/* DATA SORT PropsOf$RAW-embedded-module_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW__embedded__module_xSORT = 0, VarOf_M_PropsOf_sRAW__embedded__module_xSORT = 1, Data_M_PropsOf_sRAW__embedded__module} EnumOf_M_PropsOf_sRAW__embedded__module_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW__embedded__module struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__embedded__module;
extern struct _SortDescriptor sort_M_PropsOf_sRAW__embedded__module_xSORT;

/* DATA SORT PropsOf$RAW-fragment_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW__fragment_xSORT = 0, VarOf_M_PropsOf_sRAW__fragment_xSORT = 1, Data_M_PropsOf_sRAW__fragment} EnumOf_M_PropsOf_sRAW__fragment_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW__fragment struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__fragment;
extern struct _SortDescriptor sort_M_PropsOf_sRAW__fragment_xSORT;

/* DATA SORT PropsOf$RAW-import_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW__import_xSORT = 0, VarOf_M_PropsOf_sRAW__import_xSORT = 1, Data_M_PropsOf_sRAW__import} EnumOf_M_PropsOf_sRAW__import_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW__import struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__import;
extern struct _SortDescriptor sort_M_PropsOf_sRAW__import_xSORT;

/* DATA SORT PropsOf$RAW-module_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW__module_xSORT = 0, VarOf_M_PropsOf_sRAW__module_xSORT = 1, Data_M_PropsOf_sRAW__module} EnumOf_M_PropsOf_sRAW__module_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW__module struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__module;
extern struct _SortDescriptor sort_M_PropsOf_sRAW__module_xSORT;

/* DATA SORT PropsOf$RAW-nestedDeclarations_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW__nestedDeclarations_xSORT = 0, VarOf_M_PropsOf_sRAW__nestedDeclarations_xSORT = 1, Data_M_PropsOf_sRAW__nestedDeclarations} EnumOf_M_PropsOf_sRAW__nestedDeclarations_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW__nestedDeclarations struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__nestedDeclarations;
extern struct _SortDescriptor sort_M_PropsOf_sRAW__nestedDeclarations_xSORT;

/* DATA SORT PropsOf$RAW-nested_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW__nested_xSORT = 0, VarOf_M_PropsOf_sRAW__nested_xSORT = 1, Data_M_PropsOf_sRAW__nested} EnumOf_M_PropsOf_sRAW__nested_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW__nested struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__nested;
extern struct _SortDescriptor sort_M_PropsOf_sRAW__nested_xSORT;

/* DATA SORT PropsOf$RAW-priority_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW__priority_xSORT = 0, VarOf_M_PropsOf_sRAW__priority_xSORT = 1, Data_M_PropsOf_sRAW__priority} EnumOf_M_PropsOf_sRAW__priority_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW__priority struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__priority;
extern struct _SortDescriptor sort_M_PropsOf_sRAW__priority_xSORT;

/* DATA SORT PropsOf$RAW-rule_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW__rule_xSORT = 0, VarOf_M_PropsOf_sRAW__rule_xSORT = 1, Data_M_PropsOf_sRAW__rule} EnumOf_M_PropsOf_sRAW__rule_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW__rule struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__rule;
extern struct _SortDescriptor sort_M_PropsOf_sRAW__rule_xSORT;

/* DATA SORT PropsOf$RAW-scheme_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW__scheme_xSORT = 0, VarOf_M_PropsOf_sRAW__scheme_xSORT = 1, Data_M_PropsOf_sRAW__scheme} EnumOf_M_PropsOf_sRAW__scheme_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW__scheme struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__scheme;
extern struct _SortDescriptor sort_M_PropsOf_sRAW__scheme_xSORT;

/* DATA SORT PropsOf$RAW-sort_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW__sort_xSORT = 0, VarOf_M_PropsOf_sRAW__sort_xSORT = 1, Data_M_PropsOf_sRAW__sort} EnumOf_M_PropsOf_sRAW__sort_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW__sort struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__sort;
extern struct _SortDescriptor sort_M_PropsOf_sRAW__sort_xSORT;

/* DATA SORT PropsOf$RAW-space_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW__space_xSORT = 0, VarOf_M_PropsOf_sRAW__space_xSORT = 1, Data_M_PropsOf_sRAW__space} EnumOf_M_PropsOf_sRAW__space_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW__space struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__space;
extern struct _SortDescriptor sort_M_PropsOf_sRAW__space_xSORT;

/* DATA SORT PropsOf$RAW-static_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW__static_xSORT = 0, VarOf_M_PropsOf_sRAW__static_xSORT = 1, Data_M_PropsOf_sRAW__static} EnumOf_M_PropsOf_sRAW__static_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW__static struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__static;
extern struct _SortDescriptor sort_M_PropsOf_sRAW__static_xSORT;

/* DATA SORT PropsOf$RAW-sugar_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW__sugar_xSORT = 0, VarOf_M_PropsOf_sRAW__sugar_xSORT = 1, Data_M_PropsOf_sRAW__sugar} EnumOf_M_PropsOf_sRAW__sugar_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW__sugar struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__sugar;
extern struct _SortDescriptor sort_M_PropsOf_sRAW__sugar_xSORT;

/* DATA SORT PropsOf$RAW-symbol_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW__symbol_xSORT = 0, VarOf_M_PropsOf_sRAW__symbol_xSORT = 1, Data_M_PropsOf_sRAW__symbol} EnumOf_M_PropsOf_sRAW__symbol_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW__symbol struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__symbol;
extern struct _SortDescriptor sort_M_PropsOf_sRAW__symbol_xSORT;

/* DATA SORT PropsOf$RAW-synthesizedrefs_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW__synthesizedrefs_xSORT = 0, VarOf_M_PropsOf_sRAW__synthesizedrefs_xSORT = 1, Data_M_PropsOf_sRAW__synthesizedrefs} EnumOf_M_PropsOf_sRAW__synthesizedrefs_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW__synthesizedrefs struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__synthesizedrefs;
extern struct _SortDescriptor sort_M_PropsOf_sRAW__synthesizedrefs_xSORT;

/* DATA SORT PropsOf$RAW-token_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW__token_xSORT = 0, VarOf_M_PropsOf_sRAW__token_xSORT = 1, Data_M_PropsOf_sRAW__token} EnumOf_M_PropsOf_sRAW__token_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW__token struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__token;
extern struct _SortDescriptor sort_M_PropsOf_sRAW__token_xSORT;

/* DATA SORT PropsOf$RAW-top-module_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRAW__top__module_xSORT = 0, VarOf_M_PropsOf_sRAW__top__module_xSORT = 1, Data_M_PropsOf_sRAW__top__module} EnumOf_M_PropsOf_sRAW__top__module_xSORT;
#define STRUCT_Con_M_PropsOf_sRAW__top__module struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRAW__top__module;
extern struct _SortDescriptor sort_M_PropsOf_sRAW__top__module_xSORT;

/* DATA SORT PropsOf$RegExp$Cons_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRegExp_sCons_xSORT = 0, VarOf_M_PropsOf_sRegExp_sCons_xSORT = 1, Data_M_PropsOf_sRegExp_sCons} EnumOf_M_PropsOf_sRegExp_sCons_xSORT;
#define STRUCT_Con_M_PropsOf_sRegExp_sCons struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRegExp_sCons;
extern struct _SortDescriptor sort_M_PropsOf_sRegExp_sCons_xSORT;

/* DATA SORT PropsOf$RegExp$Nil_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sRegExp_sNil_xSORT = 0, VarOf_M_PropsOf_sRegExp_sNil_xSORT = 1, Data_M_PropsOf_sRegExp_sNil} EnumOf_M_PropsOf_sRegExp_sNil_xSORT;
#define STRUCT_Con_M_PropsOf_sRegExp_sNil struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sRegExp_sNil;
extern struct _SortDescriptor sort_M_PropsOf_sRegExp_sNil_xSORT;

/* DATA SORT PropsOf$TEXT_MAP_SORT HEADER DECLARATIONS. */
typedef enum {FunOf_M_PropsOf_sTEXT_xMAP_xSORT = 0, VarOf_M_PropsOf_sTEXT_xMAP_xSORT = 1, Data_M_PropsOf_sTEXT_xMAP} EnumOf_M_PropsOf_sTEXT_xMAP_xSORT;
#define STRUCT_Con_M_PropsOf_sTEXT_xMAP struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PropsOf_sTEXT_xMAP;
extern struct _SortDescriptor sort_M_PropsOf_sTEXT_xMAP_xSORT;

/* DATA SORT RawAttribute HEADER DECLARATIONS. */
typedef enum {FunOf_M_RawAttribute = 0, VarOf_M_RawAttribute = 1, Data_M_RAW_Attribute} EnumOf_M_RawAttribute;
#define STRUCT_Con_M_RAW_Attribute struct _Con_M_RAW_Attribute
struct _Con_M_RAW_Attribute {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_Attribute;
extern struct _SortDescriptor sort_M_RawAttribute;

/* DATA SORT RawAttributeForm HEADER DECLARATIONS. */
typedef enum {FunOf_M_RawAttributeForm = 0, VarOf_M_RawAttributeForm = 1, Data_M_RAW_AttributeFormMap, Data_M_RAW_AttributeFormSet, Data_M_RAW_AttributeFormSimple} EnumOf_M_RawAttributeForm;
#define STRUCT_Con_M_RAW_AttributeFormMap struct _Con_M_RAW_AttributeFormMap
struct _Con_M_RAW_AttributeFormMap {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_AttributeFormMap;
#define STRUCT_Con_M_RAW_AttributeFormSet struct _Con_M_RAW_AttributeFormSet
struct _Con_M_RAW_AttributeFormSet {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_AttributeFormSet;
#define STRUCT_Con_M_RAW_AttributeFormSimple struct _Con_M_RAW_AttributeFormSimple
struct _Con_M_RAW_AttributeFormSimple {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_AttributeFormSimple;
extern struct _SortDescriptor sort_M_RawAttributeForm;

/* DATA SORT RawAttributeKind HEADER DECLARATIONS. */
typedef enum {FunOf_M_RawAttributeKind = 0, VarOf_M_RawAttributeKind = 1, Data_M_RAW_AttributeKindDown, Data_M_RAW_AttributeKindUp} EnumOf_M_RawAttributeKind;
#define STRUCT_Con_M_RAW_AttributeKindDown struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_RAW_AttributeKindDown;
#define STRUCT_Con_M_RAW_AttributeKindUp struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_RAW_AttributeKindUp;
extern struct _SortDescriptor sort_M_RawAttributeKind;

/* DATA SORT RawAttributeOption HEADER DECLARATIONS. */
typedef enum {FunOf_M_RawAttributeOption = 0, VarOf_M_RawAttributeOption = 1, Data_M_RAW_AttributeOption} EnumOf_M_RawAttributeOption;
#define STRUCT_Con_M_RAW_AttributeOption struct _Con_M_RAW_AttributeOption
struct _Con_M_RAW_AttributeOption {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_AttributeOption;
extern struct _SortDescriptor sort_M_RawAttributeOption;

/* DATA SORT RawAttributeValue HEADER DECLARATIONS. */
typedef enum {FunOf_M_RawAttributeValue = 0, VarOf_M_RawAttributeValue = 1, Data_M_RAW_AttributeValue, Data_M_RAW_AttributeKey, Data_M_RAW_AttributeKeyValue, Data_M_RAW_AttributeNotKey} EnumOf_M_RawAttributeValue;
#define STRUCT_Con_M_RAW_AttributeValue struct _Con_M_RAW_AttributeValue
struct _Con_M_RAW_AttributeValue {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_AttributeValue;
#define STRUCT_Con_M_RAW_AttributeKey struct _Con_M_RAW_AttributeKey
struct _Con_M_RAW_AttributeKey {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_AttributeKey;
#define STRUCT_Con_M_RAW_AttributeKeyValue struct _Con_M_RAW_AttributeKeyValue
struct _Con_M_RAW_AttributeKeyValue {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_AttributeKeyValue;
#define STRUCT_Con_M_RAW_AttributeNotKey struct _Con_M_RAW_AttributeNotKey
struct _Con_M_RAW_AttributeNotKey {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_AttributeNotKey;
extern struct _SortDescriptor sort_M_RawAttributeValue;

/* DATA SORT RawDeclaration HEADER DECLARATIONS. */
typedef enum {FunOf_M_RawDeclaration = 0, VarOf_M_RawDeclaration = 1, Data_M_RAW__nestedDeclarations, Data_M_RAW__space, Data_M_RAW__import, Data_M_RAW__embedded__module, Data_M_RAW__rule, Data_M_RAW__attribute, Data_M_RAW__fragment, Data_M_RAW__synthesizedrefs, Data_M_RAW__token, Data_M_RAW__sort, Data_M_RAW__anonymous} EnumOf_M_RawDeclaration;
#define STRUCT_Con_M_RAW__nestedDeclarations struct _Con_M_RAW__nestedDeclarations
struct _Con_M_RAW__nestedDeclarations {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW__nestedDeclarations;
#define STRUCT_Con_M_RAW__space struct _Con_M_RAW__space
struct _Con_M_RAW__space {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW__space;
#define STRUCT_Con_M_RAW__import struct _Con_M_RAW__import
struct _Con_M_RAW__import {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW__import;
#define STRUCT_Con_M_RAW__embedded__module struct _Con_M_RAW__embedded__module
struct _Con_M_RAW__embedded__module {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW__embedded__module;
#define STRUCT_Con_M_RAW__rule struct _Con_M_RAW__rule
struct _Con_M_RAW__rule {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW__rule;
#define STRUCT_Con_M_RAW__attribute struct _Con_M_RAW__attribute
struct _Con_M_RAW__attribute {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW__attribute;
#define STRUCT_Con_M_RAW__fragment struct _Con_M_RAW__fragment
struct _Con_M_RAW__fragment {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW__fragment;
#define STRUCT_Con_M_RAW__synthesizedrefs struct _Con_M_RAW__synthesizedrefs
struct _Con_M_RAW__synthesizedrefs {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW__synthesizedrefs;
#define STRUCT_Con_M_RAW__token struct _Con_M_RAW__token
struct _Con_M_RAW__token {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW__token;
#define STRUCT_Con_M_RAW__sort struct _Con_M_RAW__sort
struct _Con_M_RAW__sort {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW__sort;
#define STRUCT_Con_M_RAW__anonymous struct _Con_M_RAW__anonymous
struct _Con_M_RAW__anonymous {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW__anonymous;
extern struct _SortDescriptor sort_M_RawDeclaration;

/* DATA SORT RawDeclarations HEADER DECLARATIONS. */
typedef enum {FunOf_M_RawDeclarations = 0, VarOf_M_RawDeclarations = 1, Data_M_Declarations_sNil, Data_M_RAW_Declarations_sCons} EnumOf_M_RawDeclarations;
#define STRUCT_Con_M_Declarations_sNil struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_Declarations_sNil;
#define STRUCT_Con_M_RAW_Declarations_sCons struct _Con_M_RAW_Declarations_sCons
struct _Con_M_RAW_Declarations_sCons {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_Declarations_sCons;
extern struct _SortDescriptor sort_M_RawDeclarations;

/* DATA SORT RawEmbeddedModule HEADER DECLARATIONS. */
typedef enum {FunOf_M_RawEmbeddedModule = 0, VarOf_M_RawEmbeddedModule = 1, Data_M_RAW__module} EnumOf_M_RawEmbeddedModule;
#define STRUCT_Con_M_RAW__module struct _Con_M_RAW__module
struct _Con_M_RAW__module {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW__module;
extern struct _SortDescriptor sort_M_RawEmbeddedModule;

/* DATA SORT RawForm HEADER DECLARATIONS. */
typedef enum {FunOf_M_RawForm = 0, VarOf_M_RawForm = 1, Data_M_RAW_FormParsedSorted, Data_M_RAW_FormConstruction, Data_M_RAW_FormParsedUnsorted} EnumOf_M_RawForm;
#define STRUCT_Con_M_RAW_FormParsedSorted struct _Con_M_RAW_FormParsedSorted
struct _Con_M_RAW_FormParsedSorted {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_FormParsedSorted;
#define STRUCT_Con_M_RAW_FormConstruction struct _Con_M_RAW_FormConstruction
struct _Con_M_RAW_FormConstruction {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_FormConstruction;
#define STRUCT_Con_M_RAW_FormParsedUnsorted struct _Con_M_RAW_FormParsedUnsorted
struct _Con_M_RAW_FormParsedUnsorted {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_FormParsedUnsorted;
extern struct _SortDescriptor sort_M_RawForm;

/* DATA SORT RawInheritedRef HEADER DECLARATIONS. */
typedef enum {FunOf_M_RawInheritedRef = 0, VarOf_M_RawInheritedRef = 1, Data_M_RAW_InheritedRef} EnumOf_M_RawInheritedRef;
#define STRUCT_Con_M_RAW_InheritedRef struct _Con_M_RAW_InheritedRef
struct _Con_M_RAW_InheritedRef {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_InheritedRef;
extern struct _SortDescriptor sort_M_RawInheritedRef;

/* DATA SORT RawModule HEADER DECLARATIONS. */
typedef enum {FunOf_M_RawModule = 0, VarOf_M_RawModule = 1, Data_M_RAW__top__module} EnumOf_M_RawModule;
#define STRUCT_Con_M_RAW__top__module struct _Con_M_RAW__top__module
struct _Con_M_RAW__top__module {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW__top__module;
extern struct _SortDescriptor sort_M_RawModule;

/* DATA SORT RawParsed HEADER DECLARATIONS. */
typedef enum {FunOf_M_RawParsed = 0, VarOf_M_RawParsed = 1, Data_M_RAW_ParsedTerm, Data_M_RAW_ParsedDone, Data_M_RAW_ParsedWord} EnumOf_M_RawParsed;
#define STRUCT_Con_M_RAW_ParsedTerm struct _Con_M_RAW_ParsedTerm
struct _Con_M_RAW_ParsedTerm {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_ParsedTerm;
#define STRUCT_Con_M_RAW_ParsedDone struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_RAW_ParsedDone;
#define STRUCT_Con_M_RAW_ParsedWord struct _Con_M_RAW_ParsedWord
struct _Con_M_RAW_ParsedWord {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_ParsedWord;
extern struct _SortDescriptor sort_M_RawParsed;

/* DATA SORT RawParsedForm HEADER DECLARATIONS. */
typedef enum {FunOf_M_RawParsedForm = 0, VarOf_M_RawParsedForm = 1, Data_M_RAW_ParsedFormTerm, Data_M_RAW_ParsedFormWord, Data_M_RAW_ParsedFormDone, Data_M_RAW_ParsedFormSpace} EnumOf_M_RawParsedForm;
#define STRUCT_Con_M_RAW_ParsedFormTerm struct _Con_M_RAW_ParsedFormTerm
struct _Con_M_RAW_ParsedFormTerm {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_ParsedFormTerm;
#define STRUCT_Con_M_RAW_ParsedFormWord struct _Con_M_RAW_ParsedFormWord
struct _Con_M_RAW_ParsedFormWord {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_ParsedFormWord;
#define STRUCT_Con_M_RAW_ParsedFormDone struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_RAW_ParsedFormDone;
#define STRUCT_Con_M_RAW_ParsedFormSpace struct _Con_M_RAW_ParsedFormSpace
struct _Con_M_RAW_ParsedFormSpace {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_ParsedFormSpace;
extern struct _SortDescriptor sort_M_RawParsedForm;

/* DATA SORT RawPriority HEADER DECLARATIONS. */
typedef enum {FunOf_M_RawPriority = 0, VarOf_M_RawPriority = 1, Data_M_RAW__default, Data_M_RAW__priority, Data_M_RAW_Normal} EnumOf_M_RawPriority;
#define STRUCT_Con_M_RAW__default struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_RAW__default;
#define STRUCT_Con_M_RAW__priority struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_RAW__priority;
#define STRUCT_Con_M_RAW_Normal struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_RAW_Normal;
extern struct _SortDescriptor sort_M_RawPriority;

/* DATA SORT RawRegExp HEADER DECLARATIONS. */
typedef enum {FunOf_M_RawRegExp = 0, VarOf_M_RawRegExp = 1, Data_M_RegExp_sCons, Data_M_RegExp_sNil} EnumOf_M_RawRegExp;
#define STRUCT_Con_M_RegExp_sCons struct _Con_M_RegExp_sCons
struct _Con_M_RegExp_sCons {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RegExp_sCons;
#define STRUCT_Con_M_RegExp_sNil struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_RegExp_sNil;
extern struct _SortDescriptor sort_M_RawRegExp;

/* DATA SORT RawRegExpChoice HEADER DECLARATIONS. */
typedef enum {FunOf_M_RawRegExpChoice = 0, VarOf_M_RawRegExpChoice = 1, Data_M_RAW__nested, Data_M_RAW_RegExpConcat} EnumOf_M_RawRegExpChoice;
#define STRUCT_Con_M_RAW__nested struct _Con_M_RAW__nested
struct _Con_M_RAW__nested {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW__nested;
#define STRUCT_Con_M_RAW_RegExpConcat struct _Con_M_RAW_RegExpConcat
struct _Con_M_RAW_RegExpConcat {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_RegExpConcat;
extern struct _SortDescriptor sort_M_RawRegExpChoice;

/* DATA SORT RawRegExpClass HEADER DECLARATIONS. */
typedef enum {FunOf_M_RawRegExpClass = 0, VarOf_M_RawRegExpClass = 1, Data_M_RAW_RegExpClassDone, Data_M_RAW_RegExpClassNot, Data_M_RAW_RegExpClassRange, Data_M_RAW_RegExpClassChar} EnumOf_M_RawRegExpClass;
#define STRUCT_Con_M_RAW_RegExpClassDone struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_RAW_RegExpClassDone;
#define STRUCT_Con_M_RAW_RegExpClassNot struct _Con_M_RAW_RegExpClassNot
struct _Con_M_RAW_RegExpClassNot {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_RegExpClassNot;
#define STRUCT_Con_M_RAW_RegExpClassRange struct _Con_M_RAW_RegExpClassRange
struct _Con_M_RAW_RegExpClassRange {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_RegExpClassRange;
#define STRUCT_Con_M_RAW_RegExpClassChar struct _Con_M_RAW_RegExpClassChar
struct _Con_M_RAW_RegExpClassChar {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_RegExpClassChar;
extern struct _SortDescriptor sort_M_RawRegExpClass;

/* DATA SORT RawRegExpSimple HEADER DECLARATIONS. */
typedef enum {FunOf_M_RawRegExpSimple = 0, VarOf_M_RawRegExpSimple = 1, Data_M_RAW_RegExpClass, Data_M_RAW_RegExpRef, Data_M_RAW_RegExpAny, Data_M_RAW_RegExpWord, Data_M_RAW_RegExpString, Data_M_RAW_RegExpNest} EnumOf_M_RawRegExpSimple;
#define STRUCT_Con_M_RAW_RegExpClass struct _Con_M_RAW_RegExpClass
struct _Con_M_RAW_RegExpClass {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_RegExpClass;
#define STRUCT_Con_M_RAW_RegExpRef struct _Con_M_RAW_RegExpRef
struct _Con_M_RAW_RegExpRef {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_RegExpRef;
#define STRUCT_Con_M_RAW_RegExpAny struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_RAW_RegExpAny;
#define STRUCT_Con_M_RAW_RegExpWord struct _Con_M_RAW_RegExpWord
struct _Con_M_RAW_RegExpWord {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_RegExpWord;
#define STRUCT_Con_M_RAW_RegExpString struct _Con_M_RAW_RegExpString
struct _Con_M_RAW_RegExpString {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_RegExpString;
#define STRUCT_Con_M_RAW_RegExpNest struct _Con_M_RAW_RegExpNest
struct _Con_M_RAW_RegExpNest {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_RegExpNest;
extern struct _SortDescriptor sort_M_RawRegExpSimple;

/* DATA SORT RawRegExpUnit HEADER DECLARATIONS. */
typedef enum {FunOf_M_RawRegExpUnit = 0, VarOf_M_RawRegExpUnit = 1, Data_M_RAW_RegExpUnit} EnumOf_M_RawRegExpUnit;
#define STRUCT_Con_M_RAW_RegExpUnit struct _Con_M_RAW_RegExpUnit
struct _Con_M_RAW_RegExpUnit {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_RegExpUnit;
extern struct _SortDescriptor sort_M_RawRegExpUnit;

/* DATA SORT RawRepeat HEADER DECLARATIONS. */
typedef enum {FunOf_M_RawRepeat = 0, VarOf_M_RawRepeat = 1, Data_M_RAW_RepeatSomeSep, Data_M_RAW_RepeatSome, Data_M_RAW_RepeatSingle, Data_M_RAW_RepeatMaybe, Data_M_RAW_RepeatMaybeSome} EnumOf_M_RawRepeat;
#define STRUCT_Con_M_RAW_RepeatSomeSep struct _Con_M_RAW_RepeatSomeSep
struct _Con_M_RAW_RepeatSomeSep {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_RepeatSomeSep;
#define STRUCT_Con_M_RAW_RepeatSome struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_RAW_RepeatSome;
#define STRUCT_Con_M_RAW_RepeatSingle struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_RAW_RepeatSingle;
#define STRUCT_Con_M_RAW_RepeatMaybe struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_RAW_RepeatMaybe;
#define STRUCT_Con_M_RAW_RepeatMaybeSome struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_RAW_RepeatMaybeSome;
extern struct _SortDescriptor sort_M_RawRepeat;

/* DATA SORT RawRule HEADER DECLARATIONS. */
typedef enum {FunOf_M_RawRule = 0, VarOf_M_RawRule = 1, Data_M_RAW_Rule} EnumOf_M_RawRule;
#define STRUCT_Con_M_RAW_Rule struct _Con_M_RAW_Rule
struct _Con_M_RAW_Rule {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_Rule;
extern struct _SortDescriptor sort_M_RawRule;

/* DATA SORT RawScope HEADER DECLARATIONS. */
typedef enum {FunOf_M_RawScope = 0, VarOf_M_RawScope = 1, Data_M_RAW_Scope} EnumOf_M_RawScope;
#define STRUCT_Con_M_RAW_Scope struct _Con_M_RAW_Scope
struct _Con_M_RAW_Scope {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_Scope;
extern struct _SortDescriptor sort_M_RawScope;

/* DATA SORT RawScopeSort HEADER DECLARATIONS. */
typedef enum {FunOf_M_RawScopeSort = 0, VarOf_M_RawScopeSort = 1, Data_M_RAW_ScopeSortBinder, Data_M_RAW_ScopeSort} EnumOf_M_RawScopeSort;
#define STRUCT_Con_M_RAW_ScopeSortBinder struct _Con_M_RAW_ScopeSortBinder
struct _Con_M_RAW_ScopeSortBinder {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_ScopeSortBinder;
#define STRUCT_Con_M_RAW_ScopeSort struct _Con_M_RAW_ScopeSort
struct _Con_M_RAW_ScopeSort {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_ScopeSort;
extern struct _SortDescriptor sort_M_RawScopeSort;

/* DATA SORT RawSort HEADER DECLARATIONS. */
typedef enum {FunOf_M_RawSort = 0, VarOf_M_RawSort = 1, Data_M_RAW_SortParam, Data_M_RAW_SortName, Data_M_RAW_Sort} EnumOf_M_RawSort;
#define STRUCT_Con_M_RAW_SortParam struct _Con_M_RAW_SortParam
struct _Con_M_RAW_SortParam {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_SortParam;
#define STRUCT_Con_M_RAW_SortName struct _Con_M_RAW_SortName
struct _Con_M_RAW_SortName {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_SortName;
#define STRUCT_Con_M_RAW_Sort struct _Con_M_RAW_Sort
struct _Con_M_RAW_Sort {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_Sort;
extern struct _SortDescriptor sort_M_RawSort;

/* DATA SORT RawSortAbstraction HEADER DECLARATIONS. */
typedef enum {FunOf_M_RawSortAbstraction = 0, VarOf_M_RawSortAbstraction = 1, Data_M_RAW_SortAbstractionParam, Data_M_RAW_SortAbstractionBody} EnumOf_M_RawSortAbstraction;
#define STRUCT_Con_M_RAW_SortAbstractionParam struct _Con_M_RAW_SortAbstractionParam
struct _Con_M_RAW_SortAbstractionParam {struct _Construction construction; Term sub[1]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M_RAW_SortAbstractionParam;
#define STRUCT_Con_M_RAW_SortAbstractionBody struct _Con_M_RAW_SortAbstractionBody
struct _Con_M_RAW_SortAbstractionBody {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_SortAbstractionBody;
extern struct _SortDescriptor sort_M_RawSortAbstraction;

/* DATA SORT RawSortAlternative HEADER DECLARATIONS. */
typedef enum {FunOf_M_RawSortAlternative = 0, VarOf_M_RawSortAlternative = 1, Data_M_RAW__static, Data_M_RAW__sugar, Data_M_RAW__scheme, Data_M_RAW__symbol, Data_M_RAW__data} EnumOf_M_RawSortAlternative;
#define STRUCT_Con_M_RAW__static struct _Con_M_RAW__static
struct _Con_M_RAW__static {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW__static;
#define STRUCT_Con_M_RAW__sugar struct _Con_M_RAW__sugar
struct _Con_M_RAW__sugar {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW__sugar;
#define STRUCT_Con_M_RAW__scheme struct _Con_M_RAW__scheme
struct _Con_M_RAW__scheme {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW__scheme;
#define STRUCT_Con_M_RAW__symbol struct _Con_M_RAW__symbol
struct _Con_M_RAW__symbol {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW__symbol;
#define STRUCT_Con_M_RAW__data struct _Con_M_RAW__data
struct _Con_M_RAW__data {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW__data;
extern struct _SortDescriptor sort_M_RawSortAlternative;

/* DATA SORT RawSubstituteSort HEADER DECLARATIONS. */
typedef enum {FunOf_M_RawSubstituteSort = 0, VarOf_M_RawSubstituteSort = 1, Data_M_RAW_SubstituteSort} EnumOf_M_RawSubstituteSort;
#define STRUCT_Con_M_RAW_SubstituteSort struct _Con_M_RAW_SubstituteSort
struct _Con_M_RAW_SubstituteSort {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_SubstituteSort;
extern struct _SortDescriptor sort_M_RawSubstituteSort;

/* DATA SORT RawSynthesizedRef HEADER DECLARATIONS. */
typedef enum {FunOf_M_RawSynthesizedRef = 0, VarOf_M_RawSynthesizedRef = 1, Data_M_RAW_SynthesizedRef} EnumOf_M_RawSynthesizedRef;
#define STRUCT_Con_M_RAW_SynthesizedRef struct _Con_M_RAW_SynthesizedRef
struct _Con_M_RAW_SynthesizedRef {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_SynthesizedRef;
extern struct _SortDescriptor sort_M_RawSynthesizedRef;

/* DATA SORT RawTerm HEADER DECLARATIONS. */
typedef enum {FunOf_M_RawTerm = 0, VarOf_M_RawTerm = 1, Data_M_RAW_VariableUseSorted, Data_M_RAW_Parsed, Data_M_RAW_Literal, Data_M_RAW_ParsedSorted, Data_M_RAW_Construction, Data_M_RAW_ConstructionSorted, Data_M_RAW_MetaApplication, Data_M_RAW_MetaApplicationSorted, Data_M_RAW_Special, Data_M_OMITTED, Data_M_RAW_VariableUse} EnumOf_M_RawTerm;
#define STRUCT_Con_M_RAW_VariableUseSorted struct _Con_M_RAW_VariableUseSorted
struct _Con_M_RAW_VariableUseSorted {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_VariableUseSorted;
#define STRUCT_Con_M_RAW_Parsed struct _Con_M_RAW_Parsed
struct _Con_M_RAW_Parsed {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_Parsed;
#define STRUCT_Con_M_RAW_Literal struct _Con_M_RAW_Literal
struct _Con_M_RAW_Literal {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_Literal;
#define STRUCT_Con_M_RAW_ParsedSorted struct _Con_M_RAW_ParsedSorted
struct _Con_M_RAW_ParsedSorted {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_ParsedSorted;
#define STRUCT_Con_M_RAW_Construction struct _Con_M_RAW_Construction
struct _Con_M_RAW_Construction {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_Construction;
#define STRUCT_Con_M_RAW_ConstructionSorted struct _Con_M_RAW_ConstructionSorted
struct _Con_M_RAW_ConstructionSorted {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_ConstructionSorted;
#define STRUCT_Con_M_RAW_MetaApplication struct _Con_M_RAW_MetaApplication
struct _Con_M_RAW_MetaApplication {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_MetaApplication;
#define STRUCT_Con_M_RAW_MetaApplicationSorted struct _Con_M_RAW_MetaApplicationSorted
struct _Con_M_RAW_MetaApplicationSorted {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_MetaApplicationSorted;
#define STRUCT_Con_M_RAW_Special struct _Con_M_RAW_Special
struct _Con_M_RAW_Special {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_Special;
#define STRUCT_Con_M_OMITTED struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_OMITTED;
#define STRUCT_Con_M_RAW_VariableUse struct _Con_M_RAW_VariableUse
struct _Con_M_RAW_VariableUse {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RAW_VariableUse;
extern struct _SortDescriptor sort_M_RawTerm;

/* DATA SORT RefMode HEADER DECLARATIONS. */
typedef enum {FunOf_M_RefMode = 0, VarOf_M_RefMode = 1, Data_M_RM_xNONE, Data_M_RM_xALL, Data_M_RM_xONLY_xTOP} EnumOf_M_RefMode;
#define STRUCT_Con_M_RM_xNONE struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_RM_xNONE;
#define STRUCT_Con_M_RM_xALL struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_RM_xALL;
#define STRUCT_Con_M_RM_xONLY_xTOP struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_RM_xONLY_xTOP;
extern struct _SortDescriptor sort_M_RefMode;

/* DATA SORT SortEntry HEADER DECLARATIONS. */
typedef enum {FunOf_M_SortEntry = 0, VarOf_M_SortEntry = 1, Data_M_SE_xNONE, Data_M_NAMES, Data_M_SE_xTOKEN, Data_M_SE_xATTRIBUTE, Data_M_SE_xSORT} EnumOf_M_SortEntry;
#define STRUCT_Con_M_SE_xNONE struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_SE_xNONE;
#define STRUCT_Con_M_NAMES struct _Con_M_NAMES
struct _Con_M_NAMES {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NAMES;
#define STRUCT_Con_M_SE_xTOKEN struct _Con_M_SE_xTOKEN
struct _Con_M_SE_xTOKEN {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SE_xTOKEN;
#define STRUCT_Con_M_SE_xATTRIBUTE struct _Con_M_SE_xATTRIBUTE
struct _Con_M_SE_xATTRIBUTE {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SE_xATTRIBUTE;
#define STRUCT_Con_M_SE_xSORT struct _Con_M_SE_xSORT
struct _Con_M_SE_xSORT {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SE_xSORT;
extern struct _SortDescriptor sort_M_SortEntry;

/* DATA SORT Text HEADER DECLARATIONS. */
typedef enum {FunOf_M_Text = 0, VarOf_M_Text = 1, Data_M__sTextNil, Data_M__sTextCons} EnumOf_M_Text;
#define STRUCT_Con_M__sTextNil struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M__sTextNil;
#define STRUCT_Con_M__sTextCons struct _Con_M__sTextCons
struct _Con_M__sTextCons {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__sTextCons;
extern struct _SortDescriptor sort_M_Text;

/* DATA SORT Text-Part HEADER DECLARATIONS. */
typedef enum {FunOf_M_Text_Part = 0, VarOf_M_Text_Part = 1, Data_M__sTextString, Data_M__sTextEmbed, Data_M__sTextIndent, Data_M__sTextGroup, Data_M__sTextSeparator, Data_M__sTextBreak, Data_M__sTextChars} EnumOf_M_Text_Part;
#define STRUCT_Con_M__sTextString struct _Con_M__sTextString
struct _Con_M__sTextString {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__sTextString;
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
#define STRUCT_Con_M__sTextBreak struct _Con_M__sTextBreak
struct _Con_M__sTextBreak {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__sTextBreak;
#define STRUCT_Con_M__sTextChars struct _Con_M__sTextChars
struct _Con_M__sTextChars {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__sTextChars;
extern struct _SortDescriptor sort_M_Text_Part;

/* DATA SORT TextMapSort HEADER DECLARATIONS. */
typedef enum {FunOf_M_TextMapSort = 0, VarOf_M_TextMapSort = 1, Data_M_TEXT_xMAP} EnumOf_M_TextMapSort;
#define STRUCT_Con_M_TEXT_xMAP struct _Con_M_TEXT_xMAP
struct _Con_M_TEXT_xMAP {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_TEXT_xMAP;
extern struct _SortDescriptor sort_M_TextMapSort;

/* DATA SORT Wrapper HEADER DECLARATIONS. */
typedef enum {FunOf_M_Wrapper = 0, VarOf_M_Wrapper = 1, Data_M_Wrapper, Data_M_NoWrapper} EnumOf_M_Wrapper;
#define STRUCT_Con_M_Wrapper struct _Con_M_Wrapper
struct _Con_M_Wrapper {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_Wrapper;
#define STRUCT_Con_M_NoWrapper struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_NoWrapper;
extern struct _SortDescriptor sort_M_Wrapper;

/* FUNCTION CookCRS-CRS-TermConstruction2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_TermConstruction2_s10 struct _Con_M_CRS_TermConstruction2_s10
struct _Con_M_CRS_TermConstruction2_s10 {struct _Construction construction; Term sub[4]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_TermConstruction2_s10;
extern int step_M_CRS_TermConstruction2_s10(Sink,Term);

/* FUNCTION Prelude-JoinMappedTextMaps2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_JoinMappedTextMaps2_s3 struct _Con_M_JoinMappedTextMaps2_s3
struct _Con_M_JoinMappedTextMaps2_s3 {struct _Construction construction; Term sub[2]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M_JoinMappedTextMaps2_s3;
extern int step_M_JoinMappedTextMaps2_s3(Sink,Term);

/* FUNCTION CookBase-MakeLocation2-1$MakeLocation2$4$STRING HEADER DECLARATIONS. */
#define STRUCT_Con_M_MakeLocation2_s4 struct _Con_M_MakeLocation2_s4
struct _Con_M_MakeLocation2_s4 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_MakeLocation2_s4;
extern int step_M_MakeLocation2_s4(Sink,Term);

/* FUNCTION CookBase-MakeLocation2-1$MakeLocation2$2$STRING HEADER DECLARATIONS. */
#define STRUCT_Con_M_MakeLocation2_s2 struct _Con_M_MakeLocation2_s2
struct _Con_M_MakeLocation2_s2 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_MakeLocation2_s2;
extern int step_M_MakeLocation2_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-TermConstruction2-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_TermConstruction2_s12 struct _Con_M_CRS_TermConstruction2_s12
struct _Con_M_CRS_TermConstruction2_s12 {struct _Construction construction; Term sub[6]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_TermConstruction2_s12;
extern int step_M_CRS_TermConstruction2_s12(Sink,Term);

/* FUNCTION CookCRS-CRS-TermConstruction2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_TermConstruction2_s11 struct _Con_M_CRS_TermConstruction2_s11
struct _Con_M_CRS_TermConstruction2_s11 {struct _Construction construction; Term sub[5]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_TermConstruction2_s11;
extern int step_M_CRS_TermConstruction2_s11(Sink,Term);

/* FUNCTION CookCRS-CRS-TermConstruction2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_TermConstruction2_s13 struct _Con_M_CRS_TermConstruction2_s13
struct _Con_M_CRS_TermConstruction2_s13 {struct _Construction construction; Term sub[4]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_TermConstruction2_s13;
extern int step_M_CRS_TermConstruction2_s13(Sink,Term);

/* FUNCTION CookN-KeepInheritedMapEntry2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepInheritedMapEntry2_s10 struct _Con_M_KeepInheritedMapEntry2_s10
struct _Con_M_KeepInheritedMapEntry2_s10 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepInheritedMapEntry2_s10;
extern int step_M_KeepInheritedMapEntry2_s10(Sink,Term);

/* FUNCTION CookN-KeepInheritedMapEntry2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepInheritedMapEntry2_s11 struct _Con_M_KeepInheritedMapEntry2_s11
struct _Con_M_KeepInheritedMapEntry2_s11 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepInheritedMapEntry2_s11;
extern int step_M_KeepInheritedMapEntry2_s11(Sink,Term);

/* FUNCTION CookPG-PG-InlineRegExpSimple- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_InlineRegExpSimple struct _Con_M_PG_InlineRegExpSimple
struct _Con_M_PG_InlineRegExpSimple {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_InlineRegExpSimple;
extern int step_M_PG_InlineRegExpSimple(Sink,Term);

/* FUNCTION CookN-N-InheritedRefsList-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_InheritedRefsList_s3 struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_N_InheritedRefsList_s3;
extern int step_M_N_InheritedRefsList_s3(Sink,Term);

/* FUNCTION Text-AsText-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_AsText struct _Con_M_AsText
struct _Con_M_AsText {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_AsText;
extern int step_M_AsText(Sink,Term);

/* FUNCTION CookN-N-InheritedRefsList-2$N-InheritedRefsList$1$RAW-InheritedRef HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_InheritedRefsList_s1 struct _Con_M_N_InheritedRefsList_s1
struct _Con_M_N_InheritedRefsList_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_InheritedRefsList_s1;
extern int step_M_N_InheritedRefsList_s1(Sink,Term);

/* FUNCTION CookN-N-InheritedRefsList-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_InheritedRefsList_s2 struct _Con_M_N_InheritedRefsList_s2
struct _Con_M_N_InheritedRefsList_s2 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_InheritedRefsList_s2;
extern int step_M_N_InheritedRefsList_s2(Sink,Term);

/* FUNCTION CookPG-SameScopeSort2-2$SameScopeSort2$12$RAW-RepeatSingle HEADER DECLARATIONS. */
#define STRUCT_Con_M_SameScopeSort2_s12 struct _Con_M_SameScopeSort2_s12
struct _Con_M_SameScopeSort2_s12 {struct _Construction construction; Term sub[10]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SameScopeSort2_s12;
extern int step_M_SameScopeSort2_s12(Sink,Term);

/* FUNCTION CookPG-SameScopeSort2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_SameScopeSort2_s10 struct _Con_M_SameScopeSort2_s10
struct _Con_M_SameScopeSort2_s10 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SameScopeSort2_s10;
extern int step_M_SameScopeSort2_s10(Sink,Term);

/* FUNCTION Prelude-NewLine-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_NewLine struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_NewLine;
extern int step_M_NewLine(Sink,Term);

/* FUNCTION CookN-ResolveSynthesize HEADER DECLARATIONS. */
#define STRUCT_Con_M_N__resolve_s13 struct _Con_M_N__resolve_s13
struct _Con_M_N__resolve_s13 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N__resolve_s13;
extern int step_M_N__resolve_s13(Sink,Term);

/* FUNCTION CookN-Resolve-Space HEADER DECLARATIONS. */
#define STRUCT_Con_M_N__resolve_s12 struct _Con_M_N__resolve_s12
struct _Con_M_N__resolve_s12 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N__resolve_s12;
extern int step_M_N__resolve_s12(Sink,Term);

/* FUNCTION CookN-Resolve-Token HEADER DECLARATIONS. */
#define STRUCT_Con_M_N__resolve_s14 struct _Con_M_N__resolve_s14
struct _Con_M_N__resolve_s14 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N__resolve_s14;
extern int step_M_N__resolve_s14(Sink,Term);

/* FUNCTION CookN-Resolve-Sort HEADER DECLARATIONS. */
#define STRUCT_Con_M_N__resolve_s11 struct _Con_M_N__resolve_s11
struct _Con_M_N__resolve_s11 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N__resolve_s11;
extern int step_M_N__resolve_s11(Sink,Term);

/* FUNCTION CookN-ResolveRule HEADER DECLARATIONS. */
#define STRUCT_Con_M_N__resolve_s10 struct _Con_M_N__resolve_s10
struct _Con_M_N__resolve_s10 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N__resolve_s10;
extern int step_M_N__resolve_s10(Sink,Term);

/* FUNCTION Prelude-ContainsName-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ContainsName_s1 struct _Con_M_ContainsName_s1
struct _Con_M_ContainsName_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ContainsName_s1;
extern int step_M_ContainsName_s1(Sink,Term);

/* FUNCTION CookN-_DefineLessEqual2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefineLessEqual2_s2 struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M__xDefineLessEqual2_s2;
extern int step_M__xDefineLessEqual2_s2(Sink,Term);

/* FUNCTION CookN-_DefineLessEqual2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefineLessEqual2_s1 struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M__xDefineLessEqual2_s1;
extern int step_M__xDefineLessEqual2_s1(Sink,Term);

/* FUNCTION CookN-KeepInheritedMapEntry-1$KeepInheritedMapEntry$OK HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepInheritedMapEntry struct _Con_M_KeepInheritedMapEntry
struct _Con_M_KeepInheritedMapEntry {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepInheritedMapEntry;
extern int step_M_KeepInheritedMapEntry(Sink,Term);

/* FUNCTION CookCRS-CRS-then-Rules-DataSynth-Need-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS__then_Rules_DataSynth_Need_s1 struct _Con_M_CRS__then_Rules_DataSynth_Need_s1
struct _Con_M_CRS__then_Rules_DataSynth_Need_s1 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS__then_Rules_DataSynth_Need_s1;
extern int step_M_CRS__then_Rules_DataSynth_Need_s1(Sink,Term);

/* FUNCTION Prelude-RemoveName1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_RemoveName1 struct _Con_M_RemoveName1
struct _Con_M_RemoveName1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RemoveName1;
extern int step_M_RemoveName1(Sink,Term);

/* FUNCTION CookCRS-CRS-SynthesizeRule-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_SynthesizeRule struct _Con_M_CRS_SynthesizeRule
struct _Con_M_CRS_SynthesizeRule {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_SynthesizeRule;
extern int step_M_CRS_SynthesizeRule(Sink,Term);

/* FUNCTION CookBase-SortVar3-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortVar3_s4 struct _Con_M_SortVar3_s4
struct _Con_M_SortVar3_s4 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortVar3_s4;
extern int step_M_SortVar3_s4(Sink,Term);

/* FUNCTION CookBase-SortVar3-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortVar3_s5 struct _Con_M_SortVar3_s5
struct _Con_M_SortVar3_s5 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortVar3_s5;
extern int step_M_SortVar3_s5(Sink,Term);

/* FUNCTION CookBase-TokenName-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_TokenName struct _Con_M_TokenName
struct _Con_M_TokenName {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_TokenName;
extern int step_M_TokenName(Sink,Term);

/* FUNCTION CookCRS-CRS-Parsed- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Parsed_s1 struct _Con_M_CRS_Parsed_s1
struct _Con_M_CRS_Parsed_s1 {struct _Construction construction; Term sub[9]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Parsed_s1;
extern int step_M_CRS_Parsed_s1(Sink,Term);

/* FUNCTION CookBase-SortVar3-2$SortVar3$3$$Nil HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortVar3_s3 struct _Con_M_SortVar3_s3
struct _Con_M_SortVar3_s3 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortVar3_s3;
extern int step_M_SortVar3_s3(Sink,Term);

/* FUNCTION CookPG-VariableMarker2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_VariableMarker2_s7 struct _Con_M_VariableMarker2_s7
struct _Con_M_VariableMarker2_s7 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_VariableMarker2_s7;
extern int step_M_VariableMarker2_s7(Sink,Term);

/* FUNCTION CookCRS-CRS-Parsed-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Parsed_s3 struct _Con_M_CRS_Parsed_s3
struct _Con_M_CRS_Parsed_s3 {struct _Construction construction; Term sub[8]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Parsed_s3;
extern int step_M_CRS_Parsed_s3(Sink,Term);

/* FUNCTION Prelude-Map- HEADER DECLARATIONS. */
#define STRUCT_Con_M_Map_s1 struct _Con_M_Map_s1
struct _Con_M_Map_s1 {struct _Construction construction; Term sub[2]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M_Map_s1;
extern int step_M_Map_s1(Sink,Term);

/* FUNCTION CookPG-VariableMarker2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_VariableMarker2_s6 struct _Con_M_VariableMarker2_s6
struct _Con_M_VariableMarker2_s6 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_VariableMarker2_s6;
extern int step_M_VariableMarker2_s6(Sink,Term);

/* FUNCTION CookBase-SortVar3- HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortVar3_s1 struct _Con_M_SortVar3_s1
struct _Con_M_SortVar3_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortVar3_s1;
extern int step_M_SortVar3_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-Parsed-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Parsed_s2 struct _Con_M_CRS_Parsed_s2
struct _Con_M_CRS_Parsed_s2 {struct _Construction construction; Term sub[8]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Parsed_s2;
extern int step_M_CRS_Parsed_s2(Sink,Term);

/* FUNCTION CookPG-VariableMarker2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_VariableMarker2_s5 struct _Con_M_VariableMarker2_s5
struct _Con_M_VariableMarker2_s5 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_VariableMarker2_s5;
extern int step_M_VariableMarker2_s5(Sink,Term);

/* FUNCTION Prelude-Map-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_Map_s3 struct _Con_M_Map_s3
struct _Con_M_Map_s3 {struct _Construction construction; Term sub[1]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M_Map_s3;
extern int step_M_Map_s3(Sink,Term);

/* FUNCTION CookPG-VariableMarker2-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_VariableMarker2_s4 struct _Con_M_VariableMarker2_s4
struct _Con_M_VariableMarker2_s4 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_VariableMarker2_s4;
extern int step_M_VariableMarker2_s4(Sink,Term);

/* FUNCTION Prelude-Map-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_Map_s2 struct _Con_M_Map_s2
struct _Con_M_Map_s2 {struct _Construction construction; Term sub[3]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M_Map_s2;
extern int step_M_Map_s2(Sink,Term);

/* FUNCTION CookPG-VariableMarker2-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_VariableMarker2_s3 struct _Con_M_VariableMarker2_s3
struct _Con_M_VariableMarker2_s3 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_VariableMarker2_s3;
extern int step_M_VariableMarker2_s3(Sink,Term);

/* FUNCTION CookPG-VariableMarker2-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_VariableMarker2_s2 struct _Con_M_VariableMarker2_s2
struct _Con_M_VariableMarker2_s2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_VariableMarker2_s2;
extern int step_M_VariableMarker2_s2(Sink,Term);

/* FUNCTION CookPG-VariableMarker2-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_VariableMarker2_s1 struct _Con_M_VariableMarker2_s1
struct _Con_M_VariableMarker2_s1 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_VariableMarker2_s1;
extern int step_M_VariableMarker2_s1(Sink,Term);

/* FUNCTION CookN-SynthesizedMapNames-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SynthesizedMapNames struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_SynthesizedMapNames;
extern int step_M_SynthesizedMapNames(Sink,Term);

/* FUNCTION Prelude-JoinTextMaps-1$JoinTextMaps$TEXT_MAP HEADER DECLARATIONS. */
#define STRUCT_Con_M_JoinTextMaps struct _Con_M_JoinTextMaps
struct _Con_M_JoinTextMaps {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_JoinTextMaps;
extern int step_M_JoinTextMaps(Sink,Term);

/* FUNCTION CookN-Declarations-fragment HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_Declarations1_s7 struct _Con_M_N_Declarations1_s7
struct _Con_M_N_Declarations1_s7 {struct _Construction construction; Term sub[9]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M_N_Declarations1_s7;
extern int step_M_N_Declarations1_s7(Sink,Term);

/* FUNCTION CookN-Declarations-local HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_Declarations1_s8 struct _Con_M_N_Declarations1_s8
struct _Con_M_N_Declarations1_s8 {struct _Construction construction; Term sub[8]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M_N_Declarations1_s8;
extern int step_M_N_Declarations1_s8(Sink,Term);

/* FUNCTION CookCRS-CRS-ParamSequence-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_ParamSequence_s2 struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_CRS_ParamSequence_s2;
extern int step_M_CRS_ParamSequence_s2(Sink,Term);

/* FUNCTION CookN-Declarations-rule HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_Declarations1_s9 struct _Con_M_N_Declarations1_s9
struct _Con_M_N_Declarations1_s9 {struct _Construction construction; Term sub[8]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M_N_Declarations1_s9;
extern int step_M_N_Declarations1_s9(Sink,Term);

/* FUNCTION CookCRS-CRS-ParamSequence-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_ParamSequence_s1 struct _Con_M_CRS_ParamSequence_s1
struct _Con_M_CRS_ParamSequence_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_ParamSequence_s1;
extern int step_M_CRS_ParamSequence_s1(Sink,Term);

/* FUNCTION CookN-Declarations-alternatives HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_Declarations1_s3 struct _Con_M_N_Declarations1_s3
struct _Con_M_N_Declarations1_s3 {struct _Construction construction; Term sub[8]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M_N_Declarations1_s3;
extern int step_M_N_Declarations1_s3(Sink,Term);

/* FUNCTION CookN-Declarations-attribute HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_Declarations1_s4 struct _Con_M_N_Declarations1_s4
struct _Con_M_N_Declarations1_s4 {struct _Construction construction; Term sub[11]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M_N_Declarations1_s4;
extern int step_M_N_Declarations1_s4(Sink,Term);

/* FUNCTION CookN-N-Declarations1-1$N-Declarations1$5$RAW-module HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_Declarations1_s5 struct _Con_M_N_Declarations1_s5
struct _Con_M_N_Declarations1_s5 {struct _Construction construction; Term sub[8]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M_N_Declarations1_s5;
extern int step_M_N_Declarations1_s5(Sink,Term);

/* FUNCTION CookN-N-Declarations1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_Declarations1_s6 struct _Con_M_N_Declarations1_s6
struct _Con_M_N_Declarations1_s6 {struct _Construction construction; Term sub[10]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M_N_Declarations1_s6;
extern int step_M_N_Declarations1_s6(Sink,Term);

/* FUNCTION CookN-Declarations-none HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_Declarations1_s1 struct _Con_M_N_Declarations1_s1
struct _Con_M_N_Declarations1_s1 {struct _Construction construction; Term sub[5]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M_N_Declarations1_s1;
extern int step_M_N_Declarations1_s1(Sink,Term);

/* FUNCTION CookN- HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_Declarations1_s2 struct _Con_M_N_Declarations1_s2
struct _Con_M_N_Declarations1_s2 {struct _Construction construction; Term sub[7]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M_N_Declarations1_s2;
extern int step_M_N_Declarations1_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-Term-Attributes-8 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Term_Attributes_s10 struct _Con_M_CRS_Term_Attributes_s10
struct _Con_M_CRS_Term_Attributes_s10 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Term_Attributes_s10;
extern int step_M_CRS_Term_Attributes_s10(Sink,Term);

/* FUNCTION CookN-DerivedSorts-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts struct _Con_M_DerivedSorts
struct _Con_M_DerivedSorts {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts;
extern int step_M_DerivedSorts(Sink,Term);

/* FUNCTION CookCRS-CRS-Declaration1-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declaration1_s6 struct _Con_M_CRS_Declaration1_s6
struct _Con_M_CRS_Declaration1_s6 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declaration1_s6;
extern int step_M_CRS_Declaration1_s6(Sink,Term);

/* FUNCTION CookCRS-CRS-Declaration1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declaration1_s4 struct _Con_M_CRS_Declaration1_s4
struct _Con_M_CRS_Declaration1_s4 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declaration1_s4;
extern int step_M_CRS_Declaration1_s4(Sink,Term);

/* FUNCTION CookCRS-CRS-Declaration1-5 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declaration1_s5 struct _Con_M_CRS_Declaration1_s5
struct _Con_M_CRS_Declaration1_s5 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declaration1_s5;
extern int step_M_CRS_Declaration1_s5(Sink,Term);

/* FUNCTION Prelude-UnLift-1$UnLift$LIFTED HEADER DECLARATIONS. */
#define STRUCT_Con_M_UnLift struct _Con_M_UnLift
struct _Con_M_UnLift {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_UnLift;
extern int step_M_UnLift(Sink,Term);

/* FUNCTION CookCRS-CRS-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_s2 struct _Con_M_CRS_s2
struct _Con_M_CRS_s2 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_s2;
extern int step_M_CRS_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-1$CRS$1$RAW-module HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_s1 struct _Con_M_CRS_s1
struct _Con_M_CRS_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_s1;
extern int step_M_CRS_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-Declaration1-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declaration1_s3 struct _Con_M_CRS_Declaration1_s3
struct _Con_M_CRS_Declaration1_s3 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declaration1_s3;
extern int step_M_CRS_Declaration1_s3(Sink,Term);

/* FUNCTION CookCRS-CRS-Declaration1-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declaration1_s2 struct _Con_M_CRS_Declaration1_s2
struct _Con_M_CRS_Declaration1_s2 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declaration1_s2;
extern int step_M_CRS_Declaration1_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-Declaration1- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declaration1_s1 struct _Con_M_CRS_Declaration1_s1
struct _Con_M_CRS_Declaration1_s1 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declaration1_s1;
extern int step_M_CRS_Declaration1_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-TermAttributes-1$CRS-TermAttributes$OK HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_TermAttributes struct _Con_M_CRS_TermAttributes
struct _Con_M_CRS_TermAttributes {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_TermAttributes;
extern int step_M_CRS_TermAttributes(Sink,Term);

/* FUNCTION Prelude-Tl-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_Tl_s1 struct _Con_M_Tl_s1
struct _Con_M_Tl_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_Tl_s1;
extern int step_M_Tl_s1(Sink,Term);

/* FUNCTION Prelude-Tl-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_Tl_s2 struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_Tl_s2;
extern int step_M_Tl_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-Attributes3-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Attributes3_s1 struct _Con_M_CRS_Attributes3_s1
struct _Con_M_CRS_Attributes3_s1 {struct _Construction construction; Term sub[4]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Attributes3_s1;
extern int step_M_CRS_Attributes3_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-then-Rules-DataSynth-Need-1$CRS-then-Rules-DataSynth-Need$OK HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS__then_Rules_DataSynth_Need struct _Con_M_CRS__then_Rules_DataSynth_Need
struct _Con_M_CRS__then_Rules_DataSynth_Need {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS__then_Rules_DataSynth_Need;
extern int step_M_CRS__then_Rules_DataSynth_Need(Sink,Term);

/* FUNCTION CookCRS-CRS-Parsed-In-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Parsed_In_s3 struct _Con_M_CRS_Parsed_In_s3
struct _Con_M_CRS_Parsed_In_s3 {struct _Construction construction; Term sub[6]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Parsed_In_s3;
extern int step_M_CRS_Parsed_In_s3(Sink,Term);

/* FUNCTION CookCRS-CRS-AddSynthesisNeeds- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AddSynthesisNeeds_s4 struct _Con_M_CRS_AddSynthesisNeeds_s4
struct _Con_M_CRS_AddSynthesisNeeds_s4 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AddSynthesisNeeds_s4;
extern int step_M_CRS_AddSynthesisNeeds_s4(Sink,Term);

/* FUNCTION CookCRS-CRS-Parsed-In-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Parsed_In_s2 struct _Con_M_CRS_Parsed_In_s2
struct _Con_M_CRS_Parsed_In_s2 {struct _Construction construction; Term sub[6]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Parsed_In_s2;
extern int step_M_CRS_Parsed_In_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-AddSynthesisNeeds-1$CRS-AddSynthesisNeeds$3$RAW-Attribute HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AddSynthesisNeeds_s3 struct _Con_M_CRS_AddSynthesisNeeds_s3
struct _Con_M_CRS_AddSynthesisNeeds_s3 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AddSynthesisNeeds_s3;
extern int step_M_CRS_AddSynthesisNeeds_s3(Sink,Term);

/* FUNCTION CookCRS-CRS-Parsed-In-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Parsed_In_s1 struct _Con_M_CRS_Parsed_In_s1
struct _Con_M_CRS_Parsed_In_s1 {struct _Construction construction; Term sub[4]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Parsed_In_s1;
extern int step_M_CRS_Parsed_In_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-AddSynthesisNeeds-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AddSynthesisNeeds_s6 struct _Con_M_CRS_AddSynthesisNeeds_s6
struct _Con_M_CRS_AddSynthesisNeeds_s6 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AddSynthesisNeeds_s6;
extern int step_M_CRS_AddSynthesisNeeds_s6(Sink,Term);

/* FUNCTION CookCRS-CRS-AddSynthesisNeeds-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AddSynthesisNeeds_s5 struct _Con_M_CRS_AddSynthesisNeeds_s5
struct _Con_M_CRS_AddSynthesisNeeds_s5 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AddSynthesisNeeds_s5;
extern int step_M_CRS_AddSynthesisNeeds_s5(Sink,Term);

/* FUNCTION CookN-N-SortAbstraction-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_SortAbstraction struct _Con_M_N_SortAbstraction
struct _Con_M_N_SortAbstraction {struct _Construction construction; Term sub[5]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M_N_SortAbstraction;
extern int step_M_N_SortAbstraction(Sink,Term);

/* FUNCTION CookCRS-CRS-Module-1$CRS-Module HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Module struct _Con_M_CRS_Module
struct _Con_M_CRS_Module {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Module;
extern int step_M_CRS_Module(Sink,Term);

/* FUNCTION CookCRS-CRS-AddSynthesisNeeds-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AddSynthesisNeeds_s7 struct _Con_M_CRS_AddSynthesisNeeds_s7
struct _Con_M_CRS_AddSynthesisNeeds_s7 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AddSynthesisNeeds_s7;
extern int step_M_CRS_AddSynthesisNeeds_s7(Sink,Term);

/* FUNCTION CookN-KeepSynthesizedMapEntry-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepSynthesizedMapEntry_s1 struct _Con_M_KeepSynthesizedMapEntry_s1
struct _Con_M_KeepSynthesizedMapEntry_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepSynthesizedMapEntry_s1;
extern int step_M_KeepSynthesizedMapEntry_s1(Sink,Term);

/* FUNCTION Prelude-RemoveFirstName-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_RemoveFirstName_s1 struct _Con_M_RemoveFirstName_s1
struct _Con_M_RemoveFirstName_s1 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RemoveFirstName_s1;
extern int step_M_RemoveFirstName_s1(Sink,Term);

/* FUNCTION CookPG-PG3-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG3_s1 struct _Con_M_PG3_s1
struct _Con_M_PG3_s1 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG3_s1;
extern int step_M_PG3_s1(Sink,Term);

/* FUNCTION Prelude-EmptyTextMap-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_EmptyTextMap struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_EmptyTextMap;
extern int step_M_EmptyTextMap(Sink,Term);

/* FUNCTION CookCRS-CRS-AddSynthesisNeeds- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AddSynthesisNeeds_s2 struct _Con_M_CRS_AddSynthesisNeeds_s2
struct _Con_M_CRS_AddSynthesisNeeds_s2 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AddSynthesisNeeds_s2;
extern int step_M_CRS_AddSynthesisNeeds_s2(Sink,Term);

/* FUNCTION Prelude-TextFold- HEADER DECLARATIONS. */
#define STRUCT_Con_M_TextFold struct _Con_M_TextFold
struct _Con_M_TextFold {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_TextFold;
extern int step_M_TextFold(Sink,Term);

/* FUNCTION CookCRS-CRS-ParsedForm-ParsedForm-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_ParsedForm_ParsedForm_s6 struct _Con_M_CRS_ParsedForm_ParsedForm_s6
struct _Con_M_CRS_ParsedForm_ParsedForm_s6 {struct _Construction construction; Term sub[7]; Variable binder[5];};
extern struct _ConstructionDescriptor descriptor_M_CRS_ParsedForm_ParsedForm_s6;
extern int step_M_CRS_ParsedForm_ParsedForm_s6(Sink,Term);

/* FUNCTION CookCRS-CRS-ParsedForm-ParsedForm-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_ParsedForm_ParsedForm_s5 struct _Con_M_CRS_ParsedForm_ParsedForm_s5
struct _Con_M_CRS_ParsedForm_ParsedForm_s5 {struct _Construction construction; Term sub[10]; Variable binder[5];};
extern struct _ConstructionDescriptor descriptor_M_CRS_ParsedForm_ParsedForm_s5;
extern int step_M_CRS_ParsedForm_ParsedForm_s5(Sink,Term);

/* FUNCTION CookCRS-CRS-MetaDeclaration1- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_MetaDeclaration1 struct _Con_M_CRS_MetaDeclaration1
struct _Con_M_CRS_MetaDeclaration1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_MetaDeclaration1;
extern int step_M_CRS_MetaDeclaration1(Sink,Term);

/* FUNCTION CookCRS-CRS-ParsedForm-ParsedForm-5 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_ParsedForm_ParsedForm_s4 struct _Con_M_CRS_ParsedForm_ParsedForm_s4
struct _Con_M_CRS_ParsedForm_ParsedForm_s4 {struct _Construction construction; Term sub[12]; Variable binder[5];};
extern struct _ConstructionDescriptor descriptor_M_CRS_ParsedForm_ParsedForm_s4;
extern int step_M_CRS_ParsedForm_ParsedForm_s4(Sink,Term);

/* FUNCTION CookCRS-CRS-ParsedForm-ParsedForm- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_ParsedForm_ParsedForm_s3 struct _Con_M_CRS_ParsedForm_ParsedForm_s3
struct _Con_M_CRS_ParsedForm_ParsedForm_s3 {struct _Construction construction; Term sub[9]; Variable binder[5];};
extern struct _ConstructionDescriptor descriptor_M_CRS_ParsedForm_ParsedForm_s3;
extern int step_M_CRS_ParsedForm_ParsedForm_s3(Sink,Term);

/* FUNCTION CookN-N-SortAlternatives-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_SortAlternatives_s2 struct _Con_M_N_SortAlternatives_s2
struct _Con_M_N_SortAlternatives_s2 {struct _Construction construction; Term sub[4]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M_N_SortAlternatives_s2;
extern int step_M_N_SortAlternatives_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-ParsedForm-ParsedForm-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_ParsedForm_ParsedForm_s2 struct _Con_M_CRS_ParsedForm_ParsedForm_s2
struct _Con_M_CRS_ParsedForm_ParsedForm_s2 {struct _Construction construction; Term sub[7]; Variable binder[5];};
extern struct _ConstructionDescriptor descriptor_M_CRS_ParsedForm_ParsedForm_s2;
extern int step_M_CRS_ParsedForm_ParsedForm_s2(Sink,Term);

/* FUNCTION CookN-N-SortAlternatives-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_SortAlternatives_s1 struct _Con_M_N_SortAlternatives_s1
struct _Con_M_N_SortAlternatives_s1 {struct _Construction construction; Term sub[6]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M_N_SortAlternatives_s1;
extern int step_M_N_SortAlternatives_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-ParsedForm-ParsedForm-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_ParsedForm_ParsedForm_s1 struct _Con_M_CRS_ParsedForm_ParsedForm_s1
struct _Con_M_CRS_ParsedForm_ParsedForm_s1 {struct _Construction construction; Term sub[5]; Variable binder[5];};
extern struct _ConstructionDescriptor descriptor_M_CRS_ParsedForm_ParsedForm_s1;
extern int step_M_CRS_ParsedForm_ParsedForm_s1(Sink,Term);

/* FUNCTION CookN-_InsertDefine1- HEADER DECLARATIONS. */
#define STRUCT_Con_M__xInsertDefine1 struct _Con_M__xInsertDefine1
struct _Con_M__xInsertDefine1 {struct _Construction construction; Term sub[5]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M__xInsertDefine1;
extern int step_M__xInsertDefine1(Sink,Term);

/* FUNCTION CookCRS-CRS-Term-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Term_s7 struct _Con_M_CRS_Term_s7
struct _Con_M_CRS_Term_s7 {struct _Construction construction; Term sub[12]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Term_s7;
extern int step_M_CRS_Term_s7(Sink,Term);

/* FUNCTION CookCRS-CRS-Declaration1- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declaration1 struct _Con_M_CRS_Declaration1
struct _Con_M_CRS_Declaration1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declaration1;
extern int step_M_CRS_Declaration1(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Attribute- HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Attribute_s2 struct _Con_M_DerivedSorts_Attribute_s2
struct _Con_M_DerivedSorts_Attribute_s2 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Attribute_s2;
extern int step_M_DerivedSorts_Attribute_s2(Sink,Term);

/* FUNCTION CookN-_InsertDefine2- HEADER DECLARATIONS. */
#define STRUCT_Con_M__xInsertDefine2 struct _Con_M__xInsertDefine2
struct _Con_M__xInsertDefine2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xInsertDefine2;
extern int step_M__xInsertDefine2(Sink,Term);

/* FUNCTION CookCRS-CRS-Term-10 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Term_s8 struct _Con_M_CRS_Term_s8
struct _Con_M_CRS_Term_s8 {struct _Construction construction; Term sub[10]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Term_s8;
extern int step_M_CRS_Term_s8(Sink,Term);

/* FUNCTION CookCRS-CRS-Term-7 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Term_s9 struct _Con_M_CRS_Term_s9
struct _Con_M_CRS_Term_s9 {struct _Construction construction; Term sub[10]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Term_s9;
extern int step_M_CRS_Term_s9(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Attribute-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Attribute_s4 struct _Con_M_DerivedSorts_Attribute_s4
struct _Con_M_DerivedSorts_Attribute_s4 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Attribute_s4;
extern int step_M_DerivedSorts_Attribute_s4(Sink,Term);

/* FUNCTION CookBase-RegExpLeafName- HEADER DECLARATIONS. */
#define STRUCT_Con_M_RegExpLeafName_s1 struct _Con_M_RegExpLeafName_s1
struct _Con_M_RegExpLeafName_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RegExpLeafName_s1;
extern int step_M_RegExpLeafName_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-MetaDeclarations1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_MetaDeclarations1_s1 struct _Con_M_CRS_MetaDeclarations1_s1
struct _Con_M_CRS_MetaDeclarations1_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_MetaDeclarations1_s1;
extern int step_M_CRS_MetaDeclarations1_s1(Sink,Term);

/* FUNCTION CookN-AttributeKeySortName2-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_AttributeKeySortName2_s1 struct _Con_M_AttributeKeySortName2_s1
struct _Con_M_AttributeKeySortName2_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_AttributeKeySortName2_s1;
extern int step_M_AttributeKeySortName2_s1(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Attribute-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Attribute_s3 struct _Con_M_DerivedSorts_Attribute_s3
struct _Con_M_DerivedSorts_Attribute_s3 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Attribute_s3;
extern int step_M_DerivedSorts_Attribute_s3(Sink,Term);

/* FUNCTION CookN-AttributeKeySortName2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_AttributeKeySortName2_s3 struct _Con_M_AttributeKeySortName2_s3
struct _Con_M_AttributeKeySortName2_s3 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_AttributeKeySortName2_s3;
extern int step_M_AttributeKeySortName2_s3(Sink,Term);

/* FUNCTION CookN-AttributeKeySortName2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_AttributeKeySortName2_s4 struct _Con_M_AttributeKeySortName2_s4
struct _Con_M_AttributeKeySortName2_s4 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_AttributeKeySortName2_s4;
extern int step_M_AttributeKeySortName2_s4(Sink,Term);

/* FUNCTION CookN-AttributeKeySortName2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_AttributeKeySortName2_s5 struct _Con_M_AttributeKeySortName2_s5
struct _Con_M_AttributeKeySortName2_s5 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_AttributeKeySortName2_s5;
extern int step_M_AttributeKeySortName2_s5(Sink,Term);

/* FUNCTION CookCRS-CRS-MetaDeclaration1-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_MetaDeclaration1_s1 struct _Con_M_CRS_MetaDeclaration1_s1
struct _Con_M_CRS_MetaDeclaration1_s1 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_MetaDeclaration1_s1;
extern int step_M_CRS_MetaDeclaration1_s1(Sink,Term);

/* FUNCTION CookN-AttributeKeySortName2-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_AttributeKeySortName2_s6 struct _Con_M_AttributeKeySortName2_s6
struct _Con_M_AttributeKeySortName2_s6 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_AttributeKeySortName2_s6;
extern int step_M_AttributeKeySortName2_s6(Sink,Term);

/* FUNCTION CookCRS-CRS-MetaDeclaration1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_MetaDeclaration1_s2 struct _Con_M_CRS_MetaDeclaration1_s2
struct _Con_M_CRS_MetaDeclaration1_s2 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_MetaDeclaration1_s2;
extern int step_M_CRS_MetaDeclaration1_s2(Sink,Term);

/* FUNCTION CookN-AttributeKeySortName2-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_AttributeKeySortName2_s7 struct _Con_M_AttributeKeySortName2_s7
struct _Con_M_AttributeKeySortName2_s7 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_AttributeKeySortName2_s7;
extern int step_M_AttributeKeySortName2_s7(Sink,Term);

/* FUNCTION CookPG-PG-Productions-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Productions struct _Con_M_PG_Productions
struct _Con_M_PG_Productions {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_Productions;
extern int step_M_PG_Productions(Sink,Term);

/* FUNCTION CookCRS-CRS-Term-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Term_s1 struct _Con_M_CRS_Term_s1
struct _Con_M_CRS_Term_s1 {struct _Construction construction; Term sub[11]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Term_s1;
extern int step_M_CRS_Term_s1(Sink,Term);

/* FUNCTION CookN-AttributeKeySortName2-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_AttributeKeySortName2_s8 struct _Con_M_AttributeKeySortName2_s8
struct _Con_M_AttributeKeySortName2_s8 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_AttributeKeySortName2_s8;
extern int step_M_AttributeKeySortName2_s8(Sink,Term);

/* FUNCTION CookCRS-CRS-Term-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Term_s2 struct _Con_M_CRS_Term_s2
struct _Con_M_CRS_Term_s2 {struct _Construction construction; Term sub[13]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Term_s2;
extern int step_M_CRS_Term_s2(Sink,Term);

/* FUNCTION CookN-ProductionNameDerived-1$ProductionNameDerived$DERIVED HEADER DECLARATIONS. */
#define STRUCT_Con_M_ProductionNameDerived struct _Con_M_ProductionNameDerived
struct _Con_M_ProductionNameDerived {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ProductionNameDerived;
extern int step_M_ProductionNameDerived(Sink,Term);

/* FUNCTION CookCRS-CRS-Term-9 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Term_s3 struct _Con_M_CRS_Term_s3
struct _Con_M_CRS_Term_s3 {struct _Construction construction; Term sub[10]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Term_s3;
extern int step_M_CRS_Term_s3(Sink,Term);

/* FUNCTION CookCRS-CRS-MetaDeclarations1-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_MetaDeclarations1_s2 struct _Con_M_CRS_MetaDeclarations1_s2
struct _Con_M_CRS_MetaDeclarations1_s2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_MetaDeclarations1_s2;
extern int step_M_CRS_MetaDeclarations1_s2(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Attribute-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Attribute_s6 struct _Con_M_DerivedSorts_Attribute_s6
struct _Con_M_DerivedSorts_Attribute_s6 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Attribute_s6;
extern int step_M_DerivedSorts_Attribute_s6(Sink,Term);

/* FUNCTION CookN-Then-DerivedSorts-Term-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_Then_DerivedSorts_Term_s1 struct _Con_M_Then_DerivedSorts_Term_s1
struct _Con_M_Then_DerivedSorts_Term_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_Then_DerivedSorts_Term_s1;
extern int step_M_Then_DerivedSorts_Term_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-Term-5 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Term_s4 struct _Con_M_CRS_Term_s4
struct _Con_M_CRS_Term_s4 {struct _Construction construction; Term sub[11]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Term_s4;
extern int step_M_CRS_Term_s4(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Attribute-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Attribute_s5 struct _Con_M_DerivedSorts_Attribute_s5
struct _Con_M_DerivedSorts_Attribute_s5 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Attribute_s5;
extern int step_M_DerivedSorts_Attribute_s5(Sink,Term);

/* FUNCTION CookCRS-CRS-TermConstruction-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_TermConstruction struct _Con_M_CRS_TermConstruction
struct _Con_M_CRS_TermConstruction {struct _Construction construction; Term sub[10]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_TermConstruction;
extern int step_M_CRS_TermConstruction(Sink,Term);

/* FUNCTION CookCRS-CRS-Term-6 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Term_s5 struct _Con_M_CRS_Term_s5
struct _Con_M_CRS_Term_s5 {struct _Construction construction; Term sub[13]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Term_s5;
extern int step_M_CRS_Term_s5(Sink,Term);

/* FUNCTION CookCRS-CRS-MetaDeclaration1-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_MetaDeclaration1_s3 struct _Con_M_CRS_MetaDeclaration1_s3
struct _Con_M_CRS_MetaDeclaration1_s3 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_MetaDeclaration1_s3;
extern int step_M_CRS_MetaDeclaration1_s3(Sink,Term);

/* FUNCTION CookCRS-CRS-Forms-AttributeForm-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Forms_AttributeForm_s10 struct _Con_M_CRS_Forms_AttributeForm_s10
struct _Con_M_CRS_Forms_AttributeForm_s10 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Forms_AttributeForm_s10;
extern int step_M_CRS_Forms_AttributeForm_s10(Sink,Term);

/* FUNCTION CookCRS-CRS-Term-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Term_s6 struct _Con_M_CRS_Term_s6
struct _Con_M_CRS_Term_s6 {struct _Construction construction; Term sub[10]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Term_s6;
extern int step_M_CRS_Term_s6(Sink,Term);

/* FUNCTION CookCRS-CRS-MetaDeclaration1-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_MetaDeclaration1_s4 struct _Con_M_CRS_MetaDeclaration1_s4
struct _Con_M_CRS_MetaDeclaration1_s4 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_MetaDeclaration1_s4;
extern int step_M_CRS_MetaDeclaration1_s4(Sink,Term);

/* FUNCTION Prelude-ThenRemoveName-1$ThenRemoveName$OK HEADER DECLARATIONS. */
#define STRUCT_Con_M_ThenRemoveName struct _Con_M_ThenRemoveName
struct _Con_M_ThenRemoveName {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ThenRemoveName;
extern int step_M_ThenRemoveName(Sink,Term);

/* FUNCTION CookBase-SortVar-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortVar struct _Con_M_SortVar
struct _Con_M_SortVar {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortVar;
extern int step_M_SortVar(Sink,Term);

/* FUNCTION CookN-Declarations- HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_Declarations1 struct _Con_M_N_Declarations1
struct _Con_M_N_Declarations1 {struct _Construction construction; Term sub[5]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M_N_Declarations1;
extern int step_M_N_Declarations1(Sink,Term);

/* FUNCTION CookCRS-CRS-ScopeBinderSort1-2$CRS-ScopeBinderSort1$1$RAW-SubstituteSort HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_ScopeBinderSort1_s1 struct _Con_M_CRS_ScopeBinderSort1_s1
struct _Con_M_CRS_ScopeBinderSort1_s1 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_ScopeBinderSort1_s1;
extern int step_M_CRS_ScopeBinderSort1_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-ScopeBinderSort1-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_ScopeBinderSort1_s2 struct _Con_M_CRS_ScopeBinderSort1_s2
struct _Con_M_CRS_ScopeBinderSort1_s2 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_ScopeBinderSort1_s2;
extern int step_M_CRS_ScopeBinderSort1_s2(Sink,Term);

/* FUNCTION CookCRS-SubRefMode- HEADER DECLARATIONS. */
#define STRUCT_Con_M_SubRefMode struct _Con_M_SubRefMode
struct _Con_M_SubRefMode {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SubRefMode;
extern int step_M_SubRefMode(Sink,Term);

/* FUNCTION CookCRS-CRS-TermAttributes-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_TermAttributes_s1 struct _Con_M_CRS_TermAttributes_s1
struct _Con_M_CRS_TermAttributes_s1 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_TermAttributes_s1;
extern int step_M_CRS_TermAttributes_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-ScopeBinderSort1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_ScopeBinderSort1_s3 struct _Con_M_CRS_ScopeBinderSort1_s3
struct _Con_M_CRS_ScopeBinderSort1_s3 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_ScopeBinderSort1_s3;
extern int step_M_CRS_ScopeBinderSort1_s3(Sink,Term);

/* FUNCTION CookCRS-CRS-AddSynthesisNeeds-1$CRS-AddSynthesisNeeds$OK HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AddSynthesisNeeds struct _Con_M_CRS_AddSynthesisNeeds
struct _Con_M_CRS_AddSynthesisNeeds {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AddSynthesisNeeds;
extern int step_M_CRS_AddSynthesisNeeds(Sink,Term);

/* FUNCTION CookN-SynthesizedNames-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SynthesizedNames struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_SynthesizedNames;
extern int step_M_SynthesizedNames(Sink,Term);

/* FUNCTION CookCRS-CRS-ParsedForm-ParsedForm- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_ParsedForm_ParsedForm struct _Con_M_CRS_ParsedForm_ParsedForm
struct _Con_M_CRS_ParsedForm_ParsedForm {struct _Construction construction; Term sub[5]; Variable binder[5];};
extern struct _ConstructionDescriptor descriptor_M_CRS_ParsedForm_ParsedForm;
extern int step_M_CRS_ParsedForm_ParsedForm(Sink,Term);

/* FUNCTION CookCRS-CRS-ParamPrefix-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_ParamPrefix_s1 struct _Con_M_CRS_ParamPrefix_s1
struct _Con_M_CRS_ParamPrefix_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_ParamPrefix_s1;
extern int step_M_CRS_ParamPrefix_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-ParamPrefix-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_ParamPrefix_s2 struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_CRS_ParamPrefix_s2;
extern int step_M_CRS_ParamPrefix_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-TermConstruction3- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_TermConstruction3_s9 struct _Con_M_CRS_TermConstruction3_s9
struct _Con_M_CRS_TermConstruction3_s9 {struct _Construction construction; Term sub[6]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_TermConstruction3_s9;
extern int step_M_CRS_TermConstruction3_s9(Sink,Term);

/* FUNCTION CookCRS-CRS-TermConstruction3-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_TermConstruction3_s7 struct _Con_M_CRS_TermConstruction3_s7
struct _Con_M_CRS_TermConstruction3_s7 {struct _Construction construction; Term sub[7]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_TermConstruction3_s7;
extern int step_M_CRS_TermConstruction3_s7(Sink,Term);

/* FUNCTION CookCRS-SubRefMode-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SubRefMode_s3 struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_SubRefMode_s3;
extern int step_M_SubRefMode_s3(Sink,Term);

/* FUNCTION CookCRS-SubRefMode-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SubRefMode_s2 struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_SubRefMode_s2;
extern int step_M_SubRefMode_s2(Sink,Term);

/* FUNCTION CookCRS-SubRefMode-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SubRefMode_s1 struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_SubRefMode_s1;
extern int step_M_SubRefMode_s1(Sink,Term);

/* FUNCTION CookN-_InsertDefine4-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xInsertDefine4 struct _Con_M__xInsertDefine4
struct _Con_M__xInsertDefine4 {struct _Construction construction; Term sub[7]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M__xInsertDefine4;
extern int step_M__xInsertDefine4(Sink,Term);

/* FUNCTION CookN-_InsertDefine3- HEADER DECLARATIONS. */
#define STRUCT_Con_M__xInsertDefine3 struct _Con_M__xInsertDefine3
struct _Con_M__xInsertDefine3 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xInsertDefine3;
extern int step_M__xInsertDefine3(Sink,Term);

/* FUNCTION CookBase-RegExpLeafName-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_RegExpLeafName_s3 struct _Con_M_RegExpLeafName_s3
struct _Con_M_RegExpLeafName_s3 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RegExpLeafName_s3;
extern int step_M_RegExpLeafName_s3(Sink,Term);

/* FUNCTION CookBase-RegExpLeafName-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_RegExpLeafName_s2 struct _Con_M_RegExpLeafName_s2
struct _Con_M_RegExpLeafName_s2 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RegExpLeafName_s2;
extern int step_M_RegExpLeafName_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-Scope-1$CRS-Scope$RAW-Scope HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Scope struct _Con_M_CRS_Scope
struct _Con_M_CRS_Scope {struct _Construction construction; Term sub[5]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Scope;
extern int step_M_CRS_Scope(Sink,Term);

/* FUNCTION CookCRS-CRS-MetaDeclarations-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_MetaDeclarations struct _Con_M_CRS_MetaDeclarations
struct _Con_M_CRS_MetaDeclarations {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_MetaDeclarations;
extern int step_M_CRS_MetaDeclarations(Sink,Term);

/* FUNCTION CookN-Then-DerivedSorts-Scope-1$Then-DerivedSorts-Scope$1$RAW-Scope HEADER DECLARATIONS. */
#define STRUCT_Con_M_Then_DerivedSorts_Scope_s1 struct _Con_M_Then_DerivedSorts_Scope_s1
struct _Con_M_Then_DerivedSorts_Scope_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_Then_DerivedSorts_Scope_s1;
extern int step_M_Then_DerivedSorts_Scope_s1(Sink,Term);

/* FUNCTION CookN-Then-DerivedSorts-Scope-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_Then_DerivedSorts_Scope_s2 struct _Con_M_Then_DerivedSorts_Scope_s2
struct _Con_M_Then_DerivedSorts_Scope_s2 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_Then_DerivedSorts_Scope_s2;
extern int step_M_Then_DerivedSorts_Scope_s2(Sink,Term);

/* FUNCTION CookCRS-AddTopRefMode-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_AddTopRefMode_s1 struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_AddTopRefMode_s1;
extern int step_M_AddTopRefMode_s1(Sink,Term);

/* FUNCTION Prelude-UnionNames1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_UnionNames1_s3 struct _Con_M_UnionNames1_s3
struct _Con_M_UnionNames1_s3 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_UnionNames1_s3;
extern int step_M_UnionNames1_s3(Sink,Term);

/* FUNCTION CookCRS-CRS-Declarations-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declarations struct _Con_M_CRS_Declarations
struct _Con_M_CRS_Declarations {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declarations;
extern int step_M_CRS_Declarations(Sink,Term);

/* FUNCTION Prelude-UnionNames1-1$UnionNames1$2$NAME_SET HEADER DECLARATIONS. */
#define STRUCT_Con_M_UnionNames1_s2 struct _Con_M_UnionNames1_s2
struct _Con_M_UnionNames1_s2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_UnionNames1_s2;
extern int step_M_UnionNames1_s2(Sink,Term);

/* FUNCTION Prelude-TextFoldMap-1$TextFoldMap$TEXT_MAP HEADER DECLARATIONS. */
#define STRUCT_Con_M_TextFoldMap struct _Con_M_TextFoldMap
struct _Con_M_TextFoldMap {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_TextFoldMap;
extern int step_M_TextFoldMap(Sink,Term);

/* FUNCTION CookPG-PG-Production1- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Production1 struct _Con_M_PG_Production1
struct _Con_M_PG_Production1 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_Production1;
extern int step_M_PG_Production1(Sink,Term);

/* FUNCTION CookPG-ProductionNames2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_ProductionNames2 struct _Con_M_ProductionNames2
struct _Con_M_ProductionNames2 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ProductionNames2;
extern int step_M_ProductionNames2(Sink,Term);

/* FUNCTION CookCRS-CRS-Form-PatternEnv-1$CRS-Form-PatternEnv$2$NAMES HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Form_PatternEnv_s2 struct _Con_M_CRS_Form_PatternEnv_s2
struct _Con_M_CRS_Form_PatternEnv_s2 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Form_PatternEnv_s2;
extern int step_M_CRS_Form_PatternEnv_s2(Sink,Term);

/* FUNCTION CookPG-ProductionNames3- HEADER DECLARATIONS. */
#define STRUCT_Con_M_ProductionNames3 struct _Con_M_ProductionNames3
struct _Con_M_ProductionNames3 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ProductionNames3;
extern int step_M_ProductionNames3(Sink,Term);

/* FUNCTION CookCRS-CRS-Form-PatternEnv-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Form_PatternEnv_s3 struct _Con_M_CRS_Form_PatternEnv_s3
struct _Con_M_CRS_Form_PatternEnv_s3 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Form_PatternEnv_s3;
extern int step_M_CRS_Form_PatternEnv_s3(Sink,Term);

/* FUNCTION CookPG-ProductionNames4- HEADER DECLARATIONS. */
#define STRUCT_Con_M_ProductionNames4 struct _Con_M_ProductionNames4
struct _Con_M_ProductionNames4 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ProductionNames4;
extern int step_M_ProductionNames4(Sink,Term);

/* FUNCTION CookCRS-CRS-TermConstruction3- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_TermConstruction3_s3 struct _Con_M_CRS_TermConstruction3_s3
struct _Con_M_CRS_TermConstruction3_s3 {struct _Construction construction; Term sub[8]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_TermConstruction3_s3;
extern int step_M_CRS_TermConstruction3_s3(Sink,Term);

/* FUNCTION CookCRS-CRS-TermConstruction3-5 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_TermConstruction3_s4 struct _Con_M_CRS_TermConstruction3_s4
struct _Con_M_CRS_TermConstruction3_s4 {struct _Construction construction; Term sub[7]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_TermConstruction3_s4;
extern int step_M_CRS_TermConstruction3_s4(Sink,Term);

/* FUNCTION CookPG-ProductionNames4-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ProductionNames4_s2 struct _Con_M_ProductionNames4_s2
struct _Con_M_ProductionNames4_s2 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ProductionNames4_s2;
extern int step_M_ProductionNames4_s2(Sink,Term);

/* FUNCTION CookPG-PG-InlineRegExpUnit-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_InlineRegExpUnit_s3 struct _Con_M_PG_InlineRegExpUnit_s3
struct _Con_M_PG_InlineRegExpUnit_s3 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_InlineRegExpUnit_s3;
extern int step_M_PG_InlineRegExpUnit_s3(Sink,Term);

/* FUNCTION CookCRS-CRS-TermConstruction3- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_TermConstruction3_s5 struct _Con_M_CRS_TermConstruction3_s5
struct _Con_M_CRS_TermConstruction3_s5 {struct _Construction construction; Term sub[8]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_TermConstruction3_s5;
extern int step_M_CRS_TermConstruction3_s5(Sink,Term);

/* FUNCTION CookPG-ProductionNames4-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ProductionNames4_s1 struct _Con_M_ProductionNames4_s1
struct _Con_M_ProductionNames4_s1 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ProductionNames4_s1;
extern int step_M_ProductionNames4_s1(Sink,Term);

/* FUNCTION CookPG-PG-InlineRegExpUnit- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_InlineRegExpUnit_s2 struct _Con_M_PG_InlineRegExpUnit_s2
struct _Con_M_PG_InlineRegExpUnit_s2 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_InlineRegExpUnit_s2;
extern int step_M_PG_InlineRegExpUnit_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-TermConstruction3-6 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_TermConstruction3_s6 struct _Con_M_CRS_TermConstruction3_s6
struct _Con_M_CRS_TermConstruction3_s6 {struct _Construction construction; Term sub[9]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_TermConstruction3_s6;
extern int step_M_CRS_TermConstruction3_s6(Sink,Term);

/* FUNCTION Prelude-IfSingleton- HEADER DECLARATIONS. */
#define STRUCT_Con_M_IfSingleton struct _Con_M_IfSingleton
struct _Con_M_IfSingleton {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_IfSingleton;
extern int step_M_IfSingleton(Sink,Term);

/* FUNCTION CookPG-PG-InlineRegExpUnit-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_InlineRegExpUnit_s5 struct _Con_M_PG_InlineRegExpUnit_s5
struct _Con_M_PG_InlineRegExpUnit_s5 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_InlineRegExpUnit_s5;
extern int step_M_PG_InlineRegExpUnit_s5(Sink,Term);

/* FUNCTION CookBase-RuleTopSort-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_RuleTopSort_s1 struct _Con_M_RuleTopSort_s1
struct _Con_M_RuleTopSort_s1 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RuleTopSort_s1;
extern int step_M_RuleTopSort_s1(Sink,Term);

/* FUNCTION CookPG-ProductionNames4-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ProductionNames4_s3 struct _Con_M_ProductionNames4_s3
struct _Con_M_ProductionNames4_s3 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ProductionNames4_s3;
extern int step_M_ProductionNames4_s3(Sink,Term);

/* FUNCTION CookPG-PG-InlineRegExpUnit-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_InlineRegExpUnit_s4 struct _Con_M_PG_InlineRegExpUnit_s4
struct _Con_M_PG_InlineRegExpUnit_s4 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_InlineRegExpUnit_s4;
extern int step_M_PG_InlineRegExpUnit_s4(Sink,Term);

/* FUNCTION CookPG-PG-InlineRegExpUnit-5 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_InlineRegExpUnit_s7 struct _Con_M_PG_InlineRegExpUnit_s7
struct _Con_M_PG_InlineRegExpUnit_s7 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_InlineRegExpUnit_s7;
extern int step_M_PG_InlineRegExpUnit_s7(Sink,Term);

/* FUNCTION CookCRS-CRS-TermConstruction3- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_TermConstruction3_s1 struct _Con_M_CRS_TermConstruction3_s1
struct _Con_M_CRS_TermConstruction3_s1 {struct _Construction construction; Term sub[7]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_TermConstruction3_s1;
extern int step_M_CRS_TermConstruction3_s1(Sink,Term);

/* FUNCTION CookPG-SameScopeSort2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_SameScopeSort2 struct _Con_M_SameScopeSort2
struct _Con_M_SameScopeSort2 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SameScopeSort2;
extern int step_M_SameScopeSort2(Sink,Term);

/* FUNCTION CookPG-PG-InlineRegExpUnit-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_InlineRegExpUnit_s6 struct _Con_M_PG_InlineRegExpUnit_s6
struct _Con_M_PG_InlineRegExpUnit_s6 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_InlineRegExpUnit_s6;
extern int step_M_PG_InlineRegExpUnit_s6(Sink,Term);

/* FUNCTION CookBase-MakeLocation2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_MakeLocation2_s5 struct _Con_M_MakeLocation2_s5
struct _Con_M_MakeLocation2_s5 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_MakeLocation2_s5;
extern int step_M_MakeLocation2_s5(Sink,Term);

/* FUNCTION CookCRS-CRS-MatchSynthesisNeeds-1$CRS-MatchSynthesisNeeds$OK HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_MatchSynthesisNeeds struct _Con_M_CRS_MatchSynthesisNeeds
struct _Con_M_CRS_MatchSynthesisNeeds {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_MatchSynthesisNeeds;
extern int step_M_CRS_MatchSynthesisNeeds(Sink,Term);

/* FUNCTION CookCRS-AddTopRefMode-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_AddTopRefMode_s2 struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_AddTopRefMode_s2;
extern int step_M_AddTopRefMode_s2(Sink,Term);

/* FUNCTION CookCRS-AddTopRefMode-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_AddTopRefMode_s3 struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_AddTopRefMode_s3;
extern int step_M_AddTopRefMode_s3(Sink,Term);

/* FUNCTION CookN-AttributeKeySortName2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_AttributeKeySortName2 struct _Con_M_AttributeKeySortName2
struct _Con_M_AttributeKeySortName2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_AttributeKeySortName2;
extern int step_M_AttributeKeySortName2(Sink,Term);

/* FUNCTION CookN-KeepInheritedMapEntry2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepInheritedMapEntry2_s5 struct _Con_M_KeepInheritedMapEntry2_s5
struct _Con_M_KeepInheritedMapEntry2_s5 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepInheritedMapEntry2_s5;
extern int step_M_KeepInheritedMapEntry2_s5(Sink,Term);

/* FUNCTION CookN-KeepInheritedMapEntry2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepInheritedMapEntry2_s6 struct _Con_M_KeepInheritedMapEntry2_s6
struct _Con_M_KeepInheritedMapEntry2_s6 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepInheritedMapEntry2_s6;
extern int step_M_KeepInheritedMapEntry2_s6(Sink,Term);

/* FUNCTION Prelude-IfLifted-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_IfLifted_s1 struct _Con_M_IfLifted_s1
struct _Con_M_IfLifted_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_IfLifted_s1;
extern int step_M_IfLifted_s1(Sink,Term);

/* FUNCTION CookN-KeepInheritedMapEntry2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepInheritedMapEntry2_s7 struct _Con_M_KeepInheritedMapEntry2_s7
struct _Con_M_KeepInheritedMapEntry2_s7 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepInheritedMapEntry2_s7;
extern int step_M_KeepInheritedMapEntry2_s7(Sink,Term);

/* FUNCTION CookN-AttributeKeySortName1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_AttributeKeySortName1 struct _Con_M_AttributeKeySortName1
struct _Con_M_AttributeKeySortName1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_AttributeKeySortName1;
extern int step_M_AttributeKeySortName1(Sink,Term);

/* FUNCTION Prelude-IfLifted-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_IfLifted_s2 struct _Con_M_IfLifted_s2
struct _Con_M_IfLifted_s2 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_IfLifted_s2;
extern int step_M_IfLifted_s2(Sink,Term);

/* FUNCTION CookN-KeepInheritedMapEntry2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepInheritedMapEntry2_s8 struct _Con_M_KeepInheritedMapEntry2_s8
struct _Con_M_KeepInheritedMapEntry2_s8 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepInheritedMapEntry2_s8;
extern int step_M_KeepInheritedMapEntry2_s8(Sink,Term);

/* FUNCTION CookPG-PG-Expand-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Expand struct _Con_M_PG_Expand
struct _Con_M_PG_Expand {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_Expand;
extern int step_M_PG_Expand(Sink,Term);

/* FUNCTION Prelude-Or-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_Or_s1 struct _Con_M_Or_s1
struct _Con_M_Or_s1 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_Or_s1;
extern int step_M_Or_s1(Sink,Term);

/* FUNCTION CookN-KeepInheritedMapEntry2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepInheritedMapEntry2_s9 struct _Con_M_KeepInheritedMapEntry2_s9
struct _Con_M_KeepInheritedMapEntry2_s9 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepInheritedMapEntry2_s9;
extern int step_M_KeepInheritedMapEntry2_s9(Sink,Term);

/* FUNCTION Prelude-Or-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_Or_s2 struct _Con_M_Or_s2
struct _Con_M_Or_s2 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_Or_s2;
extern int step_M_Or_s2(Sink,Term);

/* FUNCTION CookN-_InsertDefines- HEADER DECLARATIONS. */
#define STRUCT_Con_M__xInsertDefines struct _Con_M__xInsertDefines
struct _Con_M__xInsertDefines {struct _Construction construction; Term sub[4]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M__xInsertDefines;
extern int step_M__xInsertDefines(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBodyTerm1x-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBodyTerm1x_s2 struct _Con_M_PG_ProduceBodyTerm1x_s2
struct _Con_M_PG_ProduceBodyTerm1x_s2 {struct _Construction construction; Term sub[17]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBodyTerm1x_s2;
extern int step_M_PG_ProduceBodyTerm1x_s2(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBodyTerm1x-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBodyTerm1x_s1 struct _Con_M_PG_ProduceBodyTerm1x_s1
struct _Con_M_PG_ProduceBodyTerm1x_s1 {struct _Construction construction; Term sub[17]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBodyTerm1x_s1;
extern int step_M_PG_ProduceBodyTerm1x_s1(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Attribute-1$DerivedSorts-Attribute$RAW-Attribute HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Attribute struct _Con_M_DerivedSorts_Attribute
struct _Con_M_DerivedSorts_Attribute {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Attribute;
extern int step_M_DerivedSorts_Attribute(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-Derived2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_Derived2 struct _Con_M_CRS_Rules_Derived2
struct _Con_M_CRS_Rules_Derived2 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_Derived2;
extern int step_M_CRS_Rules_Derived2(Sink,Term);

/* FUNCTION CookN-KeepInheritedMapEntry2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepInheritedMapEntry2_s1 struct _Con_M_KeepInheritedMapEntry2_s1
struct _Con_M_KeepInheritedMapEntry2_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepInheritedMapEntry2_s1;
extern int step_M_KeepInheritedMapEntry2_s1(Sink,Term);

/* FUNCTION CookN-KeepInheritedMapEntry2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepInheritedMapEntry2_s2 struct _Con_M_KeepInheritedMapEntry2_s2
struct _Con_M_KeepInheritedMapEntry2_s2 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepInheritedMapEntry2_s2;
extern int step_M_KeepInheritedMapEntry2_s2(Sink,Term);

/* FUNCTION CookN-KeepInheritedMapEntry2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepInheritedMapEntry2_s4 struct _Con_M_KeepInheritedMapEntry2_s4
struct _Con_M_KeepInheritedMapEntry2_s4 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepInheritedMapEntry2_s4;
extern int step_M_KeepInheritedMapEntry2_s4(Sink,Term);

/* FUNCTION Prelude-IfSingleton-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_IfSingleton_s1 struct _Con_M_IfSingleton_s1
struct _Con_M_IfSingleton_s1 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_IfSingleton_s1;
extern int step_M_IfSingleton_s1(Sink,Term);

/* FUNCTION Prelude-IfSingleton-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_IfSingleton_s2 struct _Con_M_IfSingleton_s2
struct _Con_M_IfSingleton_s2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_IfSingleton_s2;
extern int step_M_IfSingleton_s2(Sink,Term);

/* FUNCTION CookBase-ProductionName-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ProductionName struct _Con_M_ProductionName
struct _Con_M_ProductionName {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ProductionName;
extern int step_M_ProductionName(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBody1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBody1_s10 struct _Con_M_PG_ProduceBody1_s10
struct _Con_M_PG_ProduceBody1_s10 {struct _Construction construction; Term sub[5]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBody1_s10;
extern int step_M_PG_ProduceBody1_s10(Sink,Term);

/* FUNCTION CookPG-PG-InlineRegExpChoice- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_InlineRegExpChoice struct _Con_M_PG_InlineRegExpChoice
struct _Con_M_PG_InlineRegExpChoice {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_InlineRegExpChoice;
extern int step_M_PG_InlineRegExpChoice(Sink,Term);

/* FUNCTION CookN-KeepInheritedMapEntry2-2$KeepInheritedMapEntry2$ HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepInheritedMapEntry2 struct _Con_M_KeepInheritedMapEntry2
struct _Con_M_KeepInheritedMapEntry2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepInheritedMapEntry2;
extern int step_M_KeepInheritedMapEntry2(Sink,Term);

/* FUNCTION CookN-KeepInheritedMapEntry1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepInheritedMapEntry1 struct _Con_M_KeepInheritedMapEntry1
struct _Con_M_KeepInheritedMapEntry1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepInheritedMapEntry1;
extern int step_M_KeepInheritedMapEntry1(Sink,Term);

/* FUNCTION CookPG-PG-InlineRegExpClass1- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_InlineRegExpClass1 struct _Con_M_PG_InlineRegExpClass1
struct _Con_M_PG_InlineRegExpClass1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_InlineRegExpClass1;
extern int step_M_PG_InlineRegExpClass1(Sink,Term);

/* FUNCTION CookCRS-MapWrapperConstruction- HEADER DECLARATIONS. */
#define STRUCT_Con_M_MapWrapperConstruction struct _Con_M_MapWrapperConstruction
struct _Con_M_MapWrapperConstruction {struct _Construction construction; Term sub[2]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M_MapWrapperConstruction;
extern int step_M_MapWrapperConstruction(Sink,Term);

/* FUNCTION CookPG-PG-InlineRegExpClass2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_InlineRegExpClass2 struct _Con_M_PG_InlineRegExpClass2
struct _Con_M_PG_InlineRegExpClass2 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_InlineRegExpClass2;
extern int step_M_PG_InlineRegExpClass2(Sink,Term);

/* FUNCTION CookN-N-InitOtherMaps-1$N-InitOtherMaps HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_InitOtherMaps struct _Con_M_N_InitOtherMaps
struct _Con_M_N_InitOtherMaps {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_InitOtherMaps;
extern int step_M_N_InitOtherMaps(Sink,Term);

/* FUNCTION CookN-Then-DerivedSorts-Defines-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_Then_DerivedSorts_Defines_s2 struct _Con_M_Then_DerivedSorts_Defines_s2
struct _Con_M_Then_DerivedSorts_Defines_s2 {struct _Construction construction; Term sub[3]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M_Then_DerivedSorts_Defines_s2;
extern int step_M_Then_DerivedSorts_Defines_s2(Sink,Term);

/* FUNCTION CookN-N-Finish5- HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_Finish5 struct _Con_M_N_Finish5
struct _Con_M_N_Finish5 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_Finish5;
extern int step_M_N_Finish5(Sink,Term);

/* FUNCTION CookN-Then-DerivedSorts-Defines- HEADER DECLARATIONS. */
#define STRUCT_Con_M_Then_DerivedSorts_Defines_s1 struct _Con_M_Then_DerivedSorts_Defines_s1
struct _Con_M_Then_DerivedSorts_Defines_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_Then_DerivedSorts_Defines_s1;
extern int step_M_Then_DerivedSorts_Defines_s1(Sink,Term);

/* FUNCTION CookN-N-Finish4-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_Finish4 struct _Con_M_N_Finish4
struct _Con_M_N_Finish4 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_Finish4;
extern int step_M_N_Finish4(Sink,Term);

/* FUNCTION CookN-Then-DerivedSorts-Defines-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_Then_DerivedSorts_Defines_s4 struct _Con_M_Then_DerivedSorts_Defines_s4
struct _Con_M_Then_DerivedSorts_Defines_s4 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_Then_DerivedSorts_Defines_s4;
extern int step_M_Then_DerivedSorts_Defines_s4(Sink,Term);

/* FUNCTION CookN-N-Finish3- HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_Finish3 struct _Con_M_N_Finish3
struct _Con_M_N_Finish3 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_Finish3;
extern int step_M_N_Finish3(Sink,Term);

/* FUNCTION CookN-Then-DerivedSorts-Defines-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_Then_DerivedSorts_Defines_s3 struct _Con_M_Then_DerivedSorts_Defines_s3
struct _Con_M_Then_DerivedSorts_Defines_s3 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_Then_DerivedSorts_Defines_s3;
extern int step_M_Then_DerivedSorts_Defines_s3(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules1- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules1 struct _Con_M_CRS_Rules1
struct _Con_M_CRS_Rules1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules1;
extern int step_M_CRS_Rules1(Sink,Term);

/* FUNCTION CookN-N-Finish2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_Finish2 struct _Con_M_N_Finish2
struct _Con_M_N_Finish2 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_Finish2;
extern int step_M_N_Finish2(Sink,Term);

/* FUNCTION Prelude-Fold2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_Fold2_s5 struct _Con_M_Fold2_s5
struct _Con_M_Fold2_s5 {struct _Construction construction; Term sub[4]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M_Fold2_s5;
extern int step_M_Fold2_s5(Sink,Term);

/* FUNCTION CookN-N-Finish9-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_Finish9 struct _Con_M_N_Finish9
struct _Con_M_N_Finish9 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_Finish9;
extern int step_M_N_Finish9(Sink,Term);

/* FUNCTION CookN-Then-DerivedSorts-Defines-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_Then_DerivedSorts_Defines_s5 struct _Con_M_Then_DerivedSorts_Defines_s5
struct _Con_M_Then_DerivedSorts_Defines_s5 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_Then_DerivedSorts_Defines_s5;
extern int step_M_Then_DerivedSorts_Defines_s5(Sink,Term);

/* FUNCTION Prelude-Fold2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_Fold2_s6 struct _Con_M_Fold2_s6
struct _Con_M_Fold2_s6 {struct _Construction construction; Term sub[3]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M_Fold2_s6;
extern int step_M_Fold2_s6(Sink,Term);

/* FUNCTION Prelude-Fold2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_Fold2_s3 struct _Con_M_Fold2_s3
struct _Con_M_Fold2_s3 {struct _Construction construction; Term sub[5]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M_Fold2_s3;
extern int step_M_Fold2_s3(Sink,Term);

/* FUNCTION CookN-N-Finish7-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_Finish7 struct _Con_M_N_Finish7
struct _Con_M_N_Finish7 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_Finish7;
extern int step_M_N_Finish7(Sink,Term);

/* FUNCTION Prelude-Fold2-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_Fold2_s4 struct _Con_M_Fold2_s4
struct _Con_M_Fold2_s4 {struct _Construction construction; Term sub[6]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M_Fold2_s4;
extern int step_M_Fold2_s4(Sink,Term);

/* FUNCTION CookN-N-Finish6-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_Finish6 struct _Con_M_N_Finish6
struct _Con_M_N_Finish6 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_Finish6;
extern int step_M_N_Finish6(Sink,Term);

/* FUNCTION CookN-KeepSynthesizedEntry-1$KeepSynthesizedEntry$OK HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepSynthesizedEntry struct _Con_M_KeepSynthesizedEntry
struct _Con_M_KeepSynthesizedEntry {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepSynthesizedEntry;
extern int step_M_KeepSynthesizedEntry(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Sort-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Sort struct _Con_M_DerivedSorts_Sort
struct _Con_M_DerivedSorts_Sort {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Sort;
extern int step_M_DerivedSorts_Sort(Sink,Term);

/* FUNCTION Prelude-WrappedTextFold- HEADER DECLARATIONS. */
#define STRUCT_Con_M_WrappedTextFold struct _Con_M_WrappedTextFold
struct _Con_M_WrappedTextFold {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_WrappedTextFold;
extern int step_M_WrappedTextFold(Sink,Term);

/* FUNCTION CookCRS-CRS-Declarations-TokenSynth-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declarations_TokenSynth_s1 struct _Con_M_CRS_Declarations_TokenSynth_s1
struct _Con_M_CRS_Declarations_TokenSynth_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declarations_TokenSynth_s1;
extern int step_M_CRS_Declarations_TokenSynth_s1(Sink,Term);

/* FUNCTION CookBase-FullName-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_FullName struct _Con_M_FullName
struct _Con_M_FullName {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_FullName;
extern int step_M_FullName(Sink,Term);

/* FUNCTION CookCRS-_Hash-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xHash struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M__xHash;
extern int step_M__xHash(Sink,Term);

/* FUNCTION CookPG-PG-isLeftRecursive-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG__isLeftRecursive_s3 struct _Con_M_PG__isLeftRecursive_s3
struct _Con_M_PG__isLeftRecursive_s3 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG__isLeftRecursive_s3;
extern int step_M_PG__isLeftRecursive_s3(Sink,Term);

/* FUNCTION CookPG-PG-isLeftRecursive-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG__isLeftRecursive_s4 struct _Con_M_PG__isLeftRecursive_s4
struct _Con_M_PG__isLeftRecursive_s4 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG__isLeftRecursive_s4;
extern int step_M_PG__isLeftRecursive_s4(Sink,Term);

/* FUNCTION Prelude-FirstName-1$FirstName$NAME_SET HEADER DECLARATIONS. */
#define STRUCT_Con_M_FirstName struct _Con_M_FirstName
struct _Con_M_FirstName {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_FirstName;
extern int step_M_FirstName(Sink,Term);

/* FUNCTION CookPG-PG-isLeftRecursive-3$PG-isLeftRecursive$1$PFK HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG__isLeftRecursive_s1 struct _Con_M_PG__isLeftRecursive_s1
struct _Con_M_PG__isLeftRecursive_s1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG__isLeftRecursive_s1;
extern int step_M_PG__isLeftRecursive_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-Priority-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Priority_s3 struct _Con_M_CRS_Priority_s3
struct _Con_M_CRS_Priority_s3 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Priority_s3;
extern int step_M_CRS_Priority_s3(Sink,Term);

/* FUNCTION CookPG-PG-isLeftRecursive- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG__isLeftRecursive_s2 struct _Con_M_PG__isLeftRecursive_s2
struct _Con_M_PG__isLeftRecursive_s2 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG__isLeftRecursive_s2;
extern int step_M_PG__isLeftRecursive_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-Priority-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Priority_s1 struct _Con_M_CRS_Priority_s1
struct _Con_M_CRS_Priority_s1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Priority_s1;
extern int step_M_CRS_Priority_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-Priority-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Priority_s2 struct _Con_M_CRS_Priority_s2
struct _Con_M_CRS_Priority_s2 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Priority_s2;
extern int step_M_CRS_Priority_s2(Sink,Term);

/* FUNCTION CookN-N-then-Finish7-1$N-then-Finish7$OK HEADER DECLARATIONS. */
#define STRUCT_Con_M_N__then_Finish7 struct _Con_M_N__then_Finish7
struct _Con_M_N__then_Finish7 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N__then_Finish7;
extern int step_M_N__then_Finish7(Sink,Term);

/* FUNCTION CookPG-PG-isLeftRecursive-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG__isLeftRecursive_s5 struct _Con_M_PG__isLeftRecursive_s5
struct _Con_M_PG__isLeftRecursive_s5 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG__isLeftRecursive_s5;
extern int step_M_PG__isLeftRecursive_s5(Sink,Term);

/* FUNCTION CookPG-PG-isLeftRecursive-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG__isLeftRecursive_s6 struct _Con_M_PG__isLeftRecursive_s6
struct _Con_M_PG__isLeftRecursive_s6 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG__isLeftRecursive_s6;
extern int step_M_PG__isLeftRecursive_s6(Sink,Term);

/* FUNCTION CookPG-PG-DeclareRegExpUnits- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_DeclareRegExpUnits struct _Con_M_PG_DeclareRegExpUnits
struct _Con_M_PG_DeclareRegExpUnits {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_DeclareRegExpUnits;
extern int step_M_PG_DeclareRegExpUnits(Sink,Term);

/* FUNCTION CookN-KeepInheritedMapEntry-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepInheritedMapEntry_s1 struct _Con_M_KeepInheritedMapEntry_s1
struct _Con_M_KeepInheritedMapEntry_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepInheritedMapEntry_s1;
extern int step_M_KeepInheritedMapEntry_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-AttributeGroups-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AttributeGroups_s3 struct _Con_M_CRS_AttributeGroups_s3
struct _Con_M_CRS_AttributeGroups_s3 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AttributeGroups_s3;
extern int step_M_CRS_AttributeGroups_s3(Sink,Term);

/* FUNCTION CookCRS-CRS-AttributeValues-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AttributeValues_s8 struct _Con_M_CRS_AttributeValues_s8
struct _Con_M_CRS_AttributeValues_s8 {struct _Construction construction; Term sub[10]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AttributeValues_s8;
extern int step_M_CRS_AttributeValues_s8(Sink,Term);

/* FUNCTION CookCRS-CRS-AttributeGroups- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AttributeGroups_s2 struct _Con_M_CRS_AttributeGroups_s2
struct _Con_M_CRS_AttributeGroups_s2 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AttributeGroups_s2;
extern int step_M_CRS_AttributeGroups_s2(Sink,Term);

/* FUNCTION CookBase-SortVar2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortVar2 struct _Con_M_SortVar2
struct _Con_M_SortVar2 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortVar2;
extern int step_M_SortVar2(Sink,Term);

/* FUNCTION CookCRS-CRS-AttributeValues-7 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AttributeValues_s7 struct _Con_M_CRS_AttributeValues_s7
struct _Con_M_CRS_AttributeValues_s7 {struct _Construction construction; Term sub[10]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AttributeValues_s7;
extern int step_M_CRS_AttributeValues_s7(Sink,Term);

/* FUNCTION CookCRS-CRS-AttributeGroups-4$CRS-AttributeGroups$1$RAW-Attribute HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AttributeGroups_s1 struct _Con_M_CRS_AttributeGroups_s1
struct _Con_M_CRS_AttributeGroups_s1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AttributeGroups_s1;
extern int step_M_CRS_AttributeGroups_s1(Sink,Term);

/* FUNCTION CookN-KeepInheritedEntry1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepInheritedEntry1 struct _Con_M_KeepInheritedEntry1
struct _Con_M_KeepInheritedEntry1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepInheritedEntry1;
extern int step_M_KeepInheritedEntry1(Sink,Term);

/* FUNCTION CookN-KeepInheritedEntry2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepInheritedEntry2 struct _Con_M_KeepInheritedEntry2
struct _Con_M_KeepInheritedEntry2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepInheritedEntry2;
extern int step_M_KeepInheritedEntry2(Sink,Term);

/* FUNCTION CookCRS-CRS-AttributeValues- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AttributeValues_s2 struct _Con_M_CRS_AttributeValues_s2
struct _Con_M_CRS_AttributeValues_s2 {struct _Construction construction; Term sub[9]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AttributeValues_s2;
extern int step_M_CRS_AttributeValues_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-AttributeValues-4$CRS-AttributeValues$1$RAW-Attribute HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AttributeValues_s1 struct _Con_M_CRS_AttributeValues_s1
struct _Con_M_CRS_AttributeValues_s1 {struct _Construction construction; Term sub[6]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AttributeValues_s1;
extern int step_M_CRS_AttributeValues_s1(Sink,Term);

/* FUNCTION CookBase-SortMetaVar2-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortMetaVar2_s9 struct _Con_M_SortMetaVar2_s9
struct _Con_M_SortMetaVar2_s9 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortMetaVar2_s9;
extern int step_M_SortMetaVar2_s9(Sink,Term);

/* FUNCTION CookCRS-CRS-AttributeValues-5 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AttributeValues_s6 struct _Con_M_CRS_AttributeValues_s6
struct _Con_M_CRS_AttributeValues_s6 {struct _Construction construction; Term sub[11]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AttributeValues_s6;
extern int step_M_CRS_AttributeValues_s6(Sink,Term);

/* FUNCTION CookCRS-CRS-AttributeGroups-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AttributeGroups_s8 struct _Con_M_CRS_AttributeGroups_s8
struct _Con_M_CRS_AttributeGroups_s8 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AttributeGroups_s8;
extern int step_M_CRS_AttributeGroups_s8(Sink,Term);

/* FUNCTION CookCRS-CRS-then-RepeatRules-3$CRS-then-RepeatRules$OK HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS__then_RepeatRules struct _Con_M_CRS__then_RepeatRules
struct _Con_M_CRS__then_RepeatRules {struct _Construction construction; Term sub[14]; Variable binder[9];};
extern struct _ConstructionDescriptor descriptor_M_CRS__then_RepeatRules;
extern int step_M_CRS__then_RepeatRules(Sink,Term);

/* FUNCTION CookBase-SortMetaVar2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortMetaVar2_s8 struct _Con_M_SortMetaVar2_s8
struct _Con_M_SortMetaVar2_s8 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortMetaVar2_s8;
extern int step_M_SortMetaVar2_s8(Sink,Term);

/* FUNCTION CookCRS-CRS-AttributeValues-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AttributeValues_s5 struct _Con_M_CRS_AttributeValues_s5
struct _Con_M_CRS_AttributeValues_s5 {struct _Construction construction; Term sub[10]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AttributeValues_s5;
extern int step_M_CRS_AttributeValues_s5(Sink,Term);

/* FUNCTION CookCRS-CRS-AttributeGroups-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AttributeGroups_s7 struct _Con_M_CRS_AttributeGroups_s7
struct _Con_M_CRS_AttributeGroups_s7 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AttributeGroups_s7;
extern int step_M_CRS_AttributeGroups_s7(Sink,Term);

/* FUNCTION Prelude-UnLift-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_UnLift_s1 struct _Con_M_UnLift_s1
struct _Con_M_UnLift_s1 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_UnLift_s1;
extern int step_M_UnLift_s1(Sink,Term);

/* FUNCTION CookBase-SortMetaVar2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortMetaVar2_s7 struct _Con_M_SortMetaVar2_s7
struct _Con_M_SortMetaVar2_s7 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortMetaVar2_s7;
extern int step_M_SortMetaVar2_s7(Sink,Term);

/* FUNCTION CookCRS-CRS-AttributeValues- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AttributeValues_s4 struct _Con_M_CRS_AttributeValues_s4
struct _Con_M_CRS_AttributeValues_s4 {struct _Construction construction; Term sub[9]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AttributeValues_s4;
extern int step_M_CRS_AttributeValues_s4(Sink,Term);

/* FUNCTION CookCRS-CRS-AttributeGroups-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AttributeGroups_s6 struct _Con_M_CRS_AttributeGroups_s6
struct _Con_M_CRS_AttributeGroups_s6 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AttributeGroups_s6;
extern int step_M_CRS_AttributeGroups_s6(Sink,Term);

/* FUNCTION CookCRS-CRS-Form-PatternEnv2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Form_PatternEnv2_s11 struct _Con_M_CRS_Form_PatternEnv2_s11
struct _Con_M_CRS_Form_PatternEnv2_s11 {struct _Construction construction; Term sub[9]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Form_PatternEnv2_s11;
extern int step_M_CRS_Form_PatternEnv2_s11(Sink,Term);

/* FUNCTION CookBase-SortMetaVar2-1$SortMetaVar2$6$$Nil HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortMetaVar2_s6 struct _Con_M_SortMetaVar2_s6
struct _Con_M_SortMetaVar2_s6 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortMetaVar2_s6;
extern int step_M_SortMetaVar2_s6(Sink,Term);

/* FUNCTION CookCRS-CRS-AttributeGroups- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AttributeGroups_s5 struct _Con_M_CRS_AttributeGroups_s5
struct _Con_M_CRS_AttributeGroups_s5 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AttributeGroups_s5;
extern int step_M_CRS_AttributeGroups_s5(Sink,Term);

/* FUNCTION CookCRS-CRS-Form-PatternEnv2-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Form_PatternEnv2_s10 struct _Con_M_CRS_Form_PatternEnv2_s10
struct _Con_M_CRS_Form_PatternEnv2_s10 {struct _Construction construction; Term sub[9]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Form_PatternEnv2_s10;
extern int step_M_CRS_Form_PatternEnv2_s10(Sink,Term);

/* FUNCTION CookCRS-IfRefModeHides- HEADER DECLARATIONS. */
#define STRUCT_Con_M_IfRefModeHides struct _Con_M_IfRefModeHides
struct _Con_M_IfRefModeHides {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_IfRefModeHides;
extern int step_M_IfRefModeHides(Sink,Term);

/* FUNCTION CookPG-PG-1$PG$RAW-top-module HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG struct _Con_M_PG
struct _Con_M_PG {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG;
extern int step_M_PG(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Attributes-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Attributes_s1 struct _Con_M_DerivedSorts_Attributes_s1
struct _Con_M_DerivedSorts_Attributes_s1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Attributes_s1;
extern int step_M_DerivedSorts_Attributes_s1(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Attributes-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Attributes_s2 struct _Con_M_DerivedSorts_Attributes_s2
struct _Con_M_DerivedSorts_Attributes_s2 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Attributes_s2;
extern int step_M_DerivedSorts_Attributes_s2(Sink,Term);

/* FUNCTION CookN-N-Finish0-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_Finish0 struct _Con_M_N_Finish0
struct _Con_M_N_Finish0 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_Finish0;
extern int step_M_N_Finish0(Sink,Term);

/* FUNCTION CookN-N-Finish1- HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_Finish1 struct _Con_M_N_Finish1
struct _Con_M_N_Finish1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_Finish1;
extern int step_M_N_Finish1(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBodyTerm1-5 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBodyTerm1_s7 struct _Con_M_PG_ProduceBodyTerm1_s7
struct _Con_M_PG_ProduceBodyTerm1_s7 {struct _Construction construction; Term sub[11]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBodyTerm1_s7;
extern int step_M_PG_ProduceBodyTerm1_s7(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBodyTerm1-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBodyTerm1_s3 struct _Con_M_PG_ProduceBodyTerm1_s3
struct _Con_M_PG_ProduceBodyTerm1_s3 {struct _Construction construction; Term sub[14]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBodyTerm1_s3;
extern int step_M_PG_ProduceBodyTerm1_s3(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBodyTerm1-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBodyTerm1_s4 struct _Con_M_PG_ProduceBodyTerm1_s4
struct _Con_M_PG_ProduceBodyTerm1_s4 {struct _Construction construction; Term sub[16]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBodyTerm1_s4;
extern int step_M_PG_ProduceBodyTerm1_s4(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBodyTerm1-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBodyTerm1_s5 struct _Con_M_PG_ProduceBodyTerm1_s5
struct _Con_M_PG_ProduceBodyTerm1_s5 {struct _Construction construction; Term sub[18]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBodyTerm1_s5;
extern int step_M_PG_ProduceBodyTerm1_s5(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBodyTerm1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBodyTerm1_s6 struct _Con_M_PG_ProduceBodyTerm1_s6
struct _Con_M_PG_ProduceBodyTerm1_s6 {struct _Construction construction; Term sub[16]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBodyTerm1_s6;
extern int step_M_PG_ProduceBodyTerm1_s6(Sink,Term);

/* FUNCTION CookCRS-CRS-Priority- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Priority struct _Con_M_CRS_Priority
struct _Con_M_CRS_Priority {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Priority;
extern int step_M_CRS_Priority(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBodyTerm1-4$PG-ProduceBodyTerm1$1$PFK HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBodyTerm1_s1 struct _Con_M_PG_ProduceBodyTerm1_s1
struct _Con_M_PG_ProduceBodyTerm1_s1 {struct _Construction construction; Term sub[13]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBodyTerm1_s1;
extern int step_M_PG_ProduceBodyTerm1_s1(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBodyTerm1- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBodyTerm1_s2 struct _Con_M_PG_ProduceBodyTerm1_s2
struct _Con_M_PG_ProduceBodyTerm1_s2 {struct _Construction construction; Term sub[14]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBodyTerm1_s2;
extern int step_M_PG_ProduceBodyTerm1_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-then-RepeatRules-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS__then_RepeatRules_s3 struct _Con_M_CRS__then_RepeatRules_s3
struct _Con_M_CRS__then_RepeatRules_s3 {struct _Construction construction; Term sub[13]; Variable binder[9];};
extern struct _ConstructionDescriptor descriptor_M_CRS__then_RepeatRules_s3;
extern int step_M_CRS__then_RepeatRules_s3(Sink,Term);

/* FUNCTION CookN-N-FormInheritedAttributes-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_FormInheritedAttributes_s2 struct _Con_M_N_FormInheritedAttributes_s2
struct _Con_M_N_FormInheritedAttributes_s2 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_FormInheritedAttributes_s2;
extern int step_M_N_FormInheritedAttributes_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-then-RepeatRules-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS__then_RepeatRules_s4 struct _Con_M_CRS__then_RepeatRules_s4
struct _Con_M_CRS__then_RepeatRules_s4 {struct _Construction construction; Term sub[13]; Variable binder[9];};
extern struct _ConstructionDescriptor descriptor_M_CRS__then_RepeatRules_s4;
extern int step_M_CRS__then_RepeatRules_s4(Sink,Term);

/* FUNCTION CookN-N-FormInheritedAttributes-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_FormInheritedAttributes_s3 struct _Con_M_N_FormInheritedAttributes_s3
struct _Con_M_N_FormInheritedAttributes_s3 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_FormInheritedAttributes_s3;
extern int step_M_N_FormInheritedAttributes_s3(Sink,Term);

/* FUNCTION CookCRS-CRS-then-RepeatRules-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS__then_RepeatRules_s5 struct _Con_M_CRS__then_RepeatRules_s5
struct _Con_M_CRS__then_RepeatRules_s5 {struct _Construction construction; Term sub[13]; Variable binder[9];};
extern struct _ConstructionDescriptor descriptor_M_CRS__then_RepeatRules_s5;
extern int step_M_CRS__then_RepeatRules_s5(Sink,Term);

/* FUNCTION CookCRS-CRS-then-RepeatRules-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS__then_RepeatRules_s6 struct _Con_M_CRS__then_RepeatRules_s6
struct _Con_M_CRS__then_RepeatRules_s6 {struct _Construction construction; Term sub[14]; Variable binder[9];};
extern struct _ConstructionDescriptor descriptor_M_CRS__then_RepeatRules_s6;
extern int step_M_CRS__then_RepeatRules_s6(Sink,Term);

/* FUNCTION CookCRS-CRS-Term-Core-5 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Term_Core_s4 struct _Con_M_CRS_Term_Core_s4
struct _Con_M_CRS_Term_Core_s4 {struct _Construction construction; Term sub[10]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Term_Core_s4;
extern int step_M_CRS_Term_Core_s4(Sink,Term);

/* FUNCTION CookCRS-CRS-Term-Core-10 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Term_Core_s3 struct _Con_M_CRS_Term_Core_s3
struct _Con_M_CRS_Term_Core_s3 {struct _Construction construction; Term sub[9]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Term_Core_s3;
extern int step_M_CRS_Term_Core_s3(Sink,Term);

/* FUNCTION CookPG-PG-Production-Defines2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Production_Defines2 struct _Con_M_PG_Production_Defines2
struct _Con_M_PG_Production_Defines2 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_Production_Defines2;
extern int step_M_PG_Production_Defines2(Sink,Term);

/* FUNCTION CookCRS-CRS-Term-Core-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Term_Core_s2 struct _Con_M_CRS_Term_Core_s2
struct _Con_M_CRS_Term_Core_s2 {struct _Construction construction; Term sub[12]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Term_Core_s2;
extern int step_M_CRS_Term_Core_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-Term-Core-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Term_Core_s1 struct _Con_M_CRS_Term_Core_s1
struct _Con_M_CRS_Term_Core_s1 {struct _Construction construction; Term sub[10]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Term_Core_s1;
extern int step_M_CRS_Term_Core_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-then-RepeatRules- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS__then_RepeatRules_s2 struct _Con_M_CRS__then_RepeatRules_s2
struct _Con_M_CRS__then_RepeatRules_s2 {struct _Construction construction; Term sub[13]; Variable binder[9];};
extern struct _ConstructionDescriptor descriptor_M_CRS__then_RepeatRules_s2;
extern int step_M_CRS__then_RepeatRules_s2(Sink,Term);

/* FUNCTION CookN-N-FormInheritedAttributes-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_FormInheritedAttributes_s1 struct _Con_M_N_FormInheritedAttributes_s1
struct _Con_M_N_FormInheritedAttributes_s1 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_FormInheritedAttributes_s1;
extern int step_M_N_FormInheritedAttributes_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-Term-Core-9 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Term_Core_s8 struct _Con_M_CRS_Term_Core_s8
struct _Con_M_CRS_Term_Core_s8 {struct _Construction construction; Term sub[9]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Term_Core_s8;
extern int step_M_CRS_Term_Core_s8(Sink,Term);

/* FUNCTION CookCRS-CRS-Term-Core-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Term_Core_s7 struct _Con_M_CRS_Term_Core_s7
struct _Con_M_CRS_Term_Core_s7 {struct _Construction construction; Term sub[11]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Term_Core_s7;
extern int step_M_CRS_Term_Core_s7(Sink,Term);

/* FUNCTION CookBase-SortMetaVar2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortMetaVar2_s1 struct _Con_M_SortMetaVar2_s1
struct _Con_M_SortMetaVar2_s1 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortMetaVar2_s1;
extern int step_M_SortMetaVar2_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-Term-Core-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Term_Core_s6 struct _Con_M_CRS_Term_Core_s6
struct _Con_M_CRS_Term_Core_s6 {struct _Construction construction; Term sub[9]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Term_Core_s6;
extern int step_M_CRS_Term_Core_s6(Sink,Term);

/* FUNCTION CookN-N-SortAlternativesDefines-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_SortAlternativesDefines_s2 struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_N_SortAlternativesDefines_s2;
extern int step_M_N_SortAlternativesDefines_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-Term-Core-6 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Term_Core_s5 struct _Con_M_CRS_Term_Core_s5
struct _Con_M_CRS_Term_Core_s5 {struct _Construction construction; Term sub[12]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Term_Core_s5;
extern int step_M_CRS_Term_Core_s5(Sink,Term);

/* FUNCTION CookN-N-SortAlternativesDefines-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_SortAlternativesDefines_s1 struct _Con_M_N_SortAlternativesDefines_s1
struct _Con_M_N_SortAlternativesDefines_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_SortAlternativesDefines_s1;
extern int step_M_N_SortAlternativesDefines_s1(Sink,Term);

/* FUNCTION CookBase-SortMetaVar2-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortMetaVar2_s2 struct _Con_M_SortMetaVar2_s2
struct _Con_M_SortMetaVar2_s2 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortMetaVar2_s2;
extern int step_M_SortMetaVar2_s2(Sink,Term);

/* FUNCTION CookBase-SortMetaVar2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortMetaVar2_s4 struct _Con_M_SortMetaVar2_s4
struct _Con_M_SortMetaVar2_s4 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortMetaVar2_s4;
extern int step_M_SortMetaVar2_s4(Sink,Term);

/* FUNCTION CookCRS-CRS-Term-Core-7 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Term_Core_s9 struct _Con_M_CRS_Term_Core_s9
struct _Con_M_CRS_Term_Core_s9 {struct _Construction construction; Term sub[9]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Term_Core_s9;
extern int step_M_CRS_Term_Core_s9(Sink,Term);

/* FUNCTION Prelude-Hd- HEADER DECLARATIONS. */
#define STRUCT_Con_M_Hd struct _Con_M_Hd
struct _Con_M_Hd {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_Hd;
extern int step_M_Hd(Sink,Term);

/* FUNCTION CookCRS-CRS-Attributes4- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Attributes4 struct _Con_M_CRS_Attributes4
struct _Con_M_CRS_Attributes4 {struct _Construction construction; Term sub[5]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Attributes4;
extern int step_M_CRS_Attributes4(Sink,Term);

/* FUNCTION CookN-N-SortAlternatives-Error-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_SortAlternatives_Error struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_N_SortAlternatives_Error;
extern int step_M_N_SortAlternatives_Error(Sink,Term);

/* FUNCTION CookCRS-CRS-Attributes1- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Attributes1 struct _Con_M_CRS_Attributes1
struct _Con_M_CRS_Attributes1 {struct _Construction construction; Term sub[4]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Attributes1;
extern int step_M_CRS_Attributes1(Sink,Term);

/* FUNCTION CookCRS-CRS-Attributes3-1$CRS-Attributes3$AM HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Attributes3 struct _Con_M_CRS_Attributes3
struct _Con_M_CRS_Attributes3 {struct _Construction construction; Term sub[4]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Attributes3;
extern int step_M_CRS_Attributes3(Sink,Term);

/* FUNCTION CookCRS-CRS-Attributes2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Attributes2 struct _Con_M_CRS_Attributes2
struct _Con_M_CRS_Attributes2 {struct _Construction construction; Term sub[4]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Attributes2;
extern int step_M_CRS_Attributes2(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules1-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules1_s2 struct _Con_M_CRS_Rules1_s2
struct _Con_M_CRS_Rules1_s2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules1_s2;
extern int step_M_CRS_Rules1_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules1_s1 struct _Con_M_CRS_Rules1_s1
struct _Con_M_CRS_Rules1_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules1_s1;
extern int step_M_CRS_Rules1_s1(Sink,Term);

/* FUNCTION CookBase-MakeLocation-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_MakeLocation struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_MakeLocation;
extern int step_M_MakeLocation(Sink,Term);

/* FUNCTION Prelude-StringToText-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_StringToText struct _Con_M_StringToText
struct _Con_M_StringToText {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_StringToText;
extern int step_M_StringToText(Sink,Term);

/* FUNCTION CookN-KeepSynthesizedMapEntry2-2$KeepSynthesizedMapEntry2$ HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepSynthesizedMapEntry2 struct _Con_M_KeepSynthesizedMapEntry2
struct _Con_M_KeepSynthesizedMapEntry2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepSynthesizedMapEntry2;
extern int step_M_KeepSynthesizedMapEntry2(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-Defines- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_Defines struct _Con_M_CRS_Rules_Defines
struct _Con_M_CRS_Rules_Defines {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_Defines;
extern int step_M_CRS_Rules_Defines(Sink,Term);

/* FUNCTION CookN-KeepSynthesizedMapEntry1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepSynthesizedMapEntry1 struct _Con_M_KeepSynthesizedMapEntry1
struct _Con_M_KeepSynthesizedMapEntry1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepSynthesizedMapEntry1;
extern int step_M_KeepSynthesizedMapEntry1(Sink,Term);

/* FUNCTION Prelude-Stringify-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_Stringify struct _Con_M_Stringify
struct _Con_M_Stringify {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_Stringify;
extern int step_M_Stringify(Sink,Term);

/* FUNCTION CookCRS-CRS-Embed-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Embed struct _Con_M_CRS_Embed
struct _Con_M_CRS_Embed {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Embed;
extern int step_M_CRS_Embed(Sink,Term);

/* FUNCTION Prelude-Fold2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_Fold2_s1 struct _Con_M_Fold2_s1
struct _Con_M_Fold2_s1 {struct _Construction construction; Term sub[4]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M_Fold2_s1;
extern int step_M_Fold2_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-then-Rules-DataSynth-It-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS__then_Rules_DataSynth_It_s1 struct _Con_M_CRS__then_Rules_DataSynth_It_s1
struct _Con_M_CRS__then_Rules_DataSynth_It_s1 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS__then_Rules_DataSynth_It_s1;
extern int step_M_CRS__then_Rules_DataSynth_It_s1(Sink,Term);

/* FUNCTION Prelude-If- HEADER DECLARATIONS. */
#define STRUCT_Con_M_If struct _Con_M_If
struct _Con_M_If {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_If;
extern int step_M_If(Sink,Term);

/* FUNCTION CookBase-TermTopSort- HEADER DECLARATIONS. */
#define STRUCT_Con_M_TermTopSort struct _Con_M_TermTopSort
struct _Con_M_TermTopSort {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_TermTopSort;
extern int step_M_TermTopSort(Sink,Term);

/* FUNCTION CookN-DerivedSorts2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts2 struct _Con_M_DerivedSorts2
struct _Con_M_DerivedSorts2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts2;
extern int step_M_DerivedSorts2(Sink,Term);

/* FUNCTION CookPG-ProductionNames2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ProductionNames2_s2 struct _Con_M_ProductionNames2_s2
struct _Con_M_ProductionNames2_s2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ProductionNames2_s2;
extern int step_M_ProductionNames2_s2(Sink,Term);

/* FUNCTION CookPG-PG-Production-Defines2-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Production_Defines2_s1 struct _Con_M_PG_Production_Defines2_s1
struct _Con_M_PG_Production_Defines2_s1 {struct _Construction construction; Term sub[9]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_Production_Defines2_s1;
extern int step_M_PG_Production_Defines2_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-Declarations-PrecWrapper- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declarations_PrecWrapper_s1 struct _Con_M_CRS_Declarations_PrecWrapper_s1
struct _Con_M_CRS_Declarations_PrecWrapper_s1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declarations_PrecWrapper_s1;
extern int step_M_CRS_Declarations_PrecWrapper_s1(Sink,Term);

/* FUNCTION CookPG-ProductionNames2-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ProductionNames2_s1 struct _Con_M_ProductionNames2_s1
struct _Con_M_ProductionNames2_s1 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ProductionNames2_s1;
extern int step_M_ProductionNames2_s1(Sink,Term);

/* FUNCTION CookPG-ProductionNames2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ProductionNames2_s4 struct _Con_M_ProductionNames2_s4
struct _Con_M_ProductionNames2_s4 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ProductionNames2_s4;
extern int step_M_ProductionNames2_s4(Sink,Term);

/* FUNCTION CookPG-PG-Production-Defines2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Production_Defines2_s3 struct _Con_M_PG_Production_Defines2_s3
struct _Con_M_PG_Production_Defines2_s3 {struct _Construction construction; Term sub[9]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_Production_Defines2_s3;
extern int step_M_PG_Production_Defines2_s3(Sink,Term);

/* FUNCTION CookCRS-CRS-Declarations-PrecWrapper-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declarations_PrecWrapper_s3 struct _Con_M_CRS_Declarations_PrecWrapper_s3
struct _Con_M_CRS_Declarations_PrecWrapper_s3 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declarations_PrecWrapper_s3;
extern int step_M_CRS_Declarations_PrecWrapper_s3(Sink,Term);

/* FUNCTION CookPG-ProductionNames2-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ProductionNames2_s3 struct _Con_M_ProductionNames2_s3
struct _Con_M_ProductionNames2_s3 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ProductionNames2_s3;
extern int step_M_ProductionNames2_s3(Sink,Term);

/* FUNCTION CookPG-PG-Production-Defines2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Production_Defines2_s2 struct _Con_M_PG_Production_Defines2_s2
struct _Con_M_PG_Production_Defines2_s2 {struct _Construction construction; Term sub[10]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_Production_Defines2_s2;
extern int step_M_PG_Production_Defines2_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-Declarations-PrecWrapper-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declarations_PrecWrapper_s2 struct _Con_M_CRS_Declarations_PrecWrapper_s2
struct _Con_M_CRS_Declarations_PrecWrapper_s2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declarations_PrecWrapper_s2;
extern int step_M_CRS_Declarations_PrecWrapper_s2(Sink,Term);

/* FUNCTION CookPG-PG-Lexical2Tail- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Lexical2Tail struct _Con_M_PG_Lexical2Tail
struct _Con_M_PG_Lexical2Tail {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_Lexical2Tail;
extern int step_M_PG_Lexical2Tail(Sink,Term);

/* FUNCTION CookN-DerivedSorts-ScopeSort- HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_ScopeSort struct _Con_M_DerivedSorts_ScopeSort
struct _Con_M_DerivedSorts_ScopeSort {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_ScopeSort;
extern int step_M_DerivedSorts_ScopeSort(Sink,Term);

/* FUNCTION CookCRS-CRS-Term-Core-8 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Term_Core_s10 struct _Con_M_CRS_Term_Core_s10
struct _Con_M_CRS_Term_Core_s10 {struct _Construction construction; Term sub[11]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Term_Core_s10;
extern int step_M_CRS_Term_Core_s10(Sink,Term);

/* FUNCTION CookN-KeepInheritedEntry2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepInheritedEntry2_s1 struct _Con_M_KeepInheritedEntry2_s1
struct _Con_M_KeepInheritedEntry2_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepInheritedEntry2_s1;
extern int step_M_KeepInheritedEntry2_s1(Sink,Term);

/* FUNCTION CookN-KeepInheritedEntry2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepInheritedEntry2_s2 struct _Con_M_KeepInheritedEntry2_s2
struct _Con_M_KeepInheritedEntry2_s2 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepInheritedEntry2_s2;
extern int step_M_KeepInheritedEntry2_s2(Sink,Term);

/* FUNCTION CookN-KeepInheritedEntry2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepInheritedEntry2_s3 struct _Con_M_KeepInheritedEntry2_s3
struct _Con_M_KeepInheritedEntry2_s3 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepInheritedEntry2_s3;
extern int step_M_KeepInheritedEntry2_s3(Sink,Term);

/* FUNCTION CookBase-SortNameWithRepeat2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortNameWithRepeat2_s1 struct _Con_M_SortNameWithRepeat2_s1
struct _Con_M_SortNameWithRepeat2_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortNameWithRepeat2_s1;
extern int step_M_SortNameWithRepeat2_s1(Sink,Term);

/* FUNCTION CookN-KeepInheritedEntry2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepInheritedEntry2_s4 struct _Con_M_KeepInheritedEntry2_s4
struct _Con_M_KeepInheritedEntry2_s4 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepInheritedEntry2_s4;
extern int step_M_KeepInheritedEntry2_s4(Sink,Term);

/* FUNCTION CookBase-SortNameWithRepeat2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortNameWithRepeat2_s2 struct _Con_M_SortNameWithRepeat2_s2
struct _Con_M_SortNameWithRepeat2_s2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortNameWithRepeat2_s2;
extern int step_M_SortNameWithRepeat2_s2(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Form-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Form_s2 struct _Con_M_DerivedSorts_Form_s2
struct _Con_M_DerivedSorts_Form_s2 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Form_s2;
extern int step_M_DerivedSorts_Form_s2(Sink,Term);

/* FUNCTION CookN-KeepInheritedEntry2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepInheritedEntry2_s5 struct _Con_M_KeepInheritedEntry2_s5
struct _Con_M_KeepInheritedEntry2_s5 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepInheritedEntry2_s5;
extern int step_M_KeepInheritedEntry2_s5(Sink,Term);

/* FUNCTION Prelude-Special_error-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_Special_xerror struct _Con_M_Special_xerror
struct _Con_M_Special_xerror {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_Special_xerror;
extern int step_M_Special_xerror(Sink,Term);

/* FUNCTION CookBase-SortNameWithRepeat2-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortNameWithRepeat2_s3 struct _Con_M_SortNameWithRepeat2_s3
struct _Con_M_SortNameWithRepeat2_s3 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortNameWithRepeat2_s3;
extern int step_M_SortNameWithRepeat2_s3(Sink,Term);

/* FUNCTION CookPG-PG-ProduceDerived-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceDerived_s1 struct _Con_M_PG_ProduceDerived_s1
struct _Con_M_PG_ProduceDerived_s1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceDerived_s1;
extern int step_M_PG_ProduceDerived_s1(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Form-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Form_s1 struct _Con_M_DerivedSorts_Form_s1
struct _Con_M_DerivedSorts_Form_s1 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Form_s1;
extern int step_M_DerivedSorts_Form_s1(Sink,Term);

/* FUNCTION CookN-KeepInheritedEntry2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepInheritedEntry2_s6 struct _Con_M_KeepInheritedEntry2_s6
struct _Con_M_KeepInheritedEntry2_s6 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepInheritedEntry2_s6;
extern int step_M_KeepInheritedEntry2_s6(Sink,Term);

/* FUNCTION CookBase-SortNameWithRepeat2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortNameWithRepeat2_s4 struct _Con_M_SortNameWithRepeat2_s4
struct _Con_M_SortNameWithRepeat2_s4 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortNameWithRepeat2_s4;
extern int step_M_SortNameWithRepeat2_s4(Sink,Term);

/* FUNCTION CookPG-PG-DeclareRegExpUnits-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_DeclareRegExpUnits_s2 struct _Con_M_PG_DeclareRegExpUnits_s2
struct _Con_M_PG_DeclareRegExpUnits_s2 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_DeclareRegExpUnits_s2;
extern int step_M_PG_DeclareRegExpUnits_s2(Sink,Term);

/* FUNCTION CookN-KeepInheritedEntry2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepInheritedEntry2_s7 struct _Con_M_KeepInheritedEntry2_s7
struct _Con_M_KeepInheritedEntry2_s7 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepInheritedEntry2_s7;
extern int step_M_KeepInheritedEntry2_s7(Sink,Term);

/* FUNCTION CookBase-SortNameWithRepeat2-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortNameWithRepeat2_s5 struct _Con_M_SortNameWithRepeat2_s5
struct _Con_M_SortNameWithRepeat2_s5 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortNameWithRepeat2_s5;
extern int step_M_SortNameWithRepeat2_s5(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Form-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Form_s3 struct _Con_M_DerivedSorts_Form_s3
struct _Con_M_DerivedSorts_Form_s3 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Form_s3;
extern int step_M_DerivedSorts_Form_s3(Sink,Term);

/* FUNCTION Prelude-TextFold1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_TextFold1_s2 struct _Con_M_TextFold1_s2
struct _Con_M_TextFold1_s2 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_TextFold1_s2;
extern int step_M_TextFold1_s2(Sink,Term);

/* FUNCTION CookBase-SortNameWithRepeat2-5 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortNameWithRepeat2_s6 struct _Con_M_SortNameWithRepeat2_s6
struct _Con_M_SortNameWithRepeat2_s6 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortNameWithRepeat2_s6;
extern int step_M_SortNameWithRepeat2_s6(Sink,Term);

/* FUNCTION Prelude-TextFold1-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_TextFold1_s1 struct _Con_M_TextFold1_s1
struct _Con_M_TextFold1_s1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_TextFold1_s1;
extern int step_M_TextFold1_s1(Sink,Term);

/* FUNCTION CookN-DerivedSorts-ParsedForm-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_ParsedForm_s2 struct _Con_M_DerivedSorts_ParsedForm_s2
struct _Con_M_DerivedSorts_ParsedForm_s2 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_ParsedForm_s2;
extern int step_M_DerivedSorts_ParsedForm_s2(Sink,Term);

/* FUNCTION CookN-DerivedSorts-ParsedForm-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_ParsedForm_s3 struct _Con_M_DerivedSorts_ParsedForm_s3
struct _Con_M_DerivedSorts_ParsedForm_s3 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_ParsedForm_s3;
extern int step_M_DerivedSorts_ParsedForm_s3(Sink,Term);

/* FUNCTION CookCRS-CRS-Declarations-TokenSynth-1$CRS-Declarations-TokenSynth$OK HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declarations_TokenSynth struct _Con_M_CRS_Declarations_TokenSynth
struct _Con_M_CRS_Declarations_TokenSynth {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declarations_TokenSynth;
extern int step_M_CRS_Declarations_TokenSynth(Sink,Term);

/* FUNCTION CookN-DerivedSorts-ParsedForm-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_ParsedForm_s4 struct _Con_M_DerivedSorts_ParsedForm_s4
struct _Con_M_DerivedSorts_ParsedForm_s4 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_ParsedForm_s4;
extern int step_M_DerivedSorts_ParsedForm_s4(Sink,Term);

/* FUNCTION CookCRS-CRS-Declarations-Derived-1$CRS-Declarations-Derived$DERIVED HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declarations_Derived struct _Con_M_CRS_Declarations_Derived
struct _Con_M_CRS_Declarations_Derived {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declarations_Derived;
extern int step_M_CRS_Declarations_Derived(Sink,Term);

/* FUNCTION CookN-DerivedSorts-ParsedForm-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_ParsedForm_s1 struct _Con_M_DerivedSorts_ParsedForm_s1
struct _Con_M_DerivedSorts_ParsedForm_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_ParsedForm_s1;
extern int step_M_DerivedSorts_ParsedForm_s1(Sink,Term);

/* FUNCTION CookN-_InsertSynthesizedRefs-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xInsertSynthesizedRefs struct _Con_M__xInsertSynthesizedRefs
struct _Con_M__xInsertSynthesizedRefs {struct _Construction construction; Term sub[3]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M__xInsertSynthesizedRefs;
extern int step_M__xInsertSynthesizedRefs(Sink,Term);

/* FUNCTION CookPG-PG-ProduceRepeat-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceRepeat_s3 struct _Con_M_PG_ProduceRepeat_s3
struct _Con_M_PG_ProduceRepeat_s3 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceRepeat_s3;
extern int step_M_PG_ProduceRepeat_s3(Sink,Term);

/* FUNCTION CookPG-PG-ProduceRepeat-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceRepeat_s4 struct _Con_M_PG_ProduceRepeat_s4
struct _Con_M_PG_ProduceRepeat_s4 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceRepeat_s4;
extern int step_M_PG_ProduceRepeat_s4(Sink,Term);

/* FUNCTION CookPG-PG-ProduceRepeat-5 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceRepeat_s5 struct _Con_M_PG_ProduceRepeat_s5
struct _Con_M_PG_ProduceRepeat_s5 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceRepeat_s5;
extern int step_M_PG_ProduceRepeat_s5(Sink,Term);

/* FUNCTION CookPG-PG-ProduceRepeat-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceRepeat_s1 struct _Con_M_PG_ProduceRepeat_s1
struct _Con_M_PG_ProduceRepeat_s1 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceRepeat_s1;
extern int step_M_PG_ProduceRepeat_s1(Sink,Term);

/* FUNCTION CookPG-PG-ProduceRepeat-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceRepeat_s2 struct _Con_M_PG_ProduceRepeat_s2
struct _Con_M_PG_ProduceRepeat_s2 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceRepeat_s2;
extern int step_M_PG_ProduceRepeat_s2(Sink,Term);

/* FUNCTION CookPG-PG-InlineRegExpChoice-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_InlineRegExpChoice_s2 struct _Con_M_PG_InlineRegExpChoice_s2
struct _Con_M_PG_InlineRegExpChoice_s2 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_InlineRegExpChoice_s2;
extern int step_M_PG_InlineRegExpChoice_s2(Sink,Term);

/* FUNCTION CookPG-PG-InlineRegExpChoice-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_InlineRegExpChoice_s1 struct _Con_M_PG_InlineRegExpChoice_s1
struct _Con_M_PG_InlineRegExpChoice_s1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_InlineRegExpChoice_s1;
extern int step_M_PG_InlineRegExpChoice_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-User2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_User2 struct _Con_M_CRS_User2
struct _Con_M_CRS_User2 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_User2;
extern int step_M_CRS_User2(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBody2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBody2 struct _Con_M_PG_ProduceBody2
struct _Con_M_PG_ProduceBody2 {struct _Construction construction; Term sub[8]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBody2;
extern int step_M_PG_ProduceBody2(Sink,Term);

/* FUNCTION CookN-KeepInheritedEntry-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepInheritedEntry_s1 struct _Con_M_KeepInheritedEntry_s1
struct _Con_M_KeepInheritedEntry_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepInheritedEntry_s1;
extern int step_M_KeepInheritedEntry_s1(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBody1- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBody1 struct _Con_M_PG_ProduceBody1
struct _Con_M_PG_ProduceBody1 {struct _Construction construction; Term sub[6]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBody1;
extern int step_M_PG_ProduceBody1(Sink,Term);

/* FUNCTION CookCRS-CRS-AttributeKeyValues-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AttributeKeyValues struct _Con_M_CRS_AttributeKeyValues
struct _Con_M_CRS_AttributeKeyValues {struct _Construction construction; Term sub[4]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AttributeKeyValues;
extern int step_M_CRS_AttributeKeyValues(Sink,Term);

/* FUNCTION CookN-_DefinePrec-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefinePrec_s1 struct _Con_M__xDefinePrec_s1
struct _Con_M__xDefinePrec_s1 {struct _Construction construction; Term sub[2]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M__xDefinePrec_s1;
extern int step_M__xDefinePrec_s1(Sink,Term);

/* FUNCTION CookN-_FormLess-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xFormLess_s10 struct _Con_M__xFormLess_s10
struct _Con_M__xFormLess_s10 {struct _Construction construction; Term sub[9]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xFormLess_s10;
extern int step_M__xFormLess_s10(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-Rule-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_Rule_s10 struct _Con_M_CRS_Rules_Rule_s10
struct _Con_M_CRS_Rules_Rule_s10 {struct _Construction construction; Term sub[12]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_Rule_s10;
extern int step_M_CRS_Rules_Rule_s10(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-Rule-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_Rule_s11 struct _Con_M_CRS_Rules_Rule_s11
struct _Con_M_CRS_Rules_Rule_s11 {struct _Construction construction; Term sub[10]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_Rule_s11;
extern int step_M_CRS_Rules_Rule_s11(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-Rule-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_Rule_s12 struct _Con_M_CRS_Rules_Rule_s12
struct _Con_M_CRS_Rules_Rule_s12 {struct _Construction construction; Term sub[10]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_Rule_s12;
extern int step_M_CRS_Rules_Rule_s12(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-Rule-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_Rule_s13 struct _Con_M_CRS_Rules_Rule_s13
struct _Con_M_CRS_Rules_Rule_s13 {struct _Construction construction; Term sub[12]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_Rule_s13;
extern int step_M_CRS_Rules_Rule_s13(Sink,Term);

/* FUNCTION CookPG-SameSort2-3$SameSort2$4$RAW-Sort HEADER DECLARATIONS. */
#define STRUCT_Con_M_SameSort2_s4 struct _Con_M_SameSort2_s4
struct _Con_M_SameSort2_s4 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SameSort2_s4;
extern int step_M_SameSort2_s4(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-Derived-1$CRS-Rules-Derived$DERIVED HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_Derived struct _Con_M_CRS_Rules_Derived
struct _Con_M_CRS_Rules_Derived {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_Derived;
extern int step_M_CRS_Rules_Derived(Sink,Term);

/* FUNCTION CookPG-SameSort2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_SameSort2_s5 struct _Con_M_SameSort2_s5
struct _Con_M_SameSort2_s5 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SameSort2_s5;
extern int step_M_SameSort2_s5(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-Define- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_Define struct _Con_M_CRS_Rules_Define
struct _Con_M_CRS_Rules_Define {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_Define;
extern int step_M_CRS_Rules_Define(Sink,Term);

/* FUNCTION CookN-_DefinePrec-5 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefinePrec_s6 struct _Con_M__xDefinePrec_s6
struct _Con_M__xDefinePrec_s6 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xDefinePrec_s6;
extern int step_M__xDefinePrec_s6(Sink,Term);

/* FUNCTION CookPG-SameSort2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SameSort2_s2 struct _Con_M_SameSort2_s2
struct _Con_M_SameSort2_s2 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SameSort2_s2;
extern int step_M_SameSort2_s2(Sink,Term);

/* FUNCTION CookN-_FormLess-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xFormLess_s11 struct _Con_M__xFormLess_s11
struct _Con_M__xFormLess_s11 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xFormLess_s11;
extern int step_M__xFormLess_s11(Sink,Term);

/* FUNCTION CookN-_DefinePrec-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefinePrec_s4 struct _Con_M__xDefinePrec_s4
struct _Con_M__xDefinePrec_s4 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xDefinePrec_s4;
extern int step_M__xDefinePrec_s4(Sink,Term);

/* FUNCTION CookN-_DefinePrec-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefinePrec_s5 struct _Con_M__xDefinePrec_s5
struct _Con_M__xDefinePrec_s5 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xDefinePrec_s5;
extern int step_M__xDefinePrec_s5(Sink,Term);

/* FUNCTION CookPG-SameSort2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_SameSort2_s1 struct _Con_M_SameSort2_s1
struct _Con_M_SameSort2_s1 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SameSort2_s1;
extern int step_M_SameSort2_s1(Sink,Term);

/* FUNCTION CookN-_DefinePrec- HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefinePrec_s2 struct _Con_M__xDefinePrec_s2
struct _Con_M__xDefinePrec_s2 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xDefinePrec_s2;
extern int step_M__xDefinePrec_s2(Sink,Term);

/* FUNCTION CookN-N-SortAbstractionDefines- HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_SortAbstractionDefines struct _Con_M_N_SortAbstractionDefines
struct _Con_M_N_SortAbstractionDefines {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_SortAbstractionDefines;
extern int step_M_N_SortAbstractionDefines(Sink,Term);

/* FUNCTION CookN-_DefinePrec-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefinePrec_s3 struct _Con_M__xDefinePrec_s3
struct _Con_M__xDefinePrec_s3 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xDefinePrec_s3;
extern int step_M__xDefinePrec_s3(Sink,Term);

/* FUNCTION Prelude-Tl- HEADER DECLARATIONS. */
#define STRUCT_Con_M_Tl struct _Con_M_Tl
struct _Con_M_Tl {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_Tl;
extern int step_M_Tl(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-Inherited-1$CRS-Rules-Inherited$OK HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_Inherited struct _Con_M_CRS_Rules_Inherited
struct _Con_M_CRS_Rules_Inherited {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_Inherited;
extern int step_M_CRS_Rules_Inherited(Sink,Term);

/* FUNCTION CookN-_DefineWrapper- HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefineWrapper struct _Con_M__xDefineWrapper
struct _Con_M__xDefineWrapper {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xDefineWrapper;
extern int step_M__xDefineWrapper(Sink,Term);

/* FUNCTION Prelude-TextFold-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_TextFold_s2 struct _Con_M_TextFold_s2
struct _Con_M_TextFold_s2 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_TextFold_s2;
extern int step_M_TextFold_s2(Sink,Term);

/* FUNCTION Prelude-AddName-1$AddName$NAME_SET HEADER DECLARATIONS. */
#define STRUCT_Con_M_AddName struct _Con_M_AddName
struct _Con_M_AddName {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_AddName;
extern int step_M_AddName(Sink,Term);

/* FUNCTION CookCRS-CRS-FormScopeMetaApplication2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_FormScopeMetaApplication2 struct _Con_M_CRS_FormScopeMetaApplication2
struct _Con_M_CRS_FormScopeMetaApplication2 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_FormScopeMetaApplication2;
extern int step_M_CRS_FormScopeMetaApplication2(Sink,Term);

/* FUNCTION Prelude-TextFold-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_TextFold_s1 struct _Con_M_TextFold_s1
struct _Con_M_TextFold_s1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_TextFold_s1;
extern int step_M_TextFold_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-AttributeValues- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AttributeValues struct _Con_M_CRS_AttributeValues
struct _Con_M_CRS_AttributeValues {struct _Construction construction; Term sub[5]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AttributeValues;
extern int step_M_CRS_AttributeValues(Sink,Term);

/* FUNCTION Prelude-UnString-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_UnString struct _Con_M_UnString
struct _Con_M_UnString {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_UnString;
extern int step_M_UnString(Sink,Term);

/* FUNCTION Prelude-NameSetList1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_NameSetList1_s1 struct _Con_M_NameSetList1_s1
struct _Con_M_NameSetList1_s1 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NameSetList1_s1;
extern int step_M_NameSetList1_s1(Sink,Term);

/* FUNCTION Prelude-IfLifted- HEADER DECLARATIONS. */
#define STRUCT_Con_M_IfLifted struct _Con_M_IfLifted
struct _Con_M_IfLifted {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_IfLifted;
extern int step_M_IfLifted(Sink,Term);

/* FUNCTION CookCRS-CRS-MetaDeclarations-Derived2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_MetaDeclarations_Derived2 struct _Con_M_CRS_MetaDeclarations_Derived2
struct _Con_M_CRS_MetaDeclarations_Derived2 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_MetaDeclarations_Derived2;
extern int step_M_CRS_MetaDeclarations_Derived2(Sink,Term);

/* FUNCTION CookCRS-CRS-Term-Attributes- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Term_Attributes struct _Con_M_CRS_Term_Attributes
struct _Con_M_CRS_Term_Attributes {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Term_Attributes;
extern int step_M_CRS_Term_Attributes(Sink,Term);

/* FUNCTION CookN-DLE-Rule-Abstraction HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefineLessEqual_s11 struct _Con_M__xDefineLessEqual_s11
struct _Con_M__xDefineLessEqual_s11 {struct _Construction construction; Term sub[6]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M__xDefineLessEqual_s11;
extern int step_M__xDefineLessEqual_s11(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Attributes- HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Attributes struct _Con_M_DerivedSorts_Attributes
struct _Con_M_DerivedSorts_Attributes {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Attributes;
extern int step_M_DerivedSorts_Attributes(Sink,Term);

/* FUNCTION CookN-DLE-Rule- HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefineLessEqual_s10 struct _Con_M__xDefineLessEqual_s10
struct _Con_M__xDefineLessEqual_s10 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xDefineLessEqual_s10;
extern int step_M__xDefineLessEqual_s10(Sink,Term);

/* FUNCTION CookN-DLE-Rule-Rule HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefineLessEqual_s13 struct _Con_M__xDefineLessEqual_s13
struct _Con_M__xDefineLessEqual_s13 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xDefineLessEqual_s13;
extern int step_M__xDefineLessEqual_s13(Sink,Term);

/* FUNCTION CookN-DLE-Rule-Form HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefineLessEqual_s12 struct _Con_M__xDefineLessEqual_s12
struct _Con_M__xDefineLessEqual_s12 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xDefineLessEqual_s12;
extern int step_M__xDefineLessEqual_s12(Sink,Term);

/* FUNCTION CookPG-ProductionNames- HEADER DECLARATIONS. */
#define STRUCT_Con_M_ProductionNames struct _Con_M_ProductionNames
struct _Con_M_ProductionNames {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ProductionNames;
extern int step_M_ProductionNames(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-Synthesized-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_Synthesized_s1 struct _Con_M_CRS_Rules_Synthesized_s1
struct _Con_M_CRS_Rules_Synthesized_s1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_Synthesized_s1;
extern int step_M_CRS_Rules_Synthesized_s1(Sink,Term);

/* FUNCTION CookCRS-SortSynthesizes2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortSynthesizes2 struct _Con_M_SortSynthesizes2
struct _Con_M_SortSynthesizes2 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortSynthesizes2;
extern int step_M_SortSynthesizes2(Sink,Term);

/* FUNCTION CookN-ProductionNameDerived-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ProductionNameDerived_s1 struct _Con_M_ProductionNameDerived_s1
struct _Con_M_ProductionNameDerived_s1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ProductionNameDerived_s1;
extern int step_M_ProductionNameDerived_s1(Sink,Term);

/* FUNCTION Prelude-ThenAsText-1$ThenAsText$OK HEADER DECLARATIONS. */
#define STRUCT_Con_M_ThenAsText struct _Con_M_ThenAsText
struct _Con_M_ThenAsText {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ThenAsText;
extern int step_M_ThenAsText(Sink,Term);

/* FUNCTION Prelude-Drop- HEADER DECLARATIONS. */
#define STRUCT_Con_M_Drop struct _Con_M_Drop
struct _Con_M_Drop {struct _Construction construction; Term sub[3]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M_Drop;
extern int step_M_Drop(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBodyWord2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBodyWord2 struct _Con_M_PG_ProduceBodyWord2
struct _Con_M_PG_ProduceBodyWord2 {struct _Construction construction; Term sub[8]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBodyWord2;
extern int step_M_PG_ProduceBodyWord2(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-Rule-1$CRS-Rules-Rule$RAW-Rule HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_Rule struct _Con_M_CRS_Rules_Rule
struct _Con_M_CRS_Rules_Rule {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_Rule;
extern int step_M_CRS_Rules_Rule(Sink,Term);

/* FUNCTION CookPG-PG-AttributeProduction-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_AttributeProduction struct _Con_M_PG_AttributeProduction
struct _Con_M_PG_AttributeProduction {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_AttributeProduction;
extern int step_M_PG_AttributeProduction(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBodyWord1- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBodyWord1 struct _Con_M_PG_ProduceBodyWord1
struct _Con_M_PG_ProduceBodyWord1 {struct _Construction construction; Term sub[9]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBodyWord1;
extern int step_M_PG_ProduceBodyWord1(Sink,Term);

/* FUNCTION CookPG-ProductionConstruction-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ProductionConstruction_s4 struct _Con_M_ProductionConstruction_s4
struct _Con_M_ProductionConstruction_s4 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ProductionConstruction_s4;
extern int step_M_ProductionConstruction_s4(Sink,Term);

/* FUNCTION CookN-N-InitOtherMaps1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_InitOtherMaps1 struct _Con_M_N_InitOtherMaps1
struct _Con_M_N_InitOtherMaps1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_InitOtherMaps1;
extern int step_M_N_InitOtherMaps1(Sink,Term);

/* FUNCTION CookN-Resolve HEADER DECLARATIONS. */
#define STRUCT_Con_M_N__resolve struct _Con_M_N__resolve
struct _Con_M_N__resolve {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N__resolve;
extern int step_M_N__resolve(Sink,Term);

/* FUNCTION CookPG-ProductionConstruction-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ProductionConstruction_s5 struct _Con_M_ProductionConstruction_s5
struct _Con_M_ProductionConstruction_s5 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ProductionConstruction_s5;
extern int step_M_ProductionConstruction_s5(Sink,Term);

/* FUNCTION CookPG-ProductionConstruction-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ProductionConstruction_s2 struct _Con_M_ProductionConstruction_s2
struct _Con_M_ProductionConstruction_s2 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ProductionConstruction_s2;
extern int step_M_ProductionConstruction_s2(Sink,Term);

/* FUNCTION CookPG-ProductionConstruction-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ProductionConstruction_s3 struct _Con_M_ProductionConstruction_s3
struct _Con_M_ProductionConstruction_s3 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ProductionConstruction_s3;
extern int step_M_ProductionConstruction_s3(Sink,Term);

/* FUNCTION CookN-N-InitOtherMaps2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_InitOtherMaps2 struct _Con_M_N_InitOtherMaps2
struct _Con_M_N_InitOtherMaps2 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_InitOtherMaps2;
extern int step_M_N_InitOtherMaps2(Sink,Term);

/* FUNCTION CookPG-ProductionConstruction-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ProductionConstruction_s6 struct _Con_M_ProductionConstruction_s6
struct _Con_M_ProductionConstruction_s6 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ProductionConstruction_s6;
extern int step_M_ProductionConstruction_s6(Sink,Term);

/* FUNCTION CookN-N-Finish1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_Finish1_s1 struct _Con_M_N_Finish1_s1
struct _Con_M_N_Finish1_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_Finish1_s1;
extern int step_M_N_Finish1_s1(Sink,Term);

/* FUNCTION CookN-N-Finish1-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_Finish1_s2 struct _Con_M_N_Finish1_s2
struct _Con_M_N_Finish1_s2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_Finish1_s2;
extern int step_M_N_Finish1_s2(Sink,Term);

/* FUNCTION CookPG-ProductionConstruction- HEADER DECLARATIONS. */
#define STRUCT_Con_M_ProductionConstruction_s1 struct _Con_M_ProductionConstruction_s1
struct _Con_M_ProductionConstruction_s1 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ProductionConstruction_s1;
extern int step_M_ProductionConstruction_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-NameOptions-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_NameOptions_s2 struct _Con_M_CRS_NameOptions_s2
struct _Con_M_CRS_NameOptions_s2 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_NameOptions_s2;
extern int step_M_CRS_NameOptions_s2(Sink,Term);

/* FUNCTION CookBase-SortName2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortName2 struct _Con_M_SortName2
struct _Con_M_SortName2 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortName2;
extern int step_M_SortName2(Sink,Term);

/* FUNCTION CookBase-SortName1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortName1 struct _Con_M_SortName1
struct _Con_M_SortName1 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortName1;
extern int step_M_SortName1(Sink,Term);

/* FUNCTION CookN-ConstructorScopeSorts3-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ConstructorScopeSorts3_s1 struct _Con_M_ConstructorScopeSorts3_s1
struct _Con_M_ConstructorScopeSorts3_s1 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ConstructorScopeSorts3_s1;
extern int step_M_ConstructorScopeSorts3_s1(Sink,Term);

/* FUNCTION CookN-ConstructorScopeSorts3-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ConstructorScopeSorts3_s2 struct _Con_M_ConstructorScopeSorts3_s2
struct _Con_M_ConstructorScopeSorts3_s2 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ConstructorScopeSorts3_s2;
extern int step_M_ConstructorScopeSorts3_s2(Sink,Term);

/* FUNCTION CookN-ConstructorScopeSorts3-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ConstructorScopeSorts3_s3 struct _Con_M_ConstructorScopeSorts3_s3
struct _Con_M_ConstructorScopeSorts3_s3 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ConstructorScopeSorts3_s3;
extern int step_M_ConstructorScopeSorts3_s3(Sink,Term);

/* FUNCTION CookCRS-CRS-NameOptions-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_NameOptions_s1 struct _Con_M_CRS_NameOptions_s1
struct _Con_M_CRS_NameOptions_s1 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_NameOptions_s1;
extern int step_M_CRS_NameOptions_s1(Sink,Term);

/* FUNCTION CookN-N-CaptureOtherMaps-1$N-CaptureOtherMaps$2$NAMES HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_CaptureOtherMaps_s2 struct _Con_M_N_CaptureOtherMaps_s2
struct _Con_M_N_CaptureOtherMaps_s2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_CaptureOtherMaps_s2;
extern int step_M_N_CaptureOtherMaps_s2(Sink,Term);

/* FUNCTION CookN-N-CaptureOtherMaps-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_CaptureOtherMaps_s3 struct _Con_M_N_CaptureOtherMaps_s3
struct _Con_M_N_CaptureOtherMaps_s3 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_CaptureOtherMaps_s3;
extern int step_M_N_CaptureOtherMaps_s3(Sink,Term);

/* FUNCTION CookCRS-NeedSynthesizedName-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_NeedSynthesizedName struct _Con_M_NeedSynthesizedName
struct _Con_M_NeedSynthesizedName {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NeedSynthesizedName;
extern int step_M_NeedSynthesizedName(Sink,Term);

/* FUNCTION CookCRS-CRS-RewriteRule-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_RewriteRule struct _Con_M_CRS_RewriteRule
struct _Con_M_CRS_RewriteRule {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_RewriteRule;
extern int step_M_CRS_RewriteRule(Sink,Term);

/* FUNCTION CookN-KeepSynthesizedMapEntry2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepSynthesizedMapEntry2_s10 struct _Con_M_KeepSynthesizedMapEntry2_s10
struct _Con_M_KeepSynthesizedMapEntry2_s10 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepSynthesizedMapEntry2_s10;
extern int step_M_KeepSynthesizedMapEntry2_s10(Sink,Term);

/* FUNCTION CookN-KeepSynthesizedMapEntry2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepSynthesizedMapEntry2_s11 struct _Con_M_KeepSynthesizedMapEntry2_s11
struct _Con_M_KeepSynthesizedMapEntry2_s11 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepSynthesizedMapEntry2_s11;
extern int step_M_KeepSynthesizedMapEntry2_s11(Sink,Term);

/* FUNCTION CookN-N-InitOtherMaps-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_InitOtherMaps_s3 struct _Con_M_N_InitOtherMaps_s3
struct _Con_M_N_InitOtherMaps_s3 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_InitOtherMaps_s3;
extern int step_M_N_InitOtherMaps_s3(Sink,Term);

/* FUNCTION CookN-N-InitOtherMaps-1$N-InitOtherMaps$2$NAMES HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_InitOtherMaps_s2 struct _Con_M_N_InitOtherMaps_s2
struct _Con_M_N_InitOtherMaps_s2 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_InitOtherMaps_s2;
extern int step_M_N_InitOtherMaps_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-MetaDeclarations-Derived-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_MetaDeclarations_Derived_s1 struct _Con_M_CRS_MetaDeclarations_Derived_s1
struct _Con_M_CRS_MetaDeclarations_Derived_s1 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_MetaDeclarations_Derived_s1;
extern int step_M_CRS_MetaDeclarations_Derived_s1(Sink,Term);

/* FUNCTION Prelude-JoinTextMaps2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_JoinTextMaps2 struct _Con_M_JoinTextMaps2
struct _Con_M_JoinTextMaps2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_JoinTextMaps2;
extern int step_M_JoinTextMaps2(Sink,Term);

/* FUNCTION CookPG-PG-1$PG$1$RAW-module HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_s1 struct _Con_M_PG_s1
struct _Con_M_PG_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_s1;
extern int step_M_PG_s1(Sink,Term);

/* FUNCTION CookPG-PG-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_s2 struct _Con_M_PG_s2
struct _Con_M_PG_s2 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_s2;
extern int step_M_PG_s2(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Parsed- HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Parsed struct _Con_M_DerivedSorts_Parsed
struct _Con_M_DerivedSorts_Parsed {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Parsed;
extern int step_M_DerivedSorts_Parsed(Sink,Term);

/* FUNCTION Prelude-RemoveFirstName-1$RemoveFirstName$NAME_SET HEADER DECLARATIONS. */
#define STRUCT_Con_M_RemoveFirstName struct _Con_M_RemoveFirstName
struct _Con_M_RemoveFirstName {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RemoveFirstName;
extern int step_M_RemoveFirstName(Sink,Term);

/* FUNCTION CookPG-PG-InlineRegExp2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_InlineRegExp2 struct _Con_M_PG_InlineRegExp2
struct _Con_M_PG_InlineRegExp2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_InlineRegExp2;
extern int step_M_PG_InlineRegExp2(Sink,Term);

/* FUNCTION CookCRS-CRS-Module-1$CRS-Module$3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Module_s3 struct _Con_M_CRS_Module_s3
struct _Con_M_CRS_Module_s3 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Module_s3;
extern int step_M_CRS_Module_s3(Sink,Term);

/* FUNCTION CookCRS-CRS-then-Rules-DataSynth-Got-1$CRS-then-Rules-DataSynth-Got$OK HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS__then_Rules_DataSynth_Got struct _Con_M_CRS__then_Rules_DataSynth_Got
struct _Con_M_CRS__then_Rules_DataSynth_Got {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS__then_Rules_DataSynth_Got;
extern int step_M_CRS__then_Rules_DataSynth_Got(Sink,Term);

/* FUNCTION CookCRS-CRS-Module-1$CRS-Module$6 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Module_s6 struct _Con_M_CRS_Module_s6
struct _Con_M_CRS_Module_s6 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Module_s6;
extern int step_M_CRS_Module_s6(Sink,Term);

/* FUNCTION CookCRS-CRS-Module-1$CRS-Module$5$NAMES HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Module_s5 struct _Con_M_CRS_Module_s5
struct _Con_M_CRS_Module_s5 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Module_s5;
extern int step_M_CRS_Module_s5(Sink,Term);

/* FUNCTION CookCRS-CRS-AttributeGroups2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AttributeGroups2 struct _Con_M_CRS_AttributeGroups2
struct _Con_M_CRS_AttributeGroups2 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AttributeGroups2;
extern int step_M_CRS_AttributeGroups2(Sink,Term);

/* FUNCTION CookCRS-CRS-Module-1$CRS-Module$2$NAMES HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Module_s2 struct _Con_M_CRS_Module_s2
struct _Con_M_CRS_Module_s2 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Module_s2;
extern int step_M_CRS_Module_s2(Sink,Term);

/* FUNCTION Prelude-Or- HEADER DECLARATIONS. */
#define STRUCT_Con_M_Or struct _Con_M_Or
struct _Con_M_Or {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_Or;
extern int step_M_Or(Sink,Term);

/* FUNCTION CookCRS-CRS-Rule-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rule struct _Con_M_CRS_Rule
struct _Con_M_CRS_Rule {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rule;
extern int step_M_CRS_Rule(Sink,Term);

/* FUNCTION CookN-_InsertDefine3-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xInsertDefine3_s1 struct _Con_M__xInsertDefine3_s1
struct _Con_M__xInsertDefine3_s1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xInsertDefine3_s1;
extern int step_M__xInsertDefine3_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-Module-1$CRS-Module$8$NAMES HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Module_s8 struct _Con_M_CRS_Module_s8
struct _Con_M_CRS_Module_s8 {struct _Construction construction; Term sub[9]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Module_s8;
extern int step_M_CRS_Module_s8(Sink,Term);

/* FUNCTION CookPG-PG-ProduceRepeat- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceRepeat struct _Con_M_PG_ProduceRepeat
struct _Con_M_PG_ProduceRepeat {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceRepeat;
extern int step_M_PG_ProduceRepeat(Sink,Term);

/* FUNCTION CookN-_InsertDefine3-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xInsertDefine3_s2 struct _Con_M__xInsertDefine3_s2
struct _Con_M__xInsertDefine3_s2 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xInsertDefine3_s2;
extern int step_M__xInsertDefine3_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-Module-1$CRS-Module$9 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Module_s9 struct _Con_M_CRS_Module_s9
struct _Con_M_CRS_Module_s9 {struct _Construction construction; Term sub[9]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Module_s9;
extern int step_M_CRS_Module_s9(Sink,Term);

/* FUNCTION CookCRS-CRS-Parsed-In2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Parsed_In2 struct _Con_M_CRS_Parsed_In2
struct _Con_M_CRS_Parsed_In2 {struct _Construction construction; Term sub[5]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Parsed_In2;
extern int step_M_CRS_Parsed_In2(Sink,Term);

/* FUNCTION CookN-N-InitOtherMaps2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_InitOtherMaps2_s1 struct _Con_M_N_InitOtherMaps2_s1
struct _Con_M_N_InitOtherMaps2_s1 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_InitOtherMaps2_s1;
extern int step_M_N_InitOtherMaps2_s1(Sink,Term);

/* FUNCTION Prelude-NameSetList1-1$NameSetList1$NAME_SET HEADER DECLARATIONS. */
#define STRUCT_Con_M_NameSetList1 struct _Con_M_NameSetList1
struct _Con_M_NameSetList1 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NameSetList1;
extern int step_M_NameSetList1(Sink,Term);

/* FUNCTION CookN-N-InitOtherMaps2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_InitOtherMaps2_s2 struct _Con_M_N_InitOtherMaps2_s2
struct _Con_M_N_InitOtherMaps2_s2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_InitOtherMaps2_s2;
extern int step_M_N_InitOtherMaps2_s2(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBodyTerm1- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBodyTerm1 struct _Con_M_PG_ProduceBodyTerm1
struct _Con_M_PG_ProduceBodyTerm1 {struct _Construction construction; Term sub[12]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBodyTerm1;
extern int step_M_PG_ProduceBodyTerm1(Sink,Term);

/* FUNCTION CookCRS-CRS-Declaration-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declaration struct _Con_M_CRS_Declaration
struct _Con_M_CRS_Declaration {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declaration;
extern int step_M_CRS_Declaration(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBodyTerm2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBodyTerm2 struct _Con_M_PG_ProduceBodyTerm2
struct _Con_M_PG_ProduceBodyTerm2 {struct _Construction construction; Term sub[11]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBodyTerm2;
extern int step_M_PG_ProduceBodyTerm2(Sink,Term);

/* FUNCTION Prelude-And-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_And_s1 struct _Con_M_And_s1
struct _Con_M_And_s1 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_And_s1;
extern int step_M_And_s1(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBodyTerm3- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBodyTerm3 struct _Con_M_PG_ProduceBodyTerm3
struct _Con_M_PG_ProduceBodyTerm3 {struct _Construction construction; Term sub[10]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBodyTerm3;
extern int step_M_PG_ProduceBodyTerm3(Sink,Term);

/* FUNCTION Prelude-And-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_And_s2 struct _Con_M_And_s2
struct _Con_M_And_s2 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_And_s2;
extern int step_M_And_s2(Sink,Term);

/* FUNCTION Prelude-WrappedTextFold-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_WrappedTextFold_s2 struct _Con_M_WrappedTextFold_s2
struct _Con_M_WrappedTextFold_s2 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_WrappedTextFold_s2;
extern int step_M_WrappedTextFold_s2(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBodyTerm4-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBodyTerm4 struct _Con_M_PG_ProduceBodyTerm4
struct _Con_M_PG_ProduceBodyTerm4 {struct _Construction construction; Term sub[12]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBodyTerm4;
extern int step_M_PG_ProduceBodyTerm4(Sink,Term);

/* FUNCTION Prelude-WrappedTextFold-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_WrappedTextFold_s1 struct _Con_M_WrappedTextFold_s1
struct _Con_M_WrappedTextFold_s1 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_WrappedTextFold_s1;
extern int step_M_WrappedTextFold_s1(Sink,Term);

/* FUNCTION Prelude-TextPartToString-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_TextPartToString_s2 struct _Con_M_TextPartToString_s2
struct _Con_M_TextPartToString_s2 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_TextPartToString_s2;
extern int step_M_TextPartToString_s2(Sink,Term);

/* FUNCTION Prelude-TextPartToString-6 HEADER DECLARATIONS. */
#define STRUCT_Con_M_TextPartToString_s3 struct _Con_M_TextPartToString_s3
struct _Con_M_TextPartToString_s3 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_TextPartToString_s3;
extern int step_M_TextPartToString_s3(Sink,Term);

/* FUNCTION CookPG-ProductionNames-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ProductionNames_s1 struct _Con_M_ProductionNames_s1
struct _Con_M_ProductionNames_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ProductionNames_s1;
extern int step_M_ProductionNames_s1(Sink,Term);

/* FUNCTION Prelude-TextPartToString-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_TextPartToString_s1 struct _Con_M_TextPartToString_s1
struct _Con_M_TextPartToString_s1 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_TextPartToString_s1;
extern int step_M_TextPartToString_s1(Sink,Term);

/* FUNCTION CookPG-ProductionNames-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ProductionNames_s2 struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_ProductionNames_s2;
extern int step_M_ProductionNames_s2(Sink,Term);

/* FUNCTION Prelude-TextPartToString-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_TextPartToString_s6 struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_TextPartToString_s6;
extern int step_M_TextPartToString_s6(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-DefineSynth-1$CRS-Rules-DefineSynth$OK HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_DefineSynth struct _Con_M_CRS_Rules_DefineSynth
struct _Con_M_CRS_Rules_DefineSynth {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_DefineSynth;
extern int step_M_CRS_Rules_DefineSynth(Sink,Term);

/* FUNCTION Prelude-TextPartToString-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_TextPartToString_s4 struct _Con_M_TextPartToString_s4
struct _Con_M_TextPartToString_s4 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_TextPartToString_s4;
extern int step_M_TextPartToString_s4(Sink,Term);

/* FUNCTION CookPG-PG-InlineRegExpUnits- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_InlineRegExpUnits struct _Con_M_PG_InlineRegExpUnits
struct _Con_M_PG_InlineRegExpUnits {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_InlineRegExpUnits;
extern int step_M_PG_InlineRegExpUnits(Sink,Term);

/* FUNCTION Prelude-JoinTextMaps-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_JoinTextMaps_s1 struct _Con_M_JoinTextMaps_s1
struct _Con_M_JoinTextMaps_s1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_JoinTextMaps_s1;
extern int step_M_JoinTextMaps_s1(Sink,Term);

/* FUNCTION Prelude-TextPartToString-5 HEADER DECLARATIONS. */
#define STRUCT_Con_M_TextPartToString_s5 struct _Con_M_TextPartToString_s5
struct _Con_M_TextPartToString_s5 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_TextPartToString_s5;
extern int step_M_TextPartToString_s5(Sink,Term);

/* FUNCTION CookN-DLE- HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefineLessEqual struct _Con_M__xDefineLessEqual
struct _Con_M__xDefineLessEqual {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xDefineLessEqual;
extern int step_M__xDefineLessEqual(Sink,Term);

/* FUNCTION Prelude-TextFold1- HEADER DECLARATIONS. */
#define STRUCT_Con_M_TextFold1 struct _Con_M_TextFold1
struct _Con_M_TextFold1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_TextFold1;
extern int step_M_TextFold1(Sink,Term);

/* FUNCTION CookBase-RuleTopSort-1$RuleTopSort$RAW-Rule HEADER DECLARATIONS. */
#define STRUCT_Con_M_RuleTopSort struct _Con_M_RuleTopSort
struct _Con_M_RuleTopSort {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RuleTopSort;
extern int step_M_RuleTopSort(Sink,Term);

/* FUNCTION CookN-AttributeValueSortName2-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_AttributeValueSortName2_s8 struct _Con_M_AttributeValueSortName2_s8
struct _Con_M_AttributeValueSortName2_s8 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_AttributeValueSortName2_s8;
extern int step_M_AttributeValueSortName2_s8(Sink,Term);

/* FUNCTION CookN-AttributeValueSortName2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_AttributeValueSortName2_s5 struct _Con_M_AttributeValueSortName2_s5
struct _Con_M_AttributeValueSortName2_s5 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_AttributeValueSortName2_s5;
extern int step_M_AttributeValueSortName2_s5(Sink,Term);

/* FUNCTION CookN-AttributeValueSortName2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_AttributeValueSortName2_s4 struct _Con_M_AttributeValueSortName2_s4
struct _Con_M_AttributeValueSortName2_s4 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_AttributeValueSortName2_s4;
extern int step_M_AttributeValueSortName2_s4(Sink,Term);

/* FUNCTION CookN-AttributeValueSortName2-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_AttributeValueSortName2_s7 struct _Con_M_AttributeValueSortName2_s7
struct _Con_M_AttributeValueSortName2_s7 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_AttributeValueSortName2_s7;
extern int step_M_AttributeValueSortName2_s7(Sink,Term);

/* FUNCTION CookN-AttributeValueSortName2-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_AttributeValueSortName2_s6 struct _Con_M_AttributeValueSortName2_s6
struct _Con_M_AttributeValueSortName2_s6 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_AttributeValueSortName2_s6;
extern int step_M_AttributeValueSortName2_s6(Sink,Term);

/* FUNCTION CookPG-PG-isLeftRecursive1-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG__isLeftRecursive1_s10 struct _Con_M_PG__isLeftRecursive1_s10
struct _Con_M_PG__isLeftRecursive1_s10 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG__isLeftRecursive1_s10;
extern int step_M_PG__isLeftRecursive1_s10(Sink,Term);

/* FUNCTION CookCRS-CRS-Term- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Term struct _Con_M_CRS_Term
struct _Con_M_CRS_Term {struct _Construction construction; Term sub[8]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Term;
extern int step_M_CRS_Term(Sink,Term);

/* FUNCTION CookN-AttributeValueSortName2-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_AttributeValueSortName2_s1 struct _Con_M_AttributeValueSortName2_s1
struct _Con_M_AttributeValueSortName2_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_AttributeValueSortName2_s1;
extern int step_M_AttributeValueSortName2_s1(Sink,Term);

/* FUNCTION CookN-AttributeValueSortName2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_AttributeValueSortName2_s3 struct _Con_M_AttributeValueSortName2_s3
struct _Con_M_AttributeValueSortName2_s3 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_AttributeValueSortName2_s3;
extern int step_M_AttributeValueSortName2_s3(Sink,Term);

/* FUNCTION CookPG-PG-isLeftRecursive1-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG__isLeftRecursive1_s11 struct _Con_M_PG__isLeftRecursive1_s11
struct _Con_M_PG__isLeftRecursive1_s11 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG__isLeftRecursive1_s11;
extern int step_M_PG__isLeftRecursive1_s11(Sink,Term);

/* FUNCTION Prelude-RemoveName-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_RemoveName_s1 struct _Con_M_RemoveName_s1
struct _Con_M_RemoveName_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RemoveName_s1;
extern int step_M_RemoveName_s1(Sink,Term);

/* FUNCTION CookBase-ProductionNameWithPrecRepeat-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ProductionNameWithPrecRepeat_s2 struct _Con_M_ProductionNameWithPrecRepeat_s2
struct _Con_M_ProductionNameWithPrecRepeat_s2 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ProductionNameWithPrecRepeat_s2;
extern int step_M_ProductionNameWithPrecRepeat_s2(Sink,Term);

/* FUNCTION CookBase-ProductionNameWithPrecRepeat- HEADER DECLARATIONS. */
#define STRUCT_Con_M_ProductionNameWithPrecRepeat_s1 struct _Con_M_ProductionNameWithPrecRepeat_s1
struct _Con_M_ProductionNameWithPrecRepeat_s1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ProductionNameWithPrecRepeat_s1;
extern int step_M_ProductionNameWithPrecRepeat_s1(Sink,Term);

/* FUNCTION CookBase-ProductionNameWithPrecRepeat-5 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ProductionNameWithPrecRepeat_s6 struct _Con_M_ProductionNameWithPrecRepeat_s6
struct _Con_M_ProductionNameWithPrecRepeat_s6 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ProductionNameWithPrecRepeat_s6;
extern int step_M_ProductionNameWithPrecRepeat_s6(Sink,Term);

/* FUNCTION CookBase-ProductionNameWithPrecRepeat-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ProductionNameWithPrecRepeat_s5 struct _Con_M_ProductionNameWithPrecRepeat_s5
struct _Con_M_ProductionNameWithPrecRepeat_s5 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ProductionNameWithPrecRepeat_s5;
extern int step_M_ProductionNameWithPrecRepeat_s5(Sink,Term);

/* FUNCTION CookBase-ProductionNameWithPrecRepeat-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ProductionNameWithPrecRepeat_s4 struct _Con_M_ProductionNameWithPrecRepeat_s4
struct _Con_M_ProductionNameWithPrecRepeat_s4 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ProductionNameWithPrecRepeat_s4;
extern int step_M_ProductionNameWithPrecRepeat_s4(Sink,Term);

/* FUNCTION CookBase-ProductionNameWithPrecRepeat-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ProductionNameWithPrecRepeat_s3 struct _Con_M_ProductionNameWithPrecRepeat_s3
struct _Con_M_ProductionNameWithPrecRepeat_s3 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ProductionNameWithPrecRepeat_s3;
extern int step_M_ProductionNameWithPrecRepeat_s3(Sink,Term);

/* FUNCTION CookPG-SameSort2-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SameSort2_s6 struct _Con_M_SameSort2_s6
struct _Con_M_SameSort2_s6 {struct _Construction construction; Term sub[10]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SameSort2_s6;
extern int step_M_SameSort2_s6(Sink,Term);

/* FUNCTION CookPG-SameSort2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SameSort2_s7 struct _Con_M_SameSort2_s7
struct _Con_M_SameSort2_s7 {struct _Construction construction; Term sub[10]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SameSort2_s7;
extern int step_M_SameSort2_s7(Sink,Term);

/* FUNCTION CookPG-SameSort2-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SameSort2_s8 struct _Con_M_SameSort2_s8
struct _Con_M_SameSort2_s8 {struct _Construction construction; Term sub[9]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SameSort2_s8;
extern int step_M_SameSort2_s8(Sink,Term);

/* FUNCTION CookPG-SameSort2-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SameSort2_s9 struct _Con_M_SameSort2_s9
struct _Con_M_SameSort2_s9 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SameSort2_s9;
extern int step_M_SameSort2_s9(Sink,Term);

/* FUNCTION CookCRS-CRS-AddAttributes-8$CRS-AddAttributes$OK HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AddAttributes struct _Con_M_CRS_AddAttributes
struct _Con_M_CRS_AddAttributes {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AddAttributes;
extern int step_M_CRS_AddAttributes(Sink,Term);

/* FUNCTION CookPG-IfAliasKind-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_IfAliasKind_s5 struct _Con_M_IfAliasKind_s5
struct _Con_M_IfAliasKind_s5 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_IfAliasKind_s5;
extern int step_M_IfAliasKind_s5(Sink,Term);

/* FUNCTION CookCRS-FormPrec- HEADER DECLARATIONS. */
#define STRUCT_Con_M_FormPrec struct _Con_M_FormPrec
struct _Con_M_FormPrec {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_FormPrec;
extern int step_M_FormPrec(Sink,Term);

/* FUNCTION Prelude-SameString-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SameString struct _Con_M_SameString
struct _Con_M_SameString {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SameString;
extern int step_M_SameString(Sink,Term);

/* FUNCTION CookPG-PG-isLeftRecursive1-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG__isLeftRecursive1_s18 struct _Con_M_PG__isLeftRecursive1_s18
struct _Con_M_PG__isLeftRecursive1_s18 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG__isLeftRecursive1_s18;
extern int step_M_PG__isLeftRecursive1_s18(Sink,Term);

/* FUNCTION CookPG-PG-isLeftRecursive1-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG__isLeftRecursive1_s17 struct _Con_M_PG__isLeftRecursive1_s17
struct _Con_M_PG__isLeftRecursive1_s17 {struct _Construction construction; Term sub[9]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG__isLeftRecursive1_s17;
extern int step_M_PG__isLeftRecursive1_s17(Sink,Term);

/* FUNCTION CookN-N-SortAlternativesDefines- HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_SortAlternativesDefines struct _Con_M_N_SortAlternativesDefines
struct _Con_M_N_SortAlternativesDefines {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_SortAlternativesDefines;
extern int step_M_N_SortAlternativesDefines(Sink,Term);

/* FUNCTION CookPG-PG-isLeftRecursive1-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG__isLeftRecursive1_s19 struct _Con_M_PG__isLeftRecursive1_s19
struct _Con_M_PG__isLeftRecursive1_s19 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG__isLeftRecursive1_s19;
extern int step_M_PG__isLeftRecursive1_s19(Sink,Term);

/* FUNCTION CookPG-PG-isLeftRecursive1-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG__isLeftRecursive1_s14 struct _Con_M_PG__isLeftRecursive1_s14
struct _Con_M_PG__isLeftRecursive1_s14 {struct _Construction construction; Term sub[9]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG__isLeftRecursive1_s14;
extern int step_M_PG__isLeftRecursive1_s14(Sink,Term);

/* FUNCTION CookPG-IfAliasKind-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_IfAliasKind_s3 struct _Con_M_IfAliasKind_s3
struct _Con_M_IfAliasKind_s3 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_IfAliasKind_s3;
extern int step_M_IfAliasKind_s3(Sink,Term);

/* FUNCTION CookPG-PG-isLeftRecursive1- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG__isLeftRecursive1_s13 struct _Con_M_PG__isLeftRecursive1_s13
struct _Con_M_PG__isLeftRecursive1_s13 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG__isLeftRecursive1_s13;
extern int step_M_PG__isLeftRecursive1_s13(Sink,Term);

/* FUNCTION CookCRS-CRS-Term-Core- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Term_Core struct _Con_M_CRS_Term_Core
struct _Con_M_CRS_Term_Core {struct _Construction construction; Term sub[7]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Term_Core;
extern int step_M_CRS_Term_Core(Sink,Term);

/* FUNCTION CookPG-IfAliasKind-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_IfAliasKind_s4 struct _Con_M_IfAliasKind_s4
struct _Con_M_IfAliasKind_s4 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_IfAliasKind_s4;
extern int step_M_IfAliasKind_s4(Sink,Term);

/* FUNCTION CookPG-PG-isLeftRecursive1-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG__isLeftRecursive1_s16 struct _Con_M_PG__isLeftRecursive1_s16
struct _Con_M_PG__isLeftRecursive1_s16 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG__isLeftRecursive1_s16;
extern int step_M_PG__isLeftRecursive1_s16(Sink,Term);

/* FUNCTION CookPG-IfAliasKind-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_IfAliasKind_s1 struct _Con_M_IfAliasKind_s1
struct _Con_M_IfAliasKind_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_IfAliasKind_s1;
extern int step_M_IfAliasKind_s1(Sink,Term);

/* FUNCTION CookPG-PG-isLeftRecursive1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG__isLeftRecursive1_s15 struct _Con_M_PG__isLeftRecursive1_s15
struct _Con_M_PG__isLeftRecursive1_s15 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG__isLeftRecursive1_s15;
extern int step_M_PG__isLeftRecursive1_s15(Sink,Term);

/* FUNCTION CookPG-IfAliasKind-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_IfAliasKind_s2 struct _Con_M_IfAliasKind_s2
struct _Con_M_IfAliasKind_s2 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_IfAliasKind_s2;
extern int step_M_IfAliasKind_s2(Sink,Term);

/* FUNCTION CookPG-PG-isLeftRecursive1-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG__isLeftRecursive1_s20 struct _Con_M_PG__isLeftRecursive1_s20
struct _Con_M_PG__isLeftRecursive1_s20 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG__isLeftRecursive1_s20;
extern int step_M_PG__isLeftRecursive1_s20(Sink,Term);

/* FUNCTION CookPG-PG-isLeftRecursive1-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG__isLeftRecursive1_s21 struct _Con_M_PG__isLeftRecursive1_s21
struct _Con_M_PG__isLeftRecursive1_s21 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG__isLeftRecursive1_s21;
extern int step_M_PG__isLeftRecursive1_s21(Sink,Term);

/* FUNCTION CookN-N-CaptureOtherMaps-1$N-CaptureOtherMaps HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_CaptureOtherMaps struct _Con_M_N_CaptureOtherMaps
struct _Con_M_N_CaptureOtherMaps {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_CaptureOtherMaps;
extern int step_M_N_CaptureOtherMaps(Sink,Term);

/* FUNCTION CookCRS-CRS-MatchSynthesisNeeds-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_MatchSynthesisNeeds_s1 struct _Con_M_CRS_MatchSynthesisNeeds_s1
struct _Con_M_CRS_MatchSynthesisNeeds_s1 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_MatchSynthesisNeeds_s1;
extern int step_M_CRS_MatchSynthesisNeeds_s1(Sink,Term);

/* FUNCTION Prelude-UnionNames-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_UnionNames struct _Con_M_UnionNames
struct _Con_M_UnionNames {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_UnionNames;
extern int step_M_UnionNames(Sink,Term);

/* FUNCTION CookBase-ScopeSortMetaVar- HEADER DECLARATIONS. */
#define STRUCT_Con_M_ScopeSortMetaVar struct _Con_M_ScopeSortMetaVar
struct _Con_M_ScopeSortMetaVar {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ScopeSortMetaVar;
extern int step_M_ScopeSortMetaVar(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Scopes-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Scopes struct _Con_M_DerivedSorts_Scopes
struct _Con_M_DerivedSorts_Scopes {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Scopes;
extern int step_M_DerivedSorts_Scopes(Sink,Term);

/* FUNCTION CookN-_DefineWrapperSugar- HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefineWrapperSugar struct _Con_M__xDefineWrapperSugar
struct _Con_M__xDefineWrapperSugar {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xDefineWrapperSugar;
extern int step_M__xDefineWrapperSugar(Sink,Term);

/* FUNCTION CookPG-PG-LeftRecursive2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_LeftRecursive2_s1 struct _Con_M_PG_LeftRecursive2_s1
struct _Con_M_PG_LeftRecursive2_s1 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_LeftRecursive2_s1;
extern int step_M_PG_LeftRecursive2_s1(Sink,Term);

/* FUNCTION CookBase-AttributeName-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_AttributeName_s1 struct _Con_M_AttributeName_s1
struct _Con_M_AttributeName_s1 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_AttributeName_s1;
extern int step_M_AttributeName_s1(Sink,Term);

/* FUNCTION CookPG-PG-LeftRecursive2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_LeftRecursive2_s2 struct _Con_M_PG_LeftRecursive2_s2
struct _Con_M_PG_LeftRecursive2_s2 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_LeftRecursive2_s2;
extern int step_M_PG_LeftRecursive2_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-Defines-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_Defines_s1 struct _Con_M_CRS_Rules_Defines_s1
struct _Con_M_CRS_Rules_Defines_s1 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_Defines_s1;
extern int step_M_CRS_Rules_Defines_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-Defines-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_Defines_s2 struct _Con_M_CRS_Rules_Defines_s2
struct _Con_M_CRS_Rules_Defines_s2 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_Defines_s2;
extern int step_M_CRS_Rules_Defines_s2(Sink,Term);

/* FUNCTION CookN-_FormLess- HEADER DECLARATIONS. */
#define STRUCT_Con_M__xFormLess_s8 struct _Con_M__xFormLess_s8
struct _Con_M__xFormLess_s8 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xFormLess_s8;
extern int step_M__xFormLess_s8(Sink,Term);

/* FUNCTION CookN-_FormLess-7 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xFormLess_s9 struct _Con_M__xFormLess_s9
struct _Con_M__xFormLess_s9 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xFormLess_s9;
extern int step_M__xFormLess_s9(Sink,Term);

/* FUNCTION CookBase-IfSingletonRepeat- HEADER DECLARATIONS. */
#define STRUCT_Con_M_IfSingletonRepeat struct _Con_M_IfSingletonRepeat
struct _Con_M_IfSingletonRepeat {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_IfSingletonRepeat;
extern int step_M_IfSingletonRepeat(Sink,Term);

/* FUNCTION Prelude-Append-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_Append_s2 struct _Con_M_Append_s2
struct _Con_M_Append_s2 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_Append_s2;
extern int step_M_Append_s2(Sink,Term);

/* FUNCTION CookN-N-SortAlternatives- HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_SortAlternatives struct _Con_M_N_SortAlternatives
struct _Con_M_N_SortAlternatives {struct _Construction construction; Term sub[5]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M_N_SortAlternatives;
extern int step_M_N_SortAlternatives(Sink,Term);

/* FUNCTION CookN-N-Finish-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_Finish struct _Con_M_N_Finish
struct _Con_M_N_Finish {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_Finish;
extern int step_M_N_Finish(Sink,Term);

/* FUNCTION CookPG-SameSort2-2$SameSort2$RAW-Sort HEADER DECLARATIONS. */
#define STRUCT_Con_M_SameSort2 struct _Con_M_SameSort2
struct _Con_M_SameSort2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SameSort2;
extern int step_M_SameSort2(Sink,Term);

/* FUNCTION CookN-_FormLess-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xFormLess_s6 struct _Con_M__xFormLess_s6
struct _Con_M__xFormLess_s6 {struct _Construction construction; Term sub[9]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xFormLess_s6;
extern int step_M__xFormLess_s6(Sink,Term);

/* FUNCTION CookN-_FormLess-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xFormLess_s5 struct _Con_M__xFormLess_s5
struct _Con_M__xFormLess_s5 {struct _Construction construction; Term sub[10]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xFormLess_s5;
extern int step_M__xFormLess_s5(Sink,Term);

/* FUNCTION CookN-_FormLess-6 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xFormLess_s4 struct _Con_M__xFormLess_s4
struct _Con_M__xFormLess_s4 {struct _Construction construction; Term sub[9]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xFormLess_s4;
extern int step_M__xFormLess_s4(Sink,Term);

/* FUNCTION CookN-_FormLess- HEADER DECLARATIONS. */
#define STRUCT_Con_M__xFormLess_s3 struct _Con_M__xFormLess_s3
struct _Con_M__xFormLess_s3 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xFormLess_s3;
extern int step_M__xFormLess_s3(Sink,Term);

/* FUNCTION CookN-_FormLess-5 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xFormLess_s1 struct _Con_M__xFormLess_s1
struct _Con_M__xFormLess_s1 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xFormLess_s1;
extern int step_M__xFormLess_s1(Sink,Term);

/* FUNCTION CookPG-ExtractSubstitutedSort-1$ExtractSubstitutedSort$RAW-SubstituteSort HEADER DECLARATIONS. */
#define STRUCT_Con_M_ExtractSubstitutedSort struct _Con_M_ExtractSubstitutedSort
struct _Con_M_ExtractSubstitutedSort {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ExtractSubstitutedSort;
extern int step_M_ExtractSubstitutedSort(Sink,Term);

/* FUNCTION Prelude-Append-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_Append_s1 struct _Con_M_Append_s1
struct _Con_M_Append_s1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_Append_s1;
extern int step_M_Append_s1(Sink,Term);

/* FUNCTION Prelude-Trim-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_Trim struct _Con_M_Trim
struct _Con_M_Trim {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_Trim;
extern int step_M_Trim(Sink,Term);

/* FUNCTION CookN-ConstructorScopeSorts1-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ConstructorScopeSorts1_s1 struct _Con_M_ConstructorScopeSorts1_s1
struct _Con_M_ConstructorScopeSorts1_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ConstructorScopeSorts1_s1;
extern int step_M_ConstructorScopeSorts1_s1(Sink,Term);

/* FUNCTION CookN-ConstructorScopeSorts1-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ConstructorScopeSorts1_s2 struct _Con_M_ConstructorScopeSorts1_s2
struct _Con_M_ConstructorScopeSorts1_s2 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ConstructorScopeSorts1_s2;
extern int step_M_ConstructorScopeSorts1_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-then-Rules-DataSynth-Fold-1$CRS-then-Rules-DataSynth-Fold$OK HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS__then_Rules_DataSynth_Fold struct _Con_M_CRS__then_Rules_DataSynth_Fold
struct _Con_M_CRS__then_Rules_DataSynth_Fold {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS__then_Rules_DataSynth_Fold;
extern int step_M_CRS__then_Rules_DataSynth_Fold(Sink,Term);

/* FUNCTION CookN-ConstructorScopeSorts1-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ConstructorScopeSorts1_s3 struct _Con_M_ConstructorScopeSorts1_s3
struct _Con_M_ConstructorScopeSorts1_s3 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ConstructorScopeSorts1_s3;
extern int step_M_ConstructorScopeSorts1_s3(Sink,Term);

/* FUNCTION CookN-ConstructorScopeSorts1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ConstructorScopeSorts1_s4 struct _Con_M_ConstructorScopeSorts1_s4
struct _Con_M_ConstructorScopeSorts1_s4 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ConstructorScopeSorts1_s4;
extern int step_M_ConstructorScopeSorts1_s4(Sink,Term);

/* FUNCTION CookN-ConstructorScopeSorts1-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ConstructorScopeSorts1_s5 struct _Con_M_ConstructorScopeSorts1_s5
struct _Con_M_ConstructorScopeSorts1_s5 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ConstructorScopeSorts1_s5;
extern int step_M_ConstructorScopeSorts1_s5(Sink,Term);

/* FUNCTION CookN-ConstructorScopeSorts0-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ConstructorScopeSorts0 struct _Con_M_ConstructorScopeSorts0
struct _Con_M_ConstructorScopeSorts0 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ConstructorScopeSorts0;
extern int step_M_ConstructorScopeSorts0(Sink,Term);

/* FUNCTION CookBase-NestedRepeat-some-single HEADER DECLARATIONS. */
#define STRUCT_Con_M_NestedRepeat_s22 struct _Con_M_NestedRepeat_s22
struct _Con_M_NestedRepeat_s22 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NestedRepeat_s22;
extern int step_M_NestedRepeat_s22(Sink,Term);

/* FUNCTION CookBase-NestedRepeat-some-some HEADER DECLARATIONS. */
#define STRUCT_Con_M_NestedRepeat_s23 struct _Con_M_NestedRepeat_s23
struct _Con_M_NestedRepeat_s23 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NestedRepeat_s23;
extern int step_M_NestedRepeat_s23(Sink,Term);

/* FUNCTION CookN-ConstructorScopeSorts2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_ConstructorScopeSorts2 struct _Con_M_ConstructorScopeSorts2
struct _Con_M_ConstructorScopeSorts2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ConstructorScopeSorts2;
extern int step_M_ConstructorScopeSorts2(Sink,Term);

/* FUNCTION CookBase-NestedRepeat-some-maybe HEADER DECLARATIONS. */
#define STRUCT_Con_M_NestedRepeat_s20 struct _Con_M_NestedRepeat_s20
struct _Con_M_NestedRepeat_s20 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NestedRepeat_s20;
extern int step_M_NestedRepeat_s20(Sink,Term);

/* FUNCTION CookN-ConstructorScopeSorts1- HEADER DECLARATIONS. */
#define STRUCT_Con_M_ConstructorScopeSorts1 struct _Con_M_ConstructorScopeSorts1
struct _Con_M_ConstructorScopeSorts1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ConstructorScopeSorts1;
extern int step_M_ConstructorScopeSorts1(Sink,Term);

/* FUNCTION CookN-N-then-Declarations1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N__then_Declarations1_s1 struct _Con_M_N__then_Declarations1_s1
struct _Con_M_N__then_Declarations1_s1 {struct _Construction construction; Term sub[5]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M_N__then_Declarations1_s1;
extern int step_M_N__then_Declarations1_s1(Sink,Term);

/* FUNCTION CookBase-NestedRepeat-some-many HEADER DECLARATIONS. */
#define STRUCT_Con_M_NestedRepeat_s21 struct _Con_M_NestedRepeat_s21
struct _Con_M_NestedRepeat_s21 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NestedRepeat_s21;
extern int step_M_NestedRepeat_s21(Sink,Term);

/* FUNCTION CookBase-NestedRepeat-somesep- HEADER DECLARATIONS. */
#define STRUCT_Con_M_NestedRepeat_s26 struct _Con_M_NestedRepeat_s26
struct _Con_M_NestedRepeat_s26 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NestedRepeat_s26;
extern int step_M_NestedRepeat_s26(Sink,Term);

/* FUNCTION CookBase-NestedRepeat-somesep-maybe HEADER DECLARATIONS. */
#define STRUCT_Con_M_NestedRepeat_s27 struct _Con_M_NestedRepeat_s27
struct _Con_M_NestedRepeat_s27 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NestedRepeat_s27;
extern int step_M_NestedRepeat_s27(Sink,Term);

/* FUNCTION CookCRS-CRS-Scope-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Scope_s1 struct _Con_M_CRS_Scope_s1
struct _Con_M_CRS_Scope_s1 {struct _Construction construction; Term sub[7]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Scope_s1;
extern int step_M_CRS_Scope_s1(Sink,Term);

/* FUNCTION CookBase-NestedRepeat-some-somesep HEADER DECLARATIONS. */
#define STRUCT_Con_M_NestedRepeat_s24 struct _Con_M_NestedRepeat_s24
struct _Con_M_NestedRepeat_s24 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NestedRepeat_s24;
extern int step_M_NestedRepeat_s24(Sink,Term);

/* FUNCTION CookBase-NestedRepeat-somesep-many HEADER DECLARATIONS. */
#define STRUCT_Con_M_NestedRepeat_s28 struct _Con_M_NestedRepeat_s28
struct _Con_M_NestedRepeat_s28 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NestedRepeat_s28;
extern int step_M_NestedRepeat_s28(Sink,Term);

/* FUNCTION CookBase-NestedRepeat-somesep-single HEADER DECLARATIONS. */
#define STRUCT_Con_M_NestedRepeat_s29 struct _Con_M_NestedRepeat_s29
struct _Con_M_NestedRepeat_s29 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NestedRepeat_s29;
extern int step_M_NestedRepeat_s29(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-Derived-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_Derived_s1 struct _Con_M_CRS_Rules_Derived_s1
struct _Con_M_CRS_Rules_Derived_s1 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_Derived_s1;
extern int step_M_CRS_Rules_Derived_s1(Sink,Term);

/* FUNCTION CookN-N-then-Finish7-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N__then_Finish7_s1 struct _Con_M_N__then_Finish7_s1
struct _Con_M_N__then_Finish7_s1 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N__then_Finish7_s1;
extern int step_M_N__then_Finish7_s1(Sink,Term);

/* FUNCTION CookN-ConstructorScopeSorts3- HEADER DECLARATIONS. */
#define STRUCT_Con_M_ConstructorScopeSorts3 struct _Con_M_ConstructorScopeSorts3
struct _Con_M_ConstructorScopeSorts3 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ConstructorScopeSorts3;
extern int step_M_ConstructorScopeSorts3(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBodyWord2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBodyWord2_s1 struct _Con_M_PG_ProduceBodyWord2_s1
struct _Con_M_PG_ProduceBodyWord2_s1 {struct _Construction construction; Term sub[9]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBodyWord2_s1;
extern int step_M_PG_ProduceBodyWord2_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-AddAttributes-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AddAttributes_s10 struct _Con_M_CRS_AddAttributes_s10
struct _Con_M_CRS_AddAttributes_s10 {struct _Construction construction; Term sub[9]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AddAttributes_s10;
extern int step_M_CRS_AddAttributes_s10(Sink,Term);

/* FUNCTION CookCRS-CRS-AddAttributes- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AddAttributes_s12 struct _Con_M_CRS_AddAttributes_s12
struct _Con_M_CRS_AddAttributes_s12 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AddAttributes_s12;
extern int step_M_CRS_AddAttributes_s12(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBodyWord2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBodyWord2_s2 struct _Con_M_PG_ProduceBodyWord2_s2
struct _Con_M_PG_ProduceBodyWord2_s2 {struct _Construction construction; Term sub[7]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBodyWord2_s2;
extern int step_M_PG_ProduceBodyWord2_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-AddAttributes-5 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AddAttributes_s13 struct _Con_M_CRS_AddAttributes_s13
struct _Con_M_CRS_AddAttributes_s13 {struct _Construction construction; Term sub[9]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AddAttributes_s13;
extern int step_M_CRS_AddAttributes_s13(Sink,Term);

/* FUNCTION CookCRS-CRS-AddAttributes-7 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AddAttributes_s14 struct _Con_M_CRS_AddAttributes_s14
struct _Con_M_CRS_AddAttributes_s14 {struct _Construction construction; Term sub[10]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AddAttributes_s14;
extern int step_M_CRS_AddAttributes_s14(Sink,Term);

/* FUNCTION CookCRS-CRS-AddAttributes-8 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AddAttributes_s15 struct _Con_M_CRS_AddAttributes_s15
struct _Con_M_CRS_AddAttributes_s15 {struct _Construction construction; Term sub[9]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AddAttributes_s15;
extern int step_M_CRS_AddAttributes_s15(Sink,Term);

/* FUNCTION CookCRS-CRS-AddAttributes-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AddAttributes_s16 struct _Con_M_CRS_AddAttributes_s16
struct _Con_M_CRS_AddAttributes_s16 {struct _Construction construction; Term sub[9]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AddAttributes_s16;
extern int step_M_CRS_AddAttributes_s16(Sink,Term);

/* FUNCTION CookCRS-CRS-AddAttributes-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AddAttributes_s17 struct _Con_M_CRS_AddAttributes_s17
struct _Con_M_CRS_AddAttributes_s17 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AddAttributes_s17;
extern int step_M_CRS_AddAttributes_s17(Sink,Term);

/* FUNCTION CookN-_InsertDefine-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xInsertDefine struct _Con_M__xInsertDefine
struct _Con_M__xInsertDefine {struct _Construction construction; Term sub[4]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M__xInsertDefine;
extern int step_M__xInsertDefine(Sink,Term);

/* FUNCTION Prelude-NumberToText-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_NumberToText struct _Con_M_NumberToText
struct _Con_M_NumberToText {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NumberToText;
extern int step_M_NumberToText(Sink,Term);

/* FUNCTION CookBase-NestedRepeat-somesep-some HEADER DECLARATIONS. */
#define STRUCT_Con_M_NestedRepeat_s30 struct _Con_M_NestedRepeat_s30
struct _Con_M_NestedRepeat_s30 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NestedRepeat_s30;
extern int step_M_NestedRepeat_s30(Sink,Term);

/* FUNCTION CookBase-NestedRepeat-somesep-somesep HEADER DECLARATIONS. */
#define STRUCT_Con_M_NestedRepeat_s31 struct _Con_M_NestedRepeat_s31
struct _Con_M_NestedRepeat_s31 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NestedRepeat_s31;
extern int step_M_NestedRepeat_s31(Sink,Term);

/* FUNCTION Prelude-FirstName-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_FirstName_s1 struct _Con_M_FirstName_s1
struct _Con_M_FirstName_s1 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_FirstName_s1;
extern int step_M_FirstName_s1(Sink,Term);

/* FUNCTION CookPG-SameSort-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SameSort struct _Con_M_SameSort
struct _Con_M_SameSort {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SameSort;
extern int step_M_SameSort(Sink,Term);

/* FUNCTION Prelude-NameSetList-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_NameSetList struct _Con_M_NameSetList
struct _Con_M_NameSetList {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NameSetList;
extern int step_M_NameSetList(Sink,Term);

/* FUNCTION CookPG-ProductionWord-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ProductionWord struct _Con_M_ProductionWord
struct _Con_M_ProductionWord {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ProductionWord;
extern int step_M_ProductionWord(Sink,Term);

/* FUNCTION CookPG-PG-LeftRecursive-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_LeftRecursive_s1 struct _Con_M_PG_LeftRecursive_s1
struct _Con_M_PG_LeftRecursive_s1 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_LeftRecursive_s1;
extern int step_M_PG_LeftRecursive_s1(Sink,Term);

/* FUNCTION CookPG-PG-LeftRecursive-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_LeftRecursive_s2 struct _Con_M_PG_LeftRecursive_s2
struct _Con_M_PG_LeftRecursive_s2 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_LeftRecursive_s2;
extern int step_M_PG_LeftRecursive_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-SynthesizeRule1- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_SynthesizeRule1_s3 struct _Con_M_CRS_SynthesizeRule1_s3
struct _Con_M_CRS_SynthesizeRule1_s3 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_SynthesizeRule1_s3;
extern int step_M_CRS_SynthesizeRule1_s3(Sink,Term);

/* FUNCTION CookN-_InsertDefine1-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xInsertDefine1_s1 struct _Con_M__xInsertDefine1_s1
struct _Con_M__xInsertDefine1_s1 {struct _Construction construction; Term sub[4]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M__xInsertDefine1_s1;
extern int step_M__xInsertDefine1_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-SynthesizeRule1-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_SynthesizeRule1_s4 struct _Con_M_CRS_SynthesizeRule1_s4
struct _Con_M_CRS_SynthesizeRule1_s4 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_SynthesizeRule1_s4;
extern int step_M_CRS_SynthesizeRule1_s4(Sink,Term);

/* FUNCTION CookCRS-CRS-SynthesizeRule1-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_SynthesizeRule1_s5 struct _Con_M_CRS_SynthesizeRule1_s5
struct _Con_M_CRS_SynthesizeRule1_s5 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_SynthesizeRule1_s5;
extern int step_M_CRS_SynthesizeRule1_s5(Sink,Term);

/* FUNCTION CookCRS-CRS-SynthesizeRule1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_SynthesizeRule1_s6 struct _Con_M_CRS_SynthesizeRule1_s6
struct _Con_M_CRS_SynthesizeRule1_s6 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_SynthesizeRule1_s6;
extern int step_M_CRS_SynthesizeRule1_s6(Sink,Term);

/* FUNCTION CookN-_InsertDefine1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xInsertDefine1_s2 struct _Con_M__xInsertDefine1_s2
struct _Con_M__xInsertDefine1_s2 {struct _Construction construction; Term sub[9]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M__xInsertDefine1_s2;
extern int step_M__xInsertDefine1_s2(Sink,Term);

/* FUNCTION CookPG-Lexical-token HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Lexical2_s13 struct _Con_M_PG_Lexical2_s13
struct _Con_M_PG_Lexical2_s13 {struct _Construction construction; Term sub[7]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M_PG_Lexical2_s13;
extern int step_M_PG_Lexical2_s13(Sink,Term);

/* FUNCTION CookPG-Lexical-synthesizedref HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Lexical2_s12 struct _Con_M_PG_Lexical2_s12
struct _Con_M_PG_Lexical2_s12 {struct _Construction construction; Term sub[6]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M_PG_Lexical2_s12;
extern int step_M_PG_Lexical2_s12(Sink,Term);

/* FUNCTION CookPG-Lexical-space HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Lexical2_s11 struct _Con_M_PG_Lexical2_s11
struct _Con_M_PG_Lexical2_s11 {struct _Construction construction; Term sub[6]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M_PG_Lexical2_s11;
extern int step_M_PG_Lexical2_s11(Sink,Term);

/* FUNCTION CookCRS-CRS-Module-1$CRS-Module$11$NAMES HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Module_s11 struct _Con_M_CRS_Module_s11
struct _Con_M_CRS_Module_s11 {struct _Construction construction; Term sub[10]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Module_s11;
extern int step_M_CRS_Module_s11(Sink,Term);

/* FUNCTION CookCRS-CRS-Module-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Module_s12 struct _Con_M_CRS_Module_s12
struct _Con_M_CRS_Module_s12 {struct _Construction construction; Term sub[10]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Module_s12;
extern int step_M_CRS_Module_s12(Sink,Term);

/* FUNCTION CookBase-NestedRepeat-maybe- HEADER DECLARATIONS. */
#define STRUCT_Con_M_NestedRepeat_s1 struct _Con_M_NestedRepeat_s1
struct _Con_M_NestedRepeat_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NestedRepeat_s1;
extern int step_M_NestedRepeat_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-SynthesizeRule1- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_SynthesizeRule1_s1 struct _Con_M_CRS_SynthesizeRule1_s1
struct _Con_M_CRS_SynthesizeRule1_s1 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_SynthesizeRule1_s1;
extern int step_M_CRS_SynthesizeRule1_s1(Sink,Term);

/* FUNCTION CookBase-NestedRepeat-many-maybe HEADER DECLARATIONS. */
#define STRUCT_Con_M_NestedRepeat_s8 struct _Con_M_NestedRepeat_s8
struct _Con_M_NestedRepeat_s8 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NestedRepeat_s8;
extern int step_M_NestedRepeat_s8(Sink,Term);

/* FUNCTION CookBase-NestedRepeat-many-many HEADER DECLARATIONS. */
#define STRUCT_Con_M_NestedRepeat_s9 struct _Con_M_NestedRepeat_s9
struct _Con_M_NestedRepeat_s9 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NestedRepeat_s9;
extern int step_M_NestedRepeat_s9(Sink,Term);

/* FUNCTION CookBase-NestedRepeat-maybe-somesep HEADER DECLARATIONS. */
#define STRUCT_Con_M_NestedRepeat_s6 struct _Con_M_NestedRepeat_s6
struct _Con_M_NestedRepeat_s6 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NestedRepeat_s6;
extern int step_M_NestedRepeat_s6(Sink,Term);

/* FUNCTION CookBase-NestedRepeat-many- HEADER DECLARATIONS. */
#define STRUCT_Con_M_NestedRepeat_s7 struct _Con_M_NestedRepeat_s7
struct _Con_M_NestedRepeat_s7 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NestedRepeat_s7;
extern int step_M_NestedRepeat_s7(Sink,Term);

/* FUNCTION CookBase-NestedRepeat-maybe-single HEADER DECLARATIONS. */
#define STRUCT_Con_M_NestedRepeat_s4 struct _Con_M_NestedRepeat_s4
struct _Con_M_NestedRepeat_s4 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NestedRepeat_s4;
extern int step_M_NestedRepeat_s4(Sink,Term);

/* FUNCTION CookBase-NestedRepeat-maybe-some HEADER DECLARATIONS. */
#define STRUCT_Con_M_NestedRepeat_s5 struct _Con_M_NestedRepeat_s5
struct _Con_M_NestedRepeat_s5 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NestedRepeat_s5;
extern int step_M_NestedRepeat_s5(Sink,Term);

/* FUNCTION CookBase-NestedRepeat-maybe-maybe HEADER DECLARATIONS. */
#define STRUCT_Con_M_NestedRepeat_s2 struct _Con_M_NestedRepeat_s2
struct _Con_M_NestedRepeat_s2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NestedRepeat_s2;
extern int step_M_NestedRepeat_s2(Sink,Term);

/* FUNCTION CookBase-NestedRepeat-maybe-many HEADER DECLARATIONS. */
#define STRUCT_Con_M_NestedRepeat_s3 struct _Con_M_NestedRepeat_s3
struct _Con_M_NestedRepeat_s3 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NestedRepeat_s3;
extern int step_M_NestedRepeat_s3(Sink,Term);

/* FUNCTION CookCRS-CRS-MetaDeclarations-Derived-1$CRS-MetaDeclarations-Derived$DERIVED HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_MetaDeclarations_Derived struct _Con_M_CRS_MetaDeclarations_Derived
struct _Con_M_CRS_MetaDeclarations_Derived {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_MetaDeclarations_Derived;
extern int step_M_CRS_MetaDeclarations_Derived(Sink,Term);

/* FUNCTION CookN-_DefineWrapperSugar-5 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefineWrapperSugar_s3 struct _Con_M__xDefineWrapperSugar_s3
struct _Con_M__xDefineWrapperSugar_s3 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xDefineWrapperSugar_s3;
extern int step_M__xDefineWrapperSugar_s3(Sink,Term);

/* FUNCTION CookN-_DefineWrapperSugar-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefineWrapperSugar_s4 struct _Con_M__xDefineWrapperSugar_s4
struct _Con_M__xDefineWrapperSugar_s4 {struct _Construction construction; Term sub[9]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xDefineWrapperSugar_s4;
extern int step_M__xDefineWrapperSugar_s4(Sink,Term);

/* FUNCTION Prelude-Hd-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_Hd_s1 struct _Con_M_Hd_s1
struct _Con_M_Hd_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_Hd_s1;
extern int step_M_Hd_s1(Sink,Term);

/* FUNCTION CookN-_DefineWrapperSugar-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefineWrapperSugar_s5 struct _Con_M__xDefineWrapperSugar_s5
struct _Con_M__xDefineWrapperSugar_s5 {struct _Construction construction; Term sub[11]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xDefineWrapperSugar_s5;
extern int step_M__xDefineWrapperSugar_s5(Sink,Term);

/* FUNCTION Prelude-Hd-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_Hd_s2 struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_Hd_s2;
extern int step_M_Hd_s2(Sink,Term);

/* FUNCTION CookN-_DefineWrapperSugar-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefineWrapperSugar_s6 struct _Con_M__xDefineWrapperSugar_s6
struct _Con_M__xDefineWrapperSugar_s6 {struct _Construction construction; Term sub[9]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xDefineWrapperSugar_s6;
extern int step_M__xDefineWrapperSugar_s6(Sink,Term);

/* FUNCTION Prelude-Append- HEADER DECLARATIONS. */
#define STRUCT_Con_M_Append struct _Con_M_Append
struct _Con_M_Append {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_Append;
extern int step_M_Append(Sink,Term);

/* FUNCTION CookCRS-AddInheritedName-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_AddInheritedName struct _Con_M_AddInheritedName
struct _Con_M_AddInheritedName {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_AddInheritedName;
extern int step_M_AddInheritedName(Sink,Term);

/* FUNCTION CookCRS-CRS-SortMetaVar-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_SortMetaVar struct _Con_M_CRS_SortMetaVar
struct _Con_M_CRS_SortMetaVar {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_SortMetaVar;
extern int step_M_CRS_SortMetaVar(Sink,Term);

/* FUNCTION CookN-_DefineWrapperSugar- HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefineWrapperSugar_s1 struct _Con_M__xDefineWrapperSugar_s1
struct _Con_M__xDefineWrapperSugar_s1 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xDefineWrapperSugar_s1;
extern int step_M__xDefineWrapperSugar_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-ParamSequence- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_ParamSequence struct _Con_M_CRS_ParamSequence
struct _Con_M_CRS_ParamSequence {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_ParamSequence;
extern int step_M_CRS_ParamSequence(Sink,Term);

/* FUNCTION CookN-_DefineWrapperSugar-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefineWrapperSugar_s2 struct _Con_M__xDefineWrapperSugar_s2
struct _Con_M__xDefineWrapperSugar_s2 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xDefineWrapperSugar_s2;
extern int step_M__xDefineWrapperSugar_s2(Sink,Term);

/* FUNCTION Prelude-TextToString-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_TextToString_s2 struct _Con_M_TextToString_s2
struct _Con_M_TextToString_s2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_TextToString_s2;
extern int step_M_TextToString_s2(Sink,Term);

/* FUNCTION Prelude-TextToString-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_TextToString_s1 struct _Con_M_TextToString_s1
struct _Con_M_TextToString_s1 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_TextToString_s1;
extern int step_M_TextToString_s1(Sink,Term);

/* FUNCTION CookBase-RegExpLeafWord-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_RegExpLeafWord_s1 struct _Con_M_RegExpLeafWord_s1
struct _Con_M_RegExpLeafWord_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RegExpLeafWord_s1;
extern int step_M_RegExpLeafWord_s1(Sink,Term);

/* FUNCTION CookBase-NestedRepeat-single-somesep HEADER DECLARATIONS. */
#define STRUCT_Con_M_NestedRepeat_s18 struct _Con_M_NestedRepeat_s18
struct _Con_M_NestedRepeat_s18 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NestedRepeat_s18;
extern int step_M_NestedRepeat_s18(Sink,Term);

/* FUNCTION CookBase-RegExpLeafWord-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_RegExpLeafWord_s2 struct _Con_M_RegExpLeafWord_s2
struct _Con_M_RegExpLeafWord_s2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RegExpLeafWord_s2;
extern int step_M_RegExpLeafWord_s2(Sink,Term);

/* FUNCTION CookPG-PG-Production-Attribute-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Production_Attribute struct _Con_M_PG_Production_Attribute
struct _Con_M_PG_Production_Attribute {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_Production_Attribute;
extern int step_M_PG_Production_Attribute(Sink,Term);

/* FUNCTION CookBase-NestedRepeat-single-some HEADER DECLARATIONS. */
#define STRUCT_Con_M_NestedRepeat_s17 struct _Con_M_NestedRepeat_s17
struct _Con_M_NestedRepeat_s17 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NestedRepeat_s17;
extern int step_M_NestedRepeat_s17(Sink,Term);

/* FUNCTION CookBase-NestedRepeat-some- HEADER DECLARATIONS. */
#define STRUCT_Con_M_NestedRepeat_s19 struct _Con_M_NestedRepeat_s19
struct _Con_M_NestedRepeat_s19 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NestedRepeat_s19;
extern int step_M_NestedRepeat_s19(Sink,Term);

/* FUNCTION CookBase-NestedRepeat-single-maybe HEADER DECLARATIONS. */
#define STRUCT_Con_M_NestedRepeat_s14 struct _Con_M_NestedRepeat_s14
struct _Con_M_NestedRepeat_s14 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NestedRepeat_s14;
extern int step_M_NestedRepeat_s14(Sink,Term);

/* FUNCTION CookCRS-CRS-Text-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Text struct _Con_M_CRS_Text
struct _Con_M_CRS_Text {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Text;
extern int step_M_CRS_Text(Sink,Term);

/* FUNCTION CookBase-NestedRepeat-single- HEADER DECLARATIONS. */
#define STRUCT_Con_M_NestedRepeat_s13 struct _Con_M_NestedRepeat_s13
struct _Con_M_NestedRepeat_s13 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NestedRepeat_s13;
extern int step_M_NestedRepeat_s13(Sink,Term);

/* FUNCTION CookBase-NestedRepeat-single-single HEADER DECLARATIONS. */
#define STRUCT_Con_M_NestedRepeat_s16 struct _Con_M_NestedRepeat_s16
struct _Con_M_NestedRepeat_s16 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NestedRepeat_s16;
extern int step_M_NestedRepeat_s16(Sink,Term);

/* FUNCTION CookBase-NestedRepeat-single-many HEADER DECLARATIONS. */
#define STRUCT_Con_M_NestedRepeat_s15 struct _Con_M_NestedRepeat_s15
struct _Con_M_NestedRepeat_s15 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NestedRepeat_s15;
extern int step_M_NestedRepeat_s15(Sink,Term);

/* FUNCTION CookPG-VariableMarker2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_VariableMarker2 struct _Con_M_VariableMarker2
struct _Con_M_VariableMarker2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_VariableMarker2;
extern int step_M_VariableMarker2(Sink,Term);

/* FUNCTION CookBase-NestedRepeat-many-single HEADER DECLARATIONS. */
#define STRUCT_Con_M_NestedRepeat_s10 struct _Con_M_NestedRepeat_s10
struct _Con_M_NestedRepeat_s10 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NestedRepeat_s10;
extern int step_M_NestedRepeat_s10(Sink,Term);

/* FUNCTION Prelude-And- HEADER DECLARATIONS. */
#define STRUCT_Con_M_And struct _Con_M_And
struct _Con_M_And {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_And;
extern int step_M_And(Sink,Term);

/* FUNCTION CookBase-NestedRepeat-many-somesep HEADER DECLARATIONS. */
#define STRUCT_Con_M_NestedRepeat_s12 struct _Con_M_NestedRepeat_s12
struct _Con_M_NestedRepeat_s12 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NestedRepeat_s12;
extern int step_M_NestedRepeat_s12(Sink,Term);

/* FUNCTION Prelude-TextToString-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_TextToString_s3 struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_TextToString_s3;
extern int step_M_TextToString_s3(Sink,Term);

/* FUNCTION CookBase-NestedRepeat-many-some HEADER DECLARATIONS. */
#define STRUCT_Con_M_NestedRepeat_s11 struct _Con_M_NestedRepeat_s11
struct _Con_M_NestedRepeat_s11 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NestedRepeat_s11;
extern int step_M_NestedRepeat_s11(Sink,Term);

/* FUNCTION CookN-KeepSynthesizedEntry-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepSynthesizedEntry_s1 struct _Con_M_KeepSynthesizedEntry_s1
struct _Con_M_KeepSynthesizedEntry_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepSynthesizedEntry_s1;
extern int step_M_KeepSynthesizedEntry_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-Form-PatternEnv1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Form_PatternEnv1_s3 struct _Con_M_CRS_Form_PatternEnv1_s3
struct _Con_M_CRS_Form_PatternEnv1_s3 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Form_PatternEnv1_s3;
extern int step_M_CRS_Form_PatternEnv1_s3(Sink,Term);

/* FUNCTION CookCRS-CRS-Form-PatternEnv1-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Form_PatternEnv1_s2 struct _Con_M_CRS_Form_PatternEnv1_s2
struct _Con_M_CRS_Form_PatternEnv1_s2 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Form_PatternEnv1_s2;
extern int step_M_CRS_Form_PatternEnv1_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-Form-PatternEnv1-2$CRS-Form-PatternEnv1$1$RAW-InheritedRef HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Form_PatternEnv1_s1 struct _Con_M_CRS_Form_PatternEnv1_s1
struct _Con_M_CRS_Form_PatternEnv1_s1 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Form_PatternEnv1_s1;
extern int step_M_CRS_Form_PatternEnv1_s1(Sink,Term);

/* FUNCTION CookN-ThenRemoveAttributeName-1$ThenRemoveAttributeName$OK HEADER DECLARATIONS. */
#define STRUCT_Con_M_ThenRemoveAttributeName struct _Con_M_ThenRemoveAttributeName
struct _Con_M_ThenRemoveAttributeName {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ThenRemoveAttributeName;
extern int step_M_ThenRemoveAttributeName(Sink,Term);

/* FUNCTION CookPG-PG-stripLeftRecursion- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG__stripLeftRecursion_s1 struct _Con_M_PG__stripLeftRecursion_s1
struct _Con_M_PG__stripLeftRecursion_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG__stripLeftRecursion_s1;
extern int step_M_PG__stripLeftRecursion_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-Rule1- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rule1_s2 struct _Con_M_CRS_Rule1_s2
struct _Con_M_CRS_Rule1_s2 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rule1_s2;
extern int step_M_CRS_Rule1_s2(Sink,Term);

/* FUNCTION CookPG-PG-stripLeftRecursion-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG__stripLeftRecursion_s2 struct _Con_M_PG__stripLeftRecursion_s2
struct _Con_M_PG__stripLeftRecursion_s2 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG__stripLeftRecursion_s2;
extern int step_M_PG__stripLeftRecursion_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-Rule1-5 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rule1_s3 struct _Con_M_CRS_Rule1_s3
struct _Con_M_CRS_Rule1_s3 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rule1_s3;
extern int step_M_CRS_Rule1_s3(Sink,Term);

/* FUNCTION CookCRS-CRS-Rule1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rule1_s6 struct _Con_M_CRS_Rule1_s6
struct _Con_M_CRS_Rule1_s6 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rule1_s6;
extern int step_M_CRS_Rule1_s6(Sink,Term);

/* FUNCTION CookCRS-CRS-Rule1-6 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rule1_s7 struct _Con_M_CRS_Rule1_s7
struct _Con_M_CRS_Rule1_s7 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rule1_s7;
extern int step_M_CRS_Rule1_s7(Sink,Term);

/* FUNCTION CookCRS-CRS-Rule1-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rule1_s4 struct _Con_M_CRS_Rule1_s4
struct _Con_M_CRS_Rule1_s4 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rule1_s4;
extern int step_M_CRS_Rule1_s4(Sink,Term);

/* FUNCTION CookCRS-CRS-Rule1-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rule1_s5 struct _Con_M_CRS_Rule1_s5
struct _Con_M_CRS_Rule1_s5 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rule1_s5;
extern int step_M_CRS_Rule1_s5(Sink,Term);

/* FUNCTION CookPG-PG-stripLeftRecursion-2$PG-stripLeftRecursion$9$RAW-RepeatSingle HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG__stripLeftRecursion_s9 struct _Con_M_PG__stripLeftRecursion_s9
struct _Con_M_PG__stripLeftRecursion_s9 {struct _Construction construction; Term sub[12]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG__stripLeftRecursion_s9;
extern int step_M_PG__stripLeftRecursion_s9(Sink,Term);

/* FUNCTION CookPG-SameScopeSort2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SameScopeSort2_s13 struct _Con_M_SameScopeSort2_s13
struct _Con_M_SameScopeSort2_s13 {struct _Construction construction; Term sub[10]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SameScopeSort2_s13;
extern int step_M_SameScopeSort2_s13(Sink,Term);

/* FUNCTION CookPG-PG-stripLeftRecursion-2$PG-stripLeftRecursion$7$$Nil HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG__stripLeftRecursion_s7 struct _Con_M_PG__stripLeftRecursion_s7
struct _Con_M_PG__stripLeftRecursion_s7 {struct _Construction construction; Term sub[13]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG__stripLeftRecursion_s7;
extern int step_M_PG__stripLeftRecursion_s7(Sink,Term);

/* FUNCTION CookCRS-CRS-FormScopeMetaApplication2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_FormScopeMetaApplication2_s3 struct _Con_M_CRS_FormScopeMetaApplication2_s3
struct _Con_M_CRS_FormScopeMetaApplication2_s3 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_FormScopeMetaApplication2_s3;
extern int step_M_CRS_FormScopeMetaApplication2_s3(Sink,Term);

/* FUNCTION CookPG-SameScopeSort2-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SameScopeSort2_s14 struct _Con_M_SameScopeSort2_s14
struct _Con_M_SameScopeSort2_s14 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SameScopeSort2_s14;
extern int step_M_SameScopeSort2_s14(Sink,Term);

/* FUNCTION CookCRS-CRS-FormScopeMetaApplication2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_FormScopeMetaApplication2_s2 struct _Con_M_CRS_FormScopeMetaApplication2_s2
struct _Con_M_CRS_FormScopeMetaApplication2_s2 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_FormScopeMetaApplication2_s2;
extern int step_M_CRS_FormScopeMetaApplication2_s2(Sink,Term);

/* FUNCTION CookPG-PG-stripLeftRecursion-2$PG-stripLeftRecursion$5$RAW-SortName HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG__stripLeftRecursion_s5 struct _Con_M_PG__stripLeftRecursion_s5
struct _Con_M_PG__stripLeftRecursion_s5 {struct _Construction construction; Term sub[11]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG__stripLeftRecursion_s5;
extern int step_M_PG__stripLeftRecursion_s5(Sink,Term);

/* FUNCTION CookCRS-CRS-FormScopeMetaApplication2-2$CRS-FormScopeMetaApplication2$1$RAW-SubstituteSort HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_FormScopeMetaApplication2_s1 struct _Con_M_CRS_FormScopeMetaApplication2_s1
struct _Con_M_CRS_FormScopeMetaApplication2_s1 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_FormScopeMetaApplication2_s1;
extern int step_M_CRS_FormScopeMetaApplication2_s1(Sink,Term);

/* FUNCTION CookPG-PG-stripLeftRecursion-2$PG-stripLeftRecursion$3$RAW-ScopeSort HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG__stripLeftRecursion_s3 struct _Con_M_PG__stripLeftRecursion_s3
struct _Con_M_PG__stripLeftRecursion_s3 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG__stripLeftRecursion_s3;
extern int step_M_PG__stripLeftRecursion_s3(Sink,Term);

/* FUNCTION CookPG-PG-stripLeftRecursion-2$PG-stripLeftRecursion$4$RAW-Sort HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG__stripLeftRecursion_s4 struct _Con_M_PG__stripLeftRecursion_s4
struct _Con_M_PG__stripLeftRecursion_s4 {struct _Construction construction; Term sub[9]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG__stripLeftRecursion_s4;
extern int step_M_PG__stripLeftRecursion_s4(Sink,Term);

/* FUNCTION CookCRS-SortSynthesizes-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortSynthesizes struct _Con_M_SortSynthesizes
struct _Con_M_SortSynthesizes {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortSynthesizes;
extern int step_M_SortSynthesizes(Sink,Term);

/* FUNCTION CookN-DerivedSorts2-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts2_s1 struct _Con_M_DerivedSorts2_s1
struct _Con_M_DerivedSorts2_s1 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts2_s1;
extern int step_M_DerivedSorts2_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-Rule1-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rule1_s8 struct _Con_M_CRS_Rule1_s8
struct _Con_M_CRS_Rule1_s8 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rule1_s8;
extern int step_M_CRS_Rule1_s8(Sink,Term);

/* FUNCTION CookN-DerivedSorts2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts2_s4 struct _Con_M_DerivedSorts2_s4
struct _Con_M_DerivedSorts2_s4 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts2_s4;
extern int step_M_DerivedSorts2_s4(Sink,Term);

/* FUNCTION CookN-DerivedSorts2-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts2_s3 struct _Con_M_DerivedSorts2_s3
struct _Con_M_DerivedSorts2_s3 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts2_s3;
extern int step_M_DerivedSorts2_s3(Sink,Term);

/* FUNCTION CookN-DerivedSorts2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts2_s2 struct _Con_M_DerivedSorts2_s2
struct _Con_M_DerivedSorts2_s2 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts2_s2;
extern int step_M_DerivedSorts2_s2(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBodyTerm3-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBodyTerm3_s1 struct _Con_M_PG_ProduceBodyTerm3_s1
struct _Con_M_PG_ProduceBodyTerm3_s1 {struct _Construction construction; Term sub[13]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBodyTerm3_s1;
extern int step_M_PG_ProduceBodyTerm3_s1(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBodyTerm3-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBodyTerm3_s2 struct _Con_M_PG_ProduceBodyTerm3_s2
struct _Con_M_PG_ProduceBodyTerm3_s2 {struct _Construction construction; Term sub[11]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBodyTerm3_s2;
extern int step_M_PG_ProduceBodyTerm3_s2(Sink,Term);

/* FUNCTION CookPG-PG-DeclareRegExpUnit-1$PG-DeclareRegExpUnit$RAW-RegExpUnit HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_DeclareRegExpUnit struct _Con_M_PG_DeclareRegExpUnit
struct _Con_M_PG_DeclareRegExpUnit {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_DeclareRegExpUnit;
extern int step_M_PG_DeclareRegExpUnit(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-DataSynth-1$CRS-Rules-DataSynth$OK HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_DataSynth struct _Con_M_CRS_Rules_DataSynth
struct _Con_M_CRS_Rules_DataSynth {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_DataSynth;
extern int step_M_CRS_Rules_DataSynth(Sink,Term);

/* FUNCTION CookN-AttributeKeySortName-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_AttributeKeySortName struct _Con_M_AttributeKeySortName
struct _Con_M_AttributeKeySortName {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_AttributeKeySortName;
extern int step_M_AttributeKeySortName(Sink,Term);

/* FUNCTION CookPG-ExtractSubstitutedSort-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ExtractSubstitutedSort_s1 struct _Con_M_ExtractSubstitutedSort_s1
struct _Con_M_ExtractSubstitutedSort_s1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ExtractSubstitutedSort_s1;
extern int step_M_ExtractSubstitutedSort_s1(Sink,Term);

/* FUNCTION CookPG-Lexical-sort HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Lexical2_s10 struct _Con_M_PG_Lexical2_s10
struct _Con_M_PG_Lexical2_s10 {struct _Construction construction; Term sub[8]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M_PG_Lexical2_s10;
extern int step_M_PG_Lexical2_s10(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBody1-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBody1_s9 struct _Con_M_PG_ProduceBody1_s9
struct _Con_M_PG_ProduceBody1_s9 {struct _Construction construction; Term sub[10]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBody1_s9;
extern int step_M_PG_ProduceBody1_s9(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBody1-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBody1_s7 struct _Con_M_PG_ProduceBody1_s7
struct _Con_M_PG_ProduceBody1_s7 {struct _Construction construction; Term sub[10]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBody1_s7;
extern int step_M_PG_ProduceBody1_s7(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBody1-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBody1_s8 struct _Con_M_PG_ProduceBody1_s8
struct _Con_M_PG_ProduceBody1_s8 {struct _Construction construction; Term sub[12]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBody1_s8;
extern int step_M_PG_ProduceBody1_s8(Sink,Term);

/* FUNCTION CookN-KeepSynthesizedEntry1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepSynthesizedEntry1 struct _Con_M_KeepSynthesizedEntry1
struct _Con_M_KeepSynthesizedEntry1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepSynthesizedEntry1;
extern int step_M_KeepSynthesizedEntry1(Sink,Term);

/* FUNCTION CookN-_AddSynthesizedRefs- HEADER DECLARATIONS. */
#define STRUCT_Con_M__xAddSynthesizedRefs_s1 struct _Con_M__xAddSynthesizedRefs_s1
struct _Con_M__xAddSynthesizedRefs_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xAddSynthesizedRefs_s1;
extern int step_M__xAddSynthesizedRefs_s1(Sink,Term);

/* FUNCTION Prelude-HasNames-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_HasNames_s1 struct _Con_M_HasNames_s1
struct _Con_M_HasNames_s1 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_HasNames_s1;
extern int step_M_HasNames_s1(Sink,Term);

/* FUNCTION CookN-KeepSynthesizedEntry2-2$KeepSynthesizedEntry2$ HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepSynthesizedEntry2 struct _Con_M_KeepSynthesizedEntry2
struct _Con_M_KeepSynthesizedEntry2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepSynthesizedEntry2;
extern int step_M_KeepSynthesizedEntry2(Sink,Term);

/* FUNCTION CookN-_AddSynthesizedRefs-2$_AddSynthesizedRefs$2$RAW-SynthesizedRef HEADER DECLARATIONS. */
#define STRUCT_Con_M__xAddSynthesizedRefs_s2 struct _Con_M__xAddSynthesizedRefs_s2
struct _Con_M__xAddSynthesizedRefs_s2 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xAddSynthesizedRefs_s2;
extern int step_M__xAddSynthesizedRefs_s2(Sink,Term);

/* FUNCTION CookN-_AddSynthesizedRefs-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xAddSynthesizedRefs_s3 struct _Con_M__xAddSynthesizedRefs_s3
struct _Con_M__xAddSynthesizedRefs_s3 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xAddSynthesizedRefs_s3;
extern int step_M__xAddSynthesizedRefs_s3(Sink,Term);

/* FUNCTION CookN-_AddSynthesizedRefs-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xAddSynthesizedRefs_s4 struct _Con_M__xAddSynthesizedRefs_s4
struct _Con_M__xAddSynthesizedRefs_s4 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xAddSynthesizedRefs_s4;
extern int step_M__xAddSynthesizedRefs_s4(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBody1-5$PG-ProduceBody1$1$PFK HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBody1_s1 struct _Con_M_PG_ProduceBody1_s1
struct _Con_M_PG_ProduceBody1_s1 {struct _Construction construction; Term sub[7]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBody1_s1;
extern int step_M_PG_ProduceBody1_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-Binders-SubstituteSorts-2$CRS-Binders-SubstituteSorts$1$RAW-SubstituteSort HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Binders_SubstituteSorts_s1 struct _Con_M_CRS_Binders_SubstituteSorts_s1
struct _Con_M_CRS_Binders_SubstituteSorts_s1 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Binders_SubstituteSorts_s1;
extern int step_M_CRS_Binders_SubstituteSorts_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-Declarations-Inherited-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declarations_Inherited_s1 struct _Con_M_CRS_Declarations_Inherited_s1
struct _Con_M_CRS_Declarations_Inherited_s1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declarations_Inherited_s1;
extern int step_M_CRS_Declarations_Inherited_s1(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBody1- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBody1_s2 struct _Con_M_PG_ProduceBody1_s2
struct _Con_M_PG_ProduceBody1_s2 {struct _Construction construction; Term sub[8]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBody1_s2;
extern int step_M_PG_ProduceBody1_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-NameOptions- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_NameOptions struct _Con_M_CRS_NameOptions
struct _Con_M_CRS_NameOptions {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_NameOptions;
extern int step_M_CRS_NameOptions(Sink,Term);

/* FUNCTION CookCRS-CRS-MetaDeclarations-PrecWrapper-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_MetaDeclarations_PrecWrapper_s3 struct _Con_M_CRS_MetaDeclarations_PrecWrapper_s3
struct _Con_M_CRS_MetaDeclarations_PrecWrapper_s3 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_MetaDeclarations_PrecWrapper_s3;
extern int step_M_CRS_MetaDeclarations_PrecWrapper_s3(Sink,Term);

/* FUNCTION CookN-AttributeValueSortName2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_AttributeValueSortName2 struct _Con_M_AttributeValueSortName2
struct _Con_M_AttributeValueSortName2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_AttributeValueSortName2;
extern int step_M_AttributeValueSortName2(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBody1-5 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBody1_s5 struct _Con_M_PG_ProduceBody1_s5
struct _Con_M_PG_ProduceBody1_s5 {struct _Construction construction; Term sub[9]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBody1_s5;
extern int step_M_PG_ProduceBody1_s5(Sink,Term);

/* FUNCTION CookCRS-CRS-MetaDeclarations-PrecWrapper- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_MetaDeclarations_PrecWrapper_s1 struct _Con_M_CRS_MetaDeclarations_PrecWrapper_s1
struct _Con_M_CRS_MetaDeclarations_PrecWrapper_s1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_MetaDeclarations_PrecWrapper_s1;
extern int step_M_CRS_MetaDeclarations_PrecWrapper_s1(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBody1-6 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBody1_s6 struct _Con_M_PG_ProduceBody1_s6
struct _Con_M_PG_ProduceBody1_s6 {struct _Construction construction; Term sub[9]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBody1_s6;
extern int step_M_PG_ProduceBody1_s6(Sink,Term);

/* FUNCTION CookCRS-CRS-MetaDeclarations-PrecWrapper-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_MetaDeclarations_PrecWrapper_s2 struct _Con_M_CRS_MetaDeclarations_PrecWrapper_s2
struct _Con_M_CRS_MetaDeclarations_PrecWrapper_s2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_MetaDeclarations_PrecWrapper_s2;
extern int step_M_CRS_MetaDeclarations_PrecWrapper_s2(Sink,Term);

/* FUNCTION CookN-AttributeValueSortName1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_AttributeValueSortName1 struct _Con_M_AttributeValueSortName1
struct _Con_M_AttributeValueSortName1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_AttributeValueSortName1;
extern int step_M_AttributeValueSortName1(Sink,Term);

/* FUNCTION CookCRS-CRS-Binders-SubstituteSorts-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Binders_SubstituteSorts_s3 struct _Con_M_CRS_Binders_SubstituteSorts_s3
struct _Con_M_CRS_Binders_SubstituteSorts_s3 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Binders_SubstituteSorts_s3;
extern int step_M_CRS_Binders_SubstituteSorts_s3(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBody1- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBody1_s4 struct _Con_M_PG_ProduceBody1_s4
struct _Con_M_PG_ProduceBody1_s4 {struct _Construction construction; Term sub[8]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBody1_s4;
extern int step_M_PG_ProduceBody1_s4(Sink,Term);

/* FUNCTION CookCRS-CRS-Binders-SubstituteSorts-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Binders_SubstituteSorts_s2 struct _Con_M_CRS_Binders_SubstituteSorts_s2
struct _Con_M_CRS_Binders_SubstituteSorts_s2 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Binders_SubstituteSorts_s2;
extern int step_M_CRS_Binders_SubstituteSorts_s2(Sink,Term);

/* FUNCTION CookN-N-SortAbstractionDefines2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_SortAbstractionDefines2 struct _Con_M_N_SortAbstractionDefines2
struct _Con_M_N_SortAbstractionDefines2 {struct _Construction construction; Term sub[1]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M_N_SortAbstractionDefines2;
extern int step_M_N_SortAbstractionDefines2(Sink,Term);

/* FUNCTION CookBase-SortName2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortName2_s3 struct _Con_M_SortName2_s3
struct _Con_M_SortName2_s3 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortName2_s3;
extern int step_M_SortName2_s3(Sink,Term);

/* FUNCTION Prelude-HasNames-1$HasNames$NAME_SET HEADER DECLARATIONS. */
#define STRUCT_Con_M_HasNames struct _Con_M_HasNames
struct _Con_M_HasNames {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_HasNames;
extern int step_M_HasNames(Sink,Term);

/* FUNCTION CookBase-SortName2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortName2_s4 struct _Con_M_SortName2_s4
struct _Con_M_SortName2_s4 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortName2_s4;
extern int step_M_SortName2_s4(Sink,Term);

/* FUNCTION CookBase-SortName2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortName2_s5 struct _Con_M_SortName2_s5
struct _Con_M_SortName2_s5 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortName2_s5;
extern int step_M_SortName2_s5(Sink,Term);

/* FUNCTION CookBase-SortName2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortName2_s6 struct _Con_M_SortName2_s6
struct _Con_M_SortName2_s6 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortName2_s6;
extern int step_M_SortName2_s6(Sink,Term);

/* FUNCTION CookN-_InsertDefine1b-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xInsertDefine1b struct _Con_M__xInsertDefine1b
struct _Con_M__xInsertDefine1b {struct _Construction construction; Term sub[6]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M__xInsertDefine1b;
extern int step_M__xInsertDefine1b(Sink,Term);

/* FUNCTION CookN-_DefinePrec- HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefinePrec struct _Con_M__xDefinePrec
struct _Con_M__xDefinePrec {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xDefinePrec;
extern int step_M__xDefinePrec(Sink,Term);

/* FUNCTION CookPG-PG-DeclareRegExpSimple- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_DeclareRegExpSimple struct _Con_M_PG_DeclareRegExpSimple
struct _Con_M_PG_DeclareRegExpSimple {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_DeclareRegExpSimple;
extern int step_M_PG_DeclareRegExpSimple(Sink,Term);

/* FUNCTION CookN-_then-InsertDefines-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xthen_InsertDefines_s1 struct _Con_M__xthen_InsertDefines_s1
struct _Con_M__xthen_InsertDefines_s1 {struct _Construction construction; Term sub[4]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M__xthen_InsertDefines_s1;
extern int step_M__xthen_InsertDefines_s1(Sink,Term);

/* FUNCTION CookBase-SortName2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortName2_s1 struct _Con_M_SortName2_s1
struct _Con_M_SortName2_s1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortName2_s1;
extern int step_M_SortName2_s1(Sink,Term);

/* FUNCTION CookPG-PG-InlineRegExpUnits-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_InlineRegExpUnits_s1 struct _Con_M_PG_InlineRegExpUnits_s1
struct _Con_M_PG_InlineRegExpUnits_s1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_InlineRegExpUnits_s1;
extern int step_M_PG_InlineRegExpUnits_s1(Sink,Term);

/* FUNCTION CookBase-SortName2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortName2_s2 struct _Con_M_SortName2_s2
struct _Con_M_SortName2_s2 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortName2_s2;
extern int step_M_SortName2_s2(Sink,Term);

/* FUNCTION CookPG-PG-InlineRegExpUnits-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_InlineRegExpUnits_s2 struct _Con_M_PG_InlineRegExpUnits_s2
struct _Con_M_PG_InlineRegExpUnits_s2 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_InlineRegExpUnits_s2;
extern int step_M_PG_InlineRegExpUnits_s2(Sink,Term);

/* FUNCTION CookPG-PG-isLeftRecursive1-2$PG-isLeftRecursive1$9$RAW-Repeat HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG__isLeftRecursive1_s9 struct _Con_M_PG__isLeftRecursive1_s9
struct _Con_M_PG__isLeftRecursive1_s9 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG__isLeftRecursive1_s9;
extern int step_M_PG__isLeftRecursive1_s9(Sink,Term);

/* FUNCTION CookPG-PG-isLeftRecursive1- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG__isLeftRecursive1_s6 struct _Con_M_PG__isLeftRecursive1_s6
struct _Con_M_PG__isLeftRecursive1_s6 {struct _Construction construction; Term sub[9]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG__isLeftRecursive1_s6;
extern int step_M_PG__isLeftRecursive1_s6(Sink,Term);

/* FUNCTION CookPG-PG-isLeftRecursive1-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG__isLeftRecursive1_s7 struct _Con_M_PG__isLeftRecursive1_s7
struct _Con_M_PG__isLeftRecursive1_s7 {struct _Construction construction; Term sub[10]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG__isLeftRecursive1_s7;
extern int step_M_PG__isLeftRecursive1_s7(Sink,Term);

/* FUNCTION CookPG-SubRepeat- HEADER DECLARATIONS. */
#define STRUCT_Con_M_SubRepeat struct _Con_M_SubRepeat
struct _Con_M_SubRepeat {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SubRepeat;
extern int step_M_SubRepeat(Sink,Term);

/* FUNCTION CookN-KeepInheritedEntry-1$KeepInheritedEntry$OK HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepInheritedEntry struct _Con_M_KeepInheritedEntry
struct _Con_M_KeepInheritedEntry {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepInheritedEntry;
extern int step_M_KeepInheritedEntry(Sink,Term);

/* FUNCTION CookPG-PG-Productions1-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Productions1_s1 struct _Con_M_PG_Productions1_s1
struct _Con_M_PG_Productions1_s1 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_Productions1_s1;
extern int step_M_PG_Productions1_s1(Sink,Term);

/* FUNCTION CookPG-PG-isLeftRecursive1-2$PG-isLeftRecursive1$1$RAW-ScopeSort HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG__isLeftRecursive1_s1 struct _Con_M_PG__isLeftRecursive1_s1
struct _Con_M_PG__isLeftRecursive1_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG__isLeftRecursive1_s1;
extern int step_M_PG__isLeftRecursive1_s1(Sink,Term);

/* FUNCTION CookPG-PG-Productions1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Productions1_s2 struct _Con_M_PG_Productions1_s2
struct _Con_M_PG_Productions1_s2 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_Productions1_s2;
extern int step_M_PG_Productions1_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-Declarations-Derived-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declarations_Derived_s1 struct _Con_M_CRS_Declarations_Derived_s1
struct _Con_M_CRS_Declarations_Derived_s1 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declarations_Derived_s1;
extern int step_M_CRS_Declarations_Derived_s1(Sink,Term);

/* FUNCTION CookBase-CookError-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CookError struct _Con_M_CookError
struct _Con_M_CookError {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CookError;
extern int step_M_CookError(Sink,Term);

/* FUNCTION CookBase-TermTopSort-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_TermTopSort_s10 struct _Con_M_TermTopSort_s10
struct _Con_M_TermTopSort_s10 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_TermTopSort_s10;
extern int step_M_TermTopSort_s10(Sink,Term);

/* FUNCTION CookPG-PG-isLeftRecursive1-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG__isLeftRecursive1_s4 struct _Con_M_PG__isLeftRecursive1_s4
struct _Con_M_PG__isLeftRecursive1_s4 {struct _Construction construction; Term sub[9]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG__isLeftRecursive1_s4;
extern int step_M_PG__isLeftRecursive1_s4(Sink,Term);

/* FUNCTION CookN-InheritedMapNames-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_InheritedMapNames struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_InheritedMapNames;
extern int step_M_InheritedMapNames(Sink,Term);

/* FUNCTION CookPG-PG-isLeftRecursive1-2$PG-isLeftRecursive1$2$RAW-Sort HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG__isLeftRecursive1_s2 struct _Con_M_PG__isLeftRecursive1_s2
struct _Con_M_PG__isLeftRecursive1_s2 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG__isLeftRecursive1_s2;
extern int step_M_PG__isLeftRecursive1_s2(Sink,Term);

/* FUNCTION CookPG-PG-isLeftRecursive1-2$PG-isLeftRecursive1$3$RAW-Sort HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG__isLeftRecursive1_s3 struct _Con_M_PG__isLeftRecursive1_s3
struct _Con_M_PG__isLeftRecursive1_s3 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG__isLeftRecursive1_s3;
extern int step_M_PG__isLeftRecursive1_s3(Sink,Term);

/* FUNCTION CookPG-PG2-1$PG2$NSM HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG2 struct _Con_M_PG2
struct _Con_M_PG2 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG2;
extern int step_M_PG2(Sink,Term);

/* FUNCTION CookPG-PG1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG1 struct _Con_M_PG1
struct _Con_M_PG1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG1;
extern int step_M_PG1(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-DataSynth-Fold2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_DataSynth_Fold2_s6 struct _Con_M_CRS_Rules_DataSynth_Fold2_s6
struct _Con_M_CRS_Rules_DataSynth_Fold2_s6 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_DataSynth_Fold2_s6;
extern int step_M_CRS_Rules_DataSynth_Fold2_s6(Sink,Term);

/* FUNCTION CookPG-PG3-1$PG3$NSM HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG3 struct _Con_M_PG3
struct _Con_M_PG3 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG3;
extern int step_M_PG3(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-DataSynth-Fold2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_DataSynth_Fold2_s5 struct _Con_M_CRS_Rules_DataSynth_Fold2_s5
struct _Con_M_CRS_Rules_DataSynth_Fold2_s5 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_DataSynth_Fold2_s5;
extern int step_M_CRS_Rules_DataSynth_Fold2_s5(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-DataSynth-Fold2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_DataSynth_Fold2_s1 struct _Con_M_CRS_Rules_DataSynth_Fold2_s1
struct _Con_M_CRS_Rules_DataSynth_Fold2_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_DataSynth_Fold2_s1;
extern int step_M_CRS_Rules_DataSynth_Fold2_s1(Sink,Term);

/* FUNCTION CookBase-AttributeName-1$AttributeName$RAW-Attribute HEADER DECLARATIONS. */
#define STRUCT_Con_M_AttributeName struct _Con_M_AttributeName
struct _Con_M_AttributeName {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_AttributeName;
extern int step_M_AttributeName(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-DataSynth-Fold2-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_DataSynth_Fold2_s4 struct _Con_M_CRS_Rules_DataSynth_Fold2_s4
struct _Con_M_CRS_Rules_DataSynth_Fold2_s4 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_DataSynth_Fold2_s4;
extern int step_M_CRS_Rules_DataSynth_Fold2_s4(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-DataSynth-Fold2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_DataSynth_Fold2_s3 struct _Con_M_CRS_Rules_DataSynth_Fold2_s3
struct _Con_M_CRS_Rules_DataSynth_Fold2_s3 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_DataSynth_Fold2_s3;
extern int step_M_CRS_Rules_DataSynth_Fold2_s3(Sink,Term);

/* FUNCTION CookBase-RegExpLeafSuffix-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_RegExpLeafSuffix_s2 struct _Con_M_RegExpLeafSuffix_s2
struct _Con_M_RegExpLeafSuffix_s2 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RegExpLeafSuffix_s2;
extern int step_M_RegExpLeafSuffix_s2(Sink,Term);

/* FUNCTION CookBase-RegExpLeafSuffix-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_RegExpLeafSuffix_s1 struct _Con_M_RegExpLeafSuffix_s1
struct _Con_M_RegExpLeafSuffix_s1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RegExpLeafSuffix_s1;
extern int step_M_RegExpLeafSuffix_s1(Sink,Term);

/* FUNCTION Prelude-NoNames-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_NoNames struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_NoNames;
extern int step_M_NoNames(Sink,Term);

/* FUNCTION CookCRS-CRS-DefineDataPrint-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_DefineDataPrint struct _Con_M_CRS_DefineDataPrint
struct _Con_M_CRS_DefineDataPrint {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_DefineDataPrint;
extern int step_M_CRS_DefineDataPrint(Sink,Term);

/* FUNCTION Prelude-Drop-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_Drop_s1 struct _Con_M_Drop_s1
struct _Con_M_Drop_s1 {struct _Construction construction; Term sub[2]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M_Drop_s1;
extern int step_M_Drop_s1(Sink,Term);

/* FUNCTION Prelude-Drop-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_Drop_s2 struct _Con_M_Drop_s2
struct _Con_M_Drop_s2 {struct _Construction construction; Term sub[3]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M_Drop_s2;
extern int step_M_Drop_s2(Sink,Term);

/* FUNCTION Prelude-JoinTextMaps2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_JoinTextMaps2_s4 struct _Con_M_JoinTextMaps2_s4
struct _Con_M_JoinTextMaps2_s4 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_JoinTextMaps2_s4;
extern int step_M_JoinTextMaps2_s4(Sink,Term);

/* FUNCTION CookPG-PG-stripLeftRecursion-1$PG-stripLeftRecursion$PFK HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG__stripLeftRecursion struct _Con_M_PG__stripLeftRecursion
struct _Con_M_PG__stripLeftRecursion {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG__stripLeftRecursion;
extern int step_M_PG__stripLeftRecursion(Sink,Term);

/* FUNCTION Prelude-JoinTextMaps2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_JoinTextMaps2_s3 struct _Con_M_JoinTextMaps2_s3
struct _Con_M_JoinTextMaps2_s3 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_JoinTextMaps2_s3;
extern int step_M_JoinTextMaps2_s3(Sink,Term);

/* FUNCTION Prelude-JoinTextMaps2-2$JoinTextMaps2$2$TEXT_MAP HEADER DECLARATIONS. */
#define STRUCT_Con_M_JoinTextMaps2_s2 struct _Con_M_JoinTextMaps2_s2
struct _Con_M_JoinTextMaps2_s2 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_JoinTextMaps2_s2;
extern int step_M_JoinTextMaps2_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-Declarations1- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declarations1 struct _Con_M_CRS_Declarations1
struct _Con_M_CRS_Declarations1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declarations1;
extern int step_M_CRS_Declarations1(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Rule-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Rule_s1 struct _Con_M_DerivedSorts_Rule_s1
struct _Con_M_DerivedSorts_Rule_s1 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Rule_s1;
extern int step_M_DerivedSorts_Rule_s1(Sink,Term);

/* FUNCTION Prelude-RemoveName-1$RemoveName$NAME_SET HEADER DECLARATIONS. */
#define STRUCT_Con_M_RemoveName struct _Con_M_RemoveName
struct _Con_M_RemoveName {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RemoveName;
extern int step_M_RemoveName(Sink,Term);

/* FUNCTION CookCRS-FormPrec-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_FormPrec_s1 struct _Con_M_FormPrec_s1
struct _Con_M_FormPrec_s1 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_FormPrec_s1;
extern int step_M_FormPrec_s1(Sink,Term);

/* FUNCTION CookCRS-FormPrec-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_FormPrec_s2 struct _Con_M_FormPrec_s2
struct _Con_M_FormPrec_s2 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_FormPrec_s2;
extern int step_M_FormPrec_s2(Sink,Term);

/* FUNCTION CookCRS-FormPrec-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_FormPrec_s3 struct _Con_M_FormPrec_s3
struct _Con_M_FormPrec_s3 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_FormPrec_s3;
extern int step_M_FormPrec_s3(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBody-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBody struct _Con_M_PG_ProduceBody
struct _Con_M_PG_ProduceBody {struct _Construction construction; Term sub[6]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBody;
extern int step_M_PG_ProduceBody(Sink,Term);

/* FUNCTION Prelude-FoldWhen- HEADER DECLARATIONS. */
#define STRUCT_Con_M_FoldWhen_s1 struct _Con_M_FoldWhen_s1
struct _Con_M_FoldWhen_s1 {struct _Construction construction; Term sub[3]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M_FoldWhen_s1;
extern int step_M_FoldWhen_s1(Sink,Term);

/* FUNCTION CookN-_ParsedFormLess- HEADER DECLARATIONS. */
#define STRUCT_Con_M__xParsedFormLess struct _Con_M__xParsedFormLess
struct _Con_M__xParsedFormLess {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xParsedFormLess;
extern int step_M__xParsedFormLess(Sink,Term);

/* FUNCTION CookBase-BaseSortName-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_BaseSortName struct _Con_M_BaseSortName
struct _Con_M_BaseSortName {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_BaseSortName;
extern int step_M_BaseSortName(Sink,Term);

/* FUNCTION Prelude-FoldWhen-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_FoldWhen_s2 struct _Con_M_FoldWhen_s2
struct _Con_M_FoldWhen_s2 {struct _Construction construction; Term sub[4]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M_FoldWhen_s2;
extern int step_M_FoldWhen_s2(Sink,Term);

/* FUNCTION Prelude-FoldWhen-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_FoldWhen_s3 struct _Con_M_FoldWhen_s3
struct _Con_M_FoldWhen_s3 {struct _Construction construction; Term sub[2]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M_FoldWhen_s3;
extern int step_M_FoldWhen_s3(Sink,Term);

/* FUNCTION CookCRS-CRS-Form-PatternEnv1- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Form_PatternEnv1 struct _Con_M_CRS_Form_PatternEnv1
struct _Con_M_CRS_Form_PatternEnv1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Form_PatternEnv1;
extern int step_M_CRS_Form_PatternEnv1(Sink,Term);

/* FUNCTION CookCRS-CRS-Form-PatternEnv2-2$CRS-Form-PatternEnv2$SE_ATTRIBUTE HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Form_PatternEnv2 struct _Con_M_CRS_Form_PatternEnv2
struct _Con_M_CRS_Form_PatternEnv2 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Form_PatternEnv2;
extern int step_M_CRS_Form_PatternEnv2(Sink,Term);

/* FUNCTION Prelude-Special_message-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_Special_xmessage struct _Con_M_Special_xmessage
struct _Con_M_Special_xmessage {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_Special_xmessage;
extern int step_M_Special_xmessage(Sink,Term);

/* FUNCTION Prelude-SingletonTextMap-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SingletonTextMap struct _Con_M_SingletonTextMap
struct _Con_M_SingletonTextMap {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SingletonTextMap;
extern int step_M_SingletonTextMap(Sink,Term);

/* FUNCTION CookCRS-CRS-Declarations-Defines-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declarations_Defines_s2 struct _Con_M_CRS_Declarations_Defines_s2
struct _Con_M_CRS_Declarations_Defines_s2 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declarations_Defines_s2;
extern int step_M_CRS_Declarations_Defines_s2(Sink,Term);

/* FUNCTION Prelude-MapWhen- HEADER DECLARATIONS. */
#define STRUCT_Con_M_MapWhen_s1 struct _Con_M_MapWhen_s1
struct _Con_M_MapWhen_s1 {struct _Construction construction; Term sub[2]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_MapWhen_s1;
extern int step_M_MapWhen_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-Declarations-Defines-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declarations_Defines_s1 struct _Con_M_CRS_Declarations_Defines_s1
struct _Con_M_CRS_Declarations_Defines_s1 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declarations_Defines_s1;
extern int step_M_CRS_Declarations_Defines_s1(Sink,Term);

/* FUNCTION Prelude-MapWhen-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_MapWhen_s3 struct _Con_M_MapWhen_s3
struct _Con_M_MapWhen_s3 {struct _Construction construction; Term sub[1]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_MapWhen_s3;
extern int step_M_MapWhen_s3(Sink,Term);

/* FUNCTION Prelude-MapWhen-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_MapWhen_s2 struct _Con_M_MapWhen_s2
struct _Con_M_MapWhen_s2 {struct _Construction construction; Term sub[3]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_MapWhen_s2;
extern int step_M_MapWhen_s2(Sink,Term);

/* FUNCTION CookPG-PG-InlineRegExp2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_InlineRegExp2_s1 struct _Con_M_PG_InlineRegExp2_s1
struct _Con_M_PG_InlineRegExp2_s1 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_InlineRegExp2_s1;
extern int step_M_PG_InlineRegExp2_s1(Sink,Term);

/* FUNCTION CookBase-MakeLocation2-1$MakeLocation2$STRING HEADER DECLARATIONS. */
#define STRUCT_Con_M_MakeLocation2 struct _Con_M_MakeLocation2
struct _Con_M_MakeLocation2 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_MakeLocation2;
extern int step_M_MakeLocation2(Sink,Term);

/* FUNCTION CookPG-PG-InlineRegExp-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_InlineRegExp_s1 struct _Con_M_PG_InlineRegExp_s1
struct _Con_M_PG_InlineRegExp_s1 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_InlineRegExp_s1;
extern int step_M_PG_InlineRegExp_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-Declarations-Synthesized-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declarations_Synthesized_s1 struct _Con_M_CRS_Declarations_Synthesized_s1
struct _Con_M_CRS_Declarations_Synthesized_s1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declarations_Synthesized_s1;
extern int step_M_CRS_Declarations_Synthesized_s1(Sink,Term);

/* FUNCTION CookPG-PG-stripLeftRecursion-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG__stripLeftRecursion_s12 struct _Con_M_PG__stripLeftRecursion_s12
struct _Con_M_PG__stripLeftRecursion_s12 {struct _Construction construction; Term sub[11]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG__stripLeftRecursion_s12;
extern int step_M_PG__stripLeftRecursion_s12(Sink,Term);

/* FUNCTION CookPG-PG-stripLeftRecursion-2$PG-stripLeftRecursion$11$$Nil HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG__stripLeftRecursion_s11 struct _Con_M_PG__stripLeftRecursion_s11
struct _Con_M_PG__stripLeftRecursion_s11 {struct _Construction construction; Term sub[12]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG__stripLeftRecursion_s11;
extern int step_M_PG__stripLeftRecursion_s11(Sink,Term);

/* FUNCTION CookN-AttributeValueSortName-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_AttributeValueSortName struct _Con_M_AttributeValueSortName
struct _Con_M_AttributeValueSortName {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_AttributeValueSortName;
extern int step_M_AttributeValueSortName(Sink,Term);

/* FUNCTION CookPG-PG-InlineRegExp2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_InlineRegExp2_s2 struct _Con_M_PG_InlineRegExp2_s2
struct _Con_M_PG_InlineRegExp2_s2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_InlineRegExp2_s2;
extern int step_M_PG_InlineRegExp2_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-ScopeBinderSort2-2$CRS-ScopeBinderSort2$1$RAW-SubstituteSort HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_ScopeBinderSort2_s1 struct _Con_M_CRS_ScopeBinderSort2_s1
struct _Con_M_CRS_ScopeBinderSort2_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_ScopeBinderSort2_s1;
extern int step_M_CRS_ScopeBinderSort2_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-ScopeBinderSort2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_ScopeBinderSort2_s2 struct _Con_M_CRS_ScopeBinderSort2_s2
struct _Con_M_CRS_ScopeBinderSort2_s2 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_ScopeBinderSort2_s2;
extern int step_M_CRS_ScopeBinderSort2_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-ScopeBinderSort2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_ScopeBinderSort2_s3 struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_CRS_ScopeBinderSort2_s3;
extern int step_M_CRS_ScopeBinderSort2_s3(Sink,Term);

/* FUNCTION CookN-DerivedSorts-ParsedForm- HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_ParsedForm struct _Con_M_DerivedSorts_ParsedForm
struct _Con_M_DerivedSorts_ParsedForm {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_ParsedForm;
extern int step_M_DerivedSorts_ParsedForm(Sink,Term);

/* FUNCTION CookCRS-CRS-AddAttributes- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AddAttributes_s2 struct _Con_M_CRS_AddAttributes_s2
struct _Con_M_CRS_AddAttributes_s2 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AddAttributes_s2;
extern int step_M_CRS_AddAttributes_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-AddAttributes- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AddAttributes_s4 struct _Con_M_CRS_AddAttributes_s4
struct _Con_M_CRS_AddAttributes_s4 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AddAttributes_s4;
extern int step_M_CRS_AddAttributes_s4(Sink,Term);

/* FUNCTION CookPG-PG-InlineRegExp-1$PG-InlineRegExp$RegExp$Cons HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_InlineRegExp struct _Con_M_PG_InlineRegExp
struct _Con_M_PG_InlineRegExp {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_InlineRegExp;
extern int step_M_PG_InlineRegExp(Sink,Term);

/* FUNCTION CookCRS-CRS-AddAttributes-3$CRS-AddAttributes$3$RAW-Attribute HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AddAttributes_s3 struct _Con_M_CRS_AddAttributes_s3
struct _Con_M_CRS_AddAttributes_s3 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AddAttributes_s3;
extern int step_M_CRS_AddAttributes_s3(Sink,Term);

/* FUNCTION CookCRS-_Hashs-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xHashs struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M__xHashs;
extern int step_M__xHashs(Sink,Term);

/* FUNCTION CookCRS-CRS-AddAttributes-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AddAttributes_s7 struct _Con_M_CRS_AddAttributes_s7
struct _Con_M_CRS_AddAttributes_s7 {struct _Construction construction; Term sub[9]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AddAttributes_s7;
extern int step_M_CRS_AddAttributes_s7(Sink,Term);

/* FUNCTION CookBase-IfSingletonRepeat-5 HEADER DECLARATIONS. */
#define STRUCT_Con_M_IfSingletonRepeat_s5 struct _Con_M_IfSingletonRepeat_s5
struct _Con_M_IfSingletonRepeat_s5 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_IfSingletonRepeat_s5;
extern int step_M_IfSingletonRepeat_s5(Sink,Term);

/* FUNCTION CookCRS-CRS-AddAttributes-6 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AddAttributes_s8 struct _Con_M_CRS_AddAttributes_s8
struct _Con_M_CRS_AddAttributes_s8 {struct _Construction construction; Term sub[10]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AddAttributes_s8;
extern int step_M_CRS_AddAttributes_s8(Sink,Term);

/* FUNCTION CookBase-IfSingletonRepeat-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_IfSingletonRepeat_s3 struct _Con_M_IfSingletonRepeat_s3
struct _Con_M_IfSingletonRepeat_s3 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_IfSingletonRepeat_s3;
extern int step_M_IfSingletonRepeat_s3(Sink,Term);

/* FUNCTION CookCRS-CRS-AddAttributes- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AddAttributes_s6 struct _Con_M_CRS_AddAttributes_s6
struct _Con_M_CRS_AddAttributes_s6 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AddAttributes_s6;
extern int step_M_CRS_AddAttributes_s6(Sink,Term);

/* FUNCTION CookBase-IfSingletonRepeat-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_IfSingletonRepeat_s4 struct _Con_M_IfSingletonRepeat_s4
struct _Con_M_IfSingletonRepeat_s4 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_IfSingletonRepeat_s4;
extern int step_M_IfSingletonRepeat_s4(Sink,Term);

/* FUNCTION CookCRS-CRS-Term-Form- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Term_Form struct _Con_M_CRS_Term_Form
struct _Con_M_CRS_Term_Form {struct _Construction construction; Term sub[7]; Variable binder[5];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Term_Form;
extern int step_M_CRS_Term_Form(Sink,Term);

/* FUNCTION CookCRS-CRS-AddAttributes-8 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AddAttributes_s9 struct _Con_M_CRS_AddAttributes_s9
struct _Con_M_CRS_AddAttributes_s9 {struct _Construction construction; Term sub[9]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AddAttributes_s9;
extern int step_M_CRS_AddAttributes_s9(Sink,Term);

/* FUNCTION CookCRS-CRS-TermConstruction3-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_TermConstruction3_s13 struct _Con_M_CRS_TermConstruction3_s13
struct _Con_M_CRS_TermConstruction3_s13 {struct _Construction construction; Term sub[5]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_TermConstruction3_s13;
extern int step_M_CRS_TermConstruction3_s13(Sink,Term);

/* FUNCTION CookCRS-CRS-TermConstruction3-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_TermConstruction3_s12 struct _Con_M_CRS_TermConstruction3_s12
struct _Con_M_CRS_TermConstruction3_s12 {struct _Construction construction; Term sub[7]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_TermConstruction3_s12;
extern int step_M_CRS_TermConstruction3_s12(Sink,Term);

/* FUNCTION CookCRS-CRS-TermConstruction3- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_TermConstruction3_s11 struct _Con_M_CRS_TermConstruction3_s11
struct _Con_M_CRS_TermConstruction3_s11 {struct _Construction construction; Term sub[6]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_TermConstruction3_s11;
extern int step_M_CRS_TermConstruction3_s11(Sink,Term);

/* FUNCTION CookCRS-CRS-TermConstruction3-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_TermConstruction3_s10 struct _Con_M_CRS_TermConstruction3_s10
struct _Con_M_CRS_TermConstruction3_s10 {struct _Construction construction; Term sub[5]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_TermConstruction3_s10;
extern int step_M_CRS_TermConstruction3_s10(Sink,Term);

/* FUNCTION Prelude-TextLookup-1$TextLookup$OK HEADER DECLARATIONS. */
#define STRUCT_Con_M_TextLookup struct _Con_M_TextLookup
struct _Con_M_TextLookup {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_TextLookup;
extern int step_M_TextLookup(Sink,Term);

/* FUNCTION CookBase-IfSingletonRepeat-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_IfSingletonRepeat_s1 struct _Con_M_IfSingletonRepeat_s1
struct _Con_M_IfSingletonRepeat_s1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_IfSingletonRepeat_s1;
extern int step_M_IfSingletonRepeat_s1(Sink,Term);

/* FUNCTION CookN-_DefineLessEqual2- HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefineLessEqual2 struct _Con_M__xDefineLessEqual2
struct _Con_M__xDefineLessEqual2 {struct _Construction construction; Term sub[1]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M__xDefineLessEqual2;
extern int step_M__xDefineLessEqual2(Sink,Term);

/* FUNCTION CookBase-IfSingletonRepeat-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_IfSingletonRepeat_s2 struct _Con_M_IfSingletonRepeat_s2
struct _Con_M_IfSingletonRepeat_s2 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_IfSingletonRepeat_s2;
extern int step_M_IfSingletonRepeat_s2(Sink,Term);

/* FUNCTION CookCRS-InheritedName-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_InheritedName struct _Con_M_InheritedName
struct _Con_M_InheritedName {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_InheritedName;
extern int step_M_InheritedName(Sink,Term);

/* FUNCTION CookPG-PG-Production-Defines- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Production_Defines_s1 struct _Con_M_PG_Production_Defines_s1
struct _Con_M_PG_Production_Defines_s1 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_Production_Defines_s1;
extern int step_M_PG_Production_Defines_s1(Sink,Term);

/* FUNCTION CookPG-PG-Production-Defines-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Production_Defines_s7 struct _Con_M_PG_Production_Defines_s7
struct _Con_M_PG_Production_Defines_s7 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_Production_Defines_s7;
extern int step_M_PG_Production_Defines_s7(Sink,Term);

/* FUNCTION CookPG-PG-Production-Defines- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Production_Defines_s6 struct _Con_M_PG_Production_Defines_s6
struct _Con_M_PG_Production_Defines_s6 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_Production_Defines_s6;
extern int step_M_PG_Production_Defines_s6(Sink,Term);

/* FUNCTION CookPG-PG-Production-Defines-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Production_Defines_s8 struct _Con_M_PG_Production_Defines_s8
struct _Con_M_PG_Production_Defines_s8 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_Production_Defines_s8;
extern int step_M_PG_Production_Defines_s8(Sink,Term);

/* FUNCTION CookPG-PG-Production-Defines-5 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Production_Defines_s3 struct _Con_M_PG_Production_Defines_s3
struct _Con_M_PG_Production_Defines_s3 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_Production_Defines_s3;
extern int step_M_PG_Production_Defines_s3(Sink,Term);

/* FUNCTION CookPG-PG-Production-Defines-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Production_Defines_s2 struct _Con_M_PG_Production_Defines_s2
struct _Con_M_PG_Production_Defines_s2 {struct _Construction construction; Term sub[6]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M_PG_Production_Defines_s2;
extern int step_M_PG_Production_Defines_s2(Sink,Term);

/* FUNCTION CookPG-PG-InlineRegExpClass2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_InlineRegExpClass2_s1 struct _Con_M_PG_InlineRegExpClass2_s1
struct _Con_M_PG_InlineRegExpClass2_s1 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_InlineRegExpClass2_s1;
extern int step_M_PG_InlineRegExpClass2_s1(Sink,Term);

/* FUNCTION CookPG-PG-Production-Defines-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Production_Defines_s4 struct _Con_M_PG_Production_Defines_s4
struct _Con_M_PG_Production_Defines_s4 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_Production_Defines_s4;
extern int step_M_PG_Production_Defines_s4(Sink,Term);

/* FUNCTION CookCRS-CRS-Attributes4-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Attributes4_s4 struct _Con_M_CRS_Attributes4_s4
struct _Con_M_CRS_Attributes4_s4 {struct _Construction construction; Term sub[4]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Attributes4_s4;
extern int step_M_CRS_Attributes4_s4(Sink,Term);

/* FUNCTION CookCRS-CRS-AttributeGroups- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AttributeGroups struct _Con_M_CRS_AttributeGroups
struct _Con_M_CRS_AttributeGroups {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AttributeGroups;
extern int step_M_CRS_AttributeGroups(Sink,Term);

/* FUNCTION CookCRS-CRS-Attributes4-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Attributes4_s3 struct _Con_M_CRS_Attributes4_s3
struct _Con_M_CRS_Attributes4_s3 {struct _Construction construction; Term sub[6]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Attributes4_s3;
extern int step_M_CRS_Attributes4_s3(Sink,Term);

/* FUNCTION CookCRS-CRS-Attributes4-2$CRS-Attributes4$2$AM HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Attributes4_s2 struct _Con_M_CRS_Attributes4_s2
struct _Con_M_CRS_Attributes4_s2 {struct _Construction construction; Term sub[6]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Attributes4_s2;
extern int step_M_CRS_Attributes4_s2(Sink,Term);

/* FUNCTION CookN-KeepSynthesizedMapEntry-1$KeepSynthesizedMapEntry$OK HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepSynthesizedMapEntry struct _Con_M_KeepSynthesizedMapEntry
struct _Con_M_KeepSynthesizedMapEntry {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepSynthesizedMapEntry;
extern int step_M_KeepSynthesizedMapEntry(Sink,Term);

/* FUNCTION CookN-_DefineWrapper- HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefineWrapper_s2 struct _Con_M__xDefineWrapper_s2
struct _Con_M__xDefineWrapper_s2 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xDefineWrapper_s2;
extern int step_M__xDefineWrapper_s2(Sink,Term);

/* FUNCTION CookN-_DefineWrapper-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefineWrapper_s1 struct _Con_M__xDefineWrapper_s1
struct _Con_M__xDefineWrapper_s1 {struct _Construction construction; Term sub[4]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M__xDefineWrapper_s1;
extern int step_M__xDefineWrapper_s1(Sink,Term);

/* FUNCTION CookN-_DefineWrapper-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefineWrapper_s4 struct _Con_M__xDefineWrapper_s4
struct _Con_M__xDefineWrapper_s4 {struct _Construction construction; Term sub[9]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xDefineWrapper_s4;
extern int step_M__xDefineWrapper_s4(Sink,Term);

/* FUNCTION CookPG-PG-AttributeCollection-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_AttributeCollection_s3 struct _Con_M_PG_AttributeCollection_s3
struct _Con_M_PG_AttributeCollection_s3 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_AttributeCollection_s3;
extern int step_M_PG_AttributeCollection_s3(Sink,Term);

/* FUNCTION CookN-_DefineWrapper-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefineWrapper_s3 struct _Con_M__xDefineWrapper_s3
struct _Con_M__xDefineWrapper_s3 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xDefineWrapper_s3;
extern int step_M__xDefineWrapper_s3(Sink,Term);

/* FUNCTION CookPG-PG-AttributeCollection-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_AttributeCollection_s2 struct _Con_M_PG_AttributeCollection_s2
struct _Con_M_PG_AttributeCollection_s2 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_AttributeCollection_s2;
extern int step_M_PG_AttributeCollection_s2(Sink,Term);

/* FUNCTION CookN-_DefineWrapper-5 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefineWrapper_s6 struct _Con_M__xDefineWrapper_s6
struct _Con_M__xDefineWrapper_s6 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xDefineWrapper_s6;
extern int step_M__xDefineWrapper_s6(Sink,Term);

/* FUNCTION CookPG-PG-AttributeCollection- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_AttributeCollection_s1 struct _Con_M_PG_AttributeCollection_s1
struct _Con_M_PG_AttributeCollection_s1 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_AttributeCollection_s1;
extern int step_M_PG_AttributeCollection_s1(Sink,Term);

/* FUNCTION CookN-_DefineWrapper-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefineWrapper_s5 struct _Con_M__xDefineWrapper_s5
struct _Con_M__xDefineWrapper_s5 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xDefineWrapper_s5;
extern int step_M__xDefineWrapper_s5(Sink,Term);

/* FUNCTION CookCRS-SetInheritedName-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SetInheritedName struct _Con_M_SetInheritedName
struct _Con_M_SetInheritedName {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SetInheritedName;
extern int step_M_SetInheritedName(Sink,Term);

/* FUNCTION CookCRS-CRS-Declarations-Defines- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declarations_Defines struct _Con_M_CRS_Declarations_Defines
struct _Con_M_CRS_Declarations_Defines {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declarations_Defines;
extern int step_M_CRS_Declarations_Defines(Sink,Term);

/* FUNCTION CookCRS-CRS-ScopeBinderSort1- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_ScopeBinderSort1 struct _Con_M_CRS_ScopeBinderSort1
struct _Con_M_CRS_ScopeBinderSort1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_ScopeBinderSort1;
extern int step_M_CRS_ScopeBinderSort1(Sink,Term);

/* FUNCTION CookCRS-CRS-ScopeBinderSort2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_ScopeBinderSort2 struct _Con_M_CRS_ScopeBinderSort2
struct _Con_M_CRS_ScopeBinderSort2 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_ScopeBinderSort2;
extern int step_M_CRS_ScopeBinderSort2(Sink,Term);

/* FUNCTION Prelude-AddName-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_AddName_s1 struct _Con_M_AddName_s1
struct _Con_M_AddName_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_AddName_s1;
extern int step_M_AddName_s1(Sink,Term);

/* FUNCTION CookPG-PG-Lexical-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Lexical struct _Con_M_PG_Lexical
struct _Con_M_PG_Lexical {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_Lexical;
extern int step_M_PG_Lexical(Sink,Term);

/* FUNCTION CookN-Resolve HEADER DECLARATIONS. */
#define STRUCT_Con_M_N__resolve_s2 struct _Con_M_N__resolve_s2
struct _Con_M_N__resolve_s2 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N__resolve_s2;
extern int step_M_N__resolve_s2(Sink,Term);

/* FUNCTION CookN-ResolveDone HEADER DECLARATIONS. */
#define STRUCT_Con_M_N__resolve_s1 struct _Con_M_N__resolve_s1
struct _Con_M_N__resolve_s1 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N__resolve_s1;
extern int step_M_N__resolve_s1(Sink,Term);

/* FUNCTION CookCRS-SortSynthesizes2-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortSynthesizes2_s1 struct _Con_M_SortSynthesizes2_s1
struct _Con_M_SortSynthesizes2_s1 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortSynthesizes2_s1;
extern int step_M_SortSynthesizes2_s1(Sink,Term);

/* FUNCTION CookBase-SortName-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortName struct _Con_M_SortName
struct _Con_M_SortName {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortName;
extern int step_M_SortName(Sink,Term);

/* FUNCTION CookN-Resolve-Module HEADER DECLARATIONS. */
#define STRUCT_Con_M_N__resolve_s6 struct _Con_M_N__resolve_s6
struct _Con_M_N__resolve_s6 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N__resolve_s6;
extern int step_M_N__resolve_s6(Sink,Term);

/* FUNCTION CookCRS-SortSynthesizes2-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortSynthesizes2_s2 struct _Con_M_SortSynthesizes2_s2
struct _Con_M_SortSynthesizes2_s2 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortSynthesizes2_s2;
extern int step_M_SortSynthesizes2_s2(Sink,Term);

/* FUNCTION CookN-Resolve-Module$N-resolve$5$RAW-module HEADER DECLARATIONS. */
#define STRUCT_Con_M_N__resolve_s5 struct _Con_M_N__resolve_s5
struct _Con_M_N__resolve_s5 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N__resolve_s5;
extern int step_M_N__resolve_s5(Sink,Term);

/* FUNCTION CookCRS-SortSynthesizes2-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortSynthesizes2_s3 struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_SortSynthesizes2_s3;
extern int step_M_SortSynthesizes2_s3(Sink,Term);

/* FUNCTION CookN-Resolve-Attribute HEADER DECLARATIONS. */
#define STRUCT_Con_M_N__resolve_s4 struct _Con_M_N__resolve_s4
struct _Con_M_N__resolve_s4 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N__resolve_s4;
extern int step_M_N__resolve_s4(Sink,Term);

/* FUNCTION CookCRS-SortSynthesizes2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortSynthesizes2_s4 struct _Con_M_SortSynthesizes2_s4
struct _Con_M_SortSynthesizes2_s4 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortSynthesizes2_s4;
extern int step_M_SortSynthesizes2_s4(Sink,Term);

/* FUNCTION CookN-Resolve-NakedAlternative HEADER DECLARATIONS. */
#define STRUCT_Con_M_N__resolve_s3 struct _Con_M_N__resolve_s3
struct _Con_M_N__resolve_s3 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N__resolve_s3;
extern int step_M_N__resolve_s3(Sink,Term);

/* FUNCTION CookCRS-SortSynthesizes2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortSynthesizes2_s5 struct _Con_M_SortSynthesizes2_s5
struct _Con_M_SortSynthesizes2_s5 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortSynthesizes2_s5;
extern int step_M_SortSynthesizes2_s5(Sink,Term);

/* FUNCTION Prelude-TextLookup-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_TextLookup_s1 struct _Con_M_TextLookup_s1
struct _Con_M_TextLookup_s1 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_TextLookup_s1;
extern int step_M_TextLookup_s1(Sink,Term);

/* FUNCTION CookN-N-Finish3-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_Finish3_s4 struct _Con_M_N_Finish3_s4
struct _Con_M_N_Finish3_s4 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_Finish3_s4;
extern int step_M_N_Finish3_s4(Sink,Term);

/* FUNCTION CookN-N-Finish3-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_Finish3_s3 struct _Con_M_N_Finish3_s3
struct _Con_M_N_Finish3_s3 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_Finish3_s3;
extern int step_M_N_Finish3_s3(Sink,Term);

/* FUNCTION CookN-N-Finish3-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_Finish3_s1 struct _Con_M_N_Finish3_s1
struct _Con_M_N_Finish3_s1 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_Finish3_s1;
extern int step_M_N_Finish3_s1(Sink,Term);

/* FUNCTION CookN-N-Finish3-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_Finish3_s2 struct _Con_M_N_Finish3_s2
struct _Con_M_N_Finish3_s2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_Finish3_s2;
extern int step_M_N_Finish3_s2(Sink,Term);

/* FUNCTION CookBase-SortRepeatString2-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortRepeatString2_s5 struct _Con_M_SortRepeatString2_s5
struct _Con_M_SortRepeatString2_s5 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortRepeatString2_s5;
extern int step_M_SortRepeatString2_s5(Sink,Term);

/* FUNCTION CookN-N-Finish5-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_Finish5_s1 struct _Con_M_N_Finish5_s1
struct _Con_M_N_Finish5_s1 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_Finish5_s1;
extern int step_M_N_Finish5_s1(Sink,Term);

/* FUNCTION CookBase-SortRepeatString2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortRepeatString2_s4 struct _Con_M_SortRepeatString2_s4
struct _Con_M_SortRepeatString2_s4 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortRepeatString2_s4;
extern int step_M_SortRepeatString2_s4(Sink,Term);

/* FUNCTION CookN-N-Finish5-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_Finish5_s2 struct _Con_M_N_Finish5_s2
struct _Con_M_N_Finish5_s2 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_Finish5_s2;
extern int step_M_N_Finish5_s2(Sink,Term);

/* FUNCTION CookBase-SortRepeatString2-5 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortRepeatString2_s6 struct _Con_M_SortRepeatString2_s6
struct _Con_M_SortRepeatString2_s6 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortRepeatString2_s6;
extern int step_M_SortRepeatString2_s6(Sink,Term);

/* FUNCTION CookBase-SortRepeatString2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortRepeatString2_s1 struct _Con_M_SortRepeatString2_s1
struct _Con_M_SortRepeatString2_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortRepeatString2_s1;
extern int step_M_SortRepeatString2_s1(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Repeat-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Repeat_s6 struct _Con_M_DerivedSorts_Repeat_s6
struct _Con_M_DerivedSorts_Repeat_s6 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Repeat_s6;
extern int step_M_DerivedSorts_Repeat_s6(Sink,Term);

/* FUNCTION CookBase-SortRepeatString2-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortRepeatString2_s3 struct _Con_M_SortRepeatString2_s3
struct _Con_M_SortRepeatString2_s3 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortRepeatString2_s3;
extern int step_M_SortRepeatString2_s3(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Repeat-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Repeat_s4 struct _Con_M_DerivedSorts_Repeat_s4
struct _Con_M_DerivedSorts_Repeat_s4 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Repeat_s4;
extern int step_M_DerivedSorts_Repeat_s4(Sink,Term);

/* FUNCTION CookBase-SortRepeatString2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortRepeatString2_s2 struct _Con_M_SortRepeatString2_s2
struct _Con_M_SortRepeatString2_s2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortRepeatString2_s2;
extern int step_M_SortRepeatString2_s2(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Repeat-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Repeat_s5 struct _Con_M_DerivedSorts_Repeat_s5
struct _Con_M_DerivedSorts_Repeat_s5 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Repeat_s5;
extern int step_M_DerivedSorts_Repeat_s5(Sink,Term);

/* FUNCTION CookN-_FormLess- HEADER DECLARATIONS. */
#define STRUCT_Con_M__xFormLess struct _Con_M__xFormLess
struct _Con_M__xFormLess {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xFormLess;
extern int step_M__xFormLess(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-TokenSynth-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_TokenSynth_s1 struct _Con_M_CRS_Rules_TokenSynth_s1
struct _Con_M_CRS_Rules_TokenSynth_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_TokenSynth_s1;
extern int step_M_CRS_Rules_TokenSynth_s1(Sink,Term);

/* FUNCTION CookPG-Lex HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Lexical2 struct _Con_M_PG_Lexical2
struct _Con_M_PG_Lexical2 {struct _Construction construction; Term sub[3]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M_PG_Lexical2;
extern int step_M_PG_Lexical2(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Repeat- HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Repeat_s1 struct _Con_M_DerivedSorts_Repeat_s1
struct _Con_M_DerivedSorts_Repeat_s1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Repeat_s1;
extern int step_M_DerivedSorts_Repeat_s1(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Repeat-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Repeat_s3 struct _Con_M_DerivedSorts_Repeat_s3
struct _Con_M_DerivedSorts_Repeat_s3 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Repeat_s3;
extern int step_M_DerivedSorts_Repeat_s3(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Repeat-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Repeat_s2 struct _Con_M_DerivedSorts_Repeat_s2
struct _Con_M_DerivedSorts_Repeat_s2 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Repeat_s2;
extern int step_M_DerivedSorts_Repeat_s2(Sink,Term);

/* FUNCTION CookCRS-SetSynthesizedName-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SetSynthesizedName struct _Con_M_SetSynthesizedName
struct _Con_M_SetSynthesizedName {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SetSynthesizedName;
extern int step_M_SetSynthesizedName(Sink,Term);

/* FUNCTION CookN-N-SortAlternativeDefine-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_SortAlternativeDefine_s3 struct _Con_M_N_SortAlternativeDefine_s3
struct _Con_M_N_SortAlternativeDefine_s3 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_SortAlternativeDefine_s3;
extern int step_M_N_SortAlternativeDefine_s3(Sink,Term);

/* FUNCTION CookN-N-SortAlternativeDefine-5 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_SortAlternativeDefine_s4 struct _Con_M_N_SortAlternativeDefine_s4
struct _Con_M_N_SortAlternativeDefine_s4 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_SortAlternativeDefine_s4;
extern int step_M_N_SortAlternativeDefine_s4(Sink,Term);

/* FUNCTION CookN-N-SortAlternativeDefine-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_SortAlternativeDefine_s1 struct _Con_M_N_SortAlternativeDefine_s1
struct _Con_M_N_SortAlternativeDefine_s1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_SortAlternativeDefine_s1;
extern int step_M_N_SortAlternativeDefine_s1(Sink,Term);

/* FUNCTION CookN-N-SortAlternativeDefine-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_SortAlternativeDefine_s2 struct _Con_M_N_SortAlternativeDefine_s2
struct _Con_M_N_SortAlternativeDefine_s2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_SortAlternativeDefine_s2;
extern int step_M_N_SortAlternativeDefine_s2(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Sort2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Sort2_s1 struct _Con_M_DerivedSorts_Sort2_s1
struct _Con_M_DerivedSorts_Sort2_s1 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Sort2_s1;
extern int step_M_DerivedSorts_Sort2_s1(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Sort2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Sort2_s2 struct _Con_M_DerivedSorts_Sort2_s2
struct _Con_M_DerivedSorts_Sort2_s2 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Sort2_s2;
extern int step_M_DerivedSorts_Sort2_s2(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Sort2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Sort2_s3 struct _Con_M_DerivedSorts_Sort2_s3
struct _Con_M_DerivedSorts_Sort2_s3 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Sort2_s3;
extern int step_M_DerivedSorts_Sort2_s3(Sink,Term);

/* FUNCTION CookN-N-SortAlternativeDefine-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_SortAlternativeDefine_s5 struct _Con_M_N_SortAlternativeDefine_s5
struct _Con_M_N_SortAlternativeDefine_s5 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_SortAlternativeDefine_s5;
extern int step_M_N_SortAlternativeDefine_s5(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Sort2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Sort2_s4 struct _Con_M_DerivedSorts_Sort2_s4
struct _Con_M_DerivedSorts_Sort2_s4 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Sort2_s4;
extern int step_M_DerivedSorts_Sort2_s4(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Sort2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Sort2_s5 struct _Con_M_DerivedSorts_Sort2_s5
struct _Con_M_DerivedSorts_Sort2_s5 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Sort2_s5;
extern int step_M_DerivedSorts_Sort2_s5(Sink,Term);

/* FUNCTION CookCRS-CRS-MetaDeclaration-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_MetaDeclaration struct _Con_M_CRS_MetaDeclaration
struct _Con_M_CRS_MetaDeclaration {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_MetaDeclaration;
extern int step_M_CRS_MetaDeclaration(Sink,Term);

/* FUNCTION Prelude-ThenAsText-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ThenAsText_s1 struct _Con_M_ThenAsText_s1
struct _Con_M_ThenAsText_s1 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ThenAsText_s1;
extern int step_M_ThenAsText_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-DataSynth-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_DataSynth_s1 struct _Con_M_CRS_Rules_DataSynth_s1
struct _Con_M_CRS_Rules_DataSynth_s1 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_DataSynth_s1;
extern int step_M_CRS_Rules_DataSynth_s1(Sink,Term);

/* FUNCTION CookPG-PG-InlineRegExpClass2-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_InlineRegExpClass2_s2 struct _Con_M_PG_InlineRegExpClass2_s2
struct _Con_M_PG_InlineRegExpClass2_s2 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_InlineRegExpClass2_s2;
extern int step_M_PG_InlineRegExpClass2_s2(Sink,Term);

/* FUNCTION CookPG-PG-InlineRegExpClass2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_InlineRegExpClass2_s3 struct _Con_M_PG_InlineRegExpClass2_s3
struct _Con_M_PG_InlineRegExpClass2_s3 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_InlineRegExpClass2_s3;
extern int step_M_PG_InlineRegExpClass2_s3(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-Rule-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_Rule_s6 struct _Con_M_CRS_Rules_Rule_s6
struct _Con_M_CRS_Rules_Rule_s6 {struct _Construction construction; Term sub[10]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_Rule_s6;
extern int step_M_CRS_Rules_Rule_s6(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Term-10 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Term_s6 struct _Con_M_DerivedSorts_Term_s6
struct _Con_M_DerivedSorts_Term_s6 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Term_s6;
extern int step_M_DerivedSorts_Term_s6(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-Rule-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_Rule_s5 struct _Con_M_CRS_Rules_Rule_s5
struct _Con_M_CRS_Rules_Rule_s5 {struct _Construction construction; Term sub[13]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_Rule_s5;
extern int step_M_CRS_Rules_Rule_s5(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Term-9 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Term_s5 struct _Con_M_DerivedSorts_Term_s5
struct _Con_M_DerivedSorts_Term_s5 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Term_s5;
extern int step_M_DerivedSorts_Term_s5(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-Rule-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_Rule_s8 struct _Con_M_CRS_Rules_Rule_s8
struct _Con_M_CRS_Rules_Rule_s8 {struct _Construction construction; Term sub[13]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_Rule_s8;
extern int step_M_CRS_Rules_Rule_s8(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Term-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Term_s4 struct _Con_M_DerivedSorts_Term_s4
struct _Con_M_DerivedSorts_Term_s4 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Term_s4;
extern int step_M_DerivedSorts_Term_s4(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-Rule-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_Rule_s7 struct _Con_M_CRS_Rules_Rule_s7
struct _Con_M_CRS_Rules_Rule_s7 {struct _Construction construction; Term sub[11]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_Rule_s7;
extern int step_M_CRS_Rules_Rule_s7(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Term-8 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Term_s3 struct _Con_M_DerivedSorts_Term_s3
struct _Con_M_DerivedSorts_Term_s3 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Term_s3;
extern int step_M_DerivedSorts_Term_s3(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-Rule- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_Rule_s2 struct _Con_M_CRS_Rules_Rule_s2
struct _Con_M_CRS_Rules_Rule_s2 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_Rule_s2;
extern int step_M_CRS_Rules_Rule_s2(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Term-11 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Term_s9 struct _Con_M_DerivedSorts_Term_s9
struct _Con_M_DerivedSorts_Term_s9 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Term_s9;
extern int step_M_DerivedSorts_Term_s9(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-Rule-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_Rule_s4 struct _Con_M_CRS_Rules_Rule_s4
struct _Con_M_CRS_Rules_Rule_s4 {struct _Construction construction; Term sub[11]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_Rule_s4;
extern int step_M_CRS_Rules_Rule_s4(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Term-6 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Term_s8 struct _Con_M_DerivedSorts_Term_s8
struct _Con_M_DerivedSorts_Term_s8 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Term_s8;
extern int step_M_DerivedSorts_Term_s8(Sink,Term);

/* FUNCTION CookPG-PG-DeclareRegExp- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_DeclareRegExp struct _Con_M_PG_DeclareRegExp
struct _Con_M_PG_DeclareRegExp {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_DeclareRegExp;
extern int step_M_PG_DeclareRegExp(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-Rule-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_Rule_s3 struct _Con_M_CRS_Rules_Rule_s3
struct _Con_M_CRS_Rules_Rule_s3 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_Rule_s3;
extern int step_M_CRS_Rules_Rule_s3(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Term-5 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Term_s7 struct _Con_M_DerivedSorts_Term_s7
struct _Con_M_DerivedSorts_Term_s7 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Term_s7;
extern int step_M_DerivedSorts_Term_s7(Sink,Term);

/* FUNCTION CookPG-PG-DeclareRegExpSimple-6 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_DeclareRegExpSimple_s3 struct _Con_M_PG_DeclareRegExpSimple_s3
struct _Con_M_PG_DeclareRegExpSimple_s3 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_DeclareRegExpSimple_s3;
extern int step_M_PG_DeclareRegExpSimple_s3(Sink,Term);

/* FUNCTION CookPG-PG-DeclareRegExpSimple-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_DeclareRegExpSimple_s4 struct _Con_M_PG_DeclareRegExpSimple_s4
struct _Con_M_PG_DeclareRegExpSimple_s4 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_DeclareRegExpSimple_s4;
extern int step_M_PG_DeclareRegExpSimple_s4(Sink,Term);

/* FUNCTION CookBase-ScopeSortMetaVar-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ScopeSortMetaVar_s4 struct _Con_M_ScopeSortMetaVar_s4
struct _Con_M_ScopeSortMetaVar_s4 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ScopeSortMetaVar_s4;
extern int step_M_ScopeSortMetaVar_s4(Sink,Term);

/* FUNCTION CookPG-PG-DeclareRegExpSimple-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_DeclareRegExpSimple_s1 struct _Con_M_PG_DeclareRegExpSimple_s1
struct _Con_M_PG_DeclareRegExpSimple_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_DeclareRegExpSimple_s1;
extern int step_M_PG_DeclareRegExpSimple_s1(Sink,Term);

/* FUNCTION CookPG-PG-DeclareRegExpUnit- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_DeclareRegExpUnit_s2 struct _Con_M_PG_DeclareRegExpUnit_s2
struct _Con_M_PG_DeclareRegExpUnit_s2 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_DeclareRegExpUnit_s2;
extern int step_M_PG_DeclareRegExpUnit_s2(Sink,Term);

/* FUNCTION CookPG-PG-DeclareRegExpSimple-5 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_DeclareRegExpSimple_s2 struct _Con_M_PG_DeclareRegExpSimple_s2
struct _Con_M_PG_DeclareRegExpSimple_s2 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_DeclareRegExpSimple_s2;
extern int step_M_PG_DeclareRegExpSimple_s2(Sink,Term);

/* FUNCTION CookPG-PG-DeclareRegExpUnit-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_DeclareRegExpUnit_s4 struct _Con_M_PG_DeclareRegExpUnit_s4
struct _Con_M_PG_DeclareRegExpUnit_s4 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_DeclareRegExpUnit_s4;
extern int step_M_PG_DeclareRegExpUnit_s4(Sink,Term);

/* FUNCTION CookPG-PG-DeclareRegExpUnit-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_DeclareRegExpUnit_s3 struct _Con_M_PG_DeclareRegExpUnit_s3
struct _Con_M_PG_DeclareRegExpUnit_s3 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_DeclareRegExpUnit_s3;
extern int step_M_PG_DeclareRegExpUnit_s3(Sink,Term);

/* FUNCTION CookPG-PG-DeclareRegExpUnit-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_DeclareRegExpUnit_s6 struct _Con_M_PG_DeclareRegExpUnit_s6
struct _Con_M_PG_DeclareRegExpUnit_s6 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_DeclareRegExpUnit_s6;
extern int step_M_PG_DeclareRegExpUnit_s6(Sink,Term);

/* FUNCTION CookPG-PG-DeclareRegExpUnit-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_DeclareRegExpUnit_s5 struct _Con_M_PG_DeclareRegExpUnit_s5
struct _Con_M_PG_DeclareRegExpUnit_s5 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_DeclareRegExpUnit_s5;
extern int step_M_PG_DeclareRegExpUnit_s5(Sink,Term);

/* FUNCTION CookCRS-CRS-Declarations-Define-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declarations_Define_s1 struct _Con_M_CRS_Declarations_Define_s1
struct _Con_M_CRS_Declarations_Define_s1 {struct _Construction construction; Term sub[6]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declarations_Define_s1;
extern int step_M_CRS_Declarations_Define_s1(Sink,Term);

/* FUNCTION CookPG-PG-MetaTail-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_MetaTail_s1 struct _Con_M_PG_MetaTail_s1
struct _Con_M_PG_MetaTail_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_MetaTail_s1;
extern int step_M_PG_MetaTail_s1(Sink,Term);

/* FUNCTION CookPG-PG-MetaTail-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_MetaTail_s2 struct _Con_M_PG_MetaTail_s2
struct _Con_M_PG_MetaTail_s2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_MetaTail_s2;
extern int step_M_PG_MetaTail_s2(Sink,Term);

/* FUNCTION CookPG-PG-DeclareRegExpUnit-5 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_DeclareRegExpUnit_s7 struct _Con_M_PG_DeclareRegExpUnit_s7
struct _Con_M_PG_DeclareRegExpUnit_s7 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_DeclareRegExpUnit_s7;
extern int step_M_PG_DeclareRegExpUnit_s7(Sink,Term);

/* FUNCTION CookCRS-CRS-Declarations-Define- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declarations_Define_s3 struct _Con_M_CRS_Declarations_Define_s3
struct _Con_M_CRS_Declarations_Define_s3 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declarations_Define_s3;
extern int step_M_CRS_Declarations_Define_s3(Sink,Term);

/* FUNCTION CookCRS-CRS-Declarations-Define-5 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declarations_Define_s4 struct _Con_M_CRS_Declarations_Define_s4
struct _Con_M_CRS_Declarations_Define_s4 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declarations_Define_s4;
extern int step_M_CRS_Declarations_Define_s4(Sink,Term);

/* FUNCTION CookCRS-CRS-Declarations-Define-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declarations_Define_s5 struct _Con_M_CRS_Declarations_Define_s5
struct _Con_M_CRS_Declarations_Define_s5 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declarations_Define_s5;
extern int step_M_CRS_Declarations_Define_s5(Sink,Term);

/* FUNCTION CookCRS-CRS-Declarations-Define-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declarations_Define_s6 struct _Con_M_CRS_Declarations_Define_s6
struct _Con_M_CRS_Declarations_Define_s6 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declarations_Define_s6;
extern int step_M_CRS_Declarations_Define_s6(Sink,Term);

/* FUNCTION CookCRS-CRS-Declarations-Define-6 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declarations_Define_s7 struct _Con_M_CRS_Declarations_Define_s7
struct _Con_M_CRS_Declarations_Define_s7 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declarations_Define_s7;
extern int step_M_CRS_Declarations_Define_s7(Sink,Term);

/* FUNCTION CookCRS-CRS-Declarations-Define-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declarations_Define_s8 struct _Con_M_CRS_Declarations_Define_s8
struct _Con_M_CRS_Declarations_Define_s8 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declarations_Define_s8;
extern int step_M_CRS_Declarations_Define_s8(Sink,Term);

/* FUNCTION CookCRS-CRS-Declarations-Define-7 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declarations_Define_s9 struct _Con_M_CRS_Declarations_Define_s9
struct _Con_M_CRS_Declarations_Define_s9 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declarations_Define_s9;
extern int step_M_CRS_Declarations_Define_s9(Sink,Term);

/* FUNCTION CookN-_then-InsertDefines-1$_then-InsertDefines$OK HEADER DECLARATIONS. */
#define STRUCT_Con_M__xthen_InsertDefines struct _Con_M__xthen_InsertDefines
struct _Con_M__xthen_InsertDefines {struct _Construction construction; Term sub[5]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M__xthen_InsertDefines;
extern int step_M__xthen_InsertDefines(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-Rule-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_Rule_s9 struct _Con_M_CRS_Rules_Rule_s9
struct _Con_M_CRS_Rules_Rule_s9 {struct _Construction construction; Term sub[10]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_Rule_s9;
extern int step_M_CRS_Rules_Rule_s9(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Term-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Term_s1 struct _Con_M_DerivedSorts_Term_s1
struct _Con_M_DerivedSorts_Term_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Term_s1;
extern int step_M_DerivedSorts_Term_s1(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Term-7 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Term_s2 struct _Con_M_DerivedSorts_Term_s2
struct _Con_M_DerivedSorts_Term_s2 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Term_s2;
extern int step_M_DerivedSorts_Term_s2(Sink,Term);

/* FUNCTION CookN-_InsertDefines-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xInsertDefines_s2 struct _Con_M__xInsertDefines_s2
struct _Con_M__xInsertDefines_s2 {struct _Construction construction; Term sub[3]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M__xInsertDefines_s2;
extern int step_M__xInsertDefines_s2(Sink,Term);

/* FUNCTION CookBase-TermTopSort-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_TermTopSort_s9 struct _Con_M_TermTopSort_s9
struct _Con_M_TermTopSort_s9 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_TermTopSort_s9;
extern int step_M_TermTopSort_s9(Sink,Term);

/* FUNCTION CookN-_InsertDefines-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xInsertDefines_s1 struct _Con_M__xInsertDefines_s1
struct _Con_M__xInsertDefines_s1 {struct _Construction construction; Term sub[5]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M__xInsertDefines_s1;
extern int step_M__xInsertDefines_s1(Sink,Term);

/* FUNCTION CookBase-TermTopSort-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_TermTopSort_s6 struct _Con_M_TermTopSort_s6
struct _Con_M_TermTopSort_s6 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_TermTopSort_s6;
extern int step_M_TermTopSort_s6(Sink,Term);

/* FUNCTION CookBase-TermTopSort-8 HEADER DECLARATIONS. */
#define STRUCT_Con_M_TermTopSort_s5 struct _Con_M_TermTopSort_s5
struct _Con_M_TermTopSort_s5 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_TermTopSort_s5;
extern int step_M_TermTopSort_s5(Sink,Term);

/* FUNCTION CookBase-TermTopSort-10 HEADER DECLARATIONS. */
#define STRUCT_Con_M_TermTopSort_s8 struct _Con_M_TermTopSort_s8
struct _Con_M_TermTopSort_s8 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_TermTopSort_s8;
extern int step_M_TermTopSort_s8(Sink,Term);

/* FUNCTION CookBase-TermTopSort-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_TermTopSort_s7 struct _Con_M_TermTopSort_s7
struct _Con_M_TermTopSort_s7 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_TermTopSort_s7;
extern int step_M_TermTopSort_s7(Sink,Term);

/* FUNCTION CookBase-RegExpLeafSuffix- HEADER DECLARATIONS. */
#define STRUCT_Con_M_RegExpLeafSuffix struct _Con_M_RegExpLeafSuffix
struct _Con_M_RegExpLeafSuffix {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RegExpLeafSuffix;
extern int step_M_RegExpLeafSuffix(Sink,Term);

/* FUNCTION CookBase-TermTopSort-6 HEADER DECLARATIONS. */
#define STRUCT_Con_M_TermTopSort_s2 struct _Con_M_TermTopSort_s2
struct _Con_M_TermTopSort_s2 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_TermTopSort_s2;
extern int step_M_TermTopSort_s2(Sink,Term);

/* FUNCTION CookBase-TermTopSort-5 HEADER DECLARATIONS. */
#define STRUCT_Con_M_TermTopSort_s1 struct _Con_M_TermTopSort_s1
struct _Con_M_TermTopSort_s1 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_TermTopSort_s1;
extern int step_M_TermTopSort_s1(Sink,Term);

/* FUNCTION CookN-N-InheritedRefsList- HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_InheritedRefsList struct _Con_M_N_InheritedRefsList
struct _Con_M_N_InheritedRefsList {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_InheritedRefsList;
extern int step_M_N_InheritedRefsList(Sink,Term);

/* FUNCTION CookBase-TermTopSort-7 HEADER DECLARATIONS. */
#define STRUCT_Con_M_TermTopSort_s4 struct _Con_M_TermTopSort_s4
struct _Con_M_TermTopSort_s4 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_TermTopSort_s4;
extern int step_M_TermTopSort_s4(Sink,Term);

/* FUNCTION CookBase-TermTopSort-9 HEADER DECLARATIONS. */
#define STRUCT_Con_M_TermTopSort_s3 struct _Con_M_TermTopSort_s3
struct _Con_M_TermTopSort_s3 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_TermTopSort_s3;
extern int step_M_TermTopSort_s3(Sink,Term);

/* FUNCTION CookPG-PG-DeclareRegExpSimple-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_DeclareRegExpSimple_s6 struct _Con_M_PG_DeclareRegExpSimple_s6
struct _Con_M_PG_DeclareRegExpSimple_s6 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_DeclareRegExpSimple_s6;
extern int step_M_PG_DeclareRegExpSimple_s6(Sink,Term);

/* FUNCTION CookPG-PG-DeclareRegExpSimple-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_DeclareRegExpSimple_s5 struct _Con_M_PG_DeclareRegExpSimple_s5
struct _Con_M_PG_DeclareRegExpSimple_s5 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_DeclareRegExpSimple_s5;
extern int step_M_PG_DeclareRegExpSimple_s5(Sink,Term);

/* FUNCTION CookBase-ScopeSortMetaVar-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ScopeSortMetaVar_s3 struct _Con_M_ScopeSortMetaVar_s3
struct _Con_M_ScopeSortMetaVar_s3 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ScopeSortMetaVar_s3;
extern int step_M_ScopeSortMetaVar_s3(Sink,Term);

/* FUNCTION CookBase-ScopeSortMetaVar-1$ScopeSortMetaVar$2$RAW-RepeatSingle HEADER DECLARATIONS. */
#define STRUCT_Con_M_ScopeSortMetaVar_s2 struct _Con_M_ScopeSortMetaVar_s2
struct _Con_M_ScopeSortMetaVar_s2 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ScopeSortMetaVar_s2;
extern int step_M_ScopeSortMetaVar_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-Form-PatternEnv-1$CRS-Form-PatternEnv HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Form_PatternEnv struct _Con_M_CRS_Form_PatternEnv
struct _Con_M_CRS_Form_PatternEnv {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Form_PatternEnv;
extern int step_M_CRS_Form_PatternEnv(Sink,Term);

/* FUNCTION CookBase-RegExpLeafWord- HEADER DECLARATIONS. */
#define STRUCT_Con_M_RegExpLeafWord struct _Con_M_RegExpLeafWord
struct _Con_M_RegExpLeafWord {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_RegExpLeafWord;
extern int step_M_RegExpLeafWord(Sink,Term);

/* FUNCTION CookN-N-SortAlternativeDefine- HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_SortAlternativeDefine struct _Con_M_N_SortAlternativeDefine
struct _Con_M_N_SortAlternativeDefine {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_SortAlternativeDefine;
extern int step_M_N_SortAlternativeDefine(Sink,Term);

/* FUNCTION CookPG-SameScopeSort-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SameScopeSort struct _Con_M_SameScopeSort
struct _Con_M_SameScopeSort {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SameScopeSort;
extern int step_M_SameScopeSort(Sink,Term);

/* FUNCTION CookN-Resolve-Fragment HEADER DECLARATIONS. */
#define STRUCT_Con_M_N__resolve_s7 struct _Con_M_N__resolve_s7
struct _Con_M_N__resolve_s7 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N__resolve_s7;
extern int step_M_N__resolve_s7(Sink,Term);

/* FUNCTION CookN-Resolve-Import HEADER DECLARATIONS. */
#define STRUCT_Con_M_N__resolve_s8 struct _Con_M_N__resolve_s8
struct _Con_M_N__resolve_s8 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N__resolve_s8;
extern int step_M_N__resolve_s8(Sink,Term);

/* FUNCTION CookCRS-CRS2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS2_s1 struct _Con_M_CRS2_s1
struct _Con_M_CRS2_s1 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS2_s1;
extern int step_M_CRS2_s1(Sink,Term);

/* FUNCTION CookN-ResolveNesting HEADER DECLARATIONS. */
#define STRUCT_Con_M_N__resolve_s9 struct _Con_M_N__resolve_s9
struct _Con_M_N__resolve_s9 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N__resolve_s9;
extern int step_M_N__resolve_s9(Sink,Term);

/* FUNCTION Prelude-Special_error-2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_Special_xerror__2 struct _Con_M_Special_xerror__2
struct _Con_M_Special_xerror__2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_Special_xerror__2;
extern int step_M_Special_xerror__2(Sink,Term);

/* FUNCTION CookPG-PG-Production-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Production struct _Con_M_PG_Production
struct _Con_M_PG_Production {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_Production;
extern int step_M_PG_Production(Sink,Term);

/* FUNCTION Prelude-Fold-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_Fold_s3 struct _Con_M_Fold_s3
struct _Con_M_Fold_s3 {struct _Construction construction; Term sub[2]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_Fold_s3;
extern int step_M_Fold_s3(Sink,Term);

/* FUNCTION CookCRS-CRS-AttributeValues-6 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AttributeValues_s12 struct _Con_M_CRS_AttributeValues_s12
struct _Con_M_CRS_AttributeValues_s12 {struct _Construction construction; Term sub[11]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AttributeValues_s12;
extern int step_M_CRS_AttributeValues_s12(Sink,Term);

/* FUNCTION CookCRS-CRS-AttributeValues-8 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AttributeValues_s13 struct _Con_M_CRS_AttributeValues_s13
struct _Con_M_CRS_AttributeValues_s13 {struct _Construction construction; Term sub[10]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AttributeValues_s13;
extern int step_M_CRS_AttributeValues_s13(Sink,Term);

/* FUNCTION CookCRS-CRS-AttributeValues-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AttributeValues_s14 struct _Con_M_CRS_AttributeValues_s14
struct _Con_M_CRS_AttributeValues_s14 {struct _Construction construction; Term sub[10]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AttributeValues_s14;
extern int step_M_CRS_AttributeValues_s14(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBodyTerm2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBodyTerm2_s1 struct _Con_M_PG_ProduceBodyTerm2_s1
struct _Con_M_PG_ProduceBodyTerm2_s1 {struct _Construction construction; Term sub[12]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBodyTerm2_s1;
extern int step_M_PG_ProduceBodyTerm2_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-AttributeValues-9 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AttributeValues_s15 struct _Con_M_CRS_AttributeValues_s15
struct _Con_M_CRS_AttributeValues_s15 {struct _Construction construction; Term sub[4]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AttributeValues_s15;
extern int step_M_CRS_AttributeValues_s15(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBodyTerm2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBodyTerm2_s2 struct _Con_M_PG_ProduceBodyTerm2_s2
struct _Con_M_PG_ProduceBodyTerm2_s2 {struct _Construction construction; Term sub[10]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBodyTerm2_s2;
extern int step_M_PG_ProduceBodyTerm2_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-AttributeValues-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AttributeValues_s11 struct _Con_M_CRS_AttributeValues_s11
struct _Con_M_CRS_AttributeValues_s11 {struct _Construction construction; Term sub[10]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AttributeValues_s11;
extern int step_M_CRS_AttributeValues_s11(Sink,Term);

/* FUNCTION CookCRS-CRS-Declarations-DefineSynth-1$CRS-Declarations-DefineSynth$OK HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declarations_DefineSynth struct _Con_M_CRS_Declarations_DefineSynth
struct _Con_M_CRS_Declarations_DefineSynth {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declarations_DefineSynth;
extern int step_M_CRS_Declarations_DefineSynth(Sink,Term);

/* FUNCTION CookCRS-CRS-AttributeValues- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_AttributeValues_s10 struct _Con_M_CRS_AttributeValues_s10
struct _Con_M_CRS_AttributeValues_s10 {struct _Construction construction; Term sub[9]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_AttributeValues_s10;
extern int step_M_CRS_AttributeValues_s10(Sink,Term);

/* FUNCTION Prelude-Fold- HEADER DECLARATIONS. */
#define STRUCT_Con_M_Fold_s1 struct _Con_M_Fold_s1
struct _Con_M_Fold_s1 {struct _Construction construction; Term sub[3]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_Fold_s1;
extern int step_M_Fold_s1(Sink,Term);

/* FUNCTION Prelude-Fold-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_Fold_s2 struct _Con_M_Fold_s2
struct _Con_M_Fold_s2 {struct _Construction construction; Term sub[4]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_Fold_s2;
extern int step_M_Fold_s2(Sink,Term);

/* FUNCTION CookN-DLE-Form- HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefineLessEqual_s6 struct _Con_M__xDefineLessEqual_s6
struct _Con_M__xDefineLessEqual_s6 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xDefineLessEqual_s6;
extern int step_M__xDefineLessEqual_s6(Sink,Term);

/* FUNCTION CookPG-PG-InlineRegExpSimple-5 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_InlineRegExpSimple_s2 struct _Con_M_PG_InlineRegExpSimple_s2
struct _Con_M_PG_InlineRegExpSimple_s2 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_InlineRegExpSimple_s2;
extern int step_M_PG_InlineRegExpSimple_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-then-RepeatRulesSynth-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS__then_RepeatRulesSynth_s1 struct _Con_M_CRS__then_RepeatRulesSynth_s1
struct _Con_M_CRS__then_RepeatRulesSynth_s1 {struct _Construction construction; Term sub[9]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS__then_RepeatRulesSynth_s1;
extern int step_M_CRS__then_RepeatRulesSynth_s1(Sink,Term);

/* FUNCTION CookPG-PG-InlineRegExpSimple-6 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_InlineRegExpSimple_s3 struct _Con_M_PG_InlineRegExpSimple_s3
struct _Con_M_PG_InlineRegExpSimple_s3 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_InlineRegExpSimple_s3;
extern int step_M_PG_InlineRegExpSimple_s3(Sink,Term);

/* FUNCTION CookN-DLE-Abstraction-Rule HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefineLessEqual_s4 struct _Con_M__xDefineLessEqual_s4
struct _Con_M__xDefineLessEqual_s4 {struct _Construction construction; Term sub[6]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M__xDefineLessEqual_s4;
extern int step_M__xDefineLessEqual_s4(Sink,Term);

/* FUNCTION CookPG-PG-InlineRegExpSimple-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_InlineRegExpSimple_s4 struct _Con_M_PG_InlineRegExpSimple_s4
struct _Con_M_PG_InlineRegExpSimple_s4 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_InlineRegExpSimple_s4;
extern int step_M_PG_InlineRegExpSimple_s4(Sink,Term);

/* FUNCTION CookN-_DefineLessEqual-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefineLessEqual_s3 struct _Con_M__xDefineLessEqual_s3
struct _Con_M__xDefineLessEqual_s3 {struct _Construction construction; Term sub[4]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M__xDefineLessEqual_s3;
extern int step_M__xDefineLessEqual_s3(Sink,Term);

/* FUNCTION CookPG-PG-InlineRegExpSimple-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_InlineRegExpSimple_s5 struct _Con_M_PG_InlineRegExpSimple_s5
struct _Con_M_PG_InlineRegExpSimple_s5 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_InlineRegExpSimple_s5;
extern int step_M_PG_InlineRegExpSimple_s5(Sink,Term);

/* FUNCTION CookPG-PG-InlineRegExpSimple-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_InlineRegExpSimple_s6 struct _Con_M_PG_InlineRegExpSimple_s6
struct _Con_M_PG_InlineRegExpSimple_s6 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_InlineRegExpSimple_s6;
extern int step_M_PG_InlineRegExpSimple_s6(Sink,Term);

/* FUNCTION CookN-DLE-Form-Rule HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefineLessEqual_s8 struct _Con_M__xDefineLessEqual_s8
struct _Con_M__xDefineLessEqual_s8 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xDefineLessEqual_s8;
extern int step_M__xDefineLessEqual_s8(Sink,Term);

/* FUNCTION CookN-DLE-Form-Form HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefineLessEqual_s7 struct _Con_M__xDefineLessEqual_s7
struct _Con_M__xDefineLessEqual_s7 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xDefineLessEqual_s7;
extern int step_M__xDefineLessEqual_s7(Sink,Term);

/* FUNCTION CookN-Then-DerivedSorts-Scope-1$Then-DerivedSorts-Scope$OK HEADER DECLARATIONS. */
#define STRUCT_Con_M_Then_DerivedSorts_Scope struct _Con_M_Then_DerivedSorts_Scope
struct _Con_M_Then_DerivedSorts_Scope {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_Then_DerivedSorts_Scope;
extern int step_M_Then_DerivedSorts_Scope(Sink,Term);

/* FUNCTION CookPG-PG-InlineRegExpSimple-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_InlineRegExpSimple_s1 struct _Con_M_PG_InlineRegExpSimple_s1
struct _Con_M_PG_InlineRegExpSimple_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_InlineRegExpSimple_s1;
extern int step_M_PG_InlineRegExpSimple_s1(Sink,Term);

/* FUNCTION CookBase-NestedRepeat- HEADER DECLARATIONS. */
#define STRUCT_Con_M_NestedRepeat struct _Con_M_NestedRepeat
struct _Con_M_NestedRepeat {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_NestedRepeat;
extern int step_M_NestedRepeat(Sink,Term);

/* FUNCTION CookCRS-Make_Alternate-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_Make_xAlternate struct _Con_M_Make_xAlternate
struct _Con_M_Make_xAlternate {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_Make_xAlternate;
extern int step_M_Make_xAlternate(Sink,Term);

/* FUNCTION CookPG-PG-DeclareRegExp-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_DeclareRegExp_s1 struct _Con_M_PG_DeclareRegExp_s1
struct _Con_M_PG_DeclareRegExp_s1 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_DeclareRegExp_s1;
extern int step_M_PG_DeclareRegExp_s1(Sink,Term);

/* FUNCTION CookPG-PG-DeclareRegExp-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_DeclareRegExp_s2 struct _Con_M_PG_DeclareRegExp_s2
struct _Con_M_PG_DeclareRegExp_s2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_DeclareRegExp_s2;
extern int step_M_PG_DeclareRegExp_s2(Sink,Term);

/* FUNCTION CookBase-ScopeSortName- HEADER DECLARATIONS. */
#define STRUCT_Con_M_ScopeSortName struct _Con_M_ScopeSortName
struct _Con_M_ScopeSortName {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ScopeSortName;
extern int step_M_ScopeSortName(Sink,Term);

/* FUNCTION CookCRS-CRS-Term-8 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Term_s10 struct _Con_M_CRS_Term_s10
struct _Con_M_CRS_Term_s10 {struct _Construction construction; Term sub[12]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Term_s10;
extern int step_M_CRS_Term_s10(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-TokenSynth-1$CRS-Rules-TokenSynth$OK HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_TokenSynth struct _Con_M_CRS_Rules_TokenSynth
struct _Con_M_CRS_Rules_TokenSynth {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_TokenSynth;
extern int step_M_CRS_Rules_TokenSynth(Sink,Term);

/* FUNCTION CookN- HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefineLessEqual_s2 struct _Con_M__xDefineLessEqual_s2
struct _Con_M__xDefineLessEqual_s2 {struct _Construction construction; Term sub[3]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M__xDefineLessEqual_s2;
extern int step_M__xDefineLessEqual_s2(Sink,Term);

/* FUNCTION CookPG-ProductionNames3-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ProductionNames3_s5 struct _Con_M_ProductionNames3_s5
struct _Con_M_ProductionNames3_s5 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ProductionNames3_s5;
extern int step_M_ProductionNames3_s5(Sink,Term);

/* FUNCTION CookPG-ProductionNames3-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ProductionNames3_s4 struct _Con_M_ProductionNames3_s4
struct _Con_M_ProductionNames3_s4 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ProductionNames3_s4;
extern int step_M_ProductionNames3_s4(Sink,Term);

/* FUNCTION CookPG-ProductionNames3-5 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ProductionNames3_s6 struct _Con_M_ProductionNames3_s6
struct _Con_M_ProductionNames3_s6 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ProductionNames3_s6;
extern int step_M_ProductionNames3_s6(Sink,Term);

/* FUNCTION CookPG-ProductionNames3- HEADER DECLARATIONS. */
#define STRUCT_Con_M_ProductionNames3_s1 struct _Con_M_ProductionNames3_s1
struct _Con_M_ProductionNames3_s1 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ProductionNames3_s1;
extern int step_M_ProductionNames3_s1(Sink,Term);

/* FUNCTION CookPG-ProductionNames3-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ProductionNames3_s3 struct _Con_M_ProductionNames3_s3
struct _Con_M_ProductionNames3_s3 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ProductionNames3_s3;
extern int step_M_ProductionNames3_s3(Sink,Term);

/* FUNCTION CookPG-PG-Production-Defines3-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Production_Defines3_s2 struct _Con_M_PG_Production_Defines3_s2
struct _Con_M_PG_Production_Defines3_s2 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_Production_Defines3_s2;
extern int step_M_PG_Production_Defines3_s2(Sink,Term);

/* FUNCTION CookPG-ProductionNames3-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ProductionNames3_s2 struct _Con_M_ProductionNames3_s2
struct _Con_M_ProductionNames3_s2 {struct _Construction construction; Term sub[5]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M_ProductionNames3_s2;
extern int step_M_ProductionNames3_s2(Sink,Term);

/* FUNCTION CookPG-PG-Production-Defines3- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Production_Defines3_s1 struct _Con_M_PG_Production_Defines3_s1
struct _Con_M_PG_Production_Defines3_s1 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_Production_Defines3_s1;
extern int step_M_PG_Production_Defines3_s1(Sink,Term);

/* FUNCTION CookPG-PG-Production-Defines3-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Production_Defines3_s3 struct _Con_M_PG_Production_Defines3_s3
struct _Con_M_PG_Production_Defines3_s3 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_Production_Defines3_s3;
extern int step_M_PG_Production_Defines3_s3(Sink,Term);

/* FUNCTION CookCRS-CRS-Declarations-Derived2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declarations_Derived2 struct _Con_M_CRS_Declarations_Derived2
struct _Con_M_CRS_Declarations_Derived2 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declarations_Derived2;
extern int step_M_CRS_Declarations_Derived2(Sink,Term);

/* FUNCTION CookBase-SortVar2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortVar2_s4 struct _Con_M_SortVar2_s4
struct _Con_M_SortVar2_s4 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortVar2_s4;
extern int step_M_SortVar2_s4(Sink,Term);

/* FUNCTION CookBase-SortVar2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortVar2_s3 struct _Con_M_SortVar2_s3
struct _Con_M_SortVar2_s3 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortVar2_s3;
extern int step_M_SortVar2_s3(Sink,Term);

/* FUNCTION CookPG-IfAliasKind- HEADER DECLARATIONS. */
#define STRUCT_Con_M_IfAliasKind struct _Con_M_IfAliasKind
struct _Con_M_IfAliasKind {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_IfAliasKind;
extern int step_M_IfAliasKind(Sink,Term);

/* FUNCTION CookBase-SortVar2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortVar2_s6 struct _Con_M_SortVar2_s6
struct _Con_M_SortVar2_s6 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortVar2_s6;
extern int step_M_SortVar2_s6(Sink,Term);

/* FUNCTION CookBase-SortVar2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortVar2_s5 struct _Con_M_SortVar2_s5
struct _Con_M_SortVar2_s5 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortVar2_s5;
extern int step_M_SortVar2_s5(Sink,Term);

/* FUNCTION CookCRS-CRS-Declarations1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declarations1_s1 struct _Con_M_CRS_Declarations1_s1
struct _Con_M_CRS_Declarations1_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declarations1_s1;
extern int step_M_CRS_Declarations1_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-Declarations1-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declarations1_s2 struct _Con_M_CRS_Declarations1_s2
struct _Con_M_CRS_Declarations1_s2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declarations1_s2;
extern int step_M_CRS_Declarations1_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-then-PrintP-1$CRS-then-PrintP$OK HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS__then_PrintP struct _Con_M_CRS__then_PrintP
struct _Con_M_CRS__then_PrintP {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS__then_PrintP;
extern int step_M_CRS__then_PrintP(Sink,Term);

/* FUNCTION CookBase-SortVar2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortVar2_s2 struct _Con_M_SortVar2_s2
struct _Con_M_SortVar2_s2 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortVar2_s2;
extern int step_M_SortVar2_s2(Sink,Term);

/* FUNCTION CookBase-SortVar2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortVar2_s1 struct _Con_M_SortVar2_s1
struct _Con_M_SortVar2_s1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortVar2_s1;
extern int step_M_SortVar2_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-Synthesized-1$CRS-Rules-Synthesized$OK HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_Synthesized struct _Con_M_CRS_Rules_Synthesized
struct _Con_M_CRS_Rules_Synthesized {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_Synthesized;
extern int step_M_CRS_Rules_Synthesized(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-Define-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_Define_s1 struct _Con_M_CRS_Rules_Define_s1
struct _Con_M_CRS_Rules_Define_s1 {struct _Construction construction; Term sub[7]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_Define_s1;
extern int step_M_CRS_Rules_Define_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-Define- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_Define_s3 struct _Con_M_CRS_Rules_Define_s3
struct _Con_M_CRS_Rules_Define_s3 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_Define_s3;
extern int step_M_CRS_Rules_Define_s3(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-Define-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_Define_s5 struct _Con_M_CRS_Rules_Define_s5
struct _Con_M_CRS_Rules_Define_s5 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_Define_s5;
extern int step_M_CRS_Rules_Define_s5(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-Define-5 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_Define_s4 struct _Con_M_CRS_Rules_Define_s4
struct _Con_M_CRS_Rules_Define_s4 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_Define_s4;
extern int step_M_CRS_Rules_Define_s4(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-Define-6 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_Define_s7 struct _Con_M_CRS_Rules_Define_s7
struct _Con_M_CRS_Rules_Define_s7 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_Define_s7;
extern int step_M_CRS_Rules_Define_s7(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-Define-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_Define_s6 struct _Con_M_CRS_Rules_Define_s6
struct _Con_M_CRS_Rules_Define_s6 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_Define_s6;
extern int step_M_CRS_Rules_Define_s6(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-Define-7 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_Define_s9 struct _Con_M_CRS_Rules_Define_s9
struct _Con_M_CRS_Rules_Define_s9 {struct _Construction construction; Term sub[9]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_Define_s9;
extern int step_M_CRS_Rules_Define_s9(Sink,Term);

/* FUNCTION CookCRS-CRS-MetaDeclarations1- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_MetaDeclarations1 struct _Con_M_CRS_MetaDeclarations1
struct _Con_M_CRS_MetaDeclarations1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_MetaDeclarations1;
extern int step_M_CRS_MetaDeclarations1(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-Define-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_Define_s8 struct _Con_M_CRS_Rules_Define_s8
struct _Con_M_CRS_Rules_Define_s8 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_Define_s8;
extern int step_M_CRS_Rules_Define_s8(Sink,Term);

/* FUNCTION CookCRS-CRS-MetaDeclarations-AttributeOptions-1$CRS-MetaDeclarations-AttributeOptions$2$RAW-AttributeOption HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_MetaDeclarations_AttributeOptions_s2 struct _Con_M_CRS_MetaDeclarations_AttributeOptions_s2
struct _Con_M_CRS_MetaDeclarations_AttributeOptions_s2 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_MetaDeclarations_AttributeOptions_s2;
extern int step_M_CRS_MetaDeclarations_AttributeOptions_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-MetaDeclarations-AttributeOptions-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_MetaDeclarations_AttributeOptions_s3 struct _Con_M_CRS_MetaDeclarations_AttributeOptions_s3
struct _Con_M_CRS_MetaDeclarations_AttributeOptions_s3 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_MetaDeclarations_AttributeOptions_s3;
extern int step_M_CRS_MetaDeclarations_AttributeOptions_s3(Sink,Term);

/* FUNCTION CookPG-PG-LeftRecursive2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_LeftRecursive2 struct _Con_M_PG_LeftRecursive2
struct _Con_M_PG_LeftRecursive2 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_LeftRecursive2;
extern int step_M_PG_LeftRecursive2(Sink,Term);

/* FUNCTION CookCRS-CRS-MetaDeclarations-AttributeOptions- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_MetaDeclarations_AttributeOptions_s1 struct _Con_M_CRS_MetaDeclarations_AttributeOptions_s1
struct _Con_M_CRS_MetaDeclarations_AttributeOptions_s1 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_MetaDeclarations_AttributeOptions_s1;
extern int step_M_CRS_MetaDeclarations_AttributeOptions_s1(Sink,Term);

/* FUNCTION CookN-_InsertSynthesizedRefs1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xInsertSynthesizedRefs1_s1 struct _Con_M__xInsertSynthesizedRefs1_s1
struct _Con_M__xInsertSynthesizedRefs1_s1 {struct _Construction construction; Term sub[3]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M__xInsertSynthesizedRefs1_s1;
extern int step_M__xInsertSynthesizedRefs1_s1(Sink,Term);

/* FUNCTION CookN-_InsertSynthesizedRefs1-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xInsertSynthesizedRefs1_s2 struct _Con_M__xInsertSynthesizedRefs1_s2
struct _Con_M__xInsertSynthesizedRefs1_s2 {struct _Construction construction; Term sub[8]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M__xInsertSynthesizedRefs1_s2;
extern int step_M__xInsertSynthesizedRefs1_s2(Sink,Term);

/* FUNCTION CookN-_InsertSynthesizedRefs1-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xInsertSynthesizedRefs1_s3 struct _Con_M__xInsertSynthesizedRefs1_s3
struct _Con_M__xInsertSynthesizedRefs1_s3 {struct _Construction construction; Term sub[5]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M__xInsertSynthesizedRefs1_s3;
extern int step_M__xInsertSynthesizedRefs1_s3(Sink,Term);

/* FUNCTION CookCRS-CRS-MetaDeclarations-AttributeOptions-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_MetaDeclarations_AttributeOptions_s4 struct _Con_M_CRS_MetaDeclarations_AttributeOptions_s4
struct _Con_M_CRS_MetaDeclarations_AttributeOptions_s4 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_MetaDeclarations_AttributeOptions_s4;
extern int step_M_CRS_MetaDeclarations_AttributeOptions_s4(Sink,Term);

/* FUNCTION CookN-Declarations-token HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_Declarations1_s13 struct _Con_M_N_Declarations1_s13
struct _Con_M_N_Declarations1_s13 {struct _Construction construction; Term sub[9]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M_N_Declarations1_s13;
extern int step_M_N_Declarations1_s13(Sink,Term);

/* FUNCTION CookN-Declarations-synthesizedrefs HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_Declarations1_s12 struct _Con_M_N_Declarations1_s12
struct _Con_M_N_Declarations1_s12 {struct _Construction construction; Term sub[8]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M_N_Declarations1_s12;
extern int step_M_N_Declarations1_s12(Sink,Term);

/* FUNCTION CookN-Declarations-space HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_Declarations1_s11 struct _Con_M_N_Declarations1_s11
struct _Con_M_N_Declarations1_s11 {struct _Construction construction; Term sub[8]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M_N_Declarations1_s11;
extern int step_M_N_Declarations1_s11(Sink,Term);

/* FUNCTION CookN-Declarations-sort HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_Declarations1_s10 struct _Con_M_N_Declarations1_s10
struct _Con_M_N_Declarations1_s10 {struct _Construction construction; Term sub[10]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M_N_Declarations1_s10;
extern int step_M_N_Declarations1_s10(Sink,Term);

/* FUNCTION Prelude-UnionNames1-1$UnionNames1$NAME_SET HEADER DECLARATIONS. */
#define STRUCT_Con_M_UnionNames1 struct _Con_M_UnionNames1
struct _Con_M_UnionNames1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_UnionNames1;
extern int step_M_UnionNames1(Sink,Term);

/* FUNCTION CookPG-SubRepeat-somesep-word-word HEADER DECLARATIONS. */
#define STRUCT_Con_M_SubRepeat_s34 struct _Con_M_SubRepeat_s34
struct _Con_M_SubRepeat_s34 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SubRepeat_s34;
extern int step_M_SubRepeat_s34(Sink,Term);

/* FUNCTION CookPG-SubRepeat-somesep-string-word HEADER DECLARATIONS. */
#define STRUCT_Con_M_SubRepeat_s33 struct _Con_M_SubRepeat_s33
struct _Con_M_SubRepeat_s33 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SubRepeat_s33;
extern int step_M_SubRepeat_s33(Sink,Term);

/* FUNCTION CookPG-SubRepeat-somesep- HEADER DECLARATIONS. */
#define STRUCT_Con_M_SubRepeat_s32 struct _Con_M_SubRepeat_s32
struct _Con_M_SubRepeat_s32 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SubRepeat_s32;
extern int step_M_SubRepeat_s32(Sink,Term);

/* FUNCTION CookPG-PG-DeclareRegExpChoice- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_DeclareRegExpChoice struct _Con_M_PG_DeclareRegExpChoice
struct _Con_M_PG_DeclareRegExpChoice {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_DeclareRegExpChoice;
extern int step_M_PG_DeclareRegExpChoice(Sink,Term);

/* FUNCTION CookPG-SubRepeat-somesep-word-string HEADER DECLARATIONS. */
#define STRUCT_Con_M_SubRepeat_s30 struct _Con_M_SubRepeat_s30
struct _Con_M_SubRepeat_s30 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SubRepeat_s30;
extern int step_M_SubRepeat_s30(Sink,Term);

/* FUNCTION CookCRS-CRS-Term-Attributes-9 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Term_Attributes_s3 struct _Con_M_CRS_Term_Attributes_s3
struct _Con_M_CRS_Term_Attributes_s3 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Term_Attributes_s3;
extern int step_M_CRS_Term_Attributes_s3(Sink,Term);

/* FUNCTION CookCRS-CRS-Term-Attributes-5 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Term_Attributes_s4 struct _Con_M_CRS_Term_Attributes_s4
struct _Con_M_CRS_Term_Attributes_s4 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Term_Attributes_s4;
extern int step_M_CRS_Term_Attributes_s4(Sink,Term);

/* FUNCTION CookCRS-CRS-FormScopeSorts- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_FormScopeSorts struct _Con_M_CRS_FormScopeSorts
struct _Con_M_CRS_FormScopeSorts {struct _Construction construction; Term sub[7]; Variable binder[5];};
extern struct _ConstructionDescriptor descriptor_M_CRS_FormScopeSorts;
extern int step_M_CRS_FormScopeSorts(Sink,Term);

/* FUNCTION CookCRS-CRS-Term-Attributes-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Term_Attributes_s1 struct _Con_M_CRS_Term_Attributes_s1
struct _Con_M_CRS_Term_Attributes_s1 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Term_Attributes_s1;
extern int step_M_CRS_Term_Attributes_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-Term-Attributes-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Term_Attributes_s2 struct _Con_M_CRS_Term_Attributes_s2
struct _Con_M_CRS_Term_Attributes_s2 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Term_Attributes_s2;
extern int step_M_CRS_Term_Attributes_s2(Sink,Term);

/* FUNCTION CookN-_ParsedFormLess-8 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xParsedFormLess_s11 struct _Con_M__xParsedFormLess_s11
struct _Con_M__xParsedFormLess_s11 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xParsedFormLess_s11;
extern int step_M__xParsedFormLess_s11(Sink,Term);

/* FUNCTION CookBase-ScopeSortName-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ScopeSortName_s2 struct _Con_M_ScopeSortName_s2
struct _Con_M_ScopeSortName_s2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ScopeSortName_s2;
extern int step_M_ScopeSortName_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-Inherited-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_Inherited_s1 struct _Con_M_CRS_Rules_Inherited_s1
struct _Con_M_CRS_Rules_Inherited_s1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_Inherited_s1;
extern int step_M_CRS_Rules_Inherited_s1(Sink,Term);

/* FUNCTION CookN-_ParsedFormLess-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xParsedFormLess_s10 struct _Con_M__xParsedFormLess_s10
struct _Con_M__xParsedFormLess_s10 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xParsedFormLess_s10;
extern int step_M__xParsedFormLess_s10(Sink,Term);

/* FUNCTION CookBase-ScopeSortName-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ScopeSortName_s1 struct _Con_M_ScopeSortName_s1
struct _Con_M_ScopeSortName_s1 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ScopeSortName_s1;
extern int step_M_ScopeSortName_s1(Sink,Term);

/* FUNCTION CookN-N-Declarations-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_Declarations struct _Con_M_N_Declarations
struct _Con_M_N_Declarations {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_Declarations;
extern int step_M_N_Declarations(Sink,Term);

/* FUNCTION CookN-_ParsedFormLess-8 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xParsedFormLess_s17 struct _Con_M__xParsedFormLess_s17
struct _Con_M__xParsedFormLess_s17 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xParsedFormLess_s17;
extern int step_M__xParsedFormLess_s17(Sink,Term);

/* FUNCTION CookN-_ParsedFormLess-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xParsedFormLess_s16 struct _Con_M__xParsedFormLess_s16
struct _Con_M__xParsedFormLess_s16 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xParsedFormLess_s16;
extern int step_M__xParsedFormLess_s16(Sink,Term);

/* FUNCTION CookN-_ParsedFormLess-5 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xParsedFormLess_s19 struct _Con_M__xParsedFormLess_s19
struct _Con_M__xParsedFormLess_s19 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xParsedFormLess_s19;
extern int step_M__xParsedFormLess_s19(Sink,Term);

/* FUNCTION CookN-_ParsedFormLess-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xParsedFormLess_s18 struct _Con_M__xParsedFormLess_s18
struct _Con_M__xParsedFormLess_s18 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xParsedFormLess_s18;
extern int step_M__xParsedFormLess_s18(Sink,Term);

/* FUNCTION CookN-_ParsedFormLess-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xParsedFormLess_s13 struct _Con_M__xParsedFormLess_s13
struct _Con_M__xParsedFormLess_s13 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xParsedFormLess_s13;
extern int step_M__xParsedFormLess_s13(Sink,Term);

/* FUNCTION CookCRS-CRS-Literate-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Literate struct _Con_M_CRS_Literate
struct _Con_M_CRS_Literate {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Literate;
extern int step_M_CRS_Literate(Sink,Term);

/* FUNCTION CookN-_ParsedFormLess-6 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xParsedFormLess_s12 struct _Con_M__xParsedFormLess_s12
struct _Con_M__xParsedFormLess_s12 {struct _Construction construction; Term sub[10]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xParsedFormLess_s12;
extern int step_M__xParsedFormLess_s12(Sink,Term);

/* FUNCTION CookN-_ParsedFormLess- HEADER DECLARATIONS. */
#define STRUCT_Con_M__xParsedFormLess_s15 struct _Con_M__xParsedFormLess_s15
struct _Con_M__xParsedFormLess_s15 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xParsedFormLess_s15;
extern int step_M__xParsedFormLess_s15(Sink,Term);

/* FUNCTION CookCRS-CRS-TermConstruction1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_TermConstruction1 struct _Con_M_CRS_TermConstruction1
struct _Con_M_CRS_TermConstruction1 {struct _Construction construction; Term sub[10]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_TermConstruction1;
extern int step_M_CRS_TermConstruction1(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-DefineSynth-1$CRS-Rules-DefineSynth$3$NAMES HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_DefineSynth_s3 struct _Con_M_CRS_Rules_DefineSynth_s3
struct _Con_M_CRS_Rules_DefineSynth_s3 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_DefineSynth_s3;
extern int step_M_CRS_Rules_DefineSynth_s3(Sink,Term);

/* FUNCTION CookBase-SortNameWithRepeat1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortNameWithRepeat1 struct _Con_M_SortNameWithRepeat1
struct _Con_M_SortNameWithRepeat1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortNameWithRepeat1;
extern int step_M_SortNameWithRepeat1(Sink,Term);

/* FUNCTION CookPG-PG-Produce- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Produce_s1 struct _Con_M_PG_Produce_s1
struct _Con_M_PG_Produce_s1 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_Produce_s1;
extern int step_M_PG_Produce_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-DefineSynth-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_DefineSynth_s4 struct _Con_M_CRS_Rules_DefineSynth_s4
struct _Con_M_CRS_Rules_DefineSynth_s4 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_DefineSynth_s4;
extern int step_M_CRS_Rules_DefineSynth_s4(Sink,Term);

/* FUNCTION CookPG-PG-Production1-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Production1_s4 struct _Con_M_PG_Production1_s4
struct _Con_M_PG_Production1_s4 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_Production1_s4;
extern int step_M_PG_Production1_s4(Sink,Term);

/* FUNCTION CookPG-PG-MetaHead-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_MetaHead_s5 struct _Con_M_PG_MetaHead_s5
struct _Con_M_PG_MetaHead_s5 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_MetaHead_s5;
extern int step_M_PG_MetaHead_s5(Sink,Term);

/* FUNCTION CookPG-PG-Production1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Production1_s2 struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PG_Production1_s2;
extern int step_M_PG_Production1_s2(Sink,Term);

/* FUNCTION CookBase-FullPrefix-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_FullPrefix struct _Con_M_FullPrefix
struct _Con_M_FullPrefix {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_FullPrefix;
extern int step_M_FullPrefix(Sink,Term);

/* FUNCTION CookPG-PG-Production1-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Production1_s3 struct _Con_M_PG_Production1_s3
struct _Con_M_PG_Production1_s3 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_Production1_s3;
extern int step_M_PG_Production1_s3(Sink,Term);

/* FUNCTION CookPG-PG-Produce-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Produce_s2 struct _Con_M_PG_Produce_s2
struct _Con_M_PG_Produce_s2 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_Produce_s2;
extern int step_M_PG_Produce_s2(Sink,Term);

/* FUNCTION CookPG-PG-MetaHead-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_MetaHead_s1 struct _Con_M_PG_MetaHead_s1
struct _Con_M_PG_MetaHead_s1 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_MetaHead_s1;
extern int step_M_PG_MetaHead_s1(Sink,Term);

/* FUNCTION CookPG-PG-Produce-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Produce_s3 struct _Con_M_PG_Produce_s3
struct _Con_M_PG_Produce_s3 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_Produce_s3;
extern int step_M_PG_Produce_s3(Sink,Term);

/* FUNCTION Prelude-When-1$When$OK HEADER DECLARATIONS. */
#define STRUCT_Con_M_When struct _Con_M_When
struct _Con_M_When {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_When;
extern int step_M_When(Sink,Term);

/* FUNCTION CookPG-PG-MetaHead- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_MetaHead_s3 struct _Con_M_PG_MetaHead_s3
struct _Con_M_PG_MetaHead_s3 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_MetaHead_s3;
extern int step_M_PG_MetaHead_s3(Sink,Term);

/* FUNCTION CookPG-PG-MetaHead-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_MetaHead_s4 struct _Con_M_PG_MetaHead_s4
struct _Con_M_PG_MetaHead_s4 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_MetaHead_s4;
extern int step_M_PG_MetaHead_s4(Sink,Term);

/* FUNCTION CookPG-Lexical- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Lexical2_s2 struct _Con_M_PG_Lexical2_s2
struct _Con_M_PG_Lexical2_s2 {struct _Construction construction; Term sub[5]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M_PG_Lexical2_s2;
extern int step_M_PG_Lexical2_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-Term-Attributes-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Term_Attributes_s6 struct _Con_M_CRS_Term_Attributes_s6
struct _Con_M_CRS_Term_Attributes_s6 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Term_Attributes_s6;
extern int step_M_CRS_Term_Attributes_s6(Sink,Term);

/* FUNCTION CookPG-Lexical-alternatives HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Lexical2_s3 struct _Con_M_PG_Lexical2_s3
struct _Con_M_PG_Lexical2_s3 {struct _Construction construction; Term sub[6]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M_PG_Lexical2_s3;
extern int step_M_PG_Lexical2_s3(Sink,Term);

/* FUNCTION CookCRS-CRS-Term-Attributes-6 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Term_Attributes_s5 struct _Con_M_CRS_Term_Attributes_s5
struct _Con_M_CRS_Term_Attributes_s5 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Term_Attributes_s5;
extern int step_M_CRS_Term_Attributes_s5(Sink,Term);

/* FUNCTION CookCRS-CRS-Term-Attributes-10 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Term_Attributes_s8 struct _Con_M_CRS_Term_Attributes_s8
struct _Con_M_CRS_Term_Attributes_s8 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Term_Attributes_s8;
extern int step_M_CRS_Term_Attributes_s8(Sink,Term);

/* FUNCTION CookPG-Lexcial-done HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Lexical2_s1 struct _Con_M_PG_Lexical2_s1
struct _Con_M_PG_Lexical2_s1 {struct _Construction construction; Term sub[3]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M_PG_Lexical2_s1;
extern int step_M_PG_Lexical2_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-Term-Attributes-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Term_Attributes_s7 struct _Con_M_CRS_Term_Attributes_s7
struct _Con_M_CRS_Term_Attributes_s7 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Term_Attributes_s7;
extern int step_M_CRS_Term_Attributes_s7(Sink,Term);

/* FUNCTION CookPG-PG-Production1-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Production1_s1 struct _Con_M_PG_Production1_s1
struct _Con_M_PG_Production1_s1 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_Production1_s1;
extern int step_M_PG_Production1_s1(Sink,Term);

/* FUNCTION CookPG-Lexical-module HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Lexical2_s6 struct _Con_M_PG_Lexical2_s6
struct _Con_M_PG_Lexical2_s6 {struct _Construction construction; Term sub[8]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M_PG_Lexical2_s6;
extern int step_M_PG_Lexical2_s6(Sink,Term);

/* FUNCTION CookPG-Lexical-fragment HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Lexical2_s7 struct _Con_M_PG_Lexical2_s7
struct _Con_M_PG_Lexical2_s7 {struct _Construction construction; Term sub[7]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M_PG_Lexical2_s7;
extern int step_M_PG_Lexical2_s7(Sink,Term);

/* FUNCTION CookCRS-CRS-Term-Attributes-7 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Term_Attributes_s9 struct _Con_M_CRS_Term_Attributes_s9
struct _Con_M_CRS_Term_Attributes_s9 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Term_Attributes_s9;
extern int step_M_CRS_Term_Attributes_s9(Sink,Term);

/* FUNCTION CookPG-Lexical-attribute HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Lexical2_s4 struct _Con_M_PG_Lexical2_s4
struct _Con_M_PG_Lexical2_s4 {struct _Construction construction; Term sub[9]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M_PG_Lexical2_s4;
extern int step_M_PG_Lexical2_s4(Sink,Term);

/* FUNCTION CookPG-Lexical-module$PG-Lexical2$5$RAW-module HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Lexical2_s5 struct _Con_M_PG_Lexical2_s5
struct _Con_M_PG_Lexical2_s5 {struct _Construction construction; Term sub[6]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M_PG_Lexical2_s5;
extern int step_M_PG_Lexical2_s5(Sink,Term);

/* FUNCTION CookN-_InsertDefine2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xInsertDefine2_s1 struct _Con_M__xInsertDefine2_s1
struct _Con_M__xInsertDefine2_s1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xInsertDefine2_s1;
extern int step_M__xInsertDefine2_s1(Sink,Term);

/* FUNCTION CookN-_InsertDefine2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xInsertDefine2_s2 struct _Con_M__xInsertDefine2_s2
struct _Con_M__xInsertDefine2_s2 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xInsertDefine2_s2;
extern int step_M__xInsertDefine2_s2(Sink,Term);

/* FUNCTION CookPG-Lexical-nest HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Lexical2_s8 struct _Con_M_PG_Lexical2_s8
struct _Con_M_PG_Lexical2_s8 {struct _Construction construction; Term sub[6]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M_PG_Lexical2_s8;
extern int step_M_PG_Lexical2_s8(Sink,Term);

/* FUNCTION CookPG-Lexical-rule HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Lexical2_s9 struct _Con_M_PG_Lexical2_s9
struct _Con_M_PG_Lexical2_s9 {struct _Construction construction; Term sub[6]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M_PG_Lexical2_s9;
extern int step_M_PG_Lexical2_s9(Sink,Term);

/* FUNCTION Prelude-JoinMappedTextMaps-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_JoinMappedTextMaps struct _Con_M_JoinMappedTextMaps
struct _Con_M_JoinMappedTextMaps {struct _Construction construction; Term sub[2]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M_JoinMappedTextMaps;
extern int step_M_JoinMappedTextMaps(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-DefineSynth-1$CRS-Rules-DefineSynth$1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_DefineSynth_s1 struct _Con_M_CRS_Rules_DefineSynth_s1
struct _Con_M_CRS_Rules_DefineSynth_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_DefineSynth_s1;
extern int step_M_CRS_Rules_DefineSynth_s1(Sink,Term);

/* FUNCTION CookPG-SubRepeat-single HEADER DECLARATIONS. */
#define STRUCT_Con_M_SubRepeat_s13 struct _Con_M_SubRepeat_s13
struct _Con_M_SubRepeat_s13 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SubRepeat_s13;
extern int step_M_SubRepeat_s13(Sink,Term);

/* FUNCTION CookPG-SubRepeat-many-other HEADER DECLARATIONS. */
#define STRUCT_Con_M_SubRepeat_s12 struct _Con_M_SubRepeat_s12
struct _Con_M_SubRepeat_s12 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SubRepeat_s12;
extern int step_M_SubRepeat_s12(Sink,Term);

/* FUNCTION CookPG-SubRepeat-many-other HEADER DECLARATIONS. */
#define STRUCT_Con_M_SubRepeat_s11 struct _Con_M_SubRepeat_s11
struct _Con_M_SubRepeat_s11 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SubRepeat_s11;
extern int step_M_SubRepeat_s11(Sink,Term);

/* FUNCTION CookPG-SubRepeat-many-other HEADER DECLARATIONS. */
#define STRUCT_Con_M_SubRepeat_s10 struct _Con_M_SubRepeat_s10
struct _Con_M_SubRepeat_s10 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SubRepeat_s10;
extern int step_M_SubRepeat_s10(Sink,Term);

/* FUNCTION CookPG-SubRepeat-some-single HEADER DECLARATIONS. */
#define STRUCT_Con_M_SubRepeat_s17 struct _Con_M_SubRepeat_s17
struct _Con_M_SubRepeat_s17 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SubRepeat_s17;
extern int step_M_SubRepeat_s17(Sink,Term);

/* FUNCTION CookBase-BaseSortName2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_BaseSortName2 struct _Con_M_BaseSortName2
struct _Con_M_BaseSortName2 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_BaseSortName2;
extern int step_M_BaseSortName2(Sink,Term);

/* FUNCTION CookPG-SubRepeat-some-many HEADER DECLARATIONS. */
#define STRUCT_Con_M_SubRepeat_s16 struct _Con_M_SubRepeat_s16
struct _Con_M_SubRepeat_s16 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SubRepeat_s16;
extern int step_M_SubRepeat_s16(Sink,Term);

/* FUNCTION CookPG-SubRepeat-some-maybe HEADER DECLARATIONS. */
#define STRUCT_Con_M_SubRepeat_s15 struct _Con_M_SubRepeat_s15
struct _Con_M_SubRepeat_s15 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SubRepeat_s15;
extern int step_M_SubRepeat_s15(Sink,Term);

/* FUNCTION CookPG-SubRepeat-some- HEADER DECLARATIONS. */
#define STRUCT_Con_M_SubRepeat_s14 struct _Con_M_SubRepeat_s14
struct _Con_M_SubRepeat_s14 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SubRepeat_s14;
extern int step_M_SubRepeat_s14(Sink,Term);

/* FUNCTION CookCRS-CRS-Declarations-Synthesized-1$CRS-Declarations-Synthesized$OK HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declarations_Synthesized struct _Con_M_CRS_Declarations_Synthesized
struct _Con_M_CRS_Declarations_Synthesized {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declarations_Synthesized;
extern int step_M_CRS_Declarations_Synthesized(Sink,Term);

/* FUNCTION CookPG-PG-DeclareRegExpChoice-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_DeclareRegExpChoice_s1 struct _Con_M_PG_DeclareRegExpChoice_s1
struct _Con_M_PG_DeclareRegExpChoice_s1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_DeclareRegExpChoice_s1;
extern int step_M_PG_DeclareRegExpChoice_s1(Sink,Term);

/* FUNCTION CookPG-PG-DeclareRegExpChoice-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_DeclareRegExpChoice_s2 struct _Con_M_PG_DeclareRegExpChoice_s2
struct _Con_M_PG_DeclareRegExpChoice_s2 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_DeclareRegExpChoice_s2;
extern int step_M_PG_DeclareRegExpChoice_s2(Sink,Term);

/* FUNCTION CookPG-PG-DeclareRegExpUnits-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_DeclareRegExpUnits_s1 struct _Con_M_PG_DeclareRegExpUnits_s1
struct _Con_M_PG_DeclareRegExpUnits_s1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_DeclareRegExpUnits_s1;
extern int step_M_PG_DeclareRegExpUnits_s1(Sink,Term);

/* FUNCTION CookPG-SubRepeat-some-some HEADER DECLARATIONS. */
#define STRUCT_Con_M_SubRepeat_s18 struct _Con_M_SubRepeat_s18
struct _Con_M_SubRepeat_s18 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SubRepeat_s18;
extern int step_M_SubRepeat_s18(Sink,Term);

/* FUNCTION CookPG-SubRepeat-some-somesep HEADER DECLARATIONS. */
#define STRUCT_Con_M_SubRepeat_s19 struct _Con_M_SubRepeat_s19
struct _Con_M_SubRepeat_s19 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SubRepeat_s19;
extern int step_M_SubRepeat_s19(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-PrecWrapper-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_PrecWrapper_s3 struct _Con_M_CRS_Rules_PrecWrapper_s3
struct _Con_M_CRS_Rules_PrecWrapper_s3 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_PrecWrapper_s3;
extern int step_M_CRS_Rules_PrecWrapper_s3(Sink,Term);

/* FUNCTION CookN-InheritedNames-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_InheritedNames struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_InheritedNames;
extern int step_M_InheritedNames(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-PrecWrapper-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_PrecWrapper_s2 struct _Con_M_CRS_Rules_PrecWrapper_s2
struct _Con_M_CRS_Rules_PrecWrapper_s2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_PrecWrapper_s2;
extern int step_M_CRS_Rules_PrecWrapper_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-PrecWrapper- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules_PrecWrapper_s1 struct _Con_M_CRS_Rules_PrecWrapper_s1
struct _Con_M_CRS_Rules_PrecWrapper_s1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules_PrecWrapper_s1;
extern int step_M_CRS_Rules_PrecWrapper_s1(Sink,Term);

/* FUNCTION CookPG-SubRepeat-somesep-maybe HEADER DECLARATIONS. */
#define STRUCT_Con_M_SubRepeat_s22 struct _Con_M_SubRepeat_s22
struct _Con_M_SubRepeat_s22 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SubRepeat_s22;
extern int step_M_SubRepeat_s22(Sink,Term);

/* FUNCTION CookPG-PG-Lexical2Tail-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Lexical2Tail_s1 struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PG_Lexical2Tail_s1;
extern int step_M_PG_Lexical2Tail_s1(Sink,Term);

/* FUNCTION CookPG-SubRepeat-somesep- HEADER DECLARATIONS. */
#define STRUCT_Con_M_SubRepeat_s21 struct _Con_M_SubRepeat_s21
struct _Con_M_SubRepeat_s21 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SubRepeat_s21;
extern int step_M_SubRepeat_s21(Sink,Term);

/* FUNCTION CookPG-SubRepeat-somesep-single HEADER DECLARATIONS. */
#define STRUCT_Con_M_SubRepeat_s24 struct _Con_M_SubRepeat_s24
struct _Con_M_SubRepeat_s24 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SubRepeat_s24;
extern int step_M_SubRepeat_s24(Sink,Term);

/* FUNCTION CookPG-SubRepeat-somesep-many HEADER DECLARATIONS. */
#define STRUCT_Con_M_SubRepeat_s23 struct _Con_M_SubRepeat_s23
struct _Con_M_SubRepeat_s23 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SubRepeat_s23;
extern int step_M_SubRepeat_s23(Sink,Term);

/* FUNCTION CookPG-PG-Lexical2Tail-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Lexical2Tail_s2 struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_PG_Lexical2Tail_s2;
extern int step_M_PG_Lexical2Tail_s2(Sink,Term);

/* FUNCTION Prelude-TextToString- HEADER DECLARATIONS. */
#define STRUCT_Con_M_TextToString struct _Con_M_TextToString
struct _Con_M_TextToString {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_TextToString;
extern int step_M_TextToString(Sink,Term);

/* FUNCTION CookPG-SubRepeat-somesep- HEADER DECLARATIONS. */
#define STRUCT_Con_M_SubRepeat_s26 struct _Con_M_SubRepeat_s26
struct _Con_M_SubRepeat_s26 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SubRepeat_s26;
extern int step_M_SubRepeat_s26(Sink,Term);

/* FUNCTION CookPG-SubRepeat-somesep-some HEADER DECLARATIONS. */
#define STRUCT_Con_M_SubRepeat_s25 struct _Con_M_SubRepeat_s25
struct _Con_M_SubRepeat_s25 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SubRepeat_s25;
extern int step_M_SubRepeat_s25(Sink,Term);

/* FUNCTION CookPG-SubRepeat-somesep- HEADER DECLARATIONS. */
#define STRUCT_Con_M_SubRepeat_s28 struct _Con_M_SubRepeat_s28
struct _Con_M_SubRepeat_s28 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SubRepeat_s28;
extern int step_M_SubRepeat_s28(Sink,Term);

/* FUNCTION CookCRS-CRS-FormScopeSorts-2$CRS-FormScopeSorts$1$RAW-ScopeSort HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_FormScopeSorts_s1 struct _Con_M_CRS_FormScopeSorts_s1
struct _Con_M_CRS_FormScopeSorts_s1 {struct _Construction construction; Term sub[8]; Variable binder[5];};
extern struct _ConstructionDescriptor descriptor_M_CRS_FormScopeSorts_s1;
extern int step_M_CRS_FormScopeSorts_s1(Sink,Term);

/* FUNCTION CookCRS-IfSortSynthesizes-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_IfSortSynthesizes struct _Con_M_IfSortSynthesizes
struct _Con_M_IfSortSynthesizes {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_IfSortSynthesizes;
extern int step_M_IfSortSynthesizes(Sink,Term);

/* FUNCTION CookCRS-CRS-FormScopeSorts-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_FormScopeSorts_s5 struct _Con_M_CRS_FormScopeSorts_s5
struct _Con_M_CRS_FormScopeSorts_s5 {struct _Construction construction; Term sub[6]; Variable binder[5];};
extern struct _ConstructionDescriptor descriptor_M_CRS_FormScopeSorts_s5;
extern int step_M_CRS_FormScopeSorts_s5(Sink,Term);

/* FUNCTION CookCRS-CRS-FormScopeSorts-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_FormScopeSorts_s4 struct _Con_M_CRS_FormScopeSorts_s4
struct _Con_M_CRS_FormScopeSorts_s4 {struct _Construction construction; Term sub[11]; Variable binder[5];};
extern struct _ConstructionDescriptor descriptor_M_CRS_FormScopeSorts_s4;
extern int step_M_CRS_FormScopeSorts_s4(Sink,Term);

/* FUNCTION CookCRS-CRS-FormScopeSorts-2$CRS-FormScopeSorts$3$RAW-RepeatSingle HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_FormScopeSorts_s3 struct _Con_M_CRS_FormScopeSorts_s3
struct _Con_M_CRS_FormScopeSorts_s3 {struct _Construction construction; Term sub[11]; Variable binder[5];};
extern struct _ConstructionDescriptor descriptor_M_CRS_FormScopeSorts_s3;
extern int step_M_CRS_FormScopeSorts_s3(Sink,Term);

/* FUNCTION CookPG-PG-LeftRecursive- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_LeftRecursive struct _Con_M_PG_LeftRecursive
struct _Con_M_PG_LeftRecursive {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_LeftRecursive;
extern int step_M_PG_LeftRecursive(Sink,Term);

/* FUNCTION CookBase-BaseSortName2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_BaseSortName2_s6 struct _Con_M_BaseSortName2_s6
struct _Con_M_BaseSortName2_s6 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_BaseSortName2_s6;
extern int step_M_BaseSortName2_s6(Sink,Term);

/* FUNCTION CookBase-BaseSortName2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_BaseSortName2_s5 struct _Con_M_BaseSortName2_s5
struct _Con_M_BaseSortName2_s5 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_BaseSortName2_s5;
extern int step_M_BaseSortName2_s5(Sink,Term);

/* FUNCTION CookBase-BaseSortName2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_BaseSortName2_s4 struct _Con_M_BaseSortName2_s4
struct _Con_M_BaseSortName2_s4 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_BaseSortName2_s4;
extern int step_M_BaseSortName2_s4(Sink,Term);

/* FUNCTION CookPG-SameScopeSort2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_SameScopeSort2_s4 struct _Con_M_SameScopeSort2_s4
struct _Con_M_SameScopeSort2_s4 {struct _Construction construction; Term sub[9]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SameScopeSort2_s4;
extern int step_M_SameScopeSort2_s4(Sink,Term);

/* FUNCTION CookPG-SameScopeSort2-1$SameScopeSort2$2$RAW-RepeatSingle HEADER DECLARATIONS. */
#define STRUCT_Con_M_SameScopeSort2_s2 struct _Con_M_SameScopeSort2_s2
struct _Con_M_SameScopeSort2_s2 {struct _Construction construction; Term sub[9]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SameScopeSort2_s2;
extern int step_M_SameScopeSort2_s2(Sink,Term);

/* FUNCTION CookBase-BaseClassOf-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_BaseClassOf struct _Con_M_BaseClassOf
struct _Con_M_BaseClassOf {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_BaseClassOf;
extern int step_M_BaseClassOf(Sink,Term);

/* FUNCTION CookPG-SubRepeat-somesep-string-string HEADER DECLARATIONS. */
#define STRUCT_Con_M_SubRepeat_s29 struct _Con_M_SubRepeat_s29
struct _Con_M_SubRepeat_s29 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SubRepeat_s29;
extern int step_M_SubRepeat_s29(Sink,Term);

/* FUNCTION CookPG-SameScopeSort2-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SameScopeSort2_s8 struct _Con_M_SameScopeSort2_s8
struct _Con_M_SameScopeSort2_s8 {struct _Construction construction; Term sub[10]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SameScopeSort2_s8;
extern int step_M_SameScopeSort2_s8(Sink,Term);

/* FUNCTION CookPG-SameScopeSort2-1$SameScopeSort2$6$RAW-RepeatSingle HEADER DECLARATIONS. */
#define STRUCT_Con_M_SameScopeSort2_s6 struct _Con_M_SameScopeSort2_s6
struct _Con_M_SameScopeSort2_s6 {struct _Construction construction; Term sub[12]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SameScopeSort2_s6;
extern int step_M_SameScopeSort2_s6(Sink,Term);

/* FUNCTION CookPG-SameScopeSort2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SameScopeSort2_s7 struct _Con_M_SameScopeSort2_s7
struct _Con_M_SameScopeSort2_s7 {struct _Construction construction; Term sub[12]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SameScopeSort2_s7;
extern int step_M_SameScopeSort2_s7(Sink,Term);

/* FUNCTION CookBase-BaseSortName2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_BaseSortName2_s3 struct _Con_M_BaseSortName2_s3
struct _Con_M_BaseSortName2_s3 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_BaseSortName2_s3;
extern int step_M_BaseSortName2_s3(Sink,Term);

/* FUNCTION CookBase-BaseSortName2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_BaseSortName2_s2 struct _Con_M_BaseSortName2_s2
struct _Con_M_BaseSortName2_s2 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_BaseSortName2_s2;
extern int step_M_BaseSortName2_s2(Sink,Term);

/* FUNCTION Prelude-ContainsName-1$ContainsName$NAME_SET HEADER DECLARATIONS. */
#define STRUCT_Con_M_ContainsName struct _Con_M_ContainsName
struct _Con_M_ContainsName {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ContainsName;
extern int step_M_ContainsName(Sink,Term);

/* FUNCTION CookBase-BaseSortName2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_BaseSortName2_s1 struct _Con_M_BaseSortName2_s1
struct _Con_M_BaseSortName2_s1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_BaseSortName2_s1;
extern int step_M_BaseSortName2_s1(Sink,Term);

/* FUNCTION Prelude-When-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_When_s1 struct _Con_M_When_s1
struct _Con_M_When_s1 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_When_s1;
extern int step_M_When_s1(Sink,Term);

/* FUNCTION Prelude-FoldNamesWhen-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_FoldNamesWhen struct _Con_M_FoldNamesWhen
struct _Con_M_FoldNamesWhen {struct _Construction construction; Term sub[3]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M_FoldNamesWhen;
extern int step_M_FoldNamesWhen(Sink,Term);

/* FUNCTION CookCRS-CRS-User-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_User struct _Con_M_CRS_User
struct _Con_M_CRS_User {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_User;
extern int step_M_CRS_User(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Rule-1$DerivedSorts-Rule$RAW-Rule HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Rule struct _Con_M_DerivedSorts_Rule
struct _Con_M_DerivedSorts_Rule {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Rule;
extern int step_M_DerivedSorts_Rule(Sink,Term);

/* FUNCTION CookN-KeepSynthesizedEntry2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepSynthesizedEntry2_s3 struct _Con_M_KeepSynthesizedEntry2_s3
struct _Con_M_KeepSynthesizedEntry2_s3 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepSynthesizedEntry2_s3;
extern int step_M_KeepSynthesizedEntry2_s3(Sink,Term);

/* FUNCTION CookN-KeepSynthesizedMapEntry2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepSynthesizedMapEntry2_s8 struct _Con_M_KeepSynthesizedMapEntry2_s8
struct _Con_M_KeepSynthesizedMapEntry2_s8 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepSynthesizedMapEntry2_s8;
extern int step_M_KeepSynthesizedMapEntry2_s8(Sink,Term);

/* FUNCTION CookN-KeepSynthesizedEntry2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepSynthesizedEntry2_s4 struct _Con_M_KeepSynthesizedEntry2_s4
struct _Con_M_KeepSynthesizedEntry2_s4 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepSynthesizedEntry2_s4;
extern int step_M_KeepSynthesizedEntry2_s4(Sink,Term);

/* FUNCTION CookN-KeepSynthesizedMapEntry2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepSynthesizedMapEntry2_s7 struct _Con_M_KeepSynthesizedMapEntry2_s7
struct _Con_M_KeepSynthesizedMapEntry2_s7 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepSynthesizedMapEntry2_s7;
extern int step_M_KeepSynthesizedMapEntry2_s7(Sink,Term);

/* FUNCTION CookN-KeepSynthesizedEntry2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepSynthesizedEntry2_s5 struct _Con_M_KeepSynthesizedEntry2_s5
struct _Con_M_KeepSynthesizedEntry2_s5 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepSynthesizedEntry2_s5;
extern int step_M_KeepSynthesizedEntry2_s5(Sink,Term);

/* FUNCTION CookN-KeepSynthesizedMapEntry2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepSynthesizedMapEntry2_s6 struct _Con_M_KeepSynthesizedMapEntry2_s6
struct _Con_M_KeepSynthesizedMapEntry2_s6 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepSynthesizedMapEntry2_s6;
extern int step_M_KeepSynthesizedMapEntry2_s6(Sink,Term);

/* FUNCTION Prelude-AddNameNumber-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_AddNameNumber struct _Con_M_AddNameNumber
struct _Con_M_AddNameNumber {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_AddNameNumber;
extern int step_M_AddNameNumber(Sink,Term);

/* FUNCTION CookN-KeepSynthesizedEntry2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepSynthesizedEntry2_s6 struct _Con_M_KeepSynthesizedEntry2_s6
struct _Con_M_KeepSynthesizedEntry2_s6 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepSynthesizedEntry2_s6;
extern int step_M_KeepSynthesizedEntry2_s6(Sink,Term);

/* FUNCTION CookN-KeepSynthesizedMapEntry2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepSynthesizedMapEntry2_s5 struct _Con_M_KeepSynthesizedMapEntry2_s5
struct _Con_M_KeepSynthesizedMapEntry2_s5 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepSynthesizedMapEntry2_s5;
extern int step_M_KeepSynthesizedMapEntry2_s5(Sink,Term);

/* FUNCTION CookN-KeepSynthesizedEntry2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepSynthesizedEntry2_s1 struct _Con_M_KeepSynthesizedEntry2_s1
struct _Con_M_KeepSynthesizedEntry2_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepSynthesizedEntry2_s1;
extern int step_M_KeepSynthesizedEntry2_s1(Sink,Term);

/* FUNCTION CookN-KeepSynthesizedEntry2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepSynthesizedEntry2_s2 struct _Con_M_KeepSynthesizedEntry2_s2
struct _Con_M_KeepSynthesizedEntry2_s2 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepSynthesizedEntry2_s2;
extern int step_M_KeepSynthesizedEntry2_s2(Sink,Term);

/* FUNCTION CookN-KeepSynthesizedMapEntry2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepSynthesizedMapEntry2_s9 struct _Con_M_KeepSynthesizedMapEntry2_s9
struct _Con_M_KeepSynthesizedMapEntry2_s9 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepSynthesizedMapEntry2_s9;
extern int step_M_KeepSynthesizedMapEntry2_s9(Sink,Term);

/* FUNCTION CookN-KeepSynthesizedEntry2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepSynthesizedEntry2_s7 struct _Con_M_KeepSynthesizedEntry2_s7
struct _Con_M_KeepSynthesizedEntry2_s7 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepSynthesizedEntry2_s7;
extern int step_M_KeepSynthesizedEntry2_s7(Sink,Term);

/* FUNCTION CookN-KeepSynthesizedMapEntry2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepSynthesizedMapEntry2_s3 struct _Con_M_KeepSynthesizedMapEntry2_s3
struct _Con_M_KeepSynthesizedMapEntry2_s3 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepSynthesizedMapEntry2_s3;
extern int step_M_KeepSynthesizedMapEntry2_s3(Sink,Term);

/* FUNCTION CookN-KeepSynthesizedMapEntry2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepSynthesizedMapEntry2_s2 struct _Con_M_KeepSynthesizedMapEntry2_s2
struct _Con_M_KeepSynthesizedMapEntry2_s2 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepSynthesizedMapEntry2_s2;
extern int step_M_KeepSynthesizedMapEntry2_s2(Sink,Term);

/* FUNCTION CookN-KeepSynthesizedMapEntry2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_KeepSynthesizedMapEntry2_s1 struct _Con_M_KeepSynthesizedMapEntry2_s1
struct _Con_M_KeepSynthesizedMapEntry2_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_KeepSynthesizedMapEntry2_s1;
extern int step_M_KeepSynthesizedMapEntry2_s1(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Terms-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Terms struct _Con_M_DerivedSorts_Terms
struct _Con_M_DerivedSorts_Terms {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Terms;
extern int step_M_DerivedSorts_Terms(Sink,Term);

/* FUNCTION CookCRS-CollectSynthesizedName-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CollectSynthesizedName struct _Con_M_CollectSynthesizedName
struct _Con_M_CollectSynthesizedName {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CollectSynthesizedName;
extern int step_M_CollectSynthesizedName(Sink,Term);

/* FUNCTION CookCRS-CRS-Attributes1-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Attributes1_s1 struct _Con_M_CRS_Attributes1_s1
struct _Con_M_CRS_Attributes1_s1 {struct _Construction construction; Term sub[5]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Attributes1_s1;
extern int step_M_CRS_Attributes1_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-Attributes1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Attributes1_s2 struct _Con_M_CRS_Attributes1_s2
struct _Con_M_CRS_Attributes1_s2 {struct _Construction construction; Term sub[3]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Attributes1_s2;
extern int step_M_CRS_Attributes1_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-Declarations-Define- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declarations_Define struct _Con_M_CRS_Declarations_Define
struct _Con_M_CRS_Declarations_Define {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declarations_Define;
extern int step_M_CRS_Declarations_Define(Sink,Term);

/* FUNCTION CookPG-SamePrec-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SamePrec struct _Con_M_SamePrec
struct _Con_M_SamePrec {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SamePrec;
extern int step_M_SamePrec(Sink,Term);

/* FUNCTION CookBase-SortMetaVar-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortMetaVar struct _Con_M_SortMetaVar
struct _Con_M_SortMetaVar {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortMetaVar;
extern int step_M_SortMetaVar(Sink,Term);

/* FUNCTION CookBase-ParsePrefix-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ParsePrefix struct _Con_M_ParsePrefix
struct _Con_M_ParsePrefix {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ParsePrefix;
extern int step_M_ParsePrefix(Sink,Term);

/* FUNCTION CookBase-ProductionNameWithPrec-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ProductionNameWithPrec struct _Con_M_ProductionNameWithPrec
struct _Con_M_ProductionNameWithPrec {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ProductionNameWithPrec;
extern int step_M_ProductionNameWithPrec(Sink,Term);

/* FUNCTION CookCRS-MapWrapperConstruction- HEADER DECLARATIONS. */
#define STRUCT_Con_M_MapWrapperConstruction_s2 struct _Con_M_MapWrapperConstruction_s2
struct _Con_M_MapWrapperConstruction_s2 {struct _Construction construction; Term sub[5]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M_MapWrapperConstruction_s2;
extern int step_M_MapWrapperConstruction_s2(Sink,Term);

/* FUNCTION Prelude-If-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_If_s1 struct _Con_M_If_s1
struct _Con_M_If_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_If_s1;
extern int step_M_If_s1(Sink,Term);

/* FUNCTION CookCRS-MapWrapperConstruction-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_MapWrapperConstruction_s7 struct _Con_M_MapWrapperConstruction_s7
struct _Con_M_MapWrapperConstruction_s7 {struct _Construction construction; Term sub[4]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M_MapWrapperConstruction_s7;
extern int step_M_MapWrapperConstruction_s7(Sink,Term);

/* FUNCTION Prelude-If-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_If_s2 struct _Con_M_If_s2
struct _Con_M_If_s2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_If_s2;
extern int step_M_If_s2(Sink,Term);

/* FUNCTION CookCRS-MapWrapperConstruction-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_MapWrapperConstruction_s6 struct _Con_M_MapWrapperConstruction_s6
struct _Con_M_MapWrapperConstruction_s6 {struct _Construction construction; Term sub[5]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M_MapWrapperConstruction_s6;
extern int step_M_MapWrapperConstruction_s6(Sink,Term);

/* FUNCTION CookCRS-MapWrapperConstruction-5 HEADER DECLARATIONS. */
#define STRUCT_Con_M_MapWrapperConstruction_s5 struct _Con_M_MapWrapperConstruction_s5
struct _Con_M_MapWrapperConstruction_s5 {struct _Construction construction; Term sub[7]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M_MapWrapperConstruction_s5;
extern int step_M_MapWrapperConstruction_s5(Sink,Term);

/* FUNCTION CookCRS-MapWrapperConstruction- HEADER DECLARATIONS. */
#define STRUCT_Con_M_MapWrapperConstruction_s4 struct _Con_M_MapWrapperConstruction_s4
struct _Con_M_MapWrapperConstruction_s4 {struct _Construction construction; Term sub[6]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M_MapWrapperConstruction_s4;
extern int step_M_MapWrapperConstruction_s4(Sink,Term);

/* FUNCTION CookCRS-MapWrapperConstruction-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_MapWrapperConstruction_s9 struct _Con_M_MapWrapperConstruction_s9
struct _Con_M_MapWrapperConstruction_s9 {struct _Construction construction; Term sub[5]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M_MapWrapperConstruction_s9;
extern int step_M_MapWrapperConstruction_s9(Sink,Term);

/* FUNCTION CookCRS-MapWrapperConstruction-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_MapWrapperConstruction_s8 struct _Con_M_MapWrapperConstruction_s8
struct _Con_M_MapWrapperConstruction_s8 {struct _Construction construction; Term sub[6]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M_MapWrapperConstruction_s8;
extern int step_M_MapWrapperConstruction_s8(Sink,Term);

/* FUNCTION CookN-N-SortAbstractionDefines2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_SortAbstractionDefines2_s1 struct _Con_M_N_SortAbstractionDefines2_s1
struct _Con_M_N_SortAbstractionDefines2_s1 {struct _Construction construction; Term sub[2]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_N_SortAbstractionDefines2_s1;
extern int step_M_N_SortAbstractionDefines2_s1(Sink,Term);

/* FUNCTION CookN-N-SortAbstractionDefines2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_SortAbstractionDefines2_s2 struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_N_SortAbstractionDefines2_s2;
extern int step_M_N_SortAbstractionDefines2_s2(Sink,Term);

/* FUNCTION CookPG-PG-ProduceDerived-1$PG-ProduceDerived$DERIVED HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceDerived struct _Con_M_PG_ProduceDerived
struct _Con_M_PG_ProduceDerived {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceDerived;
extern int step_M_PG_ProduceDerived(Sink,Term);

/* FUNCTION CookBase-CheckString-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CheckString struct _Con_M_CheckString
struct _Con_M_CheckString {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CheckString;
extern int step_M_CheckString(Sink,Term);

/* FUNCTION CookPG-PG-InlineRegExpRangeChar-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_InlineRegExpRangeChar struct _Con_M_PG_InlineRegExpRangeChar
struct _Con_M_PG_InlineRegExpRangeChar {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_InlineRegExpRangeChar;
extern int step_M_PG_InlineRegExpRangeChar(Sink,Term);

/* FUNCTION Prelude-Concat- HEADER DECLARATIONS. */
#define STRUCT_Con_M_Concat_s1 struct _Con_M_Concat_s1
struct _Con_M_Concat_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_Concat_s1;
extern int step_M_Concat_s1(Sink,Term);

/* FUNCTION Prelude-Concat-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_Concat_s2 struct _Con_M_Concat_s2
struct _Con_M_Concat_s2 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_Concat_s2;
extern int step_M_Concat_s2(Sink,Term);

/* FUNCTION Prelude-Concat-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_Concat_s3 struct _Con_M_Concat_s3
struct _Con_M_Concat_s3 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_Concat_s3;
extern int step_M_Concat_s3(Sink,Term);

/* FUNCTION Prelude-Concat-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_Concat_s4 struct _ConstantConstruction
extern struct _ConstructionDescriptor descriptor_M_Concat_s4;
extern int step_M_Concat_s4(Sink,Term);

/* FUNCTION Prelude-TextFoldMap-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_TextFoldMap_s1 struct _Con_M_TextFoldMap_s1
struct _Con_M_TextFoldMap_s1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_TextFoldMap_s1;
extern int step_M_TextFoldMap_s1(Sink,Term);

/* FUNCTION CookCRS-AddTopRefMode- HEADER DECLARATIONS. */
#define STRUCT_Con_M_AddTopRefMode struct _Con_M_AddTopRefMode
struct _Con_M_AddTopRefMode {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_AddTopRefMode;
extern int step_M_AddTopRefMode(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Sort2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Sort2 struct _Con_M_DerivedSorts_Sort2
struct _Con_M_DerivedSorts_Sort2 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Sort2;
extern int step_M_DerivedSorts_Sort2(Sink,Term);

/* FUNCTION CookCRS-CRS-then-Rules-DataSynth-Got-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS__then_Rules_DataSynth_Got_s1 struct _Con_M_CRS__then_Rules_DataSynth_Got_s1
struct _Con_M_CRS__then_Rules_DataSynth_Got_s1 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS__then_Rules_DataSynth_Got_s1;
extern int step_M_CRS__then_Rules_DataSynth_Got_s1(Sink,Term);

/* FUNCTION CookN-DerivedSorts-ScopeSort-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_ScopeSort_s1 struct _Con_M_DerivedSorts_ScopeSort_s1
struct _Con_M_DerivedSorts_ScopeSort_s1 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_ScopeSort_s1;
extern int step_M_DerivedSorts_ScopeSort_s1(Sink,Term);

/* FUNCTION CookN-DerivedSorts-ScopeSort-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_ScopeSort_s2 struct _Con_M_DerivedSorts_ScopeSort_s2
struct _Con_M_DerivedSorts_ScopeSort_s2 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_ScopeSort_s2;
extern int step_M_DerivedSorts_ScopeSort_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-Declarations-Inherited-1$CRS-Declarations-Inherited$OK HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declarations_Inherited struct _Con_M_CRS_Declarations_Inherited
struct _Con_M_CRS_Declarations_Inherited {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declarations_Inherited;
extern int step_M_CRS_Declarations_Inherited(Sink,Term);

/* FUNCTION CookN-_ParsedFormLess-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xParsedFormLess_s1 struct _Con_M__xParsedFormLess_s1
struct _Con_M__xParsedFormLess_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xParsedFormLess_s1;
extern int step_M__xParsedFormLess_s1(Sink,Term);

/* FUNCTION CookN-_ParsedFormLess-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xParsedFormLess_s4 struct _Con_M__xParsedFormLess_s4
struct _Con_M__xParsedFormLess_s4 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xParsedFormLess_s4;
extern int step_M__xParsedFormLess_s4(Sink,Term);

/* FUNCTION CookN-_ParsedFormLess- HEADER DECLARATIONS. */
#define STRUCT_Con_M__xParsedFormLess_s3 struct _Con_M__xParsedFormLess_s3
struct _Con_M__xParsedFormLess_s3 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xParsedFormLess_s3;
extern int step_M__xParsedFormLess_s3(Sink,Term);

/* FUNCTION CookN-_ParsedFormLess-7 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xParsedFormLess_s6 struct _Con_M__xParsedFormLess_s6
struct _Con_M__xParsedFormLess_s6 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xParsedFormLess_s6;
extern int step_M__xParsedFormLess_s6(Sink,Term);

/* FUNCTION CookN-N-LinkDefine-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_LinkDefine struct _Con_M_N_LinkDefine
struct _Con_M_N_LinkDefine {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_LinkDefine;
extern int step_M_N_LinkDefine(Sink,Term);

/* FUNCTION CookN-_ParsedFormLess-7 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xParsedFormLess_s5 struct _Con_M__xParsedFormLess_s5
struct _Con_M__xParsedFormLess_s5 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xParsedFormLess_s5;
extern int step_M__xParsedFormLess_s5(Sink,Term);

/* FUNCTION CookCRS-CRS-ParamPrefix- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_ParamPrefix struct _Con_M_CRS_ParamPrefix
struct _Con_M_CRS_ParamPrefix {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_ParamPrefix;
extern int step_M_CRS_ParamPrefix(Sink,Term);

/* FUNCTION CookBase-SortMetaVar2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortMetaVar2 struct _Con_M_SortMetaVar2
struct _Con_M_SortMetaVar2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortMetaVar2;
extern int step_M_SortMetaVar2(Sink,Term);

/* FUNCTION CookCRS-CRS-then-Rules-DataSynth-Fold-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS__then_Rules_DataSynth_Fold_s1 struct _Con_M_CRS__then_Rules_DataSynth_Fold_s1
struct _Con_M_CRS__then_Rules_DataSynth_Fold_s1 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS__then_Rules_DataSynth_Fold_s1;
extern int step_M_CRS__then_Rules_DataSynth_Fold_s1(Sink,Term);

/* FUNCTION CookPG-SubRepeat-many- HEADER DECLARATIONS. */
#define STRUCT_Con_M_SubRepeat_s7 struct _Con_M_SubRepeat_s7
struct _Con_M_SubRepeat_s7 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SubRepeat_s7;
extern int step_M_SubRepeat_s7(Sink,Term);

/* FUNCTION CookPG-SubRepeat-many-other HEADER DECLARATIONS. */
#define STRUCT_Con_M_SubRepeat_s8 struct _Con_M_SubRepeat_s8
struct _Con_M_SubRepeat_s8 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SubRepeat_s8;
extern int step_M_SubRepeat_s8(Sink,Term);

/* FUNCTION CookN-Then-DerivedSorts2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_Then_DerivedSorts2_s1 struct _Con_M_Then_DerivedSorts2_s1
struct _Con_M_Then_DerivedSorts2_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_Then_DerivedSorts2_s1;
extern int step_M_Then_DerivedSorts2_s1(Sink,Term);

/* FUNCTION CookPG-SubRepeat-maybe-some HEADER DECLARATIONS. */
#define STRUCT_Con_M_SubRepeat_s5 struct _Con_M_SubRepeat_s5
struct _Con_M_SubRepeat_s5 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SubRepeat_s5;
extern int step_M_SubRepeat_s5(Sink,Term);

/* FUNCTION CookPG-SubRepeat-maybe-somesep HEADER DECLARATIONS. */
#define STRUCT_Con_M_SubRepeat_s6 struct _Con_M_SubRepeat_s6
struct _Con_M_SubRepeat_s6 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SubRepeat_s6;
extern int step_M_SubRepeat_s6(Sink,Term);

/* FUNCTION CookPG-SubRepeat-maybe-many HEADER DECLARATIONS. */
#define STRUCT_Con_M_SubRepeat_s3 struct _Con_M_SubRepeat_s3
struct _Con_M_SubRepeat_s3 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SubRepeat_s3;
extern int step_M_SubRepeat_s3(Sink,Term);

/* FUNCTION CookPG-SubRepeat-maybe-single HEADER DECLARATIONS. */
#define STRUCT_Con_M_SubRepeat_s4 struct _Con_M_SubRepeat_s4
struct _Con_M_SubRepeat_s4 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SubRepeat_s4;
extern int step_M_SubRepeat_s4(Sink,Term);

/* FUNCTION Prelude-TextPartToString- HEADER DECLARATIONS. */
#define STRUCT_Con_M_TextPartToString struct _Con_M_TextPartToString
struct _Con_M_TextPartToString {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_TextPartToString;
extern int step_M_TextPartToString(Sink,Term);

/* FUNCTION CookPG-SubRepeat-maybe- HEADER DECLARATIONS. */
#define STRUCT_Con_M_SubRepeat_s1 struct _Con_M_SubRepeat_s1
struct _Con_M_SubRepeat_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SubRepeat_s1;
extern int step_M_SubRepeat_s1(Sink,Term);

/* FUNCTION CookPG-SubRepeat-maybe-maybe HEADER DECLARATIONS. */
#define STRUCT_Con_M_SubRepeat_s2 struct _Con_M_SubRepeat_s2
struct _Con_M_SubRepeat_s2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SubRepeat_s2;
extern int step_M_SubRepeat_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-Forms-AttributeForm-5 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Forms_AttributeForm_s3 struct _Con_M_CRS_Forms_AttributeForm_s3
struct _Con_M_CRS_Forms_AttributeForm_s3 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Forms_AttributeForm_s3;
extern int step_M_CRS_Forms_AttributeForm_s3(Sink,Term);

/* FUNCTION CookCRS-CRS-Forms-AttributeForm-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Forms_AttributeForm_s4 struct _Con_M_CRS_Forms_AttributeForm_s4
struct _Con_M_CRS_Forms_AttributeForm_s4 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Forms_AttributeForm_s4;
extern int step_M_CRS_Forms_AttributeForm_s4(Sink,Term);

/* FUNCTION CookCRS-CRS-Forms-AttributeForm-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Forms_AttributeForm_s5 struct _Con_M_CRS_Forms_AttributeForm_s5
struct _Con_M_CRS_Forms_AttributeForm_s5 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Forms_AttributeForm_s5;
extern int step_M_CRS_Forms_AttributeForm_s5(Sink,Term);

/* FUNCTION Prelude-Special_message-2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_Special_xmessage__2 struct _Con_M_Special_xmessage__2
struct _Con_M_Special_xmessage__2 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_Special_xmessage__2;
extern int step_M_Special_xmessage__2(Sink,Term);

/* FUNCTION CookPG-PG-InlineRegExpClass1-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_InlineRegExpClass1_s1 struct _Con_M_PG_InlineRegExpClass1_s1
struct _Con_M_PG_InlineRegExpClass1_s1 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_InlineRegExpClass1_s1;
extern int step_M_PG_InlineRegExpClass1_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-Forms-AttributeForm- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Forms_AttributeForm_s7 struct _Con_M_CRS_Forms_AttributeForm_s7
struct _Con_M_CRS_Forms_AttributeForm_s7 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Forms_AttributeForm_s7;
extern int step_M_CRS_Forms_AttributeForm_s7(Sink,Term);

/* FUNCTION CookPG-PG-InlineRegExpClass1-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_InlineRegExpClass1_s2 struct _Con_M_PG_InlineRegExpClass1_s2
struct _Con_M_PG_InlineRegExpClass1_s2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_InlineRegExpClass1_s2;
extern int step_M_PG_InlineRegExpClass1_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-Forms-AttributeForm-6 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Forms_AttributeForm_s8 struct _Con_M_CRS_Forms_AttributeForm_s8
struct _Con_M_CRS_Forms_AttributeForm_s8 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Forms_AttributeForm_s8;
extern int step_M_CRS_Forms_AttributeForm_s8(Sink,Term);

/* FUNCTION CookCRS-CRS-Forms-AttributeForm-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Forms_AttributeForm_s9 struct _Con_M_CRS_Forms_AttributeForm_s9
struct _Con_M_CRS_Forms_AttributeForm_s9 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Forms_AttributeForm_s9;
extern int step_M_CRS_Forms_AttributeForm_s9(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Form- HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Form struct _Con_M_DerivedSorts_Form
struct _Con_M_DerivedSorts_Form {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Form;
extern int step_M_DerivedSorts_Form(Sink,Term);

/* FUNCTION CookPG-SubRepeat-many-many HEADER DECLARATIONS. */
#define STRUCT_Con_M_SubRepeat_s9 struct _Con_M_SubRepeat_s9
struct _Con_M_SubRepeat_s9 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SubRepeat_s9;
extern int step_M_SubRepeat_s9(Sink,Term);

/* FUNCTION CookCRS-SynthesizedName-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SynthesizedName struct _Con_M_SynthesizedName
struct _Con_M_SynthesizedName {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SynthesizedName;
extern int step_M_SynthesizedName(Sink,Term);

/* FUNCTION Prelude-TextToString2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_TextToString2 struct _Con_M_TextToString2
struct _Con_M_TextToString2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_TextToString2;
extern int step_M_TextToString2(Sink,Term);

/* FUNCTION CookCRS-CRS-Forms-AttributeForm- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Forms_AttributeForm_s2 struct _Con_M_CRS_Forms_AttributeForm_s2
struct _Con_M_CRS_Forms_AttributeForm_s2 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Forms_AttributeForm_s2;
extern int step_M_CRS_Forms_AttributeForm_s2(Sink,Term);

/* FUNCTION CookN-_DefineWrapperForm-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefineWrapperForm_s3 struct _Con_M__xDefineWrapperForm_s3
struct _Con_M__xDefineWrapperForm_s3 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xDefineWrapperForm_s3;
extern int step_M__xDefineWrapperForm_s3(Sink,Term);

/* FUNCTION CookCRS-CRS-TermConstruction2-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_TermConstruction2_s7 struct _Con_M_CRS_TermConstruction2_s7
struct _Con_M_CRS_TermConstruction2_s7 {struct _Construction construction; Term sub[6]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_TermConstruction2_s7;
extern int step_M_CRS_TermConstruction2_s7(Sink,Term);

/* FUNCTION CookCRS-CRS1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS1 struct _Con_M_CRS1
struct _Con_M_CRS1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS1;
extern int step_M_CRS1(Sink,Term);

/* FUNCTION CookN-_DefineWrapperForm-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefineWrapperForm_s4 struct _Con_M__xDefineWrapperForm_s4
struct _Con_M__xDefineWrapperForm_s4 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xDefineWrapperForm_s4;
extern int step_M__xDefineWrapperForm_s4(Sink,Term);

/* FUNCTION CookCRS-CRS-TermConstruction2-6 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_TermConstruction2_s6 struct _Con_M_CRS_TermConstruction2_s6
struct _Con_M_CRS_TermConstruction2_s6 {struct _Construction construction; Term sub[8]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_TermConstruction2_s6;
extern int step_M_CRS_TermConstruction2_s6(Sink,Term);

/* FUNCTION CookN-_DefineWrapperForm-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefineWrapperForm_s5 struct _Con_M__xDefineWrapperForm_s5
struct _Con_M__xDefineWrapperForm_s5 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xDefineWrapperForm_s5;
extern int step_M__xDefineWrapperForm_s5(Sink,Term);

/* FUNCTION CookCRS-CRS-TermConstruction2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_TermConstruction2_s5 struct _Con_M_CRS_TermConstruction2_s5
struct _Con_M_CRS_TermConstruction2_s5 {struct _Construction construction; Term sub[7]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_TermConstruction2_s5;
extern int step_M_CRS_TermConstruction2_s5(Sink,Term);

/* FUNCTION CookN-_DefineWrapperForm-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefineWrapperForm_s6 struct _Con_M__xDefineWrapperForm_s6
struct _Con_M__xDefineWrapperForm_s6 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xDefineWrapperForm_s6;
extern int step_M__xDefineWrapperForm_s6(Sink,Term);

/* FUNCTION CookCRS-CRS-TermConstruction2-5 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_TermConstruction2_s4 struct _Con_M_CRS_TermConstruction2_s4
struct _Con_M_CRS_TermConstruction2_s4 {struct _Construction construction; Term sub[6]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_TermConstruction2_s4;
extern int step_M_CRS_TermConstruction2_s4(Sink,Term);

/* FUNCTION CookCRS-CRS2-1$CRS2$NSM HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS2 struct _Con_M_CRS2
struct _Con_M_CRS2 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS2;
extern int step_M_CRS2(Sink,Term);

/* FUNCTION CookCRS-CRS-TermConstruction2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_TermConstruction2_s3 struct _Con_M_CRS_TermConstruction2_s3
struct _Con_M_CRS_TermConstruction2_s3 {struct _Construction construction; Term sub[7]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_TermConstruction2_s3;
extern int step_M_CRS_TermConstruction2_s3(Sink,Term);

/* FUNCTION CookCRS-CRS-Form-PatternEnv2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Form_PatternEnv2_s9 struct _Con_M_CRS_Form_PatternEnv2_s9
struct _Con_M_CRS_Form_PatternEnv2_s9 {struct _Construction construction; Term sub[9]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Form_PatternEnv2_s9;
extern int step_M_CRS_Form_PatternEnv2_s9(Sink,Term);

/* FUNCTION CookN-_DefineWrapperForm- HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefineWrapperForm_s1 struct _Con_M__xDefineWrapperForm_s1
struct _Con_M__xDefineWrapperForm_s1 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xDefineWrapperForm_s1;
extern int step_M__xDefineWrapperForm_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-TermConstruction2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_TermConstruction2_s1 struct _Con_M_CRS_TermConstruction2_s1
struct _Con_M_CRS_TermConstruction2_s1 {struct _Construction construction; Term sub[6]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_TermConstruction2_s1;
extern int step_M_CRS_TermConstruction2_s1(Sink,Term);

/* FUNCTION CookN-_DefineWrapperForm-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xDefineWrapperForm_s2 struct _Con_M__xDefineWrapperForm_s2
struct _Con_M__xDefineWrapperForm_s2 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xDefineWrapperForm_s2;
extern int step_M__xDefineWrapperForm_s2(Sink,Term);

/* FUNCTION CookN-Then-DerivedSorts2-1$Then-DerivedSorts2$OK HEADER DECLARATIONS. */
#define STRUCT_Con_M_Then_DerivedSorts2 struct _Con_M_Then_DerivedSorts2
struct _Con_M_Then_DerivedSorts2 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_Then_DerivedSorts2;
extern int step_M_Then_DerivedSorts2(Sink,Term);

/* FUNCTION CookCRS-CRS-Form-PatternEnv2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Form_PatternEnv2_s8 struct _Con_M_CRS_Form_PatternEnv2_s8
struct _Con_M_CRS_Form_PatternEnv2_s8 {struct _Construction construction; Term sub[9]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Form_PatternEnv2_s8;
extern int step_M_CRS_Form_PatternEnv2_s8(Sink,Term);

/* FUNCTION CookCRS-CRS-Form-PatternEnv2-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Form_PatternEnv2_s5 struct _Con_M_CRS_Form_PatternEnv2_s5
struct _Con_M_CRS_Form_PatternEnv2_s5 {struct _Construction construction; Term sub[10]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Form_PatternEnv2_s5;
extern int step_M_CRS_Form_PatternEnv2_s5(Sink,Term);

/* FUNCTION CookCRS-CRS-Form-PatternEnv2-5 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Form_PatternEnv2_s6 struct _Con_M_CRS_Form_PatternEnv2_s6
struct _Con_M_CRS_Form_PatternEnv2_s6 {struct _Construction construction; Term sub[10]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Form_PatternEnv2_s6;
extern int step_M_CRS_Form_PatternEnv2_s6(Sink,Term);

/* FUNCTION CookCRS-CRS-Form-PatternEnv2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Form_PatternEnv2_s4 struct _Con_M_CRS_Form_PatternEnv2_s4
struct _Con_M_CRS_Form_PatternEnv2_s4 {struct _Construction construction; Term sub[10]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Form_PatternEnv2_s4;
extern int step_M_CRS_Form_PatternEnv2_s4(Sink,Term);

/* FUNCTION CookPG-PG-InlineRegExpClass1-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_InlineRegExpClass1_s4 struct _Con_M_PG_InlineRegExpClass1_s4
struct _Con_M_PG_InlineRegExpClass1_s4 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_InlineRegExpClass1_s4;
extern int step_M_PG_InlineRegExpClass1_s4(Sink,Term);

/* FUNCTION CookPG-PG-InlineRegExpClass1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_InlineRegExpClass1_s3 struct _Con_M_PG_InlineRegExpClass1_s3
struct _Con_M_PG_InlineRegExpClass1_s3 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_InlineRegExpClass1_s3;
extern int step_M_PG_InlineRegExpClass1_s3(Sink,Term);

/* FUNCTION CookCRS-CRS-Form-PatternEnv2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Form_PatternEnv2_s2 struct _Con_M_CRS_Form_PatternEnv2_s2
struct _Con_M_CRS_Form_PatternEnv2_s2 {struct _Construction construction; Term sub[8]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Form_PatternEnv2_s2;
extern int step_M_CRS_Form_PatternEnv2_s2(Sink,Term);

/* FUNCTION CookN-N-then-Declarations1-1$N-then-Declarations1$OK HEADER DECLARATIONS. */
#define STRUCT_Con_M_N__then_Declarations1 struct _Con_M_N__then_Declarations1
struct _Con_M_N__then_Declarations1 {struct _Construction construction; Term sub[6]; Variable binder[3];};
extern struct _ConstructionDescriptor descriptor_M_N__then_Declarations1;
extern int step_M_N__then_Declarations1(Sink,Term);

/* FUNCTION CookBase-SortRepeatString-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortRepeatString struct _Con_M_SortRepeatString
struct _Con_M_SortRepeatString {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortRepeatString;
extern int step_M_SortRepeatString(Sink,Term);

/* FUNCTION CookPG-PG-MetaHead- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_MetaHead struct _Con_M_PG_MetaHead
struct _Con_M_PG_MetaHead {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_MetaHead;
extern int step_M_PG_MetaHead(Sink,Term);

/* FUNCTION CookCRS-CRS-then-RepeatRulesSynth-1$CRS-then-RepeatRulesSynth$OK HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS__then_RepeatRulesSynth struct _Con_M_CRS__then_RepeatRulesSynth
struct _Con_M_CRS__then_RepeatRulesSynth {struct _Construction construction; Term sub[10]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS__then_RepeatRulesSynth;
extern int step_M_CRS__then_RepeatRulesSynth(Sink,Term);

/* FUNCTION CookCRS-AddSynthesizedName-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_AddSynthesizedName struct _Con_M_AddSynthesizedName
struct _Con_M_AddSynthesizedName {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_AddSynthesizedName;
extern int step_M_AddSynthesizedName(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Parsed-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Parsed_s3 struct _Con_M_DerivedSorts_Parsed_s3
struct _Con_M_DerivedSorts_Parsed_s3 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Parsed_s3;
extern int step_M_DerivedSorts_Parsed_s3(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Parsed-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Parsed_s2 struct _Con_M_DerivedSorts_Parsed_s2
struct _Con_M_DerivedSorts_Parsed_s2 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Parsed_s2;
extern int step_M_DerivedSorts_Parsed_s2(Sink,Term);

/* FUNCTION CookPG-PG-Productions1- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Productions1 struct _Con_M_PG_Productions1
struct _Con_M_PG_Productions1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_Productions1;
extern int step_M_PG_Productions1(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Parsed-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Parsed_s1 struct _Con_M_DerivedSorts_Parsed_s1
struct _Con_M_DerivedSorts_Parsed_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Parsed_s1;
extern int step_M_DerivedSorts_Parsed_s1(Sink,Term);

/* FUNCTION Prelude-ThenRemoveName-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ThenRemoveName_s1 struct _Con_M_ThenRemoveName_s1
struct _Con_M_ThenRemoveName_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ThenRemoveName_s1;
extern int step_M_ThenRemoveName_s1(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBodyWord1- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBodyWord1_s2 struct _Con_M_PG_ProduceBodyWord1_s2
struct _Con_M_PG_ProduceBodyWord1_s2 {struct _Construction construction; Term sub[11]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBodyWord1_s2;
extern int step_M_PG_ProduceBodyWord1_s2(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBodyWord1-4$PG-ProduceBodyWord1$1$PFK HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBodyWord1_s1 struct _Con_M_PG_ProduceBodyWord1_s1
struct _Con_M_PG_ProduceBodyWord1_s1 {struct _Construction construction; Term sub[10]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBodyWord1_s1;
extern int step_M_PG_ProduceBodyWord1_s1(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBodyWord1-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBodyWord1_s4 struct _Con_M_PG_ProduceBodyWord1_s4
struct _Con_M_PG_ProduceBodyWord1_s4 {struct _Construction construction; Term sub[13]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBodyWord1_s4;
extern int step_M_PG_ProduceBodyWord1_s4(Sink,Term);

/* FUNCTION CookPG-PG2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG2_s1 struct _Con_M_PG2_s1
struct _Con_M_PG2_s1 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG2_s1;
extern int step_M_PG2_s1(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBodyWord1-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBodyWord1_s3 struct _Con_M_PG_ProduceBodyWord1_s3
struct _Con_M_PG_ProduceBodyWord1_s3 {struct _Construction construction; Term sub[11]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBodyWord1_s3;
extern int step_M_PG_ProduceBodyWord1_s3(Sink,Term);

/* FUNCTION CookN-ConstructorScopeSorts-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ConstructorScopeSorts struct _Con_M_ConstructorScopeSorts
struct _Con_M_ConstructorScopeSorts {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ConstructorScopeSorts;
extern int step_M_ConstructorScopeSorts(Sink,Term);

/* FUNCTION CookN-_ParsedFormLess- HEADER DECLARATIONS. */
#define STRUCT_Con_M__xParsedFormLess_s9 struct _Con_M__xParsedFormLess_s9
struct _Con_M__xParsedFormLess_s9 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xParsedFormLess_s9;
extern int step_M__xParsedFormLess_s9(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBodyWord1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBodyWord1_s6 struct _Con_M_PG_ProduceBodyWord1_s6
struct _Con_M_PG_ProduceBodyWord1_s6 {struct _Construction construction; Term sub[13]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBodyWord1_s6;
extern int step_M_PG_ProduceBodyWord1_s6(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBodyWord1-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBodyWord1_s5 struct _Con_M_PG_ProduceBodyWord1_s5
struct _Con_M_PG_ProduceBodyWord1_s5 {struct _Construction construction; Term sub[15]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBodyWord1_s5;
extern int step_M_PG_ProduceBodyWord1_s5(Sink,Term);

/* FUNCTION CookN-_ParsedFormLess-7 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xParsedFormLess_s7 struct _Con_M__xParsedFormLess_s7
struct _Con_M__xParsedFormLess_s7 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M__xParsedFormLess_s7;
extern int step_M__xParsedFormLess_s7(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBodyWord1-5 HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBodyWord1_s7 struct _Con_M_PG_ProduceBodyWord1_s7
struct _Con_M_PG_ProduceBodyWord1_s7 {struct _Construction construction; Term sub[8]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBodyWord1_s7;
extern int step_M_PG_ProduceBodyWord1_s7(Sink,Term);

/* FUNCTION CookPG-PG-ProduceBodyTerm1x- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_ProduceBodyTerm1x struct _Con_M_PG_ProduceBodyTerm1x
struct _Con_M_PG_ProduceBodyTerm1x {struct _Construction construction; Term sub[18]; Variable binder[2];};
extern struct _ConstructionDescriptor descriptor_M_PG_ProduceBodyTerm1x;
extern int step_M_PG_ProduceBodyTerm1x(Sink,Term);

/* FUNCTION CookCRS-CRS-Rule1- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rule1 struct _Con_M_CRS_Rule1
struct _Con_M_CRS_Rule1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rule1;
extern int step_M_CRS_Rule1(Sink,Term);

/* FUNCTION CookCRS-CRS-TermConstruction2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_TermConstruction2_s9 struct _Con_M_CRS_TermConstruction2_s9
struct _Con_M_CRS_TermConstruction2_s9 {struct _Construction construction; Term sub[5]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_TermConstruction2_s9;
extern int step_M_CRS_TermConstruction2_s9(Sink,Term);

/* FUNCTION CookCRS-CRS-FormScopeMetaApplication-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_FormScopeMetaApplication struct _Con_M_CRS_FormScopeMetaApplication
struct _Con_M_CRS_FormScopeMetaApplication {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_FormScopeMetaApplication;
extern int step_M_CRS_FormScopeMetaApplication(Sink,Term);

/* FUNCTION CookCRS-CRS-then-PrintP-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS__then_PrintP_s1 struct _Con_M_CRS__then_PrintP_s1
struct _Con_M_CRS__then_PrintP_s1 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS__then_PrintP_s1;
extern int step_M_CRS__then_PrintP_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-1$CRS$RAW-top-module HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS struct _Con_M_CRS
struct _Con_M_CRS {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS;
extern int step_M_CRS(Sink,Term);

/* FUNCTION CookCRS-CRS-Term-Form-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Term_Form_s1 struct _Con_M_CRS_Term_Form_s1
struct _Con_M_CRS_Term_Form_s1 {struct _Construction construction; Term sub[10]; Variable binder[5];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Term_Form_s1;
extern int step_M_CRS_Term_Form_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-Term-Form-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Term_Form_s2 struct _Con_M_CRS_Term_Form_s2
struct _Con_M_CRS_Term_Form_s2 {struct _Construction construction; Term sub[11]; Variable binder[5];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Term_Form_s2;
extern int step_M_CRS_Term_Form_s2(Sink,Term);

/* FUNCTION Prelude-JoinMappedTextMaps2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_JoinMappedTextMaps2_s2 struct _Con_M_JoinMappedTextMaps2_s2
struct _Con_M_JoinMappedTextMaps2_s2 {struct _Construction construction; Term sub[4]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M_JoinMappedTextMaps2_s2;
extern int step_M_JoinMappedTextMaps2_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-Term-Form-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Term_Form_s3 struct _Con_M_CRS_Term_Form_s3
struct _Con_M_CRS_Term_Form_s3 {struct _Construction construction; Term sub[10]; Variable binder[5];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Term_Form_s3;
extern int step_M_CRS_Term_Form_s3(Sink,Term);

/* FUNCTION Prelude-JoinMappedTextMaps2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_JoinMappedTextMaps2_s1 struct _Con_M_JoinMappedTextMaps2_s1
struct _Con_M_JoinMappedTextMaps2_s1 {struct _Construction construction; Term sub[3]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M_JoinMappedTextMaps2_s1;
extern int step_M_JoinMappedTextMaps2_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-RepeatSort-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_RepeatSort struct _Con_M_CRS_RepeatSort
struct _Con_M_CRS_RepeatSort {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_RepeatSort;
extern int step_M_CRS_RepeatSort(Sink,Term);

/* FUNCTION CookCRS-CRS-then-Rules-DataSynth-It-1$CRS-then-Rules-DataSynth-It$OK HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS__then_Rules_DataSynth_It struct _Con_M_CRS__then_Rules_DataSynth_It
struct _Con_M_CRS__then_Rules_DataSynth_It {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS__then_Rules_DataSynth_It;
extern int step_M_CRS__then_Rules_DataSynth_It(Sink,Term);

/* FUNCTION Prelude-IfEmpty- HEADER DECLARATIONS. */
#define STRUCT_Con_M_IfEmpty struct _Con_M_IfEmpty
struct _Con_M_IfEmpty {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_IfEmpty;
extern int step_M_IfEmpty(Sink,Term);

/* FUNCTION CookCRS-CRS-SynthesizeRule2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_SynthesizeRule2_s6 struct _Con_M_CRS_SynthesizeRule2_s6
struct _Con_M_CRS_SynthesizeRule2_s6 {struct _Construction construction; Term sub[10]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_SynthesizeRule2_s6;
extern int step_M_CRS_SynthesizeRule2_s6(Sink,Term);

/* FUNCTION CookCRS-CRS-SynthesizeRule2-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_SynthesizeRule2_s5 struct _Con_M_CRS_SynthesizeRule2_s5
struct _Con_M_CRS_SynthesizeRule2_s5 {struct _Construction construction; Term sub[11]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_SynthesizeRule2_s5;
extern int step_M_CRS_SynthesizeRule2_s5(Sink,Term);

/* FUNCTION CookPG-PG-MetaTail- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_MetaTail struct _Con_M_PG_MetaTail
struct _Con_M_PG_MetaTail {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_MetaTail;
extern int step_M_PG_MetaTail(Sink,Term);

/* FUNCTION CookN-N-FormInheritedAttributes- HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_FormInheritedAttributes struct _Con_M_N_FormInheritedAttributes
struct _Con_M_N_FormInheritedAttributes {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_FormInheritedAttributes;
extern int step_M_N_FormInheritedAttributes(Sink,Term);

/* FUNCTION CookCRS-CRS-SynthesizeRule2-1$CRS-SynthesizeRule2$1$RAW-Attribute HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_SynthesizeRule2_s1 struct _Con_M_CRS_SynthesizeRule2_s1
struct _Con_M_CRS_SynthesizeRule2_s1 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_SynthesizeRule2_s1;
extern int step_M_CRS_SynthesizeRule2_s1(Sink,Term);

/* FUNCTION CookCRS-CRS-SynthesizeRule2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_SynthesizeRule2_s4 struct _Con_M_CRS_SynthesizeRule2_s4
struct _Con_M_CRS_SynthesizeRule2_s4 {struct _Construction construction; Term sub[10]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_SynthesizeRule2_s4;
extern int step_M_CRS_SynthesizeRule2_s4(Sink,Term);

/* FUNCTION CookCRS-CRS-SynthesizeRule2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_SynthesizeRule2_s3 struct _Con_M_CRS_SynthesizeRule2_s3
struct _Con_M_CRS_SynthesizeRule2_s3 {struct _Construction construction; Term sub[9]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_SynthesizeRule2_s3;
extern int step_M_CRS_SynthesizeRule2_s3(Sink,Term);

/* FUNCTION CookN-_InsertSynthesizedRefs1- HEADER DECLARATIONS. */
#define STRUCT_Con_M__xInsertSynthesizedRefs1 struct _Con_M__xInsertSynthesizedRefs1
struct _Con_M__xInsertSynthesizedRefs1 {struct _Construction construction; Term sub[4]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M__xInsertSynthesizedRefs1;
extern int step_M__xInsertSynthesizedRefs1(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Term-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Term_s10 struct _Con_M_DerivedSorts_Term_s10
struct _Con_M_DerivedSorts_Term_s10 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Term_s10;
extern int step_M_DerivedSorts_Term_s10(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Term-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Term_s11 struct _Con_M_DerivedSorts_Term_s11
struct _Con_M_DerivedSorts_Term_s11 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Term_s11;
extern int step_M_DerivedSorts_Term_s11(Sink,Term);

/* FUNCTION CookCRS-CRS-Binders-SubstituteSorts- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Binders_SubstituteSorts struct _Con_M_CRS_Binders_SubstituteSorts
struct _Con_M_CRS_Binders_SubstituteSorts {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Binders_SubstituteSorts;
extern int step_M_CRS_Binders_SubstituteSorts(Sink,Term);

/* FUNCTION CookBase-SortMetaVar2-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortMetaVar2_s11 struct _Con_M_SortMetaVar2_s11
struct _Con_M_SortMetaVar2_s11 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortMetaVar2_s11;
extern int step_M_SortMetaVar2_s11(Sink,Term);

/* FUNCTION CookBase-SortMetaVar2-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortMetaVar2_s10 struct _Con_M_SortMetaVar2_s10
struct _Con_M_SortMetaVar2_s10 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortMetaVar2_s10;
extern int step_M_SortMetaVar2_s10(Sink,Term);

/* FUNCTION CookCRS-CRS-Rules-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Rules struct _Con_M_CRS_Rules
struct _Con_M_CRS_Rules {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Rules;
extern int step_M_CRS_Rules(Sink,Term);

/* FUNCTION CookPG-PG-Production-Defines- HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_Production_Defines struct _Con_M_PG_Production_Defines
struct _Con_M_PG_Production_Defines {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_Production_Defines;
extern int step_M_PG_Production_Defines(Sink,Term);

/* FUNCTION CookN-_InsertSynthesizedRefs2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M__xInsertSynthesizedRefs2 struct _Con_M__xInsertSynthesizedRefs2
struct _Con_M__xInsertSynthesizedRefs2 {struct _Construction construction; Term sub[3]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M__xInsertSynthesizedRefs2;
extern int step_M__xInsertSynthesizedRefs2(Sink,Term);

/* FUNCTION CookCRS-CRS-Parsed2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Parsed2 struct _Con_M_CRS_Parsed2
struct _Con_M_CRS_Parsed2 {struct _Construction construction; Term sub[5]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Parsed2;
extern int step_M_CRS_Parsed2(Sink,Term);

/* FUNCTION CookN-ConstructorScopeSorts2-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ConstructorScopeSorts2_s5 struct _Con_M_ConstructorScopeSorts2_s5
struct _Con_M_ConstructorScopeSorts2_s5 {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ConstructorScopeSorts2_s5;
extern int step_M_ConstructorScopeSorts2_s5(Sink,Term);

/* FUNCTION CookCRS-CRS-Declarations-DefineSynth-1$CRS-Declarations-DefineSynth$1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declarations_DefineSynth_s1 struct _Con_M_CRS_Declarations_DefineSynth_s1
struct _Con_M_CRS_Declarations_DefineSynth_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declarations_DefineSynth_s1;
extern int step_M_CRS_Declarations_DefineSynth_s1(Sink,Term);

/* FUNCTION CookN-ConstructorScopeSorts2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ConstructorScopeSorts2_s2 struct _Con_M_ConstructorScopeSorts2_s2
struct _Con_M_ConstructorScopeSorts2_s2 {struct _Construction construction; Term sub[4]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M_ConstructorScopeSorts2_s2;
extern int step_M_ConstructorScopeSorts2_s2(Sink,Term);

/* FUNCTION CookN-ConstructorScopeSorts2- HEADER DECLARATIONS. */
#define STRUCT_Con_M_ConstructorScopeSorts2_s1 struct _Con_M_ConstructorScopeSorts2_s1
struct _Con_M_ConstructorScopeSorts2_s1 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ConstructorScopeSorts2_s1;
extern int step_M_ConstructorScopeSorts2_s1(Sink,Term);

/* FUNCTION Prelude-Concat- HEADER DECLARATIONS. */
#define STRUCT_Con_M_Concat struct _Con_M_Concat
struct _Con_M_Concat {struct _Construction construction; Term sub[1]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_Concat;
extern int step_M_Concat(Sink,Term);

/* FUNCTION CookN-ConstructorScopeSorts2-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ConstructorScopeSorts2_s4 struct _Con_M_ConstructorScopeSorts2_s4
struct _Con_M_ConstructorScopeSorts2_s4 {struct _Construction construction; Term sub[6]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ConstructorScopeSorts2_s4;
extern int step_M_ConstructorScopeSorts2_s4(Sink,Term);

/* FUNCTION CookN-ConstructorScopeSorts2-4 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ConstructorScopeSorts2_s3 struct _Con_M_ConstructorScopeSorts2_s3
struct _Con_M_ConstructorScopeSorts2_s3 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ConstructorScopeSorts2_s3;
extern int step_M_ConstructorScopeSorts2_s3(Sink,Term);

/* FUNCTION CookCRS-CRS-Parsed1-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Parsed1 struct _Con_M_CRS_Parsed1
struct _Con_M_CRS_Parsed1 {struct _Construction construction; Term sub[7]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Parsed1;
extern int step_M_CRS_Parsed1(Sink,Term);

/* FUNCTION CookCRS-CRS-Declarations-DefineSynth-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declarations_DefineSynth_s4 struct _Con_M_CRS_Declarations_DefineSynth_s4
struct _Con_M_CRS_Declarations_DefineSynth_s4 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declarations_DefineSynth_s4;
extern int step_M_CRS_Declarations_DefineSynth_s4(Sink,Term);

/* FUNCTION CookCRS-CRS-Declarations-DefineSynth-1$CRS-Declarations-DefineSynth$3$NAMES HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Declarations_DefineSynth_s3 struct _Con_M_CRS_Declarations_DefineSynth_s3
struct _Con_M_CRS_Declarations_DefineSynth_s3 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Declarations_DefineSynth_s3;
extern int step_M_CRS_Declarations_DefineSynth_s3(Sink,Term);

/* FUNCTION CookPG-SameSort2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SameSort2_s11 struct _Con_M_SameSort2_s11
struct _Con_M_SameSort2_s11 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SameSort2_s11;
extern int step_M_SameSort2_s11(Sink,Term);

/* FUNCTION CookPG-SameSort2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SameSort2_s12 struct _Con_M_SameSort2_s12
struct _Con_M_SameSort2_s12 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SameSort2_s12;
extern int step_M_SameSort2_s12(Sink,Term);

/* FUNCTION CookPG-SameSort2-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SameSort2_s10 struct _Con_M_SameSort2_s10
struct _Con_M_SameSort2_s10 {struct _Construction construction; Term sub[7]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SameSort2_s10;
extern int step_M_SameSort2_s10(Sink,Term);

/* FUNCTION CookN-DerivedSorts-Term- HEADER DECLARATIONS. */
#define STRUCT_Con_M_DerivedSorts_Term struct _Con_M_DerivedSorts_Term
struct _Con_M_DerivedSorts_Term {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_DerivedSorts_Term;
extern int step_M_DerivedSorts_Term(Sink,Term);

/* FUNCTION CookPG-VariableMarker-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_VariableMarker struct _Con_M_VariableMarker
struct _Con_M_VariableMarker {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_VariableMarker;
extern int step_M_VariableMarker(Sink,Term);

/* FUNCTION CookCRS-CRS-Attributes-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Attributes_s2 struct _Con_M_CRS_Attributes_s2
struct _Con_M_CRS_Attributes_s2 {struct _Construction construction; Term sub[5]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Attributes_s2;
extern int step_M_CRS_Attributes_s2(Sink,Term);

/* FUNCTION CookCRS-CRS-Attributes-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Attributes_s3 struct _Con_M_CRS_Attributes_s3
struct _Con_M_CRS_Attributes_s3 {struct _Construction construction; Term sub[5]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Attributes_s3;
extern int step_M_CRS_Attributes_s3(Sink,Term);

/* FUNCTION CookCRS-CRS-Attributes- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Attributes_s1 struct _Con_M_CRS_Attributes_s1
struct _Con_M_CRS_Attributes_s1 {struct _Construction construction; Term sub[6]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Attributes_s1;
extern int step_M_CRS_Attributes_s1(Sink,Term);

/* FUNCTION CookPG-SameSort2-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SameSort2_s13 struct _Con_M_SameSort2_s13
struct _Con_M_SameSort2_s13 {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SameSort2_s13;
extern int step_M_SameSort2_s13(Sink,Term);

/* FUNCTION CookPG-PG-InlineRegExpUnit-3$PG-InlineRegExpUnit$RAW-RegExpUnit HEADER DECLARATIONS. */
#define STRUCT_Con_M_PG_InlineRegExpUnit struct _Con_M_PG_InlineRegExpUnit
struct _Con_M_PG_InlineRegExpUnit {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_PG_InlineRegExpUnit;
extern int step_M_PG_InlineRegExpUnit(Sink,Term);

/* FUNCTION CookN-N-SortAbstractionDefines-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_SortAbstractionDefines_s1 struct _Con_M_N_SortAbstractionDefines_s1
struct _Con_M_N_SortAbstractionDefines_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_N_SortAbstractionDefines_s1;
extern int step_M_N_SortAbstractionDefines_s1(Sink,Term);

/* FUNCTION CookN-N-SortAbstractionDefines-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_N_SortAbstractionDefines_s2 struct _Con_M_N_SortAbstractionDefines_s2
struct _Con_M_N_SortAbstractionDefines_s2 {struct _Construction construction; Term sub[2]; Variable binder[1];};
extern struct _ConstructionDescriptor descriptor_M_N_SortAbstractionDefines_s2;
extern int step_M_N_SortAbstractionDefines_s2(Sink,Term);

/* FUNCTION CookN-Then-DerivedSorts-Defines-1$Then-DerivedSorts-Defines$OK HEADER DECLARATIONS. */
#define STRUCT_Con_M_Then_DerivedSorts_Defines struct _Con_M_Then_DerivedSorts_Defines
struct _Con_M_Then_DerivedSorts_Defines {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_Then_DerivedSorts_Defines;
extern int step_M_Then_DerivedSorts_Defines(Sink,Term);

/* FUNCTION CookBase-SortNameWithRepeat-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_SortNameWithRepeat struct _Con_M_SortNameWithRepeat
struct _Con_M_SortNameWithRepeat {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_SortNameWithRepeat;
extern int step_M_SortNameWithRepeat(Sink,Term);

/* FUNCTION CookCRS-CRS-Forms-AttributeForm- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Forms_AttributeForm struct _Con_M_CRS_Forms_AttributeForm
struct _Con_M_CRS_Forms_AttributeForm {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Forms_AttributeForm;
extern int step_M_CRS_Forms_AttributeForm(Sink,Term);

/* FUNCTION CookN-ThenRemoveAttributeName-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_ThenRemoveAttributeName_s2 struct _Con_M_ThenRemoveAttributeName_s2
struct _Con_M_ThenRemoveAttributeName_s2 {struct _Construction construction; Term sub[5]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ThenRemoveAttributeName_s2;
extern int step_M_ThenRemoveAttributeName_s2(Sink,Term);

/* FUNCTION Prelude-IfEmpty-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_IfEmpty_s1 struct _Con_M_IfEmpty_s1
struct _Con_M_IfEmpty_s1 {struct _Construction construction; Term sub[4]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_IfEmpty_s1;
extern int step_M_IfEmpty_s1(Sink,Term);

/* FUNCTION CookN-ThenRemoveAttributeName-1$ThenRemoveAttributeName$1$RAW-Attribute HEADER DECLARATIONS. */
#define STRUCT_Con_M_ThenRemoveAttributeName_s1 struct _Con_M_ThenRemoveAttributeName_s1
struct _Con_M_ThenRemoveAttributeName_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_ThenRemoveAttributeName_s1;
extern int step_M_ThenRemoveAttributeName_s1(Sink,Term);

/* FUNCTION Prelude-IfEmpty-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_IfEmpty_s2 struct _Con_M_IfEmpty_s2
struct _Con_M_IfEmpty_s2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_IfEmpty_s2;
extern int step_M_IfEmpty_s2(Sink,Term);

/* FUNCTION CookN-Then-DerivedSorts-Term-1$Then-DerivedSorts-Term$OK HEADER DECLARATIONS. */
#define STRUCT_Con_M_Then_DerivedSorts_Term struct _Con_M_Then_DerivedSorts_Term
struct _Con_M_Then_DerivedSorts_Term {struct _Construction construction; Term sub[3]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_Then_DerivedSorts_Term;
extern int step_M_Then_DerivedSorts_Term(Sink,Term);

/* FUNCTION CookCRS-CRS-Parsed-In- HEADER DECLARATIONS. */
#define STRUCT_Con_M_CRS_Parsed_In struct _Con_M_CRS_Parsed_In
struct _Con_M_CRS_Parsed_In {struct _Construction construction; Term sub[4]; Variable binder[4];};
extern struct _ConstructionDescriptor descriptor_M_CRS_Parsed_In;
extern int step_M_CRS_Parsed_In(Sink,Term);

/* FUNCTION CookCRS-IfRefModeHides-3 HEADER DECLARATIONS. */
#define STRUCT_Con_M_IfRefModeHides_s1 struct _Con_M_IfRefModeHides_s1
struct _Con_M_IfRefModeHides_s1 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_IfRefModeHides_s1;
extern int step_M_IfRefModeHides_s1(Sink,Term);

/* FUNCTION CookCRS-IfRefModeHides-2 HEADER DECLARATIONS. */
#define STRUCT_Con_M_IfRefModeHides_s3 struct _Con_M_IfRefModeHides_s3
struct _Con_M_IfRefModeHides_s3 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_IfRefModeHides_s3;
extern int step_M_IfRefModeHides_s3(Sink,Term);

/* FUNCTION CookCRS-IfRefModeHides-1 HEADER DECLARATIONS. */
#define STRUCT_Con_M_IfRefModeHides_s2 struct _Con_M_IfRefModeHides_s2
struct _Con_M_IfRefModeHides_s2 {struct _Construction construction; Term sub[2]; Variable binder[0];};
extern struct _ConstructionDescriptor descriptor_M_IfRefModeHides_s2;
extern int step_M_IfRefModeHides_s2(Sink,Term);

#ifdef __cplusplus
}
#endif
/* END OF C HEADER FOR CRSX Cook MODULE . */
#endif

