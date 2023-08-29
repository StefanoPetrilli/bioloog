#include "find_shared_spliced_motif.h"

namespace dna {

std::string FindSharedSplicedMotif(
    const std::pair<std::string, std::string>& sequences) {
  return algorithm::DynamicLongestCommonSubsequence(sequences);
}
}  // namespace dna
