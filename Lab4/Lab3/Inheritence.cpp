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
	cout << "������������ ������: " << this->name << endl;
	cout << "���������� ������ �� ������ : " << this->amount << endl;
	cout << "���� ������ � BYN : " << this->cost << endl;
	cout << "���� �������� ������ ( � ����� ) : " << this->shelfLife << endl;
	cout << "��� �������� ���� �����? ";
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
	cout << "������ ����������� : " << this->DeliciousMark << endl;
	Pomelo::information();
	
}

///////////////////////	   Pomelo	   ////////////////////////////////////////
void Pomelo::AMOUNTOFCLASSES() {
	std::cout << "���������� �������� ������� ������ + �������� ������������ ������ : "
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
	cout << "��� �������: " << typeid(this).name() << endl;
	Pomelo::information();
}
void Pomelo::information()
{
	cout << "������������ ������: " << this->name << endl;
	cout << "���������� ������ �� ������ : " << this->amount << endl;
	cout << "���� ������ � BYN : " << this->cost << endl;
	cout << "���� �������� ������ ( � ����� ) : " << this->shelfLife << endl;
	cout << "��� �������� ���� �����? ";
		switch (this->DoYouLikeIt)
		{
			case iLikeIt:	  cout << " Of course!" << endl; break;

			case iDontLikeIt: cout << "NO!"         << endl; break;
		}
	cout << endl;

}