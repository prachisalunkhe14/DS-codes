#include<stdio.h>
#include<stdlib.h>

struct node *head = NULL;
struct node *tail = NULL;

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

void InsertAtHead( int val){
    struct node *newNode = createNode(val);
  
    if(head == NULL){ // if(tail == NULL)
        head = tail = newNode;
        tail -> next = head; // tail -> next = newNode;
    }
    else{
         struct node *temp = head;
        newNode ->next = head;
        head = newNode;
        tail->next = head; // tail->next = newNode;
    }
}

void InsertAtTail(int val){
    struct node *newNode = createNode(val);
  
    if(head == NULL){ // if(tail == NULL)
        head = tail = newNode;
        tail -> next = head; // tail -> next = newNode;
    }
    else{
         struct node *temp = head;
        newNode ->next = head;
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAtPos(struct node *head, int pos, int val){
    struct node *newNode = createNode(val);

    if(head == NULL/* tail == NULL*/){
        head = tail = newNode;
    }
    
    if(pos <0){
        printf("Invalide Pos ");
    }

    if(pos == 1){
        InsertAtHead(val);
    }
    else{
        struct node *temp = head;
        struct node *NEXTNODE = NULL;

        for(int i =0; i< pos-1; i++){
            NEXTNODE = temp;
            temp = temp -> next;
        }
        newNode -> next = NEXTNODE -> next;
        NEXTNODE -> next = newNode;
    }
}

void deletAtHead(){

    if(head == NULL){
        printf("Empty LL !!"); return;
    }
    if (head == tail){
        free(head);
        head = tail = NULL; return;
    }
    struct node * temp = head;
    head = head -> next;
    tail -> next = head;
    temp -> next = NULL;
    free(temp);
    
}
void deletAtTail(){

    if(head == NULL){
        printf("Empty LL !!"); return;
    }
    if (head == tail){
        free(head);
        head = tail = NULL; 
    }
    struct node * temp = tail;
    struct node * prev = head;
    while(prev->next != tail){
        prev = prev -> next;
    }
    tail = prev;
    tail -> next = head;

    temp -> next = NULL;
    free(temp);
    
}

void  deleteAtPos(struct node *head/* "*tail" */, int pos) {
    if(head == NULL){
        printf("Empty LL !!! ");
    }

    struct node *temp = head; // temp = tail->next;
    struct node *NEXTNODE = NULL;

    if(pos <0){
        printf("Envalid Position ");
    }
    if (pos == 1){
        deletAtHead();
    }
    else{
        for(int i =0 ; i< pos -1 ; i++){
            NEXTNODE = temp;
            temp = temp->next;
        }
        NEXTNODE ->next = temp -> next;
        temp -> next = NULL;
        free(temp);
    }
}

void printCLL(struct node *head){
    struct node *temp;
    printf("%d ->",head->data);
    temp = head->next;
    
    if (head == NULL ){printf("!!");}
    else{

        while(temp != head){
         printf(" %d ->", temp->data);
         temp = temp -> next;
    }
    }
     printf("%d",head->data); // temp->data
}

int main(){
    // int n , val;
    // printf("Enter no. of Nodes: ");
    // scanf("%d",&n);

    // for (int i =1; i<=n; i++){
    //     printf("Enter value of node: ");
    //     scanf("%d",&val);
        
    // }
    int pos;

    InsertAtHead(1);
    InsertAtHead(2);
    InsertAtHead(3);
    printf("After Inserting values at Head. \n");
    printCLL(head);
    printf("\n");

    printf("After Inserting values at Tail. \n");
    InsertAtTail(10);
    InsertAtTail(20);
    InsertAtTail(30);
    printCLL(head);
    printf("\n");

    printf("Enter position to insert: ");
    scanf("%d",&pos);

    insertAtPos(head,pos,100);
    printf("After inserting at position %d: \n", pos);
    printCLL(head);

    // deletAtHead();
    //     printf("After deleting values at Head. \n");
    //     printCLL(head);
    //  printf("\n");

    // deletAtTail();
    //     printf("After deleting values at Tail. \n");
    //     printCLL(head);
    //  printf("\n");
    
    // printf("Enter position to delete: ");
    // scanf("%d",&pos);
    // deleteAtPos(head,pos);
    // printf("After deleting at position %d: \n", pos);
    // printCLL(head);

}