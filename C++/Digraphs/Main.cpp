//Shan Miller
//A01020750
//Project 7

#include <iostream>
#include "Graph.h"
using namespace std;

int main(){

	bool select = false;
	int option;

	do{
		cout<<"Which digraph do you want?"<<endl;
		cout<<"1: digraph1"<<endl;
		cout<<"2: digraph2"<<endl;
		cout<<"3: digraph3"<<endl;
		cout<<"0: quit"<<endl;

		cin>>option;

		cout<<endl<<endl;

		if(option >= 0 && option <= 3) select = true;

	}while(!select);

	string digraph;

	switch(option){
	case 0:
		break;
	case 1:
		digraph = "digraph1.txt";
		break;
	case 2:
		digraph = "digraph2.txt";
		break;
	case 3:
		digraph = "digraph3.txt";
		break;
	default:
		break;
	}

	Graph myGraph;
	vector<int> vec1, vec2;
	int read;

	if(option != 0){
		myGraph.read_file(digraph);
		myGraph.list_print();

		int one, two;
		cout<<"For which two numbers do you want the shortest common ancestor? ";
		cin>>one>>two;
		myGraph.SCA(one, two,true);

		cout<<endl<<"---Two subsets---"<<endl;

		int subset1, subset2;

		cout<<"How many nodes are in subset A? ";
		cin>>subset1;
		cout<<"Enter those node numbers: ";

		for(int i = 0; i < subset1; i++) {
			cin>>read;
			vec1.push_back(read);
		}

		cout<<"How many nodes are in subset B? ";
		cin>>subset2;
		cout<<"Enter those node numbers: ";

		for(int j = 0; j < subset2; j++){
			cin>>read;
			vec2.push_back(read);
		}
		cout<<endl;
		cout<<"Comparing subset A node: "<<vec1[0]<<endl;
		cout<<"Comparing subset B node: "<<vec2[0]<<endl;
		int length = myGraph.SCA(vec1[0], vec2[0], true);
		int temp = length;
		int ssA = 0;
		int ssB = 0;

		for(int i = 0; i < subset1; i++){
			for(int j = 0; j < subset2; j++){
				
				if(!(i==0&&j==0)){
					cout<<"Comparing subset A node: "<<vec1[i]<<endl;
					cout<<"Comparing subset B node: "<<vec2[j]<<endl;
					temp = myGraph.SCA(vec1[i], vec2[j], true);
				}
				
				if(length > temp){
					//cout<<"Comparing subset A node: "<<vec1[i]<<endl;
					//cout<<"Comparing subset B node: "<<vec2[j]<<endl;
					length =temp;
					cout<<endl;
					ssA = i;
					ssB = j;
				}
				
			}
		}
		cout<<endl;
		cout<<"The shortest ancestral path between the subsets is: "<<endl;
		cout<<"Subset A: "<<vec1[ssA]<<endl;
		cout<<"Subset B: "<<vec2[ssB]<<endl;

		vector<int> outList;

		int numi;

		cout<<"How many numbers are you testing for the outcast?"<<endl;

		cin>>numi;
		cout<<"Enter those numbers: ";
		for(int i = 0; i < numi; i++){
			cin>>read;
			outList.push_back(read);
		}

		cout<<"The outcast of the graph is: "<<myGraph.outCast(numi, outList)<<endl;

	}


	return 0;
}