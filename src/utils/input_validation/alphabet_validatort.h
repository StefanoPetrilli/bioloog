//
// Created by Stefano on 12/10/2022.
//

#ifndef BIOLOOG_SRC_UTILS_INPUT_VALIDATION_ALPHABET_VALIDATORT_H_
#define BIOLOOG_SRC_UTILS_INPUT_VALIDATION_ALPHABET_VALIDATORT_H_
#include <string>
#include <vector>

namespace input_validation {
static std::string RNA_ALPHABET = "ACGU";
class AlphabetValidator {
 private:
  std::vector<int> lookup_vector;
  void SetLookupVector(char character);

 public:
  explicit AlphabetValidator(const std::string& alphabet);
  std::vector<int> GetLookupVector();
  bool IsPartOfTheAlphabet(char character);
};
}
#endif //BIOLOOG_SRC_UTILS_INPUT_VALIDATION_ALPHABET_VALIDATORT_H_
