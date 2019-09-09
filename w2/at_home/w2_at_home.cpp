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
	// testing that "display(...)" works
	cout << "------------------------------" << endl
		<< "The first kingdom of Westeros" << endl
		<< "------------------------------" << endl;
	display(&pKingdoms[0]);
	cout << "------------------------------" << endl << endl;

	// testing that the first overload of "display(...)" works
	display(pKingdoms, count);
	cout << endl;


	// testing that the second overload of "display(...)" works
	display(pKingdoms, count, 345678);
	cout << endl;


	// testing that the third overload of "display(...)" works
	display(pKingdoms, count, "Mordor");
	cout << endl;

	display(pKingdoms, count, "The_Vale");
	cout << endl;

	delete [] pKingdoms;
	return 0;
}