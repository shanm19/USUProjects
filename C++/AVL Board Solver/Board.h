#ifndef BOARD_H
#define BOARD_H
#include <string>
#include <iostream>
#include <fstream>
#include <assert.h>
#include <sstream>
using namespace std;


class Board {
public:
	static const int SIZE = 3;
	int board[SIZE][SIZE];  // Values of board
	int spacex;             // x subscript of space
	int spacey;             // y subscript of space

	Board(const Board & b);
	bool move(int m);
	void makeBoard(int jumbleCt=0);
	string toString();
	bool Board::operator==(Board &b);
	Board(){ makeBoard();};
	bool Board::moveNorth();
	bool moveSouth();
	bool moveEast();
	bool moveWest();
	void jumble(int ct);
};
#endif