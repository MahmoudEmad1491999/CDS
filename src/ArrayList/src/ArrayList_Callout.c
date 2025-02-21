#include "ArrayList_Callout.h"
#include <stdio.h>
#include <stdlib.h>

// Called when creating an ArrayList fails (e.g., memory allocation failure).
void CreateArrayList_Failure_Callout() {
    printf("CreateArrayList_Failure_Callout: Failed to create ArrayList (memory allocation error).\n");
    exit(-1); // Exit the program with an error code.
}

// Called when freeing an ArrayList fails (e.g., invalid pointer or double-free).
void FreeArrayList_Failure_Callout() {
    printf("FreeArrayList_Failure_Callout: Failed to free ArrayList (invalid pointer or double-free).\n");
    exit(-1); // Exit the program with an error code.
}

// Called when appending an element to the ArrayList fails (e.g., resizing failure).
void ArrayList_Append_Failure_Callout() {
    printf("ArrayList_Append_Failure_Callout: Failed to append element (resizing error).\n");
    exit(-1); // Exit the program with an error code.
}

// Called when inserting an element into the ArrayList fails (e.g., invalid index or resizing failure).
void ArrayList_Insert_Failure_Callout() {
    printf("ArrayList_Insert_Failure_Callout: Failed to insert element (invalid index or resizing error).\n");
    exit(-1); // Exit the program with an error code.
}

// Called when removing elements from the ArrayList based on a predicate fails (e.g., invalid predicate or memory issues).
void ArrayList_Remove_By_Predicate_Failure_Callout() {
    printf("ArrayList_Remove_By_Predicate_Failure_Callout: Failed to remove elements (predicate error).\n");
    exit(-1); // Exit the program with an error code.
}

// Called when removing an element from the ArrayList by index fails (e.g., invalid index or memory issues).
void ArrayList_Remove_By_Index_Failure_Callout() {
    printf("ArrayList_Remove_By_Index_Failure_Callout: Failed to remove element (invalid index or memory error).\n");
    exit(-1); // Exit the program with an error code.
}

// Called when replacing an element in the ArrayList fails (e.g., invalid index or memory issues).
void ArrayList_Replace_Failure_Callout() {
    printf("ArrayList_Replace_Failure_Callout: Failed to replace element (invalid index or memory error).\n");
    exit(-1); // Exit the program with an error code.
}

// Called when retrieving an element from the ArrayList fails (e.g., invalid index).
void ArrayList_Get_Failure_Callout() {
    printf("ArrayList_Get_Failure_Callout: Failed to retrieve element (invalid index).\n");
    exit(-1); // Exit the program with an error code.
}

// Called when getting the size of the ArrayList fails (e.g., invalid ArrayList pointer).
void ArrayList_Size_Failure_Callout() {
    printf("ArrayList_Size_Failure_Callout: Failed to get size (invalid ArrayList pointer).\n");
    exit(-1); // Exit the program with an error code.
}

// Called when checking if the ArrayList is empty fails (e.g., invalid ArrayList pointer).
void ArrayList_IsEmpty_Failure_Callout() {
    printf("ArrayList_IsEmpty_Failure_Callout: Failed to check if ArrayList is empty (invalid ArrayList pointer).\n");
    exit(-1); // Exit the program with an error code.
}

// Called when removing all elements from the ArrayList fails (e.g., memory issues).
void ArrayList_RemoveAll_Failure_Callout() {
    printf("ArrayList_RemoveAll_Failure_Callout: Failed to remove all elements (memory error).\n");
    exit(-1); // Exit the program with an error code.
}

// Called when checking if the ArrayList contains a specific element fails (e.g., invalid ArrayList pointer).
void ArrayList_Contains_Failure_Callout() {
    printf("ArrayList_Contains_Failure_Callout: Failed to check if ArrayList contains element (invalid ArrayList pointer).\n");
    exit(-1); // Exit the program with an error code.
}

// Called when finding the index of a specific element in the ArrayList fails (e.g., invalid ArrayList pointer).
void ArrayList_IndexOf_Failure_Callout() {
    printf("ArrayList_IndexOf_Failure_Callout: Failed to find index of element (invalid ArrayList pointer).\n");
    exit(-1); // Exit the program with an error code.
}

// Called when finding the last index of a specific element in the ArrayList fails (e.g., invalid ArrayList pointer).
void ArrayList_LastIndexOf_Failure_Callout() {
    printf("ArrayList_LastIndexOf_Failure_Callout: Failed to find last index of element (invalid ArrayList pointer).\n");
    exit(-1); // Exit the program with an error code.
}

// Called when doubling the size of the ArrayList fails (e.g., memory allocation failure).
void ArrayList_DoubleSize_Failure_Callout() {
    printf("ArrayList_DoubleSize_Failure_Callout: Failed to double the size of ArrayList (memory allocation error).\n");
    exit(-1); // Exit the program with an error code.
}