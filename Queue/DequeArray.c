#include<stdio.h>
#include<stdlib.h>
#define N 5
int deque[N];
int f=-1, r=-1;

void enqueuefront(int val){
    if((f == 0 && r == N-1)|| (f == r+1)){
        printf("Queue is Full\n");
    }
    else if(f == -1 && r == -1){
        f = r = 0;
        deque[f] = val;
    }
    else if(f == 0){
        f = N-1;
        deque[f] = val;
    }
    else{
        f --;
        deque[f] = val;
    }
}

void enqueuerear(int val){
    if((f == 0 && r == N-1)|| (f == r+1)){
         printf("Queue is Full\n");
    }
    else if(f == -1 && r == -1){
        f = r = 0;
        deque[r] = val;
    }
    else if(r == N-1){
        r =0; 
        deque[r] = val;
    }
    else{
        r ++; 
        deque[r] = val;
    }
}

void display(){
    int i = f;
    while(i != r){
        printf("%d ",deque[i]);
        i = (i+1)% N;
    }
    printf("%d \n", deque[r]);
}

void getfront(){
    if(f == -1 && r == -1){
        printf("Queue is Empty. \n");
    }
    else {
        printf("%d \n", deque[r]);
    }
}

void getrear(){
     if(f == -1 && r == -1){
        printf("Queue is Empty. \n");
    }
    else{
        printf("%d \n",deque[r]);
    }
}

void dequefront(){
    if(f == -1 && r == -1){
        printf("Queue is Empty. \n");
    }
    else if( f== r){
        f = r = -1;
    }
    else if(f == N-1){
        printf("deleted element from front: %d \n",deque[f]);
        f = 0;
    }
    else{
        printf("deleted element from front: %d \n",deque[f]);
        f++;
    }
}

void dequerear(){
    if(f == -1 && r == -1){
        printf("Queue is Empty. \n");
    }
    else if( f == r){
        f = r= -1;
    }
    else if( r == 0){
        printf("deleted element from rear: %d \n",deque[r]);
        r = N-1;
    }
    else{
        printf("deleted element from rear: %d \n",deque[r]);
        r--;
    }
}

int main(){
    enqueuefront(10);
    enqueuerear(-1);
    enqueuefront(3);
    enqueuerear(5);
    dequefront();
    getrear();

    display();
    enqueuefront(6);
    dequerear();
    getrear();

    enqueuefront(7);
    getfront();

    display();
    dequerear();

    enqueuefront(70);
    dequefront();
    getfront();
    display();

    getrear();
    enqueuerear(50);
}