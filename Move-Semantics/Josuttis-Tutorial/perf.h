#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <chrono>

class Perf
{
    std::chrono::steady_clock::time_point last;

public:
    Perf() {
        reset();
    }

    void reset() {
        last = std::chrono::steady_clock::now();
    }

    void diff(const std::string &msg = {}) {
        auto now = std::chrono::steady_clock::now();
        std::chrono::duration<double, std::milli> diff{now - last};
        std::cout << "\n====> " << msg << " "
                  << std::right << std::fixed << std::setprecision(2)
                  << std::setw(8) << diff.count() << "ms\n";
        reset();
    }
};