#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"Worker.h"

using namespace std;

class OrderList
{
public:

	void AddOrder(string name,string TypeOfWork, int price, int days, Worker* team, const int size, const int groupSize, const int groupNumber);
	void ShowOrders();
	void WriteToFile();
	~OrderList();
private:
	static int ListSize;
	static int AmountOfOrders;
	string *TypeOfWork;
	string *name;
	int *price;
	int *days;
	Worker** teamList;
};

