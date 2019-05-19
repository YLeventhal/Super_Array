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
	SuperArray() {};
	~SuperArray() {};

	TNode<T>& operator[](int);
	int operator = (int);
	SuperArray<T>& operator=(const SuperArray<T>&);
	const int num_elements()const;
	const int lowest_index()const;
	const int highest_index()const;
	TNode<T>* GetHead() { return m_pHead; }
};

template<class T>
TNode<T>& SuperArray<T>::operator[](int index)
{
	TNode<T>* temp;

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

}


template<class T>
SuperArray<T>&  SuperArray<T>::operator=(const SuperArray<T>&)
{


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
	return highest_index;
}

