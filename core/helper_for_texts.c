
int
findPositionInDynamicText(struct dynamicText** text, char* needle, int offset, char* filename, int lineNumber)
{
    if (NULL == text)
    {
        appendMessageToErrorLog("Variable is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (NULL == (*text))
    {
        appendMessageToErrorLog("Pointer is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (NULL == needle)
    {
        appendMessageToErrorLog("Needle is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }
    
    int lengthOfText = getLengthFromDynamicText(text, filename, lineNumber);
    int lengthOfNeedle = customStrlen(needle);

    if (0 == lengthOfNeedle)
    {
        appendMessageToErrorLog("Text for needle is empty!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }
    
    if (offset < 0)
    {
        appendMessageToErrorLog("Offset for start index is smaller than 0!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (0 == lengthOfText)
    {
        return -1;
    }
    
    if (offset >= lengthOfText)
    {
        appendMessageToErrorLog("Offset for start index is greater-equal than length of text!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (lengthOfNeedle > lengthOfText)
    {
        return -1;
    }

    for (int i = offset; i < lengthOfText; i++)
    {
        if ((*text)->bytes[i] != needle[0])
        {
            continue;
        }

        int maxBytesUntilEndOfText = lengthOfText - i;
        if (maxBytesUntilEndOfText < lengthOfNeedle)
        {
            break;
        }
        
        int isValid = 1;
        
        for (int k = 0; k < lengthOfNeedle; k++)
        {
            if ((*text)->bytes[i + k] != needle[k])
            {
                isValid = 0;
            }
        }

        if (isValid)
        {
            return i;
        }
    }
    
    return -1;
}


void
getSubstringInBytesFromDynamicText(struct dynamicText** text, int startIndexInBytes, int endIndexInBytes, struct dynamicText** substring, char* filename, int lineNumber)
{
    if (NULL == text)
    {
        appendMessageToErrorLog("Variable text is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (NULL == (*text))
    {
        appendMessageToErrorLog("Pointer for text is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }
    
    if (NULL == substring)
    {
        appendMessageToErrorLog("Variable for substring is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (NULL == (*substring))
    {
        appendMessageToErrorLog("Pointer for substring is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }
    
    if (startIndexInBytes < 0)
    {
        appendMessageToErrorLog("startIndexInBytes is smaller than 0!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (startIndexInBytes >= customStrlen((*text)->bytes))
    {
        appendMessageToErrorLog("startIndexInBytes is greater-equal than the maximum length of text!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (endIndexInBytes < startIndexInBytes)
    {
        appendMessageToErrorLog("endIndexInBytes is smaller than startIndexInBytes!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (endIndexInBytes > customStrlen((*text)->bytes))
    {
        appendMessageToErrorLog("endIndexInBytes is greater-equal than the maximum length of text!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    int maxLength = endIndexInBytes - startIndexInBytes;
    
    if ((*substring)->amountOfBytes < maxLength)
    {
        resizeDynamicText(substring, (*text)->amountOfBytes, filename, lineNumber);
    }
    
    /* Clearing allocated memory again for safety. */
    customMemset((*substring)->bytes, '\0', (*substring)->amountOfBytes);
    
    for (int i = 0; i < maxLength; i++)
    {
        (*substring)->bytes[i] = (*text)->bytes[i + startIndexInBytes];
    }
    
    (*substring)->bytes[(*substring)->amountOfBytes - 1] = '\0';
    
    /*
    if (maxLength == (*substring)->amountOfBytes)
    {
        (*substring)->bytes[(*substring)->amountOfBytes - 1] = '\0';
    }
    else
    {
        (*substring)->bytes[(*substring)->amountOfBytes - 1] = '\0';
    }
    */
}


void
explodeDynamicText(struct dynamicText** text, char* separator, struct listForDynamicText** list, char* filename, int lineNumber)
{
    int lengthOfText = getLengthFromDynamicText(text, filename, lineNumber);
    int lengthOfSeparator = customStrlen(separator);
    
    if (0 == lengthOfText)
    {
        appendMessageToErrorLog("Text is empty!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (0 == lengthOfSeparator)
    {
        appendMessageToErrorLog("Separator is empty!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    int offset = 0;
    int bufferCounter = 0;

    struct dynamicText* var1 = allocateDynamicText(filename, lineNumber);
    
    if ((*var1).amountOfBytes < (*text)->amountOfBytes)
    {
        resizeDynamicText(&var1, (*text)->amountOfBytes, filename, lineNumber);
    }
    
    int delay = 0;

    for (int i = offset; i < lengthOfText; i++)
    {
        if (delay > 0)
        {
            delay--;

            if ((i + 1) == lengthOfText)
            {
                pushElementInListForDynamicText(list, "", filename, lineNumber);
                break;
            }

            continue;
        }
    
        if ((*text)->bytes[i] != separator[0])
        {
            (*var1).bytes[bufferCounter] = (*text)->bytes[i];
            bufferCounter++;
            
            continue;
        }

        int isValid = 1;
        
        for (int k = 0; k < lengthOfSeparator; k++)
        {
            if ((i + k) >= lengthOfText)
            {
                // @TODO: Do we need this assertion?
                // isValid = 0;
                
                break;
            }
            
            if ((*text)->bytes[i + k] != separator[k])
            {
                isValid = 0;
            }
        }

        if (isValid)
        {
            pushElementInListForDynamicText(list, (*var1).bytes, filename, lineNumber);
            
            bufferCounter = 0;
            assignDynamicText(&var1, "", filename, lineNumber);
            
            if ((i + 1) == lengthOfText)
            {
                pushElementInListForDynamicText(list, "", filename, lineNumber);
                break;
            }
            
            delay += (lengthOfSeparator - 1);
            
            continue;
        }
        
        (*var1).bytes[bufferCounter] = (*text)->bytes[i];
        bufferCounter++;
    }
    
    if (getLengthFromDynamicText(&var1, filename, lineNumber) > 0)
    {
        pushElementInListForDynamicText(list, (*var1).bytes, filename, lineNumber);
        assignDynamicText(&var1, "", filename, lineNumber);
    }
    
    freeDynamicText(&var1, __FILE__, __LINE__);
    var1 = NULL;
}


void
implodeListForDynamicText(struct listForDynamicText** list, struct dynamicText** text, char* textForInsert, char* filename, int lineNumber)
{
    if (NULL == list)
    {
        appendMessageToErrorLog("List variable is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (NULL == (*list))
    {
        appendMessageToErrorLog("List pointer is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (NULL == text)
    {
        appendMessageToErrorLog("Text variable is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (NULL == (*text))
    {
        appendMessageToErrorLog("Text pointer is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }
    
    struct listForDynamicText* bufferList = *list;

    int counter = 1;
    while (NULL != bufferList)
    {
        struct dynamicText* element = (*bufferList).item;
        
        appendDynamicText(text, getBytesPointerFromDynamicText(&element), filename, lineNumber);
        
        if (NULL != (*bufferList).next)
        {
            appendDynamicText(text, textForInsert, filename, lineNumber);
        }
        
        bufferList = (*bufferList).next;
        counter++;
    }
}


void
stripTagsInDynamicText(struct dynamicText** element, char* filename, int lineNumber)
{
    struct dynamicText* newText = allocateDynamicText(filename, lineNumber);
    
    if ((*newText).amountOfBytes < (*element)->amountOfBytes)
    {
        resizeDynamicText(&newText, (*element)->amountOfBytes, filename, lineNumber);
    }
    
    int i = 0;
    int length = customStrlen((*element)->bytes); 
    for (i = 0; i <= (length - 1); i++)
    {
        if ('<' == (*element)->bytes[i])
        {
            (*newText).bytes[i] = ' ';
        }
        else if ('>' == (*element)->bytes[i])
        {
            (*newText).bytes[i] = ' ';
        }
        else
        {
            (*newText).bytes[i] = (*element)->bytes[i];
        }
    }
    
    (*newText).bytes[i] = '\0';
    
    // @TODO: This is inefficient. How to handle it better?
    assignDynamicText(element, (*newText).bytes, filename, lineNumber);
    freeDynamicText(&newText, filename, lineNumber);
    newText = NULL;
}


void
replaceDynamicText(struct dynamicText** text, char* search, char* replace, char* filename, int lineNumber)
{
    if (NULL == text)
    {
        appendMessageToErrorLog("Variable for text is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }
    
    if (NULL == (*text))
    {
        appendMessageToErrorLog("Pointer for text is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }
    
    int lengthOfText = getLengthFromDynamicText(text, filename, lineNumber);
    
    if (0 == lengthOfText)
    {
        appendMessageToErrorLog("Text is empty!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (NULL == search)
    {
        appendMessageToErrorLog("Variable for search is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    int lengthOfSearch = customStrlen(search);
    
    if (0 == lengthOfSearch)
    {
        appendMessageToErrorLog("Search is empty!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    int lengthOfReplace = customStrlen(replace);
    int bufferCounter = 0;

    struct dynamicText* var1 = allocateDynamicText(filename, lineNumber);
    
    if ((*var1).amountOfBytes < (*text)->amountOfBytes)
    {
        resizeDynamicText(&var1, (*text)->amountOfBytes, filename, lineNumber);
    }
    
    int delay = 0;

    for (int i = 0; i < lengthOfText; i++)
    {
        if (delay > 0)
        {
            delay--;

            continue;
        }
    
        if ((*text)->bytes[i] != search[0])
        {
            (*var1).bytes[bufferCounter] = (*text)->bytes[i];
            bufferCounter++;
            
            continue;
        }

        int isValid = 1;
        
        for (int k = 0; k < lengthOfSearch; k++)
        {
            if ((i + k) >= lengthOfText)
            {
                isValid = 0;
                break;
            }
            
            if ((*text)->bytes[i + k] != search[k])
            {
                isValid = 0;
            }
        }

        if (isValid)
        {
            appendDynamicText(&var1, replace, filename, lineNumber);
            bufferCounter += lengthOfReplace;

            int newLength = getLengthFromDynamicText(&var1, filename, lineNumber) + lengthOfReplace;
            newLength *= 2;
            
            if (newLength > (*var1).amountOfBytes)
            {
                resizeDynamicText(&var1, newLength, filename, lineNumber);
            }
            
            if ((i + 1) == lengthOfText)
            {
                break;
            }
            
            delay += (lengthOfSearch - 1);
            
            continue;
        }
        
        (*var1).bytes[bufferCounter] = (*text)->bytes[i];
        bufferCounter++;
    }

    assignDynamicText(text, (*var1).bytes, filename, lineNumber);

    freeDynamicText(&var1, __FILE__, __LINE__);
    var1 = NULL;
}


int
convertTextIntoInteger(char* text, char* filename, int lineNumber)
{
    if (NULL == text)
    {
        appendMessageToErrorLog("Variable for text is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    return customStrtol(text, (char**) NULL, 10);
}


int
isExactTextMatch(char* text1, char* text2, char* filename, int lineNumber)
{
    if (NULL == text1)
    {
        appendMessageToErrorLog("Variable text1 is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (NULL == text2)
    {
        appendMessageToErrorLog("Variable text2 is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    int lengthOfText1 = customStrlen(text1);
    int lengthOfText2 = customStrlen(text2);

    if (lengthOfText1 != lengthOfText2)
    {
        return 0;
    }

    int maximumLength = lengthOfText1;

    if (lengthOfText2 < maximumLength)
    {
        maximumLength = lengthOfText2;
    }

    if (0 == customStrncmp(text1, text2, maximumLength))
    {
        return 1;
    }
    
    return 0;
}


int
startsWith(const char *haystack, const char *needle, char* filename, int lineNumber)
{
    // @TODO: Do not use negation here!
    if ((!haystack) || (!needle))
    {
        return 0;
    }
    
    int lengthOfHaystack = customStrlen(haystack);
    int lengthOfNeedle = customStrlen(needle);

    if (lengthOfHaystack < lengthOfNeedle)
    {
        return 0;
    }

    return (0 == customMemcmp(haystack, needle, lengthOfNeedle));
}


int
endsWith(const char *haystack, const char *needle, char* filename, int lineNumber)
{
    // @TODO: Do not use negation here!
    if ((!haystack) || (!needle))
    {
        return 0;
    }
    
    int lengthOfHaystack = customStrlen(haystack);
    int lengthOfNeedle = customStrlen(needle);
    
    if (lengthOfNeedle > lengthOfHaystack)
    {
        return 0;
    }
    
    return (0 == customStrncmp(haystack + lengthOfHaystack - lengthOfNeedle, needle, lengthOfNeedle));
}


void
toLower(struct dynamicText** text, char* filename, int lineNumber)
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
        {.from="A", .to="a"},
        {.from="B", .to="b"},
        {.from="C", .to="c"},
        {.from="D", .to="d"},
        {.from="E", .to="e"},
        {.from="F", .to="f"},
        {.from="G", .to="g"},
        {.from="H", .to="h"},
        {.from="I", .to="i"},
        {.from="J", .to="j"},
        {.from="K", .to="k"},
        {.from="L", .to="l"},
        {.from="M", .to="m"},
        {.from="N", .to="n"},
        {.from="O", .to="o"},
        {.from="P", .to="p"},
        {.from="Q", .to="q"},
        {.from="R", .to="r"},
        {.from="S", .to="s"},
        {.from="T", .to="t"},
        {.from="U", .to="u"},
        {.from="V", .to="v"},
        {.from="W", .to="w"},
        {.from="X", .to="x"},
        {.from="Y", .to="y"},
        {.from="Z", .to="z"},
        {.from="Ä", .to="ä"},
        {.from="Ö", .to="ö"},
        {.from="Ü", .to="ü"},
        {.from="ẞ", .to="ß"},
    };

    int amountOfElements = sizeof(mapping) / sizeof(mapping[0]);
    for (int i = 0; i < amountOfElements; i++)
    {
        replaceDynamicText(text, mapping[i].from, mapping[i].to, filename, lineNumber);
    }
}

