//
// Created by Stefano on 12/2/2022.
//

#ifndef BIOLOOG_SRC_UTILS_CLI_COUNT_NUCLEOTIDES_H_
#define BIOLOOG_SRC_UTILS_CLI_COUNT_NUCLEOTIDES_H_

#include <string>
#include "../../src/DNA/count_nucleotides.h"
#include "../file/read_from_file.h"

namespace cli {
void CountNucleotides(const std::string &file_name);
}
#endif //BIOLOOG_SRC_UTILS_CLI_COUNT_NUCLEOTIDES_H_
