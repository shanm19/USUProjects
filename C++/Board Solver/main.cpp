#include "board.h"
#include "stdlib.h"
#include <assert.h>
#include <iostream>

using namespace std;
//the structure of the node to contain the board and add it to the linked list
struct node{
	Board key_value;
	//int state;
	node* next;
	node(int);
	int previousDirection;
public:
	void printBoard() //function to print each board
	{
		cout<<key_value.toString();
	}
	node(){
		this->next=NULL;
		this->previousDirection=-1; //originally to be used to track which of the directions have already been taken for the recursive call
		//but I didn't do it recursively in the end
		//this->state=-1;
	}
};
//the linked list class to create some recursive and other functions to be used to swap boards and add them to the list
class linkedList{

public: void add(node);
		linkedList();
		void printList(Board winningBoard);
		node *head;
		
		
private: 
		 void add(node, node*);
		 void printList(node*, Board winningBoard);

};
//default constructor for the list
linkedList::linkedList(){
	head = NULL;
}

//helper function for adding a board
void linkedList::add(node newBoard){
	add(newBoard, head);
}
//recursive function for adding a board
void linkedList::add(node newBoard, node* nod){
	
	if(head == NULL){
		head  = &newBoard;
	}
	else if(nod->next == NULL)
	{
		nod->next = &newBoard;
	}
	else
	{
		add(newBoard, nod->next);
	}
}

//helper function for printing
void linkedList::printList(Board winningBoard){
	cout<<endl;
	printList(head, winningBoard);
}
//recursive function for printing the boards
void linkedList::printList(node* noder, Board winningBoard){
	if(noder == NULL || noder->key_value==winningBoard){
		cout<<endl<<"Winning Board"<<endl;
		noder->printBoard();
	}
	else
	{
		noder->printBoard();
		printList(noder->next, winningBoard);
	}
}

int main()
{
	linkedList test;

	Board winningBoard, testBoard;

	Board board1;
	node node1;
	//construction of the first test board
	board1.board[0][0]=1;
	board1.board[0][1]=3;
	board1.board[0][2]=4;
	board1.board[1][0]=2;
	board1.board[1][1]=5;
	board1.board[1][2]=6;
	board1.board[2][0]=7;
	board1.board[2][1]=0;
	board1.board[2][2]=8;
	node1.key_value=board1;
	cout<<"Board 1"<<endl<<board1.toString();

	Board board2;
	node node2;
	//construction of the second test board
	board2.board[0][0]=1;
	board2.board[0][1]=2;
	board2.board[0][2]=3;
	board2.board[1][0]=0;
	board2.board[1][1]=4;
	board2.board[1][2]=5;
	board2.board[2][0]=7;
	board2.board[2][1]=8;
	board2.board[2][2]=6;
	node2.key_value=board2;
	cout<<"Board 2"<<endl<<board2.toString();

	Board board3;
	node node3;
	//construction of the third test board
	board3.board[0][0]=1;
	board3.board[0][1]=2;
	board3.board[0][2]=3;
	board3.board[1][0]=7;
	board3.board[1][1]=4;
	board3.board[1][2]=5;
	board3.board[2][0]=8;
	board3.board[2][1]=0;
	board3.board[2][2]=6;
	node3.key_value=board3;
	cout<<"Board 3"<<endl<<board3.toString();
	
	bool same = false;

	cout<<"Solved board"<<endl<<testBoard.toString();
	//simple jumbled board test
	testBoard.jumble(1);

	cout<<"Jumbled board"<<endl<<testBoard.toString();
	
	test.add(node1);
	linkedList test1, test2, test3;

	node *noder1, *noder2, *noder3;
	noder1 = test1.head;
	noder2 = test2.head;
	noder3 = test3.head;
	node *noder = test.head;
	//this loop here is to move the tiles on the board
	//it's not completely functional
	while(!(noder->key_value == winningBoard)){
		for(int i=0; i<4; i++){
			node1.key_value.move(i);
			test.add(node1);
			node1.key_value=board1;
		}
		noder=noder->next;
		noder->printBoard();
	}
	//printing the list and passing it the winning board to compare the boards to as it goes
	test.printList(winningBoard);

	while(!(noder1->key_value == winningBoard)){
		for(int i=0; i<4; i++){
			node2.key_value.move(i);
			test.add(node2);
			node2.key_value=board2;
		}
		noder1=noder1->next;
		noder1->printBoard();
	}
	//printing the list and passing it the winning board to compare the boards to as it goes
	test1.printList(winningBoard);

	while(!(noder2->key_value == winningBoard)){
		for(int i=0; i<4; i++){
			node3.key_value.move(i);
			test2.add(node3);
			node3.key_value=board3;
		}
		noder2=noder2->next;
		noder2->printBoard();
	}
	//printing the list and passing it the winning board to compare the boards to as it goes
	test2.printList(winningBoard);


	return 0;
}