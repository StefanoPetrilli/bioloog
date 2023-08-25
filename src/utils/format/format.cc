#include "format.h"

namespace format {
    std::string ToString([[maybe_unused]] std::vector<int> list) {
        std::string result {};
        for (auto i : list)
            result.append(std::to_string(i) + " ");
        return result.substr(0, result.size() - 1);
    }
}
