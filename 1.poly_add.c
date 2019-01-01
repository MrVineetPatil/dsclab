#include<stdio.h>
#include<stdlib.h>
#define COMPARE(x,y) (x==y?0:x>y?1:-1)
typedef struct
{
    float coef;
    int exp;
} poly;
poly terms[100];
int avail=0;
void attach(float coeff, int expo)
{
    if(avail>=100)
        exit(1);
    terms[avail].coef=coeff;
    terms[avail].exp=expo;
    avail++;
}
void padd(int starta, int finisha, int startb, int finishb, int* startd, int* finishd)
{
    float sum=0;
    *startd=avail;
    while(starta<=finisha&&startb<=finishb)
    {
        switch(COMPARE(terms[starta].exp,terms[startb].exp))
        {
            case -1: attach(terms[startb].coef,terms[startb].exp);
                     startb++;
            break;
            case 1: attach(terms[starta].coef,terms[starta].exp);
                    starta++;
            break;
            case 0: sum=terms[starta].coef+terms[startb].coef;
                    if(sum)
                        attach(sum,terms[starta].exp);
                    starta++, startb++;
            break;
        }
    }
    for(; starta<=finisha; starta++)
        attach(terms[starta].coef,terms[starta].exp);
    for(; startb<=finishb; startb++)
        attach(terms[startb].coef,terms[startb].exp);
    *finishd=avail-1;
}
void printpoly(int start, int end)
{
    int i;
    for(i=start; i<=end; i++)
    {
        if(i==end)
            printf("%.2f X^%d\n\n",terms[i].coef,terms[i].exp);
        else
            printf("%.2f X^%d + ",terms[i].coef,terms[i].exp);
    }
}
void main()
{
    int expo, count=0, starta=0, startb=0, finisha=0, finishb=0, i, n, startd=0, finishd=0;
    float coeff;
    while(count!=2)
    {
        printf("\nEnter the number of terms: ");
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            printf("\nEnter exponent: ");
            scanf("%d",&expo);
            printf("Enter coefficient: ");
            scanf("%f",&coeff);
            attach(coeff,expo);
        }
        if(count==0)
        {
            finisha=avail-1;
            startb=avail;
        }
        if(count==1)
            finishb=avail-1;
        count++;
    }
    printf("\n");
    printpoly(starta,finisha);
    printpoly(startb,finishb);
    padd(starta,finisha,startb,finishb,&startd,&finishd);
    printf("Sum: ");
    printpoly(startd,finishd);
}
