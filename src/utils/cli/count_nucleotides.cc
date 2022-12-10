//
// Created by Stefano on 12/2/2022.
//

#include "count_nucleotides.h"

namespace cli {
void CountNucleotides(const std::string& file_name) {
  std::string dna_sequence;
  read_from_file::ReadFromFile(file_name, dna_sequence);
  std::array<int, 4> result = DNA::CountNucleotides(dna_sequence);
  std::cout << "A:" << result[0] << ", C:" << result[1] << ", G:" << result[2] << ", T: " << result[3] << std::endl;
}
}