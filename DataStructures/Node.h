#pragma once

template <typename T>
class Node
{
public:
	Node()
		: mData(T())
		, mPrev(nullptr)
		, mNext(nullptr)
	{

	}

public:
	T mData;
	Node<T>* mPrev;
	Node<T>* mNext;
};
