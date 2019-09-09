
#define _CRT_SECURE_NO_WARNINGS

#include "Error.h"
#include <iostream>
#include <cstring>

namespace sict
{
ErrorMessege::ErrorMessege()
{
	m_message = nullptr;
}

ErrorMessege::ErrorMessege(const char *errorMessage)
{
	m_message = nullptr;
	message(errorMessage);
}

void ErrorMessege::operator=(const char *errorMessage)
{
	//clear();//dealloc m_message
	//message(errorMessage);
	delete[] m_message;
	m_message = nullptr;
	m_message = new char[strlen(errorMessage) + 1];
	strcpy(m_message, errorMessage);
}

void ErrorMessege::clear()
{
	delete[] m_message;
	m_message = nullptr;
}

bool ErrorMessege::isClear() const
{
	bool clear = false;
	if (m_message == nullptr)
	{
		clear = true;
	}
	return clear;
}

void ErrorMessege::message(const char *value)
{
	clear(); //dealloc m_message
	//delete[] m_message;
	m_message = new char[strlen(value) + 1];
	strcpy(m_message, value);
}

ErrorMessege::operator const char *() const
{
	return m_message;
}

ErrorMessege::operator bool() const
{
	return isClear();
}

std::ostream &operator<<(std::ostream &ostr, const ErrorMessege &em)
{
	if (em.isClear()){}
	else{
		ostr << em.m_message;
	}

	return ostr;
}

} // namespace sict