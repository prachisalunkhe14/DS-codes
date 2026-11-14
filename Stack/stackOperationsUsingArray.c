#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int stack[MAX]; int top = -1;

void push(int val){
   
    if(top == MAX-1){
        printf("\nStack is FULL (Overflow) !!");
    }
    else{
        top ++;
        stack[top] = val;
    }
}

void pop(){
    int value;
    if(top == -1){
        printf("\nUnderflow!!!");
    }
    else{
        value = stack[top];
        top--;
        printf("\nPopped Element is: %d. ",value);
    }
}

void popPer(int val){
 if(top == -1){
        printf("\nUnderflow!!!");
    }
    else{
        int value,i;
        for( i=0;i<MAX;i++){
            if(stack[top] == val){
                value = stack[i];
                top--;
                printf("\nPopped Element is: %d. ",value);
            }
        }
    }
}

void peek(){
    if(top == -1){
        printf("\nStack Empty !!! ");
    }
    else{
        printf("\n%d",stack[top]);
    }
}

void display(){
   if(top == -1){
        printf("\nStack Empty !!! ");
    }
    else{
        int i;
        for (i=top;i>=0;i--){
            printf("\n%d ",stack[top]);
            top --;
        }
    }
}

int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    display();

    // pop();
    // pop();

    // display();

    // push(65);
    // push(98);

    // display();

    // popPer(20);

    // display();
    return 0;

}