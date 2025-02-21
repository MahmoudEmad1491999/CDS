#include "ArrayList.h"
#include "ArrayList_Callout.h"
#include <stdlib.h>
#include <string.h>

/**
 * Doubles the size of the ArrayList.
 * If the ArrayList is NULL or realloc fails, the failure callout is triggered.
 *
 * @param arrayList Pointer to the ArrayList to resize.
 */
void ArrayList_DoubleSize(ArrayList *arrayList) {
    if (arrayList == NULL) {
        ArrayList_DoubleSize_Failure_Callout(); // Handle NULL ArrayList.
        return;
    }

    // Attempt to reallocate memory for the list.
    ARRAYLIST_ELEMENT_DATATYPE *newList = realloc(arrayList->list, sizeof(ARRAYLIST_ELEMENT_DATATYPE) * arrayList->size * 2);
    if (newList == NULL) {
        ArrayList_DoubleSize_Failure_Callout(); // Handle realloc failure.
        return;
    }

    // Update the list and size.
    arrayList->list = newList;
    arrayList->size *= 2;
}

/**
 * Creates a new ArrayList with the specified initial size.
 * If memory allocation fails, the failure callout is triggered.
 *
 * @param size Initial size of the ArrayList.
 * @return Pointer to the newly created ArrayList, or NULL on failure.
 */
ArrayList *CreateArrayList(ARRAYLIST_LENGTH_DATATYPE size, ARRAYLIST_FREE_FUNCTION_POINTER_DATATYPE freeFunc) {
    if (size <= 0) {
        CreateArrayList_Failure_Callout(); // Handle invalid size.
        return NULL;
    }

    // Allocate memory for the ArrayList structure.
    ArrayList *arrayList = malloc(sizeof(ArrayList));
    if (arrayList == NULL) {
        CreateArrayList_Failure_Callout(); // Handle malloc failure.
        return NULL;
    }

    // Allocate memory for the internal list.
    arrayList->list = malloc(sizeof(ARRAYLIST_ELEMENT_DATATYPE) * size);
    if (arrayList->list == NULL) {
        free(arrayList); // Free the ArrayList structure if list allocation fails.
        CreateArrayList_Failure_Callout(); // Handle malloc failure.
        return NULL;
    }

    // Initialize ArrayList fields.
    arrayList->size = size;
    arrayList->len = 0;
    arrayList->freeFunc = NULL; // Initialize freeFunc to NULL.
    return arrayList;
}

/**
 * Frees the ArrayList and its elements.
 * If a free function is provided, it is used to free each element.
 *
 * @param arrayList Pointer to the ArrayList to free.
 */
void FreeArrayList(ArrayList *arrayList) {
    if (arrayList == NULL) {
        return; // Do nothing if the ArrayList is NULL.
    }

    if (arrayList->list != NULL) {
        // Free each element using the provided free function or default free.
        if (arrayList->freeFunc != NULL) {
            for (ARRAYLIST_INDEX_DATATYPE index = 0; index < arrayList->len; index++) {
                arrayList->freeFunc(arrayList->list[index]);
            }
        } else {
            for (ARRAYLIST_INDEX_DATATYPE index = 0; index < arrayList->len; index++) {
                free(arrayList->list[index]);
            }
        }
        free(arrayList->list); // Free the internal list.
    }
    free(arrayList); // Free the ArrayList structure.
}

/**
 * Appends an element to the end of the ArrayList.
 * If the ArrayList is full, its size is doubled.
 * If the ArrayList is NULL or resizing fails, the failure callout is triggered.
 *
 * @param arrayList Pointer to the ArrayList.
 * @param ele Element to append.
 */
void ArrayList_Append(ArrayList *arrayList, ARRAYLIST_ELEMENT_DATATYPE ele) {
    if (arrayList == NULL) {
        ArrayList_Append_Failure_Callout(); // Handle NULL ArrayList.
        return;
    }

    // Resize the ArrayList if it is full.
    if (arrayList->len >= arrayList->size) {
        ARRAYLIST_LENGTH_DATATYPE oldSize = arrayList->size;
        ArrayList_DoubleSize(arrayList);
        if (arrayList->size == oldSize) { // Check if resizing failed.
            ArrayList_Append_Failure_Callout();
            return;
        }
    }

    // Append the element and update the length.
    arrayList->list[arrayList->len] = ele;
    arrayList->len++;
}

/**
 * Inserts an element at the specified index in the ArrayList.
 * If the ArrayList is full, its size is doubled.
 * If the ArrayList is NULL or the index is invalid, the failure callout is triggered.
 *
 * @param arrayList Pointer to the ArrayList.
 * @param ele Element to insert.
 * @param index Index at which to insert the element.
 */
