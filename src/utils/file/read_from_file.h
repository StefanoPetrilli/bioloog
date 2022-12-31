//
// Created by Stefano on 11/23/2022.
//

#ifndef BIOLOOG_READFROMFILE_H
#define BIOLOOG_READFROMFILE_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include "file.h"

namespace file {
const static char kFastaStartingCharacter = '>';
const static char kNewLine = '\n';
const static std::string kPathSeparator =
#ifdef _WIN32
    "\\";
#else
    "/";
#endif
std::string static const kDefaultInputFilePath = ".." +
    kPathSeparator + ".." +
    kPathSeparator + "input_files" +
    kPathSeparator;

std::string KeyFormat(const std::string &basic_string);
std::string RemoveEscapeCharacter(const std::string &basic_string);
void ReadFromFile(const std::string& path, std::string &result);
std::vector<std::string> ReadLinesFromFile(const std::string& path);
std::map<std::string, std::string> ReadFastaFromFile(const std::string& path);
}
#endif //BIOLOOG_READFROMFILE_H
