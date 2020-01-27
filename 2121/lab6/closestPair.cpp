/*
 * Name:
 * Date Submitted:
 * Lab Section:
 * Assignment Name:
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

struct point
{
    double x;
    double y;
};

/*Implement the following function
  Reads in a file specified by the parameter
  Format of file: #of points on first line
                  remaining (#of points) lines: x-value and y-value of point
                  one point per line
                  x-value and y-value are double-precision values and
                  bounded by the unit square 0.0 <= x,y < 1.0
  Should use "spatial hashing" where the #of cells scales with the #of points
  and find the distance between the closest pair of points which will be
  returned as a double type value
*/
double closestPair(string filename);
bool distFound(point,point, set< vector< point >>);
double checkGroups(point, vector< point >&, set< vector< point >>);

int main()
{
    double min;
    string filename;
    cout << "File with list of points within unit square: ";
    cin >> filename;
    min = closestPair(filename);
    cout << setprecision(16);
    cout << "Distance between closest pair of points: " << min << endl;
    return 0;
}

double closestPair(string filename)	{

	// Open file
	ifstream input (filename);

	// Number of points to be inputted and compared
	int numPoints = 0;
	input >> numPoints;
	int b = sqrt(numPoints);

	// Grid plane of all input points
	vector< vector< vector< point>>> grid(b, vector<vector< point>>(b));
	
	// Loop to put all points in plane
	for(int i = 0; i < numPoints; i++)	{
		point current;
		current.x = 0;
		current.y = 0;
		input >> current.x;
		input >> current.y;

		int xHash = (int)(current.x * b);
		int yHash = (int)(current.y * b);

		grid[xHash][yHash].push_back(current);
	}

		
	double min = 1;
	
	set< vector< point>> checkedPoints;

	for(int i = 0; i < b; i++)	{
		for(int j = 0; j < b; j++)	{
			for(auto currentPoint : grid[i][j])	{
				double temp = checkGroups( currentPoint, grid[i][j], checkedPoints);
				double compare = 2;
				
				// Find shortest length from point to west bucket
				if(j != 0)	{
					compare = checkGroups( currentPoint, grid[i][j-1], checkedPoints);
					temp = (compare<temp)? compare:temp;
					
					// Find shortest length from point to northwest bucket
					if( i != (b-1))	{
						compare = checkGroups( currentPoint, grid[i+1][j-1], checkedPoints);
						temp = (compare<temp)? compare:temp;
					}

				}
				
				// Find shortest length from point to east bucket
				if(j != (b - 1))	{
					compare = checkGroups( currentPoint, grid[i][j+1], checkedPoints);
					temp = (compare<temp)? compare:temp;
					
					// Find shortest length from point to northeast bucket
					if( i != (b-1))	{
						compare = checkGroups( currentPoint, grid[i+1][j+1], checkedPoints);
						temp = (compare<temp)? compare:temp;
					}
				}
				
				// Find shortest length from point to south bucket
				if(i != 0)	{
					compare = checkGroups( currentPoint, grid[i-1][j], checkedPoints);
					temp = (compare<temp)? compare:temp;
					
					// Find shortest length from point to southwest bucket
					if(j != 0)	{
						compare = checkGroups( currentPoint, grid[i-1][j-1], checkedPoints);
						temp = (compare<temp)? compare:temp;
					}
					
					// Find shortest length from point to southeast bucket
					if(j != (b-1))	{
						compare = checkGroups( currentPoint, grid[i-1][j+1], checkedPoints);
						temp = (compare<temp)? compare:temp;
					}
				}	
				
				// Find shortest length from point to north bucket
				if(i != (b - 1))	{
					compare = checkGroups( currentPoint, grid[i+1][j], checkedPoints);
					temp = (compare<temp)? compare:temp;

				}
				
				if(temp < min)
					min = temp;
			}
		}
	}

	return min;
}

// Checks if the two points have been compared to each other already
bool distFound(point l, point r, set< vector< point >> group)	{
	
	// Two possible arrangements of points in vector
	vector< point > sideOne = {l,r};
	vector< point > sideTwo = {r,l};
	auto one = group.find( sideOne );
	auto two = group.find( sideTwo );

	if( one != group.end() or two != group.end())
		return true;
	else
		return false;

}

// Checks input group of points against the 1st parameter current
double checkGroups(point current, vector< point > &group, set< vector< point >> checked)	{
	
	// Min set higher than could possibly be
	double min = 2;

	// Loop through all points in group
	for(auto points : group)	{
		
		// Point is comparing to itself
		if(points.x == current.x and points.y == current.y)
			continue;
		
		// Distance between points not already checked
		if(!distFound(current, points, checked))	{

			// Make new vector of distance two points being compared
			vector< point > newVec(2, current);
			newVec[1] = points;
			checked.insert( newVec );
			double xDiff = current.x - points.x;
			double yDiff = current.y - points.y;
			double dist = sqrt( pow(xDiff,2) + pow(yDiff,2));
			
			// Check for new distance being less than old minimum
			if(dist < min)
				min = dist;

		}

	}

	// Return minimum value from comparison of group
	return min;

}

// Operator override to allow set method 'find' to work with the point struct
inline bool operator<(const point& lhs, const point& rhs)	{
	if( lhs.x < rhs.x)	{
		if( lhs.y < rhs.y)
			return true;
	}

	return false;
}
