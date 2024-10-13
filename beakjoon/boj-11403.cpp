#include <iostream>

int n;
int dp[100][100];

int main() {
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> dp[i][j];
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][k] == 1 && dp[k][j] == 1) {
                    dp[i][j] = 1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << dp[i][j] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}