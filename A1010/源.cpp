#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<map>
using namespace std;
//Radix change from 2 to 36
map<char, long long> Map;
map<long long, char> rMap;
long long Change_N_to_10(string Number, long long Radix) {
	long long result = 0;
	long long buffer = 1;
	reverse(Number.begin(), Number.end());
	for (long long i = 0; i < Number.size(); i++) {
		result += buffer * Map[Number[i]];
		buffer *= Radix;
	}
	return result;
}
string Change_10_to_N(long long Number,long long Radix) {
	string result="";
	//³ýNÈ¡Óà·¨
	long long Buffer = Number;
	if (Buffer != 0) {
		while (Buffer != 0) {
			result.push_back( rMap[Buffer%Radix]);
			Buffer /= Radix;
		}
	}
	else {
		result = "0";
	}
	reverse(result.begin(), result.end());
	return result;
}
int main() {
	for (long long i = 0; i <= 9; i++) {
		Map[i + '0'] = i;
	}
	for (long long i = 0; i <= 26; i++) {
		Map[i + 'a'] = i + 10;
	}
	for (long long i = 0; i <= 9; i++) {
		rMap[i ] = i+ '0';
	}
	for (long long i = 0; i <= 26; i++) {
		rMap[i+ 10 ] = i + 'a';
	}
	string N1, N2;
	long long tN1, tN2;
	long long temp;
	long long Radix;
	cin >> N1 >> N2 >> temp >> Radix;
	if (temp == 1) {
		long long flag = 0;
		tN1 = Change_N_to_10(N1, Radix);
		for (long long i = 2; i <= 36; i++) {
			N1 = Change_10_to_N(tN1, i);
			if (N1 == N2) {
				cout << i << endl;
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			cout << "Impossible" << endl;
		}
	}
	else {
		long long flag = 0;
		tN2 = Change_N_to_10(N2, Radix);
		for (long long i = 2; i <= 36; i++) {
			N2 = Change_10_to_N(tN2, i);
			if (N1 == N2) {
				cout << i << endl;
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			cout << "Impossible" << endl;
		}
	}
	return 0;
}