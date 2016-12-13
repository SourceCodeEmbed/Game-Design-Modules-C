#pragma once
class TicTacToeGame
{
public:
	TicTacToeGame();
	
	void playGame();

	
private:
	

	// Get input from the User
	int getXCoord();
	int getYCoord();

	// Places the marker, if it return false then it couldnt place
	bool placeMarker(int x, int y,char currentPlayer);
	
    bool checkForVictory(char currentPlayer);
	// Empties the Board
	void clearBoard(); 
	// Prints the Board 
	void printBoard();

	char board [3] [3];
	
};

