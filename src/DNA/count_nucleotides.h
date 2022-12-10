//
// Created by Stefano on 11/29/2022.
//

#ifndef BIOLOOG_COUNTNUCELOTIDES_H
#define BIOLOOG_COUNTNUCELOTIDES_H

#include <array>
#include <string>
#include <stdexcept>

namespace count_nucleotides {
std::array<int, 4> CountNucleotides(std::string const &DNA);
}
#endif //BIOLOOG_COUNTNUCELOTIDES_H
