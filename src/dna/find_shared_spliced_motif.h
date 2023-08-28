
#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "format.h"

namespace DNA {
std::string FindSharedSplicedMotif(
    const std::pair<std::string, std::string>& sequences);
std::string RecursiveFindSharedSplicedMotif(
    const std::pair<std::string, std::string>& sequences);
std::string DynamicProgrammingFindSharedSplicedMotif(
    const std::pair<std::string, std::string>& sequences);
}  // namespace DNA