
#include "TicTacToeGame.h"
#include <iostream>

using namespace std;


TicTacToeGame::TicTacToeGame(void)
{
	
}

void TicTacToeGame::playGame()
{   
	clearBoard();
	char player1 = 'X';
	char player2 = 'O';

	char currentPlayer = player1;
	bool isDone = false;

	int turn = 0;

	while (isDone == false)
	{
	// Print the Board
	printBoard();
	int x, y ; 
	//Get in Input
	x = getXCoord();
	y = getYCoord();
	// Place the marker
	if (placeMarker(x,y,currentPlayer) == false )
	{
		cout<<" \n That spot is occupied!\n";
	}else
	{
		turn++;
		if (checkForVictory(currentPlayer) == true)
		{
			cout<<"The game is over! Player " << currentPlayer << " has Won! \n";
			isDone = true;
		}else if ( turn == 9)
		{
			cout<<" \n Its a tie game! \n";
			isDone = true;
		}
		
	
			// Switch players
			if (currentPlayer == player1)
			{
			currentPlayer = player2;
			cout<<"\n Player 2's Turn \n";
			}else
			{
			currentPlayer = player1;
			cout<<"\n Player 1's Turn \n";
			}
		
	}
	

	

	}
}


bool TicTacToeGame::placeMarker(int x, int y , char currentPlayer)
{
	if (board[x][y] != ' ' ){
	return false;
	}

	board[x] [y] = currentPlayer;
	return true;
}


bool TicTacToeGame::checkForVictory( char currentPlayer )
{
	//Check the rows
	for (int x= 0; x < 3; x++)
	{
		if ((board [x] [0] == currentPlayer) && (board[x] [0] == board [x] [1]) && (board [x] [1] == board [x] [2]) )
	{
		return true; 
	}
	}

	// Check for Columns
	for (int y = 0; y < 3; y++)
	{
		if ((board [y] [0] == currentPlayer) && (board [0] [y] == board [1] [y]) && (board [1] [y] == board [2] [y]) )
	{
		return true; 
	}
	}

	// Check for top left diognal
	if ((board [0] [0] == currentPlayer) && (board[0] [0] == board [1] [1]) && (board [1] [1] == board [2] [2]) )
	{
		return true; 
	}
	// Check for top right diognal
	if ((board [0] [2] == currentPlayer) && (board[0] [2] == board [1] [1]) && (board [1] [1] == board [2] [0]) )
	{
		return true; 
	}

	return false;
}

int TicTacToeGame::getXCoord()
{
	bool isInputBad = true;
	int x;
	while (isInputBad == true)
	{
	cout<< " Enter the X Coordinate: ";
	cin>>x;
	if (x < 1 || x > 3)
	{
		cout<<"Invalid Coorinate\n";
	}else
	{
		isInputBad = false;
	}
	}
	
	return x-1;
}

int TicTacToeGame::getYCoord()
{

	bool isInputBad = true;
	int y;
	while (isInputBad == true)
	{
	cout<< " Enter the Y Coordinate: ";
	cin>>y;
	if (y < 1 || y > 3)
	{
		cout<<"Invalid Coordinate\n";
	}else
	{
		isInputBad = false;
	}
	}

	return y-1;
}
void TicTacToeGame::clearBoard() 
{
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			board [x] [y] = ' ';
		}
	}
}

void TicTacToeGame::printBoard()
{
			cout<< endl;
			cout<< " |1 2 3|\n";
    
		for (int x = 0; x < 3; x++)
		{
			cout<< " -------\n";
			cout<< x+1 << "|" << board [x] [0] << "|" << board [x] [1] << "|" << board [x] [2] << "|\n";
			
		}
			cout<< " -------\n";
}
