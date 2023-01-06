//
// Created by Stefano on 12/11/2022.
//

#ifndef BIOLOOG_TEST_DNA_RNA_TO_PROTEIN_TRANSLATION_TEST_H_
#define BIOLOOG_TEST_DNA_RNA_TO_PROTEIN_TRANSLATION_TEST_H_
#include <gtest/gtest.h>

#include "rna_to_protein_translation.h"
#include "read_from_file.h"
#include "dna_to_rna_transcription.h"

namespace rna_to_protein_translation_test {
class RnaToProteinTranslationTestSingleProtein
    : public ::testing::TestWithParam<std::tuple<std::string, std::string>> {
};

class RnaToProteinTranslationTestMultipleProtein
    : public ::testing::TestWithParam<std::tuple<std::string, std::string>> {
};
}
#endif //BIOLOOG_TEST_DNA_RNA_TO_PROTEIN_TRANSLATION_TEST_H_
