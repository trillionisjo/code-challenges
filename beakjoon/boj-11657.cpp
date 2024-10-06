#include <iostream>

#define INF 0x7FFFFFFF

struct Edge {
    int from;
    int to;
    int cost;
};

int n, m;
Edge edges[6000];
long long dist[501];

int main() {
    std::cin >> n >> m;
    for (int i = 0; i < m; i++) {
        std::cin >> edges[i].from >> edges[i].to >> edges[i].cost;
    }

    dist[1] = 0;
    for (int i = 2; i <= n; i++) {
        dist[i] = INF;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int from = edges[j].from;
            int to = edges[j].to;
            int cost = edges[j].cost;
            if (dist[from] != INF && dist[from] + cost < dist[to]) {
                dist[to] = dist[from] + cost;
            }
        }
    }

    bool negative_cycle = false;
    for (int j = 0; j < m; j++) {
        int from = edges[j].from;
        int to = edges[j].to;
        int cost = edges[j].cost;
        if (dist[from] != INF && dist[from] + cost < dist[to]) {
            negative_cycle = true;
            break;
        }
    }

    if (negative_cycle) {
        std::cout << -1 << '\n';
        return 0;
    }

    for (int i = 2; i <= n; i++) {
        if (dist[i] == INF) dist[i] = -1;
        std::cout << dist[i] << '\n';
    }

    return 0;
}