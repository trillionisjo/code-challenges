#include <iostream>
#include <stack>

int cy, cx;
int board[1000][1000];

int largest_rect_size(int y) {
    std::stack <int> stack;
    stack.push(-1);

    int ans = 0;

    for (int x = 0; x < cx; x++) {
        while (stack.top() != -1 && board[y][stack.top()] > board[y][x]) {
            int height = board[y][stack.top()];
            stack.pop();
            ans = std::max(ans, (x - stack.top() - 1) * height);
        }
        stack.push(x);
    }

    while (stack.top() != -1) {
        int height = board[y][stack.top()];
        stack.pop();
        ans = std::max(ans, (cx - stack.top() - 1) * height);
    }

    return ans;
}

int solve() {
    for (int y = 1; y < cy; y++) {
        for (int x = 0; x < cx; x++) {
            if (board[y][x] == 0) {
                continue;
            }
            board[y][x] += board[y - 1][x];
        }
    }

    int ans = 0;
    for (int y = 0; y < cy; y++) {
        ans = std::max(ans, largest_rect_size(y));
    }
    return ans;
}

int main() {
    while (true) {
        std::cin >> cy >> cx;
        if (cy == 0 && cx == 0) {
            break;
        }
        for (int y = 0; y < cy; y++) {
            for (int x = 0; x < cx; x++) {
                std::cin >> board[y][x];
            }
        }
        std::cout << solve() << '\n';
    }

    return 0;
}