//Rubtcov Nikolai rnikolai@myseneca.ca 134471168
#include "Fraction.h"

using namespace std;

namespace sict{
    Fraction::Fraction(){  
            denom =-1;              // safe empty state
    }
    
    Fraction::Fraction(int n, int d) // n: numerator, d: denominator
    { 
        if(n >= 0 && d > 0){
            num = n;
            denom = d;
            reduce();
        }
        else 
            denom =-1;              // set to safe empty state
    }

    int Fraction::gcd()                                        // returns the greatest common divisor of num and denom 
    {
        int mn = min();                                        // min of num and denom
        int mx = max();                                        // mX of num and denom

        for (int x=mn ; x > 0 ; x--)                           // find the greatest common divisor
            if( mx % x == 0 &&  mn % x == 0)
                return x;
        return 1;

    } 

    void Fraction::reduce()                                         // simplify the Fraction number  
    {
        int tmp = gcd();
        num /= tmp;
        denom /= tmp;
    }

    int Fraction::max ()
    {
        return (num >= denom) ? num : denom; 
    }

    int Fraction::min()
    {
        return (num >= denom) ? denom : num; 
    }
  
    // TODO: Copy-paste the implementation of member isEmpty function from the in_lab part answer HERE
	bool Fraction::isEmpty()const {
		return (denom == -1);
	}
    // TODO: Copy-paste the implementation of member display function from the in_ab part answer HERE
	void Fraction::display()const {
		if (isEmpty()) {
			cout << "Invalid Fraction Object!";
		}
		else if (denom == 1) {
			cout << num;
		}
		else {
			cout << num << "/" << denom;
		}
	}

    // TODO: Copy-paste the implementation of member operator+= function from the in_lab part answer HERE
	Fraction Fraction::operator+= (Fraction toadd) {
		if (!(isEmpty() || toadd.isEmpty())) {
			num = num*toadd.denom + toadd.num*denom;
			denom = denom*toadd.denom;
			this->reduce();
		}
		else {
			Fraction(*this);
		}
		return *this;
	}

    // TODO: Copy-paste the implementation of member operator+ function from the in_ab part answer HERE
	Fraction Fraction::operator+(Fraction toadd)const {
		Fraction output(0, -1);
		if (!(isEmpty() || toadd.isEmpty())) {
			output.num = num*toadd.denom + toadd.num*denom;
			output.denom = denom*toadd.denom;
			output.reduce();
		}
		return output;
	}
    // TODO: Copy-paste the implementation of member operator* function from the in_lab part answer HERE
	Fraction Fraction::operator*(Fraction tostar)const {
		Fraction output(0, -1);
		if (!(isEmpty() || tostar.isEmpty())) {
			output.num = num*tostar.num;
			output.denom = denom*tostar.denom;
			output.reduce();
		}
		return output;
	}

    // TODO: write the implementation of member operator== function HERE
	bool Fraction::operator==(Fraction compare)const {
		return ((!(isEmpty() || compare.isEmpty())) && (num*compare.denom == compare.num*denom));
	}
    // TODO: write the implementation of member operator!= function HERE
	bool Fraction::operator!=(Fraction compare)const {
		return ((!(isEmpty() || compare.isEmpty())) && (num*compare.denom != compare.num*denom));
	}
    // TODO: write the implementation of member operator double () function HERE
    /*Fraction::operator double()const{
		return ((double)num / (double)denom);
	}
    // TODO: write the implementation of member operator double () function HERE
	Fraction::operator int()const {
		return ((int)num/(int)denom);
	}*/

}