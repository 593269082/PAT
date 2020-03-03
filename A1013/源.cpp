#include<iostream>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<memory.h>
#include<vector>
using namespace std;
const int MAXN = 1010;
int N, M, K;
bool visited[MAXN];
vector<int> G[MAXN];
void DFS_VISIT(int x) {
	for (int i = 0; i < G[x].size(); i++) {
		if (visited[G[x][i]] != 1) {
			visited[G[x][i]] = 1;
			DFS_VISIT(G[x][i]);
		}
	}
}
int DFS(int u) {
	//if u is BLACK return connected blocks number
	memset(visited, 0, sizeof(visited));
	visited[u] = 1;
	int Count = 0;
	for (int i = 1; i <= N; i++) {
		if (visited[i] != 1) {
			DFS_VISIT(i);
			Count++;
		}
	}
	return Count;
}

int main() {
	memset(visited, 0, sizeof(visited));
	
	cin >> N >> M >> K;
	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int qu = 0;
	for(int i = 0; i < K; i++) {
		scanf("%d",&qu);
		cout << DFS(qu) - 1 << endl;
	}

	return 0;
}