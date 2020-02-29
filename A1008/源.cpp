#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	int total_time=0;
	int state = 0;
	int pre_state;
	for (int i = 0; i < N; i++) {
		cin >> pre_state;
		if (pre_state > state) {
			total_time += (pre_state - state) * 6 + 5;
			state = pre_state;
		}
		else if (pre_state < state) {
			total_time += (state - pre_state) * 4 + 5;
			state = pre_state;
		}
		else{
			total_time += 5;
		}
	}
	cout << total_time << endl;
	return 0;
}