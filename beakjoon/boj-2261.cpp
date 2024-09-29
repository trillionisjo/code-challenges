#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>

struct Point {
    int x, y;

    bool operator < (const Point& other) const {
        if (y == other.y) return x < other.x;
        return y < other.y;
    }
};

int n;
Point points[100'000];

int square(const Point& p1, const Point& p2) {
    int x = p2.x - p1.x;
    int y = p2.y - p1.y;
    return x*x + y*y;
}

int solve() {
    // x를 기준으로 정렬.
    std::sort(points, points + n, [](const Point& p1, const Point& p2) { return p1.x < p2.x; });

    std::set <Point> candidate;
    candidate.insert(points[0]);
    candidate.insert(points[1]);

    int ans = square(points[0], points[1]);
    int left_idx = 0;

    for (int i = 2; i < n; i++) {
        const Point& right = points[i];

        while (left_idx < i) {
            const Point& left = points[left_idx];
            int x_dist = right.x - left.x;

            if (x_dist * x_dist > ans) {
                candidate.erase(left);
                left_idx += 1;
            } else {
                break;
            }
        }
        
        int dist = (int)sqrt((float)ans) + 1;
        auto lower_point = Point{-100'000, right.y - dist};
        auto upper_point = Point{100'000, right.y + dist};
        auto lower = candidate.lower_bound(lower_point);
        auto upper = candidate.upper_bound(upper_point);

        for (auto it = lower; it != upper; it++) {
            int s = square(right, *it);
            if (s < ans) ans = s;
        }

        candidate.insert(right);
    }

    return ans;
}

int main() {
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> points[i].x >> points[i].y;
    }

    std::cout << solve() << '\n';
    return 0;
}