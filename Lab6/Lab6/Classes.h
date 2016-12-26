#pragma once

class List
{
	private:
		List* head;
		List* next;
		int x;
		int size;
	public:
		List() : head(nullptr), next(nullptr), x(0), size(0) {};
		List(int id) : head(nullptr), next(nullptr), x(id), size(0) {};
		void add(int id);
		void pop(int id);
		void PrintList(char*);
		int  getValue();
		bool empty();
		List &operator =(List& list);
		void operator --();
		bool operator ==(List list);
		List &operator +(List& list);
};

