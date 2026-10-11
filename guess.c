#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{   system("chcp 65001 > nul");
    int c=0;
    int b=0;
    srand(time(NULL));
    int a = rand() % 100 + 1;
    printf("我想好了一个 1~100 的数,猜猜看:");
 while(b!=a)
{
    scanf("%d",&b);
    c++;
if (b>a)
{
printf("大了！");
}else if (b<a)
{
printf("小了 !");
}
}
printf("恭喜你猜对了!共用了%d次",c);
 system("pause");
 return 0;
}



