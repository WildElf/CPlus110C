// Eric Zimmerman, Assignment 12, CS110C
// A weighted graph with Dijkstra's algorithm
#include "WeightedGraph.h"
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
  int size = 6;

  WeightedGraph graph;
  graph.printMatrix();
  cout << endl << endl;

  graph.algorithmDijkstra();
//  graph.printMatrix();
  cout << "  From SFO to   SFO  LAX  LAS  PHX  DEN  JFK\n";
  graph.printWeights();

}
