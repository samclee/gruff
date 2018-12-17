#ifndef GRUFF_H
#define GRUFF_H

#include <iostream>
#include <map>
#include <set>
#include <string>
using std::cout;
using std::map;
using std::set;
using std::string;

class Graph {
private:
	map<string, set<int>> nodes;
public:
	Graph();
	unsigned int size();
};

Graph::Graph() {}

unsigned int Graph::size() {
	return nodes.size();
}

#endif