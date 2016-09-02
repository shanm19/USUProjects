#include "Node.h"


// Create a new node before "anext" in the linked list.
Node::Node(GameState g,Node * anext,Node *aprev)
{ gameState =g;
  next  = anext;
  prev = aprev;
  //cout << "Node Constructor\n" << g.toString() << endl;
}