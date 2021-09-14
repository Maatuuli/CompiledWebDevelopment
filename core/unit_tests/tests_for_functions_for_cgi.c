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
#include "../helper_for_cgi.c"
#include "helper_for_tests.c"


static void
executeTest1(void)
{
    char* titleFromTest = "#01 ???.";

    int var1 = getNumericValueFromHexadecialLetter('A', __FILE__, __LINE__);

    if (
        (var1 < 0)
        || (var1 > 15)
    )
    {
        abortTestWithErrorMessage(titleFromTest, __func__, __FILE__, __LINE__);
    }

    if (
        (var1 >= 0)
        && (var1 <= 15)
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
    printf("TEST SUITE: getNumericValueFromhexadecialLetter function\n");

    executeTest1();
 
    return EXIT_SUCCESS;
}
