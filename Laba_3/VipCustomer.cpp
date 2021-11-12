#include "VipCustomer.h"

template<typename T1, typename T2, typename T3>
VipCustomer<T1, T2, T3>::~VipCustomer()
{
}

template<typename T1, typename T2, typename T3>
VipCustomer<T1, T2, T3>::VipCustomer()
{
}

template<typename T1, typename T2, typename T3>
VipCustomer<T1, T2, T3>::VipCustomer(T1 name, T1 TypeOfWork, T3 price, T2 days) : Customer<T1, T2, T3>(name, TypeOfWork, price, days)
{

}

template<typename T1, typename T2, typename T3>
void VipCustomer<T1, T2, T3>::Discount()
{
	this->SetPrice(this->GetPrice() - ((this->GetPrice() * 20) / 100));

}
