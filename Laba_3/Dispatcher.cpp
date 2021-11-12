#include "Dispatcher.h"

Dispatcher::Dispatcher(string name, int age)
{
	this->SetName(name);
	this->SetAge(age);
}

void Dispatcher::SetTeam(Team& team)
{
	this->team = &team;
	
}

void Dispatcher::ShowDispTeam()
{	

	cout<<this->team->GetTeam(0)[2].GetWorker();
	
	
}

Team* Dispatcher::GetTeam()
{
	return this->team;
}


