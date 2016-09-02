#include "stdafx.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Person 
{
private:
	string name, address, city, state, zipCode;
public:
	friend ostream & operator<<(ostream &, Person &);
	friend istream & operator>>(istream &, Person &);
};

istream & operator>>(istream &inputF, Person &aPerson)
{
	inputF.ignore(1, '\n');
	getline(inputF, aPerson.name);
	getline(inputF, aPerson.address);
	getline(inputF, aPerson.city);
	getline(inputF, aPerson.state);
	inputF >> aPerson.zipCode;
	return inputF;
}
ostream & operator<<(ostream &outputF, Person & aPerson)
{
	outputF << setw(20) << "Name: " << aPerson.name << endl;
	outputF << setw(20) << "Address: " << aPerson.address << endl;
	outputF << setw(20) << "City, State zip: " << aPerson.city << ", ";
	outputF << aPerson.state << "   " << aPerson.zipCode << endl;

	return outputF;
}

//class for a standard package
class Package
{
protected:
	Person shipper, receiver;
	int weightInOunces;
	double costPerOunceToShip;
	static int numberPackagesShipped;
public:
	static int outputNumberPackagesShipped()
	{
		return numberPackagesShipped;
	}
	void incrementNumberPackagesShipped() {
		numberPackagesShipped++;
	}
	void outputPackageShippingCost();
	friend ostream & operator<<(ostream &, Package &);
	friend istream & operator>>(istream &, Package &);
};
int Package::numberPackagesShipped = 0;

void Package::outputPackageShippingCost()
{
	cout << "Shipping cost for " << weightInOunces << " ounces @$" << costPerOunceToShip
	<< "/ounce is $" << weightInOunces << " costPerOunceToShip" << endl << endl;
}

ostream & operator<<(ostream &outputF, Package &aPackage)
{
	outputF << "\nShipper\n" << aPackage.shipper << endl;
	outputF << "\nReceiver\n" << aPackage.receiver << endl;
	return outputF;
}

istream & operator>>(istream &inputF, Package &aPackage)
{
	inputF >> aPackage.weightInOunces >> aPackage.costPerOunceToShip;
	inputF >> aPackage.shipper;
	inputF >> aPackage.receiver;

	return inputF;
}


//class for a two day package
class TwoDayPackage: public Package
{
protected:
	double priceCount;
	static int numberPackagesShippedTwoDay;
public:
	static int outputNumberPackagesShippedTwoDay()
	{
		return numberPackagesShippedTwoDay;
	}
	void incrementNumberPackagesShipped() {
		TwoDayPackage::numberPackagesShipped++;
	}
	void outputPackageShippingCost();
	friend ostream & operator<<(ostream &, TwoDayPackage &);
	friend istream & operator>>(istream &, TwoDayPackage &);
};

int TwoDayPackage::numberPackagesShippedTwoDay = 0;

void TwoDayPackage::outputPackageShippingCost()
{
	cout << "Shipping cost for " << weightInOunces << " ounces @$" << costPerOunceToShip
	<< "/ounce is $" << weightInOunces << " costPerOunceToShip" << endl << endl;
}

ostream & operator<<(ostream &outputF, TwoDayPackage &aTwoDayPackage)
{
	outputF << "\nShipper\n" << aTwoDayPackage.shipper << endl;
	outputF << "\nReceiver\n" << aTwoDayPackage.receiver << endl;
	return outputF;
}

istream & operator>>(istream &inputF, TwoDayPackage &aTwoDayPackage)
{
	inputF >> aTwoDayPackage.weightInOunces >> aTwoDayPackage.costPerOunceToShip;
	inputF >> aTwoDayPackage.shipper;
	inputF >> aTwoDayPackage.receiver;

	return inputF;
}


//class for an overnight package
class OvernightPackage: public Package
{
protected:
	double overnightCount;
	static int numberPackagesShippedOvernight;
public:
	static int outputNumberPackagesShipped()
	{
		return numberPackagesShipped;
	}
	void incrementNumberPackagesShipped() {
		OvernightPackage::numberPackagesShipped++;
	}
	void outputPackageShippingCost();
	friend ostream & operator<<(ostream &, OvernightPackage &);
	friend istream & operator>>(istream &, OvernightPackage &);
};

int OvernightPackage::numberPackagesShippedOvernight = 0;

void OvernightPackage::outputPackageShippingCost()
{
	cout << "Shipping cost for " << weightInOunces << " ounces @$" << costPerOunceToShip
	<< "/ounce is $" << weightInOunces << " costPerOunceToShip" << endl << endl;
}

ostream & operator<<(ostream &outputF, OvernightPackage &anOvernightPackage)
{
	outputF << "\nShipper\n" << anOvernightPackage.shipper << endl;
	outputF << "\nReceiver\n" << anOvernightPackage.receiver << endl;
	return outputF;
}

istream & operator>>(istream &inputF, OvernightPackage &anOvernightPackage)
{
	inputF >> anOvernightPackage.weightInOunces >> anOvernightPackage.costPerOunceToShip;
	inputF >> anOvernightPackage.shipper;
	inputF >> anOvernightPackage.receiver;

	return inputF;
}

int main()
{
	ifstream inputFile;
	string fileName;
	char packageType;
	Package aPackage;
	TwoDayPackage aTwoDayPackage;
	OvernightPackage anOvernightPackage;

	cout << "input the name of the file, including path if needed (no spaces allowed): ";
	cin >> fileName;

	inputFile.open(fileName);
	//inputFile.open("ShippingData.txt");

	while (!inputFile)
	{
		cout << "Incorrect file name - please re-input the file name\n";
		cin >> fileName;
	}

	inputFile >> packageType;
	while (!inputFile.fail())
	{
		switch (packageType)
		{
			case 'P':
				aPackage.incrementNumberPackagesShipped();
				inputFile >> aPackage;
				cout << "PACKAGE #" << Package::outputNumberPackagesShipped() << endl;
				cout << aPackage;
				aPackage.outputPackageShippingCost();
			case 'O':
				anOvernightPackage.incrementNumberPackagesShipped();
				inputFile >> anOvernightPackage;
				cout << "OVERNIGHT PACKAGE #" << OvernightPackage::outputNumberPackagesShipped() << endl;
				cout << anOvernightPackage;
				anOvernightPackage.outputPackageShippingCost();
				break;
			case 'T':
				aTwoDayPackage.incrementNumberPackagesShipped();
				inputFile >> aTwoDayPackage;
				cout << "TWO DAY PACKAGE #" << TwoDayPackage::outputNumberPackagesShipped() << endl;
				aTwoDayPackage.outputPackageShippingCost();
				break;
		}
		inputFile >> packageType;
	}

	cout << "\n\n" << setw(35) << "Total Packages Shipped: " << Package::outputNumberPackagesShipped() << endl;
	cout << setw(35) << "Total Two Day Packages Shipped: " << TwoDayPackage::outputNumberPackagesShipped() << endl;
	cout << setw(35) << "Total Overnight Packages Shipped: " << OvernightPackage::outputNumberPackagesShipped() << endl;

}