#include "maxflow.h"

int main()
{
	int graph[V][V] = { {0,13,0,4,0,0},
						 {0,0,7,0,0,3},
						 {0,0,0,0,0,5},
						 {0,0,0,0,7,0},
						 {0,0,0,0,0,15},
						 {0,0,0,0,0,0} };

	cout << "The maximum possible flow is " << fordFulkerson(graph, 0, 5);

	return 0;
}
