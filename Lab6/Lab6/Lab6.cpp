#include "stdafx.h"
using namespace std;


int main()
{
	setlocale(LC_ALL, "");

	List list1(1);	// Создание списка list1
	List list2(2);	//				и  list2

	cout << "Добавление элементов 1, 2, 3, 4 в список list1" << endl;
	list1.add(2);
	list1.add(3);
	list1.add(4);
	list1.PrintList("list1");
	cout << endl << endl;

	cout << "Добавление элементов 5, 6, 7, 8 в список list2" << endl;
	list2.add(5);
	list2.add(6);
	list2.add(7);
	list2.add(8);
	list2.PrintList("list2");
	cout << endl << endl;

	cout << "Результат сложения списка list1 и list2" << endl;
	list1 + list2;
	list1.PrintList("list1");
	cout << endl << endl;

	cout << "Удаление 1-го элемента из листа1 и листа2" << endl;
	--list1;
	list1.PrintList("list1");
	cout << endl << endl;
	--list2;
	list2.PrintList("list2");
	cout << endl << endl;

	cout << "Присваивание листу1 лист2" << endl;
	list1 = list2;
	list1.PrintList("list1");
	cout << endl << endl;
    return 0;
}

