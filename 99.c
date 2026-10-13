#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{   system("chcp 65001 > nul");
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j<=i; j++)
        {
            printf("%d*%d=%d\t",j,i,j*i);
        }
    printf("\n");
    }
    
    
    system("pause");
 return 0;
}
