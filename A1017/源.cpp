#include<iostream>
#include<algorithm>	
#include<string>
#include<vector>
#include<queue>
#include<set>
using namespace std;
class Person {
public:
	int start;
	int process;
	int end;
	friend bool operator<(Person A, Person B) {
		return A.start > B.start;
	}
};
class Window {
public:
	Person P;
	bool empty;
	Window() {
		empty = 1;//empty!

	}
};


priority_queue<Person> Qwait;
set<int> Ts;
int S_to_Time(int H, int M, int S) {
	return H * 60 * 60 + M * 60 + S;
}
int main() {
	int N, K;
	cin >> N >> K;
	vector<Window> Windows;
	Window Buffer;
	Buffer.empty = 1;
	for (int i = 0; i < K; i++) {
		Windows.push_back(Buffer);
	}
	Person PBuffer;
	int HH, MM, SS;
	int PP;
	int end_time = S_to_Time(17, 0, 1);
	int start_time = S_to_Time(8, 0, 0);
	Ts.insert(start_time);
	int Count = 0;
	for (int i = 0; i < N; i++) {
		scanf_s("%d:%d:%d", &HH, &MM, &SS);
		cin >> PP;
		PBuffer.start = S_to_Time(HH, MM, SS);
		PBuffer.process = PP*60;
		if (PBuffer.start < end_time)
		{
			if (PBuffer.start >= start_time) {
				Ts.insert(PBuffer.start);
			};
			Count++;
			 Qwait.push(PBuffer);
		}
	}
	int Sum_Time = 0;
	int Current_Time;
	set<int>::iterator its;
	while (!Ts.empty()) {
		its = Ts.begin();
	//	cout << (*its)/3600<<" "<< (*its) / 60 % 60 << " "<<(*its) % 60  << endl;
		Current_Time = (*its);
		for (int i = 0; i < K; i++) {
			if (Windows[i].empty == 1) {
				//schedual
				if (Qwait.empty() || Qwait.top().start > Current_Time)
				{
					//cout << Qwait.top().start << endl;
					Windows[i].empty = 1;
				}
				else
				{
					Windows[i].P = Qwait.top();
					Windows[i].P.end = Windows[i].P.process + Current_Time;
					Ts.insert(Windows[i].P.end);
					Windows[i].empty = 0;
					Qwait.pop();
				}
				
			}
			else if (Windows[i].P.end == Current_Time) {
			//	cout << Windows[i].P.end - Windows[i].P.start - Windows[i].P.process << endl;
				Sum_Time += Windows[i].P.end - Windows[i].P.start- Windows[i].P.process;
				Windows[i].empty = 1;
				//schedual
				if ( Qwait.empty()||Qwait.top().start > Current_Time )
					Windows[i].empty = 1;
				else
				{
					Windows[i].P = Qwait.top();
					Windows[i].P.end = Windows[i].P.process + Current_Time;
					Ts.insert(Windows[i].P.end);
					Windows[i].empty = 0;
					Qwait.pop();
				}

			}
		}
		Ts.erase(its);
	}
printf("%.1f\n",(float)Sum_Time / ((float)Count*(float)60));
	return 0;
}