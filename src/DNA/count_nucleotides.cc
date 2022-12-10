//
// Created by Stefano on 11/29/2022.
//

#include "count_nucleotides.h"

namespace count_nucleotides {
std::array<int, 4> CountNucleotides(std::string const &DNA) {

  std::array<int, 4> counting = {0, 0, 0, 0};

  for (char c : DNA) {
    switch (c) {
      case 'A':counting[0]++;
        break;
      case 'C':counting[1]++;
        break;
      case 'G':counting[2]++;
        break;
      case 'T':counting[3]++;
        break;
      default:throw std::invalid_argument("An illegal character was inserted. Only 'A', 'C', 'G' and 'T' accepted.");
    }
  }

  return counting;
}
}