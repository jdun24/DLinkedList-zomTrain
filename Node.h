#ifndef NODE_H
#define NODE_H

#include<iostream>

template<typename T>
class Node
{

	
    public:

    Node(T da){
		data = da;
	}

	T data;
    Node<T>* next;
	Node<T>* prev;
};

#endif