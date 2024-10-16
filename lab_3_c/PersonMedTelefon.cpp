#include "PersonMedTelefon.h"
#include "Person.h" 
#include <string>
#define PN(x) std::cout << x

	
	class PersonMedTelefon:public Person
	{
		std::string telefonNummer;
	public:
		PersonMedTelefon(const std::string& name, const std::string& adress, const std::string& telefonNummer)
			:Person(name,adress),telefonNummer(telefonNummer){}
		void Print() 
		{
			Person::Print();
			PN("Telefonnummer: " + telefonNummer + '\n');
		}
		
	};








