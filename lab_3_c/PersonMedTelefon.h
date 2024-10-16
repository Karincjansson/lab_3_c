#pragma once
 
class PersonMedTelefon :public Person
{
private:
	std::string telefonnNummer;
public: 
	PersonMedTelefon();
	 void Print()const override;
	 ~PersonMedTelefon();
};

