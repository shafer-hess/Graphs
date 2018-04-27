#include <iostream>
#include <iomanip>
#include <string>
#include "graph.h"

#define INFI 1000000

/*
	Graph class for use in Project 5.
	
	This provided code does not include any specific data structure
	for storing a graph, only a list of methods that will be called 
	from main. Based on the project handout and the lecture slides,
	select a method for storing the graph and implement it here.

*/

// Constructor for Graph 
Graph::Graph(int Vertices, int routes) {
	this->setNumCities(Vertices);
	this->setNumRoutes(routes);

	int citiesAdded = 0;
	int connectedComponents = 0;

	adjacent = new double*[Vertices];
	for(int i = 0; i < Vertices; i++) { adjacent[i] = new double[Vertices]; } 

	cities = new string[Vertices];
	visited = new bool[Vertices];
	disc = new int[Vertices];
	evalFunc = new int[Vertices];
	parent = new int[Vertices];
	dist = new double[Vertices];
	sptSet = new bool[Vertices];
	mstSet = new bool[Vertices];
	key = new int[Vertices];

	for(int i = 0; i < Vertices; i++) {
		cities[i] = "";
		disc[i] = -1;
		evalFunc[i] = -1;
		//parent[i] = -1;
		visited[i] = false;
	} 
}

Graph::~Graph() {
	delete [] cities;
	delete [] visited;
	delete [] disc;
	delete [] evalFunc;
	delete [] parent;
	delete [] dist;
	delete [] sptSet;
	delete [] mstSet;
	delete [] adjacent;
	delete [] key;
}

int Graph::exists(string name) {
	for(int i = 0; i < numCities; i++) {
		if(cities[i] == name) {
			return i;
		}
	}
	return -1;
}

void Graph::addRoute(string c1, string c2, double weight) {
	int cPos1 = exists(c1);
	int cPos2 = exists(c2);
	
	if(cPos1 == -1) {
		cities[citiesAdded] = c1;
		cPos1 = citiesAdded;
		citiesAdded++;
	}

	if(cPos2 == -1) {
		cities[citiesAdded] = c2;
		cPos2 = citiesAdded;
		citiesAdded++;
	}

	adjacent[cPos1][cPos2] = weight;
	adjacent[cPos2][cPos1] = weight;

}

void Graph::analyseGraph() {
	int components = getConnected();
	cout << components << endl;
	separationEdges();
}

void Graph::traverse(int index) {
	visited[index] = true;
	
	int j;
	for(j = 0; j < numCities; j++) {
		if(visited[j] == false && isAdjacent(index, j)) {
			traverse(j);
		}
	}
}

int Graph::getConnected() {

	int connected = 0;
	
	for(int i = 0; i < numCities; i++) { visited[i] = false; }
	for(int i = 0; i < numCities; i++) {
		if(visited[i] == false) {
			connected++;
			traverse(i);
		}
	}

	return connected;
}

void Graph::separationHelper(int index) {
	static int time = 0;
	visited[index] = true;	
	disc[index] = evalFunc[index] = ++time;

	for(int i = 0; i < numCities; i++) {
		if(isAdjacent(index, i)) {
			if(!visited[i]) {
				parent[i] = index;
				separationHelper(i);
				
				evalFunc[index] = min(evalFunc[index], evalFunc[i]);
				if(evalFunc[i] > disc[index]) {
					if(cities[i] < cities[index]) {
						numSeparations++;
						separations.push_back(make_pair(cities[i], cities[index]));
					}
					else {
						numSeparations++;
						separations.push_back(make_pair(cities[index], cities[i]));
					}
				}
			}
			else if(i != parent[index]) {
				evalFunc[index] = min(evalFunc[index], disc[i]);
			}
		}
	}
}

bool strCompare(string s1, string s2) { return s1 < s2; }

void Graph::separationEdges() {
	for(int i = 0; i < numCities; i++) { visited[i] = false; }

	for(int i = 0; i < numCities; i++) {
		if(visited[i] == false) {
			separationHelper(i);
		}
	}

	cout << numSeparations << endl;
	for(int i = separations.size() -1; i >= 0; i--) {
		cout << separations[i].first << " " << separations[i].second << endl;
	}
}

