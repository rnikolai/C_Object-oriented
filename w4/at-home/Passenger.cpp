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
	
    Passenger::Passenger (const char *name,const char *dest){
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

	void Passenger::travelWith(const Passenger* arrPassengers,const int size) const {
		int x = 0;
		if (arrPassengers != nullptr && size > 0) {
			int _output[size];
			for (int i = 0; i < size; i++) {
				if (m_departureYear == arrPassengers[i].m_departureYear && m_departureMonth == arrPassengers[i].m_departureMonth &&	m_departureDay == arrPassengers[i].m_departureDay && strcmp(m_destination, arrPassengers[i].m_destination) == 0) {
					_output[x] = i;
					x++;
				}
			}
			if (x < size) {
				cout << m_name << " will be accompanied by";
				for (int i = 0; i < x; i++) {
					cout << " " << arrPassengers[_output[i]].m_name;
					if (i != (x - 1)) cout << ",";
				}
				cout << "." << endl;
			}
			if (x == size) {
				cout << "Everybody can join " << m_name << " on vacation!" << endl;
				cout << m_name << " will be accompanied by";
				for (int i = 0; i < x; i++) {
					cout << " " << arrPassengers[_output[i]].m_name;
					if (i != (x - 1)) cout << ",";
				}
				cout << "." << endl;
			}
		}
		if (x == 0) {
			cout << "Nobody can join " << m_name << " on vacation!" << endl;
		}
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