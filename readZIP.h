#ifndef READZIP_H
#define READZIP_H

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include "endCentralDir.h"
#include "centralDir.h"
#include "localFileHeader.h"
#include <QString>
#include <list>
#include "FileNode.h"
#include "dataDescriptor.h"

using namespace std;

class readZIP
{
public:
    end_Central_Dir ECDir;
    central_Dir CDir;
    localFileHeader LFH;
    Descriptor desc;
    list<FileNode>fl;

    ifstream file;
    bool openFile(string);
    bool readFile();
    string setTimeDate();
    string setFilename();
    string setCRC();
};

#endif // READZIP_H
