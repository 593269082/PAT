#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
const int MAXN = 1001;
const int INF = 0x3ffffff;
int d[MAXN];
bool vis[MAXN];
vector<int> pre[MAXN];
int n;
int G[MAXN][MAXN];
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
					d[v] = d[u] + G[u][v];//优化d[v]
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
vector<int> ins;
vector<int>outs;
int midCap;
int Weight[MAXN];
vector<vector<int> > Paths;
void DFS(int u,int in,int out,vector<int> Path) {

	if (pre[u].size() == 0) {
		//到达了起点
		//ins.push_back(in);
		//outs.push_back(out);
		Paths.push_back(Path);
		return;
	}
	Path.push_back(u);
	//if (Weight[u] > midCap) {
	//	out = out + Weight[u] - midCap;
	//}
	//else if (Weight[u] < midCap) {
	//	in = in + midCap - Weight[u];
	//}
	for (int i = 0; i < pre[u].size(); i++) {
		DFS(pre[u][i],in,out,Path);
	}
}
int main() {
	int start = 0;
	int end;
	int M;
	vector<int>path;
	cin >> midCap >> n >> end >> M;
	midCap /= 2;
	n = n + 1;
	for (int i =1; i < n; i++) {
		cin >> Weight[i];
	}
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			G[i][j]=INF;
		}
	}
	int x, y;
	int W;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> W;
		G[x][y]=G[x][y]= W;
	}
	Dijkstra(0);
	DFS(end, 0, 0,path);
	int in, out;
	int need = 0;
	for (int i = 0; i < Paths.size(); i++) {
		in = 0;
		out = 0;
		for (int j = Paths[i].size() - 1; j >= 0; j--) {
			if (Weight[Paths[i][j]] < midCap) {
				need = midCap - Weight[Paths[i][j]];
				if (need >= in) {
					need -= in;
					in = 0;
					out += need;

				}
				else {
					in -= need;

				}
			}
			else if (Weight[Paths[i][j]] > midCap) {
				in += Weight[Paths[i][j]] - midCap;
			}
		}
		ins.push_back(in);
		outs.push_back(out);
	}
	int pos = 0;
	int MIN = INF;
	int MINin = INF;
	int rein;
	int reout;
	for (int i = 0; i < ins.size(); i++) {
		//cout << ins[i] << " " << outs[i] << endl;

		if (outs[i] < MIN) {
			rein = ins[i];
			reout = outs[i];
			pos = i;
		}
		else if (outs[i]==MIN&&ins[i] < MINin) {
			rein = ins[i];
			reout = outs[i];
			pos = i;
		}
	}
	cout << reout<< " 0->";
	for (int i = Paths[pos].size() - 1; i >= 0; i--) {
		if (i != 0) {
			cout << Paths[pos][i] << "->";
		}
		else {
			cout << Paths[pos][i] << " ";
		}
	}cout << rein << endl;
	return 0;
}
/*
10 4 4 5
4 8 9 0
0 1 1 
1 2 1 
1 3 2
 2 3 1
  3 4 1


*/