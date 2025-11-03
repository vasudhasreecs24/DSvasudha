#include<stdio.h>
#define N 5
int queue[N];
int front=-1;
int rear=-1;
void enqueue(int x)
{
    if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=x;
    }
    else if((rear+1)%N==front)
    {
        printf("Queue is full\n");
    }
    else{
        rear=(rear+1)%N;
        queue[rear]=x;
    }
}
void dequeue()
{

    if(front==-1 && rear==-1)
    {
        printf("Queue is empty\n");

    }
    else if(front==rear)
    {

        printf("Deleted element is :%d\n",queue[front]);

    }
    else
    {
        printf("Deleted element is:%d\n",queue[front]);
        front=(front+1)%N;
    }
}
void display()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty\n");
    }
    else{
            int i;
        printf("Queue elements are:\n");
        for ( i=front;i!=rear;i=(i+1)%N)
        {
            printf("%d  ",queue[i]);
        }
        printf(" %d",queue[i]);
    }
}
void peek()
{
    if(front==-1 &&rear==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Front elements are :%d\n",queue[front]);
    }
}
int main()
{
    int choice,x;
    while(1)
    {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.peek\n");
        printf("Enter your choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter element to insert: ");
                   scanf("%d",&x);
                   enqueue(x);
                   break;
            case 2: dequeue();break;
            case 3:display();break;
            case 4:peek();break;
            case 5:printf("Existing....\n");exit(0);break;
            default:printf("INvalid choice");
        }
    }
    return 0;
}

