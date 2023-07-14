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
#include <sys/stat.h>

#include "../../wrapperStdLib/wrappedStandardLibrary.c"
#include "../../wrapperStdLib/wrappedFunctionForAllocation.c"
#include "../../wrapperStdLib/wrappedFunctionForReallocation.c"
#include "../../DynamicText/DynamicText.class.c"
#include "../../DynamicTextList/DynamicTextList.class.c"
#include "../../helper_for_texts/helper_for_texts.c"
#include "../../AssociativeDynamicText/AssociativeDynamicText.class.c"
#include "../../AssociativeDynamicTextList/AssociativeDynamicTextList.class.c"
#include "../../helper_for_cgi/helper_for_cgi.c"
#include "../oksa.c"


int
main(void)
{
    printf("\n");
    printf("TEST SUITE: Oksa functions => Not allowed test cases ending with exit() \n");

    printf("[SUCCESS] #01 ???\n");

    renderOksaFile("../../apps/frontend/does_not_exist.twig.html", NULL, NULL, __FILE__, __LINE__);

    return EXIT_SUCCESS;
}
