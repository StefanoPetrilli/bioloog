#include <iostream>

#include "cli/display_help.h"
#include "cli/count_nucleotides.h"

int main(int argc, char *argv[]) {

  if (argc == 1)
    cli::DisplayHelp();
  else
    switch (cli::StringToCommand(argv[1])) {
      case cli::Command::CountNucleotidesCommand: cli::CountNucleotides(argv[2]);
        break;
      default:return 1; // cli::display_error()
    }

  return 0;
}

