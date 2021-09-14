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
    char* titleFromTest = "#03 Assign a NULL parameter as text to a dynamicText which is not allowed!";
    printf("[SUCCESS] %s\n", titleFromTest);

    struct dynamicText* var1 = allocateDynamicText(__FILE__, __LINE__);
    assignDynamicText(&var1, NULL, __FILE__, __LINE__);
}


int
main(void)
{
    executeTest1();

    return EXIT_SUCCESS;
}
