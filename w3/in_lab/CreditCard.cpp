#include "CreditCard.h"
#include <iostream>
#include <string.h>
using namespace std;

namespace sict {
	 /*void CreditCard::construct(void) {
		 char m_cardHolderName[MAX_NAME_LENGTH] = { 0 };
		unsigned long long m_cardNumber = 0;
		int     m_institutionCode = 0;
		int     m_expiryYear = 0;
		int     m_expiryMonth = 0;
		int m_numberInTheBack = 0;
	}
	void CreditCard::~construct(void) {
	}*/
	void CreditCard::name(const char cardHolderName[]) {
		strcpy(m_cardHolderName, cardHolderName);
	}
	void CreditCard::initialize(unsigned long long creditCardNumber, int instCode, int expiryYear, int expiryMonth, int numberInTheBack) {
		m_cardNumber = creditCardNumber;
		m_institutionCode = instCode;
		m_expiryYear = expiryYear;
		m_expiryMonth = expiryMonth;
		m_numberInTheBack = numberInTheBack;
	}
	void CreditCard::write() const {
		if (isValid()) {
			cout << "Cardholder: " << m_cardHolderName << endl;
			cout << "Card Number: " << m_cardNumber << endl;
			cout << "Institution: " << m_institutionCode << endl;
			cout << "Expires: " << m_expiryMonth <<"/"<< m_expiryYear << endl;
			cout << "Number at the back: " << m_numberInTheBack ;
		}
	}
	bool CreditCard::isValid() const {
		bool out = true;
		if (m_cardHolderName == NULL) {
			out = false;
		}
		else if (MIN_CARD_NUMBER > m_cardNumber || m_cardNumber > MAX_CARD_NUMBER) {
			out = false;
		}
		else if (MIN_INST_NUMBER> m_institutionCode|| m_institutionCode >MAX_INST_NUMBER) {
			out = false;
		}
		else if (MIN_EXP_YEAR> m_expiryYear|| m_expiryYear > MAX_EXP_YEAR) {
			out = false;
		}
		else if (0 > m_numberInTheBack || m_numberInTheBack > 1000) {
			out = false;
		}
		return out;
	}
}
