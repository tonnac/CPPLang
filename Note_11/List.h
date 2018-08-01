#pragma once
#include <iostream>

template <class K>
class Node
{
public:
	void setNext(Node* nNode);
	Node<K>* getNext();
	K getData();
	Node(const K& data = 0);
private:
	K m_kData;
	Node<K> * m_pNext;
};


template <class K>
class List
{
public:
	List();
	~List();
	void push_back(const K& data);
	void push_front(const K& data);
	K pop_back();
	K pop_front();
public:
	Node<K>* begin();
	Node<K>* end();
private :
	template <class K>
	class list_iterator
	{
	private:
		Node<K>* current;
	public:
		list_iterator(Node<K>* node=nullptr)
		{
			current = node;
		}
//		list_iterator operator+(list_iterator& src);
		list_iterator& operator++(int m)
		{
			current = current->getNext();
			return *this;
		}
		list_iterator& operator--(int m)
		{
			Node<K>* temp = m_pHead->getNext();
			while (temp->getNext() != current)
			{
				temp = temp->getNext();
			}
			current = temp;
			return *this;
		}
		Node<K>* operator->() const
		{
			return current;
		}
		Node<K>* operator*() const
		{
			return current;
		}
		list_iterator& operator=(Node<K>*src)
		{
			current = src;
		}
		bool operator!=(const Node<K>*src) const
		{
			if (current == src)
				return false;
			return true;
		}
		bool operator==(const Node<K>*src) const
		{
			return !(current == src);
		}
	};
public:
	using iterator = List<K>::list_iterator<K>;
private:
	Node<K> * m_pHead;
	Node<K> * m_pTail;
};