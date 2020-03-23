#include "readZIP.h"
#include <list>
void readZIP::openFile(string filename)
{
    file.open(filename, ios::binary);

    if (file.fail())
    {
        cout << "Could not open ZIP file." << endl;
        return;
    }

}

void readZIP::readFile()
{
    int cdirpos = 0;
    file.seekg(0, ios_base::end);
    int end = file.tellg();
    int pos = end - 22;
    file.seekg(pos);

    file.read((char*)&ECDir.EOCDBuffer, 22);

    ECDir.unpack();
    ECDir.comment = new char[ECDir.commentSize + 1];
    file.read(ECDir.comment, ECDir.commentSize);
    ECDir.comment[ECDir.commentSize] = '\0';

    ECDir.printHeader();

    //file.seekg(ECDir.offsetCentralDir);
    cdirpos = ECDir.offsetCentralDir;
    for (int i = 0; i < ECDir.numRecords; i++)
    {
        FileNode *node = new FileNode;

        file.seekg(cdirpos);
        file.read((char*)&CDir.centralDirBuffer, 46);

        CDir.unpack();
        CDir.filename = new char[CDir.fileName_Size + 1];
        file.read(CDir.filename, CDir.fileName_Size);
        CDir.filename[CDir.fileName_Size] = '\0';

        CDir.extraField = new char[CDir.extra_Size + 1];
        file.read(CDir.extraField, CDir.extra_Size);
        CDir.extraField[CDir.extra_Size] = '\0';

        CDir.fileComment = new char[CDir.comment_Size + 1];
        file.read(CDir.fileComment, CDir.comment_Size);
        CDir.fileComment[CDir.comment_Size] = '\0';

        CDir.printHeader();

        //Add Atributes to FileNode
        node->name = CDir.filename;
        node->time = CDir.timeMod;
        node->date = CDir.dateMod;
        node->compMethod = CDir.compression;
        node->uncompressedSize = CDir.uncompSize;
        node->compressedSize = CDir.compSize;
        node->CRC32 = CDir.CRC32;
        node->offset = CDir.offsetLocalFileHeader;
        fl.push_back(*node);

        cdirpos = file.tellg();

        file.seekg(CDir.offsetLocalFileHeader);
        file.read((char*)&LFH.LFHbuffer, 30);
        LFH.unpack();
        LFH.filename = new char[LFH.filenameSize + 1];
        file.read(LFH.filename, LFH.filenameSize);
        LFH.filename[LFH.filenameSize] = '\0';

        LFH.extra = new char[LFH.extraSize + 1];
        file.read(LFH.extra, LFH.extraSize);
        LFH.extra[LFH.extraSize] = '\0';

        int readData = LFH.compSize - LFH.extraSize;
        LFH.data = new char[readData + 1];
        file.read(LFH.data, readData);
        LFH.data[readData] = '\0';
        cout << "========= Local File Header " << i + 1 << " =========" << endl;
        LFH.printHeader();
    }

    file.close();
}
