
#include "Person.h"
#include <iostream>
#include <string>
#define PN(x) std::cout << x


	std::string name, adress;


	Person::Person(){}

	Person::Person(const std::string& name, const std::string& adress)
	{
	}
	std::string Person::getName() const
	{
		return std::string();
	}
	std::string Person::getAdress() const
	{
		return std::string();
	}
	void Person::Print() const
	{
		PN("Namn: " + name + "Address: " + adress);

	};
	


