#include "ArrayList.h"
#include "ArrayList_Callout.h"
#include "stdlib.h"
#include "string.h"
void ArrayList_DoubleSize(ArrayList *arrayList)
{
    if (arrayList != NULL)
    {
        ARRAYLIST_ELEMENT_DATATYPE *list_with_new_size = realloc(arrayList->list, sizeof(ARRAYLIST_ELEMENT_DATATYPE) * arrayList->size * 2);
        if (list_with_new_size != NULL)
        {
            arrayList->list = list_with_new_size;
            arrayList->size = arrayList->size * 2;
        }
    }
    else
    {
        ArrayList_DoubleSize_Failure_Callout();
    }
}
ArrayList *CreateArrayList(ARRAYLIST_LENGTH_DATATYPE size)
{
    ArrayList *ret = malloc(sizeof(ArrayList));

    if (ret != NULL)
    {
        if (size > 0)
        {
            void *internal_list = malloc(sizeof(ARRAYLIST_ELEMENT_DATATYPE) * size);
            if (internal_list != NULL)
            {
                ret->list = internal_list;
                ret->size = size;
                ret->len = 0;
            }
            else
            {
                CreateArrayList_Failure_Callout();
            }
        }
        else
        {
            CreateArrayList_Failure_Callout();
        }
        return ret;
    }
    else
    {
        CreateArrayList_Failure_Callout();
        return NULL;
    }
}

void FreeArrayList(ArrayList *arrayList)
{
    if (arrayList != NULL)
    {
        if (arrayList->freeFunc != NULL)
        {
            for (ARRAYLIST_INDEX_DATATYPE index; index < arrayList->len; index++)
            {
                ARRAYLIST_ELEMENT_DATATYPE currentElement = arrayList->list[index];
                arrayList->freeFunc(currentElement);
            }
            free(arrayList->list);
            free(arrayList);
        }
        else
        {
            for (ARRAYLIST_INDEX_DATATYPE index; index < arrayList->len; index++)
            {
                ARRAYLIST_ELEMENT_DATATYPE currentElement = arrayList->list[index];
                free(currentElement);
            }
            free(arrayList->list);
            free(arrayList);
        }
    }
    else
    {
        // do nothing
    }
}

void ArrayList_Append(ArrayList *arrayList, ARRAYLIST_ELEMENT_DATATYPE ele)
{
    ARRAYLIST_INDEX_DATATYPE next_available_index = 0;
    if (arrayList != NULL)
    {
        if (arrayList->len < arrayList->size)
        {
            next_available_index = arrayList->len;
            arrayList->list[next_available_index] = ele;
            arrayList->len = arrayList->len + 1;
            return;
        }
        else
        {
            ArrayList_DoubleSize(arrayList);
            next_available_index = arrayList->len;
            arrayList->list[next_available_index] = ele;
            arrayList->len = arrayList->len + 1;
            return;
        }
    }
    else
    {
        ArrayList_Append_Failure_Callout();
    }
}

void ArrayList_Insert(ArrayList *arrayList, ARRAYLIST_ELEMENT_DATATYPE ele, ARRAYLIST_INDEX_DATATYPE index)
{
    ARRAYLIST_LENGTH_DATATYPE after_element_list_size = 0;
    int memmove_res = 0;

    if (arrayList == NULL || index >= arrayList->len)
    {
        ArrayList_Insert_Failure_Callout();
    }

    if (arrayList->len == arrayList->size)
    {
        ArrayList_DoubleSize(arrayList);
    }

    after_element_list_size = (arrayList->len) - (index);
    memmove_resmemmove(arrayList->list + index, arrayList->list + index + 1, after_element_list_size * sizeof(ARRAYLIST_ELEMENT_DATATYPE));

    arrayList->list[index] = ele;
    arrayList->len = arrayList->len + 1;

    return;
}

void ArrayList_Remove_By_Predicate(ArrayList *arrayList, ARRAYLIST_PREDICATE_FUNCTION predicateFunction)
{
    if (arrayList == NULL || predicateFunction == NULL)
    {
        ArrayList_Remove_By_Predicate_Failure_Callout();
    }
    int8 predicateFunctionRes = INT8_MAX;
    // find first index phase
    for (ARRAYLIST_INDEX_DATATYPE index = 0; index < arrayList->len; index++)
    {
        predicateFunctionRes = predicateFunction(arrayList->list[index]);
        if (predicateFunctionRes == ARRAYLIST_TRUE)
        {
            arrayList->freeFunc(arrayList->list[index]);
            memmove(arrayList->list[index + 1], arrayList->list[index], sizeof(ARRAYLIST_ELEMENT_DATATYPE) * (arrayList->len - index - 1));
            arrayList->len = arrayList->len - 1;
            break;
        }
    }
}

