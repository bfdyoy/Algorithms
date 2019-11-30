#ifndef UTILS_CODE_H
#define UTILS_CODE_H

#include <iostream>
#include <fstream>

using namespace std;

typedef struct _nodeAvl
{
	int key;
	int echi;
	struct _nodeAvl *left, *right;
}NodeAvl;

int max(int a, int b);
int maxPathLength(NodeAvl* p);
void computeBalanceFactor(NodeAvl* p);
NodeAvl* leftRot(NodeAvl* p);
NodeAvl* rightRot(NodeAvl* p);
NodeAvl* doubleLeftRot(NodeAvl* p);
NodeAvl* doubleRightRot(NodeAvl* p);
NodeAvl* balance(NodeAvl* p, int& level);
NodeAvl* insertAvlNode(NodeAvl* p, int val, int& level);
NodeAvl* deleteAvlNode(NodeAvl* p, int val, int& level);
void printAvlTree(NodeAvl* p, int level);
int findNode(NodeAvl* p, int val);

#endif //UTILS_CODE_H