void ArrayList_Insert(ArrayList *arrayList, ARRAYLIST_ELEMENT_DATATYPE ele, ARRAYLIST_INDEX_DATATYPE index) {
    if (arrayList == NULL || index > arrayList->len) {
        ArrayList_Insert_Failure_Callout(); // Handle NULL ArrayList or invalid index.
        return;
    }

    // Resize the ArrayList if it is full.
    if (arrayList->len >= arrayList->size) {
        ARRAYLIST_LENGTH_DATATYPE oldSize = arrayList->size;
        ArrayList_DoubleSize(arrayList);
        if (arrayList->size == oldSize) { // Check if resizing failed.
            ArrayList_Insert_Failure_Callout();
            return;
        }
    }

    // Shift elements to make space for the new element.
    memmove(arrayList->list + index + 1, arrayList->list + index, (arrayList->len - index) * sizeof(ARRAYLIST_ELEMENT_DATATYPE));

    // Insert the element and update the length.
    arrayList->list[index] = ele;
    arrayList->len++;
}

/**
 * Removes the first element that satisfies the given predicate.
 * If the ArrayList is NULL or the predicate is NULL, the failure callout is triggered.
 *
 * @param arrayList Pointer to the ArrayList.
 * @param predicateFunction Predicate function to test elements.
 */
void ArrayList_Remove_By_Predicate(ArrayList *arrayList, ARRAYLIST_PREDICATE_FUNCTION predicateFunction) {
    if (arrayList == NULL || predicateFunction == NULL) {
        ArrayList_Remove_By_Predicate_Failure_Callout(); // Handle NULL ArrayList or predicate.
        return;
    }

    // Search for the first element that satisfies the predicate.
    for (ARRAYLIST_INDEX_DATATYPE index = 0; index < arrayList->len; index++) {
        if (predicateFunction(arrayList->list[index]) == ARRAYLIST_TRUE) {
            // Free the element and shift the remaining elements.
            arrayList->freeFunc(arrayList->list[index]);
            memmove(arrayList->list + index, arrayList->list + index + 1, (arrayList->len - index - 1) * sizeof(ARRAYLIST_ELEMENT_DATATYPE));
            arrayList->len--;
            break;
        }
    }
}

/**
 * Removes the element at the specified index.
 * If the ArrayList is NULL or the index is invalid, the failure callout is triggered.
 *
 * @param arrayList Pointer to the ArrayList.
 * @param index Index of the element to remove.
 */
void ArrayList_Remove_By_Index(ArrayList *arrayList, ARRAYLIST_INDEX_DATATYPE index) {
    if (arrayList == NULL || index >= arrayList->len) {
        ArrayList_Remove_By_Index_Failure_Callout(); // Handle NULL ArrayList or invalid index.
        return;
    }

    // Free the element and shift the remaining elements.
    arrayList->freeFunc(arrayList->list[index]);
    memmove(arrayList->list + index, arrayList->list + index + 1, (arrayList->len - index - 1) * sizeof(ARRAYLIST_ELEMENT_DATATYPE));
    arrayList->len--;
}

/**
 * Replaces the element at the specified index.
 * If the ArrayList is NULL or the index is invalid, the failure callout is triggered.
 *
 * @param arrayList Pointer to the ArrayList.
 * @param index Index of the element to replace.
 * @param ele New element.
 */
void ArrayList_Replace(ArrayList *arrayList, ARRAYLIST_INDEX_DATATYPE index, ARRAYLIST_ELEMENT_DATATYPE ele) {
    if (arrayList == NULL || index >= arrayList->len) {
        ArrayList_Replace_Failure_Callout(); // Handle NULL ArrayList or invalid index.
        return;
    }

    // Free the old element and replace it with the new one.
    arrayList->freeFunc(arrayList->list[index]);
    arrayList->list[index] = ele;
}

/**
 * Retrieves the element at the specified index.
 * If the ArrayList is NULL or the index is invalid, the failure callout is triggered.
 *
 * @param arrayList Pointer to the ArrayList.
 * @param index Index of the element to retrieve.
 * @return The element at the specified index, or NULL on failure.
 */
ARRAYLIST_ELEMENT_DATATYPE ArrayList_Get(ArrayList *arrayList, ARRAYLIST_INDEX_DATATYPE index) {
    if (arrayList == NULL || index >= arrayList->len) {
        ArrayList_Get_Failure_Callout(); // Handle NULL ArrayList or invalid index.
        return NULL;
    }
    return arrayList->list[index];
}

/**
 * Returns the current number of elements in the ArrayList.
 * If the ArrayList is NULL, the failure callout is triggered.
 *
 * @param arrayList Pointer to the ArrayList.
 * @return The number of elements in the ArrayList, or -1 on failure.
 */
ARRAYLIST_LENGTH_DATATYPE ArrayList_Size(ArrayList *arrayList) {
    if (arrayList == NULL) {
        ArrayList_Size_Failure_Callout(); // Handle NULL ArrayList.
        return -1;
    }
    return arrayList->len;
}

