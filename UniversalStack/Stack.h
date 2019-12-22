#pragma once
#include <stdlib.h>
#include <string>

// size of stack in bytes
template<size_t size>
class Stack
{

public:
	Stack() 
	{
		base = malloc(size); // allocating memory
		top = base;
		max = (void*)((char*)base + size);
	}

	~Stack()
	{
		free(base);
	}

	template<typename T>
	bool push(T val)
	{
		if (hasEnoughSpace(val))
		{
			*static_cast<T*>(top) = val; // write value into memory
			top = static_cast<void*>(static_cast<char*>(top) + sizeof(val)); // increment pointer
			sizes[count++] = sizeof(val); // save size and increment count
			return true;
		}

		return false;
	}

	void* pop()
	{
		if (!isEmpty())
		{
			top = static_cast<void*>(static_cast<char*>(top) - sizes[--count]); // decrement pointer and count
			sizes[count] = 0;
			return top;
		}

		return nullptr;
	}

	void* peek()
	{
		if (!isEmpty())
		{
			return static_cast<void*>(static_cast<char*>(top) - sizes[count - 1]);
		}
		
		return nullptr;
	}

	bool isEmpty() { return top == base; }
	bool isFull() { return top == max; }

private:
	size_t getLeftSpace() { return (char*)max - (char*)top; }
	template<typename T>
	bool hasEnoughSpace(T val) { return sizeof(val) <= getLeftSpace(); }

	size_t sizes[size]; // in extreme case there are size elements with size of 1 byte
	int count = 0;
	void* top;
	void* base;
	void* max;
};

