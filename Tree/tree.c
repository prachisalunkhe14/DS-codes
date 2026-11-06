#include<stdio.h>
#include<stdlib.h>

//time complexicity for building a tree is O(n)
// bcoz it visiting each evry data/element in the given list

struct node{
    int data;
    struct node *left;
    struct node *right;
};
static int idx = -1;

struct node * createNode(int val){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node *buildTree (int preOrder[])
{
    idx++;
    if(preOrder[idx] == -1){
        return 0;
    }
    struct node *root = createNode(preOrder[idx]);
    root-> left = buildTree(preOrder);
    root->right = buildTree(preOrder);

    return root;
}

/*tree traversal: in which 4 types are there
1. PreOrder(recursive)
2. InOrder(recursive)
3. PostOrder (recursive)
4.Level Order (iterative )
*/


int main(){
    int preOrder[]={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    struct node *root = buildTree(preOrder);

    printf("%d ",root->data);
    printf("%d ",root->left->data);
    printf("%d ",root->right->data);
}