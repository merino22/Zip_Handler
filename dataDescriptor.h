#ifndef DATADESCRIPTOR_H
#define DATADESCRIPTOR_H

#include <inttypes.h>
#include <string.h>
#include <iostream>

using namespace std;

class Descriptor
{
public:
    char descBuffer[12];

    uint32_t CRC32;
    uint32_t compSize;
    uint32_t uncompSize;

    void unpack();
    void printDescriptor();
};

#endif // DATADESCRIPTOR_H
