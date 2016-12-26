#include "stdafx.h"

int main()
{
	setlocale(LC_ALL, "");
	// Наш класс контроллер
	Gift MyGift;	

	// Наименование, масса, цена, высота, ширина, длина
	Subject roses("Розы", 1000, 10, 5,  5,  50); 
	Subject cake( "Торт", 2000, 15, 20, 30, 30);
	Subject wine( "Вино", 750,  20, 35, 7,  7);

	// Добавляем наши предметы в подарок
	MyGift.add(&roses);
	MyGift.add(&cake);
	MyGift.add(&wine);

	// Вывод предметов в подарке
	MyGift.PrintList();

	// Нахождение предмета с наименьшей массой
	MyGift.getLeastMass();

	// Удаление элемента с наименованием "Вино"
	MyGift.extract("Вино");

	// Вывод предметов в подарке
	MyGift.PrintList();

	// Сортировка элементов 
	MyGift.sort();
	MyGift.PrintList();
	
    return 0;
}

