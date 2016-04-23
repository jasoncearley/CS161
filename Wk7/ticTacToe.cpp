/**********************************************************************
 * Program: ticTacToe.cpp
 * Author: Jason Cearley
 * Class: CS161
 * Date: 11/14/14
 * Modified: 11/14/14
 * Description: This program allows the users to play a game of 
 * 				Tic-Tac-Toe.
 * Output: Winner of each game and if more than 1 game played, the 
 * 		   overall winner.
 * *******************************************************************/

#include <iostream>  // cin/cout
#include <limits> 	 // limits
#include <string>    // strings 
#include <cstdlib>   // atoi

using namespace std;

// Prototype Function(s)
void display_board(const char [][3]);
void get_move(char [][3], int, int);
bool check_for_winner(const char [][3]);

int main(int argc, char *argv[])
{
	int num_games = 0, 		// Store the # of games to play
		player_move = 0, 	// Keep track of whose move it is
		PlayerX_Wins = 0, 	// Keep track of Player X's wins
		PlayerO_Wins = 0,	// Keep track of Player O's wins
		Ties = 0,			// Keep track of the Ties
		game_number = 0;	// Keep track of the game #
	char board [3][3];		// The board for the tic tac toe game
	
	// Set # of games to play to 1 if no command line argument
	if (!argv[1])
	{
		num_games = 1;
	}
	
	// Set # of games to play to # in command line argument
	if (argv[1])
	{
		num_games = atoi(argv[1]);
	}
	
	// Do/while loop for the "War"
	do
	{
		// Initialize board with periods
		for (int row = 0; row < 3; row++)
		{
			for (int col = 0; col < 3; col++)
			{
				board [row][col] = '.';
			}
		}
	
		cout << "This is game " << game_number + 1 << " of " << num_games
			 << endl;
			 
		display_board(board);
		
		// Do/while loop for the "battles"
		do
		{
			get_move(board, game_number, player_move);
	
			display_board(board);
			
			// Check for a winner and increment their wins appropriately
			if (check_for_winner(board))
			{
				if (game_number % 2 == 0)
				{
					if (player_move % 2 == 0)
					{
						cout << "Congrats Player X! You won this game." 
						 << endl;
					
						PlayerX_Wins++;
					}
					
					else
					{
						cout << "Congrats Player O! You won this game." 
						 << endl;
					
						PlayerO_Wins++;
					}
				}
				
				else
				{
					if (player_move % 2 == 0)
					{
						cout << "Congrats Player O! You won this game." 
						 << endl;
					
						PlayerO_Wins++;
					}
					
					else
					{
						cout << "Congrats Player X! You won this game." 
						 << endl;
					
						PlayerX_Wins++;
					}
				}
				
				goto new_game;
			}
		
			player_move++;
		}
		while(player_move != 9);
		
		// Increment ties if no one won a battle
		Ties++;
		
		cout << "It's a Tie." << endl;
		
		new_game:
		game_number++;		// Increment the game number
		player_move = 0;	// Reset player_move back to 0
	}
	while (game_number != num_games);
	
	// Display results
	cout << "Player X won " << PlayerX_Wins << " game(s)." << endl;
	cout << "Player O won " << PlayerO_Wins << " game(s)." << endl;
	cout << "There were " << Ties << " Tie(s)." << endl;
	
	if (PlayerX_Wins > PlayerO_Wins)
	{
		cout << "The Grand Champion is Player X!" << endl;
	}
	
	else if (PlayerO_Wins > PlayerX_Wins)
	{
		cout << "The Grand Champion is Player O!" << endl;
	}
	
	else
	{
		cout << "There is no Grand Champion. It's a Tie." << endl;
	}
	 
	return 0;
}

/***********************************************************************
 * This function will display the board with the user's input.
 **********************************************************************/
void display_board(const char board[][3])
{
	cout << "  0 1 2" << endl;
	
	for (int row = 0; row < 3; row++)
	{
		cout << row << " ";
		
		for (int col = 0; col < 3; col++)
		{
			cout << board [row][col] << " ";
		}
		
		cout << endl;
	}
	
	cout << endl;
}

/***********************************************************************
 * This function will fill the board with the user's input and validate
 * it.
 **********************************************************************/
void get_move(char board[][3], int game, int player)
{
	int row = 0, col = 0;
	
	bad:
	
	// Prompt app player for move based on game # & player #
	if (game % 2 == 0)
	{
		if (player % 2 == 0)
		{
			cout << "Player X: Please enter your move." << endl;
		}
	
		else
		{
			cout << "Player 0: Please enter your move." << endl;
		}
	}
	
	else
	{
		if (player % 2 == 0)
		{
			cout << "Player O: Please enter your move." << endl;
		}
	
		else
		{
			cout << "Player X: Please enter your move." << endl;
		}
	}
	
	cin >> row;		// Store first # to row
	
	// Ensure row is valid
	if (!cin || row < 0 || row > 2)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "That was not a valid entry. Please try again. ";
		goto bad;
	}
	 
	cin >> col;		// Store second # to col
	
	// Ensure col is valid
	if (!cin || col < 0 || col > 2)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "That was not a valid entry. Please try again. ";
		goto bad;
	}
	
	// Ensure space is not already taken
	if (board[row][col] != '.')
	{
		cout << "That space is already taken. ";
		goto bad;
	}
	
	// Make sure user did not try to supply > 2 numbers for coordinates
	if (cin.peek() != 10)
	{
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "That is not a valid entry. " << endl;
		goto bad;
	}
	
	// Fill board w/ app player's move
	if (game % 2 == 0)
	{
		if (player % 2 == 0)
		{	
			board[row][col] = 'X';
		}
	
		else 
		{
			board[row][col] = 'O';
		}
	}
	
	else
	{
		if (player % 2 == 0)
		{	
			board[row][col] = 'O';
		}
	
		else 
		{
			board[row][col] = 'X';
		}
	}
}

/***********************************************************************
 * This function checks the board for a winner (i.e. 3 in a row on any 
 * row, col, or major diagonal).
 **********************************************************************/
bool check_for_winner(const char board[][3])
{
	int same;
	
	// For loop to check for 3 in a row on any rows
	for (int row = 0; row < 3; row++)
	{
		same = 0;
		
		for (int col = 0; col < 2; col++)
		{	
			if (board[row][col] == board[row][col + 1] 
				&& board[row][col] != '.')
			{
				same++;
			}
		}
		
		if (same == 2)
		{
			return true;
		}
	}
	
	// For loop to check for 3 in a row in any cols
	for (int col = 0; col < 3; col++)
	{
		same = 0;
		
		for (int row = 0; row < 2; row++)
		{	
			if (board[row][col] == board[row + 1][col] 
				&& board[row][col] != '.')
			{
				same++;
			}
		}
		
		if (same == 2)
		{
			return true;
		}
	}
	
	same = 0;
	
	// Check a major diagonal for 3 in a row
	for (int a = 0; a < 2; a++)
	{
		if (board[a][a] == board[a + 1][a + 1] 
			&& board[a + 1][a + 1] != '.')
		{
			same++;
		}
		
		if (same == 2)
		{
			return true;
		}
	}
	
	same = 0;
	
	// Look at next major diagonal for 3 in a row
	for (int a = 2, b = 0; a > 0; a--, b++)
	{
		if (board[a][b] == board[a - 1][b + 1] 
			&& board[a][b] != '.')
		{
			same++;
		}
		
		if (same == 2)
		{
			return true;
		}
	}
	
	return false;
}
		
		
