//
// Created by Stefano on 12/10/2022.
//

#ifndef BIOLOOG_SRC_UTILS_INPUT_VALIDATION_ALPHABET_VALIDATORT_H_
#define BIOLOOG_SRC_UTILS_INPUT_VALIDATION_ALPHABET_VALIDATORT_H_
#include <string>
#include <vector>
#include <iostream>

#include "../../DNA/find_motif.h"
#include "../../DNA/find_shared_motif.h"
#include "../input_validation/alphabet_validatort.h"

namespace input_validation {
static const std::string kRnaAlphabet = "ACGU";
static const std::string kDnaAlphabet = "ACGT";
static const std::string kRnaErrorMessage = "An illegal character was inserted. Only 'A', 'C', 'G' and 'U' accepted.";
static const std::string kDnaErrorMessage = "An illegal character was inserted. Only 'A', 'C', 'G' and 'T' accepted.";

class AlphabetValidator {

 private:
  std::string error_message_;
  std::vector<int> lookup_vector_;
  void SetLookupVector(char character);
  [[nodiscard]] std::string GetErrorMessage() const;
  void SetErrorMessage(const std::string& error_message);

 public:
  explicit AlphabetValidator(const std::string& alphabet, const std::string &error_message);
  std::vector<int> GetLookupVector();
  [[nodiscard]] bool IsPartOfTheAlphabet(char character) const;
  void IsPartOfTheAlphabet(const std::string& sequence) const;
};

static const AlphabetValidator kStandardValidatorRna = AlphabetValidator(kRnaAlphabet, kRnaErrorMessage);
static const AlphabetValidator kStandardValidatorDna = AlphabetValidator(kDnaAlphabet, kDnaErrorMessage);
}
#endif //BIOLOOG_SRC_UTILS_INPUT_VALIDATION_ALPHABET_VALIDATORT_H_
