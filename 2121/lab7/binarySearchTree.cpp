/*
 * Evan Hastings
 * 10/25/19
 * 2121-001
 * Lab 7: Binary Search Tree
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <assert.h>

using namespace std;

struct Node {
  int key;
  int size;
  Node *left;
  Node *right;
  Node (int k) { key = k; size = 1; left = right = nullptr; }
};

Node * newRoot(Node *, int);
Node *insert_random(Node*,int);

void fix_size(Node *T)
{
	if(T == nullptr) return;
	T->size = 1;
	if (T->left) T->size += T->left->size;
	if (T->right) T->size += T->right->size;
}

// insert key k into tree T, returning a pointer to the resulting tree
Node *insert(Node *T, int k)
{
  if (T == nullptr) return new Node(k);
  if (k < T->key) T->left = insert(T->left, k);
  else T->right = insert(T->right, k);
  fix_size(T);
  return T;
}

// returns a vector of key values corresponding to the inorder traversal of T (i.e., the contents of T in sorted order)
vector<int> inorder_traversal(Node *T)
{
  vector<int> inorder;
  vector<int> rhs;
  if (T == nullptr) return inorder;
  inorder=inorder_traversal(T->left);
  inorder.push_back(T->key);
  rhs=inorder_traversal(T->right);
  inorder.insert(inorder.end(), rhs.begin(), rhs.end());
  return inorder;
}

// return a pointer to the node with key k in tree T, or nullptr if it doesn't exist
Node *find(Node *T, int k)
{
	// T does not exist
	if(T == nullptr)
		return nullptr;
	
	// T contains the key of interest
	if(T->key == k)
		return T;

	// key is right of T
	if(T->key < k) return find(T->right,k);
	
	// key is left of T
	else return find(T->left,k);
	
}

// return pointer to node of rank r (with r'th largest key; e.g. r=0 is the minimum)
Node *select(Node *T, int r)
{
	//assert(T!=nullptr && r>=0 && r<T->size);

	// Rank = left->size only when that exists. Elswise it is 0
	int rank = T->left == nullptr ? 0 : T->left->size;

	// newRank is r -rank -1 when the position is to the right of rank
	int newRank = rank < r ? r - rank - 1 : r;

	// r is on the right of current position
	if(rank < r)
		return select(T->right,newRank);

	// r is on the left of current position
	else if (rank > r)	
		return select(T->left,newRank);

	// T is the rank
	else
		return T;
}

// Join trees L and R (with L containing keys all <= the keys in R)
// Return a pointer to the joined tree.  
Node *join(Node *L, Node *R)
{
	// choose either the root of L or the root of R to be the root of the joined tree
	// (where we choose with probabilities proportional to the sizes of L and R)
	
	// If either tree is null, the other tree is just the result
	if(L == nullptr)
		return R;
	if(R == nullptr)
		return L;
	
	bool rootDet = (rand() % 100) <= (abs(L->size) / abs(L->size + R->size))*100;

	// rootDet = true -> L is root
	if(rootDet)	{
		L = insert_random(L,R->key);
		L = join(L,R->left);
		L = join(L,R->right);
		fix_size(L);
		return L;
	}

	else	{
		R = insert_random(R,L->key);
		R = join(L->left,R);
		R = join(L->right,R);
		fix_size(R);
		return R;
	}
	
}

// remove key k from T, returning a pointer to the resulting tree.
// it is required that k be present in T
Node *remove(Node *T, int k)
{
	//assert(T != nullptr);

	// T does not exist in tree
	Node *loc = find(T,k);
	if(loc == nullptr)
		return T;
	
	// key is greater than current key
	if(T->key < k)	{
		T->right = remove(T->right,k);
		fix_size(T);
		return T;
	}
	
	// key is less than current key
	else if(T->key > k)	{
		T->left = remove(T->left,k);
		fix_size(T);
		return T;
	}

	// current key is key of interest
	else	{
		Node *tempL = T->left;
		Node *tempR = T->right;
		T = join(tempL,tempR);
		fix_size(T);
		return T;
	}

}

// Split tree T on key k into tree L (containing keys <= k) and a tree R (containing keys > k)
void split(Node *T, int k, Node **L, Node **R)
{

	// Base case: parent node is a leaf
	if(T == nullptr)
		return;

	// Current node belongs to left tree
	else if(T->key <= k)
		*L = insert_random(*L,T->key);

	// Current node belongs to right tree
	else
		*R = insert_random(*R,T->key);

	split(T->right,k,L,R);
	split(T->left,k,L,R);

}


// insert key k into the tree T, returning a pointer to the resulting tree
Node *insert_random(Node *T, int k)
{
	// If k is the Nth node inserted into T, then:
	// with probability 1/N, insert k at the root of T
	// otherwise, insert_random k recursively left or right of the root of T
	
	// Tree not initialized yet
	if(T == nullptr) return new Node(k);

	bool prob = (rand() % (T->size + 1)) == 0;
	
	// 1/N chance occurs
	if(prob)	{
		return newRoot(T,k);
	}

	// Randomly insert k being greater than current key
	if(T->key < k)
		T->right = insert_random(T->right,k);

	// Randomly insert k being less than or equal to current key
	else
		T->left = insert_random(T->left,k);

	fix_size(T);
	return T;
  
	//Implement Node *insert_random(Node *T, int k)
}

// Function to rotate tree to the right
Node* rotateR(Node *T)	{
	Node *temp = T->left;
	if(temp == nullptr) return T;

	T->left = temp->right;
	temp->right = T;
	temp->size = T->size;
	fix_size(T);
	return temp;
}

// Function to rotate tree to the left
Node* rotateL(Node* T)	{
	
	Node *temp = T->right;
	if(temp == nullptr) return T;

	T->right = temp->left;
	temp->left = T;
	temp->size = T->size;
	fix_size(T);
	return temp;
}

// Function to create tree with new root
Node *newRoot(Node *T, int k)	{
	if(T == nullptr) return new Node(k);

	if(T->key < k)	{
		T->right = newRoot(T->right,k);
		return rotateL(T);
	}

	else	{
		T->left = newRoot(T->left,k);
		return rotateR(T);
	}
}

void printVector(vector<int> v)
{
    for (int i=0; i<v.size(); i++)
    {
        cout << v[i] << endl;
    }
}

int main(void)
{
  vector<int> inorder;
  vector<int> A(10,0);
  
  // put 0..9 into A[0..9] in random order
  for (int i=0; i<10; i++) A[i] = i;
  for (int i=9; i>0; i--) swap(A[i], A[rand()%i]);
  cout << "Contents of A (to be inserted into BST):\n";
  printVector(A);
  
  // insert contents of A into a BST
  Node *T = nullptr;
  for (int i=0; i<10; i++) T = insert(T, A[i]);
  
  // print contents of BST (should be 0..9 in sorted order)
  cout << "Contents of BST (should be 0..9 in sorted order):\n";
  inorder=inorder_traversal(T);
  printVector(inorder);

  // test select
  for (int i=0; i<10; i++) {
    Node *result = select(T, i);
    if (!result || result->key != i) cout << "Select test failed for select(" << i << ")!\n";
  }

  // test find: Elements 0..9 should be found; 10 should not be found
  cout << "Elements 0..9 should be found; 10 should not be found:\n";
  for (int i=0; i<11; i++) 
    if (find(T,i)) cout << i << " found\n";
    else cout << i << " not found\n";

  // test split
  Node *L = nullptr, *R = nullptr;
  split(T, 4, &L, &R);
  cout << "Contents of left tree after split (should be 0..4):\n";
  inorder=inorder_traversal(L);
  printVector(inorder);
  cout << "Left tree size " << L->size << "\n";
  cout << "Contents of right tree after split (should be 5..9):\n";
  inorder=inorder_traversal(R);
  printVector(inorder);
  cout << "Right tree size " << R->size << "\n";
    
  // test join
  T = join(L, R);
  cout << "Contents of re-joined tree (should be 0..9)\n";
  inorder=inorder_traversal(T);
  printVector(inorder);
  cout << "Tree size " << T->size << "\n";
  
  // test remove
  for (int i=0; i<10; i++) A[i] = i;
  for (int i=9; i>0; i--) swap(A[i], A[rand()%i]);
  for (int i=0; i<10; i++) {
    T = remove(T, A[i]);
    cout << "Contents of tree after removing " << A[i] << ":\n";
    inorder=inorder_traversal(T);
    printVector(inorder);
    if (T != nullptr)
      cout << "Tree size " << T->size << "\n";
  }

  // test insert_random
  cout << "Inserting 1 million elements in order; this should be very fast...\n";
  for (int i=0; i<1000000; i++) T = insert_random(T, i);
  cout << "Tree size " << T->size << "\n";
  cout << "Done\n";
  
  return 0;
}
