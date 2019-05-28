#pragma once
#include <string>
#include <iostream>
#include "TNode.h"


template<class T>
class SuperArray
{
private:
	TNode<T>* m_pHead = nullptr;
	int m_nNumOfElements = 0;
	int m_nLowestIndex = 10000000;
	int m_nHighestIndex = -10000000;

public:
	SuperArray() {
		//std::cout << "called superarrays def constructor op\n";
	};
	~SuperArray() {};

	TNode<T>* GetHead()const { return m_pHead; }
	TNode<T>& operator[](const int index);
	SuperArray<T>& operator=(const SuperArray<T>&);

	//to use const here for the returned value is meaningless b/c.. what is returned is just a copy of the value. 
	// the necessary usage of this kind of const is when you return a reference and dont want the actual value of the member it is 
	// referencing changed
	/*const*/ int num_elements()const;
	 int lowest_index()const;
	 int highest_index()const;

	void remove(int index);
	void remove();
	void DeleteRec(TNode<T>* node);
	void AdjIndexRecord(int index);
	bool Empty();
	void PntrToFunc(void(*ptrfunc)(T));
};



template<class T>
void SuperArray<T>::AdjIndexRecord(int index)
{
	int newHighestIndex = -10000000;
	int newLowestIndex = 10000000;

	TNode<T>* temp;

	// Deleted the node with the highest index
	if (this->m_nHighestIndex == index)
	{
		temp = m_pHead;
		while (temp->GetNext() != nullptr)
		{
			if (temp->GetIndex() > newHighestIndex)
			{
				newHighestIndex = temp->GetIndex();
			}
			temp = temp->GetNext();
		}
		if (temp->GetIndex() > newHighestIndex)
		{
			newHighestIndex = temp->GetIndex();
		}
		this->m_nHighestIndex = newHighestIndex;
	}
	if (this->m_nLowestIndex == index)
	{
		temp = m_pHead;
		while (temp->GetNext() != nullptr)
		{
			if (temp->GetIndex() < newLowestIndex)
			{
				newLowestIndex = temp->GetIndex();
			}
			temp = temp->GetNext();
		}
		if (temp->GetIndex() < newLowestIndex)
		{
			newLowestIndex = temp->GetIndex();
		}
		this->m_nLowestIndex = newLowestIndex;
	}
}

template<class T>
bool SuperArray<T>::Empty()
{
	return  (m_pHead == nullptr) ? true : false;
}

template<class T>
void SuperArray<T>::remove(int index)
{
	TNode<T>* current;
	TNode<T>* previous;
	TNode<T>* toDelete;
	
	bool deleted = false;
	
	// If the array is not empty...
	if (!Empty())
	{
		// If the index is the first in the list, store its address in toDelete, point head to next node and delete the node
		if (m_pHead->GetIndex() == index)
		{
			toDelete = m_pHead;
			this->m_pHead = m_pHead->GetNext();
			delete toDelete;
			deleted = true;
		}
		else// The index is not the first, therfor search the list to see if it exists

		{
			current = m_pHead->GetNext();
			previous = m_pHead;
			while (current != nullptr)
			{
				// If it exists, store its address in toDelete, point previous to next node and delete the current node
				if (current->GetIndex() == index)
				{
					toDelete = current;
					previous->SetNext(current->GetNext());
					delete toDelete;
					deleted = true;
					break;
				}
				// Moving pointers over to next node
				previous = current;
				current = current->GetNext();
			}
		}
		// If deleted only node
		if (Empty())
		{
			m_nNumOfElements = 0;
			m_nHighestIndex = -10000000;
			m_nLowestIndex = 10000000;
		}
		else if (deleted)// deleted something and there are still more nodes in the array
		{
			m_nNumOfElements--;
			this->AdjIndexRecord(index);
		}
	}
}

template<class T>
void SuperArray<T>::remove()throw(std::string)
{
	// If Array is not empty, delete the list, null the head pointer, and reset the counter values
	if (m_pHead != nullptr)
	{
		DeleteRec(m_pHead);
		m_pHead = nullptr;
		m_nNumOfElements = 0;
		m_nHighestIndex = -10000000;
		m_nLowestIndex = 10000000;
	}
	/*else// Array is empty , therfor throw an exception
	{
		std::string error = "The Array is empty!";
		throw error;
	}*/
}

