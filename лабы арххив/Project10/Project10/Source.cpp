#include <iostream>
#include<time.h>
#include<set>
#include <algorithm>
using namespace std;

struct Stack1 {
	int top;
	int* data;
};
void InitStack(Stack1& st, int capacity) {
	st.data = new int[capacity];
	st.top = -1;
}
void push(Stack1& st, int value, int capacity) {
	if (st.top == capacity) {
		cout << "Stack overflow" << endl;
	}
	else
	st.data[++st.top] = value;
}
int pop(Stack1& st) {
	return st.data[st.top--];
}
void nullStack(Stack1& st) {
	st.top = -1;
}
bool empty(Stack1& st) {
	return st.top == -1;
}
void PrintStack(Stack1& st) {
	Stack1 tmp = st;
	while(tmp.top!=-1)
		cout << pop(tmp) << endl;
	cout << endl;
}

struct Queue1 {
	int head, tail, size;
	int* data;
};
void nullQueue(Queue1& q) {
	q.head = 0; q.tail = q.size - 1;
}
void InitQueue(Queue1& q,int capacity) {
	q.size = capacity + 1;
	q.data = new int[q.size];
	nullQueue(q);
}
int next(Queue1& q, int n) {
	return (n + 1) % q.size;
}
bool empty(Queue1& q) {
	return next(q, q.tail) == q.head;
}
void add(Queue1& q, int value) {
	if (next(q, next(q, q.tail)) == q.head)
		cout << "Queue overflow" << endl;
	else {
		q.tail = next(q, q.tail);
		q.data[q.tail] = value;
	}
}
int del(Queue1& q) {
	if (empty(q)) {
		cout << "Queue is empty" << endl; return 0;
	}
	else {
		int d = q.data[q.head];
		q.head = next(q, q.head);
		return d;
	}

}

void PrintQueue(Queue1& q) {
	for (int i = q.head; i != next(q, q.tail); i = next(q, i))
		cout << q.data[i] << endl;
	cout << endl;
}


int main() {
	srand(time(NULL));

	Stack1 st1, st2;
	int capacity = 1 + rand() % 100;
	InitStack(st1, capacity);
	for (int i = 0; i <= capacity; i++) {
		push(st1, rand() % 1000, capacity);
	}
	PrintStack(st1);

	Queue1 Que1;
	capacity = 1 + rand() % 100;

	InitQueue(Que1, capacity); 
	for (int i = 0; i < capacity; i++)
		add(Que1, rand() % 1000);

	PrintQueue(Que1);

	set<int> num1;
	while (st1.top != -1) {
		num1.insert(pop(st1));
	}
	set<int> num2;
	for (int i = Que1.head; i != next(Que1, Que1.tail); i = next(Que1, i))
		num2.insert(Que1.data[i]);
	nullQueue(Que1);
	for (int n : num1)
		cout << n << " ";
	cout << endl;
	cout <<"=============================="<< endl;
	for (int n : num2)
		cout << n << " ";
	cout << endl;
	cout << "==============================" << endl;
	set<int> num3;

	set_intersection(num1.begin(), num1.end(),
		num2.begin(), num2.end(),
		inserter(num3, num3.begin()));

	capacity = num3.size();
	InitStack(st2, capacity);
	for (int n : num3)
		push(st2, n, capacity);

	PrintStack(st2);
	cout << endl;
	nullStack(st2);
	system("pause");
	return 0;
}
