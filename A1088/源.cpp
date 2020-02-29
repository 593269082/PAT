#include<iostream>
#include<algorithm>
#include<string>

#include<math.h>
#define  ll long long
using namespace std;
class RationalNumber {
public:
	ll up;
	ll down;
};
ll gcd(ll a, ll b) {
	if (b == 0)return a;
	return gcd(b, a % b);
}

void reduce(RationalNumber& a) {

	if (a.down < 0) {
		a.down = -a.down;
		a.up = -a.up;
	}
	if (a.up == 0) {
		a.down = 1;
	}
	else {
		ll GCD = gcd(abs(a.up), abs(a.down));
		a.up /= GCD;
		a.down /= GCD;
	}
	
}
void Show(RationalNumber& a) {
	reduce(a);
	if (a.up < 0) {
		cout << "(";
	}
	if (a.down == 1) cout << a.up;
	else if (abs(a.up) > abs(a.down)) {
		cout << a.up / a.down << " " << abs(a.up) % a.down << "/" << a.down;
	}
	else {
		cout << a.up << "/" << a.down;
	}

	if (a.up < 0) {
		cout << ")";
	}
}
RationalNumber ADD(RationalNumber A, RationalNumber B) {
	RationalNumber Re;
	Re.up = A.down * B.up + A.up * B.down;
	Re.down = A.down * B.down;
	return Re;
}
RationalNumber SUB(RationalNumber A, RationalNumber B) {
	RationalNumber Re;
	Re.up = A.up * B.down-A.down * B.up;
	Re.down = A.down * B.down;
	return Re;
}
RationalNumber MUL(RationalNumber A, RationalNumber B) {
	RationalNumber Re;
	Re.up = A.up * B.up;
	Re.down = A.down * B.down;
	return Re;
}
RationalNumber DIV(RationalNumber A, RationalNumber B) {
	RationalNumber Re;
	Re.up = A.up * B.down;
	Re.down = A.down * B.up;
	return Re;
}
int main() {
	RationalNumber A, B;
	scanf_s("%lld/%lld", &A.up, &A.down);
	scanf_s("%lld/%lld", &B.up, &B.down);
	Show(A);
	cout << " + ";
	Show(B);
	cout << " = ";
	 RationalNumber Buffer = ADD(A, B);
	Show(Buffer);
	cout << endl;
	Show(A);
	cout << " - ";
	Show(B);
	cout << " = ";
	Buffer = SUB(A, B);
	Show(Buffer);
	cout << endl;
	Show(A);
	cout << " * ";
	Show(B);
	cout << " = ";
	 Buffer = MUL(A, B);
	Show(Buffer);
	cout << endl;
	Show(A);
	cout << " / ";
	Show(B); 
	cout << " = ";
	if (B.up == 0) {
		cout << "Inf";
	}
	else {
		 Buffer = DIV(A, B);
		Show(Buffer);
	}
	cout << endl;
	return 0;
}