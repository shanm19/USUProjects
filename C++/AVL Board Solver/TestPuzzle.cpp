#include "Game.h"
#include <time.h>

int main()
{  	srand((int) time(NULL));
	bool playAgain = true;
	char response;
	cout << "Welcome to 8 puzzle \n";
	Game g;
	while (playAgain)
	{  g.play();
	   cout << "Play Again?  Answer Y for yes\n";
	   cin >> response;
	   playAgain = toupper(response)=='Y';
	}


}
