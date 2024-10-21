#include "PersonMedTelefon.h"
#include <iostream>


	PersonMedTelefon::PersonMedTelefon(const std::string& name, const std::string& adress, const std::string& telefonNummer)
		:Person(name, adress), telefonNummer(telefonNummer)
	{

	}
	void PersonMedTelefon::Print()const
	{
		Person::Print();
		std::cout << "Telefonnummer: " << telefonNummer << std::endl;
	}
	
	
	








