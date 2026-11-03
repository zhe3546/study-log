#include <iostream>
#include <stdlib.h>
int main()
{
    system("chcp 65001 > nul");
    std::cout << "你好" << std::endl;
    system("pause");
    return 0;
}