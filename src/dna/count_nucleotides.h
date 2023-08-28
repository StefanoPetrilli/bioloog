#pragma once

#include <array>
#include <stdexcept>
#include <string>

namespace dna {
std::array<int, 4> CountNucleotides(std::string const& dna);
}
