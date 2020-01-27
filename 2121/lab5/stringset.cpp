/*
 * Evan Hastings
 * 10/01/19
 * 2121-001
 * Lab 5: Spell Checker Using a Hash Table
 */

#include "stringset.h"
#include <iostream>

Stringset::Stringset() : table(4), num_elems(0), size(4) {}

//Used in test cases and testStringset() in main.cpp, do not modify
vector<list<string>> Stringset::getTable() const
{
    return table;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getNumElems() const
{
    return num_elems;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getSize() const
{
    return size;
}

// Function to put a string into the table if it does not already
// Belong to the set
void Stringset::insert(string word)
{
	// Check for word's existence in table
	if(this->find(word))
		return;
	
	// Find hash index
	hash<string> strHash;
	int index = strHash( word ) % this->size;
	
	// Place word in hased index and increment
	table[index].push_back(word);
	num_elems++;
	
	// Table size increase for efficiency
	if( num_elems == size )	{
		size *= 2;
		vector< list< string >> updated( size );
		
		// Loop through all lists in table
		for(auto iter : table)	{

			// Loop through all strings in list
			for(auto elem : iter)	{
				index = strHash( elem ) % size;
				updated[index].push_back( elem );
			}
		}

		// Resize and reassign of table to new larger table
		table.resize( size );
		table.swap(updated);
	}
}

// Function to determine if a word exists in the set
bool Stringset::find(string word) const
{

	// Hash index
	hash<string> strHash;
	int index = strHash(word) % size;

	// Loop through all strings in list at hash index
	for(auto elem : table[index])	{

		// Word is found
		if(elem.compare(word) == 0)
			return true;
	}
	
	// Word is not found
	return false;
}

// Function to remove a string from the table if it is in the table
void Stringset::remove(string word)
{
	
	// Hash index
	hash<string> strHash;
	int index = strHash( word ) % this->size;
	
	// Loop through all strings in list at hash index
	for(auto elem : table[index])	{

		// Word is found
		if(word.compare( elem.data() ) == 0)	{
			table[index].remove(word);
			num_elems--;
			return;
		}
	}
}
