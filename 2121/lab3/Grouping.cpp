/*
 * Name:
 * Date Submitted:
 * Lab Section:
 * Assignment Name:
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//Represents an occupied square in the grid
//Do not modify the GridSquare class or its member functions
class GridSquare
{
    private:
        int row, col;
    public:
        GridSquare() : row(0), col(0) {} //Default constructor, (0,0) square
        GridSquare(int r, int c) : row(r), col(c) {} //(r,c) square
        //Compare with == operator, used in test cases
        bool operator== (const GridSquare r) const
        {
            if ((row == r.row) && (col == r.col))
            {
                return true;
            }
            return false;
        }
        int getRow() { return row; } //return row value
        int getCol() { return col; } //return column value
        //Output using << operator, used in Grouping::printGroups()
        friend ostream& operator<< (ostream& os, const GridSquare obj);
};

//Function definition for <ostream> << <GridSquare>
ostream& operator<< (ostream& os, const GridSquare obj)
{
    os << "(" << obj.row << "," << obj.col << ")";
    return os;
}

/*
Groups squares in 10x10 grid upon construction
Additional private helper functions may be added
Need to implement the constructor that takes a file name
as well as findGroup
The findGroup function's parameter list may be changed based
on how the function is implemented
*/
class Grouping
{
    private:
        int grid[10][10];
        vector<vector<GridSquare>> groups;
        bool vecCheck( GridSquare );
        bool boundsCheck(int, int);

    public:
        Grouping() : grid{},groups() {} //Default constructor, no groups
        Grouping(string fileName); //Implement this function
        void findGroup(int r, int c, int groupNum); //Implement this function (recursive)
        void printGroups() //Displays grid's groups of squares
        {
            for(int g=0; g<groups.size(); g++)
            {
                cout << "Group " << g+1 << ": ";
                for(int s=0; s<groups[g].size(); s++)
                {
                    cout << " " << groups[g][s];
                }
                cout << endl;
            }
        }
        vector<vector<GridSquare>> getGroups() //Needed in unit tests
        {
            return groups;
        }
			
			
			};

//Implement the (parameterized) constructor and findGroup functions below
Grouping::Grouping(string filename)	{
	
	ifstream input( filename );
	char temp;
	
	// Loop through all characters in file
	for(int i = 0; i < 10; i++)	{
		for(int j = 0; j < 10; j++)	{
			input >> temp;

			if(temp == 'X')
				grid[i][j] = 1;
			else
				grid[i][j] = 0;
		}
	}
	
	// Loop through all characters in file
	int groupNum = 0;
	for(int i = 0; i < 10; i++)	{
		for(int j = 0; j < 10; j++)	{
			
			// GridSquare of current position
			GridSquare current(i,j);
			
			// Check for X char
			if( grid[i][j] ) {
				
				// Check if groups has been filled previously
				if( groups.empty() )	{
					
					// Make new vector group and find all adjacent squares
					vector< GridSquare > newVec;
					groups.push_back( newVec );
					findGroup( i, j, groupNum );
					groupNum++;
				}
				
				// Check for position already being in a group
				else if( vecCheck( current ))	{
					
					// Make new vector group and find all adjacent squares
					vector< GridSquare > newVec;
					groups.push_back( newVec );
					findGroup( i, j, groupNum );
					groupNum++;
				}
			}
		}
	}
}

// Recursive function to find all adjacent squares in a group
// puts all found members into group specified by groupNum
void Grouping::findGroup(int r, int c, int groupNum)	{
	
	GridSquare current(r,c);
	if( boundsCheck(r,c)) {}
	
	else if( !grid[r][c] ) {}

	else if( vecCheck( current ))	{
		groups.at(groupNum).push_back(current);
		findGroup(r, c+1, groupNum);
		findGroup(r, c-1, groupNum);
		findGroup(r+1, c, groupNum);
		findGroup(r-1, c, groupNum);
		
	}

}

// Helper function to determine that a square is in bounds
// return: true iff 0 <= r <= max_rows and 0 <= c <= max_cols
bool Grouping::boundsCheck(int r, int c)	{
	if(r > 9 or r < 0)
		return true;
	else if(c > 9 or c < 0)
		return true;
	else
		return false;
}

// Helper function to check if a position is in a vector group
bool Grouping::vecCheck( GridSquare pos )	{
	
	// Loop through vector of all groups
	for(int i = 0; i < groups.size(); i++)	{

		// Looop through each subgroup
		for(int j = 0; j < groups.at(i).size(); j++)	{
			
			if (groups.at(i).at(j) == pos)
				return false;

		}
	}

	return true;

}


//Simple main function to test Grouping
int main()
{
    Grouping input1("input1.txt");
    input1.printGroups();
    
    return 0;
}
