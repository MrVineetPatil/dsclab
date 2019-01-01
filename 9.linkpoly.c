#include<stdio.h>
#include<stdlib.h>
#define COMPARE(x,y)((x==y)?0:(x>y)?1:-1)
struct node
{
float coeff;
int exp;
struct node*link;
};
typedef struct node*polypointer;
void attach(float coefficient,int exponent,polypointer* ptr)
{
polypointer temp;
temp=(polypointer)malloc(sizeof(struct node));
temp->coeff=coefficient;
temp->exp=exponent;
(*ptr)->link=temp;
*ptr=temp;
(*ptr)->link=NULL;
}
polypointer cadd(polypointer a,polypointer b)
{
polypointer c,lastC,startA;
int sum,done=0;
startA=a;
a=a->link;
b=b->link;
c=(polypointer)malloc(sizeof(struct node));
c->exp=-1;
lastC=c;
do
{
switch (COMPARE(a->exp,b->exp))
{
case 1:attach(a->coeff,a->exp,&lastC);
a=a->link;
break;
case 0:if(startA==a)
done=1;
else
{
sum=a->coeff+b->coeff;
if(sum)
attach(sum,a->exp,&lastC);
a=a->link;
b=b->link;
}
break;
case -1:attach(b->coeff,b->exp,&lastC);
b=b->link;
break;
}
}while(!done);
lastC->link=c;
return c;
}
void printPoly(polypointer k)
{
k=k->link;
while(((k->link)->exp)!=-1)
{
printf("%.2fx^%d+",k->coeff,k->exp);
k=k->link;
}
printf("%.2fx^%d",k->coeff,k->exp);
printf("\n");
}
int main()
{
polypointer a,b,c,endA,endB;
int n,i,expon;
float coef;
a=(polypointer)malloc(sizeof(struct node));
a->exp=-1;
b=(polypointer)malloc(sizeof(struct node));
b->exp=-1;
printf("enter the number of terms for first polynomial\n");
scanf("%d",&n);
endA=a;
for(i=0;i<n;i++)
{
printf("Enter the coefficient\n");
scanf("%f",&coef);
printf("Enter the exponent\n");
scanf("%d",&expon);
attach(coef,expon,&endA);
}
endA->link=a;
printf("Enter the number of terms for second polynomial\n");
scanf("%d",&n);
endB=b;
for(i=0;i<n;i++)
{
printf("Enter the coefficient\n");
scanf("%f",&coef);
printf("Enter the exponenet\n");
scanf("%d",&expon);
attach(coef,expon,&endB);
}
endB->link=b;
c=cadd(a,b);
printPoly(a);
printPoly(b);
printPoly(c);
}
