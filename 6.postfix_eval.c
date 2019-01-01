#include<stdio.h>
typedef enum precedence
{ lparen, rparen, plus, minus, multiply, divide, mod, eos, operand } precedence;
char expr[100];
int stack[100], top=-1;
precedence getToken(char* sym, int* n)
{
    *sym=expr[(*n)++];
    switch(*sym)
    {
        case '+': return plus;
        case '-': return minus;
        case '*': return multiply;
        case '/': return divide;
        case '%': return mod;
        case '\0': return eos;
        default: return operand;
    }
}
void push(int token)
{   stack[++top]=token;     }
int pop()
{   return stack[top--];    }
int eval()
{
    char symbol;
    int n=0, op1, op2;
    precedence token=getToken(&symbol, &n);
    while(token!=eos)
    {
        if(token==operand)
            push(symbol-'0');
        else
        {
            op2=pop();
            op1=pop();
            switch(token)
            {
                case plus: push(op1+op2); break;
                case minus: push(op1-op2); break;
                case multiply: push(op1*op2); break;
                case divide: push(op1/op2); break;
                case mod: push(op1%op2); break;
                case eos: break;
                case operand: break;
            }
        }
        token=getToken(&symbol, &n);
    }
    return pop();
}
void main()
{
    printf("Enter postfix expression to evaluate: ");
    scanf("%s",expr);
    printf("\nResult: %d",eval());
}
