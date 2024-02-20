#pragma once

class Queue
{

private:
	struct Node1
	{
		int data;
		Node1* next;
	};
	Node1* head, * tail;
public:
	Queue();
	bool Empty();
	void Add(int value);
	int Get();
	void Del();
	void PrintQueue();
	void NullQueue();
};

