#include <iostream>
#include <vector>
#include <climits>

const int MAX = 46340;

std::vector <int> primes;
bool check[MAX + 1];

void build_primes() {
    for (int i = 2; i <= MAX; i++) {
        if (check[i]) {
            continue;
        }
        primes.push_back(i * i);
        for (int j = i + i; j <= MAX; j += i) {
            check[j] = true;
        }
    }
}

int calc(int idx, long long mul, long long limit) {
    if (idx >= (int)primes.size()) {
        return 0;
    }

    long long curr = mul * primes[idx];
    if (curr > limit) {
        return 0;
    }

    int ans = int(limit / curr);
    ans += calc(idx + 1, mul, limit);
    ans -= calc(idx + 1, curr, limit);
    return ans;
}

int solve(int k) {
    long long left = 0;
    long long right = INT_MAX;
    int ans = 0;

    while (left <= right) {
        int mid = int((left + right) / 2);
        int nono = mid - calc(0, 1, mid);
        if (nono < k) {
            left = mid + 1;
        } else {
            ans = mid;
            right = mid - 1;
        }
    }

    return ans;
}

int main() {
    build_primes();

    int k;
    std::cin >> k;
    std::cout << solve(k) << '\n';

    return 0;
}