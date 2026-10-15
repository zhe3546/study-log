#include <stdio.h>
#include <stdlib.h>
int isprime(int n){
    if (n<2)
    {
        return 0;
    }
    for (int i = 2; i < n; i++)
    {
        if (n%i==0)
        {
            return 0;
        }   
    }
    return 1;   
}
int main(void)
{ system("chcp 65001 > nul");
    int x;
    printf("请输入一个整数：");
    scanf("%d",&x);
if (isprime(x) == 1) {
    printf("%d 是素数\n", x);
}else{
    printf("不是素数");
}
system("pause");
return 0;
}
