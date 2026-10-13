#include <stdio.h>
#include <stdlib.h>
int main(void)
{    
    int s[10];
    for (int i = 0; i < 10; i++) {
    scanf("%d", &s[i]); 
    
}
    for (int i = 9; i >=0; i--)
    {
        printf("%d ",s[i]);
        }
    
    system("pause");
return 0;
}