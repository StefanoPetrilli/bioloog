//
// Created by Stefano on 11/23/2022.
//

#include "read_from_file.h"

namespace file {

void ReadFromFile(const std::string& path, std::string& result) {
  std::ifstream file_stream(kDefaultInputFilePath + path);

  if (file_stream.is_open()) {
    getline(file_stream, result, '\x1A');
    file_stream.close();
  } else {
    throw std::invalid_argument(
        "The path does not correspond to a file or the file cannot be "
        "accessed");
  }
}

std::vector<std::string> ReadLinesFromFile(const std::string& path) {
  std::string file_content;
  ReadFromFile(path, file_content);

  std::vector<std::string> result{};
  std::string line;

  size_t position_start = 0;
  size_t position_end;
  size_t delimiter_length = 1;
  while ((position_end = file_content.find(kNewLine, position_start)) !=
         std::string::npos) {
    line = RemoveEscapeCharacter(
        file_content.substr(position_start, position_end - position_start));
    position_start = position_end + delimiter_length;
    result.push_back(line);
    line = "";
  }

  if (not line.empty()) result.push_back(line);

  return result;
}

auto is_sequence_name = [](const std::string& line) {
  return line.starts_with('>');
};

std::unordered_map<std::string, std::string> ReadFastaFromFile(
    const std::string& path) {
  std::unordered_map<std::string, std::string> result;
  auto file_lines = ReadLinesFromFile(path);

  std::string key;
  std::string content;
  for (const std::string& line : file_lines) {
    if (is_sequence_name(line)) {
      result.insert({key, content});
      key = KeyFormat(line);
      content = "";
    } else {
      content += RemoveEscapeCharacter(line);
    }
  }

  result.insert({key, content});
  result.erase("");
  return result;
}

std::pair<std::string, std::string> ReadFastaPairFromFile(
    const std::string& path) {
  std::pair<std::string, std::string> result;
  size_t second_sequence_index{0};
  auto file_lines = ReadLinesFromFile(path);

  file_lines.erase(file_lines.begin());
  for (size_t i = 0; i < file_lines.size(); i++) {
    if (is_sequence_name(file_lines[i]) && second_sequence_index == 0)
      second_sequence_index = i;
    else if (is_sequence_name(file_lines[i]) && second_sequence_index != 0) {
      throw std::invalid_argument("The file contains more than two sequences");
    }
  }

  for (size_t i = 0; i < second_sequence_index; i++)
    result.first += file_lines[i];

  for (size_t i = second_sequence_index + 1; i < file_lines.size(); i++)
    result.second += file_lines[i];

  return result;
}

std::string RemoveEscapeCharacter(const std::string& line) {
  std::string result = line;
  while (result.starts_with('\n') || result.starts_with('\r'))
    result = result.substr(1);
  while (result.ends_with('\n') || result.ends_with('\r'))
    result = result.substr(0, result.length() - 1);
  return result;
}

std::string KeyFormat(const std::string& key) {
  return key.ends_with('\r') ? RemoveEscapeCharacter(key.substr(1))
                             : key.substr(1);
}
}  // namespace file