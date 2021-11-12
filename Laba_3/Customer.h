#pragma once
#include<iostream>
#include<string>
#include"Person.h"
#include"Status.h"

using namespace std;

template<typename T1, typename T2, typename T3>
class Customer: public Person, private Status
{
public:
	Customer();
	Customer(T1 name, T1 TypeOfWork, T3 price, T2 days);
	void SetRequest(T1 name, T1 TypeOfWork, T3 price, T2 days);
	T1&GetRequest();
	T1 GetCustomerName();
	T2&GetPrice();
	T2&GetDays();
	void SetPrice(T2 price);
	virtual ~Customer();
	Customer(const Customer& other);
	void HaveAbaby();
	virtual void Discount() = 0;

private:
	T1 TypeOfWork;
	T3 price;
	T2 days;
};
template class Customer<string, int, int>;

