#ifndef VERTEX_H
#define VERTEX_H

#include <string>
#include <vector>

#include "Edge.h"

class Edge;
class Vertex {
	private:
		std::vector<Edge> edgeList;
		std::string name;

	public:
		Vertex(std::string vertexName);
		~Vertex();
		
		void addEdge(Edge * newEdge);
		void setName(std::string newName);
			
		int getNumEdges();
		std::string getName();		
};

#endif
