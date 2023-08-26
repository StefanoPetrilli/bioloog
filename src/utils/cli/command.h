#pragma once

#include <iostream>
#include <list>
#include <stdexcept>
#include <string>
#include <unordered_map>

#include "count_nucleotides.h"
#include "dna_to_rna_transcription.h"
#include "find_consensus_and_profile.h"
#include "find_spliced_motif.h"
#include "find_shared_spliced_motif.h"
#include "format.h"
#include "inferring_mRna_from_protein.h"
#include "read_from_file.h"
#include "restriction_sites.h"
#include "rna_splicing.h"
#include "rna_to_protein_translation.h"

namespace cli {
class VirtualCommand {
 public:
  VirtualCommand(const std::string& name, const std::string& description);
  ~VirtualCommand() = default;

  void SetName(const std::string& name);
  void SetDescription(const std::string& description);
  static void ListPushBack(VirtualCommand* command);

  [[nodiscard]] std::string GetName() const;
  [[nodiscard]] std::string GetDescription() const;
  static std::list<VirtualCommand*> GetList();

  [[nodiscard]] std::string ToString() const;

  virtual void Exec(const std::string& path) = 0;

 private:
  std::string name_;
  std::string description_;
  static std::list<VirtualCommand*> list_;
};

class CountNucleotides : VirtualCommand {
 public:
  CountNucleotides(const std::string& name, const std::string& description)
      : VirtualCommand(name, description){};
  void Exec(const std::string& path) override;
};

class DnaToRnaTranscription : VirtualCommand {
 public:
  DnaToRnaTranscription(const std::string& name, const std::string& description)
      : VirtualCommand(name, description){};
  void Exec(const std::string& path) override;
};

class RnaToProteinTranslation : VirtualCommand {
 public:
  RnaToProteinTranslation(const std::string& name,
                          const std::string& description)
      : VirtualCommand(name, description){};
  void Exec(const std::string& path) override;
};

class FindMotif : VirtualCommand {
 public:
  FindMotif(const std::string& name, const std::string& description)
      : VirtualCommand(name, description){};
  void Exec(const std::string& path) override;
};

class FindSharedMotif : VirtualCommand {
 public:
  FindSharedMotif(const std::string& name, const std::string& description)
      : VirtualCommand(name, description){};
  void Exec(const std::string& path) override;
};

class FindConsensusAndProfile : VirtualCommand {
 public:
  FindConsensusAndProfile(const std::string& name,
                          const std::string& description)
      : VirtualCommand(name, description){};
  void Exec(const std::string& path) override;
};

class RestrictionSite : VirtualCommand {
 public:
  RestrictionSite(const std::string& name, const std::string& description)
      : VirtualCommand(name, description){};
  void Exec(const std::string& path) override;
};

class InferringmRna : VirtualCommand {
 public:
  InferringmRna(const std::string& name, const std::string& description)
      : VirtualCommand(name, description){};
  void Exec(const std::string& path) override;
};

class RnaSplicing : VirtualCommand {
 public:
  RnaSplicing(const std::string& name, const std::string& description)
      : VirtualCommand(name, description){};
  void Exec(const std::string& path) override;
};

class FindSplicedMotif : VirtualCommand {
 public:
  FindSplicedMotif(const std::string& name, const std::string& description)
      : VirtualCommand(name, description){};
  void Exec(const std::string& path) override;
};

class FindSharedSplicedMotif : VirtualCommand {
 public:
  FindSharedSplicedMotif(const std::string& name,
                         const std::string& description)
      : VirtualCommand(name, description){};
  void Exec(const std::string& path) override;
};
}  // namespace cli
