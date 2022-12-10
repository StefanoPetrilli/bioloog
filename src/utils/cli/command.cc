//
// Created by Stefano on 12/2/2022.
//

#include "command.h"

namespace cli {
std::string CommandToString(Command command) {
  switch (command) {
    case CountNucleotides:
      return "count_nucleotides\tTakes a DNA string and returns"
             "the counting of each nucleotides in the format {'A', 'C', 'T', 'G'}";
    default:throw std::domain_error("Unexpected valued encountered.");
  }
}

Command StringToCommand(std::string string) {
  auto it = command_table.find(string);

  if (it != command_table.end())
    return it->second;
  else
    return Command::InvalidCommand;

}
}