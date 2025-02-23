#pragma once

#include "PriorityQueueLinkedList.h"

template<class T>
class PriorityQueue
{
public:
	PriorityQueue(int size)
	{
		assert(size > 0);
		m_lsize = size;
	}
	~PriorityQueue() {}

	// Priority Queue Functions
	void push(T val, int priority)
	{
		assert(m_elements.GetSize() < m_lsize);

		//if (m_elements.GetSize() == 0)
		//{
			m_elements.Push(val, priority);
		//}
		//else
		//{
		//	LinkIterator<T> it;
		//	it = m_elements.Begin();

		//	CMP cmp;	// Placeholder for the comparisons

		//	while (it.isValid())
		//	{
		//		//if (cmp(val, *it))
		//		if(cmp(priority,it.GetNodePriority()))
		//		{
		//			break;	// Move the iterator to the place where we want to insert the new node into
		//		}

		//		it++;
		//	}

		//	if (it.isValid())
		//	{
		//		m_elements.Insert_Before(it, val);
		//	}
		//	else
		//	{
		//		m_elements.Push(val,priority);
		//	}
		//}
	}

	void pop()
	{
		m_elements.Pop();
	}

	LinkNode<T> front()
	{
		return *m_elements.Begin();
	}
	/*LinkNode<T>* back()
	{
		LinkIterator<T> it;
		it = m_elements.Last();

		return m_elements.;
	}*/

	// Helper functions
	int GetSize()
	{
		return m_elements.GetSize();
	}

	int GetMaxSize()
	{
		return m_lsize;
	}

	bool isEmpty()
	{
		return (m_elements.GetSize() == 0);
	}

	void Resize(int size)
	{
		assert(size > 0);
		m_lsize = size;
	}

private:
	LinkedList<T> m_elements; // Priority Queue Linked List
	int m_lsize;
};