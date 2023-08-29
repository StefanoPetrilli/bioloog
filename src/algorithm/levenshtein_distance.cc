#include "levenshtein_distance.h"

namespace algorithm {
int DynamicLevenshteinDistance(
    const std::pair<std::string, std::string>& sequences) {
  size_t num_rows = sequences.second.size() + 1;
  size_t num_cols = sequences.first.size() + 1;

  std::vector<std::vector<int>> result_matrix(num_rows,
                                              std::vector<int>(num_cols, 0));

  for (size_t i = 0; i < num_rows; ++i) {
    for (size_t y = 0; y < num_cols; ++y) {
      if (i == 0) {
        result_matrix.at(i).at(y) = y;
        continue;
      }

      if (y == 0) {
        result_matrix.at(i).at(y) = i;
        continue;
      }

      if (sequences.second.at(i - 1) != sequences.first.at(y - 1)) {
        auto min = std::min(std::min(result_matrix.at(i - 1).at(y - 1),
                                     result_matrix.at(i).at(y - 1)),
                            result_matrix.at(i - 1).at(y));
        result_matrix.at(i).at(y) = min + 1;
      } else
        result_matrix.at(i).at(y) = result_matrix.at(i - 1).at(y - 1);
    }
  }
  return result_matrix.back().back();
}
}  // namespace algorithm