
void
appendHtmlForStartPage(struct dynamicText** contentForMain, int* noUrlMatchedForRouting, char* filename, int lineNumber)
{
    *noUrlMatchedForRouting = 0;
    
    assignDynamicText(contentForMain, "\n" \
    "    <p><span class=\"bold\">Project goals</span>:</p>\n" \
    "    <ul class=\"list_settings\">\n" \
    "        <li>web development in <span class=\"bold\">compiled programming languages</span> like the C programming language</li>\n" \
    "        <li>basic set of functions for <span class=\"bold\">programming easily</span> a website</li>\n" \
    "        <li>usage of <span class=\"bold\">FastCGI or CGI</span> (<a rel=\"noopener noreferrer nofollow\" target=\"_blank\" href=\"https://fastcgi-archives.github.io/Understanding_FastCGI_Application_Performance_FastCGI.html\">link</a>)\n" \
    "            <ul>\n" \
    "                <li>CGI and FastCGI are part of most web spaces for just $5 per month</li>\n" \
    "                <li>execute your compiled web sites <span class=\"bold\">without</span> the need to have an own web server</li>\n" \
    "            </ul>\n" \
    "        </li>\n" \
    "        <li>usage of tools and best practices for <span class=\"bold\">defensive programming</span> in error-prone programming languages\n" \
    "            <ul>\n" \
    "                <li><span class=\"bold\">unit tests</span> with good equivalence partitioning</li>\n" \
    "                <li><span class=\"bold\">manual test cases</span> with a spreadsheet document</li>\n" \
    "                <li><span class=\"bold\">automated browser tests</span> with Selenium automation tool (<a rel=\"noopener noreferrer nofollow\" target=\"_blank\" href=\"https://www.selenium.dev/\">link</a>) and the Java programming language</li>\n" \
    "                <li>usage of an <span class=\"bold\">address santizer</span> tools to avoid <span class=\"bold\">not allowed</span> read or write actions in memory (<a rel=\"noopener noreferrer nofollow\" target=\"_blank\" href=\"https://www.usenix.org/system/files/conference/atc12/atc12-final39.pdf\">link to paper from the developers</a>)</li>\n" \
    "                <li>writing own functions with <span class=\"bold\">low cyclomatic complexity for easy maintenance</span> (<a rel=\"noopener noreferrer nofollow\" target=\"_blank\" href=\"https://www.gnu.org/software/complexity/manual/complexity.html#complexity-scale\">link</a>)</li>\n" \
    "                <li><span class=\"bold\">strict exit</span> during wrong usage of own functions with <span class=\"bold\">detailed error logging</span> (origin .c-filename + line number)</li>\n" \
    "                <li>usage of CppCheck (<a rel=\"noopener noreferrer nofollow\" target=\"_blank\" href=\"http://cppcheck.sourceforge.net/\">link</a>) and Splint tool (<a rel=\"noopener noreferrer nofollow\" target=\"_blank\" href=\"https://splint.org/\">link</a>) for <span class=\"bold\">static code analysis</span></li>\n" \
    "                <li><span class=\"bold\">high code coverage</span> for own functions with lcov tool (<a rel=\"noopener noreferrer nofollow\" target=\"_blank\" href=\"http://ltp.sourceforge.net/coverage/lcov.php\">link</a>)</li>\n" \
    "            </ul>\n" \
    "        </li>\n" \
    "        <li>showing the ratio between source code for the production code and unit tests\n" \
    "            <ul>\n" \
    "                <li>ratio 4:1 for the frontend sources</li>\n" \
    "                <li>ratio 1:4 for the core sources</li>\n" \
    "            </ul>\n" \
    "        </li>\n" \
    "        <li>statistics for the amount of allocation, reallocation and free calls</li>\n" \
    "        <li>\"One-file compilation\" approach with multi *.c file structure: You <span class=\"bold\">compile the whole website</span> with one GCC bash line.</li>\n" \
    "        <li>future plans for porting this project to PHP (<a rel=\"noopener noreferrer nofollow\" target=\"_blank\" href=\"https://en.wikipedia.org/wiki/PHP\">link</a>) and the strong-typing Ada programming language (<a rel=\"noopener noreferrer nofollow\" target=\"_blank\" href=\"https://en.wikipedia.org/wiki/Ada_(programming_language)\">link</a>)</li>\n" \
    "    </ul>\n" \
    "    <br />\n" \
    "    <p>Here you can find detailed <a class=\"bold\" href=\"?routing=/project-statistics\">project statistics</a>.</p>\n" \
    "    \n", filename, lineNumber);
}


