#include <stdio.h>
#include <stdlib.h>
int main(void)
{   system("chcp 65001 > nul");
    int a[10]  ;  
    for (int i = 0; i < 10; i++) {
    scanf("%d", &a[i]); 
    
}
    int max=a[0];
    int pos=0;
    for (int i = 0; i < 10; i++)
    {
        if (a[i]>max)
        {
            max=a[i];
            pos=i;
        }
        
    }
    printf("最高分是%d,是第%d个输入的",max,pos+1);
    system("pause");
return 0;
}