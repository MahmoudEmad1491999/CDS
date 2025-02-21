#if !defined(ARRAYLIST_H)
#define ARRAYLIST_H
#include "std_types.h"
#include "ArrayList_Types.h"
#include "ArrayList_Cfg.h"

ArrayList* CreateArrayList();
void FreeArrayList(ArrayList*);
void ArrayList_Append(ArrayList*, ARRAYLIST_ELEMENT_DATATYPE);
void ArrayList_Insert(ArrayList*, ARRAYLIST_ELEMENT_DATATYPE, ARRAYLIST_INDEX_DATATYPE);
void ArrayList_Remove_By_Predicate(ArrayList*, ARRAYLIST_PREDICATE_FUNCTION);
void ArrayList_Remove_By_Index(ArrayList*, ARRAYLIST_INDEX_DATATYPE);
void ArrayList_Replace(ArrayList*, ARRAYLIST_INDEX_DATATYPE, ARRAYLIST_ELEMENT_DATATYPE);
void ArrayList_Get(ArrayList*, ARRAYLIST_INDEX_DATATYPE);
ARRAYLIST_LENGTH_DATATYPE ArrayList_Size(ArrayList*);
int8 ArrayList_IsEmpty(ArrayList*);
void ArrayList_RemoveAll(ArrayList*);
int8 ArrayList_Contains(ArrayList*, ARRAYLIST_ELEMENT_DATATYPE, ARRAYLIST_COMPARATOR_FUNCTION);
ARRAYLIST_INDEX_DATATYPE ArrayList_IndexOf(ArrayList*, ARRAYLIST_ELEMENT_DATATYPE, ARRAYLIST_COMPARATOR_FUNCTION);
void ArrayList_LastIndexOf(ArrayList*, ARRAYLIST_ELEMENT_DATATYPE, ARRAYLIST_COMPARATOR_FUNCTION);

#endif // ARRAYLIST_H
