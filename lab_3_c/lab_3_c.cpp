// lab_3_c.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Person.h"
#include "PersonReg.h"
#include "PersonMedTelefon.h"

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



void Init(PersonReg& tr) {
	
	tr.Töm();


	tr.LäggTillTest("Olle", "0703955123");
	tr.LäggTillTest("Olle", "123");
	tr.LäggTillTest("Kurtåke", "12345");
	tr.LäggTillTest("Olle", "456");
	tr.LäggTillTest("Sven", "456");
	tr.LäggTillTest("Kurt", "95815");
	

	PN(std::endl);
	PN(("fullt reg "));
	PN((std::endl));
	DN((tr.Print()));
}

#include <fstream>


void Test1() {
	PersonReg reg(10);
	reg.ReadReg(reg, "PersonExempel.txt");
	reg.Print(); //PN("\n\n");
	reg.Töm();

	reg.Print();

}

void Test2() {
	PersonReg reg(10);
	//reg.Print(); std::cout << "\n\n";
	Init(reg);
	std::string namn, adress;

	PN("vilket namn vill du ta bort? \n");
	std::getline(std::cin, namn);

	Person* tep = reg.SökNamn(namn);

	if (tep) {
		std::cout << "Adress för " << namn << ": " << tep->getAdress() << std::endl;

		reg.TaBortEntry(tep);
		PN("Har tagits bort från registret. \n");
	}
	else {
		PN("not found \n");
	}
	/*Person* tep = reg.SökNamn(namn);*/

	if (tep) {
		std::cout << "Adress för " << namn << ": " << tep->getAdress() << std::endl;

		reg.TaBortEntry(tep);
		PN("Har tagits bort från registret. \n");
	}
	else {
		PN("not found \n");
	}
	/*Person* tep = reg.SökNamn(namn);*/

	if (tep) {
		std::cout << "Adress för " << namn << ": " << tep->getAdress() << std::endl;

		reg.TaBortEntry(tep);
		PN("Har tagits bort från registret. \n");
	}
	else {
		PN("not found \n");
	}
	/*Person* tep = reg.SökNamn(namn);*/

	if (tep) {
		std::cout << "Adress för " << namn << ": " << tep->getAdress() << std::endl;

		reg.TaBortEntry(tep);
		PN("Har tagits bort från registret. \n");
	}
	else {
		PN("not found \n");
	}
	/*Person* tep = reg.SökNamn(namn);*/

	if (tep) {
		std::cout << "Adress för " << namn << ": " << tep->getAdress() << std::endl;

		reg.TaBortEntry(tep);
		PN("Har tagits bort från registret. \n");
	}
	else {
		PN("not found \n");
	}

	PN("Aktuellt register efter borttagning: \n");
	reg.Print();

	reg.Töm();
	PN("Registret har tömts \n");
	reg.Print();
}
void Test2ish() {

	std::string namn, adress;
	PersonReg reg(6);
	
	Init(reg);
	
	/*PN(reg.maxSize );
	PN("\n");*/
	//reg.ReadReg(reg , "PersonExempel.txt");

	//
	//reg.Print();//ifall du använder textfilen
	PN("\n");
	PN("vilket namn vill du ta bort? \n");
	std::getline(std::cin, namn);

	Person* tep = nullptr;
	bool found = false;
	// genom att använda en whileloop så går koden igenom alla instanser av namnet angivet. tar bort alla olle till exempel
	while ((tep = reg.SökNamn(namn)) != nullptr)
	{
		std::cout << "Adress för " << namn << ": " << tep->getAdress() << std::endl;

		reg.TaBortEntry(tep);
		found = true;
		PN("Har tagits bort från registret. \n\n");
	}
	if (!found)
	{
		std::cout << "not found \n";
	}
	PN("Aktuellt register efter borttagning: \n\n");
	reg.Print();// visar vilka som är kvar

	reg.Töm();//töm 
	PN("\n");
	PN("Registret har tömts \n");
	reg.Print();//kollara bara att det är tömt ordentligt
}

void Test3() {
	PersonReg reg(6);

	Init(reg);
	PN('\n');

	std::string namn, adress;
	Person* tep;

	tep = nullptr;//sätts till nullptr så sökningen börjar från först instansen

	//om söknamnet Olle finns så skrivs all info ut
	while (tep = reg.SökFritt("Olle", tep)) {
		tep->Print();
		//cout << tep->adress << endl;
	}
	//om inte skrivs not found ut
	/*PN("not found \n");
	PN('\n');*/


	PN("blandade sökningar: \n");
	//om adressen hr en siffra i sig så skrivs den ut, även om den är utskriven på namn med
	Person* ptr1 = nullptr, * ptr2 = nullptr;
	bool first = true;
	while (first || ptr1 || ptr2) {
		if (ptr1 || first) {
			ptr1 = reg.SökFritt("Olle", ptr1);
			if (ptr1)
				ptr1->Print();
		}
		if (ptr2 || first) {
			ptr2 = reg.SökFritt("1", ptr2);
			if (ptr2)
				ptr2->Print();
		}
		first = false;
	}
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	std::locale::global(std::locale("swedish"));
		std::cin.imbue(std::locale("swedish"));
		std::cout.imbue(std::locale("swedish"));
	//PersonReg pr(10);
	//Init(pr);
	

	//Test1();
	//Test2ish();
	//Test2();//fixa? verkar som som den läser kurt som sven??
	Test3();

	//Uppgift 3?? bug !=butterfly
	/*PersonReg reg(2);

	Person* person1 = new Person("Anna ", "123456");
	Person* person2 = new PersonMedTelefon("Erik", "475849", "1234567");
	reg.LäggTill(*person1);
	reg.LäggTill(*person2);
	reg.Print();*/
	//Init(reg);

	std::cin.get();
}
