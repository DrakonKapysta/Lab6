#pragma once
#include<iostream>
#include<string>
#include"Customer.h"


using namespace std;

template<typename T1, typename T2, typename T3>
class VipCustomer : public virtual Customer<T1, T2, T3>
{
public:
	~VipCustomer();
	VipCustomer();
	VipCustomer(T1 name, T1 TypeOfWork, T3 price, T2 days);
	void Discount() override;
private:

};
template class VipCustomer<string, int, int>;

