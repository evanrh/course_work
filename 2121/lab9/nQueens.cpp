/*
 * Name: Evan Hastings
 * Date Submitted: 11/14/19
 * Lab Section: 2121-001
 * Assignment Name: Lab 9: N-Queens Problem
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// A value will be true if a queen is placed there
// False otherwise
vector<vector<bool>> BOARD;
int NUM_SOLUTIONS = 0;

void checkRow(int);
bool validPos(int,int);

//Uses recursion to count how many solutions there are for
//placing n queens on an nxn chess board
int nQueens(int n)
{
	//Implement int nQueens(int n)
	//Feel free to implement any recursive helper functions
	
	// Create new board of n x n all set to false
	BOARD = vector<vector<bool>>(n,vector<bool>(n, false));
	NUM_SOLUTIONS = 0;
	
	// Start recursion through board
	checkRow(0);
	
	BOARD.clear();

	// For 1 it needs to return 1, but for all other n, the number is doubled
	return n > 1 ? NUM_SOLUTIONS * 2: 1;
}

void checkRow(int r)	{
	
	// Set a max for the columns if in first row
	int max = BOARD[r].size();

	// Check if n is odd
	if(r == 0)
		max = max % 2 == 0 ? max / 2 : ceil(max / 2);

	// If function makes it to last row, then there is a solution
	if(r == (int)BOARD.size())
		NUM_SOLUTIONS++;

	else	{
		for(int col = 0; col < max; col++)	{
			if(validPos(r,col))	{
				BOARD[r][col] = true;
				checkRow(r+1);
				BOARD[r][col] = false;
			}
			
		}
	}

	
}

bool validPos(int r, int c)	{

	// Check if a queen is in the current column
	for(int row = 0; row < r; row++)	{
		if(BOARD[row][c])
			return false;
	}

	// Check if a queen is in the \ diagonal
	for(int i = r, j = c; i >= 0 && j >= 0; i--, j--)	{
		if(BOARD[i][j])
			return false;
	}

	// Check if a queen is in the / diagonal
	for(int i = r, j = c; i >= 0 && j < BOARD[r].size(); i--, j++)	{
		if(BOARD[i][j])
			return false;
	}

	// Space is valid
	return true;
}

int main()
{
    cout << "1: " << nQueens(1) << endl;
    cout << "2: " << nQueens(2) << endl;
    cout << "3: " << nQueens(3) << endl;
    cout << "4: " << nQueens(4) << endl;
    cout << "5: " << nQueens(5) << endl;
    cout << "6: " << nQueens(6) << endl;
    cout << "7: " << nQueens(7) << endl;
    cout << "8: " << nQueens(8) << endl;
    cout << "9: " << nQueens(9) << endl;
    cout << "10: " << nQueens(10) << endl;
    cout << "11: " << nQueens(11) << endl;
    cout << "12: " << nQueens(12) << endl;
    return 0;
}
