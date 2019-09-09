#include "kingdom.h"
#include <iostream>
using namespace std;

void westeros::display(Kingdom* tr){
	cout << tr->m_name <<" ,population "<< tr->m_population << endl;
}
