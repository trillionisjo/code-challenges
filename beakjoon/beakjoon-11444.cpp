#include <iostream>

const long long mod = 1'000'000'007;

struct Matrix2x2 {
    long long mat[2][2] = {0,};
};

Matrix2x2 operator* (Matrix2x2 m1, Matrix2x2 m2) {
    Matrix2x2 result;
    result.mat[0][0] = m1.mat[0][0] * m2.mat[0][0] + m1.mat[0][1] * m2.mat[1][0];
    result.mat[0][1] = m1.mat[0][0] * m2.mat[0][1] + m1.mat[0][1] * m2.mat[1][1];
    result.mat[1][0] = m1.mat[1][0] * m2.mat[0][0] + m1.mat[1][1] * m2.mat[1][0];
    result.mat[1][1] = m1.mat[1][0] * m2.mat[0][1] + m1.mat[1][1] * m2.mat[1][1];

    result.mat[0][0] %= mod;
    result.mat[0][1] %= mod;
    result.mat[1][0] %= mod;
    result.mat[1][1] %= mod;
    return result;
}

long long solve(long long n) {
    Matrix2x2 result;
    result.mat[0][0] = 1;
    result.mat[1][1] = 1;

    Matrix2x2 a;
    a.mat[0][0] = 1;
    a.mat[0][1] = 1;
    a.mat[1][0] = 1;

    while (n) {
        if (n % 2 == 1) {
            result = result * a;
        }
        a = a * a;
        n = n / 2;
    }
    return result.mat[0][0];
}

int main() {
    long long n;
    std::cin >> n;
    std::cout << solve(n - 1) << '\n';
    return 0;
}