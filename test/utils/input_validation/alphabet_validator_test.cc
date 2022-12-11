//
// Created by Stefano on 12/10/2022.
//
#include "alphabet_validator_test.h"

//TODO rewrite those tests more gracefully using parameters tests
namespace input_validation_test {
TEST(AlphabetValidator, InstantiateLookupTableProperly) {
  std::string alphabet = "ABC";
  char outside_of_alphabet = 'a';
  input_validation::AlphabetValidator test_validator = input_validation::AlphabetValidator(alphabet);
  for(char c : alphabet)
    EXPECT_EQ(test_validator.GetLookupVector().at(c), true);
  EXPECT_EQ(test_validator.GetLookupVector().at(outside_of_alphabet), false);
}

TEST(AlphabetValidator, IsPartOfTheAlphabet_ShouldWorkProperly) {
  std::string alphabet = "DEF";
  char outside_of_alphabet = 'a';
  input_validation::AlphabetValidator test_validator = input_validation::AlphabetValidator(alphabet);
  for(char c : alphabet)
    EXPECT_EQ(test_validator.IsPartOfTheAlphabet(c), true);
  EXPECT_EQ(test_validator.IsPartOfTheAlphabet(outside_of_alphabet), false);
}
}