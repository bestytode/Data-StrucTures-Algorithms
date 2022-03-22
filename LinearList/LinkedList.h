#pragma once
#ifndef LinkedList_
#define LinkedList_

#include <initializer_list>
#include <iostream>
#include <stdexcept>

template<typename T>
struct Node
{
	T val;
	Node<T>* next;

	Node() :val(0), next(nullptr) {};
	Node(T val) :val(val), next(nullptr) {};
	Node(T val, Node<T>* node) : val(val), next(node) {};

	friend std::ostream& operator <<(std::ostream& out, const Node<T>& node){
		return out << node.val;
	}
};

template<typename T>
class LinkedList final
{
public:
	// Default constructor
	LinkedList() : 
		head(nullptr), m_size(0) {}

	LinkedList(std::initializer_list<T> list)
	{
		for (T val : list)
			push_back(val);
	}

	// Copy constructor
    LinkedList(const LinkedList& other)	
	{
		if (other.empty())
		{
			head = nullptr;
			m_size = 0;
		}
		
		head = new Node<T>(other.head->val);
		Node<T>* current = head;
		Node<T>* otherHead = other.head;
		Node<T>* otherCurrent = otherHead;

		// if other->next exists, copy the same value to current node
		while (otherCurrent->next) {
			current->next = new Node<T>(otherCurrent->next->val);
			otherCurrent = otherCurrent->next;
			current = current->next;
		}
		m_size = other.m_size;
	}

	T& operator[](size_t index)const
	{
		if (empty() || index > m_size - 1)
			throw std::invalid_argument("Invalid index!");

		Node<T>* temp = head;
		for (size_t i = 0; i < index; i++)
		{
			temp = temp->next;
		}
		return temp->val;
	}

	void push_front(T val)
	{
		Node<T>* temp = new Node<T>(val);
		if (empty())
		{
			head = temp;
			m_size++;
			return;
		}

		temp->next = head;
		head = temp;
		m_size++;
	}

	void push_back(T val) 
	{
		if (empty())
		{
			push_front(val);
			return;
		}

		Node<T>* temp = head;
        Node<T>* newNode = new Node<T>(val);
		while (temp->next)
		{
			temp = temp->next;
		}

		temp->next = newNode;
		m_size++;
	}

	void pop_front()
	{
		if (empty())
			return;

		Node<T>* temp = head;
		head = head->next;
		delete temp;
		--m_size;
	}

	void pop_back()
	{
		if (empty())
		{
			return;
		}
		else if (m_size == 1)
		{
			pop_front();
			return;
		}

		Node<T>* prev = head;
		Node<T>* curr = head->next;
		while (curr->next)
		{
			prev = prev->next;
			curr = curr->next;
		}

		// the prev now becomes the last node
		// so the next pointer of the prev point to nullptr
		prev->next = nullptr;
		delete curr;
		--m_size;
	}

	void insert(int val, size_t index)
	{

		if (empty() || index > m_size)
			throw std::invalid_argument("Invalid index!");

		// If inserting a new head
		if (index == 0)
		{
			push_front(val);
			return;
		}
		// If inserting a new last listNode
		else if (index == m_size)
		{
			push_back(val);
			return;
		}

		Node<T>* prev = head;

		// Traverse the elements until the selected index is found
		for (size_t i = 0; i < index - 1; ++i)
		{
			prev = prev->next;
		}
		Node<T>* next = prev->next;
		Node<T>* newNode = new Node<T>(val);

		// Insert this new node between the previous node and the next node
		newNode->next = next;
		prev->next = newNode;
		++m_size;
	}

	void erase(size_t index)
	{
		if (empty() || index > m_size - 1)
			throw std::invalid_argument("Invalid index!");

		if (empty())
		{
			return;
		}
		else if (index == 0)
		{
			pop_front();
			return;
		}
		else if (index == m_size - 1)
		{
			pop_back();
			return;
		}

		Node<T>* prev = head;
		for (size_t i = 0; i < index - 1; ++i)
		{
			prev = prev->next;
		}

		Node<T>* curr = prev->next;
		Node<T>* next = curr->next;

		// Link the prev to next to remove the mid element
		prev->next = next;
		delete curr;
		--m_size;
	}

	void reverse()	
	{
		if (empty() || size() == 1)
			return;

		Node<T>* prev = nullptr;
		Node<T>* curr = head;
		while (curr)
		{
			Node<T>* next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		head = prev;
	}

	//Utilities
	void print()const
	{
		std::cout << *this;
	}

	int size()const
	{
		return m_size;
	}

	bool empty()const
	{
		return m_size == 0;
	}

	friend std::ostream& operator << (std::ostream& out, const LinkedList& list)
	{
		if (list.empty())
		{
			return out;
		}

		Node<T>* temp = list.head;
		while (temp)
		{
			out << temp->val << " ";
			temp = temp->next;
		}
		return out;
	}
private:
	Node<T>* head;
	size_t m_size = 0;
public:
	class Iterator
	{
	public:
		Iterator() : current(nullptr) {}
		Iterator(Node<T>* node) : current(node) {}

		// Dereference operation
		T& operator*()
		{
			return current->val;
		}

		Iterator& operator ++ ()
		{
			current = current->next;
			return *this;
		}

		Iterator operator ++ (T)
		{
			Iterator itr = *this;
			current = current->next;
			return itr;
		}

		//Iterator & operator -- ();	// No this method existing in singly list
		//Iterator operator -- (int);   // No this method existing in singly list

		bool operator == (const Iterator& other)
		{
			return current == other.current;
		}

		bool operator != (const Iterator& other)
		{
			return current != other.current;
		}
	private:
		Node<T>* current;
	};
public:
	Iterator begin() 
	{
		return Iterator(head);
	}

	Iterator end()
	{
		Iterator itr = Iterator(head);
		for (size_t i = 0; i < m_size; i++) 
			itr++;		
		return itr;
	}
};

#endif LinkedList_
