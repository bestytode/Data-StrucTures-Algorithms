#pragma once
#ifndef VECTOR_
#define VECTOR_

#include<iostream>

template<class T>
class Vector
{
public:
	Vector()
	{
		// allocate 2 elements
		reAlloc(2);
	}

	void push_back(const T& value)
	{
		if (m_size >= m_capacity)
			reAlloc((m_capacity + m_capacity / 2));

		m_data[m_size] = value;
		m_size++;
	}

	// adding temporary value
	void push_back(T&& value)
	{
		if (m_size >= m_capacity)
			reAlloc((m_capacity + m_capacity / 2));

		// rvalue value became lvalue after entering the function
		m_data[m_size] = std::move(value);
		m_size++;
	}

	const T& operator[](size_t index)const
	{
		if (index >= m_size)
		{
			// assert
		}
		return m_data[index];
	}

	 T& operator[](size_t index)
	 {
		 if (index >= m_size)
		 {
			 // assert
		 }
		return m_data[index];
	 }

	size_t size()const
	{
		return m_size;
	}
private:
	// reallocate memory operation
	void reAlloc(size_t newCapacity)
	{
		// 1.allocate a new block of memory
		// 2.copy/move 
		// 3.delete

		if (newCapacity < m_size)
			m_size = newCapacity;

		T* newBlock = new T[newCapacity];
		for (size_t i = 0; i < m_size; ++i)
		{
			newBlock[i] = std::move(m_data[i]);
		}
		delete[] m_data;
		m_data = newBlock;
		m_capacity = newCapacity;
	}

private:
	// m_data representing the array name
	T* m_data = nullptr;

	// number of stored elements
	size_t m_size = 0;

	// ensure capacity is greater than or equals to size
	size_t m_capacity = 0;
};

#endif VECTOR_