#pragma once
#include <iostream>

template <typename T>
class Queue
{
	T* data;
	size_t size;
	size_t capacity;

	size_t put;
	size_t get;

	void resize();
	void copyFrom(const Queue& other);
	void moveFrom(Queue&& other);
	void free();

public:

	Queue();

	Queue(const Queue& other);
	Queue(Queue&& other);

	Queue& operator=(const Queue& other);
	Queue& operator=(Queue&& other);

	~Queue();

	void push(const T& element);
	void push(T&& element);

	void pop();
	const T& peek() const;
	bool isEmpty() const;
};

template <typename T>
void Queue<T>::resize()
{
	T* dataCopy = new T[capacity * 2];
	for (int i = 0; i < size; i++)
	{
		dataCopy[i] = data[get];
		(++get) %= capacity;
	}

	delete[] data;
	data = dataCopy;

	capacity *= 2;
	put = size;
	get = 0;
}

template <typename T>
void Queue<T>::copyFrom(const Queue& other)
{
	data = new T[other.capacity];
	for (int i = 0; i < other.capacity; i++)
	{
		data[i] = other.data[i];
	}

	capacity = other.capacity;
	size = other.size;
	put = other.put;
	get = other.get;
}

template <typename T>
void Queue<T>::moveFrom(Queue&& other)
{
	data = other.data;
	other.data = nullptr;

	capacity = other.capacity;
	other.capacity = 0;

	size = other.size;
	other.size = 0;

	put = other.put;
	other.put = 0;

	get = other.get;
	other.get = 0;
}

template <typename T>
void Queue<T>::free()
{
	delete[] data;
	capacity = 0;
	size = 0;
	put = get = 0;
}

template <typename T>
Queue<T>::Queue()
{
	capacity = 8;
	size = 0;
	data = new T[capacity];
	get = put = 0;
}

template <typename T>
Queue<T>::Queue(const Queue& other)
{
	copyFrom(other);
}

template <typename T>
Queue<T>::Queue(Queue&& other)
{
	moveFrom(std::move(other));
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template <typename T>
Queue<T>& Queue<T>::operator=(Queue&& other)
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template <typename T>
Queue<T>::~Queue()
{
	free();
}

template <typename T>
void Queue<T>::push(const T& element)
{
	if (size == capacity)
	{
		resize();
	}

	data[put] = element;
	(++put) %= capacity;
	size++;
}

template <typename T>
void Queue<T>::push(T&& element)
{
	if (size == capacity)
	{
		resize();
	}

	data[put] = std::move(element);
	(++put) %= capacity;
	size++;
}

template <typename T>
void Queue<T>::pop()
{
	if (isEmpty())
	{
		throw std::exception("The queue is already empty!");
	}

	(++get) %= capacity;
	--size;
}

template <typename T>
const T& Queue<T>::peek() const
{
	if (isEmpty())
	{
		throw std::exception("The queue is empty!");
	}

	return data[get];
}

template <typename T>
bool Queue<T>::isEmpty() const
{
	return size == 0;
}
