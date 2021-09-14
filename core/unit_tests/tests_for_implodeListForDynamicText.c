/*
The MIT License (MIT)

Copyright (c) 2021 Thomas Krüger

See full details in LICENSE.txt file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <time.h>

#include "../wrappedStandardLibrary.c"
#include "../wrappedFunctionForAllocation.c"
#include "../wrappedFunctionForReallocation.c"
#include "../dynamic_text.c"
#include "../dynamic_text_list.c"
#include "../helper_for_texts.c"
#include "helper_for_tests.c"


static void
executeTest1(void)
{
    char* titleFromTest = "#01 Implode a normal list with key value pairs.";

    struct dynamicText* var2 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var2, "name1=value1&name2=value2&name3=value3&name4=value4", __FILE__, __LINE__);
    
    struct listForDynamicText* list1 = newListForDynamicText(__FILE__, __LINE__);
    explodeDynamicText(&var2, "&", &list1, __FILE__, __LINE__);
    
    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    implodeListForDynamicText(&list1, &var1, "&", __FILE__, __LINE__);
    
    if (
        (0 != customStrlen(getBytesPointerFromDynamicText(&var1)))
        && (0 != customStrncmp(getBytesPointerFromDynamicText(&var1), "", 0))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }

    freeDynamicText(&var1, __FILE__, __LINE__);
    freeDynamicText(&var2, __FILE__, __LINE__);
    freeListForDynamicText(&list1, __FILE__, __LINE__);

    if (
        (NULL == var1)
        && (NULL == var2)
        && (NULL == list1)
        && (globaleAmountOfAllocations == globaleAmountOfFrees)
        && (0 == globaleAmountOfAllocatedMemoryInBytes)
    )
    {
        printf("[SUCCESS] %s\n", titleFromTest);
        return;
    }
    
    abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
}


int
main(void)
{
    printf("\n");
    printf("TEST SUITE: implodeListForDynamicText function\n");

    executeTest1();

    return EXIT_SUCCESS;
}
