#pragma once
#ifndef PERSONREG_H
#define PersonReg_H
#include "Person.h"
#include <string>


class PersonReg
{
private:
	Person* personer;

	//int maxSize;
	int currentSize;
public:
	PersonReg(int maxSize);
	~PersonReg();
	int maxSize;
	bool L�ggTill(const Person& person);
	bool L�ggTillTest(const std::string& namn, const std::string& adress);
	bool ReadReg(PersonReg& reg, const std::string& filename);
	void TaBortEntry(Person* ptr);
	Person* S�kNamn(const std::string& namn)const;
	void Print()const;
	void T�m();
	Person* S�kFritt(const std::string& s�kEfter, Person* startOnNext)const;

};

#endif // PERSONREG_H