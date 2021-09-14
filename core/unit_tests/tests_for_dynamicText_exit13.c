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


static void
executeTest1(void)
{
    char* titleFromTest = "#13 Allocate a dynamicText with a mocked allocation function which always return NULL!";
    printf("[SUCCESS] %s\n", titleFromTest);

    /* Change mocking function for allocation to NULL. */
    globaleTestingFlagForNullAllocation = 1;
    
    allocateDynamicText(__FILE__, __LINE__);
}


int
main(void)
{
    executeTest1();

    return EXIT_SUCCESS;
}
