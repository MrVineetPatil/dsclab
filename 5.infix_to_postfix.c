#include<stdio.h>
typedef enum precedence
{ lparen, rparen, plus, minus, multiply, divide, mod, eos, operand } precedence;
int isp[]={0, 19, 12, 12, 13, 13, 13, 0};
int icp[]={20, 19, 12, 12, 13, 13, 13, 0};
char expr[100];
int stack[100], top;
precedence getToken(char* sym, int* n)
{
    *sym=expr[(*n)++];
    switch(*sym)
    {
        case '(': return lparen;
        case ')': return rparen;
        case '+': return plus;
        case '-': return minus;
        case '*': return multiply;
        case '/': return divide;
        case '%': return mod;
        case '\0': return eos;
        default: return operand;
    }
}
void printToken(precedence token)
{
    switch(token)
    {
        case lparen: printf("("); break;
        case rparen: printf(")"); break;
        case plus: printf("+"); break;
        case minus: printf("-"); break;
        case divide: printf("/"); break;
        case multiply: printf("*"); break;
        case mod: printf("%%"); break;
        case eos: printf("\n"); break;
        case 8: break;
    }
}
void push(int token)
{   stack[++top]=token;     }
int pop()
{   return stack[top--];    }
void postfix()
{
    char symbol;
    precedence token;
    int n=0;
    stack[0]=eos;
    for(token=getToken(&symbol,&n); token!=eos; token=getToken(&symbol,&n))
    {
        if(token==operand)
            printf("%c",symbol);
        else if(token==rparen)
        {
            while(stack[top]!=lparen)
                printToken(pop());
            pop();
        }
        else
        {
            while(isp[stack[top]]>=icp[token])
                printToken(pop());
            push(token);
        }
    }
    while((token=pop())!=eos)
        printToken(token);
    printf("\n");
}
void main()
{
    printf("Enter the infix expression: ");
    scanf("%s",expr);
    printf("\nThe postfix expression is: ");
    postfix();
}
