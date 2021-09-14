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
#include "../associative_dynamic_text.c"
#include "helper_for_tests.c"


static void
executeTest1(void)
{
    char* titleFromTest = "#01 Minimal initialization with key and freeing of empty key value stores.";

    char* textForkey = "name1";
    char* textForValue = "";

    struct associativeDynamicText* var1 = allocateAssociativeDynamicTextByKey(textForkey, __FILE__, __LINE__);

    if (NULL == var1)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }

    struct dynamicText* key = (*var1).internalKey;
    struct dynamicText* value = (*var1).internalValue;

    if (
        (customStrlen(textForkey) != customStrlen(getBytesPointerFromDynamicText(&key)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&key), textForkey, customStrlen(textForkey)))
        || (customStrlen(textForValue) != customStrlen(getBytesPointerFromDynamicText(&value)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&value), textForValue, customStrlen(textForValue)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeAssociativeDynamicText(&var1, __FILE__, __LINE__);

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
    char* titleFromTest = "#02 One-byte key and empty value.";

    char* textForkey = "a";
    char* textForValue = "";

    struct associativeDynamicText* var1 = allocateAssociativeDynamicTextByKey(textForkey, __FILE__, __LINE__);

    if (NULL == var1)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    struct dynamicText* key = (*var1).internalKey;
    struct dynamicText* value = (*var1).internalValue;

    if (
        (customStrlen(textForkey) != customStrlen(getBytesPointerFromDynamicText(&key)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&key), textForkey, customStrlen(textForkey)))
        || (customStrlen(textForValue) != customStrlen(getBytesPointerFromDynamicText(&value)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&value), textForValue, customStrlen(textForValue)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeAssociativeDynamicText(&var1, __FILE__, __LINE__);

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
    char* titleFromTest = "#03 Multi-byte key and empty value.";

    char* textForkey = "Ä";
    char* textForValue = "";

    struct associativeDynamicText* var1 = allocateAssociativeDynamicTextByKey(textForkey, __FILE__, __LINE__);

    if (NULL == var1)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    struct dynamicText* key = (*var1).internalKey;
    struct dynamicText* value = (*var1).internalValue;

    if (
        (customStrlen(textForkey) != customStrlen(getBytesPointerFromDynamicText(&key)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&key), textForkey, customStrlen(textForkey)))
        || (customStrlen(textForValue) != customStrlen(getBytesPointerFromDynamicText(&value)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&value), textForValue, customStrlen(textForValue)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeAssociativeDynamicText(&var1, __FILE__, __LINE__);

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
    char* titleFromTest = "#04 Regular key and empty value.";

    char* textForkey = "name1";
    char* textForValue = "";

    struct associativeDynamicText* var1 = allocateAssociativeDynamicTextByKey(textForkey, __FILE__, __LINE__);

    if (NULL == var1)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    struct dynamicText* key = (*var1).internalKey;
    struct dynamicText* value = (*var1).internalValue;

    if (
        (customStrlen(textForkey) != customStrlen(getBytesPointerFromDynamicText(&key)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&key), textForkey, customStrlen(textForkey)))
        || (customStrlen(textForValue) != customStrlen(getBytesPointerFromDynamicText(&value)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&value), textForValue, customStrlen(textForValue)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeAssociativeDynamicText(&var1, __FILE__, __LINE__);

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
    char* titleFromTest = "#05 Large key and empty value.";

    char* textForkey = "Sed ut (ÄÖÜäöüß@µ) unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo. Nemo enim ipsam voluptatem quia voluptas sit aspernatur aut odit aut fugit, sed quia consequuntur magni dolores eos qui ratione voluptatem sequi nesciunt. Neque porro quisquam est, qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit, sed quia non numquam eius modi tempora incidunt ut labore et dolore magnam aliquam quaerat voluptatem. Ut enim ad minima veniam, quis nostrum exercitationem ullam corporis suscipit laboriosam, nisi ut aliquid ex ea commodi consequatur? Quis autem vel eum iure reprehenderit qui in ea voluptate velit esse quam nihil molestiae consequatur, vel illum qui dolorem eum fugiat quo voluptas nulla pariatur?";
    char* textForValue = "";

    struct associativeDynamicText* var1 = allocateAssociativeDynamicTextByKey(textForkey, __FILE__, __LINE__);

    if (NULL == var1)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    struct dynamicText* key = (*var1).internalKey;
    struct dynamicText* value = (*var1).internalValue;

    if (
        (customStrlen(textForkey) != customStrlen(getBytesPointerFromDynamicText(&key)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&key), textForkey, customStrlen(textForkey)))
        || (customStrlen(textForValue) != customStrlen(getBytesPointerFromDynamicText(&value)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&value), textForValue, customStrlen(textForValue)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeAssociativeDynamicText(&var1, __FILE__, __LINE__);

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
executeTest6(void)
{
    char* titleFromTest = "#06 Set empty value.";

    char* textForkey = "name1";
    char* textForValue = "";

    struct associativeDynamicText* var1 = allocateAssociativeDynamicTextByKey(textForkey, __FILE__, __LINE__);
    
    if (NULL == var1)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    setValueInAssociativeDynamicText(&var1, textForValue, __FILE__, __LINE__);

    struct dynamicText* key = (*var1).internalKey;
    struct dynamicText* value = (*var1).internalValue;

    if (
        (customStrlen(textForkey) != customStrlen(getBytesPointerFromDynamicText(&key)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&key), textForkey, customStrlen(textForkey)))
        || (customStrlen(textForValue) != customStrlen(getBytesPointerFromDynamicText(&value)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&value), textForValue, customStrlen(textForValue)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeAssociativeDynamicText(&var1, __FILE__, __LINE__);

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
executeTest7(void)
{
    char* titleFromTest = "#07 Set one-letter value.";

    char* textForkey = "name1";
    char* textForValue = "a";

    struct associativeDynamicText* var1 = allocateAssociativeDynamicTextByKey(textForkey, __FILE__, __LINE__);

    if (NULL == var1)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }

    setValueInAssociativeDynamicText(&var1, textForValue, __FILE__, __LINE__);

    struct dynamicText* key = (*var1).internalKey;
    struct dynamicText* value = (*var1).internalValue;

    if (
        (customStrlen(textForkey) != customStrlen(getBytesPointerFromDynamicText(&key)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&key), textForkey, customStrlen(textForkey)))
        || (customStrlen(textForValue) != customStrlen(getBytesPointerFromDynamicText(&value)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&value), textForValue, customStrlen(textForValue)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeAssociativeDynamicText(&var1, __FILE__, __LINE__);

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
executeTest8(void)
{
    char* titleFromTest = "#08 Set multi-byte value.";

    char* textForkey = "name1";
    char* textForValue = "ÄÖÜäöüß@µ";

    struct associativeDynamicText* var1 = allocateAssociativeDynamicTextByKey(textForkey, __FILE__, __LINE__);

    if (NULL == var1)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    setValueInAssociativeDynamicText(&var1, textForValue, __FILE__, __LINE__);

    struct dynamicText* key = (*var1).internalKey;
    struct dynamicText* value = (*var1).internalValue;

    if (
        (customStrlen(textForkey) != customStrlen(getBytesPointerFromDynamicText(&key)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&key), textForkey, customStrlen(textForkey)))
        || (customStrlen(textForValue) != customStrlen(getBytesPointerFromDynamicText(&value)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&value), textForValue, customStrlen(textForValue)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeAssociativeDynamicText(&var1, __FILE__, __LINE__);

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
executeTest9(void)
{
    char* titleFromTest = "#09 Set large value.";

    char* textForkey = "name1";
    char* textForValue = "Sed ut (ÄÖÜäöüß@µ) unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo. Nemo enim ipsam voluptatem quia voluptas sit aspernatur aut odit aut fugit, sed quia consequuntur magni dolores eos qui ratione voluptatem sequi nesciunt. Neque porro quisquam est, qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit, sed quia non numquam eius modi tempora incidunt ut labore et dolore magnam aliquam quaerat voluptatem. Ut enim ad minima veniam, quis nostrum exercitationem ullam corporis suscipit laboriosam, nisi ut aliquid ex ea commodi consequatur? Quis autem vel eum iure reprehenderit qui in ea voluptate velit esse quam nihil molestiae consequatur, vel illum qui dolorem eum fugiat quo voluptas nulla pariatur?";

    struct associativeDynamicText* var1 = allocateAssociativeDynamicTextByKey(textForkey, __FILE__, __LINE__);

    if (NULL == var1)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    setValueInAssociativeDynamicText(&var1, textForValue, __FILE__, __LINE__);

    struct dynamicText* key = (*var1).internalKey;
    struct dynamicText* value = (*var1).internalValue;

    if (
        (customStrlen(textForkey) != customStrlen(getBytesPointerFromDynamicText(&key)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&key), textForkey, customStrlen(textForkey)))
        || (customStrlen(textForValue) != customStrlen(getBytesPointerFromDynamicText(&value)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&value), textForValue, customStrlen(textForValue)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeAssociativeDynamicText(&var1, __FILE__, __LINE__);

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
    printf("TEST SUITE: associative_dynamic_text.c file\n");

    executeTest1();
    executeTest2();
    executeTest3();
    executeTest4();
    executeTest5();
    executeTest6();
    executeTest7();
    executeTest8();
    executeTest9();

    return EXIT_SUCCESS;
}
