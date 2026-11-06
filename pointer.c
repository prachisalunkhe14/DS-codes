#include<stdio.h>

int main(){
    int a = 10;
    int *ptr = &a;
    
    printf("%d\n", ptr);
    printf("%d\n", *ptr);

    ptr++; // Incrementing the pointer to point to the next integer location
    // printf("%d\n", *ptr);

    ptr = ptr + 2; // Incrementing the pointer to point to the next integer location
    printf("%d\n", ptr);
    return 0;

}