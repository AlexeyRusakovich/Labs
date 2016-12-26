#include "stdafx.h"

int main()
{
	setlocale(LC_ALL, "");
	// ��� ����� ����������
	Gift MyGift;	

	// ������������, �����, ����, ������, ������, �����
	Subject roses("����", 1000, 10, 5,  5,  50); 
	Subject cake( "����", 2000, 15, 20, 30, 30);
	Subject wine( "����", 750,  20, 35, 7,  7);

	// ��������� ���� �������� � �������
	MyGift.add(&roses);
	MyGift.add(&cake);
	MyGift.add(&wine);

	// ����� ��������� � �������
	MyGift.PrintList();

	// ���������� �������� � ���������� ������
	MyGift.getLeastMass();

	// �������� �������� � ������������� "����"
	MyGift.extract("����");

	// ����� ��������� � �������
	MyGift.PrintList();

	// ���������� ��������� 
	MyGift.sort();
	MyGift.PrintList();
	
    return 0;
}

