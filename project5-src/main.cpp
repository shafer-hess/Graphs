#include <iostream>
#include <string>
#include "graph.h"
#include <vector>
#include <algorithm>
#include "Edge.h"
#include "Vertex.h"
 
using namespace std;
 

 // Part 1 : Find the connected components and the bridge
void part1() {
	int numCities;
	int numRoutes;
	cin >> numCities;
	cin >> numRoutes;
	
	Graph *  g = new Graph(numCities, numRoutes);

	for(int i = 0; i < numRoutes; i++) {
		string c1;
		string c2;					
		double weight;
		
		cin >> c1;
		cin >> c2;
		cin >> weight;
		g->addRoute(c1, c2, weight);

	}

	g->analyseGraph();
}

 // Part 2 :  Find a ticket using Dijkstra	
void part2() {
	int numCities;
	int numRoutes;

	cin >> numCities;
	cin >> numRoutes;
	
	Graph * g = new Graph(numCities, numRoutes);
	
	for(int i = 0; i < numRoutes; i++) {
		string c1;
		string c2;
		double weight;

		cin >> c1;
		cin >> c2;
		cin >> weight;
		g->addRoute(c1, c2, weight);
	}

	string src;
	string dest;

	while(true) {
		cin >> src;
		cin >> dest;
		
		if(src == "END") { break; }
		g->findCost(src,dest);
		//cout << src << " " << dest << endl;
		//break;
	}

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
