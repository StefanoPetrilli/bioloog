#include "utils/cli/display_help.h"
#include "utils/cli/command.h"

int main(int argc, char *argv[]) {
  if (argc == 1)
    cli::DisplayHelp();
  else {
    for (cli::VirtualCommand *i : cli::VirtualCommand::GetList())
      if (argv[1] == i->GetName()) i->Exec(argv[2]);

    return 0;
  }
}
