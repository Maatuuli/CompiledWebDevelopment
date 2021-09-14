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
    char* titleFromTest = "#01 Offset  0: Find no position of an one-byte search text in an empty text.";

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, "", __FILE__, __LINE__);

    int pos = findPositionInDynamicText(&var1, "a", 0, __FILE__, __LINE__);

    if (-1 != pos)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }

    freeDynamicText(&var1, __FILE__, __LINE__);

    if (
        (-1 == pos)
        && (NULL == var1)
        && (globaleAmountOfAllocations == globaleAmountOfFrees)
        && (0 == globaleAmountOfAllocatedMemoryInBytes)
    )
    {
        printf("[SUCCESS] %s\n", titleFromTest);
        return;
    }
    
    abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
}


static void
executeTest2(void)
{
    char* titleFromTest = "#02 Offset  0: Find no position of an one-byte search text in an one-byte text.";

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, "1", __FILE__, __LINE__);

    int pos = findPositionInDynamicText(&var1, "a", 0, __FILE__, __LINE__);

    if (-1 != pos)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }

    freeDynamicText(&var1, __FILE__, __LINE__);

    if (
        (-1 == pos)
        && (NULL == var1)
        && (globaleAmountOfAllocations == globaleAmountOfFrees)
        && (0 == globaleAmountOfAllocatedMemoryInBytes)
    )
    {
        printf("[SUCCESS] %s\n", titleFromTest);
        return;
    }
    
    abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
}


static void
executeTest3(void)
{
    char* titleFromTest = "#03 Offset  0: Find no position of a multi-byte search text in an one-byte text.";

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, "1", __FILE__, __LINE__);

    int pos = findPositionInDynamicText(&var1, "ü", 0, __FILE__, __LINE__);

    if (-1 != pos)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }

    freeDynamicText(&var1, __FILE__, __LINE__);

    if (
        (-1 == pos)
        && (NULL == var1)
        && (globaleAmountOfAllocations == globaleAmountOfFrees)
        && (0 == globaleAmountOfAllocatedMemoryInBytes)
    )
    {
        printf("[SUCCESS] %s\n", titleFromTest);
        return;
    }
    
    abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
}


static void
executeTest4(void)
{
    char* titleFromTest = "#04 Offset  0: Find no position of an one-byte search text in an ordinary text.";

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, "This is a normal sentence.", __FILE__, __LINE__);

    int pos = findPositionInDynamicText(&var1, "Z", 0, __FILE__, __LINE__);

    if (-1 != pos)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }

    freeDynamicText(&var1, __FILE__, __LINE__);

    if (
        (-1 == pos)
        && (NULL == var1)
        && (globaleAmountOfAllocations == globaleAmountOfFrees)
        && (0 == globaleAmountOfAllocatedMemoryInBytes)
    )
    {
        printf("[SUCCESS] %s\n", titleFromTest);
        return;
    }
    
    abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
}


static void
executeTest5(void)
{
    char* titleFromTest = "#05 Offset >0: Find no position of an one-byte search text in an ordinary text.";

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, "The letter Z is a regular letter.", __FILE__, __LINE__);

    int pos = findPositionInDynamicText(&var1, "Z", 15, __FILE__, __LINE__);

    if (-1 != pos)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }

    freeDynamicText(&var1, __FILE__, __LINE__);

    if (
        (-1 == pos)
        && (NULL == var1)
        && (globaleAmountOfAllocations == globaleAmountOfFrees)
        && (0 == globaleAmountOfAllocatedMemoryInBytes)
    )
    {
        printf("[SUCCESS] %s\n", titleFromTest);
        return;
    }
    
    abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
}


static void
executeTest6(void)
{
    char* titleFromTest = "#06 Offset  0: Find no position of a multi-byte search text in an ordinary text.";

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, "Umlautz are regular letters.", __FILE__, __LINE__);

    int pos = findPositionInDynamicText(&var1, "äöü", 0, __FILE__, __LINE__);

    if (-1 != pos)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }

    freeDynamicText(&var1, __FILE__, __LINE__);

    if (
        (-1 == pos)
        && (NULL == var1)
        && (globaleAmountOfAllocations == globaleAmountOfFrees)
        && (0 == globaleAmountOfAllocatedMemoryInBytes)
    )
    {
        printf("[SUCCESS] %s\n", titleFromTest);
        return;
    }
    
    abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
}


static void
executeTest7(void)
{
    char* titleFromTest = "#07 Offset >0: Find no position of a multi-byte search text in an ordinary text.";

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, "Umlautz like äöü are regular letters.", __FILE__, __LINE__);

    int pos = findPositionInDynamicText(&var1, "äöü", 20, __FILE__, __LINE__);

    if (-1 != pos)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }

    freeDynamicText(&var1, __FILE__, __LINE__);

    if (
        (-1 == pos)
        && (NULL == var1)
        && (globaleAmountOfAllocations == globaleAmountOfFrees)
        && (0 == globaleAmountOfAllocatedMemoryInBytes)
    )
    {
        printf("[SUCCESS] %s\n", titleFromTest);
        return;
    }
    
    abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
}


