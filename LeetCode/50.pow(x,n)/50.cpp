#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

double quickMul(double x, long long N) {
	if (N == 0) {
		return 1.0;
	}
	double y = quickMul(x, N / 2);
	return N % 2 == 0 ? y * y : y * y * x;
}

double myPow(double x, int n) {
	long long N = n;
	return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
}


int main()
{
	cout << myPow(2.1, 3);
	return 0;
}