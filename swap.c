#include <stdio.h>
#include <stdlib.h>
int swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
int main(void)
{   system("chcp 65001 > nul");    
    int p=3;
    int h=5;
    swap(&p,&h);
    printf("%d %d",p,h);
    system("pause");
return 0;
}