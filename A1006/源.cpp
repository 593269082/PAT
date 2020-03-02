#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<vector>
using namespace std;
class Person {
public:
	string ID;
	int in_time;
	int out_time;
};
bool cmp1(Person A,Person B) {
	return A.in_time < B.in_time;
}
bool cmp2(Person A, Person B) {
	return A.out_time > B.out_time;
}
vector<Person> Array;
int main() {
	int N;
	cin >> N;
	Person Buffer;
	int Buffer_time;
	int hh, mm, ss;
	for (int i = 0; i < N; i++) {
		cin >> Buffer.ID;
		scanf_s("%d:%d:%d", &hh, &mm, &ss);
		Buffer_time = hh * 60 * 60 + mm * 60 + ss;
		Buffer.in_time = Buffer_time;
		scanf_s("%d:%d:%d", &hh, &mm, &ss);
		Buffer_time = hh * 60 * 60 + mm * 60 + ss;
		Buffer.out_time = Buffer_time;
		Array.push_back(Buffer);
	}
	sort(Array.begin(), Array.end(), cmp1);
	cout << Array[0].ID << " ";
	sort(Array.begin(), Array.end(), cmp2);
	cout << Array[0].ID << endl;

	return 0;
}