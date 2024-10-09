#pragma once
#ifndef PERSONREG_H
#define PersonReg_H
#include "Person.h"
#include <string>


class PersonReg
{
private:
	Person* personer;

	int maxSize;
	int currentSize;
public:
	PersonReg(int maxSize);
	~PersonReg();

	bool LäggTill(const Person& person);
	bool LäggTillTest(const std::string& namn, const std::string& adress);
	bool ReadReg(PersonReg& reg, const std::string& filename);
	void TaBortEntry(Person* ptr);
	Person* SökNamn(const std::string& namn)const;
	void Print()const;
	void Töm();
	Person* SökFritt(const std::string& sökEfter, Person* startonNext)const;

};

#endif // PERSONREG_H