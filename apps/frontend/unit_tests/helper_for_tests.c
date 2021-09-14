
static void
abortTestWithErrorMessage(char* titleFromTest, const char* functionName, char* filename, int lineNumber)
{
    printf("[FAILED] %s\n", titleFromTest);
    printf("globaleAmountOfAllocations: %d\n", globaleAmountOfAllocations);
    printf("globaleAmountOfReallocations: %d\n", globaleAmountOfReallocations);
    printf("globaleAmountOfFrees: %d\n", globaleAmountOfFrees);
    printf("ABORTED in function \"%s\" in file: \"%s\" on line: %d!\n", functionName, filename, lineNumber);
    
    customExit(EXIT_FAILURE);
}

