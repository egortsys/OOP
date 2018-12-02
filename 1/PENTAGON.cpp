#include "PENTAGON.h"
#include "FIGURE.h"
#include <iostream>
#include <cstdlib>
#include <cmath>


Pentagon:: Pentagon():Pentagon(0){}
Pentagon:: Pentagon(std::istream & is){
	std::cout << "Введите желаемую сторону правильного пятиугольника  " << std::endl;
	is >> side;
} 
Pentagon:: Pentagon(int side_a): side(side_a){;
}

double Pentagon::area(){
	return (1.25 * side * side * (1/ atan(3.14/5)));
}
void Pentagon:: print() {
	std::cout << "Сторона правильного пятиугольника " << side <<std::endl;
}
