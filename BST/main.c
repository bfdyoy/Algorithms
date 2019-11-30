#include "trees.h"


int main()

{
    Node *root=NULL, *maxim = NULL, *minim = NULL;
    Node *altNode = NULL, *altNode2 = NULL;
    bool isFound;
    int i,n,x;
    do
    {
        printf("\n1.Adauga un nod");
        printf("\n2.Sterge un nod");
        printf("\n3.Preorder");
        printf("\n4.Inorder");
        printf("\n5.Postorder");
        printf("\n6.Arborescenta");
        printf("\n7.Verifica daca un nod apartine");
        printf("\n8.Valoarea maxima");
        printf("\n9.Valoarea minima");
        printf("\n10.Inorder successor:");
        printf("\n11.Inorder predecessor:");
        printf("\n\nOptiunea dumneavoastra:");
        scanf("%d",&i);
        switch(i)
        {
        case 1:
            scanf("%d",&n);
            root= Add_Node(root,n);
            break;
        case 2:
            printf("\nAlegeti nodul pe care doriti sa-l stergeti");
            scanf("%d",&x);
            root=Delete(root,x);
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            inorder(root);
            break;
        case 5:
            postorder(root);
            break;
        case 6:
            Display(root, 0);
            break;
        case 7:
            printf("\nIntroduceti nodul pe care doriti sa-l cautati:");
            scanf("%d", &x);
            isFound = findNode(root, x);
            if(isFound == true)
                printf("\nNodul exista in arbore !");
            else
                printf("\nNodul nu exista in arbore!");
            break;
        case 8:
            maxim = findMax(root);
            printf("\n%d\n", maxim->data);
            break;
        case 9:
            minim = FindMin(root);
            printf("\n%d\n", minim->data);
            break;
        case 10:
            printf("\nIntroduceti nodul pentru care sa se caute succesorul:");
            scanf("%d", &x);
            altNode = getNodeByData(root, x);
            altNode2 = inordSuccessor(root, altNode);
            printf("\n%d\n", altNode2->data);
            break;
        case 11:
            printf("\nIntroduceti nodul pentru care sa se caute predecesorul:");
            scanf("%d", &x);
            altNode = getNodeByData(root, x);
            altNode2 = inordPredecessor(root, altNode);
            printf("\n%d\n", altNode2->data);
            break;
        }
    }
    while(i);
    return 0;
}
