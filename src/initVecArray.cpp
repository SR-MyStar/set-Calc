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
//===------ src/initVecArray.cpp - @initVecArray function definition -------===//

#include "initVecArray"

void initVecArray(std::string &list, std::pmr::vector<long double> &vec) {
    using std::format;
    std::regex spaceRegex{","};
    list = std::regex_replace(list, spaceRegex, " ");
    if (list.front() == ' ') {
        list.erase(list.begin());
    }
    if (list.back() == ' ') {
        list.pop_back();
    }

    std::smatch result;
    if (std::regex_match(list, result, std::regex{".*[^0-9 .].*"})) {
        std::cerr << std::format(
            "\033[31merror: \033[mInvalid character\n       {}\n       "
            "\033[31m",
            list);
        for (const auto &ch : list) {
            if (ch == ' ' || ch == '.') {
                std::cerr << ch;
                continue;
            }
            if (ch != '0' && ch != '1' && ch != '2' && ch != '3' && ch != '4'
                && ch != '5' && ch != '6' && ch != '7' && ch != '8'
                && ch != '9')
                std::cerr << '~';
        }
        std::cerr << "\n\033[m";
    }

    std::stringstream inputStream{list};
    long double       value;
    for ([[maybe_unused]] const auto &i :
         std::views::iota(0, std::count(list.begin(), list.end(), ' ') + 1)) {
        inputStream >> value;
        vec.emplace_back(value);
    }
    std::ranges::sort(vec);
}
