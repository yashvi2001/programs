#include<stdio.h>
void main()
{
    int r,c,size=0;
    printf("Enter the number of rows and columns of the matrix : \n");
    scanf("%d %d",&r,&c);
    int a[r][c];
    printf("Enter the elements of the matrix : \n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Display the lower traingle matrix : \n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(i<j)
            {
                printf("%4c",' ');
            }
            else
            {
                printf("%4d",a[i][j]);
            }
            
        }
        printf("\n");
    }
    printf("Display the upper traingle matrix : \n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(j<i)
            {
                printf("%4c",' ');
            }
            else
            {
                printf("%4d",a[i][j]);
            }
        }
        printf("\n");
    }
}