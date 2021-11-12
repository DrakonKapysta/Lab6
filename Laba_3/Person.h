#pragma once
#include<iostream>
#include<string>

using namespace std;

class Person
{
public:
	void GetMessage();
	void SetName(string name);
	void SetAge(int age);

	string GetName();
	int GetAge();
	Person& operator =(const Person& other);
	bool operator ==(const Person& other);
	bool operator !=(const Person& other);
	bool operator >(const Person& other);
	bool operator <(const Person& other);
	bool operator <=(const Person& other);
	bool operator >=(const Person& other);
	Person operator +(const Person& other);
	Person operator -(const Person& other);
	Person operator *(const Person& other);
	Person operator %(const Person& other);
	Person& operator +=(const Person& other);
	Person& operator -=(const Person& other);
	Person& operator *=(const Person& other);
	Person& operator %=(const Person& other);
	Person& operator ++();
	Person operator ++(int value);
	Person& operator --();
	Person operator --(int value);
	int& operator[](int index);
	Person(const Person& other);
	Person();

private:
	string name;
	int age;
	int arr[5]{234,12,14,63,35};
};

