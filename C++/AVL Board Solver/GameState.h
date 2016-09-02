#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <string>
#include <iostream>
#include <fstream>
#include <assert.h>
#include "Board.h"
#include <sstream>
using namespace std;


class GameState
{ 

public:
    Board current;   // Contents of current board
	int stateID;     // State ID of the current board
	int prevStateID; // State ID of the parent board
	string toString();
	GameState( Board curr,int prevID, int currID)
	{   current = curr;
		prevStateID = prevID;
		stateID = currID;
	
	}
	GameState()
	{ current.makeBoard();
	}
};
#endif