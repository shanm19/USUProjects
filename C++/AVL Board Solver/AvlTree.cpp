#include "AvlTree.h"

void AvlTree::makeEmpty( )
{
	makeEmpty( root );
}

bool AvlTree::isEmpty( ) 
{
	return root == NULL;
}

//Assign tree to rhs
AvlTree & AvlTree:: operator=(  AvlTree & rhs )
{
	if( this != &rhs )
	{
		makeEmpty( );
		root = clone( rhs.root );
	}
	return *this;
}

/**
* Internal method to get element field in node t.
* Return the element field or -1 if t is NULL.
*/

int AvlTree::elementAt( AvlNode *t ) 
{
	if( t == NULL )
		return -1;
	else
		return t->element;
}

bool AvlTree::tooHeavyLeft(AvlNode *t)
{   if (t==NULL) return false;
	return	(height( t->left ) - height( t->right ) == 2 );
}

bool AvlTree::tooHeavyRight(AvlNode *t)
{  if (t==NULL) return false;
	return	(height( t->right ) - height( t->left ) == 2 );
}

bool AvlTree::heavyRight(AvlNode *t)
{ if (t==NULL) return false;
	return	height( t->right) > height( t->left );
}
bool AvlTree::heavyLeft(AvlNode *t)
{  if (t==NULL) return false;
	return	(height( t->left ) > height( t->right ) );
}
/**
* Internal method to insert into a subtree.
* x is the item to insert.
* t is the node that roots the subtree.
*/


void AvlTree::insert(  int x, AvlNode * & t ) 
{
	if( t == NULL )
		t = new AvlNode( x, NULL, NULL );
	else if( x <= t->element )
	{
		insert( x, t->left );
		if( tooHeavyLeft(t))
			if( heavyLeft(t->left) )
				rotateWithLeftchild( t );
			else
				doubleWithLeftchild( t );
	}
	else 
	{
		insert( x, t->right );
		if(tooHeavyRight(t))
			if( heavyRight(t->right) )
				rotateWithRightchild( t );
			else
				doubleWithRightchild( t );
	}

	t->height = max( height( t->left ), height( t->right ) ) + 1;
}

/**
* Internal method to find the smallest item in a subtree t.
* Return node containing the smallest item.
*/

AvlNode *  AvlTree::findMin( AvlNode *t ) 
{
	if( t == NULL)
		return t;

	while( t->left != NULL )
		t = t->left;
	return t;
}

/**
* Internal method to find the largest item in a subtree t.
* Return node containing the largest item.
*/

AvlNode * AvlTree::findMax( AvlNode *t ) 
{
	if( t == NULL )
		return t;

	while( t->right != NULL )
		t = t->right;
	return t;
}

/**
* Internal method to find an item in a subtree.
* x is item to search for.
* t is the node that roots the tree.
* Return node containing the matched item.
*/

AvlNode * AvlTree::find(  int x, AvlNode *t ) 
{
	while( t != NULL )
		if( x < t->element )
			t = t->left;
		else if( t->element < x )
			t = t->right;
		else
			return t;    // Match

	return NULL;   // No match
}

/**
* Internal method to make subtree empty.
*/

void AvlTree::makeEmpty( AvlNode * & t ) 
{
	if( t != NULL )
	{
		makeEmpty( t->left );
		makeEmpty( t->right );
		delete t;
	}
	t = NULL;
}

/**
* Internal method to clone subtree.
*/

AvlNode *  AvlTree::clone( AvlNode * t ) 
{
	if( t == NULL )
		return NULL;
	else
		return new AvlNode( t->element, clone( t->left ),clone( t->right ), t->height );
}

/**
* Return the height of node t or -1 if NULL.
*/

int AvlTree::height( AvlNode *t ) 
{
	return t == NULL ? -1 : t->height;
}

/**
* Return maximum of lhs and rhs.
*/

int AvlTree::max( int lhs, int rhs ) 
{
	return lhs > rhs ? lhs : rhs;
}

/**
* Rotate binary tree node with left child.
* For AVL trees, this is a single rotation for case 1.
* Update heights, then set new root.
*/

void AvlTree::rotateWithLeftchild( AvlNode * & k2 ) 
{   assert(k2!=NULL && k2->left !=NULL);
	AvlNode *k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
	k1->height = max( height( k1->left ), k2->height ) + 1;
	k2 = k1;
}

/**
* Rotate binary tree node with right child.
* For AVL trees, this is a single rotation for case 4.
* Update heights, then set new root.
*/

void AvlTree::rotateWithRightchild( AvlNode * & k1 ) 
{   assert(k1!=NULL && k1->right !=NULL);
	AvlNode *k2 = k1->right;
	k1->right = k2->left;
	k2->left = k1;
	k1->height = max( height( k1->left ), height( k1->right ) ) + 1;
	k2->height = max( height( k2->right ), k1->height ) + 1;
	k1 = k2;
}

/**
* Double rotate binary tree node: first left child.
* with its right child; then node k3 with new left child.
* For AVL trees, this is a double rotation for case 2.
* Update heights, then set new root.
*/

void AvlTree::doubleWithLeftchild( AvlNode * & k3 ) 
{   assert(k3!=NULL);
	rotateWithRightchild( k3->left );
	rotateWithLeftchild( k3 );
}

/**
* Double rotate binary tree node: first right child.
* with its left child; then node k1 with new right child.
* For AVL trees, this is a double rotation for case 3.
* Update heights, then set new root.
*/

void AvlTree::doubleWithRightchild( AvlNode * & k1 ) 
{    assert(k1!=NULL);
	rotateWithLeftchild( k1->right );
	rotateWithRightchild( k1 );
}

/**
* Internal method to print a subtree in sorted order.
* t points to the node that roots the tree.
*/

void AvlTree::printTree( AvlNode *t,string indent ) 
{
	if( t != NULL )
	{
		printTree( t->right, indent+"  " );
		cout << indent << t->element << endl;
		printTree( t->left, indent+"  " );
	}
}
