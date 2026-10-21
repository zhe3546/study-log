#include <stdio.h>
#include <stdlib.h>
int main(void)
{   
    system("chcp 65001 > nul");    
    for (int i = 0; i < 100; i++)
    {
        int b=1;
        if (i<=2)
        {
            printf("%d ",i);
        }else if (i>2)
        {
            for (int j = 2; j < i; j++)
            {
                if (i%j==0)
                {
                    b=0;
                    break;
                }
                
            }
            if (b)
            {
                printf("%d ",i);
            }
            
            
        }
        
        
    }
    
    
    system("pause");
return 0;
}