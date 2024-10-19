#include <iostream>
#include <vector>
#include <queue>

const int INF = 0x7fffffff;

struct Edge {
    int to;
    int cost;
};

int n, m;
std::vector <Edge> adj[501];
long long dist[501];
int check[501];
int count[501];

int spfa() {
    std::queue <int> q;
    q.push(1);
    check[1] = true;

    while (!q.empty()) {
        int from = q.front(); q.pop();
        check[from] = false;
        
        for (const Edge& e : adj[from]) {
            if (dist[e.to] <= dist[from] + e.cost) {
                continue;
            }

            dist[e.to] = dist[from] + e.cost;

            if (check[e.to]) {
                continue;
            }
            
            q.push(e.to);
            check[e.to] = true;
            count[e.to] += 1;

            if (count[e.to] >= n) {
                return -1;
            }
        }
    }

    return 0;
}

int main() {
    std::cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int from, to, cost;
        std::cin >> from >> to >> cost;
        adj[from].push_back(Edge{to, cost});
    }

    for (int i = 2; i <= n; i++) {
        dist[i] = INF;
    }

    if (spfa() == -1) {
        std::cout << -1;
        return 0;
    }

    for (int i = 2; i <= n; i++) {
        std::cout << (dist[i] == INF ? -1 : dist[i]) << '\n';
    }
    
    return 0;
}