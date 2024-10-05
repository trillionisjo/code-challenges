#include <iostream>
#include <vector>
#include <algorithm>

struct Meeting {
    int start, end;
};

int main() {
    int n;
    std::cin >> n;
    std::vector <Meeting> arr(n);

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i].start >> arr[i].end;
    }

    std::sort(arr.begin(), arr.end(),
              [](const Meeting& a, const Meeting& b) {
                  if (a.end == b.end) {
                      return a.start < b.start;
                  }
                  return a.end < b.end;
              });

    int now = 0;
    int ans = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (now <= arr[i].start) {
            now = arr[i].end;
            ans += 1;
        }
    }

    std::cout << ans << '\n';
    return 0;
}