void
appendHtmlForProductDetailPage(struct dynamicText** contentForMain, int* noUrlMatchedForRouting, char* currentUriText, char* filename, int lineNumber)
{
    char* htmlTemplate = "\n" \
        "    <p><span class=\"bold\">Product information</span>:</p>\n" \
        "    <p><span class=\"bold\">Product number:</span><br />{{ product_id }}</p>\n" \
        "    <p><span class=\"bold\">Product:</span><br />{{ title }}</p>\n" \
        "    <p><span class=\"bold\">Description:</span><br />{{ description }}</p>\n";

    int amountOfElements = sizeof(products) / sizeof(products[0]);

    struct dynamicText* partOfUrl = allocateDynamicText(filename, lineNumber);

    for (int i = 0; i < amountOfElements; i++)
    {
        assignDynamicText(&partOfUrl, "/products/", filename, lineNumber);
        appendDynamicText(&partOfUrl, products[i].id, filename, lineNumber);
        
        if (0 == endsWith(currentUriText, getBytesPointerFromDynamicText(&partOfUrl), __FILE__, __LINE__))
        {
            continue;
        }
        
        *noUrlMatchedForRouting = 0;
        
        struct type_product product = products[i];
        
        struct dynamicText* text = allocateDynamicText(filename, lineNumber);
        assignDynamicText(&text, htmlTemplate, filename, lineNumber);

        replaceDynamicText(&text, "{{ product_id }}", product.product_id, filename, lineNumber);
        replaceDynamicText(&text, "{{ title }}", product.title, filename, lineNumber);
        replaceDynamicText(&text, "{{ description }}", product.description, filename, lineNumber);

        appendDynamicText(contentForMain, getBytesPointerFromDynamicText(&text), __FILE__, __LINE__);
        freeDynamicText(&text, filename, lineNumber);
        
        break;
    }
    
    freeDynamicText(&partOfUrl, filename, lineNumber);
}


void
appendHtmlForProductOverviewWithDataArray(struct dynamicText** contentForMain, int* noUrlMatchedForRouting, char* filename, int lineNumber)
{
    *noUrlMatchedForRouting = 0;
    
    char* htmlTemplate = "    <p><a href=\"?routing=/products/{{ id }}\">{{ title }}</a> ({{ product_id }})</p>\n";

    assignDynamicText(contentForMain, "\n    <p><span class=\"bold\">Product overview</span>:</p>\n", __FILE__, __LINE__);
    struct dynamicText* text = allocateDynamicText(filename, lineNumber);

    int amountOfElements = sizeof(products) / sizeof(products[0]);
    for (int i = 0; i < amountOfElements; i++)
    {
        struct type_product product = products[i];

        assignDynamicText(&text, htmlTemplate, filename, lineNumber);

        replaceDynamicText(&text, "{{ id }}", product.id, filename, lineNumber);
        replaceDynamicText(&text, "{{ product_id }}", product.product_id, filename, lineNumber);
        replaceDynamicText(&text, "{{ title }}", product.title, filename, lineNumber);

        appendDynamicText(contentForMain, getBytesPointerFromDynamicText(&text), __FILE__, __LINE__);
    }
    
    freeDynamicText(&text, filename, lineNumber);
}


void
appendHtmlForQuoteOverviewWithDataArray(struct dynamicText** contentForMain, int* noUrlMatchedForRouting, char* filename, int lineNumber)
{
    *noUrlMatchedForRouting = 0;
    
    char* htmlTemplate = "    <p><span style=\"font-style: italic;\">\"{{ quote }}\"</span><br /><span style=\"font-weight: 700;\">{{ author }}</span></p>\n";

    assignDynamicText(contentForMain, "\n    <p><span class=\"bold\">Quote overview</span>:</p>\n", __FILE__, __LINE__);
    struct dynamicText* text = allocateDynamicText(filename, lineNumber);

    int amountOfElements = sizeof(quotes) / sizeof(quotes[0]);
    for (int i = 0; i < amountOfElements; i++)
    {
        struct type_quote quote = quotes[i];

        assignDynamicText(&text, htmlTemplate, filename, lineNumber);

        replaceDynamicText(&text, "{{ id }}", quote.id, filename, lineNumber);
        replaceDynamicText(&text, "{{ quote }}", quote.quote, filename, lineNumber);
        replaceDynamicText(&text, "{{ author }}", quote.author, filename, lineNumber);

        appendDynamicText(contentForMain, getBytesPointerFromDynamicText(&text), __FILE__, __LINE__);
    }
    
    freeDynamicText(&text, filename, lineNumber);
}


