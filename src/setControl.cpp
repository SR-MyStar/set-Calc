//===---------------------------- -*- C++ -*- ----------------------------===//
//
// Part of the set-Calc Project, under the GNU General Public License v3.0.
//
// See https://github.com/SR-MyStar/set-calc/blob/main/LICENSE
// for license information.
//
// SPDX-License-Identifier: GNU General Public License v3.0 only
//
//===--- src/setControl.cpp - The definition for set control functions ---===//
///
/// @file
/// This file define some math functions,
/// They are: @code
///     void size(std::pmr::vector<long double> &vec);
///     void showset(std::pmr::vector<long double> &vec);
///     void reset(std::pmr::vector<long double> &vec);
/// @endcode
///
//===---------------------------------------------------------------------===//

#include "setControl"

void size(std::pmr::vector<long double> &vec) {
    using std::format;

    std::cout << format("Size: {}\n", vec.size());
}

void showset(std::pmr::vector<long double> &vec) {
    using std::format;

    std::cout << format("[{}", vec.front());
    std::for_each(++vec.begin(), vec.end(),
                  [](const auto &val) { std::cout << format(", {}", val); });
    std::cout << "]\n";
}

void reset(std::pmr::vector<long double> &vec) {
    using std::format;

    std::cout << "Now, set is emptied\n";
    vec.clear();
}
