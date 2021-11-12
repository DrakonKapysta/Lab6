#pragma once
#include<iostream>
#include<string>
#include"Team.h"
#include"Person.h"

using namespace std;


class Dispatcher: public Person
{
public:
	Dispatcher(string name, int age);
	void SetTeam(Team& team);
	void ShowDispTeam();
	Team* GetTeam();

private:
	Team* team;
};

