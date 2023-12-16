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
//===--------- src/numMath.cpp - The definition for math functions ---------===//
///
/// @file
/// This file defines some math functions,
/// They are: @code
///     void avgnum(std::pmr::vector<long double> &vec);
///     void minnum(std::pmr::vector<long double> &vec);
///     void midnum(std::pmr::vector<long double> &vec,
///                 const std::size_t             &sizeDividedByTwo);
///     void maxnum(std::pmr::vector<long double> &vec);
///     void rangenum(std::pmr::vector<long double> &vec);
///     void modenum(std::pmr::vector<long double> &vec);
///     void variance(std::pmr::vector<long double> &vec,
///                   const std::size_t             &sizeV);
/// @endcode
///
//===-----------------------------------------------------------------------===//

#include "numMath"

void avgnum(std::pmr::vector<long double> &vec) {
    using std::format;

    std::cout << format("Average number: {}\n",
                        std::accumulate(vec.begin(), vec.end(), 0.0l)
                            / vec.size());
}

void minnum(std::pmr::vector<long double> &vec) {
    using std::format;

    std::cout << format("Minimum number: {}\n", vec.front());
}

void midnum(std::pmr::vector<long double> &vec,
            const std::size_t             &sizeDividedByTwo) {
    using std::format;

    std::cout << format(
        "Median number: {}\n",
        vec.size() & 1
            ? vec[sizeDividedByTwo]
            : (vec[sizeDividedByTwo - 1] + vec[sizeDividedByTwo]) / 2);
}

void maxnum(std::pmr::vector<long double> &vec) {
    using std::format;

    std::cout << format("Maximum number: {}\n", vec.back());
}

void rangenum(std::pmr::vector<long double> &vec) {
    using std::format;

    std::cout << format("Range: {}\n", vec.back() - vec.front());
}

void modenum(std::pmr::vector<long double> &vec) {
    using std::format;

    auto &&opt = getModeNumber(vec);
    if (!opt.has_value()) {
        std::cout << "Mode number: none\n";
    }
    std::cout << format("Mode number: {}\n", opt.value());
}

void variance(std::pmr::vector<long double> &vec, const std::size_t &sizeV) {
    using std::format;

    auto &&avgN = std::accumulate(vec.begin(), vec.end(), 0.0l) / sizeV;
    auto   v    = vec;
    auto   res  = v | std::ranges::views::transform([&avgN](const auto &n) {
                   return (n - avgN) * (n - avgN);
               });
    std::cout << format("Variance: {}\n",
                        std::accumulate(res.begin(), res.end(), 0.0l) / avgN);
}
