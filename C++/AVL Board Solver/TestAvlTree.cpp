
#include "AvlTree.h"
#include <fstream>
#include <iostream>
using namespace std;


int main( )
{
	ofstream ofs;
	ofs.open("prog3.txt");
	AvlTree t;
	int test[] = {11,1,3,5,7,9,11,2,4,8,11,30,20,15,18,3,3,11};
	//	int test[] = {1,3,5,7,9,11,2,4,8,30,20,15,18};
	int size = sizeof(test)/sizeof (int);
	int part1=9;
	for (int i = 0; i <part1; i++)
	{
		t.insert( test[i] );
		t.printTree( "**insert ");
	}

	t.remove(7);
	t.printTree( "**After removal of 7" );
	t.remove(9);
	t.printTree( "**After removal of 9" );
	for (int i = part1; i < size; i++)
	{
		t.insert( test[i] );
		t.printTree( "**insert" );
	}

	for (int i=0 ; i <3; i++) 
	    cout <<"Removed " <<  t.removeMin() << endl;
	t.insert(17);
	t.printTree("\nFinal Tree");
	return 0;
}
