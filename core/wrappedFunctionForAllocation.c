
void*
customCalloc(size_t n, size_t size)
{
    globaleAmountOfAllocations++;
    globaleAmountOfAllocatedMemoryInBytes += n * size;

    if (globaleAmountOfAllocatedMemoryInBytes > globalePeakOfAllocatedMemoryInBytes)
    {
        globalePeakOfAllocatedMemoryInBytes = globaleAmountOfAllocatedMemoryInBytes;
    }
    
    return calloc(n, size);
}

