
struct dynamicText {
    int amountOfBytes;
    char* bytes;
};


int
getMinimumAmountOfBytesForAllocation(char* filename, int lineNumber)
{
    return 64;
}


void
freeDynamicText(struct dynamicText** element, char* filename, int lineNumber)
{
    if (NULL == element)
    {
        appendMessageToErrorLog("Variable is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }
    
    if (NULL == (*element))
    {
        appendMessageToErrorLog("Double free on dynamic text element!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }
    
    if (NULL != (*element)->bytes)
    {
        /* Clear complete memory before freeing. */
        customMemset((*element)->bytes, '\0', (*element)->amountOfBytes);

        customFree((*element)->bytes, (*element)->amountOfBytes);
        (*element)->bytes = NULL;
    }
    
    (*element)->amountOfBytes = 0;
 
    customFree(*element, sizeof(struct dynamicText));
    *element = NULL;
}


void
resizeDynamicText(struct dynamicText** element, int newSize, char* filename, int lineNumber)
{
    if (NULL == element)
    {
        appendMessageToErrorLog("Variable is NULL and not able to resize!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }
    
    if (NULL == (*element))
    {
        appendMessageToErrorLog("Pointer for dynamic text element is NULL and not able to resize!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (newSize < (*element)->amountOfBytes)
    {
        appendMessageToErrorLog("New size is smaller than previous size in realloc()!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (newSize == (*element)->amountOfBytes)
    {
        appendMessageToErrorLog("New size is equal to previous size in realloc()!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    (*element)->bytes = customRealloc((*element)->bytes, newSize * sizeof(char), (*element)->amountOfBytes);
    
    if (NULL == (*element)->bytes)
    {
        appendMessageToErrorLog("NULL pointer was delivered from realloc()!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    /* Initialise additional bytes from new pointer with termination sign. */
    for (int i = ((*element)->amountOfBytes - 1); i < newSize; i++)
    {
        (*element)->bytes[i] = '\0';
    }        
    
    (*element)->amountOfBytes = newSize;

    /* Terminate last index of the allocated string at the end - always. */
    (*element)->bytes[(*element)->amountOfBytes - 1] = '\0';
}


struct dynamicText*
allocateDynamicText(char* filename, int lineNumber)
{
    struct dynamicText* element = customCalloc(1, sizeof(struct dynamicText));
    
    if (NULL == element)
    {
        appendMessageToErrorLog("NULL pointer as return value from function calloc()!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    (*element).amountOfBytes = getMinimumAmountOfBytesForAllocation(filename, lineNumber);

    (*element).bytes = customCalloc((*element).amountOfBytes, sizeof(char));
    
    /* Clearing allocated memory again for safety. */
    customMemset((*element).bytes, '\0', (*element).amountOfBytes);
    (*element).bytes[0] = '\0';
    
    return element;
}


void
appendDynamicText(struct dynamicText** element, char* text, char* filename, int lineNumber)
{
    if (NULL == element)
    {
        appendMessageToErrorLog("Dynamic text element is NULL and not able to append text!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }
    
    if (NULL == (*element))
    {
        appendMessageToErrorLog("Dynamic text element is NULL and not able to append text!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (NULL == text)
    {
        appendMessageToErrorLog("Text variable is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }
    
    int maxLengthForCopy = customStrlen((*element)->bytes);
    maxLengthForCopy += customStrlen(text);
    maxLengthForCopy += 1;

    if (maxLengthForCopy > (*element)->amountOfBytes)
    {
        /* Increase amount of needed memory by an extra amount, to avoid byte by byte reallocations. */
        maxLengthForCopy += getMinimumAmountOfBytesForAllocation(filename, lineNumber);

        resizeDynamicText(element, maxLengthForCopy, filename, lineNumber);
    }

    customStrncat((*element)->bytes, text, (*element)->amountOfBytes - customStrlen((*element)->bytes));

    /* Add additional termination signs. */
    // @TODO: Enabled these outcomment lines!
    // (*element)->bytes[customStrlen((*element)->bytes) + customStrlen(text)] = '\0';
    // (*element)->bytes[(*element)->amountOfBytes - 1] = '\0';
}


void
assignDynamicText(struct dynamicText** element, char* text, char* filename, int lineNumber)
{
    if (NULL == element)
    {
        appendMessageToErrorLog("Variable is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (NULL == (*element))
    {
        appendMessageToErrorLog("Dynamic text element is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (NULL == text)
    {
        appendMessageToErrorLog("Text variable is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }
    
    /* Clearing allocated memory for safety for next usage. */
    customMemset((*element)->bytes, '\0', (*element)->amountOfBytes);

    int maxLengthForCopy = customStrlen(text);
    maxLengthForCopy += 1;

    if (maxLengthForCopy > (*element)->amountOfBytes)
    {
        /* Increase amount of needed memory by an extra amount, to avoid byte by byte reallocations. */
        maxLengthForCopy += getMinimumAmountOfBytesForAllocation(filename, lineNumber);
        
        resizeDynamicText(element, maxLengthForCopy, filename, lineNumber);
    }
    
    /* Again clearing allocated memory for safety for next usage. */
    customMemset((*element)->bytes, '\0', (*element)->amountOfBytes);
    
    customStrncpy((*element)->bytes, text, (*element)->amountOfBytes - 1);
    
    /* Add additional termination signs. */
    // @TODO: Enabled these outcomment lines!
    // (*element)->bytes[customStrlen(text)] = '\0';
    // (*element)->bytes[(*element)->amountOfBytes - 1] = '\0';
}


size_t
getLengthFromDynamicText(struct dynamicText** element, char* filename, int lineNumber)
{
    if (NULL == element)
    {
        appendMessageToErrorLog("Variable is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (NULL == (*element))
    {
        appendMessageToErrorLog("Pointer for dynamic text element is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    return customStrlen((*element)->bytes);
}


char*
getBytesPointerFromDynamicText(struct dynamicText** element)
{
    return (*element)->bytes;
}

