#include <stdio.h>

// Find the largest number
int getMax(int arr[], int n)
{
    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}

// Counting Sort according to each digit
void countingSort(int arr[], int n, int place)
{
    int output[n];
    int count[10] = {0};

    // Count occurrences of each digit
    for (int i = 0; i < n; i++)
    {
        int digit = (arr[i] / place) % 10;
        count[digit]++;
    }

    // Calculate positions
    for (int i = 1; i < 10; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    // Build output array
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / place) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy output back to original array
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

// Radix Sort
void radixSort(int arr[], int n)
{
    int max = getMax(arr, n);

    // Sort according to each digit
    for (int place = 1; max / place > 0; place *= 10)
    {
        countingSort(arr, n, place);
    }
}

// Display array
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    // int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    // int n = sizeof(arr) / sizeof(arr[0]);
    int arr[100], n, i;
    printf("Enter the Number of Elements:");
    scanf("%d",&n);

    printf("Enter the ELements: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }



    printf("Before sorting: ");
    display(arr, n);

    radixSort(arr, n);

    printf("\nAfter sorting: ");
    display(arr, n);

    return 0;
}