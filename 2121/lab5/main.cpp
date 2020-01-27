/*
 * Evan Hastings
 * 10/01/19
 * 2121-001
 * Lab 5: Spell Check Using a Hash Table
 */
 
 #include "stringset.h"
 #include <iostream>
 #include <fstream>
 
 void testStringset(Stringset& words);
 void loadStringset(Stringset& words, string filename);
 vector<string> spellcheck(const Stringset& words, string word);
 
 int main()
 {
     Stringset wordlist;
     testStringset(wordlist);
     return 0;
 }
 
 void testStringset(Stringset& words)
 {
     string choice;
     string word;
     do
     {
         cout << "I: insert word" << endl;
         cout << "F: find word" << endl;
         cout << "R: remove word" << endl;
         cout << "P: print words in stringset" << endl;
         cout << "Q: quit" << endl;
         cin >> choice;
         switch (choice[0])
         {
             case 'I':
             case 'i':
                cout << "Enter word to insert: ";
                cin >> word;
                words.insert(word);
                break;
             case 'F':
             case 'f':
                cout << "Enter word to find: ";
                cin >> word;
                if (words.find(word))
                {
                    cout << word << " in stringset" << endl;
                }
                else
                {
                    cout << word << " not in stringset" << endl;
                }
                break;
             case 'R':
             case 'r':
                cout << "Enter word to remove: ";
                cin >> word;
                words.remove(word);
                break;
             case 'P':
             case 'p':
                vector<list<string>> t = words.getTable();
                int numWords = words.getNumElems();
                int tSize = words.getSize();
                for(int i=0; i<tSize; ++i)
                {
                    list<string>::iterator pos;
                    for (pos = t[i].begin(); pos != t[i].end(); ++pos)
                    {
                        cout << *pos << endl;
                    }
                }
                cout << "Words: " << numWords << endl;
         }
     } while (choice[0] != 'Q' && choice[0] != 'q');
 }

 // Function to load words from a file into the String set
 void loadStringset(Stringset& words, string filename)
 {
	ifstream input(filename, ifstream::in);
	string current;
	
	// Loop through all lines in input file
	while( getline(input, current))
		words.insert( current );

	input.close();
 }
 
 // Function to find all words in set that are one character away from word
 vector<string> spellcheck(const Stringset& words, string word)
 {
	string newWord;
	vector<string> output;
	
	// Loop through all letters in word
	for(auto i = 0; i < word.length(); i++)	{

		// Loop through all letters of alphabet
		for(char j = 'a'; j <= 'z'; j++)	{
			newWord = word.data();
			newWord[i] = j;
			
			// Throw out current word if it is the same as the input
			if( newWord == word )
				continue;
			
			// Check for word existing in the set
			else if(words.find( newWord ))
				output.push_back( newWord );

		}
	}
	
	// Return vector of all words found that meet aforementioned conditions
	return output;
 }
