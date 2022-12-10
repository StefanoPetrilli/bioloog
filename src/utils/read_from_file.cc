//
// Created by Stefano on 11/23/2022.
//

#include <fstream>
#include "read_from_file.h"

namespace read_from_file {

void ReadFromFile(const std::string &path, std::string &result) {

  std::ifstream file(defaultInputFilePath + path);

  if (file.is_open()) {
    getline(file, result, '\x1A');
    file.close();
  } else {
    throw std::invalid_argument("The path does not correspond to a file or the file cannot be accessed");
  }
}

}