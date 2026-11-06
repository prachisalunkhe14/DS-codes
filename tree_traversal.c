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


// Recursive PreOrder Traversal (Root -> Left -> Right)
void preOrder(struct node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

// Recursive InOrder Traversal (left -> Root -> Right)
void inOrder(struct node *root) {
    if (root == NULL) {
        return;
    }

    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

// Recursive PostOrder Traversal (Left -> Right -> Root)
void postOrder(struct node *root) {
    if (root == NULL) {
        return;
    }

    preOrder(root->left);
    preOrder(root->right);
    printf("%d ", root->data);
    
}


int main(){
    int preO[]={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    struct node *root = buildTree(preO);

    // printf("%d ",root->data);
    // printf("%d ",root->left->data);
    // printf("%d ",root->right->data);

    printf("\nPreOrder Traversal Output:\n");
    preOrder(root);
    printf("\n");

    printf("\nInOrder Traversal Output:\n");
    inOrder(root);
    printf("\n");

    printf("\nPostOrder Traversal Output:\n");
    postOrder(root);
    printf("\n");
}