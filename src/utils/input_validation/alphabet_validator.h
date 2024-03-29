#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "alphabet_validator.h"
#include "find_motif.h"
#include "find_shared_motif.h"

namespace input_validation {
static const std::string kRnaAlphabet = "ACGU";
static const std::string kDnaAlphabet = "ACGT";
static const std::string kProteinAlphabet = "QWERTYUIPASDFGHKLCVNM";
static const std::string kRnaErrorMessage =
    "An illegal character was inserted. Only 'A', 'C', 'G' and 'U' accepted.";
static const std::string kDnaErrorMessage =
    "An illegal character was inserted. Only 'A', 'C', 'G' and 'T' accepted.";
static const std::string kProteinErrorMessage =
    "An illegal character was inserted. All the letters except 'B', 'J', 'O', "
    "'U', 'X', and 'Z'.";

class AlphabetValidator {
 private:
  std::string error_message_;
  std::vector<int> lookup_vector_;
  void SetLookupVector(char character);
  [[nodiscard]] std::string GetErrorMessage() const;
  void SetErrorMessage(const std::string &error_message);

 public:
  explicit AlphabetValidator(const std::string &alphabet,
                             const std::string &error_message);
  std::vector<int> GetLookupVector();
  [[nodiscard]] bool IsPartOfTheAlphabet(char character) const;
  void IsPartOfTheAlphabet(const std::string &sequence) const;
};

static const AlphabetValidator kStandardValidatorRna =
    AlphabetValidator(kRnaAlphabet, kRnaErrorMessage);
static const AlphabetValidator kStandardValidatorDna =
    AlphabetValidator(kDnaAlphabet, kDnaErrorMessage);
static const AlphabetValidator kStandardValidatorProtein =
    AlphabetValidator(kProteinAlphabet, kProteinErrorMessage);
}  // namespace input_validation
