//看了半天 原来是个大水题。。
#include<iostream>
#include<algorithm>
#include<string>
#include<stdio.h>

using namespace std;

int main() {
	float W, T, L;
	float ans = 1.0;
	for (int i = 1; i <= 3; i++) {
		cin >> W >> T >> L;
		if (W > T&& W > L) {
			ans *= W;
			cout << "W ";
		}
		else if (T > W&& T > L) {
			ans *= T;
			cout << "T ";
		}
		else {
			ans *= L;
			cout << "L ";
		}
	}

	printf("%.2f\n", (ans * 0.65 - 1.0) * 2.0);
	return 0;
}