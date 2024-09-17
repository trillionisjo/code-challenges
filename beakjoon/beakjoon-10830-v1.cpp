#include <iostream>
#include <vector>

const int mod = 1000;
int size;

std::vector <int> operator *(const std::vector <int>& x, const std::vector <int>& y) {
	std::vector <int> result(size * size, 0);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			for (int k = 0; k < size; k++)
				result[i * size + j] += x[i * size + k] * y[k * size + j];

	return result;
}

std::vector <int> operator %(const std::vector <int>& x, int mod) {
	std::vector <int> result = x;

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			result[i * size + j] %= mod;

	return result;
}

std::vector <int> solve(const std::vector <int>& a, long long n) {
	if (n == 1) {
		return a % mod;
	}

	if (n % 2 == 0) {
		std::vector <int> temp = solve(a, n / 2);
		temp = temp * temp % mod;
		return temp;
	}

	if (n % 2 == 1) {
		std::vector <int> temp = solve(a, n - 1);
		temp = a * temp % mod;
		return temp;
	}
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