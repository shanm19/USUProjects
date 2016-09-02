// Shan Miller
// A01020750

#include "stdafx.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

//structure for each record
struct PartRecord
{
	int partID;
	char businessName[50], 
		address[50],
		city[30],
		state[5];
	int zipCode;
	int quantityOnHand;
};

//the function used to sort throught the binary
bool binSearch(fstream &binaryPartsFile, int partID) {

	int recordNumber;
	long int recordSizeInBytes = sizeof(PartRecord);   
	// This is the number of bytes in a record 
	long int totalRecordsInFile;  
	// total number of records in the file 
	long int first, last, middle; 
	bool found = false; 
	PartRecord aPartRecord; 

	binaryPartsFile.seekg(0L, ios::end);   
	// sets position to last byte in the file 
	totalRecordsInFile = binaryPartsFile.tellg()/recordSizeInBytes;  
	// tellg() gives number of bytes from start 
	binaryPartsFile.seekg(0L, ios::beg); 

	first = 0;  
	last = totalRecordsInFile - 1; 
	middle = (first + last)/2;   
	// record number to read and check id 

	// Now let's read that record 
	recordNumber = middle * recordSizeInBytes; 
	binaryPartsFile.seekg(recordNumber, ios::beg); 
	binaryPartsFile.read(reinterpret_cast<char *>(&aPartRecord), sizeof(PartRecord)); 

	// The test
	// It is right here that it is noticed that nothing is being saved into the binary version of the file
	if (aPartRecord.partID == partID) 
	{ 
		binaryPartsFile.seekg(-recordSizeInBytes, ios::cur); 
		return true; 
	} 
	else
		return false;

}

int main()
{
	bool found = false;
	fstream binaryPartsFile, outputFStream; 
	PartRecord aPartRecord;

	binaryPartsFile.open("bintest.txt", ios::in);
	//one possibility, if you check the folder I created, it shows the anything.dat to be a type "Video CD Movie"
	//or at least, on my computer.  I don't know why.
	outputFStream.open("anything.dat", ios::out | ios::binary);

	//this creates the structure and is supposed to translate it to binary
	//BUT THAT IS THE ONLY PART NOT WORKING
	while(!binaryPartsFile.fail()){
		string tempString;
		int TempNumOne;

		binaryPartsFile>>aPartRecord.partID;
		binaryPartsFile.ignore();
		//I wrote a bunch of couts so you can clearly tell that everything is at least making it into the normal file
		cout<<aPartRecord.partID;
		
		binaryPartsFile.getline(aPartRecord.businessName, 50);
		cout<<aPartRecord.businessName;

		binaryPartsFile.getline(aPartRecord.address, 50);
		cout<<aPartRecord.address;

		binaryPartsFile.getline(aPartRecord.city, 30);
		cout<<aPartRecord.city;

		binaryPartsFile.getline(aPartRecord.state, 5);

		cout<<aPartRecord.state;

		binaryPartsFile>>aPartRecord.zipCode;
		binaryPartsFile.ignore();
		binaryPartsFile>>aPartRecord.quantityOnHand;
		//this may the part where it's not writing to the file correctly
		outputFStream.write(reinterpret_cast<char *> (&aPartRecord), sizeof(PartRecord));
	}
	binaryPartsFile.close();


	int search;
	cout<<"\nEnter the Part ID you are searching for: ";
	cin>>search;

	//the loop that continues searching until the user inputs something invalid
	while(search >= 1){

	found = binSearch(outputFStream, search);

	if(found)
		cout<<"Part ID was found!";
	else
		cout<<"Not found!";

	cout<<"\nEnter the Part ID you are searching for: ";
	cin>>search;
	}

	outputFStream.close();
}

