//
// Created by Stefano on 12/25/2022.
//

#include "command_test.h"

namespace command_test {
TEST(Command, Expect_Throw_WhenInputsAreNotValid) {
  cli::CountNucleotides count_nucleotides{"count_nucleotides",
                                          "Takes a DNA string and returns the counting of each nucleotides in the format {'A', 'C', 'T', 'G}"};
  cli::DnaToRnaTranscription dna_to_rna_implementation{"dna_to_rna_translation",
                                                       "Takes a DNA string and returnsthe rna transcription"};
  cli::RnaToProteinTranslation rna_to_protein_translation{"rna_to_protein_translation",
                                                          "Takes a RNA string and returnsthe proteins translation"};
  cli::FindMotif find_motif{"find_motif",
                            "Takes a DNA sequence, a motif and return the positions of the motif in the dna sequence"};
  cli::FindSharedMotif find_shared_motif{"find_shared_motif",
                                         "Takes multiple DNA sequences, and return the longest common motif"};

  for (auto command : cli::VirtualCommand::GetList()) {
    std::string path = input_with_errors[command->GetName()];
    EXPECT_THROW(command->Exec(path), std::exception);
  }
}
}