/*
 * Evan Hastings
 * Date Submitted:
 * 2121-001
 * Lab 4: Searching and Sorting
 */

#pragma once

#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

template <class T>
std::vector<T> mergeSort(std::vector<T> lst){

	vector<T> l;
	vector<T> r;
	
	// Base case 
	if( lst.size() <= 1)	{
		return lst;
	}

	// Increment var and middle value of vector
	unsigned int i = 0;
	unsigned int mid = lst.size() / 2;
	
	// Create left half vector
	for( i = 0; i < mid; i++)
		l.push_back( lst.at(i) );
	
	// Create right half vector
	for( i = mid; i < lst.size(); i++)
		r.push_back( lst.at(i) );
	
	// MergeSort both sides of vector recursively
	l = mergeSort(l);
	r = mergeSort(r);
	vector<T> output;
	
	i = 0;
	
	// Sort values of vectors into output in ascending order
	while(l.size() > 0 or r.size() > 0 )	{

		// Both vectors still contain values
		if(l.size() > 0 and r.size() > 0 )	{
			
			// Store smallest value in output and remove from original vector
			if(l.front() <= r.front())	{
				output.push_back( l.front());
				l.erase( l.begin() );
			}
			
			else	{
				output.push_back( r.front());
				r.erase( r.begin() );
			}
		}
		
		// Only l contains values
		else if(l.size() > 0)	{
			unsigned int top = l.size();
			for(i = 0; i < top; i++)	{
				output.push_back( l.front() );
				l.erase( l.begin() );
			}
		}
		
		// Only r contains values
		else if(r.size() > 0)	{
			unsigned int top = r.size();
			for(i = 0; i < top; i++)	{
				output.push_back( r.front() );
				r.erase( r.begin() );
			}
		}
	}

	return output;
}

/*
	Overloaded quickSort function that takes a start and stop point
	of the vector being sorted
*/
template <class T>
void quickSort(std::vector<T> &lst, int low, int high){
	
	// Base case
	if((high - low) <= 0 or high <= 0)
		return;
	
	int index = low + rand() % (high - low);
	T pivot = lst.at(index);
	
	T temp = lst.at(low);

	lst.at(low) = pivot;
	lst.at(index) = temp;
	index = low;
	
	// Loop through all members of vector
	for(int i = low + 1; i <= high; i++)	{
		
		// If value at i is < pivot, the index is incremented and the value there
		// is swapped with the value at i
		if( lst.at(i) < pivot)	{
			index++;
			temp = lst.at(index);
			lst.at(index) = lst.at(i);
			lst.at(i) = temp;
		}
	}
	
	// Swap value at index with pivot
	temp = lst.at(low);
	lst.at(low) = lst.at(index);
	lst.at(index) = temp;
	
	// Another base case check
	if(index > 0)
		quickSort(lst, low, index - 1);
	if(index < (int)lst.size())
		quickSort(lst, index + 1,high);


}

template <class T>
std::vector<T> quickSort(std::vector<T> lst){
	
	srand(time(NULL));
	// Base case
	if(lst.size() <= 1)
		return lst;
	
	int index = rand() % lst.size();
	T pivot = lst.at(index);
	
	// Swap pivot and first member of vector
	T temp = lst.at(0);
	lst.at(0) = pivot;
	lst.at(index) = temp;
	index = 0;
	
	// Loop through all members of vector
	for(int i = 1; i < (int)lst.size(); i++)	{

		// If value at i is < pivot, the index is incremented and the value there
		// is swapped with the value at i
		if( lst.at(i) < pivot)	{
			index++;
			temp = lst.at(index);
			lst.at(index) = lst.at(i);
			lst.at(i) = temp;
		}
	}
	
	// Swap pivot with value at new index
	temp = lst.at(0);
	lst.at(0) = lst.at(index);
	lst.at(index) = temp;
	
	// Sort partitions of vector
	quickSort(lst, 0, index - 1);
	quickSort(lst, index + 1,(int)lst.size() - 1);
	
	return lst;
	
}


