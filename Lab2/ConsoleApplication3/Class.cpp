#include "stdafx.h"
#include "Class.h"
#include <iostream>


Vector::Vector(Vector &obj)
{
	std::cout << "Работает конструктор копирования!" << std::endl;
	x = obj.x;
	y = obj.y;
}
Vector::Vector(int x1, int y1)
{
		  
	std::cout << "Работает конструктор с 2-мя параметрами!" << std::endl;
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
	std::cout << "Модуль данного вектора равен : " << pow((this->x)^2 + (this->y)^2, 1.0 / 2.0) << std::endl;
}
void   Vector::scal_mul(class Vector obj)
{
	std::cout << std::endl << "Результат скалярного произведения : " << (x*obj.x + y*obj.y) << std::endl;
}
void   Vector::add(class Vector obj)
{
	x += obj.x;
	y += obj.y;
	std::cout << "Резульатом сложения 2-х векторов является вектор с координатами : ( " << x <<
		" , " << y << " ) ." << std::endl;
}
void   Vector::sub(class Vector obj)
{
	x -= obj.x;
	y -= obj.y;
	std::cout << "Резульатом вычитания 2-х векторов является вектор с координатами : A( " << x <<
		" , " << y << " ) ." << std::endl;
}
void   Vector::mul_const(int constanta)
{
	x *= constanta;
	y *= constanta;
	std::cout << "Резульатом умножения вектора на константу является вектор с координатами : A( " << x <<
		" , " << y << " ) ." << std::endl;
}
void   Vector::coll_or_not(Vector obj)
{
	if ((y != 0) & (obj.y != 0))
	{
		if(x/y == obj.x/obj.y)
			std::cout << "Вектора Коллениарны" << std::endl;
		else
			std::cout << "Вектора не Коллениарны" << std::endl;
	}
	else
	{
		bool a = false;
		if ((y == 0) & (obj.y == obj.x))
		{
			std::cout << "Вектора Коллениарны" << std::endl;
			bool a = true;
		}
		if ((obj.y == 0) & (y == x))
		{
			std::cout << "Вектора Коллениарны" << std::endl;
			bool a = true;
		}
		if (!a)
			std::cout << "Вектора не Коллениарны" << std::endl;
			
	};

}
void   Vector::ort_or_not(Vector obj)
{
	if ((x*obj.x + y*obj.y) == 0)
		std::cout << "Ортогональны" << std::endl;
	else
		std::cout << "Не ортогональны" << std::endl;
}
void   Vector::getVector()
{
	std::cout << "Координаты вектора : x = " << x << " y = " << y << std::endl;
	this->module();
}
int    Vector::summ()
{
	int summa = this->x + this->y;
	return summa;
}
