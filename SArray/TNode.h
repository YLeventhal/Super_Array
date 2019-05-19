#pragma once

template<class T>
class TNode
{
private:
	int m_nIndex;
	T m_tData;
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
	const T& GetData()const { return m_tData; }
	TNode<T>*& GetNext() { return m_pNext; }

	//void SetIndex(int index) { m_nIndex = index; }
	void SetData(T pData) { m_tData = pData; };
	void SetNext(TNode<T>* pPtr) { m_pNext = pPtr; }
};

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

