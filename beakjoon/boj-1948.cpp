#include <iostream>
#include <vector>
#include <queue>

struct Edge {
    int to;
    int cost;
};

int n, m;
int dist[10001];
int indg[10001];
std::vector <Edge> adj1[10001];
std::vector <Edge> adj2[10001];
int start, end;
bool visited[10001];

std::pair <int, int> solve() {
    std::queue <int> q;
    q.push(start);

    while (!q.empty()) {
        int from = q.front(); q.pop();
        for (const Edge& e : adj1[from]) {
            if (dist[e.to] < dist[from] + e.cost) {
                dist[e.to] = dist[from] + e.cost;
            }
            indg[e.to] -= 1;
            if (indg[e.to] == 0) {
                q.push(e.to);
            }
        }
    }

    int count = 0;
    q.push(end);

    while (!q.empty()) {
        int from = q.front(); q.pop();
        for (const Edge& e : adj2[from]) {
            if (e.cost != dist[from] - dist[e.to]) {
                continue;
            }
            count += 1;
            if (visited[e.to]) {
                continue;
            }
            visited[e.to] = true;
            q.push(e.to);
        }
    }

    return std::make_pair(dist[end], count);
}

int main() {
    std::cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        std::cin >> from >> to >> cost;
        adj1[from].push_back(Edge{to, cost});
        adj2[to].push_back(Edge{from, cost});
        indg[to] += 1;
    }
    std::cin >> start >> end;

    auto ans = solve();
    std::cout << ans.first << '\n' << ans.second << '\n';
    return 0;
}