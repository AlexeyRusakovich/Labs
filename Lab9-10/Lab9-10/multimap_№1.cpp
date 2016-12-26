#include <iostream>
#include <map>

using namespace std;


int main()
{
	setlocale(LC_ALL, "");
	multimap<int, float> map;

////////// 1 //////////	
	cout << "\t\t///////////// 1 /////////////" << endl;
	map.insert(pair<int, float>(1, 3.14f));	// ���������� ��� � multimap
	map.insert(pair<int, float>(2, 4.14f));
	map.insert(pair<int, float>(3, 5.14f));
	map.insert(pair<int, float>(4, 6.14f));
	cout << "����� ���������� map:" << endl;
	for (auto it_map : map)					// ����� multimap
	{
		cout << '{' << it_map.first << ", " << it_map.second << '}' << ' ';
	}
	cout << endl << endl;

////////// 2 //////////	
	cout << "\t\t///////////// 2 /////////////" << endl;
	map.erase(1);							// �������� ��������� �� ����� (������������ �������� ����� ���������) 
	map.erase(2);
	

	map.insert(pair<int, float>(1, 7.14f));	// ���������� ��� � multimap
	map.insert(pair<int, float>(2, 8.14f));

	cout << "����� ����������� ���������� map:" << endl;
	for (auto it_map : map)					// ����� multimap
	{
		cout << '{' << it_map.first << ", " << it_map.second << '}' << ' ';
	}
	cout << endl << endl;

////////// 3 //////////

	cout << "\t\t///////////// 3 /////////////" << endl;
	cout << "�������� ���������� � ������� ������������ ���������:" << endl;
	for (auto it_map = map.rbegin(); it_map != map.rend(); it_map++)
	{
		cout << '{' << it_map->first << ", " << it_map->second << '}' << ' ';
	}
	cout << endl << endl;

	cout << "�������� ���������� � ������� ������������ ���������:" << endl;
	for (auto it_map = map.cbegin(); it_map != map.end(); it_map++)
	{
		cout << '{' << it_map->first << ", " << it_map->second << '}' << ' ';
	}
	cout << endl << endl;

////////// 4 //////////

	cout << "\t\t///////////// 4 /////////////" << endl;
	multimap<int, float> map2;			// C������� ������� ���������� map2

	map2.insert(pair<int, float>(5, 9.14f));
	map2.insert(pair<int, float>(6, 10.14f));
	map2.insert(pair<int, float>(7, 11.14f));
	map2.insert(pair<int, float>(8, 12.14f));

	cout << "����� ���������� map2:" << endl;
	for (auto it_map : map2)
	{
		cout << '{' << it_map.first << ", " << it_map.second << '}' << ' ';
	}
	cout << endl<< endl;


////////// 5 //////////
	
	cout << "\t\t///////////// 5 /////////////" << endl;
	cout << "�������� 2-� ��������� �� ���������� map2 ������� � 1-��:" << endl << endl;
	
	
	auto it_map = map2.begin();
	for (int i = 0 ; i < 2; i++)
	{
		it_map = map2.erase(it_map);
	}

	

	cout << "����� ������� ���������� map:" << endl;
	for (auto it_map : map)
	{
		cout << '{' << it_map.first << ", " << it_map.second << '}' << ' ';
	}
	cout << endl<< endl;
	cout << "����� ������� ���������� map2:" << endl;
	for (auto it_map : map2)
	{
		cout << '{' << it_map.first << ", " << it_map.second << '}' << ' ';
	}

	return 0;
}