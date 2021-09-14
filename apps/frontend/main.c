/*
The MIT License (MIT)

Copyright (c) 2021 Thomas Krüger

See full details in LICENSE.txt file.
*/

/*
 * Compile with address sanitizer:
 * gcc -std=c11 -O3 -s -Wall -Wstrict-prototypes -Wshadow -Wconversion -Wextra -Wno-unused-parameter -Wno-overlength-strings -Wpedantic -Winline -fsanitize=address -fsanitize=undefined -fsanitize=leak -fsanitize-address-use-after-scope main.c --output index.cgi `mariadb_config --cflags --libs`
 * gcc -std=c11 -O3 -s -Wall -Wstrict-prototypes -Wshadow -Wextra -Wno-unused-parameter -Wno-overlength-strings -Wpedantic -Winline -fsanitize=address -fsanitize=undefined -fsanitize=leak -fsanitize-address-use-after-scope main.c --output index.cgi `mariadb_config --cflags --libs`
 *
 */

/* This define for _xopen_source is needed for compiling/linking the clockid_t datatype. */
#define _XOPEN_SOURCE 600

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <mysql.h>

#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>


#include "../../core/wrappedStandardLibrary.c"
#include "../../core/wrappedFunctionForAllocation.c"
#include "../../core/wrappedFunctionForReallocation.c"
#include "../../core/dynamic_text.c"
#include "../../core/dynamic_text_list.c"
#include "../../core/helper_for_texts.c"
#include "../../core/associative_dynamic_text.c"
#include "../../core/associative_dynamic_text_list.c"
#include "../../core/helper_for_cgi.c"

#include "helper_for_database.c"
#include "helper_for_subpages.c"
#include "start_application.c"


int
main(void)
{
    struct timespec clockStart;

    // @TODO: Custom-Funktion fehlt!
    if (-1 == clock_gettime(CLOCK_REALTIME, &clockStart))
    {
        perror("clock_gettime // start");
        exit(EXIT_FAILURE);
    }

    char* currentRequestMethod = customGetenv("REQUEST_METHOD");
    char* currentCookie = customGetenv("HTTP_COOKIE");
    char* textForQueryString = customGetenv("QUERY_STRING");
    
    // char *textForQueryString = "routing=/products-by-mysql";
    // char *textForQueryString = "routing=/products";
    // char *textForQueryString = "routing=/search";
    // char *textForQueryString = "routing=/products/fq372g592dd2";
    // char *textForQueryString = "routing=/products&fb%C3%A4uid=4356554%C3%A4";
    // char *textForQueryString = "routing=/products&";

    // char *textForQueryString = "routing=/search";
    // char* currentRequestMethod = "POST";

    startApplication(clockStart, currentRequestMethod, currentCookie, textForQueryString);

    return EXIT_SUCCESS;
}
