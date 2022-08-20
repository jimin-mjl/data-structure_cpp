#pragma once

constexpr float INC = 1.5f;  // vector capacity의 증가량 

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

		if (mSize == mCapacity)  // capacity가 꽉 찬 경우 새로운 메모리 공간으로 이사한다 
		{
			int capacity = static_cast<int>(mCapacity * INC);
			if (mSize == capacity)  // capacity가 1인 경우 
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

		T* newData = new T[size];  // 요청된 크기만큼의 새로운 메모리 공간을 마련한다

		if (mData)
		{
			for (int i = 0; i < mSize; i++)  // 새 공간으로 데이터를 복사한다
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
