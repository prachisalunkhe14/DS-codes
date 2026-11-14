#include<stdio.h>
#include<stdlib.h>
#define N 3

int queue[N];
int cap = N;
int f= -1, r = -1;
int currSize = 0;

void enqueue(int data){ //time complexicity O(1)
    if(r== -1 && f == -1){
        f++; r++;
        queue[r] = data;
        currSize++;
    }
    else if(currSize == cap){
        printf("OverFlow !!\n");
    }
    else{
        r = (r+1)% cap;
        queue[r] = data;
        currSize++;
    }
}

void dequeue(){ //time complexicity O(1)
    if(r== -1 && f == 0){
        printf("UnderFlow !!\n");
    }
    else if(f == r){
        printf("%d deleted.\n",queue[f]);//only one element is there
        f = r = -1;
        currSize --;
    }else{
        f = (f+1)%cap;
        currSize --;
    }
}

void front(){ //time complexicity O(1)
     if(r== -1 && f == 0){
        printf("UnderFlow !!\n");
    }
    else{
        printf("Data : %d\n",queue[f]);
    }
}

void displayCQ(){
   int i =f;
   if(f == -1 && r == -1){
    printf("Queue is Empty !!\n");
   }
   
    printf("Queue is: ");
    while(1){
        printf("%d ", queue[i]);
        if(i == r){
            break;
        }
        i = (i+1) % cap;
    }
   printf("\n");
}

int main(){
    displayCQ();

    enqueue(1);
    enqueue(5);
    displayCQ();

    front();

    dequeue();
    displayCQ();
    front();

    enqueue(50);
    enqueue(60);

    displayCQ();
}
