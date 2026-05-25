//
// Created by mirla on 12/11/2025.
//
#include <chrono>
#include <iomanip>
#include <iostream>

#ifndef NON_LINEAR_DATA_STRUCTURE_UTILS_H
#define NON_LINEAR_DATA_STRUCTURE_UTILS_H

void printFormattedElapsedTime(std::chrono::duration<double> elapsedTime) {
    using namespace std::chrono;

    auto elapsed_us = duration_cast<microseconds>(elapsedTime);
    auto elapsed_ms = duration_cast<milliseconds>(elapsedTime);

    if (elapsed_us.count() < 1000) {
        std::cout << "Elapsed time: " << elapsed_us.count() << " µs (microseconds)\n";
    }
    else if (elapsed_ms.count() < 1000) {
        std::cout << "Elapsed time: " << elapsed_ms.count() << " ms (milliseconds)\n";
    }
    else {
        double elapsed = elapsedTime.count();
        int hours = static_cast<int>(elapsed / 3600);
        int minutes = static_cast<int>((static_cast<int>(elapsed) % 3600) / 60);
        int seconds = static_cast<int>(elapsed) % 60;
        int milliseconds = static_cast<int>((elapsed - static_cast<int>(elapsed)) * 1000);

        std::cout << "Elapsed time: "
                  << std::setfill('0') << std::setw(2) << hours << ":"
                  << std::setw(2) << minutes << ":"
                  << std::setw(2) << seconds << "."
                 << std::setw(3) << milliseconds << '\n';
    }
}
#endif //NON_LINEAR_DATA_STRUCTURE_UTILS_H

