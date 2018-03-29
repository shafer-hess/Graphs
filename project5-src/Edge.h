#ifndef EDGE_H
#define EDGE_H

#include <string>
#include <vector>

#include "Vertex.h"

class Edge {
	private:
		Vertex * v1;
		Vertex * v2;
		double weight;	

	public:
		Edge(Vertex * vertex1, Vertex * vertex2, double edgeWeight);
		~Edge();

		void setV1(Vertex * vertex);
		void setV2(Vertex * vertex);
		void setWeight(double val);

		double getWeight();
		Vertex * getV1();
		Vertex * getV2();
};

#endif
