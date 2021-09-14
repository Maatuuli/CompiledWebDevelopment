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


static void
executeTest1(void)
{
    char* titleFromTest = "#13 Get element by key from NULL parameter for list is not allowed!";
    printf("[SUCCESS] %s\n", titleFromTest);
    
    getElementByKeyFromListForAssociativeDynamicText(NULL, "name1", __FILE__, __LINE__);
}


int
main(void)
{
    executeTest1();

    return EXIT_SUCCESS;
}
