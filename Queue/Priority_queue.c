#include <stdio.h>
#define N 5

int pq[N];
int f = -1, r = -1;

void enqueue(int x)
{
    int pos;
    if (r == N - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        pos = r;
        r++;
        while (pos >= 0 && pq[pos] >= x)
        {
            pq[pos + 1] = pq[pos]; // shift right
            pos--;
        }
        pq[pos + 1] = x;
        if (f == -1)
            f = 0;
    }
}

void dequeue()
{
    if (f == -1)
    {
        printf("Queue is empty\n");
    }
    else if (f == r) // last element
    {
        printf("Deleted: %d\n", pq[f]);
        f = r = -1;
    }
    else
    {
        printf("Deleted: %d\n", pq[f]);
        f++;
    }
}

void display()
{
    int i;
    if (f == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (i = f; i <= r; i++)
        printf("%d ", pq[i]);
    printf("\n");
}

int main()
{
    enqueue(6);
    enqueue(2);
    enqueue(4);
    display();
    dequeue();
    display();
    return 0;
}