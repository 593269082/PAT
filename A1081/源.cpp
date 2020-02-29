#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
	if (b == 0)return a;
	return gcd(b, a % b);
}
class RationalNumber {
public:
	long long int numerator;
	long long int denominator;
	void Regular() {
		if (denominator < 0) {
			numerator = -numerator;
			denominator = -denominator;
		}
		if (numerator == 0) {
			denominator = 1;
		}
		else {
			long long int GCD = gcd(abs(numerator), abs(denominator));
			numerator /= GCD;
			denominator /= GCD;
		}
	}
};
RationalNumber Add(RationalNumber a , RationalNumber b) {
	RationalNumber c;
	c.numerator = a.numerator * b.denominator + a.denominator * b.numerator;
	c.denominator = a.denominator * b.denominator;
	return c;
}
void Show(RationalNumber A) {
	A.Regular();
	if (A.denominator == 1) cout << A.numerator<<endl;
	else if (abs(A.numerator) > abs(A.denominator)) {
		cout << A.numerator / A.denominator << " " << abs(A.numerator) % A.denominator<<"/"<< A.denominator << endl;
	}
	else {
		cout << A.numerator % A.denominator<<"/"<< A.denominator << endl;
	}
}
int main() {
	int N;
	cin >> N;
	RationalNumber Re;
	Re.numerator = 0;
	Re.denominator = 1;
	RationalNumber Buffer;
	for (int i = 0; i < N; i++) {
		scanf_s("%lld/%lld", &Buffer.numerator, &Buffer.denominator);
		Re = Add(Buffer, Re);
		Re.Regular();
	}
	Show(Re);
	return 0;
}