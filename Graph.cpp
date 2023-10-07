#include "Graph.h"
Graph::Graph() {
	start = NULL;
	size = 0;
}

Graph::~Graph() {

}

void Graph::InsertNode(char p) {
	start = new Node(start, NULL, p);
	size++;
}

Node* Graph::FindNode(char p){
	Node* tmp = start;
	while (tmp != NULL && tmp->name != p)
		tmp = tmp->next;

	return tmp;
}

void Graph::InsertEdge(char a, char b, int w) {
	Node* pa = FindNode(a);
	Node* pb = FindNode(b);
	if (pa != NULL && pb != NULL) {
		Edge *e = new Edge(pb, pa->adj, w);
		pa->adj = e;
	}
}

Edge* Graph::FindEdge(char a, char b) {
	Node* pa = FindNode(a);
	Node* pb = FindNode(b);
	if (pa != NULL && pb != NULL) {
		Edge* e = pa->adj;
		while (e != NULL && e->dest != pb)
			e = e->link;

		return e;
	}
	else return 0;
}

void Graph::Route(int max, char a, char b) {
	Node* tmp = FindNode('A');
}

void Graph::MaxIzlazniStepen() {
	int max=0, now=0;
	char n = start->name;
	Node* tmp = start;
	Node* tmp2 = start;
	while (tmp != NULL) {
		while (tmp2 != NULL) {
			if (EdgeExists(tmp->name, tmp2->name)) {
				now++;

			}

			tmp2 = tmp2->next;
		}
		if (now > max) {
			max = now;
			n = tmp->name;
		}
		now = 0;
		tmp2 = start;
		tmp = tmp->next;
	}
	cout << "Cvor: " << n << " ima najvise ulaznih cvorova, i to: " << max << endl;
}

void Graph::MaxUlazniStepen() {
	int max = 0, now = 0;
	char n = start->name;

	Node* tmp = start;
	Node* tmp2 = start;
	while (tmp != NULL) {
		while (tmp2 != NULL) {
			if (EdgeExists(tmp2->name, tmp->name)) {
				now++;

			}

			tmp2 = tmp2->next;
		}
		if (now > max) {
			max = now;
			n = tmp->name;
		}
		now = 0;
		tmp2 = start;
		tmp = tmp->next;
	}
	cout << "Cvor: " << n << " ima najvise izlaznih cvorova, i to: " << max << endl;
}

void Graph::MinIzlazniStepen() {
	int min = size, now = 0;
	char n = start->name;
	Node* tmp = start;
	Node* tmp2 = start;
	while (tmp != NULL) {
		while (tmp2 != NULL) {
			if (EdgeExists(tmp->name, tmp2->name)) {
				now++;

			}

			tmp2 = tmp2->next;
		}
		if (now < min) {
			min = now;
			n = tmp->name;
		}
		now = 0;
		tmp2 = start;
		tmp = tmp->next;
	}
	cout << "Cvor: " << n << " ima najmanje izlaznih cvorova, i to: " << min << endl;
}

void Graph::MinUlazniStepen() {
	int min = size, now = 0;
	char n = start->name;
	Node* tmp = start;
	Node* tmp2 = start;
	while (tmp != NULL) {
		while (tmp2 != NULL) {
			if (EdgeExists(tmp2->name, tmp->name)) {
				now++;

			}

			tmp2 = tmp2->next;
		}
		if (now < min) {
			min = now;
			n = tmp->name;
		}
		now = 0;
		tmp2 = start;
		tmp = tmp->next;
	}
	cout << "Cvor: " << n << " ima najmaje uaznih cvorova, i to: " << min << endl;
}

bool Graph::JakoPovezanGraf() {
	int number = 0;
	Node* tmp = start;
	Node* tmp2 = start;
	while (tmp != NULL) {
		while (tmp2 != NULL) {
			if (EdgeExists(tmp->name, tmp2->name)) {
				number++;
			}
			tmp2 = tmp2->next;
		}
		tmp2 = start;
		tmp = tmp->next;
	}
	cout << "Broj potega: " << number << ", koliko treba biti povezano: " << size * (size - 1) << endl;
	if (number == (size - 1) * size)
		return true;
	return false;
}

bool Graph::EdgeExists(char a, char b) {
	if (FindEdge(a, b))
		return true;
	return false;
}

void Graph::PrintGraph() {
	Node* tmp = start;
	Node* tmp2 = start;
	while (tmp != NULL) {
		cout << "[" << tmp->name << "] ";
		while (tmp2 != NULL) {
			if (EdgeExists(tmp->name, tmp2->name)) {
				Edge* e = FindEdge(tmp->name, tmp2->name);
				cout << "[" << tmp->name << "]" << "->|" << e->weight << "|->";
			}
			cout << "[" << tmp2->name << "] ";
			tmp2 = tmp2->next;
		}
		cout << endl;
		cout << endl;
		tmp2 = start;
		tmp = tmp->next;
	}
}