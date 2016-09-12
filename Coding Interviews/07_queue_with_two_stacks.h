#ifndef QUEUE_WITH_TWO_STACKS_H
#define QUEUE_WITH_TWO_STACKS_H

#include <stack>
#include <exception>

template<typename T> class CQueue
{
public:
	CQueue(void);
	~CQueue(void);
	void appendTail(const T &node);
	T deleteHead();
private:
	stack<T> stack1;
	stack<T> stack2;
};

template<typename T>
void CQueue<T>::appendTail(const T &node)
{
	stack1.push(node);
}

template<typename T>
T CQueue<T>::deleteHead()
{
	if (!stack2.empty())
	{
		stack2.pop();
	}
	else if (!stack1.empty())
	{
		while (!stack1.empty())
		{
			auto item = stack1.top();
			stack1.pop();
			stack2.push(item);
		}
	}
	else
	{
		throw std::exception("underflow");
	}
	auto head = stack2.top();
	stack2.pop();
	return head;
}

#endif