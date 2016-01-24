/**
  About {{filename}}.h/{{filename}}.cpp
  By: Mike

*/

#ifndef SERIALIZATIONREADER_H
#define SERIALIZATIONREADER_H

#include <iostream>
#include <fstream>

#include "serializationconstants.h"

namespace MTechEngine {
namespace IO {
class SerializationReader
{
public:
    SerializationReader();
    int ReadBytesFromFile(char *readInto, int bufferSize, const char filename[]);
    int ReadInt(char src[], int &pointer);
    short ReadShort(char src[], int &pointer);
};
}
}
#endif // SERIALIZATIONREADER_H
