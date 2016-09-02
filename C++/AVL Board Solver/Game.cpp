#include "Game.h"

// Find a solution to the 8 puzzle game created by a random jumbling.
void Game::play() {
	const int MAXMOVE = 4;  // Can move in four directions

	const int JUMBLE = 36;  // Numnber of times to jumble the initial board
	Board win;              // The goal board
	GameState nextGS,gs;    // Current and next game states
	int currStateID;     // Current stateID
	currStateID = 0;
	board.makeBoard(JUMBLE);
	gs = GameState(board,-1,currStateID++);
	moves.add(gs);
	ofs << gs.toString();
	cout << gs.toString();


	while (!moves.isEmpty()){
		gs = moves.remove();

		Board  myBoard= gs.current;
		for (int t = 0; t < MAXMOVE; t++) {
			Board possible = myBoard;
			possible.move(t);

			if (!moves.contain(possible) && !(possible==myBoard))
			{
				nextGS = GameState(possible,gs.stateID,currStateID++);
				moves.add(nextGS);
				ofs << nextGS.toString() << endl;
				cout << nextGS.toString() << endl;
			}
			if (possible==win){ 
				ofs << possible.toString() << "From state " << gs.stateID << endl;
				cout << possible.toString() << "From state " << gs.stateID << endl;
				ofs << "YOU WIN!!!\n";
				cout << "YOU WIN!!!\n";
				return;
			}
		}
	}
	cout << "You lose\n";
	ofs << "You lose\n";

};

Game::Game (){
	//cout << "Game constructor called\n";
	board.makeBoard();
	ofs.open("prog1OUT.txt");
};
