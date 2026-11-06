#include<stdio.h>

int a[10] = {0,0,0,0,0,0,} ,i,k[10],n,j;

void insert(int key);
void collision(int key,int k);

void insert(int key){
   int k = key % 10;
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

void collision(int key, int k)
{
    printf("\nCollision occurred.");

    int j = 1;

    while(j != 10)
    {
        int k1 = (k + j) % 10;

        if(a[k1] == 0)
        {
            a[k1] = key;
            printf("\nValue is inserted.");
            break;
        }
        else
        {
            j++;
        }
    }

    if(j == 10)
        printf("\nHash Table is full.");
}

void printHashTable(int a[]){
    printf("\nHash Table would be: \n");
    for(i= 0 ; i <11;i++){
    printf("%d = %d \n",i,a[i]);
    }
}

int main(){
    printf("Hash Table size is 10");

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