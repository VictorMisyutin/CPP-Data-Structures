//============================================================================
// Name        : CSC240_Test2.cpp
// Author      : Ivan Temesvari
// Date        : 4/19/19
// Description : CSC 240 Test 2 code
//============================================================================
#include "GraphType.h"
#include <iostream>
using namespace std;


int main() {
	//For Floyds algorithm
	GraphType<string> myGraph(10);
	myGraph.AddVertex("A");
	myGraph.AddVertex("B");
	myGraph.AddVertex("C");
	myGraph.AddVertex("D");
	myGraph.AddVertex("E");
	myGraph.AddVertex("F");
	myGraph.AddVertex("G");
	myGraph.AddEdge("A", "B", 80);
	myGraph.AddEdge("B", "A", 80);
	myGraph.AddEdge("B", "C", 79);
	myGraph.AddEdge("B", "E", 153);
	myGraph.AddEdge("C", "B", 79);
	myGraph.AddEdge("C", "D", 78);
	myGraph.AddEdge("C", "F", 74);
	myGraph.AddEdge("D", "C", 78);
	myGraph.AddEdge("D", "E", 98);
	myGraph.AddEdge("D", "F", 89);
	myGraph.AddEdge("E", "B", 153);
	myGraph.AddEdge("E", "D", 98);
	myGraph.AddEdge("E", "F", 67);
	myGraph.AddEdge("F", "C", 74);
	myGraph.AddEdge("F", "D", 89);
	myGraph.AddEdge("F", "E", 67);
	myGraph.AddEdge("F", "G", 67);
	myGraph.AddEdge("G", "F", 67);

	cout << "Before:" << endl;
	cout << myGraph << endl;
	myGraph.allPairsShortestPaths();
	cout << "After:" << endl;
	cout << myGraph << endl;


	// other functions
	GraphType<string> myGraph2(10);
	myGraph2.AddVertex("A");
	myGraph2.AddVertex("B");
	myGraph2.AddVertex("C");
	myGraph2.AddVertex("D");
	myGraph2.AddVertex("E");
	myGraph2.AddVertex("F");
	myGraph2.AddVertex("G");
	myGraph2.AddEdge("A", "B", 80);
	myGraph2.AddEdge("B", "A", 80);
	myGraph2.AddEdge("B", "C", 79);
	myGraph2.AddEdge("B", "E", 153);
	myGraph2.AddEdge("C", "B", 79);
	myGraph2.AddEdge("C", "D", 78);
	myGraph2.AddEdge("C", "F", 74);
	myGraph2.AddEdge("D", "C", 78);
	myGraph2.AddEdge("D", "E", 98);
	myGraph2.AddEdge("D", "F", 89);
	myGraph2.AddEdge("E", "B", 153);
	myGraph2.AddEdge("E", "D", 98);
	myGraph2.AddEdge("E", "F", 67);
	myGraph2.AddEdge("F", "C", 74);
	myGraph2.AddEdge("F", "D", 89);
	myGraph2.AddEdge("F", "E", 67);
	myGraph2.AddEdge("F", "G", 67);
	myGraph2.AddEdge("G", "F", 67);
	string startV = "A";
	string endV = "D";
	ShortestPath(myGraph2, startV);
	DepthFirstSearch(myGraph2, startV, endV);
	BreadthFirstSearch(myGraph2, startV, endV);
	return 0;
}

