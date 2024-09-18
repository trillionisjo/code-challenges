#include <iostream>

int n;
long long m;
int prime[10];

long long solve(int idx, long long mul) {
    if (idx >= n) {
        return 0;
    }

    long long curr = mul * prime[idx];
    if (curr > m) {
        return 0;
    }

    long long ans = m / curr;
    ans += solve(idx + 1, mul);
    ans -= solve(idx + 1, curr);
    return ans;
}

int main() {
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
        std::cin >> prime[i];
    }

    std::cout << solve(0, 1) << '\n';
    return 0;
}