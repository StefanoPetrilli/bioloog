#include <iostream>

#include "cli/display_help.h"

int main(int argc, char *argv[]) {

  if (argc == 1)
    cli::DisplayHelp();
  else
    switch (cli::StringToCommand(argv[1])) {
      case cli::Command::CountNucleotides:return 1;
      default:return 0; // cli::display_error()
    }

  return 0;
}

