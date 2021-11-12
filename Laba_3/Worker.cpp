#include "Worker.h"


Worker::Worker(string name, int age):
	 IfWork(false)
{
	this->SetName(name);
}

Worker::Worker() {}

void Worker::GetMessage()
{
	cout << "I am a worker" << endl;
}

string* Worker::GetWorker()
{
	return &this->GetName();

}
bool& Worker::ShowWorkBool()
{
	return this->IfWork;
}
void Worker::SetWorkBool(bool& IfWork)
{
	this->IfWork = IfWork;
}
;