/**
 * Checks if the ArrayList is empty.
 * If the ArrayList is NULL, the failure callout is triggered.
 *
 * @param arrayList Pointer to the ArrayList.
 * @return ARRAYLIST_TRUE if the ArrayList is empty, ARRAYLIST_FALSE otherwise, or -1 on failure.
 */
int8 ArrayList_IsEmpty(ArrayList *arrayList) {
    if (arrayList == NULL) {
        ArrayList_IsEmpty_Failure_Callout(); // Handle NULL ArrayList.
        return -1;
    }
    return arrayList->len == 0 ? ARRAYLIST_TRUE : ARRAYLIST_FALSE;
}

/**
 * Removes all elements from the ArrayList.
 * If the ArrayList is NULL, the failure callout is triggered.
 *
 * @param arrayList Pointer to the ArrayList.
 */
void ArrayList_RemoveAll(ArrayList *arrayList) {
    if (arrayList == NULL) {
        ArrayList_RemoveAll_Failure_Callout(); // Handle NULL ArrayList.
        return;
    }

    // Free all elements and reset the length.
    for (ARRAYLIST_INDEX_DATATYPE index = 0; index < arrayList->len; index++) {
        arrayList->freeFunc(arrayList->list[index]);
    }
    arrayList->len = 0;
}

/**
 * Checks if the ArrayList contains a specific element.
 * If the ArrayList is NULL or the comparator is NULL, the failure callout is triggered.
 *
 * @param arrayList Pointer to the ArrayList.
 * @param ele Element to search for.
 * @param comparatorFunction Comparator function to compare elements.
 * @return ARRAYLIST_TRUE if the element is found, ARRAYLIST_FALSE otherwise, or -1 on failure.
 */
int8 ArrayList_Contains(ArrayList *arrayList, ARRAYLIST_ELEMENT_DATATYPE ele, ARRAYLIST_COMPARATOR_FUNCTION comparatorFunction) {
    if (arrayList == NULL || comparatorFunction == NULL) {
        ArrayList_Contains_Failure_Callout(); // Handle NULL ArrayList or comparator.
        return -1;
    }

    // Search for the element.
    for (ARRAYLIST_INDEX_DATATYPE index = 0; index < arrayList->len; index++) {
        if (comparatorFunction(ele, arrayList->list[index]) == ARRAYLIST_EQUAL) {
            return ARRAYLIST_TRUE;
        }
    }
    return ARRAYLIST_FALSE;
}

/**
 * Finds the index of the first occurrence of a specific element.
 * If the ArrayList is NULL or the comparator is NULL, the failure callout is triggered.
 *
 * @param arrayList Pointer to the ArrayList.
 * @param ele Element to search for.
 * @param comparatorFunction Comparator function to compare elements.
 * @return The index of the first occurrence, or ARRAYLIST_NONEXISTENT_INDEX if not found or on failure.
 */
ARRAYLIST_INDEX_DATATYPE ArrayList_IndexOf(ArrayList *arrayList, ARRAYLIST_ELEMENT_DATATYPE ele, ARRAYLIST_COMPARATOR_FUNCTION comparatorFunction) {
    if (arrayList == NULL || comparatorFunction == NULL) {
        ArrayList_IndexOf_Failure_Callout(); // Handle NULL ArrayList or comparator.
        return ARRAYLIST_NONEXISTENT_INDEX;
    }

    // Search for the element.
    for (ARRAYLIST_INDEX_DATATYPE index = 0; index < arrayList->len; index++) {
        if (comparatorFunction(ele, arrayList->list[index]) == ARRAYLIST_EQUAL) {
            return index;
        }
    }
    return ARRAYLIST_NONEXISTENT_INDEX;
}

/**
 * Finds the index of the last occurrence of a specific element.
 * If the ArrayList is NULL or the comparator is NULL, the failure callout is triggered.
 *
 * @param arrayList Pointer to the ArrayList.
 * @param ele Element to search for.
 * @param comparatorFunction Comparator function to compare elements.
 * @return The index of the last occurrence, or ARRAYLIST_NONEXISTENT_INDEX if not found or on failure.
 */
ARRAYLIST_INDEX_DATATYPE ArrayList_LastIndexOf(ArrayList *arrayList, ARRAYLIST_ELEMENT_DATATYPE ele, ARRAYLIST_COMPARATOR_FUNCTION comparatorFunction) {
    if (arrayList == NULL || comparatorFunction == NULL) {
        ArrayList_LastIndexOf_Failure_Callout(); // Handle NULL ArrayList or comparator.
        return ARRAYLIST_NONEXISTENT_INDEX;
    }

    // Search for the element from the end.
    for (ARRAYLIST_INDEX_DATATYPE index = arrayList->len - 1; index >= 0; index--) {
        if (comparatorFunction(ele, arrayList->list[index]) == ARRAYLIST_EQUAL) {
            return index;
        }
    }
    return ARRAYLIST_NONEXISTENT_INDEX;
}