#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>

using namespace std;
class Trasaction {
public:
	string Name;
	int Month;
	int Day;
	int Hour;
	int Minute;
	bool On_Off_Line;
	Trasaction(){
		On_Off_Line = 0;
	}
};
class Person {
public:
	string Name;
	vector<pair<Trasaction, Trasaction> > Trasactions;
};
bool cmp(Trasaction A,Trasaction B) {
	if (A.Name == B.Name) {
		if (A.Day == B.Day) {
			if (A.Hour == B.Hour) {
				return A.Minute < B.Minute;
			}
			else {
				return A.Hour < B.Hour;
			}
		}
		else {
			return A.Day < B.Day;
		}
	}
	return A.Name < B.Name;
}
map<int, int> H_To_Price;
vector<Trasaction> Total_Trasactions;
bool isOnline(string Buffer) {
	if (Buffer == "on-line") {
		return 1;
	}
	else {
		return 0;
	}
}
map<string, Person*> Persons;
int main() {
	for (int i = 0; i <= 23; i++) {
		cin >> H_To_Price[i];
	}
	int N;
	string TheName;
	int theM;
	int theD;
	int theH;
	int theMM;
	bool ifOnLine;
	string Buffer;
	cin >> N;
	Trasaction bufferT;
	for (int i = 0; i < N; i++) {
		cin >> TheName;
		if (Persons.find(TheName)== Persons.end()) {
			Persons[TheName] = new Person;
			Persons[TheName]->Name = TheName;
		}
		scanf_s("%d:%d:%d:%d", &theM, &theD, &theH, &theMM);
		cin >> Buffer;
		bufferT.Day = theD;
		bufferT.Month = theM;
		bufferT.Hour = theH;
		bufferT.Name = TheName;
		bufferT.Minute = theMM;
		bufferT.On_Off_Line = isOnline(Buffer);
		Total_Trasactions.push_back(bufferT);
	}
	sort(Total_Trasactions.begin(), Total_Trasactions.end(), cmp);
	Trasaction CurrentTrasact;
	CurrentTrasact = Total_Trasactions[0];
	int i = 0;
	pair<Trasaction, Trasaction> Buf;
	for (;;i++) {
		if (Total_Trasactions[i].On_Off_Line) {
			CurrentTrasact = Total_Trasactions[i];
			i++;
			break;
		}
	}

	for (; i < Total_Trasactions.size(); i++) {
		if (Total_Trasactions[i].Name == CurrentTrasact.Name) {
			if (Total_Trasactions[i].On_Off_Line == 1) {
				CurrentTrasact = Total_Trasactions[i];
			}
			else {
				Buf.first = CurrentTrasact;
				Buf.second= Total_Trasactions[i];
				Persons[CurrentTrasact.Name]->Trasactions.push_back(Buf);
				for (;i<Total_Trasactions.size(); i++) {
					if (Total_Trasactions[i].On_Off_Line) {
						CurrentTrasact = Total_Trasactions[i];
						break;
					}
				}
			}
		}
		else {
			if (Total_Trasactions[i].On_Off_Line == 1) {
				CurrentTrasact = Total_Trasactions[i];
			}
		}
	}
	map<string, Person*>::iterator its = Persons.begin();
	map<string, Person*>::iterator ite= Persons.end();
	int Time = 0;
	float Price = 0.0;
	float SumPrice = 0.0;

	int sd, ed, sh, eh, sm, em;
	int tsd, ted, tsh, teh, tsm, tem;
	while (its != ite) {
		if ((*its).second->Trasactions.size() == 0) {
			its++;
			continue;
		}
		cout << (*its).first << " ";
		printf("%02d", theM);
		cout<< endl;
		SumPrice = 0;
		for (int i = 0; i < (*its).second->Trasactions.size(); i++) {
			printf("%02d:%02d:%02d ", (*its).second->Trasactions[i].first.Day, (*its).second->Trasactions[i].first.Hour, (*its).second->Trasactions[i].first.Minute);
			printf("%02d:%02d:%02d ", (*its).second->Trasactions[i].second.Day, (*its).second->Trasactions[i].second.Hour, (*its).second->Trasactions[i].second.Minute);
			sd = (*its).second->Trasactions[i].first.Day;
			sh = (*its).second->Trasactions[i].first.Hour;
			sm = (*its).second->Trasactions[i].first.Minute;
			ed = (*its).second->Trasactions[i].second.Day;
			eh = (*its).second->Trasactions[i].second.Hour;
			em = (*its).second->Trasactions[i].second.Minute;
			Time = 0;
			Price = 0;
			for (int d = sd; d <= ed; d++) {
				tsh = 0;
				teh = 23;
				if (d == ed) {
					teh = eh;
				}
				if(d==sd){
					tsh = sh;
				}
				for (int h = tsh; h <= teh; h++) {
					tsm = 0;
					tem = 59;
					if (h == eh&& d == ed) {
						tem = em;
					}
					if (h == sh&&d==sd) {
						tsm = sm;
					}
					
					Time += tem - tsm + 1;
					if (h == eh && d == ed) {
						Price += (tem - tsm) * H_To_Price[h];
					}
					else {
						Price += (tem - tsm+1) * H_To_Price[h];
					}
				}
			}
			cout << Time -1<< " ";
			printf("$%.2f", Price/100);
			SumPrice += Price;
			cout << endl;
		}
		if(SumPrice!=0)
		printf("Total amount: $%.2f", SumPrice/100);
		cout << endl;
		its++;
	}
	return 0; 
}
/*
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
8
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
//CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line




*/