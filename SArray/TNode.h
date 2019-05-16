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
	TNode(int index) { m_nIndex = index; }
	~TNode() {};

	TNode<T>& operator=(T data);

	int GetIndex() { return m_nIndex; }
	T& GetData() { return m_tData; }
	TNode<T>* GetNext() { return m_pNext; }

	//void SetIndex(int index) { m_nIndex = index; }
	void SetData(T pData) { m_tData = pData; };
	void SetNext(TNode<T>* pPtr) { m_pNext = pPtr; }
};

template<class T>
TNode<T>& TNode<T>::operator=(T data)
{
		this->m_tData = data;
		return *this;
}

