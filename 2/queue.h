#ifndef QUEUE_H
#define  QUEUE_H

#include <cstdlib>
#include <iostream>
#include "Trapeze.h"
class TQueue  {
public:
	TQueue();
	TQueue(int size_q);
	bool Empty();
	Trapeze Pop();
	void Push_back(Trapeze tra);
	int Size(); 
	~TQueue();
	Trapeze & operator[](int number);
	Trapeze * data;
	int size;
	int capacity;
};


#endif 
