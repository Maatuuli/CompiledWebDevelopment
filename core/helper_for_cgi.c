
int
getNumericValueFromHexadecialLetter(unsigned char hexadecialLetter, char* filename, int lineNumber)
{
    struct typeForMapping {
        char from;
        int to;
    };
        
    struct typeForMapping mapping[] = {
        {.from='0',  .to=0},
        {.from='1',  .to=1},
        {.from='2',  .to=2},
        {.from='3',  .to=3},
        {.from='4',  .to=4},
        {.from='5',  .to=5},
        {.from='6',  .to=6},
        {.from='7',  .to=7},
        {.from='8',  .to=8},
        {.from='9',  .to=9},
        {.from='A',  .to=10},
        {.from='B',  .to=11},
        {.from='C',  .to=12},
        {.from='D',  .to=13},
        {.from='E',  .to=14},
        {.from='F',  .to=15},
    };

    int amountOfElements = sizeof(mapping) / sizeof(mapping[0]);
    for (int i = 0; i < amountOfElements; i++)
    {
        if (hexadecialLetter == mapping[i].from)
        {
            return mapping[i].to;
        }
    }

    appendMessageToErrorLog("Hexadecimal value is not known!", __func__, filename, lineNumber);
    customExit(EXIT_FAILURE);
    
    return 0;
}


void
convertCgiEncodingIntoNormalText(struct dynamicText** oldText, char* filename, int lineNumber)
{
    struct dynamicText* newText = allocateDynamicText(filename, lineNumber);
    
    if ((*newText).amountOfBytes < (*oldText)->amountOfBytes)
    {
        resizeDynamicText(&newText, (*oldText)->amountOfBytes, filename, lineNumber);
    }
    
    int index = 0;
    int delayCounter = -1;
    unsigned char letterValue = 1;
    for (int i = 0; i <= ((*oldText)->amountOfBytes - 1); i++)
    {
        if (2 == delayCounter)
        {
            delayCounter = 1;
            letterValue *= getNumericValueFromHexadecialLetter((*oldText)->bytes[i], filename, lineNumber);
            letterValue *= 16;
            
            continue;
        }

        if (1 == delayCounter)
        {
            letterValue += getNumericValueFromHexadecialLetter((*oldText)->bytes[i], filename, lineNumber);

            (*newText).bytes[index] = (unsigned char) letterValue;
            index++;
            delayCounter = -1;
            letterValue = 1;
            
            continue;
        }
        
        if ('%' == (*oldText)->bytes[i])
        {
            delayCounter = 2;
            letterValue = 1;
            continue;
        }

        if ('+' == (*oldText)->bytes[i])
        {
            (*newText).bytes[index] = ' ';
            index++;
            continue;
        }
        
        (*newText).bytes[index] = (*oldText)->bytes[i];
        index++;
    }

    // DEBUG // TODO // WRONG???    
    // index++;
    // (*newText).bytes[index] = '\0';

    // @TODO: This is totally unefficient. How to handle better?
    assignDynamicText(oldText, (*newText).bytes, filename, lineNumber);
    freeDynamicText(&newText, filename, lineNumber);
    newText = NULL;
}


