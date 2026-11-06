#include<stdio.h>
#include<stdlib.h>

struct node *head = NULL;
//struct node *tail = NULL;


struct node{
    int data;
    struct node *next;
};

struct node* createNode(int val){ //<-- Changed int to struct node*
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void CreateLL( int val){
    struct node *newNode = createNode(val);
  
    if(head == NULL){
        head = newNode;
    }
    else{
         struct node *temp = head;

        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printLL(struct node *head){
    struct node *temp;
    temp = head;
    while(temp != NULL){
    printf("%d ->", temp->data);
    temp = temp -> next;
    }
     printf("NULL\n");
}

void insertATBeg(int val){ // Time complexity: O(1)
    struct node *newNode = createNode(val);
    if( head == NULL){
        printf("List is Empty. ");
    }
    else{
    newNode->next = head;
    head = newNode;}
}

void insertATEnd(int val){ // Time complexity: O(n)
    struct node *newNode =  createNode(val);
    struct node *temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
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
while(temp != NULL){
    pre = temp;
    temp = temp -> next;
}
pre -> next = NULL;
free(temp);
}

void insertAtPos(int val, int pos){ // Time complexity: O(n)
    struct node *temp;
    struct node *newNode = createNode(val);
    temp = head;

    //case 1: if pos is 0, insert at beginning
    if(pos == 0){
        insertATBeg(val);
    }

    // case 2: if pos is greater than length of linked list, insert at end
    if(pos <0){
        return;
    }

    // case 3: if pos is greater than length of linked list, insert at end
     for(int i =0;i<pos-1;i++){
        temp = temp -> next;
     }
     newNode -> next = temp -> next;
     temp -> next = newNode;
}

void deleteAtPos(int pos){ // Time complexity: O(n)
    struct node *temp, *pre;

    temp = pre = head;

    if(pos == 0){
        deleteAtBeg();
    }
    else if(pos < 0){
        return;
    }
    else{
        for(int i =0; i<pos; i++){
            pre = temp;
            temp = temp -> next;
        }
        pre -> next = temp -> next;
        free(temp);
    }
}

void search(int val){ // Time complexity: O(n)
    struct node *temp = head;
    int pos = 0;

    while(temp != NULL){
        if(temp -> data == val){
            printf("Value %d found at position %d\n", val, pos);
            return;
        }
        temp = temp ->next;
        pos ++;
        
    }
    printf("Value %d not found in the list\n", val);
}

int main(){
    int n , val;
    printf("Enter no. of Nodes: ");
    scanf("%d",&n);

    for (int i =1; i<=n; i++){
        printf("Enter value of node: ");
        scanf("%d",&val);
        CreateLL(val);
    }
        printLL(head);

    // int n1;
    // printf("Enter value to search: ");
    // scanf("%d",&n1);
    // search(n1);



    // int pos;
    // printf("Enter position to insert: ");
    // scanf("%d",&pos);

    // insertAtPos(100,pos);
    // printf("After inserting at position %d: \n", pos);
    // printLL(head);

    // printf("Enter position to delete: ");
    // scanf("%d",&pos);
    // deleteAtPos(pos);
    // printf("After deleting at position %d: \n", pos);
    // printLL(head);

    insertATBeg(10);
    printf("After inserting at beginning: \n");
    printLL(head);

    // insertATEnd(20);
    // printf("After inserting at end: \n");
    // printLL(head);

    // deleteAtBeg();
    // printf("After deleting at beginning: \n");
    // printLL(head);

    // deleteAtEnd();
    // printf("After deleting at end: \n");
    // printLL(head);
   
}