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
    char* titleFromTest = "#01 Replace text A with text B within an ordinary text.";

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, "Just some words for a complete sentence with a placeholder AB at the end!", __FILE__, __LINE__);

    replaceDynamicText(&var1, "AB", "123", __FILE__, __LINE__);

    if (
        (0 != customStrlen(getBytesPointerFromDynamicText(&var1)))
        && (0 != customStrncmp(getBytesPointerFromDynamicText(&var1), "", 0))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }

    freeDynamicText(&var1, __FILE__, __LINE__);

    if (
        (NULL == var1)
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
    char* titleFromTest = "#02 Replace text A with text B within an ordinary text.";

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, "wooden chair (red)", __FILE__, __LINE__);

    replaceDynamicText(&var1, "red)", "<span style=\"color: red; font-weight: bold;\">red)</span>", __FILE__, __LINE__);

    if (
        (0 != customStrlen(getBytesPointerFromDynamicText(&var1)))
        && (0 != customStrncmp(getBytesPointerFromDynamicText(&var1), "", 0))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }

    freeDynamicText(&var1, __FILE__, __LINE__);

    if (
        (NULL == var1)
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
    char* titleFromTest = "#03 Replace text A with one-letter multibyte text B within an ordinary text.";

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, "This black chair is the 2nd variant of the red chair (ÜÖÄäöüµß@). Soluta nobis eleifend option congue nihil imperdiet doming id quod mazim placerat facer possim assum.", __FILE__, __LINE__);
    replaceDynamicText(&var1, "ü", "<span class=\"bold\">ü</span>", __FILE__, __LINE__);

    if (
        (0 != customStrlen(getBytesPointerFromDynamicText(&var1)))
        && (0 != customStrncmp(getBytesPointerFromDynamicText(&var1), "", 0))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }

    freeDynamicText(&var1, __FILE__, __LINE__);

    if (
        (NULL == var1)
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
    char* titleFromTest = "#04 Replace text A with text B within an ordinary text.";

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, "This is a long description for the wooden table. Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat.", __FILE__, __LINE__);

    replaceDynamicText(&var1, "cription for the wooden table. Ut wisi enim ad minim veniam, quis nostrud exerci tation ", "<span style=\"color: red; font-weight: bold;\">cription for the wooden table. Ut wisi enim ad minim veniam, quis nostrud exerci tation </span>", __FILE__, __LINE__);

    if (
        (0 != customStrlen(getBytesPointerFromDynamicText(&var1)))
        && (0 != customStrncmp(getBytesPointerFromDynamicText(&var1), "", 0))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }

    freeDynamicText(&var1, __FILE__, __LINE__);

    if (
        (NULL == var1)
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
    char* titleFromTest = "#05 ???.";

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, "This is a long description for the product bed (ÜÖÄäöüµß@). Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat. Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis.", __FILE__, __LINE__);

    replaceDynamicText(&var1, " ", "<span> </span>", __FILE__, __LINE__);

    if (
        (0 != customStrlen(getBytesPointerFromDynamicText(&var1)))
        && (0 != customStrncmp(getBytesPointerFromDynamicText(&var1), "", 0))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }

    freeDynamicText(&var1, __FILE__, __LINE__);

    if (
        (NULL == var1)
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
    printf("TEST SUITE: replaceDynamicText function\n");

    executeTest1();
    executeTest2();
    executeTest3();
    executeTest4();

    executeTest5();
    
    return EXIT_SUCCESS;
}
