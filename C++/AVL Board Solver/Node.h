#include <string>
#include <iostream>
#include <fstream>
#include <assert.h>
#include "GameState.h"
using namespace std;

// Node in a doubly linked list of words
class Node
{
public:
	GameState gameState;  // data
	Node * next;  // next Node
	Node * prev;  // previous Node
	Node(GameState g,Node * anext=NULL,Node *aprev=NULL);
};