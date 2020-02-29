#include<iostream>
#include<algorithm>
#include<string>
#include<stdio.h>

using namespace std;
double Nums[100010];
int main() {
	//数列的片段和
	int NUM;
	cin >> NUM;
	for (int i = 0; i < NUM; i++) {
		scanf_s("%lf",&Nums[i]);

	}
	double Sum = 0;
	for (int i = 0; i < NUM; i++) {
		Sum += Nums[i] * (NUM - i) * (i + 1);
	}
	printf("%.2f\n", Sum);
	return 0;
}