//
// Created by Stefano on 1/15/2023.
//

#ifndef BIOLOOG_SRC_DNA_FIND_SPLICED_MOTIF_H_
#define BIOLOOG_SRC_DNA_FIND_SPLICED_MOTIF_H_

#include <cstdio>
#include <list>
#include <unordered_map>
#include <string>

namespace DNA {
std::list<int> FindSplicedMotif(const std::unordered_map<std::string, std::string> &sequences);
}
#endif //BIOLOOG_SRC_DNA_FIND_SPLICED_MOTIF_H_
