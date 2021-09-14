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
    char* titleFromTest = "#09 Get a list element from a NULL parameter which is not allowed!";
    printf("[SUCCESS] %s\n", titleFromTest);
    
    getElementByIndexFromListForDynamicText(NULL, 0, __FILE__, __LINE__);
}


int
main(void)
{
    executeTest1();

    return EXIT_SUCCESS;
}
