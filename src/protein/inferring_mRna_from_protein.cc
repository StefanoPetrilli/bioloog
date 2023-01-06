//
// Created by Stefano on 1/6/2023.
//

#include "inferring_mRna_from_protein.h"

namespace protein
{
unsigned int InferMRna(const std::string& protein_sequence){
  unsigned int result = 1;

  for (auto protein : protein_sequence + kStopCodon)
    result = (result * GetPossibleTranslations(protein)) % 1000000;

  return result;
}
unsigned int GetPossibleTranslations(const char &protein) {
  return protein::kProteinToPossibleTranslation.at(protein);
}
}