void
appendHtmlForProductOverviewWithMySql(struct dynamicText** contentForMain, int* noUrlMatchedForRouting, char* filename, int lineNumber)
{
    *noUrlMatchedForRouting = 0;
    
    MYSQL mysqlObject;

    // @TODO: Custom-Funktion fehlt!
    if (NULL == mysql_init(&mysqlObject))
    {
        *noUrlMatchedForRouting = 1;
        appendMessageToErrorLog("mysql_init() return NULL!", __func__, __FILE__, __LINE__);
    
        customFree(&mysqlObject, 50);
    
        return;
    }
    
    MYSQL mysqlObjectForSecuredDeallocation = mysqlObject;
    
    mysql_options(&mysqlObject, MYSQL_SET_CHARSET_NAME, "utf8"); 
    mysql_options(&mysqlObject, MYSQL_INIT_COMMAND, "SET NAMES utf8");
    
    // @TODO: Custom-Funktion fehlt!
    MYSQL *mysqlConnection = mysql_real_connect(&mysqlObject, getDatabaseServerName(), getDatabaseUsername(), getDatabasePassword(), getDatabaseName(), 0, 0, 0);
    
    if (NULL == mysqlConnection)
    {
        *noUrlMatchedForRouting = 1;
        
        // @TODO: Custom-Funktion fehlt!
        appendMessageToErrorLog(mysql_error(&mysqlObject), __func__, __FILE__, __LINE__);
        
        // @TODO: Custom-Funktion fehlt!
        mysql_close(mysqlConnection);
        mysql_close(&mysqlObjectForSecuredDeallocation);
    
        return;
    }

    appendDynamicText(contentForMain, "\n    <p><span class=\"bold\">Product overview</span>:</p>\n", __FILE__, __LINE__);
    
    
    // @TODO: Custom-Funktion fehlt!
    int state = mysql_query(mysqlConnection, "SELECT id, product_id, title FROM products ORDER BY title ASC");
    
    if (0 != state)
    {
        *noUrlMatchedForRouting = 1;
        
        // @TODO: Custom-Funktion fehlt!
        appendMessageToErrorLog(mysql_error(mysqlConnection), __func__, __FILE__, __LINE__);
        
        return;
    }
    
    // @TODO: Custom-Funktion fehlt!
    MYSQL_RES *result = mysql_store_result(mysqlConnection);

    if (NULL == result)
    {
        *noUrlMatchedForRouting = 1;
        
        // @TODO: Custom-Funktion fehlt!
        appendMessageToErrorLog("result is NULL from mysql_store_result()!", __func__, __FILE__, __LINE__);
        appendMessageToErrorLog(mysql_error(mysqlConnection), __func__, __FILE__, __LINE__);
        
        return;
    }

    char* htmlTemplate = "    <p><a href=\"?routing=/products/{{ id }}\">{{ title }}</a> ({{ product_id }})</p>\n";
    struct dynamicText* text = allocateDynamicText(filename, lineNumber);
    
    MYSQL_ROW row;
    // @TODO: Custom-Funktion fehlt!
    while (NULL != (row = mysql_fetch_row(result)))
    {
        assignDynamicText(&text, htmlTemplate, filename, lineNumber);

        replaceDynamicText(&text, "{{ id }}", row[0], filename, lineNumber);
        replaceDynamicText(&text, "{{ title }}", row[2], filename, lineNumber);
        replaceDynamicText(&text, "{{ product_id }}", row[1], filename, lineNumber);

        appendDynamicText(contentForMain, getBytesPointerFromDynamicText(&text), __FILE__, __LINE__);
    }

    freeDynamicText(&text, filename, lineNumber);

    // @TODO: Custom-Funktion fehlt!
    mysql_free_result(result);
    // @TODO: Custom-Funktion fehlt!
    mysql_close(mysqlConnection);
}


void
appendHtmlForImpressum(struct dynamicText** contentForMain, int* noUrlMatchedForRouting, char* filename, int lineNumber)
{
    *noUrlMatchedForRouting = 0;
    
    appendDynamicText(contentForMain, "\n" \
    "    <p>This website is a prototype for showing how to use the C programming language to program a CGI-based standard website.</p>\n", __FILE__, __LINE__);
}


