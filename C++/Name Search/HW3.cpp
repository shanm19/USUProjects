//A01020750
//Shan Miller
//HW4

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Persons.h"

using namespace std;

string fileName, readIn1, readIn2, readIn3, searchLN, searchFN;
int age;
bool searchBool = true;


//this will find the file and read in the text to a document
void fillVector(vector <Persons>& pass, vector <Persons*>& pointing)
{
	static int counter = 0;

	cout<<"What is the name of the file, including the extension?";
	cin>>fileName;
	
		ifstream myfile(fileName);

		if (myfile.is_open())
		{
			
			while (!myfile.eof())
			{
				myfile>>readIn1;
				myfile>>readIn2;
				myfile>>readIn3;
				myfile>>age;

				Persons person(readIn1, readIn2, readIn3, age);

				pass.push_back(person);
				
				
				counter++;
			}

			for(int i = 0; i < pass.size(); i++)
			pointing.push_back(&pass[i]);

			myfile.close();
		}

		else cout << "File was not found.";
		
}
				
//main
int main()
{
	vector <Persons> objects;

	vector <Persons*> recordPointers;

	fillVector(objects, recordPointers);

	Persons test(objects);
	Persons references(recordPointers);

	references.outputRecords();
	cout<<endl;

	references.sortRecords();
	references.outputRecords();

	while(searchBool = true)
	{
		cout<<"Enter a name you're searching for in the format <last name> <first name>, \n"
			<<"or type \"I quit\" to terminate: ";
		cin>>searchLN;
		cin>>searchFN;

		if (searchLN == "I" && searchFN == "quit")
			return 0;

		references.binSearch(searchLN, searchFN);
	}

}