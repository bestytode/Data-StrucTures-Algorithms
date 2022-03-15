// Simple Singly List Implementation with cpp

#pragma once
#ifndef MY_LINKED_LIST_
#define MY_LINKED_LIST_

#include<iostream>
#include<initializer_list>
#include<cassert>

// Struct ListNode with datatype integer
struct ListNode
{
	int val;
	ListNode* next;

	ListNode() :val(0), next(nullptr) {};
	ListNode(int  data) :val(data), next(nullptr) {};
	ListNode(int  data, ListNode* next) : val(data), next(next) {};

	friend std::ostream& operator <<(std::ostream& out, const ListNode& node)
	{	
	    return << node.val;		
	}
};

// Class LinkedList with datatype integer
class LinkedList final
{
public:
	LinkedList() : head(nullptr), m_size(0) {}
	LinkedList(std::initializer_list<int>list)
	{
		for (int data : list)
		{
			push_back(data);
		}
	}

	// Copy constuctor
	LinkedList(const LinkedList& list)
	{
		//TODO
	}

	int& operator[](int index) const
	{
		//TODO
	}

	void push_front(int val)
	{
		//TODO
	}

	void push_back(int val)
	{
		//TODO
	}

	void insert(int val, int index)
	{
		//TODO
	}

	void erase(int index)
	{
		//TODO
	}

	void reverse()
	{
		//TODO
	}

	int size() const
	{
		return m_size;
	}
        void empty() const
	{
		return m_size == 0;
	}
	
	// Overloading << to output whole LinkedList
	friend std::ostream& operator<<(std::ostream& out, const LinkedList& list)
	{
		if(!list.head)
		    return out;

        ListNode* temp = list.head;
		while (temp)
		{
			out << temp->val << " ";
			temp = temp->next;
		}
		return out;
	}


private:
	ListNode* head;
	int m_size = 0;

public:

	// Class Iterator with datatype integer
	class Iterator
	{
	public:

		Iterator() :current(nullptr) {}
		Iterator(ListNode* node) :current(node) {}

		// Dereference 
		int& operator*()
		{
			return current->val;
		}

		Iterator& operator++()
		{
			current = current->next;
			return *this;
		}

		Iterator operator++(int)
		{
			Iterator old = *this;
			current = current->next;
			return old;
		}

		//Iterator & operator -- ();	// No this method in singly list
		//Iterator operator -- (int);   // No this method in singly list

		bool operator == (const Iterator & itr)
		{
			return current == itr.current;
		}

		bool operator != (const Iterator& itr)
		{
			return current != itr.current;
		}

	private:
		ListNode* current;
	};

public:
	Iterator begin() 
	{
		return Iterator(head);
	}

	Iterator end()
	{
		Iterator it = Iterator(head);

		for (int i = 0; i < m_size; i++)
		{
			it++;
		}
		return it;
	}
};

#endif MY_LINKED_LIST_
