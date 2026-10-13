#include <stdio.h>
#include <stdlib.h>
int main(void)
{   
    double sum=0;
    system("chcp 65001 > nul");  
    int s[10];
    for (int g = 0; g < 10; g++)
    {
        scanf("%d",&s[g]);
    }
    
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9-i; j++)
        {
           if (s[j]>s[j+1])
           {
            int y=s[j];
            s[j]=s[j+1];
            s[j+1]=y;
           }
        
        }
    }
    for (int k = 0; k < 10; k++)
    {
       printf("%d ",s[k]);
    }
    printf("最大值%d\n",s[9]);
    printf("最小值%d\n",s[0]);
    for (int t = 0; t < 10; t++)
    {
        sum+=s[t];
    }
    printf("平均值%.1f\n", (double)sum/10);
    system("pause");
return 0;
}