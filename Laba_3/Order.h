#pragma once
#include<iostream>
#include<string>
#include"Dispatcher.h"
#include"Customer.h"
#include"OrderList.h"
#include<time.h>

using namespace std;

class Order
{
public:
	//Order(Dispatcher& dispatcher, Customer * customer, OrderList& orderList);
	Order();
	void ShowOrder();
	void AddOrder(Dispatcher& dispatcher, Customer<string,int,int>* customer, OrderList& orderList);
	void addToList();


private:
	Dispatcher* dispatcher;
	Customer<string, int, int>*customer;
	OrderList* orderList;
};

