#include <stdio.h>
#include <stdlib.h>
int main(void)
{   int a[10];
    int sum=0;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d",&a[i]);
    }
    for (int *p = a; p < a+10; p++)
    {
        sum+=*p;
        
    }
       
    printf("%d",sum);
    
    system("pause");
return 0;
}