#include "stdafx.h"

product::product(char* name, int costt , int amountt)
{
	strcpy(nameOfProduct, name);
	cost = costt;
	amount = amountt;
}
void product::information()
{
	cout << endl << "������������ ������ : " << nameOfProduct << endl;
	cout << "��������� ������ � ������� : "  << amount << endl;
	cout << "���� : " << cost << " BYN" << endl;
}
void product::addProduct(int a)
{
	amount += a;
	cout << endl << "������ � ������� : " << amount << endl;
}
void product::removeFromSale(int a)
{
	if (a <= amount)
	{
		amount -= a;
		cout << endl << "�������� : " << amount << " � �������" << endl;
	}
	else
		cout << endl <<  "��� ������� ������ � �������, �� ������ : " << amount << " ��." << endl;
}
food_product::food_product(char* name, int a, int b, int c) : product::product(name, a, b)
{
	shelfLife = c;
}
void food_product::information()
{
	product::information();
	cout << "���� �������� : " << shelfLife << " ����" << endl;
}