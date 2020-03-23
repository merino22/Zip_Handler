#ifndef LOCALFILEHEADER_H
#define LOCALFILEHEADER_H

#include <inttypes.h>
#include <string.h>
#include <iostream>
	
using namespace std;

class localFileHeader
{
public:
	char LFHbuffer[30];

	char signature[4];
	uint16_t verExtract;
	uint16_t bitFlag;
	uint16_t compMethod;
	uint16_t timeModif;
	uint16_t dateModif;
	uint32_t CRC32;
	int compSize;
	int uncompSize;
	uint16_t filenameSize;
	uint16_t extraSize;
	char* filename;
	char* extra;
	char* data;
	void unpack();
	void printHeader();
};

#endif