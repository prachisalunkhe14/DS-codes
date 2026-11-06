#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

struct node *createNode(int val){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newnode->data = val;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

void createDLL(int val){
    struct node *newNode = createNode(val);
  
    if(head == NULL){
        head = newNode;
        newNode->prev = NULL;
        newNode->next = NULL;
    }
    else{
         struct node *temp = head;

        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
         newNode->prev = temp;
    newNode->next = NULL;
    }
}

void insertATBeg(int val){ //Time complexity = O(1)
    struct node *newNode = createNode(val);
    if (head == NULL){
        printf("DLL is empty !!");
    }
    else{
         newNode -> next = head;
         head -> prev = newNode;
         head  = newNode;
    }
}

void insertATEnd(int val){ // Time complexity = O(n)
    struct node *newNode = createNode(val);
    struct node *temp;
    if (head == NULL){
        printf("DLL is empty !!");
    }
    temp  = head;
        while (temp->next != NULL){
            temp = temp -> next;
        }
         newNode -> prev = temp; 
         temp -> next = newNode;

}

void insertATMiddle(int val,int pos){ //Time complexity = O(n)
    struct node *newNode = createNode(val);
    struct node *temp;
    struct node *prev;

    temp = head;

    if(head == NULL){
        printf("DLL is empty");
    }
    if(pos == 0){
     insertATBeg(val);
    }
    if(pos <0){ 
        printf("Invalid Position !! ");
    }

    for(int i = 0; i< pos -1; i++){
        prev = temp;
        temp = temp -> next;
    }
    newNode -> next = prev->next;
    prev -> next = newNode;
    temp -> prev = newNode;
}

void deleteAtBeg(){ // Time complexity: O(1)
    if (head == NULL) {
        return; 
    }
    struct node *temp = head;
    
        head = head -> next;
        free(temp);
}

void deleteAtEnd(){ // Time complexity: O(n)
    struct node *temp;
struct node *pre;
temp  = head;
while(temp->next != NULL){
    pre = temp;
    temp = temp -> next;
}
pre -> next = NULL;
free(temp);
}

void deleteAtPos(int pos){
    if (head == NULL){printf("DLL id EMpty !! ");}

    struct node *temp;
    struct node *prev;
    struct node *Tnext;

    temp = head;
    for(int i =0; i<pos-1; i++){
        prev = temp;
        temp = temp->next;
        Tnext = temp -> next;
    }
    prev ->next = temp->next;
    Tnext -> prev = temp->prev;
    free(temp);
}

void printDLL(struct node *head){
    struct node *temp;
        temp = head;
    while(temp != NULL){
        printf(" <- %d -> ", temp->data);
        temp = temp -> next;
        }
    printf("NULL\n");
}

int main(){
    int n , val;
    printf("Enter no. of Nodes: ");
    scanf("%d",&n);

    for (int i =1; i<=n; i++){
        printf("Enter value of node: ");
        scanf("%d",&val);
        createDLL(val);
    }
        printDLL(head);

    insertATBeg(10);
    printf("After inserting at beginning: \n");
    printDLL(head);

    // insertATEnd(20);
    // printf("After inserting at end: \n");
    // printDLL(head);

    // int pos;
    // printf("Enter position to insert: ");
    // scanf("%d",&pos);

    // insertATMiddle(100,pos);
    // printf("After inserting at position %d: \n", pos);
    // printDLL(head);

    // deleteAtBeg();
    // printf("After deleting at beginning: \n");
    // printDLL(head);

    // deleteAtEnd();
    // printf("After deleting at end: \n");
    // printDLL(head);

    // printf("Enter position to delete: ");
    // scanf("%d",&pos);
    // deleteAtPos(pos);
    // printf("After deleting at position %d: \n", pos);
    // printDLL(head);

}