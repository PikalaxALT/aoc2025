#include <charconv>
#include <ranges>
#include <string_view>
#include "aoc2025.hpp"

using namespace std::literals;

class Day1 : public aoc2025::Impl {
    std::vector<int> turns;
public:
    Day1 (const std::string &input) : aoc2025::Impl(input) {
        turns = std::string_view(input) |
            std::views::split("\n"sv) |
            std::views::transform([](const auto &line) -> int {
                int steps;
                std::string_view line_sv (line);
                std::from_chars(line.begin() + 1, line.end(), steps);
                if (line[0] == 'L') {
                    steps = -steps;
                }
                return steps;
            }) |
            std::ranges::to<std::vector>();
    }

    void part1 () final {
        int position = 50;
        int zeroCount = 0;
        for (int turn : turns) {
            position = (position + turn) % 100;
            zeroCount += (position == 0);
        }
        std::cout << zeroCount << std::endl;
    }

    void part2 () final {
        int position = 50;
        int zeroCount = 0;
        for (int turn : turns) {
            if (turn >= 0) {
                position += turn;
            } else {
                position = position ? 100 - position : 0;
                position -= turn;
            }
            auto [quot, rem] = std::div(position, 100);
            zeroCount += quot;
            if (turn >= 0) {
                position = rem;
            } else {
                position = rem ? 100 - rem : 0;
            }
        }
        std::cout << zeroCount << std::endl;
    }
};

int main () {
    aoc2025::main<Day1>();
}
