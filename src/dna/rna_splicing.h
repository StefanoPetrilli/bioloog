#pragma once

#include <unordered_map>
#include <string>
#include <iostream>

#include "dna_to_rna_transcription.h"
#include "rna_to_protein_translation.h"
namespace DNA {
std::string RnaSplicing(const std::unordered_map<std::string, std::string> &sequences);
std::string GetLonger(const std::unordered_map<std::string, std::string> &sequences);
}
