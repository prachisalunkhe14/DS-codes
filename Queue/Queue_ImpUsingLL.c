#include<stdio.h>
#include<stdlib.h>

struct node *head = NULL;
struct node *tail = NULL;

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int val){ //<-- Changed int to struct node*
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void enqueue(int val){ // INSERT AT TAIL  time complexcity is O(1)
     struct node *newnode = createNode(val);
    if(tail == NULL && head == NULL){
        head = tail = newnode;
    }
    else{
        tail ->next = newnode;
        tail = newnode;
    }
}

void dequeue(){ //time complexcity is O(1)
    if(head == NULL && tail == NULL){
        printf("Underflow Condition !!!\n");
    }
    else{
        struct node *temp;
        temp = head;
        printf("Popped data :%d\n",head -> data);
        head = head -> next;
        free (temp);
    }
}

void peek(){ //time complexcity is O(1)
    if(head == NULL && tail == NULL){
        printf("Queue is empty !!\n");
    }
    else{
        printf("Data : %d \n",head -> data);
    }
}

void disQueue(struct node *head){ //time complexcity is O(1)
    struct node *temp;
    if(head == NULL && tail == NULL){
        printf("Queue is empty !!\n");
    }
    else{
        temp = head;
        while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp -> next;
        }
     printf("NULL\n");
    }
}

int main(){
    disQueue(head);
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    disQueue(head);

    peek();

    dequeue();
    disQueue(head);

    peek();

    dequeue();
    disQueue(head);

    peek();

    return 0;
}