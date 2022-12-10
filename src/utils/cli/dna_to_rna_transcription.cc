//
// Created by Stefano on 12/7/2022.
//

#include "dna_to_rna_transcription.h"

namespace cli {
void DnaToRnaTranscription(const std::string &file_name){
  std::string dna_sequence;
  read_from_file::ReadFromFile(file_name, dna_sequence);
  std::string result = DNA::dna_to_rna_transcription(dna_sequence);
  std::cout << "The corresponding rna is: " << result << std::endl;
}
}