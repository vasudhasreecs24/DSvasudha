#include <stdio.h>
#include <stdlib.h>

#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enque(int x)
{
    if (rear == N - 1)
    {
        printf("Queue Overflow\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
        printf("inserted element=%d",x);
    }
    else
    {
        rear++;
        queue[rear] = x;
        printf("inserted element=%d",x);
    }
}

void deque()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else if (front == rear)
    {
        printf("Deleted element = %d\n", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("Deleted element = %d\n", queue[front]);
        front++;
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void peek()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Front element = %d\n", queue[front]);
    }
}

int main()
{
    int ch, x;
    while (1)
    {
        printf("\nEnter your choice:1. Enqueue 2. Dequeue 3. Display 4. Peek 5. Exit ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter element to insert: ");
            scanf("%d", &x);
            enque(x);
            break;
        case 2:
            deque();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            exit(0);
        default:
            printf("Choice out of range\n");
        }
    }
    return 0;
}
