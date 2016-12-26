#pragma once

class Subject
{
private:
	char* name;			// ������������ �������� � �������	
	int mass;			// ����� �������
	int cost;			// ���� �������
	int height;			// ������ �������
	int width;			// ������ �������
	int length;			// ����� �������
public:
	Subject* next;
	Subject* prev;
	Subject() : name(nullptr), mass(0), cost(0), height(0), width(0), length(0) {};
	Subject(char*, int, int, int, int, int);
	void setMass(int);
	void setCost(int);
	void setSize(int, int, int);
	void getInfo() const;
	char* getName() const;
	int getMass()const;
	int getCost()const;
	int getSize()const;
};
class Gift
{
	private:
		int size;
		Subject* head;
		Subject* tail;
	public:
		Gift() : size(0) , head(nullptr), tail(nullptr) {};
		void add(Subject*);
		void extract(char*);
		Subject* getFirst() const;
		Subject* getLast() const;
		Subject* getNext(Subject* subject);
		Subject* getPrev(Subject* subject);
		void sort();
		void swapSubjects(Subject*, Subject*);
		void getSize();
		void getLeastMass();
		void PrintList();
};
