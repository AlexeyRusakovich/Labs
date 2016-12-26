#include "stdafx.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	try{

	List<double> list1(1);		
	List<double> list2(2);		
	//List<int> list3(-1);			// Cоздание списка list3 с неверным параметром (генерация исключения)
	//--list3;						// Извлечение последнего элемента из пустого списка (генерация исключения)
	//list3.PrintList("list3");		// Вывод пустого списка (генерация исключения)
	//list3.pop(2);					// Извлечение элемента (генерация исключения)
	//getmin<List<int>,int>(list3);	// Нахождения минимального элемента в пустом списке (генерация исключения)

	
	// Тестирование работы шаблонных функций
	cout << "Добавление элементов 1, 2, 3, 4 в список list1" << endl;
	list1.add(2.3);
	list1.add(3.5);
	list1.add(4.7);
	list1.PrintList("list1");
	cout << endl << endl;

	cout << "Добавление элементов 5, 6, 7, 8 в список list2" << endl;
	list2.add(5.2);
	list2.add(6);
	list2.add(7.1);
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

	// Глобальная шаблонная функция вычисляющая минимальное значение списка
	getmin<List<double>,double>(list1);
	}
	catch (MyException e)
	{
		cerr << e.what() << "\t" << e.getMessage() << "\tValue: " << e.getX() << endl;
	}
	catch (...)
	{
		cerr << "Unexpected exception!" << endl;
	}

    return 0;
}

