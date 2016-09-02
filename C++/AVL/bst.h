#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

template <class Etype>
class TreeNode
{
public:
	Etype element;  // value in node
	TreeNode *left;  // left child
	TreeNode *right; // right child
	TreeNode *parent; // parent of node
	TreeNode( Etype e = 0, TreeNode *l = NULL, TreeNode *r = NULL, TreeNode *p = NULL ) : 
	element( e ), left( l ), right( r ),parent(p) { }
};

template <class Etype>
class BinarySearchTree
{
protected:
	TreeNode<Etype> *root;  // root of tree
	Etype LOW;   // Smallest possible value stored in tree
	Etype HIGH;  // Largest possible value stored in tree
	bool insert(Etype & x, TreeNode<Etype> * & t,TreeNode<Etype>*  p);

	void printTree( TreeNode<Etype> * t ,string indent,int currDepth=0,int maxDepth=numeric_limits<int>::max());

	TreeNode<Etype> * findSmall(TreeNode<Etype> * t) const;
	TreeNode<Etype> * find(TreeNode<Etype> * curr, Etype value)const;
	int size( TreeNode<Etype> *t) const;

public:
	int getSmall() { 
		TreeNode <Etype> *t = findSmall(root);
		if (t==NULL) return 0;
		return t->element;
	}

	BinarySearchTree(Etype low=0, Etype high=0 ) : root( NULL ) {
		LOW = low;
		HIGH = high;
	}

	//Print the tree preceeded by the "msg".
	// Print the tree to depth "depth"
	// Print the whole tree if no depth is specified
	void  printTree(string msg,int depth=numeric_limits<int>::max()) 
	{ cout << endl<< msg << endl;
	printTree( root,"",0,depth); 
	}

	//Insert item x into the tree using BST ordering
	virtual int insert(Etype & x ) { return insert( x, root,NULL ); }

};


// return the number of nodes in the tree rooted at t
template <class Etype>
int BinarySearchTree<Etype>::size( TreeNode<Etype> *t) const
{  if (t == NULL) return 0;
return (1+size(t->left) + size(t->right));
}


//Print the contents of tree t
// Indent the tree bby the string "indent"
// Print the tree to a depth of "depth" given "currdepth" is the depth of t
template <class Etype>
void BinarySearchTree<Etype>:: printTree( TreeNode<Etype> *t,string indent,int currdepth, int depth) 
{  
	if (t==NULL || currdepth>depth) return;
	printTree(t->right, indent+"  ",currdepth+1,depth);
	if (t->parent !=NULL)
		cout << indent << t->element << "(" << t->parent->element << ")" << endl;
	else
		cout << indent << t->element << "( no parent)" << endl;
	printTree(t->left, indent+"  ",currdepth+1,depth);
}

// insert inserts data into the tree rooted at t
// parent is the parent of t
// Returns true if insertion is successful  (duplicates are not allowed)
// Code is O(log n) for a balanced tree as each level is accessed once
template <class Etype>
bool BinarySearchTree<Etype>::insert(Etype & data, TreeNode<Etype> * & t, TreeNode<Etype> *  parent )
{
	if( t == NULL )
	{  // cout << "inserting " << data << endl;
		t = new TreeNode<Etype>( data,NULL,NULL, parent );
		if (t == NULL) return false;
		return true;
	}
	if (data==t->element) return false;  // ignore duplicates
	if( data < t->element ) return insert( data, t->left,t );
	return insert( data, t->right,t );
}
// find seaches for data in the tree rooted at curr
// Returns the node if the find is successful, NULL otherwise
// Code is O(log n) for a balanced tree as each level is accessed once
template <class Etype>
TreeNode<Etype> * BinarySearchTree<Etype>::find(TreeNode<Etype> * curr, Etype value) const

{ if (curr==NULL) return NULL;

if (curr->element == value)

	return curr;

if (value < curr->element) return find (curr->left, value);

return find(curr->right, value);

}

// FInd the smallest node in the BST rooted at t
template <class Etype>
TreeNode<Etype> * BinarySearchTree<Etype>::findSmall(TreeNode<Etype> * t) const
{TreeNode<Etype>* s = t;
for (; s->left!=NULL; s = s->left)
	;
return s;
}


