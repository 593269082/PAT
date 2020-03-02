//MSS问题 DP做法 O(n)
#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
const int MAXN = 10010;
using namespace std;
int A[MAXN];
int dp[MAXN];
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < MAXN; i++) {
		A[i] = 0;
		dp[i] = 0;
	}
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	dp[0] = A[0];
	for (int i = 1; i <= N - 1; i++) {
		dp[i] = max(A[i], dp[i - 1] + A[i]);
	}
	int MAX = -10000000;
	int pos = 0;
	for (int i = 0; i <= N - 1; i++) {
		if (MAX < dp[i]) {
			pos = i;
			MAX = dp[i];
		}

	}
	if (MAX < 0) {
		cout << 0 << " " << A[0] << " " << A[N - 1] << endl;
	}
	else {
		int startpos;
		int countSum = 0;
		for (int i = pos; i >= 0; i--) {
			countSum += A[i];
			if (countSum == MAX) {
				startpos = i;
				
			}
		}
		cout << MAX << " " << A[startpos] << " " << A[pos] << endl;
	}
	return 0;
}
//注意审题
