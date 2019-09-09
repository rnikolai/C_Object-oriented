//Nikolai Rubtcov 134471168
#include <iostream>
#include "Contact.h"
#include <cstring>

using namespace std;
namespace communication {

	Contact::Contact() {
		m_name[0] = '\0';
		m_phoneNumbers = nullptr;
		m_noOfPhoneNumbers = 0;
	}

	Contact::Contact(const char* cName, long long* pNumbers, int num) {
		//safe state 
		m_name[0] = '\0';
		m_phoneNumbers = nullptr;
		m_noOfPhoneNumbers = 0;

		if (pNumbers != nullptr && pNumbers[0] != '\0') {
			m_phoneNumbers = new long long[num];
		}
		int countryCode;
		int areaCode;
		int phoneNumber;
		int x = 0;

		//name validation
		if (cName != nullptr && cName[0] != '\0') {
			strncpy(m_name, cName, 20);
			m_name[20] = '\0';
		}
		//phone number validation
		for (int i = 0; i < num; i++) {
			if (pNumbers[i] > 10000000000 && pNumbers[i] < 999999999999) {
				countryCode = (pNumbers[i] / 10000000000);
				areaCode = ((pNumbers[i] % 10000000000) / 10000000);
				phoneNumber = pNumbers[i] % 10000000;
				if (countryCode > 0 && countryCode <= 19 && areaCode > 0 && areaCode < 999 && phoneNumber >= 1000000 && phoneNumber <= 99999999) {
					m_phoneNumbers[x] = pNumbers[i];
					x++;
				}
			}
			//for the display function
			outputNum = x;
		}
	}
	void Contact::display() {
		int countryCode;
		int areaCode;
		int phoneNumber;
		int firstPartOfPhoneNumber;
		int secondPartOfPhoneNumber;

		if (isEmpty()) {
			cout << "Empty contact!" << endl;
		}
		else {
			cout << m_name << endl;
			if (m_phoneNumbers != nullptr && m_phoneNumbers[0] != '\0') {
				for (int ii = 0; ii < outputNum; ii++) {

					countryCode = (m_phoneNumbers[ii] / 10000000000);
					areaCode = ((m_phoneNumbers[ii] % 10000000000) / 10000000);
					phoneNumber = m_phoneNumbers[ii] % 10000000;
					firstPartOfPhoneNumber = phoneNumber / 10000;
					secondPartOfPhoneNumber = phoneNumber % 10000;

					cout << "(+" << countryCode << ") " << areaCode << " " << firstPartOfPhoneNumber << "-" << secondPartOfPhoneNumber << endl;
				}
			}
		}
	}

	//destructor
	Contact::~Contact() {
		delete[] m_phoneNumbers;
		m_phoneNumbers = nullptr;
	}

	bool Contact::isEmpty() const {
		bool empty;
			if (m_name[0] == '\0' && m_phoneNumbers == nullptr && m_noOfPhoneNumbers == 0) {
				empty = true;
			}
			else {
				empty = false;
			}

			return empty;
	}
}