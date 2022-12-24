//
// Created by Stefano on 12/16/2022.
//

#ifndef BIOLOOG_SRC_DNA_FIND_MOTIF_H_
#define BIOLOOG_SRC_DNA_FIND_MOTIF_H_

#include <string>
#include <list>
#include <iostream>


namespace DNA {
std::list<int> FindMotif(const std::string& dna_sequence, const std::string& motif);
bool ContainMotif(const std::string& dna_sequence, const std::string& motif);
}
#endif //BIOLOOG_SRC_DNA_FIND_MOTIF_H_
