#include <iostream>
#include <vector>
#include <queue>

#define INF 0x7FFFFFFF

struct Edge {
    int to;
    int cost;
};

int n, m;
std::vector <Edge> edge[20001];
int dist[20001];
bool visited[20001];

void dijkstra(int start) {
    std::priority_queue <std::pair <int, int>, std::vector <std::pair <int, int>>, std::greater <std::pair <int, int>>> q; // MinHeap
    q.push(std::make_pair(0, start));
    dist[start] = 0;

    while (!q.empty()) {
        int d = q.top().first;
        int idx = q.top().second;
        q.pop();

        if (visited[idx]) {
            continue;
        }
        visited[idx] = true;

        for (Edge& e : edge[idx]) {
            if (dist[e.to] <= d + e.cost) {
                continue;
            }
            dist[e.to] = d + e.cost;
            q.push(std::make_pair(dist[e.to], e.to));
        }
    }
}

int main() {
    int start;

    std::cin >> n >> m;
    std::cin >> start;

    for (int i = 0; i < m; i++) {
        int from, to, cost;
        std::cin >> from >> to >> cost;
        edge[from].push_back(Edge{to, cost});
    }

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }

    dijkstra(start);

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            std::cout << "INF" << '\n';
        } else {
            std::cout << dist[i] << '\n';
        }
    }

    return 0;
}