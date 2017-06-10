#include <iostream>
#include "ShablonList.h"
#include "Product.h"
#include <Windows.h>
//#include "Iterator.h"
#include <string.h>
#include"Algorithm.h"
using namespace std;


enum FindFields
{
	NAME, COST, WEIGHT, NUMBER
};

template <class T>
class menu
{
	bool isExit;
	int a;
	ShablonList<Product> list;
	Product pr;
public:
	menu()
	{
		isExit = true;
		a = 0;
	}
	void MainMenu()
	{
		while (isExit)
		{
			cout << "1 - �������� �������" << endl;
			cout << "2 - ������� �������" << endl;
			cout << "3 - ����������� ������" << endl;
			cout << "4 - ����� ������� � ������" << endl;
			cout << "5 - �������� �������� � ������ �������" << endl;
			cout << "6 - ������������� ������" << endl;
			cout << "7 - �����" << endl;
				cin >> a;
				switch (a)
				{
					case 1:
					{
						cin >> pr;
						list.addElementHead(pr);
						break;
					}

					case 2:
					{
						int a = 0;
						cout << "������� ����� ���������� ��������: " << "[1;" << list.getElementsCount() << "]" << endl;
							cin >> a;
							while (a < 1 || a > list.getElementsCount())
								cin >> a;
						list.deleteElement(a);
						break;
					}

					case 3:
					{
						Iterator<Product> it;
						for (it = list.begin(); it.eos(); it++)
							cout << it;

						cout << "��������: " << endl;
						cout << "-------------------------";
						for (it = list.rBegin(); it.eos(); it--)
							cout << it;
						//list.printAllElements();
						break;
					}

					case 4:
					{
						Product pr;
						Iterator<Product> it;
						it = list.begin();
						pr.HowFind();
						Algorithm<Product>::find(it, pr);
						break;
					}

					case 5:
					{
						Iterator<Product> it;
						system("cls");
						int x, y, i = 0;
						for (it = list.begin(); it.eos(); it++)
						{
							cout << "������� �����: " << i + 1 << endl;
							cout << it;
							i++;
							cout << endl;
						}

						cout << "������� ������ ���������, ������� ������ ��������: " << endl;
						cin >> x >> y;
						Iterator<Product> it1;
						Iterator<Product> it2;
						it1 = list.begin();
						it2 = list.begin();
						Algorithm<Product>::swap(&it1[x], &it2[y]);
						for (it = list.begin(); it.eos(); it++)
							cout << it;

						cout << "-----------------------";
						it = list.begin();
						cout << *it << endl;;
						break;

					}

					case 6:
					{
						Iterator<Product> it1;
						it1 = list.begin();
						Algorithm<Product>::sort(it1);
						break;
					}

					case 7:
					{
						isExit = false;
						break;
					}

					default:
					{
						cout << "�������� ����!" << endl;
						cin >> a;
					}
     	     }
		}
	}
};