void
appendHtmlForProjectStatistics(struct dynamicText** contentForMain, int* noUrlMatchedForRouting, char* filename, int lineNumber)
{
    *noUrlMatchedForRouting = 0;
    
    assignDynamicText(contentForMain, "\n" \
    "    <p><span class=\"bold\">Project statistics</span>:</p>\n" \
    "    <ul class=\"list_settings\">\n" \
    "        <li>programmed by Thomas Krüger</li>\n" \
    "        <li>Public GitHub repository: <a rel=\"noopener noreferrer nofollow\" target=\"_blank\" href=\"https://github.com/Maatuuli/CompiledWebDevelopment\">https://github.com/Maatuuli/CompiledWebDevelopment</a></li>\n" \
    "        <li><span class=\"bold\">CGI</span> web project</li>\n" \
    "        <li>programmed in the <span class=\"bold\">C programming language</span></li>\n" \
    "        <li><span class=\"bold\">no external libraries</span>, only standard C library and MySQL library</li>\n" \
    "        <li>integrated <span class=\"bold\">sanitizers for addresses, leaks and undefined behavior</span> (GCC: <a rel=\"noopener noreferrer nofollow\" target=\"_blank\" href=\"https://www.usenix.org/system/files/conference/atc12/atc12-final39.pdf\">link to the paper from the developers</a> // <a rel=\"noopener noreferrer nofollow\" target=\"_blank\" href=\"https://gcc.gnu.org/onlinedocs/gcc/Instrumentation-Options.html#index-fsanitize_003daddress\">GCC options</a>)</li>\n" \
    "        <li>usage of check tools: CppCheck (<a rel=\"noopener noreferrer nofollow\" target=\"_blank\" href=\"http://cppcheck.sourceforge.net/\">link</a>), Splint (<a rel=\"noopener noreferrer nofollow\" target=\"_blank\" href=\"https://splint.org/\">link</a>), GNU Complexity (<a rel=\"noopener noreferrer nofollow\" target=\"_blank\" href=\"https://www.gnu.org/software/complexity/manual/complexity.html#complexity-scale\">link</a>)</li>\n" \
    "        <li><span class=\"bold\">project stucture for frontend website</span>:\n" \
    "            <ul>\n" \
    "                <li>Public GitHub repository: <a rel=\"noopener noreferrer nofollow\" target=\"_blank\" href=\"https://github.com/Maatuuli/CompiledWebDevelopment/tree/main/apps/frontend\">https://github.com/Maatuuli/CompiledWebDevelopment/tree/main/apps/frontend</a></li>\n" \
    "                <li>Files for \"frontend\" application:\n" \
    "                    <ul>\n" \
    "                        <li>4x application .c files\n" \
    "                            <ul>\n" \
    "                                <li><span class=\"bold\">compiled from scratch</span> included core .c files in 0.774 seconds with GCC compiler 9.3 on Ubuntu Linux</li>\n" \
    "                                <li>routing</li>\n" \
    "                                <li>html templates</li>\n" \
    "                                <li>database data</li>\n" \
    "                                <li>HTTP status codes</li>\n" \
    "                            </ul>\n" \
    "                        </li>\n" \
    "                        <li>1x unit test .c file for application *.c files</li>\n" \
    "                        <li>4x .java files for automated test cases\n" \
    "                            <ul>\n" \
    "                                <li>plain Java and <span class=\"bold\">Selenium automation tool</span> with Chrome browser</li>\n" \
    "                                <li>compiled with javac compiler</li>\n" \
    "                            </ul>\n" \
    "                        </li>\n" \
    "                        <li>1x spreadsheet .ods file (OpenOffice Calc) for manual test cases</li>\n" \
    "                    </ul>\n" \
    "                </li>\n" \
    "                <li>Testing:\n" \
    "                    <ul>\n" \
    "                        <li><span class=\"bold\">40x manual test cases</span>\n" \
    "                            <ul>\n" \
    "                                <li>QA spreadsheet document</li>\n" \
    "                                <li>Public GitHub repository: <a rel=\"noopener noreferrer nofollow\" target=\"_blank\" href=\"https://github.com/Maatuuli/CompiledWebDevelopment/tree/main/apps/frontend/manual_test_cases\">https://github.com/Maatuuli/CompiledWebDevelopment/tree/main/apps/frontend/manual_test_cases</a>\n" \
    "                                    <br />\n" \
    "                                    <br />\n" \
    "                                    <a target=\"blank\" href=\"manual_test_cases___2021-09-13.png\"><img src=\"manual_test_cases___2021-09-13.png\" width=\"700\" alt=\"Spreadsheet document with manual test cases for the frontend.\" /></a>\n" \
    "                                </li>\n" \
    "                            </ul>\n" \
    "                        </li>\n" \
    "                        <li><span class=\"bold\">10 of 40 manual test cases were automated</span>\n" \
    "                            <ul>\n" \
    "                                <li>browser automation with <span class=\"bold\">Selenium</span> and Google Chrome</li>\n" \
    "                                <li>test runs showing for each automated test case every step for reproduce (<a target=\"blank\" href=\"frontend___automated_test_cases.txt\">link to file</a>)</li>\n" \
    "                                <li>duration for complete test run: 11.1 seconds</li>\n" \
    "                                <li>Public GitHub repository: <a rel=\"noopener noreferrer nofollow\" target=\"_blank\" href=\"https://github.com/Maatuuli/CompiledWebDevelopment/tree/main/apps/frontend/automated_test_cases\">https://github.com/Maatuuli/CompiledWebDevelopment/tree/main/apps/frontend/automated_test_cases</a>\n" \
    "                                    <br />\n" \
    "                                    <br />\n" \
    "                                    <a target=\"blank\" href=\"frontend___automated_test_cases.txt\"><img src=\"frontend___automated_test_cases___2021-09-13.png\" width=\"700\" alt=\"Logging output of a complete test run from the automated browser tests with Selenium.\" /></a>\n" \
    "                                </li>\n" \
    "                            </ul>\n" \
    "                        </li>\n" \
    "                        <li><span class=\"bold\">13x unit tests</span>\n" \
    "                            <ul>\n" \
    "                                <li>written in plain C</li>\n" \
    "                                <li>checking all routing URLs from the frontend application</li>\n" \
    "                                <li>duration for a complete test run: 1.1 seconds</li>\n" \
    "                                <li>Public GitHub repository: <a rel=\"noopener noreferrer nofollow\" target=\"_blank\" href=\"https://github.com/Maatuuli/CompiledWebDevelopment/tree/main/apps/frontend/unit_tests\">https://github.com/Maatuuli/CompiledWebDevelopment/tree/main/apps/frontend/unit_tests</a></li>\n" \
    "                            </ul>\n" \
    "                        </li>\n" \
    "                    </ul>\n" \
    "                </li>\n" \
    "                <li>Lines of code for \"frontend\" application:\n" \
    "                    <ul>\n" \
    "                        <li>total: 1301 loc</li>\n" \
    "                        <li>748 loc (application *.c files)</li>\n" \
    "                        <li>260 loc (unit tests *.c files)</li>\n" \
    "                        <li>258 loc (automated test cases *.java files)</li>\n" \
    "                        <li>22 loc (bash files for testing & code coverage)\n" \
    "                            <br />\n" \
    "                            <br />\n" \
    "                            <img src=\"frontend___lines_of_code_chart___2021-09-13.png\" width=\"700\" alt=\"Pie chart for visualizing the lines of code for the frontend application.\" />\n" \
    "                        </li>\n" \
    "                    </ul>\n" \
    "                </li>\n" \
    "                <li>Code coverage for \"frontend\":\n" \
    "                    <ul>\n" \
    "                        <li>lines: 74.1%</li>\n" \
    "                        <li>functions: 100.0%\n" \
    "                            <br />\n" \
    "                            <br />\n" \
    "                            <a target=\"blank\" href=\"frontend___code_coverage___2021-09-13.png\"><img src=\"frontend___code_coverage___2021-09-13.png\" width=\"700\" alt=\"Chart HTML overview of the current state of the code coverage from the frontend files.\" /></a>\n" \
    "                        </li>\n" \
    "                    </ul>\n" \
    "                </li>\n" \
    "                <li>Cyclomatic complexity for \"frontend\":\n" \
    "                    <ul>\n" \
    "                        <li>14x *.c functions</li>\n" \
    "                        <li>complexity scores: <span class=\"bold\">1 – 13</span></li>\n" \
    "                    </ul>\n" \
    "                </li>\n" \
    "            </ul>\n" \
    "        </li>\n" \
    "        <li style=\"margin-top: 30px;\"><span class=\"bold\">project stucture for core files for C web development</span>:\n" \
    "            <ul>\n" \
    "                <li>Public GitHub repository: <a rel=\"noopener noreferrer nofollow\" target=\"_blank\" href=\"https://github.com/Maatuuli/CompiledWebDevelopment/tree/main/core\">https://github.com/Maatuuli/CompiledWebDevelopment/tree/main/core</a></li>\n" \
    "                <li>Files for \"core\":\n" \
    "                    <ul>\n" \
    "                        <li>9x core .c files\n" \
    "                            <ul>\n" \
    "                                <li>implementation of dynamicText (allocation, assign, append, free, lists)</li>\n" \
    "                                <li>implementation of associativeDynamicText (allocation, set, free, lists)</li>\n" \
    "                                <li>helper functions for text operations (explode, implode, replace, find, substring, etc.)</li>\n" \
    "                                <li>helper functions for CGI (GET/POST parameters, escaping, etc.)</li>\n" \
    "                                <li>wrapper functions for standard library functions</li>\n" \
    "                                <li>wrapper functions for MySQL functions</li>\n" \
    "                            </ul>\n" \
    "                        </li>\n" \
    "                        <li>78x unit test .c files for core .c files</li>\n" \
    "                    </ul>\n" \
    "                </li>\n" \
    "                <li>Testing:\n" \
    "                    <ul>\n" \
    "                        <li><span class=\"bold\">161x unit tests</span>\n" \
    "                            <ul>\n" \
    "                                <li>written in plain C</li>\n" \
    "                                <li>duration for a complete test run: 6.1 seconds</li>\n" \
    "                                <li>Public GitHub repository: <a rel=\"noopener noreferrer nofollow\" target=\"_blank\" href=\"https://github.com/Maatuuli/CompiledWebDevelopment/tree/main/core/unit_tests\">https://github.com/Maatuuli/CompiledWebDevelopment/tree/main/core/unit_tests</a>\n" \
    "                                    <br />\n" \
    "                                    <br />\n" \
    "                                    <a target=\"blank\" href=\"core___unit-tests___2021-09-10.png\"><img src=\"core___unit-tests___2021-09-10.png\" width=\"700\" alt=\"Linux console screen of executed unit tests for the core files.\" /></a>\n" \
    "                                </li>\n" \
    "                            </ul>\n" \
    "                        </li>\n" \
    "                    </ul>\n" \
    "                </li>\n" \
    "                <li>Lines of code for \"core\":\n" \
    "                    <ul>\n" \
    "                        <li>total: 6095 loc</li>\n" \
    "                        <li>1190 loc (core *.c files)</li>\n" \
    "                        <li>4731 loc (unit tests for core *.c files)</li>\n" \
    "                        <li>174 loc (bash files for testing & code coverage)\n" \
    "                            <br />\n" \
    "                            <br />\n" \
    "                            <img src=\"chart___2021-09-10.png\" width=\"700\" alt=\"Pie chart for visualizing the lines of code for the core sources in this CGI project.\" />\n" \
    "                        </li>\n" \
    "                    </ul>\n" \
    "                </li>\n" \
    "                <li>Code coverage for \"core\":\n" \
    "                    <ul>\n" \
    "                        <li>lines: 77.4%</li>\n" \
    "                        <li>functions: 78.8%\n" \
    "                            <br />\n" \
    "                            <br />\n" \
    "                            <a target=\"blank\" href=\"core___code_coverage___2021-09-10.png\"><img src=\"core___code_coverage___2021-09-10.png\" width=\"700\" alt=\"Chart HTML overview of the current state of the code coverage from the core files.\" /></a>\n" \
    "                        </li>\n" \
    "                    </ul>\n" \
    "                </li>\n" \
    "                <li>Cyclomatic complexity for \"core\":\n" \
    "                    <ul>\n" \
    "                        <li>*.c files: 38x functions</li>\n" \
    "                        <li>complexity scores: <span class=\"bold\">1 – 6</span> (level: \"Easily maintained code.\")</li>\n" \
    "                        <li>unit-tests: 240x functions</li>\n" \
    "                        <li>complexity scores: <span class=\"bold\">1 – 5</span> (level: \"Easily maintained code.\")</li>\n" \
    "                    </ul>\n" \
    "                </li>\n" \
    "            </ul>\n" \
    "            <br />\n" \
    "            <br />\n" \
    "            <br />\n" \
    "        </li>\n" \
    "        <li>General information about cyclomatic complexity analysis (GNU Complexity 1.10):\n" \
    "            <ul>\n" \
    "                <li>Description of the score values:\n" \
    "                    <ul>\n" \
    "                        <li>0 – 9 => Easily maintained code.</li>\n" \
    "                        <li>10 – 19 => Maintained with little trouble.</li>\n" \
    "                        <li>20 – 29 => Maintained with some effort.</li>\n" \
    "                        <li>30 – 39 => Difficult to maintain code.</li>\n" \
    "                        <li>40 – 49 => Hard to maintain code.</li>\n" \
    "                        <li>50 – 99 => Unmaintainable code.</li>\n" \
    "                        <li>100 – 199 => Crazy making difficult code.</li>\n" \
    "                        <li>200+ => I only wish I were kidding.</li>\n" \
    "                        <li>reference: <a href=\"https://www.gnu.org/software/complexity/manual/complexity.html#complexity-scale\" rel=\"noopener noreferrer nofollow\" target=\"_blank\">https://www.gnu.org/software/complexity/manual/complexity.html#complexity-scale</a></li>\n" \
    "                    </ul>\n" \
    "                </li>\n" \
    "            </ul>\n" \
    "        </li>\n" \
    "    </ul>\n", __FILE__, __LINE__);
}


