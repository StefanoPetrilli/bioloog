//
// Created by Stefano on 1/15/2023.
//

#ifndef BIOLOOG_SRC_DNA_RNA_SPLICING_H_
#define BIOLOOG_SRC_DNA_RNA_SPLICING_H_

#include <map>
#include <string>
#include <iostream>
#include "dna_to_rna_transcription.h"
#include "rna_to_protein_translation.h"
namespace DNA {
std::string RnaSplicing(const std::map<std::string, std::string> &sequences);
std::string GetLonger(const std::map<std::string, std::string> &sequences);
}
#endif //BIOLOOG_SRC_DNA_RNA_SPLICING_H_
