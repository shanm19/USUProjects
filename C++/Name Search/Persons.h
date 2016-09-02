#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class Persons
{

public:

	Persons();
	Persons(std::string lastName, std::string firstName, std::string sex, int num);
	Persons(std::vector <Persons> example);
	Persons(std::vector <Persons*>& pointers);

	void outputRecords();
	void sortRecords();
	void binSearch(std::string value, std::string value1);

private:
	std::vector <Persons> copy;
	std::vector <Persons*> pointCopy;
	std::string FN, LN, gender;
	int age;

};