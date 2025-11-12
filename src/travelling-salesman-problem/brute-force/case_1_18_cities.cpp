//
// Created by mirla on 11/11/2025.
//
#include <iostream>
#include  <vector>
#include <limits>
#include <queue>
#include <algorithm>
#include <chrono>

#include "utils.h"


int main() {
    const int N=18;

    const int INF = std::numeric_limits<int>::max();
    std::vector<std::vector<int>> validPaths;
    std::vector<std::vector<int>> routes =
        {
        {0, 20, INF, INF, INF, INF, INF, 29, INF, INF, INF, 29, 37, INF, INF, INF, INF, INF},
        {20, 0, 25, INF, INF, INF, INF, 28, INF, INF, INF, 39, INF, INF, INF, INF, INF, INF},
        {INF, 25, 0, 25, INF, INF, INF, 30, INF, INF, INF, INF, 54, INF, INF, INF, INF, INF},
        {INF, INF, 25, 0, 39, 32, 42, INF, 23, 33, INF, INF, INF, 56, INF, INF, INF, INF},
        {INF, INF, INF, 39, 0, 12, 26, INF, INF, 19, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, 32, 12, 0, 17, INF, INF, 35, 30, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, 42, 26, 17, 0, INF, INF, INF, 38, INF, INF, INF, INF, INF, INF, INF},
        {29, 28, 30, INF, INF, INF, INF, 0, INF, INF, INF, 25, 22, INF, INF, INF, INF, INF},
        {INF, INF, INF, 23, INF, INF, INF, INF, 0, 26, INF, INF, 34, INF, INF, 43, INF, INF},
        {INF, INF, INF, 33, 19, 35, INF, INF, 26, 0, 24, INF, INF, 30, 19, INF, INF, INF},
        {INF, INF, INF, INF, INF, 30, 38, INF, INF, 24, 0, INF, INF, INF, 26, INF, INF, 36},
        {29, 39, INF, INF, INF, INF, INF, 25, INF, INF, INF, 0, 27, INF, INF, 43, INF, INF},
        {INF, INF, 54, INF, INF, INF, INF, 22, 34, INF, INF, 27, 0, 24, INF, 19, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, 30, INF, INF, 24, 0, 20, 19, 17, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, 19, 26, INF, INF, 20, 0, INF, 18, 21},
        {INF, INF, INF, INF, INF, INF, INF, INF, 43, INF, INF, 43, 19, 19, INF, 0, 26, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 17, 18, 26, 0, 15},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 36, INF, INF, INF, 21, INF, 15, 0}
    };

    std::vector<int> cities;
    for (int i = 1; i < N; ++i) {cities.push_back(i);}

    int minCost = INF;
    std::vector<int> bestPath;

    do {
        int cost = 0;
        int currentCity = 0;
        bool valid = true;

        for (int nextCity : cities) {
            if (routes[currentCity][nextCity] == INF) {
                valid = false;
                break;
            }
            cost += routes[currentCity][nextCity];
            if (cost >= minCost) {
                valid = false;
                break;
            }
            currentCity = nextCity;
        }

        if (valid && routes[currentCity][0] != INF) {
            cost += routes[currentCity][0];
        } else {
            valid = false;
        }

        if (valid) {
            validPaths.push_back(cities);
            if (cost < minCost) {
                minCost = cost;
                bestPath = cities;
            }
        }

    } while (std::next_permutation(cities.begin(), cities.end()));


    if (minCost == INF) {
        std::cout << "No valid tour exists.\n";
    } else {
        std::cout << "Minimum cost: " << minCost << "\nTour: 1 ";
        for (int city : bestPath) std::cout << "-> " << city + 1 << " ";
        std::cout << "-> 1\n";
    }
    if (!validPaths.empty()) {
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
