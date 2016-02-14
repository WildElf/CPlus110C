//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.
// E Jo Zimmerman - 110C - Assignment 3
// Creating a double linked list and reverse function

/** @file Node.h 
	 Listing 4-1 */
#ifndef _NODE
#define _NODE

template<class ItemType>
class Node
{
private:
	ItemType		item; // A data item
	Node<ItemType>* next; // Pointer to next node
	Node<ItemType>* prev; // Pointer to previous node
	
public:
	Node();
	Node(const ItemType& anItem);
	Node(const ItemType& anItem, Node<ItemType>* nextNodePtr, Node<ItemType>* prevNodePtr);
	void setItem(const ItemType& anItem);
	void setNext(Node<ItemType>*);
	void setPrev(Node<ItemType>*);
	ItemType getItem() const ;
	Node<ItemType>* getNext() const ;
	Node<ItemType>* getPrev() const ;
}; // end Node

#endif