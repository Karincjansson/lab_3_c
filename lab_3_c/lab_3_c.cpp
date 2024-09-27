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
		Töm();
	}

	
	
	bool LäggTill(const Person* const person) {

		if(currentSize<maxStorlek)
		{
			personer[currentSize++] = person;
			return true; 
		}
		return false;

	}
	bool LäggTillTest(const std::string& namn, const std::string& adress) {

		return LäggTill(new Person(namn, adress));
	}
	void TaBortEntry(Person* ptr)
	{
		if(ptr>= personer && ptr<personer + currentSize)
		{
			int index = ptr - personer;
			for(Person* it =personer +index; it!= personer + currentSize-1; it++)
			{
				*it = *it(it + 1);
			}
			currentSize--;
		}
	}
	void Töm() {
		currentSize = 0;
	}
	Person* SökNamn(const std::string& namn)
	{
		for(Person* ptr = personer;ptr!= personer + currentSize;++ptr )
		{
			if (ptr->name==namn)
			{
				return ptr;
			}
		}
		return nullptr;
	}

	void Print() const
	{
		for(Person*ptr = personer; ptr!=personer + currentSize;ptr++ )
		{
			person->Print();
		}
	}
};

void Init(PersonReg& tr) {
	tr.Töm();
	PD(tr.LäggTillTest("olle", "0703955123"));
	PD(tr.LäggTillTest("olle", "123"));
	PD(tr.LäggTillTest("kurtåke", "12345"));
	PD(tr.LäggTillTest("olle", "456"));
	PD(tr.LäggTillTest("sven", "456"));
	PD(tr.LäggTillTest("kurt", "95815"));
	PN(std::endl);
	PN(("fullt reg "));
	PN((std::endl));
	DN((tr.Print()));
}

#include <fstream>
bool ReadReg(PersonReg& reg, std::string fileName) {
	std::string line;
	std::ifstream myfile("PersonExempel.txt");

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			while (line.length() == 0 && getline(myfile, line))
				;
			std::string name(line);
			std::string adress;
			getline(myfile, adress);
			Person p(name, adress);
			reg.LäggTill(&p);
		}
		myfile.close();
		return true;
	}
	else {
		std::cout << "Unable to open file";
		return false;
	}
}

void Test1() {
	PersonReg reg(10);
	ReadReg(reg, "PersonExempel.txt");
	reg.Print(); std::cout << "\n\n";
	reg.Töm();

	reg.Print();
}

void Test2() {
	PersonReg reg(10);
	Init(reg);
	std::string namn, adress;
	Person* tep;

	tep = reg.SökNamn("olle");
	if (tep) {
		std::cout << tep->adress << std::endl;
		reg.TaBortEntry(tep);
	}
	else
		std::cout << "not found \n";

	tep = reg.SökNamn("olle");
	if (tep) {
		std::cout << tep->adress << std::endl;
		reg.TaBortEntry(tep);
	}
	else
		std::cout << "not found \n";

	tep = reg.SökNamn("olle");
	if (tep) {
		std::cout << tep->adress << std::endl;
		reg.TaBortEntry(tep);
	}
	else
		std::cout << "not found \n";

	tep = reg.SökNamn("olle");
	if (tep) {
		std::cout << tep->adress << std::endl;
		reg.TaBortEntry(tep);
	}
	else
		std::cout << "not found \n";

	tep = reg.SökNamn("olle");
	if (tep) {
		std::cout << tep->adress << std::endl;
		reg.TaBortEntry(tep);
	}
	else
		std::cout << "not found \n";

	reg.Print();

	reg.Töm();
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
//    while (tep = reg.SökFritt("olle", tep)) {
//        tep->Print();
//        //        cout << tep->adress << endl;
//    }
//    cout << "not found \n";
//
//    cout << "blandade sökningar \n";
//    Person* ptr1 = nullptr, * ptr2 = nullptr;
//    bool first = true;
//    while (first || ptr1 || ptr2) {
//        if (ptr1 || first) {
//            ptr1 = reg.SökFritt("olle", ptr1);
//            if (ptr1)
//                ptr1->Print();
//        }
//        if (ptr2 || first) {
//            ptr2 = reg.SökFritt("581", ptr2);
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
	Test2();
	//Test3();
	std::cin.get();
}
//int main()
//{
//	std::cout << "Hello World!\n";
//}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
