//
// Created by Stefano on 11/29/2022.
//

#include <stdexcept>
#include <iostream>
#include "countNucleotides.h"

namespace countNucleotides {
    std::array<int, 4> CountNucleotides(std::string const &DNA){

        std::array<int, 4> counting = {0, 0, 0, 0};

        for(char c : DNA) {
            switch (c) {
                default:
                    throw std::invalid_argument("An illegal character was inserted. Only 'A', 'C', 'G' and 'T' accepted.");
            }
        }

        return counting;
    }
}