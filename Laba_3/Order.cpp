#include "Order.h"

//Order::Order(Dispatcher& dispatcher, Customer* customer, OrderList& orderList)
//{
//	customer->Discount();
//	this->dispatcher = &dispatcher;
//	this->customer = customer;
//	this->orderList = &orderList;
//}

Order::Order()
{
}

void Order::ShowOrder()
{
	cout <<"Customer: "<< customer->GetCustomerName() << endl;
	cout << "Days: "<<customer->GetDays() << endl;
	cout << "Price: "<<customer->GetPrice() << endl;
	cout <<"Request: "<< customer->GetRequest() << endl;
}

void Order::AddOrder(Dispatcher& dispatcher, Customer<string, int, int>* customer, OrderList& orderList)
{
	customer->Discount();
	this->dispatcher = &dispatcher;
	this->customer = customer;
	this->orderList = &orderList;
}

void Order::addToList()
{
	bool ifTrue = true;
	int group = 0;
	while (this->dispatcher->GetTeam()->GetTeam(group)[0].ShowWorkBool() == true)
	{
		if (group == this->dispatcher->GetTeam()->GetGroupAmount() - 2)
		{
			cout << "All the group are busy!" << endl;
			return;
		}
		group++;
	}
	if (group == this->dispatcher->GetTeam()->GetGroupAmount()-2 && this->dispatcher->GetTeam()->GetGroupSize() != 0)
	{
		for (int i = 0; i < this->dispatcher->GetTeam()->GetGroupSize(); i++)
		{
			this->dispatcher->GetTeam()->GetTeam(group)[i].SetWorkBool(ifTrue);
		}
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			this->dispatcher->GetTeam()->GetTeam(group)[i].SetWorkBool(ifTrue);
		}
	}
	this->orderList->AddOrder(customer->GetCustomerName(), customer->GetRequest(), customer->GetPrice(), customer->GetDays(), this->dispatcher->GetTeam()->GetTeam(group), this->dispatcher->GetTeam()->GetGroupSize(), this->dispatcher->GetTeam()->GetGroupAmount() - 2, group);
}





