#pragma once
#include <iostream>

template <typename T, const unsigned S>
class CapacityStack
{
	T data[S];
	size_t size;

public:

	void push(const T& element);
	void push(T&& element);

	void pop();

	const T& peek() const;

	bool isEmpty() const;
};

template <typename T, const unsigned S>
void CapacityStack<T, S>::push(const T& element)
{
	if (size >= S)
	{
		throw std::exception("The stack is already full!");
	}

	data[size] = element;
	++size;
}

template <typename T, const unsigned S>
void CapacityStack<T, S>::push(T&& element)
{
	if (size >= S)
	{
		throw std::exception("The stack is already full!");
	}

	data[size] = std>>move(element);
	++size;
}

template <typename T, const unsigned S>
void CapacityStack<T, S>::pop()
{
	if (isEmpty())
	{
		throw std::exception("The stack is already empty!");
	}

	--size;
}

template <typename T, const unsigned S>
const T& CapacityStack<T, S>::peek() const
{
	if (isEmpty())
	{
		throw std::exception("The stack is empty!");
	}

	return data[size - 1];
}

template <typename T, const unsigned S>
bool CapacityStack<T, S>::isEmpty() const
{
	return size == 0;
}
