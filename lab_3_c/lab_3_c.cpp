// lab_3_c.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Person.h"
#include "PersonReg.h"

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
	tr.T�m();
	PD(tr.L�ggTillTest("Olle", "0703955123"));
	PD(tr.L�ggTillTest("Olle", "123"));
	PD(tr.L�ggTillTest("Kurt�ke", "12345"));
	PD(tr.L�ggTillTest("Olle", "456"));
	PD(tr.L�ggTillTest("Sven", "456"));
	PD(tr.L�ggTillTest("Kurt", "95815"));
	PN(std::endl);
	PN(("fullt reg "));
	PN((std::endl));
	DN((tr.Print()));
}

#include <fstream>


void Test1() {
	PersonReg reg(10);
	reg.ReadReg(reg, "PersonExempel.txt");
	reg.Print(); std::cout << "\n\n";
	reg.T�m();

	reg.Print();

}

void Test2() {
	PersonReg reg(10);
	reg.ReadReg(reg, "PersonExempel.txt");
	reg.Print(); std::cout << "\n\n";
	Init(reg);
	std::string namn, adress;

	PN("vilket namn vill du ta bort? \n");
	std::getline(std::cin, namn);

	Person* tep = reg.S�kNamn(namn);

	if (tep) {
		std::cout << "Adress f�r " << namn << ": " << tep->getAdress() << std::endl;

		reg.TaBortEntry(tep);
		PN("Har tagits bort fr�n registret. \n");
	}
	else {
		PN("not found \n");
	}

	PN("Aktuellt register efter borttagning: \n");
	reg.Print();

	reg.T�m();
	PN("Registret har t�mts \n");
	reg.Print();
}
void Test2ish() {
	PersonReg reg(10);
	Init(reg);
	std::string namn, adress;

	PN("vilket namn vill du ta bort? \n");
	std::getline(std::cin, namn);

	Person* tep = nullptr;
	bool found = false;
	// genom att anv�nda en whileloop s� g�r koden igenom alla instanser av namnet angivet. tar bort alla olle till exempel
	while ((tep = reg.S�kNamn(namn)) != nullptr)
	{
		std::cout << "Adress f�r " << namn << ": " << tep->getAdress() << std::endl;

		reg.TaBortEntry(tep);
		found = true;
		PN("Har tagits bort fr�n registret. \n");
	}
	if (!found)
	{
		std::cout << "not found \n";
	}
	PN("Aktuellt register efter borttagning: \n");
	reg.Print();

	reg.T�m();
	PN("Registret har t�mts \n");
	reg.Print();
}

//void Test3() {
//	PersonReg reg(10);
//
//	Init(reg);
//	reg.Print();
//	std::string namn, adress;
//	Person te, * tep;
//
//	tep = nullptr;
//	while (tep = reg.S�kFritt("olle", tep)) {
//		tep->Print();
//		//        cout << tep->adress << endl;
//	}
//	PN("not found \n");
//
//	PN("blandade s�kningar \n");
//	Person* ptr1 = nullptr, * ptr2 = nullptr;
//	bool first = true;
//	while (first || ptr1 || ptr2) {
//		if (ptr1 || first) {
//			ptr1 = reg.S�kFritt("olle", ptr1);
//			if (ptr1)
//				ptr1->Print();
//		}
//		if (ptr2 || first) {
//			ptr2 = reg.S�kFritt("581", ptr2);
//			if (ptr2)
//				ptr2->Print();
//		}
//		first = false;
//	}
//}

	int main()
	{
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
