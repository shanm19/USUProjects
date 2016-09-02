#include "DoublyLinkedList.h"


//Add the state "w" to the first of the doubly linked list
void DoublyLinkedList::add(GameState w) {
	Node * n = new Node(w);
	size++;
	if (head==NULL) 
	{    head = n;
	tail = n;
	return;
	}
	tail->next = n;
	n->prev = tail;
	tail =n;
}

// Return the first thing in the queue and return it.
GameState DoublyLinkedList::remove() {
	if (head==NULL) return GameState(); 
	GameState gs = head->gameState;
	Node* temp = head;
	head = head->next;
	delete (temp);
	if (head==NULL)
		tail = NULL;
	else head->prev = NULL;
	return gs;
}

// Empty the queue
void DoublyLinkedList::clear() {
	Node * n = NULL;

	for(Node * curr =head; curr!= NULL; curr = n)
	{  n = curr->next;
	delete (curr);
	}
}

// Return true if the queue contains board b.
bool DoublyLinkedList::contain(Board &b) {
	for (Node *curr = head; curr !=NULL; curr= curr->next)
		if (curr->gameState.current == b) return true;
	return false;
}

