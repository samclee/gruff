#ifndef GRUFF_H
#define GRUFF_H

#include <iostream>
#include <map>
#include <set>
#include <string>
using std::cout;
using std::cin;
using std::map;
using std::set;
using std::string;

/* ========== Node class ========== */
class Node {
private:
	set<string> neighbors;
	bool marked;
public:
	Node();

	bool isMarked();
	set<string> getNeighbors();
	void printNeighbors();
	
	void mark();
	void addNeighbor(string);
	void removeNeighbor(string);
};

Node::Node() : marked(false) {}

bool Node::isMarked() {
	return marked;
} // isMarked()

set<string> Node::getNeighbors() {
	return neighbors;
}

void Node::printNeighbors() {
	for (set<string>::iterator n = neighbors.begin(); n != neighbors.end(); n++)
			cout << "(" << *n << ") ";
	cout << '\n';
} // printNeighbors()

void Node::mark() {
	marked = true;
} // mark()

void Node::addNeighbor(string s) {
	neighbors.insert(s);
} // addNeighbor()

void Node::removeNeighbor(string s) {
	neighbors.remove(s);
}

/* ========== Graph class ========== */
class Graph {
private:
	map<string, Node> nodes;

public:
	Graph();
	Graph(string);

	void addEdge(string, string);
	void interactiveAdd();
	
	unsigned int size();
	void print();
};

Graph::Graph() {}

Graph::Graph(string filename) {
	
}

void Graph::addEdge(string src, string dst) {
	nodes[src].addNeighbor(dst);
}

void Graph::interactiveAdd() {
	cout << "Enter edges with the format: src to dst.\nEnter done to finish.\n";
	string input;

	while (input != "done") {
		cin >> input;
		// parse
		// add edge
	}
}

unsigned int Graph::size() {
	return nodes.size();
}

void Graph::print() {
	for (map<string, Node>::iterator src = nodes.begin(); src != nodes.end(); src++) {
		cout << '(' << src->first << ") has edges to: ";
		src->second.printNeighbors();
	}
}

#endif