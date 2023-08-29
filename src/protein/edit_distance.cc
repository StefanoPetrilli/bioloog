#include "edit_distance.h"

namespace protein {
int EditDistance(const std::pair<std::string, std::string>& pair) {
  return algorithm::DynamicLevenshteinDistance(pair);
}
}  // namespace protein