//
// Created by Stefano on 12/11/2022.
//

#ifndef BIOLOOG_TEST_DNA_DNA_TO_RNA_TRANSCRIPTION_TEST_H_
#define BIOLOOG_TEST_DNA_DNA_TO_RNA_TRANSCRIPTION_TEST_H_
#include <gtest/gtest.h>
#include "../../src/DNA/dna_to_rna_transcription.h"
#include "../../src/utils/file/read_from_file.h"

namespace dna_transcript_rna_test {
class DnaToRnaTranscriptionMultipleParametersNoTranslationTests
    : public ::testing::TestWithParam<std::tuple<std::string, std::string>> {
};

class DnaToRnaTranscriptionMultipleParametersTranslationTests :
    public ::testing::TestWithParam<std::tuple<std::string, std::string>> {
};
}
#endif //BIOLOOG_TEST_DNA_DNA_TO_RNA_TRANSCRIPTION_TEST_H_
