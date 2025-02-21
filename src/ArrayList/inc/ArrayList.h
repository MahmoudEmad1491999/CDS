// Main header file for the ArrayList implementation.
// This file declares the public API for the ArrayList, including functions for creating,
// manipulating, and querying the ArrayList.

// Header guard to prevent multiple inclusions of this header file.
#if !defined(ARRAYLIST_H)
#define ARRAYLIST_H

// Include the standard types header file, which defines basic data types like int32, int8, etc.
#include "std_types.h"

// Include the ArrayList types header file, which defines the ArrayList structure and related types.
#include "ArrayList_Types.h"

// Include the ArrayList configuration header file, which defines data types, constants, and function pointers.
#include "ArrayList_Cfg.h"

// Function to create a new ArrayList.
// Parameters:
//   - freeFunc: A function pointer to the custom free function for elements.
//               If NULL, no cleanup is performed for elements.
// Returns:
//   - A pointer to the newly created ArrayList.
//   - NULL if memory allocation fails.
ArrayList* CreateArrayList(ARRAYLIST_LENGTH_DATATYPE size, ARRAYLIST_FREE_FUNCTION_POINTER_DATATYPE freeFunc);

// Function to free an ArrayList and its elements.
// Parameters:
//   - arrayList: A pointer to the ArrayList to be freed.
// If a free function is provided in the ArrayList, it will be used to free each element.
void FreeArrayList(ArrayList* arrayList);

// Function to append an element to the end of the ArrayList.
// Parameters:
//   - arrayList: A pointer to the ArrayList.
//   - ele: The element to append.
void ArrayList_Append(ArrayList* arrayList, ARRAYLIST_ELEMENT_DATATYPE ele);

// Function to insert an element at a specific index in the ArrayList.
// Parameters:
//   - arrayList: A pointer to the ArrayList.
//   - ele: The element to insert.
//   - index: The index at which to insert the element.
void ArrayList_Insert(ArrayList* arrayList, ARRAYLIST_ELEMENT_DATATYPE ele, ARRAYLIST_INDEX_DATATYPE index);

// Function to remove elements from the ArrayList that satisfy a given predicate.
// Parameters:
//   - arrayList: A pointer to the ArrayList.
//   - predicate: A function pointer to the predicate function.
void ArrayList_Remove_By_Predicate(ArrayList* arrayList, ARRAYLIST_PREDICATE_FUNCTION predicate);

// Function to remove an element at a specific index from the ArrayList.
// Parameters:
//   - arrayList: A pointer to the ArrayList.
//   - index: The index of the element to remove.
void ArrayList_Remove_By_Index(ArrayList* arrayList, ARRAYLIST_INDEX_DATATYPE index);

// Function to replace an element at a specific index in the ArrayList.
// Parameters:
//   - arrayList: A pointer to the ArrayList.
//   - index: The index of the element to replace.
//   - ele: The new element.
void ArrayList_Replace(ArrayList* arrayList, ARRAYLIST_INDEX_DATATYPE index, ARRAYLIST_ELEMENT_DATATYPE ele);

// Function to get an element at a specific index from the ArrayList.
// Parameters:
//   - arrayList: A pointer to the ArrayList.
//   - index: The index of the element to retrieve.
// Returns:
//   - The element at the specified index.
//   - NULL if the index is out of bounds.
ARRAYLIST_ELEMENT_DATATYPE ArrayList_Get(ArrayList* arrayList, ARRAYLIST_INDEX_DATATYPE index);

// Function to get the current number of elements in the ArrayList.
// Parameters:
//   - arrayList: A pointer to the ArrayList.
// Returns:
//   - The number of elements in the ArrayList.
ARRAYLIST_LENGTH_DATATYPE ArrayList_Size(ArrayList* arrayList);

// Function to check if the ArrayList is empty.
// Parameters:
//   - arrayList: A pointer to the ArrayList.
// Returns:
//   - ARRAYLIST_TRUE if the ArrayList is empty.
//   - ARRAYLIST_FALSE otherwise.
int8 ArrayList_IsEmpty(ArrayList* arrayList);

// Function to remove all elements from the ArrayList.
// Parameters:
//   - arrayList: A pointer to the ArrayList.
void ArrayList_RemoveAll(ArrayList* arrayList);

// Function to check if the ArrayList contains a specific element.
// Parameters:
//   - arrayList: A pointer to the ArrayList.
//   - ele: The element to search for.
//   - comparator: A function pointer to the comparator function.
// Returns:
//   - ARRAYLIST_TRUE if the element is found.
//   - ARRAYLIST_FALSE otherwise.
int8 ArrayList_Contains(ArrayList* arrayList, ARRAYLIST_ELEMENT_DATATYPE ele, ARRAYLIST_COMPARATOR_FUNCTION comparator);

// Function to find the index of the first occurrence of a specific element in the ArrayList.
// Parameters:
//   - arrayList: A pointer to the ArrayList.
//   - ele: The element to search for.
//   - comparator: A function pointer to the comparator function.
// Returns:
//   - The index of the first occurrence of the element.
//   - ARRAYLIST_NONEXISTENT_INDEX if the element is not found.
ARRAYLIST_INDEX_DATATYPE ArrayList_IndexOf(ArrayList* arrayList, ARRAYLIST_ELEMENT_DATATYPE ele, ARRAYLIST_COMPARATOR_FUNCTION comparator);

// Function to find the index of the last occurrence of a specific element in the ArrayList.
// Parameters:
//   - arrayList: A pointer to the ArrayList.
//   - ele: The element to search for.
//   - comparator: A function pointer to the comparator function.
// Returns:
//   - The index of the last occurrence of the element.
//   - ARRAYLIST_NONEXISTENT_INDEX if the element is not found.
ARRAYLIST_INDEX_DATATYPE ArrayList_LastIndexOf(ArrayList* arrayList, ARRAYLIST_ELEMENT_DATATYPE ele, ARRAYLIST_COMPARATOR_FUNCTION comparator);

// End of the header guard.
#endif // ARRAYLIST_H