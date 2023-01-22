#include "FileXml.h"

string FileXml::getNameFile()
{
    return NAME_FILE_XML;
}

bool FileXml::isFileEmpty()
{
    bool fileIsEmpty = true;
    fstream textFile;
    textFile.open(getNameFile().c_str(), ios::app);

    if (textFile.good() == true)
    {
        textFile.seekg(0, ios::end);
        if (textFile.tellg() != 0)
            fileIsEmpty = false;
    }

    textFile.close();
    return fileIsEmpty;
}
