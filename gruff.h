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

class Graph {
private:
	map<string, set<string>> nodes;
	bool undirected;

public:
	Graph();
	Graph(bool);
	Graph(string);

	void addEdge(string, string);
	void interactiveAdd();
	
	unsigned int size();
	void print();
};

Graph::Graph() : undirected(true) {}

Graph::Graph(bool ud) : undirected(ud) {}

Graph::Graph(string filename) {
	
}

void Graph::addEdge(string src, string dst) {
	nodes[src].insert(dst);
	if (undirected)
		nodes[dst].insert(src);
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
	for (map<string, set<string>>::iterator src = nodes.begin(); src != nodes.end(); src++) {
		set<string> dsts = src->second;
		cout << '(' << src->first << ") has edges to:\n";

		for (set<string>::iterator dst = dsts.begin(); dst != dsts.end(); dst++)
			cout << "\t(" << *dst << ")\n";
	}
}

#endif