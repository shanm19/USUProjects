//Shan Miller
//A01020750
//Project 2

#include "Header.h"
#include <ctime>
using namespace std;

void printVector(string msg,vector<int> t)
{
	cout << endl << msg;
	for (int i=0; i < (int) t.size(); i++)
		cout << t[i] << " " ;
	cout << endl;

}

int main()
{
	const int COUNT = 30;  // size of tree
	const int MAXELE = 100;
	BinarySearchTree<int> tree1(0,MAXELE);
	BinarySearchTree<int> tree2(0,MAXELE);
	BinarySearchTree<int> tree3(0,MAXELE);
	BinarySearchTree<int> tree4(0,MAXELE);
	BinarySearchTree<int> tree5(0,MAXELE);

	int values[] = {10,25,5,8,6,1,30,50,22,11,19,42,3};
	int size = sizeof values/sizeof(int);

	for (int i=0; i < size; i++){
		tree1.insert(values[i]);
		tree3.insert(values[i]);
	}
	tree1.printTree("Tree 1");

	srand((int) time(0));
	for (int i = 0; i <COUNT; i++){
		int t = rand()%MAXELE;
		tree2.insert(t); 
	}
	tree2.printTree("Random tree");
 
	tree2.printShort("\nList of Keys: ");
	

	tree2.fall();

	tree2.printTree("\n Tree with Leaves Removed");


	int e = tree2.getSmall();
	cout << "starting at " << e << endl;
	for (int i = 0; i < 10; i++)
	{  e = tree2.successor(e);
	cout <<  "The next sucessor is " << e << endl;
	}
	

	tree3.printTree("Tree 3");
	
	int a=1;
	int b =50;
	TreeNode<int> * ans = tree3.closestCommon(a,b);
	if (ans==NULL)
		cout << a << " and " << b << " have no common ancestor"<<endl;
	else 
		cout << a << " and " << b << " have ancestor: "<< ans->element<< endl;
	a=19;
	b =22; 
	ans = tree3.closestCommon(a,b);
	if  (ans==NULL)
		cout << a << " and " << b << " have no common ancestor"<<endl;
	else 
		cout << a << " and " << b << " have ancestor: "<< ans->element<< endl;  
	a=11;
	b = 30;
	ans = tree3.closestCommon(a,b);
	if  (ans==NULL)
		cout << a << " and " << b << " have no common ancestor"<<endl;
	else 
		cout << a << " and " << b << " have ancestor: "<< ans->element<< endl;
	a=15;
	b = 30;
	ans = tree3.closestCommon(a,b);
	if  (ans==NULL)
		cout << a << " and " << b << " have no common ancestor"<<endl;
	else 
		cout << a << " and " << b << " have ancestor: "<< ans->element<< endl;
	
	tree1.printTree("tree1");
	cout << "The width of the tree1 is " << tree1.width() << endl;
	tree2.printTree("Tree2");
	cout << "The width of the tree2 is " << tree2.width() << endl;
	
	tree2.flip();
	tree2.printTree("Flipped Tree 2");
	/*
	int preOrderI[] = {8,3,1,6,4,7,10,14,13};
	vector<int> preOrder (preOrderI,preOrderI + sizeof(preOrderI)/sizeof(int));
	printVector("Preorder ", preOrder);
	tree4.buildFromPreorder(preOrder);

	tree4.printTree("tree from Preorder");
	int perfectBalanceI[] = {8,3,1,6,4,7,10,14,13,0,11,21};

	vector<int> perfectBal (perfectBalanceI,perfectBalanceI + sizeof(perfectBalanceI)/sizeof(int));
	sort(perfectBal.begin(), perfectBal.end());
	printVector("Balance Keys", perfectBal);
	tree4.perfectBalance(perfectBal);
	tree4.printTree("Perfect Balance");

	if (tree4.isBST()) 
		cout << "Tree is a BST\n";
	else
		cout << "Tree is NOT a BST\n";

	vector<int> unordered (perfectBalanceI,perfectBalanceI + sizeof(perfectBalanceI)/sizeof(int));
	tree4.perfectBalance(unordered);
	printVector("Keys", unordered);
	tree4.printTree("Unordered");
	if (tree4.isBST()) 
		cout << "Tree is a BST\n";
	else
		cout << "Tree is NOT a BST\n";

	int nodesI[] = {3,5,12,10,11,13,16};
	vector<int> nodes (nodesI,nodesI + sizeof(nodesI)/sizeof(int));
	printVector("Keys", nodes);
	tree4.perfectBalance(nodes);
	tree4.printTree("tree from  Keys");
	if (tree4.isBST()) 
		cout << "Tree is a BST\n";
	else
		cout << "Tree is NOT a BST\n";

	for (int i = 0; i <6; i++){
		int t = rand()%MAXELE;
		tree5.insert(t); 
	}
	tree5.printTree("Tree 5");
	cout << "Find max complete";
	tree5.printMaxCompleteSubtree();
	for (int i = 0; i <COUNT; i++){
		int t = rand()%MAXELE;
		tree5.insert(t); 
	}
	tree5.printTree("Extended Tree 5");
	cout << "Find max complete";
	tree5.printMaxCompleteSubtree();
*/
	int stop;
	cin>>stop;
}
