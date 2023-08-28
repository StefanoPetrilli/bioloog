#pragma once

#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>

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
std::string static const kDefaultInputFilePath = ".." + kPathSeparator + ".." +
                                                 kPathSeparator +
                                                 "input_files" + kPathSeparator;

std::string KeyFormat(const std::string& key);
std::string RemoveEscapeCharacter(const std::string& line);
void ReadFromFile(const std::string& path, std::string& result);
std::vector<std::string> ReadLinesFromFile(const std::string& path);
std::unordered_map<std::string, std::string> ReadFastaFromFile(
    const std::string& path);
std::pair<std::string, std::string> ReadFastaPairFromFile(
    const std::string& path);
}  // namespace file
