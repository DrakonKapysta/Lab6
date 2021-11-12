#pragma once
#include<iostream>
#include<string>
#include"Person.h"

using namespace std;

class Worker: public Person
{
public:
	Worker(string name, int age);
	Worker();
	void GetMessage();
	string *GetWorker();
	void SetWorkBool(bool& IfWork);
	bool & ShowWorkBool();



private:
	/*string name_p;*/
	bool IfWork;
};

