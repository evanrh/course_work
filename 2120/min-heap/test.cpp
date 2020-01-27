#include <vector>
#include <iostream>
#include <random>
#include "minHeap.h"
using namespace std;

int main()	{

vector<int> input;
vector<int> heapTest;
for (int i=1000000; i > 0; i--) input.push_back(i);

minHeap h(input);

for (int i=0; i<1000000; i++)

{

	  heapTest.push_back(h.removeMin());
	  //cout << heapTest[i] << " ";

}
cout << endl;
}
