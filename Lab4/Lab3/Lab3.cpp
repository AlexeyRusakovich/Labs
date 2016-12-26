#include "stdafx.h"

int Pomelo::amountOfClasses;

int main()
{
	setlocale(LC_ALL, "");

	Grapefruit*	grapefruit	= new Grapefruit(10, 5, 48, iDontLikeIt, 8	);
	Orange*		orange		= new Orange	(30, 2, 72, iLikeIt			);
	Pomelo*		pomelo		= new Pomelo	(25, 3, 48, iDontLikeIt		);


	Printer		print;
	Inspector	inspector;
	Curator		curator;

	print.iAmPrinting(grapefruit);				// Печать информации об объектах
	print.iAmPrinting(orange);
	print.iAmPrinting(pomelo);

	orange->product_.inside_method(orange);		// Проверка

	inspector.iKnowAllAboutYou(grapefruit);

	curator.iCanModify(grapefruit);

	print.iAmPrinting(grapefruit);

	pomelo->AMOUNTOFCLASSES();


	volatile const int a = 5;					// const_cast
	int *b;							
	b = const_cast<int *>(&a);		
	*b = 4;
	std::cout << "a : " << a << endl<<  "b : " << *b << std::endl;
	return 0;
	
}

