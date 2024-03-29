#include<stdio.h>
#include<stdlib.h>
typedef struct element
{
int key;
}element;
struct queue
{
element data;
struct queue* link;
};
typedef struct queue*queuepointer;
queuepointer front[10],rear[10];
void enQueue(element item,int i)
{
queuepointer temp;
temp=(queuepointer)malloc(sizeof(struct queue));
temp->data=item;
if(front[i])
rear[i]->link=temp;
else
front[i]=temp;
rear[i]=temp;
rear[i]->link=NULL;
}
element deQueue(int i)
{
queuepointer temp;
temp=front[i];
element item;
if(front[i])
{
item=front[i]->data;
front[i]=front[i]->link;
}
else
{
item.key=-1;
}
free(temp);
return item;
}
void display(int i)
{
queuepointer temp;
temp=front[i];
if(front[i]==NULL)
{
printf("Queue is empty\n");
return;
}
printf("Queue %d is\n",i+1);
for(;temp;temp=temp->link)
printf("%d\t",temp->data.key);
printf("\n");
}
int main()
{
int choice,queueno;
element item;
while(1)
{
printf("Enter\n1.Add\n2.Delete\n3.Display\n4.Exit\n");
scanf("%d",&choice);
if(choice!=4)
{
printf("Enter queue number from 1-10\n");
scanf("%d",&queueno);
}
switch(choice)
{
case 1: printf("Enter data to be inserted:");
scanf("%d",&item.key);
enQueue(item,queueno-1);
break;
case 2: item=deQueue(queueno-1);
if(item.key==-1)
printf("Queue empty\n");
else
printf("Element deleted:%d\n",item.key);
break;
case 3: display(queueno-1);
break;
case 4: printf("Operation Complete\n");
exit(0);
}
}
}
