
int globaleTestingFlagForNullAllocation = 0;

void*
customCalloc(size_t n, size_t size)
{
    globaleAmountOfAllocations++;
    globaleAmountOfAllocatedMemoryInBytes += n * size;

    if (globaleAmountOfAllocatedMemoryInBytes > globalePeakOfAllocatedMemoryInBytes)
    {
        globalePeakOfAllocatedMemoryInBytes = globaleAmountOfAllocatedMemoryInBytes;
    }

    if (1 == globaleTestingFlagForNullAllocation)
    {    
        return NULL;
    }
    
    return calloc(n, size);
}

