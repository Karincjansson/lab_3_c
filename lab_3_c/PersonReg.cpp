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
		T�m();
		delete[] personer;
	}
	bool  PersonReg::L�ggTill(const Person& person) {

		if (currentSize < maxSize)//om det finns plats l�gg till
		{
			personer[currentSize++] = person;
			return true;
		}
		return false;

	}

	bool PersonReg::L�ggTillTest(const std::string& namn, const std::string& adress) {

		Person newPerson(namn, adress);
		//if (currentSize < maxSize)//om det finns plats l�gg till
		//{
		//	personer[currentSize++] =  Person(namn, adress);
		//	return true;
		//}
		//return false;
		return L�ggTill(newPerson);
	}

	bool  PersonReg::ReadReg(PersonReg& reg, const std::string& fileName) {
		std::string line;
		std::ifstream myfile("PersonExempel.txt");
		/*myfile.imbue(std::locale("swedish"));*/

		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				while (line.length() == 0 && getline(myfile, line));
				std::string name(line);
				std::string adress;
				getline(myfile, adress);
				Person p(name, adress);
				reg.L�ggTill(p);
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
	void PersonReg::T�m() {
		currentSize = 0;
	}
	Person* PersonReg::S�kNamn(const std::string& namn)const
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

	Person* PersonReg::S�kFritt(const std::string& s�kEfter, Person* startOnNext) const
	{
		//om staronnext �r null,s�tt start till b�rjan av personer annars k�r fr�n satt position
		Person* start = (startOnNext == nullptr)? personer : startOnNext + 1;
		for(Person* ptr = start;ptr<personer + currentSize;ptr++)//loops genom personer
		{
			//om namn eller adress finns returnera personen
			if(ptr->getName().find(s�kEfter)!= std::string::npos|| ptr->getAdress().find(s�kEfter) != std::string::npos)
			{
				return ptr;
			}
		}
		//om ingen hittat returnera null
		return nullptr;
	}
	