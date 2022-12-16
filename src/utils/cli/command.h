//
// Created by Stefano on 12/2/2022.
//

#ifndef BIOLOOG_SRC_UTILS_CLI_COMMANDS_H_
#define BIOLOOG_SRC_UTILS_CLI_COMMANDS_H_

#include <string>
#include <unordered_map>
#include <stdexcept>
#include <list>
#include <iostream>

#include "file/read_from_file.h"
#include "count_nucleotides.h"
#include "dna_to_rna_transcription.h"
#include "rna_to_protein_translation.h"

namespace cli {

class VirtualCommand {

 public:
  //TODO where should I put the fields?
  std::string name_;
  std::string description_;

  static std::list<VirtualCommand *> list_;

  //TODO where should I put constructors and de-constructor?
  VirtualCommand(const std::string &name, const std::string &description) {
    this->SetName(name);
    this->SetDescription(description);
    list_.push_back(this);
  }
  ~VirtualCommand() = default;

  void SetName(const std::string &name);
  void SetDescription(const std::string &description);

  [[nodiscard]] std::string GetName() const;
  [[nodiscard]] std::string GetDescription() const;
  [[nodiscard]] std::string ToString() const;

  static std::list<VirtualCommand *> GetList();
  virtual void Exec(const std::string &path) = 0;
};

class CountNucleotides : VirtualCommand {
 public:
  CountNucleotides(const std::string &name, const std::string &description) : VirtualCommand(name,
                                                                                                    description) {};
  void Exec(const std::string &path) override;
};

class DnaToRnaTranscription : VirtualCommand {
 public:
  DnaToRnaTranscription(const std::string &name, const std::string &description) : VirtualCommand(name,
                                                                                                    description) {};
  void Exec(const std::string &path) override;
};

class RnaToProteinTranslation : VirtualCommand {
 public:
  RnaToProteinTranslation(const std::string &name, const std::string &description) : VirtualCommand(name,
                                                                                                    description) {};
  void Exec(const std::string &path) override;
};
}
#endif //BIOLOOG_SRC_UTILS_CLI_COMMANDS_H_
