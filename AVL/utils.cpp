#include "utils.h"


int max(int a, int b)
{
	return (a > b ? a : b); //operator ternar <=> if
}


int maxPathLength(NodeAvl* node)
{
	if (node == NULL)
	{
		return 0;
	}
	return(max(maxPathLength(node->right), maxPathLength(node->left)) + 1);
}


void computeBalanceFactor(NodeAvl* node)
{
	int maxLeft = 0, maxRight = 0;

	if (node->left != NULL)
	{
		maxLeft = maxPathLength(node->left);
	}
	else
	{
		maxLeft = 0;
	}

	if (node->right != NULL)
	{
		maxRight = maxPathLength(node->right);
	}
	else
	{
		maxRight = 0;
	}

	node->echi = maxRight - maxLeft;

}


NodeAvl* leftRot(NodeAvl* node)
{
	NodeAvl* heavyChild;

	heavyChild = node->right;
	node->right = heavyChild->left;
	heavyChild->left = node;

	computeBalanceFactor(node);
	computeBalanceFactor(heavyChild);

	node = heavyChild;
	return node;
}


NodeAvl* rightRot(NodeAvl* node)
{
	NodeAvl* heavyChild;

	heavyChild = node->left;
	node->left = heavyChild->right;
	heavyChild->right = node;

	computeBalanceFactor(node);
	computeBalanceFactor(heavyChild);

	node = heavyChild;
	return node;
}


NodeAvl* doubleLeftRot(NodeAvl* node)
{
	node->right = rightRot(node->right);
	node = leftRot(node);
	return node;
}


NodeAvl* doubleRightRot(NodeAvl* node)
{
	node->left = leftRot(node->left);
	node = rightRot(node);
	return node;
}


NodeAvl* balance(NodeAvl* node, int& level)
{
	NodeAvl* heavyChild;

	computeBalanceFactor(node);

	if (node->echi == -2)
	{
		cout << "\n!!!" << (level - 2) <<"!!!\n";
		heavyChild = node->left;
		if (heavyChild->echi == 1)
		{
			
			node = doubleRightRot(node);
		}
		else
		{
			
			node = rightRot(node);
		}
	}
	else
	{
		if (node->echi == 2)
		{
			heavyChild = node->right;
			cout << "\n!!!" << (level - 2) << "!!!\n";
			if (heavyChild->echi == -1)
			{
				
				node = doubleLeftRot(node);
			}
			else
			{
				
				node = leftRot(node);
			}
		}
	}
	return node;
}

NodeAvl* insertAvlNode(NodeAvl* node, int value, int& level)
{
	if (node == NULL)
	{
		node = new NodeAvl;
		node->key = value;
		node->echi = 0;
		node->left = NULL;
		node->right = NULL;
		return node;
		level++;
	}
	else
		if (value < node->key)
		{
			node->left = insertAvlNode(node->left, value, level);
			level++;
		}
			
		else if (value > node->key)
		{
			node->right = insertAvlNode(node->right, value, level);
			level++;
		}
		else
			cout <<"The key" << value << "already exists! \n";

	node = balance(node, level);

	return node;
}


NodeAvl* deleteAvlNode(NodeAvl* node, int val, int& level)
{
	if (node == NULL)
	{
		cout << "Can't delete key" << val << "is not in AVL tree!\n";
		return node;
	}

	if (val < node->key)
	{
		level++;
		node->left = deleteAvlNode(node->left, val, level);
	}
	else if (val > node->key)
	{
		level++;
		node->right = deleteAvlNode(node->right, val, level);
	}
	else
	{
		if ((node->left == NULL) || (node->right == NULL))
		{
			NodeAvl* temp;
			if (node->left != NULL)
			{
				temp = node->left;
			}
			else
			{
				temp = node->right;
			}

			if (temp == NULL)
			{
				node = NULL;
			}
			else
			{
				*node = *temp;
				delete temp;
			}
		}
		else
		{
			NodeAvl* temp = node->right;

			while (temp->left != NULL)
			{
				temp = temp->left;
			}
			node->key = temp->key;
			node->right = deleteAvlNode(node->right, temp->key, level);
		}
	}
	if (node != NULL)
	{
		node = balance(node, level);
	}
	return node;
}

void printAvlTree(NodeAvl* node, int level)
{
	if (node != NULL)
	{
		printAvlTree(node->right, level + 7);
		for (int it = 0; it < level; it++)
		{
			cout << " ";
		}
		cout << node->key << "(" << node->echi << ")\n";
		printAvlTree(node->left, level + 7);
	}
}

int findNode(NodeAvl* p, int val)
{
	NodeAvl* current = p;
	int nivel = 0;
	while (current != NULL)
	{
		if (current->key == val)
		{
			break;
		}
		else if (val > current->key)
		{
			current = current->right;
		}
		else
		{
			current = current->left;
		}
		nivel++;
	}
	return nivel;
}