#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void displayboard (char[3][3]);
void player1(char[3][3], bool &);
void player2(char[3][3], bool &);
bool winner1(char[3][3]);
bool winner2(char[3][3]);

int main()
{
	int moves = 0;
	char board[3][3] = { {'*', '*', '*'}, {'*', '*', '*'}, {'*', '*', '*'} };
	bool end = false, win1 = false, win2 = false, draw = false;

	cout << "### TIC TAC TOE GAME ###\n\n";

	displayboard(board);	

	while(!end)
	{
		player1(board, win1);

		if(win1)
		{
			end = true;
			break;
		}

		moves = moves + 1;

		if(moves == 9)
		{
			end = true;
			draw = true;
			break;
		}	

		player2(board, win2);

		if(win2)
		{
			end = true;
			break;
		}

		moves = moves + 1;

		if(moves == 9)
		{
			end = true;
			draw = true;
			break;
		}	
	
	}///end of while

	if(draw == true)
	{
		cout << "A tie has occurred. There is no winner.\n";
	}

	if(win2)
		cout << "Player 2 has won!\n";

	if(win1)
		cout << "Player 1 has won!\n";


	return 0;
}


void displayboard(char playingBoard[3][3]) //To show the board
{
	
	for(int count = 0; count < 3; count++)
	{
		for(int index = 0; index <3; index++)
		{
			cout << playingBoard[count][index];
			cout << " ";

		}

		cout << endl;
	}

	cout << endl;
}

void player1(char board[3][3], bool &win1)
{
	int row = 0, column = 0;

	cout << "Player 1: Enter your move in the format <row> <column>: ";
	cin >> row >> column;
	cout << endl;



	while ( (row > 3) || (row < 1) || (column > 3) || (column < 1) )
	{
		displayboard(board);		
		cout << "Player 1: Enter your move in the format <row> <column>: ";
		cin >> row >> column;
		cout << endl;
		
	}

	while(board[row - 1][column - 1] != '*')
	{
		displayboard(board);		
		cout << "Player 1: Enter your move in the format <row> <column>: ";
		cin >> row >> column;
		cout << endl;
		
	}

	board[row - 1][column - 1] = 'X';
	displayboard(board);
	win1 = winner1(board);
}

void player2(char board[3][3], bool &win2)
{
	int row = 0, column = 0;

	cout << "Player 2: Enter your move in the format <row> <column>: ";
	cin >> row >> column;
	cout << endl;


	while ( (row > 3) || (row < 1) || (column > 3) || (column < 1) )
	{
		row = 0;
		column = 0;
		
		displayboard(board);		
		cout << "Player 2: Enter your move in the format <row> <column>: ";
		cin >> row >> column;
		cout << endl;		
	}

	while(board[row - 1][column - 1] != '*')
	{
		displayboard(board);		
		cout << "Player 2: Enter your move in the format <row> <column>: ";
		cin >> row >> column;
		cout << endl;		
	}

	board[row - 1][column - 1] = 'O';
	displayboard(board);
	win2 = winner2(board);
}

bool winner1(char board[3][3])
{
	//Check diagonal left to right
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] == 'X')
	{
		return true;
	}

	//Check diagonal right to left
	if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] == 'X')
	{
		return true;
	}

	// Horizontal
	for(int count = 0; count < 3; count++)
	{
		int column = 0;
		if(board[count][column] == board[count][column + 1] && board[count][column] == board[count][column + 2] )
		{
			if(board[count][column] == 'X')
			{
				return true;
			}
		}

	}

	//Vertical
	for(int index = 0; index < 3; index++)
	{
		int row = 0;
		if(board[row][index] == board[row + 1][index] && board[row][index] == board[row +2][index] )
		{
			if(board[row][index] == 'X')
			{
				return true;
			}
		}
	}

	return false;
		

}//End of Winner Function

bool winner2(char board[3][3])
{
	//Check diagonal left to right
	if(board[0][0] == board[1][1]  && board[1][1] == board[2][2] && board[1][1] == 'O')
	{
		return true;
	}

	//Check diagonal right to left
	if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] == 'O')
	{
		return true;
	}

	// Horizontal
	for(int count = 0; count < 3; count++)
	{
		int column = 0;
		if(board[count][column] == board[count][column + 1] && board[count][column] == board[count][column + 2] )
		{
			if(board[count][column] == 'O')
			{
				return true;
			}
		}

	}

	//Vertical
	for(int index = 0; index < 3; index++)
	{
		int row = 0;
		if(board[row][index] == board[row + 1][index] && board[row][index] == board[row +2][index] )
		{
			if(board[row][index] == 'O')
			{
				return true;
			}
		}
	}

	return false;
		

}//End of Winner Function

