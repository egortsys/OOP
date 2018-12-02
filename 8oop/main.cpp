#include <iostream>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <random>
#include "TQueue.h"
#include "TQueueItem.h"
#include "TIterator.h"
#include "Figure.h"
#include "Rhombus.h"
#include "Pentagon.h"
#include "Trapeze.h"
/*#include "RemoveCriteriaBySquare.h"
#include "RemoveCriteriaRhombus.h"*/

void menu()
{
    std::cout << "1. Push rhombus in queue"  << std::endl;
    std::cout << "2. Push pentagon in queue"  << std::endl;
    std::cout << "3. Push trapeze in queue"  << std::endl;
    std::cout << "4. Pop element"  << std::endl;
    std::cout << "5. Print queue" << std::endl;
    std::cout << "6. Menu"  << std::endl;
    std::cout << "7. Exit"  << std::endl;
}

void TestQueue() {
    Queue <TQueue<Figure>, Figure> q;
    char cmd;
    while ( std::cin >> cmd ) {
        switch (cmd) {
        case '1':
            q.InsertSubitem(std::shared_ptr <Figure> (new Rhombus(std::cin)));
            break;
        case '2':
            q.InsertSubitem(std::shared_ptr <Figure> (new Pentagon(std::cin)));
            break;
        case '3':
            q.InsertSubitem(std::shared_ptr <Figure> (new Hexagon(std::cin)));
            break;
        case '4':
            double square;
            std::cin >> square;
            q.DeleteSubitems(std::shared_ptr <IRemoveCriteria<Figure>> (new RemoveCriteriaBySquare<Figure>(square)));
            break;
        case '5':
            q.DeleteSubitems(std::shared_ptr <IRemoveCriteria<Figure>> (new RemoveCriteriaRhombus<Figure>()));
            break;
        case 'p':
            std::cout << q << std::endl;
            break;
        default:
            break;
        }
    }
}

void TestSort() {
    int numTests;
    std::cin >> numTests;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution1(1, 100);
    std::uniform_int_distribution<int> distribution2(1, 100);
    generator.seed(time(nullptr));
    TQueue <Figure> q1;
    TQueue <Figure> q2;
    for (int i = 0; i < numTests; i++) {
        int side = distribution1(generator);
        int angle = distribution2(generator);
        q1.Push(std::shared_ptr <Figure> (std::make_shared <Rhombus> (side,angle)));
        q2.Push(std::shared_ptr <Figure> (std::make_shared <Rhombus> (side,angle)));
    }
    auto begin = std::chrono::high_resolution_clock::now();
    q1.Sort();
    for ( TIterator <TQueueItem <Figure>, Figure> i = q1.begin(); i != q1.end(); i++){
		(*i)->Print();
		std::cout << (*i)->Square() << std::endl;}
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Sort:" << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;
    begin = std::chrono::high_resolution_clock::now();
    q2.ParallelSort();
    for ( TIterator <TQueueItem <Figure>, Figure> i = q2.begin(); i != q2.end(); i++){
	(*i)->Print();
	std::cout << (*i)->Square() << std::endl;}
    end = std::chrono::high_resolution_clock::now();
    std::cout << "ParallelSort:" << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;
}

int main(void)
{
    TestSort();
    //TestQueue();
    TQueue<Figure> q;
    char cmd;
    menu();
    while ( std::cin >> cmd )
    {
        switch (cmd) {
        case '1':
            q.Push(std::shared_ptr <Figure> (std::make_shared <Rhombus> (std::cin)));// new Rhombus(std::cin)));
            break;
        case '2':
            q.Push(std::shared_ptr <Figure> (std::make_shared <Pentagon> (std::cin)));// new Pentagon(std::cin)));
            break;
        case '3':
            q.Push(std::shared_ptr <Figure> (std::make_shared <Trapeze> (std::cin)));// new Trapeze(std::cin)));
            break;
        case '4':
            q.Pop()->Print();
            break;
        case '5':
            for ( TIterator <TQueueItem <Figure>, Figure> i = q.begin(); i != q.end(); i++)
                (*i)->Print();
            break;
        case '6':
            menu();
            break;
        case '7':
            return 0;
            break;
        case 's':
            q.ParallelSort();
            break;
        default:
            break;
        }
    }
}