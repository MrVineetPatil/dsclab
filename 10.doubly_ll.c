#include<stdio.h>
#include<stdlib.h>
struct node
{
    int key;
    struct node* llink;
    struct node* rlink;
};
typedef struct node* nodeptr;
void insert(int ele, nodeptr hdr)
{
    nodeptr temp;
    temp=(nodeptr)malloc(sizeof(struct node));
    temp->key=ele;
    temp->llink=hdr;
    temp->rlink=hdr->rlink;
    hdr->rlink->llink=temp;
    hdr->rlink=temp;
}
int delete(int item, nodeptr hdr)
{
    if(hdr->rlink==hdr)
    {
        printf("EMPTY LIST!!\n");
        return -1;
    }
    hdr=hdr->rlink;
    while(hdr->key!=-1)
    {
        if(hdr->key==item)
        {
            hdr->rlink->llink=hdr->llink;
            hdr->llink->rlink=hdr->rlink;
            free(hdr);
            return 0;
        }
        hdr=hdr->rlink;
    }
}
void displaylr(nodeptr hdr)
{
    if(hdr->rlink==hdr)
        printf("EMPTY LIST!!\n");
    hdr=hdr->rlink;
    while(hdr->key!=-1)
    {
        printf("%d\t",hdr->key);
        hdr=hdr->rlink;
    }
    printf("\n");
}
void displayrl(nodeptr hdr)
{
    if(hdr->llink==hdr)
        printf("EMPTY LIST!!\n");
    hdr=hdr->llink;
    while(hdr->key!=-1)
    {
        printf("%d\t",hdr->key);
        hdr=hdr->llink;
    }
    printf("\n");
}
void main()
{
    int ch, element;
    nodeptr first=(nodeptr)malloc(sizeof(struct node));
    first->key=-1;
    first->rlink=first;
    first->llink=first;
    while(ch!=5)
    {
        printf("Enter\n1.Insertion\n2.Deletion\n3.Display Front\n4.Display Back\n5.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter element: ");
                    scanf("%d",&element);
                    insert(element,first);
            break;
            case 2: printf("Enter element to be deleted: ");
                    scanf("%d",&element);
                    int result=delete(element,first);
                    if(result==-1)
                        printf("Element not found!\n");
                    else
                        printf("Element deleted is: %d\n",element);
            break;
            case 3: displaylr(first);
            break;
            case 4: displayrl(first);
            break;
            case 5: exit(0);
            default: exit(0);
        }
    }
}
