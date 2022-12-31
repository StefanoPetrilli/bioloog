//
// Created by Stefano on 12/2/2022.
//

#include "command.h"

namespace cli {
std::list<cli::VirtualCommand *> cli::VirtualCommand::list_;

VirtualCommand::VirtualCommand(const std::string &name, const std::string &description) {
  this->SetName(name);
  this->SetDescription(description);
  ListPushBack(this);
}

void VirtualCommand::SetName(const std::string &name) {
  this->name_ = name;
}

void VirtualCommand::SetDescription(const std::string &description) {
  this->description_ = description;
}

void VirtualCommand::ListPushBack(VirtualCommand *command) {
  list_.push_back(command);
}

std::string VirtualCommand::GetName() const {
  return this->name_;
}

std::string VirtualCommand::GetDescription() const {
  return this->description_;
}

std::list<VirtualCommand *> VirtualCommand::GetList() {
  return list_;
}

std::string VirtualCommand::ToString() const {
  return GetName() + " : " + GetDescription();
}

void CountNucleotides::Exec(const std::string &path) {
  std::string dna_sequence;
  read_from_file::ReadFromFile(path, dna_sequence);

  input_validation::kStandardValidatorDna.IsPartOfTheAlphabet(dna_sequence);

  std::array<int, 4> result = DNA::CountNucleotides(dna_sequence);
  std::cout << "A:" << result[0] << ", C:" << result[1] << ", G:" << result[2] << ", T: " << result[3] << std::endl;
}

void DnaToRnaTranscription::Exec(const std::string &path) {
  std::string dna_sequence;
  read_from_file::ReadFromFile(path, dna_sequence);

  input_validation::kStandardValidatorDna.IsPartOfTheAlphabet(dna_sequence);

  std::string result = DNA::DnaToRnaTranscription(dna_sequence);
  std::cout << "The corresponding rna is: " << result << std::endl;
}

void RnaToProteinTranslation::Exec(const std::string &path) {
  std::string dna_sequence;
  read_from_file::ReadFromFile(path, dna_sequence);

  input_validation::kStandardValidatorDna.IsPartOfTheAlphabet(dna_sequence);

  std::string result = DNA::RnaToProteinTranslation(dna_sequence);
  std::cout << "The protein translation is: " << result << std::endl;
}

void FindMotif::Exec(const std::string &path) {
  std::string file_content;
  read_from_file::ReadFromFile(path, file_content);

  int newline_position = file_content.find(read_from_file::kNewLine);
  std::string dna_sequence = read_from_file::RemoveEscapeCharacter(file_content.substr(0, newline_position));
  std::string motif_starting_with_newline = file_content.substr(newline_position);
  std::string motif = read_from_file::RemoveEscapeCharacter(motif_starting_with_newline);

  input_validation::kStandardValidatorDna.IsPartOfTheAlphabet(dna_sequence);
  input_validation::kStandardValidatorDna.IsPartOfTheAlphabet(motif);

  std::list<int> result = DNA::FindMotif(dna_sequence, motif);
  std::cout << "The motif positions are: ";
  for (auto i : result) {
    std::cout << i + 1 << " ";
  }
  std::cout << std::endl;
}

void FindSharedMotif::Exec(const std::string &path) {
  std::string file_content;
  auto map = read_from_file::ReadFastaFromFile(path);

  for (auto dna_sequence : map) {
    input_validation::kStandardValidatorDna.IsPartOfTheAlphabet(dna_sequence.second);
  }

  std::string result = DNA::FindSharedMotif(map);
  std::cout << result << std::endl;
}

void FindConsensusAndProfile::Exec(const std::string &path) {
  std::string file_content;
  auto map = read_from_file::ReadFastaFromFile(path);

  for (auto dna_sequence : map) {
    input_validation::kStandardValidatorDna.IsPartOfTheAlphabet(dna_sequence.second);
  }

  auto result = DNA::FindConsensusAndProfile(map);
  std::cout << std::get<0>(result) << '\n' << DNA::ProfileToString(std::get<1>(result)) << std::endl;
}

static const cli::CountNucleotides kCountNucleotides = CountNucleotides("count_nucleotides",
                                                                        "Takes a DNA string and returns the counting of each nucleotides in the format {'A', 'C', 'T', 'G}");
static const cli::DnaToRnaTranscription kDnaToRnaTranscription = DnaToRnaTranscription("dna_to_rna_translation",
                                                                                       "Takes a DNA string and returnsthe rna transcription");
static const cli::RnaToProteinTranslation kToProteinTranslation = RnaToProteinTranslation("rna_to_protein_translation",
                                                                                          "Takes a RNA string and returnsthe proteins translation");
static const cli::FindMotif kFindMotif = FindMotif("find_motif",
                                                   "Takes a DNA sequence, a motif and return the positions of the motif in the dna sequence");
static const cli::FindSharedMotif kFindSharedMotif = FindSharedMotif("find_shared_motif",
                                                                     "Takes multiple DNA sequences, and return the longest common motif");
static const cli::FindConsensusAndProfile kFindConsensusAndProfile = FindConsensusAndProfile("find_consensus_and_profile",
                                                                     "Takes multiple DNA sequences, and return consensus and profile");
}