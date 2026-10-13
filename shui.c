#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n;   
    for (n=100;n<1000;n++)
    {       
        int a=n%10;
        int b=n/10%10;
        int c=n/100; 
         if(a*a*a+b*b*b+c*c*c==n)
         {
            printf("%d\n",n);
         }
        
    }
    system("pause");
return 0;
}