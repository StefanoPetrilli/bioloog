#include "alphabet_validator.h"

#include <gtest/gtest.h>

// TODO(stefanopetrilli): rewrite those tests more gracefully using parameters
// testsg parameters tests
namespace input_validation_test {
TEST(AlphabetValidator, InstantiateLookupTableProperly) {
  std::string alphabet = "ABC";
  char outside_of_alphabet = 'a';

  input_validation::AlphabetValidator test_validator =
      input_validation::AlphabetValidator(alphabet, "");

  for (char c : alphabet)
    EXPECT_EQ(test_validator.GetLookupVector().at(c), true);

  EXPECT_EQ(test_validator.GetLookupVector().at(outside_of_alphabet), false);
}

TEST(AlphabetValidator, IsStringPartOfTheAlphabetShouldWorkProperly) {
  std::string alphabet = "DEF";
  char outside_of_alphabet = 'a';

  input_validation::AlphabetValidator test_validator =
      input_validation::AlphabetValidator(alphabet, "");

  for (char c : alphabet)
    EXPECT_EQ(test_validator.IsPartOfTheAlphabet(c), true);

  EXPECT_EQ(test_validator.IsPartOfTheAlphabet(outside_of_alphabet), false);
}

TEST(AlphabetValidator, IsStringPartOfTheAlphabetShouldNotThrow) {
  std::string alphabet = "DEF";
  std::string outside_of_alphabet = "DEFDEFDEFFEDFED";

  input_validation::AlphabetValidator test_validator =
      input_validation::AlphabetValidator(alphabet, "");

  EXPECT_NO_THROW(test_validator.IsPartOfTheAlphabet(outside_of_alphabet));
}

TEST(AlphabetValidator, IsStringPartOfTheAlphabetShouldThrow) {
  std::string alphabet = "DEF";
  std::string outside_of_alphabet = "a";

  input_validation::AlphabetValidator test_validator =
      input_validation::AlphabetValidator(alphabet, "");

  EXPECT_THROW(test_validator.IsPartOfTheAlphabet(outside_of_alphabet),
               std::invalid_argument);
}
}  // namespace input_validation_test