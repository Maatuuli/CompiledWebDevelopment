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
    char* titleFromTest = "#01 Explode a text with an one-letter separator which do not exist.";

    char* expectedText = "name1";
    
    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, "name1", __FILE__, __LINE__);
    
    struct listForDynamicText* list1 = newListForDynamicText(__FILE__, __LINE__);
    explodeDynamicText(&var1, "&", &list1, __FILE__, __LINE__);

    struct dynamicText* var2 = getElementByIndexFromListForDynamicText(&list1, 0, __FILE__, __LINE__);

    if (
        (NULL == list1)
        || (1 != countElementsInListForDynamicText(&list1, __FILE__, __LINE__))
        || (customStrlen(expectedText) != customStrlen(getBytesPointerFromDynamicText(&var2)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&var2), expectedText, customStrlen(expectedText)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeDynamicText(&var1, __FILE__, __LINE__);
    freeListForDynamicText(&list1, __FILE__, __LINE__);

    if (
        (NULL == list1)
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
    char* titleFromTest = "#02 Explode a text with a normal text which do not exist.";

    char* expectedText = "name1";
    
    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, "name1", __FILE__, __LINE__);
    
    struct listForDynamicText* list1 = newListForDynamicText(__FILE__, __LINE__);
    explodeDynamicText(&var1, "ein", &list1, __FILE__, __LINE__);

    struct dynamicText* var2 = getElementByIndexFromListForDynamicText(&list1, 0, __FILE__, __LINE__);

    if (
        (NULL == list1)
        || (1 != countElementsInListForDynamicText(&list1, __FILE__, __LINE__))
        || (customStrlen(expectedText) != customStrlen(getBytesPointerFromDynamicText(&var2)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&var2), expectedText, customStrlen(expectedText)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeDynamicText(&var1, __FILE__, __LINE__);
    freeListForDynamicText(&list1, __FILE__, __LINE__);

    if (
        (NULL == list1)
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
    char* titleFromTest = "#03 Explode a text with a multi-byte separator which do not exist.";

    char* expectedText = "name1";
    
    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, "name1", __FILE__, __LINE__);
    
    struct listForDynamicText* list1 = newListForDynamicText(__FILE__, __LINE__);
    explodeDynamicText(&var1, "ü", &list1, __FILE__, __LINE__);

    struct dynamicText* var2 = getElementByIndexFromListForDynamicText(&list1, 0, __FILE__, __LINE__);

    if (
        (NULL == list1)
        || (1 != countElementsInListForDynamicText(&list1, __FILE__, __LINE__))
        || (customStrlen(expectedText) != customStrlen(getBytesPointerFromDynamicText(&var2)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&var2), expectedText, customStrlen(expectedText)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeDynamicText(&var1, __FILE__, __LINE__);
    freeListForDynamicText(&list1, __FILE__, __LINE__);

    if (
        (NULL == list1)
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
    char* titleFromTest = "#04 Explode a text with a multi-byte text which do not exist.";

    char* expectedText = "name1";
    
    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, "name1", __FILE__, __LINE__);
    
    struct listForDynamicText* list1 = newListForDynamicText(__FILE__, __LINE__);
    explodeDynamicText(&var1, "üäö", &list1, __FILE__, __LINE__);

    struct dynamicText* var2 = getElementByIndexFromListForDynamicText(&list1, 0, __FILE__, __LINE__);

    if (
        (NULL == list1)
        || (1 != countElementsInListForDynamicText(&list1, __FILE__, __LINE__))
        || (customStrlen(expectedText) != customStrlen(getBytesPointerFromDynamicText(&var2)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&var2), expectedText, customStrlen(expectedText)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeDynamicText(&var1, __FILE__, __LINE__);
    freeListForDynamicText(&list1, __FILE__, __LINE__);

    if (
        (NULL == list1)
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
    char* titleFromTest = "#05 Explode a classical key value text which one parameter pair.";

    char* expectedText1 = "name";
    char* expectedText2 = "value";
    
    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, "name=value", __FILE__, __LINE__);
    
    struct listForDynamicText* list1 = newListForDynamicText(__FILE__, __LINE__);
    explodeDynamicText(&var1, "=", &list1, __FILE__, __LINE__);

    struct dynamicText* element1 = getElementByIndexFromListForDynamicText(&list1, 0, __FILE__, __LINE__);
    struct dynamicText* element2 = getElementByIndexFromListForDynamicText(&list1, 1, __FILE__, __LINE__);

    if (
        (NULL == list1)
        || (2 != countElementsInListForDynamicText(&list1, __FILE__, __LINE__))
        || (customStrlen(expectedText1) != customStrlen(getBytesPointerFromDynamicText(&element1)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&element1), expectedText1, customStrlen(expectedText1)))
        || (customStrlen(expectedText2) != customStrlen(getBytesPointerFromDynamicText(&element2)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&element2), expectedText2, customStrlen(expectedText2)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeDynamicText(&var1, __FILE__, __LINE__);
    freeListForDynamicText(&list1, __FILE__, __LINE__);

    if (
        (NULL == list1)
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
    char* titleFromTest = "#06 Explode a classical key value text with many parameter pairs.";

    char* expectedText1 = "name1=value1";
    char* expectedText2 = "name2=value2";
    char* expectedText3 = "name3=value3";
    char* expectedText4 = "name4=value4";
    
    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, "name1=value1&name2=value2&name3=value3&name4=value4", __FILE__, __LINE__);
    
    struct listForDynamicText* list1 = newListForDynamicText(__FILE__, __LINE__);
    explodeDynamicText(&var1, "&", &list1, __FILE__, __LINE__);

    struct dynamicText* element1 = getElementByIndexFromListForDynamicText(&list1, 0, __FILE__, __LINE__);
    struct dynamicText* element2 = getElementByIndexFromListForDynamicText(&list1, 1, __FILE__, __LINE__);
    struct dynamicText* element3 = getElementByIndexFromListForDynamicText(&list1, 2, __FILE__, __LINE__);
    struct dynamicText* element4 = getElementByIndexFromListForDynamicText(&list1, 3, __FILE__, __LINE__);

    if (
        (NULL == list1)
        || (4 != countElementsInListForDynamicText(&list1, __FILE__, __LINE__))
        || (customStrlen(expectedText1) != customStrlen(getBytesPointerFromDynamicText(&element1)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&element1), expectedText1, customStrlen(expectedText1)))
        || (customStrlen(expectedText2) != customStrlen(getBytesPointerFromDynamicText(&element2)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&element2), expectedText2, customStrlen(expectedText2)))
        || (customStrlen(expectedText3) != customStrlen(getBytesPointerFromDynamicText(&element3)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&element3), expectedText3, customStrlen(expectedText3)))
        || (customStrlen(expectedText4) != customStrlen(getBytesPointerFromDynamicText(&element4)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&element4), expectedText4, customStrlen(expectedText4)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeDynamicText(&var1, __FILE__, __LINE__);
    freeListForDynamicText(&list1, __FILE__, __LINE__);

    if (
        (NULL == list1)
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
    char* titleFromTest = "#07 Explode a classical key value text which has only key part.";

    char* expectedText1 = "key";
    char* expectedText2 = "";
    
    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, "key=", __FILE__, __LINE__);
    
    struct listForDynamicText* list1 = newListForDynamicText(__FILE__, __LINE__);
    explodeDynamicText(&var1, "=", &list1, __FILE__, __LINE__);

    struct dynamicText* element1 = getElementByIndexFromListForDynamicText(&list1, 0, __FILE__, __LINE__);
    struct dynamicText* element2 = getElementByIndexFromListForDynamicText(&list1, 1, __FILE__, __LINE__);

    if (
        (NULL == list1)
        || (2 != countElementsInListForDynamicText(&list1, __FILE__, __LINE__))
        || (customStrlen(expectedText1) != customStrlen(getBytesPointerFromDynamicText(&element1)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&element1), expectedText1, customStrlen(expectedText1)))
        || (customStrlen(expectedText2) != customStrlen(getBytesPointerFromDynamicText(&element2)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&element2), expectedText2, customStrlen(expectedText2)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeDynamicText(&var1, __FILE__, __LINE__);
    freeListForDynamicText(&list1, __FILE__, __LINE__);

    if (
        (NULL == list1)
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
    char* titleFromTest = "#08 Explode a classical key value text which has only value part.";

    char* expectedText1 = "";
    char* expectedText2 = "value";
    
    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, "=value", __FILE__, __LINE__);
    
    struct listForDynamicText* list1 = newListForDynamicText(__FILE__, __LINE__);
    explodeDynamicText(&var1, "=", &list1, __FILE__, __LINE__);

    struct dynamicText* element1 = getElementByIndexFromListForDynamicText(&list1, 0, __FILE__, __LINE__);
    struct dynamicText* element2 = getElementByIndexFromListForDynamicText(&list1, 1, __FILE__, __LINE__);

    if (
        (NULL == list1)
        || (2 != countElementsInListForDynamicText(&list1, __FILE__, __LINE__))
        || (customStrlen(expectedText1) != customStrlen(getBytesPointerFromDynamicText(&element1)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&element1), expectedText1, customStrlen(expectedText1)))
        || (customStrlen(expectedText2) != customStrlen(getBytesPointerFromDynamicText(&element2)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&element2), expectedText2, customStrlen(expectedText2)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeDynamicText(&var1, __FILE__, __LINE__);
    freeListForDynamicText(&list1, __FILE__, __LINE__);

    if (
        (NULL == list1)
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
    char* titleFromTest = "#09 Explode a classical key value text which has different configured pairs.";

    char* expectedText1 = "key1=value1";
    char* expectedText2 = "key2=";
    char* expectedText3 = "key3";
    
    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, "key1=value1&key2=&key3", __FILE__, __LINE__);
    
    struct listForDynamicText* list1 = newListForDynamicText(__FILE__, __LINE__);
    explodeDynamicText(&var1, "&", &list1, __FILE__, __LINE__);

    struct dynamicText* element1 = getElementByIndexFromListForDynamicText(&list1, 0, __FILE__, __LINE__);
    struct dynamicText* element2 = getElementByIndexFromListForDynamicText(&list1, 1, __FILE__, __LINE__);
    struct dynamicText* element3 = getElementByIndexFromListForDynamicText(&list1, 2, __FILE__, __LINE__);

    if (
        (NULL == list1)
        || (3 != countElementsInListForDynamicText(&list1, __FILE__, __LINE__))
        || (customStrlen(expectedText1) != customStrlen(getBytesPointerFromDynamicText(&element1)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&element1), expectedText1, customStrlen(expectedText1)))
        || (customStrlen(expectedText2) != customStrlen(getBytesPointerFromDynamicText(&element2)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&element2), expectedText2, customStrlen(expectedText2)))
        || (customStrlen(expectedText3) != customStrlen(getBytesPointerFromDynamicText(&element3)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&element3), expectedText3, customStrlen(expectedText3)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeDynamicText(&var1, __FILE__, __LINE__);
    freeListForDynamicText(&list1, __FILE__, __LINE__);

    if (
        (NULL == list1)
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
    char* titleFromTest = "#10 Explode an one-byte text with a multi-byte letter.";

    char* expectedText1 = " ";
    
    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, " ", __FILE__, __LINE__);
    
    struct listForDynamicText* list1 = newListForDynamicText(__FILE__, __LINE__);
    explodeDynamicText(&var1, "ü", &list1, __FILE__, __LINE__);

    struct dynamicText* element1 = getElementByIndexFromListForDynamicText(&list1, 0, __FILE__, __LINE__);

    if (
        (NULL == list1)
        || (1 != countElementsInListForDynamicText(&list1, __FILE__, __LINE__))
        || (customStrlen(expectedText1) != customStrlen(getBytesPointerFromDynamicText(&element1)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&element1), expectedText1, customStrlen(expectedText1)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeDynamicText(&var1, __FILE__, __LINE__);
    freeListForDynamicText(&list1, __FILE__, __LINE__);

    if (
        (NULL == list1)
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
    char* titleFromTest = "#11 Explode an one-byte text with a multi-byte text.";

    char* expectedText1 = "üüä";
    
    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, "üüä", __FILE__, __LINE__);
    
    struct listForDynamicText* list1 = newListForDynamicText(__FILE__, __LINE__);
    explodeDynamicText(&var1, " ", &list1, __FILE__, __LINE__);

    struct dynamicText* element1 = getElementByIndexFromListForDynamicText(&list1, 0, __FILE__, __LINE__);

    if (
        (NULL == list1)
        || (1 != countElementsInListForDynamicText(&list1, __FILE__, __LINE__))
        || (customStrlen(expectedText1) != customStrlen(getBytesPointerFromDynamicText(&element1)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&element1), expectedText1, customStrlen(expectedText1)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeDynamicText(&var1, __FILE__, __LINE__);
    freeListForDynamicText(&list1, __FILE__, __LINE__);

    if (
        (NULL == list1)
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
    char* titleFromTest = "#12 Explode a large text with a multi byte text.";

    char* expectedText1 = "This is a chair description. Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis at vero eros et accumsan et iusto odio dignissim qui blandit praesent luptatum zzril delenit augue duis dolore te feugait nulla facilisi.";

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, "This is a chair description. Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis at vero eros et accumsan et iusto odio dignissim qui blandit praesent luptatum zzril delenit augue duis dolore te feugait nulla facilisi.", __FILE__, __LINE__);
    
    struct listForDynamicText* list1 = newListForDynamicText(__FILE__, __LINE__);
    explodeDynamicText(&var1, "INC", &list1, __FILE__, __LINE__);

    struct dynamicText* element1 = getElementByIndexFromListForDynamicText(&list1, 0, __FILE__, __LINE__);

    if (
        (NULL == list1)
        || (1 != countElementsInListForDynamicText(&list1, __FILE__, __LINE__))
        || (customStrlen(expectedText1) != customStrlen(getBytesPointerFromDynamicText(&element1)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&element1), expectedText1, customStrlen(expectedText1)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeDynamicText(&var1, __FILE__, __LINE__);
    freeListForDynamicText(&list1, __FILE__, __LINE__);

    if (
        (NULL == list1)
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
    char* titleFromTest = "#13 ???.";

    // char* expectedText1 = "routing=/url/new";

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    
    for (int i = 0; i < ((*var1).amountOfBytes - 1); i++)
    {
        (*var1).bytes[i] = 'a';
    }

    (*var1).bytes[(*var1).amountOfBytes - 2] = '&';
    
    struct listForDynamicText* list1 = newListForDynamicText(__FILE__, __LINE__);
    explodeDynamicText(&var1, "&", &list1, __FILE__, __LINE__);

    freeDynamicText(&var1, __FILE__, __LINE__);
    freeListForDynamicText(&list1, __FILE__, __LINE__);

    if (
        (NULL == list1)
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
    char* titleFromTest = "#14 ???.";

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, "aaaei", __FILE__, __LINE__);
    
    struct listForDynamicText* list1 = newListForDynamicText(__FILE__, __LINE__);
    explodeDynamicText(&var1, "ein", &list1, __FILE__, __LINE__);

    freeDynamicText(&var1, __FILE__, __LINE__);
    freeListForDynamicText(&list1, __FILE__, __LINE__);

    if (
        (NULL == list1)
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
executeTest15(void)
{
    char* titleFromTest = "#15 ???.";

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, "aaaein", __FILE__, __LINE__);
    
    struct listForDynamicText* list1 = newListForDynamicText(__FILE__, __LINE__);
    explodeDynamicText(&var1, "ein", &list1, __FILE__, __LINE__);

    freeDynamicText(&var1, __FILE__, __LINE__);
    freeListForDynamicText(&list1, __FILE__, __LINE__);

    if (
        (NULL == list1)
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
    printf("TEST SUITE: explodeDynamicText function\n");

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
    executeTest15();
    
    return EXIT_SUCCESS;
}
