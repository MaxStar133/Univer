#include "Header.h"
#include <iostream>


Queue::Queue() {
	head = NULL;
	tail = NULL;
}
bool Queue::Empty() {
	return head == NULL;
}
void Queue::Add(int value) {
	if (Empty()) {
		head = new Node1;
		head->data = value;
		head->next = NULL;
		tail = head;
	}
	else {
		tail->next = new Node1;
		tail = tail->next;
		tail->data = value;
		tail->next = NULL;
	}
}
void Queue::Del() {
	if (Empty()) {
		std::cout << "Queue is empty" << std::endl;
	}
	else {
		Node1* tmp = head;
		head = head->next;
		delete(tmp);
	}
}
int Queue::Get(){
	if (Empty()){
		std::cout << "Queue is empty" << std::endl;
		return 0;
	}
	else{
		int r_data = head->data;
		Node1* tmp = head;
		head = head->next;
		delete tmp;
		return r_data;
	}
}
void Queue::PrintQueue() {
	Node1* current = head;
	while (current != NULL) {
		std::cout << current->data <<std::endl;
		current = current->next;
	}
}
void Queue::NullQueue() {
	Node1* tmp;
	while (!Empty()) {
		tmp = head;
		head = head->next;
		delete(tmp);
	}
}


