//Nikolai Rubtcov 134471168 rnikolai
#include <cstring>
#include <iostream>
#include "Hero.h"

using namespace std;


//////////////////////////////////////////////
// Default constructor
//
Hero::Hero ()
{
	strcpy(m_name , "");
	m_maximumHealth = 0;
	m_health = 0;
	m_attack = 0;
}


///////////////////////////////////////////////////
// Constructor
// 
Hero::Hero (const char name[], unsigned maximumHealth, unsigned attack)
{
	strcpy(m_name, name);
	m_maximumHealth = maximumHealth;
	m_health = m_maximumHealth;
	m_attack = attack;
}



/////////////////////////////////////////////////////////
// 
// Hero::display function
void Hero::display (ostream & out) const 
{
	cout << m_name;
}



/////////////////////////////////////////////////
// Hero::isEmpty ()
// return true if the Hero object is uninitialized
//
bool Hero::isEmpty () const 
{
	return (strcmp(m_name,""));
}

/////////////////////////////////////////////////
// sets the Hero object's health back to full
//

void Hero::respawn() {
	m_health = m_maximumHealth;
}
