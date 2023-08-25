//
// Created by Stefano on 1/15/2023.
//

#ifndef BIOLOOG_SRC_DNA_FIND_SPLICED_MOTIF_H_
#define BIOLOOG_SRC_DNA_FIND_SPLICED_MOTIF_H_

#include <cstdio>
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>

namespace DNA {
std::vector<int> FindSplicedMotif(const std::pair<std::string, std::string> &sequences);
}
#endif //BIOLOOG_SRC_DNA_FIND_SPLICED_MOTIF_H_
