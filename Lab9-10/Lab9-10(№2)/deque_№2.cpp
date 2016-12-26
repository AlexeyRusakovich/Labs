#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <memory>
#include <vector>
#include "/ООП/Лабараторные/Lab3/Lab3/Inheritence.h"
#include "/ООП/Лабараторные/Lab3/Lab3/Inheritence.cpp"

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	deque<shared_ptr<food_product> > deq;

	deq.push_back(shared_ptr<food_product>(new food_product("Lemon", 1, 20, 72)));
	deq.push_back(shared_ptr<food_product>(new food_product("Apple", 2, 40, 144)));
	deq.push_back(shared_ptr<food_product>(new food_product("Orange", 3, 40, 36)));

	////////// 1 //////////	
	cout << "\t\t///////////// 1 /////////////" << endl;

	cout << "Вывод элементов двусторонней очереди dec:" << endl;
	for (auto it : deq)
	{
		it->information();
	}
	cout << endl << endl;

	////////// 2 //////////	
	cout << "\t\t///////////// 2 /////////////" << endl;
	deq.erase(deq.begin());							// Удаление элементов c начала двусторонней очереди

	deq.push_front(shared_ptr<food_product>(new food_product("Banana", 5, 120, 24)));

	cout << "Вывод измененной двусторонней очереди:" << endl;
	for (auto it : deq)
	{
		it->information();
	}
	cout << endl << endl;

////////// 3 //////////
	cout << "\t\t///////////// 3 /////////////" << endl;
	cout << "Просмотр двусторонней очереди с помощью shared_ptr:" << endl;
	unsigned int i = 0;
	for (shared_ptr<food_product> p = deq[i]; i < deq.size();)
	{
		p = deq[i++];
		p->information();	
	}
	cout << endl << endl;

	cout << "Просмотр двусторонней очереди с помощью итератора:" << endl;
	for (auto it_deq = deq.cbegin(); it_deq != deq.end(); it_deq++)
	{
		(*(it_deq))->information();
 	}
	cout << endl << endl;

	////////////// 4 //////////

	cout << "\t\t///////////// 4 /////////////" << endl;

	deque <shared_ptr<food_product> > deq2;
	deq2.push_back(shared_ptr<food_product>(new food_product("Qiwi", 1, 20, 72)));
	deq2.push_back(shared_ptr<food_product>(new food_product("Watermelon", 2, 40, 144)));
	deq2.push_back(shared_ptr<food_product>(new food_product("Strawbery", 3, 40, 36)));	

	cout << "Вывод двусторонней очереди deq2:" << endl;
	for (auto it_deq : deq2)
	{
		it_deq->information();
	}
	cout << endl << endl;


	////////// 5 //////////

	cout << "\t\t///////////// 5 /////////////" << endl;
	cout << "Удаление 2-х элементов из двусторонней очереди deq2 начиная с 1-го:" << endl << endl;


	auto it_deq = deq2.begin();
	for (int i = 0; i < 2; i++)
	{
		deq2.erase(it_deq);
		it_deq = deq2.begin();
	}

	cout << "\t\tВывод deq2:" << endl;
	for (auto it_deq : deq2)
	{
		it_deq->information();
	}
	cout << endl;

	cout << "\t\tВывод deq:" << endl;
	for (auto it_deq : deq)
	{
		it_deq->information();
	}
	cout << endl << endl;
	
	
	return 0;
}