bool Graph::isAdjacent(int i1, int i2) {
	return (adjacent[i1][i2] != 0) ? true : false;
}

double Graph::minimumDist() {
	double  min = INFI;
	double  minIndex = INFI;

	for(int i = 0; i < numCities; i++) {
		if(sptSet[i] == false && dist[i] <= min) {
			min = dist[i];
			minIndex = i;
		}
	}
	
	return minIndex;

}

double Graph::minimumKey() {
	double min = INFI;
	double minIndex = INFI;
	
	for(int i = 0; i < numCities; i++) {
		if(mstSet[i] == false && key[i] < min) {
			min = key[i];
			minIndex = i;
		}
	}

	return minIndex;

}

void Graph::findCost(const string &source, const string &destination) {
	int src;
	int dest;
	for(int i = 0; i < numCities; i++) {
		if(cities[i] == source) {
			src = i;	
		}
		if(cities[i] == destination) {
			dest = i;
		}
	}

	dijkstra(src, dest);
}

void Graph::dijkstra(int src, int dest) {
	for(int i = 0; i < numCities; i++) {
		parent[i] = -1;			//PARENT ARRAY FOR INTERMEDIATE PATHS
		dist[i] = INFI;
		sptSet[i] = false;
	}

	dist[src] = 0;
	
	for(int i = 0; i < numCities - 1; i++) {
		int d = minimumDist();
		sptSet[d] = true;
		
		for(int i = 0; i < numCities; i++) {
			if(!sptSet[i] && adjacent[d][i] && dist[d] != INFI && dist[d] + adjacent[d][i] < dist[i]) {
				parent[i] = d;
				dist[i] = dist[d] + adjacent[d][i];
			}
		}
	}

	int flag = 0;
	for(int i = 0; i < numCities; i++) {
		if(parent[i] != -1 && parent[i] != 0) { flag = 1; }
	}

	if(flag || (dist[src] == 0 && flag == 0 && dist[dest] != INFI)) {
		cout << cities[src] << " ";	
		printPaths(dest);
	
		cout << std::fixed;	
		cout << std::setprecision(2);
		cout << dist[dest] << endl;
	}

	else {
		cout << "not possible" << endl;
	}
}

void Graph::createMST(int root) {
	for(int i = 0; i < numCities; i++) {
		key[i] = INFI;
		mstSet[i] = false;
	}
	
	key[root] = 0;
	parent[root] = -1;
	
	for(int i = 1; i < numCities-1; i++) {
		int d = minimumKey();
		mstSet[d] = true;
		
		for(int i = 0; i < numCities; i++) {
			if(adjacent[d][i] && !mstSet[i] && (adjacent[d][i] < key[i])) {
				parent[i] = d;
				key[i] = adjacent[d][i];
			}
		}
	
	}	
}


void Graph::printDistances(int dest) {
	cout << "Vertex    Distance from Source" << endl;		
	for(int i = 0; i < numCities; i++) {
		if(cities[dest] == cities[i]) {
			cout << cities[i] << "   " << dist[i] << endl; 
		}
	}
}

void Graph::printPaths(int dest) {
	if(parent[dest] == -1) { return; }
	printPaths(parent[dest]);
	cout << cities[dest] << " ";
}

void Graph::eulerTour(int root) {

	vector<string> children;
	cout << cities[root] << endl;
	for(int i = 0; i < numCities; i++) {
		if(parent[i] == root) {
			children.push_back(cities[i]);
		}
	}
	
	sort(children.begin(), children.end(), strCompare);
	for(int i = 0; i < children.size(); i++) {
		int pos = exists(children[i]);
		eulerTour(pos);
	}

}

void Graph::printMST() {
	cout << "Edge  Weight" << endl;
	for(int i = 1; i < numCities; i++) {
		cout << std::fixed;
		cout << std::setprecision(2);
		cout << parent[i] << " - " << i << "   " << adjacent[i][parent[i]] << endl;
	}
}

void Graph::setNumCities(int num) {
	numCities = num;
}

void Graph::setNumRoutes(int num) {
	numRoutes = num;
}
