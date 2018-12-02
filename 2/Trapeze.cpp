#include "FIGURE.h"
#include "Trapeze.h"
#include <iostream>
#include <cmath>



Trapeze:: Trapeze(): Trapeze(0, 0, 0){
}

Trapeze:: Trapeze(int i, int j, int k): side_a(i), side_b(j), side_c(k){

	//std::cout << "Trapeze created" << side_a <<" "<< side_a<< " "<< side_b << " " << side_c << std::endl; 
} 
Trapeze::Trapeze(std::istream & is){
	std::cout << "Введите стороны трапеции " << std::endl;
	is >> side_a; 
	is >> side_b;
	is >> side_c;

}
std::ostream & operator << (std::ostream & os, const Trapeze  &tra) {
	os << "Тип фигуры - трапеция" << std::endl << "Боковые стороны равны - " ; 
	os << tra.side_a << " " << std::endl;
	os <<"Первое основание - "<<tra.side_b << " " << std::endl;
	os <<"Второе основание - " <<tra.side_c << " " << std::endl;
	return os;
}
std::istream & operator >> (std::istream & is,Trapeze & tra){
	is >> tra.side_a;
	is >> tra.side_b;
	is >> tra.side_c;
	return is; 
}

 double Trapeze::area (){
 	double h = side_a*(sin((side_c - side_b/2)/side_a));
 	return (((side_b + side_c)/2) *h);

 }

 void Trapeze::print(){
 	std::cout << " a= " << side_a <<  " a2= "<< side_a <<  " b= " << side_b << " c= " << side_c << std::endl;
 }

 Trapeze:: ~Trapeze(){ 
 } 
 bool operator==(Trapeze tr, Trapeze tr2){
 	return ((tr.side_a = tr2.side_a)&& (tr.side_b = tr2.side_b)&&(tr.side_c = tr2.side_c));
 }