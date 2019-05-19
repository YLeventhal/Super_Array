#pragma once

template<class T>
class SuperArray
{
private:
	TNode<T>* m_pHead = nullptr;
	int m_nNumOfElements = 0;
	int m_nLowestIndex = 0;
	int m_nHighestIndex = 0;

public:
	SuperArray() {};
	~SuperArray() {};

	TNode<T>& operator[](int);
	int operator = (int);
	SuperArray<T>& operator=(const SuperArray<T>&);
	const int num_elements()const;
	const int lowest_index()const;
	const int highest_index()const;
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
		m_nLowestIndex = index;
		m_nHighestIndex = index;
		return *m_pHead;
	}
	// check if the given index already exists. If yes, return that node and the overloaded node operator= will overwrite the data
	// if not, iterate through the list till we reach the last node and add new node after that
	else 
	{
		temp = m_pHead;
		while (temp != nullptr)
		{
			if (temp->GetIndex() == index)
			{
				return *temp;
			}
			
			temp = temp->GetNext();
			
		}
		temp = new TNode<T>(index);
		m_nNumOfElements++;
		return *temp;
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

