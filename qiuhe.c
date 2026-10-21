#include <stdio.h>
#include <stdlib.h>
int main(void)
{   
    system("chcp 65001 > nul");
    int sum=0;
    int max=0;
    int l;
    int h;
    double p=0;
    int a[3][4];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d",&a[i][j]);
        }
        
    }
     for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            sum+=a[i][j];
        }
        printf("%d",sum);
        printf("\n");
    } 
for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            p+=a[i][j];
        }
        printf("%f",p/3);
        printf("\n");
    }  
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (a[i][j]>max)
            {
                max=a[i][j];
                h=i+1;
                l=j+1;
            }
            
        }
        
    }
    printf("%d行%d列",h,l);
    system("pause");
return 0;
}