#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<map>
#include<vector>

using namespace std;
class node {
public:
	int N;
	float a;

};
const float EPS = 1e-7;
vector<node> P1;
vector<node> P2;
bool cmp(node A, node B) {
	return A.N > B.N;
}
int main() {
	node Buffer;
	int K;
	int N_buffer;
	float a_buffer;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> Buffer.N >> Buffer.a;
		P1.push_back(Buffer);
	}
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> Buffer.N >> Buffer.a;
		P2.push_back(Buffer);
	}
	map<int, float> Map;
	for (int i = 0; i < P1.size(); i++) {
		for (int j = 0; j < P2.size(); j++) {
			N_buffer = P1[i].N + P2[j].N;
			a_buffer = P1[i].a * P2[j].a;
			if (Map.find(N_buffer) == Map.end()) {
				Map[N_buffer] = a_buffer;
			}
			else {
				Map[N_buffer] += a_buffer;
			}
		}
	}
	map<int, float>::iterator its = Map.begin();
	map<int, float>::iterator ite = Map.end();
	int Count = 0;
	vector<node> P;
	while (its != ite) {
		Count++;
		
		Buffer.N = (*its).first;
		Buffer.a = (*its).second;
		if (Buffer.a<EPS && Buffer.a>-EPS) {
			Count--;
		}
		else {
			P.push_back(Buffer);
		}
		its++;
	}
	sort(P.begin(), P.end(), cmp);
	cout << Count;
	for (int i = 0; i < P.size(); i++) {
		
		printf( " %d %.1f", P[i].N, P[i].a);
	}
	cout << endl;
	return 0;
}
//0µÄÎÊÌâ