#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    double a;
    double b;
    char c;
system("chcp 65001 > nul");
printf("请输入第一个数:");
scanf("%lf",&a);
printf("请输入第二个数:");
scanf("%lf",&b);
printf("请输入运算符:");
scanf(" %c",&c);
if (c == '+') {
       printf("%.2f\n", a + b);
   } else if (c == '-') {
    printf("%.2f\n", a - b);
   }else if (c == '*') {
    printf("%.2f\n", a * b);
   }else if (c == '/') {
    printf("%.2f\n", a / b);
   }
system("pause");
return 0;
}
