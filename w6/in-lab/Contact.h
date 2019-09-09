//Nikolai Rubtcov 134471168
#ifndef CONTACT_H_244_
#define CONTACT_H_244_

namespace communication{	
	class Contact
	{
		char m_name[21];
		long long* m_phoneNumbers;
		int m_noOfPhoneNumbers;
		int outputNum; 
	public:
	
		Contact();
		Contact(const char*, long long*, int );
		~Contact();
	
		void display();
		bool isEmpty() const;

	public:

		Contact(const Contact& other) = delete;
		Contact& operator=(const Contact& other) = delete;
	};
}
#endif