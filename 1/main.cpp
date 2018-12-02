#include <iostream>
#include <cstdlib>
#include "TRAPEZE.h"
#include "romb.h"
#include "PENTAGON.h"
using namespace std; 


bool cheak (int side_a, int side_b, int side_c){
	return (((2*side_a) + side_b) >  side_c); 
}
void print_margins(){
	cout << "1) Расчитать площадь" << endl  << "2) Вывести длины сторон" << endl << "3) Вернуться к выбору фигуры" << endl; 
}



int main(){
	// Создадим меню
	int flag = 0;
	while (flag != 4){ 
		cout << "Выберете фигуру из списка " << endl << "1) Трапеция " << endl << "2) Ромб " << endl << "3) Пятиугольник " << endl << "4) Выход" << endl; 
		cin >> flag; 
		if (flag == 1){
			int side_a = 1, side_b =1, side_c=1;
			int flag_two = 1;
			while(flag_two){
				cout << "Введите желаемые стороны трапеции в формате a,b,c где a - равная с двух стороно боковая сторона,b - верхнее основани, с-нижнее основание"<< endl;
				cout << "Обратите внимание на выполнение условий существования - 2*a + b > c" << endl;
				cin >> side_a >> side_b >> side_c;
				if(cheak(side_a, side_b, side_c)){
					flag_two = 0;
				}
				else {
					cout << "Трапеции с данными сторонами не существует" << endl;
				}
			}
			Trapeze * tra = new Trapeze(side_a, side_b, side_c); 
			tra->print();
			print_margins();
			int flag_lvl_2;
			cin >> flag_lvl_2;
			while(flag_lvl_2!=3){
				if (flag_lvl_2 == 1){
					cout << "Площадь трапеции - "<< tra->area() << endl;
					}
				else if (flag_lvl_2 ==2){
					tra->print();
					}
				else if (flag_lvl_2 ==3){
					delete tra;
				}
				else if (flag_lvl_2 >=4){
					cout << "Пункта с таким номером не существует" << endl;
					}
				cin >> flag_lvl_2; 
				}
			} 

		else if (flag == 2){
			Romb * romb = new Romb(cin);
			print_margins();
			int flag_lvl_2;
			cin >> flag_lvl_2;
			while(flag_lvl_2!=3){
				if (flag_lvl_2 == 1){
					cout << "Площадь ромба - "<< romb->area() << endl;
					}
				else if (flag_lvl_2 ==2){
					romb->print();
					}
				else if (flag_lvl_2 >=4){
					cout << "Пункта с таким номером не существует" << endl;
					}
					else if(flag_lvl_2 ==3){
						delete romb;
					}
				cin >> flag_lvl_2; 
			}
		}
		else if (flag == 3){
			cout << "Введите желаемую сторону пятиугольника " << endl;
			int side;
			cin >> side;
			Pentagon *pent = new Pentagon(side);
			print_margins();
			int flag_lvl_2;
			cin >> flag_lvl_2;
			while(flag_lvl_2!=3){
				if (flag_lvl_2 == 1){
					cout << "Площадь пятиугольника - "<< pent->area() << endl;
					}
				else if (flag_lvl_2 ==2){
					pent->print();
					}
				else if (flag_lvl_2 >=4){
					cout << "Пункта с таким номером не существует" << endl;
				}
				else if(flag_lvl_2 ==3){
					delete pent;
				}
				cin >> flag_lvl_2; 
			}

		}
		else if (flag > 4) {
			cout << "Пункта с таким номером не существует" << endl;
		}
	} 

}