void
appendHtmlForSearch(struct dynamicText** contentForMain, int* noUrlMatchedForRouting, char* currentRequestMethod, struct listForAssociativeDynamicText** listForPostParameters, char* filename, int lineNumber)
{
    *noUrlMatchedForRouting = 0;
    
    struct dynamicText *textFromSearchInput = NULL;
    
    if (NULL != currentRequestMethod)
    {
        if (0 == isListEmptyForAssociativeDynamicText(listForPostParameters, __FILE__, __LINE__))
        {
            struct associativeDynamicText* var1 = getElementByKeyFromListForAssociativeDynamicText(listForPostParameters, "search", __FILE__, __LINE__);
            textFromSearchInput = (*var1).internalValue;
            
            convertSpecialCharsIntoHtmlCodes(&textFromSearchInput, __FILE__, __LINE__);
            
            appendMessageToErrorLog("Search input was:", __func__, __FILE__, __LINE__);
            appendMessageToErrorLog(getBytesPointerFromDynamicText(&textFromSearchInput), __func__, __FILE__, __LINE__);
        }
    }
    
    if (NULL != textFromSearchInput)
    {
        appendDynamicText(contentForMain, "\n    <p>Search results for the text input: \"", __FILE__, __LINE__);
        appendDynamicText(contentForMain, getBytesPointerFromDynamicText(&textFromSearchInput), __FILE__, __LINE__);
        appendDynamicText(contentForMain, "\"</p>\n", __FILE__, __LINE__);
    }
    else
    {
        appendDynamicText(contentForMain, "\n    <p>Search results for the text input: \"\"</p>\n", __FILE__, __LINE__);
    }
    
    if (
        (NULL != textFromSearchInput)
        && (0 == isExactTextMatch(getBytesPointerFromDynamicText(&textFromSearchInput), "", __FILE__, __LINE__))
    )
    {
        struct dynamicText* bufferText = allocateDynamicText(__FILE__, __LINE__);
        struct dynamicText* bufferText2 = allocateDynamicText(__FILE__, __LINE__);
        struct dynamicText* bufferText3 = allocateDynamicText(__FILE__, __LINE__);

        assignDynamicText(&bufferText2, "<span style=\"color: red; font-weight: bold;\">", __FILE__, __LINE__);
        appendDynamicText(&bufferText2, getBytesPointerFromDynamicText(&textFromSearchInput), __FILE__, __LINE__);
        appendDynamicText(&bufferText2, "</span>", __FILE__, __LINE__);

        struct dynamicText *toLoweredTextFromSearchInput = allocateDynamicText(__FILE__, __LINE__);
        assignDynamicText(&toLoweredTextFromSearchInput, getBytesPointerFromDynamicText(&textFromSearchInput), __FILE__, __LINE__);
        toLower(&toLoweredTextFromSearchInput, __FILE__, __LINE__);

        int amountOfElements = sizeof(products) / sizeof(products[0]);
        for (int i = 0; i < amountOfElements; i++)
        {
            struct type_product product = products[i];
            
            int wasFound = 0;
            
            assignDynamicText(&bufferText, product.title, __FILE__, __LINE__);
            toLower(&bufferText, __FILE__, __LINE__);
            
            int newPosition = findPositionInDynamicText(&bufferText, getBytesPointerFromDynamicText(&toLoweredTextFromSearchInput), 0, __FILE__, __LINE__);
            if (-1 != newPosition)
            {
                wasFound = 1;
            }

            assignDynamicText(&bufferText, product.description, __FILE__, __LINE__);
            toLower(&bufferText, __FILE__, __LINE__);
            
            newPosition = findPositionInDynamicText(&bufferText, getBytesPointerFromDynamicText(&toLoweredTextFromSearchInput), 0, __FILE__, __LINE__);
            if (-1 != newPosition)
            {
                wasFound = 1;
            }

            assignDynamicText(&bufferText, product.product_id, __FILE__, __LINE__);
            toLower(&bufferText, __FILE__, __LINE__);

            newPosition = findPositionInDynamicText(&bufferText, getBytesPointerFromDynamicText(&toLoweredTextFromSearchInput), 0, __FILE__, __LINE__);
            if (-1 != newPosition)
            {
                wasFound = 1;
            }
            
            if (0 == wasFound)
            {
                continue;
            }
        
            noUrlMatchedForRouting = 0;
            
            assignDynamicText(&bufferText3, "", __FILE__, __LINE__);

            appendDynamicText(&bufferText3, "\n" \
            "    <p><a href=\"?routing=/products/{{ id }}\"><span class=\"bold\">{{ title }}</span></a> (ID: {{ product_id }})<br />\n" \
            "    {{ description }}</p>\n", __FILE__, __LINE__);

            replaceDynamicText(&bufferText3, "{{ id }}", product.id, __FILE__, __LINE__);

            assignDynamicText(&bufferText, product.title, __FILE__, __LINE__);
            replaceDynamicText(&bufferText, getBytesPointerFromDynamicText(&textFromSearchInput), getBytesPointerFromDynamicText(&bufferText2), __FILE__, __LINE__);
            replaceDynamicText(&bufferText3, "{{ title }}", getBytesPointerFromDynamicText(&bufferText), __FILE__, __LINE__);

            assignDynamicText(&bufferText, product.product_id, __FILE__, __LINE__);
            replaceDynamicText(&bufferText, getBytesPointerFromDynamicText(&textFromSearchInput), getBytesPointerFromDynamicText(&bufferText2), __FILE__, __LINE__);
            replaceDynamicText(&bufferText3, "{{ product_id }}", getBytesPointerFromDynamicText(&bufferText), __FILE__, __LINE__);

            assignDynamicText(&bufferText, product.description, __FILE__, __LINE__);
            replaceDynamicText(&bufferText, getBytesPointerFromDynamicText(&textFromSearchInput), getBytesPointerFromDynamicText(&bufferText2), __FILE__, __LINE__);
            replaceDynamicText(&bufferText3, "{{ description }}", getBytesPointerFromDynamicText(&bufferText), __FILE__, __LINE__);
    
            appendDynamicText(contentForMain, getBytesPointerFromDynamicText(&bufferText3), __FILE__, __LINE__);
        }
        
        freeDynamicText(&toLoweredTextFromSearchInput, __FILE__, __LINE__);
        freeDynamicText(&bufferText, __FILE__, __LINE__);
        freeDynamicText(&bufferText2, __FILE__, __LINE__);
        freeDynamicText(&bufferText3, __FILE__, __LINE__);
    }
}


