#pragma once
#include "Vector.h"

template <typename T, typename Container = Vector<T>>
class Stack
{
public:
	Stack()
		: mContainer(nullptr)
		, mSize(0)
	{

	}
	virtual ~Stack()
	{
		if (mContainer)
		{
			delete mContainer;
		}
	}
	void push(const T& data)
	{
		if (mContainer == nullptr)
		{
			mContainer = new Container;
		}

		mContainer->push_back(data);
		mSize++;
	}
	void pop()
	{
		if (mSize > 0)
		{
			mContainer->pop_back();
			mSize--;
		}
	}
	T& top() const
	{
		Container& container = *mContainer;
		return container[mSize - 1];
	}
	bool empty() const 
	{
		return mSize == 0;
	}
	size_t size() const
	{
		return mSize;
	}
private:
	Container* mContainer;
	size_t mSize;
};
