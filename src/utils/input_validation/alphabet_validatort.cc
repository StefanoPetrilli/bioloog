//
// Created by Stefano on 12/10/2022.
//

#include <iostream>
#include "alphabet_validatort.h"

namespace input_validation {
input_validation::AlphabetValidator::AlphabetValidator(const std::string &alphabet) {
  this->lookup_vector = std::vector<int>(128, false);
  for (char c : alphabet)
    this->SetLookupVector(c);
}

std::vector<int> input_validation::AlphabetValidator::GetLookupVector() {
  return this->lookup_vector;
}

void input_validation::AlphabetValidator::SetLookupVector(char character) {
  this->lookup_vector.at(character) = true;
}

bool input_validation::AlphabetValidator::IsPartOfTheAlphabet(char character) {
  return this->lookup_vector.at(character);
}
}

