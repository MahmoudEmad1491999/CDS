// Header guard to prevent multiple inclusions of this header file.
// This ensures that the contents of the file are only included once during compilation.
#if !defined(ARRAYLIST_CALLOUT_H)
#define ARRAYLIST_CALLOUT_H

// Include the ArrayList header file, which likely contains the definition of the ArrayList structure
// and related functions.
#include "ArrayList.h"

// Function declarations for failure callouts related to ArrayList operations.
// These functions are likely used to handle errors or failures in ArrayList operations.

// Called when creating an ArrayList fails (e.g., memory allocation failure).
void CreateArrayList_Failure_Callout();

// Called when freeing an ArrayList fails (e.g., invalid pointer or double-free).
void FreeArrayList_Failure_Callout();

// Called when appending an element to the ArrayList fails (e.g., resizing failure).
void ArrayList_Append_Failure_Callout();

// Called when inserting an element into the ArrayList fails (e.g., invalid index or resizing failure).
void ArrayList_Insert_Failure_Callout();

// Called when removing elements from the ArrayList based on a predicate fails (e.g., invalid predicate or memory issues).
void ArrayList_Remove_By_Predicate_Failure_Callout();

// Called when removing an element from the ArrayList by index fails (e.g., invalid index or memory issues).
void ArrayList_Remove_By_Index_Failure_Callout();

// Called when replacing an element in the ArrayList fails (e.g., invalid index or memory issues).
void ArrayList_Replace_Failure_Callout();

// Called when retrieving an element from the ArrayList fails (e.g., invalid index).
void ArrayList_Get_Failure_Callout();

// Called when getting the size of the ArrayList fails (e.g., invalid ArrayList pointer).
void ArrayList_Size_Failure_Callout();

// Called when checking if the ArrayList is empty fails (e.g., invalid ArrayList pointer).
void ArrayList_IsEmpty_Failure_Callout();

// Called when removing all elements from the ArrayList fails (e.g., memory issues).
void ArrayList_RemoveAll_Failure_Callout();

// Called when checking if the ArrayList contains a specific element fails (e.g., invalid ArrayList pointer).
void ArrayList_Contains_Failure_Callout();

// Called when finding the index of a specific element in the ArrayList fails (e.g., invalid ArrayList pointer).
void ArrayList_IndexOf_Failure_Callout();

// Called when finding the last index of a specific element in the ArrayList fails (e.g., invalid ArrayList pointer).
void ArrayList_LastIndexOf_Failure_Callout();

// Called when doubling the size of the ArrayList fails (e.g., memory allocation failure).
void ArrayList_DoubleSize_Failure_Callout();

// End of the header guard.
#endif // ARRAYLIST_CALLOUT_H