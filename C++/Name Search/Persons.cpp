#include "Persons.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

//default constructor
Persons::Persons()
{
	LN = "";
	FN = "";
	gender = "";
	age = 0;
}

//constructor for each object
Persons::Persons(std::string lastName, std::string firstName, std::string sex, int num)
{
	LN = lastName;
	FN = firstName;
	gender = sex;
	age = num;
}

//this function will output each of the variables for each object
void Persons::outputRecords()
{

	for (int i=0; i < pointCopy.size(); i++)
	{
		cout<<left<<setw(10)<<(*pointCopy[i]).LN
			<<left<<setw(10)<<(*pointCopy[i]).FN
			<<left<<setw(3)<<(*pointCopy[i]).gender
			<<left<<setw(5)<<(*pointCopy[i]).age<<endl;
	}
}

//another constructor, this one accepts the vector created in main
Persons::Persons(vector <Persons> example)
{
	copy = example;
}

//this constructor accepts the pointing vector and references
Persons::Persons(vector <Persons*>& pointers)
{
	pointCopy = pointers;
}

//selection sort algorithm
void Persons::sortRecords()
{
	int startScan, maxIndex, size;
	Persons maxValue;

	size = pointCopy.size();
	
	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		maxIndex = 0;
		maxValue = *pointCopy[0];

		for (int index = 1; index < size - startScan; index++)
		{

			if ((*pointCopy[index]).LN.compare(maxValue.LN) > 0)
			{
				maxValue = *pointCopy[index];
				maxIndex = index;
			}
			else if((*pointCopy[index]).LN.compare(maxValue.LN) == 0)
			{
				if((*pointCopy[index]).LN.compare(maxValue.FN) > 0)
				{
					maxValue = *pointCopy[index];
					maxIndex = index;
				}
			}
		}

		*pointCopy[maxIndex] = *pointCopy[size - 1 - startScan];
		*pointCopy[size - 1 - startScan] = maxValue;
	}
}

//the binary search to determine if an item is in the vector
void Persons::binSearch(string value, string value1)
{
	int first = 0,
		last = pointCopy.size() - 1,
		middle,
		position = -1;

	bool found = false;

	while (!found && first <= last)
	{
		middle = (first + last) / 2;

		if ((*pointCopy[middle]).LN == value)
		{
			if ((*pointCopy[middle]).FN == value1)
			{
				found = true;
				
				cout<<left<<setw(10)<<(*pointCopy[middle]).LN
					<<left<<setw(10)<<(*pointCopy[middle]).FN
					<<left<<setw(3)<<(*pointCopy[middle]).gender
					<<left<<setw(5)<<(*pointCopy[middle]).age<<endl;
			}
			else if ((*pointCopy[middle]).FN > value1)
				last = middle - 1;

			else
				first = middle + 1;
		}

		else if ((*pointCopy[middle]).LN > value)
			last = middle - 1;

		else
			first = middle + 1;
	}
	if (found == false)
		cout<<value<<" "<<value1<<" is not present in this file.";
}
