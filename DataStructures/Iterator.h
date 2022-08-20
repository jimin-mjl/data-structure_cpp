#pragma once
#include "Node.h"

template <typename T>
class Iterator
{
public:
	Iterator()
		: mNode(nullptr)
	{

	}
	Iterator(Node<T>* node)
		: mNode(node)
	{
		
	}
	Iterator& operator++()  // prefixÇü
	{
		mNode = mNode->mNext;
		return *this;
	}
	Iterator operator++(int)  // postfixÇü
	{
		Iterator<T> temp = this;
		mNode = mNode->mNext;
		return temp;
	}
	Iterator& operator--()
	{
		mNode = mNode->mPrev;
		return *this;
	}
	Iterator operator--(int)
	{
		Iterator<T> temp = this;
		mNode = mNode->mPrev;
		return temp;
	}
	bool operator==(const Iterator& it)
	{
		return mNode == it.mNode;
	}
	bool operator!=(const Iterator& it)
	{
		return !operator==(it);
	}
	T& operator*()
	{
		return mNode->mData;
	}

public:
	Node<T>* mNode;
};
