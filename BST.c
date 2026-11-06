#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

// Function to build a BST from an array
struct node* buildBST(int arr[], int n) {
    struct node* root = NULL;

    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    return root;
}

struct node* insert(struct node *root, int val){

    if (root == NULL){
        return createNode(val);
    }

    if(val < root->data){
        root -> left=insert(root->left,val);
    } else{
        root -> right = insert( root->right ,val);
    }
   return root;
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

//search an element in BST
bool search(struct node *root, int key){
   if(root == NULL)
   return false;

   if(root->data == key)
   return true;

   if (root->data > key)
        search (root->left,key);
    else
        search(root->right,key);
}

int main(){
    int arr[]={8,10,11,2,5,1,15};
    int n = 7;
    struct node *root = buildBST(arr,n);

    inOrder(root);
    printf("\n");

    int key;
    printf("Enter number to be insert: \n");
    scanf("%d",&key);

    insert(root,key);

    printf("After inserting a value:\n");
    inOrder(root);
    printf("\n");

    // int key;
    // printf("enter number to be search: ");
    // scanf("%d",&key);
     
    // bool T = search(root,key);

    // if(T == false)
    //     printf("Number is not found!!");
    // else
    // printf("Number is found!!");


    // printf("%d ",root->data);
    // printf("%d ",root->left->data);
    // printf("%d ",root->right->data);
}
