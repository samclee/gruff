#ifndef GRUFF_H
#define GRUFF_H

#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <utility>
using std::cout;
using std::cin;
using std::ifstream;
using std::map;
using std::set;
using std::string;
using std::pair;
using std::make_pair;

string eatSpaces(string s) {
	int l = 0, r = s.size()-1;
	while (l <= r && s[l] == ' ') l++;
	while (r >= l && s[r] == ' ') r--;

	if (r < l)
		return "";

	return s.substr(l, r-l+1);
}


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
} // getNeighbors()

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
	neighbors.erase(s);
} // removeNeighbor()

/* ========== Graph class ========== */
class Graph {
protected:
	map<string, Node> nodes;

public:
	Graph();
	Graph(string);

	void addNode(string);
	void removeNode(string);
	virtual void addEdge(string, string);
	virtual void removeEdge(string, string);
	pair<string,string> parse(string);
	void interactiveAdd();
	
	unsigned int size();
	void print();
};

Graph::Graph() {}

Graph::Graph(string filename) {
	ifstream ifs(filename);

	string line;
	while (getline(ifs, line)) {
		pair<string,string> endpoints = parse(line);
		if (endpoints.second == "") {
			addNode(endpoints.first);
		}
		else {
			addEdge(endpoints.first, endpoints.second);
		}
	}
} // file constructor

void Graph::addNode(string s) {
	nodes[s];
} // addNode()

void Graph::removeNode(string s) {
	nodes.erase(s);
	for (map<string, Node>::iterator src = nodes.begin(); src != nodes.end(); src++) {
		src->second.removeNeighbor(s);
	}
} // removeNode()

void Graph::addEdge(string src, string dst) {
	nodes[src].addNeighbor(dst);
	addNode(dst);
} // addEdge()

void Graph::removeEdge(string src, string dst) {
	if (nodes.find(src) == nodes.end())
		return;
	nodes[src].removeNeighbor(dst);
} // removeEdge()

pair<string,string> Graph::parse(string line) {
	string src, dst;

	int midpoint = line.find("->");
	if (midpoint == string::npos) {
		src = line;
	}
	else {
		src = line.substr(0, midpoint);
		src = eatSpaces(src);
		dst = line.substr(midpoint+2);
		dst = eatSpaces(dst);
	}
	
	return make_pair(src, dst);
} // parse file input into node names

void Graph::interactiveAdd() {
	cout << "Enter edges with the format: src -> dst.\nEnter done to finish.\n";
	
	string line;
	while (getline(cin, line) && line != "done") {
		pair<string,string> endpoints = parse(line);
		if (endpoints.second == "") {
			addNode(endpoints.first);
		}
		else {
			addEdge(endpoints.first, endpoints.second);
		}
	}
} // interactively add nodes

unsigned int Graph::size() {
	return nodes.size();
} // size()

void Graph::print() {
	for (map<string, Node>::iterator src = nodes.begin(); src != nodes.end(); src++) {
		cout << '(' << src->first << ") has edges to: ";
		src->second.printNeighbors();
	}
} // prints()

/* ========== Undirected Graph class ========== */
class UndirectedGraph : public Graph {
public:
	UndirectedGraph();
	UndirectedGraph(string);

	virtual void addEdge(string, string);
	virtual void removeEdge(string, string);
};

UndirectedGraph::UndirectedGraph() {}

UndirectedGraph::UndirectedGraph(string filename) : Graph() {
	ifstream ifs(filename);

	string line;
	while (getline(ifs, line)) {
		pair<string,string> endpoints = parse(line);
		if (endpoints.second == "") {
			addNode(endpoints.first);
		}
		else {
			addEdge(endpoints.first, endpoints.second);
		}
	}
}

void UndirectedGraph::addEdge(string src, string dst) {
	nodes[src].addNeighbor(dst);
	nodes[dst].addNeighbor(src);
}

void UndirectedGraph::removeEdge(string src, string dst) {
	if (nodes.find(src) == nodes.end() || nodes.find(dst) == nodes.end())
		return;
	nodes[src].removeNeighbor(dst);
	nodes[dst].removeNeighbor(src);
}

#endif