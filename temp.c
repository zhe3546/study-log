#include <stdio.h>
#include <stdlib.h>
int main(void)
{
system("chcp 65001 > nul");
    double a;
printf("请输入华氏温度:");
scanf("%lf",&a);
a = 5*(a- 32)/9;
printf("摄氏度：%.2f",a);
system("pause");
return 0;
}