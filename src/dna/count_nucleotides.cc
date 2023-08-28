#include "count_nucleotides.h"

namespace dna {
std::array<int, 4> CountNucleotides(std::string const& dna) {
  std::array<int, 4> counting = {0, 0, 0, 0};

  for (char c : dna) {
    switch (c) {
      case 'A':
        counting[0]++;
        break;
      case 'C':
        counting[1]++;
        break;
      case 'G':
        counting[2]++;
        break;
      case 'T':
        counting[3]++;
        break;
      default:
        throw std::invalid_argument(
            "An illegal character was inserted. Only 'A', 'C', 'G' and 'T' "
            "accepted.");
    }
  }

  return counting;
}
}  // namespace dna