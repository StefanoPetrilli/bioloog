#pragma once

#include <string>
#include <list>
#include <iostream>
#ifdef _OPENMP
#include <omp.h>
#endif

#include "alphabet_validator.h"

namespace DNA {
std::list<int> FindMotif(const std::string &dna_sequence, const std::string &motif);
bool ContainMotif(const std::string &dna_sequence, const std::string &motif);
bool SequentialContainMotif(const std::string &dna_sequence, const std::string &motif);
#ifdef _OPENMP
static const size_t kDimensionRequirementForParallelExecutionFindMotif = 1000000;
bool ParallelContainMotif(const std::string &dna_sequence, const std::string &motif, size_t chunk_size = 1000);
#endif
}
