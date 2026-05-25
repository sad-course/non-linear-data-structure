//
// Created by mirla on 21/10/2025.
//
#include <iostream>
#include  <vector>
#include <limits>
#include <queue>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include "utils.h"

int main() {
    const int INF = std::numeric_limits<int>::max();
    const int N=5;
    std::vector<std::vector<int>> validPaths;
    char printAllPaths;

    do {
        std::cout << "Do you want print all valid paths? (y/n)" << std::endl;
        std::cin >> printAllPaths;
    }while (std::tolower(printAllPaths) != 'y' && std::tolower(printAllPaths) != 'n');

    auto start = std::chrono::high_resolution_clock::now();

    std::vector<std::vector<int>> routes = {
        {0, 2, INF, 3, 6},
        {2, 0, 4, 3 , INF},
        {INF, 4, 0, 7, 3},
        {3, 3, 7, 0, 3},
        {6, INF, 3, 3, 0}
    };

    std::vector<int> cities;
    for (int i = 1; i < N; ++i) {cities.push_back(i);}

    int minCost = INF;
    std::vector<int> bestPath;

    do {
        int cost = 0;
        int currentCity = 0;
        bool valid = true;

        for (int nextCity: cities) {
            if (routes[currentCity][nextCity] == INF) {
                valid = false;
                break;
            }
            cost += routes[currentCity][nextCity];
            currentCity = nextCity;
        }

        if (valid && routes[currentCity][0] != INF) {
            cost += routes[currentCity][0];
        } else {
            valid = false;
        }

        if (valid) {
            std::vector<int> path = cities;
            path.push_back(cost);
            validPaths.push_back(path);
            if (cost < minCost) {
                minCost = cost;
                bestPath = cities;
            }
        }
    } while (std::next_permutation(cities.begin(), cities.end()));

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
    printFormattedElapsedTime(elapsedTime);

    if (minCost == INF) {
        std::cout << "No valid tour exists.\n";
    } else {
        std::cout << "Best path cost: " << minCost << "\nTour: 1 ";
        for (int city : bestPath) std::cout << "-> " << city + 1 << " ";
        std::cout << "-> 1\n";
    }
    if (!validPaths.empty() && std::tolower(printAllPaths) == 'y') {
        std::cout << "Valid Paths:" << std::endl;
        for (auto& city : validPaths) {
            std::cout << "1";
            for (size_t i = 0; i < city.size() - 1; ++i) {
                std::cout << " -> " << city[i] + 1;
            }

            int cost = city.back();
            std::cout << " -> 1 | Cost: " << cost << "\n";
        }
    }
    return 0;
}
