#ifndef FILENODE_H
#define FILENODE_H

#include <inttypes.h>
#include<string>

using namespace std;

class FileNode
{
public:
    char* name;
    string dateTime;
    uint16_t compMethod;
    int uncompressedSize;
    int compressedSize;
    int CRC32;
    int offset;
};

#endif // FILENODE_H
