#include "endCentralDir.h"

void end_Central_Dir::unpack()
{
    char* buff = EOCDBuffer;

    memcpy(signature, buff, 4);
    memcpy(&diskNumber, buff += 4, 2);
    memcpy(&diskStartCentralDir, buff += 2, 2);
    memcpy(&numRecords, buff += 2, 2);
    memcpy(&totalNumRecords, buff += 2, 2);
    memcpy(&sizeCentralDir, buff += 2, 4);
    memcpy(&offsetCentralDir, buff += 4, 4);
    memcpy(&commentSize, buff += 4, 2);
}

void end_Central_Dir::printHeader()
{
    char sig[4];
    //sig[4] = '\0';
    memcpy(sig, signature, 4);

    cout << "========= End of Central Directory =========" << endl;
    cout << "Signature: " << sig[0] << sig[1] << (int)sig[2] << (int)sig[3] << endl;
    cout << "Disk Number: " << diskNumber << endl;
    cout << "Disk of Start Central Directory: " << diskStartCentralDir << endl;
    cout << "Number of Records: " << numRecords << endl;
    cout << "Total number of Records: " << numRecords << endl;
    cout << "Size of Central Dir: " << sizeCentralDir << endl;
    cout << "Offset of Central Dir: " << offsetCentralDir << endl;
    cout << "Comment Size: " << commentSize << endl;
    cout << "Comment: " << comment << endl;
}
