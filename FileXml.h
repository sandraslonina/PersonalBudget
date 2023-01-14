#ifndef FILEXML_H
#define FILEXML_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;

class FileXml {
    const string NAME_FILE_XML;

public:
    FileXml(string nameFileXml) : NAME_FILE_XML(nameFileXml) {}

    string getNameFile();
    bool fileIsEmpty();
};
#endif