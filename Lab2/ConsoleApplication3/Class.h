#pragma once
#include "stdafx.h"

class Vector
{
	private:
		int x;
		int y;
	public:
		Vector() : x(0), y(0) 
		{
			std::cout << "Конструктор по умолчанию" << std::endl;
		}
		Vector(int x1, int y1);
		Vector(Vector &obj);
		void setVector(int x, int y);
		void getVector();
		void module();
		void scal_mul(class Vector obj);
		void add(class Vector obj);
		void sub(class Vector obj);
		void mul_const(int constanta);
		void coll_or_not(Vector obj);
		void ort_or_not(Vector obj);		
		int  summ();
		~Vector()
		{
			std::cout << "Destruct work!" << std::endl;
		}
};
