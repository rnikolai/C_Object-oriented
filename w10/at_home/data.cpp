#include <iostream>
#include <iomanip>
#include "data.h"

namespace sict {

	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime,const double* violentCrimeRate, const int* grandTheftAuto, const int n) {
		std::cout << std::setprecision(2) << std::fixed;
		// Q1: print the population change in millions of people
		std::cout << "Population change from 2000 to 2004 is "  << (static_cast<double>(sict::max(population,n)-sict::min(population ,n)) / 1000000 ) << " million" << std::endl;
		
		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005
		std::cout << "Violent Crime trend is " << (violentCrime[0] > violentCrime[n - 1] ? "down" : "up") << std::endl;
	
		// Q3 print the GTA number accurate to 0 decimal places
		std::cout << "There are " << (sict::average(grandTheftAuto, n)/1000000) << " million Grand Theft Auto incidents on average a year" << std::endl;

		// Q4. Print the min and max violentCrime rates
		std::cout << std::setprecision(0);
		std::cout << "The Minimum Violent Crime rate was " << sict::min(violentCrimeRate, n) << std::endl << "The Maximum Violent Crime rate was " << sict::max(violentCrimeRate, n) << std::endl;


	}
}