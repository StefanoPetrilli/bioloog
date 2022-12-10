//
// Created by Stefano on 12/2/2022.
//

#include <string>
#include <unordered_map>
#include <stdexcept>

#ifndef BIOLOOG_SRC_UTILS_CLI_COMMANDS_H_
#define BIOLOOG_SRC_UTILS_CLI_COMMANDS_H_
namespace cli {
enum Command {
  CountNucleotides,
  InvalidCommand
};

static std::unordered_map<std::string, Command> const command_table = {
    {"count_nucleotides", Command::CountNucleotides}
};

static const Command all_commands[] = {CountNucleotides};

std::string CommandToString(Command command);

Command StringToCommand(std::string string);
}
#endif //BIOLOOG_SRC_UTILS_CLI_COMMANDS_H_
