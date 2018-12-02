
#ifndef OCTAGON_H
#define OCTAGON_H
#include <iostream>
#include "FIGURE.h"
class  Pentagon: public FIGURE
{
public:
	Pentagon();
	Pentagon(std::istream & is);
	Pentagon(int);

	double area() override;
	void print() override;



	int side;
	
};


#endif