#include "stdafx.h"
using namespace std;

void List::add(int id)
{
	if (head)
	{
		List* a = new List();
		List* temp = head;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = a;
		a->x = id;
		a->next = nullptr;
		size++;
	}
	else
	{
		List* a = new List();
		head = a;
		a->x = id;
		a->next = nullptr;
		size++;
	}
}
void List::pop(int id)
{
	if (head)
	{
		List* temp = head;
		if (size == 1 && temp->getValue() == id)
		{

			delete temp;
			head = nullptr;
			size--;
		}
		else if (temp->getValue() == id)
		{
			head = temp->next;
			delete temp;
			size--;
		}
		else
		{
			while (temp)
			{
				if(temp->next->getValue() == id)
				{
					temp->next = temp->next->next;
					delete temp;
					size--;
					break;
				}
				temp = temp->next;
			}
		}
	}
	else
		cout << "В списке нет элементов " << endl;
}
int List::getValue()
{
	return this->x;
}
List &List::operator =(List& list)
{
	this->head = list.head;
	this->next = list.next;
	this->size = list.size;
	this->x = list.x;
	return *this;
}
void List::operator --()
{
	List* temp = head;
	if (head)
	{
		head = head->next;
		delete temp;
	}
}
bool List::operator ==(List list)
{
	if (this->head == list.head &&
		this->next == list.next &&
		this->size == list.size &&
		this->x == list.x)
		return true;
	else
		return false;
}
bool List::empty()
{
	return (head) ? false : true;
}
List &List::operator +(List& list)
{
	if (this->head)
	{
		List* temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = list.head;
		return *this;
	}
	else
	{
		head = list.head;
		return *this;
	}
}
void List::PrintList(char* name)
{
	if (head)
	{
		List* temp = head;
		cout << "Значения списка " << name << " : " << endl;
		while (temp)
		{
			cout << temp->x << endl;
			temp = temp->next;
		}
	}
	else
		cout << "Список пуст!" << endl;
}
