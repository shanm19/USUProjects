#include "Node.h"
class DoublyLinkedList {
	int size;  // Number of items in linked list
	Node * head;  // First node in list
	Node* tail;   // Last node in list

public:
	DoublyLinkedList(void) {head=NULL; size=0;}
	void add(GameState);
	GameState remove();
	bool contain(Board & b);
	void clear();
	bool isEmpty() {return head==NULL;}
};

