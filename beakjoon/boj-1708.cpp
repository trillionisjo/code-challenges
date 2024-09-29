#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
    long long x, y;

    bool operator < (const Point& other) const {
        if (y == other.y) {
            return x < other.x;
        }
        return y < other.y;
    }
};

int n;
Point p;
Point points[100'000];

int ccw(const Point& p1, const Point& p2, const Point& p3) {
    long long a = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
    long long b = p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;

    if (a - b < 0) return -1;
    if (a - b > 0) return 1;
    return 0;
}

long long dist(const Point& p1, const Point& p2) {
    long long x = (p2.x - p1.x);
    long long y = (p2.y - p1.y);
    return x * x + y * y;
}

bool cmp(const Point& u, const Point& v) {
    int temp = ccw(p, u, v);
    if (temp == 0) {
        return dist(p, u) < dist(p, v);
    }
    return temp == 1;
}

int solve() {
    std::vector <Point> convex;

    for (int i = 0; i < n; i++) {
        while (convex.size() >= 2) {
            int orientation = ccw(convex[convex.size() - 2], convex[convex.size() - 1], points[i]);
            if (orientation == 1) break;
            convex.pop_back();
        }
        convex.push_back(points[i]);
    }

    return (int)convex.size();
}

int main() {
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> points[i].x >> points[i].y;
    }

    p = points[0];
    for (int i = 1; i < n; i++) {
        if (points[i] < p) p = points[i];
    }

    std::sort(points, points + n, cmp);

    std::cout << solve() << '\n';
    return 0;
}