#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<map>
/*
Waiting in Line
ģ��
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
int Crux = 0;//�ؼ��ڵ� Ҳ��ʾ��ǰʱ��
queue<Customer> waitingQueue;
queue<Customer, vector<Customer>> windosQueues[MAXN];
priority_queue<CruxTime, vector<CruxTime>, cmp1> TransactionTimes;
vector<Customer> Customers;
map<int, int> Windows_Map;
void schedual() {
	//��ʱ�ȼ�����д��ڶ��У������ʱ�й�������˵Ĵ��ڣ���������ڵĵ�ǰ�ȴ���Ŀ��һ��Ȼ��������ڼ����������У�������а����ȴ����������󴰿ںŵ�˳��������У�
	//Ȼ������ȴ����У�����ȴ��������еȴ����ˣ��ʹӻ��������ȡ��һ�����ᣬ���봰�ڶ����У���ע����ʱ�䣬����ʱ��=��β����ʱ��+����ִ��ʱ�䡣������ڴ��ڶ����ǿյģ���ôΪcurrentTime+����ִ��ʱ�䣬ÿ����һ���ؼ�ʱ�䣬�ͽ����ʱ�����ؼ�����
	
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
		schedual();//��ʱ�ȼ�����д��ڶ��У������ʱ�й�������˵Ĵ��ڣ���������ڵĵ�ǰ�ȴ���Ŀ��һ��Ȼ��������ڼ����������У�������а����ȴ����������󴰿ںŵ�˳��������У�
		//Ȼ������ȴ����У�����ȴ��������еȴ����ˣ��ʹӻ��������ȡ��һ�����ᣬ���봰�ڶ����У���ע����ʱ�䣬����ʱ��=��β����ʱ��+����ִ��ʱ�䡣������ڴ��ڶ����ǿյģ���ôΪcurrentTime+����ִ��ʱ�䣬ÿ����һ���ؼ�ʱ�䣬�ͽ����ʱ�����ؼ�����

	}

	return 0;
}