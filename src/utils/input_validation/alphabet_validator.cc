//
// Created by Stefano on 12/10/2022.
//

#include "alphabet_validator.h"

namespace input_validation {
input_validation::AlphabetValidator::AlphabetValidator(
    const std::string& alphabet, const std::string& error_message) {
  this->lookup_vector_ = std::vector<int>(128, false);

  for (char c : alphabet)
    this->SetLookupVector(c);

  SetErrorMessage(error_message);
}

std::vector<int> input_validation::AlphabetValidator::GetLookupVector() {
  return this->lookup_vector_;
}

void input_validation::AlphabetValidator::SetLookupVector(char character) {
  this->lookup_vector_.at(character) = true;
}

bool input_validation::AlphabetValidator::IsPartOfTheAlphabet(
    char character) const {
  return this->lookup_vector_.at(character);
}

void AlphabetValidator::IsPartOfTheAlphabet(const std::string& sequence) const {
  for (char c : sequence) {
    if (!this->IsPartOfTheAlphabet(c))
      throw std::invalid_argument(GetErrorMessage());
  }
}

std::string AlphabetValidator::GetErrorMessage() const {
  return this->error_message_;
}

void AlphabetValidator::SetErrorMessage(const std::string& error_message) {
  this->error_message_ = error_message;
}
}  // namespace input_validation
