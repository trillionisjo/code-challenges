#include <iostream>

const int mod = 1'000'000;
const int cycle = mod / 10 * 15;

int arr[cycle];

int main() {
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i < cycle; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2]) % mod;
    }

    long long n;
    std::cin >> n;
    std::cout << arr[n % cycle] << '\n';

    return 0;
}