#include<stdio.h>

int main(){
    int i,j,n,a[100],temp;

    printf("Enter size of array: ");
    scanf("%d",&n);

    printf("Enter elements: \n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    for(i = 1; i < n; i++){
        temp = a[i];
        for( j= i-1 ; j >= 0; j--){
            if(a[j] > temp){
                a [j+1] = a[j];
            }
            else{
                
                break;
            }
        }
        a[j+1] = temp;
    } 

    // for(i = 1; i < n; i++){
    //     temp = a[i];
    //     j = i - 1;
    //     while(j >= 0 && a[j] > temp){
    //         a[j + 1] = a[j];
    //         j--;
    //     }
    //     a[j + 1] = temp;
    // }

    printf("\nAfter Sorting : \n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}