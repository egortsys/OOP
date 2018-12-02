#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <iostream>
#include <cstdlib>
#include "FIGURE.h"
#include  <cmath>


class Trapeze: public FIGURE {
	public: 
		Trapeze();
		Trapeze(std::istream & is);
		Trapeze(int side_a,int side_b ,int side_c);
		friend std::ostream & operator <<  (std::ostream & os, const Trapeze  &tra); 
		friend std::istream & operator >> (std::istream & is, Trapeze &tra);
		friend bool operator == (Trapeze tr, Trapeze tr2);

		double area() override;
		void print() override; 
		~Trapeze();

		int  side_a;
		int  side_b; 
		int  side_c;

};
#endif