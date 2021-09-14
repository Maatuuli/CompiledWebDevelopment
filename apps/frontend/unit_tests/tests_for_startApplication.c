/*
The MIT License (MIT)

Copyright (c) 2021 Thomas Krüger

See full details in LICENSE.txt file.
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


#include "../../../core/wrappedStandardLibrary.c"
#include "../../../core/wrappedFunctionForAllocation.c"
#include "../../../core/wrappedFunctionForReallocation.c"
#include "../../../core/dynamic_text.c"
#include "../../../core/dynamic_text_list.c"
#include "../../../core/helper_for_texts.c"
#include "../../../core/associative_dynamic_text.c"
#include "../../../core/associative_dynamic_text_list.c"
#include "../../../core/helper_for_cgi.c"

#include "../helper_for_database.c"
#include "../helper_for_subpages.c"
#include "../start_application.c"


static void
executeTest1(void)
{
    struct timespec clockStart;

    // @TODO: Custom-Funktion fehlt!
    if (-1 == clock_gettime(CLOCK_REALTIME, &clockStart))
    {
        perror("clock_gettime // start");
        exit(EXIT_FAILURE);
    }

    char* currentRequestMethod = NULL;
    char* currentCookie = NULL;
    char* textForQueryString = NULL;
    
    startApplication(clockStart, currentRequestMethod, currentCookie, textForQueryString);

    char* titleFromTest = "#01 ???.";
    printf("[SUCCESS] %s\n", titleFromTest);
}


static void
executeTest2(void)
{
    struct timespec clockStart;

    // @TODO: Custom-Funktion fehlt!
    if (-1 == clock_gettime(CLOCK_REALTIME, &clockStart))
    {
        perror("clock_gettime // start");
        exit(EXIT_FAILURE);
    }

    char* currentRequestMethod = NULL;
    char* currentCookie = NULL;
    char* textForQueryString = "routing=/products";
    
    startApplication(clockStart, currentRequestMethod, currentCookie, textForQueryString);

    char* titleFromTest = "#02 ???.";
    printf("[SUCCESS] %s\n", titleFromTest);
}


static void
executeTest3(void)
{
    struct timespec clockStart;

    // @TODO: Custom-Funktion fehlt!
    if (-1 == clock_gettime(CLOCK_REALTIME, &clockStart))
    {
        perror("clock_gettime // start");
        exit(EXIT_FAILURE);
    }

    char* currentRequestMethod = NULL;
    char* currentCookie = NULL;
    char *textForQueryString = "routing=/products-by-mysql";
   
    startApplication(clockStart, currentRequestMethod, currentCookie, textForQueryString);

    char* titleFromTest = "#03 ???.";
    printf("[SUCCESS] %s\n", titleFromTest);
}


static void
executeTest4(void)
{
    struct timespec clockStart;

    // @TODO: Custom-Funktion fehlt!
    if (-1 == clock_gettime(CLOCK_REALTIME, &clockStart))
    {
        perror("clock_gettime // start");
        exit(EXIT_FAILURE);
    }

    char* currentRequestMethod = NULL;
    char* currentCookie = NULL;
    char *textForQueryString = "routing=/products/fq372g592dd2";
   
    startApplication(clockStart, currentRequestMethod, currentCookie, textForQueryString);

    char* titleFromTest = "#04 ???.";
    printf("[SUCCESS] %s\n", titleFromTest);
}


static void
executeTest5(void)
{
    struct timespec clockStart;

    // @TODO: Custom-Funktion fehlt!
    if (-1 == clock_gettime(CLOCK_REALTIME, &clockStart))
    {
        perror("clock_gettime // start");
        exit(EXIT_FAILURE);
    }

    char* currentRequestMethod = NULL;
    char* currentCookie = NULL;
    char *textForQueryString = "routing=/quotes";
   
    startApplication(clockStart, currentRequestMethod, currentCookie, textForQueryString);

    char* titleFromTest = "#05 ???.";
    printf("[SUCCESS] %s\n", titleFromTest);
}


static void
executeTest6(void)
{
    struct timespec clockStart;

    // @TODO: Custom-Funktion fehlt!
    if (-1 == clock_gettime(CLOCK_REALTIME, &clockStart))
    {
        perror("clock_gettime // start");
        exit(EXIT_FAILURE);
    }

    char* currentRequestMethod = NULL;
    char* currentCookie = NULL;
    char *textForQueryString = "routing=/project-statistics";
   
    startApplication(clockStart, currentRequestMethod, currentCookie, textForQueryString);

    char* titleFromTest = "#06 ???.";
    printf("[SUCCESS] %s\n", titleFromTest);
}


static void
executeTest7(void)
{
    struct timespec clockStart;

    // @TODO: Custom-Funktion fehlt!
    if (-1 == clock_gettime(CLOCK_REALTIME, &clockStart))
    {
        perror("clock_gettime // start");
        exit(EXIT_FAILURE);
    }

    char* currentRequestMethod = NULL;
    char* currentCookie = NULL;
    char *textForQueryString = "routing=/impressum";
   
    startApplication(clockStart, currentRequestMethod, currentCookie, textForQueryString);

    char* titleFromTest = "#07 ???.";
    printf("[SUCCESS] %s\n", titleFromTest);
}


static void
executeTest8(void)
{
    struct timespec clockStart;

    // @TODO: Custom-Funktion fehlt!
    if (-1 == clock_gettime(CLOCK_REALTIME, &clockStart))
    {
        perror("clock_gettime // start");
        exit(EXIT_FAILURE);
    }

    char* currentRequestMethod = NULL;
    char* currentCookie = NULL;
    char *textForQueryString = "routing=/search";
   
    startApplication(clockStart, currentRequestMethod, currentCookie, textForQueryString);

    char* titleFromTest = "#08 ???.";
    printf("[SUCCESS] %s\n", titleFromTest);
}


static void
executeTest9(void)
{
    struct timespec clockStart;

    // @TODO: Custom-Funktion fehlt!
    if (-1 == clock_gettime(CLOCK_REALTIME, &clockStart))
    {
        perror("clock_gettime // start");
        exit(EXIT_FAILURE);
    }

    char* currentRequestMethod = NULL;
    char* currentCookie = NULL;
    char *textForQueryString = "routing=/1234567890";
   
    startApplication(clockStart, currentRequestMethod, currentCookie, textForQueryString);

    char* titleFromTest = "#09 ???.";
    printf("[SUCCESS] %s\n", titleFromTest);
}


static void
executeTest10(void)
{
    struct timespec clockStart;

    // @TODO: Custom-Funktion fehlt!
    if (-1 == clock_gettime(CLOCK_REALTIME, &clockStart))
    {
        perror("clock_gettime // start");
        exit(EXIT_FAILURE);
    }

    char* currentRequestMethod = NULL;
    char* currentCookie = NULL;
    char *textForQueryString = "routing=/products/this_product_id_does_not_exists";
   
    startApplication(clockStart, currentRequestMethod, currentCookie, textForQueryString);

    char* titleFromTest = "#10 ???.";
    printf("[SUCCESS] %s\n", titleFromTest);
}


static void
executeTest11(void)
{
    struct timespec clockStart;

    // @TODO: Custom-Funktion fehlt!
    if (-1 == clock_gettime(CLOCK_REALTIME, &clockStart))
    {
        perror("clock_gettime // start");
        exit(EXIT_FAILURE);
    }

    char* currentRequestMethod = NULL;
    char* currentCookie = NULL;
    char *textForQueryString = "routing=/delete-cookie";
   
    startApplication(clockStart, currentRequestMethod, currentCookie, textForQueryString);

    char* titleFromTest = "#11 ???.";
    printf("[SUCCESS] %s\n", titleFromTest);
}


static void
executeTest12(void)
{
    struct timespec clockStart;

    // @TODO: Custom-Funktion fehlt!
    if (-1 == clock_gettime(CLOCK_REALTIME, &clockStart))
    {
        perror("clock_gettime // start");
        exit(EXIT_FAILURE);
    }

    char* currentRequestMethod = NULL;
    char* currentCookie = NULL;
    char *textForQueryString = "routing=/accept-cookie";
   
    startApplication(clockStart, currentRequestMethod, currentCookie, textForQueryString);

    char* titleFromTest = "#12 ???.";
    printf("[SUCCESS] %s\n", titleFromTest);
}



static void
executeTest13(void)
{
    struct timespec clockStart;

    // @TODO: Custom-Funktion fehlt!
    if (-1 == clock_gettime(CLOCK_REALTIME, &clockStart))
    {
        perror("clock_gettime // start");
        exit(EXIT_FAILURE);
    }

    char* currentRequestMethod = NULL;
    char currentCookie[256] = "hits=2";
    char* textForQueryString = NULL;
    
    startApplication(clockStart, currentRequestMethod, currentCookie, textForQueryString);

    char* titleFromTest = "#13 ???.";
    printf("[SUCCESS] %s\n", titleFromTest);
}


static void
executeTest20(void)
{
    struct timespec clockStart;

    // @TODO: Custom-Funktion fehlt!
    if (-1 == clock_gettime(CLOCK_REALTIME, &clockStart))
    {
        perror("clock_gettime // start");
        exit(EXIT_FAILURE);
    }

    char* currentRequestMethod = NULL;
    char* currentCookie = NULL;
    char *textForQueryString = "routing=/old_products";
   
    startApplication(clockStart, currentRequestMethod, currentCookie, textForQueryString);

    char* titleFromTest = "#20 ???.";
    printf("[SUCCESS] %s\n", titleFromTest);
}


int
main(void)
{
    printf("\n");
    printf("TEST SUITE: startApplication function\n");

    executeTest1();
    executeTest2();
    executeTest3();
    executeTest4();
    executeTest5();
    executeTest6();
    executeTest7();
    executeTest8();
    executeTest9();
    executeTest10();
    executeTest11();
    executeTest12();
    executeTest13();
    
    executeTest20();

    return EXIT_SUCCESS;
}