void
executeActionsFor301RedirectSubpage(char* baseHref, char* filename, int lineNumber)
{
    /* Complete response header with additional linebreak and exit cgi program. */
    printf("Status: 301 Moved Permanently\n");
    printf("Location: %s?routing=/products\n", baseHref);
    
    printf("\n");
    customExit(EXIT_SUCCESS); }


void
appendHtmlForDeleteCookie(struct dynamicText** contentForMain, int* noUrlMatchedForRouting, char* filename, int lineNumber)
{
    *noUrlMatchedForRouting = 0;
    
    /* Delete cookie in HTTP header. */
    printf("Set-Cookie: hits=1; expires=Tue, 01-Dec-2020 10:00:00 GMT; path=/; domain=.maatuu.li; secure\n");
    
    appendDynamicText(contentForMain, "<p>Cookie was deleted. After the next reload its removed from your browser cache.</p>", __FILE__, __LINE__);
}


void
appendHtmlForAcceptCookie(struct dynamicText** contentForMain, int* noUrlMatchedForRouting, char* filename, int lineNumber)
{
    *noUrlMatchedForRouting = 0;
    
    /* Set cookie in HTTP header. */
    printf("Set-Cookie: hits=1; expires=Fri, 01-Apr-2032 10:00:00 GMT; path=/; domain=.maatuu.li; secure\n");
    
    appendDynamicText(contentForMain, "<p>Cookie was created.</p>", __FILE__, __LINE__);
}


void
appendHtmlFor404ErrorPage(struct dynamicText** contentForMain, char* filename, int lineNumber)
{
    /* Set up HTTP status code to 404. */
    printf("Status: 404 Not Found\n");
    
    appendDynamicText(contentForMain, "<p><span class=\"bold\">404 - Page not found</span><br /><br />This url does not exist!</p>", __FILE__, __LINE__);
}

