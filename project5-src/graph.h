#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
	private:
		int numCities;				//Variable that stores the number of vertices in the graph
		int numRoutes;				//Variable that stores the number of possible routes between the vertices of the graph
		double weight;				//Variable that stores the weight of an edge

		string *cities;				//Array of size numCities that stores the names of all the vertices in the order they were added
		double **adjacent;			//Adjacency matrix implementation of graph of size numCities x numCities
		int * disc;				//Array that stores the time of discovery for each vertex
		int * evalFunc;				//Array that stores the data for determining if an edge is a separation edge
		int * parent;				//Array that stores parent info during Dijkstra algorithm and Separation edge calculations
		bool * visited;				//Bool array that indicates if a vertex has been visited or not

		double * dist;				//Array that stores the distance from a vertex to all other vertices
		bool * sptSet;				//Bool array that indicates if the vertex is in the spanning tree

		bool * mstSet;
		int * key;		
	
		vector<pair<string,string>> separations; //Vector that stores all separation edges for output, traverse in reverse order for proper output

		vector<string> adjList;			//Adjacency List vector for Euler Tour
		vector<string> euler;			//Vector to store Euler Tour
	
	public:
		int citiesAdded;			//Number of cities added
		int connectedComponents;		//Connected components for output
		int numSeparations;			//Number of separation edges

		Graph(int, int);
		~Graph(); 
		// Create the graph
		void addRoute(string, string, double);	//Adds route (sets adjacent in adjaceny matrix) given two vertices in the graph
		
		//part 1: Find the connected components and the bridges
		void analyseGraph();			//Function call that calls getConnected and separationEdges()		
		
		// Part 2: Find a ticket using Dijkstra	
		void findCost(const string &source, const string &destination);         
		
		// Part 3: Try to do a tour of all cities
		void eulerianTour(int);			

		//MISC Functions
		void setNumCities(int num);		//Sets number of cities given parameter in constructor
		void setNumRoutes(int num);		//Sets number of routes given parameter in constructor
		void setWeight(int v1, int v2);		//Sets weight in adjacency matrix given two vertices
	
		int getNumCities();			//Returns the number of cities that was passed in constructor
		int getNumRoutes();			//Returns the number of routes that was passed in constructor
		double getWeight(int v1, int v2);	//Get weight of an edge given two vertices
		
		//PART 1 HELPER FUNCTIONS
		void separationHelper(int index);	//Helper function that contains the DFS traversal and calculations
		void separationEdges();			//Find all separation edges

		int exists(string name);		//check if node exists in cities array
		bool isAdjacent(int, int);		//Check adjacency matrix for adjacency of two vertices
	
		void traverse(int index);		//DFS traversal function for finding connected components and bridge edges
		int getConnected();			//Calculate all connected components in the graph

		//PART 2 HELPER FUNCTIONS
		double minimumDist();			//Function for finding the minimum distance between vertices
		void dijkstra(int src, int dest);	//Dijkstra algorithm for finding shortest distance from source to all other points
		void printDistances(int dest);		//prints the distance from source to destination
		void printPaths(int dest);		//prints path from source, through intermediate nodes, to destination

		//PART 3 HELPER FUNCTIONS
		void printMST();			//prints the minimum spanning tree
		void createMST(int root);		//creates a minimum spanning tree using prim-jarnik algorithm
		double minimumKey();			//find the minimum key
		void eulerTour(int root);	
};

#endif
