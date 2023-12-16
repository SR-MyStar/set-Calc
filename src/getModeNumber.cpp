//---------------------------- -*- C++ -*- ----------------------------===//
//
// Part of the set-Calc Project, under the GNU General Public License v3.0.
//
// See https://github.com/SR-MyStar/set-calc/blob/main/LICENSE
// for license information.
//
// SPDX-License-Identifier: GNU General Public License v3.0 only
//
//===--- src/getModeNumber.cpp - @getModeNumber function definition ---===//

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
