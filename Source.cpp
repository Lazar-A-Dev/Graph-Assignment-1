#include<iostream>
#include"Graph.h"
using namespace std;
void main() {
	Graph g;
	g.InsertNode('A');
	g.InsertNode('B');
	g.InsertNode('C');
	g.InsertNode('D');
	g.InsertNode('E');
	g.InsertNode('F');
	g.InsertNode('G');

	g.InsertEdge('A', 'F', 3);
	g.InsertEdge('F', 'B', 4);
	g.InsertEdge('A', 'D', 1);
	g.InsertEdge('D', 'C', 5);
	g.InsertEdge('D', 'E', 2);
	g.InsertEdge('D', 'G', 1);
	g.InsertEdge('E', 'G', 1);
	g.InsertEdge('C', 'G', 1);

	g.InsertEdge('F', 'A', 3);
	g.InsertEdge('B', 'F', 4);
	g.InsertEdge('D', 'A', 1);
	g.InsertEdge('C', 'D', 5);
	g.InsertEdge('E', 'D', 2);
	g.InsertEdge('G', 'D', 1);
	g.InsertEdge('G', 'E', 1);
	g.InsertEdge('G', 'C', 1);

	//g.InsertEdge('B', 'D', 2);

	g.PrintGraph();
	cout << endl;
	g.MaxIzlazniStepen();
	g.MaxUlazniStepen();
	cout << "jako povezan graf: " << g.JakoPovezanGraf() << endl;
	g.MinIzlazniStepen();
	g.MinUlazniStepen();
	system("pause");
}