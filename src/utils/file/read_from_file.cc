//
// Created by Stefano on 11/23/2022.
//

#include <list>

#include "read_from_file.h"

namespace read_from_file {

void ReadFromFile(std::string const &path, std::string &result) {

  std::ifstream file(kDefaultInputFilePath + path);

  if (file.is_open()) {
    getline(file, result, '\x1A');
    file.close();
  } else {
    throw std::invalid_argument("The path does not correspond to a file or the file cannot be accessed");
  }
}

std::list<std::string> ReadLinesFromFile(const std::string &path) {

  std::string file_content;
  ReadFromFile(path, file_content);

  std::list<std::string> result{};
  std::string line;

  size_t position_start = 0, position_end, delimiter_length = 1;
  while ((position_end = file_content.find(kNewLine, position_start)) != std::string::npos) {
    line = file_content.substr(position_start, position_end - position_start);
    position_start = position_end + delimiter_length;
    result.push_back(line);
    line = "";
  }

  if (not line.empty())
    result.push_back(line);

  return result;
}
}