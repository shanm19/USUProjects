//Shan Miller
//A01020750
//Project 6: Percolation

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "UnionFind.h"
#include "Pair.h"
#include <fstream>
using namespace std;
void part_one(){	
	DisjSets<Pair<int> > mySet(30);
	mySet.unionSets(0,0);
	mySet.unionSets(0,0); //tests that the same union isn't done twice
	mySet.unionSets(3,8);
	mySet.unionSets(3,9); //second union on 3 maintains the union to highest size
	mySet.unionSets(4,1); //tests if higher number is on the left
	mySet.unionSets(0,9); //tests the higher size remains the root
	mySet.unionSets(0,7);
	mySet.unionSets(5,1);
	mySet.unionSets(1,7); //4-1 union, maintains rank
	//cout<<mySet;
	mySet.find(5); //path compresses 5 to three, since its parent is currently 4
	//cout<<mySet;

	//creates a set larger than the 3 tree
	mySet.unionSets(28,27);
	mySet.unionSets(26,25);
	mySet.unionSets(24,23);
	mySet.unionSets(22,21);
	mySet.unionSets(20,19);
	mySet.unionSets(18,17);

	mySet.unionSets(17,27);
	mySet.unionSets(25,24);
	mySet.unionSets(22,20);

	mySet.unionSets(17,23);
	mySet.unionSets(25,20);

	mySet.find(19); //compresses, maintains rank
	mySet.unionSets(16,19);
	mySet.unionSets(14,16);
	//connects 3-tree to the 18-tree, 18 is new root, it has a higher rank
	mySet.unionSets(3,19);

	cout<<mySet;
}

int to_i(int x, int y, int SIZE){
	return (SIZE)*x + y;
}
/*
int to_x(int i, int SIZE_Y){
	return i/SIZE_Y;
}
int to_y(int i, int SIZE_X){
	i%SIZE_X;
}
*/
//function to see if something on the bottom row is connected to the top row
bool check_perc(DisjSets<Pair<int> > &game, int SIZE_X, int SIZE_Y){
	int i = to_i(SIZE_X-1,0,SIZE_Y);
	//game.find(i); //perform path compression
	if(game.rootFind(i) == 0) return true;
	//if(game.s[i].ParentID == 0) return true;
	return false;
}

void printMatrix(bool (&m)[22][20], int SIZE_X, int SIZE_Y, ofstream &out){
	//loop to create the 20x20 matrix
	for(int i = 1; i <= SIZE_X-1; i++){
		
		if(i == 1 || i == (SIZE_X-1)) { //prints the dummy rows just so they can be seen
			out<<' ';
			for(int print = 0; print < SIZE_Y; print++) out<<'-';
			out<<endl;
		}
		if(i == SIZE_X-1) break;
		for(int j = 0; j <= SIZE_Y; j++){
			if(j == 0){
				out<<'|';
				if(m[i][j]) out<<'X';
				else out<<' ';
			}
			else if(j == SIZE_Y) out<<'|'<<endl;
			else{
				if(m[i][j]) out<<'X';
				else out<<' ';
			}
		}
	}
}

//finds all neighbors and connects them together
void adjacency(bool (&m)[22][20], int SIZE_X, int SIZE_Y, int x, int y, DisjSets<Pair<int> > &game, ofstream &out){
	int i = to_i(x, y, SIZE_Y);
	int j;

	if(x-1 >= 0){
		if(!m[x-1][y]) {
			j = i - SIZE_Y;
			if(j > 0){
				game.unionSets(i, j);
				//game.find(i);
				//game.find(j);
				//printMatrix(m, SIZE_X, SIZE_Y, out);
				
				//game.find(j);
				/*out<<"UNION CHECK"<<endl;
				out<<"#: "<<i<<endl;
				out<<game.s[i]<<endl;
				out<<"#: "<<j<<endl;
				out<<game.s[j]<<endl;*/
			}
		}
	}
	if(x+1 <= SIZE_X){
		if(!m[x+1][y]){
			j = i + SIZE_Y;
			if(j < SIZE_X*SIZE_Y){
				game.unionSets(i, j);
				//game.find(i);
				//printMatrix(m, SIZE_X, SIZE_Y, out);
				//game.find(j);
				/*out<<"UNION CHECK"<<endl;
				out<<"#: "<<i<<endl;
				out<<game.s[i]<<endl;
				out<<"#: "<<j<<endl;
				out<<game.s[j]<<endl;*/
			}
		}
	}
	if(y-1 >= 0){
		if(!m[x][y-1]){
			j = i - 1;
			if(j > 0){
				game.unionSets(i, j);
				//game.find(i);
				//printMatrix(m, SIZE_X, SIZE_Y, out);
				//game.find(j);
				/*out<<"UNION CHECK"<<endl;
				out<<"#: "<<i<<endl;
				out<<game.s[i]<<endl;
				out<<"#: "<<j<<endl;
				out<<game.s[j]<<endl;*/
			}
		}
	}
	if(y+1 <= SIZE_Y){
		if(!m[x][y+1]){
			j = i + 1;
			if(j < SIZE_X*SIZE_Y){
				game.unionSets(i, j);
				//game.find(i);
				//printMatrix(m, SIZE_X, SIZE_Y, out);
				//game.find(j);
				/*out<<"UNION CHECK"<<endl;
				out<<"#: "<<i<<endl;
				out<<game.s[i]<<endl;
				out<<"#: "<<j<<endl;
				out<<game.s[j]<<endl;*/
			}
		}
	}
	//game.find(i);
}

