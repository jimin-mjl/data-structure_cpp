#pragma once

constexpr float INC = 1.5f;  // vector capacity�� ������ 

template <typename T>
class Vector
{
public:
	Vector()
		: mSize(0)
		, mCapacity(1)
		, mData(nullptr)
	{

	}
	virtual ~Vector()
	{
		std::cout << "" << std::endl;
		if (mData)
		{
			delete[] mData;
		}
	}
	size_t size() const
	{
		return mSize;
	}
	size_t capacity() const 
	{
		return mCapacity;
	}
	void push_back(const T& data)
	{
		if (mSize == 0)
		{
			mData = new T[mCapacity];
		}

		if (mSize == mCapacity)  // capacity�� �� �� ��� ���ο� �޸� �������� �̻��Ѵ� 
		{
			int capacity = static_cast<int>(mCapacity * INC);
			if (mSize == capacity)  // capacity�� 1�� ��� 
			{
				capacity++;
			}

			reserve(capacity);
		}
		
		mData[mSize] = data;
		mSize++;
	}
	void pop_back()
	{
		if (mSize > 0)
		{
			mSize--;
		}
	}
	void clear()
	{
		if (mData)
		{
			delete[] mData;
			mData = nullptr;
		}

		mSize = 0;
	}
	void reserve(const int size)
	{
		if (mCapacity >= size)
		{
			return;
		}

		T* newData = new T[size];  // ��û�� ũ�⸸ŭ�� ���ο� �޸� ������ �����Ѵ�

		if (mData)
		{
			for (int i = 0; i < mSize; i++)  // �� �������� �����͸� �����Ѵ�
			{
				newData[i] = mData[i];
			}

			delete[] mData;
		}

		mData = newData;
		mCapacity = size;
	}
	T& operator[](const int order) const
	{
		return mData[order];
	}

private:
	T* mData;
	size_t mSize;
	size_t mCapacity;
};
