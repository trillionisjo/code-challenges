#include <iostream>
#include <vector>
#include <queue>

const int INF = 0x7FFFFFFF;

int n, m;
int dp[101][101];
int next[101][101];

void path(int x, int y) {
    if (next[x][y] == -1) {
        std::cout << 0 << '\n';
        return;
    }

    std::queue <int> q;
    q.push(x);
    while (x != y) {
        x = next[x][y];
        q.push(x);
    }

    std::cout << q.size() << ' ';
    while (!q.empty()) {
        std::cout << q.front() << ' ';
        q.pop();
    }
    std::cout << '\n';
}

int main() {
    std::cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = (i == j ? 0 : INF);
            next[i][j] = -1;
        }
    }

    for (int i = 0; i < m; i++) {
        int from, to, cost;
        std::cin >> from >> to >> cost;

        if (cost < dp[from][to]) {
            dp[from][to] = cost;
            next[from][to] = to;
        }
    }

    // floyd
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dp[i][k] == INF || dp[k][j] == INF) {
                    continue;
                }

                if (dp[i][k] + dp[k][j] < dp[i][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cout << (dp[i][j] == INF ? 0 : dp[i][j]) << ' ';
        }
        std::cout << '\n';
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            path(i, j);
        }
    }

    return 0;
}