#include "stdafx.h"

/////////////////////////  Orange      ////////////////////////////////////////
	 Orange::Orange()
{
	this->cost = -1;
	this->amount = -1;
	this->shelfLife = -1;
	this->DoYouLikeIt = iDontLikeIt;
}
	 Orange::Orange(int ccost, int aamount, int sshelfLife, bool DoYou)
{
	cost = ccost;
	amount = aamount;
	shelfLife = sshelfLife;
	DoYouLikeIt = DoYou;
}
void Orange::toConsole()
{
	cout << typeid(this).name() << endl;
	this->information();
}
void Orange::information()
{
	cout << "Наименование товара: " << this->name << endl;
	cout << "Количество товара на складе : " << this->amount << endl;
	cout << "Цена товара в BYN : " << this->cost << endl;
	cout << "Срок годности товара ( в часах ) : " << this->shelfLife << endl;
	cout << "Вам нравится этот товар? ";
		switch (this->DoYouLikeIt)
		{
			case iLikeIt:	  cout << " Of course!" << endl; break;

			case iDontLikeIt: cout << "NO!" << endl; break;
		};
	cout << endl;
};

////////////////////////   Grapefruit  ////////////////////////////////////////
void Grapefruit::toConsole()
{
	cout << typeid(this).name() << endl;
	this->information();
}
void Grapefruit::information()
{
	cout << "Оценка покупателей : " << this->DeliciousMark << endl;
	Pomelo::information();
	
}

///////////////////////	   Pomelo	   ////////////////////////////////////////
void Pomelo::AMOUNTOFCLASSES() {
	std::cout << "Количество объектов данного класса + объектов производного класса : "
		<< this->amountOfClasses << std::endl << std::endl;
};
void Pomelo::setAmount(int aamount)
{
	this->amount = aamount;
};
void Pomelo::setCost(int ccost)
{
	this->cost = ccost;
};
void Pomelo::setShelfLife(int sshelfLife)
{
	this->shelfLife = sshelfLife;
}
	 Pomelo::Pomelo(int ccost, int aamount, int sshelfLife, bool DoYou)
{
	amountOfClasses++;
	cost = ccost;
	amount = aamount;
	shelfLife = sshelfLife;
	DoYouLikeIt = DoYou;

}
void Pomelo::toConsole()
{
	cout << "Тип объекта: " << typeid(this).name() << endl;
	Pomelo::information();
}
void Pomelo::information()
{
	cout << "Наименование товара: " << this->name << endl;
	cout << "Количество товара на складе : " << this->amount << endl;
	cout << "Цена товара в BYN : " << this->cost << endl;
	cout << "Срок годности товара ( в часах ) : " << this->shelfLife << endl;
	cout << "Вам нравится этот товар? ";
		switch (this->DoYouLikeIt)
		{
			case iLikeIt:	  cout << " Of course!" << endl; break;

			case iDontLikeIt: cout << "NO!"         << endl; break;
		}
	cout << endl;

}