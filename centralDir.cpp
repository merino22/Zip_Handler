#include "centralDir.h"
#include <fstream>
void central_Dir::unpack()
{
    char* buff = centralDirBuffer;

    memcpy(signature, buff, 4);
    memcpy(&version, buff += 4, 2);
    memcpy(&verExtract, buff += 2, 2);
    memcpy(&bitFlag, buff += 2, 2);
    memcpy(&compression, buff += 2, 2);
    memcpy(&timeMod, buff += 2, 2);
    memcpy(&dateMod, buff += 2, 2);
    memcpy(&CRC32, buff += 2, 4);
    memcpy(&compSize, buff += 4, 4);
    memcpy(&uncompSize, buff += 4, 4);
    memcpy(&fileName_Size, buff += 4, 2);
    memcpy(&extra_Size, buff += 2, 2);
    memcpy(&comment_Size, buff += 2, 2);
    memcpy(&diskNumber, buff += 2, 2);
    memcpy(interFileAtri, buff += 2, 2);
    memcpy(extFileAtri, buff += 2, 4);
    memcpy(&offsetLocalFileHeader, buff += 4, 4);
}

void central_Dir::printHeader()
{
    char sig[4];
    memcpy(sig, signature, 4);

    cout << "========= Central Directory =========" << endl;
    cout << "Signature: " << sig[0] << sig[1] << (int)sig[2] << (int)sig[3] << endl;
    cout << "Version: " << version << endl;
    cout << "Version Extract: " << verExtract << endl;
    cout << "Bit Flag: " << bitFlag << endl;
    cout << "Compression: " << compression << endl;
    cout << "Time last Modified: " << timeMod << endl;
    cout << "Date last Modified: " << dateMod << endl;
    cout << "CRC-32: " << CRC32 << endl;
    cout << "Compressed Size: " << compSize << endl;
    cout << "Uncompressed Size: " << uncompSize << endl;
    cout << "Filename Size: " << fileName_Size << endl;
    cout << "Extra Field Size: " << extra_Size << endl;
    cout << "Comment Size: " << comment_Size << endl;
    cout << "Disk Number: " << diskNumber << endl;
    cout << "Internal File Attributes: " << interFileAtri << endl;
    cout << "External File Attributes: " << extFileAtri << endl;
    cout << "Local File Header Offset: " << offsetLocalFileHeader << endl;
    cout << "Filename: " << filename << endl;
    cout << "Extra Field: " << extraField << endl;
    cout << "File Comment: " << fileComment << endl;
}

void central_Dir::infoToFile()
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

    file << "===============| Central Directory |===============";
    file << "\nSignature: " << sig[0] << sig[1] << (int)sig[2] << (int)sig[3];
    file << "\nVersion: " << version;
    file << "\nVersion Extract: " << verExtract;
    file << "\nBit Flag: " << bitFlag;
    file << "\nCompression: " << compression;
    file << "\nTime last Modified: " << timeMod;
    file << "\nDate last Modified: " << dateMod;
    file << "\nCRC-32: " << CRC32;
    file << "\nCompressed Size: " << compSize;
    file << "\nUncompressed Size: " << uncompSize;
    file << "\nFilename Size: " << fileName_Size;
    file << "\nExtra Field Size: " << extra_Size;
    file << "\nComment Size: " << comment_Size;
    file << "\nDisk Number: " << diskNumber;
    file << "\nInternal File Attributes: " << interFileAtri;
    file << "\nExternal File Attributes: " << extFileAtri;
    file << "\nLocal File Header Offset: " << offsetLocalFileHeader;
    file << "\nFilename: " << filename;
    file << "\nExtra Field: " << extraField;
    file << "\nFile Comment: " << fileComment;
    file << "\n\n";
    file.close();

}
