#include <iostream>
#include <vector>
#include <queue>

struct Edge {
    int to;
    int cost;
};

struct CompareEdge {
    bool operator() (const Edge& e1, const Edge& e2) const {
        return e1.cost > e2.cost;
    }
};

int n;
std::vector <Edge> nodes[1001];
bool visited[1001];

int solve() {
    std::priority_queue <Edge, std::vector <Edge>, CompareEdge> q;
    int ans = 0;

    visited[1] = true;
    for (const Edge& edge : nodes[1]) {
        q.push(edge);
    }

    while (!q.empty()) {
        int to = q.top().to;
        int cost = q.top().cost;
        q.pop();

        if (visited[to]) {
            continue;
        }

        ans += cost;
        visited[to] = true;

        for (const Edge& edge : nodes[to]) {
            q.push(edge);
        }
    }

    return ans;
}

int main() {
    int m;
    std::cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        std::cin >> from >> to >> cost;
        nodes[from].push_back(Edge{to, cost});
        nodes[to].push_back(Edge{from, cost});
    }

    std::cout << solve() << '\n';
    return 0;
}
