//
// Created by Stefano on 12/16/2022.
//
#include "find_motif.h"

namespace DNA {
std::list<int> FindMotif(const std::string& dna_sequence,
                         const std::string& motif) {

  std::list<int> result{};
  size_t floating_position = 0;

  while (floating_position != std::string::npos) {
    floating_position = dna_sequence.find(motif, floating_position);
    if (floating_position != std::string::npos) {
      result.push_back((int)floating_position);
      floating_position++;
    }
  }

  return result;
}

bool ContainMotif(const std::string& dna_sequence, const std::string& motif) {
#ifdef _OPENMP
  return ParallelContainMotif(dna_sequence, motif);
#else
  return SequentialContainMotif(dna_sequence, motif);
#endif
}

bool SequentialContainMotif(const std::string& dna_sequence,
                            const std::string& motif) {
  return dna_sequence.find(motif) != std::string::npos;
}

#ifdef _OPENMP
bool ParallelContainMotif(const std::string& dna_sequence,
                          const std::string& motif, size_t chunk_size) {
  if (dna_sequence.size() < kDimensionRequirementForParallelExecutionFindMotif)
    return SequentialContainMotif(dna_sequence, motif);

  bool found = false;
  if (chunk_size < motif.size())
    chunk_size = motif.size() * 2;
#pragma omp parallel shared(dna_sequence, motif, chunk_size, \
                            found) default(none)
  {
#pragma omp single
    {
      for (size_t i = 0; i < dna_sequence.size() && not found;
           i += chunk_size) {
#pragma omp task shared(dna_sequence, motif, chunk_size, found) \
    firstprivate(i) default(none)
        {
          if (dna_sequence
                  .substr(i == 0 ? 0 : i - motif.length(), i + chunk_size)
                  .find(motif) != std::string::npos)
#pragma omp atomic write
            found = true;
        }
      }
    }
  }
  return found;
}
#endif
}  // namespace DNA
