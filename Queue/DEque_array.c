#include <stdio.h>
#define N 5

int deque[N];
int f = -1, r = -1;

void enqueuefront(int x)
{
    if ((f == 0 && r == N - 1) || (f == r + 1))
    {
        printf("Queue is full\n");
    }
    else if (f == -1 && r == -1) // empty deque
    {
        f = r = 0;
        deque[f] = x;
    }
    else if (f == 0) // wrap around
    {
        f = N - 1;
        deque[f] = x;
    }
    else
    {
        f--;
        deque[f] = x;
    }
}

void enqueuerear(int x)
{
    if ((f == 0 && r == N - 1) || (f == r + 1))
    {
        printf("Queue is full\n");
    }
    else if (f == -1 && r == -1) // empty deque
    {
        f = r = 0;
        deque[r] = x;
    }
    else if (r == N - 1) // wrap around
    {
        r = 0;
        deque[r] = x;
    }
    else
    {
        r++;
        deque[r] = x;
    }
}

void dequeuefront()
{
    if (f == -1 && r == -1)
    {
        printf("Queue is empty\n");
    }
    else if (f == r) // only one element
    {
        printf("Deleted: %d\n", deque[f]);
        f = r = -1;
    }
    else if (f == N - 1) // wrap around
    {
        printf("Deleted: %d\n", deque[f]);
        f = 0;
    }
    else
    {
        printf("Deleted: %d\n", deque[f]);
        f++;
    }
}

void dequeuerear()
{
    if (f == -1 && r == -1)
    {
        printf("Queue is empty\n");
    }
    else if (f == r) // only one element
    {
        printf("Deleted: %d\n", deque[r]);
        f = r = -1;
    }
    else if (r == 0) // wrap around
    {
        printf("Deleted: %d\n", deque[r]);
        r = N - 1;
    }
    else
    {
        printf("Deleted: %d\n", deque[r]);
        r--;
    }
}

void display()
{
    int i;
    if (f == -1 && r == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Deque: ");
    i = f;
    while (i != r)
    {
        printf("%d ", deque[i]);
        i = (i + 1) % N;
    }
    printf("%d\n", deque[r]);
}

int main()
{
    enqueuerear(10);
    enqueuerear(20);
    enqueuefront(5);
    display();
    dequeuefront();
    dequeuerear();
    display();
    return 0;
}