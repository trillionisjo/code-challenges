#include <iostream>

struct Point {
    long long x, y;

    bool operator < (const Point& other) const {
        if (x == other.x) {
            return y < other.y;
        }
        return x < other.x;
    }

    bool operator <= (const Point& other) const {
        if (x == other.x) {
            return y <= other.y;
        }
        return x <= other.x;
    }
};

int ccw(const Point& p1, const Point& p2, const Point& p3) {
    long long a = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
    long long b = p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;

    if (a - b < 0) return -1;
    if (a - b > 0) return 1;
    return 0;
}

bool cross(Point p1, Point p2, Point p3, Point p4) {
    int ccw1, ccw2;
    int res1, res2;

    ccw1 = ccw(p1, p2, p3);
    ccw2 = ccw(p1, p2, p4);
    res1 = ccw1 * ccw2;

    ccw1 = ccw(p3, p4, p1);
    ccw2 = ccw(p3, p4, p2);
    res2 = ccw1 * ccw2;

    if (res1 == 0 && res2 == 0) {
        if (p2 < p1) std::swap(p1, p2);
        if (p4 < p3) std::swap(p3, p4);
        return p1 <= p4 && p3 <= p2;
    }

    return res1 <= 0 && res2 <= 0;
}

int main() {
    Point p1, p2, p3, p4;

    std::cin >> p1.x >> p1.y >> p2.x >> p2.y;
    std::cin >> p3.x >> p3.y >> p4.x >> p4.y;

    std::cout << cross(p1, p2, p3, p4) << '\n';
    return 0;
}