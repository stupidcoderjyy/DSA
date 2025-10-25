//
// Created by PC on 2025/10/25.
//

#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

auto Func(const std::vector<int>& vec) -> std::tuple<int, int, double> {
    auto [min, max] = std::minmax_element(vec.begin(), vec.end());
    auto avr = std::accumulate(vec.begin(), vec.end(), 0) / static_cast<double>(vec.size());
    return {*min, *max, avr};
}

int main() {
    std::tuple<int, std::string, double> t(1, "a", 1.5f);
    std::cout << std::get<0>(t) << " " << std::get<1>(t) << " " << std::get<2>(t) << '\n';
    const auto&[a1, a2, a3] = t;
    std::cout << a1 << " " << a2 << " " << a3 << '\n';

    const auto& [min, max, avr] = Func({1, 2, 3, 4});
    std::cout << min << " " << max << " " << avr << '\n';
 }
