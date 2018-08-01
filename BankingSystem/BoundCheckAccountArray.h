#pragma once
#include "HighCreditAccount.h"

template <class T>
class BoundCheckptrArray
{
private:
	static int m_iCounter;
	T * m_pHead;
	T * m_pTail;
	BoundCheckptrArray(const BoundCheckptrArray& data) {}
	BoundCheckptrArray& operator =(const BoundCheckptrArray& data) {}
public:
	T& operator[] (int idx);
	const T& operator[] (int idx) const;
	void AddArray(T * data);
	T* GetpHead() const { return m_pHead; }
	T* GetpTail() const { return m_pHead; }
public:
	static int GetCnt() { return m_iCounter; }
	BoundCheckptrArray() : m_pHead(NULL), m_pTail(NULL)
	{}
	~BoundCheckptrArray();
};

template <class T>
T& BoundCheckptrArray<T>::operator[] (int idx)
{
	try
	{
		if (idx < 0 || idx >= arrlen)
		{
			throw false;
		}
		return arr[idx];
	}
	catch (bool expn)
	{
		if (expn == false)
		{
			cout << "²¨Á®" << endl;
			exit(1);
		}
	}
}
template <class T>
const T& BoundCheckptrArray<T>::operator[] (int idx) const
{
	try
	{
		if (idx < 0 || idx >= arrlen)
		{
			throw false;
		}
		return arr[idx];
	}
	catch (bool expn)
	{
		if (expn == false)
		{
			cout << "²¨Á®" << endl;
			exit(1);
		}
	}
}
template <class T>
void BoundCheckptrArray<T>::AddArray(T * data)
{
	if (m_pHead == NULL) {
		m_pHead = data;
		m_pTail = m_pHead;
		return;
	}
	/*Account * temp = pTail->GetpNext();*/
	m_pTail->AccountAdd(data);
	m_pTail = data;
	m_iCounter++;
}
template <class T>
BoundCheckptrArray<T>::~BoundCheckptrArray()
{
	int i = 0;
	T * temp = m_pHead;
	T * temp1 = m_pHead;
	while (i++ < m_iCounter)
	{
		temp1 = temp->GetpNext();
		delete temp;
		temp = temp1;
	}
}

template <class T>
int BoundCheckptrArray<T>::m_iCounter = 0;