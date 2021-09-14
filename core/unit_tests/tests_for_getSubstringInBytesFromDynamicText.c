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
    char* titleFromTest = "#01 Get one-byte substring from an one-byte text.";

    char* expectedText = "a";

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, "a", __FILE__, __LINE__);
    
    struct dynamicText* var2 = allocateDynamicText(__FILE__, __LINE__);
    getSubstringInBytesFromDynamicText(&var1, 0, 1, &var2, __FILE__, __LINE__);
    
    if (
        (customStrlen(expectedText) != customStrlen(getBytesPointerFromDynamicText(&var2)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&var2), expectedText, customStrlen(expectedText)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }

    freeDynamicText(&var1, __FILE__, __LINE__);
    freeDynamicText(&var2, __FILE__, __LINE__);

    if (
        (NULL == var1)
        && (NULL == var2)
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
    char* titleFromTest = "#02 Get one-byte substring from an ordinary text.";

    char* expectedText = "a";

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, "This is a regular sentence with ÄÖÜäöü@µ signs.", __FILE__, __LINE__);
    
    struct dynamicText* var2 = allocateDynamicText(__FILE__, __LINE__);
    getSubstringInBytesFromDynamicText(&var1, 8, 9, &var2, __FILE__, __LINE__);
    
    if (
        (customStrlen(expectedText) != customStrlen(getBytesPointerFromDynamicText(&var2)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&var2), expectedText, customStrlen(expectedText)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }

    freeDynamicText(&var1, __FILE__, __LINE__);
    freeDynamicText(&var2, __FILE__, __LINE__);

    if (
        (NULL == var1)
        && (NULL == var2)
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
    char* titleFromTest = "#03 Get one-letter multibyte substring from an ordinary text.";

    char* expectedText = "ü";

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, "This is a regular sentence with ÄÖÜäöü@µ signs.", __FILE__, __LINE__);
    
    struct dynamicText* var2 = allocateDynamicText(__FILE__, __LINE__);
    getSubstringInBytesFromDynamicText(&var1, 42, 44, &var2, __FILE__, __LINE__);
    
    if (
        (customStrlen(expectedText) != customStrlen(getBytesPointerFromDynamicText(&var2)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&var2), expectedText, customStrlen(expectedText)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }

    freeDynamicText(&var1, __FILE__, __LINE__);
    freeDynamicText(&var2, __FILE__, __LINE__);

    if (
        (NULL == var1)
        && (NULL == var2)
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
    char* titleFromTest = "#04 Get one-byte substring from a large text.";

    char* sentence1 = "Lorem ipsum sit amet, consectetur adipiscing (ÄÖÜäöüß@µ) elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    char* expectedText = "m";

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, sentence1, __FILE__, __LINE__);
    
    struct dynamicText* var2 = allocateDynamicText(__FILE__, __LINE__);
    getSubstringInBytesFromDynamicText(&var1, 10, 11, &var2, __FILE__, __LINE__);
    
    if (
        (customStrlen(expectedText) != customStrlen(getBytesPointerFromDynamicText(&var2)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&var2), expectedText, customStrlen(expectedText)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }

    freeDynamicText(&var1, __FILE__, __LINE__);
    freeDynamicText(&var2, __FILE__, __LINE__);

    if (
        (NULL == var1)
        && (NULL == var2)
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
    char* titleFromTest = "#05 Get multi-byte substring from an ordinary text.";

    char* expectedText = "with ÄÖÜäöü@µ signs";

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, "This is a regular sentence with ÄÖÜäöü@µ signs.", __FILE__, __LINE__);
    
    struct dynamicText* var2 = allocateDynamicText(__FILE__, __LINE__);
    getSubstringInBytesFromDynamicText(&var1, 27, 53, &var2, __FILE__, __LINE__);
    
    if (
        (customStrlen(expectedText) != customStrlen(getBytesPointerFromDynamicText(&var2)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&var2), expectedText, customStrlen(expectedText)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }

    freeDynamicText(&var1, __FILE__, __LINE__);
    freeDynamicText(&var2, __FILE__, __LINE__);

    if (
        (NULL == var1)
        && (NULL == var2)
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
    char* titleFromTest = "#06 Get complete text as substring from an ordinary text.";

    char* expectedText = "This is a regular sentence with ÄÖÜäöü@µ signs.";
    char* sentence1    = "This is a regular sentence with ÄÖÜäöü@µ signs.";

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, sentence1, __FILE__, __LINE__);
    
    struct dynamicText* var2 = allocateDynamicText(__FILE__, __LINE__);
    getSubstringInBytesFromDynamicText(&var1, 0, customStrlen(sentence1), &var2, __FILE__, __LINE__);
    
    if (
        (customStrlen(expectedText) != customStrlen(getBytesPointerFromDynamicText(&var2)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&var2), expectedText, customStrlen(expectedText)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }

    freeDynamicText(&var1, __FILE__, __LINE__);
    freeDynamicText(&var2, __FILE__, __LINE__);

    if (
        (NULL == var1)
        && (NULL == var2)
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
    char* titleFromTest = "#07 Get multi-byte substring from a large text.";

    char* expectedText = "Lorem ipsum sit amet, consectetur adipiscing (ÄÖÜäöüß@µ) elit,";
    char* sentence1 = "Lorem ipsum sit amet, consectetur adipiscing (ÄÖÜäöüß@µ) elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    
    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, sentence1, __FILE__, __LINE__);
    
    struct dynamicText* var2 = allocateDynamicText(__FILE__, __LINE__);
    getSubstringInBytesFromDynamicText(&var1, 0, 70, &var2, __FILE__, __LINE__);
    
    if (
        (customStrlen(expectedText) != customStrlen(getBytesPointerFromDynamicText(&var2)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&var2), expectedText, customStrlen(expectedText)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }

    freeDynamicText(&var1, __FILE__, __LINE__);
    freeDynamicText(&var2, __FILE__, __LINE__);

    if (
        (NULL == var1)
        && (NULL == var2)
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
    char* titleFromTest = "#08 Get complete text as substring from a large text.";

    char* expectedText = "Lorem ipsum sit amet, consectetur adipiscing (ÄÖÜäöüß@µ) elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    char* sentence1 = "Lorem ipsum sit amet, consectetur adipiscing (ÄÖÜäöüß@µ) elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, sentence1, __FILE__, __LINE__);
    
    struct dynamicText* var2 = allocateDynamicText(__FILE__, __LINE__);
    getSubstringInBytesFromDynamicText(&var1, 0, customStrlen(sentence1), &var2, __FILE__, __LINE__);
    
    if (
        (customStrlen(expectedText) != customStrlen(getBytesPointerFromDynamicText(&var2)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&var2), expectedText, customStrlen(expectedText)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }

    freeDynamicText(&var1, __FILE__, __LINE__);
    freeDynamicText(&var2, __FILE__, __LINE__);

    if (
        (NULL == var1)
        && (NULL == var2)
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
    printf("TEST SUITE: getSubstringInBytesFromDynamicText function\n");

    executeTest1();
    executeTest2();
    executeTest3();
    executeTest4();
    executeTest5();
    executeTest6();
    executeTest7();
    executeTest8();

    return EXIT_SUCCESS;
}
