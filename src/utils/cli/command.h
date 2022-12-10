//
// Created by Stefano on 12/2/2022.
//

#ifndef BIOLOOG_SRC_UTILS_CLI_COMMANDS_H_
#define BIOLOOG_SRC_UTILS_CLI_COMMANDS_H_

#include <string>
#include <unordered_map>
#include <stdexcept>

namespace cli {
enum Command {
  CountNucleotidesCommand,
  DnaToRnaTranscriptionCommand,
  InvalidCommand
};

static std::unordered_map<std::string, Command> const command_table = {
    {"count_nucleotides", Command::CountNucleotidesCommand},
    {"dna_to_rna_transcription", Command::DnaToRnaTranscriptionCommand}
};

static const Command all_commands[] = {CountNucleotidesCommand, DnaToRnaTranscriptionCommand};

std::string CommandToString(Command command);

Command StringToCommand(const std::string& string);
}
#endif //BIOLOOG_SRC_UTILS_CLI_COMMANDS_H_
