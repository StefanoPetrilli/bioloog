//
// Created by Stefano on 12/2/2022.
//
#include "command_test.h"

namespace command_test {
TEST(CommandToString, CommandCountNucleotidesShouldReturnExpectedText) {
  EXPECT_EQ(cli::CommandToString(cli::Command::CountNucleotidesCommand),
            "count_nucleotides\tTakes a DNA string and returns"
            "the counting of each nucleotides in the format {'A', 'C', 'T', 'G'}");
}

TEST(CommandToString, CommandInvalidCommandShouldThrowDomainExcpetion) {
  EXPECT_THROW(cli::CommandToString(cli::Command::InvalidCommand), std::domain_error);
}

TEST(StringToCommand, StringShouldReturnExpectedCommand) {
  EXPECT_EQ(cli::StringToCommand("count_nucleotides"), cli::Command::CountNucleotidesCommand);

  EXPECT_EQ(cli::StringToCommand("unknown_command"), cli::Command::InvalidCommand);
}
}