struct dynamicText*
getPostDataFromStandardInput(char* currentRequestMethod, char* filename, int lineNumber)
{
    struct dynamicText* text = allocateDynamicText(filename, lineNumber);
    
    if (NULL == currentRequestMethod)
    {
        return text;
    }
    
    // @TODO: Länge des Vergleichs ist statisch und nicht dynamisch!
    int maximumLength = customStrlen("POST");
    int length = customStrlen(currentRequestMethod);
    
    if (length < maximumLength)
    {
        maximumLength = length;
    }
    
    if (0 != customStrncmp(currentRequestMethod, "POST", maximumLength))
    {
        return text;
    }
    
    char* len_ = customGetenv("CONTENT_LENGTH");
    int len = customStrtol(len_, NULL, 10);
    char *postdata = customCalloc(len + 1, sizeof(char));
    
    if (!postdata)
    {
        appendMessageToErrorLog("NULL pointer as return value from function calloc()!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);

        return text;
    }
    
    if (NULL == customFgets(postdata, len + 1, stdin))
    {
        appendMessageToErrorLog("NULL pointer as return value from function fgets()!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);

        return text;
    }
    
    assignDynamicText(&text, postdata, filename, lineNumber);
    customFree(postdata, len + 1);
    postdata = NULL;
    
    return text;
}


void
initRequestParametersByEnvironmentText(struct listForAssociativeDynamicText **list, char* textFromServer, char* filename, int lineNumber)
{
    if (NULL == textFromServer)
    {
        return;
    }

    if (0 == customStrlen(textFromServer))
    {
        return;
    }

    struct listForDynamicText* listForExplode = newListForDynamicText(filename, lineNumber);
    struct dynamicText* item = allocateDynamicText(filename, lineNumber);
    assignDynamicText(&item, textFromServer, filename, lineNumber);
    explodeDynamicText(&item, "&", &listForExplode, filename, lineNumber);
    freeDynamicText(&item, filename, lineNumber);
    item = NULL;

    int amountOfListElements = countElementsInListForDynamicText(&listForExplode, filename, lineNumber);
    for (int i = 0; i < amountOfListElements; i++)
    {
        struct dynamicText* elementFromList = getElementByIndexFromListForDynamicText(&listForExplode, i, filename, lineNumber);
        
        if (0 == getLengthFromDynamicText(&elementFromList, __FILE__, __LINE__))
        {
            continue;
        }
        
        struct listForDynamicText* listForPostParameter = newListForDynamicText(filename, lineNumber);
        explodeDynamicText(&elementFromList, "=", &listForPostParameter, filename, lineNumber);

        if (2 == countElementsInListForDynamicText(&listForPostParameter, filename, lineNumber))
        {
            struct dynamicText* textForKey = getElementByIndexFromListForDynamicText(&listForPostParameter, 0, filename, lineNumber);
            struct dynamicText* textForValue = getElementByIndexFromListForDynamicText(&listForPostParameter, 1, filename, lineNumber);

            convertCgiEncodingIntoNormalText(&textForKey, filename, lineNumber);
            convertCgiEncodingIntoNormalText(&textForValue, filename, lineNumber);
            stripTagsInDynamicText(&textForKey, filename, lineNumber);
            stripTagsInDynamicText(&textForValue, filename, lineNumber);

            addElementByKeyInListForAssociativeDynamicText(list, getBytesPointerFromDynamicText(&textForKey), getBytesPointerFromDynamicText(&textForValue), filename, lineNumber);
        }
        else if (1 == countElementsInListForDynamicText(&listForPostParameter, filename, lineNumber))
        {
            struct dynamicText* textForKey = getElementByIndexFromListForDynamicText(&listForPostParameter, 0, filename, lineNumber);
            convertCgiEncodingIntoNormalText(&textForKey, filename, lineNumber);
            stripTagsInDynamicText(&textForKey, filename, lineNumber);
            
            addElementByKeyInListForAssociativeDynamicText(list, getBytesPointerFromDynamicText(&textForKey), "", filename, lineNumber);
        }
        else
        {
            appendMessageToErrorLog("Amount of parts for $_POST parameter is not between 1 and 2!", __func__, filename, lineNumber);
            customExit(EXIT_FAILURE);
        }
        
        freeListForDynamicText(&listForPostParameter, filename, lineNumber);
        listForPostParameter = NULL;
    }

    freeListForDynamicText(&listForExplode, filename, lineNumber);
    listForExplode = NULL;
}


void
convertSpecialCharsIntoHtmlCodes(struct dynamicText** text, char* filename, int lineNumber)
{
    if (0 == getLengthFromDynamicText(text, __FILE__, __LINE__))
    {
        return;
    }

    struct typeForMapping {
        char* from;
        char* to;
    };
        
    struct typeForMapping mapping[] = {
        {.from="&",  .to="&amp;"},
        {.from="\"", .to="&quot;"},
        {.from="'",  .to="&apos;"},
        {.from="<",  .to="&lt;"},
        {.from=">",  .to="&gt;"}
    };

    int amountOfElements = sizeof(mapping) / sizeof(mapping[0]);
    for (int i = 0; i < amountOfElements; i++)
    {
        replaceDynamicText(text, mapping[i].from, mapping[i].to, filename, lineNumber);
    }
}