static void
executeTest8(void)
{
    char* titleFromTest = "#08 Offset  0: Find no position of a half correct multi-byte search text in an ordinary text.";

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, "Umlautz like äöü are regular letters.", __FILE__, __LINE__);

    int pos = findPositionInDynamicText(&var1, "äöT", 0, __FILE__, __LINE__);

    if (-1 != pos)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }

    freeDynamicText(&var1, __FILE__, __LINE__);

    if (
        (-1 == pos)
        && (NULL == var1)
        && (globaleAmountOfAllocations == globaleAmountOfFrees)
        && (0 == globaleAmountOfAllocatedMemoryInBytes)
    )
    {
        printf("[SUCCESS] %s\n", titleFromTest);
        return;
    }
    
    abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
}


static void
executeTest9(void)
{
    char* titleFromTest = "#09 Offset  0: Find the correct position of an one-byte search text in an one-byte text.";

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, "1", __FILE__, __LINE__);

    int pos = findPositionInDynamicText(&var1, "1", 0, __FILE__, __LINE__);

    if (-1 == pos)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }

    freeDynamicText(&var1, __FILE__, __LINE__);

    if (
        (0 == pos)
        && (NULL == var1)
        && (globaleAmountOfAllocations == globaleAmountOfFrees)
        && (0 == globaleAmountOfAllocatedMemoryInBytes)
    )
    {
        printf("[SUCCESS] %s\n", titleFromTest);
        return;
    }
    
    abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
}


static void
executeTest10(void)
{
    char* titleFromTest = "#10 Offset  0: Find the correct position of an one-byte search text in an ordinary text.";

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, "This is a regular sentence.", __FILE__, __LINE__);

    int pos = findPositionInDynamicText(&var1, "g", 0, __FILE__, __LINE__);

    if (-1 == pos)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }

    freeDynamicText(&var1, __FILE__, __LINE__);

    if (
        (12 == pos)
        && (NULL == var1)
        && (globaleAmountOfAllocations == globaleAmountOfFrees)
        && (0 == globaleAmountOfAllocatedMemoryInBytes)
    )
    {
        printf("[SUCCESS] %s\n", titleFromTest);
        return;
    }
    
    abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
}


static void
executeTest11(void)
{
    char* titleFromTest = "#11 Offset >0: Find the correct position of an one-byte search text in an ordinary text.";

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, "This is a regular sentence.", __FILE__, __LINE__);

    int pos = findPositionInDynamicText(&var1, "e", 12, __FILE__, __LINE__);

    if (-1 == pos)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }

    freeDynamicText(&var1, __FILE__, __LINE__);

    if (
        (19 == pos)
        && (NULL == var1)
        && (globaleAmountOfAllocations == globaleAmountOfFrees)
        && (0 == globaleAmountOfAllocatedMemoryInBytes)
    )
    {
        printf("[SUCCESS] %s\n", titleFromTest);
        return;
    }
    
    abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
}


static void
executeTest12(void)
{
    char* titleFromTest = "#12 Offset  0: Find the correct position of a multi-byte search text in an ordinary text.";

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, "The umlautz äöü are regular letters.", __FILE__, __LINE__);

    int pos = findPositionInDynamicText(&var1, "äöü", 0, __FILE__, __LINE__);

    if (-1 == pos)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }

    freeDynamicText(&var1, __FILE__, __LINE__);

    if (
        (12 == pos)
        && (NULL == var1)
        && (globaleAmountOfAllocations == globaleAmountOfFrees)
        && (0 == globaleAmountOfAllocatedMemoryInBytes)
    )
    {
        printf("[SUCCESS] %s\n", titleFromTest);
        return;
    }
    
    abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
}


static void
executeTest13(void)
{
    char* titleFromTest = "#13 Offset >0: Find the correct position of a multi-byte search text in an ordinary text.";

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, "The umlautz äöü are regular letters. The text äöü contains three unicode letters.", __FILE__, __LINE__);

    int pos = findPositionInDynamicText(&var1, "äöü", 30, __FILE__, __LINE__);

    if (-1 == pos)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }

    freeDynamicText(&var1, __FILE__, __LINE__);

    /* This is the offset of a multi-byte unicode text with umlauts, be aware of this! */
    int expectedValue = 49;

    if (
        (expectedValue == pos)
        && (NULL == var1)
        && (globaleAmountOfAllocations == globaleAmountOfFrees)
        && (0 == globaleAmountOfAllocatedMemoryInBytes)
    )
    {
        printf("[SUCCESS] %s\n", titleFromTest);
        return;
    }
    
    abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
}


static void
executeTest14(void)
{
    char* titleFromTest = "#14 ?????????? Offset 0: Find the correct position of a multi-byte search text in an ordinary text.";

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, "commodo descriptio", __FILE__, __LINE__);

    int pos = findPositionInDynamicText(&var1, "description", 0, __FILE__, __LINE__);

    if (-1 != pos)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }

    freeDynamicText(&var1, __FILE__, __LINE__);

    if (
        (-1 == pos)
        && (NULL == var1)
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
    printf("TEST SUITE: findPositionInDynamicText function\n");

    executeTest1();
    executeTest2();
    executeTest3();
    executeTest4();
    executeTest5();
    executeTest6();
    executeTest7();
    executeTest8();
    executeTest9();
    executeTest10();
    executeTest11();
    executeTest12();
    executeTest13();
    executeTest14();

    return EXIT_SUCCESS;
}
