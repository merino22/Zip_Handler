#ifndef FILENODE_H
#define FILENODE_H

#include <inttypes.h>
#include<string>

using namespace std;

class FileNode
{
public:
    string name;
    string dateTime;
    uint16_t compMethod;
    int uncompressedSize;
    int compressedSize;
    string CRC32;
    int offset;
};

#endif // FILENODE_H
