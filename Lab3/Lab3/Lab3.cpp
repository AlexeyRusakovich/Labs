// Lab3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{
	setlocale(LC_ALL, "");
	product a[2];
	food_product b[2];
	a[0] = product("����",100,10);
	a[1] = product("�����", 5, 1000);
	b[0] = food_product("����", 10, 30, 24);
	b[1] = food_product("�������", 1, 2000, 72);
	a[0].information();								// ����� ���������� �� ��������
	a[1].information();
	b[0].information();
	b[1].information();

	b[0].addProduct(10);							// ����� �� ����� 10 ������
	b[0].information();

	b[1].removeFromSale(1999);						// ������� 1999 ������
	b[1].information();
    return 0;
}

