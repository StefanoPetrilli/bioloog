//
// Created by Stefano on 11/23/2022.
//

#ifndef BIOLOOG_READFROMFILE_H
#define BIOLOOG_READFROMFILE_H

#include <string>
#include <fstream>
#include <iostream>

namespace read_from_file {

const std::string pathSeparator =
#ifdef _WIN32
    "\\";
#else
    "/";
#endif

std::string const defaultInputFilePath = ".." +
    pathSeparator + ".." +
    pathSeparator + "input_files" +
    pathSeparator;

void ReadFromFile(std::string const &path, std::string &result);

}

#endif //BIOLOOG_READFROMFILE_H
