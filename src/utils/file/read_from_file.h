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

namespace read_from_file {

const static char kNewLine = '\n';
const static char kFastaStartingCharacter = '>';
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

void ReadFromFile(std::string const &path, std::string &result);
std::vector<std::string> ReadLinesFromFile(const std::string &path);
std::map<std::string, std::string> ReadFastaFromFile(const std::string &path);
}
#endif //BIOLOOG_READFROMFILE_H
