#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
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
	int windosID;
	int StartTime;
	int EndTime;
	int TransactionTime;
	
};
struct cmp1 {
bool operator()(Customer a, Customer b) {
	return a.EndTime <b.EndTime;
}
};
int N, M, K, Q;
const int MAXN = 21;
int windowsCustomer_num[MAXN];
vector<Customer> Customers;
priority_queue<Customer,vector<Customer>> waitingQueue;
priority_queue<Customer, vector<Customer>, cmp1> windosQueues[MAXN];
priority_queue<Customer, vector<Customer>, cmp1> exacQueue;
void schedual() {
	//���е��ȣ��ڵ�ǰʱ�䣬�Եȴ����кʹ��ڶ��н��е��ȣ�����ǰ�ȴ������е�
	while (1) {
		Customer curr = waitingQueue.top();
		
	}
}
int main() {
	//initial
	
	cin >> N >> M >> K >> Q;
	//N windows num;M capacity;K customers num;Q query num
	Customer Buffer;
	for (int i = 1; i <= N; i++) {
		windowsCustomer_num[i] = 0;
	}
	for (int i = 1; i <= K; i++) {
		cin >> Buffer.TransactionTime;
		Buffer.ID = i;
		Customers.push_back(Buffer);
		waitingQueue.push(Buffer);
	}
	//schedual



	return 0;
}