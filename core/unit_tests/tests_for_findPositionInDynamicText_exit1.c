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


static void
executeTest1(void)
{
    char* titleFromTest = "#01 Find a position in a NULL parameter is not allowed!";
    printf("[SUCCESS] %s\n", titleFromTest);

    findPositionInDynamicText(NULL, "is", 0, __FILE__, __LINE__);
}


int
main(void)
{
    printf("\n");
    printf("TEST SUITE: findPositionInDynamicText function => Not allowed test cases ending with exit() \n");

    executeTest1();

    return EXIT_SUCCESS;
}
