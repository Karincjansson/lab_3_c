
#include "Person.h"
#include <iostream>
#include <string>
#define PN(x) std::cout << x


	std::string name, adress;


	Person::Person():name(""), adress("") {}

	Person::Person(const std::string& name, const std::string& adress):name(name),adress(adress)//lol prova ta bort efter :
	{
	}
	std::string Person::getName() const
	{
		return name;
	}
	std::string Person::getAdress() const
	{
		return adress;
	}
	void Person::Print() const
	{
		PN("Namn: " + name +" "+ "Adress: " + adress);
		PN( "\n");
	};
	


