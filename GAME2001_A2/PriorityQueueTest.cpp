#include <iostream>
#include "PriorityQueue.h"
using namespace std;

template<class T>
class less_cmp // Less than compare with nonpointer type
{
public:
	inline bool operator()(T lVal, T rVal)
	{
		return lVal < rVal;
	}
};

template<class T>
class less_cmp_pointer // Less than compare with pointer types
{
public:
	inline bool operator()(T lVal, T rVal)
	{
		return ((*lVal) < (*rVal));
	}
};

template<class T>
class greater_cmp // Less than compare with nonpointer type
{
public:
	inline bool operator()(T lVal, T rVal)
	{
		return !(lVal < rVal);
	}
};

template<class T>
class greater_cmp_pointer // Less than compare with pointer types
{
public:
	inline bool operator()(T lVal, T rVal)
	{
		return !((*lVal) < (*rVal));
	}
};

class NetworkMessage
{
public:
	NetworkMessage() : m_priority(0), m_id(0) {}
	NetworkMessage(int p, int id) : m_priority(p), m_id(id) {}
	~NetworkMessage() {}

	int GetPriority()
	{
		return m_priority;
	}
	int GetID()
	{
		return m_id;
	}

	// Overload operator
	bool operator<(NetworkMessage& m)
	{
		// Check the priority level of both network messages
		if (m_priority < m.GetPriority())
		{
			return true;
		}
		else if (m_id < m.GetID())
		{
			return true;
		}

		return false;
	}
	bool operator>(NetworkMessage& m)
	{
		return !(*this < m);	// NOT( this is less than m )
	}
private:
	int m_priority;
	int m_id;
};

int main()
{
	cout << "Priority queue data structure example!" << endl << endl;

	const int SIZE = 8;
	//PriorityQueue<NetworkMessage, less_cmp<NetworkMessage> > que(SIZE);
	PriorityQueue<int> que(SIZE);
	/*que.push(NetworkMessage(3, 100));
	que.push(NetworkMessage(2, 286));
	que.push(NetworkMessage(1, 362));
	que.push(NetworkMessage(3, 435));*/
	que.push(545, 3);
	que.push(48, 6);
	que.push(65, 1);
	que.push(14, 2);
	que.push(52, 4);
	que.push(52, 2);
	que.push(15, 1);
	que.push(25, 6);
	// Display the priority queue
	cout << "Priority queue content (Size - " << que.GetSize() << ") : " << endl;

	while (que.isEmpty() == false)
	{
		cout << "  Priority: " << que.front().getPriority();
		cout << "  Data: " << que.front().getData();
		cout << endl;

		que.pop();
	}

	cout << endl;

	if (que.isEmpty() == true)
	{
		cout << "The container is empty." << endl;
	}
	else
	{
		cout << "The container is NOT empty." << endl;
	}
	std::cout << "Test for object data" << std::endl << std::endl;
	class Test {
	public:
		Test() : m_data("no data") {}
		Test(std::string d) : m_data(d) {}
		std::string getTestData() {
			return m_data;
		}
		~Test() {}

	private:
		std::string m_data;
	};
	PriorityQueue<Test> que2(5);
	que2.push(Test("HI"), 4);
	que2.push(Test("John"), 2);
	que2.push(Test("Bye"), 3);
	que2.push(Test("Wow"), 3);
	que2.push(Test("Day"), 3);
	// Display the priority queue
	cout << "Priority queue content (Size - " << que2.GetSize() << ") : " << endl;

	while (que2.isEmpty() == false)
	{
		cout << "  Priority: " << que2.front().getPriority();
		cout << "  Data: " << que2.front().getData().getTestData();
		cout << endl;

		que2.pop();
	}

	cout << endl;
	return 0;
}