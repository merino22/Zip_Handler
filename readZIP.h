#ifndef READZIP_H
#define READZIP_H

#include <fstream>
#include <string>
#include <iostream>
#include "endCentralDir.h"
#include "centralDir.h"
#include "localFileHeader.h"

using namespace std;

class readZIP
{
public:
	end_Central_Dir ECDir;
	central_Dir CDir;
	localFileHeader LFH;

	ifstream file;
	void openFile(string);
	void readFile();
};

#endif

