#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main() 
{
    char c[1000];
    size_t i,j,n;
    int counter=0;
    scanf("%s",c);
    //printf("%s",c);
for(i=0;i<=9;++i)
{
    counter=0;
    for(j=0;j<=strlen(c);++j)
    {
    n=c[j];
    if((n>=65 && n<=90)||(n>=97 && n<=122))
        continue;
    else if ((i+48)==n)
    counter=counter+1;
    }
    printf("%d ",counter);
}
    
    return 0; 
}
