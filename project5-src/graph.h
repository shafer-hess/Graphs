#ifndef GRAPH_H
#define GRAPH_H

#include <string>

using namespace std;

class Graph
{
	private:
		int numCities;
		int numRoutes;
		string *cities;
		double weight;
		
	public:
		
		Graph(int, int); 
		// Create the graph
		void addRoute(string, string, double);	

		//part 1: Find the connected components and the bridges
		void analyseGraph();		
		
		
		// Part 2: Find a ticket using Dijkstra	
		void findCost(const string &source, const string &destination);         
		
		// Part 3: Try to do a tour of all cities
		void eulerianTour(int);  // NOTE : If necessary, you can change the parameters to this function.

};

#endif
