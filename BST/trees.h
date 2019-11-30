#ifndef TREES_H_INCLUDED
#define TREES_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct _Node
{
    int data;
    struct _Node *left;
    struct _Node *right;
}
Node;

void Display(Node* root, int nivel);
Node *Add_Node(Node *root,int data);
void preorder (Node *root);
void inorder(Node *root);
void postorder(Node *root);
Node* FindMin(Node *root);
Node* Delete( Node *root, int data);
bool findNode(Node *root, int searchedData);
Node *findMax(Node *root);
Node *inordSuccessor(Node *root, Node *aNode);
Node *inordPredecessor (Node *root, Node *aNode);
Node *getNodeByData (Node *root, int data);

#endif // TREES_H_INCLUDED
