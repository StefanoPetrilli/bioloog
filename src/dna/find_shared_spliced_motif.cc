#include "find_shared_spliced_motif.h"

namespace DNA {

std::string FindSharedSplicedMotif(
    const std::pair<std::string, std::string>& sequences) {
  return DynamicProgrammingFindSharedSplicedMotif(sequences);
}

std::string RecursiveFindSharedSplicedMotif(
    const std::pair<std::string, std::string>& sequences) {
  if (sequences.first.empty() || sequences.second.empty())
    return std::string();
  else if (sequences.first.back() == sequences.second.back())
    return RecursiveFindSharedSplicedMotif(std::make_pair(
               sequences.first.substr(0, sequences.first.size() - 1),
               sequences.second.substr(0, sequences.second.size() - 1))) +
           sequences.first.back();
  else {
    std::string first = RecursiveFindSharedSplicedMotif(
        std::make_pair(sequences.first.substr(0, sequences.first.size() - 1),
                       sequences.second));
    std::string second = RecursiveFindSharedSplicedMotif(std::make_pair(
        sequences.first,
        sequences.second.substr(0, sequences.second.size() - 1)));
    return first.size() > second.size() ? first : second;
  }

  return std::string();
}

std::string DynamicProgrammingFindSharedSplicedMotif(
    const std::pair<std::string, std::string>& sequences) {
  size_t numRows = sequences.second.size() + 1,
         numCols = sequences.first.size() + 1;
  std::vector<std::vector<std::string>> result_matrix(
      numRows, std::vector<std::string>(numCols, std::string()));

  for (size_t i = 1; i < numRows; ++i) {
    for (size_t y = 1; y < numCols; ++y) {
      if (sequences.second.at(i - 1) == sequences.first.at(y - 1))
        result_matrix.at(i).at(y) =
            result_matrix.at(i - 1).at(y - 1) + sequences.second.at(i - 1);
      else
        result_matrix.at(i - 1).at(y).size() <
                result_matrix.at(i).at(y - 1).size()
            ? result_matrix.at(i).at(y) = result_matrix.at(i).at(y - 1)
            : result_matrix.at(i).at(y) = result_matrix.at(i - 1).at(y);
    }
  }

  return result_matrix.back().back();
}

}  // namespace DNA
