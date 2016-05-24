// Eric Zimmerman, Assignment 12, CS110C
// A weighted graph with Dijkstra's algorithm
#include "WeightedGraph.h"

using namespace std;

WeightedGraph::WeightedGraph(int size)
{
	rows = size;
	cols = size;
	vertexSet = new bool[rows];
	weight = new float[rows];

	graph = new float*[rows];
	// initialize arrays by rows
	for (int i=0;i<rows;i++)
	{
		graph[i] = new float[cols];
		weight[i] = INFINITY;
		vertexSet[i] = false;
	}
	// initilize graph columns
	for (int r=0;r<rows;r++)
		for (int c=0;c<cols;c++)
		{
			if (r != c)
				graph[r][c] = INFINITY;
			else
				graph[r][c] = 0.0;
		}
}

WeightedGraph::WeightedGraph()
{
	rows = cols = 6;
	vertexSet = new bool[rows];
	weight = new float[rows];
	graph = populateGraph();
}

WeightedGraph::~WeightedGraph()
{
	for (int i=rows-1;i>=0;i--)
		delete [] graph[i];

		delete [] graph;
}

float** WeightedGraph::populateGraph()
{
	float** pop = new float*[rows];

  for (int row=0;row<rows;row++)
	{
		pop[row] = new float[cols];
		weight[row] = INFINITY;
		vertexSet[row] = false;
		for (int col=0;col<cols;col++)
    {
      if (row != col)
        pop[row][col] = HUGE_VALF;
      else
        pop[row][col] = 0.0;
    }
	}

  pop[0][1] = pop[1][0] = 120;
  pop[0][2] = pop[2][0] = 150;
  pop[0][5] = pop[5][0] = 500;
  pop[1][3] = pop[3][1] = 75;
  pop[1][5] = pop[5][1] = 350;
  pop[2][4] = pop[4][2] = 250;
  pop[3][4] = pop[4][3] = 150;

	return pop;
}

bool WeightedGraph::setWeight(int from, int to, float weight)
{
	if (from <= rows && to <= cols && from != to)
	{
		graph[from][to] = graph[to][from] = weight;
		return true;
	}
	else
		return false;
}

int WeightedGraph::getLowestWeight(int from, int to)
{
	return 0;
}

void WeightedGraph::algorithmDijkstra()
{
	int lowest = 1, v, u;
	// initialize vertexSet
	vertexSet[0] = true;
	bool incomplete = true;

	// initlize weight array
	for (v=0;v<rows;v++)
	{
		weight[v] = graph[0][v];
		if (weight[v] > 0 && weight[v] < weight[lowest])
			lowest = v;
	}


//  int loopProtection = 0;
	while (incomplete)
	{

		for (int i=0;i<rows;i++) // check if vertexSet is complete
		{
			incomplete = false;
			if (!vertexSet[i])
			{ // if not, update lowest out of the set
				incomplete = true;
				if (weight[i] > 0 && weight[i] < weight[lowest])
					lowest = i;
				else if (vertexSet[lowest])
					lowest = i;
			}
		}

		if (!vertexSet[lowest])
		{
			vertexSet[lowest] = true;
//			cout << lowest << " added to set\n";
		}
		else if (incomplete)
			cout << "WARNING: lowest column (" << lowest << ") is already in the set";

		for (int u=0;u<rows;u++)
		{
			if ((!vertexSet[u]) && (weight[u] > weight[lowest] + graph[lowest][u]))
			{
//				cout << u << " not in vertexSet, " << weight[u] << " is changing to " << weight[lowest]+graph[lowest][u];
				weight[u] = weight[lowest] + graph[lowest][u];
//				cout << "...confirmed: weight[" << u << "] is now " << weight[u] << endl;
			}
		}

//		printWeights();
//		printVertextSet();
	}
}

void WeightedGraph::printMatrix()
{

	for (int r=0;r<rows;r++)
	{
		if (r == 0)
		{
			cout << "    ";
			for (int c=0;c<cols;c++)
				cout << "   " << c << "  ";

			cout << endl;
		}

		cout << " " << r << "  ";
		for (int c=0;c<cols;c++)
		{
			if (isinf(graph[r][c])) // checks for INFINITY
				cout << "|  ∞  ";
			else if ((int)graph[r][c] < 10) // single digit formatting
				cout << "|  " << (int)graph[r][c] << "  ";
			else if ((int)graph[r][c] < 100) // double digit formatting
				cout << "|  " << (int)graph[r][c] << " ";
			else // triple digit formatting
				cout << "| " << (int)graph[r][c] << " ";
		}
		cout << "|" << endl;
	}
}

void WeightedGraph::printWeights()
{
	cout << "From Vertex 0: ";

	for (int i=0;i<cols;i++)
	{
		if (isinf(weight[i])) // checks for INFINITY
			cout << "  ∞  ";
		else if (weight[i] < 10)
			cout << "  " << weight[i] << "  ";
		else if (weight[i] < 100)
			cout << "  " << weight[i] << " ";
		else
			cout << " " << weight[i] << " ";
	}
	cout << endl;
}

void WeightedGraph::printVertextSet()
{
	cout << "Vertex set: ";
	for (int i=0;i<rows;i++)
		if (vertexSet[i])
			cout << "  " << i << " ";
	cout << endl;
}

void WeightedGraph::printLowestFromVertex(int from)
{

}
