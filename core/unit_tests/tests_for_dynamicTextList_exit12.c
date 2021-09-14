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
    char* titleFromTest = "#12 Get a list element with a index higher than max element count which is not allowed!";
    printf("[SUCCESS] %s\n", titleFromTest);
    
    struct listForDynamicText* list1 = newListForDynamicText(__FILE__, __LINE__);
    
    pushElementInListForDynamicText(&list1, "This is a text (ÄÖÜäöüß@µ).", __FILE__, __LINE__);
    pushElementInListForDynamicText(&list1, "Another text (ÄÖÜäöüß@µ).", __FILE__, __LINE__);
    pushElementInListForDynamicText(&list1, "Additional text (ÄÖÜäöüß@µ).", __FILE__, __LINE__);
    
    getElementByIndexFromListForDynamicText(&list1, 999, __FILE__, __LINE__);
}


int
main(void)
{
    executeTest1();

    return EXIT_SUCCESS;
}
