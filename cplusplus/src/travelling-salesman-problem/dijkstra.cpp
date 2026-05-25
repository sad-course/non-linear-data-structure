//
// Created by mirla on 03/12/2025.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

const int INF = std::numeric_limits<int>::max();

using namespace std;

void dijkstra(const vector<vector<int>>& graph, int start, int end) {
    int n = graph.size();

    vector<int> dist(n, INF);
    vector<int> parent(n, -1);

    // Min-heap (distância, nó)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != INF) {
                int nd = d + graph[u][v];
                if (nd < dist[v]) {
                    dist[v] = nd;
                    parent[v] = u;
                    pq.push({nd, v});
                }
            }
        }
    }

    if (dist[end] == INF) {
        cout << "Não existe caminho entre " << start << " e " << end << "\n";
        return;
    }

    cout << "Distância mínima de " << start << " até " << end << ": " << dist[end] << "\n";


    vector<int> path;
    for (int v = end; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    cout << "Caminho: ";
    for (int v : path) cout << v << " ";
    cout << "\n";
}

int main() {
    const int INF = std::numeric_limits<int>::max();

    std::vector<std::vector<int>> routes_18 =
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

    dijkstra(routes_18, 0, 12);
}
