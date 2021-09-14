
void
startApplication(struct timespec clockStart, char* currentRequestMethod, char* currentCookie, char* textForQueryString)
{
    char baseHref[] = "https://maatuu.li/minimal/";
    
    /* Init "get" data from server. */
    struct listForAssociativeDynamicText* listForGetParameters = newListForAssociativeDynamicText(__FILE__, __LINE__);
    initRequestParametersByEnvironmentText(&listForGetParameters, textForQueryString, __FILE__, __LINE__);
    
    struct associativeDynamicText* parameterForRouting = NULL;
    struct dynamicText* textForRouting = NULL;
    char* currentUriText = NULL;
    
    if (1 == checkIfKeyExistsInListForAssociativeDynamicText(&listForGetParameters, "routing", __FILE__, __LINE__))
    {
        parameterForRouting = getElementByKeyFromListForAssociativeDynamicText(&listForGetParameters, "routing", __FILE__, __LINE__);
        textForRouting = (*parameterForRouting).internalValue;
        currentUriText = getBytesPointerFromDynamicText(&textForRouting);
    }

    struct dynamicText* contentForMain = allocateDynamicText(__FILE__, __LINE__);   

    char* standardTextForActiveCss = "class=\"active\" ";

    struct dynamicText* cssTextForNode1 = allocateDynamicText(__FILE__, __LINE__);   
    struct dynamicText* cssTextForNode4 = allocateDynamicText(__FILE__, __LINE__);   
    struct dynamicText* cssTextForNode5 = allocateDynamicText(__FILE__, __LINE__);   
    struct dynamicText* cssTextForNode6 = allocateDynamicText(__FILE__, __LINE__);   
    struct dynamicText* cssTextForNode7 = allocateDynamicText(__FILE__, __LINE__);   
    struct dynamicText* cssTextForNodeQuote = allocateDynamicText(__FILE__, __LINE__);   

    printf("Content-Type: text/html; charset=utf-8\n");
    printf("x-powered-by: C / CGI\n");

    /* Init post data from server. */
    struct listForAssociativeDynamicText* listForPostParameters = newListForAssociativeDynamicText(__FILE__, __LINE__);
    struct dynamicText* postDataFromStandardInput = getPostDataFromStandardInput(currentRequestMethod, __FILE__, __LINE__);
    initRequestParametersByEnvironmentText(&listForPostParameters, getBytesPointerFromDynamicText(&postDataFromStandardInput), __FILE__, __LINE__);
    freeDynamicText(&postDataFromStandardInput, __FILE__, __LINE__);

    if (NULL != currentCookie)
    {
        struct dynamicText* item = allocateDynamicText(__FILE__, __LINE__);
        assignDynamicText(&item, currentCookie, __FILE__, __LINE__);

        struct listForDynamicText* listForCookieValues = newListForDynamicText(__FILE__, __LINE__);
        explodeDynamicText(&item, "=", &listForCookieValues, __FILE__, __LINE__);
        struct dynamicText* textForAmountOfHitsFromCookie = getElementByIndexFromListForDynamicText(&listForCookieValues, 1, __FILE__, __LINE__);
        int amountOfHitsFromCookie = convertTextIntoInteger(getBytesPointerFromDynamicText(&textForAmountOfHitsFromCookie), __FILE__, __LINE__);
        freeListForDynamicText(&listForCookieValues, __FILE__, __LINE__);
        freeDynamicText(&item, __FILE__, __LINE__);
        
        amountOfHitsFromCookie++;
        
        // @TODO: Custom-Funktion fehlt!
        sprintf(currentCookie, "hits=%d", amountOfHitsFromCookie);
        printf("Set-Cookie: hits=%d; expires=Fri, 01-Apr-2022 10:00:00 GMT; path=/; domain=.maatuu.li; secure\n", amountOfHitsFromCookie);
    }

    int noUrlMatchedForRouting = 1;

    if (NULL == textForRouting)
    {
        appendHtmlForStartPage(&contentForMain, &noUrlMatchedForRouting, __FILE__, __LINE__);
        assignDynamicText(&cssTextForNode1, standardTextForActiveCss, __FILE__, __LINE__);
    }
    else if (startsWith(getBytesPointerFromDynamicText(&textForRouting), "/products/", __FILE__, __LINE__))
    {
        appendHtmlForProductDetailPage(&contentForMain, &noUrlMatchedForRouting, currentUriText, __FILE__, __LINE__);
        assignDynamicText(&cssTextForNode4, standardTextForActiveCss, __FILE__, __LINE__);
    }
    else if (isExactTextMatch(getBytesPointerFromDynamicText(&textForRouting), "/products", __FILE__, __LINE__))
    {
        appendHtmlForProductOverviewWithDataArray(&contentForMain, &noUrlMatchedForRouting, __FILE__, __LINE__);
        assignDynamicText(&cssTextForNode4, standardTextForActiveCss, __FILE__, __LINE__);
    }
    else if (isExactTextMatch(getBytesPointerFromDynamicText(&textForRouting), "/products-by-mysql", __FILE__, __LINE__))
    {
        appendHtmlForProductOverviewWithMySql(&contentForMain, &noUrlMatchedForRouting, __FILE__, __LINE__);
        assignDynamicText(&cssTextForNode5, standardTextForActiveCss, __FILE__, __LINE__);
    }
    else if (isExactTextMatch(getBytesPointerFromDynamicText(&textForRouting), "/quotes", __FILE__, __LINE__))
    {
        appendHtmlForQuoteOverviewWithDataArray(&contentForMain, &noUrlMatchedForRouting, __FILE__, __LINE__);
        assignDynamicText(&cssTextForNodeQuote, standardTextForActiveCss, __FILE__, __LINE__);
    }
    else if (isExactTextMatch(getBytesPointerFromDynamicText(&textForRouting), "/project-statistics", __FILE__, __LINE__))
    {
        appendHtmlForProjectStatistics(&contentForMain, &noUrlMatchedForRouting, __FILE__, __LINE__);
        assignDynamicText(&cssTextForNode6, standardTextForActiveCss, __FILE__, __LINE__);
    }
    else if (isExactTextMatch(getBytesPointerFromDynamicText(&textForRouting), "/impressum", __FILE__, __LINE__))
    {
        appendHtmlForImpressum(&contentForMain, &noUrlMatchedForRouting, __FILE__, __LINE__);
        assignDynamicText(&cssTextForNode7, standardTextForActiveCss, __FILE__, __LINE__);
    }
    else if (isExactTextMatch(getBytesPointerFromDynamicText(&textForRouting), "/search", __FILE__, __LINE__))
    {
        appendHtmlForSearch(&contentForMain, &noUrlMatchedForRouting, currentRequestMethod, &listForPostParameters, __FILE__, __LINE__);
    }
    else if (isExactTextMatch(getBytesPointerFromDynamicText(&textForRouting), "/old_products", __FILE__, __LINE__))
    {
        executeActionsFor301RedirectSubpage(baseHref, __FILE__, __LINE__);
    }
    else if (isExactTextMatch(getBytesPointerFromDynamicText(&textForRouting), "/delete-cookie", __FILE__, __LINE__))
    {
        appendHtmlForDeleteCookie(&contentForMain, &noUrlMatchedForRouting, __FILE__, __LINE__);
    }
    else if (isExactTextMatch(getBytesPointerFromDynamicText(&textForRouting), "/accept-cookie", __FILE__, __LINE__))
    {
        appendHtmlForAcceptCookie(&contentForMain, &noUrlMatchedForRouting, __FILE__, __LINE__);
    }
    else
    {
        noUrlMatchedForRouting = 0;
        appendHtmlFor404ErrorPage(&contentForMain, __FILE__, __LINE__);
    }

    if (noUrlMatchedForRouting)
    {
        appendHtmlFor404ErrorPage(&contentForMain, __FILE__, __LINE__);
    }

    fputs("\n" \
    "<!DOCTYPE html>\n" \
    "<html lang=\"en\">\n" \
    "<head>\n" \
    "    <meta charset=\"UTF-8\" />\n" \
    "    <meta name=\"description\" content=\"Example of a dynamic CGI website programmed in the C programming language.\" />\n" \
    "    <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\" />\n" \
    "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n" \
    "    \n" \
    "    <title>Dynamic CGI website programmed in the C programming language</title>\n" \
    "    \n" \
    "    <!-- Touch Icons - iOS and Android 2.1+ 180x180 pixels in size. -->\n" \
    "    <link rel=\"apple-touch-icon-precomposed\" href=\"images/favicon_180x180.png\">\n" \
    "    \n" \
    "    <!-- Firefox, Chrome, Safari, IE 11+ and Opera. 196x196 pixels in size. -->\n" \
    "    <link rel=\"icon\" href=\"images/favicon_192x192.png\">\n" \
    "    \n" \
    "    <style>\n" \
    "    a { color: black; }\n" \
    "    body { background-color: #FFF8DC; font-family: Arial, Helvetica, sans-serif; }\n" \
    "    header { font-size: 34px; }\n" \
    "    nav { background-color: #F5DEB3; }\n" \
    "    nav a { margin-right: 30px; }\n" \
    "    nav a.active { font-weight: bold; }\n" \
    "    main { min-height: 300px; }\n" \
    "    .bold { font-weight: bold; }\n" \
    "    header, nav, main, footer { padding: 10px; }\n" \
    "    footer { background-color: #F5DEB3; }\n" \
    "    ul.list_settings li { margin-top: 10px; margin-bottom: 10px; }\n" \
    "    </style>\n" \
    "</head>\n" \
    "<body>\n" \
    "\n" \
    "<!-- header -->\n" \
    "<header>Dynamic CGI website programmed in the C programming language</header>\n" \
    "\n", stdout);

    printf("<!-- navigation -->\n");
    printf("<nav style=\"line-height: 2.5em;\">\n");
    printf("    <a %shref=\"%s\">Home</a>\n", getBytesPointerFromDynamicText(&cssTextForNode1), baseHref);
    printf("    <a %shref=\"?routing=/products\">Products (data array)</a>\n", getBytesPointerFromDynamicText(&cssTextForNode4));
    printf("    <a %shref=\"?routing=/products-by-mysql\">Products (MySQL)</a>\n", getBytesPointerFromDynamicText(&cssTextForNode5));
    printf("    <a %shref=\"?routing=/quotes\">Quotes (data array)</a>\n", getBytesPointerFromDynamicText(&cssTextForNodeQuote));
    printf("    <a %shref=\"?routing=/project-statistics\">Project Statistics</a>\n", getBytesPointerFromDynamicText(&cssTextForNode6));
    printf("    <a %shref=\"?routing=/impressum\">Impressum</a>\n", getBytesPointerFromDynamicText(&cssTextForNode7));
    printf("    \n");
    printf("    <div>\n");
    printf("        <form action=\"%s?routing=/search\" accept-charset=\"utf-8\" method=\"post\">\n", baseHref);
    printf("            <label style=\"display: block; height: 1px; width: 1px;\" for=\"search\">Search:</label>\n");
    
    if (
        (NULL != currentRequestMethod)
        && (0 == isListEmptyForAssociativeDynamicText(&listForPostParameters, __FILE__, __LINE__))
    )
    {
        struct associativeDynamicText* var1 = getElementByKeyFromListForAssociativeDynamicText(&listForPostParameters, "search", __FILE__, __LINE__);
        struct dynamicText* textFromSearchInput = (*var1).internalValue;
        printf("            <input style=\"width: 400px; margin-right: 25px;\" type=\"text\" id=\"search\" name=\"search\" value=\"%s\">\n", getBytesPointerFromDynamicText(&textFromSearchInput));
    }
    else
    {
        printf("            <input style=\"width: 400px; margin-right: 25px;\" type=\"text\" id=\"search\" name=\"search\" value=\"\">\n");
    }
    
    fputs("\n" \
    "            <input type=\"hidden\" name=\"hidden_input_field\">\n" \
    "            <input type=\"submit\" value=\"start Product Search (data array)\">\n" \
    "        </form>\n" \
    "    </div>\n" \
    "</nav>\n" \
    "\n", stdout);

    printf("<!-- main content -->\n");
    printf("<main>%s</main>\n", getBytesPointerFromDynamicText(&contentForMain));


    freeDynamicText(&cssTextForNode1, __FILE__, __LINE__);
    freeDynamicText(&cssTextForNode4, __FILE__, __LINE__);
    freeDynamicText(&cssTextForNode5, __FILE__, __LINE__);
    freeDynamicText(&cssTextForNode6, __FILE__, __LINE__);
    freeDynamicText(&cssTextForNode7, __FILE__, __LINE__);
    freeDynamicText(&cssTextForNodeQuote, __FILE__, __LINE__);
    freeDynamicText(&contentForMain, __FILE__, __LINE__);

    freeListForAssociativeDynamicText(&listForGetParameters, __FILE__, __LINE__);
    freeListForAssociativeDynamicText(&listForPostParameters, __FILE__, __LINE__);

    char textForCurrentTimestamp[256];
    time_t currentTime;
    struct tm localTimeObject;

    // @TODO: Custom-Funktion fehlt!
    currentTime = time(NULL);

    // @TODO: Custom-Funktion fehlt!
    if (NULL == localtime_r(&currentTime, &localTimeObject))
    {
        printf("[ERROR] Error during logging because localtime is NULL!");
        customExit(EXIT_FAILURE);
    }

    // @TODO: Custom-Funktion fehlt!
    strftime(textForCurrentTimestamp, 256, "%Y-%m-%d %H:%M:%S", &localTimeObject);

    struct timespec clockEnd;
    
    // @TODO: Custom-Funktion fehlt!
    if (-1 == clock_gettime(CLOCK_REALTIME, &clockEnd))
    {
        // @TODO: Custom-Funktion fehlt!
        perror("clock_gettime // end");
        exit(EXIT_FAILURE);
    }

    double runtimeInSeconds = ((double) clockEnd.tv_nsec / 1000000000.0L) + ((double) clockEnd.tv_sec - (double) clockStart.tv_sec);
    runtimeInSeconds -= ((double) clockStart.tv_nsec / 1000000000.0L);

    double runtimeInMilliSeconds = ((double) clockEnd.tv_nsec / 1000000.0L) + (((double) clockEnd.tv_sec - (double) clockStart.tv_sec) * 1000.0L);
    runtimeInMilliSeconds -= ((double) clockStart.tv_nsec / 1000000.0L);

    double runtimeInMicroSeconds = ((double) clockEnd.tv_nsec / 1000.0L) + (((double) clockEnd.tv_sec - (double) clockStart.tv_sec) * 1000000.0L);
    runtimeInMicroSeconds -= ((double) clockStart.tv_nsec / 1000.0L);
    
    fputs("\n" \
    "<!-- footer -->\n", stdout);
    printf("<footer>© 2021 Maatuu.li // Thomas Krüger<br />Contents prepared on the server with C in %.6lf seconds (%.6lf milliseconds or %.3lf microseconds). All time measurements are affected from the integrated GCC sanitizers (2x – 10x slowdown).</footer>\n", runtimeInSeconds, runtimeInMilliSeconds, runtimeInMicroSeconds);
    printf("<div id=\"debug_section\" style=\"padding: 10px; margin-top: 25px; background-color: #F5DEB3;\"><span class=\"bold\">Additional debug links for testing:</span><br /><ul><li style=\"margin-top: 15px; margin-bottom: 15px;\"><a href=\"?routing=/old_products\">301-Redirect-Link to \"Products (data array)\"</a></li><li style=\"margin-top: 15px; margin-bottom: 15px;\"><a href=\"?routing=/1234567890\">HTTP-Status-Code-404 Broken Link</a></li><li style=\"margin-top: 15px; margin-bottom: 15px;\"><a href=\"?routing=/delete-cookie\">Delete Cookie</a></li><li style=\"margin-top: 15px; margin-bottom: 15px;\"><a href=\"?routing=/accept-cookie\">Accept Cookie</a></li></ul><span class=\"bold\">Debug output</span>:<br />Server time: %s // Cookie: \"%s\" //<br />%i allocated bytes at peak / %i allocated bytes at the end (%ix allocation, %ix realloc, %ix free)</div>\n", textForCurrentTimestamp, currentCookie, globalePeakOfAllocatedMemoryInBytes, globaleAmountOfAllocatedMemoryInBytes, globaleAmountOfAllocations, globaleAmountOfReallocations, globaleAmountOfFrees);
    fputs("\n" \
    "</body>\n" \
    "</html>", stdout);
}

