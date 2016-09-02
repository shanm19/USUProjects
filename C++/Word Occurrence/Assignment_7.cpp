//Shan Miller
//Assignment 7

#include "stdafx.h"
#include "Strings.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//a structure to store each word and their occurrence count
struct myStructure
{
	string word;
	int count;
};

//this function creates a vector with the occurrences of each string
void wordCount(string environment, vector<myStructure> &myVector)
{
	
	for(int i = 0; i < environment.length(); i++)
	{
		myStructure word;
		bool isWord = false;
		//finds the first acceptable character
		if(isalpha(environment[i]))
		{
			word.word += environment[i];
			isWord = true;
			i++;
			while(isWord)
		{
			//finds the whole word
			if(i < environment.size() && (isalnum(environment[i]) || environment[i] == '_'))
			{
				word.word += environment[i];
				word.count = 1;
				i++;
			}
			else
			{
				isWord = false;
			}
		}
		}
		//only executes if the string is longer than one character, as per the definition of a word
		if(word.word.length() > 1)
		{
			for(int o = 0; o < myVector.size(); o++)
			{
				if(myVector[o].word == word.word)
				{
					myVector[o].count++;
					isWord = true;
				}
			}
			//enters the information into the vector
			if(isWord == false)
			{
				myVector.push_back(word);
			}
		}
	}
}

//this is the function that takes the user input and searches for every instance of that string
int search(string toFind, string environmentString)
{
	bool isFound;
	int count = 0;
				for(int i = 0; i < environmentString.length() - toFind.length(); i++)
				{
					if(tolower(environmentString[i]) == toFind[0])
					{
						for(int o = 1; o < toFind.length(); o++)
						{
							if(tolower(environmentString[i+o]) == toFind[o])
							{
								isFound = true;
							}
							else
							{
								isFound = false;
								break;
							}
						}
						if(isFound)
							count++;
					}
				}
				//outputs the strings if the count is greater than 0
				if(count > 0)
					cout<<endl<<environmentString;
				return count;
}

//main
int main()
{
	extern char **environ;   // needed to access your execution environment
	
	vector<myStructure> myVector;

	int k = 0;

	string anything = " ";
	
	//displays the environ
	while (environ[k] != 0)
	{
		cout << environ[k] << endl;
		k++;
	}

	k = 0;

	//loads the parameters to the function wordCount
	while(environ[k] != 0)
	{
		wordCount(environ[k], myVector);
		k++;
	}

	int totalWordCount = 0;

	//this displays the total word count
	for(int i = 0; i < myVector.size(); i++)
		totalWordCount = totalWordCount + myVector[i].count;

	cout<<endl<<"Your total word count for this file is: "<<totalWordCount;

	cout<<endl<<"The least occurring words include: "<<endl;

	//this displays the least occurring words
	for(int i = 0; i < myVector.size(); i++)
	{
		if(myVector[i].count == 1)
			cout<<endl<<myVector[i].word;
	}
	cout<<endl<<"With just 1 occurrence.";
	
	int maxCompare = 0;
	int indexSaver = 0;

	//this displays the most occurring word(s)
	for(int i = 0; i < myVector.size(); i++)
	{
		if(myVector[i].count >= maxCompare)
		{
			maxCompare = myVector[i].count;
			indexSaver = i;
		}
	}
	cout<<endl<<"The most occurring word was: "<<myVector[indexSaver].word<<" with "<<myVector[indexSaver].count<<" as the count.";

	//this section reads in the user input and does a search
	
	while(anything != "end")
	{

		cout<<endl<<"Enter a string to search for up to 40 characters: ";

		getline(cin, anything);
		
		//determines if the input is within the acceptable length
		while(anything.length() >= 40 || anything.length() == 0)
		{
			cout<<endl<<"Invalid search, try again: ";
			getline(cin, anything);
		}
		
		//lowercases the input
		for(int i = 0; i < anything.length(); i++)
		{
			anything[i] = tolower(anything[i]);
		}
		
		k = 0;
		//this performs the search for the input
		if(anything != "end")
		{
			int counter = 0;

			while(environ[k] != 0)
			{
				counter = counter + search(anything, environ[k]);
				
				k++;
			}
			cout<<endl<<"Count of your query: "<<counter;
		}
		
	}
		return 0;
}