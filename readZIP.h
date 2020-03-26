#ifndef READZIP_H
#define READZIP_H

#include <fstream>
#include <string>
#include <iostream>
#include "endCentralDir.h"
#include "centralDir.h"
#include "localFileHeader.h"
#include <QString>
#include <list>
#include "FileNode.h"

using namespace std;

class readZIP
{
public:
    end_Central_Dir ECDir;
    central_Dir CDir;
    localFileHeader LFH;
    list<FileNode>fl;

    ifstream file;
    void openFile(string);
    void readFile();
    string setTimeDate();
};

#endif // READZIP_H
