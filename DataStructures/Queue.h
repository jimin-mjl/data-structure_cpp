#pragma once
#include "List.h"

template <typename T, typename Container = List<T>>
class Queue
{
public:
	Queue()
		: mContainer(nullptr)
		, mSize(0)
	{

	}
	virtual ~Queue()
	{
		if (mContainer)
		{
			delete mContainer;
		}
	}
	void push(const T& data)
	{
		if (mSize == 0)
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
			mContainer->erase(mContainer->begin());
			mSize--;
		}
	}
	T& front() const
	{
		typename Container::iterator it = mContainer->begin();
		return *it;
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
