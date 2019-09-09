//Nikolai Rubtcov 134471168

#include "Passenger.h"
#include <iostream>
#include <cstring>

using namespace std;

namespace sict {
	
	Passenger::Passenger() {
		m_name[0] = '\0';
		m_destination[0] = '\0';
		m_departureYear = 0;
		m_departureMonth = 0;
		m_departureDay = 0;
	}
	
    Passenger::Passenger (char name[] , char dest[]){
		if (dest != nullptr && name != nullptr && dest[0] != 0 && name[0] != 0) {
			strcpy(m_name, name);
			strcpy(m_destination, dest);
			m_departureYear = 2017;
			m_departureMonth = 7;
			m_departureDay = 1;
		}
		else {
			strcpy(m_name, "\0");
			strcpy(m_destination, "\0");
			m_departureYear = 0;
			m_departureMonth = 0;
			m_departureDay = 0;
		}
	}
	
	bool Passenger::canTravelWith(const Passenger& pass) const {
		return (!(strcmp(m_destination, pass.m_destination)) && (m_departureDay == pass.m_departureDay) && (m_departureMonth == pass.m_departureMonth) && (m_departureYear == pass.m_departureYear));
	}

	bool Passenger::isEmpty() const{
		return ((m_name == '\0') && (m_destination == '\0') && m_departureYear ==  m_departureMonth ==  m_departureDay == 0);
	}
	void Passenger::display() const
	{
		if (!isEmpty()){
			cout << m_name << " - " << m_destination << endl;
		}
		else{
			cout << "No passenger!" << endl;
		}
	}
}