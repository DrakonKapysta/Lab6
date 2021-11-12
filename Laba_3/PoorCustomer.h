#pragma once
#include<iostream>
#include<string>
#include"Customer.h"

template<typename T1, typename T2, typename T3>
class PoorCustomer :public virtual Customer<T1, T2,T3>
{
public:
	~PoorCustomer();
	PoorCustomer();
	PoorCustomer(T1 name, T1 TypeOfWork, T3 price, T2 days);
	void Discount() override;
private:
};
template class PoorCustomer<string, int, int>;
