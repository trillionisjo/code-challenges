#include <iostream>
#include <vector>

int n;
int hour[10001];
std::vector <int> neighbors[10001];
bool visited[10001];

int dfs(int idx) {
    if (visited[idx]) {
        return hour[idx];
    }

    int max_hour = 0;
    visited[idx] = true;

    for (int next : neighbors[idx]) {
        max_hour = std::max(max_hour, dfs(next));
    }

    hour[idx] += max_hour;
    return hour[idx];
}

int main() {
    std::cin >> n;
    for (int node = 1; node <= n; node++) {
        std::cin >> hour[node];

        int m;
        std::cin >> m;

        for (int i = 0; i < m; i++) {
            int from;
            std::cin >> from;
            neighbors[node].push_back(from);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = std::max(ans, dfs(i));
    }
    std::cout << ans << '\n';

    return 0;
}