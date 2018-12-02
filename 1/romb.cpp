#include "romb.h"
#include <iostream>
#include "FIGURE.h"
#include <cmath>


double Romb::area() {
	return side*side *sin(angle/57);
}
void Romb::print(){
	std::cout <<"Стороны ромба " << side << std::endl;
}
Romb:: Romb(int a): side(a){
	
}
Romb:: Romb(): Romb(0){

}
Romb:: Romb(std::istream & is){
	std::cout << "Введите желаемую сторону ромба" << " введите меньший угол ромба" << std::endl; 
	is >> side;
	is >> angle;
	std::cout << "Cоздан ромб со сторой " << side << " и меньшим углом " <<  angle << std::endl;
}
