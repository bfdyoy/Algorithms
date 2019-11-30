#ifndef MAX_FLOW_H
#define MAX_FLOW_H

#include <iostream>
#include <cstdbool>
#include <queue>
#include <limits.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define V 6

bool bfs(int rGraph[V][V], int s, int t, int parent[]);
int fordFulkerson(int graph[V][V], int s, int t);

#endif // !MAX_FLOW_H
