#include <iostream>
#include <vector>

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

int solve(const Point& p0, const std::vector<Point>& poly) {
    for (size_t i = 0; i + 1 < poly.size(); i++) {
        if (0 == ccw(poly[i], poly[i + 1], p0)) {
            Point min, max;
            min.x = std::min(poly[i].x, poly[i + 1].x);
            min.y = std::min(poly[i].y, poly[i + 1].y);
            max.x = std::max(poly[i].x, poly[i + 1].x);
            max.y = std::max(poly[i].y, poly[i + 1].y);
            if (min <= p0 && p0 <= max) {
                return 1;
            }
        }
    }

    Point p1 = {1, 1'000'000'001};
    int count = 0;
    for (size_t i = 0; i + 1 < poly.size(); i++) {
        count += cross(poly[i], poly[i + 1], p0, p1);
    }
    return count % 2;
}

int main() {
    int n;
    std::vector<Point> poly;

    std::cin >> n;
    poly.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> poly[i].x >> poly[i].y;
    }
    poly.push_back(poly[0]);

    for (int i = 0; i < 3; i++) {
        Point p0;
        std::cin >> p0.x >> p0.y;
        std::cout << solve(p0, poly) << '\n';
    }

    return 0;
}