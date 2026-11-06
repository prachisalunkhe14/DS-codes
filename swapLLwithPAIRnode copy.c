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

struct node* swapPairs(struct node* head) {
    if( head == NULL || head ->next == NULL){
        return head;
    }
    struct node *first = head;
    struct node *sec = head -> next;
    struct node *prev = NULL;

    while(first != NULL && sec != NULL){
        struct node *third = sec->next;
        sec->next = first;
        first -> next = third;

        if(prev != NULL){
            prev ->next = sec;
        }
        else{
            head = sec;
        }
    prev = first;
    first = third;
    if(third != NULL){
        sec = third -> next;
    }
    else{
        sec = NULL;
    }
    }
    return head;
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

        struct node * H = swapPairs(head);
         printLL(H);

}