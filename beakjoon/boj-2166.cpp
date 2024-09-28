#include <iostream>
#include <vector>

int main() {
    int n;
    std::vector <long long> x, y;
    long long ans;

    std::cin >> n;
    x.resize(n);
    y.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }
    x.push_back(x[0]);
    y.push_back(y[0]);

    ans = 0;
    for (int i = 0; i < n; i++) {
        ans += x[i] * y[i + 1];
        ans -= y[i] * x[i + 1];
    }

    if (ans < 0) ans = -ans;

    std::cout << ans / 2 << '.';
    if (ans % 2 == 0) std::cout << 0 << '\n';
    else std::cout << 5 << '\n';

    return 0;
}