#ifndef MEMORYREADER_H
#define MEMORYREADER_H

#include "client.h"

class MemoryReader
{
public:
    MemoryReader();
    Client c;
    int ReadInt(int Address);
    void PeekPause();
    int PeekRead(int Address);
    void PeekUnpause();
};

#endif // MEMORYREADER_H
