#!/usr/bin/env bash

set -euo pipefail

for i in {1..11}; do
    if ! [ -f src/aoc2025_${i}.cpp ]; then
        cat <<-EOF > src/aoc2025_${i}.cpp
#include "aoc2025.hpp"

class Day$i : public aoc2025::Impl {
public:
    Day$i (const std::string &input) : aoc2025::Impl(input) {}

    void part1 () final {}

    void part2 () final {}
};

int main () {
    aoc2025::main<Day$i>();
}
EOF
    fi
done
