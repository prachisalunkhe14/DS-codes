
#include <stdio.h>

int fibSearch(int a[], int n, int key)
{
    int fib2 = 0;
    int fib1 = 1;
    int fib = fib1 + fib2; // intiallt fib = 1.
    int offset = -1;       // Why is offset = -1? Because the search has not moved to any array position yet.

    while (fib < n)
    { // Find the smallest Fibonacci number greater than or equal to n
        /*For example, if n = 5, the Fibonacci numbers are:
        1 → 2 → 3 → 5
        When fib = 5, the condition fib < n becomes false, and the loop stops.
        Why do we need this? Fibonacci Search uses these numbers to decide the positions at which to search.*/
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    while (fib > 1)
    {
        int i = offset + fib2;

        if (i < n && a[i] < key)
        {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        else if (i < n && a[i] > key)
        {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        else if (i < n && a[i] == key)
        {
            return i;
        }
    }

    if (fib1 && offset + 1 < n &&
        a[offset + 1] == key)
        return offset + 1;

    return -1;
}

int main()
{
    int a[100], n, key, i, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter sorted elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    result = fibSearch(a, n, key);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}