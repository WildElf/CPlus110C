//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Implementation file for the class LinkedList.
 @file LinkedList.cpp */

#include "LinkedList.h"  // Header file
#include <cassert>
#include <string>
#include <cstdlib>
#include <iostream>

// ************************************************
//  Constructors & Destructor
// ************************************************

// Default constructor
template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), tailPtr(nullptr), itemCount(0)
{
	headPtr = nullptr;
	tailPtr = nullptr;
	itemCount = 0;
}  // end default constructor

// Copy constructor
template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList) : itemCount(aList.itemCount)
{
	Node<ItemType>* origHeadPtr = aList.headPtr;  // Points to original chain head
	Node<ItemType>* origTailPtr = aList.tailPtr;  // Points to original chain tail

	if (origHeadPtr == nullptr && origTailPtr == nullptr) // Original list is empty
	{
		headPtr = nullptr;  
		tailPtr = nullptr;
	}
	else
	{
		// Copy first node
		headPtr = new Node<ItemType>();
		headPtr->setItem(origHeadPtr->getItem());

		// Copy last node
//		tailPtr = new Node<ItemType<();
//		tailPtr->setItem(origTailPtr>getItem());
		
		// Copy remaining nodes
		Node<ItemType>* newNextPtr = headPtr;		// Points to last node in new chain
		origHeadPtr = origHeadPtr->getNext();	  // Advance original-chain pointer
		while (origHeadPtr != nullptr)
		{
			// Get next item from original chain
			ItemType nextItem = origHeadPtr->getItem();
			
			// Create a new node containing the next item 
			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);  
			
			// Link new node to end of new chain
			newNextPtr->setNext(newNodePtr);
			
			// Advance pointer to new last node		
			newNextPtr = newNextPtr->getNext();
			
			// Advance original-chain pointer
			origHeadPtr = origHeadPtr->getNext();
		}  // end while
		
		newNextPtr->setNext(nullptr);				  // Flag end of chain
	}  // end if
}  // end copy constructor

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
	clear();
}  // end destructor

// ************************************************
//  Public Methods
// ************************************************
template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedList<ItemType>::getLength() const
{
	return itemCount;
}  // end getLength

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{

	bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
	if (ableToInsert)
	{
		itemCount++;  // Increase count of entries
		// Create a new node containing the new entry 
		Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);  

		if (newPosition == 1 && itemCount == 1)
		{
			// add the one and only
			tailPtr = headPtr = newNodePtr;
		}
		else if (newPosition == 1)
		{
			std::cout << "***Adding another first item\n";
			// set new entry at first position
			newNodePtr->setNext(headPtr); // get ahead of heatPtr
			headPtr->setPrev(newNodePtr); // set headPtr behind new node
			headPtr = newNodePtr; // become the new head
		}
		else if (newPosition == itemCount)
		{
			std::cout << "***Adding a last item\n";
			// set new entry at the last position
			newNodePtr->setPrev(tailPtr); // get behind tailPtr
			tailPtr->setNext(newNodePtr); // set tailPtr in front of new node
			tailPtr = newNodePtr; // become the new tail

		}
		else
		{
			std::cout << "***Adding a middle item";
	 	 
			Node<ItemType>* nextPtr = getNodeAt(newPosition);
			Node<ItemType>* prevPtr = getNodeAt(newPosition-1);

			newNodePtr->setNext(nextPtr); // new node inserted into position
			nextPtr->setPrev(newNodePtr); // old position points back to new node

			newNodePtr->setPrev(prevPtr); // new node inserted after previous position
			prevPtr->setNext(newNodePtr); // prev position points ahead to new node
			
		}
	}  // end if

	return ableToInsert;
}  // end insert

template<class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
	bool ableToRemove = (position >= 1) && (position <= itemCount);
	if (ableToRemove)
	{
		Node<ItemType>* curPtr = nullptr;
		if (position == 1)
		{
			// Remove the first node in the chain
			curPtr = headPtr; // Save pointer to node
			headPtr = headPtr->getNext();
			headPtr->setPrev(nullptr); // disconnect backwards connection
			
		}
		else if (position == itemCount)
		{
			// remove last node in the chain
			curPtr = tailPtr; // save pointer for clean up
			tailPtr = tailPtr->getPrev();
			tailPrt->setNext(nullptr); // disconnect foreward connection
		}
		else
		{
			// Find node that is before the one to delete
			Node<ItemType>* prevPtr = getNodeAt(position - 1);
			
			// Point to node to delete
			curPtr = prevPtr->getNext();
			
			// Disconnect indicated node from chain by connecting the
			// prior node with the one after
			prevPtr->setNext(curPtr->getNext());
			
		}  // end if
		
		// Return node to system
		curPtr->setNext(nullptr);
		delete curPtr;
		curPtr = nullptr;
		
		itemCount--;  // Decrease count of entries
	}  // end if
	
	return ableToRemove;
}  // end remove

template<class ItemType>
void LinkedList<ItemType>::clear()
{
	while (!isEmpty())
		remove(1);
}  // end clear

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const throw(PrecondViolatedExcep)
{

	// Enforce precondition
	bool ableToGet = (position >= 1) && (position <= itemCount);
	if (ableToGet)
	{

		Node<ItemType>* nodePtr = getNodeAt(position);
			
		return nodePtr->getItem();
	}
	else
	{
		string message = "getEntry() called with an empty list or "; 
		message  = message + "invalid position.";
		throw(PrecondViolatedExcep(message)); 
	}  // end if
}  // end getEntry

template<class ItemType>
void LinkedList<ItemType>::setEntry(int position, const ItemType& newEntry) throw(PrecondViolatedExcep)
{
	// Enforce precondition
	bool ableToSet = (position >= 1) && (position <= itemCount);
	if (ableToSet)
	{
		Node<ItemType>* nodePtr = getNodeAt(position);
		nodePtr->setItem(newEntry);
	}
	else
	{
		string message = "setEntry() called with an invalid position."; 
		throw(PrecondViolatedExcep(message)); 
	}  // end if
}  // end setEntry

// ************************************************
//  Private Methods
// ************************************************
template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
	// Debugging check of precondition
	assert( (position >= 1) && (position <= itemCount) );
	
	Node<ItemType>* curPtr = headPtr;
	
	curPtr = getNodeAtRecursive(position, curPtr);
			
	return curPtr;
}  // end getNodeAt

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAtRecursive(int position,
														 Node<ItemType>* curPtr) const
{
	if (position == 1)
	{
		return curPtr;
	}
	else
	{
		return getNodeAtRecursive(position-1, curPtr->getNext());
	}


}  // end getNodeAtRecursive

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::insertNode(int position,
												 Node<ItemType>* newNodePtr,
												 Node<ItemType>* subChainPtr)
{
	if (position == 1)
	{
		// Insert new node at beginning of subchain
		newNodePtr->setNext(subChainPtr);
		subChainPtr = newNodePtr;
		itemCount++;
	}
	else
	{
		Node<ItemType>* chainPtr = insertNode(position - 1, newNodePtr, 
												subChainPtr->getNext());
		subChainPtr->setNext(chainPtr);
	}
	
	return subChainPtr;
} // end insertNode


// End of implementation file.  To get this to compile on hills,
// add definitions of template types we will use (int or string now,
// add more types if necessary)
template class LinkedList<int>;
template class LinkedList<std::string>;
