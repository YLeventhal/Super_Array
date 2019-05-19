#pragma once
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
		std::cout << "called superarrays def constructor op\n";
	};
	~SuperArray() {};

	TNode<T>* GetHead()const { return m_pHead; }
	TNode<T>& operator[](const int index);
	int operator = (int);
	SuperArray<T>& operator=(const SuperArray<T>&);

	const int num_elements()const;
	const int lowest_index()const;
	const int highest_index()const;
	void remove(int index);
	void remove();
	void PntrToFunc(void(*ptrfunc)(T& obj));
};

template<class T>
void SuperArray<T>::remove(int index)
{
	TNode<T>* current;
	TNode<T>* previous;
	TNode<T>* toDelete;


	// If the index is the first in the list, store its address in toDelete, point head to next node and delete the node
	if (m_pHead->GetIndex() == index)
	{
		if (this->m_nHighestIndex == index)
		{
			m_nHighestIndex = m_pHead->GetHighestPreIndex();
		}
		toDelete = m_pHead;
		m_pHead = m_pHead->GetNext();
		delete toDelete;
		m_nNumOfElements--;
	}

	current = m_pHead->GetNext();
	previous = m_pHead;
	// The index is not the first, therfor search the list to see if it exists
	while (current != nullptr)
	{
		// If it exists, store its address in toDelete, point previous to next node and delete the current node
		if (current->GetIndex() == index)
		{
			toDelete = current;
			previous->GetNext() = current->GetNext();
			delete toDelete;
			return;
		}
		// Moving pointers over to next node
		previous = current;
		current = current->GetNext();
	}
}

template<class T>
void SuperArray<T>::remove()
{
	// If Array is not empty, delete the list and null the head pointer
	if (m_pHead != nullptr)
	{
		delete m_pHead;
		m_pHead = nullptr;
		m_nNumOfElements = 0;
		m_nHighestIndex = -10000000;
		m_nLowestIndex = 10000000;
	}
	else// Array is empty , therfor throw an exception
	{
		throw "The Array is empty!";
	}
}

// Receives a function pointer, that itself receives an object from the array list, and calls the functioin on each object
template<class T>
void SuperArray<T>::PntrToFunc(void(*ptrfunc)(T& obj))
{
	TNode<T>* temp = m_pHead;

	while (temp != nullptr)
	{
		ptrfunc(temp->GetData());
		temp = temp->GetNext();
	}
}

template<class T>
TNode<T>& SuperArray<T>::operator[](const int index)
{
	std::cout << "called superarrays[] op\n";
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
		m_pHead = new TNode<T>(index, currentHighestIndex, lowestCurrentIndex);
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
			(temp->GetNext()) = new TNode<T>(index);
			m_nNumOfElements++;
			return *temp->GetNext();
		}
	}
}

template<class T>
int SuperArray<T>::operator=(int)
{
	std::cout << "called super arrays  =op  (int)\n";

}


template<class T>
SuperArray<T>&  SuperArray<T>::operator=(const SuperArray<T>& other)
{
	std::cout << "called super arrays  =op  (superarray)\n";
	this->m_nNumOfElements = other.num_elements();
	this->m_nHighestIndex = other.highest_index();
	this->m_nLowestIndex = other.lowest_index();

	TNode<T>* hostArray = this->m_pHead;
	TNode<T>* otherArray = other.GetHead();
	TNode<T>* previous = nullptr;

	while (otherArray != nullptr)
	{
		// If we are creating the first node in the list
		if (hostArray == this->m_pHead)
		{
			hostArray = new TNode<T>(otherArray->GetIndex());
			*hostArray = *otherArray;
			this->m_pHead = hostArray;
			previous = hostArray;
			hostArray = nullptr;
		}
		// Creating the rest of the nodes
		else
		{
			previous->GetNext() = new TNode<T>(otherArray->GetIndex());
			previous = previous->GetNext();
			*previous = *otherArray;
		}
		otherArray = otherArray->GetNext();
	}
	return *this;
}


template<class T>
const int SuperArray<T>::num_elements()const
{
	return m_nNumOfElements;
}

template<class T>
const int SuperArray<T>::lowest_index()const
{
	return m_nLowestIndex;
}

template<class T>
const int SuperArray<T>::highest_index()const
{
	return m_nHighestIndex;
}

