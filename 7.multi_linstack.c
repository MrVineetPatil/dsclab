#include<stdio.h>
#include<stdlib.h>
typedef struct
{ 
    int key; 
} element;
struct stack
{
    element data;
    struct stack* link;
};
typedef struct stack* stackptr;
stackptr top[10];
void push(element item, int i)
{
    stackptr temp=(stackptr)malloc(sizeof(struct stack));
    temp->data=item;
    temp->link=top[i];
    top[i]=temp;
}
element pop(int i)
{
    stackptr temp=top[i];
    element item;
    if(!temp)
    {
         item.key=-1;
         return item;
    }
    item=top[i]->data;
    top[i]=top[i]->link;
    free(temp);
    return item;
}
void display(int i)
{
    stackptr temp=top[i];
    element item;
    if(!temp)
    {
        printf("\nStack is EMPTY!!\n");
        return;
    }
    printf("Stack %d is:\n",i+1);
    for(; temp; temp=temp->link)
        printf("%d\t",temp->data.key);
    printf("\n");
}
void main()
{
    int ch, stackno;
    element item;
    while(ch!=4)
    {
        printf("\nEnter\n1.Push\n2.Pop\n3.Display\n4.Exit\n\n");
        scanf("%d",&ch);
        if(ch<4)
        {
            printf("Enter stack no: ");
            scanf("%d",&stackno);
        }
        switch(ch)
        {
            case 1: printf("\nEnter element to be pushed: ");
                    scanf("%d",&item);
                    push(item,stackno-1);
            break;
            case 2: item=pop(stackno-1);
                    if(item.key==-1)
                        printf("\nStack Empty!!\n");
                    else
                        printf("\nElement popped is: %d\n\n",item.key);
            break;
            case 3: display(stackno-1);
            break;
            case 4: exit(0);
            default: exit(0);
        }
    }
}
