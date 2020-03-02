#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;

map<int, string> int_to_string;
void print_sum_en(string str) {
	long long Sum = 0;
	for (int i = 0; i < str.size(); i++) {
		Sum += str[i] - '0';
	}
	vector<string> RE;
	if (Sum == 0) {
		cout <<"zero" << endl;
		return;
	}
	while (Sum != 0) {
		RE.push_back(int_to_string[Sum % 10]);
		Sum /= 10;
	}
	for (int i = 0; i < RE.size(); i++) {
		if (i != 0) {
			cout << " ";
		}
		cout << RE[RE.size()-1-i];
	}
	cout << endl;
}
int main() {
	int_to_string[0] = "zero";
	int_to_string[1] = "one";
	int_to_string[2] = "two";
	int_to_string[3] = "three";
	int_to_string[4] = "four";
	int_to_string[5] = "five";
	int_to_string[6] = "six";
	int_to_string[7] = "seven";
	int_to_string[8] = "eight";
	int_to_string[9] = "nine";
	string A;
	cin >> A;
	print_sum_en(A);



	return 0;
}