// Shan Miller
// A01020750
// Assignment 12
/*
#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	string file;
	ifstream fileIn;
	int num1, num2;
	char oper;

	cout<<"Input file name or directory: ";
	cin>>file;

	fileIn.open(file);
	//test if file is present
	while (!fileIn)
	{
		cout<<"Error, please try again: \n";
		cin>>file;
		fileIn.open(file);
	}
	//reads in the file
	while (!fileIn.eof())
	{
		fileIn>>num1;
		fileIn>>num2;
		fileIn>>oper;

	}

	fileIn.close();



}
*/
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <limits>
#include <string>
using namespace std;
 
char fileOperations(stack<int>& myStack);
ifstream inFile;

int main()
{

	string file;
	char oper;
	int result;
	stack<int> myStack;
	int num1, num2;

	cout<<"Input file name or directory: ";
	cin>>file;

	inFile.open(file);
	//test if file is present
	while (!inFile)
	{
		cout<<"Error, please try again: \n";
		cin>>file;
		inFile.open(file);
	}
	
	//reads in the file
	oper = fileOperations(myStack);
	while (oper!='&')
	{
		//set the two operands from the stack
		num2 = myStack.top();
		myStack.pop();
		num1 = myStack.top();
		myStack.pop();
		//checks the operator and reacts accordingly
		switch(oper)
          {
                  case '+': result=num1 + num2;
                  break;
                  case '-': result=num1 - num2;
                  break;
                  case '*': result=num1 * num2;
                  break;
				  //for the case that it is being divided by 0
                  case '/': 
						  if(num2 == 0) {
							  result = NULL;
							  cout << "Cannot divide by 0." << endl;
						  }
						  else
							  result = num1 / num2;
                  break;
				  case '%': 
					  if(num2 == 0) {
							  result = NULL;
							  cout << "Cannot mod by 0." << endl;
						  }
						  else
							  result = num1 % num2;
				  break;
				  case '\\': result=num2 * -1;
					  myStack.push(num1);
					  break;

		}
		myStack.push(result);
		//this will print all the calculations
		if(result != NULL)
			cout<< num1 << ' ' << oper << ' ' << num2 << " = " << result << endl;

		oper = fileOperations(myStack);

	}

	inFile.close();

}
//the function to create the stack of integers and get the operator
//it also returns '&' if it is next in line to terminate the program
char fileOperations(stack<int>& myStack){
	int temp1, temp2;
	char oper;
	
	if(inFile.peek()=='&')
		return '&';
	else
	{
		inFile>>temp1;
		inFile>>temp2;
		inFile>>open;
		myStack.push(temp1);
		myStack.push(temp2);
		inFile.get();

		return open;
	}

}