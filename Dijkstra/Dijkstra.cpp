#include <vector>
#include <set>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdbool>
#include <fstream>

#define DIM 50010
#define INF DIM*1000
#define MAX_VERTICES 50
#define MAX_WEIGTH 50

using namespace std;

vector<pair<int, int>> adjacency_list[DIM]; /// aici se creeaza un vector de vectori de perechi (fiecare element
											///al vectorului are 2 campuri de tip int),
											/// in care o sa pastram lista de adiacenta al fiecarui nod.
set<pair<int, int>> tail; ///creem un set in care pastram nodul si distanta acestuia;
							/// perechile din set sunt ( distance[nod], nod)

int distances[DIM], x, y, c, no_vertices, no_edges, k;

ifstream fin("dijkstra.in");
ofstream fout("test.in");

int matrix[20][20];

void generateInput(int noVertices, int procent)
{
	int it, it2;
	if (!fout.is_open())
	{
		cout << "File couldn't be opened!";
	}
	fout.clear();
	srand(time(0));
	int cntVertices(0), generated1(0), generated2(0);
	int maxEdges = noVertices * (noVertices - 1) / 2;


	for (it = 1; it <= noVertices; it++)
	{
		for (it2 = 1; it2 <= noVertices; it2++)
		{
			matrix[it][it2] = 0;
		}
	}

	for (it = 1; it <= noVertices - 1; it++)
	{
		int weigth = rand() % MAX_WEIGTH + 1;
		if (((maxEdges * procent) / 100) == cntVertices)
		{
			break;
		}
		matrix[it+1][it] = 1;
		matrix[it][it+1] = 1;
		cntVertices++;
		fout << it << " " << it+1 << " " << weigth << "\n";
	}

	for (it = 1; it <= noVertices; it++)
	{
		for (it2 = 1; it2 <= noVertices; it2++)
		{
			if (matrix[it][it2] == 0 && it != it2)
			{
				matrix[it][it2] = 1;
				matrix[it2][it] = 1;
				int weigth = rand() % MAX_WEIGTH + 1;
				cntVertices++;
				fout << it << " " << it2 << " " << weigth << "\n";
			}
			if (((maxEdges * procent) / 100) == cntVertices)
			{
				break;
			}
		}
	}
	fout.close();
}


/*
while (maxVertices * procent > cntVertices)
	{
		weigth = rand() % MAX_WEIGTH + 1;
		generated1 = rand() % noVertices + 1;
		generated2 = rand() % noVertices + 1;
		if ((generated1 != generated2) && (adjList[generated1]))
		{
			adjList[generated1].push_back(make_pair(generated2, weigth));
			adjList[generated2].push_back(make_pair(generated1, weigth));
			fout << generated1 << " " << generated2 << " " << weigth << "\n";
		}
	}
*/


int main()
{
	generateInput(10, 90);
	fin >> no_vertices >> no_edges;
	for (int i = 1; i <= no_edges; i++)
	{
		fin >> x >> y >> c; /// citim legaturile care se formeaza intre noduri si costul acestora
		///Pentru graf orientat:
		adjacency_list[x].push_back(make_pair(y, c)); /// in lista de adiacenta a nodului de plecare adaugam
														/// o pereche formata din nodul si costul adiacent

		///Daca graful este neorientat adaugam:
		///adjacency_list[y].push_back( make_pair(x, c) );
	}

	for (int i = 1; i <= no_vertices; i++)
	{
		distances[i] = INF; ///initializam distantele fiecarui nod ca fiind infinit
	}

	///Consideram ca 1 este nodul de plecare.
	distances[1] = 0; /// distanta nodului de plecare este 0

	tail.insert(make_pair(0, 1)); /// adaugam in set distanta nodului 1;
	///in set tinem perechi(cost, nod) doar pentru nodurile nealese inca si actualizate macar o data;
	///in paralel tinem distantele minime la noduri si in vectorul distances


	while (!tail.empty()) ///cat timp exista elemente in set
	{
		int vertex = tail.begin()->second; ///din primul element al setului, pastram al doilea
												///camp din pereche (nodul), pentru ca apoi sa
		tail.erase(tail.begin());             ///il stergem

		for (int i = 0; i < adjacency_list[vertex].size(); i++) ///parcurgem lista de adiacenta a nodului curent
		{
			int neighbour = adjacency_list[vertex][i].first; ///nod vecin
			int cost = adjacency_list[vertex][i].second;   ///costul pana la nodul vecin

			if (distances[neighbour] > distances[vertex] + cost)  ///daca distanta nodului vecin e mai mare
			{                            ///decat distanta nodului curent + costul pana la acesta, trebuie sa
										///actualizam valoarea din vectorul distances al vecinului.

				tail.erase(make_pair(distances[neighbour], neighbour)); ///cauta in set daca exista acest nod si il sterge
				distances[neighbour] = distances[vertex] + cost;      ///actualizeaza noua distanta a nodului vecin
				tail.insert(make_pair(distances[neighbour], neighbour));   /// adaugam parechea cu costul actualizat si nod

				///Acest if actualizeaza distantele astfel incat sa aiba cele mai mici valori posibile( cel mai scurt drum
																							///pana la nodul respectiv).
			}
		}
	}

	///Trebuie sa afisam distanta de la nodul de pornire pana la toate nodurile grafului.
	for (int i = 2; i <= no_vertices; i++) ///parcurgem toate nodurile grafului, in afara de cel de pornire (in cazul nostru
	{                                                                                                   /// nodul 1
		if (distances[i] == INF) /// daca nu s-a actualizat niciodata distanta acelui nod ( nu se poate ajunge la acest nod
			cout << "0 ";         ///din nodul de pornire ) , afiseaza distanta 0.
		else
			cout << distances[i] << " ";
	}
}