#include "GameState.h"

string GameState::toString(){
	stringstream ss;

	ss<<"State " << stateID << " From State " << prevStateID << "\n" <<current.toString() << endl;
	/*
	for (int i=0; i < Board::SIZE;i++)
	{ for (int j=0; j < Board::SIZE; j++)
	      ss << current.board[i][j] << " ";
	  ss << "   "; 
	  for (int j=0; j < Board::SIZE; j++)
	 	    ss << previous.board[i][j] << " ";
	  ss<< endl;
	}
	*/
	return ss.str();

};