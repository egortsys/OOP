#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include "FIGURE.h"

class Romb: public FIGURE {
	public:
		Romb();
		Romb(std::istream & is);
		Romb(int a);

		double area() override;
		void print() override;

		int side; 
		double angle;

};
#endif