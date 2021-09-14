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
#include "mocks/wrappedFunctionForAllocation.c"
#include "../wrappedFunctionForReallocation.c"
#include "../dynamic_text.c"
#include "../dynamic_text_list.c"


static void
executeTest1(void)
{
    char* titleFromTest = "#06 Push two texts and the last one with a mocked allocation function which always return NULL!";
    printf("[SUCCESS] %s\n", titleFromTest);
    
    struct listForDynamicText* list1 = newListForDynamicText(__FILE__, __LINE__);
    
    pushElementInListForDynamicText(&list1, "Just some words for a sentence (ÄÖÜäöüß@µ).", __FILE__, __LINE__);
    
    /* Change mocking function for allocation to NULL. */
    globaleTestingFlagForNullAllocation = 1;

    pushElementInListForDynamicText(&list1, "Another sentence (ÄÖÜäöüß@µ).", __FILE__, __LINE__);
}


int
main(void)
{
    executeTest1();

    return EXIT_SUCCESS;
}
