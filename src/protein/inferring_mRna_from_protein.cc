//
// Created by Stefano on 1/6/2023.
//

#include "inferring_mRna_from_protein.h"

namespace protein {
unsigned int InferMRna(std::string& protein_sequence) {
  protein_sequence.push_back(kStopCodon);

#ifdef _OPENMP
  return ParallelInferMRna(protein_sequence);
#else
  return SequentialInferMRna(protein_sequence);
#endif
}

unsigned int SequentialInferMRna(const std::string& protein_sequence) {
  unsigned int result = 1;

  for (const char& i : protein_sequence)
    result = (result * GetPossibleTranslations(i)) % kModule;

  return result;
}

unsigned int ParallelInferMRna(const std::string& protein_sequence) {
  long result = 1;

#pragma omp parallel shared(result, protein_sequence, kModule) default(none)
  {
#pragma omp single
    {
#pragma omp declare reduction(productAndModule:long                     \
                              : omp_out = (omp_out * omp_in) % 1000000) \
    initializer(omp_priv = omp_orig)
#pragma omp taskloop num_tasks(1) reduction(productAndModule \
                                            : result)        \
    shared(protein_sequence, kModule) default(none)
      for (size_t i = 0; i < protein_sequence.length(); i++)
        result = (result * GetPossibleTranslations(protein_sequence.at(i))) %
                 kModule;
    }
  }

  return result;
}

unsigned int GetPossibleTranslations(const char& protein) {
  return protein::kProteinToPossibleTranslation.at(protein);
}
}  // namespace protein