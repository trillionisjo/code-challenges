#include <iostream>

long long min, max;
bool check[1'000'001];

int solve() {
    for (long long num = 2; num * num <= max; num++) {
        long long jegop = num * num;
        long long start = jegop - min % jegop;
        if (start == jegop) {
            start = 0;
        }

        for (long long i = start; i <= max - min; i += jegop) {
            check[i] = true;
        }
    }

    int ans = 0;
    for (int i = 0; i <= max - min; i++) {
        ans += !check[i];
    }
    return ans;
}

int main() {
    std::cin >> min >> max;
    std::cout << solve() << '\n';
    return 0;
}