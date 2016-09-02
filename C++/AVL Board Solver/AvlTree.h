//#include "dsexceptions.h"
#include <string>
#include <iostream>
#include <iomanip>
#include "assert.h"

using namespace std;
class AvlNode
{ public:
int element;
AvlNode   *left;
AvlNode   *right;
int       height;

AvlNode(int  theElement, AvlNode *lt, AvlNode *rt, int h = 0 )
	: element( theElement ), left( lt ), right( rt ), height( h ) { }
};



class AvlTree
{
public:
	AvlTree( ){root=NULL; };
	~AvlTree( ) {   makeEmpty( );};

	int  findMin( )  { return elementAt( findMin( root ) );}
	int  findMax( ) { return elementAt( findMax( root ) );};
	AvlNode* find(  int  x ) {AvlNode * res= find(x,root);  if (res==NULL) return NULL; return res;};
	bool isEmpty( ) ;
	void printTree(string msg ){ cout << msg << endl; printTree(root, ""); };

	void makeEmpty( );
	void insert(  int  x ) {  insert( x, root );}

	AvlTree & operator=(  AvlTree & rhs );
	bool remove(int x) {return remove(root,x);};

	bool tooHeavyLeft(AvlNode *t);
    bool tooHeavyRight(AvlNode *t);
	bool heavyRight(AvlNode *t);
    bool heavyLeft(AvlNode *t);

	int removeMin() {return removeMin(root);};  //WARNING not written
private:
	bool remove(AvlNode *& t, int word) {return true;};  //WARNING not written
	int removeMin(AvlNode *& t) {return 0;};  //WARNING not written
	AvlNode *root;
	int  elementAt( AvlNode *t ) ;

	void insert(  int x, AvlNode * & t ) ;
	AvlNode * findMin( AvlNode *t ) ;
	AvlNode * findMax( AvlNode *t ) ;
	AvlNode * find(  int x, AvlNode *t ) ;
	void makeEmpty( AvlNode * & t ) ;
	void printTree( AvlNode *t,string indent ) ;
	AvlNode * clone( AvlNode *t ) ;
	
	// Avl manipulations
	int height( AvlNode *t ) ;
	int max( int lhs, int rhs ) ;
	void rotateWithLeftchild( AvlNode * & k2 ) ;
	void rotateWithRightchild( AvlNode * & k1 ) ;
	void doubleWithLeftchild( AvlNode * & k3 ) ;
	void doubleWithRightchild( AvlNode * & k1 ) ;
};

