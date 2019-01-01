#include<stdio.h>
#include<stdlib.h>
typedef struct
{   int key;    }element;
element* queue;
int front=0, rear=0, capacity=2;
void copy(element* s, element* e, element* nq)
{
    int i=0;
    while(s<e)
    {
        *(nq+i)=*s;
        i++;
        s++;
    }
}
void queuefull()
{
    element* nq=(element*)malloc(2*capacity*sizeof(element));
    int start=(front+1)%capacity;
    if(start<2)
        copy(queue+start,queue+capacity,nq);
    else
    {
        copy(queue+start,queue+capacity,nq);
        copy(queue,queue+rear+1,queue+start-capacity);
    }
    front=2*capacity-1;
    rear=capacity-1;
    capacity*=2;
    free(queue);
    queue=nq;
}
void addq(element item)
{
    rear=(rear+1)%capacity;
    if(front==rear)
        queuefull();
    queue[rear]=item;
}
element deleteq()
{
    element item;
    if(front==rear)
        item.key=-1;
    front=(front+1)%capacity;
    item=queue[front];
    return item;
}
void display()
{
    if(front==rear)
        printf("\n\nQueue is Empty!\n\n");
    else
    {
        int i;
        printf("\n\nThe Queue is:\n");
        for(i=(front+1)%capacity; i!=(rear+1)%capacity; i=(i+1)%capacity)
            printf("%d\t",queue[i].key);
        printf("\n");
    }
}
void main()
{
    queue=(element*)malloc(sizeof(element));
    int c;
    element item;
    while(c!=4)
    {
        printf("\nEnter\n1. Insert\n2. Delete\n3. Display\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1: printf("\nEnter element: ");
                    scanf("%d",&item.key);
                    addq(item);
            break;
            case 2: item=deleteq();
                    if(item.key==-1)
                        printf("\n\nQueue is Empty!\n\n");
                    else
                        printf("\n\nElement deleted: %d\n",item.key);
            break;
            case 3: display();
            break;
            case 4: exit(0);
            default: exit(0);
        }
    }
}
