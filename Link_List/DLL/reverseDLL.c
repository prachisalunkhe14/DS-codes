#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;
struct node *prev;
        struct node *curr;
         struct node *NextNode;

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
void printDLL(struct node *head){
    struct node *temp;
        temp = head;
    while(temp != NULL){
        printf(" <- %d -> ", temp->data);
        temp = temp -> next;
        }
    printf("NULL\n");
}


void reversDLL(struct node *head){
    
    prev = NULL;
    curr =  head;
    NextNode = NULL;

    while( curr != NULL){
        NextNode = curr -> next;
        curr-> next = prev;
        curr ->prev = NextNode;
        prev = curr;
        curr = NextNode;
    }
    head = prev;
    //return head;
    printDLL(head);
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

   reversDLL(head);

}