// Shan Miller
// A01020750

#include "stdafx.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

//this is the function that will fill the vector of characters with only one of each letter from each of the three strings
void fillVector(string one, string two, string three, vector<char> &letters){

	bool found = false;

	//loop for the first string
	for(int i = 0; i < one.length(); i++){
		found = true;
		for(int c = 0; c < letters.size(); c++){

			if(letters[c] == one[i])
				found = false;
		}
		if(found)
			letters.push_back(one[i]);
	}
	//loop for the second string
	for(int i = 0; i < two.length(); i++){
		found = true;
		for(int c = 0; c < letters.size(); c++){

			if(letters[c] == two[i])
				found = false;
		}
		if(found)
			letters.push_back(two[i]);
	}
	//loop for the third string
	for(int i = 0; i < three.length(); i++){
		found = true;
		for(int c = 0; c < letters.size(); c++){

			if(letters[c] == three[i])
				found = false;
		}
		if(found)
			letters.push_back(three[i]);
	}
}
//boolean function that determines if the permutation works
bool permutationWorks(string one, string two, string three, vector<char> &letters, int p[], char mode){

	int oneInt = 0;
	int twoInt = 0;
	int threeInt = 0;
	//bool works;
	//create the integer for the first string
	for(int i = 0; i < one.length(); i++){
		for(int c = 0; c < letters.size(); c++){
			if(one[i] == letters[c]){
				oneInt *= 10;
				oneInt += p[c];
			}
		}
	}
	//create the integer for the second string
	for(int i = 0; i < two.length(); i++){
		for(int c = 0; c < letters.size(); c++){
			if(two[i] == letters[c]){
				twoInt *= 10;
				twoInt += p[c];
			}
		}
	}
	//create the integer for the third string
	for(int i = 0; i < three.length(); i++){
		for(int c = 0; c < letters.size(); c++){
			if(three[i] == letters[c]){
				threeInt *= 10;
				threeInt += p[c];
			}
		}
	}
	//checks the mode to determine which operator to use
	if(mode == '-'){
		if(oneInt - twoInt == threeInt){
			cout<<endl<<one<<": "<<oneInt;
			cout<<" - ";
			cout<<endl<<two<<": "<<twoInt;
			cout<<" = ";
			cout<<endl<<three<<": "<<threeInt;
			return true;
		}
		else
			return false;
		}
		if(mode == '+'){
			if(oneInt + twoInt == threeInt){
			cout<<endl<<one<<": "<<oneInt;
			cout<<" + ";
			cout<<endl<<two<<": "<<twoInt;
			cout<<" = ";
			cout<<endl<<three<<": "<<threeInt;
			return true;
		}
			else
				return false;
		}
		return false;
}

//this function will create all possible permutations for the strings and test to see if they're valid
void permute(bool unused[], int P[], int L, int N, vector<char> &letters, char mode, string one, string two, string three){
	if(L >= N){
		if(permutationWorks(one, two, three, letters, P, mode)){
			//to print the permutation that works
			cout<<endl<<"Permutation that works: ";
			for(int i = 0; i < N; i++){
				cout<<P[i];
			}
			cout<<endl;
		}
	}
	else{
		for(int i = 0; i < 10; i++){
			if(unused[i]){
				P[L]=i;
				unused[i] = false;
				//where the recursion takes place
				permute(unused, P, L+1, N, letters, mode, one, two, three);
				unused[i] = true;
			}
		}
	}
}

int main()
{
	vector<char> letters;

	bool unused[10] = {true, true, true, true, true, true, true, true, true, true};
	int P[7];
	int L = 0;
	int N = 7;

	char mode;
	string one, two, three;

	string file;
	ifstream fileIn;

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
	//reads in the mode and strings
	while (!fileIn.eof())
	{
		fileIn>>mode;
		fileIn>>one;
		fileIn>>two;
		fileIn>>three;
	}

	fileIn.close();

	fillVector(one, two, three, letters);

	//for(int i = 0; i < letters.size(); i++)
	//	cout<<letters[i];

	permute(unused, P, L, N, letters, mode, one, two, three);
}

