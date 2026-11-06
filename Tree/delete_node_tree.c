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

// Function to build a BST from an array
struct node* buildBST(int arr[], int n) { 
    struct node* root = NULL;

    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
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

struct node* getInorderSuccessor(struct node * root){//left most node  in right subtree
while(root != NULL && root->left){
    root = root->left;
}
return root;
}

struct node * delNode(int key, struct node *root){ //key == val to delete
    struct node* temp;
    if(root == NULL){
        return NULL;
    }

    if(key < root-> data){
        root -> left = delNode(key,root->left);
    }
    else if(key > root-> data){
        root->right = delNode(key,root->right);
    }
    else{
        //key == root;
        //chile == 0 or 1
        if(root->left == NULL){
            temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            temp = root->left;
            free(root);
            return temp;
        }
        else{ // 2 child
            struct node *IS = getInorderSuccessor(root->right);
            root->data = IS->data;
            root -> right = delNode(IS->data, root->right);

        }

    }
    return root;
}

int main(){
    int arr[]={8,10,11,2,5,1,15};
    int n = 7;
    struct node *root = buildBST(arr,n);

    printf("before Deleting: \n");
    inOrder(root);
    printf("\n");


    int key;
    printf("enter number to be delete: ");
    scanf("%d",&key);

    delNode(key,root);

    printf("After Deleting: \n");
    inOrder(root);
    printf("\n");


     
    // bool T = search(root,key);

    // if(T == false)
    //     printf("Number is not found!!");
    // else
    // printf("Number is found!!");




    // printf("%d ",root->data);
    // printf("%d ",root->left->data);
    // printf("%d ",root->right->data);
}
