#include <iostream>
#include <vector>
#include <queue>

struct Node {
    int time;
    int ind;
    std::vector <int> adj;
};

int n;
Node dag[10001];
int dp[10001];

int bfs() {
    std::queue <int> q;

    for (int i = 1; i <= n; i++) {
        if (dag[i].ind != 0) continue;
        dp[i] = dag[i].time;
        q.push(i);
    }

    while (!q.empty()) {
        int idx = q.front(); q.pop();

        for (int next : dag[idx].adj) {
            dag[next].ind -= 1;

            if (dp[next] < dp[idx] + dag[next].time) {
                dp[next] = dp[idx] + dag[next].time;
            }

            if (dag[next].ind == 0) {
                q.push(next);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = std::max(dp[i], ans);
    }
    return ans;
}

int main() {
    std::cin >> n;
    for (int node = 1; node <= n; node++) {
        std::cin >> dag[node].time;
        std::cin >> dag[node].ind;

        for (int i = 0; i < dag[node].ind; i++) {
            int from;
            std::cin >> from;
            dag[from].adj.push_back(node);
        }
    }

    std::cout << bfs() << '\n';

    return 0;
}