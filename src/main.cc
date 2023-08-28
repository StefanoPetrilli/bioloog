#include "utils/cli/command.h"
#include "utils/cli/display_help.h"

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {
  if (argc == 1)
    cli::DisplayHelp();
  else {
    for (cli::VirtualCommand *i : cli::VirtualCommand::GetList())
      if (argv[1] == i->GetName()) i->Exec(argv[2]);
    return 0;
  }
}
