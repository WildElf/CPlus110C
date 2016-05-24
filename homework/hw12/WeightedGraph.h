// Eric Zimmerman, Assignment 12, CS110C
// A weighted graph with Dijkstra's algorithm
#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H
#define INFINITY    HUGE_VALF
#include <cmath>
#include <iostream>

class WeightedGraph
{
private:
	float** graph;
	bool* vertexSet;
	float* weight;
	int rows;
	int cols;
	float** populateGraph();
public:
	WeightedGraph();
	WeightedGraph(int size);
	~WeightedGraph();
	bool setWeight(int from, int to, float weight);
	int getLowestWeight(int from, int to);
	void algorithmDijkstra();
	void printMatrix();
	void printWeights();
	void printVertextSet();
	void printLowestFromVertex(int from);
};

#endif
