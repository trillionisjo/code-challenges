#include <iostream>
#include <vector>

const int mod = 1000;
int size;

std::vector <int> operator *(const std::vector <int>& x, const std::vector <int>& y) {
    std::vector <int> result(size * size, 0);

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            for (int k = 0; k < size; k++) {
                result[i * size + j] += x[i * size + k] * y[k * size + j];
                result[i * size + j] %= mod;
            }
    return result;
}

std::vector <int> solve(std::vector <int> a, long long n) {
    std::vector <int> result(size * size);
    for (int i = 0; i < size; i++) {
        result[i * size + i] = 1;
    }
    
    while (n) {
        if (n % 2 == 1) {
            result = result * a;
        }
        a = a * a;
        n /= 2;
    }
    return result;
}
int main() {
    std::vector <int> mat;
    long long n;

    std::cin >> size >> n;
    mat.resize(size * size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cin >> mat[i * size + j];
        }
    }

    std::vector <int> ans = solve(mat, n);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << ans[i * size + j] << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}
