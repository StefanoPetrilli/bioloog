#include "cli/display_help.h"
#include "cli/count_nucleotides.h"
#include "cli/display_error.h"
#include "cli/dna_to_rna_transcription.h"
#include "cli/rna_to_protein_translation.h"

int main(int argc, char *argv[]) {

  if (argc == 1)
    cli::DisplayHelp();
  else
    switch (cli::StringToCommand(argv[1])) {
      case cli::Command::CountNucleotidesCommand: cli::CountNucleotides(argv[2]);
        break;
      case cli::Command::DnaToRnaTranscriptionCommand: cli::DnaToRnaTranscription(argv[2]);
        break;
      case cli::Command::RnaToDnaTranslationCommand: cli::RnaToProteinTranslation(argv[2]);
        break;
      default: cli::DisplayError();
    }

  return 0;
}

