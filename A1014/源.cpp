#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<map>
/*
Waiting in Line
模拟
zyp
20200303
*/
using namespace std;
class Customer {
public:
	int ID;
	int windowsID;
	int StartTime;
	int EndTime;
	int TransactionTime;
	
};

class CruxTime{
public:
	int Time;
};
struct cmp1 {
bool operator()(CruxTime a, CruxTime b) {
	return a.Time<b.Time;
}
};
int N, M, K, Q;
const int MAXN = 21;
int Crux = 0;//关键节点 也表示当前时间
queue<Customer> waitingQueue;
queue<Customer, vector<Customer>> windosQueues[MAXN];
priority_queue<CruxTime, vector<CruxTime>, cmp1> TransactionTimes;
vector<Customer> Customers;
map<int, int> Windows_Map;
void schedual() {
	//此时先检查所有窗口队列，如果此时有工作完成了的窗口，将这个窗口的当前等待数目减一，然后将这个窗口加入机会队列中（机会队列按照先窗口人数，后窗口号的顺序有序队列）
	//然后遍历等待队列，如果等待队列中有等待的人，就从机会队列中取出一个机会，加入窗口队列中，标注结束时间，结束时间=队尾结束时间+自身执行时间。如果现在窗口队列是空的，那么为currentTime+自身执行时间，每次有一个关键时间，就将这个时间加入关键队列
	
	for (int i = 1; i <=N; i++) {

	}
}
int main() {
	//initial
	cin >> N >> M >> K >> Q;
	//N windows num;M capacity;K customers num;Q query num
	Customer Buffer;
	for (int i = 1; i <= K; i++) {
		cin >> Buffer.TransactionTime;
		Buffer.ID = i;
		Customers.push_back(Buffer);
		waitingQueue.push(Buffer);
	}
	for (int i = 1; i <= N; i++) {
		Windows_Map[i] = M;
	}
	//schedual
	
	CruxTime Buf;
	Buf.Time = Crux;
	TransactionTimes.push(Buf);
	while (!TransactionTimes.empty()) {
		Buf = TransactionTimes.top();
		Crux = Buf.Time;
		schedual();//此时先检查所有窗口队列，如果此时有工作完成了的窗口，将这个窗口的当前等待数目减一，然后将这个窗口加入机会队列中（机会队列按照先窗口人数，后窗口号的顺序有序队列）
		//然后遍历等待队列，如果等待队列中有等待的人，就从机会队列中取出一个机会，加入窗口队列中，标注结束时间，结束时间=队尾结束时间+自身执行时间。如果现在窗口队列是空的，那么为currentTime+自身执行时间，每次有一个关键时间，就将这个时间加入关键队列

	}

	return 0;
}