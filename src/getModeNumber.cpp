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
//===----- src/getModeNumber.cpp - @getModeNumber function definition ------===//

#include "getModeNumber"

std::optional<long double> getModeNumber(std::pmr::vector<long double> &vec) {
    if (vec.size() == 0) {
        return std::nullopt;
    }
    std::map<long double, std::size_t> setMap;
    for (const auto &num : vec) {
        ++setMap[num];
    }
    auto max = std::max_element(setMap.begin(), setMap.end(),
                                [](std::pair<long double, std::size_t> a,
                                   std::pair<long double, std::size_t> b) {
                                    return a.second < b.second;
                                });
    for (auto it = setMap.begin(); it != setMap.end(); ++it) {
        if (it->second == max->second && it->first != max->first) {
            return std::nullopt;
        }
    }
    return max->first;
}
