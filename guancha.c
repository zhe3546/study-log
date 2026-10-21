#include <stdio.h>
#include <stdlib.h>
int main(void)
{   system("chcp 65001 > nul");    
    int q;
    double p;
    printf("%p\n",&q);
    printf("%p\n",&q+1);
    printf("%p\n",&p);
    printf("%p\n",&p+1);
    system("pause");
return 0;
}