#pragma once

#ifndef DLIST_H
#define DLIST_H

#include <iostream>
#include <cstdlib>	//required to rand()
#include <ctime>
#include "zombie.h"
#include "Node.h"
using namespace std;


template<typename T> 
class dlist
{
	private:
	Node<T>* head;
	
	Node<T>* getNewNode(T data){
		Node<T>* newNode = new Node<T>(data);
		//newNode->data = z;
		newNode->next = NULL;
		newNode->prev = NULL;
		return newNode;
	}		
	public:
	dlist(){
		head = NULL;
	}	
	
	//Forward Decs
	~dlist();
	void printList();
	void print_reverse();
	void addToFront(T data); // Final should not be int
	void addToEnd(T data); // Final should not be int
	void addAtIndex(T data, int index);
	void addBefore(Node<T>* find, T data);
	void addAfter(Node<T>* find, T data);
	T removeFromFront();
	int length();
	T removeFromEnd();
	void removeTheFirst(T data);
	void removeAllOf(T data);
	int removeBefore(Node<T>* find);
	int removeAfter(Node<T>* find);
	bool elementExists(T data);
	Node<T>* Find(T data);
	int indexOf(T data);
	int retrieveFront();
	int retrieveEnd();
	T retrieve(int index);
	void empty();
	void deleteNode(Node<T>* tempHead, Node<T>* del);
	Node<T>* getHead();
};

template<typename T> void dlist<T>::addToFront(T data){
	Node<T>* temp = getNewNode(data);
	if (head == NULL){
			head = temp;
			return;
	}
	head->prev = temp;
	temp->next = head;
	head = temp;
}

template<typename T> void dlist<T>::addToEnd(T data){
	Node<T>* temp = getNewNode(data);
	if (head == NULL){
			head = temp;
			return;
	}
	Node<T>* t = head;
	while (t->next != NULL)
	{
		t = t->next;
	}
	t->next = temp;
	temp->prev = t;
}

template<typename T> void dlist<T>::printList(){
	Node<T>* temp = head;
	cout << "List Size: ";
	cout << to_string(length());
	cout << " :: ";
	while (temp != NULL){
		cout << " ["<< temp->data.getColor() << "] ";
		temp = temp->next;
	}
	cout << "\n";
}

template<typename T> void dlist<T>::print_reverse(){
	Node<T>* t = head;
	while (t->next != NULL){
		t = t->next;
	}
	while (t != NULL){
		cout << t->data << " ";
		t = t->prev;
	}
	cout << "\n";
}

template<typename T> void dlist<T>::addAtIndex(T data, int index){
	if(index > length() || index < 0){
		cout << "ERROR :- addAtIndex tried adding Out Of Bounds!\n";
		return;
	}

	Node<T>* t = head;
	Node<T>* newNode = getNewNode(data);
	newNode->next = NULL;
  	newNode->prev = NULL;
	for (int i = 0; i < index - 1; i++)
	{
		if(newNode != NULL) {
        	t = t->next;
      	}
	}
	
	if(t != NULL) {
      	newNode->next = t->next;
      	newNode->prev = t;
      	t->next = newNode;
      	if(newNode->next != NULL){
      		//newNode->next->prev = newNode; 
			newNode->next->prev = newNode; 
	  	}
    } 
}

template<typename T> T dlist<T>::removeFromFront(){
	if(head == NULL){
		cout << "Nothing to remove! ERROR # -: ";
		return 0;
	}
	Node<T>* temp = head;
	head = head -> next;
	delete temp;
	return temp->data;
}

template<typename T> T dlist<T>::removeFromEnd(){
	Node<T>* temp = head;
	while(temp->next->next != NULL){
		temp = temp->next;
	}
	Zombie re = temp->data;	//to save the val inside
	
	Node<T>* last = temp->next;
	temp->next = NULL;
	delete(last);
	return re;
}

template<typename T> void dlist<T>::removeTheFirst(T data){
	Node<T>* temp = head;
	if(head == NULL){
		cout << "Nothing To Remove! ERROR";
		return;
	}else if(head->data == data){
		head=head->next;
		delete temp;
		return;
	}

	while(temp != NULL){
		if(temp->data == data){
			deleteNode(head, temp);
			return;
		}
		temp = temp->next;
	}
}

