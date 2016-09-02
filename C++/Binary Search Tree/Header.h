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

	void printShort(TreeNode<Etype> * t);
	void fall(TreeNode<Etype> * t);
	int successor(TreeNode<Etype> * t);
	TreeNode<Etype>* closestCommon(TreeNode<Etype> * a, TreeNode<Etype> * b);
	void flip(TreeNode<Etype> * t);

	void width(TreeNode<Etype> * t, int & height);

	void buildFromPreorder(TreeNode<Etype> * t, vector<int> preorder);
	bool isBST(TreeNode<Etype> * t);

	void printTree( TreeNode<Etype> * t ,string indent,int currDepth=0,int maxDepth=numeric_limits<int>::max());

	TreeNode<Etype> * findSmall(TreeNode<Etype> * t) const;
	TreeNode<Etype> * find(TreeNode<Etype> * curr, Etype value)const;
	int size( TreeNode<Etype> *t) const;


public:
	//a bunch of the wrapper functions for the various methods in the project

	bool isBST(){
		return isBST(root);
	}

	void buildFromPreorder(vector<int> preorder){
		buildFromPreorder(root, preorder);
	}

	int width(){

		int height = 1;
		width(root, height);
		return height;
	}

	void flip(){
		flip(root);
	}

	TreeNode<Etype>* closestCommon(int a, int b){
		return closestCommon(find(root, a), find(root, b));
	}

	int successor(int e){
		return successor(find(root, e));
	}

	void fall(){
		fall(root);
	}

	//prints the passed message and calls the key printing recursive function
	void printShort(string msg){
		cout<<endl<<msg<<endl;
		printShort(root);
	}
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
	{ 
		cout << endl<< msg << endl;
		printTree(root,"",0,depth); 
	}

	//Insert item x into the tree using BST ordering
	virtual int insert(Etype & x ) { return insert( x, root,NULL ); }

};


// return the number of nodes in the tree rooted at t
template <class Etype>
int BinarySearchTree<Etype>::size(TreeNode<Etype> *t) const
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
	{   cout << "inserting " << data << endl;
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

{
	if (curr==NULL) return NULL;

	if (curr->element == value)

		return curr;

	if (value < curr->element) return find (curr->left, value);

	return find(curr->right, value);

}

// Find the smallest node in the BST rooted at t
template <class Etype>
TreeNode<Etype> * BinarySearchTree<Etype>::findSmall(TreeNode<Etype> * t) const
{
	TreeNode<Etype>* s = t;
	for (; s->left!=NULL; s = s->left);
	return s;
}

//prints the keys in the tree in order
//O(n log n)
template <class Etype>
void BinarySearchTree<Etype>::printShort(TreeNode<Etype> * t){

	if (t==NULL) return; //base case
	printShort(t->left); //traverses and finds smallest
	if (t->parent !=NULL)
		cout << t->element << endl;
	else
		cout << t->element << endl;
	printShort(t->right); //traverses till the largest nodes

}

//removes all of the leaf nodes and removes them
//O(log n)
template <class Etype>
void BinarySearchTree<Etype>::fall(TreeNode<Etype> * t){
	if (t==NULL) return; //base case
	//finds the end of each subtree and deletes the node
	//after changing the parents' pointers to NULL
	if(t->right == NULL && t->left == NULL){
		if(t->parent->element > t->element)
			t->parent->left = NULL;
		if(t->parent->element < t->element)
			t->parent->right = NULL;
		delete t;
	}
	else
	{
		fall(t->left);
		fall(t->right);
	}
	
}

//finds the next number in the tree
//O(n^2)
template <class Etype>
int BinarySearchTree<Etype>::successor(TreeNode<Etype> * t){
	if(t==NULL) return -1;	//base case
	if(t->right == NULL){ //compares the elements in parent and child nodes
		while(t->parent->element < t->element){
			t = t->parent;
		}
		if(t->parent != NULL)
			t = t->parent;
		return t->element;
	}
	//search the other side for the closest number
	if(t->right != NULL){
		t = t->right;
		while(t->left != NULL){
			t = t->left;
		}
		return t->element;
	}
		
}

//finds the node that can lead to both numbers passed
//O(n)
template <class Etype>
TreeNode<Etype>* BinarySearchTree<Etype>::closestCommon(TreeNode<Etype> * a, TreeNode<Etype> * b){
	if(a == NULL || b == NULL) //base case
		return NULL;
	if(find(a, b->element) != NULL) //uses find to traverse list only from parent node
		return a;
	else
		closestCommon(a->parent, b);
	
}

//mirrors the tree
//O(log n)
template <class Etype>
void BinarySearchTree<Etype>::flip(TreeNode<Etype> * t){
	if(t!=NULL){ //temp node to flip the nodes on each side
		TreeNode<Etype> * temp;
		temp = t->left;
		t->left = t->right;
		t->right = temp;
	}
	//recursive call to traverse the list
	if(t->left!=NULL)
		flip(t->left);
	if(t->right!=NULL)
		flip(t->right);
}

//width function doesn't completely work
//I couldn't determine when to add to height
//O(n log n)
template <class Etype>
void BinarySearchTree<Etype>::width(TreeNode<Etype> * t, int & height){
	if (t==NULL) return;

	width(t->left, height);
	width(t->right, height);
	//meant to add to height only when it finds the longest depth of each subtree
	if(size(t->left) <= height)
		height++;
	if(size(t->right) <= height)
		height++;
}

//I didn't understand how this function is supposed to function
//differently from the insert function
//O(n log n)
template <class Etype>
void BinarySearchTree<Etype>::buildFromPreorder(TreeNode<Etype> * t, vector<int> preorder){
	//supposed to create a new node after each new number is read in
	/*
	int size = preorder.size();
	t->element = preorder[0];
	for(i=1; i<size; i++){
		if(preorder[i] < preorder[i-1])
			t->left = new TreeNode<Etype>(preorder[i],NULL,NULL, t);
		if(preorder[i] > preorder[i-1])
			t->right = new TreeNode<Etype>(preorder[i],NULL,NULL, t);//back to top, traverse
	}
	*/
}

//function to check if the tree is a binary search tree
//O(n)
template <class Etype>
bool BinarySearchTree<Etype>::isBST(TreeNode<Etype> * t){
    if(t->left == NULL && t->right == NULL) // traverses and sees if both pointers lead to NULL
        return true;
    else if ((t->left == NULL && t->right != NULL)||(t->right == NULL && t->left != NULL)) //the other cases that would lead to false
        return false;   
    else
        return ((isBST(t->left))?isBST(t->right):false);

}
