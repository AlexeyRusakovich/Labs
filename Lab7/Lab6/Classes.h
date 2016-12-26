#pragma once

template <class T1>
class List
{
	private:
		List* head;
		List* next;
		T1 x;
		int size;
	public:
		List() : head(nullptr), next(nullptr), x(0), size(0) {};
		List(T1 id) : head(nullptr), next(nullptr), x(id), size(0) {};
		void add(T1 id);
		void pop(T1 id);
		void PrintList(char*);
		T1  getValue();
		List* getHead();
		List* getNext();
		int getSize();
		bool empty();
		List &operator =(List& list);
		void operator --();
		bool operator ==(List list);
		List &operator +(List& list);
};
// Глобальная шаблонная функция
template <class ListType, class T1> void getmin(ListType& list)
{
	ListType* temp = list.getHead();
	T1 min = temp->getValue();
	for (int i = 0; i < list.getSize(); i++)
	{
		if (min > temp->getValue())
			min = temp->getValue();
		
			temp = temp->getNext();
	}
	cout << "Минимальное значения списка : " << min << endl;
};


template<class T1> void List<T1>::add(T1 id)
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
template<class T1> void List<T1>::pop(T1 id)
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
				if (temp->next->getValue() == id)
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
template<class T1> T1   List<T1>::getValue()
{
	return this->x;
}
template<class T1> List<T1>* List<T1>::getHead()
{
	return this->head;
}
template<class T1> int	List<T1>::getSize()
{
	return this->size;
}
template<class T1> List<T1>* List<T1>::getNext()
{
	return this->next;
}
template<class T1> List<T1>& List<T1>::operator =(List& list)
{
	this->head = list.head;
	this->next = list.next;
	this->size = list.size;
	this->x = list.x;
	return *this;
}
template<class T1> void List<T1>::operator --()
{
	List* temp = head;
	if (head)
	{
		size--;
		head = head->next;
		delete temp;
	}
}
template<class T1> bool List<T1>::operator ==(List list)
{
	if (this->head == list.head &&
		this->next == list.next &&
		this->size == list.size &&
		this->x == list.x)
		return true;
	else
		return false;
}
template<class T1> bool List<T1>::empty()
{
	return (head) ? false : true;
}
template<class T1> List<T1>& List<T1>::operator +(List& list)
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
template<class T1> void List<T1>::PrintList(char* name)
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


