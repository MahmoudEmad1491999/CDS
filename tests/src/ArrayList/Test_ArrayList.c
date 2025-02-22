#include "ArrayList.h"
#include "stdlib.h"
#include "Assertion.extern.h"


void CustomFreeFunction(void* ptr)
{
    free(ptr);
}

void Test_CreateArrayList()
{
    // Test Creation With Normal Size and custom freeFunction;
    ArrayList* al = CreateArrayList(10, CustomFreeFunction);

    assert_ptr_neq_null(al);


    

    return;
}
void Test_ArrayList_DoubleSize()
{
    return;
}

void Test_FreeArrayList()
{
    return;
}
void Test_ArrayList_Append()
{
    return;
}
void Test_ArrayList_Insert()
{
    return;
}
void Test_ArrayList_Remove_By_Predicate()
{
    return;
}
void Test_ArrayList_Remove_By_Index()
{
    return;
}
void Test_ArrayList_Replace()
{
    return;
}
void Test_ArrayList_Get()
{
    return;
}
void Test_ArrayList_Size()
{
    return;
}
void Test_ArrayList_IsEmpty()
{
    return;
}
void Test_ArrayList_RemoveAll()
{
    return;
}
void Test_ArrayList_Contains()
{
    return;
}
void Test_ArrayList_IndexOf()
{
    return;
}
void Test_ArrayList_LastIndexOf()
{
    return;
}



int main(int argc, char** argv)
{
    Test_CreateArrayList();
    return 0;
}