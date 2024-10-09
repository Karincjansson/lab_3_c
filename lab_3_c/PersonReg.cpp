#include "PersonReg.h"
#include "Person.h"
#include <fstream>
#include <iostream>

	PersonReg::PersonReg(int maxSize) : maxSize(maxSize), currentSize(0)
	{
		personer = new Person[maxSize];
	}
	PersonReg::~PersonReg()
	{
		Töm();
		delete[] personer;
	}
	bool  PersonReg::LäggTill(const Person& person) {

		if (currentSize < maxSize)//om det finns plats lägg till
		{
			personer[currentSize++] = person;
			return true;
		}
		return false;

	}
	bool  PersonReg::ReadReg(PersonReg& reg, const std::string& fileName) {
		std::string line;
		std::ifstream myfile("PersonExempel.txt");

		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				while (line.length() == 0 && getline(myfile, line));
				std::string name(line);
				std::string adress;
				getline(myfile, adress);
				Person p(name, adress);
				reg.LäggTill(p);
			}
			myfile.close();
			return true;
		}
		else
		{
			std::cout << "Unable to open file";
			return false;
		}
	}
		
		
	bool PersonReg::LäggTillTest(const std::string& namn, const std::string& adress) {
	
		if (currentSize < maxSize)//om det finns plats lägg till
		{
			personer[currentSize++] =  Person(namn, adress);
			return true;
		}
		return false;
	}

	void PersonReg::TaBortEntry(Person* ptr)
	{
		if (ptr >= personer && ptr < personer + currentSize)
		{
			int index = ptr - personer;
			for (Person* it = personer + index; it < personer + currentSize - 1; it++)
			{
				*it = *(it + 1);
			}
			currentSize--;
		}
	}
	void PersonReg::Töm() {
		currentSize = 0;
	}
	Person* PersonReg::SökNamn(const std::string& namn)const
	{
		for (Person* ptr = personer; ptr != personer + currentSize; ++ptr)
		{
			if (ptr->getName() == namn)
			{
				return ptr;
			}
		}
		return nullptr;
	}

	void PersonReg::Print() const
	{
		for (Person* ptr = personer; ptr != personer + currentSize; ptr++)
		{
			ptr->Print();
		}
	}

	Person* PersonReg::SökFritt(const std::string& sökEfter, Person* startonNext) const
	{
		return nullptr;
	}
