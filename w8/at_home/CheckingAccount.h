#ifndef ICT_CHECKINGACCOUNT_H__
#define ICT_CHECKINGACCOUNT_H__

#include "Account.h"

using namespace std;

namespace ict {
	class CheckingAccount : public Account {
	private:
		double transactionFee;

		// TODO: chargeFee subtract transaction fee form the balance
		void chargeFee();

	public:

		// TODO: constructor initializes balance and transaction fee
		CheckingAccount(double funds, double tf);

		// TODO: Write a function prototype to override debit function
		bool debit(double funds);
		// TODO: Write a function prototype to override credit function
		void credit(double funds);
		// TODO: Write a function prototype to  override display function
		ostream& display(ostream& ostr);
	};
};
#endif