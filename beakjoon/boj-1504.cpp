#include <iostream>
#include <vector>
#include <queue>

const int INF = 0x7fffffff;

struct Edge {
    int to;
    int cost;
};

int n, m;
int dists[801];
std::vector <Edge> edges[801];
bool visited[801];
int v1, v2;

int add(int a, int b, int c) {
    if (a == INF || b == INF || c == INF) {
        return INF;
    }
    return a + b + c;
}

std::vector <int> dijkstra(int start) {
    for (int i = 1; i <= n; i++) {
        dists[i] = INF;
        visited[i] = false;
    }

    std::priority_queue <std::pair <int, int>, std::vector <std::pair <int, int>>, std::greater <std::pair <int, int>>> q;
    dists[start] = 0;
    q.push(std::make_pair(0, start));

    while (!q.empty()) {
        int dist = q.top().first;
        int vertex = q.top().second;
        q.pop();
        
        if (visited[vertex]) {
            continue;
        }
        visited[vertex] = true;

        for (const Edge& e : edges[vertex]) {
            if (dists[e.to] <= e.cost + dist) {
                continue;
            }
            dists[e.to] = e.cost + dist;
            q.push(std::make_pair(dists[e.to], e.to));
        }
    }

    return std::vector <int>(dists, dists + n + 1);
}

int main() {
    std::cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        std::cin >> from >> to >> cost;
        edges[from].push_back(Edge{to, cost});
        edges[to].push_back(Edge{from, cost});
    }
    std::cin >> v1 >> v2;

    std::vector <int> dstart = dijkstra(1);
    std::vector <int> d1 = dijkstra(v1);
    std::vector <int> d2 = dijkstra(v2);

    int ans1 = add(dstart[v1], d1[v2], d2[n]);
    int ans2 = add(dstart[v2], d2[v1], d1[n]);

    int ans = std::min(ans1, ans2);
    std::cout << (ans == INF ? -1 : ans) << '\n';
    return 0;
}