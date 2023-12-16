//===----------------------------- -*- C++ -*- -----------------------------===//
//
// Copyright (c) 2023 Star. All Rights Reserved.
//
// This file is part of set-calc.
//
// set-calc is free software: you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the Free Software
// Foundation, either version 3 of the License, or (at your option) any later
// version.
//
// set-calc is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
// A PARTICULAR PURPOSE. See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along with
// set-calc. If not, see <https://www.gnu.org/licenses/>.
//
//===---------- src/main.cpp - Main file of the set-calc program -----------===//

#include "initVecArray"
#include "numMath"
#include "setControl"
#include <array>
#include <cstddef>
#include <format>
#include <iostream>
#include <memory_resource>
#include <regex>
#include <string>
#include <vector>

void help() {
    std::cout << "Commands:\n"
                 "------------------------------------------\n"
                 "  set(x1,x2,...,xn) - Set the set.\n"
                 "  minnum            - Print minimum number in the set.\n"
                 "  maxnum            - Print maximum number in the set.\n"
                 "  size              - Print the size of the set.\n"
                 "  showset           - Print the set.\n"
                 "  reset             - Clear the set.\n"
                 "  rangenum          - Print set range.\n"
                 "  midnum            - Print median number in the set.\n"
                 "  modenum           - Print mode number in the set.\n"
                 "  variance          - Print variance in the set.\n"
                 "  help              - Show the help.\n";
}

int main() {
    using std::format;

    std::ios::sync_with_stdio(0);

    std::array<std::byte, 1000000LL>    buf;
    std::pmr::monotonic_buffer_resource pool{buf.data(), buf.size()};
    std::pmr::vector<long double>       vec{&pool};

    std::regex  setFunctionRegex{"^set\\(.*\\)$"};
    std::smatch result;
    std::string input;
    std::size_t sizeDividedByTwo{0}, sizeV{0};
    while (1) {
        std::cout << ">>> ";
        std::getline(std::cin, input);

        if (input.empty()) continue;
        else if (input == "exit") break;
        else if (input == "help") help();
        else if (std::regex_match(input, result, setFunctionRegex)) {
            input.erase(input.begin(), input.begin() + 4);
            input.pop_back();
            initVecArray(input, vec);
            sizeDividedByTwo = vec.size() / 2;
            sizeV            = vec.size();
        } else if (vec.empty()) {
            std::cerr << "\033[31merror: \033[mSet is empty!\n";
            continue;
        } else if (input == "avgnum") avgnum(vec);
        else if (input == "minnum") minnum(vec);
        else if (input == "maxnum") maxnum(vec);
        else if (input == "size") size(vec);
        else if (input == "showset") showset(vec);
        else if (input == "reset") reset(vec);
        else if (input == "rangenum") rangenum(vec);
        else if (input == "midnum") midnum(vec, sizeDividedByTwo);
        else if (input == "modenum") modenum(vec);
        else if (input == "variance") variance(vec, sizeV);
        else std::cerr << "\033[31merror: \033[mCommand not found.\n";
    }
}
