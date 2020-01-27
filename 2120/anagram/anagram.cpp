/*
 * Evan Hastings
 * 10/19/19
 * Single Word Anagram Finder
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;

vector<string> loadWordlist(string filename);
void stringSort(string&);
vector<string> anagram(string word, vector<string> wordlist);

int main()
{
    vector<string> words;
    vector<string> anagrams;
    string inputWord;
    words=loadWordlist("wordlist.txt");
    cout << "Find single-word anagrams for the following word: ";
    cin >> inputWord;
    anagrams = anagram(inputWord, words);
    for (unsigned int i=0; i<anagrams.size(); i++)
    {
        cout << anagrams[i] << endl;
    }
    return 0;
}

vector<string> loadWordlist(string filename)
{
    vector<string> words;
    ifstream inFile;
    string word;
    inFile.open(filename);
    if(inFile.is_open())
    {
        while(getline(inFile,word))
        {
            if(word.length() > 0)
            {
                words.push_back(word);
            }
        }
        inFile.close();
    }
    return words;
}

vector<string> anagram(string word, vector<string> wordlist)
{

	unordered_map< string, vector<string>> wordDict;
	
	// Items in full list loop
	for( auto item : wordlist)	{
		string old = item;
		stringSort(item);
		wordDict[item].push_back(old);
	}

	stringSort(word);
	return wordDict[word];
}


// Function to sort string using insertion sort
void stringSort(string& input)	{
	
	for(unsigned int i = 0; i < input.length(); i ++)	{
		for(unsigned int j = 1; j < input.length(); j++)
			if(input[j] < input[i])	{
				char temp = input[i];
				input[i] = input[j];
				input[j] = temp;
			}
	}
}
