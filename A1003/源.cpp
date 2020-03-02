#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#define INF 0x3fffff
using namespace std;
const int MAXN = 1000;
vector<int> pre[MAXN];
int G[MAXN][MAXN];
int d[MAXN];
bool vis[MAXN];
int n;
void Dijkstra(int s) {
	fill(d, d + MAXN, INF);
	fill(vis, vis + MAXN, 0);
	d[s] = 0;
	for (int i = 0; i < n; i++) {
		int u = -1;
		int MIN = INF;
		for (int j = 0; j < n; j++) {
			if (vis[j] == 0 && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1)return;
		vis[u] = 1;
		for (int v = 0; v < n; v++) {
			if (vis[v] == false && G[u][v] != INF) {
				if (d[u] + G[u][v] < d[v]) {
					d[v] = d[u] + G[u][v];//ÓÅ»¯d[v]
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (d[u] + G[u][v] == d[v]) {
					pre[v].push_back(u);
				}
			}
		}
	}
}
int MAX_Weight;
int Count;int Weight[MAXN];
void DFS_Dijkstra(int C1,int Point,int weight ) {
	if (Point == C1) {
		weight += Weight[C1];
		if (weight > MAX_Weight) {
			MAX_Weight = weight;
		}
		Count++;
		return;
	}
	weight += Weight[Point];
	for (int i = 0; i < pre[Point].size(); i++) {
		DFS_Dijkstra(C1, pre[Point][i], weight);
	}
}

int main() {
	Count = 0;
	MAX_Weight = -1;
	cin >> n;
	int M;
	int C1, C2;
	cin >> M >> C1 >> C2;
	int Buffer;
	int S, T;
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			G[i][j]= INF;
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> Weight[i];
	}

	for (int i = 0; i < M; i++) {
		cin >> S >> T>>Buffer;
		G[S][T]=Buffer; G[T][S] = Buffer;
	}
	Dijkstra(C1);
	DFS_Dijkstra(C1, C2, 0);
	cout << Count << " " << MAX_Weight << endl;

	return 0;
}