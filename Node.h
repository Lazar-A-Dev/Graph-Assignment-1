#pragma once
#include<iostream>
#include"Edge.h"
using namespace std;
class Node {
public:
	Node* next;
	Edge* adj;
	char name;

public:

	Node() {
		next = NULL;
		adj = NULL;
		name = NULL;
	}

	Node(Node* next, Edge* adj, char name) {
		this->next = next;
		this->adj = adj;
		this->name = name;
	}

	void Print() {
		cout << name;
	}
};
