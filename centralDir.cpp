#include "centralDir.h"

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
	cout << "Compression Size: " << compSize << endl;
	cout << "Uncompression Size: " << uncompSize << endl;
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
