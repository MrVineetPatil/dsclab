#include<stdio.h>
#include<string.h>
void fail(char* pat, int failure[])
{
    int i, j, n=strlen(pat);
    failure[0]=-1;
    for(j=1; j<n; j++)
    {
        i=failure[j-1];
        while(pat[j]!=pat[i+1]&&i>=0)
            i=failure[i];
        if(pat[j]==pat[i+1])
            failure[j]=i+1;
        else
            failure[j]=-1;
    }
}
int pmatch(char* string, char* pat, int failure[])
{
    int i=0, j=0, lens=strlen(string), lenp=strlen(pat);
    while(i<lens&&j<lenp)
    {
        if(string[i]==pat[j])
            i++, j++;
        else if(j==0)
            i++;
        else
            j=failure[j-1]+1;
    }
    return j==lenp?i-lenp+1:-1;
}
void main()
{
    char string[50], pat[50];
    int failure[50], i=0;
    printf("Enter the string: ");
    scanf("%s",string);
    printf("Enter the pattern: ");
    scanf("%s",pat);
    fail(pat,failure);
    printf("\nThe failure array is:\n");
    for(; i<strlen(pat); i++)
        printf("%d\t",failure[i]);
    int res=pmatch(string, pat, failure);
    if(res==-1)
        printf("\nPattern not found\n");
    else
        printf("\n\nPattern found at %d position in the entered string\n",res);
}
