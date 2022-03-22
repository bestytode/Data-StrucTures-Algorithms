#pragma once
#include <iostream>
#include <initializer_list>
#include <memory>

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

// Template Class LinkedList
template<typename T>
class LinkedList final
{
public:
	LinkedList() : head(nullptr), m_size(0) {}
	LinkedList(std::initializer_list<T>list); // TODO
	LinkedList(const LinkedList<T>& list);    // TODO

	void push_front(T val); // TODO
	void push_back(T val);  // TODO
	void pop_front();       // TODO
	void pop_back();        // TODO

	void insert(size_t index, T val); // TODO
	void erase(size_t index);         // TODO

	void reverse();         // TODO
	size_t search(T val)const; // TODO

	void print()const;  // TODO
	size_t size()const; // TODO
	bool empty()const;  // TODO

	T& operator[](size_t index)const; // TODO
	friend std::ostream& operator<<(std::ostream& out, const LinkedList<T>& list); // TODO
private:
	std::shared_ptr<ListNode<T>>head;
	size_t m_size;
public:
	// Template Class Iterator
	class Iterator
	{
	public:
		Iterator() :current(nullptr) {}
		Iterator(std::shared_ptr<ListNode<T>> node) :current(node) {}

		T& operator*();         // TODO
		Iterator& operator++();   // TODO
		Iterator operator++(int); // TODO

		//Iterator& operator--();   // No this method existing in singly list
		//Iterator operator--(int); // No this method existing in singly list

		bool operator==(const Iterator& itr); // TODO
		bool operator!=(const Iterator& itr); // TODO
	private:
		std::shared_ptr<ListNode<T>> current;
	};
public:
	Iterator begin(); // TODO
	Iterator end();   // TODO
};
