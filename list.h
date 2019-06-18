// Basic singly linked list without error checking.
#ifndef _SMART_LIST_H_
#define _SMART_LIST_H_

#include <iostream> // cout
#include <memory>   // smart pointer

template <typename T>
class list
{
private:
	template <typename T>
	struct node
	{
		node(T e) { element = e; }

		T element;
		std::shared_ptr<node<T>> next = nullptr;
	};

	std::shared_ptr<node<T>> head = nullptr, tail = nullptr;

public:
	~list() { clear(); };

	friend std::ostream& operator<< (std::ostream& os, const list<T>& list)
	{
		for (auto node = list.head; node; node = node->next)
			os << node->element;
		return os << std::endl;
	}

	void clear()
	{
		while (!empty())
			pop_front();
		head.reset(), tail.reset();
	}
	
	std::size_t size() const
	{ 
		std::size_t size = 0;
		for (auto node = head; node; node = node->next, size++);
		return size;
	}
	
	bool empty() const { return head == nullptr; }
	
	T& back() const { return tail->element; }
	T& front() const { return head->element; }

	void push_back(const T& e) 
	{
		auto newNode{ std::make_shared<node<T>>(e) };
		if (!head)
			head = newNode;
		if (tail)
			tail->next = newNode;
		tail = newNode;
	}

	void push_front(const T& e) 
	{
		auto newNode{ std::make_shared<node<T>>(e) };
		if (!tail)
			tail = newNode;
		newNode->next = head;
		head = newNode;
	}

	void pop_front() 
	{
		if (empty())
			return;
		if (tail == head)
			tail.reset();
		auto temp = head;
		head = std::move(head->next);
		temp.reset();
	}
};

#endif
