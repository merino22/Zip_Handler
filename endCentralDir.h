#ifndef ENDCENTRALDIR_H
#define ENDCENTRALDIR_H

#pragma warning ( disable:4996 );

#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

class end_Central_Dir
{
public:
    char EOCDBuffer[22];

    char signature[4];
    uint16_t diskNumber;
    uint16_t diskStartCentralDir;
    uint16_t numRecords;
    uint16_t totalNumRecords;
    int sizeCentralDir;
    int offsetCentralDir;
    uint16_t commentSize;
    char* comment;

    void unpack();
    void printHeader();
};//22 bytes

#endif // ENDCENTRALDIR_H
