#include "format.h"

namespace format {  // TODO(stefanopetrilli): make the ToString function generic
std::string ToString(const std::vector<int>& list) {
  std::string result{};
  for (auto i : list) result.append(std::to_string(i) + " ");
  return result.substr(0, result.size() - 1);
}

std::string ToString(const std::vector<std::string>& list) {
  std::string result{};
  for (const auto& i : list) result.append(i + " ");
  return result.substr(0, result.size() - 1);
}
}  // namespace format
