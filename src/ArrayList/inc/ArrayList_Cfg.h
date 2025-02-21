// Configuration header for the ArrayList implementation.
// This file defines data types, constants, and function pointer types used by the ArrayList.
// It ensures consistency and flexibility in the implementation.

// Header guard to prevent multiple inclusions of this header file.
#if !defined(ARRAYLIST_CFG_H)
#define ARRAYLIST_CFG_H

// Include a standard types header file, which defines basic data types like int32, int8, etc.
#include "std_types.h"

// Constants for boolean values and comparison results.
// These improve code readability and maintainability.

// Represents a true condition (1).
#define ARRAYLIST_TRUE 1

// Represents a false condition (0).
#define ARRAYLIST_FALSE 0

// Enumeration for comparison results.
// This provides better type safety and readability than using raw integers.
typedef enum {
    ARRAYLIST_EQUAL = 0,   // The elements are equal.
    ARRAYLIST_GREATER = 1, // The first element is greater.
    ARRAYLIST_LESS = -1    // The first element is less.
} ArrayListComparisonResult;

// Represents an invalid or nonexistent index in the ArrayList.
// This value is returned when an operation fails to find a valid index.
#define ARRAYLIST_NONEXISTENT_INDEX -1

// Define the data type for elements stored in the ArrayList.
// Using `void*` allows the ArrayList to store any type of data (generic programming).
typedef void* ARRAYLIST_ELEMENT_DATATYPE;

// Define the data type for the length of the ArrayList.
// Using `int32` ensures the length can be represented as a signed 32-bit integer.
typedef int32 ARRAYLIST_LENGTH_DATATYPE;

// Define the data type for indices in the ArrayList.
// This is the same as the length data type, ensuring consistency.
typedef ARRAYLIST_LENGTH_DATATYPE ARRAYLIST_INDEX_DATATYPE;

// Define a function pointer type for freeing elements stored in the ArrayList.
// This allows custom cleanup logic for elements when the ArrayList is freed.
// Parameters:
//   - element: The element to be freed.
typedef void (*ARRAYLIST_FREE_FUNCTION_POINTER_DATATYPE)(ARRAYLIST_ELEMENT_DATATYPE element);

// Define a function pointer type for predicate functions.
// Predicate functions are used to test elements (e.g., in search or filter operations).
// Parameters:
//   - element: The element to be tested.
// Returns:
//   - ARRAYLIST_TRUE if the element satisfies the predicate.
//   - ARRAYLIST_FALSE otherwise.
typedef int8 (*ARRAYLIST_PREDICATE_FUNCTION)(ARRAYLIST_ELEMENT_DATATYPE element);

// Define a function pointer type for comparator functions.
// Comparator functions are used to compare two elements.
// Parameters:
//   - element1: The first element to compare.
//   - element2: The second element to compare.
// Returns:
//   - ARRAYLIST_EQUAL if the elements are equal.
//   - ARRAYLIST_GREATER if the first element is greater.
//   - ARRAYLIST_LESS if the first element is less.
typedef int8 (*ARRAYLIST_COMPARATOR_FUNCTION)(ARRAYLIST_ELEMENT_DATATYPE element1, ARRAYLIST_ELEMENT_DATATYPE element2);

// End of the header guard.
#endif // ARRAYLIST_CFG_H