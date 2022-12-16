//
// Created by Stefano on 12/1/2022.
//

#include "display_help.h"

namespace cli {
void DisplayHelp() {
  std::cout << cli::ascii_art << cli::program_name << std::endl;
  std::cout << '\n' << cli::commands_intro << '\n' <<  std::endl;

  for(cli::VirtualCommand* i : cli::VirtualCommand::GetList())
    std::cout << i->ToString() << std::endl;
}
}