// lab_3_c.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <fstream>
#include <vector>
#include <string>
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif

#if 1
#define PN(x) std::cout << x
#define DN(x) x
#define PD(x) std::cout << x
#else
#define PN(x)
#define DN(x)
#define PD(x) (x)
#endif

struct Person {
	std::string name;
	std::string adress;
	Person() :name(""), adress("") {}
	Person(std::string name, std::string adress) : name(name), adress(adress) {}
	void Print() const
	{
		std::cout << "Namn: " << name << "Address: " << adress << std::endl;
	}
};

class PersonReg {
private:

	Person* personer;
	int maxStorlek;
	int currentSize;
public:
	PersonReg(int maxStorlek) : maxStorlek(maxStorlek), currentSize(0)
	{
		personer = new Person[maxStorlek];
	}
	~PersonReg()
	{
		T�m();
		delete[] personer;
	}



	bool L�ggTill(const Person& person) {

		if (currentSize < maxStorlek)
		{
			personer[currentSize++] = person;
			return true;
		}
		return false;

	}
	bool L�ggTillTest(const std::string& namn, const std::string& adress) {

		return L�ggTill(Person(namn, adress));
	}
	void TaBortEntry(Person* ptr)
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
	void T�m() {
		currentSize = 0;
	}
	Person* S�kNamn(const std::string& namn)
	{
		for (Person* ptr = personer; ptr != personer + currentSize; ++ptr)
		{
			if (ptr->name == namn)
			{
				return ptr;
			}
		}
		return nullptr;
	}

	void Print() const
	{
		for (Person* ptr = personer; ptr != personer + currentSize; ptr++)
		{
			ptr->Print();
		}
	}
};

void Init(PersonReg& tr) {
	tr.T�m();
	PD(tr.L�ggTillTest("Olle", "0703955123"));
	PD(tr.L�ggTillTest("Olle", "123"));
	PD(tr.L�ggTillTest("Kurt�ke","12345"));
	PD(tr.L�ggTillTest("Olle", "456"));
	PD(tr.L�ggTillTest("Sven", "456"));
	PD(tr.L�ggTillTest("Kurt", "95815"));
	PN(std::endl);
	PN(("fullt reg "));
	PN((std::endl));
	DN((tr.Print()));
}

#include <fstream>
bool ReadReg(PersonReg& reg, const std::string& fileName) {
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

void Test1() {
	PersonReg reg(10);
	ReadReg(reg, "PersonExempel.txt");
	reg.Print(); std::cout << "\n\n";
	reg.T�m();

	reg.Print();
}

void Test2() {
	PersonReg reg(10);
	ReadReg(reg, "PersonExempel.txt");
	reg.Print(); std::cout << "\n\n";
	//Init(reg);
	std::string namn, adress;

	std::cout << "vilket namn vill du ta bort? \n";
	std::getline(std::cin, namn);

	Person* tep = reg.S�kNamn(namn);

	if (tep) {
		std::cout << "Adress f�r " << namn << ": " << tep->adress << std::endl;

		reg.TaBortEntry(tep);
		std::cout << "Har tagits bort fr�n registret. \n";
	}
	else {
		std::cout << "not found \n";
	}

	std::cout << "Aktuellt register efter borttagning: \n";
	reg.Print();

	reg.T�m();
	std::cout << "Registret har t�mts \n";
	reg.Print();
}
void Test2ish() {
	PersonReg reg(10);
	Init(reg);
	std::string namn, adress;

	std::cout << "vilket namn vill du ta bort? \n";
	std::getline(std::cin, namn);

	Person* tep = nullptr;
	bool found = false;
	// genom att anv�nda en whileloop s� g�r koden igenom alla instanser av namnet angivet. tar bort alla olle till exempel
	while((tep=reg.S�kNamn(namn))!=nullptr)
	{
		std::cout << "Adress f�r " << namn << ": " << tep->adress << std::endl;

		reg.TaBortEntry(tep);
		found = true;
		std::cout << "Har tagits bort fr�n registret. \n";
	}
	if(!found)
	{
		std::cout << "not found \n";
	}
	std::cout << "Aktuellt register efter borttagning: \n";
	reg.Print();

	reg.T�m();
	std::cout << "Registret har t�mts \n";
	reg.Print();
}

//void Test3() {
//    PersonReg reg(10);
//
//    Init(reg);
//    reg.Print();
//    string namn, adress;
//    Person te, * tep;
//
//    tep = nullptr;
//    while (tep = reg.S�kFritt("olle", tep)) {
//        tep->Print();
//        //        cout << tep->adress << endl;
//    }
//    cout << "not found \n";
//
//    cout << "blandade s�kningar \n";
//    Person* ptr1 = nullptr, * ptr2 = nullptr;
//    bool first = true;
//    while (first || ptr1 || ptr2) {
//        if (ptr1 || first) {
//            ptr1 = reg.S�kFritt("olle", ptr1);
//            if (ptr1)
//                ptr1->Print();
//        }
//        if (ptr2 || first) {
//            ptr2 = reg.S�kFritt("581", ptr2);
//            if (ptr2)
//                ptr2->Print();
//        }
//        first = false;
//    }
//}

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	std::locale::global(std::locale("swedish"));
	PersonReg pr(5);
	Init(pr);
	Test1();
	Test2ish();
	//Test2();
	//Test3();
	std::cin.get();
}
