//
// Created by Stefano on 12/25/2022.
//

#include "command_test.h"

namespace command_test {
TEST(Command, Expect_Throw_WhenInputsAreNotValid) {
  for (auto command : cli::VirtualCommand::GetList()) {
    std::string path = input_with_errors[command->GetName()];
    EXPECT_THROW(command->Exec(path), std::exception);
  }
}
}  // namespace command_test