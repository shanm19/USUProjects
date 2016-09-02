#include <string>
#include <ctime>
#include <iostream>
#include <fstream>
#include <assert.h>
#include "GameState.h"

#include "DoublyLinkedList.h"
using namespace std;

class Game {
	ofstream ofs;    // Output file for game trace
public:   
	DoublyLinkedList moves; //Queue of gameboards
	Board board;            // Current board
	void play();             

	// Setup game and read dictionary from "filename"
	Game ();
};
