#include "stdafx.h"
#include "Class.h"
#include <locale>
#define count 10



int main()
{
	setlocale(LC_ALL, "rus");
	Vector a[count];
	srand((unsigned)time(NULL));
	for (int i = 0; i < count; i++)
	{
		std::cout << std::endl;
		a[i].getVector();
	}
	for (int i = 0; i < count; i++)
	{
		a[i].setVector(rand() % count, rand() % count);
	}
	for (int i = 0; i < count; i++)
	{
		std::cout << std::endl;
		a[i].getVector();
	}
	int min = 0, max = 0;
	for (int i = 1; i < count; i++)
	{
		if (a[i].summ() < a[min].summ())
			min = i;
		if (a[i].summ() > a[max].summ())
			max = i;
	}
	std::cout << std::endl <<  "Минимальная сумма элементов : "  << a[min].summ() << std::endl
		 				   <<  "Максимальная сумма элементов : " << a[max].summ() << std::endl;
	for (int i = 1; i < count - 1; i++)
	{
		a[i].coll_or_not(a[i + 1]);
	}
	for (int i = 1; i < count - 1; i++)
	{
		a[i].ort_or_not(a[i + 1]);
	}
	system("pause");
    return 0;
	
}

