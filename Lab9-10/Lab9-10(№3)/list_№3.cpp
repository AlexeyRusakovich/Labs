#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <vector>
#include "D:\���������������� �++\��� (II ���� II �������)\������������\Lab3\Lab3\Inheritence.h"
#include "D:\���������������� �++\��� (II ���� II �������)\������������\Lab3\Lab3\Inheritence.cpp"
using namespace std; 

bool MyDataSortPredicate(food_product& lhs,food_product& rhs)
{
		return lhs.getLife() > rhs.getLife();

}
bool MyDataSortPredicate2(food_product& lhs, food_product& rhs)
{
	return lhs.getLife() < rhs.getLife();

}
food_product Lemon("Lemon", 1, 20, 72);
int main()
{
	//////////// 1 ///////////
		cout << "\t\t////////// 1 ///////////" << endl << endl;
		setlocale(LC_ALL, "");
		list<food_product> myList;
		food_product Lemon("Lemon", 1, 20, 72);
		food_product Apple("Apple", 2, 40, 144);
		food_product Orange("Orange", 3, 40, 36);
	
		myList.push_back(Lemon);		// ���������� ��������� � myList						
		myList.push_back(Apple);
		myList.push_back(Orange);
	
		cout << "����� ������ myList:" << endl;
		for (auto it_list : myList)		// ����� myList
		{
			it_list.information();
		}
		cout << endl;
	
		myList.sort(MyDataSortPredicate);	// ���������� myList �� ����� ��������
	
		cout << "��������������� �� ����� �������� myList:" << endl;
		for (auto it_list : myList)		// ����� myList
		{
			it_list.information();
		}
		cout << endl;
	
	////////// 2 ///////////
		cout << "\t\t////////// 2 ///////////" << endl << endl;
		auto it_rbegin = myList.rend();		// �������� ������ ������
		auto it_rend	 =	myList.rbegin();	// �������� ����� ������
		auto it		  = myList.rbegin();
		bool ifTrue = false;
		int shelfTime;
		cout << "������� ���� �������� ��������, ������� ������ �����: ";
		cin >> shelfTime;
		for (auto it_list = it_rend; it_list != it_rbegin; it_list++)
		{
			if (it_list->getLife() == shelfTime)
			{
				it = it_list;
				ifTrue = true;
			}
		}
		if (ifTrue)
		{
			cout << "������� � ������ �������� " << shelfTime << " :" << endl;
			it->information();
		}
		else
			cout << "������� � ������ ������ �������� �� ������!" << endl;
	
	////////// 3 ///////////
		cout << "\t\t////////// 3 ///////////" << endl << endl;
	
		list<food_product> expired_products;	// ������ ������������ ���������
		auto it_begin = myList.begin();
		auto it_end = myList.end(); 
		auto temp_it = myList.end();
		cout << "������� ������ ����� �������� ��������� : ";
		cin >> shelfTime;
		for (auto it_list = it_begin; it_list != it_end;)
		{
			int Time_life = 0;
			if (Time_life = it_list->getLife() > shelfTime)
			{
				expired_products.push_back(*it_list);
				it_list = myList.erase(it_list);
			}
			else
				it_list++;
	
		}
		cout << "����� ������ ��������� c �������� ������ �������� : " << endl;

		for (auto it_list : expired_products)
		{
			it_list.information();
		}
		
		cout << endl << "����� ������ ������ ��������� : " << endl;
		for (auto it_list : myList)
		{
			it_list.information();
		}
		cout << endl;		
	
	////////// 4 ///////////
		cout << "\t\t////////// 4 ///////////" << endl << endl;
	
		food_product Strawberry("Strawberry", 3, 15, 36);
		food_product Pomelo("Pomelo", 4, 40, 72);
		food_product Banana("Banana", 1, 100, 180);
	
	
		myList.push_back(Banana);
		myList.push_back(Pomelo);
		myList.push_back(Strawberry);
	
		myList.sort(MyDataSortPredicate2);				// ���������� 2-� �������
		expired_products.sort(MyDataSortPredicate2);
	
		cout << "����� ������ ��������� c �������� ������ ��������  : " << endl;

		for (auto it_list : expired_products)
		{
			it_list.information();
		}
		cout << endl << "����� ������ ������ ��������� + ���������� �������� : " << endl;
		for (auto it_list : myList)
		{
			it_list.information();
		}
		cout << endl;
		
	
	
	////////// 5 ///////////
		cout << "\t\t////////// 5 ///////////" << endl << endl;
	
		list<food_product> all_products;	// ������ ���� ���������
		
		for (auto it_list : myList)
			all_products.push_back(it_list);
		for (auto it_list : expired_products)
			all_products.push_back(it_list);
	
		cout << "����� ������������ ������� myList �  expired_products � all_products :" << endl;
		for (auto it_list : all_products)
		{
			it_list.information();
		}
		cout << endl;
	////////// 6 ///////////
		cout << "\t\t////////// 6 ///////////" << endl << endl;
		cout << "������� ���� �������� �������� : ";
		cin >> shelfTime;
		int count_ = 0;
		for (auto it_list : all_products)
		{
			if (it_list.getLife() <= shelfTime)
				count_++;
		}
		cout << "���������� ������ ��������� : " << count_ << endl; count_ = 0;
		cout << "������� ���������� ������ ��������� � ������� ������ �������" << endl;
		for_each(all_products.begin(), all_products.end(), [&](food_product a) mutable {
			if(a.getLife() <= shelfTime)
				count_++;
		});
			cout << "���������� ������ ��������� : " << count_ << endl;
		cout << "������� ���� �������� �������� : ";
		cin >> shelfTime;
		ifTrue = false;
		for (auto it_list : all_products)
		{
			if (it_list.getLife() == shelfTime)
				ifTrue = false;
		}
		if (ifTrue)
		{
			cout << endl << "������� � ������ ������ �������� ���� � ����� ��������!" << endl << endl;
		}
		else
			cout << endl <<  "������� � ������ ������ �������� �� ������!" << endl << endl;

	////////// 7 ///////////
		cout << "\t\t////////// 7 ///////////" << endl << endl;
		string a("Hello World!!!!");	// 
		string b(a);
		string c(10, 'f');
		string d(a, 0, 8);
		string e(a, 8, 12);
		string f{'a', 'b', 'c'};
		
		// ����� ���� �����
		cout << "a = \" " << a << " \"" << endl 
			 << "b = \" " << b << " \"" << endl
			 << "c = \" " << c << " \"" << endl
			 << "d = \" " << d << " \"" << endl
			 << "e = \" " << e << " \"" << endl
			 << "f = \" " << f << " \"" << endl;

		// ������������ ������� ����� string 
		cout << "a.size() = \t" <<  a.size() << endl;										
		cout << "a.find('l') = \t" << a.find('l') << endl;									
		cout << "a.find(\"World\") = \t" << a.find("World") << endl;						
		cout << "a.append(it_first,it_last) =  " << a.append(c.begin(),c.end()) << endl;	
		cout << "b.append(it_first, it_first + count) = \t" << b.append(c.begin(), c.begin() + 5) << endl;
		cout << "c.append(const char*) = \t" << c.append("Yeeeee!")<< endl;				
		cout << "d.assign(it_first, it_last) \t" << d.assign(e.begin(), e.end()) << endl << endl;

	////////// 8 ///////////
		cout << "\t\t////////// 8 ///////////" << endl << endl;
		class fc
		{
			int _cnt;
		public:
			fc(int __cnt) { _cnt = __cnt; };
			bool operator()(int __cnt) { return (__cnt > _cnt); };
		};
		vector<int> vec{ 1, 3, 5, 177, 30, 522, 2, 150 };
		
		cout << "���������� ��������� � ������� ������ ����� 40 : ";
		cout << count_if(vec.begin(), vec.end(), fc(40)) << endl << endl;


	return 0;
};