#include "FileXml.h"

string FileXml::getNameFile() {
    return NAME_FILE_XML;
}

bool FileXml::fileIsEmpty() {
    bool fileEmpty = true;
    fstream fileXml;
    fileXml.open(getNameFile().c_str(), ios::app);

    if (fileXml.good() == true) {
        fileXml.seekg(0, ios::end);

        if (fileXml.tellg() != 0)
            fileEmpty = false;
    }

    fileXml.close();
    return fileEmpty;
}
