#include <iostream>
#include <vector>

const int INF = 0x7FFFFFFF;

int n, m;
int dp[101][101];

int main() {
    std::cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = (i == j ? 0 : INF);
        }
    }

    for (int i = 0; i < m; i++) {
        int from, to, cost;
        std::cin >> from >> to >> cost;

        if (cost < dp[from][to]) {
            dp[from][to] = cost;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dp[i][k] == INF || dp[k][j] == INF) {
                    continue;
                }

                if (dp[i][k] + dp[k][j] < dp[i][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
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

    return 0;
}