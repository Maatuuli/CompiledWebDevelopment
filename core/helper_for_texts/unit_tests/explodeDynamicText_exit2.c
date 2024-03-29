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
    printf("[SUCCESS] #02 Explode text from a NULL pointer parameter is not allowed!\n");
    
    int errorNumber = 0;
    struct DynamicText* var1 = allocateDynamicText(&errorNumber, __FILE__, __LINE__);
    (*var1).set(&var1, "This is a sentence.", &errorNumber, __FILE__, __LINE__);

    explodeDynamicText(&var1, "", NULL, __FILE__, __LINE__);

    return EXIT_SUCCESS;
}
