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
#include "helper_for_tests.c"


static void
checkIfUnusedMemoryIsSetUpAsZero(char* titleFromTest, struct dynamicText** text, char* filename, int lineNumber)
{
    for (int i = customStrlen(getBytesPointerFromDynamicText(text)); i <= ((*text)->amountOfBytes - 1); i++)
    {
        if ('\0' == (*text)->bytes[i])
        {
            continue;
        }
        
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
}


static void
executeTest1(void)
{
    char* titleFromTest = "#01 Minimal initialization and freeing of empty dynamic texts.";

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    checkIfUnusedMemoryIsSetUpAsZero(titleFromTest, &var1, __FILE__, __LINE__);
    
    if (
        (NULL == var1)
        || (customStrlen("") != customStrlen(getBytesPointerFromDynamicText(&var1)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&var1), "", customStrlen("")))
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
    char* titleFromTest = "#02 Assign an empty text to a dynamic text.";

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    checkIfUnusedMemoryIsSetUpAsZero(titleFromTest, &var1, __FILE__, __LINE__);
    
    assignDynamicText(&var1, "", __FILE__, __LINE__);
    checkIfUnusedMemoryIsSetUpAsZero(titleFromTest, &var1, __FILE__, __LINE__);

    if (
        (customStrlen("") != customStrlen(getBytesPointerFromDynamicText(&var1)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&var1), "", customStrlen("")))
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
    char* titleFromTest = "#03 Assign an ordinary text to a dynamic text.";

    char* ordinaryText = "This ia an ordinary text (ÄÖÜäöüß@µ).";
    
    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    checkIfUnusedMemoryIsSetUpAsZero(titleFromTest, &var1, __FILE__, __LINE__);

    assignDynamicText(&var1, ordinaryText, __FILE__, __LINE__);
    checkIfUnusedMemoryIsSetUpAsZero(titleFromTest, &var1, __FILE__, __LINE__);

    if (
        (customStrlen(ordinaryText) != customStrlen(getBytesPointerFromDynamicText(&var1)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&var1), ordinaryText, customStrlen(ordinaryText)))
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
    char* titleFromTest = "#04 Assign a text with the longest possible length without triggering a reallocation.";

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    checkIfUnusedMemoryIsSetUpAsZero(titleFromTest, &var1, __FILE__, __LINE__);

    int oldAmountOfReallocations = globaleAmountOfReallocations;

    char* exampleText = "Adipiscing elit, sed do eiusmod tempor incididunt ut labore et.";
                      // 123456789012345678901234567890123456789012345678901234567890123
                      // 1       10        20        30        40        50        60 63
    
    assignDynamicText(&var1, exampleText, __FILE__, __LINE__);
    checkIfUnusedMemoryIsSetUpAsZero(titleFromTest, &var1, __FILE__, __LINE__);

    if (
        (customStrlen(exampleText) != (getMinimumAmountOfBytesForAllocation(__FILE__, __LINE__) - 1))
        || (customStrlen(exampleText) != customStrlen(getBytesPointerFromDynamicText(&var1)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&var1), exampleText, customStrlen(exampleText)))
        || (oldAmountOfReallocations != globaleAmountOfReallocations)
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
    char* titleFromTest = "#05 Assign on every step growing texts to a dynamic text.";

    char* sentence1 = "Just (ÄÖÜäöüß@µ).";
    char* sentence2 = "Just some words (ÄÖÜäöüß@µ).";
    char* sentence3 = "Just some words for a sentence (ÄÖÜäöüß@µ).";
    
    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    checkIfUnusedMemoryIsSetUpAsZero(titleFromTest, &var1, __FILE__, __LINE__);
    
    assignDynamicText(&var1, sentence1, __FILE__, __LINE__);
    checkIfUnusedMemoryIsSetUpAsZero(titleFromTest, &var1, __FILE__, __LINE__);

    if (
        (customStrlen(sentence1) != customStrlen(getBytesPointerFromDynamicText(&var1)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&var1), sentence1, customStrlen(sentence1)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    assignDynamicText(&var1, sentence2, __FILE__, __LINE__);
    checkIfUnusedMemoryIsSetUpAsZero(titleFromTest, &var1, __FILE__, __LINE__);

    if (
        (customStrlen(sentence2) != customStrlen(getBytesPointerFromDynamicText(&var1)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&var1), sentence2, customStrlen(sentence2)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    assignDynamicText(&var1, sentence3, __FILE__, __LINE__);
    checkIfUnusedMemoryIsSetUpAsZero(titleFromTest, &var1, __FILE__, __LINE__);

    if (
        (customStrlen(sentence3) != customStrlen(getBytesPointerFromDynamicText(&var1)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&var1), sentence3, customStrlen(sentence3)))
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
executeTest6(void)
{
    char* titleFromTest = "#06 Assign on every step shrinking texts to a dynamic text.";

    char* sentence1 = "Just some words for a sentence (ÄÖÜäöüß@µ).";
    char* sentence2 = "Just some words (ÄÖÜäöüß@µ).";
    char* sentence3 = "Just (ÄÖÜäöüß@µ).";

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    checkIfUnusedMemoryIsSetUpAsZero(titleFromTest, &var1, __FILE__, __LINE__);
    
    assignDynamicText(&var1, sentence1, __FILE__, __LINE__);
    checkIfUnusedMemoryIsSetUpAsZero(titleFromTest, &var1, __FILE__, __LINE__);

    if (
        (customStrlen(sentence1) != customStrlen(getBytesPointerFromDynamicText(&var1)))
        && (0 != customStrncmp(getBytesPointerFromDynamicText(&var1), sentence1, customStrlen(sentence1)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }

    assignDynamicText(&var1, sentence2, __FILE__, __LINE__);
    checkIfUnusedMemoryIsSetUpAsZero(titleFromTest, &var1, __FILE__, __LINE__);

    if (
        (customStrlen(sentence2) != customStrlen(getBytesPointerFromDynamicText(&var1)))
        && (0 != customStrncmp(getBytesPointerFromDynamicText(&var1), sentence2, customStrlen(sentence2)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    assignDynamicText(&var1, sentence3, __FILE__, __LINE__);
    checkIfUnusedMemoryIsSetUpAsZero(titleFromTest, &var1, __FILE__, __LINE__);

    if (
        (customStrlen(sentence3) != customStrlen(getBytesPointerFromDynamicText(&var1)))
        && (0 != customStrncmp(getBytesPointerFromDynamicText(&var1), sentence3, customStrlen(sentence3)))
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
executeTest7(void)
{
    char* titleFromTest = "#07 Assign a large text to a dynamic text to force a realloc action.";

    char* sentence1 = "Sed ut (ÄÖÜäöüß@µ) unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo. Nemo enim ipsam voluptatem quia voluptas sit aspernatur aut odit aut fugit, sed quia consequuntur magni dolores eos qui ratione voluptatem sequi nesciunt. Neque porro quisquam est, qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit, sed quia non numquam eius modi tempora incidunt ut labore et dolore magnam aliquam quaerat voluptatem. Ut enim ad minima veniam, quis nostrum exercitationem ullam corporis suscipit laboriosam, nisi ut aliquid ex ea commodi consequatur? Quis autem vel eum iure reprehenderit qui in ea voluptate velit esse quam nihil molestiae consequatur, vel illum qui dolorem eum fugiat quo voluptas nulla pariatur?";
    int oldAmountOfReallocations = globaleAmountOfReallocations;

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    checkIfUnusedMemoryIsSetUpAsZero(titleFromTest, &var1, __FILE__, __LINE__);
    
    assignDynamicText(&var1, sentence1, __FILE__, __LINE__);
    checkIfUnusedMemoryIsSetUpAsZero(titleFromTest, &var1, __FILE__, __LINE__);

    if (
        (customStrlen(sentence1) != customStrlen(getBytesPointerFromDynamicText(&var1)))
        || (0 != customStrncmp(getBytesPointerFromDynamicText(&var1), sentence1, customStrlen(sentence1)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeDynamicText(&var1, __FILE__, __LINE__);
    
    if (
        (NULL == var1)
        && (globaleAmountOfAllocations == globaleAmountOfFrees)
        && (oldAmountOfReallocations < globaleAmountOfReallocations)
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
    char* titleFromTest = "#08 Assign some large texts to a dynamic text to force some realloc actions.";

    char* sentence1 = "Lorem ipsum (ÄÖÜäöüß@µ) sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    char* sentence2 = "Sed ut (ÄÖÜäöüß@µ) unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo. Nemo enim ipsam voluptatem quia voluptas sit aspernatur aut odit aut fugit, sed quia consequuntur magni dolores eos qui ratione voluptatem sequi nesciunt. Neque porro quisquam est, qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit, sed quia non numquam eius modi tempora incidunt ut labore et dolore magnam aliquam quaerat voluptatem. Ut enim ad minima veniam, quis nostrum exercitationem ullam corporis suscipit laboriosam, nisi ut aliquid ex ea commodi consequatur? Quis autem vel eum iure reprehenderit qui in ea voluptate velit esse quam nihil molestiae consequatur, vel illum qui dolorem eum fugiat quo voluptas nulla pariatur?";
    int oldAmountOfReallocations = globaleAmountOfReallocations;

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    checkIfUnusedMemoryIsSetUpAsZero(titleFromTest, &var1, __FILE__, __LINE__);

    assignDynamicText(&var1, sentence1, __FILE__, __LINE__);
    checkIfUnusedMemoryIsSetUpAsZero(titleFromTest, &var1, __FILE__, __LINE__);

    assignDynamicText(&var1, sentence2, __FILE__, __LINE__);
    checkIfUnusedMemoryIsSetUpAsZero(titleFromTest, &var1, __FILE__, __LINE__);

    if (
        (customStrlen(sentence2) != customStrlen(getBytesPointerFromDynamicText(&var1)))
        && (0 != customStrncmp(getBytesPointerFromDynamicText(&var1), sentence2, customStrlen(sentence2)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeDynamicText(&var1, __FILE__, __LINE__);
    
    if (
        (NULL == var1)
        && (globaleAmountOfAllocations == globaleAmountOfFrees)
        && ((oldAmountOfReallocations + 2) <= globaleAmountOfReallocations)
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
    char* titleFromTest = "#09 Append an empty text to a dynamic text.";

    char* sentence1 = "";
    
    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    checkIfUnusedMemoryIsSetUpAsZero(titleFromTest, &var1, __FILE__, __LINE__);

    appendDynamicText(&var1, sentence1, __FILE__, __LINE__);
    checkIfUnusedMemoryIsSetUpAsZero(titleFromTest, &var1, __FILE__, __LINE__);
    
    if (
        (customStrlen(sentence1) != customStrlen(getBytesPointerFromDynamicText(&var1)))
        && (0 != customStrncmp(getBytesPointerFromDynamicText(&var1), sentence1, customStrlen(sentence1)))
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
executeTest10(void)
{
    char* titleFromTest = "#10 Append an ordinary text to a dynamic text.";

    char* sentence1 = "Just some words for a sentence (ÄÖÜäöüß@µ).";
    
    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    checkIfUnusedMemoryIsSetUpAsZero(titleFromTest, &var1, __FILE__, __LINE__);
    
    appendDynamicText(&var1, sentence1, __FILE__, __LINE__);
    checkIfUnusedMemoryIsSetUpAsZero(titleFromTest, &var1, __FILE__, __LINE__);

    if (
        (customStrlen(sentence1) != customStrlen(getBytesPointerFromDynamicText(&var1)))
        && (0 != customStrncmp(getBytesPointerFromDynamicText(&var1), sentence1, customStrlen(sentence1)))
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
executeTest11(void)
{
    char* titleFromTest = "#11 Append multiple times texts to a dynamic text.";

    char* sentence1 = "A new text (ÄÖÜäöüß@µ).";
    char* sentence2 = " This is the time for a better text (ÄÖÜäöüß@µ)!";
    char* sentence3 = " Three texts in a text is a text (ÄÖÜäöüß@µ)!";
    
    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    checkIfUnusedMemoryIsSetUpAsZero(titleFromTest, &var1, __FILE__, __LINE__);
    
    appendDynamicText(&var1, sentence1, __FILE__, __LINE__);
    checkIfUnusedMemoryIsSetUpAsZero(titleFromTest, &var1, __FILE__, __LINE__);

    if (
        (customStrlen(sentence1) != customStrlen(getBytesPointerFromDynamicText(&var1)))
        && (0 != customStrncmp(getBytesPointerFromDynamicText(&var1), sentence1, customStrlen(sentence1)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    appendDynamicText(&var1, sentence2, __FILE__, __LINE__);
    checkIfUnusedMemoryIsSetUpAsZero(titleFromTest, &var1, __FILE__, __LINE__);

    if ((customStrlen(sentence1) + customStrlen(sentence2)) != customStrlen(getBytesPointerFromDynamicText(&var1)))
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }

    appendDynamicText(&var1, sentence3, __FILE__, __LINE__);
    checkIfUnusedMemoryIsSetUpAsZero(titleFromTest, &var1, __FILE__, __LINE__);

    if ((customStrlen(sentence1) + customStrlen(sentence2) + customStrlen(sentence3)) != customStrlen(getBytesPointerFromDynamicText(&var1)))
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
executeTest12(void)
{
    char* titleFromTest = "#12 Append some large texts to a dynamic text to force some realloc actions.";

    char* sentence1 = "Lorem ipsum (ÄÖÜäöüß@µ) sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    char* sentence2 = "Sed ut (ÄÖÜäöüß@µ) unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo. Nemo enim ipsam voluptatem quia voluptas sit aspernatur aut odit aut fugit, sed quia consequuntur magni dolores eos qui ratione voluptatem sequi nesciunt. Neque porro quisquam est, qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit, sed quia non numquam eius modi tempora incidunt ut labore et dolore magnam aliquam quaerat voluptatem. Ut enim ad minima veniam, quis nostrum exercitationem ullam corporis suscipit laboriosam, nisi ut aliquid ex ea commodi consequatur? Quis autem vel eum iure reprehenderit qui in ea voluptate velit esse quam nihil molestiae consequatur, vel illum qui dolorem eum fugiat quo voluptas nulla pariatur?";

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    checkIfUnusedMemoryIsSetUpAsZero(titleFromTest, &var1, __FILE__, __LINE__);
    
    appendDynamicText(&var1, sentence1, __FILE__, __LINE__);
    checkIfUnusedMemoryIsSetUpAsZero(titleFromTest, &var1, __FILE__, __LINE__);

    if (customStrlen(sentence1) != customStrlen(getBytesPointerFromDynamicText(&var1)))
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    appendDynamicText(&var1, sentence2, __FILE__, __LINE__);
    checkIfUnusedMemoryIsSetUpAsZero(titleFromTest, &var1, __FILE__, __LINE__);

    if (customStrlen(sentence1) + customStrlen(sentence2) != customStrlen(getBytesPointerFromDynamicText(&var1)))
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeDynamicText(&var1, __FILE__, __LINE__);
    
    if (
        (NULL == var1)
        && (globaleAmountOfAllocations == globaleAmountOfFrees)
        && (globaleAmountOfReallocations > 0)
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
    char* titleFromTest = "#13 Resize a dynamic text two times and fill all bytes with letters each time.";

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    checkIfUnusedMemoryIsSetUpAsZero(titleFromTest, &var1, __FILE__, __LINE__);
    
    for (int i = 0; i < (*var1).amountOfBytes; i++)
    {
        (*var1).bytes[i] = 'a';
    }
    (*var1).bytes[(*var1).amountOfBytes - 1] = '\0';

    checkIfUnusedMemoryIsSetUpAsZero(titleFromTest, &var1, __FILE__, __LINE__);
    
    if (
        (getMinimumAmountOfBytesForAllocation(__FILE__, __LINE__) != (*var1).amountOfBytes)
        || ((getMinimumAmountOfBytesForAllocation(__FILE__, __LINE__) - 1) != customStrlen(getBytesPointerFromDynamicText(&var1)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }

    int newSize = 200;
    resizeDynamicText(&var1, newSize, __FILE__, __LINE__);
    checkIfUnusedMemoryIsSetUpAsZero(titleFromTest, &var1, __FILE__, __LINE__);
    
    for (int i = 0; i < (*var1).amountOfBytes; i++)
    {
        (*var1).bytes[i] = 'a';
    }
    (*var1).bytes[(*var1).amountOfBytes - 1] = '\0';
    
    checkIfUnusedMemoryIsSetUpAsZero(titleFromTest, &var1, __FILE__, __LINE__);
    
    if (
        (newSize != (*var1).amountOfBytes)
        || ((newSize - 1) != customStrlen(getBytesPointerFromDynamicText(&var1)))
    )
    {
        printf("[FAILED] %s\n", titleFromTest);
        printf("ABORTED in function \"%s\" in file: \"%s\" on line: %d!\n", __func__, __FILE__, __LINE__);
        
        customExit(EXIT_FAILURE);
    }
    
    newSize = 300;
    resizeDynamicText(&var1, newSize, __FILE__, __LINE__);
    checkIfUnusedMemoryIsSetUpAsZero(titleFromTest, &var1, __FILE__, __LINE__);

    for (int i = 0; i < (*var1).amountOfBytes; i++)
    {
        (*var1).bytes[i] = 'a';
    }
    (*var1).bytes[(*var1).amountOfBytes - 1] = '\0';
    checkIfUnusedMemoryIsSetUpAsZero(titleFromTest, &var1, __FILE__, __LINE__);

    if (
        (newSize != (*var1).amountOfBytes)
        || ((newSize - 1) != customStrlen(getBytesPointerFromDynamicText(&var1)))
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }
    
    freeDynamicText(&var1, __FILE__, __LINE__);
    
    if (
        (NULL == var1)
        && (globaleAmountOfAllocations == globaleAmountOfFrees)
        && (globaleAmountOfReallocations > 0)
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
    printf("TEST SUITE: dynamic_text.c file\n");

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

    return EXIT_SUCCESS;
}
