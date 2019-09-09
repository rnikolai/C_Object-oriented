#include <iostream>
#include "kingdom.h"

using namespace std;
using namespace westeros;

int main(void)
{
	int count = 0;
	Kingdom* pKingdoms = nullptr;
	cout << "==========" << "\n"
		 << "Input data" << "\n"
		 << "==========" << "\n"
		 << "Enter the number of kingdoms: ";
	cin >> count;
	cin.ignore();
	pKingdoms = new Kingdom[count];
	for (int i = 0; i < count; ++i)
	{
		cout << "Enter the name for kingdom #" << i+1 << ": ";
		cin >> pKingdoms[i].m_name;
		cout << "Enter the number people living in " << pKingdoms[i].m_name << ": " ;
		cin >> pKingdoms[i].m_population;
	}
	cout << "==========" << endl << endl;

	cout << "------------------------------" << endl
		<< "The first kingdom of Westeros" << endl
		<< "------------------------------" << endl;
	display(&pKingdoms[0]);
	cout << "------------------------------" << endl << endl;

	delete [] pKingdoms;
	return 0;
}