#include <iostream>

int n;
long long m;
int prime[10];

long long solve() {
    long long answer = 0;

    for (int mask = 1; mask < (1 << n); mask++) {
        int cnt = 0;
        long long mul = 1;

        for (int i = 0; i < n; i++) {
            if (mask & 1 << i) {
                mul *= prime[i];
                if (mul > m) {
                    cnt = -1;
                    break;
                }
                cnt += 1;
            }
        }
        if (cnt == -1) {
            continue;
        }

        if (cnt % 2 == 0) {
            answer -= m / mul;
        } else {
            answer += m / mul;
        }
    }

    return answer;
}

int main() {
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
        std::cin >> prime[i];
    }

    std::cout << solve() << '\n';
    return 0;
}