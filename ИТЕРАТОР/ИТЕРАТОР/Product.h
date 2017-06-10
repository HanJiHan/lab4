#pragma once;

#include<iostream>
#include<string>
#pragma warning (disable : 4996)
using namespace std;

class Product
{
protected:
	string name;
	float cost;
	float weight;
	int theNumber;
	int fullFields;

public:
	Product(){
		cost = 0;
		weight = 0;
		theNumber = 0;
		fullFields = 0;
	}

	friend ostream& operator << (ostream& os, Product& pr)
	{
		os << "������������ ������: " << pr.getName() << endl <<
			"���� ������: " << pr.getPrice() << endl <<
			"��� ������: " << pr.getWeight() << endl <<
			"���������� ������: " << pr.getTheNumber() << endl;
		return os;
	}

	friend istream& operator >> (istream& is, Product& temp)
	{
		cout << "������� ������������ ������: " << endl;
		is >> temp.name;
		cout << "������� ���� ������: " << endl;
		is >> temp.cost;
		cout << "������� ��� ������: " << endl;
		is >> temp.weight;
		cout << "������� ���������� ������: " << endl;
		is >> temp.theNumber;
		return is;
	}

	bool operator> (Product pr)
	{
		if (this->name > pr.name)
			return true;
		else
			return false;
	}

	void setName(string name)
	{
		this->name = name;
	}

	string getName()
	{
		return name;
	}

	void setPrice(float cost)
	{
		this->cost = cost;
	}

	float getPrice()
	{
		return cost;
	}

	void setWeight(float weight)
	{
		this->weight = weight;
	}

	float getWeight()
	{
		return weight;
	}

	void setTheNumber(int theNumber)
	{
		this->theNumber = theNumber;
	}

	void changeTheNumber(int theNumber)
	{
		this->theNumber = this->theNumber - theNumber;
	}

	int getTheNumber()
	{
		return theNumber;
	}

	int getFullFields()
	{
		return fullFields;
	}

	bool operator==(Product &pr)
	{
		int kol = 0;

		if (!pr.getName().empty())
			if (name == pr.getName())
				kol++;
		if (pr.getPrice() != 0)
			if (cost == pr.getPrice())
				kol++;
		if (pr.getWeight() != 0)
			if (weight == pr.getWeight())
				kol++;
		if (pr.getTheNumber() != 0)
			if (theNumber == pr.getTheNumber())
				kol++;

		if (pr.getFullFields() == kol)
			return true;
		else
			return false;
		
	}

	void HowFind()
	{
		int x;
		cout << "������� �������� ������" << endl;
		cout << "������ ������������?(1/0)" << endl;
		cin >> x;
		if (x == 1)
		{
			cout << "������������: " << endl;
			cin >> name;
			setName(name);
			fullFields++;
		}
		system("cls");

		cout << "������ ����?(1/0)" << endl;
		cin >> x;
		if (x == 1)
		{
			cout << "����: " << endl;
			cin >> cost;
			setPrice(cost);
			fullFields++;
		}

		system("cls");
		cout << "������ ���?(1/0)" << endl;
		cin >> x;
		if (x == 1)
		{
			cout << "���: " << endl;
			cin >> weight;
			setWeight(weight);
			fullFields++;
		}

		system("cls");
		cout << "������ ����������?(1/0)" << endl;
		cin >> x;
		if (x == 1)
		{
			cout << "����������: " << endl;
			cin >> theNumber;
			setTheNumber(theNumber);
			fullFields++;
		}
	}

	~Product()
	{
	}

};