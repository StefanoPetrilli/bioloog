#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "format.h"

namespace algorithm {
int DynamicLevenshteinDistance(
    const std::pair<std::string, std::string>& sequences);
}  // namespace algorithm