template<typename T> void dlist<T>::deleteNode(Node<T>* tempHead, Node<T>* del){

    if (tempHead == NULL || del == NULL){
		cout<< "ERROR -: NULL ARGS GIVEN!";
        return;
	}
    if (tempHead == del){	//Makes sure its not the head
        tempHead = del->next;
	}
    if (del->next != NULL){		//Checks its not last
        del->next->prev = del->prev;
	}
    if (del->prev != NULL){		//Checks its not first
        del->prev->next = del->next;
	}
    free(del);
}

template<typename T> void dlist<T>::removeAllOf(T data){
	Node<T>* curr = head;
	Node<T>* next;
	if(head == NULL){
		cout << "Nothing To Remove! ERROR\n";
		return;
	}

	while(curr != NULL){
		if(curr->data == data){
			next = curr->next;
			deleteNode(head, curr);
			curr = next;
		}else{
			curr = curr->next;
		}
	}
}

template<typename T> int dlist<T>::removeBefore(Node<T>* find){
	Node<T>* curr = head;
	int val;
	while(curr->next != find){
		curr = curr->next;
	}	//curr is now one before the node we looked for
	val = curr->data;
	deleteNode(head, curr);
	return val;
}

template<typename T> int dlist<T>::removeAfter(Node<T>* find){
	Node<T>* curr = head;
	int val;
	while(curr->next != find){
		curr = curr->next;
	}	
	if(curr->next->next != NULL){
		curr = curr->next->next;//curr is now one after the node we looked for
	}else{
		cout << "removeAfter ERORR -: Tried Removing a node that does not exist\n";
	}
	val = curr->data;
	deleteNode(head, curr);
	return val;
}

template<typename T> int dlist<T>::length(){
	Node<T>* temp = head;
	int length = 0;
	while(temp != NULL){
		temp = temp-> next;
		length++;
	}
	delete temp;
	return length;
}

template<typename T> bool dlist<T>::elementExists(T data){
	Node<T>* temp = head;
	for(int i = 0; i < length(); i++){
		if(temp->data == data){
			return true;
		}else{
			temp = temp-> next;
		}
	}
	return false;
}

template<typename T> int dlist<T>::retrieveFront(){
	return head->data;
}

template<typename T> int dlist<T>::retrieveEnd(){
	Node<T>* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	return temp->data;
}

template<typename T> int dlist<T>::indexOf(T data){
	Node<T>* temp = head;
	int index = 0;
	
	while(temp->next != NULL){
		if(temp->data == data){
			return index;
		}else{
			temp = temp->next;
		}
		index++;
	}
	cout << "ERROR -: Could not find node!! Returning 0";
	return 0;
}

template<typename T> T dlist<T>::retrieve(int index){
	Node<T>* temp = head;
	if(index > 0 && index < length()){	//Is index in bounds?
		for(int i = 0; i < index; i++){
			temp = temp->next;
		}
	}else if(index == 0){
		return temp->data;
	}else{
		//cout << "ERROR -: Index Out Of Bounds! Returning 0";
		return NULL;
	}
	return temp->data;
}

template<typename T> Node<T>* dlist<T>::Find(T data){
	Node<T>* temp = head;
	while(temp->next != NULL){
		if(temp->data == data){
			return temp;
		}else{
			temp = temp->next;
		}
	}
	//cout << "ERROR -: Could not find node!!  Returning last node instead";
	return NULL;
}

template<typename T> void dlist<T>::addBefore(Node<T>* find, T data){
	Node<T>* temp = head;
	int index = 0;
	while(temp->next != NULL){
		if(temp->data == find->data){
			addAtIndex(data, index);
			return;
		}
		temp = temp->next;
		index++;	// we can use to add at index
	}
	cout << "ERROR -: Element Not Found\n";
}

template<typename T> void dlist<T>::addAfter(Node<T>* find, T data){
	Node<T>* temp = head;
	int index = 0;
	while(temp->next != NULL){
		if(temp->data == find->data){
			index = index + 1;
			addAtIndex(data, index);
			return;
		}
		temp = temp->next;
		index++;	// we can use to add at index
	}
	cout << "ERROR -: Element Not Found\n";
}

template<typename T> dlist<T>::~dlist(){
	Node<T>* temp = head;
	while(head->next != NULL){
		head = head->next;
		delete temp;
		temp = head;
	}
	
}

template<typename T> Node<T>* dlist<T>::getHead(){
	return head;
}
#endif