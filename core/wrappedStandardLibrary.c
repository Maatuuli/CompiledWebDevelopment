
int globaleAmountOfAllocations = 0;
int globaleAmountOfReallocations = 0;
int globaleAmountOfFrees = 0;
int globalePeakOfAllocatedMemoryInBytes = 0;
int globaleAmountOfAllocatedMemoryInBytes = 0;


void
customExit(int status)
{
    exit(status);
}


void
appendMessageToErrorLog(const char* message, const char* functionName, char* filename, int lineNumber)
{
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
    if (0 == strftime(textForCurrentTimestamp, 256, "%Y-%m-%d %H:%M:%S", &localTimeObject))
    {
        printf("[ERROR] Error during writing into text with strftime and result is 0!");
        customExit(EXIT_FAILURE);
    }

    FILE* pointerForTextFile = fopen("./error.log", "a");

    if (NULL == pointerForTextFile)
    {
        printf("[ERROR] Error log does not work or exist!");
        customExit(EXIT_FAILURE);
    }

    fprintf(pointerForTextFile, "%s [ERROR] %s\n", textForCurrentTimestamp, message);
    fprintf(pointerForTextFile, "%s [ERROR] In function \"%s\".\n", textForCurrentTimestamp, functionName);
    fprintf(pointerForTextFile, "%s [ERROR] Starting point was file \"%s\" on line %i!\n", textForCurrentTimestamp, filename, lineNumber);
    
    if (0 != fclose(pointerForTextFile))
    {
        printf("[ERROR] Error during closing of the error logging file!");
        customExit(EXIT_FAILURE);
    }
}


size_t
customStrlen(const char* str)
{
    return strlen(str);
}


char*
customStrncpy(char* restrict destination, const char* restrict source, size_t num)
{
    return strncpy(destination, source, num);
}


char*
customStrncat(char* restrict destination, const char* restrict source, size_t num)
{
    return strncat(destination, source, num);
}


void
customFree(void *pointer, size_t size)
{
    globaleAmountOfAllocatedMemoryInBytes -= size;
    
    free(pointer);
    
    globaleAmountOfFrees++;
}


char*
customGetenv(char const* name)
{
    return getenv(name);
}


void*
customMemset(void *str, int c, size_t n)
{
    return memset(str, c, n);
}


int
customMemcmp(const void* ptr1, const void* ptr2, size_t num)
{
    return memcmp(ptr1, ptr2, num);
}


int
customStrncmp(const char* str1, const char* str2, size_t num)
{
    return strncmp(str1, str2, num);
}


long int
customStrtol(const char* str, char** endptr, int base)
{
    return strtol(str, endptr, base);
}


char*
customFgets(char* str, int n, FILE* stream)
{
    return fgets(str, n, stream);
}
