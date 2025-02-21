#if !defined(ARRAYLIST_TYPES_H)
#define ARRAYLIST_TYPES_H
#include "std_types.h"
#include "ArrayList_Cfg.h"

typedef struct
{
    ARRAYLIST_ELEMENT_DATATYPE* list;
    ARRAYLIST_LENGTH_DATATYPE len;
    ARRAYLIST_LENGTH_DATATYPE size;
    ARRAYLIST_FREE_FUNCTION_POINTER_DATATYPE freeFunc;
} ArrayList;


#endif // ARRAYLIST_TYPES_H
