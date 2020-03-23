#ifndef CENTRALDIR_H
#define CENTRALDIR_H

#include <inttypes.h>
#include <string.h>
#include <iostream>
#include <ctime>
#pragma warning( disable:4996 );

using namespace std;

class central_Dir
{
public:
	char centralDirBuffer[46];
	
	char signature[4];
	uint16_t version;
	uint16_t verExtract;
	uint16_t bitFlag;
	uint16_t compression;
	uint16_t timeMod;
	uint16_t dateMod;
	uint32_t CRC32;
	int compSize;
	int uncompSize;
	uint16_t fileName_Size;
	uint16_t extra_Size;
	uint16_t comment_Size;
	uint16_t diskNumber;
	char interFileAtri[2];
	char extFileAtri[4];
	uint32_t offsetLocalFileHeader;
	char* filename;
	char* extraField;
	char* fileComment;

	void unpack();
	void printHeader();
};

#endif
