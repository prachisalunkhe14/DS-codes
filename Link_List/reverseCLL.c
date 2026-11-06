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


// void printCLL(struct node *head){
//     struct node *temp;
//     printf("%d ->",head->data);
//     temp = head->next;
    
//     if (head == NULL ){printf("!!");}
//     else{

//         while(temp != head){
//          printf(" %d ->", temp->data);
//          temp = temp -> next;
//     }
//     }
//      printf("%d",head->data); // temp->data
// }

void printCLL(struct node *head){
    if(head == NULL){
        printf("!!");
        return;
    }
    struct node *temp = head;
    do{
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != head);
    printf("%d", head->data);
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

// void reverseCLL(){
//     struct node *prev=NULL;
//     struct node *curr = head;
//     struct node *next= NULL;

//     if(head == NULL){
//         printf("CLL is empty. ");
//     }
//     if(curr -> next == curr){
//         printf("Only 1 node is there. ");
//     }
//     else{
//         while(curr != tail){
//            next = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = next;
//         }

//    // Reverse the old tail's link
//     curr->next = prev;

//     // Update head and tail
//     tail = head;
//     head = curr;

//     // Make the CLL circular again
//     tail->next = head;
//     }
// }

void reverse()
{
    struct node *current, *prev, *nextnode;

    current = tail->next;
    nextnode = current->next;

    if (tail == 0)
    {
        printf("List is Empty");
    }
    else if (current->next == current)
    {
        printf("Only 1 node");
    }
    else
    {
        while (current != tail)
        {
            prev = current;
            current = nextnode;
            nextnode = current->next;
            current->next = prev;
        }
        nextnode->next = tail;
        tail = nextnode;
    }
}

int main(){
    // InsertAtHead(1);
    // InsertAtHead(2);
    // InsertAtHead(3);
    // printf("After Inserting values at Head. \n");
    // printCLL(head);
    // printf("\n");

    printf("After Inserting values at Tail. \n");
    InsertAtTail(10);
    InsertAtTail(20);
    InsertAtTail(30);
    printCLL(head);
    printf("\n");

    reverse();
    printCLL(head);

}