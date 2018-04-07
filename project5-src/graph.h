#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <algorithm>

//#include "Edge.h"
//#include "Vertex.h"

using namespace std;

class Graph {
	private:
		int numCities;
		int numRoutes;
		double weight;

		string *cities;
		double **adjacent;
		int * disc;
		int * evalFunc;
		int * parent;
		bool * visited;

		double * dist;
		bool * sptSet;
		
		vector<pair<string,string>> separations;
	
	public:
		int citiesAdded;			//Number of cities added
		int connectedComponents;		//Connected components for output
		int numSeparations;			//Number of separation edges

		Graph(int, int); 
		// Create the graph
		void addRoute(string, string, double);	
		
		//part 1: Find the connected components and the bridges
		void analyseGraph();		
		
		// Part 2: Find a ticket using Dijkstra	
		void findCost(const string &source, const string &destination);         
		
		// Part 3: Try to do a tour of all cities
		void eulerianTour(int);  // NOTE : If necessary, you can change the parameters to this function.

		//MISC Functions
		void setNumCities(int num);
		void setNumRoutes(int num);
		void setWeight(int num);
	
		int getNumCities();
		int getNumRoutes();
		double getWeight();
		
		//PART 1 HELPER FUNCTIONS
		void separationHelper(int index);
		void separationEdges();

		int exists(string name);
		bool isAdjacent(int, int);
	
		void traverse(int index);
		int getConnected();		//For free

		//PART 2 HELPER FUNCTIONS
		double minimumDist();
		void dijkstra(int src, int dest);
		void printDistances();
		
};

#endif
