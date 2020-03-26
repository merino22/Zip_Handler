#include "readZIP.h"
#include <list>

#pragma warning ( disable:4996 )
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

    //Extract End of Central Directory
    file.read((char*)&ECDir.EOCDBuffer, 22);
    ECDir.unpack();
    ECDir.comment = new char[ECDir.commentSize + 1];
    file.read(ECDir.comment, ECDir.commentSize);
    ECDir.comment[ECDir.commentSize] = '\0';

    ECDir.printHeader();

    //Extract Central Directory Headers
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

        //Set Date & Time to DOS Format
        string dateTime = "";
        dateTime = setTimeDate();
        cout << "New Date: " << dateTime << endl;
        cdirpos = file.tellg();

        //Add Atributes to FileNode
        node->name = CDir.filename;
        node->dateTime = dateTime;
        node->compMethod = CDir.compression;
        node->uncompressedSize = CDir.uncompSize;
        node->compressedSize = CDir.compSize;
        node->CRC32 = CDir.CRC32;
        node->offset = CDir.offsetLocalFileHeader;
        fl.push_back(*node);

        //Extract Local File Headers
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

string readZIP::setTimeDate()
{
     string newStr;

         int day = 0, month = 0, year = 0;
         day = (CDir.dateMod & 0x1F);
         if (day < 10)
         {
             newStr += '0';
         }
         newStr += to_string(day);
         newStr += '/';

         month = (((CDir.dateMod) >> 5) & 0x0F);
         if (month < 10)
         {
             newStr += '0';
         }
         newStr += to_string(month);
         newStr += '/';

         year = ((CDir.dateMod >> 9) & 0x7F) + 1980;
         if (year < 10)
         {
             newStr += '0';
         }
         newStr += to_string(year);
         newStr += ' ';

         int sec = 0, min = 0, hours = 0;
         hours = CDir.timeMod >> 11;
         if (hours < 10)
         {
             newStr += '0';
         }
         newStr += to_string(hours);
         newStr += ':';

         min = (CDir.timeMod >> 5) & 0x3F;
         if (min < 10)
         {
             newStr += '0';
         }
         newStr += to_string(min);
         newStr += ':';

         sec = (CDir.timeMod & 0x1F) * 2;
         if (sec < 10)
         {
             newStr += '0';
         }
         newStr += to_string(sec);
         return newStr;
}
