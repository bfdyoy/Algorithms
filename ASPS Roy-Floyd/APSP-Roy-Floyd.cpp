// APSP-Roy-Floyd.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "royFloyd.h"

int main()

{
	char ch;
	int x, y, n, m;
	int cost[100][100];

	initial_cost(cost, n, m);

	printf_s("\n The weight matrix is:\n");
	display_matrix(cost, n);
	Roy_Floyd(cost, n);

	printf_s("\n The minimum cost matrix is:\n");
	display_matrix(cost, n);

	do
	{
		printf_s("\n\nDetermine which is the minimum cost path between two nodes of the graph\n");
		printf_s("x= ");
		scanf_s("%d", &x);

		printf_s("y= ");
		scanf_s("%d", &y);
		print_path(x, y, cost, n);

		printf_s("\n\n\n Do you want to find a path between other nodes from the graph? <y/n>");
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	
	//getchar();
	return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
