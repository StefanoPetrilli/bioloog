#pragma once

#include <gtest/gtest.h>

#include "dna_to_rna_transcription.h"
#include "read_from_file.h"

namespace dna_transcript_rna_test {
class DnaToRnaTranscriptionMultipleParametersNoTranslationTests
    : public ::testing::TestWithParam<std::tuple<std::string, std::string>> {
};

class DnaToRnaTranscriptionMultipleParametersTranslationTests :
    public ::testing::TestWithParam<std::tuple<std::string, std::string>> {
};
}
