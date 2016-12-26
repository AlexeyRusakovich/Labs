#include "stdafx.h"

product::product(char* name, int costt , int amountt)
{
	strcpy(nameOfProduct, name);
	cost = costt;
	amount = amountt;
}
void product::information()
{
	cout << endl << "Наименование товара : " << nameOfProduct << endl;
	cout << "Количетво товара в продаже : "  << amount << endl;
	cout << "Цена : " << cost << " BYN" << endl;
}
void product::addProduct(int a)
{
	amount += a;
	cout << endl << "Товара в наличии : " << amount << endl;
}
void product::removeFromSale(int a)
{
	if (a <= amount)
	{
		amount -= a;
		cout << endl << "Осталось : " << amount << " в наличии" << endl;
	}
	else
		cout << endl <<  "Нет столько товара в наличии, на складе : " << amount << " шт." << endl;
}
food_product::food_product(char* name, int a, int b, int c) : product::product(name, a, b)
{
	shelfLife = c;
}
void food_product::information()
{
	product::information();
	cout << "Срок годности : " << shelfLife << " часа" << endl;
}