//this function randomly removes X's from the graph until it's empty
void remove(){
	ofstream myfile;
	myfile.open("remove.txt");
	int a, b;
	static const int SIZE_X = 22;
	static const int SIZE_Y = 20;
	static const int SIZE_Z = SIZE_X * SIZE_Y;
	bool percolates = false;
	int x, y;
	srand( (unsigned int)time(NULL)); //generate a random seed based on time
	bool closed[SIZE_X][SIZE_Y];
	int ct = 0;
	float threshold;
	DisjSets<Pair<int> > perc_game(SIZE_Z);
	
	int t = to_i(SIZE_X-1,0,SIZE_Y);

	perc_game.s[0].Rank = 500; 
	perc_game.s[t].Rank = 450;

	//create the dummy rows all set to false
	for(int k = 0; k < SIZE_Y; k++){
		closed[0][k] = false;
		closed[SIZE_X-1][k] = false;
		a = to_i(0, k, SIZE_Y);
		b = to_i(SIZE_X-1, k, SIZE_Y);
		//cout<<"A: "<<a<<" B: "<<b<<endl;
		//union top row together
		if(a > 0){
			perc_game.unionSets(a-1, a);
			perc_game.find(a);
		}
		//union bottom row together
		if(b > SIZE_Y*(SIZE_X-1)) {
			perc_game.unionSets(b-1, b);
			perc_game.find(b);
		}
	}
	//myfile<<perc_game; //adding this proves that the dummy rows all connected
	
	//cout<<"Rank: "<<perc_game.s[0].R();
	//perc_game.printContents();
	
	//this is where it randomly removes elements
	do{
		if(ct > SIZE_Z) break;

		x = rand() % SIZE_X;
		y = rand() % SIZE_Y;
		if(x == 0) x++;
		else if(x == SIZE_X-1) x--;

		if(closed[x][y]){
			closed[x][y] = false;
			ct++;

			//checks to connect all adjacent open slots
			adjacency(closed, SIZE_X, SIZE_Y, x, y, perc_game, myfile); 

			//checks that the top and bottom connect
			percolates = check_perc(perc_game, SIZE_X, SIZE_Y);
			//perc_game.printContents();
			//printMatrix(closed, SIZE_X, SIZE_Y);
			if(ct%50 == 0 && !percolates) {
				//myfile<<perc_game;
				myfile<<"Current count: "<<ct<<endl;
				threshold = static_cast<float>(ct)/(SIZE_Z-SIZE_Y*2);
				myfile<<"Current ratio: "<<threshold<<endl;
				printMatrix(closed, SIZE_X, SIZE_Y, myfile);
				myfile<<endl;
			}
			if(percolates){
				myfile<<perc_game;
				myfile<<"It percolated!"<<endl;
				myfile<<"Current count: "<<ct<<endl;
				threshold = static_cast<float>(ct)/(SIZE_Z-SIZE_Y*2);
				myfile<<"The percolation threshold is: "<<threshold<<endl;
				printMatrix(closed, SIZE_X, SIZE_Y, myfile);
				myfile<<endl;
				
			}
		}
		
	//stops running when either everything has been opened or if it percolates
	}while(!percolates  && ct < (SIZE_Z));
	myfile.close();
}



int main(){

	//part 1
	part_one();

	//part 2
	remove();

	return 0;
}