#include "PoorCustomer.h"

template<typename T1, typename T2, typename T3>
PoorCustomer<T1, T2, T3>::~PoorCustomer()
{
}

template<typename T1, typename T2, typename T3>
PoorCustomer<T1, T2, T3>::PoorCustomer()
{
}
template<typename T1, typename T2, typename T3>
PoorCustomer<T1, T2, T3>::PoorCustomer(T1 name, T1 TypeOfWork, T3 price, T2 days):Customer<T1, T2,T3>(name, TypeOfWork, price, days)
{
}

template<typename T1, typename T2, typename T3>
void PoorCustomer<T1, T2, T3>::Discount()
{
	this->SetPrice(this->GetPrice() + ((this->GetPrice() * 5) / 100));
}

