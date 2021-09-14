struct associativeDynamicText {
    struct dynamicText* internalKey;
    struct dynamicText* internalValue;
};


struct associativeDynamicText*
allocateAssociativeDynamicTextByKey(char* key, char* filename, int lineNumber)
{
    if (NULL == key)
    {
        appendMessageToErrorLog("Variable for key is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (0 == customStrlen(key))
    {
        appendMessageToErrorLog("Text variable for key is empty!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    struct associativeDynamicText* element = customCalloc(1, sizeof(struct associativeDynamicText));
    
    if (NULL == element)
    {
        appendMessageToErrorLog("NULL pointer as return value from function calloc()!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    struct dynamicText* newText = allocateDynamicText(filename, lineNumber);
    assignDynamicText(&newText, key, filename, lineNumber);
    (*element).internalKey = newText;
    
    (*element).internalValue = allocateDynamicText(filename, lineNumber);
    
    return element;
}


void
setValueInAssociativeDynamicText(struct associativeDynamicText** element, char* text, char* filename, int lineNumber)
{
    if (NULL == element)
    {
        appendMessageToErrorLog("Variable is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (NULL == (*element))
    {
        appendMessageToErrorLog("Variable for pointer is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }
    
    assignDynamicText(&((*element)->internalValue), text, filename, lineNumber);
}


void
freeAssociativeDynamicText(struct associativeDynamicText** element, char* filename, int lineNumber)
{
    if (NULL == element)
    {
        appendMessageToErrorLog("Variable is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (NULL == (*element))
    {
        appendMessageToErrorLog("Double free on associativeDynamicText element!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }
    
    freeDynamicText(&(*element)->internalKey, filename, lineNumber);
    freeDynamicText(&(*element)->internalValue, filename, lineNumber);

    (*element)->internalKey = NULL;
    (*element)->internalValue = NULL;
    
    customFree(*element, sizeof(struct associativeDynamicText));
    *element = NULL;
}

