#include "Board.h"

// Create a printable representation of the Board class
string Board::toString() {
	stringstream ss;
	for (int i=0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			ss << board[i][j] << " ";
		ss << endl;
	}
	ss<<endl;
	return ss.str();
};

// return true if board is identical to b
bool Board::operator==(Board &b) {

	for (int i=0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			if (board[i][j] != b.board[i][j]) return false;
	return true;
}

//Create a board that can be solved using moves
//jumbleCt indicates the number of moves that may be required
//if jumbleCt ==0, return the winning board
void Board::makeBoard(int jumbleCt) {
	int val=1;
	for (int i=0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			board[i][j] = val++;
	board[SIZE-1][SIZE-1]=0;
	spacex = spacey = SIZE-1;
	jumble(jumbleCt);
}

//Copy constructor
Board::Board(const Board & b) {
	for (int i=0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
		{
			board[i][j] = b.board[i][j];
			if (b.board[i][j]==0)
			{ spacex=i;
			spacey=j;
			}
		}
}

// Swap the values of two ints
void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

//move another block North into the empty position
//Return true if successful
bool Board::moveNorth() {
	if (spacex == SIZE-1) return false;
	//cout << "moveNorth " << spacex << spacey<<endl;
	swap(board[spacex][spacey], board[spacex+1][spacey]);
	spacex++;
	return true;
}

//move another block South into the empty position
//Return true if successful
bool Board::moveSouth() {
	if (spacex == 0) return false;
	//cout << "moveSouth " << spacex << spacey<<endl;
	swap(board[spacex][spacey], board[spacex-1][spacey]);
	spacex--;
	return true;
}
//move another block East into the empty position
//Return true if successful
bool Board::moveEast() {
	if (spacey == 0) return false;
	//cout << "moveEast " << spacex << spacey<<endl;
	swap(board[spacex][spacey], board[spacex][spacey-1]);
	spacey--;
	return true;
}

//move another block West into the empty position
//Return true if successful
bool Board::moveWest() {
	if (spacey == SIZE-1) return false;
	//cout << "moveWest " << spacex << spacey<<endl;
	swap(board[spacex][spacey], board[spacex][spacey+1]);
	spacey++;
	return true;
}

// Randomly apply ct moves to the board
void Board::jumble(int ct) {
	for (int i=0; i < ct; i++)
		move(rand()%4);
}

// Attempt to make one move on the board, 0 indictes Move North, etc
//Return true if successful
bool Board::move(int m){
	switch (m)
	{case 0: return moveNorth();
	case 1: return moveEast();
	case 2: return moveSouth();
	case 3: return moveWest();
	}
	return false;
}

