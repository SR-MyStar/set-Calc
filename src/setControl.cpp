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
//===---- src/setControl.cpp - The definition for set control functions ----===//
///
/// @file
/// This file define some math functions,
/// They are: @code
///     void size(std::pmr::vector<long double> &vec);
///     void showset(std::pmr::vector<long double> &vec);
///     void reset(std::pmr::vector<long double> &vec);
/// @endcode
///
//===-----------------------------------------------------------------------===//

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
