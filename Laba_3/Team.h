#pragma once

#include<iostream>
#include<string>
#include"Worker.h"

using namespace std;

class Team
{
public:

	void SetTeamMember(Worker& worker);
	void ShowTeam();
	int GetGroupAmount();
	int GetGroupSize();

	Worker* GetTeam(int NumberOfGroup);
	~Team();
private:
	static int size;
	static int counter;
	static int GroupAmount;
	Worker** team;
};

