#pragma once

#ifndef PersonMedTelefon_H
#define PersonMedTelefon_H
#include "person.h"
#include <string>
#include<iostream>
class PersonMedTelefon :public Person
{
private:
	std::string telefonNummer;
public:
	PersonMedTelefon(const std::string& name, const std::string& adress, const std::string& telefonNummer);
	void Print()const override;
	virtual ~PersonMedTelefon() = default;


};
#endif 