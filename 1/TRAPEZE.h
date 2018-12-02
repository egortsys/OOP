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
		Trapeze(int,int,int);

		double area() override;
		void print() override; 
		//~Triangle();

		int  side_a;
		int  side_b; 
		int  side_c;

};
#endif