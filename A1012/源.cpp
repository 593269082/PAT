#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
using namespace std;

class person {
public:
	string ID;
	int C;
	int M;
	int E;
	int A;
	vector<pair<int, int> > Ranks;
};
bool cmp1(person a, person b) {
	return a.A > b.A;
}
bool cmp2(person a, person b) {
	return a.C> b.C;
}
bool cmp3(person a, person b) {
	return a.M > b.M;
}
bool cmp4(person a, person b) {
	return a.E > b.E;
}
bool cmp5(pair<int,int> a, pair<int,int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}
vector<person> Students;
map<string, int> Map;
map<int, string> Map2;
int main() {
	Map2[1] = "A";
	Map2[2] = "C";
	Map2[3] = "M";
	Map2[4] = "E";
		int N, M;
	cin >> N >> M;
	person Buffer;
	for (int i = 0; i < N; i++) {
		cin >> Buffer.ID >> Buffer.C >> Buffer.M >> Buffer.E;
		Buffer.A = (Buffer.C + Buffer.E + Buffer.M) / 3;
		Students.push_back(Buffer);

	}
	sort(Students.begin(), Students.end(), cmp1);
	int Rank = 1;
	Students[0].Ranks.push_back(pair<int, int>(Rank, 1));
	for (int i = 1; i < Students.size(); i++) {
		if (Students[i].A == Students[i - 1].A) {
			Students[i].Ranks.push_back(pair<int, int>(Rank, 1));
		}
		else {
			Rank = i+1;
			Students[i].Ranks.push_back(pair<int, int>(Rank, 1));
		}
	}
	sort(Students.begin(), Students.end(), cmp2);
 Rank = 1;
	Students[0].Ranks.push_back(pair<int, int>(Rank, 2));
	for (int i = 1; i < Students.size(); i++) {
		if (Students[i].C == Students[i - 1].C) {
			Students[i].Ranks.push_back(pair<int, int>(Rank, 2));
		}
		else {
			Rank = i + 1;
			Students[i].Ranks.push_back(pair<int, int>(Rank, 2));
		}
	}
	sort(Students.begin(), Students.end(), cmp3);
	Rank = 1;
	Students[0].Ranks.push_back(pair<int, int>(Rank, 3));
	for (int i = 1; i < Students.size(); i++) {
		if (Students[i].M == Students[i - 1].M) {
			Students[i].Ranks.push_back(pair<int, int>(Rank, 3));
		}
		else {
			Rank = i + 1;
			Students[i].Ranks.push_back(pair<int, int>(Rank, 3));
		}
	}
	sort(Students.begin(), Students.end(), cmp4);
 Rank = 1;
	Students[0].Ranks.push_back(pair<int, int>(Rank, 4));
	Map[Students[0].ID] = 0;
	for (int i = 1; i < Students.size(); i++) {
		Map[Students[i].ID] = i;
		if (Students[i].E == Students[i - 1].E) {
			Students[i].Ranks.push_back(pair<int, int>(Rank, 4));
		}
		else {
			Rank = i + 1;
			Students[i].Ranks.push_back(pair<int, int>(Rank, 4));
		}
	}
	for (int i = 0; i < Students.size(); i++) {
		sort(Students[i].Ranks.begin(), Students[i].Ranks.end(), cmp5);
	}
	string IDBuffer;
	for (int i = 1; i <= M; i++) {
		cin >> IDBuffer;
		if (Map.find(IDBuffer) == Map.end()) {
			cout << "N/A" << endl;
		}
		else {
			cout << Students[Map[IDBuffer]].Ranks[0].first <<" "<< Map2[Students[Map[IDBuffer]].Ranks[0].second] << endl;
		}
	}
	return 0;
}