#include "command.h"
#include "display_help.h"

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {
  auto *e = new cli::EditDistance(
      "edit_distance", "Find a the edit distance between two protein strings.");
  e->Exec(file::kEditDistance);

  /*
  if (argc == 1)
    cli::DisplayHelp();
  else {
    for (cli::VirtualCommand *i : cli::VirtualCommand::GetList())
      if (argv[1] == i->GetName()) i->Exec(argv[2]);
    return 0;
  }
  */
}
