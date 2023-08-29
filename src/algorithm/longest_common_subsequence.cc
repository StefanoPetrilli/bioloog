#include "longest_common_subsequence.h"

namespace algorithm {
std::string RecursiveLongestCommonSubsequence(
    const std::pair<std::string, std::string>& sequences) {
  if (sequences.first.empty() || sequences.second.empty()) return std::string();
  if (sequences.first.back() == sequences.second.back())
    return RecursiveLongestCommonSubsequence(std::make_pair(
               sequences.first.substr(0, sequences.first.size() - 1),
               sequences.second.substr(0, sequences.second.size() - 1))) +
           sequences.first.back();

  std::string first = RecursiveLongestCommonSubsequence(std::make_pair(
      sequences.first.substr(0, sequences.first.size() - 1), sequences.second));
  std::string second = RecursiveLongestCommonSubsequence(
      std::make_pair(sequences.first,
                     sequences.second.substr(0, sequences.second.size() - 1)));
  return first.size() > second.size() ? first : second;
}

std::string DynamicLongestCommonSubsequence(
    const std::pair<std::string, std::string>& sequences) {
  size_t num_rows = sequences.second.size() + 1;
  size_t num_cols = sequences.first.size() + 1;
  std::vector<std::vector<std::string>> result_matrix(
      num_rows, std::vector<std::string>(num_cols, std::string()));

  for (size_t i = 1; i < num_rows; ++i) {
    for (size_t y = 1; y < num_cols; ++y) {
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
}  // namespace algorithm