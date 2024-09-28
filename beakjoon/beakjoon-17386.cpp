#include <iostream>

int ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    long long a = x1 * y2 + x2 * y3 + x3 * y1;
    long long b = y1 * x2 + y2 * x3 + y3 * x1;

    if (a - b < 0) return -1;
    if (a - b > 0) return 1;
    return 0;
}

int main() {
    int x1, y1, x2, y2;
    int x3, y3, x4, y4;

    std::cin >> x1 >> y1 >> x2 >> y2;
    std::cin >> x3 >> y3 >> x4 >> y4;

    int ccw1 = ccw(x1, y1, x2, y2, x3, y3);
    int ccw2 = ccw(x1, y1, x2, y2, x4, y4);

    if (ccw1 * ccw2 > 0) {
        std::cout << 0 << '\n';
        return 0;
    }

    ccw1 = ccw(x3, y3, x4, y4, x1, y1);
    ccw2 = ccw(x3, y3, x4, y4, x2, y2);

    if (ccw1 * ccw2 > 0) {
        std::cout << 0 << '\n';
        return 0;
    }

    std::cout << 1 << '\n';
    return 0;
}