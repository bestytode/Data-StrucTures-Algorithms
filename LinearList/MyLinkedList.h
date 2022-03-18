// Simple Singly List Implementation with cpp

#pragma once
#ifndef LINKED_LIST_
#define LINKED_LIST_

#include<iostream>
#include<initializer_list>
#include<cassert>
 
// Struct ListNode
struct ListNode
{
	int val;
	ListNode* next;

	ListNode() :val(0), next(nullptr) {};
	ListNode(int  data) :val(data), next(nullptr) {};
	ListNode(int  data, ListNode* next) : val(data), next(next) {};
	~ListNode() = default;

	friend std::ostream& operator <<(std::ostream& out, const ListNode& node) 
	{
	    return out << node.val;		
	}
};

// Class LinkedList
class LinkedList final
{
public:
	// Default constructor
	LinkedList() : head(nullptr), m_size(0) {}

	// initialize LinkedList as "LinkedList list = {1 ,2, 3, 4, 5};"
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
		if (list.empty()) 
		{
			LinkedList();
			return;
		}

		ListNode* temp = head;
		for (int i = 0; i < list.size(); ++i)
		{
			temp->val = list[i];
			temp = temp->next;
		}
	}

	// Destructor
	~LinkedList() = default;

	int get(size_t index)const
	{
		return (*this)[index];
	}

	int& operator[](size_t index)const
	{
		// Check if the index is out of bound
		assert(index <= m_size - 1);

		if (index == 0) 
		{
			return head->val;
		}

                // Start from the Head
		ListNode* temp = head;

		// Iterate through the linked list elements
	        // until it finds the selected index
		for (int i = 0; i < index; ++i)
		{
			temp = temp->next;
		}

		// Simply return the node result
		return temp->val;
	}

	void push_front(int val)
	{
		// Create a new Node
		ListNode* temp = new ListNode(val);

		// If the linked list is empty, replace temp as head
		if (empty())
		{
			head = temp;
			++m_size;
			return;
		}
		// The current head will no longer become a head
                // so the mext pointer of the new ListNode will point to the current head
		else 
		{
		    temp->next = head;
		    head = temp;
		    ++m_size;
	        }
	}

        void push_back(int val)
	{
		if (empty())
		{
			push_front(val);
			return;
		}

		ListNode* newNode = new ListNode(val, nullptr);

		// Iterate through the linked list elements
		// to get the last ListNode
		ListNode* temp = head;
		while (temp)
		{
			temp = temp->next;
		}

		// The last ListNode point to newNode
		temp->next = newNode;
		++m_size;
	}

	void pop_front()
	{
		if (empty())
		{
			return;
		}

		ListNode* temp = head;

		// Point the head pointer
	        // to the element next to the current head
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

		// If LinkedList has only one element
	        // just simply call pop_front()
		if (m_size == 1)
		{
			pop_front();
			return;
		}

		ListNode* prev = head;
		ListNode* curr = head->next;
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

	void insert(size_t index, int val)
	{
		// Check if the index is out of bound
		assert(index <= m_size);

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

		ListNode* prev = head;

                // Traverse the elements until the selected index is found
		for (int i = 0; i < index - 1; ++i)
		{
			prev = prev->next;
		}
		ListNode* next = prev->next;
		ListNode* newNode = new ListNode(val);

		// Insert this new node between the previous node and the next node
		newNode->next = next;
		prev->next = newNode;

		++m_size;
	}

	void erase(size_t index)
	{
		if (empty())
		{
			return;
		}
		assert(index < m_size);

		if (index == 0)
		{
			pop_front();
			return;
		}
		else if (index == m_size - 1)
		{
			pop_back();
			return;
		}

		ListNode* prev = head;
		for (int i = 0; i < index - 1; ++i)
		{
			prev = prev->next;
		}

		ListNode* curr = prev->next;
		ListNode* next = curr->next;

		// Link the prev to next to remove the mid element
		prev->next = next;

		delete curr;
		--m_size;
	}
    
	void reverse()
	{
		if (empty() || size() == 1) 
		{
			return;
		}

		ListNode* prev = nullptr;
		ListNode* curr = head;

		while (curr)
		{
			ListNode* next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		head = prev;
	}

	// return the first occurrence val int LinkedList or -1 if not founded
	int search(int val)
	{
		if (empty())
		{
			return -1;
		}

		int index = 0;

		// Traverse until the selected value
	        // is matched with the value
	        // of the current position,
		ListNode* temp = head;
		while (temp)
		{
			if (temp->val == val)
			{
				return index;
			}
			++index;
			temp = temp->next;
		}
		return -1;
	}

	void clear()
	{
		if (empty()) 
		{
			return;
	        }
		while (head) 
		{
			ListNode* temp = head;
			head = head->next;
			delete temp;
		}
	}

	void print()const
	{
		std::cout << *this;
	}

	int size() const
	{
		return m_size;
	}

	bool empty() const
	{
		return m_size == 0;
	}

	// Overloading << to output whole LinkedList
	friend std::ostream& operator<<(std::ostream& out, const LinkedList& list) 
	{
		if (list.empty())
		{
			return out;
		}

                ListNode* temp = list.head;
		while (temp)
		{
			out << temp->val << " ";
			temp = temp->next;
		}
		return out;
	}

private:
	ListNode* head = nullptr;
	size_t m_size = 0;

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

		//Iterator & operator -- ();	// No this method existing in singly list
		//Iterator operator -- (int);   // No this method existing in singly list

		bool operator==(const Iterator & itr) const
		{
			return current == itr.current;
		}

		bool operator!=(const Iterator& itr) const
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

#endif LINKED_LIST_
