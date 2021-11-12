#include "OrderList.h"

int OrderList::ListSize = 0;
int OrderList::AmountOfOrders = 0;
void OrderList::AddOrder(string name, string TypeOfWork, int price, int days, Worker* team, const int size, const int groupSize, const int groupNumber)
{
	
	AmountOfOrders++;
	if (AmountOfOrders == 1)
	{
		this->TypeOfWork = new string[AmountOfOrders];
		this->price = new int[AmountOfOrders];
		this->days = new int[AmountOfOrders];
		this->name = new string[AmountOfOrders];
		this->TypeOfWork[0] = TypeOfWork;
		this->price[0] = price;
		this->days[0] = days;
		this->name[0] = name;
	}
	else
	{
		string* WorkBuffer = new string[AmountOfOrders];
		string* NameBuffer = new string[AmountOfOrders];
		int* PriceBuffer = new int[AmountOfOrders];
		int* DaysBuffer = new int[AmountOfOrders];
		for (int i = 0; i < AmountOfOrders-1; i++)
		{
			WorkBuffer[i] = this->TypeOfWork[i];
			PriceBuffer[i] = this->price[i];
			DaysBuffer[i] = this->days[i];
			NameBuffer[i] = this->name[i];
		}
		WorkBuffer[AmountOfOrders-1] = TypeOfWork;
		PriceBuffer[AmountOfOrders - 1] = price;
		DaysBuffer[AmountOfOrders - 1] = days;
		NameBuffer[AmountOfOrders - 1] = name;
		delete[] this->TypeOfWork;
		delete[] this->price;
		delete[] this->days;
		delete[] this->name;
		*&this->TypeOfWork = WorkBuffer;
		*&this->price = PriceBuffer;
		*&this->days = DaysBuffer;
		*&this->name = NameBuffer;
	}
	if ((groupNumber == groupSize) && size != 0)
	{
		ListSize = size;
		if (AmountOfOrders == 1)
		{
			teamList = new Worker * [AmountOfOrders];
			for (int i = 0; i < AmountOfOrders; i++)
			{
				teamList[i] = new Worker[size];
			}
			for (int i = 0; i < size; i++)
			{
				teamList[AmountOfOrders - 1][i] = team[i];
			}
		}
		else
		{
			Worker** teamListBuffer = new Worker * [AmountOfOrders];
			for (int i = 0; i < AmountOfOrders-1; i++)
			{
				teamListBuffer[i] = new Worker[3];
			}
			teamListBuffer[AmountOfOrders] = new Worker[size];
			for (int i = 0; i < 3; i++)
			{
				teamListBuffer[AmountOfOrders - 2][i] = teamList[AmountOfOrders - 2][i];
			}
			for (int i = 0; i < size; i++)
			{
				teamListBuffer[AmountOfOrders - 1][i] = team[i];
			}
			for (int i = 0; i < AmountOfOrders - 2; i++)
			{
				delete[] teamList[i];
			}
			delete[] teamList;
			*&teamList = teamListBuffer;
		}
	}
	else
	{
		if (AmountOfOrders == 1)
		{
			teamList = new Worker * [AmountOfOrders];
			for (int i = 0; i < AmountOfOrders; i++)
			{
				teamList[i] = new Worker[3];
			}
			for (int i = 0; i < 3; i++)
			{
				teamList[AmountOfOrders - 1][i] = team[i];
			}
		}
		else
		{
			Worker** teamListBuffer = new Worker * [AmountOfOrders];
			for (int i = 0; i < AmountOfOrders; i++)
			{
				teamListBuffer[i] = new Worker[3];
			}
			for (int i = 0; i < AmountOfOrders - 1; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					teamListBuffer[i][j] = teamList[i][j];
				}
			}
			
			for (int i = 0; i < 3; i++)
			{
				teamListBuffer[AmountOfOrders - 1][i] = team[i];
			}
			for (int i = 0; i < AmountOfOrders - 2; i++)
			{
				delete[] teamList[i];
			}
			delete[] teamList;
			*&teamList = teamListBuffer;
		}
	}
}

void OrderList::ShowOrders()
{
	for (int i = 0; i < AmountOfOrders; i++)
	{
		cout << "Requester: " << this->name[i] << endl;
		cout << "Type of Work: " << this->TypeOfWork[i] << endl;
		cout << "Price: " << this->price[i] << endl;
		cout << "Days: " << this->days[i] << endl;
		cout << "Workers in this task: ";
		for (int  j = 0; j < 3; j++)
		{
			cout << *this->teamList[i][j].GetWorker()<<" ";
		}
		cout << endl;
	}
}

void OrderList::WriteToFile()
{
	fstream fs;
	fs.open("MyFile.txt", fstream::in | fstream::out);

	if (!fs.is_open())
	{
		cout << "ERROR!" << endl;
	}
	else
	{
		for (int i = 0; i < AmountOfOrders; i++)
		{
			fs << "Requester: " << this->name[i] << endl;
			fs << "Type of Work: " << this->TypeOfWork[i] << endl;
			fs << "Price: " << this->price[i] << endl;
			fs << "Days: " << this->days[i] << endl;
			fs << "Workers in this task: ";
			for (int j = 0; j < 3; j++)
			{
				fs << *this->teamList[i][j].GetWorker() << " ";
			}
			fs << endl;
		}
	}
}

OrderList::~OrderList()
{
	delete[] this->name;
	delete[] this->price;
	delete[] this->TypeOfWork;
	delete[] this->days;
	for (int i = 0; i < AmountOfOrders - 1; i++)
	{
		delete[] teamList[i];
	}
	delete[] teamList;
}
