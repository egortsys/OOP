#include <iostream>
#include "queue.h"
#include "Trapeze.h"


using namespace std;

void menu(){
	cout << "Нажмите 1 для добавления элемента в очередь " <<endl;
	cout << "Нажмите 2 чтобы извлеч первый элемент из очереди " << endl;
	cout << "Нажмите 3 чтобы вевеcти размер оереди " << endl;
	cout << "Нажмите 5 для выхода " << endl;
}
void menu2(){
	cout << "Нажмите 1 для вывода площади данного эелемента " << endl;
	cout << "Нажмите 2 для возврата к первому меню " << endl;
}


int main(){

	int flag = 0;
	cout << "Введите вместимость очереди " << endl;
	int size;
	cin >> size;
	TQueue qu(size);
	menu();
	cout << "Создана очередь на " << size << " элементов" << endl;
	while(flag != 5) {
		cin >> flag;
		if(flag == 1){
			Trapeze tr(cin);
			qu.Push_back(tr);
			cout << "Элемент добавлен " << endl; 
		}
		else if (flag==2){
			Trapeze tr = qu.Pop(); 
			cout << "Извлечен элемент "<< endl  << tr << endl; 
			int flag2 = 0;
			menu2();
			while(flag2 != 2){
				cin >> flag2;
				if(flag2 == 1){
					cout << "Площадь данной трапеции " << tr.area() << endl;
				}
				else if(flag2  == 2){
					break;
				}
			}
		}
		else if (flag==3){
			cout << "Размер очереди " << qu.Size() << endl; 
		}
		else if (flag == 5){
			return 0;
		} 

	}
} 