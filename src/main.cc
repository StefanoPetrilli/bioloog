#include "cli/display_help.h"
#include "cli/command.h"

int main(int argc, char *argv[]) {
  cli::CountNucleotides count_nucleotides{"count_nucleotides", "Takes a DNA string and returnsthe counting of each nucleotides in the format {'A', 'C', 'T', 'G}"};
  cli::DnaToRnaTranscription dna_to_rna_implementation{"dna_to_rna_translation", "Takes a DNA string and returnsthe rna transcription"};
  cli::RnaToProteinTranslation rna_to_protein_translation{"rna_to_protein_translation", "Takes a RNA string and returnsthe proteins translation"};

  if (argc == 1)
    cli::DisplayHelp();
  else {
    for(cli::VirtualCommand* i : cli::VirtualCommand::GetList()) {
      if (argv[1] == i->GetName()) i->Exec(argv[2]);
    }
  }

  return 0;
}

