#include "List.h"

template <class K>
Node<K>::Node(const K& data)
{
	m_kData = data;
	m_pNext = nullptr;
}
template <class K>
void Node<K>::setNext(Node* nNode)
{
	m_pNext = nNode;
}
template <class K>
Node<K>* Node<K>::getNext()
{
	return m_pNext;
}

template <class K>
K Node<K>::getData()
{
	return m_kData;
}

template <class K>
List<K>::List()
{
	m_pHead = new Node<K>;
	m_pTail = m_pHead;
}
template <class K>
List<K>::~List()
{
	Node<K>* temp = m_pHead;
	while (temp != nullptr)
	{
		m_pHead = m_pHead->getNext();
		delete temp;
		temp = m_pHead;
	}
}
template <class K>
void List<K>::push_back(const K& data)
{
	Node<K>* newNode = new Node<K>(data);
	m_pTail->setNext(newNode);
	m_pTail = newNode;
}
template <class K>
void List<K>::push_front(const K& data)
{
	Node<K>* newNode = new Node<K>(data);
	Node<K>* headNext = m_pHead->getNext();
	newNode->setNext(headNext);
	m_pHead->setNext(newNode);
	while (m_pTail->getNext() != nullptr)
	{
		m_pTail = m_pTail->getNext();
	}
}
template <class K>
K List<K>::pop_back()
{
	K rn = m_pTail->getData();
	Node<K>* temp = m_pHead;
	while (temp->getNext() != m_pTail)
	{
		temp = temp->getNext();
	}
	delete m_pTail;
	m_pTail = temp;
	m_pTail->setNext(nullptr);
	return rn;
}
template <class K>
K List<K>::pop_front()
{
	Node<K>* temp = m_pHead->getNext();
	K rn = temp->getData();
	m_pHead->setNext(temp->getNext());
	delete temp;
	return rn;
}
template <class K>
Node<K>* List<K>::begin()
{
	return m_pHead->getNext();
}
template <class K>
Node<K>* List<K>::end()
{
	return m_pTail->getNext();
}
//template <class K>
//List<K>::list_iterator List<K>::list_iterator::operator+(list_iterator& src)
//{
//
//
