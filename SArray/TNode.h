#pragma once
#include <iostream>
using namespace std;

template<class T>
class TNode
{
private:
	int m_nIndex;
	mutable T m_tData;
	TNode<T>* m_pNext = nullptr;
public:
	TNode() {}
	TNode(int index) 
	{
		m_nIndex = index;
	}
	~TNode() {};

	TNode(const TNode<T>& other)
	{
		std::cout << "called TNodes copy constructor op\n";

		this->m_nIndex = other.GetIndex();
		this->m_tData = other.GetData();
	}

	TNode<T>& operator=(const T& data);
	TNode<T>& operator=(const TNode<T>& node);

	int GetIndex() { return m_nIndex; }
	T& GetData()const { return /*(const_cast<TNode*>(this))->*/m_tData; }
	TNode<T>* GetNext() { return m_pNext; }

	//void SetIndex(int index) { m_nIndex = index; }
	void SetData(T pData) { m_tData = pData; };
	void SetNext(TNode<T>* pPtr) { m_pNext = pPtr; }
	friend ostream& operator<<(ostream& s, const TNode<T>& node);
};


template<class T>
ostream& operator<<(ostream& s, const TNode<T>& node)
{
	s << "Index: " << node.m_nIndex << endl;
	//s << "Element: " << node.m_tData << endl;
}


template<class T>
TNode<T>& TNode<T>::operator=(const T& data)
{
	std::cout << "called TNodes=(int) op\n";

		this->m_tData = data;
		return *this;
}

template<class T>
TNode<T>& TNode<T>::operator=(const TNode<T>& node)
{
	std::cout << "called TNodes=(TNode) op\n";

	this->m_tData = node.GetData();
	return *this;
}

