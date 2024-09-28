#include <iostream>

int solve(int x1, int y1, int x2, int y2, int x3, int y3) {
    int a = x1 * y2 + x2 * y3 + x3 * y1;
    int b = x2 * y1 + x3 * y2 + x1 * y3;
    int ccw = a - b;
    if (ccw > 0) return 1;
    else if (ccw < 0) return -1;
    else return 0;
}

int main() {
    int x1, y1;
    int x2, y2;
    int x3, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    std::cout << solve(x1, y1, x2, y2, x3, y3) << '\n';
}