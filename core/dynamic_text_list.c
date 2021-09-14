
struct listForDynamicText {
    struct dynamicText* item;
    struct listForDynamicText* next;
};


struct listForDynamicText*
newListForDynamicText(char* filename, int lineNumber)
{
    return NULL;
}


int
isListEmptyForDynamicText(struct listForDynamicText** list, char* filename, int lineNumber)
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


void
pushElementInListForDynamicText(struct listForDynamicText** list, char* text, char* filename, int lineNumber)
{
    if (NULL == list)
    {
        appendMessageToErrorLog("List variable is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }
    
    if (NULL == text)
    {
        appendMessageToErrorLog("Text variable is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }
    
    if (NULL == (*list))
    {
        struct listForDynamicText* listElement = customCalloc(1, sizeof(struct listForDynamicText));
        
        if (NULL == listElement)
        {
            appendMessageToErrorLog("NULL pointer from calloc() on empty list()!", __func__, filename, lineNumber);
            customExit(EXIT_FAILURE);
        }
        
        (*listElement).item = allocateDynamicText(filename, lineNumber);
        (*listElement).next = NULL;
        
        assignDynamicText(&(*listElement).item, text, filename, lineNumber);
        
        *list = listElement; // @TODO: Unnötiger Umweg über eine weitere Variable?
        
        return;
    }

    struct listForDynamicText* bufferList = *list;

    while (NULL != (*bufferList).next)
    {
        bufferList = (*bufferList).next;
    }

    struct listForDynamicText* listElement = customCalloc(1, sizeof(struct listForDynamicText));
    
    if (NULL == listElement)
    {
        appendMessageToErrorLog("NULL pointer from calloc() on last empty element!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }
    
    (*listElement).item = allocateDynamicText(filename, lineNumber);
    (*listElement).next = NULL;
    
    assignDynamicText(&(*listElement).item, text, filename, lineNumber);
    
    (*bufferList).next = listElement;
}


/*
void
printListForDynamicText(struct listForDynamicText** list, char* filename, int lineNumber)
{
    if (NULL == list)
    {
        appendMessageToErrorLog("List variable is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (NULL == *list)
    {
        printf("List is empty!\n");
        
        return;
    }
    
    struct listForDynamicText* bufferList = *list;

    int counter = 1;
    while (NULL != bufferList)
    {
        struct dynamicText* element = (*bufferList).item;
        printf("List-Element #%i: \"%s\"\n", counter, (*element).bytes);
        bufferList = (*bufferList).next;
        counter++;
    }
}
*/


void
freeListForDynamicText(struct listForDynamicText** list, char* filename, int lineNumber)
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
    
    struct listForDynamicText* bufferList = *list;

    while (NULL != bufferList)
    {
        struct listForDynamicText* element = bufferList;
        freeDynamicText(&(*element).item, filename, lineNumber);
        (*element).item = NULL;
        
        bufferList = (*bufferList).next;
        
        customFree(element, sizeof(struct listForDynamicText));
        element = NULL;
    }
    
    *list = NULL;
}


int
countElementsInListForDynamicText(struct listForDynamicText** list, char* filename, int lineNumber)
{
    if (NULL == list)
    {
        appendMessageToErrorLog("List variable is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (NULL == *list)
    {
        return 0;
    }
    
    struct listForDynamicText* bufferList = *list;

    int counter = 0;
    while (NULL != bufferList)
    {
        bufferList = (*bufferList).next;
        counter++;
    }
    
    return counter;
}


struct dynamicText*
getElementByIndexFromListForDynamicText(struct listForDynamicText** list, int index, char* filename, int lineNumber)
{
    if (NULL == list)
    {
        appendMessageToErrorLog("List variable is NULL!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (NULL == *list)
    {
        appendMessageToErrorLog("List is empty!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (index < 0)
    {
        appendMessageToErrorLog("Index less than 0!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    if (index >= countElementsInListForDynamicText(list, filename, lineNumber))
    {
        appendMessageToErrorLog("Index greater than amount of elements!", __func__, filename, lineNumber);
        customExit(EXIT_FAILURE);
    }

    struct listForDynamicText* bufferList = *list;
    
    int counter = 0;
    
    do
    {
        if (counter == index)
        {
            break;
        }
        
        bufferList = (*bufferList).next;
        counter++;
    }
    while (NULL != bufferList);

    return (*bufferList).item;
}
