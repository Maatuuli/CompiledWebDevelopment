
void*
customRealloc(void *ptr, size_t newSize, size_t oldSize)
{
    globaleAmountOfReallocations++;

    globaleAmountOfAllocatedMemoryInBytes -= oldSize;
    globaleAmountOfAllocatedMemoryInBytes += newSize;
    
    if (globaleAmountOfAllocatedMemoryInBytes > globalePeakOfAllocatedMemoryInBytes)
    {
        globalePeakOfAllocatedMemoryInBytes = globaleAmountOfAllocatedMemoryInBytes;
    }
    
    return NULL;
}

