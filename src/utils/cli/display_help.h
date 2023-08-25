#pragma once

#include <string>
#include <iostream>

#include "command.h"

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
