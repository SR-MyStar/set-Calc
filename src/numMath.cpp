//===--------------------------- -*- C++ -*- ---------------------------===//
//
// Part of the set-Calc Project, under the GNU General Public License v3.0.
//
// See https://github.com/SR-MyStar/set-calc/blob/main/LICENSE
// for license information.
//
// SPDX-License-Identifier: GNU General Public License v3.0 only
//
//===------ src/numMath.cpp - The definition for math functions --------===//
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
//===-------------------------------------------------------------------===//

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
