/*
The MIT License (MIT)
Copyright (c) 2022 Thomas Krüger
See full details in LICENSE.txt file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <time.h>

#include "../../wrapperStdLib/wrappedStandardLibrary.c"
#include "../../wrapperStdLib/wrappedFunctionForAllocation.c"
#include "../../wrapperStdLib/wrappedFunctionForReallocation.c"
#include "../../DynamicText/DynamicText.class.c"
#include "../../DynamicTextList/DynamicTextList.class.c"
#include "../helper_for_texts.c"


int
main(void)
{
    printf("[SUCCESS] #04 Replacing with NULL for search which is not allowed!\n");

    int errorNumber = 0;
    struct DynamicText* var1 = allocateDynamicText(&errorNumber, __FILE__, __LINE__);
    (*var1).set(&var1, "abcdef", &errorNumber, __FILE__, __LINE__);

    replaceDynamicText(&var1, NULL, "b", __FILE__, __LINE__);

    return EXIT_SUCCESS;
}
