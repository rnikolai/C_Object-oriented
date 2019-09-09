#include <iostream>
#include <cstring>

namespace sict {
	// These numbers define 
	// a) the range of data we expect to see in this workshop
	//    0 to 1 billion
	//    use them in the min and max function
	// b) the output column width for a single data field
	const int LARGEST_NUMBER  = 1000000000; // 1,000,000,000
	const int SMALLEST_NUMBER = 0;          
	const int COLUMN_WIDTH    = 15;

	// max returns the largest item in data
	template <typename T>
	T max(const T* data, int N){
		int largest = SMALLEST_NUMBER;
		for (int i = 0; i < N; i++) {
			if (largest <= data[i]) {
				largest = data[i];
			}
		}
		return largest;
	}
	// min returns the smallest item in data
	template <typename T>
	T min(const T* data, int N){
		int min = LARGEST_NUMBER;
		for (int i = 0; i < N; i++) {
			if (min > data[i]) {
				min = data[i];
			}
		}
		return min;
	}
	// sum returns the sum of n items in data
	template <typename T>
	T sum(T *data[], int N){
		int sum = 0;
		for (int i = 0; i < N; i++) {
			sum += data[i];
		}
		return sum;
	}
	// average returns the average of n items in data
	template <typename T>
	double average(T data[], int N){
		int sum = 0;
		for (int i = 0; i < N; i++) {
			sum += data[i];
		}
		return (sum / N);//autocast since return type is double
	}
	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	template<class T>
	bool read(std::istream& input, T* pData, int N){
		char comma;

		// read N  numbers separated by commas
		for (int i = 0; i< N; i++){
			T number;
			input >> comma;
			if (comma != ',') return false;
			if (input >> number){
				pData[i] = number;
			}
			else{
				return false;
			}

		}
		return true;
	}
	// display inserts n items of data into std::cout
	template<class T>
	void display(const char* rowName, T *pData, int N){
		std::cout.width(20);
		std::cout << rowName;
		for (int i = 0; i < N; i++){
			std::cout.width(COLUMN_WIDTH);
			std::cout << pData[i];
		}
		std::cout << std::endl;
	}

	template<typename T>
	bool readRow(std::istream& input, const char* name, T* pData, int N){
		char rowname[2000];
		//char comma;
		bool ok = true;

		// robust error handling
		if (input.bad()){
			ok = false;
		}

		if (ok){
			// read the name of the row first
			input.get(rowname, 2000, ',');
			// note: get will read a string upto the , character
			// it will leave the , character in the input buffer 

			// if the user is trying to read the wrong row, return an error
			if (strcmp(rowname, name) != 0)
			{
				// wrong row
				cout << "Cannot parse row for " << name << endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
		{
			// read in the data array
			ok = read(input, pData, N);
		}
		// finish the line
		input.ignore(2000, '\n');
		return ok;
	}
	
	void answers(const int*, const int*, const int*, const double*, const int*, const int n);

}