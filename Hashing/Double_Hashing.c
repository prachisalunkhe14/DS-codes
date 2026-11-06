#include<stdio.h>

int a[10] = {0,0,0,0,0,0,} ,i,k[10],n,j;

void insert(int key);
void collision(int key,int k);

void insert(int key){
   int k = key % 11;
    if(a[k] == 0){
         printf("\nIndex is empty");
         a[k]=key;
         printf("\nValue is inserted. ");
    }
    else{
        //insert(key);
        
        collision(key,k);
    }
}

void collision(int key, int k){
    printf("\nCollision occurred.");
    int j = 1;
    int k1 = 8 - (key % 8);
    while(j != 11){
        int k2 = (k + j*k1) % 11;
        if(a[k2] == 0)  {
            a[k2] = key;
            printf("\nValue is inserted.");
            break;
        }
        else {
            j++;
        }
    }
    if(j == 11)
        printf("\nHash Table is full.");
   

}

void printHashTable(int a[]){
    printf("\nHash Table would be: \n");
    for(i= 0 ; i <11;i++){
    printf("%d = %d \n",i,a[i]);
    }
}

int main(){
    printf("Hash Table size is 11");

    printf("\nHow many keys you want to insert? :- ");
    scanf("%d",&n);
    
    printf("\nEnter KEYS to be inset: \n");
    for(i=0;i<n;i++){
        scanf("%d",&k[i]);
    }

    for(i=0;i<n;i++){
        insert(k[i]);
    }

    printHashTable(a);
}