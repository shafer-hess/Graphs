#include <iostream>
#include <string>
#include "graph.h"
#include "Edge.h"
#include "Vertex.h"
 
using namespace std;
 

 // Part 1 : Find the connected components and the bridge
void part1() {
	Vertex * v1 = new Vertex("A");
	Vertex * v2 = new Vertex("B");
	Edge * e1 = new Edge(v1,v2,12.5);

	cout << e1->getV1()->getName() << " " << e1->getV2()->getName() << " " << e1->getWeight() << endl;

}

 // Part 2 :  Find a ticket using Dijkstra	
void part2() {

}

 // Part 3 :Try to do a tour of all cities 
void part3() {
 

}
 
int main() {
	 double cmd;
	 cin >> cmd;

	 if(cmd == 1) part1();
	 else if(cmd == 2) part2();
	 else if(cmd == 3) part3();

	 return 0;
 }
