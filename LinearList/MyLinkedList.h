#pragma once
#ifndef LINKED_LIST_
#define LINKED_LIST_

#include<iostream>
#include<initializer_list>
#include<memory>

// Template Struct ListNode
template<typename T>
struct ListNode
{
	T val;
	std::shared_ptr<ListNode<T>>next;

	ListNode() :val(0), next(nullptr) {};
	ListNode(T  data) :val(data), next(nullptr) {};
	ListNode(T  data, std::shared_ptr<ListNode<T>> next) : val(data), next(next) {};
};

// Class LinkedList
template<typename T>
class LinkedList final
{
public:
	LinkedList() : head(nullptr), m_size(0) {}

	LinkedList(std::initializer_list<T>list); // TODO

	LinkedList(const LinkedList& list); // TODO

	int& operator[](size_t index) const; // TODO

	void push_front(T val); // TODO

	void push_back(T val); // TODO

	void pop_front(); // TODO

	void pop_back(); // TODO

	void insert(size_t index, T val); // TODO

	void erase(size_t index); // TODO

	void reverse(); // TODO

	// return the first occurrence val int LinkedList or -1 if not founded
	int search(T val) const; // TODO

	void print()const {
		std::cout << *this;
	}

	size_t size() const {
		return m_size;
	}

	bool empty() const {
		return m_size == 0;
	}

	// Overloading << to output whole LinkedList
	friend std::ostream& operator<<(std::ostream& out, const LinkedList& list); // TODO
private:
	std::shared_ptr<ListNode<T>> head;
	size_t m_size = 0;
public:
	// Class Iterator
	class Iterator
	{
	public:
		Iterator() :current(nullptr) {}
		Iterator(std::shared_ptr<ListNode<T>> node) :current(node) {}

		// Dereference operation
		int& operator*() {
			return current->val;
		}

		Iterator& operator++() {
			current = current->next;
			return *this;
		}

		Iterator operator++(int) {
			Iterator old = *this;
			current = current->next;
			return old;
		}

		//Iterator & operator -- ();	// No this method existing in singly list
		//Iterator operator -- (int);   // No this method existing in singly list

		bool operator==(const Iterator& itr) const {
			return current == itr.current;
		}

		bool operator!=(const Iterator& itr) const {
			return current != itr.current;
		}
	private:
		std::shared_ptr<ListNode<T>> current;
	};
public:
	Iterator begin() {
		return Iterator(head);
	}

	Iterator end() {
		Iterator itr = Iterator(head);
		for (int i = 0; i < m_size; i++)
			itr++;
		return itr;
	}
};

#endif LINKED_LIST_
