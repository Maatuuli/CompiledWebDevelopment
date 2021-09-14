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
#include "../helper_for_texts.c"
#include "../associative_dynamic_text.c"
#include "../associative_dynamic_text_list.c"


static void
executeTest1(void)
{
    char* titleFromTest = "#10 Add an element in a not empty list with a mocked allocation function which always return NULL!";
    printf("[SUCCESS] %s\n", titleFromTest);
    
    struct listForAssociativeDynamicText* list1 = newListForAssociativeDynamicText(__FILE__, __LINE__);
    addElementByKeyInListForAssociativeDynamicText(&list1, "name1", "value1", __FILE__, __LINE__);
    
    /* Change mocking function for allocation to NULL. */
    globaleTestingFlagForNullAllocation = 1;
    
    addElementByKeyInListForAssociativeDynamicText(&list1, "name2", "value2", __FILE__, __LINE__);
}


int
main(void)
{
    executeTest1();

    return EXIT_SUCCESS;
}
