#pragma once

class MyException
{	
	int x;
	char message[255];
	public:
		MyException(int xx, char* mmessage)
		{
			x = xx;
			strcpy_s(message, mmessage);
		}
		const char* what() const
		{
			return "Oops!Exception!";
		}
		const char* getMessage()
		{
			return message;
		}
		int getX()
		{
			return x;
		}
};

template <class T1>
class List				// Допустим что наш список должен состоять тольо из чисел >= 0 (Для возможности генерации исключения)
{
	private:
		List* head;		// Указатель на начало списка
		List* next;		// Следующий элемент списка
		T1 x;			// значение списка
		int size;		// размер списка
	public:
		List() : head(nullptr), next(nullptr), x(0), size(0) {};
		List(T1 id);
		void add(T1 id);				// Добавление элемента в список
		void pop(T1 id);				// Извлечение последнего элемента
		void PrintList(char*);			// Вывод списка
		T1  getValue();					// Получить значение элемента списка
		List* getHead();				// Получить указатель на начало списка
		List* getNext();				// Получить следующий элемент списка
		int getSize();					// Функция, возвращающая размер списка
		bool empty();					// Проверка на пустоту списка
		List &operator =(List& list);
		void operator --();
		bool operator ==(List list);
		List &operator +(List& list);
};
// Глобальная шаблонная функция
template <class ListType, class T1> void getmin(ListType& list)
{
	if (list.getHead() == nullptr)
		throw MyException(0, "Getmin function error.Blank Index");
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

// Определение функций класса List
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
	if (head == nullptr)
		throw MyException(NULL, "Pop fuction error.Recovery is not possible. The list is empty!");
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
template<class T1> bool List<T1>::empty()
{
	return (head) ? false : true;
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
	if (head == nullptr)
		throw MyException(NULL,"Operator-- error.Blank index.");
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
	if (head == nullptr)
		throw MyException(NULL, "PrintList function error.The list is empty!");
		List* temp = head;
		cout << "Значения списка " << name << " : " << endl;
		while (temp)
		{
			cout << temp->x << endl;
			temp = temp->next;
		}
	
}
template<class T1> List<T1>::List(T1 id)
{
	if (id < 0)
		throw MyException(id, "List constuctor error.Value is less than zero");
	head = nullptr;
	next = nullptr;
	size = 0;
	x = id;
};


