#include <stdio.h>
#include <stdlib.h>
int main(void)
{   system("chcp 65001 > nul");    
    int a=10;
    int *p=&a;
    double b=10;
    double *j=&b;
    char c=10;
    char *i=&c;
    printf("%p\n",p);
    printf("%p\n",j);
    printf("%p\n",i);
    *p = 100;  
    printf("%d\n", a); 
    system("pause");
return 0;
}