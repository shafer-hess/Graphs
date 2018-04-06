#include "Edge.h"
#include "Vertex.h"

using namespace std;

Vertex::Vertex(string vertexName) {
	this->name = vertexName;
}

Vertex::~Vertex() {}


void Vertex::addEdge(Edge * newEdge) {
	edgeList.push_back(newEdge);
}


void Vertex::setName(string newName) {
	this->name = newName;
}

int Vertex::getNumEdges() {
	return edgeList.size();
	//return 0;
}

string Vertex::getName() {
	return name;
}
