#include <iostream>
#include <vector>
#include <queue>

struct Node {
    int ind;
    std::vector <int> neighbors;
};

int n, m;
Node dag[32001];

std::vector <int> solve() {
    std::vector <int> ans;
    std::priority_queue <int, std::vector <int>, std::greater <int>> q;

    for (int i = 1; i <= n; i++) {
        if (dag[i].ind != 0) continue;
        q.push(i);
    }

    while (!q.empty()) {
        int idx = q.top(); q.pop();
        ans.push_back(idx);

        for (int next : dag[idx].neighbors) {
            dag[next].ind -= 1;
            if (dag[next].ind == 0) {
                q.push(next);
            }
        }
    }

    return ans;
}

int main() {
    std::cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to;
        std::cin >> from >> to;
        dag[from].neighbors.push_back(to);
        dag[to].ind += 1;
    }

    auto ans = solve();
    for (int num : ans) {
        std::cout << num << ' ';
    }

    return 0;
}