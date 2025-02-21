// Types header for the ArrayList implementation.
// This file defines the structure and types used by the ArrayList.
// It builds on the configuration defined in `ArrayList_Cfg.h`.

// Header guard to prevent multiple inclusions of this header file.
#if !defined(ARRAYLIST_TYPES_H)
#define ARRAYLIST_TYPES_H

// Include the standard types header file, which defines basic data types like int32, int8, etc.
#include "std_types.h"

// Include the ArrayList configuration header file, which defines data types, constants, and function pointers.
#include "ArrayList_Cfg.h"

// Define the ArrayList structure.
// This structure represents a dynamic array that can grow as needed.
typedef struct {
    // Pointer to the dynamically allocated array of elements.
    // The elements are of type `ARRAYLIST_ELEMENT_DATATYPE` (void*), allowing the ArrayList to store any data type.
    ARRAYLIST_ELEMENT_DATATYPE* list;

    // Current number of elements in the ArrayList.
    // This is of type `ARRAYLIST_LENGTH_DATATYPE` (int32), ensuring it can represent the size of the list.
    ARRAYLIST_LENGTH_DATATYPE len;

    // Current capacity of the ArrayList (total allocated memory in terms of number of elements).
    // This is of type `ARRAYLIST_LENGTH_DATATYPE` (int32), ensuring it can represent the size of the allocated memory.
    ARRAYLIST_LENGTH_DATATYPE size;

    // Function pointer for freeing elements when the ArrayList is destroyed or elements are removed.
    // This allows custom cleanup logic for elements, especially useful when elements are dynamically allocated.
    // If NULL, no cleanup is performed for elements.
    ARRAYLIST_FREE_FUNCTION_POINTER_DATATYPE freeFunc;
} ArrayList;

// End of the header guard.
#endif // ARRAYLIST_TYPES_H