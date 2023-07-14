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

#include "../../wrapperStdLib/wrappedStandardLibrary.c"
#include "../../wrapperStdLib/wrappedFunctionForAllocation.c"
#include "../../wrapperStdLib/wrappedFunctionForReallocation.c"
#include "../../DynamicText/DynamicText.class.c"
#include "../../DynamicTextList/DynamicTextList.class.c"
#include "../helper_for_texts.c"


int
main(void)
{
    printf("[SUCCESS] #03 Start index is smaller than 0 which is not allowed!\n");

    int errorNumber = 0;
    struct DynamicText* var1 = allocateDynamicText(&errorNumber, __FILE__, __LINE__);
    struct DynamicText* var2 = allocateDynamicText(&errorNumber, __FILE__, __LINE__);

    getSubstringInBytesFromDynamicText(&var1, -1, 5, &var2, __FILE__, __LINE__);

    return EXIT_SUCCESS;
}
