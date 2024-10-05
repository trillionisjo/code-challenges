#include <iostream>
#include <vector>
#include <algorithm>

struct point {
    int x;
    int io;
};

int main() {
    int n;
    std::cin >> n;
    std::vector <point> arr(n * 2);

    for (int i = 0; i < n; i++) {
        int start, end;
        std::cin >> start >> end;

        arr[i].x = start;
        arr[i].io = 1;

        arr[i + n].x = end;
        arr[i + n].io = -1;
    }

    std::sort(arr.begin(), arr.end(),
              [](const point& p1, const point& p2) {
                  if (p1.x == p2.x) {
                      return p1.io < p2.io;
                  }
                  return p1.x < p2.x;
              });

    int cnt = 0;
    int ans = 0;

    for (const point& p : arr) {
        cnt += p.io;
        ans = std::max(ans, cnt);
    }

    std::cout << ans << '\n';

    return 0;
}