#include <iostream>
#include <vector>
#include <cstring>

#define INF 0x7FFFFFFF

struct Edge {
    int to;
    int cost;
};

int n, m;
std::vector <Edge> edge[1001];
int dist[1001];
bool visited[1001];

int dijkstra(int start, int end) {
    dist[start] = 0;

    for (int i = 1; i <= n - 1; i++) {
        int min_idx = -1;

        for (int j = 1; j <= n; j++) {
            if (visited[j]) {
                continue;
            }
            if (min_idx == -1 || dist[j] < dist[min_idx]) {
                min_idx = j;
            }
        }

        visited[min_idx] = true;

        for (Edge& e : edge[min_idx]) {
            if (visited[e.to]) {
                continue;
            }
            if (dist[min_idx] + e.cost < dist[e.to]) {
                dist[e.to] = dist[min_idx] + e.cost;
            }
        }
    }

    return dist[end];
}

int main() {
    std::cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        std::cin >> from >> to >> cost;
        edge[from].push_back(Edge{to, cost});
    }

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }

    int start, end;
    std::cin >> start >> end;
    std::cout << dijkstra(start, end) << '\n';

    return 0;
}