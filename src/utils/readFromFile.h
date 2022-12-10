//
// Created by Stefano on 11/23/2022.
//

#ifndef BIOLOOG_READFROMFILE_H
#define BIOLOOG_READFROMFILE_H

#include <string>

namespace readFromFile {

const std::string pathSeparator =
#ifdef _WIN32
    "\\";
#else
"/";
#endif

std::string const defaultInputFilePath = ".." +
    pathSeparator + ".." +
    pathSeparator + "inputFiles" +
    pathSeparator;

void readFromFile(std::string const &path, std::string &result);

};

#endif //BIOLOOG_READFROMFILE_H
