#include "Team.h"

int Team::size = 0;
int Team::GroupAmount = 1;
int Team::counter = 0;

void Team::SetTeamMember(Worker& worker)
{
	counter++;
	size++;
	if (size == 1 && GroupAmount == 1)
	{
		this->team = new Worker * [1];
		this->team[0] = new Worker[3];
		this->team[0][0] = worker;
	}
	else
	{
		Worker** NewTeam = new Worker * [GroupAmount];
		if (GroupAmount == 1)
			NewTeam[0] = new Worker[size];
		else
		{
			int i = 0;
			for (i; i < GroupAmount - 1; i++)
			{
				NewTeam[i] = new Worker[3];
			}
			NewTeam[i] = new Worker[size];
			for (int i = 0; i < GroupAmount - 1; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					NewTeam[i][j] = this->team[i][j];
				}
			}
			for (int j = 0; j < size - 1; j++)
			{
				NewTeam[GroupAmount - 1][j] = this->team[i][j];
			}
			NewTeam[GroupAmount - 1][size - 1] = worker;
			if (GroupAmount >= 2 && size > 1)
			{
				for (int i = 0; i < GroupAmount; i++)
				{
					delete[] team[i];
				}
			}
			else
			{
				for (int i = 0; i < GroupAmount - 1; i++)
				{
					delete[] team[i];
				}
			}
			delete[] team;
			*&team = NewTeam;
			if (size == 3)
			{
				GroupAmount++;
				size = 0;
			}
			return;
		}
		for (int i = 0; i < GroupAmount; i++)
		{
			for (int j = 0; j < size - 1; j++)
			{
				NewTeam[i][j] = this->team[i][j];
			}
		}
		NewTeam[GroupAmount - 1][size - 1] = worker;
		for (int i = 0; i < GroupAmount; i++)
		{
			delete[] team[i];
		}
		delete[] team;
		*&team = NewTeam;
	}
	if (size == 3)
	{
		GroupAmount++;
		size = 0;
	}
}

void Team::ShowTeam()
{
	for (int i = 0; i < GroupAmount - 1; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << team[i][j].GetWorker() << endl;
		}
	}
}

int Team::GetGroupAmount()
{
	return GroupAmount;
}

int Team::GetGroupSize()
{
	return size;
}



Worker* Team::GetTeam(int NumberOfGroup)
{
	if (NumberOfGroup >= GroupAmount-1)
	{
		cout << "There is no such group!" << endl;
	}
	else
		return this->team[NumberOfGroup];

}

Team::~Team()
{
	if (GroupAmount >= 2 && size > 1)
	{
		for (int i = 0; i < GroupAmount; i++)
		{
			delete[] team[i];
		}
	}
	else
	{
		for (int i = 0; i < GroupAmount - 1; i++)
		{
			delete[] team[i];
		}
	}
}
