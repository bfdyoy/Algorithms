#pragma once
#ifndef ROYFLOYD_CODE_H
#define ROYFLOYD_CODE_H

#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <vector>
#include <malloc.h>
using namespace std;

#define Infinit 90000

typedef struct edge																	//structure for edge
{
	int source;																		//source vertex
	int destination;																//destination vertex
	int weight;																		//edge weight
};

typedef struct graph																//structure for graph
{
	int noOfVertices;																//number of vertixes
	int noOfEdges;																	//number of edges
	edge* pEdge;																	//edges
};

graph* loadGraph(int *matrix[], int n, int m);

bool nodeVisited(std::vector<int>& visited, int node);

vector<int> getAdjNodes(graph* G, int node);

vector<int> getAdjWeights(graph* G, int node);

void initial_cost(int cost[100][100], int& n, int& m);

void display_matrix(int cost[100][100], int n);

void Roy_Floyd(int cost[100][100], int n);

void print_path(int first, int last, int cost[100][100], int n);

void compute_path(int node1, int node2, int n, int cost[100][100]);

#endif //ROYFLOYD_CODE_H