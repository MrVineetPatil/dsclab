#include<stdio.h>
typedef struct
{
    int row, col, val;
} terms;
void f_transpose(terms a[], terms b[])
{
    int i, j, row_terms[100], startingpos[100], num_terms=a[0].val, num_cols=a[0].col;
    b[0].col=a[0].row, b[0].row=num_cols, b[0].val=num_terms;
    if(num_terms>0)
    {
        for(i=0; i<num_cols; i++)
            row_terms[i]=0;
        for(i=1; i<=num_terms; i++)
            row_terms[a[i].col]++;
        startingpos[0]=1;
        for(i=1; i<num_cols; i++)
            startingpos[i]=startingpos[i-1]+row_terms[i-1];
        for(i=1; i<=num_terms; i++)
        {
            j=startingpos[a[i].col]++;
            b[j].row=a[i].col;
            b[j].col=a[i].row;
            b[j].val=a[i].val;
        }
    }
}
void display(terms p[])
{
    int i=1, num_terms=p[0].val;
    printf("row\tcolumn\tvalue\n%d\t%d\t%d\n\n",p[0].row,p[0].col,p[0].val);
    for(; i<=num_terms; i++)
        printf("%d\t%d\t%d\n",p[i].row,p[i].col,p[i].val);
}
void main()
{
    int i;
    terms c[100], d[100];
    printf("Enter Sparse Matrix A:\nEnter Rows: ");
    scanf("%d",&c[0].row);
    printf("Enter Columns: ");
    scanf("%d",&c[0].col);
    printf("Enter the number of non zero values: ");
    scanf("%d",&c[0].val);
    for(i=1; i<=c[0].val; i++)
    {
        printf("Enter row: ");
        scanf("%d",&c[i].row);
        printf("Enter column: ");
        scanf("%d",&c[i].col);
        printf("Enter value: ");
        scanf("%d",&c[i].val);
    }
    display(c);
    f_transpose(c,d);
    display(d);
}
