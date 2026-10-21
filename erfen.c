#include <stdio.h>
#include <stdlib.h>
int main(void)
{   system("chcp 65001 > nul");
    int found=0;
    int low=0;
    int high=9;
    int fou;
    int a[10];
    printf("输入成绩：");
    for (int i = 0;  i < 10; i++)
    {
        scanf("%d",&a[i]);     
    }
    printf("查找");
    scanf("%d",&fou);
    while(low<=high)
    {
        int mid = (low + high) / 2;
        if (a[mid]>fou)
        {
            high=mid-1;

        } else if (a[mid]<fou)
        {
            low=mid+1;
        }else if (a[mid]==fou)
        {
            printf("找到了，下标是%d",mid);
            found=1;
            break;
        }
  
        
    }
    if (found==0)
    {
        printf("不存在");
    }
    
system("pause");
return 0;
}