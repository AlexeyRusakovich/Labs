#include "stdafx.h"
#include "Class.h"
#include <iostream>


Vector::Vector(Vector &obj)
{
	std::cout << "�������� ����������� �����������!" << std::endl;
	x = obj.x;
	y = obj.y;
}
Vector::Vector(int x1, int y1)
{
		  
	std::cout << "�������� ����������� � 2-�� �����������!" << std::endl;
	x = x1;
	y = y1;
}
void   Vector::setVector(int x1, int y1)
{
	x = x1;
	y = y1;
}
void   Vector::module()
{
	std::cout << "������ ������� ������� ����� : " << pow((this->x)^2 + (this->y)^2, 1.0 / 2.0) << std::endl;
}
void   Vector::scal_mul(class Vector obj)
{
	std::cout << std::endl << "��������� ���������� ������������ : " << (x*obj.x + y*obj.y) << std::endl;
}
void   Vector::add(class Vector obj)
{
	x += obj.x;
	y += obj.y;
	std::cout << "���������� �������� 2-� �������� �������� ������ � ������������ : ( " << x <<
		" , " << y << " ) ." << std::endl;
}
void   Vector::sub(class Vector obj)
{
	x -= obj.x;
	y -= obj.y;
	std::cout << "���������� ��������� 2-� �������� �������� ������ � ������������ : A( " << x <<
		" , " << y << " ) ." << std::endl;
}
void   Vector::mul_const(int constanta)
{
	x *= constanta;
	y *= constanta;
	std::cout << "���������� ��������� ������� �� ��������� �������� ������ � ������������ : A( " << x <<
		" , " << y << " ) ." << std::endl;
}
void   Vector::coll_or_not(Vector obj)
{
	if ((y != 0) & (obj.y != 0))
	{
		if(x/y == obj.x/obj.y)
			std::cout << "������� �����������" << std::endl;
		else
			std::cout << "������� �� �����������" << std::endl;
	}
	else
	{
		bool a = false;
		if ((y == 0) & (obj.y == obj.x))
		{
			std::cout << "������� �����������" << std::endl;
			bool a = true;
		}
		if ((obj.y == 0) & (y == x))
		{
			std::cout << "������� �����������" << std::endl;
			bool a = true;
		}
		if (!a)
			std::cout << "������� �� �����������" << std::endl;
			
	};

}
void   Vector::ort_or_not(Vector obj)
{
	if ((x*obj.x + y*obj.y) == 0)
		std::cout << "������������" << std::endl;
	else
		std::cout << "�� ������������" << std::endl;
}
void   Vector::getVector()
{
	std::cout << "���������� ������� : x = " << x << " y = " << y << std::endl;
	this->module();
}
int    Vector::summ()
{
	int summa = this->x + this->y;
	return summa;
}
