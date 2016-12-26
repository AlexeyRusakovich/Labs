#include "stdafx.h"
using namespace std;
#pragma warning(disable: 4267)

/////////////////// Subject ///////////////////
Subject::Subject(char* nname, int mmass,int ccost ,int hheight ,int wwidth,int llength )
{
	name = nname;
	mass = mmass;
	cost = ccost;
	height = hheight;
	width = wwidth;
	length = llength;
}
void Subject::setMass(int mmass)
{
	mass = mmass;
}
void Subject::setCost(int ccost)
{
	cost = ccost;
}
void Subject::setSize(int hheight, int wwidth, int llength)
{
	height = hheight;
	width = wwidth;
	length = llength;
}
void Subject::getInfo() const
{	
	cout << endl;
	cout << "Наименование подарка: " << name << endl;
	cout << "Масса: " << mass << endl;
	cout << "Цена: " << cost << endl;
	cout << "Размер: " << height << "x" << width << "x" << length << endl;
}
char* Subject::getName() const
{
	return name;
}
int Subject::getMass() const 
{
	return mass;
}
int Subject::getCost() const
{
	return cost;
}
int Subject::getSize() const
{
	return (height*width*length);
}
///////////////////   Gift  ///////////////////
void Gift::add(Subject* subject)
{
	if (tail)
	{
		tail->next = subject;	
		subject->prev = tail;
		tail = subject;
		this->size++;
	}
	else
	{
		tail = head = subject;
		subject->next = nullptr;
		subject->prev = nullptr;
		this->size++;
	}
}
void Gift::extract(char* nname)
{
	if (head)
	{
		Subject* temp = head;
		while(temp)
		{
			if (!strcmp(temp->getName(), nname))
			{
				if (size == 1)
				{
					temp = head; head = nullptr;	tail = nullptr;
					this->size--;	break;
				}
				else if (temp->next && temp->prev)
				{
					temp->next->prev = temp->prev;
					temp->prev->next = temp->next;	
					head = (temp = head) ?  head->next : head;
					this->size--; 	break;
				}
				else if (temp->next)
				{
					temp->next->prev = nullptr;
					head = (temp = head) ? head->next : head;
					this->size--; 	break;
				}
				else
				{
					temp->prev->next = nullptr;
					tail = temp->prev;
					this->size--;
				}
			}
			temp = temp->next;
		}
	}
	else
	{
		cout << "В подарке нет предметов!!!" << endl;
	}
}
Subject* Gift::getFirst() const
{
	return (head) ? head : nullptr;
}
Subject* Gift::getLast() const
{
	return (tail) ? tail : nullptr;
}
Subject* Gift::getNext(Subject* subject)
{
	return (subject) ? subject->next : nullptr;
}
Subject* Gift::getPrev(Subject* subject)
{
	return (subject) ? subject->prev : nullptr;
}
void Gift::swapSubjects(Subject* subject1, Subject* subject2)
{	// List: ...obj ⇄ sub1 ⇄ sub2 ⇄ obj...
	if (subject1->prev && subject2->next)
	{
		subject1->prev->next = subject2;
		subject2->next->prev = subject1;
		subject2->prev = subject1->prev;
		subject1->next = subject2->next;
		subject2->next = subject1;
		subject1->prev = subject2;
	}

	// List: ...obj ⇄ sub1 ⇄ sub2
	else if (subject1->prev && !subject2->next)
	{
		subject1->next = nullptr;
		subject2->next = subject1;
		subject1->prev->next = subject2;
		subject2->prev = subject1->prev;
		subject1->prev = subject2;
	}

	// List: sub1 ⇄ sub2 ⇄obj...
	else if (!subject1->prev && subject2->next)
	{
		head = (head = subject1) ? subject2 : head;
		subject1->next = subject2->next;
		subject2->next->prev = subject1;
		subject2->next = subject1;
		subject2->prev = nullptr;
		subject1->prev = subject2;
	}

	// List: sub1 ⇄ sub2
	else
	{
		subject1->next = nullptr;
		subject2->prev = nullptr;
		subject1->prev = subject2;
		subject2->next = subject1;
		head = (head == subject1) ? subject2 : head;
		tail = (tail == subject2) ? subject1 : tail;
	}
}
void Gift::sort()
{
	cout << endl << "Сортировка по габаритам : " << endl;
	Subject* temp;
	for (int k = 0; k < size - 1; k++)
	{
		temp = this->head;
		for (int i = 0; i < size - 1; i++)
		{
			temp = temp->next;
			if (temp->prev->getSize() >= temp->getSize())
				swapSubjects(temp->prev, temp);			
		}
	}
}
void Gift::getSize()
{
	cout << "Количество вещей в подарке : " << size << endl;
}
void Gift::getLeastMass()
{
	if (head)
	{
		Subject* p = head;
		int min = 0;
		if (size == 1)
		{
			cout << "Минимальная масса подарка: " << p->getMass() << endl;
			return;
		}
		for(int i = 0 ; i < size - 1; i++)
		{
			min = (p->getMass() < p->next->getMass()) ? p->getMass() : p->next->getMass();
			p = getNext(p);
		}
		cout << "Минимальная масса подарка: " << min << endl;
	}
	else
		cout << "Тут пусто!" << endl;
	
}
void Gift::PrintList()
{
	Subject* temp = head;
	for (int i = 0; i < size; i++)
	{
		temp->getInfo();
		temp = getNext(temp);
	}
}
