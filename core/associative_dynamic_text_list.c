
struct listForAssociativeDynamicText {
    struct associativeDynamicText* item;
    struct listForAssociativeDynamicText *next;
};


struct listForAssociativeDynamicText*
newListForAssociativeDynamicText(char* filename, int lineNumber)
{
    return NULL;
}


int
isListEmptyForAssociativeDynamicText(struct listForAssociativeDynamicText** list, char* filename, int lineNumber)
{
    if (NULL == list)
    {
        appendMessageToErrorLog("List variable is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (NULL == (*list))
    {
        return 1;
    }
    
    return 0;
}


int
checkIfKeyExistsInListForAssociativeDynamicText(struct listForAssociativeDynamicText** list, char* textForKey, char* filename, int lineNumber)
{
    if (NULL == list)
    {
        appendMessageToErrorLog("List variable is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (NULL == textForKey)
    {
        appendMessageToErrorLog("Pointer for key is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (0 == customStrlen(textForKey))
    {
        appendMessageToErrorLog("Key variable is empty!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }
    
    if (NULL == (*list))
    {
        return 0;
    }
    
    struct listForAssociativeDynamicText* bufferList = *list;

    int counter = 1;
    while (NULL != bufferList)
    {
        struct associativeDynamicText* element = (*bufferList).item;
        char* key = (*(*element).internalKey).bytes;
        
        if (isExactTextMatch(textForKey, key, filename, lineNumber))
        {
            return 1;
        }
        
        bufferList = (*bufferList).next;
        counter++;
    }
    
    return 0;
}


void
addElementByKeyInListForAssociativeDynamicText(struct listForAssociativeDynamicText** list, char* textForKey, char* textForValue, char* filename, int lineNumber)
{
    if (NULL == list)
    {
        appendMessageToErrorLog("List variable is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (NULL == textForKey)
    {
        appendMessageToErrorLog("Pointer for key is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (0 == customStrlen(textForKey))
    {
        appendMessageToErrorLog("Key variable is empty!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (NULL == textForValue)
    {
        appendMessageToErrorLog("Pointer for value is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (NULL == (*list))
    {
        struct listForAssociativeDynamicText* listElement = customCalloc(1, sizeof(struct listForAssociativeDynamicText));
        
        if (NULL == listElement)
        {
            appendMessageToErrorLog("NULL pointer from calloc() on empty list()!", __func__, filename, lineNumber);
            customExit(EXIT_FAILURE);
        }

        struct associativeDynamicText* item = allocateAssociativeDynamicTextByKey(textForKey, filename, lineNumber);
        
        setValueInAssociativeDynamicText(&item, textForValue, filename, lineNumber);

        (*listElement).item = item;
        (*listElement).next = NULL;
        
        *list = listElement; // @TODO: Unnötiger Umweg über eine weitere Variable?
        
        return;
    }

    if (1 == checkIfKeyExistsInListForAssociativeDynamicText(list, textForKey, filename, lineNumber))
    {
        appendMessageToErrorLog("Key exists and would not be unique in the list anymore!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }
    
    struct listForAssociativeDynamicText* bufferList = *list;

    while (NULL != (*bufferList).next)
    {
        bufferList = (*bufferList).next;
    }

    struct listForAssociativeDynamicText* listElement = customCalloc(1, sizeof(struct listForAssociativeDynamicText));
    
    if (NULL == listElement)
    {
        appendMessageToErrorLog("NULL pointer from calloc() on last empty element!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }
    
    struct associativeDynamicText* item = allocateAssociativeDynamicTextByKey(textForKey, filename, lineNumber);
    
    setValueInAssociativeDynamicText(&item, textForValue, filename, lineNumber);

    (*listElement).item = item;
    (*listElement).next = NULL;
    
    (*bufferList).next = listElement; // @TODO: Unnötiger Umweg über eine weitere Variable?
}


void
freeListForAssociativeDynamicText(struct listForAssociativeDynamicText** list, char* filename, int lineNumber)
{
    if (NULL == list)
    {
        appendMessageToErrorLog("List variable is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (NULL == (*list))
    {
        return;
    }
    
    struct listForAssociativeDynamicText* bufferList = *list;

    while (NULL != bufferList)
    {
        struct listForAssociativeDynamicText* element = bufferList;
        
        freeAssociativeDynamicText(&(*element).item, filename, lineNumber);
        (*element).item = NULL;
        
        bufferList = (*bufferList).next;
        
        customFree(element, sizeof(struct listForAssociativeDynamicText));
        element = NULL;
    }
    
    *list = NULL;
}


/*
void
printListForAssociativeDynamicText(struct listForAssociativeDynamicText** list, char* filename, int lineNumber)
{
    if (NULL == list)
    {
        appendMessageToErrorLog("List variable is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (NULL == (*list))
    {
        printf("List is empty!\n");
        
        return;
    }
    
    struct listForAssociativeDynamicText* bufferList = *list;

    int counter = 1;
    while (NULL != bufferList)
    {
        struct associativeDynamicText* element = (*bufferList).item;
        printf("Key #%i: %s\n", counter, (*(*element).internalKey).bytes);
        printf("Value #%i: %s\n", counter, (*(*element).internalValue).bytes);
        bufferList = (*bufferList).next;
        counter++;
    }
}
*/


struct associativeDynamicText*
getElementByKeyFromListForAssociativeDynamicText(struct listForAssociativeDynamicText **list, char* key, char* filename, int lineNumber)
{
    if (NULL == list)
    {
        appendMessageToErrorLog("List variable is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }
    
    if (NULL == (*list))
    {
        appendMessageToErrorLog("Pointer for list is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (NULL == key)
    {
        appendMessageToErrorLog("Key variable is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (0 == customStrlen(key))
    {
        appendMessageToErrorLog("Key variable is empty!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }
    
    struct listForAssociativeDynamicText *element = *list;

    while (NULL != element)
    {
        struct associativeDynamicText* item = (*element).item;
        struct dynamicText* buffer = (*item).internalKey; 
        char* keyFromElement = getBytesPointerFromDynamicText(&buffer);
        
        if (isExactTextMatch(keyFromElement, key, filename, lineNumber))
        {
            break;
        }
    
        element = (*element).next;
    }
    
    if (NULL == element)
    {
        appendMessageToErrorLog("Key does not exists in list!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }
    
    return (*element).item;
}

