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
#include "helper_for_tests.c"



static void
executeTest1(void)
{
    char* titleFromTest = "#01 Minimal initialization and freeing of an empty list for dynamic texts.";

    struct listForDynamicText* list1 = newListForDynamicText(__FILE__, __LINE__);

    if (NULL != list1)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
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
    char* titleFromTest = "#02 Push an empty text into an empty list for dynamic texts.";

    struct listForDynamicText* list1 = newListForDynamicText(__FILE__, __LINE__);

    pushElementInListForDynamicText(&list1, "", __FILE__, __LINE__);

    if (NULL == list1)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
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
    char* titleFromTest = "#03 Push an empty text into a not empty list for dynamic texts.";

    struct listForDynamicText* list1 = newListForDynamicText(__FILE__, __LINE__);

    pushElementInListForDynamicText(&list1, "This ia a normal text (ÄÖÜäöüß@µ).", __FILE__, __LINE__);
    pushElementInListForDynamicText(&list1, "", __FILE__, __LINE__);

    if (NULL == list1)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
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
    char* titleFromTest = "#04 Push an ordinary text into an empty list for dynamic texts.";

    struct listForDynamicText* list1 = newListForDynamicText(__FILE__, __LINE__);

    pushElementInListForDynamicText(&list1, "This ia a normal text (ÄÖÜäöüß@µ).", __FILE__, __LINE__);

    if (NULL == list1)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
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
    char* titleFromTest = "#05 Push an ordinary text into a not empty list for dynamic texts.";

    struct listForDynamicText* list1 = newListForDynamicText(__FILE__, __LINE__);

    pushElementInListForDynamicText(&list1, "Initial text (ÄÖÜäöüß@µ).", __FILE__, __LINE__);
    pushElementInListForDynamicText(&list1, "This ia a normal text (ÄÖÜäöüß@µ).", __FILE__, __LINE__);

    if (NULL == list1)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
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
    char* titleFromTest = "#06 Push a long text into an empty list for dynamic texts.";

    char* sentence1 = "Sed ut (ÄÖÜäöüß@µ) unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo. Nemo enim ipsam voluptatem quia voluptas sit aspernatur aut odit aut fugit, sed quia consequuntur magni dolores eos qui ratione voluptatem sequi nesciunt. Neque porro quisquam est, qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit, sed quia non numquam eius modi tempora incidunt ut labore et dolore magnam aliquam quaerat voluptatem. Ut enim ad minima veniam, quis nostrum exercitationem ullam corporis suscipit laboriosam, nisi ut aliquid ex ea commodi consequatur? Quis autem vel eum iure reprehenderit qui in ea voluptate velit esse quam nihil molestiae consequatur, vel illum qui dolorem eum fugiat quo voluptas nulla pariatur?";
    
    struct listForDynamicText* list1 = newListForDynamicText(__FILE__, __LINE__);

    pushElementInListForDynamicText(&list1, sentence1, __FILE__, __LINE__);

    if (NULL == list1)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
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
    char* titleFromTest = "#07 Push a long text into a not empty list for dynamic texts.";

    char* sentence1 = "Sed ut (ÄÖÜäöüß@µ) unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo. Nemo enim ipsam voluptatem quia voluptas sit aspernatur aut odit aut fugit, sed quia consequuntur magni dolores eos qui ratione voluptatem sequi nesciunt. Neque porro quisquam est, qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit, sed quia non numquam eius modi tempora incidunt ut labore et dolore magnam aliquam quaerat voluptatem. Ut enim ad minima veniam, quis nostrum exercitationem ullam corporis suscipit laboriosam, nisi ut aliquid ex ea commodi consequatur? Quis autem vel eum iure reprehenderit qui in ea voluptate velit esse quam nihil molestiae consequatur, vel illum qui dolorem eum fugiat quo voluptas nulla pariatur?";
    
    struct listForDynamicText* list1 = newListForDynamicText(__FILE__, __LINE__);

    pushElementInListForDynamicText(&list1, "This ia a normal text (ÄÖÜäöüß@µ).", __FILE__, __LINE__);
    pushElementInListForDynamicText(&list1, sentence1, __FILE__, __LINE__);

    if (NULL == list1)
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
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
    char* titleFromTest = "#08 Count the amount of list elements from an empty list.";

    struct listForDynamicText* list1 = newListForDynamicText(__FILE__, __LINE__);

    int countForList1 = countElementsInListForDynamicText(&list1, __FILE__, __LINE__);

    if (
        (NULL != list1)
        || (0 != countForList1)
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
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
    char* titleFromTest = "#09 Count the amount of list elements from a list with 1 element.";

    struct listForDynamicText* list1 = newListForDynamicText(__FILE__, __LINE__);

    pushElementInListForDynamicText(&list1, "This is a text (ÄÖÜäöüß@µ).", __FILE__, __LINE__);

    int countForList1 = countElementsInListForDynamicText(&list1, __FILE__, __LINE__);

    if (
        (NULL == list1)
        || (1 != countForList1)
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
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
    char* titleFromTest = "#10 Count the amount of list elements from a list with 3 elements.";

    struct listForDynamicText* list1 = newListForDynamicText(__FILE__, __LINE__);

    pushElementInListForDynamicText(&list1, "This is a text (ÄÖÜäöüß@µ).", __FILE__, __LINE__);
    pushElementInListForDynamicText(&list1, "Another text (ÄÖÜäöüß@µ).", __FILE__, __LINE__);
    pushElementInListForDynamicText(&list1, "", __FILE__, __LINE__);

    int countForList1 = countElementsInListForDynamicText(&list1, __FILE__, __LINE__);

    if (
        (NULL == list1)
        || (3 != countForList1)
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
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
    char* titleFromTest = "#11 Check emptyness for an empty list.";

    struct listForDynamicText* list1 = newListForDynamicText(__FILE__, __LINE__);

    if (
        (NULL != list1)
        || (1 != isListEmptyForDynamicText(&list1, __FILE__, __LINE__))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
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
    char* titleFromTest = "#12 Check emptyness for a list with 1 element.";

    struct listForDynamicText* list1 = newListForDynamicText(__FILE__, __LINE__);
    pushElementInListForDynamicText(&list1, "This is a text (ÄÖÜäöüß@µ).", __FILE__, __LINE__);

    int restult = isListEmptyForDynamicText(&list1, __FILE__, __LINE__);
    
    if (
        (NULL == list1)
        || (0 != restult)
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
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
    char* titleFromTest = "#13 Check emptyness for a list with 3 list elements.";

    struct listForDynamicText* list1 = newListForDynamicText(__FILE__, __LINE__);
    pushElementInListForDynamicText(&list1, "This is a text (ÄÖÜäöüß@µ).", __FILE__, __LINE__);
    pushElementInListForDynamicText(&list1, "Another text (ÄÖÜäöüß@µ).", __FILE__, __LINE__);
    pushElementInListForDynamicText(&list1, "", __FILE__, __LINE__);

    int restult = isListEmptyForDynamicText(&list1, __FILE__, __LINE__);
    
    if (
        (NULL == list1)
        || (0 != restult)
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
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
    char* titleFromTest = "#14 Get the correct element #1 from a list with 3 elements.";

    struct listForDynamicText* list1 = newListForDynamicText(__FILE__, __LINE__);

    char* sentence1 = "This is a text (ÄÖÜäöüß@µ).";
    char* sentence2 = "Another text (ÄÖÜäöüß@µ).";
    char* sentence3 = "";

    pushElementInListForDynamicText(&list1, sentence1, __FILE__, __LINE__);
    pushElementInListForDynamicText(&list1, sentence2, __FILE__, __LINE__);
    pushElementInListForDynamicText(&list1, sentence3, __FILE__, __LINE__);

    struct dynamicText* var1 = getElementByIndexFromListForDynamicText(&list1, 0, __FILE__, __LINE__);

    if (
        (NULL == list1)
        || (NULL == var1)
        || (customStrlen(sentence1) != customStrlen(getBytesPointerFromDynamicText(&var1)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&var1), sentence1, customStrlen(sentence1)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
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
    char* titleFromTest = "#15 Get the correct element #2 from a list with 3 elements.";

    struct listForDynamicText* list1 = newListForDynamicText(__FILE__, __LINE__);

    char* sentence1 = "This is a text (ÄÖÜäöüß@µ).";
    char* sentence2 = "Another text (ÄÖÜäöüß@µ).";
    char* sentence3 = "";

    pushElementInListForDynamicText(&list1, sentence1, __FILE__, __LINE__);
    pushElementInListForDynamicText(&list1, sentence2, __FILE__, __LINE__);
    pushElementInListForDynamicText(&list1, sentence3, __FILE__, __LINE__);

    struct dynamicText* var1 = getElementByIndexFromListForDynamicText(&list1, 1, __FILE__, __LINE__);

    if (
        (NULL == list1)
        || (NULL == var1)
        || (customStrlen(sentence2) != customStrlen(getBytesPointerFromDynamicText(&var1)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&var1), sentence2, customStrlen(sentence2)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
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
executeTest16(void)
{
    char* titleFromTest = "#16 Get the correct element #3 from a list with 3 elements.";

    struct listForDynamicText* list1 = newListForDynamicText(__FILE__, __LINE__);

    char* sentence1 = "This is a text (ÄÖÜäöüß@µ).";
    char* sentence2 = "Another text (ÄÖÜäöüß@µ).";
    char* sentence3 = "";

    pushElementInListForDynamicText(&list1, sentence1, __FILE__, __LINE__);
    pushElementInListForDynamicText(&list1, sentence2, __FILE__, __LINE__);
    pushElementInListForDynamicText(&list1, sentence3, __FILE__, __LINE__);

    struct dynamicText* var1 = getElementByIndexFromListForDynamicText(&list1, 2, __FILE__, __LINE__);

    if (
        (NULL == list1)
        || (NULL == var1)
        || (customStrlen(sentence3) != customStrlen(getBytesPointerFromDynamicText(&var1)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&var1), sentence3, customStrlen(sentence3)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
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
    printf("TEST SUITE: dynamic_text_list.c file\n");

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

    return EXIT_SUCCESS;
}
