#include <iostream>
#include <vector>
#include <algorithm>

struct Edge {
    int from;
    int to;
    int cost;
};

int n;
std::vector <Edge> edges;
int parent[1001];

int Find(int idx) {
    if (idx == parent[idx]) {
        return idx;
    } else {
        return parent[idx] = Find(parent[idx]);
    }
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    parent[x] = y;
}

int solve() {
    int ans = 0;
    for (const Edge& edge : edges) {
        int x = Find(edge.from);
        int y = Find(edge.to);
        if (x == y) continue;
        Union(x, y);
        ans += edge.cost;
    }
    return ans;
}

int main() {
    int m;
    std::cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        std::cin >> from >> to >> cost;
        edges.push_back(Edge{from, to, cost});
    }

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    std::sort(edges.begin(), edges.end(),
              [](const Edge& e1, const Edge& e2) {
                  return e1.cost < e2.cost;
              });

    std::cout << solve() << '\n';
    return 0;
}