// Receives a function pointer, that itself receives an object from the array list, and calls the functioin on each object
template<class T>
void SuperArray<T>::PntrToFunc(void(*ptrfunc)(T))
{
	TNode<T>* temp = m_pHead;
	if (temp != nullptr)
	{
		while (temp != nullptr)
		{
			ptrfunc(temp->GetData());
			temp = temp->GetNext();
		}
	}
	else { cout << "empty list"; }
}

//Can alternatively return T& and then won't need toverload the operator= of CNode
template<class T>
TNode<T>& SuperArray<T>::operator[](const int index)
{
	//std::cout << "called superarrays[] op\n";
	TNode<T>* temp;
	int currentHighestIndex = m_nHighestIndex;
	int lowestCurrentIndex = m_nLowestIndex;

	if (index > m_nHighestIndex)
		m_nHighestIndex = index;
	if (index < m_nLowestIndex)
		m_nLowestIndex = index;

	// No nodes in the list therefor add new node at head
	if (m_pHead == nullptr)
	{
		m_pHead = new TNode<T>(index);
		m_nNumOfElements++;
		return *m_pHead;
	}
	// check if the given index already exists. If yes, return that node and the overloaded node operator= will overwrite the data
	// if not, iterate through the list till we reach the last node and add new node after that
	else 
	{
		temp = m_pHead;
		while (temp->GetNext() != nullptr)
		{
			if (temp->GetIndex() == index)
			{
				return *temp;
			}
			
			temp = temp->GetNext();
		}
		// the loop checks up to but not inc the last node, therfor we need to check it out of the loop
		if (temp->GetIndex() == index)
		{
			return *temp;
		}
		else
		{
			temp->SetNext(new TNode<T>(index)) ;
			m_nNumOfElements++;
			return *temp->GetNext();
		}
	}
}



template<class T>
SuperArray<T>&  SuperArray<T>::operator=(const SuperArray<T>& other)
{
	//std::cout << "called super arrays  =op  (superarray)\n";
	this->m_nNumOfElements = other.num_elements();
	this->m_nHighestIndex = other.highest_index();
	this->m_nLowestIndex = other.lowest_index();

	TNode<T>* hostArrayNode = this->m_pHead;
	TNode<T>* otherArrayNode = other.GetHead();
	TNode<T>* previous = nullptr;

	//Erase all current nodes that exist (if there are any) in the assigned to array
	this->remove();

	// Iterate through the list of the other array and copy the details to our array
	while (otherArrayNode != nullptr)
	{
		// Will enter here if we are creating the first node in the list (this condition will always 
		// be true for the first iteration..its here for the rest of the iterations)
		if (hostArrayNode == this->m_pHead)
		{
			hostArrayNode = new TNode<T>(otherArrayNode->GetIndex());
			*hostArrayNode = *otherArrayNode;
			this->m_pHead = hostArrayNode;
			previous = hostArrayNode;
			hostArrayNode = nullptr;
		}
		// Creating the rest of the nodes
		else
		{
			previous->SetNext(new TNode<T>(otherArrayNode->GetIndex()));
			previous = previous->GetNext();
			*previous = *otherArrayNode;
		}
		otherArrayNode = otherArrayNode->GetNext();
	}
	return *this;
}


template<class T>
int SuperArray<T>::num_elements()const
{
	return m_nNumOfElements;
}

template<class T>
int SuperArray<T>::lowest_index()const
{
	return m_nLowestIndex;
}

template<class T>
int SuperArray<T>::highest_index()const
{
	return m_nHighestIndex;
}

template<class T>
void SuperArray<T>::DeleteRec(TNode<T>* node)
{
	// Recurse to end of list
	if (node == nullptr)
	{
		return;
	}
	else
	{
		DeleteRec(node->GetNext());
	}
	// Backtrack and delete each node along the way
	delete node;
}