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


static void
executeTest1(void)
{
    char* titleFromTest = "#01 Assign an empty text to a NULL parameter which is not allowed!";
    printf("[SUCCESS] %s\n", titleFromTest);

    assignDynamicText(NULL, "", __FILE__, __LINE__);
}


int
main(void)
{
    printf("\n");
    printf("TEST SUITE: dynamic_text.c file => Not allowed test cases ending with exit() \n");

    executeTest1();

    return EXIT_SUCCESS;
}
