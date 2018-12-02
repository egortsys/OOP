#include "queue.h"
#include "Trapeze.h" 
#include <cstdlib>

TQueue::TQueue() {
	data = new Trapeze[1];
	capacity = 1;
	size = 0; 
}
TQueue::TQueue(int size_q) {
	data = new Trapeze[size_q];
	capacity = size_q;
	size = 0; 
}


bool TQueue::Empty(){
	return size == 0;
}

void TQueue::Push_back(Trapeze tra){
	if (size != capacity){
		data[size] = tra;
		size++;
	}
	else {
		std::cout << "Очередь переполнена " << std::endl;
	}
}
Trapeze TQueue::Pop(){
	Trapeze ReturnTrapeze = data[0];
	for(int i = 0; i < size -1; i++){
		data[i] = data[i+1];
	}
	size--;
	return  ReturnTrapeze;
}
int TQueue::Size(){
	return size;
}

Trapeze & TQueue::operator[](int index) {
	if ((index > 0)  && (index < size -1)){
		return data[index];
	}
}
TQueue:: ~TQueue(){
	delete [] data;
}
