#pragma once
#include "Iterator.h"

template <typename T>
class List
{
public:
	List()
		: mSize(0)
	{
		mHead = new Node<T>;
		mTail = new Node<T>;

		mHead->mNext = mTail;
		mTail->mPrev = mHead;
	}
	virtual ~List()
	{
		while (mSize > 0)
		{
			pop_back();
		}

		delete mHead;
		delete mTail;
	}
	void push_back(const T& data)
	{
		addNode(mTail, data);
		mSize++;
	}
	void push_front(const T& data)
	{
		addNode(mHead->mNext, data);
		mSize++;
	}
	void pop_back()
	{
		if (mTail->mPrev == mHead)
		{
			return;
		}

		removeNode(mTail->mPrev);
		mSize--;
	}
	void clear()
	{
		while (mSize > 0)
		{
			pop_back();
		}
	}
	size_t size() const
	{
		return mSize;
	}

private:
	Node<T>* addNode(Node<T>* next, const T& value)
	{
		Node<T>* prev = next->mPrev;
		
		Node<T>* node = new Node<T>;
		node->mPrev = prev;
		node->mNext = next;
		node->mData = value;

		prev->mNext = node;
		next->mPrev = node;

		return node;
	}
	Node<T>* removeNode(Node<T>* node)
	{
		Node<T>* next = node->mNext;
		Node<T>* prev = node->mPrev;

		next->mPrev = prev;
		prev->mNext = next;

		delete node;
		return next;
	}

public:
	using iterator = Iterator<T>;  // typedef Iterator<T> iterator;

	iterator begin() const
	{
		return iterator(mHead->mNext);
	}
	iterator end() const 
	{
		return iterator(mTail);
	}
	iterator insert(iterator next, const T& data)  // 인자로 받은 노드 앞에 추가하고 추가한 노드 반환   
	{
		Node<T>* node =  addNode(next.mNode, data);
		mSize++;
		return iterator(node);
	}
	iterator erase(iterator node)  // 인자로 받은 노드를 삭제하고 삭제한 노드의 다음 노드 반환 
	{
		Node<T>* next = removeNode(node.mNode);
		mSize--;
		return iterator(next);
	}

private:
	Node<T>* mHead;
	Node<T>* mTail;
	size_t mSize;
};
