#if !defined(ASSERTION_H)
#define ASSERTION_H

#include "stdlib.h"
#include "stdio.h"


inline void assert_ptr_neq_null(void* ptr)
{
    if(ptr == NULL)
    {
        printf("FAILURE: given PTR Is Null\n");
    }
    else {
        printf("SUCCESS: given PTR IS NOT NULL\n");
    }
}
inline void assert_ptr_eq_null(void* ptr)
{
    if(ptr == NULL)
    {
        printf("SUCCESS: given PTR Is Null\n");
    }
    else {
        printf("FAILURE: given PTR IS NOT NULL\n");
    }
}

#endif // ASSERTION_H
