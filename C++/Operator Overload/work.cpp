//Shan Miller
//A01020750
//Assignment 5

#include <iostream>
#include <iomanip>
using namespace std;

class fractionClass // fractionClass that declares the private and public variables
{
	private:
		int numerator;
		int denominator;

	public:
		fractionClass(int, int);
		fractionClass(int);
		fractionClass() {numerator = 0; denominator=1;}

		fractionClass operator+(fractionClass);
		fractionClass operator-(fractionClass);
		fractionClass operator*(fractionClass);
		fractionClass operator/(fractionClass);

		bool operator>(fractionClass);
		bool operator>=(fractionClass);
		bool operator<(fractionClass);
		bool operator<=(fractionClass);
		bool operator==(fractionClass);
		bool operator!=(fractionClass);
	
		friend ostream& operator<<(ostream&, fractionClass&);
		friend istream& operator>>(istream&, fractionClass&);
};

int main()
{
	fractionClass frac1, frac2, frac3;
	bool looper = true;

	while(looper = true) // while loop that accepts fractions and gives the appropriate outputs
	{
		cout << "Input three fractions (A, B, and C): ";

		cin >> frac1;
		cin >> frac2;
		cin >> frac3;

		cout << "A: " << frac1;
		cout << "\tB: " << frac2;
		cout << "\tC: " << frac3 << endl;

		cout << "A+B: " << frac1+frac2 << "\t";
		cout << "A+C: " << frac1+frac3 << "\t";
		cout << "B+C: " << frac2+frac3 << "\t";
		cout << "A+B+C: " << frac1+frac2+frac3 << endl;

		cout << "A-B: " << frac1-frac2 << "\t";
		cout << "A-C: " << frac1-frac3 << "\t";
		cout << "B-C: " << frac2-frac3 << "\t";
		cout << "A-B-C: " << frac1-frac2-frac3 << endl;

		cout << "A*B: " << frac1*frac2 << "\t";
		cout << "A*C: " << frac1*frac3 << "\t";
		cout << "B*C: " << frac2*frac3 << "\t";
		cout << "A*B*C: " << frac1*frac2*frac3 << endl;

		cout << "A/B: " << frac1/frac2 << "\t";
		cout << "A/C: " << frac1/frac3 << "\t";
		cout << "B/C: " << frac2/frac3 << "\t";
		cout << "A/B/C: " << frac1/frac2/frac3 << endl;

		cout << "A>B: "; 
			if(frac1>frac2)
				cout<<"true\t";
			else
				cout<<"false\t";

		cout << "A>C: ";
			if(frac1>frac3)
				cout<<"true"<<endl;
			else
				cout<<"false"<<endl;

		cout << "A>=B: "; 
			if(frac1>=frac2)
				cout<<"true\t";
			else
				cout<<"false\t";

		cout << "A>=C: ";
			if(frac1>=frac3)
				cout<<"true"<< endl;
			else
				cout<<"false"<<endl;

		cout << "A<B: "; 
			if(frac1<frac2)
				cout<<"true\t";
			else
				cout<<"false\t";

		cout << "A<C: ";
			if(frac1<frac3)
				cout<<"true"<< endl;
			else
				cout<<"false"<<endl;

		cout << "A<=B: "; 
			if(frac1<=frac2)
				cout<<"true\t";
			else
				cout<<"false\t";

		cout << "A<=C: ";
			if(frac1<=frac3)
				cout<<"true"<< endl;
			else
				cout<<"false"<<endl;

		cout << "A==B: "; 
			if(frac1==frac2)
				cout<<"true\t";
			else
				cout<<"false\t";

		cout << "A==C: ";
			if(frac1==frac3)
				cout<<"true"<< endl;
			else
				cout<<"false"<<endl;

		cout << "A!=B: "; 
			if(frac1!=frac2)
				cout<<"true\t";
			else
				cout<<"false\t";

		cout << "A!=C: ";
			if(frac1!=frac3)
				cout<<"true"<< endl;
			else
				cout<<"false"<<endl;

	}

}

