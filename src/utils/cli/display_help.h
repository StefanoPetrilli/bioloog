//
// Created by Stefano on 12/1/2022.
//

#ifndef BIOLOOG_SRC_UTILS_CLI_DISPLAY_HELP_H_
#define BIOLOOG_SRC_UTILS_CLI_DISPLAY_HELP_H_

#include <string>
#include <iostream>

#include "command_test.h"

namespace cli {

const std::string ascii_art = "`-:-.   ,-;\"`-:-.   ,-;\"`-:-.   ,-;\"`-:-.   ,-;\"\n"
                          "   `=`,'=/     `=`,'=/     `=`,'=/     `=`,'=/\n"
                          "     y==/        y==/        y==/        y==/\n"
                          "   ,=,-<=`.    ,=,-<=`.    ,=,-<=`.    ,=,-<=`.\n"
                          ",-'-'   `-=_,-'-'   `-=_,-'-'   `-=_,-'-'   `-=_\n";
const std::string program_name = "bioloog v0.0\n";
const std::string commands_intro = "The available commands are:\n";

void DisplayHelp();
}
#endif //BIOLOOG_SRC_UTILS_CLI_DISPLAY_HELP_H_
