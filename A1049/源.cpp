#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main() {
	int n;
	cin >> n;
	int left = 0;
	int right;
	int a=1;
	int now;
	int ans = 0;
	while (n / a != 0) {
		left = n / (a*10);
		now = n / a % 10;
		right = n % a;
		if (now == 0) ans += left * a;
		else if (now == 1) ans += left * a + right + 1;
		else ans += (left + 1) * a;
		a *= 10;

	}
	cout << ans << endl;

	return 0;
}