bool fractionClass::operator>(fractionClass compare) // overloaded > operator
{
	double temp, temp2;
	bool comparison = true;
	
	temp = static_cast<double>(this->numerator) / this->denominator;
	temp2 = static_cast<double>(compare.numerator) / compare.denominator;

	if(temp <= temp2 || this->denominator == 0)
		comparison = false;

	return comparison;
}

bool fractionClass::operator>=(fractionClass compare) // overloaded >= operator
{
	double temp, temp2;
	bool comparison = true;
	
	temp = static_cast<double>(this->numerator) / this->denominator;
	temp2 = static_cast<double>(compare.numerator) / compare.denominator;

	if(temp < temp2 || this->denominator == 0)
		comparison = false;

	return comparison;
}

bool fractionClass::operator<(fractionClass compare) // overloaded < operator
{
	double temp, temp2;
	bool comparison = true;
	
	temp = static_cast<double>(this->numerator) / this->denominator;
	temp2 = static_cast<double>(compare.numerator) / compare.denominator;

	if(temp >= temp2 || this->denominator == 0)
		comparison = false;

	return comparison;
}

bool fractionClass::operator<=(fractionClass compare) // overloaded <= operator
{
	double temp, temp2;
	bool comparison = true;
	
	temp = static_cast<double>(this->numerator) / this->denominator;
	temp2 = static_cast<double>(compare.numerator) / compare.denominator;

	if(temp > temp2 || this->denominator == 0)
		comparison = false;

	return comparison;
}

bool fractionClass::operator==(fractionClass compare) // overloaded == operator
{
	double temp, temp2;
	bool comparison = true;
	
	temp = static_cast<double>(this->numerator) / this->denominator;
	temp2 = static_cast<double>(compare.numerator) / compare.denominator;

	if(temp != temp2 || this->denominator == 0)
		comparison = false;

	return comparison;
}

bool fractionClass::operator!=(fractionClass compare) // overloaded != operator
{
	double temp, temp2;
	bool comparison = true;
	
	temp = static_cast<double>(this->numerator) / this->denominator;
	temp2 = static_cast<double>(compare.numerator) / compare.denominator;

	if(temp == temp2)
		comparison = false;

	return comparison;
}

fractionClass fractionClass::operator+(fractionClass secondNum) // overloaded addition operator
{
	fractionClass temp;
	
	temp.denominator = (this->denominator * secondNum.denominator);
	temp.numerator = ((this->numerator * secondNum.denominator) + (secondNum.numerator * this->denominator));

	return temp;
}

fractionClass fractionClass::operator-(fractionClass secondNum) // overloaded subtraction operator
{
	fractionClass temp;
	
	temp.denominator = (this->denominator * secondNum.denominator);
	temp.numerator = ((this->numerator * secondNum.denominator) - (secondNum.numerator * this->denominator));

	return temp;
}
fractionClass fractionClass::operator*(fractionClass secondNum) // overloaded multiplication operator
{
	fractionClass temp;
	
	temp.denominator = (this->denominator * secondNum.denominator);
	temp.numerator = (this->numerator * secondNum.numerator);

	return temp;
}
fractionClass fractionClass::operator/(fractionClass secondNum) // overloaded division operator
{
	fractionClass temp;
	
	temp.denominator = (this->denominator * secondNum.numerator);
	temp.numerator = (this->numerator * secondNum.denominator);

	if(temp.denominator == 0 || secondNum.denominator == 0) // establishes the case of the undefined fraction
		
		{
			temp.numerator = 0;
			temp.denominator = 0;
		}

	return temp;
}

ostream& operator<<(ostream& out, fractionClass& one) // overloaded outstream operator
{
	if(one.denominator == 0) // output if undefined
		out << "ND\t";
	else
		out<<one.numerator << "/" << one.denominator;

	return out;
}

istream& operator>>(istream& in, fractionClass& two) // overloaded instream operator
{
	in >> two.numerator;
	in.ignore(10,'/');
	in >> two.denominator;
	return in;
}

fractionClass::fractionClass(int num, int den) // constructor for fractionClass with two parameters
{numerator = num; denominator = den;}

fractionClass::fractionClass(int onlyNum) // contructor for fractionClass with one parameter
{numerator = onlyNum; denominator = 1;}