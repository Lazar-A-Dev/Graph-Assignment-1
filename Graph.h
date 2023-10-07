#pragma once
#include<iostream>
#include"Node.h"
using namespace std;
class Graph
{
public:
	Node* start;
	int size;

public:

	Graph();
	~Graph();
	void InsertNode(char p);
	Node* FindNode(char p);
	void InsertEdge(char a, char b, int w);
	Edge* FindEdge(char a, char b);
	bool EdgeExists(char a, char b);
	void Route(int max, char a, char b);
	void MaxIzlazniStepen();//stampa ime cvora i koliko potega izlaze iz njega
	void MaxUlazniStepen();//stampa ime cvora i koliko potega ulaze u njemu
	void MinIzlazniStepen();
	void MinUlazniStepen();
	bool JakoPovezanGraf();
	void PrintGraph();
};

