// Shan Miller
// A01020750

#include "stdafx.h"
#include <iostream>

using namespace std;

struct node{
	int data;
	node* next;
	node(int);
};

class linkedList{

public: void add(int); //done
		bool isMember(int); //done
		void remove(int); //done
		linkedList(); //done
		void reverse();
		void printList(); //done
		
private: node *head;
		 void add(int, node*);
		 void printList(node*);
		 void remove(int, node*);
		 bool isMember(int, node*);
		 void reverse(node*&);

};

//helper function for adding an int
void linkedList::add(int x){
	add(x, head);
}
//recursive function for adding an int
void linkedList::add(int x, node* noder){
	
	if(head == NULL){
		head  = new node(x);
	}
	else if(noder->next == NULL)
	{
		noder->next = new node(x);
	}
	else
	{
		add(x, noder->next);
	}
}

//helper function for printing
void linkedList::printList(){
	cout<<endl;
	printList(head);
}
//recursive function for printing
void linkedList::printList(node* noder){
	if(noder == NULL){
		cout<<endl<<"End of list!";
	}
	else if(noder != NULL)
	{
		cout<<noder->data<<" ";
		printList(noder->next);
	}
}

//helper function for finding a member
bool linkedList::isMember(int x){
	bool finder = false;
	finder = isMember(x, head);
	return finder;
}
//recursive function for finding a member
bool linkedList::isMember(int x, node* noder){
	if(noder == NULL){
		return false;
	}
	else if(noder->data == x)
	{
		return true;
	}
	else
		isMember(x, noder->next);
}

//helper function for removing a specific int
void linkedList::remove(int x){
	try{
	remove(x, head);
	}
	catch(int e){
		cout<<endl<<"Error, number to be removed was not found!";
	}
}
//recursive function for removing a specific int
void linkedList::remove(int x, node* noder){
	node* temp;
		if(head == NULL){
			throw 1;
		}
		else if(head->data == x){
			node* temp = head;
			head = head->next;
			delete temp;
		}
		else if(noder->next == NULL)
			throw 1;
		else if(noder->next->data == x){
			temp = noder->next;
			noder->next = temp->next;
			delete temp;
		}
		else
			remove(x, noder->next);
	
}
//helper function for reversing the nodes

void linkedList::reverse(){
	node* tempHead = NULL;
	reverse(tempHead);
	head = tempHead;
}
//recursive function for reversing the nodes
void linkedList::reverse(node* &tempHead){

	if(head == NULL){
		return;
	}
		
	else {
		node* temp = new node(head->data);
		temp->next = tempHead;
		tempHead = temp;
		temp = head;
		head = head->next;
		delete temp;
		reverse(tempHead);
	}
}
//default constructor
linkedList::linkedList(){
	head = NULL;
}
node::node(int x){
	data = x;
	next = NULL;
}

int main()
{
	linkedList test;
	bool finder;
	int stop;

	test.add(5);
	test.add(7);
	test.add(10);
	test.add(23);
	test.add(14);
	test.add(8);
	test.add(-2);
	test.printList();
	
	test.remove(10);
	test.remove(-2);
	test.remove(6);
	test.printList();
	
	finder = test.isMember(23);
	if(finder)
		cout<<endl<<"23 is a member!";
	else
		cout<<endl<<"23 is not a member!";

	test.reverse();

	finder = test.isMember(7);
	if(finder)
		cout<<endl<<"7 is a member!";
	else
		cout<<endl<<"7 is not a member!";
	finder = test.isMember(5);
	if(finder)
		cout<<endl<<"5 is a member!";
	else
		cout<<endl<<"5 is not a member!";

	test.printList();
	cin>>stop;
}

