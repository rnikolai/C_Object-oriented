#ifndef PASSENGER_H
#define PASSENGER_H

namespace sict {

	class Passenger {
	private:
		char m_name[32];
		char m_destination[32];
		int m_departureYear;
		int m_departureMonth;
		int m_departureDay;
	public:
		Passenger();
		Passenger(char[], char[]) ;
		void display() const;
		bool isEmpty() const;
		bool canTravelWith(const Passenger&) const;
	};
}
#endif