#pragma once

#include <iostream>
#include <string>
#include <unordered_map>

namespace protein {
static const int kModule = 1000000;
static const char kStopCodon = '0';
static const std::unordered_map<char, int> kProteinToPossibleTranslation = {
    {'F', 2}, {'L', 6}, {'S', 6}, {'Y', 2}, {'0', 3}, {'C', 2}, {'W', 1},
    {'P', 4}, {'H', 2}, {'Q', 2}, {'R', 6}, {'I', 3}, {'M', 1}, {'T', 4},
    {'N', 2}, {'K', 2}, {'V', 4}, {'A', 4}, {'D', 2}, {'E', 2}, {'G', 4}};
unsigned int InferMRna(std::string &protein_sequence);
unsigned int SequentialInferMRna(const std::string &protein_sequence);
unsigned int GetPossibleTranslations(const char &protein);
#ifdef _OPENMP
unsigned int ParallelInferMRna(const std::string &protein_sequence);
#endif
}  // namespace protein
