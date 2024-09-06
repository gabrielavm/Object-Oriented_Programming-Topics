#pragma once
#include <iostream>

template<typename T>
class UniquePtr
{
	T* data;

public:

	UniquePtr(T* ptr);

	UniquePtr(const UniquePtr& other) = delete;
	UniquePtr(UniquePtr&& other) noexcept;

	UniquePtr& operator=(const UniquePtr& other) = delete;
	UniquePtr& operator=(UniquePtr&& other) noexcept;

	~UniquePtr();

	T& operator*();
	const T& operator*() const;

	T* operator->();
	const T* operator->() const;
};

template<typename T>
UniquePtr<T>::UniquePtr(T* ptr) : data(ptr)
{}

template<typename T>
UniquePtr<T>::UniquePtr(UniquePtr&& other) noexcept
{
	data = other.data;
	other.data = nullptr;
}

template<typename T>
UniquePtr<T>& UniquePtr<T>::operator=(UniquePtr&& other) noexcept
{
	if (this != &other)
	{
		delete data;
		data = other.data;
		other.data = nullptr;
	}

	return *this;
}

template<typename T>
UniquePtr<T>::~UniquePtr()
{
	delete data;
}

template<typename T>
T& UniquePtr<T>::operator*()
{
	return *data;
}

template<typename T>
const T& UniquePtr<T>::operator*() const
{
	return *data;
}

template<typename T>
T* UniquePtr<T>::operator->()
{
	return data;
}

template<typename T>
const T* UniquePtr<T>::operator->() const
{
	return data;
}
