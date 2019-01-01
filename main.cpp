#include "gruff.h"

int main() {
	UndirectedGraph g("test.txt");
	g.mark("a");
	g.mark("groof");
	g.mark("doesn't exist");
	if (g.isMarked("groof"))
		cout << "groof marked\n";
	if (g.isMarked("lalalalal"))
		cout << "I hope this doesn't print\n";

	set<string> cnbors = g.getNeighborsOf("c");
	for (string n : cnbors)
		cout << n << '\n';
	g.print();

	return 0;
}