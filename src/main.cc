#include "utils/cli/display_help.h"
#include "utils/cli/command.h"

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {

  auto e = new cli::FindSplicedMotif("find_spliced_motif", "Find a spliced motif in a sequence");
  e->Exec("rosalind_sseq_1_dataset.txt");

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
