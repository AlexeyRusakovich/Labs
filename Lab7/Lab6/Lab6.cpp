#include "stdafx.h"
using namespace std;


int main()
{
	setlocale(LC_ALL, "");

	List<int> list1(1);	// �������� ������ list1
	List<int> list2(2);	//				�  list2
	
	// ������������ ������ ��������� �������
	cout << "���������� ��������� 1, 2, 3, 4 � ������ list1" << endl;
	list1.add(2.3);
	list1.add(3.5);
	list1.add(4.7);
	list1.PrintList("list1");
	cout << endl << endl;

	cout << "���������� ��������� 5, 6, 7, 8 � ������ list2" << endl;
	list2.add(5.2);
	list2.add(6);
	list2.add(7.1);
	list2.add(8);
	list2.PrintList("list2");
	cout << endl << endl;

	cout << "��������� �������� ������ list1 � list2" << endl;
	list1 + list2;
	list1.PrintList("list1");
	cout << endl << endl;

	cout << "�������� 1-�� �������� �� �����1 � �����2" << endl;
	--list1;
	list1.PrintList("list1");
	cout << endl << endl;
	--list2;
	list2.PrintList("list2");
	cout << endl << endl;

	cout << "������������ �����1 ����2" << endl;
	list1 = list2;
	list1.PrintList("list1");
	cout << endl << endl;

	// ���������� ��������� ������� ����������� ����������� �������� ������
	getmin<List<int>,int>(list1);
    return 0;
}

