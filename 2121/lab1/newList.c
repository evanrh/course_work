/*
 * Name:
 * Date Submitted:
 * Lab Section:
 * Assignment Name:
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
	start = nullptr;
	mySize = 0;
}

//Destroy all nodes in this list to prevent memory leaks
template <class T>
List<T>::~List(){
	Node<T> * temp = start;

	while(temp)	{
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
	if(start == nullptr)
		return true;
	else
		return false;
}

//Create a new node with value, and insert that new node
//into this list at start
template <class T>
void List<T>::insertStart(T value){

	if(this->empty())
		start = new Node<T>(value);

	else	{
		Node<T> * temp = start;
		start = new Node<T>(value);
		start->next = temp;
	}
	mySize += 1;
}

//Create a new node with value, and insert that new node
//into this list at end
template <class T>
void List<T>::insertEnd(T value){
	if(this->empty())
		start = new Node<T>(value);

	else	{
		Node<T> * temp = start;

		while(temp->next)
			temp = temp->next;
		
		temp->next = new Node<T>(value);
	}
	mySize += 1;
}

//Create a new node with value <value>, and insert that new node at position j
template <class T>
void List<T>::insertAt(T value, int j){
	Node<T> * temp = start;
	
	if(j == 0)	{
		temp = new Node<T>(value);
		temp->next = start;
		start = temp;
	}

	else	{
		for(int i = 1; i < j; i++)
			temp = temp->next;

		Node<T> * newNode = new Node<T>(value);
		newNode->next = temp->next;
		temp->next = newNode;

	}
	mySize += 1;
}

//Remove node at start
//Make no other changes to list
template <class T>
void List<T>::removeStart(){
	Node<T> * temp = nullptr;
	if(start->next)	{
		temp = start->next;
		delete start;
		start = temp;
	}

	else
		delete start;
	
	mySize -= 1;
}

//Remove node at end
//Make no other changes to list
template <class T>
void List<T>::removeEnd(){
	Node<T> * temp = start;

	while(temp->next)
		temp = temp->next;
	
	delete temp;
	mySize -= 1;
}

//Remove node at position j
//Make no other changes to list
template <class T>
void List<T>::removeAt(int j){
	Node<T> * temp = start;

	for(int i = 1; i < j; i++)
		temp = temp->next;
	
	Node<T> * holder = temp->next;
	temp->next = temp->next->next;
	delete holder;
	mySize -= 1;
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

	while(temp->next)
		temp = temp->next;
	
	return temp->value;
}

//Return the value of the node at position j in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getAt(int j){
	Node<T> * temp = start;

	for(int i = 1; i < j; i++)
		temp = temp->next;
	
	return temp->next->value;
}

//Return the position of the (first) node whose value is equal to the key
//Otherwise, return -1
template <class T>
int List<T>::find(T key){
	Node<T> * temp = start;
	int loc = 0;

	while(temp->value != key)	{
		temp = temp->next;
		loc += 1;
	}

	return loc;

}
