#pragma once
#include <iostream>
#ifndef STACK_H
#define STACK_H
#define SIZE 5

struct Node {
	char data;
	Node* link;
};

class Stack {
private:
	Node* head; // top

public:
	Stack() {
		Node* head = NULL;
	}

	Stack(Stack& top) {
		Node* head = NULL;
	}

	~Stack() {  }

	void push(int value) {
		Node* ptr = new Node();
		ptr->data = value;
		ptr->link = head;
		head = ptr;
	}

	void pop() {
		if (empty()) {
			std::cout << "Error: Stack is empty" << std::endl;
		}
		else {
			Node* ptr = head;
			head = head->link;
			delete(ptr);
		}
	}

	int top() {
		if (!empty()) {
			return head->data;
		}
		else {
			exit(0);
		}
	}

	void swap(int a, int b) {
		int temp;
		if (empty()) {
			std::cout << "Stack is Empty";
		}
		else {
			temp = a;
			a = b;
			b = temp;
		}
	}

	int size() {
		int count = 0;
		Node* ptr = head;
		while (ptr != NULL) {
			++count;
			ptr = ptr->link;
		}
		return count;
	}

	bool isFull() {
		if (head != NULL && size() >= SIZE)
			return true;
		else
			return false;
	}

	bool empty() {
		// This said head != NULL for 3 days and 
		// I didn't know it. So that was fun debugging
		if (head == NULL) 
			return true;
		else
			return false;
	}
};
#endif // !STACK_H