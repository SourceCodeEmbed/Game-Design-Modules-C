#include<iostream>
#include "TicTacToeGame.h"

using namespace std;


int main()
{   bool isDone = false;
	char input;

	TicTacToeGame game;
	

	while (isDone == false)
	{
		game.playGame();
		cout<<"Would ypu like to play again ? (Y/N): ";
		cin>>input;

		if (input == 'N' || input == 'n')
		{
			isDone = true;
		}
	}

	system("PAUSE");
	return 0;
}