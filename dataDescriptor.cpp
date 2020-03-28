#include "dataDescriptor.h"

void Descriptor::unpack()
{
    char *buff = descBuffer;

    memcpy(&CRC32, buff, 4);
    memcpy(&compSize, buff += 4, 4);
    memcpy(&uncompSize, buff += 4, 4);
}

void Descriptor::printDescriptor()
{
    cout << "======= Data Descriptor ========" << endl;
    cout << "CRC-32: " << CRC32 << endl;
    cout << "Compressed Size: " << compSize << endl;
    cout << "Uncompressed Size: " << uncompSize << endl;
}
