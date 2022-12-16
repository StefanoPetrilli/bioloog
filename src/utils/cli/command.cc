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
  std::array<int, 4> result = DNA::CountNucleotides(dna_sequence);
  std::cout << "A:" << result[0] << ", C:" << result[1] << ", G:" << result[2] << ", T: " << result[3] << std::endl;
}

void DnaToRnaTranscription::Exec(const std::string &path) {
  std::string dna_sequence;
  read_from_file::ReadFromFile(path, dna_sequence);
  std::string result = DNA::DnaToRnaTranscription(dna_sequence);
  std::cout << "The corresponding rna is: " << result << std::endl;
}

void RnaToProteinTranslation::Exec(const std::string &path) {
  std::string dna_sequence;
  read_from_file::ReadFromFile(path, dna_sequence);
  std::string result = DNA::RnaToProteinTranslation(dna_sequence);
  std::cout << "The protein translation is: " << result << std::endl;
}
}