#include "utils.h"

int main()
{
	int key, i, level(0);
	char option;

	NodeAvl* root = NULL;

	ifstream myFile;
	myFile.open("input.txt");

	if (!myFile)
	{
		perror("Unable to open the file");
		return 0;
	}

	do
	{
		cout << "\n1.Adauga un nod.";
		cout << "\n2.Sterge un nod.";
		cout << "\n3.Arborescenta.";
		cout << "\n4.Incarcarea din fisierul prestabilit.\n";
		cin >> i;
	
		switch (i)
		{
		case 1:
			level = 0;
			cin >> key;
			root = insertAvlNode(root, key, level);
			break;
		case 2:
			level = 0;
			cin >> key;
			root = deleteAvlNode(root, key, level);
			break;
		case 3:
			printAvlTree(root, 0);
			break;
		case 4:
			while (!myFile.eof())
			{
				myFile.get(option);
				if (option == 'I')
				{
					level = 0;
					myFile >> key;
					root = insertAvlNode(root, key, level);
				}
				else if (option == 'D')
				{
					level = 0;
					myFile >> key;
					root = deleteAvlNode(root, key, level);
				}
			}
			myFile.close();
			break;
		}	
	} while (i);
	
	return 0;
}
