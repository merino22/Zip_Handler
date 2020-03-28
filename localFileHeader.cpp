#include "localFileHeader.h"
#include <fstream>
void localFileHeader::unpack()
{
    char* buff = LFHbuffer;

    memcpy(signature, buff, 4);
    memcpy(&verExtract, buff += 4, 2);
    memcpy(&bitFlag, buff += 2, 2);
    memcpy(&compMethod, buff += 2, 2);
    memcpy(&timeModif, buff += 2, 2);
    memcpy(&dateModif, buff += 2, 2);
    memcpy(&CRC32, buff += 2, 4);
    memcpy(&compSize, buff += 4, 4);
    memcpy(&uncompSize, buff += 4, 4);
    memcpy(&filenameSize, buff += 4, 2);
    memcpy(&extraSize, buff += 2, 2);
}

void localFileHeader::printHeader()
{
    char sig[4];
    memcpy(sig, signature, 4);

    cout << "Signature: " << sig[0] << sig[1] << (int)sig[2] << (int)sig[3] << endl;
    cout << "Version Extract: " << verExtract << endl;
    cout << "Bit Flag: " << bitFlag << endl;
    cout << "Compression Method: " << compMethod << endl;
    cout << "Time Modified: " << timeModif << endl;
    cout << "Date Modified: " << dateModif << endl;
    cout << "CRC-32: " << CRC32 << endl;
    cout << "Compressed Size: " << compSize << endl;
    cout << "Uncompressed Size: " << uncompSize << endl;
    cout << "Filename Size: " << filenameSize << endl;
    cout << "Extra Size: " << extraSize << endl;
    cout << "Filename: " << filename << endl;
    cout << "Extra Field: " << extra << endl;
    cout << "File Compressed Data: " << data << endl;
}

void localFileHeader::infoToFile()
{
    char sig[4];
    memcpy(sig, signature, 4);

    fstream file;
    file.open("/home/merino/Aaron/fileInfo.txt", ios::out | ios::app);
    if(file.fail())
    {
        cout << "Could not open Info file" << endl;
        return;
    }
    file << "===============| Local File Header |===============";
    file << "\nSignature: " << sig[0] << sig[1] << (int)sig[2] << (int)sig[3];
    file << "\nVersion Extract: " << verExtract;
    file << "\nBit Flag: " << bitFlag;
    file << "\nCompression Method: " << compMethod;
    file << "\nTime Modified: " << timeModif;
    file << "\nDate Modified: " << dateModif;;
    file << "\nCRC-32: " << CRC32;
    file << "\nCompressed Size: " << compSize;
    file << "\nUncompressed Size: " << uncompSize;
    file << "\nFilename Size: " << filenameSize;
    file << "\nExtra Size: " << extraSize;
    file << "\nFilename: " << filename;
    file << "\nExtra Field: " << extra;
    file << "\nCompressed Data: " << data;
    file << "\n\n";
}
