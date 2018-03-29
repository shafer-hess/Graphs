#include "Edge.h"
#include "Vertex.h"

using namespace std;

Edge::Edge(Vertex * vertex1, Vertex * vertex2, double edgeWeight) {
	this->v1 = vertex1;
	this->v2 = vertex2;
	this->weight = edgeWeight;
}

Edge::~Edge() {}

Vertex * Edge::getV1() {
	return v1;
}

Vertex * Edge::getV2() {
	return v2;
}

double Edge::getWeight() {
	return weight;
}

void Edge::setWeight(double val) {
	this->weight = val;
}

void Edge::setV1(Vertex * vertex) {
	this->v1 = vertex;
}

void Edge::setV2(Vertex * vertex) {
	this->v2 = vertex;
}
