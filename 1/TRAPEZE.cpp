#include "FIGURE.h"
#include "TRAPEZE.h"
#include <iostream>
#include <cmath>



Trapeze:: Trapeze(): Trapeze(0, 0, 0){
}

Trapeze:: Trapeze(int i, int j, int k): side_a(i), side_b(j), side_c(k){

	std::cout << "Trapeze created" << side_a <<" "<< side_a<< " "<< side_b << " " << side_c << std::endl; 
} 
Trapeze::Trapeze(std::istream & is){
	is >> side_a; 
	is >> side_b;
	is >> side_c;

}

 double Trapeze::area (){
 	double h = side_a*(sin((side_c - side_b/2)/side_a));
 	return (((side_b + side_c)/2) *h);

 }

 void Trapeze::print(){
 	std::cout << " a= " << side_a <<  " a2= "<< side_a <<  " b= " << side_b << " c= " << side_c << std::endl;
 }
