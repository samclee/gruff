#include "gruff.h"

int main() {
	Graph g;
	g.interactiveAdd();
	g.addEdge("a", "v");
	g.print();

	return 0;
}