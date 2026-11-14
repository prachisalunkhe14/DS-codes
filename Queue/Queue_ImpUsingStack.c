#include<stdio.h>
#include<stdlib.h>
#define N 5
int s1[N], s2[N];
int top1 = -1, top2 = -1;
int count = 0;

int pop1(){
    return s1[top1--];
}

int pop2(){
    return s2[top2--];
}

void push2(int data){
    if(top2 == N-1){
        printf("Full !!\n");
    }
    else{
        top2++;
        s2[top2]=data;
    }
}

void push1(int val){
    if(top1 == N-1){
        printf("Overflow!! \n");
    }
    else{
            top1 ++;
            s1[top1] = val;
    }
}

void enqueue(int val){ // stack 1
    push1(val);
    count++;
}

void dequeue(){
    int i,a,b;
    if(top1 == -1 && top2 == -1){
        printf("Queue is empty. \n");
    }
    else{
        for(i=0;i<count;i++ ){
            a = pop1();
            push2(a);
        }
        b = pop2();
        printf("Deleted element %d \n",b);
        count --;
        for(i=0; i< count; i++){
            a = pop2();
            push1(a);
        }
    }
}

void display(){
    int i;
     if(top1 == -1 && top2 == -1){
        printf("Queue is empty. \n");
    }
    else{
        for(i =0 ; i<= top1; i++){
        printf("%d ",s1[i]);
    }
    printf("\n");
}
}

void main(){
    display();
    enqueue(5);
    enqueue(2);
    enqueue(-1);
    enqueue(3);

    display();

    dequeue();
    display();

    enqueue(8);
    enqueue(9);
    enqueue(-2);// overlflow

    display();

    dequeue();
    display();

}