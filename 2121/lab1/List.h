/*
 * Evan
 * 9/4/19
 * Section 1
 * Lab 1: List Stacks and Queues
 */

#pragma once

#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

//This class represents a linked list of node objects
//Do not modify anything in the class interface
template <class T>
class List{

 private:
  Node<T> * start; //pointer to the first node in this list
  int mySize;  //size (or length) of this list

 public:
  List();
  ~List();
  int size();
  bool empty();
  void insertStart(T);
  void insertEnd(T);
  void insertAt(T, int);
  void removeStart();
  void removeEnd();
  void removeAt(int);
  T getFirst();
  T getLast();
  T getAt(int);
  int find(T);

  //Print the name and this list's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name){
    cout << name << ": ";
    cout << "size = " << size();
    cout << ", values = ";
    Node<T> * iterator = start;
    while(iterator != nullptr){
      cout << iterator->value << ' ';
      iterator = iterator->next;
    }
    cout << endl;
  }

}; //end of class interface (you may modify the code below)

//Implement all of the functions below
//Construct an empty list by initializig this list's instance variables
template <class T>
List<T>::List(){

	// Initializes values to null and 0
	start = nullptr;
	mySize = 0;
}

//Destroy all nodes in this list to prevent memory leaks
template <class T>
List<T>::~List(){
	Node<T> * temp = start;
	
	// Loop through all elements of linked list
	while(temp != nullptr)	{
		start = temp->next;
		delete temp;
		temp = start;
	}
}

//Return the size of this list
template <class T>
int List<T>::size(){
	return mySize;
}

//Return true if this list is empty
//Otherwise, return false
template <class T>
bool List<T>::empty(){

	// mySize will only be 0 when no nodes are present
	if(mySize == 0)
		return true;
	else
		return false;
}

//Create a new node with value, and insert that new node
//into this list at start
template <class T>
void List<T>::insertStart(T value){
	
	// New node->next points to previous start location
	Node<T> * temp = start;
	start = new Node<T>(value);
	start->next = temp;
	
	// Increment size of list
	mySize++;
}

//Create a new node with value, and insert that new node
//into this list at end
template <class T>
void List<T>::insertEnd(T value){

	// If list is empty, node is placed at front
	if(this->empty())	{
		start = new Node<T>(value);
		start->next = nullptr;
	}
	
	// List is not empty
	else	{
		Node<T> * temp = start;
	
		// Loop to last node in list
		while(temp->next)
			temp = temp->next;
		
		// Addition of node to list
		temp->next = new Node<T>(value);
		temp->next->next = nullptr;
	}

	// List size increment
	mySize++;
}

//Create a new node with value <value>, and insert that new node at position j
template <class T>
void List<T>::insertAt(T value, int j){
	Node<T> * temp = start;
	
	// Condition for location being at start
	if(j == 0)
		this->insertStart( value );
	
	// location not at start
	else	{

		// Loop through to list position j
		for(int i = 1; i < j; i++)
			temp = temp->next;
	
		// Addition of node to list
		Node<T> * newNode = new Node<T>(value);
		newNode->next = temp->next;
		temp->next = newNode;

	}

	// List size increment
	mySize++;
}

//Remove node at start
//Make no other changes to list
template <class T>
void List<T>::removeStart(){
	Node<T> * temp = start;
	
	start = temp->next;
	delete temp;
	mySize--;
}

//Remove node at end
//Make no other changes to list
template <class T>
void List<T>::removeEnd(){
	Node<T> * temp = start;
	Node<T> * last = nullptr;
	
	// Loop through list to end
	while(temp->next != nullptr)	{
		last = temp;
		temp = temp->next;
	}
	
	// Delete end node and update pointer of previous element to null
	delete temp;
	last->next = nullptr;
	mySize -= 1;
}

//Remove node at position j
//Make no other changes to list
template <class T>
void List<T>::removeAt(int j){
	Node<T> * temp = start;
	
	// Check for start location
	if(j == 0)
		this->removeStart();
	
	else	{
		// Loop to position j of list
		for(int i = 1; i < j; i++)
			temp = temp->next;
	
		//  assign holder for last element and delete
		Node<T> * holder = temp->next;
		temp->next = temp->next->next;
		delete holder;
		mySize--;
	}
}

//Return the value of the first node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getFirst(){
	return start->value;
}

//Return the value of the last node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getLast(){
	Node<T> * temp = start;
	
	// Loop through to end of list
	while(temp->next)
		temp = temp->next;
	
	// Return last node of list
	return temp->value;
}

//Return the value of the node at position j in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getAt(int j){
	Node<T> * temp = start;
	
	// Loop through to list to position j
	for(int i = 1; i < j; i++)
		temp = temp->next;
	
	// Return element at position j
	return temp->next->value;
}

//Return the position of the (first) node whose value is equal to the key
//Otherwise, return -1
template <class T>
int List<T>::find(T key){
	Node<T> * temp = start;
	int loc = 0;
	
	// Loop through all nodes of list
	while(temp->value != key)	{

		// Check for end of list
		if(temp->next == nullptr)
			return -1;
		else	{
			temp = temp->next;
			loc += 1;
		}
	}
	
	// Returns position key was found at if key is found
	return loc;

}
