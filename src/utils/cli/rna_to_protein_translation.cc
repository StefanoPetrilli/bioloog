//
// Created by Stefano on 12/8/2022.
//

#include "rna_to_protein_translation_test.h"
#include "file/read_from_file.h"
#include "../../src/DNA/rna_to_protein_translation.h"

namespace cli {
void RnaToProteinTranslation(const std::string &file_name){
  std::string dna_sequence;
  read_from_file::ReadFromFile(file_name, dna_sequence);
  std::string result = DNA::RnaToProteinTranslation(dna_sequence);
  std::cout << "The protein translation is: " << result << std::endl;
}
}