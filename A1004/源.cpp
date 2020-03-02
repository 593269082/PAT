#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

#include<queue>
using namespace std;
class node {
public:
	string  ID;
	int layer;
	vector<int> childs;
	int flag;
};
string RootID = "01";
node Node[100];
int Layers[100];
int MaxLayer;
int change_str_int(string ID) {
	return (ID[0] - '0') * 10 + ID[1] - '0';
}
void LayerOrder(int root) {
	queue<int> Q;
	Q.push(root);
	Node[root].layer = 0;
	while (!Q.empty()) {
		int front = Q.front();
		//判断某一层的叶节点和非叶节点数目
		if (Node[front].childs.size() == 0) {
			Layers[Node[front].layer]++;
		}
		Q.pop();
		for (int i = 0; i < Node[front].childs.size(); i++) {
			int child = Node[front].childs[i];
			Node[child].layer = Node[front].layer + 1;
			MaxLayer = max(MaxLayer, Node[child].layer);
			Q.push(child);
		}
	}
}
int main() {
	int N, M;
	cin >> N >> M;
	MaxLayer = 0;
	for (int i = 0; i <= 99; i++) {
		Layers[i] = 0;
	}
	for (int i = 0; i <= 99; i++) {
		Node[i].flag = 0;
	}
	//root: 01
	string ID;
	for (int i = 0; i <M; i++) {
		cin >> ID;
		if (Node[change_str_int(ID)].flag == 0) {
			Node[change_str_int(ID)].flag = 1;
			Node[change_str_int(ID)].ID = ID;
		}
		int NUM;
		cin >> NUM;
		string childID;
		for (int i = 0; i < NUM; i++) {
			cin >> childID;
			//cout << change_str_int(ID);
			//cout << " " << change_str_int(childID);
			if (Node[change_str_int(childID)].flag == 0) {
				Node[change_str_int(childID)].flag = 1;
				Node[change_str_int(childID)].ID = childID;
			}
			
			Node[change_str_int(ID)].childs.push_back(change_str_int(childID));
		}
	}
	LayerOrder(1);
	for (int i = 0; i <= MaxLayer; i++) {
		if (i != 0) cout << " ";
		cout << Layers[i];
	}
	cout << endl;

	return 0;
}