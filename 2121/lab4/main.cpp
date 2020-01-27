#include <iostream>
#include "Searches.h"
#include "Sorts.h"
using namespace std;

int main(void)	{
	
	vector<int> my = {1, 3, 56, 72, 99, 100, 153, 172};
	
	vector<int> me = {4, 1, 2, 45, 7, 86, 3};

	cout << binarySearch(my, 172) << endl;
	
	cout << "Original vec: ";

	for(auto iter:me)
		cout << iter << " ";
	cout << endl;
	me = quickSort(me);

	cout << "Sorted vec: ";
	for(auto iter:me)
		cout << iter << " ";

	cout << endl;
	return 0;
}
