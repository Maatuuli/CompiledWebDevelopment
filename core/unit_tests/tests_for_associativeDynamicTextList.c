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
#include "../associative_dynamic_text.c"
#include "../associative_dynamic_text_list.c"
#include "helper_for_tests.c"


static void
executeTest1(void)
{
    char* titleFromTest = "#01 Minimal initialization and freeing of an empty list.";

    struct listForAssociativeDynamicText* list1 = newListForAssociativeDynamicText(__FILE__, __LINE__);

    if (NULL != list1)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeListForAssociativeDynamicText(&list1, __FILE__, __LINE__);

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
    char* titleFromTest = "#02 Add element with one-byte key into list.";

    struct listForAssociativeDynamicText* list1 = newListForAssociativeDynamicText(__FILE__, __LINE__);
    addElementByKeyInListForAssociativeDynamicText(&list1, "a", "", __FILE__, __LINE__);
    
    if (NULL == list1)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeListForAssociativeDynamicText(&list1, __FILE__, __LINE__);

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
    char* titleFromTest = "#03 Add element with multi-byte key into list.";

    struct listForAssociativeDynamicText* list1 = newListForAssociativeDynamicText(__FILE__, __LINE__);
    addElementByKeyInListForAssociativeDynamicText(&list1, "Ä", "", __FILE__, __LINE__);
    
    if (NULL == list1)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeListForAssociativeDynamicText(&list1, __FILE__, __LINE__);

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
    char* titleFromTest = "#04 Add element with regular key into list.";

    struct listForAssociativeDynamicText* list1 = newListForAssociativeDynamicText(__FILE__, __LINE__);
    addElementByKeyInListForAssociativeDynamicText(&list1, "name1", "", __FILE__, __LINE__);
    
    if (NULL == list1)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeListForAssociativeDynamicText(&list1, __FILE__, __LINE__);

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
    char* titleFromTest = "#05 Add element with large key into list.";

    char* largeKey = "Sed ut (ÄÖÜäöüß@µ) unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo. Nemo enim ipsam voluptatem quia voluptas sit aspernatur aut odit aut fugit, sed quia consequuntur magni dolores eos qui ratione voluptatem sequi nesciunt. Neque porro quisquam est, qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit, sed quia non numquam eius modi tempora incidunt ut labore et dolore magnam aliquam quaerat voluptatem. Ut enim ad minima veniam, quis nostrum exercitationem ullam corporis suscipit laboriosam, nisi ut aliquid ex ea commodi consequatur? Quis autem vel eum iure reprehenderit qui in ea voluptate velit esse quam nihil molestiae consequatur, vel illum qui dolorem eum fugiat quo voluptas nulla pariatur?";

    struct listForAssociativeDynamicText* list1 = newListForAssociativeDynamicText(__FILE__, __LINE__);
    addElementByKeyInListForAssociativeDynamicText(&list1, largeKey, "", __FILE__, __LINE__);
    
    if (NULL == list1)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeListForAssociativeDynamicText(&list1, __FILE__, __LINE__);

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
    char* titleFromTest = "#06 Add element with one-byte value into list.";

    struct listForAssociativeDynamicText* list1 = newListForAssociativeDynamicText(__FILE__, __LINE__);
    addElementByKeyInListForAssociativeDynamicText(&list1, "name1", "a", __FILE__, __LINE__);
    
    if (NULL == list1)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeListForAssociativeDynamicText(&list1, __FILE__, __LINE__);

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
    char* titleFromTest = "#07 Add element with multi-byte value into list.";

    struct listForAssociativeDynamicText* list1 = newListForAssociativeDynamicText(__FILE__, __LINE__);
    addElementByKeyInListForAssociativeDynamicText(&list1, "name1", "Ä", __FILE__, __LINE__);
    
    if (NULL == list1)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeListForAssociativeDynamicText(&list1, __FILE__, __LINE__);

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
    char* titleFromTest = "#08 Add element with regular value into list.";

    struct listForAssociativeDynamicText* list1 = newListForAssociativeDynamicText(__FILE__, __LINE__);
    addElementByKeyInListForAssociativeDynamicText(&list1, "name1", "value1", __FILE__, __LINE__);
    
    if (NULL == list1)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeListForAssociativeDynamicText(&list1, __FILE__, __LINE__);

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
    char* titleFromTest = "#09 Add element with large value into list.";

    char* largeValue = "Sed ut (ÄÖÜäöüß@µ) unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo. Nemo enim ipsam voluptatem quia voluptas sit aspernatur aut odit aut fugit, sed quia consequuntur magni dolores eos qui ratione voluptatem sequi nesciunt. Neque porro quisquam est, qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit, sed quia non numquam eius modi tempora incidunt ut labore et dolore magnam aliquam quaerat voluptatem. Ut enim ad minima veniam, quis nostrum exercitationem ullam corporis suscipit laboriosam, nisi ut aliquid ex ea commodi consequatur? Quis autem vel eum iure reprehenderit qui in ea voluptate velit esse quam nihil molestiae consequatur, vel illum qui dolorem eum fugiat quo voluptas nulla pariatur?";
    
    struct listForAssociativeDynamicText* list1 = newListForAssociativeDynamicText(__FILE__, __LINE__);
    addElementByKeyInListForAssociativeDynamicText(&list1, "name1", largeValue, __FILE__, __LINE__);
    
    if (NULL == list1)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeListForAssociativeDynamicText(&list1, __FILE__, __LINE__);

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
    char* titleFromTest = "#10 Add 3 regular elements into a list.";

    struct listForAssociativeDynamicText* list1 = newListForAssociativeDynamicText(__FILE__, __LINE__);
    addElementByKeyInListForAssociativeDynamicText(&list1, "name1", "value1", __FILE__, __LINE__);
    addElementByKeyInListForAssociativeDynamicText(&list1, "name2", "value2", __FILE__, __LINE__);
    addElementByKeyInListForAssociativeDynamicText(&list1, "name3", "value3", __FILE__, __LINE__);
    
    if (NULL == list1)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeListForAssociativeDynamicText(&list1, __FILE__, __LINE__);

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
    char* titleFromTest = "#11 Check if list with 0 elements is empty.";

    struct listForAssociativeDynamicText* list1 = newListForAssociativeDynamicText(__FILE__, __LINE__);

    if (
        (NULL != list1)
        || (0 == isListEmptyForAssociativeDynamicText(&list1, __FILE__, __LINE__))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeListForAssociativeDynamicText(&list1, __FILE__, __LINE__);

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
    char* titleFromTest = "#12 Check if list with 1 element is empty.";

    struct listForAssociativeDynamicText* list1 = newListForAssociativeDynamicText(__FILE__, __LINE__);
    addElementByKeyInListForAssociativeDynamicText(&list1, "name1", "value1", __FILE__, __LINE__);

    if (
        (NULL == list1)
        || (0 != isListEmptyForAssociativeDynamicText(&list1, __FILE__, __LINE__))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeListForAssociativeDynamicText(&list1, __FILE__, __LINE__);

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
    char* titleFromTest = "#13 Check if list with 2 elements is empty.";

    struct listForAssociativeDynamicText* list1 = newListForAssociativeDynamicText(__FILE__, __LINE__);
    addElementByKeyInListForAssociativeDynamicText(&list1, "name1", "value1", __FILE__, __LINE__);
    addElementByKeyInListForAssociativeDynamicText(&list1, "name2", "value2", __FILE__, __LINE__);

    if (
        (NULL == list1)
        || (0 != isListEmptyForAssociativeDynamicText(&list1, __FILE__, __LINE__))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeListForAssociativeDynamicText(&list1, __FILE__, __LINE__);

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
    char* titleFromTest = "#14 Check if regular key exists in empty list.";

    struct listForAssociativeDynamicText* list1 = newListForAssociativeDynamicText(__FILE__, __LINE__);

    if (
        (NULL != list1)
        || (0 != checkIfKeyExistsInListForAssociativeDynamicText(&list1, "name1", __FILE__, __LINE__))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeListForAssociativeDynamicText(&list1, __FILE__, __LINE__);

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
    char* titleFromTest = "#15 Check if non-existing key exists in list with 3 elements.";

    struct listForAssociativeDynamicText* list1 = newListForAssociativeDynamicText(__FILE__, __LINE__);
    addElementByKeyInListForAssociativeDynamicText(&list1, "name1", "value1", __FILE__, __LINE__);
    addElementByKeyInListForAssociativeDynamicText(&list1, "name2", "value2", __FILE__, __LINE__);
    addElementByKeyInListForAssociativeDynamicText(&list1, "name3", "value3", __FILE__, __LINE__);

    if (
        (NULL == list1)
        || (0 != checkIfKeyExistsInListForAssociativeDynamicText(&list1, "non-existing-key", __FILE__, __LINE__))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeListForAssociativeDynamicText(&list1, __FILE__, __LINE__);

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
executeTest16(void)
{
    char* titleFromTest = "#16 Check if existing keys exist in list with 3 elements.";

    struct listForAssociativeDynamicText* list1 = newListForAssociativeDynamicText(__FILE__, __LINE__);
    addElementByKeyInListForAssociativeDynamicText(&list1, "name1", "value1", __FILE__, __LINE__);
    addElementByKeyInListForAssociativeDynamicText(&list1, "name2", "value2", __FILE__, __LINE__);
    addElementByKeyInListForAssociativeDynamicText(&list1, "name3", "value3", __FILE__, __LINE__);

    if (
        (NULL == list1)
        || (1 != checkIfKeyExistsInListForAssociativeDynamicText(&list1, "name1", __FILE__, __LINE__))
        || (1 != checkIfKeyExistsInListForAssociativeDynamicText(&list1, "name2", __FILE__, __LINE__))
        || (1 != checkIfKeyExistsInListForAssociativeDynamicText(&list1, "name3", __FILE__, __LINE__))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeListForAssociativeDynamicText(&list1, __FILE__, __LINE__);

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
executeTest17(void)
{
    char* titleFromTest = "#17 Get different elements with their key from a list.";

    char* textForKey1 = "a";
    char* textForKey2 = "ÄÖÜ";
    char* textForKey3 = "Sed ut (ÄÖÜäöüß@µ) unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo. Nemo enim ipsam voluptatem quia voluptas sit aspernatur aut odit aut fugit, sed quia consequuntur magni dolores eos qui ratione voluptatem sequi nesciunt. Neque porro quisquam est, qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit, sed quia non numquam eius modi tempora incidunt ut labore et dolore magnam aliquam quaerat voluptatem. Ut enim ad minima veniam, quis nostrum exercitationem ullam corporis suscipit laboriosam, nisi ut aliquid ex ea commodi consequatur? Quis autem vel eum iure reprehenderit qui in ea voluptate velit esse quam nihil molestiae consequatur, vel illum qui dolorem eum fugiat quo voluptas nulla pariatur?";

    char* textForValue1 = "value1";
    char* textForValue2 = "value2";
    char* textForValue3 = "value3";

    struct listForAssociativeDynamicText* list1 = newListForAssociativeDynamicText(__FILE__, __LINE__);
    addElementByKeyInListForAssociativeDynamicText(&list1, textForKey1, textForValue1, __FILE__, __LINE__);
    addElementByKeyInListForAssociativeDynamicText(&list1, textForKey2, textForValue2, __FILE__, __LINE__);
    addElementByKeyInListForAssociativeDynamicText(&list1, textForKey3, textForValue3, __FILE__, __LINE__);

    struct associativeDynamicText* var1 = getElementByKeyFromListForAssociativeDynamicText(&list1, textForKey1, __FILE__, __LINE__);
    struct associativeDynamicText* var2 = getElementByKeyFromListForAssociativeDynamicText(&list1, textForKey2, __FILE__, __LINE__);
    struct associativeDynamicText* var3 = getElementByKeyFromListForAssociativeDynamicText(&list1, textForKey3, __FILE__, __LINE__);

    struct dynamicText* text1 = (*var1).internalValue;
    struct dynamicText* text2 = (*var2).internalValue;
    struct dynamicText* text3 = (*var3).internalValue;

    if (
        (NULL == list1)
        || (1 != isExactTextMatch(getBytesPointerFromDynamicText(&text1), textForValue1, __FILE__, __LINE__))
        || (1 != isExactTextMatch(getBytesPointerFromDynamicText(&text2), textForValue2, __FILE__, __LINE__))
        || (1 != isExactTextMatch(getBytesPointerFromDynamicText(&text3), textForValue3, __FILE__, __LINE__))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeListForAssociativeDynamicText(&list1, __FILE__, __LINE__);

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
    printf("TEST SUITE: associative_dynamic_text_list.c file\n");

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
    executeTest16();
    executeTest17();

    return EXIT_SUCCESS;
}
