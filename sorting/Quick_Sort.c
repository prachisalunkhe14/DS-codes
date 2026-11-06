#include<stdio.h>

int quick_sort(int[] , int, int );

int main(){
    int i,n,a[100];

    printf("Give array size: ");
    scanf("%d",&n);

    printf("Enter array elements: \n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    quick_sort(a,0,n-1);

    printf("After Sorting: \n");
    for(i=0;i<n;i++){   
        printf("%d ",a[i]);
    }
    return 0;
}

int partitioning(int a[], int st, int end){

    int i,j,temp,pivot;

        pivot = st;
        i = st;
        j = end;

        while (i <= j){
           while (i <= end && a[i] <= a[pivot])
    i++;
while (j >= st && a[j] > a[pivot])
    j--;
            if ( j > i ){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        
        }
        temp = a[j];
        a[j] =  a[pivot];
        a[pivot] = temp;
    return j;
}

int quick_sort(int a[], int st, int end){
    
    if(st < end){
        int loc = partitioning(a,st,end);
        quick_sort(a,st,loc-1);  
        quick_sort (a,loc+1,end);
    }
    return 0;
}
