//
// Created by Stefano on 12/2/2022.
//

#include "command.h"

namespace cli {
std::list<cli::VirtualCommand*> cli::VirtualCommand::list_;

VirtualCommand::VirtualCommand(const std::string& name,
                               const std::string& description) {
  this->SetName(name);
  this->SetDescription(description);
  ListPushBack(this);
}

void VirtualCommand::SetName(const std::string& name) { this->name_ = name; }

void VirtualCommand::SetDescription(const std::string& description) {
  this->description_ = description;
}

void VirtualCommand::ListPushBack(VirtualCommand* command) {
  list_.push_back(command);
}

std::string VirtualCommand::GetName() const { return this->name_; }

std::string VirtualCommand::GetDescription() const {
  return this->description_;
}

std::list<VirtualCommand*> VirtualCommand::GetList() { return list_; }

std::string VirtualCommand::ToString() const {
  return GetName() + " : " + GetDescription();
}

void CountNucleotides::Exec(const std::string& path) {
  std::string dna_sequence;
  file::ReadFromFile(path, dna_sequence);

  input_validation::kStandardValidatorDna.IsPartOfTheAlphabet(dna_sequence);

  std::array<int, 4> result = dna::CountNucleotides(dna_sequence);
  std::cout << "A:" << result[0] << ", C:" << result[1] << ", G:" << result[2]
            << ", T: " << result[3] << std::endl;
}

void DnaToRnaTranscription::Exec(const std::string& path) {
  std::string dna_sequence;
  file::ReadFromFile(path, dna_sequence);

  input_validation::kStandardValidatorDna.IsPartOfTheAlphabet(dna_sequence);

  std::string result = dna::DnaToRnaTranscription(dna_sequence);
  std::cout << "The corresponding rna is: " << result << std::endl;
}

void RnaToProteinTranslation::Exec(const std::string& path) {
  std::string rna_sequence;
  file::ReadFromFile(path, rna_sequence);

  input_validation::kStandardValidatorRna.IsPartOfTheAlphabet(rna_sequence);

  std::string result = dna::RnaToProteinTranslation(rna_sequence);
  std::cout << "The protein translation is: " << result << std::endl;
}

void FindMotif::Exec(const std::string& path) {
  std::string file_content;
  file::ReadFromFile(path, file_content);

  int newline_position = file_content.find(file::kNewLine);
  std::string dna_sequence =
      file::RemoveEscapeCharacter(file_content.substr(0, newline_position));
  std::string motif_starting_with_newline =
      file_content.substr(newline_position);
  std::string motif = file::RemoveEscapeCharacter(motif_starting_with_newline);

  input_validation::kStandardValidatorDna.IsPartOfTheAlphabet(dna_sequence);
  input_validation::kStandardValidatorDna.IsPartOfTheAlphabet(motif);

  std::list<int> result = dna::FindMotif(dna_sequence, motif);
  std::cout << "The motif positions are: ";
  for (auto i : result) {
    std::cout << i + 1 << " ";
  }
  std::cout << std::endl;
}

void FindSharedMotif::Exec(const std::string& path) {
  std::string file_content;
  auto map = file::ReadFastaFromFile(path);

  for (const auto& dna_sequence : map) {
    input_validation::kStandardValidatorDna.IsPartOfTheAlphabet(
        dna_sequence.second);
  }

  std::string result = dna::FindSharedMotif(map);
  std::cout << result << std::endl;
}

void FindConsensusAndProfile::Exec(const std::string& path) {
  std::string file_content;
  auto map = file::ReadFastaFromFile(path);

  for (const auto& dna_sequence : map) {
    input_validation::kStandardValidatorDna.IsPartOfTheAlphabet(
        dna_sequence.second);
  }

  auto result = dna::FindConsensusAndProfile(map);
  std::cout << std::get<0>(result) << '\n'
            << dna::ProfileToString(std::get<1>(result)) << std::endl;
}

void RestrictionSite::Exec(const std::string& path) {
  std::string file_content;
  auto map = file::ReadFastaFromFile(path);

  for (const auto& dna_sequence : map) {
    input_validation::kStandardValidatorDna.IsPartOfTheAlphabet(
        dna_sequence.second);
  }

  auto result = dna::RestrictionSites(map.begin()->second);
  std::cout << dna::Format(result) << std::endl;
}

void InferringmRna::Exec(const std::string& path) {
  std::string protein_sequence;
  file::ReadFromFile(path, protein_sequence);

  input_validation::kStandardValidatorProtein.IsPartOfTheAlphabet(
      protein_sequence);

  std::cout << protein::InferMRna(protein_sequence) << std::endl;
}

void RnaSplicing::Exec(const std::string& path) {
  std::string file_content;
  auto map = file::ReadFastaFromFile(path);

  for (const auto& dna_sequence : map) {
    input_validation::kStandardValidatorDna.IsPartOfTheAlphabet(
        dna_sequence.second);
  }

  auto result = dna::RnaSplicing(map);
  std::cout << "The result is: " << result << std::endl;
}

void FindSplicedMotif::Exec(const std::string& path) {
  std::string file_content;
  auto pair = file::ReadFastaPairFromFile(path);

  input_validation::kStandardValidatorDna.IsPartOfTheAlphabet(pair.first);
  input_validation::kStandardValidatorDna.IsPartOfTheAlphabet(pair.second);

  auto result = dna::FindSplicedMotif(pair);
  auto formatted_result = format::ToString(result);
  std::cout << "The result is: " << formatted_result << std::endl;
}

void FindSharedSplicedMotif::Exec(const std::string& path) {
  std::string file_content;
  auto pair = file::ReadFastaPairFromFile(path);

  input_validation::kStandardValidatorDna.IsPartOfTheAlphabet(pair.first);
  input_validation::kStandardValidatorDna.IsPartOfTheAlphabet(pair.second);

  auto result = dna::FindSharedSplicedMotif(pair);
  std::cout << "The result is: " << result << std::endl;
}

void EditDistance::Exec(const std::string& path) {
  std::string file_content;
  auto pair = file::ReadFastaPairFromFile(path);

  input_validation::kStandardValidatorProtein.IsPartOfTheAlphabet(pair.first);
  input_validation::kStandardValidatorProtein.IsPartOfTheAlphabet(pair.second);

  auto result = protein::EditDistance(pair);
  std::cout << "The result is: " << result << std::endl;
}

static const cli::CountNucleotides kCountNucleotides =
    CountNucleotides("count_nucleotides",
                     "Takes a dna string and returns the counting of each "
                     "nucleotides in the format {'A', 'C', 'T', 'G}");

static const cli::DnaToRnaTranscription kDnaToRnaTranscription =
    DnaToRnaTranscription(
        "dna_to_rna_translation",
        "Takes a dna string and returnsthe rna transcription");

static const cli::RnaToProteinTranslation kToProteinTranslation =
    RnaToProteinTranslation(
        "rna_to_protein_translation",
        "Takes a RNA string and returnsthe proteins translation");

static const cli::FindMotif kFindMotif =
    FindMotif("find_motif",
              "Takes a dna sequence, a motif and return the positions of the "
              "motif in the dna sequence");

static const cli::FindSharedMotif kFindSharedMotif = FindSharedMotif(
    "find_shared_motif",
    "Takes multiple dna sequences, and return the longest common motif");

static const cli::FindConsensusAndProfile kFindConsensusAndProfile =
    FindConsensusAndProfile(
        "find_consensus_and_profile",
        "Takes multiple dna sequences, and return consensus and profile");

static const cli::RestrictionSite kRestrictionSite =
    RestrictionSite("restriction_site",
                    "Take a dna string in FASTA format and return the position "
                    "of restriction sites.");

static const cli::InferringmRna kInferringmRna =
    InferringmRna("infer_possible_mRna",
                  "Take a protein sequence and returns the number of possible "
                  "RNA sequence that could have generated that sequence");

static const cli::RnaSplicing kRnaSplicing = RnaSplicing(
    "rna_splicing",
    "Takes a dna sequence and exons in FASTA format, returns the protein "
    "string resulting from ranscribing and translating the exons");

static const cli::FindSplicedMotif kFindSplicedMotif = FindSplicedMotif(
    "find_spliced_motif",
    "Takes a dna sequence and a motif in fasta format and returns a collection "
    "of indices that correspond to the position of the element of the motif");

static const cli::FindSharedSplicedMotif kFindSharedSplicedMotif =
    FindSharedSplicedMotif(
        "find_shared_spliced_motif",
        "Takes two dna sequence and find the longest shared spliced motif");

static const cli::EditDistance kEditDistance = EditDistance(
    "edit_distance", "Find a the edit distance between two protein strings.");
}  // namespace cli
