#include <iostream>
#include <vector>

int n, m;
std::vector <int> dag[32001];
bool visited[32001];

void dfs(std::vector <int>& ans, int idx) {
    visited[idx] = true;
    for (int next : dag[idx]) {
        if (visited[next]) continue;
        dfs(ans, next);
    }
    ans.push_back(idx);
}

int main() {
    std::cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to;
        std::cin >> from >> to;
        dag[to].push_back(from);
    }

    std::vector <int> ans;

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        dfs(ans, i);
    }

    for (int num : ans) {
        std::cout << num << ' ';
    }

    return 0;
}