#include <stdio.h>
#include <stdlib.h>
int main(void)
{  
    int a[3][3];
    int b[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d",&a[i][j]);
        }
        
    }
    for(int i=0;i<3;i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            b[j][i]=a[i][j];
        }
        
    }
    for(int i=0;i<3;i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    system("pause");
return 0;
}