void ArrayList_Remove_By_Index(ArrayList *arrayList, ARRAYLIST_INDEX_DATATYPE index)
{
    if (arrayList == NULL || index >= arrayList->len)
    {
        ArrayList_Remove_By_Index_Failure_Callout();
    }

    if (index == arrayList->len - 1)
    {
        arrayList->freeFunc(arrayList->list[index]);
        arrayList->len = arrayList->len - 1;
    }
    else
    {
        arrayList->freeFunc(arrayList->list[index]);
        memmove(arrayList->list[index + 1], arrayList->list[index], sizeof(ARRAYLIST_ELEMENT_DATATYPE) * (arrayList->len - index - 1));
        arrayList->len = arrayList->len - 1;
    }
}

void ArrayList_Replace(ArrayList *arrayList, ARRAYLIST_INDEX_DATATYPE index, ARRAYLIST_ELEMENT_DATATYPE ele)
{
    if (arrayList == NULL || index >= arrayList->len)
    {
        ArrayList_Replace_Failure_Callout();
    }

    arrayList->freeFunc(arrayList->list[index]);
    arrayList->list[index] = ele;
}

void ArrayList_Get(ArrayList *arrayList, ARRAYLIST_INDEX_DATATYPE index)
{
    if (arrayList == NULL || index >= arrayList->len)
    {
        ArrayList_Get_Failure_Callout();
        return;
    }
}

ARRAYLIST_LENGTH_DATATYPE ArrayList_Size(ArrayList *arrayList)
{
    if (arrayList == NULL)
    {
        ArrayList_Size_Failure_Callout();
        return -1;
    }
    return arrayList->size;
}

int8 ArrayList_IsEmpty(ArrayList *arrayList)
{
    if (arrayList == NULL)
    {
        ArrayList_IsEmpty_Failure_Callout();
        return -1;
    }
    return arrayList->len == 0;
}

void ArrayList_RemoveAll(ArrayList *arrayList)
{
    if (arrayList == NULL)
    {
        ArrayList_RemoveAll_Failure_Callout();
        return;
    }

    for (ARRAYLIST_INDEX_DATATYPE index = 0; index < arrayList->len; index++)
    {
        arrayList->freeFunc(arrayList->list[index]);
    }
    arrayList->len = 0;
}

int8 ArrayList_Contains(ArrayList *arrayList, ARRAYLIST_ELEMENT_DATATYPE ele, ARRAYLIST_COMPARATOR_FUNCTION comparatorFunction)
{
    if (arrayList == NULL || comparatorFunction == NULL)
    {
        ArrayList_Contains_Failure_Callout();
        return;
    }
    for (ARRAYLIST_INDEX_DATATYPE index = 0; index < arrayList->len; index++)
    {
        int8 res = INT8_MAX;
        res = comparatorFunction(ele, arrayList->list[index]);
        if (res == 0)
        {
            return ARRAYLIST_TRUE;
        }
    }
    return ARRAYLIST_FALSE;
}

ARRAYLIST_INDEX_DATATYPE ArrayList_IndexOf(ArrayList *arrayList, ARRAYLIST_ELEMENT_DATATYPE ele, ARRAYLIST_COMPARATOR_FUNCTION comparatorFunction)
{
    if (arrayList == NULL || comparatorFunction == NULL)
    {
        ArrayList_Contains_Failure_Callout();
        return;
    }
    for (ARRAYLIST_INDEX_DATATYPE index = 0; index < arrayList->len; index++)
    {
        int8 res = INT8_MAX;
        res = comparatorFunction(ele, arrayList->list[index]);
        if (res == ARRAYLIST_EQUAL)
        {
            return index;
        }
    }

    return ARRAYLIST_NONEXISTENT_INDEX;
}

ARRAYLIST_INDEX_DATATYPE ArrayList_LastIndexOf(ArrayList *arrayList, ARRAYLIST_ELEMENT_DATATYPE ele, ARRAYLIST_COMPARATOR_FUNCTION comparatorFunction)
{
    if (arrayList == NULL || comparatorFunction == NULL)
    {
        ArrayList_Contains_Failure_Callout();
        return;
    }
    for (ARRAYLIST_INDEX_DATATYPE index = arrayList->len; index >= 0; index--)
    {
        int8 res = INT8_MAX;
        res = comparatorFunction(ele, arrayList->list[index]);
        if (res == ARRAYLIST_EQUAL)
        {
            return index;
        }
    }

    return ARRAYLIST_NONEXISTENT_INDEX;
}