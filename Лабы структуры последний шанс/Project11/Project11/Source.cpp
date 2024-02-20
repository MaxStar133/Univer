#include "Header.h"
#include <iostream>
#include<time.h>
#include<set>
#include <algorithm>
using namespace std;

struct Node {
	int data;
	Node* next;
};

void InitStack(Node*& top) { top = NULL; }

void push(Node*& top, int value) {
	Node* tmp=new Node; 
	tmp->next = top;
	top = tmp;
	top->data = value;
}

int pop(Node*& top) {
	Node* tmp=top; 
	int d = top->data;
	top = top->next;
	delete(tmp);
	return d;
}

bool empty(Node*& top){
return top == NULL;
}

void nullStack(Node*& top) {
	Node* tmp;
	while (!empty(top)) {
		tmp = top;
		top = top->next;
		delete(tmp);
	}
}
void PrintNode(Node*& top) {
	Node* current = top;
	while (current != NULL) {
		cout << current->data << endl;
		current = current->next;
	}
}

int main() {
	srand(time(NULL));
	Node* st1,* st2;
	InitStack(st1);
	int capacity1 = 1 + rand() % 100;
	for (int i = 0; i <=capacity1; i++)
		push(st1, rand() % 1000);
	
	PrintNode(st1);
	cout << endl;

	Queue que;
	int capacity2 = 1 + rand() % 100;
	for (int i = 0; i <= capacity2; i++)
		que.Add(rand() % 1000);
	que.PrintQueue();
	cout << endl;

	set<int> num1;
	while(!empty(st1))
		num1.insert(pop(st1));

	set<int> num2;
	while(!que.Empty())
		num2.insert(que.Get());

	for (int n : num1)
		cout << n << " ";
	cout << endl;
	cout << "==============================" << endl;
	for (int n : num2)
		cout << n << " ";
	cout << endl;
	cout << "==============================" << endl;
	set<int> num3;
	set_intersection(num1.begin(), num1.end(),
		num2.begin(), num2.end(),
		inserter(num3, num3.begin()));

	InitStack(st2);
	for (int n : num3)
		push(st2, n);

	PrintNode(st2);
	system("pause"); 
	return 0;
}