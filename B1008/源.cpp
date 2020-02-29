#include<iostream>
#include<algorithm>
#include<string>
#include<stdio.h>

using namespace std;
int gcd(int a,int b) {
	if (b == 0)return a;
	else return gcd(b, a % b);
}//求最小公约数

int A[105];
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int temp = 0;
	int d = gcd(N, M);
	int current_pos;
	int pos;
	for (int i = N - M; i <= N - M + d - 1; i++) {

	}



	return 0;
}