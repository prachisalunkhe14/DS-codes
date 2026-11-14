    #include<stdio.h>
    #include<stdlib.h>

    struct node *front = NULL;
    struct node *rear = NULL;

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

    void enqueue(int val){
        struct node* newnode = createNode(val);
        if(front == NULL && rear == NULL){
            rear = front = newnode;
            rear->next = front;
        }
        else{
            rear->next = newnode;
            rear = newnode;
            newnode ->next = front;
        }
    }

    void dequeue(){
        struct node *temp;
        temp = front;
        if(rear== NULL && front == NULL){
            printf("UnderFlow !!\n");
        }
        else if(front == rear){
            front = rear = NULL;
            free(temp);
        }
        else{
            front = front -> next;
            free(temp);
            rear -> next = front;
        }
    }

    void peek(){
        if(rear== NULL && front == NULL){
            printf("Queue is Empty !!\n");
            return;
        }
        else{
            printf("Data : %d\n",front -> data);
        }
    }

    void disCQ(){
        struct node *temp = front;
        if(rear== NULL && front == NULL){
            printf("Queue is Empty !!\n");
        }
    else{
        printf("Queue is: ");
        while(temp != rear){
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("%d ",rear-> data);
    }
    }

    int main(){
        disCQ();

        enqueue(1);
        enqueue(5);
        disCQ();

        peek();

        dequeue();
        disCQ();
        peek();

        enqueue(50);
        enqueue(60);

        disCQ();
    }