#ifndef SICT_ITEM_H__
#define ISCT_ITEM_H__
#include "POS.h"
#include "PosIO.h"

namespace ict{
	class Item: public PosIO { // inherited from PosIO
		char m_sku[MAX_SKU_LEN + 1];
		char* m_name;
		double m_price;
		bool m_taxed;
		int m_quantity;
	public:
		// constructors
		Item();// no argument, default
		Item(const char*, const char*, double, bool = true);
		Item(const Item& other);// copy
		
		virtual ~Item() { delete[] m_name; }

		// operator=
		Item& operator=(const Item& other);

		// mutators/setters
		void sku(const char*);
		void price(double);
		void name(const char*);
		void taxed(bool);
		void quantity(int);

		// constant queries/accessors/getters
		const char* sku() const; //returns the address of an unmodifiable character string
		double price() const;// returns a double
		char* name() const; //returns the address of an unmodifiable character string
		int taxed() const; // returns a bool
		int quantity() const;// returns an integer

		double cost() const; // return (m_price = (m_taxed) ? m_price *= TAX + 1 : m_price);
		bool isEmpty() const; // return true if the Item is in a safe empty state.

		// operators
		bool operator==(const char*);
		int operator+=(int);
		int operator-=(int);

	};// class Item
	  
  // non-member
  // operator += 
  double operator+=(double& d, const Item& I);
  // operator << and operator >>
  std::ostream& operator<<(std::ostream& ostr, const Item& rightHand);// posIO.h
  std::istream& operator>>(std::istream& is, Item& rightHand);// posIO.h
}
#endif