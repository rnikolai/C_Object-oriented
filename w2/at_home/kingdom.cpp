#include "kingdom.h"
#include <iostream>
#include <cstring>
using namespace std;

void westeros::display(Kingdom* tr){
	cout << tr->m_name <<", population "<< tr->m_population << endl;
}
void westeros::display(Kingdom tr[], int count) {
	int i;
	int totalpop = 0;
	cout << "------------------------------\nKingdoms of Westeros\n------------------------------" << endl;
	for (i = 0; i < count; i++) {
		cout << i + 1 << ". " << tr[i].m_name << ", population " << tr[i].m_population << endl;
		totalpop += tr[i].m_population;
	}
	cout << "------------------------------\nTotal population of Westeros: " << totalpop <<"\n------------------------------"<< endl;
}
void westeros::display(Kingdom tr[], int count, int minval) {
	int i;
	cout << "------------------------------\nKingdoms of Westeros with more than " << minval << " people\n------------------------------" << endl;
	for (i = 0; i < count; i++) {
		if (tr[i].m_population >= minval) {
			cout << tr[i].m_name << ", population " << tr[i].m_population << endl;
		}
	}
	cout << "------------------------------" << endl;
}
void westeros::display(Kingdom tr[], int count, const char name[]) {
	int i;
	int arrsnap = -1;
	cout << "------------------------------\nSearching for kingdom " << name << " in Westeros\n------------------------------"<< endl;
	for (i = 0; i < count; i++) {
		if ( !(strcmp(name,tr[i].m_name))) {
			arrsnap = i;
		}
	}
	if (arrsnap != -1) {
		cout << tr[arrsnap].m_name << ", population " << tr[arrsnap].m_population << endl;
	}
	else {
		cout << name << " is not part of Westeros.\n";
	}
	cout << "------------------------------" << endl;
}