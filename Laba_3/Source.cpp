#include<iostream>
#include<string>
#include"Worker.h"
#include"Team.h"
#include"Customer.h"
#include "Dispatcher.h"
#include "Order.h"
#include "OrderList.h"
#include"VipCustomer.h"
#include"PoorCustomer.h"
#include "Person.h"

using namespace std;

int main()
{
	// Раннє зв'язування 
	//============================
	/*Person* person = new Person;
	person->GetMessage();
	delete person;
	person = new Worker;
	person->GetMessage();
	delete person;*/
	//============================


	// Оператор присвоєння(=)
	//============================
	/*Person Tomas;
	Tomas.SetName("Tomas");
	Tomas.SetAge(24);
	Person TomasCopy;
	TomasCopy = Tomas;*/
	//============================


	// Оператори порівняння(==\!=\>\<\>=\<=) 
	//============================
	/*Person Tomas;
	Tomas.SetName("Tomas");
	Tomas.SetAge(25);
	Person Tolik;
	Tolik.SetAge(24);
	Tolik.SetName("Tolik");
	bool result = Tomas == Tolik;
	cout << "== "<<result << endl;
	result = Tomas != Tolik;
	cout << "!= " << result << endl;
	result = Tomas > Tolik;
	cout <<"> "<< result<<endl;
	result = Tomas < Tolik;
	cout << "< " << result << endl;
	result = Tomas <= Tolik;
	cout << "<= " << result << endl;
	result = Tomas >= Tolik;
	cout << ">= " << result << endl;*/
	//============================

	//Математичні оператори(+\-\*\%....) 
	//============================
	/*Person Tomas;
	Tomas.SetName("Tomas");
	Tomas.SetAge(25);
	Person Tolik;
	Tolik.SetAge(24);
	Tolik.SetName("Tolik");
	Person Niko;
	Niko = Tomas + Tolik;
	cout <<"+ "<< Niko.GetAge() << endl;
	Niko = Tomas - Tolik;
	cout << "- " << Niko.GetAge() << endl;
	Niko = Tomas * Tolik;
	cout << "* " << Niko.GetAge() << endl;
	Niko = Tomas % Tolik;
	cout << "% " << Niko.GetAge() << endl;
	Niko += Tomas;
	cout << "+= " << Niko.GetAge() << endl;
	Niko -= Tomas;
	cout << "-= " << Niko.GetAge() << endl;
	Niko *= Tomas;
	cout << "*= " << Niko.GetAge() << endl;
	Niko %= Tomas;
	cout << "%= " << Niko.GetAge() << endl;
	++Niko;
	cout << "++Niko " << Niko.GetAge() << endl;
	Niko = Tomas++;
	--Niko;
	cout << "++Niko " << Niko.GetAge() << endl;
	Niko = Tomas--;
	cout << "Niko = --Tomas " << Niko.GetAge() << " Tomas: " << Tomas.GetAge() << endl;*/
	//============================

	//Оператор індексування([]) 
	//============================
	/*Person Tomas;
	cout << Tomas[0] << endl;*/
	//============================

	setlocale(LC_ALL, "Ukr");
	string TypeOfWork, name;
	int price, days;
	VipCustomer<string, int, int> vipCustomer;
	PoorCustomer<string, int, int> poorCustomer;
	Order order;
	OrderList orderList;
	Dispatcher dispatcher("Tom", 31);
	const int size = 9;
	Worker worker[size]
	{
		Worker("Tom", 23),
		Worker("Andrey",21),
		Worker("Alexander", 41),
		Worker("Jarramy", 44),
		Worker("Tim", 32),
		Worker("Notail", 19),
		Worker("Saksa", 43),
		Worker("Topson", 34),
		Worker("Miracle", 18),
	};
	Team team;
	for (int i = 0; i < size; i++)
	{
		team.SetTeamMember(worker[i]);
	}
	dispatcher.SetTeam(team);
	for (int i = 0; i <2; i++)
	{
		cout << "Enter name: ";
		cin >> name;
		cout << "Type of work: ";
		cin >> TypeOfWork;
		cout << "Price: ";
		cin >> price;
		cout << "Days: ";
		cin >> days;
		if (i % 2 == 0)
		{
			try
			{
				poorCustomer.SetRequest(name, TypeOfWork, price, days);
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
				continue;
			}
			order.AddOrder(dispatcher, &poorCustomer, orderList);
			order.ShowOrder();
			order.addToList();
		}
		else
		{
			try
			{
				vipCustomer.SetRequest(name, TypeOfWork, price, days);
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
			}
			order.AddOrder(dispatcher, (Customer<string,int, int>*)&vipCustomer, orderList);
			order.ShowOrder();
			order.addToList();
			continue;
		}
	}

	return 0;
}