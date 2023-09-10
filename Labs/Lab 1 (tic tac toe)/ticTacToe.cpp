 

//Tic-Tac-Toe Implementation file

#include <iostream>
#include <iomanip> 
#include <random>
#include <string>
#include <windows.h>
#include "ticTacToe.h"

using namespace std;

void ticTacToe::play()
{
	srand(time(0)); //set the random seed based on time.
    bool done = false;
    char player;
    if(rand()%2 == 0){
    	player = 'X';
    }
    else{
    	player = 'O';
    }
    displayBoard();

    //tournament loop here before while !done.
    while (!done)
    {
        done = getXOMove(player);

        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }
}

void ticTacToe::displayBoard() const
{
    cout << "    1    2   3" << endl;
    cout << " 1  "<<board[0][0]<<" | "<<board[0][1]<<"  | "<<board[0][2]<<" " << endl;
    cout << "  ____|____|____" << endl;
    cout << "      |    |   " << endl;
    cout << " 2  "<<board[1][0]<<" | "<<board[1][1]<<"  | "<<board[1][2]<<" " << endl;
    cout << "  ____|____|____" << endl;
    cout << "      |    |   " << endl;
    cout << " 3  "<<board[2][0]<<" | "<<board[2][1]<<"  | "<<board[2][2]<<" " << endl;
}

bool ticTacToe::isValidMove(int row, int col) const
{
	return board[row][col] == ' '? true : false;
}

bool ticTacToe::getXOMove(char playerSymbol)
{
	string userIn = "";
	int row,col;
	do{
		cout << "Player " << playerSymbol << " enter a valid move: ";
		getline(cin, userIn);
		row = int(userIn.at(0))-49;
		col = int(userIn.at(2))-49;
	}
	while(!isValidMove(row,col));
	board[row][col] = playerSymbol;
	noOfMoves++;

	if(gameStatus() == WIN){
		cout << endl;
		displayBoard();
		cout << "Player " << playerSymbol << " wins!" <<endl;
		return true;
	}
	else if(gameStatus() == DRAW){
		cout << endl;
		displayBoard();
		cout << "The game ended in a draw." << endl;
		cout << "A new game will begin shortly. " << endl;
		Sleep(3000);
		reStart();
		cout << endl;
	}
	displayBoard();
	return false;
}

status ticTacToe::gameStatus()
{
	if(noOfMoves < 6){
		return CONTINUE;
	}
	// check rows
	for (int row = 0; row<3;row++){
		if(board[row][0] == board[row][1] && board[row][0] == board[row][2]){
			return WIN;
		}
	}

	//check columns
	for (int col = 0; col<3;col++){
		if(board[0][col] == board[1][col] && board[0][col] == board[2][2]){
			return WIN;
		}
	}
	//check diagonals
	if((board[0][0] == board[1][1] && board[0][0] == board[2][2]) || (board[0][2] == board[1][1] && board[0][2] == board[2][0])){
		return WIN;
	}
	if(noOfMoves == 9){
		return DRAW;
	}
	return CONTINUE;
}

void ticTacToe::reStart()
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            board[row][col] = ' ';

    noOfMoves = 0;
}

ticTacToe::ticTacToe()
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            board[row][col] = ' ';

    noOfMoves = 0;
}
