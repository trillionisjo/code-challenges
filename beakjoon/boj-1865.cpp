#include <iostream>

struct Edge {
    int from;
    int to;
    int cost;
};

int n, m, w;
Edge edges[5200];
int dist[501];

bool solve() {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 2 * m + w; j++) {
            int from = edges[j].from;
            int to = edges[j].to;
            int cost = edges[j].cost;

            if (dist[from] + cost < dist[to]) {
                dist[to] = dist[from] + cost;
            }
        }
    }

    bool negative_cycle = false;
    for (int j = 0; j < 2 * m + w; j++) {
        int from = edges[j].from;
        int to = edges[j].to;
        int cost = edges[j].cost;

        if (dist[from] + cost < dist[to]) {
            negative_cycle = true;
            break;
        }
    }

    return negative_cycle;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::cin >> n >> m >> w;

        for (int i = 1; i <= n; i++) {
            dist[i] = 0;
        }

        for (int i = 0; i < m; i++) {
            std::cin >> edges[i].from >> edges[i].to >> edges[i].cost;
            edges[i + m] = edges[i];
            std::swap(edges[i + m].from, edges[i + m].to);
        }

        for (int i = 2 * m; i < 2 * m + w; i++) {
            std::cin >> edges[i].from >> edges[i].to >> edges[i].cost;
            edges[i].cost *= -1;
        }

        bool ans = solve();
        std::cout << (ans ? "YES" : "NO") << '\n';
    }

    return 0;
}